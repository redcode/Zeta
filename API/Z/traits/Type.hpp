/* Z Kit - traits/Type.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//__/__| Kit
Copyright (C) 2006-2020 Manuel Sainz de Baranda y Goñi.
Copyright (C) 2018 Sofía Ortega Sosa.
Released under the terms of the GNU Lesser General Public License v3. */

/* TODO:
	noexcept
	transaction_safe
	traits de std
	enums
	Ambiguous
	Z_DECLARES
	includes
*/

#ifndef Z_traits_Type_HPP
#define Z_traits_Type_HPP

#include <Z/inspection/Z.h>
#include <Z/keys/number.h>
#include <Z/traits/constants.hpp>
#include <Z/traits/TypeList.hpp>
#include <Z/classes/NaT.hpp>
#include <Z/macros/aggregate.h>
#include <Z/macros/control.h>
#include <Z/types/fundamental.hpp>
#include <Z/macros/tokens.h>

#if !Z_DECLARES(TypeList)
#	include <Z/traits/control.hpp>

#	if Z_DIALECT_HAS(CPP, VARIADIC_TEMPLATE)
#		include <Z/traits/TypeCount.hpp>
#	endif
#endif

#if Z_DIALECT_HAS(CPP, EXPRESSION_SFINAE)
#	include <Z/functions/unevaluated.hpp>
#endif

#if Z_DIALECT_HAS(CPP, NOEXCEPT_AS_PART_OF_THE_FUNCTION_TYPE)
#	include <Z/classes/Empty.hpp>
#endif

#if	Z_COMPILER_HAS_MAGIC_CONSTANT(MANGLED_FUNCTION_NAME) && \
	Z_DIALECT_HAS(CPP, CPP14_CONSTEXPR_FUNCTION)

#	include <Z/functions/type.hpp>
#	include <Z/classes/Symbol.hpp>
#endif

// MARK: - Component availability configuration

//-----------------------------------------------------------------------.
// Transformation components that are available only if the language     |
// features that their resulting types require are supported or enabled. |
//-----------------------------------------------------------------------'

#if Z_DIALECT_HAS(CPP, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)
#	define Z_DECLARES_TypeAddConstLValue			TRUE
#	define Z_DECLARES_TypeAddConstRValue			TRUE
#	define Z_DECLARES_TypeAddConstVolatileLValue		TRUE
#	define Z_DECLARES_TypeAddConstVolatileRValue		TRUE
#	define Z_DECLARES_TypeAddLValue				TRUE
#	define Z_DECLARES_TypeAddRValue				TRUE
#	define Z_DECLARES_TypeAddVolatileLValue			TRUE
#	define Z_DECLARES_TypeAddVolatileRValue			TRUE
#	define Z_DECLARES_TypeToConstLValue			TRUE
#	define Z_DECLARES_TypeToConstRValue			TRUE
#	define Z_DECLARES_TypeToConstVolatileLValue		TRUE
#	define Z_DECLARES_TypeToConstVolatileRValue		TRUE
#	define Z_DECLARES_TypeToLValue				TRUE
#	define Z_DECLARES_TypeToRValue				TRUE
#	define Z_DECLARES_TypeToVolatileLValue			TRUE
#	define Z_DECLARES_TypeToVolatileRValue			TRUE
#	define Z_DECLARES_Type_MEMBER_add_const_lvalue		TRUE
#	define Z_DECLARES_Type_MEMBER_add_const_rvalue		TRUE
#	define Z_DECLARES_Type_MEMBER_add_const_volatile_lvalue TRUE
#	define Z_DECLARES_Type_MEMBER_add_const_volatile_rvalue TRUE
#	define Z_DECLARES_Type_MEMBER_add_lvalue		TRUE
#	define Z_DECLARES_Type_MEMBER_add_rvalue		TRUE
#	define Z_DECLARES_Type_MEMBER_add_volatile_lvalue	TRUE
#	define Z_DECLARES_Type_MEMBER_add_volatile_rvalue	TRUE
#	define Z_DECLARES_Type_MEMBER_to_const_lvalue		TRUE
#	define Z_DECLARES_Type_MEMBER_to_const_rvalue		TRUE
#	define Z_DECLARES_Type_MEMBER_to_const_volatile_lvalue  TRUE
#	define Z_DECLARES_Type_MEMBER_to_const_volatile_rvalue  TRUE
#	define Z_DECLARES_Type_MEMBER_to_lvalue			TRUE
#	define Z_DECLARES_Type_MEMBER_to_rvalue			TRUE
#	define Z_DECLARES_Type_MEMBER_to_volatile_lvalue	TRUE
#	define Z_DECLARES_Type_MEMBER_to_volatile_rvalue	TRUE
#else
#	define Z_DECLARES_TypeAddConstLValue			FALSE
#	define Z_DECLARES_TypeAddConstRValue			FALSE
#	define Z_DECLARES_TypeAddConstVolatileLValue		FALSE
#	define Z_DECLARES_TypeAddConstVolatileRValue		FALSE
#	define Z_DECLARES_TypeAddLValue				FALSE
#	define Z_DECLARES_TypeAddRValue				FALSE
#	define Z_DECLARES_TypeAddVolatileLValue			FALSE
#	define Z_DECLARES_TypeAddVolatileRValue			FALSE
#	define Z_DECLARES_TypeToConstLValue			FALSE
#	define Z_DECLARES_TypeToConstRValue			FALSE
#	define Z_DECLARES_TypeToConstVolatileLValue		FALSE
#	define Z_DECLARES_TypeToConstVolatileRValue		FALSE
#	define Z_DECLARES_TypeToLValue				FALSE
#	define Z_DECLARES_TypeToRValue				FALSE
#	define Z_DECLARES_TypeToVolatileLValue			FALSE
#	define Z_DECLARES_TypeToVolatileRValue			FALSE
#	define Z_DECLARES_Type_MEMBER_add_const_lvalue		FALSE
#	define Z_DECLARES_Type_MEMBER_add_const_rvalue		FALSE
#	define Z_DECLARES_Type_MEMBER_add_const_volatile_lvalue FALSE
#	define Z_DECLARES_Type_MEMBER_add_const_volatile_rvalue FALSE
#	define Z_DECLARES_Type_MEMBER_add_lvalue		FALSE
#	define Z_DECLARES_Type_MEMBER_add_rvalue		FALSE
#	define Z_DECLARES_Type_MEMBER_add_volatile_lvalue	FALSE
#	define Z_DECLARES_Type_MEMBER_add_volatile_rvalue	FALSE
#	define Z_DECLARES_Type_MEMBER_to_const_lvalue		FALSE
#	define Z_DECLARES_Type_MEMBER_to_const_rvalue		FALSE
#	define Z_DECLARES_Type_MEMBER_to_const_volatile_lvalue  FALSE
#	define Z_DECLARES_Type_MEMBER_to_const_volatile_rvalue  FALSE
#	define Z_DECLARES_Type_MEMBER_to_lvalue			FALSE
#	define Z_DECLARES_Type_MEMBER_to_rvalue			FALSE
#	define Z_DECLARES_Type_MEMBER_to_volatile_lvalue	FALSE
#	define Z_DECLARES_Type_MEMBER_to_volatile_rvalue	FALSE
#endif

#if Z_DIALECT_HAS(CPP, NOEXCEPT_AS_PART_OF_THE_FUNCTION_TYPE)
#	define Z_DECLARES_TypeIsNoexcept	      TRUE
#	define Z_DECLARES_TypeAddNoexcept	      TRUE
#	define Z_DECLARES_TypeRemoveNoexcept	      TRUE
#	define Z_DECLARES_Type_MEMBER_is_noexcept     TRUE
#	define Z_DECLARES_Type_MEMBER_add_noexcept    TRUE
#	define Z_DECLARES_Type_MEMBER_remove_noexcept TRUE
#else
#	define Z_DECLARES_TypeIsNoexcept	      FALSE
#	define Z_DECLARES_TypeAddNoexcept	      FALSE
#	define Z_DECLARES_TypeRemoveNoexcept	      FALSE
#	define Z_DECLARES_Type_MEMBER_is_noexcept     FALSE
#	define Z_DECLARES_Type_MEMBER_add_noexcept    FALSE
#	define Z_DECLARES_Type_MEMBER_remove_noexcept FALSE
#endif

#if Z_DIALECT_HAS(CPP, RVALUE_REFERENCE)
#	define Z_DECLARES_TypeAddRValueReference	   TRUE
#	define Z_DECLARES_TypeToRValueReference		   TRUE
#	define Z_DECLARES_Type_MEMBER_add_rvalue_reference TRUE
#	define Z_DECLARES_Type_MEMBER_to_rvalue_reference  TRUE
#else
#	define Z_DECLARES_TypeAddRValueReference	   FALSE
#	define Z_DECLARES_TypeToRValueReference		   FALSE
#	define Z_DECLARES_Type_MEMBER_add_rvalue_reference FALSE
#	define Z_DECLARES_Type_MEMBER_to_rvalue_reference  FALSE
#endif

//---------------------------------------------------------------------.
// Components that require compiler built-in traits to be implemented. |
// There are no known workarounds.				       |
//---------------------------------------------------------------------'

#if Z_COMPILER_HAS_TRAIT(TYPE_HAS_VIRTUAL_DESTRUCTOR)
#	define Z_DECLARES_TypeHasVirtualDestructor	     TRUE
#	define Z_DECLARES_Type_MEMBER_has_virtual_destructor TRUE
#else
#	define Z_DECLARES_TypeHasVirtualDestructor	     FALSE
#	define Z_DECLARES_Type_MEMBER_has_virtual_destructor FALSE
#endif

#if Z_COMPILER_HAS_TRAIT(TYPE_IS_ABSTRACT)
#	define Z_DECLARES_TypeIsAbstract	  TRUE
#	define Z_DECLARES_Type_MEMBER_is_abstract TRUE
#else
#	define Z_DECLARES_TypeIsAbstract	  FALSE
#	define Z_DECLARES_Type_MEMBER_is_abstract FALSE
#endif

#if Z_COMPILER_HAS_TRAIT(TYPE_IS_AGGREGATE)
#	define Z_DECLARES_TypeIsAggregate	   TRUE
#	define Z_DECLARES_Type_MEMBER_is_aggregate TRUE
#else
#	define Z_DECLARES_TypeIsAggregate	   FALSE
#	define Z_DECLARES_Type_MEMBER_is_aggregate FALSE
#endif

#if Z_COMPILER_HAS_TRAIT(TYPE_IS_ASSIGNABLE)
#	define Z_DECLARES_TypeIsAssignable TRUE
#else
#	define Z_DECLARES_TypeIsAssignable FALSE
#endif

#if Z_COMPILER_HAS_TRAIT(TYPE_IS_BASE)
#	define Z_DECLARES_TypeIsBase TRUE
#else
#	define Z_DECLARES_TypeIsBase FALSE
#endif

#if Z_COMPILER_HAS_TRAIT(TYPE_IS_CONVERTIBLE)
#	define Z_DECLARES_TypeIsConvertible TRUE
#else
#	define Z_DECLARES_TypeIsConvertible FALSE
#endif

#if Z_COMPILER_HAS_TRAIT(TYPE_IS_FINAL)
#	define Z_DECLARES_TypeIsFinal	       TRUE
#	define Z_DECLARES_Type_MEMBER_is_final TRUE
#else
#	define Z_DECLARES_TypeIsFinal	       FALSE
#	define Z_DECLARES_Type_MEMBER_is_final FALSE
#endif

#if Z_COMPILER_HAS_TRAIT(TYPE_IS_INTERFACE_CLASS)
#	define Z_DECLARES_TypeIsInterfaceClass		 TRUE
#	define Z_DECLARES_Type_MEMBER_is_interface_class TRUE
#else
#	define Z_DECLARES_TypeIsInterfaceClass		 FALSE
#	define Z_DECLARES_Type_MEMBER_is_interface_class FALSE
#endif

#if Z_COMPILER_HAS_TRAIT(TYPE_IS_LITERAL)
#	define Z_DECLARES_TypeIsLiteral		 TRUE
#	define Z_DECLARES_Type_MEMBER_is_literal TRUE
#else
#	define Z_DECLARES_TypeIsLiteral		 FALSE
#	define Z_DECLARES_Type_MEMBER_is_literal FALSE
#endif

#if Z_COMPILER_HAS_TRAIT(TYPE_IS_NOTHROW_ASSIGNABLE)
#	define Z_DECLARES_TypeIsNothrowAssignable TRUE
#else
#	define Z_DECLARES_TypeIsNothrowAssignable FALSE
#endif

#if Z_COMPILER_HAS_TRAIT(TYPE_IS_POD)
#	define Z_DECLARES_TypeIsPOD	     TRUE
#	define Z_DECLARES_Type_MEMBER_is_pod TRUE
#else
#	define Z_DECLARES_TypeIsPOD	     FALSE
#	define Z_DECLARES_Type_MEMBER_is_pod FALSE
#endif

#if Z_COMPILER_HAS_TRAIT(TYPE_IS_POLYMORPHIC)
#	define Z_DECLARES_TypeIsPolymorphic	     TRUE
#	define Z_DECLARES_Type_MEMBER_is_polymorphic TRUE
#else
#	define Z_DECLARES_TypeIsPolymorphic	     FALSE
#	define Z_DECLARES_Type_MEMBER_is_polymorphic FALSE
#endif

#if Z_COMPILER_HAS_TRAIT(TYPE_IS_TRIVIALLY_ASSIGNABLE)
#	define Z_DECLARES_TypeIsTriviallyAssignable TRUE
#else
#	define Z_DECLARES_TypeIsTriviallyAssignable FALSE
#endif

#if Z_COMPILER_HAS_TRAIT(TYPE_IS_TRIVIALLY_COPY_ASSIGNABLE)
#	define Z_DECLARES_TypeIsTriviallyCopyAssignable		   TRUE
#	define Z_DECLARES_Type_MEMBER_is_trivially_copy_assignable TRUE
#else
#	define Z_DECLARES_TypeIsTriviallyCopyAssignable		   FALSE
#	define Z_DECLARES_Type_MEMBER_is_trivially_copy_assignable FALSE
#endif

#if Z_COMPILER_HAS_TRAIT(TYPE_IS_TRIVIALLY_COPY_CONSTRUCTIBLE)
#	define Z_DECLARES_TypeIsTriviallyCopyConstructible	      TRUE
#	define Z_DECLARES_Type_MEMBER_is_trivially_copy_constructible TRUE
#else
#	define Z_DECLARES_TypeIsTriviallyCopyConstructible	      FALSE
#	define Z_DECLARES_Type_MEMBER_is_trivially_copy_constructible FALSE
#endif

#if Z_COMPILER_HAS_TRAIT(TYPE_IS_TRIVIALLY_COPYABLE)
#	define Z_DECLARES_TypeIsTriviallyCopyable	    TRUE
#	define Z_DECLARES_Type_MEMBER_is_trivially_copyable TRUE
#else
#	define Z_DECLARES_TypeIsTriviallyCopyable	    FALSE
#	define Z_DECLARES_Type_MEMBER_is_trivially_copyable FALSE
#endif

#if Z_COMPILER_HAS_TRAIT(TYPE_IS_TRIVIALLY_DEFAULT_CONSTRUCTIBLE)
#	define Z_DECLARES_TypeIsTriviallyDefaultConstructible		 TRUE
#	define Z_DECLARES_Type_MEMBER_is_trivially_default_constructible TRUE
#else
#	define Z_DECLARES_TypeIsTriviallyDefaultConstructible		 FALSE
#	define Z_DECLARES_Type_MEMBER_is_trivially_default_constructible FALSE
#endif

#if Z_COMPILER_HAS_TRAIT(TYPE_IS_TRIVIALLY_DESTRUCTIBLE)
#	define Z_DECLARES_TypeIsTriviallyDestructible		TRUE
#	define Z_DECLARES_Type_MEMBER_is_trivially_destructible TRUE
#else
#	define Z_DECLARES_TypeIsTriviallyDestructible		FALSE
#	define Z_DECLARES_Type_MEMBER_is_trivially_destructible FALSE
#endif

#if Z_COMPILER_HAS_TRAIT(TYPE_IS_UNION)
#	define Z_DECLARES_TypeIsUnion	       TRUE
#	define Z_DECLARES_Type_MEMBER_is_union TRUE
#else
#	define Z_DECLARES_TypeIsUnion	       FALSE
#	define Z_DECLARES_Type_MEMBER_is_union FALSE
#endif

#if Z_COMPILER_HAS_TRAIT(TYPE_UNDERLYING_TYPE)
#	define Z_DECLARES_TypeUnderlyingType	      TRUE
#	define Z_DECLARES_Type_MEMBER_underlying_type TRUE
#else
#	define Z_DECLARES_TypeUnderlyingType	      FALSE
#	define Z_DECLARES_Type_MEMBER_underlying_type FALSE
#endif

//-------------------------------------------------------------------------.
// Components that use built-in compiler traits if available. If not, they |
// are implemented using workarounds that require some C++11 features.	   |
//-------------------------------------------------------------------------'

#if Z_COMPILER_HAS_TRAIT(TYPE_IS_COMPLETE) || Z_DIALECT_HAS(CPP, EXPRESSION_SFINAE)
#	define Z_DECLARES_TypeIsComplete TRUE
#else
#	define Z_DECLARES_TypeIsComplete FALSE
#endif

#if	Z_COMPILER_HAS_TRAIT(TYPE_IS_DEFAULT_CONSTRUCTIBLE) || \
	(Z_DIALECT_HAS(CPP, EXPRESSION_SFINAE) && Z_DIALECT_HAS_SPECIFIER(CPP, DECLTYPE)) // No existe TYPE_IS_DEFAULT_CONSTRUCTIBLE

#	define Z_DECLARES_TypeIsDefaultConstructible	       TRUE
#	define Z_DECLARES_Type_MEMBER_is_default_constructible TRUE
#else
#	define Z_DECLARES_TypeIsDefaultConstructible	       FALSE
#	define Z_DECLARES_Type_MEMBER_is_default_constructible FALSE
#endif

#if Z_COMPILER_HAS_TRAIT(TYPE_IS_ENUMERATION) || Z_DIALECT_HAS(CPP, EXPRESSION_SFINAE)
#	define Z_DECLARES_TypeIsEnumeration	     TRUE
#	define Z_DECLARES_Type_MEMBER_is_enumeration TRUE
#else
#	define Z_DECLARES_TypeIsEnumeration	     FALSE
#	define Z_DECLARES_Type_MEMBER_is_enumeration FALSE
#endif

//----------------------------------------------------------------------.
// Components that require compiler built-in traits in addition to some |
// C++11 features to be implemented. There are no known workarounds.	|
//----------------------------------------------------------------------'

#if Z_DIALECT_HAS(CPP, VARIADIC_TEMPLATE) && Z_COMPILER_HAS_TRAIT(TYPE_IS_CONSTRUCTIBLE)
#	define Z_DECLARES_TypeIsConstructible TRUE
#else
#	define Z_DECLARES_TypeIsConstructible FALSE
#endif

#if Z_DIALECT_HAS(CPP, VARIADIC_TEMPLATE) && Z_COMPILER_HAS_TRAIT(TYPE_IS_NOTHROW_CONSTRUCTIBLE)
#	define Z_DECLARES_TypeIsNothrowConstructible TRUE
#else
#	define Z_DECLARES_TypeIsNothrowConstructible FALSE
#endif

#if Z_DIALECT_HAS(CPP, VARIADIC_TEMPLATE) && Z_COMPILER_HAS_TRAIT(TYPE_IS_TRIVIALLY_CONSTRUCTIBLE)
#	define Z_DECLARES_TypeIsTriviallyConstructible TRUE
#else
#	define Z_DECLARES_TypeIsTriviallyConstructible FALSE
#endif

//----------------------------------------------------------------.
// Components that require some C++11 features to be implemented. |
//----------------------------------------------------------------'

#ifdef Z_NULLPTR
#	define Z_DECLARES_TypeIsNullPtr		 TRUE
#	define Z_DECLARES_Type_MEMBER_is_nullptr TRUE
#else
#	define Z_DECLARES_TypeIsNullPtr		 FALSE
#	define Z_DECLARES_Type_MEMBER_is_nullptr FALSE
#endif

#if Z_DIALECT_HAS(CPP, EXTENDED_VARIADIC_TEMPLATE_TEMPLATE_PARAMETERS)
#	define Z_DECLARES_TypeIsTemplate	  TRUE
#	define Z_DECLARES_Type_MEMBER_is_template TRUE
#else
#	define Z_DECLARES_TypeIsTemplate	  FALSE
#	define Z_DECLARES_Type_MEMBER_is_template FALSE
#endif

#if Z_DECLARES(TypeList)
#	define Z_DECLARES_TypeParameter		 TRUE
#	define Z_DECLARES_TypeParameters	 TRUE
#	define Z_DECLARES_Type_MEMBER_parameters TRUE
#else
#	define Z_DECLARES_TypeParameter		 FALSE
#	define Z_DECLARES_TypeParameters	 FALSE
#	define Z_DECLARES_Type_MEMBER_parameters FALSE
#endif

#if Z_DIALECT_HAS(CPP, TYPE_ALIAS_TEMPLATE)
#	define Z_DECLARES_Type_MEMBER_add_member_pointer TRUE
#	define Z_DECLARES_Type_MEMBER_to_member_pointer  TRUE
#else
#	define Z_DECLARES_Type_MEMBER_add_member_pointer FALSE
#	define Z_DECLARES_Type_MEMBER_to_member_pointer  FALSE
#endif

#if Z_DIALECT_HAS(CPP, TYPE_ALIAS_TEMPLATE) && Z_DECLARES(TypeList)
#	define Z_DECLARES_Type_MEMBER_parameter TRUE
#else
#	define Z_DECLARES_Type_MEMBER_parameter FALSE
#endif

//------------------------------------------------.
// Components that require some C++14 features in |
// addition to compiler magic to be implemented.  |
//------------------------------------------------'

#if	Z_COMPILER_HAS_MAGIC_CONSTANT(MANGLED_FUNCTION_NAME) && \
	Z_DIALECT_HAS(CPP, CPP14_CONSTEXPR_FUNCTION)

#	define Z_DECLARES_Type_MEMBER_string	  TRUE
#	define Z_DECLARES_Type_MEMBER_string_size TRUE
#	define Z_DECLARES_Type_MEMBER_symbol	  TRUE
#else
#	define Z_DECLARES_Type_MEMBER_string	  FALSE
#	define Z_DECLARES_Type_MEMBER_string_size FALSE
#	define Z_DECLARES_Type_MEMBER_symbol	  FALSE
#endif

//---------------------------------------------------------.
// Components that are only available in Objective-C++ and |
// that require some C++11 features to be implemented.	   |
//---------------------------------------------------------'

#if Z_LANGUAGE_INCLUDES(OBJECTIVE_CPP) && Z_DIALECT_HAS(CPP, EXPRESSION_SFINAE)
#	define Z_DECLARES_TypeIsObjectiveCInstance		      TRUE
#	define Z_DECLARES_TypeIsObjectiveCInstancePointer	      TRUE
#	define Z_DECLARES_Type_MEMBER_is_objective_c_instance	      TRUE
#	define Z_DECLARES_Type_MEMBER_is_objective_c_instance_pointer TRUE
#else
#	define Z_DECLARES_TypeIsObjectiveCInstance		      FALSE
#	define Z_DECLARES_TypeIsObjectiveCInstancePointer	      FALSE
#	define Z_DECLARES_Type_MEMBER_is_objective_c_instance	      FALSE
#	define Z_DECLARES_Type_MEMBER_is_objective_c_instance_pointer FALSE
#endif

