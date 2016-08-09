/* Z Kit C++ API - traits/SelectType.hpp
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_traits_SelectType_HPP__
#define __Z_traits_SelectType_HPP__

#include <Z/macros/repetition.h>

namespace Zeta {

	template <int,
		class C00,	  class C01 = void, class C02 = void, class C03 = void,
		class C04 = void, class C05 = void, class C06 = void, class C07 = void,
		class C08 = void, class C09 = void, class C10 = void, class C11 = void,
		class C12 = void, class C13 = void, class C14 = void, class C15 = void,
		class C16 = void, class C17 = void, class C18 = void, class C19 = void,
		class C20 = void, class C21 = void, class C22 = void, class C23 = void,
		class C24 = void, class C25 = void, class C26 = void, class C27 = void,
		class C28 = void, class C29 = void, class C30 = void, class C31 = void
	> struct SelectType {};

#	define Z_TEMPLATE_SPECIALIZATION(type_count, index)		       \
	template <Z_ENUMERATE_APPENDING_INDEX(type_count, class C)>	       \
	struct SelectType<index, Z_ENUMERATE_APPENDING_INDEX(type_count, C)> { \
		typedef C##index type;					       \
	};

#	define Z_TEMPLATE_SPECIALIZATION_GROUP(type_count) \
	Z_FOR_##type_count##_CALL_WITH_TOKEN_AND_INDEX(Z_TEMPLATE_SPECIALIZATION, type_count,)

	Z_FOR_32_CALL_WITH_INDEX(Z_TEMPLATE_SPECIALIZATION_GROUP,)

#	undef Z_TEMPLATE_SPECIALIZATION_GROUP
#	undef Z_TEMPLATE_SPECIALIZATION
}

#endif // __Z_traits_SelectType_HPP__
