/* Zeta API - Z/classes/ObjectSelector.hpp
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_classes_ObjectSelector_HPP
#define Z_classes_ObjectSelector_HPP

#include <Z/inspection/Z.h>
#include <Z/classes/Selector.hpp>

#if Z_HAS(Selector)
#	define Z_HAS_ObjectSelector 1


	namespace Zeta {
		template <class f> struct ObjectSelector;

		template <class r, class... p>
		struct ObjectSelector<r(p...)> {
			typedef r (* Send     )(id,		     SEL, p...);
			typedef r (* SendSuper)(struct objc_super *, SEL, p...);

			SEL selector;
			id  object;


			Z_INLINE ObjectSelector() Z_NOTHROW
				Z_DEFAULTED({})


			Z_INLINE ObjectSelector(id object_, SEL selector_) Z_NOTHROW
			: object(object_), selector(selector_) {}


			Z_INLINE operator id() const Z_NOTHROW
				{return object;}


			Z_INLINE operator SEL() const Z_NOTHROW
				{return selector;}


			Z_INLINE ObjectSelector &operator =(SEL rhs) Z_NOTHROW
				{selector = rhs; return *this;}


			Z_INLINE ObjectSelector &operator =(id rhs) Z_NOTHROW
				{object = rhs; return *this;}


			Z_INLINE r operator ()(typename Type<p>::to_forwardable... arguments) const Z_NOTHROW
			{return (Send(ObjectiveC::send<r>()))(object, selector, arguments...);}


			Z_INLINE r operator ()(id object_, typename Type<p>::to_forwardable... arguments) const Z_NOTHROW
			{return (Send(ObjectiveC::send<r>()))(object_, selector, arguments...);}


			Z_INLINE r super(typename Type<p>::to_forwardable... arguments) const Z_NOTHROW
				{
				struct objc_super object_super {object, class_getSuperclass(object_getClass(object))};
				return (SendSuper(objc_msgSendSuper))(&object_super, this->selector, arguments...);
				}


			Z_INLINE r super(id object, typename Type<p>::to_forwardable... arguments) const Z_NOTHROW
				{
				struct objc_super object_super {object, class_getSuperclass(object_getClass(object))};
				return (SendSuper(objc_msgSendSuper))(&object_super, this->selector, arguments...);
				}


			Z_INLINE r super(const struct objc_super &object_super, typename Type<p>::to_forwardable... arguments) const Z_NOTHROW
				{
				return (SendSuper(ObjectiveC::send_super<r>()))
					(const_cast<struct objc_super *>(&object_super), selector, arguments...);
				}


			Z_INLINE ObjectSelector &set(id object, SEL selector) Z_NOTHROW
				{
				this->selector = selector;
				this->object   = object;
				return *this;
				}
		};
	}
#endif

#endif // Z_classes_ObjectSelector_HPP
