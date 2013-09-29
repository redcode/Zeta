/* Q API - macros/value.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2013 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_macros_value_H__
#define __Q_macros_value_H__

#include <Q/types/base.h>

/* MARK: - Basics */

#define Q_ABSOLUTE(value) ((a) < 0 ? -(a) : (a))

/* MARK: - Limits */

#define Q_MAXIMUM(a, b) ((a) > (b) ? (a) : (b))
#define Q_MINIMUM(a, b) ((a) < (b) ? (a) : (b))

/* MARK: - Masked Bounded Addition/Subtraction */

#define Q_MBA(value, delta, mask)			 \
	(((value) & (mask)) + ((delta) & (mask)) > (mask) \
		? (mask) : ((value) & (mask)) + ((delta) & (mask)))

#define Q_MBS(value, delta, mask)			 \
	(((value) & (mask)) - ((delta) & (mask)) > (mask) \
		? 0 : ((value) & (mask)) - ((delta) & (mask)))

/* MARK: - Mirroring */

#define Q_UINT16_FROM_UINT8_MIRROR( value) (((quint16 )(value)) *	   0x0101)
#define Q_UINT32_FROM_UINT8_MIRROR( value) (((quint32 )(value)) * Q_UINT32(0x01010101))
#define Q_UINT32_FROM_UINT16_MIRROR(value) (((quint32 )(value)) * Q_UINT32(0x00010001))
#define Q_UINT64_FROM_UINT8_MIRROR( value) (((quint64 )(value)) * Q_UINT64(0x0101010101010101))
#define Q_UINT64_FROM_UINT16_MIRROR(value) (((quint64 )(value)) * Q_UINT64(0x0001000100010001))
#define Q_UINT64_FROM_UINT32_MIRROR(value) (((quint64 )(value)) * Q_UINT64(0x0000000100000001))

#if Q_IS_AVAILABLE(UINT128)

#	if Q_COMPILER_HAS(UINT128_LITERAL)

#		define Q_UINT128_FROM_UINT8_MIRROR( value) (((quint128)(value)) * Q_UINT128(0x01010101010101010101010101010101))
#		define Q_UINT128_FROM_UINT16_MIRROR(value) (((quint128)(value)) * Q_UINT128(0x00010001000100010001000100010001))
#		define Q_UINT128_FROM_UINT32_MIRROR(value) (((quint128)(value)) * Q_UINT128(0x00000001000000010000000100000001))
#		define Q_UINT128_FROM_UINT64_MIRROR(value) (((quint128)(value)) * Q_UINT128(0x00000000000000010000000000000001))

#		define Q_AVAILABLE_128BIT_MIRRORING_MACROS

#	elif Q_C_HAS(COMPOUND_LITERAL)

#		define Q_UINT128_FROM_UINT8_MIRROR(value)				\
			(((quint128)value) * ((Q128Bit){				\
				.uint64_values.index0 = Q_UINT64(0x0101010101010101),	\
				.uint64_values.index1 = Q_UINT64(0x0101010101010101)	\
			}).uint128_value)

#		define Q_UINT128_FROM_UINT16_MIRROR(value)				\
			(((quint128)value) * ((Q128Bit){				\
				.uint64_values.index0 = Q_UINT64(0x0001000100010001),	\
				.uint64_values.index1 = Q_UINT64(0x0001000100010001)	\
			}).uint128_value)

#		define Q_UINT128_FROM_UINT32_MIRROR(value)				\
			(((quint128)value) * ((Q128Bit){				\
				.uint64_values.index0 = Q_UINT64(0x0000000100000001),	\
				.uint64_values.index1 = Q_UINT64(0x0000000100000001)	\
			}).uint128_value)

#		define Q_UINT128_FROM_UINT64_MIRROR(value)				\
			(((quint128)value) * ((Q128Bit){				\
				.uint64_values.index0 = Q_UINT64(0x0000000000000001),	\
				.uint64_values.index1 = Q_UINT64(0x0000000000000001)	\
			}).uint128_value)

#		define Q_AVAILABLE_128BIT_MIRRORING_MACROS

#	endif

