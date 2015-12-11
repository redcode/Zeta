/* Z Kit C API - keys/endianness.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_keys_endianness_H__
#define __Z_keys_endianness_H__

#define Z_ENDIANNESS_MIXED  1
#define	Z_ENDIANNESS_LITTLE 2
#define	Z_ENDIANNESS_BIG    3
#define	Z_ENDIANNESS_PDP    4

#define Z_KEY_BITS_ENDIANNESS 8
#define Z_KEY_LAST_ENDIANNESS Z_ENDIANNESS_PDP

#define Z_ENDIANNESS_STRING_MIXED  "Mixed Endian"
#define Z_ENDIANNESS_STRING_LITTLE "Little Endian"
#define Z_ENDIANNESS_STRING_BIG	   "Big Endian"
#define Z_ENDIANNESS_STRING_PDP	   "PDP Endian"

#endif /* __Z_keys_endianness_H__ */
