/* Z Kit C++ API - traits/Type.hpp
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_traits_Type_HPP__
#define __Z_traits_Type_HPP__

#include <Z/types/base.h>
#include <Z/macros/language.hpp>

namespace ZKit {

	// MARK: - Abstract

	namespace Abstract {namespace Type {

		struct Base {
			enum {	is_arithmetic	     = false,
				is_array	     = false,
				is_class	     = false,
				is_callable	     = false,
				is_const	     = false,
				is_const_volatile    = false,
				is_enum		     = false,
				is_exact	     = false,
				is_integer	     = false,
				is_flexible_array    = false,
				is_function	     = false,
				is_member_pointer    = false,
				is_natural	     = false,
				is_number	     = false,
				is_pointer	     = false,
				is_reference	     = false,
				is_real		     = false,
				is_signed	     = false,
				is_union	     = false,
				is_value	     = false,
				is_variadic	     = false,
				is_variadic_function = false,
				is_void		     = false,
				is_volatile	     = false
			};
		};

		struct Number : Base {
			enum {	is_arithmetic = true,
				is_number     = true,
				is_value      = true
			};
		};

		struct Natural : Number {
			enum {	is_exact   = true,
				is_natural = true,
			};
			enum {minimum = 0};
		};

		struct Integer : Number {
			enum {	is_exact   = true,
				is_integer = true,
				is_signed  = true
			};
		};

		struct Real : Number {
			enum {	is_real   = true,
				is_signed = true
			};
		};

		struct UChar : Natural {
			enum {	bits = Z_UCHAR_BITS,
				size = Z_UCHAR_SIZE
			};
			enum {maximum = Z_UCHAR_MAXIMUM};

			typedef unsigned char type;
			typedef unsigned char to_unsigned;
			typedef signed   char to_signed;
		};

		struct UShort : Natural {
			enum {	bits = Z_USHORT_BITS,
				size = Z_USHORT_SIZE
			};
			enum {maximum = Z_USHORT_MAXIMUM};

			typedef unsigned short int type;
			typedef unsigned short int to_unsigned;
			typedef signed	 short int to_signed;
		};

		struct UInt : Natural {
			enum {	bits = Z_UINT_BITS,
				size = Z_UINT_SIZE
			};
			enum {maximum = Z_UINT_MAXIMUM};

			typedef unsigned int type;
			typedef unsigned int to_unsigned;
			typedef signed	 int to_signed;
		};

		struct ULong : Natural {
			enum {	bits = Z_ULONG_BITS,
				size = Z_ULONG_SIZE
			};
			enum {maximum = Z_ULONG_MAXIMUM};

			typedef unsigned long int type;
			typedef unsigned long int to_unsigned;
			typedef signed	 long int to_signed;
		};

		struct ULLong : Natural {
			enum {	bits = Z_ULLONG_BITS,
				size = Z_ULLONG_SIZE
			};
			enum {maximum = Z_ULLONG_MAXIMUM};

			typedef unsigned long long int type;
			typedef unsigned long long int to_unsigned;
			typedef signed	 long long int to_signed;
		};

		struct Char : Integer {
			enum {	bits = Z_CHAR_BITS,
				size = Z_CHAR_SIZE
			};
			enum {	minimum = Z_CHAR_MINIMUM,
				maximum = Z_CHAR_MAXIMUM
			};

			typedef signed	 char type;
			typedef unsigned char to_unsigned;
			typedef signed	 char to_signed;
		};

		struct Short : Integer {
			enum {	bits = Z_SHORT_BITS,
				size = Z_SHORT_SIZE
			};
			enum {	minimum = Z_SHORT_MINIMUM,
				maximum = Z_SHORT_MAXIMUM
			};

			typedef signed	 short int type;
			typedef unsigned short int to_unsigned;
			typedef signed	 short int to_signed;
		};

		struct Int : Integer {
			enum {	bits = Z_INT_BITS,
				size = Z_INT_SIZE
			};
			enum {	minimum = Z_INT_MINIMUM,
				maximum = Z_INT_MAXIMUM
			};

			typedef signed	 int type;
			typedef unsigned int to_unsigned;
			typedef signed	 int to_signed;
		};

		struct Long : Integer {
			enum {	bits = Z_LONG_BITS,
				size = Z_LONG_SIZE
			};
			enum {	minimum = Z_LONG_MINIMUM,
				maximum = Z_LONG_MAXIMUM
			};

			typedef signed	 long int type;
			typedef unsigned long int to_unsigned;
			typedef signed	 long int to_signed;
		};

		struct LLong : Integer {
			enum {	bits = Z_LLONG_BITS,
				size = Z_LLONG_SIZE
			};
			enum {	minimum = Z_LLONG_MINIMUM,
				maximum = Z_LLONG_MAXIMUM
			};

			typedef signed	 long long int type;
			typedef unsigned long long int to_unsigned;
			typedef signed	 long long int to_signed;
		};

		struct Float : Real {
			enum {	bits		    = Z_FLOAT_BITS,
				size		    = Z_FLOAT_SIZE,
				bias		    = Z_FLOAT_BIAS,
				decimal_digits	    = Z_FLOAT_DECIMAL_DIGITS,
				significand_offset  = Z_FLOAT_SIGNIFICAND_OFFSET,
				significand_bits    = Z_FLOAT_SIGNIFICAND_BITS,
				significand_digits  = Z_FLOAT_SIGNIFICAND_DIGITS,
				exponent_offset	    = Z_FLOAT_EXPONENT_OFFSET,
				exponent_bits	    = Z_FLOAT_EXPONENT_BITS,
				exponent_radix	    = Z_FLOAT_EXPONENT_RADIX,
				exponent_minimum    = Z_FLOAT_EXPONENT_MINIMUM,
				exponent_maximum    = Z_FLOAT_EXPONENT_MAXIMUM,
				exponent_10_minimum = Z_FLOAT_EXPONENT_10_MINIMUM,
				exponent_10_maximum = Z_FLOAT_EXPONENT_10_MAXIMUM,
				sign_offset	    = Z_FLOAT_SIGN_OFFSET,
				sign_bits	    = Z_FLOAT_SIGN_BITS
			};

			static inline Z_CONSTANT_EXPRESSION float epsilon() {return Z_FLOAT_EPSILON;}
			static inline Z_CONSTANT_EXPRESSION float minimum() {return Z_FLOAT_MINIMUM;}
			static inline Z_CONSTANT_EXPRESSION float maximum() {return Z_FLOAT_MAXIMUM;}

			typedef float type;
		};

		struct Double : Real {
			enum {	bits		    = Z_DOUBLE_BITS,
				size		    = Z_DOUBLE_SIZE,
				bias		    = Z_DOUBLE_BIAS,
				decimal_digits	    = Z_DOUBLE_DECIMAL_DIGITS,
				significand_offset  = Z_DOUBLE_SIGNIFICAND_OFFSET,
				significand_bits    = Z_DOUBLE_SIGNIFICAND_BITS,
				significand_digits  = Z_DOUBLE_SIGNIFICAND_DIGITS,
				exponent_offset	    = Z_DOUBLE_EXPONENT_OFFSET,
				exponent_bits	    = Z_DOUBLE_EXPONENT_BITS,
				exponent_radix	    = Z_DOUBLE_EXPONENT_RADIX,
				exponent_minimum    = Z_DOUBLE_EXPONENT_MINIMUM,
				exponent_maximum    = Z_DOUBLE_EXPONENT_MAXIMUM,
				exponent_10_minimum = Z_DOUBLE_EXPONENT_10_MINIMUM,
				exponent_10_maximum = Z_DOUBLE_EXPONENT_10_MAXIMUM,
				sign_offset	    = Z_DOUBLE_SIGN_OFFSET,
				sign_bits	    = Z_DOUBLE_SIGN_BITS
			};

			static inline Z_CONSTANT_EXPRESSION double epsilon() {return Z_DOUBLE_EPSILON;}
			static inline Z_CONSTANT_EXPRESSION double minimum() {return Z_DOUBLE_MINIMUM;}
			static inline Z_CONSTANT_EXPRESSION double maximum() {return Z_DOUBLE_MAXIMUM;}

			typedef double type;
		};

		struct LDouble : Real {
			enum {	bits		    = Z_LDOUBLE_BITS,
				size		    = Z_LDOUBLE_SIZE,
				bias		    = Z_LDOUBLE_BIAS,
				decimal_digits	    = Z_LDOUBLE_DECIMAL_DIGITS,
				significand_offset  = Z_LDOUBLE_SIGNIFICAND_OFFSET,
				significand_bits    = Z_LDOUBLE_SIGNIFICAND_BITS,
				significand_digits  = Z_LDOUBLE_SIGNIFICAND_DIGITS,
				exponent_offset	    = Z_LDOUBLE_EXPONENT_OFFSET,
				exponent_bits	    = Z_LDOUBLE_EXPONENT_BITS,
				exponent_radix	    = Z_LDOUBLE_EXPONENT_RADIX,
				exponent_minimum    = Z_LDOUBLE_EXPONENT_MINIMUM,
				exponent_maximum    = Z_LDOUBLE_EXPONENT_MAXIMUM,
				exponent_10_minimum = Z_LDOUBLE_EXPONENT_10_MINIMUM,
				exponent_10_maximum = Z_LDOUBLE_EXPONENT_10_MAXIMUM,
				sign_offset	    = Z_LDOUBLE_SIGN_OFFSET,
				sign_bits	    = Z_LDOUBLE_SIGN_BITS
			};

			static inline Z_CONSTANT_EXPRESSION long double epsilon() {return Z_LDOUBLE_EPSILON;}
			static inline Z_CONSTANT_EXPRESSION long double minimum() {return Z_LDOUBLE_MINIMUM;}
			static inline Z_CONSTANT_EXPRESSION long double maximum() {return Z_LDOUBLE_MAXIMUM;}

			typedef long double type;
		};

		template <typename T> struct Pointer : Base {
			enum {	is_pointer = true,
				is_value   = true
			};

			typedef T* type;
			typedef T  pointee_type;
		};

		template <typename T, zsize N> struct Array : Base {
			enum {is_array = true};
			enum {element_count = N};

			typedef T type[N];
			typedef T element_type;
		};

		template <typename T> struct FlexibleArray : Base {
			enum {	is_array	  = true,
				is_flexible_array = true,
			};

			typedef T type[];
			typedef T element_type;
		};

#		if Z_LANGUAGE_HAS(VARIADIC_TEMPLATE)

			template <class R, class... A> struct Function : Base {
				enum {	is_callable = true,
					is_function = true
				};
				enum {arity = sizeof...(A)};

				typedef R type		     (A...);
				typedef R type_const	     (A...) const;
				typedef R type_volatile	     (A...)	  volatile;
				typedef R type_const_volatile(A...) const volatile;

				typedef R return_type;
			};

			template <class R, class... A> struct VariadicFunction : Function<R, A...> {
				enum {is_variadic = true};

				typedef R type		     (A..., ...);
				typedef R type_const	     (A..., ...) const;
				typedef R type_volatile	     (A..., ...)       volatile;
				typedef R type_const_volatile(A..., ...) const volatile;
			};

#		endif
	}}

	// MARK: - Mixins

	namespace Mixins {namespace Type {

		template <class C> struct Unqualified : C {
			typedef const	       typename C::type add_const;
			typedef	      volatile typename C::type add_volatile;
			typedef const volatile typename C::type add_const_volatile;
			typedef		       typename C::type remove_const;
			typedef		       typename C::type remove_volatile;
			typedef		       typename C::type remove_const_volatile;
		};

		template <class C> struct Const : Unqualified<C> {
			enum {is_const = true};

			typedef const	       typename C::type type;
			typedef const volatile typename C::type add_volatile;
			typedef const	       typename C::type remove_volatile;
		};

		template <class C> struct Volatile : Unqualified<C> {
			enum {is_volatile = true};

			typedef	      volatile typename C::type type;
			typedef const volatile typename C::type add_const;
			typedef	      volatile typename C::type remove_const;
		};

		template <class C> struct ConstVolatile : Unqualified<C> {
			enum {	is_const	  = true,
				is_volatile	  = true,
				is_const_volatile = true
			};

			typedef const volatile typename C::type type;
			typedef const volatile typename C::type add_const;
			typedef const volatile typename C::type add_volatile;
			typedef	      volatile typename C::type remove_const;
			typedef const	       typename C::type remove_volatile;
		};

		template <class C> struct ConstArray : Const<C> {
			typedef const typename C::element_type element_type;
		};

		template <class C> struct VolatileArray : Volatile<C> {
			typedef volatile typename C::element_type element_type;
		};

		template <class C> struct ConstVolatileArray : ConstVolatile<C> {
			typedef const volatile typename C::element_type element_type;
		};

		template <class C> struct UnqualifiedFunction : C {
			typedef typename C::type_const		add_const;
			typedef typename C::type_volatile	add_volatile;
			typedef typename C::type_const_volatile add_const_volatile;
			typedef typename C::type		remove_const;
			typedef typename C::type		remove_volatile;
			typedef typename C::type		remove_const_volatile;
		};

		template <class C> struct ConstFunction : UnqualifiedFunction<C> {
			enum {is_const = true};

			typedef typename C::type_const		type;
			typedef typename C::type_const_volatile add_volatile;
			typedef typename C::type_const		remove_volatile;
		};

		template <class C> struct VolatileFunction : UnqualifiedFunction<C> {
			enum {is_volatile = true};

			typedef typename C::type_volatile	type;
			typedef typename C::type_const_volatile add_const;
			typedef typename C::type_volatile	remove_const;
		};

		template <class C> struct ConstVolatileFunction : UnqualifiedFunction<C> {
			enum {	is_const	  = true,
				is_volatile	  = true,
				is_const_volatile = true
			};

			typedef typename C::type_const_volatile type;
			typedef typename C::type_const_volatile add_const;
			typedef typename C::type_const_volatile add_volatile;
			typedef typename C::type_volatile	remove_const;
			typedef typename C::type_const		remove_volatile;
		};
	}}

	template <typename T> struct Type : Abstract::Type::Base {};

	// MARK: - void

	template <> struct Type<void> : Abstract::Type::Base {enum {is_void = true};};

	// MARK: - Numbers

	template <> struct Type<unsigned char	      > : Mixins::Type::Unqualified<Abstract::Type::UChar  > {};
	template <> struct Type<unsigned short int    > : Mixins::Type::Unqualified<Abstract::Type::UShort > {};
	template <> struct Type<unsigned int	      > : Mixins::Type::Unqualified<Abstract::Type::UInt   > {};
	template <> struct Type<unsigned long int     > : Mixins::Type::Unqualified<Abstract::Type::ULong  > {};
	template <> struct Type<unsigned long long int> : Mixins::Type::Unqualified<Abstract::Type::ULLong > {};
	template <> struct Type<signed char	      > : Mixins::Type::Unqualified<Abstract::Type::Char   > {};
	template <> struct Type<signed short int      > : Mixins::Type::Unqualified<Abstract::Type::Short  > {};
	template <> struct Type<signed int	      > : Mixins::Type::Unqualified<Abstract::Type::Int	   > {};
	template <> struct Type<signed long int	      > : Mixins::Type::Unqualified<Abstract::Type::Long   > {};
	template <> struct Type<signed long long int  > : Mixins::Type::Unqualified<Abstract::Type::LLong  > {};
	template <> struct Type<float		      > : Mixins::Type::Unqualified<Abstract::Type::Float  > {};
	template <> struct Type<double		      > : Mixins::Type::Unqualified<Abstract::Type::Double > {};
	template <> struct Type<long double	      > : Mixins::Type::Unqualified<Abstract::Type::LDouble> {};

	template <typename T> struct Type<const T> : Mixins::Type::Const<Type<T> > {
		typedef const typename Type<T>::to_unsigned to_unsigned;
		typedef const typename Type<T>::to_signed   to_signed;
	};

	template <typename T> struct Type<volatile T> : Mixins::Type::Volatile<Type<T> > {
		typedef volatile typename Type<T>::to_unsigned to_unsigned;
		typedef volatile typename Type<T>::to_signed   to_signed;
	};

	template <typename T> struct Type<const volatile T> : Mixins::Type::ConstVolatile<Type<T> > {
		typedef const volatile typename Type<T>::to_unsigned to_unsigned;
		typedef const volatile typename Type<T>::to_signed   to_signed;
	};

	// MARK: - Pointers

	template <typename T> struct Type<T*> : Mixins::Type::Unqualified<Abstract::Type::Pointer<T> > {};

	template <typename T> struct Type<T* const	   > : Mixins::Type::Const	  <Type<T*> > {};
	template <typename T> struct Type<T*	   volatile> : Mixins::Type::Volatile	  <Type<T*> > {};
	template <typename T> struct Type<T* const volatile> : Mixins::Type::ConstVolatile<Type<T*> > {};

	// MARK: - References

	template <typename T> struct Type<T&> : Abstract::Type::Base {
		enum {is_reference = true};

		typedef T& type;
		typedef T  referenced_type;
	};

	// MARK: - Arrays

 	template <typename T, zsize N> struct Type<T[N]> : Mixins::Type::Unqualified<Abstract::Type::Array<T, N> > {};

	template <typename T, zsize N> struct Type<const	  T[N]> : Mixins::Type::ConstArray	  <Type<T[N]> > {};
	template <typename T, zsize N> struct Type<	 volatile T[N]> : Mixins::Type::VolatileArray	  <Type<T[N]> > {};
	template <typename T, zsize N> struct Type<const volatile T[N]> : Mixins::Type::ConstVolatileArray<Type<T[N]> > {};

	// MARK: - Flexible arrays

	template <typename T> struct Type<T[]> : Mixins::Type::Unqualified<Abstract::Type::FlexibleArray<T> > {};

	template <typename T> struct Type<const		 T[]> : Mixins::Type::ConstArray	<Type<T[]> > {};
	template <typename T> struct Type<	volatile T[]> : Mixins::Type::VolatileArray	<Type<T[]> > {};
	template <typename T> struct Type<const volatile T[]> : Mixins::Type::ConstVolatileArray<Type<T[]> > {};

	// MARK: - Functions

#	if Z_LANGUAGE_HAS(VARIADIC_TEMPLATE)

		template <class R, class... A> struct Type<R(A...)> : Mixins::Type::UnqualifiedFunction<Abstract::Type::Function<R, A...> > {};

		template <class R, class... A> struct Type<R(A...) const	 > : Mixins::Type::ConstFunction	<Type<R(A...)> > {};
		template <class R, class... A> struct Type<R(A...)	 volatile> : Mixins::Type::VolatileFunction     <Type<R(A...)> > {};
		template <class R, class... A> struct Type<R(A...) const volatile> : Mixins::Type::ConstVolatileFunction<Type<R(A...)> > {};

		template <class R, class... A> struct Type<R(A..., ...)> : Mixins::Type::UnqualifiedFunction<Abstract::Type::VariadicFunction<R, A...> > {};

		template <class R, class... A> struct Type<R(A..., ...) const	      > : Mixins::Type::ConstFunction	     <Type<R(A..., ...)> > {};
		template <class R, class... A> struct Type<R(A..., ...)	      volatile> : Mixins::Type::VolatileFunction     <Type<R(A..., ...)> > {};
		template <class R, class... A> struct Type<R(A..., ...) const volatile> : Mixins::Type::ConstVolatileFunction<Type<R(A..., ...)> > {};

#		if Z_LANGUAGE_HAS(REFERENCE_QUALIFIED_FUNCTION)

			template <class R, class... A> struct Type<R(A...) &> : Type<R(A...)> {};

			template <class R, class... A> struct Type<R(A...) const	  &> : Mixins::Type::ConstFunction	  <Type<R(A...) &> > {};
			template <class R, class... A> struct Type<R(A...)	 volatile &> : Mixins::Type::VolatileFunction	  <Type<R(A...) &> > {};
			template <class R, class... A> struct Type<R(A...) const volatile &> : Mixins::Type::ConstVolatileFunction<Type<R(A...) &> > {};

			template <class R, class... A> struct Type<R(A...) &&> : Type<R(A...)> {};

			template <class R, class... A> struct Type<R(A...) const	  &&> : Mixins::Type::ConstFunction	   <Type<R(A...) &&> > {};
			template <class R, class... A> struct Type<R(A...)	 volatile &&> : Mixins::Type::VolatileFunction	   <Type<R(A...) &&> > {};
			template <class R, class... A> struct Type<R(A...) const volatile &&> : Mixins::Type::ConstVolatileFunction<Type<R(A...) &&> > {};

			template <class R, class... A> struct Type<R(A..., ...) &> : Type<R(A..., ...)> {};

			template <class R, class... A> struct Type<R(A..., ...) const	       & > : Mixins::Type::ConstFunction	<Type<R(A..., ...) &> > {};
			template <class R, class... A> struct Type<R(A..., ...)	      volatile & > : Mixins::Type::VolatileFunction	<Type<R(A..., ...) &> > {};
			template <class R, class... A> struct Type<R(A..., ...) const volatile & > : Mixins::Type::ConstVolatileFunction<Type<R(A..., ...) &> > {};

			template <class R, class... A> struct Type<R(A..., ...) &&> : Type<R(A..., ...)> {};

			template <class R, class... A> struct Type<R(A..., ...) const	       &&> : Mixins::Type::ConstFunction	<Type<R(A..., ...) &&> > {};
			template <class R, class... A> struct Type<R(A..., ...)	      volatile &&> : Mixins::Type::VolatileFunction	<Type<R(A..., ...) &&> > {};
			template <class R, class... A> struct Type<R(A..., ...) const volatile &&> : Mixins::Type::ConstVolatileFunction<Type<R(A..., ...) &&> > {};

#		endif

#	endif
}

#endif // __Z_traits_Type_HPP__
