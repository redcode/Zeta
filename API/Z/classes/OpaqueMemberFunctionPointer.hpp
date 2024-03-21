/* Zeta API - Z/classes/OpaqueMemberFunctionPointer.hpp
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_classes_OpaqueMemberFunctionPointer_HPP
#define Z_classes_OpaqueMemberFunctionPointer_HPP

#include <Z/classes/NaT.hpp>


namespace Zeta {struct OpaqueMemberFunctionPointer {
	void (NaT::* value)();


	template <class m>
	Z_INLINE OpaqueMemberFunctionPointer(m pointer) Z_NOTHROW
	: value(reinterpret_cast<void (NaT::*)()>(pointer)) {}


	template <class m>
	Z_INLINE operator m() const Z_NOTHROW
		{return reinterpret_cast<m>(value);}
};}


#endif // Z_classes_OpaqueMemberFunctionPointer_HPP
