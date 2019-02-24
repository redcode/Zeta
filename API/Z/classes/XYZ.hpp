/* Z Kit - classes/XYZ.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2019 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_classes_XYZ_HPP
#define Z_classes_XYZ_HPP

#ifndef Z_classes_XY_HPP
#	include <Z/classes/XY.hpp>
#endif


#define Z_IMPLEMENTATION_COMMON									\
												\
typedef typename ZTypeFixedNumber(Z3D, T) Base;							\
T x, y, z;											\
												\
Z_INLINE XYZ() Z_DEFAULTED({})									\
												\
Z_CT(CPP11) XYZ(T x, T y, T z)	      : x(x),	    y(y),	z(z)	   {}			\
Z_CT(CPP11) XYZ(T x, T y)	      : x(x),	    y(y),	z(T(0))	   {}			\
Z_CT(CPP11) XYZ(T xyz)		      : x(xyz),	    y(xyz),	z(xyz)	   {}			\
Z_CT(CPP11) XYZ(const XY<T> &xy)      : x(xy.x),    y(xy.y),	z(T(0))	   {}			\
Z_CT(CPP11) XYZ(const XY<T> &xy, T z) : x(xy.x),    y(xy.y),	z(z)	   {}			\
Z_CT(CPP11) XYZ(T x, const XY<T> &yz) : x(x),	    y(yz.x),	z(yz.y)	   {}			\
Z_CT(CPP11) XYZ(const Base &other)    : x(other.x), y(other.y), z(other.z) {}			\
												\
Z_CT(CPP11) operator Boolean() const {return x != T(0) || y != T(0) || z != T(0);}		\
Z_INLINE    operator Base&  () const {return *((Base *)this);}					\
												\
Z_CT(CPP11) Boolean operator ==(const XYZ &rhs) const {return x == rhs.x && y == rhs.y && z == rhs.z;}  \
Z_CT(CPP11) Boolean operator !=(const XYZ &rhs) const {return x != rhs.x || y != rhs.y || z != rhs.z;}  \
Z_CT(CPP11) Boolean operator <=(const XYZ &rhs) const {return x <= rhs.x && y <= rhs.y && z <= rhs.z;}  \
Z_CT(CPP11) Boolean operator >=(const XYZ &rhs) const {return x >= rhs.x && y >= rhs.y && z >= rhs.z;}  \
Z_CT(CPP11) Boolean operator > (const XYZ &rhs) const {return x >  rhs.x && y >	 rhs.y && z >  rhs.z;}  \
Z_CT(CPP11) Boolean operator < (const XYZ &rhs) const {return x <  rhs.x && y <	 rhs.y && z <  rhs.z;}  \
												\
Z_CT(CPP11) XYZ operator +(const XYZ &rhs) const {return XYZ(x + rhs.x, y + rhs.y, z + rhs.z);} \
Z_CT(CPP11) XYZ operator -(const XYZ &rhs) const {return XYZ(x - rhs.x, y - rhs.y, z - rhs.z);} \
Z_CT(CPP11) XYZ operator *(const XYZ &rhs) const {return XYZ(x * rhs.x, y * rhs.y, z * rhs.z);} \
Z_CT(CPP11) XYZ operator /(const XYZ &rhs) const {return XYZ(x / rhs.x, y / rhs.y, z / rhs.z);} \
											\
Z_INLINE XYZ &operator +=(const XYZ &rhs) {return *this = *this + rhs;}			\
Z_INLINE XYZ &operator -=(const XYZ &rhs) {return *this = *this - rhs;}			\
Z_INLINE XYZ &operator *=(const XYZ &rhs) {return *this = *this * rhs;}			\
Z_INLINE XYZ &operator /=(const XYZ &rhs) {return *this = *this / rhs;}			\
											\
Z_CT(CPP11) Boolean operator ==(T rhs) const {return x == rhs && y == rhs && z == rhs;}	\
Z_CT(CPP11) Boolean operator !=(T rhs) const {return x != rhs || y != rhs || z != rhs;}	\
Z_CT(CPP11) Boolean operator <=(T rhs) const {return x <= rhs && y <= rhs && z <= rhs;}	\
Z_CT(CPP11) Boolean operator >=(T rhs) const {return x >= rhs && y >= rhs && z >= rhs;}	\
Z_CT(CPP11) Boolean operator > (T rhs) const {return x >  rhs && y >  rhs && z >  rhs;}	\
Z_CT(CPP11) Boolean operator < (T rhs) const {return x <  rhs && y <  rhs && z <  rhs;}	\
											\
Z_CT(CPP11) XYZ operator +(T rhs) const {return XYZ(x + rhs, y + rhs, z + rhs);}	\
Z_CT(CPP11) XYZ operator -(T rhs) const {return XYZ(x - rhs, y - rhs, z - rhs);}	\
Z_CT(CPP11) XYZ operator *(T rhs) const {return XYZ(x * rhs, y * rhs, z * rhs);}	\
Z_CT(CPP11) XYZ operator /(T rhs) const {return XYZ(x / rhs, y / rhs, z / rhs);}	\
											\
Z_INLINE XYZ &operator +=(T rhs) {return *this = *this + rhs;}				\
Z_INLINE XYZ &operator -=(T rhs) {return *this = *this - rhs;}				\
Z_INLINE XYZ &operator *=(T rhs) {return *this = *this * rhs;}				\
Z_INLINE XYZ &operator /=(T rhs) {return *this = *this / rhs;}				\
											\
Z_INLINE T  operator [](UInt index) const {return ((T *)this)[index];}			\
Z_INLINE T &operator [](UInt index)	  {return ((T *)this)[index];}			\
											\
Z_CT(CPP11) XY<T> xy () const {return XY<T>(x, y);}					\
Z_CT(CPP11) XY<T> xz () const {return XY<T>(x, z);}					\
Z_CT(CPP11) XY<T> yx () const {return XY<T>(y, x);}					\
Z_CT(CPP11) XY<T> yz () const {return XY<T>(y, z);}					\
Z_CT(CPP11) XY<T> zx () const {return XY<T>(z, x);}					\
Z_CT(CPP11) XY<T> zy () const {return XY<T>(z, y);}					\
Z_CT(CPP11) XYZ	  xzy() const {return XYZ(x, z, y);}					\
Z_CT(CPP11) XYZ	  yxz() const {return XYZ(y, x, z);}					\
Z_CT(CPP11) XYZ	  yzx() const {return XYZ(y, z, x);}					\
Z_CT(CPP11) XYZ	  zxy() const {return XYZ(z, x, y);}					\
Z_CT(CPP11) XYZ	  zyx() const {return XYZ(z, y, x);}					\
											\
											\
Z_CT(CPP11) XYZ clamp(const XYZ &minimum, const XYZ &maximum) const			\
	{										\
	return XYZ									\
		(Zeta::clamp<T>(x, minimum.x, maximum.x),				\
		 Zeta::clamp<T>(y, minimum.y, maximum.y),				\
		 Zeta::clamp<T>(z, minimum.z, maximum.z));				\
	}										\
											\
											\
Z_CT(CPP11) XYZ clamp(T minimum, T maximum) const					\
	{										\
	return XYZ									\
		(Zeta::clamp<T>(x, minimum, maximum),					\
		 Zeta::clamp<T>(y, minimum, maximum),					\
		 Zeta::clamp<T>(z, minimum, maximum));					\
	}										\
											\
											\
Z_CT(CPP11) XYZ cross_product(const XYZ &other) const					\
	{										\
	return XYZ									\
		(y * other.z - z * other.y,						\
		 z * other.x - x * other.z,						\
		 x * other.y - y * other.x);						\
	}										\
											\
											\
Z_CT(CPP11) T dot_product(const XYZ &other) const					\
	{return x * other.x + y * other.y + z * other.z;}				\
											\
											\
Z_CT(CPP11) XYZ fit(const XYZ &other) const						\
	{return XYZ(T(0));} /* TODO */							\
											\
											\
