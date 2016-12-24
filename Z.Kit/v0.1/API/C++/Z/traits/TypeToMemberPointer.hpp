/* Z Kit C++ API - traits/TypeToMemberPointer.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_traits_TypeToMemberPointer_HPP__
#define __Z_traits_TypeToMemberPointer_HPP__

#include <Z/inspection/language.h>

namespace Zeta {

#	if Z_LANGUAGE_HAS(CPP, VARIADIC_TEMPLATE)

		template <class T, class C> struct TypeToMemberPointer {typedef T C::*type;};

		template <class C, class R, class... A> struct TypeToMemberPointer<R(A...)		 , C> {typedef R(C::*type)(A...)	       ;};
		template <class C, class R, class... A> struct TypeToMemberPointer<R(A...) const	 , C> {typedef R(C::*type)(A...) const	       ;};
		template <class C, class R, class... A> struct TypeToMemberPointer<R(A...)	 volatile, C> {typedef R(C::*type)(A...)       volatile;};
		template <class C, class R, class... A> struct TypeToMemberPointer<R(A...) const volatile, C> {typedef R(C::*type)(A...) const volatile;};

		template <class C, class R, class... A> struct TypeToMemberPointer<R(A..., ...)		      , C> {typedef R(C::*type)(A...)		    ;};
		template <class C, class R, class... A> struct TypeToMemberPointer<R(A..., ...) const	      , C> {typedef R(C::*type)(A...) const	    ;};
		template <class C, class R, class... A> struct TypeToMemberPointer<R(A..., ...)	      volatile, C> {typedef R(C::*type)(A...)	    volatile;};
		template <class C, class R, class... A> struct TypeToMemberPointer<R(A..., ...) const volatile, C> {typedef R(C::*type)(A...) const volatile;};

#		if Z_LANGUAGE_HAS(CPP, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)

			template <class C, class R, class... A> struct TypeToMemberPointer<R(A...)		  & , C> {typedef R(C::*type)(A...)		   & ;};
			template <class C, class R, class... A> struct TypeToMemberPointer<R(A...)		  &&, C> {typedef R(C::*type)(A...)		   &&;};
			template <class C, class R, class... A> struct TypeToMemberPointer<R(A...) const	  & , C> {typedef R(C::*type)(A...) const	   & ;};
			template <class C, class R, class... A> struct TypeToMemberPointer<R(A...) const	  &&, C> {typedef R(C::*type)(A...) const	   &&;};
			template <class C, class R, class... A> struct TypeToMemberPointer<R(A...)	 volatile & , C> {typedef R(C::*type)(A...)	  volatile & ;};
			template <class C, class R, class... A> struct TypeToMemberPointer<R(A...)	 volatile &&, C> {typedef R(C::*type)(A...)	  volatile &&;};
			template <class C, class R, class... A> struct TypeToMemberPointer<R(A...) const volatile & , C> {typedef R(C::*type)(A...) const volatile & ;};
			template <class C, class R, class... A> struct TypeToMemberPointer<R(A...) const volatile &&, C> {typedef R(C::*type)(A...) const volatile &&;};

			template <class C, class R, class... A> struct TypeToMemberPointer<R(A..., ...)		       & , C> {typedef R(C::*type)(A..., ...)		     & ;};
			template <class C, class R, class... A> struct TypeToMemberPointer<R(A..., ...)		       &&, C> {typedef R(C::*type)(A..., ...)		     &&;};
			template <class C, class R, class... A> struct TypeToMemberPointer<R(A..., ...) const	       & , C> {typedef R(C::*type)(A..., ...) const	     & ;};
			template <class C, class R, class... A> struct TypeToMemberPointer<R(A..., ...) const	       &&, C> {typedef R(C::*type)(A..., ...) const	     &&;};
			template <class C, class R, class... A> struct TypeToMemberPointer<R(A..., ...)	      volatile & , C> {typedef R(C::*type)(A..., ...)	    volatile & ;};
			template <class C, class R, class... A> struct TypeToMemberPointer<R(A..., ...)	      volatile &&, C> {typedef R(C::*type)(A..., ...)	    volatile &&;};
			template <class C, class R, class... A> struct TypeToMemberPointer<R(A..., ...) const volatile & , C> {typedef R(C::*type)(A..., ...) const volatile & ;};
			template <class C, class R, class... A> struct TypeToMemberPointer<R(A..., ...) const volatile &&, C> {typedef R(C::*type)(A..., ...) const volatile &&;};

#		endif

#	endif

}

#endif // __Z_traits_TypeToMemberPointer_HPP__
