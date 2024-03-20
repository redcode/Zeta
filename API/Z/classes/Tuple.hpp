/* Zeta API - Z/classes/Tuple.hpp
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_classes_Tuple_HPP
#define Z_classes_Tuple_HPP

#include <Z/inspection/language.h>

#if Z_DIALECT_HAS(CPP11, EXTENDED_VARIADIC_TEMPLATE_TEMPLATE_PARAMETERS) /* ¿No es necesario, basta con VARIADIC_TEMPLATE? */
#	include <Z/traits/type.hpp>

#	define Z_HAS_Tuple 1


	namespace Zeta {namespace ZetaDetail {namespace Tuple {

		template <class type_list> struct Element;


		template <class... t> struct Super {
			typedef Element<typename TypeListRotateRight<TypeList<t...>, 1>::type> type;
		};


		template <class t0>
		struct Element<TypeList<t0> > {
			typedef t0 type;

			type value;

			Z_INLINE Element()
				Z_DEFAULTED({})


			Z_CT(CPP11) Element(typename Zeta::Type<t0>::to_forwardable value)
			: value(value) {}
		};


		template <class tn, class... t>
		struct Element<TypeList<tn, t...> > : Super<t...>::type {
			typedef tn type;

			type value;

			Z_INLINE Element()
				Z_DEFAULTED({})


			Z_CT(CPP11) Element(
				typename Zeta::Type<t >::to_forwardable... previous,
				typename Zeta::Type<tn>::to_forwardable value
			) : Super<t...>::type(previous...), value(value) {}
		};
	}}}


	namespace Zeta {template <class... t> class Tuple : public ZetaDetail::Tuple::Super<t...>::type {
		private:
		typedef typename ZetaDetail::Tuple::Super<t...>::type Super;

		public:
		template <UInt i> class At {

			private:
			enum {tail_size = TypeCount<t...>::value - (i + 1)};

			public:
			typedef ZetaDetail::Tuple::Element<typename TypeListRotateRight<
				typename TypeListRemoveTail<TypeList<t...>, tail_size>::type, 1
			>::type> Element;

			typedef typename Element::type type;
		};


#		if !Z_DIALECT_HAS(CPP11, INHERITING_CONSTRUCTORS)
			using Super::Super;

#		else
			Z_INLINE Tuple()
				Z_DEFAULTED({})


			Z_CT(CPP11) Tuple(typename Type<t>::to_forwardable... values)
			: Super(values...) {}
#		endif


		template <UInt index>
		Z_INLINE typename At<index>::type &at() Z_NOTHROW
			{return At<index>::Element::value;}


		template <UInt index>
		Z_CT(CPP11) typename Type<typename At<index>::type>::to_forwardable get() const Z_NOTHROW
			{return At<index>::Element::value;}


		template <UInt index>
		Z_INLINE Tuple &set(typename Type<typename At<index>::type>::to_forwardable value)
			{
			At<index>::Element::value = value;
			return *this;
			}
	};}


#	if	defined(Z_WITH_STD)			 && \
		Z_DIALECT_HAS(CPP17, STRUCTURED_BINDING) && \
		defined(__has_include)			 && \
		__has_include(<tuple>)

#		include <tuple>

#		define Z_z_IMPLEMENTATION(qualifiers)										\
																\
			template <class... t>											\
			struct std::tuple_size<qualifiers Zeta::Tuple<t...> > {							\
				enum {value = sizeof...(t)};									\
			};													\
																\
			template <std::size_t i, class... t>									\
			struct std::tuple_element<i, qualifiers Zeta::Tuple<t...> > {						\
				typedef typename Zeta::Type<typename Zeta::Tuple<t...>::template At<i>::type>::add_const type;	\
			};

		Z_z_IMPLEMENTATION(Z_EMPTY	 )
		Z_z_IMPLEMENTATION(const	 )
		Z_z_IMPLEMENTATION(const volatile)
		Z_z_IMPLEMENTATION(	 volatile)

#		undef Z_z_IMPLEMENTATION
#	endif

#endif

#endif // Z_classes_Tuple_HPP
