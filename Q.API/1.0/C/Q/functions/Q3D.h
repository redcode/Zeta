/* Q API - functions/Q3D.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2013 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_functions_Q3D_H__
#define __Q_functions_Q3D_H__

#include <Q/functions/value.h>
#include <Q/inspection/language.h>


/* MARK: - Operations for natural, integer and real types */


#if Q_C_HAS(COMPOUND_LITERAL)

#	define q_3d_uchar(  x, y, z) ((Q3DUChar  ){x, y, z})
#	define q_3d_ushort( x, y, z) ((Q3DUShort ){x, y, z})
#	define q_3d_uint(   x, y, z) ((Q3DUInt	 ){x, y, z})
#	define q_3d_ulong(  x, y, z) ((Q3DULong	 ){x, y, z})
#	define q_3d_ullong( x, y, z) ((Q3DULLong ){x, y, z})
#	define q_3d_char(   x, y, z) ((Q3DChar	 ){x, y, z})
#	define q_3d_short(  x, y, z) ((Q3DShort	 ){x, y, z})
#	define q_3d_int(    x, y, z) ((Q3DInt	 ){x, y, z})
#	define q_3d_long(   x, y, z) ((Q3DLong	 ){x, y, z})
#	define q_3d_llong(  x, y, z) ((Q3DLLong	 ){x, y, z})
#	define q_3d_float(  x, y, z) ((Q3DFloat	 ){x, y, z})
#	define q_3d_double( x, y, z) ((Q3DDouble ){x, y, z})
#	define q_3d_ldouble(x, y, z) ((Q3DLDouble){x, y, z})
#	define q_3d_uint8(  x, y, z) ((Q3DUInt8	 ){x, y, z})
#	define q_3d_uint16( x, y, z) ((Q3DUInt16 ){x, y, z})
#	define q_3d_uint32( x, y, z) ((Q3DUInt32 ){x, y, z})
#	define q_3d_uint64( x, y, z) ((Q3DUInt64 ){x, y, z})
#	define q_3d_int8(   x, y, z) ((Q3DInt8	 ){x, y, z})
#	define q_3d_int16(  x, y, z) ((Q3DInt16	 ){x, y, z})
#	define q_3d_int32(  x, y, z) ((Q3DInt32	 ){x, y, z})
#	define q_3d_int64(  x, y, z) ((Q3DInt64	 ){x, y, z})
#	define q_3d_size(   x, y, z) ((Q3DSize	 ){x, y, z})
#	define q_3d_uintptr(x, y, z) ((Q3DUIntPtr){x, y, z})
#	define q_3d_uinttop(x, y, z) ((Q3DUIntTop){x, y, z})
#	define q_3d_uintmax(x, y, z) ((Q3DUIntMax){x, y, z})
#	define q_3d_ssize(  x, y, z) ((Q3DSSize	 ){x, y, z})
#	define q_3d_intptr( x, y, z) ((Q3DIntPtr ){x, y, z})
#	define q_3d_inttop( x, y, z) ((Q3DIntTop ){x, y, z})
#	define q_3d_intmax( x, y, z) ((Q3DIntMax ){x, y, z})
#	define q_3d_natural(x, y, z) ((Q3DNatural){x, y, z})
#	define q_3d_integer(x, y, z) ((Q3DInteger){x, y, z})
#	define q_3d_real(   x, y, z) ((Q3DReal	 ){x, y, z})
						
#	define Q_3D_NEW(Type, type)

#else

