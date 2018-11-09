/* Z Kit - traits/Type.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Copyright (C) 2018 Ortega Sosa, Sofía.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_traits_Type_HPP_
#define _Z_traits_Type_HPP_

#include <Z/keys/mathematics/number.h>
#include <Z/inspection/Z.h>
#include <Z/traits/base.hpp>
#include <Z/traits/TernaryType.hpp>
#include <Z/traits/TypeList.hpp>

#if !Z_HAS_TRAIT(TypeList)
#	include <Z/traits/SelectType.hpp>

#	if Z_LANGUAGE_HAS(CPP, VARIADIC_TEMPLATE)
#		include <Z/traits/TypeCount.hpp>
#	endif
#endif

#if	Z_COMPILER_HAS_MAGIC_CONSTANT(MANGLED_FUNCTION_NAME) && \
	Z_LANGUAGE_HAS(CPP, CPP14_RULES_ON_CONSTANT_EXPRESSION_FUNCTION)

#	include <Z/functions/base/type.hpp>
#	include <Z/classes/base/Symbol.hpp>
#endif

// MARK: - Component availability configuration

//-------------------------------------------------.
// Components that are only available if the types |
// to which they refer are supported or enabled.   |
//-------------------------------------------------'

#if Z_UINT8_VALUE_TYPE == Z_VALUE_TYPE_UINT8
#	define Z_HAS_TRAIT_TypeIsUInt8	 TRUE
#	define Z_TRAIT_Type_HAS_is_uint8 TRUE
#else
#	define Z_HAS_TRAIT_TypeIsUInt8	 FALSE
#	define Z_TRAIT_Type_HAS_is_uint8 FALSE
#endif

#if Z_SINT8_VALUE_TYPE == Z_VALUE_TYPE_SINT8
#	define Z_HAS_TRAIT_TypeIsSInt8	 TRUE
#	define Z_TRAIT_Type_HAS_is_sint8 TRUE
#else
#	define Z_HAS_TRAIT_TypeIsSInt8	 FALSE
#	define Z_TRAIT_Type_HAS_is_sint8 FALSE
#endif

#if Z_UINT16_VALUE_TYPE == Z_VALUE_TYPE_UINT16
#	define Z_HAS_TRAIT_TypeIsUInt16	  TRUE
#	define Z_TRAIT_Type_HAS_is_uint16 TRUE
#else
#	define Z_HAS_TRAIT_TypeIsUInt16	  FALSE
#	define Z_TRAIT_Type_HAS_is_uint16 FALSE
#endif

#if Z_SINT16_VALUE_TYPE == Z_VALUE_TYPE_SINT16
#	define Z_HAS_TRAIT_TypeIsSInt16	  TRUE
#	define Z_TRAIT_Type_HAS_is_sint16 TRUE
#else
#	define Z_HAS_TRAIT_TypeIsSInt16	  FALSE
#	define Z_TRAIT_Type_HAS_is_sint16 FALSE
#endif

#if defined(Z_UINT32) && Z_UINT32_VALUE_TYPE == Z_VALUE_TYPE_UINT32
#	define Z_HAS_TRAIT_TypeIsUInt32	  TRUE
#	define Z_TRAIT_Type_HAS_is_uint32 TRUE
#else
#	define Z_HAS_TRAIT_TypeIsUInt32	  FALSE
#	define Z_TRAIT_Type_HAS_is_uint32 FALSE
#endif

#if defined(Z_SINT32) && Z_SINT32_VALUE_TYPE == Z_VALUE_TYPE_SINT32
#	define Z_HAS_TRAIT_TypeIsSInt32	  TRUE
#	define Z_TRAIT_Type_HAS_is_sint32 TRUE
#else
#	define Z_HAS_TRAIT_TypeIsSInt32	  FALSE
#	define Z_TRAIT_Type_HAS_is_sint32 FALSE
#endif

#if defined(Z_UINT64) && Z_UINT64_VALUE_TYPE == Z_VALUE_TYPE_UINT64
#	define Z_HAS_TRAIT_TypeIsUInt64	  TRUE
#	define Z_TRAIT_Type_HAS_is_uint64 TRUE
#else
#	define Z_HAS_TRAIT_TypeIsUInt64	  FALSE
#	define Z_TRAIT_Type_HAS_is_uint64 FALSE
#endif

#if defined(Z_SINT64) && Z_SINT64_VALUE_TYPE == Z_VALUE_TYPE_SINT64
#	define Z_HAS_TRAIT_TypeIsSInt64	  TRUE
#	define Z_TRAIT_Type_HAS_is_sint64 TRUE
#else
#	define Z_HAS_TRAIT_TypeIsSInt64	  FALSE
#	define Z_TRAIT_Type_HAS_is_sint64 FALSE
#endif

#if defined(Z_UINT128) && Z_UINT128_VALUE_TYPE == Z_VALUE_TYPE_UINT128
#	define Z_HAS_TRAIT_TypeIsUInt128   TRUE
#	define Z_TRAIT_Type_HAS_is_uint128 TRUE
#else
#	define Z_HAS_TRAIT_TypeIsUInt128   FALSE
#	define Z_TRAIT_Type_HAS_is_uint128 FALSE
#endif

#if defined(Z_SINT128) && Z_SINT128_VALUE_TYPE == Z_VALUE_TYPE_SINT128
#	define Z_HAS_TRAIT_TypeIsSInt128   TRUE
#	define Z_TRAIT_Type_HAS_is_sint128 TRUE
#else
#	define Z_HAS_TRAIT_TypeIsSInt128   FALSE
#	define Z_TRAIT_Type_HAS_is_sint128 FALSE
#endif

#if defined(Z_FLOAT16) && Z_FLOAT16_VALUE_TYPE == Z_VALUE_TYPE_FLOAT16
#	define Z_HAS_TRAIT_TypeIsFloat16   TRUE
#	define Z_TRAIT_Type_HAS_is_float16 TRUE
#else
#	define Z_HAS_TRAIT_TypeIsFloat16   FALSE
#	define Z_TRAIT_Type_HAS_is_float16 FALSE
#endif

#if defined(Z_FLOAT32) && Z_FLOAT32_VALUE_TYPE == Z_VALUE_TYPE_FLOAT32
#	define Z_HAS_TRAIT_TypeIsFloat32   TRUE
#	define Z_TRAIT_Type_HAS_is_float32 TRUE
#else
#	define Z_HAS_TRAIT_TypeIsFloat32   FALSE
#	define Z_TRAIT_Type_HAS_is_float32 FALSE
#endif

#if defined(Z_FLOAT64) && Z_FLOAT64_VALUE_TYPE == Z_VALUE_TYPE_FLOAT64
#	define Z_HAS_TRAIT_TypeIsFloat64   TRUE
#	define Z_TRAIT_Type_HAS_is_float64 TRUE
#else
#	define Z_HAS_TRAIT_TypeIsFloat64   FALSE
#	define Z_TRAIT_Type_HAS_is_float64 FALSE
#endif

#if defined(Z_FLOAT128) && Z_FLOAT128_VALUE_TYPE == Z_VALUE_TYPE_FLOAT128
#	define Z_HAS_TRAIT_TypeIsFloat128   TRUE
#	define Z_TRAIT_Type_HAS_is_float128 TRUE
#else
#	define Z_HAS_TRAIT_TypeIsFloat128   FALSE
#	define Z_TRAIT_Type_HAS_is_float128 FALSE
#endif

#if defined(Z_FLOAT80_X87) && Z_FLOAT80_X87_VALUE_TYPE == Z_VALUE_TYPE_FLOAT80_X87
#	define Z_HAS_TRAIT_TypeIsFloat80_x87   TRUE
#	define Z_TRAIT_Type_HAS_is_float80_x87 TRUE
#else
#	define Z_HAS_TRAIT_TypeIsFloat80_x87   FALSE
#	define Z_TRAIT_Type_HAS_is_float80_x87 FALSE
#endif

#if defined(Z_FLOAT96_X87) && Z_FLOAT96_X87_VALUE_TYPE == Z_VALUE_TYPE_FLOAT96_X87
#	define Z_HAS_TRAIT_TypeIsFloat96_x87   TRUE
#	define Z_TRAIT_Type_HAS_is_float96_x87 TRUE
#else
#	define Z_HAS_TRAIT_TypeIsFloat96_x87   FALSE
#	define Z_TRAIT_Type_HAS_is_float96_x87 FALSE
#endif

#if defined(Z_FLOAT128_X87) && Z_FLOAT128_X87_VALUE_TYPE == Z_VALUE_TYPE_FLOAT128_X87
#	define Z_HAS_TRAIT_TypeIsFloat128_x87	TRUE
#	define Z_TRAIT_Type_HAS_is_float128_x87 TRUE
#else
#	define Z_HAS_TRAIT_TypeIsFloat128_x87	FALSE
#	define Z_TRAIT_Type_HAS_is_float128_x87 FALSE
#endif

#ifdef Z_LLONG
#	define Z_HAS_TRAIT_TypeIsSLLong	  TRUE
#	define Z_HAS_TRAIT_TypeIsULLong	  TRUE
#	define Z_TRAIT_Type_HAS_is_sllong TRUE
#	define Z_TRAIT_Type_HAS_is_ullong TRUE
#else
#	define Z_HAS_TRAIT_TypeIsSLLong	  FALSE
#	define Z_HAS_TRAIT_TypeIsULLong	  FALSE
#	define Z_TRAIT_Type_HAS_is_sllong FALSE
#	define Z_TRAIT_Type_HAS_is_ullong FALSE
#endif

#ifdef Z_FLOAT
#	define Z_HAS_TRAIT_TypeIsFloat	 TRUE
#	define Z_TRAIT_Type_HAS_is_float TRUE
#else
#	define Z_HAS_TRAIT_TypeIsFloat	 FALSE
#	define Z_TRAIT_Type_HAS_is_float FALSE
#endif

#ifdef Z_DOUBLE
#	define Z_HAS_TRAIT_TypeIsDouble	  TRUE
#	define Z_TRAIT_Type_HAS_is_double TRUE
#else
#	define Z_HAS_TRAIT_TypeIsDouble	  FALSE
#	define Z_TRAIT_Type_HAS_is_double FALSE
#endif

#ifdef Z_LDOUBLE
#	define Z_HAS_TRAIT_TypeIsLDouble   TRUE
#	define Z_TRAIT_Type_HAS_is_ldouble TRUE
#else
#	define Z_HAS_TRAIT_TypeIsLDouble   FALSE
#	define Z_TRAIT_Type_HAS_is_ldouble FALSE
#endif

#if Z_LANGUAGE_HAS_TYPE(CPP, BOOLEAN)
#	define Z_HAS_TRAIT_TypeIsBoolean   TRUE
#	define Z_TRAIT_Type_HAS_is_boolean TRUE
#else
#	define Z_HAS_TRAIT_TypeIsBoolean   FALSE
#	define Z_TRAIT_Type_HAS_is_boolean FALSE
#endif

/*#if Z_LANGUAGE_HAS_TYPE(CPP, WCHAR)
#	define Z_HAS_TRAIT_TypeIsWChar	TRUE
#	define Z_TRAIT_Type_HAS_is_wchar TRUE
#else
#	define Z_HAS_TRAIT_TypeIsWChar	 FALSE
#	define Z_TRAIT_Type_HAS_is_wchar FALSE
#endif

#if Z_LANGUAGE_HAS_TYPE(CPP, CHAR16)
#	define Z_HAS_TRAIT_TypeIsChar16	  TRUE
#	define Z_TRAIT_Type_HAS_is_char16 TRUE
#else
#	define Z_HAS_TRAIT_TypeIsChar16	  FALSE
#	define Z_TRAIT_Type_HAS_is_char16 FALSE
#endif

#if Z_LANGUAGE_HAS_TYPE(CPP, CHAR32)
#	define Z_HAS_TRAIT_TypeIsChar32	  TRUE
#	define Z_TRAIT_Type_HAS_is_char32 TRUE
#else
#	define Z_HAS_TRAIT_TypeIsChar32	  FALSE
#	define Z_TRAIT_Type_HAS_is_char32 FALSE
#endif*/

#if Z_LANGUAGE_HAS_SPECIFIER(CPP, DECLARED_TYPE) && Z_LANGUAGE_HAS_LITERAL(CPP, NULL_POINTER)
#	define Z_HAS_TRAIT_TypeIsNullPointer	TRUE
#	define Z_TRAIT_Type_HAS_is_null_pointer TRUE
#else
#	define Z_HAS_TRAIT_TypeIsNullPointer	FALSE
#	define Z_TRAIT_Type_HAS_is_null_pointer FALSE
#endif

//--------------------------------------------------------.
// Components that are only available if the language	  |
// features to which they refer are supported or enabled. |
//--------------------------------------------------------'

#if Z_LANGUAGE_HAS(CPP, RVALUE_REFERENCE)
#	define Z_HAS_TRAIT_TypeIsFunctionRValueReference     TRUE
#	define Z_HAS_TRAIT_TypeIsRValueReference	     TRUE
#	define Z_HAS_TRAIT_TypeAddRValueReference	     TRUE
#	define Z_HAS_TRAIT_TypeToRValueReference	     TRUE
#	define Z_TRAIT_Type_HAS_is_function_rvalue_reference TRUE
#	define Z_TRAIT_Type_HAS_is_rvalue_reference	     TRUE
#	define Z_TRAIT_Type_HAS_add_rvalue_reference	     TRUE
#	define Z_TRAIT_Type_HAS_to_rvalue_reference	     TRUE
#else
#	define Z_HAS_TRAIT_TypeIsFunctionRValueReference     FALSE
#	define Z_HAS_TRAIT_TypeIsRValueReference	     FALSE
#	define Z_HAS_TRAIT_TypeAddRValueReference	     FALSE
#	define Z_HAS_TRAIT_TypeToRValueReference	     FALSE
#	define Z_TRAIT_Type_HAS_is_function_rvalue_reference FALSE
#	define Z_TRAIT_Type_HAS_is_rvalue_reference	     FALSE
#	define Z_TRAIT_Type_HAS_add_rvalue_reference	     FALSE
#	define Z_TRAIT_Type_HAS_to_rvalue_reference	     FALSE
#endif

#if Z_LANGUAGE_HAS(CPP, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)
#	define Z_HAS_TRAIT_TypeIsConstLValue		   TRUE
#	define Z_HAS_TRAIT_TypeIsConstRValue		   TRUE
#	define Z_HAS_TRAIT_TypeIsConstVolatileLValue	   TRUE
#	define Z_HAS_TRAIT_TypeIsConstVolatileRValue	   TRUE
#	define Z_HAS_TRAIT_TypeIsLValue			   TRUE
#	define Z_HAS_TRAIT_TypeIsRValue			   TRUE
#	define Z_HAS_TRAIT_TypeIsVolatileLValue		   TRUE
#	define Z_HAS_TRAIT_TypeIsVolatileRValue		   TRUE
#	define Z_HAS_TRAIT_TypeAddConstLValue		   TRUE
#	define Z_HAS_TRAIT_TypeAddConstRValue		   TRUE
#	define Z_HAS_TRAIT_TypeAddConstVolatileLValue	   TRUE
#	define Z_HAS_TRAIT_TypeAddConstVolatileRValue	   TRUE
#	define Z_HAS_TRAIT_TypeAddLValue		   TRUE
#	define Z_HAS_TRAIT_TypeAddRValue		   TRUE
#	define Z_HAS_TRAIT_TypeAddVolatileLValue	   TRUE
#	define Z_HAS_TRAIT_TypeAddVolatileRValue	   TRUE
#	define Z_HAS_TRAIT_TypeRemoveConstThis		   TRUE
#	define Z_HAS_TRAIT_TypeRemoveConstVolatileThis	   TRUE
#	define Z_HAS_TRAIT_TypeRemoveThis		   TRUE
#	define Z_HAS_TRAIT_TypeRemoveVolatileThis	   TRUE
#	define Z_HAS_TRAIT_TypeToConstLValue		   TRUE
#	define Z_HAS_TRAIT_TypeToConstRValue		   TRUE
#	define Z_HAS_TRAIT_TypeToConstVolatileLValue	   TRUE
#	define Z_HAS_TRAIT_TypeToConstVolatileRValue	   TRUE
#	define Z_HAS_TRAIT_TypeToLValue			   TRUE
#	define Z_HAS_TRAIT_TypeToRValue			   TRUE
#	define Z_HAS_TRAIT_TypeToVolatileLValue		   TRUE
#	define Z_HAS_TRAIT_TypeToVolatileRValue		   TRUE
#	define Z_TRAIT_Type_HAS_is_const_lvalue		   TRUE
#	define Z_TRAIT_Type_HAS_is_const_rvalue		   TRUE
#	define Z_TRAIT_Type_HAS_is_const_volatile_lvalue   TRUE
#	define Z_TRAIT_Type_HAS_is_const_volatile_rvalue   TRUE
#	define Z_TRAIT_Type_HAS_is_lvalue		   TRUE
#	define Z_TRAIT_Type_HAS_is_rvalue		   TRUE
#	define Z_TRAIT_Type_HAS_is_volatile_lvalue	   TRUE
#	define Z_TRAIT_Type_HAS_is_volatile_rvalue	   TRUE
#	define Z_TRAIT_Type_HAS_add_const_lvalue	   TRUE
#	define Z_TRAIT_Type_HAS_add_const_rvalue	   TRUE
#	define Z_TRAIT_Type_HAS_add_const_volatile_lvalue  TRUE
#	define Z_TRAIT_Type_HAS_add_const_volatile_rvalue  TRUE
#	define Z_TRAIT_Type_HAS_add_lvalue		   TRUE
#	define Z_TRAIT_Type_HAS_add_rvalue		   TRUE
#	define Z_TRAIT_Type_HAS_add_volatile_lvalue	   TRUE
#	define Z_TRAIT_Type_HAS_add_volatile_rvalue	   TRUE
#	define Z_TRAIT_Type_HAS_remove_const_this	   TRUE
#	define Z_TRAIT_Type_HAS_remove_const_volatile_this TRUE
#	define Z_TRAIT_Type_HAS_remove_this		   TRUE
#	define Z_TRAIT_Type_HAS_remove_volatile_this	   TRUE
#	define Z_TRAIT_Type_HAS_to_const_lvalue		   TRUE
#	define Z_TRAIT_Type_HAS_to_const_rvalue		   TRUE
#	define Z_TRAIT_Type_HAS_to_const_volatile_lvalue   TRUE
#	define Z_TRAIT_Type_HAS_to_const_volatile_rvalue   TRUE
#	define Z_TRAIT_Type_HAS_to_lvalue		   TRUE
#	define Z_TRAIT_Type_HAS_to_rvalue		   TRUE
#	define Z_TRAIT_Type_HAS_to_volatile_lvalue	   TRUE
#	define Z_TRAIT_Type_HAS_to_volatile_rvalue	   TRUE
#else
#	define Z_HAS_TRAIT_TypeIsConstLValue		   FALSE
#	define Z_HAS_TRAIT_TypeIsConstRValue		   FALSE
#	define Z_HAS_TRAIT_TypeIsConstVolatileLValue	   FALSE
#	define Z_HAS_TRAIT_TypeIsConstVolatileRValue	   FALSE
#	define Z_HAS_TRAIT_TypeIsLValue			   FALSE
#	define Z_HAS_TRAIT_TypeIsRValue			   FALSE
#	define Z_HAS_TRAIT_TypeIsVolatileLValue		   FALSE
#	define Z_HAS_TRAIT_TypeIsVolatileRValue		   FALSE
#	define Z_HAS_TRAIT_TypeAddConstLValue		   FALSE
#	define Z_HAS_TRAIT_TypeAddConstRValue		   FALSE
#	define Z_HAS_TRAIT_TypeAddConstVolatileLValue	   FALSE
#	define Z_HAS_TRAIT_TypeAddConstVolatileRValue	   FALSE
#	define Z_HAS_TRAIT_TypeAddLValue		   FALSE
#	define Z_HAS_TRAIT_TypeAddRValue		   FALSE
#	define Z_HAS_TRAIT_TypeAddVolatileLValue	   FALSE
#	define Z_HAS_TRAIT_TypeAddVolatileRValue	   FALSE
#	define Z_HAS_TRAIT_TypeRemoveConstThis		   FALSE
#	define Z_HAS_TRAIT_TypeRemoveConstVolatileThis	   FALSE
#	define Z_HAS_TRAIT_TypeRemoveThis		   FALSE
#	define Z_HAS_TRAIT_TypeRemoveVolatileThis	   FALSE
#	define Z_HAS_TRAIT_TypeToConstLValue		   FALSE
#	define Z_HAS_TRAIT_TypeToConstRValue		   FALSE
#	define Z_HAS_TRAIT_TypeToConstVolatileLValue	   FALSE
#	define Z_HAS_TRAIT_TypeToConstVolatileRValue	   FALSE
#	define Z_HAS_TRAIT_TypeToLValue			   FALSE
#	define Z_HAS_TRAIT_TypeToRValue			   FALSE
#	define Z_HAS_TRAIT_TypeToVolatileLValue		   FALSE
#	define Z_HAS_TRAIT_TypeToVolatileRValue		   FALSE
#	define Z_TRAIT_Type_HAS_is_const_lvalue		   FALSE
#	define Z_TRAIT_Type_HAS_is_const_rvalue		   FALSE
#	define Z_TRAIT_Type_HAS_is_const_volatile_lvalue   FALSE
#	define Z_TRAIT_Type_HAS_is_const_volatile_rvalue   FALSE
#	define Z_TRAIT_Type_HAS_is_lvalue		   FALSE
#	define Z_TRAIT_Type_HAS_is_rvalue		   FALSE
#	define Z_TRAIT_Type_HAS_is_volatile_lvalue	   FALSE
#	define Z_TRAIT_Type_HAS_is_volatile_rvalue	   FALSE
#	define Z_TRAIT_Type_HAS_add_const_lvalue	   FALSE
#	define Z_TRAIT_Type_HAS_add_const_rvalue	   FALSE
#	define Z_TRAIT_Type_HAS_add_const_volatile_lvalue  FALSE
#	define Z_TRAIT_Type_HAS_add_const_volatile_rvalue  FALSE
#	define Z_TRAIT_Type_HAS_add_lvalue		   FALSE
#	define Z_TRAIT_Type_HAS_add_rvalue		   FALSE
#	define Z_TRAIT_Type_HAS_add_volatile_lvalue	   FALSE
#	define Z_TRAIT_Type_HAS_add_volatile_rvalue	   FALSE
#	define Z_TRAIT_Type_HAS_remove_const_this	   FALSE
#	define Z_TRAIT_Type_HAS_remove_const_volatile_this FALSE
#	define Z_TRAIT_Type_HAS_remove_this		   FALSE
#	define Z_TRAIT_Type_HAS_remove_volatile_this	   FALSE
#	define Z_TRAIT_Type_HAS_to_const_lvalue		   FALSE
#	define Z_TRAIT_Type_HAS_to_const_rvalue		   FALSE
#	define Z_TRAIT_Type_HAS_to_const_volatile_lvalue   FALSE
#	define Z_TRAIT_Type_HAS_to_const_volatile_rvalue   FALSE
#	define Z_TRAIT_Type_HAS_to_lvalue		   FALSE
#	define Z_TRAIT_Type_HAS_to_rvalue		   FALSE
#	define Z_TRAIT_Type_HAS_to_volatile_lvalue	   FALSE
#	define Z_TRAIT_Type_HAS_to_volatile_rvalue	   FALSE
#endif

