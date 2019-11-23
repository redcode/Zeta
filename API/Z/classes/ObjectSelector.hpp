/* Z Kit - classes/ObjectSelector.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//__/__| Kit
Copyright (C) 2006-2020 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_classes_ObjectSelector_HPP
#define Z_classes_ObjectSelector_HPP

#include <Z/inspection/Z.h>
#include <Z/classes/Selector.hpp>

#if Z_DECLARES(Selector)


	namespace Zeta {

		template <class F> struct ObjectSelector;

		template <class R, class... P> struct ObjectSelector<R(P...)> : Selector<R(P...)> {
			typedef typename Selector<R(P...)>::Call      Call;
			typedef typename Selector<R(P...)>::CallSuper CallSuper;

			id object;


			Z_INLINE ObjectSelector() Z_NOTHROW
				Z_DEFAULTED({})


			Z_INLINE ObjectSelector(id object, SEL selector) Z_NOTHROW
			: Selector<R(P...)>(selector), object(object) {}


			Z_INLINE operator id() const Z_NOTHROW
				{return object;}


			Z_INLINE ObjectSelector &operator =(SEL rhs) Z_NOTHROW
				{this->selector = rhs; return *this;}


			Z_INLINE ObjectSelector &operator =(id rhs) Z_NOTHROW
				{object = rhs; return *this;}


			template <class RR = R>
			Z_INLINE typename TypeIf<Type<RR>::is_void, RR>::type
			operator ()(typename Type<P>::to_forwardable... arguments) const Z_NOTHROW
				{reinterpret_cast<Call>(objc_msgSend)(object, this->selector, arguments...);}


			template <class RR = R>
			Z_INLINE typename TypeIf<Type<RR>::is_void, RR>::type
			operator ()(id object, typename Type<P>::to_forwardable... arguments) const Z_NOTHROW
				{reinterpret_cast<Call>(objc_msgSend)(object, this->selector, arguments...);}


#			if Z_ISA_IS(X86_64) || Z_ISA_IS(X86_32)

				template <class RR = R>
				Z_INLINE typename TypeIf<!Type<RR>::is_void && !Type<RR>::is_real && !Type<RR>::is_class, RR>::type
				operator ()(typename Type<P>::to_forwardable... arguments) const Z_NOTHROW
					{return reinterpret_cast<Call>(objc_msgSend)(object, this->selector, arguments...);}


				template <class RR = R>
				Z_INLINE typename TypeIf<!Type<RR>::is_void && !Type<RR>::is_real && !Type<RR>::is_class, RR>::type
				operator ()(id object, typename Type<P>::to_forwardable... arguments) const Z_NOTHROW
					{return reinterpret_cast<Call>(objc_msgSend)(object, this->selector, arguments...);}


				template <class RR = R>
				Z_INLINE typename TypeIf<Type<RR>::is_real, RR>::type
				operator ()(typename Type<P>::to_forwardable... arguments) const Z_NOTHROW
					{return reinterpret_cast<Call>(objc_msgSend_fpret)(object, this->selector, arguments...);}


				template <class RR = R>
				Z_INLINE typename TypeIf<Type<RR>::is_real, RR>::type
				operator ()(id object, typename Type<P>::to_forwardable... arguments) const Z_NOTHROW
					{return reinterpret_cast<Call>(objc_msgSend_fpret)(object, this->selector, arguments...);}

#			else

				template <class RR = R>
				Z_INLINE typename TypeIf<!Type<RR>::is_void && !Type<RR>::is_class, RR>::type
				operator ()(typename Type<P>::to_forwardable... arguments) const Z_NOTHROW
					{return reinterpret_cast<Call>(objc_msgSend)(object, this->selector, arguments...);}


				template <class RR = R>
				Z_INLINE typename TypeIf<!Type<RR>::is_void && !Type<RR>::is_class, RR>::type
				operator ()(id object, typename Type<P>::to_forwardable... arguments) const Z_NOTHROW
					{return reinterpret_cast<Call>(objc_msgSend)(object, this->selector, arguments...);}

#			endif


			template <class RR = R>
			Z_INLINE typename TypeIf<Type<RR>::is_class, RR>::type
			operator ()(typename Type<P>::to_forwardable... arguments) const Z_NOTHROW
				{return reinterpret_cast<Call>(objc_msgSend_stret)(object, this->selector, arguments...);}


			template <class RR = R>
			Z_INLINE typename TypeIf<Type<RR>::is_class, RR>::type
			operator ()(id object, typename Type<P>::to_forwardable... arguments) const Z_NOTHROW
				{return reinterpret_cast<Call>(objc_msgSend_stret)(object, this->selector, arguments...);}


			template <class RR = R>
			Z_INLINE typename TypeIf<Type<RR>::is_void, RR>::type
			super(const struct objc_super &object_super, typename Type<P>::to_forwardable... arguments) const Z_NOTHROW
				{
				reinterpret_cast<CallSuper>(objc_msgSendSuper)
					(const_cast<struct objc_super *>(&object_super), this->selector, arguments...);
				}


			template <class RR = R>
			Z_INLINE typename TypeIf<!Type<RR>::is_void && !Type<RR>::is_class, RR>::type
			super(const struct objc_super &object_super, typename Type<P>::to_forwardable... arguments) const Z_NOTHROW
				{
				return reinterpret_cast<CallSuper>(objc_msgSendSuper)
					(const_cast<struct objc_super *>(&object_super), this->selector, arguments...);
				}


			template <class RR = R>
			Z_INLINE typename TypeIf<Type<RR>::is_class, RR>::type
			super(const struct objc_super &object_super, typename Type<P>::to_forwardable... arguments) const Z_NOTHROW
				{
				return reinterpret_cast<CallSuper>(objc_msgSendSuper_stret)
					(const_cast<struct objc_super *>(&object_super), this->selector, arguments...);
				}


			Z_INLINE ObjectSelector &set(id object, SEL selector) Z_NOTHROW
				{
				this->selector = selector;
				this->object   = object;
				return *this;
				}


#			if Z_LANGUAGE_INCLUDES(OBJECTIVE_CPP)

				template <class RR = R>
				Z_INLINE typename TypeIf<Type<RR>::is_void, RR>::type
				super(typename Type<P>::to_forwardable... arguments) const Z_NOTHROW
					{
					struct objc_super object_super {object, [[object class] superclass]};
					reinterpret_cast<CallSuper>(objc_msgSendSuper)(&object_super, this->selector, arguments...);
					}


				template <class RR = R>
				Z_INLINE typename TypeIf<Type<RR>::is_void, RR>::type
				super(id object, typename Type<P>::to_forwardable... arguments) const Z_NOTHROW
					{
					struct objc_super object_super {object, [[object class] superclass]};
					reinterpret_cast<CallSuper>(objc_msgSendSuper)(&object_super, this->selector, arguments...);
					}


				template <class RR = R>
				Z_INLINE typename TypeIf<!Type<RR>::is_void && !Type<RR>::is_class, RR>::type
				super(typename Type<P>::to_forwardable... arguments) const Z_NOTHROW
					{
					struct objc_super object_super {object, [[object class] superclass]};
					return reinterpret_cast<CallSuper>(objc_msgSendSuper)(&object_super, this->selector, arguments...);
					}


				template <class RR = R>
				Z_INLINE typename TypeIf<!Type<RR>::is_void && !Type<RR>::is_class, RR>::type
				super(id object, typename Type<P>::to_forwardable... arguments) const Z_NOTHROW
					{
					struct objc_super object_super {object, [[object class] superclass]};
					return reinterpret_cast<CallSuper>(objc_msgSendSuper)(&object_super, this->selector, arguments...);
					}


				template <class RR = R>
				Z_INLINE typename TypeIf<Type<RR>::is_class, RR>::type
				super(typename Type<P>::to_forwardable... arguments) const Z_NOTHROW
					{
					struct objc_super object_super {object, [[object class] superclass]};
					return reinterpret_cast<CallSuper>(objc_msgSendSuper_stret)(&object_super, this->selector, arguments...);
					}


				template <class RR = R>
				Z_INLINE typename TypeIf<Type<RR>::is_class, RR>::type
				super(id object, typename Type<P>::to_forwardable... arguments) const Z_NOTHROW
					{
					struct objc_super object_super {object, [[object class] superclass]};
					return reinterpret_cast<CallSuper>(objc_msgSendSuper_stret)(&object_super, this->selector, arguments...);
					}

#			endif
		};
	}


#	define Z_DECLARES_ObjectSelector TRUE
#else
#	define Z_DECLARES_ObjectSelector FALSE
#endif

#endif // Z_classes_ObjectSelector_HPP
