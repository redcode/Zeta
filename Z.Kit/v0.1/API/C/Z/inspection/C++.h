/* Z Kit C API - inspection/C++.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_inspection_CPP_H__
#define __Z_inspection_CPP_H__

#if defined(Z_USE_CPP17)
#	include <Z/inspection/private/C++/C++17.h>

#elif defined(Z_USE_CPP14)
#	include <Z/inspection/private/C++/C++14.h>

#elif defined(Z_USE_CPP11)
#	include <Z/inspection/private/C++/C++11.h>

#elif defined(Z_USE_CPP07_TR1)
#	include <Z/inspection/private/C++/C++07 TR1.h>

#elif defined(Z_USE_CPP03)
#	include <Z/inspection/private/C++/C++03.h>

#elif defined(Z_USE_CPP98)
#	include <Z/inspection/private/C++/C++98.h>

#elif defined(Z_USE_CPP89)
#	include <Z/inspection/private/C++/C++89.h> /* C++ v2.0 */

#elif defined(Z_USE_CPP85)
#	include <Z/inspection/private/C++/C++85.h>

#elif defined(__cplusplus)

#	if __cplusplus >= 201402L
#		include <Z/inspection/private/C++/C++14.h>

#	elif __cplusplus >= 201103L
#		include <Z/inspection/private/C++/C++11.h>

#	elif __cplusplus >= 199711L
#		include <Z/inspection/private/C++/C++98.h>

#	else
#		include <Z/inspection/private/C++/C++85.h>
#	endif
#endif

#define Z_CPP_HAS(		 WHAT ) (defined Z_CPP_HAS_##WHAT		 )
#define Z_CPP_HAS_TYPE(		 WHICH) (defined Z_CPP_HAS_TYPE_##WHICH		 )
#define Z_CPP_HAS_TYPE_QUALIFIER(WHICH) (defined Z_CPP_HAS_TYPE_QUALIFIER_##WHICH)
#define Z_CPP_HAS_STORAGE_CLASS( WHICH) (defined Z_CPP_HAS_STORAGE_CLASS_##WHICH )
#define Z_CPP_HAS_SPECIFIER(	 WHICH) (defined Z_CPP_HAS_SPECIFIER_##WHICH     )
#define Z_CPP_HAS_OPERATOR(	 WHICH) (defined Z_CPP_HAS_OPERATOR_##WHICH      )

#endif /* __Z_inspection_CPP_H__ */
