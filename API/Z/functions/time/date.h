/* Z Kit - functions/time/date.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.

This library is  free software: you can redistribute it  and/or modify it under
the terms  of the GNU  Lesser General Public License  as published by  the Free
Software Foundation, either  version 3 of the License, or  (at your option) any
later version.

This library is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

You should have received  a copy of the GNU Lesser General Public License along
with this library. If not, see <http://www.gnu.org/licenses/>. */

#ifndef _Z_functions_time_date_H_
#define _Z_functions_time_date_H_

#include <Z/types/base.h>
#include <Z/macros/date.h>


static Z_INLINE 
boolean z_gregorian_year_is_leap(zullong year)
	{return Z_GREGORIAN_YEAR_IS_LEAP(year);}


static Z_INLINE
zuint8 z_gregorian_year_days_in_month(zullong year, zuint8 month)
	{
	return month == 2
		? (Z_GREGORIAN_YEAR_IS_LEAP(year) ? 29 : 28)
		: (month == 4 || month == 6 || month == 9 || month == 11 ? 30 : 31);
	}


#endif /* _Z_functions_time_date_H_ */
