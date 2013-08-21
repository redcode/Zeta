/* Q API - functions/value.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2013 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_functions_value_H__
#define __Q_functions_value_H__

#include <Q/types/basics.h>
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


#define Q_IMPLEMENTATION_VALUE_REVERSED(type, TYPE)	\
							\
Q_INLINE						\
q##type q_##type##_reversed(q##type value)		\
	{return Q_##TYPE##_REVERSED(value);}


Q_IMPLEMENTATION_VALUE_REVERSED_IN_LEVEL(16,  8)
Q_IMPLEMENTATION_VALUE_REVERSED_IN_LEVEL(32,  8)
Q_IMPLEMENTATION_VALUE_REVERSED_IN_LEVEL(32, 16)
Q_IMPLEMENTATION_VALUE_REVERSED_IN_LEVEL(64,  8)
Q_IMPLEMENTATION_VALUE_REVERSED_IN_LEVEL(64, 16)
Q_IMPLEMENTATION_VALUE_REVERSED_IN_LEVEL(64, 32)

Q_IMPLEMENTATION_VALUE_REVERSED(ushort,	 USHORT	)
Q_IMPLEMENTATION_VALUE_REVERSED(uint,	 UINT	)
Q_IMPLEMENTATION_VALUE_REVERSED(ulong,	 ULONG	)
Q_IMPLEMENTATION_VALUE_REVERSED(ullong,	 ULLONG	)
Q_IMPLEMENTATION_VALUE_REVERSED(short,	 SHORT	)
Q_IMPLEMENTATION_VALUE_REVERSED(int,	 INT	)
Q_IMPLEMENTATION_VALUE_REVERSED(long,	 LONG	)
Q_IMPLEMENTATION_VALUE_REVERSED(llong,	 LLONG	)
Q_IMPLEMENTATION_VALUE_REVERSED(uint16,	 UINT16	)
Q_IMPLEMENTATION_VALUE_REVERSED(uint32,	 UINT32	)
Q_IMPLEMENTATION_VALUE_REVERSED(uint64,	 UINT64	)
Q_IMPLEMENTATION_VALUE_REVERSED(int16,	 INT16	)
Q_IMPLEMENTATION_VALUE_REVERSED(int32,	 INT32	)
Q_IMPLEMENTATION_VALUE_REVERSED(int64,	 INT64	)
Q_IMPLEMENTATION_VALUE_REVERSED(size,	 SIZE	)
Q_IMPLEMENTATION_VALUE_REVERSED(uintptr, UINTPTR)
Q_IMPLEMENTATION_VALUE_REVERSED(uinttop, UINTTOP)
Q_IMPLEMENTATION_VALUE_REVERSED(uintmax, UINTMAX)
Q_IMPLEMENTATION_VALUE_REVERSED(ssize,	 SSIZE	)
Q_IMPLEMENTATION_VALUE_REVERSED(intptr,	 INTPTR	)
Q_IMPLEMENTATION_VALUE_REVERSED(inttop,	 INTTOP	)
Q_IMPLEMENTATION_VALUE_REVERSED(intmax,	 INTMAX	)
Q_IMPLEMENTATION_VALUE_REVERSED(natural, NATURAL)
Q_IMPLEMENTATION_VALUE_REVERSED(integer, INTEGER)

#if Q_CHAR_BITS > 8
	Q_IMPLEMENTATION_VALUE_REVERSED(char,	CHAR)
	Q_IMPLEMENTATION_VALUE_REVERSED(uchar, UCHAR)
#endif

#if Q_IS_AVAILABLE(UINT128) && Q_IS_AVAILABLE(128BIT_REVERSION_MACROS)

	Q_IMPLEMENTATION_VALUE_REVERSED_IN_LEVEL(128,  8)
	Q_IMPLEMENTATION_VALUE_REVERSED_IN_LEVEL(128, 16)
	Q_IMPLEMENTATION_VALUE_REVERSED_IN_LEVEL(128, 32)
	Q_IMPLEMENTATION_VALUE_REVERSED_IN_LEVEL(128, 64)

	Q_IMPLEMENTATION_VALUE_REVERSED(uint128, UINT128)

#endif

#if Q_IS_AVAILABLE(INT128) && Q_IS_AVAILABLE(128BIT_REVERSION_MACROS)
	Q_IMPLEMENTATION_VALUE_REVERSED(int128, INT128)
#endif


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
	{return Q_##TYPE##_REVERSED(value);}


#if Q_CHAR_BITS > 8
#	if Q_CHAR_ENDIANNESS == Q_ENDIANNESS_BIG

#		define q_uchar_big_endian(value) (value)
#		define	q_char_big_endian(value) (value)
		Q_IMPLEMENTATION_VALUE_ENDIAN(uchar, UCHAR, little)
		Q_IMPLEMENTATION_VALUE_ENDIAN( char,  CHAR,  little)

#	elif Q_CHAR_ENDIANNESS == Q_ENDIANNESS_LITTLE

#		define q_uchar_little_endian(value) (value)
#		define	q_char_little_endian(value) (value)
		Q_IMPLEMENTATION_VALUE_ENDIAN(uchar, UCHAR, big)
		Q_IMPLEMENTATION_VALUE_ENDIAN( char,  CHAR, big)

#	endif
#endif

#if Q_SHORT_ENDIANNESS == Q_ENDIANNESS_BIG

#	define q_ushort_big_endian(value) (value)
#	define	q_short_big_endian(value) (value)
	Q_IMPLEMENTATION_VALUE_ENDIAN(ushort, USHORT, little)
	Q_IMPLEMENTATION_VALUE_ENDIAN( short,  SHORT, little)

#elif Q_SHORT_ENDIANNESS == Q_ENDIANNESS_LITTLE

#	define q_ushort_little_endian(value) (value)
#	define	q_short_little_endian(value) (value)
	Q_IMPLEMENTATION_VALUE_ENDIAN(ushort, USHORT, big)
	Q_IMPLEMENTATION_VALUE_ENDIAN( short,  SHORT, big)

#endif

#if Q_INT_ENDIANNESS == Q_ENDIANNESS_BIG

#	define q_uint_big_endian(value) (value)
#	define	q_int_big_endian(value) (value)
	Q_IMPLEMENTATION_VALUE_ENDIAN(uint, UINT, little)
	Q_IMPLEMENTATION_VALUE_ENDIAN( int,  INT, little)

#elif Q_INT_ENDIANNESS == Q_ENDIANNESS_LITTLE

#	define q_uint_little_endian(value) (value)
#	define	q_int_little_endian(value) (value)
	Q_IMPLEMENTATION_VALUE_ENDIAN(uint, UINT, big)
	Q_IMPLEMENTATION_VALUE_ENDIAN( int,  INT, big)

#endif

#if Q_LONG_ENDIANNESS == Q_ENDIANNESS_BIG

#	define q_ulong_big_endian(value) (value)
#	define	q_long_big_endian(value) (value)
	Q_IMPLEMENTATION_VALUE_ENDIAN(ulong, ULONG, little)
	Q_IMPLEMENTATION_VALUE_ENDIAN( long,  LONG, little)

#elif Q_LONG_ENDIANNESS == Q_ENDIANNESS_LITTLE

#	define q_ulong_little_endian(value) (value)
#	define	q_long_little_endian(value) (value)
	Q_IMPLEMENTATION_VALUE_ENDIAN(ulong, ULONG, big)
	Q_IMPLEMENTATION_VALUE_ENDIAN( long,  LONG, big)

#endif

#if Q_LLONG_ENDIANNESS == Q_ENDIANNESS_BIG

#	define q_ullong_big_endian(value) (value)
#	define	q_llong_big_endian(value) (value)
	Q_IMPLEMENTATION_VALUE_ENDIAN(ullong, ULLONG, little)
	Q_IMPLEMENTATION_VALUE_ENDIAN( llong,  LLONG, little)

#elif Q_LLONG_ENDIANNESS == Q_ENDIANNESS_LITTLE

#	define q_ullong_little_endian(value) (value)
#	define	q_llong_little_endian(value) (value)
	Q_IMPLEMENTATION_VALUE_ENDIAN(ullong, ULLONG, big)
	Q_IMPLEMENTATION_VALUE_ENDIAN( llong,  LLONG, big)

#endif

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

#if Q_SIZE_ENDIANNESS == Q_ENDIANNESS_BIG

#	define	q_size_big_endian(value) (value)
#	define q_ssize_big_endian(value) (value)
	Q_IMPLEMENTATION_VALUE_ENDIAN(size,   SIZE, little)
	Q_IMPLEMENTATION_VALUE_ENDIAN(ssize, SSIZE, little)

#elif Q_SIZE_ENDIANNESS == Q_ENDIANNESS_LITTLE

#	define	q_size_little_endian(value) (value)
#	define q_ssize_little_endian(value) (value)
	Q_IMPLEMENTATION_VALUE_ENDIAN(size,   SIZE, big)
	Q_IMPLEMENTATION_VALUE_ENDIAN(ssize, SSIZE, big)

#endif

#if Q_INTPTR_ENDIANNESS == Q_ENDIANNESS_BIG

#	define q_uintptr_big_endian(value) (value)
#	define	q_intptr_big_endian(value) (value)
	Q_IMPLEMENTATION_VALUE_ENDIAN(uintptr, UINTPTR, little)
	Q_IMPLEMENTATION_VALUE_ENDIAN( intptr,  INTPTR, little)

#elif Q_INTPTR_ENDIANNESS == Q_ENDIANNESS_LITTLE

#	define q_uintptr_little_endian(value) (value)
#	define	q_intptr_little_endian(value) (value)
	Q_IMPLEMENTATION_VALUE_ENDIAN(uintptr, UINTPTR, big)
	Q_IMPLEMENTATION_VALUE_ENDIAN( intptr,  INTPTR, big)

#endif

#if Q_INTTOP_ENDIANNESS == Q_ENDIANNESS_BIG

#	define q_uinttop_big_endian(value) (value)
#	define	q_inttop_big_endian(value) (value)
	Q_IMPLEMENTATION_VALUE_ENDIAN(uinttop, UINTTOP, little)
	Q_IMPLEMENTATION_VALUE_ENDIAN( inttop,  INTTOP, little)

#elif Q_INTTOP_ENDIANNESS == Q_ENDIANNESS_LITTLE

#	define q_uinttop_little_endian(value) (value)
#	define	q_inttop_little_endian(value) (value)
	Q_IMPLEMENTATION_VALUE_ENDIAN(uinttop, UINTTOP, big)
	Q_IMPLEMENTATION_VALUE_ENDIAN( inttop,  INTTOP, big)

#endif

#if Q_INTMAX_ENDIANNESS == Q_ENDIANNESS_BIG

#	define q_uintmax_big_endian(value) (value)
#	define	q_intmax_big_endian(value) (value)
	Q_IMPLEMENTATION_VALUE_ENDIAN(uintmax, UINTMAX, little)
	Q_IMPLEMENTATION_VALUE_ENDIAN( intmax,  INTMAX, little)

#elif Q_INTMAX_ENDIANNESS == Q_ENDIANNESS_LITTLE

#	define q_uintmax_little_endian(value) (value)
#	define	q_intmax_little_endian(value) (value)
	Q_IMPLEMENTATION_VALUE_ENDIAN(uintmax, UINTMAX, big)
	Q_IMPLEMENTATION_VALUE_ENDIAN( intmax,  INTMAX, big)

#endif

#if Q_NATURAL_ENDIANNESS == Q_ENDIANNESS_BIG

#	define q_natural_big_endian(value) (value)
	Q_IMPLEMENTATION_VALUE_ENDIAN(natural, NATURAL, little)

#elif Q_NATURAL_ENDIANNESS == Q_ENDIANNESS_LITTLE

#	define q_natural_little_endian(value) (value)
	Q_IMPLEMENTATION_VALUE_ENDIAN(natural, NATURAL, big)

#endif

#if Q_INTEGER_ENDIANNESS == Q_ENDIANNESS_BIG

#	define q_integer_big_endian(value) (value)
	Q_IMPLEMENTATION_VALUE_ENDIAN(integer, INTEGER, little)

#elif Q_INTEGER_ENDIANNESS == Q_ENDIANNESS_LITTLE

#	define q_integer_little_endian(value) (value)
	Q_IMPLEMENTATION_VALUE_ENDIAN(integer, INTEGER, big)

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


#define Q_IMPLEMENTATION_INTEGER_VALUE(type, zero)	\
							\
Q_INLINE						\
q##type q_##type##_absolute(q##type value)		\
	{return value < zero ? -value : value;}


Q_IMPLEMENTATION_INTEGER_VALUE(char,	Q_CHAR(	  0)  )
Q_IMPLEMENTATION_INTEGER_VALUE(short,	Q_SHORT(  0)  )
Q_IMPLEMENTATION_INTEGER_VALUE(int,	Q_INT(	  0)  )
Q_IMPLEMENTATION_INTEGER_VALUE(long,	Q_LONG(	  0)  )
Q_IMPLEMENTATION_INTEGER_VALUE(llong,	Q_LLONG(  0)  )
Q_IMPLEMENTATION_INTEGER_VALUE(float,		  0.0F)
Q_IMPLEMENTATION_INTEGER_VALUE(double,		  0.0 )
Q_IMPLEMENTATION_INTEGER_VALUE(ldouble,		  0.0L)
Q_IMPLEMENTATION_INTEGER_VALUE(int8,	Q_INT8(	  0)  )
Q_IMPLEMENTATION_INTEGER_VALUE(int16,	Q_INT16(  0)  )
Q_IMPLEMENTATION_INTEGER_VALUE(int32,	Q_INT32(  0)  )
Q_IMPLEMENTATION_INTEGER_VALUE(int64,	Q_INT64(  0)  )
Q_IMPLEMENTATION_INTEGER_VALUE(ssize,	Q_SSIZE(  0)  )
Q_IMPLEMENTATION_INTEGER_VALUE(intptr,	Q_INTPTR( 0)  )
Q_IMPLEMENTATION_INTEGER_VALUE(inttop,	Q_INTTOP( 0)  )
Q_IMPLEMENTATION_INTEGER_VALUE(intmax,	Q_INTMAX( 0)  )
Q_IMPLEMENTATION_INTEGER_VALUE(integer, Q_INTEGER(0)  )
Q_IMPLEMENTATION_INTEGER_VALUE(real,	Q_REAL(	  0.0))


/* MARK: - Operations for real types only */


