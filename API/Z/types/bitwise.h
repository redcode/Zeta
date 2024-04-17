/* Zeta API - Z/types/bitwise.h
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_types_bitwise_H
#define Z_types_bitwise_H

#include <Z/inspection/ISA.h>
#include <Z/macros/language.h>
#include <Z/types/integral.h>
#include <Z/macros/structure.h> /* For backward compatibility. To be removed. */

#if defined(Z_UINT8) || defined(Z_SINT8)
#	define Z_HAS_ZInt8 1

	typedef Z_PACKED_UNION_BEGIN {
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
	} Z_PACKED_UNION_END ZInt8;
#endif

#if	defined(Z_UINT8 ) || defined(Z_SINT8 ) || \
	defined(Z_UINT16) || defined(Z_SINT16)

#	define Z_HAS_ZInt16 1

	typedef Z_PACKED_UNION_BEGIN {
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

			struct {
#				if Z_ISA_INTEGRAL_ENDIANNESS != Z_ENDIANNESS_BIG
					zuint8 at_0;
					zuint8 at_1;
#				else
					zuint8 at_1;
					zuint8 at_0;
#				endif
			} uint8_values;
#		endif

#		ifdef Z_SINT8
			zsint8 sint8_array[2];

			struct {
#				if Z_ISA_INTEGRAL_ENDIANNESS != Z_ENDIANNESS_BIG
					zsint8 at_0;
					zsint8 at_1;
#				else
					zsint8 at_1;
					zsint8 at_0;
#				endif
			} sint8_values;
#		endif
	} Z_PACKED_UNION_END ZInt16;
#endif

#if	defined(Z_UINT8 ) || defined(Z_SINT8 ) || \
	defined(Z_UINT16) || defined(Z_SINT16) || \
	defined(Z_UINT32) || defined(Z_SINT32)

#	define Z_HAS_ZInt32 1

	typedef Z_PACKED_UNION_BEGIN {
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

			struct {
#				if Z_ISA_INTEGRAL_ENDIANNESS == Z_ENDIANNESS_LITTLE
					zuint16 at_0;
					zuint16 at_1;
#				else
					zuint16 at_1;
					zuint16 at_0;
#				endif
			} uint16_values;
#		endif

#		ifdef Z_SINT16
			zsint16 sint16_array[2];

			struct {
#				if Z_ISA_INTEGRAL_ENDIANNESS == Z_ENDIANNESS_LITTLE
					zsint16 at_0;
					zsint16 at_1;
#				else
					zsint16 at_1;
					zsint16 at_0;
#				endif
			} sint16_values;
#		endif

#		ifdef Z_UINT8
			zuint8 uint8_array[4];

			struct {
#				if Z_ISA_INTEGRAL_ENDIANNESS == Z_ENDIANNESS_LITTLE
					zuint8 at_0;
					zuint8 at_1;
					zuint8 at_2;
					zuint8 at_3;
#				elif Z_ISA_INTEGRAL_ENDIANNESS == Z_ENDIANNESS_BIG
					zuint8 at_3;
					zuint8 at_2;
					zuint8 at_1;
					zuint8 at_0;
#				else
					zuint8 at_2;
					zuint8 at_3;
					zuint8 at_0;
					zuint8 at_1;
#				endif
			} uint8_values;
#		endif

#		ifdef Z_SINT8
			zsint8 sint8_array[4];

			struct {
#				if Z_ISA_INTEGRAL_ENDIANNESS == Z_ENDIANNESS_LITTLE
					zsint8 at_0;
					zsint8 at_1;
					zsint8 at_2;
					zsint8 at_3;
#				elif Z_ISA_INTEGRAL_ENDIANNESS == Z_ENDIANNESS_BIG
					zsint8 at_3
					zsint8 at_2;
					zsint8 at_1;
					zsint8 at_0;
#				else
					zsint8 at_2;
					zsint8 at_3;
					zsint8 at_0;
					zsint8 at_1;
#				endif
			} sint8_values;
#		endif
	} Z_PACKED_UNION_END ZInt32;
#endif

#if	defined(Z_UINT8 ) || defined(Z_SINT8 ) || \
	defined(Z_UINT16) || defined(Z_SINT16) || \
	defined(Z_UINT32) || defined(Z_SINT32) || \
	defined(Z_UINT64) || defined(Z_SINT64)