#endif

#if Q_UINTTOP_BITS == 32

#	define Q_UINTTOP_FROM_UINT8_MIRROR  Q_UINT32_FROM_UINT8_MIRROR
#	define Q_UINTTOP_FROM_UINT16_MIRROR Q_UINT32_FROM_UINT16_MIRROR

#elif Q_UINTTOP_BITS == 64

#	define Q_UINTTOP_FROM_UINT8_MIRROR  Q_UINT64_FROM_UINT8_MIRROR
#	define Q_UINTTOP_FROM_UINT16_MIRROR Q_UINT64_FROM_UINT16_MIRROR
#	define Q_UINTTOP_FROM_UINT32_MIRROR Q_UINT64_FROM_UINT32_MIRROR

#elif Q_UINTTOP_BITS == 128 && \
      Q_IS_AVAILABLE(128BIT_MIRRORING_MACROS)

#	define Q_UINTTOP_FROM_UINT8_MIRROR  Q_UINT128_FROM_UINT8_MIRROR
#	define Q_UINTTOP_FROM_UINT16_MIRROR Q_UINT128_FROM_UINT16_MIRROR
#	define Q_UINTTOP_FROM_UINT32_MIRROR Q_UINT128_FROM_UINT32_MIRROR
#	define Q_UINTTOP_FROM_UINT64_MIRROR Q_UINT128_FROM_UINT64_MIRROR

#endif

/* MARK: - Reversion */

#define Q_8BIT_REVERSED_IN_8BIT(  value)   (value)
#define	Q_16BIT_REVERSED_IN_8BIT( value) (((value) <<  8) | ((value) >>  8))
#define	Q_32BIT_REVERSED_IN_16BIT(value) (((value) << 16) | ((value) >> 16))
#define	Q_64BIT_REVERSED_IN_32BIT(value) (((value) << 32) | ((value) >> 32))

#define	Q_32BIT_REVERSED_IN_8BIT(value)		 \
	( ( (value)			  << 24) \
	| (((value) & Q_UINT32(0x00FF00)) <<  8) \
	| (((value) & Q_UINT32(0xFF0000)) >>  8) \
	| ( (value)			  >> 24) )

#define	Q_64BIT_REVERSED_IN_8BIT(value)			 \
	( ( (value)				  << 56) \
	| (((value) & Q_UINT64(0x0000000000FF00)) << 40) \
	| (((value) & Q_UINT64(0x00000000FF0000)) << 24) \
	| (((value) & Q_UINT64(0x000000FF000000)) <<  8) \
	| (((value) & Q_UINT64(0x0000FF00000000)) >>  8) \
	| (((value) & Q_UINT64(0x00FF0000000000)) >> 24) \
	| (((value) & Q_UINT64(0xFF000000000000)) >> 40) \
	| ( (value)				  >> 56) )

#define	Q_64BIT_REVERSED_IN_16BIT(value)	       \
	( ( (value)				<< 48) \
	| (((value) & Q_UINT64(0x0000FFFF0000)) << 16) \
	| (((value) & Q_UINT64(0xFFFF00000000)) >> 16) \
	| ( (value)				>> 48) )

#define Q_16BIT_REVERSE_IN_8BIT( value) ((value) = Q_16BIT_REVERSED_IN_8BIT( value))
#define Q_32BIT_REVERSE_IN_8BIT( value) ((value) = Q_32BIT_REVERSED_IN_8BIT( value))
#define Q_32BIT_REVERSE_IN_16BIT(value) ((value) = Q_32BIT_REVERSED_IN_16BIT(value))
#define Q_64BIT_REVERSE_IN_8BIT( value) ((value) = Q_64BIT_REVERSED_IN_8BIT( value))
#define Q_64BIT_REVERSE_IN_16BIT(value) ((value) = Q_64BIT_REVERSED_IN_16BIT(value))
#define Q_64BIT_REVERSE_IN_32BIT(value) ((value) = Q_64BIT_REVERSED_IN_32BIT(value))

#if Q_IS_AVAILABLE(UINT128) && \
    Q_COMPILER_HAS(UINT128_LITERAL)

