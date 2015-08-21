/* Z Kit C API - types/time.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_types_time_H__
#define __Z_types_time_H__

#include <Z/types/base.h>

#if Z_IS_AVAILABLE(UINT128)
	typedef zuint128 ZAttotime;
#else
	typedef struct {
		zuint64 seconds;
		zuint64 attoseconds;
	} ZAttotime;
#endif

#endif /* __Z_types_time_H__ */
