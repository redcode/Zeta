/* Zeta API - Z/functions/casting.hpp
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_functions_casting_HPP
#define Z_functions_casting_HPP

#include <Z/traits/type.hpp>

#if Z_DIALECT_HAS(CPP11, RVALUE_REFERENCE)
#	define Z_HAS_forwardable 1
#	define Z_HAS_movable     1


	namespace Zeta {
		template <class t>
		static Z_CT(CPP11) t &&forwardable(typename Type<t>::remove_reference &what) Z_NOTHROW
			{return static_cast<t &&>(what);}


		template <class t>
		static Z_CT(CPP11) t &&forwardable(typename Type<t>::remove_reference &&what) Z_NOTHROW
			{return static_cast<t &&>(what);}


		template <class t>
		static Z_CT(CPP11) typename Type<t>::remove_reference &&movable(t &&what) Z_NOTHROW
			{return static_cast<typename Type<t>::remove_reference &&>(what);}
	}


#	if	Z_HAS_MEMBER(Type, is_copy_constructible) && \
		Z_HAS_MEMBER(Type, is_nothrow_move_constructible)

#		include <Z/traits/control.hpp>

#		define Z_HAS_movable_if_nothrow 1

		namespace Zeta {
			// TODO: Revisar
			template <class t>
			static Z_CT(CPP11) typename TernaryType<
				Type<t>::is_copy_constructible && !Type<t>::is_nothrow_move_constructible,
				const t&, t&&
			>::type
			movable_if_nothrow(t &what) Z_NOTHROW
				{return movable(what);}
		}


#	endif
#endif

#endif // Z_functions_casting_HPP