//------------------------------------------------.
// Components that need compiler built-in traits. |
// There are no known workarounds.		  |
//------------------------------------------------'

#if Z_COMPILER_HAS_TRAIT(TYPE_HAS_VIRTUAL_DESTRUCTOR)
#	define Z_HAS_TRAIT_TypeHasVirtualDestructor    TRUE
#	define Z_TRAIT_Type_HAS_has_virtual_destructor TRUE
#else
#	define Z_HAS_TRAIT_TypeHasVirtualDestructor    FALSE
#	define Z_TRAIT_Type_HAS_has_virtual_destructor FALSE
#endif

#if Z_COMPILER_HAS_TRAIT(TYPE_IS_ABSTRACT)
#	define Z_HAS_TRAIT_TypeIsAbstract   TRUE
#	define Z_TRAIT_Type_HAS_is_abstract TRUE
#else
#	define Z_HAS_TRAIT_TypeIsAbstract   FALSE
#	define Z_TRAIT_Type_HAS_is_abstract FALSE
#endif

#if Z_COMPILER_HAS_TRAIT(TYPE_IS_AGGREGATE)
#	define Z_HAS_TRAIT_TypeIsAggregate   TRUE
#	define Z_TRAIT_Type_HAS_is_aggregate TRUE
#else
#	define Z_HAS_TRAIT_TypeIsAggregate   FALSE
#	define Z_TRAIT_Type_HAS_is_aggregate FALSE
#endif

#if Z_COMPILER_HAS_TRAIT(TYPE_IS_ASSIGNABLE)
#	define Z_HAS_TRAIT_TypeIsAssignable TRUE
#else
#	define Z_HAS_TRAIT_TypeIsAssignable FALSE
#endif

#if Z_COMPILER_HAS_TRAIT(TYPE_IS_BASE)
#	define Z_HAS_TRAIT_TypeIsBase TRUE
#else
#	define Z_HAS_TRAIT_TypeIsBase FALSE
#endif

#if Z_COMPILER_HAS_TRAIT(TYPE_IS_CONVERTIBLE)
#	define Z_HAS_TRAIT_TypeIsConvertible TRUE
#else
#	define Z_HAS_TRAIT_TypeIsConvertible FALSE
#endif

#if Z_COMPILER_HAS_TRAIT(TYPE_IS_FINAL)
#	define Z_HAS_TRAIT_TypeIsFinal	 TRUE
#	define Z_TRAIT_Type_HAS_is_final TRUE
#else
#	define Z_HAS_TRAIT_TypeIsFinal	 FALSE
#	define Z_TRAIT_Type_HAS_is_final FALSE
#endif

#if Z_COMPILER_HAS_TRAIT(TYPE_IS_INTERFACE_CLASS)
#	define Z_HAS_TRAIT_TypeIsInterfaceClass	   TRUE
#	define Z_TRAIT_Type_HAS_is_interface_class TRUE
#else
#	define Z_HAS_TRAIT_TypeIsInterfaceClass	   FALSE
#	define Z_TRAIT_Type_HAS_is_interface_class FALSE
#endif

#if Z_COMPILER_HAS_TRAIT(TYPE_IS_LITERAL)
#	define Z_HAS_TRAIT_TypeIsLiteral   TRUE
#	define Z_TRAIT_Type_HAS_is_literal TRUE
#else
#	define Z_HAS_TRAIT_TypeIsLiteral   FALSE
#	define Z_TRAIT_Type_HAS_is_literal FALSE
#endif

#if Z_COMPILER_HAS_TRAIT(TYPE_IS_NOTHROW_ASSIGNABLE)
#	define Z_HAS_TRAIT_TypeIsNothrowAssignable TRUE
#else
#	define Z_HAS_TRAIT_TypeIsNothrowAssignable FALSE
#endif

#if Z_COMPILER_HAS_TRAIT(TYPE_IS_POD)
#	define Z_HAS_TRAIT_TypeIsPOD   TRUE
#	define Z_TRAIT_Type_HAS_is_pod TRUE
#else
#	define Z_HAS_TRAIT_TypeIsPOD   FALSE
#	define Z_TRAIT_Type_HAS_is_pod FALSE
#endif

#if Z_COMPILER_HAS_TRAIT(TYPE_IS_POLYMORPHIC)
#	define Z_HAS_TRAIT_TypeIsPolymorphic   TRUE
#	define Z_TRAIT_Type_HAS_is_polymorphic TRUE
#else
#	define Z_HAS_TRAIT_TypeIsPolymorphic   FALSE
#	define Z_TRAIT_Type_HAS_is_polymorphic FALSE
#endif

#if Z_COMPILER_HAS_TRAIT(TYPE_IS_TRIVIALLY_ASSIGNABLE)
#	define Z_HAS_TRAIT_TypeIsTriviallyAssignable TRUE
#else
#	define Z_HAS_TRAIT_TypeIsTriviallyAssignable FALSE
#endif

#if Z_COMPILER_HAS_TRAIT(TYPE_IS_TRIVIALLY_COPY_ASSIGNABLE)
#	define Z_HAS_TRAIT_TypeIsTriviallyCopyAssignable     TRUE
#	define Z_TRAIT_Type_HAS_is_trivially_copy_assignable TRUE
#else
#	define Z_HAS_TRAIT_TypeIsTriviallyCopyAssignable     FALSE
#	define Z_TRAIT_Type_HAS_is_trivially_copy_assignable FALSE
#endif

#if Z_COMPILER_HAS_TRAIT(TYPE_IS_TRIVIALLY_COPY_CONSTRUCTIBLE)
#	define Z_HAS_TRAIT_TypeIsTriviallyCopyConstructible	TRUE
#	define Z_TRAIT_Type_HAS_is_trivially_copy_constructible TRUE
#else
#	define Z_HAS_TRAIT_TypeIsTriviallyCopyConstructible	FALSE
#	define Z_TRAIT_Type_HAS_is_trivially_copy_constructible FALSE
#endif

#if Z_COMPILER_HAS_TRAIT(TYPE_IS_TRIVIALLY_COPYABLE)
#	define Z_HAS_TRAIT_TypeIsTriviallyCopyable    TRUE
#	define Z_TRAIT_Type_HAS_is_trivially_copyable TRUE
#else
#	define Z_HAS_TRAIT_TypeIsTriviallyCopyable    FALSE
#	define Z_TRAIT_Type_HAS_is_trivially_copyable FALSE
#endif

#if Z_COMPILER_HAS_TRAIT(TYPE_IS_TRIVIALLY_DEFAULT_CONSTRUCTIBLE)
#	define Z_HAS_TRAIT_TypeIsTriviallyDefaultConstructible	   TRUE
#	define Z_TRAIT_Type_HAS_is_trivially_default_constructible TRUE
#else
#	define Z_HAS_TRAIT_TypeIsTriviallyDefaultConstructible	   FALSE
#	define Z_TRAIT_Type_HAS_is_trivially_default_constructible FALSE
#endif

#if Z_COMPILER_HAS_TRAIT(TYPE_IS_TRIVIALLY_DESTRUCTIBLE)
#	define Z_HAS_TRAIT_TypeIsTriviallyDestructible	  TRUE
#	define Z_TRAIT_Type_HAS_is_trivially_destructible TRUE
#else
#	define Z_HAS_TRAIT_TypeIsTriviallyDestructible	  FALSE
#	define Z_TRAIT_Type_HAS_is_trivially_destructible FALSE
#endif

#if Z_COMPILER_HAS_TRAIT(TYPE_IS_UNION)
#	define Z_HAS_TRAIT_TypeIsUnion	 TRUE
#	define Z_TRAIT_Type_HAS_is_union TRUE
#else
#	define Z_HAS_TRAIT_TypeIsUnion	 FALSE
#	define Z_TRAIT_Type_HAS_is_union FALSE
#endif

#if Z_COMPILER_HAS_TRAIT(TYPE_UNDERLYING_TYPE)
#	define Z_HAS_TRAIT_TypeUnderlyingType	TRUE
#	define Z_TRAIT_Type_HAS_underlying_type TRUE
#else
#	define Z_HAS_TRAIT_TypeUnderlyingType	FALSE
#	define Z_TRAIT_Type_HAS_underlying_type FALSE
#endif

//-----------------------------------------------------------.
// Components that need compiler built-in traits in addition |
// to some C++11 features. There are no known workarounds.   |
//-----------------------------------------------------------'

#if Z_LANGUAGE_HAS(CPP, VARIADIC_TEMPLATE) && Z_COMPILER_HAS_TRAIT(TYPE_IS_CONSTRUCTIBLE)
#	define Z_HAS_TRAIT_TypeIsConstructible TRUE
#else
#	define Z_HAS_TRAIT_TypeIsConstructible FALSE
#endif

#if Z_LANGUAGE_HAS(CPP, VARIADIC_TEMPLATE) && Z_COMPILER_HAS_TRAIT(TYPE_IS_NOTHROW_CONSTRUCTIBLE)
#	define Z_HAS_TRAIT_TypeIsNothrowConstructible TRUE
#else
#	define Z_HAS_TRAIT_TypeIsNothrowConstructible FALSE
#endif

#if Z_LANGUAGE_HAS(CPP, VARIADIC_TEMPLATE) && Z_COMPILER_HAS_TRAIT(TYPE_IS_TRIVIALLY_CONSTRUCTIBLE)
#	define Z_HAS_TRAIT_TypeIsTriviallyConstructible TRUE
#else
#	define Z_HAS_TRAIT_TypeIsTriviallyConstructible FALSE
#endif

//-------------------------------------------------------------.
// Components that use built-in compiler traits if available.  |
// If not, they use workarounds that need some C++11 features. |
//-------------------------------------------------------------'

#if Z_COMPILER_HAS_TRAIT(TYPE_IS_ENUMERATION) || Z_LANGUAGE_HAS(CPP, EXPRESSION_SFINAE)
#	define Z_HAS_TRAIT_TypeIsEnumeration   TRUE
#	define Z_TRAIT_Type_HAS_is_enumeration TRUE
#else
#	define Z_HAS_TRAIT_TypeIsEnumeration   FALSE
#	define Z_TRAIT_Type_HAS_is_enumeration FALSE
#endif

//-------------------------------------------.
// Components that need some C++11 features. |
//-------------------------------------------'

#if Z_LANGUAGE_HAS(CPP, EXPRESSION_SFINAE)
#	define Z_HAS_TRAIT_TypeIsComplete   TRUE
#	define Z_HAS_TRAIT_TypeIsIncomplete TRUE
#else
#	define Z_HAS_TRAIT_TypeIsComplete   FALSE
#	define Z_HAS_TRAIT_TypeIsIncomplete FALSE
#endif

#if Z_LANGUAGE_HAS(CPP, EXPRESSION_SFINAE) && Z_LANGUAGE_HAS_SPECIFIER(CPP, DECLARED_TYPE)
#	define Z_HAS_TRAIT_TypeIsDefaultConstructible	 TRUE
#	define Z_TRAIT_Type_HAS_is_default_constructible TRUE
#else
#	define Z_HAS_TRAIT_TypeIsDefaultConstructible	 FALSE
#	define Z_TRAIT_Type_HAS_is_default_constructible FALSE
#endif

#if Z_LANGUAGE_HAS(CPP, EXPRESSION_SFINAE) && Z_LANGUAGE_HAS_SPECIFIER(CPP, DECLARED_TYPE)
#	define Z_HAS_TRAIT_TypeIsFunctional TRUE
#	define Z_HAS_TRAIT_TypeIsFunctor    TRUE
#else
#	define Z_HAS_TRAIT_TypeIsFunctional FALSE
#	define Z_HAS_TRAIT_TypeIsFunctor    TRUE
#endif

#if Z_LANGUAGE_HAS(CPP, VARIADIC_TEMPLATE_EXTENDED_PARAMETERS)
#	define Z_HAS_TRAIT_TypeIsTemplate   TRUE
#	define Z_TRAIT_Type_HAS_is_template TRUE
#else
#	define Z_HAS_TRAIT_TypeIsTemplate   FALSE
#	define Z_TRAIT_Type_HAS_is_template FALSE
#endif

#if Z_HAS_TRAIT(TypeList)
#	define Z_HAS_TRAIT_TypeParameters  TRUE
#	define Z_TRAIT_Type_HAS_parameters TRUE
#else
#	define Z_HAS_TRAIT_TypeParameters  FALSE
#	define Z_TRAIT_Type_HAS_parameters FALSE
#endif

//-------------------------------------------------------------------------.
// Components that need some C++14 features in addition to compiler magic. |
//-------------------------------------------------------------------------'

#if	Z_COMPILER_HAS_MAGIC_CONSTANT(MANGLED_FUNCTION_NAME) && \
	Z_LANGUAGE_HAS(CPP, CPP14_RULES_ON_CONSTANT_EXPRESSION_FUNCTION)

#	define Z_TRAIT_Type_HAS_string		 TRUE
#	define Z_TRAIT_Type_HAS_symbol		 TRUE
#	define Z_TRAIT_Type_HAS_type_string_size TRUE
#else
#	define Z_TRAIT_Type_HAS_string		 FALSE
#	define Z_TRAIT_Type_HAS_symbol		 FALSE
#	define Z_TRAIT_Type_HAS_type_string_size FALSE
#endif

//------------------------------------------------------.
// Components that are only available in Objective-C++. |
//------------------------------------------------------'

#if Z_LANGUAGE_INCLUDES(OBJECTIVE_CPP)
#	define Z_HAS_TRAIT_TypeIsObjectiveCClass	      TRUE
#	define Z_HAS_TRAIT_TypeIsObjectiveCClassPointer	      TRUE
#	define Z_HAS_TRAIT_TypeIsObjectiveCObject	      TRUE
#	define Z_HAS_TRAIT_TypeIsObjectiveCObjectPointer      TRUE
#	define Z_TRAIT_Type_HAS_is_objective_c_class	      TRUE
#	define Z_TRAIT_Type_HAS_is_objective_c_class_pointer  TRUE
#	define Z_TRAIT_Type_HAS_is_objective_c_object	      TRUE
#	define Z_TRAIT_Type_HAS_is_objective_c_object_pointer TRUE
#else
#	define Z_HAS_TRAIT_TypeIsObjectiveCClass	      FALSE
#	define Z_HAS_TRAIT_TypeIsObjectiveCClassPointer	      FALSE
#	define Z_HAS_TRAIT_TypeIsObjectiveCObject	      FALSE
#	define Z_HAS_TRAIT_TypeIsObjectiveCObjectPointer      FALSE
#	define Z_TRAIT_Type_HAS_is_objective_c_class	      FALSE
#	define Z_TRAIT_Type_HAS_is_objective_c_class_pointer  FALSE
#	define Z_TRAIT_Type_HAS_is_objective_c_object	      FALSE
#	define Z_TRAIT_Type_HAS_is_objective_c_object_pointer FALSE
#endif

//-----------------------------------------------------.
// Components that are only available in Objective-C++ |
// and that need some C++11 features.		       |
//-----------------------------------------------------'

#if Z_LANGUAGE_INCLUDES(OBJECTIVE_CPP) && Z_LANGUAGE_HAS(CPP, EXPRESSION_SFINAE)
#	define Z_HAS_TRAIT_TypeIsObjectiveCInstance		TRUE
#	define Z_HAS_TRAIT_TypeIsObjectiveCInstancePointer	TRUE
#	define Z_TRAIT_Type_HAS_is_objective_c_instance		TRUE
#	define Z_TRAIT_Type_HAS_is_objective_c_instance_pointer TRUE
#else
#	define Z_HAS_TRAIT_TypeIsObjectiveCInstance		FALSE
#	define Z_HAS_TRAIT_TypeIsObjectiveCInstancePointer	FALSE
#	define Z_TRAIT_Type_HAS_is_objective_c_instance		FALSE
#	define Z_TRAIT_Type_HAS_is_objective_c_instance_pointer FALSE
#endif

//-------------------------------------------------------------------.
// Aliases that are only available if the language supports template |
// aliases and the component to which they refer is also available.  |
//-------------------------------------------------------------------'

#if Z_LANGUAGE_HAS(CPP, TEMPLATE_ALIAS)
#	define Z_TRAIT_Type_HAS_to_member_pointer	    TRUE
#	define Z_HAS_TRAIT_ALIAS_type_add_const		    TRUE
#	define Z_HAS_TRAIT_ALIAS_type_add_const_volatile    TRUE
#	define Z_HAS_TRAIT_ALIAS_type_add_lvalue_reference  TRUE
#	define Z_HAS_TRAIT_ALIAS_type_add_pointer	    TRUE
#	define Z_HAS_TRAIT_ALIAS_type_add_volatile	    TRUE
#	define Z_HAS_TRAIT_ALIAS_type_class_type	    TRUE
#	define Z_HAS_TRAIT_ALIAS_type_element_type	    TRUE
#	define Z_HAS_TRAIT_ALIAS_type_pointee_type	    TRUE
#	define Z_HAS_TRAIT_ALIAS_type_referencee_type	    TRUE
#	define Z_HAS_TRAIT_ALIAS_type_remove_const	    TRUE
#	define Z_HAS_TRAIT_ALIAS_type_remove_const_volatile TRUE
#	define Z_HAS_TRAIT_ALIAS_type_remove_pointer	    TRUE
#	define Z_HAS_TRAIT_ALIAS_type_remove_reference	    TRUE
#	define Z_HAS_TRAIT_ALIAS_type_remove_volatile	    TRUE
#	define Z_HAS_TRAIT_ALIAS_type_return_type	    TRUE
#	define Z_HAS_TRAIT_ALIAS_type_to_const		    TRUE
#	define Z_HAS_TRAIT_ALIAS_type_to_const_volatile	    TRUE
#	define Z_HAS_TRAIT_ALIAS_type_to_forwardable	    TRUE
#	define Z_HAS_TRAIT_ALIAS_type_to_function	    TRUE
#	define Z_HAS_TRAIT_ALIAS_type_to_lvalue_reference   TRUE
#	define Z_HAS_TRAIT_ALIAS_type_to_member_pointer	    TRUE
#	define Z_HAS_TRAIT_ALIAS_type_to_opaque		    TRUE
#	define Z_HAS_TRAIT_ALIAS_type_to_pointer	    TRUE
#	define Z_HAS_TRAIT_ALIAS_type_to_signed		    TRUE
#	define Z_HAS_TRAIT_ALIAS_type_to_unqualified	    TRUE
#	define Z_HAS_TRAIT_ALIAS_type_to_unsigned	    TRUE
#	define Z_HAS_TRAIT_ALIAS_type_to_volatile	    TRUE
#	define Z_HAS_TRAIT_ALIAS_type_to_wrap		    TRUE
#else
#	define Z_TRAIT_Type_HAS_to_member_pointer	    FALSE
#	define Z_HAS_TRAIT_ALIAS_type_add_const		    FALSE
#	define Z_HAS_TRAIT_ALIAS_type_add_const_volatile    FALSE
#	define Z_HAS_TRAIT_ALIAS_type_add_lvalue_reference  FALSE
#	define Z_HAS_TRAIT_ALIAS_type_add_pointer	    FALSE
#	define Z_HAS_TRAIT_ALIAS_type_add_volatile	    FALSE
#	define Z_HAS_TRAIT_ALIAS_type_class_type	    FALSE
#	define Z_HAS_TRAIT_ALIAS_type_element_type	    FALSE
#	define Z_HAS_TRAIT_ALIAS_type_pointee_type	    FALSE
#	define Z_HAS_TRAIT_ALIAS_type_referencee_type	    FALSE
#	define Z_HAS_TRAIT_ALIAS_type_remove_const	    FALSE
#	define Z_HAS_TRAIT_ALIAS_type_remove_const_volatile FALSE
#	define Z_HAS_TRAIT_ALIAS_type_remove_pointer	    FALSE
#	define Z_HAS_TRAIT_ALIAS_type_remove_reference	    FALSE
#	define Z_HAS_TRAIT_ALIAS_type_remove_volatile	    FALSE
#	define Z_HAS_TRAIT_ALIAS_type_return_type	    FALSE
#	define Z_HAS_TRAIT_ALIAS_type_to_const		    FALSE
#	define Z_HAS_TRAIT_ALIAS_type_to_const_volatile	    FALSE
#	define Z_HAS_TRAIT_ALIAS_type_to_forwardable	    FALSE
#	define Z_HAS_TRAIT_ALIAS_type_to_function	    FALSE
#	define Z_HAS_TRAIT_ALIAS_type_to_lvalue_reference   FALSE
#	define Z_HAS_TRAIT_ALIAS_type_to_member_pointer	    FALSE
#	define Z_HAS_TRAIT_ALIAS_type_to_opaque		    FALSE
#	define Z_HAS_TRAIT_ALIAS_type_to_pointer	    FALSE
#	define Z_HAS_TRAIT_ALIAS_type_to_signed		    FALSE
#	define Z_HAS_TRAIT_ALIAS_type_to_unqualified	    FALSE
#	define Z_HAS_TRAIT_ALIAS_type_to_unsigned	    FALSE
#	define Z_HAS_TRAIT_ALIAS_type_to_volatile	    FALSE
#	define Z_HAS_TRAIT_ALIAS_type_to_wrap		    FALSE
#endif

#if	Z_LANGUAGE_HAS(CPP, TEMPLATE_ALIAS) && \
	Z_LANGUAGE_HAS(CPP, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)

