/* Z Kit C++ API - traits/TypeList.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_traits_TypeList_HPP__
#define __Z_traits_TypeList_HPP__

#include <Z/traits/Template.hpp>

#if Z_LANGUAGE_HAS(CPP, VARIADIC_TEMPLATE)

	namespace Zeta {

		template<class... T> struct TypeList {
			enum {size = sizeof...(T)};

			typedef typename SelectType<0,			 T...>::type first;
			typedef typename SelectType<size ? size - 1 : 0, T...>::type last;

			typedef	typename Template::RemoveFirst<TypeList>::type remove_first;
			typedef typename Template::RemoveLast <TypeList>::type remove_last;

#			if Z_LANGUAGE_HAS(CPP, TEMPLATE_ALIAS)

				template<unsigned int I> using get     = typename SelectType<I, T...>::type;
				template<class... more > using prepend = TypeList<more..., T...>;
				template<class... more > using append  = TypeList<T..., more...>;
				template<unsigned int I> using remove  = typename Template::Remove<TypeList, I>::type;

#			endif
		};
	}

#endif

#endif // __Z_traits_TypeList_HPP__
