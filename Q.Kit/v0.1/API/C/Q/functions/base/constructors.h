/* Q Kit C API - functions/base/constructors.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_functions_base_constructors_H__
#define __Q_functions_base_constructors_H__

#include <Q/types/base.h>

#if Q_LANGUAGE_HAS(COMPOUND_LITERAL)

#	define q_2d_uint8(  x, y) ((Q2DUInt8  ){x, y})
#	define q_2d_uint16( x, y) ((Q2DUInt16 ){x, y})
#	define q_2d_uint32( x, y) ((Q2DUInt32 ){x, y})
#	define q_2d_uint64( x, y) ((Q2DUInt64 ){x, y})
#	define q_2d_int8(   x, y) ((Q2DInt8   ){x, y})
#	define q_2d_int16(  x, y) ((Q2DInt16  ){x, y})
#	define q_2d_int32(  x, y) ((Q2DInt32  ){x, y})
#	define q_2d_int64(  x, y) ((Q2DInt64  ){x, y})
#	define q_2d_float(  x, y) ((Q2DFloat  ){x, y})
#	define q_2d_double( x, y) ((Q2DDouble ){x, y})
#	define q_2d_ldouble(x, y) ((Q2DLDouble){x, y})

#	define q_3d_uint8(  x, y, z) ((Q3DUInt8	 ){x, y, z})
#	define q_3d_uint16( x, y, z) ((Q3DUInt16 ){x, y, z})
#	define q_3d_uint32( x, y, z) ((Q3DUInt32 ){x, y, z})
#	define q_3d_uint64( x, y, z) ((Q3DUInt64 ){x, y, z})
#	define q_3d_int8(   x, y, z) ((Q3DInt8	 ){x, y, z})
#	define q_3d_int16(  x, y, z) ((Q3DInt16	 ){x, y, z})
#	define q_3d_int32(  x, y, z) ((Q3DInt32	 ){x, y, z})
#	define q_3d_int64(  x, y, z) ((Q3DInt64	 ){x, y, z})
#	define q_3d_float(  x, y, z) ((Q3DFloat  ){x, y, z})
#	define q_3d_double( x, y, z) ((Q3DDouble ){x, y, z})
#	define q_3d_ldouble(x, y, z) ((Q3DLDouble){x, y, z})

#	define q_4d_uint8(  x, y, z, w) ((Q4DUInt8  ){x, y, z, w})
#	define q_4d_uint16( x, y, z, w) ((Q4DUInt16 ){x, y, z, w})
#	define q_4d_uint32( x, y, z, w) ((Q4DUInt32 ){x, y, z, w})
#	define q_4d_uint64( x, y, z, w) ((Q4DUInt64 ){x, y, z, w})
#	define q_4d_int8(   x, y, z, w) ((Q4DInt8   ){x, y, z, w})
#	define q_4d_int16(  x, y, z, w) ((Q4DInt16  ){x, y, z, w})
#	define q_4d_int32(  x, y, z, w) ((Q4DInt32  ){x, y, z, w})
#	define q_4d_int64(  x, y, z, w) ((Q4DInt64  ){x, y, z, w})
#	define q_4d_float(  x, y, z, w) ((Q4DFloat  ){x, y, z, w})
#	define q_4d_double( x, y, z, w) ((Q4DDouble ){x, y, z, w})
#	define q_4d_ldouble(x, y, z, w) ((Q4DLDouble){x, y, z, w})

#	define q_range(index, size)  ((QRange){index, size})

#else

#	define Q_MAGNITUDE_CONSTRUCTORS_IMPLEMENTATION(Type, type)	  	\
									  	\
									  	\
	Q_INLINE Q2D##Type q_2d_##type(q##type x, q##type y)			\
		{Q2D##Type magnitude = {x, y}; return magnitude;}	  	\
									  	\
									  	\
	Q_INLINE Q3D##Type q_3d_##type(q##type x, q##type y, q##type z)		\
		{Q3D##Type magnitude = {x, y, z}; return magnitude;}	  	\
									  	\
									  	\
	Q_INLINE								\
	Q4D##Type q_4d_##type(q##type x, q##type y, q##type z, q##type w) 	\
		{Q4D##Type magnitude = {x, y, z, w}; return magnitude;}


	Q_MAGNITUDE_CONSTRUCTORS_IMPLEMENTATION(UInt8,	 uint8	)
	Q_MAGNITUDE_CONSTRUCTORS_IMPLEMENTATION(UInt16,  uint16 )
	Q_MAGNITUDE_CONSTRUCTORS_IMPLEMENTATION(UInt32,  uint32 )
	Q_MAGNITUDE_CONSTRUCTORS_IMPLEMENTATION(UInt64,  uint64 )
	Q_MAGNITUDE_CONSTRUCTORS_IMPLEMENTATION(Int8,	 int8	)
	Q_MAGNITUDE_CONSTRUCTORS_IMPLEMENTATION(Int16,	 int16	)
	Q_MAGNITUDE_CONSTRUCTORS_IMPLEMENTATION(Int32,	 int32	)
	Q_MAGNITUDE_CONSTRUCTORS_IMPLEMENTATION(Int64,	 int64	)
	Q_MAGNITUDE_CONSTRUCTORS_IMPLEMENTATION(Float,	 float	)
	Q_MAGNITUDE_CONSTRUCTORS_IMPLEMENTATION(Double,  double )
	Q_MAGNITUDE_CONSTRUCTORS_IMPLEMENTATION(LDouble, ldouble)


	Q_INLINE QRange q_range(qsize index, qsize size)
		{QRange range = {index, size}; return range;}

#endif

#define q_2d_uint8_zero   q_2d_uint8  (0, 0)
#define q_2d_uint16_zero  q_2d_uint16 (0, 0)
#define q_2d_uint32_zero  q_2d_uint32 (0, 0)
#define q_2d_uint64_zero  q_2d_uint64 (0, 0)
#define q_2d_int8_zero	  q_2d_int8   (0, 0)
#define q_2d_int16_zero   q_2d_int16  (0, 0)
#define q_2d_int32_zero   q_2d_int32  (0, 0)
#define q_2d_int64_zero   q_2d_int64  (0, 0)
#define q_2d_float_zero   q_2d_float  (0.0F, 0.0F)
#define q_2d_double_zero  q_2d_double (0.0,  0.0 )
#define q_2d_ldouble_zero q_2d_ldouble(0.0L, 0.0L)

#define q_3d_uint8_zero   q_3d_uint8  (0, 0, 0)
#define q_3d_uint16_zero  q_3d_uint16 (0, 0, 0)
#define q_3d_uint32_zero  q_3d_uint32 (0, 0, 0)
#define q_3d_uint64_zero  q_3d_uint64 (0, 0, 0)
#define q_3d_int8_zero	  q_3d_int8   (0, 0, 0)
#define q_3d_int16_zero   q_3d_int16  (0, 0, 0)
#define q_3d_int32_zero   q_3d_int32  (0, 0, 0)
#define q_3d_int64_zero   q_3d_int64  (0, 0, 0)
#define q_3d_float_zero   q_3d_float  (0.0F, 0.0F, 0.0F)
#define q_3d_double_zero  q_3d_double (0.0,  0.0,  0.0 )
#define q_3d_ldouble_zero q_3d_ldouble(0.0L, 0.0L, 0.0L)

#define q_4d_uint8_zero   q_4d_uint8  (0, 0, 0, 0)
#define q_4d_uint16_zero  q_4d_uint16 (0, 0, 0, 0)
#define q_4d_uint32_zero  q_4d_uint32 (0, 0, 0, 0)
#define q_4d_uint64_zero  q_4d_uint64 (0, 0, 0, 0)
#define q_4d_int8_zero	  q_4d_int8   (0, 0, 0, 0)
#define q_4d_int16_zero   q_4d_int16  (0, 0, 0, 0)
#define q_4d_int32_zero   q_4d_int32  (0, 0, 0, 0)
#define q_4d_int64_zero   q_4d_int64  (0, 0, 0, 0)
#define q_4d_float_zero   q_4d_float  (0.0F, 0.0F, 0.0F, 0.0F)
#define q_4d_double_zero  q_4d_double (0.0,  0.0,  0.0,  0.0 )
#define q_4d_ldouble_zero q_4d_ldouble(0.0L, 0.0L, 0.0L, 0.0L)

#define q_2d_value(	TYPE) Q_JOIN_2(q_2d_, Q_##TYPE##_FIXED_TYPE_name       )
#define q_3d_value(	TYPE) Q_JOIN_2(q_3d_, Q_##TYPE##_FIXED_TYPE_name       )
#define q_4d_value(	TYPE) Q_JOIN_2(q_4d_, Q_##TYPE##_FIXED_TYPE_name       )
#define q_2d_value_zero(TYPE) Q_JOIN_3(q_2d_, Q_##TYPE##_FIXED_TYPE_name, _zero)
#define q_3d_value_zero(TYPE) Q_JOIN_3(q_3d_, Q_##TYPE##_FIXED_TYPE_name, _zero)
#define q_4d_value_zero(TYPE) Q_JOIN_3(q_4d_, Q_##TYPE##_FIXED_TYPE_name, _zero)

#define q_range_zero q_range(0, 0)

/* MARK: - Default real type definitions */

#define q_2d Q_JOIN_2(q_2d_, Q_REAL_FIXED_TYPE_name)
#define q_3d Q_JOIN_2(q_3d_, Q_REAL_FIXED_TYPE_name)
#define q_4d Q_JOIN_2(q_4d_, Q_REAL_FIXED_TYPE_name)

#define q_2d_zero Q_JOIN_3(q_2d_, Q_REAL_FIXED_TYPE_name, _zero)
#define q_3d_zero Q_JOIN_3(q_3d_, Q_REAL_FIXED_TYPE_name, _zero)
#define q_4d_zero Q_JOIN_3(q_4d_, Q_REAL_FIXED_TYPE_name, _zero)

#endif /* __Q_functions_base_constructors_H__ */
