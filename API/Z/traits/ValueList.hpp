/* Z Kit - traits/ValueList.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//__/__| Kit
Copyright (C) 2006-2020 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_traits_ValueList_HPP
#define Z_traits_ValueList_HPP

#include <Z/inspection/language.h>


namespace Zeta {

	template <class T, T... values> struct {

		typedef typename ValueListRemoveFirst<ValueList>::type remove_first;
		typedef typename ValueListRemoveFirst<ValueList>::type remove_last;
		typedef typename ValueListReverse    <ValueList>::type reverse;

#		if Z_DIALECT_HAS(CPP, VARIABLE_TEMPLATE) && Z_DIALECT_HAS_SPECIFIER(CPP, CONSTEXPR)

#		endif

	};

}


#endif // Z_traits_ValueList_HPP
