/*
 * Register all the formats and protocols
 * Copyright (c) 2000, 2001, 2002 Fabrice Bellard
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

#include "avformat.h"
#include "rtp.h"
#include "rdt.h"
#include "url.h"
#include "version.h"

#define REGISTER_MUXER(X, x)                                            \
    {                                                                   \
        extern AVOutputFormat ff_##x##_muxer;                           \
        if (CONFIG_##X##_MUXER)                                         \
            av_register_output_format(&ff_##x##_muxer);                 \
    }

#define REGISTER_DEMUXER(X, x)                                          \
    {                                                                   \
        extern AVInputFormat ff_##x##_demuxer;                          \
        if (CONFIG_##X##_DEMUXER)                                       \
            av_register_input_format(&ff_##x##_demuxer);                \
    }

#define REGISTER_MUXDEMUX(X, x) REGISTER_MUXER(X, x); REGISTER_DEMUXER(X, x)

#define REGISTER_PROTOCOL(X, x)                                         \
    {                                                                   \
        extern URLProtocol ff_##x##_protocol;                           \
        if (CONFIG_##X##_PROTOCOL)                                      \
            ffurl_register_protocol(&ff_##x##_protocol,                 \
                                    sizeof(ff_##x##_protocol));         \
    }

void av_register_all(void)
{
    static int initialized;

    if (initialized)
        return;
    initialized = 1;

    avcodec_register_all();

    /* (de)muxers */
#if CONFIG_A64_MUXER 
	REGISTER_MUXER   (A64,              a64);
#endif

#if CONFIG_AAC_DEMUXER 

	REGISTER_DEMUXER (AAC,              aac);
#endif

#if CONFIG_AC3_DEMUXER 
#if CONFIG_AC3_MUXER 

	REGISTER_MUXDEMUX(AC3,              ac3);
#endif
#endif

#if CONFIG_ACT_DEMUXER 

	REGISTER_DEMUXER (ACT,              act);
#endif

#if CONFIG_ADF_DEMUXER 

	REGISTER_DEMUXER (ADF,              adf);
#endif

#if CONFIG_ADP_DEMUXER 

	REGISTER_DEMUXER (ADP,              adp);
#endif

#if CONFIG_ADTS_MUXER 

	REGISTER_MUXER   (ADTS,             adts);
#endif

#if CONFIG_ADX_DEMUXER 
#if CONFIG_ADX_MUXER 

	REGISTER_MUXDEMUX(ADX,              adx);
#endif
#endif

#if CONFIG_AEA_DEMUXER 

	REGISTER_DEMUXER (AEA,              aea);
#endif

#if CONFIG_AFC_DEMUXER 

	REGISTER_DEMUXER (AFC,              afc);
#endif

#if CONFIG_AIFF_DEMUXER 
#if CONFIG_AIFF_MUXER 

	REGISTER_MUXDEMUX(AIFF,             aiff);
#endif
#endif

#if CONFIG_AMR_DEMUXER 
#if CONFIG_AMR_MUXER 

	REGISTER_MUXDEMUX(AMR,              amr);
#endif
#endif

#if CONFIG_ANM_DEMUXER 

	REGISTER_DEMUXER (ANM,              anm);
#endif

#if CONFIG_APC_DEMUXER 

	REGISTER_DEMUXER (APC,              apc);
#endif

#if CONFIG_APE_DEMUXER 

	REGISTER_DEMUXER (APE,              ape);
#endif

#if CONFIG_AQTITLE_DEMUXER 

	REGISTER_DEMUXER (AQTITLE,          aqtitle);
#endif

#if CONFIG_ASF_DEMUXER 
#if CONFIG_ASF_MUXER 

	REGISTER_MUXDEMUX(ASF,              asf);
#endif
#endif

#if CONFIG_ASS_DEMUXER 
#if CONFIG_ASS_MUXER 

	REGISTER_MUXDEMUX(ASS,              ass);
#endif
#endif

#if CONFIG_AST_DEMUXER 
#if CONFIG_AST_MUXER 

	REGISTER_MUXDEMUX(AST,              ast);
#endif
#endif

#if CONFIG_ASF_STREAM_MUXER 

	REGISTER_MUXER   (ASF_STREAM,       asf_stream);
#endif

#if CONFIG_AU_DEMUXER 
#if CONFIG_AU_MUXER 

	REGISTER_MUXDEMUX(AU,               au);
#endif
#endif

#if CONFIG_AVI_DEMUXER 
#if CONFIG_AVI_MUXER 

	REGISTER_MUXDEMUX(AVI,              avi);
#endif
#endif

#if CONFIG_AVISYNTH_DEMUXER 

	REGISTER_DEMUXER (AVISYNTH,         avisynth);
#endif

#if CONFIG_AVM2_MUXER 

	REGISTER_MUXER   (AVM2,             avm2);
#endif

#if CONFIG_AVR_DEMUXER 

	REGISTER_DEMUXER (AVR,              avr);
#endif

#if CONFIG_AVS_DEMUXER 

	REGISTER_DEMUXER (AVS,              avs);
#endif

#if CONFIG_BETHSOFTVID_DEMUXER 

	REGISTER_DEMUXER (BETHSOFTVID,      bethsoftvid);
#endif

#if CONFIG_BFI_DEMUXER 

	REGISTER_DEMUXER (BFI,              bfi);
#endif

#if CONFIG_BINTEXT_DEMUXER 

	REGISTER_DEMUXER (BINTEXT,          bintext);
#endif

