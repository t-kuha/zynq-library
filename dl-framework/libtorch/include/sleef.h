//          Copyright Naoki Shibata 2010 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef __SLEEF_H__
#define __SLEEF_H__

#include <stddef.h>
#include <stdint.h>

#if (defined(__GNUC__) || defined(__CLANG__)) && !defined(__INTEL_COMPILER)
#define CONST const
#else
#define CONST
#endif

#if (defined(__MINGW32__) || defined(__MINGW64__) || defined(__CYGWIN__) || defined(_MSC_VER)) && !defined(SLEEF_STATIC_LIBS)
#ifdef IMPORT_IS_EXPORT
#define IMPORT __declspec(dllexport)
#else // #ifdef IMPORT_IS_EXPORT
#define IMPORT __declspec(dllimport)
#if (defined(_MSC_VER))
#pragma comment(lib,"sleef.lib")
#endif // #if (defined(_MSC_VER))
#endif // #ifdef IMPORT_IS_EXPORT
#else // #if (defined(__MINGW32__) || defined(__MINGW64__) || defined(__CYGWIN__) || defined(_MSC_VER)) && !defined(SLEEF_STATIC_LIBS)
#define IMPORT
#endif // #if (defined(__MINGW32__) || defined(__MINGW64__) || defined(__CYGWIN__) || defined(_MSC_VER)) && !defined(SLEEF_STATIC_LIBS)

#if (defined(__GNUC__) || defined(__CLANG__)) && (defined(__i386__) || defined(__x86_64__))
#include <x86intrin.h>
#endif

#if (defined(_MSC_VER))
#include <intrin.h>
#endif

#if defined(__ARM_NEON__) || defined(__ARM_NEON)
#include <arm_neon.h>
#endif

#if defined(__ARM_FEATURE_SVE)
#include <arm_sve.h>
#endif

//

#ifndef SLEEF_FP_ILOGB0
#define SLEEF_FP_ILOGB0 ((int)-2147483648)
#endif

#ifndef SLEEF_FP_ILOGBNAN
#define SLEEF_FP_ILOGBNAN ((int)2147483647)
#endif

//

IMPORT void *Sleef_malloc(size_t z);
IMPORT void Sleef_free(void *ptr);
IMPORT uint64_t Sleef_currentTimeMicros();

#if defined(__i386__) || defined(__x86_64__) || defined(_MSC_VER)
IMPORT void Sleef_x86CpuID(int32_t out[4], uint32_t eax, uint32_t ecx);
#endif

//

#ifndef Sleef_double2_DEFINED
#define Sleef_double2_DEFINED
typedef struct {
  double x, y;
} Sleef_double2;
#endif

#ifndef Sleef_float2_DEFINED
#define Sleef_float2_DEFINED
typedef struct {
  float x, y;
} Sleef_float2;
#endif

#ifndef Sleef_longdouble2_DEFINED
#define Sleef_longdouble2_DEFINED
typedef struct {
  long double x, y;
} Sleef_longdouble2;
#endif

#if defined(ENABLEFLOAT128) && !defined(Sleef_quad2_DEFINED)
#define Sleef_quad2_DEFINED
typedef __float128 Sleef_quad;
typedef struct {
  __float128 x, y;
} Sleef_quad2;
#endif

