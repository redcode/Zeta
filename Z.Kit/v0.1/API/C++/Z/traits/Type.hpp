/* Z Kit C++ API - traits/Type.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_traits_Type_HPP__
#define __Z_traits_Type_HPP__

#include <Z/keys/mathematics/number.h>
#include <Z/inspection/Z.h>
#include <Z/traits/TypeList.hpp>

#if Z_LANGUAGE_HAS(CPP, RELAXED_CONSTANT_EXPRESSION_FUNCTION)
#	include <Z/functions/base/type.hpp>
#	include <Z/classes/base/Symbol.hpp>
#endif

// MARK: - Abstract

namespace Zeta {namespace Detail {namespace Type {namespace Abstract {

	struct Invalid {
		enum {	is_arithmetic		     = false,
			is_array		     = false,
			is_callable		     = false,
			is_char			     = false,
			is_class		     = false,
			is_compound		     = false,
			is_const		     = false,
			is_const_volatile	     = false,
			is_data_member_pointer	     = false,
			is_empty		     = false,
			is_exact		     = false,
			is_integer		     = false,
			is_flexible_array	     = false,
			is_function		     = false,
			is_function_lvalue_reference = false,
			is_function_pointer	     = false,
			is_function_reference	     = false,
			is_fundamental		     = false,
			is_lvalue_reference	     = false,
			is_member_function_pointer   = false,
			is_member_pointer	     = false,
			is_nat			     = true,
			is_natural		     = false,
			is_number		     = false,
			is_pointer		     = false,
			is_qualified		     = false,
			is_real			     = false,
			is_reference		     = false,
			is_scalar		     = false,
			is_schar		     = false,
			is_signed		     = false,
			is_sint			     = false,
			is_slong		     = false,
			is_sshort		     = false,
			is_storable		     = false,
			is_structure		     = false,
			is_uchar		     = false,
			is_uint			     = false,
			is_ulong		     = false,
			is_ushort		     = false,
			is_valid		     = false,
			is_value		     = false,
			is_variadic		     = false,
			is_variadic_function	     = false,
			is_void			     = false,
			is_void_pointer		     = false,
			is_volatile		     = false
		};

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
		typedef NaT referencee_type;
		typedef NaT return_type;

		typedef NaT to_const;
		typedef NaT to_const_volatile;
		typedef NaT to_forwardable;
		typedef NaT to_function;
		typedef NaT to_lvalue_reference;
		typedef NaT to_opaque;
		typedef NaT to_pointer;
		typedef NaT to_signed;
		typedef NaT to_unqualified;
		typedef NaT to_unsigned;
		typedef NaT to_volatile;
		typedef NaT to_wrap;
		typedef NaT add_const;
		typedef NaT add_const_volatile;
		typedef NaT add_lvalue_reference;
		typedef NaT add_pointer;
		typedef NaT add_volatile;
		typedef NaT remove_const;
		typedef NaT remove_const_volatile;
		typedef NaT remove_pointer;
		typedef NaT remove_reference;
		typedef NaT remove_volatile;

#		if Z_COMPILER_HAS_TRAIT(TYPE_IS_ABSTRACT)
			enum {is_abstract = false};
#			define Z_HAS_TYPE_IS_ABSTRACT TRUE
#		else
#			define Z_HAS_TYPE_IS_ABSTRACT FALSE
#		endif

#		if Z_COMPILER_HAS_TRAIT(TYPE_IS_AGGREGATE)
			enum {is_aggregate = false};
#			define Z_HAS_TYPE_IS_AGGREGATE TRUE
#		else
#			define Z_HAS_TYPE_IS_AGGREGATE FALSE
#		endif

#		if Z_LANGUAGE_HAS_TYPE(CPP, BOOLEAN)
			enum {is_boolean = false};
#			define Z_HAS_TYPE_IS_BOOLEAN TRUE
#		else
#			define Z_HAS_TYPE_IS_BOOLEAN FALSE
#		endif

#		ifdef Z_DOUBLE
			enum {is_double = false};
#			define Z_HAS_TYPE_IS_DOUBLE TRUE
#		else
#			define Z_HAS_TYPE_IS_DOUBLE FALSE
#		endif

#		if Z_COMPILER_HAS_TRAIT(TYPE_IS_ENUMERATION)
			enum {is_enumeration = false};
#			define Z_HAS_TYPE_IS_ENUMERATION TRUE
#		else
#			define Z_HAS_TYPE_IS_ENUMERATION FALSE
#		endif

#		if Z_COMPILER_HAS_TRAIT(TYPE_IS_FINAL)
			enum {is_final = false};
#			define Z_HAS_TYPE_IS_FINAL TRUE
#		else
#			define Z_HAS_TYPE_IS_FINAL FALSE
#		endif

#		ifdef Z_FLOAT
			enum {is_float = false};
#			define Z_HAS_TYPE_IS_FLOAT TRUE
#		else
#			define Z_HAS_TYPE_IS_FLOAT FALSE
#		endif

#		if defined(Z_FLOAT16) && Z_FLOAT16_VALUE_TYPE == Z_VALUE_TYPE_FLOAT16
			enum {is_float16 = false};
#			define Z_HAS_TYPE_IS_FLOAT16 TRUE
#		else
#			define Z_HAS_TYPE_IS_FLOAT16 FALSE
#		endif

#		if defined(Z_FLOAT32) && Z_FLOAT32_VALUE_TYPE == Z_VALUE_TYPE_FLOAT32
			enum {is_float32 = false};
#			define Z_HAS_TYPE_IS_FLOAT32 TRUE
#		else
#			define Z_HAS_TYPE_IS_FLOAT32 FALSE
#		endif

#		if defined(Z_FLOAT64) && Z_FLOAT64_VALUE_TYPE == Z_VALUE_TYPE_FLOAT64
			enum {is_float64 = false};
#			define Z_HAS_TYPE_IS_FLOAT64 TRUE
#		else
#			define Z_HAS_TYPE_IS_FLOAT64 FALSE
#		endif

#		if defined(Z_FLOAT128) && Z_FLOAT128_VALUE_TYPE == Z_VALUE_TYPE_FLOAT128
			enum {is_float128 = false};
#			define Z_HAS_TYPE_IS_FLOAT128 TRUE
#		else
#			define Z_HAS_TYPE_IS_FLOAT128 FALSE
#		endif

#		if defined(Z_FLOAT80_X87) && Z_FLOAT80_X87_VALUE_TYPE == Z_VALUE_TYPE_FLOAT80_X87
			enum {is_float80_x87 = false};
#			define Z_HAS_TYPE_IS_FLOAT80_X87 TRUE
#		else
#			define Z_HAS_TYPE_IS_FLOAT80_X87 FALSE
#		endif

#		if defined(Z_FLOAT96_X87) && Z_FLOAT96_X87_VALUE_TYPE == Z_VALUE_TYPE_FLOAT96_X87
			enum {is_float96_x87 = false};
#			define Z_HAS_TYPE_IS_FLOAT96_X87 TRUE
#		else
#			define Z_HAS_TYPE_IS_FLOAT96_X87 FALSE
#		endif

#		if defined(Z_FLOAT128_X87) && Z_FLOAT128_X87_VALUE_TYPE == Z_VALUE_TYPE_FLOAT128_X87
			enum {is_float128_x87 = false};
#			define Z_HAS_TYPE_IS_FLOAT128_X87 TRUE
#		else
#			define Z_HAS_TYPE_IS_FLOAT128_X87 FALSE
#		endif

#		if Z_COMPILER_HAS_TRAIT(TYPE_IS_INTERFACE_CLASS)
			enum {is_interface_class = false};
#			define Z_HAS_TYPE_IS_INTERFACE_CLASS TRUE
#		else
#			define Z_HAS_TYPE_IS_INTERFACE_CLASS FALSE
#		endif

#		ifdef Z_LDOUBLE
			enum {is_ldouble = false};
#			define Z_HAS_TYPE_IS_LDOUBLE TRUE
#		else
#			define Z_HAS_TYPE_IS_LDOUBLE FALSE
#		endif

#		if Z_COMPILER_HAS_TRAIT(TYPE_IS_LITERAL)
			enum {is_literal = false};
#			define Z_HAS_TYPE_IS_LITERAL TRUE
#		else
#			define Z_HAS_TYPE_IS_LITERAL FALSE
#		endif

#		if Z_LANGUAGE_HAS_SPECIFIER(CPP, DECLARED_TYPE) && Z_LANGUAGE_HAS_LITERAL(CPP, NULL_POINTER)
			enum {is_null_pointer = false};
#			define Z_HAS_TYPE_IS_NULL_POINTER TRUE
#		else
#			define Z_HAS_TYPE_IS_NULL_POINTER FALSE
#		endif

#		if Z_COMPILER_HAS_TRAIT(TYPE_IS_POD)
			enum {is_pod = false};
#			define Z_HAS_TYPE_IS_POD TRUE
#		else
#			define Z_HAS_TYPE_IS_POD FALSE
#		endif

#		if Z_COMPILER_HAS_TRAIT(TYPE_IS_POLYMORPHIC)
			enum {is_polymorphic = false};
#			define Z_HAS_TYPE_IS_POLYMORPHIC TRUE
#		else
#			define Z_HAS_TYPE_IS_POLYMORPHIC FALSE
#		endif

#		if Z_SINT8_VALUE_TYPE == Z_VALUE_TYPE_SINT8
			enum {is_sint8 = false};
#			define Z_HAS_TYPE_IS_SINT8 TRUE
#		else
#			define Z_HAS_TYPE_IS_SINT8 FALSE
#		endif

#		if Z_SINT16_VALUE_TYPE == Z_VALUE_TYPE_SINT16
			enum {is_sint16 = false};
#			define Z_HAS_TYPE_IS_SINT16 TRUE
#		else
#			define Z_HAS_TYPE_IS_SINT16 FALSE
#		endif

#		if defined(Z_SINT32) && Z_SINT32_VALUE_TYPE == Z_VALUE_TYPE_SINT32
			enum {is_sint32 = false};
#			define Z_HAS_TYPE_IS_SINT32 TRUE
#		else
#			define Z_HAS_TYPE_IS_SINT32 FALSE
#		endif

#		if defined(Z_SINT64) && Z_SINT64_VALUE_TYPE == Z_VALUE_TYPE_SINT64
			enum {is_sint64 = false};
#			define Z_HAS_TYPE_IS_SINT64 TRUE
#		else
#			define Z_HAS_TYPE_IS_SINT64 FALSE
#		endif

#		if defined(Z_SINT128) && Z_SINT128_VALUE_TYPE == Z_VALUE_TYPE_SINT128
			enum {is_sint128 = false};
#			define Z_HAS_TYPE_IS_SINT128 TRUE
#		else
#			define Z_HAS_TYPE_IS_SINT128 FALSE
#		endif

#		ifdef Z_SLLONG
			enum {is_sllong = false};
#			define Z_HAS_TYPE_IS_SLLONG TRUE
#		else
#			define Z_HAS_TYPE_IS_SLLONG FALSE
#		endif

#		if Z_LANGUAGE_HAS(CPP, VARIADIC_TEMPLATE_EXTENDED_PARAMETERS)
			enum {is_template = false};
#			define Z_HAS_TYPE_IS_TEMPLATE TRUE
#		else
#			define Z_HAS_TYPE_IS_TEMPLATE FALSE
#		endif

#		if Z_UINT8_VALUE_TYPE == Z_VALUE_TYPE_UINT8
			enum {is_uint8 = false};
#			define Z_HAS_TYPE_IS_UINT8 TRUE
#		else
#			define Z_HAS_TYPE_IS_UINT8 FALSE
#		endif

#		if Z_UINT16_VALUE_TYPE == Z_VALUE_TYPE_UINT16
			enum {is_uint16 = false};
#			define Z_HAS_TYPE_IS_UINT16 TRUE
#		else
#			define Z_HAS_TYPE_IS_UINT16 FALSE
#		endif

#		if defined(Z_UINT32) && Z_UINT32_VALUE_TYPE == Z_VALUE_TYPE_UINT32
			enum {is_uint32 = false};
#			define Z_HAS_TYPE_IS_UINT32 TRUE
#		else
#			define Z_HAS_TYPE_IS_UINT32 FALSE
#		endif

#		if defined(Z_UINT64) && Z_UINT64_VALUE_TYPE == Z_VALUE_TYPE_UINT64
			enum {is_uint64 = false};
#			define Z_HAS_TYPE_IS_UINT64 TRUE
#		else
#			define Z_HAS_TYPE_IS_UINT64 FALSE
#		endif

#		if defined(Z_UINT128) && Z_UINT128_VALUE_TYPE == Z_VALUE_TYPE_UINT128
			enum {is_uint128 = false};
#			define Z_HAS_TYPE_IS_UINT128 TRUE
#		else
#			define Z_HAS_TYPE_IS_UINT128 FALSE
#		endif

#		ifdef Z_ULLONG
			enum {is_ullong = false};
#			define Z_HAS_TYPE_IS_ULLONG TRUE
#		else
#			define Z_HAS_TYPE_IS_ULLONG FALSE
#		endif

#		if Z_COMPILER_HAS_TRAIT(TYPE_IS_UNION)
			enum {is_union = false};
#			define Z_HAS_TYPE_IS_UNION TRUE
#		else
#			define Z_HAS_TYPE_IS_UNION FALSE
#		endif

#		if Z_LANGUAGE_HAS(CPP, VARIADIC_TEMPLATE)

#			if Z_LANGUAGE_HAS(CPP, RVALUE_REFERENCE)
				enum {is_function_rvalue_reference = false};
#				define Z_HAS_TYPE_IS_FUNCTION_RVALUE_REFERENCE TRUE
#			else
#				define Z_HAS_TYPE_IS_FUNCTION_RVALUE_REFERENCE FALSE
#			endif

#			if Z_LANGUAGE_HAS(CPP, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)

				enum {	is_const_lvalue		 = false,
					is_const_rvalue		 = false,
					is_const_volatile_lvalue = false,
					is_const_volatile_rvalue = false,
					is_lvalue		 = false,
					is_rvalue		 = false,
					is_volatile_lvalue	 = false,
					is_volatile_rvalue	 = false
				};

				typedef NaT to_const_lvalue;
				typedef NaT to_const_rvalue;
				typedef NaT to_const_volatile_lvalue;
				typedef NaT to_const_volatile_rvalue;
				typedef NaT to_lvalue;
				typedef NaT to_rvalue;
				typedef NaT to_volatile_lvalue;
				typedef NaT to_volatile_rvalue;
				typedef NaT add_const_lvalue;
				typedef NaT add_const_rvalue;
				typedef NaT add_const_volatile_lvalue;
				typedef NaT add_const_volatile_rvalue;
				typedef NaT add_lvalue;
				typedef NaT add_rvalue;
				typedef NaT add_volatile_lvalue;
				typedef NaT add_volatile_rvalue;
				typedef NaT remove_const_this;
				typedef NaT remove_const_volatile_this;
				typedef NaT remove_this;
				typedef NaT remove_volatile_this;

#				define Z_HAS_TYPE_IS_CONST_LVALUE	     TRUE
#				define Z_HAS_TYPE_IS_CONST_RVALUE	     TRUE
#				define Z_HAS_TYPE_IS_CONST_VOLATILE_LVALUE   TRUE
#				define Z_HAS_TYPE_IS_CONST_VOLATILE_RVALUE   TRUE
#				define Z_HAS_TYPE_IS_LVALUE		     TRUE
#				define Z_HAS_TYPE_IS_RVALUE		     TRUE
#				define Z_HAS_TYPE_IS_VOLATILE_LVALUE	     TRUE
#				define Z_HAS_TYPE_IS_VOLATILE_RVALUE	     TRUE
#				define Z_HAS_TYPE_TO_CONST_LVALUE	     TRUE
#				define Z_HAS_TYPE_TO_CONST_RVALUE	     TRUE
#				define Z_HAS_TYPE_TO_CONST_VOLATILE_LVALUE   TRUE
#				define Z_HAS_TYPE_TO_CONST_VOLATILE_RVALUE   TRUE
#				define Z_HAS_TYPE_TO_LVALUE		     TRUE
#				define Z_HAS_TYPE_TO_RVALUE		     TRUE
#				define Z_HAS_TYPE_TO_VOLATILE_LVALUE	     TRUE
#				define Z_HAS_TYPE_TO_VOLATILE_RVALUE	     TRUE
#				define Z_HAS_TYPE_ADD_CONST_LVALUE	     TRUE
#				define Z_HAS_TYPE_ADD_CONST_RVALUE	     TRUE
#				define Z_HAS_TYPE_ADD_CONST_VOLATILE_LVALUE  TRUE
#				define Z_HAS_TYPE_ADD_CONST_VOLATILE_RVALUE  TRUE
#				define Z_HAS_TYPE_ADD_LVALUE		     TRUE
#				define Z_HAS_TYPE_ADD_RVALUE		     TRUE
#				define Z_HAS_TYPE_ADD_VOLATILE_LVALUE	     TRUE
#				define Z_HAS_TYPE_ADD_VOLATILE_RVALUE	     TRUE
#				define Z_HAS_TYPE_REMOVE_CONST_THIS	     TRUE
#				define Z_HAS_TYPE_REMOVE_CONST_VOLATILE_THIS TRUE
#				define Z_HAS_TYPE_REMOVE_THIS		     TRUE
#				define Z_HAS_TYPE_REMOVE_VOLATILE_THIS	     TRUE
#			else
#				define Z_HAS_TYPE_IS_CONST_LVALUE	     FALSE
#				define Z_HAS_TYPE_IS_CONST_RVALUE	     FALSE
#				define Z_HAS_TYPE_IS_CONST_VOLATILE_LVALUE   FALSE
#				define Z_HAS_TYPE_IS_CONST_VOLATILE_RVALUE   FALSE
#				define Z_HAS_TYPE_IS_LVALUE		     FALSE
#				define Z_HAS_TYPE_IS_RVALUE		     FALSE
#				define Z_HAS_TYPE_IS_VOLATILE_LVALUE	     FALSE
#				define Z_HAS_TYPE_IS_VOLATILE_RVALUE	     FALSE
#				define Z_HAS_TYPE_TO_CONST_LVALUE	     FALSE
#				define Z_HAS_TYPE_TO_CONST_RVALUE	     FALSE
#				define Z_HAS_TYPE_TO_CONST_VOLATILE_LVALUE   FALSE
#				define Z_HAS_TYPE_TO_CONST_VOLATILE_RVALUE   FALSE
#				define Z_HAS_TYPE_TO_LVALUE		     FALSE
#				define Z_HAS_TYPE_TO_RVALUE		     FALSE
#				define Z_HAS_TYPE_TO_VOLATILE_LVALUE	     FALSE
#				define Z_HAS_TYPE_TO_VOLATILE_RVALUE	     FALSE
#				define Z_HAS_TYPE_ADD_CONST_LVALUE	     FALSE
#				define Z_HAS_TYPE_ADD_CONST_RVALUE	     FALSE
#				define Z_HAS_TYPE_ADD_CONST_VOLATILE_LVALUE  FALSE
#				define Z_HAS_TYPE_ADD_CONST_VOLATILE_RVALUE  FALSE
#				define Z_HAS_TYPE_ADD_LVALUE		     FALSE
#				define Z_HAS_TYPE_ADD_RVALUE		     FALSE
#				define Z_HAS_TYPE_ADD_VOLATILE_LVALUE	     FALSE
#				define Z_HAS_TYPE_ADD_VOLATILE_RVALUE	     FALSE
#				define Z_HAS_TYPE_REMOVE_CONST_THIS	     FALSE
#				define Z_HAS_TYPE_REMOVE_CONST_VOLATILE_THIS FALSE
#				define Z_HAS_TYPE_REMOVE_THIS		     FALSE
#				define Z_HAS_TYPE_REMOVE_VOLATILE_THIS	     FALSE
#			endif

#		endif

#		if Z_LANGUAGE_HAS(CPP, RVALUE_REFERENCE)

			enum {is_rvalue_reference = false};

			typedef NaT to_rvalue_reference;
			typedef NaT add_rvalue_reference;

#			define Z_HAS_TYPE_IS_RVALUE_REFERENCE	       TRUE
#			define Z_HAS_TYPE_TO_RVALUE_REFERENCE	       TRUE
#			define Z_HAS_TYPE_ADD_RVALUE_REFERENCE	       TRUE
#		else
#			define Z_HAS_TYPE_IS_RVALUE_REFERENCE	       FALSE
#			define Z_HAS_TYPE_TO_RVALUE_REFERENCE	       FALSE
#			define Z_HAS_TYPE_ADD_RVALUE_REFERENCE	       FALSE
#		endif

#		if Z_COMPILER_HAS_TRAIT(TYPE_UNDERLYING_TYPE)
			typedef NaT underlying_type;
#			define Z_HAS_TYPE_UNDERLYING_TYPE TRUE
#		else
#			define Z_HAS_TYPE_UNDERLYING_TYPE FALSE
#		endif

#		if Z_HAS_TRAIT(TYPE_LIST)
			typedef NaT parameters;
#			define Z_HAS_TYPE_PARAMETERS TRUE
#		else
#			define Z_HAS_TYPE_PARAMETERS FALSE
#		endif
	};

	struct Valid : Invalid {
		enum {	is_nat	 = false,
			is_valid = true
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

#		if Z_HAS(TYPE_IS_LITERAL)
			enum {is_literal = true};
#		endif

#		if Z_HAS(TYPE_IS_POD)
			enum {is_pod = true};
#		endif
	};

	struct Exact : Number {
		enum {is_exact = true};
	};

	struct Natural : Exact {
		enum {is_natural = true};
		enum {number_set = Z_NUMBER_SET_N};
		enum {minimum = 0};
	};

	struct Integer : Exact {
		enum {	is_integer = true,
			is_signed  = true
		};
		enum {number_set = Z_NUMBER_SET_Z};
	};

	struct Real : Number {
		enum {	is_real   = true,
			is_signed = true
		};
		enum {number_set = Z_NUMBER_SET_R};
	};

	struct Void : Valid {
		enum {	is_fundamental = true,
			is_void	       = true
		};

#		if Z_HAS(TYPE_IS_LITERAL)
			enum {is_literal = true};
#		endif

		typedef void type;
	};

#	if Z_HAS(TYPE_IS_UINT8)

		struct UInt8 : Natural {
			enum {is_uint8 = true};

			enum {	value_type	 = Z_UINT8_VALUE_TYPE,
				fixed_value_type = Z_UINT8_FIXED_VALUE_TYPE,
				value_format	 = Z_UINT8_VALUE_FORMAT
			};
			enum {maximum = Z_UINT8_MAXIMUM};

			typedef zuint8 type;
			typedef zuint8 to_unsigned;
			typedef zsint8 to_signed;
		};

#	endif

#	if Z_HAS(TYPE_IS_UINT16)

		struct UInt16 : Natural {
			enum {is_uint16 = true};

			enum {	value_type	 = Z_UINT16_VALUE_TYPE,
				fixed_value_type = Z_UINT16_FIXED_VALUE_TYPE,
				value_format	 = Z_UINT16_VALUE_FORMAT
			};
			enum {maximum = Z_UINT16_MAXIMUM};

			typedef zuint16 type;
			typedef zuint16 to_unsigned;
			typedef zsint16 to_signed;
		};

#	endif

#	if Z_HAS(TYPE_IS_UINT32)

		struct UInt32 : Natural {
			enum {is_uint32 = true};

			enum {	value_type	 = Z_UINT32_VALUE_TYPE,
				fixed_value_type = Z_UINT32_FIXED_VALUE_TYPE,
				value_format	 = Z_UINT32_VALUE_FORMAT
			};
			enum {maximum = Z_UINT32_MAXIMUM};

			typedef zuint32 type;
			typedef zuint32 to_unsigned;
			typedef zsint32 to_signed;
		};

#	endif

#	if Z_HAS(TYPE_IS_UINT64)

		struct UInt64 : Natural {
			enum {is_uint64 = true};

			enum {	value_type	 = Z_UINT64_VALUE_TYPE,
				fixed_value_type = Z_UINT64_FIXED_VALUE_TYPE,
				value_format	 = Z_UINT64_VALUE_FORMAT
			};
			enum {maximum = Z_UINT64_MAXIMUM};

			typedef zuint64 type;
			typedef zuint64 to_unsigned;

#			ifdef Z_SINT64
				typedef zsint64 to_signed;
#			endif
		};

#	endif

#	if Z_HAS(TYPE_IS_UINT128)

		struct UInt128 : Natural {
			enum {is_uint128 = true};

			enum {	value_type	 = Z_UINT128_VALUE_TYPE,
				fixed_value_type = Z_UINT128_FIXED_VALUE_TYPE,
				value_format	 = Z_UINT128_VALUE_FORMAT
			};
			enum {maximum = Z_UINT128_MAXIMUM};

			typedef zuint128 type;
			typedef zuint128 to_unsigned;

#			ifdef Z_SINT128
				typedef zsint128 to_signed;
#			endif
		};

#	endif

#	if Z_HAS(TYPE_IS_SINT8)

		struct SInt8 : Integer {
			enum {is_sint8 = true};

			enum {	value_type	 = Z_SINT8_VALUE_TYPE,
				fixed_value_type = Z_SINT8_FIXED_VALUE_TYPE,
				value_format	 = Z_SINT8_VALUE_FORMAT
			};
			enum {	minimum = Z_SINT8_MINIMUM,
				maximum = Z_SINT8_MAXIMUM
			};

			typedef zsint8 type;
			typedef zuint8 to_unsigned;
			typedef zsint8 to_signed;
		};

#	endif

#	if Z_HAS(TYPE_IS_SINT16)

		struct SInt16 : Integer {
			enum {is_sint16 = true};

			enum {	value_type	 = Z_SINT16_VALUE_TYPE,
				fixed_value_type = Z_SINT16_FIXED_VALUE_TYPE,
				value_format	 = Z_SINT16_VALUE_FORMAT
			};
			enum {	minimum = Z_SINT16_MINIMUM,
				maximum = Z_SINT16_MAXIMUM
			};

			typedef zsint16 type;
			typedef zuint16 to_unsigned;
			typedef zsint16 to_signed;
		};

#	endif

#	if Z_HAS(TYPE_IS_SINT32)

		struct SInt32 : Integer {
			enum {is_sint32 = true};

			enum {	value_type	 = Z_SINT16_VALUE_TYPE,
				fixed_value_type = Z_SINT16_FIXED_VALUE_TYPE,
				value_format	 = Z_SINT16_VALUE_FORMAT
			};
			enum {	minimum = Z_SINT32_MINIMUM,
				maximum = Z_SINT32_MAXIMUM
			};

			typedef zsint32 type;
			typedef zuint32 to_unsigned;
			typedef zsint32 to_signed;
		};

#	endif

#	if Z_HAS(TYPE_IS_SINT64)

		struct SInt64 : Integer {
			enum {is_sint64 = true};

			enum {	value_type	 = Z_SINT64_VALUE_TYPE,
				fixed_value_type = Z_SINT64_FIXED_VALUE_TYPE,
				value_format	 = Z_SINT64_VALUE_FORMAT
			};
			enum {	minimum = Z_SINT64_MINIMUM,
				maximum = Z_SINT64_MAXIMUM
			};

			typedef zsint64 type;
			typedef zsint64 to_signed;

#			ifdef Z_UINT64
				typedef zuint64 to_unsigned;
#			endif
		};

#	endif

#	if Z_HAS(TYPE_IS_SINT128)

		struct SInt128 : Integer {
			enum {is_sint128 = true};

			enum {	value_type	 = Z_SINT128_VALUE_TYPE,
				fixed_value_type = Z_SINT128_FIXED_VALUE_TYPE,
				value_format	 = Z_SINT128_VALUE_FORMAT
			};
			enum {	minimum = Z_SINT128_MINIMUM,
				maximum = Z_SINT128_MAXIMUM
			};

			typedef zsint128 type;
			typedef zsint128 to_signed;

#			ifdef Z_UINT128
				typedef zuint128 to_unsigned;
#			endif
		};

#	endif

#	if Z_HAS(TYPE_IS_FLOAT16)

		struct Float16 : Real {
			enum {is_float16 = true};

			enum {	value_type	 = Z_FLOAT16_VALUE_TYPE,
				fixed_value_type = Z_FLOAT16_FIXED_VALUE_TYPE,
				value_format	 = Z_FLOAT16_VALUE_FORMAT
			};
			enum {	bias		   = Z_FLOAT16_BIAS,
				decimal_digits	   = Z_FLOAT16_DECIMAL_DIGITS,
				significand_offset = Z_FLOAT16_SIGNIFICAND_OFFSET,
				significand_bits   = Z_FLOAT16_SIGNIFICAND_BITS,
				significand_digits = Z_FLOAT16_SIGNIFICAND_DIGITS,
				exponent_offset	   = Z_FLOAT16_EXPONENT_OFFSET,
				exponent_bits	   = Z_FLOAT16_EXPONENT_BITS,
				exponent_radix	   = Z_FLOAT16_EXPONENT_RADIX,
				sign_offset	   = Z_FLOAT16_SIGN_OFFSET,
				sign_bits	   = Z_FLOAT16_SIGN_BITS
			};
			enum {	exponent_minimum    = Z_FLOAT16_EXPONENT_MINIMUM,
				exponent_maximum    = Z_FLOAT16_EXPONENT_MAXIMUM,
				exponent_10_minimum = Z_FLOAT16_EXPONENT_10_MINIMUM,
				exponent_10_maximum = Z_FLOAT16_EXPONENT_10_MAXIMUM
			};

			static Z_CT_MEMBER(CPP11) zfloat16 epsilon () {return Z_FLOAT16_EPSILON;}
			static Z_CT_MEMBER(CPP11) zfloat16 minimum () {return Z_FLOAT16_MINIMUM;}
			static Z_CT_MEMBER(CPP11) zfloat16 maximum () {return Z_FLOAT16_MAXIMUM;}
		/*	static Z_CT_MEMBER(CPP11) zfloat16 infinity() Z_NO_EXCEPTION {return Z_FLOAT16_INFINITY;}
			static Z_CT_MEMBER(CPP11) zfloat16 nan	   () Z_NO_EXCEPTION {return Z_FLOAT16_NAN;}*/

			typedef zfloat16 type;
			typedef zfloat16 to_signed;
		};

