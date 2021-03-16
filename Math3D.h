#pragma once
#include <math.h>

typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;

typedef _Bool bool;
#define true 1
#define false 0

#define declare_vectors(type) \
typedef type __attribute__((ext_vector_type(2))) type##2; \
typedef type __attribute__((ext_vector_type(3))) type##3; \
typedef type __attribute__((ext_vector_type(4))) type##4;
declare_vectors(char)
declare_vectors(uchar)
declare_vectors(short)
declare_vectors(ushort)
declare_vectors(int)
declare_vectors(uint)
declare_vectors(long)
declare_vectors(ulong)
declare_vectors(float)
declare_vectors(double)
#undef declare_vectors

#define type2_cast(t, v) ((t##2){ (t)((v).x), (t)((v).y) })
#define type3_cast(t, v) ((t##3){ (t)((v).x), (t)((v).y), (t)((v).z) })
#define type4_cast(t, v) ((t##4){ (t)((v).x), (t)((v).y), (t)((v).z), (t)((v).w) })
#define char2_cast(v) type2_cast(char, v)
#define char3_cast(v) type3_cast(char, v)
#define char4_cast(v) type4_cast(char, v)
#define uchar2_cast(v) type2_cast(uchar, v)
#define uchar3_cast(v) type3_cast(uchar, v)
#define uchar4_cast(v) type4_cast(uchar, v)
#define short2_cast(v) type2_cast(short, v)
#define short3_cast(v) type3_cast(short, v)
#define short4_cast(v) type4_cast(short, v)
#define ushort2_cast(v) type2_cast(ushort, v)
#define ushort3_cast(v) type3_cast(ushort, v)
#define ushort4_cast(v) type4_cast(ushort, v)
#define int2_cast(v) type2_cast(int, v)
#define int3_cast(v) type3_cast(int, v)
#define int4_cast(v) type4_cast(int, v)
#define uint2_cast(v) type2_cast(uint, v)
#define uint3_cast(v) type3_cast(uint, v)
#define uint4_cast(v) type4_cast(uint, v)
#define long2_cast(v) type2_cast(long, v)
#define long3_cast(v) type3_cast(long, v)
#define long4_cast(v) type4_cast(long, v)
#define ulong2_cast(v) type2_cast(ulong, v)
#define ulong3_cast(v) type3_cast(ulong, v)
#define ulong4_cast(v) type4_cast(ulong, v)
#define float2_cast(v) type2_cast(float, v)
#define float3_cast(v) type3_cast(float, v)
#define float4_cast(v) type4_cast(float, v)
#define double2_cast(v) type2_cast(double, v)
#define double3_cast(v) type3_cast(double, v)
#define double4_cast(v) type4_cast(double, v)

#define declare_vector_constants(type, t) \
static inline type##2 zero_2##t() { return (type##2){ 0, 0 }; } \
static inline type##2 one_2##t() { return (type##2){ 1, 1 }; } \
static inline type##2 x_2##t() { return (type##2){ 1, 0 }; } \
static inline type##2 y_2##t() { return (type##2){ 0, 1 }; } \
static inline type##3 zero_3##t() { return (type##3){ 0, 0, 0 }; } \
static inline type##3 one_3##t() { return (type##3){ 1, 1, 1 }; } \
static inline type##3 x_3##t() { return (type##3){ 1, 0, 0 }; } \
static inline type##3 y_3##t() { return (type##3){ 0, 1, 0 }; } \
static inline type##3 z_3##t() { return (type##3){ 0, 0, 1 }; } \
static inline type##4 zero_4##t() { return (type##4){ 0, 0, 0, 0 }; } \
static inline type##4 one_4##t() { return (type##4){ 1, 1, 1, 1 }; } \
static inline type##4 x_4##t() { return (type##4){ 1, 0, 0, 0 }; } \
static inline type##4 y_4##t() { return (type##4){ 0, 1, 0, 0 }; } \
static inline type##4 z_4##t() { return (type##4){ 0, 0, 1, 0 }; } \
static inline type##4 w_4##t() { return (type##4){ 0, 0, 0, 1 }; }
declare_vector_constants(char, c)
declare_vector_constants(uchar, uc)
declare_vector_constants(short, s)
declare_vector_constants(ushort, us)
declare_vector_constants(int, i)
declare_vector_constants(uint, ui)
declare_vector_constants(long, l)
declare_vector_constants(ulong, ul)
declare_vector_constants(float, f)
declare_vector_constants(double, d)
#undef declare_vector_constants

static inline char abs_c(char v) { return abs(v); }
static inline short abs_s(short v) { return abs(v); }
static inline int abs_i(int v) { return abs(v); }
static inline long abs_l(long v) { return labs(v); }
static inline float abs_f(float v) { return fabsf(v); }
static inline double abs_d(double v) { return fabs(v); }
#define declare_abs(type, t) \
static inline type##2 abs_2##t(type##2 v) { return (type##2){ abs_##t(v.x), abs_##t(v.y) }; } \
static inline type##3 abs_3##t(type##3 v) { return (type##3){ abs_##t(v.x), abs_##t(v.y), abs_##t(v.z) }; } \
static inline type##4 abs_4##t(type##4 v) { return (type##4){ abs_##t(v.x), abs_##t(v.y), abs_##t(v.z), abs_##t(v.w) }; }
declare_abs(char, c)
declare_abs(short, s)
declare_abs(int, i)
declare_abs(long, l)
declare_abs(float, f)
declare_abs(double, d)
#undef declare_abs

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

