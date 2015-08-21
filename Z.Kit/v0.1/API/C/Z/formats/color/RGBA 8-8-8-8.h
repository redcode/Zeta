/* Z Kit C API - formats/color/RGBA 8-8-8-8.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_formats_color_RGBA_8_8_8_8_H__
#define __Z_formats_color_RGBA_8_8_8_8_H__

#include <Z/types/base.h>

#if Z_UINT32_ENDIANNESS == Z_ENDIANNESS_BIG

	Z_DEFINE_STRICT_STRUCTURE (
		zuint8 red;
		zuint8 green;
		zuint8 blue;
		zuint8 alpha;
	) ZRGBA_8_8_8_8;

#elif Z_UINT32_ENDIANNESS == Z_ENDIANNESS_LITTLE

	Z_DEFINE_STRICT_STRUCTURE (
		zuint8 alpha;
		zuint8 blue;
		zuint8 green;
		zuint8 red;
	) ZRGBA_8_8_8_8;

#endif

#endif /* __Z_formats_color_RGBA_8_8_8_8_H__ */
