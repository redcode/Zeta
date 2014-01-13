/* Q API - macros/value.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2014 Manuel Sainz de Baranda y Goñi.
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

#	else

#		define Q_UINT128_FROM_UINT8_MIRROR( value) (((quint128)(value)) * ((quint128)0x0101010101010101 | ((quint128)0101010101010101 << 64)))
#		define Q_UINT128_FROM_UINT16_MIRROR(value) (((quint128)(value)) * ((quint128)0x0001000100010001 | ((quint128)0001000100010001 << 64)))
#		define Q_UINT128_FROM_UINT32_MIRROR(value) (((quint128)(value)) * ((quint128)0x0000000100000001 | ((quint128)0000000100000001 << 64)))
#		define Q_UINT128_FROM_UINT64_MIRROR(value) (((quint128)(value)) * ((quint128)0x0000000000000001 | ((quint128)0000000000000001 << 64)))

#	endif

#endif

#if Q_UINTTOP_BITS == 32

#	define Q_UINTTOP_FROM_UINT8_MIRROR  Q_UINT32_FROM_UINT8_MIRROR
#	define Q_UINTTOP_FROM_UINT16_MIRROR Q_UINT32_FROM_UINT16_MIRROR

#elif Q_UINTTOP_BITS == 64

#	define Q_UINTTOP_FROM_UINT8_MIRROR  Q_UINT64_FROM_UINT8_MIRROR
#	define Q_UINTTOP_FROM_UINT16_MIRROR Q_UINT64_FROM_UINT16_MIRROR
#	define Q_UINTTOP_FROM_UINT32_MIRROR Q_UINT64_FROM_UINT32_MIRROR

#elif Q_UINTTOP_BITS == 128

#	define Q_UINTTOP_FROM_UINT8_MIRROR  Q_UINT128_FROM_UINT8_MIRROR
#	define Q_UINTTOP_FROM_UINT16_MIRROR Q_UINT128_FROM_UINT16_MIRROR
#	define Q_UINTTOP_FROM_UINT32_MIRROR Q_UINT128_FROM_UINT32_MIRROR
#	define Q_UINTTOP_FROM_UINT64_MIRROR Q_UINT128_FROM_UINT64_MIRROR

#endif

/* MARK: - Reversion */

#define Q_8BIT_REVERSED_IN_1BIT(value)				     \
	( ((value) << 7)	     |  ((value) >> 7)		   | \
	 (((value) << 5) & (1 << 6)) | (((value) >> 5) & (1 << 1)) | \
	 (((value) << 3) & (1 << 5)) | (((value) >> 3) & (1 << 2)) | \
	 (((value) << 1) & (1 << 4)) | (((value) >> 1) & (1 << 3)) )

#define Q_8BIT_REVERSED_IN_2BIT(value)				     \
	( ((value) << 6)	     |  ((value) >> 6)		   | \
	 (((value) << 2) & (3 << 4)) | (((value) >> 2) & (3 << 2)) )

#define Q_8BIT_REVERSED_IN_4BIT(value) (((value) << 4) | ((value) >> 4))

#define Q_16BIT_REVERSED_IN_1BIT(value)					\
	( ((value) << 15)	       |  ((value) >> 15)	      | \
	 (((value) << 13) & (1 << 14)) | (((value) >> 13) & (1 << 1)) | \
	 (((value) << 11) & (1 << 13)) | (((value) >> 11) & (1 << 2)) | \
	 (((value) <<  9) & (1 << 12)) | (((value) >>  9) & (1 << 3)) | \
	 (((value) <<  7) & (1 << 11)) | (((value) >>  7) & (1 << 4)) | \
	 (((value) <<  5) & (1 << 10)) | (((value) >>  5) & (1 << 5)) | \
	 (((value) <<  3) & (1 <<  9)) | (((value) >>  3) & (1 << 6)) | \
	 (((value) <<  1) & (1 <<  8)) | (((value) >>  1) & (1 << 7)) )

#define Q_16BIT_REVERSED_IN_2BIT(value)					\
	( ((value) << 14)	       |  ((value) >> 14)	      | \
	 (((value) << 10) & (3 << 12)) | (((value) >> 10) & (3 << 2)) | \
	 (((value) <<  6) & (3 << 10)) | (((value) >>  6) & (3 << 4)) | \
	 (((value) <<  2) & (3 <<  8)) | (((value) >>  2) & (3 << 6)) )

#define Q_16BIT_REVERSED_IN_4BIT(value)					\
	( ((value) << 12)	       |  ((value) >> 12)	      | \
	 (((value) <<  4) & (15 << 8)) | (((value) >> 4) & (15 << 4)) )

#define Q_16BIT_REVERSED_IN_8BIT(value) (((value) << 8) | ((value) >> 8))