#	endif

#	if Z_HAS(TYPE_IS_FLOAT32)

		struct Float32 : Real {
			enum {is_float32 = true};

			enum {	value_type	 = Z_FLOAT32_VALUE_TYPE,
				fixed_value_type = Z_FLOAT32_FIXED_VALUE_TYPE,
				value_format	 = Z_FLOAT32_VALUE_FORMAT
			};
			enum {	bias		   = Z_FLOAT32_BIAS,
				decimal_digits	   = Z_FLOAT32_DECIMAL_DIGITS,
				significand_offset = Z_FLOAT32_SIGNIFICAND_OFFSET,
				significand_bits   = Z_FLOAT32_SIGNIFICAND_BITS,
				significand_digits = Z_FLOAT32_SIGNIFICAND_DIGITS,
				exponent_offset	   = Z_FLOAT32_EXPONENT_OFFSET,
				exponent_bits	   = Z_FLOAT32_EXPONENT_BITS,
				exponent_radix	   = Z_FLOAT32_EXPONENT_RADIX,
				sign_offset	   = Z_FLOAT32_SIGN_OFFSET,
				sign_bits	   = Z_FLOAT32_SIGN_BITS
			};
			enum {	exponent_minimum    = Z_FLOAT32_EXPONENT_MINIMUM,
				exponent_maximum    = Z_FLOAT32_EXPONENT_MAXIMUM,
				exponent_10_minimum = Z_FLOAT32_EXPONENT_10_MINIMUM,
				exponent_10_maximum = Z_FLOAT32_EXPONENT_10_MAXIMUM
			};

			static Z_CT_MEMBER(CPP11) zfloat32 epsilon () {return Z_FLOAT32_EPSILON;}
			static Z_CT_MEMBER(CPP11) zfloat32 minimum () {return Z_FLOAT32_MINIMUM;}
			static Z_CT_MEMBER(CPP11) zfloat32 maximum () {return Z_FLOAT32_MAXIMUM;}
		/*	static Z_CT_MEMBER(CPP11) zfloat32 infinity() Z_NO_EXCEPTION {return Z_FLOAT32_INFINITY;}
			static Z_CT_MEMBER(CPP11) zfloat32 nan	   () Z_NO_EXCEPTION {return Z_FLOAT32_NAN;}*/

			typedef zfloat32 type;
			typedef zfloat32 to_signed;
		};

