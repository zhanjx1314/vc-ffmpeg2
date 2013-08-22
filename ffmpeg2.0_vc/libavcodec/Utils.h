#ifndef LIBAVCODEC_UTILS_H
#define LIBAVCODEC_UTILS_H

int ff_get_buffer(AVCodecContext *avctx, AVFrame *frame, int flags);
int ff_alloc_packet2(AVCodecContext *avctx, AVPacket *avpkt, int size);
int ff_reget_buffer(AVCodecContext *avctx, AVFrame *frame);

#endif