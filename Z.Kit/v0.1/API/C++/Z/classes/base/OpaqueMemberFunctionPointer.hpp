/* Z Kit C++ API - classes/base/OpaqueMemberFunctionPointer.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_classes_base_OpaqueMemberFunctionPointer_HPP__
#define __Z_classes_base_OpaqueMemberFunctionPointer_HPP__

#include <Z/traits/base.hpp>


namespace Zeta {struct OpaqueMemberFunctionPointer {
	void (NaT::* pointer)();

	template <class T> Z_CT_MEMBER(CPP11) OpaqueMemberFunctionPointer(T pointer)
	: pointer((void (NaT::*)())pointer) {}

	template <class T> Z_CT_MEMBER(CPP11) operator T() const {return (T)pointer;}
};}


#endif // __Z_classes_base_OpaqueMemberFunctionPointer_HPP__
