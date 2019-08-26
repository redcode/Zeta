/* Z Kit - classes/Functor.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2019 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_classes_Functor_HPP
#define Z_classes_Functor_HPP

#include <Z/classes/ObjectMemberFunction.hpp>

#if Z_HAS_CLASS(ObjectMemberFunction)

#	ifdef Z_USE_OBJECTIVE_C_RUNTIME
#		include <Z/classes/ObjectSelector.hpp>
#	endif


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
				static Z_INLINE typename TypeIf<Type<RR>::is_void, Call>::type
				function() Z_NOTHROW
					{
					return [](const Functor *functor, typename Type<P>::to_forwardable... arguments)
						{functor->target.function(arguments...);};
					}


				template <class RR = R>
				static Z_INLINE typename TypeIf<!Type<RR>::is_void, Call>::type
				function() Z_NOTHROW
					{
					return [](const Functor *functor, typename Type<P>::to_forwardable... arguments)
						{return functor->target.function(arguments...);};
					}


				template <class RR = R>
				static Z_INLINE typename TypeIf<Type<RR>::is_void, Call>::type
				object_member_function() Z_NOTHROW
					{
					return [](const Functor *functor, typename Type<P>::to_forwardable... arguments)
						{
						(functor->target.object_member_function.object->*functor->target.object_member_function.function)
							(arguments...);
						};
					}


				template <class RR = R>
				static Z_INLINE typename TypeIf<!Type<RR>::is_void, Call>::type
				object_member_function() Z_NOTHROW
					{
					return [](const Functor *functor, typename Type<P>::to_forwardable... arguments)
						{
						return (functor->target.object_member_function.object->*functor->target.object_member_function.function)
							(arguments...);
						};
					}


#				if Z_HAS_CLASS(ObjectSelector)

					typedef R (* CallObjectSelector)(id, SEL, P...);


					template <class RR = R>
					static Z_INLINE typename TypeIf<Type<RR>::is_void, Call>::type
					object_selector() Z_NOTHROW
						{
						return [](const Functor *functor, typename Type<P>::to_forwardable... arguments)
							{
							reinterpret_cast<CallObjectSelector>(objc_msgSend)
								(functor->target.object_selector.object, functor->target.object_selector.selector,
								 arguments...);
							};
						}


#					if Z_ISA == Z__X86_64 || Z_ISA == Z__X86_32

						template <class RR = R>
						static Z_INLINE typename TypeIf<!Type<RR>::is_void && !Type<RR>::is_real && !Type<RR>::is_class, Call>::type
						object_selector() Z_NOTHROW
							{
							return [](const Functor *functor, typename Type<P>::to_forwardable... arguments)
								{
								return reinterpret_cast<CallObjectSelector>(objc_msgSend)
									(functor->target.object_selector.object, functor->target.object_selector.selector,
									 arguments...);
								};
							}


						template <class RR = R>
						static Z_INLINE typename TypeIf<Type<RR>::is_real, Call>::type
						object_selector() Z_NOTHROW
							{
							return [](const Functor *functor, typename Type<P>::to_forwardable... arguments)
								{
								return reinterpret_cast<CallObjectSelector>(objc_msgSend_fpret)
									(functor->target.object_selector.object, functor->target.object_selector.selector,
									 arguments...);
								};
							}

#					else

						template <class RR = R>
						static Z_INLINE typename TypeIf<!Type<RR>::is_void && !Type<RR>::is_class, Call>::type
						object_selector() Z_NOTHROW
							{
							return [](const Functor *functor, typename Type<P>::to_forwardable... arguments)
								{
								return reinterpret_cast<CallObjectSelector>(objc_msgSend)
									(functor->target.object_selector.object, functor->target.object_selector.selector,
									 arguments...);
								};
							}

#					endif


					template <class RR = R>
					static Z_INLINE typename TypeIf<Type<RR>::is_class, Call>::type
					object_selector() Z_NOTHROW
						{
						return [](const Functor *functor, typename Type<P>::to_forwardable... arguments)
							{
							return reinterpret_cast<CallObjectSelector>(objc_msgSend_stret)
								(functor->target.object_selector.object, functor->target.object_selector.selector,
								 arguments...);
							};
						}

#				endif
			};


			public:

			Z_CT(CPP11) Functor() Z_NOTHROW
			: call(NULL), destroy(NULL) {}


#			ifdef Z_NULL_POINTER
				Z_CT(CPP11) Functor(NullPointer) Z_NOTHROW
				: call(NULL), destroy(NULL) {}
#			endif


			Z_INLINE Functor(R (* function)(P...)) Z_NOTHROW
			: call(Callers::function()), destroy(NULL)
				{target.function = function;}


			template <class O, class M, class E = typename TypeIf<
				(Type<O>::is_void || Type<O>::is_class) &&
				Type<M>::is_member_function_pointer	&&
				TypeIsSame<typename Type<M>::flow::to_function::end::to_unqualified, R(P...)>::value,
			M>::type>
			Z_INLINE Functor(O *object, M function) Z_NOTHROW
			: call(Callers::object_member_function()), destroy(NULL)
				{
				target.object_member_function.function = reinterpret_cast<R (NaT::*)(P...)>(function);
				target.object_member_function.object   = reinterpret_cast<NaT *>(const_cast<typename Type<O>::to_unqualified *>(object));
				}


			template <class O, class M, class E = typename TypeIf<
				Type<O>::is_class		    &&
				Type<M>::is_member_function_pointer &&
				TypeIsSame<typename Type<M>::flow::to_function::end::to_unqualified, R(P...)>::value,
			M>::type>
			Z_INLINE Functor(const O &object, M function) Z_NOTHROW
			: call(Callers::object_member_function()), destroy(NULL)
				{
				target.object_member_function.function = reinterpret_cast<R (NaT::*)(P...)>(function);
				target.object_member_function.object   = reinterpret_cast<NaT *>(const_cast<typename Type<O>::to_unqualified *>(&object));
				}


			Z_INLINE Functor(const ObjectMemberFunction<R(P...)> &object_member_function) Z_NOTHROW
			: call(Callers::object_member_function()), destroy(NULL)
				{
				target.object_member_function.function = object_member_function.function;
				target.object_member_function.object   = object_member_function.object;
				}


#			if Z_HAS_TRAIT(TypeIsConvertible)

				template <class O, class E = typename TypeIf<
					Type<O>::is_class &&
					TypeIsConvertible<O, R(*)(P...)>::value,
				O>::type>
				Z_INLINE Functor(const O &object) Z_NOTHROW
				: call(Callers::function()), destroy(NULL)
					{target.function = (R(*)(P...))object;} // TODO: cast

#			endif


#			if Z_HAS_CLASS(ObjectSelector)

				Z_INLINE Functor(id object, SEL selector) Z_NOTHROW
				: call(Callers::object_selector()), destroy(NULL)
					{
					target.object_selector.selector = selector;
					target.object_selector.object	= object;
					}


				Z_INLINE Functor(const ObjectSelector<R(P...)> &object_selector) Z_NOTHROW
				: call(Callers::object_selector()), destroy(NULL)
					{
					target.object_selector.selector = object_selector.selector;
					target.object_selector.object	= object_selector.object;
					}

#			endif


			Z_INLINE ~Functor()
				{if (destroy) destroy(this);}


			Z_CT(CPP11) operator Boolean() const Z_NOTHROW
				{return call != NULL;}


			template <class RR = R>
			Z_INLINE typename TypeIf<Type<RR>::is_void, RR>::type
			operator ()(typename Type<P>::to_forwardable... arguments) const
				{call(this, arguments...);}


			template <class RR = R>
			Z_INLINE typename TypeIf<!Type<RR>::is_void, RR>::type
			operator ()(typename Type<P>::to_forwardable... arguments) const
				{return call(this, arguments...);}
		};
	}


#	define Z_HAS_CLASS_Functor TRUE
#else
#	define Z_HAS_CLASS_Functor FALSE
#endif

#endif // Z_classes_Functor_HPP
