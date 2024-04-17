/* Zeta API - Z/macros/bitwise.h
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_macros_bitwise_H
#define Z_macros_bitwise_H

#include <Z/inspection/ISA.h>
#include <Z/types/integral.h>
#include <Z/macros/casting.h>

/* MARK: - 8-bit operations */

#define Z_UINT8_REVERSE_4(value) \
	(Z_CAST(zuint8)(((value) << 4) | ((value) >> 4)))

#define Z_UINT8_ROTATE_LEFT(value, rotation) \
	(Z_CAST(zuint8)(((value) << (rotation)) | ((value) >> (8 - (rotation)))))

#define Z_UINT8_ROTATE_RIGHT(value, rotation) \
	(Z_CAST(zuint8)(((value) >> (rotation)) | ((value) << (8 - (rotation)))))

#define Z_UINT8_LITTLE_ENDIAN Z_SAME
#define Z_UINT8_BIG_ENDIAN    Z_SAME
#define Z_UINT8_PDP_ENDIAN    Z_SAME

/* MARK: - 16-bit operations */

#define Z_UINT16_REVERSE_8(value) \
	(Z_CAST(zuint16)(((value) << 8) | ((value) >> 8)))

#define Z_UINT16_ROTATE_LEFT(value, rotation) \
	(Z_CAST(zuint16)(((value) << (rotation)) | ((value) >> (16 - (rotation)))))

#define Z_UINT16_ROTATE_RIGHT(value, rotation) \
	(Z_CAST(zuint16)(((value) >> (rotation)) | ((value) << (16 - (rotation)))))

#if Z_ISA_INTEGRAL_ENDIANNESS != Z_ENDIANNESS_BIG
#	define Z_UINT16_LITTLE_ENDIAN Z_SAME
#	define Z_UINT16_BIG_ENDIAN    Z_UINT16_REVERSE_8
#	define Z_UINT16_PDP_ENDIAN    Z_SAME
#else
#	define Z_UINT16_LITTLE_ENDIAN Z_UINT16_REVERSE_8
#	define Z_UINT16_BIG_ENDIAN    Z_SAME
#	define Z_UINT16_PDP_ENDIAN    Z_UINT16_REVERSE_8
#endif

/* MARK: - 32-bit operations */

#define Z_UINT32_FLIP_8(value) (Z_CAST(zuint32)( \
	((value << 8) & Z_UINT32(0xFF00FF00)) |	 \
	((value >> 8) & Z_UINT32(0x00FF00FF))))

#define Z_UINT32_REVERSE_8(value)			   \
	(Z_CAST(zuint32)(				   \
	(((value) << 24)			       ) | \
	(((value) >> 24)			       ) | \
	(((value) <<  8) & (Z_CAST(zuint32)(255) << 16)) | \
	(((value) >>  8) & (Z_CAST(zuint32)(255) <<  8))))

#define Z_UINT32_REVERSE_16(value) \
	(Z_CAST(zuint32)(((value) << 16) | ((value) >> 16)))

#define Z_UINT32_ROTATE_LEFT(value, rotation) \
	(Z_CAST(zuint32)(((value) << (rotation)) | ((value) >> (32 - (rotation)))))

#define Z_UINT32_ROTATE_RIGHT(value, rotation) \
	(Z_CAST(zuint32)(((value) >> (rotation)) | ((value) << (32 - (rotation)))))

#if Z_ISA_INTEGRAL_ENDIANNESS == Z_ENDIANNESS_LITTLE
#	define Z_UINT32_LITTLE_ENDIAN Z_SAME
#	define Z_UINT32_BIG_ENDIAN    Z_UINT32_REVERSE_8
#	define Z_UINT32_PDP_ENDIAN    Z_UINT32_REVERSE_16
#elif Z_ISA_INTEGRAL_ENDIANNESS == Z_ENDIANNESS_BIG
#	define Z_UINT32_LITTLE_ENDIAN Z_UINT32_REVERSE_8
#	define Z_UINT32_BIG_ENDIAN    Z_SAME
#	define Z_UINT32_PDP_ENDIAN    Z_UINT32_FLIP_8
#else
#	define Z_UINT32_LITTLE_ENDIAN Z_UINT32_REVERSE_16
#	define Z_UINT32_BIG_ENDIAN    Z_UINT32_FLIP_8
#	define Z_UINT32_PDP_ENDIAN    Z_SAME
#endif

/* MARK: - 64-bit operations */

#ifdef Z_UINT64

