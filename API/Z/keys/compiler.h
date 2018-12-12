/* Z Kit - keys/compiler.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_keys_compiler_H_
#define _Z_keys_compiler_H_
							      /* First released by:   Official website:			   */
#define Z_COMPILER_UNKNOWN				  0 /* ---------------------- ------------------------------------ */
#define Z_COMPILER_GCC					  1 /* GNU		      <https://gcc.gnu.org>		   */
#define Z_COMPILER_CLANG				  2 /* LLVM Foundation, The   <https://clang.llvm.org>		   */
#define Z_COMPILER_VISUAL_CPP				  3 /* Microsoft	      <https://visualstudio.microsoft.com> */
#define Z_COMPILER_ACC					  4 /*								   */
#define Z_COMPILER_ALTIUM_MICROBLAZE_C			  5 /*								   */
#define Z_COMPILER_ALTIUM_C_TO_HARDWARE			  6 /*								   */
#define Z_COMPILER_AMSTERDAM_COMPILER_KIT		  7 /*								   */
#define Z_COMPILER_APPLE_LLVM				  8 /* Apple		      <https://developer.apple.com/xcode>  */
#define Z_COMPILER_ARM_C_CPP_COMPILER			  9 /*								   */
#define Z_COMPILER_ARM_COMPILER				 10 /*								   */
#define Z_COMPILER_AZTEC_C				 11 /*								   */
#define Z_COMPILER_BORLAND_CPP				 12 /* Borland							   */
#define Z_COMPILER_CC65					 13 /* von Bassewitz, Ullrich <https://cc65.github.io>		   */
#define Z_COMPILER_CODE_WARRIOR				 14 /*								   */
#define Z_COMPILER_COMEAU_CPP				 15 /*								   */
#define Z_COMPILER_COMPAQ_C_CPP				 16 /*								   */
#define Z_COMPILER_COMPCERT				 17 /*								   */
#define Z_COMPILER_CONVEX_C				 18 /*								   */
#define Z_COMPILER_COVERITY_C_CPP_STATIC_ANALYZER	 19 /*								   */
#define Z_COMPILER_CRAY_C				 20 /*								   */
#define Z_COMPILER_DIAB_C_CPP				 21 /*								   */
#define Z_COMPILER_DICE_C				 22 /*								   */
#define Z_COMPILER_DIGITAL_MARS				 23 /*								   */
#define Z_COMPILER_DIGNUS_SYSTEMS_C			 24 /*								   */
#define Z_COMPILER_DJGPP				 25 /*								   */
#define Z_COMPILER_EDG_CPP_FRONTEND			 26 /*								   */
#define Z_COMPILER_EKOPATH				 27 /*								   */
#define Z_COMPILER_FUJITSU_CPP				 28 /*								   */
#define Z_COMPILER_GREEN_HILL_C_CPP			 29 /*								   */
#define Z_COMPILER_HP_ACPP				 30 /*								   */
#define Z_COMPILER_HP_ANSI_C				 31 /*								   */
#define Z_COMPILER_HP_UPC				 32 /*								   */
#define Z_COMPILER_IAR_C_CPP				 33 /*								   */
#define Z_COMPILER_IBM_XL_C_CPP				 34 /*								   */
#define Z_COMPILER_IBM_Z_OS_C_CPP			 35 /*								   */
#define Z_COMPILER_IMAGECRAFT_C				 36 /*								   */
#define Z_COMPILER_INTEL_CPP				 37 /* Intel							   */
#define Z_COMPILER_KAI_CPP				 38 /*								   */
#define Z_COMPILER_KEIL_C166				 39 /*								   */
#define Z_COMPILER_KEIL_C51				 40 /*								   */
#define Z_COMPILER_KEIL_CARM				 41 /*								   */
#define Z_COMPILER_LCC					 42 /*								   */
#define Z_COMPILER_METAWARE_HIGH_C_CPP			 43 /*								   */
#define Z_COMPILER_MICROTEC_C_CPP			 44 /*								   */
#define Z_COMPILER_MICROWAY_NDP_C			 45 /*								   */
#define Z_COMPILER_MINGW				 46 /* Peters, Colin	      <http://www.mingw.org>		   */
#define Z_COMPILER_MIPS_PRO				 47 /*								   */
#define Z_COMPILER_MIRACLE_C				 48 /*								   */
#define Z_COMPILER_MPW_CPP				 49 /*								   */
#define Z_COMPILER_NORCROFT_C				 50 /*								   */
#define Z_COMPILER_NWCC					 51 /*								   */
#define Z_COMPILER_OPEN64				 52 /*								   */
#define Z_COMPILER_ORACLE_PRO_C_PRECOMPILER		 53 /*								   */
#define Z_COMPILER_ORACLE_SOLARIS_STUDIO		 54 /*								   */
#define Z_COMPILER_PACIFIC_C				 55 /*								   */
#define Z_COMPILER_PALM_C_CPP				 56 /*								   */
#define Z_COMPILER_PCC					 57 /* Johnson, Stephen C.    <http://pcc.ludd.ltu.se>		   */
#define Z_COMPILER_PELLES_C				 58 /*								   */
#define Z_COMPILER_PGI_C_CPP				 59 /*								   */
#define Z_COMPILER_RENESAS_C_CPP			 60 /*								   */
#define Z_COMPILER_SAS_C				 61 /*								   */
#define Z_COMPILER_SCCZ80				 62 /* Z88DK		      <https://www.z88dk.org>		   */
#define Z_COMPILER_SCO_OPEN_SERVER			 63 /*								   */
#define Z_COMPILER_SDCC					 64 /*								   */
#define Z_COMPILER_SN_COMPILER				 65 /*								   */
#define Z_COMPILER_STRATUS_VOS_C			 66 /*								   */
#define Z_COMPILER_SYMANTEC_CPP				 67 /*								   */
#define Z_COMPILER_TENDRA_C_CPP				 68 /*								   */
#define Z_COMPILER_TEXAS_INSTRUMENTS_C_CPP_COMPILER	 69 /*								   */
#define Z_COMPILER_THINK_C				 70 /*								   */
#define Z_COMPILER_TINY_C				 71 /*								   */
#define Z_COMPILER_TURBO_C_CPP				 72 /* Borland							   */
#define Z_COMPILER_ULTIMATE_C_CPP			 73 /*								   */
#define Z_COMPILER_USL_C				 74 /*								   */
#define Z_COMPILER_VBCC					 75 /*								   */
#define Z_COMPILER_WATCOM_C_CPP				 76 /* Watcom International   <http://openwatcom.org>		   */
#define Z_COMPILER_ZORTECH_CPP				 77 /*								   */

