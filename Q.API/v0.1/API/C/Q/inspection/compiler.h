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
#	include <Q/inspection/private/compiler/Clang.h>

#elif defined(__GNUC__)
#	include <Q/inspection/private/compiler/GCC.h>

#elif defined(_MSC_VER)
#	include <Q/inspection/private/compiler/Microsoft Visual C++.h>

#elif defined(_ACC_)
#	include <Q/inspection/private/compiler/ACC.h>

#elif defined(__CMB__)
#	include <Q/inspection/private/compiler/Altium MicroBlaze C.h>

#elif defined(__CHC__)
#	include <Q/inspection/private/compiler/Altium C-to-Hardware.h>

#elif defined(__ACK__)
#	include <Q/inspection/private/compiler/Amsterdam Compiler Kit.h>

#elif defined(__CC_ARM)
#	include <Q/inspection/private/compiler/ARM Compiler.h>

#elif defined(AZTEC_C) || defined(__AZTEC_C__)
#	include <Q/inspection/private/compiler/Aztec C.h>

#elif defined(__BORLANDC__) || defined(__CODEGEARC__)
#	include <Q/inspection/private/compiler/Borland C++.h>

#elif defined(__CC65__)
#	include <Q/inspection/private/compiler/CC65.h>

#elif defined(__COMO__)
#	include <Q/inspection/private/compiler/Comeau C++.h>

#elif defined(__DECC) || defined(__DECCXX) || defined(__VAXC) || defined(VAXC)
#	include <Q/inspection/private/compiler/Compaq C - C++.h>

#elif defined(__convexc__)
#	include <Q/inspection/private/compiler/Convex C.h>

#elif defined(_CRAYC)
#	include <Q/inspection/private/compiler/Cray C.h>

#elif defined(__DCC__)
#	include <Q/inspection/private/compiler/Diab C - C++.h>

#elif defined(_DICE)
#	include <Q/inspection/private/compiler/DICE C.h>

#elif defined(__DMC__)
#	include <Q/inspection/private/compiler/Digital Mars.h>

#elif defined(__SYSC__)
#	include <Q/inspection/private/compiler/Dignus Systems - C++.h>

#elif defined(__DJGPP__) || defined(__GO32__)
#	include <Q/inspection/private/compiler/DJGPP.h>

#elif defined(__EDG__)
#	include <Q/inspection/private/compiler/EDG C++ Frontend.h>

#elif defined(__PATHCC__)
#	include <Q/inspection/private/compiler/EKOPath.h>

#elif defined(__FCC_VERSION)
#	include <Q/inspection/private/compiler/Fujitsu C++.h>

#elif defined(__ghs__)
#	include <Q/inspection/private/compiler/Green Hill C - C++.h>

#elif defined(__HP_aCC)
#	include <Q/inspection/private/compiler/HP aC++.h>

#elif defined(__HP_cc)
#	include <Q/inspection/private/compiler/HP ANSI C.h>

#elif defined(__IAR_SYSTEMS_ICC__)
#	include <Q/inspection/private/compiler/IAR C - C++.h>

#elif defined(__xlc__) || defined(__xlC__)
#	include <Q/inspection/private/compiler/IBM XL C - C++.h>

#elif defined(__IBMC__) || defined(__IBMCPP__)
#	if defined(__COMPILER_VER__)
#		include <Q/inspection/private/compiler/IBM z OS C - C++.h>
#	else
#		include <Q/inspection/private/compiler/IBM XL C - C++.h>
#	endif

#elif defined(__IMAGECRAFT__)
#	include <Q/inspection/private/compiler/ImageCraft C.h>

#elif defined(__INTEL_COMPILER)	|| defined(__ICC) || defined(__ECC) || defined(__ICL)
#	include <Q/inspection/private/compiler/Intel C - C++.h>

#elif defined(__KCC)
#	include <Q/inspection/private/compiler/KAI C++.h>

#elif defined(__C166__)
#	include <Q/inspection/private/compiler/KEIL C166.h>

#elif defined(__C51__) || defined(__CX51__)
#	include <Q/inspection/private/compiler/KEIL C51.h>

#elif defined(__CA__) || defined(__KEIL__)
#	include <Q/inspection/private/compiler/KEIL CARM.h>

#elif defined(__LCC__)
#	include <Q/inspection/private/compiler/LCC.h>

#elif defined(__HIGHC__)
#	include <Q/inspection/private/compiler/MetaWare High C - C++.h>

#elif defined(__MWERKS__) || defined(__CWCC__)
#	include <Q/inspection/private/compiler/Metrowerks CodeWarrior.h>

#elif defined(_MRI)
#	include <Q/inspection/private/compiler/Microtec C - C++.h>

#elif defined(__NDPC__) || defined(__NDPX__)
#	include <Q/inspection/private/compiler/Microway NDP C.h>

#elif defined(__MINGW32__) || defined(__MINGW64__)
#	include <Q/inspection/private/compiler/MinGW.h>

