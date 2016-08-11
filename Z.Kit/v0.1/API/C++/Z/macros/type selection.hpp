 /* Z Kit C++ API - macros/type selection.hpp
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_macros_type_selection_HPP__
#define __Z_macros_type_selection_HPP__

#include <Z/macros/conditionals.h>
#include <Z/traits/mathematics.hpp>

#define Z_ENUMERATE_FIXED_NATURAL_TYPES(prefix, invalid)      \
	prefix##8, prefix##16, prefix##32,		      \
	Z_IF_UINT64_IS_AVAILABLE_ELSE (prefix##64,  invalid), \
	Z_IF_UINT128_IS_AVAILABLE_ELSE(prefix##128, invalid)

#define Z_ENUMERATE_FIXED_INTEGER_TYPES(prefix, invalid)     \
	prefix##8, prefix##16, prefix##32,		     \
	Z_IF_INT64_IS_AVAILABLE_ELSE (prefix##64,  invalid), \
	Z_IF_INT128_IS_AVAILABLE_ELSE(prefix##128, invalid)

#define Z_ENUMERATE_FIXED_REAL_TYPES(prefix, invalid)					  \
	Z_IF_FLOAT16_IS_AVAILABLE_ELSE (prefix##16,  invalid),				  \
	Z_IF_FLOAT24_IS_AVAILABLE_ELSE (prefix##24,  invalid),				  \
	Z_IF_FLOAT32_IS_AVAILABLE_ELSE (prefix##32,  invalid), invalid,			  \
	Z_IF_FLOAT48_IS_AVAILABLE_ELSE (prefix##48,  invalid), invalid,			  \
	Z_IF_FLOAT64_IS_AVAILABLE_ELSE (prefix##64,  invalid),				  \
	Z_IF_FLOAT72_IS_AVAILABLE_ELSE (prefix##72,  invalid),				  \
	Z_IF_FLOAT80_IS_AVAILABLE_ELSE (prefix##80,  invalid), invalid,			  \
	Z_IF_FLOAT96_IS_AVAILABLE_ELSE (prefix##96,  invalid), invalid, invalid, invalid, \
	Z_IF_FLOAT128_IS_AVAILABLE_ELSE(prefix##128, invalid)

#define ZNaturalType(Name, T) Zeta::SelectType<		  \
	Zeta::Logarithm2<Zeta::Type<T>::size>::value,	  \
	Z_ENUMERATE_FIXED_NATURAL_TYPES(Name##UInt, void) \
>::type

#define ZIntegerType(Name, T) Zeta::SelectType<		 \
	Zeta::Logarithm2<Zeta::Type<T>::size>::value,	 \
	Z_ENUMERATE_FIXED_INTEGER_TYPES(Name##Int, void) \
>::type

#define ZExactType(Name, T) Zeta::SelectType<		   \
	Zeta::Logarithm2<Zeta::Type<T>::size>::value	   \
	+ (Zeta::Type<T>::is_signed ? 5 : 0),		   \
	Z_ENUMERATE_FIXED_NATURAL_TYPES(Name##UInt, void), \
	Z_ENUMERATE_FIXED_INTEGER_TYPES(Name##Int,  void)  \
>::type

#define ZRealType(Name, T) Zeta::SelectType<		\
	Zeta::Type<T>::size - 2,			\
	Z_ENUMERATE_FIXED_REAL_TYPES(Name##Float, void) \
>::type

#define ZSignedType(Name, T) SelectType<			\
	Zeta::Type<T>::is_real					\
		? Zeta::Type<T>::size - 2 + 5			\
		: Zeta::Logarithm2<Zeta::Type<T>::size>::value,	\
	Z_ENUMERATE_FIXED_INTEGER_TYPES(Name##Int,   void),	\
	Z_ENUMERATE_FIXED_REAL_TYPES   (Name##Float, void)	\
>::type

#define ZNumberType(Name, T) SelectType<		       \
	Zeta::Type<T>::is_real				       \
		? Zeta::Type<T>::size - 2 + 5 + 5	       \
		: Zeta::Logarithm2<Zeta::Type<T>::size>::value \
		  + (Zeta::Type<T>::is_signed ? 5 : 0),	       \
	Z_ENUMERATE_FIXED_NATURAL_TYPES(Name##UInt,  void),    \
	Z_ENUMERATE_FIXED_INTEGER_TYPES(Name##Int,   void),    \
	Z_ENUMERATE_FIXED_REAL_TYPES   (Name##Float, void)     \
>::type

#endif // __Z_macros_type_selection_HPP__
