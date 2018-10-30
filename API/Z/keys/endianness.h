/* Z Kit - keys/endianness.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.

This library is free software: you can redistribute it and/or modify it
under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this library.  If not, see <http://www.gnu.org/licenses/>. */

#ifndef _Z_keys_endianness_H_
#define _Z_keys_endianness_H_

#define	Z_ENDIANNESS_BIG    0
#define	Z_ENDIANNESS_LITTLE 1
#define	Z_ENDIANNESS_PDP    2
#define Z_ENDIANNESS_MIXED  4

#define Z_KEY_BITS_ENDIANNESS 8
#define Z_KEY_LAST_ENDIANNESS Z_ENDIANNESS_MIXED

#define Z_ENDIANNESS_STRING_BIG	   "Big Endian"
#define Z_ENDIANNESS_STRING_LITTLE "Little Endian"
#define Z_ENDIANNESS_STRING_PDP	   "PDP Endian"
#define Z_ENDIANNESS_STRING_MIXED  "Mixed Endian"

#endif /* _Z_keys_endianness_H_ */
