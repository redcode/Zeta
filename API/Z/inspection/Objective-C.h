/* Z Kit - inspection/Objective-C.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_inspection_Objective_C_H_
#define _Z_inspection_Objective_C_H_

#include <Z/constants/base.h>
#include <Z/keys/Objective-C.h>

#ifndef Z_OBJECTIVE_C
#	if defined(__OBJC2__)
#		define Z_OBJECTIVE_C Z_OBJECTIVE_C_2_0
#	elif defined(__OBJC__)
#		define Z_OBJECTIVE_C Z_OBJECTIVE_C_1_0
#	endif
#endif

#ifdef Z_OBJECTIVE_C

#	if Z_OBJECTIVE_C == Z_OBJECTIVE_C_2_0

#		include <Z/inspection/Objective-C/modules/Objective-C v2.0.h>

#		define Z_OBJECTIVE_C_STRING Z_OBJECTIVE_C_STRING_OBJECTIVE_C_2_0

#	elif Z_OBJECTIVE_C == Z_OBJECTIVE_C_1_0

#		include <Z/inspection/Objective-C/modules/Objective-C v1.0.h>

#		define Z_OBJECTIVE_C_STRING Z_OBJECTIVE_C_STRING_OBJECTIVE_C_1_0

#	endif

#endif

#include <Z/inspection/Objective-C/completion.h>

#define Z_OBJECTIVE_C_HAS(		 WHAT ) Z_OBJECTIVE_C_HAS_##WHAT
#define Z_OBJECTIVE_C_HAS_ATTRIBUTE(	 WHICH) Z_OBJECTIVE_C_HAS_ATTRIBUTE_##WHICH
#define Z_OBJECTIVE_C_HAS_LITERAL(	 WHICH) Z_OBJECTIVE_C_HAS_LITERAL_##WHICH
#define Z_OBJECTIVE_C_HAS_OPERATOR(	 WHICH) Z_OBJECTIVE_C_HAS_OPERATOR_##WHICH
#define Z_OBJECTIVE_C_HAS_SPECIFIER(	 WHICH) Z_OBJECTIVE_C_HAS_SPECIFIER_##WHICH
#define Z_OBJECTIVE_C_HAS_STORAGE_CLASS( WHICH) Z_OBJECTIVE_C_HAS_STORAGE_CLASS_##WHICH
#define Z_OBJECTIVE_C_HAS_TYPE(		 WHICH) Z_OBJECTIVE_C_HAS_TYPE_##WHICH
#define Z_OBJECTIVE_C_HAS_TYPE_QUALIFIER(WHICH) Z_OBJECTIVE_C_HAS_TYPE_QUALIFIER_##WHICH

#endif /* _Z_inspection_Objective_C_H_ */
