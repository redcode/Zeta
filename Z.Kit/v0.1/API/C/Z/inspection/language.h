/* Z Kit C API - inspection/language.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_inspection_language_H__
#define __Z_inspection_language_H__

#include <Z/keys/language.h>
#include <Z/inspection/C.h>
#include <Z/inspection/compiler.h>

#if defined(__cplusplus) && (defined(__OBJC__) || defined(__OBJC2__))

#	include <Z/inspection/C++.h>
#	include <Z/inspection/Objective-C.h>

#	define Z_LANGUAGE Z_LANGUAGE_OBJECTIVE_CPP

#elif defined(__OBJC__) || defined(__OBJC2__)

#	include <Z/inspection/Objective-C.h>

#	define Z_LANGUAGE Z_LANGUAGE_OBJECTIVE_C

#elif defined(__cplusplus)

#	include <Z/inspection/C++.h>

#	define Z_LANGUAGE Z_LANGUAGE_CPP

#else
#	define Z_LANGUAGE Z_LANGUAGE_C
#endif

#define Z_LANGUAGE_HAS(LANGUAGE, WHAT)			    \
	(!(defined Z_COMPILER_##LANGUAGE##_LACKS_##WHAT) && \
	 ((defined Z_COMPILER_##LANGUAGE##_HAS_##WHAT)	 || \
	  (defined Z_##LANGUAGE##_HAS_##WHAT)))

#define Z_LANGUAGE_HAS_TYPE(LANGUAGE, TYPE)			 \
	(!(defined Z_COMPILER_##LANGUAGE##_LACKS_TYPE_##TYPE) && \
	 ((defined Z_COMPILER_##LANGUAGE##_HAS_TYPE_##TYPE)  || \
	  (defined Z_##LANGUAGE##_HAS_SPECIFIER_##TYPE)))

#define Z_LANGUAGE_HAS_TYPE_QUALIFIER(LANGUAGE, TYPE_QUALIFIER)			     \
	(!(defined Z_COMPILER_##LANGUAGE##_LACKS_TYPE_QUALIFIER_##TYPE_QUALIFIER) && \
	 ((defined Z_COMPILER_##LANGUAGE##_HAS_TYPE_QUALIFIER_##TYPE_QUALIFIER)	  || \
	  (defined Z_##LANGUAGE##_HAS_TYPE_QUALIFIER_##TYPE_QUALIFIER)))

#define Z_LANGUAGE_HAS_STORAGE_CLASS(LANGUAGE, STORAGE_CLASS)			   \
	(!(defined Z_COMPILER_##LANGUAGE##_LACKS_STORAGE_CLASS_##STORAGE_CLASS) && \
	 ((defined Z_COMPILER_##LANGUAGE##_HAS_STORAGE_CLASS_##STORAGE_CLASS)	|| \
	  (defined Z_##LANGUAGE##_HAS_STORAGE_CLASS_##STORAGE_CLASS)))

#define Z_LANGUAGE_HAS_SPECIFIER(LANGUAGE, SPECIFIER)			   \
	(!(defined Z_COMPILER_##LANGUAGE##_LACKS_SPECIFIER_##SPECIFIER) && \
	 ((defined Z_COMPILER_##LANGUAGE##_HAS_SPECIFIER_##SPECIFIER)	|| \
	  (defined Z_##LANGUAGE##_HAS_SPECIFIER_##SPECIFIER)))

#define Z_LANGUAGE_HAS_OPERATOR(LANGUAGE, OPERATOR)			 \
	(!(defined Z_COMPILER_##LANGUAGE##_LACKS_OPERATOR_##OPERATOR) && \
	 ((defined Z_COMPILER_##LANGUAGE##_HAS_OPERATOR_##OPERATOR)   || \
	  (defined Z_##LANGUAGE##_HAS_OPERATOR_##OPERATOR)))

#endif /* __Z_inspection_language_H__ */
