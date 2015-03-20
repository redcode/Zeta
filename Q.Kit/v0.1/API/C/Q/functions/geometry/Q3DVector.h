/* Q Kit C API - functions/geometry/Q3DVector.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_functions_geometry_Q3DVector_H__
#define __Q_functions_geometry_Q3DVector_H__

#include <Q/functions/geometry/constructors.h>
#include <Q/functions/base/Q3DValue.h>


#define Q_IMPLEMENTATION_3D_VECTOR(Type, type)					\
										\
										\
Q_INLINE qboolean q_3d_##type##_vector_are_equal(				\
	Q3D##Type##Vector a,							\
	Q3D##Type##Vector b							\
)										\
	{									\
	return	q_3d_##type##_are_equal(a.a, b.a) &&				\
		q_3d_##type##_are_equal(a.b, b.b);				\
	}									\
										\
										\
Q_INLINE qboolean q_3d_##type##_vector_are_perpendicular(			\
	Q3D##Type##Vector a,							\
	Q3D##Type##Vector b							\
)										\
	{									\
	return q_3d_##type##_are_perpendicular					\
		(q_3d_##type##_subtract(a.b, a.a),				\
		 q_3d_##type##_subtract(b.b, b.a));				\
	}									\
										\
										\
Q_INLINE qboolean q_3d_##type##_vector_is_zero(Q3D##Type##Vector object)	\
	{									\
	return	q_3d_##type##_is_zero(object.a) &&				\
		q_3d_##type##_is_zero(object.b);				\
	}									\
										\
										\
Q_INLINE									\
Q3D##Type##Vector q_3d_##type##_vector_reversed(Q3D##Type##Vector object)	\
	{									\
	return q_3d_##type##_vector						\
		(object.b.x, object.b.y, object.b.z,				\
		 object.a.x, object.a.y, object.a.z);				\
	}									\


Q_IMPLEMENTATION_3D_VECTOR(Float,   float  )
Q_IMPLEMENTATION_3D_VECTOR(Double,  double )
Q_IMPLEMENTATION_3D_VECTOR(LDouble, ldouble)


/* MARK: - Default real type definitions */

#define q_3d_vector_are_equal	      Q_JOIN_3(q_3d_, Q_REAL_FIXED_TYPE_name, _vector_are_equal	       )
#define q_3d_vector_are_perpendicular Q_JOIN_3(q_3d_, Q_REAL_FIXED_TYPE_name, _vector_are_perpendicular)
#define q_3d_vector_is_zero	      Q_JOIN_3(q_3d_, Q_REAL_FIXED_TYPE_name, _vector_is_zero	       )
#define q_3d_vector_reversed	      Q_JOIN_3(q_3d_, Q_REAL_FIXED_TYPE_name, _vector_reversed	       )

#endif /* __Q_functions_geometry_Q3DVector_H__ */
