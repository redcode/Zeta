/* Z Kit C API - macros/casting.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_macros_casting_H__
#define __Z_macros_casting_H__

#include <Z/inspection/language.h>

#if Z_LANGUAGE_HAS(COMPOUND_LITERAL) && Z_LANGUAGE_HAS(ANONYMOUS_UNION)

#	define Z_CAST(to_type, from_type, structure) \
		((union {to_type to; from_type from;}){.from = structure}).to

#	define Z_AVAILABLE_CAST_MACRO

#endif

#endif /* __Z_macros_casting_H__ */
