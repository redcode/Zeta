/* Z Kit C++ API - classes/functional/Selector.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_classes_functional_Selector_HPP__
#define __Z_classes_functional_Selector_HPP__

#include <Z/traits/filtering.hpp>

#if	Z_LANGUAGE_HAS_SPECIFIER(CPP, AUTO)				      && \
	Z_LANGUAGE_HAS_SPECIFIER(CPP, CONSTANT_EXPRESSION)		      && \
	Z_LANGUAGE_HAS(CPP, DEFAULT_TEMPLATE_ARGUMENTS_FOR_FUNCTION_TEMPLATE) && \
	Z_LANGUAGE_HAS(CPP, SFINAE)

#	include <Z/traits/Type.hpp>
#	include <objc/message.h>


	namespace Zeta {

		template <class F> struct Selector;

		template <class R, class... P> struct Selector<R(P...)> {
			SEL selector;

			typedef R (* Caller	)(id,		      SEL, P...);
			typedef R (* SuperCaller)(struct objc_super*, SEL, P...);

#			if Z_CPU_ARCHITECTURE == Z_CPU_ARCHITECTURE_AARCH64
				static Z_CONSTANT Caller      caller	   = (Caller	 )objc_msgSend;
				static Z_CONSTANT SuperCaller super_caller = (SuperCaller)objc_msgSendSuper;
#			else
				static Z_CONSTANT auto caller = Type<R>::is_compound
					? objc_msgSend_stret
					: (Type<R>::is_real ? objc_msgSend_fpret : objc_msgSend);

				static Z_CONSTANT auto super_caller = Type<R>::is_compound
					? objc_msgSendSuper_stret
					: objc_msgSendSuper;
#			endif

			Z_INLINE_MEMBER Selector() {}

			Z_CT_MEMBER(CPP11) Selector(SEL selector) : selector(selector) {}

			Z_CT_MEMBER(CPP11) operator SEL() const {return selector;}


			template <bool returns_void = Type<R>::is_void>
			Z_INLINE_MEMBER typename EnableIf<returns_void, void>::type
			operator ()(id object, typename Type<P>::to_forwardable... arguments) const
				{((Caller)caller)(object, selector, arguments...);}


			template <bool returns_void = Type<R>::is_void>
			Z_INLINE_MEMBER typename EnableIf<!returns_void, R>::type
			operator ()(id object, typename Type<P>::to_forwardable... arguments) const
				{return ((Caller)caller)(object, selector, arguments...);}


			template <bool returns_void = Type<R>::is_void>
			Z_INLINE_MEMBER typename EnableIf<returns_void, void>::type
			super(const struct objc_super &object_super, typename Type<P>::to_forwardable... arguments) const
				{((SuperCaller)super_caller)((struct objc_super *)&object_super, selector, arguments...);}


			template <bool returns_void = Type<R>::is_void>
			Z_INLINE_MEMBER typename EnableIf<!returns_void, R>::type
			super(const struct objc_super &object_super, typename Type<P>::to_forwardable... arguments) const
				{return ((SuperCaller)super_caller)((struct objc_super *)&object_super, selector, arguments...);}


#			if Z_LANGUAGE_INCLUDES(OBJECTIVE_CPP)

				template <bool returns_void = Type<R>::is_void>
				Z_INLINE_MEMBER typename EnableIf<returns_void, void>::type
				super(id object, typename Type<P>::to_forwardable... arguments) const
					{
					struct objc_super object_super {object, [[object class] superclass]};
					((SuperCaller)super_caller)(&object_super, selector, arguments...);
					}

				template <bool returns_void = Type<R>::is_void>
				Z_INLINE_MEMBER typename EnableIf<!returns_void, R>::type
				super(id object, typename Type<P>::to_forwardable... arguments) const
					{
					struct objc_super object_super {object, [[object class] superclass]};
					return ((SuperCaller)super_caller)(&object_super, selector, arguments...);
					}

#			endif
		};
	}


#	define Z_HAS_CLASS_SELECTOR TRUE
#else
#	define Z_HAS_CLASS_SELECTOR FALSE
#endif

#endif // __Z_classes_functional_Selector_HPP__
