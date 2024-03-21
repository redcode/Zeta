/* Zeta API - Z/traits/casting.hpp
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_traits_casting_HPP
#define Z_traits_casting_HPP

#include <Z/macros/language.hpp>

namespace Zeta {
	template <class to> struct Cast {typedef to type;};

#	if Z_DIALECT_HAS(CPP11, TYPE_ALIAS_TEMPLATE)
#		define Z_HAS_cast 1
		template <class to> using cast = to;
#	endif

#	if	Z_DIALECT_HAS(CPP11, DIRECT_LIST_INITIALIZATION) && \
		Z_DIALECT_HAS(CPP17, DEDUCTION_GUIDES_FOR_CLASS_TEMPLATE)

#		define Z_HAS_auto_cast 1

		template <class from> struct auto_cast {
			const from &value;

			explicit Z_CT(CPP11) auto_cast(const from &value_) Z_NOTHROW
			: value{value_} {}

			template <class to>
			Z_CT(CPP11) operator to() const Z_NOTHROW
				{return to(value);}
		};
#	endif
}

#endif // Z_traits_casting_HPP
