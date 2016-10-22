/* Z Kit C++ API - macros/enumeration.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_macros_enumeration_HPP__
#define __Z_macros_enumeration_HPP__

#include <Z/classes/base/abstract/Enumeration.hpp>

#if Z_LANGUAGE_HAS(CPP, STRONGLY_TYPED_ENUMERATION)

#	define Z_ENUMERATION_BEGIN(Type, UnderlyingType)			  \
		struct Type : Zeta::Abstract::Enumeration<UnderlyingType> {	  \
										  \
		Z_INLINE_MEMBER Type() {}					  \
		Z_INLINE_MEMBER Type(UnderlyingType value) {this->value = value;} \
										  \
	enum Values : UnderlyingType {

#else

#	define Z_ENUMERATION_BEGIN(Type, UnderlyingType)	       \
		struct Type : Zeta::Abstract::Enumeration<int> {       \
								       \
		Z_INLINE_MEMBER Type() {}			       \
		Z_INLINE_MEMBER Type(int value) {this->value = value;} \
								       \
	enum {

#endif

#define Z_ENUMERATION_END };};

#endif // __Z_macros_enumeration_HPP__
