/* Z Kit C API - inspection/floating point.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_inspection_floating_point_H__
#define __Z_inspection_floating_point_H__

#include <Z/inspection/CPU.h>
#include <Z/inspection/language.h>

#define Z_INSPECTING_FLOATING_POINT

#	if	Z_CPU_ARCHITECTURE == Z_CPU_ARCHITECTURE_X86_32 || \
		Z_CPU_ARCHITECTURE == Z_CPU_ARCHITECTURE_X86_64

#		include <Z/formats/floating point/IEEE 754.h>
#		include <Z/formats/floating point/Intel.h>

#		undef IEEE_754_BINARY32
#		undef IEEE_754_BINARY64

#		define Z_FLOATING_POINT_NAME_FLOAT   IEEE_754_BINARY32
#		define Z_FLOATING_POINT_NAME_DOUBLE  IEEE_754_BINARY64
#		define Z_FLOATING_POINT_NAME_LDOUBLE INTEL_FLOAT80

#	else
#	endif

#undef Z_INSPECTING_FLOATING_POINT

#include <Z/keys/floating point.h>

#define Z_FLOATING_POINT_HAS_TYPE(TYPE)	0


#define Z_FLOATING_POINT_TYPE(		     TYPE)
#define Z_FLOATING_POINT_LITERAL(	     TYPE)
#define Z_FLOATING_POINT_VALUE_TYPE(	     TYPE)
#define Z_FLOATING_POINT_VALUE_FORMAT(	     TYPE)
#define Z_FLOATING_POINT_BIAS(		     TYPE)
#define Z_FLOATING_POINT_EPSILON(	     TYPE)
#define Z_FLOATING_POINT_MINIMUM(	     TYPE)
#define Z_FLOATING_POINT_MAXIMUM(	     TYPE)
#define Z_FLOATING_POINT_DECIMAL_DIGITS(     TYPE)
#define Z_FLOATING_POINT_SIGNIFICAND_OFFSET( TYPE)
#define Z_FLOATING_POINT_SIGNIFICAND_BITS(   TYPE)
#define Z_FLOATING_POINT_SIGNIFICAND_DIGITS( TYPE)
#define Z_FLOATING_POINT_EXPONENT_OFFSET(    TYPE)
#define Z_FLOATING_POINT_EXPONENT_BITS(	     TYPE)
#define Z_FLOATING_POINT_EXPONENT_RADIX(     TYPE)
#define Z_FLOATING_POINT_EXPONENT_MINIMUM(   TYPE)
#define Z_FLOATING_POINT_EXPONENT_MAXIMUM(   TYPE)
#define Z_FLOATING_POINT_EXPONENT_10_MINIMUM(TYPE)
#define Z_FLOATING_POINT_EXPONENT_10_MAXIMUM(TYPE)
#define Z_FLOATING_POINT_SIGN_OFFSET(	     TYPE)
#define Z_FLOATING_POINT_SIGN_BITS(	     TYPE)

#define Z_FLOATING_POINT_INFINITY(TYPE, LITERAL)
#define Z_FLOATING_POINT_NAN(	  TYPE, LITERAL)














			/*

#if Z_COMPILER_HAS_MACRO(INFINITY)
#	define Z_FLOATING_POINT_INFINITY(TYPE, _) Z_COMPILER_MACRO(INFINITY)(_(Z_FLOATING_POINT_MAXIMUM(TYPE)), _)
#else
#	define Z_FLOATING_POINT_INFINITY(TYPE, _) (_(Z_FLOATING_POINT_MAXIMUM(TYPE)) + _(Z_FLOATING_POINT_MAXIMUM(TYPE)))
#endif

#if Z_COMPILER_HAS_MACRO(NAN)
#	define Z_FLOATING_POINT_NAN(TYPE, _) Z_COMPILER_MACRO(NAN)(_(Z_FLOATING_POINT_MAXIMUM(TYPE)), _)
#else
#	define Z_FLOATING_POINT_NAN(TYPE, _) (Z_FLOATING_POINT_INFINITY(TYPE, _) - Z_FLOATING_POINT_INFINITY(TYPE, _))
#endif*/

#endif /* __Z_inspection_floating_point_H__ */