#	define Z_HAS_TRAIT_ALIAS_type_add_const_lvalue		 TRUE
#	define Z_HAS_TRAIT_ALIAS_type_add_const_rvalue		 TRUE
#	define Z_HAS_TRAIT_ALIAS_type_add_const_volatile_lvalue	 TRUE
#	define Z_HAS_TRAIT_ALIAS_type_add_const_volatile_rvalue	 TRUE
#	define Z_HAS_TRAIT_ALIAS_type_add_lvalue		 TRUE
#	define Z_HAS_TRAIT_ALIAS_type_add_rvalue		 TRUE
#	define Z_HAS_TRAIT_ALIAS_type_add_volatile_lvalue	 TRUE
#	define Z_HAS_TRAIT_ALIAS_type_add_volatile_rvalue	 TRUE
#	define Z_HAS_TRAIT_ALIAS_type_remove_const_this		 TRUE
#	define Z_HAS_TRAIT_ALIAS_type_remove_const_volatile_this TRUE
#	define Z_HAS_TRAIT_ALIAS_type_remove_this		 TRUE
#	define Z_HAS_TRAIT_ALIAS_type_remove_volatile_this	 TRUE
#	define Z_HAS_TRAIT_ALIAS_type_to_const_lvalue		 TRUE
#	define Z_HAS_TRAIT_ALIAS_type_to_const_rvalue		 TRUE
#	define Z_HAS_TRAIT_ALIAS_type_to_const_volatile_lvalue	 TRUE
#	define Z_HAS_TRAIT_ALIAS_type_to_const_volatile_rvalue	 TRUE
#	define Z_HAS_TRAIT_ALIAS_type_to_lvalue			 TRUE
#	define Z_HAS_TRAIT_ALIAS_type_to_rvalue			 TRUE
#	define Z_HAS_TRAIT_ALIAS_type_to_volatile_lvalue	 TRUE
#	define Z_HAS_TRAIT_ALIAS_type_to_volatile_rvalue	 TRUE
#else
#	define Z_HAS_TRAIT_ALIAS_type_add_const_lvalue		 TRUE
#	define Z_HAS_TRAIT_ALIAS_type_add_const_rvalue		 TRUE
#	define Z_HAS_TRAIT_ALIAS_type_add_const_volatile_lvalue	 TRUE
#	define Z_HAS_TRAIT_ALIAS_type_add_const_volatile_rvalue	 TRUE
#	define Z_HAS_TRAIT_ALIAS_type_add_lvalue		 TRUE
#	define Z_HAS_TRAIT_ALIAS_type_add_rvalue		 TRUE
#	define Z_HAS_TRAIT_ALIAS_type_add_volatile_lvalue	 TRUE
#	define Z_HAS_TRAIT_ALIAS_type_add_volatile_rvalue	 TRUE
#	define Z_HAS_TRAIT_ALIAS_type_remove_const_this		 TRUE
#	define Z_HAS_TRAIT_ALIAS_type_remove_const_volatile_this TRUE
#	define Z_HAS_TRAIT_ALIAS_type_remove_this		 TRUE
#	define Z_HAS_TRAIT_ALIAS_type_remove_volatile_this	 TRUE
#	define Z_HAS_TRAIT_ALIAS_type_to_const_lvalue		 TRUE
#	define Z_HAS_TRAIT_ALIAS_type_to_const_rvalue		 TRUE
#	define Z_HAS_TRAIT_ALIAS_type_to_const_volatile_lvalue	 TRUE
#	define Z_HAS_TRAIT_ALIAS_type_to_const_volatile_rvalue	 TRUE
#	define Z_HAS_TRAIT_ALIAS_type_to_lvalue			 TRUE
#	define Z_HAS_TRAIT_ALIAS_type_to_rvalue			 TRUE
#	define Z_HAS_TRAIT_ALIAS_type_to_volatile_lvalue	 TRUE
#	define Z_HAS_TRAIT_ALIAS_type_to_volatile_rvalue	 TRUE
#endif

#if Z_LANGUAGE_HAS(CPP, TEMPLATE_ALIAS) && Z_LANGUAGE_HAS(CPP, RVALUE_REFERENCE)
#	define Z_HAS_TRAIT_ALIAS_type_add_rvalue_reference TRUE
#	define Z_HAS_TRAIT_ALIAS_type_to_rvalue_reference  TRUE
#else
#	define Z_HAS_TRAIT_ALIAS_type_add_rvalue_reference FALSE
#	define Z_HAS_TRAIT_ALIAS_type_to_rvalue_reference  FALSE
#endif

#if Z_LANGUAGE_HAS(CPP, TEMPLATE_ALIAS) && Z_TRAIT_HAS(Type, parameters)
#	define Z_HAS_TRAIT_ALIAS_type_parameters TRUE
#else
#	define Z_HAS_TRAIT_ALIAS_type_parameters FALSE
#endif

#if Z_LANGUAGE_HAS(CPP, TEMPLATE_ALIAS) && Z_TRAIT_HAS(Type, underlying_type)
#	define Z_HAS_TRAIT_ALIAS_type_underlying_type TRUE
#else
#	define Z_HAS_TRAIT_ALIAS_type_underlying_type FALSE
#endif

// MARK: - Helpers

namespace Zeta {namespace Detail {namespace Type {namespace Helpers {

#	if Z_LANGUAGE_HAS(CPP, EXPRESSION_SFINAE)

		namespace {
			template <class T, SInt L, Boolean B> struct IsComplete			     : False {};
			template <class T, SInt L>	      struct IsComplete	 <T, L, !!sizeof(T)> : True  {};
			template <class T, SInt L, Boolean B> struct IsIncomplete		     : True  {};
			template <class T, SInt L>	      struct IsIncomplete<T, L, !!sizeof(T)> : False {};
		}

		template <class T, Boolean B> struct IsStructureOrUnion				 : False {};
		template <class T>	      struct IsStructureOrUnion<T, !!sizeof(int (T::*))> : True  {};

		template <class T, Boolean B> struct IsUsableToCastNumber		     : False {};
		template <class T>	      struct IsUsableToCastNumber<T, !!sizeof((T)1)> : True  {};

#		if Z_LANGUAGE_HAS_SPECIFIER(CPP, DECLARED_TYPE)

			template <class T, class R> struct IsDefaultConstructible		    : False {};
			template <class T>	    struct IsDefaultConstructible<T, decltype(T())> : True  {};

			template <class T> Z_INLINE T fake();

			template <class T, class F, class R> struct IsFunctional : False {};
			template <class T, class F, class R> struct IsFunctor	 : False {};

			#if Z_LANGUAGE_HAS(CPP, VARIADIC_TEMPLATE)

				template <class T, class R, class... P> struct IsFunctional<T, R(P...), decltype(fake<T>()	     (fake<P>()...))> : True {};
				template <class T, class R, class... P> struct IsFunctor   <T, R(P...), decltype(fake<T>().operator()(fake<P>()...))> : True {};

#			else

				template <class T, class R> struct IsFunctional<T, R(), decltype(fake<T>()	     ())> : True {};
				template <class T, class R> struct IsFunctor   <T, R(), decltype(fake<T>().operator()())> : True {};

#				define Z_TEMPLATE_FAKE_ARGUMENT(index) fake<P##index>()

#				define Z_TEMPLATE_SPECIALIZATIONS(parameter_count)								     \
																		     \
				template <class T, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct IsFunctional<	     \
					T, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA)),						     \
					decltype(fake<T>()(Z_FOR_##parameter_count##_CALL_WITH_INDEX(Z_TEMPLATE_FAKE_ARGUMENT, Z_COMMA)))	     \
				> : True {};													     \
																		     \
				template <class T, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct IsFunctor<		     \
					T, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA)),						     \
					decltype(fake<T>().operator()(Z_FOR_##parameter_count##_CALL_WITH_INDEX(Z_TEMPLATE_FAKE_ARGUMENT, Z_COMMA))) \
				> : True {};

				Z_FOR_32_CALL_WITH_TIME(Z_TEMPLATE_SPECIALIZATIONS, Z_EMPTY)
#				undef Z_TEMPLATE_SPECIALIZATIONS
#				undef Z_TEMPLATE_FAKE_ARGUMENT

#			endif

#		endif

#	endif

	template <class T> struct RemovePointer;
	template <class T> struct RemovePointer<T*> {typedef T type;};
}}}}

// MARK: - Abstract

namespace Zeta {namespace Detail {namespace Type {namespace Abstract {

	struct Invalid {
		enum {	is_arithmetic		     = false,
			is_array		     = false,
			is_callable		     = false,
			is_char			     = false,
			is_class		     = false,
			is_const		     = false,
			is_const_volatile	     = false,
			is_data_member_pointer	     = false,
			is_empty		     = false,
			is_exact		     = false,
			is_integer		     = false,
			is_integral		     = false,
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
			is_signed_or_unsigned	     = false,
			is_simple		     = false,
			is_sint			     = false,
			is_slong		     = false,
			is_sshort		     = false,
			is_statically_allocatable    = false,
			is_storable		     = false,
			is_structure		     = false,
			is_structure_or_union	     = false,
			is_uchar		     = false,
			is_uint			     = false,
			is_ulong		     = false,
			is_unsigned		     = false,
			is_ushort		     = false,
			is_valid		     = false,
			is_variadic		     = false,
			is_variadic_function	     = false,
			is_void			     = false,
			is_void_pointer		     = false,
			is_volatile		     = false
		};

		enum {	arity	      = 0,
			bits	      = 0,
			element_count = 0,
			pointer_level = 0,
			size	      = 0
		};

		typedef NaT type;

		typedef NaT add_const;
		typedef NaT add_const_volatile;
		typedef NaT add_lvalue_reference;
		typedef NaT add_pointer;
		typedef NaT add_volatile;
		typedef NaT class_type;
		typedef NaT element_type;
		typedef NaT pointee_type;
		typedef NaT referencee_type;
		typedef NaT remove_const;
		typedef NaT remove_const_volatile;
		typedef NaT remove_pointer;
		typedef NaT remove_reference;
		typedef NaT remove_volatile;
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

#		if Z_TRAIT_HAS(Type, has_virtual_destructor)
			enum {has_virtual_destructor = false};
#		endif

#		if Z_TRAIT_HAS(Type, is_abstract)
			enum {is_abstract = false};
#		endif

#		if Z_TRAIT_HAS(Type, is_aggregate)
			enum {is_aggregate = false};
#		endif

#		if Z_TRAIT_HAS(Type, is_boolean)
			enum {is_boolean = false};
#		endif

/*#		if Z_TRAIT_HAS(Type, is_char16)
			enum {is_char16 = false};
#		endif

#		if Z_TRAIT_HAS(Type, is_char32)
			enum {is_char32 = false};
#		endif*/

#		if Z_TRAIT_HAS(Type, is_default_constructible)
			enum {is_default_constructible = false};
#		endif

#		if Z_TRAIT_HAS(Type, is_double)
			enum {is_double = false};
#		endif

#		if Z_TRAIT_HAS(Type, is_enumeration)
			enum {is_enumeration = false};
#		endif

#		if Z_TRAIT_HAS(Type, is_final)
			enum {is_final = false};
#		endif

#		if Z_TRAIT_HAS(Type, is_float)
			enum {is_float = false};
#		endif

#		if Z_TRAIT_HAS(Type, is_float16)
			enum {is_float16 = false};
#		endif

#		if Z_TRAIT_HAS(Type, is_float32)
			enum {is_float32 = false};
#		endif

#		if Z_TRAIT_HAS(Type, is_float64)
			enum {is_float64 = false};
#		endif

#		if Z_TRAIT_HAS(Type, is_float128)
			enum {is_float128 = false};
#		endif

#		if Z_TRAIT_HAS(Type, is_float80_x87)
			enum {is_float80_x87 = false};
#		endif

#		if Z_TRAIT_HAS(Type, is_float96_x87)
			enum {is_float96_x87 = false};
#		endif

#		if Z_TRAIT_HAS(Type, is_float128_x87)
			enum {is_float128_x87 = false};
#		endif

#		if Z_TRAIT_HAS(Type, is_interface_class)
			enum {is_interface_class = false};
#		endif

#		if Z_TRAIT_HAS(Type, is_ldouble)
			enum {is_ldouble = false};
#		endif

#		if Z_TRAIT_HAS(Type, is_literal)
			enum {is_literal = false};
#		endif

#		if Z_TRAIT_HAS(Type, is_null_pointer)
			enum {is_null_pointer = false};
#		endif

#		if Z_TRAIT_HAS(Type, is_pod)
			enum {is_pod = false};
#		endif

#		if Z_TRAIT_HAS(Type, is_polymorphic)
			enum {is_polymorphic = false};
#		endif

#		if Z_TRAIT_HAS(Type, is_sint8)
			enum {is_sint8 = false};
#		endif

#		if Z_TRAIT_HAS(Type, is_sint16)
			enum {is_sint16 = false};
#		endif

#		if Z_TRAIT_HAS(Type, is_sint32)
			enum {is_sint32 = false};
#		endif

#		if Z_TRAIT_HAS(Type, is_sint64)
			enum {is_sint64 = false};
#		endif

#		if Z_TRAIT_HAS(Type, is_sint128)
			enum {is_sint128 = false};
#		endif

#		if Z_TRAIT_HAS(Type, is_template)
			enum {is_template = false};
#		endif

#		if Z_TRAIT_HAS(Type, is_trivially_copy_assignable)
			enum {is_trivially_copy_assignable = false};
#		endif

#		if Z_TRAIT_HAS(Type, is_trivially_copy_constructible)
			enum {is_trivially_copy_constructible = false};
#		endif

#		if Z_TRAIT_HAS(Type, is_trivially_copyable)
			enum {is_trivially_copyable = false};
#		endif

#		if Z_TRAIT_HAS(Type, is_trivially_default_constructible)
			enum {is_trivially_default_constructible = false};
#		endif

#		if Z_TRAIT_HAS(Type, is_trivially_destructible)
			enum {is_trivially_destructible = false};
#		endif

#		if Z_TRAIT_HAS(Type, is_uint8)
			enum {is_uint8 = false};
#		endif

#		if Z_TRAIT_HAS(Type, is_uint16)
			enum {is_uint16 = false};
#		endif

#		if Z_TRAIT_HAS(Type, is_uint32)
			enum {is_uint32 = false};
#		endif

#		if Z_TRAIT_HAS(Type, is_uint64)
			enum {is_uint64 = false};
#		endif

#		if Z_TRAIT_HAS(Type, is_uint128)
			enum {is_uint128 = false};
#		endif

#		if Z_TRAIT_HAS(Type, is_union)
			enum {is_union = false};
#		endif

/*#		if Z_TRAIT_HAS(Type, is_wchar)
			enum {is_wchar = false};
#		endif*/

#		if Z_LANGUAGE_INCLUDES(OBJECTIVE_CPP)

			enum {	is_objective_c_class	      = false,
				is_objective_c_class_pointer  = false,
				is_objective_c_object	      = false,
				is_objective_c_object_pointer = false
			};

#			if Z_LANGUAGE_HAS(CPP, EXPRESSION_SFINAE)
				enum {	is_objective_c_instance		= false,
					is_objective_c_instance_pointer = false
				};
#			endif

#		endif

#		ifdef Z_LLONG
			enum {	is_sllong = false,
				is_ullong = false
			};
#		endif

#		if Z_LANGUAGE_HAS(CPP, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)

			enum {	is_const_lvalue		 = false,
				is_const_rvalue		 = false,
				is_const_volatile_lvalue = false,
				is_const_volatile_rvalue = false,
				is_lvalue		 = false,
				is_rvalue		 = false,
				is_volatile_lvalue	 = false,
				is_volatile_rvalue	 = false
			};

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
			typedef NaT to_const_lvalue;
			typedef NaT to_const_rvalue;
			typedef NaT to_const_volatile_lvalue;
			typedef NaT to_const_volatile_rvalue;
			typedef NaT to_lvalue;
			typedef NaT to_rvalue;
			typedef NaT to_volatile_lvalue;
			typedef NaT to_volatile_rvalue;

#		endif

#		if Z_LANGUAGE_HAS(CPP, RVALUE_REFERENCE)

			enum {	is_function_rvalue_reference = false,
				is_rvalue_reference	     = false
			};

			typedef NaT add_rvalue_reference;
			typedef NaT to_rvalue_reference;

#		endif

#		if Z_TRAIT_HAS(Type, parameters)
			typedef NaT parameters;
#		endif

#		if Z_TRAIT_HAS(Type, underlying_type)
			typedef NaT underlying_type;
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

	struct Simple : Storable {
		enum {	is_simple		  = true,
			is_statically_allocatable = true
		};

#		if Z_TRAIT_HAS(Type, is_literal)
			enum {is_literal = true};
#		endif

#		if Z_TRAIT_HAS(Type, is_trivially_copy_constructible)
			enum {is_trivially_copy_constructible = true};
#		endif

#		if Z_TRAIT_HAS(Type, is_trivially_destructible)
			enum {is_trivially_destructible = true};
#		endif

		//----------------------------------------------.
		// Unlike the standard C++ library, Z considers |
		// the following to be "true" for references:	|
		//----------------------------------------------'

#		if Z_TRAIT_HAS(Type, is_default_constructible)
			enum {is_default_constructible = true};
#		endif

#		if Z_TRAIT_HAS(Type, is_trivially_copy_assignable)
			enum {is_trivially_copy_assignable = true};
#		endif

#		if Z_TRAIT_HAS(Type, is_trivially_copyable)
			enum {is_trivially_copyable = true};
#		endif

#		if Z_TRAIT_HAS(Type, is_trivially_default_constructible)
			enum {is_trivially_default_constructible = true};
#		endif
	};

	struct Number : Simple {
		enum {	is_arithmetic  = true,
			is_fundamental = true,
			is_number      = true,
			is_scalar      = true
		};

#		if Z_TRAIT_HAS(Type, is_pod)
			enum {is_pod = true};
#		endif
	};

	struct Integral : Number {
		enum {	is_exact    = true,
			is_integral = true,
		};
	};

	struct Natural : Integral {
		enum {	is_natural	      = true,
			is_unsigned	      = true,
			is_signed_or_unsigned = true
		};
		enum {number_set = Z_NUMBER_SET_N};
		enum {minimum = 0};
	};

	struct Integer : Integral {
		enum {	is_integer	      = true,
			is_signed	      = true,
			is_signed_or_unsigned = true
		};
		enum {number_set = Z_NUMBER_SET_Z};
	};

	struct Real : Number {
		enum {	is_real		      = true,
			is_signed	      = true,
			is_signed_or_unsigned = true
		};
		enum {number_set = Z_NUMBER_SET_R};
	};

	struct PointerLike : Simple {
		enum {is_scalar = true};

#		if Z_TRAIT_HAS(Type, is_pod)
			enum {is_pod = true};
#		endif
	};

#	if Z_TRAIT_HAS(Type, is_uint8)

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

#	if Z_TRAIT_HAS(Type, is_sint8)

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

#	if Z_TRAIT_HAS(Type, is_uint16)

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

#	if Z_TRAIT_HAS(Type, is_sint16)

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

#	if Z_TRAIT_HAS(Type, is_uint32)

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

#	if Z_TRAIT_HAS(Type, is_sint32)

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

#	if Z_TRAIT_HAS(Type, is_uint64)

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

#	if Z_TRAIT_HAS(Type, is_sint64)

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

#	if Z_TRAIT_HAS(Type, is_uint128)

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

#	if Z_TRAIT_HAS(Type, is_sint128)

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

#	if Z_TRAIT_HAS(Type, is_float16)

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

			static Z_CT(CPP11) zfloat16 epsilon () {return Z_FLOAT16_EPSILON;}
			static Z_CT(CPP11) zfloat16 minimum () {return Z_FLOAT16_MINIMUM;}
			static Z_CT(CPP11) zfloat16 maximum () {return Z_FLOAT16_MAXIMUM;}
		/*	static Z_CT(CPP11) zfloat16 infinity() Z_NO_EXCEPTION {return Z_FLOAT16_INFINITY;}
			static Z_CT(CPP11) zfloat16 nan	    () Z_NO_EXCEPTION {return Z_FLOAT16_NAN;}*/

			typedef zfloat16 type;
			typedef zfloat16 to_signed;
		};

#	endif

#	if Z_TRAIT_HAS(Type, is_float32)

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

			static Z_CT(CPP11) zfloat32 epsilon () {return Z_FLOAT32_EPSILON;}
			static Z_CT(CPP11) zfloat32 minimum () {return Z_FLOAT32_MINIMUM;}
			static Z_CT(CPP11) zfloat32 maximum () {return Z_FLOAT32_MAXIMUM;}
		/*	static Z_CT(CPP11) zfloat32 infinity() Z_NO_EXCEPTION {return Z_FLOAT32_INFINITY;}
			static Z_CT(CPP11) zfloat32 nan	    () Z_NO_EXCEPTION {return Z_FLOAT32_NAN;}*/

			typedef zfloat32 type;
			typedef zfloat32 to_signed;
		};

#	endif

#	if Z_TRAIT_HAS(Type, is_float64)

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

			static Z_CT(CPP11) zfloat64 epsilon () {return Z_FLOAT64_EPSILON;}
			static Z_CT(CPP11) zfloat64 minimum () {return Z_FLOAT64_MINIMUM;}
			static Z_CT(CPP11) zfloat64 maximum () {return Z_FLOAT64_MAXIMUM;}
		/*	static Z_CT(CPP11) zfloat64 infinity() Z_NO_EXCEPTION {return Z_FLOAT64_INFINITY;}
			static Z_CT(CPP11) zfloat64 nan	    () Z_NO_EXCEPTION {return Z_FLOAT64_NAN;}*/

			typedef zfloat64 type;
			typedef zfloat64 to_signed;
		};

#	endif

#	if Z_TRAIT_HAS(Type, is_float128)

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

			static Z_CT(CPP11) zfloat128 epsilon () {return Z_FLOAT128_EPSILON;}
			static Z_CT(CPP11) zfloat128 minimum () {return Z_FLOAT128_MINIMUM;}
			static Z_CT(CPP11) zfloat128 maximum () {return Z_FLOAT128_MAXIMUM;}
		/*	static Z_CT(CPP11) zfloat128 infinity() Z_NO_EXCEPTION {return Z_FLOAT128_INFINITY;}
			static Z_CT(CPP11) zfloat128 nan     () Z_NO_EXCEPTION {return Z_FLOAT128_NAN;}*/

			typedef zfloat128 type;
			typedef zfloat128 to_signed;
		};

#	endif

#	if Z_TRAIT_HAS(Type, is_float80_x87)

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

			static Z_CT(CPP11) zfloat80_x87 epsilon () {return Z_FLOAT80_X87_EPSILON;}
			static Z_CT(CPP11) zfloat80_x87 minimum () {return Z_FLOAT80_X87_MINIMUM;}
			static Z_CT(CPP11) zfloat80_x87 maximum () {return Z_FLOAT80_X87_MAXIMUM;}
		/*	static Z_CT(CPP11) zfloat80_x87 infinity() Z_NO_EXCEPTION {return Z_FLOAT80_X87_INFINITY;}
			static Z_CT(CPP11) zfloat80_x87 nan	() Z_NO_EXCEPTION {return Z_FLOAT80_X87_NAN;}*/

			typedef zfloat80_x87 type;
			typedef zfloat80_x87 to_signed;
		};

#	endif

#	if Z_TRAIT_HAS(Type, is_float96_x87)

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

			static Z_CT(CPP11) zfloat96_x87 epsilon () {return Z_FLOAT96_X87_EPSILON;}
			static Z_CT(CPP11) zfloat96_x87 minimum () {return Z_FLOAT96_X87_MINIMUM;}
			static Z_CT(CPP11) zfloat96_x87 maximum () {return Z_FLOAT96_X87_MAXIMUM;}
		/*	static Z_CT(CPP11) zfloat96_x87 infinity() Z_NO_EXCEPTION {return Z_FLOAT96_X87_INFINITY;}
			static Z_CT(CPP11) zfloat96_x87 nan	() Z_NO_EXCEPTION {return Z_FLOAT96_X87_NAN;}*/

			typedef zfloat96_x87 type;
			typedef zfloat96_x87 to_signed;
		};

#	endif

#	if Z_TRAIT_HAS(Type, is_float128_x87)

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

			static Z_CT(CPP11) zfloat128_x87 epsilon () {return Z_FLOAT128_X87_EPSILON;}
			static Z_CT(CPP11) zfloat128_x87 minimum () {return Z_FLOAT128_X87_MINIMUM;}
			static Z_CT(CPP11) zfloat128_x87 maximum () {return Z_FLOAT128_X87_MAXIMUM;}
		/*	static Z_CT(CPP11) zfloat128_x87 infinity() Z_NO_EXCEPTION {return Z_FLOAT128_X87_INFINITY;}
			static Z_CT(CPP11) zfloat128_x87 nan	 () Z_NO_EXCEPTION {return Z_FLOAT128_X87_NAN;}*/

			typedef zfloat128_x87 type;
			typedef zfloat128_x87 to_signed;
		};

