/* Q API - functions/base/value.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2014 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_functions_base_value_H__
#define __Q_functions_base_value_H__

#include <Q/macros/value.h>


/* MARK: - Reversion */


#define Q_IMPLEMENTATION_VALUE_REVERSED(bits, level)				\
										\
Q_INLINE quint##bits q_uint##bits##_reversed_in_##level##bit(quint##bits value)	\
	{return Q_##bits##BIT_REVERSED_IN_##level##BIT(value);}			\
										\
Q_INLINE qint##bits q_int##bits##_reversed_in_##level##bit(qint##bits value)	\
	{return Q_##bits##BIT_REVERSED_IN_##level##BIT(value);}


Q_IMPLEMENTATION_VALUE_REVERSED( 8,  1)
Q_IMPLEMENTATION_VALUE_REVERSED( 8,  2)
Q_IMPLEMENTATION_VALUE_REVERSED( 8,  4)
Q_IMPLEMENTATION_VALUE_REVERSED(16,  1)
Q_IMPLEMENTATION_VALUE_REVERSED(16,  2)
Q_IMPLEMENTATION_VALUE_REVERSED(16,  4)
Q_IMPLEMENTATION_VALUE_REVERSED(16,  8)
Q_IMPLEMENTATION_VALUE_REVERSED(32,  1)
Q_IMPLEMENTATION_VALUE_REVERSED(32,  2)
Q_IMPLEMENTATION_VALUE_REVERSED(32,  4)
Q_IMPLEMENTATION_VALUE_REVERSED(32,  8)
Q_IMPLEMENTATION_VALUE_REVERSED(32, 16)
Q_IMPLEMENTATION_VALUE_REVERSED(64,  1)
Q_IMPLEMENTATION_VALUE_REVERSED(64,  2)
Q_IMPLEMENTATION_VALUE_REVERSED(64,  4)
Q_IMPLEMENTATION_VALUE_REVERSED(64,  8)
Q_IMPLEMENTATION_VALUE_REVERSED(64, 16)
Q_IMPLEMENTATION_VALUE_REVERSED(64, 32)

#define q_uint8_reversed  Q_SAME
#define q_uint16_reversed q_uint16_reversed_in_8bit
#define q_uint32_reversed q_uint32_reversed_in_8bit
#define q_uint64_reversed q_uint64_reversed_in_8bit
#define q_int8_reversed   Q_SAME
#define q_int16_reversed  q_int16_reversed_in_8bit
#define q_int32_reversed  q_int32_reversed_in_8bit
#define q_int64_reversed  q_int64_reversed_in_8bit

#if Q_IS_AVAILABLE(UINT128)

	Q_IMPLEMENTATION_VALUE_REVERSED(128,  1)
	Q_IMPLEMENTATION_VALUE_REVERSED(128,  2)
	Q_IMPLEMENTATION_VALUE_REVERSED(128,  4)
	Q_IMPLEMENTATION_VALUE_REVERSED(128,  8)
	Q_IMPLEMENTATION_VALUE_REVERSED(128, 16)
	Q_IMPLEMENTATION_VALUE_REVERSED(128, 32)
	Q_IMPLEMENTATION_VALUE_REVERSED(128, 64)

#	define q_uint128_reversed q_uint128_reversed_in_8bit
#	define q_int128_reversed  q_int128_reversed_in_8bit

#endif

#define q_value_reversed(TYPE) Q_JOIN_3(q_, Q_##TYPE##_FIXED_TYPE_name, _reversed)


/* MARK: - Rotation */


#define Q_IMPLEMENTATION_VALUE_ROTATED(bits)					\
										\
Q_INLINE									\
quint##bits q_uint##bits##_rotated_left(quint##bits value, quint rotation)	\
	{return Q_##bits##BIT_ROTATE_LEFT(value, rotation);}			\
										\
Q_INLINE									\
quint##bits q_uint##bits##_rotated_right(quint##bits value, quint rotation)	\
	{return Q_##bits##BIT_ROTATE_RIGHT(value, rotation);}			\
										\
Q_INLINE									\
qint##bits q_int##bits##_rotated_left(qint##bits value, quint rotation)		\
	{return Q_##bits##BIT_ROTATE_LEFT(value, rotation);}			\
										\
Q_INLINE									\
qint##bits q_int##bits##_rotated_right(qint##bits value, quint rotation)	\
	{return Q_##bits##BIT_ROTATE_RIGHT(value, rotation);}			\


Q_IMPLEMENTATION_VALUE_ROTATED( 8)
Q_IMPLEMENTATION_VALUE_ROTATED(16)
Q_IMPLEMENTATION_VALUE_ROTATED(32)
Q_IMPLEMENTATION_VALUE_ROTATED(64)

#define q_value_rotated_left( TYPE) Q_JOIN_3(q_, Q_##TYPE##_FIXED_TYPE_name, _rotated_left )
#define q_value_rotated_right(TYPE) Q_JOIN_3(q_, Q_##TYPE##_FIXED_TYPE_name, _rotated_right)


/* MARK: - Endianness */


#if Q_INT16_ENDIANNESS == Q_ENDIANNESS_BIG

#	define q_uint16_big_endian    Q_SAME
#	define q_int16_big_endian     Q_SAME
#	define q_uint16_little_endian q_uint16_reversed
#	define q_int16_little_endian  q_int16_reversed

#elif Q_INT16_ENDIANNESS == Q_ENDIANNESS_LITTLE

#	define q_uint16_big_endian    q_uint16_reversed
#	define q_int16_big_endian     q_int16_reversed
#	define q_uint16_little_endian Q_SAME
#	define q_int16_little_endian  Q_SAME

#endif

#if Q_INT32_ENDIANNESS == Q_ENDIANNESS_BIG

#	define q_uint32_big_endian    Q_SAME
#	define q_int32_big_endian     Q_SAME
#	define q_uint32_little_endian q_uint32_reversed
#	define q_int32_little_endian  q_int32_reversed

#elif Q_INT32_ENDIANNESS == Q_ENDIANNESS_LITTLE

#	define q_uint32_big_endian    q_uint32_reversed
#	define q_int32_big_endian     q_int32_reversed
#	define q_uint32_little_endian Q_SAME
#	define q_int32_little_endian  Q_SAME

#endif

#if Q_INT64_ENDIANNESS == Q_ENDIANNESS_BIG

#	define q_uint64_big_endian    Q_SAME
#	define q_int64_big_endian     Q_SAME
#	define q_uint64_little_endian q_uint64_reversed
#	define q_int64_little_endian  q_int64_reversed

#elif Q_INT64_ENDIANNESS == Q_ENDIANNESS_LITTLE

#	define q_uint64_big_endian    q_uint64_reversed
#	define q_int64_big_endian     q_int64_reversed
#	define q_uint64_little_endian Q_SAME
#	define q_int64_little_endian  Q_SAME

#endif

#if Q_IS_AVAILABLE(UINT128)
#	if Q_UINT128_ENDIANNESS == Q_ENDIANNESS_BIG

#		define q_uint128_big_endian    Q_SAME
#		define q_uint128_little_endian q_uint128_reversed

#	elif Q_UINT128_ENDIANNESS == Q_ENDIANNESS_LITTLE

#		define q_uint128_big_endian    q_uint128_reversed
#		define q_uint128_little_endian Q_SAME

#	endif
#endif

#if Q_IS_AVAILABLE(INT128)
#	if Q_INT128_ENDIANNESS == Q_ENDIANNESS_BIG

#		define q_int128_big_endian     Q_SAME
#		define q_int128_little_endian  q_int128_reversed

#	elif Q_INT128_ENDIANNESS == Q_ENDIANNESS_LITTLE

#		define q_int128_big_endian     q_int128_reversed
#		define q_int128_little_endian  Q_SAME

#	endif
#endif

#define q_value_big_endian(   TYPE) Q_JOIN_3(q_, Q_##TYPE##_FIXED_TYPE_name, _big_endian   )
#define q_value_little_endian(TYPE) Q_JOIN_3(q_, Q_##TYPE##_FIXED_TYPE_name, _little_endian)


/* MARK: - Mirroring */


Q_INLINE quinttop q_uint8_top_mirror(quint8 value)
	{return Q_8BIT_TOP_MIRROR(value);}


#if Q_UINTTOP_BITS > 16

	Q_INLINE quinttop q_uint16_top_mirror(quint16 value)
		{return Q_16BIT_TOP_MIRROR(value);}

#	if Q_UINTTOP_ENDIANNESS == Q_UINT16_ENDIANNESS

#		define q_uint16_top_packet q_uint16_top_mirror

#	elif	(Q_UINTTOP_ENDIANNESS == Q_ENDIANNESS_BIG     && \
		 Q_UINT16_ENDIANNESS  == Q_ENDIANNESS_LITTLE) || \
		(Q_UINTTOP_ENDIANNESS == Q_ENDIANNESS_LITTLE  && \
		 Q_UINT16_ENDIANNESS  == Q_ENDIANNESS_BIG)

		Q_INLINE quinttop q_uint16_top_packet(quint16 value)
			{return Q_16BIT_TOP_MIRROR(q_uint16_reversed(value));}
#	endif
#endif


#if Q_UINTTOP_BITS > 32

	Q_INLINE quinttop q_uint32_top_mirror(quint32 value)
		{return Q_32BIT_TOP_MIRROR(value);}

#	if Q_UINTTOP_ENDIANNESS == Q_UINT32_ENDIANNESS

#		define q_uint32_top_packet q_uint32_top_mirror

#	elif	(Q_UINTTOP_ENDIANNESS == Q_ENDIANNESS_BIG     && \
		 Q_UINT32_ENDIANNESS  == Q_ENDIANNESS_LITTLE) || \
		(Q_UINTTOP_ENDIANNESS == Q_ENDIANNESS_LITTLE  && \
		 Q_UINT32_ENDIANNESS  == Q_ENDIANNESS_BIG)

		Q_INLINE quinttop q_uint32_top_packet(quint32 value)
			{return Q_32BIT_TOP_MIRROR(q_uint32_reversed(value));}
#	endif
#endif


#if Q_UINTTOP_BITS > 64

	Q_INLINE quinttop q_uint64_top_mirror(quint64 value)
		{return Q_64BIT_TOP_MIRROR(value);}

#	if Q_UINTTOP_ENDIANNESS == Q_UINT64_ENDIANNESS

#		define q_uint64_top_packet q_uint64_top_mirror

#	elif	(Q_UINTTOP_ENDIANNESS == Q_ENDIANNESS_BIG     && \
		 Q_UINT64_ENDIANNESS  == Q_ENDIANNESS_LITTLE) || \
		(Q_UINTTOP_ENDIANNESS == Q_ENDIANNESS_LITTLE  && \
		 Q_UINT64_ENDIANNESS  == Q_ENDIANNESS_BIG)

		Q_INLINE quinttop q_uint64_top_packet(quint64 value)
			{return Q_64BIT_TOP_MIRROR(q_uint64_reversed(value));}
#	endif
#endif


/* MARK: - Binary codified decimal */


Q_INLINE quint32 q_uint32_to_bcd(quint32 value)
	{
	quint32 result = 0;
	quint	shift  = 0;

	for (; value; value /= 10, shift += 4)
		result |= (value % 10) << shift;

	return result;
	}


Q_INLINE quint32 q_bcd_to_uint32(quint32 value)
	{
	quint32 result = 0;
	quint32 scale  = 1;

	for (; value; value >>= 4, scale *= 10)
		result += (value & 0x0F) * scale;

	return result;
	}


/* MARK: - Operations for natural, integer and real types */


#define Q_IMPLEMENTATION_VALUE_NATURAL(type)					\
										\
										\
Q_INLINE void q_##type##_swap(void *a, void *b)					\
	{									\
	q##type t = *(q##type *)a;						\
										\
	*(q##type *)a = *(q##type *)b;						\
	*(q##type *)b = t;							\
	}									\
										\
										\
Q_INLINE q##type q_##type##_minimum(q##type a, q##type b)			\
	{return Q_MINIMUM(a, b);}						\
										\
										\
Q_INLINE q##type q_##type##_maximum(q##type a, q##type b)			\
	{return Q_MAXIMUM(a, b);}						\
										\
										\
Q_INLINE									\
q##type q_##type##_clamp(q##type value, q##type minimum, q##type maximum)	\
	{									\
	return q_##type##_minimum						\
		(q_##type##_maximum(value, minimum), maximum);			\
	}									\


Q_IMPLEMENTATION_VALUE_NATURAL(uint8  )
Q_IMPLEMENTATION_VALUE_NATURAL(uint16 )
Q_IMPLEMENTATION_VALUE_NATURAL(uint32 )
Q_IMPLEMENTATION_VALUE_NATURAL(uint64 )
Q_IMPLEMENTATION_VALUE_NATURAL(int8   )
Q_IMPLEMENTATION_VALUE_NATURAL(int16  )
Q_IMPLEMENTATION_VALUE_NATURAL(int32  )
Q_IMPLEMENTATION_VALUE_NATURAL(int64  )
Q_IMPLEMENTATION_VALUE_NATURAL(float  )
Q_IMPLEMENTATION_VALUE_NATURAL(double )
Q_IMPLEMENTATION_VALUE_NATURAL(ldouble)

#define q_value_swap(   TYPE) Q_JOIN_3(q_, Q_##TYPE##_FIXED_TYPE_name, _swap   )
#define q_value_minimum(TYPE) Q_JOIN_3(q_, Q_##TYPE##_FIXED_TYPE_name, _minimum)
#define q_value_maximum(TYPE) Q_JOIN_3(q_, Q_##TYPE##_FIXED_TYPE_name, _maximum)
#define q_value_clamp(  TYPE) Q_JOIN_3(q_, Q_##TYPE##_FIXED_TYPE_name, _clamp  )


/* MARK: - Operations for integer and real types */


#define Q_IMPLEMENTATION_VALUE_INTEGER(type)			 \
								 \
Q_INLINE q##type q_##type##_absolute(q##type value)		 \
	{return value < (q##type)0 ? -value : value;}		 \
								 \
Q_INLINE q##type q_##type##_sign(q##type value)			 \
	{return value >= (q##type)0 ? (q##type)1 : -(q##type)1;}


Q_IMPLEMENTATION_VALUE_INTEGER(int8   )
Q_IMPLEMENTATION_VALUE_INTEGER(int16  )
Q_IMPLEMENTATION_VALUE_INTEGER(int32  )
Q_IMPLEMENTATION_VALUE_INTEGER(int64  )
Q_IMPLEMENTATION_VALUE_INTEGER(ssize  )
Q_IMPLEMENTATION_VALUE_INTEGER(float  )
Q_IMPLEMENTATION_VALUE_INTEGER(double )
Q_IMPLEMENTATION_VALUE_INTEGER(ldouble)

#define q_value_absolute(TYPE) Q_JOIN_3(q_, Q_##TYPE##_FIXED_TYPE_name, _absolute)
#define q_value_sign(	 TYPE) Q_JOIN_3(q_, Q_##TYPE##_FIXED_TYPE_name, _sign	 )


/* MARK: - Operations for real types only */


#define Q_IMPLEMENTATION_VALUE_REAL(type, _, epsilon, infinity)			\
										\
										\
Q_INLINE qboolean q_##type##_are_almost_equal(q##type a, q##type b)		\
	{return q_##type##_absolute(a - b) <= epsilon;}				\
										\
										\
Q_INLINE q##type q_##type##_lerp(q##type a, q##type b, q##type t)		\
	{return a + t * (b - a);}						\
										\
										\
Q_INLINE q##type q_##type##_inverse_lerp(q##type a, q##type b, q##type t)	\
	{return (t - a) / (b - a);}						\
										\
										\
Q_INLINE q##type q_##type##_smoothstep(q##type a, q##type b, q##type t)		\
	{									\
	if (t <= a) return _(0.0);						\
	if (t >= b) return _(1.0);						\
	t = (t - a) / (b - a);							\
	return t * t * (_(3.0) - _(2.0) * t);					\
	}									\
										\
										\
Q_INLINE q##type q_##type##_smootherstep(q##type a, q##type b, q##type t)	\
	{									\
	if (t <= a) return _(0.0);						\
	if (t >= b) return _(1.0);						\
	t = (t - a) / (b - a);							\
	return t * t * t * (t * (t * _(6.0) - _(15.0)) + _(10.0));		\
	}									\
										\
										\
Q_INLINE qboolean q_##type##_is_almost_zero(q##type value)			\
	{return q_##type##_absolute(value) <= epsilon;}				\
										\
										\
Q_INLINE qboolean q_##type##_is_finite(q##type value)				\
	{return value == value && value != infinity && value != -infinity;}	\
										\
										\
Q_INLINE qboolean q_##type##_is_infinity(q##type value)				\
	{return value == infinity || value == -infinity;}			\
										\
										\
Q_INLINE qboolean q_##type##_is_nan(q##type value)				\
	{return !(value == value);}						\
										\
										\
Q_INLINE q##type q_##type##_sign_or_zero(q##type value)				\
	{									\
	return q_##type##_absolute(value) <= epsilon				\
		? _(0.0) : q_##type##_sign(value);				\
	}									\
										\
										\
Q_INLINE q##type q_##type##_clamp_01(q##type value)				\
	{return q_##type##_minimum(q_##type##_maximum(value, _(0.0)), _(1.0));}


Q_IMPLEMENTATION_VALUE_REAL(float,   Q_FLOAT,	Q_FLOAT_EPSILON,   Q_FLOAT_INFINITY  )
Q_IMPLEMENTATION_VALUE_REAL(double,  Q_DOUBLE,	Q_DOUBLE_EPSILON,  Q_DOUBLE_INFINITY )
Q_IMPLEMENTATION_VALUE_REAL(ldouble, Q_LDOUBLE, Q_LDOUBLE_EPSILON, Q_LDOUBLE_INFINITY)


/* MARK: - Default real type definitions */


#if defined(Q_USE_REAL_FLOAT)

#	define q_are_almost_equal q_float_are_almost_equal
#	define q_minimum	  q_float_minimum
#	define q_maximum	  q_float_maximum
#	define q_lerp		  q_float_lerp
#	define q_inverse_lerp	  q_float_inverse_lerp
#	define q_smoothstep	  q_float_smoothstep
#	define q_smootherstep	  q_float_smootherstep
#	define q_is_almost_zero	  q_float_is_almost_zero
#	define q_is_finite	  q_float_is_finite
#	define q_is_infinity	  q_float_is_infinity
#	define q_is_nan		  q_float_is_nan
#	define q_absolute	  q_float_absolute
#	define q_sign		  q_float_sign
#	define q_sign_or_zero	  q_float_sign_or_zero
#	define q_clamp		  q_float_clamp
#	define q_clamp_01	  q_float_clamp_01

#elif defined(Q_USE_REAL_LDOUBLE)

#	define q_are_almost_equal q_ldouble_are_almost_equal
#	define q_minimum	  q_ldouble_minimum
#	define q_maximum	  q_ldouble_maximum
#	define q_lerp		  q_ldouble_lerp
#	define q_inverse_lerp	  q_ldouble_inverse_lerp
#	define q_smoothstep	  q_ldouble_smoothstep
#	define q_smootherstep	  q_ldouble_smootherstep
#	define q_is_almost_zero	  q_ldouble_is_almost_zero
#	define q_is_finite	  q_ldouble_is_finite
#	define q_is_infinity	  q_ldouble_is_infinity
#	define q_is_nan		  q_ldouble_is_nan
#	define q_absolute	  q_ldouble_absolute
#	define q_sign		  q_ldouble_sign
#	define q_sign_or_zero	  q_ldouble_sign_or_zero
#	define q_clamp		  q_ldouble_clamp
#	define q_clamp_01	  q_ldouble_clamp_01

#else

#	define q_are_almost_equal q_double_are_almost_equal
#	define q_minimum	  q_double_minimum
#	define q_maximum	  q_double_maximum
#	define q_lerp		  q_double_lerp
#	define q_inverse_lerp	  q_double_inverse_lerp
#	define q_smoothstep	  q_double_smoothstep
#	define q_smootherstep	  q_double_smootherstep
#	define q_is_almost_zero	  q_double_is_almost_zero
#	define q_is_finite	  q_double_is_finite
#	define q_is_infinity	  q_double_is_infinity
#	define q_is_nan		  q_double_is_nan
#	define q_absolute	  q_double_absolute
#	define q_sign		  q_double_sign
#	define q_sign_or_zero	  q_double_sign_or_zero
#	define q_clamp		  q_double_clamp
#	define q_clamp_01	  q_double_clamp_01

#endif


/* MARK: - Atomic operations */


#if Q_CPU_IS_CAPABLE_OF(8BIT_ATOMICS)

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_8BIT_ATOMIC_SET_BIT)
		Q_ASSEMBLY_IMPLEMENTATION_8BIT_ATOMIC_SET_BIT
#		define Q_AVAILABLE_8BIT_ATOMIC_SET_BIT
#	elif Q_COMPILER_HAS_FUNCTION(8BIT_ATOMIC_SET_BIT)
#		define q_8bit_atomic_set_bit Q_COMPILER_FUNCTION_8BIT_ATOMIC_SET_BIT
#		define Q_AVAILABLE_8BIT_ATOMIC_SET_BIT
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_8BIT_ATOMIC_CLEAR_BIT)
		Q_ASSEMBLY_IMPLEMENTATION_8BIT_ATOMIC_CLEAR_BIT
#		define Q_AVAILABLE_8BIT_ATOMIC_CLEAR_BIT
#	elif Q_COMPILER_HAS_FUNCTION(8BIT_ATOMIC_CLEAR_BIT)
#		define q_8bit_atomic_clear_bit Q_COMPILER_FUNCTION_8BIT_ATOMIC_CLEAR_BIT
#		define Q_AVAILABLE_8BIT_ATOMIC_CLEAR_BIT
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_SET_IF_EQUAL)
		Q_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_SET_IF_EQUAL
#		define Q_AVAILABLE_UINT8_ATOMIC_SET_IF_EQUAL
#	elif Q_COMPILER_HAS_FUNCTION(UINT8_ATOMIC_SET_IF_EQUAL)
#		define q_uint8_atomic_set_if_equal Q_COMPILER_FUNCTION_UINT8_ATOMIC_SET_IF_EQUAL
#		define Q_AVAILABLE_UINT8_ATOMIC_SET_IF_EQUAL
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_GET_THEN_INCREMENT)
		Q_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_GET_THEN_INCREMENT
#		define Q_AVAILABLE_UINT8_ATOMIC_GET_THEN_INCREMENT
#	elif Q_COMPILER_HAS_FUNCTION(UINT8_ATOMIC_GET_THEN_INCREMENT)
#		define q_uint8_atomic_get_then_increment Q_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_INCREMENT
#		define Q_AVAILABLE_UINT8_ATOMIC_GET_THEN_INCREMENT
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_GET_THEN_DECREMENT)
		Q_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_GET_THEN_DECREMENT
#		define Q_AVAILABLE_UINT8_ATOMIC_GET_THEN_DECREMENT
#	elif Q_COMPILER_HAS_FUNCTION(UINT8_ATOMIC_GET_THEN_DECREMENT)
#		define q_uint8_atomic_get_then_decrement Q_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_DECREMENT
#		define Q_AVAILABLE_UINT8_ATOMIC_GET_THEN_DECREMENT
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_GET_THEN_ADD)
		Q_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_GET_THEN_ADD
#		define Q_AVAILABLE_UINT8_ATOMIC_GET_THEN_ADD
#	elif Q_COMPILER_HAS_FUNCTION(UINT8_ATOMIC_GET_THEN_ADD)
#		define q_uint8_atomic_get_then_add Q_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_ADD
#		define Q_AVAILABLE_UINT8_ATOMIC_GET_THEN_ADD
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_GET_THEN_SUBTRACT)
		Q_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_GET_THEN_SUBTRACT
#		define Q_AVAILABLE_UINT8_ATOMIC_GET_THEN_SUBTRACT
#	elif Q_COMPILER_HAS_FUNCTION(UINT8_ATOMIC_GET_THEN_SUBTRACT)
#		define q_uint8_atomic_get_then_subtract Q_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_SUBTRACT
#		define Q_AVAILABLE_UINT8_ATOMIC_GET_THEN_SUBTRACT
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_GET_THEN_AND)
		Q_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_GET_THEN_AND
#		define Q_AVAILABLE_UINT8_ATOMIC_GET_THEN_AND
#	elif Q_COMPILER_HAS_FUNCTION(UINT8_ATOMIC_GET_THEN_AND)
#		define q_uint8_atomic_get_then_and Q_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_AND
#		define Q_AVAILABLE_UINT8_ATOMIC_GET_THEN_AND
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_GET_THEN_OR)
		Q_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_GET_THEN_OR
#		define Q_AVAILABLE_UINT8_ATOMIC_GET_THEN_OR
#	elif Q_COMPILER_HAS_FUNCTION(UINT8_ATOMIC_GET_THEN_OR)
#		define q_uint8_atomic_get_then_or Q_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_OR
#		define Q_AVAILABLE_UINT8_ATOMIC_GET_THEN_OR
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_GET_THEN_XOR)
		Q_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_GET_THEN_XOR
#		define Q_AVAILABLE_UINT8_ATOMIC_GET_THEN_XOR
#	elif Q_COMPILER_HAS_FUNCTION(UINT8_ATOMIC_GET_THEN_XOR)
#		define q_uint8_atomic_get_then_xor Q_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_XOR
#		define Q_AVAILABLE_UINT8_ATOMIC_GET_THEN_XOR
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_GET_THEN_NOT)
		Q_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_GET_THEN_NOT
#		define Q_AVAILABLE_UINT8_ATOMIC_GET_THEN_NOT
#	elif Q_COMPILER_HAS_FUNCTION(UINT8_ATOMIC_GET_THEN_NOT)
#		define q_uint8_atomic_get_then_not Q_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_NOT
#		define Q_AVAILABLE_UINT8_ATOMIC_GET_THEN_NOT
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_INCREMENT_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_INCREMENT_THEN_GET
#		define Q_AVAILABLE_UINT8_ATOMIC_INCREMENT_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(UINT8_ATOMIC_INCREMENT_THEN_GET)
#		define q_uint8_atomic_increment_then_get Q_COMPILER_FUNCTION_UINT8_ATOMIC_INCREMENT_THEN_GET
#		define Q_AVAILABLE_UINT8_ATOMIC_INCREMENT_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_DECREMENT_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_DECREMENT_THEN_GET
#		define Q_AVAILABLE_UINT8_ATOMIC_DECREMENT_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(UINT8_ATOMIC_DECREMENT_THEN_GET)
#		define q_uint8_atomic_decrement_then_get Q_COMPILER_FUNCTION_UINT8_ATOMIC_DECREMENT_THEN_GET
#		define Q_AVAILABLE_UINT8_ATOMIC_DECREMENT_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_ADD_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_ADD_THEN_GET
#		define Q_AVAILABLE_UINT8_ATOMIC_ADD_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(UINT8_ATOMIC_ADD_THEN_GET)
#		define q_uint8_atomic_add_then_get Q_COMPILER_FUNCTION_UINT8_ATOMIC_ADD_THEN_GET
#		define Q_AVAILABLE_UINT8_ATOMIC_ADD_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_SUBTRACT_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_SUBTRACT_THEN_GET
#		define Q_AVAILABLE_UINT8_ATOMIC_SUBTRACT_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(UINT8_ATOMIC_SUBTRACT_THEN_GET)
#		define q_uint8_atomic_subtract_then_get Q_COMPILER_FUNCTION_UINT8_ATOMIC_SUBTRACT_THEN_GET
#		define Q_AVAILABLE_UINT8_ATOMIC_SUBTRACT_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_AND_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_AND_THEN_GET
#		define Q_AVAILABLE_UINT8_ATOMIC_AND_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(UINT8_ATOMIC_AND_THEN_GET)
#		define q_uint8_atomic_and_then_get Q_COMPILER_FUNCTION_UINT8_ATOMIC_AND_THEN_GET
#		define Q_AVAILABLE_UINT8_ATOMIC_AND_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_OR_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_OR_THEN_GET
#		define Q_AVAILABLE_UINT8_ATOMIC_OR_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(UINT8_ATOMIC_OR_THEN_GET)
#		define q_uint8_atomic_or_then_get Q_COMPILER_FUNCTION_UINT8_ATOMIC_OR_THEN_GET
#		define Q_AVAILABLE_UINT8_ATOMIC_OR_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_XOR_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_XOR_THEN_GET
#		define Q_AVAILABLE_UINT8_ATOMIC_XOR_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(UINT8_ATOMIC_XOR_THEN_GET)
#		define q_uint8_atomic_xor_then_get Q_COMPILER_FUNCTION_UINT8_ATOMIC_XOR_THEN_GET
#		define Q_AVAILABLE_UINT8_ATOMIC_XOR_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_NOT_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_NOT_THEN_GET
#		define Q_AVAILABLE_UINT8_ATOMIC_NOT_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(UINT8_ATOMIC_NOT_THEN_GET)
#		define q_uint8_atomic_not_then_get Q_COMPILER_FUNCTION_UINT8_ATOMIC_NOT_THEN_GET
#		define Q_AVAILABLE_UINT8_ATOMIC_NOT_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_SET_IF_EQUAL)
		Q_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_SET_IF_EQUAL
#		define Q_AVAILABLE_INT8_ATOMIC_SET_IF_EQUAL
#	elif Q_COMPILER_HAS_FUNCTION(INT8_ATOMIC_SET_IF_EQUAL)
#		define q_int8_atomic_set_if_equal Q_COMPILER_FUNCTION_INT8_ATOMIC_SET_IF_EQUAL
#		define Q_AVAILABLE_INT8_ATOMIC_SET_IF_EQUAL
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_GET_THEN_INCREMENT)
		Q_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_GET_THEN_INCREMENT
#		define Q_AVAILABLE_INT8_ATOMIC_GET_THEN_INCREMENT
#	elif Q_COMPILER_HAS_FUNCTION(INT8_ATOMIC_GET_THEN_INCREMENT)
#		define q_int8_atomic_get_then_increment Q_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_INCREMENT
#		define Q_AVAILABLE_INT8_ATOMIC_GET_THEN_INCREMENT
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_GET_THEN_DECREMENT)
		Q_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_GET_THEN_DECREMENT