//--------------------------------------------------------------------.
// Aliases that are available only if the language supports template  |
// aliases and the components to which they refer are also available. |
//--------------------------------------------------------------------'

#if Z_DIALECT_HAS(CPP, TYPE_ALIAS_TEMPLATE)
#	define Z_DECLARES_type_add_const		  TRUE
#	define Z_DECLARES_type_add_const_volatile	  TRUE
#	define Z_DECLARES_type_add_lvalue_reference	  TRUE
#	define Z_DECLARES_type_add_member_pointer	  TRUE
#	define Z_DECLARES_type_add_pointer		  TRUE
#	define Z_DECLARES_type_add_volatile		  TRUE
#	define Z_DECLARES_type_class_type		  TRUE
#	define Z_DECLARES_type_element_type		  TRUE
#	define Z_DECLARES_type_indirectee_type		  TRUE
#	define Z_DECLARES_type_pointee_type		  TRUE
#	define Z_DECLARES_type_referencee_type		  TRUE
#	define Z_DECLARES_type_remove_array		  TRUE
#	define Z_DECLARES_type_remove_const		  TRUE
#	define Z_DECLARES_type_remove_const_this	  TRUE
#	define Z_DECLARES_type_remove_const_volatile	  TRUE
#	define Z_DECLARES_type_remove_const_volatile_this TRUE
#	define Z_DECLARES_type_remove_indirection	  TRUE
#	define Z_DECLARES_type_remove_member_pointer	  TRUE
#	define Z_DECLARES_type_remove_pointer		  TRUE
#	define Z_DECLARES_type_remove_reference		  TRUE
#	define Z_DECLARES_type_remove_this		  TRUE
#	define Z_DECLARES_type_remove_volatile		  TRUE
#	define Z_DECLARES_type_remove_volatile_this	  TRUE
#	define Z_DECLARES_type_return_type		  TRUE
#	define Z_DECLARES_type_to_const			  TRUE
#	define Z_DECLARES_type_to_const_volatile	  TRUE
#	define Z_DECLARES_type_to_forwardable		  TRUE
#	define Z_DECLARES_type_to_function		  TRUE
#	define Z_DECLARES_type_to_lvalue_reference	  TRUE
#	define Z_DECLARES_type_to_member_pointer	  TRUE
#	define Z_DECLARES_type_to_opaque		  TRUE
#	define Z_DECLARES_type_to_pointer		  TRUE
#	define Z_DECLARES_type_to_signed		  TRUE
#	define Z_DECLARES_type_to_unqualified		  TRUE
#	define Z_DECLARES_type_to_unsigned		  TRUE
#	define Z_DECLARES_type_to_volatile		  TRUE
#	define Z_DECLARES_type_to_wrap			  TRUE
#else
#	define Z_DECLARES_type_add_const		  FALSE
#	define Z_DECLARES_type_add_const_volatile	  FALSE
#	define Z_DECLARES_type_add_lvalue_reference	  FALSE
#	define Z_DECLARES_type_add_member_pointer	  FALSE
#	define Z_DECLARES_type_add_pointer		  FALSE
#	define Z_DECLARES_type_add_volatile		  FALSE
#	define Z_DECLARES_type_class_type		  FALSE
#	define Z_DECLARES_type_element_type		  FALSE
#	define Z_DECLARES_type_indirectee_type		  FALSE
#	define Z_DECLARES_type_pointee_type		  FALSE
#	define Z_DECLARES_type_referencee_type		  FALSE
#	define Z_DECLARES_type_remove_array		  FALSE
#	define Z_DECLARES_type_remove_const		  FALSE
#	define Z_DECLARES_type_remove_const_this	  FALSE
#	define Z_DECLARES_type_remove_const_volatile	  FALSE
#	define Z_DECLARES_type_remove_const_volatile_this FALSE
#	define Z_DECLARES_type_remove_indirection	  FALSE
#	define Z_DECLARES_type_remove_member_pointer	  FALSE
#	define Z_DECLARES_type_remove_pointer		  FALSE
#	define Z_DECLARES_type_remove_reference		  FALSE
#	define Z_DECLARES_type_remove_this		  FALSE
#	define Z_DECLARES_type_remove_volatile		  FALSE
#	define Z_DECLARES_type_remove_volatile_this	  FALSE
#	define Z_DECLARES_type_return_type		  FALSE
#	define Z_DECLARES_type_to_const			  FALSE
#	define Z_DECLARES_type_to_const_volatile	  FALSE
#	define Z_DECLARES_type_to_forwardable		  FALSE
#	define Z_DECLARES_type_to_function		  FALSE
#	define Z_DECLARES_type_to_lvalue_reference	  FALSE
#	define Z_DECLARES_type_to_member_pointer	  FALSE
#	define Z_DECLARES_type_to_opaque		  FALSE
#	define Z_DECLARES_type_to_pointer		  FALSE
#	define Z_DECLARES_type_to_signed		  FALSE
#	define Z_DECLARES_type_to_unqualified		  FALSE
#	define Z_DECLARES_type_to_unsigned		  FALSE
#	define Z_DECLARES_type_to_volatile		  FALSE
#	define Z_DECLARES_type_to_wrap			  FALSE
#endif

#if	Z_DIALECT_HAS(CPP, TYPE_ALIAS_TEMPLATE) && \
	Z_DIALECT_HAS(CPP, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)

#	define Z_DECLARES_type_add_const_lvalue		 TRUE
#	define Z_DECLARES_type_add_const_rvalue		 TRUE
#	define Z_DECLARES_type_add_const_volatile_lvalue TRUE
#	define Z_DECLARES_type_add_const_volatile_rvalue TRUE
#	define Z_DECLARES_type_add_lvalue		 TRUE
#	define Z_DECLARES_type_add_rvalue		 TRUE
#	define Z_DECLARES_type_add_volatile_lvalue	 TRUE
#	define Z_DECLARES_type_add_volatile_rvalue	 TRUE
#	define Z_DECLARES_type_to_const_lvalue		 TRUE
#	define Z_DECLARES_type_to_const_rvalue		 TRUE
#	define Z_DECLARES_type_to_const_volatile_lvalue	 TRUE
#	define Z_DECLARES_type_to_const_volatile_rvalue	 TRUE
#	define Z_DECLARES_type_to_lvalue		 TRUE
#	define Z_DECLARES_type_to_rvalue		 TRUE
#	define Z_DECLARES_type_to_volatile_lvalue	 TRUE
#	define Z_DECLARES_type_to_volatile_rvalue	 TRUE
#else
#	define Z_DECLARES_type_add_const_lvalue		 FALSE
#	define Z_DECLARES_type_add_const_rvalue		 FALSE
#	define Z_DECLARES_type_add_const_volatile_lvalue FALSE
#	define Z_DECLARES_type_add_const_volatile_rvalue FALSE
#	define Z_DECLARES_type_add_lvalue		 FALSE
#	define Z_DECLARES_type_add_rvalue		 FALSE
#	define Z_DECLARES_type_add_volatile_lvalue	 FALSE
#	define Z_DECLARES_type_add_volatile_rvalue	 FALSE
#	define Z_DECLARES_type_to_const_lvalue		 FALSE
#	define Z_DECLARES_type_to_const_rvalue		 FALSE
#	define Z_DECLARES_type_to_const_volatile_lvalue	 FALSE
#	define Z_DECLARES_type_to_const_volatile_rvalue	 FALSE
#	define Z_DECLARES_type_to_lvalue		 FALSE
#	define Z_DECLARES_type_to_rvalue		 FALSE
#	define Z_DECLARES_type_to_volatile_lvalue	 FALSE
#	define Z_DECLARES_type_to_volatile_rvalue	 FALSE
#endif

#if Z_DIALECT_HAS(CPP, TYPE_ALIAS_TEMPLATE) && Z_DIALECT_HAS(CPP, RVALUE_REFERENCE)
#	define Z_DECLARES_type_add_rvalue_reference TRUE
#	define Z_DECLARES_type_to_rvalue_reference  TRUE
#else
#	define Z_DECLARES_type_add_rvalue_reference FALSE
#	define Z_DECLARES_type_to_rvalue_reference  FALSE
#endif

#if Z_DIALECT_HAS(CPP, TYPE_ALIAS_TEMPLATE) && Z_DECLARES_MEMBER(Type, parameters)
#	define Z_DECLARES_type_parameters TRUE
#else
#	define Z_DECLARES_type_parameters FALSE
#endif

#if Z_DIALECT_HAS(CPP, TYPE_ALIAS_TEMPLATE) && Z_DECLARES_MEMBER(Type, underlying_type)
#	define Z_DECLARES_type_underlying_type TRUE
#else
#	define Z_DECLARES_type_underlying_type FALSE
#endif

#if Z_DECLARES_MEMBER(Type, parameter)
#	define Z_DECLARES_type_parameter TRUE
#else
#	define Z_DECLARES_type_parameter FALSE
#endif

// MARK: - Helpers

namespace Zeta {namespace Detail {namespace Type {namespace Helpers {

#	if Z_DIALECT_HAS(CPP, EXPRESSION_SFINAE)

		template <class T, Boolean B> struct IsConstruct			  : False {};
		template <class T>	      struct IsConstruct<T, !!sizeof(int (T::*))> : True  {};

		template <class T, Boolean B> struct IsUsableToCastNumber		     : False {};
		template <class T>	      struct IsUsableToCastNumber<T, !!sizeof((T)1)> : True  {};

#		if Z_DIALECT_HAS_SPECIFIER(CPP, DECLTYPE)

			template <class T, class R> struct IsDefaultConstructible		    : False {};
			template <class T>	    struct IsDefaultConstructible<T, decltype(T())> : True  {};

			template <class T, class F, class R> struct IsCallable : False {};
			template <class T, class F, class R> struct IsFunctor  : False {};

			#if Z_DIALECT_HAS(CPP, VARIADIC_TEMPLATE)

				template <class T, class R, class... P> struct IsCallable<T, R(P...), decltype(fake<T>()	   (fake<P>()...))> : True {};
				template <class T, class R, class... P> struct IsFunctor <T, R(P...), decltype(fake<T>().operator()(fake<P>()...))> : True {};

#			else

				template <class T, class R> struct IsCallable<T, R(), decltype(fake<T>()	   ())> : True {};
				template <class T, class R> struct IsFunctor <T, R(), decltype(fake<T>().operator()())> : True {};

#				define Z_TEMPLATE_FAKE_ARGUMENT(index) fake<P##index>()

#				define Z_TEMPLATE_SPECIALIZATIONS(parameter_count)								     \
																		     \
				template <class T, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct IsCallable<	     \
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

}}}}

namespace Zeta {

	template <class A, class B> struct TypeIsSame	    : False {};
	template <class A	  > struct TypeIsSame<A, A> : True  {};

#	if Z_DECLARES(TypeIsAssignable)
		template <class T, class from_type> struct TypeIsAssignable {
			enum {value = Z_COMPILER_TRAIT(TYPE_IS_ASSIGNABLE)(T, from_type)};
		};
#	endif

#	if Z_DECLARES(TypeIsBase)
		template <class T, class of_type> struct TypeIsBase {
			enum {value = Z_COMPILER_TRAIT(TYPE_IS_BASE)(T, of_type)};
		};
#	endif

#	if Z_DIALECT_HAS(CPP, EXPRESSION_SFINAE) && Z_DIALECT_HAS_SPECIFIER(CPP, DECLTYPE) // Añadir FLAG

		template <class T, class compatible_call_prototype> struct TypeIsCallable;
		template <class T, class compatible_call_prototype> struct TypeIsFunctor;

#		if Z_DIALECT_HAS(CPP, VARIADIC_TEMPLATE)

			template <class T, class R, class... P> struct TypeIsCallable<T, R(P...)> : Detail::Type::Helpers::IsCallable<T, R(P...), R> {};
			template <class T, class R, class... P> struct TypeIsFunctor <T, R(P...)> : Detail::Type::Helpers::IsFunctor <T, R(P...), R> {};

#		else

			template <class T, class R> struct TypeIsCallable<T, R()> : Detail::Type::Helpers::IsCallable<T, R(), R> {};
			template <class T, class R> struct TypeIsFunctor <T, R()> : Detail::Type::Helpers::IsFunctor <T, R(), R> {};

#			define Z_TEMPLATE_SPECIALIZATIONS(parameter_count)							     \
																     \
			template <class T, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct TypeIsCallable< \
				T, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA))					     \
			> : Detail::Type::Helpers::IsCallable<T, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA)), R> {};       \
																     \
			template <class T, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)> struct TypeIsFunctor<  \
				T, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA))					     \
			> : Detail::Type::Helpers::IsFunctor<T, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA)), R> {};

			Z_FOR_32_CALL_WITH_TIME(Z_TEMPLATE_SPECIALIZATIONS, Z_EMPTY)
#			undef Z_TEMPLATE_SPECIALIZATIONS

#		endif

#	endif

#	if Z_COMPILER_HAS_TRAIT(TYPE_IS_COMPLETE)

		template <class T, SInt at_line> struct TypeIsComplete {
			enum {value = Z_COMPILER_TRAIT(TYPE_IS_COMPLETE)(T)};
		};

#	elif Z_DIALECT_HAS(CPP, EXPRESSION_SFINAE)

		namespace Detail {namespace Type {namespace Helpers {namespace {
			template <class T, SInt L, Boolean B> struct TestCompleteness			 : False {};
			template <class T, SInt L>	      struct TestCompleteness<T, L, !!sizeof(T)> : True  {};
		}}}}

		namespace {
			template <class T, SInt at_line> struct TypeIsComplete : Detail::Type::Helpers::TestCompleteness<T, at_line, true> {};
		}

#	endif

#	if Z_DECLARES(TypeIsConvertible)
		template <class T, class to_type> struct TypeIsConvertible {
			enum {value = Z_COMPILER_TRAIT(TYPE_IS_CONVERTIBLE)(T, to_type)};
		};
#	endif

#	if Z_DECLARES(TypeIsConstructible)
		template <class T, class... parameters> struct TypeIsConstructible {
			enum {value = Z_COMPILER_TRAIT(TYPE_IS_CONSTRUCTIBLE)(T, parameters...)};
		};
#	endif

#	if Z_DECLARES(TypeIsNothrowAssignable)
		template <class T, class from_type> struct TypeIsNothrowAssignable {
			enum {value = Z_COMPILER_TRAIT(TYPE_IS_NOTHROW_ASSIGNABLE)(T, from_type)};
		};
#	endif

#	if Z_DECLARES(TypeIsNothrowConstructible)
		template <class T, class... parameters> struct TypeIsNothrowConstructible {
			enum {value = Z_COMPILER_TRAIT(TYPE_IS_NOTHROW_CONSTRUCTIBLE)(T, parameters...)};
		};
#	endif

#	if Z_DECLARES(TypeIsTriviallyAssignable)
		template <class T, class from_type> struct TypeIsTriviallyAssignable {
			enum {value = Z_COMPILER_TRAIT(TYPE_IS_TRIVIALLY_ASSIGNABLE)(T, from_type)};
		};
#	endif

#	if Z_DECLARES(TypeIsTriviallyConstructible)
		template <class T, class... parameters> struct TypeIsTriviallyConstructible {
			enum {value = Z_COMPILER_TRAIT(TYPE_IS_TRIVIALLY_CONSTRUCTIBLE)(T, parameters...)};
		};
#	endif

	template <class T> struct TypeRemovePointer	{typedef T type;};
	template <class T> struct TypeRemovePointer<T*> {typedef T type;};

	template <class T, class klass> struct TypeAddMemberPointer;

	template <class T, class C> struct TypeAddMemberPointer {typedef T C::*type;};

	template <class C> struct TypeAddMemberPointer<		      void, C> {typedef NaT type;};
	template <class C> struct TypeAddMemberPointer<const	      void, C> {typedef NaT type;};
	template <class C> struct TypeAddMemberPointer<const volatile void, C> {typedef NaT type;};
	template <class C> struct TypeAddMemberPointer<	     volatile void, C> {typedef NaT type;};

	template <class T, class C> struct TypeAddMemberPointer<T&, C> {typedef NaT type;};

#	if Z_DIALECT_HAS(CPP, RVALUE_REFERENCE)
		template <class T, class C> struct TypeAddMemberPointer<T&&, C> {typedef NaT type;};
#	endif
}

// MARK: - Abstract

namespace Zeta {namespace Detail {namespace Type {namespace Abstract {

	// MARK: - Abstract: Invalid

	struct Invalid {
		enum {	can_decorate_function	      = false,
			can_decorate_member_pointer   = false,
			can_decorate_pointer	      = false,
			can_decorate_reference	      = false,
			can_form_member_pointer	      = false,
			can_form_pointer	      = false,
			can_form_reference	      = false,
			has_qualified_indirectee      = false,
			is_arithmetic		      = false,
			is_array		      = false,
			is_block_object		      = false,
			is_boolean		      = false,
			is_class		      = false,
			is_compound		      = false,
			is_const		      = false,
			is_const_lvalue		      = false,
			is_const_rvalue		      = false,
			is_const_volatile	      = false,
			is_const_volatile_lvalue      = false,
			is_const_volatile_rvalue      = false,
			is_data_lvalue_reference      = false,
			is_data_member_pointer	      = false,
			is_data_pointer		      = false,
			is_data_reference	      = false,
			is_data_rvalue_reference      = false,
			is_empty		      = false,
			is_exact		      = false,
			is_indirection		      = false,
			is_integer		      = false,
			is_integral		      = false,
			is_floating_point	      = false,
			is_function		      = false,
			is_function_lvalue_reference  = false,
			is_function_pointer	      = false,
			is_function_reference	      = false,
			is_function_rvalue_reference  = false,
			is_fundamental		      = false,
			is_lvalue		      = false,
			is_lvalue_reference	      = false,
			is_member_function_pointer    = false,
			is_member_pointer	      = false,
			is_nat			      = true,
			is_natural		      = false,
			is_number		      = false,
			is_objective_c_class	      = false,
			is_objective_c_class_pointer  = false,
			is_objective_c_object	      = false,
			is_objective_c_object_pointer = false,
			is_pointer		      = false,
			is_qualified		      = false,
			is_real			      = false,
			is_reference		      = false,
			is_rvalue		      = false,
			is_rvalue_reference	      = false,
			is_scalar		      = false,
			is_signed		      = false,
			is_simple		      = false,
			is_sized_array		      = false,
			is_statically_allocatable     = false,
			is_storable		      = false,
			is_structure		      = false,
			is_unsigned		      = false,
			is_unsized_array	      = false,
			is_valid		      = false,
			is_variadic		      = false,
			is_variadic_function	      = false,
			is_void			      = false,
			is_void_pointer		      = false,
			is_volatile		      = false,
			is_volatile_lvalue	      = false,
			is_volatile_rvalue	      = false,
			iss_const		      = false,
			iss_const_lvalue	      = false,
			iss_const_rvalue	      = false,
			iss_const_volatile	      = false,
			iss_lvalue		      = false,
			iss_rvalue		      = false,
			iss_volatile		      = false,
			iss_volatile_lvalue	      = false,
			iss_volatile_rvalue	      = false
		};

		enum {	arity		  = 0,
			dimension_count	  = 0,
			element_count	  = 0,
			indirection_level = 0,
			pointer_level	  = 0
		};

		enum {	fixed_fundamental = 0,
			fundamental	  = 0,
			number_format	  = 0,
			number_set	  = 0,
		};

#		if Z_DECLARES_MEMBER(Type, has_virtual_destructor)
			enum {has_virtual_destructor = false};
#		endif

#		if Z_DECLARES_MEMBER(Type, is_abstract)
			enum {is_abstract = false};
#		endif

#		if Z_DECLARES_MEMBER(Type, is_aggregate)
			enum {is_aggregate = false};
#		endif

#		if Z_DECLARES_MEMBER(Type, is_default_constructible)
			enum {is_default_constructible = false};
#		endif

#		if Z_DECLARES_MEMBER(Type, is_enumeration)
			enum {is_enumeration = false};
#		endif

#		if Z_DECLARES_MEMBER(Type, is_final)
			enum {is_final = false};
#		endif

#		if Z_DECLARES_MEMBER(Type, is_interface_class)
			enum {is_interface_class = false};
#		endif

#		if Z_DECLARES_MEMBER(Type, is_literal)
			enum {is_literal = false};
#		endif

#		if Z_DECLARES_MEMBER(Type, is_noexcept)
			enum {is_noexcept = false};
#		endif

#		if Z_DECLARES_MEMBER(Type, is_nullptr)
			enum {is_nullptr = false};
#		endif

#		if Z_DECLARES_MEMBER(Type, is_pod)
			enum {is_pod = false};
#		endif

#		if Z_DECLARES_MEMBER(Type, is_polymorphic)
			enum {is_polymorphic = false};
#		endif

#		if Z_DECLARES_MEMBER(Type, is_template)
			enum {is_template = false};
#		endif

#		if Z_DECLARES_MEMBER(Type, is_trivially_copy_assignable)
			enum {is_trivially_copy_assignable = false};
#		endif

#		if Z_DECLARES_MEMBER(Type, is_trivially_copy_constructible)
			enum {is_trivially_copy_constructible = false};
#		endif

#		if Z_DECLARES_MEMBER(Type, is_trivially_copyable)
			enum {is_trivially_copyable = false};
#		endif

#		if Z_DECLARES_MEMBER(Type, is_trivially_default_constructible)
			enum {is_trivially_default_constructible = false};
#		endif

#		if Z_DECLARES_MEMBER(Type, is_trivially_destructible)
			enum {is_trivially_destructible = false};
#		endif

#		if Z_DECLARES_MEMBER(Type, is_union)
			enum {is_union = false};
#		endif

#		if Z_LANGUAGE_INCLUDES(OBJECTIVE_CPP) && Z_DIALECT_HAS(CPP, EXPRESSION_SFINAE)
			enum {	is_objective_c_instance		= false,
				is_objective_c_instance_pointer = false
			};
#		endif

		typedef NaT type;

