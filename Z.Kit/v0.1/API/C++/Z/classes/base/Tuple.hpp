/* Z Kit C++ API - classes/base/Tuple.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_classes_base_Tuple_HPP__
#define __Z_classes_base_Tuple_HPP__

#include <Z/traits/Type.hpp>


namespace Zeta {

	namespace Partials {namespace Tuple {

		template <class... T> class Element;

		template <class... T> struct Super {
			typedef typename TypeListRename<
				typename TypeListRotateRight<TypeList<T...>, 1>::type, Element
			>::type type;
		};


		template <class TN, class... T> class Element<TN, T...> : public Super<T...>::type {
			private:
			typedef typename Super<T...>::type Super;

			protected:
			TN _value;

			typedef TN type;

			Z_INLINE_MEMBER Element() {}
			Z_INLINE_MEMBER Element(T... previous, TN value) : Super(previous...), _value(value) {}
		};


		template <class TN> class Element<TN> {
			protected:
			TN _value;

			typedef TN type;

			Z_INLINE_MEMBER Element() {}
			Z_INLINE_MEMBER Element(TN value) : _value(value) {}
		};
	}}


	template <class... T> class Tuple : public Partials::Tuple::Super<T...>::type {
		private:
		typedef typename Partials::Tuple::Super<T...>::type Super;

		protected:
		template <unsigned int I> struct At {
			typedef typename TypeListRename<
				typename TypeListRotateRight<
					typename TypeListRemoveTail<TypeList<T...>, sizeof...(T) - (I + 1)>::type, 1
				>::type,
				Partials::Tuple::Element
			>::type element;

			typedef typename element::type type;
		};

		public:
		Z_INLINE_MEMBER Tuple() {}
		Z_INLINE_MEMBER Tuple(T... values) : Super(values...) {}


		template <unsigned int I> Z_INLINE_MEMBER typename At<I>::type get()
			{return At<I>::element::_value;}


		template <unsigned int I> Z_INLINE_MEMBER void set(typename At<I>::type value)
			{return At<I>::element::_value = value;}
	};
}


#endif // __Z_classes_base_Tuple_HPP__
