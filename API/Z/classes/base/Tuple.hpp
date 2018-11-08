/* Z Kit - classes/base/Tuple.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_classes_base_Tuple_HPP_
#define _Z_classes_base_Tuple_HPP_

#include <Z/inspection/language.h>

#if Z_LANGUAGE_HAS(CPP, VARIADIC_TEMPLATE_EXTENDED_PARAMETERS)

#	include <Z/traits/Type.hpp>


	namespace Zeta {namespace Detail {namespace Tuple {

		template <class type_list> class Element;


		template <class... T> struct Super {
			typedef Element<typename TypeListRotateRight<TypeList<T...>, 1>::type> type;
		};


		template <class T0>
		struct Element<TypeList<T0> > {
			typedef T0 Value;

			Value value;

			Z_INLINE Element() Z_DEFAULTED({})

			Z_CT(CPP11) Element(typename Zeta::Type<T0>::to_forwardable value)
			: value(value) {}
		};


		template <class TN, class... T>
		struct Element<TypeList<TN, T...> > : Super<T...>::type {
			typedef TN Value;

			Value value;

			Z_INLINE Element() Z_DEFAULTED({})

			Z_CT(CPP11) Element(
				typename Zeta::Type<T >::to_forwardable... previous,
				typename Zeta::Type<TN>::to_forwardable value
			) : Super<T...>::type(previous...), value(value) {}
		};
	}}}


	namespace Zeta {template <class... T> class Tuple : public Detail::Tuple::Super<T...>::type {

		private:
		typedef typename Detail::Tuple::Super<T...>::type Super;

		public:
		template <UInt I> class At {

			private:
			enum {tail_size = TypeCount<T...>::value - (I + 1)};

			public:
			typedef Detail::Tuple::Element<typename TypeListRotateRight<
				typename TypeListRemoveTail<TypeList<T...>, tail_size>::type, 1
			>::type> Element;

			typedef typename Element::Value type;
		};


#		if Z_LANGUAGE_HAS(CPP, INHERITING_CONSTRUCTORS)
			using Super::Super;
#		else
			Z_INLINE Tuple() Z_DEFAULTED({})

			Z_CT(CPP11) Tuple(typename Type<T>::to_forwardable... values)
			: Super(values...) {}
#		endif


		template <UInt I>
		Z_INLINE typename At<I>::type &at()
			{return At<I>::Element::value;}


		template <UInt I>
		Z_CT(CPP11) typename Type<typename At<I>::type>::to_forwardable get() const
			{return At<I>::Element::value;}


		template <UInt I>
		Z_INLINE Tuple &set(typename Type<typename At<I>::type>::to_forwardable value)
			{
			At<I>::Element::value = value;
			return *this;
			}
	};}


#	define Z_HAS_CLASS_Tuple TRUE
#else
#	define Z_HAS_CLASS_Tuple FALSE
#endif

#endif // _Z_classes_base_Tuple_HPP_
