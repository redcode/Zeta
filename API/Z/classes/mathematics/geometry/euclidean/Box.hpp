/* Z Kit - classes/mathematics/geometry/euclidean/Box.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_classes_mathematics_geometry_euclidean_Box_HPP_
#define _Z_classes_mathematics_geometry_euclidean_Box_HPP_

#include <Z/classes/base/Value3D.hpp>
#include <Z/types/mathematics.h>


#define Z_IMPLEMENTATION_COMMON									\
												\
typedef typename ZTypeFixedSigned(ZBox, T) Base;						\
Value3D<T> point, size;										\
												\
Z_INLINE Box() Z_DEFAULTED({})									\
												\
												\
Z_CT(CPP11) Box(const Value3D<T> &point, const Value3D<T> &size)				\
: point(point), size(size) {}									\
												\
												\
Z_CT(CPP11) Box(const Value3D<T> &point, T size_x, T size_y, T size_z)				\
: point(point), size(size_x, size_y, size_z) {}							\
												\
												\
Z_CT(CPP11) Box(const Value3D<T> &point, T size_xyz)						\
: point(point), size(size_xyz) {}								\
												\
												\
Z_CT(CPP11) Box(T point_x, T point_y, T point_z, const Value3D<T> &size)			\
: point(point_x, point_y, point_z), size(size) {}						\
												\
												\
Z_CT(CPP11) Box(T point_x, T point_y, T point_z, T size_x, T size_y, T size_z)			\
: point(point_x, point_y, point_z), size(size_x, size_y, size_z) {}				\
												\
												\
Z_CT(CPP11) Box(T point_x, T point_y, T point_z, T size_xyz)					\
: point(point_x, point_y, point_z), size(size_xyz) {}						\
												\
												\
Z_CT(CPP11) Box(T point_xyz, const Value3D<T> &size)						\
: point(point_xyz), size(size) {}								\
												\
												\
Z_CT(CPP11) Box(const Value3D<T> &size)								\
: point(T(0)), size(size) {}									\
												\
												\
Z_CT(CPP11) Box(T size_x, T size_y, T size_z)							\
: point(T(0)), size(size_x, size_y, size_z) {}							\
												\
												\
Z_CT(CPP11) Box(T size_xyz)									\
: point(T(0)), size(size_xyz) {}								\
												\
												\
static Z_CT(CPP14) Box from_vertices(const Value3D<T> &a, const Value3D<T> &b)			\
	{											\
	Value3D<T> minimum = a.minimum(b);							\
												\
	return Box(minimum, a.maximum(b) - minimum);						\
	}											\
												\
												\
Z_CT(CPP11) operator Boolean() const {return point || size;}					\
Z_INLINE    operator Base&  () const {return *((Base *)this);}					\
												\
												\
Z_CT(CPP11) Boolean operator ==(const Box &rhs) const						\
	{return point == rhs.point && size == rhs.size;}					\
												\
												\
Z_CT(CPP11) Boolean operator !=(const Box &rhs) const						\
	{return point != rhs.point || size != rhs.size;}					\
												\
												\
/* Intersection */										\
Z_CT(CPP14) Box operator &(const Box &rhs) const						\
	{											\
	T x1, x2, y1, y2, z1, z2;								\
												\
	return	(x1 = maximum<T>(point.x,	   rhs.point.x)) <				\
		(x2 = minimum<T>(point.x + size.x, rhs.point.x + rhs.size.x)) &&		\
		(y1 = maximum<T>(point.y,	   rhs.point.y)) <				\
		(y2 = minimum<T>(point.y + size.y, rhs.point.y + rhs.size.y)) &&		\
		(z1 = maximum<T>(point.z,	   rhs.point.z)) <				\
		(z2 = minimum<T>(point.z + size.z, rhs.point.z + rhs.size.z))			\
												\
		? Box(x1, y1, z1, x2 - x1, y2 - y1, z2 - z1)					\
		: Box(T(0));									\
	}											\
												\
												\
/* Union */											\
Z_CT(CPP14) Box operator |(const Box &rhs) const						\
	{											\
	Box result;										\
												\
	result.point = point.minimum(rhs.point);						\
	result.size  = (point + size).maximum(rhs.point + rhs.size) - result.point;		\
	return result;										\
	}											\
												\
												\
Z_INLINE Box &operator &=(const Box &rhs) {return *this = *this & rhs;}				\
Z_INLINE Box &operator |=(const Box &rhs) {return *this = *this | rhs;}				\
												\