		typedef NaT add_const;
		typedef NaT add_const_volatile;
		typedef NaT add_lvalue_reference;
		typedef NaT add_pointer;
		typedef NaT add_volatile;
		typedef NaT class_type;
		typedef NaT element_type;
		typedef NaT indirectee_type;
		typedef NaT pointee_type;
		typedef NaT referencee_type;
		typedef NaT remove_array;
		typedef NaT remove_const;
		typedef NaT remove_const_this;
		typedef NaT remove_const_volatile;
		typedef NaT remove_const_volatile_this;
		typedef NaT remove_indirection;
		typedef NaT remove_member_pointer;
		typedef NaT remove_pointer;
		typedef NaT remove_reference;
		typedef NaT remove_this;
		typedef NaT remove_volatile;
		typedef NaT remove_volatile_this;
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
		typedef NaT to_unspecified;
		typedef NaT to_unsigned;
		typedef NaT to_volatile;
		typedef NaT to_wrap;

#		if Z_DIALECT_HAS(CPP, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)
			typedef NaT add_const_lvalue;
			typedef NaT add_const_rvalue;
			typedef NaT add_const_volatile_lvalue;
			typedef NaT add_const_volatile_rvalue;
			typedef NaT add_lvalue;
			typedef NaT add_rvalue;
			typedef NaT add_volatile_lvalue;
			typedef NaT add_volatile_rvalue;
			typedef NaT to_const_lvalue;
			typedef NaT to_const_rvalue;
			typedef NaT to_const_volatile_lvalue;
			typedef NaT to_const_volatile_rvalue;
			typedef NaT to_lvalue;
			typedef NaT to_rvalue;
			typedef NaT to_volatile_lvalue;
			typedef NaT to_volatile_rvalue;
#		endif

#		if Z_DIALECT_HAS(CPP, NOEXCEPT_AS_PART_OF_THE_FUNCTION_TYPE)
			typedef NaT add_noexcept;
			typedef NaT remove_noexcept;
#		endif

#		if Z_DIALECT_HAS(CPP, RVALUE_REFERENCE)
			typedef NaT add_rvalue_reference;
			typedef NaT to_rvalue_reference;
#		endif

#		if Z_DECLARES_MEMBER(Type, remove_noexcept)
#		endif

#		if Z_DECLARES_MEMBER(Type, parameters)
			typedef NaT parameters;
#		endif

#		if Z_DECLARES_MEMBER(Type, underlying_type)
			typedef NaT underlying_type;
#		endif

#		if Z_DIALECT_HAS(CPP, TYPE_ALIAS_TEMPLATE)
			template <class klass> using add_member_pointer = NaT;
			template <class klass> using to_member_pointer	= NaT;
#		endif

#		if Z_DECLARES_MEMBER(Type, parameter)
			template <zuint index> using parameter = NaT;
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

#		if Z_DECLARES_MEMBER(Type, is_literal)
			enum {is_literal = true};
#		endif

#		if Z_DECLARES_MEMBER(Type, is_trivially_copy_constructible)
			enum {is_trivially_copy_constructible = true};
#		endif

#		if Z_DECLARES_MEMBER(Type, is_trivially_destructible)
			enum {is_trivially_destructible = true};
#		endif

		//----------------------------------------------.
		// Unlike the standard C++ library, Z considers |
		// the following to be "true" for references:	|
		//----------------------------------------------'

#		if Z_DECLARES_MEMBER(Type, is_default_constructible)
			enum {is_default_constructible = true};
#		endif

#		if Z_DECLARES_MEMBER(Type, is_trivially_copy_assignable)
			enum {is_trivially_copy_assignable = true};
#		endif

#		if Z_DECLARES_MEMBER(Type, is_trivially_copyable)
			enum {is_trivially_copyable = true};
#		endif

#		if Z_DECLARES_MEMBER(Type, is_trivially_default_constructible)
			enum {is_trivially_default_constructible = true};
#		endif
	};

	struct Number : Simple {
		enum {	is_arithmetic  = true,
			is_fundamental = true,
			is_number      = true,
			is_scalar      = true
		};

#		if Z_DECLARES_MEMBER(Type, is_pod)
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

	struct FloatingPoint : Real {
		enum {is_floating_point = true};
	};

	struct PointerLike : Simple {
		enum {is_scalar = true};

#		if Z_DECLARES_MEMBER(Type, is_pod)
			enum {is_pod = true};
#		endif
	};

	// MARK: - Abstract: Standard C/C++ fundamental types

	struct Void : Valid {
		enum {	is_fundamental = true,
			is_void	       = true
		};

#		if Z_DECLARES_MEMBER(Type, is_literal)
			enum {is_literal = true};
#		endif

		typedef void type;
	};

	struct Char : Z_TERNARY(Z_CHAR_IS_SIGNED)(Integer, Natural) {
		enum {	fundamental	  = Z_CHAR_FUNDAMENTAL,
			fixed_fundamental = Z_CHAR_FIXED_FUNDAMENTAL,
			number_format	  = Z_CHAR_NUMBER_FORMAT
		};
		enum {	minimum = Z_CHAR_MINIMUM,
			maximum = Z_CHAR_MAXIMUM
		};

		typedef zchar  type;
		typedef zuchar to_unsigned;
		typedef zschar to_signed;
	};

#	define Z_IMPLEMENTATION(NAME, Name, name)			   \
									   \
	struct U##Name : Natural {					   \
		enum {	fundamental	  = Z_U##NAME##_FUNDAMENTAL,	   \
			fixed_fundamental = Z_U##NAME##_FIXED_FUNDAMENTAL, \
			number_format	  = Z_U##NAME##_NUMBER_FORMAT	   \
		};							   \
		enum {maximum = Z_U##NAME##_MAXIMUM};			   \
									   \
		typedef zu##name type;					   \
		typedef zu##name to_unsigned;				   \
		typedef zs##name to_signed;				   \
	};								   \
									   \
	struct S##Name : Integer {					   \
		enum {	fundamental	  = Z_S##NAME##_FUNDAMENTAL,	   \
			fixed_fundamental = Z_S##NAME##_FIXED_FUNDAMENTAL, \
			number_format	  = Z_S##NAME##_NUMBER_FORMAT	   \
		};							   \
		enum {	minimum = Z_S##NAME##_MINIMUM,			   \
			maximum = Z_S##NAME##_MAXIMUM			   \
		};							   \
									   \
		typedef zs##name type;					   \
		typedef zu##name to_unsigned;				   \
		typedef zs##name to_signed;				   \
	};

	Z_IMPLEMENTATION(CHAR,	Char,  char )
	Z_IMPLEMENTATION(SHORT, Short, short)
	Z_IMPLEMENTATION(INT,	Int,   int  )
	Z_IMPLEMENTATION(LONG,	Long,  long )

#	ifdef Z_LLONG
		Z_IMPLEMENTATION(LLONG, LLong, llong)
#	endif

#	undef Z_IMPLEMENTATION

#	if Z_DIALECT_HAS_TYPE(CPP, BOOL) || Z_DIALECT_HAS_TYPE(C, BOOL)

		struct Boolean : Integral {
			enum {is_boolean = true};

			typedef bool type;
		};

#	endif

#	if Z_DIALECT_HAS_TYPE(CPP, WCHAR_T)

		struct WChar : Natural { // TODO: Can be Integer
			enum {fundamental = Z_FUNDAMENTAL_WCHAR};

			typedef wchar_t type;
		};

#	endif

#	define Z_IMPLEMENTATION(bits)						\
										\
	struct Char##bits : Natural {						\
		enum {	fundamental	  = Z_FUNDAMENTAL_CHAR##bits,		\
			fixed_fundamental = Z_FUNDAMENTAL_UINT##bits,		\
			number_format	  = Z_NUMBER_FORMAT_##bits##BIT_NATURAL \
		};								\
										\
		typedef char##bits##_t type;					\
		typedef char##bits##_t to_unsigned;				\
	};

/*#	if Z_DIALECT_HAS_TYPE(CPP, CHAR8_T)
		Z_IMPLEMENTATION(8)
#	endif*/

#	if Z_DIALECT_HAS_TYPE(CPP, CHAR16_T)
		Z_IMPLEMENTATION(16)
#	endif

#	if Z_DIALECT_HAS_TYPE(CPP, CHAR32_T)
		Z_IMPLEMENTATION(32)
#	endif

#	undef Z_IMPLEMENTATION

#	define Z_IMPLEMENTATION(bits)					      \
									      \
	struct UInt##bits : Natural {					      \
		enum {	fundamental	  = Z_UINT##bits##_FUNDAMENTAL,	      \
			fixed_fundamental = Z_UINT##bits##_FIXED_FUNDAMENTAL, \
			number_format	  = Z_UINT##bits##_NUMBER_FORMAT      \
		};							      \
		enum {maximum = Z_UINT##bits##_MAXIMUM};		      \
									      \
		typedef zuint##bits type;				      \
		typedef zuint##bits to_unsigned;			      \
									      \
		Z_IF(Z_DATA_MODEL_HAS_TYPE(SINT##bits))			      \
			(typedef zsint##bits to_signed;)		      \
	};

#	if defined(Z_UINT8) && Z_UINT8_FUNDAMENTAL == Z_FUNDAMENTAL_UINT8
		Z_IMPLEMENTATION(8)
#	endif

#	if defined(Z_UINT16) && Z_UINT16_FUNDAMENTAL == Z_FUNDAMENTAL_UINT16
		Z_IMPLEMENTATION(16)
#	endif

#	if defined(Z_UINT24) && Z_UINT24_FUNDAMENTAL == Z_FUNDAMENTAL_UINT24
		Z_IMPLEMENTATION(24)
#	endif

#	if defined(Z_UINT32) && Z_UINT32_FUNDAMENTAL == Z_FUNDAMENTAL_UINT32
		Z_IMPLEMENTATION(32)
#	endif

#	if defined(Z_UINT40) && Z_UINT40_FUNDAMENTAL == Z_FUNDAMENTAL_UINT40
		Z_IMPLEMENTATION(40)
#	endif

#	if defined(Z_UINT48) && Z_UINT48_FUNDAMENTAL == Z_FUNDAMENTAL_UINT48
		Z_IMPLEMENTATION(48)
#	endif

#	if defined(Z_UINT56) && Z_UINT56_FUNDAMENTAL == Z_FUNDAMENTAL_UINT56
		Z_IMPLEMENTATION(56)
#	endif

#	if defined(Z_UINT64) && Z_UINT64_FUNDAMENTAL == Z_FUNDAMENTAL_UINT64
		Z_IMPLEMENTATION(64)
#	endif

#	if defined(Z_UINT128) && Z_UINT128_FUNDAMENTAL == Z_FUNDAMENTAL_UINT128
		Z_IMPLEMENTATION(128)
#	endif

#	undef Z_IMPLEMENTATION

#	define Z_IMPLEMENTATION(bits)					      \
									      \
	struct SInt##bits : Integer {					      \
		enum {	fundamental	  = Z_SINT##bits##_FUNDAMENTAL,	      \
			fixed_fundamental = Z_SINT##bits##_FIXED_FUNDAMENTAL, \
			number_format	  = Z_SINT##bits##_NUMBER_FORMAT      \
		};							      \
		enum {	minimum = Z_SINT##bits##_MINIMUM,		      \
			maximum = Z_SINT##bits##_MAXIMUM		      \
		};							      \
									      \
		typedef zsint##bits type;				      \
		typedef zsint##bits to_signed;				      \
									      \
		Z_IF(Z_DATA_MODEL_HAS_TYPE(UINT##bits))			      \
			(typedef zuint##bits to_unsigned;)		      \
	};

#	if defined(Z_SINT8) && Z_SINT8_FUNDAMENTAL == Z_FUNDAMENTAL_SINT8
		Z_IMPLEMENTATION(8)
#	endif

#	if defined(Z_SINT16) && Z_SINT16_FUNDAMENTAL == Z_FUNDAMENTAL_SINT16
		Z_IMPLEMENTATION(16)
#	endif

#	if defined(Z_SINT24) && Z_SINT24_FUNDAMENTAL == Z_FUNDAMENTAL_SINT24
		Z_IMPLEMENTATION(24)
#	endif

#	if defined(Z_SINT32) && Z_SINT32_FUNDAMENTAL == Z_FUNDAMENTAL_SINT32
		Z_IMPLEMENTATION(32)
#	endif

#	if defined(Z_SINT40) && Z_SINT40_FUNDAMENTAL == Z_FUNDAMENTAL_SINT40
		Z_IMPLEMENTATION(40)
#	endif

#	if defined(Z_SINT48) && Z_SINT48_FUNDAMENTAL == Z_FUNDAMENTAL_SINT48
		Z_IMPLEMENTATION(48)
#	endif

#	if defined(Z_SINT56) && Z_SINT56_FUNDAMENTAL == Z_FUNDAMENTAL_SINT56
		Z_IMPLEMENTATION(56)
#	endif

#	if defined(Z_SINT64) && Z_SINT64_FUNDAMENTAL == Z_FUNDAMENTAL_SINT64
		Z_IMPLEMENTATION(64)
#	endif

#	if defined(Z_SINT128) && Z_SINT128_FUNDAMENTAL == Z_FUNDAMENTAL_SINT128
		Z_IMPLEMENTATION(128)
#	endif

#	undef Z_IMPLEMENTATION

#	define Z_IMPLEMENTATION(NAME, Name, name)						    \
												    \
	struct Name : FloatingPoint {								    \
		enum {	fundamental	  = Z_##NAME##_FUNDAMENTAL,				    \
			fixed_fundamental = Z_##NAME##_FIXED_FUNDAMENTAL,			    \
			number_format	  = Z_##NAME##_NUMBER_FORMAT				    \
		};										    \
		enum {	digits_10	    = Z_##NAME##_DIGITS_10,				    \
			maximum_digits_10   = Z_##NAME##_MAXIMUM_DIGITS_10,			    \
			radix		    = Z_##NAME##_RADIX,					    \
			significand_digits  = Z_##NAME##_SIGNIFICAND_DIGITS,			    \
			exponent_maximum    = Z_##NAME##_EXPONENT_MAXIMUM,			    \
			exponent_minimum    = Z_##NAME##_EXPONENT_MINIMUM,			    \
			exponent_10_maximum = Z_##NAME##_EXPONENT_10_MAXIMUM,			    \
			exponent_10_minimum = Z_##NAME##_EXPONENT_10_MINIMUM			    \
		};										    \
												    \
		static Z_CT(CPP11) z##name epsilon	   () {return Z_##NAME##_EPSILON;}	    \
		static Z_CT(CPP11) z##name maximum	   () {return Z_##NAME##_MAXIMUM;}	    \
		static Z_CT(CPP11) z##name minimum	   () {return Z_##NAME##_MINIMUM;}	    \
		static Z_CT(CPP11) z##name denormal_minimum() {return Z_##NAME##_DENORMAL_MINIMUM;} \
												    \
		typedef z##name type;								    \
		typedef z##name to_signed;							    \
	};

#	ifdef Z_FLOAT
		Z_IMPLEMENTATION(FLOAT, Float, float)
#	endif

#	ifdef Z_DOUBLE
		Z_IMPLEMENTATION(DOUBLE, Double, double)
#	endif

#	ifdef Z_LDOUBLE
		Z_IMPLEMENTATION(LDOUBLE, LDouble, ldouble)
#	endif

/*#	ifdef Z_FLOAT16
		Z_IMPLEMENTATION(FLOAT16, Float16, float16)
#	endif

#	ifdef Z_FLOAT32
		Z_IMPLEMENTATION(FLOAT32, Float32, float32)
#	endif

#	ifdef Z_FLOAT64
		Z_IMPLEMENTATION(FLOAT64, Float64, float64)
#	endif

#	ifdef Z_FLOAT128
		Z_IMPLEMENTATION(FLOAT128, Float128, float128)
#	endif

#	ifdef Z_FLOAT32X
		Z_IMPLEMENTATION(FLOAT32X, Float32x, float32x)
#	endif

#	ifdef Z_FLOAT64X
		Z_IMPLEMENTATION(FLOAT64X, Float64x, float64x)
#	endif

#	ifdef Z_FLOAT128X
		Z_IMPLEMENTATION(FLOAT128X, Float128x, float128x)
#	endif

#	ifdef Z_DECIMAL32
		Z_IMPLEMENTATION(DECIMAL32, Decimal32, decimal32)
#	endif

#	ifdef Z_DECIMAL64
		Z_IMPLEMENTATION(DECIMAL64, Decimal64, decimal64)
#	endif

#	ifdef Z_DECIMAL128
		Z_IMPLEMENTATION(DECIMAL128, Decimal128, decimal128)
#	endif

#	ifdef Z_DECIMAL64X
		Z_IMPLEMENTATION(DECIMAL64X, Decimal64x, decimal64x)
#	endif

#	ifdef Z_DECIMAL128X
		Z_IMPLEMENTATION(DECIMAL128X, Decimal128x, decimal128x)
#	endif*/

#	if defined(Z_BFP16) && Z_BFP16_FUNDAMENTAL == Z_FUNDAMENTAL_BFP16
		Z_IMPLEMENTATION(BFP16, BFP16, bfp16)
#	endif

#	if defined(Z_BFP32) && Z_BFP32_FUNDAMENTAL == Z_FUNDAMENTAL_BFP32
		Z_IMPLEMENTATION(BFP32, BFP32, bfp32)
#	endif

#	if defined(Z_BFP64) && Z_BFP64_FUNDAMENTAL == Z_FUNDAMENTAL_BFP64
		Z_IMPLEMENTATION(BFP64, BFP64, bfp64)
#	endif

#	if defined(Z_BFP128) && Z_BFP128_FUNDAMENTAL == Z_FUNDAMENTAL_BFP128
		Z_IMPLEMENTATION(BFP128, BFP128, bfp128)
#	endif

#	if defined(Z_DFP32) && Z_DFP32_FUNDAMENTAL == Z_FUNDAMENTAL_DFP32
		Z_IMPLEMENTATION(DFP32, DFP32, dfp32)
#	endif

#	if defined(Z_DFP64) && Z_DFP64_FUNDAMENTAL == Z_FUNDAMENTAL_DFP64
		Z_IMPLEMENTATION(DFP64, DFP64, dfp64)
#	endif

#	if defined(Z_DFP128) && Z_DFP128_FUNDAMENTAL == Z_FUNDAMENTAL_DFP128
		Z_IMPLEMENTATION(DFP128, DFP128, dfp128)
#	endif

#	if defined(Z_X87_DE80) && Z_X87_DE80_FUNDAMENTAL == Z_FUNDAMENTAL_X87_DE80
		Z_IMPLEMENTATION(X87_DE80, x87_DE80, x87_de80)
#	endif

#	if defined(Z_X87_DE96) && Z_X87_DE96_FUNDAMENTAL == Z_FUNDAMENTAL_X87_DE96
		Z_IMPLEMENTATION(X87_DE96, x87_DE96, x87_de96)
#	endif

#	if defined(Z_X87_DE128) && Z_X87_DE128_FUNDAMENTAL == Z_FUNDAMENTAL_X87_DE128
		Z_IMPLEMENTATION(X87_DE128, x87_DE128, x87_de128)
#	endif

#	undef Z_IMPLEMENTATION

#	if Z_DECLARES_MEMBER(Type, is_nullptr)

		struct NullPtr : PointerLike {
			enum {	is_fundamental	= true,
				is_nullptr = true
			};

			typedef decltype(nullptr) type;
		};

#	endif

	// MARK: - Abstract: Array types

	template <zboolean E, class T> struct Array;

	template <class T> struct Array<false, T> : Storable {
		enum {is_array = true};

		typedef T element_type;
	};

	template <class T> struct Array<true, T> : Array<false, T> {
#		if Z_DECLARES_MEMBER(Type, is_aggregate)
			enum {is_aggregate = true};
#		endif

#		if Z_COMPILER_HAS_TRAIT(TYPE_IS_DEFAULT_CONSTRUCTIBLE) // No existe TYPE_IS_DEFAULT_CONSTRUCTIBLE
			enum {is_default_constructible = Z_COMPILER_TRAIT(TYPE_IS_DEFAULT_CONSTRUCTIBLE)(T)};
#		elif Z_DECLARES_MEMBER(Type, is_default_constructible)
			enum {is_default_constructible = Helpers::IsDefaultConstructible<T, T>::value};
#		endif

#		if Z_DECLARES_MEMBER(Type, is_literal)
			enum {is_literal = Z_COMPILER_TRAIT(TYPE_IS_LITERAL)(T)};
#		endif

#		if Z_DECLARES_MEMBER(Type, is_pod)
			enum {is_pod = Z_COMPILER_TRAIT(TYPE_IS_POD)(T)};
#		endif

#		if Z_DECLARES_MEMBER(Type, is_trivially_copy_constructible)
			enum {is_trivially_copy_constructible = Z_COMPILER_TRAIT(TYPE_IS_TRIVIALLY_COPY_CONSTRUCTIBLE)(T)};
#		endif

#		if Z_DECLARES_MEMBER(Type, is_trivially_copyable)
			enum {is_trivially_copyable = Z_COMPILER_TRAIT(TYPE_IS_TRIVIALLY_COPYABLE)(T)};
#		endif

#		if Z_DECLARES_MEMBER(Type, is_trivially_default_constructible)
			enum {is_trivially_default_constructible = Z_COMPILER_TRAIT(TYPE_IS_TRIVIALLY_DEFAULT_CONSTRUCTIBLE)(T)};
#		endif

#		if Z_DECLARES_MEMBER(Type, is_trivially_destructible)
			enum {is_trivially_destructible = Z_COMPILER_TRAIT(TYPE_IS_TRIVIALLY_DESTRUCTIBLE)(T)};
#		endif
	};

	template <zboolean E, class T, zusize N> struct SizedArray : Array<E, T> {
		enum {	is_empty		  = (N == 0),
			is_statically_allocatable = true,
			is_sized_array		  = true
		};
		enum {element_count = N};

		typedef T type[N];
	};

	template <zboolean E, class T> struct UnsizedArray : Array<E, T> {
		enum {	is_empty	 = true,
			is_unsized_array = true
		};

		typedef T type[];
	};

	// MARK: - Abstract: Pointer types

	template <class T> struct Pointer : PointerLike {
		enum {	is_indirection = true,
			is_pointer     = true
		};

		typedef T* type;
		typedef T  indirectee_type;
		typedef T  pointee_type;
	};

	template <class T, class C, class M> struct MemberPointer : PointerLike {
		enum {	is_indirection	  = true,
			is_member_pointer = true
		};

		typedef T type;
		typedef C class_type;
		typedef M indirectee_type;
		typedef M pointee_type;
	};

	// MARK: - Abstract: Reference types

	template <class T> struct Reference : Simple {
		enum {	is_indirection = true,
			is_reference   = true
		};

		typedef T indirectee_type;
		typedef T referencee_type;
	};

	template <class T> struct LValueReference : Reference<T> {
		enum {is_lvalue_reference = true};

		typedef T& type;
	};

#	if Z_DIALECT_HAS(CPP, RVALUE_REFERENCE)

		template <class T> struct RValueReference : Reference<T> {
			enum {is_rvalue_reference = true};

			typedef T&& type;
		};

#	endif

	// MARK: - Specializations: Function types

#	if Z_DIALECT_HAS(CPP, NOEXCEPT_AS_PART_OF_THE_FUNCTION_TYPE)

		template <zboolean is_noexcept, class T, class C = Empty> struct Function;

#		define Z_PARTIAL__NOEXCEPT noexcept(X)

#	else
#		define Z_PARTIAL__NOEXCEPT
#	endif

#	define Z_PARTIAL__COMMON_CONVERSIONS(parameters)			    \
	typedef R to_const	   (parameters) const	       Z_PARTIAL__NOEXCEPT; \
	typedef R to_const_volatile(parameters) const volatile Z_PARTIAL__NOEXCEPT; \
	typedef R to_unqualified   (parameters)		       Z_PARTIAL__NOEXCEPT; \
	typedef R to_volatile	   (parameters)	volatile       Z_PARTIAL__NOEXCEPT;

#	if Z_DIALECT_HAS(CPP, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)

#		define Z_PARTIAL__REFERENCE_CONVERSIONS(parameters)				      \
		typedef R to_const_lvalue	  (parameters) const	      &	 Z_PARTIAL__NOEXCEPT; \
		typedef R to_const_rvalue	  (parameters) const	      && Z_PARTIAL__NOEXCEPT; \
		typedef R to_const_volatile_lvalue(parameters) const volatile &	 Z_PARTIAL__NOEXCEPT; \
		typedef R to_const_volatile_rvalue(parameters) const volatile && Z_PARTIAL__NOEXCEPT; \
		typedef R to_lvalue		  (parameters)		      &	 Z_PARTIAL__NOEXCEPT; \
		typedef R to_rvalue		  (parameters)		      && Z_PARTIAL__NOEXCEPT; \
		typedef R to_volatile_lvalue	  (parameters)	     volatile &	 Z_PARTIAL__NOEXCEPT; \
		typedef R to_volatile_rvalue	  (parameters)	     volatile && Z_PARTIAL__NOEXCEPT;

#	else
#		define Z_PARTIAL__REFERENCE_CONVERSIONS(parameters)
#	endif

#	if Z_DIALECT_HAS(CPP, VARIADIC_TEMPLATE)

#		if Z_DIALECT_HAS(CPP, NOEXCEPT_AS_PART_OF_THE_FUNCTION_TYPE)

			template <zboolean X, class R, class... P, class C> struct Function<X, R(P...), C> : C {
				Z_PARTIAL__COMMON_CONVERSIONS	(P...)
				Z_PARTIAL__REFERENCE_CONVERSIONS(P...)
			};

			template <zboolean X, class R, class... P, class C> struct Function<X, R(P..., ...), C> : C {
				Z_PARTIAL__COMMON_CONVERSIONS	(P... Z_COMMA ...)
				Z_PARTIAL__REFERENCE_CONVERSIONS(P... Z_COMMA ...)
			};

#		endif

#		if Z_DIALECT_HAS(CPP, NOEXCEPT_AS_PART_OF_THE_FUNCTION_TYPE)
			template <zboolean X, class R, class... P> struct NonVariadicFunction : Function<X, R(P...), Valid> {
				enum {is_noexcept = X};
#		else
			template <class R, class... P> struct NonVariadicFunction : Valid {
				Z_PARTIAL__COMMON_CONVERSIONS	(P...)
				Z_PARTIAL__REFERENCE_CONVERSIONS(P...)
#		endif
			enum {is_function = true};
			enum {arity = TypeCount<P...>::value};

			typedef R type(P...);
			typedef R return_type;

#			if Z_DECLARES_MEMBER(Type, parameters)
				typedef TypeList<P...> parameters;
#			endif

#			if Z_DECLARES_MEMBER(Type, parameter)
				template <zuint index> using parameter = typename TypeListGet<parameters, index>::type;
#			endif
		};

#		if Z_DIALECT_HAS(CPP, NOEXCEPT_AS_PART_OF_THE_FUNCTION_TYPE)
			template <zboolean X, class R, class... P> struct VariadicFunction : Function<X, R(P..., ...), Valid> {
				enum {is_noexcept = X};
#		else
			template <class R, class... P> struct VariadicFunction : Valid {
				Z_PARTIAL__COMMON_CONVERSIONS	(P... Z_COMMA ...)
				Z_PARTIAL__REFERENCE_CONVERSIONS(P... Z_COMMA ...)
#		endif
			enum {	is_function = true,
				is_variadic = true
			};
			enum {arity = TypeCount<P...>::value};

			typedef R type(P..., ...);
			typedef R return_type;

#			if Z_DECLARES_MEMBER(Type, parameters)
				typedef TypeList<P...> parameters;
#			endif

#			if Z_DECLARES_MEMBER(Type, parameter)
				template <zuint index> using parameter = typename TypeListGet<parameters, index>::type;
#			endif
		};

#	else

#		if Z_DIALECT_HAS(CPP, NOEXCEPT_AS_PART_OF_THE_FUNCTION_TYPE)

#			define Z_IMPLEMENTATION(parameter_count)											\
																			\
			template <zboolean X, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA) Z_IF(parameter_count)(Z_COMMA) class C>	\
			struct Function<X, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA)), C>							\
			: C {	Z_PARTIAL__COMMON_CONVERSIONS	(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA))					\
				Z_PARTIAL__REFERENCE_CONVERSIONS(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA))					\
			};																\
																			\
			template <zboolean X, class R, Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA) Z_IF(parameter_count)(Z_COMMA) class C>	\
			struct Function<X, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA) Z_IF(parameter_count)(Z_COMMA) ...), C>			\
			: C {	Z_PARTIAL__COMMON_CONVERSIONS	(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA) Z_IF(parameter_count)(Z_COMMA) ...)	\
				Z_PARTIAL__REFERENCE_CONVERSIONS(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA) Z_IF(parameter_count)(Z_COMMA) ...)	\
			};																\
																			\
			template <zboolean X, class R Z_IF(parameter_count)(Z_COMMA) Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)>		\
			struct NonVariadicFunctionWith##parameter_count##Parameters									\
			: Function<X, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA)), Valid> {							\
				enum {	is_function = true,												\
					is_noexcept = X													\
				};															\
				enum {arity = parameter_count};												\
																			\
				typedef R type(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA));							\
				typedef R return_type;													\
			};																\
																			\
			template <zboolean X, class R Z_IF(parameter_count)(Z_COMMA) Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)>		\
			struct VariadicFunctionWith##parameter_count##Parameters									\
			: Function<X, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA) Z_IF(parameter_count)(Z_COMMA) ...), Valid> {		\
				enum {	is_function = true,												\
					is_noexcept = X,												\
					is_variadic = true												\
				};															\
				enum {arity = parameter_count};												\
																			\
				typedef R type(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA) Z_IF(parameter_count)(Z_COMMA) ...);			\
				typedef R return_type;													\
			};

