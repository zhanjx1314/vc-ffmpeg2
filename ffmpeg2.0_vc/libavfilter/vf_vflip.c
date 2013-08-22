/*
 * Copyright (c) 2007 Bobby Bingham
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
 * video vertical flip filter
 */

#include "libavutil/internal.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "internal.h"
#include "video.h"

typedef struct {
    int vsub;   ///< vertical chroma subsampling
} FlipContext;

static int config_input(AVFilterLink *link)
{
    FlipContext *flip = link->dst->priv;
    const AVPixFmtDescriptor *desc = av_pix_fmt_desc_get(link->format);

    flip->vsub = desc->log2_chroma_h;

    return 0;
}

static AVFrame *get_video_buffer(AVFilterLink *link, int w, int h)
{
    FlipContext *flip = link->dst->priv;
    AVFrame *frame;
    int i;

    frame = ff_get_video_buffer(link->dst->outputs[0], w, h);
    if (!frame)
        return NULL;

    for (i = 0; i < 4; i ++) {
        int vsub = i == 1 || i == 2 ? flip->vsub : 0;
        int height = FF_CEIL_RSHIFT(h, vsub);

        if (frame->data[i]) {
            frame->data[i] += (height - 1) * frame->linesize[i];
            frame->linesize[i] = -frame->linesize[i];
        }
    }

    return frame;
}

static int filter_frame(AVFilterLink *link, AVFrame *frame)
{
    FlipContext *flip = link->dst->priv;
    int i;

    for (i = 0; i < 4; i ++) {
        int vsub = i == 1 || i == 2 ? flip->vsub : 0;
        int height = FF_CEIL_RSHIFT(link->h, vsub);

        if (frame->data[i]) {
            frame->data[i] += (height - 1) * frame->linesize[i];
            frame->linesize[i] = -frame->linesize[i];
        }
    }

    return ff_filter_frame(link->dst->outputs[0], frame);
}
static const AVFilterPad avfilter_vf_vflip_inputs[]={
	{
		/*.name=*/"default",
			/*.type=*/AVMEDIA_TYPE_VIDEO,
			/*.min_perms=*/0,
			/*.rej_perms=*/0,
			/*.start_frame=*/0,
			/*.get_video_buffer=*/get_video_buffer,
			/*.get_audio_buffer=*/0,
			/*.end_frame=*/0,
			/*.draw_slice=*/0,
			/*.filter_frame=*/filter_frame,
			/*.poll_frame=*/0,
			/*.request_frame=*/0,
			/*.config_props=*/config_input,
			/*.needs_fifo=*/0,
			/*.needs_writable=*/0,
	}
	,{NULL}};

	static const AVFilterPad avfilter_vf_vflip_outputs[]={
		{
			/*.name=*/"default",
				/*.type=*/AVMEDIA_TYPE_VIDEO,
				/*.min_perms=*/0,
				/*.rej_perms=*/0,
				/*.start_frame=*/0,
				/*.get_video_buffer=*/0,
				/*.get_audio_buffer=*/0,
				/*.end_frame=*/0,
				/*.draw_slice=*/0,
				/*.filter_frame=*/0,
				/*.poll_frame=*/0,
				/*.request_frame=*/0,
				/*.config_props=*/0,
				/*.needs_fifo=*/0,
				/*.needs_writable=*/0,
		}
		,{NULL}};


		AVFilter avfilter_vf_vflip={
			/*.name=*/"vflip",
			/*.description=*/NULL_IF_CONFIG_SMALL("Flip the input video vertically."),
			/*.inputs=*/avfilter_vf_vflip_inputs,
			/*.outputs=*/avfilter_vf_vflip_outputs,
			/*.priv_class=*/0,
			/*.flags=*/0,
			/*.init=*/0,
			/*.init_dict=*/0,
			/*.uninit=*/0,
			/*.query_formats=*/0,
			/*.priv_size=*/sizeof(FlipContext),
			/*.next=*/0,
			/*.process_command=*/0,
			/*.init_opaque=*/0,
		};
