/* Z Kit - macros/value.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_macros_value_H__
#define __Z_macros_value_H__

#include <Z/types/base.h>

/* MARK: - Basics */

#define Z_MAXIMUM(a, b) ((a) > (b) ? (a) : (b))
#define Z_MINIMUM(a, b) ((a) < (b) ? (a) : (b))

#define Z_ABSOLUTE(	value) ((a) < 0 ? -(a) : (a))
#define Z_IS_POWER_OF_2(value) !((value) & ((value) - 1))

#define Z_NEXT_MULTIPLE(    value, base) ((value) + (base) - ((value) % (base)))
#define Z_PREVIOUS_MULTIPLE(value, base) ((((value) - 1) / (base)) * (base))

/* MARK: - Masked bounded addition/subtraction */

#define Z_MBA(value, delta, mask)			  \
	(((value) & (mask)) + ((delta) & (mask)) > (mask) \
		? (mask) : ((value) & (mask)) + ((delta) & (mask)))

#define Z_MBS(value, delta, mask)			  \
	(((value) & (mask)) - ((delta) & (mask)) > (mask) \
		? 0 : ((value) & (mask)) - ((delta) & (mask)))

/* MARK: - 8-bit operations */

#define Z_8BIT_REVERSE_IN_1BIT(value)				     \
	( ((value) << 7)	     |  ((value) >> 7)		   | \
	 (((value) << 5) & (1 << 6)) | (((value) >> 5) & (1 << 1)) | \
	 (((value) << 3) & (1 << 5)) | (((value) >> 3) & (1 << 2)) | \
	 (((value) << 1) & (1 << 4)) | (((value) >> 1) & (1 << 3)) )

#define Z_8BIT_REVERSE_IN_2BIT(value)				     \
	( ((value) << 6)	     |  ((value) >> 6)		   | \
	 (((value) << 2) & (3 << 4)) | (((value) >> 2) & (3 << 2)) )

#define Z_8BIT_REVERSE_IN_4BIT(value) (((value) << 4) | ((value) >> 4))

#define Z_8BIT_ROTATE_LEFT( value, rotation) (((value) << (rotation)) | ((value) >> (8 - (rotation))))
#define Z_8BIT_ROTATE_RIGHT(value, rotation) (((value) >> (rotation)) | ((value) << (8 - (rotation))))

#define Z_8BIT_ENSURE_BIG_ENDIAN(   value)
#define Z_8BIT_ENSURE_LITTLE_ENDIAN(value)
#define Z_8BIT_BIG_ENDIAN(	    value) (value)
#define Z_8BIT_LITTLE_ENDIAN(	    value) (value)

/* MARK: - 16-bit operations */

#define Z_8BIT_16BIT_MIRROR(value) (((zbint16)(value)) * 0x0101)

#define Z_16BIT_REVERSE_IN_1BIT(value)					\
	( ((value) << 15)	       |  ((value) >> 15)	      | \
	 (((value) << 13) & (1 << 14)) | (((value) >> 13) & (1 << 1)) | \
	 (((value) << 11) & (1 << 13)) | (((value) >> 11) & (1 << 2)) | \
	 (((value) <<  9) & (1 << 12)) | (((value) >>  9) & (1 << 3)) | \
	 (((value) <<  7) & (1 << 11)) | (((value) >>  7) & (1 << 4)) | \
	 (((value) <<  5) & (1 << 10)) | (((value) >>  5) & (1 << 5)) | \
	 (((value) <<  3) & (1 <<  9)) | (((value) >>  3) & (1 << 6)) | \
	 (((value) <<  1) & (1 <<  8)) | (((value) >>  1) & (1 << 7)) )

#define Z_16BIT_REVERSE_IN_2BIT(value)					\
	( ((value) << 14)	       |  ((value) >> 14)	      | \
	 (((value) << 10) & (3 << 12)) | (((value) >> 10) & (3 << 2)) | \
	 (((value) <<  6) & (3 << 10)) | (((value) >>  6) & (3 << 4)) | \
	 (((value) <<  2) & (3 <<  8)) | (((value) >>  2) & (3 << 6)) )

#define Z_16BIT_REVERSE_IN_4BIT(value)					\
	( ((value) << 12)	       |  ((value) >> 12)	      | \
	 (((value) <<  4) & (15 << 8)) | (((value) >> 4) & (15 << 4)) )

#define Z_16BIT_REVERSE_IN_8BIT(value) (((value) << 8) | ((value) >> 8))

#define Z_16BIT_ROTATE_LEFT( value, rotation) (((value) << (rotation)) | ((value) >> (16 - (rotation))))
#define Z_16BIT_ROTATE_RIGHT(value, rotation) (((value) >> (rotation)) | ((value) << (16 - (rotation))))

#if Z_BINT16_ENDIANNESS == Z_ENDIANNESS_BIG

#	define Z_16BIT_ENSURE_BIG_ENDIAN(   value)
#	define Z_16BIT_ENSURE_LITTLE_ENDIAN(value) ((value) = Z_16BIT_REVERSE_IN_8BIT(value))
#	define Z_16BIT_BIG_ENDIAN		   Z_SAME
#	define Z_16BIT_LITTLE_ENDIAN		   Z_16BIT_REVERSE_IN_8BIT

#elif Z_BINT16_ENDIANNESS == Z_ENDIANNESS_LITTLE

#	define Z_16BIT_ENSURE_BIG_ENDIAN(   value) ((value) = Z_16BIT_REVERSE_IN_8BIT(value))
#	define Z_16BIT_ENSURE_LITTLE_ENDIAN(value)
#	define Z_16BIT_BIG_ENDIAN		   Z_16BIT_REVERSE_IN_8BIT
#	define Z_16BIT_LITTLE_ENDIAN		   Z_SAME

