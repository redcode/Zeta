/* Q API - functions/value.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2014 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_functions_value_H__
#define __Q_functions_value_H__

#include <Q/types/base.h>
#include <Q/macros/value.h>


/* MARK: - Reversion */


#define Q_IMPLEMENTATION_VALUE_REVERSED_IN_LEVEL(bits, level)		\
									\
Q_INLINE								\
quint##bits q_uint##bits##_reversed_in_##level##bit(quint##bits value)	\
	{return Q_##bits##BIT_REVERSED_IN_##level##BIT(value);}		\
									\
Q_INLINE								\
qint##bits q_int##bits##_reversed_in_##level##bit(qint##bits value)	\
	{return Q_##bits##BIT_REVERSED_IN_##level##BIT(value);}


Q_IMPLEMENTATION_VALUE_REVERSED_IN_LEVEL(16,  8)
Q_IMPLEMENTATION_VALUE_REVERSED_IN_LEVEL(32,  8)
Q_IMPLEMENTATION_VALUE_REVERSED_IN_LEVEL(32, 16)
Q_IMPLEMENTATION_VALUE_REVERSED_IN_LEVEL(64,  8)
Q_IMPLEMENTATION_VALUE_REVERSED_IN_LEVEL(64, 16)
Q_IMPLEMENTATION_VALUE_REVERSED_IN_LEVEL(64, 32)

#define q_uint8_reversed(value)	(value)
#define q_uint16_reversed	q_uint16_reversed_in_8bit
#define q_uint32_reversed	q_uint32_reversed_in_8bit
#define q_uint64_reversed	q_uint64_reversed_in_8bit
#define q_int8_reversed(value)	(value)
#define q_int16_reversed	q_int16_reversed_in_8bit
#define q_int32_reversed	q_int32_reversed_in_8bit
#define q_int64_reversed	q_int64_reversed_in_8bit

#if Q_IS_AVAILABLE(UINT128) && Q_IS_AVAILABLE(128BIT_REVERSION_MACROS)

	Q_IMPLEMENTATION_VALUE_REVERSED_IN_LEVEL(128,  8)
	Q_IMPLEMENTATION_VALUE_REVERSED_IN_LEVEL(128, 16)
	Q_IMPLEMENTATION_VALUE_REVERSED_IN_LEVEL(128, 32)
	Q_IMPLEMENTATION_VALUE_REVERSED_IN_LEVEL(128, 64)

#	define q_uint128_reversed	q_uint128_reversed_in_8bit
#	define q_int128_reversed	q_int128_reversed_in_8bit

#endif

#define q_reversed(TYPE) Q_JOIN_3(q_, Q_##TYPE##_FIXED_TYPE_name, _reversed)


/* MARK: - Rotation */


#define Q_IMPLEMENTATION_VALUE_ROTATED(bits)				\
									\
Q_INLINE								\
void q_uint##bits##_rotated_left(quint##bits *value, quint rotation)	\
	{Q_##bits##BIT_ROTATE_LEFT(*value, rotation);}			\
									\
Q_INLINE								\
void q_uint##bits##_rotated_right(quint##bits *value, quint rotation)	\
	{Q_##bits##BIT_ROTATE_RIGHT(*value, rotation);}			\
									\
Q_INLINE								\
void q_int##bits##_rotated_left(qint##bits *value, quint rotation)	\
	{Q_##bits##BIT_ROTATE_LEFT(*value, rotation);}			\
									\
Q_INLINE								\
void q_int##bits##_rotated_right(qint##bits *value, quint rotation)	\
	{Q_##bits##BIT_ROTATE_RIGHT(*value, rotation);}			\


Q_IMPLEMENTATION_VALUE_ROTATED( 8)
Q_IMPLEMENTATION_VALUE_ROTATED(16)
Q_IMPLEMENTATION_VALUE_ROTATED(32)
Q_IMPLEMENTATION_VALUE_ROTATED(64)


/* MARK: - Endianness */


#define Q_IMPLEMENTATION_VALUE_ENDIAN(type, TYPE, endianness)	\
								\
Q_INLINE							\
q##type q_##type##_##endianness##_endian(q##type value)		\
	{return Q_REVERSED(TYPE)(value);}


#if Q_INT16_ENDIANNESS == Q_ENDIANNESS_BIG

#	define q_uint16_big_endian(value) (value)
#	define	q_int16_big_endian(value) (value)
	Q_IMPLEMENTATION_VALUE_ENDIAN(uint16, UINT16, little)
	Q_IMPLEMENTATION_VALUE_ENDIAN( int16,  INT16, little)

#elif Q_INT16_ENDIANNESS == Q_ENDIANNESS_LITTLE

#	define q_uint16_little_endian(value) (value)
#	define	q_int16_little_endian(value) (value)
	Q_IMPLEMENTATION_VALUE_ENDIAN(uint16, UINT16, big)
	Q_IMPLEMENTATION_VALUE_ENDIAN( int16,  INT16, big)

#endif

#if Q_INT32_ENDIANNESS == Q_ENDIANNESS_BIG

#	define q_uint32_big_endian(value) (value)
#	define	q_int32_big_endian(value) (value)
	Q_IMPLEMENTATION_VALUE_ENDIAN(uint32, UINT32, little)
	Q_IMPLEMENTATION_VALUE_ENDIAN( int32,  INT32, little)

#elif Q_INT32_ENDIANNESS == Q_ENDIANNESS_LITTLE

#	define q_uint32_little_endian(value) (value)
#	define	q_int32_little_endian(value) (value)
	Q_IMPLEMENTATION_VALUE_ENDIAN(uint32, UINT32, big)
	Q_IMPLEMENTATION_VALUE_ENDIAN( int32,  INT32, big)

#endif

#if Q_INT64_ENDIANNESS == Q_ENDIANNESS_BIG

#	define q_uint64_big_endian(value) (value)
#	define	q_int64_big_endian(value) (value)
	Q_IMPLEMENTATION_VALUE_ENDIAN(uint64, UINT64, little)
	Q_IMPLEMENTATION_VALUE_ENDIAN( int64,  INT64, little)

#elif Q_INT64_ENDIANNESS == Q_ENDIANNESS_LITTLE

#	define q_uint64_little_endian(value) (value)
#	define	q_int64_little_endian(value) (value)
	Q_IMPLEMENTATION_VALUE_ENDIAN(uint64, UINT64, big)
	Q_IMPLEMENTATION_VALUE_ENDIAN( int64,  INT64, big)

#endif

#if Q_IS_AVAILABLE(UINT128) && Q_IS_AVAILABLE(128BIT_REVERSION_MACROS)
#	if Q_UINT128_ENDIANNESS == Q_ENDIANNESS_BIG

#		define q_uint128_big_endian(value) (value)
		Q_IMPLEMENTATION_VALUE_ENDIAN(uint128, UINT128, little)

#	elif Q_UINT128_ENDIANNESS == Q_ENDIANNESS_LITTLE

#		define q_uint128_little_endian(value) (value)
		Q_IMPLEMENTATION_VALUE_ENDIAN(uint128, UINT128, big)

#	endif
#endif

#if Q_IS_AVAILABLE(INT128) && Q_IS_AVAILABLE(128BIT_REVERSION_MACROS)
#	if Q_INT128_ENDIANNESS == Q_ENDIANNESS_BIG

#		define q_int128_big_endian(value) (value)
		Q_IMPLEMENTATION_VALUE_ENDIAN(int128, INT128, little)

#	elif Q_INT128_ENDIANNESS == Q_ENDIANNESS_LITTLE

#		define q_int128_little_endian(value) (value)
		Q_IMPLEMENTATION_VALUE_ENDIAN(int128, INT128, big)

#	endif
#endif

#define q_big_endian(	TYPE) Q_JOIN_3(q_, Q_##TYPE##_FIXED_TYPE_name, _big_endian   )
#define q_little_endian(TYPE) Q_JOIN_3(q_, Q_##TYPE##_FIXED_TYPE_name, _little_endian)


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


#define Q_IMPLEMENTATION_NATURAL_VALUE(type)					\
										\
										\
Q_INLINE									\
void q_##type##_swap(void *a, void *b)						\
	{									\
	q##type t = *(q##type *)a;						\
										\
	*(q##type *)a = *(q##type *)b;						\
	*(q##type *)b = t;							\
	}									\
										\
										\
Q_INLINE									\
q##type q_##type##_minimum(q##type a, q##type b)				\
	{return Q_MINIMUM(a, b);}						\
										\
										\
Q_INLINE									\
q##type q_##type##_maximum(q##type a, q##type b)				\
	{return Q_MAXIMUM(a, b);}						\
										\
										\
Q_INLINE									\
q##type q_##type##_clamp(q##type value, q##type minimum, q##type maximum)	\
	{									\
	return q_##type##_minimum						\
		(q_##type##_maximum(value, minimum), maximum);			\
	}									\


Q_IMPLEMENTATION_NATURAL_VALUE(uchar  )
Q_IMPLEMENTATION_NATURAL_VALUE(ushort )
Q_IMPLEMENTATION_NATURAL_VALUE(uint   )
Q_IMPLEMENTATION_NATURAL_VALUE(ulong  )
Q_IMPLEMENTATION_NATURAL_VALUE(ullong )
Q_IMPLEMENTATION_NATURAL_VALUE(char   )
Q_IMPLEMENTATION_NATURAL_VALUE(short  )
Q_IMPLEMENTATION_NATURAL_VALUE(int    )
Q_IMPLEMENTATION_NATURAL_VALUE(long   )
Q_IMPLEMENTATION_NATURAL_VALUE(llong  )
Q_IMPLEMENTATION_NATURAL_VALUE(float  )
Q_IMPLEMENTATION_NATURAL_VALUE(double )
Q_IMPLEMENTATION_NATURAL_VALUE(ldouble)
Q_IMPLEMENTATION_NATURAL_VALUE(uint8  )
Q_IMPLEMENTATION_NATURAL_VALUE(uint16 )
Q_IMPLEMENTATION_NATURAL_VALUE(uint32 )
Q_IMPLEMENTATION_NATURAL_VALUE(uint64 )
Q_IMPLEMENTATION_NATURAL_VALUE(int8   )
Q_IMPLEMENTATION_NATURAL_VALUE(int16  )
Q_IMPLEMENTATION_NATURAL_VALUE(int32  )
Q_IMPLEMENTATION_NATURAL_VALUE(int64  )
Q_IMPLEMENTATION_NATURAL_VALUE(size   )
Q_IMPLEMENTATION_NATURAL_VALUE(uintptr)
Q_IMPLEMENTATION_NATURAL_VALUE(uinttop)
Q_IMPLEMENTATION_NATURAL_VALUE(uintmax)
Q_IMPLEMENTATION_NATURAL_VALUE(ssize  )
Q_IMPLEMENTATION_NATURAL_VALUE(intptr )
Q_IMPLEMENTATION_NATURAL_VALUE(inttop )
Q_IMPLEMENTATION_NATURAL_VALUE(intmax )
Q_IMPLEMENTATION_NATURAL_VALUE(natural)
Q_IMPLEMENTATION_NATURAL_VALUE(integer)
Q_IMPLEMENTATION_NATURAL_VALUE(real   )

#define q_pointer_swap q_uintptr_swap


/* MARK: - Operations for integer and real types */


#define Q_IMPLEMENTATION_INTEGER_VALUE(type)				\
									\
									\
Q_INLINE								\
q##type q_##type##_absolute(q##type value)				\
	{return value < (q##type)0 ? -value : value;}			\
									\
									\
Q_INLINE								\
q##type q_##type##_sign(q##type value)					\
	{return value >= (q##type)0 ? (q##type)1 : -(q##type)1;}


Q_IMPLEMENTATION_INTEGER_VALUE(char   )
Q_IMPLEMENTATION_INTEGER_VALUE(short  )
Q_IMPLEMENTATION_INTEGER_VALUE(int    )
Q_IMPLEMENTATION_INTEGER_VALUE(long   )
Q_IMPLEMENTATION_INTEGER_VALUE(llong  )
Q_IMPLEMENTATION_INTEGER_VALUE(float  )
Q_IMPLEMENTATION_INTEGER_VALUE(double )
Q_IMPLEMENTATION_INTEGER_VALUE(ldouble)
Q_IMPLEMENTATION_INTEGER_VALUE(int8   )
Q_IMPLEMENTATION_INTEGER_VALUE(int16  )
Q_IMPLEMENTATION_INTEGER_VALUE(int32  )
Q_IMPLEMENTATION_INTEGER_VALUE(int64  )
Q_IMPLEMENTATION_INTEGER_VALUE(ssize  )
Q_IMPLEMENTATION_INTEGER_VALUE(intptr )
Q_IMPLEMENTATION_INTEGER_VALUE(inttop )
Q_IMPLEMENTATION_INTEGER_VALUE(intmax )
Q_IMPLEMENTATION_INTEGER_VALUE(integer)


/* MARK: - Operations for real types only */


#define Q_IMPLEMENTATION_REAL_VALUE(type, _, epsilon)				\
										\
										\
Q_INLINE									\
qboolean q_##type##_are_almost_equal(q##type a, q##type b)			\
	{return q_##type##_absolute(a - b) <= epsilon;}				\
										\
										\
Q_INLINE									\
q##type q_##type##_lerp(q##type a, q##type b, q##type alpha)			\
	{return a + alpha * (b - a);}						\
										\
										\
Q_INLINE									\
q##type q_##type##_smoothstep(q##type a, q##type b, q##type alpha)		\
	{									\
	if (alpha <= a) return _(0.0);						\
	if (alpha >= b) return _(1.0);						\
	alpha = (alpha - a) / (b - a);						\
	return alpha * alpha * (_(3.0) - _(2.0) * alpha);			\
	}									\
										\
										\
Q_INLINE									\
q##type q_##type##_smootherstep(q##type a, q##type b, q##type alpha)		\
	{									\
	if (alpha <= a) return 0;						\
	if (alpha >= b) return 1;						\
	alpha = (alpha - a) / (b - a);						\
										\
	return	alpha * alpha * alpha *						\
		(alpha * (alpha * _(6.0) - _(15.0)) + _(10.0));			\
	}									\
										\
										\
Q_INLINE									\
qboolean q_##type##_is_nan(q##type value)					\
	{return !(value == value);}						\
										\
										\
Q_INLINE									\
qboolean q_##type##_is_near_zero(q##type value)					\
	{return q_##type##_absolute(value) <= epsilon;}				\
										\
										\
Q_INLINE									\
q##type q_##type##_clamp_01(q##type value)					\
	{return q_##type##_minimum(q_##type##_maximum(value, _(0.0)), _(1.0));}


Q_IMPLEMENTATION_REAL_VALUE(float,   Q_FLOAT,	Q_FLOAT_EPSILON	 )
Q_IMPLEMENTATION_REAL_VALUE(double,  Q_DOUBLE,	Q_DOUBLE_EPSILON )
Q_IMPLEMENTATION_REAL_VALUE(ldouble, Q_LDOUBLE, Q_LDOUBLE_EPSILON)


/* MARK: - Default real type definitions */


#if defined(Q_USE_REAL_FLOAT)

#	define q_are_almost_equal	q_float_are_almost_equal
#	define q_minimum		q_float_minimum
#	define q_maximum		q_float_maximum
#	define q_lerp			q_float_lerp
#	define q_smoothstep		q_float_smoothstep
#	define q_smootherstep		q_float_smootherstep
#	define q_is_nan			q_float_is_nan
#	define q_is_near_zero		q_float_is_near_zero
#	define q_absolute		q_float_absolute
#	define q_sign			q_float_sign
#	define q_clamp			q_float_clamp
#	define q_clamp_01		q_float_clamp_01

#elif defined(Q_USE_REAL_LDOUBLE)

#	define q_are_almost_equal	q_ldouble_are_almost_equal
#	define q_minimum		q_ldouble_minimum
#	define q_maximum		q_ldouble_maximum
#	define q_lerp			q_ldouble_lerp
#	define q_smoothstep		q_ldouble_smoothstep
#	define q_smootherstep		q_ldouble_smootherstep
#	define q_is_nan			q_ldouble_is_nan
#	define q_is_near_zero		q_ldouble_is_near_zero
#	define q_absolute		q_ldouble_absolute
#	define q_sign			q_ldouble_sign
#	define q_clamp			q_ldouble_clamp
#	define q_clamp_01		q_ldouble_clamp_01

#else

#	define q_are_almost_equal	q_double_are_almost_equal
#	define q_minimum		q_double_minimum
#	define q_maximum		q_double_maximum
#	define q_lerp			q_double_lerp
#	define q_smoothstep		q_double_smoothstep
#	define q_smootherstep		q_double_smootherstep
#	define q_is_nan			q_double_is_nan
#	define q_is_near_zero		q_double_is_near_zero
#	define q_absolute		q_double_absolute
#	define q_sign			q_double_sign
#	define q_clamp			q_double_clamp
#	define q_clamp_01		q_double_clamp_01

#endif

#endif /* __Q_functions_value_H__ */
