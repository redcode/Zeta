/* Z Kit C API - inspection/compiler.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_inspection_compiler_H__
#define __Z_inspection_compiler_H__

#if defined(__clang__)
#	if defined(__apple_build_version__)
#		include <Z/inspection/private/compiler/Apple LLVM.h>
#	else
#		include <Z/inspection/private/compiler/Clang.h>
#	endif

#elif defined(_MSC_VER)
#	include <Z/inspection/private/compiler/Visual C++.h>

#elif defined(_ACC_)
#	include <Z/inspection/private/compiler/ACC.h>

#elif defined(__CMB__)
#	include <Z/inspection/private/compiler/Altium MicroBlaze C.h>

#elif defined(__CHC__)
#	include <Z/inspection/private/compiler/Altium C-to-Hardware.h>

#elif defined(__ACK__)
#	include <Z/inspection/private/compiler/Amsterdam Compiler Kit.h>

#elif defined(__ARMCC__)
#	include <Z/inspection/private/compiler/ARM C - C++ Compiler.h>

#elif defined(__CC_ARM)
#	include <Z/inspection/private/compiler/ARM Compiler.h>

#elif defined(AZTEC_C) || defined(__AZTEC_C__)
#	include <Z/inspection/private/compiler/Aztec C.h>

#elif defined(__BORLANDC__) || defined(__CODEGEARC__)
#	include <Z/inspection/private/compiler/Borland C++.h>

#elif defined(__CC65__)
#	include <Z/inspection/private/compiler/CC65.h>

#elif defined(__MWERKS__) || defined(__CWCC__)
#	include <Z/inspection/private/compiler/CodeWarrior.h>

#elif defined(__COMO__)
#	include <Z/inspection/private/compiler/Comeau C++.h>

#elif defined(__DECC) || defined(__DECCXX) || defined(__VAXC) || defined(VAXC)
#	include <Z/inspection/private/compiler/Compaq C - C++.h>

#elif defined(__COMPCERT__)
#	include <Z/inspection/private/compiler/CompCert.h>

#elif defined(__convexc__)
#	include <Z/inspection/private/compiler/Convex C.h>

#elif defined(__COVERITY__)
#	include <Z/inspection/private/compiler/Coverity C - C++ Static Analyzer.h>

#elif defined(_CRAYC)
#	include <Z/inspection/private/compiler/Cray C.h>

#elif defined(__DCC__)
#	include <Z/inspection/private/compiler/Diab C - C++.h>

#elif defined(_DICE)
#	include <Z/inspection/private/compiler/DICE C.h>

#elif defined(__DMC__)
#	include <Z/inspection/private/compiler/Digital Mars.h>

#elif defined(__SYSC__)
#	include <Z/inspection/private/compiler/Dignus Systems C - C++.h>

#elif defined(__DJGPP__) || defined(__GO32__)
#	include <Z/inspection/private/compiler/DJGPP.h>

#elif defined(__EDG__)
#	include <Z/inspection/private/compiler/EDG C++ Frontend.h>

#elif defined(__PATHCC__)
#	include <Z/inspection/private/compiler/EKOPath.h>

#elif defined(__FCC_VERSION)
#	include <Z/inspection/private/compiler/Fujitsu C++.h>

#elif defined(__ghs__)
#	include <Z/inspection/private/compiler/Green Hill C - C++.h>

#elif defined(__HP_aCC)
#	include <Z/inspection/private/compiler/HP aC++.h>

#elif defined(__HP_cc)
#	include <Z/inspection/private/compiler/HP ANSI C.h>

#elif defined(__HP_aCC)
#	include <Z/inspection/private/compiler/HP aC++.h>

#elif defined(__IAR_SYSTEMS_ICC__)
#	include <Z/inspection/private/compiler/IAR C - C++.h>

#elif defined(__xlc__) || defined(__xlC__)
#	include <Z/inspection/private/compiler/IBM XL C - C++.h>

#elif defined(__IBMC__) || defined(__IBMCPP__)
#	if defined(__COMPILER_VER__)
#		include <Z/inspection/private/compiler/IBM z OS C - C++.h>
#	else
#		include <Z/inspection/private/compiler/IBM XL C - C++.h>
#	endif

#elif defined(__IMAGECRAFT__)
#	include <Z/inspection/private/compiler/ImageCraft C.h>

#elif defined(__INTEL_COMPILER)	|| defined(__ICC) || defined(__ECC) || defined(__ICL)
#	include <Z/inspection/private/compiler/Intel C++.h>

#elif defined(__KCC)
#	include <Z/inspection/private/compiler/KAI C++.h>

#elif defined(__C166__)
#	include <Z/inspection/private/compiler/KEIL C166.h>

#elif defined(__C51__) || defined(__CX51__)
#	include <Z/inspection/private/compiler/KEIL C51.h>

#elif defined(__CA__) || defined(__KEIL__)
#	include <Z/inspection/private/compiler/KEIL CARM.h>

#elif defined(__LCC__)
#	include <Z/inspection/private/compiler/LCC.h>

#elif defined(__HIGHC__)
#	include <Z/inspection/private/compiler/MetaWare High C - C++.h>

#elif defined(_MRI)
#	include <Z/inspection/private/compiler/Microtec C - C++.h>

#elif defined(__NDPC__) || defined(__NDPX__)
#	include <Z/inspection/private/compiler/Microway NDP C.h>

#elif defined(__MINGW32__) || defined(__MINGW64__)
#	include <Z/inspection/private/compiler/MinGW.h>

#elif defined(__sgi) || defined(sgi)
#	include <Z/inspection/private/compiler/MIPSpro.h>

#elif defined(MIRACLE)
#	include <Z/inspection/private/compiler/Miracle C.h>

#elif defined(__MRC__) || defined(MPW_C) || defined(MPW_CPLUS)
#	include <Z/inspection/private/compiler/MPW C++.h>

#elif defined(__CC_NORCROFT)
#	include <Z/inspection/private/compiler/Norcroft C.h>

#elif defined(__NWCC__)
#	include <Z/inspection/private/compiler/NWCC.h>

#elif defined(__OPEN64__) || defined(__OPENCC__)
#	include <Z/inspection/private/compiler/Open64.h>

#elif defined(ORA_PROC)
#	include <Z/inspection/private/compiler/Oracle Pro C Precompiler.h>

#elif defined(__SUNPRO_C) || defined(__SUNPRO_CC)
#	include <Z/inspection/private/compiler/Oracle Solaris Studio.h>

#elif defined(__PACIFIC__)
#	include <Z/inspection/private/compiler/Pacific C.h>

#elif defined(_PACC_VER)
#	include <Z/inspection/private/compiler/Palm C - C++.h>

#elif defined(__POCC__)
#	include <Z/inspection/private/compiler/Pelles C.h>

#elif defined(__PGI)
#	include <Z/inspection/private/compiler/PGI C - C++.h>

#elif defined(__RENESAS__) || defined(__HITACHI__)
#	include <Z/inspection/private/compiler/Renesas C - C++.h>

#elif defined(SASC) || defined(__SASC) || defined(__SASC__)
#	include <Z/inspection/private/compiler/SAS - C.h>

#elif defined(_SCO_DS)
#	include <Z/inspection/private/compiler/SCO OpenServer.h>

#elif defined(SDCC)
#	include <Z/inspection/private/compiler/Small Device C Compiler.h>

#elif defined(__SNC__)
#	include <Z/inspection/private/compiler/SN Compiler.h>

#elif defined(__VOSC__)
#	include <Z/inspection/private/compiler/Stratus VOS C.h>

#elif defined(__SC__)
#	include <Z/inspection/private/compiler/Symantec C++.h>

#elif defined(__TenDRA__)
#	include <Z/inspection/private/compiler/TenDRA C - C++.h>

#elif defined(__TI_COMPILER_VERSION__) || defined(_TMS320C6X)
#	include <Z/inspection/private/compiler/Texas Instruments C - C++ Compiler.h>

/*#elif defined()
#	define Z_COMPILER_NAME THINK C*/