#	endif

	struct Void : Valid {
		enum {	is_fundamental = true,
			is_void	       = true
		};

#		if Z_TRAIT_HAS(Type, is_literal)
			enum {is_literal = true};
#		endif

		typedef void type;
	};

	struct Char : TernaryType<Z_CHAR_IS_SIGNED, Integer, Natural>::type {
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

#	ifdef Z_LLONG

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

#	if Z_TRAIT_HAS(Type, is_float)

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

			static Z_CT(CPP11) zfloat epsilon () {return Z_FLOAT_EPSILON;}
			static Z_CT(CPP11) zfloat minimum () {return Z_FLOAT_MINIMUM;}
			static Z_CT(CPP11) zfloat maximum () {return Z_FLOAT_MAXIMUM;}
		/*	static Z_CT(CPP11) zfloat infinity() Z_NO_EXCEPTION {return Z_FLOAT_INFINITY;}
			static Z_CT(CPP11) zfloat nan	  () Z_NO_EXCEPTION {return Z_FLOAT_NAN;}*/

			typedef zfloat type;
			typedef zfloat to_signed;
		};

#	endif

#	if Z_TRAIT_HAS(Type, is_double)

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

			static Z_CT(CPP11) zdouble epsilon () {return Z_DOUBLE_EPSILON;}
			static Z_CT(CPP11) zdouble minimum () {return Z_DOUBLE_MINIMUM;}
			static Z_CT(CPP11) zdouble maximum () {return Z_DOUBLE_MAXIMUM;}
		/*	static Z_CT(CPP11) zdouble infinity() Z_NO_EXCEPTION {return Z_DOUBLE_INFINITY;}
			static Z_CT(CPP11) zdouble nan	   () Z_NO_EXCEPTION {return Z_DOUBLE_NAN;}*/

			typedef zdouble type;
			typedef zdouble to_signed;
		};

#	endif

#	if Z_TRAIT_HAS(Type, is_ldouble)

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

			static Z_CT(CPP11) zldouble epsilon () {return Z_LDOUBLE_EPSILON;}
			static Z_CT(CPP11) zldouble minimum () {return Z_LDOUBLE_MINIMUM;}
			static Z_CT(CPP11) zldouble maximum () {return Z_LDOUBLE_MAXIMUM;}
		/*	static Z_CT(CPP11) zldouble infinity() Z_NO_EXCEPTION {return Z_LDOUBLE_INFINITY;}
			static Z_CT(CPP11) zldouble nan	    () Z_NO_EXCEPTION {return Z_LDOUBLE_NAN;}*/

			typedef zldouble type;
			typedef zldouble to_signed;
		};

#	endif

#	if Z_TRAIT_HAS(Type, is_boolean)

		struct Boolean : Integral {
			enum {is_boolean = true};

			typedef bool type;
		};

#	endif

/*#	if Z_TRAIT_HAS(Type, is_wchar)

		struct WChar {
			enum {is_wchar = true};

			typedef wchar_t type;
		};

#	endif

#	if Z_TRAIT_HAS(Type, is_char16)

		struct Char16 {
			enum {is_wchar = true};

			typedef char16_t type;
		};

#	endif

#	if Z_TRAIT_HAS(Type, is_char32)

		struct Char32 {
			enum {is_wchar = true};

			typedef char32_t type;
		};

#	endif*/

#	if Z_TRAIT_HAS(Type, is_null_pointer)

		struct NullPointer : PointerLike {
			enum {	is_fundamental	= true,
				is_null_pointer = true
			};

			typedef decltype(nullptr) type;
		};

#	endif

	template <zboolean E, class T> struct Array;

	template <class T> struct Array<false, T> : Storable {
		enum {is_array = true};

		typedef T element_type;
	};

	template <class T> struct Array<true, T> : Array<false, T> {
#		if Z_TRAIT_HAS(Type, is_aggregate)
			enum {is_aggregate = true};
#		endif

#		if Z_TRAIT_HAS(Type, is_default_constructible)
			enum {is_default_constructible = Helpers::IsDefaultConstructible<T, T>::value};
#		endif

#		if Z_TRAIT_HAS(Type, is_literal)
			enum {is_literal = Z_COMPILER_TRAIT(TYPE_IS_LITERAL)(T)};
#		endif

#		if Z_TRAIT_HAS(Type, is_pod)
			enum {is_pod = Z_COMPILER_TRAIT(TYPE_IS_POD)(T)};
#		endif

#		if Z_TRAIT_HAS(Type, is_trivially_copy_constructible)
			enum {is_trivially_copy_constructible = Z_COMPILER_TRAIT(TYPE_IS_TRIVIALLY_COPY_CONSTRUCTIBLE)(T)};
#		endif

#		if Z_TRAIT_HAS(Type, is_trivially_copyable)
			enum {is_trivially_copyable = Z_COMPILER_TRAIT(TYPE_IS_TRIVIALLY_COPYABLE)(T)};
#		endif

#		if Z_TRAIT_HAS(Type, is_trivially_default_constructible)
			enum {is_trivially_default_constructible = Z_COMPILER_TRAIT(TYPE_IS_TRIVIALLY_DEFAULT_CONSTRUCTIBLE)(T)};
#		endif

#		if Z_TRAIT_HAS(Type, is_trivially_destructible)
			enum {is_trivially_destructible = Z_COMPILER_TRAIT(TYPE_IS_TRIVIALLY_DESTRUCTIBLE)(T)};
#		endif
	};

	template <zboolean E, class T, zusize N> struct SizedArray : Array<E, T> {
		enum {	is_empty		  = (N == 0),
			is_statically_allocatable = true
		};
		enum {element_count = N};

		typedef T type[N];
	};

	template <zboolean E, class T> struct FlexibleArray : Array<E, T> {
		enum {	is_empty	  = true,
			is_flexible_array = true
		};

		typedef T type[];
	};

	template <class T> struct Pointer : PointerLike {
		enum {is_pointer = true};

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

	template <class T> struct Reference : Simple {
		enum {is_reference = true};

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
			enum {arity = TypeCount<P...>::value};

			typedef R type		   (P...);
			typedef R to_const	   (P...) const;
			typedef R to_const_volatile(P...) const volatile;
			typedef R to_volatile	   (P...)	volatile;

#			if Z_LANGUAGE_HAS(CPP, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)
				typedef R to_const_lvalue	  (P...) const		&;
				typedef R to_const_rvalue	  (P...) const		&&;
				typedef R to_const_volatile_lvalue(P...) const volatile &;
				typedef R to_const_volatile_rvalue(P...) const volatile &&;
				typedef R to_lvalue		  (P...)		&;
				typedef R to_rvalue		  (P...)		&&;
				typedef R to_volatile_lvalue	  (P...)       volatile &;
				typedef R to_volatile_rvalue	  (P...)       volatile &&;
#			endif

			typedef R return_type;

#			if Z_TRAIT_HAS(Type, parameters)
				typedef TypeList<P...> parameters;
#			endif
		};

		template <class R, class... P> struct VariadicFunction : Function<R, P...> {
			enum {is_variadic = true};

			typedef R type		   (P..., ...);
			typedef R to_const	   (P..., ...) const;
			typedef R to_const_volatile(P..., ...) const volatile;
			typedef R to_volatile	   (P..., ...)	     volatile;

#			if Z_LANGUAGE_HAS(CPP, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)
				typedef R to_const_lvalue	  (P..., ...) const	     &;
				typedef R to_const_rvalue	  (P..., ...) const	     &&;
				typedef R to_const_volatile_lvalue(P..., ...) const volatile &;
				typedef R to_const_volatile_rvalue(P..., ...) const volatile &&;
				typedef R to_lvalue		  (P..., ...)		     &;
				typedef R to_rvalue		  (P..., ...)		     &&;
				typedef R to_volatile_lvalue	  (P..., ...)	    volatile &;
				typedef R to_volatile_rvalue	  (P..., ...)	    volatile &&;
#			endif
		};

#	else

		template <class R> struct FunctionWith0Parameters : Valid {
			enum {	is_callable = true,
				is_function = true
			};
			enum {arity = 0};

			typedef R type		   ();
			typedef R to_const	   () const;
			typedef R to_const_volatile() const volatile;
			typedef R to_volatile	   ()	    volatile;

#			if Z_LANGUAGE_HAS(CPP, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)
				typedef R to_const_lvalue	  () const	    &;
				typedef R to_const_rvalue	  () const	    &&;
				typedef R to_const_volatile_lvalue() const volatile &;
				typedef R to_const_volatile_rvalue() const volatile &&;
				typedef R to_lvalue		  ()		    &;
				typedef R to_rvalue		  ()		    &&;
				typedef R to_volatile_lvalue	  ()	   volatile &;
				typedef R to_volatile_rvalue	  ()	   volatile &&;
#			endif

			typedef R return_type;
		};

#		if Z_LANGUAGE_HAS(CPP, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)

#			define Z_TEMPLATE_SPECIALIZATIONS(parameter_count)								       \
																	       \
			template <class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)>					       \
			struct FunctionWith##parameter_count##Parameters : Valid {							       \
				enum {	is_callable = true,										       \
					is_function = true										       \
				};													       \
				enum {arity = parameter_count};										       \
																	       \
				typedef R type			  (Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA));			       \
				typedef R to_const		  (Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA)) const;		       \
				typedef R to_const_lvalue	  (Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA)) const	      &;       \
				typedef R to_const_rvalue	  (Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA)) const	      &&;      \
				typedef R to_const_volatile	  (Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA)) const volatile;	       \
				typedef R to_const_volatile_lvalue(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA)) const volatile &;       \
				typedef R to_const_volatile_rvalue(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA)) const volatile &&;      \
				typedef R to_lvalue		  (Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA))		      &;       \
				typedef R to_rvalue		  (Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA))		      &&;      \
				typedef R to_volatile		  (Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA))	     volatile;	       \
				typedef R to_volatile_lvalue	  (Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA))	     volatile &;       \
				typedef R to_volatile_rvalue	  (Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA))	     volatile &&;      \
				typedef R return_type;											       \
			};														       \
																	       \
			template <class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)>					       \
			struct VariadicFunctionWith##parameter_count##Parameters							       \
			: FunctionWith##parameter_count##Parameters<R, Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA)> {		       \
				enum {is_variadic = true};										       \
																	       \
				typedef R type			  (Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...);		       \
				typedef R to_const		  (Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...) const;	       \
				typedef R to_const_lvalue	  (Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...) const	   &;  \
				typedef R to_const_rvalue	  (Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...) const	   &&; \
				typedef R to_const_volatile	  (Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...) const volatile;    \
				typedef R to_const_volatile_lvalue(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...) const volatile &;  \
				typedef R to_const_volatile_rvalue(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...) const volatile &&; \
				typedef R to_lvalue		  (Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...)		   &;  \
				typedef R to_rvalue		  (Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...)		   &&; \
				typedef R to_volatile		  (Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...)	  volatile;    \
				typedef R to_volatile_lvalue	  (Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...)	  volatile &;  \
				typedef R to_volatile_rvalue	  (Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...)	  volatile &&; \
			};

#		else

#			define Z_TEMPLATE_SPECIALIZATIONS(parameter_count)							     \
																     \
			template <class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)>				     \
			struct FunctionWith##parameter_count##Parameters : Valid {						     \
				enum {	is_callable = true,									     \
					is_function = true									     \
				};												     \
				enum {arity = parameter_count + 1};								     \
																     \
				typedef R type		   (Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA));		     \
				typedef R to_const	   (Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA)) const;		     \
				typedef R to_const_volatile(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA)) const volatile;	     \
				typedef R to_volatile	   (Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA))	      volatile;      \
																     \
				typedef R return_type;										     \
			};													     \
																     \
			template <class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)>				     \
			struct VariadicFunctionWith##parameter_count##Parameters						     \
			: FunctionWith##parameter_count##Parameters<R, Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA)> {	     \
				enum {is_variadic = true};									     \
																     \
				typedef R type		   (Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...);		     \
				typedef R to_const	   (Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...) const;	     \
				typedef R to_const_volatile(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...) const volatile; \
				typedef R to_volatile	   (Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...)	   volatile; \
			};

#		endif

		Z_FOR_32_CALL_WITH_TIME(Z_TEMPLATE_SPECIALIZATIONS, Z_EMPTY)
#		undef Z_TEMPLATE_SPECIALIZATIONS

#	endif

	enum {	Enumeration,
		Structure,
		Union,
		ObjectiveCInstance
	};

	template <zboolean E, zuint K, class T> struct Kind;

#	if Z_TRAIT_HAS(Type, is_enumeration)

		template <class T> struct Kind<false, Enumeration, T> : Simple {
			enum {	is_enumeration = true,
				is_scalar      = true
			};

#			if Z_TRAIT_HAS(Type, is_pod)
				enum {is_pod = true};
#			endif

			typedef T type;
		};

		template <class T> struct Kind<true, Enumeration, T> : Kind<false, Enumeration, T> {
#			if Z_TRAIT_HAS(Type, underlying_type)
				typedef Z_COMPILER_TRAIT(TYPE_UNDERLYING_TYPE)(T) underlying_type;
#			endif
		};

#	endif

	template <zboolean E, class T> struct StructureOrUnion;

	template <class T> struct StructureOrUnion<false, T> : Storable {
		enum {is_structure_or_union = true};

		typedef T type;
	};

	template <class T> struct StructureOrUnion<true, T> : StructureOrUnion<false, T> {

#		if Z_TRAIT_HAS(Type, is_aggregate)
			enum {is_aggregate = Z_COMPILER_TRAIT(TYPE_IS_AGGREGATE)(T)};
#		endif

#		if Z_TRAIT_HAS(Type, is_default_constructible)
			enum {is_default_constructible = Helpers::IsDefaultConstructible<T, T>::value};
#		endif

#		if Z_TRAIT_HAS(Type, is_final)
			enum {is_final = Z_COMPILER_TRAIT(TYPE_IS_FINAL)(T)};
#		endif

#		if Z_TRAIT_HAS(Type, is_literal)
			enum {is_literal = Z_COMPILER_TRAIT(TYPE_IS_LITERAL)(T)};
#		endif

#		if Z_TRAIT_HAS(Type, is_pod)
			enum {is_pod = Z_COMPILER_TRAIT(TYPE_IS_POD)(T)};
#		endif

#		if Z_TRAIT_HAS(Type, is_trivially_copy_assignable)
			enum {is_trivially_copy_assignable = Z_COMPILER_TRAIT(TYPE_IS_TRIVIALLY_COPY_ASSIGNABLE)(T)};
#		endif

#		if Z_TRAIT_HAS(Type, is_trivially_copy_constructible)
			enum {is_trivially_copy_constructible = Z_COMPILER_TRAIT(TYPE_IS_TRIVIALLY_COPY_CONSTRUCTIBLE)(T)};
#		endif

#		if Z_TRAIT_HAS(Type, is_trivially_copyable)
			enum {is_trivially_copyable = Z_COMPILER_TRAIT(TYPE_IS_TRIVIALLY_COPYABLE)(T)};
#		endif

#		if Z_TRAIT_HAS(Type, is_trivially_default_constructible)
			enum {is_trivially_default_constructible = Z_COMPILER_TRAIT(TYPE_IS_TRIVIALLY_DEFAULT_CONSTRUCTIBLE)(T)};
#		endif

#		if Z_TRAIT_HAS(Type, is_trivially_destructible)
			enum {is_trivially_destructible = Z_COMPILER_TRAIT(TYPE_IS_TRIVIALLY_DESTRUCTIBLE)(T)};
#		endif
	};

	template <zboolean E, class T> struct MaybeTemplate : StructureOrUnion<E, T> {};

#	if Z_TRAIT_HAS(Type, is_template)

		template <zboolean E, template <class...> class T, class... A> struct MaybeTemplate<E, T<A...> > : StructureOrUnion<E, T<A...> > {
			enum {is_template = true};
			enum {arity = TypeCount<A...>::value};

			typedef TypeList<A...> parameters;
		};

#	endif

	template <class T> class Kind<false, Structure, T> : public MaybeTemplate<false, T> {
		public:
		enum {	is_class     = true,
			is_structure = true
		};
	};

	template <class T> class Kind<true, Structure, T> : public MaybeTemplate<true, T> {
		public:
		enum {	is_class     = true,
			is_structure = true
		};

#		if Z_TRAIT_HAS(Type, has_virtual_destructor)
			enum {has_virtual_destructor = Z_COMPILER_TRAIT(TYPE_HAS_VIRTUAL_DESTRUCTOR)(T)};
#		endif

#		if Z_TRAIT_HAS(Type, is_abstract)
			enum {is_abstract = Z_COMPILER_TRAIT(TYPE_IS_ABSTRACT)(T)};
#		endif

#		if Z_COMPILER_HAS_TRAIT(TYPE_IS_EMPTY)
			enum {is_empty = Z_COMPILER_TRAIT(TYPE_IS_EMPTY)(T)};
#		else
			private:
			struct Dummy		    {zsint dummy;};
			struct Z_EBCO EmptyTest : T {zsint dummy;};

			public:
			enum {is_empty = (sizeof(EmptyTest) == sizeof(Dummy))};
#		endif

#		if Z_TRAIT_HAS(Type, is_interface_class)
			enum {is_interface_class = Z_COMPILER_TRAIT(TYPE_IS_INTERFACE_CLASS)(T)};
#		endif

#		if Z_TRAIT_HAS(Type, is_polymorphic)
			enum {is_polymorphic = Z_COMPILER_TRAIT(TYPE_IS_POLYMORPHIC)(T)};
#		endif
	};

#	if Z_TRAIT_HAS(Type, is_union)

		template <zboolean E, class T> struct Kind<E, Union, T> : MaybeTemplate<E, T> {
			enum {	is_statically_allocatable = true,
				is_union		  = true
			};
		};

#	endif

#	if Z_LANGUAGE_INCLUDES(OBJECTIVE_CPP)

		struct ObjectiveCObject : Valid {
			enum {is_objective_c_object = true};

			typedef typename Pointer<id>::remove_pointer type;
		};

		struct ObjectiveCClass : ObjectiveCObject {
			enum {is_objective_c_class = true};

			typedef typename Pointer<Class>::remove_pointer type;
		};

#		if Z_TRAIT_HAS(Type, is_objective_c_instance)

			template <zboolean E, class T> struct Kind<E, ObjectiveCInstance, T> : ObjectiveCObject {
				enum {is_objective_c_instance = true};

				typedef T type;
			};

#		endif

#	endif
}}}}

namespace Zeta {namespace Detail {namespace Type {namespace Mixins {

	// MARK: - Mixins: Qualifiers (generic)

	template <class C> struct Unqualified : C {
		typedef const	       typename C::type add_const;
		typedef const volatile typename C::type add_const_volatile;
		typedef	      volatile typename C::type add_volatile;
		typedef		       typename C::type remove_const;
		typedef		       typename C::type remove_const_volatile;
		typedef		       typename C::type remove_volatile;
		typedef const	       typename C::type to_const;
		typedef const volatile typename C::type to_const_volatile;
		typedef	      volatile typename C::type to_volatile;
		typedef		       typename C::type to_unqualified;
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
			is_const_volatile = true,
			is_volatile	  = true
		};

		typedef typename C::to_const_volatile type;
		typedef typename C::to_const_volatile add_const;
		typedef typename C::to_const_volatile add_volatile;
		typedef typename C::to_volatile	      remove_const;
		typedef typename C::to_const	      remove_volatile;
	};

	// MARK: - Mixins: Qualifiers (signed or unsigned)

	template <class C> struct ConstInteger : Const<C> {
		typedef const typename C::to_unsigned to_unsigned;
	};

	template <class C> struct VolatileInteger : Volatile<C> {
		typedef volatile typename C::to_unsigned to_unsigned;
	};

	template <class C> struct ConstVolatileInteger : ConstVolatile<C> {
		typedef const volatile typename C::to_unsigned to_unsigned;
	};

	template <class C> struct ConstSignedOrUnsigned : TernaryType<C::is_real, Const<C>, ConstInteger<C> >::type {
		typedef const typename C::to_signed to_signed;
	};

	template <class C> struct VolatileSignedOrUnsigned : TernaryType<C::is_real, Volatile<C>, VolatileInteger<C> >::type {
		typedef volatile typename C::to_signed to_signed;
	};

	template <class C> struct ConstVolatileSignedOrUnsigned : TernaryType<C::is_real, ConstVolatile<C>, ConstVolatileInteger<C> >::type {
		typedef const volatile typename C::to_signed to_signed;
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
		typedef typename C::to_const	      add_const;
		typedef typename C::to_const_volatile add_const_volatile;
		typedef typename C::to_volatile	      add_volatile;
		typedef typename C::type	      remove_const;
		typedef typename C::type	      remove_const_volatile;
		typedef typename C::type	      remove_volatile;
		typedef typename C::type	      to_unqualified;

#		if Z_LANGUAGE_HAS(CPP, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)
			typedef typename C::to_const_lvalue	     add_const_lvalue;
			typedef typename C::to_const_rvalue	     add_const_rvalue;
			typedef typename C::to_const_volatile_lvalue add_const_volatile_lvalue;
			typedef typename C::to_const_volatile_rvalue add_const_volatile_rvalue;
			typedef typename C::to_lvalue		     add_lvalue;
			typedef typename C::to_rvalue		     add_rvalue;
			typedef typename C::to_volatile_lvalue	     add_volatile_lvalue;
			typedef typename C::to_volatile_rvalue	     add_volatile_rvalue;
			typedef typename C::type		     remove_const_this;
			typedef typename C::type		     remove_const_volatile_this;
			typedef typename C::type		     remove_this;
			typedef typename C::type		     remove_volatile_this;
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
			typedef typename C::to_const_volatile_lvalue add_const_lvalue;
			typedef typename C::to_const_volatile_rvalue add_const_rvalue;
			typedef typename C::to_volatile_lvalue	     add_lvalue;
			typedef typename C::to_volatile_rvalue	     add_rvalue;
			typedef typename C::to_volatile		     remove_const_this;
			typedef typename C::to_volatile		     remove_this;
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
			typedef typename C::to_const_volatile_lvalue add_const_lvalue;
			typedef typename C::to_const_volatile_rvalue add_const_rvalue;
			typedef typename C::to_const_volatile_lvalue add_lvalue;
			typedef typename C::to_const_volatile_rvalue add_rvalue;
			typedef typename C::to_const_volatile_lvalue add_volatile_lvalue;
			typedef typename C::to_const_volatile_rvalue add_volatile_rvalue;
			typedef typename C::to_volatile		     remove_const_this;
			typedef typename C::to_const_volatile	     remove_this;
			typedef typename C::to_const		     remove_volatile_this;
#		endif
	};

#	if Z_LANGUAGE_HAS(CPP, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)