#if CONFIG_BINK_DEMUXER 

	REGISTER_DEMUXER (BINK,             bink);
#endif

#if CONFIG_BIT_DEMUXER 
#if CONFIG_BIT_MUXER 

	REGISTER_MUXDEMUX(BIT,              bit);
#endif
#endif

#if CONFIG_BMV_DEMUXER 

	REGISTER_DEMUXER (BMV,              bmv);
#endif

#if CONFIG_BRSTM_DEMUXER 

	REGISTER_DEMUXER (BRSTM,            brstm);
#endif

#if CONFIG_BOA_DEMUXER 

	REGISTER_DEMUXER (BOA,              boa);
#endif

#if CONFIG_C93_DEMUXER 

	REGISTER_DEMUXER (C93,              c93);
#endif

#if CONFIG_CAF_DEMUXER 
#if CONFIG_CAF_MUXER 

	REGISTER_MUXDEMUX(CAF,              caf);
#endif
#endif

#if CONFIG_CAVSVIDEO_DEMUXER 
#if CONFIG_CAVSVIDEO_MUXER 

	REGISTER_MUXDEMUX(CAVSVIDEO,        cavsvideo);
#endif
#endif

#if CONFIG_CDG_DEMUXER 

	REGISTER_DEMUXER (CDG,              cdg);
#endif

#if CONFIG_CDXL_DEMUXER 

	REGISTER_DEMUXER (CDXL,             cdxl);
#endif

#if CONFIG_CONCAT_DEMUXER 

	REGISTER_DEMUXER (CONCAT,           concat);
#endif

#if CONFIG_CRC_MUXER 

	REGISTER_MUXER   (CRC,              crc);
#endif

#if CONFIG_DATA_DEMUXER 
#if CONFIG_DATA_MUXER 

	REGISTER_MUXDEMUX(DATA,             data);
#endif
#endif

#if CONFIG_DAUD_DEMUXER 
#if CONFIG_DAUD_MUXER 

	REGISTER_MUXDEMUX(DAUD,             daud);
#endif
#endif

#if CONFIG_DFA_DEMUXER 

	REGISTER_DEMUXER (DFA,              dfa);
#endif

#if CONFIG_DIRAC_DEMUXER 
#if CONFIG_DIRAC_MUXER 

	REGISTER_MUXDEMUX(DIRAC,            dirac);
#endif
#endif

#if CONFIG_DNXHD_DEMUXER 
#if CONFIG_DNXHD_MUXER 

	REGISTER_MUXDEMUX(DNXHD,            dnxhd);
#endif
#endif

#if CONFIG_DSICIN_DEMUXER 

	REGISTER_DEMUXER (DSICIN,           dsicin);
#endif

#if CONFIG_DTS_DEMUXER 
#if CONFIG_DTS_MUXER 

	REGISTER_MUXDEMUX(DTS,              dts);
#endif
#endif

#if CONFIG_DTSHD_DEMUXER 

	REGISTER_DEMUXER (DTSHD,            dtshd);
#endif

#if CONFIG_DV_DEMUXER 
#if CONFIG_DV_MUXER 

	REGISTER_MUXDEMUX(DV,               dv);
#endif
#endif

#if CONFIG_DXA_DEMUXER 

	REGISTER_DEMUXER (DXA,              dxa);
#endif

#if CONFIG_EA_DEMUXER 

	REGISTER_DEMUXER (EA,               ea);
#endif

#if CONFIG_EA_CDATA_DEMUXER 

	REGISTER_DEMUXER (EA_CDATA,         ea_cdata);
#endif

#if CONFIG_EAC3_DEMUXER 
#if CONFIG_EAC3_MUXER 

	REGISTER_MUXDEMUX(EAC3,             eac3);
#endif
#endif

#if CONFIG_EPAF_DEMUXER 

	REGISTER_DEMUXER (EPAF,             epaf);
#endif

#if CONFIG_F4V_MUXER 

	REGISTER_MUXER   (F4V,              f4v);
#endif

#if CONFIG_FFM_DEMUXER 
#if CONFIG_FFM_MUXER 

	REGISTER_MUXDEMUX(FFM,              ffm);
#endif
#endif

#if CONFIG_FFMETADATA_DEMUXER 
#if CONFIG_FFMETADATA_MUXER 

	REGISTER_MUXDEMUX(FFMETADATA,       ffmetadata);
#endif
#endif

#if CONFIG_FILMSTRIP_DEMUXER 
#if CONFIG_FILMSTRIP_MUXER 

	REGISTER_MUXDEMUX(FILMSTRIP,        filmstrip);
#endif
#endif

#if CONFIG_FLAC_DEMUXER 
#if CONFIG_FLAC_MUXER 

	REGISTER_MUXDEMUX(FLAC,             flac);
#endif
#endif

#if CONFIG_FLIC_DEMUXER 

	REGISTER_DEMUXER (FLIC,             flic);
#endif

#if CONFIG_FLV_DEMUXER 
#if CONFIG_FLV_MUXER 

	REGISTER_MUXDEMUX(FLV,              flv);
#endif
#endif

#if CONFIG_FOURXM_DEMUXER 

	REGISTER_DEMUXER (FOURXM,           fourxm);
#endif

#if CONFIG_FRAMECRC_MUXER 

	REGISTER_MUXER   (FRAMECRC,         framecrc);
#endif

#if CONFIG_FRAMEMD5_MUXER 

	REGISTER_MUXER   (FRAMEMD5,         framemd5);
#endif

