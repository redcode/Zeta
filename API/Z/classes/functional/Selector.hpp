/* Z Kit - classes/functional/Selector.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_classes_functional_Selector_HPP_
#define _Z_classes_functional_Selector_HPP_

#include <Z/inspection/language.h>

#if	Z_LANGUAGE_HAS(CPP, SFINAE)	       && \
	Z_LANGUAGE_HAS(CPP, VARIADIC_TEMPLATE) && \
	Z_LANGUAGE_HAS(CPP, DEFAULT_TEMPLATE_ARGUMENTS_FOR_FUNCTION_TEMPLATE)

#	include <Z/traits/filtering.hpp>
#	include <Z/traits/Type.hpp>
#	include <objc/message.h>


	namespace Zeta {

		template <class F> struct Selector;

		template <class R, class... P> struct Selector<R(P...)> {
			typedef R (* Call     )(id,		    SEL, P...);
			typedef R (* CallSuper)(struct objc_super*, SEL, P...);

			SEL selector;

			Z_INLINE Selector() Z_DEFAULTED({})

			Z_INLINE Selector(SEL selector)
			: selector(selector) {}


			Z_INLINE operator SEL() const {return selector;}


			template <class RR = R>
			Z_INLINE typename EnableIf<Type<RR>::is_void, RR>::type
			operator ()(id object, typename Type<P>::to_forwardable... arguments) const
				{((Call)objc_msgSend)(object, selector, arguments...);}


#			if	Z_CPU_ARCHITECTURE == Z_CPU_ARCHITECTURE_X86_64 || \
				Z_CPU_ARCHITECTURE == Z_CPU_ARCHITECTURE_X86_32

				template <class RR = R>
				Z_INLINE typename EnableIf<
					!Type<RR>::is_void &&
					!Type<RR>::is_real &&
					!Type<RR>::is_structure_or_union,
				RR>::type
				operator ()(id object, typename Type<P>::to_forwardable... arguments) const
					{return ((Call)objc_msgSend)(object, selector, arguments...);}


				template <class RR = R>
				Z_INLINE typename EnableIf<Type<RR>::is_real, RR>::type
				operator ()(id object, typename Type<P>::to_forwardable... arguments) const
					{return ((Call)objc_msgSend_fpret)(object, selector, arguments...);}

#			else

				template <class RR = R>
				Z_INLINE typename EnableIf<
					!Type<RR>::is_void &&
					!Type<RR>::is_structure_or_union,
				RR>::type
				operator ()(id object, typename Type<P>::to_forwardable... arguments) const
					{return ((Call)objc_msgSend)(object, selector, arguments...);}

#			endif


			template <class RR = R>
			Z_INLINE typename EnableIf<Type<RR>::is_structure_or_union, RR>::type
			operator ()(id object, typename Type<P>::to_forwardable... arguments) const
				{return ((Call)objc_msgSend_stret)(object, selector, arguments...);}


			template <class RR = R>
			Z_INLINE typename EnableIf<Type<RR>::is_void, RR>::type
			super(const struct objc_super &object_super, typename Type<P>::to_forwardable... arguments) const
				{((CallSuper)objc_msgSendSuper)((struct objc_super *)&object_super, selector, arguments...);}


			template <class RR = R>
			Z_INLINE typename EnableIf<
				!Type<RR>::is_void &&
				!Type<RR>::is_structure_or_union,
			RR>::type
			super(const struct objc_super &object_super, typename Type<P>::to_forwardable... arguments) const
				{return ((CallSuper)objc_msgSendSuper)((struct objc_super *)&object_super, selector, arguments...);}


			template <class RR = R>
			Z_INLINE typename EnableIf<Type<RR>::is_structure_or_union, RR>::type
			super(const struct objc_super &object_super, typename Type<P>::to_forwardable... arguments) const
				{return ((CallSuper)objc_msgSendSuper_stret)((struct objc_super *)&object_super, selector, arguments...);}


#			if Z_LANGUAGE_INCLUDES(OBJECTIVE_CPP)

				template <class RR = R>
				Z_INLINE typename EnableIf<Type<RR>::is_void, RR>::type
				super(id object, typename Type<P>::to_forwardable... arguments) const
					{
					struct objc_super object_super {object, [[object class] superclass]};
					((CallSuper)objc_msgSendSuper)(&object_super, selector, arguments...);
					}


				template <class RR = R>
				Z_INLINE typename EnableIf<
					!Type<RR>::is_void &&
					!Type<RR>::is_structure_or_union,
				RR>::type
				super(id object, typename Type<P>::to_forwardable... arguments) const
					{
					struct objc_super object_super {object, [[object class] superclass]};
					return ((CallSuper)objc_msgSendSuper)(&object_super, selector, arguments...);
					}


				template <class RR = R>
				Z_INLINE typename EnableIf<Type<RR>::is_structure_or_union, RR>::type
				super(id object, typename Type<P>::to_forwardable... arguments) const
					{
					struct objc_super object_super {object, [[object class] superclass]};
					return ((CallSuper)objc_msgSendSuper_stret)(&object_super, selector, arguments...);
					}

#			endif
		};
	}


#	define Z_HAS_CLASS_Selector TRUE
#else
#	define z_has_class_Selector FALSE
#endif

#endif // _Z_classes_functional_Selector_HPP_
