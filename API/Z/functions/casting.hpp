/* Z Kit - functions/casting.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//__/__| Kit
Copyright (C) 2006-2020 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_functions_casting_HPP
#define Z_functions_casting_HPP

#include <Z/traits/Type.hpp>

#if Z_DIALECT_HAS(CPP, RVALUE_REFERENCE)

	namespace Zeta {


		template <class T>
		static Z_CT(CPP11) T &&forwardable(typename Type<T>::remove_reference &what) Z_NOTHROW
			{return static_cast<T &&>(what);}


		template <class T>
		static Z_CT(CPP11) T &&forwardable(typename Type<T>::remove_reference &&what) Z_NOTHROW
			{return static_cast<T &&>(what);}


		template <class T>
		static Z_CT(CPP11) typename Type<T>::remove_reference &&movable(T &&what) Z_NOTHROW
			{return static_cast<typename Type<T>::remove_reference &&>(what);}


	}

#	define Z_DECLARES_forwardable TRUE
#	define Z_DECLARES_movable     TRUE
#else
#	define Z_DECLARES_forwardable FALSE
#	define Z_DECLARES_movable     FALSE
#endif

#endif // Z_functions_casting_HPP
