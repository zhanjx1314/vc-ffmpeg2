/*
 * filter registration
 * Copyright (c) 2008 Vitor Sessak
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

#include "avfilter.h"
#include "config.h"
#include "opencl_allkernels.h"


#define REGISTER_FILTER(X, x, y)                                        \
    {                                                                   \
        extern AVFilter avfilter_##y##_##x;                             \
        if (CONFIG_##X##_FILTER)                                        \
            avfilter_register(&avfilter_##y##_##x);                     \
    }

#define REGISTER_FILTER_UNCONDITIONAL(x)                                \
    {                                                                   \
        extern AVFilter avfilter_##x;                                   \
        avfilter_register(&avfilter_##x);                               \
    }

void avfilter_register_all(void)
{
    static int initialized;

    if (initialized)
        return;
    initialized = 1;

#if FF_API_ACONVERT_FILTER
#if CONFIG_ACONVERT_FILTER
    REGISTER_FILTER(ACONVERT,       aconvert,       af);
#endif
#endif

#if CONFIG_AFADE_FILTER 
	REGISTER_FILTER(AFADE,          afade,          af);
#endif

#if CONFIG_AFORMAT_FILTER 

	REGISTER_FILTER(AFORMAT,        aformat,        af);
#endif

#if CONFIG_AINTERLEAVE_FILTER 

	REGISTER_FILTER(AINTERLEAVE,    ainterleave,    af);
#endif

#if CONFIG_ALLPASS_FILTER 

	REGISTER_FILTER(ALLPASS,        allpass,        af);
#endif

#if CONFIG_AMERGE_FILTER 

	REGISTER_FILTER(AMERGE,         amerge,         af);
#endif

#if CONFIG_AMIX_FILTER 

	REGISTER_FILTER(AMIX,           amix,           af);
#endif

#if CONFIG_ANULL_FILTER 

	REGISTER_FILTER(ANULL,          anull,          af);
#endif

#if CONFIG_APAD_FILTER 

	REGISTER_FILTER(APAD,           apad,           af);
#endif

#if CONFIG_APERMS_FILTER 

	REGISTER_FILTER(APERMS,         aperms,         af);
#endif

#if CONFIG_APHASER_FILTER 

	REGISTER_FILTER(APHASER,        aphaser,        af);
#endif

#if CONFIG_ARESAMPLE_FILTER 

	REGISTER_FILTER(ARESAMPLE,      aresample,      af);
#endif

#if CONFIG_ASELECT_FILTER 

	REGISTER_FILTER(ASELECT,        aselect,        af);
#endif

#if CONFIG_ASENDCMD_FILTER 

	REGISTER_FILTER(ASENDCMD,       asendcmd,       af);
#endif

#if CONFIG_ASETNSAMPLES_FILTER 

	REGISTER_FILTER(ASETNSAMPLES,   asetnsamples,   af);
#endif

#if CONFIG_ASETPTS_FILTER 

	REGISTER_FILTER(ASETPTS,        asetpts,        af);
#endif

#if CONFIG_ASETRATE_FILTER 

	REGISTER_FILTER(ASETRATE,       asetrate,       af);
#endif

#if CONFIG_ASETTB_FILTER 

	REGISTER_FILTER(ASETTB,         asettb,         af);
#endif

#if CONFIG_ASHOWINFO_FILTER 

	REGISTER_FILTER(ASHOWINFO,      ashowinfo,      af);
#endif

#if CONFIG_ASPLIT_FILTER 

	REGISTER_FILTER(ASPLIT,         asplit,         af);
#endif

#if CONFIG_ASTATS_FILTER 

	REGISTER_FILTER(ASTATS,         astats,         af);
#endif

#if CONFIG_ASTREAMSYNC_FILTER 

	REGISTER_FILTER(ASTREAMSYNC,    astreamsync,    af);
#endif

#if CONFIG_ASYNCTS_FILTER 

	REGISTER_FILTER(ASYNCTS,        asyncts,        af);
#endif

#if CONFIG_ATEMPO_FILTER 

	REGISTER_FILTER(ATEMPO,         atempo,         af);
#endif

#if CONFIG_ATRIM_FILTER 

	REGISTER_FILTER(ATRIM,          atrim,          af);
#endif

#if CONFIG_AZMQ_FILTER 

	REGISTER_FILTER(AZMQ,           azmq,           af);
#endif

#if CONFIG_BANDPASS_FILTER 

	REGISTER_FILTER(BANDPASS,       bandpass,       af);
#endif

#if CONFIG_BANDREJECT_FILTER 

	REGISTER_FILTER(BANDREJECT,     bandreject,     af);
#endif

#if CONFIG_BASS_FILTER 

	REGISTER_FILTER(BASS,           bass,           af);
#endif

#if CONFIG_BIQUAD_FILTER 

	REGISTER_FILTER(BIQUAD,         biquad,         af);
#endif

#if CONFIG_CHANNELMAP_FILTER 

	REGISTER_FILTER(CHANNELMAP,     channelmap,     af);
#endif

#if CONFIG_CHANNELSPLIT_FILTER 

	REGISTER_FILTER(CHANNELSPLIT,   channelsplit,   af);
#endif

#if CONFIG_EARWAX_FILTER 

	REGISTER_FILTER(EARWAX,         earwax,         af);
#endif

#if CONFIG_EBUR128_FILTER 

	REGISTER_FILTER(EBUR128,        ebur128,        af);
#endif

#if CONFIG_EQUALIZER_FILTER 

	REGISTER_FILTER(EQUALIZER,      equalizer,      af);
#endif

#if CONFIG_HIGHPASS_FILTER 

	REGISTER_FILTER(HIGHPASS,       highpass,       af);
#endif

#if CONFIG_JOIN_FILTER 

	REGISTER_FILTER(JOIN,           join,           af);
#endif

#if CONFIG_LOWPASS_FILTER 

	REGISTER_FILTER(LOWPASS,        lowpass,        af);
#endif

#if CONFIG_PAN_FILTER 

	REGISTER_FILTER(PAN,            pan,            af);
#endif

#if CONFIG_RESAMPLE_FILTER 

	REGISTER_FILTER(RESAMPLE,       resample,       af);
#endif

#if CONFIG_SILENCEDETECT_FILTER 

	REGISTER_FILTER(SILENCEDETECT,  silencedetect,  af);
#endif

#if CONFIG_TREBLE_FILTER 

	REGISTER_FILTER(TREBLE,         treble,         af);
#endif

#if CONFIG_VOLUME_FILTER 

	REGISTER_FILTER(VOLUME,         volume,         af);
#endif

#if CONFIG_VOLUMEDETECT_FILTER 

	REGISTER_FILTER(VOLUMEDETECT,   volumedetect,   af);
#endif

#if CONFIG_AEVALSRC_FILTER 


	REGISTER_FILTER(AEVALSRC,       aevalsrc,       asrc);
#endif

#if CONFIG_ANULLSRC_FILTER 

	REGISTER_FILTER(ANULLSRC,       anullsrc,       asrc);
#endif

#if CONFIG_FLITE_FILTER 

	REGISTER_FILTER(FLITE,          flite,          asrc);
#endif

#if CONFIG_SINE_FILTER 

	REGISTER_FILTER(SINE,           sine,           asrc);
#endif

#if CONFIG_ANULLSINK_FILTER 


	REGISTER_FILTER(ANULLSINK,      anullsink,      asink);
#endif

#if CONFIG_ALPHAEXTRACT_FILTER 


	REGISTER_FILTER(ALPHAEXTRACT,   alphaextract,   vf);
#endif

#if CONFIG_ALPHAMERGE_FILTER 

	REGISTER_FILTER(ALPHAMERGE,     alphamerge,     vf);
#endif

#if CONFIG_ASS_FILTER 

	REGISTER_FILTER(ASS,            ass,            vf);
#endif

#if CONFIG_BBOX_FILTER 

	REGISTER_FILTER(BBOX,           bbox,           vf);
#endif

#if CONFIG_BLACKDETECT_FILTER 

	REGISTER_FILTER(BLACKDETECT,    blackdetect,    vf);
#endif

#if CONFIG_BLACKFRAME_FILTER 

	REGISTER_FILTER(BLACKFRAME,     blackframe,     vf);
#endif

#if CONFIG_BLEND_FILTER 

	REGISTER_FILTER(BLEND,          blend,          vf);
#endif

#if CONFIG_BOXBLUR_FILTER 

	REGISTER_FILTER(BOXBLUR,        boxblur,        vf);
#endif

#if CONFIG_COLORBALANCE_FILTER 

	REGISTER_FILTER(COLORBALANCE,   colorbalance,   vf);
#endif

#if CONFIG_COLORCHANNELMIXER_FILTER 

	REGISTER_FILTER(COLORCHANNELMIXER, colorchannelmixer, vf);
#endif

#if CONFIG_COLORMATRIX_FILTER 

	REGISTER_FILTER(COLORMATRIX,    colormatrix,    vf);
#endif

#if CONFIG_COPY_FILTER 

	REGISTER_FILTER(COPY,           copy,           vf);
#endif

#if CONFIG_CROP_FILTER 

	REGISTER_FILTER(CROP,           crop,           vf);
#endif

#if CONFIG_CROPDETECT_FILTER 

	REGISTER_FILTER(CROPDETECT,     cropdetect,     vf);
#endif

#if CONFIG_CURVES_FILTER 

	REGISTER_FILTER(CURVES,         curves,         vf);
#endif

#if CONFIG_DCTDNOIZ_FILTER 

	REGISTER_FILTER(DCTDNOIZ,       dctdnoiz,       vf);
#endif

#if CONFIG_DECIMATE_FILTER 

	REGISTER_FILTER(DECIMATE,       decimate,       vf);
#endif

#if CONFIG_DELOGO_FILTER 

	REGISTER_FILTER(DELOGO,         delogo,         vf);
#endif

#if CONFIG_DESHAKE_FILTER 

	REGISTER_FILTER(DESHAKE,        deshake,        vf);
#endif

#if CONFIG_DRAWBOX_FILTER 

	REGISTER_FILTER(DRAWBOX,        drawbox,        vf);
#endif

#if CONFIG_DRAWGRID_FILTER 

	REGISTER_FILTER(DRAWGRID,       drawgrid,       vf);
#endif

#if CONFIG_DRAWTEXT_FILTER 

	REGISTER_FILTER(DRAWTEXT,       drawtext,       vf);
#endif

#if CONFIG_EDGEDETECT_FILTER 

	REGISTER_FILTER(EDGEDETECT,     edgedetect,     vf);
#endif

#if CONFIG_EXTRACTPLANES_FILTER 

	REGISTER_FILTER(EXTRACTPLANES,  extractplanes,  vf);
#endif

#if CONFIG_FADE_FILTER 

	REGISTER_FILTER(FADE,           fade,           vf);
#endif

#if CONFIG_FIELD_FILTER 

	REGISTER_FILTER(FIELD,          field,          vf);
#endif

#if CONFIG_FIELDMATCH_FILTER 

	REGISTER_FILTER(FIELDMATCH,     fieldmatch,     vf);
#endif

#if CONFIG_FIELDORDER_FILTER 

	REGISTER_FILTER(FIELDORDER,     fieldorder,     vf);
#endif

#if CONFIG_FORMAT_FILTER 

	REGISTER_FILTER(FORMAT,         format,         vf);
#endif

#if CONFIG_FPS_FILTER 

	REGISTER_FILTER(FPS,            fps,            vf);
#endif

#if CONFIG_FRAMESTEP_FILTER 

	REGISTER_FILTER(FRAMESTEP,      framestep,      vf);
#endif

#if CONFIG_FREI0R_FILTER 

	REGISTER_FILTER(FREI0R,         frei0r,         vf);
#endif

#if CONFIG_GEQ_FILTER 

	REGISTER_FILTER(GEQ,            geq,            vf);
#endif

#if CONFIG_GRADFUN_FILTER 

	REGISTER_FILTER(GRADFUN,        gradfun,        vf);
#endif

#if CONFIG_HALDCLUT_FILTER 

	REGISTER_FILTER(HALDCLUT,       haldclut,       vf);
#endif

#if CONFIG_HFLIP_FILTER 

	REGISTER_FILTER(HFLIP,          hflip,          vf);
#endif

#if CONFIG_HISTEQ_FILTER 

	REGISTER_FILTER(HISTEQ,         histeq,         vf);
#endif

#if CONFIG_HISTOGRAM_FILTER 

	REGISTER_FILTER(HISTOGRAM,      histogram,      vf);
#endif

#if CONFIG_HQDN3D_FILTER 

	REGISTER_FILTER(HQDN3D,         hqdn3d,         vf);
#endif

#if CONFIG_HUE_FILTER 

	REGISTER_FILTER(HUE,            hue,            vf);
#endif

#if CONFIG_IDET_FILTER 

	REGISTER_FILTER(IDET,           idet,           vf);
#endif

#if CONFIG_IL_FILTER 

	REGISTER_FILTER(IL,             il,             vf);
#endif

#if CONFIG_INTERLACE_FILTER 

	REGISTER_FILTER(INTERLACE,      interlace,      vf);
#endif

#if CONFIG_INTERLEAVE_FILTER 

	REGISTER_FILTER(INTERLEAVE,     interleave,     vf);
#endif

#if CONFIG_KERNDEINT_FILTER 

	REGISTER_FILTER(KERNDEINT,      kerndeint,      vf);
#endif

#if CONFIG_LUT3D_FILTER 

	REGISTER_FILTER(LUT3D,          lut3d,          vf);
#endif

#if CONFIG_LUT_FILTER 

	REGISTER_FILTER(LUT,            lut,            vf);
#endif

#if CONFIG_LUTRGB_FILTER 

	REGISTER_FILTER(LUTRGB,         lutrgb,         vf);
#endif

#if CONFIG_LUTYUV_FILTER 

	REGISTER_FILTER(LUTYUV,         lutyuv,         vf);
#endif

#if CONFIG_MCDEINT_FILTER 

	REGISTER_FILTER(MCDEINT,        mcdeint,        vf);
#endif

#if CONFIG_MP_FILTER 

	REGISTER_FILTER(MP,             mp,             vf);
#endif

#if CONFIG_MPDECIMATE_FILTER 

	REGISTER_FILTER(MPDECIMATE,     mpdecimate,     vf);
#endif

#if CONFIG_NEGATE_FILTER 

	REGISTER_FILTER(NEGATE,         negate,         vf);
#endif

#if CONFIG_NOFORMAT_FILTER 

	REGISTER_FILTER(NOFORMAT,       noformat,       vf);
#endif

#if CONFIG_NOISE_FILTER 

	REGISTER_FILTER(NOISE,          noise,          vf);
#endif

#if CONFIG_NULL_FILTER 

	REGISTER_FILTER(NULL,           null,           vf);
#endif

#if CONFIG_OCV_FILTER 

	REGISTER_FILTER(OCV,            ocv,            vf);
#endif

#if CONFIG_OVERLAY_FILTER 

	REGISTER_FILTER(OVERLAY,        overlay,        vf);
#endif

#if CONFIG_OWDENOISE_FILTER 

	REGISTER_FILTER(OWDENOISE,      owdenoise,      vf);
#endif

#if CONFIG_PAD_FILTER 

	REGISTER_FILTER(PAD,            pad,            vf);
#endif

#if CONFIG_PERMS_FILTER 

	REGISTER_FILTER(PERMS,          perms,          vf);
#endif

#if CONFIG_PIXDESCTEST_FILTER 

	REGISTER_FILTER(PIXDESCTEST,    pixdesctest,    vf);
#endif

#if CONFIG_PP_FILTER 

	REGISTER_FILTER(PP,             pp,             vf);
#endif

#if CONFIG_PSNR_FILTER 

	REGISTER_FILTER(PSNR,           psnr,           vf);
#endif

#if CONFIG_REMOVELOGO_FILTER 

	REGISTER_FILTER(REMOVELOGO,     removelogo,     vf);
#endif

#if CONFIG_ROTATE_FILTER 

	REGISTER_FILTER(ROTATE,         rotate,         vf);
#endif

#if CONFIG_SAB_FILTER 

	REGISTER_FILTER(SAB,            sab,            vf);
#endif

#if CONFIG_SCALE_FILTER 

	REGISTER_FILTER(SCALE,          scale,          vf);
#endif

#if CONFIG_SELECT_FILTER 

	REGISTER_FILTER(SELECT,         select,         vf);
#endif

#if CONFIG_SENDCMD_FILTER 

	REGISTER_FILTER(SENDCMD,        sendcmd,        vf);
#endif

#if CONFIG_SEPARATEFIELDS_FILTER 

	REGISTER_FILTER(SEPARATEFIELDS, separatefields, vf);
#endif

#if CONFIG_SETDAR_FILTER 

	REGISTER_FILTER(SETDAR,         setdar,         vf);
#endif

#if CONFIG_SETFIELD_FILTER 

	REGISTER_FILTER(SETFIELD,       setfield,       vf);
#endif

#if CONFIG_SETPTS_FILTER 

	REGISTER_FILTER(SETPTS,         setpts,         vf);
#endif

#if CONFIG_SETSAR_FILTER 

	REGISTER_FILTER(SETSAR,         setsar,         vf);
#endif

#if CONFIG_SETTB_FILTER 

	REGISTER_FILTER(SETTB,          settb,          vf);
#endif

#if CONFIG_SHOWINFO_FILTER 

	REGISTER_FILTER(SHOWINFO,       showinfo,       vf);
#endif

#if CONFIG_SMARTBLUR_FILTER 

	REGISTER_FILTER(SMARTBLUR,      smartblur,      vf);
#endif

#if CONFIG_SPLIT_FILTER 

	REGISTER_FILTER(SPLIT,          split,          vf);
#endif

#if CONFIG_SPP_FILTER 

	REGISTER_FILTER(SPP,            spp,            vf);
#endif

#if CONFIG_STEREO3D_FILTER 

	REGISTER_FILTER(STEREO3D,       stereo3d,       vf);
#endif

#if CONFIG_SUBTITLES_FILTER 

	REGISTER_FILTER(SUBTITLES,      subtitles,      vf);
#endif

#if CONFIG_SUPER2XSAI_FILTER 

	REGISTER_FILTER(SUPER2XSAI,     super2xsai,     vf);
#endif

#if CONFIG_SWAPUV_FILTER 

	REGISTER_FILTER(SWAPUV,         swapuv,         vf);
#endif

#if CONFIG_TELECINE_FILTER 

	REGISTER_FILTER(TELECINE,       telecine,       vf);
#endif

#if CONFIG_THUMBNAIL_FILTER 

	REGISTER_FILTER(THUMBNAIL,      thumbnail,      vf);
#endif

#if CONFIG_TILE_FILTER 

	REGISTER_FILTER(TILE,           tile,           vf);
#endif

#if CONFIG_TINTERLACE_FILTER 

	REGISTER_FILTER(TINTERLACE,     tinterlace,     vf);
#endif

#if CONFIG_TRANSPOSE_FILTER 

	REGISTER_FILTER(TRANSPOSE,      transpose,      vf);
#endif

#if CONFIG_TRIM_FILTER 

	REGISTER_FILTER(TRIM,           trim,           vf);
#endif

#if CONFIG_UNSHARP_FILTER 

	REGISTER_FILTER(UNSHARP,        unsharp,        vf);
#endif

#if CONFIG_VFLIP_FILTER 

	REGISTER_FILTER(VFLIP,          vflip,          vf);
#endif

#if CONFIG_VIDSTABDETECT_FILTER 

	REGISTER_FILTER(VIDSTABDETECT,  vidstabdetect,  vf);
#endif

#if CONFIG_VIDSTABTRANSFORM_FILTER 

	REGISTER_FILTER(VIDSTABTRANSFORM, vidstabtransform, vf);
#endif

#if CONFIG_VIGNETTE_FILTER 

	REGISTER_FILTER(VIGNETTE,       vignette,       vf);
#endif

#if CONFIG_YADIF_FILTER 

	REGISTER_FILTER(YADIF,          yadif,          vf);
#endif

#if CONFIG_ZMQ_FILTER 

	REGISTER_FILTER(ZMQ,            zmq,            vf);
#endif

#if CONFIG_CELLAUTO_FILTER 


	REGISTER_FILTER(CELLAUTO,       cellauto,       vsrc);
#endif

#if CONFIG_COLOR_FILTER 

	REGISTER_FILTER(COLOR,          color,          vsrc);
#endif

#if CONFIG_FREI0R_FILTER 

	REGISTER_FILTER(FREI0R,         frei0r_src,     vsrc);
#endif

#if CONFIG_HALDCLUTSRC_FILTER 

	REGISTER_FILTER(HALDCLUTSRC,    haldclutsrc,    vsrc);
#endif

#if CONFIG_LIFE_FILTER 

	REGISTER_FILTER(LIFE,           life,           vsrc);
#endif

#if CONFIG_MANDELBROT_FILTER 

	REGISTER_FILTER(MANDELBROT,     mandelbrot,     vsrc);
#endif

#if CONFIG_MPTESTSRC_FILTER 

	REGISTER_FILTER(MPTESTSRC,      mptestsrc,      vsrc);
#endif

#if CONFIG_NULLSRC_FILTER 

	REGISTER_FILTER(NULLSRC,        nullsrc,        vsrc);
#endif

#if CONFIG_RGBTESTSRC_FILTER 

	REGISTER_FILTER(RGBTESTSRC,     rgbtestsrc,     vsrc);
#endif

#if CONFIG_SMPTEBARS_FILTER 

	REGISTER_FILTER(SMPTEBARS,      smptebars,      vsrc);
#endif

#if CONFIG_SMPTEHDBARS_FILTER 

	REGISTER_FILTER(SMPTEHDBARS,    smptehdbars,    vsrc);
#endif

#if CONFIG_TESTSRC_FILTER 

	REGISTER_FILTER(TESTSRC,        testsrc,        vsrc);
#endif

#if CONFIG_NULLSINK_FILTER 


	REGISTER_FILTER(NULLSINK,       nullsink,       vsink);
#endif

#if CONFIG_AVECTORSCOPE_FILTER 


	/* multimedia filters */
	REGISTER_FILTER(AVECTORSCOPE,   avectorscope,   avf);
