/* Z Kit C++ API - classes/functional/ObjectSelector.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_classes_functional_ObjectSelector_HPP__
#define __Z_classes_functional_ObjectSelector_HPP__

#include <Z/classes/functional/Selector.hpp>

#if Z_HAS_CLASS(Selector)


	namespace Zeta {
		template <class F> struct ObjectSelector;

		template <class R, class... P> struct ObjectSelector<R(P...)> : Selector<R(P...)> {
			typedef typename Selector<R(P...)>::Call      Call;
			typedef typename Selector<R(P...)>::CallSuper CallSuper;

			id object;

			Z_INLINE_MEMBER ObjectSelector() {}


			Z_CT_MEMBER(CPP11) ObjectSelector(id object, SEL selector)
			: Selector<R(P...)>(selector), object(object) {}


			template <class RR = R>
			Z_INLINE_MEMBER typename EnableIf<Type<RR>::is_void, void>::type
			operator ()(typename Type<P>::to_forwardable... arguments) const
				{((Call)objc_msgSend)(object, this->selector, arguments...);}


#			if Z_CPU_ARCHITECTURE == Z_CPU_ARCHITECTURE_X86_64 || Z_CPU_ARCHITECTURE == Z_CPU_ARCHITECTURE_X86_32

				template <class RR = R>
				Z_INLINE_MEMBER typename EnableIf<
					!Type<RR>::is_void &&
					!Type<RR>::is_real &&
					!Type<RR>::is_compound,
				RR>::type
				operator ()(typename Type<P>::to_forwardable... arguments) const
					{return ((Call)objc_msgSend)(object, this->selector, arguments...);}


				template <class RR = R>
				Z_INLINE_MEMBER typename EnableIf<Type<RR>::is_real, RR>::type
				operator ()(typename Type<P>::to_forwardable... arguments) const
					{return ((Call)objc_msgSend_fpret)(object, this->selector, arguments...);}

#			else

				template <class RR = R>
				Z_INLINE_MEMBER typename EnableIf<
					!Type<RR>::is_void &&
					!Type<RR>::is_compound,
				RR>::type
				operator ()(typename Type<P>::to_forwardable... arguments) const
					{return ((Call)objc_msgSend)(object, this->selector, arguments...);}

#			endif


			template <class RR = R>
			Z_INLINE_MEMBER typename EnableIf<Type<RR>::is_compound, RR>::type
			operator ()(typename Type<P>::to_forwardable... arguments) const
				{return ((Call)objc_msgSend_stret)(object, this->selector, arguments...);}


#			if Z_LANGUAGE_INCLUDES(OBJECTIVE_CPP)

				template <class RR = R>
				Z_INLINE_MEMBER typename EnableIf<Type<RR>::is_void, void>::type
				super(typename Type<P>::to_forwardable... arguments) const
					{
					struct objc_super object_super {object, [[object class] superclass]};
					((CallSuper)objc_msgSendSuper)(&object_super, this->selector, arguments...);
					}


				template <class RR = R>
				Z_INLINE_MEMBER typename EnableIf<
					!Type<RR>::is_void &&
					!Type<RR>::is_compound,
				RR>::type
				super(typename Type<P>::to_forwardable... arguments) const
					{
					struct objc_super object_super {object, [[object class] superclass]};
					((CallSuper)objc_msgSendSuper)(&object_super, this->selector, arguments...);
					}


				template <class RR = R>
				Z_INLINE_MEMBER typename EnableIf<Type<RR>::is_compound, RR>::type
				super(typename Type<P>::to_forwardable... arguments) const
					{
					struct objc_super object_super {object, [[object class] superclass]};
					((CallSuper)objc_msgSendSuper_stret)(&object_super, this->selector, arguments...);
					}

#			endif
		};
	}


#	define Z_HAS_CLASS_ObjectSelector TRUE
#else
#	define Z_HAS_CLASS_ObjectSelector FALSE
#endif

#endif // __Z_classes_functional_Selector_HPP__
