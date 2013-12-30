/* Q API - formats/floating point/Intel.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2014 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_formats_floating_point_Intel_H__
#define __Q_formats_floating_point_Intel_H__

#include <Q/types/base.h>

/* MARK: - Intel Float80 */

/*   79 78			    64	 63															       0
   .---.-------------------------------.---------------------------------------------------------------------------------------------------------------------------------.
   | S | E E E E E E E E E E E E E E E | M M M M M M M M M M M M M M M M M M M M M M M M M M M M M M M M M M M M M M M M M M M M M M M M M M M M M M M M M M M M M M M M |
   '---'-------------------------------'---------------------------------------------------------------------------------------------------------------------------------' */

#define Q_INTEL_FLOAT80_BITS			80
#define Q_INTEL_FLOAT80_BIAS			0x3FFF
#define Q_INTEL_FLOAT80_MINIMUM			3.3621031431120935062627E-4932L
#define Q_INTEL_FLOAT80_MAXIMUM			1.1897314953572317650213E+4932L
#define Q_INTEL_FLOAT80_EPSILON			1.0842021724855044340075E-19L
#define Q_INTEL_FLOAT80_DECIMAL_DIGITS		18
#define Q_INTEL_FLOAT80_MANTISA_OFFSET		0
#define Q_INTEL_FLOAT80_MANTISA_BITS		64
#define Q_INTEL_FLOAT80_MANTISSA_DIGITS		64 /* Correct? */
#define Q_INTEL_FLOAT80_EXPONENT_OFFSET		64
#define Q_INTEL_FLOAT80_EXPONENT_BITS		15
#define Q_INTEL_FLOAT80_EXPONENT_RADIX		2
#define Q_INTEL_FLOAT80_EXPONENT_MINIMUM	(-16381)
#define Q_INTEL_FLOAT80_EXPONENT_MAXIMUM	16384
#define Q_INTEL_FLOAT80_EXPONENT_10_MINIMUM	(-4931)
#define Q_INTEL_FLOAT80_EXPONENT_10_MAXIMUM	4932
#define Q_INTEL_FLOAT80_SIGN_OFFSET		127
#define Q_INTEL_FLOAT80_SIGN_BITS		1

typedef struct {
} QIntelFloat80;

/* MARK: - Intel Float96 */

typedef struct {
} QIntelFloat96;

#endif /* __Q_formats_floating_point_Intel_H__ */
