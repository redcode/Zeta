/* Q API - functions/time.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2013 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_functions_time_H__
#define __Q_functions_time_H__

#include <Q/types/base.h>
#include <Q/macros/time.h>


Q_INLINE
qboolean q_gregorian_year_is_leap(quint64 year)
	{return Q_GREGORIAN_YEAR_IS_LEAP(year);}


Q_INLINE
quint8 q_gregorian_year_days_in_month(quint64 year, quint8 month)
	{
	if (month == 2) return qv_gregorian_year_is_leap(year) ? 29 : 28;
	if (month == 4 || month == 6 || month == 9 || month == 11) return 30;
	return 31;
	}


#endif /* __Q_functions_time_H__ */
