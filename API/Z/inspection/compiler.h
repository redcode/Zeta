/* Zeta API - Z/inspection/compiler.h
 ______ ____________  ___
|__   /|  ___|__  __|/   \
  /  /_|  __|  |  | /  *  \
 /_____|_____| |__|/__/ \__\
Copyright (C) 2006-2023 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_inspection_compiler_H
#define Z_inspection_compiler_H

#include <Z/keys/compiler.h>
#include <Z/macros/token.h>
#include <Z/macros/version.h>

#define Z_COMPILER_IS(COMPILER) Z_IS_TRUE(Z_COMPILER_IS_##COMPILER)

#define Z_COMPILER_DIALECT_HAS(			       LANGUAGE, FEATURE		) Z_IS_TRUE(Z_COMPILER_HAS_##LANGUAGE##_##FEATURE					 )
#define Z_COMPILER_DIALECT_HAS_ATTRIBUTE(	       LANGUAGE, ATTRIBUTE		) Z_IS_TRUE(Z_COMPILER_HAS_##LANGUAGE##_ATTRIBUTE_##ATTRIBUTE				 )
#define Z_COMPILER_DIALECT_HAS_ESCAPE_SEQUENCE(	       LANGUAGE, ESCAPE_SEQUENCE	) Z_IS_TRUE(Z_COMPILER_HAS_##LANGUAGE##_ESCAPE_SEQUENCE_##ESCAPE_SEQUENCE		 )
#define Z_COMPILER_DIALECT_HAS_IDENTIFIER(	       LANGUAGE, IDENTIFIER		) Z_IS_TRUE(Z_COMPILER_HAS_##LANGUAGE##_IDENTIFIER_##IDENTIFIER				 )
#define Z_COMPILER_DIALECT_HAS_LITERAL(		       LANGUAGE, LITERAL		) Z_IS_TRUE(Z_COMPILER_HAS_##LANGUAGE##_LITERAL_##LITERAL				 )
#define Z_COMPILER_DIALECT_HAS_OPERATOR(	       LANGUAGE, OPERATOR		) Z_IS_TRUE(Z_COMPILER_HAS_##LANGUAGE##_OPERATOR_##OPERATOR				 )
#define Z_COMPILER_DIALECT_HAS_OPERATOR_CASE(	       LANGUAGE, OPERATOR, CASE		) Z_IS_TRUE(Z_COMPILER_HAS_##LANGUAGE##_OPERATOR_CASE_##OPERATOR##_##CASE		 )
#define Z_COMPILER_DIALECT_HAS_PREPROCESSOR_DIRECTIVE( LANGUAGE, PREPROCESSOR_DIRECTIVE ) Z_IS_TRUE(Z_COMPILER_HAS_##LANGUAGE##_PREPROCESSOR_DIRECTIVE_##PREPROCESSOR_DIRECTIVE	 )
#define Z_COMPILER_DIALECT_HAS_PREPROCESSOR_IDENTIFIER(LANGUAGE, PREPROCESSOR_IDENTIFIER) Z_IS_TRUE(Z_COMPILER_HAS_##LANGUAGE##_PREPROCESSOR_IDENTIFIER_##PREPROCESSOR_IDENTIFIER)
#define Z_COMPILER_DIALECT_HAS_PREPROCESSOR_OPERATOR(  LANGUAGE, PREPROCESSOR_OPERATOR	) Z_IS_TRUE(Z_COMPILER_HAS_##LANGUAGE##_PREPROCESSOR_OPERATOR_##PREPROCESSOR_OPERATOR	 )
#define Z_COMPILER_DIALECT_HAS_SPECIFIER(	       LANGUAGE, SPECIFIER		) Z_IS_TRUE(Z_COMPILER_HAS_##LANGUAGE##_SPECIFIER_##SPECIFIER				 )
#define Z_COMPILER_DIALECT_HAS_SPECIFIER_CASE(	       LANGUAGE, SPECIFIER, CASE	) Z_IS_TRUE(Z_COMPILER_HAS_##LANGUAGE##_SPECIFIER_CASE_##SPECIFIER##_##CASE		 )
#define Z_COMPILER_DIALECT_HAS_STD_PRAGMA(	       LANGUAGE, STD_PRAGMA		) Z_IS_TRUE(Z_COMPILER_HAS_##LANGUAGE##_STD_PRAGMA_##STD_PRAGMA				 )
#define Z_COMPILER_DIALECT_HAS_STORAGE_CLASS(	       LANGUAGE, STORAGE_CLASS		) Z_IS_TRUE(Z_COMPILER_HAS_##LANGUAGE##_STORAGE_CLASS_##STORAGE_CLASS			 )
#define Z_COMPILER_DIALECT_HAS_TYPE(		       LANGUAGE, TYPE			) Z_IS_TRUE(Z_COMPILER_HAS_##LANGUAGE##_TYPE_##TYPE					 )
#define Z_COMPILER_DIALECT_HAS_TYPE_MODIFIER(	       LANGUAGE, TYPE_MODIFIER		) Z_IS_TRUE(Z_COMPILER_HAS_##LANGUAGE##_TYPE_MODIFIER_##TYPE_MODIFIER			 )
#define Z_COMPILER_DIALECT_HAS_TYPE_QUALIFIER(	       LANGUAGE, TYPE_QUALIFIER		) Z_IS_TRUE(Z_COMPILER_HAS_##LANGUAGE##_TYPE_QUALIFIER_##TYPE_QUALIFIER			 )

#define Z_COMPILER_HAS(		      FEATURE	    ) Z_IS_TRUE(Z_COMPILER_HAS_##FEATURE		      )
#define Z_COMPILER_HAS_ATTRIBUTE(     ATTRIBUTE	    ) Z_IS_TRUE(Z_COMPILER_HAS_ATTRIBUTE_##ATTRIBUTE	      )
#define Z_COMPILER_HAS_CONSTANT(      CONSTANT	    ) Z_IS_TRUE(Z_COMPILER_HAS_CONSTANT_##CONSTANT	      )
#define Z_COMPILER_HAS_FUNCTION(      FUNCTION	    ) Z_IS_TRUE(Z_COMPILER_HAS_FUNCTION_##FUNCTION	      )
#define Z_COMPILER_HAS_LITERAL(	      LITERAL	    ) Z_IS_TRUE(Z_COMPILER_HAS_LITERAL_##LITERAL	      )
#define Z_COMPILER_HAS_MACRO(	      MACRO	    ) Z_IS_TRUE(Z_COMPILER_HAS_MACRO_##MACRO		      )
#define Z_COMPILER_HAS_MAGIC_CONSTANT(MAGIC_CONSTANT) Z_IS_TRUE(Z_COMPILER_HAS_MAGIC_CONSTANT_##MAGIC_CONSTANT)
#define Z_COMPILER_HAS_TRAIT(	      TRAIT	    ) Z_IS_TRUE(Z_COMPILER_HAS_TRAIT_##TRAIT		      )
#define Z_COMPILER_HAS_TYPE(	      TYPE	    ) Z_IS_TRUE(Z_COMPILER_HAS_TYPE_##TYPE		      )
#define Z_COMPILER_ATTRIBUTE(	      ATTRIBUTE	    ) Z_COMPILER_ATTRIBUTE_##ATTRIBUTE
#define Z_COMPILER_CONSTANT(	      CONSTANT	    ) Z_COMPILER_CONSTANT_##CONSTANT
#define Z_COMPILER_FUNCTION(	      FUNCTION	    ) Z_COMPILER_FUNCTION_##FUNCTION
#define Z_COMPILER_LITERAL(	      LITERAL	    ) Z_COMPILER_LITERAL_##LITERAL
#define Z_COMPILER_MACRO(	      MACRO	    ) Z_COMPILER_MACRO_##MACRO
#define Z_COMPILER_MAGIC_CONSTANT(    MAGIC_CONSTANT) Z_COMPILER_MAGIC_CONSTANT_##MAGIC_CONSTANT
#define Z_COMPILER_TRAIT(	      TRAIT	    ) Z_COMPILER_TRAIT_##TRAIT
#define Z_COMPILER_TYPE(	      TYPE	    ) Z_COMPILER_TYPE_##TYPE

#ifdef Z_COMPILER_HEADER
#	include Z_COMPILER_HEADER

#else
#	ifndef Z_COMPILER
#		include <Z/inspection/compiler/detection.h>
#	endif

/*#	if Z_COMPILER == Z_COMPILER_ACC
#		include <Z/inspection/compiler/modules/ACC.h>
#	elif Z_COMPILER == Z_COMPILER_ALTIUM_C_TO_HARDWARE
#		include <Z/inspection/compiler/modules/Altium C-to-Hardware.h>
#	elif Z_COMPILER == Z_COMPILER_ALTIUM_MICROBLAZE_C
#		include <Z/inspection/compiler/modules/Altium MicroBlaze C.h>
#	elif Z_COMPILER == Z_COMPILER_AMSTERDAM_COMPILER_KIT
#		include <Z/inspection/compiler/modules/Amsterdam Compiler Kit.h>
#	elif Z_COMPILER == Z_COMPILER_APPLE_CLANG
#		include <Z/inspection/compiler/modules/Apple Clang.h>
#	elif Z_COMPILER == Z_COMPILER_ARM_C_CPP_COMPILER
#		include <Z/inspection/compiler/modules/ARM C-C++ Compiler.h>
#	elif Z_COMPILER == Z_COMPILER_ARM_COMPILER
#		include <Z/inspection/compiler/modules/ARM Compiler.h>
#	elif Z_COMPILER == Z_COMPILER_AZTEC_C
#		include <Z/inspection/compiler/modules/Aztec C.h>
#	elif Z_COMPILER == Z_COMPILER_BCC
#		include <Z/inspection/compiler/modules/BCC.h>*/
#	if Z_COMPILER == Z_COMPILER_CC65
#		include <Z/inspection/compiler/modules/cc65.h>
#	elif Z_COMPILER == Z_COMPILER_CLANG
#		include <Z/inspection/compiler/modules/Clang.h>
/*#	elif Z_COMPILER == Z_COMPILER_CODE_WARRIOR
#		include <Z/inspection/compiler/modules/CodeWarrior.h>
#	elif Z_COMPILER == Z_COMPILER_COMEAU_CPP
#		include <Z/inspection/compiler/modules/Comeau C++.h>
#	elif Z_COMPILER == Z_COMPILER_COMPAQ_C_CPP
#		include <Z/inspection/compiler/modules/Compaq C-C++.h>
#	elif Z_COMPILER == Z_COMPILER_COMPCERT
#		include <Z/inspection/compiler/modules/CompCert.h>
#	elif Z_COMPILER == Z_COMPILER_CONVEX_C
#		include <Z/inspection/compiler/modules/Convex C.h>
#	elif Z_COMPILER == Z_COMPILER_COVERITY_C_CPP_STATIC_ANALYZER
#		include <Z/inspection/compiler/modules/Coverity C-C++ Static Analyzer.h>
#	elif Z_COMPILER == Z_COMPILER_CRAY_C
#		include <Z/inspection/compiler/modules/Cray C.h>
#	elif Z_COMPILER == Z_COMPILER_DIAB_C_CPP
#		include <Z/inspection/compiler/modules/Diab C-C++.h>
#	elif Z_COMPILER == Z_COMPILER_DICE_C
#		include <Z/inspection/compiler/modules/DICE C.h>
#	elif Z_COMPILER == Z_COMPILER_DIGITAL_MARS
#		include <Z/inspection/compiler/modules/Digital Mars.h>
#	elif Z_COMPILER == Z_COMPILER_DJGPP
#		include <Z/inspection/compiler/modules/DJGPP.h>
#	elif Z_COMPILER == Z_COMPILER_EDG_CPP_FRONTEND
#		include <Z/inspection/compiler/modules/EDG C++ Frontend.h>
#	elif Z_COMPILER == Z_COMPILER_EKOPATH
#		include <Z/inspection/compiler/modules/EKOPath.h>
#	elif Z_COMPILER == Z_COMPILER_FUJITSU_CPP
#		include <Z/inspection/compiler/modules/Fujitsu C++.h>*/
#	elif Z_COMPILER == Z_COMPILER_GCC
#		include <Z/inspection/compiler/modules/GCC.h>
/*#	elif Z_COMPILER == Z_COMPILER_GREEN_HILL_C_CPP
#		include <Z/inspection/compiler/modules/Green Hill C-C++.h>
#	elif Z_COMPILER == Z_COMPILER_HP_ACPP
#		include <Z/inspection/compiler/modules/HP aC++.h>
#	elif Z_COMPILER == Z_COMPILER_HP_ANSI_C
#		include <Z/inspection/compiler/modules/HP ANSI C.h>
#	elif Z_COMPILER == Z_COMPILER_HP_UPC
#		include <Z/inspection/compiler/modules/HP UPC.h>
#	elif Z_COMPILER == Z_COMPILER_IAR_C_CPP
#		include <Z/inspection/compiler/modules/IAR C-C++.h>
#	elif Z_COMPILER == Z_COMPILER_IBM_XL_C_CPP
#		include <Z/inspection/compiler/modules/IBM XL C-C++.h>
#	elif Z_COMPILER == Z_COMPILER_IBM_Z_OS_C_CPP
#		include <Z/inspection/compiler/modules/IBM z-OS C-C++.h>
#	elif Z_COMPILER == Z_COMPILER_IMAGECRAFT_C
#		include <Z/inspection/compiler/modules/ImageCraft C.h>
#	elif Z_COMPILER == Z_COMPILER_INTEL_CPP
#		include <Z/inspection/compiler/modules/Intel C++.h>
#	elif Z_COMPILER == Z_COMPILER_KAI_CPP
#		include <Z/inspection/compiler/modules/KAI C++.h>
#	elif Z_COMPILER == Z_COMPILER_KEIL_C166
#		include <Z/inspection/compiler/modules/KEIL C166.h>
#	elif Z_COMPILER == Z_COMPILER_KEIL_C51
#		include <Z/inspection/compiler/modules/KEIL C51.h>
#	elif Z_COMPILER == Z_COMPILER_KEIL_CARM
#		include <Z/inspection/compiler/modules/KEIL CARM.h>
#	elif Z_COMPILER == Z_COMPILER_LCC
#		include <Z/inspection/compiler/modules/LCC.h>
#	elif Z_COMPILER == Z_COMPILER_MCC
#		include <Z/inspection/compiler/modules/MCC.h>
#	elif Z_COMPILER == Z_COMPILER_METAWARE_HIGH_C_CPP
#		include <Z/inspection/compiler/modules/MetaWare High C-C++.h>
#	elif Z_COMPILER == Z_COMPILER_MICROTEC_C_CPP
#		include <Z/inspection/compiler/modules/Microtec C-C++.h>
#	elif Z_COMPILER == Z_COMPILER_MINGW
#		include <Z/inspection/compiler/modules/MinGW.h>
#	elif Z_COMPILER == Z_COMPILER_MIPS_PRO
#		include <Z/inspection/compiler/modules/MIPSpro.h>
#	elif Z_COMPILER == Z_COMPILER_MIRACLE_C
#		include <Z/inspection/compiler/modules/Miracle C.h>
#	elif Z_COMPILER == Z_COMPILER_MPW_CPP
#		include <Z/inspection/compiler/modules/MPW C++.h>
#	elif Z_COMPILER == Z_COMPILER_MSC
#		include <Z/inspection/compiler/modules/MSC.h>*/
#	elif Z_COMPILER == Z_COMPILER_MSVC
#		include <Z/inspection/compiler/modules/MSVC.h>
/*#	elif Z_COMPILER == Z_COMPILER_NDP_C
#		include <Z/inspection/compiler/modules/NDP C.h>
#	elif Z_COMPILER == Z_COMPILER_NORCROFT_C
#		include <Z/inspection/compiler/modules/Norcroft C.h>
#	elif Z_COMPILER == Z_COMPILER_NVC
#		include <Z/inspection/compiler/modules/NVC.h>
#	elif Z_COMPILER == Z_COMPILER_NWCC
#		include <Z/inspection/compiler/modules/NWCC.h>
#	elif Z_COMPILER == Z_COMPILER_OPEN64
#		include <Z/inspection/compiler/modules/Open64.h>
#	elif Z_COMPILER == Z_COMPILER_ORACLE_PRO_C_PRECOMPILER
#		include <Z/inspection/compiler/modules/Oracle Pro-C Precompiler.h>
#	elif Z_COMPILER == Z_COMPILER_ORACLE_SOLARIS_STUDIO
#		include <Z/inspection/compiler/modules/Oracle Solaris Studio.h>
#	elif Z_COMPILER == Z_COMPILER_PACIFIC_C
#		include <Z/inspection/compiler/modules/Pacific C.h>
#	elif Z_COMPILER == Z_COMPILER_PALM_C_CPP
#		include <Z/inspection/compiler/modules/Palm C-C++.h>
#	elif Z_COMPILER == Z_COMPILER_PCC
#		include <Z/inspection/compiler/modules/PCC.h>
#	elif Z_COMPILER == Z_COMPILER_PELLES_C
#		include <Z/inspection/compiler/modules/Pelles C.h>
#	elif Z_COMPILER == Z_COMPILER_PGI_C_CPP
#		include <Z/inspection/compiler/modules/PGI C-C++.h>
#	elif Z_COMPILER == Z_COMPILER_RENESAS_C_CPP
#		include <Z/inspection/compiler/modules/Renesas C-C++.h>
#	elif Z_COMPILER == Z_COMPILER_SAS_C
#		include <Z/inspection/compiler/modules/SAS-C.h>
#	elif Z_COMPILER == Z_COMPILER_SCCZ80
#		include <Z/inspection/compiler/modules/SCCZ80.h>
#	elif Z_COMPILER == Z_COMPILER_SDCC
#		include <Z/inspection/compiler/modules/SDCC.h>
#	elif Z_COMPILER == Z_COMPILER_SNC
#		include <Z/inspection/compiler/modules/SNC.h>
#	elif Z_COMPILER == Z_COMPILER_SYMANTEC_CPP
#		include <Z/inspection/compiler/modules/Symantec C++.h>
#	elif Z_COMPILER == Z_COMPILER_SYSTEMS_C
#		include <Z/inspection/compiler/modules/Systems-C.h>
#	elif Z_COMPILER == Z_COMPILER_TENDRA
#		include <Z/inspection/compiler/modules/TenDRA.h>
#	elif Z_COMPILER == Z_COMPILER_THINK_C
#		include <Z/inspection/compiler/modules/THINK C.h>
#	elif Z_COMPILER == Z_COMPILER_TI_C_CPP_COMPILER
#		include <Z/inspection/compiler/modules/Texas Instruments C-C++ Compiler.h>*/
#	elif Z_COMPILER == Z_COMPILER_TINY_CC
#		include <Z/inspection/compiler/modules/TinyCC.h>
/*#	elif Z_COMPILER == Z_COMPILER_TURBO_C
#		include <Z/inspection/compiler/modules/Turbo C.h>
#	elif Z_COMPILER == Z_COMPILER_TURBO_CPP
#		include <Z/inspection/compiler/modules/Turbo C++.h>
#	elif Z_COMPILER == Z_COMPILER_ULTRA_C_CPP
#		include <Z/inspection/compiler/modules/Ultra C-C++.h>
#	elif Z_COMPILER == Z_COMPILER_USL
#		include <Z/inspection/compiler/modules/USL.h>
#	elif Z_COMPILER == Z_COMPILER_VBCC
#		include <Z/inspection/compiler/modules/vbcc.h>
#	elif Z_COMPILER == Z_COMPILER_VOS_C
#		include <Z/inspection/compiler/modules/VOS C.h>
#	elif Z_COMPILER == Z_COMPILER_VOS_STANDARD_C
#		include <Z/inspection/compiler/modules/VOS Standard C.h>
#	elif Z_COMPILER == Z_COMPILER_WATCOM_C_CPP
#		include <Z/inspection/compiler/modules/Watcom C-C++.h>
#	elif Z_COMPILER == Z_COMPILER_ZORTECH_CPP
#		include <Z/inspection/compiler/modules/Zortech C++.h>*/
#	elif Z_COMPILER == Z_COMPILER_UNKNOWN
#		include <Z/inspection/compiler/modules/generic.h>
#	else
#		error "Invalid Z_COMPILER key."
#	endif
#endif

