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
static inline type##2 zero2##t() { return (type##2){ 0, 0 }; } \
static inline type##2 one2##t() { return (type##2){ 1, 1 }; } \
static inline type##2 x2##t() { return (type##2){ 1, 0 }; } \
static inline type##2 y2##t() { return (type##2){ 0, 1 }; } \
static inline type##3 zero3##t() { return (type##3){ 0, 0, 0 }; } \
static inline type##3 one3##t() { return (type##3){ 1, 1, 1 }; } \
static inline type##3 x3##t() { return (type##3){ 1, 0, 0 }; } \
static inline type##3 y3##t() { return (type##3){ 0, 1, 0 }; } \
static inline type##3 z3##t() { return (type##3){ 0, 0, 1 }; } \
static inline type##4 zero4##t() { return (type##4){ 0, 0, 0, 0 }; } \
static inline type##4 one4##t() { return (type##4){ 1, 1, 1, 1 }; } \
static inline type##4 x4##t() { return (type##4){ 1, 0, 0, 0 }; } \
static inline type##4 y4##t() { return (type##4){ 0, 1, 0, 0 }; } \
static inline type##4 z4##t() { return (type##4){ 0, 0, 1, 0 }; } \
static inline type##4 w4##t() { return (type##4){ 0, 0, 0, 1 }; }
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
