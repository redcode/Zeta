/* Z Kit - classes/base/Value3D.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_classes_base_Value3D_HPP_
#define _Z_classes_base_Value3D_HPP_

#ifndef _Z_classes_base_Value2D_HPP_
#	include <Z/classes/base/Value2D.hpp>
#endif


#define Z_IMPLEMENTATION_COMMON									\
												\
typedef typename ZTypeFixedNumber(Z3D, T) Base;							\
T x, y, z;											\
												\
Z_INLINE Value3D() Z_DEFAULTED({})								\
												\
Z_CT(CPP11) Value3D(T x, T y, T z)	       : x(x),	     y(y),	 z(z)	    {}		\
Z_CT(CPP11) Value3D(T x, T y)		       : x(x),	     y(y),	 z(T(0))    {}		\
Z_CT(CPP11) Value3D(T xyz)		       : x(xyz),     y(xyz),	 z(xyz)	    {}		\
Z_CT(CPP11) Value3D(const Value2D<T> &xy)      : x(xy.x),    y(xy.y),	 z(T(0))    {}		\
Z_CT(CPP11) Value3D(const Value2D<T> &xy, T z) : x(xy.x),    y(xy.y),	 z(z)	    {}		\
Z_CT(CPP11) Value3D(T x, const Value2D<T> &yz) : x(x),	     y(yz.x),	 z(yz.y)    {}		\
Z_CT(CPP11) Value3D(const Base &other)	       : x(other.x), y(other.y), z(other.z) {}		\
												\
Z_CT(CPP11) operator Boolean() const {return x != T(0) || y != T(0) || z != T(0);}		\
Z_INLINE    operator Base&  () const {return *((Base *)this);}					\
													    \
Z_CT(CPP11) Boolean operator ==(const Value3D &rhs) const {return x == rhs.x && y == rhs.y && z == rhs.z;}  \
Z_CT(CPP11) Boolean operator !=(const Value3D &rhs) const {return x != rhs.x || y != rhs.y || z != rhs.z;}  \
Z_CT(CPP11) Boolean operator <=(const Value3D &rhs) const {return x <= rhs.x && y <= rhs.y && z <= rhs.z;}  \
Z_CT(CPP11) Boolean operator >=(const Value3D &rhs) const {return x >= rhs.x && y >= rhs.y && z >= rhs.z;}  \
Z_CT(CPP11) Boolean operator > (const Value3D &rhs) const {return x >  rhs.x && y >  rhs.y && z >  rhs.z;}  \
Z_CT(CPP11) Boolean operator < (const Value3D &rhs) const {return x <  rhs.x && y <  rhs.y && z <  rhs.z;}  \
													    \
Z_CT(CPP11) Value3D operator +(const Value3D &rhs) const {return Value3D(x + rhs.x, y + rhs.y, z + rhs.z);} \
Z_CT(CPP11) Value3D operator -(const Value3D &rhs) const {return Value3D(x - rhs.x, y - rhs.y, z - rhs.z);} \
Z_CT(CPP11) Value3D operator *(const Value3D &rhs) const {return Value3D(x * rhs.x, y * rhs.y, z * rhs.z);} \
Z_CT(CPP11) Value3D operator /(const Value3D &rhs) const {return Value3D(x / rhs.x, y / rhs.y, z / rhs.z);} \
													    \
Z_INLINE Value3D &operator +=(const Value3D &rhs) {return *this = *this + rhs;}			\
Z_INLINE Value3D &operator -=(const Value3D &rhs) {return *this = *this - rhs;}			\
Z_INLINE Value3D &operator *=(const Value3D &rhs) {return *this = *this * rhs;}			\
Z_INLINE Value3D &operator /=(const Value3D &rhs) {return *this = *this / rhs;}			\
												\
Z_CT(CPP11) Boolean operator ==(T rhs) const {return x == rhs && y == rhs && z == rhs;}		\
Z_CT(CPP11) Boolean operator !=(T rhs) const {return x != rhs || y != rhs || z != rhs;}		\
Z_CT(CPP11) Boolean operator <=(T rhs) const {return x <= rhs && y <= rhs && z <= rhs;}		\
Z_CT(CPP11) Boolean operator >=(T rhs) const {return x >= rhs && y >= rhs && z >= rhs;}		\
Z_CT(CPP11) Boolean operator > (T rhs) const {return x >  rhs && y >  rhs && z >  rhs;}		\
Z_CT(CPP11) Boolean operator < (T rhs) const {return x <  rhs && y <  rhs && z <  rhs;}		\
												\
Z_CT(CPP11) Value3D operator +(T rhs) const {return Value3D(x + rhs, y + rhs, z + rhs);}	\
Z_CT(CPP11) Value3D operator -(T rhs) const {return Value3D(x - rhs, y - rhs, z - rhs);}	\
Z_CT(CPP11) Value3D operator *(T rhs) const {return Value3D(x * rhs, y * rhs, z * rhs);}	\
Z_CT(CPP11) Value3D operator /(T rhs) const {return Value3D(x / rhs, y / rhs, z / rhs);}	\
												\
Z_INLINE Value3D &operator +=(T rhs) {return *this = *this + rhs;}				\
Z_INLINE Value3D &operator -=(T rhs) {return *this = *this - rhs;}				\
Z_INLINE Value3D &operator *=(T rhs) {return *this = *this * rhs;}				\
Z_INLINE Value3D &operator /=(T rhs) {return *this = *this / rhs;}				\
												\
Z_INLINE T  operator [](UInt index) const {return ((T *)this)[index];}				\
Z_INLINE T &operator [](UInt index)	  {return ((T *)this)[index];}				\
												\
Z_CT(CPP11) Value2D<T> xy () const {return Value2D<T>(x, y);}					\
Z_CT(CPP11) Value2D<T> xz () const {return Value2D<T>(x, z);}					\
Z_CT(CPP11) Value2D<T> yx () const {return Value2D<T>(y, x);}					\
Z_CT(CPP11) Value2D<T> yz () const {return Value2D<T>(y, z);}					\
Z_CT(CPP11) Value2D<T> zx () const {return Value2D<T>(z, x);}					\
Z_CT(CPP11) Value2D<T> zy () const {return Value2D<T>(z, y);}					\
Z_CT(CPP11) Value3D    xzy() const {return Value3D(x, z, y);}					\
Z_CT(CPP11) Value3D    yxz() const {return Value3D(y, x, z);}					\
Z_CT(CPP11) Value3D    yzx() const {return Value3D(y, z, x);}					\
Z_CT(CPP11) Value3D    zxy() const {return Value3D(z, x, y);}					\
Z_CT(CPP11) Value3D    zyx() const {return Value3D(z, y, x);}					\
												\
												\
Z_CT(CPP11) Value3D clamp(const Value3D &minimum, const Value3D &maximum) const			\
	{											\
	return Value3D										\
		(Zeta::clamp<T>(x, minimum.x, maximum.x),					\
		 Zeta::clamp<T>(y, minimum.y, maximum.y),					\
		 Zeta::clamp<T>(z, minimum.z, maximum.z));					\
	}											\
												\
												\
Z_CT(CPP11) Value3D clamp(T minimum, T maximum) const						\
	{											\
	return Value3D										\
		(Zeta::clamp<T>(x, minimum, maximum),						\
		 Zeta::clamp<T>(y, minimum, maximum),						\
		 Zeta::clamp<T>(z, minimum, maximum));						\
	}											\
												\
												\
Z_CT(CPP11) Value3D cross_product(const Value3D &other) const					\
	{											\
	return Value3D										\
		(y * other.z - z * other.y,							\
		 z * other.x - x * other.z,							\
		 x * other.y - y * other.x);							\
	}											\
												\
												\
Z_CT(CPP11) T dot_product(const Value3D &other) const						\
	{return x * other.x + y * other.y + z * other.z;}					\
												\
												\
Z_CT(CPP11) Value3D fit(const Value3D &other) const						\
	{return Value3D(T(0));} /* TODO */							\
												\
												\