#define Q_32BIT_REVERSED_IN_1BIT(value)							   \
	( ((value) << 31)			|  ((value) >> 31)			 | \
	 (((value) << 29) & ((quint32)1 << 30)) | (((value) >> 29) & ((quint32)1 <<  1)) | \
	 (((value) << 27) & ((quint32)1 << 29)) | (((value) >> 27) & ((quint32)1 <<  2)) | \
	 (((value) << 25) & ((quint32)1 << 28)) | (((value) >> 25) & ((quint32)1 <<  3)) | \
	 (((value) << 23) & ((quint32)1 << 27)) | (((value) >> 23) & ((quint32)1 <<  4)) | \
	 (((value) << 21) & ((quint32)1 << 26)) | (((value) >> 21) & ((quint32)1 <<  5)) | \
	 (((value) << 19) & ((quint32)1 << 25)) | (((value) >> 19) & ((quint32)1 <<  6)) | \
	 (((value) << 17) & ((quint32)1 << 24)) | (((value) >> 17) & ((quint32)1 <<  7)) | \
	 (((value) << 15) & ((quint32)1 << 23)) | (((value) >> 15) & ((quint32)1 <<  8)) | \
	 (((value) << 13) & ((quint32)1 << 22)) | (((value) >> 13) & ((quint32)1 <<  9)) | \
	 (((value) << 11) & ((quint32)1 << 21)) | (((value) >> 11) & ((quint32)1 << 10)) | \
	 (((value) <<  9) & ((quint32)1 << 20)) | (((value) >>  9) & ((quint32)1 << 11)) | \
	 (((value) <<  7) & ((quint32)1 << 19)) | (((value) >>  7) & ((quint32)1 << 12)) | \
	 (((value) <<  5) & ((quint32)1 << 18)) | (((value) >>  5) & ((quint32)1 << 13)) | \
	 (((value) <<  3) & ((quint32)1 << 17)) | (((value) >>  3) & ((quint32)1 << 14)) | \
	 (((value) <<  1) & ((quint32)1 << 16)) | (((value) >>  1) & ((quint32)1 << 15)) )

#define Q_32BIT_REVERSED_IN_2BIT(value)							   \
	( ((value) << 30)			|  ((value) >> 30)			 | \
	 (((value) << 26) & ((quint32)3 << 28)) | (((value) >> 26) & ((quint32)3 <<  2)) | \
	 (((value) << 22) & ((quint32)3 << 26)) | (((value) >> 22) & ((quint32)3 <<  4)) | \
	 (((value) << 18) & ((quint32)3 << 24)) | (((value) >> 18) & ((quint32)3 <<  6)) | \
	 (((value) << 14) & ((quint32)3 << 22)) | (((value) >> 14) & ((quint32)3 <<  8)) | \
	 (((value) << 10) & ((quint32)3 << 20)) | (((value) >> 10) & ((quint32)3 << 10)) | \
	 (((value) <<  6) & ((quint32)3 << 18)) | (((value) >>	6) & ((quint32)3 << 12)) | \
	 (((value) <<  2) & ((quint32)3 << 16)) | (((value) >>	2) & ((quint32)3 << 14)) )

#define Q_32BIT_REVERSED_IN_4BIT(value)							     \
	( ((value) << 28)			 |  ((value) >> 28)			   | \
	 (((value) << 20) & ((quint32)15 << 24)) | (((value) >> 20) & ((quint32)15 <<  4)) | \
	 (((value) << 12) & ((quint32)15 << 20)) | (((value) >> 12) & ((quint32)15 <<  8)) | \
	 (((value) <<  4) & ((quint32)15 << 16)) | (((value) >>  4) & ((quint32)15 << 12)) )

#define Q_32BIT_REVERSED_IN_8BIT(value)							      \
	( ((value) << 24)			  |  ((value) >> 24)			    | \
	 (((value) <<  8) & ((quint32)255 << 16)) | (((value) >>  8) & ((quint32)255 << 8)) )

#define Q_32BIT_REVERSED_IN_16BIT(value) (((value) << 16) | ((value) >> 16))