#		define Q_AVAILABLE_INT8_ATOMIC_GET_THEN_DECREMENT
#	elif Q_COMPILER_HAS_FUNCTION(INT8_ATOMIC_GET_THEN_DECREMENT)
#		define q_int8_atomic_get_then_decrement Q_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_DECREMENT
#		define Q_AVAILABLE_INT8_ATOMIC_GET_THEN_DECREMENT
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_GET_THEN_ADD)
		Q_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_GET_THEN_ADD
#		define Q_AVAILABLE_INT8_ATOMIC_GET_THEN_ADD
#	elif Q_COMPILER_HAS_FUNCTION(INT8_ATOMIC_GET_THEN_ADD)
#		define q_int8_atomic_get_then_add Q_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_ADD
#		define Q_AVAILABLE_INT8_ATOMIC_GET_THEN_ADD
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_GET_THEN_SUBTRACT)
		Q_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_GET_THEN_SUBTRACT
#		define Q_AVAILABLE_INT8_ATOMIC_GET_THEN_SUBTRACT
#	elif Q_COMPILER_HAS_FUNCTION(INT8_ATOMIC_GET_THEN_SUBTRACT)
#		define q_int8_atomic_get_then_subtract Q_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_SUBTRACT
#		define Q_AVAILABLE_INT8_ATOMIC_GET_THEN_SUBTRACT
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_GET_THEN_AND)
		Q_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_GET_THEN_AND
