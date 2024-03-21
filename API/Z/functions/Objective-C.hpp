/* Zeta API - Z/functions/Objective-C.hpp
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_functions_Objective_C_HPP
#define Z_functions_Objective_C_HPP

#include <Z/traits/type.hpp>
#include <Z/inspection/ISA.h>
#include <objc/message.h>


namespace Zeta {namespace ObjectiveC {
/*
#	if Z_ISA_IS(X86_64)
		template <class rr = r>
		Z_INLINE typename TypeIf<!Type<rr>::is_class, rr>::type
#	elif Z_ISA_IS(X86_32)
		template <class rr = r>
		Z_INLINE typename TypeIf<!Type<rr>::is_class && !Type<rr>::is_real, rr>::type
#	elif Z_ISA_IS(AARCH64)
		Z_INLINE r
#	endif*/


	template <class f>
	static Z_CT(CPP11) decltype(objc_msgSend) *send() Z_NOTHROW
		{return objc_msgSend;}


	template <class f>
	static Z_CT(CPP11) decltype(objc_msgSendSuper) *send_super() Z_NOTHROW
		{return objc_msgSendSuper;}
}}


#endif // Z_functions_Objective_C_HPP
