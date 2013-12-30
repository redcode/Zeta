/* Q API - inspection/compiler.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2014 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_inspection_compiler_H__
#define __Q_inspection_compiler_H__

#if defined(__clang__)

#	define Q_COMPILER_NAME Clang

#elif defined(__GNUC__)

#	define Q_COMPILER_NAME GCC

#elif defined(_MSC_VER)

#	define Q_COMPILER_NAME Microsoft Visual C++

#elif defined(_ACC_)

#	define Q_COMPILER_NAME ACC

#elif defined(__CMB__)

#	define Q_COMPILER_NAME Altium MicroBlaze C

#elif defined(__CHC__)

#	define Q_COMPILER_NAME Altium C-to-Hardware

#elif defined(__ACK__)

#	define Q_COMPILER_NAME Amsterdam Compiler Kit

#elif defined(__CC_ARM)

#	define Q_COMPILER_NAME ARM Compiler

#elif defined(AZTEC_C) || defined(__AZTEC_C__)

#	define Q_COMPILER_NAME Aztec C

#elif defined(__BORLANDC__) || defined(__CODEGEARC__)

#	define Q_COMPILER_NAME Borland C++

#elif defined(__CC65__)

#	define Q_COMPILER_NAME CC65

#elif defined(__COMO__)

#	define Q_COMPILER_NAME Comeau C++ 

#elif defined(__DECC) || defined(__DECCXX) || defined(__VAXC) || defined(VAXC)

#	define Q_COMPILER_NAME Compaq C - C++

#elif defined(__convexc__)

#	define Q_COMPILER_NAME Convex C

#elif defined(_CRAYC)

#	define Q_COMPILER_NAME Cray C

#elif defined(__DCC__)

#	define Q_COMPILER_NAME Diab C - C++

#elif defined(_DICE)

#	define Q_COMPILER_NAME DICE C

#elif defined(__DMC__)

#	define Q_COMPILER_NAME Digital Mars

#elif defined(__SYSC__)

#	define Q_COMPILER_NAME Dignus Systems - C++

#elif defined(__DJGPP__) || defined(__GO32__)

#	define Q_COMPILER_NAME DJGPP

#elif defined(__EDG__)

#	define Q_COMPILER_NAME EDG C++ Frontend

#elif defined(__PATHCC__)

#	define Q_COMPILER_NAME EKOPath

#elif defined(__FCC_VERSION)

#	define Q_COMPILER_NAME Fujitsu C++

#elif defined(__ghs__)

#	define Q_COMPILER_NAME Green Hill C - C++

#elif defined(__HP_aCC)

#	define Q_COMPILER_NAME HP aC++

#elif defined(__HP_cc)

#	define Q_COMPILER_NAME HP ANSI C

#elif defined(__IAR_SYSTEMS_ICC__)

#	define Q_COMPILER_NAME IAR C - C++

#elif defined(__xlc__) || defined(__xlC__)

#	define Q_COMPILER_NAME IBM XL C - C++

#elif defined(__IBMC__) || defined(__IBMCPP__)

#	if defined(__COMPILER_VER__)
#		define Q_COMPILER_NAME IBM z OS C - C++
#	else
#		define Q_COMPILER_NAME IBM XL C - C++
#	endif

#elif defined(__IMAGECRAFT__)

#	define Q_COMPILER_NAME ImageCraft C

#elif defined(__INTEL_COMPILER)	|| defined(__ICC) || defined(__ECC) || defined(__ICL)

#	define Q_COMPILER_NAME Intel C - C++

#elif defined(__KCC)

#	define Q_COMPILER_NAME KAI C++

#elif defined(__C166__)

#	define Q_COMPILER_NAME KEIL C166

#elif defined(__C51__) || defined(__CX51__)

#	define Q_COMPILER_NAME KEIL C51

#elif defined(__CA__) || defined(__KEIL__)

#	define Q_COMPILER_NAME KEIL CARM

#elif defined(__LCC__)

#	define Q_COMPILER_NAME LCC

#elif defined(__HIGHC__)

#	define Q_COMPILER_NAME MetaWare High C - C++

#elif defined(__MWERKS__) || defined(__CWCC__)

#	define Q_COMPILER_NAME Metrowerks CodeWarrior

#elif defined(_MRI)

#	define Q_COMPILER_NAME Microtec C - C++

#elif defined(__NDPC__) || defined(__NDPX__)

#	define Q_COMPILER_NAME Microway NDP C

#elif defined(__MINGW32__) || defined(__MINGW64__)

#	define Q_COMPILER_NAME MinGW

#elif defined(__sgi) || defined(sgi)

#	define Q_COMPILER_NAME MIPSpro

#elif defined(MIRACLE)

#	define Q_COMPILER_NAME Miracle C

#elif defined(__MRC__) || defined(MPW_C) || defined(MPW_CPLUS)

#	define Q_COMPILER_NAME MPW C++

#elif defined(__CC_NORCROFT)

#	define Q_COMPILER_NAME Norcroft C

#elif defined(__NWCC__)

#	define Q_COMPILER_NAME NWCC

#elif defined(__OPEN64__) || defined(__OPENCC__)

#	define Q_COMPILER_NAME Open64

#elif defined(ORA_PROC)

#	define Q_COMPILER_NAME Oracle Pro C Precompiler

#elif defined(__SUNPRO_C) || defined(__SUNPRO_CC)

#	define Q_COMPILER_NAME Oracle Solaris Studio

#elif defined(__PACIFIC__)

#	define Q_COMPILER_NAME Pacific C

#elif defined(_PACC_VER)

#	define Q_COMPILER_NAME Palm C - C++

#elif defined(__POCC__)

#	define Q_COMPILER_NAME Pelles C

#elif defined(__PGI)

#	define Q_COMPILER_NAME Portland Group C - C++

#elif defined(__RENESAS__) || defined(__HITACHI__)

#	define Q_COMPILER_NAME Renesas C - C++

#elif defined(SASC) || defined(__SASC) || defined(__SASC__)

#	define Q_COMPILER_NAME SAS - C

#elif defined(_SCO_DS)

#	define Q_COMPILER_NAME SCO OpenServer

#elif defined(SDCC)

#	define Q_COMPILER_NAME Small Device C Compiler

#elif defined(__SNC__)

#	define Q_COMPILER_NAME SN Compiler

#elif defined(__VOSC__)

#	define Q_COMPILER_NAME Stratus VOS C

#elif defined(__SC__)

#	define Q_COMPILER_NAME Symantec C++

#elif defined(__TenDRA__)

#	define Q_COMPILER_NAME TenDRA C - C++

#elif defined(__TI_COMPILER_VERSION__)

#	define Q_COMPILER_NAME Texas Instruments C - C++ Compiler

/*#elif defined()

#	define Q_COMPILER_NAME THINK C*/

#elif defined(__TINYC__)

#	define Q_COMPILER_NAME Tiny C

#elif defined(__TURBOC__)

#	define Q_COMPILER_NAME Turbo C - C++

#elif defined(_UCC)

#	define Q_COMPILER_NAME Ultimate C - C++

#elif defined(__USLC__)

#	define Q_COMPILER_NAME USL C

#elif defined(__WATCOMC__)

#	define Q_COMPILER_NAME Watcom C++

#elif defined(__ZTC__)

#	define Q_COMPILER_NAME Zortech C++

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