		template <class C> struct LValueFunction : QualifiedFunction<C> {
			enum {is_lvalue = true};

			typedef typename C::to_lvalue		     type;
			typedef typename C::to_const_lvalue	     add_const;
			typedef typename C::to_const_volatile_lvalue add_const_volatile;
			typedef typename C::to_volatile_lvalue	     add_volatile;
			typedef typename C::to_lvalue		     remove_const;
			typedef typename C::to_lvalue		     remove_const_volatile;
			typedef typename C::to_lvalue		     remove_volatile;
		};

		template <class C> struct RValueFunction : QualifiedFunction<C> {
			enum {is_rvalue = true};

			typedef typename C::to_rvalue		     type;
			typedef typename C::to_const_rvalue	     add_const;
			typedef typename C::to_const_volatile_rvalue add_const_volatile;
			typedef typename C::to_volatile_rvalue	     add_volatile;
			typedef typename C::to_rvalue		     remove_const;
			typedef typename C::to_rvalue		     remove_const_volatile;
			typedef typename C::to_rvalue		     remove_volatile;
		};

		template <class C> struct ConstLValueFunction : QualifiedFunction<C> {
			enum {	is_const	= true,
				is_const_lvalue = true,
				is_lvalue	= true
			};

			typedef typename C::to_const_lvalue	     type;
			typedef typename C::to_const_lvalue	     add_const;
			typedef typename C::to_const_volatile_lvalue add_const_volatile;
			typedef typename C::to_const_lvalue	     add_lvalue;
			typedef typename C::to_const_rvalue	     add_rvalue;
			typedef typename C::to_const_volatile_lvalue add_volatile;
			typedef typename C::to_const_volatile_lvalue add_volatile_lvalue;
			typedef typename C::to_const_volatile_rvalue add_volatile_rvalue;
			typedef typename C::to_lvalue		     remove_const;
			typedef typename C::to_lvalue		     remove_const_volatile;
			typedef typename C::to_const		     remove_this;
			typedef typename C::to_const_lvalue	     remove_volatile;
			typedef typename C::to_const		     remove_volatile_this;
		};

		template <class C> struct ConstRValueFunction : QualifiedFunction<C> {
			enum {	is_const	= true,
				is_const_rvalue = true,
				is_rvalue	= true
			};

			typedef typename C::to_const_rvalue	     type;
			typedef typename C::to_const_rvalue	     add_const;
			typedef typename C::to_const_volatile_rvalue add_const_volatile;
			typedef typename C::to_const_lvalue	     add_lvalue;
			typedef typename C::to_const_rvalue	     add_rvalue;
			typedef typename C::to_const_volatile_rvalue add_volatile;
			typedef typename C::to_const_volatile_lvalue add_volatile_lvalue;
			typedef typename C::to_const_volatile_rvalue add_volatile_rvalue;
			typedef typename C::to_rvalue		     remove_const;
			typedef typename C::to_rvalue		     remove_const_volatile;
			typedef typename C::to_const		     remove_this;
			typedef typename C::to_const_rvalue	     remove_volatile;
			typedef typename C::to_const		     remove_volatile_this;
		};

		template <class C> struct VolatileLValueFunction : QualifiedFunction<C> {
			enum {	is_lvalue	   = true,
				is_volatile	   = true,
				is_volatile_lvalue = true
			};

			typedef typename C::to_volatile_lvalue	     type;
			typedef typename C::to_const_volatile_lvalue add_const;
			typedef typename C::to_const_volatile_lvalue add_const_lvalue;
			typedef typename C::to_const_volatile_rvalue add_const_rvalue;
			typedef typename C::to_const_volatile_lvalue add_const_volatile;
			typedef typename C::to_volatile_lvalue	     add_lvalue;
			typedef typename C::to_volatile_rvalue	     add_rvalue;
			typedef typename C::to_volatile_lvalue	     add_volatile;
			typedef typename C::to_volatile_lvalue	     remove_const;
			typedef typename C::to_volatile		     remove_const_this;
			typedef typename C::to_lvalue		     remove_const_volatile;
			typedef typename C::to_volatile		     remove_this;
			typedef typename C::to_lvalue		     remove_volatile;
		};

		template <class C> struct VolatileRValueFunction : QualifiedFunction<C> {
			enum {	is_rvalue	   = true,
				is_volatile	   = true,
				is_volatile_rvalue = true
			};

			typedef typename C::to_volatile_rvalue	     type;
			typedef typename C::to_const_volatile_rvalue add_const;
			typedef typename C::to_const_volatile_lvalue add_const_lvalue;
			typedef typename C::to_const_volatile_rvalue add_const_rvalue;
			typedef typename C::to_const_volatile_rvalue add_const_volatile;
			typedef typename C::to_volatile_lvalue	     add_lvalue;
			typedef typename C::to_volatile_rvalue	     add_rvalue;
			typedef typename C::to_volatile_rvalue	     add_volatile;
			typedef typename C::to_volatile_rvalue	     remove_const;
			typedef typename C::to_volatile		     remove_const_this;
			typedef typename C::to_rvalue		     remove_const_volatile;
			typedef typename C::to_volatile		     remove_this;
			typedef typename C::to_rvalue		     remove_volatile;
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
			typedef typename C::to_const_volatile_lvalue add_const_lvalue;
			typedef typename C::to_const_volatile_rvalue add_const_rvalue;
			typedef typename C::to_const_volatile_lvalue add_const_volatile;
			typedef typename C::to_const_volatile_lvalue add_lvalue;
			typedef typename C::to_const_volatile_rvalue add_rvalue;
			typedef typename C::to_const_volatile_lvalue add_volatile;
			typedef typename C::to_const_volatile_lvalue add_volatile_lvalue;
			typedef typename C::to_const_volatile_rvalue add_volatile_rvalue;
			typedef typename C::to_volatile_lvalue	     remove_const;
			typedef typename C::to_volatile		     remove_const_this;
			typedef typename C::to_lvalue		     remove_const_volatile;
			typedef typename C::to_const_volatile	     remove_this;
			typedef typename C::to_const_lvalue	     remove_volatile;
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
			typedef typename C::to_const_volatile_lvalue add_const_lvalue;
			typedef typename C::to_const_volatile_rvalue add_const_rvalue;
			typedef typename C::to_const_volatile_rvalue add_const_volatile;
			typedef typename C::to_const_volatile_lvalue add_lvalue;
			typedef typename C::to_const_volatile_rvalue add_rvalue;
			typedef typename C::to_const_volatile_rvalue add_volatile;
			typedef typename C::to_const_volatile_lvalue add_volatile_lvalue;
			typedef typename C::to_const_volatile_rvalue add_volatile_rvalue;
			typedef typename C::to_volatile_rvalue	     remove_const;
			typedef typename C::to_volatile		     remove_const_this;
			typedef typename C::to_rvalue		     remove_const_volatile;
			typedef typename C::to_const_volatile	     remove_this;
			typedef typename C::to_const_rvalue	     remove_volatile;
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

	template <class C> struct Convertible : C {
		typedef typename C::type& add_lvalue_reference;
		typedef typename C::type* add_pointer;
		typedef typename C::type& to_lvalue_reference;
		typedef typename C::type* to_pointer;

#		if Z_LANGUAGE_HAS(CPP, RVALUE_REFERENCE)
			typedef typename C::type&& add_rvalue_reference;
			typedef typename C::type&& to_rvalue_reference;
#		endif
	};

	enum {	Void,
		Function,
		InconvertibleFunction,
		ConvertibleFunction,
		Value,
		VoidPointer,
		Pointer,
		MemberFunctionPointer,
		Reference,
		ObjectiveCObject
	};

	template <zuint K, class C> struct Kind;

	// MARK: - Mixins: Kind (virtual)

	template <class C> struct Kind<Void, C> : Virtual<C> {
		typedef typename C::type* add_pointer;
		typedef typename C::type* to_pointer;
	};

	template <class C> struct Kind<InconvertibleFunction, C> : Virtual<C> {
		typedef typename C::type to_function;
	};

	template <class C> struct Kind<ConvertibleFunction, C> : Kind<InconvertibleFunction, Convertible<C> > {};

	// MARK: - Mixins: Kind (storable)

	template <class C> struct Kind<Value, C> : Storable<Convertible<C> > {};

	template <class C> struct Kind<VoidPointer, C> : Storable<C> {
		typedef typename C::type&	 add_lvalue_reference;
		typedef typename C::type*	 add_pointer;
		typedef typename C::pointee_type remove_pointer;
		typedef typename C::type	 to_pointer;

#		if Z_TRAIT_HAS(Type, add_rvalue_reference)
			typedef typename C::type&& add_rvalue_reference;
#		endif
	};

	template <class C> struct Kind<Pointer, C> : Kind<VoidPointer, C> {
		typedef typename C::pointee_type& to_lvalue_reference;

#		if Z_TRAIT_HAS(Type, to_rvalue_reference)
			typedef typename C::pointee_type&& to_rvalue_reference;
#		endif
	};

	template <class C> struct Kind<MemberFunctionPointer, C> : Storable<C> {
		typedef typename C::pointee_type to_function;
	};

	template <class C> struct Kind<Reference, C> : Storable<C> {
		typedef NaT			     add_const;
		typedef NaT			     add_const_volatile;
		typedef NaT			     add_volatile;
		typedef typename C::type	     remove_pointer;
		typedef typename C::referencee_type  remove_reference;
		typedef NaT			     to_const;
		typedef NaT			     to_const_volatile;
		typedef typename C::referencee_type& to_lvalue_reference;
		typedef typename C::referencee_type* to_pointer;
		typedef NaT			     to_volatile;

#		if Z_TRAIT_HAS(Type, to_rvalue_reference)
			typedef typename C::referencee_type&& to_rvalue_reference;
#		endif
	};

	// MARK: - Mixins: Objective-C objects

#	if Z_LANGUAGE_INCLUDES(OBJECTIVE_CPP)
		template <class C> struct Kind<ObjectiveCObject, C> : Convertible<C> {};
#	endif
}}}}

namespace Zeta {namespace Detail {namespace Type {

	// MARK: - Specializations: Enumerations, structures, unions and Objective-C instances

	template <class T> struct Ambiguous {

		enum {	structure_detected =
#			if Z_COMPILER_HAS_TRAIT(TYPE_IS_CLASS)
				Z_COMPILER_TRAIT(TYPE_IS_CLASS)(T)
#			else
				false
#			endif
		};

		enum {	union_detected =
#			if Z_COMPILER_HAS_TRAIT(TYPE_IS_UNION)
				Z_COMPILER_TRAIT(TYPE_IS_UNION)(T)
#			else
				false
#			endif
		};

		enum {	structure_or_union_detected = structure_detected || union_detected ||
#			if Z_LANGUAGE_HAS(CPP, EXPRESSION_SFINAE)
				Helpers::IsStructureOrUnion<T, true>::value
#			else
				false
#			endif
		};

		enum {	enumeration_detected =
#			if Z_COMPILER_HAS_TRAIT(TYPE_IS_ENUMERATION)
				Z_COMPILER_TRAIT(TYPE_IS_ENUMERATION)(T)
#			elif Z_LANGUAGE_HAS(CPP, EXPRESSION_SFINAE)
				!structure_or_union_detected && Helpers::IsUsableToCastNumber<T, true>::value
#			else
				false
#			endif
		};

		enum {	objective_c_instance_detected =
			Z_LANGUAGE_INCLUDES(OBJECTIVE_C)       &&
			Z_LANGUAGE_HAS(CPP, EXPRESSION_SFINAE) &&
			!enumeration_detected		       &&
			!structure_or_union_detected
		};

		enum {	kind = enumeration_detected
				? Abstract::Enumeration
				: (union_detected
					? Abstract::Union
					: (objective_c_instance_detected
						? Abstract::ObjectiveCInstance
						: Abstract::Structure))
		};
	};

	template <Boolean E, class T> struct Case : Mixins::Unqualified<Abstract::Kind<E, Ambiguous<T>::kind, T> > {};

	// MARK: - Specializations: Fixed width numeric types

#	if Z_TRAIT_HAS(Type, is_uint8)
		template <Boolean E> struct Case<E, UInt8> : Mixins::Unqualified<Abstract::UInt8> {};
#	endif

#	if Z_TRAIT_HAS(Type, is_sint8)
		template <Boolean E> struct Case<E, SInt8> : Mixins::Unqualified<Abstract::SInt8> {};
#	endif

#	if Z_TRAIT_HAS(Type, is_uint16)
		template <Boolean E> struct Case<E, UInt16> : Mixins::Unqualified<Abstract::UInt16> {};
#	endif

#	if Z_TRAIT_HAS(Type, is_sint16)
		template <Boolean E> struct Case<E, SInt16> : Mixins::Unqualified<Abstract::SInt16> {};
#	endif

#	if Z_TRAIT_HAS(Type, is_uint32)
		template <Boolean E> struct Case<E, UInt32> : Mixins::Unqualified<Abstract::UInt32> {};
#	endif

#	if Z_TRAIT_HAS(Type, is_sint32)
		template <Boolean E> struct Case<E, SInt32> : Mixins::Unqualified<Abstract::SInt32> {};
#	endif

#	if Z_TRAIT_HAS(Type, is_uint64)
		template <Boolean E> struct Case<E, UInt64> : Mixins::Unqualified<Abstract::UInt64> {};
#	endif

#	if Z_TRAIT_HAS(Type, is_sint64)
		template <Boolean E> struct Case<E, SInt64> : Mixins::Unqualified<Abstract::SInt64> {};
#	endif

#	if Z_TRAIT_HAS(Type, is_uint128)
		template <Boolean E> struct Case<E, UInt128> : Mixins::Unqualified<Abstract::UInt128> {};
#	endif

#	if Z_TRAIT_HAS(Type, is_sint128)
		template <Boolean E> struct Case<E, SInt128> : Mixins::Unqualified<Abstract::SInt128> {};
#	endif

#	if Z_TRAIT_HAS(Type, is_float16)
		template <Boolean E> struct Case<E, Float16> : Mixins::Unqualified<Abstract::Float16> {};
#	endif

#	if Z_TRAIT_HAS(Type, is_float32)
		template <Boolean E> struct Case<E, Float32> : Mixins::Unqualified<Abstract::Float32> {};
#	endif

#	if Z_TRAIT_HAS(Type, is_float64)
		template <Boolean E> struct Case<E, Float64> : Mixins::Unqualified<Abstract::Float64> {};
#	endif

#	if Z_TRAIT_HAS(Type, is_float128)
		template <Boolean E> struct Case<E, Float128> : Mixins::Unqualified<Abstract::Float128> {};
#	endif

#	if Z_TRAIT_HAS(Type, is_float80_x87)
		template <Boolean E> struct Case<E, Float80_x87> : Mixins::Unqualified<Abstract::Float80_x87> {};
#	endif

#	if Z_TRAIT_HAS(Type, is_float96_x87)
		template <Boolean E> struct Case<E, Float96_x87> : Mixins::Unqualified<Abstract::Float96_x87> {};
#	endif

#	if Z_TRAIT_HAS(Type, is_float128_x87)
		template <Boolean E> struct Case<E, Float128_x87> : Mixins::Unqualified<Abstract::Float128_x87> {};
#	endif

	// MARK: - Specializations: C/C++ fundamental types

	template <Boolean E> struct Case<E, void  > : Mixins::Unqualified<Abstract::Void  > {};
	template <Boolean E> struct Case<E, Char  > : Mixins::Unqualified<Abstract::Char  > {};
	template <Boolean E> struct Case<E, UChar > : Mixins::Unqualified<Abstract::UChar > {};
	template <Boolean E> struct Case<E, SChar > : Mixins::Unqualified<Abstract::SChar > {};
	template <Boolean E> struct Case<E, UShort> : Mixins::Unqualified<Abstract::UShort> {};
	template <Boolean E> struct Case<E, SShort> : Mixins::Unqualified<Abstract::SShort> {};
	template <Boolean E> struct Case<E, UInt  > : Mixins::Unqualified<Abstract::UInt  > {};
	template <Boolean E> struct Case<E, SInt  > : Mixins::Unqualified<Abstract::SInt  > {};
	template <Boolean E> struct Case<E, ULong > : Mixins::Unqualified<Abstract::ULong > {};
	template <Boolean E> struct Case<E, SLong > : Mixins::Unqualified<Abstract::SLong > {};

#	ifdef Z_LLONG
		template <Boolean E> struct Case<E, ULLong> : Mixins::Unqualified<Abstract::ULLong> {};
		template <Boolean E> struct Case<E, SLLong> : Mixins::Unqualified<Abstract::SLLong> {};
#	endif

#	if Z_TRAIT_HAS(Type, is_float)
		template <Boolean E> struct Case<E, Float> : Mixins::Unqualified<Abstract::Float> {};
#	endif

#	if Z_TRAIT_HAS(Type, is_double)
		template <Boolean E> struct Case<E, Double> : Mixins::Unqualified<Abstract::Double> {};
#	endif

#	if Z_TRAIT_HAS(Type, is_ldouble)
		template <Boolean E> struct Case<E, LDouble> : Mixins::Unqualified<Abstract::LDouble> {};
#	endif

#	if Z_TRAIT_HAS(Type, is_boolean)
		template <Boolean E> struct Case<E, Boolean> : Mixins::Unqualified<Abstract::Boolean> {};
#	endif

	// MARK: - Specializations: C++ specific fundamental types

/*#	if Z_TRAIT_HAS(Type, is_wchar)
		template <Boolean E> struct Case<E, WChar> : Mixins::Unqualified<Abstract::WChar> {};
#	endif

#	if Z_TRAIT_HAS(Type, is_char16)
		template <Boolean E> struct Case<E, Char16> : Mixins::Unqualified<Abstract::Char16> {};
#	endif

#	if Z_TRAIT_HAS(Type, is_char32)
		template <Boolean E> struct Case<E, Char32> : Mixins::Unqualified<Abstract::Char32> {};
#	endif*/

#	if Z_TRAIT_HAS(Type, is_null_pointer)
		template <Boolean E> struct Case<E, NullPointer> : Mixins::Unqualified<Abstract::NullPointer> {};
#	endif

	// MARK: - Specializations: Sized arrays

	template <Boolean E, class T, USize N> struct Case<E, T[N]> : Mixins::Unqualified<Abstract::SizedArray<E, T, N> > {};

	template <Boolean E, class T, USize N> struct Case<E, const	     T[N]> : Mixins::ConstArray	       <Case<E, T[N]> > {};
	template <Boolean E, class T, USize N> struct Case<E,	    volatile T[N]> : Mixins::VolatileArray     <Case<E, T[N]> > {};
	template <Boolean E, class T, USize N> struct Case<E, const volatile T[N]> : Mixins::ConstVolatileArray<Case<E, T[N]> > {};

	// MARK: - Specializations: Flexible arrays

	template <Boolean E, class T> struct Case<E, T[]> : Mixins::Unqualified<Abstract::FlexibleArray<E, T> > {};

	template <Boolean E, class T> struct Case<E, const	    T[]> : Mixins::ConstArray	     <Case<E, T[]> > {};
	template <Boolean E, class T> struct Case<E, 	   volatile T[]> : Mixins::VolatileArray     <Case<E, T[]> > {};
	template <Boolean E, class T> struct Case<E, const volatile T[]> : Mixins::ConstVolatileArray<Case<E, T[]> > {};

	// MARK: - Specializations: Pointers

	template <Boolean E, class T> class Case<E, T*> : public Mixins::Unqualified<Abstract::Pointer<T> > {
		private:
		typedef Case<false, T> Pointee;

		public:
		enum {	is_callable	    = Pointee::is_function,
			is_function_pointer = Pointee::is_function,
			is_void_pointer	    = Pointee::is_void
		};

#		if Z_LANGUAGE_INCLUDES(OBJECTIVE_CPP)

			enum {	is_objective_c_class_pointer  = Pointee::is_objective_c_class,
				is_objective_c_object_pointer = Pointee::is_objective_c_object,
			};

#			if Z_TRAIT_HAS(Type, is_objective_c_instance_pointer)
				enum {is_objective_c_instance_pointer = Pointee::is_objective_c_instance};
#			endif

#		endif

		enum {pointer_level = Pointee::pointer_level + 1};

		typedef typename TernaryType<is_function_pointer, T, NaT>::type to_function;
	};

	template <Boolean E, class C, class T> struct Case<E, T C::*> : Mixins::Unqualified<Abstract::DataMemberPointer<T C::*, C, T> > {
		enum {pointer_level = Case<E, T>::pointer_level + 1};
	};

#	if Z_LANGUAGE_HAS(CPP, VARIADIC_TEMPLATE)

		template <Boolean E, class C, class R, class... P> struct Case<E, R(C::*)(P...)		      > : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(P...)		  , C, R(P...)		     > > {};
		template <Boolean E, class C, class R, class... P> struct Case<E, R(C::*)(P...) const	      > : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(P...) const	  , C, R(P...) const	     > > {};
		template <Boolean E, class C, class R, class... P> struct Case<E, R(C::*)(P...) const volatile> : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(P...) const volatile, C, R(P...) const volatile> > {};
		template <Boolean E, class C, class R, class... P> struct Case<E, R(C::*)(P...)	volatile      > : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(P...)	  volatile, C, R(P...)	     volatile> > {};

		template <Boolean E, class C, class R, class... P> struct Case<E, R(C::*)(P..., ...)		   > : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(P..., ...)		    , C, R(P..., ...)		    > > {};
		template <Boolean E, class C, class R, class... P> struct Case<E, R(C::*)(P..., ...) const	   > : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(P..., ...) const	    , C, R(P..., ...) const	    > > {};
		template <Boolean E, class C, class R, class... P> struct Case<E, R(C::*)(P..., ...) const volatile> : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(P..., ...) const volatile, C, R(P..., ...) const volatile> > {};
		template <Boolean E, class C, class R, class... P> struct Case<E, R(C::*)(P..., ...)	   volatile> : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(P..., ...)       volatile, C, R(P..., ...)       volatile> > {};

#		if Z_LANGUAGE_HAS(CPP, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)

			template <Boolean E, class C, class R, class... P> struct Case<E, R(C::*)(P...)		       & > : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(P...)		      & , C, R(P...)		    & > > {};
			template <Boolean E, class C, class R, class... P> struct Case<E, R(C::*)(P...)		       &&> : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(P...)		      &&, C, R(P...)		    &&> > {};
			template <Boolean E, class C, class R, class... P> struct Case<E, R(C::*)(P...) const	       & > : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(P...) const	      & , C, R(P...) const	    & > > {};
			template <Boolean E, class C, class R, class... P> struct Case<E, R(C::*)(P...) const	       &&> : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(P...) const	      &&, C, R(P...) const	    &&> > {};
			template <Boolean E, class C, class R, class... P> struct Case<E, R(C::*)(P...) const volatile & > : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(P...) const volatile & , C, R(P...) const volatile & > > {};
			template <Boolean E, class C, class R, class... P> struct Case<E, R(C::*)(P...) const volatile &&> : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(P...) const volatile &&, C, R(P...) const volatile &&> > {};
			template <Boolean E, class C, class R, class... P> struct Case<E, R(C::*)(P...)	      volatile & > : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(P...)	     volatile & , C, R(P...)	   volatile & > > {};
			template <Boolean E, class C, class R, class... P> struct Case<E, R(C::*)(P...)	      volatile &&> : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(P...)	     volatile &&, C, R(P...)	   volatile &&> > {};

