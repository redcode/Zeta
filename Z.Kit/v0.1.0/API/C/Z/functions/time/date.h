/* Z Kit C API - functions/time/date.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_functions_time_date_H__
#define __Z_functions_time_date_H__

#include <Z/types/base.h>
#include <Z/macros/date.h>


Z_INLINE zboolean z_gregorian_year_is_leap(zullong year)
	{return Z_GREGORIAN_YEAR_IS_LEAP(year);}


Z_INLINE zuint8 z_gregorian_year_days_in_month(zullong year, zuint8 month)
	{
	if (month == 2) return z_gregorian_year_is_leap(year) ? 29 : 28;
	if (month == 4 || month == 6 || month == 9 || month == 11) return 30;
	return 31;
	}


#endif /* __Z_functions_time_date_H__ */
