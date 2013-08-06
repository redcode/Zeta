/* Q API - functions/Q3DValue.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2013 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_functions_Q3DValue_H__
#define __Q_functions_Q3DValue_H__

#include <Q/functions/value.h>
#include <Q/inspection/language.h>

#ifndef Q_3D_VALUE_EXPORT
#	define Q_3D_VALUE_EXPORT Q_INLINE
#endif

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
						
#	define Q_3D_VALUE_NEW(Type, type)

#else

#	define Q_3D_VALUE_NEW(Type, type)				\
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


#define Q_IMPLEMENTATION_NATURAL_3D_VALUE(Type, type)				\
										\
										\
Q_3D_VALUE_NEW(Type, type)							\
										\
										\
Q_3D_VALUE_EXPORT								\
qboolean q_3d_##type##_are_equal(Q3D##Type a, Q3D##Type b)			\
	{return a.x == b.x && a.y == b.y && a.z == b.z;}			\
										\
										\
Q_3D_VALUE_EXPORT								\
void q_##3d_##type##_swap(Q3D##Type *a, Q3D##Type *b)				\
	{									\
	Q3D##Type t = *a;							\
										\
	*a = *b;								\
	*b = t;									\
	}									\
										\
										\
Q_3D_VALUE_EXPORT								\
qboolean q_3d_##type##_contains(Q3D##Type a, Q3D##Type b)			\
	{return b.x <= a.x && b.y <= a.y && b.z <= a.z;}			\
										\
										\
Q_3D_VALUE_EXPORT								\
Q3D##Type q_3d_##type##_add(Q3D##Type a, Q3D##Type b)				\
	{return q_3d_##type(a.x + b.x, a.y + b.y, a.z + b.z);}			\
										\
										\
Q_3D_VALUE_EXPORT								\
Q3D##Type q_3d_##type##_subtract(Q3D##Type a, Q3D##Type b)			\
	{return q_3d_##type(a.x - b.x, a.y - b.y, a.z - b.z);}			\
										\
										\
Q_3D_VALUE_EXPORT								\
Q3D##Type q_3d_##type##_multiply(Q3D##Type a, Q3D##Type b)			\
	{return q_3d_##type(a.x * b.x, a.y * b.y, a.z * b.z);}			\
										\
										\
Q_3D_VALUE_EXPORT								\
Q3D##Type q_3d_##type##_divide(Q3D##Type a, Q3D##Type b)			\
	{return q_3d_##type(a.x / b.x, a.y / b.y, a.z / b.z);}			\
										\
										\
Q_3D_VALUE_EXPORT								\
q##type q_3d_##type##_dot_product(Q3D##Type a, Q3D##Type b)			\
	{return a.x * b.x + a.y * b.y;} /* Terminar */				\
										\
										\
Q_3D_VALUE_EXPORT								\
q##type q_3d_##type##_cross_product(Q3D##Type a, Q3D##Type b)			\
	{return a.x * b.y - a.y * b.x;}	/* Terminar */				\
										\
										\