#		define Q_AVAILABLE_INT8_ATOMIC_GET_THEN_AND
#	elif Q_COMPILER_HAS_FUNCTION(INT8_ATOMIC_GET_THEN_AND)
#		define q_int8_atomic_get_then_and Q_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_AND
#		define Q_AVAILABLE_INT8_ATOMIC_GET_THEN_AND
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_GET_THEN_OR)
		Q_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_GET_THEN_OR
#		define Q_AVAILABLE_INT8_ATOMIC_GET_THEN_OR
#	elif Q_COMPILER_HAS_FUNCTION(INT8_ATOMIC_GET_THEN_OR)
#		define q_int8_atomic_get_then_or Q_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_OR
#		define Q_AVAILABLE_INT8_ATOMIC_GET_THEN_OR
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_GET_THEN_XOR)
		Q_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_GET_THEN_XOR
#		define Q_AVAILABLE_INT8_ATOMIC_GET_THEN_XOR
#	elif Q_COMPILER_HAS_FUNCTION(INT8_ATOMIC_GET_THEN_XOR)
#		define q_int8_atomic_get_then_xor Q_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_XOR
#		define Q_AVAILABLE_INT8_ATOMIC_GET_THEN_XOR
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_GET_THEN_NOT)
		Q_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_GET_THEN_NOT
#		define Q_AVAILABLE_INT8_ATOMIC_GET_THEN_NOT
#	elif Q_COMPILER_HAS_FUNCTION(INT8_ATOMIC_GET_THEN_NOT)
#		define q_int8_atomic_get_then_not Q_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_NOT
#		define Q_AVAILABLE_INT8_ATOMIC_GET_THEN_NOT
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_INCREMENT_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_INCREMENT_THEN_GET
#		define Q_AVAILABLE_INT8_ATOMIC_INCREMENT_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(INT8_ATOMIC_INCREMENT_THEN_GET)
#		define q_int8_atomic_increment_then_get Q_COMPILER_FUNCTION_INT8_ATOMIC_INCREMENT_THEN_GET
#		define Q_AVAILABLE_INT8_ATOMIC_INCREMENT_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_DECREMENT_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_DECREMENT_THEN_GET
#		define Q_AVAILABLE_INT8_ATOMIC_DECREMENT_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(INT8_ATOMIC_DECREMENT_THEN_GET)
#		define q_int8_atomic_decrement_then_get Q_COMPILER_FUNCTION_INT8_ATOMIC_DECREMENT_THEN_GET
#		define Q_AVAILABLE_INT8_ATOMIC_DECREMENT_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_ADD_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_ADD_THEN_GET
#		define Q_AVAILABLE_INT8_ATOMIC_ADD_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(INT8_ATOMIC_ADD_THEN_GET)
#		define q_int8_atomic_add_then_get Q_COMPILER_FUNCTION_INT8_ATOMIC_ADD_THEN_GET
#		define Q_AVAILABLE_INT8_ATOMIC_ADD_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_SUBTRACT_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_SUBTRACT_THEN_GET
#		define Q_AVAILABLE_INT8_ATOMIC_SUBTRACT_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(INT8_ATOMIC_SUBTRACT_THEN_GET)
#		define q_int8_atomic_subtract_then_get Q_COMPILER_FUNCTION_INT8_ATOMIC_SUBTRACT_THEN_GET
#		define Q_AVAILABLE_INT8_ATOMIC_SUBTRACT_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_AND_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_AND_THEN_GET
#		define Q_AVAILABLE_INT8_ATOMIC_AND_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(INT8_ATOMIC_AND_THEN_GET)
#		define q_int8_atomic_and_then_get Q_COMPILER_FUNCTION_INT8_ATOMIC_AND_THEN_GET
#		define Q_AVAILABLE_INT8_ATOMIC_AND_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_OR_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_OR_THEN_GET
#		define Q_AVAILABLE_INT8_ATOMIC_OR_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(INT8_ATOMIC_OR_THEN_GET)
#		define q_int8_atomic_or_then_get Q_COMPILER_FUNCTION_INT8_ATOMIC_OR_THEN_GET
#		define Q_AVAILABLE_INT8_ATOMIC_OR_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_XOR_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_XOR_THEN_GET
#		define Q_AVAILABLE_INT8_ATOMIC_XOR_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(INT8_ATOMIC_XOR_THEN_GET)
#		define q_int8_atomic_xor_then_get Q_COMPILER_FUNCTION_INT8_ATOMIC_XOR_THEN_GET
#		define Q_AVAILABLE_INT8_ATOMIC_XOR_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_NOT_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_NOT_THEN_GET
#		define Q_AVAILABLE_INT8_ATOMIC_NOT_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(INT8_ATOMIC_NOT_THEN_GET)
#		define q_int8_atomic_not_then_get Q_COMPILER_FUNCTION_INT8_ATOMIC_NOT_THEN_GET
#		define Q_AVAILABLE_INT8_ATOMIC_NOT_THEN_GET
#	endif

#endif

#if Q_CPU_IS_CAPABLE_OF(16BIT_ATOMICS)

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_16BIT_ATOMIC_SET_BIT)
		Q_ASSEMBLY_IMPLEMENTATION_16BIT_ATOMIC_SET_BIT
#		define Q_AVAILABLE_16BIT_ATOMIC_SET_BIT
#	elif Q_COMPILER_HAS_FUNCTION(16BIT_ATOMIC_SET_BIT)
#		define q_16bit_atomic_set_bit Q_COMPILER_FUNCTION_16BIT_ATOMIC_SET_BIT
#		define Q_AVAILABLE_16BIT_ATOMIC_SET_BIT
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_16BIT_ATOMIC_CLEAR_BIT)
		Q_ASSEMBLY_IMPLEMENTATION_16BIT_ATOMIC_CLEAR_BIT
#		define Q_AVAILABLE_16BIT_ATOMIC_CLEAR_BIT
#	elif Q_COMPILER_HAS_FUNCTION(16BIT_ATOMIC_CLEAR_BIT)
#		define q_16bit_atomic_clear_bit Q_COMPILER_FUNCTION_16BIT_ATOMIC_CLEAR_BIT
#		define Q_AVAILABLE_16BIT_ATOMIC_CLEAR_BIT
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_SET_IF_EQUAL)
		Q_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_SET_IF_EQUAL
#		define Q_AVAILABLE_UINT16_ATOMIC_SET_IF_EQUAL
#	elif Q_COMPILER_HAS_FUNCTION(UINT16_ATOMIC_SET_IF_EQUAL)
#		define q_uint16_atomic_set_if_equal Q_COMPILER_FUNCTION_UINT16_ATOMIC_SET_IF_EQUAL
#		define Q_AVAILABLE_UINT16_ATOMIC_SET_IF_EQUAL
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_GET_THEN_INCREMENT)
		Q_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_GET_THEN_INCREMENT
#		define Q_AVAILABLE_UINT16_ATOMIC_GET_THEN_INCREMENT
#	elif Q_COMPILER_HAS_FUNCTION(UINT16_ATOMIC_GET_THEN_INCREMENT)
#		define q_uint16_atomic_get_then_increment Q_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_INCREMENT
#		define Q_AVAILABLE_UINT16_ATOMIC_GET_THEN_INCREMENT
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_GET_THEN_DECREMENT)
		Q_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_GET_THEN_DECREMENT
#		define Q_AVAILABLE_UINT16_ATOMIC_GET_THEN_DECREMENT
#	elif Q_COMPILER_HAS_FUNCTION(UINT16_ATOMIC_GET_THEN_DECREMENT)
#		define q_uint16_atomic_get_then_decrement Q_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_DECREMENT
#		define Q_AVAILABLE_UINT16_ATOMIC_GET_THEN_DECREMENT
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_GET_THEN_ADD)
		Q_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_GET_THEN_ADD
