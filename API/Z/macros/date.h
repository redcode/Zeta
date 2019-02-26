/* Z Kit - macros/date.h
 _____  _______________
/_   /_/  -_/_   _/  _ | Kit
 /____/\___/ /__//___/_| ゼータキット
Copyright (C) 2006-2019 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_macros_date_H
#define Z_macros_date_H

#define Z_GREGORIAN_YEAR_IS_LEAP(year) \
	!((year) % 100 ? (year) % 4 : (year) % 400)

#endif /* Z_macros_date_H */