			template <Boolean E, class C, class R, class... P> struct Case<E, R(C::*)(P..., ...)		    & > : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(P..., ...)		& , C, R(P..., ...)		   & > > {};
			template <Boolean E, class C, class R, class... P> struct Case<E, R(C::*)(P..., ...)		    &&> : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(P..., ...)		&&, C, R(P..., ...)		   &&> > {};
			template <Boolean E, class C, class R, class... P> struct Case<E, R(C::*)(P..., ...) const	    & > : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(P..., ...) const		& , C, R(P..., ...) const	   & > > {};
			template <Boolean E, class C, class R, class... P> struct Case<E, R(C::*)(P..., ...) const	    &&> : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(P..., ...) const		&&, C, R(P..., ...) const	   &&> > {};
			template <Boolean E, class C, class R, class... P> struct Case<E, R(C::*)(P..., ...) const volatile & > : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(P..., ...) const volatile & , C, R(P..., ...) const volatile & > > {};
			template <Boolean E, class C, class R, class... P> struct Case<E, R(C::*)(P..., ...) const volatile &&> : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(P..., ...) const volatile &&, C, R(P..., ...) const volatile &&> > {};
			template <Boolean E, class C, class R, class... P> struct Case<E, R(C::*)(P..., ...)	   volatile & > : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(P..., ...)       volatile & , C, R(P..., ...)	  volatile & > > {};
			template <Boolean E, class C, class R, class... P> struct Case<E, R(C::*)(P..., ...)	   volatile &&> : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(P..., ...)       volatile &&, C, R(P..., ...)	  volatile &&> > {};

#		endif

#	else

		template <Boolean E, class C, class R> struct Case<E, R(C::*)()		      > : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)()		      , C, R()		     > > {};
		template <Boolean E, class C, class R> struct Case<E, R(C::*)() const	      > : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)() const	      , C, R() const	     > > {};
		template <Boolean E, class C, class R> struct Case<E, R(C::*)() const volatile> : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)() const volatile, C, R() const volatile> > {};
		template <Boolean E, class C, class R> struct Case<E, R(C::*)()	      volatile> : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)()	      volatile, C, R()	     volatile> > {};

#		define Z_TEMPLATE_SPECIALIZATIONS(parameter_count)																																													    \
																																																					    \
		template <Boolean E, class C, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct Case<E, R(C::*)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA))		  > : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA))		    , C, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA))		     > > {};		    \
		template <Boolean E, class C, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct Case<E, R(C::*)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA)) const	  > : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA)) const	    , C, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA)) const	     > > {};		    \
		template <Boolean E, class C, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct Case<E, R(C::*)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA)) const volatile> : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA)) const volatile, C, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA)) const volatile> > {};		    \
		template <Boolean E, class C, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct Case<E, R(C::*)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA))	  volatile> : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA))	    volatile, C, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA))	     volatile> > {};		    \
																																																					    \
		template <Boolean E, class C, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct Case<E, R(C::*)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...)	       > : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...)		      , C, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...)		    > > {}; \
		template <Boolean E, class C, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct Case<E, R(C::*)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...) const	       > : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...) const	      , C, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...) const	    > > {}; \
		template <Boolean E, class C, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct Case<E, R(C::*)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...) const volatile> : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...) const volatile, C, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...) const volatile> > {}; \
		template <Boolean E, class C, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct Case<E, R(C::*)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...)       volatile> : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...)	      volatile, C, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...)	    volatile> > {};

		Z_FOR_32_CALL_WITH_TIME(Z_TEMPLATE_SPECIALIZATIONS, Z_EMPTY)
#		undef Z_TEMPLATE_SPECIALIZATIONS

#		if Z_LANGUAGE_HAS(CPP, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)

			template <Boolean E, class C, class R> struct Case<E, R(C::*)()		       & > : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)()		  & , C, R()		    & > > {};
			template <Boolean E, class C, class R> struct Case<E, R(C::*)()		       &&> : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)()		  &&, C, R()		    &&> > {};
			template <Boolean E, class C, class R> struct Case<E, R(C::*)() const	       & > : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)() const	  & , C, R() const	    & > > {};
			template <Boolean E, class C, class R> struct Case<E, R(C::*)() const	       &&> : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)() const	  &&, C, R() const	    &&> > {};
			template <Boolean E, class C, class R> struct Case<E, R(C::*)() const volatile & > : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)() const volatile & , C, R() const volatile & > > {};
			template <Boolean E, class C, class R> struct Case<E, R(C::*)() const volatile &&> : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)() const volatile &&, C, R() const volatile &&> > {};
			template <Boolean E, class C, class R> struct Case<E, R(C::*)()	      volatile & > : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)()	 volatile & , C, R()	   volatile & > > {};
			template <Boolean E, class C, class R> struct Case<E, R(C::*)()	      volatile &&> : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)()	 volatile &&, C, R()	   volatile &&> > {};

#			define Z_TEMPLATE_SPECIALIZATIONS(parameter_count)																																														     \
																																																							     \
			template <Boolean E, class C, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct Case<E, R(C::*)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA))		   & > : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA))		& , C, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA))		    & > > {};		     \
			template <Boolean E, class C, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct Case<E, R(C::*)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA))		   &&> : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA))		&&, C, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA))		    &&> > {};		     \
			template <Boolean E, class C, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct Case<E, R(C::*)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA)) const	   & > : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA)) const		& , C, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA)) const	    & > > {};		     \
			template <Boolean E, class C, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct Case<E, R(C::*)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA)) const	   &&> : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA)) const		&&, C, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA)) const	    &&> > {};		     \
			template <Boolean E, class C, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct Case<E, R(C::*)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA)) const volatile & > : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA)) const volatile & , C, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA)) const volatile & > > {};		     \
			template <Boolean E, class C, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct Case<E, R(C::*)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA)) const volatile &&> : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA)) const volatile &&, C, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA)) const volatile &&> > {};		     \
			template <Boolean E, class C, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct Case<E, R(C::*)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA))	  volatile & > : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA))       volatile & , C, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA))	   volatile & > > {};		     \
			template <Boolean E, class C, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct Case<E, R(C::*)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA))	  volatile &&> : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA))       volatile &&, C, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA))	   volatile &&> > {};		     \
																																																							     \
			template <Boolean E, class C, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct Case<E, R(C::*)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...)		& > : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...)		  & , C, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...)		   & > > {}; \
			template <Boolean E, class C, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct Case<E, R(C::*)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...)		&&> : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...)		  &&, C, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...)		   &&> > {}; \
			template <Boolean E, class C, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct Case<E, R(C::*)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...) const		& > : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...) const	  & , C, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...) const	   & > > {}; \
			template <Boolean E, class C, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct Case<E, R(C::*)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...) const		&&> : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...) const	  &&, C, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...) const	   &&> > {}; \
			template <Boolean E, class C, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct Case<E, R(C::*)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...) const volatile & > : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...) const volatile & , C, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...) const volatile & > > {}; \
			template <Boolean E, class C, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct Case<E, R(C::*)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...) const volatile &&> : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...) const volatile &&, C, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...) const volatile &&> > {}; \
			template <Boolean E, class C, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct Case<E, R(C::*)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...)       volatile & > : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...)	 volatile & , C, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...)	  volatile & > > {}; \
			template <Boolean E, class C, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct Case<E, R(C::*)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...)       volatile &&> : Mixins::Unqualified<Abstract::MemberFunctionPointer<R(C::*)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...)	 volatile &&, C, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...)	  volatile &&> > {};

			Z_FOR_32_CALL_WITH_TIME(Z_TEMPLATE_SPECIALIZATIONS, Z_EMPTY)
#			undef Z_TEMPLATE_SPECIALIZATIONS

#		endif

#	endif

	// MARK: - Specializations: References

	template <Boolean E, class T> struct Case<E, T&> : Mixins::Unqualified<Abstract::LValueReference<T> > {
		enum {	is_function_reference	     = Case<false, T>::is_function,
			is_function_lvalue_reference = is_function_reference,
			is_callable		     = is_function_reference
		};

		typedef typename TernaryType<is_function_reference, T, NaT>::type to_function;
	};

#	if Z_TRAIT_HAS(Type, is_rvalue_reference)

		template <Boolean E, class T> struct Case<E, T&&> : Mixins::Unqualified<Abstract::RValueReference<T> > {
			enum {	is_function_reference	     = Case<false, T>::is_function,
				is_function_rvalue_reference = is_function_reference,
				is_callable		     = is_function_reference
			};

			typedef typename TernaryType<is_function_reference, T, NaT>::type to_function;
		};

#	endif

	// MARK: - Specializations: Functions

#	if Z_LANGUAGE_HAS(CPP, VARIADIC_TEMPLATE)

		template <Boolean E, class R, class... P> struct Case<E, R(P...)> : Mixins::UnqualifiedFunction<Abstract::Function<R, P...> > {};

		template <Boolean E, class R, class... P> struct Case<E, R(P...) const	       > : Mixins::ConstFunction	<Case<E, R(P...)> > {};
		template <Boolean E, class R, class... P> struct Case<E, R(P...) const volatile> : Mixins::ConstVolatileFunction<Case<E, R(P...)> > {};
		template <Boolean E, class R, class... P> struct Case<E, R(P...)       volatile> : Mixins::VolatileFunction	<Case<E, R(P...)> > {};

		template <Boolean E, class R, class... P> struct Case<E, R(P..., ...)> : Mixins::UnqualifiedFunction<Abstract::VariadicFunction<R, P...> > {};

		template <Boolean E, class R, class... P> struct Case<E, R(P..., ...) const	    > : Mixins::ConstFunction	     <Case<E, R(P..., ...)> > {};
		template <Boolean E, class R, class... P> struct Case<E, R(P..., ...) const volatile> : Mixins::ConstVolatileFunction<Case<E, R(P..., ...)> > {};
		template <Boolean E, class R, class... P> struct Case<E, R(P..., ...)	    volatile> : Mixins::VolatileFunction     <Case<E, R(P..., ...)> > {};

#		if Z_LANGUAGE_HAS(CPP, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)

			template <Boolean E, class R, class... P> struct Case<E, R(P...)		& > : Mixins::LValueFunction		 <Case<E, R(P...)> > {};
			template <Boolean E, class R, class... P> struct Case<E, R(P...)		&&> : Mixins::RValueFunction		 <Case<E, R(P...)> > {};
			template <Boolean E, class R, class... P> struct Case<E, R(P...) const		& > : Mixins::ConstLValueFunction	 <Case<E, R(P...)> > {};
			template <Boolean E, class R, class... P> struct Case<E, R(P...) const		&&> : Mixins::ConstRValueFunction	 <Case<E, R(P...)> > {};
			template <Boolean E, class R, class... P> struct Case<E, R(P...) const volatile & > : Mixins::ConstVolatileLValueFunction<Case<E, R(P...)> > {};
			template <Boolean E, class R, class... P> struct Case<E, R(P...) const volatile &&> : Mixins::ConstVolatileRValueFunction<Case<E, R(P...)> > {};
			template <Boolean E, class R, class... P> struct Case<E, R(P...)       volatile & > : Mixins::VolatileLValueFunction	 <Case<E, R(P...)> > {};
			template <Boolean E, class R, class... P> struct Case<E, R(P...)       volatile &&> : Mixins::VolatileRValueFunction	 <Case<E, R(P...)> > {};

			template <Boolean E, class R, class... P> struct Case<E, R(P..., ...)		     & > : Mixins::LValueFunction	      <Case<E, R(P..., ...)> > {};
			template <Boolean E, class R, class... P> struct Case<E, R(P..., ...)		     &&> : Mixins::RValueFunction	      <Case<E, R(P..., ...)> > {};
			template <Boolean E, class R, class... P> struct Case<E, R(P..., ...) const	     & > : Mixins::ConstLValueFunction	      <Case<E, R(P..., ...)> > {};
			template <Boolean E, class R, class... P> struct Case<E, R(P..., ...) const	     &&> : Mixins::ConstRValueFunction	      <Case<E, R(P..., ...)> > {};
			template <Boolean E, class R, class... P> struct Case<E, R(P..., ...) const volatile & > : Mixins::ConstVolatileLValueFunction<Case<E, R(P..., ...)> > {};
			template <Boolean E, class R, class... P> struct Case<E, R(P..., ...) const volatile &&> : Mixins::ConstVolatileRValueFunction<Case<E, R(P..., ...)> > {};
			template <Boolean E, class R, class... P> struct Case<E, R(P..., ...)	    volatile & > : Mixins::VolatileLValueFunction     <Case<E, R(P..., ...)> > {};
			template <Boolean E, class R, class... P> struct Case<E, R(P..., ...)	    volatile &&> : Mixins::VolatileRValueFunction     <Case<E, R(P..., ...)> > {};

#		endif

#	else

		template <Boolean E, class R> struct Case<E, R()> : Mixins::UnqualifiedFunction<Abstract::FunctionWith0Parameters<R> > {};

		template <Boolean E, class R> struct Case<E, R() const	       > : Mixins::ConstFunction	<Case<E, R()> > {};
		template <Boolean E, class R> struct Case<E, R() const volatile> : Mixins::ConstVolatileFunction<Case<E, R()> > {};
		template <Boolean E, class R> struct Case<E, R()       volatile> : Mixins::VolatileFunction	<Case<E, R()> > {};

#		define Z_TEMPLATE_SPECIALIZATIONS(parameter_count)																																	  \
																																									  \
		template <Boolean E, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct Case<E, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA))> : Mixins::UnqualifiedFunction<Abstract::FunctionWith##parameter_count##Parameters<R, Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA)> > {};		  \
																																									  \
		template <Boolean E, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct Case<E, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA)) const	   > : Mixins::ConstFunction	    <Case<E, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA))> > {};					  \
		template <Boolean E, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct Case<E, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA)) const volatile> : Mixins::ConstVolatileFunction<Case<E, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA))> > {};					  \
		template <Boolean E, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct Case<E, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA))	   volatile> : Mixins::VolatileFunction     <Case<E, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA))> > {};					  \
																																									  \
		template <Boolean E, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct Case<E, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...)> : Mixins::UnqualifiedFunction<Abstract::VariadicFunctionWith##parameter_count##Parameters<R, Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA)> > {}; \
																																									  \
		template <Boolean E, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct Case<E, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...) const		> : Mixins::ConstFunction	 <Case<E, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...)> > {};				  \
		template <Boolean E, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct Case<E, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...) const volatile> : Mixins::ConstVolatileFunction<Case<E, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...)> > {};				  \
		template <Boolean E, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct Case<E, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...)	volatile> : Mixins::VolatileFunction	 <Case<E, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...)> > {};

		Z_FOR_32_CALL_WITH_TIME(Z_TEMPLATE_SPECIALIZATIONS, Z_EMPTY)
#		undef Z_TEMPLATE_SPECIALIZATIONS

#		if Z_LANGUAGE_HAS(CPP, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)

			template <Boolean E, class R> struct Case<E, R()		& > : Mixins::LValueFunction		 <Case<E, R()> > {};
			template <Boolean E, class R> struct Case<E, R()		&&> : Mixins::RValueFunction		 <Case<E, R()> > {};
			template <Boolean E, class R> struct Case<E, R() const		& > : Mixins::ConstLValueFunction	 <Case<E, R()> > {};
			template <Boolean E, class R> struct Case<E, R() const		&&> : Mixins::ConstRValueFunction	 <Case<E, R()> > {};
			template <Boolean E, class R> struct Case<E, R() const volatile & > : Mixins::ConstVolatileLValueFunction<Case<E, R()> > {};
			template <Boolean E, class R> struct Case<E, R() const volatile &&> : Mixins::ConstVolatileRValueFunction<Case<E, R()> > {};
			template <Boolean E, class R> struct Case<E, R()       volatile & > : Mixins::VolatileLValueFunction	 <Case<E, R()> > {};
			template <Boolean E, class R> struct Case<E, R()       volatile &&> : Mixins::VolatileRValueFunction	 <Case<E, R()> > {};

#			define Z_TEMPLATE_SPECIALIZATIONS(parameter_count)																														     \
																																							     \
			template <Boolean E, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct Case<E, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA))		    & > : Mixins::LValueFunction	     <Case<E, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA))> > {};	     \
			template <Boolean E, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct Case<E, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA))		    &&> : Mixins::RValueFunction	     <Case<E, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA))> > {};	     \
			template <Boolean E, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct Case<E, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA)) const	    & > : Mixins::ConstLValueFunction	     <Case<E, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA))> > {};	     \
			template <Boolean E, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct Case<E, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA)) const	    &&> : Mixins::ConstRValueFunction	     <Case<E, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA))> > {};	     \
			template <Boolean E, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct Case<E, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA)) const volatile & > : Mixins::ConstVolatileLValueFunction<Case<E, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA))> > {};	     \
			template <Boolean E, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct Case<E, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA)) const volatile &&> : Mixins::ConstVolatileRValueFunction<Case<E, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA))> > {};	     \
			template <Boolean E, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct Case<E, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA))	   volatile & > : Mixins::VolatileLValueFunction     <Case<E, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA))> > {};	     \
			template <Boolean E, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct Case<E, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA))	   volatile &&> : Mixins::VolatileRValueFunction     <Case<E, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA))> > {};	     \
																																							     \
			template <Boolean E, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct Case<E, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...)		 & > : Mixins::LValueFunction		  <Case<E, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...)> > {}; \
			template <Boolean E, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct Case<E, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...)		 &&> : Mixins::RValueFunction		  <Case<E, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...)> > {}; \
			template <Boolean E, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct Case<E, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...) const		 & > : Mixins::ConstLValueFunction	  <Case<E, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...)> > {}; \
			template <Boolean E, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct Case<E, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...) const		 &&> : Mixins::ConstRValueFunction	  <Case<E, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...)> > {}; \
			template <Boolean E, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct Case<E, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...) const volatile & > : Mixins::ConstVolatileLValueFunction<Case<E, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...)> > {}; \
			template <Boolean E, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct Case<E, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...) const volatile &&> : Mixins::ConstVolatileRValueFunction<Case<E, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...)> > {}; \
			template <Boolean E, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct Case<E, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...)	volatile & > : Mixins::VolatileLValueFunction	  <Case<E, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...)> > {}; \
			template <Boolean E, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct Case<E, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...)	volatile &&> : Mixins::VolatileRValueFunction	  <Case<E, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...)> > {};

			Z_FOR_32_CALL_WITH_TIME(Z_TEMPLATE_SPECIALIZATIONS, Z_EMPTY)
#			undef Z_TEMPLATE_SPECIALIZATIONS

#		endif

#	endif

	// MARK: - Specializations: Apple blocks

	// MARK: - Specializations: Objective-C

#	if Z_LANGUAGE_INCLUDES(OBJECTIVE_CPP)
		template <Boolean E> struct Case<E, Helpers::RemovePointer<id	>::type> : Mixins::Unqualified<Abstract::ObjectiveCObject> {};
		template <Boolean E> struct Case<E, Helpers::RemovePointer<Class>::type> : Mixins::Unqualified<Abstract::ObjectiveCClass > {};
#	endif

	// MARK: - Specializations: Qualified types

	template <Boolean E, class T> struct Case<E, const	    T> : TernaryType<Case<false, T>::is_signed_or_unsigned, Mixins::ConstSignedOrUnsigned	 <Case<E, T> >, Mixins::Const	     <Case<E, T> > >::type {};
	template <Boolean E, class T> struct Case<E, const volatile T> : TernaryType<Case<false, T>::is_signed_or_unsigned, Mixins::ConstVolatileSignedOrUnsigned<Case<E, T> >, Mixins::ConstVolatile<Case<E, T> > >::type {};
	template <Boolean E, class T> struct Case<E, 	   volatile T> : TernaryType<Case<false, T>::is_signed_or_unsigned, Mixins::VolatileSignedOrUnsigned	 <Case<E, T> >, Mixins::Volatile     <Case<E, T> > >::type {};

	// MARK: - Final aggregate

	template <class T> struct Final : Mixins::Kind<
		Case<false, T>::is_storable
			? (Case<false, T>::is_pointer
				? (Case<false, T>::is_member_function_pointer
					? Mixins::MemberFunctionPointer
					: (Case<false, T>::is_void_pointer ? Mixins::VoidPointer : Mixins::Pointer))
				: (Case<false, T>::is_reference
					? Mixins::Reference
					: Mixins::Value))
			: (Case<false, T>::is_void
				? Mixins::Void
				: (Case<false, T>::is_function && Case<false, T>::is_qualified
					? Mixins::InconvertibleFunction
					: Mixins::ConvertibleFunction)),
		Case<true, T>
	> {
		typedef typename TernaryType<
			Final::is_structure_or_union,
			typename Final<const typename Final::remove_const_volatile>::add_lvalue_reference, T
		>::type to_forwardable;
	};

	template <> struct Final<		NaT> : Abstract::Invalid {};
	template <> struct Final<const		NaT> : Abstract::Invalid {};
	template <> struct Final<const volatile NaT> : Abstract::Invalid {};
	template <> struct Final<      volatile NaT> : Abstract::Invalid {};
}}}

namespace Zeta {

	template <class A, class B> struct TypeAreEqual	      : False {};
	template <class A	  > struct TypeAreEqual<A, A> : True  {};

#	if Z_HAS_TRAIT(TypeIsAssignable)

		template <class T, class from_type> struct TypeIsAssignable {
			enum {value = Z_COMPILER_TRAIT(TYPE_IS_ASSIGNABLE)(T, from_type)};
		};

#	endif

#	if Z_HAS_TRAIT(TypeIsBase)

		template <class T, class of_type> struct TypeIsBase {
			enum {value = Z_COMPILER_TRAIT(TYPE_IS_BASE)(T, of_type)};
		};

#	endif

#	if Z_LANGUAGE_HAS(CPP, EXPRESSION_SFINAE)

		namespace {
			template <class T, SInt at_line> struct TypeIsComplete	 : Detail::Type::Helpers::IsComplete  <T, at_line, true> {};
			template <class T, SInt at_line> struct TypeIsIncomplete : Detail::Type::Helpers::IsIncomplete<T, at_line, true> {};
		}

#	endif

#	if Z_HAS_TRAIT(TypeIsConvertible)

		template <class T, class to_type> struct TypeIsConvertible {
			enum {value = Z_COMPILER_TRAIT(TYPE_IS_CONVERTIBLE)(T, to_type)};
		};

#	endif

#	if Z_HAS_TRAIT(TypeIsConstructible)

		template <class T, class... parameters> struct TypeIsConstructible {
			enum {value = Z_COMPILER_TRAIT(TYPE_IS_CONSTRUCTIBLE)(T, parameters...)};
		};

#	endif

#	if Z_LANGUAGE_HAS(CPP, EXPRESSION_SFINAE) && Z_LANGUAGE_HAS_SPECIFIER(CPP, DECLARED_TYPE)

