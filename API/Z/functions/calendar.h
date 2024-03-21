/* Zeta API - Z/functions/calendar.h
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_functions_calendar_H
#define Z_functions_calendar_H

#include <Z/types/integral.h>
#include <Z/macros/calendar.h>


static Z_INLINE
boolean z_gregorian_year_is_leap(zulong year)
	{return Z_GREGORIAN_YEAR_IS_LEAP(year);}


static Z_INLINE
zuint8 z_gregorian_year_days_in_month(zulong year, zuint8 month)
	{
	return month == 2
		? (Z_GREGORIAN_YEAR_IS_LEAP(year) ? 29 : 28)
		: (month == 4 || month == 6 || month == 9 || month == 11
			? 30 : 31);
	}


static Z_INLINE
boolean z_julian_year_is_leap(zulong year)
	{return Z_JULIAN_YEAR_IS_LEAP(year);}


#endif /* Z_functions_calendar_H */
