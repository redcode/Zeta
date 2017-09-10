/* Z Kit C API - functions/mathematics/geometry/euclidean/constructors.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2017 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_functions_mathematics_geometry_euclidean_constructors_H__
#define __Z_functions_mathematics_geometry_euclidean_constructors_H__

#include <Z/types/mathematics.h>

#if Z_LANGUAGE_HAS(C, COMPOUND_LITERAL)

#	define z_2d_line_int8(a_x, a_y, b_x, b_y)				   \
		((Z2DLineInt8){							   \
			{(zint8)(a_x), (zint8)(a_y)},				   \
			{(zint8)(b_x), (zint8)(b_y)}				   \
		})

#	define z_3d_line_int8(a_x, a_y, a_z, b_x, b_y, b_z)			   \
		((Z3DLineInt8){							   \
			{(zint8)(a_x), (zint8)(a_y), (zint8)(a_z)},		   \
			{(zint8)(b_x), (zint8)(b_y), (zint8)(b_z)}		   \
		})

#	define z_box_int8(point_x, point_y, point_z, size_x, size_y, size_z)	   \
		((ZBoxInt8){							   \
			{(zint8)(point_x), (zint8)(point_y), (zint8)(point_z)},	   \
			{(zint8)(size_x ), (zint8)(size_y ), (zint8)(size_z )}	   \
		})

#	define z_rectangle_int8(point_x, point_y, size_x, size_y)		   \
		((ZRectangleInt8){						   \
			{(zint8)(point_x), (zint8)(point_y)},			   \
			{(zint8)(size_x ), (zint8)(size_y )}			   \
		})

#	define z_2d_line_int16(a_x, a_y, b_x, b_y)				   \
		((Z2DLineInt16){						   \
			{(zint16)(a_x), (zint16)(a_y)},				   \
			{(zint16)(b_x), (zint16)(b_y)}				   \
		})

#	define z_3d_line_int16(a_x, a_y, a_z, b_x, b_y, b_z)			   \
		((Z3DLineInt16){						   \
			{(zint16)(a_x), (zint16)(a_y), (zint16)(a_z)},		   \
			{(zint16)(b_x), (zint16)(b_y), (zint16)(b_z)}		   \
		})

#	define z_box_int16(point_x, point_y, point_z, size_x, size_y, size_z)	   \
		((ZBoxInt16){							   \
			{(zint16)(point_x), (zint16)(point_y), (zint16)(point_z)}, \
			{(zint16)(size_x ), (zint16)(size_y ), (zint16)(size_z )}  \
		})

#	define z_rectangle_int16(point_x, point_y, size_x, size_y)		   \
		((ZRectangleInt16){						   \
			{(zint16)(point_x), (zint16)(point_y)},			   \
			{(zint16)(size_x ), (zint16)(size_y )}			   \
		})

#	define z_2d_line_int32(a_x, a_y, b_x, b_y)				   \
		((Z2DLineInt32){						   \
			{(zint32)(a_x), (zint32)(a_y)},				   \
			{(zint32)(b_x), (zint32)(b_y)}				   \
		})

#	define z_3d_line_int32(a_x, a_y, a_z, b_x, b_y, b_z)			   \
		((Z3DLineInt32){						   \
			{(zint32)(a_x), (zint32)(a_y), (zint32)(a_z)},		   \
			{(zint32)(b_x), (zint32)(b_y), (zint32)(b_z)}		   \
		})

#	define z_box_int32(point_x, point_y, point_z, size_x, size_y, size_z)	   \
		((ZBoxInt32){							   \
			{(zint32)(point_x), (zint32)(point_y), (zint32)(point_z)}, \
			{(zint32)(size_x ), (zint32)(size_y ), (zint32)(size_z )}  \
		})

#	define z_rectangle_int32(point_x, point_y, size_x, size_y)		   \
		((ZRectangleInt32){						   \
			{(zint32)(point_x), (zint32)(point_y)},			   \
			{(zint32)(size_x ), (zint32)(size_y )}			   \
		})

#	ifdef Z_INT64

#		define z_2d_line_int64(a_x, a_y, b_x, b_y)				   \
			((Z2DLineInt64){						   \
				{(zint64)(a_x), (zint64)(a_y)},				   \
				{(zint64)(b_x), (zint64)(b_y)}				   \
			})

#		define z_3d_line_int64(a_x, a_y, a_z, b_x, b_y, b_z)			   \
			((Z3DLineInt64){						   \
				{(zint64)(a_x), (zint64)(a_y), (zint64)(a_z)},		   \
				{(zint64)(b_x), (zint64)(b_y), (zint64)(b_z)}		   \
			})

#		define z_box_int64(point_x, point_y, point_z, size_x, size_y, size_z)	   \
			((ZBoxInt64){							   \
				{(zint64)(point_x), (zint64)(point_y), (zint64)(point_z)}, \
				{(zint64)(size_x ), (zint64)(size_y ), (zint64)(size_z )}  \
			})

#		define z_rectangle_int64(point_x, point_y, size_x, size_y)		   \
			((ZRectangleInt64){						   \
				{(zint64)(point_x), (zint64)(point_y)},			   \
				{(zint64)(size_x ), (zint64)(size_y )}			   \
			})

#	endif

#	ifdef Z_INT128

#		define z_2d_line_int128(a_x, a_y, b_x, b_y)				      \
			((Z2DLineInt128){						      \
				{(zint128)(a_x), (zint128)(a_y)},			      \
				{(zint128)(b_x), (zint128)(b_y)}			      \
			})

#		define z_3d_line_int128(a_x, a_y, a_z, b_x, b_y, b_z)			      \
			((Z3DLineInt128){						      \
				{(zint128)(a_x), (zint128)(a_y), (zint128)(a_z)},	      \
				{(zint128)(b_x), (zint128)(b_y), (zint128)(b_z)}	      \
			})

#		define z_box_int128(point_x, point_y, point_z, size_x, size_y, size_z)	      \
			((ZBoxInt128){							      \
				{(zint128)(point_x), (zint128)(point_y), (zint128)(point_z)}, \
				{(zint128)(size_x ), (zint128)(size_y ), (zint128)(size_z )}  \
			})

#		define z_rectangle_int128(point_x, point_y, size_x, size_y)		      \
			((ZRectangleInt128){						      \
				{(zint128)(point_x), (zint128)(point_y)},		      \
				{(zint128)(size_x ), (zint128)(size_y )}		      \
			})

#	endif

#	ifdef Z_FLOAT16

#		define z_2d_line_float16(a_x, a_y, b_x, b_y)					 \
			((Z2DLineFloat16){							 \
				{(zfloat16)(a_x), (zfloat16)(a_y)},				 \
				{(zfloat16)(b_x), (zfloat16)(b_y)}				 \
			})

#		define z_3d_line_float16(a_x, a_y, a_z, b_x, b_y, b_z)				 \
			((Z3DLineFloat16){							 \
				{(zfloat16)(a_x), (zfloat16)(a_y), (zfloat16)(a_z)},		 \
				{(zfloat16)(b_x), (zfloat16)(b_y), (zfloat16)(b_z)}		 \
			})

#		define z_box_float16(point_x, point_y, point_z, size_x, size_y, size_z)		 \
			((ZBoxFloat16){								 \
				{(zfloat16)(point_x), (zfloat16)(point_y), (zfloat16)(point_z)}, \
				{(zfloat16)(size_x ), (zfloat16)(size_y ), (zfloat16)(size_z )}	 \
			})

#		define z_circle_float16(point_x, point_y, radius)				 \
			((ZCircleFloat16){							 \
				{(zfloat16)(x), (zfloat16)(y)},					 \
				(zfloat16)(radius)						 \
			})

#		define z_rectangle_float16(point_x, point_y, size_x, size_y)			 \
			((ZRectangleFloat16){							 \
				{(zfloat16)(point_x), (zfloat16)(point_y)},			 \
				{(zfloat16)(size_x ), (zfloat16)(size_y )}			 \
			})

#		define z_sphere_float16(point_x, point_y, point_z, radius)			 \
			((ZCircleFloat16){							 \
				{(zfloat16)(point_x), (zfloat16)(point_y), (zfloat16)(point_z)}, \
				(zfloat16)(radius)						 \
			})

#	endif

#	ifdef Z_FLOAT24

#		define z_2d_line_float24(a_x, a_y, b_x, b_y)					 \
			((Z2DLineFloat24){							 \
				{(zfloat24)(a_x), (zfloat24)(a_y)},				 \
				{(zfloat24)(b_x), (zfloat24)(b_y)}				 \
			})

#		define z_3d_line_float24(a_x, a_y, a_z, b_x, b_y, b_z)				 \
			((Z3DLineFloat24){							 \
				{(zfloat24)(a_x), (zfloat24)(a_y), (zfloat24)(a_z)},		 \
				{(zfloat24)(b_x), (zfloat24)(b_y), (zfloat24)(b_z)}		 \
			})

#		define z_box_float24(point_x, point_y, point_z, size_x, size_y, size_z)		 \
			((ZBoxFloat24){								 \
				{(zfloat24)(point_x), (zfloat24)(point_y), (zfloat24)(point_z)}, \
				{(zfloat24)(size_x ), (zfloat24)(size_y ), (zfloat24)(size_z )}	 \
			})

#		define z_circle_float24(point_x, point_y, radius)				 \
			((ZCircleFloat24){							 \
				{(zfloat24)(point_x), (zfloat24)(point_y)},			 \
				(zfloat24)(radius)						 \
			})

#		define z_rectangle_float24(point_x, point_y, size_x, size_y)			 \
			((ZRectangleFloat24){							 \
				{(zfloat24)(point_x), (zfloat24)(point_y)},			 \
				{(zfloat24)(size_x ), (zfloat24)(size_y )}			 \
			})

#		define z_sphere_float24(point_x, point_y, point_z, radius)			 \
			((ZCircleFloat24){							 \
				{(zfloat24)(point_x), (zfloat24)(point_y), (zfloat24)(point_z)}, \
				(zfloat24)(radius)						 \
			})

#	endif

#	ifdef Z_FLOAT32

#		define z_2d_line_float32(a_x, a_y, b_x, b_y)					 \
			((Z2DLineFloat32){							 \
				{(zfloat32)(a_x), (zfloat32)(a_y)},				 \
				{(zfloat32)(b_x), (zfloat32)(b_y)}				 \
			})

#		define z_3d_line_float32(a_x, a_y, a_z, b_x, b_y, b_z)				 \
			((Z3DLineFloat32){							 \
				{(zfloat32)(a_x), (zfloat32)(a_y), (zfloat32)(a_z)},		 \
				{(zfloat32)(b_x), (zfloat32)(b_y), (zfloat32)(b_z)}		 \
			})

#		define z_box_float32(point_x, point_y, point_z, size_x, size_y, size_z)		 \
			((ZBoxFloat32){								 \
				{(zfloat32)(point_x), (zfloat32)(point_y), (zfloat32)(point_z)}, \
				{(zfloat32)(size_x ), (zfloat32)(size_y ), (zfloat32)(size_z )}	 \
			})

#		define z_circle_float32(point_x, point_y, radius)				 \
			((ZCircleFloat32){							 \
				{(zfloat32)(point_x), (zfloat32)(point_y)},			 \
				(zfloat32)(radius)						 \
			})

#		define z_rectangle_float32(point_x, point_y, size_x, size_y)			 \
			((ZRectangleFloat32){							 \
				{(zfloat32)(point_x), (zfloat32)(point_y)},			 \
				{(zfloat32)(size_x ), (zfloat32)(size_y )}			 \
			})

#		define z_sphere_float32(point_x, point_y, point_z, radius)			 \
			((ZCircleFloat32){							 \
				{(zfloat32)(point_x), (zfloat32)(point_y), (zfloat32)(point_z)}, \
				(zfloat32)(radius)						 \
			})

#	endif

#	ifdef Z_FLOAT48

#		define z_2d_line_float48(a_x, a_y, b_x, b_y)					 \
			((Z2DLineFloat48){							 \
				{(zfloat48)(a_x), (zfloat48)(a_y)},				 \
				{(zfloat48)(b_x), (zfloat48)(b_y)}				 \
			})

#		define z_3d_line_float48(a_x, a_y, a_z, b_x, b_y, b_z)				 \
			((Z3DLineFloat48){							 \
				{(zfloat48)(a_x), (zfloat48)(a_y), (zfloat48)(a_z)},		 \
				{(zfloat48)(b_x), (zfloat48)(b_y), (zfloat48)(b_z)}		 \
			})

#		define z_box_float48(point_x, point_y, point_z, size_x, size_y, size_z)		 \
			((ZBoxFloat48){								 \
				{(zfloat48)(point_x), (zfloat48)(point_y), (zfloat48)(point_z)}, \
				{(zfloat48)(size_x ), (zfloat48)(size_y ), (zfloat48)(size_z )}	 \
			})

#		define z_circle_float48(point_x, point_y, radius)				 \
			((ZCircleFloat48){							 \
				{(zfloat48)(point_x), (zfloat48)(point_y)},			 \
				(zfloat48)(radius)						 \
			})

#		define z_rectangle_float48(point_x, point_y, size_x, size_y)			 \
			((ZRectangleFloat48){							 \
				{(zfloat48)(point_x), (zfloat48)(point_y)},			 \
				{(zfloat48)(size_x ), (zfloat48)(size_y )}			 \
			})

#		define z_sphere_float48(point_x, point_y, point_z, radius)			 \
			((ZCircleFloat48){							 \
				{(zfloat48)(point_x), (zfloat48)(point_y), (zfloat48)(point_z)}, \
				(zfloat48)(radius)						 \
			})

#	endif

#	ifdef Z_FLOAT64

#		define z_2d_line_float64(a_x, a_y, b_x, b_y)					 \
			((Z2DLineFloat64){							 \
				{(zfloat64)(a_x), (zfloat64)(a_y)},				 \
				{(zfloat64)(b_x), (zfloat64)(b_y)}				 \
			})

#		define z_3d_line_float64(a_x, a_y, a_z, b_x, b_y, b_z)				 \
			((Z3DLineFloat64){							 \
				{(zfloat64)(a_x), (zfloat64)(a_y), (zfloat64)(a_z)},		 \
				{(zfloat64)(b_x), (zfloat64)(b_y), (zfloat64)(b_z)}		 \
			})

#		define z_box_float64(point_x, point_y, point_z, size_x, size_y, size_z)		 \
			((ZBoxFloat64){								 \
				{(zfloat64)(point_x), (zfloat64)(point_y), (zfloat64)(point_z)}, \
				{(zfloat64)(size_x ), (zfloat64)(size_y ), (zfloat64)(size_z )}	 \
			})

#		define z_circle_float64(point_x, point_y, radius)				 \
			((ZCircleFloat64){							 \
				{(zfloat64)(point_x), (zfloat64)(point_y)},			 \
				(zfloat64)(radius)						 \
			})

#		define z_rectangle_float64(point_x, point_y, size_x, size_y)			 \
			((ZRectangleFloat64){							 \
				{(zfloat64)(point_x), (zfloat64)(point_y)},			 \
				{(zfloat64)(size_x ), (zfloat64)(size_y )}			 \
			})

#		define z_sphere_float64(point_x, point_y, point_z, radius)			 \
			((ZCircleFloat64){							 \
				{(zfloat64)(point_x), (zfloat64)(point_y), (zfloat64)(point_z)}, \
				(zfloat64)(radius)						 \
			})

#	endif

#	ifdef Z_FLOAT72

#		define z_2d_line_float72(a_x, a_y, b_x, b_y)					 \
			((Z2DLineFloat72){							 \
				{(zfloat72)(a_x), (zfloat72)(a_y)},				 \
				{(zfloat72)(b_x), (zfloat72)(b_y)}				 \
			})

#		define z_3d_line_float72(a_x, a_y, a_z, b_x, b_y, b_z)				 \
			((Z3DLineFloat72){							 \
				{(zfloat72)(a_x), (zfloat72)(a_y), (zfloat72)(a_z)},		 \
				{(zfloat72)(b_x), (zfloat72)(b_y), (zfloat72)(b_z)}		 \
			})

#		define z_box_float72(point_x, point_y, point_z, size_x, size_y, size_z)		 \
			((ZBoxFloat72){								 \
				{(zfloat72)(point_x), (zfloat72)(point_y), (zfloat72)(point_z)}, \
				{(zfloat72)(size_x ), (zfloat72)(size_y ), (zfloat72)(size_z )}	 \
			})

#		define z_circle_float72(point_x, point_y, radius)				 \
			((ZCircleFloat72){							 \
				{(zfloat72)(point_x), (zfloat72)(point_y)},			 \
				(zfloat72)(radius)						 \
			})

#		define z_rectangle_float72(point_x, point_y, size_x, size_y)			 \
			((ZRectangleFloat72){							 \
				{(zfloat72)(point_x), (zfloat72)(point_y)},			 \
				{(zfloat72)(size_x ), (zfloat72)(size_y )}			 \
			})

#		define z_sphere_float72(point_x, point_y, point_z, radius)			 \
			((ZCircleFloat72){							 \
				{(zfloat72)(point_x), (zfloat72)(point_y), (zfloat72)(point_z)}, \
				(zfloat72)(radius)						 \
			})

#	endif

#	ifdef Z_FLOAT80

#		define z_2d_line_float80(a_x, a_y, b_x, b_y)					 \
			((Z2DLineFloat80){							 \
				{(zfloat80)(a_x), (zfloat80)(a_y)},				 \
				{(zfloat80)(b_x), (zfloat80)(b_y)}				 \
			})

#		define z_3d_line_float80(a_x, a_y, a_z, b_x, b_y, b_z)				 \
			((Z3DLineFloat80){							 \
				{(zfloat80)(a_x), (zfloat80)(a_y), (zfloat80)(a_z)},		 \
				{(zfloat80)(b_x), (zfloat80)(b_y), (zfloat80)(b_z)}		 \
			})

#		define z_box_float80(point_x, point_y, point_z, size_x, size_y, size_z)		 \
			((ZBoxFloat80){								 \
				{(zfloat80)(point_x), (zfloat80)(point_y), (zfloat80)(point_z)}, \
				{(zfloat80)(size_x ), (zfloat80)(size_y ), (zfloat80)(size_z )}	 \
			})

#		define z_circle_float80(point_x, point_y, radius)				 \
			((ZCircleFloat80){							 \
				{(zfloat80)(point_x), (zfloat80)(point_y)},			 \
				(zfloat80)(radius)						 \
			})

#		define z_rectangle_float80(point_x, point_y, size_x, size_y)			 \
			((ZRectangleFloat80){							 \
				{(zfloat80)(point_x), (zfloat80)(point_y)},			 \
				{(zfloat80)(size_x ), (zfloat80)(size_y )}			 \
			})

#		define z_sphere_float80(point_x, point_y, point_z, radius)			 \
			((ZCircleFloat80){							 \
				{(zfloat80)(point_x), (zfloat80)(point_y), (zfloat80)(point_z)}, \
				(zfloat80)(radius)						 \
		})

#	endif

#	ifdef Z_FLOAT96

#		define z_2d_line_float96(a_x, a_y, b_x, b_y)					 \
			((Z2DLineFloat96){							 \
				{(zfloat96)(a_x), (zfloat96)(a_y)},				 \
				{(zfloat96)(b_x), (zfloat96)(b_y)}				 \
			})

#		define z_3d_line_float96(a_x, a_y, a_z, b_x, b_y, b_z)				 \
			((Z3DLineFloat96){							 \
				{(zfloat96)(a_x), (zfloat96)(a_y), (zfloat96)(a_z)},		 \
				{(zfloat96)(b_x), (zfloat96)(b_y), (zfloat96)(b_z)}		 \
			})

#		define z_box_float96(point_x, point_y, point_z, size_x, size_y, size_z)		 \
			((ZBoxFloat96){								 \
				{(zfloat96)(point_x), (zfloat96)(point_y), (zfloat96)(point_z)}, \
				{(zfloat96)(size_x ), (zfloat96)(size_y ), (zfloat96)(size_z )}	 \
			})

#		define z_circle_float96(point_x, point_y, radius)				 \
			((ZCircleFloat96){							 \
				{(zfloat96)(point_x), (zfloat96)(point_y)},			 \
				(zfloat96)(radius)						 \
			})

#		define z_rectangle_float96(point_x, point_y, size_x, size_y)			 \
			((ZRectangleFloat96){							 \
				{(zfloat96)(point_x), (zfloat96)(point_y)},			 \
				{(zfloat96)(size_x ), (zfloat96)(size_y )}			 \
			})

#		define z_sphere_float96(point_x, point_y, point_z, radius)			 \
			((ZCircleFloat96){							 \
				{(zfloat96)(point_x), (zfloat96)(point_y), (zfloat96)(point_z)}, \
				(zfloat96)(radius)						 \
			})

#	endif

#	ifdef Z_FLOAT128

#		define z_2d_line_float128(a_x, a_y, b_x, b_y)					    \
			((Z2DLineFloat128){							    \
				{(zfloat128)(a_x), (zfloat128)(a_y)},				    \
				{(zfloat128)(b_x), (zfloat128)(b_y)}				    \
			})

#		define z_3d_line_float128(a_x, a_y, a_z, b_x, b_y, b_z)				    \
			((Z3DLineFloat128){							    \
				{(zfloat128)(a_x), (zfloat128)(a_y), (zfloat128)(a_z)},		    \
				{(zfloat128)(b_x), (zfloat128)(b_y), (zfloat128)(b_z)}		    \
			})

#		define z_box_float128(point_x, point_y, point_z, size_x, size_y, size_z)	    \
			((ZBoxFloat128){							    \
				{(zfloat128)(point_x), (zfloat128)(point_y), (zfloat128)(point_z)}, \
				{(zfloat128)(size_x ), (zfloat128)(size_y ), (zfloat128)(size_z )}  \
			})

#		define z_circle_float128(point_x, point_y, radius)				    \
			((ZCircleFloat128){							    \
				{(zfloat128)(point_x), (zfloat128)(point_y)},			    \
				(zfloat128)(radius)						    \
			})

#		define z_rectangle_float128(point_x, point_y, size_x, size_y)			    \
			((ZRectangleFloat128){							    \
				{(zfloat128)(point_x), (zfloat128)(point_y)},			    \
				{(zfloat128)(size_x ), (zfloat128)(size_y )}			    \
			})

#		define z_sphere_float128(point_x, point_y, point_z, radius)			    \
			((ZCircleFloat128){							    \
				{(zfloat128)(point_x), (zfloat128)(point_y), (zfloat128)(point_z)}, \
				(zfloat128)(radius)						    \
			})

#	endif

#else

#	define Z_IMPLEMENTATION_EUCLIDEAN_GEOMETRY_CONSTRUCTORS_INTEGER(Type, type)		\
												\
												\
	Z_INLINE Z2DLine##Type z_2d_line_##type(						\
		z##type a_x,									\
		z##type a_y,									\
		z##type b_x,									\
		z##type b_y									\
	)											\
		{Z2DLine##Type object = {{a_x, a_y}, {b_x, b_y}}; return object;}		\
												\
												\
	Z_INLINE Z3DLine##Type z_3d_line_##type(						\
		z##type a_x,									\
		z##type a_y,									\
		z##type a_z,									\
		z##type b_x,									\
		z##type b_y,									\
		z##type b_z									\
	)											\
		{Z3DLine##Type object = {{a_x, a_y, a_z}, {b_x, b_y, b_z}}; return object;}	\
												\
												\
	Z_INLINE ZBox##Type z_box_##type(							\
		z##type x,									\
		z##type y,									\
		z##type z,									\
		z##type size_x,									\
		z##type size_y,									\
		z##type size_z									\
	)											\
		{ZBox##Type object = {{x, y, z}, {size_x, size_y, size_z}}; return object;}	\
												\
												\
	Z_INLINE ZRectangle##Type z_rectangle_##type(						\
		z##type x,									\
		z##type y,									\
		z##type size_x,									\
		z##type size_y									\
	)											\
		{ZRectangle##Type object = {{x, y}, {size_x, size_y}}; return object;}


#	define Z_IMPLEMENTATION_EUCLIDEAN_GEOMETRY_CONSTRUCTORS_REAL(Type, type)		\
												\
												\
	Z_INLINE ZCircle##Type z_circle_##type(z##type x, z##type y, z##type radius)		\
		{ZCircle##Type object = {{x, y}, radius}; return object;}			\
												\
												\
	Z_INLINE ZSphere##Type z_sphere_##type(z##type x, z##type y, z##type z, z##type radius)	\
		{ZSphere##Type object = {{x, y, z}, radius}; return object;}


	Z_IMPLEMENTATION_EUCLIDEAN_GEOMETRY_CONSTRUCTORS_INTEGER(Int8,	int8 )
	Z_IMPLEMENTATION_EUCLIDEAN_GEOMETRY_CONSTRUCTORS_INTEGER(Int16, int16)
	Z_IMPLEMENTATION_EUCLIDEAN_GEOMETRY_CONSTRUCTORS_INTEGER(Int32, int32)

#	ifdef Z_INT64
		Z_IMPLEMENTATION_EUCLIDEAN_GEOMETRY_CONSTRUCTORS_INTEGER(Int64, int64)
#	endif

#	ifdef Z_INT128
		Z_IMPLEMENTATION_EUCLIDEAN_GEOMETRY_CONSTRUCTORS_INTEGER(Int128, int128)
#	endif

#	ifdef Z_FLOAT16
		Z_IMPLEMENTATION_EUCLIDEAN_GEOMETRY_CONSTRUCTORS_INTEGER(Float16, float16)
		Z_IMPLEMENTATION_EUCLIDEAN_GEOMETRY_CONSTRUCTORS_REAL	(Float16, float16)
#	endif

#	ifdef Z_FLOAT32
		Z_IMPLEMENTATION_EUCLIDEAN_GEOMETRY_CONSTRUCTORS_INTEGER(Float32, float32)
		Z_IMPLEMENTATION_EUCLIDEAN_GEOMETRY_CONSTRUCTORS_REAL	(Float32, float32)
#	endif

#	ifdef Z_FLOAT48
		Z_IMPLEMENTATION_EUCLIDEAN_GEOMETRY_CONSTRUCTORS_INTEGER(Float48, float48)
		Z_IMPLEMENTATION_EUCLIDEAN_GEOMETRY_CONSTRUCTORS_REAL	(Float48, float48)
#	endif

#	ifdef Z_FLOAT64
		Z_IMPLEMENTATION_EUCLIDEAN_GEOMETRY_CONSTRUCTORS_INTEGER(Float64, float64)
		Z_IMPLEMENTATION_EUCLIDEAN_GEOMETRY_CONSTRUCTORS_REAL	(Float64, float64)
#	endif

#	ifdef Z_FLOAT72
		Z_IMPLEMENTATION_EUCLIDEAN_GEOMETRY_CONSTRUCTORS_INTEGER(Float72, float72)
		Z_IMPLEMENTATION_EUCLIDEAN_GEOMETRY_CONSTRUCTORS_REAL	(Float72, float72)
#	endif

#	ifdef Z_FLOAT80
		Z_IMPLEMENTATION_EUCLIDEAN_GEOMETRY_CONSTRUCTORS_INTEGER(Float80, float80)
		Z_IMPLEMENTATION_EUCLIDEAN_GEOMETRY_CONSTRUCTORS_REAL	(Float80, float80)
#	endif

#	ifdef Z_FLOAT96
		Z_IMPLEMENTATION_EUCLIDEAN_GEOMETRY_CONSTRUCTORS_INTEGER(Float96, float96)
		Z_IMPLEMENTATION_EUCLIDEAN_GEOMETRY_CONSTRUCTORS_REAL	(Float96, float96)
#	endif

#	ifdef Z_FLOAT128
		Z_IMPLEMENTATION_EUCLIDEAN_GEOMETRY_CONSTRUCTORS_INTEGER(Float128, float128)
		Z_IMPLEMENTATION_EUCLIDEAN_GEOMETRY_CONSTRUCTORS_REAL	(Float128, float128)
#	endif

#endif

#define z_aabb_int8 z_3d_line_int8
#define z_aabr_int8 z_2d_line_int8

#define z_2d_line_int8_zero   z_2d_line_int8  (0.0, 0.0, 0.0, 0.0)
#define z_3d_line_int8_zero   z_3d_line_int8  (0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#define z_aabb_int8_zero      z_3d_line_int8_zero
#define z_aabr_int8_zero      z_2d_line_int8_zero
#define z_box_int8_zero	      z_box_int8      (0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#define z_rectangle_int8_zero z_rectangle_int8(0.0, 0.0, 0.0, 0.0)

#define z_aabb_int16 z_3d_line_int16
#define z_aabr_int16 z_2d_line_int16

#define z_2d_line_int16_zero   z_2d_line_int16	(0.0, 0.0, 0.0, 0.0)
#define z_3d_line_int16_zero   z_3d_line_int16	(0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#define z_aabb_int16_zero      z_3d_line_int16_zero
#define z_aabr_int16_zero      z_2d_line_int16_zero
#define z_box_int16_zero       z_box_int16	(0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#define z_rectangle_int16_zero z_rectangle_int16(0.0, 0.0, 0.0, 0.0)

#define z_aabb_int32 z_3d_line_int32
#define z_aabr_int32 z_2d_line_int32

#define z_2d_line_int32_zero   z_2d_line_int32	(0.0, 0.0, 0.0, 0.0)
#define z_3d_line_int32_zero   z_3d_line_int32	(0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#define z_aabb_int32_zero      z_3d_line_int32_zero
#define z_aabr_int32_zero      z_2d_line_int32_zero
#define z_box_int32_zero       z_box_int32	(0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#define z_rectangle_int32_zero z_rectangle_int32(0.0, 0.0, 0.0, 0.0)

#ifdef Z_INT64

#	define z_aabb_int64 z_3d_line_int64
#	define z_aabr_int64 z_2d_line_int64

#	define z_2d_line_int64_zero   z_2d_line_int64  (0.0, 0.0, 0.0, 0.0)
#	define z_3d_line_int64_zero   z_3d_line_int64  (0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#	define z_aabb_int64_zero      z_3d_line_int64_zero
#	define z_aabr_int64_zero      z_2d_line_int64_zero
#	define z_box_int64_zero	      z_box_int64      (0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#	define z_rectangle_int64_zero z_rectangle_int64(0.0, 0.0, 0.0, 0.0)

#endif

#ifdef Z_INT128

#	define z_aabb_int128 z_3d_line_int128
#	define z_aabr_int128 z_2d_line_int128

#	define z_2d_line_int128_zero   z_2d_line_int128	 (0.0, 0.0, 0.0, 0.0)
#	define z_3d_line_int128_zero   z_3d_line_int128	 (0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#	define z_aabb_int128_zero      z_3d_line_int128_zero
#	define z_aabr_int128_zero      z_2d_line_int128_zero
#	define z_box_int128_zero       z_box_int128	 (0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#	define z_rectangle_int128_zero z_rectangle_int128(0.0, 0.0, 0.0, 0.0)

#endif

#ifdef Z_FLOAT16

#	define z_aabb_float16 z_3d_line_float16
#	define z_aabr_float16 z_2d_line_float16

#	define z_2d_line_float16_zero	z_2d_line_float16  (0.0, 0.0, 0.0, 0.0)
#	define z_3d_line_float16_zero	z_3d_line_float16  (0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#	define z_aabb_float16_zero	z_3d_line_float16_zero
#	define z_aabr_float16_zero	z_2d_line_float16_zero
#	define z_box_float16_zero	z_box_float16	   (0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#	define z_circle_float16_zero	z_circle_float16   (0.0, 0.0, 0.0)
#	define z_rectangle_float16_zero	z_rectangle_float16(0.0, 0.0, 0.0, 0.0)
#	define z_sphere_float16_zero	z_sphere_float16   (0.0, 0.0, 0.0, 0.0)

#endif

#ifdef Z_FLOAT24

#	define z_aabb_float24 z_3d_line_float24
#	define z_aabr_float24 z_2d_line_float24

#	define z_2d_line_float24_zero	z_2d_line_float24  (0.0, 0.0, 0.0, 0.0)
#	define z_3d_line_float24_zero	z_3d_line_float24  (0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#	define z_aabb_float24_zero	z_3d_line_float24_zero
#	define z_aabr_float24_zero	z_2d_line_float24_zero
#	define z_box_float24_zero	z_box_float24	   (0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#	define z_circle_float24_zero	z_circle_float24   (0.0, 0.0, 0.0)
#	define z_rectangle_float24_zero	z_rectangle_float24(0.0, 0.0, 0.0, 0.0)
#	define z_sphere_float24_zero	z_sphere_float24   (0.0, 0.0, 0.0, 0.0)

#endif

#ifdef Z_FLOAT32

#	define z_aabb_float32 z_3d_line_float32
#	define z_aabr_float32 z_2d_line_float32

#	define z_2d_line_float32_zero	z_2d_line_float32  (0.0, 0.0, 0.0, 0.0)
#	define z_3d_line_float32_zero	z_3d_line_float32  (0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#	define z_aabb_float32_zero	z_3d_line_float32_zero
#	define z_aabr_float32_zero	z_2d_line_float32_zero
#	define z_box_float32_zero	z_box_float32	   (0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#	define z_circle_float32_zero	z_circle_float32   (0.0, 0.0, 0.0)
#	define z_rectangle_float32_zero	z_rectangle_float32(0.0, 0.0, 0.0, 0.0)
#	define z_sphere_float32_zero	z_sphere_float32   (0.0, 0.0, 0.0, 0.0)

#endif

#ifdef Z_FLOAT48

#	define z_aabb_float48 z_3d_line_float48
#	define z_aabr_float48 z_2d_line_float48

#	define z_2d_line_float48_zero	z_2d_line_float48  (0.0, 0.0, 0.0, 0.0)
#	define z_3d_line_float48_zero	z_3d_line_float48  (0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#	define z_aabb_float48_zero	z_3d_line_float48_zero
#	define z_aabr_float48_zero	z_2d_line_float48_zero
#	define z_box_float48_zero	z_box_float48	   (0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#	define z_circle_float48_zero	z_circle_float48   (0.0, 0.0, 0.0)
#	define z_rectangle_float48_zero	z_rectangle_float48(0.0, 0.0, 0.0, 0.0)
#	define z_sphere_float48_zero	z_sphere_float48   (0.0, 0.0, 0.0, 0.0)

#endif

#ifdef Z_FLOAT64

#	define z_aabb_float64 z_3d_line_float64
#	define z_aabr_float64 z_2d_line_float64

#	define z_2d_line_float64_zero	z_2d_line_float64  (0.0, 0.0, 0.0, 0.0)
#	define z_3d_line_float64_zero	z_3d_line_float64  (0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#	define z_aabb_float64_zero	z_3d_line_float64_zero
#	define z_aabr_float64_zero	z_2d_line_float64_zero
#	define z_box_float64_zero	z_box_float64	   (0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#	define z_circle_float64_zero	z_circle_float64   (0.0, 0.0, 0.0)
#	define z_rectangle_float64_zero	z_rectangle_float64(0.0, 0.0, 0.0, 0.0)
#	define z_sphere_float64_zero	z_sphere_float64   (0.0, 0.0, 0.0, 0.0)

#endif

#ifdef Z_FLOAT72

#	define z_aabb_float72 z_3d_line_float72
#	define z_aabr_float72 z_2d_line_float72

#	define z_2d_line_float72_zero	z_2d_line_float72  (0.0, 0.0, 0.0, 0.0)
#	define z_3d_line_float72_zero	z_3d_line_float72  (0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#	define z_aabb_float72_zero	z_3d_line_float72_zero
#	define z_aabr_float72_zero	z_2d_line_float72_zero
#	define z_box_float72_zero	z_box_float72	   (0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#	define z_circle_float72_zero	z_circle_float72   (0.0, 0.0, 0.0)
#	define z_rectangle_float72_zero	z_rectangle_float72(0.0, 0.0, 0.0, 0.0)
#	define z_sphere_float72_zero	z_sphere_float72   (0.0, 0.0, 0.0, 0.0)

#endif

#ifdef Z_FLOAT80

#	define z_aabb_float80 z_3d_line_float80
#	define z_aabr_float80 z_2d_line_float80

#	define z_2d_line_float80_zero	z_2d_line_float80  (0.0, 0.0, 0.0, 0.0)
#	define z_3d_line_float80_zero	z_3d_line_float80  (0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#	define z_aabb_float80_zero	z_3d_line_float80_zero
#	define z_aabr_float80_zero	z_2d_line_float80_zero
#	define z_box_float80_zero	z_box_float80	   (0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#	define z_circle_float80_zero	z_circle_float80   (0.0, 0.0, 0.0)
#	define z_rectangle_float80_zero z_rectangle_float80(0.0, 0.0, 0.0, 0.0)
#	define z_sphere_float80_zero	z_sphere_float80   (0.0, 0.0, 0.0, 0.0)

#endif

#ifdef Z_FLOAT96

#	define z_aabb_float96 z_3d_line_float96
#	define z_aabr_float96 z_2d_line_float96

#	define z_2d_line_float96_zero	z_2d_line_float96  (0.0, 0.0, 0.0, 0.0)
#	define z_3d_line_float96_zero	z_3d_line_float96  (0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#	define z_aabb_float96_zero	z_3d_line_float96_zero
#	define z_aabr_float96_zero	z_2d_line_float96_zero
#	define z_box_float96_zero	z_box_float96	   (0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#	define z_circle_float96_zero	z_circle_float96   (0.0, 0.0, 0.0)
#	define z_rectangle_float96_zero z_rectangle_float96(0.0, 0.0, 0.0, 0.0)
#	define z_sphere_float96_zero	z_sphere_float96   (0.0, 0.0, 0.0, 0.0)

#endif

#ifdef Z_FLOAT128

#	define z_aabb_float128 z_3d_line_float128
#	define z_aabr_float128 z_2d_line_float128

#	define z_2d_line_float128_zero	 z_2d_line_float128  (0.0, 0.0, 0.0, 0.0)
#	define z_3d_line_float128_zero	 z_3d_line_float128  (0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#	define z_aabb_float128_zero	 z_3d_line_float128_zero
#	define z_aabr_float128_zero	 z_2d_line_float128_zero
#	define z_box_float128_zero	 z_box_float128	     (0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
#	define z_circle_float128_zero	 z_circle_float128   (0.0, 0.0, 0.0)
#	define z_rectangle_float128_zero z_rectangle_float128(0.0, 0.0, 0.0, 0.0)
#	define z_sphere_float128_zero	 z_sphere_float128   (0.0, 0.0, 0.0, 0.0)

#endif

#define z_2d_line_type(	 TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_line_,	 )
#define z_3d_line_type(	 TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_line_,	 )
#define z_aabb_type(	 TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabb_,	 )
#define z_aabr_type(	 TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_,	 )
#define z_box_type(	 TYPE) Z_INSERT_##TYPE##_fixed_type(z_box_type,	 )
#define z_circle_type(	 TYPE) Z_INSERT_##TYPE##_fixed_type(z_circle_,	 )
#define z_rectangle_type(TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_,)
#define z_sphere_type(	 TYPE) Z_INSERT_##TYPE##_fixed_type(z_sphere_,	 )

#define z_2d_line_type_zero(  TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_line_,   _zero)
#define z_3d_line_type_zero(  TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_line_,   _zero)
#define z_aabb_type_zero(     TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabb_,      _zero)
#define z_aabr_type_zero(     TYPE) Z_INSERT_##TYPE##_fixed_type(z_aabr_,      _zero)
#define z_box_type_zero(      TYPE) Z_INSERT_##TYPE##_fixed_type(z_box_,       _zero)
#define z_circle_type_zero(   TYPE) Z_INSERT_##TYPE##_fixed_type(z_circle_,    _zero)
#define z_rectangle_type_zero(TYPE) Z_INSERT_##TYPE##_fixed_type(z_rectangle_, _zero)
#define z_sphere_type_zero(   TYPE) Z_INSERT_##TYPE##_fixed_type(z_sphere_,    _zero)

/* MARK: - Default real type definitions */

#ifdef Z_REAL

#	define z_2d_line   z_2d_line_type  (REAL)
#	define z_3d_line   z_3d_line_type  (REAL)
#	define z_aabb	   z_3d_line
#	define z_aabr	   z_2d_line
#	define z_box	   z_box_type	   (REAL)
#	define z_circle	   z_circle_type   (REAL)
#	define z_rectangle z_rectangle_type(REAL)
#	define z_sphere	   z_sphere_type   (REAL)

#	define z_2d_line_zero	z_2d_line_type_zero  (REAL)
#	define z_3d_line_zero	z_3d_line_type_zero  (REAL)
#	define z_aabb_zero	z_3d_line_zero
#	define z_aabr_zero	z_2d_line_zero
#	define z_box_zero	z_box_type_zero	     (REAL)
#	define z_circle_zero	z_circle_type_zero   (REAL)
#	define z_rectangle_zero	z_rectangle_type_zero(REAL)
#	define z_sphere_zero	z_sphere_type_zero   (REAL)

#endif

#endif /* __Z_functions_mathematics_geometry_euclidean_constructors_H__ */
