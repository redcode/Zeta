/* Z Kit C++ API - classes/functional/ObjectSelector.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_classes_functional_ObjectSelector_HPP__
#define __Z_classes_functional_ObjectSelector_HPP__

#include <Z/classes/functional/Selector.hpp>

#if Z_HAS_CLASS_SELECTOR && Z_LANGUAGE_INCLUDES(OBJECTIVE_CPP)


	namespace Zeta {
		template <class F> struct ObjectSelector;

		template <class R, class... P> struct ObjectSelector<R(P...)> : Selector<R(P...)> {
			id object;

			Z_INLINE_MEMBER ObjectSelector() {}

			Z_CT_MEMBER(CPP11) ObjectSelector(id object, SEL selector) : Selector(selector), object(object) {}

			template <bool returns_void = Type<R>::is_void>
			Z_INLINE_MEMBER typename EnableIf<returns_void, void>::type
			operator ()(typename Type<P>::to_forwardable... arguments) const
				{((Caller)caller)(object, this->selector, arguments...);}


			template <bool returns_void = Type<R>::is_void>
			Z_INLINE_MEMBER typename EnableIf<!returns_void, R>::type
			operator ()(typename Type<P>::to_forwardable... arguments) const
				{return ((Caller)caller)(object, this->selector, arguments...);}


			template <bool returns_void = Type<R>::is_void>
			Z_INLINE_MEMBER typename EnableIf<returns_void, void>::type
			super(typename Type<P>::to_forwardable... arguments) const
				{
				struct objc_super object_super {object, [[object class] superclass]};
				((SuperCaller)super_caller)(&object_super, this->selector, arguments...);
				}

			template <bool returns_void = Type<R>::is_void>
			Z_INLINE_MEMBER typename EnableIf<!returns_void, R>::type
			super(typename Type<P>::to_forwardable... arguments) const
				{
				struct objc_super object_super {object, [[object class] superclass]};
				return ((SuperCaller)super_caller)(&object_super, this->selector, arguments...);
				}
		};

	}


#	define Z_HAS_CLASS_ObjectSelector TRUE
#else
#	define Z_HAS_CLASS_ObjectSelector FALSE
#endif

#endif // __Z_classes_functional_Selector_HPP__