#define Z_COMPILER_NAME_GCC				 "GCC"
#define Z_COMPILER_NAME_CLANG				 "Clang"
#define Z_COMPILER_NAME_VISUAL_CPP			 "Visual C++"
#define Z_COMPILER_NAME_ACC				 "ACC"
#define Z_COMPILER_NAME_ALTIUM_MICROBLAZE_C		 "Altium MicroBlaze C"
#define Z_COMPILER_NAME_ALTIUM_C_TO_HARDWARE		 "Altium C-to-Hardware"
#define Z_COMPILER_NAME_AMSTERDAM_COMPILER_KIT		 "Amsterdam Compiler Kit"
#define Z_COMPILER_NAME_APPLE_LLVM			 "Apple LLVM"
#define Z_COMPILER_NAME_ARM_C_CPP_COMPILER		 "ARM C/C++ Compiler" /* Previously known as ARM RealView C/C++ Compiler */
#define Z_COMPILER_NAME_ARM_COMPILER			 "ARM Compiler"
#define Z_COMPILER_NAME_AZTEC_C				 "Aztec C"
#define Z_COMPILER_NAME_BORLAND_CPP			 "Borland C++"
#define Z_COMPILER_NAME_CC65				 "cc65"
#define Z_COMPILER_NAME_CODE_WARRIOR			 "CodeWarrior"
#define Z_COMPILER_NAME_COMEAU_CPP			 "Comeau C++ "
#define Z_COMPILER_NAME_COMPAQ_C_CPP			 "Compaq C/C++"
#define Z_COMPILER_NAME_COMPCERT			 "CompCert"
#define Z_COMPILER_NAME_CONVEX_C			 "Convex C"
#define Z_COMPILER_NAME_COVERITY_C_CPP_STATIC_ANALYZER   "Coverity C/C++ Static Analyzer"
#define Z_COMPILER_NAME_CRAY_C				 "Cray C"
#define Z_COMPILER_NAME_DIAB_C_CPP			 "Diab C/C++"
#define Z_COMPILER_NAME_DICE_C				 "DICE C"
#define Z_COMPILER_NAME_DIGITAL_MARS			 "Digital Mars"
#define Z_COMPILER_NAME_DIGNUS_SYSTEMS_C		 "Dignus Systems/C"
#define Z_COMPILER_NAME_DJGPP				 "DJGPP"
#define Z_COMPILER_NAME_EDG_CPP_FRONTEND		 "EDG C++ Frontend"
#define Z_COMPILER_NAME_EKOPARH				 "EKOPath"
#define Z_COMPILER_NAME_FUJITSU_CPP			 "Fujitsu C++"
#define Z_COMPILER_NAME_GREEN_HILL_C_CPP		 "Green Hill C/C++"
#define Z_COMPILER_NAME_HP_ACPP				 "HP aC++"
#define Z_COMPILER_NAME_HP_ANSI_C			 "HP ANSI C"
#define Z_COMPILER_NAME_HP_UPC				 "HP UPC"
#define Z_COMPILER_NAME_IAR_C_CPP			 "IAR C/C++"
#define Z_COMPILER_NAME_IBM_XL_C_CPP			 "IBM XL C/C++"
#define Z_COMPILER_NAME_IBM_Z_OS_C_CPP			 "IBM z/OS C/C++"
#define Z_COMPILER_NAME_IMAGECRAFT_C			 "ImageCraft C"
#define Z_COMPILER_NAME_INTEL_CPP			 "Intel C++"
#define Z_COMPILER_NAME_KAI_CPP				 "KAI C++"
#define Z_COMPILER_NAME_KEIL_C166			 "KEIL C166"
#define Z_COMPILER_NAME_KEIL_C51			 "KEIL C51"
#define Z_COMPILER_NAME_KEIL_CARM			 "KEIL CARM" /* Discontinued – Replaced by ARM RealView C/C++ Compiler */
#define Z_COMPILER_NAME_LCC				 "LLC"
#define Z_COMPILER_NAME_METAWARE_HIGH_C_CPP		 "MetaWare High C/C++"
#define Z_COMPILER_NAME_MICROTEC_C_CPP			 "Microtec C/C++"
#define Z_COMPILER_NAME_MICROWAY_NDP_C			 "Microway NDP C"
#define Z_COMPILER_NAME_MINGW				 "MinGW"
#define Z_COMPILER_NAME_MIPS_PRO			 "MIPSpro"
#define Z_COMPILER_NAME_MIRACLE_C			 "Miracle C"
#define Z_COMPILER_NAME_MPW_CPP				 "MPW C++"
#define Z_COMPILER_NAME_NORCROFT_C			 "Norcroft C"
#define Z_COMPILER_NAME_NWCC				 "NWCC"
#define Z_COMPILER_NAME_OPEN64				 "Open64"
#define Z_COMPILER_NAME_ORACLE_PRO_C_PRECOMPILER	 "Oracle Pro*C Precompiler"
#define Z_COMPILER_NAME_ORACLE_SOLARIS_STUDIO		 "Oracle Solaris Studio"
#define Z_COMPILER_NAME_PACIFIC_C			 "Pacific C"
#define Z_COMPILER_NAME_PALM_C_CPP			 "Palm C/C++"
#define Z_COMPILER_NAME_PCC				 "PCC" /* Portable C Compiler */
#define Z_COMPILER_NAME_PELLES_C			 "Pelles C"
#define Z_COMPILER_NAME_PGI_C_CPP			 "PGI C/C++"
#define Z_COMPILER_NAME_RENESAS_C_CPP			 "Renesas C/C++"
#define Z_COMPILER_NAME_SAS_C				 "SAS/C"
#define Z_COMPILER_NAME_SCCZ80				 "SCCZ80"
#define Z_COMPILER_NAME_SCO_OPEN_SERVER			 "SCO OpenServer"
#define Z_COMPILER_NAME_SDCC				 "SDCC" /* Small Device C Compiler */
#define Z_COMPILER_NAME_SN_COMPILER			 "SN Compiler"
#define Z_COMPILER_NAME_STRATUS_VOS_C			 "Stratus VOS C"
#define Z_COMPILER_NAME_SYMANTEC_CPP			 "Symantec C++"
#define Z_COMPILER_NAME_TENDRA_C_CPP			 "TenDRA C - C++"
#define Z_COMPILER_NAME_TEXAS_INSTRUMENTS_C_CPP_COMPILER "Texas Instruments C/C++ Compiler"
#define Z_COMPILER_NAME_THINK_C				 "THINK C"
#define Z_COMPILER_NAME_TINY_C				 "Tiny C"
#define Z_COMPILER_NAME_TURBO_C_CPP			 "Turbo C/C++"
#define Z_COMPILER_NAME_ULTIMATE_C_CPP			 "Ultimate C/C++"
#define Z_COMPILER_NAME_USL_C				 "USL C"
#define Z_COMPILER_NAME_VBCC				 "VBCC"
#define Z_COMPILER_NAME_WATCOM_C_CPP			 "Watcom C/C++"
#define Z_COMPILER_NAME_ZORTECH_CPP			 "Zortech C++"

