/* Z Kit - keys/endianness.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_keys_endianness_H_
#define _Z_keys_endianness_H_

#define	Z_ENDIANNESS_BIG    0
#define	Z_ENDIANNESS_LITTLE 1
#define	Z_ENDIANNESS_PDP    2
#define Z_ENDIANNESS_MIXED  4

#define Z_KEY_BITS_ENDIANNESS 8
#define Z_KEY_LAST_ENDIANNESS Z_ENDIANNESS_MIXED

#define Z_ENDIANNESS_STRING_BIG	   "big-endian"
#define Z_ENDIANNESS_STRING_LITTLE "little-endian"
#define Z_ENDIANNESS_STRING_PDP	   "PDP-endian"
#define Z_ENDIANNESS_STRING_MIXED  "mixed-endian"

#endif /* _Z_keys_endianness_H_ */
