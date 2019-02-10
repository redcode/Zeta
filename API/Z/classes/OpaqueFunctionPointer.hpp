/* Z Kit - classes/OpaqueFunctionPointer.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2019 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_classes_OpaqueFunctionPointer_HPP_
#define Z_classes_OpaqueFunctionPointer_HPP_

#include <Z/macros/language.hpp>


namespace Zeta {struct OpaqueFunctionPointer {
	void (* function)();


	template <class T>
	Z_INLINE OpaqueFunctionPointer(T function) Z_NOTHROW
	: function((void (*)())function) {}


	template <class T>
	Z_INLINE operator T() const Z_NOTHROW
		{return (T)function;}
};}


#endif // Z_classes_OpaqueFunctionPointer_HPP_
