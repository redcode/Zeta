/* Z Kit - inspection/C++/modules/C++14.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//__/__| Kit
Copyright (C) 2006-2020 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_inspection_CPP_modules_CPP14_H
#define Z_inspection_CPP_modules_CPP14_H

#include <Z/inspection/C++/modules/C++11.h>			 /* Paper  Test macro					  */
								 /* -----  ---------------------------------------------- */
#define Z_CPP_HAS_APOSTROPHE_AS_DIGIT_SEPARATOR		    TRUE /* N3781  __cpp_digit_separator(s)	   >= 201309L (?) */
#define Z_CPP_HAS_CPP14_CONSTEXPR_FUNCTION		    TRUE /* N3652  __cpp_constexpr		   >= 201304L (+) */
#define Z_CPP_HAS_CPP14_CONTEXTUAL_CONVERSION		    TRUE /* N3323						  */
#define Z_CPP_HAS_DEFAULT_MEMBER_INITIALIZER_FOR_AGGREGATE  TRUE /* N3653  __cpp_aggregate_nsdmi	   >= 201304L (!) */
#define Z_CPP_HAS_GENERIC_LAMBDA			    TRUE /* N3649  __cpp_generic_lambdas	   >= 201304L (!) */
#define Z_CPP_HAS_INITIALIZED_LAMBDA_CAPTURE		    TRUE /* N3648  __cpp_init_captures		   >= 201304L (!) */
#define Z_CPP_HAS_RETURN_TYPE_DEDUCTION_FOR_NORMAL_FUNCTION TRUE /* N3638  __cpp_return_type_deduction	   >= 201304L (!) */
#define Z_CPP_HAS_SIZED_DEALLOCATION			    TRUE /* N3778  __cpp_sized_deallocation	   >= 201309L (!) */
#define Z_CPP_HAS_VARIABLE_TEMPLATE			    TRUE /* N3651  __cpp_variable_templates	   >= 201304L (!) */
#define Z_CPP_HAS_ATTRIBUTE_DEPRECATED			    TRUE /* N3760  __has_cpp_attribute(deprecated) >= 201309L (!) */
#define Z_CPP_HAS_LITERAL_BINARY_INTEGRAL		    TRUE /* N3472  __cpp_binary_literals	   >= 201304L (!) */
#define Z_CPP_HAS_SPECIFIER_CASE_DECLTYPE_AUTO		    TRUE /* N3638  __cpp_decltype_auto		   >= 201304L (!) */

#endif /* Z_inspection_CPP_modules_CPP14_H */