#define Q_64BIT_REVERSED_IN_1BIT(value)							   \
	( ((value) << 63)			|  ((value) >> 63)			 | \
	 (((value) << 61) & ((quint64)1 << 62)) | (((value) >> 61) & ((quint64)1 <<  1)) | \
	 (((value) << 59) & ((quint64)1 << 61)) | (((value) >> 59) & ((quint64)1 <<  2)) | \
	 (((value) << 57) & ((quint64)1 << 60)) | (((value) >> 57) & ((quint64)1 <<  3)) | \
	 (((value) << 55) & ((quint64)1 << 59)) | (((value) >> 55) & ((quint64)1 <<  4)) | \
	 (((value) << 53) & ((quint64)1 << 58)) | (((value) >> 53) & ((quint64)1 <<  5)) | \
	 (((value) << 51) & ((quint64)1 << 57)) | (((value) >> 51) & ((quint64)1 <<  6)) | \
	 (((value) << 49) & ((quint64)1 << 56)) | (((value) >> 49) & ((quint64)1 <<  7)) | \
	 (((value) << 47) & ((quint64)1 << 55)) | (((value) >> 47) & ((quint64)1 <<  8)) | \
	 (((value) << 45) & ((quint64)1 << 54)) | (((value) >> 45) & ((quint64)1 <<  9)) | \
	 (((value) << 43) & ((quint64)1 << 53)) | (((value) >> 43) & ((quint64)1 << 10)) | \
	 (((value) << 41) & ((quint64)1 << 52)) | (((value) >> 41) & ((quint64)1 << 11)) | \
	 (((value) << 39) & ((quint64)1 << 51)) | (((value) >> 39) & ((quint64)1 << 12)) | \
	 (((value) << 37) & ((quint64)1 << 50)) | (((value) >> 37) & ((quint64)1 << 13)) | \
	 (((value) << 35) & ((quint64)1 << 49)) | (((value) >> 35) & ((quint64)1 << 14)) | \
	 (((value) << 33) & ((quint64)1 << 48)) | (((value) >> 33) & ((quint64)1 << 15)) | \
	 (((value) << 31) & ((quint64)1 << 47)) | (((value) >> 31) & ((quint64)1 << 16)) | \
	 (((value) << 29) & ((quint64)1 << 46)) | (((value) >> 29) & ((quint64)1 << 17)) | \
	 (((value) << 27) & ((quint64)1 << 45)) | (((value) >> 27) & ((quint64)1 << 18)) | \
	 (((value) << 25) & ((quint64)1 << 44)) | (((value) >> 25) & ((quint64)1 << 19)) | \
	 (((value) << 23) & ((quint64)1 << 43)) | (((value) >> 23) & ((quint64)1 << 20)) | \
	 (((value) << 21) & ((quint64)1 << 42)) | (((value) >> 21) & ((quint64)1 << 21)) | \
	 (((value) << 19) & ((quint64)1 << 41)) | (((value) >> 19) & ((quint64)1 << 22)) | \
	 (((value) << 17) & ((quint64)1 << 40)) | (((value) >> 17) & ((quint64)1 << 23)) | \
	 (((value) << 15) & ((quint64)1 << 39)) | (((value) >> 15) & ((quint64)1 << 24)) | \
	 (((value) << 13) & ((quint64)1 << 38)) | (((value) >> 13) & ((quint64)1 << 25)) | \
	 (((value) << 11) & ((quint64)1 << 37)) | (((value) >> 11) & ((quint64)1 << 26)) | \
	 (((value) <<  9) & ((quint64)1 << 36)) | (((value) >>	9) & ((quint64)1 << 27)) | \
	 (((value) <<  7) & ((quint64)1 << 35)) | (((value) >>	7) & ((quint64)1 << 28)) | \
	 (((value) <<  5) & ((quint64)1 << 34)) | (((value) >>	5) & ((quint64)1 << 29)) | \
	 (((value) <<  3) & ((quint64)1 << 33)) | (((value) >>	3) & ((quint64)1 << 30)) | \
	 (((value) <<  1) & ((quint64)1 << 32)) | (((value) >>	1) & ((quint64)1 << 31)) )

#define Q_64BIT_REVERSED_IN_2BIT(value)							   \
	( ((value) << 62)			|  ((value) >> 62)			 | \
	 (((value) << 58) & ((quint64)3 << 60)) | (((value) >> 58) & ((quint64)3 <<  2)) | \
	 (((value) << 54) & ((quint64)3 << 58)) | (((value) >> 54) & ((quint64)3 <<  4)) | \
	 (((value) << 50) & ((quint64)3 << 56)) | (((value) >> 50) & ((quint64)3 <<  6)) | \
	 (((value) << 46) & ((quint64)3 << 54)) | (((value) >> 46) & ((quint64)3 <<  8)) | \
	 (((value) << 42) & ((quint64)3 << 52)) | (((value) >> 42) & ((quint64)3 << 10)) | \
	 (((value) << 38) & ((quint64)3 << 50)) | (((value) >> 38) & ((quint64)3 << 12)) | \
	 (((value) << 34) & ((quint64)3 << 48)) | (((value) >> 34) & ((quint64)3 << 14)) | \
	 (((value) << 30) & ((quint64)3 << 46)) | (((value) >> 30) & ((quint64)3 << 16)) | \
	 (((value) << 26) & ((quint64)3 << 44)) | (((value) >> 26) & ((quint64)3 << 18)) | \
	 (((value) << 22) & ((quint64)3 << 42)) | (((value) >> 22) & ((quint64)3 << 20)) | \
	 (((value) << 18) & ((quint64)3 << 40)) | (((value) >> 18) & ((quint64)3 << 22)) | \
	 (((value) << 14) & ((quint64)3 << 38)) | (((value) >> 14) & ((quint64)3 << 24)) | \
	 (((value) << 10) & ((quint64)3 << 36)) | (((value) >> 10) & ((quint64)3 << 26)) | \
	 (((value) <<  6) & ((quint64)3 << 34)) | (((value) >>	6) & ((quint64)3 << 28)) | \
	 (((value) <<  2) & ((quint64)3 << 32)) | (((value) >>	2) & ((quint64)3 << 30)) )

