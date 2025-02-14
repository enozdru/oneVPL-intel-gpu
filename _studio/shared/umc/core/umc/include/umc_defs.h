// Copyright (c) 2003-2020 Intel Corporation
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef __UMC_DEFS_H__
#define __UMC_DEFS_H__

#include "mfx_config.h"
// This file contains defines which switch on/off support of
// codecs and renderers on application level
/*
// Windows
*/

/*
// Linux on IA32
*/

#if !defined(ANDROID)

    // video decoders
    //#define UMC_ENABLE_VP8_VIDEO_DECODER
    #define MFX_ENABLE_VP9_VIDEO_DECODE

    // video encoders
    #define UMC_ENABLE_MVC_VIDEO_ENCODER
    #define UMC_ENABLE_MPEG2_VIDEO_ENCODER
    #define UMC_ENABLE_MPEG4_VIDEO_ENCODER

    #define UMC_ENABLE_UMC_SCENE_ANALYZER

#endif // Linux on IA32

/*
// Android
*/

#if defined(ANDROID)

    // video encoders
    #define UMC_ENABLE_MVC_VIDEO_ENCODER

    #define UMC_ENABLE_UMC_SCENE_ANALYZER

#endif // Android

#ifdef __cplusplus

namespace UMC
{

};

#endif //__cplusplus

// splitters
#define UMC_ENABLE_AVI_SPLITTER
#define UMC_ENABLE_MPEG2_SPLITTER
#define UMC_ENABLE_MP4_SPLITTER
#define UMC_ENABLE_VC1_SPLITTER
#define UMC_ENABLE_H264_SPLITTER
#include "ipps.h"

#include <stdint.h>

#ifdef __cplusplus
#include <cstring>
#include <algorithm>
#define MFX_INTERNAL_CPY(dst, src, size) std::copy((const uint8_t *)(src), (const uint8_t *)(src)+(int)(size), (uint8_t *)(dst))
#else
#define MFX_INTERNAL_CPY(dst, src, size) memcpy((uint8_t *)(dst), (const uint8_t *)(src), (int)(size))
#endif //__cplusplus

#define MFX_INTERNAL_ZERO(dst, size) memset((uint8_t *)(dst), 0, (int)(size))

#ifndef MFX_ABS
#define MFX_ABS( a )    ((a) >= 0 ? (a) : -(a))
#endif

#define MFX_MAX_32S    ( 2147483647 )
#define MFX_MAXABS_64F ( 1.7976931348623158e+308 )
#define MFX_MAX_32U    ( 0xFFFFFFFF )

  #define MFX_MAX_64S  ( 9223372036854775807LL )

typedef IppiSize mfxSize;

  #define __STDCALL
  #define __CDECL

  #define ALIGN_DECL(X) __attribute__ ((aligned(X)))

/******************************************************************************/

#endif // __UMC_DEFS_H__