#elif defined(__TINYC__)
#	include <Z/inspection/private/compiler/Tiny C.h>

#elif defined(__TURBOC__)
#	include <Z/inspection/private/compiler/Turbo C - C++.h>

#elif defined(_UCC)
#	include <Z/inspection/private/compiler/Ultimate C - C++.h>

#elif defined(__USLC__)
#	include <Z/inspection/private/compiler/USL C.h>

#elif defined(__VBCC__)
#	include <Z/inspection/private/compiler/VBCC.h>

#elif defined(__WATCOMC__)
#	include <Z/inspection/private/compiler/Watcom C - C++.h>

#elif defined(__ZTC__)
#	include <Z/inspection/private/compiler/Zortech C++.h>

#elif defined(__GNUC__)
#	include <Z/inspection/private/compiler/GCC.h>

#else
#	include <Z/inspection/private/compiler/generic.h>
#endif

#define Z_COMPILER_C_HAS(		WHAT ) (defined Z_COMPILER_C_HAS_##WHAT		       )
#define Z_COMPILER_C_HAS_TYPE(		WHICH) (defined Z_COMPILER_C_HAS_TYPE_##WHICH	       )
#define Z_COMPILER_C_HAS_TYPE_QUALIFIER(WHICH) (defined Z_COMPILER_C_HAS_TYPE_QUALIFIER_##WHICH)
#define Z_COMPILER_C_HAS_STORAGE_CLASS(	WHICH) (defined Z_COMPILER_C_HAS_STORAGE_CLASS_##WHICH )
#define Z_COMPILER_C_HAS_SPECIFIER(	WHICH) (defined Z_COMPILER_C_HAS_SPECIFIER_##WHICH     )
#define Z_COMPILER_C_HAS_OPERATOR(	WHICH) (defined Z_COMPILER_C_HAS_OPERATOR_##WHICH      )

