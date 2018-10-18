/* Z Kit - inspection/compiler.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_inspection_compiler_H_
#define _Z_inspection_compiler_H_

#include <Z/constants/base.h>
#include <Z/keys/compiler.h>

#if defined(__clang__)
#	if defined(__apple_build_version__)
#		include <Z/inspection/compiler/modules/Apple LLVM.h>
#	else
#		include <Z/inspection/compiler/modules/Clang.h>
#	endif

#elif defined(_ACC_)
#	include <Z/inspection/compiler/modules/ACC.h>

#elif defined(__CMB__)
#	include <Z/inspection/compiler/modules/Altium MicroBlaze C.h>

#elif defined(__CHC__)
#	include <Z/inspection/compiler/modules/Altium C-to-Hardware.h>

#elif defined(__ACK__)
#	include <Z/inspection/compiler/modules/Amsterdam Compiler Kit.h>

#elif defined(__ARMCC__)
#	include <Z/inspection/compiler/modules/ARM C - C++ Compiler.h>

#elif defined(__CC_ARM)
#	include <Z/inspection/compiler/modules/ARM Compiler.h>

#elif defined(AZTEC_C) || defined(__AZTEC_C__)
#	include <Z/inspection/compiler/modules/Aztec C.h>

#elif defined(__BORLANDC__) || defined(__CODEGEARC__)
#	include <Z/inspection/compiler/modules/Borland C++.h>

#elif defined(__CC65__)
#	include <Z/inspection/compiler/modules/cc65.h>

#elif defined(__MWERKS__) || defined(__CWCC__)
#	include <Z/inspection/compiler/modules/CodeWarrior.h>

#elif defined(__COMO__)
#	include <Z/inspection/compiler/modules/Comeau C++.h>

#elif defined(__DECC) || defined(__DECCXX) || defined(__VAXC) || defined(VAXC)
#	include <Z/inspection/compiler/modules/Compaq C - C++.h>

#elif defined(__COMPCERT__)
#	include <Z/inspection/compiler/modules/CompCert.h>

#elif defined(__convexc__)
#	include <Z/inspection/compiler/modules/Convex C.h>

#elif defined(__COVERITY__)
#	include <Z/inspection/compiler/modules/Coverity C - C++ Static Analyzer.h>

#elif defined(_CRAYC)
#	include <Z/inspection/compiler/modules/Cray C.h>

#elif defined(__DCC__)
#	include <Z/inspection/compiler/modules/Diab C - C++.h>

#elif defined(_DICE)
#	include <Z/inspection/compiler/modules/DICE C.h>

#elif defined(__DMC__)
#	include <Z/inspection/compiler/modules/Digital Mars.h>

#elif defined(__SYSC__)
#	include <Z/inspection/compiler/modules/Dignus Systems C - C++.h>

#elif defined(__DJGPP__) || defined(__GO32__)
#	include <Z/inspection/compiler/modules/DJGPP.h>

#elif defined(__EDG__)
#	include <Z/inspection/compiler/modules/EDG C++ Frontend.h>

#elif defined(__PATHCC__)
#	include <Z/inspection/compiler/modules/EKOPath.h>

#elif defined(__FCC_VERSION)
#	include <Z/inspection/compiler/modules/Fujitsu C++.h>

#elif defined(__ghs__)
#	include <Z/inspection/compiler/modules/Green Hill C - C++.h>

#elif defined(__HP_aCC)
#	include <Z/inspection/compiler/modules/HP aC++.h>

#elif defined(__HP_cc)
#	include <Z/inspection/compiler/modules/HP ANSI C.h>

#elif defined(__HP_aCC)
#	include <Z/inspection/compiler/modules/HP aC++.h>

#elif defined(__IAR_SYSTEMS_ICC__)
#	include <Z/inspection/compiler/modules/IAR C - C++.h>

#elif defined(__xlc__) || defined(__xlC__)
#	include <Z/inspection/compiler/modules/IBM XL C - C++.h>

#elif defined(__IBMC__) || defined(__IBMCPP__)
#	if defined(__COMPILER_VER__)
#		include <Z/inspection/compiler/modules/IBM z OS C - C++.h>
#	else
#		include <Z/inspection/compiler/modules/IBM XL C - C++.h>
#	endif

#elif defined(__IMAGECRAFT__)
#	include <Z/inspection/compiler/modules/ImageCraft C.h>

#elif defined(__INTEL_COMPILER)	|| defined(__ICC) || defined(__ECC) || defined(__ICL)
#	include <Z/inspection/compiler/modules/Intel C++.h>

#elif defined(__KCC)
#	include <Z/inspection/compiler/modules/KAI C++.h>

#elif defined(__C166__)
#	include <Z/inspection/compiler/modules/KEIL C166.h>

#elif defined(__C51__) || defined(__CX51__)
#	include <Z/inspection/compiler/modules/KEIL C51.h>

#elif defined(__CA__) || defined(__KEIL__)
#	include <Z/inspection/compiler/modules/KEIL CARM.h>

#elif defined(__LCC__)
#	include <Z/inspection/compiler/modules/LCC.h>

#elif defined(__HIGHC__)
#	include <Z/inspection/compiler/modules/MetaWare High C - C++.h>

#elif defined(_MRI)
#	include <Z/inspection/compiler/modules/Microtec C - C++.h>

#elif defined(__NDPC__) || defined(__NDPX__)
#	include <Z/inspection/compiler/modules/Microway NDP C.h>

#elif defined(__MINGW__) || defined(__MINGW32__) || defined(__MINGW64__)
#	include <Z/inspection/compiler/modules/MinGW.h>

#elif defined(__sgi) || defined(sgi)
#	include <Z/inspection/compiler/modules/MIPSpro.h>

#elif defined(MIRACLE)
#	include <Z/inspection/compiler/modules/Miracle C.h>

#elif defined(__MRC__) || defined(MPW_C) || defined(MPW_CPLUS)
#	include <Z/inspection/compiler/modules/MPW C++.h>

#elif defined(__CC_NORCROFT)
#	include <Z/inspection/compiler/modules/Norcroft C.h>

#elif defined(__NWCC__)
#	include <Z/inspection/compiler/modules/NWCC.h>

#elif defined(__OPEN64__) || defined(__OPENCC__)
#	include <Z/inspection/compiler/modules/Open64.h>

#elif defined(ORA_PROC)
#	include <Z/inspection/compiler/modules/Oracle Pro C Precompiler.h>

#elif defined(__SUNPRO_C) || defined(__SUNPRO_CC)
#	include <Z/inspection/compiler/modules/Oracle Solaris Studio.h>

#elif defined(__PACIFIC__)
#	include <Z/inspection/compiler/modules/Pacific C.h>

#elif defined(_PACC_VER)
#	include <Z/inspection/compiler/modules/Palm C - C++.h>

#elif defined(__POCC__)
#	include <Z/inspection/compiler/modules/Pelles C.h>

#elif defined(__PGI)
#	include <Z/inspection/compiler/modules/PGI C - C++.h>

#elif defined(__RENESAS__) || defined(__HITACHI__)
#	include <Z/inspection/compiler/modules/Renesas C - C++.h>

#elif defined(SASC) || defined(__SASC) || defined(__SASC__)
#	include <Z/inspection/compiler/modules/SAS - C.h>

#elif defined(__SCCZ80)
#	include <Z/inspection/compiler/modules/SCCZ80.h>

#elif defined(_SCO_DS)
#	include <Z/inspection/compiler/modules/SCO OpenServer.h>

#elif defined(__SDCC) /* Z88DK version? */ /* || defined(SDCC) */
#	include <Z/inspection/compiler/modules/SDCC.h>

