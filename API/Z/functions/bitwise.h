/* Zeta API - Z/functions/bitwise.h
 ______ ____________  ___
|__   /|  ___|__  __|/   \
  /  /_|  __|  |  | /  *  \
 /_____|_____| |__|/__/ \__\
Copyright (C) 2006-2022 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_functions_bitwise_H
#define Z_functions_bitwise_H

#include <Z/macros/bitwise.h>
#include <Z/macros/language.h>

/*

static Z_INLINE
zuint32 z_uint32_alter_bits(zuint32 value, zuint32 mask, zboolean bit)
	{return value ^ ((Z_CAST(zuint32)(-Z_CAST(zsint32)(bit)) ^ value) & mask);}



static Z_INLINE
zuint32 z_uint32_alter_bits(zuint32 value, zuint32 mask, zboolean bit)
	{return (value & ~mask) | (Z_CAST(zuint32)(-Z_CAST(zsint32)(bit)) & mask);}
*/


#define Z__NATURAL_EXTRACT(bits)							\
											\
	static Z_INLINE									\
	zuint##bits z_uint##bits##_extract(zuint##bits value, zuint offset, zuint size) \
		{return (value >> offset) & (Z_UINT##bits##_MAXIMUM << offset);}


#define Z__INTEGER_EXTRACT(bits)									       \
													       \
	static Z_INLINE											       \
	zsint##bits z_sint##bits##_extract(zuint##bits value, zuint offset, zuint size)			       \
		{											       \
		zuint##bits mask = Z_UINT##bits(1) << (size - 1U);					       \
													       \
		return Z_CAST(zsint##bits)								       \
			((((value >> offset) & ((Z_UINT##bits(1) << size) - Z_UINT##bits(1))) ^ mask) - mask); \
		}


#define Z__NATURAL_REVERSE(bits)				\
								\
	static Z_INLINE						\
	zuint##bits z_uint##bits##_reverse(zuint##bits value)	\
		{						\
		return	Z_JOIN_2(Z_INSERT_NUMBER_, Z_CHAR_BITS)	\
			(Z_UINT##bits##_REVERSE_IN_, BIT)	\
				(value);			\
		}


#define Z__NATURAL_ROTATE(bits)							   \
										   \
	static Z_INLINE								   \
	zuint##bits z_uint##bits##_rotate_left(zuint##bits value, zuint rotation)  \
		{return Z_UINT##bits##_ROTATE_LEFT(value, rotation);}		   \
										   \
										   \
	static Z_INLINE								   \
	zuint##bits z_uint##bits##_rotate_right(zuint##bits value, zuint rotation) \
		{return Z_UINT##bits##_ROTATE_RIGHT(value, rotation);}


#ifdef Z_UINT8
	Z__NATURAL_EXTRACT(8)
	Z__NATURAL_ROTATE (8)

#	define z_uint8_reverse Z_SAME
#endif

#ifdef Z_SINT8
	Z__INTEGER_EXTRACT(8)
#endif

#ifdef Z_UINT16
	Z__NATURAL_EXTRACT(16)
	Z__NATURAL_REVERSE(16)
	Z__NATURAL_ROTATE (16)

#	if Z_ISA_INTEGRAL_ENDIANNESS == Z_ENDIANNESS_BIG
#		define z_uint16_big_endian    Z_SAME
#		define z_uint16_little_endian z_uint16_reverse

#	elif Z_ISA_INTEGRAL_ENDIANNESS == Z_ENDIANNESS_LITTLE
#		define z_uint16_big_endian    z_uint16_reverse
#		define z_uint16_little_endian Z_SAME
#	endif
#endif

#ifdef Z_SINT16
	Z__INTEGER_EXTRACT(16)
#endif

#ifdef Z_UINT32
	Z__NATURAL_EXTRACT(32)
	Z__NATURAL_REVERSE(32)
	Z__NATURAL_ROTATE (32)

#	if Z_ISA_INTEGRAL_ENDIANNESS == Z_ENDIANNESS_BIG
#		define z_uint32_big_endian    Z_SAME
#		define z_uint32_little_endian z_uint32_reverse

#	elif Z_ISA_INTEGRAL_ENDIANNESS == Z_ENDIANNESS_LITTLE
#		define z_uint32_big_endian    z_uint32_reverse
#		define z_uint32_little_endian Z_SAME
#	endif
#endif

#ifdef Z_SINT32
	Z__INTEGER_EXTRACT(32)
#endif

#ifdef Z_UINT64
	Z__NATURAL_EXTRACT(64)
	Z__NATURAL_REVERSE(64)
	Z__NATURAL_ROTATE (64)

#	if Z_ISA_INTEGRAL_ENDIANNESS == Z_ENDIANNESS_BIG
#		define z_uint64_big_endian    Z_SAME
#		define z_uint64_little_endian z_uint64_reverse

#	elif Z_ISA_INTEGRAL_ENDIANNESS == Z_ENDIANNESS_LITTLE
#		define z_uint64_big_endian    z_uint64_reverse
#		define z_uint64_little_endian Z_SAME
#	endif
#endif

#ifdef Z_SINT64
	Z__INTEGER_EXTRACT(64)
#endif

#ifdef Z_UINT128
	Z__NATURAL_EXTRACT(128)
	Z__NATURAL_REVERSE(128)
	Z__NATURAL_ROTATE (128)

#	if Z_ISA_INTEGRAL_ENDIANNESS == Z_ENDIANNESS_BIG
#		define z_uint128_big_endian    Z_SAME
#		define z_uint128_little_endian z_uint128_reverse

#	elif Z_ISA_INTEGRAL_ENDIANNESS == Z_ENDIANNESS_LITTLE
#		define z_uint128_big_endian    z_uint128_reverse
#		define z_uint128_little_endian Z_SAME
#	endif
#endif

#ifdef Z_SINT128
	Z__INTEGER_EXTRACT(128)
#endif


#undef Z__NATURAL_EXTRACT
#undef Z__INTEGER_EXTRACT
#undef Z__NATURAL_REVERSE
#undef Z__NATURAL_ROTATE


#define z_type_big_endian(   TYPE) Z_INSERT_type(Z_##TYPE##_FIXED_FUNDAMENTAL)(z_, _big_endian   )
#define z_type_little_endian(TYPE) Z_INSERT_type(Z_##TYPE##_FIXED_FUNDAMENTAL)(z_, _little_endian)
#define z_type_reverse(	     TYPE) Z_INSERT_type(Z_##TYPE##_FIXED_FUNDAMENTAL)(z_, _reverse	 )
#define z_type_rotate_left(  TYPE) Z_INSERT_type(Z_##TYPE##_FIXED_FUNDAMENTAL)(z_, _rotate_left  )
#define z_type_rotate_right( TYPE) Z_INSERT_type(Z_##TYPE##_FIXED_FUNDAMENTAL)(z_, _rotate_right )

#endif /* Z_functions_bitwise_H */