#		else

#			define Z_IMPLEMENTATION(parameter_count)											\
																			\
			template <class R Z_IF(parameter_count)(Z_COMMA) Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)>			\
			struct NonVariadicFunctionWith##parameter_count##Parameters : Valid {								\
				Z_PARTIAL__COMMON_CONVERSIONS	(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA))					\
				Z_PARTIAL__REFERENCE_CONVERSIONS(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA))					\
																			\
				enum {is_function = true};												\
				enum {arity = parameter_count};												\
																			\
				typedef R type(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA));							\
				typedef R return_type;													\
			};																\
																			\
			template <class R Z_IF(parameter_count)(Z_COMMA) Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)>			\
			struct VariadicFunctionWith##parameter_count##Parameters : Valid {								\
				Z_PARTIAL__COMMON_CONVERSIONS	(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA) Z_IF(parameter_count)(Z_COMMA) ...) \
				Z_PARTIAL__REFERENCE_CONVERSIONS(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA) Z_IF(parameter_count)(Z_COMMA) ...) \
																			\
				enum {	is_function = true,												\
					is_variadic = true												\
				};															\
				enum {arity = parameter_count};												\
																			\
				typedef R type(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA) Z_IF(parameter_count)(Z_COMMA) ...);			\
				typedef R return_type;													\
			};

#		endif

		Z_FOR_32_CALL_WITH_INDEX(Z_IMPLEMENTATION, Z_EMPTY)
#		undef Z_IMPLEMENTATION

#	endif

#	undef Z_PARTIAL__NOEXCEPT
#	undef Z_PARTIAL__COMMON_CONVERSIONS
#	undef Z_PARTIAL__REFERENCE_CONVERSIONS

	enum {	Enumeration,
		Structure,
		Union,
		ObjectiveCInstance
	};

	template <zboolean E, zuint K, class T> struct Kind;

#	if Z_DECLARES_MEMBER(Type, is_enumeration)

		template <class T> struct Kind<false, Enumeration, T> : Simple {
			enum {	is_enumeration = true,
				is_scalar      = true
			};

#			if Z_DECLARES_MEMBER(Type, is_pod)
				enum {is_pod = true};
#			endif

			typedef T type;
		};

		template <class T> struct Kind<true, Enumeration, T> : Kind<false, Enumeration, T> {
#			if Z_DECLARES_MEMBER(Type, underlying_type)
				typedef Z_COMPILER_TRAIT(TYPE_UNDERLYING_TYPE)(T) underlying_type;
#			endif
		};

#	endif

	template <zboolean E, class T> struct Construct;

	template <class T> struct Construct<false, T> : Storable {
		enum {is_class = true};

		typedef T type;
	};

	template <class T> struct Construct<true, T> : Construct<false, T> {

#		if Z_DECLARES_MEMBER(Type, is_aggregate)
			enum {is_aggregate = Z_COMPILER_TRAIT(TYPE_IS_AGGREGATE)(T)};
#		endif

#		if Z_COMPILER_HAS_TRAIT(TYPE_IS_DEFAULT_CONSTRUCTIBLE)
			enum {is_default_constructible = Z_COMPILER_TRAIT(TYPE_IS_DEFAULT_CONSTRUCTIBLE)(T)};
#		elif Z_DECLARES_MEMBER(Type, is_default_constructible)
			enum {is_default_constructible = Helpers::IsDefaultConstructible<T, T>::value};
#		endif

#		if Z_DECLARES_MEMBER(Type, is_final)
			enum {is_final = Z_COMPILER_TRAIT(TYPE_IS_FINAL)(T)};
#		endif

#		if Z_DECLARES_MEMBER(Type, is_literal)
			enum {is_literal = Z_COMPILER_TRAIT(TYPE_IS_LITERAL)(T)};
#		endif

#		if Z_DECLARES_MEMBER(Type, is_pod)
			enum {is_pod = Z_COMPILER_TRAIT(TYPE_IS_POD)(T)};
#		endif

#		if Z_DECLARES_MEMBER(Type, is_trivially_copy_assignable)
			enum {is_trivially_copy_assignable = Z_COMPILER_TRAIT(TYPE_IS_TRIVIALLY_COPY_ASSIGNABLE)(T)};
#		endif

#		if Z_DECLARES_MEMBER(Type, is_trivially_copy_constructible)
			enum {is_trivially_copy_constructible = Z_COMPILER_TRAIT(TYPE_IS_TRIVIALLY_COPY_CONSTRUCTIBLE)(T)};
#		endif

#		if Z_DECLARES_MEMBER(Type, is_trivially_copyable)
			enum {is_trivially_copyable = Z_COMPILER_TRAIT(TYPE_IS_TRIVIALLY_COPYABLE)(T)};
#		endif

#		if Z_DECLARES_MEMBER(Type, is_trivially_default_constructible)
			enum {is_trivially_default_constructible = Z_COMPILER_TRAIT(TYPE_IS_TRIVIALLY_DEFAULT_CONSTRUCTIBLE)(T)};
#		endif

#		if Z_DECLARES_MEMBER(Type, is_trivially_destructible)
			enum {is_trivially_destructible = Z_COMPILER_TRAIT(TYPE_IS_TRIVIALLY_DESTRUCTIBLE)(T)};
#		endif
	};

	template <zboolean E, class T> struct MaybeTemplate : Construct<E, T> {};

#	if Z_DECLARES_MEMBER(Type, is_template)

		template <zboolean E, template <class...> class T, class... A> struct MaybeTemplate<E, T<A...> > : Construct<E, T<A...> > {
			enum {is_template = true};
			enum {arity = TypeCount<A...>::value};

			typedef TypeList<A...> parameters;

#			if Z_DECLARES_MEMBER(Type, parameter)
				template <zuint index> using parameter = typename TypeListGet<parameters, index>::type;
#			endif
		};

#	endif

	template <class T> class Kind<false, Structure, T> : public MaybeTemplate<false, T> {
		public:
		enum {is_structure = true};
	};

	template <class T> class Kind<true, Structure, T> : public MaybeTemplate<true, T> {
		public:
		enum {is_structure = true};

#		if Z_DECLARES_MEMBER(Type, has_virtual_destructor)
			enum {has_virtual_destructor = Z_COMPILER_TRAIT(TYPE_HAS_VIRTUAL_DESTRUCTOR)(T)};
#		endif

#		if Z_DECLARES_MEMBER(Type, is_abstract)
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

#		if Z_DECLARES_MEMBER(Type, is_interface_class)
			enum {is_interface_class = Z_COMPILER_TRAIT(TYPE_IS_INTERFACE_CLASS)(T)};
#		endif

#		if Z_DECLARES_MEMBER(Type, is_polymorphic)
			enum {is_polymorphic = Z_COMPILER_TRAIT(TYPE_IS_POLYMORPHIC)(T)};
#		endif
	};

#	if Z_DECLARES_MEMBER(Type, is_union)

		template <zboolean E, class T> struct Kind<E, Union, T> : MaybeTemplate<E, T> {
			enum {	is_statically_allocatable = true,
				is_union		  = true
			};
		};

#	endif

#	if Z_LANGUAGE_INCLUDES(OBJECTIVE_CPP)

		struct ObjectiveCObject : Storable {
			enum {is_objective_c_object = true};

			typedef typename TypeRemovePointer<id>::type type;
		};

		struct ObjectiveCClass : ObjectiveCObject {
			enum {is_objective_c_class = true};

			typedef typename TypeRemovePointer<Class>::type type;
		};

#		if Z_DECLARES_MEMBER(Type, is_objective_c_instance)

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

	enum {	NonNumber,
		Number
	};

	template <zuint K, class C> struct Const;
	template <zuint K, class C> struct ConstVolatile;
	template <zuint K, class C> struct Volatile;

	template <class C> struct Const<NonNumber, C> : Qualified<C> {
		enum {	is_const  = true,
			iss_const = true
		};

		typedef typename C::to_const	      type;
		typedef typename C::to_const_volatile add_volatile;
		typedef typename C::to_const	      remove_volatile;
	};

	template <class C> struct Const<Number, C> : Const<NonNumber, C> {
		typedef const typename C::to_signed   to_signed;
		typedef const typename C::to_unsigned to_unsigned;
	};

	template <class C> struct Volatile<NonNumber, C> : Qualified<C> {
		enum {	is_volatile  = true,
			iss_volatile = true
		};

		typedef typename C::to_volatile	      type;
		typedef typename C::to_const_volatile add_const;
		typedef typename C::to_volatile	      remove_const;
	};

	template <class C> struct Volatile<Number, C> : Volatile<NonNumber, C> {
		typedef volatile typename C::to_signed	 to_signed;
		typedef volatile typename C::to_unsigned to_unsigned;
	};

	template <class C> struct ConstVolatile<NonNumber, C> : Qualified<C> {
		enum {	is_const	   = true,
			is_const_volatile  = true,
			is_volatile	   = true,
			iss_const_volatile = true
		};

		typedef typename C::to_const_volatile type;
		typedef typename C::to_const_volatile add_const;
		typedef typename C::to_const_volatile add_volatile;
		typedef typename C::to_volatile	      remove_const;
		typedef typename C::to_const	      remove_volatile;
	};

	template <class C> struct ConstVolatile<Number, C> : ConstVolatile<NonNumber, C> {
		typedef const volatile typename C::to_signed   to_signed;
		typedef const volatile typename C::to_unsigned to_unsigned;
	};

	// MARK: - Mixins: Qualifiers (array)

	template <class C> struct ConstArray : Const<NonNumber, Unqualified<C> > {
		typedef const typename C::element_type element_type;
	};

	template <class C> struct VolatileArray : Volatile<NonNumber, Unqualified<C> > {
		typedef volatile typename C::element_type element_type;
	};

	template <class C> struct ConstVolatileArray : ConstVolatile<NonNumber, Unqualified<C> > {
		typedef const volatile typename C::element_type element_type;
	};

	// MARK: - Mixins: Qualifiers (function)

	template <class C> struct UnqualifiedFunction : C {
		typedef typename C::to_unqualified    type;
		typedef typename C::to_const	      add_const;
		typedef typename C::to_const_volatile add_const_volatile;
		typedef typename C::to_volatile	      add_volatile;
		typedef typename C::to_unqualified    remove_const;
		typedef typename C::to_unqualified    remove_const_this;
		typedef typename C::to_unqualified    remove_const_volatile;
		typedef typename C::to_unqualified    remove_const_volatile_this;
		typedef typename C::to_unqualified    remove_this;
		typedef typename C::to_unqualified    remove_volatile;
		typedef typename C::to_unqualified    remove_volatile_this;

#		if Z_DIALECT_HAS(CPP, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)
			typedef typename C::to_const_lvalue	     add_const_lvalue;
			typedef typename C::to_const_rvalue	     add_const_rvalue;
			typedef typename C::to_const_volatile_lvalue add_const_volatile_lvalue;
			typedef typename C::to_const_volatile_rvalue add_const_volatile_rvalue;
			typedef typename C::to_lvalue		     add_lvalue;
			typedef typename C::to_rvalue		     add_rvalue;
			typedef typename C::to_volatile_lvalue	     add_volatile_lvalue;
			typedef typename C::to_volatile_rvalue	     add_volatile_rvalue;
#		endif

#		if Z_DIALECT_HAS(CPP, NOEXCEPT_AS_PART_OF_THE_FUNCTION_TYPE)
			typedef typename Abstract::Function<true,  typename C::type>::to_unqualified add_noexcept;
			typedef typename Abstract::Function<false, typename C::type>::to_unqualified remove_noexcept;
#		endif
	};

	template <class C> struct QualifiedFunction : UnqualifiedFunction<C> {
		enum {is_qualified = true};
	};

	template <class C> struct ConstFunction : QualifiedFunction<C> {
		enum {	is_const  = true,
			iss_const = true
		};

		typedef typename C::to_const	      type;
		typedef typename C::to_const_volatile add_volatile;
		typedef typename C::to_const	      remove_this;
		typedef typename C::to_const	      remove_volatile;
		typedef typename C::to_const	      remove_volatile_this;

#		if Z_DIALECT_HAS(CPP, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)
			typedef typename C::to_const_lvalue	     add_lvalue;
			typedef typename C::to_const_rvalue	     add_rvalue;
			typedef typename C::to_const_volatile_lvalue add_volatile_lvalue;
			typedef typename C::to_const_volatile_rvalue add_volatile_rvalue;
#		endif

#		if Z_DIALECT_HAS(CPP, NOEXCEPT_AS_PART_OF_THE_FUNCTION_TYPE)
			typedef typename Abstract::Function<true,  typename C::type>::to_const add_noexcept;
			typedef typename Abstract::Function<false, typename C::type>::to_const remove_noexcept;
#		endif
	};

	template <class C> struct VolatileFunction : QualifiedFunction<C> {
		enum {	is_volatile  = true,
			iss_volatile = true
		};

		typedef typename C::to_volatile	      type;
		typedef typename C::to_const_volatile add_const;
		typedef typename C::to_volatile	      remove_const;
		typedef typename C::to_volatile	      remove_const_this;
		typedef typename C::to_volatile	      remove_this;

#		if Z_DIALECT_HAS(CPP, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)
			typedef typename C::to_const_volatile_lvalue add_const_lvalue;
			typedef typename C::to_const_volatile_rvalue add_const_rvalue;
			typedef typename C::to_volatile_lvalue	     add_lvalue;
			typedef typename C::to_volatile_rvalue	     add_rvalue;
#		endif

#		if Z_DIALECT_HAS(CPP, NOEXCEPT_AS_PART_OF_THE_FUNCTION_TYPE)
			typedef typename Abstract::Function<true,  typename C::type>::to_volatile add_noexcept;
			typedef typename Abstract::Function<false, typename C::type>::to_volatile remove_noexcept;
#		endif
	};

	template <class C> struct ConstVolatileFunction : QualifiedFunction<C> {
		enum {	is_const	   = true,
			is_const_volatile  = true,
			is_volatile	   = true,
			iss_const_volatile = true
		};

		typedef typename C::to_const_volatile type;
		typedef typename C::to_const_volatile add_const;
		typedef typename C::to_const_volatile add_volatile;
		typedef typename C::to_volatile	      remove_const;
		typedef typename C::to_volatile	      remove_const_this;
		typedef typename C::to_const_volatile remove_this;
		typedef typename C::to_const	      remove_volatile;
		typedef typename C::to_const	      remove_volatile_this;

#		if Z_DIALECT_HAS(CPP, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)
			typedef typename C::to_const_volatile_lvalue add_const_lvalue;
			typedef typename C::to_const_volatile_rvalue add_const_rvalue;
			typedef typename C::to_const_volatile_lvalue add_lvalue;
			typedef typename C::to_const_volatile_rvalue add_rvalue;
			typedef typename C::to_const_volatile_lvalue add_volatile_lvalue;
			typedef typename C::to_const_volatile_rvalue add_volatile_rvalue;
#		endif

#		if Z_DIALECT_HAS(CPP, NOEXCEPT_AS_PART_OF_THE_FUNCTION_TYPE)
			typedef typename Abstract::Function<true,  typename C::type>::to_const_volatile add_noexcept;
			typedef typename Abstract::Function<false, typename C::type>::to_const_volatile remove_noexcept;
#		endif
	};

