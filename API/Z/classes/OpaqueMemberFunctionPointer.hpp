/* Z Kit - classes/OpaqueMemberFunctionPointer.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2019 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_classes_OpaqueMemberFunctionPointer_HPP_
#define Z_classes_OpaqueMemberFunctionPointer_HPP_

#include <Z/types/fundamental.hpp>


namespace Zeta {struct OpaqueMemberFunctionPointer {
	void (NaT::* function)();


	template <class M>
	Z_INLINE OpaqueMemberFunctionPointer(M function) Z_NOTHROW
	: function((void (NaT::*)())function) {}


	template <class M>
	Z_INLINE operator M() const Z_NOTHROW
		{return (M)function;}
};}


#endif // Z_classes_OpaqueMemberFunctionPointer_HPP_
