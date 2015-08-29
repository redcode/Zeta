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

#	define z_2d_uint8(  x, y)	((Z2DUInt8  ){x, y})
#	define z_2d_uint16( x, y)	((Z2DUInt16 ){x, y})
#	define z_2d_uint32( x, y)	((Z2DUInt32 ){x, y})
#	define z_2d_uint64( x, y)	((Z2DUInt64 ){x, y})
#	define z_2d_int8(   x, y)	((Z2DInt8   ){x, y})
#	define z_2d_int16(  x, y)	((Z2DInt16  ){x, y})
#	define z_2d_int32(  x, y)	((Z2DInt32  ){x, y})
#	define z_2d_int64(  x, y)	((Z2DInt64  ){x, y})
#	define z_2d_float(  x, y)	((Z2DFloat  ){x, y})
#	define z_2d_double( x, y)	((Z2DDouble ){x, y})
#	define z_2d_ldouble(x, y)	((Z2DLDouble){x, y})

#	define z_3d_uint8(  x, y, z)	((Z3DUInt8  ){x, y, z})
#	define z_3d_uint16( x, y, z)	((Z3DUInt16 ){x, y, z})
#	define z_3d_uint32( x, y, z)	((Z3DUInt32 ){x, y, z})
#	define z_3d_uint64( x, y, z)	((Z3DUInt64 ){x, y, z})
#	define z_3d_int8(   x, y, z)	((Z3DInt8   ){x, y, z})
#	define z_3d_int16(  x, y, z)	((Z3DInt16  ){x, y, z})
#	define z_3d_int32(  x, y, z)	((Z3DInt32  ){x, y, z})
#	define z_3d_int64(  x, y, z)	((Z3DInt64  ){x, y, z})
#	define z_3d_float(  x, y, z)	((Z3DFloat  ){x, y, z})
#	define z_3d_double( x, y, z)	((Z3DDouble ){x, y, z})
#	define z_3d_ldouble(x, y, z)	((Z3DLDouble){x, y, z})

#	define z_4d_uint8(  x, y, z, w) ((Z4DUInt8  ){x, y, z, w})
#	define z_4d_uint16( x, y, z, w) ((Z4DUInt16 ){x, y, z, w})
#	define z_4d_uint32( x, y, z, w) ((Z4DUInt32 ){x, y, z, w})
#	define z_4d_uint64( x, y, z, w) ((Z4DUInt64 ){x, y, z, w})
#	define z_4d_int8(   x, y, z, w) ((Z4DInt8   ){x, y, z, w})
#	define z_4d_int16(  x, y, z, w) ((Z4DInt16  ){x, y, z, w})
#	define z_4d_int32(  x, y, z, w) ((Z4DInt32  ){x, y, z, w})
#	define z_4d_int64(  x, y, z, w) ((Z4DInt64  ){x, y, z, w})
#	define z_4d_float(  x, y, z, w) ((Z4DFloat  ){x, y, z, w})
#	define z_4d_double( x, y, z, w) ((Z4DDouble ){x, y, z, w})
#	define z_4d_ldouble(x, y, z, w) ((Z4DLDouble){x, y, z, w})

#	define z_range(index, size) ((ZRange){index, size})

#else

