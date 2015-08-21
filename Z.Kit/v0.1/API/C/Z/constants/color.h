/* Z Kit C API - constants/color.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_constants_color_H__
#define __Z_constants_color_H__

#include <Z/inspection/CPU.h>

#if Z_CPU_32BIT_ENDIANNESS == Z_ENDIANNESS_BIG

#	define Z_RGBA_8_8_8_MASK_R
#	define Z_RGBA_8_8_8_MASK_G
#	define Z_RGBA_8_8_8_MASK_B
#	define Z_RGBA_8_8_8_MASK_A

#elif Z_CPU_32BIT_ENDIANNESS == Z_ENDIANNESS_LITTLE

#	define Z_RGBA_8_8_8_MASK_R
#	define Z_RGBA_8_8_8_MASK_G
#	define Z_RGBA_8_8_8_MASK_B
#	define Z_RGBA_8_8_8_MASK_A

#endif

#endif /* __Z_constants_color_H__ */
