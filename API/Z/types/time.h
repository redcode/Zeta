/* Z Kit - types/time.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_types_time_H_
#define _Z_types_time_H_

#include <Z/types/base.h>

Z_DEFINE_STRICT_STRUCTURE (
	Z128Bit	seconds;
	Z64Bit	attoseconds;
) ZAttotime;

Z_DEFINE_STRICT_STRUCTURE (
	Z128Bit seconds;
	zuint32 nanoseconds;
) ZNanotime;

#endif /* _Z_types_time_H_ */