Z_CT(CPP11) Boolean has_zero() const								\
	{return x == T(0) || y == T(0) || z == T(0);}						\
												\
												\
Z_CT(CPP11) T inner_maximum() const								\
	{return Zeta::maximum<T>(Zeta::maximum<T>(x, y), z);}					\
												\
												\
Z_CT(CPP11) T inner_middle() const								\
	{return (x + y + z) / T(3);}								\
												\
												\
Z_CT(CPP11) T inner_minimum() const								\
	{return Zeta::minimum<T>(Zeta::minimum<T>(x, y), z);}					\
												\
												\
Z_CT(CPP11) T inner_product() const								\
	{return x * y * z;}									\
												\
												\
Z_CT(CPP11) T inner_sum() const									\
	{return x + y + z;}									\
												\
												\
Z_CT(CPP11) Boolean is_zero() const								\
	{return x == T(0) && y == T(0) && z == T(0);}						\
												\
												\
Z_CT(CPP11) Value3D maximum(const Value3D &other) const						\
	{											\
	return Value3D										\
		(Zeta::maximum<T>(x, other.x),							\
		 Zeta::maximum<T>(y, other.y),							\
		 Zeta::maximum<T>(z, other.z));							\
	}											\
												\
												\
Z_CT(CPP11) Value3D minimum(const Value3D &other) const						\
	{											\
	return Value3D										\
		(Zeta::minimum<T>(x, other.x),							\
		 Zeta::minimum<T>(y, other.y),							\
		 Zeta::minimum<T>(z, other.z));							\
	}											\
												\
												\
