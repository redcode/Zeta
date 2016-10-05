/* Z Kit C API - macros/casting.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_macros_casting_H__
#define __Z_macros_casting_H__

#include <Z/inspection/language.h>

#if	Z_LANGUAGE_HAS(C, ANONYMOUS_UNION	) && \
	Z_LANGUAGE_HAS(C, COMPOUND_LITERAL	) && \
	Z_LANGUAGE_HAS(C, DESIGNATED_INITIALIZER)

#	define Z_CAST(to_type, from_type, structure) \
		((union {to_type to; from_type from;}){.from = structure}).to

#endif

#endif /* __Z_macros_casting_H__ */
