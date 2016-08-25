/* Z Kit C API - inspection/floating point.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_inspection_floating_point_H__
#define __Z_inspection_floating_point_H__

#include <Z/keys/floating point.h>
#include <Z/inspection/CPU.h>
#include <Z/inspection/language.h>

#define Z_INSPECTING_FLOATING_POINT

#	if	Z_CPU_ARCHITECTURE == Z_CPU_ARCHITECTURE_X86_32 || \
		Z_CPU_ARCHITECTURE == Z_CPU_ARCHITECTURE_X86_64

#		include <Z/formats/floating point/IEEE 754.h>
#		include <Z/formats/floating point/Intel.h>

#		if Z_LANGUAGE_HAS_TYPE(C, FLOAT)
#			define Z_FLOATING_POINT_BITS_FLOAT	32
#			define Z_FLOATING_POINT_TYPE_FLOAT32	float
#			define Z_FLOATING_POINT_LITERAL_FLOAT32	Z_SUFFIX_F

#			define Z_PREPEND_FLOATING_POINT_FLOAT32(RIGHT) Z_IEEE_754_BINARY32##RIGHT
#		endif

#		if Z_LANGUAGE_HAS_TYPE(C, DOUBLE)
#			define Z_FLOATING_POINT_BITS_DOUBLE	64
#			define Z_FLOATING_POINT_TYPE_FLOAT64	double
#			define Z_FLOATING_POINT_LITERAL_FLOAT64	Z_SAME

#			define Z_PREPEND_FLOATING_POINT_FLOAT64(RIGHT) Z_IEEE_754_BINARY64##RIGHT
#		endif

#		if Z_LANGUAGE_HAS_TYPE(C, LDOUBLE)
#			define Z_FLOATING_POINT_BITS_LDOUBLE	 128
#			define Z_FLOATING_POINT_TYPE_FLOAT128	 long double
#			define Z_FLOATING_POINT_LITERAL_FLOAT128 Z_SUFFIX_L

#			define Z_PREPEND_FLOATING_POINT_FLOAT128(RIGHT) Z_INTEL_FLOAT80##RIGHT
#		endif

#	elif	Z_CPU_ARCHITECTURE == Z_CPU_ARCHITECTURE_A_ARCH_32

#		include <Z/formats/floating point/IEEE 754.h>

#		if Z_LANGUAGE_HAS_TYPE(C, FLOAT)
#			define Z_FLOATING_POINT_BITS_FLOAT	32
#			define Z_FLOATING_POINT_TYPE_FLOAT32	float
#			define Z_FLOATING_POINT_LITERAL_FLOAT32 Z_SUFFIX_F

#			define Z_PREPEND_FLOATING_POINT_FLOAT32(RIGHT) Z_IEEE_754_BINARY32##RIGHT
#		endif

#		if Z_LANGUAGE_HAS_TYPE(C, DOUBLE)
#			define Z_FLOATING_POINT_BITS_DOUBLE	64
#			define Z_FLOATING_POINT_TYPE_FLOAT64	double
#			define Z_FLOATING_POINT_LITERAL_FLOAT64 Z_SAME

#			define Z_PREPEND_FLOATING_POINT_FLOAT64(RIGHT) Z_IEEE_754_BINARY64##RIGHT
#		endif

#		if Z_LANGUAGE_HAS_TYPE(C, LDOUBLE)
#			define Z_FLOATING_POINT_BITS_LDOUBLE 64
#		endif

#	endif

#undef Z_INSPECTING_FLOATING_POINT

#define Z_FLOATING_POINT_HAS_TYPE(	     TYPE) (defined Z_FLOATING_POINT_TYPE_##TYPE)
#define Z_FLOATING_POINT_TYPE(		     TYPE) Z_FLOATING_POINT_TYPE_##TYPE
#define Z_FLOATING_POINT_LITERAL(	     TYPE) Z_FLOATING_POINT_LITERAL_##TYPE
#define Z_FLOATING_POINT_VALUE_TYPE(	     TYPE)
#define Z_FLOATING_POINT_VALUE_FORMAT(	     TYPE)
#define Z_FLOATING_POINT_BITS(		     TYPE) Z_FLOATING_POINT_BITS_##TYPE
#define Z_FLOATING_POINT_BIAS(		     TYPE) Z_PREPEND_FLOATING_POINT_##TYPE(_BIAS	       )
#define Z_FLOATING_POINT_DECIMAL_DIGITS(     TYPE) Z_PREPEND_FLOATING_POINT_##TYPE(_DECIMAL_DIGITS     )
#define Z_FLOATING_POINT_SIGNIFICAND_OFFSET( TYPE) Z_PREPEND_FLOATING_POINT_##TYPE(_SIGNIFICAND_OFFSET )
#define Z_FLOATING_POINT_SIGNIFICAND_BITS(   TYPE) Z_PREPEND_FLOATING_POINT_##TYPE(_SIGNIFICAND_BITS   )
#define Z_FLOATING_POINT_SIGNIFICAND_DIGITS( TYPE) Z_PREPEND_FLOATING_POINT_##TYPE(_SIGNIFICAND_DIGITS )
#define Z_FLOATING_POINT_EXPONENT_OFFSET(    TYPE) Z_PREPEND_FLOATING_POINT_##TYPE(_EXPONENT_OFFSET    )
#define Z_FLOATING_POINT_EXPONENT_BITS(	     TYPE) Z_PREPEND_FLOATING_POINT_##TYPE(_EXPONENT_BITS      )
#define Z_FLOATING_POINT_EXPONENT_RADIX(     TYPE) Z_PREPEND_FLOATING_POINT_##TYPE(_EXPONENT_RADIX     )
#define Z_FLOATING_POINT_EXPONENT_MINIMUM(   TYPE) Z_PREPEND_FLOATING_POINT_##TYPE(_EXPONENT_MINIMUM   )
#define Z_FLOATING_POINT_EXPONENT_MAXIMUM(   TYPE) Z_PREPEND_FLOATING_POINT_##TYPE(_EXPONENT_MAXIMUM   )
#define Z_FLOATING_POINT_EXPONENT_10_MINIMUM(TYPE) Z_PREPEND_FLOATING_POINT_##TYPE(_EXPONENT_10_MINIMUM)
#define Z_FLOATING_POINT_EXPONENT_10_MAXIMUM(TYPE) Z_PREPEND_FLOATING_POINT_##TYPE(_EXPONENT_10_MAXIMUM)
#define Z_FLOATING_POINT_SIGN_OFFSET(	     TYPE) Z_PREPEND_FLOATING_POINT_##TYPE(_SIGN_OFFSET	       )
#define Z_FLOATING_POINT_SIGN_BITS(	     TYPE) Z_PREPEND_FLOATING_POINT_##TYPE(_SIGN_BITS	       )
#define Z_FLOATING_POINT_EPSILON(	     TYPE) Z_PREPEND_FLOATING_POINT_##TYPE(_EPSILON	       )
#define Z_FLOATING_POINT_MINIMUM(	     TYPE) Z_PREPEND_FLOATING_POINT_##TYPE(_MINIMUM	       )
#define Z_FLOATING_POINT_MAXIMUM(	     TYPE) Z_PREPEND_FLOATING_POINT_##TYPE(_MAXIMUM	       )

#define	Z_FLOATING_POINT_INFINITY(TYPE, LITERAL) \
	(LITERAL(Z_PREPEND_FLOATING_POINT_##TYPE(_MAXIMUM)) + LITERAL(Z_PREPEND_FLOATING_POINT_##TYPE(_MAXIMUM)))

#define	Z_FLOATING_POINT_NAN(TYPE, LITERAL) \
	((LITERAL(Z_PREPEND_FLOATING_POINT_##TYPE(_MAXIMUM)) + LITERAL(Z_PREPEND_FLOATING_POINT_##TYPE(_MAXIMUM))) - \
	 (LITERAL(Z_PREPEND_FLOATING_POINT_##TYPE(_MAXIMUM)) + LITERAL(Z_PREPEND_FLOATING_POINT_##TYPE(_MAXIMUM))))

#endif /* __Z_inspection_floating_point_H__ */