Z_CT(CPP11) Value3D middle(const Value3D &other) const						\
	{											\
	return Value3D										\
		((x + other.x) / T(2),								\
		 (y + other.y) / T(2),								\
		 (z + other.z) / T(2));								\
	}											\
												\
												\
Z_INLINE Value3D rotate_as_axes(Value3D<SInt8> rotation) const					\
	{											\
	Value3D result = *this;									\
												\
	if ((rotation.x % 4) & 1) Zeta::swap<T>(&result.y, &result.z);				\
	if ((rotation.y % 4) & 1) Zeta::swap<T>(&result.x, &result.z);				\
	if ((rotation.z % 4) & 1) Zeta::swap<T>(&result.x, &result.y);				\
	return result;										\
	}											\
												\
												\
Z_CT(CPP11) T squared_length() const								\
	{return x * x + y * y + z * z;}								\
												\
												\
Z_INLINE void swap(Value3D &other)								\
	{Zeta::swap<Base>(this, &other);}


#define Z_IMPLEMENTATION_SIGNED									\
												\
Z_CT(CPP11) Value3D absolute() const								\
	{											\
	return Value3D										\
		(Zeta::absolute<T>(x),								\
		 Zeta::absolute<T>(y),								\
		 Zeta::absolute<T>(z));								\
	}											\
												\
												\
Z_CT(CPP11) Boolean has_negative() const							\
	{return x < T(0) || y < T(0) || z < T(0);}						\
												\
												\
Z_CT(CPP11) Boolean is_negative() const								\
	{return x < T(0) && y < T(0) && z < T(0);}						\
												\
												\
Z_CT(CPP11) Value3D negative() const								\
	{return Value3D(-x, -y, -z);}


namespace Zeta {

	// template <class T, UInt T_number_set = Type<T>::number_set> struct Value3D;


	template <class T> struct Value3D<T, Z_NUMBER_SET_Z> {
		Z_IMPLEMENTATION_COMMON
		Z_IMPLEMENTATION_SIGNED


		Z_CT(CPP11) Boolean is_perpendicular(const Value3D &other) const
			{return !Zeta::absolute<T>(dot_product(other));}


#		ifdef Z_EXTENSION_VALUE_3D_Z
			Z_EXTENSION_VALUE_3D_Z
#		endif
	};


