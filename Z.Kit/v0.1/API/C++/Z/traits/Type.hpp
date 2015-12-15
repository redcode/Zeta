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

namespace ZKit {

	// MARK: - Abstract

	namespace Abstract {namespace Type {

		struct Base {
			enum {	is_arithmetic	  = false,
				is_array	  = false,
				is_class	  = false,
				is_callable	  = false,
				is_const	  = false,
				is_const_volatile = false,
				is_enum		  = false,
				is_exact	  = false,
				is_integer	  = false,
				is_function	  = false,
				is_member_pointer = false,
				is_natural	  = false,
				is_pointer	  = false,
				is_reference	  = false,
				is_real		  = false,
				is_signed	  = false,
				is_union	  = false,
				is_number	  = false,
				is_variadic	  = false,
				is_void		  = false,
				is_volatile	  = false
			};
		};

		struct Number : Base {
			enum {	is_number     = true,
				is_arithmetic = true
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

		struct Char {
			typedef		       unsigned char base_unsigned_type;
			typedef const	       unsigned char const_unsigned_type;
			typedef	      volatile unsigned char volatile_unsigned_type;
			typedef const volatile unsigned char const_volatile_unsigned_type;
			typedef		      	 signed char base_signed_type;
			typedef const	      	 signed char const_signed_type;
			typedef	      volatile	 signed char volatile_signed_type;
			typedef const volatile	 signed char const_volatile_signed_type;	
		};

		struct Short {
			typedef		       unsigned short int base_unsigned_type;
			typedef const	       unsigned short int const_unsigned_type;
			typedef	      volatile unsigned short int volatile_unsigned_type;
			typedef const volatile unsigned short int const_volatile_unsigned_type;
			typedef		      	 signed short int base_signed_type;
			typedef const	      	 signed short int const_signed_type;
			typedef	      volatile	 signed short int volatile_signed_type;
			typedef const volatile	 signed short int const_volatile_signed_type;	
		};

		struct Int {
			typedef		       unsigned int base_unsigned_type;
			typedef const	       unsigned int const_unsigned_type;
			typedef	      volatile unsigned int volatile_unsigned_type;
			typedef const volatile unsigned int const_volatile_unsigned_type;
			typedef		      	 signed int base_signed_type;
			typedef const	      	 signed int const_signed_type;
			typedef	      volatile	 signed int volatile_signed_type;
			typedef const volatile	 signed int const_volatile_signed_type;	
		};

		struct Long {
			typedef		       unsigned long int base_unsigned_type;
			typedef const	       unsigned long int const_unsigned_type;
			typedef	      volatile unsigned long int volatile_unsigned_type;
			typedef const volatile unsigned long int const_volatile_unsigned_type;
			typedef		      	 signed long int base_signed_type;
			typedef const	      	 signed long int const_signed_type;
			typedef	      volatile	 signed long int volatile_signed_type;
			typedef const volatile	 signed long int const_volatile_signed_type;	
		};

		struct LLong {
			typedef		       unsigned long long int base_unsigned_type;
			typedef const	       unsigned long long int const_unsigned_type;
			typedef	      volatile unsigned long long int volatile_unsigned_type;
			typedef const volatile unsigned long long int const_volatile_unsigned_type;
			typedef		      	 signed long long int base_signed_type;
			typedef const	      	 signed long long int const_signed_type;
			typedef	      volatile	 signed long long int volatile_signed_type;
			typedef const volatile	 signed long long int const_volatile_signed_type;	
		};
	}}

	namespace Mixins {namespace Type {

		template <class C> struct Const	   : C {enum {is_const    = true};};
		template <class C> struct Volatile : C {enum {is_volatile = true};};

		template <class C> struct ConstVolatile : C {
			enum {	is_const	  = true,
				is_volatile	  = true,
				is_const_volatile = true
			};
		};
	}}


	template <typename T> struct Type : Abstract::Type::Base {};

	// MARK: - void