#endif

/* MARK: - 32-bit operations */

#define Z_8BIT_32BIT_MIRROR( value) (((zbint32)(value)) * Z_BINT32(0x01010101))
#define Z_16BIT_32BIT_MIRROR(value) (((zbint32)(value)) * Z_BINT32(0x00010001))

#define Z_32BIT_REVERSE_IN_1BIT(value)							   \
	( ((value) << 31)			|  ((value) >> 31)			 | \
	 (((value) << 29) & ((zbint32)1 << 30)) | (((value) >> 29) & ((zbint32)1 <<  1)) | \
	 (((value) << 27) & ((zbint32)1 << 29)) | (((value) >> 27) & ((zbint32)1 <<  2)) | \
	 (((value) << 25) & ((zbint32)1 << 28)) | (((value) >> 25) & ((zbint32)1 <<  3)) | \
	 (((value) << 23) & ((zbint32)1 << 27)) | (((value) >> 23) & ((zbint32)1 <<  4)) | \
	 (((value) << 21) & ((zbint32)1 << 26)) | (((value) >> 21) & ((zbint32)1 <<  5)) | \
	 (((value) << 19) & ((zbint32)1 << 25)) | (((value) >> 19) & ((zbint32)1 <<  6)) | \
	 (((value) << 17) & ((zbint32)1 << 24)) | (((value) >> 17) & ((zbint32)1 <<  7)) | \
	 (((value) << 15) & ((zbint32)1 << 23)) | (((value) >> 15) & ((zbint32)1 <<  8)) | \
	 (((value) << 13) & ((zbint32)1 << 22)) | (((value) >> 13) & ((zbint32)1 <<  9)) | \
	 (((value) << 11) & ((zbint32)1 << 21)) | (((value) >> 11) & ((zbint32)1 << 10)) | \
	 (((value) <<  9) & ((zbint32)1 << 20)) | (((value) >>  9) & ((zbint32)1 << 11)) | \
	 (((value) <<  7) & ((zbint32)1 << 19)) | (((value) >>  7) & ((zbint32)1 << 12)) | \
	 (((value) <<  5) & ((zbint32)1 << 18)) | (((value) >>  5) & ((zbint32)1 << 13)) | \
	 (((value) <<  3) & ((zbint32)1 << 17)) | (((value) >>  3) & ((zbint32)1 << 14)) | \
	 (((value) <<  1) & ((zbint32)1 << 16)) | (((value) >>  1) & ((zbint32)1 << 15)) )

#define Z_32BIT_REVERSE_IN_2BIT(value)							   \
	( ((value) << 30)			|  ((value) >> 30)			 | \
	 (((value) << 26) & ((zbint32)3 << 28)) | (((value) >> 26) & ((zbint32)3 <<  2)) | \
	 (((value) << 22) & ((zbint32)3 << 26)) | (((value) >> 22) & ((zbint32)3 <<  4)) | \
	 (((value) << 18) & ((zbint32)3 << 24)) | (((value) >> 18) & ((zbint32)3 <<  6)) | \
	 (((value) << 14) & ((zbint32)3 << 22)) | (((value) >> 14) & ((zbint32)3 <<  8)) | \
	 (((value) << 10) & ((zbint32)3 << 20)) | (((value) >> 10) & ((zbint32)3 << 10)) | \
	 (((value) <<  6) & ((zbint32)3 << 18)) | (((value) >>	6) & ((zbint32)3 << 12)) | \
	 (((value) <<  2) & ((zbint32)3 << 16)) | (((value) >>	2) & ((zbint32)3 << 14)) )

#define Z_32BIT_REVERSE_IN_4BIT(value)							     \
	( ((value) << 28)			 |  ((value) >> 28)			   | \
	 (((value) << 20) & ((zbint32)15 << 24)) | (((value) >> 20) & ((zbint32)15 <<  4)) | \
	 (((value) << 12) & ((zbint32)15 << 20)) | (((value) >> 12) & ((zbint32)15 <<  8)) | \
	 (((value) <<  4) & ((zbint32)15 << 16)) | (((value) >>  4) & ((zbint32)15 << 12)) )

#define Z_32BIT_REVERSE_IN_8BIT(value)							      \
	( ((value) << 24)			  |  ((value) >> 24)			    | \
	 (((value) <<  8) & ((zbint32)255 << 16)) | (((value) >>  8) & ((zbint32)255 << 8)) )

#define Z_32BIT_REVERSE_IN_16BIT(value) (((value) << 16) | ((value) >> 16))

#define Z_32BIT_ROTATE_LEFT( value, rotation) (((value) << (rotation)) | ((value) >> (32 - (rotation))))
#define Z_32BIT_ROTATE_RIGHT(value, rotation) (((value) >> (rotation)) | ((value) << (32 - (rotation))))

#define Z_32BIT_FROM_8BIT_DCBA(d, c, b, a)		   \
	((((zbint32)(d)) << 24) | (((zbint32)(c)) << 16) | \
	 (((zbint32)(b)) <<  8) |  ((zbint32)(a)))

#define Z_32BIT_FROM_8BIT_0CBA(c, b, a)	\
	((((zbint32)(c)) << 16) | (((zbint32)(b)) << 8) | ((zbint32)(a)))

#define Z_32BIT_FROM_8BIT_0CB0(c, b) \
	((((zbint32)(c)) << 16) | (((zbint32)(b)) << 8))

#define Z_32BIT_FROM_8BIT_00BA(b, a) \
	((((zbint32)(b)) << 8) | ((zbint32)(a)))

