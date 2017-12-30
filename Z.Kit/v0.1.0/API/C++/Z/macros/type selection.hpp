/* Z Kit C++ API - macros/type selection.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_macros_type_selection_HPP__
#define __Z_macros_type_selection_HPP__

#include <Z/traits/Type.hpp>
#include <Z/traits/mathematics.hpp>
#include <Z/macros/type enumeration.h>

#define Z_TYPE_WITH_FIXED_NATURAL_SUFFIX(					\
	prefix, suffix, T							\
)										\
	Zeta::SelectType<							\
		Zeta::Type<T>::is_natural					\
			? Zeta::Logarithm2<sizeof(T)>::value			\
			: 31,							\
		Z_ENUMERATE_FIXED_NATURAL_TYPES(prefix##suffix, void)		\
	>::type

#define Z_TYPE_WITH_FIXED_INTEGER_SUFFIX(					\
	prefix, suffix, T							\
)										\
	Zeta::SelectType<							\
		Zeta::Type<T>::is_integer					\
			? Zeta::Logarithm2<sizeof(T)>::value			\
			: 31,							\
		Z_ENUMERATE_FIXED_INTEGER_TYPES(prefix##suffix, void)		\
	>::type

#define Z_TYPE_WITH_FIXED_EXACT_SUFFIX(						\
	prefix, natural_suffix, integer_suffix, T				\
)										\
	Zeta::SelectType<							\
		Zeta::Type<T>::is_exact						\
			? Zeta::Logarithm2<sizeof(T)>::value			\
			  + (Zeta::Type<T>::is_signed ? 5 : 0)			\
			: 31,							\
		Z_ENUMERATE_FIXED_NATURAL_TYPES(prefix##natural_suffix, void),	\
		Z_ENUMERATE_FIXED_INTEGER_TYPES(prefix##integer_suffix, void)	\
	>::type

#define Z_TYPE_WITH_FIXED_REAL_SUFFIX(						\
	prefix, suffix, T							\
)										\
	Zeta::SelectType<							\
		Zeta::Type<T>::is_real ? Type<T>::precision_bits / 8 - 2 : 31,	\
		Z_ENUMERATE_FIXED_REAL_TYPES(prefix##suffix, void)		\
	>::type

#define Z_TYPE_WITH_FIXED_SIGNED_SUFFIX(					\
	prefix, integer_suffix, real_suffix, T					\
)										\
	Zeta::SelectType<							\
		Zeta::Type<T>::is_signed					\
			? (Zeta::Type<T>::is_real				\
				? Type<T>::precision_bits / 8 - 2 + 5		\
				: Zeta::Logarithm2<sizeof(T)>::value)		\
			: 31,							\
		Z_ENUMERATE_FIXED_INTEGER_TYPES(prefix##integer_suffix, void),	\
		Z_ENUMERATE_FIXED_REAL_TYPES   (prefix##real_suffix,	void)	\
	>::type

#define Z_TYPE_WITH_FIXED_NUMBER_SUFFIX(					\
	prefix, natural_suffix, integer_suffix, real_suffix, T			\
)										\
	Zeta::SelectType<							\
		Zeta::Type<T>::is_number					\
			? (Zeta::Type<T>::is_real				\
				? Type<T>::precision_bits / 8 - 2 + 5 + 5	\
				: Zeta::Logarithm2<sizeof(T)>::value		\
				  + (Zeta::Type<T>::is_signed ? 5 : 0))		\
			: 31,							\
		Z_ENUMERATE_FIXED_NATURAL_TYPES(prefix##natural_suffix, void),	\
		Z_ENUMERATE_FIXED_INTEGER_TYPES(prefix##integer_suffix, void),	\
		Z_ENUMERATE_FIXED_REAL_TYPES   (prefix##real_suffix,	void)	\
	>::type


#define ZTypeFixedNatural(Name, T)						\
	Zeta::SelectType<							\
		Zeta::Type<T>::is_natural					\
			? Zeta::Logarithm2<sizeof(T)>::value			\
			: 31,							\
		Z_ENUMERATE_FIXED_NATURAL_TYPES(Name##UInt, void)		\
	>::type

#define ZTypeFixedInteger(Name, T)						\
	Zeta::SelectType<							\
		Zeta::Type<T>::is_integer					\
			? Zeta::Logarithm2<sizeof(T)>::value			\
			: 31,							\
		Z_ENUMERATE_FIXED_INTEGER_TYPES(Name##Int, void)		\
	>::type

#define ZTypeFixedExact(Name, T)						\
	Zeta::SelectType<							\
		Zeta::Type<T>::is_exact						\
			? Zeta::Logarithm2<sizeof(T)>::value			\
			  + (Zeta::Type<T>::is_signed ? 5 : 0)			\
			: 31,							\
		Z_ENUMERATE_FIXED_NATURAL_TYPES(Name##UInt, void),		\
		Z_ENUMERATE_FIXED_INTEGER_TYPES(Name##Int,  void)		\
	>::type

#define ZTypeFixedReal(Name, T)							\
	Zeta::SelectType<							\
		Zeta::Type<T>::is_real						\
			? Type<T>::precision_bits / 8 - 2			\
			: 31,							\
		Z_ENUMERATE_FIXED_REAL_TYPES(Name##Float, void)			\
	>::type

#define ZTypeFixedSigned(Name, T)						\
	Zeta::SelectType<							\
		Zeta::Type<T>::is_signed					\
			? (Zeta::Type<T>::is_real				\
				? Type<T>::precision_bits / 8 - 2 + 5		\
				: Zeta::Logarithm2<sizeof(T)>::value)		\
			: 31,							\
		Z_ENUMERATE_FIXED_INTEGER_TYPES(Name##Int,   void),		\
		Z_ENUMERATE_FIXED_REAL_TYPES   (Name##Float, void)		\
	>::type

#define ZTypeFixedNumber(Name, T)						\
	Zeta::SelectType<							\
		Zeta::Type<T>::is_number					\
			? (Zeta::Type<T>::is_real				\
				? Type<T>::precision_bits / 8 - 2 + 5 + 5	\
				: Zeta::Logarithm2<sizeof(T)>::value		\
				  + (Zeta::Type<T>::is_signed ? 5 : 0))		\
			: 31,							\
		Z_ENUMERATE_FIXED_NATURAL_TYPES(Name##UInt,  void),		\
		Z_ENUMERATE_FIXED_INTEGER_TYPES(Name##Int,   void),		\
		Z_ENUMERATE_FIXED_REAL_TYPES   (Name##Float, void)		\
	>::type

#endif // __Z_macros_type_selection_HPP__
