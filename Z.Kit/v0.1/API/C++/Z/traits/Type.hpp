/* Z Kit C++ API - traits/Type.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_traits_Type_HPP__
#define __Z_traits_Type_HPP__

#include <Z/types/base.h>
#include <Z/macros/language.hpp>
#include <Z/traits/SelectType.hpp>

namespace Zeta {

	// MARK: - Abstract

	namespace Abstract {namespace Type {

		struct Invalid {
			enum {	is_arithmetic		     = false,
				is_array		     = false,
				is_callable		     = false,
				is_class		     = false,
				is_const		     = false,
				is_const_volatile	     = false,
				is_enum			     = false,
				is_exact		     = false,
				is_integer		     = false,
				is_flexible_array	     = false,
				is_function		     = false,
				is_function_pointer	     = false,
				is_function_reference	     = false,
				is_function_lvalue_reference = false,
				is_function_rvalue_reference = false,
				is_fundamental		     = false,
				is_member_pointer	     = false,
				is_natural		     = false,
				is_number		     = false,
				is_nullptr		     = false,
				is_pod			     = false,
				is_pointer		     = false,
				is_qualified		     = false,
				is_real			     = false,
				is_reference		     = false,
				is_lvalue_reference	     = false,
				is_rvalue_reference	     = false,
				is_scalar		     = false,
				is_signed		     = false,
				is_struct		     = false,
				is_template		     = false,
				is_union		     = false,
				is_valid		     = false,
				is_value		     = false,
				is_variadic		     = false,
				is_variadic_function	     = false,
				is_void			     = false,
				is_void_pointer		     = false,
				is_volatile		     = false
			};

			enum {	is_constructible		   = false,
				is_copy_constructible		   = false,
				is_default_constructible	   = false,
				is_move_constructible		   = false,
				is_trivially_constructible	   = false,
				is_trivially_copy_constructible	   = false,
				is_trivially_default_constructible = false,
				is_trivially_move_constructible	   = false,
				is_nothrow_constructible	   = false,
				is_nothrow_copy_constructible	   = false,
				is_nothrow_default_constructible   = false,
				is_nothrow_move_constructible	   = false
			};

			enum {	arity	      = 0,
				element_count = 0
			};

			typedef Invalid type;
			typedef Invalid element_type;
			typedef Invalid pointee_type;
			typedef Invalid referenced_type;
			typedef Invalid return_type;
			typedef Invalid underlying_type;

			typedef Invalid to_argument;
			typedef Invalid to_signed;
			typedef Invalid to_unsigned;
			typedef Invalid to_const;
			typedef Invalid to_volatile;
			typedef Invalid to_const_volatile;
			typedef Invalid to_pointer;
			typedef Invalid to_lvalue_reference;
			typedef Invalid to_rvalue_reference;

			typedef Invalid add_const;
			typedef Invalid add_volatile;
			typedef Invalid add_const_volatile;
			typedef Invalid add_pointer;
			typedef Invalid add_lvalue_reference;
			typedef Invalid add_rvalue_reference;

			typedef Invalid remove_const;
			typedef Invalid remove_volatile;
			typedef Invalid remove_const_volatile;
			typedef Invalid remove_pointer;
			typedef Invalid remove_reference;
		};

		struct Valid : Invalid {
			enum {is_valid = true};
		};

		struct Fundamental : Valid {
			enum {is_fundamental = true};
		};

		struct Void : Fundamental {
			enum {is_void = true};	

			typedef void type;
		};

		struct Number : Fundamental {
			enum {	is_arithmetic  = true,
				is_pod	       = true,
				is_number      = true,
				is_scalar      = true,
				is_value       = true
			};
		};

		struct Exact : Number {
			enum {is_exact = true};
		};

		struct Natural : Exact {
			enum {is_natural = true};
			enum {minimum = 0};
		};

		struct Integer : Exact {
			enum {	is_integer = true,
				is_signed  = true
			};
		};

		struct Real : Number {
			enum {	is_real   = true,
				is_signed = true
			};
		};

#		if Z_UINT8_BASE_VALUE_TYPE == Z_VALUE_TYPE_UINT8

			struct UInt8 : Natural {
				enum {	bits = Z_UINT8_BITS,
					size = Z_UINT8_SIZE
				};
				enum {maximum = Z_UINT8_MAXIMUM};

				typedef zuint8 type;
				typedef zuint8 to_unsigned;

#				ifdef Z_INT8
					typedef zint8 to_signed;
#				endif
			};

#		endif

#		if Z_UINT16_BASE_VALUE_TYPE == Z_VALUE_TYPE_UINT16

			struct UInt16 : Natural {
				enum {	bits = Z_UINT16_BITS,
					size = Z_UINT16_SIZE
				};
				enum {maximum = Z_UINT16_MAXIMUM};

				typedef zuint16 type;
				typedef zuint16 to_unsigned;

#				ifdef Z_INT16
					typedef zint16 to_signed;
#				endif
			};

#		endif

#		if defined(Z_UINT32) && Z_UINT32_BASE_VALUE_TYPE == Z_VALUE_TYPE_UINT32

			struct UInt32 : Natural {
				enum {	bits = Z_UINT32_BITS,
					size = Z_UINT32_SIZE
				};
				enum {maximum = Z_UINT32_MAXIMUM};

				typedef zuint32 type;
				typedef zuint32 to_unsigned;

#				ifdef Z_INT32
					typedef zint32 to_signed;
#				endif
			};

#		endif

#		if defined(Z_UINT64) && Z_UINT64_BASE_VALUE_TYPE == Z_VALUE_TYPE_UINT64

			struct UInt64 : Natural {
				enum {	bits = Z_UINT64_BITS,
					size = Z_UINT64_SIZE
				};
				enum {maximum = Z_UINT64_MAXIMUM};

				typedef zuint64 type;
				typedef zuint64 to_unsigned;

#				ifdef Z_INT64
					typedef zint64 to_signed;
#				endif
			};

#		endif

#		if defined(Z_UINT128) && Z_UINT128_BASE_VALUE_TYPE == Z_VALUE_TYPE_UINT128

			struct UInt128 : Natural {
				enum {	bits = Z_UINT128_BITS,
					size = Z_UINT128_SIZE
				};
				enum {maximum = Z_UINT128_MAXIMUM};

				typedef zuint128 type;
				typedef zuint128 to_unsigned;

#				ifdef Z_INT128
					typedef zint128 to_signed;
#				endif
			};

#		endif

#		if Z_INT8_BASE_VALUE_TYPE == Z_VALUE_TYPE_INT8

			struct Int8 : Integer {
				enum {	bits = Z_INT8_BITS,
					size = Z_INT8_SIZE
				};
				enum {	minimum = Z_INT8_MINIMUM,
					maximum = Z_INT8_MAXIMUM
				};

				typedef zint8 type;
				typedef zint8 to_signed;

#				ifdef Z_UINT8
					typedef zuint8 to_unsigned;
#				endif
			};

#		endif

#		if Z_INT16_BASE_VALUE_TYPE == Z_VALUE_TYPE_INT16

			struct Int16 : Integer {
				enum {	bits = Z_INT16_BITS,
					size = Z_INT16_SIZE
				};
				enum {	minimum = Z_INT16_MINIMUM,
					maximum = Z_INT16_MAXIMUM
				};

				typedef zint16 type;
				typedef zint16 to_signed;

#				ifdef Z_UINT16
					typedef zuint16 to_unsigned;
#				endif
			};

#		endif

#		if defined(Z_INT32) && Z_INT32_BASE_VALUE_TYPE == Z_VALUE_TYPE_INT32

			struct Int32 : Integer {
				enum {	bits = Z_INT32_BITS,
					size = Z_INT32_SIZE
				};
				enum {	minimum = Z_INT32_MINIMUM,
					maximum = Z_INT32_MAXIMUM
				};

				typedef zint32 type;
				typedef zint32 to_signed;

#				ifdef Z_UINT32
					typedef zuint32 to_unsigned;
#				endif
			};

#		endif

#		if defined(Z_INT64) && Z_INT64_BASE_VALUE_TYPE == Z_VALUE_TYPE_INT64

			struct Int64 : Integer {
				enum {	bits = Z_INT64_BITS,
					size = Z_INT64_SIZE
				};
				enum {	minimum = Z_INT64_MINIMUM,
					maximum = Z_INT64_MAXIMUM
				};

				typedef zint64 type;
				typedef zint64 to_signed;

#				ifdef Z_UINT64
					typedef zuint64 to_unsigned;
#				endif
			};

#		endif

#		if defined(Z_INT128) && Z_INT128_BASE_VALUE_TYPE == Z_VALUE_TYPE_INT128

			struct Int128 : Integer {
				enum {	bits = Z_INT128_BITS,
					size = Z_INT128_SIZE
				};
				enum {	minimum = Z_INT128_MINIMUM,
					maximum = Z_INT128_MAXIMUM
				};

				typedef zint128 type;
				typedef zint128 to_signed;

#				ifdef Z_UINT128
					typedef zuint128 to_unsigned;
#				endif
			};

#		endif

		struct Character : SelectType<Z_CHARACTER_IS_SIGNED, Natural, Integer>::type {
			enum {	bits = Z_CHARACTER_BITS,
				size = Z_CHARACTER_SIZE
			};
			enum {	minimum = Z_CHARACTER_MINIMUM,
				maximum = Z_CHARACTER_MAXIMUM
			};

			typedef char	      type;
			typedef unsigned char to_unsigned;
			typedef signed   char to_signed;
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

#		ifdef Z_ULLONG

			struct ULLong : Natural {
				enum {	bits = Z_ULLONG_BITS,
					size = Z_ULLONG_SIZE
				};
				enum {maximum = Z_ULLONG_MAXIMUM};

				typedef unsigned long long int type;
				typedef unsigned long long int to_unsigned;

#				ifdef Z_LLONG
					typedef signed long long int to_signed;
#				endif
			};

#		endif

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

#		ifdef Z_LLONG

			struct LLong : Integer {
				enum {	bits = Z_LLONG_BITS,
					size = Z_LLONG_SIZE
				};
				enum {	minimum = Z_LLONG_MINIMUM,
					maximum = Z_LLONG_MAXIMUM
				};

				typedef signed long long int type;
				typedef signed long long int to_signed;

#				ifdef Z_ULLONG
					typedef unsigned long long int to_unsigned;
#				endif
			};

#		endif

#		ifdef Z_FLOAT

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
					sign_offset	    = Z_FLOAT_SIGN_OFFSET,
					sign_bits	    = Z_FLOAT_SIGN_BITS
				};
				enum {	exponent_minimum    = Z_FLOAT_EXPONENT_MINIMUM,
					exponent_maximum    = Z_FLOAT_EXPONENT_MAXIMUM,
					exponent_10_minimum = Z_FLOAT_EXPONENT_10_MINIMUM,
					exponent_10_maximum = Z_FLOAT_EXPONENT_10_MAXIMUM
				};

				static Z_INLINE_MEMBER Z_CONSTANT_EXPRESSION float epsilon () {return Z_FLOAT_EPSILON;}
				static Z_INLINE_MEMBER Z_CONSTANT_EXPRESSION float minimum () {return Z_FLOAT_MINIMUM;}
				static Z_INLINE_MEMBER Z_CONSTANT_EXPRESSION float maximum () {return Z_FLOAT_MAXIMUM;}
				//static Z_INLINE_MEMBER Z_CONSTANT_EXPRESSION float infinity() Z_NO_EXCEPTION {return Z_FLOAT_INFINITY;}
				//static Z_INLINE_MEMBER Z_CONSTANT_EXPRESSION float nan	   () Z_NO_EXCEPTION {return Z_FLOAT_NAN;}

				typedef float type;
				typedef float to_signed;
			};

#		endif

#		ifdef Z_DOUBLE

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
					sign_offset	    = Z_DOUBLE_SIGN_OFFSET,
					sign_bits	    = Z_DOUBLE_SIGN_BITS
				};
				enum {	exponent_minimum    = Z_DOUBLE_EXPONENT_MINIMUM,
					exponent_maximum    = Z_DOUBLE_EXPONENT_MAXIMUM,
					exponent_10_minimum = Z_DOUBLE_EXPONENT_10_MINIMUM,
					exponent_10_maximum = Z_DOUBLE_EXPONENT_10_MAXIMUM
				};

				static Z_INLINE_MEMBER Z_CONSTANT_EXPRESSION double epsilon () {return Z_DOUBLE_EPSILON;}
				static Z_INLINE_MEMBER Z_CONSTANT_EXPRESSION double minimum () {return Z_DOUBLE_MINIMUM;}
				static Z_INLINE_MEMBER Z_CONSTANT_EXPRESSION double maximum () {return Z_DOUBLE_MAXIMUM;}
				//static Z_INLINE_MEMBER Z_CONSTANT_EXPRESSION double infinity() Z_NO_EXCEPTION {return Z_DOUBLE_INFINITY;}
				//static Z_INLINE_MEMBER Z_CONSTANT_EXPRESSION double nan	    () Z_NO_EXCEPTION {return Z_DOUBLE_NAN;}

				typedef double type;
				typedef double to_signed;
			};

#		endif

#		ifdef Z_LDOUBLE

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
					sign_offset	    = Z_LDOUBLE_SIGN_OFFSET,
					sign_bits	    = Z_LDOUBLE_SIGN_BITS
				};
				enum {	exponent_minimum    = Z_LDOUBLE_EXPONENT_MINIMUM,
					exponent_maximum    = Z_LDOUBLE_EXPONENT_MAXIMUM,
					exponent_10_minimum = Z_LDOUBLE_EXPONENT_10_MINIMUM,
					exponent_10_maximum = Z_LDOUBLE_EXPONENT_10_MAXIMUM
				};

				static Z_INLINE_MEMBER Z_CONSTANT_EXPRESSION long double epsilon () {return Z_LDOUBLE_EPSILON;}
				static Z_INLINE_MEMBER Z_CONSTANT_EXPRESSION long double minimum () {return Z_LDOUBLE_MINIMUM;}
				static Z_INLINE_MEMBER Z_CONSTANT_EXPRESSION long double maximum () {return Z_LDOUBLE_MAXIMUM;}
				//static Z_INLINE_MEMBER Z_CONSTANT_EXPRESSION long double infinity() Z_NO_EXCEPTION {return Z_LDOUBLE_INFINITY;}
				//static Z_INLINE_MEMBER Z_CONSTANT_EXPRESSION long double nan	 () Z_NO_EXCEPTION {return Z_LDOUBLE_NAN;     }

				typedef long double type;
				typedef long double to_signed;
			};

#		endif

#		if Z_LANGUAGE_HAS_SPECIFIER(CPP, DECLARED_TYPE) && Z_LANGUAGE_HAS_LITERAL(CPP, NULL_POINTER)

			struct NullPointer : Valid {
				enum {	is_fundamental = true,
					is_scalar      = true,
					is_nullptr     = true
				};	

				typedef decltype(nullptr) type;
			};

#		endif

		template <class T> struct Pointer : Valid {
			enum {	is_pointer = true,
				is_scalar  = true,
				is_value   = true
			};

			typedef T* type;
			typedef T  pointee_type;
		};

		template <class T> struct Reference : Valid {
			enum {is_reference = true};

			typedef T referenced_type;
		};

		template <class T> struct LValueReference : Reference<T> {
			enum {is_lvalue_reference = true};

			typedef T& type;
		};

		template <class T> struct RValueReference : Reference<T> {
			enum {is_rvalue_reference = true};

			typedef T&& type;
		};

		template <class T, zsize N> struct Array : Valid {
			enum {is_array = true};
			enum {element_count = N};

			typedef T type[N];
			typedef T element_type;
		};

		template <class T> struct FlexibleArray : Valid {
			enum {	is_array	  = true,
				is_flexible_array = true,
			};

			typedef T type[];
			typedef T element_type;
		};

#		if Z_LANGUAGE_HAS(CPP, VARIADIC_TEMPLATE)

			template <class R, class... A> struct Function : Valid {
				enum {	is_callable = true,
					is_function = true
				};
				enum {arity = sizeof...(A)};

				typedef R type		   (A...);
				typedef R to_const	   (A...) const;
				typedef R to_volatile	   (A...)	volatile;
				typedef R to_const_volatile(A...) const volatile;

				typedef R return_type;
			};

			template <class R, class... A> struct VariadicFunction : Function<R, A...> {
				enum {is_variadic = true};

				typedef R type		   (A..., ...);
				typedef R to_const	   (A..., ...) const;
				typedef R to_volatile	   (A..., ...)	     volatile;
				typedef R to_const_volatile(A..., ...) const volatile;
			};

#		endif

		template <class T> struct Enum : Valid {
			enum {is_enum = true};

			typedef T type;
		};

		template <class T> struct Struct : Valid {
			enum {is_struct = true};

			typedef T type;
		};

		template <class T> struct Union : Valid {
			enum {is_union = true};

			typedef T type;
		};

#		if Z_LANGUAGE_HAS(CPP, VARIADIC_TEMPLATE_EXTENDED_PARAMETERS)

			template <template<class...> class T, class... A> struct Template : Struct<T<A...> > {
				enum {is_template = true};
				enum {arity = sizeof...(A)};
			};

#		endif
	}}

	// MARK: - Mixins

	namespace Mixins {namespace Type {

		// MARK: - Unqualified

		template <class C> struct Unqualified : C {
			typedef const	       typename C::type to_const;
			typedef	      volatile typename C::type to_volatile;
			typedef const volatile typename C::type to_const_volatile;
			typedef const	       typename C::type add_const;
			typedef	      volatile typename C::type add_volatile;
			typedef const volatile typename C::type add_const_volatile;
			typedef		       typename C::type remove_const;
			typedef		       typename C::type remove_volatile;
			typedef		       typename C::type remove_const_volatile;
		};

		template <class C> struct UnqualifiedFunction : C {
			typedef typename C::to_const	      add_const;
			typedef typename C::to_volatile	      add_volatile;
			typedef typename C::to_const_volatile add_const_volatile;
			typedef typename C::type	      remove_const;
			typedef typename C::type	      remove_volatile;
			typedef typename C::type	      remove_const_volatile;
		};

		// MARK: - Qualified

		template <class C> struct Qualified : Unqualified<C> {
			enum {is_qualified = true};
		};

		template <class C> struct QualifiedFunction : UnqualifiedFunction<C> {
			enum {is_qualified = true};
		};

		// MARK: - const qualified

		template <class C> struct Const : Qualified<C> {
			enum {is_const = true};

			typedef const	       typename C::type type;
			typedef const volatile typename C::type add_volatile;
			typedef const	       typename C::type remove_volatile;
		};

		template <class C> struct ConstExact : Const<C> {
			typedef const typename C::to_unsigned to_unsigned;
			typedef const typename C::to_signed   to_signed;
		};

		template <class C> struct ConstArray : Const<C> {
			typedef const typename C::element_type element_type;
		};

		template <class C> struct ConstFunction : QualifiedFunction<C> {
			enum {is_const = true};

			typedef typename C::to_const	      type;
			typedef typename C::to_const_volatile add_volatile;
			typedef typename C::to_const	      remove_volatile;
		};

		// MARK: - volatile qualified

		template <class C> struct Volatile : Qualified<C> {
			enum {is_volatile = true};

			typedef	      volatile typename C::type type;
			typedef const volatile typename C::type add_const;
			typedef	      volatile typename C::type remove_const;
		};

		template <class C> struct VolatileExact : Volatile<C> {
			typedef volatile typename C::to_unsigned to_unsigned;
			typedef volatile typename C::to_signed	 to_signed;
		};

		template <class C> struct VolatileArray : Volatile<C> {
			typedef volatile typename C::element_type element_type;
		};

		template <class C> struct VolatileFunction : QualifiedFunction<C> {
			enum {is_volatile = true};

			typedef typename C::to_volatile	      type;
			typedef typename C::to_const_volatile add_const;
			typedef typename C::to_volatile	      remove_const;
		};

		// MARK: - const volatile qualified

		template <class C> struct ConstVolatile : Qualified<C> {
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

		template <class C> struct ConstVolatileExact : ConstVolatile<C> {
			typedef const volatile typename C::to_unsigned to_unsigned;
			typedef const volatile typename C::to_signed   to_signed;
		};

		template <class C> struct ConstVolatileArray : ConstVolatile<C> {
			typedef const volatile typename C::element_type element_type;
		};

		template <class C> struct ConstVolatileFunction : QualifiedFunction<C> {
			enum {	is_const	  = true,
				is_volatile	  = true,
				is_const_volatile = true
			};

			typedef typename C::to_const_volatile type;
			typedef typename C::to_const_volatile add_const;
			typedef typename C::to_const_volatile add_volatile;
			typedef typename C::to_volatile	      remove_const;
			typedef typename C::to_const	      remove_volatile;
		};

		// MARK: - Void

		template <class C> struct Void : C {
			typedef typename C::type* to_pointer;
			typedef typename C::type* add_pointer;
			typedef typename C::type  remove_pointer;
			typedef typename C::type  remove_reference;
		};

		// MARK: - Value

		template <class C> struct Value : C {
			typedef typename C::type* to_pointer;
			typedef typename C::type& to_lvalue_reference;
			typedef typename C::type* add_pointer;
			typedef typename C::type& add_lvalue_reference;
			typedef typename C::type  remove_pointer;
			typedef typename C::type  remove_reference;

#			if Z_LANGUAGE_HAS(CPP, RVALUE_REFERENCE)
				typedef typename C::type&& to_rvalue_reference;
				typedef typename C::type&& add_rvalue_reference;
#			endif
		};

		// MARK: - Void pointer

		template <class C> struct VoidPointer : C {
			typedef typename C::type	  to_pointer;
			typedef typename C::type*	  add_pointer;
			typedef typename C::type&	  add_lvalue_reference;
			typedef typename C::pointee_type  remove_pointer;
			typedef typename C::type	  remove_reference;

#			if Z_LANGUAGE_HAS(CPP, RVALUE_REFERENCE)
				typedef typename C::type&& add_rvalue_reference;
#			endif
		};

		// MARK: - Pointer

		template <class C> struct Pointer : C {
			typedef typename C::type	  to_pointer;
			typedef typename C::pointee_type& to_lvalue_reference;
			typedef typename C::type*	  add_pointer;
			typedef typename C::type&	  add_lvalue_reference;
			typedef typename C::pointee_type  remove_pointer;
			typedef typename C::type	  remove_reference;

#			if Z_LANGUAGE_HAS(CPP, RVALUE_REFERENCE)
				typedef typename C::pointee_type&& to_rvalue_reference;
				typedef typename C::type&&	   add_rvalue_reference;
#			endif
		};

		// MARK: - Reference

		template <class C> struct Reference : C {
			typedef Abstract::Type::Invalid to_const;
			typedef Abstract::Type::Invalid to_volatile;
			typedef Abstract::Type::Invalid to_const_volatile;
			typedef Abstract::Type::Invalid add_const;
			typedef Abstract::Type::Invalid add_volatile;
			typedef Abstract::Type::Invalid add_const_volatile;

			typedef typename C::referenced_type remove_reference;
		};

		// MARK: - L-value Reference

		template <class C> struct LValueReference : Reference<C> {
			typedef typename C::referenced_type* to_pointer;
			typedef typename C::type	     to_lvalue_reference;
			typedef typename C::type	     remove_pointer;

#			if Z_LANGUAGE_HAS(CPP, RVALUE_REFERENCE)
				typedef typename C::referenced_type&& to_rvalue_reference;
#			endif
		};

		// MARK: - R-value Reference

		template <class C> struct RValueReference : Reference<C> {
			typedef typename C::referenced_type* to_pointer;
			typedef typename C::referenced_type& to_lvalue_reference;
			typedef typename C::type	     to_rvalue_reference;
			typedef typename C::type	     remove_pointer;
		};
	}}

	namespace Partials {namespace Type {

		// MARK: - Structures and unions (WIP)

		template <class T> struct Case : Mixins::Type::Unqualified<Abstract::Type::Struct<T> > {};

		// MARK: - void

		template <> struct Case<void> : Mixins::Type::Unqualified<Abstract::Type::Void> {};

		// MARK: - Numbers

#		if Z_UINT8_BASE_VALUE_TYPE == Z_VALUE_TYPE_UINT8
			template <> struct Case<zuint8> : Mixins::Type::Unqualified<Abstract::Type::UInt8> {};
#		endif

#		if Z_UINT16_BASE_VALUE_TYPE == Z_VALUE_TYPE_UINT16
			template <> struct Case<zuint16> : Mixins::Type::Unqualified<Abstract::Type::UInt16> {};
#		endif

#		if defined(Z_UINT32) && Z_UINT32_BASE_VALUE_TYPE == Z_VALUE_TYPE_UINT32
			template <> struct Case<zuint32> : Mixins::Type::Unqualified<Abstract::Type::UInt32> {};
#		endif

#		if defined(Z_UINT64) && Z_UINT64_BASE_VALUE_TYPE == Z_VALUE_TYPE_UINT64
			template <> struct Case<zuint64> : Mixins::Type::Unqualified<Abstract::Type::UInt64> {};
#		endif

#		if defined(Z_UINT128) && Z_UINT128_BASE_VALUE_TYPE == Z_VALUE_TYPE_UINT128
			template <> struct Case<zuint128> : Mixins::Type::Unqualified<Abstract::Type::UInt128> {};
#		endif

#		if Z_INT8_BASE_VALUE_TYPE == Z_VALUE_TYPE_INT8
			template <> struct Case<zint8> : Mixins::Type::Unqualified<Abstract::Type::Int8> {};
#		endif

#		if Z_INT16_BASE_VALUE_TYPE == Z_VALUE_TYPE_INT16
			template <> struct Case<zint16> : Mixins::Type::Unqualified<Abstract::Type::Int16> {};
#		endif

#		if defined(Z_INT32) && Z_INT32_BASE_VALUE_TYPE == Z_VALUE_TYPE_INT32
			template <> struct Case<zint32> : Mixins::Type::Unqualified<Abstract::Type::Int32> {};
#		endif

#		if defined(Z_INT64) && Z_INT64_BASE_VALUE_TYPE == Z_VALUE_TYPE_INT64
			template <> struct Case<zint64> : Mixins::Type::Unqualified<Abstract::Type::Int64> {};
#		endif

#		if defined(Z_INT128) && Z_INT128_BASE_VALUE_TYPE == Z_VALUE_TYPE_INT128
			template <> struct Case<zint128> : Mixins::Type::Unqualified<Abstract::Type::Int128> {};
#		endif

		template <> struct Case<char> : Mixins::Type::Unqualified<Abstract::Type::Character> {};

		template <> struct Case<unsigned char	  > : Mixins::Type::Unqualified<Abstract::Type::UChar > {};
		template <> struct Case<unsigned short int> : Mixins::Type::Unqualified<Abstract::Type::UShort> {};
		template <> struct Case<unsigned int	  > : Mixins::Type::Unqualified<Abstract::Type::UInt  > {};
		template <> struct Case<unsigned long int > : Mixins::Type::Unqualified<Abstract::Type::ULong > {};

#		ifdef Z_ULLONG
			template <> struct Case<unsigned long long int> : Mixins::Type::Unqualified<Abstract::Type::ULLong> {};
#		endif

		template <> struct Case<signed char	> : Mixins::Type::Unqualified<Abstract::Type::Char > {};
		template <> struct Case<signed short int> : Mixins::Type::Unqualified<Abstract::Type::Short> {};
		template <> struct Case<signed int	> : Mixins::Type::Unqualified<Abstract::Type::Int  > {};
		template <> struct Case<signed long int	> : Mixins::Type::Unqualified<Abstract::Type::Long > {};

#		ifdef Z_LLONG
			template <> struct Case<signed long long int> : Mixins::Type::Unqualified<Abstract::Type::LLong > {};
#		endif

#		ifdef Z_FLOAT
			template <> struct Case<float> : Mixins::Type::Unqualified<Abstract::Type::Float> {};
#		endif

#		ifdef Z_DOUBLE
			template <> struct Case<double> : Mixins::Type::Unqualified<Abstract::Type::Double> {};
#		endif

#		ifdef Z_LDOUBLE
			template <> struct Case<long double> : Mixins::Type::Unqualified<Abstract::Type::LDouble> {};
#		endif

		// MARK: - Pointers

		template <class T> struct Case<T*> : Mixins::Type::Unqualified<Abstract::Type::Pointer<T> > {
			enum {	is_function_pointer = Case<T>::is_function,
				is_callable	    = is_function_pointer,
				is_void_pointer	    = Case<T>::is_void
			};
		};

		// MARK: - Null pointer type

#		if Z_LANGUAGE_HAS_SPECIFIER(CPP, DECLARED_TYPE) && Z_LANGUAGE_HAS_LITERAL(CPP, NULL_POINTER)
			template <> struct Case<decltype(nullptr)> : Mixins::Type::Unqualified<Abstract::Type::NullPointer> {};
#		endif

		// MARK: - L-value References

		template <class T> struct Case<T&> : Mixins::Type::Unqualified<Abstract::Type::LValueReference<T> > {
			enum {	is_function_reference	     = Case<T>::is_function,
				is_function_lvalue_reference = is_function_reference,
				is_callable		     = is_function_reference
			};
		};

		// MARK: - R-value references

		template <class T> struct Case<T&&> : Mixins::Type::Unqualified<Abstract::Type::RValueReference<T> > {
			enum {	is_function_reference	     = Case<T>::is_function,
				is_function_rvalue_reference = is_function_reference,
				is_callable		     = is_function_reference
			};
		};

		// MARK: - Arrays

		template <class T, zsize N> struct Case<T[N]> : Mixins::Type::Unqualified<Abstract::Type::Array<T, N> > {};

		template <class T, zsize N> struct Case<const	       T[N]> : Mixins::Type::ConstArray	       <Case<T[N]> > {};
		template <class T, zsize N> struct Case<      volatile T[N]> : Mixins::Type::VolatileArray     <Case<T[N]> > {};
		template <class T, zsize N> struct Case<const volatile T[N]> : Mixins::Type::ConstVolatileArray<Case<T[N]> > {};

		// MARK: - Flexible arrays

		template <class T> struct Case<T[]> : Mixins::Type::Unqualified<Abstract::Type::FlexibleArray<T> > {};

		template <class T> struct Case<const	      T[]> : Mixins::Type::ConstArray	     <Case<T[]> > {};
		template <class T> struct Case<	     volatile T[]> : Mixins::Type::VolatileArray     <Case<T[]> > {};
		template <class T> struct Case<const volatile T[]> : Mixins::Type::ConstVolatileArray<Case<T[]> > {};

		// MARK: - Functions

#		if Z_LANGUAGE_HAS(CPP, VARIADIC_TEMPLATE)

			template <class R, class... A> struct Case<R(A...)> : Mixins::Type::UnqualifiedFunction<Abstract::Type::Function<R, A...> > {};

			template <class R, class... A> struct Case<R(A...) const	 > : Mixins::Type::ConstFunction	<Case<R(A...)> > {};
			template <class R, class... A> struct Case<R(A...)	 volatile> : Mixins::Type::VolatileFunction	<Case<R(A...)> > {};
			template <class R, class... A> struct Case<R(A...) const volatile> : Mixins::Type::ConstVolatileFunction<Case<R(A...)> > {};

			template <class R, class... A> struct Case<R(A..., ...)> : Mixins::Type::UnqualifiedFunction<Abstract::Type::VariadicFunction<R, A...> > {};

			template <class R, class... A> struct Case<R(A..., ...) const	      > : Mixins::Type::ConstFunction	     <Case<R(A..., ...)> > {};
			template <class R, class... A> struct Case<R(A..., ...)	      volatile> : Mixins::Type::VolatileFunction     <Case<R(A..., ...)> > {};
			template <class R, class... A> struct Case<R(A..., ...) const volatile> : Mixins::Type::ConstVolatileFunction<Case<R(A..., ...)> > {};

#			if Z_LANGUAGE_HAS(CPP, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)

				template <class R, class... A> struct Case<R(A...) &> : Case<R(A...)> {};

				template <class R, class... A> struct Case<R(A...) const	  &> : Mixins::Type::ConstFunction	  <Case<R(A...) &> > {};
				template <class R, class... A> struct Case<R(A...)	 volatile &> : Mixins::Type::VolatileFunction	  <Case<R(A...) &> > {};
				template <class R, class... A> struct Case<R(A...) const volatile &> : Mixins::Type::ConstVolatileFunction<Case<R(A...) &> > {};

				template <class R, class... A> struct Case<R(A...) &&> : Case<R(A...)> {};

				template <class R, class... A> struct Case<R(A...) const	  &&> : Mixins::Type::ConstFunction	   <Case<R(A...) &&> > {};
				template <class R, class... A> struct Case<R(A...)	 volatile &&> : Mixins::Type::VolatileFunction	   <Case<R(A...) &&> > {};
				template <class R, class... A> struct Case<R(A...) const volatile &&> : Mixins::Type::ConstVolatileFunction<Case<R(A...) &&> > {};

				template <class R, class... A> struct Case<R(A..., ...) &> : Case<R(A..., ...)> {};

				template <class R, class... A> struct Case<R(A..., ...) const	       & > : Mixins::Type::ConstFunction	<Case<R(A..., ...) &> > {};
				template <class R, class... A> struct Case<R(A..., ...)	      volatile & > : Mixins::Type::VolatileFunction	<Case<R(A..., ...) &> > {};
				template <class R, class... A> struct Case<R(A..., ...) const volatile & > : Mixins::Type::ConstVolatileFunction<Case<R(A..., ...) &> > {};

				template <class R, class... A> struct Case<R(A..., ...) &&> : Case<R(A..., ...)> {};

				template <class R, class... A> struct Case<R(A..., ...) const	       &&> : Mixins::Type::ConstFunction	<Case<R(A..., ...) &&> > {};
				template <class R, class... A> struct Case<R(A..., ...)	      volatile &&> : Mixins::Type::VolatileFunction	<Case<R(A..., ...) &&> > {};
				template <class R, class... A> struct Case<R(A..., ...) const volatile &&> : Mixins::Type::ConstVolatileFunction<Case<R(A..., ...) &&> > {};

#			endif

#		endif

		// MARK: - Templates

#		if Z_LANGUAGE_HAS(CPP, VARIADIC_TEMPLATE_EXTENDED_PARAMETERS)
			template <template<class...> class T, class... A> struct Case<T<A...> > : Mixins::Type::Unqualified<Abstract::Type::Template<T, A...> > {};
#		endif

		// MARK: - Generic specializations for qualified types

		template <class T> struct Case<const	      T> : SelectType<Case<T>::is_exact, Mixins::Type::Const	    <Case<T> >, Mixins::Type::ConstExact	<Case<T> > >::type {};
		template <class T> struct Case<	     volatile T> : SelectType<Case<T>::is_exact, Mixins::Type::Volatile	    <Case<T> >, Mixins::Type::VolatileExact	<Case<T> > >::type {};
		template <class T> struct Case<const volatile T> : SelectType<Case<T>::is_exact, Mixins::Type::ConstVolatile<Case<T> >, Mixins::Type::ConstVolatileExact<Case<T> > >::type {};

		// MARK: - Final construction

		template <class T> struct Final : SelectType <
			Case<T>::is_pointer
				? (Case<T>::is_void_pointer ? 2 : 3)
				: (Case<T>::is_reference
					? (Case<T>::is_lvalue_reference ? 4 : 5)
					: (Case<T>::is_void ? 0 : 1)),
			Mixins::Type::Void	     <Case<T> >,
			Mixins::Type::Value	     <Case<T> >,
			Mixins::Type::VoidPointer    <Case<T> >,
			Mixins::Type::Pointer	     <Case<T> >,
			Mixins::Type::LValueReference<Case<T> >,
			Mixins::Type::RValueReference<Case<T> >
		>::type {};
	}}

	template <class T> class Type : public Partials::Type::Final<T> {
		private: typedef Partials::Type::Final<T> Super;

		public:

		typedef typename SelectType<
			Super::is_struct || Super::is_union,
			T,
			const typename Partials::Type::Final<typename Super::remove_const_volatile>::add_lvalue_reference
		>::type to_argument;

		typedef struct {
			zuint8 data[sizeof(T)];
		} to_opaque;

		// TODO: constexpr functions
	};

	template <> struct Type<	       Abstract::Type::Invalid> : Abstract::Type::Invalid {};
	template <> struct Type<const	       Abstract::Type::Invalid> : Abstract::Type::Invalid {};
	template <> struct Type<      volatile Abstract::Type::Invalid> : Abstract::Type::Invalid {};
	template <> struct Type<const volatile Abstract::Type::Invalid> : Abstract::Type::Invalid {};
}

#endif // __Z_traits_Type_HPP__