#define Z_32BIT_FROM_DCBA(d, c, b, a)					     \
	(((((zbint32)(d)) & 0xFF) << 24) | ((((zbint32)(c)) & 0xFF) << 16) | \
	 ((((zbint32)(b)) & 0xFF) <<  8) |  (((zbint32)(a)) & 0xFF))

#if Z_BINT32_ENDIANNESS == Z_ENDIANNESS_BIG

#	define Z_32BIT_ENSURE_BIG_ENDIAN(   value)
#	define Z_32BIT_ENSURE_LITTLE_ENDIAN(value) ((value) = Z_32BIT_REVERSE_IN_8BIT(value))
#	define Z_32BIT_BIG_ENDIAN		   Z_SAME
#	define Z_32BIT_LITTLE_ENDIAN		   Z_32BIT_REVERSE_IN_8BIT

#elif Z_BINT32_ENDIANNESS == Z_ENDIANNESS_LITTLE

#	define Z_32BIT_ENSURE_BIG_ENDIAN(   value) ((value) = Z_32BIT_REVERSE_IN_8BIT(value))
#	define Z_32BIT_ENSURE_LITTLE_ENDIAN(value)
#	define Z_32BIT_BIG_ENDIAN		   Z_32BIT_REVERSE_IN_8BIT
#	define Z_32BIT_LITTLE_ENDIAN		   Z_SAME

#endif

/* MARK: - 64-bit operations */

#ifdef Z_BINT64

#	define Z_8BIT_64BIT_MIRROR( value) (((zbint64)(value)) * Z_BINT64(0x0101010101010101))
#	define Z_16BIT_64BIT_MIRROR(value) (((zbint64)(value)) * Z_BINT64(0x0001000100010001))
#	define Z_32BIT_64BIT_MIRROR(value) (((zbint64)(value)) * Z_BINT64(0x0000000100000001))

#	define Z_64BIT_REVERSE_IN_1BIT(value)							   \
		( ((value) << 63)			|  ((value) >> 63)			 | \
		 (((value) << 61) & ((zbint64)1 << 62)) | (((value) >> 61) & ((zbint64)1 <<  1)) | \
		 (((value) << 59) & ((zbint64)1 << 61)) | (((value) >> 59) & ((zbint64)1 <<  2)) | \
		 (((value) << 57) & ((zbint64)1 << 60)) | (((value) >> 57) & ((zbint64)1 <<  3)) | \
		 (((value) << 55) & ((zbint64)1 << 59)) | (((value) >> 55) & ((zbint64)1 <<  4)) | \
		 (((value) << 53) & ((zbint64)1 << 58)) | (((value) >> 53) & ((zbint64)1 <<  5)) | \
		 (((value) << 51) & ((zbint64)1 << 57)) | (((value) >> 51) & ((zbint64)1 <<  6)) | \
		 (((value) << 49) & ((zbint64)1 << 56)) | (((value) >> 49) & ((zbint64)1 <<  7)) | \
		 (((value) << 47) & ((zbint64)1 << 55)) | (((value) >> 47) & ((zbint64)1 <<  8)) | \
		 (((value) << 45) & ((zbint64)1 << 54)) | (((value) >> 45) & ((zbint64)1 <<  9)) | \
		 (((value) << 43) & ((zbint64)1 << 53)) | (((value) >> 43) & ((zbint64)1 << 10)) | \
		 (((value) << 41) & ((zbint64)1 << 52)) | (((value) >> 41) & ((zbint64)1 << 11)) | \
		 (((value) << 39) & ((zbint64)1 << 51)) | (((value) >> 39) & ((zbint64)1 << 12)) | \
		 (((value) << 37) & ((zbint64)1 << 50)) | (((value) >> 37) & ((zbint64)1 << 13)) | \
		 (((value) << 35) & ((zbint64)1 << 49)) | (((value) >> 35) & ((zbint64)1 << 14)) | \
		 (((value) << 33) & ((zbint64)1 << 48)) | (((value) >> 33) & ((zbint64)1 << 15)) | \
		 (((value) << 31) & ((zbint64)1 << 47)) | (((value) >> 31) & ((zbint64)1 << 16)) | \
		 (((value) << 29) & ((zbint64)1 << 46)) | (((value) >> 29) & ((zbint64)1 << 17)) | \
		 (((value) << 27) & ((zbint64)1 << 45)) | (((value) >> 27) & ((zbint64)1 << 18)) | \
		 (((value) << 25) & ((zbint64)1 << 44)) | (((value) >> 25) & ((zbint64)1 << 19)) | \
		 (((value) << 23) & ((zbint64)1 << 43)) | (((value) >> 23) & ((zbint64)1 << 20)) | \
		 (((value) << 21) & ((zbint64)1 << 42)) | (((value) >> 21) & ((zbint64)1 << 21)) | \
		 (((value) << 19) & ((zbint64)1 << 41)) | (((value) >> 19) & ((zbint64)1 << 22)) | \
		 (((value) << 17) & ((zbint64)1 << 40)) | (((value) >> 17) & ((zbint64)1 << 23)) | \
		 (((value) << 15) & ((zbint64)1 << 39)) | (((value) >> 15) & ((zbint64)1 << 24)) | \
		 (((value) << 13) & ((zbint64)1 << 38)) | (((value) >> 13) & ((zbint64)1 << 25)) | \
		 (((value) << 11) & ((zbint64)1 << 37)) | (((value) >> 11) & ((zbint64)1 << 26)) | \
		 (((value) <<  9) & ((zbint64)1 << 36)) | (((value) >>	9) & ((zbint64)1 << 27)) | \
		 (((value) <<  7) & ((zbint64)1 << 35)) | (((value) >>	7) & ((zbint64)1 << 28)) | \
		 (((value) <<  5) & ((zbint64)1 << 34)) | (((value) >>	5) & ((zbint64)1 << 29)) | \
		 (((value) <<  3) & ((zbint64)1 << 33)) | (((value) >>	3) & ((zbint64)1 << 30)) | \
		 (((value) <<  1) & ((zbint64)1 << 32)) | (((value) >>	1) & ((zbint64)1 << 31)) )

