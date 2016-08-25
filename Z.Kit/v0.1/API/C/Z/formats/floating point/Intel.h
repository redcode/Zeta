/* Z Kit C API - formats/floating point/Intel.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_formats_floating_point_Intel_H__
#define __Z_formats_floating_point_Intel_H__

/* MARK: - Intel Float80 */

#define Z_INTEL_FLOAT80_BITS			80
#define Z_INTEL_FLOAT80_BIAS			16383				/* OK */
#define Z_INTEL_FLOAT80_EPSILON			1.0842021724855044340075e-19	/* OK */
#define Z_INTEL_FLOAT80_MINIMUM			3.3621031431120935062627e-4932	/* OK */
#define Z_INTEL_FLOAT80_MAXIMUM			1.1897314953572317650213e+4932	// OK
#define Z_INTEL_FLOAT80_DECIMAL_DIGITS		18		/* OK */
#define Z_INTEL_FLOAT80_SIGNIFICAND_OFFSET	0		/* OK */
#define Z_INTEL_FLOAT80_SIGNIFICAND_BITS	64		/* OK */
#define Z_INTEL_FLOAT80_SIGNIFICAND_DIGITS	64		/* OK */
#define Z_INTEL_FLOAT80_EXPONENT_OFFSET		64		/* OK */
#define Z_INTEL_FLOAT80_EXPONENT_BITS		15
#define Z_INTEL_FLOAT80_EXPONENT_RADIX		2		/* OK */
#define Z_INTEL_FLOAT80_EXPONENT_MINIMUM	-16381		/* OK */
#define Z_INTEL_FLOAT80_EXPONENT_MAXIMUM	16384		/* OK */
#define Z_INTEL_FLOAT80_EXPONENT_10_MINIMUM	-4931		/* OK */
#define Z_INTEL_FLOAT80_EXPONENT_10_MAXIMUM	4932		/* OK */
#define Z_INTEL_FLOAT80_SIGN_OFFSET		79		/* OK */
#define Z_INTEL_FLOAT80_SIGN_BITS		1		/* OK */

#endif /* __Z_formats_floating_point_Intel_H__ */

#ifdef Z_INSPECTING_FLOATING_POINT

#	ifndef __Z_formats_floating_point_Intel_H__INSPECTION
#	define __Z_formats_floating_point_Intel_H__INSPECTION

#	define Z_INSERT_FLOATING_POINT(left, right) left##IEEE754##right
#	define Z_INSERT_FloatingPoint( left, right) left##IEEE754##right
#	define Z_INSERT_floating_point(left, right) left##ieee754##right

#	endif /* __Z_formats_floating_point_Intel_H__INSPECTION */

#else

#	ifndef __Z_formats_floating_point_Intel_H__NO_INSPECTION
#	define __Z_formats_floating_point_Intel_H__NO_INSPECTION

#	include <Z/types/base.h>

	typedef struct {
	} ZIntelFloat80;

	typedef struct {
	} ZIntelFloat96;

#	endif /* __Z_formats_floating_point_Intel_H__NO_INSPECTION */

#endif
