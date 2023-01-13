/* Zeta API - Z/types/bitwise.h
 ______ ____________  ___
|__   /|  ___|__  __|/   \
  /  /_|  __|  |  | /  *  \
 /_____|_____| |__|/__/ \__\
Copyright (C) 2006-2023 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_types_bitwise_H
#define Z_types_bitwise_H

#include <Z/macros/language.h>
#include <Z/macros/member.h>
#include <Z/types/integral.h>

#if defined(Z_UINT8) || defined(Z_SINT8)
#	define Z_HAS_ZInt8 TRUE

	Z_DEFINE_PACKED_UNION_BEGIN {
#		ifdef Z_UINT8
			zuint8 uint8_value;
			zuint8 uint8_array[1];

			struct {zuint8 at_0;
			} uint8_values;
#		endif

#		ifdef Z_SINT8
			zsint8 sint8_value;
			zsint8 sint8_array;

			struct {zsint8 at_0;
			} sint8_values;
#		endif
	} Z_DEFINE_PACKED_UNION_END (ZInt8);
#endif

#if	defined(Z_UINT8 ) || defined(Z_SINT8 ) || \
	defined(Z_UINT16) || defined(Z_SINT16)

#	define Z_HAS_ZInt16 TRUE

	Z_DEFINE_PACKED_UNION_BEGIN {
#		ifdef Z_UINT16
			zuint16 uint16_value;
			zuint16 uint16_array[1];

			struct {zuint16 at_0;
			} uint16_values;
#		endif

#		ifdef Z_SINT16
			zsint16 sint16_value;
			zsint16 sint16_array;

			struct {zsint16 at_0;
			} sint16_values;
#		endif

#		ifdef Z_UINT8
			zuint8 uint8_array[2];

			struct {Z_ENDIANIZED_MEMBERS(2) (
				zuint8 at_1,
				zuint8 at_0
			)} uint8_values;
#		endif

#		ifdef Z_SINT8
			zsint8 sint8_array[2];

			struct {Z_ENDIANIZED_MEMBERS(2) (
				zsint8 at_1,
				zsint8 at_0
			)} sint8_values;
#		endif
	} Z_DEFINE_PACKED_UNION_END (ZInt16);
#endif

#if	defined(Z_UINT8 ) || defined(Z_SINT8 ) || \
	defined(Z_UINT16) || defined(Z_SINT16) || \
	defined(Z_UINT32) || defined(Z_SINT32)

#	define Z_HAS_ZInt32 TRUE

	Z_DEFINE_PACKED_UNION_BEGIN {
#		ifdef Z_UINT32
			zuint32 uint32_value;
			zuint32 uint32_array[1];

			struct {zuint32 at_0;
			} uint32_values;
#		endif

#		ifdef Z_SINT32
			zsint32 sint32_value;
			zsint32 sint32_array;

			struct {zsint32 at_0;
			} sint32_values;
#		endif

#		ifdef Z_UINT16
			zuint16 uint16_array[2];

			struct {Z_ENDIANIZED_MEMBERS(2) (
				zuint16 at_1,
				zuint16 at_0
			)} uint16_values;
#		endif

#		ifdef Z_SINT16
			zsint16 sint16_array[2];

			struct {Z_ENDIANIZED_MEMBERS(2) (
				zsint16 at_1,
				zsint16 at_0
			)} sint16_values;
#		endif

#		ifdef Z_UINT8
			zuint8 uint8_array[4];

			struct {Z_ENDIANIZED_MEMBERS(4) (
				zuint8 at_3,
				zuint8 at_2,
				zuint8 at_1,
				zuint8 at_0
			)} uint8_values;
#		endif

#		ifdef Z_SINT8
			zsint8 sint8_array[4];

			struct {Z_ENDIANIZED_MEMBERS(4) (
				zsint8 at_3,
				zsint8 at_2,
				zsint8 at_1,
				zsint8 at_0
			)} sint8_values;
#		endif
	} Z_DEFINE_PACKED_UNION_END (ZInt32);
#endif

#if	defined(Z_UINT8 ) || defined(Z_SINT8 ) || \
	defined(Z_UINT16) || defined(Z_SINT16) || \
	defined(Z_UINT32) || defined(Z_SINT32) || \
	defined(Z_UINT64) || defined(Z_SINT64)

#	define Z_HAS_ZInt64 TRUE

	Z_DEFINE_PACKED_UNION_BEGIN {
#		ifdef Z_UINT64
			zuint64 uint64_value;
			zuint64 uint64_array[1];

			struct {zuint64 at_0;
			} uint64_values;
#		endif

#		ifdef Z_SINT64
			zsint64 sint64_value;
			zsint64 sint64_array;

			struct {zsint64 at_0;
			} sint64_values;
#		endif

#		ifdef Z_UINT32
			zuint32 uint32_array[2];

			struct {Z_ENDIANIZED_MEMBERS(2) (
				zuint32 at_1,
				zuint32 at_0
			)} uint32_values;
#		endif

#		ifdef Z_SINT32
			zsint32 sint32_array[2];

			struct {Z_ENDIANIZED_MEMBERS(2) (
				zsint32 at_1,
				zsint32 at_0
			)} sint32_values;
#		endif

#		ifdef Z_UINT16
			zuint16 uint16_array[4];

			struct {Z_ENDIANIZED_MEMBERS(4) (
				zuint16 at_3,
				zuint16 at_2,
				zuint16 at_1,
				zuint16 at_0
			)} uint16_values;
#		endif

#		ifdef Z_SINT16
			zsint16 sint16_array[4];

			struct {Z_ENDIANIZED_MEMBERS(4) (
				zsint16 at_3,
				zsint16 at_2,
				zsint16 at_1,
				zsint16 at_0
			)} sint16_values;
#		endif

#		ifdef Z_UINT8
			zuint8 uint8_array[8];

			struct {Z_ENDIANIZED_MEMBERS(8) (
				zuint8 at_7,
				zuint8 at_6,
				zuint8 at_5,
				zuint8 at_4,
				zuint8 at_3,
				zuint8 at_2,
				zuint8 at_1,
				zuint8 at_0
			)} uint8_values;
#		endif

#		ifdef Z_SINT8
			zsint8 sint8_array[8];

			struct {Z_ENDIANIZED_MEMBERS(8) (
				zsint8 at_7,
				zsint8 at_6,
				zsint8 at_5,
				zsint8 at_4,
				zsint8 at_3,
				zsint8 at_2,
				zsint8 at_1,
				zsint8 at_0
			)} sint8_values;
#		endif
	} Z_DEFINE_PACKED_UNION_END (ZInt64);
#endif

#if	defined(Z_UINT8	 ) || defined(Z_SINT8  ) || \
	defined(Z_UINT16 ) || defined(Z_SINT16 ) || \
	defined(Z_UINT32 ) || defined(Z_SINT32 ) || \
	defined(Z_UINT64 ) || defined(Z_SINT64 ) || \
	defined(Z_UINT128) || defined(Z_SINT128)

#	define Z_HAS_ZInt128 TRUE

	Z_DEFINE_PACKED_UNION_BEGIN {
#		ifdef Z_UINT128
			zuint128 uint128_value;
			zuint128 uint128_array[1];

			struct {zuint128 at_0;
			} uint128_values;
#		endif

#		ifdef Z_SINT128
			zsint128 sint128_value;
			zsint128 sint128_array;

			struct {zsint128 at_0;
			} sint128_values;
#		endif

#		ifdef Z_UINT64
			zuint64 uint64_array[2];

			struct {Z_ENDIANIZED_MEMBERS(2) (
				zuint64 at_1,
				zuint64 at_0
			)} uint64_values;
#		endif

#		ifdef Z_SINT64
			zsint64 sint64_array[2];

			struct {Z_ENDIANIZED_MEMBERS(2) (
				zsint64 at_1,
				zsint64 at_0
			)} sint64_values;
#		endif

#		ifdef Z_UINT32
			zuint32 uint32_array[4];

			struct {Z_ENDIANIZED_MEMBERS(4) (
				zuint32 at_3,
				zuint32 at_2,
				zuint32 at_1,
				zuint32 at_0
			)} uint32_values;
#		endif

#		ifdef Z_SINT32
			zsint32 sint32_array[4];

			struct {Z_ENDIANIZED_MEMBERS(4) (
				zsint32 at_3,
				zsint32 at_2,
				zsint32 at_1,
				zsint32 at_0
			)} sint32_values;
#		endif

#		ifdef Z_UINT16
			zuint16 uint16_array[8];

			struct {Z_ENDIANIZED_MEMBERS(8) (
				zuint16 at_7,
				zuint16 at_6,
				zuint16 at_5,
				zuint16 at_4,
				zuint16 at_3,
				zuint16 at_2,
				zuint16 at_1,
				zuint16 at_0
			)} uint16_values;
#		endif

#		ifdef Z_SINT16
			zsint16 sint16_array[8];

			struct {Z_ENDIANIZED_MEMBERS(8) (
				zsint16 at_7,
				zsint16 at_6,
				zsint16 at_5,
				zsint16 at_4,
				zsint16 at_3,
				zsint16 at_2,
				zsint16 at_1,
				zsint16 at_0
			)} sint16_values;
#		endif

#		ifdef Z_UINT8
			zuint8 uint8_array[16];

			struct {Z_ENDIANIZED_MEMBERS(16) (
				zuint8 at_15,
				zuint8 at_14,
				zuint8 at_13,
				zuint8 at_12,
				zuint8 at_11,
				zuint8 at_10,
				zuint8 at_9,
				zuint8 at_8,
				zuint8 at_7,
				zuint8 at_6,
				zuint8 at_5,
				zuint8 at_4,
				zuint8 at_3,
				zuint8 at_2,
				zuint8 at_1,
				zuint8 at_0
			)} uint8_values;
#		endif

#		ifdef Z_SINT8
			zsint8 sint8_array[16];

			struct {Z_ENDIANIZED_MEMBERS(16) (
				zsint8 at_15,
				zsint8 at_14,
				zsint8 at_13,
				zsint8 at_12,
				zsint8 at_11,
				zsint8 at_10,
				zsint8 at_9,
				zsint8 at_8,
				zsint8 at_7,
				zsint8 at_6,
				zsint8 at_5,
				zsint8 at_4,
				zsint8 at_3,
				zsint8 at_2,
				zsint8 at_1,
				zsint8 at_0
			)} sint8_values;
#		endif
	} Z_DEFINE_PACKED_UNION_END (ZInt128);
#endif

#endif /* Z_types_bitwise_H */