#	define Q_128BIT_REVERSED_IN_8BIT(value)					   \
		( ( (value)						   << 120) \
		| (((value) & Q_UINT128(0x00000000000000000000000000FF00)) << 104) \
		| (((value) & Q_UINT128(0x000000000000000000000000FF0000)) <<  88) \
		| (((value) & Q_UINT128(0x0000000000000000000000FF000000)) <<  72) \
		| (((value) & Q_UINT128(0x00000000000000000000FF00000000)) <<  56) \
		| (((value) & Q_UINT128(0x000000000000000000FF0000000000)) <<  40) \
		| (((value) & Q_UINT128(0x0000000000000000FF000000000000)) <<  24) \
		| (((value) & Q_UINT128(0x00000000000000FF00000000000000)) <<   8) \
		| (((value) & Q_UINT128(0x000000000000FF0000000000000000)) >>   8) \
		| (((value) & Q_UINT128(0x0000000000FF000000000000000000)) >>  24) \
		| (((value) & Q_UINT128(0x00000000FF00000000000000000000)) >>  40) \
		| (((value) & Q_UINT128(0x000000FF0000000000000000000000)) >>  56) \
		| (((value) & Q_UINT128(0x0000FF000000000000000000000000)) >>  72) \
		| (((value) & Q_UINT128(0x00FF00000000000000000000000000)) >>  88) \
		| (((value) & Q_UINT128(0xFF0000000000000000000000000000)) >> 104) \
		| ( (value)						   >> 120) )

#	define Q_128BIT_REVERSED_IN_16BIT(value)				 \
		( ( (value)						 << 112) \
		| (((value) & Q_UINT128(0x00000000000000000000FFFF0000)) <<  80) \
		| (((value) & Q_UINT128(0x0000000000000000FFFF00000000)) <<  48) \
		| (((value) & Q_UINT128(0x000000000000FFFF000000000000)) <<  16) \
		| (((value) & Q_UINT128(0x00000000FFFF0000000000000000)) >>  16) \
		| (((value) & Q_UINT128(0x0000FFFF00000000000000000000)) >>  48) \
		| (((value) & Q_UINT128(0xFFFF000000000000000000000000)) >>  80) \
		| ( (value)						 >> 112) )

#	define Q_128BIT_REVERSED_IN_32BIT(value)			    \
		( ( (value)					     << 96) \
		| (((value) & Q_UINT128(0x00000000FFFFFFFF00000000)) << 32) \
		| (((value) & Q_UINT128(0xFFFFFFFF0000000000000000)) >> 32) \
		| ( (value)					     >> 96) )

#	define Q_128BIT_REVERSED_IN_64BIT(value) (((value) << 64) | ((value) >> 64))

#	define Q_128BIT_REVERSE_IN_8BIT(  value) ((value) = Q_128BIT_REVERSED_IN_8BIT( value))
#	define Q_128BIT_REVERSE_IN_16BIT( value) ((value) = Q_128BIT_REVERSED_IN_16BIT(value))
#	define Q_128BIT_REVERSE_IN_32BIT( value) ((value) = Q_128BIT_REVERSED_IN_32BIT(value))
#	define Q_128BIT_REVERSE_IN_64BIT( value) ((value) = Q_128BIT_REVERSED_IN_64BIT(value))

#	define Q_AVAILABLE_128BIT_REVERSION_MACROS

#endif

#define Q_REVERSED(TYPE) Q_JOIN_3(Q_, Q_##TYPE##_BITS, BIT_REVERSED_IN_8BIT)
#define Q_REVERSE( TYPE) Q_JOIN_3(Q_, Q_##TYPE##_BITS, BIT_REVERSE_IN_8BIT )

/* MARK: - Rotation */

