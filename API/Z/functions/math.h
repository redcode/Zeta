/* Zeta API - Z/functions/math.h
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_functions_math_H
#define Z_functions_math_H

#include <Z/macros/math.h>


/* MARK: - Common implementation */

#define Z_z_IMPLEMENTATION_COMMON(type)							\
											\
	static Z_INLINE									\
	z##type z_##type##_maximum(z##type a, z##type b)				\
		{return Z_MAXIMUM(a, b);}						\
											\
											\
	static Z_INLINE									\
	z##type z_##type##_minimum(z##type a, z##type b)				\
		{return Z_MINIMUM(a, b);}						\
											\
											\
	static Z_INLINE									\
	z##type z_##type##_clamp(z##type value, z##type minimum, z##type maximum)	\
		{return z_##type##_minimum(z_##type##_maximum(value, minimum), maximum);}


#define z_T_clamp(  T) Z_INSERT_type(Z_##T##_FIXED_FUNDAMENTAL)(z_, _clamp  )
#define z_T_maximum(T) Z_INSERT_type(Z_##T##_FIXED_FUNDAMENTAL)(z_, _maximum)
#define z_T_minimum(T) Z_INSERT_type(Z_##T##_FIXED_FUNDAMENTAL)(z_, _minimum)


/* MARK: - Partial implementation for signed types */

#define Z_z_IMPLEMENTATION_SIGNED(type)							\
											\
	static Z_INLINE									\
	z##type z_##type##_absolute(z##type value)					\
		{return value < (z##type)0 ? -value : value;}				\
											\
											\
	static Z_INLINE									\
	z##type z_##type##_sign(z##type value)						\
		{return value >= (z##type)0 ? (z##type)1 : -(z##type)1;}


#define z_T_absolute(T) Z_INSERT_type(Z_##TYPE##_FIXED_FUNDAMENTAL(z_, _absolute)
#define z_T_sign(    T) Z_INSERT_type(Z_##TYPE##_FIXED_FUNDAMENTAL(z_, _sign	)


/* MARK: - Implementation for real types */

#define Z_z_IMPLEMENTATION_REAL(type, _, epsilon, infinity)				\
											\
	static Z_INLINE									\
	zboolean z_##type##_are_almost_equal(z##type a, z##type b)			\
		{return z_##type##_absolute(a - b) <= epsilon;}				\
											\
											\
	static Z_INLINE									\
	z##type z_##type##_clamp_01(z##type value)					\
		{return z_##type##_minimum(z_##type##_maximum(value, _(0.0)), _(1.0));}	\
											\
											\
	static Z_INLINE									\
	z##type z_##type##_inverse_lerp(z##type a, z##type b, z##type t)		\
		{return (t - a) / (b - a);}						\
											\
											\
	static Z_INLINE									\
	zboolean z_##type##_is_almost_zero(z##type value)				\
		{return z_##type##_absolute(value) <= epsilon;}				\
											\
											\
	static Z_INLINE									\
	zboolean z_##type##_is_finite(z##type value)					\
		{return value == value && value != infinity && value != -infinity;}	\
											\
											\
	static Z_INLINE									\
	zboolean z_##type##_is_infinity(z##type value)					\
		{return value == infinity || value == -infinity;}			\
											\
											\
	static Z_INLINE									\
	zboolean z_##type##_is_nan(z##type value)					\
		{return !(value == value);}						\
											\
											\
	static Z_INLINE									\
	z##type z_##type##_lerp(z##type a, z##type b, z##type t)			\
		{return a + t * (b - a);}						\
											\
											\
	static Z_INLINE									\
	z##type z_##type##_sign_or_zero(z##type value)					\
		{									\
		return z_##type##_absolute(value) <= epsilon				\
			? _(0.0)							\
			: z_##type##_sign(value);					\
		}									\
											\
											\
	static Z_INLINE									\
	z##type z_##type##_smootherstep(z##type a, z##type b, z##type t)		\
		{									\
		if (t <= a) return _(0.0);						\
		if (t >= b) return _(1.0);						\
		t = (t - a) / (b - a);							\
		return t * t * t * (t * (t * _(6.0) - _(15.0)) + _(10.0));		\
		}									\
											\
											\
	static Z_INLINE									\
	z##type z_##type##_smoothstep(z##type a, z##type b, z##type t)			\
		{									\
		if (t <= a) return _(0.0);						\
		if (t >= b) return _(1.0);						\
		t = (t - a) / (b - a);							\
		return t * t * (_(3.0) - _(2.0) * t);					\
		}


#define z_T_are_almost_equal(T) Z_INSERT_type(Z_##T##_FIXED_FUNDAMENTAL(z_, _are_almost_equal)
#define z_T_clamp_01(	     T) Z_INSERT_type(Z_##T##_FIXED_FUNDAMENTAL(z_, _clamp_01	     )
#define z_T_inverse_lerp(    T) Z_INSERT_type(Z_##T##_FIXED_FUNDAMENTAL(z_, _inverse_lerp    )
#define z_T_is_almost_zero(  T) Z_INSERT_type(Z_##T##_FIXED_FUNDAMENTAL(z_, _is_almost_zero  )
#define z_T_is_finite(	     T) Z_INSERT_type(Z_##T##_FIXED_FUNDAMENTAL(z_, _is_finite	     )
#define z_T_is_infinity(     T) Z_INSERT_type(Z_##T##_FIXED_FUNDAMENTAL(z_, _is_infinity     )
#define z_T_is_nan(	     T) Z_INSERT_type(Z_##T##_FIXED_FUNDAMENTAL(z_, _is_nan	     )
#define z_T_lerp(	     T) Z_INSERT_type(Z_##T##_FIXED_FUNDAMENTAL(z_, _lerp	     )
#define z_T_sign_or_zero(    T) Z_INSERT_type(Z_##T##_FIXED_FUNDAMENTAL(z_, _sign_or_zero    )
#define z_T_smootherstep(    T) Z_INSERT_type(Z_##T##_FIXED_FUNDAMENTAL(z_, _smootherstep    )
#define z_T_smoothstep(	     T) Z_INSERT_type(Z_##T##_FIXED_FUNDAMENTAL(z_, _smoothstep	     )


/* MARK: - uint8 */

Z_z_IMPLEMENTATION_COMMON(uint8)


static Z_INLINE
zboolean z_uint8_addition_overflows(zuint8 a, zuint8 b)
	{return (zuint16)a + (zuint16)b > Z_UINT8_MAXIMUM;}


static Z_INLINE
zboolean z_uint8_addition_overflows_3(zuint8 a, zuint8 b, zuint8 c)
	{return (zuint16)a + (zuint16)b + (zuint16)c > Z_UINT8_MAXIMUM;}


static Z_INLINE
zboolean z_uint8_addition_overflows_4(zuint8 a, zuint8 b, zuint8 c, zuint8 d)
	{return (zuint16)a + (zuint16)b + (zuint16)c + (zuint16)d > Z_UINT8_MAXIMUM;}


static Z_INLINE
zboolean z_uint8_multiplication_overflows(zuint8 a, zuint8 b)
	{return (zuint16)a * (zuint16)b > Z_UINT8_MAXIMUM;}


/*static Z_INLINE
zboolean z_uint8_multiplication_overflows_3(zuint8 a, zuint8 b, zuint8 c)
	{return Z_FALSE;}


static Z_INLINE
zboolean z_uint8_multiplication_overflows_4(zuint8 a, zuint8 b, zuint8 c, zuint8 d)
	{return Z_FALSE;}*/


static Z_INLINE
zboolean z_uint8_subtraction_overflows(zuint8 a, zuint8 b)
	{return b > a;}


/*static Z_INLINE
zboolean z_uint8_subtraction_overflows_3(zuint8 a, zuint8 b, zuint8 c)
	{return Z_FALSE;}


static Z_INLINE
zboolean z_uint8_subtraction_overflows_4(zuint8 a, zuint8 b, zuint8 c, zuint8 d)
	{return Z_FALSE;}*/


/* MARK: - sint8 */

Z_z_IMPLEMENTATION_COMMON(sint8)
Z_z_IMPLEMENTATION_SIGNED(sint8)


/*static Z_INLINE
zboolean z_sint8_addition_overflows(zsint8 a, zsint8 b)
	{return Z_FALSE;}


static Z_INLINE
zboolean z_sint8_addition_overflows_3(zsint8 a, zsint8 b, zsint8 c)
	{return Z_FALSE;}


static Z_INLINE
zboolean z_sint8_addition_overflows_4(zsint8 a, zsint8 b, zsint8 c, zsint8 d)
	{return Z_FALSE;}


static Z_INLINE
zboolean z_sint8_multiplication_overflows(zsint8 a, zsint8 b)
	{return Z_FALSE;}


static Z_INLINE
zboolean z_sint8_multiplication_overflows_3(zsint8 a, zsint8 b, zsint8 c)
	{return Z_FALSE;}


static Z_INLINE
zboolean z_sint8_multiplication_overflows_4(zsint8 a, zsint8 b, zsint8 c, zsint8 d)
	{return Z_FALSE;}


static Z_INLINE
zboolean z_sint8_subtraction_overflows(zsint8 a, zsint8 b)
	{return Z_FALSE;}


static Z_INLINE
zboolean z_sint8_subtraction_overflows_3(zsint8 a, zsint8 b, zsint8 c)
	{return Z_FALSE;}


static Z_INLINE
zboolean z_sint8_subtraction_overflows_4(zsint8 a, zsint8 b, zsint8 c, zsint8 d)
	{return Z_FALSE;}*/


/* MARK: - uint16 */

Z_z_IMPLEMENTATION_COMMON(uint16)


static Z_INLINE
zboolean z_uint16_addition_overflows(zuint16 a, zuint16 b)
	{return (zuint32)a + (zuint32)b > Z_UINT16_MAXIMUM;}


static Z_INLINE
zboolean z_uint16_addition_overflows_3(zuint16 a, zuint16 b, zuint16 c)
	{return (zuint32)a + (zuint32)b + (zuint32)c > Z_UINT16_MAXIMUM;}


static Z_INLINE
zboolean z_uint16_addition_overflows_4(zuint16 a, zuint16 b, zuint16 c, zuint16 d)
	{return (zuint32)a + (zuint32)b + (zuint32)c + (zuint32)d > Z_UINT16_MAXIMUM;}


static Z_INLINE
zboolean z_uint16_multiplication_overflows(zuint16 a, zuint16 b)
	{return (zuint32)a * (zuint32)b > Z_UINT16_MAXIMUM;}


/*static Z_INLINE
zboolean z_uint16_multiplication_overflows_3(zuint16 a, zuint16 b, zuint16 c)
	{return Z_FALSE;}


static Z_INLINE
zboolean z_uint16_multiplication_overflows_4(zuint16 a, zuint16 b, zuint16 c, zuint16 d)
	{return Z_FALSE;}*/


static Z_INLINE
zboolean z_uint16_subtraction_overflows(zuint16 a, zuint16 b)
	{return b > a;}


/*static Z_INLINE
zboolean z_uint16_subtraction_overflows_3(zuint16 a, zuint16 b, zuint16 c)
	{return Z_FALSE;}


static Z_INLINE
zboolean z_uint16_subtraction_overflows_4(zuint16 a, zuint16 b, zuint16 c, zuint16 d)
	{return Z_FALSE;}*/


/* MARK: - sint16 */

Z_z_IMPLEMENTATION_COMMON(sint16)
Z_z_IMPLEMENTATION_SIGNED(sint16)


/*static Z_INLINE
zboolean z_sint16_addition_overflows(zsint16 a, zsint16 b)
	{return Z_FALSE;}


static Z_INLINE
zboolean z_sint16_addition_overflows_3(zsint16 a, zsint16 b, zsint16 c)
	{return Z_FALSE;}


static Z_INLINE
zboolean z_sint16_addition_overflows_4(zsint16 a, zsint16 b, zsint16 c, zsint16 d)
	{return Z_FALSE;}


static Z_INLINE
zboolean z_sint16_multiplication_overflows(zsint16 a, zsint16 b)
	{return Z_FALSE;}


static Z_INLINE
zboolean z_sint16_multiplication_overflows_3(zsint16 a, zsint16 b, zsint16 c)
	{return Z_FALSE;}


static Z_INLINE
zboolean z_sint16_multiplication_overflows_4(zsint16 a, zsint16 b, zsint16 c, zsint16 d)
	{return Z_FALSE;}


static Z_INLINE
zboolean z_sint16_subtraction_overflows(zsint16 a, zsint16 b)
	{return Z_FALSE;}


static Z_INLINE
zboolean z_sint16_subtraction_overflows_3(zsint16 a, zsint16 b, zsint16 c)
	{return Z_FALSE;}


static Z_INLINE
zboolean z_sint16_subtraction_overflows_4(zsint16 a, zsint16 b, zsint16 c, zsint16 d)
	{return Z_FALSE;}*/


/* MARK: - uint32 */

Z_z_IMPLEMENTATION_COMMON(uint32)


/*static Z_INLINE
zboolean z_uint32_addition_overflows(zuint32 a, zuint32 b)
	{return Z_FALSE;}


static Z_INLINE
zboolean z_uint32_addition_overflows_3(zuint32 a, zuint32 b, zuint32 c)
	{return Z_FALSE;}


static Z_INLINE
zboolean z_uint32_addition_overflows_4(zuint32 a, zuint32 b, zuint32 c, zuint32 d)
	{return Z_FALSE;}


static Z_INLINE
zboolean z_uint32_multiplication_overflows(zuint32 a, zuint32 b)
	{return Z_FALSE;}


static Z_INLINE
zboolean z_uint32_multiplication_overflows_3(zuint32 a, zuint32 b, zuint32 c)
	{return Z_FALSE;}


static Z_INLINE
zboolean z_uint32_multiplication_overflows_4(zuint32 a, zuint32 b, zuint32 c, zuint32 d)
	{return Z_FALSE;}


static Z_INLINE
zboolean z_uint32_subtraction_overflows(zuint32 a, zuint32 b)
	{return b > a;}


static Z_INLINE
zboolean z_uint32_subtraction_overflows_3(zuint32 a, zuint32 b, zuint32 c)
	{return Z_FALSE;}


static Z_INLINE
zboolean z_uint32_subtraction_overflows_4(zuint32 a, zuint32 b, zuint32 c, zuint32 d)
	{return Z_FALSE;}*/


/* MARK: - sint32 */

Z_z_IMPLEMENTATION_COMMON(sint32)
Z_z_IMPLEMENTATION_SIGNED(sint32)


/*static Z_INLINE
zboolean z_sint32_addition_overflows(zsint32 a, zsint32 b)
	{return Z_FALSE;}


static Z_INLINE
zboolean z_sint32_addition_overflows_3(zsint32 a, zsint32 b, zsint32 c)
	{return Z_FALSE;}


static Z_INLINE
zboolean z_sint32_addition_overflows_4(zsint32 a, zsint32 b, zsint32 c, zsint32 d)
	{return Z_FALSE;}


static Z_INLINE
zboolean z_sint32_multiplication_overflows(zsint32 a, zsint32 b)
	{return Z_FALSE;}


static Z_INLINE
zboolean z_sint32_multiplication_overflows_3(zsint32 a, zsint32 b, zsint32 c)
	{return Z_FALSE;}


static Z_INLINE
zboolean z_sint32_multiplication_overflows_4(zsint32 a, zsint32 b, zsint32 c, zsint32 d)
	{return Z_FALSE;}


static Z_INLINE
zboolean z_sint32_subtraction_overflows(zsint32 a, zsint32 b)
	{return Z_FALSE;}


static Z_INLINE
zboolean z_sint32_subtraction_overflows_3(zsint32 a, zsint32 b, zsint32 c)
	{return Z_FALSE;}


static Z_INLINE
zboolean z_sint32_subtraction_overflows_4(zsint32 a, zsint32 b, zsint32 c, zsint32 d)
	{return Z_FALSE;}*/


/* MARK: - uint64 */

#ifdef Z_UINT64

	Z_z_IMPLEMENTATION_COMMON(uint64)


	/*static Z_INLINE
	zboolean z_uint64_addition_overflows(zuint64 a, zuint64 b)
		{return Z_FALSE;}


	static Z_INLINE
	zboolean z_uint64_addition_overflows_3(zuint64 a, zuint64 b, zuint64 c)
		{return Z_FALSE;}


	static Z_INLINE
	zboolean z_uint64_addition_overflows_4(zuint64 a, zuint64 b, zuint64 c, zuint64 d)
		{return Z_FALSE;}


	static Z_INLINE
	zboolean z_uint64_multiplication_overflows(zuint64 a, zuint64 b)
		{return Z_FALSE;}

	static Z_INLINE
	zboolean z_uint64_multiplication_overflows_3(zuint64 a, zuint64 b, zuint64 c)
		{return Z_FALSE;}


	static Z_INLINE
	zboolean z_uint64_multiplication_overflows_4(zuint64 a, zuint64 b, zuint64 c, zuint64 d)
		{return Z_FALSE;}


	static Z_INLINE
	zboolean z_uint64_subtraction_overflows(zuint64 a, zuint64 b)
		{return b > a;}


	static Z_INLINE
	zboolean z_uint64_subtraction_overflows_3(zuint64 a, zuint64 b, zuint64 c)
		{return Z_FALSE;}


	static Z_INLINE
	zboolean z_uint64_subtraction_overflows_4(zuint64 a, zuint64 b, zuint64 c, zuint64 d)
		{return Z_FALSE;}*/

#endif


/* MARK: - sint64 */

#ifdef Z_SINT64

	Z_z_IMPLEMENTATION_COMMON(sint64)
	Z_z_IMPLEMENTATION_SIGNED(sint64)


	/*static Z_INLINE
	zboolean z_sint64_addition_overflows(zsint64 a, zsint64 b)
		{return Z_FALSE;}


	static Z_INLINE
	zboolean z_sint64_addition_overflows_3(zsint64 a, zsint64 b, zsint64 c)
		{return Z_FALSE;}


	static Z_INLINE
	zboolean z_sint64_addition_overflows_4(zsint64 a, zsint64 b, zsint64 c, zsint64 d)
		{return Z_FALSE;}


	static Z_INLINE
	zboolean z_sint64_multiplication_overflows(zsint64 a, zsint64 b)
		{return Z_FALSE;}


	static Z_INLINE
	zboolean z_sint64_multiplication_overflows_3(zsint64 a, zsint64 b, zsint64 c)
		{return Z_FALSE;}


	static Z_INLINE
	zboolean z_sint64_multiplication_overflows_4(zsint64 a, zsint64 b, zsint64 c, zsint64 d)
		{return Z_FALSE;}


	static Z_INLINE
	zboolean z_sint64_subtraction_overflows(zsint64 a, zsint64 b)
		{return Z_FALSE;}


	static Z_INLINE
	zboolean z_sint64_subtraction_overflows_3(zsint64 a, zsint64 b, zsint64 c)
		{return Z_FALSE;}


	static Z_INLINE
	zboolean z_sint64_subtraction_overflows_4(zsint64 a, zsint64 b, zsint64 c, zsint64 d)
		{return Z_FALSE;}*/

#endif


/* MARK: - uint128 */

#ifdef Z_UINT128

	Z_z_IMPLEMENTATION_COMMON (uint128)


	/*static Z_INLINE
	zboolean z_uint128_addition_overflows(zuint128 a, zuint128 b)
		{return Z_FALSE;}


	static Z_INLINE
	zboolean z_uint128_addition_overflows_3(zuint128 a, zuint128 b, zuint128 c)
		{return Z_FALSE;}


	static Z_INLINE
	zboolean z_uint128_addition_overflows_4(zuint128 a, zuint128 b, zuint128 c, zuint128 d)
		{return Z_FALSE;}


	static Z_INLINE
	zboolean z_uint128_multiplication_overflows(zuint128 a, zuint128 b)
		{return Z_FALSE;}


	static Z_INLINE
	zboolean z_uint128_multiplication_overflows_3(zuint128 a, zuint128 b, zuint128 c)
		{return Z_FALSE;}


	static Z_INLINE
	zboolean z_uint128_multiplication_overflows_4(zuint128 a, zuint128 b, zuint128 c, zuint128 d)
		{return Z_FALSE;}


	static Z_INLINE
	zboolean z_uint128_subtraction_overflows(zuint128 a, zuint128 b)
		{return b > a;}


	static Z_INLINE
	zboolean z_uint128_subtraction_overflows_3(zuint128 a, zuint128 b, zuint128 c)
		{return Z_FALSE;}


	static Z_INLINE
	zboolean z_uint128_subtraction_overflows_4(zuint128 a, zuint128 b, zuint128 c, zuint128 d)
		{return Z_FALSE;}*/

#endif


/* MARK: - sint128 */

#ifdef Z_SINT128

	Z_z_IMPLEMENTATION_COMMON (sint128)
	Z_z_IMPLEMENTATION_SIGNED (sint128)


	/*static Z_INLINE
	zboolean z_sint128_addition_overflows(zsint128 a, zsint128 b)
		{return Z_FALSE;}


	static Z_INLINE
	zboolean z_sint128_addition_overflows_3(zsint128 a, zsint128 b, zsint128 c)
		{return Z_FALSE;}


	static Z_INLINE
	zboolean z_sint128_addition_overflows_4(zsint128 a, zsint128 b, zsint128 c, zsint128 d)
		{return Z_FALSE;}


	static Z_INLINE
	zboolean z_sint128_multiplication_overflows(zsint128 a, zsint128 b)
		{return Z_FALSE;}


	static Z_INLINE
	zboolean z_sint128_multiplication_overflows_3(zsint128 a, zsint128 b, zsint128 c)
		{return Z_FALSE;}


	static Z_INLINE
	zboolean z_sint128_multiplication_overflows_4(zsint128 a, zsint128 b, zsint128 c, zsint128 d)
		{return Z_FALSE;}


	static Z_INLINE
	zboolean z_sint128_subtraction_overflows(zsint128 a, zsint128 b)
		{return Z_FALSE;}


	static Z_INLINE
	zboolean z_sint128_subtraction_overflows_3(zsint128 a, zsint128 b, zsint128 c)
		{return Z_FALSE;}


	static Z_INLINE
	zboolean z_sint128_subtraction_overflows_4(zsint128 a, zsint128 b, zsint128 c, zsint128 d)
		{return Z_FALSE;}*/

#endif


/* MARK: - float16 */

#ifdef Z_FLOAT16
	Z_z_IMPLEMENTATION_COMMON(float16)
	Z_z_IMPLEMENTATION_SIGNED(float16)
	Z_z_IMPLEMENTATION_REAL	 (float16, Z_FLOAT16, Z_FLOAT16_EPSILON, Z_FLOAT16_INFINITY)
#endif


/* MARK: - float32 */

#ifdef Z_FLOAT32
	Z_z_IMPLEMENTATION_COMMON(float32)
	Z_z_IMPLEMENTATION_SIGNED(float32)
	Z_z_IMPLEMENTATION_REAL	 (float32, Z_FLOAT32, Z_FLOAT32_EPSILON, Z_FLOAT32_INFINITY)
#endif

/* MARK: - float64 */

#ifdef Z_FLOAT64
	Z_z_IMPLEMENTATION_COMMON(float64)
	Z_z_IMPLEMENTATION_SIGNED(float64)
	Z_z_IMPLEMENTATION_REAL	 (float64, Z_FLOAT64, Z_FLOAT64_EPSILON, Z_FLOAT64_INFINITY)
#endif


/* MARK: - float128 */

#ifdef Z_FLOAT128
	Z_z_IMPLEMENTATION_COMMON(float128)
	Z_z_IMPLEMENTATION_SIGNED(float128)
	Z_z_IMPLEMENTATION_REAL	 (float128, Z_FLOAT128, Z_FLOAT128_EPSILON, Z_FLOAT128_INFINITY)
#endif


/* MARK: - float80_x87 */

#ifdef Z_FLOAT80_X87
	Z_z_IMPLEMENTATION_COMMON(float80_x87)
	Z_z_IMPLEMENTATION_SIGNED(float80_x87)
	Z_z_IMPLEMENTATION_REAL	 (float80_x87, Z_FLOAT80_X87, Z_FLOAT80_X87_EPSILON, Z_FLOAT80_X87_INFINITY)
#endif


/* MARK: - float96_x87 */

#ifdef Z_FLOAT96_X87
	Z_z_IMPLEMENTATION_COMMON(float96_x87)
	Z_z_IMPLEMENTATION_SIGNED(float96_x87)
	Z_z_IMPLEMENTATION_REAL	 (float96_x87, Z_FLOAT96_X87, Z_FLOAT96_X87_EPSILON, Z_FLOAT96_X87_INFINITY)
#endif


/* MARK: - float128_x87 */

#ifdef Z_FLOAT128_X87
	Z_z_IMPLEMENTATION_COMMON(float128_x87)
	Z_z_IMPLEMENTATION_SIGNED(float128_x87)
	Z_z_IMPLEMENTATION_REAL	 (float128_x87, Z_FLOAT128_X87, Z_FLOAT128_X87_EPSILON, Z_FLOAT128_X87_INFINITY)
#endif


/* MARK: - Cleanup */

#undef Z_z_IMPLEMENTATION_COMMON
#undef Z_z_IMPLEMENTATION_SIGNED
#undef Z_z_IMPLEMENTATION_REAL


/* MARK: - Function selectors */


#define z_T_addition_overflows(	       TYPE) Z_INSERT_##T##_fixed_type(z_, _addition_overflows     )
#define z_T_addition_overflows_3(      TYPE) Z_INSERT_##T##_fixed_type(z_, _addition_overflows_3   )
#define z_T_addition_overflows_4(      TYPE) Z_INSERT_##T##_fixed_type(z_, _addition_overflows_4   )
#define z_T_multiplication_overflows(  TYPE) Z_INSERT_##T##_fixed_type(z_, _addition_overflows     )
#define z_T_multiplication_overflows_3(TYPE) Z_INSERT_##T##_fixed_type(z_, _addition_overflows_3   )
#define z_T_multiplication_overflows_4(TYPE) Z_INSERT_##T##_fixed_type(z_, _addition_overflows_4   )
#define z_T_subtraction_overflows(     TYPE) Z_INSERT_##T##_fixed_type(z_, _subtraction_overflows  )
#define z_T_subtraction_overflows_3(   TYPE) Z_INSERT_##T##_fixed_type(z_, _subtraction_overflows_3)
#define z_T_subtraction_overflows_4(   TYPE) Z_INSERT_##T##_fixed_type(z_, _subtraction_overflows_4)


/* MARK: - Default real type definitions */

#ifdef Z_REAL
#	define z_absolute	  z_T_absolute	      (REAL)
#	define z_are_almost_equal z_T_are_almost_equal(REAL)
#	define z_clamp		  z_T_clamp	      (REAL)
#	define z_clamp_01	  z_T_clamp_01	      (REAL)
#	define z_inverse_lerp	  z_T_inverse_lerp    (REAL)
#	define z_is_almost_zero	  z_T_is_almost_zero  (REAL)
#	define z_is_finite	  z_T_is_finite	      (REAL)
#	define z_is_infinity	  z_T_is_infinity     (REAL)
#	define z_is_nan		  z_T_is_nan	      (REAL)
#	define z_lerp		  z_T_lerp	      (REAL)
#	define z_maximum	  z_T_maximum	      (REAL)
#	define z_minimum	  z_T_minimum	      (REAL)
#	define z_sign		  z_T_sign	      (REAL)
#	define z_sign_or_zero	  z_T_sign_or_zero    (REAL)
#	define z_smootherstep	  z_T_smootherstep    (REAL)
#	define z_smoothstep	  z_T_smoothstep      (REAL)
#endif


#endif /* Z_functions_math_H */
