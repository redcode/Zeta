/* Z Kit C API - functions/base/constructors.h
	      ___
 _____	____ /	/______
/_   /_/  -_)  __/  _ /
 /____/\___/\__/ \__,_/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_functions_base_constructors_H__
#define __Z_functions_base_constructors_H__

#include <Z/types/base.h>

#if Z_LANGUAGE_HAS(C, COMPOUND_LITERAL)

#	define z_2d_uint8(x, y)		  ((Z2DUInt8){(zuint8)(x), (zuint8)(y)})
#	define z_3d_uint8(x, y, z)	  ((Z3DUInt8){(zuint8)(x), (zuint8)(y), (zuint8)(z)})
#	define z_4d_uint8(x, y, z, w)	  ((Z4DUInt8){(zuint8)(x), (zuint8)(y), (zuint8)(z), (zuint8)(w)})
#	define z_range_uint8(index, size) ((ZRangeUInt8){(zuint8)(index), (zuint8)(size)})

#	define z_2d_uint16(x, y)	   ((Z2DUInt16){(zuint16)(x), (zuint16)(y)})
#	define z_3d_uint16(x, y, z)	   ((Z3DUInt16){(zuint16)(x), (zuint16)(y), (zuint16)(z)})
#	define z_4d_uint16(x, y, z, w)	   ((Z4DUInt16){(zuint16)(x), (zuint16)(y), (zuint16)(z), (zuint16)(w)})
#	define z_range_uint16(index, size) ((ZRangeUInt16){(zuint16)(index), (zuint16)(size)})

#	define z_2d_uint32(x, y)	   ((Z2DUInt32){(zuint32)(x), (zuint32)(y)})
#	define z_3d_uint32(x, y, z)	   ((Z3DUInt32){(zuint32)(x), (zuint32)(y), (zuint32)(z)})
#	define z_4d_uint32(x, y, z, w)	   ((Z4DUInt32){(zuint32)(x), (zuint32)(y), (zuint32)(z), (zuint32)(w)})
#	define z_range_uint32(index, size) ((ZRangeUInt32){(zuint32)(index), (zuint32)(size)})

#	ifdef Z_UINT64
#		define z_2d_uint64(x, y)	   ((Z2DUInt64){(zuint32)(x), (zuint64)(y)})
#		define z_3d_uint64(x, y, z)	   ((Z3DUInt64){(zuint64)(x), (zuint64)(y), (zuint64)(z)})
#		define z_4d_uint64(x, y, z, w)	   ((Z4DUInt64){(zuint64)(x), (zuint64)(y), (zuint64)(z), (zuint64)(w)})
#		define z_range_uint64(index, size) ((ZRangeUInt64){(zuint64)(index), (zuint64)(size)})
#	endif

#	ifdef Z_UINT128
#		define z_2d_uint128(x, y)	    ((Z2DUInt128 ){(zuint128)(x), (zuint128)(y)})
#		define z_3d_uint128(x, y, z)	    ((Z3DUInt128 ){(zuint128)(x), (zuint128)(y), (zuint128)(z)})
#		define z_4d_uint128(x, y, z, w)	    ((Z4DUInt128 ){(zuint128)(x), (zuint128)(y), (zuint128)(z), (zuint128)(w)})
#		define z_range_uint128(index, size) ((ZRangeUInt128){(zuint128)(index), (zuint128)(size)})
#	endif

#	define z_2d_int8(x, y)	     ((Z2DInt8){(zint8)(x), (zint8)(y)})
#	define z_3d_int8(x, y, z)    ((Z3DInt8){(zint8)(x), (zint8)(y), (zint8)(z)})
#	define z_4d_int8(x, y, z, w) ((Z4DInt8){(zint8)(x), (zint8)(y), (zint8)(z), (zint8)(w)})

#	define z_2d_int16(x, y)	      ((Z2DInt16){(zint16)(x), (zint16)(y)})
#	define z_3d_int16(x, y, z)    ((Z3DInt16){(zint16)(x), (zint16)(y), (zint16)(z)})
#	define z_4d_int16(x, y, z, w) ((Z4DInt16){(zint16)(x), (zint16)(y), (zint16)(z), (zint16)(w)})

#	define z_2d_int32(x, y)	      ((Z2DInt32){(zint32)(x), (zint32)(y)})
#	define z_3d_int32(x, y, z)    ((Z3DInt32){(zint32)(x), (zint32)(y), (zint32)(z)})
#	define z_4d_int32(x, y, z, w) ((Z4DInt32){(zint32)(x), (zint32)(y), (zint32)(z), (zint32)(w)})

#	ifdef Z_INT64
#		define z_2d_int64(x, y)	      ((Z2DInt64){(zint64)(x), (zint64)(y)})
#		define z_3d_int64(x, y, z)    ((Z3DInt64){(zint64)(x), (zint64)(y), (zint64)(z)})
#		define z_4d_int64(x, y, z, w) ((Z4DInt64){(zint64)(x), (zint64)(y), (zint64)(z), (zint64)(w)})
#	endif

#	ifdef Z_INT128
#		define z_2d_int128(x, y)       ((Z2DInt128){(zint128)(x), (zint128)(y)})
#		define z_3d_int128(x, y, z)    ((Z3DInt128){(zint128)(x), (zint128)(y), (zint128)(z)})
#		define z_4d_int128(x, y, z, w) ((Z4DInt128){(zint128)(x), (zint128)(y), (zint128)(z), (zint128)(w)})
#	endif

#	ifdef Z_FLOAT16
#		define z_2d_float16(x, y)	((Z2DFloat16){(zfloat16)(x), (zfloat16)(y)})
#		define z_3d_float16(x, y, z)	((Z3DFloat16){(zfloat16)(x), (zfloat16)(y), (zfloat16)(z)})
#		define z_4d_float16(x, y, z, w)	((Z4DFloat16){(zfloat16)(x), (zfloat16)(y), (zfloat16)(z), (zfloat16)(w)})
#	endif

#	ifdef Z_FLOAT24
#		define z_2d_float24(x, y)	((Z2DFloat24){(zfloat24)(x), (zfloat24)(y)})
#		define z_3d_float24(x, y, z)	((Z3DFloat24){(zfloat24)(x), (zfloat24)(y), (zfloat24)(z)})
#		define z_4d_float24(x, y, z, w)	((Z4DFloat24){(zfloat24)(x), (zfloat24)(y), (zfloat24)(z), (zfloat24)(w)})
#	endif

#	ifdef Z_FLOAT32
#		define z_2d_float32(x, y)	((Z2DFloat32){(zfloat32)(x), (zfloat32)(y)})
#		define z_3d_float32(x, y, z)	((Z3DFloat32){(zfloat32)(x), (zfloat32)(y), (zfloat32)(z)})
#		define z_4d_float32(x, y, z, w)	((Z4DFloat32){(zfloat32)(x), (zfloat32)(y), (zfloat32)(z), (zfloat32)(w)})
#	endif

#	ifdef Z_FLOAT48
#		define z_2d_float48(x, y)	((Z2DFloat48){(zfloat48)(x), (zfloat48)(y)})
#		define z_3d_float48(x, y, z)	((Z3DFloat48){(zfloat48)(x), (zfloat48)(y), (zfloat48)(z)})
#		define z_4d_float48(x, y, z, w)	((Z4DFloat48){(zfloat48)(x), (zfloat48)(y), (zfloat48)(z), (zfloat48)(w)})
#	endif

#	ifdef Z_FLOAT64
#		define z_2d_float64(x, y)	((Z2DFloat64){(zfloat64)(x), (zfloat64)(y)})
#		define z_3d_float64(x, y, z)	((Z3DFloat64){(zfloat64)(x), (zfloat64)(y), (zfloat64)(z)})
#		define z_4d_float64(x, y, z, w)	((Z4DFloat64){(zfloat64)(x), (zfloat64)(y), (zfloat64)(z), (zfloat64)(w)})
#	endif

#	ifdef Z_FLOAT72
#		define z_2d_float72(x, y)	((Z2DFloat72){(zfloat72)(x), (zfloat72)(y)})
#		define z_3d_float72(x, y, z)	((Z3DFloat72){(zfloat72)(x), (zfloat72)(y), (zfloat72)(z)})
#		define z_4d_float72(x, y, z, w)	((Z4DFloat72){(zfloat72)(x), (zfloat72)(y), (zfloat72)(z), (zfloat72)(w)})
#	endif

#	ifdef Z_FLOAT80
#		define z_2d_float80(x, y)	((Z2DFloat80){(zfloat80)(x), (zfloat80)(y)})
#		define z_3d_float80(x, y, z)	((Z3DFloat80){(zfloat80)(x), (zfloat80)(y), (zfloat80)(z)})
#		define z_4d_float80(x, y, z, w)	((Z4DFloat80){(zfloat80)(x), (zfloat80)(y), (zfloat80)(z), (zfloat80)(w)})
#	endif

#	ifdef Z_FLOAT96
#		define z_2d_float96(x, y)	((Z2DFloat96){(zfloat96)(x), (zfloat96)(y)})
#		define z_3d_float96(x, y, z)	((Z3DFloat96){(zfloat96)(x), (zfloat96)(y), (zfloat96)(z)})
#		define z_4d_float96(x, y, z, w)	((Z4DFloat96){(zfloat96)(x), (zfloat96)(y), (zfloat96)(z), (zfloat96)(w)})
#	endif

#	ifdef Z_FLOAT128
#		define z_2d_float128(x, y)	 ((Z2DFloat128){(zfloat128)(x), (zfloat128)(y)})
#		define z_3d_float128(x, y, z)	 ((Z3DFloat128){(zfloat128)(x), (zfloat128)(y), (zfloat128)(z)})
#		define z_4d_float128(x, y, z, w) ((Z4DFloat128){(zfloat128)(x), (zfloat128)(y), (zfloat128)(z), (zfloat128)(w)})
#	endif

#else

#	define Z_IMPLEMENTATION_ND_VALUE_CONSTRUCTORS(Type, type)	  \
									  \
	Z_INLINE Z2D##Type z_2d_##type(z##type x, z##type y)		  \
		{Z2D##Type object = {x, y}; return object;}		  \
									  \
	Z_INLINE Z3D##Type z_3d_##type(z##type x, z##type y, z##type z)	  \
		{Z3D##Type object = {x, y, z}; return object;}		  \
									  \
	Z_INLINE							  \
	Z4D##Type z_4d_##type(z##type x, z##type y, z##type z, z##type w) \
		{Z4D##Type object = {x, y, z, w}; return object;}


#	define Z_IMPLEMENTATION_RANGE_CONSTRUCTOR(Type, type)		  \
									  \
	Z_INLINE ZRange##Type z_range_##type(z##type index, z##type size) \
		{ZRange##Type object = {index, size}; return object;}


	Z_IMPLEMENTATION_ND_VALUE_CONSTRUCTORS(UInt8,  uint8 )
	Z_IMPLEMENTATION_RANGE_CONSTRUCTOR    (UInt8,  uint8 )
	Z_IMPLEMENTATION_ND_VALUE_CONSTRUCTORS(UInt16, uint16)
	Z_IMPLEMENTATION_RANGE_CONSTRUCTOR    (UInt16, uint16)
	Z_IMPLEMENTATION_ND_VALUE_CONSTRUCTORS(UInt32, uint32)
	Z_IMPLEMENTATION_RANGE_CONSTRUCTOR    (UInt32, uint32)

#	ifdef Z_UINT64
		Z_IMPLEMENTATION_ND_VALUE_CONSTRUCTORS(UInt64, uint64)
		Z_IMPLEMENTATION_RANGE_CONSTRUCTOR    (UInt64, uint64)
#	endif

#	ifdef Z_UINT128
		Z_IMPLEMENTATION_ND_VALUE_CONSTRUCTORS(UInt128, uint128)
		Z_IMPLEMENTATION_RANGE_CONSTRUCTOR    (UInt128, uint128)
#	endif

	Z_IMPLEMENTATION_ND_VALUE_CONSTRUCTORS(Int8,  int8 )
	Z_IMPLEMENTATION_ND_VALUE_CONSTRUCTORS(Int16, int16)
	Z_IMPLEMENTATION_ND_VALUE_CONSTRUCTORS(Int32, int32)

#	ifdef Z_INT64
		Z_IMPLEMENTATION_ND_VALUE_CONSTRUCTORS(Int64, int64)
#	endif

#	ifdef Z_INT128
		Z_IMPLEMENTATION_ND_VALUE_CONSTRUCTORS(Int128, int128)
#	endif

#	ifdef Z_FLOAT16
		Z_IMPLEMENTATION_ND_VALUE_CONSTRUCTORS(Float16, float64)
#	endif

#	ifdef Z_FLOAT24
		Z_IMPLEMENTATION_ND_VALUE_CONSTRUCTORS(Float24, float24)
#	endif

#	ifdef Z_FLOAT32
		Z_IMPLEMENTATION_ND_VALUE_CONSTRUCTORS(Float32, float32)
#	endif

#	ifdef Z_FLOAT48
		Z_IMPLEMENTATION_ND_VALUE_CONSTRUCTORS(Float48, float48)
#	endif

#	ifdef Z_FLOAT64
		Z_IMPLEMENTATION_ND_VALUE_CONSTRUCTORS(Float64, float64)
#	endif

#	ifdef Z_FLOAT72
		Z_IMPLEMENTATION_ND_VALUE_CONSTRUCTORS(Float72, float72)
#	endif

#	ifdef Z_FLOAT80
		Z_IMPLEMENTATION_ND_VALUE_CONSTRUCTORS(Float80, float80)
#	endif

#	ifdef Z_FLOAT96
		Z_IMPLEMENTATION_ND_VALUE_CONSTRUCTORS(Float96, float96)
#	endif

#	ifdef Z_FLOAT128
		Z_IMPLEMENTATION_ND_VALUE_CONSTRUCTORS(Float128, float128)
#	endif

#endif

#define z_2d_uint8_zero	   z_2d_uint8(0, 0)
#define z_3d_uint8_zero	   z_3d_uint8(0, 0, 0)
#define z_4d_uint8_zero	   z_4d_uint8(0, 0, 0, 0)
#define z_range_uint8_zero z_range_uint8(0, 0)

#define z_2d_uint16_zero    z_2d_uint16(0, 0)
#define z_3d_uint16_zero    z_3d_uint16(0, 0, 0)
#define z_4d_uint16_zero    z_4d_uint16(0, 0, 0, 0)
#define z_range_uint16_zero z_range_uint16(0, 0)

#define z_2d_uint32_zero    z_2d_uint32(0, 0)
#define z_3d_uint32_zero    z_3d_uint32(0, 0, 0)
#define z_4d_uint32_zero    z_4d_uint32(0, 0, 0, 0)
#define z_range_uint32_zero z_range_uint32(0, 0)

#ifdef Z_UINT64
#	define z_2d_uint64_zero	   z_2d_uint64(0, 0)
#	define z_3d_uint64_zero	   z_3d_uint64(0, 0, 0)
#	define z_4d_uint64_zero	   z_4d_uint64(0, 0, 0, 0)
#	define z_range_uint64_zero z_range_uint64(0, 0)
#endif

#ifdef Z_UINT128
#	define z_2d_uint128_zero    z_2d_uint128(0, 0)
#	define z_3d_uint128_zero    z_3d_uint128(0, 0, 0)
#	define z_4d_uint128_zero    z_4d_uint128(0, 0, 0, 0)
#	define z_range_uint128_zero z_range_uint128(0, 0)
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

#ifdef Z_INT64
#	define z_2d_int64_zero z_2d_int64(0, 0)
#	define z_3d_int64_zero z_3d_int64(0, 0, 0)
#	define z_4d_int64_zero z_4d_int64(0, 0, 0, 0)
#endif

#ifdef Z_INT128
#	define z_2d_int128_zero z_2d_int128(0, 0)
#	define z_3d_int128_zero z_3d_int128(0, 0, 0)
#	define z_4d_int128_zero z_4d_int128(0, 0, 0, 0)
#endif

#ifdef Z_FLOAT16
#	define z_2d_float16_zero z_2d_float16(0.0, 0.0)
#	define z_3d_float16_zero z_3d_float16(0.0, 0.0, 0.0)
#	define z_4d_float16_zero z_4d_float16(0.0, 0.0, 0.0, 0.0)
#endif

#ifdef Z_FLOAT24
#	define z_2d_float24_zero z_2d_float24(0.0, 0.0)
#	define z_3d_float24_zero z_3d_float24(0.0, 0.0, 0.0)
#	define z_4d_float24_zero z_4d_float24(0.0, 0.0, 0.0, 0.0)
#endif

#ifdef Z_FLOAT32
#	define z_2d_float32_zero z_2d_float32(0.0, 0.0)
#	define z_3d_float32_zero z_3d_float32(0.0, 0.0, 0.0)
#	define z_4d_float32_zero z_4d_float32(0.0, 0.0, 0.0, 0.0)
#endif

#ifdef Z_FLOAT48
#	define z_2d_float48_zero z_2d_float48(0.0, 0.0)
#	define z_3d_float48_zero z_3d_float48(0.0, 0.0, 0.0)
#	define z_4d_float48_zero z_4d_float48(0.0, 0.0, 0.0, 0.0)
#endif

#ifdef Z_FLOAT64
#	define z_2d_float64_zero z_2d_float64(0.0, 0.0)
#	define z_3d_float64_zero z_3d_float64(0.0, 0.0, 0.0)
#	define z_4d_float64_zero z_4d_float64(0.0, 0.0, 0.0, 0.0)
#endif

#ifdef Z_FLOAT72
#	define z_2d_float72_zero z_2d_float72(0.0, 0.0)
#	define z_3d_float72_zero z_3d_float72(0.0, 0.0, 0.0)
#	define z_4d_float72_zero z_4d_float72(0.0, 0.0, 0.0, 0.0)
#endif

#ifdef Z_FLOAT80
#	define z_2d_float80_zero z_2d_float80(0.0, 0.0)
#	define z_3d_float80_zero z_3d_float80(0.0, 0.0, 0.0)
#	define z_4d_float80_zero z_4d_float80(0.0, 0.0, 0.0, 0.0)
#endif

#ifdef Z_FLOAT96
#	define z_2d_float96_zero z_2d_float96(0.0, 0.0)
#	define z_3d_float96_zero z_3d_float96(0.0, 0.0, 0.0)
#	define z_4d_float96_zero z_4d_float96(0.0, 0.0, 0.0, 0.0)
#endif

#ifdef Z_FLOAT128
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

#define z_range_type(	  TYPE) Z_INSERT_##TYPE##_fixed_type(z_range_,)
#define z_range_type_zero(TYPE) Z_INSERT_##TYPE##_fixed_type(z_range_, _zero)

/* MARK: - Default real type definitions */

#ifdef Z_REAL
#	define z_2d	 z_2d_type     (REAL)
#	define z_3d	 z_3d_type     (REAL)
#	define z_4d	 z_4d_type     (REAL)
#	define z_2d_zero z_2d_type_zero(REAL)
#	define z_3d_zero z_3d_type_zero(REAL)
#	define z_4d_zero z_4d_type_zero(REAL)
#endif

#define z_range	     z_range_type     (SIZE)
#define z_range_zero z_range_type_zero(SIZE)

#endif /* __Z_functions_base_constructors_H__ */
