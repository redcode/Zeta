/* Z Kit - classes/base/OpaqueFunctionPointer.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_classes_base_OpaqueFunctionPointer_HPP__
#define __Z_classes_base_OpaqueFunctionPointer_HPP__

#include <Z/macros/language.hpp>


namespace Zeta {struct OpaqueFunctionPointer {
	void (* function)();

	template <class T>
	Z_INLINE OpaqueFunctionPointer(T function)
	: function((void (*)())function) {}

	template <class T>
	Z_INLINE operator T() const {return (T)function;}
};}


#endif // __Z_classes_base_OpaqueFunctionPointer_HPP__
