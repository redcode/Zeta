/* Q API - formats/image/ICNS.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2014 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_formats_image_ICNS_H__
#define __Q_formats_image_ICNS_H__

#include <Q/types/base.h>

Q_DEFINE_STRICT_STRUCTURE (
	quint32 type;
	quint32 size;
) QICNSEntry;

Q_DEFINE_STRICT_STRUCTURE (
	quint32    signature;	  /* 'icns' */
	quint32    total_size;
	quint32    toc_signature; /* 'TOC ' */
	quint32    toc_size;
	QICNSEntry toc_entries[];
) QICNSHeader;

#if Q_CPU_INTEGER_ENDIANNESS(32BIT) == Q_ENDIANNESS_BIG

#	define Q_ICNS_ENTRY_TYPE_16X16_32BIT	'is32'
#	define Q_ICNS_ENTRY_TYPE_32X32_32BIT	'il32'
#	define Q_ICNS_ENTRY_TYPE_64X64_32BIT
#	define Q_ICNS_ENTRY_TYPE_128X128_32BIT
#	define Q_ICNS_ENTRY_TYPE_256X256_32BIT
#	define Q_ICNS_ENTRY_TYPE_512X512_32BIT

#if Q_CPU_INTEGER_ENDIANNESS(32BIT) == Q_ENDIANNESS_LITTLE

#endif

#endif /* __Q_formats_image_ICNS_H__ */