#	if Z_DIALECT_HAS(CPP, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)

		template <class C> struct LValueFunction : QualifiedFunction<C> {
			enum {	is_lvalue  = true,
				iss_lvalue = true
			};

			typedef typename C::to_lvalue		     type;
			typedef typename C::to_const_lvalue	     add_const;
			typedef typename C::to_const_lvalue	     add_const_rvalue;
			typedef typename C::to_const_volatile_lvalue add_const_volatile;
			typedef typename C::to_const_volatile_lvalue add_const_volatile_rvalue;
			typedef typename C::to_lvalue		     add_rvalue;
			typedef typename C::to_volatile_lvalue	     add_volatile;
			typedef typename C::to_volatile_lvalue	     add_volatile_rvalue;
			typedef typename C::to_lvalue		     remove_const;
			typedef typename C::to_lvalue		     remove_const_volatile;
			typedef typename C::to_lvalue		     remove_volatile;

#			if Z_DIALECT_HAS(CPP, NOEXCEPT_AS_PART_OF_THE_FUNCTION_TYPE)
				typedef typename Abstract::Function<true,  typename C::type>::to_lvalue add_noexcept;
				typedef typename Abstract::Function<false, typename C::type>::to_lvalue remove_noexcept;
#			endif
		};

		template <class C> struct RValueFunction : QualifiedFunction<C> {
			enum {	is_rvalue  = true,
				iss_rvalue = true
			};

			typedef typename C::to_rvalue		     type;
			typedef typename C::to_const_rvalue	     add_const;
			typedef typename C::to_const_volatile_rvalue add_const_volatile;
			typedef typename C::to_volatile_rvalue	     add_volatile;
			typedef typename C::to_rvalue		     remove_const;
			typedef typename C::to_rvalue		     remove_const_volatile;
			typedef typename C::to_rvalue		     remove_volatile;

#			if Z_DIALECT_HAS(CPP, NOEXCEPT_AS_PART_OF_THE_FUNCTION_TYPE)
				typedef typename Abstract::Function<true,  typename C::type>::to_rvalue add_noexcept;
				typedef typename Abstract::Function<false, typename C::type>::to_rvalue remove_noexcept;
#			endif
		};

		template <class C> struct ConstLValueFunction : QualifiedFunction<C> {
			enum {	is_const	 = true,
				is_const_lvalue  = true,
				is_lvalue	 = true,
				iss_const_lvalue = true
			};

			typedef typename C::to_const_lvalue	     type;
			typedef typename C::to_const_lvalue	     add_const;
			typedef typename C::to_const_lvalue	     add_const_rvalue;
			typedef typename C::to_const_volatile_lvalue add_const_volatile;
			typedef typename C::to_const_volatile_lvalue add_const_volatile_rvalue;
			typedef typename C::to_const_lvalue	     add_lvalue;
			typedef typename C::to_const_lvalue	     add_rvalue;
			typedef typename C::to_const_volatile_lvalue add_volatile;
			typedef typename C::to_const_volatile_lvalue add_volatile_lvalue;
			typedef typename C::to_const_volatile_lvalue add_volatile_rvalue;
			typedef typename C::to_lvalue		     remove_const;
			typedef typename C::to_lvalue		     remove_const_volatile;
			typedef typename C::to_const		     remove_this;
			typedef typename C::to_const_lvalue	     remove_volatile;
			typedef typename C::to_const		     remove_volatile_this;

#			if Z_DIALECT_HAS(CPP, NOEXCEPT_AS_PART_OF_THE_FUNCTION_TYPE)
				typedef typename Abstract::Function<true,  typename C::type>::to_const_lvalue add_noexcept;
				typedef typename Abstract::Function<false, typename C::type>::to_const_lvalue remove_noexcept;
#			endif
		};

		template <class C> struct ConstRValueFunction : QualifiedFunction<C> {
			enum {	is_const	 = true,
				is_const_rvalue  = true,
				is_rvalue	 = true,
				iss_const_rvalue = true
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

#			if Z_DIALECT_HAS(CPP, NOEXCEPT_AS_PART_OF_THE_FUNCTION_TYPE)
				typedef typename Abstract::Function<true,  typename C::type>::to_const_rvalue add_noexcept;
				typedef typename Abstract::Function<false, typename C::type>::to_const_rvalue remove_noexcept;
#			endif
		};

		template <class C> struct VolatileLValueFunction : QualifiedFunction<C> {
			enum {	is_lvalue	    = true,
				is_volatile	    = true,
				is_volatile_lvalue  = true,
				iss_volatile_lvalue = true
			};

			typedef typename C::to_volatile_lvalue	     type;
			typedef typename C::to_const_volatile_lvalue add_const;
			typedef typename C::to_const_volatile_lvalue add_const_lvalue;
			typedef typename C::to_const_volatile_lvalue add_const_rvalue;
			typedef typename C::to_const_volatile_lvalue add_const_volatile;
			typedef typename C::to_const_volatile_lvalue add_const_volatile_vralue;
			typedef typename C::to_volatile_lvalue	     add_lvalue;
			typedef typename C::to_volatile_lvalue	     add_rvalue;
			typedef typename C::to_volatile_lvalue	     add_volatile;
			typedef typename C::to_volatile_lvalue	     add_volatile_rvalue;
			typedef typename C::to_volatile_lvalue	     remove_const;
			typedef typename C::to_volatile		     remove_const_this;
			typedef typename C::to_lvalue		     remove_const_volatile;
			typedef typename C::to_volatile		     remove_this;
			typedef typename C::to_lvalue		     remove_volatile;

#			if Z_DIALECT_HAS(CPP, NOEXCEPT_AS_PART_OF_THE_FUNCTION_TYPE)
				typedef typename Abstract::Function<true,  typename C::type>::to_volatile_lvalue add_noexcept;
				typedef typename Abstract::Function<false, typename C::type>::to_volatile_lvalue remove_noexcept;
#			endif
		};

		template <class C> struct VolatileRValueFunction : QualifiedFunction<C> {
			enum {	is_rvalue	    = true,
				is_volatile	    = true,
				is_volatile_rvalue  = true,
				iss_volatile_rvalue = true
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

#			if Z_DIALECT_HAS(CPP, NOEXCEPT_AS_PART_OF_THE_FUNCTION_TYPE)
				typedef typename Abstract::Function<true,  typename C::type>::to_volatile_rvalue add_noexcept;
				typedef typename Abstract::Function<false, typename C::type>::to_volatile_rvalue remove_noexcept;
#			endif
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
			typedef typename C::to_const_volatile_lvalue add_const_rvalue;
			typedef typename C::to_const_volatile_lvalue add_const_volatile;
			typedef typename C::to_const_volatile_lvalue add_const_volatile_rvalue;
			typedef typename C::to_const_volatile_lvalue add_lvalue;
			typedef typename C::to_const_volatile_lvalue add_rvalue;
			typedef typename C::to_const_volatile_lvalue add_volatile;
			typedef typename C::to_const_volatile_lvalue add_volatile_lvalue;
			typedef typename C::to_const_volatile_lvalue add_volatile_rvalue;
			typedef typename C::to_volatile_lvalue	     remove_const;
			typedef typename C::to_volatile		     remove_const_this;
			typedef typename C::to_lvalue		     remove_const_volatile;
			typedef typename C::to_const_volatile	     remove_this;
			typedef typename C::to_const_lvalue	     remove_volatile;
			typedef typename C::to_const		     remove_volatile_this;

#			if Z_DIALECT_HAS(CPP, NOEXCEPT_AS_PART_OF_THE_FUNCTION_TYPE)
				typedef typename Abstract::Function<true,  typename C::type>::to_const_volatile_lvalue add_noexcept;
				typedef typename Abstract::Function<false, typename C::type>::to_const_volatile_lvalue remove_noexcept;
#			endif
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

#			if Z_DIALECT_HAS(CPP, NOEXCEPT_AS_PART_OF_THE_FUNCTION_TYPE)
				typedef typename Abstract::Function<true,  typename C::type>::to_const_volatile_rvalue add_noexcept;
				typedef typename Abstract::Function<false, typename C::type>::to_const_volatile_rvalue remove_noexcept;
#			endif
		};

#	endif

	// MARK: - Mixins: Kind

	template <class C> struct StaticallyAllocatable : C {
		enum {can_form_reference = true};

		typedef typename C::type& add_lvalue_reference;

#		if Z_DIALECT_HAS(CPP, RVALUE_REFERENCE)
			typedef typename C::type&& add_rvalue_reference;
#		endif

		Z_DEFINE_PACKED_STRUCTURE({typename C::type value;},      to_wrap  );
		Z_DEFINE_PACKED_STRUCTURE({UInt8 data[sizeof(to_wrap)];}, to_opaque);
	};

	enum {	Void,
		NonReferenceableFunction,
		ReferenceableFunction,
		NonStaticallyAllocatableValue,
		StaticallyAllocatableValue,
		VoidPointer,
		Pointer,
		FunctionPointer,
		Reference,
		FunctionReference,
		DataMemberPointer,
		NonConvertibleMemberFunctionPointer,
		ConvertibleMemberFunctionPointer
	};

	template <zuint K, class C> struct Kind;

	// MARK: - Mixins: Kind (non-storable)

	template <class C> struct Kind<Void, C> : C {
		enum {	can_decorate_pointer = true,
			can_form_pointer     = true
		};

		typedef typename C::type* add_pointer;
		typedef typename C::type  remove_indirection;
		typedef typename C::type  remove_member_pointer;
		typedef typename C::type  remove_pointer;
		typedef typename C::type  remove_reference;
		typedef typename C::type* to_pointer;
	};

	template <class C> struct Kind<NonReferenceableFunction, C> : C {
		enum {	can_decorate_function	    = true,
			can_decorate_member_pointer = true,
			can_form_member_pointer	    = true
		};

		typedef typename C::type remove_indirection;
		typedef typename C::type remove_member_pointer;
		typedef typename C::type remove_pointer;
		typedef typename C::type remove_reference;
		typedef typename C::type to_function;
	};

	template <class C> struct Kind<ReferenceableFunction, C> : Kind<NonReferenceableFunction, C> {
		enum {	can_decorate_pointer   = true,
			can_decorate_reference = true,
			can_form_pointer       = true,
			can_form_reference     = true
		};

		typedef typename C::type& add_lvalue_reference;
		typedef typename C::type* add_pointer;
		typedef typename C::type& to_lvalue_reference;
		typedef typename C::type* to_pointer;

#		if Z_DIALECT_HAS(CPP, RVALUE_REFERENCE)
			typedef typename C::type&& add_rvalue_reference;
			typedef typename C::type&& to_rvalue_reference;
#		endif
	};

	// MARK: - Mixins: Kind (storable)

	template <class C> struct Value : C {
		enum {	can_decorate_member_pointer = true,
			can_decorate_pointer	    = true,
			can_decorate_reference	    = true,
			can_form_member_pointer	    = true,
			can_form_pointer	    = true
		};

		typedef typename C::type* add_pointer;
		typedef typename C::type  remove_indirection;
		typedef typename C::type  remove_member_pointer;
		typedef typename C::type  remove_pointer;
		typedef typename C::type  remove_reference;
		typedef typename C::type& to_lvalue_reference;
		typedef typename C::type* to_pointer;

#		if Z_DIALECT_HAS(CPP, RVALUE_REFERENCE)
			typedef typename C::type&& to_rvalue_reference;
#		endif
	};

	template <class C> struct Kind<NonStaticallyAllocatableValue, C> : Value<C> {
		enum {can_form_reference = true};

		typedef typename C::type& add_lvalue_reference;

#		if Z_DIALECT_HAS(CPP, RVALUE_REFERENCE)
			typedef typename C::type&& add_rvalue_reference;
#		endif
	};

	template <class C> struct Kind<StaticallyAllocatableValue, C> : StaticallyAllocatable<Value<C> > {};

	template <class C> struct Kind<VoidPointer, C> : StaticallyAllocatable<C> {
		enum {	can_decorate_pointer	= true,
			can_form_member_pointer = true,
			can_form_pointer	= true
		};

		typedef typename C::type*	  add_pointer;
		typedef typename C::pointee_type  remove_indirection;
		typedef typename C::type	  remove_member_pointer;
		typedef typename C::pointee_type  remove_pointer;
		typedef typename C::type	  remove_reference;
		typedef typename C::pointee_type* to_pointer;
	};

	template <class C> struct Kind<Pointer, C> : Kind<VoidPointer, C> {
		enum {	can_decorate_member_pointer = true,
			can_decorate_reference	    = true
		};

		typedef typename C::pointee_type& to_lvalue_reference;

#		if Z_DIALECT_HAS(CPP, RVALUE_REFERENCE)
			typedef typename C::pointee_type&& to_rvalue_reference;
#		endif
	};

	template <class C> struct Kind<FunctionPointer, C> : Kind<Pointer, C> {
		enum {can_decorate_function = true};

		typedef typename C::pointee_type to_function;
	};

	template <class C> struct Kind<Reference, C> : StaticallyAllocatable<C> {
		enum {	can_decorate_member_pointer = true,
			can_decorate_pointer	    = true,
			can_decorate_reference	    = true
		};

		typedef NaT			     add_const;
		typedef NaT			     add_const_volatile;
		typedef NaT			     add_volatile;
		typedef typename C::referencee_type  remove_indirection;
		typedef typename C::type	     remove_member_pointer;
		typedef typename C::type	     remove_pointer;
		typedef typename C::referencee_type  remove_reference;
		typedef NaT			     to_const;
		typedef NaT			     to_const_volatile;
		typedef typename C::referencee_type& to_lvalue_reference;
		typedef typename C::referencee_type* to_pointer;
		typedef NaT			     to_volatile;

#		if Z_DIALECT_HAS(CPP, RVALUE_REFERENCE)
			typedef typename C::referencee_type&& to_rvalue_reference;
#		endif
	};

	template <class C> struct Kind<FunctionReference, C> : Kind<Reference, C> {
		enum {can_decorate_function = true};

		typedef typename C::referencee_type to_function;
	};

	template <class C> struct MemberPointer : StaticallyAllocatable<C> {
		enum {	can_decorate_member_pointer = true,
			can_form_member_pointer	    = true,
			can_form_pointer	    = true
		};

		typedef typename C::type*	 add_pointer;
		typedef typename C::pointee_type remove_indirection;
		typedef typename C::pointee_type remove_member_pointer;
		typedef typename C::type	 remove_pointer;
		typedef typename C::type	 remove_reference;
	};

	template <class C> struct Kind<DataMemberPointer, C> : MemberPointer<C> {
		enum {	can_decorate_pointer   = true,
			can_decorate_reference = true
		};

		typedef typename C::pointee_type& to_lvalue_reference;
		typedef typename C::pointee_type* to_pointer;

#		if Z_DIALECT_HAS(CPP, RVALUE_REFERENCE)
			typedef typename C::pointee_type&& to_rvalue_reference;
#		endif
	};

	template <class C> struct Kind<NonConvertibleMemberFunctionPointer, C> : MemberPointer<C> {
		enum {can_decorate_function = true};

		typedef typename C::pointee_type to_function;
	};

	template <class C> struct Kind<ConvertibleMemberFunctionPointer, C> : Kind<NonConvertibleMemberFunctionPointer, C> {
		enum {	can_decorate_pointer   = true,
			can_decorate_reference = true
		};

		typedef typename C::pointee_type& to_lvalue_reference;
		typedef typename C::pointee_type* to_pointer;

#		if Z_DIALECT_HAS(CPP, RVALUE_REFERENCE)
			typedef typename C::pointee_type&& to_rvalue_reference;
#		endif
	};
}}}}

namespace Zeta {namespace Detail {namespace Type {

	// MARK: - Specializations: Enumeration, structure, union and Objective-C instance types

	template <class T> struct Ambiguous {

		enum {	structure_detected =
#			if Z_COMPILER_HAS_TRAIT(TYPE_IS_STRUCTURE)
				Z_COMPILER_TRAIT(TYPE_IS_STRUCTURE)(T)
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

		enum {	class_detected = structure_detected || union_detected ||
#			if Z_DIALECT_HAS(CPP, EXPRESSION_SFINAE)
				Helpers::IsConstruct<T, true>::value
#			else
				false
#			endif
		};

		enum {	enumeration_detected =
#			if Z_COMPILER_HAS_TRAIT(TYPE_IS_ENUMERATION)
				Z_COMPILER_TRAIT(TYPE_IS_ENUMERATION)(T)
#			elif Z_DIALECT_HAS(CPP, EXPRESSION_SFINAE)
				!class_detected && Helpers::IsUsableToCastNumber<T, true>::value
#			else
				false
#			endif
		};

		enum {	objective_c_instance_detected =
			Z_LANGUAGE_INCLUDES(OBJECTIVE_C)      &&
			Z_DIALECT_HAS(CPP, EXPRESSION_SFINAE) &&
			!enumeration_detected		      &&
			!class_detected
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

	// MARK: - Specializations: Standard C/C++ fundamental types

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

#	ifdef Z_ULLONG
		template <Boolean E> struct Case<E, ULLong> : Mixins::Unqualified<Abstract::ULLong> {};
#	endif

#	ifdef Z_SLLONG
		template <Boolean E> struct Case<E, SLLong> : Mixins::Unqualified<Abstract::SLLong> {};
#	endif

#	if Z_DIALECT_HAS_TYPE(CPP, BOOL) || Z_DIALECT_HAS_TYPE(C, BOOL)
		template <Boolean E> struct Case<E, Boolean> : Mixins::Unqualified<Abstract::Boolean> {};
#	endif

#	if Z_DIALECT_HAS_TYPE(CPP, WCHAR_T)
		template <Boolean E> struct Case<E, WChar> : Mixins::Unqualified<Abstract::WChar> {};
#	endif

/*#	if Z_DIALECT_HAS_TYPE(CPP, CHAR8_T)
		template <Boolean E> struct Case<E, Char8> : Mixins::Unqualified<Abstract::Char8> {};
#	endif*/

#	if Z_DIALECT_HAS_TYPE(CPP, CHAR16_T)
		template <Boolean E> struct Case<E, Char16> : Mixins::Unqualified<Abstract::Char16> {};
#	endif

#	if Z_DIALECT_HAS_TYPE(CPP, CHAR32_T)
		template <Boolean E> struct Case<E, Char32> : Mixins::Unqualified<Abstract::Char32> {};
#	endif

#	ifdef Z_FLOAT
		template <Boolean E> struct Case<E, Float> : Mixins::Unqualified<Abstract::Float> {};
#	endif

#	ifdef Z_DOUBLE
		template <Boolean E> struct Case<E, Double> : Mixins::Unqualified<Abstract::Double> {};
#	endif

#	ifdef Z_LDOUBLE
		template <Boolean E> struct Case<E, LDouble> : Mixins::Unqualified<Abstract::LDouble> {};
#	endif

/*#	ifdef Z_FLOAT16
		template <Boolean E> struct Case<E, Float16> : Mixins::Unqualified<Abstract::Float16> {};
#	endif

#	ifdef Z_FLOAT32
		template <Boolean E> struct Case<E, Float32> : Mixins::Unqualified<Abstract::Float32> {};
#	endif

#	ifdef Z_FLOAT64
		template <Boolean E> struct Case<E, Float64> : Mixins::Unqualified<Abstract::Float64> {};
#	endif

#	ifdef Z_FLOAT128
		template <Boolean E> struct Case<E, Float128> : Mixins::Unqualified<Abstract::Float128> {};
#	endif

#	ifdef Z_FLOAT32X
		template <Boolean E> struct Case<E, Float32x> : Mixins::Unqualified<Abstract::Float32x> {};
#	endif

#	ifdef Z_FLOAT64X
		template <Boolean E> struct Case<E, Float64x> : Mixins::Unqualified<Abstract::Float64x> {};
#	endif

#	ifdef Z_FLOAT128X
		template <Boolean E> struct Case<E, Float128x> : Mixins::Unqualified<Abstract::Float128x> {};
#	endif

#	ifdef Z_DECIMAL32
		template <Boolean E> struct Case<E, Decimal32> : Mixins::Unqualified<Abstract::Decimal32> {};
#	endif

#	ifdef Z_DECIMAL64
		template <Boolean E> struct Case<E, Decimal64> : Mixins::Unqualified<Abstract::Decimal64> {};
#	endif

#	ifdef Z_DECIMAL128
		template <Boolean E> struct Case<E, Decimal128> : Mixins::Unqualified<Abstract::Decimal128> {};
#	endif

#	ifdef Z_DECIMAL64X
		template <Boolean E> struct Case<E, Decimal64x> : Mixins::Unqualified<Abstract::Decimal64x> {};
#	endif

#	ifdef Z_DECIMAL128X
		template <Boolean E> struct Case<E, Decimal128x> : Mixins::Unqualified<Abstract::Decimal128x> {};
#	endif*/

#	if Z_DECLARES_MEMBER(Type, is_nullptr)
		template <Boolean E> struct Case<E, NullPtr> : Mixins::Unqualified<Abstract::NullPtr> {};
#	endif

	// MARK: - Specializations: Fixed width integral types

#	if defined(Z_UINT8) && Z_UINT8_FUNDAMENTAL == Z_FUNDAMENTAL_UINT8
		template <Boolean E> struct Case<E, UInt8> : Mixins::Unqualified<Abstract::UInt8> {};
#	endif

#	if defined(Z_SINT8) && Z_SINT8_FUNDAMENTAL == Z_FUNDAMENTAL_SINT8
		template <Boolean E> struct Case<E, SInt8> : Mixins::Unqualified<Abstract::SInt8> {};
#	endif

#	if defined(Z_UINT16) && Z_UINT16_FUNDAMENTAL == Z_FUNDAMENTAL_UINT16
		template <Boolean E> struct Case<E, UInt16> : Mixins::Unqualified<Abstract::UInt16> {};
#	endif

#	if defined(Z_SINT16) && Z_SINT16_FUNDAMENTAL == Z_FUNDAMENTAL_SINT16
		template <Boolean E> struct Case<E, SInt16> : Mixins::Unqualified<Abstract::SInt16> {};
#	endif

#	if defined(Z_UINT24) && Z_UINT24_FUNDAMENTAL == Z_FUNDAMENTAL_UINT24
		template <Boolean E> struct Case<E, UInt24> : Mixins::Unqualified<Abstract::UInt24> {};
#	endif

#	if defined(Z_SINT24) && Z_SINT24_FUNDAMENTAL == Z_FUNDAMENTAL_SINT24
		template <Boolean E> struct Case<E, SInt24> : Mixins::Unqualified<Abstract::SInt24> {};
#	endif

#	if defined(Z_UINT32) && Z_UINT32_FUNDAMENTAL == Z_FUNDAMENTAL_UINT32
		template <Boolean E> struct Case<E, UInt32> : Mixins::Unqualified<Abstract::UInt32> {};
#	endif

#	if defined(Z_SINT32) && Z_SINT32_FUNDAMENTAL == Z_FUNDAMENTAL_SINT32
		template <Boolean E> struct Case<E, SInt32> : Mixins::Unqualified<Abstract::SInt32> {};
#	endif

#	if defined(Z_UINT40) && Z_UINT40_FUNDAMENTAL == Z_FUNDAMENTAL_UINT40
		template <Boolean E> struct Case<E, UInt40> : Mixins::Unqualified<Abstract::UInt40> {};
#	endif

#	if defined(Z_SINT40) && Z_SINT40_FUNDAMENTAL == Z_FUNDAMENTAL_SINT40
		template <Boolean E> struct Case<E, SInt40> : Mixins::Unqualified<Abstract::SInt40> {};
#	endif

#	if defined(Z_UINT48) && Z_UINT48_FUNDAMENTAL == Z_FUNDAMENTAL_UINT48
		template <Boolean E> struct Case<E, UInt48> : Mixins::Unqualified<Abstract::UInt48> {};
#	endif

#	if defined(Z_SINT48) && Z_SINT48_FUNDAMENTAL == Z_FUNDAMENTAL_SINT48
		template <Boolean E> struct Case<E, SInt48> : Mixins::Unqualified<Abstract::SInt48> {};
#	endif

#	if defined(Z_UINT56) && Z_UINT56_FUNDAMENTAL == Z_FUNDAMENTAL_UINT56
		template <Boolean E> struct Case<E, UInt56> : Mixins::Unqualified<Abstract::UInt56> {};
#	endif

#	if defined(Z_SINT56) && Z_SINT56_FUNDAMENTAL == Z_FUNDAMENTAL_SINT56
		template <Boolean E> struct Case<E, SInt56> : Mixins::Unqualified<Abstract::SInt56> {};
#	endif

#	if defined(Z_UINT64) && Z_UINT64_FUNDAMENTAL == Z_FUNDAMENTAL_UINT64
		template <Boolean E> struct Case<E, UInt64> : Mixins::Unqualified<Abstract::UInt64> {};
#	endif

#	if defined(Z_SINT64) && Z_SINT64_FUNDAMENTAL == Z_FUNDAMENTAL_SINT64
		template <Boolean E> struct Case<E, SInt64> : Mixins::Unqualified<Abstract::SInt64> {};
#	endif

#	if defined(Z_UINT128) && Z_UINT128_FUNDAMENTAL == Z_FUNDAMENTAL_UINT128
		template <Boolean E> struct Case<E, UInt128> : Mixins::Unqualified<Abstract::UInt128> {};
#	endif

#	if defined(Z_SINT128) && Z_SINT128_FUNDAMENTAL == Z_FUNDAMENTAL_SINT128
		template <Boolean E> struct Case<E, SInt128> : Mixins::Unqualified<Abstract::SInt128> {};
#	endif

	// MARK: - Specializations: Fixed format real types

#	if defined(Z_BFP16) && Z_BFP16_FUNDAMENTAL == Z_FUNDAMENTAL_BFP16
		template <Boolean E> struct Case<E, BFP16> : Mixins::Unqualified<Abstract::BFP16> {};
#	endif

#	if defined(Z_BFP32) && Z_BFP32_FUNDAMENTAL == Z_FUNDAMENTAL_BFP32
		template <Boolean E> struct Case<E, BFP32> : Mixins::Unqualified<Abstract::BFP32> {};
#	endif

#	if defined(Z_BFP64) && Z_BFP64_FUNDAMENTAL == Z_FUNDAMENTAL_BFP64
		template <Boolean E> struct Case<E, BFP64> : Mixins::Unqualified<Abstract::BFP64> {};
#	endif

#	if defined(Z_BFP128) && Z_BFP128_FUNDAMENTAL == Z_FUNDAMENTAL_BFP128
		template <Boolean E> struct Case<E, BFP128> : Mixins::Unqualified<Abstract::BFP128> {};
#	endif

#	if defined(Z_DFP32) && Z_DFP32_FUNDAMENTAL == Z_FUNDAMENTAL_DFP32
		template <Boolean E> struct Case<E, DFP32> : Mixins::Unqualified<Abstract::DFP32> {};
#	endif

#	if defined(Z_DFP64) && Z_DFP64_FUNDAMENTAL == Z_FUNDAMENTAL_DFP64
		template <Boolean E> struct Case<E, DFP64> : Mixins::Unqualified<Abstract::DFP64> {};
#	endif

#	if defined(Z_DFP128) && Z_DFP128_FUNDAMENTAL == Z_FUNDAMENTAL_DFP128
		template <Boolean E> struct Case<E, DFP128> : Mixins::Unqualified<Abstract::DFP128> {};
#	endif

#	if defined(Z_X87_DE80) && Z_X87_DE80_FUNDAMENTAL == Z_FUNDAMENTAL_X87_DE80
		template <Boolean E> struct Case<E, x87_DE80> : Mixins::Unqualified<Abstract::x87_DE80> {};
#	endif

#	if defined(Z_X87_DE96) && Z_X87_DE96_FUNDAMENTAL == Z_FUNDAMENTAL_X87_DE96
		template <Boolean E> struct Case<E, x87_DE96> : Mixins::Unqualified<Abstract::x87_DE96> {};
#	endif

#	if defined(Z_X87_DE128) && Z_X87_DE128_FUNDAMENTAL == Z_FUNDAMENTAL_X87_DE128
		template <Boolean E> struct Case<E, x87_DE128> : Mixins::Unqualified<Abstract::x87_DE128> {};
#	endif

	// MARK: - Specializations: Array types

	template <Boolean E, class T, USize N> struct Case<E,		     T[N]> : Mixins::Unqualified       <Abstract::SizedArray<E, T, N> > {};
	template <Boolean E, class T, USize N> struct Case<E, const	     T[N]> : Mixins::ConstArray	       <Abstract::SizedArray<E, T, N> > {};
	template <Boolean E, class T, USize N> struct Case<E,	    volatile T[N]> : Mixins::VolatileArray     <Abstract::SizedArray<E, T, N> > {};
	template <Boolean E, class T, USize N> struct Case<E, const volatile T[N]> : Mixins::ConstVolatileArray<Abstract::SizedArray<E, T, N> > {};

	template <Boolean E, class T> struct Case<E,		    T[]> : Mixins::Unqualified	     <Abstract::UnsizedArray<E, T> > {};
	template <Boolean E, class T> struct Case<E, const	    T[]> : Mixins::ConstArray	     <Abstract::UnsizedArray<E, T> > {};
	template <Boolean E, class T> struct Case<E, 	   volatile T[]> : Mixins::VolatileArray     <Abstract::UnsizedArray<E, T> > {};
	template <Boolean E, class T> struct Case<E, const volatile T[]> : Mixins::ConstVolatileArray<Abstract::UnsizedArray<E, T> > {};

	// MARK: - Specializations: Pointer types

	template <Boolean E, class T> class Case<E, T*> : public Mixins::Unqualified<Abstract::Pointer<T> > {
		private:
		typedef Case<false, T> Pointee;

		public:
		enum {	has_qualified_indirectee = Pointee::is_qualified,
			is_function_pointer	 = Pointee::is_function,
			is_void_pointer		 = Pointee::is_void,
			is_data_pointer		 = !is_function_pointer
		};

#		if Z_LANGUAGE_INCLUDES(OBJECTIVE_CPP)

			enum {	is_objective_c_class_pointer  = Pointee::is_objective_c_class,
				is_objective_c_object_pointer = Pointee::is_objective_c_object,
			};

#			if Z_DECLARES_MEMBER(Type, is_objective_c_instance_pointer)
				enum {is_objective_c_instance_pointer = Pointee::is_objective_c_instance};
#			endif

#		endif

		enum {	indirection_level = Pointee::indirection_level + 1,
			pointer_level	  = Pointee::pointer_level     + 1
		};
	};

	template <Boolean E, class C, class T> class Case<E, T C::*> : public Mixins::Unqualified<Abstract::MemberPointer<T C::*, C, T> > {
		private:
		typedef Case<false, T> Pointee;

		public:
		enum {	has_qualified_indirectee   = Pointee::is_qualified,
			is_member_function_pointer = Pointee::is_function,
			is_data_member_pointer	   = !is_member_function_pointer,
		};

		enum {indirection_level = Pointee::indirection_level + 1};
	};

	// MARK: - Specializations: Reference types

	template <Boolean E, class T> class Case<E, T&> : public Mixins::Unqualified<Abstract::LValueReference<T> > {
		private:
		typedef Case<false, T> Referencee;

		public:
		enum {	has_qualified_indirectee     = Referencee::is_qualified,
			is_function_reference	     = Referencee::is_function,
			is_function_lvalue_reference = is_function_reference,
			is_data_reference	     = !is_function_reference,
			is_data_lvalue_reference     = is_data_reference
		};

		enum {indirection_level = Referencee::indirection_level + 1};
	};

#	if Z_DIALECT_HAS(CPP, RVALUE_REFERENCE)

		template <Boolean E, class T> class Case<E, T&&> : public Mixins::Unqualified<Abstract::RValueReference<T> > {
			private:
			typedef Case<false, T> Referencee;

			public:
			enum {	has_qualified_indirectee     = Referencee::is_qualified,
				is_function_reference	     = Referencee::is_function,
				is_function_rvalue_reference = is_function_reference,
				is_data_reference	     = !is_function_reference,
				is_data_rvalue_reference     = is_data_reference
			};

			enum {indirection_level = Referencee::indirection_level + 1};
		};

#	endif

	// MARK: - Specializations: Function types

#	define Z_IMPLEMENTATION__COMMON_GROUP(parameter_count)		 \
	Z_IMPLEMENTATION(parameter_count, Z_EMPTY,	  Unqualified  ) \
	Z_IMPLEMENTATION(parameter_count, const,	  Const	       ) \
	Z_IMPLEMENTATION(parameter_count, const volatile, ConstVolatile) \
	Z_IMPLEMENTATION(parameter_count,	volatile, Volatile     )

#	if Z_DIALECT_HAS(CPP, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)
#		define Z_IMPLEMENTATION__REFERENCE_GROUP(parameter_count)		  \
		Z_IMPLEMENTATION(parameter_count,		 & , LValue		) \
		Z_IMPLEMENTATION(parameter_count,		 &&, RValue		) \
		Z_IMPLEMENTATION(parameter_count, const		 & , ConstLValue	) \
		Z_IMPLEMENTATION(parameter_count, const		 &&, ConstRValue	) \
		Z_IMPLEMENTATION(parameter_count, const volatile & , ConstVolatileLValue) \
		Z_IMPLEMENTATION(parameter_count, const volatile &&, ConstVolatileRValue) \
		Z_IMPLEMENTATION(parameter_count,	volatile & , VolatileLValue	) \
		Z_IMPLEMENTATION(parameter_count,	volatile &&, VolatileRValue	)
#	else
#		define Z_IMPLEMENTATION__REFERENCE_SPECIALIZATIONS(parameter_count)
#	endif

#	if Z_DIALECT_HAS(CPP, VARIADIC_TEMPLATE)

#		if Z_DIALECT_HAS(CPP, NOEXCEPT_AS_PART_OF_THE_FUNCTION_TYPE)
#			define Z_IMPLEMENTATION(dummy, qualifiers, Qualifiers)																	\
			template <Boolean E, Boolean X, class R, class... P> struct Case<E, R(P...)	 qualifiers noexcept(X)> : Mixins::Qualifiers##Function<Abstract::NonVariadicFunction<X, R, P...> > {}; \
			template <Boolean E, Boolean X, class R, class... P> struct Case<E, R(P..., ...) qualifiers noexcept(X)> : Mixins::Qualifiers##Function<Abstract::VariadicFunction   <X, R, P...> > {};
#		else
#			define Z_IMPLEMENTATION(dummy, qualifiers, Qualifiers)													      \
			template <Boolean E, class R, class... P> struct Case<E, R(P...)      qualifiers> : Mixins::Qualifiers##Function<Abstract::NonVariadicFunction<R, P...> > {}; \
			template <Boolean E, class R, class... P> struct Case<E, R(P..., ...) qualifiers> : Mixins::Qualifiers##Function<Abstract::VariadicFunction   <R, P...> > {};
#		endif

		Z_IMPLEMENTATION__COMMON_GROUP	 (-)
		Z_IMPLEMENTATION__REFERENCE_GROUP(-)
#	else

#		if Z_DIALECT_HAS(CPP, NOEXCEPT_AS_PART_OF_THE_FUNCTION_TYPE)

#			define Z_IMPLEMENTATION(parameter_count, qualifiers, Qualifiers)															    \
																										    \
			template <Boolean E, Boolean X, class R Z_IF(parameter_count)(Z_COMMA) Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)>							    \
			struct Case<E, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA)) qualifiers noexcept(X)>												    \
			: Mixins::Qualifiers##Function<Abstract::NonVariadicFunctionWith##parameter_count##Parameters<X, R Z_IF(parameter_count)(Z_COMMA) Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA)> > {}; \
																										    \
			template <Boolean E, Boolean X, class R Z_IF(parameter_count)(Z_COMMA) Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)>							    \
			struct Case<E, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA) Z_IF(parameter_count)(Z_COMMA) ...) qualifiers noexcept(X)>								    \
			: Mixins::Qualifiers##Function<Abstract::VariadicFunctionWith##parameter_count##Parameters<X, R Z_IF(parameter_count)(Z_COMMA) Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA)> > {};