#define declare_max(type, t) \
static inline type max_##t(type a, type b) { return MAX(a, b); } \
static inline type##2 max_2##t(type##2 a, type##2 b) { return (type##2){ MAX(a.x, b.x), MAX(a.y, b.y) }; } \
static inline type##3 max_3##t(type##3 a, type##3 b) { return (type##3){ MAX(a.x, b.x), MAX(a.y, b.y), MAX(a.z, b.z) }; } \
static inline type##4 max_4##t(type##4 a, type##4 b) { return (type##4){ MAX(a.x, b.x), MAX(a.y, b.y), MAX(a.z, b.z), MAX(a.w, b.w) }; }
declare_max(char, c)
declare_max(uchar, uc)
declare_max(short, s)
declare_max(ushort, us)
declare_max(int, i)
declare_max(uint, ui)
declare_max(long, l)
declare_max(ulong, ul)
declare_max(float, f)
declare_max(double, d)
#undef declare_max

#define declare_min(type, t) \
static inline type min_##t(type a, type b) { return MAX(a, b); } \
static inline type##2 min_2##t(type##2 a, type##2 b) { return (type##2){ MIN(a.x, b.x), MIN(a.y, b.y) }; } \
static inline type##3 min_3##t(type##3 a, type##3 b) { return (type##3){ MIN(a.x, b.x), MIN(a.y, b.y), MIN(a.z, b.z) }; } \
static inline type##4 min_4##t(type##4 a, type##4 b) { return (type##4){ MIN(a.x, b.x), MIN(a.y, b.y), MIN(a.z, b.z), MIN(a.w, b.w) }; }
declare_min(char, c)
declare_min(uchar, uc)
declare_min(short, s)
declare_min(ushort, us)
declare_min(int, i)
declare_min(uint, ui)
declare_min(long, l)
declare_min(ulong, ul)
declare_min(float, f)
declare_min(double, d)
#undef declare_min

#define CLAMP(v, a, b) ((v) < (a) ? (a) : ((v) > (b) ? (b) : (v)))
#define declare_clamp(type, t) \
static inline type clamp_##t(type v, type a, type b) { return CLAMP(v, a, b); } \
static inline type##2 clamp_2##t(type##2 v, type a, type b) { return (type##2){ CLAMP(v.x, a, b), CLAMP(v.y, a, b) }; } \
static inline type##3 clamp_3##t(type##3 v, type a, type b) { return (type##3){ CLAMP(v.x, a, b), CLAMP(v.y, a, b), CLAMP(v.z, a, b) }; } \
static inline type##4 clamp_4##t(type##4 v, type a, type b) { return (type##4){ CLAMP(v.x, a, b), CLAMP(v.y, a, b), CLAMP(v.z, a, b), CLAMP(v.w, a, b) }; }
declare_clamp(char, c)
declare_clamp(uchar, uc)
declare_clamp(short, s)
declare_clamp(ushort, us)
declare_clamp(int, i)
declare_clamp(uint, ui)
declare_clamp(long, l)
declare_clamp(ulong, ul)
declare_clamp(float, f)
declare_clamp(double, d)
#undef declare_clamp

#define SIGN(v) ((v) > 0 ? 1 : ((v) < 0 ? -1 : 0))
#define declare_sign(type, t) \
static inline type sign_##t(type v) { return SIGN(v); } \
static inline type##2 sign_2##t(type##2 v) { return (type##2){ SIGN(v.x), SIGN(v.y) }; } \
static inline type##3 sign_3##t(type##3 v) { return (type##3){ SIGN(v.x), SIGN(v.y), SIGN(v.z) }; } \
static inline type##4 sign_4##t(type##4 v) { return (type##4){ SIGN(v.x), SIGN(v.y), SIGN(v.z), SIGN(v.w) }; }
declare_sign(char, c)
declare_sign(uchar, uc)
declare_sign(short, s)
declare_sign(ushort, us)
declare_sign(int, i)
declare_sign(uint, ui)
declare_sign(long, l)
declare_sign(ulong, ul)
declare_sign(float, f)
declare_sign(double, d)
#undef declare_sign

#define declare_degrees(type, t) \
static inline type degrees_##t(type rad) { return rad * (type)180 / M_PI; } \
static inline type##2 degrees_2##t(type##2 rad) { return rad * (type)180 / M_PI; } \
static inline type##3 degrees_3##t(type##3 rad) { return rad * (type)180 / M_PI; } \
static inline type##4 degrees_4##t(type##4 rad) { return rad * (type)180 / M_PI; }
declare_degrees(float, f)
declare_degrees(double, d)
#undef declare_degrees

#define declare_radians(type, t) \
static inline type radians_##t(type deg) { return deg * M_PI / (type)180; } \
static inline type##2 radians_2##t(type##2 deg) { return deg * M_PI / (type)180; } \
static inline type##3 radians_3##t(type##3 deg) { return deg * M_PI / (type)180; } \
static inline type##4 radians_4##t(type##4 deg) { return deg * M_PI / (type)180; }
declare_radians(float, f)
declare_radians(double, d)
#undef declare_degrees