	template <class T> struct Value3D<T, Z_NUMBER_SET_N> {
		Z_IMPLEMENTATION_COMMON


#		ifdef Z_EXTENSION_VALUE_3D_N
			Z_EXTENSION_VALUE_3D_N
#		endif
	};


	template <class T> struct Value3D<T, Z_NUMBER_SET_R> {
		Z_IMPLEMENTATION_COMMON
		Z_IMPLEMENTATION_SIGNED


		Z_CT(CPP11) Value3D clamp_01() const
			{
			return Value3D
				(Zeta::clamp_01<T>(x),
				 Zeta::clamp_01<T>(y),
				 Zeta::clamp_01<T>(z));
			}


		Z_CT(CPP11) Boolean has_almost_zero() const
			{
			return	Zeta::is_almost_zero<T>(x) ||
				Zeta::is_almost_zero<T>(y) ||
				Zeta::is_almost_zero<T>(z);
			}


		Z_CT(CPP11) Boolean has_finite() const
			{
			return	Zeta::is_finite<T>(x) ||
				Zeta::is_finite<T>(y) ||
				Zeta::is_finite<T>(z);
			}


		Z_CT(CPP11) Boolean has_infinity() const
			{
			return	Zeta::is_infinity<T>(x) ||
				Zeta::is_infinity<T>(y) ||
				Zeta::is_infinity<T>(z);
			}


		Z_CT(CPP11) Boolean has_nan() const
			{
			return	Zeta::is_nan<T>(x) ||
				Zeta::is_nan<T>(y) ||
				Zeta::is_nan<T>(z);
			}


		Z_CT(CPP11) Value3D inverse_lerp(const Value3D &other, T t) const
			{
			return Value3D
				(Zeta::inverse_lerp<T>(x, other.x, t),
				 Zeta::inverse_lerp<T>(y, other.y, t),
				 Zeta::inverse_lerp<T>(z, other.z, t));
			}


		Z_CT(CPP11) Boolean is_almost_equal(const Value3D &other) const
			{
			return	Zeta::are_almost_equal<T>(x, other.x) &&
				Zeta::are_almost_equal<T>(y, other.y) &&
				Zeta::are_almost_equal<T>(z, other.z);
			}


		Z_CT(CPP11) Boolean is_almost_zero() const
			{
			return	Zeta::is_almost_zero<T>(x) &&
				Zeta::is_almost_zero<T>(y) &&
				Zeta::is_almost_zero<T>(z);
			}


		Z_CT(CPP11) Boolean is_finite() const
			{
			return	Zeta::is_finite<T>(x) &&
				Zeta::is_finite<T>(y) &&
				Zeta::is_finite<T>(z);
			}


		Z_CT(CPP11) Boolean is_infinity() const
			{
			return	Zeta::is_infinity<T>(x) &&
				Zeta::is_infinity<T>(y) &&
				Zeta::is_infinity<T>(z);
			}


		Z_CT(CPP11) Boolean is_nan() const
			{
			return	Zeta::is_nan<T>(x) &&
				Zeta::is_nan<T>(y) &&
				Zeta::is_nan<T>(z);
			}


		Z_CT(CPP11) Boolean is_perpendicular(const Value3D &other) const
			{return Zeta::absolute<T>(dot_product(other)) <= Type<T>::epsilon();}


		Z_CT(CPP11) Value3D lerp(const Value3D &other, T t) const
			{
			return Value3D
				(Zeta::lerp<T>(x, other.x, t),
				 Zeta::lerp<T>(y, other.y, t),
				 Zeta::lerp<T>(z, other.z, t));
			}


		Z_CT(CPP11) Value3D reciprocal() const
			{return Value3D(T(1) / x, T(1) / y, T(1) / z);}


#		ifdef Z_EXTENSION_VALUE_3D_R
			Z_EXTENSION_VALUE_3D_R
#		endif
	};
}


#undef Z_IMPLEMENTATION_COMMON
#undef Z_IMPLEMENTATION_SIGNED

#endif // _Z_classes_base_Value3D_HPP_