#	endif

#	if Z_HAS(TYPE_IS_FLOAT64)

		struct Float64 : Real {
			enum {is_float64 = true};

			enum {	value_type	 = Z_FLOAT64_VALUE_TYPE,
				fixed_value_type = Z_FLOAT64_FIXED_VALUE_TYPE,
				value_format	 = Z_FLOAT64_VALUE_FORMAT
			};
			enum {	bias		   = Z_FLOAT64_BIAS,
				decimal_digits	   = Z_FLOAT64_DECIMAL_DIGITS,
				significand_offset = Z_FLOAT64_SIGNIFICAND_OFFSET,
				significand_bits   = Z_FLOAT64_SIGNIFICAND_BITS,
				significand_digits = Z_FLOAT64_SIGNIFICAND_DIGITS,
				exponent_offset	   = Z_FLOAT64_EXPONENT_OFFSET,
				exponent_bits	   = Z_FLOAT64_EXPONENT_BITS,
				exponent_radix	   = Z_FLOAT64_EXPONENT_RADIX,
				sign_offset	   = Z_FLOAT64_SIGN_OFFSET,
				sign_bits	   = Z_FLOAT64_SIGN_BITS
			};
			enum {	exponent_minimum    = Z_FLOAT64_EXPONENT_MINIMUM,
				exponent_maximum    = Z_FLOAT64_EXPONENT_MAXIMUM,
				exponent_10_minimum = Z_FLOAT64_EXPONENT_10_MINIMUM,
				exponent_10_maximum = Z_FLOAT64_EXPONENT_10_MAXIMUM
			};

			static Z_CT_MEMBER(CPP11) zfloat64 epsilon () {return Z_FLOAT64_EPSILON;}
			static Z_CT_MEMBER(CPP11) zfloat64 minimum () {return Z_FLOAT64_MINIMUM;}
			static Z_CT_MEMBER(CPP11) zfloat64 maximum () {return Z_FLOAT64_MAXIMUM;}
		/*	static Z_CT_MEMBER(CPP11) zfloat64 infinity() Z_NO_EXCEPTION {return Z_FLOAT64_INFINITY;}
			static Z_CT_MEMBER(CPP11) zfloat64 nan	   () Z_NO_EXCEPTION {return Z_FLOAT64_NAN;}*/

			typedef zfloat64 type;
			typedef zfloat64 to_signed;
		};

#	endif

#	if Z_HAS(TYPE_IS_FLOAT128)

		struct Float128 : Real {
			enum {is_float128 = true};

			enum {	value_type	 = Z_FLOAT128_VALUE_TYPE,
				fixed_value_type = Z_FLOAT128_FIXED_VALUE_TYPE,
				value_format	 = Z_FLOAT128_VALUE_FORMAT
			};
			enum {	bias		   = Z_FLOAT128_BIAS,
				decimal_digits	   = Z_FLOAT128_DECIMAL_DIGITS,
				significand_offset = Z_FLOAT128_SIGNIFICAND_OFFSET,
				significand_bits   = Z_FLOAT128_SIGNIFICAND_BITS,
				significand_digits = Z_FLOAT128_SIGNIFICAND_DIGITS,
				exponent_offset	   = Z_FLOAT128_EXPONENT_OFFSET,
				exponent_bits	   = Z_FLOAT128_EXPONENT_BITS,
				exponent_radix	   = Z_FLOAT128_EXPONENT_RADIX,
				sign_offset	   = Z_FLOAT128_SIGN_OFFSET,
				sign_bits	   = Z_FLOAT128_SIGN_BITS
			};
			enum {	exponent_minimum    = Z_FLOAT128_EXPONENT_MINIMUM,
				exponent_maximum    = Z_FLOAT128_EXPONENT_MAXIMUM,
				exponent_10_minimum = Z_FLOAT128_EXPONENT_10_MINIMUM,
				exponent_10_maximum = Z_FLOAT128_EXPONENT_10_MAXIMUM
			};

			static Z_CT_MEMBER(CPP11) zfloat128 epsilon () {return Z_FLOAT128_EPSILON;}
			static Z_CT_MEMBER(CPP11) zfloat128 minimum () {return Z_FLOAT128_MINIMUM;}
			static Z_CT_MEMBER(CPP11) zfloat128 maximum () {return Z_FLOAT128_MAXIMUM;}
		/*	static Z_CT_MEMBER(CPP11) zfloat128 infinity() Z_NO_EXCEPTION {return Z_FLOAT128_INFINITY;}
			static Z_CT_MEMBER(CPP11) zfloat128 nan	    () Z_NO_EXCEPTION {return Z_FLOAT128_NAN;}*/

			typedef zfloat128 type;
			typedef zfloat128 to_signed;
		};

#	endif

#	if Z_HAS(TYPE_IS_FLOAT80_X87)

		struct Float80_x87 : Real {
			enum {is_float80_x87 = true};

			enum {	value_type	 = Z_FLOAT80_X87_VALUE_TYPE,
				fixed_value_type = Z_FLOAT80_X87_FIXED_VALUE_TYPE,
				value_format	 = Z_FLOAT80_X87_VALUE_FORMAT
			};
			enum {	bias		   = Z_FLOAT80_X87_BIAS,
				decimal_digits	   = Z_FLOAT80_X87_DECIMAL_DIGITS,
				significand_offset = Z_FLOAT80_X87_SIGNIFICAND_OFFSET,
				significand_bits   = Z_FLOAT80_X87_SIGNIFICAND_BITS,
				significand_digits = Z_FLOAT80_X87_SIGNIFICAND_DIGITS,
				exponent_offset	   = Z_FLOAT80_X87_EXPONENT_OFFSET,
				exponent_bits	   = Z_FLOAT80_X87_EXPONENT_BITS,
				exponent_radix	   = Z_FLOAT80_X87_EXPONENT_RADIX,
				sign_offset	   = Z_FLOAT80_X87_SIGN_OFFSET,
				sign_bits	   = Z_FLOAT80_X87_SIGN_BITS
			};
			enum {	exponent_minimum    = Z_FLOAT80_X87_EXPONENT_MINIMUM,
				exponent_maximum    = Z_FLOAT80_X87_EXPONENT_MAXIMUM,
				exponent_10_minimum = Z_FLOAT80_X87_EXPONENT_10_MINIMUM,
				exponent_10_maximum = Z_FLOAT80_X87_EXPONENT_10_MAXIMUM
			};

			static Z_CT_MEMBER(CPP11) zfloat80_x87 epsilon () {return Z_FLOAT80_X87_EPSILON;}
			static Z_CT_MEMBER(CPP11) zfloat80_x87 minimum () {return Z_FLOAT80_X87_MINIMUM;}
			static Z_CT_MEMBER(CPP11) zfloat80_x87 maximum () {return Z_FLOAT80_X87_MAXIMUM;}
		/*	static Z_CT_MEMBER(CPP11) zfloat80_x87 infinity() Z_NO_EXCEPTION {return Z_FLOAT80_X87_INFINITY;}
			static Z_CT_MEMBER(CPP11) zfloat80_x87 nan     () Z_NO_EXCEPTION {return Z_FLOAT80_X87_NAN;}*/

			typedef zfloat80_x87 type;
			typedef zfloat80_x87 to_signed;
		};

#	endif

#	if Z_HAS(TYPE_IS_FLOAT96_X87)

		struct Float96_x87 : Real {
			enum {is_float96_x87 = true};

			enum {	value_type	 = Z_FLOAT96_X87_VALUE_TYPE,
				fixed_value_type = Z_FLOAT96_X87_FIXED_VALUE_TYPE,
				value_format	 = Z_FLOAT96_X87_VALUE_FORMAT
			};
			enum {	bias		   = Z_FLOAT96_X87_BIAS,
				decimal_digits	   = Z_FLOAT96_X87_DECIMAL_DIGITS,
				significand_offset = Z_FLOAT96_X87_SIGNIFICAND_OFFSET,
				significand_bits   = Z_FLOAT96_X87_SIGNIFICAND_BITS,
				significand_digits = Z_FLOAT96_X87_SIGNIFICAND_DIGITS,
				exponent_offset	   = Z_FLOAT96_X87_EXPONENT_OFFSET,
				exponent_bits	   = Z_FLOAT96_X87_EXPONENT_BITS,
				exponent_radix	   = Z_FLOAT96_X87_EXPONENT_RADIX,
				sign_offset	   = Z_FLOAT96_X87_SIGN_OFFSET,
				sign_bits	   = Z_FLOAT96_X87_SIGN_BITS
			};
			enum {	exponent_minimum    = Z_FLOAT96_X87_EXPONENT_MINIMUM,
				exponent_maximum    = Z_FLOAT96_X87_EXPONENT_MAXIMUM,
				exponent_10_minimum = Z_FLOAT96_X87_EXPONENT_10_MINIMUM,
				exponent_10_maximum = Z_FLOAT96_X87_EXPONENT_10_MAXIMUM
			};

			static Z_CT_MEMBER(CPP11) zfloat96_x87 epsilon () {return Z_FLOAT96_X87_EPSILON;}
			static Z_CT_MEMBER(CPP11) zfloat96_x87 minimum () {return Z_FLOAT96_X87_MINIMUM;}
			static Z_CT_MEMBER(CPP11) zfloat96_x87 maximum () {return Z_FLOAT96_X87_MAXIMUM;}
		/*	static Z_CT_MEMBER(CPP11) zfloat96_x87 infinity() Z_NO_EXCEPTION {return Z_FLOAT96_X87_INFINITY;}
			static Z_CT_MEMBER(CPP11) zfloat96_x87 nan     () Z_NO_EXCEPTION {return Z_FLOAT96_X87_NAN;}*/

			typedef zfloat96_x87 type;
			typedef zfloat96_x87 to_signed;
		};

#	endif

#	if Z_HAS(TYPE_IS_FLOAT128_X87)

		struct Float128_x87 : Real {
			enum {is_float128_x87 = true};

			enum {	value_type	 = Z_FLOAT128_X87_VALUE_TYPE,
				fixed_value_type = Z_FLOAT128_X87_FIXED_VALUE_TYPE,
				value_format	 = Z_FLOAT128_X87_VALUE_FORMAT
			};
			enum {	bias		   = Z_FLOAT128_X87_BIAS,
				decimal_digits	   = Z_FLOAT128_X87_DECIMAL_DIGITS,
				significand_offset = Z_FLOAT128_X87_SIGNIFICAND_OFFSET,
				significand_bits   = Z_FLOAT128_X87_SIGNIFICAND_BITS,
				significand_digits = Z_FLOAT128_X87_SIGNIFICAND_DIGITS,
				exponent_offset	   = Z_FLOAT128_X87_EXPONENT_OFFSET,
				exponent_bits	   = Z_FLOAT128_X87_EXPONENT_BITS,
				exponent_radix	   = Z_FLOAT128_X87_EXPONENT_RADIX,
				sign_offset	   = Z_FLOAT128_X87_SIGN_OFFSET,
				sign_bits	   = Z_FLOAT128_X87_SIGN_BITS
			};
			enum {	exponent_minimum    = Z_FLOAT128_X87_EXPONENT_MINIMUM,
				exponent_maximum    = Z_FLOAT128_X87_EXPONENT_MAXIMUM,
				exponent_10_minimum = Z_FLOAT128_X87_EXPONENT_10_MINIMUM,
				exponent_10_maximum = Z_FLOAT128_X87_EXPONENT_10_MAXIMUM
			};

			static Z_CT_MEMBER(CPP11) zfloat128_x87 epsilon () {return Z_FLOAT128_X87_EPSILON;}
			static Z_CT_MEMBER(CPP11) zfloat128_x87 minimum () {return Z_FLOAT128_X87_MINIMUM;}
			static Z_CT_MEMBER(CPP11) zfloat128_x87 maximum () {return Z_FLOAT128_X87_MAXIMUM;}
		/*	static Z_CT_MEMBER(CPP11) zfloat128_x87 infinity() Z_NO_EXCEPTION {return Z_FLOAT128_X87_INFINITY;}
			static Z_CT_MEMBER(CPP11) zfloat128_x87 nan	() Z_NO_EXCEPTION {return Z_FLOAT128_X87_NAN;}*/

			typedef zfloat128_x87 type;
			typedef zfloat128_x87 to_signed;
		};