#	define Z_64BIT_REVERSE_IN_2BIT(value)							   \
		( ((value) << 62)			|  ((value) >> 62)			 | \
		 (((value) << 58) & ((zbint64)3 << 60)) | (((value) >> 58) & ((zbint64)3 <<  2)) | \
		 (((value) << 54) & ((zbint64)3 << 58)) | (((value) >> 54) & ((zbint64)3 <<  4)) | \
		 (((value) << 50) & ((zbint64)3 << 56)) | (((value) >> 50) & ((zbint64)3 <<  6)) | \
		 (((value) << 46) & ((zbint64)3 << 54)) | (((value) >> 46) & ((zbint64)3 <<  8)) | \
		 (((value) << 42) & ((zbint64)3 << 52)) | (((value) >> 42) & ((zbint64)3 << 10)) | \
		 (((value) << 38) & ((zbint64)3 << 50)) | (((value) >> 38) & ((zbint64)3 << 12)) | \
		 (((value) << 34) & ((zbint64)3 << 48)) | (((value) >> 34) & ((zbint64)3 << 14)) | \
		 (((value) << 30) & ((zbint64)3 << 46)) | (((value) >> 30) & ((zbint64)3 << 16)) | \
		 (((value) << 26) & ((zbint64)3 << 44)) | (((value) >> 26) & ((zbint64)3 << 18)) | \
		 (((value) << 22) & ((zbint64)3 << 42)) | (((value) >> 22) & ((zbint64)3 << 20)) | \
		 (((value) << 18) & ((zbint64)3 << 40)) | (((value) >> 18) & ((zbint64)3 << 22)) | \
		 (((value) << 14) & ((zbint64)3 << 38)) | (((value) >> 14) & ((zbint64)3 << 24)) | \
		 (((value) << 10) & ((zbint64)3 << 36)) | (((value) >> 10) & ((zbint64)3 << 26)) | \
		 (((value) <<  6) & ((zbint64)3 << 34)) | (((value) >>	6) & ((zbint64)3 << 28)) | \
		 (((value) <<  2) & ((zbint64)3 << 32)) | (((value) >>	2) & ((zbint64)3 << 30)) )

#	define Z_64BIT_REVERSE_IN_4BIT(value)							     \
		( ((value) << 60)			 |  ((value) >> 60)			   | \
		 (((value) << 52) & ((zbint64)15 << 56)) | (((value) >> 52) & ((zbint64)15 <<  4)) | \
		 (((value) << 44) & ((zbint64)15 << 52)) | (((value) >> 44) & ((zbint64)15 <<  8)) | \
		 (((value) << 36) & ((zbint64)15 << 48)) | (((value) >> 36) & ((zbint64)15 << 12)) | \
		 (((value) << 28) & ((zbint64)15 << 44)) | (((value) >> 28) & ((zbint64)15 << 16)) | \
		 (((value) << 20) & ((zbint64)15 << 40)) | (((value) >> 20) & ((zbint64)15 << 20)) | \
		 (((value) << 12) & ((zbint64)15 << 36)) | (((value) >> 12) & ((zbint64)15 << 24)) | \
		 (((value) <<  4) & ((zbint64)15 << 32)) | (((value) >>  4) & ((zbint64)15 << 28)) )

#	define Z_64BIT_REVERSE_IN_8BIT(value)							       \
		( ((value) << 56)			  |  ((value) >> 56)			     | \
		 (((value) << 40) & ((zbint64)255 << 48)) | (((value) >> 40) & ((zbint64)255 <<  8)) | \
		 (((value) << 24) & ((zbint64)255 << 40)) | (((value) >> 24) & ((zbint64)255 << 16)) | \
		 (((value) <<  8) & ((zbint64)255 << 32)) | (((value) >>  8) & ((zbint64)255 << 24)) )

#	define Z_64BIT_REVERSE_IN_16BIT(value)								   \
		( ((value) << 48)			    |  ((value) >> 48)				 | \
		 (((value) << 16) & ((zbint64)65535 << 32)) | (((value) >> 16) & ((zbint64)65535 << 16)) )

#	define Z_64BIT_REVERSE_IN_32BIT(value) (((value) << 32) | ((value) >> 32))

#	define Z_64BIT_ROTATE_LEFT( value, rotation) (((value) << (rotation)) | ((value) >> (64 - (rotation))))
#	define Z_64BIT_ROTATE_RIGHT(value, rotation) (((value) >> (rotation)) | ((value) << (64 - (rotation))))

#	define Z_64BIT_FROM_32BIT_BA(b, a) ((((zbint64)(b)) << 32) | ((zbint64)(a)))

#	if Z_BINT64_ENDIANNESS == Z_ENDIANNESS_BIG

#		define Z_64BIT_ENSURE_BIG_ENDIAN(   value)
#		define Z_64BIT_ENSURE_LITTLE_ENDIAN(value) ((value) = Z_64BIT_REVERSE_IN_8BIT(value))
#		define Z_64BIT_BIG_ENDIAN		   Z_SAME
#		define Z_64BIT_LITTLE_ENDIAN		   Z_64BIT_REVERSE_IN_8BIT

#	elif Z_BINT64_ENDIANNESS == Z_ENDIANNESS_LITTLE