#include <Z/inspection/compiler/completion.h>

#ifdef Z_COMPILER_BIT_FIELD_ORDER_ALL
#	define Z_COMPILER_BIT_FIELD_ORDER(bits) Z_COMPILER_BIT_FIELD_ORDER_ALL
#else
#	define Z_COMPILER_BIT_FIELD_ORDER(bits) Z_COMPILER_BIT_FIELD_ORDER_##bits##BIT
#endif

#ifndef Z_COMPILER_DEFINE_PACKED_STRUCTURE_BEFORE_TYPEDEF
#	define Z_COMPILER_DEFINE_PACKED_STRUCTURE_BEFORE_TYPEDEF
#endif

#ifndef Z_COMPILER_DEFINE_PACKED_STRUCTURE_BEFORE_STRUCT
#	define Z_COMPILER_DEFINE_PACKED_STRUCTURE_BEFORE_STRUCT
#endif

#ifndef Z_COMPILER_DEFINE_PACKED_STRUCTURE_BEFORE_BODY
#	define Z_COMPILER_DEFINE_PACKED_STRUCTURE_BEFORE_BODY
#endif

#ifndef Z_COMPILER_DEFINE_PACKED_STRUCTURE_BEFORE_TYPE
#	define Z_COMPILER_DEFINE_PACKED_STRUCTURE_BEFORE_TYPE
#endif

