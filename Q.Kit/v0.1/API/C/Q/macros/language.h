/* Q Kit C API - macros/language.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_macros_language_H__
#define __Q_macros_language_H__

#include <Q/inspection/language.h>

#ifndef AND
#	define AND &&
#endif

#ifndef OR
#	define OR ||
#endif

#ifndef DOT
#	define DOT .
#endif

#ifndef COMMA
#	define COMMA ,
#endif

#if Q_COMPILER_HAS_C_ATTRIBUTE(STRICT_SIZE_BEGIN)
#	define Q_STRICT_SIZE_BEGIN Q_COMPILER_C_ATTRIBUTE_STRICT_SIZE_BEGIN
#	define Q_STRICT_SIZE_END   Q_COMPILER_C_ATTRIBUTE_STRICT_SIZE_END
#else
#	define Q_STRICT_SIZE_BEGIN
#	define Q_STRICT_SIZE_END
#endif

#if Q_C_HAS_TYPE_QUALIFIER(THREAD_LOCAL)


#elif Q_COMPILER_HAS_C_ATTRIBUTE(THREAD_LOCAL)
#	define Q_THREAD_LOCAL Q_COMPILER_C_ATTRIBUTE_THREAD_LOCAL
#endif

#endif /* __Q_macros_language_H__ */