#define Q_64BIT_REVERSED_IN_4BIT(value)							     \
	( ((value) << 60)			 |  ((value) >> 60)			   | \
	 (((value) << 52) & ((quint64)15 << 56)) | (((value) >> 52) & ((quint64)15 <<  4)) | \
	 (((value) << 44) & ((quint64)15 << 52)) | (((value) >> 44) & ((quint64)15 <<  8)) | \
	 (((value) << 36) & ((quint64)15 << 48)) | (((value) >> 36) & ((quint64)15 << 12)) | \
	 (((value) << 28) & ((quint64)15 << 44)) | (((value) >> 28) & ((quint64)15 << 16)) | \
	 (((value) << 20) & ((quint64)15 << 40)) | (((value) >> 20) & ((quint64)15 << 20)) | \
	 (((value) << 12) & ((quint64)15 << 36)) | (((value) >> 12) & ((quint64)15 << 24)) | \
	 (((value) <<  4) & ((quint64)15 << 32)) | (((value) >>  4) & ((quint64)15 << 28)) )

#define Q_64BIT_REVERSED_IN_8BIT(value)							       \
	( ((value) << 56)			  |  ((value) >> 56)			     | \
	 (((value) << 40) & ((quint64)255 << 48)) | (((value) >> 40) & ((quint64)255 <<  8)) | \
	 (((value) << 24) & ((quint64)255 << 40)) | (((value) >> 24) & ((quint64)255 << 16)) | \
	 (((value) <<  8) & ((quint64)255 << 32)) | (((value) >>  8) & ((quint64)255 << 24)) )

#define Q_64BIT_REVERSED_IN_16BIT(value)							   \
	( ((value) << 48)			    |  ((value) >> 48)				 | \
	 (((value) << 16) & ((quint64)65535 << 32)) | (((value) >> 16) & ((quint64)65535 << 16)) )

#define Q_64BIT_REVERSED_IN_32BIT(value) (((value) << 32) | ((value) >> 32))

#define Q_8BIT_REVERSE_IN_1BIT(  value) ((value) = Q_8BIT_REVERSED_IN_1BIT ( value))
#define Q_8BIT_REVERSE_IN_2BIT(  value) ((value) = Q_8BIT_REVERSED_IN_1BIT ( value))
#define Q_8BIT_REVERSE_IN_4BIT(  value) ((value) = Q_8BIT_REVERSED_IN_1BIT ( value))
#define Q_16BIT_REVERSE_IN_1BIT( value) ((value) = Q_16BIT_REVERSED_IN_1BIT( value))
#define Q_16BIT_REVERSE_IN_2BIT( value) ((value) = Q_16BIT_REVERSED_IN_2BIT( value))
#define Q_16BIT_REVERSE_IN_4BIT( value) ((value) = Q_16BIT_REVERSED_IN_4BIT( value))
#define Q_16BIT_REVERSE_IN_8BIT( value) ((value) = Q_16BIT_REVERSED_IN_8BIT( value))
#define Q_32BIT_REVERSE_IN_1BIT( value) ((value) = Q_32BIT_REVERSED_IN_1BIT( value))
#define Q_32BIT_REVERSE_IN_2BIT( value) ((value) = Q_32BIT_REVERSED_IN_2BIT( value))
#define Q_32BIT_REVERSE_IN_4BIT( value) ((value) = Q_32BIT_REVERSED_IN_4BIT( value))
#define Q_32BIT_REVERSE_IN_8BIT( value) ((value) = Q_32BIT_REVERSED_IN_8BIT( value))
#define Q_32BIT_REVERSE_IN_16BIT(value) ((value) = Q_32BIT_REVERSED_IN_16BIT(value))
#define Q_64BIT_REVERSE_IN_1BIT( value) ((value) = Q_64BIT_REVERSED_IN_1BIT( value))
#define Q_64BIT_REVERSE_IN_2BIT( value) ((value) = Q_64BIT_REVERSED_IN_2BIT( value))
#define Q_64BIT_REVERSE_IN_4BIT( value) ((value) = Q_64BIT_REVERSED_IN_4BIT( value))
#define Q_64BIT_REVERSE_IN_8BIT( value) ((value) = Q_64BIT_REVERSED_IN_8BIT( value))
#define Q_64BIT_REVERSE_IN_16BIT(value) ((value) = Q_64BIT_REVERSED_IN_16BIT(value))
#define Q_64BIT_REVERSE_IN_32BIT(value) ((value) = Q_64BIT_REVERSED_IN_32BIT(value))

#if Q_IS_AVAILABLE(UINT128)