#define Z_COMPILER_DIGNUS_SYSTEMS_CPP			 Z_COMPILER_DIGNUS_SYSTEMS_C /* Check this */
#define Z_COMPILER_FORTE_DEVELOPER			 Z_COMPILER_ORACLE_SOLARIS_STUDIO
#define Z_COMPILER_SUN_PRO_COMPILERS			 Z_COMPILER_ORACLE_SOLARIS_STUDIO
#define Z_COMPILER_SUN_STUDIO				 Z_COMPILER_ORACLE_SOLARIS_STUDIO
#define Z_COMPILER_SUN_WORK_SHOP			 Z_COMPILER_ORACLE_SOLARIS_STUDIO
#define Z_COMPILER_VISUAL_AGE_CPP			 Z_COMPILER_IBM_XL_C_CPP

#define Z_COMPILER_NAME_DIGNUS_SYSTEMS_CPP		 "Dignus Systems/C++"
#define Z_COMPILER_NAME_FORTE_DEVELOPER			 "Forte Developer"
#define Z_COMPILER_NAME_SUN_PRO_COMPILERS		 "SunPro Compilers"
#define Z_COMPILER_NAME_SUN_STUDIO			 "Sun Studio"
#define Z_COMPILER_NAME_SUN_WORK_SHOP			 "Sun WorkShop"
#define Z_COMPILER_NAME_VISUAL_AGE_CPP			 "VisualAge C++" /* Renamed to IBM XL C/C++ */

#endif /* _Z_keys_compiler_H_ */