#define declare_mix(type, t) \
static inline type mix_##t(type a, type b, type t) { return a * ((type)1 - t) + b * t; } \
static inline type##2 mix_2##t(type##2 a, type##2 b, type t) { return a * ((type)1 - t) + b * t; } \
static inline type##3 mix_3##t(type##3 a, type##3 b, type t) { return a * ((type)1 - t) + b * t; } \
static inline type##4 mix_4##t(type##4 a, type##4 b, type t) { return a * ((type)1 - t) + b * t; }
declare_mix(float, f)
declare_mix(double, d)
#undef declare_mix

#define STEP(edge, v) (v < edge ? 0 : 1)
#define declare_step(type, t) \
static inline type step_##t(type edge, type v) { return STEP(edge, v); } \
static inline type##2 step_2##t(type##2 edge, type##2 v) { return (type##2){ STEP(edge.x, v.x), STEP(edge.y, v.y) }; } \
static inline type##3 step_3##t(type##3 edge, type##3 v) { return (type##3){ STEP(edge.x, v.x), STEP(edge.y, v.y), STEP(edge.z, v.z) }; } \
static inline type##4 step_4##t(type##4 edge, type##4 v) { return (type##4){ STEP(edge.x, v.x), STEP(edge.y, v.y), STEP(edge.z, v.z), STEP(edge.w, v.w) }; }
declare_step(float, f)
declare_step(double, d)
#undef declare_step

#define declare_smoothstep(type, t) \
static inline type smoothstep_##t(type edge0, type edge1, type v) { type a = clamp_##t((v - edge0) / (edge1 - edge0), (type)0, (type)1); return a * a * ((type)3 - (type)2 * a); } \
static inline type##2 smoothstep_2##t(type##2 edge0, type##2 edge1, type##2 v) { type##2 a = clamp_2##t((v - edge0) / (edge1 - edge0), (type)0, (type)1); return a * a * ((type)3 - (type)2 * a); } \
static inline type##3 smoothstep_3##t(type##3 edge0, type##3 edge1, type##3 v) { type##3 a = clamp_3##t((v - edge0) / (edge1 - edge0), (type)0, (type)1); return a * a * ((type)3 - (type)2 * a); } \
static inline type##4 smoothstep_4##t(type##4 edge0, type##4 edge1, type##4 v) { type##4 a = clamp_4##t((v - edge0) / (edge1 - edge0), (type)0, (type)1); return a * a * ((type)3 - (type)2 * a); }
declare_smoothstep(float, f)
declare_smoothstep(double, d)
#undef declare_smoothstep

static inline float acos_f(float x) { return acosf(x); }
static inline double acos_d(double x) { return acos(x); }
#define declare_acos(type, t) \
static inline type##2 acos_2##t(type##2 v) { return (type##2){ acos_##t(v.x), acos_##t(v.y) }; } \
static inline type##3 acos_3##t(type##3 v) { return (type##3){ acos_##t(v.x), acos_##t(v.y), acos_##t(v.z) }; } \
static inline type##4 acos_4##t(type##4 v) { return (type##4){ acos_##t(v.x), acos_##t(v.y), acos_##t(v.z), acos_##t(v.w) }; }
declare_acos(float, f)
declare_acos(double, d)
#undef declare_acos

static inline float acosh_f(float x) { return acoshf(x); }
static inline double acosh_d(double x) { return acosh(x); }
#define declare_acosh(type, t) \
static inline type##2 acosh_2##t(type##2 v) { return (type##2){ acosh_##t(v.x), acosh_##t(v.y) }; } \
static inline type##3 acosh_3##t(type##3 v) { return (type##3){ acosh_##t(v.x), acosh_##t(v.y), acosh_##t(v.z) }; } \
static inline type##4 acosh_4##t(type##4 v) { return (type##4){ acosh_##t(v.x), acosh_##t(v.y), acosh_##t(v.z), acosh_##t(v.w) }; }
declare_acosh(float, f)
declare_acosh(double, d)
#undef declare_acosh

static inline float asin_f(float x) { return asinf(x); }
static inline double asin_d(double x) { return asin(x); }
#define declare_asin(type, t) \
static inline type##2 asin_2##t(type##2 v) { return (type##2){ asin_##t(v.x), asin_##t(v.y) }; } \
static inline type##3 asin_3##t(type##3 v) { return (type##3){ asin_##t(v.x), asin_##t(v.y), asin_##t(v.z) }; } \
static inline type##4 asin_4##t(type##4 v) { return (type##4){ asin_##t(v.x), asin_##t(v.y), asin_##t(v.z), asin_##t(v.w) }; }
declare_asin(float, f)
declare_asin(double, d)
#undef declare_asin

static inline float asinh_f(float x) { return asinhf(x); }
static inline double asinh_d(double x) { return asinh(x); }
#define declare_asinh(type, t) \
static inline type##2 asinh_2##t(type##2 v) { return (type##2){ asinh_##t(v.x), asinh_##t(v.y) }; } \
static inline type##3 asinh_3##t(type##3 v) { return (type##3){ asinh_##t(v.x), asinh_##t(v.y), asinh_##t(v.z) }; } \
static inline type##4 asinh_4##t(type##4 v) { return (type##4){ asinh_##t(v.x), asinh_##t(v.y), asinh_##t(v.z), asinh_##t(v.w) }; }
declare_asinh(float, f)
declare_asinh(double, d)
#undef declare_asinh

