/* Z Kit - classes/OpaqueMemberFunctionPointer.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2019 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_classes_OpaqueMemberFunctionPointer_HPP
#define Z_classes_OpaqueMemberFunctionPointer_HPP

#include <Z/types/fundamental.hpp>


namespace Zeta {struct OpaqueMemberFunctionPointer {
	void (NaT::* function)();


	template <class M>
	Z_INLINE OpaqueMemberFunctionPointer(M function) Z_NOTHROW
	: function(reinterpret_cast<void (NaT::*)()>(function)) {}


	template <class M>
	Z_INLINE operator M() const Z_NOTHROW
		{return reinterpret_cast<M>(function);}
};}


#endif // Z_classes_OpaqueMemberFunctionPointer_HPP