#	endif

	struct Char : SelectType<Z_CHAR_IS_SIGNED, Natural, Integer>::type {
		enum {is_char = true};

		enum {	value_type	 = Z_CHAR_VALUE_TYPE,
			fixed_value_type = Z_CHAR_FIXED_VALUE_TYPE,
			value_format	 = Z_CHAR_VALUE_FORMAT
		};
		enum {	minimum = Z_CHAR_MINIMUM,
			maximum = Z_CHAR_MAXIMUM
		};

		typedef zchar  type;
		typedef zuchar to_unsigned;
		typedef zschar to_signed;
	};

	struct UChar : Natural {
		enum {is_uchar = true};

		enum {	value_type	 = Z_UCHAR_VALUE_TYPE,
			fixed_value_type = Z_UCHAR_FIXED_VALUE_TYPE,
			value_format	 = Z_UCHAR_VALUE_FORMAT
		};
		enum {maximum = Z_UCHAR_MAXIMUM};

		typedef zuchar type;
		typedef zuchar to_unsigned;
		typedef zschar to_signed;
	};

	struct UShort : Natural {
		enum {is_ushort = true};

		enum {	value_type	 = Z_USHORT_VALUE_TYPE,
			fixed_value_type = Z_USHORT_FIXED_VALUE_TYPE,
			value_format	 = Z_USHORT_VALUE_FORMAT
		};
		enum {maximum = Z_USHORT_MAXIMUM};

		typedef zushort type;
		typedef zushort to_unsigned;
		typedef zsshort to_signed;
	};

	struct UInt : Natural {
		enum {is_uint = true};

		enum {	value_type	 = Z_UINT_VALUE_TYPE,
			fixed_value_type = Z_UINT_FIXED_VALUE_TYPE,
			value_format	 = Z_UINT_VALUE_FORMAT
		};
		enum {maximum = Z_UINT_MAXIMUM};

		typedef zuint type;
		typedef zuint to_unsigned;
		typedef zsint to_signed;
	};

	struct ULong : Natural {
		enum {is_ulong = true};

		enum {	value_type	 = Z_ULONG_VALUE_TYPE,
			fixed_value_type = Z_ULONG_FIXED_VALUE_TYPE,
			value_format	 = Z_ULONG_VALUE_FORMAT
		};
		enum {maximum = Z_ULONG_MAXIMUM};

		typedef zulong type;
		typedef zulong to_unsigned;
		typedef zslong to_signed;

	};

#	if Z_HAS(TYPE_IS_ULLONG)

		struct ULLong : Natural {
			enum {is_ullong = true};

			enum {	value_type	 = Z_ULLONG_VALUE_TYPE,
				fixed_value_type = Z_ULLONG_FIXED_VALUE_TYPE,
				value_format	 = Z_ULLONG_VALUE_FORMAT
			};
			enum {maximum = Z_ULLONG_MAXIMUM};

			typedef zullong type;
			typedef zullong to_unsigned;

#			ifdef Z_SLLONG
				typedef zsllong to_signed;
#			endif
		};

#	endif

	struct SChar : Integer {
		enum {is_schar = true};

		enum {	value_type	 = Z_SCHAR_VALUE_TYPE,
			fixed_value_type = Z_SCHAR_FIXED_VALUE_TYPE,
			value_format	 = Z_SCHAR_VALUE_FORMAT
		};
		enum {	minimum = Z_SCHAR_MINIMUM,
			maximum = Z_SCHAR_MAXIMUM
		};

		typedef zschar type;
		typedef zuchar to_unsigned;
		typedef zschar to_signed;
	};

	struct SShort : Integer {
		enum {is_sshort = true};

		enum {	value_type	 = Z_SSHORT_VALUE_TYPE,
			fixed_value_type = Z_SSHORT_FIXED_VALUE_TYPE,
			value_format	 = Z_SSHORT_VALUE_FORMAT
		};
		enum {	minimum = Z_SSHORT_MINIMUM,
			maximum = Z_SSHORT_MAXIMUM
		};

		typedef zsshort type;
		typedef zushort to_unsigned;
		typedef zsshort to_signed;
	};

	struct SInt : Integer {
		enum {is_sint = true};

		enum {	value_type	 = Z_SINT_VALUE_TYPE,
			fixed_value_type = Z_SINT_FIXED_VALUE_TYPE,
			value_format	 = Z_SINT_VALUE_FORMAT
		};
		enum {	minimum = Z_SINT_MINIMUM,
			maximum = Z_SINT_MAXIMUM
		};

		typedef zsint type;
		typedef zuint to_unsigned;
		typedef zsint to_signed;
	};

	struct SLong : Integer {
		enum {is_slong = true};

		enum {	value_type	 = Z_SLONG_VALUE_TYPE,
			fixed_value_type = Z_SLONG_FIXED_VALUE_TYPE,
			value_format	 = Z_SLONG_VALUE_FORMAT
		};
		enum {	minimum = Z_SLONG_MINIMUM,
			maximum = Z_SLONG_MAXIMUM
		};

		typedef zslong type;
		typedef zulong to_unsigned;
		typedef zslong to_signed;
	};

#	if Z_HAS(TYPE_IS_SLLONG)

		struct SLLong : Integer {
			enum {is_sllong = true};

			enum {	value_type	 = Z_SLLONG_VALUE_TYPE,
				fixed_value_type = Z_SLLONG_FIXED_VALUE_TYPE,
				value_format	 = Z_SLLONG_VALUE_FORMAT
			};
			enum {	minimum = Z_SLLONG_MINIMUM,
				maximum = Z_SLLONG_MAXIMUM
			};

			typedef zsllong type;
			typedef zsllong to_signed;

#			ifdef Z_ULLONG
				typedef zullong to_unsigned;
#			endif
		};

#	endif

#	if Z_HAS(TYPE_IS_FLOAT)

		struct Float : Real {
			enum {is_float = true};

			enum {	value_type	 = Z_FLOAT_VALUE_TYPE,
				fixed_value_type = Z_FLOAT_FIXED_VALUE_TYPE,
				value_format	 = Z_FLOAT_VALUE_FORMAT
			};
			enum {	bias		   = Z_FLOAT_BIAS,
				decimal_digits	   = Z_FLOAT_DECIMAL_DIGITS,
				significand_offset = Z_FLOAT_SIGNIFICAND_OFFSET,
				significand_bits   = Z_FLOAT_SIGNIFICAND_BITS,
				significand_digits = Z_FLOAT_SIGNIFICAND_DIGITS,
				exponent_offset	   = Z_FLOAT_EXPONENT_OFFSET,
				exponent_bits	   = Z_FLOAT_EXPONENT_BITS,
				exponent_radix	   = Z_FLOAT_EXPONENT_RADIX,
				sign_offset	   = Z_FLOAT_SIGN_OFFSET,
				sign_bits	   = Z_FLOAT_SIGN_BITS
			};
			enum {	exponent_minimum    = Z_FLOAT_EXPONENT_MINIMUM,
				exponent_maximum    = Z_FLOAT_EXPONENT_MAXIMUM,
				exponent_10_minimum = Z_FLOAT_EXPONENT_10_MINIMUM,
				exponent_10_maximum = Z_FLOAT_EXPONENT_10_MAXIMUM
			};

			static Z_CT_MEMBER(CPP11) zfloat epsilon () {return Z_FLOAT_EPSILON;}
			static Z_CT_MEMBER(CPP11) zfloat minimum () {return Z_FLOAT_MINIMUM;}
			static Z_CT_MEMBER(CPP11) zfloat maximum () {return Z_FLOAT_MAXIMUM;}
		/*	static Z_CT_MEMBER(CPP11) zfloat infinity() Z_NO_EXCEPTION {return Z_FLOAT_INFINITY;}
			static Z_CT_MEMBER(CPP11) zfloat nan	 () Z_NO_EXCEPTION {return Z_FLOAT_NAN;}*/

			typedef zfloat type;
			typedef zfloat to_signed;
		};

#	endif

#	if Z_HAS(TYPE_IS_DOUBLE)

		struct Double : Real {
			enum {is_double = true};

			enum {	value_type	 = Z_DOUBLE_VALUE_TYPE,
				fixed_value_type = Z_DOUBLE_FIXED_VALUE_TYPE,
				value_format	 = Z_DOUBLE_VALUE_FORMAT
			};
			enum {	bias		   = Z_DOUBLE_BIAS,
				decimal_digits	   = Z_DOUBLE_DECIMAL_DIGITS,
				significand_offset = Z_DOUBLE_SIGNIFICAND_OFFSET,
				significand_bits   = Z_DOUBLE_SIGNIFICAND_BITS,
				significand_digits = Z_DOUBLE_SIGNIFICAND_DIGITS,
				exponent_offset	   = Z_DOUBLE_EXPONENT_OFFSET,
				exponent_bits	   = Z_DOUBLE_EXPONENT_BITS,
				exponent_radix	   = Z_DOUBLE_EXPONENT_RADIX,
				sign_offset	   = Z_DOUBLE_SIGN_OFFSET,
				sign_bits	   = Z_DOUBLE_SIGN_BITS
			};
			enum {	exponent_minimum    = Z_DOUBLE_EXPONENT_MINIMUM,
				exponent_maximum    = Z_DOUBLE_EXPONENT_MAXIMUM,
				exponent_10_minimum = Z_DOUBLE_EXPONENT_10_MINIMUM,
				exponent_10_maximum = Z_DOUBLE_EXPONENT_10_MAXIMUM
			};

			static Z_CT_MEMBER(CPP11) zdouble epsilon () {return Z_DOUBLE_EPSILON;}
			static Z_CT_MEMBER(CPP11) zdouble minimum () {return Z_DOUBLE_MINIMUM;}
			static Z_CT_MEMBER(CPP11) zdouble maximum () {return Z_DOUBLE_MAXIMUM;}
		/*	static Z_CT_MEMBER(CPP11) zdouble infinity() Z_NO_EXCEPTION {return Z_DOUBLE_INFINITY;}
			static Z_CT_MEMBER(CPP11) zdouble nan	  () Z_NO_EXCEPTION {return Z_DOUBLE_NAN;}*/

			typedef zdouble type;
			typedef zdouble to_signed;
		};

#	endif

#	if Z_HAS(TYPE_IS_LDOUBLE)

		struct LDouble : Real {
			enum {is_ldouble = true};

			enum {	value_type	 = Z_LDOUBLE_VALUE_TYPE,
				fixed_value_type = Z_LDOUBLE_FIXED_VALUE_TYPE,
				value_format	 = Z_LDOUBLE_VALUE_FORMAT
			};
			enum {	bias		   = Z_LDOUBLE_BIAS,
				decimal_digits	   = Z_LDOUBLE_DECIMAL_DIGITS,
				significand_offset = Z_LDOUBLE_SIGNIFICAND_OFFSET,
				significand_bits   = Z_LDOUBLE_SIGNIFICAND_BITS,
				significand_digits = Z_LDOUBLE_SIGNIFICAND_DIGITS,
				exponent_offset	   = Z_LDOUBLE_EXPONENT_OFFSET,
				exponent_bits	   = Z_LDOUBLE_EXPONENT_BITS,
				exponent_radix	   = Z_LDOUBLE_EXPONENT_RADIX,
				sign_offset	   = Z_LDOUBLE_SIGN_OFFSET,
				sign_bits	   = Z_LDOUBLE_SIGN_BITS
			};
			enum {	exponent_minimum    = Z_LDOUBLE_EXPONENT_MINIMUM,
				exponent_maximum    = Z_LDOUBLE_EXPONENT_MAXIMUM,
				exponent_10_minimum = Z_LDOUBLE_EXPONENT_10_MINIMUM,
				exponent_10_maximum = Z_LDOUBLE_EXPONENT_10_MAXIMUM
			};

			static Z_CT_MEMBER(CPP11) zldouble epsilon () {return Z_LDOUBLE_EPSILON;}
			static Z_CT_MEMBER(CPP11) zldouble minimum () {return Z_LDOUBLE_MINIMUM;}
			static Z_CT_MEMBER(CPP11) zldouble maximum () {return Z_LDOUBLE_MAXIMUM;}
		/*	static Z_CT_MEMBER(CPP11) zldouble infinity() Z_NO_EXCEPTION {return Z_LDOUBLE_INFINITY;}
			static Z_CT_MEMBER(CPP11) zldouble nan	   () Z_NO_EXCEPTION {return Z_LDOUBLE_NAN;}*/

			typedef zldouble type;
			typedef zldouble to_signed;
		};

#	endif

#	if Z_HAS(TYPE_IS_BOOLEAN)

		struct Boolean : Exact {
			enum {is_boolean = true};
		};

#	endif

	template <class T> struct Array : Storable {
		enum {is_array = true};

		typedef T element_type;

#		if Z_HAS(TYPE_IS_AGGREGATE)
			enum {is_aggregate = true};
#		endif

#		if Z_HAS(TYPE_IS_LITERAL)
			enum {is_literal = Z_COMPILER_TRAIT(TYPE_IS_LITERAL)(T)};
#		endif

#		if Z_HAS(TYPE_IS_POD)
			enum {is_pod = Z_COMPILER_TRAIT(TYPE_IS_POD)(T)};
#		endif
	};

	template <class T, zusize N> struct SizedArray : Array<T> {
		enum {element_count = N};

		typedef T type[N];
	};

	template <class T> struct FlexibleArray : Array<T> {
		enum {is_flexible_array = true};

		typedef T type[];
	};

#	if Z_HAS(TYPE_IS_ENUMERATION)

		template <class T> struct Enumeration : Storable {
			enum {	is_enumeration = true,
				is_scalar      = true
			};

#			if Z_HAS(TYPE_IS_LITERAL)
				enum {is_literal = true};
#			endif

#			if Z_HAS(TYPE_IS_POD)
				enum {is_pod = true};
#			endif

			typedef T type;

#			if Z_HAS(TYPE_UNDERLYING_TYPE)
				typedef Z_COMPILER_TRAIT(TYPE_UNDERLYING_TYPE)(T) underlying_type;
#			endif
		};

