/* Z Kit C++ API - classes/base/Tuple.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_classes_base_Tuple_HPP__
#define __Z_classes_base_Tuple_HPP__

#include <Z/types/base.hpp>
#include <Z/macros/language.hpp>
#include <Z/traits/filtering.hpp>
#include <Z/traits/SelectType.hpp>


# if Z_LANGUAGE_HAS(CPP, VARIADIC_TEMPLATE)

	namespace Zeta {

		namespace Partials {

			template <unsigned int I, class... T> struct Tuple : Tuple<I - 1, T...> {
				protected:
				typedef Tuple<I, T...>	   This;
				typedef Tuple<I - 1, T...> Parent;
				typedef typename SelectType<I - 1, T...>::type type;

				private:
				type _value;

				protected:
				Z_INLINE_MEMBER type get() {return _value;}
				Z_INLINE_MEMBER void set(type value) {_value = value;}
			};

			template <class... T> struct Tuple<0, T...> {};
		}

		template <class... T> class Tuple : public Partials::Tuple<sizeof...(T), T...> {
			public:

			template <unsigned int I> Z_INLINE_MEMBER
			typename Partials::Tuple<I + 1, T...>::type get()
				{return Partials::Tuple<I + 1, T...>::get();}


			template <unsigned int I> Z_INLINE_MEMBER
			void set(typename Partials::Tuple<I + 1, T...>::type value)
				{return Partials::Tuple<I + 1, T...>::set(value);}
		};
	}

#endif


#endif // __Z_classes_base_Tuple_HPP__
