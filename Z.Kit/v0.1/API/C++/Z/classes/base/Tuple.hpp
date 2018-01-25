/* Z Kit C++ API - classes/base/Tuple.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_classes_base_Tuple_HPP__
#define __Z_classes_base_Tuple_HPP__

#include <Z/traits/Type.hpp>

#if Z_LANGUAGE_HAS(CPP, VARIADIC_TEMPLATE_EXTENDED_PARAMETERS)


	namespace Zeta {namespace Detail {namespace Tuple {

		template <class type_list> class Element;

		template <class... T> struct Super {
			typedef Element<typename TypeListRotateRight<TypeList<T...>, 1>::type> type;
		};

		template <class TN, class... T>
		class Element<TypeList<TN, T...> > : public Super<T...>::type {

			protected:
			TN _value;

			public:
			typedef TN type;

			Z_INLINE_MEMBER Element() {}

			Z_CT_MEMBER(CPP11) Element(
				typename Zeta::Type<T >::to_forwardable... previous,
				typename Zeta::Type<TN>::to_forwardable value
			) : Super<T...>::type(previous...), _value(value) {}
		};

		template <>
		class Element<TypeList<> > {
			public:
			Z_CT_MEMBER(CPP11) Element() {}
		};
	}}}


	namespace Zeta {template <class... T> class Tuple : public Detail::Tuple::Super<T...>::type {

		private:
		typedef typename Detail::Tuple::Super<T...>::type Super;

		public:
		template <UInt I> class At {

			private:
			enum {tail_size = sizeof...(T) - (I + 1)};

			public:
			typedef Detail::Tuple::Element<typename TypeListRotateRight<
				typename TypeListRemoveTail<TypeList<T...>, tail_size>::type, 1
			>::type> Element;

			typedef typename Element::type type;
		};


#		if Z_LANGUAGE_HAS(CPP, INHERITING_CONSTRUCTORS)
			using Super::Super;
#		else
			Z_CT_MEMBER(CPP11) Tuple(typename Type<T>::to_forwardable... values)
			: Super(values...) {}
#		endif


		template <UInt I>
		Z_INLINE_MEMBER typename At<I>::type &at()
			{return At<I>::Element::_value;}


		template <UInt I>
		Z_CT_MEMBER(CPP11) typename Type<typename At<I>::type>::to_forwardable get() const
			{return At<I>::Element::_value;}


		template <UInt I>
		Z_INLINE_MEMBER Tuple &set(typename Type<typename At<I>::type>::to_forwardable value)
			{
			At<I>::Element::_value = value;
			return *this;
			}
	};}


#endif

#endif // __Z_classes_base_Tuple_HPP__