#	endif

	template <class T> struct Compound : Storable {
		enum {is_compound = true};

#		if Z_HAS(TYPE_IS_AGGREGATE)
			enum {is_aggregate = Z_COMPILER_TRAIT(TYPE_IS_AGGREGATE)(T)};
#		endif

#		if Z_HAS(TYPE_IS_FINAL)
			enum {is_final = Z_COMPILER_TRAIT(TYPE_IS_FINAL)(T)};
#		endif

#		if Z_HAS(TYPE_IS_LITERAL)
			enum {is_literal = Z_COMPILER_TRAIT(TYPE_IS_LITERAL)(T)};
#		endif

#		if Z_HAS(TYPE_IS_POD)
			enum {is_pod = Z_COMPILER_TRAIT(TYPE_IS_POD)(T)};
#		endif

		typedef T type;
	};

	template <class T> struct MaybeTemplate : Compound<T> {};

#	if Z_HAS(TYPE_IS_TEMPLATE)

		template <template <class...> class T, class... A> struct MaybeTemplate<T<A...> > : Compound<T<A...> > {
			enum {is_template = true};
			enum {arity = sizeof...(A)};

			typedef TypeList<A...> parameters;
		};

#	endif

	template <class T> class Structure : public MaybeTemplate<T> {
		public:
		enum {	is_class     = true,
			is_structure = true
		};

#		if Z_HAS(TYPE_IS_ABSTRACT)
			enum {is_abstract = Z_COMPILER_TRAIT(TYPE_IS_ABSTRACT)(T)};
#		endif

#		if Z_COMPILER_HAS_TRAIT(TYPE_IS_EMPTY)
			enum {is_empty = Z_COMPILER_TRAIT(TYPE_IS_EMPTY)(T)};
#		else
			private:
			struct Dummy	     {zsint dummy;};
			struct EmptyTest : T {zsint dummy;};

			public:
			enum {is_empty = (sizeof(EmptyTest) == sizeof(Dummy))};
#		endif

#		if Z_HAS(TYPE_IS_INTERFACE_CLASS)
			enum {is_interface_class = Z_COMPILER_TRAIT(TYPE_IS_INTERFACE_CLASS)(T)};
#		endif

#		if Z_HAS(TYPE_IS_POLYMORPHIC)
			enum {is_polymorphic = Z_COMPILER_TRAIT(TYPE_IS_POLYMORPHIC)(T)};
#		endif
	};

#	if Z_HAS(TYPE_IS_UNION)

		template <class T> struct Union : MaybeTemplate<T> {
			enum {is_union = true};
		};

#	endif

	struct PointerLike : Storable {
		enum {is_scalar	= true};

#		if Z_HAS(TYPE_IS_LITERAL)
			enum {is_literal = true};
#		endif

#		if Z_HAS(TYPE_IS_POD)
			enum {is_pod = true};
#		endif
	};

#	if Z_HAS(TYPE_IS_NULL_POINTER)

		struct NullPointer : PointerLike {
			enum {	is_fundamental	= true,
				is_null_pointer = true
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

#	if Z_LANGUAGE_HAS(CPP, VARIADIC_TEMPLATE)

		template <class T, class C, class M> struct MemberFunctionPointer : MemberPointer<T, C, M> {
			enum {	is_callable		   = true,
				is_member_function_pointer = true
			};
			enum {pointer_level = 1};

			typedef M to_function;
		};

#	endif

	template <class T> struct Reference : Storable {
		enum {is_reference = true};

#		if Z_HAS(TYPE_IS_LITERAL)
			enum {is_literal = true};
#		endif

		typedef T referencee_type;
	};

	template <class T> struct LValueReference : Reference<T> {
		enum {is_lvalue_reference = true};

		typedef T& type;
	};

#	if Z_LANGUAGE_HAS(CPP, RVALUE_REFERENCE)

		template <class T> struct RValueReference : Reference<T> {
			enum {is_rvalue_reference = true};

			typedef T&& type;
		};

#	endif

#	if Z_LANGUAGE_HAS(CPP, VARIADIC_TEMPLATE)

		template <class R, class... P> struct Function : Valid {
			enum {	is_callable = true,
				is_function = true
			};
			enum {arity = sizeof...(P)};

			typedef R type		   (P...);
			typedef R to_const	   (P...) const;
			typedef R to_volatile	   (P...)	volatile;
			typedef R to_const_volatile(P...) const volatile;

#			if Z_LANGUAGE_HAS(CPP, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)
				typedef R to_lvalue		  (P...)		&;
				typedef R to_rvalue		  (P...)		&&;
				typedef R to_const_lvalue	  (P...) const		&;
				typedef R to_const_rvalue	  (P...) const		&&;
				typedef R to_volatile_lvalue	  (P...)       volatile &;
				typedef R to_volatile_rvalue	  (P...)       volatile &&;
				typedef R to_const_volatile_lvalue(P...) const volatile &;
				typedef R to_const_volatile_rvalue(P...) const volatile &&;
#			endif

			typedef R return_type;

#			if Z_HAS(TYPE_PARAMETERS)
				typedef TypeList<P...> parameters;
#			endif
		};

		template <class R, class... P> struct VariadicFunction : Function<R, P...> {
			enum {is_variadic = true};

			typedef R type		   (P..., ...);
			typedef R to_const	   (P..., ...) const;
			typedef R to_volatile	   (P..., ...)	     volatile;
			typedef R to_const_volatile(P..., ...) const volatile;

#			if Z_LANGUAGE_HAS(CPP, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)
				typedef R to_lvalue		  (P..., ...)		     &;
				typedef R to_rvalue		  (P..., ...)		     &&;
				typedef R to_const_lvalue	  (P..., ...) const	     &;
				typedef R to_const_rvalue	  (P..., ...) const	     &&;
				typedef R to_volatile_lvalue	  (P..., ...)       volatile &;
				typedef R to_volatile_rvalue	  (P..., ...)       volatile &&;
				typedef R to_const_volatile_lvalue(P..., ...) const volatile &;
				typedef R to_const_volatile_rvalue(P..., ...) const volatile &&;
#			endif
		};

#	else

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
		typedef typename C::type	      to_unqualified;
		typedef typename C::to_const	      add_const;
		typedef typename C::to_volatile	      add_volatile;
		typedef typename C::to_const_volatile add_const_volatile;
		typedef typename C::type	      remove_const;
		typedef typename C::type	      remove_volatile;
		typedef typename C::type	      remove_const_volatile;

#		if Z_LANGUAGE_HAS(CPP, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)
			typedef typename C::to_lvalue		     add_lvalue;
			typedef typename C::to_rvalue		     add_rvalue;
			typedef typename C::to_const_lvalue	     add_const_lvalue;
			typedef typename C::to_const_rvalue	     add_const_rvalue;
			typedef typename C::to_volatile_lvalue	     add_volatile_lvalue;
			typedef typename C::to_volatile_rvalue	     add_volatile_rvalue;
			typedef typename C::to_const_volatile_lvalue add_const_volatile_lvalue;
			typedef typename C::to_const_volatile_rvalue add_const_volatile_rvalue;
			typedef typename C::type		     remove_this;
			typedef typename C::type		     remove_const_this;
			typedef typename C::type		     remove_volatile_this;
			typedef typename C::type		     remove_const_volatile_this;
#		endif
	};

	template <class C> struct QualifiedFunction : C {
		enum {is_qualified = true};
	};

	template <class C> struct ConstFunction : QualifiedFunction<C> {
		enum {is_const = true};

		typedef typename C::to_const	      type;
		typedef typename C::to_const_volatile add_volatile;
		typedef typename C::to_const	      remove_volatile;

#		if Z_LANGUAGE_HAS(CPP, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)
			typedef typename C::to_const_lvalue	     add_lvalue;
			typedef typename C::to_const_rvalue	     add_rvalue;
			typedef typename C::to_const_volatile_lvalue add_volatile_lvalue;
			typedef typename C::to_const_volatile_rvalue add_volatile_rvalue;
			typedef typename C::to_const		     remove_this;
			typedef typename C::to_const		     remove_volatile_this;
#		endif
	};

	template <class C> struct VolatileFunction : QualifiedFunction<C> {
		enum {is_volatile = true};

		typedef typename C::to_volatile		     type;
		typedef typename C::to_const_volatile	     add_const;
		typedef typename C::to_volatile		     remove_const;

#		if Z_LANGUAGE_HAS(CPP, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)
			typedef typename C::to_volatile_lvalue	     add_lvalue;
			typedef typename C::to_volatile_rvalue	     add_rvalue;
			typedef typename C::to_const_volatile_lvalue add_const_lvalue;
			typedef typename C::to_const_volatile_rvalue add_const_rvalue;
			typedef typename C::to_volatile		     remove_this;
			typedef typename C::to_volatile		     remove_const_this;
#		endif
	};

	template <class C> struct ConstVolatileFunction : QualifiedFunction<C> {
		enum {	is_const	  = true,
			is_const_volatile = true,
			is_volatile	  = true
		};

		typedef typename C::to_const_volatile type;
		typedef typename C::to_const_volatile add_const;
		typedef typename C::to_const_volatile add_volatile;
		typedef typename C::to_volatile	      remove_const;
		typedef typename C::to_const	      remove_volatile;

#		if Z_LANGUAGE_HAS(CPP, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)
			typedef typename C::to_const_volatile_lvalue add_lvalue;
			typedef typename C::to_const_volatile_rvalue add_rvalue;
			typedef typename C::to_const_volatile_lvalue add_const_lvalue;
			typedef typename C::to_const_volatile_rvalue add_const_rvalue;
			typedef typename C::to_const_volatile_lvalue add_volatile_lvalue;
			typedef typename C::to_const_volatile_rvalue add_volatile_rvalue;
			typedef typename C::to_const_volatile	     remove_this;
			typedef typename C::to_volatile		     remove_const_this;
			typedef typename C::to_const		     remove_volatile_this;
#		endif
	};

#	if Z_LANGUAGE_HAS(CPP, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)

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

#	endif

	// MARK: - Mixins: Kind

	template <class C> struct Virtual : C {
		typedef typename C::type remove_pointer;
		typedef typename C::type remove_reference;
	};

	template <class C> struct Storable : Virtual<C> {
		Z_DEFINE_STRICT_STRUCTURE (typename C::type value;     ) to_wrap;
		Z_DEFINE_STRICT_STRUCTURE (UInt8 data[sizeof(to_wrap)];) to_opaque;

		enum {	size = C::is_empty ? 0 : sizeof(to_wrap),
			bits = C::is_empty ? 0 : sizeof(to_wrap) * 8
		};
	};

	enum {	Void,
		Function,
		InconvertibleFunction,
		ConvertibleFunction,
		Value,
		VoidPointer,
		Pointer,
		MemberFunctionPointer,
		Reference
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
		typedef typename C::type	 to_pointer;
		typedef typename C::type*	 add_pointer;
		typedef typename C::type&	 add_lvalue_reference;
		typedef typename C::pointee_type remove_pointer;

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

		typedef typename C::referencee_type* to_pointer;
		typedef typename C::referencee_type& to_lvalue_reference;
		typedef typename C::type	     remove_pointer;
		typedef typename C::referencee_type  remove_reference;

#		if Z_LANGUAGE_HAS(CPP, RVALUE_REFERENCE)
			typedef typename C::referencee_type&& to_rvalue_reference;
#		endif
	};
}}}}

namespace Zeta {namespace Detail {namespace Type {

	// MARK: - Specializations: Enumerations, structures and unions

	template <class T> struct Case : Mixins::Unqualified<
#		if Z_HAS(TYPE_IS_ENUMERATION) && Z_HAS(TYPE_IS_UNION)
			typename SelectType<
				Z_COMPILER_TRAIT(TYPE_IS_ENUMERATION)(T) ? 2 : Z_COMPILER_TRAIT(TYPE_IS_UNION)(T),
				Abstract::Structure<T>, Abstract::Union<T>, Abstract::Enumeration<T>
			>::type
#		elif Z_HAS(TYPE_IS_ENUMERATION)
			typename SelectType<Z_COMPILER_TRAIT(TYPE_IS_ENUMERATION)(T), Abstract::Structure<T>, Abstract::Enumeration<T> >::type
#		elif Z_HAS(TYPE_IS_UNION)
			typename SelectType<Z_COMPILER_TRAIT(TYPE_IS_UNION)(T), Abstract::Structure<T>, Abstract::Union<T> >::type
#		else
			Abstract::Structure<T>
#		endif
	> {};

	// MARK: - Specializations: void

	template <> struct Case<void> : Mixins::Unqualified<Abstract::Void> {};

	// MARK: - Specializations: Numbers

#	if Z_HAS(TYPE_IS_UINT8)
		template <> struct Case<UInt8> : Mixins::Unqualified<Abstract::UInt8> {};
#	endif

#	if Z_HAS(TYPE_IS_UINT16)
		template <> struct Case<UInt16> : Mixins::Unqualified<Abstract::UInt16> {};
#	endif

#	if Z_HAS(TYPE_IS_UINT32)
		template <> struct Case<UInt32> : Mixins::Unqualified<Abstract::UInt32> {};
#	endif

#	if Z_HAS(TYPE_IS_UINT64)
		template <> struct Case<UInt64> : Mixins::Unqualified<Abstract::UInt64> {};
#	endif

#	if Z_HAS(TYPE_IS_UINT128)
		template <> struct Case<UInt128> : Mixins::Unqualified<Abstract::UInt128> {};
#	endif

#	if Z_HAS(TYPE_IS_SINT8)
		template <> struct Case<SInt8> : Mixins::Unqualified<Abstract::SInt8> {};
#	endif

#	if Z_HAS(TYPE_IS_SINT16)
		template <> struct Case<SInt16> : Mixins::Unqualified<Abstract::SInt16> {};
#	endif

#	if Z_HAS(TYPE_IS_SINT32)
		template <> struct Case<SInt32> : Mixins::Unqualified<Abstract::SInt32> {};
#	endif

#	if Z_HAS(TYPE_IS_SINT64)
		template <> struct Case<SInt64> : Mixins::Unqualified<Abstract::SInt64> {};
#	endif

#	if Z_HAS(TYPE_IS_SINT128)
		template <> struct Case<SInt128> : Mixins::Unqualified<Abstract::SInt128> {};
#	endif

#	if Z_HAS(TYPE_IS_FLOAT16)
		template <> struct Case<Float16> : Mixins::Unqualified<Abstract::Float16> {};
#	endif

#	if Z_HAS(TYPE_IS_FLOAT32)
		template <> struct Case<Float32> : Mixins::Unqualified<Abstract::Float32> {};
#	endif

#	if Z_HAS(TYPE_IS_FLOAT64)
		template <> struct Case<Float64> : Mixins::Unqualified<Abstract::Float64> {};
#	endif

#	if Z_HAS(TYPE_IS_FLOAT128)
		template <> struct Case<Float128> : Mixins::Unqualified<Abstract::Float128> {};
#	endif

#	if Z_HAS(TYPE_IS_FLOAT80_X87)
		template <> struct Case<Float80_x87> : Mixins::Unqualified<Abstract::Float80_x87> {};
#	endif

#	if Z_HAS(TYPE_IS_FLOAT96_X87)
		template <> struct Case<Float96_x87> : Mixins::Unqualified<Abstract::Float96_x87> {};
#	endif

#	if Z_HAS(TYPE_IS_FLOAT128_X87)
		template <> struct Case<Float128_x87> : Mixins::Unqualified<Abstract::Float128_x87> {};
#	endif

