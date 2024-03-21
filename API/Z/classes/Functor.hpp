/* Zeta API - Z/classes/Functor.hpp
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_classes_Functor_HPP
#define Z_classes_Functor_HPP

#include <Z/classes/ObjectMemberFunction.hpp>

#if Z_HAS(ObjectMemberFunction)
#	ifdef Z_WITH_OBJECTIVE_C_RUNTIME
#		include <Z/classes/ObjectSelector.hpp>
#		include <Z/traits/casting.hpp>
#	endif

#	define Z_HAS_Functor 1


	namespace Zeta {

		template <class f> class Functor;

		template <class r, class... p> class Functor<r(p...)> {

			private:
			typedef r (* Call)(const Functor *, typename Type<p>::to_forwardable...);
			typedef void (* Destroy)(Functor *);

			Call	call;
			Destroy destroy;

			union {	r (* function)(p...);

				struct {r (NaT::* function)(p...);
					NaT *object;
				} object_member_function;

#				if Z_HAS(ObjectSelector)
					struct {SEL selector;
						id  object;
					} object_selector;
#				endif
			} target;


			struct Callers {

				static Z_INLINE Call function() Z_NOTHROW
					{
					return [](const Functor *functor, typename Type<p>::to_forwardable... arguments) -> r
						{return functor->target.function(arguments...);};
					}


				static Z_INLINE Call object_member_function() Z_NOTHROW
					{
					return [](const Functor *functor, typename Type<p>::to_forwardable... arguments) -> r
						{
						return (functor->target.object_member_function.object->*
							functor->target.object_member_function.function)
								(arguments...);
						};
					}


#				if Z_HAS(ObjectSelector)
					static Z_INLINE Call object_selector() Z_NOTHROW
						{
						return [](const Functor *functor, typename Type<p>::to_forwardable... arguments)
							{
							return (cast<r (*)(id, SEL, p...)>(ObjectiveC::send<r>()))(
								functor->target.object_selector.object,
								functor->target.object_selector.selector,
								arguments...);
							};
						}
#				endif
			};


			public:

			Z_CT(CPP11) Functor() Z_NOTHROW
			: call(Z_NULL), destroy(Z_NULL) {}


#			ifdef Z_NULLPTR
				Z_CT(CPP11) Functor(NullPtr) Z_NOTHROW
				: call(Z_NULL), destroy(Z_NULL) {}
#			endif


			Z_INLINE Functor(r (* function)(p...)) Z_NOTHROW
			: call(Callers::function()), destroy(Z_NULL)
				{target.function = function;}


			template <class o, class m, class e = typename TypeIf<
				(Type<o>::is_void || Type<o>::is_class) &&
				Type<m>::is_member_function_pointer	&&
				TypeIsSame<typename Type<m>::flow::to_function::end::to_unqualified, r(p...)>::value
			>::type>
			Z_INLINE Functor(o *object, m function) Z_NOTHROW
			: call(Callers::object_member_function()), destroy(Z_NULL)
				{
				target.object_member_function.function = reinterpret_cast<r (NaT::*)(p...)>(function);
				target.object_member_function.object   = reinterpret_cast<NaT *>(const_cast<typename Type<o>::to_unqualified *>(object));
				}


			template <class o, class m, class e = typename TypeIf<
				Type<o>::is_class		    &&
				Type<m>::is_member_function_pointer &&
				TypeIsSame<typename Type<m>::flow::to_function::end::to_unqualified, r(p...)>::value
			>::type>
			Z_INLINE Functor(const o &object, m function) Z_NOTHROW
			: call(Callers::object_member_function()), destroy(Z_NULL)
				{
				target.object_member_function.function = reinterpret_cast<r (NaT::*)(p...)>(function);
				target.object_member_function.object   = reinterpret_cast<NaT *>(const_cast<typename Type<o>::to_unqualified *>(&object));
				}


			Z_INLINE Functor(const ObjectMemberFunction<r(p...)> &object_member_function) Z_NOTHROW
			: call(Callers::object_member_function()), destroy(Z_NULL)
				{
				target.object_member_function.function = object_member_function.function;
				target.object_member_function.object   = object_member_function.object;
				}


#			if Z_HAS(TypeIsConvertible)

				template <class o, class e = typename TypeIf<
					Type<o>::is_class &&
					TypeIsConvertible<o, r(*)(p...)>::value
				>::type>
				Z_INLINE Functor(const o &object) Z_NOTHROW
				: call(Callers::function()), destroy(Z_NULL)
					{target.function = (r(*)(p...))object;} // TODO: cast

#			endif


#			if Z_HAS(ObjectSelector)

				Z_INLINE Functor(id object, SEL selector) Z_NOTHROW
				: call(Callers::object_selector()), destroy(Z_NULL)
					{
					target.object_selector.selector = selector;
					target.object_selector.object	= object;
					}


				Z_INLINE Functor(const ObjectSelector<r(p...)> &object_selector) Z_NOTHROW
				: call(Callers::object_selector()), destroy(Z_NULL)
					{
					target.object_selector.selector = object_selector.selector;
					target.object_selector.object	= object_selector.object;
					}

#			endif


			Z_INLINE ~Functor()
				{if (destroy) destroy(this);}


			Z_CT(CPP11) operator Boolean() const Z_NOTHROW
				{return call != Z_NULL;}


			Z_INLINE r operator ()(typename Type<p>::to_forwardable... arguments) const
				{return call(this, arguments...);}
		};
	}


#endif

#endif // Z_classes_Functor_HPP
