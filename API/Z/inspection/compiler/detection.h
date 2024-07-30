/* Zeta API - Z/inspection/compiler/detection.h
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_inspection_compiler_detection_H
#define Z_inspection_compiler_detection_H

#if defined(__clang__)
/*#	if defined(__apple_build_version__)
#		define Z_COMPILER Z_COMPILER_APPLE_CLANG
#	else*/
#		define Z_COMPILER Z_COMPILER_CLANG
/*#	endif*/

#elif defined(_ACC_)
#	define Z_COMPILER Z_COMPILER_ACC

#elif defined(__ACPP__) || defined(__ADAPTIVECPP__)
#	define Z_COMPILER Z_COMPILER_ADAPTIVE_CPP

#elif defined(__CMB__)
#	define Z_COMPILER Z_COMPILER_ALTIUM_MICROBLAZE_C

#elif defined(__CHC__)
#	define Z_COMPILER Z_COMPILER_ALTIUM_C_TO_HARDWARE

#elif defined(__ACK__)
#	define Z_COMPILER Z_COMPILER_AMSTERDAM_COMPILER_KIT

#elif defined(__ARMCC__)
#	define Z_COMPILER Z_COMPILER_ARM_C_CPP_COMPILER

#elif defined(__CC_ARM)
#	define Z_COMPILER Z_COMPILER_ARM_COMPILER

#elif defined(AZTEC_C) || defined(__AZTEC_C__)
#	define Z_COMPILER Z_COMPILER_AZTEC_C

#elif defined(__BCC__)
#	define Z_COMPILER Z_COMPILER_BCC

#elif defined(__CC65__)
#	define Z_COMPILER Z_COMPILER_CC65

#elif defined(__MWERKS__) || defined(__CWCC__)
#	define Z_COMPILER Z_COMPILER_CODE_WARRIOR

#elif defined(__COMO__)
#	define Z_COMPILER Z_COMPILER_COMEAU_CPP

#elif	!defined(__COMPAQ_UPC_VER) && \
	!defined(__HP_UPC_VER	 ) && \
	(defined(__DECC) || defined(__DECCXX) || defined(__VAXC) || defined(VAXC))

#	define Z_COMPILER Z_COMPILER_COMPAQ_C_CPP

#elif defined(__COMPCERT__)
#	define Z_COMPILER Z_COMPILER_COMPCERT

#elif defined(__convexc__)
#	define Z_COMPILER Z_COMPILER_CONVEX_C

#elif defined(__COVERITY__)
#	define Z_COMPILER Z_COMPILER_COVERITY_C_CPP_STATIC_ANALYZER

#elif defined(_CRAYC)
#	define Z_COMPILER Z_COMPILER_CRAY_C

#elif defined(__DCC__)
#	define Z_COMPILER Z_COMPILER_DIAB_C_CPP

#elif defined(_DICE)
#	define Z_COMPILER Z_COMPILER_DICE_C

#elif defined(__DMC__)
#	define Z_COMPILER Z_COMPILER_DIGITAL_MARS

#elif defined(__DJGPP__) || defined(__GO32__)
#	define Z_COMPILER Z_COMPILER_DJGPP

#elif defined(__EDG__)
#	define Z_COMPILER Z_COMPILER_EDG_CPP_FRONTEND

#elif defined(__PATHCC__)
#	define Z_COMPILER Z_COMPILER_EKOPATH

#elif defined(__FCC_VERSION)
#	define Z_COMPILER Z_COMPILER_FUJITSU_CPP

#elif defined(__ghs__)
#	define Z_COMPILER Z_COMPILER_GREEN_HILL_C_CPP

#elif defined(__HP_aCC)
#	define Z_COMPILER Z_COMPILER_HP_ACPP

#elif defined(__HP_cc)
#	define Z_COMPILER Z_COMPILER_HP_ANSI_C

#elif defined(__COMPAQ_UPC_VER) || defined(__HP_UPC_VER)
#	define Z_COMPILER Z_COMPILER_HP_UPC

#elif defined(__IAR_SYSTEMS_ICC__)
#	define Z_COMPILER Z_COMPILER_IAR_C_CPP

#elif defined(__xlc__) || defined(__xlC__) /* Not sure */
#	define Z_COMPILER Z_COMPILER_IBM_XL_C_CPP

#elif defined(__IBMC__) || defined(__IBMCPP__)
#	if defined(__COMPILER_VER__)
#		define Z_COMPILER Z_COMPILER_IBM_Z_OS_C_CPP
#	else
#		define Z_COMPILER Z_COMPILER_IBM_XL_C_CPP
#	endif

#elif defined(__IMAGECRAFT__)
#	define Z_COMPILER Z_COMPILER_IMAGECRAFT_C

#elif defined(__INTEL_COMPILER)	|| defined(__ICC) || defined(__ECC) || defined(__ICL)
#	define Z_COMPILER Z_COMPILER_INTEL_CPP

#elif defined(__KCC)
#	define Z_COMPILER Z_COMPILER_KAI_CPP

#elif defined(__C166__)
#	define Z_COMPILER Z_COMPILER_KEIL_C166

#elif defined(__C51__) || defined(__CX51__)
#	define Z_COMPILER Z_COMPILER_KEIL_C51

#elif defined(__CA__) || defined(__KEIL__)
#	define Z_COMPILER Z_COMPILER_KEIL_CARM

