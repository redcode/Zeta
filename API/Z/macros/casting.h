/* Z Kit - macros/casting.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.

This library  is free software: you  can redistribute it and/or  modify it under
the terms  of the  GNU Lesser General  Public License as  published by  the Free
Software Foundation,  either version 3 of  the License, or (at  your option) any
later version.

This library is distributed in the hope  that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty  of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

You should have received  a copy of the GNU Lesser  General Public License along
with this library. If not, see <http://www.gnu.org/licenses/>. */

#ifndef _Z_macros_casting_H_
#define _Z_macros_casting_H_

#include <Z/inspection/language.h>

#if	Z_LANGUAGE_HAS(C, ANONYMOUS_UNION	) && \
	Z_LANGUAGE_HAS(C, COMPOUND_LITERAL	) && \
	Z_LANGUAGE_HAS(C, DESIGNATED_INITIALIZER)

#	define Z_CAST(to_type, from_type, structure) \
		((union {to_type to; from_type from;}){.from = structure}).to

#endif

#endif /* _Z_macros_casting_H_ */