	template <> struct Type<void> : Abstract::Type::Base {enum {is_void = true};};

	// MARK: - Numbers

	template <> struct Type<unsigned char> : Abstract::Type::Natural, Abstract::Type::Char {
		enum {	bits = Z_UCHAR_BITS,
			size = Z_UCHAR_SIZE
		};
		enum {maximum = Z_UCHAR_MAXIMUM};

		typedef		       unsigned char base_type;
		typedef const	       unsigned char const_type;
		typedef	      volatile unsigned char volatile_type;
		typedef const volatile unsigned char const_volatile_type;
	};

	template <> struct Type<unsigned short int> : Abstract::Type::Natural, Abstract::Type::Short {
		enum {	bits = Z_USHORT_BITS,
			size = Z_USHORT_SIZE
		};
		enum {maximum = Z_USHORT_MAXIMUM};

		typedef		       unsigned short int base_type;
		typedef const	       unsigned short int const_type;
		typedef	      volatile unsigned short int volatile_type;
		typedef const volatile unsigned short int const_volatile_type;
	};

	template <> struct Type<unsigned int> : Abstract::Type::Natural, Abstract::Type::Int {
		enum {	bits = Z_UINT_BITS,
			size = Z_UINT_SIZE
		};
		enum {maximum = Z_UINT_MAXIMUM};

		typedef		       unsigned int base_type;
		typedef const	       unsigned int const_type;
		typedef	      volatile unsigned int volatile_type;
		typedef const volatile unsigned int const_volatile_type;
	};

	template <> struct Type<unsigned long int> : Abstract::Type::Natural, Abstract::Type::Long {
		enum {	bits = Z_ULONG_BITS,
			size = Z_ULONG_SIZE
		};
		enum {maximum = Z_ULONG_MAXIMUM};

		typedef		       unsigned long int base_type;
		typedef const	       unsigned long int const_type;
		typedef	      volatile unsigned long int volatile_type;
		typedef const volatile unsigned long int const_volatile_type;
	};

	template <> struct Type<unsigned long long int>	: Abstract::Type::Natural, Abstract::Type::LLong {
		enum {	bits = Z_ULLONG_BITS,
			size = Z_ULLONG_SIZE
		};
		enum {maximum = Z_ULLONG_MAXIMUM};

		typedef		       unsigned long long int base_type;
		typedef const	       unsigned long long int const_type;
		typedef	      volatile unsigned long long int volatile_type;
		typedef const volatile unsigned long long int const_volatile_type;
	};

	template <> struct Type<signed char> : Abstract::Type::Integer, Abstract::Type::Char {
		enum {	bits = Z_CHAR_BITS,
			size = Z_CHAR_SIZE
		};
		enum {	minimum = Z_CHAR_MINIMUM,
			maximum = Z_CHAR_MAXIMUM
		};

		typedef		       signed char base_type;
		typedef const	       signed char const_type;
		typedef	      volatile signed char volatile_type;
		typedef const volatile signed char const_volatile_type;
	};

	template <> struct Type<signed short int> : Abstract::Type::Integer, Abstract::Type::Short {
		enum {	bits = Z_SHORT_BITS,
			size = Z_SHORT_SIZE
		};
		enum {	minimum = Z_SHORT_MINIMUM,
			maximum = Z_SHORT_MAXIMUM
		};

		typedef		       signed short int base_type;
		typedef const	       signed short int const_type;
		typedef	      volatile signed short int volatile_type;
		typedef const volatile signed short int const_volatile_type;
	};

	template <> struct Type<signed int> : Abstract::Type::Integer, Abstract::Type::Int {
		enum {	bits = Z_INT_BITS,
			size = Z_INT_SIZE
		};
		enum {	minimum = Z_INT_MINIMUM,
			maximum = Z_INT_MAXIMUM
		};

		typedef		       signed int base_type;
		typedef const	       signed int const_type;
		typedef	      volatile signed int volatile_type;
		typedef const volatile signed int const_volatile_type;
	};