static inline float atan_f(float x) { return atanf(x); }
static inline double atan_d(double x) { return atan(x); }
#define declare_atan(type, t) \
static inline type##2 atan_2##t(type##2 v) { return (type##2){ atan_##t(v.x), atan_##t(v.y) }; } \
static inline type##3 atan_3##t(type##3 v) { return (type##3){ atan_##t(v.x), atan_##t(v.y), atan_##t(v.z) }; } \
static inline type##4 atan_4##t(type##4 v) { return (type##4){ atan_##t(v.x), atan_##t(v.y), atan_##t(v.z), atan_##t(v.w) }; }
declare_atan(float, f)
declare_atan(double, d)
#undef declare_atan

static inline float atan2_f(float x, float y) { return atan2f(x, y); }
static inline double atan2_d(double x, double y) { return atan2(x, y); }
#define declare_atan2(type, t) \
static inline type##2 atan2_2##t(type##2 vx, type##2 vy) { return (type##2){ atan2_##t(vx.x, vy.x), atan2_##t(vx.y, vy.y) }; } \
static inline type##3 atan2_3##t(type##3 vx, type##3 vy) { return (type##3){ atan2_##t(vx.x, vy.x), atan2_##t(vx.y, vy.y), atan2_##t(vx.z, vy.z) }; } \
static inline type##4 atan2_4##t(type##4 vx, type##4 vy) { return (type##4){ atan2_##t(vx.x, vy.x), atan2_##t(vx.y, vy.y), atan2_##t(vx.z, vy.z), atan2_##t(vx.w, vy.w) }; }
declare_atan2(float, f)
declare_atan2(double, d)
#undef declare_atan2

static inline float atanh_f(float x) { return atanhf(x); }
static inline double atanh_d(double x) { return atanh(x); }
#define declare_atanh(type, t) \
static inline type##2 atanh_2##t(type##2 v) { return (type##2){ atanh_##t(v.x), atanh_##t(v.y) }; } \
static inline type##3 atanh_3##t(type##3 v) { return (type##3){ atanh_##t(v.x), atanh_##t(v.y), atanh_##t(v.z) }; } \
static inline type##4 atanh_4##t(type##4 v) { return (type##4){ atanh_##t(v.x), atanh_##t(v.y), atanh_##t(v.z), atanh_##t(v.w) }; }
declare_atanh(float, f)
declare_atanh(double, d)
#undef declare_atanh

static inline float cbrt_f(float x) { return cbrtf(x); }
static inline double cbrt_d(double x) { return cbrt(x); }
#define declare_cbrt(type, t) \
static inline type##2 cbrt_2##t(type##2 v) { return (type##2){ cbrt_##t(v.x), cbrt_##t(v.y) }; } \
static inline type##3 cbrt_3##t(type##3 v) { return (type##3){ cbrt_##t(v.x), cbrt_##t(v.y), cbrt_##t(v.z) }; } \
static inline type##4 cbrt_4##t(type##4 v) { return (type##4){ cbrt_##t(v.x), cbrt_##t(v.y), cbrt_##t(v.z), cbrt_##t(v.w) }; }
declare_cbrt(float, f)
declare_cbrt(double, d)
#undef declare_cbrt

static inline float ceil_f(float x) { return ceilf(x); }
static inline double ceil_d(double x) { return ceil(x); }
#define declare_ceil(type, t) \
static inline type##2 ceil_2##t(type##2 v) { return (type##2){ ceil_##t(v.x), ceil_##t(v.y) }; } \
static inline type##3 ceil_3##t(type##3 v) { return (type##3){ ceil_##t(v.x), ceil_##t(v.y), ceil_##t(v.z) }; } \
static inline type##4 ceil_4##t(type##4 v) { return (type##4){ ceil_##t(v.x), ceil_##t(v.y), ceil_##t(v.z), ceil_##t(v.w) }; }
declare_ceil(float, f)
declare_ceil(double, d)
#undef declare_ceil

static inline float cos_f(float x) { return cosf(x); }
static inline double cos_d(double x) { return cos(x); }
#define declare_cos(type, t) \
static inline type##2 cos_2##t(type##2 v) { return (type##2){ cos_##t(v.x), cos_##t(v.y) }; } \
static inline type##3 cos_3##t(type##3 v) { return (type##3){ cos_##t(v.x), cos_##t(v.y), cos_##t(v.z) }; } \
static inline type##4 cos_4##t(type##4 v) { return (type##4){ cos_##t(v.x), cos_##t(v.y), cos_##t(v.z), cos_##t(v.w) }; }
declare_cos(float, f)
declare_cos(double, d)
#undef declare_cos

static inline float cosh_f(float x) { return coshf(x); }
static inline double cosh_d(double x) { return cosh(x); }
#define declare_cosh(type, t) \
static inline type##2 cosh_2##t(type##2 v) { return (type##2){ cosh_##t(v.x), cosh_##t(v.y) }; } \
static inline type##3 cosh_3##t(type##3 v) { return (type##3){ cosh_##t(v.x), cosh_##t(v.y), cosh_##t(v.z) }; } \
static inline type##4 cosh_4##t(type##4 v) { return (type##4){ cosh_##t(v.x), cosh_##t(v.y), cosh_##t(v.z), cosh_##t(v.w) }; }
declare_cosh(float, f)
declare_cosh(double, d)
#undef declare_cosh

