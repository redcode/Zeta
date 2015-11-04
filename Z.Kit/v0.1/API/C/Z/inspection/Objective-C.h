/* Z Kit C API - inspection/Objective-C.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_inspection_Objective_C_H__
#define __Z_inspection_Objective_C_H__

#if defined(Z_USE_OBJECTIVE_C_2_0) || defined(__OBJC2__)
#	include <Z/inspection/private/Objective-C/Objective-C v2.0.h>

#elif defined(Z_USE_OBJECTIVE_C_1_0) || defined(__OBJC__)
#	include <Z/inspection/private/Objective-C/Objective-C v1.0.h>
#endif

#define Z_OBJECTIVE_C_HAS(		 WHAT ) (defined Z_OBJECTIVE_C_HAS_##WHAT		 )
#define Z_OBJECTIVE_C_HAS_TYPE(		 WHICH) (defined Z_OBJECTIVE_C_HAS_TYPE_##WHICH		 )
#define Z_OBJECTIVE_C_HAS_TYPE_QUALIFIER(WHICH) (defined Z_OBJECTIVE_C_HAS_TYPE_QUALIFIER_##WHICH)
#define Z_OBJECTIVE_C_HAS_STORAGE_CLASS( WHICH) (defined Z_OBJECTIVE_C_HAS_STORAGE_CLASS_##WHICH )
#define Z_OBJECTIVE_C_HAS_SPECIFIER(	 WHICH) (defined Z_OBJECTIVE_C_HAS_SPECIFIER_##WHICH	 )
#define Z_OBJECTIVE_C_HAS_OPERATOR(	 WHICH) (defined Z_OBJECTIVE_C_HAS_OPERATOR_##WHICH	 )

#endif /* __Z_inspection_Objective_C_H__ */