		template <class T, class compatible_call_prototype> struct TypeIsFunctional;
		template <class T, class compatible_call_prototype> struct TypeIsFunctor;

#		if Z_LANGUAGE_HAS(CPP, VARIADIC_TEMPLATE)

			template <class T, class R, class... P> struct TypeIsFunctional<T, R(P...)> : Detail::Type::Helpers::IsFunctional<T, R(P...), R> {};
			template <class T, class R, class... P> struct TypeIsFunctor   <T, R(P...)> : Detail::Type::Helpers::IsFunctor	 <T, R(P...), R> {};

#		else

			template <class T, class R> struct TypeIsFunctional<T, R()> : Detail::Type::Helpers::IsFunctional<T, R(), R> {};
			template <class T, class R> struct TypeIsFunctor   <T, R()> : Detail::Type::Helpers::IsFunctor	 <T, R(), R> {};

#			define Z_TEMPLATE_SPECIALIZATIONS(parameter_count)							       \
																       \
			template <class T, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct TypeIsFunctional< \
				T, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA))					       \
			> : Detail::Type::Helpers::IsFunctional<T, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA)), R> {};       \
																       \
			template <class T, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct TypeIsFunctor<    \
				T, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA))					       \
			> : Detail::Type::Helpers::IsFunctor<T, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA)), R> {};

			Z_FOR_32_CALL_WITH_TIME(Z_TEMPLATE_SPECIALIZATIONS, Z_EMPTY)
#			undef Z_TEMPLATE_SPECIALIZATIONS

#		endif

#	endif

#	if Z_HAS_TRAIT(TypeIsNothrowAssignable)

		template <class T, class from_type> struct TypeIsNothrowAssignable {
			enum {value = Z_COMPILER_TRAIT(TYPE_IS_NOTHROW_ASSIGNABLE)(T, from_type)};
		};

#	endif

#	if Z_HAS_TRAIT(TypeIsNothrowConstructible)

		template <class T, class... parameters> struct TypeIsNothrowConstructible {
			enum {value = Z_COMPILER_TRAIT(TYPE_IS_NOTHROW_CONSTRUCTIBLE)(T, parameters...)};
		};

#	endif

#	if Z_HAS_TRAIT(TypeIsTriviallyAssignable)

		template <class T, class from_type> struct TypeIsTriviallyAssignable {
			enum {value = Z_COMPILER_TRAIT(TYPE_IS_TRIVIALLY_ASSIGNABLE)(T, from_type)};
		};

#	endif

#	if Z_HAS_TRAIT(TypeIsTriviallyConstructible)

		template <class T, class... parameters> struct TypeIsTriviallyConstructible {
			enum {value = Z_COMPILER_TRAIT(TYPE_IS_TRIVIALLY_CONSTRUCTIBLE)(T, parameters...)};
		};

#	endif

	template <class T, class klass> struct TypeToMemberPointer;

	template <class T, class C> struct TypeToMemberPointer {typedef T C::*type;};

	template <class C> struct TypeToMemberPointer<		     void, C> {typedef NaT type;};
	template <class C> struct TypeToMemberPointer<const	     void, C> {typedef NaT type;};
	template <class C> struct TypeToMemberPointer<const volatile void, C> {typedef NaT type;};
	template <class C> struct TypeToMemberPointer<	    volatile void, C> {typedef NaT type;};

#	if Z_LANGUAGE_HAS(CPP, VARIADIC_TEMPLATE)

		template <class C, class R, class... P> struct TypeToMemberPointer<R(P...)		 , C> {typedef R(C::*type)(P...)	       ;};
		template <class C, class R, class... P> struct TypeToMemberPointer<R(P...) const	 , C> {typedef R(C::*type)(P...) const	       ;};
		template <class C, class R, class... P> struct TypeToMemberPointer<R(P...) const volatile, C> {typedef R(C::*type)(P...) const volatile;};
		template <class C, class R, class... P> struct TypeToMemberPointer<R(P...)	 volatile, C> {typedef R(C::*type)(P...)       volatile;};

		template <class C, class R, class... P> struct TypeToMemberPointer<R(P..., ...)		      , C> {typedef R(C::*type)(P..., ...)		 ;};
		template <class C, class R, class... P> struct TypeToMemberPointer<R(P..., ...) const	      , C> {typedef R(C::*type)(P..., ...) const	 ;};
		template <class C, class R, class... P> struct TypeToMemberPointer<R(P..., ...) const volatile, C> {typedef R(C::*type)(P..., ...) const volatile;};
		template <class C, class R, class... P> struct TypeToMemberPointer<R(P..., ...)	      volatile, C> {typedef R(C::*type)(P..., ...)	 volatile;};

#		if Z_LANGUAGE_HAS(CPP, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)

			template <class C, class R, class... P> struct TypeToMemberPointer<R(P...)		  & , C> {typedef R(C::*type)(P...)		   & ;};
			template <class C, class R, class... P> struct TypeToMemberPointer<R(P...)		  &&, C> {typedef R(C::*type)(P...)		   &&;};
			template <class C, class R, class... P> struct TypeToMemberPointer<R(P...) const	  & , C> {typedef R(C::*type)(P...) const	   & ;};
			template <class C, class R, class... P> struct TypeToMemberPointer<R(P...) const	  &&, C> {typedef R(C::*type)(P...) const	   &&;};
			template <class C, class R, class... P> struct TypeToMemberPointer<R(P...) const volatile & , C> {typedef R(C::*type)(P...) const volatile & ;};
			template <class C, class R, class... P> struct TypeToMemberPointer<R(P...) const volatile &&, C> {typedef R(C::*type)(P...) const volatile &&;};
			template <class C, class R, class... P> struct TypeToMemberPointer<R(P...)	 volatile & , C> {typedef R(C::*type)(P...)	  volatile & ;};
			template <class C, class R, class... P> struct TypeToMemberPointer<R(P...)	 volatile &&, C> {typedef R(C::*type)(P...)	  volatile &&;};

			template <class C, class R, class... P> struct TypeToMemberPointer<R(P..., ...)		       & , C> {typedef R(C::*type)(P..., ...)		     & ;};
			template <class C, class R, class... P> struct TypeToMemberPointer<R(P..., ...)		       &&, C> {typedef R(C::*type)(P..., ...)		     &&;};
			template <class C, class R, class... P> struct TypeToMemberPointer<R(P..., ...) const	       & , C> {typedef R(C::*type)(P..., ...) const	     & ;};
			template <class C, class R, class... P> struct TypeToMemberPointer<R(P..., ...) const	       &&, C> {typedef R(C::*type)(P..., ...) const	     &&;};
			template <class C, class R, class... P> struct TypeToMemberPointer<R(P..., ...) const volatile & , C> {typedef R(C::*type)(P..., ...) const volatile & ;};
			template <class C, class R, class... P> struct TypeToMemberPointer<R(P..., ...) const volatile &&, C> {typedef R(C::*type)(P..., ...) const volatile &&;};
			template <class C, class R, class... P> struct TypeToMemberPointer<R(P..., ...)	      volatile & , C> {typedef R(C::*type)(P..., ...)	    volatile & ;};
			template <class C, class R, class... P> struct TypeToMemberPointer<R(P..., ...)	      volatile &&, C> {typedef R(C::*type)(P..., ...)	    volatile &&;};

#		endif

#	else

		template <class C, class R> struct TypeToMemberPointer<R()		 , C> {typedef R(C::*type)()		   ;};
		template <class C, class R> struct TypeToMemberPointer<R() const	 , C> {typedef R(C::*type)() const	   ;};
		template <class C, class R> struct TypeToMemberPointer<R() const volatile, C> {typedef R(C::*type)() const volatile;};
		template <class C, class R> struct TypeToMemberPointer<R()	 volatile, C> {typedef R(C::*type)()       volatile;};

#		define Z_TEMPLATE_SPECIALIZATIONS(parameter_count)																													       \
																																					       \
		template <class C, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct TypeToMemberPointer<R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA))		     , C> {typedef R(C::*type)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA))		 ;};	       \
		template <class C, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct TypeToMemberPointer<R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA)) const	     , C> {typedef R(C::*type)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA)) const	 ;};	       \
		template <class C, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct TypeToMemberPointer<R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA)) const volatile, C> {typedef R(C::*type)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA)) const volatile;};	       \
		template <class C, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct TypeToMemberPointer<R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA))	     volatile, C> {typedef R(C::*type)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA))	 volatile;};	       \
																																					       \
		template <class C, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct TypeToMemberPointer<R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...)		  , C> {typedef R(C::*type)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...)		   ;}; \
		template <class C, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct TypeToMemberPointer<R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...) const	  , C> {typedef R(C::*type)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...) const	   ;}; \
		template <class C, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct TypeToMemberPointer<R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...) const volatile, C> {typedef R(C::*type)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...) const volatile;}; \
		template <class C, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct TypeToMemberPointer<R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...)	  volatile, C> {typedef R(C::*type)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...)	   volatile;};

		Z_FOR_32_CALL_WITH_TIME(Z_TEMPLATE_SPECIALIZATIONS, Z_EMPTY)
#		undef Z_TEMPLATE_SPECIALIZATIONS

#		if Z_LANGUAGE_HAS(CPP, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)

			template <class C, class R> struct TypeToMemberPointer<R()		  & , C> {typedef R(C::*type)()		       & ;};
			template <class C, class R> struct TypeToMemberPointer<R()		  &&, C> {typedef R(C::*type)()		       &&;};
			template <class C, class R> struct TypeToMemberPointer<R() const	  & , C> {typedef R(C::*type)() const	       & ;};
			template <class C, class R> struct TypeToMemberPointer<R() const	  &&, C> {typedef R(C::*type)() const	       &&;};
			template <class C, class R> struct TypeToMemberPointer<R() const volatile & , C> {typedef R(C::*type)() const volatile & ;};
			template <class C, class R> struct TypeToMemberPointer<R() const volatile &&, C> {typedef R(C::*type)() const volatile &&;};
			template <class C, class R> struct TypeToMemberPointer<R()	 volatile & , C> {typedef R(C::*type)()	      volatile & ;};
			template <class C, class R> struct TypeToMemberPointer<R()	 volatile &&, C> {typedef R(C::*type)()	      volatile &&;};

#			define Z_TEMPLATE_SPECIALIZATIONS(parameter_count)																														     \
																																							     \
			template <class C, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct TypeToMemberPointer<R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA))		      & , C> {typedef R(C::*type)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA))		     & ;};	     \
			template <class C, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct TypeToMemberPointer<R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA))		      &&, C> {typedef R(C::*type)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA))		     &&;};	     \
			template <class C, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct TypeToMemberPointer<R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA)) const	      & , C> {typedef R(C::*type)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA)) const	     & ;};	     \
			template <class C, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct TypeToMemberPointer<R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA)) const	      &&, C> {typedef R(C::*type)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA)) const	     &&;};	     \
			template <class C, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct TypeToMemberPointer<R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA)) const volatile & , C> {typedef R(C::*type)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA)) const volatile & ;};	     \
			template <class C, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct TypeToMemberPointer<R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA)) const volatile &&, C> {typedef R(C::*type)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA)) const volatile &&;};	     \
			template <class C, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct TypeToMemberPointer<R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA))	     volatile & , C> {typedef R(C::*type)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA))	    volatile & ;};	     \
			template <class C, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct TypeToMemberPointer<R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA))	     volatile &&, C> {typedef R(C::*type)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA))	    volatile &&;};	     \
																																							     \
			template <class C, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct TypeToMemberPointer<R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...)		   & , C> {typedef R(C::*type)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...)		       & ;}; \
			template <class C, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct TypeToMemberPointer<R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...)		   &&, C> {typedef R(C::*type)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...)		       &&;}; \
			template <class C, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct TypeToMemberPointer<R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...) const	   & , C> {typedef R(C::*type)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...) const	       & ;}; \
			template <class C, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct TypeToMemberPointer<R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...) const	   &&, C> {typedef R(C::*type)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...) const	       &&;}; \
			template <class C, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct TypeToMemberPointer<R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...) const volatile & , C> {typedef R(C::*type)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...) const volatile & ;}; \
			template <class C, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct TypeToMemberPointer<R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...) const volatile &&, C> {typedef R(C::*type)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...) const volatile &&;}; \
			template <class C, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct TypeToMemberPointer<R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...)	  volatile & , C> {typedef R(C::*type)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...)	      volatile & ;}; \
			template <class C, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct TypeToMemberPointer<R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...)	  volatile &&, C> {typedef R(C::*type)(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA), ...)	      volatile &&;};

			Z_FOR_32_CALL_WITH_TIME(Z_TEMPLATE_SPECIALIZATIONS, Z_EMPTY)
#			undef Z_TEMPLATE_SPECIALIZATIONS

#		endif

