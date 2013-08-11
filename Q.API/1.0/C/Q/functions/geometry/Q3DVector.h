/* Q API - functions/geometry/Q3DVector.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2013 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_functions_geometry_Q3DVector_H__
#define __Q_functions_geometry_Q3DVector_H__

#include <Q/types/geometry.h>
#include <Q/functions/Q3D.h>

#ifndef Q_3D_VECTOR_EXPORT
#	define Q_3D_VECTOR_EXPORT Q_INLINE
#endif

#if Q_C_HAS(COMPOUND_LITERAL)

#	define  q_3d_float_vector(a_x, a_y, a_z,   b_x, b_y, b_z) \
		((Q3DFloatVector){a_x, a_y, a_z}, {b_x, b_y, b_z})

#	define	q_3d_double_vector(a_x, a_y, a_z,   b_x, b_y, b_z) \
		((Q3DDoubleVector){a_x, a_y, a_z}, {b_x, b_y, b_z})

#	define	q_3d_ldouble_vector(a_x, a_y, a_z,   b_x, b_y, b_z) \
		((Q3DLDoubleVector){a_x, a_y, a_z}, {b_x, b_y, b_z})

#	define Q_3D_VECTOR_NEW(Type, type)

#else

#	define Q_3D_VECTOR_NEW(Type, type)					\
										\
	Q_INLINE Q3D##Type##Vector q_3d_##type##_vector(			\
		q##type a_x,							\
		q##type a_y,							\
		q##type a_z,							\
		q##type b_x,							\
		q##type b_y,							\
		q##type b_z							\
	)									\
		{								\
		Q3D##Type##Vector vector = {{a_x, a_y, a_z}, {b_x, b_y, b_z}};	\
		return vector;							\
		}

#endif

#define q_3d_float_vector_zero	 q_3d_float_vector(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f)
#define q_3d_double_vector_zero	 q_3d_float_vector(0.0,  0.0,  0.0,  0.0,  0.0,  0.0 )
#define q_3d_ldouble_vector_zero q_3d_float_vector(0.0L, 0.0L, 0.0L, 0.0L, 0.0L, 0.0L)


#define Q_IMPLEMENTATION_3D_VECTOR(Type, type)		\
							\
							\
Q_3D_VECTOR_NEW(Type, type)				\
							\
							\
Q_3D_VECTOR_EXPORT					\
qboolean q_3d_##type##_vector_are_equal(		\
	Q3D##Type##Vector a,				\
	Q3D##Type##Vector b				\
)							\
	{						\
	return	q_3d_##type##_are_equal(a.a, b.a) &&	\
		q_3d_##type##_are_equal(a.b, b.b);	\
	}


Q_IMPLEMENTATION_3D_VECTOR(Float,   float  )
Q_IMPLEMENTATION_3D_VECTOR(Double,  double )
Q_IMPLEMENTATION_3D_VECTOR(LDouble, ldouble)
#undef Q_3D_VECTOR_NEW


/* MARK: - Default real type definitions */


#if defined(Q_USE_REAL_FLOAT)

#	define q_3d_vector		q_3d_float_vector
#	define q_3d_vector_zero		q_3d_float_vector_zero
#	define q_3d_vector_are_equal	q_3d_float_vector_are_equal

#elif defined(Q_USE_REAL_LDOUBLE)

#	define q_3d_vector		q_3d_ldouble_vector
#	define q_3d_vector_zero		q_3d_ldouble_vector_zero
#	define q_3d_vector_are_equal	q_3d_ldouble_vector_are_equal

#else

#	define q_3d_vector		q_3d_double_vector
#	define q_3d_vector_zero		q_3d_double_vector_zero
#	define q_3d_vector_are_equal	q_3d_double_vector_are_equal

#endif

#endif /* __Q_functions_geometry_Q3DVector_H__ */
