/* Z Kit C++ API - classes/base/abstract/Enumeration.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_classes_base_abstract_Enumeration_HPP__
#define __Z_classes_base_abstract_Enumeration_HPP__

#include <Z/macros/language.hpp>
#include <Z/types/base.hpp>

namespace Zeta {namespace Abstract {template <class T> struct Enumeration;}}


template <class T> struct Zeta::Abstract::Enumeration {

	T value;

#	if Z_LANGUAGE_HAS_TYPE(CPP, BOOLEAN)
		Z_INLINE_MEMBER operator bool() const {return value;}
#	endif

	Z_INLINE_MEMBER operator T() const {return value;}

	Z_INLINE_MEMBER Boolean operator ==(T value) const {return this->value == value;}
	Z_INLINE_MEMBER Boolean operator !=(T value) const {return this->value != value;}

	Z_INLINE_MEMBER T operator ~() const {return ~value;}

	Z_INLINE_MEMBER T operator &(T value) const {return this->value & value;}
	Z_INLINE_MEMBER T operator |(T value) const {return this->value | value;}
	Z_INLINE_MEMBER T operator ^(T value) const {return this->value ^ value;}

	Z_INLINE_MEMBER Enumeration &operator &=(T value) {this->value &= value; return *this;}
	Z_INLINE_MEMBER Enumeration &operator |=(T value) {this->value |= value; return *this;}
	Z_INLINE_MEMBER Enumeration &operator ^=(T value) {this->value ^= value; return *this;}
};


#endif // __Z_classes_base_abstract_Enumeration_HPP__
