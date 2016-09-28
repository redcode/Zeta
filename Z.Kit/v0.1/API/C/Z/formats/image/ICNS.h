/* Z Kit C API - formats/image/ICNS.h
	      ___
 _____	____ /	/______
/_   /_/  -_)  __/  _ /
 /____/\___/\__/ \__,_/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_formats_image_ICNS_H__
#define __Z_formats_image_ICNS_H__

#include <Z/types/base.h>

Z_DEFINE_STRICT_STRUCTURE (
	zuint32 type;
	zuint32 size;
) ZICNSEntry;

Z_DEFINE_STRICT_STRUCTURE (
	zuint32    signature;	  /* 'icns' */
	zuint32    total_size;
	zuint32    toc_signature; /* 'TOC ' */
	zuint32    toc_size;
	ZICNSEntry toc_entries[];
) ZICNSHeader;

#if Z_CPU_INTEGER_ENDIANNESS(32BIT) == Z_ENDIANNESS_BIG

#	define Z_ICNS_ENTRY_TYPE_16X16_32BIT	'is32'
#	define Z_ICNS_ENTRY_TYPE_32X32_32BIT	'il32'
#	define Z_ICNS_ENTRY_TYPE_64X64_32BIT
#	define Z_ICNS_ENTRY_TYPE_128X128_32BIT
#	define Z_ICNS_ENTRY_TYPE_256X256_32BIT
#	define Z_ICNS_ENTRY_TYPE_512X512_32BIT

#if Z_CPU_INTEGER_ENDIANNESS(32BIT) == Z_ENDIANNESS_LITTLE

#endif

#endif /* __Z_formats_image_ICNS_H__ */
