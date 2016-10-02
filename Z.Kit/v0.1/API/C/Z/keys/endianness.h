/* Z Kit C API - keys/endianness.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_|
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_keys_endianness_H__
#define __Z_keys_endianness_H__

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

#endif /* __Z_keys_endianness_H__ */
