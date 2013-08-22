/*
 * V.Flash PTX (.ptx) image decoder
 * Copyright (c) 2007 Ivo van Poorten
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#include "libavutil/common.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/imgutils.h"
#include "avcodec.h"
#include "libavutil/internal.h"
#include "libavcodec/Utils.h"

static int ptx_decode_frame(AVCodecContext *avctx, void *data, int *got_frame,
                            AVPacket *avpkt) {
    const uint8_t *buf = avpkt->data;
    const uint8_t *buf_end = avpkt->data + avpkt->size;
    AVFrame * const p = data;
    unsigned int offset, w, h, y, stride, bytes_per_pixel;
    int ret;
    uint8_t *ptr;

    if (buf_end - buf < 14)
        return AVERROR_INVALIDDATA;
    offset          = AV_RL16(buf);
    w               = AV_RL16(buf+8);
    h               = AV_RL16(buf+10);
    bytes_per_pixel = AV_RL16(buf+12) >> 3;

    if (bytes_per_pixel != 2) {
        avpriv_request_sample(avctx, "Image format not RGB15");
        return AVERROR_PATCHWELCOME;
    }

    avctx->pix_fmt = AV_PIX_FMT_BGR555LE;

    if (buf_end - buf < offset)
        return AVERROR_INVALIDDATA;
    if (offset != 0x2c)
        avpriv_request_sample(avctx, "offset != 0x2c");

    buf += offset;

    if ((ret = av_image_check_size(w, h, 0, avctx)) < 0)
        return ret;
    if (w != avctx->width || h != avctx->height)
        avcodec_set_dimensions(avctx, w, h);
    if ((ret = ff_get_buffer(avctx, p, 0)) < 0)
        return ret;

    p->pict_type = AV_PICTURE_TYPE_I;

    ptr    = p->data[0];
    stride = p->linesize[0];

    for (y = 0; y < h && buf_end - buf >= w * bytes_per_pixel; y++) {
        memcpy(ptr, buf, w*bytes_per_pixel);
        ptr += stride;
        buf += w*bytes_per_pixel;
    }

    *got_frame = 1;

    if (y < h) {
        av_log(avctx, AV_LOG_WARNING, "incomplete packet\n");
        return avpkt->size;
    }

    return offset + w*h*bytes_per_pixel;
}

AVCodec ff_ptx_decoder={
	/*.name=*/"ptx",
	/*.long_name=*/NULL_IF_CONFIG_SMALL("V.Flash PTX image"),
	/*.type=*/AVMEDIA_TYPE_VIDEO,
	/*.id=*/AV_CODEC_ID_PTX,
	/*.capabilities=*/CODEC_CAP_DR1,
	/*.supported_framerates=*/0,
	/*.pix_fmts=*/0,
	/*.supported_samplerates=*/0,
	/*.sample_fmts=*/0,
	/*.channel_layouts=*/0,
	/*.max_lowres=*/0,
	/*.priv_class=*/0,
	/*.profiles=*/0,
	/*.priv_data_size=*/0,
	/*.next=*/0,
	/*.init_thread_copy=*/0,
	/*.update_thread_context=*/0,
	/*.defaults=*/0,
	/*.init_static_data=*/0,
	/*.init=*/0,
	/*.encode_sub=*/0,
	/*.encode2=*/0,
	/*.decode=*/ptx_decode_frame,
	/*.close=*/0,
	/*.flush=*/0,
};