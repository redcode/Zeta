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

#	define Q_COMPILER_FILE Clang

#elif defined(__GNUC__)

#	define Q_COMPILER_FILE GCC

#elif defined(_MSC_VER)

#	define Q_COMPILER_FILE Microsoft Visual C++

#elif defined(_ACC_)

#	define Q_COMPILER_FILE ACC

#elif defined(__CMB__)

#	define Q_COMPILER_FILE Altium MicroBlaze C

#elif defined(__CHC__)

#	define Q_COMPILER_FILE Altium C-to-Hardware

#elif defined(__ACK__)

#	define Q_COMPILER_FILE Amsterdam Compiler Kit

#elif defined(__CC_ARM)

#	define Q_COMPILER_FILE ARM Compiler

#elif defined(AZTEC_C) || defined(__AZTEC_C__)

#	define Q_COMPILER_FILE Aztec C

#elif defined(__BORLANDC__) || defined(__CODEGEARC__)

#	define Q_COMPILER_FILE Borland C++

#elif defined(__CC65__)

#	define Q_COMPILER_FILE CC65

#elif defined(__COMO__)

#	define Q_COMPILER_FILE Comeau C++ 

#elif defined(__DECC) || defined(__DECCXX) || defined(__VAXC) || defined(VAXC)

#	define Q_COMPILER_FILE Compaq C - C++

#elif defined(__convexc__)

#	define Q_COMPILER_FILE Convex C

#elif defined(_CRAYC)

#	define Q_COMPILER_FILE Cray C

#elif defined(__DCC__)

#	define Q_COMPILER_FILE Diab C - C++

#elif defined(_DICE)

#	define Q_COMPILER_FILE DICE C

#elif defined(__DMC__)

#	define Q_COMPILER_FILE Digital Mars

#elif defined(__SYSC__)

#	define Q_COMPILER_FILE Dignus Systems - C++

#elif defined(__DJGPP__) || defined(__GO32__)

#	define Q_COMPILER_FILE DJGPP

#elif defined(__EDG__)

#	define Q_COMPILER_FILE EDG C++ Frontend

#elif defined(__PATHCC__)

#	define Q_COMPILER_FILE EKOPath

#elif defined(__FCC_VERSION)

#	define Q_COMPILER_FILE Fujitsu C++

#elif defined(__ghs__)

#	define Q_COMPILER_FILE Green Hill C - C++

#elif defined(__HP_aCC)

#	define Q_COMPILER_FILE HP aC++

#elif defined(__HP_cc)

#	define Q_COMPILER_FILE HP ANSI C

#elif defined(__IAR_SYSTEMS_ICC__)

#	define Q_COMPILER_FILE IAR C - C++

#elif defined(__xlc__) || defined(__xlC__)

#	define Q_COMPILER_FILE IBM XL C - C++

#elif defined(__IBMC__) || defined(__IBMCPP__)

#	if defined(__COMPILER_VER__)
#		define Q_COMPILER_FILE IBM z OS C - C++
#	else
#		define Q_COMPILER_FILE IBM XL C - C++
#	endif

#elif defined(__IMAGECRAFT__)

#	define Q_COMPILER_FILE ImageCraft C

#elif defined(__INTEL_COMPILER)	|| defined(__ICC) || defined(__ECC) || defined(__ICL)

#	define Q_COMPILER_FILE Intel C - C++

#elif defined(__KCC)

#	define Q_COMPILER_FILE KAI C++

#elif defined(__C166__)

#	define Q_COMPILER_FILE KEIL C166

#elif defined(__C51__) || defined(__CX51__)

#	define Q_COMPILER_FILE KEIL C51

#elif defined(__CA__) || defined(__KEIL__)

#	define Q_COMPILER_FILE KEIL CARM

#elif defined(__LCC__)

#	define Q_COMPILER_FILE LCC

#elif defined(__HIGHC__)

#	define Q_COMPILER_FILE MetaWare High C - C++

#elif defined(__MWERKS__) || defined(__CWCC__)

#	define Q_COMPILER_FILE Metrowerks CodeWarrior

#elif defined(_MRI)

#	define Q_COMPILER_FILE Microtec C - C++

#elif defined(__NDPC__) || defined(__NDPX__)

#	define Q_COMPILER_FILE Microway NDP C

#elif defined(__MINGW32__) || defined(__MINGW64__)

#	define Q_COMPILER_FILE MinGW

