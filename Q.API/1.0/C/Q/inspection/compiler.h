/* Q API - inspection/compiler.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2010-2013 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v2. */

#ifndef __Q_inspection_compiler_H__
#define __Q_inspection_compiler_H__

#if	defined(__clang__)

#	define Q_COMPILER_NAME Clang

/*#elif	defined(__llvm__)

#	define Q_COMPILER_NAME LLVM*/

#elif	defined(__GNUC__)

#	define Q_COMPILER_NAME GCC

#elif	defined(__BORLANDC__)		|| \
	defined(__CODEGEARC__)

#	define Q_COMPILER_NAME Borland C++

#elif	defined(__TURBOC__)

#	define Q_COMPILER_NAME Borland Turbo C

#elif	defined(__COMO__)

#	define Q_COMPILER_NAME Comeau C++ 

#elif	defined(__DECC)			|| \
	defined(__DECCXX)		|| \
	defined(__VAXC)			|| \
	defined(VAXC)

#	define Q_COMPILER_NAME Compaq C - C++

#elif	defined(_CRAYC)

#	define Q_COMPILER_NAME Cray C

#elif	defined(__DCC__)

#	define Q_COMPILER_NAME Diab C - C++

#elif	defined(__DMC__)		|| \
	defined(__SC__)			|| \
	defined(__ZTC__)

#	define Q_COMPILER_NAME Digital Mars

#elif	defined(__SYSC__)

#	define Q_COMPILER_NAME Dignus Systems C - C++

#elif	defined(__DJGPP__)		|| \
	defined(__GO32__)

#	define Q_COMPILER_NAME DJGPP

#elif	defined(__PATHCC__)

#	define Q_COMPILER_NAME EKOPath

#elif	defined(__ghs__)

#	define Q_COMPILER_NAME Green Hill C - C++

#elif	defined(__HP_aCC)

#	define Q_COMPILER_NAME HP aCC

#elif	defined(__HP_cc)

#	define Q_COMPILER_NAME HP ANSI C

#elif	defined(__IAR_SYSTEMS_ICC__)

#	define Q_COMPILER_NAME IAR C - C++

#elif	defined(__xlc__)		|| \
	defined(__xlC__)

#	define Q_COMPILER_NAME IBM XL C - C++

#elif	defined(__IBMC__)		|| \
	defined(__IBMCPP__)

#	if defined(__COMPILER_VER__)
#		define Q_COMPILER_NAME IBM z OS C - C++
#	else
#		define Q_COMPILER_NAME IBM XL C - C++
#	endif

#elif	defined(__IMAGECRAFT__)

#	define Q_COMPILER_NAME ImageCraft C

#elif	defined(__INTEL_COMPILER)	|| \
	defined(__ICC)			|| \
	defined(__ECC)			|| \
	defined(__ICL)

#	define Q_COMPILER_NAME Intel C - C++

#elif	defined(__KCC)

#	define Q_COMPILER_NAME KAI C++

#elif	defined(__CA__)			|| \
	defined(__KEIL__)

#	define Q_COMPILER_NAME Keil CARM

#else
#	error "Compiler not suported."
#endif

#define  Q_COMPILER_HEADER <Q/inspection/private/compiler/Q_COMPILER_NAME.h>
#include Q_COMPILER_HEADER

#define Q_COMPILER_HAS(feature)			defined(Q_COMPILER_HAS_##feature)
#define Q_COMPILER_HAS_EXTENSION(extension)	defined(Q_COMPILER_HAS_EXTENSION_##extension)
#define Q_COMPILER_HAS_TYPE(type)		defined(Q_COMPILER_TYPE_##type)
#define Q_COMPILER_HAS_FUNCTION(function)	defined(Q_COMPILER_FUNCTION_##function)

#define Q_COMPILER_TYPE(type)			Q_COMPILER_TYPE_##type
#define Q_COMPILER_FUNCTION(function)		Q_COMPILER_FUNCTION_##function

#if	Q_COMPILER_HAS_TYPE(VAL)		&& \
	Q_COMPILER_HAS_FUNCTION(VAL_INITIALIZE) && \
	Q_COMPILER_HAS_FUNCTION(VAL_FINALIZE)	&& \
	Q_COMPILER_HAS_FUNCTION(VAL_READ)	&& \
	Q_COMPILER_HAS_FUNCTION(VAL_COPY)

#	define Q_COMPILER_HAS_VAL
#endif

#endif /* __Q_inspection_compiler_H__ */
