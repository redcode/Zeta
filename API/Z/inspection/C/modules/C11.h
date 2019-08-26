/* Z Kit - inspection/C/modules/C11.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2019 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_inspection_C_modules_C11_H
#define Z_inspection_C_modules_C11_H

#include <Z/inspection/C/modules/C99.h>

#define Z_C_HAS_ANONYMOUS_STRUCTURE_AS_MEMBER TRUE
#define Z_C_HAS_ANONYMOUS_UNION_AS_MEMBER     TRUE
#define Z_C_HAS_GENERIC_SELECTION	      TRUE
#define Z_C_HAS_STATIC_ASSERTION	      TRUE
#define Z_C_HAS_TYPEDEF_REDECLARATION	      TRUE
#define Z_C_HAS_LITERAL_CHAR16_T_CHARACTER    TRUE
#define Z_C_HAS_LITERAL_CHAR16_T_STRING	      TRUE
#define Z_C_HAS_LITERAL_CHAR32_T_CHARACTER    TRUE
#define Z_C_HAS_LITERAL_CHAR32_T_STRING	      TRUE
#define Z_C_HAS_LITERAL_UTF8_STRING	      TRUE
#define Z_C_HAS_OPERATOR_ALIGNOF	      TRUE
#define Z_C_HAS_SPECIFIER_ALIGNAS	      TRUE
#define Z_C_HAS_SPECIFIER_NORETURN	      TRUE
#define Z_C_HAS_STORAGE_CLASS_THREAD_LOCAL    TRUE

#ifndef __STDC_NO_ATOMICS__
#	define Z_C_HAS_TYPE_MODIFIER_ATOMIC  TRUE
#	define Z_C_HAS_TYPE_QUALIFIER_ATOMIC TRUE
#endif

#ifdef __STDC_NO_COMPLEX__
#	undef Z_C_HAS_TYPE_DOUBLE_COMPLEX
#	undef Z_C_HAS_TYPE_DOUBLE_IMAGINARY
#	undef Z_C_HAS_TYPE_FLOAT_COMPLEX
#	undef Z_C_HAS_TYPE_FLOAT_IMAGINARY
#	undef Z_C_HAS_TYPE_LONG_DOUBLE_COMPLEX
#	undef Z_C_HAS_TYPE_LONG_DOUBLE_IMAGINARY
#	undef Z_C_HAS_TYPE_MODIFIER_COMPLEX
#	undef Z_C_HAS_TYPE_MODIFIER_IMAGINARY

#elif	defined(__STDC_IEC_559_COMPLEX__) && \
	__STDC_IEC_559_COMPLEX__ == 1	  && \
	!defined(Z_C_HAS_TYPE_MODIFIER_IMAGINARY)

#	define Z_C_HAS_TYPE_DOUBLE_IMAGINARY	  TRUE
#	define Z_C_HAS_TYPE_FLOAT_IMAGINARY	  TRUE
#	define Z_C_HAS_TYPE_LONG_DOUBLE_IMAGINARY TRUE
#	define Z_C_HAS_TYPE_MODIFIER_IMAGINARY	  TRUE
#endif

#ifdef __STDC_NO_VLA__
#	undef Z_C_HAS_VLA
#endif

#endif /* Z_inspection_C_modules_C11_H */