#if CONFIG_FRM_DEMUXER 

	REGISTER_DEMUXER (FRM,              frm);
#endif

#if CONFIG_G722_DEMUXER 
#if CONFIG_G722_MUXER 

	REGISTER_MUXDEMUX(G722,             g722);
#endif
#endif

#if CONFIG_G723_1_DEMUXER 
#if CONFIG_G723_1_MUXER 

	REGISTER_MUXDEMUX(G723_1,           g723_1);
#endif
#endif

#if CONFIG_G729_DEMUXER 

	REGISTER_DEMUXER (G729,             g729);
#endif

#if CONFIG_GIF_DEMUXER 
#if CONFIG_GIF_MUXER 

	REGISTER_MUXDEMUX(GIF,              gif);
#endif
#endif

#if CONFIG_GSM_DEMUXER 

	REGISTER_DEMUXER (GSM,              gsm);
#endif

#if CONFIG_GXF_DEMUXER 
#if CONFIG_GXF_MUXER 

	REGISTER_MUXDEMUX(GXF,              gxf);
#endif
#endif

#if CONFIG_H261_DEMUXER 
#if CONFIG_H261_MUXER 

	REGISTER_MUXDEMUX(H261,             h261);
#endif
#endif

#if CONFIG_H263_DEMUXER 
#if CONFIG_H263_MUXER 

	REGISTER_MUXDEMUX(H263,             h263);
#endif
#endif

#if CONFIG_H264_DEMUXER 
#if CONFIG_H264_MUXER 

	REGISTER_MUXDEMUX(H264,             h264);
#endif
#endif

#if CONFIG_HLS_DEMUXER 
#if CONFIG_HLS_MUXER 

	REGISTER_MUXDEMUX(HLS,              hls);
#endif
#endif

#if CONFIG_ICO_DEMUXER 
#if CONFIG_ICO_MUXER 

	REGISTER_MUXDEMUX(ICO,              ico);
#endif
#endif

#if CONFIG_IDCIN_DEMUXER 

	REGISTER_DEMUXER (IDCIN,            idcin);
#endif

#if CONFIG_IDF_DEMUXER 

	REGISTER_DEMUXER (IDF,              idf);
#endif

#if CONFIG_IFF_DEMUXER 

	REGISTER_DEMUXER (IFF,              iff);
#endif

#if CONFIG_ILBC_DEMUXER 
#if CONFIG_ILBC_MUXER 

	REGISTER_MUXDEMUX(ILBC,             ilbc);
#endif
#endif

#if CONFIG_IMAGE2_DEMUXER 
#if CONFIG_IMAGE2_MUXER 

	REGISTER_MUXDEMUX(IMAGE2,           image2);
#endif
#endif

#if CONFIG_IMAGE2PIPE_DEMUXER 
#if CONFIG_IMAGE2PIPE_MUXER 

	REGISTER_MUXDEMUX(IMAGE2PIPE,       image2pipe);
#endif
#endif

#if CONFIG_INGENIENT_DEMUXER 

	REGISTER_DEMUXER (INGENIENT,        ingenient);
#endif

#if CONFIG_IPMOVIE_DEMUXER 

	REGISTER_DEMUXER (IPMOVIE,          ipmovie);
#endif

#if CONFIG_IPOD_MUXER 

	REGISTER_MUXER   (IPOD,             ipod);
#endif

#if CONFIG_IRCAM_DEMUXER 
#if CONFIG_IRCAM_MUXER 

	REGISTER_MUXDEMUX(IRCAM,            ircam);
#endif
#endif

#if CONFIG_ISMV_MUXER 

	REGISTER_MUXER   (ISMV,             ismv);
#endif

#if CONFIG_ISS_DEMUXER 

	REGISTER_DEMUXER (ISS,              iss);
#endif

#if CONFIG_IV8_DEMUXER 

	REGISTER_DEMUXER (IV8,              iv8);
#endif

#if CONFIG_IVF_DEMUXER 
#if CONFIG_IVF_MUXER 

	REGISTER_MUXDEMUX(IVF,              ivf);
#endif
#endif

#if CONFIG_JACOSUB_DEMUXER 
#if CONFIG_JACOSUB_MUXER 

	REGISTER_MUXDEMUX(JACOSUB,          jacosub);
#endif
#endif

#if CONFIG_JV_DEMUXER 

	REGISTER_DEMUXER (JV,               jv);
#endif

#if CONFIG_LATM_DEMUXER 
#if CONFIG_LATM_MUXER 

	REGISTER_MUXDEMUX(LATM,             latm);
#endif
#endif

#if CONFIG_LMLM4_DEMUXER 

	REGISTER_DEMUXER (LMLM4,            lmlm4);
#endif

#if CONFIG_LOAS_DEMUXER 

	REGISTER_DEMUXER (LOAS,             loas);
#endif

#if CONFIG_LVF_DEMUXER 

	REGISTER_DEMUXER (LVF,              lvf);
#endif

#if CONFIG_LXF_DEMUXER 

	REGISTER_DEMUXER (LXF,              lxf);
#endif

#if CONFIG_M4V_DEMUXER 
#if CONFIG_M4V_MUXER

	REGISTER_MUXDEMUX(M4V,              m4v);
#endif
#endif

#if CONFIG_MD5_MUXER 

	REGISTER_MUXER   (MD5,              md5);
#endif

#if CONFIG_MATROSKA_DEMUXER 
#if CONFIG_MATROSKA_MUXER 

	REGISTER_MUXDEMUX(MATROSKA,         matroska);
