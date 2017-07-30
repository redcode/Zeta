/* Z Kit C API - functions/base/value.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2017 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_functions_base_value_H__
#define __Z_functions_base_value_H__

#include <Z/macros/value.h>


/* MARK: - Implementation for natural, integer and real types */


#define Z_IMPLEMENTATION_NATURAL(type)						   \
										   \
										   \
Z_INLINE z##type z_##type##_maximum(z##type a, z##type b)			   \
	{return Z_MAXIMUM(a, b);}						   \
										   \
										   \
Z_INLINE z##type z_##type##_minimum(z##type a, z##type b)			   \
	{return Z_MINIMUM(a, b);}						   \
										   \
										   \
Z_INLINE z##type z_##type##_clamp(z##type value, z##type minimum, z##type maximum) \
	{return z_##type##_minimum(z_##type##_maximum(value, minimum), maximum);}  \
										   \
										   \
Z_INLINE void z_##type##_swap(void *a, void *b)					   \
	{									   \
	z##type t = *(z##type *)a;						   \
										   \
	*(z##type *)a = *(z##type *)b;						   \
	*(z##type *)b = t;							   \
	}


#define z_type_clamp(  TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _clamp  )
#define z_type_maximum(TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _maximum)
#define z_type_minimum(TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _minimum)
#define z_type_swap(   TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _swap   )


/* MARK: - Implementation for integer and real types */


#define Z_IMPLEMENTATION_INTEGER(type)				 \
								 \
Z_INLINE z##type z_##type##_absolute(z##type value)		 \
	{return value < (z##type)0 ? -value : value;}		 \
								 \
Z_INLINE z##type z_##type##_sign(z##type value)			 \
	{return value >= (z##type)0 ? (z##type)1 : -(z##type)1;}


#define z_type_absolute(TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _absolute)
#define z_type_sign(	TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _sign	)


/* MARK: - Implementation for real types only */


#define Z_IMPLEMENTATION_REAL(type, _, epsilon, infinity)			\
										\
										\
Z_INLINE zboolean z_##type##_are_almost_equal(z##type a, z##type b)		\
	{return z_##type##_absolute(a - b) <= epsilon;}				\
										\
										\
Z_INLINE z##type z_##type##_clamp_01(z##type value)				\
	{return z_##type##_minimum(z_##type##_maximum(value, _(0.0)), _(1.0));}	\
										\
										\
Z_INLINE z##type z_##type##_inverse_lerp(z##type a, z##type b, z##type t)	\
	{return (t - a) / (b - a);}						\
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
Z_INLINE z##type z_##type##_lerp(z##type a, z##type b, z##type t)		\
	{return a + t * (b - a);}						\
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
Z_INLINE z##type z_##type##_smootherstep(z##type a, z##type b, z##type t)	\
	{									\
	if (t <= a) return _(0.0);						\
	if (t >= b) return _(1.0);						\
	t = (t - a) / (b - a);							\
	return t * t * t * (t * (t * _(6.0) - _(15.0)) + _(10.0));		\
	}									\
										\
										\
Z_INLINE z##type z_##type##_smoothstep(z##type a, z##type b, z##type t)		\
	{									\
	if (t <= a) return _(0.0);						\
	if (t >= b) return _(1.0);						\
	t = (t - a) / (b - a);							\
	return t * t * (_(3.0) - _(2.0) * t);					\
	}


#define z_type_are_almost_equal(TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _are_almost_equal)
#define z_type_clamp_01(	TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _clamp_01	)
#define z_type_inverse_lerp(	TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _inverse_lerp	)
#define z_type_is_almost_zero(	TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _is_almost_zero	)
#define z_type_is_finite(	TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _is_finite	)
#define z_type_is_infinity(	TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _is_infinity	)
#define z_type_is_nan(		TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _is_nan		)
#define z_type_lerp(		TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _lerp		)
#define z_type_sign_or_zero(	TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _sign_or_zero	)
#define z_type_smootherstep(	TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _smootherstep	)
#define z_type_smoothstep(	TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _smoothstep	)


/* MARK: - Implementations for bit operations */


#define Z_IMPLEMENTATION_VALUE_REVERSE(type, bits, level)	   \
Z_INLINE z##type z_##type##_reverse_in_##level##bit(z##type value) \
	{return Z_##bits##BIT_REVERSE_IN_##level##BIT(value);}


#define z_type_reverse(TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _reverse_in_8bit)


#define Z_IMPLEMENTATION_VALUE_ROTATE(type, bits)			\
									\
Z_INLINE z##type z_##type##_rotate_left(z##type value, zuint rotation)	\
	{return Z_##bits##BIT_ROTATE_LEFT(value, rotation);}		\
									\
Z_INLINE z##type z_##type##_rotate_right(z##type value, zuint rotation)	\
	{return Z_##bits##BIT_ROTATE_RIGHT(value, rotation);}


#define z_type_rotate_left( TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _rotate_left )
#define z_type_rotate_right(TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _rotate_right)


/* MARK: - uint8 */


Z_IMPLEMENTATION_NATURAL      (uint8)
Z_IMPLEMENTATION_VALUE_REVERSE(uint8, 8, 1)
Z_IMPLEMENTATION_VALUE_REVERSE(uint8, 8, 2)
Z_IMPLEMENTATION_VALUE_REVERSE(uint8, 8, 4)
Z_IMPLEMENTATION_VALUE_ROTATE (uint8, 8)


#define z_uint8_reverse Z_SAME


Z_INLINE zboolean z_uint8_addition_overflows(zuint8 a, zuint8 b)
	{return (zuint16)a + (zuint16)b > Z_UINT8_MAXIMUM;}


Z_INLINE zboolean z_uint8_addition_overflows_3(zuint8 a, zuint8 b, zuint8 c)
	{return (zuint16)a + (zuint16)b + (zuint16)c > Z_UINT8_MAXIMUM;}


Z_INLINE zboolean z_uint8_addition_overflows_4(zuint8 a, zuint8 b, zuint8 c, zuint8 d)
	{return (zuint16)a + (zuint16)b + (zuint16)c + (zuint16)d > Z_UINT8_MAXIMUM;}


Z_INLINE zboolean z_uint8_multiplication_overflows(zuint8 a, zuint8 b)
	{return (zuint16)a * (zuint16)b > Z_UINT8_MAXIMUM;}


Z_INLINE zboolean z_uint8_multiplication_overflows_3(zuint8 a, zuint8 b, zuint8 c)
	{return FALSE;}


Z_INLINE zboolean z_uint8_multiplication_overflows_4(zuint8 a, zuint8 b, zuint8 c, zuint8 d)
	{return FALSE;}


Z_INLINE zboolean z_uint8_subtraction_overflows(zuint8 a, zuint8 b)
	{return b > a;}


Z_INLINE zboolean z_uint8_subtraction_overflows_3(zuint8 a, zuint8 b, zuint8 c)
	{return FALSE;}


Z_INLINE zboolean z_uint8_subtraction_overflows_4(zuint8 a, zuint8 b, zuint8 c, zuint8 d)
	{return FALSE;}


#if Z_COMPILER_HAS_FUNCTION(UINT8_ATOMIC_ADD_THEN_GET)
#	define z_uint8_atomic_add_then_get Z_COMPILER_FUNCTION(UINT8_ATOMIC_ADD_THEN_GET)
#endif

#if Z_COMPILER_HAS_FUNCTION(UINT8_ATOMIC_AND_THEN_GET)
#	define z_uint8_atomic_and_then_get Z_COMPILER_FUNCTION(UINT8_ATOMIC_AND_THEN_GET)
#endif

#if Z_COMPILER_HAS_FUNCTION(UINT8_ATOMIC_DECREMENT_THEN_GET)
#	define z_uint8_atomic_decrement_then_get Z_COMPILER_FUNCTION(UINT8_ATOMIC_DECREMENT_THEN_GET)
#endif

#if Z_COMPILER_HAS_FUNCTION(UINT8_ATOMIC_GET_THEN_ADD)
#	define z_uint8_atomic_get_then_add Z_COMPILER_FUNCTION(UINT8_ATOMIC_GET_THEN_ADD)
#endif

#if Z_COMPILER_HAS_FUNCTION(UINT8_ATOMIC_GET_THEN_AND)
#	define z_uint8_atomic_get_then_and Z_COMPILER_FUNCTION(UINT8_ATOMIC_GET_THEN_AND)
#endif

#if Z_COMPILER_HAS_FUNCTION(UINT8_ATOMIC_GET_THEN_DECREMENT)
#	define z_uint8_atomic_get_then_decrement Z_COMPILER_FUNCTION(UINT8_ATOMIC_GET_THEN_DECREMENT)
#endif

#if Z_COMPILER_HAS_FUNCTION(UINT8_ATOMIC_GET_THEN_INCREMENT)
#	define z_uint8_atomic_get_then_increment Z_COMPILER_FUNCTION(UINT8_ATOMIC_GET_THEN_INCREMENT)
#endif

#if Z_COMPILER_HAS_FUNCTION(UINT8_ATOMIC_GET_THEN_NAND)
#	define z_uint8_atomic_get_then_nand Z_COMPILER_FUNCTION(UINT8_ATOMIC_GET_THEN_NAND)
#endif

#if Z_COMPILER_HAS_FUNCTION(UINT8_ATOMIC_GET_THEN_NOT)
#	define z_uint8_atomic_get_then_not Z_COMPILER_FUNCTION(UINT8_ATOMIC_GET_THEN_NOT)
#endif

#if Z_COMPILER_HAS_FUNCTION(UINT8_ATOMIC_GET_THEN_OR)
#	define z_uint8_atomic_get_then_or Z_COMPILER_FUNCTION(UINT8_ATOMIC_GET_THEN_OR)
#endif

#if Z_COMPILER_HAS_FUNCTION(UINT8_ATOMIC_GET_THEN_SET)
#	define z_uint8_atomic_get_then_set Z_COMPILER_FUNCTION(UINT8_ATOMIC_GET_THEN_SET)
#endif

#if Z_COMPILER_HAS_FUNCTION(UINT8_ATOMIC_GET_THEN_SUBTRACT)
#	define z_uint8_atomic_get_then_subtract Z_COMPILER_FUNCTION(UINT8_ATOMIC_GET_THEN_SUBTRACT)
#endif

#if Z_COMPILER_HAS_FUNCTION(UINT8_ATOMIC_GET_THEN_XOR)
#	define z_uint8_atomic_get_then_xor Z_COMPILER_FUNCTION(UINT8_ATOMIC_GET_THEN_XOR)
#endif

#if Z_COMPILER_HAS_FUNCTION(UINT8_ATOMIC_INCREMENT_THEN_GET)
#	define z_uint8_atomic_increment_then_get Z_COMPILER_FUNCTION(UINT8_ATOMIC_INCREMENT_THEN_GET)
#endif

#if Z_COMPILER_HAS_FUNCTION(UINT8_ATOMIC_NAND_THEN_GET)
#	define z_uint8_atomic_nand_then_get Z_COMPILER_FUNCTION(UINT8_ATOMIC_NAND_THEN_GET)
#endif

#if Z_COMPILER_HAS_FUNCTION(UINT8_ATOMIC_NOT_THEN_GET)
#	define z_uint8_atomic_not_then_get Z_COMPILER_FUNCTION(UINT8_ATOMIC_NOT_THEN_GET)
#endif

#if Z_COMPILER_HAS_FUNCTION(UINT8_ATOMIC_OR_THEN_GET)
#	define z_uint8_atomic_or_then_get Z_COMPILER_FUNCTION(UINT8_ATOMIC_OR_THEN_GET)
#endif

#if Z_COMPILER_HAS_FUNCTION(UINT8_ATOMIC_SET_IF_EQUAL)
#	define z_uint8_atomic_set_if_equal Z_COMPILER_FUNCTION(UINT8_ATOMIC_SET_IF_EQUAL)
#endif

#if Z_COMPILER_HAS_FUNCTION(UINT8_ATOMIC_SUBTRACT_THEN_GET)
#	define z_uint8_atomic_subtract_then_get Z_COMPILER_FUNCTION(UINT8_ATOMIC_SUBTRACT_THEN_GET)
#endif

#if Z_COMPILER_HAS_FUNCTION(UINT8_ATOMIC_XOR_THEN_GET)
#	define z_uint8_atomic_xor_then_get Z_COMPILER_FUNCTION(UINT8_ATOMIC_XOR_THEN_GET)
#endif


/* MARK: - uint16 */


Z_IMPLEMENTATION_NATURAL      (uint16)
Z_IMPLEMENTATION_VALUE_REVERSE(uint16, 16, 1)
Z_IMPLEMENTATION_VALUE_REVERSE(uint16, 16, 2)
Z_IMPLEMENTATION_VALUE_REVERSE(uint16, 16, 4)
Z_IMPLEMENTATION_VALUE_REVERSE(uint16, 16, 8)
Z_IMPLEMENTATION_VALUE_ROTATE (uint16, 16)


#define z_uint16_reverse z_uint16_reverse_in_8bit

#if Z_UINT16_ENDIANNESS == Z_ENDIANNESS_BIG

#	define z_uint16_big_endian    Z_SAME
#	define z_uint16_little_endian z_uint16_reverse

#elif Z_UINT16_ENDIANNESS == Z_ENDIANNESS_LITTLE

#	define z_uint16_big_endian    z_uint16_reverse
#	define z_uint16_little_endian Z_SAME

#endif


Z_INLINE zboolean z_uint16_addition_overflows(zuint16 a, zuint16 b)
	{return (zuint32)a + (zuint32)b > Z_UINT16_MAXIMUM;}


Z_INLINE zboolean z_uint16_addition_overflows_3(zuint16 a, zuint16 b, zuint16 c)
	{return (zuint32)a + (zuint32)b + (zuint32)c > Z_UINT16_MAXIMUM;}


Z_INLINE zboolean z_uint16_addition_overflows_4(zuint16 a, zuint16 b, zuint16 c, zuint16 d)
	{return (zuint32)a + (zuint32)b + (zuint32)c + (zuint32)d > Z_UINT16_MAXIMUM;}


Z_INLINE zboolean z_uint16_multiplication_overflows(zuint16 a, zuint16 b)
	{return (zuint32)a * (zuint32)b > Z_UINT16_MAXIMUM;}


Z_INLINE zboolean z_uint16_multiplication_overflows_3(zuint16 a, zuint16 b, zuint16 c)
	{return FALSE;}


Z_INLINE zboolean z_uint16_multiplication_overflows_4(zuint16 a, zuint16 b, zuint16 c, zuint16 d)
	{return FALSE;}


Z_INLINE zboolean z_uint16_subtraction_overflows(zuint16 a, zuint16 b)
	{return b > a;}


Z_INLINE zboolean z_uint16_subtraction_overflows_3(zuint16 a, zuint16 b, zuint16 c)
	{return FALSE;}


Z_INLINE zboolean z_uint16_subtraction_overflows_4(zuint16 a, zuint16 b, zuint16 c, zuint16 d)
	{return FALSE;}


Z_INLINE zuint8 z_uint16_minimum_storage_size(zuint16 value)
	{return value >> 8 ? 2 : 1;}


#if Z_COMPILER_HAS_FUNCTION(UINT16_ATOMIC_ADD_THEN_GET)
#	define z_uint16_atomic_add_then_get Z_COMPILER_FUNCTION(UINT16_ATOMIC_ADD_THEN_GET)
#endif

#if Z_COMPILER_HAS_FUNCTION(UINT16_ATOMIC_AND_THEN_GET)
#	define z_uint16_atomic_and_then_get Z_COMPILER_FUNCTION(UINT16_ATOMIC_AND_THEN_GET)
#endif

#if Z_COMPILER_HAS_FUNCTION(UINT16_ATOMIC_DECREMENT_THEN_GET)
#	define z_uint16_atomic_decrement_then_get Z_COMPILER_FUNCTION(UINT16_ATOMIC_DECREMENT_THEN_GET)
#endif

#if Z_COMPILER_HAS_FUNCTION(UINT16_ATOMIC_GET_THEN_ADD)
#	define z_uint16_atomic_get_then_add Z_COMPILER_FUNCTION(UINT16_ATOMIC_GET_THEN_ADD)
#endif

#if Z_COMPILER_HAS_FUNCTION(UINT16_ATOMIC_GET_THEN_AND)
#	define z_uint16_atomic_get_then_and Z_COMPILER_FUNCTION(UINT16_ATOMIC_GET_THEN_AND)
#endif

#if Z_COMPILER_HAS_FUNCTION(UINT16_ATOMIC_GET_THEN_DECREMENT)
#	define z_uint16_atomic_get_then_decrement Z_COMPILER_FUNCTION(UINT16_ATOMIC_GET_THEN_DECREMENT)
#endif

#if Z_COMPILER_HAS_FUNCTION(UINT16_ATOMIC_GET_THEN_INCREMENT)
#	define z_uint16_atomic_get_then_increment Z_COMPILER_FUNCTION(UINT16_ATOMIC_GET_THEN_INCREMENT)
#endif

#if Z_COMPILER_HAS_FUNCTION(UINT16_ATOMIC_GET_THEN_NAND)
#	define z_uint16_atomic_get_then_nand Z_COMPILER_FUNCTION(UINT16_ATOMIC_GET_THEN_NAND)
#endif

#if Z_COMPILER_HAS_FUNCTION(UINT16_ATOMIC_GET_THEN_NOT)
#	define z_uint16_atomic_get_then_not Z_COMPILER_FUNCTION(UINT16_ATOMIC_GET_THEN_NOT)
#endif

#if Z_COMPILER_HAS_FUNCTION(UINT16_ATOMIC_GET_THEN_OR)
#	define z_uint16_atomic_get_then_or Z_COMPILER_FUNCTION(UINT16_ATOMIC_GET_THEN_OR)
#endif

#if Z_COMPILER_HAS_FUNCTION(UINT16_ATOMIC_GET_THEN_SET)
#	define z_uint16_atomic_get_then_set Z_COMPILER_FUNCTION(UINT16_ATOMIC_GET_THEN_SET)
#endif

#if Z_COMPILER_HAS_FUNCTION(UINT16_ATOMIC_GET_THEN_SUBTRACT)
#	define z_uint16_atomic_get_then_subtract Z_COMPILER_FUNCTION(UINT16_ATOMIC_GET_THEN_SUBTRACT)
#endif

#if Z_COMPILER_HAS_FUNCTION(UINT16_ATOMIC_GET_THEN_XOR)
#	define z_uint16_atomic_get_then_xor Z_COMPILER_FUNCTION(UINT16_ATOMIC_GET_THEN_XOR)
#endif

#if Z_COMPILER_HAS_FUNCTION(UINT16_ATOMIC_INCREMENT_THEN_GET)
#	define z_uint16_atomic_increment_then_get Z_COMPILER_FUNCTION(UINT16_ATOMIC_INCREMENT_THEN_GET)
#endif

#if Z_COMPILER_HAS_FUNCTION(UINT16_ATOMIC_NAND_THEN_GET)
#	define z_uint16_atomic_nand_then_get Z_COMPILER_FUNCTION(UINT16_ATOMIC_NAND_THEN_GET)
#endif

#if Z_COMPILER_HAS_FUNCTION(UINT16_ATOMIC_NOT_THEN_GET)
#	define z_uint16_atomic_not_then_get Z_COMPILER_FUNCTION(UINT16_ATOMIC_NOT_THEN_GET)
#endif

#if Z_COMPILER_HAS_FUNCTION(UINT16_ATOMIC_OR_THEN_GET)
#	define z_uint16_atomic_or_then_get Z_COMPILER_FUNCTION(UINT16_ATOMIC_OR_THEN_GET)
#endif

#if Z_COMPILER_HAS_FUNCTION(UINT16_ATOMIC_SET_IF_EQUAL)
#	define z_uint16_atomic_set_if_equal Z_COMPILER_FUNCTION(UINT16_ATOMIC_SET_IF_EQUAL)
#endif

#if Z_COMPILER_HAS_FUNCTION(UINT16_ATOMIC_SUBTRACT_THEN_GET)
#	define z_uint16_atomic_subtract_then_get Z_COMPILER_FUNCTION(UINT16_ATOMIC_SUBTRACT_THEN_GET)
#endif

#if Z_COMPILER_HAS_FUNCTION(UINT16_ATOMIC_XOR_THEN_GET)
#	define z_uint16_atomic_xor_then_get Z_COMPILER_FUNCTION(UINT16_ATOMIC_XOR_THEN_GET)
#endif


/* MARK: - uint32 */


Z_IMPLEMENTATION_NATURAL      (uint32)
Z_IMPLEMENTATION_VALUE_REVERSE(uint32, 32,  1)
Z_IMPLEMENTATION_VALUE_REVERSE(uint32, 32,  2)
Z_IMPLEMENTATION_VALUE_REVERSE(uint32, 32,  4)
Z_IMPLEMENTATION_VALUE_REVERSE(uint32, 32,  8)
Z_IMPLEMENTATION_VALUE_REVERSE(uint32, 32, 16)
Z_IMPLEMENTATION_VALUE_ROTATE (uint32, 32)


#define z_uint32_reverse z_uint32_reverse_in_8bit

#if Z_UINT32_ENDIANNESS == Z_ENDIANNESS_BIG

#	define z_uint32_big_endian    Z_SAME
#	define z_uint32_little_endian z_uint32_reverse

#elif Z_UINT32_ENDIANNESS == Z_ENDIANNESS_LITTLE

#	define z_uint32_big_endian    z_uint32_reverse
#	define z_uint32_little_endian Z_SAME

#endif


Z_INLINE zboolean z_uint32_addition_overflows(zuint32 a, zuint32 b)
	{return FALSE;}


Z_INLINE zboolean z_uint32_addition_overflows_3(zuint32 a, zuint32 b, zuint32 c)
	{return FALSE;}


Z_INLINE zboolean z_uint32_addition_overflows_4(zuint32 a, zuint32 b, zuint32 c, zuint32 d)
	{return FALSE;}


Z_INLINE zboolean z_uint32_multiplication_overflows(zuint32 a, zuint32 b)
	{return FALSE;}


Z_INLINE zboolean z_uint32_multiplication_overflows_3(zuint32 a, zuint32 b, zuint32 c)
	{return FALSE;}


Z_INLINE zboolean z_uint32_multiplication_overflows_4(zuint32 a, zuint32 b, zuint32 c, zuint32 d)
	{return FALSE;}


Z_INLINE zboolean z_uint32_subtraction_overflows(zuint32 a, zuint32 b)
	{return b > a;}


Z_INLINE zboolean z_uint32_subtraction_overflows_3(zuint32 a, zuint32 b, zuint32 c)
	{return FALSE;}


Z_INLINE zboolean z_uint32_subtraction_overflows_4(zuint32 a, zuint32 b, zuint32 c, zuint32 d)
	{return FALSE;}


Z_INLINE zuint8 z_uint32_minimum_storage_size(zuint32 value)
	{
	if ((value >> 24)) return 4;
	if ((value >> 16)) return 3;
	if ((value >>  8)) return 2;
			   return 1;
	}


#if Z_COMPILER_HAS_FUNCTION(UINT32_ATOMIC_ADD_THEN_GET)
#	define z_uint32_atomic_add_then_get Z_COMPILER_FUNCTION(UINT32_ATOMIC_ADD_THEN_GET)
#endif

#if Z_COMPILER_HAS_FUNCTION(UINT32_ATOMIC_AND_THEN_GET)
#	define z_uint32_atomic_and_then_get Z_COMPILER_FUNCTION(UINT32_ATOMIC_AND_THEN_GET)
#endif

#if Z_COMPILER_HAS_FUNCTION(UINT32_ATOMIC_DECREMENT_THEN_GET)
#	define z_uint32_atomic_decrement_then_get Z_COMPILER_FUNCTION(UINT32_ATOMIC_DECREMENT_THEN_GET)
#endif

#if Z_COMPILER_HAS_FUNCTION(UINT32_ATOMIC_GET_THEN_ADD)
#	define z_uint32_atomic_get_then_add Z_COMPILER_FUNCTION(UINT32_ATOMIC_GET_THEN_ADD)
#endif

#if Z_COMPILER_HAS_FUNCTION(UINT32_ATOMIC_GET_THEN_AND)
#	define z_uint32_atomic_get_then_and Z_COMPILER_FUNCTION(UINT32_ATOMIC_GET_THEN_AND)
#endif

#if Z_COMPILER_HAS_FUNCTION(UINT32_ATOMIC_GET_THEN_DECREMENT)
#	define z_uint32_atomic_get_then_decrement Z_COMPILER_FUNCTION(UINT32_ATOMIC_GET_THEN_DECREMENT)
#endif

#if Z_COMPILER_HAS_FUNCTION(UINT32_ATOMIC_GET_THEN_INCREMENT)
#	define z_uint32_atomic_get_then_increment Z_COMPILER_FUNCTION(UINT32_ATOMIC_GET_THEN_INCREMENT)
#endif

#if Z_COMPILER_HAS_FUNCTION(UINT32_ATOMIC_GET_THEN_NAND)
#	define z_uint32_atomic_get_then_nand Z_COMPILER_FUNCTION(UINT32_ATOMIC_GET_THEN_NAND)
#endif

#if Z_COMPILER_HAS_FUNCTION(UINT32_ATOMIC_GET_THEN_NOT)
#	define z_uint32_atomic_get_then_not Z_COMPILER_FUNCTION(UINT32_ATOMIC_GET_THEN_NOT)
#endif

#if Z_COMPILER_HAS_FUNCTION(UINT32_ATOMIC_GET_THEN_OR)
#	define z_uint32_atomic_get_then_or Z_COMPILER_FUNCTION(UINT32_ATOMIC_GET_THEN_OR)
#endif

#if Z_COMPILER_HAS_FUNCTION(UINT32_ATOMIC_GET_THEN_SET)
#	define z_uint32_atomic_get_then_set Z_COMPILER_FUNCTION(UINT32_ATOMIC_GET_THEN_SET)
#endif

#if Z_COMPILER_HAS_FUNCTION(UINT32_ATOMIC_GET_THEN_SUBTRACT)
#	define z_uint32_atomic_get_then_subtract Z_COMPILER_FUNCTION(UINT32_ATOMIC_GET_THEN_SUBTRACT)
#endif

#if Z_COMPILER_HAS_FUNCTION(UINT32_ATOMIC_GET_THEN_XOR)
#	define z_uint32_atomic_get_then_xor Z_COMPILER_FUNCTION(UINT32_ATOMIC_GET_THEN_XOR)
#endif

#if Z_COMPILER_HAS_FUNCTION(UINT32_ATOMIC_INCREMENT_THEN_GET)
#	define z_uint32_atomic_increment_then_get Z_COMPILER_FUNCTION(UINT32_ATOMIC_INCREMENT_THEN_GET)
#endif

#if Z_COMPILER_HAS_FUNCTION(UINT32_ATOMIC_NAND_THEN_GET)
#	define z_uint32_atomic_nand_then_get Z_COMPILER_FUNCTION(UINT32_ATOMIC_NAND_THEN_GET)
#endif

#if Z_COMPILER_HAS_FUNCTION(UINT32_ATOMIC_NOT_THEN_GET)
#	define z_uint32_atomic_not_then_get Z_COMPILER_FUNCTION(UINT32_ATOMIC_NOT_THEN_GET)
#endif

#if Z_COMPILER_HAS_FUNCTION(UINT32_ATOMIC_OR_THEN_GET)
#	define z_uint32_atomic_or_then_get Z_COMPILER_FUNCTION(UINT32_ATOMIC_OR_THEN_GET)
#endif

#if Z_COMPILER_HAS_FUNCTION(UINT32_ATOMIC_SET_IF_EQUAL)
#	define z_uint32_atomic_set_if_equal Z_COMPILER_FUNCTION(UINT32_ATOMIC_SET_IF_EQUAL)
#endif

#if Z_COMPILER_HAS_FUNCTION(UINT32_ATOMIC_SUBTRACT_THEN_GET)
#	define z_uint32_atomic_subtract_then_get Z_COMPILER_FUNCTION(UINT32_ATOMIC_SUBTRACT_THEN_GET)
#endif

#if Z_COMPILER_HAS_FUNCTION(UINT32_ATOMIC_XOR_THEN_GET)
#	define z_uint32_atomic_xor_then_get Z_COMPILER_FUNCTION(UINT32_ATOMIC_XOR_THEN_GET)
#endif


/* MARK: - uint64 */


#ifdef Z_UINT64

	Z_IMPLEMENTATION_NATURAL      (uint64)
	Z_IMPLEMENTATION_VALUE_REVERSE(uint64, 64,  1)
	Z_IMPLEMENTATION_VALUE_REVERSE(uint64, 64,  2)
	Z_IMPLEMENTATION_VALUE_REVERSE(uint64, 64,  4)
	Z_IMPLEMENTATION_VALUE_REVERSE(uint64, 64,  8)
	Z_IMPLEMENTATION_VALUE_REVERSE(uint64, 64, 16)
	Z_IMPLEMENTATION_VALUE_REVERSE(uint64, 64, 32)
	Z_IMPLEMENTATION_VALUE_ROTATE (uint64, 64)


#	define z_uint64_reverse z_uint64_reverse_in_8bit

#	if Z_UINT64_ENDIANNESS == Z_ENDIANNESS_BIG

#		define z_uint64_big_endian    Z_SAME
#		define z_uint64_little_endian z_uint64_reverse

#	elif Z_UINT64_ENDIANNESS == Z_ENDIANNESS_LITTLE

#		define z_uint64_big_endian    z_uint64_reverse
#		define z_uint64_little_endian Z_SAME

#	endif


	Z_INLINE
	zboolean z_uint64_addition_overflows(zuint64 a, zuint64 b)
		{return FALSE;}


	Z_INLINE
	zboolean z_uint64_addition_overflows_3(zuint64 a, zuint64 b, zuint64 c)
		{return FALSE;}


	Z_INLINE
	zboolean z_uint64_addition_overflows_4(zuint64 a, zuint64 b, zuint64 c, zuint64 d)
		{return FALSE;}


	Z_INLINE
	zboolean z_uint64_multiplication_overflows(zuint64 a, zuint64 b)
		{return FALSE;}

	Z_INLINE
	zboolean z_uint64_multiplication_overflows_3(zuint64 a, zuint64 b, zuint64 c)
		{return FALSE;}


	Z_INLINE
	zboolean z_uint64_multiplication_overflows_4(zuint64 a, zuint64 b, zuint64 c, zuint64 d)
		{return FALSE;}


	Z_INLINE
	zboolean z_uint64_subtraction_overflows(zuint64 a, zuint64 b)
		{return b > a;}


	Z_INLINE
	zboolean z_uint64_subtraction_overflows_3(zuint64 a, zuint64 b, zuint64 c)
		{return FALSE;}


	Z_INLINE
	zboolean z_uint64_subtraction_overflows_4(zuint64 a, zuint64 b, zuint64 c, zuint64 d)
		{return FALSE;}


	Z_INLINE zuint8 z_uint64_minimum_storage_size(zuint64 value)
		{
		if ((value >> 56)) return 8;
		if ((value >> 48)) return 7;
		if ((value >> 40)) return 6;
		if ((value >> 32)) return 5;
		if ((value >> 24)) return 4;
		if ((value >> 16)) return 3;
		if ((value >>  8)) return 2;
				   return 1;
		}


#	if Z_COMPILER_HAS_FUNCTION(UINT64_ATOMIC_ADD_THEN_GET)
#		define z_uint64_atomic_add_then_get Z_COMPILER_FUNCTION(UINT64_ATOMIC_ADD_THEN_GET)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(UINT64_ATOMIC_AND_THEN_GET)
#		define z_uint64_atomic_and_then_get Z_COMPILER_FUNCTION(UINT64_ATOMIC_AND_THEN_GET)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(UINT64_ATOMIC_DECREMENT_THEN_GET)
#		define z_uint64_atomic_decrement_then_get Z_COMPILER_FUNCTION(UINT64_ATOMIC_DECREMENT_THEN_GET)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(UINT64_ATOMIC_GET_THEN_ADD)
#		define z_uint64_atomic_get_then_add Z_COMPILER_FUNCTION(UINT64_ATOMIC_GET_THEN_ADD)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(UINT64_ATOMIC_GET_THEN_AND)
#		define z_uint64_atomic_get_then_and Z_COMPILER_FUNCTION(UINT64_ATOMIC_GET_THEN_AND)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(UINT64_ATOMIC_GET_THEN_DECREMENT)
#		define z_uint64_atomic_get_then_decrement Z_COMPILER_FUNCTION(UINT64_ATOMIC_GET_THEN_DECREMENT)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(UINT64_ATOMIC_GET_THEN_INCREMENT)
#		define z_uint64_atomic_get_then_increment Z_COMPILER_FUNCTION(UINT64_ATOMIC_GET_THEN_INCREMENT)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(UINT64_ATOMIC_GET_THEN_NAND)
#		define z_uint64_atomic_get_then_nand Z_COMPILER_FUNCTION(UINT64_ATOMIC_GET_THEN_NAND)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(UINT64_ATOMIC_GET_THEN_NOT)
#		define z_uint64_atomic_get_then_not Z_COMPILER_FUNCTION(UINT64_ATOMIC_GET_THEN_NOT)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(UINT64_ATOMIC_GET_THEN_OR)
#		define z_uint64_atomic_get_then_or Z_COMPILER_FUNCTION(UINT64_ATOMIC_GET_THEN_OR)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(UINT64_ATOMIC_GET_THEN_SET)
#		define z_uint64_atomic_get_then_set Z_COMPILER_FUNCTION(UINT64_ATOMIC_GET_THEN_SET)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(UINT64_ATOMIC_GET_THEN_SUBTRACT)
#		define z_uint64_atomic_get_then_subtract Z_COMPILER_FUNCTION(UINT64_ATOMIC_GET_THEN_SUBTRACT)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(UINT64_ATOMIC_GET_THEN_XOR)
#		define z_uint64_atomic_get_then_xor Z_COMPILER_FUNCTION(UINT64_ATOMIC_GET_THEN_XOR)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(UINT64_ATOMIC_INCREMENT_THEN_GET)
#		define z_uint64_atomic_increment_then_get Z_COMPILER_FUNCTION(UINT64_ATOMIC_INCREMENT_THEN_GET)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(UINT64_ATOMIC_NAND_THEN_GET)
#		define z_uint64_atomic_nand_then_get Z_COMPILER_FUNCTION(UINT64_ATOMIC_NAND_THEN_GET)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(UINT64_ATOMIC_NOT_THEN_GET)
#		define z_uint64_atomic_not_then_get Z_COMPILER_FUNCTION(UINT64_ATOMIC_NOT_THEN_GET)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(UINT64_ATOMIC_OR_THEN_GET)
#		define z_uint64_atomic_or_then_get Z_COMPILER_FUNCTION(UINT64_ATOMIC_OR_THEN_GET)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(UINT64_ATOMIC_SET_IF_EQUAL)
#		define z_uint64_atomic_set_if_equal Z_COMPILER_FUNCTION(UINT64_ATOMIC_SET_IF_EQUAL)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(UINT64_ATOMIC_SUBTRACT_THEN_GET)
#		define z_uint64_atomic_subtract_then_get Z_COMPILER_FUNCTION(UINT64_ATOMIC_SUBTRACT_THEN_GET)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(UINT64_ATOMIC_XOR_THEN_GET)
#		define z_uint64_atomic_xor_then_get Z_COMPILER_FUNCTION(UINT64_ATOMIC_XOR_THEN_GET)
#	endif

#endif


/* MARK: - uint128 */


#ifdef Z_UINT128

	Z_IMPLEMENTATION_NATURAL(uint128)
	Z_IMPLEMENTATION_VALUE_REVERSE(uint128, 128,  1)
	Z_IMPLEMENTATION_VALUE_REVERSE(uint128, 128,  2)
	Z_IMPLEMENTATION_VALUE_REVERSE(uint128, 128,  4)
	Z_IMPLEMENTATION_VALUE_REVERSE(uint128, 128,  8)
	Z_IMPLEMENTATION_VALUE_REVERSE(uint128, 128, 16)
	Z_IMPLEMENTATION_VALUE_REVERSE(uint128, 128, 32)
	Z_IMPLEMENTATION_VALUE_REVERSE(uint128, 128, 64)
	Z_IMPLEMENTATION_VALUE_ROTATE (uint128, 128)


#	define z_uint128_reverse z_uint128_reverse_in_8bit

#	if Z_UINT128_ENDIANNESS == Z_ENDIANNESS_BIG

#		define z_uint128_big_endian    Z_SAME
#		define z_uint128_little_endian z_uint128_reverse

#	elif Z_UINT128_ENDIANNESS == Z_ENDIANNESS_LITTLE

#		define z_uint128_big_endian    z_uint128_reverse
#		define z_uint128_little_endian Z_SAME

#	endif


	Z_INLINE
	zboolean z_uint128_addition_overflows(zuint128 a, zuint128 b)
		{return FALSE;}


	Z_INLINE
	zboolean z_uint128_addition_overflows_3(zuint128 a, zuint128 b, zuint128 c)
		{return FALSE;}


	Z_INLINE
	zboolean z_uint128_addition_overflows_4(zuint128 a, zuint128 b, zuint128 c, zuint128 d)
		{return FALSE;}


	Z_INLINE
	zboolean z_uint128_multiplication_overflows(zuint128 a, zuint128 b)
		{return FALSE;}


	Z_INLINE
	zboolean z_uint128_multiplication_overflows_3(zuint128 a, zuint128 b, zuint128 c)
		{return FALSE;}


	Z_INLINE
	zboolean z_uint128_multiplication_overflows_4(zuint128 a, zuint128 b, zuint128 c, zuint128 d)
		{return FALSE;}


	Z_INLINE
	zboolean z_uint128_subtraction_overflows(zuint128 a, zuint128 b)
		{return b > a;}


	Z_INLINE
	zboolean z_uint128_subtraction_overflows_3(zuint128 a, zuint128 b, zuint128 c)
		{return FALSE;}


	Z_INLINE
	zboolean z_uint128_subtraction_overflows_4(zuint128 a, zuint128 b, zuint128 c, zuint128 d)
		{return FALSE;}


	Z_INLINE zuint8 z_uint128_minimum_storage_size(zuint128 value)
		{
		if ((value >> 120)) return 16;
		if ((value >> 112)) return 15;
		if ((value >> 104)) return 14;
		if ((value >>  96)) return 13;
		if ((value >>  88)) return 12;
		if ((value >>  80)) return 11;
		if ((value >>  72)) return 10;
		if ((value >>  64)) return  9;
		if ((value >>  56)) return  8;
		if ((value >>  48)) return  7;
		if ((value >>  40)) return  6;
		if ((value >>  32)) return  5;
		if ((value >>  24)) return  4;
		if ((value >>  16)) return  3;
		if ((value >>	8)) return  2;
				    return  1;
		}


#	if Z_COMPILER_HAS_FUNCTION(UINT128_ATOMIC_ADD_THEN_GET)
#		define z_uint128_atomic_add_then_get Z_COMPILER_FUNCTION(UINT128_ATOMIC_ADD_THEN_GET)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(UINT128_ATOMIC_AND_THEN_GET)
#		define z_uint128_atomic_and_then_get Z_COMPILER_FUNCTION(UINT128_ATOMIC_AND_THEN_GET)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(UINT128_ATOMIC_DECREMENT_THEN_GET)
#		define z_uint128_atomic_decrement_then_get Z_COMPILER_FUNCTION(UINT128_ATOMIC_DECREMENT_THEN_GET)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(UINT128_ATOMIC_GET_THEN_ADD)
#		define z_uint128_atomic_get_then_add Z_COMPILER_FUNCTION(UINT128_ATOMIC_GET_THEN_ADD)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(UINT128_ATOMIC_GET_THEN_AND)
#		define z_uint128_atomic_get_then_and Z_COMPILER_FUNCTION(UINT128_ATOMIC_GET_THEN_AND)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(UINT128_ATOMIC_GET_THEN_DECREMENT)
#		define z_uint128_atomic_get_then_decrement Z_COMPILER_FUNCTION(UINT128_ATOMIC_GET_THEN_DECREMENT)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(UINT128_ATOMIC_GET_THEN_INCREMENT)
#		define z_uint128_atomic_get_then_increment Z_COMPILER_FUNCTION(UINT128_ATOMIC_GET_THEN_INCREMENT)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(UINT128_ATOMIC_GET_THEN_NAND)
#		define z_uint128_atomic_get_then_nand Z_COMPILER_FUNCTION(UINT128_ATOMIC_GET_THEN_NAND)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(UINT128_ATOMIC_GET_THEN_NOT)
#		define z_uint128_atomic_get_then_not Z_COMPILER_FUNCTION(UINT128_ATOMIC_GET_THEN_NOT)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(UINT128_ATOMIC_GET_THEN_OR)
#		define z_uint128_atomic_get_then_or Z_COMPILER_FUNCTION(UINT128_ATOMIC_GET_THEN_OR)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(UINT128_ATOMIC_GET_THEN_SET)
#		define z_uint128_atomic_get_then_set Z_COMPILER_FUNCTION(UINT128_ATOMIC_GET_THEN_SET)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(UINT128_ATOMIC_GET_THEN_SUBTRACT)
#		define z_uint128_atomic_get_then_subtract Z_COMPILER_FUNCTION(UINT128_ATOMIC_GET_THEN_SUBTRACT)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(UINT128_ATOMIC_GET_THEN_XOR)
#		define z_uint128_atomic_get_then_xor Z_COMPILER_FUNCTION(UINT128_ATOMIC_GET_THEN_XOR)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(UINT128_ATOMIC_INCREMENT_THEN_GET)
#		define z_uint128_atomic_increment_then_get Z_COMPILER_FUNCTION(UINT128_ATOMIC_INCREMENT_THEN_GET)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(UINT128_ATOMIC_NAND_THEN_GET)
#		define z_uint128_atomic_nand_then_get Z_COMPILER_FUNCTION(UINT128_ATOMIC_NAND_THEN_GET)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(UINT128_ATOMIC_NOT_THEN_GET)
#		define z_uint128_atomic_not_then_get Z_COMPILER_FUNCTION(UINT128_ATOMIC_NOT_THEN_GET)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(UINT128_ATOMIC_OR_THEN_GET)
#		define z_uint128_atomic_or_then_get Z_COMPILER_FUNCTION(UINT128_ATOMIC_OR_THEN_GET)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(UINT128_ATOMIC_SET_IF_EQUAL)
#		define z_uint128_atomic_set_if_equal Z_COMPILER_FUNCTION(UINT128_ATOMIC_SET_IF_EQUAL)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(UINT128_ATOMIC_SUBTRACT_THEN_GET)
#		define z_uint128_atomic_subtract_then_get Z_COMPILER_FUNCTION(UINT128_ATOMIC_SUBTRACT_THEN_GET)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(UINT128_ATOMIC_XOR_THEN_GET)
#		define z_uint128_atomic_xor_then_get Z_COMPILER_FUNCTION(UINT128_ATOMIC_XOR_THEN_GET)
#	endif

#endif


/* MARK: - int8 */


Z_IMPLEMENTATION_NATURAL      (int8)
Z_IMPLEMENTATION_INTEGER      (int8)
Z_IMPLEMENTATION_VALUE_REVERSE(int8, 8, 1)
Z_IMPLEMENTATION_VALUE_REVERSE(int8, 8, 2)
Z_IMPLEMENTATION_VALUE_REVERSE(int8, 8, 4)
Z_IMPLEMENTATION_VALUE_ROTATE (int8, 8)


#define z_int8_reverse Z_SAME


Z_INLINE
zboolean z_int8_addition_overflows(zint8 a, zint8 b)
	{return FALSE;}


Z_INLINE
zboolean z_int8_addition_overflows_3(zint8 a, zint8 b, zint8 c)
	{return FALSE;}


Z_INLINE
zboolean z_int8_addition_overflows_4(zint8 a, zint8 b, zint8 c, zint8 d)
	{return FALSE;}


Z_INLINE
zboolean z_int8_multiplication_overflows(zint8 a, zint8 b)
	{return FALSE;}


Z_INLINE
zboolean z_int8_multiplication_overflows_3(zint8 a, zint8 b, zint8 c)
	{return FALSE;}


Z_INLINE
zboolean z_int8_multiplication_overflows_4(zint8 a, zint8 b, zint8 c, zint8 d)
	{return FALSE;}


Z_INLINE
zboolean z_int8_subtraction_overflows(zint8 a, zint8 b)
	{return FALSE;}


Z_INLINE
zboolean z_int8_subtraction_overflows_3(zint8 a, zint8 b, zint8 c)
	{return FALSE;}


Z_INLINE
zboolean z_int8_subtraction_overflows_4(zint8 a, zint8 b, zint8 c, zint8 d)
	{return FALSE;}


#if Z_COMPILER_HAS_FUNCTION(INT8_ATOMIC_ADD_THEN_GET)
#	define z_int8_atomic_add_then_get Z_COMPILER_FUNCTION(INT8_ATOMIC_ADD_THEN_GET)
#endif

#if Z_COMPILER_HAS_FUNCTION(INT8_ATOMIC_AND_THEN_GET)
#	define z_int8_atomic_and_then_get Z_COMPILER_FUNCTION(INT8_ATOMIC_AND_THEN_GET)
#endif

#if Z_COMPILER_HAS_FUNCTION(INT8_ATOMIC_DECREMENT_THEN_GET)
#	define z_int8_atomic_decrement_then_get Z_COMPILER_FUNCTION(INT8_ATOMIC_DECREMENT_THEN_GET)
#endif

#if Z_COMPILER_HAS_FUNCTION(INT8_ATOMIC_GET_THEN_ADD)
#	define z_int8_atomic_get_then_add Z_COMPILER_FUNCTION(INT8_ATOMIC_GET_THEN_ADD)
#endif

#if Z_COMPILER_HAS_FUNCTION(INT8_ATOMIC_GET_THEN_AND)
#	define z_int8_atomic_get_then_and Z_COMPILER_FUNCTION(INT8_ATOMIC_GET_THEN_AND)
#endif

#if Z_COMPILER_HAS_FUNCTION(INT8_ATOMIC_GET_THEN_DECREMENT)
#	define z_int8_atomic_get_then_decrement Z_COMPILER_FUNCTION(INT8_ATOMIC_GET_THEN_DECREMENT)
#endif

#if Z_COMPILER_HAS_FUNCTION(INT8_ATOMIC_GET_THEN_INCREMENT)
#	define z_int8_atomic_get_then_increment Z_COMPILER_FUNCTION(INT8_ATOMIC_GET_THEN_INCREMENT)
#endif

#if Z_COMPILER_HAS_FUNCTION(INT8_ATOMIC_GET_THEN_NAND)
#	define z_int8_atomic_get_then_nand Z_COMPILER_FUNCTION(INT8_ATOMIC_GET_THEN_NAND)
#endif

#if Z_COMPILER_HAS_FUNCTION(INT8_ATOMIC_GET_THEN_NOT)
#	define z_int8_atomic_get_then_not Z_COMPILER_FUNCTION(INT8_ATOMIC_GET_THEN_NOT)
#endif

#if Z_COMPILER_HAS_FUNCTION(INT8_ATOMIC_GET_THEN_OR)
#	define z_int8_atomic_get_then_or Z_COMPILER_FUNCTION(INT8_ATOMIC_GET_THEN_OR)
#endif

#if Z_COMPILER_HAS_FUNCTION(INT8_ATOMIC_GET_THEN_SET)
#	define z_int8_atomic_get_then_set Z_COMPILER_FUNCTION(INT8_ATOMIC_GET_THEN_SET)
#endif

#if Z_COMPILER_HAS_FUNCTION(INT8_ATOMIC_GET_THEN_SUBTRACT)
#	define z_int8_atomic_get_then_subtract Z_COMPILER_FUNCTION(INT8_ATOMIC_GET_THEN_SUBTRACT)
#endif

#if Z_COMPILER_HAS_FUNCTION(INT8_ATOMIC_GET_THEN_XOR)
#	define z_int8_atomic_get_then_xor Z_COMPILER_FUNCTION(INT8_ATOMIC_GET_THEN_XOR)
#endif

#if Z_COMPILER_HAS_FUNCTION(INT8_ATOMIC_INCREMENT_THEN_GET)
#	define z_int8_atomic_increment_then_get Z_COMPILER_FUNCTION(INT8_ATOMIC_INCREMENT_THEN_GET)
#endif

#if Z_COMPILER_HAS_FUNCTION(INT8_ATOMIC_NAND_THEN_GET)
#	define z_int8_atomic_nand_then_get Z_COMPILER_FUNCTION(INT8_ATOMIC_NAND_THEN_GET)
#endif

#if Z_COMPILER_HAS_FUNCTION(INT8_ATOMIC_NOT_THEN_GET)
#	define z_int8_atomic_not_then_get Z_COMPILER_FUNCTION(INT8_ATOMIC_NOT_THEN_GET)
#endif

#if Z_COMPILER_HAS_FUNCTION(INT8_ATOMIC_OR_THEN_GET)
#	define z_int8_atomic_or_then_get Z_COMPILER_FUNCTION(INT8_ATOMIC_OR_THEN_GET)
#endif

#if Z_COMPILER_HAS_FUNCTION(INT8_ATOMIC_SET_IF_EQUAL)
#	define z_int8_atomic_set_if_equal Z_COMPILER_FUNCTION(INT8_ATOMIC_SET_IF_EQUAL)
#endif

#if Z_COMPILER_HAS_FUNCTION(INT8_ATOMIC_SUBTRACT_THEN_GET)
#	define z_int8_atomic_subtract_then_get Z_COMPILER_FUNCTION(INT8_ATOMIC_SUBTRACT_THEN_GET)
#endif

#if Z_COMPILER_HAS_FUNCTION(INT8_ATOMIC_XOR_THEN_GET)
#	define z_int8_atomic_xor_then_get Z_COMPILER_FUNCTION(INT8_ATOMIC_XOR_THEN_GET)
#endif


/* MARK: - int16 */


Z_IMPLEMENTATION_NATURAL      (int16)
Z_IMPLEMENTATION_INTEGER      (int16)
Z_IMPLEMENTATION_VALUE_REVERSE(int16, 16, 1)
Z_IMPLEMENTATION_VALUE_REVERSE(int16, 16, 2)
Z_IMPLEMENTATION_VALUE_REVERSE(int16, 16, 4)
Z_IMPLEMENTATION_VALUE_REVERSE(int16, 16, 8)
Z_IMPLEMENTATION_VALUE_ROTATE (int16, 16)


#define z_int16_reverse z_int16_reverse_in_8bit

#if Z_INT16_ENDIANNESS == Z_ENDIANNESS_BIG

#	define z_int16_big_endian     Z_SAME
#	define z_int16_little_endian  z_int16_reverse

#elif Z_INT16_ENDIANNESS == Z_ENDIANNESS_LITTLE

#	define z_int16_big_endian     z_int16_reverse
#	define z_int16_little_endian  Z_SAME

#endif


Z_INLINE
zboolean z_int16_addition_overflows(zint16 a, zint16 b)
	{return FALSE;}


Z_INLINE
zboolean z_int16_addition_overflows_3(zint16 a, zint16 b, zint16 c)
	{return FALSE;}


Z_INLINE
zboolean z_int16_addition_overflows_4(zint16 a, zint16 b, zint16 c, zint16 d)
	{return FALSE;}


Z_INLINE
zboolean z_int16_multiplication_overflows(zint16 a, zint16 b)
	{return FALSE;}


Z_INLINE
zboolean z_int16_multiplication_overflows_3(zint16 a, zint16 b, zint16 c)
	{return FALSE;}


Z_INLINE
zboolean z_int16_multiplication_overflows_4(zint16 a, zint16 b, zint16 c, zint16 d)
	{return FALSE;}


Z_INLINE
zboolean z_int16_subtraction_overflows(zint16 a, zint16 b)
	{return FALSE;}


Z_INLINE
zboolean z_int16_subtraction_overflows_3(zint16 a, zint16 b, zint16 c)
	{return FALSE;}


Z_INLINE
zboolean z_int16_subtraction_overflows_4(zint16 a, zint16 b, zint16 c, zint16 d)
	{return FALSE;}


#if Z_COMPILER_HAS_FUNCTION(INT16_ATOMIC_ADD_THEN_GET)
#	define z_int16_atomic_add_then_get Z_COMPILER_FUNCTION(INT16_ATOMIC_ADD_THEN_GET)
#endif

#if Z_COMPILER_HAS_FUNCTION(INT16_ATOMIC_AND_THEN_GET)
#	define z_int16_atomic_and_then_get Z_COMPILER_FUNCTION(INT16_ATOMIC_AND_THEN_GET)
#endif

#if Z_COMPILER_HAS_FUNCTION(INT16_ATOMIC_DECREMENT_THEN_GET)
#	define z_int16_atomic_decrement_then_get Z_COMPILER_FUNCTION(INT16_ATOMIC_DECREMENT_THEN_GET)
#endif

#if Z_COMPILER_HAS_FUNCTION(INT16_ATOMIC_GET_THEN_ADD)
#	define z_int16_atomic_get_then_add Z_COMPILER_FUNCTION(INT16_ATOMIC_GET_THEN_ADD)
#endif

#if Z_COMPILER_HAS_FUNCTION(INT16_ATOMIC_GET_THEN_AND)
#	define z_int16_atomic_get_then_and Z_COMPILER_FUNCTION(INT16_ATOMIC_GET_THEN_AND)
#endif

#if Z_COMPILER_HAS_FUNCTION(INT16_ATOMIC_GET_THEN_DECREMENT)
#	define z_int16_atomic_get_then_decrement Z_COMPILER_FUNCTION(INT16_ATOMIC_GET_THEN_DECREMENT)
#endif

#if Z_COMPILER_HAS_FUNCTION(INT16_ATOMIC_GET_THEN_INCREMENT)
#	define z_int16_atomic_get_then_increment Z_COMPILER_FUNCTION(INT16_ATOMIC_GET_THEN_INCREMENT)
#endif

#if Z_COMPILER_HAS_FUNCTION(INT16_ATOMIC_GET_THEN_NAND)
#	define z_int16_atomic_get_then_nand Z_COMPILER_FUNCTION(INT16_ATOMIC_GET_THEN_NAND)
#endif

#if Z_COMPILER_HAS_FUNCTION(INT16_ATOMIC_GET_THEN_NOT)
#	define z_int16_atomic_get_then_not Z_COMPILER_FUNCTION(INT16_ATOMIC_GET_THEN_NOT)
#endif

#if Z_COMPILER_HAS_FUNCTION(INT16_ATOMIC_GET_THEN_OR)
#	define z_int16_atomic_get_then_or Z_COMPILER_FUNCTION(INT16_ATOMIC_GET_THEN_OR)
#endif

#if Z_COMPILER_HAS_FUNCTION(INT16_ATOMIC_GET_THEN_SET)
#	define z_int16_atomic_get_then_set Z_COMPILER_FUNCTION(INT16_ATOMIC_GET_THEN_SET)
#endif

#if Z_COMPILER_HAS_FUNCTION(INT16_ATOMIC_GET_THEN_SUBTRACT)
#	define z_int16_atomic_get_then_subtract Z_COMPILER_FUNCTION(INT16_ATOMIC_GET_THEN_SUBTRACT)
#endif

#if Z_COMPILER_HAS_FUNCTION(INT16_ATOMIC_GET_THEN_XOR)
#	define z_int16_atomic_get_then_xor Z_COMPILER_FUNCTION(INT16_ATOMIC_GET_THEN_XOR)
#endif

#if Z_COMPILER_HAS_FUNCTION(INT16_ATOMIC_INCREMENT_THEN_GET)
#	define z_int16_atomic_increment_then_get Z_COMPILER_FUNCTION(INT16_ATOMIC_INCREMENT_THEN_GET)
#endif

#if Z_COMPILER_HAS_FUNCTION(INT16_ATOMIC_NAND_THEN_GET)
#	define z_int16_atomic_nand_then_get Z_COMPILER_FUNCTION(INT16_ATOMIC_NAND_THEN_GET)
#endif

#if Z_COMPILER_HAS_FUNCTION(INT16_ATOMIC_NOT_THEN_GET)
#	define z_int16_atomic_not_then_get Z_COMPILER_FUNCTION(INT16_ATOMIC_NOT_THEN_GET)
#endif

#if Z_COMPILER_HAS_FUNCTION(INT16_ATOMIC_OR_THEN_GET)
#	define z_int16_atomic_or_then_get Z_COMPILER_FUNCTION(INT16_ATOMIC_OR_THEN_GET)
#endif

#if Z_COMPILER_HAS_FUNCTION(INT16_ATOMIC_SET_IF_EQUAL)
#	define z_int16_atomic_set_if_equal Z_COMPILER_FUNCTION(INT16_ATOMIC_SET_IF_EQUAL)
#endif

#if Z_COMPILER_HAS_FUNCTION(INT16_ATOMIC_SUBTRACT_THEN_GET)
#	define z_int16_atomic_subtract_then_get Z_COMPILER_FUNCTION(INT16_ATOMIC_SUBTRACT_THEN_GET)
#endif

#if Z_COMPILER_HAS_FUNCTION(INT16_ATOMIC_XOR_THEN_GET)
#	define z_int16_atomic_xor_then_get Z_COMPILER_FUNCTION(INT16_ATOMIC_XOR_THEN_GET)
#endif


/* MARK: - int32 */


Z_IMPLEMENTATION_NATURAL      (int32)
Z_IMPLEMENTATION_INTEGER      (int32)
Z_IMPLEMENTATION_VALUE_REVERSE(int32, 32,  1)
Z_IMPLEMENTATION_VALUE_REVERSE(int32, 32,  2)
Z_IMPLEMENTATION_VALUE_REVERSE(int32, 32,  4)
Z_IMPLEMENTATION_VALUE_REVERSE(int32, 32,  8)
Z_IMPLEMENTATION_VALUE_REVERSE(int32, 32, 16)
Z_IMPLEMENTATION_VALUE_ROTATE (int32, 32)


#define z_int32_reverse z_int32_reverse_in_8bit

#if Z_INT32_ENDIANNESS == Z_ENDIANNESS_BIG

#	define z_int32_big_endian     Z_SAME
#	define z_int32_little_endian  z_int32_reverse

#elif Z_INT32_ENDIANNESS == Z_ENDIANNESS_LITTLE

#	define z_int32_big_endian     z_int32_reverse
#	define z_int32_little_endian  Z_SAME

#endif


Z_INLINE
zboolean z_int32_addition_overflows(zint32 a, zint32 b)
	{return FALSE;}


Z_INLINE
zboolean z_int32_addition_overflows_3(zint32 a, zint32 b, zint32 c)
	{return FALSE;}


Z_INLINE
zboolean z_int32_addition_overflows_4(zint32 a, zint32 b, zint32 c, zint32 d)
	{return FALSE;}


Z_INLINE
zboolean z_int32_multiplication_overflows(zint32 a, zint32 b)
	{return FALSE;}


Z_INLINE
zboolean z_int32_multiplication_overflows_3(zint32 a, zint32 b, zint32 c)
	{return FALSE;}


Z_INLINE
zboolean z_int32_multiplication_overflows_4(zint32 a, zint32 b, zint32 c, zint32 d)
	{return FALSE;}


Z_INLINE
zboolean z_int32_subtraction_overflows(zint32 a, zint32 b)
	{return FALSE;}


Z_INLINE
zboolean z_int32_subtraction_overflows_3(zint32 a, zint32 b, zint32 c)
	{return FALSE;}


Z_INLINE
zboolean z_int32_subtraction_overflows_4(zint32 a, zint32 b, zint32 c, zint32 d)
	{return FALSE;}


#if Z_COMPILER_HAS_FUNCTION(INT32_ATOMIC_ADD_THEN_GET)
#	define z_int32_atomic_add_then_get Z_COMPILER_FUNCTION(INT32_ATOMIC_ADD_THEN_GET)
#endif

#if Z_COMPILER_HAS_FUNCTION(INT32_ATOMIC_AND_THEN_GET)
#	define z_int32_atomic_and_then_get Z_COMPILER_FUNCTION(INT32_ATOMIC_AND_THEN_GET)
#endif

#if Z_COMPILER_HAS_FUNCTION(INT32_ATOMIC_DECREMENT_THEN_GET)
#	define z_int32_atomic_decrement_then_get Z_COMPILER_FUNCTION(INT32_ATOMIC_DECREMENT_THEN_GET)
#endif

#if Z_COMPILER_HAS_FUNCTION(INT32_ATOMIC_GET_THEN_ADD)
#	define z_int32_atomic_get_then_add Z_COMPILER_FUNCTION(INT32_ATOMIC_GET_THEN_ADD)
#endif

#if Z_COMPILER_HAS_FUNCTION(INT32_ATOMIC_GET_THEN_AND)
#	define z_int32_atomic_get_then_and Z_COMPILER_FUNCTION(INT32_ATOMIC_GET_THEN_AND)
#endif

#if Z_COMPILER_HAS_FUNCTION(INT32_ATOMIC_GET_THEN_DECREMENT)
#	define z_int32_atomic_get_then_decrement Z_COMPILER_FUNCTION(INT32_ATOMIC_GET_THEN_DECREMENT)
#endif

#if Z_COMPILER_HAS_FUNCTION(INT32_ATOMIC_GET_THEN_INCREMENT)
#	define z_int32_atomic_get_then_increment Z_COMPILER_FUNCTION(INT32_ATOMIC_GET_THEN_INCREMENT)
#endif

#if Z_COMPILER_HAS_FUNCTION(INT32_ATOMIC_GET_THEN_NAND)
#	define z_int32_atomic_get_then_nand Z_COMPILER_FUNCTION(INT32_ATOMIC_GET_THEN_NAND)
#endif

#if Z_COMPILER_HAS_FUNCTION(INT32_ATOMIC_GET_THEN_NOT)
#	define z_int32_atomic_get_then_not Z_COMPILER_FUNCTION(INT32_ATOMIC_GET_THEN_NOT)
#endif

#if Z_COMPILER_HAS_FUNCTION(INT32_ATOMIC_GET_THEN_OR)
#	define z_int32_atomic_get_then_or Z_COMPILER_FUNCTION(INT32_ATOMIC_GET_THEN_OR)
#endif

#if Z_COMPILER_HAS_FUNCTION(INT32_ATOMIC_GET_THEN_SET)
#	define z_int32_atomic_get_then_set Z_COMPILER_FUNCTION(INT32_ATOMIC_GET_THEN_SET)
#endif

#if Z_COMPILER_HAS_FUNCTION(INT32_ATOMIC_GET_THEN_SUBTRACT)
#	define z_int32_atomic_get_then_subtract Z_COMPILER_FUNCTION(INT32_ATOMIC_GET_THEN_SUBTRACT)
#endif

#if Z_COMPILER_HAS_FUNCTION(INT32_ATOMIC_GET_THEN_XOR)
#	define z_int32_atomic_get_then_xor Z_COMPILER_FUNCTION(INT32_ATOMIC_GET_THEN_XOR)
#endif

#if Z_COMPILER_HAS_FUNCTION(INT32_ATOMIC_INCREMENT_THEN_GET)
#	define z_int32_atomic_increment_then_get Z_COMPILER_FUNCTION(INT32_ATOMIC_INCREMENT_THEN_GET)
#endif

#if Z_COMPILER_HAS_FUNCTION(INT32_ATOMIC_NAND_THEN_GET)
#	define z_int32_atomic_nand_then_get Z_COMPILER_FUNCTION(INT32_ATOMIC_NAND_THEN_GET)
#endif

#if Z_COMPILER_HAS_FUNCTION(INT32_ATOMIC_NOT_THEN_GET)
#	define z_int32_atomic_not_then_get Z_COMPILER_FUNCTION(INT32_ATOMIC_NOT_THEN_GET)
#endif

#if Z_COMPILER_HAS_FUNCTION(INT32_ATOMIC_OR_THEN_GET)
#	define z_int32_atomic_or_then_get Z_COMPILER_FUNCTION(INT32_ATOMIC_OR_THEN_GET)
#endif

#if Z_COMPILER_HAS_FUNCTION(INT32_ATOMIC_SET_IF_EQUAL)
#	define z_int32_atomic_set_if_equal Z_COMPILER_FUNCTION(INT32_ATOMIC_SET_IF_EQUAL)
#endif

#if Z_COMPILER_HAS_FUNCTION(INT32_ATOMIC_SUBTRACT_THEN_GET)
#	define z_int32_atomic_subtract_then_get Z_COMPILER_FUNCTION(INT32_ATOMIC_SUBTRACT_THEN_GET)
#endif

#if Z_COMPILER_HAS_FUNCTION(INT32_ATOMIC_XOR_THEN_GET)
#	define z_int32_atomic_xor_then_get Z_COMPILER_FUNCTION(INT32_ATOMIC_XOR_THEN_GET)
#endif


/* MARK: - int64 */


#ifdef Z_INT64

	Z_IMPLEMENTATION_NATURAL      (int64)
	Z_IMPLEMENTATION_INTEGER      (int64)
	Z_IMPLEMENTATION_VALUE_REVERSE(int64, 64,  1)
	Z_IMPLEMENTATION_VALUE_REVERSE(int64, 64,  2)
	Z_IMPLEMENTATION_VALUE_REVERSE(int64, 64,  4)
	Z_IMPLEMENTATION_VALUE_REVERSE(int64, 64,  8)
	Z_IMPLEMENTATION_VALUE_REVERSE(int64, 64, 16)
	Z_IMPLEMENTATION_VALUE_REVERSE(int64, 64, 32)
	Z_IMPLEMENTATION_VALUE_ROTATE (int64, 64)


#	define z_int64_reverse z_int64_reverse_in_8bit

#	if Z_INT64_ENDIANNESS == Z_ENDIANNESS_BIG

#		define z_int64_big_endian    Z_SAME
#		define z_int64_little_endian z_int64_reverse

#	elif Z_INT64_ENDIANNESS == Z_ENDIANNESS_LITTLE

#		define z_int64_big_endian    z_int64_reverse
#		define z_int64_little_endian Z_SAME

#	endif


	Z_INLINE
	zboolean z_int64_addition_overflows(zint64 a, zint64 b)
		{return FALSE;}


	Z_INLINE
	zboolean z_int64_addition_overflows_3(zint64 a, zint64 b, zint64 c)
		{return FALSE;}


	Z_INLINE
	zboolean z_int64_addition_overflows_4(zint64 a, zint64 b, zint64 c, zint64 d)
		{return FALSE;}


	Z_INLINE
	zboolean z_int64_multiplication_overflows(zint64 a, zint64 b)
		{return FALSE;}


	Z_INLINE
	zboolean z_int64_multiplication_overflows_3(zint64 a, zint64 b, zint64 c)
		{return FALSE;}


	Z_INLINE
	zboolean z_int64_multiplication_overflows_4(zint64 a, zint64 b, zint64 c, zint64 d)
		{return FALSE;}


	Z_INLINE
	zboolean z_int64_subtraction_overflows(zint64 a, zint64 b)
		{return FALSE;}


	Z_INLINE
	zboolean z_int64_subtraction_overflows_3(zint64 a, zint64 b, zint64 c)
		{return FALSE;}


	Z_INLINE
	zboolean z_int64_subtraction_overflows_4(zint64 a, zint64 b, zint64 c, zint64 d)
		{return FALSE;}


#	if Z_COMPILER_HAS_FUNCTION(INT64_ATOMIC_ADD_THEN_GET)
#		define z_int64_atomic_add_then_get Z_COMPILER_FUNCTION(INT64_ATOMIC_ADD_THEN_GET)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(INT64_ATOMIC_AND_THEN_GET)
#		define z_int64_atomic_and_then_get Z_COMPILER_FUNCTION(INT64_ATOMIC_AND_THEN_GET)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(INT64_ATOMIC_DECREMENT_THEN_GET)
#		define z_int64_atomic_decrement_then_get Z_COMPILER_FUNCTION(INT64_ATOMIC_DECREMENT_THEN_GET)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(INT64_ATOMIC_GET_THEN_ADD)
#		define z_int64_atomic_get_then_add Z_COMPILER_FUNCTION(INT64_ATOMIC_GET_THEN_ADD)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(INT64_ATOMIC_GET_THEN_AND)
#		define z_int64_atomic_get_then_and Z_COMPILER_FUNCTION(INT64_ATOMIC_GET_THEN_AND)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(INT64_ATOMIC_GET_THEN_DECREMENT)
#		define z_int64_atomic_get_then_decrement Z_COMPILER_FUNCTION(INT64_ATOMIC_GET_THEN_DECREMENT)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(INT64_ATOMIC_GET_THEN_INCREMENT)
#		define z_int64_atomic_get_then_increment Z_COMPILER_FUNCTION(INT64_ATOMIC_GET_THEN_INCREMENT)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(INT64_ATOMIC_GET_THEN_NAND)
#		define z_int64_atomic_get_then_nand Z_COMPILER_FUNCTION(INT64_ATOMIC_GET_THEN_NAND)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(INT64_ATOMIC_GET_THEN_NOT)
#		define z_int64_atomic_get_then_not Z_COMPILER_FUNCTION(INT64_ATOMIC_GET_THEN_NOT)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(INT64_ATOMIC_GET_THEN_OR)
#		define z_int64_atomic_get_then_or Z_COMPILER_FUNCTION(INT64_ATOMIC_GET_THEN_OR)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(INT64_ATOMIC_GET_THEN_SET)
#		define z_int64_atomic_get_then_set Z_COMPILER_FUNCTION(INT64_ATOMIC_GET_THEN_SET)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(INT64_ATOMIC_GET_THEN_SUBTRACT)
#		define z_int64_atomic_get_then_subtract Z_COMPILER_FUNCTION(INT64_ATOMIC_GET_THEN_SUBTRACT)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(INT64_ATOMIC_GET_THEN_XOR)
#		define z_int64_atomic_get_then_xor Z_COMPILER_FUNCTION(INT64_ATOMIC_GET_THEN_XOR)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(INT64_ATOMIC_INCREMENT_THEN_GET)
#		define z_int64_atomic_increment_then_get Z_COMPILER_FUNCTION(INT64_ATOMIC_INCREMENT_THEN_GET)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(INT64_ATOMIC_NAND_THEN_GET)
#		define z_int64_atomic_nand_then_get Z_COMPILER_FUNCTION(INT64_ATOMIC_NAND_THEN_GET)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(INT64_ATOMIC_NOT_THEN_GET)
#		define z_int64_atomic_not_then_get Z_COMPILER_FUNCTION(INT64_ATOMIC_NOT_THEN_GET)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(INT64_ATOMIC_OR_THEN_GET)
#		define z_int64_atomic_or_then_get Z_COMPILER_FUNCTION(INT64_ATOMIC_OR_THEN_GET)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(INT64_ATOMIC_SET_IF_EQUAL)
#		define z_int64_atomic_set_if_equal Z_COMPILER_FUNCTION(INT64_ATOMIC_SET_IF_EQUAL)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(INT64_ATOMIC_SUBTRACT_THEN_GET)
#		define z_int64_atomic_subtract_then_get Z_COMPILER_FUNCTION(INT64_ATOMIC_SUBTRACT_THEN_GET)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(INT64_ATOMIC_XOR_THEN_GET)
#		define z_int64_atomic_xor_then_get Z_COMPILER_FUNCTION(INT64_ATOMIC_XOR_THEN_GET)
#	endif

#endif


/* MARK: - int128 */


#ifdef Z_INT128

	Z_IMPLEMENTATION_NATURAL      (int128)
	Z_IMPLEMENTATION_INTEGER      (int128)
	Z_IMPLEMENTATION_VALUE_REVERSE(int128, 128,  1)
	Z_IMPLEMENTATION_VALUE_REVERSE(int128, 128,  2)
	Z_IMPLEMENTATION_VALUE_REVERSE(int128, 128,  4)
	Z_IMPLEMENTATION_VALUE_REVERSE(int128, 128,  8)
	Z_IMPLEMENTATION_VALUE_REVERSE(int128, 128, 16)
	Z_IMPLEMENTATION_VALUE_REVERSE(int128, 128, 32)
	Z_IMPLEMENTATION_VALUE_REVERSE(int128, 128, 64)
	Z_IMPLEMENTATION_VALUE_ROTATE (int128, 128)


#	define z_int128_reverse z_int128_reverse_in_8bit

#	if Z_INT128_ENDIANNESS == Z_ENDIANNESS_BIG

#		define z_int128_big_endian     Z_SAME
#		define z_int128_little_endian  z_int128_reverse

#	elif Z_INT128_ENDIANNESS == Z_ENDIANNESS_LITTLE

#		define z_int128_big_endian     z_int128_reverse
#		define z_int128_little_endian  Z_SAME

#	endif


	Z_INLINE
	zboolean z_int128_addition_overflows(zint128 a, zint128 b)
		{return FALSE;}


	Z_INLINE
	zboolean z_int128_addition_overflows_3(zint128 a, zint128 b, zint128 c)
		{return FALSE;}


	Z_INLINE
	zboolean z_int128_addition_overflows_4(zint128 a, zint128 b, zint128 c, zint128 d)
		{return FALSE;}


	Z_INLINE
	zboolean z_int128_multiplication_overflows(zint128 a, zint128 b)
		{return FALSE;}


	Z_INLINE
	zboolean z_int128_multiplication_overflows_3(zint128 a, zint128 b, zint128 c)
		{return FALSE;}


	Z_INLINE
	zboolean z_int128_multiplication_overflows_4(zint128 a, zint128 b, zint128 c, zint128 d)
		{return FALSE;}


	Z_INLINE
	zboolean z_int128_subtraction_overflows(zint128 a, zint128 b)
		{return FALSE;}


	Z_INLINE
	zboolean z_int128_subtraction_overflows_3(zint128 a, zint128 b, zint128 c)
		{return FALSE;}


	Z_INLINE
	zboolean z_int128_subtraction_overflows_4(zint128 a, zint128 b, zint128 c, zint128 d)
		{return FALSE;}


#	if Z_COMPILER_HAS_FUNCTION(INT128_ATOMIC_ADD_THEN_GET)
#		define z_int128_atomic_add_then_get Z_COMPILER_FUNCTION(INT128_ATOMIC_ADD_THEN_GET)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(INT128_ATOMIC_AND_THEN_GET)
#		define z_int128_atomic_and_then_get Z_COMPILER_FUNCTION(INT128_ATOMIC_AND_THEN_GET)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(INT128_ATOMIC_DECREMENT_THEN_GET)
#		define z_int128_atomic_decrement_then_get Z_COMPILER_FUNCTION(INT128_ATOMIC_DECREMENT_THEN_GET)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(INT128_ATOMIC_GET_THEN_ADD)
#		define z_int128_atomic_get_then_add Z_COMPILER_FUNCTION(INT128_ATOMIC_GET_THEN_ADD)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(INT128_ATOMIC_GET_THEN_AND)
#		define z_int128_atomic_get_then_and Z_COMPILER_FUNCTION(INT128_ATOMIC_GET_THEN_AND)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(INT128_ATOMIC_GET_THEN_DECREMENT)
#		define z_int128_atomic_get_then_decrement Z_COMPILER_FUNCTION(INT128_ATOMIC_GET_THEN_DECREMENT)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(INT128_ATOMIC_GET_THEN_INCREMENT)
#		define z_int128_atomic_get_then_increment Z_COMPILER_FUNCTION(INT128_ATOMIC_GET_THEN_INCREMENT)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(INT128_ATOMIC_GET_THEN_NAND)
#		define z_int128_atomic_get_then_nand Z_COMPILER_FUNCTION(INT128_ATOMIC_GET_THEN_NAND)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(INT128_ATOMIC_GET_THEN_NOT)
#		define z_int128_atomic_get_then_not Z_COMPILER_FUNCTION(INT128_ATOMIC_GET_THEN_NOT)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(INT128_ATOMIC_GET_THEN_OR)
#		define z_int128_atomic_get_then_or Z_COMPILER_FUNCTION(INT128_ATOMIC_GET_THEN_OR)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(INT128_ATOMIC_GET_THEN_SET)
#		define z_int128_atomic_get_then_set Z_COMPILER_FUNCTION(INT128_ATOMIC_GET_THEN_SET)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(INT128_ATOMIC_GET_THEN_SUBTRACT)
#		define z_int128_atomic_get_then_subtract Z_COMPILER_FUNCTION(INT128_ATOMIC_GET_THEN_SUBTRACT)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(INT128_ATOMIC_GET_THEN_XOR)
#		define z_int128_atomic_get_then_xor Z_COMPILER_FUNCTION(INT128_ATOMIC_GET_THEN_XOR)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(INT128_ATOMIC_INCREMENT_THEN_GET)
#		define z_int128_atomic_increment_then_get Z_COMPILER_FUNCTION(INT128_ATOMIC_INCREMENT_THEN_GET)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(INT128_ATOMIC_NAND_THEN_GET)
#		define z_int128_atomic_nand_then_get Z_COMPILER_FUNCTION(INT128_ATOMIC_NAND_THEN_GET)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(INT128_ATOMIC_NOT_THEN_GET)
#		define z_int128_atomic_not_then_get Z_COMPILER_FUNCTION(INT128_ATOMIC_NOT_THEN_GET)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(INT128_ATOMIC_OR_THEN_GET)
#		define z_int128_atomic_or_then_get Z_COMPILER_FUNCTION(INT128_ATOMIC_OR_THEN_GET)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(INT128_ATOMIC_SET_IF_EQUAL)
#		define z_int128_atomic_set_if_equal Z_COMPILER_FUNCTION(INT128_ATOMIC_SET_IF_EQUAL)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(INT128_ATOMIC_SUBTRACT_THEN_GET)
#		define z_int128_atomic_subtract_then_get Z_COMPILER_FUNCTION(INT128_ATOMIC_SUBTRACT_THEN_GET)
#	endif

#	if Z_COMPILER_HAS_FUNCTION(INT128_ATOMIC_XOR_THEN_GET)
#		define z_int128_atomic_xor_then_get Z_COMPILER_FUNCTION(INT128_ATOMIC_XOR_THEN_GET)
#	endif

#endif


/* MARK: - float16 */


#ifdef Z_FLOAT16
	Z_IMPLEMENTATION_NATURAL(float16)
	Z_IMPLEMENTATION_INTEGER(float16)
	Z_IMPLEMENTATION_REAL(float16, Z_FLOAT16, Z_FLOAT16_EPSILON, Z_FLOAT16_INFINITY)
#endif


/* MARK: - float24 */


#ifdef Z_FLOAT24
	Z_IMPLEMENTATION_NATURAL(float24)
	Z_IMPLEMENTATION_INTEGER(float24)
	Z_IMPLEMENTATION_REAL(float24, Z_FLOAT24, Z_FLOAT24_EPSILON, Z_FLOAT24_INFINITY)
#endif


/* MARK: - float32 */


#ifdef Z_FLOAT32
	Z_IMPLEMENTATION_NATURAL(float32)
	Z_IMPLEMENTATION_INTEGER(float32)
	Z_IMPLEMENTATION_REAL(float32, Z_FLOAT32, Z_FLOAT32_EPSILON, Z_FLOAT32_INFINITY)
#endif

/* MARK: - float48 */


#ifdef Z_FLOAT48
	Z_IMPLEMENTATION_NATURAL(float48)
	Z_IMPLEMENTATION_INTEGER(float48)
	Z_IMPLEMENTATION_REAL(float48, Z_FLOAT48, Z_FLOAT48_EPSILON, Z_FLOAT48_INFINITY)
#endif


/* MARK: - float64 */


#ifdef Z_FLOAT64
	Z_IMPLEMENTATION_NATURAL(float64)
	Z_IMPLEMENTATION_INTEGER(float64)
	Z_IMPLEMENTATION_REAL(float64, Z_FLOAT64, Z_FLOAT64_EPSILON, Z_FLOAT64_INFINITY)
#endif


/* MARK: - float72 */


#ifdef Z_FLOAT72
	Z_IMPLEMENTATION_NATURAL(float72)
	Z_IMPLEMENTATION_INTEGER(float72)
	Z_IMPLEMENTATION_REAL(float72, Z_FLOAT72, Z_FLOAT72_EPSILON, Z_FLOAT72_INFINITY)
#endif


/* MARK: - float80 */


#ifdef Z_FLOAT80
	Z_IMPLEMENTATION_NATURAL(float80)
	Z_IMPLEMENTATION_INTEGER(float80)
	Z_IMPLEMENTATION_REAL(float80, Z_FLOAT80, Z_FLOAT80_EPSILON, Z_FLOAT80_INFINITY)
#endif


/* MARK: - float96 */


#ifdef Z_FLOAT96
	Z_IMPLEMENTATION_NATURAL(float96)
	Z_IMPLEMENTATION_INTEGER(float96)
	Z_IMPLEMENTATION_REAL(float96, Z_FLOAT96, Z_FLOAT96_EPSILON, Z_FLOAT96_INFINITY)
#endif


/* MARK: - float128 */


#ifdef Z_FLOAT128
	Z_IMPLEMENTATION_NATURAL(float128)
	Z_IMPLEMENTATION_INTEGER(float128)
	Z_IMPLEMENTATION_REAL(float128, Z_FLOAT128, Z_FLOAT128_EPSILON, Z_FLOAT128_INFINITY)
#endif


/* MARK: - bint8 */


Z_IMPLEMENTATION_VALUE_REVERSE(bint8, 8, 1)
Z_IMPLEMENTATION_VALUE_REVERSE(bint8, 8, 2)
Z_IMPLEMENTATION_VALUE_REVERSE(bint8, 8, 4)
Z_IMPLEMENTATION_VALUE_ROTATE (bint8, 8)


Z_INLINE zbinttop z_bint8_top_mirror(zbint8 value)
	{return Z_8BIT_TOP_MIRROR(value);}


/* MARK: - bint16 */


Z_IMPLEMENTATION_VALUE_REVERSE(bint16, 16, 1)
Z_IMPLEMENTATION_VALUE_REVERSE(bint16, 16, 2)
Z_IMPLEMENTATION_VALUE_REVERSE(bint16, 16, 4)
Z_IMPLEMENTATION_VALUE_REVERSE(bint16, 16, 8)
Z_IMPLEMENTATION_VALUE_ROTATE (bint16, 16)


#define z_bint16_reverse z_bint16_reverse_in_8bit

#if Z_BINT16_ENDIANNESS == Z_ENDIANNESS_BIG

#	define z_bint16_big_endian    Z_SAME
#	define z_bint16_little_endian z_bint16_reverse

#elif Z_BINT16_ENDIANNESS == Z_ENDIANNESS_LITTLE

#	define z_bint16_big_endian    z_bint16_reverse
#	define z_bint16_little_endian Z_SAME

#endif


#if Z_BINTTOP_BITS > 16

	Z_INLINE zbinttop z_bint16_top_mirror(zbint16 value)
		{return Z_16BIT_TOP_MIRROR(value);}

#	if Z_BINTTOP_ENDIANNESS == Z_BINT16_ENDIANNESS

#		define z_bint16_top_packet z_bint16_top_mirror

#	elif	(Z_BINTTOP_ENDIANNESS == Z_ENDIANNESS_BIG     && \
		 Z_BINT16_ENDIANNESS  == Z_ENDIANNESS_LITTLE) || \
		(Z_BINTTOP_ENDIANNESS == Z_ENDIANNESS_LITTLE  && \
		 Z_BINT16_ENDIANNESS  == Z_ENDIANNESS_BIG)

		Z_INLINE zbinttop z_bint16_top_packet(zbint16 value)
			{return Z_16BIT_TOP_MIRROR(z_bint16_reverse(value));}
#	endif
#endif


/* MARK: - bint32 */


Z_IMPLEMENTATION_VALUE_REVERSE(bint32, 32,  1)
Z_IMPLEMENTATION_VALUE_REVERSE(bint32, 32,  2)
Z_IMPLEMENTATION_VALUE_REVERSE(bint32, 32,  4)
Z_IMPLEMENTATION_VALUE_REVERSE(bint32, 32,  8)
Z_IMPLEMENTATION_VALUE_REVERSE(bint32, 32, 16)
Z_IMPLEMENTATION_VALUE_ROTATE (bint32, 32)


#define z_bint32_reverse z_bint32_reverse_in_8bit

#if Z_BINT32_ENDIANNESS == Z_ENDIANNESS_BIG

#	define z_bint32_big_endian    Z_SAME
#	define z_bint32_little_endian z_bint32_reverse

#elif Z_BINT32_ENDIANNESS == Z_ENDIANNESS_LITTLE

#	define z_bint32_big_endian    z_bint32_reverse
#	define z_bint32_little_endian Z_SAME

#endif


#if Z_BINTTOP_BITS > 32

	Z_INLINE zbinttop z_bint32_top_mirror(zbint32 value)
		{return Z_32BIT_TOP_MIRROR(value);}

#	if Z_BINTTOP_ENDIANNESS == Z_BINT32_ENDIANNESS

#		define z_bint32_top_packet z_bint32_top_mirror

#	elif	(Z_BINTTOP_ENDIANNESS == Z_ENDIANNESS_BIG     && \
		 Z_BINT32_ENDIANNESS  == Z_ENDIANNESS_LITTLE) || \
		(Z_BINTTOP_ENDIANNESS == Z_ENDIANNESS_LITTLE  && \
		 Z_BINT32_ENDIANNESS  == Z_ENDIANNESS_BIG)

		Z_INLINE zbinttop z_bint32_top_packet(zbint32 value)
			{return Z_32BIT_TOP_MIRROR(z_bint32_reverse(value));}
#	endif

#endif


/* MARK: - bint64 */


#ifdef Z_BINT64

	Z_IMPLEMENTATION_VALUE_REVERSE(bint64, 64,  1)
	Z_IMPLEMENTATION_VALUE_REVERSE(bint64, 64,  2)
	Z_IMPLEMENTATION_VALUE_REVERSE(bint64, 64,  4)
	Z_IMPLEMENTATION_VALUE_REVERSE(bint64, 64,  8)
	Z_IMPLEMENTATION_VALUE_REVERSE(bint64, 64, 16)
	Z_IMPLEMENTATION_VALUE_REVERSE(bint64, 64, 32)
	Z_IMPLEMENTATION_VALUE_ROTATE (bint64, 64)


#	define z_bint64_reverse z_bint64_reverse_in_8bit

#	if Z_BINT64_ENDIANNESS == Z_ENDIANNESS_BIG

#		define z_bint64_big_endian    Z_SAME
#		define z_bint64_little_endian z_bint64_reverse

#	elif Z_BINT64_ENDIANNESS == Z_ENDIANNESS_LITTLE

#		define z_bint64_big_endian    z_bint64_reverse
#		define z_bint64_little_endian Z_SAME

#	endif


#	if Z_BINTTOP_BITS > 64
	
		Z_INLINE zbinttop z_bint64_top_mirror(zbint64 value)
			{return Z_64BIT_TOP_MIRROR(value);}
	
#		if Z_BINTTOP_ENDIANNESS == Z_BINT64_ENDIANNESS
	
#			define z_bint64_top_packet z_bint64_top_mirror
	
#		elif	(Z_BINTTOP_ENDIANNESS == Z_ENDIANNESS_BIG     && \
			 Z_BINT64_ENDIANNESS  == Z_ENDIANNESS_LITTLE) || \
			(Z_BINTTOP_ENDIANNESS == Z_ENDIANNESS_LITTLE  && \
			 Z_BINT64_ENDIANNESS  == Z_ENDIANNESS_BIG)
	
			Z_INLINE zbinttop z_bint64_top_packet(zbint64 value)
				{return Z_64BIT_TOP_MIRROR(z_bint64_reverse(value));}
#		endif
#	endif

#endif


/* MARK: - bint128 */


#ifdef Z_BINT128

	Z_IMPLEMENTATION_VALUE_REVERSE(bint128, 128,  1)
	Z_IMPLEMENTATION_VALUE_REVERSE(bint128, 128,  2)
	Z_IMPLEMENTATION_VALUE_REVERSE(bint128, 128,  4)
	Z_IMPLEMENTATION_VALUE_REVERSE(bint128, 128,  8)
	Z_IMPLEMENTATION_VALUE_REVERSE(bint128, 128, 16)
	Z_IMPLEMENTATION_VALUE_REVERSE(bint128, 128, 32)
	Z_IMPLEMENTATION_VALUE_REVERSE(bint128, 128, 64)
	Z_IMPLEMENTATION_VALUE_ROTATE (bint128, 128)


#	define z_bint128_reverse z_bint128_reverse_in_8bit

#	if Z_BINT128_ENDIANNESS == Z_ENDIANNESS_BIG

#		define z_bint128_big_endian    Z_SAME
#		define z_bint128_little_endian z_bint128_reverse

#	elif Z_BINT128_ENDIANNESS == Z_ENDIANNESS_LITTLE

#		define z_bint128_big_endian    z_bint128_reverse
#		define z_bint128_little_endian Z_SAME

#	endif

#endif


/* MARK: - Function selectors */


#define z_type_addition_overflows(	  TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _addition_overflows	   )
#define z_type_addition_overflows_3(	  TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _addition_overflows_3	   )
#define z_type_addition_overflows_4(	  TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _addition_overflows_4	   )
#define z_type_atomic_add_then_get(	  TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _atomic_add_then_get	   )
#define z_type_atomic_and_then_get(	  TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _atomic_and_then_get	   )
#define z_type_atomic_decrement_then_get( TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _atomic_decrement_then_get)
#define z_type_atomic_get_then_add(	  TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _atomic_get_then_add	   )
#define z_type_atomic_get_then_and(	  TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _atomic_get_then_and	   )
#define z_type_atomic_get_then_decrement( TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _atomic_get_then_decrement)
#define z_type_atomic_get_then_increment( TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _atomic_get_then_increment)
#define z_type_atomic_get_then_nand(	  TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _atomic_get_then_nand	   )
#define z_type_atomic_get_then_not(	  TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _atomic_get_then_not	   )
#define z_type_atomic_get_then_or(	  TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _atomic_get_then_or	   )
#define z_type_atomic_get_then_set(	  TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _atomic_get_then_set	   )
#define z_type_atomic_get_then_subtract(  TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _atomic_get_then_subtract )
#define z_type_atomic_get_then_xor(	  TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _atomic_get_then_xor	   )
#define z_type_atomic_increment_then_get( TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _atomic_increment_then_get)
#define z_type_atomic_nand_then_get(	  TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _atomic_nand_then_get	   )
#define z_type_atomic_not_then_get(	  TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _atomic_not_then_get	   )
#define z_type_atomic_or_then_get(	  TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _atomic_or_then_get	   )
#define z_type_atomic_set_if_equal(	  TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _atomic_set_if_equal	   )
#define z_type_atomic_subtract_then_get(  TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _atomic_subtract_then_get )
#define z_type_atomic_xor_then_get(	  TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _atomic_xor_then_get	   )
#define z_type_big_endian(		  TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _big_endian		   )
#define z_type_little_endian(		  TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _little_endian		   )
#define z_type_minimum_storage_size(	  TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _minimum_storage_size	   )
#define z_type_multiplication_overflows(  TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _addition_overflows	   )
#define z_type_multiplication_overflows_3(TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _addition_overflows_3	   )
#define z_type_multiplication_overflows_4(TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _addition_overflows_4	   )
#define z_type_subtraction_overflows(	  TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _subtraction_overflows	   )
#define z_type_subtraction_overflows_3(	  TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _subtraction_overflows_3  )
#define z_type_subtraction_overflows_4(	  TYPE) Z_INSERT_##TYPE##_fixed_type(z_, _subtraction_overflows_4  )


/* MARK: - Default real type definitions */


#ifdef Z_REAL
#	define z_absolute	  z_type_absolute	 (REAL)
#	define z_are_almost_equal z_type_are_almost_equal(REAL)
#	define z_clamp		  z_type_clamp		 (REAL)
#	define z_clamp_01	  z_type_clamp_01	 (REAL)
#	define z_inverse_lerp	  z_type_inverse_lerp	 (REAL)
#	define z_is_almost_zero	  z_type_is_almost_zero	 (REAL)
#	define z_is_finite	  z_type_is_finite	 (REAL)
#	define z_is_infinity	  z_type_is_infinity	 (REAL)
#	define z_is_nan		  z_type_is_nan		 (REAL)
#	define z_lerp		  z_type_lerp		 (REAL)
#	define z_maximum	  z_type_maximum	 (REAL)
#	define z_minimum	  z_type_minimum	 (REAL)
#	define z_sign		  z_type_sign		 (REAL)
#	define z_sign_or_zero	  z_type_sign_or_zero	 (REAL)
#	define z_smootherstep	  z_type_smootherstep	 (REAL)
#	define z_smoothstep	  z_type_smoothstep	 (REAL)
#endif


#endif /* __Z_functions_base_value_H__ */