#	define Z_HAS_ZInt64 1

	typedef Z_PACKED_UNION_BEGIN {
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

			struct {
#				if Z_ISA_INTEGRAL_ENDIANNESS == Z_ENDIANNESS_LITTLE
					zuint32 at_0;
					zuint32 at_1;
#				else
					zuint32 at_1;
					zuint32 at_0;
#				endif
			} uint32_values;
#		endif

#		ifdef Z_SINT32
			zsint32 sint32_array[2];

			struct {
#				if Z_ISA_INTEGRAL_ENDIANNESS == Z_ENDIANNESS_LITTLE
					zsint32 at_0;
					zsint32 at_1;
#				else
					zsint32 at_1;
					zsint32 at_0;
#				endif
			} sint32_values;
#		endif

#		ifdef Z_UINT16
			zuint16 uint16_array[4];

			struct {
#				if Z_ISA_INTEGRAL_ENDIANNESS == Z_ENDIANNESS_LITTLE
					zuint16 at_0;
					zuint16 at_1;
					zuint16 at_2;
					zuint16 at_3;
#				else
					zuint16 at_3;
					zuint16 at_2;
					zuint16 at_1;
					zuint16 at_0;
#				endif
			} uint16_values;
#		endif

#		ifdef Z_SINT16
			zsint16 sint16_array[4];

			struct {
#				if Z_ISA_INTEGRAL_ENDIANNESS == Z_ENDIANNESS_LITTLE
					zsint16 at_0;
					zsint16 at_1;
					zsint16 at_2;
					zsint16 at_3;
#				else
					zsint16 at_3;
					zsint16 at_2;
					zsint16 at_1;
					zsint16 at_0;
#				endif
			} sint16_values;
#		endif

#		ifdef Z_UINT8
			zuint8 uint8_array[8];

			struct {
#				if Z_ISA_INTEGRAL_ENDIANNESS == Z_ENDIANNESS_LITTLE
					zuint8 at_0;
					zuint8 at_1;
					zuint8 at_2;
					zuint8 at_3;
					zuint8 at_4;
					zuint8 at_5;
					zuint8 at_6;
					zuint8 at_7;
#				elif Z_ISA_INTEGRAL_ENDIANNESS == Z_ENDIANNESS_BIG
					zuint8 at_7;
					zuint8 at_6;
					zuint8 at_5;
					zuint8 at_4;
					zuint8 at_3;
					zuint8 at_2;
					zuint8 at_1;
					zuint8 at_0;
#				else
					zuint8 at_6;
					zuint8 at_7;
					zuint8 at_4;
					zuint8 at_5;
					zuint8 at_2;
					zuint8 at_3;
					zuint8 at_0;
					zuint8 at_1;
#				endif
			} uint8_values;
#		endif

#		ifdef Z_SINT8
			zsint8 sint8_array[8];

			struct {
#				if Z_ISA_INTEGRAL_ENDIANNESS == Z_ENDIANNESS_LITTLE
					zsint8 at_0;
					zsint8 at_1;
					zsint8 at_2;
					zsint8 at_3;
					zsint8 at_4;
					zsint8 at_5;
					zsint8 at_6;
					zsint8 at_7;
#				elif Z_ISA_INTEGRAL_ENDIANNESS == Z_ENDIANNESS_BIG
					zsint8 at_7;
					zsint8 at_6;
					zsint8 at_5;
					zsint8 at_4;
					zsint8 at_3;
					zsint8 at_2;
					zsint8 at_1;
					zsint8 at_0;
#				else
					zsint8 at_6;
					zsint8 at_7;
					zsint8 at_4;
					zsint8 at_5;
					zsint8 at_2;
					zsint8 at_3;
					zsint8 at_0;
					zsint8 at_1;
#				endif
			} sint8_values;
#		endif
	} Z_PACKED_UNION_END ZInt64;
#endif

#if	defined(Z_UINT8	 ) || defined(Z_SINT8  ) || \
	defined(Z_UINT16 ) || defined(Z_SINT16 ) || \
	defined(Z_UINT32 ) || defined(Z_SINT32 ) || \
	defined(Z_UINT64 ) || defined(Z_SINT64 ) || \
	defined(Z_UINT128) || defined(Z_SINT128)

