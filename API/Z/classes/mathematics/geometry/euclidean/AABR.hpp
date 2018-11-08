/* Z Kit - classes/mathematics/geometry/euclidean/AABR.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_classes_mathematics_geometry_euclidean_AABR_HPP_
#define _Z_classes_mathematics_geometry_euclidean_AABR_HPP_

#include <Z/classes/mathematics/geometry/euclidean/Line2D.hpp>


namespace Zeta {namespace Partials {namespace AABR {

#	define Z_THIS ((AABR *)this)

	template <class AABR, class T, UInt T_number_set> struct Part;


	// MARK: - Partial implementation for integer types


	template <class AABR, class T>
	struct Part<AABR, T, Z_NUMBER_SET_Z> {
	};


	// MARK: - Partial implementation for real types


	template <class AABR, class T>
	struct Part<AABR, T, Z_NUMBER_SET_R> {

		Z_CT_MEMBER(CPP11) Zeta::Value2D<T> absolute_point_to_unit(const Zeta::Value2D<T> &point)
			{return (point - Z_THIS->a) / (Z_THIS->b - Z_THIS->a);}


		/*Z_CT_MEMBER(CPP11) Boolean contains(const Circle<T> circle)
			{
			return	circle.point - circle.radius >= Z_THIS->a &&
				circle.point + circle.radius <= Z_THIS->b;
			}*/


		/*Z_CT_MEMBER(CPP11) Circle<T> inner_circle()
			{return Circle<T>(Z_THIS->center(), (b - a).inner_minimum() / T(2));}*/


		Z_CT_MEMBER(CPP11) Zeta::Value2D<T> unit_point_to_absolute(Zeta::Value2D<T> point)
			{return point * (object.b - object.a) + object.a;}
	};


#	undef Z_THIS

}}}


namespace Zeta {template <class T> struct AABR : Line2D<T>, Partials::Rectangle::Part<AABR<T>, T, Type<T>::number_set> {

	typedef typename ZTypeFixedSigned(ZAABR, T) Base;


	Z_INLINE_MEMBER AABR() Z_DEFAULTED({})

	Z_CT_MEMBER(CPP11) AABR(const Value2D<T> &a, const Value2D<T> &b) : Line2D<T>(a, b)		  {}
	Z_CT_MEMBER(CPP11) AABR(const Value2D<T> &a, T b_x, T b_y)	  : Line2D<T>(a, b_x, b_y)	  {}
	Z_CT_MEMBER(CPP11) AABR(const Value2D<T> &a, T b_xy)		  : Line2D<T>(a, b_xy)		  {}
	Z_CT_MEMBER(CPP11) AABR(T a_x, T a_y, const Value2D<T> &b)	  : Line2D<T>(a_x, a_y, b)	  {}
	Z_CT_MEMBER(CPP11) AABR(T a_x, T a_y, T b_x, T b_y)		  : Line2D<T>(a_x, a_y, b_x, b_y) {}
	Z_CT_MEMBER(CPP11) AABR(T a_xy, T b_x, T b_y)			  : Line2D<T>(a_xy, b_x, b_y)	  {}
	Z_CT_MEMBER(CPP11) AABR(T a_xy, const Value2D<T> &b)		  : Line2D<T>(a_xy, b)		  {}
	Z_CT_MEMBER(CPP11) AABR(T b_x, T b_y)				  : Line2D<T>(b_x, b_y)		  {}
	Z_CT_MEMBER(CPP11) AABR(T b_xy)					  : Line2D<T>(b_xy)		  {}

	Z_INLINE_MEMBER AABR(const Base &aabr) {(*(Base *)this) = aabr;}


