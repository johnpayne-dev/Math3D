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

static inline float dot_2f(float2 a, float2 b) { return a.x * b.x + a.y * b.y; }
static inline float dot_3f(float3 a, float3 b) { return a.x * b.x + a.y * b.y + a.z * b.y; }
static inline float dot_4f(float4 a, float4 b) { return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w; }
static inline double dot_2d(double2 a, double2 b) { return a.x * b.x + a.y * b.y; }
static inline double dot_3d(double3 a, double3 b) { return a.x * b.x + a.y * b.y + a.z * b.y; }
static inline double dot_4d(double4 a, double4 b) { return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w; }

static inline float length_2f(float2 v) { return sqrtf(v.x * v.x + v.y * v.y); }
static inline float length_3f(float3 v) { return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z); }
static inline float length_4f(float4 v) { return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w); }
static inline double length_2d(double2 v) { return sqrt(v.x * v.x + v.y * v.y); }
static inline double length_3d(double3 v) { return sqrt(v.x * v.x + v.y * v.y + v.z * v.z); }
static inline double length_4d(double4 v) { return sqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w); }

static inline float2 normalize_2f(float2 v) { return v / length_2f(v); }
static inline float3 normalize_3f(float3 v) { return v / length_3f(v); }
static inline float4 normalize_4f(float4 v) { return v / length_4f(v); }
static inline double2 normalize_2d(double2 v) { return v / length_2d(v); }
static inline double3 normalize_3d(double3 v) { return v / length_3d(v); }
static inline double4 normalize_4d(double4 v) { return v / length_4d(v); }

static inline float3 mod_3f(float3 v, float m) { return (float3){ fmodf(v.x, m), fmodf(v.y, m), fmodf(v.z, m) };}
