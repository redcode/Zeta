/* Q API - functions/Q2DValue.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2013 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_functions_Q2DValue_H__
#define __Q_functions_Q2DValue_H__

#include <Q/functions/value.h>
#include <Q/inspection/language.h>

#ifndef Q_2D_VALUE_EXPORT
#	define Q_2D_VALUE_EXPORT Q_INLINE
#endif

#if Q_C_HAS(COMPOUND_LITERAL)

#	define q_2d_uchar(  x, y) ((Q2DUChar  ){x, y})
#	define q_2d_ushort( x, y) ((Q2DUShort ){x, y})
#	define q_2d_uint(   x, y) ((Q2DUInt   ){x, y})
#	define q_2d_ulong(  x, y) ((Q2DULong  ){x, y})
#	define q_2d_ullong( x, y) ((Q2DULLong ){x, y})
#	define q_2d_char(   x, y) ((Q2DChar   ){x, y})
#	define q_2d_short(  x, y) ((Q2DShort  ){x, y})
#	define q_2d_int(    x, y) ((Q2DInt    ){x, y})
#	define q_2d_long(   x, y) ((Q2DLong   ){x, y})
#	define q_2d_llong(  x, y) ((Q2DLLong  ){x, y})
#	define q_2d_float(  x, y) ((Q2DFloat  ){x, y})
#	define q_2d_double( x, y) ((Q2DDouble ){x, y})
#	define q_2d_ldouble(x, y) ((Q2DLDouble){x, y})
#	define q_2d_uint8(  x, y) ((Q2DUInt8  ){x, y})
#	define q_2d_uint16( x, y) ((Q2DUInt16 ){x, y})
#	define q_2d_uint32( x, y) ((Q2DUInt32 ){x, y})
#	define q_2d_uint64( x, y) ((Q2DUInt64 ){x, y})
#	define q_2d_int8(   x, y) ((Q2DInt8   ){x, y})
#	define q_2d_int16(  x, y) ((Q2DInt16  ){x, y})
#	define q_2d_int32(  x, y) ((Q2DInt32  ){x, y})
#	define q_2d_int64(  x, y) ((Q2DInt64  ){x, y})
#	define q_2d_size(   x, y) ((Q2DSize   ){x, y})
#	define q_2d_uintptr(x, y) ((Q2DUIntPtr){x, y})
#	define q_2d_uinttop(x, y) ((Q2DUIntTop){x, y})
#	define q_2d_uintmax(x, y) ((Q2DUIntMax){x, y})
#	define q_2d_ssize(  x, y) ((Q2DSSize  ){x, y})
#	define q_2d_intptr( x, y) ((Q2DIntPtr ){x, y})
#	define q_2d_inttop( x, y) ((Q2DIntTop ){x, y})
#	define q_2d_intmax( x, y) ((Q2DIntMax ){x, y})
#	define q_2d_natural(x, y) ((Q2DNatural){x, y})
#	define q_2d_integer(x, y) ((Q2DInteger){x, y})
#	define q_2d_real(   x, y) ((Q2DReal   ){x, y})

#	define Q_2D_VALUE_NEW(Type, type)

#else

#	define Q_2D_VALUE_NEW(Type, type)				\
									\
	Q_INLINE Q##Type q_2d_##type(q##type x, q##type y)		\
		{Q##Type magnitude = {x, y}; return magnitude;}

#endif

#define q_2d_uchar_zero		q_2d_uchar  (0, 0)
#define q_2d_ushort_zero	q_2d_ushort (0, 0)
#define q_2d_uint_zero		q_2d_uint   (0, 0)
#define q_2d_ulong_zero		q_2d_ulong  (0, 0)
#define q_2d_ullong_zero	q_2d_ullong (0, 0)
#define q_2d_char_zero		q_2d_char   (0, 0)
#define q_2d_short_zero		q_2d_short  (0, 0)
#define q_2d_int_zero		q_2d_int    (0, 0)
#define q_2d_long_zero		q_2d_long   (0, 0)
#define q_2d_llong_zero		q_2d_llong  (0, 0)
#define q_2d_float_zero		q_2d_float  (0.0F, 0.0F)
#define q_2d_double_zero	q_2d_double (0.0,  0.0 )
#define q_2d_ldouble_zero	q_2d_ldouble(0.0L, 0.0L)
#define q_2d_uint8_zero		q_2d_uint8  (0, 0)
#define q_2d_uint16_zero	q_2d_uint16 (0, 0)
#define q_2d_uint32_zero	q_2d_uint32 (0, 0)
#define q_2d_uint64_zero	q_2d_uint64 (0, 0)
#define q_2d_int8_zero		q_2d_int8   (0, 0)
#define q_2d_int16_zero		q_2d_int16  (0, 0)
#define q_2d_int32_zero		q_2d_int32  (0, 0)
#define q_2d_int64_zero		q_2d_int64  (0, 0)
#define q_2d_size_zero		q_2d_size   (0, 0)
#define q_2d_uintptr_zero	q_2d_uintptr(0, 0)
#define q_2d_uinttop_zero	q_2d_uinttop(0, 0)
#define q_2d_uintmax_zero	q_2d_uintmax(0, 0)
#define q_2d_ssize_zero		q_2d_ssize  (0, 0)
#define q_2d_intptr_zero	q_2d_intptr (0, 0)
#define q_2d_inttop_zero	q_2d_inttop (0, 0)
#define q_2d_intmax_zero	q_2d_intmax (0, 0)
#define q_2d_natural_zero	q_2d_natural(0, 0)
#define q_2d_integer_zero	q_2d_integer(0, 0)
#define q_2d_real_zero		q_2d_real   (Q_REAL(0.0), Q_REAL(0.0))


#define Q_IMPLEMENTATION_2D_VALUE(Type, type)					\
										\
										\
Q_2D_NEW(Type, type)								\
										\
										\
Q_2D_VALUE_EXPORT								\
qboolean q_2d_##type##_are_equal(Q2D##Type a, Q2D##Type b)			\
	{return a.x == b.x && a.y == b.y;}					\
										\
										\
Q_2D_VALUE_EXPORT								\
qboolean q_2d_##type##_contains(Q2D##Type a, Q2D##Type b)			\
	{return (b.x <= a.x && b.y <= a.y);}					\
										\
										\
Q_2D_VALUE_EXPORT								\
Q2D##Type q_2d_##type##_add(Q2D##Type a, Q2D##Type b)				\
	{return q_2d_##type(a.x + b.x, a.y + b.y);}				\
										\
										\
Q_2D_VALUE_EXPORT								\
Q2D##Type q_2d_##type##_subtract(Q2D##Type a, Q2D##Type b)			\
	{return q_2d_##type(a.x - b.x, a.y - b.y);}				\
										\
										\
Q_2D_VALUE_EXPORT								\
Q2D##Type q_2d_##type##_multiply(Q2D##Type a, Q2D##Type b)			\
	{return q_2d_##type(a.x * b.x, a.y * b.y);}				\
										\
										\
Q_2D_VALUE_EXPORT								\
Q2D##Type q_2d_##type##_divide(Q2D##Type a, Q2D##Type b)			\
	{return q_2d_##type(a.x / b.x, a.y / b.y);}				\
										\
										\
Q_2D_VALUE_EXPORT								\
q##type q_2d_##type##_dot_product(Q2D##Type a, Q2D##Type b)			\
	{return a.x * b.x + a.y * b.y;}						\
										\
										\
Q_2D_VALUE_EXPORT								\
q##type q_2d_##type##_cross_product(Q2D##Type a, Q2D##Type b)			\
	{return a.x * b.y - a.y * b.x;}						\
										\
										\
Q_2D_VALUE_EXPORT								\
Q2D##Type q_2d_##type##_minimum(Q2D##Type a, Q2D##Type b)			\
	{									\
	return q_2d_##type							\
		(q_##type##_minimum(a.x, b.x), q_##type##_minimum(a.y, b.y));	\
	}									\
										\
										\
Q_2D_VALUE_EXPORT								\
Q2D##Type q_2d_##type##_maximum(Q2D##Type a, Q2D##Type b)			\
	{									\
	return q_2d_##type							\
		(q_##type##_maximum(a.x, b.x), q_##type##_maximum(a.y, b.y));	\
	}									\
										\
										\
Q_2D_VALUE_EXPORT								\
Q2D##Type q_2d_##type##_middle(Q2D##Type a, Q2D##Type b)			\
	{									\
	return q_2d_##type							\
		((a.x + b.x) / (q##type)2, (a.y + b.y) / (q##type)2);		\
	}									\
										\
										\
Q_2D_VALUE_EXPORT								\
Q2D##Type q_2d_##type##_fit(Q2D##Type a, Q2D##Type b)				\
	{									\
	return a.y / a.x > b.y / b.x						\
		? q_2d_##type(a.x * b.y / a.y, b.y)				\
		: q_2d_##type(b.x, a.y * b.x / a.x);				\
	}									\
										\
										\
Q_2D_VALUE_EXPORT								\
qboolean q_2d_##type##_is_zero(Q2D##Type magnitude)				\
	{return magnitude.x == (q##type)0 && magnitude.y == (q##type)0;}	\
										\
										\
Q_2D_VALUE_EXPORT								\
Q2D##Type q_2d_##type##_negative(Q2D##Type magnitude)				\
	{return q_2d_##type(-magnitude.x, -magnitude.y);}			\
										\
										\
Q_2D_VALUE_EXPORT								\
q##type q_2d_##type##_area(Q2D##Type magnitude)					\
	{return magnitude.x * magnitude.y;}					\
										\
										\
Q_2D_VALUE_EXPORT								\
q##type q_2d_##type##_square_length(Q2D##Type magnitude)			\
	{return q_2d_##type##_dot_product(magnitude, magnitude);}		\
										\
										\
Q_2D_VALUE_EXPORT								\
Q2D##Type q_2d_##type##_multiply_by_scalar(Q2D##Type magnitude, q##type scalar)	\
	{return q_2d_##type(magnitude.x * scalar, magnitude.y * scalar);}	\
										\
										\
Q_2D_VALUE_EXPORT								\
Q2D##Type q_2d_##type##_divide_by_scalar(Q2D##Type magnitude, q##type scalar)	\
	{return q_2d_##type(magnitude.x / scalar, magnitude.y / scalar);}


Q_IMPLEMENTATION_2D_VALUE(UChar,   uchar  )
Q_IMPLEMENTATION_2D_VALUE(UShort,  ushort )
Q_IMPLEMENTATION_2D_VALUE(UInt,	   uint	  )
Q_IMPLEMENTATION_2D_VALUE(ULong,   ulong  )
Q_IMPLEMENTATION_2D_VALUE(ULLong,  ullong )
Q_IMPLEMENTATION_2D_VALUE(Char,	   char	  )
Q_IMPLEMENTATION_2D_VALUE(Short,   short  )
Q_IMPLEMENTATION_2D_VALUE(Int,	   int	  )
Q_IMPLEMENTATION_2D_VALUE(Long,	   long	  )
Q_IMPLEMENTATION_2D_VALUE(LLong,   llong  )
Q_IMPLEMENTATION_2D_VALUE(Float,   float  )
Q_IMPLEMENTATION_2D_VALUE(Double,  double )
Q_IMPLEMENTATION_2D_VALUE(LDouble, ldouble)
Q_IMPLEMENTATION_2D_VALUE(UInt8,   uint8  )
Q_IMPLEMENTATION_2D_VALUE(UInt16,  uint16 )
Q_IMPLEMENTATION_2D_VALUE(UInt32,  uint32 )
Q_IMPLEMENTATION_2D_VALUE(UInt64,  uint64 )
Q_IMPLEMENTATION_2D_VALUE(Int8,	   int8	  )
Q_IMPLEMENTATION_2D_VALUE(Int16,   int16  )
Q_IMPLEMENTATION_2D_VALUE(Int32,   int32  )
Q_IMPLEMENTATION_2D_VALUE(Int64,   int64  )
Q_IMPLEMENTATION_2D_VALUE(Size,	   size	  )
Q_IMPLEMENTATION_2D_VALUE(UIntPtr, uintptr)
Q_IMPLEMENTATION_2D_VALUE(UIntTop, uinttop)
Q_IMPLEMENTATION_2D_VALUE(UIntMax, uintmax)
Q_IMPLEMENTATION_2D_VALUE(SSize,   ssize  )
Q_IMPLEMENTATION_2D_VALUE(IntPtr,  intptr )
Q_IMPLEMENTATION_2D_VALUE(IntTop,  inttop )
Q_IMPLEMENTATION_2D_VALUE(IntMax,  intmax )
Q_IMPLEMENTATION_2D_VALUE(Natural, natural)
Q_IMPLEMENTATION_2D_VALUE(Integer, integer)
Q_IMPLEMENTATION_2D_VALUE(Real,	   real	  )

#undef Q_2D_VALUE_NEW

#endif /* __Q_functions_Q2DValue_H__ */