#define Z_COMPILER_CPP_HAS(		  WHAT ) (defined Z_COMPILER_CPP_HAS_##WHAT		   )
#define Z_COMPILER_CPP_HAS_TYPE(	  WHICH) (defined Z_COMPILER_CPP_HAS_TYPE_##WHICH	   )
#define Z_COMPILER_CPP_HAS_TYPE_QUALIFIER(WHICH) (defined Z_COMPILER_CPP_HAS_TYPE_QUALIFIER_##WHICH)
#define Z_COMPILER_CPP_HAS_STORAGE_CLASS( WHICH) (defined Z_COMPILER_CPP_HAS_STORAGE_CLASS_##WHICH )
#define Z_COMPILER_CPP_HAS_SPECIFIER(	  WHICH) (defined Z_COMPILER_CPP_HAS_SPECIFIER_##WHICH     )
#define Z_COMPILER_CPP_HAS_OPERATOR(	  WHICH) (defined Z_COMPILER_CPP_HAS_OPERATOR_##WHICH	   )

#define Z_COMPILER_OBJECTIVE_C_HAS(		  WHAT ) (defined Z_COMPILER_C_HAS_##WHAT		 )
#define Z_COMPILER_OBJECTIVE_C_HAS_TYPE(	  WHICH) (defined Z_COMPILER_C_HAS_TYPE_##WHICH		 )
#define Z_COMPILER_OBJECTIVE_C_HAS_TYPE_QUALIFIER(WHICH) (defined Z_COMPILER_C_HAS_TYPE_QUALIFIER_##WHICH)
#define Z_COMPILER_OBJECTIVE_C_HAS_STORAGE_CLASS( WHICH) (defined Z_COMPILER_C_HAS_STORAGE_CLASS_##WHICH )
#define Z_COMPILER_OBJECTIVE_C_HAS_SPECIFIER(	  WHICH) (defined Z_COMPILER_C_HAS_SPECIFIER_##WHICH	 )
#define Z_COMPILER_OBJECTIVE_C_HAS_OPERATOR(	  WHICH) (defined Z_COMPILER_C_HAS_OPERATOR_##WHICH	 )