#elif defined(__sgi) || defined(sgi)
#	include <Q/inspection/private/compiler/MIPSpro.h>

#elif defined(MIRACLE)
#	include <Q/inspection/private/compiler/Miracle C.h>

#elif defined(__MRC__) || defined(MPW_C) || defined(MPW_CPLUS)
#	include <Q/inspection/private/compiler/MPW C++.h>

#elif defined(__CC_NORCROFT)
#	include <Q/inspection/private/compiler/Norcroft C.h>

#elif defined(__NWCC__)
#	include <Q/inspection/private/compiler/NWCC.h>

#elif defined(__OPEN64__) || defined(__OPENCC__)
#	include <Q/inspection/private/compiler/Open64.h>

#elif defined(ORA_PROC)
#	include <Q/inspection/private/compiler/Oracle Pro C Precompiler.h>

#elif defined(__SUNPRO_C) || defined(__SUNPRO_CC)
#	include <Q/inspection/private/compiler/Oracle Solaris Studio.h>

#elif defined(__PACIFIC__)
#	include <Q/inspection/private/compiler/Pacific C.h>

#elif defined(_PACC_VER)
#	include <Q/inspection/private/compiler/Palm C - C++.h>

#elif defined(__POCC__)
#	include <Q/inspection/private/compiler/Pelles C.h>

#elif defined(__PGI)
#	include <Q/inspection/private/compiler/Portland Group C - C++.h>

#elif defined(__RENESAS__) || defined(__HITACHI__)
#	include <Q/inspection/private/compiler/Renesas C - C++.h>

#elif defined(SASC) || defined(__SASC) || defined(__SASC__)
#	include <Q/inspection/private/compiler/SAS - C.h>

#elif defined(_SCO_DS)
#	include <Q/inspection/private/compiler/SCO OpenServer.h>

#elif defined(SDCC)
#	include <Q/inspection/private/compiler/Small Device C Compiler.h>

#elif defined(__SNC__)
#	include <Q/inspection/private/compiler/SN Compiler.h>

#elif defined(__VOSC__)
#	include <Q/inspection/private/compiler/Stratus VOS C.h>

#elif defined(__SC__)
#	include <Q/inspection/private/compiler/Symantec C++.h>

#elif defined(__TenDRA__)
#	include <Q/inspection/private/compiler/TenDRA C - C++.h>

#elif defined(__TI_COMPILER_VERSION__)
#	include <Q/inspection/private/compiler/Texas Instruments C - C++ Compiler.h>

/*#elif defined()
#	define Q_COMPILER_NAME THINK C*/

#elif defined(__TINYC__)
#	include <Q/inspection/private/compiler/Tiny C.h>

#elif defined(__TURBOC__)
#	include <Q/inspection/private/compiler/Turbo C - C++.h>

#elif defined(_UCC)
#	include <Q/inspection/private/compiler/Ultimate C - C++.h>

#elif defined(__USLC__)
#	include <Q/inspection/private/compiler/USL C.h>

#elif defined(__WATCOMC__)
#	include <Q/inspection/private/compiler/Watcom C++.h>

#elif defined(__ZTC__)
#	include <Q/inspection/private/compiler/Zortech C++.h>

#else
#	error "Compiler not suported."
#endif

#define Q_COMPILER_HAS(		 FEATURE  ) (defined Q_COMPILER_HAS_##FEATURE)
#define Q_COMPILER_HAS_CONSTANT( CONSTANT ) (defined Q_COMPILER_CONSTANT_##CONSTANT)
#define Q_COMPILER_HAS_MACRO(	 MACRO	  ) (defined Q_COMPILER_MACRO_##MACRO)
#define Q_COMPILER_HAS_EXTENSION(EXTENSION) (defined Q_COMPILER_HAS_EXTENSION_##EXTENSION)
#define Q_COMPILER_HAS_TYPE(	 TYPE	  ) (defined Q_COMPILER_TYPE_##TYPE)
#define Q_COMPILER_HAS_FUNCTION( FUNCTION ) (defined Q_COMPILER_FUNCTION_##FUNCTION)
#define Q_COMPILER_CONSTANT(	 CONSTANT ) Q_COMPILER_CONSTANT_##CONSTANT
#define Q_COMPILER_TYPE(	 TYPE	  ) Q_COMPILER_TYPE_##TYPE
#define Q_COMPILER_FUNCTION(	 FUNCTION ) Q_COMPILER_FUNCTION_##FUNCTION

#if	Q_COMPILER_HAS_TYPE(VAL)		&& \
	Q_COMPILER_HAS_FUNCTION(VAL_INITIALIZE) && \
	Q_COMPILER_HAS_FUNCTION(VAL_FINALIZE)	&& \
	Q_COMPILER_HAS_FUNCTION(VAL_READ)	&& \
	Q_COMPILER_HAS_FUNCTION(VAL_COPY)
#	define Q_COMPILER_HAS_VAL
#endif

#endif /* __Q_inspection_compiler_H__ */