#endif

#if CONFIG_CONCAT_FILTER 

	REGISTER_FILTER(CONCAT,         concat,         avf);
#endif

#if CONFIG_SHOWSPECTRUM_FILTER 

	REGISTER_FILTER(SHOWSPECTRUM,   showspectrum,   avf);
#endif

#if CONFIG_SHOWWAVES_FILTER 

	REGISTER_FILTER(SHOWWAVES,      showwaves,      avf);
#endif

#if CONFIG_AMOVIE_FILTER 


	/* multimedia sources */
	REGISTER_FILTER(AMOVIE,         amovie,         avsrc);
#endif

#if CONFIG_MOVIE_FILTER 

	REGISTER_FILTER(MOVIE,          movie,          avsrc);
#endif

#if FF_API_AVFILTERBUFFER
    REGISTER_FILTER_UNCONDITIONAL(vsink_ffbuffersink);
    REGISTER_FILTER_UNCONDITIONAL(asink_ffabuffersink);
#endif

    /* those filters are part of public or internal API => registered
     * unconditionally */
    REGISTER_FILTER_UNCONDITIONAL(asrc_abuffer);
    REGISTER_FILTER_UNCONDITIONAL(vsrc_buffer);
    REGISTER_FILTER_UNCONDITIONAL(asink_abuffer);
    REGISTER_FILTER_UNCONDITIONAL(vsink_buffer);
    REGISTER_FILTER_UNCONDITIONAL(af_afifo);
    REGISTER_FILTER_UNCONDITIONAL(vf_fifo);
    ff_opencl_register_filter_kernel_code_all();
}