	template <> struct Case<Char  > : Mixins::Unqualified<Abstract::Char  > {};
	template <> struct Case<UChar > : Mixins::Unqualified<Abstract::UChar > {};
	template <> struct Case<UShort> : Mixins::Unqualified<Abstract::UShort> {};
	template <> struct Case<UInt  > : Mixins::Unqualified<Abstract::UInt  > {};
	template <> struct Case<ULong > : Mixins::Unqualified<Abstract::ULong > {};

#	if Z_HAS(TYPE_IS_ULLONG)
		template <> struct Case<ULLong> : Mixins::Unqualified<Abstract::ULLong> {};
#	endif

	template <> struct Case<SChar > : Mixins::Unqualified<Abstract::SChar > {};
	template <> struct Case<SShort> : Mixins::Unqualified<Abstract::SShort> {};
	template <> struct Case<SInt  > : Mixins::Unqualified<Abstract::SInt  > {};
	template <> struct Case<SLong > : Mixins::Unqualified<Abstract::SLong > {};

#	if Z_HAS(TYPE_IS_SLLONG)
		template <> struct Case<SLLong> : Mixins::Unqualified<Abstract::SLLong> {};
#	endif

#	if Z_HAS(TYPE_IS_FLOAT)
		template <> struct Case<Float> : Mixins::Unqualified<Abstract::Float> {};
#	endif

#	if Z_HAS(TYPE_IS_DOUBLE)
		template <> struct Case<Double> : Mixins::Unqualified<Abstract::Double> {};
#	endif

#	if Z_HAS(TYPE_IS_LDOUBLE)
		template <> struct Case<LDouble> : Mixins::Unqualified<Abstract::LDouble> {};
#	endif

#	if Z_HAS(TYPE_IS_BOOLEAN)
		template <> struct Case<Boolean> : Mixins::Unqualified<Abstract::Boolean> {};
#	endif

	// MARK: - Specializations: Sized arrays

	template <class T, USize N> struct Case<T[N]> : Mixins::Unqualified<Abstract::SizedArray<T, N> > {};

	template <class T, USize N> struct Case<const	       T[N]> : Mixins::ConstArray	 <Case<T[N]> > {};
	template <class T, USize N> struct Case<      volatile T[N]> : Mixins::VolatileArray	 <Case<T[N]> > {};
	template <class T, USize N> struct Case<const volatile T[N]> : Mixins::ConstVolatileArray<Case<T[N]> > {};

	// MARK: - Specializations: Flexible arrays

	template <class T> struct Case<T[]> : Mixins::Unqualified<Abstract::FlexibleArray<T> > {};

	template <class T> struct Case<const	      T[]> : Mixins::ConstArray	       <Case<T[]> > {};
	template <class T> struct Case<	     volatile T[]> : Mixins::VolatileArray     <Case<T[]> > {};
	template <class T> struct Case<const volatile T[]> : Mixins::ConstVolatileArray<Case<T[]> > {};

	// MARK: - Specializations: Pointers

#	if Z_HAS(TYPE_IS_NULL_POINTER)
		template <> struct Case<NullPointer> : Mixins::Unqualified<Abstract::NullPointer> {};
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

		template <class C, class R, class... P> struct Case<R(C::*)(P...)		 > : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(P...)		     , C, R(P...)		> > {};
		template <class C, class R, class... P> struct Case<R(C::*)(P...) const		 > : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(P...) const	     , C, R(P...) const		> > {};
		template <class C, class R, class... P> struct Case<R(C::*)(P...)	volatile > : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(P...)	     volatile, C, R(P...)	volatile> > {};
		template <class C, class R, class... P> struct Case<R(C::*)(P...) const volatile > : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(P...) const volatile, C, R(P...) const volatile> > {};

		template <class C, class R, class... P> struct Case<R(C::*)(P..., ...)		      > : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(P..., ...)	       , C, R(P..., ...)	       > > {};
		template <class C, class R, class... P> struct Case<R(C::*)(P..., ...) const	      > : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(P..., ...) const	       , C, R(P..., ...) const	       > > {};
		template <class C, class R, class... P> struct Case<R(C::*)(P..., ...)	     volatile > : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(P..., ...)       volatile, C, R(P..., ...)       volatile> > {};
		template <class C, class R, class... P> struct Case<R(C::*)(P..., ...) const volatile > : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(P..., ...) const volatile, C, R(P..., ...) const volatile> > {};

#		if Z_LANGUAGE_HAS(CPP, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)

			template <class C, class R, class... P> struct Case<R(C::*)(P...)		 & > : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(P...)		& , C, R(P...)		      & > > {};
			template <class C, class R, class... P> struct Case<R(C::*)(P...)		 &&> : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(P...)		&&, C, R(P...)		      &&> > {};
			template <class C, class R, class... P> struct Case<R(C::*)(P...) const		 & > : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(P...) const		& , C, R(P...) const	      & > > {};
			template <class C, class R, class... P> struct Case<R(C::*)(P...) const		 &&> : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(P...) const		&&, C, R(P...) const	      &&> > {};
			template <class C, class R, class... P> struct Case<R(C::*)(P...)	volatile & > : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(P...)       volatile & , C, R(P...)	     volatile & > > {};
			template <class C, class R, class... P> struct Case<R(C::*)(P...)	volatile &&> : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(P...)       volatile &&, C, R(P...)	     volatile &&> > {};
			template <class C, class R, class... P> struct Case<R(C::*)(P...) const volatile & > : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(P...) const volatile & , C, R(P...) const volatile &	> > {};
			template <class C, class R, class... P> struct Case<R(C::*)(P...) const volatile &&> : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(P...) const volatile &&, C, R(P...) const volatile &&> > {};

			template <class C, class R, class... P> struct Case<R(C::*)(P..., ...)		      & > : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(P..., ...)		  & , C, R(P...)		& > > {};
			template <class C, class R, class... P> struct Case<R(C::*)(P..., ...)		      &&> : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(P..., ...)		  &&, C, R(P...)		&&> > {};
			template <class C, class R, class... P> struct Case<R(C::*)(P..., ...) const	      & > : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(P..., ...) const	  & , C, R(P...) const		& > > {};
			template <class C, class R, class... P> struct Case<R(C::*)(P..., ...) const	      &&> : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(P..., ...) const	  &&, C, R(P...) const		&&> > {};
			template <class C, class R, class... P> struct Case<R(C::*)(P..., ...)	     volatile & > : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(P..., ...)	 volatile & , C, R(P...)       volatile & > > {};
			template <class C, class R, class... P> struct Case<R(C::*)(P..., ...)	     volatile &&> : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(P..., ...)	 volatile &&, C, R(P...)       volatile &&> > {};
			template <class C, class R, class... P> struct Case<R(C::*)(P..., ...) const volatile & > : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(P..., ...) const volatile & , C, R(P...) const volatile & > > {};
			template <class C, class R, class... P> struct Case<R(C::*)(P..., ...) const volatile &&> : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(P..., ...) const volatile &&, C, R(P...) const volatile &&> > {};

#		endif

#	else
#		if Z_LANGUAGE_HAS(CPP, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)

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

#	if Z_HAS(TYPE_IS_RVALUE_REFERENCE)

		template <class T> struct Case<T&&> : Mixins::Unqualified<Abstract::RValueReference<T> > {
			enum {	is_function_reference	     = Case<T>::is_function,
				is_function_rvalue_reference = is_function_reference,
				is_callable		     = is_function_reference
			};

			typedef typename SelectType<is_function_reference, NaT, T>::type to_function;
		};

#	endif

	// MARK: - Specializations: Functions

#	if Z_LANGUAGE_HAS(CPP, VARIADIC_TEMPLATE)

		template <class R, class... P> struct Case<R(P...)> : Mixins::UnqualifiedFunction<Abstract::Function<R, P...> > {};

		template <class R, class... P> struct Case<R(P...) const	 > : Mixins::ConstFunction	  <Case<R(P...)> > {};
		template <class R, class... P> struct Case<R(P...)	 volatile> : Mixins::VolatileFunction	  <Case<R(P...)> > {};
		template <class R, class... P> struct Case<R(P...) const volatile> : Mixins::ConstVolatileFunction<Case<R(P...)> > {};

		template <class R, class... P> struct Case<R(P..., ...)> : Mixins::UnqualifiedFunction<Abstract::VariadicFunction<R, P...> > {};

		template <class R, class... P> struct Case<R(P..., ...) const	      > : Mixins::ConstFunction	       <Case<R(P..., ...)> > {};
		template <class R, class... P> struct Case<R(P..., ...)	      volatile> : Mixins::VolatileFunction     <Case<R(P..., ...)> > {};
		template <class R, class... P> struct Case<R(P..., ...) const volatile> : Mixins::ConstVolatileFunction<Case<R(P..., ...)> > {};

#		if Z_LANGUAGE_HAS(CPP, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)

			template <class R, class... P> struct Case<R(P...)		  & > : Mixins::LValueFunction		   <Case<R(P...)> > {};
			template <class R, class... P> struct Case<R(P...)		  &&> : Mixins::RValueFunction		   <Case<R(P...)> > {};
			template <class R, class... P> struct Case<R(P...) const	  & > : Mixins::ConstLValueFunction	   <Case<R(P...)> > {};
			template <class R, class... P> struct Case<R(P...) const	  &&> : Mixins::ConstRValueFunction	   <Case<R(P...)> > {};
			template <class R, class... P> struct Case<R(P...)	 volatile & > : Mixins::VolatileLValueFunction	   <Case<R(P...)> > {};
			template <class R, class... P> struct Case<R(P...)	 volatile &&> : Mixins::VolatileRValueFunction	   <Case<R(P...)> > {};
			template <class R, class... P> struct Case<R(P...) const volatile & > : Mixins::ConstVolatileLValueFunction<Case<R(P...)> > {};
			template <class R, class... P> struct Case<R(P...) const volatile &&> : Mixins::ConstVolatileRValueFunction<Case<R(P...)> > {};

			template <class R, class... P> struct Case<R(P..., ...)		       & > : Mixins::LValueFunction		<Case<R(P..., ...)> > {};
			template <class R, class... P> struct Case<R(P..., ...)		       &&> : Mixins::RValueFunction		<Case<R(P..., ...)> > {};
			template <class R, class... P> struct Case<R(P..., ...) const	       & > : Mixins::ConstLValueFunction	<Case<R(P..., ...)> > {};
			template <class R, class... P> struct Case<R(P..., ...) const	       &&> : Mixins::ConstRValueFunction	<Case<R(P..., ...)> > {};
			template <class R, class... P> struct Case<R(P..., ...)	      volatile & > : Mixins::VolatileLValueFunction     <Case<R(P..., ...)> > {};
			template <class R, class... P> struct Case<R(P..., ...)	      volatile &&> : Mixins::VolatileRValueFunction     <Case<R(P..., ...)> > {};
			template <class R, class... P> struct Case<R(P..., ...) const volatile & > : Mixins::ConstVolatileLValueFunction<Case<R(P..., ...)> > {};
			template <class R, class... P> struct Case<R(P..., ...) const volatile &&> : Mixins::ConstVolatileRValueFunction<Case<R(P..., ...)> > {};

#		endif

#	else

#		if Z_LANGUAGE_HAS(CPP, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)

#		endif

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
					: Mixins::Value))
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
		>::type to_forwardable;
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

#		define Z_HAS_TYPE_IS_ASSIGNABLE TRUE
#	else
#		define Z_HAS_TYPE_IS_ASSIGNABLE FALSE
#	endif

#	if Z_COMPILER_HAS_TRAIT(TYPE_IS_BASE)

		template <class T, class of_type> struct TypeIsBase {
			enum {value = Z_COMPILER_TRAIT(TYPE_IS_BASE)(T, of_type)};
		};

#		define Z_HAS_TYPE_IS_BASE TRUE
#	else
#		define Z_HAS_TYPE_IS_BASE FALSE
#	endif

#	if Z_COMPILER_HAS_TRAIT(TYPE_IS_CONVERTIBLE)

		template <class T, class to_type> struct TypeIsConvertible {
			enum {value = Z_COMPILER_TRAIT(TYPE_IS_CONVERTIBLE)(T, to_type)};
		};

#		define Z_HAS_TYPE_IS_CONVERTIBLE TRUE
#	else
#		define Z_HAS_TYPE_IS_CONVERTIBLE FALSE
#	endif

#	if Z_COMPILER_HAS_TRAIT(TYPE_IS_NOTHROW_ASSIGNABLE)

		template <class T, class from_type> struct TypeIsNothrowAssignable {
			enum {value = Z_COMPILER_TRAIT(TYPE_IS_NOTHROW_ASSIGNABLE)(T, from_type)};
		};

#		define Z_HAS_TYPE_IS_NOTHROW_ASSIGNABLE TRUE
#	else
#		define Z_HAS_TYPE_IS_NOTHROW_ASSIGNABLE FALSE
#	endif

#	if Z_COMPILER_HAS_TRAIT(TYPE_IS_TRIVIALLY_ASSIGNABLE)

		template <class T, class from_type> struct TypeIsTriviallyAssignable {
			enum {value = Z_COMPILER_TRAIT(TYPE_IS_TRIVIALLY_ASSIGNABLE)(T, from_type)};
		};

#		define Z_HAS_TYPE_IS_TRIVIALLY_ASSIGNABLE TRUE
#	else
#		define Z_HAS_TYPE_IS_TRIVIALLY_ASSIGNABLE FALSE
#	endif

#	if Z_LANGUAGE_HAS(CPP, VARIADIC_TEMPLATE)

#		if Z_COMPILER_HAS_TRAIT(TYPE_IS_CONSTRUCTIBLE)

			template <class T, class... parameters> struct TypeIsConstructible {
				enum {value = Z_COMPILER_TRAIT(TYPE_IS_CONSTRUCTIBLE)(T, parameters...)};
			};

#			define Z_HAS_TYPE_IS_CONSTRUCTIBLE TRUE
#		else
#			define Z_HAS_TYPE_IS_CONSTRUCTIBLE FALSE
#		endif

#		if Z_COMPILER_HAS_TRAIT(TYPE_IS_NOTHROW_CONSTRUCTIBLE)