static inline float erfc_f(float x) { return erfcf(x); }
static inline double erfc_d(double x) { return erfc(x); }
#define declare_erfc(type, t) \
static inline type##2 erfc_2##t(type##2 v) { return (type##2){ erfc_##t(v.x), erfc_##t(v.y) }; } \
static inline type##3 erfc_3##t(type##3 v) { return (type##3){ erfc_##t(v.x), erfc_##t(v.y), erfc_##t(v.z) }; } \
static inline type##4 erfc_4##t(type##4 v) { return (type##4){ erfc_##t(v.x), erfc_##t(v.y), erfc_##t(v.z), erfc_##t(v.w) }; }
declare_erfc(float, f)
declare_erfc(double, d)
#undef declare_erfc

static inline float erf_f(float x) { return erff(x); }
static inline double erf_d(double x) { return erf(x); }
#define declare_erf(type, t) \
static inline type##2 erf_2##t(type##2 v) { return (type##2){ erf_##t(v.x), erf_##t(v.y) }; } \
static inline type##3 erf_3##t(type##3 v) { return (type##3){ erf_##t(v.x), erf_##t(v.y), erf_##t(v.z) }; } \
static inline type##4 erf_4##t(type##4 v) { return (type##4){ erf_##t(v.x), erf_##t(v.y), erf_##t(v.z), erf_##t(v.w) }; }
declare_erf(float, f)
declare_erf(double, d)
#undef declare_erf

static inline float exp_f(float x) { return expf(x); }
static inline double exp_d(double x) { return exp(x); }
#define declare_exp(type, t) \
static inline type##2 exp_2##t(type##2 v) { return (type##2){ exp_##t(v.x), exp_##t(v.y) }; } \
static inline type##3 exp_3##t(type##3 v) { return (type##3){ exp_##t(v.x), exp_##t(v.y), exp_##t(v.z) }; } \
static inline type##4 exp_4##t(type##4 v) { return (type##4){ exp_##t(v.x), exp_##t(v.y), exp_##t(v.z), exp_##t(v.w) }; }
declare_exp(float, f)
declare_exp(double, d)
#undef declare_exp

static inline float exp2_f(float x) { return exp2f(x); }
static inline double exp2_d(double x) { return exp2(x); }
#define declare_exp2(type, t) \
static inline type##2 exp2_2##t(type##2 v) { return (type##2){ exp2_##t(v.x), exp2_##t(v.y) }; } \
static inline type##3 exp2_3##t(type##3 v) { return (type##3){ exp2_##t(v.x), exp2_##t(v.y), exp2_##t(v.z) }; } \
static inline type##4 exp2_4##t(type##4 v) { return (type##4){ exp2_##t(v.x), exp2_##t(v.y), exp2_##t(v.z), exp2_##t(v.w) }; }
declare_exp2(float, f)
declare_exp2(double, d)
#undef declare_exp2

static inline float expm1_f(float x) { return expm1f(x); }
static inline double expm1_d(double x) { return expm1(x); }
#define declare_expm1(type, t) \
static inline type##2 expm1_2##t(type##2 v) { return (type##2){ expm1_##t(v.x), expm1_##t(v.y) }; } \
static inline type##3 expm1_3##t(type##3 v) { return (type##3){ expm1_##t(v.x), expm1_##t(v.y), expm1_##t(v.z) }; } \
static inline type##4 expm1_4##t(type##4 v) { return (type##4){ expm1_##t(v.x), expm1_##t(v.y), expm1_##t(v.z), expm1_##t(v.w) }; }
declare_expm1(float, f)
declare_expm1(double, d)
#undef declare_expm1

static inline float dim_f(float x, float y) { return fdimf(x, y); }
static inline double dim_d(double x, double y) { return fdim(x, y); }
#define declare_dim(type, t) \
static inline type##2 dim_2##t(type##2 vx, type##2 vy) { return (type##2){ dim_##t(vx.x, vy.x), dim_##t(vx.y, vy.y) }; } \
static inline type##3 dim_3##t(type##3 vx, type##3 vy) { return (type##3){ dim_##t(vx.x, vy.x), dim_##t(vx.y, vy.y), dim_##t(vx.z, vy.z) }; } \
static inline type##4 dim_4##t(type##4 vx, type##4 vy) { return (type##4){ dim_##t(vx.x, vy.x), dim_##t(vx.y, vy.y), dim_##t(vx.z, vy.z), dim_##t(vx.w, vy.w) }; }
declare_dim(float, f)
declare_dim(double, d)
#undef declare_dim

static inline float floor_f(float x) { return floorf(x); }
static inline double floor_d(double x) { return floor(x); }
#define declare_floor(type, t) \
static inline type##2 floor_2##t(type##2 v) { return (type##2){ floor_##t(v.x), floor_##t(v.y) }; } \
static inline type##3 floor_3##t(type##3 v) { return (type##3){ floor_##t(v.x), floor_##t(v.y), floor_##t(v.z) }; } \
static inline type##4 floor_4##t(type##4 v) { return (type##4){ floor_##t(v.x), floor_##t(v.y), floor_##t(v.z), floor_##t(v.w) }; }
declare_floor(float, f)
declare_floor(double, d)
#undef declare_floor

