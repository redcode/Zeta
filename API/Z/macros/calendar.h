/* Zeta API - Z/macros/calendar.h
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_macros_calendar_H
#define Z_macros_calendar_H

#define Z_GREGORIAN_YEAR_IS_LEAP(year) \
	!((year) % ((year) % 100 ? 4 : 400))

#define Z_JULIAN_YEAR_IS_LEAP(year) \
	!((year) % 4)

#endif /* Z_macros_calendar_H */