Z_CT(CPP11) Boolean has_zero() const							\
	{return x == T(0) || y == T(0) || z == T(0);}					\
											\
											\
Z_CT(CPP11) T inner_maximum() const							\
	{return Zeta::maximum<T>(Zeta::maximum<T>(x, y), z);}				\
											\
											\
Z_CT(CPP11) T inner_middle() const							\
	{return (x + y + z) / T(3);}							\
											\
											\
Z_CT(CPP11) T inner_minimum() const							\
	{return Zeta::minimum<T>(Zeta::minimum<T>(x, y), z);}				\
											\
											\
Z_CT(CPP11) T inner_product() const							\
	{return x * y * z;}								\
											\
											\
Z_CT(CPP11) T inner_sum() const								\
	{return x + y + z;}								\
											\
											\
Z_CT(CPP11) Boolean is_zero() const							\
	{return x == T(0) && y == T(0) && z == T(0);}					\
											\
											\
Z_CT(CPP11) XYZ maximum(const XYZ &other) const						\
	{										\
	return XYZ									\
		(Zeta::maximum<T>(x, other.x),						\
		 Zeta::maximum<T>(y, other.y),						\
		 Zeta::maximum<T>(z, other.z));						\
	}										\
											\
											\
Z_CT(CPP11) XYZ minimum(const XYZ &other) const						\
	{										\
	return XYZ									\
		(Zeta::minimum<T>(x, other.x),						\
		 Zeta::minimum<T>(y, other.y),						\
		 Zeta::minimum<T>(z, other.z));						\
	}										\
											\
											\