#		define Z_64BIT_ENSURE_BIG_ENDIAN(   value) ((value) = Z_64BIT_REVERSE_IN_8BIT(value))
#		define Z_64BIT_ENSURE_LITTLE_ENDIAN(value)
#		define Z_64BIT_BIG_ENDIAN		   Z_64BIT_REVERSE_IN_8BIT
#		define Z_64BIT_LITTLE_ENDIAN		   Z_SAME

#	endif

#endif

/* MARK: - 128-bit operations */

#ifdef Z_BINT128

#	if Z_DATA_MODEL_HAS_LITERAL(UINT128) || Z_DATA_MODEL_HAS_LITERAL(SINT128)
#		define Z_8BIT_128BIT_MIRROR( value) (((zbint128)(value)) * Z_BINT128(0x01010101010101010101010101010101))
#		define Z_16BIT_128BIT_MIRROR(value) (((zbint128)(value)) * Z_BINT128(0x00010001000100010001000100010001))
#		define Z_32BIT_128BIT_MIRROR(value) (((zbint128)(value)) * Z_BINT128(0x00000001000000010000000100000001))
#		define Z_64BIT_128BIT_MIRROR(value) (((zbint128)(value)) * Z_BINT128(0x00000000000000010000000000000001))
#	else
#		define Z_8BIT_128BIT_MIRROR( value) (((zbint128)(value)) * ((zbint128)0x0101010101010101 | ((zbint128)0101010101010101 << 64)))
#		define Z_16BIT_128BIT_MIRROR(value) (((zbint128)(value)) * ((zbint128)0x0001000100010001 | ((zbint128)0001000100010001 << 64)))
#		define Z_32BIT_128BIT_MIRROR(value) (((zbint128)(value)) * ((zbint128)0x0000000100000001 | ((zbint128)0000000100000001 << 64)))
#		define Z_64BIT_128BIT_MIRROR(value) (((zbint128)(value)) * ((zbint128)0x0000000000000001 | ((zbint128)0000000000000001 << 64)))
#	endif