			template <class T, class... parameters> struct TypeIsNothrowConstructible {
				enum {value = Z_COMPILER_TRAIT(TYPE_IS_NOTHROW_CONSTRUCTIBLE)(T, parameters...)};
			};

#			define Z_HAS_TYPE_IS_NOTHROW_CONSTRUCTIBLE TRUE
#		else
#			define Z_HAS_TYPE_IS_NOTHROW_CONSTRUCTIBLE FALSE
#		endif

#		if Z_COMPILER_HAS_TRAIT(TYPE_IS_TRIVIALLY_CONSTRUCTIBLE)

			template <class T, class... parameters> struct TypeIsTriviallyConstructible {
				enum {value = Z_COMPILER_TRAIT(TYPE_IS_TRIVIALLY_CONSTRUCTIBLE)(T, parameters...)};
			};

#			define Z_HAS_TYPE_IS_TRIVIALLY_CONSTRUCTIBLE TRUE
#		else
#			define Z_HAS_TYPE_IS_TRIVIALLY_CONSTRUCTIBLE FALSE
#		endif

#	endif

	template <class T, class klass> struct TypeToMemberPointer;

	template <class T, class C> struct TypeToMemberPointer {typedef T C::*type;};

	template <class C> struct TypeToMemberPointer<		     void, C> {typedef NaT type;};
	template <class C> struct TypeToMemberPointer<const	     void, C> {typedef NaT type;};
	template <class C> struct TypeToMemberPointer<	    volatile void, C> {typedef NaT type;};
	template <class C> struct TypeToMemberPointer<const volatile void, C> {typedef NaT type;};

#	if Z_LANGUAGE_HAS(CPP, VARIADIC_TEMPLATE)

		template <class C, class R, class... P> struct TypeToMemberPointer<R(P...)		 , C> {typedef R(C::*type)(P...)	       ;};
		template <class C, class R, class... P> struct TypeToMemberPointer<R(P...) const	 , C> {typedef R(C::*type)(P...) const	       ;};
		template <class C, class R, class... P> struct TypeToMemberPointer<R(P...)	 volatile, C> {typedef R(C::*type)(P...)       volatile;};
		template <class C, class R, class... P> struct TypeToMemberPointer<R(P...) const volatile, C> {typedef R(C::*type)(P...) const volatile;};

		template <class C, class R, class... P> struct TypeToMemberPointer<R(P..., ...)		      , C> {typedef R(C::*type)(P...)		    ;};
		template <class C, class R, class... P> struct TypeToMemberPointer<R(P..., ...) const	      , C> {typedef R(C::*type)(P...) const	    ;};
		template <class C, class R, class... P> struct TypeToMemberPointer<R(P..., ...)	      volatile, C> {typedef R(C::*type)(P...)	    volatile;};
		template <class C, class R, class... P> struct TypeToMemberPointer<R(P..., ...) const volatile, C> {typedef R(C::*type)(P...) const volatile;};

#		if Z_LANGUAGE_HAS(CPP, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)

			template <class C, class R, class... P> struct TypeToMemberPointer<R(P...)		  & , C> {typedef R(C::*type)(P...)		   & ;};
			template <class C, class R, class... P> struct TypeToMemberPointer<R(P...)		  &&, C> {typedef R(C::*type)(P...)		   &&;};
			template <class C, class R, class... P> struct TypeToMemberPointer<R(P...) const	  & , C> {typedef R(C::*type)(P...) const	   & ;};
			template <class C, class R, class... P> struct TypeToMemberPointer<R(P...) const	  &&, C> {typedef R(C::*type)(P...) const	   &&;};
			template <class C, class R, class... P> struct TypeToMemberPointer<R(P...)	 volatile & , C> {typedef R(C::*type)(P...)	  volatile & ;};
			template <class C, class R, class... P> struct TypeToMemberPointer<R(P...)	 volatile &&, C> {typedef R(C::*type)(P...)	  volatile &&;};
			template <class C, class R, class... P> struct TypeToMemberPointer<R(P...) const volatile & , C> {typedef R(C::*type)(P...) const volatile & ;};
			template <class C, class R, class... P> struct TypeToMemberPointer<R(P...) const volatile &&, C> {typedef R(C::*type)(P...) const volatile &&;};

			template <class C, class R, class... P> struct TypeToMemberPointer<R(P..., ...)		       & , C> {typedef R(C::*type)(P..., ...)		     & ;};
			template <class C, class R, class... P> struct TypeToMemberPointer<R(P..., ...)		       &&, C> {typedef R(C::*type)(P..., ...)		     &&;};
			template <class C, class R, class... P> struct TypeToMemberPointer<R(P..., ...) const	       & , C> {typedef R(C::*type)(P..., ...) const	     & ;};
			template <class C, class R, class... P> struct TypeToMemberPointer<R(P..., ...) const	       &&, C> {typedef R(C::*type)(P..., ...) const	     &&;};
			template <class C, class R, class... P> struct TypeToMemberPointer<R(P..., ...)	      volatile & , C> {typedef R(C::*type)(P..., ...)	    volatile & ;};
			template <class C, class R, class... P> struct TypeToMemberPointer<R(P..., ...)	      volatile &&, C> {typedef R(C::*type)(P..., ...)	    volatile &&;};
			template <class C, class R, class... P> struct TypeToMemberPointer<R(P..., ...) const volatile & , C> {typedef R(C::*type)(P..., ...) const volatile & ;};
			template <class C, class R, class... P> struct TypeToMemberPointer<R(P..., ...) const volatile &&, C> {typedef R(C::*type)(P..., ...) const volatile &&;};

#		endif

#	else

#		if Z_LANGUAGE_HAS(CPP, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)

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
				is_char			     = Type::is_char,
				is_class		     = Type::is_class,
				is_compound		     = Type::is_compound,
				is_const		     = Type::is_const,
				is_const_volatile	     = Type::is_const_volatile,
				is_data_member_pointer	     = Type::is_data_member_pointer,
				is_empty		     = Type::is_empty,
				is_exact		     = Type::is_exact,
				is_integer		     = Type::is_integer,
				is_flexible_array	     = Type::is_flexible_array,
				is_function		     = Type::is_function,
				is_function_lvalue_reference = Type::is_function_lvalue_reference,
				is_function_pointer	     = Type::is_function_pointer,
				is_function_reference	     = Type::is_function_reference,
				is_fundamental		     = Type::is_fundamental,
				is_lvalue_reference	     = Type::is_lvalue_reference,
				is_member_function_pointer   = Type::is_member_function_pointer,
				is_member_pointer	     = Type::is_member_pointer,
				is_nat			     = Type::is_nat,
				is_natural		     = Type::is_natural,
				is_number		     = Type::is_number,
				is_pointer		     = Type::is_pointer,
				is_qualified		     = Type::is_qualified,
				is_real			     = Type::is_real,
				is_reference		     = Type::is_reference,
				is_scalar		     = Type::is_scalar,
				is_schar		     = Type::is_schar,
				is_signed		     = Type::is_signed,
				is_sint			     = Type::is_sint,
				is_slong		     = Type::is_slong,
				is_sshort		     = Type::is_sshort,
				is_storable		     = Type::is_storable,
				is_structure		     = Type::is_structure,
				is_uchar		     = Type::is_uchar,
				is_uint			     = Type::is_uint,
				is_ulong		     = Type::is_ulong,
				is_ushort		     = Type::is_ushort,
				is_valid		     = Type::is_valid,
				is_value		     = Type::is_value,
				is_variadic		     = Type::is_variadic,
				is_variadic_function	     = Type::is_variadic_function,
				is_void			     = Type::is_void,
				is_void_pointer		     = Type::is_void_pointer,
				is_volatile		     = Type::is_volatile
			};

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
			typedef typename Type<typename Type::referencee_type>::flow referencee_type;
			typedef typename Type<typename Type::return_type    >::flow return_type;

			typedef typename Type<typename Type::to_const		  >::flow to_const;
			typedef typename Type<typename Type::to_const_volatile	  >::flow to_const_volatile;
			typedef typename Type<typename Type::to_forwardable	  >::flow to_forwardable;
			typedef typename Type<typename Type::to_function	  >::flow to_function;
			typedef typename Type<typename Type::to_lvalue_reference  >::flow to_lvalue_reference;
			typedef typename Type<typename Type::to_opaque		  >::flow to_opaque;
			typedef typename Type<typename Type::to_pointer		  >::flow to_pointer;
			typedef typename Type<typename Type::to_signed		  >::flow to_signed;
			typedef typename Type<typename Type::to_unqualified	  >::flow to_unqualified;
			typedef typename Type<typename Type::to_unsigned	  >::flow to_unsigned;
			typedef typename Type<typename Type::to_volatile	  >::flow to_volatile;
			typedef typename Type<typename Type::to_wrap		  >::flow to_wrap;
			typedef typename Type<typename Type::add_const		  >::flow add_const;
			typedef typename Type<typename Type::add_const_volatile	  >::flow add_const_volatile;
			typedef typename Type<typename Type::add_lvalue_reference >::flow add_lvalue_reference;
			typedef typename Type<typename Type::add_pointer	  >::flow add_pointer;
			typedef typename Type<typename Type::add_volatile	  >::flow add_volatile;
			typedef typename Type<typename Type::remove_const	  >::flow remove_const;
			typedef typename Type<typename Type::remove_const_volatile>::flow remove_const_volatile;
			typedef typename Type<typename Type::remove_pointer	  >::flow remove_pointer;
			typedef typename Type<typename Type::remove_reference	  >::flow remove_reference;
			typedef typename Type<typename Type::remove_volatile	  >::flow remove_volatile;

#			if Z_HAS(TYPE_IS_ABSTRACT)
				enum {is_abstract = Type::is_abstract};
#			endif

#			if Z_HAS(TYPE_IS_AGGREGATE)
				enum {is_aggregate = Type::is_aggregate};
#			endif

#			if Z_HAS(TYPE_IS_BOOLEAN)
				enum {is_boolean = Type::is_boolean};
#			endif

#			if Z_HAS(TYPE_IS_DOUBLE)
				enum {is_double = Type::is_double};
#			endif

#			if Z_HAS(TYPE_IS_ENUMERATION)
				enum {is_enumeration = Type::is_enumeration};
#			endif

#			if Z_HAS(TYPE_IS_FINAL)
				enum {is_final = Type::is_final};
#			endif

#			if Z_HAS(TYPE_IS_FLOAT)
				enum {is_float = Type::is_float};
#			endif

#			if Z_HAS(TYPE_IS_FLOAT16)
				enum {is_float16 = Type::is_float16};
#			endif

#			if Z_HAS(TYPE_IS_FLOAT32)
				enum {is_float32 = Type::is_float32};
#			endif

#			if Z_HAS(TYPE_IS_FLOAT64)
				enum {is_float64 = Type::is_float64};
#			endif

#			if Z_HAS(TYPE_IS_FLOAT128)
				enum {is_float128 = Type::is_float128};
#			endif

#			if Z_HAS(TYPE_IS_FLOAT80_X87)
				enum {is_float80_x87 = Type::is_float80_x87};
#			endif

#			if Z_HAS(TYPE_IS_FLOAT96_X87)
				enum {is_float96_x87 = Type::is_float96_x87};
#			endif

#			if Z_HAS(TYPE_IS_FLOAT128_X87)
				enum {is_float128_x87 = Type::is_float128_x87};
#			endif

#			if Z_HAS(TYPE_IS_INTERFACE_CLASS)
				enum {is_interface_class = Type::is_interface_class};
#			endif

#			if Z_HAS(TYPE_IS_LDOUBLE)
				enum {is_ldouble = Type::is_ldouble};
#			endif

#			if Z_HAS(TYPE_IS_LITERAL)
				enum {is_literal = Type::is_literal};
#			endif

#			if Z_HAS(TYPE_IS_NULL_POINTER)
				enum {is_null_pointer = Type::is_null_pointer};
#			endif

#			if Z_HAS(TYPE_IS_POD)
				enum {is_pod = Type::is_pod};
#			endif

#			if Z_HAS(TYPE_IS_POLYMORPHIC)
				enum {is_polymorphic = Type::is_polymorphic};
#			endif

#			if Z_HAS(TYPE_IS_SINT8)
				enum {is_sint8 = Type::is_sint8};
#			endif

#			if Z_HAS(TYPE_IS_SINT16)
				enum {is_sint16 = Type::is_sint16};
#			endif

#			if Z_HAS(TYPE_IS_SINT32)
				enum {is_sint32 = Type::is_sint32};
#			endif

#			if Z_HAS(TYPE_IS_SINT64)
				enum {is_sint64 = Type::is_sint64};
#			endif

#			if Z_HAS(TYPE_IS_SINT128)
				enum {is_sint128 = Type::is_sint128};
#			endif

#			if Z_HAS(TYPE_IS_SLLONG)
				enum {is_sllong = Type::is_sllong};
#			endif

#			if Z_HAS_TYPE_IS_TEMPLATE
				enum {is_template = Type::is_template};
#			endif

#			if Z_HAS(TYPE_IS_UINT8)
				enum {is_uint8 = Type::is_uint8};
#			endif

#			if Z_HAS(TYPE_IS_UINT16)
				enum {is_uint16 = Type::is_uint16};
#			endif

#			if Z_HAS(TYPE_IS_UINT32)
				enum {is_uint32 = Type::is_uint32};
#			endif

#			if Z_HAS(TYPE_IS_UINT64)
				enum {is_uint64 = Type::is_uint64};
#			endif

#			if Z_HAS(TYPE_IS_UINT128)
				enum {is_uint128 = Type::is_uint128};
#			endif

#			if Z_HAS(TYPE_IS_ULLONG)
				enum {is_ullong = Type::is_ullong};
#			endif

#			if Z_HAS(TYPE_IS_UNION)
				enum {is_union = Type::is_union};
#			endif

#			if Z_LANGUAGE_HAS(CPP, VARIADIC_TEMPLATE)

#				if Z_HAS(TYPE_IS_FUNCTION_RVALUE_REFERENCE)
					enum {is_function_rvalue_reference = Type::is_function_rvalue_reference};
#				endif