	template <> struct Type<signed long int> : Abstract::Type::Integer, Abstract::Type::Long {
		enum {	bits = Z_LONG_BITS,
			size = Z_LONG_SIZE
		};
		enum {	minimum = Z_LONG_MINIMUM,
			maximum = Z_LONG_MAXIMUM
		};

		typedef		       signed long int base_type;
		typedef const	       signed long int const_type;
		typedef	      volatile signed long int volatile_type;
		typedef const volatile signed long int const_volatile_type;
	};

	template <> struct Type<signed long long int> : Abstract::Type::Integer, Abstract::Type::LLong {
		enum {	bits = Z_LLONG_BITS,
			size = Z_LLONG_SIZE
		};
		enum {	minimum = Z_LLONG_MINIMUM,
			maximum = Z_LLONG_MAXIMUM
		};

		typedef		       signed long long int base_type;
		typedef const	       signed long long int const_type;
		typedef	      volatile signed long long int volatile_type;
		typedef const volatile signed long long int const_volatile_type;
	};

	template <> struct Type<float> : Abstract::Type::Real {
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

		typedef		       float base_type;
		typedef const	       float const_type;
		typedef	      volatile float volatile_type;
		typedef const volatile float const_volatile_type;

		static constexpr float epsilon = Z_FLOAT_EPSILON;
		static constexpr float minimum = Z_FLOAT_MINIMUM;
		static constexpr float maximum = Z_FLOAT_MAXIMUM;
	};

	template <> struct Type<double> : Abstract::Type::Real {
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

		typedef		       double base_type;
		typedef const	       double const_type;
		typedef	      volatile double volatile_type;
		typedef const volatile double const_volatile_type;

		static constexpr double epsilon = Z_DOUBLE_EPSILON;
		static constexpr double minimum = Z_DOUBLE_MINIMUM;
		static constexpr double maximum = Z_DOUBLE_MAXIMUM;
	};

	template <> struct Type<long double> : Abstract::Type::Real {
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

		typedef		       long double base_type;
		typedef const	       long double const_type;
		typedef	      volatile long double volatile_type;
		typedef const volatile long double const_volatile_type;

		static constexpr long double epsilon = Z_LDOUBLE_EPSILON;
		static constexpr long double minimum = Z_LDOUBLE_MINIMUM;
		static constexpr long double maximum = Z_LDOUBLE_MAXIMUM;
	};

	template <typename T> struct Type<const		 T> : Mixins::Type::Const	 <Type<T> > {};
	template <typename T> struct Type<	volatile T> : Mixins::Type::Volatile	 <Type<T> > {};
	template <typename T> struct Type<const volatile T> : Mixins::Type::ConstVolatile<Type<T> > {};

	//template <> struct Type<enum> : public Abstract::Type::Base {enum {is_enum = true};};

	// MARK: - Pointers

	template <typename T> struct Type<T*> : Abstract::Type::Base {
		enum {is_pointer = true};

		typedef T pointed_type;
	};

	// MARK: - References

	template <typename T> struct Type<T&> : Abstract::Type::Base {
		enum {is_reference = true};

		typedef T referenced_type;
	};

	// MARK: - Arrays

	template <typename T> struct Type<T[]> : Abstract::Type::Base {
		enum {is_array = true};

		typedef		       T base_contained_type;
		typedef const	       T const_contained_type;
		typedef	      volatile T volatile_contained_type;
		typedef const volatile T const_volatile_contained_type;
	};

	template <typename T> struct Type<const		 T[]> : Mixins::Type::Const	   <Type<T[]> > {};
	template <typename T> struct Type<      volatile T[]> : Mixins::Type::Volatile	   <Type<T[]> > {};
	template <typename T> struct Type<const volatile T[]> : Mixins::Type::ConstVolatile<Type<T[]> > {};

