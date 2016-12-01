/* Z Kit C++ API - traits/TypeList.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_traits_TypeList_HPP__
#define __Z_traits_TypeList_HPP__

#include <Z/traits/SelectType.hpp>

#if Z_LANGUAGE_HAS(CPP, TEMPLATE_ALIAS)
#	include <Z/traits/transformation.hpp>
#endif

#if Z_LANGUAGE_HAS(CPP, VARIADIC_TEMPLATE)

	namespace Zeta {

		template<class... A> struct TypeList {
			enum {size = sizeof...(A)};

			typedef typename SelectType<0,			 A...>::type first;
			typedef typename SelectType<size ? size - 1 : 0, A...>::type last;

#			if Z_LANGUAGE_HAS(CPP, TEMPLATE_ALIAS)

				template<unsigned int I> using get = typename SelectType<I, A...>::type;

				template<class... more>	using prepend = TypeList<more..., A...>;
				template<class... more> using append  = TypeList<A..., more...>;

				using remove_first = typename RemoveFirstType<TypeList>::type;
				//using remove_last  = typename RemoveLastType <TypeList>::type;
#			endif
		};



	}

#endif

#endif // __Z_traits_TypeList_HPP__