static inline float hypot_f(float x, float y) { return hypotf(x, y); }
static inline double hypot_d(double x, double y) { return hypot(x, y); }
#define declare_hypot(type, t) \
static inline type##2 hypot_2##t(type##2 vx, type##2 vy) { return (type##2){ hypot_##t(vx.x, vy.x), hypot_##t(vx.y, vy.y) }; } \
static inline type##3 hypot_3##t(type##3 vx, type##3 vy) { return (type##3){ hypot_##t(vx.x, vy.x), hypot_##t(vx.y, vy.y), hypot_##t(vx.z, vy.z) }; } \
static inline type##4 hypot_4##t(type##4 vx, type##4 vy) { return (type##4){ hypot_##t(vx.x, vy.x), hypot_##t(vx.y, vy.y), hypot_##t(vx.z, vy.z), hypot_##t(vx.w, vy.w) }; }
declare_hypot(float, f)
declare_hypot(double, d)
#undef declare_hypot

static inline float lgamma_f(float x) { return lgammaf(x); }
static inline double lgamma_d(double x) { return lgamma(x); }
#define declare_lgamma(type, t) \
static inline type##2 lgamma_2##t(type##2 v) { return (type##2){ lgamma_##t(v.x), lgamma_##t(v.y) }; } \
static inline type##3 lgamma_3##t(type##3 v) { return (type##3){ lgamma_##t(v.x), lgamma_##t(v.y), lgamma_##t(v.z) }; } \
static inline type##4 lgamma_4##t(type##4 v) { return (type##4){ lgamma_##t(v.x), lgamma_##t(v.y), lgamma_##t(v.z), lgamma_##t(v.w) }; }
declare_lgamma(float, f)
declare_lgamma(double, d)
#undef declare_lgamma

static inline float log_f(float x) { return logf(x); }
static inline double log_d(double x) { return log(x); }
#define declare_log(type, t) \
static inline type##2 log_2##t(type##2 v) { return (type##2){ log_##t(v.x), log_##t(v.y) }; } \
static inline type##3 log_3##t(type##3 v) { return (type##3){ log_##t(v.x), log_##t(v.y), log_##t(v.z) }; } \
static inline type##4 log_4##t(type##4 v) { return (type##4){ log_##t(v.x), log_##t(v.y), log_##t(v.z), log_##t(v.w) }; }
declare_log(float, f)
declare_log(double, d)
#undef declare_log

static inline float log2_f(float x) { return log2f(x); }
static inline double log2_d(double x) { return log2(x); }
#define declare_log2(type, t) \
static inline type##2 log2_2##t(type##2 v) { return (type##2){ log2_##t(v.x), log2_##t(v.y) }; } \
static inline type##3 log2_3##t(type##3 v) { return (type##3){ log2_##t(v.x), log2_##t(v.y), log2_##t(v.z) }; } \
static inline type##4 log2_4##t(type##4 v) { return (type##4){ log2_##t(v.x), log2_##t(v.y), log2_##t(v.z), log2_##t(v.w) }; }
declare_log2(float, f)
declare_log2(double, d)
#undef declare_log2

static inline float log10_f(float x) { return log10f(x); }
static inline double log10_d(double x) { return log10(x); }
#define declare_log10(type, t) \
static inline type##2 log10_2##t(type##2 v) { return (type##2){ log10_##t(v.x), log10_##t(v.y) }; } \
static inline type##3 log10_3##t(type##3 v) { return (type##3){ log10_##t(v.x), log10_##t(v.y), log10_##t(v.z) }; } \
static inline type##4 log10_4##t(type##4 v) { return (type##4){ log10_##t(v.x), log10_##t(v.y), log10_##t(v.z), log10_##t(v.w) }; }
declare_log10(float, f)
declare_log10(double, d)
#undef declare_log10

static inline float log1p_f(float x) { return log1pf(x); }
static inline double log1p_d(double x) { return log1p(x); }
#define declare_log1p(type, t) \
static inline type##2 log1p_2##t(type##2 v) { return (type##2){ log1p_##t(v.x), log1p_##t(v.y) }; } \
static inline type##3 log1p_3##t(type##3 v) { return (type##3){ log1p_##t(v.x), log1p_##t(v.y), log1p_##t(v.z) }; } \
static inline type##4 log1p_4##t(type##4 v) { return (type##4){ log1p_##t(v.x), log1p_##t(v.y), log1p_##t(v.z), log1p_##t(v.w) }; }
declare_log1p(float, f)
declare_log1p(double, d)
#undef declare_log1p

static inline float logb_f(float x) { return logbf(x); }
static inline double logb_d(double x) { return logb(x); }
#define declare_logb(type, t) \
static inline type##2 logb_2##t(type##2 v) { return (type##2){ logb_##t(v.x), logb_##t(v.y) }; } \
static inline type##3 logb_3##t(type##3 v) { return (type##3){ logb_##t(v.x), logb_##t(v.y), logb_##t(v.z) }; } \
static inline type##4 logb_4##t(type##4 v) { return (type##4){ logb_##t(v.x), logb_##t(v.y), logb_##t(v.z), logb_##t(v.w) }; }
declare_logb(float, f)
declare_logb(double, d)
#undef declare_logb

