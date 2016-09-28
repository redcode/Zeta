/* Z Kit C API - types/time.h
	      ___
 _____	____ /	/______
/_   /_/  -_)  __/  _ /
 /____/\___/\__/ \__,_/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_types_time_H__
#define __Z_types_time_H__

#include <Z/types/base.h>

Z_DEFINE_STRICT_STRUCTURE (Z_32BIT_ENDIANIZED_MEMBERS(2) (
	Z128Bit	seconds,
	Z64Bit	attoseconds
)) ZAttotime;

Z_DEFINE_STRICT_STRUCTURE (Z_32BIT_ENDIANIZED_MEMBERS(2) (
	Z128Bit seconds,
	zuint32 nanoseconds
)) ZNanotime;

#endif /* __Z_types_time_H__ */