#		define Q_AVAILABLE_UINT16_ATOMIC_GET_THEN_ADD
#	elif Q_COMPILER_HAS_FUNCTION(UINT16_ATOMIC_GET_THEN_ADD)
#		define q_uint16_atomic_get_then_add Q_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_ADD
#		define Q_AVAILABLE_UINT16_ATOMIC_GET_THEN_ADD
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_GET_THEN_SUBTRACT)
		Q_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_GET_THEN_SUBTRACT
#		define Q_AVAILABLE_UINT16_ATOMIC_GET_THEN_SUBTRACT
#	elif Q_COMPILER_HAS_FUNCTION(UINT16_ATOMIC_GET_THEN_SUBTRACT)
#		define q_uint16_atomic_get_then_subtract Q_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_SUBTRACT
#		define Q_AVAILABLE_UINT16_ATOMIC_GET_THEN_SUBTRACT
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_GET_THEN_AND)
		Q_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_GET_THEN_AND
#		define Q_AVAILABLE_UINT16_ATOMIC_GET_THEN_AND
#	elif Q_COMPILER_HAS_FUNCTION(UINT16_ATOMIC_GET_THEN_AND)
#		define q_uint16_atomic_get_then_and Q_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_AND
#		define Q_AVAILABLE_UINT16_ATOMIC_GET_THEN_AND
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_GET_THEN_OR)
		Q_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_GET_THEN_OR
#		define Q_AVAILABLE_UINT16_ATOMIC_GET_THEN_OR
#	elif Q_COMPILER_HAS_FUNCTION(UINT16_ATOMIC_GET_THEN_OR)
#		define q_uint16_atomic_get_then_or Q_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_OR
#		define Q_AVAILABLE_UINT16_ATOMIC_GET_THEN_OR
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_GET_THEN_XOR)
		Q_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_GET_THEN_XOR
#		define Q_AVAILABLE_UINT16_ATOMIC_GET_THEN_XOR
#	elif Q_COMPILER_HAS_FUNCTION(UINT16_ATOMIC_GET_THEN_XOR)
#		define q_uint16_atomic_get_then_xor Q_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_XOR
#		define Q_AVAILABLE_UINT16_ATOMIC_GET_THEN_XOR
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_GET_THEN_NOT)
		Q_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_GET_THEN_NOT
#		define Q_AVAILABLE_UINT16_ATOMIC_GET_THEN_NOT
#	elif Q_COMPILER_HAS_FUNCTION(UINT16_ATOMIC_GET_THEN_NOT)
#		define q_uint16_atomic_get_then_not Q_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_NOT
#		define Q_AVAILABLE_UINT16_ATOMIC_GET_THEN_NOT
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_INCREMENT_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_INCREMENT_THEN_GET
#		define Q_AVAILABLE_UINT16_ATOMIC_INCREMENT_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(UINT16_ATOMIC_INCREMENT_THEN_GET)
#		define q_uint16_atomic_increment_then_get Q_COMPILER_FUNCTION_UINT16_ATOMIC_INCREMENT_THEN_GET
#		define Q_AVAILABLE_UINT16_ATOMIC_INCREMENT_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_DECREMENT_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_DECREMENT_THEN_GET
#		define Q_AVAILABLE_UINT16_ATOMIC_DECREMENT_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(UINT16_ATOMIC_DECREMENT_THEN_GET)
#		define q_uint16_atomic_decrement_then_get Q_COMPILER_FUNCTION_UINT16_ATOMIC_DECREMENT_THEN_GET
#		define Q_AVAILABLE_UINT16_ATOMIC_DECREMENT_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_ADD_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_ADD_THEN_GET
#		define Q_AVAILABLE_UINT16_ATOMIC_ADD_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(UINT16_ATOMIC_ADD_THEN_GET)
#		define q_uint16_atomic_add_then_get Q_COMPILER_FUNCTION_UINT16_ATOMIC_ADD_THEN_GET
#		define Q_AVAILABLE_UINT16_ATOMIC_ADD_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_SUBTRACT_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_SUBTRACT_THEN_GET
#		define Q_AVAILABLE_UINT16_ATOMIC_SUBTRACT_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(UINT16_ATOMIC_SUBTRACT_THEN_GET)
#		define q_uint16_atomic_subtract_then_get Q_COMPILER_FUNCTION_UINT16_ATOMIC_SUBTRACT_THEN_GET
#		define Q_AVAILABLE_UINT16_ATOMIC_SUBTRACT_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_AND_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_AND_THEN_GET
#		define Q_AVAILABLE_UINT16_ATOMIC_AND_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(UINT16_ATOMIC_AND_THEN_GET)
#		define q_uint16_atomic_and_then_get Q_COMPILER_FUNCTION_UINT16_ATOMIC_AND_THEN_GET
#		define Q_AVAILABLE_UINT16_ATOMIC_AND_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_OR_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_OR_THEN_GET
#		define Q_AVAILABLE_UINT16_ATOMIC_OR_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(UINT16_ATOMIC_OR_THEN_GET)
#		define q_uint16_atomic_or_then_get Q_COMPILER_FUNCTION_UINT16_ATOMIC_OR_THEN_GET
#		define Q_AVAILABLE_UINT16_ATOMIC_OR_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_XOR_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_XOR_THEN_GET
#		define Q_AVAILABLE_UINT16_ATOMIC_XOR_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(UINT16_ATOMIC_XOR_THEN_GET)
#		define q_uint16_atomic_xor_then_get Q_COMPILER_FUNCTION_UINT16_ATOMIC_XOR_THEN_GET
#		define Q_AVAILABLE_UINT16_ATOMIC_XOR_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_NOT_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_NOT_THEN_GET
#		define Q_AVAILABLE_UINT16_ATOMIC_NOT_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(UINT16_ATOMIC_NOT_THEN_GET)
#		define q_uint16_atomic_not_then_get Q_COMPILER_FUNCTION_UINT16_ATOMIC_NOT_THEN_GET
#		define Q_AVAILABLE_UINT16_ATOMIC_NOT_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_SET_IF_EQUAL)
		Q_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_SET_IF_EQUAL
#		define Q_AVAILABLE_INT16_ATOMIC_SET_IF_EQUAL
#	elif Q_COMPILER_HAS_FUNCTION(INT16_ATOMIC_SET_IF_EQUAL)
#		define q_int16_atomic_set_if_equal Q_COMPILER_FUNCTION_INT16_ATOMIC_SET_IF_EQUAL
#		define Q_AVAILABLE_INT16_ATOMIC_SET_IF_EQUAL
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_GET_THEN_INCREMENT)
		Q_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_GET_THEN_INCREMENT
#		define Q_AVAILABLE_INT16_ATOMIC_GET_THEN_INCREMENT
#	elif Q_COMPILER_HAS_FUNCTION(INT16_ATOMIC_GET_THEN_INCREMENT)
#		define q_int16_atomic_get_then_increment Q_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_INCREMENT
#		define Q_AVAILABLE_INT16_ATOMIC_GET_THEN_INCREMENT
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_GET_THEN_DECREMENT)
		Q_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_GET_THEN_DECREMENT
#		define Q_AVAILABLE_INT16_ATOMIC_GET_THEN_DECREMENT
#	elif Q_COMPILER_HAS_FUNCTION(INT16_ATOMIC_GET_THEN_DECREMENT)
#		define q_int16_atomic_get_then_decrement Q_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_DECREMENT
#		define Q_AVAILABLE_INT16_ATOMIC_GET_THEN_DECREMENT
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_GET_THEN_ADD)
		Q_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_GET_THEN_ADD
#		define Q_AVAILABLE_INT16_ATOMIC_GET_THEN_ADD
#	elif Q_COMPILER_HAS_FUNCTION(INT16_ATOMIC_GET_THEN_ADD)
#		define q_int16_atomic_get_then_add Q_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_ADD
#		define Q_AVAILABLE_INT16_ATOMIC_GET_THEN_ADD
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_GET_THEN_SUBTRACT)
		Q_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_GET_THEN_SUBTRACT
#		define Q_AVAILABLE_INT16_ATOMIC_GET_THEN_SUBTRACT
#	elif Q_COMPILER_HAS_FUNCTION(INT16_ATOMIC_GET_THEN_SUBTRACT)
#		define q_int16_atomic_get_then_subtract Q_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_SUBTRACT
#		define Q_AVAILABLE_INT16_ATOMIC_GET_THEN_SUBTRACT
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_GET_THEN_AND)
		Q_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_GET_THEN_AND
#		define Q_AVAILABLE_INT16_ATOMIC_GET_THEN_AND
#	elif Q_COMPILER_HAS_FUNCTION(INT16_ATOMIC_GET_THEN_AND)
#		define q_int16_atomic_get_then_and Q_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_AND
#		define Q_AVAILABLE_INT16_ATOMIC_GET_THEN_AND
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_GET_THEN_OR)
		Q_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_GET_THEN_OR
#		define Q_AVAILABLE_INT16_ATOMIC_GET_THEN_OR
#	elif Q_COMPILER_HAS_FUNCTION(INT16_ATOMIC_GET_THEN_OR)
#		define q_int16_atomic_get_then_or Q_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_OR
#		define Q_AVAILABLE_INT16_ATOMIC_GET_THEN_OR
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_GET_THEN_XOR)
		Q_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_GET_THEN_XOR
#		define Q_AVAILABLE_INT16_ATOMIC_GET_THEN_XOR
#	elif Q_COMPILER_HAS_FUNCTION(INT16_ATOMIC_GET_THEN_XOR)
#		define q_int16_atomic_get_then_xor Q_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_XOR
#		define Q_AVAILABLE_INT16_ATOMIC_GET_THEN_XOR
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_GET_THEN_NOT)
		Q_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_GET_THEN_NOT
#		define Q_AVAILABLE_INT16_ATOMIC_GET_THEN_NOT
#	elif Q_COMPILER_HAS_FUNCTION(INT16_ATOMIC_GET_THEN_NOT)
#		define q_int16_atomic_get_then_not Q_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_NOT
#		define Q_AVAILABLE_INT16_ATOMIC_GET_THEN_NOT
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_INCREMENT_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_INCREMENT_THEN_GET
#		define Q_AVAILABLE_INT16_ATOMIC_INCREMENT_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(INT16_ATOMIC_INCREMENT_THEN_GET)
#		define q_int16_atomic_increment_then_get Q_COMPILER_FUNCTION_INT16_ATOMIC_INCREMENT_THEN_GET
#		define Q_AVAILABLE_INT16_ATOMIC_INCREMENT_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_DECREMENT_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_DECREMENT_THEN_GET
#		define Q_AVAILABLE_INT16_ATOMIC_DECREMENT_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(INT16_ATOMIC_DECREMENT_THEN_GET)
#		define q_int16_atomic_decrement_then_get Q_COMPILER_FUNCTION_INT16_ATOMIC_DECREMENT_THEN_GET
#		define Q_AVAILABLE_INT16_ATOMIC_DECREMENT_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_ADD_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_ADD_THEN_GET
#		define Q_AVAILABLE_INT16_ATOMIC_ADD_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(INT16_ATOMIC_ADD_THEN_GET)
#		define q_int16_atomic_add_then_get Q_COMPILER_FUNCTION_INT16_ATOMIC_ADD_THEN_GET
#		define Q_AVAILABLE_INT16_ATOMIC_ADD_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_SUBTRACT_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_SUBTRACT_THEN_GET
#		define Q_AVAILABLE_INT16_ATOMIC_SUBTRACT_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(INT16_ATOMIC_SUBTRACT_THEN_GET)
#		define q_int16_atomic_subtract_then_get Q_COMPILER_FUNCTION_INT16_ATOMIC_SUBTRACT_THEN_GET
#		define Q_AVAILABLE_INT16_ATOMIC_SUBTRACT_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_AND_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_AND_THEN_GET
#		define Q_AVAILABLE_INT16_ATOMIC_AND_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(INT16_ATOMIC_AND_THEN_GET)
#		define q_int16_atomic_and_then_get Q_COMPILER_FUNCTION_INT16_ATOMIC_AND_THEN_GET
#		define Q_AVAILABLE_INT16_ATOMIC_AND_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_OR_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_OR_THEN_GET
#		define Q_AVAILABLE_INT16_ATOMIC_OR_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(INT16_ATOMIC_OR_THEN_GET)
#		define q_int16_atomic_or_then_get Q_COMPILER_FUNCTION_INT16_ATOMIC_OR_THEN_GET
#		define Q_AVAILABLE_INT16_ATOMIC_OR_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_XOR_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_XOR_THEN_GET
#		define Q_AVAILABLE_INT16_ATOMIC_XOR_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(INT16_ATOMIC_XOR_THEN_GET)
#		define q_int16_atomic_xor_then_get Q_COMPILER_FUNCTION_INT16_ATOMIC_XOR_THEN_GET
#		define Q_AVAILABLE_INT16_ATOMIC_XOR_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_NOT_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_NOT_THEN_GET
#		define Q_AVAILABLE_INT16_ATOMIC_NOT_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(INT16_ATOMIC_NOT_THEN_GET)
#		define q_int16_atomic_not_then_get Q_COMPILER_FUNCTION_INT16_ATOMIC_NOT_THEN_GET
#		define Q_AVAILABLE_INT16_ATOMIC_NOT_THEN_GET
#	endif