static inline float mod_f(float x, float y) { return fmodf(x, y); }
static inline double mod_d(double x, double y) { return fmod(x, y); }
#define declare_mod(type, t) \
static inline type##2 mod_2##t(type##2 vx, type##2 vy) { return (type##2){ mod_##t(vx.x, vy.x), mod_##t(vx.y, vy.y) }; } \
static inline type##3 mod_3##t(type##3 vx, type##3 vy) { return (type##3){ mod_##t(vx.x, vy.x), mod_##t(vx.y, vy.y), mod_##t(vx.z, vy.z) }; } \
static inline type##4 mod_4##t(type##4 vx, type##4 vy) { return (type##4){ mod_##t(vx.x, vy.x), mod_##t(vx.y, vy.y), mod_##t(vx.z, vy.z), mod_##t(vx.w, vy.w) }; }
declare_mod(float, f)
declare_mod(double, d)
#undef declare_mod

static inline float pow_f(float x, float y) { return powf(x, y); }
static inline double pow_d(double x, float y) { return pow(x, y); }
#define declare_pow(type, t) \
static inline type##2 pow_2##t(type##2 v, type y) { return (type##2){ pow_##t(v.x, y), pow_##t(v.y, y) }; } \
static inline type##3 pow_3##t(type##3 v, type y) { return (type##3){ pow_##t(v.x, y), pow_##t(v.y, y), pow_##t(v.z, y) }; } \
static inline type##4 pow_4##t(type##4 v, type y) { return (type##4){ pow_##t(v.x, y), pow_##t(v.y, y), pow_##t(v.z, y), pow_##t(v.w, y) }; }
declare_pow(float, f)
declare_pow(double, d)
#undef declare_pow

static inline float remainder_f(float x, float y) { return remainderf(x, y); }
static inline double remainder_d(double x, float y) { return remainder(x, y); }
#define declare_remainder(type, t) \
static inline type##2 remainder_2##t(type##2 v, type y) { return (type##2){ remainder_##t(v.x, y), remainder_##t(v.y, y) }; } \
static inline type##3 remainder_3##t(type##3 v, type y) { return (type##3){ remainder_##t(v.x, y), remainder_##t(v.y, y), remainder_##t(v.z, y) }; } \
static inline type##4 remainder_4##t(type##4 v, type y) { return (type##4){ remainder_##t(v.x, y), remainder_##t(v.y, y), remainder_##t(v.z, y), remainder_##t(v.w, y) }; }
declare_remainder(float, f)
declare_remainder(double, d)
#undef declare_remainder

static inline float round_f(float x) { return roundf(x); }
static inline double round_d(double x) { return round(x); }
#define declare_round(type, t) \
static inline type##2 round_2##t(type##2 v) { return (type##2){ round_##t(v.x), round_##t(v.y) }; } \
static inline type##3 round_3##t(type##3 v) { return (type##3){ round_##t(v.x), round_##t(v.y), round_##t(v.z) }; } \
static inline type##4 round_4##t(type##4 v) { return (type##4){ round_##t(v.x), round_##t(v.y), round_##t(v.z), round_##t(v.w) }; }
declare_round(float, f)
declare_round(double, d)
#undef declare_round

static inline float sin_f(float x) { return sinf(x); }
static inline double sin_d(double x) { return sin(x); }
#define declare_sin(type, t) \
static inline type##2 sin_2##t(type##2 v) { return (type##2){ sin_##t(v.x), sin_##t(v.y) }; } \
static inline type##3 sin_3##t(type##3 v) { return (type##3){ sin_##t(v.x), sin_##t(v.y), sin_##t(v.z) }; } \
static inline type##4 sin_4##t(type##4 v) { return (type##4){ sin_##t(v.x), sin_##t(v.y), sin_##t(v.z), sin_##t(v.w) }; }
declare_sin(float, f)
declare_sin(double, d)
#undef declare_sin

static inline float sinh_f(float x) { return sinhf(x); }
static inline double sinh_d(double x) { return sinh(x); }
#define declare_sinh(type, t) \
static inline type##2 sinh_2##t(type##2 v) { return (type##2){ sinh_##t(v.x), sinh_##t(v.y) }; } \
static inline type##3 sinh_3##t(type##3 v) { return (type##3){ sinh_##t(v.x), sinh_##t(v.y), sinh_##t(v.z) }; } \
static inline type##4 sinh_4##t(type##4 v) { return (type##4){ sinh_##t(v.x), sinh_##t(v.y), sinh_##t(v.z), sinh_##t(v.w) }; }
declare_sinh(float, f)
declare_sinh(double, d)
#undef declare_sinh

static inline float sqrt_f(float x) { return sqrtf(x); }
static inline double sqrt_d(double x) { return sqrt(x); }
#define declare_sqrt(type, t) \
static inline type##2 sqrt_2##t(type##2 v) { return (type##2){ sqrt_##t(v.x), sqrt_##t(v.y) }; } \
static inline type##3 sqrt_3##t(type##3 v) { return (type##3){ sqrt_##t(v.x), sqrt_##t(v.y), sqrt_##t(v.z) }; } \
static inline type##4 sqrt_4##t(type##4 v) { return (type##4){ sqrt_##t(v.x), sqrt_##t(v.y), sqrt_##t(v.z), sqrt_##t(v.w) }; }
declare_sqrt(float, f)
declare_sqrt(double, d)
#undef declare_sqrt

