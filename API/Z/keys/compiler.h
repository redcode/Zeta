/* Z Kit - keys/compiler.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2019 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_keys_compiler_H
#define Z_keys_compiler_H
							      /* First released by:   Official website:			     */
#define Z_COMPILER_UNKNOWN				  0 /* ---------------------- -------------------------------------- */
#define Z_COMPILER_GCC					  1 /* GNU		      <https://gcc.gnu.org>		     */
#define Z_COMPILER_CLANG				  2 /* LLVM Foundation, The   <https://clang.llvm.org>		     */
#define Z_COMPILER_VISUAL_CPP				  3 /* Microsoft	      <https://visualstudio.microsoft.com>   */
#define Z_COMPILER_ACC					  4 /*								     */
#define Z_COMPILER_ALTIUM_MICROBLAZE_C			  5 /*								     */
#define Z_COMPILER_ALTIUM_C_TO_HARDWARE			  6 /*								     */
#define Z_COMPILER_AMSTERDAM_COMPILER_KIT		  7 /*								     */
#define Z_COMPILER_APPLE_LLVM				  8 /* Apple		      <https://developer.apple.com/xcode>    */
#define Z_COMPILER_ARM_C_CPP_COMPILER			  9 /*								     */
#define Z_COMPILER_ARM_COMPILER				 10 /*								     */
#define Z_COMPILER_AZTEC_C				 11 /*								     */
#define Z_COMPILER_CC65					 12 /* von Bassewitz, Ullrich <https://cc65.github.io>		     */
#define Z_COMPILER_CODE_WARRIOR				 13 /*								     */
#define Z_COMPILER_COMEAU_CPP				 14 /*								     */
#define Z_COMPILER_COMPAQ_C_CPP				 15 /*								     */
#define Z_COMPILER_COMPCERT				 16 /*								     */
#define Z_COMPILER_CONVEX_C				 17 /*								     */
#define Z_COMPILER_COVERITY_C_CPP_STATIC_ANALYZER	 18 /*								     */
#define Z_COMPILER_CRAY_C				 19 /*								     */
#define Z_COMPILER_DIAB_C_CPP				 20 /*								     */
#define Z_COMPILER_DICE_C				 21 /*								     */
#define Z_COMPILER_DIGITAL_MARS				 22 /*								     */
#define Z_COMPILER_DJGPP				 23 /*								     */
#define Z_COMPILER_EDG_CPP_FRONTEND			 24 /*								     */
#define Z_COMPILER_EKOPATH				 25 /*								     */
#define Z_COMPILER_FUJITSU_CPP				 26 /*								     */
#define Z_COMPILER_GREEN_HILL_C_CPP			 27 /*								     */
#define Z_COMPILER_HP_ACPP				 28 /*								     */
#define Z_COMPILER_HP_ANSI_C				 29 /*								     */
#define Z_COMPILER_HP_UPC				 30 /* Hewlett-Packard (?)    <http://www.hp.com/go/upc>	     */
#define Z_COMPILER_IAR_C_CPP				 31 /*								     */
#define Z_COMPILER_IBM_XL_C_CPP				 32 /*								     */
#define Z_COMPILER_IBM_Z_OS_C_CPP			 33 /*								     */
#define Z_COMPILER_IMAGECRAFT_C				 34 /*								     */
#define Z_COMPILER_INTEL_CPP				 35 /* Intel							     */
#define Z_COMPILER_KAI_CPP				 36 /* Kuck & Associates					     */
#define Z_COMPILER_KEIL_C166				 37 /*								     */
#define Z_COMPILER_KEIL_C51				 38 /*								     */
#define Z_COMPILER_KEIL_CARM				 39 /*								     */
#define Z_COMPILER_LCC					 40 /*								     */
#define Z_COMPILER_METAWARE_HIGH_C_CPP			 41 /*								     */
#define Z_COMPILER_MICROTEC_C_CPP			 42 /*								     */
#define Z_COMPILER_MINGW				 43 /* Peters, Colin	      <http://www.mingw.org>		     */
#define Z_COMPILER_MIPS_PRO				 44 /*								     */
#define Z_COMPILER_MIRACLE_C				 45 /*								     */
#define Z_COMPILER_MPW_CPP				 46 /*								     */
#define Z_COMPILER_NDP_C				 47 /* Microway							     */
#define Z_COMPILER_NORCROFT_C				 48 /*								     */
#define Z_COMPILER_NWCC					 49 /*								     */
#define Z_COMPILER_OPEN64				 50 /*								     */
#define Z_COMPILER_ORACLE_PRO_C_PRECOMPILER		 51 /*								     */
#define Z_COMPILER_ORACLE_SOLARIS_STUDIO		 52 /*								     */
#define Z_COMPILER_PACIFIC_C				 53 /*								     */
#define Z_COMPILER_PALM_C_CPP				 54 /*								     */
#define Z_COMPILER_PCC					 55 /* Johnson, Stephen C.    <http://pcc.ludd.ltu.se>		     */
#define Z_COMPILER_PELLES_C				 56 /* Orinius, Pelle	      <http://www.smorgasbordet.com/pellesc> */
#define Z_COMPILER_PGI_C_CPP				 57 /*								     */
#define Z_COMPILER_RENESAS_C_CPP			 58 /*								     */
#define Z_COMPILER_SAS_C				 59 /*								     */
#define Z_COMPILER_SCCZ80				 60 /* Z88DK		      <https://www.z88dk.org>		     */
#define Z_COMPILER_SDCC					 61 /*								     */
#define Z_COMPILER_SNC					 62 /* SN Systems						     */
#define Z_COMPILER_SYMANTEC_CPP				 63 /*								     */
#define Z_COMPILER_SYSTEMS_C				 64 /* Dignus		      <http://www.dignus.com/dcc>	     */
#define Z_COMPILER_TENDRA				 65 /* DERA							     */
#define Z_COMPILER_TEXAS_INSTRUMENTS_C_CPP_COMPILER	 66 /*								     */
#define Z_COMPILER_THINK_C				 67 /*								     */
#define Z_COMPILER_TINY_C				 68 /* Bellard, Fabrice	      <https://bellard.org/tcc>		     */
#define Z_COMPILER_TURBO_C				 69 /* Borland							     */
#define Z_COMPILER_TURBO_CPP				 70 /* Borland							     */
#define Z_COMPILER_ULTRA_C_CPP				 71 /* Microware Systems					     */
#define Z_COMPILER_USL					 72 /*								     */
#define Z_COMPILER_VBCC					 73 /* Barthelmann, Volker    <http://www.compilers.de/vbcc.html>    */
#define Z_COMPILER_VOS_C				 74 /* Stratus Technologies					     */
#define Z_COMPILER_VOS_STANDARD_C			 75 /* Stratus Technologies					     */
#define Z_COMPILER_WATCOM_C_CPP				 76 /* Watcom International   <http://openwatcom.org>		     */
#define Z_COMPILER_ZORTECH_CPP				 77 /*								     */

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
#define Z_COMPILER_NAME_DJGPP				 "DJGPP"
#define Z_COMPILER_NAME_EDG_CPP_FRONTEND		 "EDG C++ Frontend"
#define Z_COMPILER_NAME_EKOPATH				 "EKOPath"
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
#define Z_COMPILER_NAME_MINGW				 "MinGW"
#define Z_COMPILER_NAME_MIPS_PRO			 "MIPSpro"
#define Z_COMPILER_NAME_MIRACLE_C			 "Miracle C"
#define Z_COMPILER_NAME_MPW_CPP				 "MPW C++"
#define Z_COMPILER_NAME_NDP_C				 "NDP C"
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
#define Z_COMPILER_NAME_SDCC				 "SDCC" /* Small Device C Compiler */
#define Z_COMPILER_NAME_SNC				 "SNC"
#define Z_COMPILER_NAME_SYMANTEC_CPP			 "Symantec C++"
#define Z_COMPILER_NAME_SYSTEMS_C			 "Systems/C"
#define Z_COMPILER_NAME_TENDRA				 "TenDRA"
#define Z_COMPILER_NAME_TEXAS_INSTRUMENTS_C_CPP_COMPILER "Texas Instruments C/C++ Compiler"
#define Z_COMPILER_NAME_THINK_C				 "THINK C"
#define Z_COMPILER_NAME_TINY_C				 "Tiny C"
#define Z_COMPILER_NAME_TURBO_C				 "Turbo C"
#define Z_COMPILER_NAME_TURBO_CPP			 "Turbo C++"
#define Z_COMPILER_NAME_ULTRA_C_CPP			 "Ultra C/C++"
#define Z_COMPILER_NAME_USL				 "USL"
#define Z_COMPILER_NAME_VBCC				 "vbcc"
#define Z_COMPILER_NAME_VOS_C				 "VOS C"
#define Z_COMPILER_NAME_VOS_STANDARD_C			 "VOS Standard C"
#define Z_COMPILER_NAME_WATCOM_C_CPP			 "Watcom C/C++"
#define Z_COMPILER_NAME_ZORTECH_CPP			 "Zortech C++"