#endif

#if Q_CPU_IS_CAPABLE_OF(32BIT_ATOMICS)

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_32BIT_ATOMIC_SET_BIT)
		Q_ASSEMBLY_IMPLEMENTATION_32BIT_ATOMIC_SET_BIT
#		define Q_AVAILABLE_32BIT_ATOMIC_SET_BIT
#	elif Q_COMPILER_HAS_FUNCTION(32BIT_ATOMIC_SET_BIT)
#		define q_32bit_atomic_set_bit Q_COMPILER_FUNCTION_32BIT_ATOMIC_SET_BIT
#		define Q_AVAILABLE_32BIT_ATOMIC_SET_BIT
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_32BIT_ATOMIC_CLEAR_BIT)
		Q_ASSEMBLY_IMPLEMENTATION_32BIT_ATOMIC_CLEAR_BIT
#		define Q_AVAILABLE_32BIT_ATOMIC_CLEAR_BIT
#	elif Q_COMPILER_HAS_FUNCTION(32BIT_ATOMIC_CLEAR_BIT)
#		define q_32bit_atomic_clear_bit Q_COMPILER_FUNCTION_32BIT_ATOMIC_CLEAR_BIT
#		define Q_AVAILABLE_32BIT_ATOMIC_CLEAR_BIT
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_SET_IF_EQUAL)
		Q_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_SET_IF_EQUAL
#		define Q_AVAILABLE_UINT32_ATOMIC_SET_IF_EQUAL
#	elif Q_COMPILER_HAS_FUNCTION(UINT32_ATOMIC_SET_IF_EQUAL)
#		define q_uint32_atomic_set_if_equal Q_COMPILER_FUNCTION_UINT32_ATOMIC_SET_IF_EQUAL
#		define Q_AVAILABLE_UINT32_ATOMIC_SET_IF_EQUAL
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_GET_THEN_INCREMENT)
		Q_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_GET_THEN_INCREMENT
#		define Q_AVAILABLE_UINT32_ATOMIC_GET_THEN_INCREMENT
#	elif Q_COMPILER_HAS_FUNCTION(UINT32_ATOMIC_GET_THEN_INCREMENT)
#		define q_uint32_atomic_get_then_increment Q_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_INCREMENT
#		define Q_AVAILABLE_UINT32_ATOMIC_GET_THEN_INCREMENT
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_GET_THEN_DECREMENT)
		Q_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_GET_THEN_DECREMENT
#		define Q_AVAILABLE_UINT32_ATOMIC_GET_THEN_DECREMENT
#	elif Q_COMPILER_HAS_FUNCTION(UINT32_ATOMIC_GET_THEN_DECREMENT)
#		define q_uint32_atomic_get_then_decrement Q_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_DECREMENT
#		define Q_AVAILABLE_UINT32_ATOMIC_GET_THEN_DECREMENT
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_GET_THEN_ADD)
		Q_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_GET_THEN_ADD
#		define Q_AVAILABLE_UINT32_ATOMIC_GET_THEN_ADD
#	elif Q_COMPILER_HAS_FUNCTION(UINT32_ATOMIC_GET_THEN_ADD)
#		define q_uint32_atomic_get_then_add Q_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_ADD
#		define Q_AVAILABLE_UINT32_ATOMIC_GET_THEN_ADD
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_GET_THEN_SUBTRACT)
		Q_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_GET_THEN_SUBTRACT
#		define Q_AVAILABLE_UINT32_ATOMIC_GET_THEN_SUBTRACT
#	elif Q_COMPILER_HAS_FUNCTION(UINT32_ATOMIC_GET_THEN_SUBTRACT)
#		define q_uint32_atomic_get_then_subtract Q_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_SUBTRACT
#		define Q_AVAILABLE_UINT32_ATOMIC_GET_THEN_SUBTRACT
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_GET_THEN_AND)
		Q_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_GET_THEN_AND
#		define Q_AVAILABLE_UINT32_ATOMIC_GET_THEN_AND
#	elif Q_COMPILER_HAS_FUNCTION(UINT32_ATOMIC_GET_THEN_AND)
#		define q_uint32_atomic_get_then_and Q_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_AND
#		define Q_AVAILABLE_UINT32_ATOMIC_GET_THEN_AND
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_GET_THEN_OR)
		Q_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_GET_THEN_OR
#		define Q_AVAILABLE_UINT32_ATOMIC_GET_THEN_OR
#	elif Q_COMPILER_HAS_FUNCTION(UINT32_ATOMIC_GET_THEN_OR)
#		define q_uint32_atomic_get_then_or Q_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_OR
#		define Q_AVAILABLE_UINT32_ATOMIC_GET_THEN_OR
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_GET_THEN_XOR)
		Q_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_GET_THEN_XOR
#		define Q_AVAILABLE_UINT32_ATOMIC_GET_THEN_XOR
#	elif Q_COMPILER_HAS_FUNCTION(UINT32_ATOMIC_GET_THEN_XOR)
#		define q_uint32_atomic_get_then_xor Q_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_XOR
#		define Q_AVAILABLE_UINT32_ATOMIC_GET_THEN_XOR
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_GET_THEN_NOT)
		Q_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_GET_THEN_NOT
#		define Q_AVAILABLE_UINT32_ATOMIC_GET_THEN_NOT
#	elif Q_COMPILER_HAS_FUNCTION(UINT32_ATOMIC_GET_THEN_NOT)
#		define q_uint32_atomic_get_then_not Q_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_NOT
#		define Q_AVAILABLE_UINT32_ATOMIC_GET_THEN_NOT
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_INCREMENT_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_INCREMENT_THEN_GET
#		define Q_AVAILABLE_UINT32_ATOMIC_INCREMENT_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(UINT32_ATOMIC_INCREMENT_THEN_GET)
#		define q_uint32_atomic_increment_then_get Q_COMPILER_FUNCTION_UINT32_ATOMIC_INCREMENT_THEN_GET
#		define Q_AVAILABLE_UINT32_ATOMIC_INCREMENT_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_DECREMENT_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_DECREMENT_THEN_GET
#		define Q_AVAILABLE_UINT32_ATOMIC_DECREMENT_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(UINT32_ATOMIC_DECREMENT_THEN_GET)
#		define q_uint32_atomic_decrement_then_get Q_COMPILER_FUNCTION_UINT32_ATOMIC_DECREMENT_THEN_GET
#		define Q_AVAILABLE_UINT32_ATOMIC_DECREMENT_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_ADD_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_ADD_THEN_GET
#		define Q_AVAILABLE_UINT32_ATOMIC_ADD_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(UINT32_ATOMIC_ADD_THEN_GET)
#		define q_uint32_atomic_add_then_get Q_COMPILER_FUNCTION_UINT32_ATOMIC_ADD_THEN_GET
#		define Q_AVAILABLE_UINT32_ATOMIC_ADD_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_SUBTRACT_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_SUBTRACT_THEN_GET
#		define Q_AVAILABLE_UINT32_ATOMIC_SUBTRACT_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(UINT32_ATOMIC_SUBTRACT_THEN_GET)
#		define q_uint32_atomic_subtract_then_get Q_COMPILER_FUNCTION_UINT32_ATOMIC_SUBTRACT_THEN_GET
#		define Q_AVAILABLE_UINT32_ATOMIC_SUBTRACT_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_AND_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_AND_THEN_GET
#		define Q_AVAILABLE_UINT32_ATOMIC_AND_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(UINT32_ATOMIC_AND_THEN_GET)
#		define q_uint32_atomic_and_then_get Q_COMPILER_FUNCTION_UINT32_ATOMIC_AND_THEN_GET
#		define Q_AVAILABLE_UINT32_ATOMIC_AND_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_OR_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_OR_THEN_GET
#		define Q_AVAILABLE_UINT32_ATOMIC_OR_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(UINT32_ATOMIC_OR_THEN_GET)
#		define q_uint32_atomic_or_then_get Q_COMPILER_FUNCTION_UINT32_ATOMIC_OR_THEN_GET
#		define Q_AVAILABLE_UINT32_ATOMIC_OR_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_XOR_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_XOR_THEN_GET
#		define Q_AVAILABLE_UINT32_ATOMIC_XOR_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(UINT32_ATOMIC_XOR_THEN_GET)
#		define q_uint32_atomic_xor_then_get Q_COMPILER_FUNCTION_UINT32_ATOMIC_XOR_THEN_GET
#		define Q_AVAILABLE_UINT32_ATOMIC_XOR_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_NOT_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_NOT_THEN_GET
#		define Q_AVAILABLE_UINT32_ATOMIC_NOT_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(UINT32_ATOMIC_NOT_THEN_GET)
#		define q_uint32_atomic_not_then_get Q_COMPILER_FUNCTION_UINT32_ATOMIC_NOT_THEN_GET
#		define Q_AVAILABLE_UINT32_ATOMIC_NOT_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_SET_IF_EQUAL)
		Q_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_SET_IF_EQUAL
#		define Q_AVAILABLE_INT32_ATOMIC_SET_IF_EQUAL
#	elif Q_COMPILER_HAS_FUNCTION(INT32_ATOMIC_SET_IF_EQUAL)
#		define q_int32_atomic_set_if_equal Q_COMPILER_FUNCTION_INT32_ATOMIC_SET_IF_EQUAL
#		define Q_AVAILABLE_INT32_ATOMIC_SET_IF_EQUAL
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_GET_THEN_INCREMENT)
		Q_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_GET_THEN_INCREMENT
#		define Q_AVAILABLE_INT32_ATOMIC_GET_THEN_INCREMENT
#	elif Q_COMPILER_HAS_FUNCTION(INT32_ATOMIC_GET_THEN_INCREMENT)
#		define q_int32_atomic_get_then_increment Q_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_INCREMENT
#		define Q_AVAILABLE_INT32_ATOMIC_GET_THEN_INCREMENT
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_GET_THEN_DECREMENT)
		Q_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_GET_THEN_DECREMENT
#		define Q_AVAILABLE_INT32_ATOMIC_GET_THEN_DECREMENT
#	elif Q_COMPILER_HAS_FUNCTION(INT32_ATOMIC_GET_THEN_DECREMENT)
#		define q_int32_atomic_get_then_decrement Q_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_DECREMENT
#		define Q_AVAILABLE_INT32_ATOMIC_GET_THEN_DECREMENT
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_GET_THEN_ADD)
		Q_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_GET_THEN_ADD
#		define Q_AVAILABLE_INT32_ATOMIC_GET_THEN_ADD
#	elif Q_COMPILER_HAS_FUNCTION(INT32_ATOMIC_GET_THEN_ADD)
#		define q_int32_atomic_get_then_add Q_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_ADD
#		define Q_AVAILABLE_INT32_ATOMIC_GET_THEN_ADD
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_GET_THEN_SUBTRACT)
		Q_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_GET_THEN_SUBTRACT
#		define Q_AVAILABLE_INT32_ATOMIC_GET_THEN_SUBTRACT
#	elif Q_COMPILER_HAS_FUNCTION(INT32_ATOMIC_GET_THEN_SUBTRACT)
#		define q_int32_atomic_get_then_subtract Q_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_SUBTRACT
#		define Q_AVAILABLE_INT32_ATOMIC_GET_THEN_SUBTRACT
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_GET_THEN_AND)
		Q_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_GET_THEN_AND
#		define Q_AVAILABLE_INT32_ATOMIC_GET_THEN_AND
#	elif Q_COMPILER_HAS_FUNCTION(INT32_ATOMIC_GET_THEN_AND)
#		define q_int32_atomic_get_then_and Q_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_AND
#		define Q_AVAILABLE_INT32_ATOMIC_GET_THEN_AND
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_GET_THEN_OR)
		Q_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_GET_THEN_OR
#		define Q_AVAILABLE_INT32_ATOMIC_GET_THEN_OR
#	elif Q_COMPILER_HAS_FUNCTION(INT32_ATOMIC_GET_THEN_OR)
#		define q_int32_atomic_get_then_or Q_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_OR
#		define Q_AVAILABLE_INT32_ATOMIC_GET_THEN_OR
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_GET_THEN_XOR)
		Q_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_GET_THEN_XOR
#		define Q_AVAILABLE_INT32_ATOMIC_GET_THEN_XOR
#	elif Q_COMPILER_HAS_FUNCTION(INT32_ATOMIC_GET_THEN_XOR)
#		define q_int32_atomic_get_then_xor Q_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_XOR
#		define Q_AVAILABLE_INT32_ATOMIC_GET_THEN_XOR
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_GET_THEN_NOT)
		Q_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_GET_THEN_NOT
