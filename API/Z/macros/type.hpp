/* Z Kit - macros/type.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ | Kit
 /____/\___/ /__//___/_| ゼータキット
Copyright (C) 2006-2019 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_macros_type_HPP
#define Z_macros_type_HPP

#include <Z/macros/type.h>
#include <Z/traits/Type.hpp>
#include <Z/traits/mathematics.hpp>

#define ZTypeFixedNatural(Name, T)					  \
	Zeta::SelectType<						  \
		Zeta::Type<T>::is_natural				  \
			? Zeta::Logarithm2<sizeof(T)>::value		  \
			: 31,						  \
		Z_ENUMERATE_FIXED_NATURAL_TYPES_BITS(Name##UInt, void)	  \
	>::type

#define ZTypeFixedInteger(Name, T)					  \
	Zeta::SelectType<						  \
		Zeta::Type<T>::is_integer				  \
			? Zeta::Logarithm2<sizeof(T)>::value		  \
			: 31,						  \
		Z_ENUMERATE_FIXED_INTEGER_TYPES_BITS(Name##SInt, void)	  \
	>::type

#define ZTypeFixedIntegral(Name, T)					  \
	Zeta::SelectType<						  \
		Zeta::Type<T>::is_integral				  \
			? Zeta::Logarithm2<sizeof(T)>::value		  \
			  + (Zeta::Type<T>::is_integer ? 5 : 0)		  \
			: 31,						  \
		Z_ENUMERATE_FIXED_NATURAL_TYPES_BITS(Name##UInt, void),	  \
		Z_ENUMERATE_FIXED_INTEGER_TYPES_BITS(Name##SInt, void)	  \
	>::type

#define ZTypeFixedReal(Name, T)						  \
	Zeta::SelectType<						  \
		Zeta::Type<T>::is_real					  \
			? Zeta::Type<T>::fixed_fundamental		  \
			  - Z_FUNDAMENTAL_FLOAT16			  \
			: 31,						  \
		Z_ENUMERATE_FIXED_REAL_TYPES(Name##Float, void)		  \
	>::type

#define ZTypeFixedSigned(Name, T)					  \
	Zeta::SelectType<						  \
		Zeta::Type<T>::is_signed				  \
			? (Zeta::Type<T>::is_integer			  \
				? Zeta::Logarithm2<sizeof(T)>::value	  \
				: Zeta::Type<T>::fixed_fundamental	  \
				  - Z_FUNDAMENTAL_FLOAT16 + 5)		  \
			: 31,						  \
		Z_ENUMERATE_FIXED_INTEGER_TYPES_BITS (Name##SInt,  void), \
		Z_ENUMERATE_FIXED_REAL_TYPES_Suffixes(Name##Float, void)  \
	>::type

#define ZTypeFixedNumber(Name, T)					  \
	Zeta::SelectType<						  \
		Zeta::Type<T>::is_number				  \
			? (Zeta::Type<T>::is_integral			  \
				? Zeta::Logarithm2<sizeof(T)>::value	  \
				  + (Zeta::Type<T>::is_integer ? 5 : 0)	  \
				: Zeta::Type<T>::fixed_fundamental	  \
				  - Z_FUNDAMENTAL_FLOAT16 + 5 + 5)	  \
			: 31,						  \
		Z_ENUMERATE_FIXED_NATURAL_TYPES_BITS (Name##UInt,  void), \
		Z_ENUMERATE_FIXED_INTEGER_TYPES_BITS (Name##SInt,  void), \
		Z_ENUMERATE_FIXED_REAL_TYPES_Suffixes(Name##Float, void)  \
	>::type

#endif // Z_macros_type_HPP