#elif defined(__SNC__)
#	include <Z/inspection/compiler/modules/SN Compiler.h>

#elif defined(__VOSC__) && !__VOSC__
#	include <Z/inspection/compiler/modules/Stratus VOS C.h>

#elif defined(__VOSC__) && __VOSC__ == 1
#	include <Z/inspection/compiler/modules/Stratus VOS Standard C.h>

#elif defined(__SC__)
#	include <Z/inspection/compiler/modules/Symantec C++.h>

#elif defined(__TenDRA__)
#	include <Z/inspection/compiler/modules/TenDRA C - C++.h>

#elif defined(__TI_COMPILER_VERSION__) || defined(_TMS320C6X)
#	include <Z/inspection/compiler/modules/Texas Instruments C - C++ Compiler.h>

/*#elif defined()
#	define Z_COMPILER_NAME THINK C*/

#elif defined(__TINYC__)
#	include <Z/inspection/compiler/modules/Tiny C.h>

#elif defined(__TURBOC__)
#	include <Z/inspection/compiler/modules/Turbo C - C++.h>

#elif defined(_UCC)
#	include <Z/inspection/compiler/modules/Ultimate C - C++.h>

#elif defined(__USLC__)
#	include <Z/inspection/compiler/modules/USL C.h>

#elif defined(__VBCC__)
#	include <Z/inspection/compiler/modules/VBCC.h>

