/* Zeta API - Z/inspection/Objective-C.h
 ______ ____________  ___
|__   /|  ___|__  __|/   \
  /  /_|  __|  |  | /  *  \
 /_____|_____| |__|/__/ \__\
Copyright (C) 2006-2023 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_inspection_Objective_C_H
#define Z_inspection_Objective_C_H

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

#endif /* Z_inspection_Objective_C_H */
