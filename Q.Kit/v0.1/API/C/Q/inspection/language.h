/* Q C API - inspection/language.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_inspection_language_H__
#define __Q_inspection_language_H__

#include <Q/inspection/C.h>

#ifdef __cplusplus
#	include <Q/inspection/C++.h>
#endif

#ifdef __OBJC__
#	include <Q/inspection/Objective-C.h>
#endif

#define Q_C_HAS(WHAT) ((defined Q_C_HAS_##WHAT) || (defined Q_COMPILER_C_HAS_##WHAT))

#ifdef __cplusplus
	/* TO DO: Detect C++ standard */
#	define Q_CPP_HAS(     WHAT) ((defined Q_CPP_HAS_##WHAT) || (defined Q_COMPILER_CPP_HAS_##WHAT))
#	define Q_LANGUAGE_HAS(WHAT) Q_C_HAS(WHAT) || Q_CPP_HAS(WHAT)
#	define Q_C_SYMBOLS_BEGIN    extern "C" {
#	define Q_C_SYMBOLS_END	    C
#else
#	define Q_LANGUAGE_HAS(WHAT) Q_C_HAS(WHAT)
#	define Q_C_SYMBOLS_BEGIN
#	define Q_C_SYMBOLS_END
#endif

#endif /* __Q_inspection_language_H__ */