#	define Z_MAGNITUDE_CONSTRUCTORS_IMPLEMENTATION(Type, type)		\
										\
										\
	Z_INLINE Z2D##Type z_2d_##type(z##type x, z##type y)			\
		{Z2D##Type magnitude = {x, y}; return magnitude;}		\
										\
										\
	Z_INLINE Z3D##Type z_3d_##type(z##type x, z##type y, z##type z)		\
		{Z3D##Type magnitude = {x, y, z}; return magnitude;}		\
										\
										\
	Z_INLINE								\
	Z4D##Type z_4d_##type(z##type x, z##type y, z##type z, z##type w) 	\
		{Z4D##Type magnitude = {x, y, z, w}; return magnitude;}


	Z_MAGNITUDE_CONSTRUCTORS_IMPLEMENTATION(UInt8,	 uint8	)
	Z_MAGNITUDE_CONSTRUCTORS_IMPLEMENTATION(UInt16,  uint16	)
	Z_MAGNITUDE_CONSTRUCTORS_IMPLEMENTATION(UInt32,  uint32	)
	Z_MAGNITUDE_CONSTRUCTORS_IMPLEMENTATION(UInt64,  uint64	)
	Z_MAGNITUDE_CONSTRUCTORS_IMPLEMENTATION(Int8,	 int8	)
	Z_MAGNITUDE_CONSTRUCTORS_IMPLEMENTATION(Int16,	 int16	)
	Z_MAGNITUDE_CONSTRUCTORS_IMPLEMENTATION(Int32,	 int32	)
	Z_MAGNITUDE_CONSTRUCTORS_IMPLEMENTATION(Int64,	 int64	)
	Z_MAGNITUDE_CONSTRUCTORS_IMPLEMENTATION(Float,	 float	)
	Z_MAGNITUDE_CONSTRUCTORS_IMPLEMENTATION(Double,  double	)
	Z_MAGNITUDE_CONSTRUCTORS_IMPLEMENTATION(LDouble, ldouble)


	Z_INLINE ZRange z_range(zsize index, zsize size)
		{ZRange range = {index, size}; return range;}

#endif

#define z_2d_uint8_zero   z_2d_uint8  (0, 0)
#define z_2d_uint16_zero  z_2d_uint16 (0, 0)
#define z_2d_uint32_zero  z_2d_uint32 (0, 0)
#define z_2d_uint64_zero  z_2d_uint64 (0, 0)
#define z_2d_int8_zero	  z_2d_int8   (0, 0)
#define z_2d_int16_zero   z_2d_int16  (0, 0)
#define z_2d_int32_zero   z_2d_int32  (0, 0)
#define z_2d_int64_zero   z_2d_int64  (0, 0)
#define z_2d_float_zero   z_2d_float  (0.0F, 0.0F)
#define z_2d_double_zero  z_2d_double (0.0,  0.0 )
#define z_2d_ldouble_zero z_2d_ldouble(0.0L, 0.0L)

#define z_3d_uint8_zero   z_3d_uint8  (0, 0, 0)
#define z_3d_uint16_zero  z_3d_uint16 (0, 0, 0)
#define z_3d_uint32_zero  z_3d_uint32 (0, 0, 0)
#define z_3d_uint64_zero  z_3d_uint64 (0, 0, 0)
#define z_3d_int8_zero	  z_3d_int8   (0, 0, 0)
#define z_3d_int16_zero   z_3d_int16  (0, 0, 0)
#define z_3d_int32_zero   z_3d_int32  (0, 0, 0)
#define z_3d_int64_zero   z_3d_int64  (0, 0, 0)
#define z_3d_float_zero   z_3d_float  (0.0F, 0.0F, 0.0F)
#define z_3d_double_zero  z_3d_double (0.0,  0.0,  0.0 )
#define z_3d_ldouble_zero z_3d_ldouble(0.0L, 0.0L, 0.0L)

#define z_4d_uint8_zero   z_4d_uint8  (0, 0, 0, 0)
#define z_4d_uint16_zero  z_4d_uint16 (0, 0, 0, 0)
#define z_4d_uint32_zero  z_4d_uint32 (0, 0, 0, 0)
#define z_4d_uint64_zero  z_4d_uint64 (0, 0, 0, 0)
#define z_4d_int8_zero	  z_4d_int8   (0, 0, 0, 0)
#define z_4d_int16_zero   z_4d_int16  (0, 0, 0, 0)
#define z_4d_int32_zero   z_4d_int32  (0, 0, 0, 0)
#define z_4d_int64_zero   z_4d_int64  (0, 0, 0, 0)
#define z_4d_float_zero   z_4d_float  (0.0F, 0.0F, 0.0F, 0.0F)
#define z_4d_double_zero  z_4d_double (0.0,  0.0,  0.0,  0.0 )
#define z_4d_ldouble_zero z_4d_ldouble(0.0L, 0.0L, 0.0L, 0.0L)

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
