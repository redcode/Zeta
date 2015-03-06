/* Q C API - types/time.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_types_time_H__
#define __Q_types_time_H__

#include <Q/types/base.h>

#if Q_IS_AVAILABLE(UINT128)
	typedef quint128 QAttotime;
#else
	typedef struct {
		quint64 seconds;
		quint64 attoseconds;
	} QAttotime;
#endif

#endif /* __Q_types_time_H__ */