#define Z_COMPILER_HAS(			     WHAT ) (defined Z_COMPILER_HAS_##WHAT		     )
#define Z_COMPILER_HAS_C_ATTRIBUTE(	     WHICH) (defined Z_COMPILER_C_ATTRIBUTE_##WHICH	     )
#define Z_COMPILER_HAS_CPP_ATTRIBUTE(	     WHICH) (defined Z_COMPILER_CPP_ATTRIBUTE_##WHICH	     )
#define Z_COMPILER_HAS_OBJECTIVE_C_ATTRIBUTE(WHICH) (defined Z_COMPILER_OBJECTIVE_C_ATTRIBUTE_##WHICH)
#define Z_COMPILER_HAS_CONSTANT(	     WHICH) (defined Z_COMPILER_CONSTANT_##WHICH	     )
#define Z_COMPILER_HAS_LITERAL(		     WHICH) (defined Z_COMPILER_LITERAL_##WHICH		     )
#define Z_COMPILER_HAS_SUFFIX(		     WHICH) (defined Z_COMPILER_SUFFIX_##WHICH		     )
#define Z_COMPILER_HAS_MACRO(		     WHICH) (defined Z_COMPILER_MACRO_##WHICH		     )
#define Z_COMPILER_HAS_FUNCTION(	     WHICH) (defined Z_COMPILER_FUNCTION_##WHICH	     )

#define Z_COMPILER_HAS_TYPE(WHICH)							    \
	(!(defined Z_COMPILER_LACKS_TYPE_##WHICH) &&					    \
	 ((defined Z_COMPILER_TYPE_##WHICH) || (defined Z_COMPILER_CPP_HAS_TYPE_##WHICH) || \
	  (defined Z_COMPILER_C_HAS_TYPE_##WHICH) || (defined Z_OBJECTIVE_C_HAS_TYPE_##WHICH)))

#define Z_COMPILER_C_ATTRIBUTE(		 WHICH) Z_COMPILER_C_ATTRIBUTE_##WHICH
#define Z_COMPILER_CPP_ATTRIBUTE(	 WHICH) Z_COMPILER_CPP_ATTRIBUTE_##WHICH
#define Z_COMPILER_OBJECTIVE_C_ATTRIBUTE(WHICH) Z_COMPILER_OBJECTIVE_C_ATTRIBUTE_##WHICH
#define Z_COMPILER_CONSTANT(		 WHICH) Z_COMPILER_CONSTANT_##WHICH
#define Z_COMPILER_TYPE(		 WHICH) Z_COMPILER_TYPE_##WHICH
#define Z_COMPILER_LITERAL(		 WHICH) Z_COMPILER_LITERAL_##WHICH
#define Z_COMPILER_SUFFIX(		 WHICH) Z_COMPILER_SUFFIX_##WHICH
#define Z_COMPILER_MACRO(		 WHICH) Z_COMPILER_MACRO_##WHICH
#define Z_COMPILER_FUNCTION(		 WHICH) Z_COMPILER_FUNCTION_##WHICH

#if	Z_COMPILER_HAS_TYPE(VAL)		&& \
	Z_COMPILER_HAS_FUNCTION(VAL_INITIALIZE) && \
	Z_COMPILER_HAS_FUNCTION(VAL_FINALIZE)	&& \
	Z_COMPILER_HAS_FUNCTION(VAL_READ)

#	define Z_COMPILER_HAS_VAL
#endif

#endif /* __Z_inspection_compiler_H__ */
