/* Z Kit C++ API - classes/base/Value3D.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_classes_base_Value3D_HPP__
#define __Z_classes_base_Value3D_HPP__

#ifndef __Z_classes_base_Value2D_HPP__
#	include <Z/classes/base/Value2D.hpp>
#endif


namespace Zeta {namespace Partials {namespace Value3D {

#	define Z_THIS ((Value3D *)this)

	template <class Base, class Value3D, class T, UInt T_number_set> struct Part;


	template <class Base, class Value3D, class T> struct Signed : Base {

#		if Z_LANGUAGE_HAS(CPP, INITIALIZER_LIST)
			Z_INLINE_MEMBER	   Signed() {}
			Z_CT_MEMBER(CPP11) Signed(T x, T y, T z) : Base{x, y, z} {}
#		endif


		Z_CT_MEMBER(CPP11) Value3D absolute() const
			{
			return Value3D
				(Zeta::absolute<T>(this->x),
				 Zeta::absolute<T>(this->y),
				 Zeta::absolute<T>(this->z));
			}


		Z_CT_MEMBER(CPP11) Boolean has_negative() const
			{return this->x < T(0) || this->y < T(0) || this->z < T(0);}


		Z_CT_MEMBER(CPP11) Boolean is_negative() const
			{return this->x < T(0) && this->y < T(0) && this->z < T(0);}


		Z_CT_MEMBER(CPP11) Value3D negative() const
			{return Value3D(-this->x, -this->y, -this->z);}
	};


	template <class Base, class Value3D, class T>
	struct Part<Base, Value3D, T, Z_NUMBER_SET_N> : Base {

#		if Z_LANGUAGE_HAS(CPP, INITIALIZER_LIST)
			Z_INLINE_MEMBER	   Part() {}
			Z_CT_MEMBER(CPP11) Part(T x, T y, T z) : Base{x, y, z} {}
#		endif
	};


	template <class Base, class Value3D, class T>
	struct Part<Base, Value3D, T, Z_NUMBER_SET_Z> : Signed<Base, Value3D, T> {

#		if Z_LANGUAGE_HAS(CPP, INITIALIZER_LIST)
			Z_INLINE_MEMBER	   Part() {}
			Z_CT_MEMBER(CPP11) Part(T x, T y, T z) : Signed<Base, Value3D, T>(x, y, z) {}
#		endif


		Z_CT_MEMBER(CPP11) Boolean is_perpendicular(const Value3D &other) const
			{return !Zeta::absolute<T>(Z_THIS->dot_product(other));}
	};


	template <class Base, class Value3D, class T>
	struct Part<Base, Value3D, T, Z_NUMBER_SET_R> : Signed<Base, Value3D, T> {

#		if Z_LANGUAGE_HAS(CPP, INITIALIZER_LIST)
			Z_INLINE_MEMBER	   Part() {}
			Z_CT_MEMBER(CPP11) Part(T x, T y) : Signed<Base, Value3D, T>(x, y, z) {}
#		endif


		Z_CT_MEMBER(CPP11) Value3D clamp_01() const
			{
			return Value3D
				(Zeta::clamp_01<T>(this->x),
				 Zeta::clamp_01<T>(this->y),
				 Zeta::clamp_01<T>(this->z));
			}


		Z_CT_MEMBER(CPP11) Boolean has_almost_zero() const
			{
			return	Zeta::is_almost_zero<T>(this->x) ||
				Zeta::is_almost_zero<T>(this->y) ||
				Zeta::is_almost_zero<T>(this->z);
			}


		Z_CT_MEMBER(CPP11) Boolean has_finite() const
			{
			return	Zeta::is_finite<T>(this->x) ||
				Zeta::is_finite<T>(this->y) ||
				Zeta::is_finite<T>(this->z);
			}


		Z_CT_MEMBER(CPP11) Boolean has_infinity() const
			{
			return	Zeta::is_infinity<T>(this->x) ||
				Zeta::is_infinity<T>(this->y) ||
				Zeta::is_infinity<T>(this->z);
			}


		Z_CT_MEMBER(CPP11) Boolean has_nan() const
			{
			return	Zeta::is_nan<T>(this->x) ||
				Zeta::is_nan<T>(this->y) ||
				Zeta::is_nan<T>(this->z);
			}


		Z_CT_MEMBER(CPP11) Value3D inverse_lerp(const Value3D &other, T t) const
			{
			return Value3D
				(Zeta::inverse_lerp<T>(this->x, other.x, t),
				 Zeta::inverse_lerp<T>(this->y, other.y, t),
				 Zeta::inverse_lerp<T>(this->z, other.z, t));
			}


		Z_CT_MEMBER(CPP11) Boolean is_almost_equal(const Value3D &other) const
			{
			return	Zeta::are_almost_equal<T>(this->x, other.x) &&
				Zeta::are_almost_equal<T>(this->y, other.y) &&
				Zeta::are_almost_equal<T>(this->z, other.z);
			}


		Z_CT_MEMBER(CPP11) Boolean is_almost_zero() const
			{
			return	Zeta::is_almost_zero<T>(this->x) &&
				Zeta::is_almost_zero<T>(this->y) &&
				Zeta::is_almost_zero<T>(this->z);
			}


		Z_CT_MEMBER(CPP11) Boolean is_finite() const
			{
			return	Zeta::is_finite<T>(this->x) &&
				Zeta::is_finite<T>(this->y) &&
				Zeta::is_finite<T>(this->z);
			}


		Z_CT_MEMBER(CPP11) Boolean is_infinity() const
			{
			return	Zeta::is_infinity<T>(this->x) &&
				Zeta::is_infinity<T>(this->y) &&
				Zeta::is_infinity<T>(this->z);
			}


		Z_CT_MEMBER(CPP11) Boolean is_nan() const
			{
			return	Zeta::is_nan<T>(this->x) &&
				Zeta::is_nan<T>(this->y) &&
				Zeta::is_nan<T>(this->z);
			}


		Z_CT_MEMBER(CPP11) Boolean is_perpendicular(const Value3D &other) const
			{return Zeta::absolute<T>(Z_THIS->dot_product(other)) <= Type<T>::epsilon();}


		Z_CT_MEMBER(CPP11) Value3D lerp(const Value3D &other, T t) const
			{
			return Value3D
				(Zeta::lerp<T>(this->x, other.x, t),
				 Zeta::lerp<T>(this->y, other.y, t),
				 Zeta::lerp<T>(this->z, other.z, t));
			}


		Z_CT_MEMBER(CPP11) Value3D reciprocal() const
			{return Value3D(T(1) / this->x, T(1) / this->y, T(1) / this->z);}
	};


#	undef Z_THIS
}}}


namespace Zeta {template <class T> struct Value3D
: Partials::Value3D::Part<typename ZTypeFixedNumber(Z3D, T), Value3D<T>, T, Type<T>::number_set> {

	typedef typename ZTypeFixedNumber(Z3D, T) Base;
	typedef Partials::Value3D::Part<Base, Value3D, T, Type<T>::number_set> Super;

	Z_INLINE_MEMBER Value3D() {}

#	if Z_LANGUAGE_HAS(CPP, INITIALIZER_LIST)
		Z_CT_MEMBER(CPP11) Value3D(T x, T y, T z)	      : Super(x,       y,	z      ) {}
		Z_CT_MEMBER(CPP11) Value3D(T x, T y)		      : Super(x,       y,	T(0)   ) {}
		Z_CT_MEMBER(CPP11) Value3D(T xyz)		      : Super(xyz,     xyz,	xyz    ) {}
		Z_CT_MEMBER(CPP11) Value3D(const Value2D<T> &xy)      : Super(xy.x,    xy.y,	T(0)   ) {}
		Z_CT_MEMBER(CPP11) Value3D(const Value2D<T> &xy, T z) : Super(xy.x,    xy.y,	z      ) {}
		Z_CT_MEMBER(CPP11) Value3D(T x, const Value2D<T> &yz) : Super(x,       yz.x,	yz.y   ) {}
		Z_CT_MEMBER(CPP11) Value3D(const Base &other)	      : Super(other.x, other.y, other.z) {}
#	else
		Z_INLINE_MEMBER Value3D(T x, T y, T z)		   {this->x = x;    this->y = y;    this->z = z;   }
		Z_INLINE_MEMBER Value3D(T x, T y)		   {this->x = x;    this->y = y;    this->z = T(0);}
		Z_INLINE_MEMBER Value3D(T xyz)			   {this->x = xyz;  this->y = xyz;  this->z = xyz; }
		Z_INLINE_MEMBER Value3D(const Value2D<T> &xy)	   {this->x = xy.x; this->y = xy.y; this->z = T(0);}
		Z_INLINE_MEMBER Value3D(const Value2D<T> &xy, T z) {this->x = xy.x; this->y = xy.y; this->z = z;   }
		Z_INLINE_MEMBER Value3D(T x, const Value2D<T> &yz) {this->x = x;    this->y = yz.x; this->z = yz.y;}
		Z_INLINE_MEMBER Value3D(const Base &other)	   {*(Base *)this = other;}
#	endif

	Z_CT_MEMBER(CPP11) operator Boolean() const {return this->x != T(0) || this->y != T(0) || this->z != T(0);}

	Z_CT_MEMBER(CPP11) Boolean operator ==(const Value3D &rhs) const {return this->x == rhs.x && this->y == rhs.y && this->z == rhs.z;}
	Z_CT_MEMBER(CPP11) Boolean operator !=(const Value3D &rhs) const {return this->x != rhs.x || this->y != rhs.y || this->z != rhs.z;}
	Z_CT_MEMBER(CPP11) Boolean operator <=(const Value3D &rhs) const {return this->x <= rhs.x && this->y <= rhs.y && this->z <= rhs.z;}
	Z_CT_MEMBER(CPP11) Boolean operator >=(const Value3D &rhs) const {return this->x >= rhs.x && this->y >= rhs.y && this->z >= rhs.z;}
	Z_CT_MEMBER(CPP11) Boolean operator > (const Value3D &rhs) const {return this->x >  rhs.x && this->y >	rhs.y && this->z >  rhs.z;}
	Z_CT_MEMBER(CPP11) Boolean operator < (const Value3D &rhs) const {return this->x <  rhs.x && this->y <	rhs.y && this->z <  rhs.z;}

	Z_CT_MEMBER(CPP11) Value3D operator +(const Value3D &rhs) const {return Value3D(this->x + rhs.x, this->y + rhs.y, this->z + rhs.z);}
	Z_CT_MEMBER(CPP11) Value3D operator -(const Value3D &rhs) const {return Value3D(this->x - rhs.x, this->y - rhs.y, this->z - rhs.z);}
	Z_CT_MEMBER(CPP11) Value3D operator *(const Value3D &rhs) const {return Value3D(this->x * rhs.x, this->y * rhs.y, this->z * rhs.z);}
	Z_CT_MEMBER(CPP11) Value3D operator /(const Value3D &rhs) const {return Value3D(this->x / rhs.x, this->y / rhs.y, this->z / rhs.z);}

	Z_INLINE_MEMBER Value3D &operator +=(const Value3D &rhs) {return *this = *this + rhs;}
	Z_INLINE_MEMBER Value3D &operator -=(const Value3D &rhs) {return *this = *this - rhs;}
	Z_INLINE_MEMBER Value3D &operator *=(const Value3D &rhs) {return *this = *this * rhs;}
	Z_INLINE_MEMBER Value3D &operator /=(const Value3D &rhs) {return *this = *this / rhs;}

	Z_CT_MEMBER(CPP11) Boolean operator ==(T rhs) const {return this->x == rhs && this->y == rhs && this->z == rhs;}
	Z_CT_MEMBER(CPP11) Boolean operator !=(T rhs) const {return this->x != rhs || this->y != rhs || this->z != rhs;}
	Z_CT_MEMBER(CPP11) Boolean operator <=(T rhs) const {return this->x <= rhs && this->y <= rhs && this->z <= rhs;}
	Z_CT_MEMBER(CPP11) Boolean operator >=(T rhs) const {return this->x >= rhs && this->y >= rhs && this->z >= rhs;}
	Z_CT_MEMBER(CPP11) Boolean operator > (T rhs) const {return this->x >  rhs && this->y >  rhs && this->z >  rhs;}
	Z_CT_MEMBER(CPP11) Boolean operator < (T rhs) const {return this->x <  rhs && this->y <  rhs && this->z <  rhs;}

	Z_CT_MEMBER(CPP11) Value3D operator +(T rhs) const {return Value3D(this->x + rhs, this->y + rhs, this->z + rhs);}
	Z_CT_MEMBER(CPP11) Value3D operator -(T rhs) const {return Value3D(this->x - rhs, this->y - rhs, this->z - rhs);}
	Z_CT_MEMBER(CPP11) Value3D operator *(T rhs) const {return Value3D(this->x * rhs, this->y * rhs, this->z * rhs);}
	Z_CT_MEMBER(CPP11) Value3D operator /(T rhs) const {return Value3D(this->x / rhs, this->y / rhs, this->z / rhs);}

	Z_INLINE_MEMBER Value3D &operator +=(T rhs) {return *this = *this + rhs;}
	Z_INLINE_MEMBER Value3D &operator -=(T rhs) {return *this = *this - rhs;}
	Z_INLINE_MEMBER Value3D &operator *=(T rhs) {return *this = *this * rhs;}
	Z_INLINE_MEMBER Value3D &operator /=(T rhs) {return *this = *this / rhs;}

	Z_INLINE_MEMBER T  operator [](UInt index) const {return ((T *)this)[index];}
	Z_INLINE_MEMBER T &operator [](UInt index)	 {return ((T *)this)[index];}


	Z_CT_MEMBER(CPP11) Value3D clamp(const Value3D &minimum, const Value3D &maximum) const
		{
		return Value3D
			(Zeta::clamp<T>(this->x, minimum.x, maximum.x),
			 Zeta::clamp<T>(this->y, minimum.y, maximum.y),
			 Zeta::clamp<T>(this->z, minimum.z, maximum.z));
		}


	Z_CT_MEMBER(CPP11) Value3D clamp(T minimum, T maximum) const
		{
		return Value3D
			(Zeta::clamp<T>(this->x, minimum, maximum),
			 Zeta::clamp<T>(this->y, minimum, maximum),
			 Zeta::clamp<T>(this->z, minimum, maximum));
		}


	Z_CT_MEMBER(CPP11) Value3D cross_product(const Value3D &other) const
		{
		return Value3D
			(this->y * other.z - this->z * other.y,
			 this->z * other.x - this->x * other.z,
			 this->x * other.y - this->y * other.x);
		}


	Z_CT_MEMBER(CPP11) T dot_product(const Value3D &other) const
		{return this->x * other.x + this->y * other.y + this->z * other.z;}


	Z_CT_MEMBER(CPP11) Value3D fit(const Value3D &other) const
		{return Value3D(T(0));} // TODO


	Z_CT_MEMBER(CPP11) Boolean has_zero() const
		{return this->x == T(0) || this->y == T(0) || this->z == T(0);}


	Z_CT_MEMBER(CPP11) T inner_maximum() const
		{return Zeta::maximum<T>(Zeta::maximum<T>(this->x, this->y), this->z);}


	Z_CT_MEMBER(CPP11) T inner_middle() const
		{return (this->x + this->y + this->z) / T(3);}


	Z_CT_MEMBER(CPP11) T inner_minimum() const
		{return Zeta::minimum<T>(Zeta::minimum<T>(this->x, this->y), this->z);}


	Z_CT_MEMBER(CPP11) T inner_product() const
		{return this->x * this->y * this->z;}


	Z_CT_MEMBER(CPP11) T inner_sum() const
		{return this->x + this->y + this->z;}


	Z_CT_MEMBER(CPP11) Boolean is_zero() const
		{return this->x == T(0) && this->y == T(0) && this->z == T(0);}


	Z_CT_MEMBER(CPP11) Value3D maximum(const Value3D &other) const
		{
		return Value3D
			(Zeta::maximum<T>(this->x, other.x),
			 Zeta::maximum<T>(this->y, other.y),
			 Zeta::maximum<T>(this->z, other.z));
		}


	Z_CT_MEMBER(CPP11) Value3D middle(const Value3D &other) const
		{
		return Value3D
			((this->x + other.x) / T(2),
			 (this->y + other.y) / T(2),
			 (this->z + other.z) / T(2));
		}


	Z_CT_MEMBER(CPP11) Value3D minimum(const Value3D &other) const
		{
		return Value3D
			(Zeta::minimum<T>(this->x, other.x),
			 Zeta::minimum<T>(this->y, other.y),
			 Zeta::minimum<T>(this->z, other.z));
		}


	Z_INLINE_MEMBER Value3D rotate_as_axes(Value3D<SInt8> rotation) const
		{
		Value3D result = *this;

		if ((rotation.x % 4) & 1) Zeta::swap<T>(&result.y, &result.z);
		if ((rotation.y % 4) & 1) Zeta::swap<T>(&result.x, &result.z);
		if ((rotation.z % 4) & 1) Zeta::swap<T>(&result.x, &result.y);
		return result;
		}


	Z_CT_MEMBER(CPP11) T squared_length() const
		{return this->x * this->x + this->y * this->y + this->z * this->z;}


	Z_INLINE_MEMBER void swap(Value3D &other)
		{Zeta::swap<Base>(this, &other);}


	Z_CT_MEMBER(CPP11) Value2D<T> xy() const
		{return Value2D<T>(this->x, this->y);}


	Z_CT_MEMBER(CPP11) Value2D<T> xz() const
		{return Value2D<T>(this->x, this->z);}


	Z_CT_MEMBER(CPP11) Value3D xzy() const
		{return Value3D(this->x, this->z, this->y);}


	Z_CT_MEMBER(CPP11) Value2D<T> yx() const
		{return Value2D<T>(this->y, this->x);}


	Z_CT_MEMBER(CPP11) Value3D yxz() const
		{return Value3D(this->y, this->x, this->z);}


	Z_CT_MEMBER(CPP11) Value2D<T> yz() const
		{return Value2D<T>(this->y, this->z);}


	Z_CT_MEMBER(CPP11) Value3D yzx() const
		{return Value3D(this->y, this->z, this->x);}


	Z_CT_MEMBER(CPP11) Value2D<T> zx() const
		{return Value2D<T>(this->z, this->x);}


	Z_CT_MEMBER(CPP11) Value3D zxy() const
		{return Value3D(this->z, this->x, this->y);}


	Z_CT_MEMBER(CPP11) Value2D<T> zy() const
		{return Value2D<T>(this->z, this->y);}


	Z_CT_MEMBER(CPP11) Value3D zyx() const
		{return Value3D(this->z, this->y, this->x);}
};}


#endif // __Z_classes_base_Value3D_HPP__
