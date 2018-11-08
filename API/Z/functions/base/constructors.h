/* Z Kit - functions/base/constructors.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_functions_base_constructors_H_
#define _Z_functions_base_constructors_H_

#include <Z/types/base.h>

#if Z_LANGUAGE_HAS(C, COMPOUND_LITERAL)

#	define z_2d_uint8(x, y)		   ((Z2DUInt8	 ){x, y}       )
#	define z_3d_uint8(x, y, z)	   ((Z3DUInt8	 ){x, y, z}    )
#	define z_4d_uint8(x, y, z, w)	   ((Z4DUInt8	 ){x, y, z, w} )
#	define z_range_uint8(index, size)  ((ZRangeUInt8 ){index, size})
#	define z_2d_sint8(x, y)		   ((Z2DSInt8	 ){x, y}       )
#	define z_3d_sint8(x, y, z)	   ((Z3DSInt8	 ){x, y, z}    )
#	define z_4d_sint8(x, y, z, w)	   ((Z4DSInt8	 ){x, y, z, w} )
#	define z_2d_uint16(x, y)	   ((Z2DUInt16	 ){x, y}       )
#	define z_3d_uint16(x, y, z)	   ((Z3DUInt16	 ){x, y, z}    )
#	define z_4d_uint16(x, y, z, w)	   ((Z4DUInt16	 ){x, y, z, w} )
#	define z_range_uint16(index, size) ((ZRangeUInt16){index, size})
#	define z_2d_sint16(x, y)	   ((Z2DSInt16	 ){x, y}       )
#	define z_3d_sint16(x, y, z)	   ((Z3DSInt16	 ){x, y, z}    )
#	define z_4d_sint16(x, y, z, w)	   ((Z4DSInt16	 ){x, y, z, w} )
#	define z_2d_uint32(x, y)	   ((Z2DUInt32	 ){x, y}       )
#	define z_3d_uint32(x, y, z)	   ((Z3DUInt32	 ){x, y, z}    )
#	define z_4d_uint32(x, y, z, w)	   ((Z4DUInt32	 ){x, y, z, w} )
#	define z_range_uint32(index, size) ((ZRangeUInt32){index, size})
#	define z_2d_sint32(x, y)	   ((Z2DSInt32	 ){x, y}       )
#	define z_3d_sint32(x, y, z)	   ((Z3DSInt32	 ){x, y, z}    )
#	define z_4d_sint32(x, y, z, w)	   ((Z4DSInt32	 ){x, y, z, w} )

#	ifdef Z_UINT64
#		define z_2d_uint64(x, y)	   ((Z2DUInt64	 ){x, y}       )
#		define z_3d_uint64(x, y, z)	   ((Z3DUInt64	 ){x, y, z}    )
#		define z_4d_uint64(x, y, z, w)	   ((Z4DUInt64	 ){x, y, z, w} )
#		define z_range_uint64(index, size) ((ZRangeUInt64){index, size})
#	endif

#	ifdef Z_SINT64
#		define z_2d_sint64(x, y)       ((Z2DSInt64){x, y}      )
#		define z_3d_sint64(x, y, z)    ((Z3DSInt64){x, y, z}   )
#		define z_4d_sint64(x, y, z, w) ((Z4DSInt64){x, y, z, w})
#	endif

#	ifdef Z_UINT128
#		define z_2d_uint128(x, y)	    ((Z2DUInt128   ){x, y}	 )
#		define z_3d_uint128(x, y, z)	    ((Z3DUInt128   ){x, y, z}	 )
#		define z_4d_uint128(x, y, z, w)	    ((Z4DUInt128   ){x, y, z, w} )
#		define z_range_uint128(index, size) ((ZRangeUInt128){index, size})
#	endif

#	ifdef Z_SINT128
#		define z_2d_sint128(x, y)	((Z2DSInt128){x, y}	 )
#		define z_3d_sint128(x, y, z)	((Z3DSInt128){x, y, z}	 )
#		define z_4d_sint128(x, y, z, w) ((Z4DSInt128){x, y, z, w})
#	endif

#	ifdef Z_FLOAT16
#		define z_2d_float16(x, y)	((Z2DFloat32){x, y}	 )
#		define z_3d_float16(x, y, z)	((Z3DFloat32){x, y, z}	 )
#		define z_4d_float16(x, y, z, w) ((Z4DFloat32){x, y, z, w})
#	endif

#	ifdef Z_FLOAT32
#		define z_2d_float32(x, y)	((Z2DFloat32){x, y}	 )
#		define z_3d_float32(x, y, z)	((Z3DFloat32){x, y, z}	 )
#		define z_4d_float32(x, y, z, w) ((Z4DFloat32){x, y, z, w})
#	endif

#	ifdef Z_FLOAT64
#		define z_2d_float64(x, y)	((Z2DFloat64){x, y}	 )
#		define z_3d_float64(x, y, z)	((Z3DFloat64){x, y, z}	 )
#		define z_4d_float64(x, y, z, w) ((Z4DFloat64){x, y, z, w})
#	endif

#	ifdef Z_FLOAT128
#		define z_2d_float128(x, y)	 ((Z2DFloat128){x, y}	   )
#		define z_3d_float128(x, y, z)	 ((Z3DFloat128){x, y, z}   )
#		define z_4d_float128(x, y, z, w) ((Z4DFloat128){x, y, z, w})
#	endif

#	ifdef Z_FLOAT80_X87
#		define z_2d_float80_x87(x, y)	    ((Z2DFloat80_x87){x, y}	 )
#		define z_3d_float80_x87(x, y, z)    ((Z3DFloat80_x87){x, y, z}	 )
#		define z_4d_float80_x87(x, y, z, w) ((Z4DFloat80_x87){x, y, z, w})
#	endif

#	ifdef Z_FLOAT96_X87
#		define z_2d_float96_x87(x, y)	    ((Z2DFloat96_x87){x, y}	 )
#		define z_3d_float96_x87(x, y, z)    ((Z3DFloat96_x87){x, y, z}	 )
#		define z_4d_float96_x87(x, y, z, w) ((Z4DFloat96_x87){x, y, z, w})
#	endif

#	ifdef Z_FLOAT128_X87
#		define z_2d_float128_x87(x, y)	     ((Z2DFloat128_x87){x, y}	   )
#		define z_3d_float128_x87(x, y, z)    ((Z3DFloat128_x87){x, y, z}   )
#		define z_4d_float128_x87(x, y, z, w) ((Z4DFloat128_x87){x, y, z, w})
#	endif

#else

#	define Z_IMPLEMENTATION_ZND_CONSTRUCTORS(Type, type)		  \
									  \
	static Z_INLINE							  \
	Z2D##Type z_2d_##type(z##type x, z##type y)			  \
		{							  \
		Z2D##Type object;					  \
									  \
		object.x = x;						  \
		object.y = y;						  \
		return object;						  \
		}							  \
									  \
									  \
	static Z_INLINE							  \
	Z3D##Type z_3d_##type(z##type x, z##type y, z##type z)		  \
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
	static Z_INLINE							  \
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


#	define Z_IMPLEMENTATION_ZRange_CONSTRUCTOR(Type, type)	 \
								 \
	static Z_INLINE						 \
	ZRange##Type z_range_##type(z##type index, z##type size) \
		{						 \
		ZRange##Type object;				 \
								 \
		object.index = index;				 \
		object.size  = size;				 \
		return object;					 \
		}


	Z_IMPLEMENTATION_ZND_CONSTRUCTORS  (UInt8,  uint8 )
	Z_IMPLEMENTATION_ZRange_CONSTRUCTOR(UInt8,  uint8 )
	Z_IMPLEMENTATION_ZND_CONSTRUCTORS  (SInt8,  sint8 )
	Z_IMPLEMENTATION_ZND_CONSTRUCTORS  (UInt16, uint16)
	Z_IMPLEMENTATION_ZRange_CONSTRUCTOR(UInt16, uint16)
	Z_IMPLEMENTATION_ZND_CONSTRUCTORS  (SInt16, sint16)
	Z_IMPLEMENTATION_ZND_CONSTRUCTORS  (UInt32, uint32)
	Z_IMPLEMENTATION_ZRange_CONSTRUCTOR(UInt32, uint32)
	Z_IMPLEMENTATION_ZND_CONSTRUCTORS  (SInt32, sint32)

#	ifdef Z_UINT64
		Z_IMPLEMENTATION_ZND_CONSTRUCTORS  (UInt64, uint64)
		Z_IMPLEMENTATION_ZRange_CONSTRUCTOR(UInt64, uint64)
		Z_IMPLEMENTATION_ZND_CONSTRUCTORS  (SInt64, sint64)
#	endif

#	ifdef Z_UINT128
		Z_IMPLEMENTATION_ZND_CONSTRUCTORS  (UInt128, uint128)
		Z_IMPLEMENTATION_ZRange_CONSTRUCTOR(UInt128, uint128)
		Z_IMPLEMENTATION_ZND_CONSTRUCTORS  (SInt128, sint128)
#	endif

#	ifdef Z_FLOAT16
		Z_IMPLEMENTATION_ZND_CONSTRUCTORS(Float16, float16)
#	endif

#	ifdef Z_FLOAT32
		Z_IMPLEMENTATION_ZND_CONSTRUCTORS(Float32, float32)
#	endif

#	ifdef Z_FLOAT64
		Z_IMPLEMENTATION_ZND_CONSTRUCTORS(Float64, float64)
#	endif

#	ifdef Z_FLOAT128
		Z_IMPLEMENTATION_ZND_CONSTRUCTORS(Float128, float128)
#	endif

#	ifdef Z_FLOAT80_X87
		Z_IMPLEMENTATION_ZND_CONSTRUCTORS(Float80_x87, float80_x87)
#	endif

#	ifdef Z_FLOAT96_X87
		Z_IMPLEMENTATION_ZND_CONSTRUCTORS(Float96_x87, float96_x87)
#	endif

#	ifdef Z_FLOAT128_X87
		Z_IMPLEMENTATION_ZND_CONSTRUCTORS(Float128_x87, float128_x87)
#	endif

#	undef Z_IMPLEMENTATION_ZND_CONSTRUCTORS
#	undef Z_IMPLEMENTATION_ZRange_CONSTRUCTOR

#endif

#define z_2d_uint8_zero	    z_2d_uint8	  (0, 0)
#define z_3d_uint8_zero	    z_3d_uint8	  (0, 0, 0)
#define z_4d_uint8_zero	    z_4d_uint8	  (0, 0, 0, 0)
#define z_range_uint8_zero  z_range_uint8 (0, 0)
#define z_2d_sint8_zero     z_2d_sint8	  (0, 0)
#define z_3d_sint8_zero     z_3d_sint8	  (0, 0, 0)
#define z_4d_sint8_zero     z_4d_sint8	  (0, 0, 0, 0)
#define z_2d_uint16_zero    z_2d_uint16	  (0, 0)
#define z_3d_uint16_zero    z_3d_uint16	  (0, 0, 0)
#define z_4d_uint16_zero    z_4d_uint16	  (0, 0, 0, 0)
#define z_range_uint16_zero z_range_uint16(0, 0)
#define z_2d_sint16_zero    z_2d_sint16	  (0, 0)
#define z_3d_sint16_zero    z_3d_sint16	  (0, 0, 0)
#define z_4d_sint16_zero    z_4d_sint16	  (0, 0, 0, 0)
#define z_2d_uint32_zero    z_2d_uint32	  (0, 0)
#define z_3d_uint32_zero    z_3d_uint32	  (0, 0, 0)
#define z_4d_uint32_zero    z_4d_uint32	  (0, 0, 0, 0)
#define z_range_uint32_zero z_range_uint32(0, 0)
#define z_2d_sint32_zero    z_2d_sint32	  (0, 0)
#define z_3d_sint32_zero    z_3d_sint32	  (0, 0, 0)
#define z_4d_sint32_zero    z_4d_sint32	  (0, 0, 0, 0)

#ifdef Z_UINT64
#	define z_2d_uint64_zero	   z_2d_uint64	 (0, 0)
#	define z_3d_uint64_zero	   z_3d_uint64	 (0, 0, 0)
#	define z_4d_uint64_zero	   z_4d_uint64	 (0, 0, 0, 0)
#	define z_range_uint64_zero z_range_uint64(0, 0)
#endif

#ifdef Z_SINT64
#	define z_2d_sint64_zero z_2d_sint64(0, 0)
#	define z_3d_sint64_zero z_3d_sint64(0, 0, 0)
#	define z_4d_sint64_zero z_4d_sint64(0, 0, 0, 0)
#endif

#ifdef Z_UINT128
#	define z_2d_uint128_zero    z_2d_uint128   (0, 0)
#	define z_3d_uint128_zero    z_3d_uint128   (0, 0, 0)
#	define z_4d_uint128_zero    z_4d_uint128   (0, 0, 0, 0)
#	define z_range_uint128_zero z_range_uint128(0, 0)
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

#define z_2d_type(	  TYPE) Z_APPEND_##TYPE##_fixed_type(z_2d_   )
#define z_3d_type(	  TYPE) Z_APPEND_##TYPE##_fixed_type(z_3d_   )
#define z_4d_type(	  TYPE) Z_APPEND_##TYPE##_fixed_type(z_4d_   )
#define z_range_type(	  TYPE) Z_APPEND_##TYPE##_fixed_type(z_range_)
#define z_2d_type_zero(	  TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_,    _zero)
#define z_3d_type_zero(	  TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_,    _zero)
#define z_4d_type_zero(	  TYPE) Z_INSERT_##TYPE##_fixed_type(z_4d_,    _zero)
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

#define z_range	     z_range_type     (USIZE)
#define z_range_zero z_range_type_zero(USIZE)

#endif /* _Z_functions_base_constructors_H_ */