#		define Q_AVAILABLE_INT32_ATOMIC_GET_THEN_NOT
#	elif Q_COMPILER_HAS_FUNCTION(INT32_ATOMIC_GET_THEN_NOT)
#		define q_int32_atomic_get_then_not Q_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_NOT
#		define Q_AVAILABLE_INT32_ATOMIC_GET_THEN_NOT
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_INCREMENT_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_INCREMENT_THEN_GET
#		define Q_AVAILABLE_INT32_ATOMIC_INCREMENT_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(INT32_ATOMIC_INCREMENT_THEN_GET)
#		define q_int32_atomic_increment_then_get Q_COMPILER_FUNCTION_INT32_ATOMIC_INCREMENT_THEN_GET
#		define Q_AVAILABLE_INT32_ATOMIC_INCREMENT_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_DECREMENT_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_DECREMENT_THEN_GET
#		define Q_AVAILABLE_INT32_ATOMIC_DECREMENT_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(INT32_ATOMIC_DECREMENT_THEN_GET)
#		define q_int32_atomic_decrement_then_get Q_COMPILER_FUNCTION_INT32_ATOMIC_DECREMENT_THEN_GET
#		define Q_AVAILABLE_INT32_ATOMIC_DECREMENT_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_ADD_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_ADD_THEN_GET
#		define Q_AVAILABLE_INT32_ATOMIC_ADD_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(INT32_ATOMIC_ADD_THEN_GET)
#		define q_int32_atomic_add_then_get Q_COMPILER_FUNCTION_INT32_ATOMIC_ADD_THEN_GET
#		define Q_AVAILABLE_INT32_ATOMIC_ADD_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_SUBTRACT_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_SUBTRACT_THEN_GET
#		define Q_AVAILABLE_INT32_ATOMIC_SUBTRACT_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(INT32_ATOMIC_SUBTRACT_THEN_GET)
#		define q_int32_atomic_subtract_then_get Q_COMPILER_FUNCTION_INT32_ATOMIC_SUBTRACT_THEN_GET
#		define Q_AVAILABLE_INT32_ATOMIC_SUBTRACT_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_AND_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_AND_THEN_GET
#		define Q_AVAILABLE_INT32_ATOMIC_AND_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(INT32_ATOMIC_AND_THEN_GET)
#		define q_int32_atomic_and_then_get Q_COMPILER_FUNCTION_INT32_ATOMIC_AND_THEN_GET
#		define Q_AVAILABLE_INT32_ATOMIC_AND_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_OR_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_OR_THEN_GET
#		define Q_AVAILABLE_INT32_ATOMIC_OR_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(INT32_ATOMIC_OR_THEN_GET)
#		define q_int32_atomic_or_then_get Q_COMPILER_FUNCTION_INT32_ATOMIC_OR_THEN_GET
#		define Q_AVAILABLE_INT32_ATOMIC_OR_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_XOR_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_XOR_THEN_GET
#		define Q_AVAILABLE_INT32_ATOMIC_XOR_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(INT32_ATOMIC_XOR_THEN_GET)
#		define q_int32_atomic_xor_then_get Q_COMPILER_FUNCTION_INT32_ATOMIC_XOR_THEN_GET
#		define Q_AVAILABLE_INT32_ATOMIC_XOR_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_NOT_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_NOT_THEN_GET
#		define Q_AVAILABLE_INT32_ATOMIC_NOT_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(INT32_ATOMIC_NOT_THEN_GET)
#		define q_int32_atomic_not_then_get Q_COMPILER_FUNCTION_INT32_ATOMIC_NOT_THEN_GET
#		define Q_AVAILABLE_INT32_ATOMIC_NOT_THEN_GET
#	endif

#endif

#if Q_CPU_IS_CAPABLE_OF(64BIT_ATOMICS)

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_64BIT_ATOMIC_SET_BIT)
		Q_ASSEMBLY_IMPLEMENTATION_64BIT_ATOMIC_SET_BIT
#		define Q_AVAILABLE_64BIT_ATOMIC_SET_BIT
#	elif Q_COMPILER_HAS_FUNCTION(64BIT_ATOMIC_SET_BIT)
#		define q_64bit_atomic_set_bit Q_COMPILER_FUNCTION_64BIT_ATOMIC_SET_BIT
#		define Q_AVAILABLE_64BIT_ATOMIC_SET_BIT
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_64BIT_ATOMIC_CLEAR_BIT)
		Q_ASSEMBLY_IMPLEMENTATION_64BIT_ATOMIC_CLEAR_BIT
#		define Q_AVAILABLE_64BIT_ATOMIC_CLEAR_BIT
#	elif Q_COMPILER_HAS_FUNCTION(64BIT_ATOMIC_CLEAR_BIT)
#		define q_64bit_atomic_clear_bit Q_COMPILER_FUNCTION_64BIT_ATOMIC_CLEAR_BIT
#		define Q_AVAILABLE_64BIT_ATOMIC_CLEAR_BIT
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_SET_IF_EQUAL)
		Q_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_SET_IF_EQUAL
#		define Q_AVAILABLE_UINT64_ATOMIC_SET_IF_EQUAL
#	elif Q_COMPILER_HAS_FUNCTION(UINT64_ATOMIC_SET_IF_EQUAL)
#		define q_uint64_atomic_set_if_equal Q_COMPILER_FUNCTION_UINT64_ATOMIC_SET_IF_EQUAL
#		define Q_AVAILABLE_UINT64_ATOMIC_SET_IF_EQUAL
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_GET_THEN_INCREMENT)
		Q_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_GET_THEN_INCREMENT
#		define Q_AVAILABLE_UINT64_ATOMIC_GET_THEN_INCREMENT
#	elif Q_COMPILER_HAS_FUNCTION(UINT64_ATOMIC_GET_THEN_INCREMENT)
#		define q_uint64_atomic_get_then_increment Q_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_INCREMENT
#		define Q_AVAILABLE_UINT64_ATOMIC_GET_THEN_INCREMENT
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_GET_THEN_DECREMENT)
		Q_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_GET_THEN_DECREMENT
#		define Q_AVAILABLE_UINT64_ATOMIC_GET_THEN_DECREMENT
#	elif Q_COMPILER_HAS_FUNCTION(UINT64_ATOMIC_GET_THEN_DECREMENT)
#		define q_uint64_atomic_get_then_decrement Q_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_DECREMENT
#		define Q_AVAILABLE_UINT64_ATOMIC_GET_THEN_DECREMENT
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_GET_THEN_ADD)
		Q_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_GET_THEN_ADD
#		define Q_AVAILABLE_UINT64_ATOMIC_GET_THEN_ADD
#	elif Q_COMPILER_HAS_FUNCTION(UINT64_ATOMIC_GET_THEN_ADD)
#		define q_uint64_atomic_get_then_add Q_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_ADD
#		define Q_AVAILABLE_UINT64_ATOMIC_GET_THEN_ADD
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_GET_THEN_SUBTRACT)
		Q_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_GET_THEN_SUBTRACT
#		define Q_AVAILABLE_UINT64_ATOMIC_GET_THEN_SUBTRACT
#	elif Q_COMPILER_HAS_FUNCTION(UINT64_ATOMIC_GET_THEN_SUBTRACT)
#		define q_uint64_atomic_get_then_subtract Q_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_SUBTRACT
#		define Q_AVAILABLE_UINT64_ATOMIC_GET_THEN_SUBTRACT
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_GET_THEN_AND)
		Q_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_GET_THEN_AND
#		define Q_AVAILABLE_UINT64_ATOMIC_GET_THEN_AND
#	elif Q_COMPILER_HAS_FUNCTION(UINT64_ATOMIC_GET_THEN_AND)
#		define q_uint64_atomic_get_then_and Q_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_AND
#		define Q_AVAILABLE_UINT64_ATOMIC_GET_THEN_AND
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_GET_THEN_OR)
		Q_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_GET_THEN_OR
#		define Q_AVAILABLE_UINT64_ATOMIC_GET_THEN_OR
#	elif Q_COMPILER_HAS_FUNCTION(UINT64_ATOMIC_GET_THEN_OR)
#		define q_uint64_atomic_get_then_or Q_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_OR
#		define Q_AVAILABLE_UINT64_ATOMIC_GET_THEN_OR
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_GET_THEN_XOR)
		Q_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_GET_THEN_XOR
#		define Q_AVAILABLE_UINT64_ATOMIC_GET_THEN_XOR
#	elif Q_COMPILER_HAS_FUNCTION(UINT64_ATOMIC_GET_THEN_XOR)
#		define q_uint64_atomic_get_then_xor Q_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_XOR
#		define Q_AVAILABLE_UINT64_ATOMIC_GET_THEN_XOR
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_GET_THEN_NOT)
		Q_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_GET_THEN_NOT
#		define Q_AVAILABLE_UINT64_ATOMIC_GET_THEN_NOT
#	elif Q_COMPILER_HAS_FUNCTION(UINT64_ATOMIC_GET_THEN_NOT)
#		define q_uint64_atomic_get_then_not Q_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_NOT
#		define Q_AVAILABLE_UINT64_ATOMIC_GET_THEN_NOT
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_INCREMENT_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_INCREMENT_THEN_GET
#		define Q_AVAILABLE_UINT64_ATOMIC_INCREMENT_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(UINT64_ATOMIC_INCREMENT_THEN_GET)
#		define q_uint64_atomic_increment_then_get Q_COMPILER_FUNCTION_UINT64_ATOMIC_INCREMENT_THEN_GET
#		define Q_AVAILABLE_UINT64_ATOMIC_INCREMENT_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_DECREMENT_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_DECREMENT_THEN_GET
#		define Q_AVAILABLE_UINT64_ATOMIC_DECREMENT_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(UINT64_ATOMIC_DECREMENT_THEN_GET)
#		define q_uint64_atomic_decrement_then_get Q_COMPILER_FUNCTION_UINT64_ATOMIC_DECREMENT_THEN_GET
#		define Q_AVAILABLE_UINT64_ATOMIC_DECREMENT_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_ADD_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_ADD_THEN_GET
#		define Q_AVAILABLE_UINT64_ATOMIC_ADD_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(UINT64_ATOMIC_ADD_THEN_GET)
#		define q_uint64_atomic_add_then_get Q_COMPILER_FUNCTION_UINT64_ATOMIC_ADD_THEN_GET
#		define Q_AVAILABLE_UINT64_ATOMIC_ADD_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_SUBTRACT_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_SUBTRACT_THEN_GET
#		define Q_AVAILABLE_UINT64_ATOMIC_SUBTRACT_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(UINT64_ATOMIC_SUBTRACT_THEN_GET)
#		define q_uint64_atomic_subtract_then_get Q_COMPILER_FUNCTION_UINT64_ATOMIC_SUBTRACT_THEN_GET
#		define Q_AVAILABLE_UINT64_ATOMIC_SUBTRACT_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_AND_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_AND_THEN_GET
#		define Q_AVAILABLE_UINT64_ATOMIC_AND_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(UINT64_ATOMIC_AND_THEN_GET)
#		define q_uint64_atomic_and_then_get Q_COMPILER_FUNCTION_UINT64_ATOMIC_AND_THEN_GET
#		define Q_AVAILABLE_UINT64_ATOMIC_AND_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_OR_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_OR_THEN_GET
#		define Q_AVAILABLE_UINT64_ATOMIC_OR_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(UINT64_ATOMIC_OR_THEN_GET)
#		define q_uint64_atomic_or_then_get Q_COMPILER_FUNCTION_UINT64_ATOMIC_OR_THEN_GET
#		define Q_AVAILABLE_UINT64_ATOMIC_OR_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_XOR_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_XOR_THEN_GET
#		define Q_AVAILABLE_UINT64_ATOMIC_XOR_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(UINT64_ATOMIC_XOR_THEN_GET)
#		define q_uint64_atomic_xor_then_get Q_COMPILER_FUNCTION_UINT64_ATOMIC_XOR_THEN_GET
#		define Q_AVAILABLE_UINT64_ATOMIC_XOR_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_NOT_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_NOT_THEN_GET
#		define Q_AVAILABLE_UINT64_ATOMIC_NOT_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(UINT64_ATOMIC_NOT_THEN_GET)
#		define q_uint64_atomic_not_then_get Q_COMPILER_FUNCTION_UINT64_ATOMIC_NOT_THEN_GET
#		define Q_AVAILABLE_UINT64_ATOMIC_NOT_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_SET_IF_EQUAL)
		Q_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_SET_IF_EQUAL
#		define Q_AVAILABLE_INT64_ATOMIC_SET_IF_EQUAL
#	elif Q_COMPILER_HAS_FUNCTION(INT64_ATOMIC_SET_IF_EQUAL)
#		define q_int64_atomic_set_if_equal Q_COMPILER_FUNCTION_INT64_ATOMIC_SET_IF_EQUAL
#		define Q_AVAILABLE_INT64_ATOMIC_SET_IF_EQUAL
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_GET_THEN_INCREMENT)
		Q_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_GET_THEN_INCREMENT
#		define Q_AVAILABLE_INT64_ATOMIC_GET_THEN_INCREMENT
#	elif Q_COMPILER_HAS_FUNCTION(INT64_ATOMIC_GET_THEN_INCREMENT)
#		define q_int64_atomic_get_then_increment Q_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_INCREMENT
#		define Q_AVAILABLE_INT64_ATOMIC_GET_THEN_INCREMENT
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_GET_THEN_DECREMENT)
		Q_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_GET_THEN_DECREMENT
#		define Q_AVAILABLE_INT64_ATOMIC_GET_THEN_DECREMENT
#	elif Q_COMPILER_HAS_FUNCTION(INT64_ATOMIC_GET_THEN_DECREMENT)
#		define q_int64_atomic_get_then_decrement Q_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_DECREMENT
#		define Q_AVAILABLE_INT64_ATOMIC_GET_THEN_DECREMENT
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_GET_THEN_ADD)
		Q_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_GET_THEN_ADD
