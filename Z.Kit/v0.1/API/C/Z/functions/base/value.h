/* Z Kit C API - functions/base/value.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_functions_base_value_H__
#define __Z_functions_base_value_H__

#include <Z/macros/value.h>


/* MARK: - Template for natural, integer and real types */


#define Z_TEMPLATE_NATURAL(type)						   \
										   \
										   \
Z_INLINE void z_##type##_swap(void *a, void *b)					   \
	{									   \
	z##type t = *(z##type *)a;						   \
										   \
	*(z##type *)a = *(z##type *)b;						   \
	*(z##type *)b = t;							   \
	}									   \
										   \
										   \
Z_INLINE z##type z_##type##_minimum(z##type a, z##type b)			   \
	{return Z_MINIMUM(a, b);}						   \
										   \
										   \
Z_INLINE z##type z_##type##_maximum(z##type a, z##type b)			   \
	{return Z_MAXIMUM(a, b);}						   \
										   \
										   \
Z_INLINE z##type z_##type##_clamp(z##type value, z##type minimum, z##type maximum) \
	{return z_##type##_minimum(z_##type##_maximum(value, minimum), maximum);}


#define z_type_swap(   TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _swap   )
#define z_type_minimum(TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _minimum)
#define z_type_maximum(TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _maximum)
#define z_type_clamp(  TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _clamp  )


/* MARK: - Template for integer and real types */


#define Z_TEMPLATE_INTEGER(type)				 \
								 \
Z_INLINE z##type z_##type##_absolute(z##type value)		 \
	{return value < (z##type)0 ? -value : value;}		 \
								 \
Z_INLINE z##type z_##type##_sign(z##type value)			 \
	{return value >= (z##type)0 ? (z##type)1 : -(z##type)1;}


#define z_type_absolute(TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _absolute)
#define z_type_sign(	TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _sign	)


/* MARK: - Template for real types only */


#define Z_TEMPLATE_REAL(type, _, epsilon, infinity)				\
										\
										\
Z_INLINE zboolean z_##type##_are_almost_equal(z##type a, z##type b)		\
	{return z_##type##_absolute(a - b) <= epsilon;}				\
										\
										\
Z_INLINE z##type z_##type##_lerp(z##type a, z##type b, z##type t)		\
	{return a + t * (b - a);}						\
										\
										\
Z_INLINE z##type z_##type##_inverse_lerp(z##type a, z##type b, z##type t)	\
	{return (t - a) / (b - a);}						\
										\
										\
Z_INLINE z##type z_##type##_smoothstep(z##type a, z##type b, z##type t)		\
	{									\
	if (t <= a) return _(0.0);						\
	if (t >= b) return _(1.0);						\
	t = (t - a) / (b - a);							\
	return t * t * (_(3.0) - _(2.0) * t);					\
	}									\
										\
										\
Z_INLINE z##type z_##type##_smootherstep(z##type a, z##type b, z##type t)	\
	{									\
	if (t <= a) return _(0.0);						\
	if (t >= b) return _(1.0);						\
	t = (t - a) / (b - a);							\
	return t * t * t * (t * (t * _(6.0) - _(15.0)) + _(10.0));		\
	}									\
										\
										\
Z_INLINE zboolean z_##type##_is_almost_zero(z##type value)			\
	{return z_##type##_absolute(value) <= epsilon;}				\
										\
										\
Z_INLINE zboolean z_##type##_is_finite(z##type value)				\
	{return value == value && value != infinity && value != -infinity;}	\
										\
										\
Z_INLINE zboolean z_##type##_is_infinity(z##type value)				\
	{return value == infinity || value == -infinity;}			\
										\
										\
Z_INLINE zboolean z_##type##_is_nan(z##type value)				\
	{return !(value == value);}						\
										\
										\
Z_INLINE z##type z_##type##_sign_or_zero(z##type value)				\
	{									\
	return z_##type##_absolute(value) <= epsilon				\
		? _(0.0)							\
		: z_##type##_sign(value);					\
	}									\
										\
										\
Z_INLINE z##type z_##type##_clamp_01(z##type value)				\
	{return z_##type##_minimum(z_##type##_maximum(value, _(0.0)), _(1.0));}


#define z_type_are_almost_equal(TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _are_almost_equal)
#define z_type_lerp(		TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _lerp		)
#define z_type_inverse_lerp(	TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _inverse_lerp	)
#define z_type_smoothstep(	TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _smoothstep	)
#define z_type_smootherstep(	TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _smootherstep	)
#define z_type_is_almost_zero(	TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _is_almost_zero	)
#define z_type_is_finite(	TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _is_finite	)
#define z_type_is_infinity(	TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _is_infinity	)
#define z_type_is_nan(		TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _is_nan		)
#define z_type_sign_or_zero(	TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _sign_or_zero	)
#define z_type_clamp_01(	TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _clamp_01	)


/* MARK: - Templates for bit operations */


#define Z_TEMPLATE_VALUE_REVERSED(export, prefix, type, bits, level)  \
export z##type prefix##type##_reversed_in_##level##bit(z##type value) \
	{return Z_##bits##BIT_REVERSED_IN_##level##BIT(value);}


#define z_type_reversed(TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _reversed_in_8bit)


#define Z_TEMPLATE_VALUE_ROTATED(export, prefix, type, bits)		   \
									   \
export z##type prefix##type##_rotated_left(z##type value, zuint rotation)  \
	{return Z_##bits##BIT_ROTATE_LEFT(value, rotation);}		   \
									   \
export z##type prefix##type##_rotated_right(z##type value, zuint rotation) \
	{return Z_##bits##BIT_ROTATE_RIGHT(value, rotation);}


#define z_type_rotated_left( TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _rotated_left )
#define z_type_rotated_right(TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _rotated_right)


/* MARK: - Implementations */


Z_TEMPLATE_NATURAL(uint8)
Z_TEMPLATE_VALUE_REVERSED(Z_INLINE, z_, uint8, 8, 1)
Z_TEMPLATE_VALUE_REVERSED(Z_INLINE, z_, uint8, 8, 2)
Z_TEMPLATE_VALUE_REVERSED(Z_INLINE, z_, uint8, 8, 4)
Z_TEMPLATE_VALUE_ROTATED (Z_INLINE, z_, uint8, 8)

#define z_uint8_reversed Z_SAME

Z_TEMPLATE_NATURAL(uint16)
Z_TEMPLATE_VALUE_REVERSED(Z_INLINE, z_, uint16, 16, 1)
Z_TEMPLATE_VALUE_REVERSED(Z_INLINE, z_, uint16, 16, 2)
Z_TEMPLATE_VALUE_REVERSED(Z_INLINE, z_, uint16, 16, 4)
Z_TEMPLATE_VALUE_REVERSED(Z_INLINE, z_, uint16, 16, 8)
Z_TEMPLATE_VALUE_ROTATED (Z_INLINE, z_, uint16, 16)

#define z_uint16_reversed z_uint16_reversed_in_8bit

Z_TEMPLATE_NATURAL(uint32)
Z_TEMPLATE_VALUE_REVERSED(Z_INLINE, z_, uint32, 32,  1)
Z_TEMPLATE_VALUE_REVERSED(Z_INLINE, z_, uint32, 32,  2)
Z_TEMPLATE_VALUE_REVERSED(Z_INLINE, z_, uint32, 32,  4)
Z_TEMPLATE_VALUE_REVERSED(Z_INLINE, z_, uint32, 32,  8)
Z_TEMPLATE_VALUE_REVERSED(Z_INLINE, z_, uint32, 32, 16)
Z_TEMPLATE_VALUE_ROTATED (Z_INLINE, z_, uint32, 32)

#define z_uint32_reversed z_uint32_reversed_in_8bit

#if Z_IS_AVAILABLE(UINT64)
	Z_TEMPLATE_NATURAL(uint64)
	Z_TEMPLATE_VALUE_REVERSED(Z_INLINE, z_, uint64, 64,  1)
	Z_TEMPLATE_VALUE_REVERSED(Z_INLINE, z_, uint64, 64,  2)
	Z_TEMPLATE_VALUE_REVERSED(Z_INLINE, z_, uint64, 64,  4)
	Z_TEMPLATE_VALUE_REVERSED(Z_INLINE, z_, uint64, 64,  8)
	Z_TEMPLATE_VALUE_REVERSED(Z_INLINE, z_, uint64, 64, 16)
	Z_TEMPLATE_VALUE_REVERSED(Z_INLINE, z_, uint64, 64, 32)
	Z_TEMPLATE_VALUE_ROTATED (Z_INLINE, z_, uint64, 64)

#	define z_uint64_reversed z_uint64_reversed_in_8bit
#endif

#if Z_IS_AVAILABLE(UINT128)
	Z_TEMPLATE_NATURAL(uint128)
	Z_TEMPLATE_VALUE_REVERSED(Z_INLINE, z_, uint128, 128,  1)
	Z_TEMPLATE_VALUE_REVERSED(Z_INLINE, z_, uint128, 128,  2)
	Z_TEMPLATE_VALUE_REVERSED(Z_INLINE, z_, uint128, 128,  4)
	Z_TEMPLATE_VALUE_REVERSED(Z_INLINE, z_, uint128, 128,  8)
	Z_TEMPLATE_VALUE_REVERSED(Z_INLINE, z_, uint128, 128, 16)
	Z_TEMPLATE_VALUE_REVERSED(Z_INLINE, z_, uint128, 128, 32)
	Z_TEMPLATE_VALUE_REVERSED(Z_INLINE, z_, uint128, 128, 64)
	Z_TEMPLATE_VALUE_ROTATED (Z_INLINE, z_, uint128, 128)

#	define z_uint128_reversed z_uint128_reversed_in_8bit
#endif

Z_TEMPLATE_NATURAL(int8)
Z_TEMPLATE_INTEGER(int8)
Z_TEMPLATE_VALUE_REVERSED(Z_INLINE, z_, int8, 8, 1)
Z_TEMPLATE_VALUE_REVERSED(Z_INLINE, z_, int8, 8, 2)
Z_TEMPLATE_VALUE_REVERSED(Z_INLINE, z_, int8, 8, 4)
Z_TEMPLATE_VALUE_ROTATED (Z_INLINE, z_, int8, 8)

#define z_int8_reversed Z_SAME

Z_TEMPLATE_NATURAL(int16)
Z_TEMPLATE_INTEGER(int16)
Z_TEMPLATE_VALUE_REVERSED(Z_INLINE, z_, int16, 16, 1)
Z_TEMPLATE_VALUE_REVERSED(Z_INLINE, z_, int16, 16, 2)
Z_TEMPLATE_VALUE_REVERSED(Z_INLINE, z_, int16, 16, 4)
Z_TEMPLATE_VALUE_REVERSED(Z_INLINE, z_, int16, 16, 8)
Z_TEMPLATE_VALUE_ROTATED (Z_INLINE, z_, int16, 16)

#define z_int16_reversed z_int16_reversed_in_8bit

Z_TEMPLATE_NATURAL(int32)
Z_TEMPLATE_INTEGER(int32)
Z_TEMPLATE_VALUE_REVERSED(Z_INLINE, z_, int32, 32,  1)
Z_TEMPLATE_VALUE_REVERSED(Z_INLINE, z_, int32, 32,  2)
Z_TEMPLATE_VALUE_REVERSED(Z_INLINE, z_, int32, 32,  4)
Z_TEMPLATE_VALUE_REVERSED(Z_INLINE, z_, int32, 32,  8)
Z_TEMPLATE_VALUE_REVERSED(Z_INLINE, z_, int32, 32, 16)
Z_TEMPLATE_VALUE_ROTATED (Z_INLINE, z_, int32, 32)

#define z_int32_reversed z_int32_reversed_in_8bit

#if Z_IS_AVAILABLE(INT64)
	Z_TEMPLATE_NATURAL(int64)
	Z_TEMPLATE_INTEGER(int64)
	Z_TEMPLATE_VALUE_REVERSED(Z_INLINE, z_, int64, 64,  1)
	Z_TEMPLATE_VALUE_REVERSED(Z_INLINE, z_, int64, 64,  2)
	Z_TEMPLATE_VALUE_REVERSED(Z_INLINE, z_, int64, 64,  4)
	Z_TEMPLATE_VALUE_REVERSED(Z_INLINE, z_, int64, 64,  8)
	Z_TEMPLATE_VALUE_REVERSED(Z_INLINE, z_, int64, 64, 16)
	Z_TEMPLATE_VALUE_REVERSED(Z_INLINE, z_, int64, 64, 32)
	Z_TEMPLATE_VALUE_ROTATED (Z_INLINE, z_, int64, 64)

#	define z_int64_reversed z_int64_reversed_in_8bit
#endif

#if Z_IS_AVAILABLE(INT128)
	Z_TEMPLATE_NATURAL(int128)
	Z_TEMPLATE_INTEGER(int128)
	Z_TEMPLATE_VALUE_REVERSED(Z_INLINE, z_, int128, 128,  1)
	Z_TEMPLATE_VALUE_REVERSED(Z_INLINE, z_, int128, 128,  2)
	Z_TEMPLATE_VALUE_REVERSED(Z_INLINE, z_, int128, 128,  4)
	Z_TEMPLATE_VALUE_REVERSED(Z_INLINE, z_, int128, 128,  8)
	Z_TEMPLATE_VALUE_REVERSED(Z_INLINE, z_, int128, 128, 16)
	Z_TEMPLATE_VALUE_REVERSED(Z_INLINE, z_, int128, 128, 32)
	Z_TEMPLATE_VALUE_REVERSED(Z_INLINE, z_, int128, 128, 64)
	Z_TEMPLATE_VALUE_ROTATED (Z_INLINE, z_, int128, 128)

#	define z_int128_reversed z_int128_reversed_in_8bit
#endif

#if Z_IS_AVAILABLE(FLOAT16)
	Z_TEMPLATE_NATURAL(float16)
	Z_TEMPLATE_INTEGER(float16)
	Z_TEMPLATE_REAL(float16, Z_FLOAT16, Z_FLOAT16_EPSILON, Z_FLOAT16_INFINITY)
#endif

#if Z_IS_AVAILABLE(FLOAT24)
	Z_TEMPLATE_NATURAL(float24)
	Z_TEMPLATE_INTEGER(float24)
	Z_TEMPLATE_REAL(float24, Z_FLOAT24, Z_FLOAT24_EPSILON, Z_FLOAT24_INFINITY)
#endif

#if Z_IS_AVAILABLE(FLOAT32)
	Z_TEMPLATE_NATURAL(float32)
	Z_TEMPLATE_INTEGER(float32)
	Z_TEMPLATE_REAL(float32, Z_FLOAT32, Z_FLOAT32_EPSILON, Z_FLOAT32_INFINITY)
#endif

#if Z_IS_AVAILABLE(FLOAT48)
	Z_TEMPLATE_NATURAL(float48)
	Z_TEMPLATE_INTEGER(float48)
	Z_TEMPLATE_REAL(float48, Z_FLOAT48, Z_FLOAT48_EPSILON, Z_FLOAT48_INFINITY)
#endif

#if Z_IS_AVAILABLE(FLOAT64)
	Z_TEMPLATE_NATURAL(float64)
	Z_TEMPLATE_INTEGER(float64)
	Z_TEMPLATE_REAL(float64, Z_FLOAT64, Z_FLOAT64_EPSILON, Z_FLOAT64_INFINITY)
#endif

#if Z_IS_AVAILABLE(FLOAT72)
	Z_TEMPLATE_NATURAL(float72)
	Z_TEMPLATE_INTEGER(float72)
	Z_TEMPLATE_REAL(float72, Z_FLOAT72, Z_FLOAT72_EPSILON, Z_FLOAT72_INFINITY)
#endif

#if Z_IS_AVAILABLE(FLOAT80)
	Z_TEMPLATE_NATURAL(float80)
	Z_TEMPLATE_INTEGER(float80)
	Z_TEMPLATE_REAL(float80, Z_FLOAT80, Z_FLOAT80_EPSILON, Z_FLOAT80_INFINITY)
#endif

#if Z_IS_AVAILABLE(FLOAT96)

	Z_TEMPLATE_NATURAL(float96)
	Z_TEMPLATE_INTEGER(float96)
	Z_TEMPLATE_REAL(float96, Z_FLOAT96, Z_FLOAT96_EPSILON, Z_FLOAT96_INFINITY)

#endif

#if Z_IS_AVAILABLE(FLOAT128)
	Z_TEMPLATE_NATURAL(float128)
	Z_TEMPLATE_INTEGER(float128)
	Z_TEMPLATE_REAL(float128, Z_FLOAT128, Z_FLOAT128_EPSILON, Z_FLOAT128_INFINITY)
#endif


/* MARK: - Default real type definitions */


#define z_are_almost_equal z_type_are_almost_equal(REAL)
#define z_minimum	   z_type_minimum	  (REAL)
#define z_maximum	   z_type_maximum	  (REAL)
#define z_lerp		   z_type_lerp		  (REAL)
#define z_inverse_lerp	   z_type_inverse_lerp	  (REAL)
#define z_smoothstep	   z_type_smoothstep	  (REAL)
#define z_smootherstep	   z_type_smootherstep	  (REAL)
#define z_is_almost_zero   z_type_is_almost_zero  (REAL)
#define z_is_finite	   z_type_is_finite	  (REAL)
#define z_is_infinity	   z_type_is_infinity	  (REAL)
#define z_is_nan	   z_type_is_nan	  (REAL)
#define z_absolute	   z_type_absolute	  (REAL)
#define z_sign		   z_type_sign		  (REAL)
#define z_sign_or_zero	   z_type_sign_or_zero	  (REAL)
#define z_clamp		   z_type_clamp		  (REAL)
#define z_clamp_01	   z_type_clamp_01	  (REAL)


/* MARK: - Endianness conversion */


#if Z_INT16_ENDIANNESS == Z_ENDIANNESS_BIG

#	define z_uint16_big_endian    Z_SAME
#	define z_int16_big_endian     Z_SAME
#	define z_uint16_little_endian z_uint16_reversed
#	define z_int16_little_endian  z_int16_reversed

#elif Z_INT16_ENDIANNESS == Z_ENDIANNESS_LITTLE

#	define z_uint16_big_endian    z_uint16_reversed
#	define z_int16_big_endian     z_int16_reversed
#	define z_uint16_little_endian Z_SAME
#	define z_int16_little_endian  Z_SAME

#endif

#if Z_INT32_ENDIANNESS == Z_ENDIANNESS_BIG

#	define z_uint32_big_endian    Z_SAME
#	define z_int32_big_endian     Z_SAME
#	define z_uint32_little_endian z_uint32_reversed
#	define z_int32_little_endian  z_int32_reversed

#elif Z_INT32_ENDIANNESS == Z_ENDIANNESS_LITTLE

#	define z_uint32_big_endian    z_uint32_reversed
#	define z_int32_big_endian     z_int32_reversed
#	define z_uint32_little_endian Z_SAME
#	define z_int32_little_endian  Z_SAME

#endif

#if Z_IS_AVAILABLE(UINT64)

#	if Z_UINT64_ENDIANNESS == Z_ENDIANNESS_BIG

#		define z_uint64_big_endian    Z_SAME
#		define z_uint64_little_endian z_uint64_reversed

#	elif Z_UINT64_ENDIANNESS == Z_ENDIANNESS_LITTLE

#		define z_uint64_big_endian    z_uint64_reversed
#		define z_uint64_little_endian Z_SAME

#	endif

#endif

#if Z_IS_AVAILABLE(INT64)

#	if Z_INT64_ENDIANNESS == Z_ENDIANNESS_BIG

#		define z_int64_big_endian    Z_SAME
#		define z_int64_little_endian z_int64_reversed

#	elif Z_INT64_ENDIANNESS == Z_ENDIANNESS_LITTLE

#		define z_int64_big_endian    z_int64_reversed
#		define z_int64_little_endian Z_SAME

#	endif

#endif

#if Z_IS_AVAILABLE(UINT128)

#	if Z_UINT128_ENDIANNESS == Z_ENDIANNESS_BIG

#		define z_uint128_big_endian    Z_SAME
#		define z_uint128_little_endian z_uint128_reversed

#	elif Z_UINT128_ENDIANNESS == Z_ENDIANNESS_LITTLE

#		define z_uint128_big_endian    z_uint128_reversed
#		define z_uint128_little_endian Z_SAME

#	endif

#endif

#if Z_IS_AVAILABLE(INT128)

#	if Z_INT128_ENDIANNESS == Z_ENDIANNESS_BIG

#		define z_int128_big_endian     Z_SAME
#		define z_int128_little_endian  z_int128_reversed

#	elif Z_INT128_ENDIANNESS == Z_ENDIANNESS_LITTLE

#		define z_int128_big_endian     z_int128_reversed
#		define z_int128_little_endian  Z_SAME

#	endif

#endif

#define z_type_big_endian(   TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _big_endian	  )
#define z_type_little_endian(TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _little_endian)


/* MARK: - Mirroring */


Z_INLINE zuinttop z_uint8_top_mirror(zuint8 value)
	{return Z_8BIT_TOP_MIRROR(value);}


#if Z_UINTTOP_BITS > 16

	Z_INLINE zuinttop z_uint16_top_mirror(zuint16 value)
		{return Z_16BIT_TOP_MIRROR(value);}

#	if Z_UINTTOP_ENDIANNESS == Z_UINT16_ENDIANNESS

#		define z_uint16_top_packet z_uint16_top_mirror

#	elif	(Z_UINTTOP_ENDIANNESS == Z_ENDIANNESS_BIG     && \
		 Z_UINT16_ENDIANNESS  == Z_ENDIANNESS_LITTLE) || \
		(Z_UINTTOP_ENDIANNESS == Z_ENDIANNESS_LITTLE  && \
		 Z_UINT16_ENDIANNESS  == Z_ENDIANNESS_BIG)

		Z_INLINE zuinttop z_uint16_top_packet(zuint16 value)
			{return Z_16BIT_TOP_MIRROR(z_uint16_reversed(value));}
#	endif
#endif


#if Z_UINTTOP_BITS > 32

	Z_INLINE zuinttop z_uint32_top_mirror(zuint32 value)
		{return Z_32BIT_TOP_MIRROR(value);}

#	if Z_UINTTOP_ENDIANNESS == Z_UINT32_ENDIANNESS

#		define z_uint32_top_packet z_uint32_top_mirror

#	elif	(Z_UINTTOP_ENDIANNESS == Z_ENDIANNESS_BIG     && \
		 Z_UINT32_ENDIANNESS  == Z_ENDIANNESS_LITTLE) || \
		(Z_UINTTOP_ENDIANNESS == Z_ENDIANNESS_LITTLE  && \
		 Z_UINT32_ENDIANNESS  == Z_ENDIANNESS_BIG)

		Z_INLINE zuinttop z_uint32_top_packet(zuint32 value)
			{return Z_32BIT_TOP_MIRROR(z_uint32_reversed(value));}
#	endif
#endif


#if Z_UINTTOP_BITS > 64

	Z_INLINE zuinttop z_uint64_top_mirror(zuint64 value)
		{return Z_64BIT_TOP_MIRROR(value);}

#	if Z_UINTTOP_ENDIANNESS == Z_UINT64_ENDIANNESS

#		define z_uint64_top_packet z_uint64_top_mirror

#	elif	(Z_UINTTOP_ENDIANNESS == Z_ENDIANNESS_BIG     && \
		 Z_UINT64_ENDIANNESS  == Z_ENDIANNESS_LITTLE) || \
		(Z_UINTTOP_ENDIANNESS == Z_ENDIANNESS_LITTLE  && \
		 Z_UINT64_ENDIANNESS  == Z_ENDIANNESS_BIG)

		Z_INLINE zuinttop z_uint64_top_packet(zuint64 value)
			{return Z_64BIT_TOP_MIRROR(z_uint64_reversed(value));}
#	endif
#endif


/* MARK: - Overflow */


Z_INLINE
zboolean z_uint8_addition_overflow(zuint8 a, zuint8 b)
	{return (zuint16)a + (zuint16)b > Z_UINT8_MAXIMUM;}


Z_INLINE
zboolean z_uint8_addition_overflow_3(zuint8 a, zuint8 b, zuint8 c)
	{return (zuint16)a + (zuint16)b + (zuint16)c > Z_UINT8_MAXIMUM;}


Z_INLINE
zboolean z_uint8_addition_overflow_4(zuint8 a, zuint8 b, zuint8 c, zuint8 d)
	{return (zuint16)a + (zuint16)b + (zuint16)c + (zuint16)d > Z_UINT8_MAXIMUM;}


Z_INLINE
zboolean z_uint8_subtraction_overflow(zuint8 a, zuint8 b)
	{return b > a;}


Z_INLINE
zboolean z_uint8_subtraction_overflow_3(zuint8 a, zuint8 b, zuint8 c)
	{return FALSE;}


Z_INLINE
zboolean z_uint8_subtraction_overflow_4(zuint8 a, zuint8 b, zuint8 c, zuint8 d)
	{return FALSE;}


Z_INLINE
zboolean z_uint8_multiplication_overflow(zuint8 a, zuint8 b)
	{return (zuint16)a * (zuint16)b > Z_UINT8_MAXIMUM;}


Z_INLINE
zboolean z_uint8_multiplication_overflow_3(zuint8 a, zuint8 b, zuint8 c)
	{return FALSE;}


Z_INLINE
zboolean z_uint8_multiplication_overflow_4(zuint8 a, zuint8 b, zuint8 c, zuint8 d)
	{return FALSE;}


Z_INLINE
zboolean z_uint16_addition_overflow(zuint16 a, zuint16 b)
	{return (zuint32)a + (zuint32)b > Z_UINT16_MAXIMUM;}


Z_INLINE
zboolean z_uint16_addition_overflow_3(zuint16 a, zuint16 b, zuint16 c)
	{return (zuint32)a + (zuint32)b + (zuint32)c > Z_UINT16_MAXIMUM;}


Z_INLINE
zboolean z_uint16_addition_overflow_4(zuint16 a, zuint16 b, zuint16 c, zuint16 d)
	{return (zuint32)a + (zuint32)b + (zuint32)c + (zuint32)d > Z_UINT16_MAXIMUM;}


Z_INLINE
zboolean z_uint16_subtraction_overflow(zuint16 a, zuint16 b)
	{return b > a;}


Z_INLINE
zboolean z_uint16_subtraction_overflow_3(zuint16 a, zuint16 b, zuint16 c)
	{return FALSE;}


Z_INLINE
zboolean z_uint16_subtraction_overflow_4(zuint16 a, zuint16 b, zuint16 c, zuint16 d)
	{return FALSE;}


Z_INLINE
zboolean z_uint16_multiplication_overflow(zuint16 a, zuint16 b)
	{return (zuint32)a * (zuint32)b > Z_UINT16_MAXIMUM;}


Z_INLINE
zboolean z_uint16_multiplication_overflow_3(zuint16 a, zuint16 b, zuint16 c)
	{return FALSE;}


Z_INLINE
zboolean z_uint16_multiplication_overflow_4(zuint16 a, zuint16 b, zuint16 c, zuint16 d)
	{return FALSE;}


Z_INLINE
zboolean z_uint32_addition_overflow(zuint32 a, zuint32 b)
	{return FALSE;}


Z_INLINE
zboolean z_uint32_addition_overflow_3(zuint32 a, zuint32 b, zuint32 c)
	{return FALSE;}


Z_INLINE
zboolean z_uint32_addition_overflow_4(zuint32 a, zuint32 b, zuint32 c, zuint32 d)
	{return FALSE;}


Z_INLINE
zboolean z_uint32_subtraction_overflow(zuint32 a, zuint32 b)
	{return b > a;}


Z_INLINE
zboolean z_uint32_subtraction_overflow_3(zuint32 a, zuint32 b, zuint32 c)
	{return FALSE;}


Z_INLINE
zboolean z_uint32_subtraction_overflow_4(zuint32 a, zuint32 b, zuint32 c, zuint32 d)
	{return FALSE;}


Z_INLINE
zboolean z_uint32_multiplication_overflow(zuint32 a, zuint32 b)
	{return FALSE;}


Z_INLINE
zboolean z_uint32_multiplication_overflow_3(zuint32 a, zuint32 b, zuint32 c)
	{return FALSE;}


Z_INLINE
zboolean z_uint32_multiplication_overflow_4(zuint32 a, zuint32 b, zuint32 c, zuint32 d)
	{return FALSE;}


#if Z_IS_AVAILABLE(UINT64)

	Z_INLINE
	zboolean z_uint64_addition_overflow(zuint64 a, zuint64 b)
		{return FALSE;}


	Z_INLINE
	zboolean z_uint64_addition_overflow_3(zuint64 a, zuint64 b, zuint64 c)
		{return FALSE;}


	Z_INLINE
	zboolean z_uint64_addition_overflow_4(zuint64 a, zuint64 b, zuint64 c, zuint64 d)
		{return FALSE;}


	Z_INLINE
	zboolean z_uint64_subtraction_overflow(zuint64 a, zuint64 b)
		{return b > a;}


	Z_INLINE
	zboolean z_uint64_subtraction_overflow_3(zuint64 a, zuint64 b, zuint64 c)
		{return FALSE;}


	Z_INLINE
	zboolean z_uint64_subtraction_overflow_4(zuint64 a, zuint64 b, zuint64 c, zuint64 d)
		{return FALSE;}


	Z_INLINE
	zboolean z_uint64_multiplication_overflow(zuint64 a, zuint64 b)
		{return FALSE;}

	Z_INLINE
	zboolean z_uint64_multiplication_overflow_3(zuint64 a, zuint64 b, zuint64 c)
		{return FALSE;}


	Z_INLINE
	zboolean z_uint64_multiplication_overflow_4(zuint64 a, zuint64 b, zuint64 c, zuint64 d)
		{return FALSE;}

#endif


#if Z_IS_AVAILABLE(UINT128)

	Z_INLINE
	zboolean z_uint128_addition_overflow(zuint128 a, zuint128 b)
		{return FALSE;}


	Z_INLINE
	zboolean z_uint128_addition_overflow_3(zuint128 a, zuint128 b, zuint128 c)
		{return FALSE;}


	Z_INLINE
	zboolean z_uint128_addition_overflow_4(zuint128 a, zuint128 b, zuint128 c, zuint128 d)
		{return FALSE;}


	Z_INLINE
	zboolean z_uint128_subtraction_overflow(zuint128 a, zuint128 b)
		{return b > a;}


	Z_INLINE
	zboolean z_uint128_subtraction_overflow_3(zuint128 a, zuint128 b, zuint128 c)
		{return FALSE;}


	Z_INLINE
	zboolean z_uint128_subtraction_overflow_4(zuint128 a, zuint128 b, zuint128 c, zuint128 d)
		{return FALSE;}


	Z_INLINE
	zboolean z_uint128_multiplication_overflow(zuint128 a, zuint128 b)
		{return FALSE;}


	Z_INLINE
	zboolean z_uint128_multiplication_overflow_3(zuint128 a, zuint128 b, zuint128 c)
		{return FALSE;}


	Z_INLINE
	zboolean z_uint128_multiplication_overflow_4(zuint128 a, zuint128 b, zuint128 c, zuint128 d)
		{return FALSE;}

#endif


Z_INLINE
zboolean z_int8_addition_overflow(zint8 a, zint8 b)
	{return FALSE;}


Z_INLINE
zboolean z_int8_addition_overflow_3(zint8 a, zint8 b, zint8 c)
	{return FALSE;}


Z_INLINE
zboolean z_int8_addition_overflow_4(zint8 a, zint8 b, zint8 c, zint8 d)
	{return FALSE;}


Z_INLINE
zboolean z_int8_subtraction_overflow(zint8 a, zint8 b)
	{return FALSE;}


Z_INLINE
zboolean z_int8_subtraction_overflow_3(zint8 a, zint8 b, zint8 c)
	{return FALSE;}


Z_INLINE
zboolean z_int8_subtraction_overflow_4(zint8 a, zint8 b, zint8 c, zint8 d)
	{return FALSE;}


Z_INLINE
zboolean z_int8_multiplication_overflow(zint8 a, zint8 b)
	{return FALSE;}


Z_INLINE
zboolean z_int8_multiplication_overflow_3(zint8 a, zint8 b, zint8 c)
	{return FALSE;}


Z_INLINE
zboolean z_int8_multiplication_overflow_4(zint8 a, zint8 b, zint8 c, zint8 d)
	{return FALSE;}


Z_INLINE
zboolean z_int16_addition_overflow(zint16 a, zint16 b)
	{return FALSE;}


Z_INLINE
zboolean z_int16_addition_overflow_3(zint16 a, zint16 b, zint16 c)
	{return FALSE;}


Z_INLINE
zboolean z_int16_addition_overflow_4(zint16 a, zint16 b, zint16 c, zint16 d)
	{return FALSE;}


Z_INLINE
zboolean z_int16_subtraction_overflow(zint16 a, zint16 b)
	{return FALSE;}


Z_INLINE
zboolean z_int16_subtraction_overflow_3(zint16 a, zint16 b, zint16 c)
	{return FALSE;}


Z_INLINE
zboolean z_int16_subtraction_overflow_4(zint16 a, zint16 b, zint16 c, zint16 d)
	{return FALSE;}


Z_INLINE
zboolean z_int16_multiplication_overflow(zint16 a, zint16 b)
	{return FALSE;}


Z_INLINE
zboolean z_int16_multiplication_overflow_3(zint16 a, zint16 b, zint16 c)
	{return FALSE;}


Z_INLINE
zboolean z_int16_multiplication_overflow_4(zint16 a, zint16 b, zint16 c, zint16 d)
	{return FALSE;}


Z_INLINE
zboolean z_int32_addition_overflow(zint32 a, zint32 b)
	{return FALSE;}


Z_INLINE
zboolean z_int32_addition_overflow_3(zint32 a, zint32 b, zint32 c)
	{return FALSE;}


Z_INLINE
zboolean z_int32_addition_overflow_4(zint32 a, zint32 b, zint32 c, zint32 d)
	{return FALSE;}


Z_INLINE
zboolean z_int32_subtraction_overflow(zint32 a, zint32 b)
	{return FALSE;}


Z_INLINE
zboolean z_int32_subtraction_overflow_3(zint32 a, zint32 b, zint32 c)
	{return FALSE;}


Z_INLINE
zboolean z_int32_subtraction_overflow_4(zint32 a, zint32 b, zint32 c, zint32 d)
	{return FALSE;}


Z_INLINE
zboolean z_int32_multiplication_overflow(zint32 a, zint32 b)
	{return FALSE;}


Z_INLINE
zboolean z_int32_multiplication_overflow_3(zint32 a, zint32 b, zint32 c)
	{return FALSE;}


Z_INLINE
zboolean z_int32_multiplication_overflow_4(zint32 a, zint32 b, zint32 c, zint32 d)
	{return FALSE;}


#if Z_IS_AVAILABLE(INT64)

	Z_INLINE
	zboolean z_int64_addition_overflow(zint64 a, zint64 b)
		{return FALSE;}


	Z_INLINE
	zboolean z_int64_addition_overflow_3(zint64 a, zint64 b, zint64 c)
		{return FALSE;}


	Z_INLINE
	zboolean z_int64_addition_overflow_4(zint64 a, zint64 b, zint64 c, zint64 d)
		{return FALSE;}


	Z_INLINE
	zboolean z_int64_subtraction_overflow(zint64 a, zint64 b)
		{return FALSE;}


	Z_INLINE
	zboolean z_int64_subtraction_overflow_3(zint64 a, zint64 b, zint64 c)
		{return FALSE;}


	Z_INLINE
	zboolean z_int64_subtraction_overflow_4(zint64 a, zint64 b, zint64 c, zint64 d)
		{return FALSE;}


	Z_INLINE
	zboolean z_int64_multiplication_overflow(zint64 a, zint64 b)
		{return FALSE;}


	Z_INLINE
	zboolean z_int64_multiplication_overflow_3(zint64 a, zint64 b, zint64 c)
		{return FALSE;}


	Z_INLINE
	zboolean z_int64_multiplication_overflow_4(zint64 a, zint64 b, zint64 c, zint64 d)
		{return FALSE;}

#endif


#if Z_IS_AVAILABLE(INT128)

	Z_INLINE
	zboolean z_int128_addition_overflow(zint128 a, zint128 b)
		{return FALSE;}


	Z_INLINE
	zboolean z_int128_addition_overflow_3(zint128 a, zint128 b, zint128 c)
		{return FALSE;}


	Z_INLINE
	zboolean z_int128_addition_overflow_4(zint128 a, zint128 b, zint128 c, zint128 d)
		{return FALSE;}


	Z_INLINE
	zboolean z_int128_subtraction_overflow(zint128 a, zint128 b)
		{return FALSE;}


	Z_INLINE
	zboolean z_int128_subtraction_overflow_3(zint128 a, zint128 b, zint128 c)
		{return FALSE;}


	Z_INLINE
	zboolean z_int128_subtraction_overflow_4(zint128 a, zint128 b, zint128 c, zint128 d)
		{return FALSE;}


	Z_INLINE
	zboolean z_int128_multiplication_overflow(zint128 a, zint128 b)
		{return FALSE;}


	Z_INLINE
	zboolean z_int128_multiplication_overflow_3(zint128 a, zint128 b, zint128 c)
		{return FALSE;}


	Z_INLINE
	zboolean z_int128_multiplication_overflow_4(zint128 a, zint128 b, zint128 c, zint128 d)
		{return FALSE;}

#endif


#define z_type_addition_overflow(	 TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _addition_overflow     )
#define z_type_addition_overflow_3(	 TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _addition_overflow_3   )
#define z_type_addition_overflow_4(	 TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _addition_overflow_4   )
#define z_type_subtraction_overflow(	 TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _subtraction_overflow  )
#define z_type_subtraction_overflow_3(	 TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _subtraction_overflow_3)
#define z_type_subtraction_overflow_4(	 TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _subtraction_overflow_4)
#define z_type_multiplication_overflow(	 TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _addition_overflow     )
#define z_type_multiplication_overflow_3(TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _addition_overflow_3   )
#define z_type_multiplication_overflow_4(TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _addition_overflow_4   )


/* MARK: - Binary codified decimal */


Z_INLINE zuint32 z_uint32_to_bcd(zuint32 value)
	{
	zuint32 result = 0;
	zuint	shift  = 0;

	for (; value; value /= 10, shift += 4) result |= (value % 10) << shift;
	return result;
	}


Z_INLINE zuint32 z_bcd_to_uint32(zuint32 value)
	{
	zuint32 result = 0;
	zuint32 scale  = 1;

	for (; value; value >>= 4, scale *= 10) result += (value & 0x0F) * scale;
	return result;
	}


/* MARK: - Atomic operations
.--------------------------------------------------------------------------------------------------.
| z<type> z_<type>_atomic_set_if_equal	    (z<type> *value, z<type> old_value, z<type> new_value) |
| z<type> z_<type>_atomic_get_then_set	    (z<type> *value, z<type> other_value)		   |
| z<type> z_<type>_atomic_get_then_increment(z<type> *value)					   |
| z<type> z_<type>_atomic_get_then_decrement(z<type> *value)					   |
| z<type> z_<type>_atomic_get_then_add	    (z<type> *value, z<type> other_value)		   |
| z<type> z_<type>_atomic_get_then_subtract (z<type> *value, z<type> other_value)		   |
| z<type> z_<type>_atomic_get_then_and	    (z<type> *value, z<type> other_value)		   |
| z<type> z_<type>_atomic_get_then_or	    (z<type> *value, z<type> other_value)		   |
| z<type> z_<type>_atomic_get_then_xor	    (z<type> *value, z<type> other_value)		   |
| z<type> z_<type>_atomic_get_then_nand	    (z<type> *value, z<type> other_value)		   |
| z<type> z_<type>_atomic_get_then_not	    (z<type> *value)					   |
| z<type> z_<type>_atomic_increment_then_get(z<type> *value)					   |
| z<type> z_<type>_atomic_decrement_then_get(z<type> *value)					   |
| z<type> z_<type>_atomic_add_then_get	    (z<type> *value, z<type> other_value)		   |
| z<type> z_<type>_atomic_subtract_then_get (z<type> *value, z<type> other_value)		   |
| z<type> z_<type>_atomic_and_then_get	    (z<type> *value, z<type> other_value)		   |
| z<type> z_<type>_atomic_or_then_get	    (z<type> *value, z<type> other_value)		   |
| z<type> z_<type>_atomic_xor_then_get	    (z<type> *value, z<type> other_value)		   |
| z<type> z_<type>_atomic_nand_then_get	    (z<type> *value, z<type> other_value)		   |
| z<type> z_<type>_atomic_not_then_get	    (z<type> *value)					   |
'-------------------------------------------------------------------------------------------------*/

#if Z_SHOULD_USE_COMPILER_FUNCTION(UINT8_ATOMIC_SET_IF_EQUAL)
#	define z_uint8_atomic_set_if_equal Z_COMPILER_FUNCTION(UINT8_ATOMIC_SET_IF_EQUAL)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(UINT8_ATOMIC_GET_THEN_SET)
#	define z_uint8_atomic_get_then_set Z_COMPILER_FUNCTION(UINT8_ATOMIC_GET_THEN_SET)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(UINT8_ATOMIC_GET_THEN_INCREMENT)
#	define z_uint8_atomic_get_then_increment Z_COMPILER_FUNCTION(UINT8_ATOMIC_GET_THEN_INCREMENT)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(UINT8_ATOMIC_GET_THEN_DECREMENT)
#	define z_uint8_atomic_get_then_decrement Z_COMPILER_FUNCTION(UINT8_ATOMIC_GET_THEN_DECREMENT)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(UINT8_ATOMIC_GET_THEN_ADD)
#	define z_uint8_atomic_get_then_add Z_COMPILER_FUNCTION(UINT8_ATOMIC_GET_THEN_ADD)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(UINT8_ATOMIC_GET_THEN_SUBTRACT)
#	define z_uint8_atomic_get_then_subtract Z_COMPILER_FUNCTION(UINT8_ATOMIC_GET_THEN_SUBTRACT)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(UINT8_ATOMIC_GET_THEN_AND)
#	define z_uint8_atomic_get_then_and Z_COMPILER_FUNCTION(UINT8_ATOMIC_GET_THEN_AND)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(UINT8_ATOMIC_GET_THEN_OR)
#	define z_uint8_atomic_get_then_or Z_COMPILER_FUNCTION(UINT8_ATOMIC_GET_THEN_OR)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(UINT8_ATOMIC_GET_THEN_XOR)
#	define z_uint8_atomic_get_then_xor Z_COMPILER_FUNCTION(UINT8_ATOMIC_GET_THEN_XOR)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(UINT8_ATOMIC_GET_THEN_NAND)
#	define z_uint8_atomic_get_then_nand Z_COMPILER_FUNCTION(UINT8_ATOMIC_GET_THEN_NAND)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(UINT8_ATOMIC_GET_THEN_NOT)
#	define z_uint8_atomic_get_then_not Z_COMPILER_FUNCTION(UINT8_ATOMIC_GET_THEN_NOT)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(UINT8_ATOMIC_INCREMENT_THEN_GET)
#	define z_uint8_atomic_increment_then_get Z_COMPILER_FUNCTION(UINT8_ATOMIC_INCREMENT_THEN_GET)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(UINT8_ATOMIC_DECREMENT_THEN_GET)
#	define z_uint8_atomic_decrement_then_get Z_COMPILER_FUNCTION(UINT8_ATOMIC_DECREMENT_THEN_GET)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(UINT8_ATOMIC_ADD_THEN_GET)
#	define z_uint8_atomic_add_then_get Z_COMPILER_FUNCTION(UINT8_ATOMIC_ADD_THEN_GET)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(UINT8_ATOMIC_SUBTRACT_THEN_GET)
#	define z_uint8_atomic_subtract_then_get Z_COMPILER_FUNCTION(UINT8_ATOMIC_SUBTRACT_THEN_GET)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(UINT8_ATOMIC_AND_THEN_GET)
#	define z_uint8_atomic_and_then_get Z_COMPILER_FUNCTION(UINT8_ATOMIC_AND_THEN_GET)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(UINT8_ATOMIC_OR_THEN_GET)
#	define z_uint8_atomic_or_then_get Z_COMPILER_FUNCTION(UINT8_ATOMIC_OR_THEN_GET)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(UINT8_ATOMIC_XOR_THEN_GET)
#	define z_uint8_atomic_xor_then_get Z_COMPILER_FUNCTION(UINT8_ATOMIC_XOR_THEN_GET)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(UINT8_ATOMIC_NAND_THEN_GET)
#	define z_uint8_atomic_nand_then_get Z_COMPILER_FUNCTION(UINT8_ATOMIC_NAND_THEN_GET)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(UINT8_ATOMIC_NOT_THEN_GET)
#	define z_uint8_atomic_not_then_get Z_COMPILER_FUNCTION(UINT8_ATOMIC_NOT_THEN_GET)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(INT8_ATOMIC_SET_IF_EQUAL)
#	define z_int8_atomic_set_if_equal Z_COMPILER_FUNCTION(INT8_ATOMIC_SET_IF_EQUAL)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(INT8_ATOMIC_GET_THEN_SET)
#	define z_int8_atomic_get_then_set Z_COMPILER_FUNCTION(INT8_ATOMIC_GET_THEN_SET)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(INT8_ATOMIC_GET_THEN_INCREMENT)
#	define z_int8_atomic_get_then_increment Z_COMPILER_FUNCTION(INT8_ATOMIC_GET_THEN_INCREMENT)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(INT8_ATOMIC_GET_THEN_DECREMENT)
#	define z_int8_atomic_get_then_decrement Z_COMPILER_FUNCTION(INT8_ATOMIC_GET_THEN_DECREMENT)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(INT8_ATOMIC_GET_THEN_ADD)
#	define z_int8_atomic_get_then_add Z_COMPILER_FUNCTION(INT8_ATOMIC_GET_THEN_ADD)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(INT8_ATOMIC_GET_THEN_SUBTRACT)
#	define z_int8_atomic_get_then_subtract Z_COMPILER_FUNCTION(INT8_ATOMIC_GET_THEN_SUBTRACT)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(INT8_ATOMIC_GET_THEN_AND)
#	define z_int8_atomic_get_then_and Z_COMPILER_FUNCTION(INT8_ATOMIC_GET_THEN_AND)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(INT8_ATOMIC_GET_THEN_OR)
#	define z_int8_atomic_get_then_or Z_COMPILER_FUNCTION(INT8_ATOMIC_GET_THEN_OR)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(INT8_ATOMIC_GET_THEN_XOR)
#	define z_int8_atomic_get_then_xor Z_COMPILER_FUNCTION(INT8_ATOMIC_GET_THEN_XOR)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(INT8_ATOMIC_GET_THEN_NAND)
#	define z_int8_atomic_get_then_nand Z_COMPILER_FUNCTION(INT8_ATOMIC_GET_THEN_NAND)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(INT8_ATOMIC_GET_THEN_NOT)
#	define z_int8_atomic_get_then_not Z_COMPILER_FUNCTION(INT8_ATOMIC_GET_THEN_NOT)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(INT8_ATOMIC_INCREMENT_THEN_GET)
#	define z_int8_atomic_increment_then_get Z_COMPILER_FUNCTION(INT8_ATOMIC_INCREMENT_THEN_GET)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(INT8_ATOMIC_DECREMENT_THEN_GET)
#	define z_int8_atomic_decrement_then_get Z_COMPILER_FUNCTION(INT8_ATOMIC_DECREMENT_THEN_GET)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(INT8_ATOMIC_ADD_THEN_GET)
#	define z_int8_atomic_add_then_get Z_COMPILER_FUNCTION(INT8_ATOMIC_ADD_THEN_GET)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(INT8_ATOMIC_SUBTRACT_THEN_GET)
#	define z_int8_atomic_subtract_then_get Z_COMPILER_FUNCTION(INT8_ATOMIC_SUBTRACT_THEN_GET)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(INT8_ATOMIC_AND_THEN_GET)
#	define z_int8_atomic_and_then_get Z_COMPILER_FUNCTION(INT8_ATOMIC_AND_THEN_GET)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(INT8_ATOMIC_OR_THEN_GET)
#	define z_int8_atomic_or_then_get Z_COMPILER_FUNCTION(INT8_ATOMIC_OR_THEN_GET)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(INT8_ATOMIC_XOR_THEN_GET)
#	define z_int8_atomic_xor_then_get Z_COMPILER_FUNCTION(INT8_ATOMIC_XOR_THEN_GET)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(INT8_ATOMIC_NAND_THEN_GET)
#	define z_int8_atomic_nand_then_get Z_COMPILER_FUNCTION(INT8_ATOMIC_NAND_THEN_GET)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(INT8_ATOMIC_NOT_THEN_GET)
#	define z_int8_atomic_not_then_get Z_COMPILER_FUNCTION(INT8_ATOMIC_NOT_THEN_GET)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(UINT16_ATOMIC_SET_IF_EQUAL)
#	define z_uint16_atomic_set_if_equal Z_COMPILER_FUNCTION(UINT16_ATOMIC_SET_IF_EQUAL)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(UINT16_ATOMIC_GET_THEN_SET)
#	define z_uint16_atomic_get_then_set Z_COMPILER_FUNCTION(UINT16_ATOMIC_GET_THEN_SET)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(UINT16_ATOMIC_GET_THEN_INCREMENT)
#	define z_uint16_atomic_get_then_increment Z_COMPILER_FUNCTION(UINT16_ATOMIC_GET_THEN_INCREMENT)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(UINT16_ATOMIC_GET_THEN_DECREMENT)
#	define z_uint16_atomic_get_then_decrement Z_COMPILER_FUNCTION(UINT16_ATOMIC_GET_THEN_DECREMENT)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(UINT16_ATOMIC_GET_THEN_ADD)
#	define z_uint16_atomic_get_then_add Z_COMPILER_FUNCTION(UINT16_ATOMIC_GET_THEN_ADD)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(UINT16_ATOMIC_GET_THEN_SUBTRACT)
#	define z_uint16_atomic_get_then_subtract Z_COMPILER_FUNCTION(UINT16_ATOMIC_GET_THEN_SUBTRACT)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(UINT16_ATOMIC_GET_THEN_AND)
#	define z_uint16_atomic_get_then_and Z_COMPILER_FUNCTION(UINT16_ATOMIC_GET_THEN_AND)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(UINT16_ATOMIC_GET_THEN_OR)
#	define z_uint16_atomic_get_then_or Z_COMPILER_FUNCTION(UINT16_ATOMIC_GET_THEN_OR)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(UINT16_ATOMIC_GET_THEN_XOR)
#	define z_uint16_atomic_get_then_xor Z_COMPILER_FUNCTION(UINT16_ATOMIC_GET_THEN_XOR)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(UINT16_ATOMIC_GET_THEN_NAND)
#	define z_uint16_atomic_get_then_nand Z_COMPILER_FUNCTION(UINT16_ATOMIC_GET_THEN_NAND)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(UINT16_ATOMIC_GET_THEN_NOT)
#	define z_uint16_atomic_get_then_not Z_COMPILER_FUNCTION(UINT16_ATOMIC_GET_THEN_NOT)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(UINT16_ATOMIC_INCREMENT_THEN_GET)
#	define z_uint16_atomic_increment_then_get Z_COMPILER_FUNCTION(UINT16_ATOMIC_INCREMENT_THEN_GET)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(UINT16_ATOMIC_DECREMENT_THEN_GET)
#	define z_uint16_atomic_decrement_then_get Z_COMPILER_FUNCTION(UINT16_ATOMIC_DECREMENT_THEN_GET)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(UINT16_ATOMIC_ADD_THEN_GET)
#	define z_uint16_atomic_add_then_get Z_COMPILER_FUNCTION(UINT16_ATOMIC_ADD_THEN_GET)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(UINT16_ATOMIC_SUBTRACT_THEN_GET)
#	define z_uint16_atomic_subtract_then_get Z_COMPILER_FUNCTION(UINT16_ATOMIC_SUBTRACT_THEN_GET)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(UINT16_ATOMIC_AND_THEN_GET)
#	define z_uint16_atomic_and_then_get Z_COMPILER_FUNCTION(UINT16_ATOMIC_AND_THEN_GET)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(UINT16_ATOMIC_OR_THEN_GET)
#	define z_uint16_atomic_or_then_get Z_COMPILER_FUNCTION(UINT16_ATOMIC_OR_THEN_GET)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(UINT16_ATOMIC_XOR_THEN_GET)
#	define z_uint16_atomic_xor_then_get Z_COMPILER_FUNCTION(UINT16_ATOMIC_XOR_THEN_GET)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(UINT16_ATOMIC_NAND_THEN_GET)
#	define z_uint16_atomic_nand_then_get Z_COMPILER_FUNCTION(UINT16_ATOMIC_NAND_THEN_GET)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(UINT16_ATOMIC_NOT_THEN_GET)
#	define z_uint16_atomic_not_then_get Z_COMPILER_FUNCTION(UINT16_ATOMIC_NOT_THEN_GET)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(INT16_ATOMIC_SET_IF_EQUAL)
#	define z_int16_atomic_set_if_equal Z_COMPILER_FUNCTION(INT16_ATOMIC_SET_IF_EQUAL)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(INT16_ATOMIC_GET_THEN_SET)
#	define z_int16_atomic_get_then_set Z_COMPILER_FUNCTION(INT16_ATOMIC_GET_THEN_SET)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(INT16_ATOMIC_GET_THEN_INCREMENT)
#	define z_int16_atomic_get_then_increment Z_COMPILER_FUNCTION(INT16_ATOMIC_GET_THEN_INCREMENT)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(INT16_ATOMIC_GET_THEN_DECREMENT)
#	define z_int16_atomic_get_then_decrement Z_COMPILER_FUNCTION(INT16_ATOMIC_GET_THEN_DECREMENT)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(INT16_ATOMIC_GET_THEN_ADD)
#	define z_int16_atomic_get_then_add Z_COMPILER_FUNCTION(INT16_ATOMIC_GET_THEN_ADD)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(INT16_ATOMIC_GET_THEN_SUBTRACT)
#	define z_int16_atomic_get_then_subtract Z_COMPILER_FUNCTION(INT16_ATOMIC_GET_THEN_SUBTRACT)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(INT16_ATOMIC_GET_THEN_AND)
#	define z_int16_atomic_get_then_and Z_COMPILER_FUNCTION(INT16_ATOMIC_GET_THEN_AND)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(INT16_ATOMIC_GET_THEN_OR)
#	define z_int16_atomic_get_then_or Z_COMPILER_FUNCTION(INT16_ATOMIC_GET_THEN_OR)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(INT16_ATOMIC_GET_THEN_XOR)
#	define z_int16_atomic_get_then_xor Z_COMPILER_FUNCTION(INT16_ATOMIC_GET_THEN_XOR)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(INT16_ATOMIC_GET_THEN_NAND)
#	define z_int16_atomic_get_then_nand Z_COMPILER_FUNCTION(INT16_ATOMIC_GET_THEN_NAND)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(INT16_ATOMIC_GET_THEN_NOT)
#	define z_int16_atomic_get_then_not Z_COMPILER_FUNCTION(INT16_ATOMIC_GET_THEN_NOT)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(INT16_ATOMIC_INCREMENT_THEN_GET)
#	define z_int16_atomic_increment_then_get Z_COMPILER_FUNCTION(INT16_ATOMIC_INCREMENT_THEN_GET)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(INT16_ATOMIC_DECREMENT_THEN_GET)
#	define z_int16_atomic_decrement_then_get Z_COMPILER_FUNCTION(INT16_ATOMIC_DECREMENT_THEN_GET)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(INT16_ATOMIC_ADD_THEN_GET)
#	define z_int16_atomic_add_then_get Z_COMPILER_FUNCTION(INT16_ATOMIC_ADD_THEN_GET)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(INT16_ATOMIC_SUBTRACT_THEN_GET)
#	define z_int16_atomic_subtract_then_get Z_COMPILER_FUNCTION(INT16_ATOMIC_SUBTRACT_THEN_GET)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(INT16_ATOMIC_AND_THEN_GET)
#	define z_int16_atomic_and_then_get Z_COMPILER_FUNCTION(INT16_ATOMIC_AND_THEN_GET)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(INT16_ATOMIC_OR_THEN_GET)
#	define z_int16_atomic_or_then_get Z_COMPILER_FUNCTION(INT16_ATOMIC_OR_THEN_GET)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(INT16_ATOMIC_XOR_THEN_GET)
#	define z_int16_atomic_xor_then_get Z_COMPILER_FUNCTION(INT16_ATOMIC_XOR_THEN_GET)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(INT16_ATOMIC_NAND_THEN_GET)
#	define z_int16_atomic_nand_then_get Z_COMPILER_FUNCTION(INT16_ATOMIC_NAND_THEN_GET)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(INT16_ATOMIC_NOT_THEN_GET)
#	define z_int16_atomic_not_then_get Z_COMPILER_FUNCTION(INT16_ATOMIC_NOT_THEN_GET)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(UINT32_ATOMIC_SET_IF_EQUAL)
#	define z_uint32_atomic_set_if_equal Z_COMPILER_FUNCTION(UINT32_ATOMIC_SET_IF_EQUAL)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(UINT32_ATOMIC_GET_THEN_SET)
#	define z_uint32_atomic_get_then_set Z_COMPILER_FUNCTION(UINT32_ATOMIC_GET_THEN_SET)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(UINT32_ATOMIC_GET_THEN_INCREMENT)
#	define z_uint32_atomic_get_then_increment Z_COMPILER_FUNCTION(UINT32_ATOMIC_GET_THEN_INCREMENT)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(UINT32_ATOMIC_GET_THEN_DECREMENT)
#	define z_uint32_atomic_get_then_decrement Z_COMPILER_FUNCTION(UINT32_ATOMIC_GET_THEN_DECREMENT)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(UINT32_ATOMIC_GET_THEN_ADD)
#	define z_uint32_atomic_get_then_add Z_COMPILER_FUNCTION(UINT32_ATOMIC_GET_THEN_ADD)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(UINT32_ATOMIC_GET_THEN_SUBTRACT)
#	define z_uint32_atomic_get_then_subtract Z_COMPILER_FUNCTION(UINT32_ATOMIC_GET_THEN_SUBTRACT)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(UINT32_ATOMIC_GET_THEN_AND)
#	define z_uint32_atomic_get_then_and Z_COMPILER_FUNCTION(UINT32_ATOMIC_GET_THEN_AND)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(UINT32_ATOMIC_GET_THEN_OR)
#	define z_uint32_atomic_get_then_or Z_COMPILER_FUNCTION(UINT32_ATOMIC_GET_THEN_OR)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(UINT32_ATOMIC_GET_THEN_XOR)
#	define z_uint32_atomic_get_then_xor Z_COMPILER_FUNCTION(UINT32_ATOMIC_GET_THEN_XOR)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(UINT32_ATOMIC_GET_THEN_NAND)
#	define z_uint32_atomic_get_then_nand Z_COMPILER_FUNCTION(UINT32_ATOMIC_GET_THEN_NAND)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(UINT32_ATOMIC_GET_THEN_NOT)
#	define z_uint32_atomic_get_then_not Z_COMPILER_FUNCTION(UINT32_ATOMIC_GET_THEN_NOT)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(UINT32_ATOMIC_INCREMENT_THEN_GET)
#	define z_uint32_atomic_increment_then_get Z_COMPILER_FUNCTION(UINT32_ATOMIC_INCREMENT_THEN_GET)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(UINT32_ATOMIC_DECREMENT_THEN_GET)
#	define z_uint32_atomic_decrement_then_get Z_COMPILER_FUNCTION(UINT32_ATOMIC_DECREMENT_THEN_GET)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(UINT32_ATOMIC_ADD_THEN_GET)
#	define z_uint32_atomic_add_then_get Z_COMPILER_FUNCTION(UINT32_ATOMIC_ADD_THEN_GET)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(UINT32_ATOMIC_SUBTRACT_THEN_GET)
#	define z_uint32_atomic_subtract_then_get Z_COMPILER_FUNCTION(UINT32_ATOMIC_SUBTRACT_THEN_GET)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(UINT32_ATOMIC_AND_THEN_GET)
#	define z_uint32_atomic_and_then_get Z_COMPILER_FUNCTION(UINT32_ATOMIC_AND_THEN_GET)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(UINT32_ATOMIC_OR_THEN_GET)
#	define z_uint32_atomic_or_then_get Z_COMPILER_FUNCTION(UINT32_ATOMIC_OR_THEN_GET)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(UINT32_ATOMIC_XOR_THEN_GET)
#	define z_uint32_atomic_xor_then_get Z_COMPILER_FUNCTION(UINT32_ATOMIC_XOR_THEN_GET)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(UINT32_ATOMIC_NAND_THEN_GET)
#	define z_uint32_atomic_nand_then_get Z_COMPILER_FUNCTION(UINT32_ATOMIC_NAND_THEN_GET)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(UINT32_ATOMIC_NOT_THEN_GET)
#	define z_uint32_atomic_not_then_get Z_COMPILER_FUNCTION(UINT32_ATOMIC_NOT_THEN_GET)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(INT32_ATOMIC_SET_IF_EQUAL)
#	define z_int32_atomic_set_if_equal Z_COMPILER_FUNCTION(INT32_ATOMIC_SET_IF_EQUAL)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(INT32_ATOMIC_GET_THEN_SET)
#	define z_int32_atomic_get_then_set Z_COMPILER_FUNCTION(INT32_ATOMIC_GET_THEN_SET)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(INT32_ATOMIC_GET_THEN_INCREMENT)
#	define z_int32_atomic_get_then_increment Z_COMPILER_FUNCTION(INT32_ATOMIC_GET_THEN_INCREMENT)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(INT32_ATOMIC_GET_THEN_DECREMENT)
#	define z_int32_atomic_get_then_decrement Z_COMPILER_FUNCTION(INT32_ATOMIC_GET_THEN_DECREMENT)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(INT32_ATOMIC_GET_THEN_ADD)
#	define z_int32_atomic_get_then_add Z_COMPILER_FUNCTION(INT32_ATOMIC_GET_THEN_ADD)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(INT32_ATOMIC_GET_THEN_SUBTRACT)
#	define z_int32_atomic_get_then_subtract Z_COMPILER_FUNCTION(INT32_ATOMIC_GET_THEN_SUBTRACT)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(INT32_ATOMIC_GET_THEN_AND)
#	define z_int32_atomic_get_then_and Z_COMPILER_FUNCTION(INT32_ATOMIC_GET_THEN_AND)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(INT32_ATOMIC_GET_THEN_OR)
#	define z_int32_atomic_get_then_or Z_COMPILER_FUNCTION(INT32_ATOMIC_GET_THEN_OR)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(INT32_ATOMIC_GET_THEN_XOR)
#	define z_int32_atomic_get_then_xor Z_COMPILER_FUNCTION(INT32_ATOMIC_GET_THEN_XOR)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(INT32_ATOMIC_GET_THEN_NAND)
#	define z_int32_atomic_get_then_nand Z_COMPILER_FUNCTION(INT32_ATOMIC_GET_THEN_NAND)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(INT32_ATOMIC_GET_THEN_NOT)
#	define z_int32_atomic_get_then_not Z_COMPILER_FUNCTION(INT32_ATOMIC_GET_THEN_NOT)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(INT32_ATOMIC_INCREMENT_THEN_GET)
#	define z_int32_atomic_increment_then_get Z_COMPILER_FUNCTION(INT32_ATOMIC_INCREMENT_THEN_GET)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(INT32_ATOMIC_DECREMENT_THEN_GET)
#	define z_int32_atomic_decrement_then_get Z_COMPILER_FUNCTION(INT32_ATOMIC_DECREMENT_THEN_GET)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(INT32_ATOMIC_ADD_THEN_GET)
#	define z_int32_atomic_add_then_get Z_COMPILER_FUNCTION(INT32_ATOMIC_ADD_THEN_GET)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(INT32_ATOMIC_SUBTRACT_THEN_GET)
#	define z_int32_atomic_subtract_then_get Z_COMPILER_FUNCTION(INT32_ATOMIC_SUBTRACT_THEN_GET)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(INT32_ATOMIC_AND_THEN_GET)
#	define z_int32_atomic_and_then_get Z_COMPILER_FUNCTION(INT32_ATOMIC_AND_THEN_GET)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(INT32_ATOMIC_OR_THEN_GET)
#	define z_int32_atomic_or_then_get Z_COMPILER_FUNCTION(INT32_ATOMIC_OR_THEN_GET)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(INT32_ATOMIC_XOR_THEN_GET)
#	define z_int32_atomic_xor_then_get Z_COMPILER_FUNCTION(INT32_ATOMIC_XOR_THEN_GET)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(INT32_ATOMIC_NAND_THEN_GET)
#	define z_int32_atomic_nand_then_get Z_COMPILER_FUNCTION(INT32_ATOMIC_NAND_THEN_GET)
#endif

#if Z_SHOULD_USE_COMPILER_FUNCTION(INT32_ATOMIC_NOT_THEN_GET)
#	define z_int32_atomic_not_then_get Z_COMPILER_FUNCTION(INT32_ATOMIC_NOT_THEN_GET)
#endif

#if Z_IS_AVAILABLE(UINT64)

#	if Z_SHOULD_USE_COMPILER_FUNCTION(UINT64_ATOMIC_SET_IF_EQUAL)
#		define z_uint64_atomic_set_if_equal Z_COMPILER_FUNCTION(UINT64_ATOMIC_SET_IF_EQUAL)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(UINT64_ATOMIC_GET_THEN_SET)
#		define z_uint64_atomic_get_then_set Z_COMPILER_FUNCTION(UINT64_ATOMIC_GET_THEN_SET)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(UINT64_ATOMIC_GET_THEN_INCREMENT)
#		define z_uint64_atomic_get_then_increment Z_COMPILER_FUNCTION(UINT64_ATOMIC_GET_THEN_INCREMENT)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(UINT64_ATOMIC_GET_THEN_DECREMENT)
#		define z_uint64_atomic_get_then_decrement Z_COMPILER_FUNCTION(UINT64_ATOMIC_GET_THEN_DECREMENT)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(UINT64_ATOMIC_GET_THEN_ADD)
#		define z_uint64_atomic_get_then_add Z_COMPILER_FUNCTION(UINT64_ATOMIC_GET_THEN_ADD)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(UINT64_ATOMIC_GET_THEN_SUBTRACT)
#		define z_uint64_atomic_get_then_subtract Z_COMPILER_FUNCTION(UINT64_ATOMIC_GET_THEN_SUBTRACT)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(UINT64_ATOMIC_GET_THEN_AND)
#		define z_uint64_atomic_get_then_and Z_COMPILER_FUNCTION(UINT64_ATOMIC_GET_THEN_AND)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(UINT64_ATOMIC_GET_THEN_OR)
#		define z_uint64_atomic_get_then_or Z_COMPILER_FUNCTION(UINT64_ATOMIC_GET_THEN_OR)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(UINT64_ATOMIC_GET_THEN_XOR)
#		define z_uint64_atomic_get_then_xor Z_COMPILER_FUNCTION(UINT64_ATOMIC_GET_THEN_XOR)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(UINT64_ATOMIC_GET_THEN_NAND)
#		define z_uint64_atomic_get_then_nand Z_COMPILER_FUNCTION(UINT64_ATOMIC_GET_THEN_NAND)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(UINT64_ATOMIC_GET_THEN_NOT)
#		define z_uint64_atomic_get_then_not Z_COMPILER_FUNCTION(UINT64_ATOMIC_GET_THEN_NOT)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(UINT64_ATOMIC_INCREMENT_THEN_GET)
#		define z_uint64_atomic_increment_then_get Z_COMPILER_FUNCTION(UINT64_ATOMIC_INCREMENT_THEN_GET)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(UINT64_ATOMIC_DECREMENT_THEN_GET)
#		define z_uint64_atomic_decrement_then_get Z_COMPILER_FUNCTION(UINT64_ATOMIC_DECREMENT_THEN_GET)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(UINT64_ATOMIC_ADD_THEN_GET)
#		define z_uint64_atomic_add_then_get Z_COMPILER_FUNCTION(UINT64_ATOMIC_ADD_THEN_GET)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(UINT64_ATOMIC_SUBTRACT_THEN_GET)
#		define z_uint64_atomic_subtract_then_get Z_COMPILER_FUNCTION(UINT64_ATOMIC_SUBTRACT_THEN_GET)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(UINT64_ATOMIC_AND_THEN_GET)
#		define z_uint64_atomic_and_then_get Z_COMPILER_FUNCTION(UINT64_ATOMIC_AND_THEN_GET)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(UINT64_ATOMIC_OR_THEN_GET)
#		define z_uint64_atomic_or_then_get Z_COMPILER_FUNCTION(UINT64_ATOMIC_OR_THEN_GET)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(UINT64_ATOMIC_XOR_THEN_GET)
#		define z_uint64_atomic_xor_then_get Z_COMPILER_FUNCTION(UINT64_ATOMIC_XOR_THEN_GET)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(UINT64_ATOMIC_NAND_THEN_GET)
#		define z_uint64_atomic_nand_then_get Z_COMPILER_FUNCTION(UINT64_ATOMIC_NAND_THEN_GET)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(UINT64_ATOMIC_NOT_THEN_GET)
#		define z_uint64_atomic_not_then_get Z_COMPILER_FUNCTION(UINT64_ATOMIC_NOT_THEN_GET)
#	endif

#endif

#if Z_IS_AVAILABLE(INT64)

#	if Z_SHOULD_USE_COMPILER_FUNCTION(INT64_ATOMIC_SET_IF_EQUAL)
#		define z_int64_atomic_set_if_equal Z_COMPILER_FUNCTION(INT64_ATOMIC_SET_IF_EQUAL)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(INT64_ATOMIC_GET_THEN_SET)
#		define z_int64_atomic_get_then_set Z_COMPILER_FUNCTION(INT64_ATOMIC_GET_THEN_SET)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(INT64_ATOMIC_GET_THEN_INCREMENT)
#		define z_int64_atomic_get_then_increment Z_COMPILER_FUNCTION(INT64_ATOMIC_GET_THEN_INCREMENT)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(INT64_ATOMIC_GET_THEN_DECREMENT)
#		define z_int64_atomic_get_then_decrement Z_COMPILER_FUNCTION(INT64_ATOMIC_GET_THEN_DECREMENT)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(INT64_ATOMIC_GET_THEN_ADD)
#		define z_int64_atomic_get_then_add Z_COMPILER_FUNCTION(INT64_ATOMIC_GET_THEN_ADD)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(INT64_ATOMIC_GET_THEN_SUBTRACT)
#		define z_int64_atomic_get_then_subtract Z_COMPILER_FUNCTION(INT64_ATOMIC_GET_THEN_SUBTRACT)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(INT64_ATOMIC_GET_THEN_AND)
#		define z_int64_atomic_get_then_and Z_COMPILER_FUNCTION(INT64_ATOMIC_GET_THEN_AND)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(INT64_ATOMIC_GET_THEN_OR)
#		define z_int64_atomic_get_then_or Z_COMPILER_FUNCTION(INT64_ATOMIC_GET_THEN_OR)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(INT64_ATOMIC_GET_THEN_XOR)
#		define z_int64_atomic_get_then_xor Z_COMPILER_FUNCTION(INT64_ATOMIC_GET_THEN_XOR)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(INT64_ATOMIC_GET_THEN_NAND)
#		define z_int64_atomic_get_then_nand Z_COMPILER_FUNCTION(INT64_ATOMIC_GET_THEN_NAND)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(INT64_ATOMIC_GET_THEN_NOT)
#		define z_int64_atomic_get_then_not Z_COMPILER_FUNCTION(INT64_ATOMIC_GET_THEN_NOT)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(INT64_ATOMIC_INCREMENT_THEN_GET)
#		define z_int64_atomic_increment_then_get Z_COMPILER_FUNCTION(INT64_ATOMIC_INCREMENT_THEN_GET)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(INT64_ATOMIC_DECREMENT_THEN_GET)
#		define z_int64_atomic_decrement_then_get Z_COMPILER_FUNCTION(INT64_ATOMIC_DECREMENT_THEN_GET)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(INT64_ATOMIC_ADD_THEN_GET)
#		define z_int64_atomic_add_then_get Z_COMPILER_FUNCTION(INT64_ATOMIC_ADD_THEN_GET)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(INT64_ATOMIC_SUBTRACT_THEN_GET)
#		define z_int64_atomic_subtract_then_get Z_COMPILER_FUNCTION(INT64_ATOMIC_SUBTRACT_THEN_GET)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(INT64_ATOMIC_AND_THEN_GET)
#		define z_int64_atomic_and_then_get Z_COMPILER_FUNCTION(INT64_ATOMIC_AND_THEN_GET)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(INT64_ATOMIC_OR_THEN_GET)
#		define z_int64_atomic_or_then_get Z_COMPILER_FUNCTION(INT64_ATOMIC_OR_THEN_GET)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(INT64_ATOMIC_XOR_THEN_GET)
#		define z_int64_atomic_xor_then_get Z_COMPILER_FUNCTION(INT64_ATOMIC_XOR_THEN_GET)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(INT64_ATOMIC_NAND_THEN_GET)
#		define z_int64_atomic_nand_then_get Z_COMPILER_FUNCTION(INT64_ATOMIC_NAND_THEN_GET)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(INT64_ATOMIC_NOT_THEN_GET)
#		define z_int64_atomic_not_then_get Z_COMPILER_FUNCTION(INT64_ATOMIC_NOT_THEN_GET)
#	endif

#endif

#if Z_IS_AVAILABLE(UINT128)

#	if Z_SHOULD_USE_COMPILER_FUNCTION(UINT128_ATOMIC_SET_IF_EQUAL)
#		define z_uint128_atomic_set_if_equal Z_COMPILER_FUNCTION(UINT128_ATOMIC_SET_IF_EQUAL)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(UINT128_ATOMIC_GET_THEN_SET)
#		define z_uint128_atomic_get_then_set Z_COMPILER_FUNCTION(UINT128_ATOMIC_GET_THEN_SET)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(UINT128_ATOMIC_GET_THEN_INCREMENT)
#		define z_uint128_atomic_get_then_increment Z_COMPILER_FUNCTION(UINT128_ATOMIC_GET_THEN_INCREMENT)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(UINT128_ATOMIC_GET_THEN_DECREMENT)
#		define z_uint128_atomic_get_then_decrement Z_COMPILER_FUNCTION(UINT128_ATOMIC_GET_THEN_DECREMENT)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(UINT128_ATOMIC_GET_THEN_ADD)
#		define z_uint128_atomic_get_then_add Z_COMPILER_FUNCTION(UINT128_ATOMIC_GET_THEN_ADD)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(UINT128_ATOMIC_GET_THEN_SUBTRACT)
#		define z_uint128_atomic_get_then_subtract Z_COMPILER_FUNCTION(UINT128_ATOMIC_GET_THEN_SUBTRACT)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(UINT128_ATOMIC_GET_THEN_AND)
#		define z_uint128_atomic_get_then_and Z_COMPILER_FUNCTION(UINT128_ATOMIC_GET_THEN_AND)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(UINT128_ATOMIC_GET_THEN_OR)
#		define z_uint128_atomic_get_then_or Z_COMPILER_FUNCTION(UINT128_ATOMIC_GET_THEN_OR)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(UINT128_ATOMIC_GET_THEN_XOR)
#		define z_uint128_atomic_get_then_xor Z_COMPILER_FUNCTION(UINT128_ATOMIC_GET_THEN_XOR)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(UINT128_ATOMIC_GET_THEN_NAND)
#		define z_uint128_atomic_get_then_nand Z_COMPILER_FUNCTION(UINT128_ATOMIC_GET_THEN_NAND)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(UINT128_ATOMIC_GET_THEN_NOT)
#		define z_uint128_atomic_get_then_not Z_COMPILER_FUNCTION(UINT128_ATOMIC_GET_THEN_NOT)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(UINT128_ATOMIC_INCREMENT_THEN_GET)
#		define z_uint128_atomic_increment_then_get Z_COMPILER_FUNCTION(UINT128_ATOMIC_INCREMENT_THEN_GET)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(UINT128_ATOMIC_DECREMENT_THEN_GET)
#		define z_uint128_atomic_decrement_then_get Z_COMPILER_FUNCTION(UINT128_ATOMIC_DECREMENT_THEN_GET)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(UINT128_ATOMIC_ADD_THEN_GET)
#		define z_uint128_atomic_add_then_get Z_COMPILER_FUNCTION(UINT128_ATOMIC_ADD_THEN_GET)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(UINT128_ATOMIC_SUBTRACT_THEN_GET)
#		define z_uint128_atomic_subtract_then_get Z_COMPILER_FUNCTION(UINT128_ATOMIC_SUBTRACT_THEN_GET)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(UINT128_ATOMIC_AND_THEN_GET)
#		define z_uint128_atomic_and_then_get Z_COMPILER_FUNCTION(UINT128_ATOMIC_AND_THEN_GET)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(UINT128_ATOMIC_OR_THEN_GET)
#		define z_uint128_atomic_or_then_get Z_COMPILER_FUNCTION(UINT128_ATOMIC_OR_THEN_GET)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(UINT128_ATOMIC_XOR_THEN_GET)
#		define z_uint128_atomic_xor_then_get Z_COMPILER_FUNCTION(UINT128_ATOMIC_XOR_THEN_GET)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(UINT128_ATOMIC_NAND_THEN_GET)
#		define z_uint128_atomic_nand_then_get Z_COMPILER_FUNCTION(UINT128_ATOMIC_NAND_THEN_GET)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION()
#		define z_uint128_atomic_not_then_get Z_COMPILER_FUNCTION(UINT128_ATOMIC_NOT_THEN_GET)
#	endif

#endif

#if Z_IS_AVAILABLE(INT128)

#	if Z_SHOULD_USE_COMPILER_FUNCTION(INT128_ATOMIC_SET_IF_EQUAL)
#		define z_int128_atomic_set_if_equal Z_COMPILER_FUNCTION(INT128_ATOMIC_SET_IF_EQUAL)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(INT128_ATOMIC_GET_THEN_SET)
#		define z_int128_atomic_get_then_set Z_COMPILER_FUNCTION(INT128_ATOMIC_GET_THEN_SET)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(INT128_ATOMIC_GET_THEN_INCREMENT)
#		define z_int128_atomic_get_then_increment Z_COMPILER_FUNCTION(INT128_ATOMIC_GET_THEN_INCREMENT)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(INT128_ATOMIC_GET_THEN_DECREMENT)
#		define z_int128_atomic_get_then_decrement Z_COMPILER_FUNCTION(INT128_ATOMIC_GET_THEN_DECREMENT)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(INT128_ATOMIC_GET_THEN_ADD)
#		define z_int128_atomic_get_then_add Z_COMPILER_FUNCTION(INT128_ATOMIC_GET_THEN_ADD)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(INT128_ATOMIC_GET_THEN_SUBTRACT)
#		define z_int128_atomic_get_then_subtract Z_COMPILER_FUNCTION(INT128_ATOMIC_GET_THEN_SUBTRACT)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(INT128_ATOMIC_GET_THEN_AND)
#		define z_int128_atomic_get_then_and Z_COMPILER_FUNCTION(INT128_ATOMIC_GET_THEN_AND)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(INT128_ATOMIC_GET_THEN_OR)
#		define z_int128_atomic_get_then_or Z_COMPILER_FUNCTION(INT128_ATOMIC_GET_THEN_OR)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(INT128_ATOMIC_GET_THEN_XOR)
#		define z_int128_atomic_get_then_xor Z_COMPILER_FUNCTION(INT128_ATOMIC_GET_THEN_XOR)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(INT128_ATOMIC_GET_THEN_NAND)
#		define z_int128_atomic_get_then_nand Z_COMPILER_FUNCTION(INT128_ATOMIC_GET_THEN_NAND)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(INT128_ATOMIC_GET_THEN_NOT)
#		define z_int128_atomic_get_then_not Z_COMPILER_FUNCTION(INT128_ATOMIC_GET_THEN_NOT)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(INT128_ATOMIC_INCREMENT_THEN_GET)
#		define z_int128_atomic_increment_then_get Z_COMPILER_FUNCTION(INT128_ATOMIC_INCREMENT_THEN_GET)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(INT128_ATOMIC_DECREMENT_THEN_GET)
#		define z_int128_atomic_decrement_then_get Z_COMPILER_FUNCTION(INT128_ATOMIC_DECREMENT_THEN_GET)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(INT128_ATOMIC_ADD_THEN_GET)
#		define z_int128_atomic_add_then_get Z_COMPILER_FUNCTION(INT128_ATOMIC_ADD_THEN_GET)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(INT128_ATOMIC_SUBTRACT_THEN_GET)
#		define z_int128_atomic_subtract_then_get Z_COMPILER_FUNCTION(INT128_ATOMIC_SUBTRACT_THEN_GET)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(INT128_ATOMIC_AND_THEN_GET)
#		define z_int128_atomic_and_then_get Z_COMPILER_FUNCTION(INT128_ATOMIC_AND_THEN_GET)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(INT128_ATOMIC_OR_THEN_GET)
#		define z_int128_atomic_or_then_get Z_COMPILER_FUNCTION(INT128_ATOMIC_OR_THEN_GET)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(INT128_ATOMIC_XOR_THEN_GET)
#		define z_int128_atomic_xor_then_get Z_COMPILER_FUNCTION(INT128_ATOMIC_XOR_THEN_GET)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(INT128_ATOMIC_NAND_THEN_GET)
#		define z_int128_atomic_nand_then_get Z_COMPILER_FUNCTION(INT128_ATOMIC_NAND_THEN_GET)
#	endif

#	if Z_SHOULD_USE_COMPILER_FUNCTION(INT128_ATOMIC_NOT_THEN_GET)
#		define z_int128_atomic_not_then_get Z_COMPILER_FUNCTION(INT128_ATOMIC_NOT_THEN_GET)
#	endif

#endif

#define z_type_atomic_set_if_equal(	 TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _atomic_set_if_equal	  )
#define z_type_atomic_get_then_set(	 TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _atomic_get_then_set	  )
#define z_type_atomic_get_then_increment(TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _atomic_get_then_increment)
#define z_type_atomic_get_then_decrement(TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _atomic_get_then_decrement)
#define z_type_atomic_get_then_add(	 TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _atomic_get_then_add	  )
#define z_type_atomic_get_then_subtract( TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _atomic_get_then_subtract )
#define z_type_atomic_get_then_and(	 TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _atomic_get_then_and	  )
#define z_type_atomic_get_then_or(	 TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _atomic_get_then_or	  )
#define z_type_atomic_get_then_xor(	 TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _atomic_get_then_xor	  )
#define z_type_atomic_get_then_nand(	 TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _atomic_get_then_nand	  )
#define z_type_atomic_get_then_not(	 TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _atomic_get_then_not	  )
#define z_type_atomic_increment_then_get(TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _atomic_increment_then_get)
#define z_type_atomic_decrement_then_get(TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _atomic_decrement_then_get)
#define z_type_atomic_add_then_get(	 TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _atomic_add_then_get	  )
#define z_type_atomic_subtract_then_get( TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _atomic_subtract_then_get )
#define z_type_atomic_and_then_get(	 TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _atomic_and_then_get	  )
#define z_type_atomic_or_then_get(	 TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _atomic_or_then_get	  )
#define z_type_atomic_xor_then_get(	 TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _atomic_xor_then_get	  )
#define z_type_atomic_nand_then_get(	 TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _atomic_nand_then_get	  )
#define z_type_atomic_not_then_get(	 TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _atomic_not_then_get	  )


#endif /* __Z_functions_base_value_H__ */