#	define Z_UINT64_FLIP_8(value) (Z_CAST(zuint64)(		\
		((value << 8) & Z_UINT64(0xFF00FF00FF00FF00)) | \
		((value >> 8) & Z_UINT64(0x00FF00FF00FF00FF))))

#	define Z_UINT64_REVERSE_8(value) (Z_CAST(zuint64)(	   \
		(((value) << 56)			       ) | \
		(((value) >> 56)			       ) | \
		(((value) << 40) & (Z_CAST(zuint64)(255) << 48)) | \
		(((value) >> 40) & (Z_CAST(zuint64)(255) <<  8)) | \
		(((value) << 24) & (Z_CAST(zuint64)(255) << 40)) | \
		(((value) >> 24) & (Z_CAST(zuint64)(255) << 16)) | \
		(((value) <<  8) & (Z_CAST(zuint64)(255) << 32)) | \
		(((value) >>  8) & (Z_CAST(zuint64)(255) << 24))))

#	define Z_UINT64_REVERSE_16(value) (Z_CAST(zuint64)(	      \
		(((value) << 48)				  ) | \
		(((value) >> 48)				  ) | \
		(((value) << 16) & (Z_CAST(zuint64)(65535U) << 32)) | \
		(((value) >> 16) & (Z_CAST(zuint64)(65535U) << 16))))

#	define Z_UINT64_REVERSE_32(value) \
		(Z_CAST(zuint64)(((value) << 32) | ((value) >> 32)))

#	define Z_UINT64_ROTATE_LEFT(value, rotation) \
		(Z_CAST(zuint64)(((value) << (rotation)) | ((value) >> (64 - (rotation)))))

#	define Z_UINT64_ROTATE_RIGHT(value, rotation) \
		(Z_CAST(zuint64)(((value) >> (rotation)) | ((value) << (64 - (rotation)))))

#	if Z_ISA_INTEGRAL_ENDIANNESS == Z_ENDIANNESS_LITTLE
#		define Z_UINT64_LITTLE_ENDIAN Z_SAME
#		define Z_UINT64_BIG_ENDIAN    Z_UINT64_REVERSE_8
#		define Z_UINT64_PDP_ENDIAN    Z_UINT64_REVERSE_16
#	elif Z_ISA_INTEGRAL_ENDIANNESS == Z_ENDIANNESS_BIG
#		define Z_UINT64_LITTLE_ENDIAN Z_UINT64_REVERSE_8
#		define Z_UINT64_BIG_ENDIAN    Z_SAME
#		define Z_UINT64_PDP_ENDIAN    Z_UINT64_FLIP_8
#	else
#		define Z_UINT64_LITTLE_ENDIAN Z_UINT64_REVERSE_16
#		define Z_UINT64_BIG_ENDIAN    Z_UINT64_FLIP_8
#		define Z_UINT64_PDP_ENDIAN    Z_SAME
#	endif

#endif

/* MARK: - 128-bit operations */

#ifdef Z_UINT128

#	define Z_UINT128_FLIP_8(value) (Z_CAST(zuint128)(  \
		((value << 8) & (			   \
			(Z_CAST(zuint128)(255) << 120) |   \
			(Z_CAST(zuint128)(255) << 104) |   \
			(Z_CAST(zuint128)(255) <<  88) |   \
			(Z_CAST(zuint128)(255) <<  72) |   \
			(Z_CAST(zuint128)(255) <<  56) |   \
			(Z_CAST(zuint128)(255) <<  40) |   \
			(Z_CAST(zuint128)(255) <<  24) |   \
			(Z_CAST(zuint128)(255) <<   8))) | \
		((value >> 8) & (			   \
			(Z_CAST(zuint128)(255) << 112) |   \
			(Z_CAST(zuint128)(255) <<  96) |   \
			(Z_CAST(zuint128)(255) <<  80) |   \
			(Z_CAST(zuint128)(255) <<  64) |   \
			(Z_CAST(zuint128)(255) <<  48) |   \
			(Z_CAST(zuint128)(255) <<  32) |   \
			(Z_CAST(zuint128)(255) <<  16) |   \
			(Z_CAST(zuint128)(255))))))