#endif
#endif

#if CONFIG_MATROSKA_AUDIO_MUXER 

	REGISTER_MUXER   (MATROSKA_AUDIO,   matroska_audio);
#endif

#if CONFIG_MGSTS_DEMUXER 

	REGISTER_DEMUXER (MGSTS,            mgsts);
#endif

#if CONFIG_MICRODVD_DEMUXER 
#if CONFIG_MICRODVD_MUXER 

	REGISTER_MUXDEMUX(MICRODVD,         microdvd);
#endif
#endif

#if CONFIG_MJPEG_DEMUXER 
#if CONFIG_MJPEG_MUXER 

	REGISTER_MUXDEMUX(MJPEG,            mjpeg);
#endif
#endif

#if CONFIG_MLP_DEMUXER 
#if CONFIG_MLP_MUXER 

	REGISTER_MUXDEMUX(MLP,              mlp);
#endif
#endif

#if CONFIG_MM_DEMUXER 

	REGISTER_DEMUXER (MM,               mm);
#endif

#if CONFIG_MMF_DEMUXER 
#if CONFIG_MMF_MUXER 

	REGISTER_MUXDEMUX(MMF,              mmf);
#endif
#endif

#if CONFIG_MOV_DEMUXER 
#if CONFIG_MOV_MUXER 

	REGISTER_MUXDEMUX(MOV,              mov);
#endif
#endif

#if CONFIG_MP2_MUXER 

	REGISTER_MUXER   (MP2,              mp2);
#endif

#if CONFIG_MP3_DEMUXER 
#if CONFIG_MP3_MUXER 

	REGISTER_MUXDEMUX(MP3,              mp3);
#endif
#endif

#if CONFIG_MP4_MUXER 

	REGISTER_MUXER   (MP4,              mp4);
#endif

#if CONFIG_MPC_DEMUXER 

	REGISTER_DEMUXER (MPC,              mpc);
#endif

#if CONFIG_MPC8_DEMUXER 

	REGISTER_DEMUXER (MPC8,             mpc8);
#endif

#if CONFIG_MPEG1SYSTEM_MUXER 

	REGISTER_MUXER   (MPEG1SYSTEM,      mpeg1system);
#endif

#if CONFIG_MPEG1VCD_MUXER 

	REGISTER_MUXER   (MPEG1VCD,         mpeg1vcd);
#endif

#if CONFIG_MPEG1VIDEO_MUXER 

	REGISTER_MUXER   (MPEG1VIDEO,       mpeg1video);
#endif

#if CONFIG_MPEG2DVD_MUXER 

	REGISTER_MUXER   (MPEG2DVD,         mpeg2dvd);
#endif

#if CONFIG_MPEG2SVCD_MUXER 

	REGISTER_MUXER   (MPEG2SVCD,        mpeg2svcd);
#endif

#if CONFIG_MPEG2VIDEO_MUXER 

	REGISTER_MUXER   (MPEG2VIDEO,       mpeg2video);
#endif

#if CONFIG_MPEG2VOB_MUXER 

	REGISTER_MUXER   (MPEG2VOB,         mpeg2vob);
#endif

#if CONFIG_MPEGPS_DEMUXER 

	REGISTER_DEMUXER (MPEGPS,           mpegps);
#endif

#if CONFIG_MPEGTS_DEMUXER 
#if CONFIG_MPEGTS_MUXER 

	REGISTER_MUXDEMUX(MPEGTS,           mpegts);
#endif
#endif

#if CONFIG_MPEGTSRAW_DEMUXER 

	REGISTER_DEMUXER (MPEGTSRAW,        mpegtsraw);
#endif

#if CONFIG_MPEGVIDEO_DEMUXER 

	REGISTER_DEMUXER (MPEGVIDEO,        mpegvideo);
#endif

#if CONFIG_MPJPEG_MUXER 

	REGISTER_MUXER   (MPJPEG,           mpjpeg);
#endif

#if CONFIG_MPL2_DEMUXER 

	REGISTER_DEMUXER (MPL2,             mpl2);
#endif

#if CONFIG_MPSUB_DEMUXER 

	REGISTER_DEMUXER (MPSUB,            mpsub);
#endif

#if CONFIG_MSNWC_TCP_DEMUXER 

	REGISTER_DEMUXER (MSNWC_TCP,        msnwc_tcp);
#endif

#if CONFIG_MTV_DEMUXER 

	REGISTER_DEMUXER (MTV,              mtv);
#endif

#if CONFIG_MV_DEMUXER 

	REGISTER_DEMUXER (MV,               mv);
#endif

#if CONFIG_MVI_DEMUXER 

	REGISTER_DEMUXER (MVI,              mvi);
#endif

#if CONFIG_MXF_DEMUXER 
#if CONFIG_MXF_MUXER 

	REGISTER_MUXDEMUX(MXF,              mxf);
#endif
#endif

#if CONFIG_MXF_D10_MUXER 

	REGISTER_MUXER   (MXF_D10,          mxf_d10);
#endif

#if CONFIG_MXG_DEMUXER 

	REGISTER_DEMUXER (MXG,              mxg);
#endif

#if CONFIG_NC_DEMUXER 

	REGISTER_DEMUXER (NC,               nc);
#endif

#if CONFIG_NISTSPHERE_DEMUXER 

	REGISTER_DEMUXER (NISTSPHERE,       nistsphere);
#endif

#if CONFIG_NSV_DEMUXER 

	REGISTER_DEMUXER (NSV,              nsv);
