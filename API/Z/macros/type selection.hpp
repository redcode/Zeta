/* Z Kit - macros/type selection.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_macros_type_selection_HPP_
#define _Z_macros_type_selection_HPP_

#include <Z/traits/Type.hpp>
#include <Z/traits/mathematics.hpp>
#include <Z/macros/type enumeration.h>

#define ZTypeFixedNatural(Name, T)						\
	Zeta::SelectType<							\
		Zeta::Type<T>::is_natural					\
			? Zeta::Logarithm2<sizeof(T)>::value			\
			: 31,							\
		Z_ENUMERATE_FIXED_NATURAL_TYPES_BITS(Name##UInt, void)		\
	>::type

#define ZTypeFixedInteger(Name, T)						\
	Zeta::SelectType<							\
		Zeta::Type<T>::is_integer					\
			? Zeta::Logarithm2<sizeof(T)>::value			\
			: 31,							\
		Z_ENUMERATE_FIXED_INTEGER_TYPES_BITS(Name##SInt, void)		\
	>::type

#define ZTypeFixedExact(Name, T)						\
	Zeta::SelectType<							\
		Zeta::Type<T>::is_exact						\
			? Zeta::Logarithm2<sizeof(T)>::value			\
			  + (Zeta::Type<T>::is_signed ? 5 : 0)			\
			: 31,							\
		Z_ENUMERATE_FIXED_NATURAL_TYPES_BITS(Name##UInt, void),		\
		Z_ENUMERATE_FIXED_INTEGER_TYPES_BITS(Name##SInt, void)		\
	>::type

#define ZTypeFixedReal(Name, T)							\
	Zeta::SelectType<							\
		Zeta::Type<T>::is_real						\
			? Type<T>::fixed_value_type				\
			  - Z_KEY_INDEX_VALUE_TYPE_FIXED_REAL			\
			: 31,							\
		Z_ENUMERATE_FIXED_REAL_TYPES(Name##Float, void)			\
	>::type

#define ZTypeFixedSigned(Name, T)						\
	Zeta::SelectType<							\
		Zeta::Type<T>::is_signed					\
			? (Zeta::Type<T>::is_integer				\
				? Zeta::Logarithm2<sizeof(T)>::value		\
				: Type<T>::fixed_value_type			\
				  - Z_KEY_INDEX_VALUE_TYPE_FIXED_REAL + 5)	\
			: 31,							\
		Z_ENUMERATE_FIXED_INTEGER_TYPES_BITS (Name##SInt,  void),	\
		Z_ENUMERATE_FIXED_REAL_TYPES_Suffixes(Name##Float, void)	\
	>::type

#define ZTypeFixedNumber(Name, T)						\
	Zeta::SelectType<							\
		Zeta::Type<T>::is_number					\
			? (Zeta::Type<T>::is_exact				\
				? Zeta::Logarithm2<sizeof(T)>::value		\
				  + (Zeta::Type<T>::is_signed ? 5 : 0)		\
				: Type<T>::fixed_value_type			\
				  - Z_KEY_INDEX_VALUE_TYPE_FIXED_REAL + 5 + 5)	\
			: 31,							\
		Z_ENUMERATE_FIXED_NATURAL_TYPES_BITS (Name##UInt,  void),	\
		Z_ENUMERATE_FIXED_INTEGER_TYPES_BITS (Name##SInt,  void),	\
		Z_ENUMERATE_FIXED_REAL_TYPES_Suffixes(Name##Float, void)	\
	>::type

#endif // _Z_macros_type_selection_HPP_
