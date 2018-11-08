/* Z Kit - classes/base/OpaqueMemberFunctionPointer.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_classes_base_OpaqueMemberFunctionPointer_HPP_
#define _Z_classes_base_OpaqueMemberFunctionPointer_HPP_

#include <Z/types/base.hpp>


namespace Zeta {struct OpaqueMemberFunctionPointer {
	void (NaT::* function)();

	template <class M>
	Z_INLINE OpaqueMemberFunctionPointer(M function)
	: function((void (NaT::*)())function) {}

	template <class M>
	Z_INLINE operator M() const {return (M)function;}
};}


#endif // _Z_classes_base_OpaqueMemberFunctionPointer_HPP_