#endif

#if CONFIG_NULL_MUXER 

	REGISTER_MUXER   (NULL,             null);
#endif

#if CONFIG_NUT_DEMUXER 
#if CONFIG_NUT_MUXER 

	REGISTER_MUXDEMUX(NUT,              nut);
#endif
#endif

#if CONFIG_NUV_DEMUXER 

	REGISTER_DEMUXER (NUV,              nuv);
#endif

#if CONFIG_OGG_DEMUXER 
#if CONFIG_OGG_MUXER 

	REGISTER_MUXDEMUX(OGG,              ogg);
#endif
#endif

#if CONFIG_OMA_DEMUXER 
#if CONFIG_OMA_MUXER 

	REGISTER_MUXDEMUX(OMA,              oma);
#endif
#endif

#if CONFIG_PAF_DEMUXER 

	REGISTER_DEMUXER (PAF,              paf);
#endif

#if CONFIG_PCM_ALAW_DEMUXER 
#if CONFIG_PCM_ALAW_MUXER 

	REGISTER_MUXDEMUX(PCM_ALAW,         pcm_alaw);
#endif
#endif

#if CONFIG_PCM_MULAW_DEMUXER 
#if CONFIG_PCM_MULAW_MUXER 

	REGISTER_MUXDEMUX(PCM_MULAW,        pcm_mulaw);
#endif
#endif

#if CONFIG_PCM_F64BE_DEMUXER 
#if CONFIG_PCM_F64BE_MUXER 

	REGISTER_MUXDEMUX(PCM_F64BE,        pcm_f64be);
#endif
#endif

#if CONFIG_PCM_F64LE_DEMUXER 
#if CONFIG_PCM_F64LE_MUXER 

	REGISTER_MUXDEMUX(PCM_F64LE,        pcm_f64le);
#endif
#endif

#if CONFIG_PCM_F32BE_DEMUXER 
#if CONFIG_PCM_F32BE_MUXER 

	REGISTER_MUXDEMUX(PCM_F32BE,        pcm_f32be);
#endif
#endif

#if CONFIG_PCM_F32LE_DEMUXER 
#if CONFIG_PCM_F32LE_MUXER 

	REGISTER_MUXDEMUX(PCM_F32LE,        pcm_f32le);
#endif
#endif

#if CONFIG_PCM_S32BE_DEMUXER 
#if CONFIG_PCM_S32BE_MUXER 

	REGISTER_MUXDEMUX(PCM_S32BE,        pcm_s32be);
#endif
#endif

#if CONFIG_PCM_S32LE_DEMUXER 
#if CONFIG_PCM_S32LE_MUXER 

	REGISTER_MUXDEMUX(PCM_S32LE,        pcm_s32le);
#endif
#endif

#if CONFIG_PCM_S24BE_DEMUXER 
#if CONFIG_PCM_S24BE_MUXER 

	REGISTER_MUXDEMUX(PCM_S24BE,        pcm_s24be);
#endif
#endif

#if CONFIG_PCM_S24LE_DEMUXER 
#if CONFIG_PCM_S24LE_MUXER 

	REGISTER_MUXDEMUX(PCM_S24LE,        pcm_s24le);
#endif
#endif

#if CONFIG_PCM_S16BE_DEMUXER 
#if CONFIG_PCM_S16BE_MUXER 

	REGISTER_MUXDEMUX(PCM_S16BE,        pcm_s16be);
#endif
#endif

#if CONFIG_PCM_S16LE_DEMUXER 
#if CONFIG_PCM_S16LE_MUXER 

	REGISTER_MUXDEMUX(PCM_S16LE,        pcm_s16le);
#endif
#endif

#if CONFIG_PCM_S8_DEMUXER 
#if CONFIG_PCM_S8_MUXER 

	REGISTER_MUXDEMUX(PCM_S8,           pcm_s8);
#endif
#endif

#if CONFIG_PCM_U32BE_DEMUXER 
#if CONFIG_PCM_U32BE_MUXER 

	REGISTER_MUXDEMUX(PCM_U32BE,        pcm_u32be);
#endif
#endif

#if CONFIG_PCM_U32LE_DEMUXER 
#if CONFIG_PCM_U32LE_MUXER 

	REGISTER_MUXDEMUX(PCM_U32LE,        pcm_u32le);
#endif
#endif

#if CONFIG_PCM_U24BE_DEMUXER 
#if CONFIG_PCM_U24BE_MUXER 

	REGISTER_MUXDEMUX(PCM_U24BE,        pcm_u24be);
#endif
#endif

#if CONFIG_PCM_U24LE_DEMUXER 
#if CONFIG_PCM_U24LE_MUXER 

	REGISTER_MUXDEMUX(PCM_U24LE,        pcm_u24le);
#endif
#endif

#if CONFIG_PCM_U16BE_DEMUXER 
#if CONFIG_PCM_U16BE_MUXER 

	REGISTER_MUXDEMUX(PCM_U16BE,        pcm_u16be);
#endif
#endif

#if CONFIG_PCM_U16LE_DEMUXER 
#if CONFIG_PCM_U16LE_MUXER 

	REGISTER_MUXDEMUX(PCM_U16LE,        pcm_u16le);
#endif
#endif

#if CONFIG_PCM_U8_DEMUXER 
#if CONFIG_PCM_U8_MUXER 

	REGISTER_MUXDEMUX(PCM_U8,           pcm_u8);
#endif
#endif

#if CONFIG_PJS_DEMUXER 

	REGISTER_DEMUXER (PJS,              pjs);