#	define Z_128BIT_REVERSE_IN_1BIT(value)								\
		( ((value) << 127)			   |  ((value) >> 127)			      | \
		 (((value) << 125) & ((zbint128)1 << 126)) | (((value) >> 125) & ((zbint128)1 <<  1)) | \
		 (((value) << 123) & ((zbint128)1 << 125)) | (((value) >> 123) & ((zbint128)1 <<  2)) | \
		 (((value) << 121) & ((zbint128)1 << 124)) | (((value) >> 121) & ((zbint128)1 <<  3)) | \
		 (((value) << 119) & ((zbint128)1 << 123)) | (((value) >> 119) & ((zbint128)1 <<  4)) | \
		 (((value) << 117) & ((zbint128)1 << 122)) | (((value) >> 117) & ((zbint128)1 <<  5)) | \
		 (((value) << 115) & ((zbint128)1 << 121)) | (((value) >> 115) & ((zbint128)1 <<  6)) | \
		 (((value) << 113) & ((zbint128)1 << 120)) | (((value) >> 113) & ((zbint128)1 <<  7)) | \
		 (((value) << 111) & ((zbint128)1 << 119)) | (((value) >> 111) & ((zbint128)1 <<  8)) | \
		 (((value) << 109) & ((zbint128)1 << 118)) | (((value) >> 109) & ((zbint128)1 <<  9)) | \
		 (((value) << 107) & ((zbint128)1 << 117)) | (((value) >> 107) & ((zbint128)1 << 10)) | \
		 (((value) << 105) & ((zbint128)1 << 116)) | (((value) >> 105) & ((zbint128)1 << 11)) | \
		 (((value) << 103) & ((zbint128)1 << 115)) | (((value) >> 103) & ((zbint128)1 << 12)) | \
		 (((value) << 101) & ((zbint128)1 << 114)) | (((value) >> 101) & ((zbint128)1 << 13)) | \
		 (((value) <<  99) & ((zbint128)1 << 113)) | (((value) >>  99) & ((zbint128)1 << 14)) | \
		 (((value) <<  97) & ((zbint128)1 << 112)) | (((value) >>  97) & ((zbint128)1 << 15)) | \
		 (((value) <<  95) & ((zbint128)1 << 111)) | (((value) >>  95) & ((zbint128)1 << 16)) | \
		 (((value) <<  93) & ((zbint128)1 << 110)) | (((value) >>  93) & ((zbint128)1 << 17)) | \
		 (((value) <<  91) & ((zbint128)1 << 109)) | (((value) >>  91) & ((zbint128)1 << 18)) | \
		 (((value) <<  89) & ((zbint128)1 << 108)) | (((value) >>  89) & ((zbint128)1 << 19)) | \
		 (((value) <<  87) & ((zbint128)1 << 107)) | (((value) >>  87) & ((zbint128)1 << 20)) | \
		 (((value) <<  85) & ((zbint128)1 << 106)) | (((value) >>  85) & ((zbint128)1 << 21)) | \
		 (((value) <<  83) & ((zbint128)1 << 105)) | (((value) >>  83) & ((zbint128)1 << 22)) | \
		 (((value) <<  81) & ((zbint128)1 << 104)) | (((value) >>  81) & ((zbint128)1 << 23)) | \
		 (((value) <<  79) & ((zbint128)1 << 103)) | (((value) >>  79) & ((zbint128)1 << 24)) | \
		 (((value) <<  77) & ((zbint128)1 << 102)) | (((value) >>  77) & ((zbint128)1 << 25)) | \
		 (((value) <<  75) & ((zbint128)1 << 101)) | (((value) >>  75) & ((zbint128)1 << 26)) | \
		 (((value) <<  73) & ((zbint128)1 << 100)) | (((value) >>  73) & ((zbint128)1 << 27)) | \
		 (((value) <<  71) & ((zbint128)1 <<  99)) | (((value) >>  71) & ((zbint128)1 << 28)) | \
		 (((value) <<  69) & ((zbint128)1 <<  98)) | (((value) >>  69) & ((zbint128)1 << 29)) | \
		 (((value) <<  67) & ((zbint128)1 <<  97)) | (((value) >>  67) & ((zbint128)1 << 30)) | \
		 (((value) <<  65) & ((zbint128)1 <<  96)) | (((value) >>  65) & ((zbint128)1 << 31)) | \
		 (((value) <<  63) & ((zbint128)1 <<  95)) | (((value) >>  63) & ((zbint128)1 << 32)) | \
		 (((value) <<  61) & ((zbint128)1 <<  94)) | (((value) >>  61) & ((zbint128)1 << 33)) | \
		 (((value) <<  59) & ((zbint128)1 <<  93)) | (((value) >>  59) & ((zbint128)1 << 34)) | \
		 (((value) <<  57) & ((zbint128)1 <<  92)) | (((value) >>  57) & ((zbint128)1 << 35)) | \
		 (((value) <<  55) & ((zbint128)1 <<  91)) | (((value) >>  55) & ((zbint128)1 << 36)) | \
		 (((value) <<  53) & ((zbint128)1 <<  90)) | (((value) >>  53) & ((zbint128)1 << 37)) | \
		 (((value) <<  51) & ((zbint128)1 <<  89)) | (((value) >>  51) & ((zbint128)1 << 38)) | \
		 (((value) <<  49) & ((zbint128)1 <<  88)) | (((value) >>  49) & ((zbint128)1 << 39)) | \
		 (((value) <<  47) & ((zbint128)1 <<  87)) | (((value) >>  47) & ((zbint128)1 << 40)) | \
		 (((value) <<  45) & ((zbint128)1 <<  86)) | (((value) >>  45) & ((zbint128)1 << 41)) | \
		 (((value) <<  43) & ((zbint128)1 <<  85)) | (((value) >>  43) & ((zbint128)1 << 42)) | \
		 (((value) <<  41) & ((zbint128)1 <<  84)) | (((value) >>  41) & ((zbint128)1 << 43)) | \
		 (((value) <<  39) & ((zbint128)1 <<  83)) | (((value) >>  39) & ((zbint128)1 << 44)) | \
		 (((value) <<  37) & ((zbint128)1 <<  82)) | (((value) >>  37) & ((zbint128)1 << 45)) | \
		 (((value) <<  35) & ((zbint128)1 <<  81)) | (((value) >>  35) & ((zbint128)1 << 46)) | \
		 (((value) <<  33) & ((zbint128)1 <<  80)) | (((value) >>  33) & ((zbint128)1 << 47)) | \
		 (((value) <<  31) & ((zbint128)1 <<  79)) | (((value) >>  31) & ((zbint128)1 << 48)) | \
		 (((value) <<  29) & ((zbint128)1 <<  78)) | (((value) >>  29) & ((zbint128)1 << 49)) | \
		 (((value) <<  27) & ((zbint128)1 <<  77)) | (((value) >>  27) & ((zbint128)1 << 50)) | \
		 (((value) <<  25) & ((zbint128)1 <<  76)) | (((value) >>  25) & ((zbint128)1 << 51)) | \
		 (((value) <<  23) & ((zbint128)1 <<  75)) | (((value) >>  23) & ((zbint128)1 << 52)) | \
		 (((value) <<  21) & ((zbint128)1 <<  74)) | (((value) >>  21) & ((zbint128)1 << 53)) | \
		 (((value) <<  19) & ((zbint128)1 <<  73)) | (((value) >>  19) & ((zbint128)1 << 54)) | \
		 (((value) <<  17) & ((zbint128)1 <<  72)) | (((value) >>  17) & ((zbint128)1 << 55)) | \
		 (((value) <<  15) & ((zbint128)1 <<  71)) | (((value) >>  15) & ((zbint128)1 << 56)) | \
		 (((value) <<  13) & ((zbint128)1 <<  70)) | (((value) >>  13) & ((zbint128)1 << 57)) | \
		 (((value) <<  11) & ((zbint128)1 <<  69)) | (((value) >>  11) & ((zbint128)1 << 58)) | \
		 (((value) <<	9) & ((zbint128)1 <<  68)) | (((value) >>   9) & ((zbint128)1 << 59)) | \
		 (((value) <<	7) & ((zbint128)1 <<  67)) | (((value) >>   7) & ((zbint128)1 << 60)) | \
		 (((value) <<	5) & ((zbint128)1 <<  66)) | (((value) >>   5) & ((zbint128)1 << 61)) | \
		 (((value) <<	3) & ((zbint128)1 <<  65)) | (((value) >>   3) & ((zbint128)1 << 62)) | \
		 (((value) <<	1) & ((zbint128)1 <<  64)) | (((value) >>   1) & ((zbint128)1 << 63)) )

