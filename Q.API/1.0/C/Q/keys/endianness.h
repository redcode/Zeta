/* Q API - keys/endianness.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2014 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_keys_endianness_H__
#define __Q_keys_endianness_H__

#define Q_ENDIANNESS_MIXED  1
#define	Q_ENDIANNESS_LITTLE 2
#define	Q_ENDIANNESS_BIG    3
#define	Q_ENDIANNESS_PDP    4

#define Q_KEY_BITS_ENDIANNESS 8
#define Q_KEY_LAST_ENDIANNESS Q_ENDIANNESS_PDP

#define Q_ENDIANNESS_STRING_MIXED  "Mixed Endian"
#define Q_ENDIANNESS_STRING_LITTLE "Little Endian"
#define Q_ENDIANNESS_STRING_BIG	   "Big Endian"
#define Q_ENDIANNESS_STRING_PDP	   "PDP Endian"

#endif /* __Q_keys_endianness_H__ */