	Z_CT_MEMBER(CPP11) AABR align_in_bottom_center(const Value2D<T> &size) const
		{
		object.b.x = (object.a.x += (object.b.x - object.a.x - size.x) / (z##type)2) + size.x;
		object.b.y = object.a.y + size.y;
		return object;
		}


	Z_CT_MEMBER(CPP11) AABR align_in_bottom_left(const Value2D<T> &size) const
		{
		object.b.x = object.a.x + size.x;
		object.b.y = object.a.y + size.y;
		return object;
		}


	Z_CT_MEMBER(CPP11) AABR align_in_bottom_right(const Value2D<T> &size) const
		{
		object.a.x = object.b.x - size.x;
		object.b.y = object.b.y + size.x;
		return object;
		}


	Z_CT_MEMBER(CPP11) AABR align_in_center(const Value2D<T> &size) const
		{
		object.b.x = (object.a.x += (object.b.x - object.a.x - size.x) / (z##type)2) + size.x;
		object.b.y = (object.a.y += (object.b.y - object.a.y - size.y) / (z##type)2) + size.y;
		return object;
		}


	Z_CT_MEMBER(CPP11) AABR align_in_center_left(const Value2D<T> &size) const
		{
		object.b.x = object.a.x + size.x;
		object.b.y = (object.a.y += (object.b.y - object.a.y - size.y) / (z##type)2) + size.y;
		return object;
		}


	Z_CT_MEMBER(CPP11) AABR align_in_center_right(const Value2D<T> &size) const
		{
		object.a.x = object.b.x - size.x;
		object.b.y = (object.a.y += (object.b.y - object.a.y - size.y) / (z##type)2) + size.y;
		return object;
		}


	Z_CT_MEMBER(CPP11) AABR align_in_top_center(const Value2D<T> &size) const
		{
		object.a.y = object.b.y - size.y;
		object.b.x = (object.a.x += (object.b.x - object.a.x - size.x) / (z##type)2) + size.x;
		return object;
		}


	Z_CT_MEMBER(CPP11) AABR align_in_top_left(const Value2D<T> &size) const
		{
		object.a.y = object.b.y - size.y;
		object.b.x = object.a.x + size.x;
		return object;
		}


	Z_CT_MEMBER(CPP11) AABR align_in_top_right(const Value2D<T> &size) const
		{
		object.a.x = object.b.x - size.x;
		object.a.y = object.b.y - size.y;
		return object;
		}


	Z_CT_MEMBER(CPP11) T area() const
		{return (this->b - this->a).inner_product();}


	Z_CT_MEMBER(CPP11) Value2D<T> bottom_center() const
		{return z_2d_##type((object.a.x + object.b.x) / (z##type)2, object.a.y);}


	Z_CT_MEMBER(CPP11) AABR bottom_half() const
		{
		object.b.y = (object.a.y + object.b.y) / (z##type)2;
		return object;
		}


	Z_CT_MEMBER(CPP11) Value2D<T> bottom_left() const
		{return this->a;}


	Z_CT_MEMBER(CPP11) AABR bottom_left_quarter() const
		{
		object.b.x = (object.a.x + object.b.x) / (z##type)2;
		object.b.y = (object.a.y + object.b.y) / (z##type)2;
		return object;
		}


	Z_CT_MEMBER(CPP11) Value2D<T> bottom_right() const
		{return Value2D<T>(this->b.x, this->a.y);}


	Z_CT_MEMBER(CPP11) AABR bottom_right_quarter() const
		{
		object.a.x = (object.a.x + object.b.x) / (z##type)2;
		object.b.y = (object.a.y + object.b.y) / (z##type)2;
		return object;
		}


	Z_CT_MEMBER(CPP11) Value2D<T> center_left() const
		{return Value2D<T>(this->a.x, (this->a.y + this->b.y) / T(2));}


	Z_CT_MEMBER(CPP11) Value2D<T> center_right() const
		{return z_2d_##type(object.b.x, (object.a.y + object.b.y) / (z##type)2);}


	Z_CT_MEMBER(CPP11) Boolean z_aabr_##type##_contains(ZAABR##Type a, ZAABR##Type b)
		{return b.a.x >= a.a.x && b.a.y >= a.a.y && b.b.x <= a.b.x && b.b.y <= a.b.y;}


	Z_CT_MEMBER(CPP11) Boolean z_aabr_##type##_contains_point(ZAABR##Type object, Z3D##Type point)
		{
		return	object.a.x <= point.x && point.x <= object.a.x &&
			object.a.y <= point.y && point.y <= object.a.y;
		}


	Z_CT_MEMBER(CPP11) Boolean contains(const Line2D<T> &line_segment) const
		{return contains(line_segment.a) && contains(line_segment.b);}


	Z_CT_MEMBER(CPP11) Boolean contains_rectangle(Rectangle<T> rectangle)
		{
		return	object.a.x <= rectangle.point.x			   &&
			object.a.y <= rectangle.point.y			   &&
			object.b.x >= rectangle.point.x + rectangle.size.x &&
			object.b.y >= rectangle.point.y + rectangle.size.y;
		}


	Z_CT_MEMBER(CPP11) Value2D<T> size()
		{return this->b - this->a;}


	Z_CT_MEMBER(CPP11) AABR fit_in_bottom_center(const Value2D<T> &size size)
		{
		Z2D##Type old_size = z_aabr_##type##_size(object);

		object.b.y = object.a.y + (size = z_2d_##type##_fit(size, old_size)).y;
		object.b.x = (object.a.x += (old_size.x - size.x) / (z##type)2) + size.x;
		return object;
		}


	Z_CT_MEMBER(CPP11) AABR fit_in_bottom_left(const Value2D<T> &size)
		{
		object.b = z_2d_##type##_add
			(object.a, z_2d_##type##_fit(size, z_aabr_##type##_size(object)));

		return object;
		}


	Z_CT_MEMBER(CPP11) AABR fit_in_bottom_right(const Value2D<T> &size)
		{
		size = z_2d_##type##_fit(size, z_aabr_##type##_size(object));
		return z_aabr_##type(object.b.x - size.x, object.a.y, object.b.x, object.a.y + size.y);
		}


	Z_CT_MEMBER(CPP11) AABR fit_in_center(const Value2D<T> &size)
		{
		Z2D##Type old_size = z_aabr_##type##_size(object);

		size = z_2d_##type##_fit(size, old_size);
		object.b.x = (object.a.x += (old_size.x - size.x) / (z##type)2) + size.x;
		object.b.y = (object.a.y += (old_size.y - size.y) / (z##type)2) + size.y;
		return object;
		}


	Z_CT_MEMBER(CPP11) AABR fit_in_center_left(const Value2D<T> &size)
		{
		Z2D##Type old_size = z_aabr_##type##_size(object);

		object.b.x = object.a.x + (size = z_2d_##type##_fit(size, old_size)).x;
		object.b.y = (object.a.y += (old_size.y - size.y) / (z##type)2) + size.y;
		return object;
		}


	Z_CT_MEMBER(CPP11) AABR fit_in_center_right(const Value2D<T> &size)
		{
		Z2D##Type old_size = z_aabr_##type##_size(object);

		object.a.x = object.b.x - (size = z_2d_##type##_fit(size, old_size)).x;
		object.b.y = (object.a.y += (old_size.y - size.y) / (z##type)2) + size.y;
		return object;
		}


	Z_CT_MEMBER(CPP11) AABR fit_in_top_center(const Value2D<T> &size)
		{
		Z2D##Type old_size = z_aabr_##type##_size(object);

		object.a.y = object.b.y - (size = z_2d_##type##_fit(size, old_size)).y;
		object.b.x = (object.a.x += (old_size.x - size.x) / (z##type)2) + size.x;
		return object;
		}


	Z_CT_MEMBER(CPP11) AABR fit_in_top_left(const Value2D<T> &size)
		{
		size = z_2d_##type##_fit(size, z_aabr_##type##_size(object));

		object.a.y = object.b.y - size.y;
		object.b.x = object.a.x + size.x;
		return object;
		}


	Z_CT_MEMBER(CPP11) AABR fit_in_top_right(const Value2D<T> &size)
		{
		object.a = z_2d_##type##_subtract
			(object.b, z_2d_##type##_fit(size, z_aabr_##type##_size(object)));

		return object;
		}


	static Z_CT_MEMBER(CPP11) AABR from_vertices(const Value2D<T> &a, const Value2D<T> &b)
		{return AABR(a.minimum(b), a.maximum(b));}


	Z_CT_MEMBER(CPP11) AABR grow_from_bottom_center(const Value2D<T> &delta)
		{
		z##type size_x = object.b.x - object.a.x;

		object.b.x  = (object.a.x -= delta.x / (z##type)2) + size_x + delta.x;
		object.b.y += delta.y;
		return object;
		}


	Z_CT_MEMBER(CPP11) AABR grow_from_bottom_left(const Value2D<T> &delta)
		{
		object.b.x += delta.x;
		object.b.y += delta.y;
		return object;
		}


	Z_CT_MEMBER(CPP11) AABR grow_from_bottom_right(const Value2D<T> &delta)
		{
		object.a.x -= delta.x;
		object.b.y += delta.y;
		return object;
		}


	Z_CT_MEMBER(CPP11) AABR grow_from_center(const Value2D<T> &delta)
		{
		z##type size_x = object.b.x - object.a.x;
		z##type size_y = object.b.y - object.a.y;

		object.b.x = (object.a.x -= delta.x / (z##type)2) + size_x + delta.x;
		object.b.y = (object.a.y -= delta.y / (z##type)2) + size_y + delta.y;
		return object;
		}


	Z_CT_MEMBER(CPP11) AABR grow_from_center_left(const Value2D<T> &delta)
		{
		z##type size_y = object.b.y - object.a.y;

		object.b.x += delta.x;
		object.b.y  = (object.a.y -= delta.y / (z##type)2) + size_y + delta.y;
		return object;
		}


	Z_CT_MEMBER(CPP11) AABR grow_from_center_right(const Value2D<T> &delta)
		{
		z##type size_y = object.b.y - object.a.y;

		object.a.x -= delta.x;
		object.b.y  = (object.a.y -= delta.y / (z##type)2) + size_y + delta.y;
		return object;
		}


	Z_CT_MEMBER(CPP11) AABR grow_from_top_center(const Value2D<T> &delta)
		{
		z##type size_x = object.b.x - object.a.x;

		object.b.x  = (object.a.x -= delta.x / (z##type)2) + size_x + delta.x;
		object.a.y -= delta.y;
		return object;
		}


	Z_CT_MEMBER(CPP11) AABR grow_from_top_left(const Value2D<T> &delta)
		{
		object.b.x += delta.x;
		object.a.y -= delta.y;
		return object;
		}


	Z_CT_MEMBER(CPP11) AABR grow_from_top_right(const Value2D<T> &delta)
		{
		object.a.x -= delta.x;
		object.a.y -= delta.y;
		return object;
		}


	Z_CT_MEMBER(CPP11) AABR grow_in_x_from_center(T delta)
		{
		z##type size_x = object.b.x - object.a.x;

		object.b.x = (object.a.x -= delta / (z##type)2) + size_x + delta;
		return object;
		}


	Z_CT_MEMBER(CPP11) AABR grow_in_x_from_left(T delta)
		{
		object.b.x += delta;
		return object;
		}


	Z_CT_MEMBER(CPP11) AABR grow_in_x_from_right(T delta)
		{
		object.a.x -= delta;
		return object;
		}


	Z_CT_MEMBER(CPP11) AABR grow_in_y_from_bottom(T delta)
		{
		object.b.y += delta;
		return object;
		}


	Z_CT_MEMBER(CPP11) AABR grow_in_y_from_center(T delta)
		{
		z##type size_y = object.b.y - object.a.y;

		object.b.y = (object.a.y -= delta / (z##type)2) + size_y + delta;
		return object;
		}


	Z_CT_MEMBER(CPP11) AABR grow_in_y_from_top(T delta)
		{
		object.a.y -= delta;
		return object;
		}


	Z_CT_MEMBER(CPP11) Boolean intersect(ZAABR##Type a, ZAABR##Type b)
		{return a.a.x < b.b.x && b.a.x < a.b.x && a.a.y < b.b.y && b.a.y < a.b.y;}


	Z_CT_MEMBER(CPP11) AABR z_aabr_##type##_intersection(ZAABR##Type a, ZAABR##Type b)	\
	{											\
	z##type x1, x2, y1, y2;									\
												\
	return	(x1 = z_##type##_maximum(a.a.x, b.a.x)) <=					\
		(x2 = z_##type##_minimum(a.b.x, b.b.x)) &&					\
		(y1 = z_##type##_maximum(a.a.y, b.a.y))	<=					\
		(y2 = z_##type##_minimum(a.b.y, b.b.y))						\
												\
		? z_aabr_##type(x1, y1, x2, y2)							\
		: z_aabr_##type##_zero;								\
	}											\
												\
												\
Z_CT_MEMBER(CPP11) AABR left_half()
	{
	object.b.x = (object.a.x + object.b.x) / (z##type)2;
	return object;										\
	}											\
												\
												\
Z_CT_MEMBER(CPP11) z##type z_aabr_##type##_maximum_x()					\
	{return object.b.x;}									\
												\
												\
Z_CT_MEMBER(CPP11) z##type z_aabr_##type##_maximum_y()					\
	{return object.b.y;}									\
												\
												\
Z_CT_MEMBER(CPP11) z##type z_aabr_##type##_middle_x()					\
	{return (object.a.x + object.b.x) / (z##type)2;}					\
												\
												\
Z_CT_MEMBER(CPP11) z##type z_aabr_##type##_middle_y()					\
	{return (object.a.y + object.b.y) / (z##type)2;}					\
												\
												\
Z_CT_MEMBER(CPP11) z##type z_aabr_##type##_minimum_x()					\
	{return object.a.x;}									\
												\
												\
Z_CT_MEMBER(CPP11) z##type z_aabr_##type##_minimum_y()					\
	{return object.a.y;}									\
												\
												\
Z_CT_MEMBER(CPP11) ZRectangle##Type z_aabr_##type##_rectangle()				\
	{											\
	return z_rectangle_##type								\
		(object.a.x, object.a.y, object.b.x - object.a.x, object.b.y - object.a.y);	\
	}											\
												\
												\
Z_CT_MEMBER(CPP11) ZAABR##Type z_aabr_##type##_right_half()				\
	{											\
	object.a.x = (object.a.x + object.b.x) / (z##type)2;					\
	return object;										\
	}											\
												\
												\
Z_CT_MEMBER(CPP11) ZAABR##Type z_aabr_##type##_shrink_from_bottom_center(const Value2D<T> &delta)
	{											\
	z##type size_x = object.b.x - object.a.x;						\
												\
	object.b.x  = (object.a.x += delta.x / (z##type)2) + size_x - delta.x;			\
	object.b.y -= delta.y;									\
	return object;										\
	}											\
												\
												\
Z_CT_MEMBER(CPP11) ZAABR##Type z_aabr_##type##_shrink_from_bottom_left(const Value2D<T> &delta)
	{											\
	object.b.x -= delta.x;									\
	object.b.y -= delta.y;									\
	return object;										\
	}											\
												\
												\
Z_CT_MEMBER(CPP11) ZAABR##Type z_aabr_##type##_shrink_from_bottom_right(const Value2D<T> &delta)\
	{											\
	object.a.x += delta.x;									\
	object.b.y -= delta.y;									\
	return object;										\
	}											\
												\
												\
Z_CT_MEMBER(CPP11) ZAABR##Type z_aabr_##type##_shrink_from_center(const Value2D<T> &delta)
	{											\
	z##type size_x = object.b.x - object.a.x;						\
	z##type size_y = object.b.y - object.a.y;						\
												\
	object.b.x = (object.a.x += delta.x / (z##type)2) + size_x - delta.x;			\
	object.b.y = (object.a.y += delta.y / (z##type)2) + size_y - delta.y;			\
	return object;										\
	}											\
												\
												\
Z_CT_MEMBER(CPP11) ZAABR##Type z_aabr_##type##_shrink_from_center_left(const Value2D<T> &delta)
	{											\
	z##type size_y = object.b.y - object.a.y;						\
												\
	object.b.x -= delta.x;									\
	object.b.y  = (object.a.y += delta.y / (z##type)2) + size_y - delta.y;			\
	return object;										\
	}											\
												\
												\
Z_CT_MEMBER(CPP11) ZAABR##Type z_aabr_##type##_shrink_from_center_right(const Value2D<T> &delta)
	{											\
	z##type size_y = object.b.y - object.a.y;						\
												\
	object.a.x += delta.x;									\
	object.b.y  = (object.a.y += delta.y / (z##type)2) + size_y - delta.y;			\
	return object;										\
	}											\
												\
												\
Z_CT_MEMBER(CPP11) ZAABR##Type z_aabr_##type##_shrink_from_top_center(const Value2D<T> &delta)
	{											\
	z##type size_x = object.b.x - object.a.x;						\
												\
	object.b.x  = (object.a.x += delta.x / (z##type)2) + size_x - delta.x;			\
	object.a.y += delta.y;									\
	return object;										\
	}											\
												\
												\
Z_CT_MEMBER(CPP11) ZAABR##Type z_aabr_##type##_shrink_from_top_left(const Value2D<T> &delta)
	{											\
	object.b.x -= delta.x;									\
	object.a.y += delta.y;									\
	return object;										\
	}											\
												\
												\
Z_CT_MEMBER(CPP11) ZAABR##Type z_aabr_##type##_shrink_from_top_right(const Value2D<T> &delta)
	{											\
	object.a.x += delta.x;									\
	object.a.y += delta.y;									\
	return object;										\
	}											\
												\
												\
Z_CT_MEMBER(CPP11) ZAABR##Type z_aabr_##type##_shrink_in_x_from_center(T delta)
	{											\
	z##type size_x = object.b.x - object.a.x;						\
												\
	object.b.x = (object.a.x += delta / (z##type)2) + size_x - delta;			\
	return object;										\
	}											\
												\
												\
Z_CT_MEMBER(CPP11) ZAABR##Type z_aabr_##type##_shrink_in_x_from_left(T delta)
	{											\
	object.b.x -= delta;									\
	return object;										\
	}											\
												\
												\
Z_CT_MEMBER(CPP11) ZAABR##Type z_aabr_##type##_shrink_in_x_from_right(T delta)
	{											\
	object.a.x += delta;									\
	return object;										\
	}											\
												\
												\
Z_CT_MEMBER(CPP11) AABR z_aabr_##type##_shrink_in_y_from_bottom(T delta) \
	{											\
	object.b.y -= delta;									\
	return object;										\
	}											\
												\
												\
Z_CT_MEMBER(CPP11) AABR z_aabr_##type##_shrink_in_y_from_center(T delta)	\
	{											\
	z##type size_y = object.b.y - object.a.y;						\
												\
	object.b.y = (object.a.y += delta / (z##type)2) + size_y - delta;			\
	return object;										\
	}											\
												\
												\
Z_CT_MEMBER(CPP11) AABR z_aabr_##type##_shrink_in_y_from_top(T delta)	\
	{											\
	object.a.y += delta;									\
	return object;										\
	}											\
												\
												\
Z_CT_MEMBER(CPP11) Z2D##Type z_aabr_##type##_top_center()				\
	{return z_2d_##type((object.a.x + object.b.x) / (z##type)2, object.b.y);}		\
												\
												\
Z_CT_MEMBER(CPP11) AABR z_aabr_##type##_top_half()				\
	{											\
	object.a.y = (object.a.y + object.b.y) / (z##type)2;					\
	return object;										\
	}											\
												\
												\
	Z_INLINE Value2D<T> top_left()
		{return Value2D<T>(this->a.x, this->b.y);}
												\
												\
Z_CT_MEMBER(CPP11) AABR z_aabr_##type##_top_left_quarter()
	{											\
	object.b.x = (object.a.x + object.b.x) / (z##type)2;					\
	object.a.y = (object.a.y + object.b.y) / (z##type)2;					\
	return object;										\
	}											\
												\
												\
Z_CT_MEMBER(CPP11) Z2D##Type z_aabr_##type##_top_right()				\
	{return object.b;}									\
												\
												\
Z_CT_MEMBER(CPP11) AABR z_aabr_##type##_top_right_quarter()			\
	{											\
	object.a.x = (object.a.x + object.b.x) / (z##type)2;					\
	object.a.y = (object.a.y + object.b.y) / (z##type)2;					\
	return object;										\
	}											\
												\
												\
Z_CT_MEMBER(CPP11) AABR z_aabr_##type##_union(ZAABR##Type a, ZAABR##Type b)			\
	{											\
	ZAABR##Type result;									\
												\
	result.a = z_2d_##type##_minimum(a.a, b.a);						\
	result.b = z_2d_##type##_maximum(a.b, b.b);						\
	return result;										\
	}

};}


#endif // _Z_classes_mathematics_geometry_euclidean_AABR_HPP_