Z_CT(CPP11) XYZ middle(const XYZ &other) const						\
	{										\
	return XYZ									\
		((x + other.x) / T(2),							\
		 (y + other.y) / T(2),							\
		 (z + other.z) / T(2));							\
	}										\
											\
											\
/*Z_INLINE XYZ rotate_as_axes(XYZ<SInt8> rotation) const					\
	{										\
	XYZ result = *this;								\
											\
	if ((rotation.x % 4) & 1) Zeta::swap<T>(&result.y, &result.z);			\
	if ((rotation.y % 4) & 1) Zeta::swap<T>(&result.x, &result.z);			\
	if ((rotation.z % 4) & 1) Zeta::swap<T>(&result.x, &result.y);			\
	return result;									\
	}*/										\
											\
											\
Z_CT(CPP11) T squared_length() const							\
	{return x * x + y * y + z * z;}							\
											\
											\
/*Z_INLINE void swap(XYZ &other)								\
	{Zeta::swap<Base>(this, &other);}*/


#define Z_IMPLEMENTATION_SIGNED								\
											\
Z_CT(CPP11) XYZ absolute() const							\
	{										\
	return XYZ									\
		(Zeta::absolute<T>(x),							\
		 Zeta::absolute<T>(y),							\
		 Zeta::absolute<T>(z));							\
	}										\
											\
											\
Z_CT(CPP11) Boolean has_negative() const						\
	{return x < T(0) || y < T(0) || z < T(0);}					\
											\
											\
Z_CT(CPP11) Boolean is_negative() const							\
	{return x < T(0) && y < T(0) && z < T(0);}					\
											\
											\
Z_CT(CPP11) XYZ negative() const							\
	{return XYZ(-x, -y, -z);}


namespace Zeta {

	// template <class T, UInt T_number_set = Type<T>::number_set> struct XYZ;


	template <class T> struct XYZ<T, Z_NUMBER_SET_Z> {
		Z_IMPLEMENTATION_COMMON
		Z_IMPLEMENTATION_SIGNED


		Z_CT(CPP11) Boolean is_perpendicular(const XYZ &other) const
			{return !Zeta::absolute<T>(dot_product(other));}


#		ifdef Z_EXTENSION_VALUE_3D_Z
			Z_EXTENSION_VALUE_3D_Z
#		endif
	};


	template <class T> struct XYZ<T, Z_NUMBER_SET_N> {
		Z_IMPLEMENTATION_COMMON


#		ifdef Z_EXTENSION_VALUE_3D_N
			Z_EXTENSION_VALUE_3D_N
#		endif
	};


	template <class T> struct XYZ<T, Z_NUMBER_SET_R> {
		Z_IMPLEMENTATION_COMMON
		Z_IMPLEMENTATION_SIGNED


		Z_CT(CPP11) XYZ clamp_01() const
			{
			return XYZ
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


		Z_CT(CPP11) XYZ inverse_lerp(const XYZ &other, T t) const
			{
			return XYZ
				(Zeta::inverse_lerp<T>(x, other.x, t),
				 Zeta::inverse_lerp<T>(y, other.y, t),
				 Zeta::inverse_lerp<T>(z, other.z, t));
			}


		Z_CT(CPP11) Boolean is_almost_equal(const XYZ &other) const
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


		Z_CT(CPP11) Boolean is_perpendicular(const XYZ &other) const
			{return Zeta::absolute<T>(dot_product(other)) <= Type<T>::epsilon();}


		Z_CT(CPP11) XYZ lerp(const XYZ &other, T t) const
			{
			return XYZ
				(Zeta::lerp<T>(x, other.x, t),
				 Zeta::lerp<T>(y, other.y, t),
				 Zeta::lerp<T>(z, other.z, t));
			}


		Z_CT(CPP11) XYZ reciprocal() const
			{return XYZ(T(1) / x, T(1) / y, T(1) / z);}


#		ifdef Z_EXTENSION_VALUE_3D_R
			Z_EXTENSION_VALUE_3D_R
#		endif
	};
}


#undef Z_IMPLEMENTATION_COMMON
#undef Z_IMPLEMENTATION_SIGNED

#endif // Z_classes_XYZ_HPP
