/* Zeta API - Z/functions/bitwise.h
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_functions_bitwise_H
#define Z_functions_bitwise_H

#include <Z/macros/bitwise.h>
#include <Z/macros/language.h>


#define Z_z_NATURAL_FLIP(type, TYPE, chunk_bits)	    \
							    \
	static Z_INLINE					    \
	z##type z_##type##_flip_##chunk_bits(z##type value) \
		{return Z_##TYPE##_FLIP_##chunk_bits(value);}


#define Z_z_NATURAL_REVERSE(type, TYPE, chunk_bits)	       \
							       \
	static Z_INLINE					       \
	z##type z_##type##_reverse_##chunk_bits(z##type value) \
		{return Z_##TYPE##_REVERSE_##chunk_bits(value);}


#define Z_z_NATURAL_ROTATE(type, TYPE)				       \
								       \
	static Z_INLINE						       \
	z##type z_##type##_rotate_left(z##type value, zuint rotation)  \
		{return Z_##TYPE##_ROTATE_LEFT(value, rotation);}      \
								       \
								       \
	static Z_INLINE						       \
	z##type z_##type##_rotate_right(z##type value, zuint rotation) \
		{return Z_##TYPE##_ROTATE_RIGHT(value, rotation);}


#ifdef Z_UINT8
	Z_z_NATURAL_REVERSE(uint8, UINT8, 4)
	Z_z_NATURAL_ROTATE (uint8, UINT8)

#	define z_uint8_reverse	     Z_SAME
#	define z_uint8_little_endian Z_SAME
#	define z_uint8_big_endian    Z_SAME
#	define z_uint8_pdp_endian    Z_SAME
#endif

#ifdef Z_UINT16
	Z_z_NATURAL_REVERSE(uint16, UINT16, 8)
	Z_z_NATURAL_ROTATE (uint16, UINT16)

#	if Z_ISA_INTEGRAL_ENDIANNESS != Z_ENDIANNESS_BIG
#		define z_uint16_little_endian Z_SAME
#		define z_uint16_big_endian    z_uint16_reverse_8
#		define z_uint16_pdp_endian    Z_SAME
#	else
#		define z_uint16_little_endian z_uint16_reverse_8
#		define z_uint16_big_endian    Z_SAME
#		define z_uint16_pdp_endian    z_uint16_reverse_8
#	endif
#endif

#ifdef Z_UINT32
	Z_z_NATURAL_FLIP   (uint32, UINT32,  8)
	Z_z_NATURAL_REVERSE(uint32, UINT32,  8)
	Z_z_NATURAL_REVERSE(uint32, UINT32, 16)
	Z_z_NATURAL_ROTATE (uint32, UINT32)

#	if Z_ISA_INTEGRAL_ENDIANNESS == Z_ENDIANNESS_LITTLE
#		define z_uint32_little_endian Z_SAME
#		define z_uint32_big_endian    z_uint32_reverse_8
#		define z_uint32_pdp_endian    z_uint32_reverse_16
#	elif Z_ISA_INTEGRAL_ENDIANNESS == Z_ENDIANNESS_BIG
#		define z_uint32_little_endian z_uint32_reverse_8
#		define z_uint32_big_endian    Z_SAME
#		define z_uint32_pdp_endian    z_uint32_flip_8
#	else
#		define z_uint32_little_endian z_uint32_reverse_16
#		define z_uint32_big_endian    z_uint32_flip_8
#		define z_uint32_pdp_endian    Z_SAME
#	endif
#endif

#ifdef Z_UINT64
	Z_z_NATURAL_FLIP   (uint64, UINT64,  8)
	Z_z_NATURAL_REVERSE(uint64, UINT64,  8)
	Z_z_NATURAL_REVERSE(uint64, UINT64, 16)
	Z_z_NATURAL_REVERSE(uint64, UINT64, 32)
	Z_z_NATURAL_ROTATE (uint64, UINT64)

#	if Z_ISA_INTEGRAL_ENDIANNESS == Z_ENDIANNESS_LITTLE
#		define z_uint64_little_endian Z_SAME
#		define z_uint64_big_endian    z_uint64_reverse_8
#		define z_uint64_pdp_endian    z_uint64_reverse_16
#	elif Z_ISA_INTEGRAL_ENDIANNESS == Z_ENDIANNESS_BIG
#		define z_uint64_little_endian z_uint64_reverse_8
#		define z_uint64_big_endian    Z_SAME
#		define z_uint64_pdp_endian    z_uint64_flip_8
#	else
#		define z_uint64_little_endian z_uint64_reverse_16
#		define z_uint64_big_endian    z_uint64_flip_8
#		define z_uint64_pdp_endian    Z_SAME
#	endif
#endif

#ifdef Z_UINT128
	Z_z_NATURAL_FLIP   (uint128, UINT128,  8)
	Z_z_NATURAL_REVERSE(uint128, UINT128,  8)
	Z_z_NATURAL_REVERSE(uint128, UINT128, 16)
	Z_z_NATURAL_REVERSE(uint128, UINT128, 32)
	Z_z_NATURAL_REVERSE(uint128, UINT128, 64)
	Z_z_NATURAL_ROTATE (uint128, UINT128)

#	if Z_ISA_INTEGRAL_ENDIANNESS == Z_ENDIANNESS_LITTLE
#		define z_uint128_little_endian Z_SAME
#		define z_uint128_big_endian    z_uint128_reverse_8
#		define z_uint128_pdp_endian    z_uint128_reverse_16

#	elif Z_ISA_INTEGRAL_ENDIANNESS == Z_ENDIANNESS_BIG
#		define z_uint128_little_endian z_uint128_reverse_8
#		define z_uint128_big_endian    Z_SAME
#		define z_uint128_pdp_endian    z_uint128_flip_8
#	else
#		define z_uint128_little_endian z_uint128_reverse_16
#		define z_uint128_big_endian    z_uint128_flip_8
#		define z_uint128_pdp_endian    Z_SAME
#	endif
#endif

#undef Z_z_NATURAL_FLIP
#undef Z_z_NATURAL_REVERSE
#undef Z_z_NATURAL_ROTATE

#define z_T_little_endian(T) Z_INSERT_type(Z_##T##_FIXED_FUNDAMENTAL)(z_, _little_endian)
#define z_T_big_endian(	  T) Z_INSERT_type(Z_##T##_FIXED_FUNDAMENTAL)(z_, _big_endian	)
#define z_T_pdp_endian(	  T) Z_INSERT_type(Z_##T##_FIXED_FUNDAMENTAL)(z_, _pdp_endian	)
#define z_T_rotate_left(  T) Z_INSERT_type(Z_##T##_FIXED_FUNDAMENTAL)(z_, _rotate_left	)
#define z_T_rotate_right( T) Z_INSERT_type(Z_##T##_FIXED_FUNDAMENTAL)(z_, _rotate_right )

#endif /* Z_functions_bitwise_H */
