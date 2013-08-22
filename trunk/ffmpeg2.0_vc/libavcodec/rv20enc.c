/*
 * RV20 encoder
 * Copyright (c) 2000,2001 Fabrice Bellard
 * Copyright (c) 2002-2004 Michael Niedermayer
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

/**
 * @file
 * RV20 encoder
 */

#include "mpegvideo.h"
#include "h263.h"
#include "put_bits.h"

void ff_rv20_encode_picture_header(MpegEncContext *s, int picture_number){
    put_bits(&s->pb, 2, s->pict_type); //I 0 vs. 1 ?
    put_bits(&s->pb, 1, 0);     /* unknown bit */
    put_bits(&s->pb, 5, s->qscale);

    put_sbits(&s->pb, 8, picture_number); //FIXME wrong, but correct is not known
    s->mb_x= s->mb_y= 0;
    ff_h263_encode_mba(s);

    put_bits(&s->pb, 1, s->no_rounding);

    av_assert0(s->f_code == 1);
    av_assert0(s->unrestricted_mv == 0);
    av_assert0(s->alt_inter_vlc == 0);
    av_assert0(s->umvplus == 0);
    av_assert0(s->modified_quant==1);
    av_assert0(s->loop_filter==1);

    s->h263_aic= s->pict_type == AV_PICTURE_TYPE_I;
    if(s->h263_aic){
        s->y_dc_scale_table=
        s->c_dc_scale_table= ff_aic_dc_scale_table;
    }else{
        s->y_dc_scale_table=
        s->c_dc_scale_table= ff_mpeg1_dc_scale_table;
    }
}

FF_MPV_GENERIC_CLASS(rv20)


const enum AVPixelFormat rv20_pix_fmts[] = { AV_PIX_FMT_YUV420P, AV_PIX_FMT_NONE };

AVCodec ff_rv20_encoder = {
	/*.name           =*/ "rv20",
	/*.long_name      =*/ NULL_IF_CONFIG_SMALL("RealVideo 2.0"),
	/*.type           =*/ AVMEDIA_TYPE_VIDEO,
	/*.id             =*/ AV_CODEC_ID_RV20,
	/* capabilities = */ 0,
	/* supported_framerates = */ 0,
	/* pix_fmts = */ rv20_pix_fmts,
	/* supported_samplerates = */ 0,
	/* sample_fmts = */ 0,
	/* channel_layouts = */0,
	/* max_lowres = */ 0,
	/* priv_class = */  &rv20_class,
	/* profiles = */ 0,
	/*.priv_data_size =*/ sizeof(MpegEncContext),
	/* next = */ 0,
	/* init_thread_copy = */ 0,
	/* update_thread_context = */ 0,
	/* defaults = */ 0,
	/* init_static_data = */ 0,
	/*.init           =*/ ff_MPV_encode_init,
	/* encode_sub = */ 0,
	/*.encode2        =*/ ff_MPV_encode_picture,
	/* decode = */ 0,
	/*.close          =*/ ff_MPV_encode_end,
	/* flush = */ 0    
};