#ifndef Z_COMPILER_DEFINE_PACKED_STRUCTURE_AFTER_TYPE
#	define Z_COMPILER_DEFINE_PACKED_STRUCTURE_AFTER_TYPE
#endif

#ifndef Z_COMPILER_DEFINE_PACKED_UNION_BEFORE_TYPEDEF
#	define Z_COMPILER_DEFINE_PACKED_UNION_BEFORE_TYPEDEF
#endif

#ifndef Z_COMPILER_DEFINE_PACKED_UNION_BEFORE_UNION
#	define Z_COMPILER_DEFINE_PACKED_UNION_BEFORE_UNION
#endif

#ifndef Z_COMPILER_DEFINE_PACKED_UNION_BEFORE_BODY
#	define Z_COMPILER_DEFINE_PACKED_UNION_BEFORE_BODY
#endif

#ifndef Z_COMPILER_DEFINE_PACKED_UNION_BEFORE_TYPE
#	define Z_COMPILER_DEFINE_PACKED_UNION_BEFORE_TYPE
#endif

#ifndef Z_COMPILER_DEFINE_PACKED_UNION_AFTER_TYPE
#	define Z_COMPILER_DEFINE_PACKED_UNION_AFTER_TYPE
#endif

#ifndef Z_COMPILER_PACKED_NAMED_STRUCTURE_BEFORE_STRUCT
#	define Z_COMPILER_PACKED_NAMED_STRUCTURE_BEFORE_STRUCT
#endif

