/* Zeta API - Z/classes/XYZ.hpp
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_classes_XYZ_HPP
#define Z_classes_XYZ_HPP

#ifndef Z_classes_XY_HPP
#	include <Z/classes/XY.hpp>
#endif


namespace Zeta {template <class t> struct XYZ {
	t x, y, z;


	Z_INLINE XYZ() Z_NOTHROW Z_DEFAULTED({})

	Z_CT(CPP11) XYZ(t x_, t y_, t z_) Z_NOTHROW
	: x(x_), y(y_), z(z_) {}


	Z_CT(CPP11) XYZ(t x_, t y_) Z_NOTHROW
	: x(x_), y(y_), z(t(0)) {}


	Z_CT(CPP11) XYZ(t xyz) Z_NOTHROW
	: x(xyz), y(xyz) {}


	Z_CT(CPP11) XYZ(const XY<t> &xy) Z_NOTHROW
	: x(xy.x), y(xy.y), z(t(0)) {}


	Z_CT(CPP11) XYZ(const XY<t> &xy, t z_) Z_NOTHROW
	: x(xy.x), y(xy.y), z(z_) {}


	Z_CT(CPP11) XYZ(t x_, const XY<t> &yz) Z_NOTHROW
	: x(x_), y(yz.x), z(yz.y) {}


#	if	Z_DIALECT_HAS(CPP98, SFINAE) && \
		Z_DIALECT_HAS(CPP11, DEFAULT_TEMPLATE_ARGUMENTS_FOR_FUNCTION_TEMPLATE)

		template <class other_t, class e = typename TypeIf<!TypeIsSame<t, other_t>::value>::type>
		Z_CT(CPP11) XYZ(const XYZ<other_t> &other) Z_NOTHROW
		: x(t(other.x)), y(t(other.y), x(t(other.z))) {}
#	endif


	Z_CT(CPP11) operator Boolean() const Z_NOTHROW
		{return x != t(0) || y != t(0) || z != t(0);}


	friend Z_CT(CPP11) Boolean operator ==(const XYZ &lhs, const XYZ &rhs) Z_NOTHROW
		{return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;}


	friend Z_CT(CPP11) Boolean operator !=(const XYZ &lhs, const XYZ &rhs) Z_NOTHROW
		{return lhs.x != rhs.x || lhs.y != rhs.y || lhs.z != rhs.z;}


	friend Z_CT(CPP11) Boolean operator >=(const XYZ &lhs, const XYZ &rhs) Z_NOTHROW
		{return lhs.x >= rhs.x && lhs.y >= rhs.y && lhs.z >= rhs.z;}


	friend Z_CT(CPP11) Boolean operator <=(const XYZ &lhs, const XYZ &rhs) Z_NOTHROW
		{return lhs.x <= rhs.x && lhs.y <= rhs.y && lhs.z <= rhs.z;}


	friend Z_CT(CPP11) Boolean operator >(const XYZ &lhs, const XYZ &rhs) Z_NOTHROW
		{return lhs.x > rhs.x && lhs.y > rhs.y && lhs.z > rhs.z;}


	friend Z_CT(CPP11) Boolean operator <(const XYZ &lhs, const XYZ &rhs) Z_NOTHROW
		{return lhs.x < rhs.x && lhs.y < rhs.y && lhs.z < rhs.z;}


	friend Z_CT(CPP11) XYZ operator +(const XYZ &lhs, const XYZ &rhs) Z_NOTHROW
		{return XYZ(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);}


	friend Z_CT(CPP11) XYZ operator -(const XYZ &lhs, const XYZ &rhs) Z_NOTHROW
		{return XYZ(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);}


	friend Z_CT(CPP11) XYZ operator *(const XYZ &lhs, const XYZ &rhs) Z_NOTHROW
		{return XYZ(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z);}


	friend Z_CT(CPP11) XYZ operator /(const XYZ &lhs, const XYZ &rhs) Z_NOTHROW
		{return XYZ(lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z);}


	friend Z_CT(CPP11) Boolean operator ==(const XYZ &lhs, t rhs) Z_NOTHROW
		{return lhs.x == rhs && lhs.y == rhs && lhs.z == rhs;}


	friend Z_CT(CPP11) Boolean operator !=(const XYZ &lhs, t rhs) Z_NOTHROW
		{return lhs.x != rhs || lhs.y != rhs || lhs.z != rhs;}


	friend Z_CT(CPP11) Boolean operator >=(const XYZ &lhs, t rhs) Z_NOTHROW
		{return lhs.x >= rhs && lhs.y >= rhs && lhs.z >= rhs;}


	friend Z_CT(CPP11) Boolean operator <=(const XYZ &lhs, t rhs) Z_NOTHROW
		{return lhs.x <= rhs && lhs.y <= rhs && lhs.z <= rhs;}


	friend Z_CT(CPP11) Boolean operator >(const XYZ &lhs, t rhs) Z_NOTHROW
		{return lhs.x > rhs && lhs.y > rhs && lhs.z > rhs;}


	friend Z_CT(CPP11) Boolean operator <(const XYZ &lhs, t rhs) Z_NOTHROW
		{return lhs.x < rhs && lhs.y < rhs && lhs.z < rhs;}


	friend Z_CT(CPP11) XYZ operator +(const XYZ &lhs, t rhs) Z_NOTHROW
		{return XYZ(lhs.x + rhs, lhs.y + rhs, lhs.z + rhs);}


	friend Z_CT(CPP11) XYZ operator -(const XYZ &lhs, t rhs) Z_NOTHROW
		{return XYZ(lhs.x - rhs, lhs.y - rhs, lhs.z - rhs);}


	friend Z_CT(CPP11) XYZ operator *(const XYZ &lhs, t rhs) Z_NOTHROW
		{return XYZ(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs);}


	friend Z_CT(CPP11) XYZ operator /(const XYZ &lhs, t rhs) Z_NOTHROW
		{return XYZ(lhs.x / rhs, lhs.y / rhs, lhs.z / rhs);}


	friend Z_CT(CPP11) Boolean operator ==(t lhs, const XYZ &rhs) Z_NOTHROW
		{return lhs == rhs.x && lhs == rhs.y && lhs == rhs.z;}


	friend Z_CT(CPP11) Boolean operator !=(t lhs, const XYZ &rhs) Z_NOTHROW
		{return lhs != rhs.x || lhs != rhs.y || lhs != rhs.y;}


	friend Z_CT(CPP11) Boolean operator >=(t lhs, const XYZ &rhs) Z_NOTHROW
		{return lhs >= rhs.x && lhs >= rhs.y && lhs >= rhs.z;}


	friend Z_CT(CPP11) Boolean operator <=(t lhs, const XYZ &rhs) Z_NOTHROW
		{return lhs <= rhs.x && lhs <= rhs.y && lhs <= rhs.z;}


	friend Z_CT(CPP11) Boolean operator >(t lhs, const XYZ &rhs) Z_NOTHROW
		{return lhs > rhs.x && lhs > rhs.y && lhs > rhs.z;}


	friend Z_CT(CPP11) Boolean operator <(t lhs, const XYZ &rhs) Z_NOTHROW
		{return lhs < rhs.x && lhs < rhs.y && lhs < rhs.z;}


	friend Z_CT(CPP11) XYZ operator +(t lhs, const XYZ &rhs) Z_NOTHROW
		{return XYZ(lhs + rhs.x, lhs + rhs.y, lhs + rhs.z);}


	friend Z_CT(CPP11) XYZ operator *(t lhs, const XYZ &rhs) Z_NOTHROW
		{return XYZ(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z);}


	friend Z_CT(CPP11) Boolean operator ==(const XYZ &lhs, const XY<t> &rhs) Z_NOTHROW
		{return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == t(0);}


	friend Z_CT(CPP11) Boolean operator !=(const XYZ &lhs, const XY<t> &rhs) Z_NOTHROW
		{return lhs.x != rhs.x || lhs.y != rhs.y || lhs.z != t(0);}


	friend Z_CT(CPP11) Boolean operator >=(const XYZ &lhs, const XY<t> &rhs) Z_NOTHROW
		{return lhs.x >= rhs.x && lhs.y >= rhs.y && lhs.z >= t(0);}


	friend Z_CT(CPP11) Boolean operator <=(const XYZ &lhs, const XY<t> &rhs) Z_NOTHROW
		{return lhs.x <= rhs.x && lhs.y <= rhs.y && lhs.z <= t(0);}


	friend Z_CT(CPP11) Boolean operator >(const XYZ &lhs, const XY<t> &rhs) Z_NOTHROW
		{return lhs.x > rhs.x && lhs.y > rhs.y && lhs.z > t(0);}


	friend Z_CT(CPP11) Boolean operator <(const XYZ &lhs, const XY<t> &rhs) Z_NOTHROW
		{return lhs.x < rhs.x && lhs.y < rhs.y && lhs.z < t(0);}


	friend Z_CT(CPP11) XYZ operator +(const XYZ &lhs, const XY<t> &rhs) Z_NOTHROW
		{return XYZ(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z);}


	friend Z_CT(CPP11) XYZ operator -(const XYZ &lhs, const XY<t> &rhs) Z_NOTHROW
		{return XYZ(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z);}


	friend Z_CT(CPP11) XYZ operator *(const XYZ &lhs, const XY<t> &rhs) Z_NOTHROW
		{return XYZ(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z, t(0));}


	friend Z_CT(CPP11) Boolean operator ==(const XY<t> &lhs, const XYZ &rhs) Z_NOTHROW
		{return lhs.x == rhs.x && lhs.y == rhs.y && rhs.z == t(0);}


	friend Z_CT(CPP11) Boolean operator !=(const XY<t> &lhs, const XYZ &rhs) Z_NOTHROW
		{return lhs.x != rhs.x || lhs.y != rhs.y || rhs.z != t(0);}


	friend Z_CT(CPP11) Boolean operator >=(const XY<t> &lhs, const XYZ &rhs) Z_NOTHROW
		{return lhs.x >= rhs.x && lhs.y >= rhs.y && t(0) >= rhs.z;}


	friend Z_CT(CPP11) Boolean operator <=(const XY<t> &lhs, const XYZ &rhs) Z_NOTHROW
		{return lhs.x <= rhs.x && lhs.y <= rhs.y && t(0) <= rhs.z;}


	friend Z_CT(CPP11) Boolean operator >(const XY<t> &lhs, const XYZ &rhs) Z_NOTHROW
		{return lhs.x > rhs.x && lhs.y > rhs.y && t(0) > rhs.z;}


	friend Z_CT(CPP11) Boolean operator <(const XY<t> &lhs, const XYZ &rhs) Z_NOTHROW
		{return lhs.x < rhs.x && lhs.y < rhs.y && t(0) < rhs.z;}


	friend Z_CT(CPP11) XYZ operator +(const XY<t> &lhs, const XYZ &rhs) Z_NOTHROW
		{return XYZ(lhs.x + rhs.x, lhs.y + rhs.y, rhs.z);}


	friend Z_CT(CPP11) XYZ operator *(const XY<t> &lhs, const XYZ &rhs) Z_NOTHROW
		{return XYZ(lhs.x + rhs.x, lhs.y + rhs.y, rhs.z, t(0));}


	Z_INLINE XYZ &operator +=(const XYZ &rhs) Z_NOTHROW {return *this = *this + rhs;}
	Z_INLINE XYZ &operator -=(const XYZ &rhs) Z_NOTHROW {return *this = *this - rhs;}
	Z_INLINE XYZ &operator *=(const XYZ &rhs) Z_NOTHROW {return *this = *this * rhs;}
	Z_INLINE XYZ &operator /=(const XYZ &rhs) Z_NOTHROW {return *this = *this / rhs;}

	Z_INLINE XYZ &operator +=(t rhs) Z_NOTHROW {return *this = *this + rhs;}
	Z_INLINE XYZ &operator -=(t rhs) Z_NOTHROW {return *this = *this - rhs;}
	Z_INLINE XYZ &operator *=(t rhs) Z_NOTHROW {return *this = *this * rhs;}
	Z_INLINE XYZ &operator /=(t rhs) Z_NOTHROW {return *this = *this / rhs;}

	Z_INLINE XY<t> &operator +=(XY<t> rhs) Z_NOTHROW {return *this = *this + rhs;}
	Z_INLINE XY<t> &operator -=(XY<t> rhs) Z_NOTHROW {return *this = *this - rhs;}
	Z_INLINE XY<t> &operator *=(XY<t> rhs) Z_NOTHROW {return *this = *this * rhs;}

	Z_INLINE t  operator [](UInt index) const Z_NOTHROW {return ((t *)this)[index];}
	Z_INLINE t &operator [](UInt index)	  Z_NOTHROW {return ((t *)this)[index];}

	Z_CT(CPP11) XY<t> xy () const Z_NOTHROW {return XY<t>(x, y);}
	Z_CT(CPP11) XY<t> xz () const Z_NOTHROW {return XY<t>(x, z);}
	Z_CT(CPP11) XY<t> yx () const Z_NOTHROW {return XY<t>(y, x);}
	Z_CT(CPP11) XY<t> yz () const Z_NOTHROW {return XY<t>(y, z);}
	Z_CT(CPP11) XY<t> zx () const Z_NOTHROW {return XY<t>(z, x);}
	Z_CT(CPP11) XY<t> zy () const Z_NOTHROW {return XY<t>(z, y);}
	Z_CT(CPP11) XYZ	  xzy() const Z_NOTHROW {return XYZ(x, z, y);}
	Z_CT(CPP11) XYZ	  yxz() const Z_NOTHROW {return XYZ(y, x, z);}
	Z_CT(CPP11) XYZ	  yzx() const Z_NOTHROW {return XYZ(y, z, x);}
	Z_CT(CPP11) XYZ	  zxy() const Z_NOTHROW {return XYZ(z, x, y);}
	Z_CT(CPP11) XYZ	  zyx() const Z_NOTHROW {return XYZ(z, y, x);}


	Z_INLINE XYZ apply(t (* function)(t)) const Z_NOTHROW
		{return XYZ(function(x), function(y), function(z));}


	Z_CT(CPP11) XYZ clamp(const XYZ &minimum, const XYZ &maximum) const Z_NOTHROW
		{
		return XYZ(
			Zeta::clamp<t>(x, minimum.x, maximum.x),
			Zeta::clamp<t>(y, minimum.y, maximum.y),
			Zeta::clamp<t>(z, minimum.z, maximum.z));
		}


	Z_CT(CPP11) XYZ clamp(t minimum, t maximum) const Z_NOTHROW
		{
		return XYZ(
			Zeta::clamp<t>(x, minimum, maximum),
			Zeta::clamp<t>(y, minimum, maximum),
			Zeta::clamp<t>(z, minimum, maximum));
		}


	Z_CT(CPP11) XYZ cross_product(const XYZ &other) const Z_NOTHROW
		{
		return XYZ(
			y * other.z - z * other.y,
			z * other.x - x * other.z,
			x * other.y - y * other.x);
		}


	Z_CT(CPP11) t dot_product(const XYZ &other) const Z_NOTHROW
		{return x * other.x + y * other.y + z * other.z;}


	Z_CT(CPP11) XYZ fit(const XYZ &other) const Z_NOTHROW
		{return XYZ(t(0));} /* TODO */


	Z_CT(CPP11) Boolean has_zero() const Z_NOTHROW
		{return x == t(0) || y == t(0) || z == t(0);}


	Z_CT(CPP11) t inner_maximum() const Z_NOTHROW
		{return Zeta::maximum<t>(Zeta::maximum<t>(x, y), z);}


	Z_CT(CPP11) t inner_middle() const Z_NOTHROW
		{return (x + y + z) / t(3);}


	Z_CT(CPP11) t inner_minimum() const Z_NOTHROW
		{return Zeta::minimum<t>(Zeta::minimum<t>(x, y), z);}


	Z_CT(CPP11) t inner_product() const Z_NOTHROW
		{return x * y * z;}


	Z_CT(CPP11) t inner_sum() const Z_NOTHROW
		{return x + y + z;}


	Z_CT(CPP11) Boolean is_zero() const Z_NOTHROW
		{return x == t(0) && y == t(0) && z == t(0);}


	Z_CT(CPP11) XYZ maximum(const XYZ &other) const Z_NOTHROW
		{
		return XYZ(
			Zeta::maximum<t>(x, other.x),
			Zeta::maximum<t>(y, other.y),
			Zeta::maximum<t>(z, other.z));
		}


	Z_CT(CPP11) XYZ middle(const XYZ &other) const Z_NOTHROW
		{
		return XYZ(
			(x + other.x) / t(2),
			(y + other.y) / t(2),
			(z + other.z) / t(2));
		}


	Z_CT(CPP11) XYZ minimum(const XYZ &other) const Z_NOTHROW
		{
		return XYZ(
			Zeta::minimum<t>(x, other.x),
			Zeta::minimum<t>(y, other.y),
			Zeta::minimum<t>(z, other.z));
		}


	/*Z_INLINE XYZ rotate_as_axes(XYZ<SInt8> rotation) const Z_NOTHROW
		{
		XYZ result = *this;

		if ((rotation.x % 4) & 1) Zeta::swap<t>(&result.y, &result.z);
		if ((rotation.y % 4) & 1) Zeta::swap<t>(&result.x, &result.z);
		if ((rotation.z % 4) & 1) Zeta::swap<t>(&result.x, &result.y);
		return result;
		}*/


	Z_CT(CPP11) t squared_length() const Z_NOTHROW
		{return x * x + y * y + z * z;}


	// MARK: - Signed


	Z_CT(CPP11) XYZ absolute() const Z_NOTHROW
		{
		return XYZ(
			Zeta::absolute<t>(x),
			Zeta::absolute<t>(y),
			Zeta::absolute<t>(z));
		}


	Z_CT(CPP11) Boolean has_negative() const Z_NOTHROW
		{return x < t(0) || y < t(0) || z < t(0);}


	Z_CT(CPP11) Boolean is_negative() const Z_NOTHROW
		{return x < t(0) && y < t(0) && z < t(0);}


	Z_CT(CPP11) XYZ negative() const Z_NOTHROW
		{return XYZ(-x, -y, -z);}


	// MARK: - Integer


	//Z_CT(CPP11) Boolean is_perpendicular(const XYZ &other) const
	//	{return !Zeta::absolute<t>(dot_product(other));}


	// MARK: - Real


	Z_CT(CPP11) XYZ clamp_01() const Z_NOTHROW
		{
		return XYZ(
			Zeta::clamp_01<t>(x),
			Zeta::clamp_01<t>(y),
			Zeta::clamp_01<t>(z));
		}


	Z_CT(CPP11) Boolean has_almost_zero() const Z_NOTHROW
		{
		return	Zeta::is_almost_zero<t>(x) ||
			Zeta::is_almost_zero<t>(y) ||
			Zeta::is_almost_zero<t>(z);
		}


	Z_CT(CPP11) Boolean has_finite() const Z_NOTHROW
		{
		return	Zeta::is_finite<t>(x) ||
			Zeta::is_finite<t>(y) ||
			Zeta::is_finite<t>(z);
		}


	Z_CT(CPP11) Boolean has_infinity() const Z_NOTHROW
		{
		return	Zeta::is_infinity<t>(x) ||
			Zeta::is_infinity<t>(y) ||
			Zeta::is_infinity<t>(z);
		}


	Z_CT(CPP11) Boolean has_nan() const Z_NOTHROW
		{
		return	Zeta::is_nan<t>(x) ||
			Zeta::is_nan<t>(y) ||
			Zeta::is_nan<t>(z);
		}


	Z_CT(CPP11) XYZ inverse_lerp(const XYZ &other, t v) const Z_NOTHROW
		{
		return XYZ(
			Zeta::inverse_lerp<t>(x, other.x, v),
			Zeta::inverse_lerp<t>(y, other.y, v),
			Zeta::inverse_lerp<t>(z, other.z, v));
		}


	Z_CT(CPP11) Boolean is_almost_equal(const XYZ &other) const Z_NOTHROW
		{
		return	Zeta::are_almost_equal<t>(x, other.x) &&
			Zeta::are_almost_equal<t>(y, other.y) &&
			Zeta::are_almost_equal<t>(z, other.z);
		}


	Z_CT(CPP11) Boolean is_almost_zero() const Z_NOTHROW
		{
		return	Zeta::is_almost_zero<t>(x) &&
			Zeta::is_almost_zero<t>(y) &&
			Zeta::is_almost_zero<t>(z);
		}


	Z_CT(CPP11) Boolean is_finite() const Z_NOTHROW
		{
		return	Zeta::is_finite<t>(x) &&
			Zeta::is_finite<t>(y) &&
			Zeta::is_finite<t>(z);
		}


	Z_CT(CPP11) Boolean is_infinity() const Z_NOTHROW
		{
		return	Zeta::is_infinity<t>(x) &&
			Zeta::is_infinity<t>(y) &&
			Zeta::is_infinity<t>(z);
		}


	Z_CT(CPP11) Boolean is_nan() const Z_NOTHROW
		{
		return	Zeta::is_nan<t>(x) &&
			Zeta::is_nan<t>(y) &&
			Zeta::is_nan<t>(z);
		}


	Z_CT(CPP11) Boolean is_perpendicular(const XYZ &other) const Z_NOTHROW
		{return Zeta::absolute<t>(dot_product(other)) <= Type<t>::epsilon();}


	Z_CT(CPP11) XYZ lerp(const XYZ &other, t v) const Z_NOTHROW
		{
		return XYZ(
			Zeta::lerp<t>(x, other.x, v),
			Zeta::lerp<t>(y, other.y, v),
			Zeta::lerp<t>(z, other.z, v));
		}


	Z_CT(CPP11) XYZ reciprocal() const Z_NOTHROW
		{return XYZ(t(1) / x, t(1) / y, t(1) / z);}
	};
}


#endif // Z_classes_XYZ_HPP
