/* Z Kit C API - keys/compiler.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_keys_compiler_H__
#define __Z_keys_compiler_H__

#define Z_COMPILER_GCC				    0
#define Z_COMPILER_CLANG			    1
#define Z_COMPILER_VISUAL_CPP			    2
#define Z_COMPILER_ACC				    3
#define Z_COMPILER_ALTIUM_MICROBLAZE_C		    4
#define Z_COMPILER_ALTIUM_C_TO_HARDWARE		    5
#define Z_COMPILER_AMSTERDAM_COMPILER_KIT	    6
#define Z_COMPILER_APPLE_LLVM			    7
#define Z_COMPILER_ARM_C_CPP_COMPILER		    8
#define Z_COMPILER_ARM_COMPILER			    9
#define Z_COMPILER_AZTEC_C			    10
#define Z_COMPILER_BORLAND_CPP			    11
#define Z_COMPILER_CC65				    12
#define Z_COMPILER_CODE_WARRIOR			    13
#define Z_COMPILER_COMEAU_CPP			    14
#define Z_COMPILER_COMPAQ_C_CPP			    15
#define Z_COMPILER_COMPCERT			    16
#define Z_COMPILER_CONVEX_C			    17
#define Z_COMPILER_COVERITY_C_CPP_STATIC_ANALYZER   18
#define Z_COMPILER_CRAY_C			    19
#define Z_COMPILER_DIAB_C_CPP			    20
#define Z_COMPILER_DICE_C			    21
#define Z_COMPILER_DIGITAL_MARS			    22
#define Z_COMPILER_DIGNUS_SYSTEMS_C		    23
#define Z_COMPILER_DIGNUS_SYSTEMS_CPP		    Z_COMPILER_DIGNUS_SYSTEMS_CPP
#define Z_COMPILER_DJGPP			    24
#define Z_COMPILER_EDG_CPP_FRONTEND		    25
#define Z_COMPILER_EKOPATH			    26
#define Z_COMPILER_FUJITSU_CPP			    27
#define Z_COMPILER_GREEN_HILL_C_CPP		    28
#define Z_COMPILER_HP_ACPP			    29
#define Z_COMPILER_HP_ANSI_C			    30
#define Z_COMPILER_HP_UPC			    31
#define Z_COMPILER_IAR_C_CPP			    32
#define Z_COMPILER_IBM_XL_C_CPP			    33
#define Z_COMPILER_VISUAL_AGE_CPP		    Z_COMPILER_IBM_XL_C_CPP
#define Z_COMPILER_IBM_Z_OS_C_CPP		    34
#define Z_COMPILER_IMAGECRAFT_C			    35
#define Z_COMPILER_INTEL_CPP			    36
#define Z_COMPILER_KAI_CPP			    37
#define Z_COMPILER_KEIL_C166			    38
#define Z_COMPILER_KEIL_C51			    39
#define Z_COMPILER_KEIL_CARM			    40
#define Z_COMPILER_LCC				    41
#define Z_COMPILER_METAWARE_HIGH_C_CPP		    42
#define Z_COMPILER_MICROTEC_C_CPP		    43
#define Z_COMPILER_MICROWAY_NDP_C		    44
#define Z_COMPILER_MINGW			    45
#define Z_COMPILER_MIPS_PRO			    46
#define Z_COMPILER_MIRACLE_C			    47
#define Z_COMPILER_MPW_CPP			    48
#define Z_COMPILER_NORCROFT_C			    49
#define Z_COMPILER_NWCC				    50
#define Z_COMPILER_OPEN64			    51
#define Z_COMPILER_ORACLE_PRO_C_PRECOMPILER	    52
#define Z_COMPILER_ORACLE_SOLARIS_STUDIO	    53
#define Z_COMPILER_SUN_STUDIO			    Z_COMPILER_ORACLE_SOLARIS_STUDIO
#define Z_COMPILER_SUN_WORK_SHOP		    Z_COMPILER_ORACLE_SOLARIS_STUDIO
#define Z_COMPILER_FORTE_DEVELOPER		    Z_COMPILER_ORACLE_SOLARIS_STUDIO
#define Z_COMPILER_SUN_PRO_COMPILERS		    Z_COMPILER_ORACLE_SOLARIS_STUDIO
#define Z_COMPILER_PACIFIC_C			    54
#define Z_COMPILER_PALM_C_CPP			    55
#define Z_COMPILER_PELLES_C			    56
#define Z_COMPILER_PGI_C_CPP			    57
#define Z_COMPILER_RENESAS_C_CPP		    58
#define Z_COMPILER_SAS_C			    59
#define Z_COMPILER_SCO_OPEN_SERVER		    60
#define Z_COMPILER_SMALL_DEVICE_C_COMPILER	    61
#define Z_COMPILER_SN_COMPILER			    62
#define Z_COMPILER_STRATUS_VOS_C		    63
#define Z_COMPILER_SYMANTEC_CPP			    64
#define Z_COMPILER_TENDRA_C_CPP			    65
#define Z_COMPILER_TEXAS_INSTRUMENTS_C_CPP_COMPILER 66
#define Z_COMPILER_THINK_C			    67
#define Z_COMPILER_TINY_C			    68
#define Z_COMPILER_TURBO_C_CPP			    69
#define Z_COMPILER_ULTIMATE_C_CPP		    70
#define Z_COMPILER_USL_C			    71
#define Z_COMPILER_VBCC				    72
#define Z_COMPILER_WATCOM_C_CPP			    73
#define Z_COMPILER_ZORTECH_CPP			    74

#define Z_COMPILER_STRING_GCC				   "GCC"
#define Z_COMPILER_STRING_CLANG				   "Clang"
#define Z_COMPILER_STRING_VISUAL_CPP			   "Visual C++"
#define Z_COMPILER_STRING_ACC				   "ACC"
#define Z_COMPILER_STRING_ALTIUM_MICROBLAZE_C		   "Altium MicroBlaze C"
#define Z_COMPILER_STRING_ALTIUM_C_TO_HARDWARE		   "Altium C-to-Hardware"
#define Z_COMPILER_STRING_AMSTERDAM_COMPILER_KIT	   "Amsterdam Compiler Kit"
#define Z_COMPILER_STRING_APPLE_LLVM			   "Apple LLVM"
#define Z_COMPILER_STRING_ARM_C_CPP_COMPILER		   "ARM C/C++ Compiler" /* Previously known as ARM RealView C/C++ Compiler */
#define Z_COMPILER_STRING_ARM_COMPILER			   "ARM Compiler"
#define Z_COMPILER_STRING_AZTEC_C			   "Aztec C"
#define Z_COMPILER_STRING_BORLAND_CPP			   "Borland C++"
#define Z_COMPILER_STRING_CC65				   "CC65"
#define Z_COMPILER_STRING_CODE_WARRIOR			   "CodeWarrior"
#define Z_COMPILER_STRING_COMEAU_CPP			   "Comeau C++ "
#define Z_COMPILER_STRING_COMPAQ_C_CPP			   "Compaq C/C++"
#define Z_COMPILER_STRING_COMPCERT			   "CompCert"
#define Z_COMPILER_STRING_CONVEX_C			   "Convex C"
#define Z_COMPILER_STRING_COVERITY_C_CPP_STATIC_ANALYZER   "Coverity C/C++ Static Analyzer"
#define Z_COMPILER_STRING_CRAY_C			   "Cray C"
#define Z_COMPILER_STRING_DIAB_C_CPP			   "Diab C/C++"
#define Z_COMPILER_STRING_DICE_C			   "DICE C"
#define Z_COMPILER_STRING_DIGITAL_MARS			   "Digital Mars"
#define Z_COMPILER_STRING_DIGNUS_SYSTEMS_C		   "Dignus Systems/C"
#define Z_COMPILER_STRING_DIGNUS_SYSTEMS_CPP		   "Dignus Systems/C++"
#define Z_COMPILER_STRING_DJGPP				   "DJGPP"
#define Z_COMPILER_STRING_EDG_CPP_FRONTEND		   "EDG C++ Frontend"
#define Z_COMPILER_STRING_EKOPARH			   "EKOPath"
#define Z_COMPILER_STRING_FUJITSU_CPP			   "Fujitsu C++"
#define Z_COMPILER_STRING_GREEN_HILL_C_CPP		   "Green Hill C/C++"
#define Z_COMPILER_STRING_HP_ACPP			   "HP aC++"
#define Z_COMPILER_STRING_HP_ANSI_C			   "HP ANSI C"
#define Z_COMPILER_STRING_HP_UPC			   "HP UPC"
#define Z_COMPILER_STRING_IAR_C_CPP			   "IAR C/C++"
#define Z_COMPILER_STRING_IBM_XL_C_CPP			   "IBM XL C/C++"
#define Z_COMPILER_STRING_VISUAL_AGE_CPP		   "VisualAge C++" /* Renamed to IBM XL C/C++ */
#define Z_COMPILER_STRING_IBM_Z_OS_C_CPP		   "IBM z/OS C/C++"
#define Z_COMPILER_STRING_IMAGECRAFT_C			   "ImageCraft C"
#define Z_COMPILER_STRING_INTEL_CPP			   "Intel C++"
#define Z_COMPILER_STRING_KAI_CPP			   "KAI C++"
#define Z_COMPILER_STRING_KEIL_C166			   "KEIL C166"
#define Z_COMPILER_STRING_KEIL_C51			   "KEIL C51"
#define Z_COMPILER_STRING_KEIL_CARM			   "KEIL CARM" /* Discontinued – Replaced by ARM RealView C/C++ Compiler */
#define Z_COMPILER_STRING_LCC				   "LLC"
#define Z_COMPILER_STRING_METAWARE_HIGH_C_CPP		   "MetaWare High C/C++"
#define Z_COMPILER_STRING_MICROTEC_C_CPP		   "Microtec C/C++"
#define Z_COMPILER_STRING_MICROWAY_NDP_C		   "Microway NDP C"
#define Z_COMPILER_STRING_MINGW				   "MinGW"
#define Z_COMPILER_STRING_MIPS_PRO			   "MIPSpro"
#define Z_COMPILER_STRING_MIRACLE_C			   "Miracle C"
#define Z_COMPILER_STRING_MPW_CPP			   "MPW C++"
#define Z_COMPILER_STRING_NORCROFT_C			   "Norcroft C"
#define Z_COMPILER_STRING_NWCC				   "NWCC"
#define Z_COMPILER_STRING_OPEN64			   "Open64"
#define Z_COMPILER_STRING_ORACLE_PRO_C_PRECOMPILER	   "Oracle Pro*C Precompiler"
#define Z_COMPILER_STRING_ORACLE_SOLARIS_STUDIO		   "Oracle Solaris Studio"
#define Z_COMPILER_STRING_SUN_STUDIO			   "Sun Studio"
#define Z_COMPILER_STRING_SUN_WORK_SHOP			   "Sun WorkShop"
#define Z_COMPILER_STRING_FORTE_DEVELOPER		   "Forte Developer"
#define Z_COMPILER_STRING_SUN_PRO_COMPILERS		   "SunPro Compilers"
#define Z_COMPILER_STRING_PACIFIC_C			   "Pacific C"
#define Z_COMPILER_STRING_PALM_C_CPP			   "Palm C/C++"
#define Z_COMPILER_STRING_PELLES_C			   "Pelles C"
#define Z_COMPILER_STRING_PGI_C_CPP			   "PGI C/C++"
#define Z_COMPILER_STRING_RENESAS_C_CPP			   "Renesas C/C++"
#define Z_COMPILER_STRING_SAS_C				   "SAS/C"
#define Z_COMPILER_STRING_SCO_OPEN_SERVER		   "SCO OpenServer"
#define Z_COMPILER_STRING_SMALL_DEVICE_C_COMPILER	   "Small Device C Compiler"
#define Z_COMPILER_STRING_SN_COMPILER			   "SN Compiler"
#define Z_COMPILER_STRING_STRATUS_VOS_C			   "Stratus VOS C"
#define Z_COMPILER_STRING_SYMANTEC_CPP			   "Symantec C++"
#define Z_COMPILER_STRING_TENDRA_C_CPP			   "TenDRA C - C++"
#define Z_COMPILER_STRING_TEXAS_INSTRUMENTS_C_CPP_COMPILER "Texas Instruments C/C++ Compiler"
#define Z_COMPILER_STRING_THINK_C			   "THINK C"
#define Z_COMPILER_STRING_TINY_C			   "Tiny C"
#define Z_COMPILER_STRING_TURBO_C_CPP			   "Turbo C/C++"
#define Z_COMPILER_STRING_ULTIMATE_C_CPP		   "Ultimate C/C++"
#define Z_COMPILER_STRING_USL_C				   "USL C"
#define Z_COMPILER_STRING_VBCC				   "VBCC"
#define Z_COMPILER_STRING_WATCOM_C_CPP			   "Watcom C/C++"
#define Z_COMPILER_STRING_ZORTECH_CPP			   "Zortech C++"

#endif /* __Z_keys_compiler_H__ */
