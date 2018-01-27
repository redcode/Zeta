/* Z Kit C API - functions/base/constructors.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
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
#		define z_2d_uint128(x, y)	    ((Z2DUInt128){(zuint128)(x), (zuint128)(y)})
#		define z_3d_uint128(x, y, z)	    ((Z3DUInt128){(zuint128)(x), (zuint128)(y), (zuint128)(z)})
#		define z_4d_uint128(x, y, z, w)	    ((Z4DUInt128){(zuint128)(x), (zuint128)(y), (zuint128)(z), (zuint128)(w)})
#		define z_range_uint128(index, size) ((ZRangeUInt128){(zuint128)(index), (zuint128)(size)})
#	endif

#	define z_2d_sint8(x, y)	      ((Z2DSInt8){(zsint8)(x), (zsint8)(y)})
#	define z_3d_sint8(x, y, z)    ((Z3DSInt8){(zsint8)(x), (zsint8)(y), (zsint8)(z)})
#	define z_4d_sint8(x, y, z, w) ((Z4DSInt8){(zsint8)(x), (zsint8)(y), (zsint8)(z), (zsint8)(w)})

#	define z_2d_sint16(x, y)       ((Z2DSInt16){(zsint16)(x), (zsint16)(y)})
#	define z_3d_sint16(x, y, z)    ((Z3DSInt16){(zsint16)(x), (zsint16)(y), (zsint16)(z)})
#	define z_4d_sint16(x, y, z, w) ((Z4DSInt16){(zsint16)(x), (zsint16)(y), (zsint16)(z), (zsint16)(w)})

#	define z_2d_sint32(x, y)       ((Z2DSInt32){(zsint32)(x), (zsint32)(y)})
#	define z_3d_sint32(x, y, z)    ((Z3DSInt32){(zsint32)(x), (zsint32)(y), (zsint32)(z)})
#	define z_4d_sint32(x, y, z, w) ((Z4DSInt32){(zsint32)(x), (zsint32)(y), (zsint32)(z), (zsint32)(w)})

#	ifdef Z_SINT64
#		define z_2d_sint64(x, y)       ((Z2DSInt64){(zsint64)(x), (zsint64)(y)})
#		define z_3d_sint64(x, y, z)    ((Z3DSInt64){(zsint64)(x), (zsint64)(y), (zsint64)(z)})
#		define z_4d_sint64(x, y, z, w) ((Z4DSInt64){(zsint64)(x), (zsint64)(y), (zsint64)(z), (zsint64)(w)})
#	endif

#	ifdef Z_SINT128
#		define z_2d_sint128(x, y)	((Z2DSInt128){(zsint128)(x), (zsint128)(y)})
#		define z_3d_sint128(x, y, z)	((Z3DSInt128){(zsint128)(x), (zsint128)(y), (zsint128)(z)})
#		define z_4d_sint128(x, y, z, w) ((Z4DSInt128){(zsint128)(x), (zsint128)(y), (zsint128)(z), (zsint128)(w)})
#	endif

#	ifdef Z_FLOAT16
#		define z_2d_float16(x, y)	((Z2DFloat32){(zfloat32)(x), (zfloat32)(y)})
#		define z_3d_float16(x, y, z)	((Z3DFloat32){(zfloat32)(x), (zfloat32)(y), (zfloat32)(z)})
#		define z_4d_float16(x, y, z, w) ((Z4DFloat32){(zfloat32)(x), (zfloat32)(y), (zfloat32)(z), (zfloat32)(w)})
#	endif

#	ifdef Z_FLOAT32
#		define z_2d_float32(x, y)	((Z2DFloat32){(zfloat32)(x), (zfloat32)(y)})
#		define z_3d_float32(x, y, z)	((Z3DFloat32){(zfloat32)(x), (zfloat32)(y), (zfloat32)(z)})
#		define z_4d_float32(x, y, z, w) ((Z4DFloat32){(zfloat32)(x), (zfloat32)(y), (zfloat32)(z), (zfloat32)(w)})
#	endif

#	ifdef Z_FLOAT64
#		define z_2d_float64(x, y)	((Z2DFloat64){(zfloat64)(x), (zfloat64)(y)})
#		define z_3d_float64(x, y, z)	((Z3DFloat64){(zfloat64)(x), (zfloat64)(y), (zfloat64)(z)})
#		define z_4d_float64(x, y, z, w) ((Z4DFloat64){(zfloat64)(x), (zfloat64)(y), (zfloat64)(z), (zfloat64)(w)})
#	endif

#	ifdef Z_FLOAT128
#		define z_2d_float128(x, y)	 ((Z2DFloat128){(zfloat128)(x), (zfloat128)(y)})
#		define z_3d_float128(x, y, z)	 ((Z3DFloat128){(zfloat128)(x), (zfloat128)(y), (zfloat128)(z)})
#		define z_4d_float128(x, y, z, w) ((Z4DFloat128){(zfloat128)(x), (zfloat128)(y), (zfloat128)(z), (zfloat128)(w)})
#	endif

#	ifdef Z_FLOAT80_X87
#		define z_2d_float80_x87(x, y)	    ((Z2DFloat80_x87){(zfloat80_x87)(x), (zfloat80_x87)(y)})
#		define z_3d_float80_x87(x, y, z)    ((Z3DFloat80_x87){(zfloat80_x87)(x), (zfloat80_x87)(y), (zfloat80_x87)(z)})
#		define z_4d_float80_x87(x, y, z, w) ((Z4DFloat80_x87){(zfloat80_x87)(x), (zfloat80_x87)(y), (zfloat80_x87)(z), (zfloat80_x87)(w)})
#	endif

#	ifdef Z_FLOAT96_X87
#		define z_2d_float96_x87(x, y)	    ((Z2DFloat96_x87){(zfloat96_x87)(x), (zfloat96_x87)(y)})
#		define z_3d_float96_x87(x, y, z)    ((Z3DFloat96_x87){(zfloat96_x87)(x), (zfloat96_x87)(y), (zfloat96_x87)(z)})
#		define z_4d_float96_x87(x, y, z, w) ((Z4DFloat96_x87){(zfloat96_x87)(x), (zfloat96_x87)(y), (zfloat96_x87)(z), (zfloat96_x87)(w)})
#	endif

#	ifdef Z_FLOAT128_X87
#		define z_2d_float128_x87(x, y)	     ((Z2DFloat128_x87){(zfloat128_x87)(x), (zfloat128_x87)(y)})
#		define z_3d_float128_x87(x, y, z)    ((Z3DFloat128_x87){(zfloat128_x87)(x), (zfloat128_x87)(y), (zfloat128_x87)(z)})
#		define z_4d_float128_x87(x, y, z, w) ((Z4DFloat128_x87){(zfloat128_x87)(x), (zfloat128_x87)(y), (zfloat128_x87)(z), (zfloat128_x87)(w)})
#	endif

#else

#	define Z_IMPLEMENTATION_ND_VALUE_CONSTRUCTORS(Type, type)	  \
									  \
									  \
	Z_INLINE Z2D##Type z_2d_##type(z##type x, z##type y)		  \
		{							  \
		Z2D##Type object;					  \
									  \
		object.x = x;						  \
		object.y = y;						  \
		return object;						  \
		}							  \
									  \
									  \
	Z_INLINE Z3D##Type z_3d_##type(z##type x, z##type y, z##type z)	  \
		{							  \
		Z3D##Type object;					  \
									  \
		object.x = x;						  \
		object.y = y;						  \
		object.z = z;						  \
		return object;						  \
		}							  \
									  \
									  \
	Z_INLINE							  \
	Z4D##Type z_4d_##type(z##type x, z##type y, z##type z, z##type w) \
		{							  \
		Z4D##Type object;					  \
									  \
		object.x = x;						  \
		object.y = y;						  \
		object.z = z;						  \
		object.w = w;						  \
		return object;						  \
		}


#	define Z_IMPLEMENTATION_RANGE_CONSTRUCTOR(Type, type)		  \
									  \
	Z_INLINE ZRange##Type z_range_##type(z##type index, z##type size) \
		{							  \
		ZRange##Type object;					  \
									  \
		object.index = index;					  \
		object.size  = size;					  \
		return object;						  \
		}


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

	Z_IMPLEMENTATION_ND_VALUE_CONSTRUCTORS(SInt8,  sint8 )
	Z_IMPLEMENTATION_ND_VALUE_CONSTRUCTORS(SInt16, sint16)
	Z_IMPLEMENTATION_ND_VALUE_CONSTRUCTORS(SInt32, sint32)

#	ifdef Z_SINT64
		Z_IMPLEMENTATION_ND_VALUE_CONSTRUCTORS(SInt64, sint64)
#	endif

#	ifdef Z_SINT128
		Z_IMPLEMENTATION_ND_VALUE_CONSTRUCTORS(SInt128, sint128)
#	endif

#	ifdef Z_FLOAT16
		Z_IMPLEMENTATION_ND_VALUE_CONSTRUCTORS(Float16, float16)
#	endif

#	ifdef Z_FLOAT32
		Z_IMPLEMENTATION_ND_VALUE_CONSTRUCTORS(Float32, float32)
#	endif

#	ifdef Z_FLOAT64
		Z_IMPLEMENTATION_ND_VALUE_CONSTRUCTORS(Float64, float64)
#	endif

#	ifdef Z_FLOAT128
		Z_IMPLEMENTATION_ND_VALUE_CONSTRUCTORS(Float128, float128)
#	endif

#	ifdef Z_FLOAT80_X87
		Z_IMPLEMENTATION_ND_VALUE_CONSTRUCTORS(Float80_x87, float80_x87)
#	endif

#	ifdef Z_FLOAT96_X87
		Z_IMPLEMENTATION_ND_VALUE_CONSTRUCTORS(Float96_x87, float96_x87)
#	endif

#	ifdef Z_FLOAT128_X87
		Z_IMPLEMENTATION_ND_VALUE_CONSTRUCTORS(Float128_x87, float128_x87)
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

#define z_2d_sint8_zero z_2d_sint8(0, 0)
#define z_3d_sint8_zero z_3d_sint8(0, 0, 0)
#define z_4d_sint8_zero z_4d_sint8(0, 0, 0, 0)

#define z_2d_sint16_zero z_2d_sint16(0, 0)
#define z_3d_sint16_zero z_3d_sint16(0, 0, 0)
#define z_4d_sint16_zero z_4d_sint16(0, 0, 0, 0)

#define z_2d_sint32_zero z_2d_sint32(0, 0)
#define z_3d_sint32_zero z_3d_sint32(0, 0, 0)
#define z_4d_sint32_zero z_4d_sint32(0, 0, 0, 0)

#ifdef Z_SINT64
#	define z_2d_sint64_zero z_2d_sint64(0, 0)
#	define z_3d_sint64_zero z_3d_sint64(0, 0, 0)
#	define z_4d_sint64_zero z_4d_sint64(0, 0, 0, 0)
#endif

#ifdef Z_SINT128
#	define z_2d_sint128_zero z_2d_sint128(0, 0)
#	define z_3d_sint128_zero z_3d_sint128(0, 0, 0)
#	define z_4d_sint128_zero z_4d_sint128(0, 0, 0, 0)
#endif

#ifdef Z_FLOAT16
#	define z_2d_float16_zero z_2d_float16(0.0, 0.0)
#	define z_3d_float16_zero z_3d_float16(0.0, 0.0, 0.0)
#	define z_4d_float16_zero z_4d_float16(0.0, 0.0, 0.0, 0.0)
#endif

#ifdef Z_FLOAT32
#	define z_2d_float32_zero z_2d_float32(0.0, 0.0)
#	define z_3d_float32_zero z_3d_float32(0.0, 0.0, 0.0)
#	define z_4d_float32_zero z_4d_float32(0.0, 0.0, 0.0, 0.0)
#endif

#ifdef Z_FLOAT64
#	define z_2d_float64_zero z_2d_float64(0.0, 0.0)
#	define z_3d_float64_zero z_3d_float64(0.0, 0.0, 0.0)
#	define z_4d_float64_zero z_4d_float64(0.0, 0.0, 0.0, 0.0)
#endif

#ifdef Z_FLOAT128
#	define z_2d_float128_zero z_2d_float128(0.0, 0.0)
#	define z_3d_float128_zero z_3d_float128(0.0, 0.0, 0.0)
#	define z_4d_float128_zero z_4d_float128(0.0, 0.0, 0.0, 0.0)
#endif

#ifdef Z_FLOAT80_X87
#	define z_2d_float80_x87_zero z_2d_float80_x87(0.0, 0.0)
#	define z_3d_float80_x87_zero z_3d_float80_x87(0.0, 0.0, 0.0)
#	define z_4d_float80_x87_zero z_4d_float80_x87(0.0, 0.0, 0.0, 0.0)
#endif

#ifdef Z_FLOAT96_X87
#	define z_2d_float96_x87_zero z_2d_float96_x87(0.0, 0.0)
#	define z_3d_float96_x87_zero z_3d_float96_x87(0.0, 0.0, 0.0)
#	define z_4d_float96_x87_zero z_4d_float96_x87(0.0, 0.0, 0.0, 0.0)
#endif

#ifdef Z_FLOAT128_X87
#	define z_2d_float128_x87_zero z_2d_float128_x87(0.0, 0.0)
#	define z_3d_float128_x87_zero z_3d_float128_x87(0.0, 0.0, 0.0)
#	define z_4d_float128_x87_zero z_4d_float128_x87(0.0, 0.0, 0.0, 0.0)
#endif

#define z_2d_type(   TYPE) Z_APPEND_##TYPE##_fixed_type(z_2d_	)
#define z_3d_type(   TYPE) Z_APPEND_##TYPE##_fixed_type(z_3d_	)
#define z_4d_type(   TYPE) Z_APPEND_##TYPE##_fixed_type(z_4d_	)
#define z_range_type(TYPE) Z_APPEND_##TYPE##_fixed_type(z_range_)

#define z_2d_type_zero(	  TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_,    _zero)
#define z_3d_type_zero(	  TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_,    _zero)
#define z_4d_type_zero(	  TYPE) Z_INSERT_##TYPE##_fixed_type(z_4d_,    _zero)
#define z_range_type_zero(TYPE) Z_INSERT_##TYPE##_fixed_type(z_range_, _zero)

/* MARK: - Default real type definitions */

#ifdef Z_REAL

#	define z_2d z_2d_type(REAL)
#	define z_3d z_3d_type(REAL)
#	define z_4d z_4d_type(REAL)

#	define z_2d_zero z_2d_type_zero(REAL)
#	define z_3d_zero z_3d_type_zero(REAL)
#	define z_4d_zero z_4d_type_zero(REAL)

#endif

#define z_range z_range_type(USIZE)

#define z_range_zero z_range_type_zero(USIZE)

#endif /* __Z_functions_base_constructors_H__ */
