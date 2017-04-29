/* Z Kit C++ API - classes/base/Tuple.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright © 2006-2017 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_classes_base_Tuple_HPP__
#define __Z_classes_base_Tuple_HPP__

#include <Z/traits/Type.hpp>

#if Z_LANGUAGE_HAS(CPP, VARIADIC_TEMPLATE_EXTENDED_PARAMETERS)

	namespace Zeta {namespace Detail {namespace Tuple {

		template <class value_type_list, class parameter_type_list> class Element;
		template <class value_type_list, class parameter_type_list> class Super;

		template <class... V, class... P> struct Super<TypeList<V...>, TypeList<P...> > {
			typedef Element<
				typename TypeListRotateRight<TypeList<V...>, 1>::type,
				typename TypeListRotateRight<TypeList<P...>, 1>::type
			> type;
		};

		template <class VN, class... V, class PN, class... P> class Element<TypeList<VN, V...>, TypeList<PN, P...> >
		: public Super<TypeList<V...>, TypeList<P...> >::type {
			private:
			typedef typename Super<TypeList<V...>, TypeList<P...> >::type Super;

			protected:
			VN _value;

			typedef VN value_type;
			typedef PN parameter_type;

			public:
			Z_INLINE_MEMBER Element() {}
			Z_CONSTANT_MEMBER(CPP11) Element(P... previous, PN value) : Super(previous...), _value(value) {}
		};

		template <class VN, class PN> class Element<TypeList<VN>, TypeList<PN> > {
			protected:
			VN _value;

			typedef VN value_type;
			typedef PN parameter_type;

			public:
			Z_INLINE_MEMBER Element() {}
			Z_CONSTANT_MEMBER(CPP11) Element(PN value) : _value(value) {}
		};
	}}}


	namespace Zeta {template <class... T> class Tuple;}


	template <class... T> class Zeta::Tuple
	: public Zeta::Detail::Tuple::Super<TypeList<T...>, typename TypeListTransform<TypeList<T...>, TypeToParameter>::type>::type {
		private:
		typedef TypeList<T...>							      ValueTypeList;
		typedef typename TypeListTransform<ValueTypeList, TypeToParameter>::type      ParameterTypeList;
		typedef typename Detail::Tuple::Super<ValueTypeList, ParameterTypeList>::type Super;

		protected:
		template <UInt I> class At {
			private:
			enum {tail_size = sizeof...(T) - (I + 1)};

			public:
			typedef Detail::Tuple::Element<
				typename TypeListRotateRight<typename TypeListRemoveTail<ValueTypeList,	    tail_size>::type, 1>::type,
				typename TypeListRotateRight<typename TypeListRemoveTail<ParameterTypeList, tail_size>::type, 1>::type
			> element;

			typedef typename element::value_type	 value_type;
			typedef typename element::parameter_type parameter_type;
		};

		public:

#		if Z_LANGUAGE_HAS(CPP, INHERITING_CONSTRUCTORS)
			using Super::Super;
#		else
			Z_CONSTANT_MEMBER(CPP11) Tuple(T... values) : Super(values...) {}
#		endif

		template <UInt I> Z_INLINE_MEMBER typename At<I>::value_type &at()
			{return At<I>::element::_value;}


		template <UInt I> Z_CONSTANT_MEMBER(CPP11) typename At<I>::value_type get() const
			{return At<I>::element::_value;}


		template <UInt I> Z_INLINE_MEMBER Tuple &set(typename At<I>::parameter_type value)
			{
			At<I>::element::_value = value;
			return *this;
			}
	};

#endif

#endif // __Z_classes_base_Tuple_HPP__
