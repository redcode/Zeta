/* Z Kit - functions/casting.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2019 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_functions_casting_HPP_
#define Z_functions_casting_HPP_

#include <Z/traits/Type.hpp>

#if Z_DIALECT_HAS(CPP, RVALUE_REFERENCE)

	namespace Zeta {


		template <class T>
		static Z_CT(CPP14) T &&to_forwardable(typename Type<T>::remove_reference &what) Z_NOTHROW
			{return static_cast<T &&>(what);}


		template <class T>
		static Z_CT(CPP14) T &&to_forwardable(typename Type<T>::remove_reference &&what) Z_NOTHROW
			{return static_cast<T &&>(what);}


		template <class T>
		static Z_CT(CPP14) typename Type<T>::remove_reference &&to_movable(T &&what) Z_NOTHROW
			{return static_cast<typename Type<T>::remove_reference &&>(what);}


	}

#endif

#endif // Z_functions_casting_HPP_
