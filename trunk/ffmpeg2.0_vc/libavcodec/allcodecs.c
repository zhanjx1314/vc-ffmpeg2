/*
 * Provide registration of all codecs, parsers and bitstream filters for libavcodec.
 * Copyright (c) 2002 Fabrice Bellard
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
 * Provide registration of all codecs, parsers and bitstream filters for libavcodec.
 */

#include "avcodec.h"
#include "config.h"

#define REGISTER_HWACCEL(X, x)                                          \
    {                                                                   \
        extern AVHWAccel ff_##x##_hwaccel;                              \
        if (CONFIG_##X##_HWACCEL)                                       \
            av_register_hwaccel(&ff_##x##_hwaccel);                     \
    }

#define REGISTER_ENCODER(X, x)                                          \
    {                                                                   \
        extern AVCodec ff_##x##_encoder;                                \
        if (CONFIG_##X##_ENCODER)                                       \
            avcodec_register(&ff_##x##_encoder);                        \
    }

#define REGISTER_DECODER(X, x)                                          \
    {                                                                   \
        extern AVCodec ff_##x##_decoder;                                \
        if (CONFIG_##X##_DECODER)                                       \
            avcodec_register(&ff_##x##_decoder);                        \
    }

#define REGISTER_ENCDEC(X, x) REGISTER_ENCODER(X, x); REGISTER_DECODER(X, x);

#define REGISTER_PARSER(X, x)                                           \
    {                                                                   \
        extern AVCodecParser ff_##x##_parser;                           \
        if (CONFIG_##X##_PARSER)                                        \
            av_register_codec_parser(&ff_##x##_parser);                 \
    }

#define REGISTER_BSF(X, x)                                              \
    {                                                                   \
        extern AVBitStreamFilter ff_##x##_bsf;                          \
        if (CONFIG_##X##_BSF)                                           \
            av_register_bitstream_filter(&ff_##x##_bsf);                \
    }

void avcodec_register_all(void)
{
    static int initialized;

    if (initialized)
        return;
    initialized = 1;

    /* hardware accelerators */
#if CONFIG_H263_VAAPI_HWACCEL 
	REGISTER_HWACCEL(H263_VAAPI,        h263_vaapi);
#endif

#if CONFIG_H263_VDPAU_HWACCEL 


	REGISTER_HWACCEL(H263_VDPAU,        h263_vdpau);
#endif

#if CONFIG_H264_DXVA2_HWACCEL 


	REGISTER_HWACCEL(H264_DXVA2,        h264_dxva2);
#endif

#if CONFIG_H264_VAAPI_HWACCEL 


	REGISTER_HWACCEL(H264_VAAPI,        h264_vaapi);
#endif

#if CONFIG_H264_VDA_HWACCEL 



	REGISTER_HWACCEL(H264_VDA,          h264_vda);
#endif

#if CONFIG_H264_VDPAU_HWACCEL 



	REGISTER_HWACCEL(H264_VDPAU,        h264_vdpau);
#endif

#if CONFIG_MPEG1_VDPAU_HWACCEL 



	REGISTER_HWACCEL(MPEG1_VDPAU,       mpeg1_vdpau);
#endif

#if CONFIG_MPEG2_DXVA2_HWACCEL 



	REGISTER_HWACCEL(MPEG2_DXVA2,       mpeg2_dxva2);
#endif

#if CONFIG_MPEG2_VAAPI_HWACCEL 



	REGISTER_HWACCEL(MPEG2_VAAPI,       mpeg2_vaapi);
#endif

#if CONFIG_MPEG2_VDPAU_HWACCEL 



	REGISTER_HWACCEL(MPEG2_VDPAU,       mpeg2_vdpau);
#endif

#if CONFIG_MPEG4_VAAPI_HWACCEL 



	REGISTER_HWACCEL(MPEG4_VAAPI,       mpeg4_vaapi);
#endif

#if CONFIG_MPEG4_VDPAU_HWACCEL 



	REGISTER_HWACCEL(MPEG4_VDPAU,       mpeg4_vdpau);
#endif

#if CONFIG_VC1_DXVA2_HWACCEL 



	REGISTER_HWACCEL(VC1_DXVA2,         vc1_dxva2);
#endif

#if CONFIG_VC1_VAAPI_HWACCEL 



	REGISTER_HWACCEL(VC1_VAAPI,         vc1_vaapi);
#endif

#if CONFIG_VC1_VDPAU_HWACCEL 



	REGISTER_HWACCEL(VC1_VDPAU,         vc1_vdpau);
#endif

#if CONFIG_WMV3_DXVA2_HWACCEL 



	REGISTER_HWACCEL(WMV3_DXVA2,        wmv3_dxva2);
#endif

#if CONFIG_WMV3_VAAPI_HWACCEL 



	REGISTER_HWACCEL(WMV3_VAAPI,        wmv3_vaapi);
#endif

#if CONFIG_WMV3_VDPAU_HWACCEL 



	REGISTER_HWACCEL(WMV3_VDPAU,        wmv3_vdpau);
#endif

#if CONFIG_A64MULTI_ENCODER 


	/* video codecs */


	REGISTER_ENCODER(A64MULTI,          a64multi);
#endif

#if CONFIG_A64MULTI5_ENCODER 



	REGISTER_ENCODER(A64MULTI5,         a64multi5);
#endif

#if CONFIG_AASC_DECODER 



	REGISTER_DECODER(AASC,              aasc);
#endif

#if CONFIG_AIC_DECODER 



	REGISTER_DECODER(AIC,               aic);
#endif

#if CONFIG_AMV_ENCODER 
#if CONFIG_AMV_DECODER 



	REGISTER_ENCDEC (AMV,               amv);
#endif
#endif

#if CONFIG_ANM_DECODER 



	REGISTER_DECODER(ANM,               anm);
#endif

#if CONFIG_ANSI_DECODER 



	REGISTER_DECODER(ANSI,              ansi);
#endif

#if CONFIG_ASV1_ENCODER 
#if CONFIG_ASV1_DECODER 



	REGISTER_ENCDEC (ASV1,              asv1);
#endif
#endif

#if CONFIG_ASV2_ENCODER 
#if CONFIG_ASV2_DECODER 



	REGISTER_ENCDEC (ASV2,              asv2);
#endif
#endif

#if CONFIG_AURA_DECODER 



	REGISTER_DECODER(AURA,              aura);
#endif

#if CONFIG_AURA2_DECODER 



	REGISTER_DECODER(AURA2,             aura2);
#endif

#if CONFIG_AVRP_ENCODER 
#if CONFIG_AVRP_DECODER 



	REGISTER_ENCDEC (AVRP,              avrp);
#endif
#endif

#if CONFIG_AVRN_DECODER 



	REGISTER_DECODER(AVRN,              avrn);
#endif

#if CONFIG_AVS_DECODER 



	REGISTER_DECODER(AVS,               avs);
#endif

#if CONFIG_AVUI_ENCODER 
#if CONFIG_AVUI_DECODER 



	REGISTER_ENCDEC (AVUI,              avui);
#endif
#endif

#if CONFIG_AYUV_ENCODER 
#if CONFIG_AYUV_DECODER 



	REGISTER_ENCDEC (AYUV,              ayuv);
#endif
#endif

#if CONFIG_BETHSOFTVID_DECODER 



	REGISTER_DECODER(BETHSOFTVID,       bethsoftvid);
#endif

#if CONFIG_BFI_DECODER 



	REGISTER_DECODER(BFI,               bfi);
#endif

#if CONFIG_BINK_DECODER 



	REGISTER_DECODER(BINK,              bink);
#endif

#if CONFIG_BMP_ENCODER 
#if CONFIG_BMP_DECODER 



	REGISTER_ENCDEC (BMP,               bmp);
#endif
#endif

#if CONFIG_BMV_VIDEO_DECODER 



	REGISTER_DECODER(BMV_VIDEO,         bmv_video);
#endif

#if CONFIG_BRENDER_PIX_DECODER 



	REGISTER_DECODER(BRENDER_PIX,       brender_pix);
#endif

#if CONFIG_C93_DECODER 



	REGISTER_DECODER(C93,               c93);
#endif

#if CONFIG_CAVS_DECODER 



	REGISTER_DECODER(CAVS,              cavs);
#endif

#if CONFIG_CDGRAPHICS_DECODER 



	REGISTER_DECODER(CDGRAPHICS,        cdgraphics);
#endif

#if CONFIG_CDXL_DECODER 



	REGISTER_DECODER(CDXL,              cdxl);
#endif

#if CONFIG_CINEPAK_DECODER 



	REGISTER_DECODER(CINEPAK,           cinepak);
#endif

#if CONFIG_CLJR_ENCODER 
#if CONFIG_CLJR_DECODER 



	REGISTER_ENCDEC(CLJR,              cljr);
#endif
#endif

#if CONFIG_CLLC_DECODER 



	REGISTER_DECODER(CLLC,              cllc);
#endif

#if CONFIG_COMFORTNOISE_ENCODER 
#if CONFIG_COMFORTNOISE_DECODER 



	REGISTER_ENCDEC(COMFORTNOISE,      comfortnoise);
#endif
#endif

#if CONFIG_CPIA_DECODER 



	REGISTER_DECODER(CPIA,              cpia);
#endif

#if CONFIG_CSCD_DECODER 



	REGISTER_DECODER(CSCD,              cscd);
#endif

#if CONFIG_CYUV_DECODER 



	REGISTER_DECODER(CYUV,              cyuv);
#endif

#if CONFIG_DFA_DECODER 



	REGISTER_DECODER(DFA,               dfa);
#endif

#if CONFIG_DIRAC_DECODER 



	REGISTER_DECODER(DIRAC,             dirac);
#endif

#if CONFIG_DNXHD_ENCODER 
#if CONFIG_DNXHD_DECODER 



	REGISTER_ENCDEC(DNXHD,             dnxhd);
#endif
#endif

#if CONFIG_DPX_ENCODER 
#if CONFIG_DPX_DECODER 



	REGISTER_ENCDEC(DPX,               dpx);
#endif
#endif

#if CONFIG_DSICINVIDEO_DECODER 



	REGISTER_DECODER(DSICINVIDEO,       dsicinvideo);
#endif

#if CONFIG_DVVIDEO_ENCODER 
#if CONFIG_DVVIDEO_DECODER 



	REGISTER_ENCDEC(DVVIDEO,           dvvideo);
#endif
#endif

#if CONFIG_DXA_DECODER 



	REGISTER_DECODER(DXA,               dxa);
#endif

#if CONFIG_DXTORY_DECODER 



	REGISTER_DECODER(DXTORY,            dxtory);
#endif

#if CONFIG_EACMV_DECODER 



	REGISTER_DECODER(EACMV,             eacmv);
#endif

#if CONFIG_EAMAD_DECODER 



	REGISTER_DECODER(EAMAD,             eamad);
#endif

#if CONFIG_EATGQ_DECODER 



	REGISTER_DECODER(EATGQ,             eatgq);
#endif

#if CONFIG_EATGV_DECODER 



	REGISTER_DECODER(EATGV,             eatgv);
#endif

#if CONFIG_EATQI_DECODER 



	REGISTER_DECODER(EATQI,             eatqi);
#endif

#if CONFIG_EIGHTBPS_DECODER 



	REGISTER_DECODER(EIGHTBPS,          eightbps);
#endif

#if CONFIG_EIGHTSVX_EXP_DECODER 



	REGISTER_DECODER(EIGHTSVX_EXP,      eightsvx_exp);
#endif

#if CONFIG_EIGHTSVX_FIB_DECODER 



	REGISTER_DECODER(EIGHTSVX_FIB,      eightsvx_fib);
#endif

#if CONFIG_ESCAPE124_DECODER 



	REGISTER_DECODER(ESCAPE124,         escape124);
#endif

#if CONFIG_ESCAPE130_DECODER 



	REGISTER_DECODER(ESCAPE130,         escape130);
#endif

#if CONFIG_EXR_DECODER 



	REGISTER_DECODER(EXR,               exr);
#endif

#if CONFIG_FFV1_ENCODER 
#if CONFIG_FFV1_DECODER 



	REGISTER_ENCDEC(FFV1,              ffv1);
#endif
#endif

#if CONFIG_FFVHUFF_ENCODER 
#if CONFIG_FFVHUFF_DECODER 



	REGISTER_ENCDEC(FFVHUFF,           ffvhuff);
#endif
#endif

#if CONFIG_FLASHSV_ENCODER 
#if CONFIG_FLASHSV_DECODER 



	REGISTER_ENCDEC(FLASHSV,           flashsv);
#endif
#endif

#if CONFIG_FLASHSV2_ENCODER 
#if CONFIG_FLASHSV2_DECODER 



	REGISTER_ENCDEC(FLASHSV2,          flashsv2);
#endif
#endif

#if CONFIG_FLIC_DECODER 



	REGISTER_DECODER(FLIC,              flic);
#endif

#if CONFIG_FLV_ENCODER 
#if CONFIG_FLV_DECODER 



	REGISTER_ENCDEC(FLV,               flv);
#endif
#endif

#if CONFIG_FOURXM_DECODER 



	REGISTER_DECODER(FOURXM,            fourxm);
#endif

#if CONFIG_FRAPS_DECODER 



	REGISTER_DECODER(FRAPS,             fraps);
#endif

#if CONFIG_FRWU_DECODER 



	REGISTER_DECODER(FRWU,              frwu);
#endif

#if CONFIG_G2M_DECODER 



	REGISTER_DECODER(G2M,               g2m);
#endif

#if CONFIG_GIF_ENCODER 
#if CONFIG_GIF_DECODER 



	REGISTER_ENCDEC(GIF,               gif);
#endif
#endif

#if CONFIG_H261_ENCODER 
#if CONFIG_H261_DECODER 



	REGISTER_ENCDEC(H261,              h261);
#endif
#endif

#if CONFIG_H263_ENCODER 
#if CONFIG_H263_DECODER 



	REGISTER_ENCDEC (H263,              h263);
#endif
#endif

#if CONFIG_H263I_DECODER 



	REGISTER_DECODER(H263I,             h263i);
#endif

#if CONFIG_H263P_ENCODER 
#if CONFIG_H263P_DECODER 



	REGISTER_ENCDEC (H263P,             h263p);
#endif
#endif

#if CONFIG_H264_DECODER 



	REGISTER_DECODER(H264,              h264);
#endif

#if CONFIG_H264_CRYSTALHD_DECODER 



	REGISTER_DECODER(H264_CRYSTALHD,    h264_crystalhd);
#endif

#if CONFIG_H264_VDA_DECODER 



	REGISTER_DECODER(H264_VDA,          h264_vda);
#endif

#if CONFIG_H264_VDPAU_DECODER 



	REGISTER_DECODER(H264_VDPAU,        h264_vdpau);
#endif

#if CONFIG_HUFFYUV_ENCODER 
#if CONFIG_HUFFYUV_DECODER 



	REGISTER_ENCDEC (HUFFYUV,           huffyuv);
#endif
#endif

#if CONFIG_IDCIN_DECODER 



	REGISTER_DECODER(IDCIN,             idcin);
#endif

#if CONFIG_IFF_BYTERUN1_DECODER 



	REGISTER_DECODER(IFF_BYTERUN1,      iff_byterun1);
#endif

#if CONFIG_IFF_ILBM_DECODER 



	REGISTER_DECODER(IFF_ILBM,          iff_ilbm);
#endif

#if CONFIG_INDEO2_DECODER 



	REGISTER_DECODER(INDEO2,            indeo2);
#endif

#if CONFIG_INDEO3_DECODER 



	REGISTER_DECODER(INDEO3,            indeo3);
#endif

#if CONFIG_INDEO4_DECODER 



	REGISTER_DECODER(INDEO4,            indeo4);
#endif

#if CONFIG_INDEO5_DECODER 



	REGISTER_DECODER(INDEO5,            indeo5);
#endif

#if CONFIG_INTERPLAY_VIDEO_DECODER 



	REGISTER_DECODER(INTERPLAY_VIDEO,   interplay_video);
#endif

#if CONFIG_JPEG2000_ENCODER 
#if CONFIG_JPEG2000_DECODER 



	REGISTER_ENCDEC (JPEG2000,          jpeg2000);
#endif
#endif

#if CONFIG_JPEGLS_ENCODER 
#if CONFIG_JPEGLS_DECODER 



	REGISTER_ENCDEC (JPEGLS,            jpegls);
#endif
#endif

#if CONFIG_JV_DECODER 



	REGISTER_DECODER(JV,                jv);
#endif

#if CONFIG_KGV1_DECODER 



	REGISTER_DECODER(KGV1,              kgv1);
#endif

#if CONFIG_KMVC_DECODER 



	REGISTER_DECODER(KMVC,              kmvc);
#endif

#if CONFIG_LAGARITH_DECODER 



	REGISTER_DECODER(LAGARITH,          lagarith);
#endif

#if CONFIG_LJPEG_ENCODER 



	REGISTER_ENCODER(LJPEG,             ljpeg);
#endif

#if CONFIG_LOCO_DECODER 



	REGISTER_DECODER(LOCO,              loco);
#endif

#if CONFIG_MDEC_DECODER 

	REGISTER_DECODER(MDEC,              mdec);
#endif

#if CONFIG_MIMIC_DECODER 

	REGISTER_DECODER(MIMIC,             mimic);
#endif

#if CONFIG_MJPEG_ENCODER 
#if CONFIG_MJPEG_DECODER 

	REGISTER_ENCDEC (MJPEG,             mjpeg);
#endif
#endif

#if CONFIG_MJPEGB_DECODER 

	REGISTER_DECODER(MJPEGB,            mjpegb);
#endif

#if CONFIG_MMVIDEO_DECODER 

	REGISTER_DECODER(MMVIDEO,           mmvideo);
#endif

#if CONFIG_MOTIONPIXELS_DECODER 

	REGISTER_DECODER(MOTIONPIXELS,      motionpixels);
#endif

#if CONFIG_MPEG_XVMC_DECODER 

	REGISTER_DECODER(MPEG_XVMC,         mpeg_xvmc);
#endif

#if CONFIG_MPEG1VIDEO_ENCODER 
#if CONFIG_MPEG1VIDEO_DECODER 

	REGISTER_ENCDEC (MPEG1VIDEO,        mpeg1video);
#endif
#endif

#if CONFIG_MPEG2VIDEO_ENCODER 
#if CONFIG_MPEG2VIDEO_DECODER 

	REGISTER_ENCDEC (MPEG2VIDEO,        mpeg2video);
#endif
#endif

#if CONFIG_MPEG4_ENCODER 
#if CONFIG_MPEG4_DECODER 

	REGISTER_ENCDEC (MPEG4,             mpeg4);
#endif
#endif

#if CONFIG_MPEG4_CRYSTALHD_DECODER 

	REGISTER_DECODER(MPEG4_CRYSTALHD,   mpeg4_crystalhd);
#endif

#if CONFIG_MPEG4_VDPAU_DECODER 

	REGISTER_DECODER(MPEG4_VDPAU,       mpeg4_vdpau);
#endif

#if CONFIG_MPEGVIDEO_DECODER 

	REGISTER_DECODER(MPEGVIDEO,         mpegvideo);
#endif

#if CONFIG_MPEG_VDPAU_DECODER 

	REGISTER_DECODER(MPEG_VDPAU,        mpeg_vdpau);
#endif

#if CONFIG_MPEG1_VDPAU_DECODER 

	REGISTER_DECODER(MPEG1_VDPAU,       mpeg1_vdpau);
#endif

#if CONFIG_MPEG2_CRYSTALHD_DECODER 

	REGISTER_DECODER(MPEG2_CRYSTALHD,   mpeg2_crystalhd);
#endif

#if CONFIG_MSA1_DECODER 

	REGISTER_DECODER(MSA1,              msa1);
#endif

#if CONFIG_MSMPEG4_CRYSTALHD_DECODER 

	REGISTER_DECODER(MSMPEG4_CRYSTALHD, msmpeg4_crystalhd);
#endif

#if CONFIG_MSMPEG4V1_DECODER 

	REGISTER_DECODER(MSMPEG4V1,         msmpeg4v1);
#endif

#if CONFIG_MSMPEG4V2_ENCODER 
#if CONFIG_MSMPEG4V2_DECODER 

	REGISTER_ENCDEC (MSMPEG4V2,         msmpeg4v2);
#endif
#endif

#if CONFIG_MSMPEG4V3_ENCODER 
#if CONFIG_MSMPEG4V3_DECODER 

	REGISTER_ENCDEC (MSMPEG4V3,         msmpeg4v3);
#endif
#endif

#if CONFIG_MSRLE_DECODER 

	REGISTER_DECODER(MSRLE,             msrle);
#endif

#if CONFIG_MSS1_DECODER 

	REGISTER_DECODER(MSS1,              mss1);
#endif

#if CONFIG_MSS2_DECODER 

	REGISTER_DECODER(MSS2,              mss2);
#endif

#if CONFIG_MSVIDEO1_ENCODER 
#if CONFIG_MSVIDEO1_DECODER 

	REGISTER_ENCDEC (MSVIDEO1,          msvideo1);
#endif
#endif

#if CONFIG_MSZH_DECODER 

	REGISTER_DECODER(MSZH,              mszh);
#endif

#if CONFIG_MTS2_DECODER 

	REGISTER_DECODER(MTS2,              mts2);
#endif

#if CONFIG_MVC1_DECODER 

	REGISTER_DECODER(MVC1,              mvc1);
#endif

#if CONFIG_MVC2_DECODER 

	REGISTER_DECODER(MVC2,              mvc2);
#endif

#if CONFIG_MXPEG_DECODER 

	REGISTER_DECODER(MXPEG,             mxpeg);
#endif

#if CONFIG_NUV_DECODER 

	REGISTER_DECODER(NUV,               nuv);
#endif

#if CONFIG_PAF_VIDEO_DECODER 

	REGISTER_DECODER(PAF_VIDEO,         paf_video);
#endif

#if CONFIG_PAM_ENCODER 
#if CONFIG_PAM_DECODER 

	REGISTER_ENCDEC (PAM,               pam);
#endif
#endif

#if CONFIG_PBM_ENCODER 
#if CONFIG_PBM_DECODER 

	REGISTER_ENCDEC (PBM,               pbm);
#endif
#endif

#if CONFIG_PCX_ENCODER 
#if CONFIG_PCX_DECODER 

	REGISTER_ENCDEC (PCX,               pcx);
#endif
#endif

#if CONFIG_PGM_ENCODER 
#if CONFIG_PGM_DECODER 

	REGISTER_ENCDEC (PGM,               pgm);
#endif
#endif

#if CONFIG_PGMYUV_ENCODER 
#if CONFIG_PGMYUV_DECODER 

	REGISTER_ENCDEC (PGMYUV,            pgmyuv);
#endif
#endif

#if CONFIG_PICTOR_DECODER 

	REGISTER_DECODER(PICTOR,            pictor);
#endif

#if CONFIG_PNG_ENCODER 
#if CONFIG_PNG_DECODER 

	REGISTER_ENCDEC (PNG,               png);
#endif
#endif

#if CONFIG_PPM_ENCODER 
#if CONFIG_PPM_DECODER 

	REGISTER_ENCDEC (PPM,               ppm);
#endif
#endif

#if CONFIG_PRORES_ENCODER 
#if CONFIG_PRORES_DECODER 

	REGISTER_ENCDEC (PRORES,            prores);
#endif
#endif

#if CONFIG_PRORES_AW_ENCODER 

	REGISTER_ENCODER(PRORES_AW,         prores_aw);
#endif

#if CONFIG_PRORES_KS_ENCODER 

	REGISTER_ENCODER(PRORES_KS,         prores_ks);
#endif

#if CONFIG_PRORES_LGPL_DECODER 

	REGISTER_DECODER(PRORES_LGPL,       prores_lgpl);
#endif

#if CONFIG_PTX_DECODER 

	REGISTER_DECODER(PTX,               ptx);
#endif

#if CONFIG_QDRAW_DECODER 

	REGISTER_DECODER(QDRAW,             qdraw);
#endif

#if CONFIG_QPEG_DECODER 

	REGISTER_DECODER(QPEG,              qpeg);
#endif

#if CONFIG_QTRLE_ENCODER 
#if CONFIG_QTRLE_DECODER 

	REGISTER_ENCDEC (QTRLE,             qtrle);
#endif
#endif

#if CONFIG_R10K_ENCODER 
#if CONFIG_R10K_DECODER 

	REGISTER_ENCDEC (R10K,              r10k);
#endif
#endif

#if CONFIG_R210_ENCODER 
#if CONFIG_R210_DECODER 

	REGISTER_ENCDEC (R210,              r210);
#endif
#endif

#if CONFIG_RAWVIDEO_ENCODER 
#if CONFIG_RAWVIDEO_DECODER 

	REGISTER_ENCDEC (RAWVIDEO,          rawvideo);
#endif
#endif

#if CONFIG_RL2_DECODER 

	REGISTER_DECODER(RL2,               rl2);
#endif

#if CONFIG_ROQ_ENCODER 
#if CONFIG_ROQ_DECODER 

	REGISTER_ENCDEC (ROQ,               roq);
#endif
#endif

#if CONFIG_RPZA_DECODER 

	REGISTER_DECODER(RPZA,              rpza);
#endif

#if CONFIG_RV10_ENCODER 
#if CONFIG_RV10_DECODER 

	REGISTER_ENCDEC (RV10,              rv10);
#endif
#endif

#if CONFIG_RV20_ENCODER 
#if CONFIG_RV20_DECODER 

	REGISTER_ENCDEC (RV20,              rv20);
#endif
#endif

#if CONFIG_RV30_DECODER 

	REGISTER_DECODER(RV30,              rv30);
#endif

#if CONFIG_RV40_DECODER 

	REGISTER_DECODER(RV40,              rv40);
#endif

#if CONFIG_S302M_ENCODER 
#if CONFIG_S302M_DECODER 

	REGISTER_ENCDEC (S302M,             s302m);
#endif
#endif

#if CONFIG_SANM_DECODER 

	REGISTER_DECODER(SANM,              sanm);
#endif

#if CONFIG_SGI_ENCODER 
#if CONFIG_SGI_DECODER 

	REGISTER_ENCDEC (SGI,               sgi);
#endif
#endif

#if CONFIG_SGIRLE_DECODER 

	REGISTER_DECODER(SGIRLE,            sgirle);
#endif

#if CONFIG_SMACKER_DECODER 

	REGISTER_DECODER(SMACKER,           smacker);
#endif

#if CONFIG_SMC_DECODER 

	REGISTER_DECODER(SMC,               smc);
#endif

#if CONFIG_SMVJPEG_DECODER 

	REGISTER_DECODER(SMVJPEG,           smvjpeg);
#endif

#if CONFIG_SNOW_ENCODER 
#if CONFIG_SNOW_DECODER 

	REGISTER_ENCDEC (SNOW,              snow);
#endif
#endif

#if CONFIG_SP5X_DECODER 

	REGISTER_DECODER(SP5X,              sp5x);
#endif

#if CONFIG_SUNRAST_ENCODER 
#if CONFIG_SUNRAST_DECODER 

	REGISTER_ENCDEC (SUNRAST,           sunrast);
#endif
#endif

#if CONFIG_SVQ1_ENCODER 
#if CONFIG_SVQ1_DECODER 

	REGISTER_ENCDEC (SVQ1,              svq1);
#endif
#endif

#if CONFIG_SVQ3_DECODER 

	REGISTER_DECODER(SVQ3,              svq3);
#endif

#if CONFIG_TARGA_ENCODER 
#if CONFIG_TARGA_DECODER 

	REGISTER_ENCDEC (TARGA,             targa);
#endif
#endif

#if CONFIG_TARGA_Y216_DECODER 

	REGISTER_DECODER(TARGA_Y216,        targa_y216);
#endif

#if CONFIG_THEORA_DECODER 

	REGISTER_DECODER(THEORA,            theora);
#endif

#if CONFIG_THP_DECODER 

	REGISTER_DECODER(THP,               thp);
#endif

#if CONFIG_TIERTEXSEQVIDEO_DECODER 

	REGISTER_DECODER(TIERTEXSEQVIDEO,   tiertexseqvideo);
#endif

#if CONFIG_TIFF_ENCODER 
#if CONFIG_TIFF_DECODER 

	REGISTER_ENCDEC (TIFF,              tiff);
#endif
#endif

#if CONFIG_TMV_DECODER 

	REGISTER_DECODER(TMV,               tmv);
#endif

#if CONFIG_TRUEMOTION1_DECODER 

	REGISTER_DECODER(TRUEMOTION1,       truemotion1);
#endif

#if CONFIG_TRUEMOTION2_DECODER 

	REGISTER_DECODER(TRUEMOTION2,       truemotion2);
#endif

#if CONFIG_TSCC_DECODER 

	REGISTER_DECODER(TSCC,              tscc);
#endif

#if CONFIG_TSCC2_DECODER 

	REGISTER_DECODER(TSCC2,             tscc2);
#endif

#if CONFIG_TXD_DECODER 

	REGISTER_DECODER(TXD,               txd);
#endif

#if CONFIG_ULTI_DECODER 

	REGISTER_DECODER(ULTI,              ulti);
#endif

#if CONFIG_UTVIDEO_ENCODER 
#if CONFIG_UTVIDEO_DECODER 

	REGISTER_ENCDEC (UTVIDEO,           utvideo);
#endif
#endif

#if CONFIG_V210_ENCODER 
#if CONFIG_V210_DECODER 

	REGISTER_ENCDEC (V210,              v210);
#endif
#endif

#if CONFIG_V210X_DECODER 

	REGISTER_DECODER(V210X,             v210x);
#endif

#if CONFIG_V308_ENCODER 
#if CONFIG_V308_DECODER 

	REGISTER_ENCDEC (V308,              v308);
#endif
#endif

#if CONFIG_V408_ENCODER 
#if CONFIG_V408_DECODER 

	REGISTER_ENCDEC (V408,              v408);
#endif
#endif

#if CONFIG_V410_ENCODER 
#if CONFIG_V410_DECODER 

	REGISTER_ENCDEC (V410,              v410);
#endif
#endif

#if CONFIG_VB_DECODER 

	REGISTER_DECODER(VB,                vb);
#endif

#if CONFIG_VBLE_DECODER 

	REGISTER_DECODER(VBLE,              vble);
#endif

#if CONFIG_VC1_DECODER 

	REGISTER_DECODER(VC1,               vc1);
#endif

#if CONFIG_VC1_CRYSTALHD_DECODER 

	REGISTER_DECODER(VC1_CRYSTALHD,     vc1_crystalhd);
#endif

#if CONFIG_VC1_VDPAU_DECODER 

	REGISTER_DECODER(VC1_VDPAU,         vc1_vdpau);
#endif

#if CONFIG_VC1IMAGE_DECODER 

	REGISTER_DECODER(VC1IMAGE,          vc1image);
#endif

#if CONFIG_VCR1_DECODER 

	REGISTER_DECODER(VCR1,              vcr1);
#endif

#if CONFIG_VMDVIDEO_DECODER 

	REGISTER_DECODER(VMDVIDEO,          vmdvideo);
#endif

#if CONFIG_VMNC_DECODER 

	REGISTER_DECODER(VMNC,              vmnc);
#endif

#if CONFIG_VP3_DECODER 

	REGISTER_DECODER(VP3,               vp3);
#endif

#if CONFIG_VP5_DECODER 

	REGISTER_DECODER(VP5,               vp5);
#endif

#if CONFIG_VP6_DECODER 

	REGISTER_DECODER(VP6,               vp6);
#endif

#if CONFIG_VP6A_DECODER 

	REGISTER_DECODER(VP6A,              vp6a);
#endif

#if CONFIG_VP6F_DECODER 

	REGISTER_DECODER(VP6F,              vp6f);
#endif

#if CONFIG_VP8_DECODER 

	REGISTER_DECODER(VP8,               vp8);
#endif

#if CONFIG_VQA_DECODER 

	REGISTER_DECODER(VQA,               vqa);
#endif

#if CONFIG_WEBP_DECODER 

	REGISTER_DECODER(WEBP,              webp);
#endif

#if CONFIG_WMV1_ENCODER 
#if CONFIG_WMV1_DECODER 

	REGISTER_ENCDEC (WMV1,              wmv1);
#endif
#endif

#if CONFIG_WMV2_ENCODER 
#if CONFIG_WMV2_DECODER 

	REGISTER_ENCDEC (WMV2,              wmv2);
#endif
#endif

#if CONFIG_WMV3_DECODER 

	REGISTER_DECODER(WMV3,              wmv3);
#endif

#if CONFIG_WMV3_CRYSTALHD_DECODER 

	REGISTER_DECODER(WMV3_CRYSTALHD,    wmv3_crystalhd);
#endif

#if CONFIG_WMV3_VDPAU_DECODER 

	REGISTER_DECODER(WMV3_VDPAU,        wmv3_vdpau);
#endif

#if CONFIG_WMV3IMAGE_DECODER 

	REGISTER_DECODER(WMV3IMAGE,         wmv3image);
#endif

#if CONFIG_WNV1_DECODER 

	REGISTER_DECODER(WNV1,              wnv1);
#endif

#if CONFIG_XAN_WC3_DECODER 

	REGISTER_DECODER(XAN_WC3,           xan_wc3);
#endif

#if CONFIG_XAN_WC4_DECODER 

	REGISTER_DECODER(XAN_WC4,           xan_wc4);
#endif

#if CONFIG_XBM_ENCODER 
#if CONFIG_XBM_DECODER 

	REGISTER_ENCDEC (XBM,               xbm);
#endif
#endif

#if CONFIG_XFACE_ENCODER 
#if CONFIG_XFACE_DECODER 

	REGISTER_ENCDEC (XFACE,             xface);
#endif
#endif

#if CONFIG_XL_DECODER 

	REGISTER_DECODER(XL,                xl);
#endif

#if CONFIG_XWD_ENCODER 
#if CONFIG_XWD_DECODER 

	REGISTER_ENCDEC (XWD,               xwd);
#endif
#endif

#if CONFIG_Y41P_ENCODER 
#if CONFIG_Y41P_DECODER 

	REGISTER_ENCDEC (Y41P,              y41p);
#endif
#endif

#if CONFIG_YOP_DECODER 

	REGISTER_DECODER(YOP,               yop);
#endif

#if CONFIG_YUV4_ENCODER 
#if CONFIG_YUV4_DECODER 

	REGISTER_ENCDEC (YUV4,              yuv4);
#endif
#endif

#if CONFIG_ZERO12V_DECODER 

	REGISTER_DECODER(ZERO12V,           zero12v);
#endif

#if CONFIG_ZEROCODEC_DECODER 

	REGISTER_DECODER(ZEROCODEC,         zerocodec);
#endif

#if CONFIG_ZLIB_ENCODER 
#if CONFIG_ZLIB_DECODER 

	REGISTER_ENCDEC (ZLIB,              zlib);
#endif
#endif

#if CONFIG_ZMBV_ENCODER 
#if CONFIG_ZMBV_DECODER 

	REGISTER_ENCDEC (ZMBV,              zmbv);
#endif
#endif

#if CONFIG_AAC_ENCODER 
#if CONFIG_AAC_DECODER 


	/* audio codecs */
	REGISTER_ENCDEC (AAC,               aac);
#endif
#endif

#if CONFIG_AAC_LATM_DECODER 

	REGISTER_DECODER(AAC_LATM,          aac_latm);
#endif

#if CONFIG_AC3_ENCODER 
#if CONFIG_AC3_DECODER 

	REGISTER_ENCDEC (AC3,               ac3);
#endif
#endif

#if CONFIG_AC3_FIXED_ENCODER 

	REGISTER_ENCODER(AC3_FIXED,         ac3_fixed);
#endif

#if CONFIG_ALAC_ENCODER 
#if CONFIG_ALAC_DECODER 

	REGISTER_ENCDEC (ALAC,              alac);
#endif
#endif

#if CONFIG_ALS_DECODER 

	REGISTER_DECODER(ALS,               als);
#endif

#if CONFIG_AMRNB_DECODER 

	REGISTER_DECODER(AMRNB,             amrnb);
#endif

#if CONFIG_AMRWB_DECODER 

	REGISTER_DECODER(AMRWB,             amrwb);
#endif

#if CONFIG_APE_DECODER 

	REGISTER_DECODER(APE,               ape);
#endif

#if CONFIG_ATRAC1_DECODER 

	REGISTER_DECODER(ATRAC1,            atrac1);
#endif

#if CONFIG_ATRAC3_DECODER 

	REGISTER_DECODER(ATRAC3,            atrac3);
#endif

#if CONFIG_BINKAUDIO_DCT_DECODER 

	REGISTER_DECODER(BINKAUDIO_DCT,     binkaudio_dct);
#endif

#if CONFIG_BINKAUDIO_RDFT_DECODER 

	REGISTER_DECODER(BINKAUDIO_RDFT,    binkaudio_rdft);
#endif

#if CONFIG_BMV_AUDIO_DECODER 

	REGISTER_DECODER(BMV_AUDIO,         bmv_audio);
#endif

#if CONFIG_COOK_DECODER 

	REGISTER_DECODER(COOK,              cook);
#endif

#if CONFIG_DCA_ENCODER 
#if CONFIG_DCA_DECODER 

	REGISTER_ENCDEC (DCA,               dca);
#endif
#endif

#if CONFIG_DSICINAUDIO_DECODER 

	REGISTER_DECODER(DSICINAUDIO,       dsicinaudio);
#endif

#if CONFIG_EAC3_ENCODER 
#if CONFIG_EAC3_DECODER 

	REGISTER_ENCDEC (EAC3,              eac3);
#endif
#endif

#if CONFIG_EVRC_DECODER 

	REGISTER_DECODER(EVRC,              evrc);
#endif

#if CONFIG_FFWAVESYNTH_DECODER 

	REGISTER_DECODER(FFWAVESYNTH,       ffwavesynth);
#endif

#if CONFIG_FLAC_ENCODER 
#if CONFIG_FLAC_DECODER 

	REGISTER_ENCDEC (FLAC,              flac);
#endif
#endif

#if CONFIG_G723_1_ENCODER 
#if CONFIG_G723_1_DECODER 

	REGISTER_ENCDEC (G723_1,            g723_1);
#endif
#endif

#if CONFIG_G729_DECODER 

	REGISTER_DECODER(G729,              g729);
#endif

#if CONFIG_GSM_DECODER 

	REGISTER_DECODER(GSM,               gsm);
#endif

#if CONFIG_GSM_MS_DECODER 

	REGISTER_DECODER(GSM_MS,            gsm_ms);
#endif

#if CONFIG_IAC_DECODER 

	REGISTER_DECODER(IAC,               iac);
#endif

#if CONFIG_IMC_DECODER 

	REGISTER_DECODER(IMC,               imc);
#endif

#if CONFIG_MACE3_DECODER 

	REGISTER_DECODER(MACE3,             mace3);
#endif

#if CONFIG_MACE6_DECODER 

	REGISTER_DECODER(MACE6,             mace6);
#endif

#if CONFIG_MLP_DECODER 

	REGISTER_DECODER(MLP,               mlp);
#endif

#if CONFIG_MP1_DECODER 

	REGISTER_DECODER(MP1,               mp1);
#endif

#if CONFIG_MP1FLOAT_DECODER 

	REGISTER_DECODER(MP1FLOAT,          mp1float);
#endif

#if CONFIG_MP2_ENCODER 
#if CONFIG_MP2_DECODER 

	REGISTER_ENCDEC (MP2,               mp2);
#endif
#endif

#if CONFIG_MP2FLOAT_DECODER 

	REGISTER_DECODER(MP2FLOAT,          mp2float);
#endif

#if CONFIG_MP3_DECODER 

	REGISTER_DECODER(MP3,               mp3);
#endif

#if CONFIG_MP3FLOAT_DECODER 

	REGISTER_DECODER(MP3FLOAT,          mp3float);
#endif

#if CONFIG_MP3ADU_DECODER 

	REGISTER_DECODER(MP3ADU,            mp3adu);
#endif

#if CONFIG_MP3ADUFLOAT_DECODER 

	REGISTER_DECODER(MP3ADUFLOAT,       mp3adufloat);
#endif

#if CONFIG_MP3ON4_DECODER 

	REGISTER_DECODER(MP3ON4,            mp3on4);
#endif

#if CONFIG_MP3ON4FLOAT_DECODER 

	REGISTER_DECODER(MP3ON4FLOAT,       mp3on4float);
#endif

#if CONFIG_MPC7_DECODER 

	REGISTER_DECODER(MPC7,              mpc7);
#endif

#if CONFIG_MPC8_DECODER 

	REGISTER_DECODER(MPC8,              mpc8);
#endif

#if CONFIG_NELLYMOSER_ENCODER 
#if CONFIG_NELLYMOSER_DECODER 

	REGISTER_ENCDEC (NELLYMOSER,        nellymoser);
#endif
#endif

#if CONFIG_PAF_AUDIO_DECODER 

	REGISTER_DECODER(PAF_AUDIO,         paf_audio);
#endif

#if CONFIG_QCELP_DECODER 

	REGISTER_DECODER(QCELP,             qcelp);
#endif

#if CONFIG_QDM2_DECODER 

	REGISTER_DECODER(QDM2,              qdm2);
#endif

#if CONFIG_RA_144_ENCODER 
#if CONFIG_RA_144_DECODER 

	REGISTER_ENCDEC (RA_144,            ra_144);
#endif
#endif

#if CONFIG_RA_288_DECODER 

	REGISTER_DECODER(RA_288,            ra_288);
#endif

#if CONFIG_RALF_DECODER 

	REGISTER_DECODER(RALF,              ralf);
#endif

#if CONFIG_SHORTEN_DECODER 

	REGISTER_DECODER(SHORTEN,           shorten);
#endif

#if CONFIG_SIPR_DECODER 

	REGISTER_DECODER(SIPR,              sipr);
#endif

#if CONFIG_SMACKAUD_DECODER 

	REGISTER_DECODER(SMACKAUD,          smackaud);
#endif

#if CONFIG_SONIC_ENCODER 
#if CONFIG_SONIC_DECODER 

	REGISTER_ENCDEC (SONIC,             sonic);
#endif
#endif

#if CONFIG_SONIC_LS_ENCODER 

	REGISTER_ENCODER(SONIC_LS,          sonic_ls);
#endif

#if CONFIG_TAK_DECODER 

	REGISTER_DECODER(TAK,               tak);
#endif

#if CONFIG_TRUEHD_DECODER 

	REGISTER_DECODER(TRUEHD,            truehd);
#endif

#if CONFIG_TRUESPEECH_DECODER 

	REGISTER_DECODER(TRUESPEECH,        truespeech);
#endif

#if CONFIG_TTA_ENCODER 
#if CONFIG_TTA_DECODER 

	REGISTER_ENCDEC (TTA,               tta);
#endif
#endif

#if CONFIG_TWINVQ_DECODER 

	REGISTER_DECODER(TWINVQ,            twinvq);
#endif

#if CONFIG_VMDAUDIO_DECODER 

	REGISTER_DECODER(VMDAUDIO,          vmdaudio);
#endif

#if CONFIG_VORBIS_ENCODER 
#if CONFIG_VORBIS_DECODER 

	REGISTER_ENCDEC (VORBIS,            vorbis);
#endif
#endif

#if CONFIG_WAVPACK_DECODER 

	REGISTER_DECODER(WAVPACK,           wavpack);
#endif

#if CONFIG_WMALOSSLESS_DECODER 

	REGISTER_DECODER(WMALOSSLESS,       wmalossless);
#endif

#if CONFIG_WMAPRO_DECODER 

	REGISTER_DECODER(WMAPRO,            wmapro);
#endif

#if CONFIG_WMAV1_ENCODER 
#if CONFIG_WMAV1_DECODER 

	REGISTER_ENCDEC (WMAV1,             wmav1);
#endif
#endif

#if CONFIG_WMAV2_ENCODER 
#if CONFIG_WMAV2_DECODER 

	REGISTER_ENCDEC (WMAV2,             wmav2);
#endif
#endif

#if CONFIG_WMAVOICE_DECODER 

	REGISTER_DECODER(WMAVOICE,          wmavoice);
#endif

#if CONFIG_WS_SND1_DECODER 

	REGISTER_DECODER(WS_SND1,           ws_snd1);
#endif

#if CONFIG_PCM_ALAW_ENCODER 
#if CONFIG_PCM_ALAW_DECODER 


	/* PCM codecs */
	REGISTER_ENCDEC (PCM_ALAW,          pcm_alaw);
#endif
#endif

#if CONFIG_PCM_BLURAY_DECODER 

	REGISTER_DECODER(PCM_BLURAY,        pcm_bluray);
#endif

#if CONFIG_PCM_DVD_DECODER 

	REGISTER_DECODER(PCM_DVD,           pcm_dvd);
#endif

#if CONFIG_PCM_F32BE_ENCODER 
#if CONFIG_PCM_F32BE_DECODER 

	REGISTER_ENCDEC (PCM_F32BE,         pcm_f32be);
#endif
#endif

#if CONFIG_PCM_F32LE_ENCODER 
#if CONFIG_PCM_F32LE_DECODER 

	REGISTER_ENCDEC (PCM_F32LE,         pcm_f32le);
#endif
#endif

#if CONFIG_PCM_F64BE_ENCODER 
#if CONFIG_PCM_F64BE_DECODER 

	REGISTER_ENCDEC (PCM_F64BE,         pcm_f64be);
#endif
#endif

#if CONFIG_PCM_F64LE_ENCODER 
#if CONFIG_PCM_F64LE_DECODER 

	REGISTER_ENCDEC (PCM_F64LE,         pcm_f64le);
#endif
#endif

#if CONFIG_PCM_LXF_DECODER 

	REGISTER_DECODER(PCM_LXF,           pcm_lxf);
#endif

#if CONFIG_PCM_MULAW_ENCODER 
#if CONFIG_PCM_MULAW_DECODER 

	REGISTER_ENCDEC (PCM_MULAW,         pcm_mulaw);
#endif
#endif

#if CONFIG_PCM_S8_ENCODER 
#if CONFIG_PCM_S8_DECODER 

	REGISTER_ENCDEC (PCM_S8,            pcm_s8);
#endif
#endif

#if CONFIG_PCM_S8_PLANAR_ENCODER 
#if CONFIG_PCM_S8_PLANAR_DECODER 

	REGISTER_ENCDEC (PCM_S8_PLANAR,     pcm_s8_planar);
#endif
#endif

#if CONFIG_PCM_S16BE_ENCODER 
#if CONFIG_PCM_S16BE_DECODER 

	REGISTER_ENCDEC (PCM_S16BE,         pcm_s16be);
#endif
#endif

#if CONFIG_PCM_S16BE_PLANAR_ENCODER 
#if CONFIG_PCM_S16BE_PLANAR_DECODER 

	REGISTER_ENCDEC (PCM_S16BE_PLANAR,  pcm_s16be_planar);
#endif
#endif

#if CONFIG_PCM_S16LE_ENCODER 
#if CONFIG_PCM_S16LE_DECODER 

	REGISTER_ENCDEC (PCM_S16LE,         pcm_s16le);
#endif
#endif

#if CONFIG_PCM_S16LE_PLANAR_ENCODER 
#if CONFIG_PCM_S16LE_PLANAR_DECODER 

	REGISTER_ENCDEC (PCM_S16LE_PLANAR,  pcm_s16le_planar);
#endif
#endif

#if CONFIG_PCM_S24BE_ENCODER 
#if CONFIG_PCM_S24BE_DECODER 

	REGISTER_ENCDEC (PCM_S24BE,         pcm_s24be);
#endif
#endif

#if CONFIG_PCM_S24DAUD_ENCODER 
#if CONFIG_PCM_S24DAUD_DECODER 

	REGISTER_ENCDEC (PCM_S24DAUD,       pcm_s24daud);
#endif
#endif

#if CONFIG_PCM_S24LE_ENCODER 
#if CONFIG_PCM_S24LE_DECODER 

	REGISTER_ENCDEC (PCM_S24LE,         pcm_s24le);
#endif
#endif

#if CONFIG_PCM_S24LE_PLANAR_ENCODER 
#if CONFIG_PCM_S24LE_PLANAR_DECODER 

	REGISTER_ENCDEC (PCM_S24LE_PLANAR,  pcm_s24le_planar);
#endif
#endif

#if CONFIG_PCM_S32BE_ENCODER 
#if CONFIG_PCM_S32BE_DECODER 

	REGISTER_ENCDEC (PCM_S32BE,         pcm_s32be);
#endif
#endif

#if CONFIG_PCM_S32LE_ENCODER 
#if CONFIG_PCM_S32LE_DECODER 

	REGISTER_ENCDEC (PCM_S32LE,         pcm_s32le);
#endif
#endif

#if CONFIG_PCM_S32LE_PLANAR_ENCODER 
#if CONFIG_PCM_S32LE_PLANAR_DECODER 

	REGISTER_ENCDEC (PCM_S32LE_PLANAR,  pcm_s32le_planar);
#endif
#endif

#if CONFIG_PCM_U8_ENCODER 
#if CONFIG_PCM_U8_DECODER 

	REGISTER_ENCDEC (PCM_U8,            pcm_u8);
#endif
#endif

#if CONFIG_PCM_U16BE_ENCODER 
#if CONFIG_PCM_U16BE_DECODER 

	REGISTER_ENCDEC (PCM_U16BE,         pcm_u16be);
#endif
#endif

#if CONFIG_PCM_U16LE_ENCODER 
#if CONFIG_PCM_U16LE_DECODER 

	REGISTER_ENCDEC (PCM_U16LE,         pcm_u16le);
#endif
#endif

#if CONFIG_PCM_U24BE_ENCODER 
#if CONFIG_PCM_U24BE_DECODER 

	REGISTER_ENCDEC (PCM_U24BE,         pcm_u24be);
#endif
#endif

#if CONFIG_PCM_U24LE_ENCODER 
#if CONFIG_PCM_U24LE_DECODER 

	REGISTER_ENCDEC (PCM_U24LE,         pcm_u24le);
#endif
#endif

#if CONFIG_PCM_U32BE_ENCODER 
#if CONFIG_PCM_U32BE_DECODER 

	REGISTER_ENCDEC (PCM_U32BE,         pcm_u32be);
#endif
#endif

#if CONFIG_PCM_U32LE_ENCODER 
#if CONFIG_PCM_U32LE_DECODER 

	REGISTER_ENCDEC (PCM_U32LE,         pcm_u32le);
#endif
#endif

#if CONFIG_PCM_ZORK_DECODER 

	REGISTER_DECODER(PCM_ZORK,          pcm_zork);
#endif

#if CONFIG_INTERPLAY_DPCM_DECODER 


	/* DPCM codecs */
	REGISTER_DECODER(INTERPLAY_DPCM,    interplay_dpcm);
#endif

#if CONFIG_ROQ_DPCM_ENCODER 
#if CONFIG_ROQ_DPCM_DECODER 

	REGISTER_ENCDEC (ROQ_DPCM,          roq_dpcm);
#endif
#endif

#if CONFIG_SOL_DPCM_DECODER 

	REGISTER_DECODER(SOL_DPCM,          sol_dpcm);
#endif

#if CONFIG_XAN_DPCM_DECODER 

	REGISTER_DECODER(XAN_DPCM,          xan_dpcm);
#endif

#if CONFIG_ADPCM_4XM_DECODER 


	/* ADPCM codecs */
	REGISTER_DECODER(ADPCM_4XM,         adpcm_4xm);
#endif

#if CONFIG_ADPCM_ADX_ENCODER 
#if CONFIG_ADPCM_ADX_DECODER 

	REGISTER_ENCDEC (ADPCM_ADX,         adpcm_adx);
#endif
#endif

#if CONFIG_ADPCM_AFC_DECODER 

	REGISTER_DECODER(ADPCM_AFC,         adpcm_afc);
#endif

#if CONFIG_ADPCM_CT_DECODER 

	REGISTER_DECODER(ADPCM_CT,          adpcm_ct);
#endif

#if CONFIG_ADPCM_DTK_DECODER 

	REGISTER_DECODER(ADPCM_DTK,         adpcm_dtk);
#endif

#if CONFIG_ADPCM_EA_DECODER 

	REGISTER_DECODER(ADPCM_EA,          adpcm_ea);
#endif

#if CONFIG_ADPCM_EA_MAXIS_XA_DECODER 

	REGISTER_DECODER(ADPCM_EA_MAXIS_XA, adpcm_ea_maxis_xa);
#endif

#if CONFIG_ADPCM_EA_R1_DECODER 

	REGISTER_DECODER(ADPCM_EA_R1,       adpcm_ea_r1);
#endif

#if CONFIG_ADPCM_EA_R2_DECODER 

	REGISTER_DECODER(ADPCM_EA_R2,       adpcm_ea_r2);
#endif

#if CONFIG_ADPCM_EA_R3_DECODER 

	REGISTER_DECODER(ADPCM_EA_R3,       adpcm_ea_r3);
#endif

#if CONFIG_ADPCM_EA_XAS_DECODER 

	REGISTER_DECODER(ADPCM_EA_XAS,      adpcm_ea_xas);
#endif

#if CONFIG_ADPCM_G722_ENCODER 
#if CONFIG_ADPCM_G722_DECODER 

	REGISTER_ENCDEC (ADPCM_G722,        adpcm_g722);
#endif
#endif

#if CONFIG_ADPCM_G726_ENCODER 
#if CONFIG_ADPCM_G726_DECODER 

	REGISTER_ENCDEC (ADPCM_G726,        adpcm_g726);
#endif
#endif

#if CONFIG_ADPCM_IMA_AMV_DECODER 

	REGISTER_DECODER(ADPCM_IMA_AMV,     adpcm_ima_amv);
#endif

#if CONFIG_ADPCM_IMA_APC_DECODER 

	REGISTER_DECODER(ADPCM_IMA_APC,     adpcm_ima_apc);
#endif

#if CONFIG_ADPCM_IMA_DK3_DECODER 

	REGISTER_DECODER(ADPCM_IMA_DK3,     adpcm_ima_dk3);
#endif

#if CONFIG_ADPCM_IMA_DK4_DECODER 

	REGISTER_DECODER(ADPCM_IMA_DK4,     adpcm_ima_dk4);
#endif

#if CONFIG_ADPCM_IMA_EA_EACS_DECODER 

	REGISTER_DECODER(ADPCM_IMA_EA_EACS, adpcm_ima_ea_eacs);
#endif

#if CONFIG_ADPCM_IMA_EA_SEAD_DECODER 

	REGISTER_DECODER(ADPCM_IMA_EA_SEAD, adpcm_ima_ea_sead);
#endif

#if CONFIG_ADPCM_IMA_ISS_DECODER 

	REGISTER_DECODER(ADPCM_IMA_ISS,     adpcm_ima_iss);
#endif

#if CONFIG_ADPCM_IMA_OKI_DECODER 

	REGISTER_DECODER(ADPCM_IMA_OKI,     adpcm_ima_oki);
#endif

#if CONFIG_ADPCM_IMA_QT_ENCODER 
#if CONFIG_ADPCM_IMA_QT_DECODER 

	REGISTER_ENCDEC (ADPCM_IMA_QT,      adpcm_ima_qt);
#endif
#endif

#if CONFIG_ADPCM_IMA_RAD_DECODER 

	REGISTER_DECODER(ADPCM_IMA_RAD,     adpcm_ima_rad);
#endif

#if CONFIG_ADPCM_IMA_SMJPEG_DECODER 

	REGISTER_DECODER(ADPCM_IMA_SMJPEG,  adpcm_ima_smjpeg);
#endif

#if CONFIG_ADPCM_IMA_WAV_ENCODER 
#if CONFIG_ADPCM_IMA_WAV_DECODER 

	REGISTER_ENCDEC (ADPCM_IMA_WAV,     adpcm_ima_wav);
#endif
#endif

#if CONFIG_ADPCM_IMA_WS_DECODER 

	REGISTER_DECODER(ADPCM_IMA_WS,      adpcm_ima_ws);
#endif

#if CONFIG_ADPCM_MS_ENCODER 
#if CONFIG_ADPCM_MS_DECODER 

	REGISTER_ENCDEC (ADPCM_MS,          adpcm_ms);
#endif
#endif

#if CONFIG_ADPCM_SBPRO_2_DECODER 

	REGISTER_DECODER(ADPCM_SBPRO_2,     adpcm_sbpro_2);
#endif

#if CONFIG_ADPCM_SBPRO_3_DECODER 

	REGISTER_DECODER(ADPCM_SBPRO_3,     adpcm_sbpro_3);
#endif

#if CONFIG_ADPCM_SBPRO_4_DECODER 

	REGISTER_DECODER(ADPCM_SBPRO_4,     adpcm_sbpro_4);
#endif

#if CONFIG_ADPCM_SWF_ENCODER 
#if CONFIG_ADPCM_SWF_DECODER 

	REGISTER_ENCDEC (ADPCM_SWF,         adpcm_swf);
#endif
#endif

#if CONFIG_ADPCM_THP_DECODER 

	REGISTER_DECODER(ADPCM_THP,         adpcm_thp);
#endif

#if CONFIG_ADPCM_XA_DECODER 

	REGISTER_DECODER(ADPCM_XA,          adpcm_xa);
#endif

#if CONFIG_ADPCM_YAMAHA_ENCODER 
#if CONFIG_ADPCM_YAMAHA_DECODER 

	REGISTER_ENCDEC (ADPCM_YAMAHA,      adpcm_yamaha);
#endif
#endif

#if CONFIG_VIMA_DECODER 

	REGISTER_DECODER(VIMA,              vima);
#endif

#if CONFIG_SSA_ENCODER 
#if CONFIG_SSA_DECODER 


	/* subtitles */
	REGISTER_ENCDEC (SSA,               ssa);
#endif
#endif

#if CONFIG_ASS_ENCODER 
#if CONFIG_ASS_DECODER 

	REGISTER_ENCDEC (ASS,               ass);
#endif
#endif

#if CONFIG_DVBSUB_ENCODER 
#if CONFIG_DVBSUB_DECODER 

	REGISTER_ENCDEC (DVBSUB,            dvbsub);
#endif
#endif

#if CONFIG_DVDSUB_ENCODER 
#if CONFIG_DVDSUB_DECODER 

	REGISTER_ENCDEC (DVDSUB,            dvdsub);
#endif
#endif

#if CONFIG_JACOSUB_DECODER 

	REGISTER_DECODER(JACOSUB,           jacosub);
#endif

#if CONFIG_MICRODVD_DECODER 

	REGISTER_DECODER(MICRODVD,          microdvd);
#endif

#if CONFIG_MOVTEXT_ENCODER 
#if CONFIG_MOVTEXT_DECODER 

	REGISTER_ENCDEC (MOVTEXT,           movtext);
#endif
#endif

#if CONFIG_MPL2_DECODER 

	REGISTER_DECODER(MPL2,              mpl2);
#endif

#if CONFIG_PGSSUB_DECODER 

	REGISTER_DECODER(PGSSUB,            pgssub);
#endif

#if CONFIG_PJS_DECODER 

	REGISTER_DECODER(PJS,               pjs);
#endif

#if CONFIG_REALTEXT_DECODER 

	REGISTER_DECODER(REALTEXT,          realtext);
#endif

#if CONFIG_SAMI_DECODER 

	REGISTER_DECODER(SAMI,              sami);
#endif

#if CONFIG_SRT_ENCODER 
#if CONFIG_SRT_DECODER 

	REGISTER_ENCDEC (SRT,               srt);
#endif
#endif

#if CONFIG_SUBRIP_ENCODER 
#if CONFIG_SUBRIP_DECODER 

	REGISTER_ENCDEC (SUBRIP,            subrip);
#endif
#endif

#if CONFIG_SUBVIEWER_DECODER 

	REGISTER_DECODER(SUBVIEWER,         subviewer);
#endif

#if CONFIG_SUBVIEWER1_DECODER 

	REGISTER_DECODER(SUBVIEWER1,        subviewer1);
#endif

#if CONFIG_TEXT_DECODER 

	REGISTER_DECODER(TEXT,              text);
#endif

#if CONFIG_VPLAYER_DECODER 

	REGISTER_DECODER(VPLAYER,           vplayer);
#endif

#if CONFIG_WEBVTT_DECODER 

	REGISTER_DECODER(WEBVTT,            webvtt);
#endif

#if CONFIG_XSUB_ENCODER 
#if CONFIG_XSUB_DECODER 

	REGISTER_ENCDEC (XSUB,              xsub);
#endif
#endif

#if CONFIG_LIBCELT_DECODER 


	/* external libraries */
	REGISTER_DECODER(LIBCELT,           libcelt);
#endif

#if CONFIG_LIBFAAC_ENCODER 

	REGISTER_ENCODER(LIBFAAC,           libfaac);
#endif

#if CONFIG_LIBFDK_AAC_ENCODER 

	REGISTER_ENCODER(LIBFDK_AAC,        libfdk_aac);
#endif

#if CONFIG_LIBGSM_ENCODER 
#if CONFIG_LIBGSM_DECODER 

	REGISTER_ENCDEC (LIBGSM,            libgsm);
#endif
#endif

#if CONFIG_LIBGSM_MS_ENCODER 
#if CONFIG_LIBGSM_MS_DECODER 

	REGISTER_ENCDEC (LIBGSM_MS,         libgsm_ms);
#endif
#endif

#if CONFIG_LIBILBC_ENCODER 
#if CONFIG_LIBILBC_DECODER 

	REGISTER_ENCDEC (LIBILBC,           libilbc);
#endif
#endif

#if CONFIG_LIBMP3LAME_ENCODER 

	REGISTER_ENCODER(LIBMP3LAME,        libmp3lame);
#endif

#if CONFIG_LIBOPENCORE_AMRNB_ENCODER 
#if CONFIG_LIBOPENCORE_AMRNB_DECODER 

	REGISTER_ENCDEC (LIBOPENCORE_AMRNB, libopencore_amrnb);
#endif
#endif

#if CONFIG_LIBOPENCORE_AMRWB_DECODER 

	REGISTER_DECODER(LIBOPENCORE_AMRWB, libopencore_amrwb);
#endif

#if CONFIG_LIBOPENJPEG_ENCODER 
#if CONFIG_LIBOPENJPEG_DECODER 

	REGISTER_ENCDEC (LIBOPENJPEG,       libopenjpeg);
#endif
#endif

#if CONFIG_LIBOPUS_ENCODER 
#if CONFIG_LIBOPUS_DECODER 

	REGISTER_ENCDEC (LIBOPUS,           libopus);
#endif
#endif

#if CONFIG_LIBSCHROEDINGER_ENCODER 
#if CONFIG_LIBSCHROEDINGER_DECODER 

	REGISTER_ENCDEC (LIBSCHROEDINGER,   libschroedinger);
#endif
#endif

#if CONFIG_LIBSHINE_ENCODER 

	REGISTER_ENCODER(LIBSHINE,          libshine);
#endif

#if CONFIG_LIBSPEEX_ENCODER 
#if CONFIG_LIBSPEEX_DECODER 

	REGISTER_ENCDEC (LIBSPEEX,          libspeex);
#endif
#endif

#if CONFIG_LIBSTAGEFRIGHT_H264_DECODER 

	REGISTER_DECODER(LIBSTAGEFRIGHT_H264, libstagefright_h264);
#endif

#if CONFIG_LIBTHEORA_ENCODER 

	REGISTER_ENCODER(LIBTHEORA,         libtheora);
#endif

#if CONFIG_LIBTWOLAME_ENCODER 

	REGISTER_ENCODER(LIBTWOLAME,        libtwolame);
#endif

#if CONFIG_LIBUTVIDEO_ENCODER 
#if CONFIG_LIBUTVIDEO_DECODER 

	REGISTER_ENCDEC (LIBUTVIDEO,        libutvideo);
#endif
#endif

#if CONFIG_LIBVO_AACENC_ENCODER 

	REGISTER_ENCODER(LIBVO_AACENC,      libvo_aacenc);
#endif

#if CONFIG_LIBVO_AMRWBENC_ENCODER 

	REGISTER_ENCODER(LIBVO_AMRWBENC,    libvo_amrwbenc);
#endif

#if CONFIG_LIBVORBIS_ENCODER 
#if CONFIG_LIBVORBIS_DECODER 

	REGISTER_ENCDEC (LIBVORBIS,         libvorbis);
#endif
#endif

#if CONFIG_LIBVPX_VP8_ENCODER 
#if CONFIG_LIBVPX_VP8_DECODER 

	REGISTER_ENCDEC (LIBVPX_VP8,        libvpx_vp8);
#endif
#endif

#if CONFIG_LIBVPX_VP9_ENCODER 
#if CONFIG_LIBVPX_VP9_DECODER 

	REGISTER_ENCDEC (LIBVPX_VP9,        libvpx_vp9);
#endif
#endif

#if CONFIG_LIBWAVPACK_ENCODER 

	REGISTER_ENCODER(LIBWAVPACK,        libwavpack);
#endif

#if CONFIG_LIBX264_ENCODER 

	REGISTER_ENCODER(LIBX264,           libx264);
#endif

#if CONFIG_LIBX264RGB_ENCODER 

	REGISTER_ENCODER(LIBX264RGB,        libx264rgb);
#endif

#if CONFIG_LIBXAVS_ENCODER 

	REGISTER_ENCODER(LIBXAVS,           libxavs);
#endif

#if CONFIG_LIBXVID_ENCODER 

	REGISTER_ENCODER(LIBXVID,           libxvid);
#endif

#if CONFIG_LIBAACPLUS_ENCODER 

	REGISTER_ENCODER(LIBAACPLUS,        libaacplus);
#endif

#if CONFIG_BINTEXT_DECODER 


	/* text */
	REGISTER_DECODER(BINTEXT,           bintext);
#endif

#if CONFIG_XBIN_DECODER 

	REGISTER_DECODER(XBIN,              xbin);
#endif

#if CONFIG_IDF_DECODER 

	REGISTER_DECODER(IDF,               idf);
#endif

#if CONFIG_AAC_PARSER 


	/* parsers */
	REGISTER_PARSER(AAC,                aac);
#endif

#if CONFIG_AAC_LATM_PARSER 

	REGISTER_PARSER(AAC_LATM,           aac_latm);
#endif

#if CONFIG_AC3_PARSER 

	REGISTER_PARSER(AC3,                ac3);
#endif

#if CONFIG_ADX_PARSER 

	REGISTER_PARSER(ADX,                adx);
#endif

#if CONFIG_BMP_PARSER 

	REGISTER_PARSER(BMP,                bmp);
#endif

#if CONFIG_CAVSVIDEO_PARSER 

	REGISTER_PARSER(CAVSVIDEO,          cavsvideo);
#endif

#if CONFIG_COOK_PARSER 

	REGISTER_PARSER(COOK,               cook);
#endif

#if CONFIG_DCA_PARSER 

	REGISTER_PARSER(DCA,                dca);
#endif

#if CONFIG_DIRAC_PARSER 

	REGISTER_PARSER(DIRAC,              dirac);
#endif

#if CONFIG_DNXHD_PARSER 

	REGISTER_PARSER(DNXHD,              dnxhd);
#endif

#if CONFIG_DVBSUB_PARSER 

	REGISTER_PARSER(DVBSUB,             dvbsub);
#endif

#if CONFIG_DVDSUB_PARSER 

	REGISTER_PARSER(DVDSUB,             dvdsub);
#endif

#if CONFIG_DVD_NAV_PARSER 

	REGISTER_PARSER(DVD_NAV,            dvd_nav);
#endif

#if CONFIG_FLAC_PARSER 

	REGISTER_PARSER(FLAC,               flac);
#endif

#if CONFIG_GSM_PARSER 

	REGISTER_PARSER(GSM,                gsm);
#endif

#if CONFIG_H261_PARSER 

	REGISTER_PARSER(H261,               h261);
#endif

#if CONFIG_H263_PARSER 

	REGISTER_PARSER(H263,               h263);
#endif

#if CONFIG_H264_PARSER 

	REGISTER_PARSER(H264,               h264);
#endif

#if CONFIG_MJPEG_PARSER 

	REGISTER_PARSER(MJPEG,              mjpeg);
#endif

#if CONFIG_MLP_PARSER 

	REGISTER_PARSER(MLP,                mlp);
#endif

#if CONFIG_MPEG4VIDEO_PARSER 

	REGISTER_PARSER(MPEG4VIDEO,         mpeg4video);
#endif

#if CONFIG_MPEGAUDIO_PARSER 

	REGISTER_PARSER(MPEGAUDIO,          mpegaudio);
#endif

#if CONFIG_MPEGVIDEO_PARSER 

	REGISTER_PARSER(MPEGVIDEO,          mpegvideo);
#endif

#if CONFIG_PNG_PARSER 

	REGISTER_PARSER(PNG,                png);
#endif

#if CONFIG_PNM_PARSER 

	REGISTER_PARSER(PNM,                pnm);
#endif

#if CONFIG_RV30_PARSER 

	REGISTER_PARSER(RV30,               rv30);
#endif

#if CONFIG_RV40_PARSER 

	REGISTER_PARSER(RV40,               rv40);
#endif

#if CONFIG_TAK_PARSER 

	REGISTER_PARSER(TAK,                tak);
#endif

#if CONFIG_VC1_PARSER 

	REGISTER_PARSER(VC1,                vc1);
#endif

#if CONFIG_VORBIS_PARSER 

	REGISTER_PARSER(VORBIS,             vorbis);
#endif

#if CONFIG_VP3_PARSER 

	REGISTER_PARSER(VP3,                vp3);
#endif

#if CONFIG_VP8_PARSER 

	REGISTER_PARSER(VP8,                vp8);
#endif

#if CONFIG_AAC_ADTSTOASC_BSF 

	/* bitstream filters */
	REGISTER_BSF(AAC_ADTSTOASC,         aac_adtstoasc);
#endif

#if CONFIG_CHOMP_BSF 

	REGISTER_BSF(CHOMP,                 chomp);
#endif

#if CONFIG_DUMP_EXTRADATA_BSF 

	REGISTER_BSF(DUMP_EXTRADATA,        dump_extradata);
#endif

#if CONFIG_H264_MP4TOANNEXB_BSF 

	REGISTER_BSF(H264_MP4TOANNEXB,      h264_mp4toannexb);
#endif

#if CONFIG_IMX_DUMP_HEADER_BSF 

	REGISTER_BSF(IMX_DUMP_HEADER,       imx_dump_header);
#endif

#if CONFIG_MJPEG2JPEG_BSF 

	REGISTER_BSF(MJPEG2JPEG,            mjpeg2jpeg);
#endif

#if CONFIG_MJPEGA_DUMP_HEADER_BSF 

	REGISTER_BSF(MJPEGA_DUMP_HEADER,    mjpega_dump_header);
#endif

#if CONFIG_MP3_HEADER_COMPRESS_BSF 

	REGISTER_BSF(MP3_HEADER_COMPRESS,   mp3_header_compress);
#endif

#if CONFIG_MP3_HEADER_DECOMPRESS_BSF 

	REGISTER_BSF(MP3_HEADER_DECOMPRESS, mp3_header_decompress);
#endif

#if CONFIG_MOV2TEXTSUB_BSF 

	REGISTER_BSF(MOV2TEXTSUB,           mov2textsub);
#endif

#if CONFIG_NOISE_BSF 

	REGISTER_BSF(NOISE,                 noise);
#endif

#if CONFIG_REMOVE_EXTRADATA_BSF 

	REGISTER_BSF(REMOVE_EXTRADATA,      remove_extradata);
#endif

#if CONFIG_TEXT2MOVSUB_BSF 

	REGISTER_BSF(TEXT2MOVSUB,           text2movsub);
#endif


}