#endif

#if CONFIG_PMP_DEMUXER 

	REGISTER_DEMUXER (PMP,              pmp);
#endif

#if CONFIG_PSP_MUXER 

	REGISTER_MUXER   (PSP,              psp);
#endif

#if CONFIG_PVA_DEMUXER 

	REGISTER_DEMUXER (PVA,              pva);
#endif

#if CONFIG_PVF_DEMUXER 

	REGISTER_DEMUXER (PVF,              pvf);
#endif

#if CONFIG_QCP_DEMUXER 

	REGISTER_DEMUXER (QCP,              qcp);
#endif

#if CONFIG_R3D_DEMUXER 

	REGISTER_DEMUXER (R3D,              r3d);
#endif

#if CONFIG_RAWVIDEO_DEMUXER 
#if CONFIG_RAWVIDEO_MUXER 

	REGISTER_MUXDEMUX(RAWVIDEO,         rawvideo);
#endif
#endif

#if CONFIG_REALTEXT_DEMUXER 

	REGISTER_DEMUXER (REALTEXT,         realtext);
#endif

#if CONFIG_REDSPARK_DEMUXER 

	REGISTER_DEMUXER (REDSPARK,         redspark);
#endif

#if CONFIG_RL2_DEMUXER 

	REGISTER_DEMUXER (RL2,              rl2);
#endif

#if CONFIG_RM_DEMUXER 
#if CONFIG_RM_MUXER 

	REGISTER_MUXDEMUX(RM,               rm);
#endif
#endif

#if CONFIG_ROQ_DEMUXER 
#if CONFIG_ROQ_MUXER 

	REGISTER_MUXDEMUX(ROQ,              roq);
#endif
#endif

#if CONFIG_RPL_DEMUXER 

	REGISTER_DEMUXER (RPL,              rpl);
#endif

#if CONFIG_RSD_DEMUXER 

	REGISTER_DEMUXER (RSD,              rsd);
#endif

#if CONFIG_RSO_DEMUXER 
#if CONFIG_RSO_MUXER 

	REGISTER_MUXDEMUX(RSO,              rso);
#endif
#endif

#if CONFIG_RTP_DEMUXER 
#if CONFIG_RTP_MUXER 

	REGISTER_MUXDEMUX(RTP,              rtp);
#endif
#endif

#if CONFIG_RTSP_DEMUXER 
#if CONFIG_RTSP_MUXER 

	REGISTER_MUXDEMUX(RTSP,             rtsp);
#endif
#endif

#if CONFIG_SAMI_DEMUXER 

	REGISTER_DEMUXER (SAMI,             sami);
#endif

#if CONFIG_SAP_DEMUXER 
#if CONFIG_SAP_MUXER 

	REGISTER_MUXDEMUX(SAP,              sap);
#endif
#endif

#if CONFIG_SBG_DEMUXER 

	REGISTER_DEMUXER (SBG,              sbg);
#endif

#if CONFIG_SDP_DEMUXER 

	REGISTER_DEMUXER (SDP,              sdp);
#endif

#if CONFIG_RTPDEC
    av_register_rtp_dynamic_payload_handlers();
    av_register_rdt_dynamic_payload_handlers();
#endif
#if CONFIG_SEGAFILM_DEMUXER 
	REGISTER_DEMUXER (SEGAFILM,         segafilm);
#endif

#if CONFIG_SEGMENT_MUXER 

	REGISTER_MUXER   (SEGMENT,          segment);
#endif

#if CONFIG_SEGMENT_MUXER 

	REGISTER_MUXER   (SEGMENT,          stream_segment);
#endif

#if CONFIG_SHORTEN_DEMUXER 

	REGISTER_DEMUXER (SHORTEN,          shorten);
#endif

#if CONFIG_SIFF_DEMUXER 

	REGISTER_DEMUXER (SIFF,             siff);
#endif

#if CONFIG_SMACKER_DEMUXER 

	REGISTER_DEMUXER (SMACKER,          smacker);
#endif

#if CONFIG_SMJPEG_DEMUXER 
#if CONFIG_SMJPEG_MUXER 

	REGISTER_MUXDEMUX(SMJPEG,           smjpeg);
#endif
#endif

#if CONFIG_SMOOTHSTREAMING_MUXER 

	REGISTER_MUXER   (SMOOTHSTREAMING,  smoothstreaming);
#endif

#if CONFIG_SMUSH_DEMUXER 

	REGISTER_DEMUXER (SMUSH,            smush);
#endif

#if CONFIG_SOL_DEMUXER 

	REGISTER_DEMUXER (SOL,              sol);
#endif

#if CONFIG_SOX_DEMUXER 
#if CONFIG_SOX_MUXER 

	REGISTER_MUXDEMUX(SOX,              sox);
#endif
#endif

#if CONFIG_SPDIF_DEMUXER 
#if CONFIG_SPDIF_MUXER 

	REGISTER_MUXDEMUX(SPDIF,            spdif);
#endif
#endif

#if CONFIG_SRT_DEMUXER 
#if CONFIG_SRT_MUXER 

	REGISTER_MUXDEMUX(SRT,              srt);
#endif
#endif

#if CONFIG_STR_DEMUXER 

	REGISTER_DEMUXER (STR,              str);
#endif

#if CONFIG_SUBVIEWER1_DEMUXER 

	REGISTER_DEMUXER (SUBVIEWER1,       subviewer1);
#endif