#	define Z_128BIT_REVERSE_IN_2BIT(value)								\
		( ((value) << 126)			   |  ((value) >> 126)			      | \
		 (((value) << 122) & ((zbint128)3 << 124)) | (((value) >> 122) & ((zbint128)3 <<  2)) | \
		 (((value) << 118) & ((zbint128)3 << 122)) | (((value) >> 118) & ((zbint128)3 <<  4)) | \
		 (((value) << 114) & ((zbint128)3 << 120)) | (((value) >> 114) & ((zbint128)3 <<  6)) | \
		 (((value) << 110) & ((zbint128)3 << 118)) | (((value) >> 110) & ((zbint128)3 <<  8)) | \
		 (((value) << 106) & ((zbint128)3 << 116)) | (((value) >> 106) & ((zbint128)3 << 10)) | \
		 (((value) << 102) & ((zbint128)3 << 114)) | (((value) >> 102) & ((zbint128)3 << 12)) | \
		 (((value) <<  98) & ((zbint128)3 << 112)) | (((value) >>  98) & ((zbint128)3 << 14)) | \
		 (((value) <<  94) & ((zbint128)3 << 110)) | (((value) >>  94) & ((zbint128)3 << 16)) | \
		 (((value) <<  90) & ((zbint128)3 << 108)) | (((value) >>  90) & ((zbint128)3 << 18)) | \
		 (((value) <<  86) & ((zbint128)3 << 106)) | (((value) >>  86) & ((zbint128)3 << 20)) | \
		 (((value) <<  82) & ((zbint128)3 << 104)) | (((value) >>  82) & ((zbint128)3 << 22)) | \
		 (((value) <<  78) & ((zbint128)3 << 102)) | (((value) >>  78) & ((zbint128)3 << 24)) | \
		 (((value) <<  74) & ((zbint128)3 << 100)) | (((value) >>  74) & ((zbint128)3 << 26)) | \
		 (((value) <<  70) & ((zbint128)3 <<  98)) | (((value) >>  70) & ((zbint128)3 << 28)) | \
		 (((value) <<  66) & ((zbint128)3 <<  96)) | (((value) >>  66) & ((zbint128)3 << 30)) | \
		 (((value) <<  62) & ((zbint128)3 <<  94)) | (((value) >>  62) & ((zbint128)3 << 32)) | \
		 (((value) <<  58) & ((zbint128)3 <<  92)) | (((value) >>  58) & ((zbint128)3 << 34)) | \
		 (((value) <<  54) & ((zbint128)3 <<  90)) | (((value) >>  54) & ((zbint128)3 << 36)) | \
		 (((value) <<  50) & ((zbint128)3 <<  88)) | (((value) >>  50) & ((zbint128)3 << 38)) | \
		 (((value) <<  46) & ((zbint128)3 <<  86)) | (((value) >>  46) & ((zbint128)3 << 40)) | \
		 (((value) <<  42) & ((zbint128)3 <<  84)) | (((value) >>  42) & ((zbint128)3 << 42)) | \
		 (((value) <<  38) & ((zbint128)3 <<  82)) | (((value) >>  38) & ((zbint128)3 << 44)) | \
		 (((value) <<  34) & ((zbint128)3 <<  80)) | (((value) >>  34) & ((zbint128)3 << 46)) | \
		 (((value) <<  30) & ((zbint128)3 <<  78)) | (((value) >>  30) & ((zbint128)3 << 48)) | \
		 (((value) <<  26) & ((zbint128)3 <<  76)) | (((value) >>  26) & ((zbint128)3 << 50)) | \
		 (((value) <<  22) & ((zbint128)3 <<  74)) | (((value) >>  22) & ((zbint128)3 << 52)) | \
		 (((value) <<  18) & ((zbint128)3 <<  72)) | (((value) >>  18) & ((zbint128)3 << 54)) | \
		 (((value) <<  14) & ((zbint128)3 <<  70)) | (((value) >>  14) & ((zbint128)3 << 56)) | \
		 (((value) <<  10) & ((zbint128)3 <<  68)) | (((value) >>  10) & ((zbint128)3 << 58)) | \
		 (((value) <<	6) & ((zbint128)3 <<  66)) | (((value) >>   6) & ((zbint128)3 << 60)) | \
		 (((value) <<	2) & ((zbint128)3 <<  64)) | (((value) >>   2) & ((zbint128)3 << 62)) )

#	define Z_128BIT_REVERSE_IN_4BIT(value)								  \
		( ((value) << 124)			    |  ((value) >> 124)				| \
		 (((value) << 116) & ((zbint128)15 << 120)) | (((value) >> 116) & ((zbint128)15 <<  4)) | \
		 (((value) << 108) & ((zbint128)15 << 116)) | (((value) >> 108) & ((zbint128)15 <<  8)) | \
		 (((value) << 100) & ((zbint128)15 << 112)) | (((value) >> 100) & ((zbint128)15 << 12)) | \
		 (((value) <<  92) & ((zbint128)15 << 108)) | (((value) >>  92) & ((zbint128)15 << 16)) | \
		 (((value) <<  84) & ((zbint128)15 << 104)) | (((value) >>  84) & ((zbint128)15 << 20)) | \
		 (((value) <<  76) & ((zbint128)15 << 100)) | (((value) >>  76) & ((zbint128)15 << 24)) | \
		 (((value) <<  68) & ((zbint128)15 <<  96)) | (((value) >>  68) & ((zbint128)15 << 28)) | \
		 (((value) <<  60) & ((zbint128)15 <<  92)) | (((value) >>  60) & ((zbint128)15 << 32)) | \
		 (((value) <<  52) & ((zbint128)15 <<  88)) | (((value) >>  52) & ((zbint128)15 << 36)) | \
		 (((value) <<  44) & ((zbint128)15 <<  84)) | (((value) >>  44) & ((zbint128)15 << 40)) | \
		 (((value) <<  36) & ((zbint128)15 <<  80)) | (((value) >>  36) & ((zbint128)15 << 44)) | \
		 (((value) <<  28) & ((zbint128)15 <<  76)) | (((value) >>  28) & ((zbint128)15 << 48)) | \
		 (((value) <<  20) & ((zbint128)15 <<  72)) | (((value) >>  20) & ((zbint128)15 << 52)) | \
		 (((value) <<  12) & ((zbint128)15 <<  68)) | (((value) >>  12) & ((zbint128)15 << 56)) | \
		 (((value) <<	4) & ((zbint128)15 <<  64)) | (((value) >>   4) & ((zbint128)15 << 60)) )

