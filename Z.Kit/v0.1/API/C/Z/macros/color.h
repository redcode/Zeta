/* Z Kit C API - macros/color.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_macros_color_H__
#define __Z_macros_color_H__

#include <Z/types/base.h>

#if Z_UINT32_ENDIANNESS == Z_ENDIANNESS_BIG

#	define Z_ARGB32(alpha, red, green, blue) Z_UINT32(0x##alpha##red##green##blue)
#	define Z_RGBA32(red, green, blue, alpha) Z_UINT32(0x##red##green##blue##alpha)

#elif Z_UINT32_ENDIANNESS == Z_ENDIANNESS_LITTLE

#	define Z_ARGB32(alpha, red, green, blue) Z_UINT32(0x##blue##green##red##alpha)
#	define Z_RGBA32(red, green, blue, alpha) Z_UINT32(0x##alpha##blue##green##red)

#endif

#endif /* __Z_macros_color_H__ */
