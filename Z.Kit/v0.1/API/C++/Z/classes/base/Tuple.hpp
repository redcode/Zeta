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
#include <type_traits>

# if Z_LANGUAGE_HAS(CPP, VARIADIC_TEMPLATE)

	namespace Zeta {

		namespace Abstract {

			template <unsigned int I, class... T>
			struct Tuple : Tuple<I - 1, T...> {
				protected:
				typedef Tuple<I, T...>	   This;
				typedef Tuple<I - 1, T...> Parent;
				typedef typename SelectType<I - 1, T...>::type type;

				private:
				type _value;


				protected:

				/*Z_INLINE_MEMBER EnableIf<true, Boolean>::type
				is_equal_to(const This &tuple) const
					{return _value == tuple._value;}


				Z_INLINE_MEMBER EnableIf<false, Boolean>::type
				is_equal_to(const This &tuple) const
					{return _value == tuple._value && Parent::is_equal_to(tuple);}*/


				protected:
				Z_INLINE_MEMBER type get() {return _value;}
				Z_INLINE_MEMBER void set(type value) {_value = value;}
			};

			template <class... T> struct Tuple<0, T...> {};
		}

		template <class... T>
		class Tuple : public Abstract::Tuple<sizeof...(T), T...> {
			public:

			/*Z_INLINE_MEMBER Boolean operator ==(const Tuple &tuple) const
				{return Partials::Abstract::Tuple<sizeof...(T), T...>::is_equal_to(tuple);}*/


			template <unsigned int I> Z_INLINE_MEMBER
			typename Abstract::Tuple<I + 1, T...>::type get()
				{return Abstract::Tuple<I + 1, T...>::get();}


			template <unsigned int I> Z_INLINE_MEMBER
			void set(typename Abstract::Tuple<I + 1, T...>::type value)
				{return Abstract::Tuple<I + 1, T...>::set(value);}
		};
	}

#endif

#endif // __Z_classes_base_Tuple_HPP__
