/* Z Kit - macros/date.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_macros_date_H_
#define _Z_macros_date_H_

#define Z_GREGORIAN_YEAR_IS_LEAP(year) \
	!((year) % 100 ? (year) % 4 : (year) % 400)

#endif /* _Z_macros_date_H_ */
