/* Zeta API - Z/functions/class.hpp
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_functions_class_HPP
#define Z_functions_class_HPP

#include <Z/constants/pointer.h>
#include <Z/types/integral.hpp>
#include <Z/traits/type.hpp>
#include <new>
namespace Zeta {


	template <class t, class c>
	static Z_INLINE USize member_offset(t c::*member) Z_NOTHROW
		{
		return (&reinterpret_cast<const Char &>(reinterpret_cast<const c *>(sizeof(c))->*member) -
			reinterpret_cast<const Char *>(sizeof(c)));
		}


	typedef void *(* DefaultInstantiator)();
	typedef void  (* DefaultConstructor )(void *object);
	typedef void  (* Deleter	    )(void *object);
	typedef void  (* Destructor	    )(void *object);


#	if Z_DIALECT_HAS(CPP11, LAMBDA)

		template <class t>
		static Z_CT(CPP11) typename TypeIf<
			Type<t>::is_class && Type<t>::is_default_constructible,
			DefaultConstructor
		>::type
		default_constructor() Z_NOTHROW
			{return [](void *object) -> void {new (object) t;};}


		template <class t>
		static Z_CT(CPP11) typename TypeIf<
			!Type<t>::is_class || !Type<t>::is_default_constructible,
			DefaultConstructor
		>::type
		default_constructor() Z_NOTHROW
			{return Z_NULL;}


		template <class t>
		static Z_CT(CPP11) typename TypeIf<
			Type<t>::is_class && Type<t>::is_default_constructible,
			DefaultInstantiator
		>::type
		default_instantiator() Z_NOTHROW
			{return []() -> void* {return new t();};}


		template <class t>
		static Z_CT(CPP11) typename TypeIf<
			!Type<t>::is_class || !Type<t>::is_default_constructible,
			DefaultInstantiator
		>::type
		default_instantiator() Z_NOTHROW
			{return Z_NULL;}


		template <class t>
		static Z_CT(CPP11) Destructor destructor() Z_NOTHROW
			{return [](void *object) -> void {reinterpret_cast<const t *>(object)->~t();};}


		template <class t>
		static Z_CT(CPP11) Deleter deleter() Z_NOTHROW
			{return [](void *object) -> void {delete reinterpret_cast<t *>(object);};}

#	endif
}

#endif // Z_functions_class_HPP