#elif defined(__sgi) || defined(sgi)

#	define Q_COMPILER_FILE MIPSpro

#elif defined(MIRACLE)

#	define Q_COMPILER_FILE Miracle C

#elif defined(__MRC__) || defined(MPW_C) || defined(MPW_CPLUS)

#	define Q_COMPILER_FILE MPW C++

#elif defined(__CC_NORCROFT)

#	define Q_COMPILER_FILE Norcroft C

#elif defined(__NWCC__)

#	define Q_COMPILER_FILE NWCC

#elif defined(__OPEN64__) || defined(__OPENCC__)

#	define Q_COMPILER_FILE Open64

#elif defined(ORA_PROC)

#	define Q_COMPILER_FILE Oracle Pro C Precompiler

#elif defined(__SUNPRO_C) || defined(__SUNPRO_CC)

#	define Q_COMPILER_FILE Oracle Solaris Studio

#elif defined(__PACIFIC__)

#	define Q_COMPILER_FILE Pacific C

#elif defined(_PACC_VER)

#	define Q_COMPILER_FILE Palm C - C++

#elif defined(__POCC__)

#	define Q_COMPILER_FILE Pelles C

#elif defined(__PGI)

#	define Q_COMPILER_FILE Portland Group C - C++

#elif defined(__RENESAS__) || defined(__HITACHI__)

#	define Q_COMPILER_FILE Renesas C - C++

#elif defined(SASC) || defined(__SASC) || defined(__SASC__)

#	define Q_COMPILER_FILE SAS - C

#elif defined(_SCO_DS)

#	define Q_COMPILER_FILE SCO OpenServer

#elif defined(SDCC)

#	define Q_COMPILER_FILE Small Device C Compiler

#elif defined(__SNC__)

#	define Q_COMPILER_FILE SN Compiler

#elif defined(__VOSC__)

#	define Q_COMPILER_FILE Stratus VOS C

#elif defined(__SC__)

#	define Q_COMPILER_FILE Symantec C++

#elif defined(__TenDRA__)

#	define Q_COMPILER_FILE TenDRA C - C++

#elif defined(__TI_COMPILER_VERSION__)

#	define Q_COMPILER_FILE Texas Instruments C - C++ Compiler

/*#elif defined()

#	define Q_COMPILER_NAME THINK C*/

#elif defined(__TINYC__)

#	define Q_COMPILER_FILE Tiny C

#elif defined(__TURBOC__)

#	define Q_COMPILER_FILE Turbo C - C++

#elif defined(_UCC)

#	define Q_COMPILER_FILE Ultimate C - C++

#elif defined(__USLC__)

#	define Q_COMPILER_FILE USL C

#elif defined(__WATCOMC__)

#	define Q_COMPILER_FILE Watcom C++

#elif defined(__ZTC__)

#	define Q_COMPILER_FILE Zortech C++

#else
#	error "Compiler not suported."
#endif

#define  Q_COMPILER_HEADER <Q/inspection/private/compiler/Q_COMPILER_FILE.h>
#include Q_COMPILER_HEADER

#define Q_COMPILER_HAS(FEATURE)			defined(Q_COMPILER_HAS_##FEATURE)
#define Q_COMPILER_HAS_EXTENSION(EXTENSION)	defined(Q_COMPILER_HAS_EXTENSION_##EXTENSION)
#define Q_COMPILER_HAS_TYPE(TYPE)		defined(Q_COMPILER_TYPE_##TYPE)
#define Q_COMPILER_HAS_FUNCTION(FUNCTION)	defined(Q_COMPILER_FUNCTION_##FUNCTION)

#define Q_COMPILER_TYPE(TYPE)			Q_COMPILER_TYPE_##TYPE
#define Q_COMPILER_FUNCTION(FUNCTION)		Q_COMPILER_FUNCTION_##FUNCTION

#if	Q_COMPILER_HAS_TYPE(VAL)		&& \
	Q_COMPILER_HAS_FUNCTION(VAL_INITIALIZE) && \
	Q_COMPILER_HAS_FUNCTION(VAL_FINALIZE)	&& \
	Q_COMPILER_HAS_FUNCTION(VAL_READ)	&& \
	Q_COMPILER_HAS_FUNCTION(VAL_COPY)

#	define Q_COMPILER_HAS_VAL
#endif

#endif /* __Q_inspection_compiler_H__ */
