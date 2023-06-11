/**
 * @file datatypes.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-06-11
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DATATYPES_H_
#define DATATYPES_H_

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <float.h>
#include <limits.h>
#include <time.h>
#include <ctype.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int_fast8_t i8;
typedef int_fast16_t i16;
typedef int_fast32_t i32;
typedef int_fast64_t i64;

typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;

typedef float f32;
typedef double f64;
typedef long double f128;
typedef float float32_t;
typedef double float64_t;
typedef long double float128_t;

typedef bool b8;
typedef bool bool_t;

typedef char c8;
typedef char char_t;

typedef size_t size_t_t;
typedef ptrdiff_t ptrdiff_t_t;
typedef intptr_t intptr_t_t;
typedef uintptr_t uintptr_t_t;

typedef void void_t;
typedef void *void_ptr_t;
typedef void **void_ptr_ptr_t;

typedef char *c8_ptr_t;
typedef char **c8_ptr_ptr_t;

#endif /* DATATYPES_H_ */