#define Z_COMPILER_FORTE_DEVELOPER			 Z_COMPILER_ORACLE_SOLARIS_STUDIO
#define Z_COMPILER_SUN_PRO_COMPILERS			 Z_COMPILER_ORACLE_SOLARIS_STUDIO
#define Z_COMPILER_SUN_STUDIO				 Z_COMPILER_ORACLE_SOLARIS_STUDIO
#define Z_COMPILER_SUN_WORK_SHOP			 Z_COMPILER_ORACLE_SOLARIS_STUDIO
#define Z_COMPILER_SYSTEMS_CPP				 Z_COMPILER_SYSTEMS_C /* Check this */
#define Z_COMPILER_VISUAL_AGE_CPP			 Z_COMPILER_IBM_XL_C_CPP

#define Z_COMPILER_NAME_FORTE_DEVELOPER			 "Forte Developer"
#define Z_COMPILER_NAME_SUN_PRO_COMPILERS		 "SunPro Compilers"
#define Z_COMPILER_NAME_SUN_STUDIO			 "Sun Studio"
#define Z_COMPILER_NAME_SUN_WORK_SHOP			 "Sun WorkShop"
#define Z_COMPILER_NAME_SYSTEMS_CPP			 "Systems/C++"
#define Z_COMPILER_NAME_VISUAL_AGE_CPP			 "VisualAge C++" /* Renamed to IBM XL C/C++ */

#endif /* Z_keys_compiler_H */