#if CONFIG_SUBVIEWER_DEMUXER 

	REGISTER_DEMUXER (SUBVIEWER,        subviewer);
#endif

#if CONFIG_SWF_DEMUXER 
#if CONFIG_SWF_MUXER 

	REGISTER_MUXDEMUX(SWF,              swf);
#endif
#endif

#if CONFIG_TAK_DEMUXER 

	REGISTER_DEMUXER (TAK,              tak);
#endif

#if CONFIG_TEE_MUXER 

	REGISTER_MUXER   (TEE,              tee);
#endif

#if CONFIG_TEDCAPTIONS_DEMUXER 

	REGISTER_DEMUXER (TEDCAPTIONS,      tedcaptions);
#endif

#if CONFIG_TG2_MUXER 

	REGISTER_MUXER   (TG2,              tg2);
#endif

#if CONFIG_TGP_MUXER 

	REGISTER_MUXER   (TGP,              tgp);
#endif

#if CONFIG_THP_DEMUXER 

	REGISTER_DEMUXER (THP,              thp);
#endif

#if CONFIG_TIERTEXSEQ_DEMUXER 

	REGISTER_DEMUXER (TIERTEXSEQ,       tiertexseq);
#endif

#if CONFIG_MKVTIMESTAMP_V2_MUXER 

	REGISTER_MUXER   (MKVTIMESTAMP_V2,  mkvtimestamp_v2);
#endif

#if CONFIG_TMV_DEMUXER 

	REGISTER_DEMUXER (TMV,              tmv);
#endif

#if CONFIG_TRUEHD_DEMUXER 
#if CONFIG_TRUEHD_MUXER 

	REGISTER_MUXDEMUX(TRUEHD,           truehd);
#endif
#endif

#if CONFIG_TTA_DEMUXER 

	REGISTER_DEMUXER (TTA,              tta);
#endif

#if CONFIG_TXD_DEMUXER 

	REGISTER_DEMUXER (TXD,              txd);
#endif

#if CONFIG_TTY_DEMUXER 

	REGISTER_DEMUXER (TTY,              tty);
#endif

#if CONFIG_VC1_DEMUXER 
#if CONFIG_VC1_MUXER 

	REGISTER_MUXDEMUX(VC1,              vc1);
#endif
#endif

#if CONFIG_VC1T_DEMUXER 
#if CONFIG_VC1T_MUXER 

	REGISTER_MUXDEMUX(VC1T,             vc1t);
#endif
#endif

#if CONFIG_VIVO_DEMUXER 

	REGISTER_DEMUXER (VIVO,             vivo);
#endif

#if CONFIG_VMD_DEMUXER 

	REGISTER_DEMUXER (VMD,              vmd);
#endif

#if CONFIG_VOBSUB_DEMUXER 

	REGISTER_DEMUXER (VOBSUB,           vobsub);
#endif

#if CONFIG_VOC_DEMUXER 
#if CONFIG_VOC_MUXER 

	REGISTER_MUXDEMUX(VOC,              voc);
#endif
#endif

#if CONFIG_VPLAYER_DEMUXER 

	REGISTER_DEMUXER (VPLAYER,          vplayer);
#endif

#if CONFIG_VQF_DEMUXER 

	REGISTER_DEMUXER (VQF,              vqf);
#endif

#if CONFIG_W64_DEMUXER 
#if CONFIG_W64_MUXER 

	REGISTER_MUXDEMUX(W64,              w64);
#endif
#endif

#if CONFIG_WAV_DEMUXER 
#if CONFIG_WAV_MUXER 

	REGISTER_MUXDEMUX(WAV,              wav);
#endif
#endif

#if CONFIG_WC3_DEMUXER 

	REGISTER_DEMUXER (WC3,              wc3);
#endif

#if CONFIG_WEBM_MUXER 

	REGISTER_MUXER   (WEBM,             webm);
#endif

#if CONFIG_WEBVTT_DEMUXER 
#if CONFIG_WEBVTT_MUXER 

	REGISTER_MUXDEMUX(WEBVTT,           webvtt);
#endif
#endif

#if CONFIG_WSAUD_DEMUXER 

	REGISTER_DEMUXER (WSAUD,            wsaud);
#endif

#if CONFIG_WSVQA_DEMUXER 

	REGISTER_DEMUXER (WSVQA,            wsvqa);
#endif

#if CONFIG_WTV_DEMUXER 
#if CONFIG_WTV_MUXER 

	REGISTER_MUXDEMUX(WTV,              wtv);
#endif
#endif

#if CONFIG_WV_DEMUXER 
#if CONFIG_WV_MUXER 

	REGISTER_MUXDEMUX(WV,               wv);
#endif
#endif

#if CONFIG_XA_DEMUXER 

	REGISTER_DEMUXER (XA,               xa);
#endif

#if CONFIG_XBIN_DEMUXER 

	REGISTER_DEMUXER (XBIN,             xbin);
#endif

#if CONFIG_XMV_DEMUXER 

	REGISTER_DEMUXER (XMV,              xmv);
#endif

#if CONFIG_XWMA_DEMUXER 

	REGISTER_DEMUXER (XWMA,             xwma);
#endif

#if CONFIG_YOP_DEMUXER 

	REGISTER_DEMUXER (YOP,              yop);
#endif

#if CONFIG_YUV4MPEGPIPE_DEMUXER 
#if CONFIG_YUV4MPEGPIPE_MUXER 

	REGISTER_MUXDEMUX(YUV4MPEGPIPE,     yuv4mpegpipe);
#endif
#endif