#		else

#			define Z_IMPLEMENTATION(parameter_count, qualifiers, Qualifiers)															 \
																										 \
			template <Boolean E, class R Z_IF(parameter_count)(Z_COMMA) Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)>									 \
			struct Case<E, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA)) qualifiers>													 \
			: Mixins::Qualifiers##Function<Abstract::NonVariadicFunctionWith##parameter_count##Parameters<R Z_IF(parameter_count)(Z_COMMA) Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA)> > {}; \
																										 \
			template <Boolean E, class R Z_IF(parameter_count)(Z_COMMA) Z_FOR_##parameter_count##_APPEND_INDEX(class P, Z_COMMA)>									 \
			struct Case<E, R(Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA) Z_IF(parameter_count)(Z_COMMA) ...) qualifiers>									 \
			: Mixins::Qualifiers##Function<Abstract::VariadicFunctionWith##parameter_count##Parameters<R Z_IF(parameter_count)(Z_COMMA) Z_FOR_##parameter_count##_APPEND_INDEX(P, Z_COMMA)> > {};

#		endif

		Z_FOR_32_CALL_WITH_INDEX(Z_IMPLEMENTATION__COMMON_GROUP,    Z_EMPTY)
		Z_FOR_32_CALL_WITH_INDEX(Z_IMPLEMENTATION__REFERENCE_GROUP, Z_EMPTY)
#	endif

#	undef Z_IMPLEMENTATION
#	undef Z_IMPLEMENTATION__COMMON_GROUP
#	undef Z_IMPLEMENTATION__REFERENCE_GROUP

	// MARK: - Specializations: Block object types (Apple extension)

#	if Z_COMPILER_C_HAS(BLOCK_OBJECT)

		template <Boolean E, class R, class... P> struct Case<E, R(^)(P...)> : Abstract::Valid {
			enum {is_block_object = true};
		};

#	endif

	// MARK: - Specializations: Objective-C types

#	if Z_LANGUAGE_INCLUDES(OBJECTIVE_CPP)
		template <Boolean E> struct Case<E, TypeRemovePointer<id   >::type> : Mixins::Unqualified<Abstract::ObjectiveCObject> {};
		template <Boolean E> struct Case<E, TypeRemovePointer<Class>::type> : Mixins::Unqualified<Abstract::ObjectiveCClass > {};
#	endif

	// MARK: - Specializations: Type qualifiers

	template <Boolean E, class T> struct Case<E, const	    T> : Mixins::Const	      <Case<false, T>::is_number, Case<E, T> > {};
	template <Boolean E, class T> struct Case<E, const volatile T> : Mixins::ConstVolatile<Case<false, T>::is_number, Case<E, T> > {};
	template <Boolean E, class T> struct Case<E, 	   volatile T> : Mixins::Volatile     <Case<false, T>::is_number, Case<E, T> > {};

	// MARK: - Detail build

	template <class T, class C = Case<true, T> > struct Build : Mixins::Kind<
		C::is_storable
			? (C::is_member_pointer
				? (C::is_member_function_pointer
					? (C::has_qualified_indirectee
						? Mixins::NonConvertibleMemberFunctionPointer
						: Mixins::ConvertibleMemberFunctionPointer)
					: Mixins::DataMemberPointer)
				: (C::is_pointer
					? (C::is_void_pointer
						? Mixins::VoidPointer
						: (C::is_function_pointer
							? Mixins::FunctionPointer
							: Mixins::Pointer))
					: (C::is_reference
						? (C::is_function_reference
							? Mixins::FunctionReference
							: Mixins::Reference)
						: (C::is_statically_allocatable
							? Mixins::StaticallyAllocatableValue
							: Mixins::NonStaticallyAllocatableValue))))
			: (C::is_void
				? Mixins::Void
				: (C::is_qualified
					? Mixins::NonReferenceableFunction
					: Mixins::ReferenceableFunction)),
	C> {
		enum {is_compound = !Build::is_fundamental};

		typedef typename TernaryType<Build::is_class,
			typename Build<const typename Build::remove_const_volatile>::add_lvalue_reference,
			T
		>::type to_forwardable;
	};

	template <> struct Build<		NaT> : Abstract::Invalid {};
	template <> struct Build<const		NaT> : Abstract::Invalid {};
	template <> struct Build<const volatile NaT> : Abstract::Invalid {};
	template <> struct Build<      volatile NaT> : Abstract::Invalid {};
}}}

namespace Zeta {

	template <class T> struct Type : Detail::Type::Build<T> {

#		if Z_DIALECT_HAS(CPP, TYPE_ALIAS_TEMPLATE)
			template <class klass> using add_member_pointer = typename TypeAddMemberPointer<T,				   klass>::type;
			template <class klass> using to_member_pointer	= typename TypeAddMemberPointer<typename Type::remove_indirection, klass>::type;
#		endif

#		if Z_COMPILER_HAS_MAGIC_CONSTANT(MANGLED_FUNCTION_NAME) && Z_DIALECT_HAS(CPP, CPP14_CONSTEXPR_FUNCTION)

#			define Z_IMPLEMENTATION__MEMBER_FUNCTIONS						       \
			static Z_CT(CPP14) USize		      string_size() {return type_string_size  <T>() ;} \
			static Z_CT(CPP14) SizedString<string_size()> string	 () {return type_string       <T>() ;} \
			static Z_CT(CPP14) Symbol		      symbol	 () {return Symbol(type_string<T>());}

			Z_IMPLEMENTATION__MEMBER_FUNCTIONS
#		else
#			define Z_IMPLEMENTATION__MEMBER_FUNCTIONS
#		endif

		typedef typename TernaryType<Type::is_valid, Type, NaT>::type if_valid;

		struct flow {
			enum {	can_decorate_function	      = Type::can_decorate_function,
				can_decorate_member_pointer   = Type::can_decorate_member_pointer,
				can_decorate_pointer	      = Type::can_decorate_pointer,
				can_decorate_reference	      = Type::can_decorate_reference,
				can_form_member_pointer	      = Type::can_form_member_pointer,
				can_form_pointer	      = Type::can_form_pointer,
				can_form_reference	      = Type::can_form_reference,
				has_qualified_indirectee      = Type::has_qualified_indirectee,
				is_arithmetic		      = Type::is_arithmetic,
				is_array		      = Type::is_array,
				is_block_object		      = Type::is_block_object,
				is_boolean		      = Type::is_boolean,
				is_class		      = Type::is_class,
				is_compound		      = Type::is_compound,
				is_const		      = Type::is_const,
				is_const_lvalue		      = Type::is_const_lvalue,
				is_const_rvalue		      = Type::is_const_rvalue,
				is_const_volatile	      = Type::is_const_volatile,
				is_const_volatile_lvalue      = Type::is_const_volatile_lvalue,
				is_const_volatile_rvalue      = Type::is_const_volatile_rvalue,
				is_data_lvalue_reference      = Type::is_data_lvalue_reference,
				is_data_member_pointer	      = Type::is_data_member_pointer,
				is_data_pointer		      = Type::is_data_pointer,
				is_data_reference	      = Type::is_data_reference,
				is_data_rvalue_reference      = Type::is_data_rvalue_reference,
				is_empty		      = Type::is_empty,
				is_exact		      = Type::is_exact,
				is_indirection		      = Type::is_indirection,
				is_integer		      = Type::is_integer,
				is_integral		      = Type::is_integral,
				is_floating_point	      = Type::is_floating_point,
				is_function		      = Type::is_function,
				is_function_lvalue_reference  = Type::is_function_lvalue_reference,
				is_function_pointer	      = Type::is_function_pointer,
				is_function_reference	      = Type::is_function_reference,
				is_function_rvalue_reference  = Type::is_function_rvalue_reference,
				is_fundamental		      = Type::is_fundamental,
				is_lvalue		      = Type::is_lvalue,
				is_lvalue_reference	      = Type::is_lvalue_reference,
				is_member_function_pointer    = Type::is_member_function_pointer,
				is_member_pointer	      = Type::is_member_pointer,
				is_nat			      = Type::is_nat,
				is_natural		      = Type::is_natural,
				is_number		      = Type::is_number,
				is_objective_c_class	      = Type::is_objective_c_class,
				is_objective_c_class_pointer  = Type::is_objective_c_class_pointer,
				is_objective_c_object	      = Type::is_objective_c_object,
				is_objective_c_object_pointer = Type::is_objective_c_object_pointer,
				is_pointer		      = Type::is_pointer,
				is_qualified		      = Type::is_qualified,
				is_real			      = Type::is_real,
				is_reference		      = Type::is_reference,
				is_rvalue		      = Type::is_rvalue,
				is_rvalue_reference	      = Type::is_rvalue_reference,
				is_scalar		      = Type::is_scalar,
				is_signed		      = Type::is_signed,
				is_simple		      = Type::is_simple,
				is_sized_array		      = Type::is_sized_array,
				is_statically_allocatable     = Type::is_statically_allocatable,
				is_storable		      = Type::is_storable,
				is_structure		      = Type::is_structure,
				is_unsigned		      = Type::is_unsigned,
				is_unsized_array	      = Type::is_unsized_array,
				is_valid		      = Type::is_valid,
				is_variadic		      = Type::is_variadic,
				is_variadic_function	      = Type::is_variadic_function,
				is_void			      = Type::is_void,
				is_void_pointer		      = Type::is_void_pointer,
				is_volatile		      = Type::is_volatile,
				is_volatile_lvalue	      = Type::is_volatile_lvalue,
				is_volatile_rvalue	      = Type::is_volatile_rvalue,
				iss_const		      = Type::iss_const,
				iss_const_lvalue	      = Type::iss_const_lvalue,
				iss_const_rvalue	      = Type::iss_const_rvalue,
				iss_const_volatile	      = Type::iss_const_volatile,
				iss_lvalue		      = Type::iss_lvalue,
				iss_rvalue		      = Type::iss_rvalue,
				iss_volatile		      = Type::iss_volatile,
				iss_volatile_lvalue	      = Type::iss_volatile_lvalue,
				iss_volatile_rvalue	      = Type::iss_volatile_rvalue
			};

			enum {	arity		  = Type::arity,
				dimension_count	  = Type::dimension_count,
				element_count	  = Type::element_count,
				indirection_level = Type::indirection_level,
				pointer_level	  = Type::pointer_level
			};

			enum {	fixed_fundamental = Type::fixed_fundamental,
				fundamental	  = Type::fundamental,
				number_format	  = Type::number_format,
				number_set	  = Type::number_set
			};

#			if Z_DECLARES_MEMBER(Type, has_virtual_destructor)
				enum {has_virtual_destructor = Type::has_virtual_destructor};
#			endif

#			if Z_DECLARES_MEMBER(Type, is_abstract)
				enum {is_abstract = Type::is_abstract};
#			endif

#			if Z_DECLARES_MEMBER(Type, is_aggregate)
				enum {is_aggregate = Type::is_aggregate};
#			endif

#			if Z_DECLARES_MEMBER(Type, is_default_constructible)
				enum {is_default_constructible = Type::is_default_constructible};
#			endif

#			if Z_DECLARES_MEMBER(Type, is_enumeration)
				enum {is_enumeration = Type::is_enumeration};
#			endif

#			if Z_DECLARES_MEMBER(Type, is_final)
				enum {is_final = Type::is_final};
#			endif

#			if Z_DECLARES_MEMBER(Type, is_interface_class)
				enum {is_interface_class = Type::is_interface_class};
#			endif

#			if Z_DECLARES_MEMBER(Type, is_literal)
				enum {is_literal = Type::is_literal};
#			endif

#			if Z_DECLARES_MEMBER(Type, is_noexcept)
				enum {is_noexcept = Type::is_noexcept};
#			endif

#			if Z_DECLARES_MEMBER(Type, is_nullptr)
				enum {is_nullptr = Type::is_nullptr};
#			endif

#			if Z_DECLARES_MEMBER(Type, is_pod)
				enum {is_pod = Type::is_pod};
#			endif

#			if Z_DECLARES_MEMBER(Type, is_polymorphic)
				enum {is_polymorphic = Type::is_polymorphic};
#			endif

#			if Z_DECLARES_MEMBER(Type, is_template)
				enum {is_template = Type::is_template};
#			endif

#			if Z_DECLARES_MEMBER(Type, is_trivially_copy_assignable)
				enum {is_trivially_copy_assignable = Type::is_trivially_copy_assignable};
#			endif

#			if Z_DECLARES_MEMBER(Type, is_trivially_copy_constructible)
				enum {is_trivially_copy_constructible = Type::is_trivially_copy_constructible};
#			endif

#			if Z_DECLARES_MEMBER(Type, is_trivially_copyable)
				enum {is_trivially_copyable = Type::is_trivially_copyable};
#			endif

#			if Z_DECLARES_MEMBER(Type, is_trivially_default_constructible)
				enum {is_trivially_default_constructible = Type::is_trivially_default_constructible};
#			endif

#			if Z_DECLARES_MEMBER(Type, is_trivially_destructible)
				enum {is_trivially_destructible = Type::is_trivially_destructible};
#			endif

#			if Z_DECLARES_MEMBER(Type, is_union)
				enum {is_union = Type::is_union};
#			endif

#			if Z_LANGUAGE_INCLUDES(OBJECTIVE_CPP) && Z_DIALECT_HAS(CPP, EXPRESSION_SFINAE)
				enum {	is_objective_c_instance		= Type::is_objective_c_instance,
					is_objective_c_instance_pointer = Type::is_objective_c_instance_pointer
				};
#			endif

			typedef Type end;

			typedef typename TernaryType<Type::is_valid, flow, NaT>::type if_valid;
/*
			enter_return_type
			enter_class_type
			enter_parameters
			enter_element_type
			enter_indirectee_type
			enter_referencee_type
			enter_pointee_type
*/
			typedef typename Type::type type;

			typedef typename Type<typename Type::add_const		       >::flow add_const;
			typedef typename Type<typename Type::add_const_volatile	       >::flow add_const_volatile;
			typedef typename Type<typename Type::add_lvalue_reference      >::flow add_lvalue_reference;
			typedef typename Type<typename Type::add_pointer	       >::flow add_pointer;
			typedef typename Type<typename Type::add_volatile	       >::flow add_volatile;
			typedef typename Type<typename Type::class_type		       >::flow class_type;
			typedef typename Type<typename Type::element_type	       >::flow element_type;
			typedef typename Type<typename Type::indirectee_type	       >::flow indirectee_type;
			typedef typename Type<typename Type::pointee_type	       >::flow pointee_type;
			typedef typename Type<typename Type::referencee_type	       >::flow referencee_type;
			typedef typename Type<typename Type::remove_array	       >::flow remove_array;
			typedef typename Type<typename Type::remove_const	       >::flow remove_const;
			typedef typename Type<typename Type::remove_const_this	       >::flow remove_const_this;
			typedef typename Type<typename Type::remove_const_volatile     >::flow remove_const_volatile;
			typedef typename Type<typename Type::remove_const_volatile_this>::flow remove_const_volatile_this;
			typedef typename Type<typename Type::remove_indirection	       >::flow remove_indirection;
			typedef typename Type<typename Type::remove_member_pointer     >::flow remove_member_pointer;
			typedef typename Type<typename Type::remove_pointer	       >::flow remove_pointer;
			typedef typename Type<typename Type::remove_reference	       >::flow remove_reference;
			typedef typename Type<typename Type::remove_this	       >::flow remove_this;
			typedef typename Type<typename Type::remove_volatile	       >::flow remove_volatile;
			typedef typename Type<typename Type::remove_volatile_this      >::flow remove_volatile_this;
			typedef typename Type<typename Type::return_type	       >::flow return_type;
			typedef typename Type<typename Type::to_const		       >::flow to_const;
			typedef typename Type<typename Type::to_const_volatile	       >::flow to_const_volatile;
			typedef typename Type<typename Type::to_forwardable	       >::flow to_forwardable;
			typedef typename Type<typename Type::to_function	       >::flow to_function;
			typedef typename Type<typename Type::to_lvalue_reference       >::flow to_lvalue_reference;
			typedef typename Type<typename Type::to_opaque		       >::flow to_opaque;
			typedef typename Type<typename Type::to_pointer		       >::flow to_pointer;
			typedef typename Type<typename Type::to_signed		       >::flow to_signed;
			typedef typename Type<typename Type::to_unqualified	       >::flow to_unqualified;
			typedef typename Type<typename Type::to_unsigned	       >::flow to_unsigned;
			typedef typename Type<typename Type::to_volatile	       >::flow to_volatile;
			typedef typename Type<typename Type::to_wrap		       >::flow to_wrap;

#			if Z_DIALECT_HAS(CPP, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)
				typedef typename Type<typename Type::add_const_lvalue	      >::flow add_const_lvalue;
				typedef typename Type<typename Type::add_const_rvalue	      >::flow add_const_rvalue;
				typedef typename Type<typename Type::add_const_volatile_lvalue>::flow add_const_volatile_lvalue;
				typedef typename Type<typename Type::add_const_volatile_rvalue>::flow add_const_volatile_rvalue;
				typedef typename Type<typename Type::add_lvalue		      >::flow add_lvalue;
				typedef typename Type<typename Type::add_rvalue		      >::flow add_rvalue;
				typedef typename Type<typename Type::add_volatile_lvalue      >::flow add_volatile_lvalue;
				typedef typename Type<typename Type::add_volatile_rvalue      >::flow add_volatile_rvalue;
				typedef typename Type<typename Type::to_const_lvalue	      >::flow to_const_lvalue;
				typedef typename Type<typename Type::to_const_rvalue	      >::flow to_const_rvalue;
				typedef typename Type<typename Type::to_const_volatile_lvalue >::flow to_const_volatile_lvalue;
				typedef typename Type<typename Type::to_const_volatile_rvalue >::flow to_const_volatile_rvalue;
				typedef typename Type<typename Type::to_lvalue		      >::flow to_lvalue;
				typedef typename Type<typename Type::to_rvalue		      >::flow to_rvalue;
				typedef typename Type<typename Type::to_volatile_lvalue	      >::flow to_volatile_lvalue;
				typedef typename Type<typename Type::to_volatile_rvalue	      >::flow to_volatile_rvalue;
#			endif

#			if Z_DIALECT_HAS(CPP, NOEXCEPT_AS_PART_OF_THE_FUNCTION_TYPE)
				typedef typename Type<typename Type::add_noexcept   >::flow add_noexcept;
				typedef typename Type<typename Type::remove_noexcept>::flow remove_noexcept;
#			endif

#			if Z_DIALECT_HAS(CPP, RVALUE_REFERENCE)
				typedef typename Type<typename Type::add_rvalue_reference>::flow add_rvalue_reference;
				typedef typename Type<typename Type::to_rvalue_reference >::flow to_rvalue_reference;
#			endif

#			if Z_DECLARES_MEMBER(Type, parameters)
				typedef typename Type::parameters parameters;
#			endif

#			if Z_DECLARES_MEMBER(Type, underlying_type)
				typedef typename Type<typename Type::underlying_type>::flow underlying_type;
#			endif

#			if Z_DIALECT_HAS(CPP, TYPE_ALIAS_TEMPLATE)
				template <class klass> using add_member_pointer = typename Type<typename Type::add_member_pointer<klass> >::flow;
				template <class klass> using to_member_pointer	= typename Type<typename Type::to_member_pointer <klass> >::flow;
#			endif

#			if Z_DECLARES_MEMBER(Type, parameter)
				template <zuint index> using parameter = typename Type<typename Type::template parameter<index> >::flow;
#			endif

			Z_IMPLEMENTATION__MEMBER_FUNCTIONS
		};

#		undef Z_IMPLEMENTATION__MEMBER_FUNCTIONS
	};

