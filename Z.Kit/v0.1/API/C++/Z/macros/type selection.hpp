 /* Z Kit C++ API - macros/type selection.hpp
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_macros_type_selection_HPP__
#define __Z_macros_type_selection_HPP__

#include <Z/traits/Type.hpp>
#include <Z/traits/mathematics.hpp>
#include <Z/macros/type enumeration.h>

#define ZNaturalType(Name, T) Zeta::SelectType<					       \
	Zeta::Type<T>::is_natural ? Zeta::Logarithm2<Zeta::Type<T>::size>::value : 31, \
	Z_ENUMERATE_FIXED_NATURAL_TYPES(Name##UInt, void)			       \
>::type

#define ZIntegerType(Name, T) Zeta::SelectType<					       \
	Zeta::Type<T>::is_integer ? Zeta::Logarithm2<Zeta::Type<T>::size>::value : 31, \
	Z_ENUMERATE_FIXED_INTEGER_TYPES(Name##Int, void)			       \
>::type

#define ZExactType(Name, T) Zeta::SelectType<			       \
		Zeta::Type<T>::is_exact				       \
			? Zeta::Logarithm2<Zeta::Type<T>::size>::value \
			  + (Zeta::Type<T>::is_signed ? 5 : 0)	       \
			: 31,					       \
	Z_ENUMERATE_FIXED_NATURAL_TYPES(Name##UInt, void),	       \
	Z_ENUMERATE_FIXED_INTEGER_TYPES(Name##Int,  void)	       \
>::type

#define ZRealType(Name, T) Zeta::SelectType<		       \
	Zeta::Type<T>::is_real ? Zeta::Type<T>::size - 2 : 31, \
	Z_ENUMERATE_FIXED_REAL_TYPES(Name##Float, void)	       \
>::type

#define ZSignedType(Name, T) Zeta::SelectType<				\
	Zeta::Type<T>::is_signed					\
		? (Zeta::Type<T>::is_real				\
			? Zeta::Type<T>::size - 2 + 5			\
			: Zeta::Logarithm2<Zeta::Type<T>::size>::value)	\
		: 31,							\
	Z_ENUMERATE_FIXED_INTEGER_TYPES(Name##Int,   void),		\
	Z_ENUMERATE_FIXED_REAL_TYPES   (Name##Float, void)		\
>::type

#define ZNumberType(Name, T) Zeta::SelectType<			       \
	Zeta::Type<T>::is_number				       \
		? (Zeta::Type<T>::is_real			       \
			? Zeta::Type<T>::size - 2 + 5 + 5	       \
			: Zeta::Logarithm2<Zeta::Type<T>::size>::value \
			  + (Zeta::Type<T>::is_signed ? 5 : 0))	       \
		: 31,						       \
	Z_ENUMERATE_FIXED_NATURAL_TYPES(Name##UInt,  void),	       \
	Z_ENUMERATE_FIXED_INTEGER_TYPES(Name##Int,   void),	       \
	Z_ENUMERATE_FIXED_REAL_TYPES   (Name##Float, void)	       \
>::type

#endif // __Z_macros_type_selection_HPP__
