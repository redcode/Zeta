/* Q API - macros/optional.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2012 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_macros_optional_H__
#define __Q_macros_optional_H__

#include <Q/types/basics.h>

#if Q_POINTER_BITS == 32

#	define Q_IF_32BIT_POINTER_CODE(		 code)		 code
#	define Q_IF_32BIT_POINTER_CODE_AND_COMMA(code)		 code,
#	define Q_IF_32BIT_POINTER_COMMA_AND_CODE(code)		,code

#	define Q_IF_64BIT_POINTER_CODE(		 code)
#	define Q_IF_64BIT_POINTER_CODE_AND_COMMA(code)
#	define Q_IF_64BIT_POINTER_COMMA_AND_CODE(code)

#elif Q_POINTER_BITS == 64

#	define Q_IF_32BIT_POINTER_CODE(		 code)
#	define Q_IF_32BIT_POINTER_CODE_AND_COMMA(code)
#	define Q_IF_32BIT_POINTER_COMMA_AND_CODE(code)

#	define Q_IF_64BIT_POINTER_CODE(		 code)		 code
#	define Q_IF_64BIT_POINTER_CODE_AND_COMMA(code)		 code,
#	define Q_IF_64BIT_POINTER_COMMA_AND_CODE(code)		,code

#endif

#if Q_IS_AVAILABLE(UINT128)

#	define Q_IF_UINT128_IS_AVAILABLE_CODE(		code)	 code
#	define Q_IF_UINT128_IS_AVAILABLE_CODE_AND_COMMA(code)	 code,
#	define Q_IF_UINT128_IS_AVAILABLE_COMMA_AND_CODE(code)	,code

#else

#	define Q_IF_UINT128_IS_AVAILABLE_CODE(		code)
#	define Q_IF_UINT128_IS_AVAILABLE_CODE_AND_COMMA(code)
#	define Q_IF_UINT128_IS_AVAILABLE_COMMA_AND_CODE(code)

#endif

#if Q_IS_AVAILABLE(INT128)

#	define Q_IF_INT128_IS_AVAILABLE_CODE(	       code)	 code
#	define Q_IF_INT128_IS_AVAILABLE_CODE_AND_COMMA(code)	 code,
#	define Q_IF_INT128_IS_AVAILABLE_COMMA_AND_CODE(code)	,code

#else

#	define Q_IF_INT128_IS_AVAILABLE_CODE(	       code)
#	define Q_IF_INT128_IS_AVAILABLE_CODE_AND_COMMA(code)
#	define Q_IF_INT128_IS_AVAILABLE_COMMA_AND_CODE(code)

#endif

#if Q_LDOUBLE_BITS == Q_DOUBLE_BITS

#	define Q_IF_TRUE_LDOUBLE_CODE(		code)		 code
#	define Q_IF_TRUE_LDOUBLE_CODE_AND_COMMA(code)		 code,
#	define Q_IF_TRUE_LDOUBLE_COMMA_AND_CODE(code)		,code

#else

#	define Q_IF_TRUE_LDOUBLE_CODE(		code)
#	define Q_IF_TRUE_LDOUBLE_CODE_AND_COMMA(code)
#	define Q_IF_TRUE_LDOUBLE_COMMA_AND_CODE(code)

#endif

#endif /* __Q_macros_optional_H__ */