#	define Q_128BIT_REVERSED_IN_1BIT(value)								\
		( ((value) << 127)			   |  ((value) >> 127)			      | \
		 (((value) << 125) & ((quint128)1 << 126)) | (((value) >> 125) & ((quint128)1 <<  1)) | \
		 (((value) << 123) & ((quint128)1 << 125)) | (((value) >> 123) & ((quint128)1 <<  2)) | \
		 (((value) << 121) & ((quint128)1 << 124)) | (((value) >> 121) & ((quint128)1 <<  3)) | \
		 (((value) << 119) & ((quint128)1 << 123)) | (((value) >> 119) & ((quint128)1 <<  4)) | \
		 (((value) << 117) & ((quint128)1 << 122)) | (((value) >> 117) & ((quint128)1 <<  5)) | \
		 (((value) << 115) & ((quint128)1 << 121)) | (((value) >> 115) & ((quint128)1 <<  6)) | \
		 (((value) << 113) & ((quint128)1 << 120)) | (((value) >> 113) & ((quint128)1 <<  7)) | \
		 (((value) << 111) & ((quint128)1 << 119)) | (((value) >> 111) & ((quint128)1 <<  8)) | \
		 (((value) << 109) & ((quint128)1 << 118)) | (((value) >> 109) & ((quint128)1 <<  9)) | \
		 (((value) << 107) & ((quint128)1 << 117)) | (((value) >> 107) & ((quint128)1 << 10)) | \
		 (((value) << 105) & ((quint128)1 << 116)) | (((value) >> 105) & ((quint128)1 << 11)) | \
		 (((value) << 103) & ((quint128)1 << 115)) | (((value) >> 103) & ((quint128)1 << 12)) | \
		 (((value) << 101) & ((quint128)1 << 114)) | (((value) >> 101) & ((quint128)1 << 13)) | \
		 (((value) <<  99) & ((quint128)1 << 113)) | (((value) >>  99) & ((quint128)1 << 14)) | \
		 (((value) <<  97) & ((quint128)1 << 112)) | (((value) >>  97) & ((quint128)1 << 15)) | \
		 (((value) <<  95) & ((quint128)1 << 111)) | (((value) >>  95) & ((quint128)1 << 16)) | \
		 (((value) <<  93) & ((quint128)1 << 110)) | (((value) >>  93) & ((quint128)1 << 17)) | \
		 (((value) <<  91) & ((quint128)1 << 109)) | (((value) >>  91) & ((quint128)1 << 18)) | \
		 (((value) <<  89) & ((quint128)1 << 108)) | (((value) >>  89) & ((quint128)1 << 19)) | \
		 (((value) <<  87) & ((quint128)1 << 107)) | (((value) >>  87) & ((quint128)1 << 20)) | \
		 (((value) <<  85) & ((quint128)1 << 106)) | (((value) >>  85) & ((quint128)1 << 21)) | \
		 (((value) <<  83) & ((quint128)1 << 105)) | (((value) >>  83) & ((quint128)1 << 22)) | \
		 (((value) <<  81) & ((quint128)1 << 104)) | (((value) >>  81) & ((quint128)1 << 23)) | \
		 (((value) <<  79) & ((quint128)1 << 103)) | (((value) >>  79) & ((quint128)1 << 24)) | \
		 (((value) <<  77) & ((quint128)1 << 102)) | (((value) >>  77) & ((quint128)1 << 25)) | \
		 (((value) <<  75) & ((quint128)1 << 101)) | (((value) >>  75) & ((quint128)1 << 26)) | \
		 (((value) <<  73) & ((quint128)1 << 100)) | (((value) >>  73) & ((quint128)1 << 27)) | \
		 (((value) <<  71) & ((quint128)1 <<  99)) | (((value) >>  71) & ((quint128)1 << 28)) | \
		 (((value) <<  69) & ((quint128)1 <<  98)) | (((value) >>  69) & ((quint128)1 << 29)) | \
		 (((value) <<  67) & ((quint128)1 <<  97)) | (((value) >>  67) & ((quint128)1 << 30)) | \
		 (((value) <<  65) & ((quint128)1 <<  96)) | (((value) >>  65) & ((quint128)1 << 31)) | \
		 (((value) <<  63) & ((quint128)1 <<  95)) | (((value) >>  63) & ((quint128)1 << 32)) | \
		 (((value) <<  61) & ((quint128)1 <<  94)) | (((value) >>  61) & ((quint128)1 << 33)) | \
		 (((value) <<  59) & ((quint128)1 <<  93)) | (((value) >>  59) & ((quint128)1 << 34)) | \
		 (((value) <<  57) & ((quint128)1 <<  92)) | (((value) >>  57) & ((quint128)1 << 35)) | \
		 (((value) <<  55) & ((quint128)1 <<  91)) | (((value) >>  55) & ((quint128)1 << 36)) | \
		 (((value) <<  53) & ((quint128)1 <<  90)) | (((value) >>  53) & ((quint128)1 << 37)) | \
		 (((value) <<  51) & ((quint128)1 <<  89)) | (((value) >>  51) & ((quint128)1 << 38)) | \
		 (((value) <<  49) & ((quint128)1 <<  88)) | (((value) >>  49) & ((quint128)1 << 39)) | \
		 (((value) <<  47) & ((quint128)1 <<  87)) | (((value) >>  47) & ((quint128)1 << 40)) | \
		 (((value) <<  45) & ((quint128)1 <<  86)) | (((value) >>  45) & ((quint128)1 << 41)) | \
		 (((value) <<  43) & ((quint128)1 <<  85)) | (((value) >>  43) & ((quint128)1 << 42)) | \
		 (((value) <<  41) & ((quint128)1 <<  84)) | (((value) >>  41) & ((quint128)1 << 43)) | \
		 (((value) <<  39) & ((quint128)1 <<  83)) | (((value) >>  39) & ((quint128)1 << 44)) | \
		 (((value) <<  37) & ((quint128)1 <<  82)) | (((value) >>  37) & ((quint128)1 << 45)) | \
		 (((value) <<  35) & ((quint128)1 <<  81)) | (((value) >>  35) & ((quint128)1 << 46)) | \
		 (((value) <<  33) & ((quint128)1 <<  80)) | (((value) >>  33) & ((quint128)1 << 47)) | \
		 (((value) <<  31) & ((quint128)1 <<  79)) | (((value) >>  31) & ((quint128)1 << 48)) | \
		 (((value) <<  29) & ((quint128)1 <<  78)) | (((value) >>  29) & ((quint128)1 << 49)) | \
		 (((value) <<  27) & ((quint128)1 <<  77)) | (((value) >>  27) & ((quint128)1 << 50)) | \
		 (((value) <<  25) & ((quint128)1 <<  76)) | (((value) >>  25) & ((quint128)1 << 51)) | \
		 (((value) <<  23) & ((quint128)1 <<  75)) | (((value) >>  23) & ((quint128)1 << 52)) | \
		 (((value) <<  21) & ((quint128)1 <<  74)) | (((value) >>  21) & ((quint128)1 << 53)) | \
		 (((value) <<  19) & ((quint128)1 <<  73)) | (((value) >>  19) & ((quint128)1 << 54)) | \
		 (((value) <<  17) & ((quint128)1 <<  72)) | (((value) >>  17) & ((quint128)1 << 55)) | \
		 (((value) <<  15) & ((quint128)1 <<  71)) | (((value) >>  15) & ((quint128)1 << 56)) | \
		 (((value) <<  13) & ((quint128)1 <<  70)) | (((value) >>  13) & ((quint128)1 << 57)) | \
		 (((value) <<  11) & ((quint128)1 <<  69)) | (((value) >>  11) & ((quint128)1 << 58)) | \
		 (((value) <<	9) & ((quint128)1 <<  68)) | (((value) >>   9) & ((quint128)1 << 59)) | \
		 (((value) <<	7) & ((quint128)1 <<  67)) | (((value) >>   7) & ((quint128)1 << 60)) | \
		 (((value) <<	5) & ((quint128)1 <<  66)) | (((value) >>   5) & ((quint128)1 << 61)) | \
		 (((value) <<	3) & ((quint128)1 <<  65)) | (((value) >>   3) & ((quint128)1 << 62)) | \
		 (((value) <<	1) & ((quint128)1 <<  64)) | (((value) >>   1) & ((quint128)1 << 63)) )