#elif defined(__LCC__)
#	define Z_COMPILER Z_COMPILER_LCC

#elif defined(__MCC__)
#	define Z_COMPILER Z_COMPILER_MCC

#elif defined(__HIGHC__)
#	define Z_COMPILER Z_COMPILER_METAWARE_HIGH_C_CPP

#elif defined(_MRI)
#	define Z_COMPILER Z_COMPILER_MICROTEC_C_CPP

#elif defined(__MINGW__) || defined(__MINGW32__) || defined(__MINGW64__)
#	define Z_COMPILER Z_COMPILER_MINGW

#elif defined(__sgi) || defined(sgi)
#	define Z_COMPILER Z_COMPILER_MIPS_PRO

#elif defined(MIRACLE)
#	define Z_COMPILER Z_COMPILER_MIRACLE_C

#elif defined(__MRC__) || defined(MPW_C) || defined(MPW_CPLUS)
#	define Z_COMPILER Z_COMPILER_MPW_CPP

#elif defined(__NDPC__) || defined(__NDPX__)
#	define Z_COMPILER Z_COMPILER_NDP_C

#elif defined(__CC_NORCROFT)
#	define Z_COMPILER Z_COMPILER_NORCROFT_C

#elif defined(__NVCOMPILER)
#	define Z_COMPILER Z_COMPILER_NVC

#elif defined(__NWCC__)
#	define Z_COMPILER Z_COMPILER_NWCC

#elif defined(__OPEN64__) || defined(__OPENCC__)
#	define Z_COMPILER Z_COMPILER_OPEN64

#elif defined(ORA_PROC)
#	define Z_COMPILER Z_COMPILER_ORACLE_PRO_C_PRECOMPILER

#elif defined(__SUNPRO_C) || defined(__SUNPRO_CC)
#	define Z_COMPILER Z_COMPILER_ORACLE_SOLARIS_STUDIO

#elif defined(__PACIFIC__)
#	define Z_COMPILER Z_COMPILER_PACIFIC_C

#elif defined(_PACC_VER)
#	define Z_COMPILER Z_COMPILER_PALM_C_CPP

#elif defined(__PCC__)
#	define Z_COMPILER Z_COMPILER_PCC

#elif defined(__POCC__)
#	define Z_COMPILER Z_COMPILER_PELLES_C

#elif defined(__PGI)
#	define Z_COMPILER Z_COMPILER_PGI_C_CPP

#elif defined(__RENESAS__) || defined(__HITACHI__)
#	define Z_COMPILER Z_COMPILER_RENESAS_C_CPP

#elif defined(__SASC) || defined(__SASC__) || defined(SASC)
#	define Z_COMPILER Z_COMPILER_SAS_C

#elif defined(__SCCZ80)
#	define Z_COMPILER Z_COMPILER_SCCZ80

#elif defined(__SDCC) /* Z88DK version? */ /* || defined(SDCC) */
#	define Z_COMPILER Z_COMPILER_SDCC

#elif defined(__SNC__)
#	define Z_COMPILER Z_COMPILER_SNC

#elif defined(__SC__)
#	define Z_COMPILER Z_COMPILER_SYMANTEC_CPP

#elif defined(__SYSC__)
#	define Z_COMPILER Z_COMPILER_SYSTEMS_C

#elif defined(__TenDRA__)
#	define Z_COMPILER Z_COMPILER_TENDRA

/*#elif defined(THINKC3) || defined(THINKC4)
#	define Z_COMPILER Z_COMPILER_THINK_C*/

#elif defined(__TI_COMPILER_VERSION__) || defined(_TMS320C6X)
#	define Z_COMPILER Z_COMPILER_TI_C_CPP_COMPILER

#elif defined(__TINYC__)
#	define Z_COMPILER Z_COMPILER_TINY_CC

#elif	defined(__BORLANDC__ ) || \
	defined(__CODEGEARC__) || \
	(defined(__TURBOC__) && __TURBOC__ >= 0x295)

#	define Z_COMPILER Z_COMPILER_TURBO_CPP

#elif defined(__TURBOC__)
#	define Z_COMPILER Z_COMPILER_TURBO_C

#elif defined(_UCC)
#	define Z_COMPILER Z_COMPILER_ULTRA_C_CPP

#elif defined(__USLC__)
#	define Z_COMPILER Z_COMPILER_USL

#elif defined(__VBCC__)
#	define Z_COMPILER Z_COMPILER_VBCC

#elif defined(__VOSC__) && !__VOSC__
#	define Z_COMPILER Z_COMPILER_VOS_C

#elif defined(__VOSC__) && __VOSC__ == 1
#	define Z_COMPILER Z_COMPILER_VOS_STANDARD_C

#elif defined(_MSC_VER)
#	if _MSC_VER < 800
#		define Z_COMPILER Z_COMPILER_MSC
#	else
#		define Z_COMPILER Z_COMPILER_MSVC
#	endif

#elif defined(__WATCOMC__)
#	define Z_COMPILER Z_COMPILER_WATCOM_C_CPP

#elif defined(__ZTC__)
#	define Z_COMPILER Z_COMPILER_ZORTECH_CPP

#elif defined(__GNUC__)
#	define Z_COMPILER Z_COMPILER_GCC

#else
#	define Z_COMPILER Z_COMPILER_UNKNOWN
#endif

#endif /* Z_inspection_compiler_detection_H */