	template <class T> struct TypeArity			{enum {value = Type<T>::arity			     };};
	template <class T> struct TypeCanDecorateFunction	{enum {value = Type<T>::can_decorate_function	     };};
	template <class T> struct TypeCanDecorateMemberPointer	{enum {value = Type<T>::can_decorate_member_pointer  };};
	template <class T> struct TypeCanDecoratePointer	{enum {value = Type<T>::can_decorate_pointer	     };};
	template <class T> struct TypeCanDecorateReference	{enum {value = Type<T>::can_decorate_reference	     };};
	template <class T> struct TypeCanFormMemberPointer	{enum {value = Type<T>::can_form_member_pointer	     };};
	template <class T> struct TypeCanFormPointer		{enum {value = Type<T>::can_form_pointer	     };};
	template <class T> struct TypeCanFormReference		{enum {value = Type<T>::can_form_reference	     };};
	template <class T> struct TypeDimensionCount		{enum {value = Type<T>::dimension_count		     };};
	template <class T> struct TypeElementCount		{enum {value = Type<T>::element_count		     };};
	template <class T> struct TypeFixedFundamental		{enum {value = Type<T>::fixed_fundamental	     };};
	template <class T> struct TypeFundamental		{enum {value = Type<T>::fundamental		     };};
	template <class T> struct TypeHasQualifiedIndirectee	{enum {value = Type<T>::has_qualified_indirectee     };};
	template <class T> struct TypeIndirectionLevel		{enum {value = Type<T>::indirection_level	     };};
	template <class T> struct TypeIsArithmetic		{enum {value = Type<T>::is_arithmetic		     };};
	template <class T> struct TypeIsArray			{enum {value = Type<T>::is_array		     };};
	template <class T> struct TypeIsBlockObject		{enum {value = Type<T>::is_block_object		     };};
	template <class T> struct TypeIsBoolean			{enum {value = Type<T>::is_boolean		     };};
	template <class T> struct TypeIsClass			{enum {value = Type<T>::is_class		     };};
	template <class T> struct TypeIsCompound		{enum {value = Type<T>::is_compound		     };};
	template <class T> struct TypeIsConst			{enum {value = Type<T>::is_const		     };};
	template <class T> struct TypeIsConstLValue		{enum {value = Type<T>::is_const_lvalue		     };};
	template <class T> struct TypeIsConstRValue		{enum {value = Type<T>::is_const_rvalue		     };};
	template <class T> struct TypeIsConstVolatile		{enum {value = Type<T>::is_const_volatile	     };};
	template <class T> struct TypeIsConstVolatileLValue	{enum {value = Type<T>::is_const_volatile_lvalue     };};
	template <class T> struct TypeIsConstVolatileRValue	{enum {value = Type<T>::is_const_volatile_rvalue     };};
	template <class T> struct TypeIsDataLValueReference	{enum {value = Type<T>::is_data_lvalue_reference     };};
	template <class T> struct TypeIsDataMemberPointer	{enum {value = Type<T>::is_data_member_pointer	     };};
	template <class T> struct TypeIsDataPointer		{enum {value = Type<T>::is_data_pointer		     };};
	template <class T> struct TypeIsDataReference		{enum {value = Type<T>::is_data_reference	     };};
	template <class T> struct TypeIsDataRValueReference	{enum {value = Type<T>::is_data_rvalue_reference     };};
	template <class T> struct TypeIsEmpty			{enum {value = Type<T>::is_empty		     };};
	template <class T> struct TypeIsExact			{enum {value = Type<T>::is_exact		     };};
	template <class T> struct TypeIsIndirection		{enum {value = Type<T>::is_indirection		     };};
	template <class T> struct TypeIsInteger			{enum {value = Type<T>::is_integer		     };};
	template <class T> struct TypeIsIntegral		{enum {value = Type<T>::is_integral		     };};
	template <class T> struct TypeIsFloatingPoint		{enum {value = Type<T>::is_floating_point	     };};
	template <class T> struct TypeIsFunction		{enum {value = Type<T>::is_function		     };};
	template <class T> struct TypeIsFunctionLValueReference {enum {value = Type<T>::is_function_lvalue_reference };};
	template <class T> struct TypeIsFunctionPointer		{enum {value = Type<T>::is_function_pointer	     };};
	template <class T> struct TypeIsFunctionReference	{enum {value = Type<T>::is_function_reference	     };};
	template <class T> struct TypeIsFunctionRValueReference {enum {value = Type<T>::is_function_rvalue_reference };};
	template <class T> struct TypeIsFundamental		{enum {value = Type<T>::is_fundamental		     };};
	template <class T> struct TypeIsLValue			{enum {value = Type<T>::is_lvalue		     };};
	template <class T> struct TypeIsLValueReference		{enum {value = Type<T>::is_lvalue_reference	     };};
	template <class T> struct TypeIsMemberFunctionPointer	{enum {value = Type<T>::is_member_function_pointer   };};
	template <class T> struct TypeIsMemberPointer		{enum {value = Type<T>::is_member_pointer	     };};
	template <class T> struct TypeIsNaT			{enum {value = Type<T>::is_nat			     };};
	template <class T> struct TypeIsNatural			{enum {value = Type<T>::is_natural		     };};
	template <class T> struct TypeIsNumber			{enum {value = Type<T>::is_number		     };};
	template <class T> struct TypeIsObjectiveCClass		{enum {value = Type<T>::is_objective_c_class	     };};
	template <class T> struct TypeIsObjectiveCClassPointer	{enum {value = Type<T>::is_objective_c_class_pointer };};
	template <class T> struct TypeIsObjectiveCObject	{enum {value = Type<T>::is_objective_c_object	     };};
	template <class T> struct TypeIsObjectiveCObjectPointer	{enum {value = Type<T>::is_objective_c_object_pointer};};
	template <class T> struct TypeIsPointer			{enum {value = Type<T>::is_pointer		     };};
	template <class T> struct TypeIsQualified		{enum {value = Type<T>::is_qualified		     };};
	template <class T> struct TypeIsReal			{enum {value = Type<T>::is_real			     };};
	template <class T> struct TypeIsReference		{enum {value = Type<T>::is_reference		     };};
	template <class T> struct TypeIsRValue			{enum {value = Type<T>::is_rvalue		     };};
	template <class T> struct TypeIsRValueReference		{enum {value = Type<T>::is_rvalue_reference	     };};
	template <class T> struct TypeIsScalar			{enum {value = Type<T>::is_scalar		     };};
	template <class T> struct TypeIsSigned			{enum {value = Type<T>::is_signed		     };};
	template <class T> struct TypeIsSimple			{enum {value = Type<T>::is_simple		     };};
	template <class T> struct TypeIsSizedArray		{enum {value = Type<T>::is_sized_array		     };};
	template <class T> struct TypeIsStaticallyAllocatable	{enum {value = Type<T>::is_statically_allocatable    };};
	template <class T> struct TypeIsStorable		{enum {value = Type<T>::is_storable		     };};
	template <class T> struct TypeIsStructure		{enum {value = Type<T>::is_structure		     };};
	template <class T> struct TypeIsUnsigned		{enum {value = Type<T>::is_unsigned		     };};
	template <class T> struct TypeIsUnsizedArray		{enum {value = Type<T>::is_unsized_array	     };};
	template <class T> struct TypeIsValid			{enum {value = Type<T>::is_valid		     };};
	template <class T> struct TypeIsVariadic		{enum {value = Type<T>::is_variadic		     };};
	template <class T> struct TypeIsVariadicFunction	{enum {value = Type<T>::is_variadic_function	     };};
	template <class T> struct TypeIsVoid			{enum {value = Type<T>::is_void			     };};
	template <class T> struct TypeIsVoidPointer		{enum {value = Type<T>::is_void_pointer		     };};
	template <class T> struct TypeIsVolatile		{enum {value = Type<T>::is_volatile		     };};
	template <class T> struct TypeIsVolatileLValue		{enum {value = Type<T>::is_volatile_lvalue	     };};
	template <class T> struct TypeIsVolatileRValue		{enum {value = Type<T>::is_volatile_rvalue	     };};
	template <class T> struct TypeIssConst			{enum {value = Type<T>::iss_const		     };};
	template <class T> struct TypeIssConstLValue		{enum {value = Type<T>::iss_const_lvalue	     };};
	template <class T> struct TypeIssConstRValue		{enum {value = Type<T>::iss_const_rvalue	     };};
	template <class T> struct TypeIssConstVolatile		{enum {value = Type<T>::iss_const_volatile	     };};
	template <class T> struct TypeIssLValue			{enum {value = Type<T>::iss_lvalue		     };};
	template <class T> struct TypeIssRValue			{enum {value = Type<T>::iss_rvalue		     };};
	template <class T> struct TypeIssVolatile		{enum {value = Type<T>::iss_volatile		     };};
	template <class T> struct TypeIssVolatileLValue		{enum {value = Type<T>::iss_volatile_lvalue	     };};
	template <class T> struct TypeIssVolatileRValue		{enum {value = Type<T>::iss_volatile_rvalue	     };};
	template <class T> struct TypeNumberFormat		{enum {value = Type<T>::number_format		     };};
	template <class T> struct TypeNumberSet			{enum {value = Type<T>::number_set		     };};
	template <class T> struct TypePointerLevel		{enum {value = Type<T>::pointer_level		     };};

#	if Z_DECLARES(TypeHasVirtualDestructor)
		template <class T> struct TypeHasVirtualDestructor {enum {value = Type<T>::has_virtual_destructor};};
#	endif

#	if Z_DECLARES(TypeIsAbstract)
		template <class T> struct TypeIsAbstract {enum {value = Type<T>::is_abstract};};
#	endif

#	if Z_DECLARES(TypeIsAggregate)
		template <class T> struct TypeIsAggregate {enum {value = Type<T>::is_aggregate};};
#	endif

#	if Z_DECLARES(TypeIsDefaultConstructible)
		template <class T> struct TypeIsDefaultConstructible {enum {value = Type<T>::is_default_constructible};};
#	endif

#	if Z_DECLARES(TypeIsEnumeration)
		template <class T> struct TypeIsEnumeration {enum {value = Type<T>::is_enumeration};};
#	endif

#	if Z_DECLARES(TypeIsFinal)
		template <class T> struct TypeIsFinal {enum {value = Type<T>::is_final};};
#	endif

#	if Z_DECLARES(TypeIsInterfaceClass)
		template <class T> struct TypeIsInterfaceClass {enum {value = Type<T>::is_interface_class};};
#	endif

#	if Z_DECLARES(TypeIsLiteral)
		template <class T> struct TypeIsLiteral {enum {value = Type<T>::is_literal};};
#	endif

#	if Z_DECLARES(TypeIsNoexcept)
		template <class T> struct TypeIsNoexcept {enum {value = Type<T>::is_noexcept};};
#	endif

#	if Z_DECLARES(TypeIsNullPtr)
		template <class T> struct TypeIsNullPtr {enum {value = Type<T>::is_nullptr};};
#	endif

#	if Z_DECLARES(TypeIsPOD)
		template <class T> struct TypeIsPOD {enum {value = Type<T>::is_pod};};
#	endif

#	if Z_DECLARES(TypeIsPolymorphic)
		template <class T> struct TypeIsPolymorphic {enum {value = Type<T>::is_polymorphic};};
#	endif

#	if Z_DECLARES(TypeIsTemplate)
		template <class T> struct TypeIsTemplate {enum {value = Type<T>::is_template};};
#	endif

#	if Z_DECLARES(TypeIsTriviallyCopyAssignable)
		template <class T> struct TypeIsTriviallyCopyAssignable {enum {value = Type<T>::is_trivially_copy_assignable};};
#	endif

#	if Z_DECLARES(TypeIsTriviallyCopyConstructible)
		template <class T> struct TypeIsTriviallyCopyConstructible {enum {value = Type<T>::is_trivially_copy_constructible};};
#	endif

#	if Z_DECLARES(TypeIsTriviallyCopyable)
		template <class T> struct TypeIsTriviallyCopyable {enum {value = Type<T>::is_trivially_copyable};};
#	endif

#	if Z_DECLARES(TypeIsTriviallyDefaultConstructible)
		template <class T> struct TypeIsTriviallyDefaultConstructible {enum {value = Type<T>::is_trivially_default_constructible};};
#	endif

#	if Z_DECLARES(TypeIsTriviallyDestructible)
		template <class T> struct TypeIsTriviallyDestructible {enum {value = Type<T>::is_trivially_destructible};};
#	endif

#	if Z_DECLARES(TypeIsUnion)
		template <class T> struct TypeIsUnion {enum {value = Type<T>::is_union};};
#	endif

#	if Z_LANGUAGE_INCLUDES(OBJECTIVE_CPP) && Z_DIALECT_HAS(CPP, EXPRESSION_SFINAE)
		template <class T> struct TypeIsObjectiveCInstance	  {enum {value = Type<T>::is_objective_c_instance	 };};
		template <class T> struct TypeIsObjectiveCInstancePointer {enum {value = Type<T>::is_objective_c_instance_pointer};};
#	endif

	template <class T> struct TypeAddConst		      {typedef typename Type<T>::add_const		    type;};
	template <class T> struct TypeAddConstVolatile	      {typedef typename Type<T>::add_const_volatile	    type;};
	template <class T> struct TypeAddLValueReference      {typedef typename Type<T>::add_lvalue_reference	    type;};
	template <class T> struct TypeAddPointer	      {typedef typename Type<T>::add_pointer		    type;};
	template <class T> struct TypeAddVolatile	      {typedef typename Type<T>::add_volatile		    type;};
	template <class T> struct TypeClassType		      {typedef typename Type<T>::class_type		    type;};
	template <class T> struct TypeElementType	      {typedef typename Type<T>::element_type		    type;};
	template <class T> struct TypeIndirecteeType	      {typedef typename Type<T>::indirectee_type	    type;};
	template <class T> struct TypePointeeType	      {typedef typename Type<T>::pointee_type		    type;};
	template <class T> struct TypeReferenceeType	      {typedef typename Type<T>::referencee_type	    type;};
	template <class T> struct TypeRemoveArray	      {typedef typename Type<T>::remove_array		    type;};
	template <class T> struct TypeRemoveConst	      {typedef typename Type<T>::remove_const		    type;};
	template <class T> struct TypeRemoveConstThis	      {typedef typename Type<T>::remove_const_this	    type;};
	template <class T> struct TypeRemoveConstVolatile     {typedef typename Type<T>::remove_const_volatile	    type;};
	template <class T> struct TypeRemoveConstVolatileThis {typedef typename Type<T>::remove_const_volatile_this type;};
	template <class T> struct TypeRemoveIndirection	      {typedef typename Type<T>::remove_indirection	    type;};
	template <class T> struct TypeRemoveMemberPointer     {typedef typename Type<T>::remove_member_pointer	    type;};
	template <class T> struct TypeRemoveReference	      {typedef typename Type<T>::remove_reference	    type;};
	template <class T> struct TypeRemoveThis	      {typedef typename Type<T>::remove_this		    type;};
	template <class T> struct TypeRemoveVolatile	      {typedef typename Type<T>::remove_volatile	    type;};
	template <class T> struct TypeRemoveVolatileThis      {typedef typename Type<T>::remove_volatile_this	    type;};
	template <class T> struct TypeReturnType	      {typedef typename Type<T>::return_type		    type;};
	template <class T> struct TypeToConst		      {typedef typename Type<T>::to_const		    type;};
	template <class T> struct TypeToConstVolatile	      {typedef typename Type<T>::to_const_volatile	    type;};
	template <class T> struct TypeToForwardable	      {typedef typename Type<T>::to_forwardable		    type;};
	template <class T> struct TypeToFunction	      {typedef typename Type<T>::to_function		    type;};
	template <class T> struct TypeToLValueReference	      {typedef typename Type<T>::to_lvalue_reference	    type;};
	template <class T> struct TypeToOpaque		      {typedef typename Type<T>::to_opaque		    type;};
	template <class T> struct TypeToPointer		      {typedef typename Type<T>::to_pointer		    type;};
	template <class T> struct TypeToSigned		      {typedef typename Type<T>::to_signed		    type;};
	template <class T> struct TypeToUnqualified	      {typedef typename Type<T>::to_unqualified		    type;};
	template <class T> struct TypeToUnsigned	      {typedef typename Type<T>::to_unsigned		    type;};
	template <class T> struct TypeToVolatile	      {typedef typename Type<T>::to_volatile		    type;};
	template <class T> struct TypeToWrap		      {typedef typename Type<T>::to_wrap		    type;};