Q_3D_VALUE_EXPORT								\
Q3D##Type q_3d_##type##_minimum(Q3D##Type a, Q3D##Type b)			\
	{									\
	return q_3d_##type							\
		(q_##type##_minimum(a.x, b.x),					\
		 q_##type##_minimum(a.y, b.y),					\
		 q_##type##_minimum(a.z, b.z));					\
	}									\
										\
										\
Q_3D_VALUE_EXPORT								\
Q3D##Type q_3d_##type##_maximum(Q3D##Type a, Q3D##Type b)			\
	{									\
	return q_3d_##type							\
		(q_##type##_maximum(a.x, b.x),					\
		 q_##type##_maximum(a.y, b.y),					\
		 q_##type##_maximum(a.z, b.z));					\
	}									\
										\
										\
Q_3D_VALUE_EXPORT								\
Q3D##Type q_3d_##type##_middle(Q3D##Type a, Q3D##Type b)			\
	{									\
	return q_3d_##type							\
		((a.x + b.x) / (q##type)2,					\
		 (a.y + b.y) / (q##type)2,					\
		 (a.z + b.z) / (q##type)2);					\
	}									\
										\
										\
Q_3D_VALUE_EXPORT								\
Q3D##Type q_3d_##type##_fit(Q3D##Type a, Q3D##Type b)				\
	{									\
	return q_3d_##type##_zero;/*a.y / a.x > b.y / b.x			\
		? q_3d_##type(a.x * b.y / a.y, b.y)				\
		: q_3d_##type(b.x, a.y * b.x / a.x);*/				\
	} /* Terminar */							\
										\
										\
Q_3D_VALUE_EXPORT								\
qboolean q_3d_##type##_is_zero(Q3D##Type magnitude)				\
	{									\
	return	magnitude.x == (q##type)0 &&					\
		magnitude.y == (q##type)0 &&					\
		magnitude.z == (q##type)0;					\
	}									\
										\
										\
Q_3D_VALUE_EXPORT								\
q##type q_3d_##type##_volume(Q3D##Type magnitude)				\
	{return magnitude.x * magnitude.y * magnitude.z;}			\
										\
										\
Q_3D_VALUE_EXPORT								\
q##type q_3d_##type##_square_length(Q3D##Type magnitude) /* Terminar */		\
	{return q_3d_##type##_dot_product(magnitude, magnitude);}		\
										\
										\
Q_3D_VALUE_EXPORT								\
Q3D##Type q_3d_##type##_multiply_by_scalar(Q3D##Type magnitude, q##type scalar)	\
	{									\
	return q_3d_##type							\
		(magnitude.x * scalar,						\
		 magnitude.y * scalar,						\
		 magnitude.z * scalar);						\
	}									\
										\
										\
Q_3D_VALUE_EXPORT								\
Q3D##Type q_3d_##type##_divide_by_scalar(Q3D##Type magnitude, q##type scalar)	\
	{									\
	return q_3d_##type							\
		(magnitude.x / scalar,						\
		 magnitude.y / scalar,						\
		 magnitude.z / scalar);						\
	}									\
										\
										\
Q_3D_VALUE_EXPORT								\
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
Q_3D_VALUE_EXPORT								\
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
Q_3D_VALUE_EXPORT								\
Q3D##Type q_3d_##type##_rotated_as_axes(Q3D##Type magnitude, Q3DInt8 rotation)	\
	{									\
	if ((rotation.x % 4) & 1) q_##type##_swap(&magnitude.y, &magnitude.z);	\
	if ((rotation.y % 4) & 1) q_##type##_swap(&magnitude.x, &magnitude.z);	\
	if ((rotation.z % 4) & 1) q_##type##_swap(&magnitude.x, &magnitude.y);	\
										\
	return magnitude;							\
	}


Q_IMPLEMENTATION_NATURAL_3D_VALUE(UChar,   uchar  )
Q_IMPLEMENTATION_NATURAL_3D_VALUE(UShort,  ushort )
Q_IMPLEMENTATION_NATURAL_3D_VALUE(UInt,	   uint	  )
Q_IMPLEMENTATION_NATURAL_3D_VALUE(ULong,   ulong  )
Q_IMPLEMENTATION_NATURAL_3D_VALUE(ULLong,  ullong )
Q_IMPLEMENTATION_NATURAL_3D_VALUE(Char,	   char	  )
Q_IMPLEMENTATION_NATURAL_3D_VALUE(Short,   short  )
Q_IMPLEMENTATION_NATURAL_3D_VALUE(Int,	   int	  )
Q_IMPLEMENTATION_NATURAL_3D_VALUE(Long,	   long	  )
Q_IMPLEMENTATION_NATURAL_3D_VALUE(LLong,   llong  )
Q_IMPLEMENTATION_NATURAL_3D_VALUE(Float,   float  )
Q_IMPLEMENTATION_NATURAL_3D_VALUE(Double,  double )
Q_IMPLEMENTATION_NATURAL_3D_VALUE(LDouble, ldouble)
Q_IMPLEMENTATION_NATURAL_3D_VALUE(UInt8,   uint8  )
Q_IMPLEMENTATION_NATURAL_3D_VALUE(UInt16,  uint16 )
Q_IMPLEMENTATION_NATURAL_3D_VALUE(UInt32,  uint32 )
Q_IMPLEMENTATION_NATURAL_3D_VALUE(UInt64,  uint64 )
Q_IMPLEMENTATION_NATURAL_3D_VALUE(Int8,	   int8	  )
Q_IMPLEMENTATION_NATURAL_3D_VALUE(Int16,   int16  )
Q_IMPLEMENTATION_NATURAL_3D_VALUE(Int32,   int32  )
Q_IMPLEMENTATION_NATURAL_3D_VALUE(Int64,   int64  )
Q_IMPLEMENTATION_NATURAL_3D_VALUE(Size,	   size	  )
Q_IMPLEMENTATION_NATURAL_3D_VALUE(UIntPtr, uintptr)
Q_IMPLEMENTATION_NATURAL_3D_VALUE(UIntTop, uinttop)
Q_IMPLEMENTATION_NATURAL_3D_VALUE(UIntMax, uintmax)
Q_IMPLEMENTATION_NATURAL_3D_VALUE(SSize,   ssize  )
Q_IMPLEMENTATION_NATURAL_3D_VALUE(IntPtr,  intptr )
Q_IMPLEMENTATION_NATURAL_3D_VALUE(IntTop,  inttop )
Q_IMPLEMENTATION_NATURAL_3D_VALUE(IntMax,  intmax )
Q_IMPLEMENTATION_NATURAL_3D_VALUE(Natural, natural)
Q_IMPLEMENTATION_NATURAL_3D_VALUE(Integer, integer)
Q_IMPLEMENTATION_NATURAL_3D_VALUE(Real,	   real	  )
#undef Q_3D_VALUE_NEW


#define Q_IMPLEMENTATION_INTEGER_3D_VALUE(Type, type)			\
									\
									\
Q_3D_VALUE_EXPORT							\
Q3D##Type q_3d_##type##_negative(Q3D##Type magnitude)			\
	{return q_3d_##type(-magnitude.x, -magnitude.y, -magnitude.z);}	\
									\
									\
Q_3D_VALUE_EXPORT							\
Q3D##Type q_3d_##type##_absolute(Q3D##Type magnitude)			\
	{								\
	return q_3d_##type						\
		(q_##type##_absolute(magnitude.x),			\
		 q_##type##_absolute(magnitude.y),			\
		 q_##type##_absolute(magnitude.z));			\
	}


Q_IMPLEMENTATION_INTEGER_3D_VALUE(Char,	   char	  )
Q_IMPLEMENTATION_INTEGER_3D_VALUE(Short,   short  )
Q_IMPLEMENTATION_INTEGER_3D_VALUE(Int,	   int	  )
Q_IMPLEMENTATION_INTEGER_3D_VALUE(Long,	   long	  )
Q_IMPLEMENTATION_INTEGER_3D_VALUE(LLong,   llong  )
Q_IMPLEMENTATION_INTEGER_3D_VALUE(Float,   float  )
Q_IMPLEMENTATION_INTEGER_3D_VALUE(Double,  double )
Q_IMPLEMENTATION_INTEGER_3D_VALUE(LDouble, ldouble)
Q_IMPLEMENTATION_INTEGER_3D_VALUE(Int8,	   int8	  )
Q_IMPLEMENTATION_INTEGER_3D_VALUE(Int16,   int16  )
Q_IMPLEMENTATION_INTEGER_3D_VALUE(Int32,   int32  )
Q_IMPLEMENTATION_INTEGER_3D_VALUE(Int64,   int64  )
Q_IMPLEMENTATION_INTEGER_3D_VALUE(SSize,   ssize  )
Q_IMPLEMENTATION_INTEGER_3D_VALUE(IntPtr,  intptr )
Q_IMPLEMENTATION_INTEGER_3D_VALUE(IntTop,  inttop )
Q_IMPLEMENTATION_INTEGER_3D_VALUE(IntMax,  intmax )
Q_IMPLEMENTATION_INTEGER_3D_VALUE(Integer, integer)
Q_IMPLEMENTATION_INTEGER_3D_VALUE(Real,	   real	  )


#define Q_IMPLEMENTATION_REAL_3D_VALUE(Type, type)			\
									\
Q_3D_VALUE_EXPORT							\
Q3D##Type q_3d_##type##_lerp(Q3D##Type a, Q3D##Type b, q##type alpha)	\
	{								\
	return q_3d_##type						\
		(q_##type##_lerp(a.x, b.x, alpha),			\
		 q_##type##_lerp(a.y, b.y, alpha),			\
		 q_##type##_lerp(a.z, b.z, alpha));			\
	}


Q_IMPLEMENTATION_REAL_3D_VALUE(Float,	float  )
Q_IMPLEMENTATION_REAL_3D_VALUE(Double,	double )
Q_IMPLEMENTATION_REAL_3D_VALUE(LDouble,	ldouble)
Q_IMPLEMENTATION_REAL_3D_VALUE(Real,	real   )


#endif /* __Q_functions_Q3DValue_H__ */
