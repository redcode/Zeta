/* Q Kit C API - inspection/language.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_inspection_language_H__
#define __Q_inspection_language_H__

#include <Q/keys/language.h>
#include <Q/inspection/C.h>

#ifdef __cplusplus
#	include <Q/inspection/C++.h>
#endif

#ifdef __OBJC__
#	include <Q/inspection/Objective-C.h>
#endif

#include <Q/inspection/compiler.h>

#if defined(__cplusplus) && defined(__OBJC__)
#	define Q_LANGUAGE Q_LANGUAGE_OBJECTIVE_CPP
#elif defined(__OBJC__)
#	define Q_LANGUAGE Q_LANGUAGE_OBJECTIVE_C
#elif defined(__cplusplus)
#	define Q_LANGUAGE Q_LANGUAGE_CPP
#else
#	define Q_LANGUAGE Q_LANGUAGE_C
#endif

#define Q_LANGUAGE_HAS(WHAT)		       \
	(defined Q_C_HAS_##WHAT)	    || \
	(defined Q_CPP_HAS_##WHAT)	    || \
	(defined Q_OBJECTIVE_C_HAS_##WHAT)  || \
	(defined Q_COMPILER_C_HAS_##WHAT)   || \
	(defined Q_COMPILER_CPP_HAS_##WHAT) || \
	(defined Q_COMPILER_OBJECTIVE_C_HAS_##WHAT)

#define Q_LANGUAGE_HAS_TYPE(WHICH)		      \
	!(defined Q_COMPILER_LACKS_TYPE_##WHICH)   && \
	((defined Q_C_HAS_TYPE_##WHICH)		   || \
	 (defined Q_CPP_HAS_TYPE_##WHICH)	   || \
	 (defined Q_OBJECTIVE_C_HAS_TYPE_##WHICH)  || \
	 (defined Q_COMPILER_C_HAS_TYPE_##WHICH)   || \
	 (defined Q_COMPILER_CPP_HAS_TYPE_##WHICH) || \
	 (defined Q_COMPILER_OBJECTIVE_C_HAS_TYPE_##WHICH))

#define Q_LANGUAGE_HAS_TYPE_QUALIFIER(WHICH)		       \
	(defined Q_C_HAS_TYPE_QUALIFIER_##WHICH)	    || \
	(defined Q_CPP_HAS_TYPE_QUALIFIER_##WHICH)	    || \
	(defined Q_OBJECTIVE_C_HAS_TYPE_QUALIFIER_##WHICH)  || \
	(defined Q_COMPILER_C_HAS_TYPE_QUALIFIER_##WHICH)   || \
	(defined Q_COMPILER_CPP_HAS_TYPE_QUALIFIER_##WHICH) || \
	(defined Q_COMPILER_OBJECTIVE_C_HAS_TYPE_QUALIFIER_##WHICH)

#define Q_LANGUAGE_HAS_STORAGE_CLASS(WHICH)		      \
	(defined Q_C_HAS_STORAGE_CLASS_##WHICH)		   || \
	(defined Q_CPP_HAS_STORAGE_CLASS_##WHICH)	   || \
	(defined Q_OBJECTIVE_C_HAS_STORAGE_CLASS_##WHICH)  || \
	(defined Q_COMPILER_C_HAS_STORAGE_CLASS_##WHICH)   || \
	(defined Q_COMPILER_CPP_HAS_STORAGE_CLASS_##WHICH) || \
	(defined Q_COMPILER_OBJECTIVE_C_HAS_STORAGE_CLASS_##WHICH)

#define Q_LANGUAGE_HAS_SPECIFIER(WHICH)		          \
	(defined Q_C_HAS_SPECIFIER_##WHICH)	       || \
	(defined Q_CPP_HAS_SPECIFIER_##WHICH)	       || \
	(defined Q_OBJECTIVE_C_HAS_SPECIFIER_##WHICH)  || \
	(defined Q_COMPILER_C_HAS_SPECIFIER_##WHICH)   || \
	(defined Q_COMPILER_CPP_HAS_SPECIFIER_##WHICH) || \
	(defined Q_COMPILER_OBJECTIVE_C_HAS_SPECIFIER_##WHICH)

#define Q_LANGUAGE_HAS_OPERATOR(WHICH)		         \
	(defined Q_C_HAS_OPERATOR_##WHICH)	      || \
	(defined Q_CPP_HAS_OPERATOR_##WHICH)	      || \
	(defined Q_OBJECTIVE_C_HAS_OPERATOR_##WHICH)  || \
	(defined Q_COMPILER_C_HAS_OPERATOR_##WHICH)   || \
	(defined Q_COMPILER_CPP_HAS_OPERATOR_##WHICH) || \
	(defined Q_COMPILER_OBJECTIVE_C_HAS_OPERATOR_##WHICH)

#endif /* __Q_inspection_language_H__ */