Z_CT(CPP11) Box operator +(const Value3D<T> &rhs) const {return Box(point + rhs, size);}	\
Z_CT(CPP11) Box operator -(const Value3D<T> &rhs) const {return Box(point - rhs, size);}	\
Z_CT(CPP11) Box operator *(const Value3D<T> &rhs) const {return Box(point * rhs, size);}	\
Z_CT(CPP11) Box operator /(const Value3D<T> &rhs) const {return Box(point / rhs, size);}	\
												\
Z_INLINE Box &operator +=(const Value3D<T> &rhs) {return *this = *this + rhs;}			\
Z_INLINE Box &operator -=(const Value3D<T> &rhs) {return *this = *this - rhs;}			\
Z_INLINE Box &operator *=(const Value3D<T> &rhs) {return *this = *this * rhs;}			\
Z_INLINE Box &operator /=(const Value3D<T> &rhs) {return *this = *this / rhs;}			\
												\
Z_CT(CPP11) Box operator +(T rhs) const {return Value3D<T>(point + rhs, size);}			\
Z_CT(CPP11) Box operator -(T rhs) const {return Value3D<T>(point - rhs, size);}			\
Z_CT(CPP11) Box operator *(T rhs) const {return Value3D<T>(point * rhs, size);}			\
Z_CT(CPP11) Box operator /(T rhs) const {return Value3D<T>(point / rhs, size);}			\
												\
Z_INLINE Box &operator +=(T rhs) {return *this = *this + rhs;}					\
Z_INLINE Box &operator -=(T rhs) {return *this = *this - rhs;}					\
Z_INLINE Box &operator *=(T rhs) {return *this = *this * rhs;}					\
Z_INLINE Box &operator /=(T rhs) {return *this = *this / rhs;}					\
												\
												\
Z_CT(CPP11) Value3D<T> center() const								\
	{return point + size / T(2);}								\
												\
												\
Z_CT(CPP11) Boolean contains(const Box &other) const						\
	{											\
	return	!other.size.has_zero() &&							\
		other.point >= point && other.point + other.size <= point + size;		\
	}											\
												\
												\
/*Z_CT(CPP11) Boolean contains(const AABB<T> &aabb) const					\
	{											\
	return	aabb.a.x != aabb.b.x && aabb.a.y != aabb.b.y && aabb.a.z != aabb.b.z &&		\
		aabb.a >= point && aabb.b <= point + size;					\
	}*/											\
												\
												\
Z_CT(CPP11) Boolean contains(const Value3D<T> &point) const					\
	{return point >= this->point && point < this->point + this->size;}			\
												\
												\
Z_CT(CPP11) Boolean intersects(const Box &other) const						\
	{											\
	return	!size.has_zero() && !other.size.has_zero() &&					\
		other.point + other.size > point && other.point < point + size;			\
	}											\
												\
												\
Z_CT(CPP11) Boolean is_zero() const								\
	{return point.is_zero() && size.is_zero();}						\
												\
												\
Z_INLINE Box &correct()										\
	{											\
	if (size.x < T(0)) point.x -= (size.x = -size.x);					\
	if (size.y < T(0)) point.y -= (size.y = -size.y);					\
	if (size.z < T(0)) point.z -= (size.z = -size.z);					\
	return *this;										\
	}											\
												\
												\
Z_INLINE void swap(Box &other)									\
	{Zeta::swap<Base>((Base *)this, (Base *)&other);}					\
};}


namespace Zeta {
	template <class T, UInt T_number_set = Type<T>::number_set> struct Box {};


	template <class T> struct Box<T, Z_NUMBER_SET_Z> {
		Z_IMPLEMENTATION_COMMON
	};


	template <class T> struct Box<T, Z_NUMBER_SET_R> {
		Z_IMPLEMENTATION_COMMON


		Z_CT(CPP11) Value3D<T> absolute_point_to_unit(const Value3D<T> &point) const
			{return (point - this->point) / this->size;}


		/*Z_CT(CPP11) Boolean contains(const Sphere<T> &sphere) const
			{
			return	sphere.radius != T(0)		      &&
				sphere.point - sphere.radius >= point &&
				sphere.point + sphere.radius <= point + size;
			}*/


		/*Z_CT(CPP11) Sphere<T> inner_sphere() const
			{return Sphere<T>(center(), size.inner_minimum() / T(2));}*/


		Z_CT(CPP11) Value3D<T> unit_point_to_absolute(const Value3D<T> &point) const
			{return point * this->size + this->point;}
	};
}


#undef Z_IMPLEMENTATION_COMMON

#endif // _Z_classes_mathematics_geometry_euclidean_Box_HPP_