#ifndef Z_COMPILER_PACKED_NAMED_STRUCTURE_BEFORE_TYPE
#	define Z_COMPILER_PACKED_NAMED_STRUCTURE_BEFORE_TYPE
#endif

#ifndef Z_COMPILER_PACKED_NAMED_STRUCTURE_BEFORE_BODY
#	define Z_COMPILER_PACKED_NAMED_STRUCTURE_BEFORE_BODY
#endif

#ifndef Z_COMPILER_PACKED_NAMED_STRUCTURE_AFTER_BODY
#	define Z_COMPILER_PACKED_NAMED_STRUCTURE_AFTER_BODY
#endif

#ifndef Z_COMPILER_PACKED_NAMED_UNION_BEFORE_UNION
#	define Z_COMPILER_PACKED_NAMED_UNION_BEFORE_UNION
#endif

#ifndef Z_COMPILER_PACKED_NAMED_UNION_BEFORE_TYPE
#	define Z_COMPILER_PACKED_NAMED_UNION_BEFORE_TYPE
#endif

#ifndef Z_COMPILER_PACKED_NAMED_UNION_BEFORE_BODY
#	define Z_COMPILER_PACKED_NAMED_UNION_BEFORE_BODY
#endif

#ifndef Z_COMPILER_PACKED_NAMED_UNION_AFTER_BODY
#	define Z_COMPILER_PACKED_NAMED_UNION_AFTER_BODY
#endif