#	define Q_128BIT_REVERSED_IN_2BIT(value)								\
		( ((value) << 126)			   |  ((value) >> 126)			      | \
		 (((value) << 122) & ((quint128)3 << 124)) | (((value) >> 122) & ((quint128)3 <<  2)) | \
		 (((value) << 118) & ((quint128)3 << 122)) | (((value) >> 118) & ((quint128)3 <<  4)) | \
		 (((value) << 114) & ((quint128)3 << 120)) | (((value) >> 114) & ((quint128)3 <<  6)) | \
		 (((value) << 110) & ((quint128)3 << 118)) | (((value) >> 110) & ((quint128)3 <<  8)) | \
		 (((value) << 106) & ((quint128)3 << 116)) | (((value) >> 106) & ((quint128)3 << 10)) | \
		 (((value) << 102) & ((quint128)3 << 114)) | (((value) >> 102) & ((quint128)3 << 12)) | \
		 (((value) <<  98) & ((quint128)3 << 112)) | (((value) >>  98) & ((quint128)3 << 14)) | \
		 (((value) <<  94) & ((quint128)3 << 110)) | (((value) >>  94) & ((quint128)3 << 16)) | \
		 (((value) <<  90) & ((quint128)3 << 108)) | (((value) >>  90) & ((quint128)3 << 18)) | \
		 (((value) <<  86) & ((quint128)3 << 106)) | (((value) >>  86) & ((quint128)3 << 20)) | \
		 (((value) <<  82) & ((quint128)3 << 104)) | (((value) >>  82) & ((quint128)3 << 22)) | \
		 (((value) <<  78) & ((quint128)3 << 102)) | (((value) >>  78) & ((quint128)3 << 24)) | \
		 (((value) <<  74) & ((quint128)3 << 100)) | (((value) >>  74) & ((quint128)3 << 26)) | \
		 (((value) <<  70) & ((quint128)3 <<  98)) | (((value) >>  70) & ((quint128)3 << 28)) | \
		 (((value) <<  66) & ((quint128)3 <<  96)) | (((value) >>  66) & ((quint128)3 << 30)) | \
		 (((value) <<  62) & ((quint128)3 <<  94)) | (((value) >>  62) & ((quint128)3 << 32)) | \
		 (((value) <<  58) & ((quint128)3 <<  92)) | (((value) >>  58) & ((quint128)3 << 34)) | \
		 (((value) <<  54) & ((quint128)3 <<  90)) | (((value) >>  54) & ((quint128)3 << 36)) | \
		 (((value) <<  50) & ((quint128)3 <<  88)) | (((value) >>  50) & ((quint128)3 << 38)) | \
		 (((value) <<  46) & ((quint128)3 <<  86)) | (((value) >>  46) & ((quint128)3 << 40)) | \
		 (((value) <<  42) & ((quint128)3 <<  84)) | (((value) >>  42) & ((quint128)3 << 42)) | \
		 (((value) <<  38) & ((quint128)3 <<  82)) | (((value) >>  38) & ((quint128)3 << 44)) | \
		 (((value) <<  34) & ((quint128)3 <<  80)) | (((value) >>  34) & ((quint128)3 << 46)) | \
		 (((value) <<  30) & ((quint128)3 <<  78)) | (((value) >>  30) & ((quint128)3 << 48)) | \
		 (((value) <<  26) & ((quint128)3 <<  76)) | (((value) >>  26) & ((quint128)3 << 50)) | \
		 (((value) <<  22) & ((quint128)3 <<  74)) | (((value) >>  22) & ((quint128)3 << 52)) | \
		 (((value) <<  18) & ((quint128)3 <<  72)) | (((value) >>  18) & ((quint128)3 << 54)) | \
		 (((value) <<  14) & ((quint128)3 <<  70)) | (((value) >>  14) & ((quint128)3 << 56)) | \
		 (((value) <<  10) & ((quint128)3 <<  68)) | (((value) >>  10) & ((quint128)3 << 58)) | \
		 (((value) <<	6) & ((quint128)3 <<  66)) | (((value) >>   6) & ((quint128)3 << 60)) | \
		 (((value) <<	2) & ((quint128)3 <<  64)) | (((value) >>   2) & ((quint128)3 << 62)) )

