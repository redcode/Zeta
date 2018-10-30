/* Z Kit - formats/image/ICNS.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.

This library  is free software: you  can redistribute it and/or  modify it under
the terms  of the  GNU Lesser General  Public License as  published by  the Free
Software Foundation,  either version 3 of  the License, or (at  your option) any
later version.

This library is distributed in the hope  that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty  of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

You should have received  a copy of the GNU Lesser  General Public License along
with this library. If not, see <http://www.gnu.org/licenses/>. */

#ifndef _Z_formats_image_ICNS_H_
#define _Z_formats_image_ICNS_H_

#include <Z/types/base.h>

Z_DEFINE_STRICT_STRUCTURE (
	zuint32 type;
	zuint32 size;
) ZICNSEntry;

Z_DEFINE_STRICT_STRUCTURE (
	zuint32 signature;     /* 'icns' */
	zuint32 total_size;
	zuint32 toc_signature; /* 'TOC ' */
	zuint32 toc_size;
	Z_FLEXIBLE_ARRAY_MEMBER(ZICNSEntry toc_entries[];)
) ZICNSHeader;

#if Z_CPU_INTEGER_ENDIANNESS(32BIT) == Z_ENDIANNESS_BIG

#	define Z_ICNS_ENTRY_TYPE_16X16_32BIT   'is32'
#	define Z_ICNS_ENTRY_TYPE_32X32_32BIT   'il32'
#	define Z_ICNS_ENTRY_TYPE_64X64_32BIT
#	define Z_ICNS_ENTRY_TYPE_128X128_32BIT
#	define Z_ICNS_ENTRY_TYPE_256X256_32BIT
#	define Z_ICNS_ENTRY_TYPE_512X512_32BIT

#if Z_CPU_INTEGER_ENDIANNESS(32BIT) == Z_ENDIANNESS_LITTLE

#endif

#endif /* _Z_formats_image_ICNS_H_ */
