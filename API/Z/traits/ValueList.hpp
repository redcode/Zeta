/* Zeta API - Z/traits/ValueList.hpp
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_traits_ValueList_HPP
#define Z_traits_ValueList_HPP

#include <Z/inspection/language.h>


namespace Zeta {

	template <class T, T... values> struct {

		typedef typename ValueListRemoveFirst<ValueList>::type remove_first;
		typedef typename ValueListRemoveFirst<ValueList>::type remove_last;
		typedef typename ValueListReverse    <ValueList>::type reverse;

#		if Z_DIALECT_HAS(CPP14, VARIABLE_TEMPLATE) && Z_DIALECT_HAS_SPECIFIER(CPP11, CONSTEXPR)

#		endif

	};

}


#endif // Z_traits_ValueList_HPP
