/* Z Kit C API - functions/base/constructors.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_functions_base_constructors_H__
#define __Z_functions_base_constructors_H__

#include <Z/macros/templating.h>


#if Z_LANGUAGE_HAS(COMPOUND_LITERAL)

#	define z_2d_uint8(x, y)	      ((Z2DUInt8){x, y})
#	define z_3d_uint8(x, y, z)    ((Z3DUInt8){x, y, z})
#	define z_4d_uint8(x, y, z, w) ((Z4DUInt8){x, y, z, w})

#	define z_2d_uint16(x, y)       ((Z2DUInt16){x, y})
#	define z_3d_uint16(x, y, z)    ((Z3DUInt16){x, y, z})
#	define z_4d_uint16(x, y, z, w) ((Z4DUInt16){x, y, z, w})

#	define z_2d_uint32(x, y)       ((Z2DUInt32){x, y})
#	define z_3d_uint32(x, y, z)    ((Z3DUInt32){x, y, z})
#	define z_4d_uint32(x, y, z, w) ((Z4DUInt32){x, y, z, w})

#	if Z_IS_AVAILABLE(UINT64)
#		define z_2d_uint64(x, y)       ((Z2DUInt64){x, y})
#		define z_3d_uint64(x, y, z)    ((Z3DUInt64){x, y, z})
#		define z_4d_uint64(x, y, z, w) ((Z4DUInt64){x, y, z, w})
#	endif

#	if Z_IS_AVAILABLE(UINT128)
#		define z_2d_uint128(x, y)	((Z2DUInt128 ){x, y})
#		define z_3d_uint128(x, y, z)	((Z3DUInt128 ){x, y, z})
#		define z_4d_uint128(x, y, z, w)	((Z4DUInt128 ){x, y, z, w})
#	endif

#	define z_2d_int8(x, y)	     ((Z2DInt8){x, y})
#	define z_3d_int8(x, y, z)    ((Z3DInt8){x, y, z})
#	define z_4d_int8(x, y, z, w) ((Z4DInt8){x, y, z, w})

#	define z_2d_int16(x, y)	      ((Z2DInt16){x, y})
#	define z_3d_int16(x, y, z)    ((Z3DInt16){x, y, z})
#	define z_4d_int16(x, y, z, w) ((Z4DInt16){x, y, z, w})

#	define z_2d_int32(x, y)	      ((Z2DInt32){x, y})
#	define z_3d_int32(x, y, z)    ((Z3DInt32){x, y, z})
#	define z_4d_int32(x, y, z, w) ((Z4DInt32){x, y, z, w})

#	if Z_IS_AVAILABLE(INT64)
#		define z_2d_int64(x, y)	      ((Z2DInt64){x, y})
#		define z_3d_int64(x, y, z)    ((Z3DInt64){x, y, z})
#		define z_4d_int64(x, y, z, w) ((Z4DInt64){x, y, z, w})
#	endif

#	if Z_IS_AVAILABLE(INT128)
#		define z_2d_int128(x, y)       ((Z2DInt128){x, y})
#		define z_3d_int128(x, y, z)    ((Z3DInt128){x, y, z})
#		define z_4d_int128(x, y, z, w) ((Z4DInt128){x, y, z, w})
#	endif

#	if Z_IS_AVAILABLE(FLOAT16)
#		define z_2d_float16(x, y)	((Z2DFloat16){x, y})
#		define z_3d_float16(x, y, z)	((Z3DFloat16){x, y, z})
#		define z_4d_float16(x, y, z, w)	((Z4DFloat16){x, y, z, w})
#	endif

#	if Z_IS_AVAILABLE(FLOAT24)
#		define z_2d_float24(x, y)	((Z2DFloat24){x, y})
#		define z_3d_float24(x, y, z)	((Z3DFloat24){x, y, z})
#		define z_4d_float24(x, y, z, w)	((Z4DFloat24){x, y, z, w})
#	endif

#	if Z_IS_AVAILABLE(FLOAT32)
#		define z_2d_float32(x, y)	((Z2DFloat32){x, y})
#		define z_3d_float32(x, y, z)	((Z3DFloat32){x, y, z})
#		define z_4d_float32(x, y, z, w)	((Z4DFloat32){x, y, z, w})
#	endif

#	if Z_IS_AVAILABLE(FLOAT48)
#		define z_2d_float48(x, y)	((Z2DFloat48){x, y})
#		define z_3d_float48(x, y, z)	((Z3DFloat48){x, y, z})
#		define z_4d_float48(x, y, z, w)	((Z4DFloat48){x, y, z, w})
#	endif

#	if Z_IS_AVAILABLE(FLOAT64)
#		define z_2d_float64(x, y)	((Z2DFloat64){x, y})
#		define z_3d_float64(x, y, z)	((Z3DFloat64){x, y, z})
#		define z_4d_float64(x, y, z, w)	((Z4DFloat64){x, y, z, w})
#	endif

#	if Z_IS_AVAILABLE(FLOAT72)
#		define z_2d_float72(x, y)	((Z2DFloat72){x, y})
#		define z_3d_float72(x, y, z)	((Z3DFloat72){x, y, z})
#		define z_4d_float72(x, y, z, w)	((Z4DFloat72){x, y, z, w})
#	endif

#	if Z_IS_AVAILABLE(FLOAT80)
#		define z_2d_float80(x, y)	((Z2DFloat80){x, y})
#		define z_3d_float80(x, y, z)	((Z3DFloat80){x, y, z})
#		define z_4d_float80(x, y, z, w)	((Z4DFloat80){x, y, z, w})
#	endif

#	if Z_IS_AVAILABLE(FLOAT96)
#		define z_2d_float96(x, y)	((Z2DFloat96){x, y})
#		define z_3d_float96(x, y, z)	((Z3DFloat96){x, y, z})
#		define z_4d_float96(x, y, z, w)	((Z4DFloat96){x, y, z, w})
#	endif

#	if Z_IS_AVAILABLE(FLOAT128)
#		define z_2d_float128(x, y)	 ((Z2DFloat128){x, y})
#		define z_3d_float128(x, y, z)	 ((Z3DFloat128){x, y, z})
#		define z_4d_float128(x, y, z, w) ((Z4DFloat128){x, y, z, w})
#	endif

#	define z_range(index, size) ((ZRange){index, size})

#else

#	define Z_TEMPLATE_MAGNITUDE_CONSTRUCTORS(Type, type)			\
										\
	Z_INLINE Z2D##Type z_2d_##type(z##type x, z##type y)			\
		{Z2D##Type magnitude = {x, y}; return magnitude;}		\
										\
	Z_INLINE Z3D##Type z_3d_##type(z##type x, z##type y, z##type z)		\
		{Z3D##Type magnitude = {x, y, z}; return magnitude;}		\
										\
	Z_INLINE								\
	Z4D##Type z_4d_##type(z##type x, z##type y, z##type z, z##type w) 	\
		{Z4D##Type magnitude = {x, y, z, w}; return magnitude;}


	Z_TEMPLATE_MAGNITUDE_CONSTRUCTORS(UInt8,  uint8	)
	Z_TEMPLATE_MAGNITUDE_CONSTRUCTORS(UInt16, uint16)
	Z_TEMPLATE_MAGNITUDE_CONSTRUCTORS(UInt32, uint32)

#	if Z_IS_AVAILABLE(UINT64)
		Z_TEMPLATE_MAGNITUDE_CONSTRUCTORS(UInt64, uint64)
#	endif

#	if Z_IS_AVAILABLE(UINT128)
		Z_TEMPLATE_MAGNITUDE_CONSTRUCTORS(UInt128, uint128)
#	endif

	Z_TEMPLATE_MAGNITUDE_CONSTRUCTORS(Int8,	 int8 )
	Z_TEMPLATE_MAGNITUDE_CONSTRUCTORS(Int16, int16)
	Z_TEMPLATE_MAGNITUDE_CONSTRUCTORS(Int32, int32)

#	if Z_IS_AVAILABLE(INT64)
		Z_TEMPLATE_MAGNITUDE_CONSTRUCTORS(Int64, int64)
#	endif

#	if Z_IS_AVAILABLE(INT128)
		Z_TEMPLATE_MAGNITUDE_CONSTRUCTORS(Int128, int128)
#	endif

#	if Z_IS_AVAILABLE(FLOAT16)
		Z_TEMPLATE_MAGNITUDE_CONSTRUCTORS(Float16, float64)
#	endif

#	if Z_IS_AVAILABLE(FLOAT24)
		Z_TEMPLATE_MAGNITUDE_CONSTRUCTORS(Float24, float24)
#	endif

#	if Z_IS_AVAILABLE(FLOAT32)
		Z_TEMPLATE_MAGNITUDE_CONSTRUCTORS(Float32, float32)
#	endif

#	if Z_IS_AVAILABLE(FLOAT48)
		Z_TEMPLATE_MAGNITUDE_CONSTRUCTORS(Float48, float48)
#	endif

#	if Z_IS_AVAILABLE(FLOAT64)
		Z_TEMPLATE_MAGNITUDE_CONSTRUCTORS(Float64, float64)
#	endif

#	if Z_IS_AVAILABLE(FLOAT72)
		Z_TEMPLATE_MAGNITUDE_CONSTRUCTORS(Float72, float72)
#	endif

#	if Z_IS_AVAILABLE(FLOAT80)
		Z_TEMPLATE_MAGNITUDE_CONSTRUCTORS(Float80, float80)
#	endif

#	if Z_IS_AVAILABLE(FLOAT96)
		Z_TEMPLATE_MAGNITUDE_CONSTRUCTORS(Float96, float96)
#	endif

#	if Z_IS_AVAILABLE(FLOAT128)
		Z_TEMPLATE_MAGNITUDE_CONSTRUCTORS(Float128, float128)
#	endif


	Z_INLINE ZRange z_range(zsize index, zsize size)
		{ZRange range = {index, size}; return range;}

#endif


#define z_2d_uint8_zero z_2d_uint8(0, 0)
#define z_3d_uint8_zero z_3d_uint8(0, 0, 0)
#define z_4d_uint8_zero z_4d_uint8(0, 0, 0, 0)

#define z_2d_uint16_zero z_2d_uint16(0, 0)
#define z_3d_uint16_zero z_3d_uint16(0, 0, 0)
#define z_4d_uint16_zero z_4d_uint16(0, 0, 0, 0)

#define z_2d_uint32_zero z_2d_uint32(0, 0)
#define z_3d_uint32_zero z_3d_uint32(0, 0, 0)
#define z_4d_uint32_zero z_4d_uint32(0, 0, 0, 0)

#if Z_IS_AVAILABLE(UINT64)
#	define z_2d_uint64_zero z_2d_uint64(0, 0)
#	define z_3d_uint64_zero z_3d_uint64(0, 0, 0)
#	define z_4d_uint64_zero z_4d_uint64(0, 0, 0, 0)
#endif

#if Z_IS_AVAILABLE(UINT128)
#	define z_2d_uint128_zero z_2d_uint128(0, 0)
#	define z_3d_uint128_zero z_3d_uint128(0, 0, 0)
#	define z_4d_uint128_zero z_4d_uint128(0, 0, 0, 0)
#endif

#define z_2d_int8_zero z_2d_int8(0, 0)
#define z_3d_int8_zero z_3d_int8(0, 0, 0)
#define z_4d_int8_zero z_4d_int8(0, 0, 0, 0)

#define z_2d_int16_zero z_2d_int16(0, 0)
#define z_3d_int16_zero z_3d_int16(0, 0, 0)
#define z_4d_int16_zero z_4d_int16(0, 0, 0, 0)

#define z_2d_int32_zero z_2d_int32(0, 0)
#define z_3d_int32_zero z_3d_int32(0, 0, 0)
#define z_4d_int32_zero z_4d_int32(0, 0, 0, 0)

#if Z_IS_AVAILABLE(INT64)
#	define z_2d_int64_zero z_2d_int64(0, 0)
#	define z_3d_int64_zero z_3d_int64(0, 0, 0)
#	define z_4d_int64_zero z_4d_int64(0, 0, 0, 0)
#endif

#if Z_IS_AVAILABLE(INT128)
#	define z_2d_int128_zero z_2d_int128(0, 0)
#	define z_3d_int128_zero z_3d_int128(0, 0, 0)
#	define z_4d_int128_zero z_4d_int128(0, 0, 0, 0)
#endif

#if Z_IS_AVAILABLE(FLOAT16)
#	define z_2d_float16_zero z_2d_float16(0.0, 0.0)
#	define z_3d_float16_zero z_3d_float16(0.0, 0.0, 0.0)
#	define z_4d_float16_zero z_4d_float16(0.0, 0.0, 0.0, 0.0)
#endif

#if Z_IS_AVAILABLE(FLOAT24)
#	define z_2d_float24_zero z_2d_float24(0.0, 0.0)
#	define z_3d_float24_zero z_3d_float24(0.0, 0.0, 0.0)
#	define z_4d_float24_zero z_4d_float24(0.0, 0.0, 0.0, 0.0)
#endif

#if Z_IS_AVAILABLE(FLOAT32)
#	define z_2d_float32_zero z_2d_float32(0.0, 0.0)
#	define z_3d_float32_zero z_3d_float32(0.0, 0.0, 0.0)
#	define z_4d_float32_zero z_4d_float32(0.0, 0.0, 0.0, 0.0)
#endif

#if Z_IS_AVAILABLE(FLOAT48)
#	define z_2d_float48_zero z_2d_float48(0.0, 0.0)
#	define z_3d_float48_zero z_3d_float48(0.0, 0.0, 0.0)
#	define z_4d_float48_zero z_4d_float48(0.0, 0.0, 0.0, 0.0)
#endif

#if Z_IS_AVAILABLE(FLOAT64)
#	define z_2d_float64_zero z_2d_float64(0.0, 0.0)
#	define z_3d_float64_zero z_3d_float64(0.0, 0.0, 0.0)
#	define z_4d_float64_zero z_4d_float64(0.0, 0.0, 0.0, 0.0)
#endif

#if Z_IS_AVAILABLE(FLOAT72)
#	define z_2d_float72_zero z_2d_float72(0.0, 0.0)
#	define z_3d_float72_zero z_3d_float72(0.0, 0.0, 0.0)
#	define z_4d_float72_zero z_4d_float72(0.0, 0.0, 0.0, 0.0)
#endif

#if Z_IS_AVAILABLE(FLOAT80)
#	define z_2d_float80_zero z_2d_float80(0.0, 0.0)
#	define z_3d_float80_zero z_3d_float80(0.0, 0.0, 0.0)
#	define z_4d_float80_zero z_4d_float80(0.0, 0.0, 0.0, 0.0)
#endif

#if Z_IS_AVAILABLE(FLOAT96)
#	define z_2d_float96_zero z_2d_float96(0.0, 0.0)
#	define z_3d_float96_zero z_3d_float96(0.0, 0.0, 0.0)
#	define z_4d_float96_zero z_4d_float96(0.0, 0.0, 0.0, 0.0)
#endif

#if Z_IS_AVAILABLE(FLOAT128)
#	define z_2d_float128_zero z_2d_float128(0.0, 0.0)
#	define z_3d_float128_zero z_3d_float128(0.0, 0.0, 0.0)
#	define z_4d_float128_zero z_4d_float128(0.0, 0.0, 0.0, 0.0)
#endif

#define z_2d_type(     TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_,)
#define z_3d_type(     TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_,)
#define z_4d_type(     TYPE) Z_INSERT_##TYPE##_fixed_type(z_4d_,)
#define z_2d_type_zero(TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _zero)
#define z_3d_type_zero(TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _zero)
#define z_4d_type_zero(TYPE) Z_INSERT_##TYPE##_fixed_type(z_4d_, _zero)

#define z_range_zero z_range(0, 0)

/* MARK: - Default real type definitions */

#define z_2d	  z_2d_type	(REAL)
#define z_3d	  z_3d_type	(REAL)
#define z_4d	  z_4d_type	(REAL)
#define z_2d_zero z_2d_type_zero(REAL)
#define z_3d_zero z_3d_type_zero(REAL)
#define z_4d_zero z_4d_type_zero(REAL)

#endif /* __Z_functions_base_constructors_H__ */
