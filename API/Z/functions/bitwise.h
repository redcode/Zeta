/* Z Kit - functions/bitwise.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//__/__| Kit
Copyright (C) 2006-2020 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_functions_bitwise_H
#define Z_functions_bitwise_H

#include <Z/macros/bitwise.h>


#define Z_IMPLEMENTATION__REVERSE(type, bits, level)	      \
							      \
static Z_INLINE						      \
z##type z_##type##_reverse_in_##level##bit(z##type value)     \
	{						      \
	return (z##type)Z_##bits##BIT_REVERSE_IN_##level##BIT \
		((zuint##bits)value);			      \
	}


#define Z_IMPLEMENTATION__ROTATE(type, bits)		       \
							       \
static Z_INLINE						       \
z##type z_##type##_rotate_left(z##type value, zuint rotation)  \
	{						       \
	return (z##type)Z_##bits##BIT_ROTATE_LEFT	       \
		((zuint##bits)value, rotation);		       \
	}						       \
							       \
							       \
static Z_INLINE						       \
z##type z_##type##_rotate_right(z##type value, zuint rotation) \
	{						       \
	return (z##type)Z_##bits##BIT_ROTATE_RIGHT	       \
		((zuint##bits)value, rotation);		       \
	}


Z_IMPLEMENTATION__REVERSE(uint8, 8, 1)
Z_IMPLEMENTATION__REVERSE(uint8, 8, 2)
Z_IMPLEMENTATION__REVERSE(uint8, 8, 4)
Z_IMPLEMENTATION__ROTATE (uint8, 8)

#define z_uint8_reverse Z_SAME

Z_IMPLEMENTATION__REVERSE(sint8, 8, 1)
Z_IMPLEMENTATION__REVERSE(sint8, 8, 2)
Z_IMPLEMENTATION__REVERSE(sint8, 8, 4)
Z_IMPLEMENTATION__ROTATE (sint8, 8)

#define z_sint8_reverse Z_SAME

Z_IMPLEMENTATION__REVERSE(uint16, 16, 1)
Z_IMPLEMENTATION__REVERSE(uint16, 16, 2)
Z_IMPLEMENTATION__REVERSE(uint16, 16, 4)
Z_IMPLEMENTATION__REVERSE(uint16, 16, 8)
Z_IMPLEMENTATION__ROTATE (uint16, 16)

#define z_uint16_reverse z_uint16_reverse_in_8bit

#if Z_UINT16_ENDIANNESS == Z_ENDIANNESS_BIG

#	define z_uint16_big_endian    Z_SAME
#	define z_uint16_little_endian z_uint16_reverse

#elif Z_UINT16_ENDIANNESS == Z_ENDIANNESS_LITTLE

#	define z_uint16_big_endian    z_uint16_reverse
#	define z_uint16_little_endian Z_SAME

#endif

Z_IMPLEMENTATION__REVERSE(sint16, 16, 1)
Z_IMPLEMENTATION__REVERSE(sint16, 16, 2)
Z_IMPLEMENTATION__REVERSE(sint16, 16, 4)
Z_IMPLEMENTATION__REVERSE(sint16, 16, 8)
Z_IMPLEMENTATION__ROTATE (sint16, 16)

#define z_sint16_reverse z_sint16_reverse_in_8bit

#if Z_SINT16_ENDIANNESS == Z_ENDIANNESS_BIG

#	define z_sint16_big_endian    Z_SAME
#	define z_sint16_little_endian z_sint16_reverse

#elif Z_SINT16_ENDIANNESS == Z_ENDIANNESS_LITTLE

#	define z_sint16_big_endian    z_sint16_reverse
#	define z_sint16_little_endian Z_SAME

#endif

Z_IMPLEMENTATION__REVERSE(uint32, 32,  1)
Z_IMPLEMENTATION__REVERSE(uint32, 32,  2)
Z_IMPLEMENTATION__REVERSE(uint32, 32,  4)
Z_IMPLEMENTATION__REVERSE(uint32, 32,  8)
Z_IMPLEMENTATION__REVERSE(uint32, 32, 16)
Z_IMPLEMENTATION__ROTATE (uint32, 32)

#define z_uint32_reverse z_uint32_reverse_in_8bit

#if Z_UINT32_ENDIANNESS == Z_ENDIANNESS_BIG

#	define z_uint32_big_endian    Z_SAME
#	define z_uint32_little_endian z_uint32_reverse

#elif Z_UINT32_ENDIANNESS == Z_ENDIANNESS_LITTLE

#	define z_uint32_big_endian    z_uint32_reverse
#	define z_uint32_little_endian Z_SAME

#endif

Z_IMPLEMENTATION__REVERSE(sint32, 32,  1)
Z_IMPLEMENTATION__REVERSE(sint32, 32,  2)
Z_IMPLEMENTATION__REVERSE(sint32, 32,  4)
Z_IMPLEMENTATION__REVERSE(sint32, 32,  8)
Z_IMPLEMENTATION__REVERSE(sint32, 32, 16)
Z_IMPLEMENTATION__ROTATE (sint32, 32)

#define z_sint32_reverse z_sint32_reverse_in_8bit

#if Z_SINT32_ENDIANNESS == Z_ENDIANNESS_BIG

#	define z_sint32_big_endian    Z_SAME
#	define z_sint32_little_endian z_sint32_reverse

#elif Z_SINT32_ENDIANNESS == Z_ENDIANNESS_LITTLE

#	define z_sint32_big_endian    z_sint32_reverse
#	define z_sint32_little_endian Z_SAME

#endif

#ifdef Z_UINT64

	Z_IMPLEMENTATION__REVERSE(uint64, 64,  1)
	Z_IMPLEMENTATION__REVERSE(uint64, 64,  2)
	Z_IMPLEMENTATION__REVERSE(uint64, 64,  4)
	Z_IMPLEMENTATION__REVERSE(uint64, 64,  8)
	Z_IMPLEMENTATION__REVERSE(uint64, 64, 16)
	Z_IMPLEMENTATION__REVERSE(uint64, 64, 32)
	Z_IMPLEMENTATION__ROTATE (uint64, 64)

#	define z_uint64_reverse z_uint64_reverse_in_8bit

#	if Z_UINT64_ENDIANNESS == Z_ENDIANNESS_BIG

#		define z_uint64_big_endian    Z_SAME
#		define z_uint64_little_endian z_uint64_reverse

#	elif Z_UINT64_ENDIANNESS == Z_ENDIANNESS_LITTLE

#		define z_uint64_big_endian    z_uint64_reverse
#		define z_uint64_little_endian Z_SAME

#	endif

#endif

#ifdef Z_SINT64

	Z_IMPLEMENTATION__REVERSE(sint64, 64,  1)
	Z_IMPLEMENTATION__REVERSE(sint64, 64,  2)
	Z_IMPLEMENTATION__REVERSE(sint64, 64,  4)
	Z_IMPLEMENTATION__REVERSE(sint64, 64,  8)
	Z_IMPLEMENTATION__REVERSE(sint64, 64, 16)
	Z_IMPLEMENTATION__REVERSE(sint64, 64, 32)
	Z_IMPLEMENTATION__ROTATE (sint64, 64)

#	define z_sint64_reverse z_sint64_reverse_in_8bit

#	if Z_SINT64_ENDIANNESS == Z_ENDIANNESS_BIG

#		define z_sint64_big_endian    Z_SAME
#		define z_sint64_little_endian z_sint64_reverse

#	elif Z_SINT64_ENDIANNESS == Z_ENDIANNESS_LITTLE

#		define z_sint64_big_endian    z_sint64_reverse
#		define z_sint64_little_endian Z_SAME

#	endif

#endif

#ifdef Z_UINT128

	Z_IMPLEMENTATION__REVERSE(uint128, 128,  1)
	Z_IMPLEMENTATION__REVERSE(uint128, 128,  2)
	Z_IMPLEMENTATION__REVERSE(uint128, 128,  4)
	Z_IMPLEMENTATION__REVERSE(uint128, 128,  8)
	Z_IMPLEMENTATION__REVERSE(uint128, 128, 16)
	Z_IMPLEMENTATION__REVERSE(uint128, 128, 32)
	Z_IMPLEMENTATION__REVERSE(uint128, 128, 64)
	Z_IMPLEMENTATION__ROTATE (uint128, 128)


#	define z_uint128_reverse z_uint128_reverse_in_8bit

#	if Z_UINT128_ENDIANNESS == Z_ENDIANNESS_BIG

#		define z_uint128_big_endian    Z_SAME
#		define z_uint128_little_endian z_uint128_reverse

#	elif Z_UINT128_ENDIANNESS == Z_ENDIANNESS_LITTLE

#		define z_uint128_big_endian    z_uint128_reverse
#		define z_uint128_little_endian Z_SAME

#	endif

#endif

#ifdef Z_SINT128

	Z_IMPLEMENTATION__REVERSE(sint128, 128,  1)
	Z_IMPLEMENTATION__REVERSE(sint128, 128,  2)
	Z_IMPLEMENTATION__REVERSE(sint128, 128,  4)
	Z_IMPLEMENTATION__REVERSE(sint128, 128,  8)
	Z_IMPLEMENTATION__REVERSE(sint128, 128, 16)
	Z_IMPLEMENTATION__REVERSE(sint128, 128, 32)
	Z_IMPLEMENTATION__REVERSE(sint128, 128, 64)
	Z_IMPLEMENTATION__ROTATE (sint128, 128)

#	define z_sint128_reverse z_sint128_reverse_in_8bit

#	if Z_SINT128_ENDIANNESS == Z_ENDIANNESS_BIG

#		define z_sint128_big_endian    Z_SAME
#		define z_sint128_little_endian z_sint128_reverse

#	elif Z_SINT128_ENDIANNESS == Z_ENDIANNESS_LITTLE

#		define z_sint128_big_endian    z_sint128_reverse
#		define z_sint128_little_endian Z_SAME

#	endif

#endif

#undef Z_IMPLEMENTATION__REVERSE
#undef Z_IMPLEMENTATION__ROTATE

#define z_type_reverse(		    TYPE) Z_INSERT_fixed_type(Z_##TYPE)(z_, _reverse_in_8bit	 )
#define z_type_rotate_left(	    TYPE) Z_INSERT_fixed_type(Z_##TYPE)(z_, _rotate_left	 )
#define z_type_rotate_right(	    TYPE) Z_INSERT_fixed_type(Z_##TYPE)(z_, _rotate_right	 )
#define z_type_big_endian(	    TYPE) Z_INSERT_fixed_type(Z_##TYPE)(z_, _big_endian		 )
#define z_type_little_endian(	    TYPE) Z_INSERT_fixed_type(Z_##TYPE)(z_, _little_endian	 )
#define z_type_minimum_storage_size(TYPE) Z_INSERT_fixed_type(Z_##TYPE)(z_, _minimum_storage_size)


#endif /* Z_functions_bitwise_H */
