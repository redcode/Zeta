/* Z Kit C++ API - traits/Type.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2017 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_traits_Type_HPP__
#define __Z_traits_Type_HPP__

#include <Z/macros/language.hpp>

#if Z_LANGUAGE_HAS(CPP, RELAXED_CONSTANT_EXPRESSION_FUNCTION)
#	include <Z/functions/base/type.hpp>
#	include <Z/classes/base/Symbol.hpp>
#endif

#if Z_LANGUAGE_HAS(CPP, VARIADIC_TEMPLATE_EXTENDED_PARAMETERS)
#	include <Z/traits/TypeList.hpp>
#else
#	include <Z/traits/SelectType.hpp>
#endif

// MARK: - Abstract

namespace Zeta {namespace Detail {namespace Type {namespace Abstract {

	struct Invalid {
		enum {	is_arithmetic		     = false,
			is_array		     = false,
			is_callable		     = false,
			is_class		     = false,
			is_compound		     = false,
			is_const		     = false,
			is_const_lvalue		     = false,
			is_const_rvalue		     = false,
			is_const_volatile	     = false,
			is_const_volatile_lvalue     = false,
			is_const_volatile_rvalue     = false,
			is_data_member_pointer	     = false,
			is_empty		     = false,
			is_exact		     = false,
			is_integer		     = false,
			is_invalid		     = true,
			is_flexible_array	     = false,
			is_function		     = false,
			is_function_pointer	     = false,
			is_function_reference	     = false,
			is_function_lvalue_reference = false,
			is_function_rvalue_reference = false,
			is_fundamental		     = false,
			is_lvalue		     = false,
			is_lvalue_reference	     = false,
			is_member_function_pointer   = false,
			is_member_pointer	     = false,
			is_natural		     = false,
			is_number		     = false,
			is_nullptr		     = false,
			is_pointer		     = false,
			is_qualified		     = false,
			is_real			     = false,
			is_reference		     = false,
			is_rvalue		     = false,
			is_rvalue_reference	     = false,
			is_scalar		     = false,
			is_signed		     = false,
			is_storable		     = false,
			is_struct		     = false,
			is_template		     = false,
			is_valid		     = false,
			is_value		     = false,
			is_variadic		     = false,
			is_variadic_function	     = false,
			is_void			     = false,
			is_void_pointer		     = false,
			is_volatile		     = false,
			is_volatile_lvalue	     = false,
			is_volatile_rvalue	     = false
		};

#		if Z_COMPILER_HAS_TRAIT(TYPE_IS_ABSTRACT)
			enum {is_abstract = false};
#		endif

#		if Z_COMPILER_HAS_TRAIT(TYPE_IS_AGGREGATE)
			enum {is_aggregate = false};
#		endif

#		if Z_COMPILER_HAS_TRAIT(TYPE_IS_ENUM)
			enum {is_enum = false};
#		endif

#		if Z_COMPILER_HAS_TRAIT(TYPE_IS_FINAL)
			enum {is_final = false};
#		endif

#		if Z_COMPILER_HAS_TRAIT(TYPE_IS_INTERFACE_CLASS)
			enum {is_interface_class = false};
#		endif

#		if Z_COMPILER_HAS_TRAIT(TYPE_IS_LITERAL)
			enum {is_literal = false};
#		endif

#		if Z_COMPILER_HAS_TRAIT(TYPE_IS_POD)
			enum {is_pod = false};
#		endif

#		if Z_COMPILER_HAS_TRAIT(TYPE_IS_POLYMORPHIC)
			enum {is_polymorphic = false};
#		endif

#		if Z_COMPILER_HAS_TRAIT(TYPE_IS_UNION)
			enum {is_union = false};
#		endif

		enum {	is_copy_assignable		   = false,
			is_copy_constructible		   = false,
			is_default_constructible	   = false,
			is_destructible			   = false,
			is_move_assignable		   = false,
			is_move_constructible		   = false,
			is_nothrow_copy_assignable	   = false,
			is_nothrow_copy_constructible	   = false,
			is_nothrow_default_constructible   = false,
			is_nothrow_destructible		   = false,
			is_nothrow_move_assignable	   = false,
			is_nothrow_move_constructible	   = false,
			is_trivially_copy_assignable	   = false,
			is_trivially_copy_constructible	   = false,
			is_trivially_default_constructible = false,
			is_trivially_destructible	   = false,
			is_trivially_move_assignable	   = false,
			is_trivially_move_constructible	   = false
		};
		enum {	arity	      = 0,
			element_count = 0,
			pointer_level = 0
		};
		enum {	bits = 0,
			size = 0
		};

		typedef NaT type;

		typedef NaT class_type;
		typedef NaT element_type;
		typedef NaT pointee_type;
		typedef NaT referenced_type;
		typedef NaT return_type;

#		if Z_COMPILER_HAS_TRAIT(TYPE_UNDERLYING_TYPE)
			typedef NaT underlying_type;
#		endif

		typedef NaT parameters;

		typedef NaT to_parameter;
		typedef NaT to_const;
		typedef NaT to_const_lvalue;
		typedef NaT to_const_rvalue;
		typedef NaT to_const_volatile;
		typedef NaT to_const_volatile_lvalue;
		typedef NaT to_const_volatile_rvalue;
		typedef NaT to_function;
		typedef NaT to_lvalue;
		typedef NaT to_lvalue_reference;
		typedef NaT to_opaque;
		typedef NaT to_pointer;
		typedef NaT to_rvalue;
		typedef NaT to_rvalue_reference;
		typedef NaT to_signed;
		typedef NaT to_unqualified;
		typedef NaT to_unsigned;
		typedef NaT to_volatile;
		typedef NaT to_volatile_lvalue;
		typedef NaT to_volatile_rvalue;
		typedef NaT to_wrap;

		typedef NaT add_const;
		typedef NaT add_const_lvalue;
		typedef NaT add_const_rvalue;
		typedef NaT add_const_volatile;
		typedef NaT add_const_volatile_lvalue;
		typedef NaT add_const_volatile_rvalue;
		typedef NaT add_lvalue;
		typedef NaT add_lvalue_reference;
		typedef NaT add_pointer;
		typedef NaT add_rvalue;
		typedef NaT add_rvalue_reference;
		typedef NaT add_volatile;
		typedef NaT add_volatile_lvalue;
		typedef NaT add_volatile_rvalue;

		typedef NaT remove_const;
		typedef NaT remove_const_this;
		typedef NaT remove_const_volatile;
		typedef NaT remove_const_volatile_this;
		typedef NaT remove_pointer;
		typedef NaT remove_reference;
		typedef NaT remove_this;
		typedef NaT remove_volatile;
		typedef NaT remove_volatile_this;
	};

	struct Valid : Invalid {
		enum {	is_invalid = false,
			is_valid   = true
		};
	};

	struct Storable : Valid {
		enum {is_storable = true};
	};

	struct Number : Storable {
		enum {	is_arithmetic  = true,
			is_fundamental = true,
			is_number      = true,
			is_scalar      = true,
			is_value       = true
		};

#		if Z_COMPILER_HAS_TRAIT(TYPE_IS_LITERAL)
			enum {is_literal = true};
#		endif

#		if Z_COMPILER_HAS_TRAIT(TYPE_IS_POD)
			enum {is_pod = true};
#		endif
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

	struct Void : Valid {
		enum {	is_fundamental = true,
			is_void	       = true
		};

#		if Z_COMPILER_HAS_TRAIT(TYPE_IS_LITERAL)
			enum {is_literal = true};
#		endif

		typedef void type;
	};

#	if Z_UINT8_BASE_VALUE_TYPE == Z_VALUE_TYPE_UINT8

		struct UInt8 : Natural {
			enum {maximum = Z_UINT8_MAXIMUM};

			typedef zuint8 type;
			typedef zuint8 to_unsigned;

#			ifdef Z_INT8
				typedef zint8 to_signed;
#			endif
		};

#	endif

#	if Z_UINT16_BASE_VALUE_TYPE == Z_VALUE_TYPE_UINT16

		struct UInt16 : Natural {
			enum {maximum = Z_UINT16_MAXIMUM};

			typedef zuint16 type;
			typedef zuint16 to_unsigned;

#			ifdef Z_INT16
				typedef zint16 to_signed;
#			endif
		};

#	endif

#	if defined(Z_UINT32) && Z_UINT32_BASE_VALUE_TYPE == Z_VALUE_TYPE_UINT32

		struct UInt32 : Natural {
			enum {maximum = Z_UINT32_MAXIMUM};

			typedef zuint32 type;
			typedef zuint32 to_unsigned;

#			ifdef Z_INT32
				typedef zint32 to_signed;
#			endif
		};

#	endif

#	if defined(Z_UINT64) && Z_UINT64_BASE_VALUE_TYPE == Z_VALUE_TYPE_UINT64

		struct UInt64 : Natural {
			enum {maximum = Z_UINT64_MAXIMUM};

			typedef zuint64 type;
			typedef zuint64 to_unsigned;

#			ifdef Z_INT64
				typedef zint64 to_signed;
#			endif
		};

#	endif

#	if defined(Z_UINT128) && Z_UINT128_BASE_VALUE_TYPE == Z_VALUE_TYPE_UINT128

		struct UInt128 : Natural {
			enum {maximum = Z_UINT128_MAXIMUM};

			typedef zuint128 type;
			typedef zuint128 to_unsigned;

#			ifdef Z_INT128
				typedef zint128 to_signed;
#			endif
		};

#	endif

#	if Z_INT8_BASE_VALUE_TYPE == Z_VALUE_TYPE_INT8

		struct Int8 : Integer {
			enum {	minimum = Z_INT8_MINIMUM,
				maximum = Z_INT8_MAXIMUM
			};

			typedef zint8 type;
			typedef zint8 to_signed;

#			ifdef Z_UINT8
				typedef zuint8 to_unsigned;
#			endif
		};

#	endif

#	if Z_INT16_BASE_VALUE_TYPE == Z_VALUE_TYPE_INT16

		struct Int16 : Integer {
			enum {	minimum = Z_INT16_MINIMUM,
				maximum = Z_INT16_MAXIMUM
			};

			typedef zint16 type;
			typedef zint16 to_signed;

#			ifdef Z_UINT16
				typedef zuint16 to_unsigned;
#			endif
		};

#	endif

#	if defined(Z_INT32) && Z_INT32_BASE_VALUE_TYPE == Z_VALUE_TYPE_INT32

		struct Int32 : Integer {
			enum {	minimum = Z_INT32_MINIMUM,
				maximum = Z_INT32_MAXIMUM
			};

			typedef zint32 type;
			typedef zint32 to_signed;

#			ifdef Z_UINT32
				typedef zuint32 to_unsigned;
#			endif
		};

#	endif

#	if defined(Z_INT64) && Z_INT64_BASE_VALUE_TYPE == Z_VALUE_TYPE_INT64

		struct Int64 : Integer {
			enum {	minimum = Z_INT64_MINIMUM,
				maximum = Z_INT64_MAXIMUM
			};

			typedef zint64 type;
			typedef zint64 to_signed;

#			ifdef Z_UINT64
				typedef zuint64 to_unsigned;
#			endif
		};

#	endif

#	if defined(Z_INT128) && Z_INT128_BASE_VALUE_TYPE == Z_VALUE_TYPE_INT128

		struct Int128 : Integer {
			enum {	minimum = Z_INT128_MINIMUM,
				maximum = Z_INT128_MAXIMUM
			};

			typedef zint128 type;
			typedef zint128 to_signed;

#			ifdef Z_UINT128
				typedef zuint128 to_unsigned;
#			endif
		};

#	endif

	struct Character : SelectType<Z_CHARACTER_IS_SIGNED, Natural, Integer>::type {
		enum {	minimum = Z_CHARACTER_MINIMUM,
			maximum = Z_CHARACTER_MAXIMUM
		};

		typedef char	      type;
		typedef unsigned char to_unsigned;
		typedef signed   char to_signed;
	};

	struct UChar : Natural {
		enum {maximum = Z_UCHAR_MAXIMUM};

		typedef unsigned char type;
		typedef unsigned char to_unsigned;
		typedef signed   char to_signed;
	};

	struct UShort : Natural {
		enum {maximum = Z_USHORT_MAXIMUM};

		typedef unsigned short int type;
		typedef unsigned short int to_unsigned;
		typedef signed	 short int to_signed;
	};

	struct UInt : Natural {
		enum {maximum = Z_UINT_MAXIMUM};

		typedef unsigned int type;
		typedef unsigned int to_unsigned;
		typedef signed	 int to_signed;
	};

	struct ULong : Natural {
		enum {maximum = Z_ULONG_MAXIMUM};

		typedef unsigned long int type;
		typedef unsigned long int to_unsigned;
		typedef signed	 long int to_signed;

	};

#	ifdef Z_ULLONG

		struct ULLong : Natural {
			enum {maximum = Z_ULLONG_MAXIMUM};

			typedef unsigned long long int type;
			typedef unsigned long long int to_unsigned;

#			ifdef Z_LLONG
				typedef signed long long int to_signed;
#			endif
		};

#	endif

	struct Char : Integer {
		enum {	minimum = Z_CHAR_MINIMUM,
			maximum = Z_CHAR_MAXIMUM
		};

		typedef signed	 char type;
		typedef unsigned char to_unsigned;
		typedef signed	 char to_signed;
	};

	struct Short : Integer {
		enum {	minimum = Z_SHORT_MINIMUM,
			maximum = Z_SHORT_MAXIMUM
		};

		typedef signed	 short int type;
		typedef unsigned short int to_unsigned;
		typedef signed	 short int to_signed;
	};

	struct Int : Integer {
		enum {	minimum = Z_INT_MINIMUM,
			maximum = Z_INT_MAXIMUM
		};

		typedef signed	 int type;
		typedef unsigned int to_unsigned;
		typedef signed	 int to_signed;
	};

	struct Long : Integer {
		enum {	minimum = Z_LONG_MINIMUM,
			maximum = Z_LONG_MAXIMUM
		};

		typedef signed	 long int type;
		typedef unsigned long int to_unsigned;
		typedef signed	 long int to_signed;
	};

#	ifdef Z_LLONG

		struct LLong : Integer {
			enum {	minimum = Z_LLONG_MINIMUM,
				maximum = Z_LLONG_MAXIMUM
			};

			typedef signed long long int type;
			typedef signed long long int to_signed;

#			ifdef Z_ULLONG
				typedef unsigned long long int to_unsigned;
#			endif
		};

#	endif

#	ifdef Z_FLOAT

		struct Float : Real {
			enum {	bias		    = Z_FLOAT_BIAS,
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

			static Z_CONSTANT_MEMBER(CPP11) float epsilon () {return Z_FLOAT_EPSILON;}
			static Z_CONSTANT_MEMBER(CPP11) float minimum () {return Z_FLOAT_MINIMUM;}
			static Z_CONSTANT_MEMBER(CPP11) float maximum () {return Z_FLOAT_MAXIMUM;}
			//static Z_CONSTANT_MEMBER(CPP11) float infinity() Z_NO_EXCEPTION {return Z_FLOAT_INFINITY;}
			//static Z_CONSTANT_MEMBER(CPP11) float nan     () Z_NO_EXCEPTION {return Z_FLOAT_NAN;}

			typedef float type;
			typedef float to_signed;
		};

#	endif

#	ifdef Z_DOUBLE

		struct Double : Real {
			enum {	bias		    = Z_DOUBLE_BIAS,
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

			static Z_CONSTANT_MEMBER(CPP11) double epsilon () {return Z_DOUBLE_EPSILON;}
			static Z_CONSTANT_MEMBER(CPP11) double minimum () {return Z_DOUBLE_MINIMUM;}
			static Z_CONSTANT_MEMBER(CPP11) double maximum () {return Z_DOUBLE_MAXIMUM;}
			//static Z_CONSTANT_MEMBER(CPP11) double infinity() Z_NO_EXCEPTION {return Z_DOUBLE_INFINITY;}
			//static Z_CONSTANT_MEMBER(CPP11) double nan     () Z_NO_EXCEPTION {return Z_DOUBLE_NAN;}

			typedef double type;
			typedef double to_signed;
		};

#	endif

#	ifdef Z_LDOUBLE

		struct LDouble : Real {
			enum {	bias		    = Z_LDOUBLE_BIAS,
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

			static Z_CONSTANT_MEMBER(CPP11) long double epsilon () {return Z_LDOUBLE_EPSILON;}
			static Z_CONSTANT_MEMBER(CPP11) long double minimum () {return Z_LDOUBLE_MINIMUM;}
			static Z_CONSTANT_MEMBER(CPP11) long double maximum () {return Z_LDOUBLE_MAXIMUM;}
			//static Z_CONSTANT_MEMBER(CPP11) long double infinity() Z_NO_EXCEPTION {return Z_LDOUBLE_INFINITY;}
			//static Z_CONSTANT_MEMBER(CPP11) long double nan     () Z_NO_EXCEPTION {return Z_LDOUBLE_NAN;}

			typedef long double type;
			typedef long double to_signed;
		};

#	endif

	template <class T> struct Array : Storable {
		enum {is_array = true};

		typedef T element_type;

#		if Z_COMPILER_HAS_TRAIT(TYPE_IS_AGGREGATE)
			enum {is_aggregate = true};
#		endif

#		if Z_COMPILER_HAS_TRAIT(TYPE_IS_LITERAL)
			enum {is_literal = Z_COMPILER_TRAIT(TYPE_IS_LITERAL)(T)};
#		endif

#		if Z_COMPILER_HAS_TRAIT(TYPE_IS_POD)
			enum {is_pod = Z_COMPILER_TRAIT(TYPE_IS_POD)(T)};
#		endif
	};

	template <class T, zsize N> struct SizedArray : Array<T> {
		enum {element_count = N};

		typedef T type[N];
	};

	template <class T> struct FlexibleArray : Array<T> {
		enum {is_flexible_array = true};

		typedef T type[];
	};

	template <class T> struct Enum : Storable {
		enum {	is_enum	   = true,
			is_scalar  = true
		};

#		if Z_COMPILER_HAS_TRAIT(TYPE_IS_LITERAL)
			enum {is_literal = true};
#		endif

#		if Z_COMPILER_HAS_TRAIT(TYPE_IS_POD)
			enum {is_pod = true};
#		endif

		typedef T type;

#		if Z_COMPILER_HAS_TRAIT(TYPE_UNDERLYING_TYPE)
			typedef Z_COMPILER_TRAIT(TYPE_UNDERLYING_TYPE)(T) underlying_type;
#		endif
	};

	template <class T> struct Compound : Storable {
		enum {is_compound = true};

#		if Z_COMPILER_HAS_TRAIT(TYPE_IS_AGGREGATE)
			enum {is_aggregate = Z_COMPILER_TRAIT(TYPE_IS_AGGREGATE)(T)};
#		endif

#		if Z_COMPILER_HAS_TRAIT(TYPE_IS_FINAL)
			enum {is_final = Z_COMPILER_TRAIT(TYPE_IS_FINAL)(T)};
#		endif

#		if Z_COMPILER_HAS_TRAIT(TYPE_IS_LITERAL)
			enum {is_literal = Z_COMPILER_TRAIT(TYPE_IS_LITERAL)(T)};
#		endif

#		if Z_COMPILER_HAS_TRAIT(TYPE_IS_POD)
			enum {is_pod = Z_COMPILER_TRAIT(TYPE_IS_POD)(T)};
#		endif

		typedef T type;
	};

	template <class T> class Struct : public Compound<T> {
		public:
		enum {	is_class  = true,
			is_struct = true
		};

#		if Z_COMPILER_HAS_TRAIT(TYPE_IS_ABSTRACT)
			enum {is_abstract = Z_COMPILER_TRAIT(TYPE_IS_ABSTRACT)(T)};
#		endif

#		if Z_COMPILER_HAS_TRAIT(TYPE_IS_EMPTY)
			enum {is_empty = Z_COMPILER_TRAIT(TYPE_IS_EMPTY)(T)};
#		else
			private:
			struct Dummy	     {zint dummy;};
			struct EmptyTest : T {zint dummy;};

			public:
			enum {is_empty = (sizeof(EmptyTest) == sizeof(Dummy))};
#		endif

#		if Z_COMPILER_HAS_TRAIT(TYPE_IS_INTERFACE_CLASS)
			enum {is_interface_class = Z_COMPILER_TRAIT(TYPE_IS_INTERFACE_CLASS)(T)};
#		endif

#		if Z_COMPILER_HAS_TRAIT(TYPE_IS_POLYMORPHIC)
			enum {is_polymorphic = Z_COMPILER_TRAIT(TYPE_IS_POLYMORPHIC)(T)};
#		endif
	};

	template <class T> struct Union : Compound<T> {
		enum {is_union = true};
	};

	struct PointerLike : Storable {
		enum {is_scalar	= true};

#		if Z_COMPILER_HAS_TRAIT(TYPE_IS_LITERAL)
			enum {is_literal = true};
#		endif

#		if Z_COMPILER_HAS_TRAIT(TYPE_IS_POD)
			enum {is_pod = true};
#		endif
	};

#	if Z_LANGUAGE_HAS_SPECIFIER(CPP, DECLARED_TYPE) && Z_LANGUAGE_HAS_LITERAL(CPP, NULL_POINTER)

		struct NullPointer : PointerLike {
			enum {	is_fundamental = true,
				is_nullptr     = true
			};

			typedef decltype(nullptr) type;
		};

#	endif

	template <class T> struct Pointer : PointerLike {
		enum {	is_pointer = true,
			is_value   = true
		};

		typedef T* type;
		typedef T  pointee_type;
	};

	template <class T, class C, class M> struct MemberPointer : PointerLike {
		enum {	is_member_pointer = true,
			is_pointer	  = true
		};

		typedef T type;
		typedef C class_type;
		typedef M pointee_type;
	};

	template <class T, class C, class M> struct DataMemberPointer : MemberPointer<T, C, M> {
		enum {is_data_member_pointer = true};

	};

	template <class T, class C, class M> struct MemberFunctionPointer : MemberPointer<T, C, M> {
		enum {	is_callable		   = true,
			is_member_function_pointer = true
		};
		enum {pointer_level = 1};

		typedef M to_function;
	};

	template <class T> struct Reference : Storable {
		enum {is_reference = true};

#		if Z_COMPILER_HAS_TRAIT(TYPE_IS_LITERAL)
			enum {is_literal = true};
#		endif

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

#	if Z_LANGUAGE_HAS(CPP, VARIADIC_TEMPLATE)

		template <class R, class... A> struct Function : Valid {
			enum {	is_callable = true,
				is_function = true
			};
			enum {arity = sizeof...(A)};

			typedef R type		   (A...);
			typedef R to_const	   (A...) const;
			typedef R to_volatile	   (A...)	volatile;
			typedef R to_const_volatile(A...) const volatile;

#			if Z_LANGUAGE_HAS(CPP, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)
				typedef R to_lvalue		  (A...)		&;
				typedef R to_rvalue		  (A...)		&&;
				typedef R to_const_lvalue	  (A...) const		&;
				typedef R to_const_rvalue	  (A...) const		&&;
				typedef R to_volatile_lvalue	  (A...)       volatile &;
				typedef R to_volatile_rvalue	  (A...)       volatile &&;
				typedef R to_const_volatile_lvalue(A...) const volatile &;
				typedef R to_const_volatile_rvalue(A...) const volatile &&;
#			endif

			typedef R return_type;
			typedef TypeList<A...> parameters;
		};

		template <class R, class... A> struct VariadicFunction : Function<R, A...> {
			enum {is_variadic = true};

			typedef R type		   (A..., ...);
			typedef R to_const	   (A..., ...) const;
			typedef R to_volatile	   (A..., ...)	     volatile;
			typedef R to_const_volatile(A..., ...) const volatile;

#			if Z_LANGUAGE_HAS(CPP, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)
				typedef R to_lvalue		  (A..., ...)		     &;
				typedef R to_rvalue		  (A..., ...)		     &&;
				typedef R to_const_lvalue	  (A..., ...) const	     &;
				typedef R to_const_rvalue	  (A..., ...) const	     &&;
				typedef R to_volatile_lvalue	  (A..., ...)       volatile &;
				typedef R to_volatile_rvalue	  (A..., ...)       volatile &&;
				typedef R to_const_volatile_lvalue(A..., ...) const volatile &;
				typedef R to_const_volatile_rvalue(A..., ...) const volatile &&;
#			endif
		};

#	endif

#	if Z_LANGUAGE_HAS(CPP, VARIADIC_TEMPLATE_EXTENDED_PARAMETERS)

		template <template <class...> class T, class... A> struct Template : Struct<T<A...> > {
			enum {is_template = true};
			enum {arity = sizeof...(A)};

			typedef TypeList<A...> parameters;
		};

#	endif
}}}}

namespace Zeta {namespace Detail {namespace Type {namespace Mixins {

	// MARK: - Mixins: Qualifiers (generic)

	template <class C> struct Unqualified : C {
		typedef		       typename C::type to_unqualified;
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

	template <class C> struct Qualified : C {
		enum {is_qualified = true};
	};

	template <class C> struct Const : Qualified<C> {
		enum {is_const = true};

		typedef typename C::to_const	      type;
		typedef typename C::to_const_volatile add_volatile;
		typedef typename C::to_const	      remove_volatile;
	};

	template <class C> struct Volatile : Qualified<C> {
		enum {is_volatile = true};

		typedef typename C::to_volatile	      type;
		typedef typename C::to_const_volatile add_const;
		typedef typename C::to_volatile	      remove_const;
	};

	template <class C> struct ConstVolatile : Qualified<C> {
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

	// MARK: - Mixins: Qualifiers (exact)

	template <class C> struct ConstExact : Const<C> {
		typedef const typename C::to_unsigned to_unsigned;
		typedef const typename C::to_signed   to_signed;
	};

	template <class C> struct VolatileExact : Volatile<C> {
		typedef volatile typename C::to_unsigned to_unsigned;
		typedef volatile typename C::to_signed	 to_signed;
	};

	template <class C> struct ConstVolatileExact : ConstVolatile<C> {
		typedef const volatile typename C::to_unsigned to_unsigned;
		typedef const volatile typename C::to_signed   to_signed;
	};

	// MARK: - Mixins: Qualifiers (array)

	template <class C> struct ConstArray : Const<C> {
		typedef const typename C::element_type element_type;
	};

	template <class C> struct VolatileArray : Volatile<C> {
		typedef volatile typename C::element_type element_type;
	};

	template <class C> struct ConstVolatileArray : ConstVolatile<C> {
		typedef const volatile typename C::element_type element_type;
	};

	// MARK: - Mixins: Qualifiers (function)

	template <class C> struct UnqualifiedFunction : C {
		typedef typename C::type		     to_unqualified;
		typedef typename C::to_const		     add_const;
		typedef typename C::to_volatile		     add_volatile;
		typedef typename C::to_const_volatile	     add_const_volatile;
		typedef typename C::to_lvalue		     add_lvalue;
		typedef typename C::to_rvalue		     add_rvalue;
		typedef typename C::to_const_lvalue	     add_const_lvalue;
		typedef typename C::to_const_rvalue	     add_const_rvalue;
		typedef typename C::to_volatile_lvalue	     add_volatile_lvalue;
		typedef typename C::to_volatile_rvalue	     add_volatile_rvalue;
		typedef typename C::to_const_volatile_lvalue add_const_volatile_lvalue;
		typedef typename C::to_const_volatile_rvalue add_const_volatile_rvalue;
		typedef typename C::type		     remove_const;
		typedef typename C::type		     remove_volatile;
		typedef typename C::type		     remove_const_volatile;
		typedef typename C::type		     remove_this;
		typedef typename C::type		     remove_const_this;
		typedef typename C::type		     remove_volatile_this;
		typedef typename C::type		     remove_const_volatile_this;
	};

	template <class C> struct QualifiedFunction : C {
		enum {is_qualified = true};
	};

	template <class C> struct ConstFunction : QualifiedFunction<C> {
		enum {is_const = true};

		typedef typename C::to_const		     type;
		typedef typename C::to_const_volatile	     add_volatile;
		typedef typename C::to_const_lvalue	     add_lvalue;
		typedef typename C::to_const_rvalue	     add_rvalue;
		typedef typename C::to_const_volatile_lvalue add_volatile_lvalue;
		typedef typename C::to_const_volatile_rvalue add_volatile_rvalue;
		typedef typename C::to_const		     remove_volatile;
		typedef typename C::to_const		     remove_this;
		typedef typename C::to_const		     remove_volatile_this;
	};

	template <class C> struct VolatileFunction : QualifiedFunction<C> {
		enum {is_volatile = true};

		typedef typename C::to_volatile		     type;
		typedef typename C::to_const_volatile	     add_const;
		typedef typename C::to_volatile_lvalue	     add_lvalue;
		typedef typename C::to_volatile_rvalue	     add_rvalue;
		typedef typename C::to_const_volatile_lvalue add_const_lvalue;
		typedef typename C::to_const_volatile_rvalue add_const_rvalue;
		typedef typename C::to_volatile		     remove_const;
		typedef typename C::to_volatile		     remove_this;
		typedef typename C::to_volatile		     remove_const_this;
	};

	template <class C> struct ConstVolatileFunction : QualifiedFunction<C> {
		enum {	is_const	  = true,
			is_const_volatile = true,
			is_volatile	  = true
		};

		typedef typename C::to_const_volatile	     type;
		typedef typename C::to_const_volatile	     add_const;
		typedef typename C::to_const_volatile	     add_volatile;
		typedef typename C::to_const_volatile_lvalue add_lvalue;
		typedef typename C::to_const_volatile_rvalue add_rvalue;
		typedef typename C::to_const_volatile_lvalue add_const_lvalue;
		typedef typename C::to_const_volatile_rvalue add_const_rvalue;
		typedef typename C::to_const_volatile_lvalue add_volatile_lvalue;
		typedef typename C::to_const_volatile_rvalue add_volatile_rvalue;
		typedef typename C::to_volatile		     remove_const;
		typedef typename C::to_const		     remove_volatile;
		typedef typename C::to_const_volatile	     remove_this;
		typedef typename C::to_volatile		     remove_const_this;
		typedef typename C::to_const		     remove_volatile_this;
	};

	template <class C> struct LValueFunction : QualifiedFunction<C> {
		enum {is_lvalue = true};

		typedef typename C::to_lvalue		     type;
		typedef typename C::to_const_lvalue	     add_const;
		typedef typename C::to_volatile_lvalue	     add_volatile;
		typedef typename C::to_const_volatile_lvalue add_const_volatile;
		typedef typename C::to_lvalue		     remove_const;
		typedef typename C::to_lvalue		     remove_volatile;
		typedef typename C::to_lvalue		     remove_const_volatile;
	};

	template <class C> struct RValueFunction : QualifiedFunction<C> {
		enum {is_rvalue = true};

		typedef typename C::to_rvalue		     type;
		typedef typename C::to_const_rvalue	     add_const;
		typedef typename C::to_volatile_rvalue	     add_volatile;
		typedef typename C::to_const_volatile_rvalue add_const_volatile;
		typedef typename C::to_rvalue		     remove_const;
		typedef typename C::to_rvalue		     remove_volatile;
		typedef typename C::to_rvalue		     remove_const_volatile;
	};

	template <class C> struct ConstLValueFunction : QualifiedFunction<C> {
		enum {	is_const	= true,
			is_const_lvalue = true,
			is_lvalue	= true
		};

		typedef typename C::to_const_lvalue	     type;
		typedef typename C::to_const_lvalue	     add_const;
		typedef typename C::to_const_volatile_lvalue add_volatile;
		typedef typename C::to_const_volatile_lvalue add_const_volatile;
		typedef typename C::to_const_lvalue	     add_lvalue;
		typedef typename C::to_const_rvalue	     add_rvalue;
		typedef typename C::to_const_volatile_lvalue add_volatile_lvalue;
		typedef typename C::to_const_volatile_rvalue add_volatile_rvalue;
		typedef typename C::to_lvalue		     remove_const;
		typedef typename C::to_const_lvalue	     remove_volatile;
		typedef typename C::to_lvalue		     remove_const_volatile;
		typedef typename C::to_const		     remove_this;
		typedef typename C::to_const		     remove_volatile_this;
	};

	template <class C> struct ConstRValueFunction : QualifiedFunction<C> {
		enum {	is_const	= true,
			is_const_rvalue = true,
			is_rvalue	= true
		};

		typedef typename C::to_const_rvalue	     type;
		typedef typename C::to_const_rvalue	     add_const;
		typedef typename C::to_const_volatile_rvalue add_volatile;
		typedef typename C::to_const_volatile_rvalue add_const_volatile;
		typedef typename C::to_const_lvalue	     add_lvalue;
		typedef typename C::to_const_rvalue	     add_rvalue;
		typedef typename C::to_const_volatile_lvalue add_volatile_lvalue;
		typedef typename C::to_const_volatile_rvalue add_volatile_rvalue;
		typedef typename C::to_rvalue		     remove_const;
		typedef typename C::to_const_rvalue	     remove_volatile;
		typedef typename C::to_rvalue		     remove_const_volatile;
		typedef typename C::to_const		     remove_this;
		typedef typename C::to_const		     remove_volatile_this;
	};

	template <class C> struct VolatileLValueFunction : QualifiedFunction<C> {
		enum {	is_lvalue	   = true,
			is_volatile	   = true,
			is_volatile_lvalue = true
		};

		typedef typename C::to_volatile_lvalue	     type;
		typedef typename C::to_const_volatile_lvalue add_const;
		typedef typename C::to_volatile_lvalue	     add_volatile;
		typedef typename C::to_const_volatile_lvalue add_const_volatile;
		typedef typename C::to_volatile_lvalue	     add_lvalue;
		typedef typename C::to_volatile_rvalue	     add_rvalue;
		typedef typename C::to_const_volatile_lvalue add_const_lvalue;
		typedef typename C::to_const_volatile_rvalue add_const_rvalue;
		typedef typename C::to_volatile_lvalue	     remove_const;
		typedef typename C::to_lvalue		     remove_volatile;
		typedef typename C::to_lvalue		     remove_const_volatile;
		typedef typename C::to_volatile		     remove_this;
		typedef typename C::to_volatile		     remove_const_this;
	};

	template <class C> struct VolatileRValueFunction : QualifiedFunction<C> {
		enum {	is_rvalue	   = true,
			is_volatile	   = true,
			is_volatile_rvalue = true
		};

		typedef typename C::to_volatile_rvalue	     type;
		typedef typename C::to_const_volatile_rvalue add_const;
		typedef typename C::to_volatile_rvalue	     add_volatile;
		typedef typename C::to_const_volatile_rvalue add_const_volatile;
		typedef typename C::to_volatile_lvalue	     add_lvalue;
		typedef typename C::to_volatile_rvalue	     add_rvalue;
		typedef typename C::to_const_volatile_lvalue add_const_lvalue;
		typedef typename C::to_const_volatile_rvalue add_const_rvalue;
		typedef typename C::to_volatile_rvalue	     remove_const;
		typedef typename C::to_rvalue		     remove_volatile;
		typedef typename C::to_rvalue		     remove_const_volatile;
		typedef typename C::to_volatile		     remove_this;
		typedef typename C::to_volatile		     remove_const_this;
	};

	template <class C> struct ConstVolatileLValueFunction : QualifiedFunction<C> {
		enum {	is_const		 = true,
			is_const_lvalue		 = true,
			is_const_volatile	 = true,
			is_const_volatile_lvalue = true,
			is_lvalue		 = true,
			is_volatile		 = true,
			is_volatile_lvalue	 = true
		};

		typedef typename C::to_const_volatile_lvalue type;
		typedef typename C::to_const_volatile_lvalue add_const;
		typedef typename C::to_const_volatile_lvalue add_volatile;
		typedef typename C::to_const_volatile_lvalue add_const_volatile;
		typedef typename C::to_const_volatile_lvalue add_lvalue;
		typedef typename C::to_const_volatile_rvalue add_rvalue;
		typedef typename C::to_const_volatile_lvalue add_const_lvalue;
		typedef typename C::to_const_volatile_rvalue add_const_rvalue;
		typedef typename C::to_const_volatile_lvalue add_volatile_lvalue;
		typedef typename C::to_const_volatile_rvalue add_volatile_rvalue;
		typedef typename C::to_volatile_lvalue	     remove_const;
		typedef typename C::to_const_lvalue	     remove_volatile;
		typedef typename C::to_lvalue		     remove_const_volatile;
		typedef typename C::to_const_volatile	     remove_this;
		typedef typename C::to_volatile		     remove_const_this;
		typedef typename C::to_const		     remove_volatile_this;
	};

	template <class C> struct ConstVolatileRValueFunction : QualifiedFunction<C> {
		enum {	is_const		 = true,
			is_const_rvalue		 = true,
			is_const_volatile	 = true,
			is_const_volatile_rvalue = true,
			is_rvalue		 = true,
			is_volatile		 = true,
			is_volatile_rvalue	 = true
		};

		typedef typename C::to_const_volatile_rvalue type;
		typedef typename C::to_const_volatile_rvalue add_const;
		typedef typename C::to_const_volatile_rvalue add_volatile;
		typedef typename C::to_const_volatile_rvalue add_const_volatile;
		typedef typename C::to_const_volatile_lvalue add_lvalue;
		typedef typename C::to_const_volatile_rvalue add_rvalue;
		typedef typename C::to_const_volatile_lvalue add_const_lvalue;
		typedef typename C::to_const_volatile_rvalue add_const_rvalue;
		typedef typename C::to_const_volatile_lvalue add_volatile_lvalue;
		typedef typename C::to_const_volatile_rvalue add_volatile_rvalue;
		typedef typename C::to_volatile_rvalue	     remove_const;
		typedef typename C::to_const_rvalue	     remove_volatile;
		typedef typename C::to_rvalue		     remove_const_volatile;
		typedef typename C::to_const_volatile	     remove_this;
		typedef typename C::to_volatile		     remove_const_this;
		typedef typename C::to_const		     remove_volatile_this;
	};

	// MARK: - Mixins: Kind

	enum {	Void,
		InconvertibleFunction,
		ConvertibleFunction,
		Value,
		VoidPointer,
		Pointer,
		MemberFunctionPointer,
		Reference,
		Template
	};

	template <class C> struct Virtual : C {
		typedef typename C::type remove_pointer;
		typedef typename C::type remove_reference;
	};

	template <class C> struct Storable : Virtual<C> {
		Z_DEFINE_STRICT_STRUCTURE (typename C::type value;     ) to_wrap;
		Z_DEFINE_STRICT_STRUCTURE (UInt8 data[sizeof(to_wrap)];) to_opaque;

		enum {	size = sizeof(to_wrap),
			bits = sizeof(to_wrap) * 8
		};
	};

	template <UInt K, class C> struct Kind;

	// MARK: - Mixins: Kind (virtual)

	template <class C> struct Kind<Void, C> : Virtual<C> {
		typedef typename C::type* to_pointer;
		typedef typename C::type* add_pointer;
	};

	template <class C> struct Kind<InconvertibleFunction, C> : Virtual<C> {
		typedef typename C::type remove_pointer;
		typedef typename C::type remove_reference;
		typedef typename C::type to_function;
	};

	template <class C> struct Kind<ConvertibleFunction, C> : Kind<InconvertibleFunction, C> {
		typedef typename C::type* to_pointer;
		typedef typename C::type& to_lvalue_reference;
		typedef typename C::type* add_pointer;
		typedef typename C::type& add_lvalue_reference;

#		if Z_LANGUAGE_HAS(CPP, RVALUE_REFERENCE)
			typedef typename C::type&& to_rvalue_reference;
			typedef typename C::type&& add_rvalue_reference;
#		endif
	};

	// MARK: - Mixins: Kind (storable)

	template <class C> struct Kind<Value, C> : Storable<C> {
		typedef typename C::type* to_pointer;
		typedef typename C::type& to_lvalue_reference;
		typedef typename C::type* add_pointer;
		typedef typename C::type& add_lvalue_reference;

#		if Z_LANGUAGE_HAS(CPP, RVALUE_REFERENCE)
			typedef typename C::type&& to_rvalue_reference;
			typedef typename C::type&& add_rvalue_reference;
#		endif
	};

	template <class C> struct Kind<VoidPointer, C> : Storable<C> {
		typedef typename C::type	  to_pointer;
		typedef typename C::type*	  add_pointer;
		typedef typename C::type&	  add_lvalue_reference;
		typedef typename C::pointee_type  remove_pointer;

#		if Z_LANGUAGE_HAS(CPP, RVALUE_REFERENCE)
			typedef typename C::type&& add_rvalue_reference;
#		endif
	};

	template <class C> struct Kind<Pointer, C> : Kind<VoidPointer, C> {
		typedef typename C::pointee_type& to_lvalue_reference;

#		if Z_LANGUAGE_HAS(CPP, RVALUE_REFERENCE)
			typedef typename C::pointee_type&& to_rvalue_reference;
#		endif
	};

	template <class C> struct Kind<MemberFunctionPointer, C> : Storable<C> {
		typedef typename C::pointee_type to_function;
	};

	template <class C> struct Kind<Reference, C> : Storable<C> {
		typedef NaT to_const;
		typedef NaT to_volatile;
		typedef NaT to_const_volatile;
		typedef NaT add_const;
		typedef NaT add_volatile;
		typedef NaT add_const_volatile;

		typedef typename C::referenced_type* to_pointer;
		typedef typename C::referenced_type& to_lvalue_reference;
		typedef typename C::type	     remove_pointer;
		typedef typename C::referenced_type  remove_reference;

#		if Z_LANGUAGE_HAS(CPP, RVALUE_REFERENCE)
			typedef typename C::referenced_type&& to_rvalue_reference;
#		endif
	};

	template <class C> struct Kind<Template, C> : Kind<Value, C> {
		// For future use.
	};
}}}}

namespace Zeta {namespace Detail {namespace Type {

	// MARK: - Specializations: Enumerations, structures and unions

	template <class T> struct Case : Mixins::Unqualified<
#		if Z_COMPILER_HAS_TRAIT(TYPE_IS_ENUM) && Z_COMPILER_HAS_TRAIT(TYPE_IS_UNION)
			typename SelectType<
				Z_COMPILER_TRAIT(TYPE_IS_ENUM)(T) ? 2 : Z_COMPILER_TRAIT(TYPE_IS_UNION)(T),
				Abstract::Struct<T>, Abstract::Union<T>, Abstract::Enum<T>
			>::type
#		elif Z_COMPILER_HAS_TRAIT(TYPE_IS_ENUM)
			typename SelectType<Z_COMPILER_TRAIT(TYPE_IS_ENUM)(T), Abstract::Struct<T>, Abstract::Enum<T> >::type
#		elif Z_COMPILER_HAS_TRAIT(TYPE_IS_UNION)
			typename SelectType<Z_COMPILER_TRAIT(TYPE_IS_UNION)(T), Abstract::Struct<T>, Abstract::Union<T> >::type
#		else
			Abstract::Struct<T>
#		endif
	> {};

	// MARK: - Specializations: void

	template <> struct Case<void> : Mixins::Unqualified<Abstract::Void> {};

	// MARK: - Specializations: Numbers

#	if Z_UINT8_BASE_VALUE_TYPE == Z_VALUE_TYPE_UINT8
		template <> struct Case<UInt8> : Mixins::Unqualified<Abstract::UInt8> {};
#	endif

#	if Z_UINT16_BASE_VALUE_TYPE == Z_VALUE_TYPE_UINT16
		template <> struct Case<UInt16> : Mixins::Unqualified<Abstract::UInt16> {};
#	endif

#	if defined(Z_UINT32) && Z_UINT32_BASE_VALUE_TYPE == Z_VALUE_TYPE_UINT32
		template <> struct Case<UInt32> : Mixins::Unqualified<Abstract::UInt32> {};
#	endif

#	if defined(Z_UINT64) && Z_UINT64_BASE_VALUE_TYPE == Z_VALUE_TYPE_UINT64
		template <> struct Case<UInt64> : Mixins::Unqualified<Abstract::UInt64> {};
#	endif

#	if defined(Z_UINT128) && Z_UINT128_BASE_VALUE_TYPE == Z_VALUE_TYPE_UINT128
		template <> struct Case<UInt128> : Mixins::Unqualified<Abstract::UInt128> {};
#	endif

#	if Z_INT8_BASE_VALUE_TYPE == Z_VALUE_TYPE_INT8
		template <> struct Case<Int8> : Mixins::Unqualified<Abstract::Int8> {};
#	endif

#	if Z_INT16_BASE_VALUE_TYPE == Z_VALUE_TYPE_INT16
		template <> struct Case<Int16> : Mixins::Unqualified<Abstract::Int16> {};
#	endif

#	if defined(Z_INT32) && Z_INT32_BASE_VALUE_TYPE == Z_VALUE_TYPE_INT32
		template <> struct Case<Int32> : Mixins::Unqualified<Abstract::Int32> {};
#	endif

#	if defined(Z_INT64) && Z_INT64_BASE_VALUE_TYPE == Z_VALUE_TYPE_INT64
		template <> struct Case<Int64> : Mixins::Unqualified<Abstract::Int64> {};
#	endif

#	if defined(Z_INT128) && Z_INT128_BASE_VALUE_TYPE == Z_VALUE_TYPE_INT128
		template <> struct Case<Int128> : Mixins::Unqualified<Abstract::Int128> {};
#	endif

	template <> struct Case<Character> : Mixins::Unqualified<Abstract::Character> {};

	template <> struct Case<UChar > : Mixins::Unqualified<Abstract::UChar > {};
	template <> struct Case<UShort> : Mixins::Unqualified<Abstract::UShort> {};
	template <> struct Case<UInt  > : Mixins::Unqualified<Abstract::UInt  > {};
	template <> struct Case<ULong > : Mixins::Unqualified<Abstract::ULong > {};

#	ifdef Z_ULLONG
		template <> struct Case<ULLong> : Mixins::Unqualified<Abstract::ULLong> {};
#	endif

	template <> struct Case<Char > : Mixins::Unqualified<Abstract::Char > {};
	template <> struct Case<Short> : Mixins::Unqualified<Abstract::Short> {};
	template <> struct Case<Int  > : Mixins::Unqualified<Abstract::Int  > {};
	template <> struct Case<Long > : Mixins::Unqualified<Abstract::Long > {};

#	ifdef Z_LLONG
		template <> struct Case<LLong> : Mixins::Unqualified<Abstract::LLong> {};
#	endif

#	ifdef Z_FLOAT
		template <> struct Case<Float> : Mixins::Unqualified<Abstract::Float> {};
#	endif

#	ifdef Z_DOUBLE
		template <> struct Case<Double> : Mixins::Unqualified<Abstract::Double> {};
#	endif

#	ifdef Z_LDOUBLE
		template <> struct Case<LDouble> : Mixins::Unqualified<Abstract::LDouble> {};
#	endif

	// MARK: - Specializations: Sized arrays

	template <class T, Size N> struct Case<T[N]> : Mixins::Unqualified<Abstract::SizedArray<T, N> > {};

	template <class T, Size N> struct Case<const	      T[N]> : Mixins::ConstArray	<Case<T[N]> > {};
	template <class T, Size N> struct Case<	     volatile T[N]> : Mixins::VolatileArray	<Case<T[N]> > {};
	template <class T, Size N> struct Case<const volatile T[N]> : Mixins::ConstVolatileArray<Case<T[N]> > {};

	// MARK: - Specializations: Flexible arrays

	template <class T> struct Case<T[]> : Mixins::Unqualified<Abstract::FlexibleArray<T> > {};

	template <class T> struct Case<const	      T[]> : Mixins::ConstArray	       <Case<T[]> > {};
	template <class T> struct Case<	     volatile T[]> : Mixins::VolatileArray     <Case<T[]> > {};
	template <class T> struct Case<const volatile T[]> : Mixins::ConstVolatileArray<Case<T[]> > {};

	// MARK: - Specializations: Pointers

#	if Z_LANGUAGE_HAS_SPECIFIER(CPP, DECLARED_TYPE) && Z_LANGUAGE_HAS_LITERAL(CPP, NULL_POINTER)
		template <> struct Case<decltype(nullptr)> : Mixins::Unqualified<Abstract::NullPointer> {};
#	endif

	template <class T> class Case<T*> : public Mixins::Unqualified<Abstract::Pointer<T> > {
		private:
		typedef Case<T> Pointee;

		public:
		enum {	is_function_pointer = Pointee::is_function,
			is_callable	    = is_function_pointer,
			is_void_pointer	    = Pointee::is_void
		};
		enum {pointer_level = Pointee::pointer_level + 1};

		typedef typename SelectType<is_function_pointer, NaT, T>::type to_function;
	};

	template <class C, class T> struct Case<T C::*> : Mixins::Unqualified<Abstract::DataMemberPointer<T C::*, C, T> > {
		enum {pointer_level = Case<T>::pointer_level + 1};
	};

#	if Z_LANGUAGE_HAS(CPP, VARIADIC_TEMPLATE)

		template <class C, class R, class... A> struct Case<R(C::*)(A...)		 > : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(A...)		     , C, R(A...)		> > {};
		template <class C, class R, class... A> struct Case<R(C::*)(A...) const		 > : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(A...) const	     , C, R(A...) const		> > {};
		template <class C, class R, class... A> struct Case<R(C::*)(A...)	volatile > : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(A...)	     volatile, C, R(A...)	volatile> > {};
		template <class C, class R, class... A> struct Case<R(C::*)(A...) const volatile > : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(A...) const volatile, C, R(A...) const volatile> > {};

		template <class C, class R, class... A> struct Case<R(C::*)(A..., ...)		      > : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(A..., ...)	       , C, R(A..., ...)	       > > {};
		template <class C, class R, class... A> struct Case<R(C::*)(A..., ...) const	      > : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(A..., ...) const	       , C, R(A..., ...) const	       > > {};
		template <class C, class R, class... A> struct Case<R(C::*)(A..., ...)	     volatile > : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(A..., ...)       volatile, C, R(A..., ...)       volatile> > {};
		template <class C, class R, class... A> struct Case<R(C::*)(A..., ...) const volatile > : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(A..., ...) const volatile, C, R(A..., ...) const volatile> > {};

#		if Z_LANGUAGE_HAS(CPP, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)

			template <class C, class R, class... A> struct Case<R(C::*)(A...)		 & > : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(A...)		& , C, R(A...)		      & > > {};
			template <class C, class R, class... A> struct Case<R(C::*)(A...)		 &&> : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(A...)		&&, C, R(A...)		      &&> > {};
			template <class C, class R, class... A> struct Case<R(C::*)(A...) const		 & > : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(A...) const		& , C, R(A...) const	      & > > {};
			template <class C, class R, class... A> struct Case<R(C::*)(A...) const		 &&> : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(A...) const		&&, C, R(A...) const	      &&> > {};
			template <class C, class R, class... A> struct Case<R(C::*)(A...)	volatile & > : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(A...)       volatile & , C, R(A...)	     volatile & > > {};
			template <class C, class R, class... A> struct Case<R(C::*)(A...)	volatile &&> : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(A...)       volatile &&, C, R(A...)	     volatile &&> > {};
			template <class C, class R, class... A> struct Case<R(C::*)(A...) const volatile & > : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(A...) const volatile & , C, R(A...) const volatile &	> > {};
			template <class C, class R, class... A> struct Case<R(C::*)(A...) const volatile &&> : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(A...) const volatile &&, C, R(A...) const volatile &&> > {};

			template <class C, class R, class... A> struct Case<R(C::*)(A..., ...)		      & > : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(A..., ...)		  & , C, R(A...)		& > > {};
			template <class C, class R, class... A> struct Case<R(C::*)(A..., ...)		      &&> : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(A..., ...)		  &&, C, R(A...)		&&> > {};
			template <class C, class R, class... A> struct Case<R(C::*)(A..., ...) const	      & > : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(A..., ...) const	  & , C, R(A...) const		& > > {};
			template <class C, class R, class... A> struct Case<R(C::*)(A..., ...) const	      &&> : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(A..., ...) const	  &&, C, R(A...) const		&&> > {};
			template <class C, class R, class... A> struct Case<R(C::*)(A..., ...)	     volatile & > : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(A..., ...)	 volatile & , C, R(A...)       volatile & > > {};
			template <class C, class R, class... A> struct Case<R(C::*)(A..., ...)	     volatile &&> : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(A..., ...)	 volatile &&, C, R(A...)       volatile &&> > {};
			template <class C, class R, class... A> struct Case<R(C::*)(A..., ...) const volatile & > : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(A..., ...) const volatile & , C, R(A...) const volatile & > > {};
			template <class C, class R, class... A> struct Case<R(C::*)(A..., ...) const volatile &&> : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(A..., ...) const volatile &&, C, R(A...) const volatile &&> > {};

#		endif

#	endif

	// MARK: - Specializations: References

	template <class T> struct Case<T&> : Mixins::Unqualified<Abstract::LValueReference<T> > {
		enum {	is_function_reference	     = Case<T>::is_function,
			is_function_lvalue_reference = is_function_reference,
			is_callable		     = is_function_reference
		};

		typedef typename SelectType<is_function_reference, NaT, T>::type to_function;
	};

	template <class T> struct Case<T&&> : Mixins::Unqualified<Abstract::RValueReference<T> > {
		enum {	is_function_reference	     = Case<T>::is_function,
			is_function_rvalue_reference = is_function_reference,
			is_callable		     = is_function_reference
		};

		typedef typename SelectType<is_function_reference, NaT, T>::type to_function;
	};

	// MARK: - Specializations: Functions

#	if Z_LANGUAGE_HAS(CPP, VARIADIC_TEMPLATE)

		template <class R, class... A> struct Case<R(A...)> : Mixins::UnqualifiedFunction<Abstract::Function<R, A...> > {};

		template <class R, class... A> struct Case<R(A...) const	 > : Mixins::ConstFunction	  <Case<R(A...)> > {};
		template <class R, class... A> struct Case<R(A...)	 volatile> : Mixins::VolatileFunction	  <Case<R(A...)> > {};
		template <class R, class... A> struct Case<R(A...) const volatile> : Mixins::ConstVolatileFunction<Case<R(A...)> > {};

		template <class R, class... A> struct Case<R(A..., ...)> : Mixins::UnqualifiedFunction<Abstract::VariadicFunction<R, A...> > {};

		template <class R, class... A> struct Case<R(A..., ...) const	      > : Mixins::ConstFunction	       <Case<R(A..., ...)> > {};
		template <class R, class... A> struct Case<R(A..., ...)	      volatile> : Mixins::VolatileFunction     <Case<R(A..., ...)> > {};
		template <class R, class... A> struct Case<R(A..., ...) const volatile> : Mixins::ConstVolatileFunction<Case<R(A..., ...)> > {};

#		if Z_LANGUAGE_HAS(CPP, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)

			template <class R, class... A> struct Case<R(A...)		  & > : Mixins::LValueFunction		   <Case<R(A...)> > {};
			template <class R, class... A> struct Case<R(A...)		  &&> : Mixins::RValueFunction		   <Case<R(A...)> > {};
			template <class R, class... A> struct Case<R(A...) const	  & > : Mixins::ConstLValueFunction	   <Case<R(A...)> > {};
			template <class R, class... A> struct Case<R(A...) const	  &&> : Mixins::ConstRValueFunction	   <Case<R(A...)> > {};
			template <class R, class... A> struct Case<R(A...)	 volatile & > : Mixins::VolatileLValueFunction	   <Case<R(A...)> > {};
			template <class R, class... A> struct Case<R(A...)	 volatile &&> : Mixins::VolatileRValueFunction	   <Case<R(A...)> > {};
			template <class R, class... A> struct Case<R(A...) const volatile & > : Mixins::ConstVolatileLValueFunction<Case<R(A...)> > {};
			template <class R, class... A> struct Case<R(A...) const volatile &&> : Mixins::ConstVolatileRValueFunction<Case<R(A...)> > {};

			template <class R, class... A> struct Case<R(A..., ...)		       & > : Mixins::LValueFunction		<Case<R(A..., ...)> > {};
			template <class R, class... A> struct Case<R(A..., ...)		       &&> : Mixins::RValueFunction		<Case<R(A..., ...)> > {};
			template <class R, class... A> struct Case<R(A..., ...) const	       & > : Mixins::ConstLValueFunction	<Case<R(A..., ...)> > {};
			template <class R, class... A> struct Case<R(A..., ...) const	       &&> : Mixins::ConstRValueFunction	<Case<R(A..., ...)> > {};
			template <class R, class... A> struct Case<R(A..., ...)	      volatile & > : Mixins::VolatileLValueFunction     <Case<R(A..., ...)> > {};
			template <class R, class... A> struct Case<R(A..., ...)	      volatile &&> : Mixins::VolatileRValueFunction     <Case<R(A..., ...)> > {};
			template <class R, class... A> struct Case<R(A..., ...) const volatile & > : Mixins::ConstVolatileLValueFunction<Case<R(A..., ...)> > {};
			template <class R, class... A> struct Case<R(A..., ...) const volatile &&> : Mixins::ConstVolatileRValueFunction<Case<R(A..., ...)> > {};

#		endif

#	endif

	// MARK: - Specializations: Templates

#	if Z_LANGUAGE_HAS(CPP, VARIADIC_TEMPLATE_EXTENDED_PARAMETERS)
		template <template <class...> class T, class... A> struct Case<T<A...> > : Mixins::Unqualified<Abstract::Template<T, A...> > {};
#	endif

	// MARK: - Specializations: Qualified types

	template <class T> struct Case<const	      T> : SelectType<Case<T>::is_exact, Mixins::Const	      <Case<T> >, Mixins::ConstExact	    <Case<T> > >::type {};
	template <class T> struct Case<	     volatile T> : SelectType<Case<T>::is_exact, Mixins::Volatile     <Case<T> >, Mixins::VolatileExact	    <Case<T> > >::type {};
	template <class T> struct Case<const volatile T> : SelectType<Case<T>::is_exact, Mixins::ConstVolatile<Case<T> >, Mixins::ConstVolatileExact<Case<T> > >::type {};

	// MARK: - Final aggregate

	template <class T> struct Final : Mixins::Kind<
		Case<T>::is_storable
			? (Case<T>::is_pointer
				? (Case<T>::is_member_function_pointer
					? Mixins::MemberFunctionPointer
					: (Case<T>::is_void_pointer ? Mixins::VoidPointer : Mixins::Pointer))
				: (Case<T>::is_reference
					? Mixins::Reference
					: (Case<T>::is_template ? Mixins::Template : Mixins::Value)))
			: (Case<T>::is_void
				? Mixins::Void
				: (Case<T>::is_function && Case<T>::is_qualified
					? Mixins::InconvertibleFunction
					: Mixins::ConvertibleFunction)),
		Case<T>
	> {
		typedef typename SelectType<
			Final::is_compound,
			T, typename Final<const typename Final::remove_const_volatile>::add_lvalue_reference
		>::type to_parameter;
	};

	template <> struct Final<		NaT> : Abstract::Invalid {};
	template <> struct Final<const		NaT> : Abstract::Invalid {};
	template <> struct Final<      volatile NaT> : Abstract::Invalid {};
	template <> struct Final<const volatile NaT> : Abstract::Invalid {};
}}}

namespace Zeta {

	template <class A, class B> struct TypeAreEqual	      : False {};
	template <class A	  > struct TypeAreEqual<A, A> : True  {};

#	if Z_COMPILER_HAS_TRAIT(TYPE_IS_ASSIGNABLE)
		template <class T, class from_type> struct TypeIsAssignable {
			enum {value = Z_COMPILER_TRAIT(TYPE_IS_ASSIGNABLE)(T, from_type)};
		};
#	endif

#	if Z_COMPILER_HAS_TRAIT(TYPE_IS_BASE)
		template <class T, class of_type> struct TypeIsBase {
			enum {value = Z_COMPILER_TRAIT(TYPE_IS_BASE)(T, of_type)};
		};
#	endif

#	if Z_COMPILER_HAS_TRAIT(TYPE_IS_CONVERTIBLE)
		template <class T, class to_type> struct TypeIsConvertible {
			enum {value = Z_COMPILER_TRAIT(TYPE_IS_CONVERTIBLE)(T, to_type)};
		};
#	endif

#	if Z_COMPILER_HAS_TRAIT(TYPE_IS_NOTHROW_ASSIGNABLE)
		template <class T, class from_type> struct TypeIsNothrowAssignable {
			enum {value = Z_COMPILER_TRAIT(TYPE_IS_NOTHROW_ASSIGNABLE)(T, from_type)};
		};
#	endif

#	if Z_COMPILER_HAS_TRAIT(TYPE_IS_TRIVIALLY_ASSIGNABLE)
		template <class T, class from_type> struct TypeIsTriviallyAssignable {
			enum {value = Z_COMPILER_TRAIT(TYPE_IS_TRIVIALLY_ASSIGNABLE)(T, from_type)};
		};
#	endif

#	if Z_LANGUAGE_HAS(CPP, VARIADIC_TEMPLATE)

#		if Z_COMPILER_HAS_TRAIT(TYPE_IS_CONSTRUCTIBLE)
			template <class T, class... parameters> struct TypeIsConstructible {
				enum {value = Z_COMPILER_TRAIT(TYPE_IS_CONSTRUCTIBLE)(T, parameters...)};
			};
#		endif

#		if Z_COMPILER_HAS_TRAIT(TYPE_IS_NOTHROW_CONSTRUCTIBLE)
			template <class T, class... parameters> struct TypeIsNothrowConstructible {
				enum {value = Z_COMPILER_TRAIT(TYPE_IS_NOTHROW_CONSTRUCTIBLE)(T, parameters...)};
			};
#		endif

#		if Z_COMPILER_HAS_TRAIT(TYPE_IS_TRIVIALLY_CONSTRUCTIBLE)
			template <class T, class... parameters> struct TypeIsTriviallyConstructible {
				enum {value = Z_COMPILER_TRAIT(TYPE_IS_TRIVIALLY_CONSTRUCTIBLE)(T, parameters...)};
			};
#		endif

#	endif

	template <class T, class klass> struct TypeToMemberPointer;

	template <class T, class C> struct TypeToMemberPointer {typedef T C::*type;};

	template <class C> struct TypeToMemberPointer<		     void, C> {typedef NaT type;};
	template <class C> struct TypeToMemberPointer<const	     void, C> {typedef NaT type;};
	template <class C> struct TypeToMemberPointer<	    volatile void, C> {typedef NaT type;};
	template <class C> struct TypeToMemberPointer<const volatile void, C> {typedef NaT type;};

#	if Z_LANGUAGE_HAS(CPP, VARIADIC_TEMPLATE)

		template <class C, class R, class... A> struct TypeToMemberPointer<R(A...)		 , C> {typedef R(C::*type)(A...)	       ;};
		template <class C, class R, class... A> struct TypeToMemberPointer<R(A...) const	 , C> {typedef R(C::*type)(A...) const	       ;};
		template <class C, class R, class... A> struct TypeToMemberPointer<R(A...)	 volatile, C> {typedef R(C::*type)(A...)       volatile;};
		template <class C, class R, class... A> struct TypeToMemberPointer<R(A...) const volatile, C> {typedef R(C::*type)(A...) const volatile;};

		template <class C, class R, class... A> struct TypeToMemberPointer<R(A..., ...)		      , C> {typedef R(C::*type)(A...)		    ;};
		template <class C, class R, class... A> struct TypeToMemberPointer<R(A..., ...) const	      , C> {typedef R(C::*type)(A...) const	    ;};
		template <class C, class R, class... A> struct TypeToMemberPointer<R(A..., ...)	      volatile, C> {typedef R(C::*type)(A...)	    volatile;};
		template <class C, class R, class... A> struct TypeToMemberPointer<R(A..., ...) const volatile, C> {typedef R(C::*type)(A...) const volatile;};

#		if Z_LANGUAGE_HAS(CPP, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)

			template <class C, class R, class... A> struct TypeToMemberPointer<R(A...)		  & , C> {typedef R(C::*type)(A...)		   & ;};
			template <class C, class R, class... A> struct TypeToMemberPointer<R(A...)		  &&, C> {typedef R(C::*type)(A...)		   &&;};
			template <class C, class R, class... A> struct TypeToMemberPointer<R(A...) const	  & , C> {typedef R(C::*type)(A...) const	   & ;};
			template <class C, class R, class... A> struct TypeToMemberPointer<R(A...) const	  &&, C> {typedef R(C::*type)(A...) const	   &&;};
			template <class C, class R, class... A> struct TypeToMemberPointer<R(A...)	 volatile & , C> {typedef R(C::*type)(A...)	  volatile & ;};
			template <class C, class R, class... A> struct TypeToMemberPointer<R(A...)	 volatile &&, C> {typedef R(C::*type)(A...)	  volatile &&;};
			template <class C, class R, class... A> struct TypeToMemberPointer<R(A...) const volatile & , C> {typedef R(C::*type)(A...) const volatile & ;};
			template <class C, class R, class... A> struct TypeToMemberPointer<R(A...) const volatile &&, C> {typedef R(C::*type)(A...) const volatile &&;};

			template <class C, class R, class... A> struct TypeToMemberPointer<R(A..., ...)		       & , C> {typedef R(C::*type)(A..., ...)		     & ;};
			template <class C, class R, class... A> struct TypeToMemberPointer<R(A..., ...)		       &&, C> {typedef R(C::*type)(A..., ...)		     &&;};
			template <class C, class R, class... A> struct TypeToMemberPointer<R(A..., ...) const	       & , C> {typedef R(C::*type)(A..., ...) const	     & ;};
			template <class C, class R, class... A> struct TypeToMemberPointer<R(A..., ...) const	       &&, C> {typedef R(C::*type)(A..., ...) const	     &&;};
			template <class C, class R, class... A> struct TypeToMemberPointer<R(A..., ...)	      volatile & , C> {typedef R(C::*type)(A..., ...)	    volatile & ;};
			template <class C, class R, class... A> struct TypeToMemberPointer<R(A..., ...)	      volatile &&, C> {typedef R(C::*type)(A..., ...)	    volatile &&;};
			template <class C, class R, class... A> struct TypeToMemberPointer<R(A..., ...) const volatile & , C> {typedef R(C::*type)(A..., ...) const volatile & ;};
			template <class C, class R, class... A> struct TypeToMemberPointer<R(A..., ...) const volatile &&, C> {typedef R(C::*type)(A..., ...) const volatile &&;};

#		endif

#	endif

	template <class T> class Type : public Detail::Type::Final<T> {
		public:

#		if Z_LANGUAGE_HAS(CPP, TEMPLATE_ALIAS)
			template <class klass> using to_member_pointer = typename TypeToMemberPointer<typename Type::type, klass>::type;
#		endif

		struct flow {
			enum {	is_arithmetic		     = Type::is_arithmetic,
				is_array		     = Type::is_array,
				is_callable		     = Type::is_callable,
				is_class		     = Type::is_class,
				is_compound		     = Type::is_compound,
				is_const		     = Type::is_const,
				is_const_lvalue		     = Type::is_const_lvalue,
				is_const_rvalue		     = Type::is_const_rvalue,
				is_const_volatile	     = Type::is_const_volatile,
				is_const_volatile_lvalue     = Type::is_const_volatile_lvalue,
				is_const_volatile_rvalue     = Type::is_const_volatile_rvalue,
				is_data_member_pointer	     = Type::is_data_member_pointer,
				is_empty		     = Type::is_empty,
				is_exact		     = Type::is_exact,
				is_integer		     = Type::is_integer,
				is_invalid		     = Type::is_invalid,
				is_flexible_array	     = Type::is_flexible_array,
				is_function		     = Type::is_function,
				is_function_pointer	     = Type::is_function_pointer,
				is_function_reference	     = Type::is_function_reference,
				is_function_lvalue_reference = Type::is_function_lvalue_reference,
				is_function_rvalue_reference = Type::is_function_rvalue_reference,
				is_fundamental		     = Type::is_fundamental,
				is_lvalue		     = Type::is_lvalue,
				is_lvalue_reference	     = Type::is_lvalue_reference,
				is_member_function_pointer   = Type::is_member_function_pointer,
				is_member_pointer	     = Type::is_member_pointer,
				is_natural		     = Type::is_natural,
				is_number		     = Type::is_number,
				is_nullptr		     = Type::is_nullptr,
				is_pointer		     = Type::is_pointer,
				is_qualified		     = Type::is_qualified,
				is_real			     = Type::is_real,
				is_reference		     = Type::is_reference,
				is_rvalue		     = Type::is_rvalue,
				is_rvalue_reference	     = Type::is_rvalue_reference,
				is_scalar		     = Type::is_scalar,
				is_signed		     = Type::is_signed,
				is_storable		     = Type::is_storable,
				is_struct		     = Type::is_struct,
				is_template		     = Type::is_template,
				is_valid		     = Type::is_valid,
				is_value		     = Type::is_value,
				is_variadic		     = Type::is_variadic,
				is_variadic_function	     = Type::is_variadic_function,
				is_void			     = Type::is_void,
				is_void_pointer		     = Type::is_void_pointer,
				is_volatile		     = Type::is_volatile,
				is_volatile_lvalue	     = Type::is_volatile_lvalue,
				is_volatile_rvalue	     = Type::is_volatile_rvalue
			};

#			if Z_COMPILER_HAS_TRAIT(TYPE_IS_ABSTRACT)
				enum {is_abstract = Type::is_abstract};
#			endif

#			if Z_COMPILER_HAS_TRAIT(TYPE_IS_AGGREGATE)
				enum {is_aggregate = Type::is_aggregate};
#			endif

#			if Z_COMPILER_HAS_TRAIT(TYPE_IS_ENUM)
				enum {is_enum = Type::is_enum};
#			endif

#			if Z_COMPILER_HAS_TRAIT(TYPE_IS_FINAL)
				enum {is_final = Type::is_final};
#			endif

#			if Z_COMPILER_HAS_TRAIT(TYPE_IS_INTERFACE_CLASS)
				enum {is_interface_class = Type::is_interface_class};
#			endif

#			if Z_COMPILER_HAS_TRAIT(TYPE_IS_LITERAL)
				enum {is_literal = Type::is_literal};
#			endif

#			if Z_COMPILER_HAS_TRAIT(TYPE_IS_POD)
				enum {is_pod = Type::is_pod};
#			endif

#			if Z_COMPILER_HAS_TRAIT(TYPE_IS_POLYMORPHIC)
				enum {is_polymorphic = Type::is_polymorphic};
#			endif

#			if Z_COMPILER_HAS_TRAIT(TYPE_IS_UNION)
				enum {is_union = Type::is_union};
#			endif

			enum {	is_copy_assignable		   = Type::is_copy_assignable,
				is_copy_constructible		   = Type::is_copy_constructible,
				is_default_constructible	   = Type::is_default_constructible,
				is_destructible			   = Type::is_destructible,
				is_move_assignable		   = Type::is_move_assignable,
				is_move_constructible		   = Type::is_move_constructible,
				is_nothrow_copy_assignable	   = Type::is_nothrow_copy_assignable,
				is_nothrow_copy_constructible	   = Type::is_nothrow_copy_constructible,
				is_nothrow_default_constructible   = Type::is_nothrow_default_constructible,
				is_nothrow_destructible		   = Type::is_nothrow_destructible,
				is_nothrow_move_assignable	   = Type::is_nothrow_move_assignable,
				is_nothrow_move_constructible	   = Type::is_nothrow_move_constructible,
				is_trivially_copy_assignable	   = Type::is_trivially_copy_assignable,
				is_trivially_copy_constructible	   = Type::is_trivially_copy_constructible,
				is_trivially_default_constructible = Type::is_trivially_default_constructible,
				is_trivially_destructible	   = Type::is_trivially_destructible,
				is_trivially_move_assignable	   = Type::is_trivially_move_assignable,
				is_trivially_move_constructible	   = Type::is_trivially_move_constructible
			};
			enum {	arity	      = Type::arity,
				element_count = Type::element_count,
				pointer_level = Type::pointer_level
			};
			enum {	bits = Type::bits,
				size = Type::size
			};

			typedef Type end;

			typedef typename Type::type type;

			typedef typename Type<typename Type::class_type	    >::flow class_type;
			typedef typename Type<typename Type::element_type   >::flow element_type;
			typedef typename Type<typename Type::pointee_type   >::flow pointee_type;
			typedef typename Type<typename Type::referenced_type>::flow referenced_type;
			typedef typename Type<typename Type::return_type    >::flow return_type;

#			if Z_COMPILER_HAS_TRAIT(TYPE_UNDERLYING_TYPE)
				typedef typename Type<typename Type::underlying_type>::flow underlying_type;
#			endif

			typedef typename Type::parameters parameters;

			typedef typename Type<typename Type::to_parameter	     >::flow to_parameter;
			typedef typename Type<typename Type::to_const		     >::flow to_const;
			typedef typename Type<typename Type::to_const_lvalue	     >::flow to_const_lvalue;
			typedef typename Type<typename Type::to_const_rvalue	     >::flow to_const_rvalue;
			typedef typename Type<typename Type::to_const_volatile	     >::flow to_const_volatile;
			typedef typename Type<typename Type::to_const_volatile_lvalue>::flow to_const_volatile_lvalue;
			typedef typename Type<typename Type::to_const_volatile_rvalue>::flow to_const_volatile_rvalue;
			typedef typename Type<typename Type::to_function	     >::flow to_function;
			typedef typename Type<typename Type::to_lvalue		     >::flow to_lvalue;
			typedef typename Type<typename Type::to_lvalue_reference     >::flow to_lvalue_reference;
			typedef typename Type<typename Type::to_opaque		     >::flow to_opaque;
			typedef typename Type<typename Type::to_pointer		     >::flow to_pointer;
			typedef typename Type<typename Type::to_rvalue		     >::flow to_rvalue;
			typedef typename Type<typename Type::to_rvalue_reference     >::flow to_rvalue_reference;
			typedef typename Type<typename Type::to_signed		     >::flow to_signed;
			typedef typename Type<typename Type::to_unqualified	     >::flow to_unqualified;
			typedef typename Type<typename Type::to_unsigned	     >::flow to_unsigned;
			typedef typename Type<typename Type::to_volatile	     >::flow to_volatile;
			typedef typename Type<typename Type::to_volatile_lvalue	     >::flow to_volatile_lvalue;
			typedef typename Type<typename Type::to_volatile_rvalue	     >::flow to_volatile_rvalue;
			typedef typename Type<typename Type::to_wrap		     >::flow to_wrap;

#			if Z_LANGUAGE_HAS(CPP, TEMPLATE_ALIAS)
				template <class klass> using to_member_pointer = typename Type<typename Type::to_member_pointer<klass> >::flow;
#			endif

			typedef typename Type<typename Type::add_const		      >::flow add_const;
			typedef typename Type<typename Type::add_const_lvalue	      >::flow add_const_lvalue;
			typedef typename Type<typename Type::add_const_rvalue	      >::flow add_const_rvalue;
			typedef typename Type<typename Type::add_const_volatile	      >::flow add_const_volatile;
			typedef typename Type<typename Type::add_const_volatile_lvalue>::flow add_const_volatile_lvalue;
			typedef typename Type<typename Type::add_const_volatile_rvalue>::flow add_const_volatile_rvalue;
			typedef typename Type<typename Type::add_lvalue		      >::flow add_lvalue;
			typedef typename Type<typename Type::add_lvalue_reference     >::flow add_lvalue_reference;
			typedef typename Type<typename Type::add_pointer	      >::flow add_pointer;
			typedef typename Type<typename Type::add_rvalue		      >::flow add_rvalue;
			typedef typename Type<typename Type::add_rvalue_reference     >::flow add_rvalue_reference;
			typedef typename Type<typename Type::add_volatile	      >::flow add_volatile;
			typedef typename Type<typename Type::add_volatile_lvalue      >::flow add_volatile_lvalue;
			typedef typename Type<typename Type::add_volatile_rvalue      >::flow add_volatile_rvalue;

			typedef typename Type<typename Type::remove_const	       >::flow remove_const;
			typedef typename Type<typename Type::remove_const_this	       >::flow remove_const_this;
			typedef typename Type<typename Type::remove_const_volatile     >::flow remove_const_volatile;
			typedef typename Type<typename Type::remove_const_volatile_this>::flow remove_const_volatile_this;
			typedef typename Type<typename Type::remove_pointer	       >::flow remove_pointer;
			typedef typename Type<typename Type::remove_reference	       >::flow remove_reference;
			typedef typename Type<typename Type::remove_this	       >::flow remove_this;
			typedef typename Type<typename Type::remove_volatile	       >::flow remove_volatile;
			typedef typename Type<typename Type::remove_volatile_this      >::flow remove_volatile_this;
		};

#		if Z_COMPILER_HAS_MAGIC_CONSTANT(MANGLED_FUNCTION_NAME) && Z_LANGUAGE_HAS(CPP, RELAXED_CONSTANT_EXPRESSION_FUNCTION)

			static Z_CONSTANT_MEMBER(CPP14) Size string_size()
				{return type_string_size<T>();}


			static Z_CONSTANT_MEMBER(CPP14) SizedString<string_size()> string()
				{return type_string<T>();}


			static Z_CONSTANT_MEMBER(CPP14) Symbol symbol()
				{return Symbol(type_string<T>());}

#		endif
	};

	template <class T> struct TypeClassType	     {typedef typename Type<T>::class_type	type;};
	template <class T> struct TypeElementType    {typedef typename Type<T>::element_type	type;};
	template <class T> struct TypePointeeType    {typedef typename Type<T>::pointee_type	type;};
	template <class T> struct TypeReferencedType {typedef typename Type<T>::referenced_type	type;};
	template <class T> struct TypeReturnType     {typedef typename Type<T>::return_type	type;};
	template <class T> struct TypeUnderlyingType {typedef typename Type<T>::underlying_type	type;};

	template <class T> struct TypeParameters {typedef typename Type<T>::parameters type;};

	template <class T> struct TypeToParameter	    {typedef typename Type<T>::to_parameter		type;};
	template <class T> struct TypeToConst		    {typedef typename Type<T>::to_const			type;};
	template <class T> struct TypeToConstLValue	    {typedef typename Type<T>::to_const_lvalue		type;};
	template <class T> struct TypeToConstRValue	    {typedef typename Type<T>::to_const_rvalue		type;};
	template <class T> struct TypeToConstVolatile	    {typedef typename Type<T>::to_const_volatile	type;};
	template <class T> struct TypeToConstVolatileLValue {typedef typename Type<T>::to_const_volatile_lvalue	type;};
	template <class T> struct TypeToConstVolatileRValue {typedef typename Type<T>::to_const_volatile_rvalue	type;};
	template <class T> struct TypeToFunction	    {typedef typename Type<T>::to_function		type;};
	template <class T> struct TypeToLValue		    {typedef typename Type<T>::to_lvalue		type;};
	template <class T> struct TypeToLValueReference	    {typedef typename Type<T>::to_lvalue_reference	type;};
	template <class T> struct TypeToOpaque		    {typedef typename Type<T>::to_opaque		type;};
	template <class T> struct TypeToPointer		    {typedef typename Type<T>::to_pointer		type;};
	template <class T> struct TypeToRValue		    {typedef typename Type<T>::to_rvalue		type;};
	template <class T> struct TypeToRValueReference	    {typedef typename Type<T>::to_rvalue_reference	type;};
	template <class T> struct TypeToSigned		    {typedef typename Type<T>::to_signed		type;};
	template <class T> struct TypeToUnqualified	    {typedef typename Type<T>::to_unqualified		type;};
	template <class T> struct TypeToUnsigned	    {typedef typename Type<T>::to_unsigned		type;};
	template <class T> struct TypeToVolatile	    {typedef typename Type<T>::to_volatile		type;};
	template <class T> struct TypeToVolatileLValue	    {typedef typename Type<T>::to_volatile_lvalue	type;};
	template <class T> struct TypeToVolatileRValue	    {typedef typename Type<T>::to_volatile_rvalue	type;};
	template <class T> struct TypeToWrap		    {typedef typename Type<T>::to_wrap			type;};

	template <class T> struct TypeAddConst		     {typedef typename Type<T>::add_const		  type;};
	template <class T> struct TypeAddConstLValue	     {typedef typename Type<T>::add_const_lvalue	  type;};
	template <class T> struct TypeAddConstRValue	     {typedef typename Type<T>::add_const_rvalue	  type;};
	template <class T> struct TypeAddConstVolatile	     {typedef typename Type<T>::add_const_volatile	  type;};
	template <class T> struct TypeAddConstVolatileLValue {typedef typename Type<T>::add_const_volatile_lvalue type;};
	template <class T> struct TypeAddConstVolatileRValue {typedef typename Type<T>::add_const_volatile_rvalue type;};
	template <class T> struct TypeAddLValue		     {typedef typename Type<T>::add_lvalue		  type;};
	template <class T> struct TypeAddLValueReference     {typedef typename Type<T>::add_lvalue_reference	  type;};
	template <class T> struct TypeAddPointer	     {typedef typename Type<T>::add_pointer		  type;};
	template <class T> struct TypeAddRValue		     {typedef typename Type<T>::add_rvalue		  type;};
	template <class T> struct TypeAddRValueReference     {typedef typename Type<T>::add_rvalue_reference	  type;};
	template <class T> struct TypeAddVolatile	     {typedef typename Type<T>::add_volatile		  type;};
	template <class T> struct TypeAddVolatileLValue	     {typedef typename Type<T>::add_volatile_lvalue	  type;};
	template <class T> struct TypeAddVolatileRValue	     {typedef typename Type<T>::add_volatile_rvalue	  type;};

	template <class T> struct TypeRemoveConst	      {typedef typename Type<T>::remove_const		    type;};
	template <class T> struct TypeRemoveConstThis	      {typedef typename Type<T>::remove_const_this	    type;};
	template <class T> struct TypeRemoveConstVolatile     {typedef typename Type<T>::remove_const_volatile	    type;};
	template <class T> struct TypeRemoveConstVolatileThis {typedef typename Type<T>::remove_const_volatile_this type;};
	template <class T> struct TypeRemovePointer	      {typedef typename Type<T>::remove_pointer		    type;};
	template <class T> struct TypeRemoveReference	      {typedef typename Type<T>::remove_reference	    type;};
	template <class T> struct TypeRemoveThis	      {typedef typename Type<T>::remove_this		    type;};
	template <class T> struct TypeRemoveVolatile	      {typedef typename Type<T>::remove_volatile	    type;};
	template <class T> struct TypeRemoveVolatileThis      {typedef typename Type<T>::remove_volatile_this	    type;};

#	if Z_LANGUAGE_HAS(CPP, TEMPLATE_ALIAS)

		template <class T> using type_class_type      = typename Type<T>::class_type;
		template <class T> using type_element_type    = typename Type<T>::element_type;
		template <class T> using type_pointee_type    = typename Type<T>::pointee_type;
		template <class T> using type_referenced_type = typename Type<T>::referenced_type;
		template <class T> using type_return_type     = typename Type<T>::return_type;
		template <class T> using type_underlying_type = typename Type<T>::underlying_type;

		template <class T> using type_parameters = typename Type<T>::parameters;

		template <class T> using type_to_parameter	       = typename Type<T>::to_parameter;
		template <class T> using type_to_const		       = typename Type<T>::to_const;
		template <class T> using type_to_const_lvalue	       = typename Type<T>::to_const_lvalue;
		template <class T> using type_to_const_rvalue	       = typename Type<T>::to_const_rvalue;
		template <class T> using type_to_const_volatile	       = typename Type<T>::to_const_volatile;
		template <class T> using type_to_const_volatile_lvalue = typename Type<T>::to_const_volatile_lvalue;
		template <class T> using type_to_const_volatile_rvalue = typename Type<T>::to_const_volatile_rvalue;
		template <class T> using type_to_function	       = typename Type<T>::to_function;
		template <class T> using type_to_lvalue		       = typename Type<T>::to_lvalue;
		template <class T> using type_to_lvalue_reference      = typename Type<T>::to_lvalue_reference;
		template <class T> using type_to_opaque		       = typename Type<T>::to_opaque;
		template <class T> using type_to_pointer	       = typename Type<T>::to_pointer;
		template <class T> using type_to_rvalue		       = typename Type<T>::to_rvalue;
		template <class T> using type_to_rvalue_reference      = typename Type<T>::to_rvalue_reference;
		template <class T> using type_to_signed		       = typename Type<T>::to_signed;
		template <class T> using type_to_unqualified	       = typename Type<T>::to_unqualified;
		template <class T> using type_to_unsigned	       = typename Type<T>::to_unsigned;
		template <class T> using type_to_volatile	       = typename Type<T>::to_volatile;
		template <class T> using type_to_volatile_lvalue       = typename Type<T>::to_volatile_lvalue;
		template <class T> using type_to_volatile_rvalue       = typename Type<T>::to_volatile_rvalue;
		template <class T> using type_to_wrap		       = typename Type<T>::to_wrap;

		template <class T, class klass> using type_to_member_pointer = typename TypeToMemberPointer<T, klass>::type;

		template <class T> using type_add_const			= typename Type<T>::add_const;
		template <class T> using type_add_const_lvalue		= typename Type<T>::add_const_lvalue;
		template <class T> using type_add_const_rvalue		= typename Type<T>::add_const_rvalue;
		template <class T> using type_add_const_volatile	= typename Type<T>::add_const_volatile;
		template <class T> using type_add_const_volatile_lvalue	= typename Type<T>::add_const_volatile_lvalue;
		template <class T> using type_add_const_volatile_rvalue	= typename Type<T>::add_const_volatile_rvalue;
		template <class T> using type_add_lvalue		= typename Type<T>::add_lvalue;
		template <class T> using type_add_lvalue_reference	= typename Type<T>::add_lvalue_reference;
		template <class T> using type_add_pointer		= typename Type<T>::add_pointer;
		template <class T> using type_add_rvalue		= typename Type<T>::add_rvalue;
		template <class T> using type_add_rvalue_reference	= typename Type<T>::add_rvalue_reference;
		template <class T> using type_add_volatile		= typename Type<T>::add_volatile;
		template <class T> using type_add_volatile_lvalue	= typename Type<T>::add_volatile_lvalue;
		template <class T> using type_add_volatile_rvalue	= typename Type<T>::add_volatile_rvalue;

		template <class T> using type_remove_const		 = typename Type<T>::remove_const;
		template <class T> using type_remove_const_this		 = typename Type<T>::remove_const_this;
		template <class T> using type_remove_const_volatile	 = typename Type<T>::remove_const_volatile;
		template <class T> using type_remove_const_volatile_this = typename Type<T>::remove_const_volatile_this;
		template <class T> using type_remove_pointer		 = typename Type<T>::remove_pointer;
		template <class T> using type_remove_reference		 = typename Type<T>::remove_reference;
		template <class T> using type_remove_this		 = typename Type<T>::remove_this;
		template <class T> using type_remove_volatile		 = typename Type<T>::remove_volatile;
		template <class T> using type_remove_volatile_this	 = typename Type<T>::remove_volatile_this;

#	endif
}

#endif // __Z_traits_Type_HPP__
