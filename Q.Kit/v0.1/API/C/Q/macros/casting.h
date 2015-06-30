/* Q Kit C API - macros/casting.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_macros_casting_H__
#define __Q_macros_casting_H__

#include <Q/inspection/language.h>

#if Q_LANGUAGE_HAS(COMPOUND_LITERAL) && Q_LANGUAGE_HAS(ANONYMOUS_UNION)

#	define Q_CAST(from_type, to_type, structure) \
		((union {from_type from; to_type to;}){.from = structure}).to

#	define Q_AVAILABLE_CAST_MACRO

#endif

#endif /* __Q_macros_casting_H__ */
