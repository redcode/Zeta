/* Q C API - configuration/module.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#include <Q/macros/preprocessor.h>

#if Q_JOIN_2_DEFINED(MODULE_NAME, _PREFIX)
#	undef  MODULE_PREFIX
#	define MODULE_PREFIX Q_JOIN_2(MODULE_NAME, _PREFIX)
#endif

#define SYMBOL(symbol) Q_JOIN_2(MODULE_PREFIX, symbol)

#if defined(BUILDING_HYBRID_MODULE) || Q_JOIN_2_DEFINED(MODULE_NAME, _USE_PUBLIC_SYMBOLS)
#	define EXPORTED(type, symbol)	     type SYMBOL(symbol)
#else
#	define EXPORTED(type, symbol) static type SYMBOL(symbol)
#endif

#if Q_JOIN_2_DEFINED(MODULE_NAME, _HEADER)
#	include Q_HEADER(Q_JOIN_2(MODULE_NAME, _HEADER))
#elif Q_JOIN_2_DEFINED(MODULE_NAME, _LOCAL_HEADER)
#	include Q_LOCAL_HEADER(Q_JOIN_2(MODULE_NAME, _LOCAL_HEADER))
#elif defined(MODULE_HEADER)
#	include MODULE_HEADER
#endif