#	define Q_3D_NEW(Type, type)					\
									\
	Q_INLINE Q3D##Type q_3d_##type(q##type x, q##type y, q##type z)	\
		{Q3D##Type magnitude = {x, y, z}; return magnitude;}

#endif

#define q_3d_uchar_zero		q_3d_uchar  (0, 0, 0)
#define q_3d_ushort_zero	q_3d_ushort (0, 0, 0)
#define q_3d_uint_zero		q_3d_uint   (0, 0, 0)
#define q_3d_ulong_zero		q_3d_ulong  (0, 0, 0)
#define q_3d_ullong_zero	q_3d_ullong (0, 0, 0)
#define q_3d_char_zero		q_3d_char   (0, 0, 0)
#define q_3d_short_zero		q_3d_short  (0, 0, 0)
#define q_3d_int_zero		q_3d_int    (0, 0, 0)
#define q_3d_long_zero		q_3d_long   (0, 0, 0)
#define q_3d_llong_zero		q_3d_llong  (0, 0, 0)
#define q_3d_float_zero		q_3d_float  (0.0F, 0.0F, 0.0F)
#define q_3d_double_zero	q_3d_double (0.0,  0.0,  0.0 )
#define q_3d_ldouble_zero	q_3d_ldouble(0.0L, 0.0L, 0.0L)
#define q_3d_uint8_zero		q_3d_uint8  (0, 0, 0)
#define q_3d_uint16_zero	q_3d_uint16 (0, 0, 0)
#define q_3d_uint32_zero	q_3d_uint32 (0, 0, 0)
#define q_3d_uint64_zero	q_3d_uint64 (0, 0, 0)
#define q_3d_int8_zero		q_3d_int8   (0, 0, 0)
#define q_3d_int16_zero		q_3d_int16  (0, 0, 0)
#define q_3d_int32_zero		q_3d_int32  (0, 0, 0)
#define q_3d_int64_zero		q_3d_int64  (0, 0, 0)
#define q_3d_size_zero		q_3d_size   (0, 0, 0)
#define q_3d_uintptr_zero	q_3d_uintptr(0, 0, 0)
#define q_3d_uinttop_zero	q_3d_uinttop(0, 0, 0)
#define q_3d_uintmax_zero	q_3d_uintmax(0, 0, 0)
#define q_3d_ssize_zero		q_3d_ssize  (0, 0, 0)
#define q_3d_intptr_zero	q_3d_intptr (0, 0, 0)
#define q_3d_inttop_zero	q_3d_inttop (0, 0, 0)
#define q_3d_intmax_zero	q_3d_intmax (0, 0, 0)
#define q_3d_natural_zero	q_3d_natural(0, 0, 0)
#define q_3d_integer_zero	q_3d_integer(0, 0, 0)
#define q_3d_real_zero		q_3d_real   (Q_REAL(0.0), Q_REAL(0.0), Q_REAL(0.0))


#define Q_IMPLEMENTATION_NATURAL_3D(Type, type)					\
										\
Q_3D_NEW(Type, type)								\
										\
										\
Q_INLINE									\
qboolean q_3d_##type##_are_equal(Q3D##Type a, Q3D##Type b)			\
	{return a.x == b.x && a.y == b.y && a.z == b.z;}			\
										\
										\
Q_INLINE									\
void q_##3d_##type##_swap(Q3D##Type *a, Q3D##Type *b)				\
	{									\
	Q3D##Type t = *a;							\
										\
	*a = *b;								\
	*b = t;									\
	}									\
										\
										\
Q_INLINE									\
qboolean q_3d_##type##_contains(Q3D##Type a, Q3D##Type b)			\
	{return b.x <= a.x && b.y <= a.y && b.z <= a.z;}			\
										\
										\
Q_INLINE									\
Q3D##Type q_3d_##type##_add(Q3D##Type a, Q3D##Type b)				\
	{return q_3d_##type(a.x + b.x, a.y + b.y, a.z + b.z);}			\
										\
										\
Q_INLINE									\
Q3D##Type q_3d_##type##_subtract(Q3D##Type a, Q3D##Type b)			\
	{return q_3d_##type(a.x - b.x, a.y - b.y, a.z - b.z);}			\
										\
										\
Q_INLINE									\
Q3D##Type q_3d_##type##_multiply(Q3D##Type a, Q3D##Type b)			\
	{return q_3d_##type(a.x * b.x, a.y * b.y, a.z * b.z);}			\
										\
										\
Q_INLINE									\
Q3D##Type q_3d_##type##_divide(Q3D##Type a, Q3D##Type b)			\
	{return q_3d_##type(a.x / b.x, a.y / b.y, a.z / b.z);}			\
										\
										\
Q_INLINE									\
q##type q_3d_##type##_dot_product(Q3D##Type a, Q3D##Type b)			\
	{return a.x * b.x + a.y * b.y + a.y * b.y;}				\
										\
										\
Q_INLINE									\
Q3D##Type q_3d_##type##_cross_product(Q3D##Type a, Q3D##Type b)			\
	{									\
	return q_3d_##type							\
		(a.y * b.z - a.z * b.y,						\
		 a.z * b.x - a.x * b.z,						\
		 a.x * b.y - a.y * b.x); 					\
	}									\
										\
										\
Q_INLINE									\
Q3D##Type q_3d_##type##_minimum(Q3D##Type a, Q3D##Type b)			\
	{									\
	return q_3d_##type							\
		(q_##type##_minimum(a.x, b.x),					\
		 q_##type##_minimum(a.y, b.y),					\
		 q_##type##_minimum(a.z, b.z));					\
	}									\
										\
										\
Q_INLINE									\
Q3D##Type q_3d_##type##_maximum(Q3D##Type a, Q3D##Type b)			\
	{									\
	return q_3d_##type							\
		(q_##type##_maximum(a.x, b.x),					\
		 q_##type##_maximum(a.y, b.y),					\
		 q_##type##_maximum(a.z, b.z));					\
	}									\
										\
										\
Q_INLINE									\
Q3D##Type q_3d_##type##_middle(Q3D##Type a, Q3D##Type b)			\
	{									\
	return q_3d_##type							\
		((a.x + b.x) / (q##type)2,					\
		 (a.y + b.y) / (q##type)2,					\
		 (a.z + b.z) / (q##type)2);					\
	}									\
										\
										\
Q_INLINE									\
Q3D##Type q_3d_##type##_fit(Q3D##Type a, Q3D##Type b)				\
	{									\
	return q_3d_##type##_zero;/*a.y / a.x > b.y / b.x			\
		? q_3d_##type(a.x * b.y / a.y, b.y)				\
		: q_3d_##type(b.x, a.y * b.x / a.x);*/				\
	} /* Terminar */							\
										\
										\
Q_INLINE									\
Q3D##Type q_3d_##type##_from_scalar(q##type scalar)				\
	{return q_3d_##type(scalar, scalar, scalar);}				\
										\
										\
Q_INLINE									\
qboolean q_3d_##type##_is_zero(Q3D##Type magnitude)				\
	{									\
	return	magnitude.x == (q##type)0 &&					\
		magnitude.y == (q##type)0 &&					\
		magnitude.z == (q##type)0;					\
	}									\
										\
										\
Q_INLINE									\
q##type q_3d_##type##_inner_sum(Q3D##Type magnitude)				\
	{return magnitude.x + magnitude.y + magnitude.z;}			\
										\
										\
Q_INLINE									\
q##type q_3d_##type##_inner_product(Q3D##Type magnitude)			\
	{return magnitude.x * magnitude.y * magnitude.z;}			\
										\
										\
Q_INLINE									\
q##type q_3d_##type##_inner_average(Q3D##Type magnitude)			\
	{return (magnitude.x + magnitude.y + magnitude.z) / (q##type)3;}	\
										\
										\
Q_INLINE									\
q##type q_3d_##type##_square_length(Q3D##Type magnitude)			\
	{									\
	return	magnitude.x * magnitude.x +					\
		magnitude.y * magnitude.y +					\
		magnitude.y * magnitude.y;					\
	}									\
										\
										\
Q_INLINE									\
Q3D##Type q_3d_##type##_multiply_by_scalar(Q3D##Type magnitude, q##type scalar)	\
	{									\
	return q_3d_##type							\
		(magnitude.x * scalar,						\
		 magnitude.y * scalar,						\
		 magnitude.z * scalar);						\
	}									\
										\
										\
Q_INLINE									\
Q3D##Type q_3d_##type##_divide_by_scalar(Q3D##Type magnitude, q##type scalar)	\
	{									\
	return q_3d_##type							\
		(magnitude.x / scalar,						\
		 magnitude.y / scalar,						\
		 magnitude.z / scalar);						\
	}									\
										\
										\
Q_INLINE									\
Q3D##Type q_3d_##type##_clamp(							\
	Q3D##Type magnitude,							\
	Q3D##Type minimum,							\
	Q3D##Type maximum							\
)										\
	{									\
	return q_3d_##type							\
		(q_##type##_clamp(magnitude.x, minimum.x, maximum.x),		\
		 q_##type##_clamp(magnitude.y, minimum.y, maximum.y),		\
		 q_##type##_clamp(magnitude.z, minimum.z, maximum.z));		\
	}									\
										\
										\
Q_INLINE									\
Q3D##Type q_3d_##type##_cube_clamp(						\
	Q3D##Type magnitude,							\
	q##type	  minimum,							\
	q##type	  maximum							\
)										\
	{									\
	return q_3d_##type							\
		(q_##type##_clamp(magnitude.x, minimum, maximum),		\
		 q_##type##_clamp(magnitude.y, minimum, maximum),		\
		 q_##type##_clamp(magnitude.z, minimum, maximum));		\
	}									\
										\
										\
Q_INLINE									\
Q3D##Type q_3d_##type##_rotated_as_axes(Q3D##Type magnitude, Q3DInt8 rotation)	\
	{									\
	if ((rotation.x % 4) & 1) q_##type##_swap(&magnitude.y, &magnitude.z);	\
	if ((rotation.y % 4) & 1) q_##type##_swap(&magnitude.x, &magnitude.z);	\
	if ((rotation.z % 4) & 1) q_##type##_swap(&magnitude.x, &magnitude.y);	\
										\
	return magnitude;							\
	}


Q_IMPLEMENTATION_NATURAL_3D(UChar,   uchar  )
Q_IMPLEMENTATION_NATURAL_3D(UShort,  ushort )
Q_IMPLEMENTATION_NATURAL_3D(UInt,    uint   )
Q_IMPLEMENTATION_NATURAL_3D(ULong,   ulong  )
Q_IMPLEMENTATION_NATURAL_3D(ULLong,  ullong )
Q_IMPLEMENTATION_NATURAL_3D(Char,    char   )
Q_IMPLEMENTATION_NATURAL_3D(Short,   short  )
Q_IMPLEMENTATION_NATURAL_3D(Int,     int    )
Q_IMPLEMENTATION_NATURAL_3D(Long,    long   )
Q_IMPLEMENTATION_NATURAL_3D(LLong,   llong  )
Q_IMPLEMENTATION_NATURAL_3D(Float,   float  )
Q_IMPLEMENTATION_NATURAL_3D(Double,  double )
Q_IMPLEMENTATION_NATURAL_3D(LDouble, ldouble)
Q_IMPLEMENTATION_NATURAL_3D(UInt8,   uint8  )
Q_IMPLEMENTATION_NATURAL_3D(UInt16,  uint16 )
Q_IMPLEMENTATION_NATURAL_3D(UInt32,  uint32 )
Q_IMPLEMENTATION_NATURAL_3D(UInt64,  uint64 )
Q_IMPLEMENTATION_NATURAL_3D(Int8,    int8   )
Q_IMPLEMENTATION_NATURAL_3D(Int16,   int16  )
Q_IMPLEMENTATION_NATURAL_3D(Int32,   int32  )
Q_IMPLEMENTATION_NATURAL_3D(Int64,   int64  )
Q_IMPLEMENTATION_NATURAL_3D(Size,    size   )
Q_IMPLEMENTATION_NATURAL_3D(UIntPtr, uintptr)
Q_IMPLEMENTATION_NATURAL_3D(UIntTop, uinttop)
Q_IMPLEMENTATION_NATURAL_3D(UIntMax, uintmax)
Q_IMPLEMENTATION_NATURAL_3D(SSize,   ssize  )
Q_IMPLEMENTATION_NATURAL_3D(IntPtr,  intptr )
Q_IMPLEMENTATION_NATURAL_3D(IntTop,  inttop )
Q_IMPLEMENTATION_NATURAL_3D(IntMax,  intmax )
Q_IMPLEMENTATION_NATURAL_3D(Natural, natural)
Q_IMPLEMENTATION_NATURAL_3D(Integer, integer)
#undef Q_3D_NEW


/* MARK: - Operations for integer and real types */


#define Q_IMPLEMENTATION_INTEGER_3D(Type, type)				\
									\
									\
Q_INLINE								\
Q3D##Type q_3d_##type##_negative(Q3D##Type magnitude)			\
	{return q_3d_##type(-magnitude.x, -magnitude.y, -magnitude.z);}	\
									\
									\
Q_INLINE								\
Q3D##Type q_3d_##type##_absolute(Q3D##Type magnitude)			\
	{								\
	return q_3d_##type						\
		(q_##type##_absolute(magnitude.x),			\
		 q_##type##_absolute(magnitude.y),			\
		 q_##type##_absolute(magnitude.z));			\
	}


Q_IMPLEMENTATION_INTEGER_3D(Char,    char   )
Q_IMPLEMENTATION_INTEGER_3D(Short,   short  )
Q_IMPLEMENTATION_INTEGER_3D(Int,     int    )
Q_IMPLEMENTATION_INTEGER_3D(Long,    long   )
Q_IMPLEMENTATION_INTEGER_3D(LLong,   llong  )
Q_IMPLEMENTATION_INTEGER_3D(Float,   float  )
Q_IMPLEMENTATION_INTEGER_3D(Double,  double )
Q_IMPLEMENTATION_INTEGER_3D(LDouble, ldouble)
Q_IMPLEMENTATION_INTEGER_3D(Int8,    int8   )
Q_IMPLEMENTATION_INTEGER_3D(Int16,   int16  )
Q_IMPLEMENTATION_INTEGER_3D(Int32,   int32  )
Q_IMPLEMENTATION_INTEGER_3D(Int64,   int64  )
Q_IMPLEMENTATION_INTEGER_3D(SSize,   ssize  )
Q_IMPLEMENTATION_INTEGER_3D(IntPtr,  intptr )
Q_IMPLEMENTATION_INTEGER_3D(IntTop,  inttop )
Q_IMPLEMENTATION_INTEGER_3D(IntMax,  intmax )
Q_IMPLEMENTATION_INTEGER_3D(Integer, integer)


/* MARK: - Operations for real types only */


#define Q_IMPLEMENTATION_REAL_3D(Type, type, _, epsilon)		\
									\
									\
Q_INLINE								\
qboolean q_3d_##type##_are_perpendicular(Q3D##Type a, Q3D##Type b)	\
	{								\
	return	q_##type##_absolute(q_3d_##type##_dot_product(a, b))	\
		<= epsilon;						\
	}								\
									\
									\
Q_INLINE								\
Q3D##Type q_3d_##type##_lerp(Q3D##Type a, Q3D##Type b, q##type alpha)	\
	{								\
	return q_3d_##type						\
		(q_##type##_lerp(a.x, b.x, alpha),			\
		 q_##type##_lerp(a.y, b.y, alpha),			\
		 q_##type##_lerp(a.z, b.z, alpha));			\
	}								\
									\
									\
Q_INLINE								\
qboolean q_3d_##type##_is_near_zero(Q3D##Type magnitude)		\
	{								\
	return	q_##type##_absolute(magnitude.x) <= epsilon &&		\
		q_##type##_absolute(magnitude.y) <= epsilon &&		\
		q_##type##_absolute(magnitude.z) <= epsilon;		\
	}								\
									\
									\
Q_INLINE								\
Q3D##Type q_3d_##type##_reciprocal(Q3D##Type magnitude)			\
	{								\
	return q_3d_##type						\
		(_(1.0) / magnitude.x,					\
		 _(1.0) / magnitude.y,					\
		 _(1.0) / magnitude.z);					\
	}


Q_IMPLEMENTATION_REAL_3D(Float,	  float,   Q_FLOAT,   Q_FLOAT_EPSILON  )
Q_IMPLEMENTATION_REAL_3D(Double,  double,  Q_DOUBLE,  Q_DOUBLE_EPSILON )
Q_IMPLEMENTATION_REAL_3D(LDouble, ldouble, Q_LDOUBLE, Q_LDOUBLE_EPSILON)


/* MARK: - Default real type definitions */


#if defined(Q_USE_REAL_FLOAT)

#	define q_3d			q_3d_float
#	define q_3d_zero		q_3d_float_zero
#	define q_3d_are_equal		q_3d_float_are_equal
#	define q_3d_are_perpendicular	q_3d_float_are_perpendicular
#	define q_3d_swap		q_3d_float_swap
#	define q_3d_contains		q_3d_float_contains
#	define q_3d_add			q_3d_float_add
#	define q_3d_subtract		q_3d_float_subtract
#	define q_3d_multiply		q_3d_float_multiply
#	define q_3d_divide		q_3d_float_divide
#	define q_3d_dot_product		q_3d_float_dot_product
#	define q_3d_cross_product	q_3d_float_cross_product
#	define q_3d_minimum		q_3d_float_minimum
#	define q_3d_maximum		q_3d_float_maximum
#	define q_3d_middle		q_3d_float_middle
#	define q_3d_fit			q_3d_float_fit
#	define q_3d_lerp		q_3d_float_lerp
#	define q_3d_from_scalar		q_3d_float_from_scalar
#	define q_3d_is_zero		q_3d_float_is_zero
#	define q_3d_negative		q_3d_float_negative
#	define q_3d_absolute		q_3d_float_absolute
#	define q_3d_reciprocal		q_3d_float_reciprocal
#	define q_3d_inner_sum		q_3d_float_inner_sum
#	define q_3d_inner_product	q_3d_float_inner_product
#	define q_3d_inner_average	q_3d_float_inner_average
#	define q_3d_square_length	q_3d_float_square_length
#	define q_3d_multiply_by_scalar	q_3d_float_multiply_by_scalar
#	define q_3d_divide_by_scalar	q_3d_float_divide_by_scalar
#	define q_3d_clamp		q_3d_float_clamp
#	define q_3d_cube_clamp		q_3d_float_cube_clamp
#	define q_3d_rotated_as_axes	q_3d_float_rotated_as_axes

#elif defined(Q_USE_REAL_LDOUBLE)

#	define q_3d			q_3d_ldouble
#	define q_3d_zero		q_3d_ldouble_zero
#	define q_3d_are_equal		q_3d_ldouble_are_equal
#	define q_3d_are_perpendicular	q_3d_ldouble_are_perpendicular
#	define q_3d_swap		q_3d_ldouble_swap
#	define q_3d_contains		q_3d_ldouble_contains
#	define q_3d_add			q_3d_ldouble_add
#	define q_3d_subtract		q_3d_ldouble_subtract
#	define q_3d_multiply		q_3d_ldouble_multiply
#	define q_3d_divide		q_3d_ldouble_divide
#	define q_3d_dot_product		q_3d_ldouble_dot_product
#	define q_3d_cross_product	q_3d_ldouble_cross_product
#	define q_3d_minimum		q_3d_ldouble_minimum
#	define q_3d_maximum		q_3d_ldouble_maximum
#	define q_3d_middle		q_3d_ldouble_middle
#	define q_3d_fit			q_3d_ldouble_fit
#	define q_3d_lerp		q_3d_ldouble_lerp
#	define q_3d_from_scalar		q_3d_ldouble_from_scalar
#	define q_3d_is_zero		q_3d_ldouble_is_zero
#	define q_3d_negative		q_3d_ldouble_negative
#	define q_3d_absolute		q_3d_ldouble_absolute
#	define q_3d_reciprocal		q_3d_ldouble_reciprocal
#	define q_3d_inner_sum		q_3d_ldouble_inner_sum
#	define q_3d_inner_product	q_3d_ldouble_inner_product
#	define q_3d_inner_average	q_3d_ldouble_inner_average
#	define q_3d_square_length	q_3d_ldouble_square_length
#	define q_3d_multiply_by_scalar	q_3d_ldouble_multiply_by_scalar
#	define q_3d_divide_by_scalar	q_3d_ldouble_divide_by_scalar
#	define q_3d_clamp		q_3d_ldouble_clamp
#	define q_3d_cube_clamp		q_3d_ldouble_cube_clamp
#	define q_3d_rotated_as_axes	q_3d_ldouble_rotated_as_axes

#else

#	define q_3d			q_3d_double
#	define q_3d_zero		q_3d_double_zero
#	define q_3d_are_equal		q_3d_double_are_equal
#	define q_3d_are_perpendicular	q_3d_double_are_perpendicular
#	define q_3d_swap		q_3d_double_swap
#	define q_3d_contains		q_3d_double_contains
#	define q_3d_add			q_3d_double_add
#	define q_3d_subtract		q_3d_double_subtract
#	define q_3d_multiply		q_3d_double_multiply
#	define q_3d_divide		q_3d_double_divide
#	define q_3d_dot_product		q_3d_double_dot_product
#	define q_3d_cross_product	q_3d_double_cross_product
#	define q_3d_minimum		q_3d_double_minimum
#	define q_3d_maximum		q_3d_double_maximum
#	define q_3d_middle		q_3d_double_middle
#	define q_3d_fit			q_3d_double_fit
#	define q_3d_lerp		q_3d_double_lerp
#	define q_3d_from_scalar		q_3d_double_from_scalar
#	define q_3d_is_zero		q_3d_double_is_zero
#	define q_3d_negative		q_3d_double_negative
#	define q_3d_absolute		q_3d_double_absolute
#	define q_3d_reciprocal		q_3d_double_reciprocal
#	define q_3d_inner_sum		q_3d_double_inner_sum
#	define q_3d_inner_product	q_3d_double_inner_product
#	define q_3d_inner_average	q_3d_double_inner_average
#	define q_3d_square_length	q_3d_double_square_length
#	define q_3d_multiply_by_scalar	q_3d_double_multiply_by_scalar
#	define q_3d_divide_by_scalar	q_3d_double_divide_by_scalar
#	define q_3d_clamp		q_3d_double_clamp
#	define q_3d_cube_clamp		q_3d_double_cube_clamp
#	define q_3d_rotated_as_axes	q_3d_double_rotated_as_axes

#endif

#endif /* __Q_functions_Q3D_H__ */