#	define Q_128BIT_REVERSED_IN_4BIT(value)								  \
		( ((value) << 124)			    |  ((value) >> 124)				| \
		 (((value) << 116) & ((quint128)15 << 120)) | (((value) >> 116) & ((quint128)15 <<  4)) | \
		 (((value) << 108) & ((quint128)15 << 116)) | (((value) >> 108) & ((quint128)15 <<  8)) | \
		 (((value) << 100) & ((quint128)15 << 112)) | (((value) >> 100) & ((quint128)15 << 12)) | \
		 (((value) <<  92) & ((quint128)15 << 108)) | (((value) >>  92) & ((quint128)15 << 16)) | \
		 (((value) <<  84) & ((quint128)15 << 104)) | (((value) >>  84) & ((quint128)15 << 20)) | \
		 (((value) <<  76) & ((quint128)15 << 100)) | (((value) >>  76) & ((quint128)15 << 24)) | \
		 (((value) <<  68) & ((quint128)15 <<  96)) | (((value) >>  68) & ((quint128)15 << 28)) | \
		 (((value) <<  60) & ((quint128)15 <<  92)) | (((value) >>  60) & ((quint128)15 << 32)) | \
		 (((value) <<  52) & ((quint128)15 <<  88)) | (((value) >>  52) & ((quint128)15 << 36)) | \
		 (((value) <<  44) & ((quint128)15 <<  84)) | (((value) >>  44) & ((quint128)15 << 40)) | \
		 (((value) <<  36) & ((quint128)15 <<  80)) | (((value) >>  36) & ((quint128)15 << 44)) | \
		 (((value) <<  28) & ((quint128)15 <<  76)) | (((value) >>  28) & ((quint128)15 << 48)) | \
		 (((value) <<  20) & ((quint128)15 <<  72)) | (((value) >>  20) & ((quint128)15 << 52)) | \
		 (((value) <<  12) & ((quint128)15 <<  68)) | (((value) >>  12) & ((quint128)15 << 56)) | \
		 (((value) <<	4) & ((quint128)15 <<  64)) | (((value) >>   4) & ((quint128)15 << 60)) )

