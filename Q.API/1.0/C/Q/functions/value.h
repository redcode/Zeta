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


/* MARK: - Swapping */


#define Q_IMPLEMENTATION_VALUE_SWAP(type)	\
						\
Q_INLINE					\
void q_##type##_swap(void *a, void *b)		\
	{					\
	q##type t = *(q##type *)a;		\
						\
	*(q##type *)a = *(q##type *)b;		\
	*(q##type *)b = t;			\
	}


Q_IMPLEMENTATION_VALUE_SWAP(pointer)
Q_IMPLEMENTATION_VALUE_SWAP(uchar  )
Q_IMPLEMENTATION_VALUE_SWAP(ushort )
Q_IMPLEMENTATION_VALUE_SWAP(uint   )
Q_IMPLEMENTATION_VALUE_SWAP(ulong  )
Q_IMPLEMENTATION_VALUE_SWAP(ullong )
Q_IMPLEMENTATION_VALUE_SWAP(char   )
Q_IMPLEMENTATION_VALUE_SWAP(short  )
Q_IMPLEMENTATION_VALUE_SWAP(int	   )
Q_IMPLEMENTATION_VALUE_SWAP(long   )
Q_IMPLEMENTATION_VALUE_SWAP(llong  )
Q_IMPLEMENTATION_VALUE_SWAP(float  )
Q_IMPLEMENTATION_VALUE_SWAP(double )
Q_IMPLEMENTATION_VALUE_SWAP(ldouble)
Q_IMPLEMENTATION_VALUE_SWAP(uint8  )
Q_IMPLEMENTATION_VALUE_SWAP(uint16 )
Q_IMPLEMENTATION_VALUE_SWAP(uint32 )
Q_IMPLEMENTATION_VALUE_SWAP(uint64 )
Q_IMPLEMENTATION_VALUE_SWAP(int8   )
Q_IMPLEMENTATION_VALUE_SWAP(int16  )
Q_IMPLEMENTATION_VALUE_SWAP(int32  )
Q_IMPLEMENTATION_VALUE_SWAP(int64  )
Q_IMPLEMENTATION_VALUE_SWAP(size   )
Q_IMPLEMENTATION_VALUE_SWAP(uintptr)
Q_IMPLEMENTATION_VALUE_SWAP(uinttop)
Q_IMPLEMENTATION_VALUE_SWAP(uintmax)
Q_IMPLEMENTATION_VALUE_SWAP(ssize  )
Q_IMPLEMENTATION_VALUE_SWAP(intptr )
Q_IMPLEMENTATION_VALUE_SWAP(inttop )
Q_IMPLEMENTATION_VALUE_SWAP(intmax )
Q_IMPLEMENTATION_VALUE_SWAP(natural)
Q_IMPLEMENTATION_VALUE_SWAP(integer)
Q_IMPLEMENTATION_VALUE_SWAP(real   )


/* MARK: - Reversion */


#define Q_IMPLEMENTATION_VALUE_REVERSED_IN_LEVEL(bits, level)		\
									\
Q_INLINE								\
quint##bits q_uint##bits##_reversed_in_##level##bit(quint##bits value)	\
	{Q_##bits##BIT_REVERSED_IN_##level_bits##BIT(value);}		\
									\
Q_INLINE								\
qint##bits q_int##bits##_reversed_in_##level##bit(qint##bits value)	\
	{Q_##bits##BIT_REVERSED_IN_##level_bits##BIT(value);}


#define Q_IMPLEMENTATION_VALUE_REVERSED(type, TYPE)	\
							\
Q_INLINE						\
q##type q_##type##_reversed(q##type value)		\
	{Q_##TYPE##_REVERSED(value);}


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


/* MARK: - Limits */


#define Q_IMPLEMENTATION_VALUE_LIMITS(type)					\
										\
Q_INLINE									\
q##type q_##type##_minimum(q##type a, q##type b) {return Q_MINIMUM(a, b);}	\
										\
Q_INLINE									\
q##type q_##type##_maximum(q##type a, q##type b) {return Q_MAXIMUM(a, b);}	\
										\
										\
Q_INLINE									\
q##type q_##type##_clamp(q##type value, q##type minimum, q##type maximum)	\
	{									\
	return q_##type##_minimum						\
		(q_##type##_maximum(value, minimum), maximum);			\
	}									\


Q_IMPLEMENTATION_VALUE_LIMITS(uchar  )
Q_IMPLEMENTATION_VALUE_LIMITS(ushort )
Q_IMPLEMENTATION_VALUE_LIMITS(uint   )
Q_IMPLEMENTATION_VALUE_LIMITS(ulong  )
Q_IMPLEMENTATION_VALUE_LIMITS(ullong )
Q_IMPLEMENTATION_VALUE_LIMITS(char   )
Q_IMPLEMENTATION_VALUE_LIMITS(short  )
Q_IMPLEMENTATION_VALUE_LIMITS(int    )
Q_IMPLEMENTATION_VALUE_LIMITS(long   )
Q_IMPLEMENTATION_VALUE_LIMITS(llong  )
Q_IMPLEMENTATION_VALUE_LIMITS(float  )
Q_IMPLEMENTATION_VALUE_LIMITS(double )
Q_IMPLEMENTATION_VALUE_LIMITS(ldouble)
Q_IMPLEMENTATION_VALUE_LIMITS(uint8  )
Q_IMPLEMENTATION_VALUE_LIMITS(uint16 )
Q_IMPLEMENTATION_VALUE_LIMITS(uint32 )
Q_IMPLEMENTATION_VALUE_LIMITS(uint64 )
Q_IMPLEMENTATION_VALUE_LIMITS(int8   )
Q_IMPLEMENTATION_VALUE_LIMITS(int16  )
Q_IMPLEMENTATION_VALUE_LIMITS(int32  )
Q_IMPLEMENTATION_VALUE_LIMITS(int64  )
Q_IMPLEMENTATION_VALUE_LIMITS(size   )
Q_IMPLEMENTATION_VALUE_LIMITS(uintptr)
Q_IMPLEMENTATION_VALUE_LIMITS(uinttop)
Q_IMPLEMENTATION_VALUE_LIMITS(uintmax)
Q_IMPLEMENTATION_VALUE_LIMITS(ssize  )
Q_IMPLEMENTATION_VALUE_LIMITS(intptr )
Q_IMPLEMENTATION_VALUE_LIMITS(inttop )
Q_IMPLEMENTATION_VALUE_LIMITS(intmax )
Q_IMPLEMENTATION_VALUE_LIMITS(natural)
Q_IMPLEMENTATION_VALUE_LIMITS(integer)
Q_IMPLEMENTATION_VALUE_LIMITS(real   )


/* MARK: - Interpolation */


#define Q_IMPLEMENTATION_VALUE_INTERPOLATION(type)		\
								\
Q_INLINE							\
q##type q_##type##_lerp(q##type a, q##type b, q##type alpha)	\
	{return (b * amount) + (a * ((q##type)1 - alpha));}


Q_IMPLEMENTATION_VALUE_INTERPOLATION(float  )
Q_IMPLEMENTATION_VALUE_INTERPOLATION(double )
Q_IMPLEMENTATION_VALUE_INTERPOLATION(ldouble)


#endif /* __Q_functions_value_H__ */