#define Q_IMPLEMENTATION_REAL_VALUE(type, epsilon)		\
								\
								\
Q_INLINE							\
qboolean q_##type##_are_almost_equal(q##type a, q##type b)	\
	{return q_##type##_absolute(a - b) <= epsilon;}		\
								\
								\
Q_INLINE							\
q##type q_##type##_lerp(q##type a, q##type b, q##type alpha)	\
	{return a + alpha * (b - a);}				\
								\
								\
Q_INLINE							\
q_##type##_is_nan(q##type value)				\
	{return !(value == value);}				\
								\
								\
Q_INLINE							\
qboolean q_##type##_is_near_zero(q##type value)			\
	{q_##type##_absolute(value) <= epsilon;}


Q_IMPLEMENTATION_REAL_VALUE(float,   Q_FLOAT_EPSILON  )
Q_IMPLEMENTATION_REAL_VALUE(double,  Q_DOUBLE_EPSILON )
Q_IMPLEMENTATION_REAL_VALUE(ldouble, Q_LDOUBLE_EPSILON)


/* MARK: - Default real type definitions */


#if defined(Q_USE_REAL_FLOAT)

#	define q_are_almost_equal	q_float_are_almost_equal
#	define q_minimum		q_float_minimum
#	define q_maximum		q_float_maximum
#	define q_lerp			q_float_lerp
#	define q_is_nan			q_float_is_nan
#	define q_is_near_zero		q_float_is_near_zero
#	define q_absolute		q_float_absolute
#	define q_clamp			q_float_clamp

#elif defined(Q_USE_REAL_LDOUBLE)

#	define q_are_almost_equal	q_ldouble_are_almost_equal
#	define q_minimum		q_ldouble_minimum
#	define q_maximum		q_ldouble_maximum
#	define q_lerp			q_ldouble_lerp
#	define q_is_nan			q_ldouble_is_nan
#	define q_absolute		q_ldouble_absolute
#	define q_is_near_zero		q_ldouble_is_near_zero
#	define q_clamp			q_ldouble_clamp

#else

#	define q_are_almost_equal	q_double_are_almost_equal
#	define q_minimum		q_double_minimum
#	define q_maximum		q_double_maximum
#	define q_lerp			q_double_lerp
#	define q_is_nan			q_double_is_nan
#	define q_absolute		q_double_absolute
#	define q_is_near_zero		q_double_is_near_zero
#	define q_clamp			q_double_clamp

#endif

#endif /* __Q_functions_value_H__ */