#ifdef __cplusplus
extern "C"
{
#endif

IMPORT CONST double Sleef_sin_u35(double);
IMPORT CONST double Sleef_cos_u35(double);
IMPORT CONST Sleef_double2 Sleef_sincos_u35(double);
IMPORT CONST double Sleef_tan_u35(double);
IMPORT CONST double Sleef_asin_u35(double);
IMPORT CONST double Sleef_acos_u35(double);
IMPORT CONST double Sleef_atan_u35(double);
IMPORT CONST double Sleef_atan2_u35(double, double);
IMPORT CONST double Sleef_log_u35(double);
IMPORT CONST double Sleef_cbrt_u35(double);
IMPORT CONST double Sleef_sin_u10(double);
IMPORT CONST double Sleef_cos_u10(double);
IMPORT CONST Sleef_double2 Sleef_sincos_u10(double);
IMPORT CONST double Sleef_tan_u10(double);
IMPORT CONST double Sleef_asin_u10(double);
IMPORT CONST double Sleef_acos_u10(double);
IMPORT CONST double Sleef_atan_u10(double);
IMPORT CONST double Sleef_atan2_u10(double, double);
IMPORT CONST double Sleef_log_u10(double);
IMPORT CONST double Sleef_cbrt_u10(double);
IMPORT CONST double Sleef_exp_u10(double);
IMPORT CONST double Sleef_pow_u10(double, double);
IMPORT CONST double Sleef_sinh_u10(double);
IMPORT CONST double Sleef_cosh_u10(double);
IMPORT CONST double Sleef_tanh_u10(double);
IMPORT CONST double Sleef_asinh_u10(double);
IMPORT CONST double Sleef_acosh_u10(double);
IMPORT CONST double Sleef_atanh_u10(double);
IMPORT CONST double Sleef_exp2_u10(double);
IMPORT CONST double Sleef_exp10_u10(double);
IMPORT CONST double Sleef_expm1_u10(double);
IMPORT CONST double Sleef_log10_u10(double);
IMPORT CONST double Sleef_log2_u10(double);
IMPORT CONST double Sleef_log1p_u10(double);
IMPORT CONST Sleef_double2 Sleef_sincospi_u05(double);
IMPORT CONST Sleef_double2 Sleef_sincospi_u35(double);
IMPORT CONST double Sleef_sinpi_u05(double);
IMPORT CONST double Sleef_cospi_u05(double);
IMPORT CONST double Sleef_ldexp(double, int);
IMPORT CONST int Sleef_ilogb(double);
IMPORT CONST double Sleef_fma(double, double, double);
IMPORT CONST double Sleef_sqrt(double);
IMPORT CONST double Sleef_sqrt_u05(double);
IMPORT CONST double Sleef_sqrt_u35(double);

IMPORT CONST double Sleef_hypot_u05(double, double);
IMPORT CONST double Sleef_hypot_u35(double, double);

IMPORT CONST double Sleef_fabs(double);
IMPORT CONST double Sleef_copysign(double, double);
IMPORT CONST double Sleef_fmax(double, double);
IMPORT CONST double Sleef_fmin(double, double);
IMPORT CONST double Sleef_fdim(double, double);
IMPORT CONST double Sleef_trunc(double);
IMPORT CONST double Sleef_floor(double);
IMPORT CONST double Sleef_ceil(double);
IMPORT CONST double Sleef_round(double);
IMPORT CONST double Sleef_rint(double);
IMPORT CONST double Sleef_nextafter(double, double);
IMPORT CONST double Sleef_frfrexp(double);
IMPORT CONST int Sleef_expfrexp(double);
IMPORT CONST double Sleef_fmod(double, double);
IMPORT CONST Sleef_double2 Sleef_modf(double);

IMPORT CONST double Sleef_lgamma_u10(double);
IMPORT CONST double Sleef_tgamma_u10(double);
IMPORT CONST double Sleef_erf_u10(double);
IMPORT CONST double Sleef_erfc_u15(double);

IMPORT CONST float Sleef_sinf_u35(float);
IMPORT CONST float Sleef_cosf_u35(float);
IMPORT CONST Sleef_float2 Sleef_sincosf_u35(float);
IMPORT CONST float Sleef_tanf_u35(float);
IMPORT CONST float Sleef_asinf_u35(float);
IMPORT CONST float Sleef_acosf_u35(float);
IMPORT CONST float Sleef_atanf_u35(float);
IMPORT CONST float Sleef_atan2f_u35(float, float);
IMPORT CONST float Sleef_logf_u35(float);
IMPORT CONST float Sleef_cbrtf_u35(float);
IMPORT CONST float Sleef_sinf_u10(float);
IMPORT CONST float Sleef_cosf_u10(float);
IMPORT CONST Sleef_float2 Sleef_sincosf_u10(float);
IMPORT CONST float Sleef_tanf_u10(float);
IMPORT CONST float Sleef_asinf_u10(float);
IMPORT CONST float Sleef_acosf_u10(float);
IMPORT CONST float Sleef_atanf_u10(float);
IMPORT CONST float Sleef_atan2f_u10(float, float);
IMPORT CONST float Sleef_logf_u10(float);
IMPORT CONST float Sleef_cbrtf_u10(float);
IMPORT CONST float Sleef_expf_u10(float);
IMPORT CONST float Sleef_powf_u10(float, float);
IMPORT CONST float Sleef_sinhf_u10(float);
IMPORT CONST float Sleef_coshf_u10(float);
IMPORT CONST float Sleef_tanhf_u10(float);
IMPORT CONST float Sleef_asinhf_u10(float);
IMPORT CONST float Sleef_acoshf_u10(float);
IMPORT CONST float Sleef_atanhf_u10(float);
IMPORT CONST float Sleef_exp2f_u10(float);
IMPORT CONST float Sleef_exp10f_u10(float);
IMPORT CONST float Sleef_expm1f_u10(float);
IMPORT CONST float Sleef_log10f_u10(float);
IMPORT CONST float Sleef_log2f_u10(float);
IMPORT CONST float Sleef_log1pf_u10(float);
IMPORT CONST Sleef_float2 Sleef_sincospif_u05(float);
IMPORT CONST Sleef_float2 Sleef_sincospif_u35(float);
IMPORT CONST float Sleef_sinpif_u05(float d);
IMPORT CONST float Sleef_cospif_u05(float d);
IMPORT CONST float Sleef_ldexpf(float, int);
IMPORT CONST int Sleef_ilogbf(float);
IMPORT CONST float Sleef_fmaf(float, float, float);
IMPORT CONST float Sleef_sqrtf(float);
IMPORT CONST float Sleef_sqrtf_u05(float);
IMPORT CONST float Sleef_sqrtf_u35(float);

IMPORT CONST float Sleef_hypotf_u05(float, float);
IMPORT CONST float Sleef_hypotf_u35(float, float);

IMPORT CONST float Sleef_fabsf(float);
IMPORT CONST float Sleef_copysignf(float, float);
IMPORT CONST float Sleef_fmaxf(float, float);
IMPORT CONST float Sleef_fminf(float, float);
IMPORT CONST float Sleef_fdimf(float, float);
IMPORT CONST float Sleef_truncf(float);
IMPORT CONST float Sleef_floorf(float);
IMPORT CONST float Sleef_ceilf(float);
IMPORT CONST float Sleef_roundf(float);
IMPORT CONST float Sleef_rintf(float);
IMPORT CONST float Sleef_nextafterf(float, float);
IMPORT CONST float Sleef_frfrexpf(float);
IMPORT CONST int Sleef_expfrexpf(float);
IMPORT CONST float Sleef_fmodf(float, float);
IMPORT CONST Sleef_float2 Sleef_modff(float);

IMPORT CONST float Sleef_lgammaf_u10(float);
IMPORT CONST float Sleef_tgammaf_u10(float);
IMPORT CONST float Sleef_erff_u10(float);
IMPORT CONST float Sleef_erfcf_u15(float);

IMPORT CONST Sleef_longdouble2 Sleef_sincospil_u05(long double);
IMPORT CONST Sleef_longdouble2 Sleef_sincospil_u35(long double);

#if defined(Sleef_quad2_DEFINED)
IMPORT CONST Sleef_quad2 Sleef_sincospiq_u05(Sleef_quad);
IMPORT CONST Sleef_quad2 Sleef_sincospiq_u35(Sleef_quad);
#endif
#ifdef __ARM_NEON__
#define STRUCT_KEYWORD___ARM_NEON__ struct

#ifndef Sleef_float32x4_t_2_DEFINED
typedef STRUCT_KEYWORD___ARM_NEON__ {
  float32x4_t x, y;
} Sleef_float32x4_t_2;
#define Sleef_float32x4_t_2_DEFINED
#endif

IMPORT CONST float32x4_t Sleef_sinf4_u35(float32x4_t);
IMPORT CONST float32x4_t Sleef_cosf4_u35(float32x4_t);
IMPORT CONST Sleef_float32x4_t_2 Sleef_sincosf4_u35(float32x4_t);
IMPORT CONST float32x4_t Sleef_tanf4_u35(float32x4_t);
IMPORT CONST float32x4_t Sleef_asinf4_u35(float32x4_t);
IMPORT CONST float32x4_t Sleef_acosf4_u35(float32x4_t);
IMPORT CONST float32x4_t Sleef_atanf4_u35(float32x4_t);
IMPORT CONST float32x4_t Sleef_atan2f4_u35(float32x4_t, float32x4_t);
IMPORT CONST float32x4_t Sleef_logf4_u35(float32x4_t);
IMPORT CONST float32x4_t Sleef_cbrtf4_u35(float32x4_t);
IMPORT CONST float32x4_t Sleef_sinf4_u10(float32x4_t);
IMPORT CONST float32x4_t Sleef_cosf4_u10(float32x4_t);
IMPORT CONST Sleef_float32x4_t_2 Sleef_sincosf4_u10(float32x4_t);
IMPORT CONST float32x4_t Sleef_tanf4_u10(float32x4_t);
IMPORT CONST float32x4_t Sleef_asinf4_u10(float32x4_t);
IMPORT CONST float32x4_t Sleef_acosf4_u10(float32x4_t);
IMPORT CONST float32x4_t Sleef_atanf4_u10(float32x4_t);
IMPORT CONST float32x4_t Sleef_atan2f4_u10(float32x4_t, float32x4_t);
IMPORT CONST float32x4_t Sleef_logf4_u10(float32x4_t);
IMPORT CONST float32x4_t Sleef_cbrtf4_u10(float32x4_t);
IMPORT CONST float32x4_t Sleef_expf4_u10(float32x4_t);
IMPORT CONST float32x4_t Sleef_powf4_u10(float32x4_t, float32x4_t);
IMPORT CONST float32x4_t Sleef_sinhf4_u10(float32x4_t);
IMPORT CONST float32x4_t Sleef_coshf4_u10(float32x4_t);
IMPORT CONST float32x4_t Sleef_tanhf4_u10(float32x4_t);
IMPORT CONST float32x4_t Sleef_asinhf4_u10(float32x4_t);
IMPORT CONST float32x4_t Sleef_acoshf4_u10(float32x4_t);
IMPORT CONST float32x4_t Sleef_atanhf4_u10(float32x4_t);
IMPORT CONST float32x4_t Sleef_exp2f4_u10(float32x4_t);
IMPORT CONST float32x4_t Sleef_exp10f4_u10(float32x4_t);
IMPORT CONST float32x4_t Sleef_expm1f4_u10(float32x4_t);
IMPORT CONST float32x4_t Sleef_log10f4_u10(float32x4_t);
IMPORT CONST float32x4_t Sleef_log2f4_u10(float32x4_t);
IMPORT CONST float32x4_t Sleef_log1pf4_u10(float32x4_t);
IMPORT CONST Sleef_float32x4_t_2 Sleef_sincospif4_u05(float32x4_t);
IMPORT CONST Sleef_float32x4_t_2 Sleef_sincospif4_u35(float32x4_t);
IMPORT CONST float32x4_t Sleef_sinpif4_u05(float32x4_t);
IMPORT CONST float32x4_t Sleef_cospif4_u05(float32x4_t);
IMPORT CONST float32x4_t Sleef_fmaf4(float32x4_t, float32x4_t, float32x4_t);
IMPORT CONST float32x4_t Sleef_sqrtf4(float32x4_t);
IMPORT CONST float32x4_t Sleef_sqrtf4_u05(float32x4_t);
IMPORT CONST float32x4_t Sleef_sqrtf4_u35(float32x4_t);
IMPORT CONST float32x4_t Sleef_hypotf4_u05(float32x4_t, float32x4_t);
IMPORT CONST float32x4_t Sleef_hypotf4_u35(float32x4_t, float32x4_t);
IMPORT CONST float32x4_t Sleef_fabsf4(float32x4_t);
IMPORT CONST float32x4_t Sleef_copysignf4(float32x4_t, float32x4_t);
IMPORT CONST float32x4_t Sleef_fmaxf4(float32x4_t, float32x4_t);
IMPORT CONST float32x4_t Sleef_fminf4(float32x4_t, float32x4_t);
IMPORT CONST float32x4_t Sleef_fdimf4(float32x4_t, float32x4_t);
IMPORT CONST float32x4_t Sleef_truncf4(float32x4_t);
IMPORT CONST float32x4_t Sleef_floorf4(float32x4_t);
IMPORT CONST float32x4_t Sleef_ceilf4(float32x4_t);
IMPORT CONST float32x4_t Sleef_roundf4(float32x4_t);
IMPORT CONST float32x4_t Sleef_rintf4(float32x4_t);
IMPORT CONST float32x4_t Sleef_nextafterf4(float32x4_t, float32x4_t);
IMPORT CONST float32x4_t Sleef_frfrexpf4(float32x4_t);
IMPORT CONST float32x4_t Sleef_fmodf4(float32x4_t, float32x4_t);
IMPORT CONST Sleef_float32x4_t_2 Sleef_modff4(float32x4_t);
IMPORT CONST float32x4_t Sleef_lgammaf4_u10(float32x4_t);
IMPORT CONST float32x4_t Sleef_tgammaf4_u10(float32x4_t);
IMPORT CONST float32x4_t Sleef_erff4_u10(float32x4_t);
IMPORT CONST float32x4_t Sleef_erfcf4_u15(float32x4_t);
IMPORT CONST int Sleef_getIntf4(int);
IMPORT CONST void *Sleef_getPtrf4(int);
#endif
#ifdef __ARM_NEON__
#define STRUCT_KEYWORD___ARM_NEON__ struct

#ifndef Sleef_float32x4_t_2_DEFINED
typedef STRUCT_KEYWORD___ARM_NEON__ {
  float32x4_t x, y;
} Sleef_float32x4_t_2;
#define Sleef_float32x4_t_2_DEFINED
#endif

IMPORT CONST float32x4_t Sleef_sinf4_u35neon(float32x4_t);
IMPORT CONST float32x4_t Sleef_cosf4_u35neon(float32x4_t);
IMPORT CONST Sleef_float32x4_t_2 Sleef_sincosf4_u35neon(float32x4_t);
IMPORT CONST float32x4_t Sleef_tanf4_u35neon(float32x4_t);
IMPORT CONST float32x4_t Sleef_asinf4_u35neon(float32x4_t);
IMPORT CONST float32x4_t Sleef_acosf4_u35neon(float32x4_t);
IMPORT CONST float32x4_t Sleef_atanf4_u35neon(float32x4_t);
IMPORT CONST float32x4_t Sleef_atan2f4_u35neon(float32x4_t, float32x4_t);
IMPORT CONST float32x4_t Sleef_logf4_u35neon(float32x4_t);
IMPORT CONST float32x4_t Sleef_cbrtf4_u35neon(float32x4_t);
IMPORT CONST float32x4_t Sleef_sinf4_u10neon(float32x4_t);
IMPORT CONST float32x4_t Sleef_cosf4_u10neon(float32x4_t);
IMPORT CONST Sleef_float32x4_t_2 Sleef_sincosf4_u10neon(float32x4_t);
IMPORT CONST float32x4_t Sleef_tanf4_u10neon(float32x4_t);
IMPORT CONST float32x4_t Sleef_asinf4_u10neon(float32x4_t);
IMPORT CONST float32x4_t Sleef_acosf4_u10neon(float32x4_t);
IMPORT CONST float32x4_t Sleef_atanf4_u10neon(float32x4_t);
IMPORT CONST float32x4_t Sleef_atan2f4_u10neon(float32x4_t, float32x4_t);
IMPORT CONST float32x4_t Sleef_logf4_u10neon(float32x4_t);
IMPORT CONST float32x4_t Sleef_cbrtf4_u10neon(float32x4_t);
IMPORT CONST float32x4_t Sleef_expf4_u10neon(float32x4_t);
IMPORT CONST float32x4_t Sleef_powf4_u10neon(float32x4_t, float32x4_t);
IMPORT CONST float32x4_t Sleef_sinhf4_u10neon(float32x4_t);
IMPORT CONST float32x4_t Sleef_coshf4_u10neon(float32x4_t);
IMPORT CONST float32x4_t Sleef_tanhf4_u10neon(float32x4_t);
IMPORT CONST float32x4_t Sleef_asinhf4_u10neon(float32x4_t);
IMPORT CONST float32x4_t Sleef_acoshf4_u10neon(float32x4_t);
IMPORT CONST float32x4_t Sleef_atanhf4_u10neon(float32x4_t);
IMPORT CONST float32x4_t Sleef_exp2f4_u10neon(float32x4_t);
IMPORT CONST float32x4_t Sleef_exp10f4_u10neon(float32x4_t);
IMPORT CONST float32x4_t Sleef_expm1f4_u10neon(float32x4_t);
IMPORT CONST float32x4_t Sleef_log10f4_u10neon(float32x4_t);
IMPORT CONST float32x4_t Sleef_log2f4_u10neon(float32x4_t);
IMPORT CONST float32x4_t Sleef_log1pf4_u10neon(float32x4_t);
IMPORT CONST Sleef_float32x4_t_2 Sleef_sincospif4_u05neon(float32x4_t);
IMPORT CONST Sleef_float32x4_t_2 Sleef_sincospif4_u35neon(float32x4_t);
IMPORT CONST float32x4_t Sleef_sinpif4_u05neon(float32x4_t);
IMPORT CONST float32x4_t Sleef_cospif4_u05neon(float32x4_t);
IMPORT CONST float32x4_t Sleef_fmaf4_neon(float32x4_t, float32x4_t, float32x4_t);
IMPORT CONST float32x4_t Sleef_sqrtf4_neon(float32x4_t);
IMPORT CONST float32x4_t Sleef_sqrtf4_u05neon(float32x4_t);
IMPORT CONST float32x4_t Sleef_sqrtf4_u35neon(float32x4_t);
IMPORT CONST float32x4_t Sleef_hypotf4_u05neon(float32x4_t, float32x4_t);
IMPORT CONST float32x4_t Sleef_hypotf4_u35neon(float32x4_t, float32x4_t);
IMPORT CONST float32x4_t Sleef_fabsf4_neon(float32x4_t);
IMPORT CONST float32x4_t Sleef_copysignf4_neon(float32x4_t, float32x4_t);
IMPORT CONST float32x4_t Sleef_fmaxf4_neon(float32x4_t, float32x4_t);
IMPORT CONST float32x4_t Sleef_fminf4_neon(float32x4_t, float32x4_t);
IMPORT CONST float32x4_t Sleef_fdimf4_neon(float32x4_t, float32x4_t);
IMPORT CONST float32x4_t Sleef_truncf4_neon(float32x4_t);
IMPORT CONST float32x4_t Sleef_floorf4_neon(float32x4_t);
IMPORT CONST float32x4_t Sleef_ceilf4_neon(float32x4_t);
IMPORT CONST float32x4_t Sleef_roundf4_neon(float32x4_t);
IMPORT CONST float32x4_t Sleef_rintf4_neon(float32x4_t);
IMPORT CONST float32x4_t Sleef_nextafterf4_neon(float32x4_t, float32x4_t);
IMPORT CONST float32x4_t Sleef_frfrexpf4_neon(float32x4_t);
IMPORT CONST float32x4_t Sleef_fmodf4_neon(float32x4_t, float32x4_t);
IMPORT CONST Sleef_float32x4_t_2 Sleef_modff4_neon(float32x4_t);
IMPORT CONST float32x4_t Sleef_lgammaf4_u10neon(float32x4_t);
IMPORT CONST float32x4_t Sleef_tgammaf4_u10neon(float32x4_t);
IMPORT CONST float32x4_t Sleef_erff4_u10neon(float32x4_t);
IMPORT CONST float32x4_t Sleef_erfcf4_u15neon(float32x4_t);
IMPORT CONST int Sleef_getIntf4_neon(int);
IMPORT CONST void *Sleef_getPtrf4_neon(int);
#endif
#ifdef __cplusplus
}
#endif

#undef IMPORT
#endif // #ifndef __SLEEF_H__
