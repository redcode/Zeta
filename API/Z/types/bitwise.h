/* Z Kit - types/bitwise.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//__/__| Kit
Copyright (C) 2006-2020 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_types_bitwise_H
#define Z_types_bitwise_H

#include <Z/types/integral.h>
#include <Z/macros/language.h>
#include <Z/macros/aggregate.h>

#if defined(Z_UINT8) || defined(Z_SINT8)

	Z_DEFINE_PACKED_UNION_BEGIN {
#		ifdef Z_UINT8
			zuint8 uint8_value;
#		endif

#		ifdef Z_SINT8
			zsint8 sint8_value;
#		endif
	} Z_DEFINE_PACKED_UNION_END (Z8Bit);

#endif

#if	defined(Z_UINT8 ) || defined(Z_SINT8 ) || \
	defined(Z_UINT16) || defined(Z_SINT16)

	Z_DEFINE_PACKED_UNION_BEGIN {
#		ifdef Z_UINT16
			zuint16 uint16_value;
#		endif

#		ifdef Z_SINT16
			zsint16 sint16_value;
#		endif

#		ifdef Z_UINT8
			zuint8 uint8_array[2];

			struct {Z_ENDIANIZED_MEMBERS(16, 2) (
				zuint8 index1,
				zuint8 index0
			)} uint8_values;
#		endif

#		ifdef Z_SINT8
			zsint8 sint8_array[2];

			struct {Z_ENDIANIZED_MEMBERS(16, 2) (
				zsint8 index1,
				zsint8 index0
			)} sint8_values;
#		endif
	} Z_DEFINE_PACKED_UNION_END (Z16Bit);

#endif

#if	defined(Z_UINT8 ) || defined(Z_SINT8 ) || \
	defined(Z_UINT16) || defined(Z_SINT16) || \
	defined(Z_UINT32) || defined(Z_SINT32)

	Z_DEFINE_PACKED_UNION_BEGIN {
#		ifdef Z_UINT32
			zuint32 uint32_value;
#		endif

#		ifdef Z_SINT32
			zsint32 sint32_value;
#		endif

#		ifdef Z_UINT16
			zuint16 uint16_array[2];

			struct {Z_ENDIANIZED_MEMBERS(32, 2) (
				zuint16 index1,
				zuint16 index0
			)} uint16_values;
#		endif

#		ifdef Z_SINT16
			zsint16 sint16_array[2];

			struct {Z_ENDIANIZED_MEMBERS(32, 2) (
				zsint16 index1,
				zsint16 index0
			)} sint16_values;
#		endif

#		ifdef Z_UINT8
			zuint8 uint8_array[4];

			struct {Z_ENDIANIZED_MEMBERS(32, 4) (
				zuint8 index3,
				zuint8 index2,
				zuint8 index1,
				zuint8 index0
			)} uint8_values;
#		endif

#		ifdef Z_SINT8
			zsint8 sint8_array[4];

			struct {Z_ENDIANIZED_MEMBERS(32, 4) (
				zsint8 index3,
				zsint8 index2,
				zsint8 index1,
				zsint8 index0
			)} sint8_values;
#		endif
	} Z_DEFINE_PACKED_UNION_END (Z32Bit);

#endif

#if	defined(Z_UINT8 ) || defined(Z_SINT8 ) || \
	defined(Z_UINT16) || defined(Z_SINT16) || \
	defined(Z_UINT32) || defined(Z_SINT32) || \
	defined(Z_UINT64) || defined(Z_SINT64)

	Z_DEFINE_PACKED_UNION_BEGIN {
#		ifdef Z_UINT64
			zuint64 uint64_value;
#		endif

#		ifdef Z_SINT64
			zsint64 sint64_value;
#		endif

#		ifdef Z_UINT32
			zuint32 uint32_array[2];

			struct {Z_ENDIANIZED_MEMBERS(64, 2) (
				zuint32 index1,
				zuint32 index0
			)} uint32_values;
#		endif

#		ifdef Z_SINT32
			zsint32 sint32_array[2];

			struct {Z_ENDIANIZED_MEMBERS(64, 2) (
				zsint32 index1,
				zsint32 index0
			)} sint32_values;
#		endif

#		ifdef Z_UINT16
			zuint16 uint16_array[4];

			struct {Z_ENDIANIZED_MEMBERS(64, 4) (
				zuint16 index3,
				zuint16 index2,
				zuint16 index1,
				zuint16 index0
			)} uint16_values;
#		endif

#		ifdef Z_SINT16
			zsint16 sint16_array[4];

			struct {Z_ENDIANIZED_MEMBERS(64, 4) (
				zsint16 index3,
				zsint16 index2,
				zsint16 index1,
				zsint16 index0
			)} sint16_values;
#		endif

#		ifdef Z_UINT8
			zuint8 uint8_array[8];

			struct {Z_ENDIANIZED_MEMBERS(64, 8) (
				zuint8 index7,
				zuint8 index6,
				zuint8 index5,
				zuint8 index4,
				zuint8 index3,
				zuint8 index2,
				zuint8 index1,
				zuint8 index0
			)} uint8_values;
#		endif

#		ifdef Z_SINT8
			zsint8 sint8_array[8];

			struct {Z_ENDIANIZED_MEMBERS(64, 8) (
				zsint8 index7,
				zsint8 index6,
				zsint8 index5,
				zsint8 index4,
				zsint8 index3,
				zsint8 index2,
				zsint8 index1,
				zsint8 index0
			)} sint8_values;
#		endif
	} Z_DEFINE_PACKED_UNION_END (Z64Bit);

#endif

#if	defined(Z_UINT8	 ) || defined(Z_SINT8  ) || \
	defined(Z_UINT16 ) || defined(Z_SINT16 ) || \
	defined(Z_UINT32 ) || defined(Z_SINT32 ) || \
	defined(Z_UINT64 ) || defined(Z_SINT64 ) || \
	defined(Z_UINT128) || defined(Z_SINT128)

	Z_DEFINE_PACKED_UNION_BEGIN {
#		ifdef Z_UINT128
			zuint128 uint128_value;
#		endif

#		ifdef Z_SINT128
			zsint128 sint128_value;
#		endif

#		ifdef Z_UINT64
			zuint64 uint64_array[2];

			struct {Z_ENDIANIZED_MEMBERS(128, 2) (
				zuint64 index1,
				zuint64 index0
			)} uint64_values;
#		endif

#		ifdef Z_SINT64
			zsint64 sint64_array[2];

			struct {Z_ENDIANIZED_MEMBERS(128, 2) (
				zsint64 index1,
				zsint64 index0
			)} sint64_values;
#		endif

#		ifdef Z_UINT32
			zuint32 uint32_array[4];

			struct {Z_ENDIANIZED_MEMBERS(128, 4) (
				zuint32 index3,
				zuint32 index2,
				zuint32 index1,
				zuint32 index0
			)} uint32_values;
#		endif

#		ifdef Z_SINT32
			zsint32 sint32_array[4];

			struct {Z_ENDIANIZED_MEMBERS(128, 4) (
				zsint32 index3,
				zsint32 index2,
				zsint32 index1,
				zsint32 index0
			)} sint32_values;
#		endif

#		ifdef Z_UINT16
			zuint16 uint16_array[8];

			struct {Z_ENDIANIZED_MEMBERS(128, 8) (
				zuint16 index7,
				zuint16 index6,
				zuint16 index5,
				zuint16 index4,
				zuint16 index3,
				zuint16 index2,
				zuint16 index1,
				zuint16 index0
			)} uint16_values;
#		endif

#		ifdef Z_SINT16
			zsint16 sint16_array[8];

			struct {Z_ENDIANIZED_MEMBERS(128, 8) (
				zsint16 index7,
				zsint16 index6,
				zsint16 index5,
				zsint16 index4,
				zsint16 index3,
				zsint16 index2,
				zsint16 index1,
				zsint16 index0
			)} sint16_values;
#		endif

#		ifdef Z_UINT8
			zuint8 uint8_array[16];

			struct {Z_ENDIANIZED_MEMBERS(128, 16) (
				zuint8 index15,
				zuint8 index14,
				zuint8 index13,
				zuint8 index12,
				zuint8 index11,
				zuint8 index10,
				zuint8 index09,
				zuint8 index08,
				zuint8 index07,
				zuint8 index06,
				zuint8 index05,
				zuint8 index04,
				zuint8 index03,
				zuint8 index02,
				zuint8 index01,
				zuint8 index00
			)} uint8_values;
#		endif

#		ifdef Z_SINT8
			zsint8 sint8_array[16];

			struct {Z_ENDIANIZED_MEMBERS(128, 16) (
				zsint8 index15,
				zsint8 index14,
				zsint8 index13,
				zsint8 index12,
				zsint8 index11,
				zsint8 index10,
				zsint8 index09,
				zsint8 index08,
				zsint8 index07,
				zsint8 index06,
				zsint8 index05,
				zsint8 index04,
				zsint8 index03,
				zsint8 index02,
				zsint8 index01,
				zsint8 index00
			)} sint8_values;
#		endif
	} Z_DEFINE_PACKED_UNION_END (Z128Bit);

#endif

#endif /* Z_types_bitwise_H */