#	define Z_UINT128_REVERSE_8(value) (Z_CAST(zuint128)(	      \
		(((value) << 120)				  ) | \
		(((value) >> 120)				  ) | \
		(((value) << 104) & (Z_CAST(zuint128)(255) << 112)) | \
		(((value) >> 104) & (Z_CAST(zuint128)(255) <<	8)) | \
		(((value) <<  88) & (Z_CAST(zuint128)(255) << 104)) | \
		(((value) >>  88) & (Z_CAST(zuint128)(255) <<  16)) | \
		(((value) <<  72) & (Z_CAST(zuint128)(255) <<  96)) | \
		(((value) >>  72) & (Z_CAST(zuint128)(255) <<  24)) | \
		(((value) <<  56) & (Z_CAST(zuint128)(255) <<  88)) | \
		(((value) >>  56) & (Z_CAST(zuint128)(255) <<  32)) | \
		(((value) <<  40) & (Z_CAST(zuint128)(255) <<  80)) | \
		(((value) >>  40) & (Z_CAST(zuint128)(255) <<  40)) | \
		(((value) <<  24) & (Z_CAST(zuint128)(255) <<  72)) | \
		(((value) >>  24) & (Z_CAST(zuint128)(255) <<  48)) | \
		(((value) <<   8) & (Z_CAST(zuint128)(255) <<  64)) | \
		(((value) >>   8) & (Z_CAST(zuint128)(255) <<  56))))

#	define Z_UINT128_REVERSE_16(value) (Z_CAST(zuint128)(		\
		(((value) << 112)				    ) | \
		(((value) >> 112)				    ) | \
		(((value) <<  80) & (Z_CAST(zuint128)(65535U) << 96)) | \
		(((value) >>  80) & (Z_CAST(zuint128)(65535U) << 16)) | \
		(((value) <<  48) & (Z_CAST(zuint128)(65535U) << 80)) | \
		(((value) >>  48) & (Z_CAST(zuint128)(65535U) << 32)) | \
		(((value) <<  16) & (Z_CAST(zuint128)(65535U) << 64)) | \
		(((value) >>  16) & (Z_CAST(zuint128)(65535U) << 48))))

#	define Z_UINT128_REVERSE_32(value) (Z_CAST(zuint128)(		   \
		(((value) << 96)				       ) | \
		(((value) >> 96)				       ) | \
		(((value) << 32) & (Z_CAST(zuint128)(4294967295) << 64)) | \
		(((value) >> 32) & (Z_CAST(zuint128)(4294967295) << 32))))

#	define Z_UINT128_REVERSE_64(value) \
		(Z_CAST(zuint128)(((value) << 64) | ((value) >> 64)))

#	define Z_UINT128_ROTATE_LEFT(value, rotation) \
		(Z_CAST(zuint128)(((value) << (rotation)) | ((value) >> (128 - (rotation)))))

#	define Z_UINT128_ROTATE_RIGHT(value, rotation) \
		(Z_CAST(zuint128)(((value) >> (rotation)) | ((value) << (128 - (rotation)))))


#	if Z_ISA_INTEGRAL_ENDIANNESS == Z_ENDIANNESS_LITTLE
#		define Z_UINT128_LITTLE_ENDIAN Z_SAME
#		define Z_UINT128_BIG_ENDIAN    Z_UINT128_REVERSE_8
#		define Z_UINT128_PDP_ENDIAN    Z_UINT128_REVERSE_16

#	elif Z_ISA_INTEGRAL_ENDIANNESS == Z_ENDIANNESS_BIG
#		define Z_UINT128_LITTLE_ENDIAN Z_UINT128_REVERSE_8
#		define Z_UINT128_BIG_ENDIAN    Z_SAME
#		define Z_UINT128_PDP_ENDIAN    Z_UINT128_FLIP_8
#	else
#		define Z_UINT128_LITTLE_ENDIAN Z_UINT128_REVERSE_16
#		define Z_UINT128_BIG_ENDIAN    Z_UINT128_FLIP_8
#		define Z_UINT128_PDP_ENDIAN    Z_SAME
#	endif

#endif

/* MARK: - Macro selectors */

#define Z_T_REVERSE(T)				  \
	Z_JOIN_2(Z_APPEND_NUMBER_, Z_CHAR_WIDTH)( \
		Z_INSERT_TYPE(Z_##T##_FIXED_FUNDAMENTAL)(Z_, _REVERSE_))

#define Z_T_BIG_ENDIAN(T) \
	Z_INSERT_TYPE(Z_##T##_FIXED_FUNDAMENTAL)(Z_, _BIG_ENDIAN)

#define Z_T_LITTLE_ENDIAN(T) \
	Z_INSERT_TYPE(Z_##T##_FIXED_FUNDAMENTAL)(Z_, _LITTLE_ENDIAN)

#endif /* Z_macros_bitwise_H */
