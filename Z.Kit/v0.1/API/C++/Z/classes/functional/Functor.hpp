/* Z Kit C++ API - classes/functional/Functor.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_classes_functional_Functor_HPP__
#define __Z_classes_functional_Functor_HPP__

#include <Z/classes/functional/ObjectMemberFunction.hpp>

#ifdef Z_USE_OBJECTIVE_C_RUNTIME
#	include <Z/classes/functional/ObjectSelector.hpp>
#endif

#if Z_HAS_CLASS(ObjectMemberFunction)


	namespace Zeta {

		template <class F> class Functor;

		template <class R, class... P> class Functor<R(P...)> {

			private:
			typedef R (* Call)(const Functor *, typename Type<P>::to_forwardable...);
			typedef void (* Destroy)(Functor *);

			Call	call;
			Destroy destroy;

			union {	R (* function)(P...);

				struct {R (NaT::* function)(P...);
					NaT *object;
				} object_member_function;

#				if Z_HAS_CLASS(ObjectSelector)
					struct {SEL selector;
						id  object;
					} object_selector;
#				endif
			} target;


			struct Callers {

				template <class RR = R>
				static Z_INLINE_MEMBER typename EnableIf<Type<RR>::is_void, Call>::type function()
					{
					return [](const Functor *functor, typename Type<P>::to_forwardable... arguments)
						{functor->target.function(arguments...);};
					}


				template <class RR = R>
				static Z_INLINE_MEMBER typename EnableIf<!Type<RR>::is_void, Call>::type function()
					{
					return [](const Functor *functor, typename Type<P>::to_forwardable... arguments)
						{return functor->target.function(arguments...);};
					}


				template <class RR = R>
				static Z_INLINE_MEMBER typename EnableIf<Type<RR>::is_void, Call>::type member_function()
					{
					return [](const Functor *functor, typename Type<P>::to_forwardable... arguments)
						{
						(functor->target.object_member_function.object->*functor->target.object_member_function.function)
							(arguments...);
						};
					}


				template <class RR = R>
				static Z_INLINE_MEMBER typename EnableIf<!Type<RR>::is_void, Call>::type member_function()
					{
					return [](const Functor *functor, typename Type<P>::to_forwardable... arguments)
						{
						return (functor->target.object_member_function.object->*functor->target.object_member_function.function)
							(arguments...);
						};
					}

#				if Z_HAS_CLASS(ObjectSelector)

#					if Z_CPU_ARCHITECTURE == Z_CPU_ARCHITECTURE_X86_64 || Z_CPU_ARCHITECTURE == Z_CPU_ARCHITECTURE_X86_32
#					endif

#				endif

			};


			public:

			Z_CT_MEMBER(CPP11) Functor() : call(NULL), destroy(NULL) {}


			Z_INLINE_MEMBER Functor(R (* function)(P...)) :
			call(Callers::function()), destroy(NULL)
				{target.function = function;}


			Z_INLINE_MEMBER Functor(const ObjectMemberFunction<R(P...)> &object_member_function) :
			call(Callers::member_function()), destroy(NULL)
				{
				target.object_member_function.function = object_member_function.function;
				target.object_member_function.object   = object_member_function.object;
				}


			template <class O, class M, class E = typename EnableIf<
				Type<O>::is_pointer				   &&
				Type<O>::flow::pointee_type::is_structure_or_union &&
				Type<M>::is_member_function_pointer		   &&
				TypeAreEqual<
					typename Type<M>::flow::to_function::end::to_unqualified,
					R(P...)
				>::value,
			M>::type>
			Z_INLINE_MEMBER Functor(O object, M function) :
			call(Callers::member_function()), destroy(NULL)
				{
				target.object_member_function.function = (R (NaT::*)(P...))function;
				target.object_member_function.object   = (NaT *)object;
				}


			template <class O, class M, class E = typename EnableIf<
				Type<O>::is_structure_or_union	    &&
				Type<M>::is_member_function_pointer &&
				TypeAreEqual<
					typename Type<M>::flow::to_function::end::to_unqualified,
					R(P...)
				>::value,
			M>::type>
			Z_INLINE_MEMBER Functor(const O &object, M function) :
			call(Callers::member_function()), destroy(NULL)
				{
				target.object_member_function.function = (R (NaT::*)(P...))function;
				target.object_member_function.object   = (NaT *)&object;
				}


#			if Z_HAS_CLASS(ObjectSelector)

				Z_INLINE_MEMBER
				Functor(const ObjectSelector<R(P...)> &object_selector) :
				call(Callers::object_selector()), destroy(NULL)
					{
					target.object_selector.selector = object_selector.selector;
					target.object_selector.object	= object_selector.object;
					}


				Z_INLINE_MEMBER
				Functor(id object, SEL selector) :
				call(Callers::object_selector()), destroy(NULL)
					{
					target.object_selector.selector = selector;
					target.object_selector.object	= object;
					}

#			endif


			Z_INLINE_MEMBER ~Functor() {if (destroy) destroy(this);}


			Z_CT_MEMBER(CPP11) operator Boolean() const {return call != NULL;}


			template <class RR = R>
			Z_INLINE_MEMBER typename EnableIf<Type<RR>::is_void, RR>::type
			operator ()(typename Type<P>::to_forwardable... arguments) const
				{call(this, arguments...);}


			template <class RR = R>
			Z_INLINE_MEMBER typename EnableIf<!Type<RR>::is_void, RR>::type
			operator ()(typename Type<P>::to_forwardable... arguments) const
				{return call(this, arguments...);}
		};
	}


#	define Z_HAS_CLASS_Functor TRUE
#else
#	define Z_HAS_CLASS_Functor FALSE
#endif

#endif // __Z_classes_functional_Functor_HPP__
