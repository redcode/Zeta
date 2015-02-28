/* Q API - macros/casting.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2014 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_macros_casting_H__
#define __Q_macros_casting_H__

#include <Q/inspection/C.h>

#if Q_C_HAS(COMPOUND_LITERAL)

#	define Q_CAST(structure, from_type, to_type) \
		((union {from_type from; to_type to;}){.from = structure}).to

#	define Q_AVAILABLE_CAST_MACRO

#endif

#endif /* __Q_macros_casting_H__ */