#	define Q_128BIT_REVERSED_IN_8BIT(value)								    \
		( ((value) << 120)			     |	((value) >> 120)			  | \
		 (((value) << 104) & ((quint128)255 << 112)) | (((value) >> 104) & ((quint128)255 <<  8)) | \
		 (((value) <<  88) & ((quint128)255 << 104)) | (((value) >>  88) & ((quint128)255 << 16)) | \
		 (((value) <<  72) & ((quint128)255 <<	96)) | (((value) >>  72) & ((quint128)255 << 24)) | \
		 (((value) <<  56) & ((quint128)255 <<	88)) | (((value) >>  56) & ((quint128)255 << 32)) | \
		 (((value) <<  40) & ((quint128)255 <<	80)) | (((value) >>  40) & ((quint128)255 << 40)) | \
		 (((value) <<  24) & ((quint128)255 <<	72)) | (((value) >>  24) & ((quint128)255 << 48)) | \
		 (((value) <<	8) & ((quint128)255 <<	64)) | (((value) >>   8) & ((quint128)255 << 56)) )

#	define Q_128BIT_REVERSED_IN_16BIT(value)							       \
		( ((value) << 112)			      |  ((value) >> 112)			     | \
		 (((value) <<  80) & ((quint128)65535 << 96)) | (((value) >>  80) & ((quint128)65535 << 16)) | \
		 (((value) <<  48) & ((quint128)65535 << 80)) | (((value) >>  48) & ((quint128)65535 << 32)) | \
		 (((value) <<  16) & ((quint128)65535 << 64)) | (((value) >>  16) & ((quint128)65535 << 48)) )

#	define Q_128BIT_REVERSED_IN_32BIT(value)								       \
		( ((value) << 96)				  |  ((value) >> 96)				     | \
		 (((value) << 32) & ((quint128)4294967295 << 64)) | (((value) >> 32) & ((quint128)4294967295 << 32)) )

#	define Q_128BIT_REVERSED_IN_64BIT(value) (((value) << 64) | ((value) >> 64))

#	define Q_128BIT_REVERSE_IN_1BIT(  value) ((value) = Q_128BIT_REVERSED_IN_1BIT( value))
#	define Q_128BIT_REVERSE_IN_2BIT(  value) ((value) = Q_128BIT_REVERSED_IN_2BIT( value))
#	define Q_128BIT_REVERSE_IN_4BIT(  value) ((value) = Q_128BIT_REVERSED_IN_4BIT( value))
#	define Q_128BIT_REVERSE_IN_8BIT(  value) ((value) = Q_128BIT_REVERSED_IN_8BIT( value))
#	define Q_128BIT_REVERSE_IN_16BIT( value) ((value) = Q_128BIT_REVERSED_IN_16BIT(value))
#	define Q_128BIT_REVERSE_IN_32BIT( value) ((value) = Q_128BIT_REVERSED_IN_32BIT(value))
#	define Q_128BIT_REVERSE_IN_64BIT( value) ((value) = Q_128BIT_REVERSED_IN_64BIT(value))

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

#if Q_IS_AVAILABLE(UINT128)

#	if Q_INT128_ENDIANNESS == Q_ENDIANNESS_BIG

#		define Q_128BIT_ENSURE_BIG_ENDIAN(value)
#		define Q_128BIT_ENSURE_LITTLE_ENDIAN		Q_128BIT_REVERSE_IN_8BIT
#		define Q_128BIT_BIG_ENDIAN(value)		(value)
#		define Q_128BIT_LITTLE_ENDIAN			Q_128BIT_REVERSED_IN_8BIT

#	elif Q_INT128_ENDIANNESS == Q_ENDIANNESS_LITTLE

#		define Q_128BIT_ENSURE_BIG_ENDIAN		Q_128BIT_REVERSE_IN_8BIT
#		define Q_128BIT_ENSURE_LITTLE_ENDIAN(value)
#		define Q_128BIT_BIG_ENDIAN			Q_128BIT_REVERSED_IN_8BIT
#		define Q_128BIT_LITTLE_ENDIAN(value)		(value)

#	endif

#endif

#define Q_ENSURE_BIG_ENDIAN(   TYPE) Q_JOIN_3(Q_, Q_##TYPE##_BITS, BIT_ENSURE_BIG_ENDIAN   )
#define Q_ENSURE_LITTLE_ENDIAN(TYPE) Q_JOIN_3(Q_, Q_##TYPE##_BITS, BIT_ENSURE_LITTLE_ENDIAN)
#define Q_BIG_ENDIAN(	       TYPE) Q_JOIN_3(Q_, Q_##TYPE##_BITS, BIT_BIG_ENDIAN	   )
#define Q_LITTLE_ENDIAN(       TYPE) Q_JOIN_3(Q_, Q_##TYPE##_BITS, BIT_LITTLE_ENDIAN	   )

#endif /* __Q_macros_value_H__ */