#if CONFIG_BLURAY_PROTOCOL 


	/* protocols */
	REGISTER_PROTOCOL(BLURAY,           bluray);
#endif

#if CONFIG_CACHE_PROTOCOL 

	REGISTER_PROTOCOL(CACHE,            cache);
#endif

#if CONFIG_CONCAT_PROTOCOL 

	REGISTER_PROTOCOL(CONCAT,           concat);
#endif

#if CONFIG_CRYPTO_PROTOCOL 

	REGISTER_PROTOCOL(CRYPTO,           crypto);
#endif

#if CONFIG_DATA_PROTOCOL 

	REGISTER_PROTOCOL(DATA,             data);
#endif

#if CONFIG_FFRTMPCRYPT_PROTOCOL 

	REGISTER_PROTOCOL(FFRTMPCRYPT,      ffrtmpcrypt);
#endif

#if CONFIG_FFRTMPHTTP_PROTOCOL 

	REGISTER_PROTOCOL(FFRTMPHTTP,       ffrtmphttp);
#endif

#if CONFIG_FILE_PROTOCOL 

	REGISTER_PROTOCOL(FILE,             file);
#endif

#if CONFIG_FTP_PROTOCOL 

	REGISTER_PROTOCOL(FTP,              ftp);
#endif

#if CONFIG_GOPHER_PROTOCOL 

	REGISTER_PROTOCOL(GOPHER,           gopher);
#endif

#if CONFIG_HLS_PROTOCOL 

	REGISTER_PROTOCOL(HLS,              hls);
#endif

#if CONFIG_HTTP_PROTOCOL 

	REGISTER_PROTOCOL(HTTP,             http);
#endif

#if CONFIG_HTTPPROXY_PROTOCOL 

	REGISTER_PROTOCOL(HTTPPROXY,        httpproxy);
#endif

#if CONFIG_HTTPS_PROTOCOL 

	REGISTER_PROTOCOL(HTTPS,            https);
#endif

#if CONFIG_MMSH_PROTOCOL 

	REGISTER_PROTOCOL(MMSH,             mmsh);
#endif

#if CONFIG_MMST_PROTOCOL 

	REGISTER_PROTOCOL(MMST,             mmst);
#endif

#if CONFIG_MD5_PROTOCOL 

	REGISTER_PROTOCOL(MD5,              md5);
#endif

#if CONFIG_PIPE_PROTOCOL 

	REGISTER_PROTOCOL(PIPE,             pipe);
#endif

#if CONFIG_RTMP_PROTOCOL 

	REGISTER_PROTOCOL(RTMP,             rtmp);
#endif

#if CONFIG_RTMPE_PROTOCOL 

	REGISTER_PROTOCOL(RTMPE,            rtmpe);
#endif

#if CONFIG_RTMPS_PROTOCOL 

	REGISTER_PROTOCOL(RTMPS,            rtmps);
#endif

#if CONFIG_RTMPT_PROTOCOL 

	REGISTER_PROTOCOL(RTMPT,            rtmpt);
#endif

#if CONFIG_RTMPTE_PROTOCOL 

	REGISTER_PROTOCOL(RTMPTE,           rtmpte);
#endif

#if CONFIG_RTMPTS_PROTOCOL 

	REGISTER_PROTOCOL(RTMPTS,           rtmpts);
#endif

#if CONFIG_RTP_PROTOCOL 

	REGISTER_PROTOCOL(RTP,              rtp);
#endif

#if CONFIG_SCTP_PROTOCOL 

	REGISTER_PROTOCOL(SCTP,             sctp);
#endif

#if CONFIG_SRTP_PROTOCOL 

	REGISTER_PROTOCOL(SRTP,             srtp);
#endif

#if CONFIG_TCP_PROTOCOL 

	REGISTER_PROTOCOL(TCP,              tcp);
#endif

#if CONFIG_TLS_PROTOCOL 

	REGISTER_PROTOCOL(TLS,              tls);
#endif

#if CONFIG_UDP_PROTOCOL 

	REGISTER_PROTOCOL(UDP,              udp);
#endif

/* external libraries */
#if CONFIG_LIBGME_DEMUXER 
	REGISTER_DEMUXER (LIBGME,           libgme);
#endif

#if CONFIG_LIBMODPLUG_DEMUXER 
	REGISTER_DEMUXER (LIBMODPLUG,       libmodplug);
#endif

#if CONFIG_LIBNUT_DEMUXER 
#if CONFIG_LIBNUT_MUXER 
	REGISTER_MUXDEMUX(LIBNUT,           libnut);
#endif
#endif

#if CONFIG_LIBQUVI_DEMUXER 

	REGISTER_DEMUXER (LIBQUVI,          libquvi);
#endif

#if CONFIG_LIBRTMP_PROTOCOL 

	REGISTER_PROTOCOL(LIBRTMP,          librtmp);
#endif

#if CONFIG_LIBRTMPE_PROTOCOL 

	REGISTER_PROTOCOL(LIBRTMPE,         librtmpe);
#endif

#if CONFIG_LIBRTMPS_PROTOCOL 

	REGISTER_PROTOCOL(LIBRTMPS,         librtmps);
#endif

#if CONFIG_LIBRTMPT_PROTOCOL 

	REGISTER_PROTOCOL(LIBRTMPT,         librtmpt);
#endif

#if CONFIG_LIBRTMPTE_PROTOCOL 

	REGISTER_PROTOCOL(LIBRTMPTE,        librtmpte);
#endif
}