#	define Z_128BIT_REVERSE_IN_8BIT(value)								    \
		( ((value) << 120)			     |	((value) >> 120)			  | \
		 (((value) << 104) & ((zbint128)255 << 112)) | (((value) >> 104) & ((zbint128)255 <<  8)) | \
		 (((value) <<  88) & ((zbint128)255 << 104)) | (((value) >>  88) & ((zbint128)255 << 16)) | \
		 (((value) <<  72) & ((zbint128)255 <<	96)) | (((value) >>  72) & ((zbint128)255 << 24)) | \
		 (((value) <<  56) & ((zbint128)255 <<	88)) | (((value) >>  56) & ((zbint128)255 << 32)) | \
		 (((value) <<  40) & ((zbint128)255 <<	80)) | (((value) >>  40) & ((zbint128)255 << 40)) | \
		 (((value) <<  24) & ((zbint128)255 <<	72)) | (((value) >>  24) & ((zbint128)255 << 48)) | \
		 (((value) <<	8) & ((zbint128)255 <<	64)) | (((value) >>   8) & ((zbint128)255 << 56)) )

#	define Z_128BIT_REVERSE_IN_16BIT(value)								       \
		( ((value) << 112)			      |  ((value) >> 112)			     | \
		 (((value) <<  80) & ((zbint128)65535 << 96)) | (((value) >>  80) & ((zbint128)65535 << 16)) | \
		 (((value) <<  48) & ((zbint128)65535 << 80)) | (((value) >>  48) & ((zbint128)65535 << 32)) | \
		 (((value) <<  16) & ((zbint128)65535 << 64)) | (((value) >>  16) & ((zbint128)65535 << 48)) )

#	define Z_128BIT_REVERSE_IN_32BIT(value)									       \
		( ((value) << 96)				  |  ((value) >> 96)				     | \
		 (((value) << 32) & ((zbint128)4294967295 << 64)) | (((value) >> 32) & ((zbint128)4294967295 << 32)) )

#	define Z_128BIT_REVERSE_IN_64BIT(value) (((value) << 64) | ((value) >> 64))

#	define Z_128BIT_ROTATE_LEFT( value, rotation) (((value) << (rotation)) | ((value) >> (128 - (rotation))))
#	define Z_128BIT_ROTATE_RIGHT(value, rotation) (((value) >> (rotation)) | ((value) << (128 - (rotation))))

#	if Z_BINT128_ENDIANNESS == Z_ENDIANNESS_BIG

#		define Z_128BIT_ENSURE_BIG_ENDIAN(   value)
#		define Z_128BIT_ENSURE_LITTLE_ENDIAN(value) ((value) = Z_128BIT_REVERSE_IN_8BIT(value))
#		define Z_128BIT_BIG_ENDIAN		    Z_SAME
#		define Z_128BIT_LITTLE_ENDIAN		    Z_128BIT_REVERSE_IN_8BIT

#	elif Z_BINT128_ENDIANNESS == Z_ENDIANNESS_LITTLE

#		define Z_128BIT_ENSURE_BIG_ENDIAN(   value) ((value) = Z_128BIT_REVERSE_IN_8BIT(value))
#		define Z_128BIT_ENSURE_LITTLE_ENDIAN(value)
#		define Z_128BIT_BIG_ENDIAN		    Z_128BIT_REVERSE_IN_8BIT
#		define Z_128BIT_LITTLE_ENDIAN		    Z_SAME

#	endif

#endif

/* MARK: - Top integer operations */

#if Z_BINTTOP_BITS == 16

#	define Z_8BIT_TOP_MIRROR  Z_8BIT_16BIT_MIRROR

#elif Z_BINTTOP_BITS == 32

#	define Z_8BIT_TOP_MIRROR  Z_8BIT_32BIT_MIRROR
#	define Z_16BIT_TOP_MIRROR Z_16BIT_32BIT_MIRROR

#elif Z_BINTTOP_BITS == 64

#	define Z_8BIT_TOP_MIRROR  Z_8BIT_64BIT_MIRROR
#	define Z_16BIT_TOP_MIRROR Z_16BIT_64BIT_MIRROR
#	define Z_32BIT_TOP_MIRROR Z_32BIT_64BIT_MIRROR

#elif Z_BINTTOP_BITS == 128

#	define Z_8BIT_TOP_MIRROR  Z_8BIT_128BIT_MIRROR
#	define Z_16BIT_TOP_MIRROR Z_16BIT_128BIT_MIRROR
#	define Z_32BIT_TOP_MIRROR Z_32BIT_128BIT_MIRROR
#	define Z_64BIT_TOP_MIRROR Z_64BIT_128BIT_MIRROR

#endif

/* MARK: - Macro selectors */

#define Z_TYPE_REVERSE(		    TYPE) Z_INSERT_##TYPE##_BITS(Z_, BIT_REVERSE_IN_8BIT     )
#define Z_TYPE_ENSURE_BIG_ENDIAN(   TYPE) Z_INSERT_##TYPE##_BITS(Z_, BIT_ENSURE_BIG_ENDIAN   )
#define Z_TYPE_ENSURE_LITTLE_ENDIAN(TYPE) Z_INSERT_##TYPE##_BITS(Z_, BIT_ENSURE_LITTLE_ENDIAN)
#define Z_TYPE_BIG_ENDIAN(	    TYPE) Z_INSERT_##TYPE##_BITS(Z_, BIT_BIG_ENDIAN	     )
#define Z_TYPE_LITTLE_ENDIAN(	    TYPE) Z_INSERT_##TYPE##_BITS(Z_, BIT_LITTLE_ENDIAN	     )

#endif /* __Z_macros_value_H__ */