#		define Q_AVAILABLE_INT64_ATOMIC_GET_THEN_ADD
#	elif Q_COMPILER_HAS_FUNCTION(INT64_ATOMIC_GET_THEN_ADD)
#		define q_int64_atomic_get_then_add Q_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_ADD
#		define Q_AVAILABLE_INT64_ATOMIC_GET_THEN_ADD
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_GET_THEN_SUBTRACT)
		Q_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_GET_THEN_SUBTRACT
#		define Q_AVAILABLE_INT64_ATOMIC_GET_THEN_SUBTRACT
#	elif Q_COMPILER_HAS_FUNCTION(INT64_ATOMIC_GET_THEN_SUBTRACT)
#		define q_int64_atomic_get_then_subtract Q_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_SUBTRACT
#		define Q_AVAILABLE_INT64_ATOMIC_GET_THEN_SUBTRACT
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_GET_THEN_AND)
		Q_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_GET_THEN_AND
#		define Q_AVAILABLE_INT64_ATOMIC_GET_THEN_AND
#	elif Q_COMPILER_HAS_FUNCTION(INT64_ATOMIC_GET_THEN_AND)
#		define q_int64_atomic_get_then_and Q_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_AND
#		define Q_AVAILABLE_INT64_ATOMIC_GET_THEN_AND
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_GET_THEN_OR)
		Q_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_GET_THEN_OR
#		define Q_AVAILABLE_INT64_ATOMIC_GET_THEN_OR
#	elif Q_COMPILER_HAS_FUNCTION(INT64_ATOMIC_GET_THEN_OR)
#		define q_int64_atomic_get_then_or Q_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_OR
#		define Q_AVAILABLE_INT64_ATOMIC_GET_THEN_OR
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_GET_THEN_XOR)
		Q_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_GET_THEN_XOR
#		define Q_AVAILABLE_INT64_ATOMIC_GET_THEN_XOR
#	elif Q_COMPILER_HAS_FUNCTION(INT64_ATOMIC_GET_THEN_XOR)
#		define q_int64_atomic_get_then_xor Q_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_XOR
#		define Q_AVAILABLE_INT64_ATOMIC_GET_THEN_XOR
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_GET_THEN_NOT)
		Q_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_GET_THEN_NOT
#		define Q_AVAILABLE_INT64_ATOMIC_GET_THEN_NOT
#	elif Q_COMPILER_HAS_FUNCTION(INT64_ATOMIC_GET_THEN_NOT)
#		define q_int64_atomic_get_then_not Q_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_NOT
#		define Q_AVAILABLE_INT64_ATOMIC_GET_THEN_NOT
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_INCREMENT_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_INCREMENT_THEN_GET
#		define Q_AVAILABLE_INT64_ATOMIC_INCREMENT_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(INT64_ATOMIC_INCREMENT_THEN_GET)
#		define q_int64_atomic_increment_then_get Q_COMPILER_FUNCTION_INT64_ATOMIC_INCREMENT_THEN_GET
#		define Q_AVAILABLE_INT64_ATOMIC_INCREMENT_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_DECREMENT_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_DECREMENT_THEN_GET
#		define Q_AVAILABLE_INT64_ATOMIC_DECREMENT_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(INT64_ATOMIC_DECREMENT_THEN_GET)
#		define q_int64_atomic_decrement_then_get Q_COMPILER_FUNCTION_INT64_ATOMIC_DECREMENT_THEN_GET
#		define Q_AVAILABLE_INT64_ATOMIC_DECREMENT_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_ADD_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_ADD_THEN_GET
#		define Q_AVAILABLE_INT64_ATOMIC_ADD_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(INT64_ATOMIC_ADD_THEN_GET)
#		define q_int64_atomic_add_then_get Q_COMPILER_FUNCTION_INT64_ATOMIC_ADD_THEN_GET
#		define Q_AVAILABLE_INT64_ATOMIC_ADD_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_SUBTRACT_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_SUBTRACT_THEN_GET
#		define Q_AVAILABLE_INT64_ATOMIC_SUBTRACT_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(INT64_ATOMIC_SUBTRACT_THEN_GET)
#		define q_int64_atomic_subtract_then_get Q_COMPILER_FUNCTION_INT64_ATOMIC_SUBTRACT_THEN_GET
#		define Q_AVAILABLE_INT64_ATOMIC_SUBTRACT_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_AND_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_AND_THEN_GET
#		define Q_AVAILABLE_INT64_ATOMIC_AND_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(INT64_ATOMIC_AND_THEN_GET)
#		define q_int64_atomic_and_then_get Q_COMPILER_FUNCTION_INT64_ATOMIC_AND_THEN_GET
#		define Q_AVAILABLE_INT64_ATOMIC_AND_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_OR_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_OR_THEN_GET
#		define Q_AVAILABLE_INT64_ATOMIC_OR_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(INT64_ATOMIC_OR_THEN_GET)
#		define q_int64_atomic_or_then_get Q_COMPILER_FUNCTION_INT64_ATOMIC_OR_THEN_GET
#		define Q_AVAILABLE_INT64_ATOMIC_OR_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_XOR_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_XOR_THEN_GET
#		define Q_AVAILABLE_INT64_ATOMIC_XOR_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(INT64_ATOMIC_XOR_THEN_GET)
#		define q_int64_atomic_xor_then_get Q_COMPILER_FUNCTION_INT64_ATOMIC_XOR_THEN_GET
#		define Q_AVAILABLE_INT64_ATOMIC_XOR_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_NOT_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_NOT_THEN_GET
#		define Q_AVAILABLE_INT64_ATOMIC_NOT_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(INT64_ATOMIC_NOT_THEN_GET)
#		define q_int64_atomic_not_then_get Q_COMPILER_FUNCTION_INT64_ATOMIC_NOT_THEN_GET
#		define Q_AVAILABLE_INT64_ATOMIC_NOT_THEN_GET
#	endif

#endif

#if Q_IS_AVAILABLE(UINT128) && Q_CPU_IS_CAPABLE_OF(128BIT_ATOMICS)

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_128BIT_ATOMIC_SET_BIT)
		Q_ASSEMBLY_IMPLEMENTATION_128BIT_ATOMIC_SET_BIT
#		define Q_AVAILABLE_128BIT_ATOMIC_SET_BIT
#	elif Q_COMPILER_HAS_FUNCTION(128BIT_ATOMIC_SET_BIT)
#		define q_128bit_atomic_set_bit Q_COMPILER_FUNCTION_128BIT_ATOMIC_SET_BIT
#		define Q_AVAILABLE_128BIT_ATOMIC_SET_BIT
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_128BIT_ATOMIC_CLEAR_BIT)
		Q_ASSEMBLY_IMPLEMENTATION_128BIT_ATOMIC_CLEAR_BIT
#		define Q_AVAILABLE_128BIT_ATOMIC_CLEAR_BIT
#	elif Q_COMPILER_HAS_FUNCTION(128BIT_ATOMIC_CLEAR_BIT)
#		define q_128bit_atomic_clear_bit Q_COMPILER_FUNCTION_128BIT_ATOMIC_CLEAR_BIT
#		define Q_AVAILABLE_128BIT_ATOMIC_CLEAR_BIT
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_SET_IF_EQUAL)
		Q_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_SET_IF_EQUAL
#		define Q_AVAILABLE_UINT128_ATOMIC_SET_IF_EQUAL
#	elif Q_COMPILER_HAS_FUNCTION(UINT128_ATOMIC_SET_IF_EQUAL)
#		define q_uint128_atomic_set_if_equal Q_COMPILER_FUNCTION_UINT128_ATOMIC_SET_IF_EQUAL
#		define Q_AVAILABLE_UINT128_ATOMIC_SET_IF_EQUAL
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_GET_THEN_INCREMENT)
		Q_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_GET_THEN_INCREMENT
#		define Q_AVAILABLE_UINT128_ATOMIC_GET_THEN_INCREMENT
#	elif Q_COMPILER_HAS_FUNCTION(UINT128_ATOMIC_GET_THEN_INCREMENT)
#		define q_uint128_atomic_get_then_increment Q_COMPILER_FUNCTION_UINT128_ATOMIC_GET_THEN_INCREMENT
#		define Q_AVAILABLE_UINT128_ATOMIC_GET_THEN_INCREMENT
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_GET_THEN_DECREMENT)
		Q_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_GET_THEN_DECREMENT
#		define Q_AVAILABLE_UINT128_ATOMIC_GET_THEN_DECREMENT
#	elif Q_COMPILER_HAS_FUNCTION(UINT128_ATOMIC_GET_THEN_DECREMENT)
#		define q_uint128_atomic_get_then_decrement Q_COMPILER_FUNCTION_UINT128_ATOMIC_GET_THEN_DECREMENT
#		define Q_AVAILABLE_UINT128_ATOMIC_GET_THEN_DECREMENT
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_GET_THEN_ADD)
		Q_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_GET_THEN_ADD
#		define Q_AVAILABLE_UINT128_ATOMIC_GET_THEN_ADD
#	elif Q_COMPILER_HAS_FUNCTION(UINT128_ATOMIC_GET_THEN_ADD)
#		define q_uint128_atomic_get_then_add Q_COMPILER_FUNCTION_UINT128_ATOMIC_GET_THEN_ADD
#		define Q_AVAILABLE_UINT128_ATOMIC_GET_THEN_ADD
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_GET_THEN_SUBTRACT)
		Q_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_GET_THEN_SUBTRACT
#		define Q_AVAILABLE_UINT128_ATOMIC_GET_THEN_SUBTRACT
#	elif Q_COMPILER_HAS_FUNCTION(UINT128_ATOMIC_GET_THEN_SUBTRACT)
#		define q_uint128_atomic_get_then_subtract Q_COMPILER_FUNCTION_UINT128_ATOMIC_GET_THEN_SUBTRACT
#		define Q_AVAILABLE_UINT128_ATOMIC_GET_THEN_SUBTRACT
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_GET_THEN_AND)
		Q_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_GET_THEN_AND
#		define Q_AVAILABLE_UINT128_ATOMIC_GET_THEN_AND
#	elif Q_COMPILER_HAS_FUNCTION(UINT128_ATOMIC_GET_THEN_AND)
#		define q_uint128_atomic_get_then_and Q_COMPILER_FUNCTION_UINT128_ATOMIC_GET_THEN_AND
#		define Q_AVAILABLE_UINT128_ATOMIC_GET_THEN_AND
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_GET_THEN_OR)
		Q_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_GET_THEN_OR
#		define Q_AVAILABLE_UINT128_ATOMIC_GET_THEN_OR
#	elif Q_COMPILER_HAS_FUNCTION(UINT128_ATOMIC_GET_THEN_OR)
#		define q_uint128_atomic_get_then_or Q_COMPILER_FUNCTION_UINT128_ATOMIC_GET_THEN_OR
#		define Q_AVAILABLE_UINT128_ATOMIC_GET_THEN_OR
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_GET_THEN_XOR)
		Q_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_GET_THEN_XOR
#		define Q_AVAILABLE_UINT128_ATOMIC_GET_THEN_XOR
#	elif Q_COMPILER_HAS_FUNCTION(UINT128_ATOMIC_GET_THEN_XOR)
#		define q_uint128_atomic_get_then_xor Q_COMPILER_FUNCTION_UINT128_ATOMIC_GET_THEN_XOR
#		define Q_AVAILABLE_UINT128_ATOMIC_GET_THEN_XOR
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_GET_THEN_NOT)
		Q_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_GET_THEN_NOT
