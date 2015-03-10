/* Q Kit C API - inspection/C++.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_inspection_CPP_H__
#define __Q_inspection_CPP_H__

#if defined(Q_USE_CPP17)
#	include <Q/inspection/private/C++/C++17.h>

#elif defined(Q_USE_CPP14)
#	include <Q/inspection/private/C++/C++14.h>

#elif defined(Q_USE_CPP11)
#	include <Q/inspection/private/C++/C++11.h>

#elif defined(Q_USE_CPP07_TR1)
#	include <Q/inspection/private/C++/C++07 TR1.h>

#elif defined(Q_USE_CPP03)
#	include <Q/inspection/private/C++/C++03.h>

#if defined(Q_USE_CPP98)
#	include <Q/inspection/private/C++/C++98.h>

#if defined(Q_USE_CPP89)
#	include <Q/inspection/private/C++/C++89.h>

#if defined(Q_USE_CPP85)
#	include <Q/inspection/private/C++/C++85.h>

#elif defined(__cplusplus)

#	if __cplusplus >= 201402L
#		include <Q/inspection/private/C++/C++14.h>

#	elif __cplusplus >= 201103L
#		include <Q/inspection/private/C++/C++11.h>

#	elif __cplusplus >= 199711L
#		include <Q/inspection/private/C++/C++98.h>

#	else
#		include <Q/inspection/private/C++/C++85.h>
#	endif
#endif

#define Q_CPP_HAS(		 WHAT ) (defined Q_CPP_HAS_##WHAT		 )
#define Q_CPP_HAS_TYPE(		 WHICH) (defined Q_CPP_HAS_TYPE_##WHICH		 )
#define Q_CPP_HAS_TYPE_QUALIFIER(WHICH) (defined Q_CPP_HAS_TYPE_QUALIFIER_##WHICH)
#define Q_CPP_HAS_STORAGE_CLASS( WHICH) (defined Q_CPP_HAS_STORAGE_CLASS_##WHICH )
#define Q_CPP_HAS_SPECIFIER(	 WHICH) (defined Q_CPP_HAS_SPECIFIER_##WHICH     )
#define Q_CPP_HAS_OPERATOR(	 WHICH) (defined Q_CPP_HAS_OPERATOR_##WHICH      )

#endif /* __Q_inspection_CPP_H__ */
