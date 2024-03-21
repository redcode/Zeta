/* Zeta API - Z/constants/build.h
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_constants_build_HPP
#define Z_constants_build_HPP

#include <Z/inspection/language.h>

#if Z_DIALECT_HAS_SPECIFIER(CPP11, CONSTEXPR)

	namespace Zeta {enum {
		build_year = (__DATE__[7] - '0') * 1000 + (__DATE__[ 8] - '0') * 100 +
			(__DATE__[9] - '0') * 10 + (__DATE__[10] - '0'),

		build_month = __DATE__[0] == 'J'
				? (__DATE__[1] == 'a'
					? 1
					: (__DATE__[2] == 'n' ? 6 : 7))
				: (__DATE__[0] == 'F'
					? 2
					: (__DATE__[0] == 'M'
						? (__DATE__[2] == 'r' ? 3 : 5)
						: (__DATE__[0] == 'A'
							? (__DATE__[1] == 'p' ? 4 : 8)
							: (__DATE__[0] == 'S'
								? 9
								: (__DATE__[0] == 'O'
									? 10
									: (__DATE__[0] == 'N' ? 11 : 12)))))),

		build_day = (__DATE__[4] == ' '
			? 0
			: __DATE__[4] - '0') * 10 + (__DATE__[5] - '0'),

		build_hour    = (__TIME__[0] - '0') * 10 + (__TIME__[1] - '0'),
		build_minutes = (__TIME__[3] - '0') * 10 + (__TIME__[4] - '0'),
		build_seconds = (__TIME__[6] - '0') * 10 + (__TIME__[7] - '0')
	};}

#endif

#endif /* Z_constants_build_HPP */
