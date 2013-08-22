/*
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

#include "cpu.h"
#include "config.h"
#include "opt.h"
#include "common.h"

#if HAVE_SCHED_GETAFFINITY
#ifndef _GNU_SOURCE
# define _GNU_SOURCE
#endif
#include <sched.h>
#endif
#if HAVE_GETPROCESSAFFINITYMASK
#include <windows.h>
#endif
#if HAVE_SYSCTL
#if HAVE_SYS_PARAM_H
#include <sys/param.h>
#endif
#include <sys/types.h>
#include <sys/param.h>
#include <sys/sysctl.h>
#endif
#if HAVE_SYSCONF
#include <unistd.h>
#endif

static int flags, checked;

void av_force_cpu_flags(int arg){
    flags   = arg;
    checked = arg != -1;
}

int av_get_cpu_flags(void)
{
    if (checked)
        return flags;
#if ARCH_ARM
    if (ARCH_ARM) flags = ff_get_cpu_flags_arm();
#endif

#if ARCH_PPC
    if (ARCH_PPC) flags = ff_get_cpu_flags_ppc();
#endif

#if ARCH_X86
    if (ARCH_X86) flags = ff_get_cpu_flags_x86();
#endif

    checked = 1;
    return flags;
}

void av_set_cpu_flags_mask(int mask)
{
    checked       = 0;
    flags         = av_get_cpu_flags() & mask;
    checked       = 1;
}


int av_parse_cpu_flags(const char *s)
{
#define CPUFLAG_MMXEXT   (AV_CPU_FLAG_MMX      | AV_CPU_FLAG_MMXEXT | AV_CPU_FLAG_CMOV)
#define CPUFLAG_3DNOW    (AV_CPU_FLAG_3DNOW    | AV_CPU_FLAG_MMX)
#define CPUFLAG_3DNOWEXT (AV_CPU_FLAG_3DNOWEXT | CPUFLAG_3DNOW)
#define CPUFLAG_SSE      (AV_CPU_FLAG_SSE      | CPUFLAG_MMXEXT)
#define CPUFLAG_SSE2     (AV_CPU_FLAG_SSE2     | CPUFLAG_SSE)
#define CPUFLAG_SSE2SLOW (AV_CPU_FLAG_SSE2SLOW | CPUFLAG_SSE2)
#define CPUFLAG_SSE3     (AV_CPU_FLAG_SSE3     | CPUFLAG_SSE2)
#define CPUFLAG_SSE3SLOW (AV_CPU_FLAG_SSE3SLOW | CPUFLAG_SSE3)
#define CPUFLAG_SSSE3    (AV_CPU_FLAG_SSSE3    | CPUFLAG_SSE3)
#define CPUFLAG_SSE4     (AV_CPU_FLAG_SSE4     | CPUFLAG_SSSE3)
#define CPUFLAG_SSE42    (AV_CPU_FLAG_SSE42    | CPUFLAG_SSE4)
#define CPUFLAG_AVX      (AV_CPU_FLAG_AVX      | CPUFLAG_SSE42)
#define CPUFLAG_XOP      (AV_CPU_FLAG_XOP      | CPUFLAG_AVX)
#define CPUFLAG_FMA4     (AV_CPU_FLAG_FMA4     | CPUFLAG_AVX)
    static const AVOption cpuflags_opts[] = {
        { "flags"   , NULL, 0, AV_OPT_TYPE_FLAGS, { 0 }, INT64_MIN, INT64_MAX, 0,"flags" },
#if   ARCH_PPC
        { "altivec" , NULL, 0, AV_OPT_TYPE_CONST, {AV_CPU_FLAG_ALTIVEC  },0,0,0, "flags" },
#elif ARCH_X86
        { "mmx"     , NULL, 0, AV_OPT_TYPE_CONST, {AV_CPU_FLAG_MMX},0,0,0,  "flags" },
        { "mmxext"  , NULL, 0, AV_OPT_TYPE_CONST, {CPUFLAG_MMXEXT},0,0,0,  "flags" },
        { "sse"     , NULL, 0, AV_OPT_TYPE_CONST, {CPUFLAG_SSE},0,0,0,  "flags" },
        { "sse2"    , NULL, 0, AV_OPT_TYPE_CONST, {CPUFLAG_SSE2},0,0,0,  "flags" },
        { "sse2slow", NULL, 0, AV_OPT_TYPE_CONST, {CPUFLAG_SSE2SLOW},0,0,0,  "flags" },
        { "sse3"    , NULL, 0, AV_OPT_TYPE_CONST, {CPUFLAG_SSE3},0,0,0, "flags" },
        { "sse3slow", NULL, 0, AV_OPT_TYPE_CONST, {CPUFLAG_SSE3SLOW},0,0,0,  "flags" },
        { "ssse3"   , NULL, 0, AV_OPT_TYPE_CONST, {CPUFLAG_SSSE3},0,0,0,  "flags" },
        { "atom"    , NULL, 0, AV_OPT_TYPE_CONST, {AV_CPU_FLAG_ATOM},0,0,0,  "flags" },
        { "sse4.1"  , NULL, 0, AV_OPT_TYPE_CONST, {CPUFLAG_SSE4},0,0,0,  "flags" },
        { "sse4.2"  , NULL, 0, AV_OPT_TYPE_CONST, {CPUFLAG_SSE42},0,0,0,  "flags" },
        { "avx"     , NULL, 0, AV_OPT_TYPE_CONST, {CPUFLAG_AVX},0,0,0,  "flags" },
        { "xop"     , NULL, 0, AV_OPT_TYPE_CONST, {CPUFLAG_XOP},0,0,0, "flags" },
        { "fma4"    , NULL, 0, AV_OPT_TYPE_CONST, {CPUFLAG_FMA4},0,0,0, "flags" },
        { "3dnow"   , NULL, 0, AV_OPT_TYPE_CONST, {CPUFLAG_3DNOW},0,0,0,  "flags" },
        { "3dnowext", NULL, 0, AV_OPT_TYPE_CONST, {CPUFLAG_3DNOWEXT},0,0,0,  "flags" },
        { "cmov",     NULL, 0, AV_OPT_TYPE_CONST, {AV_CPU_FLAG_CMOV}, 0,0,0,  "flags" },
#elif ARCH_ARM
        { "armv5te",  NULL, 0, AV_OPT_TYPE_CONST, {AV_CPU_FLAG_ARMV5TE  }, 0,0,0, "flags" },
        { "armv6",    NULL, 0, AV_OPT_TYPE_CONST, {AV_CPU_FLAG_ARMV6    }, 0,0,0,  "flags" },
        { "armv6t2",  NULL, 0, AV_OPT_TYPE_CONST, {AV_CPU_FLAG_ARMV6T2  }, 0,0,0,  "flags" },
        { "vfp",      NULL, 0, AV_OPT_TYPE_CONST, {AV_CPU_FLAG_VFP      }, 0,0,0,  "flags" },
        { "vfpv3",    NULL, 0, AV_OPT_TYPE_CONST, {AV_CPU_FLAG_VFPV3    },  0,0,0,  "flags" },
        { "neon",     NULL, 0, AV_OPT_TYPE_CONST, {AV_CPU_FLAG_NEON     },  0,0,0,  "flags" },
#endif
        { NULL },
    };

    static const AVClass class = {"cpuflags", av_default_item_name, cpuflags_opts,LIBAVUTIL_VERSION_INT,};

    int flags = 0, ret;
    const AVClass *pclass = &class;

    if ((ret = av_opt_eval_flags(&pclass, &cpuflags_opts[0], s, &flags)) < 0)
        return ret;

    return flags & INT_MAX;
}




int av_parse_cpu_caps(unsigned *flags, const char *s)
{
        static const AVOption cpuflags_opts[] = {
        { "flags"   , NULL, 0, AV_OPT_TYPE_FLAGS, { 0 }, INT64_MIN, INT64_MAX, 0,"flags" },
#if   ARCH_PPC
        { "altivec" , NULL, 0, AV_OPT_TYPE_CONST, {  AV_CPU_FLAG_ALTIVEC  }, 0,0,0, "flags" },
#elif ARCH_X86
        { "mmx"     , NULL, 0, AV_OPT_TYPE_CONST, {  AV_CPU_FLAG_MMX      },    0,0,0,"flags" },
        { "mmx2"    , NULL, 0, AV_OPT_TYPE_CONST, {  AV_CPU_FLAG_MMX2     },    0,0,0,"flags" },
        { "mmxext"  , NULL, 0, AV_OPT_TYPE_CONST, {  AV_CPU_FLAG_MMX2     },    0,0,0,"flags" },
        { "sse"     , NULL, 0, AV_OPT_TYPE_CONST, {  AV_CPU_FLAG_SSE      },    0,0,0,"flags" },
        { "sse2"    , NULL, 0, AV_OPT_TYPE_CONST, {  AV_CPU_FLAG_SSE2     },    0,0,0,"flags" },
        { "sse2slow", NULL, 0, AV_OPT_TYPE_CONST, {  AV_CPU_FLAG_SSE2SLOW },    0,0,0,"flags" },
        { "sse3"    , NULL, 0, AV_OPT_TYPE_CONST, {  AV_CPU_FLAG_SSE3     },    0,0,0,"flags" },
        { "sse3slow", NULL, 0, AV_OPT_TYPE_CONST, {  AV_CPU_FLAG_SSE3SLOW },    0,0,0,"flags" },
        { "ssse3"   , NULL, 0, AV_OPT_TYPE_CONST, {  AV_CPU_FLAG_SSSE3    },    0,0,0,"flags" },
        { "atom"    , NULL, 0, AV_OPT_TYPE_CONST, {  AV_CPU_FLAG_ATOM     },    0,0,0,"flags" },
        { "sse4.1"  , NULL, 0, AV_OPT_TYPE_CONST, {  AV_CPU_FLAG_SSE4     },    0,0,0,"flags" },
        { "sse4.2"  , NULL, 0, AV_OPT_TYPE_CONST, {  AV_CPU_FLAG_SSE42    },    0,0,0,"flags" },
        { "avx"     , NULL, 0, AV_OPT_TYPE_CONST, {  AV_CPU_FLAG_AVX      },    0,0,0,"flags" },
        { "xop"     , NULL, 0, AV_OPT_TYPE_CONST, {  AV_CPU_FLAG_XOP      },    0,0,0,"flags" },
        { "fma4"    , NULL, 0, AV_OPT_TYPE_CONST, {  AV_CPU_FLAG_FMA4     },    0,0,0,"flags" },
        { "3dnow"   , NULL, 0, AV_OPT_TYPE_CONST, {  AV_CPU_FLAG_3DNOW    },    0,0,0,"flags" },
        { "3dnowext", NULL, 0, AV_OPT_TYPE_CONST, {  AV_CPU_FLAG_3DNOWEXT },    0,0,0,"flags" },
        { "cmov",     NULL, 0, AV_OPT_TYPE_CONST, {  AV_CPU_FLAG_CMOV     },    0,0,0,"flags" },

#define CPU_FLAG_P2 AV_CPU_FLAG_CMOV | AV_CPU_FLAG_MMX
#define CPU_FLAG_P3 CPU_FLAG_P2 | AV_CPU_FLAG_MMX2 | AV_CPU_FLAG_SSE
#define CPU_FLAG_P4 CPU_FLAG_P3| AV_CPU_FLAG_SSE2
        { "pentium2", NULL, 0, AV_OPT_TYPE_CONST, {  CPU_FLAG_P2          },    0,0,0,"flags" },
        { "pentium3", NULL, 0, AV_OPT_TYPE_CONST, {  CPU_FLAG_P3          },    0,0,0,"flags" },
        { "pentium4", NULL, 0, AV_OPT_TYPE_CONST, {  CPU_FLAG_P4          },    0,0,0,"flags" },

#define CPU_FLAG_K62 AV_CPU_FLAG_MMX | AV_CPU_FLAG_3DNOW
#define CPU_FLAG_ATHLON   CPU_FLAG_K62 | AV_CPU_FLAG_CMOV | AV_CPU_FLAG_3DNOWEXT | AV_CPU_FLAG_MMX2
#define CPU_FLAG_ATHLONXP CPU_FLAG_ATHLON | AV_CPU_FLAG_SSE
#define CPU_FLAG_K8  CPU_FLAG_ATHLONXP | AV_CPU_FLAG_SSE2
        { "k6",       NULL, 0, AV_OPT_TYPE_CONST, {  AV_CPU_FLAG_MMX      },    0,0,0,"flags" },
        { "k62",      NULL, 0, AV_OPT_TYPE_CONST, {  CPU_FLAG_K62         },    0,0,0,"flags" },
        { "athlon",   NULL, 0, AV_OPT_TYPE_CONST, {  CPU_FLAG_ATHLON      },    0,0,0,"flags" },
        { "athlonxp", NULL, 0, AV_OPT_TYPE_CONST, {  CPU_FLAG_ATHLONXP    },    0,0,0,"flags" },
        { "k8",       NULL, 0, AV_OPT_TYPE_CONST, {  CPU_FLAG_K8          },    0,0,0,"flags" },
#elif ARCH_ARM
        { "armv5te",  NULL, 0, AV_OPT_TYPE_CONST, {  AV_CPU_FLAG_ARMV5TE  },    0,0,0,"flags" },
        { "armv6",    NULL, 0, AV_OPT_TYPE_CONST, {  AV_CPU_FLAG_ARMV6    },    0,0,0,"flags" },
        { "armv6t2",  NULL, 0, AV_OPT_TYPE_CONST, {  AV_CPU_FLAG_ARMV6T2  },    0,0,0,"flags" },
        { "vfp",      NULL, 0, AV_OPT_TYPE_CONST, {  AV_CPU_FLAG_VFP      },    0,0,0,"flags" },
        { "vfpv3",    NULL, 0, AV_OPT_TYPE_CONST, {  AV_CPU_FLAG_VFPV3    },    0,0,0,"flags" },
        { "neon",     NULL, 0, AV_OPT_TYPE_CONST, {  AV_CPU_FLAG_NEON     },    0,0,0,"flags" },
#endif
        { NULL },
    };
    static const AVClass class = {"cpuflags", av_default_item_name, cpuflags_opts, LIBAVUTIL_VERSION_INT,};
    const AVClass *pclass = &class;

    return av_opt_eval_flags(&pclass, &cpuflags_opts[0], s, flags);
}

int av_cpu_count(void)
{
    static volatile int printed;

    int nb_cpus = 1;
#if HAVE_SCHED_GETAFFINITY && defined(CPU_COUNT)
    cpu_set_t cpuset;

    CPU_ZERO(&cpuset);

    if (!sched_getaffinity(0, sizeof(cpuset), &cpuset))
        nb_cpus = CPU_COUNT(&cpuset);
#elif HAVE_GETPROCESSAFFINITYMASK
    DWORD_PTR proc_aff, sys_aff;
    if (GetProcessAffinityMask(GetCurrentProcess(), &proc_aff, &sys_aff))
        nb_cpus = av_popcount64(proc_aff);
#elif HAVE_SYSCTL && defined(HW_NCPU)
    int mib[2] = { CTL_HW, HW_NCPU };
    size_t len = sizeof(nb_cpus);

    if (sysctl(mib, 2, &nb_cpus, &len, NULL, 0) == -1)
        nb_cpus = 0;
#elif HAVE_SYSCONF && defined(_SC_NPROC_ONLN)
    nb_cpus = sysconf(_SC_NPROC_ONLN);
#elif HAVE_SYSCONF && defined(_SC_NPROCESSORS_ONLN)
    nb_cpus = sysconf(_SC_NPROCESSORS_ONLN);
#endif

    if (!printed) {
        av_log(NULL, AV_LOG_DEBUG, "detected %d logical cores\n", nb_cpus);
        printed = 1;
    }

    return nb_cpus;
}

#ifdef TEST

#include <stdio.h>

static const struct {
    int flag;
    const char *name;
} cpu_flag_tab[] = {
#if   ARCH_ARM
    { AV_CPU_FLAG_ARMV5TE,   "armv5te"    },
    { AV_CPU_FLAG_ARMV6,     "armv6"      },
    { AV_CPU_FLAG_ARMV6T2,   "armv6t2"    },
    { AV_CPU_FLAG_VFP,       "vfp"        },
    { AV_CPU_FLAG_VFPV3,     "vfpv3"      },
    { AV_CPU_FLAG_NEON,      "neon"       },
#elif ARCH_PPC
    { AV_CPU_FLAG_ALTIVEC,   "altivec"    },
#elif ARCH_X86
    { AV_CPU_FLAG_MMX,       "mmx"        },
    { AV_CPU_FLAG_MMXEXT,    "mmxext"     },
    { AV_CPU_FLAG_SSE,       "sse"        },
    { AV_CPU_FLAG_SSE2,      "sse2"       },
    { AV_CPU_FLAG_SSE2SLOW,  "sse2(slow)" },
    { AV_CPU_FLAG_SSE3,      "sse3"       },
    { AV_CPU_FLAG_SSE3SLOW,  "sse3(slow)" },
    { AV_CPU_FLAG_SSSE3,     "ssse3"      },
    { AV_CPU_FLAG_ATOM,      "atom"       },
    { AV_CPU_FLAG_SSE4,      "sse4.1"     },
    { AV_CPU_FLAG_SSE42,     "sse4.2"     },
    { AV_CPU_FLAG_AVX,       "avx"        },
    { AV_CPU_FLAG_XOP,       "xop"        },
    { AV_CPU_FLAG_FMA4,      "fma4"       },
    { AV_CPU_FLAG_3DNOW,     "3dnow"      },
    { AV_CPU_FLAG_3DNOWEXT,  "3dnowext"   },
    { AV_CPU_FLAG_CMOV,      "cmov"       },
#endif
    { 0 }
};

int main(void)
{
    int cpu_flags = av_get_cpu_flags();
    int i;

    printf("cpu_flags = 0x%08X\n", cpu_flags);
    printf("cpu_flags =");
    for (i = 0; cpu_flag_tab[i].flag; i++)
        if (cpu_flags & cpu_flag_tab[i].flag)
            printf(" %s", cpu_flag_tab[i].name);
    printf("\n");

    return 0;
}

#endif