	template <class T, class klass> struct TypeToMemberPointer {
		typedef typename TypeAddMemberPointer<typename Type<T>::remove_indirection, klass>::type type;
	};

#	if Z_DIALECT_HAS(CPP, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)
		template <class T> struct TypeAddConstLValue	     {typedef typename Type<T>::add_const_lvalue	  type;};
		template <class T> struct TypeAddConstRValue	     {typedef typename Type<T>::add_const_rvalue	  type;};
		template <class T> struct TypeAddConstVolatileLValue {typedef typename Type<T>::add_const_volatile_lvalue type;};
		template <class T> struct TypeAddConstVolatileRValue {typedef typename Type<T>::add_const_volatile_rvalue type;};
		template <class T> struct TypeAddLValue		     {typedef typename Type<T>::add_lvalue		  type;};
		template <class T> struct TypeAddRValue		     {typedef typename Type<T>::add_rvalue		  type;};
		template <class T> struct TypeAddVolatileLValue	     {typedef typename Type<T>::add_volatile_lvalue	  type;};
		template <class T> struct TypeAddVolatileRValue	     {typedef typename Type<T>::add_volatile_rvalue	  type;};
		template <class T> struct TypeToConstLValue	     {typedef typename Type<T>::to_const_lvalue		  type;};
		template <class T> struct TypeToConstRValue	     {typedef typename Type<T>::to_const_rvalue		  type;};
		template <class T> struct TypeToConstVolatileLValue  {typedef typename Type<T>::to_const_volatile_lvalue  type;};
		template <class T> struct TypeToConstVolatileRValue  {typedef typename Type<T>::to_const_volatile_rvalue  type;};
		template <class T> struct TypeToLValue		     {typedef typename Type<T>::to_lvalue		  type;};
		template <class T> struct TypeToRValue		     {typedef typename Type<T>::to_rvalue		  type;};
		template <class T> struct TypeToVolatileLValue	     {typedef typename Type<T>::to_volatile_lvalue	  type;};
		template <class T> struct TypeToVolatileRValue	     {typedef typename Type<T>::to_volatile_rvalue	  type;};
#	endif

#	if Z_DIALECT_HAS(CPP, NOEXCEPT_AS_PART_OF_THE_FUNCTION_TYPE)
		template <class T> struct TypeAddNoexcept    {typedef typename Type<T>::add_noexcept	type;};
		template <class T> struct TypeRemoveNoexcept {typedef typename Type<T>::remove_noexcept type;};
#	endif

#	if Z_DIALECT_HAS(CPP, RVALUE_REFERENCE)
		template <class T> struct TypeAddRValueReference {typedef typename Type<T>::add_rvalue_reference type;};
		template <class T> struct TypeToRValueReference	 {typedef typename Type<T>::to_rvalue_reference	 type;};
#	endif

#	if Z_DECLARES(TypeParameters)
		template <class T> struct TypeParameters {typedef typename Type<T>::parameters type;};
#	endif

#	if Z_DECLARES(TypeUnderlyingType)
		template <class T> struct TypeUnderlyingType {typedef typename Type<T>::underlying_type	type;};
#	endif

#	if Z_DECLARES(TypeParameter)
		template <class T, UInt index> struct TypeParameter {
			typedef typename TypeListGet<typename Type<T>::parameters, index>::type type;
		};
#	endif

#	if Z_DIALECT_HAS(CPP, VARIABLE_TEMPLATE) && Z_DIALECT_HAS_SPECIFIER(CPP, CONSTEXPR)

		template <class T> Z_CONSTANT USize   type_arity			 = Type<T>::arity;
		template <class T> Z_CONSTANT Boolean type_can_decorate_function	 = Type<T>::can_decorate_function;
		template <class T> Z_CONSTANT Boolean type_can_decorate_member_pointer	 = Type<T>::can_decorate_member_pointer;
		template <class T> Z_CONSTANT Boolean type_can_decorate_pointer		 = Type<T>::can_decorate_pointer;
		template <class T> Z_CONSTANT Boolean type_can_decorate_reference	 = Type<T>::can_decorate_reference;
		template <class T> Z_CONSTANT Boolean type_can_form_member_pointer	 = Type<T>::can_form_member_pointer;
		template <class T> Z_CONSTANT Boolean type_can_form_pointer		 = Type<T>::can_form_pointer;
		template <class T> Z_CONSTANT Boolean type_can_form_reference		 = Type<T>::can_form_reference;
		template <class T> Z_CONSTANT Boolean type_has_qualified_indirectee	 = Type<T>::has_qualified_indirectee;
		template <class T> Z_CONSTANT Boolean type_is_arithmetic		 = Type<T>::is_arithmetic;
		template <class T> Z_CONSTANT Boolean type_is_array			 = Type<T>::is_array;
		template <class T> Z_CONSTANT Boolean type_is_block_object		 = Type<T>::is_block_object;
		template <class T> Z_CONSTANT Boolean type_is_boolean			 = Type<T>::is_boolean;
		template <class T> Z_CONSTANT Boolean type_is_class			 = Type<T>::is_class;
		template <class T> Z_CONSTANT Boolean type_is_compound			 = Type<T>::is_compound;
		template <class T> Z_CONSTANT Boolean type_is_const			 = Type<T>::is_const;
		template <class T> Z_CONSTANT Boolean type_is_const_lvalue		 = Type<T>::is_const_lvalue;
		template <class T> Z_CONSTANT Boolean type_is_const_rvalue		 = Type<T>::is_const_rvalue;
		template <class T> Z_CONSTANT Boolean type_is_const_volatile		 = Type<T>::is_const_volatile;
		template <class T> Z_CONSTANT Boolean type_is_const_volatile_lvalue	 = Type<T>::is_const_volatile_lvalue;
		template <class T> Z_CONSTANT Boolean type_is_const_volatile_rvalue	 = Type<T>::is_const_volatile_rvalue;
		template <class T> Z_CONSTANT Boolean type_is_data_lvalue_reference	 = Type<T>::is_data_lvalue_reference;
		template <class T> Z_CONSTANT Boolean type_is_data_member_pointer	 = Type<T>::is_data_member_pointer;
		template <class T> Z_CONSTANT Boolean type_is_data_pointer		 = Type<T>::is_data_pointer;
		template <class T> Z_CONSTANT Boolean type_is_data_reference		 = Type<T>::is_data_reference;
		template <class T> Z_CONSTANT Boolean type_is_data_rvalue_reference	 = Type<T>::is_data_rvalue_reference;
		template <class T> Z_CONSTANT Boolean type_is_empty			 = Type<T>::is_empty;
		template <class T> Z_CONSTANT Boolean type_is_exact			 = Type<T>::is_exact;
		template <class T> Z_CONSTANT Boolean type_is_indirection		 = Type<T>::is_indirection;
		template <class T> Z_CONSTANT Boolean type_is_integer			 = Type<T>::is_integer;
		template <class T> Z_CONSTANT Boolean type_is_integral			 = Type<T>::is_integral;
		template <class T> Z_CONSTANT Boolean type_is_floating_point		 = Type<T>::is_floating_point;
		template <class T> Z_CONSTANT Boolean type_is_function			 = Type<T>::is_function;
		template <class T> Z_CONSTANT Boolean type_is_function_lvalue_reference	 = Type<T>::is_function_lvalue_reference;
		template <class T> Z_CONSTANT Boolean type_is_function_pointer		 = Type<T>::is_function_pointer;
		template <class T> Z_CONSTANT Boolean type_is_function_reference	 = Type<T>::is_function_reference;
		template <class T> Z_CONSTANT Boolean type_is_function_rvalue_reference	 = Type<T>::is_function_rvalue_reference;
		template <class T> Z_CONSTANT Boolean type_is_fundamental		 = Type<T>::is_fundamental;
		template <class T> Z_CONSTANT Boolean type_is_lvalue			 = Type<T>::is_lvalue;
		template <class T> Z_CONSTANT Boolean type_is_lvalue_reference		 = Type<T>::is_lvalue_reference;
		template <class T> Z_CONSTANT Boolean type_is_member_function_pointer	 = Type<T>::is_member_function_pointer;
		template <class T> Z_CONSTANT Boolean type_is_member_pointer		 = Type<T>::is_member_pointer;
		template <class T> Z_CONSTANT Boolean type_is_nat			 = Type<T>::is_nat;
		template <class T> Z_CONSTANT Boolean type_is_natural			 = Type<T>::is_natural;
		template <class T> Z_CONSTANT Boolean type_is_number			 = Type<T>::is_number;
		template <class T> Z_CONSTANT Boolean type_is_objective_c_class		 = Type<T>::is_objective_c_class;
		template <class T> Z_CONSTANT Boolean type_is_objective_c_class_pointer	 = Type<T>::is_objective_c_class_pointer;
		template <class T> Z_CONSTANT Boolean type_is_objective_c_object	 = Type<T>::is_objective_c_object;
		template <class T> Z_CONSTANT Boolean type_is_objective_c_object_pointer = Type<T>::is_objective_c_object_pointer;
		template <class T> Z_CONSTANT Boolean type_is_pointer			 = Type<T>::is_pointer;
		template <class T> Z_CONSTANT Boolean type_is_qualified			 = Type<T>::is_qualified;
		template <class T> Z_CONSTANT Boolean type_is_real			 = Type<T>::is_real;
		template <class T> Z_CONSTANT Boolean type_is_reference			 = Type<T>::is_reference;
		template <class T> Z_CONSTANT Boolean type_is_rvalue			 = Type<T>::is_rvalue;
		template <class T> Z_CONSTANT Boolean type_is_rvalue_reference		 = Type<T>::is_rvalue_reference;
		template <class T> Z_CONSTANT Boolean type_is_scalar			 = Type<T>::is_scalar;
		template <class T> Z_CONSTANT Boolean type_is_signed			 = Type<T>::is_signed;
		template <class T> Z_CONSTANT Boolean type_is_simple			 = Type<T>::is_simple;
		template <class T> Z_CONSTANT Boolean type_is_sized_array		 = Type<T>::is_sized_array;
		template <class T> Z_CONSTANT Boolean type_is_statically_allocatable	 = Type<T>::is_statically_allocatable;
		template <class T> Z_CONSTANT Boolean type_is_storable			 = Type<T>::is_storable;
		template <class T> Z_CONSTANT Boolean type_is_structure			 = Type<T>::is_structure;
		template <class T> Z_CONSTANT Boolean type_is_unsigned			 = Type<T>::is_unsigned;
		template <class T> Z_CONSTANT Boolean type_is_unsized_array		 = Type<T>::is_unsized_array;
		template <class T> Z_CONSTANT Boolean type_is_valid			 = Type<T>::is_valid;
		template <class T> Z_CONSTANT Boolean type_is_variadic			 = Type<T>::is_variadic;
		template <class T> Z_CONSTANT Boolean type_is_variadic_function		 = Type<T>::is_variadic_function;
		template <class T> Z_CONSTANT Boolean type_is_void			 = Type<T>::is_void;
		template <class T> Z_CONSTANT Boolean type_is_void_pointer		 = Type<T>::is_void_pointer;
		template <class T> Z_CONSTANT Boolean type_is_volatile			 = Type<T>::is_volatile;
		template <class T> Z_CONSTANT Boolean type_is_volatile_lvalue		 = Type<T>::is_volatile_lvalue;
		template <class T> Z_CONSTANT Boolean type_is_volatile_rvalue		 = Type<T>::is_volatile_rvalue;
		template <class T> Z_CONSTANT Boolean type_iss_const			 = Type<T>::iss_const;
		template <class T> Z_CONSTANT Boolean type_iss_const_lvalue		 = Type<T>::iss_const_lvalue;
		template <class T> Z_CONSTANT Boolean type_iss_const_rvalue		 = Type<T>::iss_const_rvalue;
		template <class T> Z_CONSTANT Boolean type_iss_const_volatile		 = Type<T>::iss_const_volatile;
		template <class T> Z_CONSTANT Boolean type_iss_lvalue			 = Type<T>::iss_lvalue;
		template <class T> Z_CONSTANT Boolean type_iss_rvalue			 = Type<T>::iss_rvalue;
		template <class T> Z_CONSTANT Boolean type_iss_volatile			 = Type<T>::iss_volatile;
		template <class T> Z_CONSTANT Boolean type_iss_volatile_lvalue		 = Type<T>::iss_volatile_lvalue;
		template <class T> Z_CONSTANT Boolean type_iss_volatile_rvalue		 = Type<T>::iss_volatile_rvalue;
		template <class T> Z_CONSTANT UInt    type_number_format		 = Type<T>::number_format;
		template <class T> Z_CONSTANT UInt    type_number_set			 = Type<T>::number_set;
		template <class T> Z_CONSTANT UInt    type_pointer_level		 = Type<T>::pointer_level;

		template <class A, class B> Z_CONSTANT Boolean type_is_same = TypeIsSame<A, B>::value;

#		if Z_DECLARES(TypeIsBase)
			template <class T, class of_type> Z_CONSTANT Boolean type_is_base = TypeIsBase<T, of_type>::value;
#		endif

#		if Z_DECLARES(TypeIsConvertible)
			template <class T, class to_type> Z_CONSTANT Boolean type_is_convertible = TypeIsConvertible<T, to_type>::value;
#		endif

#		if Z_DECLARES(TypeIsConstructible)
			template <class T, class... parameters> Z_CONSTANT Boolean type_is_constructible = TypeIsConstructible<T, parameters...>::value;
#		endif

#		if Z_DECLARES(TypeIsNothrowAssignable)
			template <class T, class from_type> Z_CONSTANT Boolean type_is_nothrow_assignable = TypeIsNothrowAssignable<T, from_type>::value;
#		endif

#		if Z_DECLARES(TypeIsNothrowConstructible)
			template <class T, class... parameters> Z_CONSTANT Boolean type_is_nothrow_constructible = TypeIsNothrowConstructible<T, parameters...>::value;
#		endif

#		if Z_DECLARES(TypeIsTriviallyAssignable)
			template <class T, class from_type> Z_CONSTANT Boolean type_is_trivially_assignable = TypeIsTriviallyAssignable<T, from_type>::value;
#		endif

#		if Z_DECLARES(TypeIsTriviallyConstructible)
			template <class T, class... parameters> Z_CONSTANT Boolean type_is_trivially_constructible = TypeIsTriviallyConstructible<T, parameters...>::value;
#		endif

#		if Z_DECLARES_MEMBER(Type, has_virtual_destructor)
			template <class T> Z_CONSTANT Boolean type_has_virtual_destructor = Type<T>::has_virtual_destructor;
#		endif

#		if Z_DECLARES_MEMBER(Type, is_abstract)
			template <class T> Z_CONSTANT Boolean type_is_abstract = Type<T>::is_abstract;
#		endif

#		if Z_DECLARES_MEMBER(Type, is_aggregate)
			template <class T> Z_CONSTANT Boolean type_is_aggregate = Type<T>::is_aggregate;
#		endif

#		if Z_DECLARES_MEMBER(Type, is_default_constructible)
			template <class T> Z_CONSTANT Boolean type_is_default_constructible = Type<T>::is_default_constructible;
#		endif

#		if Z_DECLARES_MEMBER(Type, is_enumeration)
			template <class T> Z_CONSTANT Boolean type_is_enumeration = Type<T>::is_enumeration;
#		endif

#		if Z_DECLARES_MEMBER(Type, is_final)
			template <class T> Z_CONSTANT Boolean type_is_final = Type<T>::is_final;
#		endif

#		if Z_DECLARES_MEMBER(Type, is_interface_class)
			template <class T> Z_CONSTANT Boolean type_is_interface_class = Type<T>::is_interface_class;
#		endif

#		if Z_DECLARES_MEMBER(Type, is_literal)
			template <class T> Z_CONSTANT Boolean type_is_literal = Type<T>::is_literal;
#		endif

#		if Z_DECLARES_MEMBER(Type, is_noexcept)
			template <class T> Z_CONSTANT Boolean type_is_noexcept = Type<T>::is_noexcept;
#		endif

#		if Z_DECLARES_MEMBER(Type, is_nullptr)
			template <class T> Z_CONSTANT Boolean type_is_nullptr = Type<T>::is_nullptr;
#		endif

#		if Z_DECLARES_MEMBER(Type, is_pod)
			template <class T> Z_CONSTANT Boolean type_is_pod = Type<T>::is_pod;
#		endif

#		if Z_DECLARES_MEMBER(Type, is_polymorphic)
			template <class T> Z_CONSTANT Boolean type_is_polymorphic = Type<T>::is_polymorphic;
#		endif

#		if Z_DECLARES_MEMBER(Type, is_template)
			template <class T> Z_CONSTANT Boolean type_is_template = Type<T>::is_template;
#		endif

#		if Z_DECLARES_MEMBER(Type, is_trivially_copy_assignable)
			template <class T> Z_CONSTANT Boolean type_is_trivially_copy_assignable = Type<T>::is_trivially_copy_assignable;
#		endif

#		if Z_DECLARES_MEMBER(Type, is_trivially_copy_constructible)
			template <class T> Z_CONSTANT Boolean type_is_trivially_copy_constructible = Type<T>::is_trivially_copy_constructible;
#		endif

#		if Z_DECLARES_MEMBER(Type, is_trivially_copyable)
			template <class T> Z_CONSTANT Boolean type_is_trivially_copyable = Type<T>::is_trivially_copyable;
#		endif

#		if Z_DECLARES_MEMBER(Type, is_trivially_default_constructible)
			template <class T> Z_CONSTANT Boolean type_is_trivially_default_constructible = Type<T>::is_trivially_default_constructible;
#		endif

#		if Z_DECLARES_MEMBER(Type, is_trivially_destructible)
			template <class T> Z_CONSTANT Boolean type_is_trivially_destructible = Type<T>::is_trivially_destructible;
#		endif

#		if Z_DECLARES_MEMBER(Type, is_union)
			template <class T> Z_CONSTANT Boolean type_is_union = Type<T>::is_union;
#		endif

#		if Z_LANGUAGE_INCLUDES(OBJECTIVE_CPP) && Z_DIALECT_HAS(CPP, EXPRESSION_SFINAE)
			template <class T> Z_CONSTANT Boolean type_is_objective_c_instance	   = Type<T>::is_objective_c_instance;
			template <class T> Z_CONSTANT Boolean type_is_objective_c_instance_pointer = Type<T>::is_objective_c_instance_pointer;
#		endif

#	endif

#	if Z_DIALECT_HAS(CPP, TYPE_ALIAS_TEMPLATE)

		template <class T> using type_add_const			 = typename Type<T>::add_const;
		template <class T> using type_add_const_volatile	 = typename Type<T>::add_const_volatile;
		template <class T> using type_add_lvalue_reference	 = typename Type<T>::add_lvalue_reference;
		template <class T> using type_add_pointer		 = typename Type<T>::add_pointer;
		template <class T> using type_add_volatile		 = typename Type<T>::add_volatile;
		template <class T> using type_class_type		 = typename Type<T>::class_type;
		template <class T> using type_element_type		 = typename Type<T>::element_type;
		template <class T> using type_indirectee_type		 = typename Type<T>::indirectee_type;
		template <class T> using type_pointee_type		 = typename Type<T>::pointee_type;
		template <class T> using type_referencee_type		 = typename Type<T>::referencee_type;
		template <class T> using type_remove_array		 = typename Type<T>::remove_array;
		template <class T> using type_remove_const		 = typename Type<T>::remove_const;
		template <class T> using type_remove_const_this		 = typename Type<T>::remove_const_this;
		template <class T> using type_remove_const_volatile	 = typename Type<T>::remove_const_volatile;
		template <class T> using type_remove_const_volatile_this = typename Type<T>::remove_const_volatile_this;
		template <class T> using type_remove_indirection	 = typename Type<T>::remove_indirection;
		template <class T> using type_remove_member_pointer	 = typename Type<T>::remove_member_pointer;
		template <class T> using type_remove_pointer		 = typename TypeRemovePointer<T>::type;
		template <class T> using type_remove_reference		 = typename Type<T>::remove_reference;
		template <class T> using type_remove_this		 = typename Type<T>::remove_this;
		template <class T> using type_remove_volatile		 = typename Type<T>::remove_volatile;
		template <class T> using type_remove_volatile_this	 = typename Type<T>::remove_volatile_this;
		template <class T> using type_return_type		 = typename Type<T>::return_type;
		template <class T> using type_to_const			 = typename Type<T>::to_const;
		template <class T> using type_to_const_volatile		 = typename Type<T>::to_const_volatile;
		template <class T> using type_to_forwardable		 = typename Type<T>::to_forwardable;
		template <class T> using type_to_function		 = typename Type<T>::to_function;
		template <class T> using type_to_lvalue_reference	 = typename Type<T>::to_lvalue_reference;
		template <class T> using type_to_opaque			 = typename Type<T>::to_opaque;
		template <class T> using type_to_pointer		 = typename Type<T>::to_pointer;
		template <class T> using type_to_signed			 = typename Type<T>::to_signed;
		template <class T> using type_to_unqualified		 = typename Type<T>::to_unqualified;
		template <class T> using type_to_unsigned		 = typename Type<T>::to_unsigned;
		template <class T> using type_to_volatile		 = typename Type<T>::to_volatile;
		template <class T> using type_to_wrap			 = typename Type<T>::to_wrap;

		template <class T, class klass> using type_add_member_pointer = typename TypeAddMemberPointer<T, klass>::type;
		template <class T, class klass> using type_to_member_pointer  = typename TypeToMemberPointer <T, klass>::type;

#		if Z_DIALECT_HAS(CPP, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)
			template <class T> using type_add_const_lvalue		= typename Type<T>::add_const_lvalue;
			template <class T> using type_add_const_rvalue		= typename Type<T>::add_const_rvalue;
			template <class T> using type_add_const_volatile_lvalue = typename Type<T>::add_const_volatile_lvalue;
			template <class T> using type_add_const_volatile_rvalue = typename Type<T>::add_const_volatile_rvalue;
			template <class T> using type_add_lvalue		= typename Type<T>::add_lvalue;
			template <class T> using type_add_rvalue		= typename Type<T>::add_rvalue;
			template <class T> using type_add_volatile_lvalue	= typename Type<T>::add_volatile_lvalue;
			template <class T> using type_add_volatile_rvalue	= typename Type<T>::add_volatile_rvalue;
			template <class T> using type_to_const_lvalue		= typename Type<T>::to_const_lvalue;
			template <class T> using type_to_const_rvalue		= typename Type<T>::to_const_rvalue;
			template <class T> using type_to_const_volatile_lvalue	= typename Type<T>::to_const_volatile_lvalue;
			template <class T> using type_to_const_volatile_rvalue	= typename Type<T>::to_const_volatile_rvalue;
			template <class T> using type_to_lvalue			= typename Type<T>::to_lvalue;
			template <class T> using type_to_rvalue			= typename Type<T>::to_rvalue;
			template <class T> using type_to_volatile_lvalue	= typename Type<T>::to_volatile_lvalue;
			template <class T> using type_to_volatile_rvalue	= typename Type<T>::to_volatile_rvalue;
#		endif

#		if Z_DIALECT_HAS(CPP, NOEXCEPT_AS_PART_OF_THE_FUNCTION_TYPE)
			template <class T> using type_add_noexcept    = typename Type<T>::add_noexcept;
			template <class T> using type_remove_noexcept = typename Type<T>::remove_noexcept;
#		endif

#		if Z_DIALECT_HAS(CPP, RVALUE_REFERENCE)
			template <class T> using type_add_rvalue_reference = typename Type<T>::add_rvalue_reference;
			template <class T> using type_to_rvalue_reference  = typename Type<T>::to_rvalue_reference;
#		endif

#		if Z_DECLARES(type_parameters)
			template <class T> using type_parameters = typename Type<T>::parameters;
#		endif

#		if Z_DECLARES(type_underlying_type)
			template <class T> using type_underlying_type = typename Type<T>::underlying_type;
#		endif

#		if Z_DECLARES(type_parameter)
			template <class T, UInt index> using type_parameter = typename Type<T>::template parameter<index>;
#		endif

#	endif
}

#endif // Z_traits_Type_HPP