#				if Z_LANGUAGE_HAS(CPP, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)

					enum {	is_const_lvalue		 = Type::is_const_lvalue,
						is_const_rvalue		 = Type::is_const_rvalue,
						is_const_volatile_lvalue = Type::is_const_volatile_lvalue,
						is_const_volatile_rvalue = Type::is_const_volatile_rvalue,
						is_lvalue		 = Type::is_lvalue,
						is_rvalue		 = Type::is_rvalue,
						is_volatile_lvalue	 = Type::is_volatile_lvalue,
						is_volatile_rvalue	 = Type::is_volatile_rvalue
					};

					typedef typename Type<typename Type::to_const_lvalue	       >::flow to_const_lvalue;
					typedef typename Type<typename Type::to_const_rvalue	       >::flow to_const_rvalue;
					typedef typename Type<typename Type::to_const_volatile_lvalue  >::flow to_const_volatile_lvalue;
					typedef typename Type<typename Type::to_const_volatile_rvalue  >::flow to_const_volatile_rvalue;
					typedef typename Type<typename Type::to_lvalue		       >::flow to_lvalue;
					typedef typename Type<typename Type::to_rvalue		       >::flow to_rvalue;
					typedef typename Type<typename Type::to_volatile_lvalue	       >::flow to_volatile_lvalue;
					typedef typename Type<typename Type::to_volatile_rvalue	       >::flow to_volatile_rvalue;
					typedef typename Type<typename Type::add_const_lvalue	       >::flow add_const_lvalue;
					typedef typename Type<typename Type::add_const_rvalue	       >::flow add_const_rvalue;
					typedef typename Type<typename Type::add_const_volatile_lvalue >::flow add_const_volatile_lvalue;
					typedef typename Type<typename Type::add_const_volatile_rvalue >::flow add_const_volatile_rvalue;
					typedef typename Type<typename Type::add_lvalue		       >::flow add_lvalue;
					typedef typename Type<typename Type::add_rvalue		       >::flow add_rvalue;
					typedef typename Type<typename Type::add_volatile_lvalue       >::flow add_volatile_lvalue;
					typedef typename Type<typename Type::add_volatile_rvalue       >::flow add_volatile_rvalue;
					typedef typename Type<typename Type::remove_const_this	       >::flow remove_const_this;
					typedef typename Type<typename Type::remove_const_volatile_this>::flow remove_const_volatile_this;
					typedef typename Type<typename Type::remove_this	       >::flow remove_this;
					typedef typename Type<typename Type::remove_volatile_this      >::flow remove_volatile_this;

#				endif

#			endif

#			if Z_LANGUAGE_HAS(CPP, RVALUE_REFERENCE)

				enum {is_rvalue_reference = Type::is_rvalue_reference};

				typedef typename Type<typename Type::to_rvalue_reference  >::flow to_rvalue_reference;
				typedef typename Type<typename Type::add_rvalue_reference >::flow add_rvalue_reference;

#			endif

#			if Z_HAS(TYPE_UNDERLYING_TYPE)
				typedef typename Type<typename Type::underlying_type>::flow underlying_type;
#			endif

#			if Z_HAS(TYPE_PARAMETERS)
				typedef typename Type::parameters parameters;
#			endif

#			if Z_LANGUAGE_HAS(CPP, TEMPLATE_ALIAS)
				template <class klass> using to_member_pointer = typename Type<typename Type::to_member_pointer<klass> >::flow;
#			endif
		};

#		if Z_COMPILER_HAS_MAGIC_CONSTANT(MANGLED_FUNCTION_NAME) && Z_LANGUAGE_HAS(CPP, RELAXED_CONSTANT_EXPRESSION_FUNCTION)


			static Z_CT_MEMBER(CPP14) USize string_size()
				{return type_string_size<T>();}


			static Z_CT_MEMBER(CPP14) SizedString<string_size()> string()
				{return type_string<T>();}


			static Z_CT_MEMBER(CPP14) Symbol symbol()
				{return Symbol(type_string<T>());}


#			define Z_HAS_TYPE_STRING_SIZE TRUE
#			define Z_HAS_TYPE_STRING      TRUE
#			define Z_HAS_TYPE_SYMBOL      TRUE
#		else
#			define Z_HAS_TYPE_STRING_SIZE FALSE
#			define Z_HAS_TYPE_STRING      FALSE
#			define Z_HAS_TYPE_SYMBOL      FALSE
#		endif
	};

	template <class T> struct TypeClassType	     {typedef typename Type<T>::class_type	type;};
	template <class T> struct TypeElementType    {typedef typename Type<T>::element_type	type;};
	template <class T> struct TypePointeeType    {typedef typename Type<T>::pointee_type	type;};
	template <class T> struct TypeReferencedType {typedef typename Type<T>::referencee_type	type;};
	template <class T> struct TypeReturnType     {typedef typename Type<T>::return_type	type;};

	template <class T> struct TypeToConst		  {typedef typename Type<T>::to_const		   type;};
	template <class T> struct TypeToConstVolatile	  {typedef typename Type<T>::to_const_volatile	   type;};
	template <class T> struct TypeToForwardable	  {typedef typename Type<T>::to_forwardable	   type;};
	template <class T> struct TypeToFunction	  {typedef typename Type<T>::to_function	   type;};
	template <class T> struct TypeToLValueReference	  {typedef typename Type<T>::to_lvalue_reference   type;};
	template <class T> struct TypeToOpaque		  {typedef typename Type<T>::to_opaque		   type;};
	template <class T> struct TypeToPointer		  {typedef typename Type<T>::to_pointer		   type;};
	template <class T> struct TypeToSigned		  {typedef typename Type<T>::to_signed		   type;};
	template <class T> struct TypeToUnqualified	  {typedef typename Type<T>::to_unqualified	   type;};
	template <class T> struct TypeToUnsigned	  {typedef typename Type<T>::to_unsigned	   type;};
	template <class T> struct TypeToVolatile	  {typedef typename Type<T>::to_volatile	   type;};
	template <class T> struct TypeToWrap		  {typedef typename Type<T>::to_wrap		   type;};
	template <class T> struct TypeAddConst		  {typedef typename Type<T>::add_const		   type;};
	template <class T> struct TypeAddConstVolatile	  {typedef typename Type<T>::add_const_volatile	   type;};
	template <class T> struct TypeAddLValueReference  {typedef typename Type<T>::add_lvalue_reference  type;};
	template <class T> struct TypeAddPointer	  {typedef typename Type<T>::add_pointer	   type;};
	template <class T> struct TypeAddVolatile	  {typedef typename Type<T>::add_volatile	   type;};
	template <class T> struct TypeRemoveConst	  {typedef typename Type<T>::remove_const	   type;};
	template <class T> struct TypeRemoveConstVolatile {typedef typename Type<T>::remove_const_volatile type;};
	template <class T> struct TypeRemovePointer	  {typedef typename Type<T>::remove_pointer	   type;};
	template <class T> struct TypeRemoveReference	  {typedef typename Type<T>::remove_reference	   type;};
	template <class T> struct TypeRemoveVolatile	  {typedef typename Type<T>::remove_volatile	   type;};

#	if Z_LANGUAGE_HAS(CPP, RVALUE_REFERENCE)
		template <class T> struct TypeToRValueReference	 {typedef typename Type<T>::to_rvalue_reference	 type;};
		template <class T> struct TypeAddRValueReference {typedef typename Type<T>::add_rvalue_reference type;};
#	endif

#	if Z_LANGUAGE_HAS(CPP, VARIADIC_TEMPLATE) && Z_LANGUAGE_HAS(CPP, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)
		template <class T> struct TypeToConstLValue	      {typedef typename Type<T>::to_const_lvalue	    type;};
		template <class T> struct TypeToConstRValue	      {typedef typename Type<T>::to_const_rvalue	    type;};
		template <class T> struct TypeToConstVolatileLValue   {typedef typename Type<T>::to_const_volatile_lvalue   type;};
		template <class T> struct TypeToConstVolatileRValue   {typedef typename Type<T>::to_const_volatile_rvalue   type;};
		template <class T> struct TypeToLValue		      {typedef typename Type<T>::to_lvalue		    type;};
		template <class T> struct TypeToRValue		      {typedef typename Type<T>::to_rvalue		    type;};
		template <class T> struct TypeToVolatileLValue	      {typedef typename Type<T>::to_volatile_lvalue	    type;};
		template <class T> struct TypeToVolatileRValue	      {typedef typename Type<T>::to_volatile_rvalue	    type;};
		template <class T> struct TypeAddConstLValue	      {typedef typename Type<T>::add_const_lvalue	    type;};
		template <class T> struct TypeAddConstRValue	      {typedef typename Type<T>::add_const_rvalue	    type;};
		template <class T> struct TypeAddConstVolatileLValue  {typedef typename Type<T>::add_const_volatile_lvalue  type;};
		template <class T> struct TypeAddConstVolatileRValue  {typedef typename Type<T>::add_const_volatile_rvalue  type;};
		template <class T> struct TypeAddLValue		      {typedef typename Type<T>::add_lvalue		    type;};
		template <class T> struct TypeAddRValue		      {typedef typename Type<T>::add_rvalue		    type;};
		template <class T> struct TypeAddVolatileLValue	      {typedef typename Type<T>::add_volatile_lvalue	    type;};
		template <class T> struct TypeAddVolatileRValue	      {typedef typename Type<T>::add_volatile_rvalue	    type;};
		template <class T> struct TypeRemoveConstThis	      {typedef typename Type<T>::remove_const_this	    type;};
		template <class T> struct TypeRemoveConstVolatileThis {typedef typename Type<T>::remove_const_volatile_this type;};
		template <class T> struct TypeRemoveThis	      {typedef typename Type<T>::remove_this		    type;};
		template <class T> struct TypeRemoveVolatileThis      {typedef typename Type<T>::remove_volatile_this	    type;};
#	endif

#	if Z_HAS(TYPE_UNDERLYING_TYPE)
		template <class T> struct TypeUnderlyingType {typedef typename Type<T>::underlying_type	type;};
#	endif

#	if Z_HAS(TYPE_PARAMETERS)
		template <class T> struct TypeParameters {typedef typename Type<T>::parameters type;};
#	endif

#	if Z_LANGUAGE_HAS(CPP, TEMPLATE_ALIAS)

		template <class T> using type_class_type      = typename Type<T>::class_type;
		template <class T> using type_element_type    = typename Type<T>::element_type;
		template <class T> using type_pointee_type    = typename Type<T>::pointee_type;
		template <class T> using type_referencee_type = typename Type<T>::referencee_type;
		template <class T> using type_return_type     = typename Type<T>::return_type;

		template <class T> using type_to_const		    = typename Type<T>::to_const;
		template <class T> using type_to_const_volatile	    = typename Type<T>::to_const_volatile;
		template <class T> using type_to_forwardable	    = typename Type<T>::to_forwardable;
		template <class T> using type_to_function	    = typename Type<T>::to_function;
		template <class T> using type_to_lvalue_reference   = typename Type<T>::to_lvalue_reference;
		template <class T> using type_to_opaque		    = typename Type<T>::to_opaque;
		template <class T> using type_to_pointer	    = typename Type<T>::to_pointer;
		template <class T> using type_to_signed		    = typename Type<T>::to_signed;
		template <class T> using type_to_unqualified	    = typename Type<T>::to_unqualified;
		template <class T> using type_to_unsigned	    = typename Type<T>::to_unsigned;
		template <class T> using type_to_volatile	    = typename Type<T>::to_volatile;
		template <class T> using type_to_wrap		    = typename Type<T>::to_wrap;
		template <class T> using type_add_const		    = typename Type<T>::add_const;
		template <class T> using type_add_const_volatile    = typename Type<T>::add_const_volatile;
		template <class T> using type_add_lvalue_reference  = typename Type<T>::add_lvalue_reference;
		template <class T> using type_add_pointer	    = typename Type<T>::add_pointer;
		template <class T> using type_add_volatile	    = typename Type<T>::add_volatile;
		template <class T> using type_remove_const	    = typename Type<T>::remove_const;
		template <class T> using type_remove_const_volatile = typename Type<T>::remove_const_volatile;
		template <class T> using type_remove_pointer	    = typename Type<T>::remove_pointer;
		template <class T> using type_remove_reference	    = typename Type<T>::remove_reference;
		template <class T> using type_remove_volatile	    = typename Type<T>::remove_volatile;

#		if Z_LANGUAGE_HAS(CPP, VARIADIC_TEMPLATE) && Z_LANGUAGE_HAS(CPP, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)
			template <class T> using type_to_const_lvalue		 = typename Type<T>::to_const_lvalue;
			template <class T> using type_to_const_rvalue		 = typename Type<T>::to_const_rvalue;
			template <class T> using type_to_const_volatile_lvalue	 = typename Type<T>::to_const_volatile_lvalue;
			template <class T> using type_to_const_volatile_rvalue	 = typename Type<T>::to_const_volatile_rvalue;
			template <class T> using type_to_lvalue			 = typename Type<T>::to_lvalue;
			template <class T> using type_to_rvalue			 = typename Type<T>::to_rvalue;
			template <class T> using type_to_volatile_lvalue	 = typename Type<T>::to_volatile_lvalue;
			template <class T> using type_to_volatile_rvalue	 = typename Type<T>::to_volatile_rvalue;
			template <class T> using type_add_const_lvalue		 = typename Type<T>::add_const_lvalue;
			template <class T> using type_add_const_rvalue		 = typename Type<T>::add_const_rvalue;
			template <class T> using type_add_const_volatile_lvalue	 = typename Type<T>::add_const_volatile_lvalue;
			template <class T> using type_add_const_volatile_rvalue	 = typename Type<T>::add_const_volatile_rvalue;
			template <class T> using type_add_lvalue		 = typename Type<T>::add_lvalue;
			template <class T> using type_add_rvalue		 = typename Type<T>::add_rvalue;
			template <class T> using type_add_volatile_lvalue	 = typename Type<T>::add_volatile_lvalue;
			template <class T> using type_add_volatile_rvalue	 = typename Type<T>::add_volatile_rvalue;
			template <class T> using type_remove_const_this		 = typename Type<T>::remove_const_this;
			template <class T> using type_remove_const_volatile_this = typename Type<T>::remove_const_volatile_this;
			template <class T> using type_remove_this		 = typename Type<T>::remove_this;
			template <class T> using type_remove_volatile_this	 = typename Type<T>::remove_volatile_this;
#		endif

#		if Z_LANGUAGE_HAS(CPP, RVALUE_REFERENCE)
			template <class T> using type_to_rvalue_reference  = typename Type<T>::to_rvalue_reference;
			template <class T> using type_add_rvalue_reference = typename Type<T>::add_rvalue_reference;
#		endif

#		if Z_HAS(TYPE_PARAMETERS)
			template <class T> using type_parameters = typename Type<T>::parameters;
#		endif

#		if Z_HAS(TYPE_UNDERLYING_TYPE)
			template <class T> using type_underlying_type = typename Type<T>::underlying_type;
#		endif

		template <class T, class klass> using type_to_member_pointer = typename TypeToMemberPointer<T, klass>::type;

#	endif
}

#endif // __Z_traits_Type_HPP__
