/* Zeta API - Z/classes/Selector.hpp
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_classes_Selector_HPP
#define Z_classes_Selector_HPP

#include <Z/inspection/language.h>

#if	Z_DIALECT_HAS(CPP98, SFINAE)		&& \
	Z_DIALECT_HAS(CPP11, VARIADIC_TEMPLATE) && \
	Z_DIALECT_HAS(CPP11, DEFAULT_TEMPLATE_ARGUMENTS_FOR_FUNCTION_TEMPLATE)

#	include <Z/traits/type.hpp>
#	include <Z/functions/Objective-C.hpp>

#	if  Z_DIALECT_HAS(CPP11, RVALUE_REFERENCE)
#		include <Z/functions/casting.hpp>
#	endif

#	define Z_HAS_Selector 1


	namespace Zeta {
		template <class f> struct Selector;


		template <class r, class... p>
		struct Selector<r(p...)> {
			typedef r (* Send     )(id,	      SEL, p...);
			typedef r (* SendSuper)(objc_super *, SEL, p...);

			SEL selector;


			Z_INLINE Selector()
				Z_DEFAULTED({})


			Z_INLINE Selector(SEL selector_)
			: selector(selector_) {}


			Z_INLINE operator SEL() const Z_NOTHROW
				{return selector;}


			Z_INLINE r operator ()(id object, typename Type<p>::to_forwardable... arguments) const Z_NOTHROW
				{
				return (Send(ObjectiveC::send<r>()))
					(object, selector, arguments...);
				}


			Z_INLINE r super(id object, typename Type<p>::to_forwardable... arguments) const Z_NOTHROW
				{
				objc_super object_super = {object, class_getSuperclass(object_getClass(object))};

				return (SendSuper(ObjectiveC::send_super<r>()))
					(&object_super, selector, arguments...);
				}


			Z_INLINE r super(const objc_super &object_super, typename Type<p>::to_forwardable... arguments) const Z_NOTHROW
				{
				return (SendSuper(ObjectiveC::send_super<r>()))
					(const_cast<objc_super *>(&object_super), selector, arguments...);
				}
		};


#		if  Z_DIALECT_HAS(CPP11, RVALUE_REFERENCE)
			template <class r, class... p>
			struct Selector<r(p..., ...)> {
				typedef r (* Send     )(id,	      SEL, p..., ...);
				typedef r (* SendSuper)(objc_super *, SEL, p..., ...);

				SEL selector;


				Z_INLINE Selector()
					Z_DEFAULTED({})


				Z_INLINE Selector(SEL selector)
				: selector(selector) {}


				Z_INLINE operator SEL() const Z_NOTHROW
					{return selector;}


				template <class... pp>
				Z_INLINE r operator ()(id object, pp&&... arguments) const Z_NOTHROW
					{
					return (Send(ObjectiveC::send<r>()))
						(object, selector, forwardable<pp>(arguments)...);
					}


				template <class... pp>
				Z_INLINE r super(id object, pp&&... arguments) const Z_NOTHROW
					{
					objc_super object_super = {object, class_getSuperclass(object_getClass(object))};

					return (SendSuper(ObjectiveC::send_super<r>()))
						(&object_super, selector, forwardable<pp>(arguments)...);
					}


				template <class... pp>
				Z_INLINE r super(const objc_super &object_super, pp&&... arguments) const Z_NOTHROW
					{
					return (SendSuper(ObjectiveC::send_super<r>()))
						(const_cast<objc_super *>(&object_super), selector, forwardable<pp>(arguments)...);
					}
			};
#		endif
	}


#endif

#endif // Z_classes_Selector_HPP
