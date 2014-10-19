/* Q API - formats/color/RGBA 8-8-8-8.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2014 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_formats_color_RGBA_8_8_8_8_H__
#define __Q_formats_color_RGBA_8_8_8_8_H__

#include <Q/types/base.h>

#if Q_UINT32_ENDIANNESS == Q_ENDIANNESS_BIG

	Q_DEFINE_STRICT_STRUCTURE (
		quint8 red;
		quint8 green;
		quint8 blue;
		quint8 alpha;
	) QRGBA_8_8_8_8;

#elif Q_UINT32_ENDIANNESS == Q_ENDIANNESS_LITTLE

	Q_DEFINE_STRICT_STRUCTURE (
		quint8 alpha;
		quint8 blue;
		quint8 green;
		quint8 red;
	) QRGBA_8_8_8_8;

#endif

#endif /* __Q_formats_color_RGBA_8_8_8_8_H__ */
