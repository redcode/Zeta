/* Q API - functions/geometry/Q2DVector.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_functions_geometry_Q2DVector_H__
#define __Q_functions_geometry_Q2DVector_H__

#include <Q/functions/geometry/constructors.h>
#include <Q/functions/base/Q2D.h>


#define Q_IMPLEMENTATION_2D_VECTOR(Type, type)					\
										\
										\
Q_INLINE qboolean q_2d_##type##_vector_are_equal(				\
	Q2D##Type##Vector a,							\
	Q2D##Type##Vector b							\
)										\
	{									\
	return	q_2d_##type##_are_equal(a.a, b.a) &&				\
		q_2d_##type##_are_equal(a.b, b.b);				\
	}									\
										\
										\
Q_INLINE qboolean q_2d_##type##_vector_are_perpendicular(			\
	Q2D##Type##Vector a,							\
	Q2D##Type##Vector b							\
)										\
	{									\
	return q_2d_##type##_are_perpendicular					\
		(q_2d_##type##_subtract(a.b, a.a),				\
		 q_2d_##type##_subtract(b.b, b.a));				\
	}									\
										\
										\
Q_INLINE qboolean q_2d_##type##_vector_is_zero(Q2D##Type##Vector vector)	\
	{									\
	return	q_2d_##type##_is_zero(vector.a) &&				\
		q_2d_##type##_is_zero(vector.b);				\
	}									\
										\
										\
Q_INLINE									\
Q2D##Type##Vector q_2d_##type##_vector_reversed(Q2D##Type##Vector vector)	\
	{									\
	return q_2d_##type##_vector						\
		(vector.b.x, vector.b.y, vector.a.x, vector.a.y);		\
	}									\


Q_IMPLEMENTATION_2D_VECTOR(Float,   float  )
Q_IMPLEMENTATION_2D_VECTOR(Double,  double )
Q_IMPLEMENTATION_2D_VECTOR(LDouble, ldouble)


/* MARK: - Default real type definitions */

#if defined(Q_USE_REAL_FLOAT)

#	define q_2d_vector_are_equal		q_2d_float_vector_are_equal
#	define q_2d_vector_are_perpendicular	q_2d_float_vector_are_perpendicular
#	define q_2d_vector_is_zero		q_2d_float_vector_is_zero
#	define q_2d_vector_reversed		q_2d_float_vector_reversed

#elif defined(Q_USE_REAL_LDOUBLE)

#	define q_2d_vector_are_equal		q_2d_ldouble_vector_are_equal
#	define q_2d_vector_are_perpendicular	q_2d_ldouble_vector_are_perpendicular
#	define q_2d_vector_is_zero		q_2d_ldouble_vector_is_zero
#	define q_2d_vector_reversed		q_2d_ldouble_vector_reversed

#else

#	define q_2d_vector_are_equal		q_2d_double_vector_are_equal
#	define q_2d_vector_are_perpendicular	q_2d_double_vector_are_perpendicular
#	define q_2d_vector_is_zero		q_2d_double_vector_is_zero
#	define q_2d_vector_reversed		q_2d_double_vector_reversed

#endif

#endif /* __Q_functions_geometry_Q2DVector_H__ */