#	define Z_HAS_ZInt128 1

	typedef Z_PACKED_UNION_BEGIN {
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

			struct {
#				if Z_ISA_INTEGRAL_ENDIANNESS == Z_ENDIANNESS_LITTLE
					zuint64 at_0;
					zuint64 at_1;
#				else
					zuint64 at_1;
					zuint64 at_0;
#				endif
			} uint64_values;
#		endif

#		ifdef Z_SINT64
			zsint64 sint64_array[2];

			struct {
#				if Z_ISA_INTEGRAL_ENDIANNESS == Z_ENDIANNESS_LITTLE
					zsint64 at_0;
					zsint64 at_1;
#				else
					zsint64 at_1;
					zsint64 at_0;
#				endif
			} sint64_values;
#		endif

#		ifdef Z_UINT32
			zuint32 uint32_array[4];

			struct {
#				if Z_ISA_INTEGRAL_ENDIANNESS == Z_ENDIANNESS_LITTLE
					zuint32 at_0;
					zuint32 at_1;
					zuint32 at_2;
					zuint32 at_3;
#				else
					zuint32 at_3;
					zuint32 at_2;
					zuint32 at_1;
					zuint32 at_0;
#				endif
			} uint32_values;
#		endif

#		ifdef Z_SINT32
			zsint32 sint32_array[4];

			struct {
#				if Z_ISA_INTEGRAL_ENDIANNESS == Z_ENDIANNESS_LITTLE
					zsint32 at_0;
					zsint32 at_1;
					zsint32 at_2;
					zsint32 at_3;
#				else
					zsint32 at_3;
					zsint32 at_2;
					zsint32 at_1;
					zsint32 at_0;
#				endif
			} sint32_values;
#		endif

#		ifdef Z_UINT16
			zuint16 uint16_array[8];

			struct {
#				if Z_ISA_INTEGRAL_ENDIANNESS == Z_ENDIANNESS_LITTLE
					zuint16 at_0;
					zuint16 at_1;
					zuint16 at_2;
					zuint16 at_3;
					zuint16 at_4;
					zuint16 at_5;
					zuint16 at_6;
					zuint16 at_7;
#				else
					zuint16 at_7;
					zuint16 at_6;
					zuint16 at_5;
					zuint16 at_4;
					zuint16 at_3;
					zuint16 at_2;
					zuint16 at_1;
					zuint16 at_0;
#				endif
			} uint16_values;
#		endif

#		ifdef Z_SINT16
			zsint16 sint16_array[8];

			struct {
#				if Z_ISA_INTEGRAL_ENDIANNESS == Z_ENDIANNESS_LITTLE
					zsint16 at_0;
					zsint16 at_1;
					zsint16 at_2;
					zsint16 at_3;
					zsint16 at_4;
					zsint16 at_5;
					zsint16 at_6;
					zsint16 at_7;
#				else
					zsint16 at_7;
					zsint16 at_6;
					zsint16 at_5;
					zsint16 at_4;
					zsint16 at_3;
					zsint16 at_2;
					zsint16 at_1;
					zsint16 at_0;
#				endif
			} sint16_values;
#		endif

#		ifdef Z_UINT8
			zuint8 uint8_array[16];

			struct {
#				if Z_ISA_INTEGRAL_ENDIANNESS == Z_ENDIANNESS_LITTLE
					zuint8 at_0;
					zuint8 at_1;
					zuint8 at_2;
					zuint8 at_3;
					zuint8 at_4;
					zuint8 at_5;
					zuint8 at_6;
					zuint8 at_7;
					zuint8 at_8;
					zuint8 at_9;
					zuint8 at_10;
					zuint8 at_11;
					zuint8 at_12;
					zuint8 at_13;
					zuint8 at_14;
					zuint8 at_15;
#				elif Z_ISA_INTEGRAL_ENDIANNESS == Z_ENDIANNESS_BIG
					zuint8 at_15;
					zuint8 at_14;
					zuint8 at_13;
					zuint8 at_12;
					zuint8 at_11;
					zuint8 at_10;
					zuint8 at_9;
					zuint8 at_8;
					zuint8 at_7;
					zuint8 at_6;
					zuint8 at_5;
					zuint8 at_4;
					zuint8 at_3;
					zuint8 at_2;
					zuint8 at_1;
					zuint8 at_0;
#				else
					zuint8 at_14;
					zuint8 at_15;
					zuint8 at_12;
					zuint8 at_13;
					zuint8 at_10;
					zuint8 at_11;
					zuint8 at_8;
					zuint8 at_9;
					zuint8 at_6;
					zuint8 at_7;
					zuint8 at_4;
					zuint8 at_5;
					zuint8 at_2;
					zuint8 at_3;
					zuint8 at_0;
					zuint8 at_1;
#				endif
			} uint8_values;
#		endif

#		ifdef Z_SINT8
			zsint8 sint8_array[16];

			struct {
#				if Z_ISA_INTEGRAL_ENDIANNESS == Z_ENDIANNESS_LITTLE
					zsint8 at_0;
					zsint8 at_1;
					zsint8 at_2;
					zsint8 at_3;
					zsint8 at_4;
					zsint8 at_5;
					zsint8 at_6;
					zsint8 at_7;
					zsint8 at_8;
					zsint8 at_9;
					zsint8 at_10;
					zsint8 at_11;
					zsint8 at_12;
					zsint8 at_13;
					zsint8 at_14;
					zsint8 at_15;
#				elif Z_ISA_INTEGRAL_ENDIANNESS == Z_ENDIANNESS_BIG
					zsint8 at_15;
					zsint8 at_14;
					zsint8 at_13;
					zsint8 at_12;
					zsint8 at_11;
					zsint8 at_10;
					zsint8 at_9;
					zsint8 at_8;
					zsint8 at_7;
					zsint8 at_6;
					zsint8 at_5;
					zsint8 at_4;
					zsint8 at_3;
					zsint8 at_2;
					zsint8 at_1;
					zsint8 at_0;
#				else
					zsint8 at_14;
					zsint8 at_15;
					zsint8 at_12;
					zsint8 at_13;
					zsint8 at_10;
					zsint8 at_11;
					zsint8 at_8;
					zsint8 at_9;
					zsint8 at_6;
					zsint8 at_7;
					zsint8 at_4;
					zsint8 at_5;
					zsint8 at_2;
					zsint8 at_3;
					zsint8 at_0;
					zsint8 at_1;
#				endif
			} sint8_values;
#		endif
	} Z_PACKED_UNION_END ZInt128;
#endif

#endif /* Z_types_bitwise_H */