#	endif

	template <class T> class Type : public Detail::Type::Final<T> {
		public:

#		if Z_TRAIT_HAS(Type, to_member_pointer)
			template <class klass> using to_member_pointer = typename TypeToMemberPointer<typename Type::type, klass>::type;
#		endif

#		if Z_COMPILER_HAS_MAGIC_CONSTANT(MANGLED_FUNCTION_NAME) && Z_LANGUAGE_HAS(CPP, CPP14_RULES_ON_CONSTANT_EXPRESSION_FUNCTION)

#			define Z_IMPLEMENTATION_MEMBER_FUNCTIONS							       \
				static Z_CT(CPP14) USize		      string_size() {return type_string_size  <T>() ;} \
				static Z_CT(CPP14) SizedString<string_size()> string	 () {return type_string       <T>() ;} \
				static Z_CT(CPP14) Symbol		      symbol	 () {return Symbol(type_string<T>());}

			Z_IMPLEMENTATION_MEMBER_FUNCTIONS
#		else
#			define Z_IMPLEMENTATION_MEMBER_FUNCTIONS
#		endif

		struct flow {
			enum {	is_arithmetic		     = Type::is_arithmetic,
				is_array		     = Type::is_array,
				is_callable		     = Type::is_callable,
				is_char			     = Type::is_char,
				is_class		     = Type::is_class,
				is_const		     = Type::is_const,
				is_const_volatile	     = Type::is_const_volatile,
				is_data_member_pointer	     = Type::is_data_member_pointer,
				is_empty		     = Type::is_empty,
				is_exact		     = Type::is_exact,
				is_integer		     = Type::is_integer,
				is_integral		     = Type::is_integral,
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
				is_signed_or_unsigned	     = Type::is_signed_or_unsigned,
				is_simple		     = Type::is_simple,
				is_sint			     = Type::is_sint,
				is_slong		     = Type::is_slong,
				is_sshort		     = Type::is_sshort,
				is_statically_allocatable    = Type::is_statically_allocatable,
				is_storable		     = Type::is_storable,
				is_structure		     = Type::is_structure,
				is_structure_or_union	     = Type::is_structure_or_union,
				is_uchar		     = Type::is_uchar,
				is_uint			     = Type::is_uint,
				is_ulong		     = Type::is_ulong,
				is_unsigned		     = Type::is_unsigned,
				is_ushort		     = Type::is_ushort,
				is_valid		     = Type::is_valid,
				is_variadic		     = Type::is_variadic,
				is_variadic_function	     = Type::is_variadic_function,
				is_void			     = Type::is_void,
				is_void_pointer		     = Type::is_void_pointer,
				is_volatile		     = Type::is_volatile
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

			typedef typename Type<typename Type::add_const		  >::flow add_const;
			typedef typename Type<typename Type::add_const_volatile	  >::flow add_const_volatile;
			typedef typename Type<typename Type::add_lvalue_reference >::flow add_lvalue_reference;
			typedef typename Type<typename Type::add_pointer	  >::flow add_pointer;
			typedef typename Type<typename Type::add_volatile	  >::flow add_volatile;
			typedef typename Type<typename Type::class_type		  >::flow class_type;
			typedef typename Type<typename Type::element_type	  >::flow element_type;
			typedef typename Type<typename Type::pointee_type	  >::flow pointee_type;
			typedef typename Type<typename Type::referencee_type	  >::flow referencee_type;
			typedef typename Type<typename Type::remove_const	  >::flow remove_const;
			typedef typename Type<typename Type::remove_const_volatile>::flow remove_const_volatile;
			typedef typename Type<typename Type::remove_pointer	  >::flow remove_pointer;
			typedef typename Type<typename Type::remove_reference	  >::flow remove_reference;
			typedef typename Type<typename Type::remove_volatile	  >::flow remove_volatile;
			typedef typename Type<typename Type::return_type	  >::flow return_type;
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

#			if Z_TRAIT_HAS(Type, has_virtual_destructor)
				enum {has_virtual_destructor = Type::has_virtual_destructor};
#			endif

#			if Z_TRAIT_HAS(Type, is_abstract)
				enum {is_abstract = Type::is_abstract};
#			endif

#			if Z_TRAIT_HAS(Type, is_aggregate)
				enum {is_aggregate = Type::is_aggregate};
#			endif

#			if Z_TRAIT_HAS(Type, is_boolean)
				enum {is_boolean = Type::is_boolean};
#			endif

/*#			if Z_TRAIT_HAS(Type, is_char16)
				enum {is_char16 = Type::is_char16};
#			endif

#			if Z_TRAIT_HAS(Type, is_char32)
				enum {is_char32 = Type::is_char32};
#			endif*/

#			if Z_TRAIT_HAS(Type, is_default_constructible)
				enum {is_default_constructible = Type::is_default_constructible};
#			endif

#			if Z_TRAIT_HAS(Type, is_double)
				enum {is_double = Type::is_double};
#			endif

#			if Z_TRAIT_HAS(Type, is_enumeration)
				enum {is_enumeration = Type::is_enumeration};
#			endif

#			if Z_TRAIT_HAS(Type, is_final)
				enum {is_final = Type::is_final};
#			endif

#			if Z_TRAIT_HAS(Type, is_float)
				enum {is_float = Type::is_float};
#			endif

#			if Z_TRAIT_HAS(Type, is_float16)
				enum {is_float16 = Type::is_float16};
#			endif

#			if Z_TRAIT_HAS(Type, is_float32)
				enum {is_float32 = Type::is_float32};
#			endif

#			if Z_TRAIT_HAS(Type, is_float64)
				enum {is_float64 = Type::is_float64};
#			endif

#			if Z_TRAIT_HAS(Type, is_float128)
				enum {is_float128 = Type::is_float128};
#			endif

#			if Z_TRAIT_HAS(Type, is_float80_x87)
				enum {is_float80_x87 = Type::is_float80_x87};
#			endif

#			if Z_TRAIT_HAS(Type, is_float96_x87)
				enum {is_float96_x87 = Type::is_float96_x87};
#			endif

#			if Z_TRAIT_HAS(Type, is_float128_x87)
				enum {is_float128_x87 = Type::is_float128_x87};
#			endif

#			if Z_TRAIT_HAS(Type, is_interface_class)
				enum {is_interface_class = Type::is_interface_class};
#			endif

#			if Z_TRAIT_HAS(Type, is_ldouble)
				enum {is_ldouble = Type::is_ldouble};
#			endif

#			if Z_TRAIT_HAS(Type, is_literal)
				enum {is_literal = Type::is_literal};
#			endif

#			if Z_TRAIT_HAS(Type, is_null_pointer)
				enum {is_null_pointer = Type::is_null_pointer};
#			endif

#			if Z_TRAIT_HAS(Type, is_pod)
				enum {is_pod = Type::is_pod};
#			endif

#			if Z_TRAIT_HAS(Type, is_polymorphic)
				enum {is_polymorphic = Type::is_polymorphic};
#			endif

#			if Z_TRAIT_HAS(Type, is_sint8)
				enum {is_sint8 = Type::is_sint8};
#			endif

#			if Z_TRAIT_HAS(Type, is_sint16)
				enum {is_sint16 = Type::is_sint16};
#			endif

#			if Z_TRAIT_HAS(Type, is_sint32)
				enum {is_sint32 = Type::is_sint32};
#			endif

#			if Z_TRAIT_HAS(Type, is_sint64)
				enum {is_sint64 = Type::is_sint64};
#			endif

#			if Z_TRAIT_HAS(Type, is_sint128)
				enum {is_sint128 = Type::is_sint128};
#			endif

#			if Z_TRAIT_HAS(Type, is_template)
				enum {is_template = Type::is_template};
#			endif

#			if Z_TRAIT_HAS(Type, is_trivially_copy_assignable)
				enum {is_trivially_copy_assignable = Type::is_trivially_copy_assignable};
#			endif

#			if Z_TRAIT_HAS(Type, is_trivially_copy_constructible)
				enum {is_trivially_copy_constructible = Type::is_trivially_copy_constructible};
#			endif

#			if Z_TRAIT_HAS(Type, is_trivially_copyable)
				enum {is_trivially_copyable = Type::is_trivially_copyable};
#			endif

#			if Z_TRAIT_HAS(Type, is_trivially_default_constructible)
				enum {is_trivially_default_constructible = Type::is_trivially_default_constructible};
#			endif

#			if Z_TRAIT_HAS(Type, is_trivially_destructible)
				enum {is_trivially_destructible = Type::is_trivially_destructible};
#			endif

#			if Z_TRAIT_HAS(Type, is_uint8)
				enum {is_uint8 = Type::is_uint8};
#			endif

#			if Z_TRAIT_HAS(Type, is_uint16)
				enum {is_uint16 = Type::is_uint16};
#			endif

#			if Z_TRAIT_HAS(Type, is_uint32)
				enum {is_uint32 = Type::is_uint32};
#			endif

#			if Z_TRAIT_HAS(Type, is_uint64)
				enum {is_uint64 = Type::is_uint64};
#			endif

#			if Z_TRAIT_HAS(Type, is_uint128)
				enum {is_uint128 = Type::is_uint128};
#			endif

#			if Z_TRAIT_HAS(Type, is_union)
				enum {is_union = Type::is_union};
#			endif

/*#			if Z_TRAIT_HAS(Type, is_wchar)
				enum {is_wchar = Type::is_wchar};
#			endif*/

#			if Z_LANGUAGE_INCLUDES(OBJECTIVE_CPP)

				enum {	is_objective_c_class	      = Type::is_objective_c_class,
					is_objective_c_class_pointer  = Type::is_objective_c_class_pointer,
					is_objective_c_object	      = Type::is_objective_c_object,
					is_objective_c_object_pointer = Type::is_objective_c_object_pointer
				};

#				if Z_LANGUAGE_HAS(CPP, EXPRESSION_SFINAE)
					enum {	is_objective_c_instance		= Type::is_objective_c_instance,
						is_objective_c_instance_pointer = Type::is_objective_c_instance_pointer
					};
#				endif

#			endif

#			ifdef Z_LLONG
				enum {	is_sllong = Type::is_sllong,
					is_ullong = Type::is_ullong
				};
#			endif

#			if Z_LANGUAGE_HAS(CPP, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)

				enum {	is_const_lvalue		 = Type::is_const_lvalue,
					is_const_rvalue		 = Type::is_const_rvalue,
					is_const_volatile_lvalue = Type::is_const_volatile_lvalue,
					is_const_volatile_rvalue = Type::is_const_volatile_rvalue,
					is_lvalue		 = Type::is_lvalue,
					is_rvalue		 = Type::is_rvalue,
					is_volatile_lvalue	 = Type::is_volatile_lvalue,
					is_volatile_rvalue	 = Type::is_volatile_rvalue
				};

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
				typedef typename Type<typename Type::to_const_lvalue	       >::flow to_const_lvalue;
				typedef typename Type<typename Type::to_const_rvalue	       >::flow to_const_rvalue;
				typedef typename Type<typename Type::to_const_volatile_lvalue  >::flow to_const_volatile_lvalue;
				typedef typename Type<typename Type::to_const_volatile_rvalue  >::flow to_const_volatile_rvalue;
				typedef typename Type<typename Type::to_lvalue		       >::flow to_lvalue;
				typedef typename Type<typename Type::to_rvalue		       >::flow to_rvalue;
				typedef typename Type<typename Type::to_volatile_lvalue	       >::flow to_volatile_lvalue;
				typedef typename Type<typename Type::to_volatile_rvalue	       >::flow to_volatile_rvalue;

#			endif

#			if Z_LANGUAGE_HAS(CPP, RVALUE_REFERENCE)

				enum {	is_function_rvalue_reference = Type::is_function_rvalue_reference,
					is_rvalue_reference	     = Type::is_rvalue_reference
				};

				typedef typename Type<typename Type::add_rvalue_reference >::flow add_rvalue_reference;
				typedef typename Type<typename Type::to_rvalue_reference  >::flow to_rvalue_reference;

#			endif

#			if Z_TRAIT_HAS(Type, parameters)
				typedef typename Type::parameters parameters;
#			endif

#			if Z_TRAIT_HAS(Type, underlying_type)
				typedef typename Type<typename Type::underlying_type>::flow underlying_type;
#			endif

#			if Z_TRAIT_HAS(Type, to_member_pointer)
				template <class klass> using to_member_pointer = typename Type<typename Type::to_member_pointer<klass> >::flow;
#			endif

			Z_IMPLEMENTATION_MEMBER_FUNCTIONS
		};

#		undef Z_IMPLEMENTATION_MEMBER_FUNCTIONS
	};

	template <class T> struct TypeArity			{enum {value = Type<T>::arity			    };};
	template <class T> struct TypeBits			{enum {value = Type<T>::bits			    };};
	template <class T> struct TypeElementCount		{enum {value = Type<T>::element_count		    };};
	template <class T> struct TypeIsArithmetic		{enum {value = Type<T>::is_arithmetic		    };};
	template <class T> struct TypeIsArray			{enum {value = Type<T>::is_array		    };};
	template <class T> struct TypeIsCallable		{enum {value = Type<T>::is_callable		    };};
	template <class T> struct TypeIsChar			{enum {value = Type<T>::is_char			    };};
	template <class T> struct TypeIsClass			{enum {value = Type<T>::is_class		    };};
	template <class T> struct TypeIsConst			{enum {value = Type<T>::is_const		    };};
	template <class T> struct TypeIsConstVolatile		{enum {value = Type<T>::is_const_volatile	    };};
	template <class T> struct TypeIsDataMemberPointer	{enum {value = Type<T>::is_data_member_pointer	    };};
	template <class T> struct TypeIsEmpty			{enum {value = Type<T>::is_empty		    };};
	template <class T> struct TypeIsExact			{enum {value = Type<T>::is_exact		    };};
	template <class T> struct TypeIsInteger			{enum {value = Type<T>::is_integer		    };};
	template <class T> struct TypeIsIntegral		{enum {value = Type<T>::is_integral		    };};
	template <class T> struct TypeIsFlexibleArray		{enum {value = Type<T>::is_flexible_array	    };};
	template <class T> struct TypeIsFunction		{enum {value = Type<T>::is_function		    };};
	template <class T> struct TypeIsFunctionLValueReference {enum {value = Type<T>::is_function_lvalue_reference};};
	template <class T> struct TypeIsFunctionPointer		{enum {value = Type<T>::is_function_pointer	    };};
	template <class T> struct TypeIsFunctionReference	{enum {value = Type<T>::is_function_reference	    };};
	template <class T> struct TypeIsFundamental		{enum {value = Type<T>::is_fundamental		    };};
	template <class T> struct TypeIsLValueReference		{enum {value = Type<T>::is_lvalue_reference	    };};
	template <class T> struct TypeIsMemberFunctionPointer	{enum {value = Type<T>::is_member_function_pointer  };};
	template <class T> struct TypeIsMemberPointer		{enum {value = Type<T>::is_member_pointer	    };};
	template <class T> struct TypeIsNaT			{enum {value = Type<T>::is_nat			    };};
	template <class T> struct TypeIsNatural			{enum {value = Type<T>::is_natural		    };};
	template <class T> struct TypeIsNumber			{enum {value = Type<T>::is_number		    };};
	template <class T> struct TypeIsPointer			{enum {value = Type<T>::is_pointer		    };};
	template <class T> struct TypeIsQualified		{enum {value = Type<T>::is_qualified		    };};
	template <class T> struct TypeIsReal			{enum {value = Type<T>::is_real			    };};
	template <class T> struct TypeIsReference		{enum {value = Type<T>::is_reference		    };};
	template <class T> struct TypeIsScalar			{enum {value = Type<T>::is_scalar		    };};
	template <class T> struct TypeIsSChar			{enum {value = Type<T>::is_schar		    };};
	template <class T> struct TypeIsSigned			{enum {value = Type<T>::is_signed		    };};
	template <class T> struct TypeIsSignedOrUnsigned	{enum {value = Type<T>::is_signed_or_unsigned	    };};
	template <class T> struct TypeIsSimple			{enum {value = Type<T>::is_simple		    };};
	template <class T> struct TypeIsSInt			{enum {value = Type<T>::is_sint			    };};
	template <class T> struct TypeIsSLong			{enum {value = Type<T>::is_slong		    };};
	template <class T> struct TypeIsSShort			{enum {value = Type<T>::is_sshort		    };};
	template <class T> struct TypeIsStaticallyAllocatable	{enum {value = Type<T>::is_statically_allocatable   };};
	template <class T> struct TypeIsStorable		{enum {value = Type<T>::is_storable		    };};
	template <class T> struct TypeIsStructure		{enum {value = Type<T>::is_structure		    };};
	template <class T> struct TypeIsStructureOrUnion	{enum {value = Type<T>::is_structure_or_union	    };};
	template <class T> struct TypeIsUChar			{enum {value = Type<T>::is_uchar		    };};
	template <class T> struct TypeIsUInt			{enum {value = Type<T>::is_uint			    };};
	template <class T> struct TypeIsULong			{enum {value = Type<T>::is_ulong		    };};
	template <class T> struct TypeIsUnsigned		{enum {value = Type<T>::is_unsigned		    };};
	template <class T> struct TypeIsUShort			{enum {value = Type<T>::is_ushort		    };};
	template <class T> struct TypeIsValid			{enum {value = Type<T>::is_valid		    };};
	template <class T> struct TypeIsVariadic		{enum {value = Type<T>::is_variadic		    };};
	template <class T> struct TypeIsVariadicFunction	{enum {value = Type<T>::is_variadic_function	    };};
	template <class T> struct TypeIsVoid			{enum {value = Type<T>::is_void			    };};
	template <class T> struct TypeIsVoidPointer		{enum {value = Type<T>::is_void_pointer		    };};
	template <class T> struct TypeIsVolatile		{enum {value = Type<T>::is_volatile		    };};
	template <class T> struct TypePointerLevel		{enum {value = Type<T>::pointer_level		    };};
	template <class T> struct TypeSize			{enum {value = Type<T>::size			    };};

	template <class T> struct TypeAddConst		  {typedef typename Type<T>::add_const		   type;};
	template <class T> struct TypeAddConstVolatile	  {typedef typename Type<T>::add_const_volatile	   type;};
	template <class T> struct TypeAddLValueReference  {typedef typename Type<T>::add_lvalue_reference  type;};
	template <class T> struct TypeAddPointer	  {typedef typename Type<T>::add_pointer	   type;};
	template <class T> struct TypeAddVolatile	  {typedef typename Type<T>::add_volatile	   type;};
	template <class T> struct TypeClassType		  {typedef typename Type<T>::class_type		   type;};
	template <class T> struct TypeElementType	  {typedef typename Type<T>::element_type	   type;};
	template <class T> struct TypePointeeType	  {typedef typename Type<T>::pointee_type	   type;};
	template <class T> struct TypeReferenceeType	  {typedef typename Type<T>::referencee_type	   type;};
	template <class T> struct TypeRemoveConst	  {typedef typename Type<T>::remove_const	   type;};
	template <class T> struct TypeRemoveConstVolatile {typedef typename Type<T>::remove_const_volatile type;};
	template <class T> struct TypeRemovePointer	  {typedef typename Type<T>::remove_pointer	   type;};
	template <class T> struct TypeRemoveReference	  {typedef typename Type<T>::remove_reference	   type;};
	template <class T> struct TypeRemoveVolatile	  {typedef typename Type<T>::remove_volatile	   type;};
	template <class T> struct TypeReturnType	  {typedef typename Type<T>::return_type	   type;};
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

#	if Z_HAS_TRAIT(TypeHasVirtualDestructor)
		template <class T> struct TypeHasVirtualDestructor {enum {value = Type<T>::has_virtual_destructor};};
#	endif

#	if Z_HAS_TRAIT(TypeIsAbstract)
		template <class T> struct TypeIsAbstract {enum {value = Type<T>::is_abstract};};
#	endif

#	if Z_HAS_TRAIT(TypeIsAggregate)
		template <class T> struct TypeIsAggregate {enum {value = Type<T>::is_aggregate};};
#	endif

#	if Z_HAS_TRAIT(TypeIsBoolean)
		template <class T> struct TypeIsBoolean {enum {value = Type<T>::is_boolean};};
#	endif

/*#	if Z_HAS_TRAIT(TypeIsChar16)
		template <class T> struct TypeIsChar16 {enum {value = Type<T>::is_char16};};
#	endif

#	if Z_HAS_TRAIT(TypeIsChar32)
		template <class T> struct TypeIsChar32 {enum {value = Type<T>::is_char32};};
#	endif*/

#	if Z_HAS_TRAIT(TypeIsDefaultConstructible)
		template <class T> struct TypeIsDefaultConstructible {enum {value = Type<T>::is_default_constructible};};
#	endif

#	if Z_HAS_TRAIT(TypeIsDouble)
		template <class T> struct TypeIsDouble {enum {value = Type<T>::is_double};};
#	endif

#	if Z_HAS_TRAIT(TypeIsEnumeration)
		template <class T> struct TypeIsEnumeration {enum {value = Type<T>::is_enumeration};};
#	endif

#	if Z_HAS_TRAIT(TypeIsFinal)
		template <class T> struct TypeIsFinal {enum {value = Type<T>::is_final};};
#	endif

#	if Z_HAS_TRAIT(TypeIsFloat)
		template <class T> struct TypeIsFloat {enum {value = Type<T>::is_float};};
#	endif

#	if Z_HAS_TRAIT(TypeIsFloat16)
		template <class T> struct TypeIsFloat16 {enum {value = Type<T>::is_float16};};
#	endif

#	if Z_HAS_TRAIT(TypeIsFloat32)
		template <class T> struct TypeIsFloat32 {enum {value = Type<T>::is_float32};};
#	endif

#	if Z_HAS_TRAIT(TypeIsFloat64)
		template <class T> struct TypeIsFloat64 {enum {value = Type<T>::is_float64};};
#	endif

#	if Z_HAS_TRAIT(TypeIsFloat128)
		template <class T> struct TypeIsFloat128 {enum {value = Type<T>::is_float128};};
#	endif

#	if Z_HAS_TRAIT(TypeIsFloat80_x87)
		template <class T> struct TypeIsFloat80_x87 {enum {value = Type<T>::is_float80_x87};};
#	endif

#	if Z_HAS_TRAIT(TypeIsFloat96_x87)
		template <class T> struct TypeIsFloat96_x87 {enum {value = Type<T>::is_float96_x87};};
#	endif

#	if Z_HAS_TRAIT(TypeIsFloat128_x87)
		template <class T> struct TypeIsFloat128_x87 {enum {value = Type<T>::is_float128_x87};};
#	endif

#	if Z_HAS_TRAIT(TypeIsInterfaceClass)
		template <class T> struct TypeIsInterfaceClass {enum {value = Type<T>::is_interface_class};};
#	endif

#	if Z_HAS_TRAIT(TypeIsLDouble)
		template <class T> struct TypeIsLDouble {enum {value = Type<T>::is_ldouble};};
#	endif

#	if Z_HAS_TRAIT(TypeIsLiteral)
		template <class T> struct TypeIsLiteral {enum {value = Type<T>::is_literal};};
#	endif

#	if Z_HAS_TRAIT(TypeIsNullPointer)
		template <class T> struct TypeIsNullPointer {enum {value = Type<T>::is_null_pointer};};
#	endif

#	if Z_HAS_TRAIT(TypeIsPOD)
		template <class T> struct TypeIsPOD {enum {value = Type<T>::is_pod};};
#	endif

#	if Z_HAS_TRAIT(TypeIsPolymorphic)
		template <class T> struct TypeIsPolymorphic {enum {value = Type<T>::is_polymorphic};};
#	endif

#	if Z_HAS_TRAIT(TypeIsSInt8)
		template <class T> struct TypeIsSInt8 {enum {value = Type<T>::is_sint8};};
#	endif

#	if Z_HAS_TRAIT(TypeIsSInt16)
		template <class T> struct TypeIsSInt16 {enum {value = Type<T>::is_sint16};};
#	endif

#	if Z_HAS_TRAIT(TypeIsSInt32)
		template <class T> struct TypeIsSInt32 {enum {value = Type<T>::is_sint32};};
#	endif

#	if Z_HAS_TRAIT(TypeIsSInt64)
		template <class T> struct TypeIsSInt64 {enum {value = Type<T>::is_sint64};};
#	endif

#	if Z_HAS_TRAIT(TypeIsSInt128)
		template <class T> struct TypeIsSInt128 {enum {value = Type<T>::is_sint128};};
#	endif

#	if Z_HAS_TRAIT(TypeIsTemplate)
		template <class T> struct TypeIsTemplate {enum {value = Type<T>::is_template};};
#	endif

#	if Z_HAS_TRAIT(TypeIsTriviallyCopyAssignable)
		template <class T> struct TypeIsTriviallyCopyAssignable {enum {value = Type<T>::is_trivially_copy_assignable};};
#	endif

#	if Z_HAS_TRAIT(TypeIsTriviallyCopyConstructible)
		template <class T> struct TypeIsTriviallyCopyConstructible {enum {value = Type<T>::is_trivially_copy_constructible};};
#	endif

#	if Z_HAS_TRAIT(TypeIsTriviallyCopyable)
		template <class T> struct TypeIsTriviallyCopyable {enum {value = Type<T>::is_trivially_copyable};};
#	endif

#	if Z_HAS_TRAIT(TypeIsTriviallyDefaultConstructible)
		template <class T> struct TypeIsTriviallyDefaultConstructible {enum {value = Type<T>::is_trivially_default_constructible};};
#	endif

#	if Z_HAS_TRAIT(TypeIsTriviallyDestructible)
		template <class T> struct TypeIsTriviallyDestructible {enum {value = Type<T>::is_trivially_destructible};};
#	endif

#	if Z_HAS_TRAIT(TypeIsUInt8)
		template <class T> struct TypeIsUInt8 {enum {value = Type<T>::is_uint8};};
#	endif

#	if Z_HAS_TRAIT(TypeIsUInt16)
		template <class T> struct TypeIsUInt16 {enum {value = Type<T>::is_uint16};};
#	endif

#	if Z_HAS_TRAIT(TypeIsUInt32)
		template <class T> struct TypeIsUInt32 {enum {value = Type<T>::is_uint32};};
#	endif

#	if Z_HAS_TRAIT(TypeIsUInt64)
		template <class T> struct TypeIsUInt64 {enum {value = Type<T>::is_uint64};};
#	endif

#	if Z_HAS_TRAIT(TypeIsUInt128)
		template <class T> struct TypeIsUInt128 {enum {value = Type<T>::is_uint128};};
#	endif

#	if Z_HAS_TRAIT(TypeIsUnion)
		template <class T> struct TypeIsUnion {enum {value = Type<T>::is_union};};
#	endif

/*#	if Z_HAS_TRAIT(TypeIsWChar)
		template <class T> struct TypeIsWChar {enum {value = Type<T>::is_wchar};};
#	endif*/

#	if Z_LANGUAGE_INCLUDES(OBJECTIVE_CPP)

		template <class T> struct TypeIsObjectiveCClass		{enum {value = Type<T>::is_objective_c_class	     };};
		template <class T> struct TypeIsObjectiveCClassPointer	{enum {value = Type<T>::is_objective_c_class_pointer };};
		template <class T> struct TypeIsObjectiveCObject	{enum {value = Type<T>::is_objective_c_object	     };};
		template <class T> struct TypeIsObjectiveCObjectPointer {enum {value = Type<T>::is_objective_c_object_pointer};};

#		if Z_LANGUAGE_HAS(CPP, EXPRESSION_SFINAE)
			template <class T> struct TypeIsObjectiveCInstance	  {enum {value = Type<T>::is_objective_c_instance	 };};
			template <class T> struct TypeIsObjectiveCInstancePointer {enum {value = Type<T>::is_objective_c_instance_pointer};};
#		endif

#	endif

#	ifdef Z_LLONG
		template <class T> struct TypeIsSLLong {enum {value = Type<T>::is_sllong};};
		template <class T> struct TypeIsULLong {enum {value = Type<T>::is_ullong};};
#	endif

#	if Z_LANGUAGE_HAS(CPP, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)

		template <class T> struct TypeIsConstLValue	    {enum {value = Type<T>::is_const_lvalue	    };};
		template <class T> struct TypeIsConstRValue	    {enum {value = Type<T>::is_const_rvalue	    };};
		template <class T> struct TypeIsConstVolatileLValue {enum {value = Type<T>::is_const_volatile_lvalue};};
		template <class T> struct TypeIsConstVolatileRValue {enum {value = Type<T>::is_const_volatile_rvalue};};
		template <class T> struct TypeIsLValue		    {enum {value = Type<T>::is_lvalue		    };};
		template <class T> struct TypeIsRValue		    {enum {value = Type<T>::is_rvalue		    };};
		template <class T> struct TypeIsVolatileLValue	    {enum {value = Type<T>::is_volatile_lvalue	    };};
		template <class T> struct TypeIsVolatileRValue	    {enum {value = Type<T>::is_volatile_rvalue	    };};

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
		template <class T> struct TypeToConstLValue	      {typedef typename Type<T>::to_const_lvalue	    type;};
		template <class T> struct TypeToConstRValue	      {typedef typename Type<T>::to_const_rvalue	    type;};
		template <class T> struct TypeToConstVolatileLValue   {typedef typename Type<T>::to_const_volatile_lvalue   type;};
		template <class T> struct TypeToConstVolatileRValue   {typedef typename Type<T>::to_const_volatile_rvalue   type;};
		template <class T> struct TypeToLValue		      {typedef typename Type<T>::to_lvalue		    type;};
		template <class T> struct TypeToRValue		      {typedef typename Type<T>::to_rvalue		    type;};
		template <class T> struct TypeToVolatileLValue	      {typedef typename Type<T>::to_volatile_lvalue	    type;};
		template <class T> struct TypeToVolatileRValue	      {typedef typename Type<T>::to_volatile_rvalue	    type;};

#	endif

#	if Z_LANGUAGE_HAS(CPP, RVALUE_REFERENCE)

		template <class T> struct TypeIsFunctionRValueReference {enum {value = Type<T>::is_function_rvalue_reference};};
		template <class T> struct TypeIsRValueReference		{enum {value = Type<T>::is_rvalue_reference	    };};

		template <class T> struct TypeAddRValueReference {typedef typename Type<T>::add_rvalue_reference type;};
		template <class T> struct TypeToRValueReference	 {typedef typename Type<T>::to_rvalue_reference	 type;};

#	endif

#	if Z_HAS_TRAIT(TypeParameters)
		template <class T> struct TypeParameters {typedef typename Type<T>::parameters type;};
#	endif

#	if Z_HAS_TRAIT(TypeUnderlyingType)
		template <class T> struct TypeUnderlyingType {typedef typename Type<T>::underlying_type	type;};
#	endif

#	if Z_LANGUAGE_HAS(CPP, TEMPLATE_ALIAS)

		template <class T> using type_add_const		    = typename Type<T>::add_const;
		template <class T> using type_add_const_volatile    = typename Type<T>::add_const_volatile;
		template <class T> using type_add_lvalue_reference  = typename Type<T>::add_lvalue_reference;
		template <class T> using type_add_pointer	    = typename Type<T>::add_pointer;
		template <class T> using type_add_volatile	    = typename Type<T>::add_volatile;
		template <class T> using type_class_type	    = typename Type<T>::class_type;
		template <class T> using type_element_type	    = typename Type<T>::element_type;
		template <class T> using type_pointee_type	    = typename Type<T>::pointee_type;
		template <class T> using type_referencee_type	    = typename Type<T>::referencee_type;
		template <class T> using type_remove_const	    = typename Type<T>::remove_const;
		template <class T> using type_remove_const_volatile = typename Type<T>::remove_const_volatile;
		template <class T> using type_remove_pointer	    = typename Type<T>::remove_pointer;
		template <class T> using type_remove_reference	    = typename Type<T>::remove_reference;
		template <class T> using type_remove_volatile	    = typename Type<T>::remove_volatile;
		template <class T> using type_return_type	    = typename Type<T>::return_type;
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

		template <class T, class klass> using type_to_member_pointer = typename TypeToMemberPointer<T, klass>::type;

#		if Z_LANGUAGE_HAS(CPP, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)
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
			template <class T> using type_to_const_lvalue		 = typename Type<T>::to_const_lvalue;
			template <class T> using type_to_const_rvalue		 = typename Type<T>::to_const_rvalue;
			template <class T> using type_to_const_volatile_lvalue	 = typename Type<T>::to_const_volatile_lvalue;
			template <class T> using type_to_const_volatile_rvalue	 = typename Type<T>::to_const_volatile_rvalue;
			template <class T> using type_to_lvalue			 = typename Type<T>::to_lvalue;
			template <class T> using type_to_rvalue			 = typename Type<T>::to_rvalue;
			template <class T> using type_to_volatile_lvalue	 = typename Type<T>::to_volatile_lvalue;
			template <class T> using type_to_volatile_rvalue	 = typename Type<T>::to_volatile_rvalue;
#		endif

#		if Z_LANGUAGE_HAS(CPP, RVALUE_REFERENCE)
			template <class T> using type_add_rvalue_reference = typename Type<T>::add_rvalue_reference;
			template <class T> using type_to_rvalue_reference  = typename Type<T>::to_rvalue_reference;
#		endif

#		if Z_HAS_TRAIT_ALIAS(type_parameters)
			template <class T> using type_parameters = typename Type<T>::parameters;
#		endif

#		if Z_HAS_TRAIT_ALIAS(type_underlying_type)
			template <class T> using type_underlying_type = typename Type<T>::underlying_type;
#		endif

#	endif
}

#endif // _Z_traits_Type_HPP_
