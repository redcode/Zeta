/* Q API - types/language.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2012 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_types_language_H__
#define __Q_types_language_H__

#include <Q/inspection/compiler.h>

#if Q_COMPILER_HAS(VAL)
	typedef Q_COMPILER_TYPE(VAL) QVAL;
#else
	typedef void* QVAL;
#endif

#define Q_VAL(p) ((QVAL *)(p))

#endif /* __Q_types_language_H__ */
