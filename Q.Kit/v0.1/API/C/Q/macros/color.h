/* Q Kit C API - macros/color.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_macros_color_H__
#define __Q_macros_color_H__

#include <Q/types/base.h>

#if Q_UINT32_ENDIANNESS == Q_ENDIANNESS_BIG

#	define Q_ARGB32(alpha, red, green, blue) Q_UINT32(0x##alpha##red##green##blue)
#	define Q_RGBA32(red, green, blue, alpha) Q_UINT32(0x##red##green##blue##alpha)

#elif Q_UINT32_ENDIANNESS == Q_ENDIANNESS_LITTLE

#	define Q_ARGB32(alpha, red, green, blue) Q_UINT32(0x##blue##green##red##alpha)
#	define Q_RGBA32(red, green, blue, alpha) Q_UINT32(0x##alpha##blue##green##red)

#endif

#endif /* __Q_macros_color_H__ */