#define Q_8BIT_ROTATED_LEFT(  value, rotation) (((value) << (rotation)) | ((value) >> ( 8 - (rotation))))
#define Q_8BIT_ROTATED_RIGHT( value, rotation) (((value) >> (rotation)) | ((value) << ( 8 - (rotation))))
#define Q_16BIT_ROTATED_LEFT( value, rotation) (((value) << (rotation)) | ((value) >> (16 - (rotation))))
#define Q_16BIT_ROTATED_RIGHT(value, rotation) (((value) >> (rotation)) | ((value) << (16 - (rotation))))
#define Q_32BIT_ROTATED_LEFT( value, rotation) (((value) << (rotation)) | ((value) >> (32 - (rotation))))
#define Q_32BIT_ROTATED_RIGHT(value, rotation) (((value) >> (rotation)) | ((value) << (32 - (rotation))))
#define Q_64BIT_ROTATED_LEFT( value, rotation) (((value) << (rotation)) | ((value) >> (64 - (rotation))))
#define Q_64BIT_ROTATED_RIGHT(value, rotation) (((value) >> (rotation)) | ((value) << (64 - (rotation))))

#define Q_8BIT_ROTATE_LEFT(   value, rotation) ((value) = Q_8BIT_ROTATED_LEFT  (value, rotation))
#define Q_8BIT_ROTATE_RIGHT(  value, rotation) ((value) = Q_8BIT_ROTATED_RIGHT (value, rotation))
#define Q_16BIT_ROTATE_LEFT(  value, rotation) ((value) = Q_8BIT_ROTATED_LEFT  (value, rotation))
#define Q_16BIT_ROTATE_RIGHT( value, rotation) ((value) = Q_16BIT_ROTATED_RIGHT(value, rotation))
#define Q_32BIT_ROTATE_LEFT(  value, rotation) ((value) = Q_32BIT_ROTATED_LEFT (value, rotation))
#define Q_32BIT_ROTATE_RIGHT( value, rotation) ((value) = Q_32BIT_ROTATED_RIGHT(value, rotation))
#define Q_64BIT_ROTATE_LEFT(  value, rotation) ((value) = Q_64BIT_ROTATED_LEFT (value, rotation))
#define Q_64BIT_ROTATE_RIGHT( value, rotation) ((value) = Q_64BIT_ROTATED_RIGHT(value, rotation))

#if Q_UINT128_IS_AVAILABLE

#	define Q_128BIT_ROTATED_LEFT( value, rotation) (((value) << (rotation)) | ((value) >> (128 - (rotation))))
#	define Q_128BIT_ROTATED_RIGHT(value, rotation) (((value) >> (rotation)) | ((value) << (128 - (rotation))))

#	define Q_128BIT_ROTATE_LEFT(  value, rotation) ((value) = Q_128BIT_ROTATED_LEFT (value, rotation))
#	define Q_128BIT_ROTATE_RIGHT( value, rotation) ((value) = Q_128BIT_ROTATED_RIGHT(value, rotation))

#	define Q_AVAILABLE_128BIT_ROTATION_MACROS

#endif

/* MARK: - Shift */

#define Q_32BIT_FROM_8BIT_DCBA(d, c, b, a)	\
	((((quint32)(d)) << 24) |		\
	 (((quint32)(c)) << 16) |		\
	 (((quint32)(b)) <<  8) |		\
	  ((quint32)(a)))

#define Q_32BIT_FROM_8BIT_0CBA(c, b, a)		\
	((((quint32)(c)) << 16) |		\
	 (((quint32)(b)) <<  8) |		\
	  ((quint32)(a)))

#define Q_32BIT_FROM_8BIT_0CB0(c, b)		\
	((((quint32)(c)) << 16) |		\
	 (((quint32)(b)) <<  8))

#define Q_32BIT_FROM_8BIT_00BA(b, a)		\
	((((quint32)(b)) <<  8) |		\
	  ((quint32)(a)))

#define Q_32BIT_FROM_DCBA(d, c, b, a)		\
	(((((quint32)(d)) & 0xFF) << 24) |	\
	 ((((quint32)(c)) & 0xFF) << 16) |	\
	 ((((quint32)(b)) & 0xFF) <<  8) |	\
	  (((quint32)(a)) & 0xFF))

#define Q_64BIT_FROM_32BIT_BA(b, a)		\
	((((quint64)(b)) << 32) |		\
	  ((quint64)(a)))

/* MARK: - Translation */

