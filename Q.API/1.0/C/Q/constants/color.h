/* Q API - constants/color.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2014 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_constants_color_H__
#define __Q_constants_color_H__

#include <Q/inspection/CPU.h>

#if Q_CPU_32BIT_ENDIANNESS == Q_ENDIANNESS_BIG

#	define Q_RGBA_8_8_8_MASK_R
#	define Q_RGBA_8_8_8_MASK_G
#	define Q_RGBA_8_8_8_MASK_B
#	define Q_RGBA_8_8_8_MASK_A

#elif Q_CPU_32BIT_ENDIANNESS == Q_ENDIANNESS_LITTLE

#	define Q_RGBA_8_8_8_MASK_R
#	define Q_RGBA_8_8_8_MASK_G
#	define Q_RGBA_8_8_8_MASK_B
#	define Q_RGBA_8_8_8_MASK_A

#endif

#endif /* __Q_constants_color_H__ */