#		define Q_AVAILABLE_UINT128_ATOMIC_GET_THEN_NOT
#	elif Q_COMPILER_HAS_FUNCTION(UINT128_ATOMIC_GET_THEN_NOT)
#		define q_uint128_atomic_get_then_not Q_COMPILER_FUNCTION_UINT128_ATOMIC_GET_THEN_NOT
#		define Q_AVAILABLE_UINT128_ATOMIC_GET_THEN_NOT
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_INCREMENT_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_INCREMENT_THEN_GET
#		define Q_AVAILABLE_UINT128_ATOMIC_INCREMENT_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(UINT128_ATOMIC_INCREMENT_THEN_GET)
#		define q_uint128_atomic_increment_then_get Q_COMPILER_FUNCTION_UINT128_ATOMIC_INCREMENT_THEN_GET
#		define Q_AVAILABLE_UINT128_ATOMIC_INCREMENT_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_DECREMENT_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_DECREMENT_THEN_GET
#		define Q_AVAILABLE_UINT128_ATOMIC_DECREMENT_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(UINT128_ATOMIC_DECREMENT_THEN_GET)
#		define q_uint128_atomic_decrement_then_get Q_COMPILER_FUNCTION_UINT128_ATOMIC_DECREMENT_THEN_GET
#		define Q_AVAILABLE_UINT128_ATOMIC_DECREMENT_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_ADD_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_ADD_THEN_GET
#		define Q_AVAILABLE_UINT128_ATOMIC_ADD_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(UINT128_ATOMIC_ADD_THEN_GET)
#		define q_uint128_atomic_add_then_get Q_COMPILER_FUNCTION_UINT128_ATOMIC_ADD_THEN_GET
#		define Q_AVAILABLE_UINT128_ATOMIC_ADD_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_SUBTRACT_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_SUBTRACT_THEN_GET
#		define Q_AVAILABLE_UINT128_ATOMIC_SUBTRACT_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(UINT128_ATOMIC_SUBTRACT_THEN_GET)
#		define q_uint128_atomic_subtract_then_get Q_COMPILER_FUNCTION_UINT128_ATOMIC_SUBTRACT_THEN_GET
#		define Q_AVAILABLE_UINT128_ATOMIC_SUBTRACT_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_AND_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_AND_THEN_GET
#		define Q_AVAILABLE_UINT128_ATOMIC_AND_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(UINT128_ATOMIC_AND_THEN_GET)
#		define q_uint128_atomic_and_then_get Q_COMPILER_FUNCTION_UINT128_ATOMIC_AND_THEN_GET
#		define Q_AVAILABLE_UINT128_ATOMIC_AND_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_OR_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_OR_THEN_GET
#		define Q_AVAILABLE_UINT128_ATOMIC_OR_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(UINT128_ATOMIC_OR_THEN_GET)
#		define q_uint128_atomic_or_then_get Q_COMPILER_FUNCTION_UINT128_ATOMIC_OR_THEN_GET
#		define Q_AVAILABLE_UINT128_ATOMIC_OR_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_XOR_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_XOR_THEN_GET
#		define Q_AVAILABLE_UINT128_ATOMIC_XOR_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(UINT128_ATOMIC_XOR_THEN_GET)
#		define q_uint128_atomic_xor_then_get Q_COMPILER_FUNCTION_UINT128_ATOMIC_XOR_THEN_GET
#		define Q_AVAILABLE_UINT128_ATOMIC_XOR_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_NOT_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_NOT_THEN_GET
#		define Q_AVAILABLE_UINT128_ATOMIC_NOT_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(UINT128_ATOMIC_NOT_THEN_GET)
#		define q_uint128_atomic_not_then_get Q_COMPILER_FUNCTION_UINT128_ATOMIC_NOT_THEN_GET
#		define Q_AVAILABLE_UINT128_ATOMIC_NOT_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_SET_IF_EQUAL)
		Q_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_SET_IF_EQUAL
#		define Q_AVAILABLE_INT128_ATOMIC_SET_IF_EQUAL
#	elif Q_COMPILER_HAS_FUNCTION(INT128_ATOMIC_SET_IF_EQUAL)
#		define q_int128_atomic_set_if_equal Q_COMPILER_FUNCTION_INT128_ATOMIC_SET_IF_EQUAL
#		define Q_AVAILABLE_INT128_ATOMIC_SET_IF_EQUAL
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_GET_THEN_INCREMENT)
		Q_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_GET_THEN_INCREMENT
#		define Q_AVAILABLE_INT128_ATOMIC_GET_THEN_INCREMENT
#	elif Q_COMPILER_HAS_FUNCTION(INT128_ATOMIC_GET_THEN_INCREMENT)
#		define q_int128_atomic_get_then_increment Q_COMPILER_FUNCTION_INT128_ATOMIC_GET_THEN_INCREMENT
#		define Q_AVAILABLE_INT128_ATOMIC_GET_THEN_INCREMENT
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_GET_THEN_DECREMENT)
		Q_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_GET_THEN_DECREMENT
#		define Q_AVAILABLE_INT128_ATOMIC_GET_THEN_DECREMENT
#	elif Q_COMPILER_HAS_FUNCTION(INT128_ATOMIC_GET_THEN_DECREMENT)
#		define q_int128_atomic_get_then_decrement Q_COMPILER_FUNCTION_INT128_ATOMIC_GET_THEN_DECREMENT
#		define Q_AVAILABLE_INT128_ATOMIC_GET_THEN_DECREMENT
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_GET_THEN_ADD)
		Q_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_GET_THEN_ADD
#		define Q_AVAILABLE_INT128_ATOMIC_GET_THEN_ADD
#	elif Q_COMPILER_HAS_FUNCTION(INT128_ATOMIC_GET_THEN_ADD)
#		define q_int128_atomic_get_then_add Q_COMPILER_FUNCTION_INT128_ATOMIC_GET_THEN_ADD
#		define Q_AVAILABLE_INT128_ATOMIC_GET_THEN_ADD
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_GET_THEN_SUBTRACT)
		Q_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_GET_THEN_SUBTRACT
#		define Q_AVAILABLE_INT128_ATOMIC_GET_THEN_SUBTRACT
#	elif Q_COMPILER_HAS_FUNCTION(INT128_ATOMIC_GET_THEN_SUBTRACT)
#		define q_int128_atomic_get_then_subtract Q_COMPILER_FUNCTION_INT128_ATOMIC_GET_THEN_SUBTRACT
#		define Q_AVAILABLE_INT128_ATOMIC_GET_THEN_SUBTRACT
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_GET_THEN_AND)
		Q_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_GET_THEN_AND
#		define Q_AVAILABLE_INT128_ATOMIC_GET_THEN_AND
#	elif Q_COMPILER_HAS_FUNCTION(INT128_ATOMIC_GET_THEN_AND)
#		define q_int128_atomic_get_then_and Q_COMPILER_FUNCTION_INT128_ATOMIC_GET_THEN_AND
#		define Q_AVAILABLE_INT128_ATOMIC_GET_THEN_AND
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_GET_THEN_OR)
		Q_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_GET_THEN_OR
#		define Q_AVAILABLE_INT128_ATOMIC_GET_THEN_OR
#	elif Q_COMPILER_HAS_FUNCTION(INT128_ATOMIC_GET_THEN_OR)
#		define q_int128_atomic_get_then_or Q_COMPILER_FUNCTION_INT128_ATOMIC_GET_THEN_OR
#		define Q_AVAILABLE_INT128_ATOMIC_GET_THEN_OR
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_GET_THEN_XOR)
		Q_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_GET_THEN_XOR
#		define Q_AVAILABLE_INT128_ATOMIC_GET_THEN_XOR
#	elif Q_COMPILER_HAS_FUNCTION(INT128_ATOMIC_GET_THEN_XOR)
#		define q_int128_atomic_get_then_xor Q_COMPILER_FUNCTION_INT128_ATOMIC_GET_THEN_XOR
#		define Q_AVAILABLE_INT128_ATOMIC_GET_THEN_XOR
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_GET_THEN_NOT)
		Q_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_GET_THEN_NOT
#		define Q_AVAILABLE_INT128_ATOMIC_GET_THEN_NOT
#	elif Q_COMPILER_HAS_FUNCTION(INT128_ATOMIC_GET_THEN_NOT)
#		define q_int128_atomic_get_then_not Q_COMPILER_FUNCTION_INT128_ATOMIC_GET_THEN_NOT
#		define Q_AVAILABLE_INT128_ATOMIC_GET_THEN_NOT
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_INCREMENT_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_INCREMENT_THEN_GET
#		define Q_AVAILABLE_INT128_ATOMIC_INCREMENT_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(INT128_ATOMIC_INCREMENT_THEN_GET)
#		define q_int128_atomic_increment_then_get Q_COMPILER_FUNCTION_INT128_ATOMIC_INCREMENT_THEN_GET
#		define Q_AVAILABLE_INT128_ATOMIC_INCREMENT_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_DECREMENT_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_DECREMENT_THEN_GET
#		define Q_AVAILABLE_INT128_ATOMIC_DECREMENT_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(INT128_ATOMIC_DECREMENT_THEN_GET)
#		define q_int128_atomic_decrement_then_get Q_COMPILER_FUNCTION_INT128_ATOMIC_DECREMENT_THEN_GET
#		define Q_AVAILABLE_INT128_ATOMIC_DECREMENT_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_ADD_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_ADD_THEN_GET
#		define Q_AVAILABLE_INT128_ATOMIC_ADD_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(INT128_ATOMIC_ADD_THEN_GET)
#		define q_int128_atomic_add_then_get Q_COMPILER_FUNCTION_INT128_ATOMIC_ADD_THEN_GET
#		define Q_AVAILABLE_INT128_ATOMIC_ADD_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_SUBTRACT_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_SUBTRACT_THEN_GET
#		define Q_AVAILABLE_INT128_ATOMIC_SUBTRACT_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(INT128_ATOMIC_SUBTRACT_THEN_GET)
#		define q_int128_atomic_subtract_then_get Q_COMPILER_FUNCTION_INT128_ATOMIC_SUBTRACT_THEN_GET
#		define Q_AVAILABLE_INT128_ATOMIC_SUBTRACT_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_AND_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_AND_THEN_GET
#		define Q_AVAILABLE_INT128_ATOMIC_AND_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(INT128_ATOMIC_AND_THEN_GET)
#		define q_int128_atomic_and_then_get Q_COMPILER_FUNCTION_INT128_ATOMIC_AND_THEN_GET
#		define Q_AVAILABLE_INT128_ATOMIC_AND_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_OR_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_OR_THEN_GET
#		define Q_AVAILABLE_INT128_ATOMIC_OR_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(INT128_ATOMIC_OR_THEN_GET)
#		define q_int128_atomic_or_then_get Q_COMPILER_FUNCTION_INT128_ATOMIC_OR_THEN_GET
#		define Q_AVAILABLE_INT128_ATOMIC_OR_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_XOR_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_XOR_THEN_GET
#		define Q_AVAILABLE_INT128_ATOMIC_XOR_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(INT128_ATOMIC_XOR_THEN_GET)
#		define q_int128_atomic_xor_then_get Q_COMPILER_FUNCTION_INT128_ATOMIC_XOR_THEN_GET
#		define Q_AVAILABLE_INT128_ATOMIC_XOR_THEN_GET
#	endif

#	if defined(Q_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_NOT_THEN_GET)
		Q_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_NOT_THEN_GET
#		define Q_AVAILABLE_INT128_ATOMIC_NOT_THEN_GET
#	elif Q_COMPILER_HAS_FUNCTION(INT128_ATOMIC_NOT_THEN_GET)
#		define q_int128_atomic_not_then_get Q_COMPILER_FUNCTION_INT128_ATOMIC_NOT_THEN_GET
#		define Q_AVAILABLE_INT128_ATOMIC_NOT_THEN_GET
#	endif

#endif

#define q_value_atomic_set_if_equal(	  TYPE) Q_JOIN_3(q_, Q_##TYPE##_FIXED_TYPE_name, _atomic_set_if_equal	   )
#define q_value_atomic_get_then_increment(TYPE) Q_JOIN_3(q_, Q_##TYPE##_FIXED_TYPE_name, _atomic_get_then_increment)
#define q_value_atomic_get_then_decrement(TYPE) Q_JOIN_3(q_, Q_##TYPE##_FIXED_TYPE_name, _atomic_get_then_decrement)
#define q_value_atomic_get_then_add(	  TYPE) Q_JOIN_3(q_, Q_##TYPE##_FIXED_TYPE_name, _atomic_get_then_add	   )
#define q_value_atomic_get_then_subtract( TYPE) Q_JOIN_3(q_, Q_##TYPE##_FIXED_TYPE_name, _atomic_get_then_subtract )
#define q_value_atomic_get_then_and(	  TYPE) Q_JOIN_3(q_, Q_##TYPE##_FIXED_TYPE_name, _atomic_get_then_and	   )
#define q_value_atomic_get_then_or(	  TYPE) Q_JOIN_3(q_, Q_##TYPE##_FIXED_TYPE_name, _atomic_get_then_or	   )
#define q_value_atomic_get_then_xor(	  TYPE) Q_JOIN_3(q_, Q_##TYPE##_FIXED_TYPE_name, _atomic_get_then_xor	   )
#define q_value_atomic_get_then_not(	  TYPE) Q_JOIN_3(q_, Q_##TYPE##_FIXED_TYPE_name, _atomic_get_then_not	   )
#define q_value_atomic_increment_then_get(TYPE) Q_JOIN_3(q_, Q_##TYPE##_FIXED_TYPE_name, _atomic_increment_then_get)
#define q_value_atomic_decrement_then_get(TYPE) Q_JOIN_3(q_, Q_##TYPE##_FIXED_TYPE_name, _atomic_decrement_then_get)
#define q_value_atomic_add_then_get(	  TYPE) Q_JOIN_3(q_, Q_##TYPE##_FIXED_TYPE_name, _atomic_add_then_get	   )
#define q_value_atomic_subtract_then_get( TYPE) Q_JOIN_3(q_, Q_##TYPE##_FIXED_TYPE_name, _atomic_subtract_then_get )
#define q_value_atomic_and_then_get(	  TYPE) Q_JOIN_3(q_, Q_##TYPE##_FIXED_TYPE_name, _atomic_and_then_get	   )
#define q_value_atomic_or_then_get(	  TYPE) Q_JOIN_3(q_, Q_##TYPE##_FIXED_TYPE_name, _atomic_or_then_get	   )
#define q_value_atomic_xor_then_get(	  TYPE) Q_JOIN_3(q_, Q_##TYPE##_FIXED_TYPE_name, _atomic_xor_then_get	   )
#define q_value_atomic_not_then_get(	  TYPE) Q_JOIN_3(q_, Q_##TYPE##_FIXED_TYPE_name, _atomic_not_then_get	   )


#endif /* __Q_functions_base_value_H__ */
