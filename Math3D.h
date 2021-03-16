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

static inline float sqrt_f(float x) { return sqrtf(x); }
static inline double sqrt_d(float x) { return sqrt(x); }
#define declare_sqrt(type, t) \
static inline type##2 sqrt_2##t(type##2 v) { return (type##2){ sqrt_##t(v.x), sqrt_##t(v.y) }; } \
static inline type##3 sqrt_3##t(type##3 v) { return (type##3){ sqrt_##t(v.x), sqrt_##t(v.y), sqrt_##t(v.z) }; } \
static inline type##4 sqrt_4##t(type##4 v) { return (type##4){ sqrt_##t(v.x), sqrt_##t(v.y), sqrt_##t(v.z), sqrt_##t(v.w) }; }
declare_sqrt(float, f)
declare_sqrt(double, d)
#undef declare_sqrt

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

static inline float3 mod_3f(float3 v, float m) { return (float3){ fmodf(v.x, m), fmodf(v.y, m), fmodf(v.z, m) };}