 	template <typename T, zsize N> struct Type<		  T[N]> : Type<		      T[]> {};
	template <typename T, zsize N> struct Type<const	  T[N]> : Type<const	      T[]> {};
	template <typename T, zsize N> struct Type<	 volatile T[N]> : Type<	     volatile T[]> {};
	template <typename T, zsize N> struct Type<const volatile T[N]> : Type<const volatile T[]> {};


	// MARK: - Structures

	/*template <typename T, class U> struct Type<T U::*> : public Abstract::Type::Base {
		enum {is_member_pointer = true};
	};*/

	// MARK: - Functions
 
	template <class R, class... A> struct Type<R(A...)> : Abstract::Type::Base {
		enum {	is_callable = true,
			is_function = true
		};

		typedef R return_type;
	};

	template <class R, class... A> struct Type<R(A...) const	 > : Mixins::Type::Const	<Type<R(A...)> > {};
	template <class R, class... A> struct Type<R(A...)	 volatile> : Mixins::Type::Volatile     <Type<R(A...)> > {};
	template <class R, class... A> struct Type<R(A...) const volatile> : Mixins::Type::ConstVolatile<Type<R(A...)> > {};

	template <class R, class... A> struct Type<R(A...) &> : Type<R(A...)> {};

	template <class R, class... A> struct Type<R(A...) const	  &> : Mixins::Type::Const	  <Type<R(A...) &> > {};
	template <class R, class... A> struct Type<R(A...)	 volatile &> : Mixins::Type::Volatile	  <Type<R(A...) &> > {};
	template <class R, class... A> struct Type<R(A...) const volatile &> : Mixins::Type::ConstVolatile<Type<R(A...) &> > {};

	template <class R, class... A> struct Type<R(A...) &&> : Type<R(A...)> {};

	template <class R, class... A> struct Type<R(A...) const	  &&> : Mixins::Type::Const	   <Type<R(A...) &&> > {};
	template <class R, class... A> struct Type<R(A...)	 volatile &&> : Mixins::Type::Volatile	   <Type<R(A...) &&> > {};
	template <class R, class... A> struct Type<R(A...) const volatile &&> : Mixins::Type::ConstVolatile<Type<R(A...) &&> > {};

	template <class R, class... A> struct Type<R(A..., ...)> : public Type<R(A...)> {enum {is_variadic = true};};

	template <class R, class... A> struct Type<R(A..., ...) const	      > : Mixins::Type::Const	     <Type<R(A..., ...)> > {};
	template <class R, class... A> struct Type<R(A..., ...)	      volatile> : Mixins::Type::Volatile     <Type<R(A..., ...)> > {};
	template <class R, class... A> struct Type<R(A..., ...) const volatile> : Mixins::Type::ConstVolatile<Type<R(A..., ...)> > {};
 
	template <class R, class... A> struct Type<R(A..., ...) &> : Type<R(A..., ...)> {};

	template <class R, class... A> struct Type<R(A..., ...) const	       & > : Mixins::Type::Const	<Type<R(A..., ...) &> > {};
	template <class R, class... A> struct Type<R(A..., ...)	      volatile & > : Mixins::Type::Volatile	<Type<R(A..., ...) &> > {};
	template <class R, class... A> struct Type<R(A..., ...) const volatile & > : Mixins::Type::ConstVolatile<Type<R(A..., ...) &> > {};

	template <class R, class... A> struct Type<R(A..., ...) &&> : Type<R(A..., ...)> {};

	template <class R, class... A> struct Type<R(A..., ...) const	       &&> : Mixins::Type::Const	<Type<R(A..., ...) &&> > {};
	template <class R, class... A> struct Type<R(A..., ...)	      volatile &&> : Mixins::Type::Volatile	<Type<R(A..., ...) &&> > {};
	template <class R, class... A> struct Type<R(A..., ...) const volatile &&> : Mixins::Type::ConstVolatile<Type<R(A..., ...) &&> > {};
}

#endif // __Z_traits_Type_HPP__