#define Q_8BIT_ENSURE_BIG_ENDIAN(   value)
#define Q_8BIT_ENSURE_LITTLE_ENDIAN(value)
#define Q_8BIT_BIG_ENDIAN(	    value) (value)
#define Q_8BIT_LITTLE_ENDIAN(	    value) (value)

#if Q_INT16_ENDIANNESS == Q_ENDIANNESS_BIG

#	define Q_16BIT_ENSURE_BIG_ENDIAN(value)
#	define Q_16BIT_ENSURE_LITTLE_ENDIAN		Q_16BIT_REVERSE_IN_8BIT
#	define Q_16BIT_BIG_ENDIAN(value)		(value)
#	define Q_16BIT_LITTLE_ENDIAN			Q_16BIT_REVERSED_IN_8BIT

#elif Q_INT16_ENDIANNESS == Q_ENDIANNESS_LITTLE

#	define Q_16BIT_ENSURE_BIG_ENDIAN		Q_16BIT_REVERSE_IN_8BIT
#	define Q_16BIT_ENSURE_LITTLE_ENDIAN(value)
#	define Q_16BIT_BIG_ENDIAN			Q_16BIT_REVERSED_IN_8BIT
#	define Q_16BIT_LITTLE_ENDIAN(value)		(value)

#endif

#if Q_INT32_ENDIANNESS == Q_ENDIANNESS_BIG

#	define Q_32BIT_ENSURE_BIG_ENDIAN(value)
#	define Q_32BIT_ENSURE_LITTLE_ENDIAN		Q_32BIT_REVERSE_IN_8BIT
#	define Q_32BIT_BIG_ENDIAN(value)		(value)
#	define Q_32BIT_LITTLE_ENDIAN			Q_32BIT_REVERSED_IN_8BIT

#elif Q_INT32_ENDIANNESS == Q_ENDIANNESS_LITTLE

#	define Q_32BIT_ENSURE_BIG_ENDIAN		Q_32BIT_REVERSE_IN_8BIT
#	define Q_32BIT_ENSURE_LITTLE_ENDIAN(value)
#	define Q_32BIT_BIG_ENDIAN			Q_32BIT_REVERSED_IN_8BIT
#	define Q_32BIT_LITTLE_ENDIAN(value)		(value)

#endif

#if Q_INT64_ENDIANNESS == Q_ENDIANNESS_BIG

#	define Q_64BIT_ENSURE_BIG_ENDIAN(value)
#	define Q_64BIT_ENSURE_LITTLE_ENDIAN		Q_64BIT_REVERSE_IN_8BIT
#	define Q_64BIT_BIG_ENDIAN(value)		(value)
#	define Q_64BIT_LITTLE_ENDIAN			Q_64BIT_REVERSED_IN_8BIT

#elif Q_INT64_ENDIANNESS == Q_ENDIANNESS_LITTLE

#	define Q_64BIT_ENSURE_BIG_ENDIAN		Q_64BIT_REVERSE_IN_8BIT
#	define Q_64BIT_ENSURE_LITTLE_ENDIAN(value)
#	define Q_64BIT_BIG_ENDIAN			Q_64BIT_REVERSED_IN_8BIT
#	define Q_64BIT_LITTLE_ENDIAN(value)		(value)

#endif

#define Q_ENSURE_BIG_ENDIAN(   TYPE) Q_JOIN_3(Q_, Q_##TYPE##_BITS, BIT_ENSURE_BIG_ENDIAN   )
#define Q_ENSURE_LITTLE_ENDIAN(TYPE) Q_JOIN_3(Q_, Q_##TYPE##_BITS, BIT_ENSURE_LITTLE_ENDIAN)
#define Q_UCHAR_BIG_ENDIAN(    TYPE) Q_JOIN_3(Q_, Q_##TYPE##_BITS, BIT_BIG_ENDIAN	   )
#define Q_UCHAR_LITTLE_ENDIAN( TYPE) Q_JOIN_3(Q_, Q_##TYPE##_BITS, BIT_LITTLE_ENDIAN	   )

#endif /* __Q_macros_value_H__ */
