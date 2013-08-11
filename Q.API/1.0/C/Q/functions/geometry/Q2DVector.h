/* Q API - functions/geometry/Q2DVector.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2013 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_functions_geometry_Q2DVector_H__
#define __Q_functions_geometry_Q2DVector_H__

#include <Q/types/geometry.h>
#include <Q/functions/Q2D.h>

#ifndef Q_2D_VECTOR_EXPORT
#	define Q_2D_VECTOR_EXPORT Q_INLINE
#endif

#if Q_C_HAS(COMPOUND_LITERAL)

#	define	q_2d_float_vector(a_x, a_y,   b_x, b_y) \
		((Q2DFloatVector){a_x, a_y}, {b_x, b_y})

#	define	q_2d_double_vector(a_x, a_y,   b_x, b_y) \
		((Q2DDoubleVector){a_x, a_y}, {b_x, b_y})

#	define	q_2d_ldouble_vector(a_x, a_y,	b_x, b_y) \
		((Q2DLDoubleVector){a_x, a_y}, {b_x, b_y})

#	define Q_2D_VECTOR_NEW(Type, type)

#else

#	define Q_2D_VECTOR_NEW(Type, type)				\
									\
	Q_INLINE Q2D##Type##Vector q_2d_##type##_vector(		\
		q##type a_x,						\
		q##type a_y,						\
		q##type b_x,						\
		q##type b_y						\
	)								\
		{							\
		Q2D##Type##Vector vector = {{a_x, a_y}, {b_x, b_y}};	\
		return vector;						\
		}

#endif

#define q_2d_float_vector_zero	 q_2d_float_vector(0.0F, 0.0F, 0.0F, 0.0F)
#define q_2d_double_vector_zero	 q_2d_float_vector(0.0,  0.0,  0.0,  0.0 )
#define q_2d_ldouble_vector_zero q_2d_float_vector(0.0L, 0.0L, 0.0L, 0.0L)


#define Q_IMPLEMENTATION_2D_VECTOR(Type, type)		\
							\
							\
Q_2D_VECTOR_NEW(Type, type)				\
							\
							\
Q_2D_VECTOR_EXPORT					\
qboolean q_2d_##type##_vector_are_equal(		\
	Q2D##Type##Vector a,				\
	Q2D##Type##Vector b				\
)							\
	{						\
	return	q_2d_##type##_are_equal(a.a, b.a) &&	\
		q_2d_##type##_are_equal(a.b, b.b);	\
	}


Q_IMPLEMENTATION_2D_VECTOR(Float,   float  )
Q_IMPLEMENTATION_2D_VECTOR(Double,  double )
Q_IMPLEMENTATION_2D_VECTOR(LDouble, ldouble)
#undef Q_2D_VECTOR_NEW


/* MARK: - Default real type definitions */


#if defined(Q_USE_REAL_FLOAT)

#	define q_2d_vector		q_2d_float_vector
#	define q_2d_vector_zero		q_2d_float_vector_zero
#	define q_2d_vector_are_equal	q_2d_float_vector_are_equal

#elif defined(Q_USE_REAL_LDOUBLE)

#	define q_2d_vector		q_2d_ldouble_vector
#	define q_2d_vector_zero		q_2d_ldouble_vector_zero
#	define q_2d_vector_are_equal	q_2d_ldouble_vector_are_equal

#else

#	define q_2d_vector		q_2d_double_vector
#	define q_2d_vector_zero		q_2d_double_vector_zero
#	define q_2d_vector_are_equal	q_2d_double_vector_are_equal

#endif

#endif /* __Q_functions_geometry_Q2DVector_H__ */