#ifndef Z_COMPILER_PACKED_UNNAMED_STRUTURE_BEFORE_STRUCT
#	define Z_COMPILER_PACKED_UNNAMED_STRUTURE_BEFORE_STRUCT
#endif

#ifndef Z_COMPILER_PACKED_UNNAMED_STRUTURE_BEFORE_BODY
#	define Z_COMPILER_PACKED_UNNAMED_STRUTURE_BEFORE_BODY
#endif

#ifndef Z_COMPILER_PACKED_UNNAMED_STRUTURE_BEFORE_IDENTIFIER
#	define Z_COMPILER_PACKED_UNNAMED_STRUTURE_BEFORE_IDENTIFIER
#endif

#ifndef Z_COMPILER_PACKED_UNNAMED_STRUTURE_AFTER_IDENTIFIER
#	define Z_COMPILER_PACKED_UNNAMED_STRUTURE_AFTER_IDENTIFIER
#endif

#ifndef Z_COMPILER_PACKED_UNNAMED_UNION_BEFORE_STRUCT
#	define Z_COMPILER_PACKED_UNNAMED_UNION_BEFORE_STRUCT
#endif

#ifndef Z_COMPILER_PACKED_UNNAMED_UNION_BEFORE_BODY
#	define Z_COMPILER_PACKED_UNNAMED_UNION_BEFORE_BODY
#endif

#ifndef Z_COMPILER_PACKED_UNNAMED_UNION_BEFORE_IDENTIFIER
#	define Z_COMPILER_PACKED_UNNAMED_UNION_BEFORE_IDENTIFIER
#endif

#ifndef Z_COMPILER_PACKED_UNNAMED_UNION_AFTER_IDENTIFIER
#	define Z_COMPILER_PACKED_UNNAMED_UNION_AFTER_IDENTIFIER
#endif

#endif /* Z_inspection_compiler_H */