static inline float tan_f(float x) { return tanf(x); }
static inline double tan_d(double x) { return tan(x); }
#define declare_tan(type, t) \
static inline type##2 tan_2##t(type##2 v) { return (type##2){ tan_##t(v.x), tan_##t(v.y) }; } \
static inline type##3 tan_3##t(type##3 v) { return (type##3){ tan_##t(v.x), tan_##t(v.y), tan_##t(v.z) }; } \
static inline type##4 tan_4##t(type##4 v) { return (type##4){ tan_##t(v.x), tan_##t(v.y), tan_##t(v.z), tan_##t(v.w) }; }
declare_tan(float, f)
declare_tan(double, d)
#undef declare_tan

static inline float tanh_f(float x) { return tanhf(x); }
static inline double tanh_d(double x) { return tanh(x); }
#define declare_tanh(type, t) \
static inline type##2 tanh_2##t(type##2 v) { return (type##2){ tanh_##t(v.x), tanh_##t(v.y) }; } \
static inline type##3 tanh_3##t(type##3 v) { return (type##3){ tanh_##t(v.x), tanh_##t(v.y), tanh_##t(v.z) }; } \
static inline type##4 tanh_4##t(type##4 v) { return (type##4){ tanh_##t(v.x), tanh_##t(v.y), tanh_##t(v.z), tanh_##t(v.w) }; }
declare_tanh(float, f)
declare_tanh(double, d)
#undef declare_tanh

static inline float tgamma_f(float x) { return tgammaf(x); }
static inline double tgamma_d(double x) { return tgamma(x); }
#define declare_tgamma(type, t) \
static inline type##2 tgamma_2##t(type##2 v) { return (type##2){ tgamma_##t(v.x), tgamma_##t(v.y) }; } \
static inline type##3 tgamma_3##t(type##3 v) { return (type##3){ tgamma_##t(v.x), tgamma_##t(v.y), tgamma_##t(v.z) }; } \
static inline type##4 tgamma_4##t(type##4 v) { return (type##4){ tgamma_##t(v.x), tgamma_##t(v.y), tgamma_##t(v.z), tgamma_##t(v.w) }; }
declare_tgamma(float, f)
declare_tgamma(double, d)
#undef declare_tgamma

static inline float trunc_f(float x) { return truncf(x); }
static inline double trunc_d(double x) { return trunc(x); }
#define declare_trunc(type, t) \
static inline type##2 trunc_2##t(type##2 v) { return (type##2){ trunc_##t(v.x), trunc_##t(v.y) }; } \
static inline type##3 trunc_3##t(type##3 v) { return (type##3){ trunc_##t(v.x), trunc_##t(v.y), trunc_##t(v.z) }; } \
static inline type##4 trunc_4##t(type##4 v) { return (type##4){ trunc_##t(v.x), trunc_##t(v.y), trunc_##t(v.z), trunc_##t(v.w) }; }
declare_trunc(float, f)
declare_trunc(double, d)
#undef declare_trunc

#define declare_dot(type, t) \
static inline type dot_2##t(type##2 a, type##2 b) { return a.x * b.x + a.y * b.y; } \
static inline type dot_3##t(type##3 a, type##3 b) { return a.x * b.x + a.y * b.y + a.z * b.z; } \
static inline type dot_4##t(type##4 a, type##4 b) { return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w; }
declare_dot(float, f)
declare_dot(double, d)
#undef declare_dot

#define declare_length(type, t) \
static inline type length_2##t(type##2 v) { return sqrt_##t(dot_2##t(v, v)); } \
static inline type length_3##t(type##3 v) { return sqrt_##t(dot_3##t(v, v)); } \
static inline type length_4##t(type##4 v) { return sqrt_##t(dot_4##t(v, v)); }
declare_length(float, f)
declare_length(double, d)
#undef declare_length

#define declare_sqlength(type, t) \
static inline type sqlength_2##t(type##2 v) { return dot_2##t(v, v); } \
static inline type sqlength_3##t(type##3 v) { return dot_3##t(v, v); } \
static inline type sqlength_4##t(type##4 v) { return dot_4##t(v, v); }
declare_sqlength(float, f)
declare_sqlength(double, d)
#undef declare_sqlength

#define declare_distance(type, t) \
static inline type distance_2##t(type##2 a, type##2 b) { return length_2##t(b - a); } \
static inline type distance_3##t(type##3 a, type##3 b) { return length_3##t(b - a); } \
static inline type distance_4##t(type##4 a, type##4 b) { return length_4##t(b - a); }
declare_distance(float, f)
declare_distance(double, d)
#undef declare_distance

#define declare_sqdistance(type, t) \
static inline type sqdistance_2##t(type##2 a, type##2 b) { return sqlength_2##t(b - a); } \
static inline type sqdistance_3##t(type##3 a, type##3 b) { return sqlength_3##t(b - a); } \
static inline type sqdistance_4##t(type##4 a, type##4 b) { return sqlength_4##t(b - a); }
declare_sqdistance(float, f)
declare_sqdistance(double, d)
#undef declare_sqdistance

#define declare_normalize(type, t) \
static inline type##2 normalize_2##t(type##2 v) { return v / length_2##t(v); } \
static inline type##3 normalize_3##t(type##3 v) { return v / length_3##t(v); } \
static inline type##4 normalize_4##t(type##4 v) { return v / length_4##t(v); }
declare_normalize(float, f)
declare_normalize(double, d)
#undef declare_normalize