#elif defined(_MSC_VER)
#	include <Z/inspection/compiler/modules/Visual C++.h>

#elif defined(__WATCOMC__)
#	include <Z/inspection/compiler/modules/Watcom C - C++.h>

#elif defined(__ZTC__)
#	include <Z/inspection/compiler/modules/Zortech C++.h>

#elif defined(__GNUC__)
#	include <Z/inspection/compiler/modules/GCC.h>

#else
#	include <Z/inspection/compiler/modules/generic.h>
#endif

#include <Z/inspection/compiler/completion.h>

#define Z_COMPILER_C_HAS(			  WHAT ) Z_COMPILER_C_HAS_##WHAT
#define Z_COMPILER_C_HAS_ATTRIBUTE(		  WHICH) Z_COMPILER_C_HAS_ATTRIBUTE_##WHICH
#define Z_COMPILER_C_HAS_LITERAL(		  WHICH) Z_COMPILER_C_HAS_LITERAL_##WHICH
#define Z_COMPILER_C_HAS_OPERATOR(		  WHICH) Z_COMPILER_C_HAS_OPERATOR_##WHICH
#define Z_COMPILER_C_HAS_SPECIFIER(		  WHICH) Z_COMPILER_C_HAS_SPECIFIER_##WHICH
#define Z_COMPILER_C_HAS_STORAGE_CLASS(		  WHICH) Z_COMPILER_C_HAS_STORAGE_CLASS_##WHICH
#define Z_COMPILER_C_HAS_TYPE(			  WHICH) Z_COMPILER_C_HAS_TYPE_##WHICH
#define Z_COMPILER_C_HAS_TYPE_QUALIFIER(	  WHICH) Z_COMPILER_C_HAS_TYPE_QUALIFIER_##WHICH
#define Z_COMPILER_CPP_HAS(			  WHAT ) Z_COMPILER_CPP_HAS_##WHAT
#define Z_COMPILER_CPP_HAS_ATTRIBUTE(		  WHICH) Z_COMPILER_CPP_HAS_ATTRIBUTE_##WHICH
#define Z_COMPILER_CPP_HAS_LITERAL(		  WHICH) Z_COMPILER_CPP_HAS_LITERAL_##WHICH
#define Z_COMPILER_CPP_HAS_OPERATOR(		  WHICH) Z_COMPILER_CPP_HAS_OPERATOR_##WHICH
#define Z_COMPILER_CPP_HAS_SPECIFIER(		  WHICH) Z_COMPILER_CPP_HAS_SPECIFIER_##WHICH
#define Z_COMPILER_CPP_HAS_STORAGE_CLASS(	  WHICH) Z_COMPILER_CPP_HAS_STORAGE_CLASS_##WHICH
#define Z_COMPILER_CPP_HAS_TYPE(		  WHICH) Z_COMPILER_CPP_HAS_TYPE_##WHICH
#define Z_COMPILER_CPP_HAS_TYPE_QUALIFIER(	  WHICH) Z_COMPILER_CPP_HAS_TYPE_QUALIFIER_##WHICH
#define Z_COMPILER_CPP_HAS_PREPROCESSOR_OPERATOR( WHICH) Z_COMPILER_CPP_HAS_PREPROCESSOR_OPERATOR_##WHICH
#define Z_COMPILER_OBJECTIVE_C_HAS(		  WHAT ) Z_COMPILER_OBJECTIVE_C_HAS_##WHAT
#define Z_COMPILER_OBJECTIVE_C_HAS_ATTRIBUTE(	  WHICH) Z_COMPILER_OBJECTIVE_C_HAS_ATTRIBUTE_##WHICH
#define Z_COMPILER_OBJECTIVE_C_HAS_LITERAL(	  WHICH) Z_COMPILER_OBJECTIVE_C_HAS_LITERAL_##WHICH
#define Z_COMPILER_OBJECTIVE_C_HAS_OPERATOR(	  WHICH) Z_COMPILER_OBJECTIVE_C_HAS_OPERATOR_##WHICH
#define Z_COMPILER_OBJECTIVE_C_HAS_SPECIFIER(	  WHICH) Z_COMPILER_OBJECTIVE_C_HAS_SPECIFIER_##WHICH
#define Z_COMPILER_OBJECTIVE_C_HAS_STORAGE_CLASS( WHICH) Z_COMPILER_OBJECTIVE_C_HAS_STORAGE_CLASS_##WHICH
#define Z_COMPILER_OBJECTIVE_C_HAS_TYPE(	  WHICH) Z_COMPILER_OBJECTIVE_C_HAS_TYPE_##WHICH
#define Z_COMPILER_OBJECTIVE_C_HAS_TYPE_QUALIFIER(WHICH) Z_COMPILER_OBJECTIVE_C_HAS_TYPE_QUALIFIER_##WHICH
#define Z_COMPILER_HAS(				  WHAT ) Z_COMPILER_HAS_##WHAT
#define Z_COMPILER_HAS_ATTRIBUTE(		  WHICH) Z_COMPILER_HAS_ATTRIBUTE_##WHICH
#define Z_COMPILER_HAS_CONSTANT(		  WHICH) Z_COMPILER_HAS_CONSTANT_##WHICH
#define Z_COMPILER_HAS_FUNCTION(		  WHICH) Z_COMPILER_HAS_FUNCTION_##WHICH
#define Z_COMPILER_HAS_LITERAL(			  WHICH) Z_COMPILER_HAS_LITERAL_##WHICH
#define Z_COMPILER_HAS_MACRO(			  WHICH) Z_COMPILER_HAS_MACRO_##WHICH
#define Z_COMPILER_HAS_MAGIC_CONSTANT(		  WHICH) Z_COMPILER_HAS_MAGIC_CONSTANT_##WHICH
#define Z_COMPILER_HAS_TRAIT(			  WHICH) Z_COMPILER_HAS_TRAIT_##WHICH
#define Z_COMPILER_HAS_TYPE(			  WHICH) Z_COMPILER_HAS_TYPE_##WHICH
#define Z_COMPILER_ATTRIBUTE(			  WHICH) Z_COMPILER_ATTRIBUTE_##WHICH
#define Z_COMPILER_CONSTANT(			  WHICH) Z_COMPILER_CONSTANT_##WHICH
#define Z_COMPILER_FUNCTION(			  WHICH) Z_COMPILER_FUNCTION_##WHICH
#define Z_COMPILER_LITERAL(			  WHICH) Z_COMPILER_LITERAL_##WHICH
#define Z_COMPILER_MAGIC_CONSTANT(		  WHICH) Z_COMPILER_MAGIC_CONSTANT_##WHICH
#define Z_COMPILER_MACRO(			  WHICH) Z_COMPILER_MACRO_##WHICH
#define Z_COMPILER_TRAIT(			  WHICH) Z_COMPILER_TRAIT_##WHICH
#define Z_COMPILER_TYPE(			  WHICH) Z_COMPILER_TYPE_##WHICH

#endif /* _Z_inspection_compiler_H_ */
