/* Zeta API - Z/traits/type.hpp
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

/* TODO:
	transaction_safe
	traits de std
	enums
	Ambiguous
	Z_HAS
	includes

	is_anonymous
	is_anonymous_class
	is_anonymous_enumeration
	is_anonymous_structure
	is_anonymous_union
	is_capturing_lambda
	is_fixed_enumeration
	is_lambda
	is_non_capturing_lambda
	is_scoped_enumeration
	is_unfixed_enumeration
	is_unscoped_enumeration
*/

#ifndef Z_traits_type_HPP
#define Z_traits_type_HPP

#include <Z/keys/number.h>
#include <Z/inspection/Z.h>
#include <Z/types/integral.hpp>
#include <Z/types/real.hpp>
#include <Z/types/pointer.hpp>
#include <Z/traits/constants.hpp>
#include <Z/traits/TypeList.hpp>
#include <Z/classes/NaT.hpp>

#if !Z_HAS(TypeList)
#	include <Z/traits/control.hpp>

#	if Z_DIALECT_HAS(CPP11, VARIADIC_TEMPLATE)
#		include <Z/traits/TypeCount.hpp>
#	endif
#endif

#if Z_DIALECT_HAS(CPP11, EXPRESSION_SFINAE)
#	include <Z/functions/unevaluated.hpp>
#endif

#if Z_DIALECT_HAS(CPP17, NOEXCEPT_AS_PART_OF_THE_FUNCTION_TYPE)
#	include <Z/classes/Empty.hpp>
#endif

#if	Z_COMPILER_HAS_MAGIC_CONSTANT(MANGLED_FUNCTION_NAME) && \
	Z_DIALECT_HAS(CPP14, CONSTEXPR_FUNCTION)

#	include <Z/functions/type.hpp>
#	include <Z/functions/hash.hpp>
#endif

#include <Z/macros/iteration.h>

// MARK: - Component availability configuration

/*----------------------------------------------------------------------.
| Transformation components that are available only if the language     |
| features that their resulting types require are supported or enabled. |
'======================================================================*/

#if Z_DIALECT_HAS(CPP11, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)
#	define Z_HAS_TypeAddConstLValue			   1
#	define Z_HAS_TypeAddConstRValue			   1
#	define Z_HAS_TypeAddConstVolatileLValue		   1
#	define Z_HAS_TypeAddConstVolatileRValue		   1
#	define Z_HAS_TypeAddLValue			   1
#	define Z_HAS_TypeAddRValue			   1
#	define Z_HAS_TypeAddVolatileLValue		   1
#	define Z_HAS_TypeAddVolatileRValue		   1
#	define Z_HAS_TypeToConstLValue			   1
#	define Z_HAS_TypeToConstRValue			   1
#	define Z_HAS_TypeToConstVolatileLValue		   1
#	define Z_HAS_TypeToConstVolatileRValue		   1
#	define Z_HAS_TypeToLValue			   1
#	define Z_HAS_TypeToRValue			   1
#	define Z_HAS_TypeToVolatileLValue		   1
#	define Z_HAS_TypeToVolatileRValue		   1
#	define Z_HAS_Type_MEMBER_add_const_lvalue	   1
#	define Z_HAS_Type_MEMBER_add_const_rvalue	   1
#	define Z_HAS_Type_MEMBER_add_const_volatile_lvalue 1
#	define Z_HAS_Type_MEMBER_add_const_volatile_rvalue 1
#	define Z_HAS_Type_MEMBER_add_lvalue		   1
#	define Z_HAS_Type_MEMBER_add_rvalue		   1
#	define Z_HAS_Type_MEMBER_add_volatile_lvalue	   1
#	define Z_HAS_Type_MEMBER_add_volatile_rvalue	   1
#	define Z_HAS_Type_MEMBER_to_const_lvalue	   1
#	define Z_HAS_Type_MEMBER_to_const_rvalue	   1
#	define Z_HAS_Type_MEMBER_to_const_volatile_lvalue  1
#	define Z_HAS_Type_MEMBER_to_const_volatile_rvalue  1
#	define Z_HAS_Type_MEMBER_to_lvalue		   1
#	define Z_HAS_Type_MEMBER_to_rvalue		   1
#	define Z_HAS_Type_MEMBER_to_volatile_lvalue	   1
#	define Z_HAS_Type_MEMBER_to_volatile_rvalue	   1
#endif

#if Z_DIALECT_HAS(CPP17, NOEXCEPT_AS_PART_OF_THE_FUNCTION_TYPE)
#	define Z_HAS_TypeIsNoexcept		 1
#	define Z_HAS_TypeAddNoexcept		 1
#	define Z_HAS_TypeRemoveNoexcept		 1
#	define Z_HAS_Type_MEMBER_is_noexcept	 1
#	define Z_HAS_Type_MEMBER_add_noexcept	 1
#	define Z_HAS_Type_MEMBER_remove_noexcept 1
#endif

#if Z_DIALECT_HAS(CPP11, RVALUE_REFERENCE)
#	define Z_HAS_TypeAddRValueReference	      1
#	define Z_HAS_TypeToRValueReference	      1
#	define Z_HAS_Type_MEMBER_add_rvalue_reference 1
#	define Z_HAS_Type_MEMBER_to_rvalue_reference  1
#endif

/*--------------------------------------------------------------------.
| Components that require compiler built-in traits to be implemented. |
| There are no known workarounds.				      |
'====================================================================*/

#if Z_COMPILER_HAS_TRAIT(TYPE_HAS_VIRTUAL_DESTRUCTOR)
#	define Z_HAS_TypeHasVirtualDestructor		1
#	define Z_HAS_Type_MEMBER_has_virtual_destructor 1
#endif

#if Z_COMPILER_HAS_TRAIT(TYPE_IS_ABSTRACT)
#	define Z_HAS_TypeIsAbstract	     1
#	define Z_HAS_Type_MEMBER_is_abstract 1
#endif

#if Z_COMPILER_HAS_TRAIT(TYPE_IS_AGGREGATE)
#	define Z_HAS_TypeIsAggregate	      1
#	define Z_HAS_Type_MEMBER_is_aggregate 1
#endif

#if Z_COMPILER_HAS_TRAIT(TYPE_IS_ASSIGNABLE)
#	define Z_HAS_TypeIsAssignable 1
#endif

#if Z_COMPILER_HAS_TRAIT(TYPE_IS_BASE)
#	define Z_HAS_TypeIsBase 1
#endif

#if Z_COMPILER_HAS_TRAIT(TYPE_IS_CONVERTIBLE)
#	define Z_HAS_TypeIsConvertible 1
#endif

#if Z_COMPILER_HAS_TRAIT(TYPE_IS_EMPTY)
#	define Z_HAS_TypeIsEmpty	  1
#	define Z_HAS_Type_MEMBER_is_empty 1
#endif

#if Z_COMPILER_HAS_TRAIT(TYPE_IS_FINAL)
#	define Z_HAS_TypeIsFinal	  1
#	define Z_HAS_Type_MEMBER_is_final 1
#endif

#if Z_COMPILER_HAS_TRAIT(TYPE_IS_INTERFACE_CLASS)
#	define Z_HAS_TypeIsInterfaceClass	    1
#	define Z_HAS_Type_MEMBER_is_interface_class 1
#endif

#if Z_COMPILER_HAS_TRAIT(TYPE_IS_LITERAL)
#	define Z_HAS_TypeIsLiteral	    1
#	define Z_HAS_Type_MEMBER_is_literal 1
#endif

#if Z_COMPILER_HAS_TRAIT(TYPE_IS_NOTHROW_ASSIGNABLE)
#	define Z_HAS_TypeIsNothrowAssignable 1
#endif

#if Z_COMPILER_HAS_TRAIT(TYPE_IS_POD)
#	define Z_HAS_TypeIsPOD		1
#	define Z_HAS_Type_MEMBER_is_pod 1
#endif

#if Z_COMPILER_HAS_TRAIT(TYPE_IS_POLYMORPHIC)
#	define Z_HAS_TypeIsPolymorphic		1
#	define Z_HAS_Type_MEMBER_is_polymorphic 1
#endif

#if Z_COMPILER_HAS_TRAIT(TYPE_IS_TRIVIALLY_ASSIGNABLE)
#	define Z_HAS_TypeIsTriviallyAssignable 1
#endif

#if Z_COMPILER_HAS_TRAIT(TYPE_IS_TRIVIALLY_COPY_ASSIGNABLE)
#	define Z_HAS_TypeIsTriviallyCopyAssignable	      1
#	define Z_HAS_Type_MEMBER_is_trivially_copy_assignable 1
#endif

#if Z_COMPILER_HAS_TRAIT(TYPE_IS_TRIVIALLY_COPY_CONSTRUCTIBLE)
#	define Z_HAS_TypeIsTriviallyCopyConstructible		 1
#	define Z_HAS_Type_MEMBER_is_trivially_copy_constructible 1
#endif

#if Z_COMPILER_HAS_TRAIT(TYPE_IS_TRIVIALLY_COPYABLE)
#	define Z_HAS_TypeIsTriviallyCopyable	       1
#	define Z_HAS_Type_MEMBER_is_trivially_copyable 1
#endif

#if Z_COMPILER_HAS_TRAIT(TYPE_IS_TRIVIALLY_DEFAULT_CONSTRUCTIBLE)
#	define Z_HAS_TypeIsTriviallyDefaultConstructible	    1
#	define Z_HAS_Type_MEMBER_is_trivially_default_constructible 1
#endif

#if Z_COMPILER_HAS_TRAIT(TYPE_IS_TRIVIALLY_DESTRUCTIBLE)
#	define Z_HAS_TypeIsTriviallyDestructible	   1
#	define Z_HAS_Type_MEMBER_is_trivially_destructible 1
#endif

#if Z_COMPILER_HAS_TRAIT(TYPE_IS_UNION)
#	define Z_HAS_TypeIsUnion	  1
#	define Z_HAS_Type_MEMBER_is_union 1
#endif

#if Z_COMPILER_HAS_TRAIT(TYPE_UNDERLYING_TYPE)
#	define Z_HAS_TypeUnderlyingType		 1
#	define Z_HAS_Type_MEMBER_underlying_type 1
#endif

/*------------------------------------------------------------------------.
| Components that use built-in compiler traits if available. If not, they |
| are implemented using workarounds that require some C++11 features.	  |
'========================================================================*/

#if Z_COMPILER_HAS_TRAIT(TYPE_IS_COMPLETE) || Z_DIALECT_HAS(CPP11, EXPRESSION_SFINAE)
#	define Z_HAS_TypeIsComplete 1
#endif

#if	Z_COMPILER_HAS_TRAIT(TYPE_IS_DEFAULT_CONSTRUCTIBLE) || \
	(Z_DIALECT_HAS(CPP11, EXPRESSION_SFINAE) && Z_DIALECT_HAS_SPECIFIER(CPP11, DECLTYPE)) // No existe TYPE_IS_DEFAULT_CONSTRUCTIBLE

#	define Z_HAS_TypeIsDefaultConstructible		  1
#	define Z_HAS_Type_MEMBER_is_default_constructible 1
#endif

#if Z_COMPILER_HAS_TRAIT(TYPE_IS_ENUMERATION) || Z_DIALECT_HAS(CPP11, EXPRESSION_SFINAE)
#	define Z_HAS_TypeIsEnumeration		1
#	define Z_HAS_Type_MEMBER_is_enumeration 1
#endif

/*---------------------------------------------------------------------.
| Components that require compiler built-in traits in addition to some |
| C++11 features to be implemented. There are no known workarounds.    |
'=====================================================================*/

#if Z_DIALECT_HAS(CPP11, VARIADIC_TEMPLATE)

#	if Z_COMPILER_HAS_TRAIT(TYPE_IS_CONSTRUCTIBLE)
#		define Z_HAS_TypeIsConstructible 1
#	endif

#	if Z_COMPILER_HAS_TRAIT(TYPE_IS_NOTHROW_CONSTRUCTIBLE)
#		define Z_HAS_TypeIsNothrowConstructible 1
#	endif

#	if Z_COMPILER_HAS_TRAIT(TYPE_IS_TRIVIALLY_CONSTRUCTIBLE)
#		define Z_HAS_TypeIsTriviallyConstructible 1
#	endif

#endif

/*---------------------------------------------------------------.
| Components that require some C++11 features to be implemented. |
'===============================================================*/

#ifdef Z_NULLPTR
#	define Z_HAS_TypeIsNullPtr	    1
#	define Z_HAS_Type_MEMBER_is_nullptr 1
#endif

#if Z_DIALECT_HAS(CPP11, EXTENDED_VARIADIC_TEMPLATE_TEMPLATE_PARAMETERS)
#	define Z_HAS_TypeIsTemplate	     1
#	define Z_HAS_Type_MEMBER_is_template 1
#endif

#if Z_HAS(TypeList)
#	define Z_HAS_TypeParameter	    1
#	define Z_HAS_TypeParameters	    1
#	define Z_HAS_Type_MEMBER_parameters 1
#endif

#if Z_DIALECT_HAS(CPP11, TYPE_ALIAS_TEMPLATE)
#	define Z_HAS_Type_MEMBER_add_member_pointer 1
#	define Z_HAS_Type_MEMBER_to_member_pointer  1
#endif

#if Z_DIALECT_HAS(CPP11, TYPE_ALIAS_TEMPLATE) && Z_HAS(TypeList)
#	define Z_HAS_Type_MEMBER_parameter 1
#endif

/*-----------------------------------------------.
| Components that require some C++14 features in |
| addition to compiler magic to be implemented.  |
'===============================================*/

#if	Z_COMPILER_HAS_MAGIC_CONSTANT(MANGLED_FUNCTION_NAME) && \
	Z_DIALECT_HAS(CPP14, CONSTEXPR_FUNCTION)

#	define Z_HAS_Type_MEMBER_string	     1
#	define Z_HAS_Type_MEMBER_string_size 1
#	define Z_HAS_Type_MEMBER_fnv0_32     1
#	define Z_HAS_Type_MEMBER_fnv1_32     1
#	define Z_HAS_Type_MEMBER_fnv1a_32    1

#	ifdef Z_UINT64
#		define Z_HAS_Type_MEMBER_fnv0_64  1
#		define Z_HAS_Type_MEMBER_fnv1_64  1
#		define Z_HAS_Type_MEMBER_fnv1a_64 1
#	endif
#endif

/*--------------------------------------------------------.
| Components that are only available in Objective-C++ and |
| that require some C++11 features to be implemented.	  |
'========================================================*/

#if Z_LANGUAGE_INCLUDES(OBJECTIVE_CPP) && Z_DIALECT_HAS(CPP11, EXPRESSION_SFINAE)
#	define Z_HAS_TypeIsObjectiveCInstance			 1
#	define Z_HAS_TypeIsObjectiveCInstancePointer		 1
#	define Z_HAS_Type_MEMBER_is_objective_c_instance	 1
#	define Z_HAS_Type_MEMBER_is_objective_c_instance_pointer 1
#endif

/*-------------------------------------------------------------------.
| Aliases that are available only if the language supports template  |
| aliases and the components to which they refer are also available. |
'===================================================================*/

#if Z_DIALECT_HAS(CPP11, TYPE_ALIAS_TEMPLATE)
#	define Z_HAS_type_add_const		     1
#	define Z_HAS_type_add_const_volatile	     1
#	define Z_HAS_type_add_lvalue_reference	     1
#	define Z_HAS_type_add_member_pointer	     1
#	define Z_HAS_type_add_pointer		     1
#	define Z_HAS_type_add_volatile		     1
#	define Z_HAS_type_class_type		     1
#	define Z_HAS_type_element_type		     1
#	define Z_HAS_type_indirectee_type	     1
#	define Z_HAS_type_pointee_type		     1
#	define Z_HAS_type_referencee_type	     1
#	define Z_HAS_type_remove_array		     1
#	define Z_HAS_type_remove_const		     1
#	define Z_HAS_type_remove_const_this	     1
#	define Z_HAS_type_remove_const_volatile	     1
#	define Z_HAS_type_remove_const_volatile_this 1
#	define Z_HAS_type_remove_indirection	     1
#	define Z_HAS_type_remove_member_pointer	     1
#	define Z_HAS_type_remove_pointer	     1
#	define Z_HAS_type_remove_reference	     1
#	define Z_HAS_type_remove_this		     1
#	define Z_HAS_type_remove_volatile	     1
#	define Z_HAS_type_remove_volatile_this	     1
#	define Z_HAS_type_return_type		     1
#	define Z_HAS_type_to_const		     1
#	define Z_HAS_type_to_const_volatile	     1
#	define Z_HAS_type_to_forwardable	     1
#	define Z_HAS_type_to_function		     1
#	define Z_HAS_type_to_lvalue_reference	     1
#	define Z_HAS_type_to_member_pointer	     1
#	define Z_HAS_type_to_opaque		     1
#	define Z_HAS_type_to_pointer		     1
#	define Z_HAS_type_to_signed		     1
#	define Z_HAS_type_to_unqualified	     1
#	define Z_HAS_type_to_unsigned		     1
#	define Z_HAS_type_to_volatile		     1
#	define Z_HAS_type_to_wrap		     1

#	if Z_DIALECT_HAS(CPP11, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)
#		define Z_HAS_type_add_const_lvalue	    1
#		define Z_HAS_type_add_const_rvalue	    1
#		define Z_HAS_type_add_const_volatile_lvalue 1
#		define Z_HAS_type_add_const_volatile_rvalue 1
#		define Z_HAS_type_add_lvalue		    1
#		define Z_HAS_type_add_rvalue		    1
#		define Z_HAS_type_add_volatile_lvalue	    1
#		define Z_HAS_type_add_volatile_rvalue	    1
#		define Z_HAS_type_to_const_lvalue	    1
#		define Z_HAS_type_to_const_rvalue	    1
#		define Z_HAS_type_to_const_volatile_lvalue  1
#		define Z_HAS_type_to_const_volatile_rvalue  1
#		define Z_HAS_type_to_lvalue		    1
#		define Z_HAS_type_to_rvalue		    1
#		define Z_HAS_type_to_volatile_lvalue	    1
#		define Z_HAS_type_to_volatile_rvalue	    1
#	endif

#	if Z_DIALECT_HAS(CPP11, RVALUE_REFERENCE)
#		define Z_HAS_type_add_rvalue_reference 1
#		define Z_HAS_type_to_rvalue_reference  1
#	endif

#	if Z_HAS_MEMBER(Type, parameters)
#		define Z_HAS_type_parameters 1
#	endif

#	if Z_HAS_MEMBER(Type, underlying_type)
#		define Z_HAS_type_underlying_type 1
#	endif

#	if Z_HAS_MEMBER(Type, parameter)
#		define Z_HAS_type_parameter 1
#	endif
#endif

namespace Zeta {

	template <class a, class b> struct TypeIsSame : False {};

	template <class t> struct TypeIsSame<t, t> : True {};

#	if Z_HAS(TypeIsAssignable)
		template <class t, class from_type> struct TypeIsAssignable {
			enum {value = Z_COMPILER_TRAIT(TYPE_IS_ASSIGNABLE)(t, from_type)};
		};
#	endif

#	if Z_HAS(TypeIsBase)
		template <class t, class of_type> struct TypeIsBase {
			enum {value = Z_COMPILER_TRAIT(TYPE_IS_BASE)(t, of_type)};
		};
#	endif

#	if Z_DIALECT_HAS(CPP11, EXPRESSION_SFINAE) && Z_DIALECT_HAS_SPECIFIER(CPP11, DECLTYPE)
		template <class t, class call_prototype, class = Maybe<> > struct TypeIsCallable : False {};

#		if Z_DIALECT_HAS(CPP11, VARIADIC_TEMPLATE)

			template <class t, class r, class... p>
			struct TypeIsCallable<t, r(p...), Maybe<TypeIsSame<r, decltype(fake<t>()(fake<p>()...))>::value> > : True {};

			template <class t, class r, class... p>
			struct TypeIsCallable<t, r(p..., ...), Maybe<TypeIsSame<r, decltype(fake<t>()(fake<p>()...))>::value> > : True {};

#		else
#			define Z_z_ARGUMENT(index) fake<p##index>()

#			define Z_z_SPECIALIZATION_PAIR(arity)										       \
																	       \
				template <class t, class r Z_IF(arity)(Z_COMMA) Z_APPEND_INDEX_FOR_##arity(class p, Z_COMMA)>		       \
				struct TypeIsCallable<											       \
					t, r(Z_APPEND_INDEX_FOR_##arity(p, Z_COMMA)),							       \
					Maybe<TypeIsSame<r, decltype(fake<t>()(Z_CALL_WITH_INDEX_FOR_##arity(Z_z_ARGUMENT, Z_COMMA)))>::value> \
				> : True {};												       \
																	       \
				template <class t, class r Z_IF(arity)(Z_COMMA) Z_APPEND_INDEX_FOR_##arity(class p, Z_COMMA)>		       \
				struct TypeIsCallable<											       \
					t, r(Z_APPEND_INDEX_FOR_##arity(p, Z_COMMA) Z_IF(arity)(Z_COMMA) ...),				       \
					Maybe<TypeIsSame<r, decltype(fake<t>()(Z_CALL_WITH_INDEX_FOR_##arity(Z_z_ARGUMENT, Z_COMMA)))>::value> \
				> : True {};

			Z_CALL_WITH_INDEX_FOR_32(Z_z_SPECIALIZATION_PAIR, Z_EMPTY)
#			undef Z_z_SPECIALIZATION_PAIR
#			undef Z_z_ARGUMENT
#		endif
#	endif

#	if Z_COMPILER_HAS_TRAIT(TYPE_IS_COMPLETE)
		template <class t, SInt at_line> struct TypeIsComplete {
			enum {value = Z_COMPILER_TRAIT(TYPE_IS_COMPLETE)(t)};
		};

#	elif Z_DIALECT_HAS(CPP11, EXPRESSION_SFINAE)
		namespace {
			template <class t, SInt at_line, class = Maybe<> >
			struct TypeIsComplete : False {};

			template <class t, SInt at_line>
			struct TypeIsComplete<t, at_line, Maybe<!!sizeof(t)> > : True {};
		}
#	endif

#	if Z_HAS(TypeIsConvertible)
		template <class t, class to_type> struct TypeIsConvertible {
			enum {value = Z_COMPILER_TRAIT(TYPE_IS_CONVERTIBLE)(t, to_type)};
		};
#	endif

#	if Z_HAS(TypeIsConstructible)
		template <class t, class... parameters> struct TypeIsConstructible {
			enum {value = Z_COMPILER_TRAIT(TYPE_IS_CONSTRUCTIBLE)(t, parameters...)};
		};
#	endif

#	if Z_HAS(TypeIsNothrowAssignable)
		template <class t, class from_type> struct TypeIsNothrowAssignable {
			enum {value = Z_COMPILER_TRAIT(TYPE_IS_NOTHROW_ASSIGNABLE)(t, from_type)};
		};
#	endif

#	if Z_HAS(TypeIsNothrowConstructible)
		template <class t, class... parameters> struct TypeIsNothrowConstructible {
			enum {value = Z_COMPILER_TRAIT(TYPE_IS_NOTHROW_CONSTRUCTIBLE)(t, parameters...)};
		};
#	endif

#	if Z_HAS(TypeIsTriviallyAssignable)
		template <class t, class from_type> struct TypeIsTriviallyAssignable {
			enum {value = Z_COMPILER_TRAIT(TYPE_IS_TRIVIALLY_ASSIGNABLE)(t, from_type)};
		};
#	endif

#	if Z_HAS(TypeIsTriviallyConstructible)
		template <class t, class... parameters> struct TypeIsTriviallyConstructible {
			enum {value = Z_COMPILER_TRAIT(TYPE_IS_TRIVIALLY_CONSTRUCTIBLE)(t, parameters...)};
		};
#	endif

	template <class t> struct TypeRemovePointer		       {typedef t type;};
	template <class t> struct TypeRemovePointer<t*		     > {typedef t type;};
	template <class t> struct TypeRemovePointer<t* const	     > {typedef t type;};
	template <class t> struct TypeRemovePointer<t* const volatile> {typedef t type;};
	template <class t> struct TypeRemovePointer<t*	     volatile> {typedef t type;};

	template <class t, class klass> struct TypeAddMemberPointer;

	template <class t, class c> struct TypeAddMemberPointer {typedef t c::*type;};

	template <class c> struct TypeAddMemberPointer<		      void, c> {typedef NaT type;};
	template <class c> struct TypeAddMemberPointer<const	      void, c> {typedef NaT type;};
	template <class c> struct TypeAddMemberPointer<const volatile void, c> {typedef NaT type;};
	template <class c> struct TypeAddMemberPointer<	     volatile void, c> {typedef NaT type;};

	template <class t, class c> struct TypeAddMemberPointer<t&, c> {typedef NaT type;};

#	if Z_DIALECT_HAS(CPP11, RVALUE_REFERENCE)
		template <class t, class c> struct TypeAddMemberPointer<t&&, c> {typedef NaT type;};
#	endif
}

// MARK: - Tests

#if !Z_COMPILER_HAS_TRAIT(TYPE_IS_DEFAULT_CONSTRUCTIBLE) && Z_HAS(TypeIsDefaultConstructible)

	namespace Zeta {namespace ZetaDetail {namespace Type {namespace Tests {

		template <class t, class = Maybe<> > struct IsDefaultConstructible : False {};

		template <class t> struct IsDefaultConstructible<t, Maybe<TypeIsSame<t, decltype(t())>::value> > : True {};
	}}}}

#endif

// MARK: - Abstract
//-----------------------------------------------------------------------.
// El namespace Abstract contiene una serie de traits que describen      |
// las propiedades básicas de los tipos, además de las transformaciones  |
// para modificar tipos no cualificados a sus versiones cualificadas.	 |
// Los traits de este namespace son utilizados como clases base que son  |
// mezcladas con los mixins del namespace Mixins, los cuales aportan la  |
// información y las transformaciones relativas a los cualificadores y a |
// la clase de objeto.							 |
//-----------------------------------------------------------------------'

namespace Zeta {namespace ZetaDetail {namespace Type {namespace Abstract {

	// MARK: - Abstract: Invalid type

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
			is_bool			      = false,
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
			number_set	  = 0
		};

#		if Z_HAS_MEMBER(Type, has_virtual_destructor)
			enum {has_virtual_destructor = false};
#		endif

#		if Z_HAS_MEMBER(Type, is_abstract)
			enum {is_abstract = false};
#		endif

#		if Z_HAS_MEMBER(Type, is_aggregate)
			enum {is_aggregate = false};
#		endif

#		if Z_HAS_MEMBER(Type, is_default_constructible)
			enum {is_default_constructible = false};
#		endif

#		if Z_HAS_MEMBER(Type, is_empty)
			enum {is_empty = false};
#		endif

#		if Z_HAS_MEMBER(Type, is_enumeration)
			enum {is_enumeration = false};
#		endif

#		if Z_HAS_MEMBER(Type, is_final)
			enum {is_final = false};
#		endif

#		if Z_HAS_MEMBER(Type, is_interface_class)
			enum {is_interface_class = false};
#		endif

#		if Z_HAS_MEMBER(Type, is_literal)
			enum {is_literal = false};
#		endif

#		if Z_HAS_MEMBER(Type, is_noexcept)
			enum {is_noexcept = false};
#		endif

#		if Z_HAS_MEMBER(Type, is_nullptr)
			enum {is_nullptr = false};
#		endif

#		if Z_HAS_MEMBER(Type, is_pod)
			enum {is_pod = false};
#		endif

#		if Z_HAS_MEMBER(Type, is_polymorphic)
			enum {is_polymorphic = false};
#		endif

#		if Z_HAS_MEMBER(Type, is_template)
			enum {is_template = false};
#		endif

#		if Z_HAS_MEMBER(Type, is_trivially_copy_assignable)
			enum {is_trivially_copy_assignable = false};
#		endif

#		if Z_HAS_MEMBER(Type, is_trivially_copy_constructible)
			enum {is_trivially_copy_constructible = false};
#		endif

#		if Z_HAS_MEMBER(Type, is_trivially_copyable)
			enum {is_trivially_copyable = false};
#		endif

#		if Z_HAS_MEMBER(Type, is_trivially_default_constructible)
			enum {is_trivially_default_constructible = false};
#		endif

#		if Z_HAS_MEMBER(Type, is_trivially_destructible)
			enum {is_trivially_destructible = false};
#		endif

#		if Z_HAS_MEMBER(Type, is_union)
			enum {is_union = false};
#		endif

#		if Z_LANGUAGE_INCLUDES(OBJECTIVE_CPP) && Z_DIALECT_HAS(CPP11, EXPRESSION_SFINAE)
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
		typedef NaT remove_array; // TODO
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

#		if Z_DIALECT_HAS(CPP11, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)
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

#		if Z_DIALECT_HAS(CPP17, NOEXCEPT_AS_PART_OF_THE_FUNCTION_TYPE)
			typedef NaT add_noexcept;
			typedef NaT remove_noexcept;
#		endif

#		if Z_DIALECT_HAS(CPP11, RVALUE_REFERENCE)
			typedef NaT add_rvalue_reference;
			typedef NaT to_rvalue_reference;
#		endif

#		if Z_HAS_MEMBER(Type, remove_noexcept)
#		endif

#		if Z_HAS_MEMBER(Type, parameters)
			typedef NaT parameters;
#		endif

#		if Z_HAS_MEMBER(Type, underlying_type)
			typedef NaT underlying_type;
#		endif

#		if Z_DIALECT_HAS(CPP11, TYPE_ALIAS_TEMPLATE)
			template <class klass> using add_member_pointer = NaT;
			template <class klass> using to_member_pointer	= NaT;
#		endif

#		if Z_HAS_MEMBER(Type, parameter)
			template <zuint index> using parameter = NaT;
#		endif
	};

	// MARK: - Abstract: Base

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

#		if Z_HAS_MEMBER(Type, is_literal)
			enum {is_literal = true};
#		endif

#		if Z_HAS_MEMBER(Type, is_trivially_copy_constructible)
			enum {is_trivially_copy_constructible = true};
#		endif

#		if Z_HAS_MEMBER(Type, is_trivially_destructible)
			enum {is_trivially_destructible = true};
#		endif

		//----------------------------------------------.
		// Unlike the standard C++ library, Z considers |
		// the following to be "true" for references:	|
		//----------------------------------------------'

#		if Z_HAS_MEMBER(Type, is_default_constructible)
			enum {is_default_constructible = true};
#		endif

#		if Z_HAS_MEMBER(Type, is_trivially_copy_assignable)
			enum {is_trivially_copy_assignable = true};
#		endif

#		if Z_HAS_MEMBER(Type, is_trivially_copyable)
			enum {is_trivially_copyable = true};
#		endif

#		if Z_HAS_MEMBER(Type, is_trivially_default_constructible)
			enum {is_trivially_default_constructible = true};
#		endif
	};

	struct Number : Simple {
		enum {	is_arithmetic  = true,
			is_fundamental = true,
			is_number      = true,
			is_scalar      = true
		};

#		if Z_HAS_MEMBER(Type, is_pod)
			enum {is_pod = true};
#		endif
	};

	struct Integral : Number {
		enum {	is_exact    = true,
			is_integral = true
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

#		if Z_HAS_MEMBER(Type, is_pod)
			enum {is_pod = true};
#		endif
	};

	// MARK: - Abstract: Standard and fixed C/C++ fundamental types

	struct Void : Valid {
		enum {	is_fundamental = true,
			is_void	       = true
		};

#		if Z_HAS_MEMBER(Type, is_literal)
			enum {is_literal = true};
#		endif

		typedef void type;
	};

	struct Char : Z_TERNARY(Z_CHAR_IS_SIGNED)(Integer, Natural) {
		enum {	fundamental	  = Z_CHAR_FUNDAMENTAL,
			fixed_fundamental = Z_CHAR_FIXED_FUNDAMENTAL
		};
		enum {	minimum = Z_CHAR_MINIMUM,
			maximum = Z_CHAR_MAXIMUM
		};

		typedef zchar  type;
		typedef zuchar to_unsigned;
		typedef zschar to_signed;
	};

#	define Z_z_STD_INTEGRAL(NAME, Name, name)				  \
										  \
		struct U##Name : Natural {					  \
			enum {	fundamental	  = Z_U##NAME##_FUNDAMENTAL,	  \
				fixed_fundamental = Z_U##NAME##_FIXED_FUNDAMENTAL \
			};							  \
			enum {maximum = Z_U##NAME##_MAXIMUM};			  \
										  \
			typedef zu##name type;					  \
			typedef zu##name to_unsigned;				  \
			typedef zs##name to_signed;				  \
		};								  \
										  \
		struct S##Name : Integer {					  \
			enum {	fundamental	  = Z_S##NAME##_FUNDAMENTAL,	  \
				fixed_fundamental = Z_S##NAME##_FIXED_FUNDAMENTAL \
			};							  \
			enum {	minimum = Z_S##NAME##_MINIMUM,			  \
				maximum = Z_S##NAME##_MAXIMUM			  \
			};							  \
										  \
			typedef zs##name type;					  \
			typedef zu##name to_unsigned;				  \
			typedef zs##name to_signed;				  \
		};

	Z_z_STD_INTEGRAL(CHAR,	Char,  char )
	Z_z_STD_INTEGRAL(SHORT, Short, short)
	Z_z_STD_INTEGRAL(INT,	Int,   int  )
	Z_z_STD_INTEGRAL(LONG,	Long,  long )

#	ifdef Z_LLONG
		Z_z_STD_INTEGRAL(LLONG, LLong, llong)
#	endif

#	undef Z_z_STD_INTEGRAL

#	ifdef Z_BOOL

		struct Bool : Integral {
			enum {is_bool = true};

			typedef zbool type;
		};

#	endif

#	if Z_DIALECT_HAS_TYPE(CPP98, WCHAR_T)

		struct WChar : Natural { // TODO: Can be Integer
			enum {fundamental = Z_FUNDAMENTAL_WCHAR};

			typedef wchar_t type;
		};

#	endif

#	define Z_z_STD_FIXED_CHARACTER(bits)				      \
		struct Char##bits : Natural {				      \
			enum {	fundamental	  = Z_FUNDAMENTAL_CHAR##bits, \
				fixed_fundamental = Z_FUNDAMENTAL_UINT##bits  \
			};						      \
									      \
			typedef char##bits##_t type;			      \
			typedef char##bits##_t to_unsigned;		      \
		};

#	if Z_DIALECT_HAS_TYPE(CPP20, CHAR8_T)
		Z_z_STD_FIXED_CHARACTER(8)
#	endif

#	if Z_DIALECT_HAS_TYPE(CPP11, CHAR16_T)
		Z_z_STD_FIXED_CHARACTER(16)
#	endif

#	if Z_DIALECT_HAS_TYPE(CPP11, CHAR32_T)
		Z_z_STD_FIXED_CHARACTER(32)
#	endif

#	undef Z_z_STD_FIXED_CHARACTER

#	define Z_z_FIXED_NATURAL(bits)								  \
		struct UInt##bits : Natural {							  \
			enum {	fundamental	  = Z_UINT##bits##_FUNDAMENTAL,			  \
				fixed_fundamental = Z_UINT##bits##_FIXED_FUNDAMENTAL		  \
			};									  \
												  \
			typedef zuint##bits type;						  \
			typedef zuint##bits to_unsigned;					  \
			Z_IF(Z_DATA_MODEL_HAS_TYPE(SINT##bits))(typedef zsint##bits to_signed;)	  \
												  \
			static Z_CT(CPP11) zuint##bits maximum() {return Z_UINT##bits##_MAXIMUM;} \
			static Z_CT(CPP11) zuint##bits minimum() {return Z_UINT##bits(0);}	  \
		};

#	define Z_z_FIXED_INTEGER(bits)								  \
		struct SInt##bits : Integer {							  \
			enum {	fundamental	  = Z_SINT##bits##_FUNDAMENTAL,			  \
				fixed_fundamental = Z_SINT##bits##_FIXED_FUNDAMENTAL		  \
			};									  \
												  \
			typedef zsint##bits type;						  \
			typedef zsint##bits to_signed;						  \
			Z_IF(Z_DATA_MODEL_HAS_TYPE(UINT##bits))(typedef zuint##bits to_unsigned;) \
												  \
			static Z_CT(CPP11) zsint##bits maximum() {return Z_SINT##bits##_MAXIMUM;} \
			static Z_CT(CPP11) zsint##bits minimum() {return Z_SINT##bits##_MINIMUM;} \
		};

#	if defined(Z_UINT8) && Z_UINT8_FUNDAMENTAL == Z_FUNDAMENTAL_UINT8
		Z_z_FIXED_NATURAL(8)
#	endif

#	if defined(Z_SINT8) && Z_SINT8_FUNDAMENTAL == Z_FUNDAMENTAL_SINT8
		Z_z_FIXED_INTEGER(8)
#	endif

#	if defined(Z_UINT16) && Z_UINT16_FUNDAMENTAL == Z_FUNDAMENTAL_UINT16
		Z_z_FIXED_NATURAL(16)
#	endif

#	if defined(Z_SINT16) && Z_SINT16_FUNDAMENTAL == Z_FUNDAMENTAL_SINT16
		Z_z_FIXED_INTEGER(16)
#	endif

#	if defined(Z_UINT24) && Z_UINT24_FUNDAMENTAL == Z_FUNDAMENTAL_UINT24
		Z_z_FIXED_NATURAL(24)
#	endif

#	if defined(Z_SINT24) && Z_SINT24_FUNDAMENTAL == Z_FUNDAMENTAL_SINT24
		Z_z_FIXED_INTEGER(24)
#	endif

#	if defined(Z_UINT32) && Z_UINT32_FUNDAMENTAL == Z_FUNDAMENTAL_UINT32
		Z_z_FIXED_NATURAL(32)
#	endif

#	if defined(Z_SINT32) && Z_SINT32_FUNDAMENTAL == Z_FUNDAMENTAL_SINT32
		Z_z_FIXED_INTEGER(32)
#	endif

#	if defined(Z_UINT40) && Z_UINT40_FUNDAMENTAL == Z_FUNDAMENTAL_UINT40
		Z_z_FIXED_NATURAL(40)
#	endif

#	if defined(Z_SINT40) && Z_SINT40_FUNDAMENTAL == Z_FUNDAMENTAL_SINT40
		Z_z_FIXED_INTEGER(40)
#	endif

#	if defined(Z_UINT48) && Z_UINT48_FUNDAMENTAL == Z_FUNDAMENTAL_UINT48
		Z_z_FIXED_NATURAL(48)
#	endif

#	if defined(Z_SINT48) && Z_SINT48_FUNDAMENTAL == Z_FUNDAMENTAL_SINT48
		Z_z_FIXED_INTEGER(48)
#	endif

#	if defined(Z_UINT56) && Z_UINT56_FUNDAMENTAL == Z_FUNDAMENTAL_UINT56
		Z_z_FIXED_NATURAL(56)
#	endif

#	if defined(Z_SINT56) && Z_SINT56_FUNDAMENTAL == Z_FUNDAMENTAL_SINT56
		Z_z_FIXED_INTEGER(56)
#	endif

#	if defined(Z_UINT64) && Z_UINT64_FUNDAMENTAL == Z_FUNDAMENTAL_UINT64
		Z_z_FIXED_NATURAL(64)
#	endif

#	if defined(Z_SINT64) && Z_SINT64_FUNDAMENTAL == Z_FUNDAMENTAL_SINT64
		Z_z_FIXED_INTEGER(64)
#	endif

#	if defined(Z_UINT128) && Z_UINT128_FUNDAMENTAL == Z_FUNDAMENTAL_UINT128
		Z_z_FIXED_NATURAL(128)
#	endif

#	if defined(Z_SINT128) && Z_SINT128_FUNDAMENTAL == Z_FUNDAMENTAL_SINT128
		Z_z_FIXED_INTEGER(128)
#	endif

#	undef Z_z_FIXED_NATURAL
#	undef Z_z_FIXED_INTEGER

#	define Z_z_REAL(NAME, Name, name)								    \
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
			typedef z##name type;								    \
			typedef z##name to_signed;							    \
													    \
			static Z_CT(CPP11) z##name epsilon	   () {return Z_##NAME##_EPSILON;}	    \
			static Z_CT(CPP11) z##name maximum	   () {return Z_##NAME##_MAXIMUM;}	    \
			static Z_CT(CPP11) z##name minimum	   () {return Z_##NAME##_MINIMUM;}	    \
			static Z_CT(CPP11) z##name denormal_minimum() {return Z_##NAME##_DENORMAL_MINIMUM;} \
		};

#	ifdef Z_FLOAT
		Z_z_REAL(FLOAT, Float, float)
#	endif

#	ifdef Z_DOUBLE
		Z_z_REAL(DOUBLE, Double, double)
#	endif

#	ifdef Z_LDOUBLE
		Z_z_REAL(LDOUBLE, LDouble, ldouble)
#	endif

#	ifdef Z_FLOAT16
		Z_z_REAL(FLOAT16, Float16, float16)
#	endif

#	ifdef Z_FLOAT32
		Z_z_REAL(FLOAT32, Float32, float32)
#	endif

#	ifdef Z_FLOAT64
		Z_z_REAL(FLOAT64, Float64, float64)
#	endif

#	ifdef Z_FLOAT128
		Z_z_REAL(FLOAT128, Float128, float128)
#	endif

#	ifdef Z_FLOAT32X
		Z_z_REAL(FLOAT32X, Float32x, float32x)
#	endif

#	ifdef Z_FLOAT64X
		Z_z_REAL(FLOAT64X, Float64x, float64x)
#	endif

#	ifdef Z_FLOAT128X
		Z_z_REAL(FLOAT128X, Float128x, float128x)
#	endif

#	ifdef Z_DECIMAL32
		Z_z_REAL(DECIMAL32, Decimal32, decimal32)
#	endif

#	ifdef Z_DECIMAL64
		Z_z_REAL(DECIMAL64, Decimal64, decimal64)
#	endif

#	ifdef Z_DECIMAL128
		Z_z_REAL(DECIMAL128, Decimal128, decimal128)
#	endif

#	ifdef Z_DECIMAL64X
		Z_z_REAL(DECIMAL64X, Decimal64x, decimal64x)
#	endif

#	ifdef Z_DECIMAL128X
		Z_z_REAL(DECIMAL128X, Decimal128x, decimal128x)
#	endif

#	if defined(Z_BFP16) && Z_BFP16_FUNDAMENTAL == Z_FUNDAMENTAL_BFP16
		Z_z_REAL(BFP16, BFP16, bfp16)
#	endif

#	if defined(Z_BFP32) && Z_BFP32_FUNDAMENTAL == Z_FUNDAMENTAL_BFP32
		Z_z_REAL(BFP32, BFP32, bfp32)
#	endif

#	if defined(Z_BFP64) && Z_BFP64_FUNDAMENTAL == Z_FUNDAMENTAL_BFP64
		Z_z_REAL(BFP64, BFP64, bfp64)
#	endif

#	if defined(Z_BFP128) && Z_BFP128_FUNDAMENTAL == Z_FUNDAMENTAL_BFP128
		Z_z_REAL(BFP128, BFP128, bfp128)
#	endif

#	if defined(Z_DFP32) && Z_DFP32_FUNDAMENTAL == Z_FUNDAMENTAL_DFP32
		Z_z_REAL(DFP32, DFP32, dfp32)
#	endif

#	if defined(Z_DFP64) && Z_DFP64_FUNDAMENTAL == Z_FUNDAMENTAL_DFP64
		Z_z_REAL(DFP64, DFP64, dfp64)
#	endif

#	if defined(Z_DFP128) && Z_DFP128_FUNDAMENTAL == Z_FUNDAMENTAL_DFP128
		Z_z_REAL(DFP128, DFP128, dfp128)
#	endif

#	if defined(Z_X87_DE80) && Z_X87_DE80_FUNDAMENTAL == Z_FUNDAMENTAL_X87_DE80
		Z_z_REAL(X87_DE80, x87_DE80, x87_de80)
#	endif

#	if defined(Z_X87_DE96) && Z_X87_DE96_FUNDAMENTAL == Z_FUNDAMENTAL_X87_DE96
		Z_z_REAL(X87_DE96, x87_DE96, x87_de96)
#	endif

#	if defined(Z_X87_DE128) && Z_X87_DE128_FUNDAMENTAL == Z_FUNDAMENTAL_X87_DE128
		Z_z_REAL(X87_DE128, x87_DE128, x87_de128)
#	endif

#	if defined(Z_IBM_ED) && Z_IBM_ED_FUNDAMENTAL == Z_FUNDAMENTAL_IBM_ED
		Z_z_REAL(IBM_ED, IBM_ED, ibm_ed)
#	endif

#	if defined(Z_BFLOAT16) && Z_BFLOAT16_FUNDAMENTAL == Z_FUNDAMENTAL_BFLOAT16
		Z_z_REAL(BFLOAT16, bfloat16, bfloat16)
#	endif

#	undef Z_z_REAL

#	if Z_HAS_MEMBER(Type, is_nullptr)
		struct NullPtr : PointerLike {
			enum {	is_fundamental	= true,
				is_nullptr = true
			};

			typedef decltype(nullptr) type;
		};
#	endif

	// MARK: - Abstract: Array types

	template <zboolean e, class t> struct Array;

	template <class t> struct Array<false, t> : Storable {
		enum {is_array = true};

		typedef t element_type;
		typedef t remove_array;
	};

	template <class t> struct Array<true, t> : Array<false, t> {
#		if Z_HAS_MEMBER(Type, is_aggregate)
			enum {is_aggregate = true};
#		endif

#		if Z_COMPILER_HAS_TRAIT(TYPE_IS_DEFAULT_CONSTRUCTIBLE) // No existe TYPE_IS_DEFAULT_CONSTRUCTIBLE
			enum {is_default_constructible = Z_COMPILER_TRAIT(TYPE_IS_DEFAULT_CONSTRUCTIBLE)(t)};
#		elif Z_HAS_MEMBER(Type, is_default_constructible)
			enum {is_default_constructible = Tests::IsDefaultConstructible<t>::value};
#		endif

#		if Z_HAS_MEMBER(Type, is_literal)
			enum {is_literal = Z_COMPILER_TRAIT(TYPE_IS_LITERAL)(t)};
#		endif

#		if Z_HAS_MEMBER(Type, is_pod)
			enum {is_pod = Z_COMPILER_TRAIT(TYPE_IS_POD)(t)};
#		endif

#		if Z_HAS_MEMBER(Type, is_trivially_copy_constructible)
			enum {is_trivially_copy_constructible = Z_COMPILER_TRAIT(TYPE_IS_TRIVIALLY_COPY_CONSTRUCTIBLE)(t)};
#		endif

#		if Z_HAS_MEMBER(Type, is_trivially_copyable)
			enum {is_trivially_copyable = Z_COMPILER_TRAIT(TYPE_IS_TRIVIALLY_COPYABLE)(t)};
#		endif

#		if Z_HAS_MEMBER(Type, is_trivially_default_constructible)
			enum {is_trivially_default_constructible = Z_COMPILER_TRAIT(TYPE_IS_TRIVIALLY_DEFAULT_CONSTRUCTIBLE)(t)};
#		endif

#		if Z_HAS_MEMBER(Type, is_trivially_destructible)
			enum {is_trivially_destructible = Z_COMPILER_TRAIT(TYPE_IS_TRIVIALLY_DESTRUCTIBLE)(t)};
#		endif
	};

	template <zboolean e, class t, zusize n> struct SizedArray : Array<e, t> {
		enum {	is_statically_allocatable = true,
			is_sized_array		  = true
		};
		enum {element_count = n};

#		if Z_HAS_MEMBER(Type, is_empty)
			enum {is_empty = (n == 0)};
#		endif

		typedef t type[n];
	};

	template <zboolean e, class t> struct UnsizedArray : Array<e, t> {
		enum {is_unsized_array = true};

#		if Z_HAS_MEMBER(Type, is_empty)
			enum {is_empty = true};
#		endif

		typedef t type[];
	};

	// MARK: - Abstract: Pointer types

	template <class t> struct Pointer : PointerLike {
		enum {	is_indirection = true,
			is_pointer     = true
		};

		typedef t* type;
		typedef t  indirectee_type;
		typedef t  pointee_type;
	};

	template <class t, class c, class m> struct MemberPointer : PointerLike {
		enum {	is_indirection	  = true,
			is_member_pointer = true
		};

		typedef t type;
		typedef c class_type;
		typedef m indirectee_type;
		typedef m pointee_type;
	};

	// MARK: - Abstract: Reference types

	template <class t> struct Reference : Simple {
		enum {	is_indirection = true,
			is_reference   = true
		};

		typedef t indirectee_type;
		typedef t referencee_type;
	};

	template <class t> struct LValueReference : Reference<t> {
		enum {is_lvalue_reference = true};

		typedef t& type;
	};

#	if Z_DIALECT_HAS(CPP11, RVALUE_REFERENCE)
		template <class t> struct RValueReference : Reference<t> {
			enum {is_rvalue_reference = true};

			typedef t&& type;
		};
#	endif

	// MARK: - Abstract: Function types

#	if Z_DIALECT_HAS(CPP17, NOEXCEPT_AS_PART_OF_THE_FUNCTION_TYPE)
		template <zboolean x, class t, class c = Empty> struct Function;

#		define Z_z_NOEXCEPT noexcept(x)

#	else
#		define Z_z_NOEXCEPT
#	endif

#	define Z_z_NORMAL_CONVERSIONS(parameters)				     \
		typedef r to_const	   (parameters) const	       Z_z_NOEXCEPT; \
		typedef r to_const_volatile(parameters) const volatile Z_z_NOEXCEPT; \
		typedef r to_unqualified   (parameters)		       Z_z_NOEXCEPT; \
		typedef r to_volatile	   (parameters)	volatile       Z_z_NOEXCEPT;

#	if Z_DIALECT_HAS(CPP11, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)

#		define Z_z_REFERENCE_CONVERSIONS(parameters)					       \
			typedef r to_const_lvalue	  (parameters) const	      &	 Z_z_NOEXCEPT; \
			typedef r to_const_rvalue	  (parameters) const	      && Z_z_NOEXCEPT; \
			typedef r to_const_volatile_lvalue(parameters) const volatile &	 Z_z_NOEXCEPT; \
			typedef r to_const_volatile_rvalue(parameters) const volatile && Z_z_NOEXCEPT; \
			typedef r to_lvalue		  (parameters)		      &	 Z_z_NOEXCEPT; \
			typedef r to_rvalue		  (parameters)		      && Z_z_NOEXCEPT; \
			typedef r to_volatile_lvalue	  (parameters)	     volatile &	 Z_z_NOEXCEPT; \
			typedef r to_volatile_rvalue	  (parameters)	     volatile && Z_z_NOEXCEPT;

#	else
#		define Z_z_REFERENCE_CONVERSIONS(parameters)
#	endif

#	if Z_DIALECT_HAS(CPP11, VARIADIC_TEMPLATE)

#		if Z_DIALECT_HAS(CPP17, NOEXCEPT_AS_PART_OF_THE_FUNCTION_TYPE)
			template <zboolean x, class r, class... p, class c> struct Function<x, r(p...), c> : c {
				Z_z_NORMAL_CONVERSIONS	 (p...)
				Z_z_REFERENCE_CONVERSIONS(p...)
			};

			template <zboolean x, class r, class... p, class c> struct Function<x, r(p..., ...), c> : c {
				Z_z_NORMAL_CONVERSIONS	 (p... Z_COMMA ...)
				Z_z_REFERENCE_CONVERSIONS(p... Z_COMMA ...)
			};
#		endif

#		if Z_DIALECT_HAS(CPP17, NOEXCEPT_AS_PART_OF_THE_FUNCTION_TYPE)
			template <zboolean x, class r, class... p> struct NonVariadicFunction : Function<x, r(p...), Valid> {
				enum {is_noexcept = x};
#		else
			template <class r, class... p> struct NonVariadicFunction : Valid {
				Z_z_NORMAL_CONVERSIONS	 (p...)
				Z_z_REFERENCE_CONVERSIONS(p...)
#		endif
			enum {is_function = true};
			enum {arity = TypeCount<p...>::value};

			typedef r type(p...);
			typedef r return_type;

#			if Z_HAS_MEMBER(Type, parameters)
				typedef TypeList<p...> parameters;
#			endif

#			if Z_HAS_MEMBER(Type, parameter)
				template <zuint index> using parameter = typename TypeListGet<parameters, index>::type;
#			endif
		};

#		if Z_DIALECT_HAS(CPP17, NOEXCEPT_AS_PART_OF_THE_FUNCTION_TYPE)
			template <zboolean x, class r, class... p> struct VariadicFunction : Function<x, r(p..., ...), Valid> {
				enum {is_noexcept = x};
#		else
			template <class r, class... p> struct VariadicFunction : Valid {
				Z_z_NORMAL_CONVERSIONS	(p... Z_COMMA ...)
				Z_z_REFERENCE_CONVERSIONS(p... Z_COMMA ...)
#		endif
			enum {	is_function	     = true,
				is_variadic	     = true,
				is_variadic_function = true
			};
			enum {arity = TypeCount<p...>::value};

			typedef r type(p..., ...);
			typedef r return_type;

#			if Z_HAS_MEMBER(Type, parameters)
				typedef TypeList<p...> parameters;
#			endif

#			if Z_HAS_MEMBER(Type, parameter)
				template <zuint index> using parameter = typename TypeListGet<parameters, index>::type;
#			endif
		};

#	else
#		if Z_DIALECT_HAS(CPP17, NOEXCEPT_AS_PART_OF_THE_FUNCTION_TYPE)

#			define Z_z_PSEUDO_SPECIALIZATION_PAIR(arity)									  \
																	  \
				template <zboolean x, class r, Z_APPEND_INDEX_FOR_##arity(class p, Z_COMMA) Z_IF(arity)(Z_COMMA) class c> \
				struct Function<x, r(Z_APPEND_INDEX_FOR_##arity(p, Z_COMMA)), c>					  \
				: c {	Z_z_NORMAL_CONVERSIONS	 (Z_APPEND_INDEX_FOR_##arity(p, Z_COMMA))				  \
					Z_z_REFERENCE_CONVERSIONS(Z_APPEND_INDEX_FOR_##arity(p, Z_COMMA))				  \
				};													  \
																	  \
				template <zboolean x, class r, Z_APPEND_INDEX_FOR_##arity(class p, Z_COMMA) Z_IF(arity)(Z_COMMA) class c> \
				struct Function<x, r(Z_APPEND_INDEX_FOR_##arity(p, Z_COMMA) Z_IF(arity)(Z_COMMA) ...), c>		  \
				: c {	Z_z_NORMAL_CONVERSIONS	 (Z_APPEND_INDEX_FOR_##arity(p, Z_COMMA) Z_IF(arity)(Z_COMMA) ...)	  \
					Z_z_REFERENCE_CONVERSIONS(Z_APPEND_INDEX_FOR_##arity(p, Z_COMMA) Z_IF(arity)(Z_COMMA) ...)	  \
				};													  \
																	  \
				template <zboolean x, class r Z_IF(arity)(Z_COMMA) Z_APPEND_INDEX_FOR_##arity(class p, Z_COMMA)>	  \
				struct NonVariadicFunctionWith##arity##Parameters							  \
				: Function<x, r(Z_APPEND_INDEX_FOR_##arity(p, Z_COMMA)), Valid> {					  \
					enum {	is_function = true,									  \
						is_noexcept = x										  \
					};												  \
					enum {Z_PASTE_2(ari,ty) = arity};								  \
																	  \
					typedef r type(Z_APPEND_INDEX_FOR_##arity(p, Z_COMMA));						  \
					typedef r return_type;										  \
				};													  \
																	  \
				template <zboolean x, class r Z_IF(arity)(Z_COMMA) Z_APPEND_INDEX_FOR_##arity(class p, Z_COMMA)>	  \
				struct VariadicFunctionWith##arity##Parameters								  \
				: Function<x, r(Z_APPEND_INDEX_FOR_##arity(p, Z_COMMA) Z_IF(arity)(Z_COMMA) ...), Valid> {		  \
					enum {	is_function = true,									  \
						is_noexcept = x,									  \
						is_variadic = true									  \
					};												  \
					enum {Z_PASTE_2(ari,ty) = arity};								  \
																	  \
					typedef r type(Z_APPEND_INDEX_FOR_##arity(p, Z_COMMA) Z_IF(arity)(Z_COMMA) ...);		  \
					typedef r return_type;										  \
				};

#		else
#			define Z_z_PSEUDO_SPECIALIZATION_PAIR(arity)								   \
																   \
				template <class r Z_IF(arity)(Z_COMMA) Z_APPEND_INDEX_FOR_##arity(class p, Z_COMMA)>		   \
				struct NonVariadicFunctionWith##arity##Parameters : Valid {					   \
					Z_z_NORMAL_CONVERSIONS	 (Z_APPEND_INDEX_FOR_##arity(p, Z_COMMA))			   \
					Z_z_REFERENCE_CONVERSIONS(Z_APPEND_INDEX_FOR_##arity(p, Z_COMMA))			   \
																   \
					enum {is_function = true};								   \
					enum {Z_PASTE_2(ari,ty) = arity};							   \
																   \
					typedef r type(Z_APPEND_INDEX_FOR_##arity(p, Z_COMMA));					   \
					typedef r return_type;									   \
				};												   \
																   \
				template <class r Z_IF(arity)(Z_COMMA) Z_APPEND_INDEX_FOR_##arity(class p, Z_COMMA)>		   \
				struct VariadicFunctionWith##arity##Parameters : Valid {					   \
					Z_z_NORMAL_CONVERSIONS	 (Z_APPEND_INDEX_FOR_##arity(p, Z_COMMA) Z_IF(arity)(Z_COMMA) ...) \
					Z_z_REFERENCE_CONVERSIONS(Z_APPEND_INDEX_FOR_##arity(p, Z_COMMA) Z_IF(arity)(Z_COMMA) ...) \
																   \
					enum {	is_function = true,								   \
						is_variadic = true								   \
					};											   \
					enum {Z_PASTE_2(ari,ty) = arity};							   \
																   \
					typedef r type(Z_APPEND_INDEX_FOR_##arity(p, Z_COMMA) Z_IF(arity)(Z_COMMA) ...);	   \
					typedef r return_type;									   \
				};
#		endif

		Z_CALL_WITH_INDEX_FOR_32(Z_z_PSEUDO_SPECIALIZATION_PAIR, Z_EMPTY)
#		undef Z_z_PSEUDO_SPECIALIZATION_PAIR
#	endif

#	undef Z_z_NOEXCEPT
#	undef Z_z_COMMON_CONVERSIONS
#	undef Z_z_REFERENCE_CONVERSIONS

	// MARK: - Abstract: Enumeration, structure, union and Objective-C instance types

	enum {	Enumeration,
		PossibleTemplate,
		Structure,
		Union,
		ObjectiveCInstance
	};

	template <zboolean e, zuint k, class t> struct Kind;

#	if Z_HAS_MEMBER(Type, is_enumeration)

		template <class t> struct Kind<false, Enumeration, t> : Simple {
			enum {	is_enumeration = true,
				is_scalar      = true
			};

#			if Z_HAS_MEMBER(Type, is_pod)
				enum {is_pod = true};
#			endif

			typedef t type;
		};

		template <class t> struct Kind<true, Enumeration, t> : Kind<false, Enumeration, t> {
#			if Z_HAS_MEMBER(Type, underlying_type)
				typedef Z_COMPILER_TRAIT(TYPE_UNDERLYING_TYPE)(t) underlying_type;
#			endif
		};

#	endif

	template <zboolean e, class t> struct Construct;

	template <class t> struct Construct<false, t> : Storable {
		enum {	is_class		  = true,
			is_statically_allocatable = true
		};

		typedef t type;
	};

	template <class t> struct Construct<true, t> : Construct<false, t> {

#		if Z_HAS_MEMBER(Type, is_aggregate)
			enum {is_aggregate = Z_COMPILER_TRAIT(TYPE_IS_AGGREGATE)(t)};
#		endif

#		if Z_COMPILER_HAS_TRAIT(TYPE_IS_DEFAULT_CONSTRUCTIBLE)
			enum {is_default_constructible = Z_COMPILER_TRAIT(TYPE_IS_DEFAULT_CONSTRUCTIBLE)(t)};
#		elif Z_HAS_MEMBER(Type, is_default_constructible)
			enum {is_default_constructible = Tests::IsDefaultConstructible<t>::value};
#		endif

#		if Z_HAS_MEMBER(Type, is_final)
			enum {is_final = Z_COMPILER_TRAIT(TYPE_IS_FINAL)(t)};
#		endif

#		if Z_HAS_MEMBER(Type, is_literal)
			enum {is_literal = Z_COMPILER_TRAIT(TYPE_IS_LITERAL)(t)};
#		endif

#		if Z_HAS_MEMBER(Type, is_pod)
			enum {is_pod = Z_COMPILER_TRAIT(TYPE_IS_POD)(t)};
#		endif

#		if Z_HAS_MEMBER(Type, is_trivially_copy_assignable)
			enum {is_trivially_copy_assignable = Z_COMPILER_TRAIT(TYPE_IS_TRIVIALLY_COPY_ASSIGNABLE)(t)};
#		endif

#		if Z_HAS_MEMBER(Type, is_trivially_copy_constructible)
			enum {is_trivially_copy_constructible = Z_COMPILER_TRAIT(TYPE_IS_TRIVIALLY_COPY_CONSTRUCTIBLE)(t)};
#		endif

#		if Z_HAS_MEMBER(Type, is_trivially_copyable)
			enum {is_trivially_copyable = Z_COMPILER_TRAIT(TYPE_IS_TRIVIALLY_COPYABLE)(t)};
#		endif

#		if Z_HAS_MEMBER(Type, is_trivially_default_constructible)
			enum {is_trivially_default_constructible = Z_COMPILER_TRAIT(TYPE_IS_TRIVIALLY_DEFAULT_CONSTRUCTIBLE)(t)};
#		endif

#		if Z_HAS_MEMBER(Type, is_trivially_destructible)
			enum {is_trivially_destructible = Z_COMPILER_TRAIT(TYPE_IS_TRIVIALLY_DESTRUCTIBLE)(t)};
#		endif
	};

	template <zboolean e, class t> struct Kind<e, PossibleTemplate, t> : Construct<e, t> {};

#	if Z_HAS_MEMBER(Type, is_template)
		template <zboolean e, template <class...> class t, class... a>
		struct Kind<e, PossibleTemplate, t<a...> > : Construct<e, t<a...> > {
			enum {is_template = true};
			enum {arity = TypeCount<a...>::value};

			typedef TypeList<a...> parameters;

#			if Z_HAS_MEMBER(Type, parameter)
				template <zuint index> using parameter = typename TypeListGet<parameters, index>::type;
#			endif
		};
#	endif

	template <class t> struct Kind<false, Structure, t> : Kind<false, PossibleTemplate, t> {
		enum {is_structure = true};
	};

	template <class t> struct Kind<true, Structure, t> : Kind<true, PossibleTemplate, t> {
		enum {is_structure = true};

#		if Z_HAS_MEMBER(Type, has_virtual_destructor)
			enum {has_virtual_destructor = Z_COMPILER_TRAIT(TYPE_HAS_VIRTUAL_DESTRUCTOR)(t)};
#		endif

#		if Z_HAS_MEMBER(Type, is_abstract)
			enum {is_abstract = Z_COMPILER_TRAIT(TYPE_IS_ABSTRACT)(t)};
#		endif

#		if Z_HAS_MEMBER(Type, is_empty)
			enum {is_empty = Z_COMPILER_TRAIT(TYPE_IS_EMPTY)(t)};
#		endif

#		if Z_HAS_MEMBER(Type, is_interface_class)
			enum {is_interface_class = Z_COMPILER_TRAIT(TYPE_IS_INTERFACE_CLASS)(t)};
#		endif

#		if Z_HAS_MEMBER(Type, is_polymorphic)
			enum {is_polymorphic = Z_COMPILER_TRAIT(TYPE_IS_POLYMORPHIC)(t)};
#		endif
	};

#	if Z_HAS_MEMBER(Type, is_union)
		template <zboolean e, class t> struct Kind<e, Union, t> : Kind<e, PossibleTemplate, t> {
			enum {is_union = true};
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

#		if Z_HAS_MEMBER(Type, is_objective_c_instance)
			template <zboolean e, class t> struct Kind<e, ObjectiveCInstance, t> : ObjectiveCObject {
				enum {is_objective_c_instance = true};

				typedef t type;
			};
#		endif

#	endif
}}}}

namespace Zeta {namespace ZetaDetail {namespace Type {namespace Mixins {

	// MARK: - Mixins: Qualifiers (generic)

	template <class c> struct Unqualified : c {
		typedef const	       typename c::type add_const;
		typedef const volatile typename c::type add_const_volatile;
		typedef	      volatile typename c::type add_volatile;
		typedef		       typename c::type remove_const;
		typedef		       typename c::type remove_const_volatile;
		typedef		       typename c::type remove_volatile;
		typedef const	       typename c::type to_const;
		typedef const volatile typename c::type to_const_volatile;
		typedef	      volatile typename c::type to_volatile;
		typedef		       typename c::type to_unqualified;
	};

	template <class c> struct Qualified : c {
		enum {is_qualified = true};
	};

	enum {	NonNumber,
		Number
	};

	template <zuint k, class c> struct Const;
	template <zuint k, class c> struct ConstVolatile;
	template <zuint k, class c> struct Volatile;

	template <class c> struct Const<NonNumber, c> : Qualified<c> {
		enum {	is_const  = true,
			iss_const = true
		};

		typedef typename c::to_const	      type;
		typedef typename c::to_const_volatile add_volatile;
		typedef typename c::to_const	      remove_volatile;
	};

	template <class c> struct Const<Number, c> : Const<NonNumber, c> {
		typedef const typename c::to_signed   to_signed;
		typedef const typename c::to_unsigned to_unsigned;
	};

	template <class c> struct Volatile<NonNumber, c> : Qualified<c> {
		enum {	is_volatile  = true,
			iss_volatile = true
		};

		typedef typename c::to_volatile	      type;
		typedef typename c::to_const_volatile add_const;
		typedef typename c::to_volatile	      remove_const;
	};

	template <class c> struct Volatile<Number, c> : Volatile<NonNumber, c> {
		typedef volatile typename c::to_signed	 to_signed;
		typedef volatile typename c::to_unsigned to_unsigned;
	};

	template <class c> struct ConstVolatile<NonNumber, c> : Qualified<c> {
		enum {	is_const	   = true,
			is_const_volatile  = true,
			is_volatile	   = true,
			iss_const_volatile = true
		};

		typedef typename c::to_const_volatile type;
		typedef typename c::to_const_volatile add_const;
		typedef typename c::to_const_volatile add_volatile;
		typedef typename c::to_volatile	      remove_const;
		typedef typename c::to_const	      remove_volatile;
	};

	template <class c> struct ConstVolatile<Number, c> : ConstVolatile<NonNumber, c> {
		typedef const volatile typename c::to_signed   to_signed;
		typedef const volatile typename c::to_unsigned to_unsigned;
	};

	// MARK: - Mixins: Qualifiers (array)

	template <class c> struct ConstArray : Const<NonNumber, Unqualified<c> > {
		typedef const typename c::element_type element_type;
		typedef const typename c::remove_array remove_array;
	};

	template <class c> struct VolatileArray : Volatile<NonNumber, Unqualified<c> > {
		typedef volatile typename c::element_type element_type;
		typedef volatile typename c::remove_array remove_array;
	};

	template <class c> struct ConstVolatileArray : ConstVolatile<NonNumber, Unqualified<c> > {
		typedef const volatile typename c::element_type element_type;
		typedef const volatile typename c::remove_array remove_array;
	};

	// MARK: - Mixins: Qualifiers (function)

	template <class c> struct UnqualifiedFunction : c {
		typedef typename c::to_unqualified    type;
		typedef typename c::to_const	      add_const;
		typedef typename c::to_const_volatile add_const_volatile;
		typedef typename c::to_volatile	      add_volatile;
		typedef typename c::to_unqualified    remove_const;
		typedef typename c::to_unqualified    remove_const_this;
		typedef typename c::to_unqualified    remove_const_volatile;
		typedef typename c::to_unqualified    remove_const_volatile_this;
		typedef typename c::to_unqualified    remove_this;
		typedef typename c::to_unqualified    remove_volatile;
		typedef typename c::to_unqualified    remove_volatile_this;

#		if Z_DIALECT_HAS(CPP11, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)
			typedef typename c::to_const_lvalue	     add_const_lvalue;
			typedef typename c::to_const_rvalue	     add_const_rvalue;
			typedef typename c::to_const_volatile_lvalue add_const_volatile_lvalue;
			typedef typename c::to_const_volatile_rvalue add_const_volatile_rvalue;
			typedef typename c::to_lvalue		     add_lvalue;
			typedef typename c::to_rvalue		     add_rvalue;
			typedef typename c::to_volatile_lvalue	     add_volatile_lvalue;
			typedef typename c::to_volatile_rvalue	     add_volatile_rvalue;
#		endif

#		if Z_DIALECT_HAS(CPP17, NOEXCEPT_AS_PART_OF_THE_FUNCTION_TYPE)
			typedef typename Abstract::Function<true,  typename c::type>::to_unqualified add_noexcept;
			typedef typename Abstract::Function<false, typename c::type>::to_unqualified remove_noexcept;
#		endif
	};

	template <class c> struct QualifiedFunction : UnqualifiedFunction<c> {
		enum {is_qualified = true};
	};

	template <class c> struct ConstFunction : QualifiedFunction<c> {
		enum {	is_const  = true,
			iss_const = true
		};

		typedef typename c::to_const	      type;
		typedef typename c::to_const_volatile add_volatile;
		typedef typename c::to_const	      remove_this;
		typedef typename c::to_const	      remove_volatile;
		typedef typename c::to_const	      remove_volatile_this;

#		if Z_DIALECT_HAS(CPP11, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)
			typedef typename c::to_const_lvalue	     add_lvalue;
			typedef typename c::to_const_rvalue	     add_rvalue;
			typedef typename c::to_const_volatile_lvalue add_volatile_lvalue;
			typedef typename c::to_const_volatile_rvalue add_volatile_rvalue;
#		endif

#		if Z_DIALECT_HAS(CPP17, NOEXCEPT_AS_PART_OF_THE_FUNCTION_TYPE)
			typedef typename Abstract::Function<true,  typename c::type>::to_const add_noexcept;
			typedef typename Abstract::Function<false, typename c::type>::to_const remove_noexcept;
#		endif
	};

	template <class c> struct VolatileFunction : QualifiedFunction<c> {
		enum {	is_volatile  = true,
			iss_volatile = true
		};

		typedef typename c::to_volatile	      type;
		typedef typename c::to_const_volatile add_const;
		typedef typename c::to_volatile	      remove_const;
		typedef typename c::to_volatile	      remove_const_this;
		typedef typename c::to_volatile	      remove_this;

#		if Z_DIALECT_HAS(CPP11, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)
			typedef typename c::to_const_volatile_lvalue add_const_lvalue;
			typedef typename c::to_const_volatile_rvalue add_const_rvalue;
			typedef typename c::to_volatile_lvalue	     add_lvalue;
			typedef typename c::to_volatile_rvalue	     add_rvalue;
#		endif

#		if Z_DIALECT_HAS(CPP17, NOEXCEPT_AS_PART_OF_THE_FUNCTION_TYPE)
			typedef typename Abstract::Function<true,  typename c::type>::to_volatile add_noexcept;
			typedef typename Abstract::Function<false, typename c::type>::to_volatile remove_noexcept;
#		endif
	};

	template <class c> struct ConstVolatileFunction : QualifiedFunction<c> {
		enum {	is_const	   = true,
			is_const_volatile  = true,
			is_volatile	   = true,
			iss_const_volatile = true
		};

		typedef typename c::to_const_volatile type;
		typedef typename c::to_const_volatile add_const;
		typedef typename c::to_const_volatile add_volatile;
		typedef typename c::to_volatile	      remove_const;
		typedef typename c::to_volatile	      remove_const_this;
		typedef typename c::to_const_volatile remove_this;
		typedef typename c::to_const	      remove_volatile;
		typedef typename c::to_const	      remove_volatile_this;

#		if Z_DIALECT_HAS(CPP11, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)
			typedef typename c::to_const_volatile_lvalue add_const_lvalue;
			typedef typename c::to_const_volatile_rvalue add_const_rvalue;
			typedef typename c::to_const_volatile_lvalue add_lvalue;
			typedef typename c::to_const_volatile_rvalue add_rvalue;
			typedef typename c::to_const_volatile_lvalue add_volatile_lvalue;
			typedef typename c::to_const_volatile_rvalue add_volatile_rvalue;
#		endif

#		if Z_DIALECT_HAS(CPP17, NOEXCEPT_AS_PART_OF_THE_FUNCTION_TYPE)
			typedef typename Abstract::Function<true,  typename c::type>::to_const_volatile add_noexcept;
			typedef typename Abstract::Function<false, typename c::type>::to_const_volatile remove_noexcept;
#		endif
	};

#	if Z_DIALECT_HAS(CPP11, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)

		template <class c> struct LValueFunction : QualifiedFunction<c> {
			enum {	is_lvalue  = true,
				iss_lvalue = true
			};

			typedef typename c::to_lvalue		     type;
			typedef typename c::to_const_lvalue	     add_const;
			typedef typename c::to_const_lvalue	     add_const_rvalue;
			typedef typename c::to_const_volatile_lvalue add_const_volatile;
			typedef typename c::to_const_volatile_lvalue add_const_volatile_rvalue;
			typedef typename c::to_lvalue		     add_rvalue;
			typedef typename c::to_volatile_lvalue	     add_volatile;
			typedef typename c::to_volatile_lvalue	     add_volatile_rvalue;
			typedef typename c::to_lvalue		     remove_const;
			typedef typename c::to_lvalue		     remove_const_volatile;
			typedef typename c::to_lvalue		     remove_volatile;

#			if Z_DIALECT_HAS(CPP17, NOEXCEPT_AS_PART_OF_THE_FUNCTION_TYPE)
				typedef typename Abstract::Function<true,  typename c::type>::to_lvalue add_noexcept;
				typedef typename Abstract::Function<false, typename c::type>::to_lvalue remove_noexcept;
#			endif
		};

		template <class c> struct RValueFunction : QualifiedFunction<c> {
			enum {	is_rvalue  = true,
				iss_rvalue = true
			};

			typedef typename c::to_rvalue		     type;
			typedef typename c::to_const_rvalue	     add_const;
			typedef typename c::to_const_volatile_rvalue add_const_volatile;
			typedef typename c::to_volatile_rvalue	     add_volatile;
			typedef typename c::to_rvalue		     remove_const;
			typedef typename c::to_rvalue		     remove_const_volatile;
			typedef typename c::to_rvalue		     remove_volatile;

#			if Z_DIALECT_HAS(CPP17, NOEXCEPT_AS_PART_OF_THE_FUNCTION_TYPE)
				typedef typename Abstract::Function<true,  typename c::type>::to_rvalue add_noexcept;
				typedef typename Abstract::Function<false, typename c::type>::to_rvalue remove_noexcept;
#			endif
		};

		template <class c> struct ConstLValueFunction : QualifiedFunction<c> {
			enum {	is_const	 = true,
				is_const_lvalue	 = true,
				is_lvalue	 = true,
				iss_const_lvalue = true
			};

			typedef typename c::to_const_lvalue	     type;
			typedef typename c::to_const_lvalue	     add_const;
			typedef typename c::to_const_lvalue	     add_const_rvalue;
			typedef typename c::to_const_volatile_lvalue add_const_volatile;
			typedef typename c::to_const_volatile_lvalue add_const_volatile_rvalue;
			typedef typename c::to_const_lvalue	     add_lvalue;
			typedef typename c::to_const_lvalue	     add_rvalue;
			typedef typename c::to_const_volatile_lvalue add_volatile;
			typedef typename c::to_const_volatile_lvalue add_volatile_lvalue;
			typedef typename c::to_const_volatile_lvalue add_volatile_rvalue;
			typedef typename c::to_lvalue		     remove_const;
			typedef typename c::to_lvalue		     remove_const_volatile;
			typedef typename c::to_const		     remove_this;
			typedef typename c::to_const_lvalue	     remove_volatile;
			typedef typename c::to_const		     remove_volatile_this;

#			if Z_DIALECT_HAS(CPP17, NOEXCEPT_AS_PART_OF_THE_FUNCTION_TYPE)
				typedef typename Abstract::Function<true,  typename c::type>::to_const_lvalue add_noexcept;
				typedef typename Abstract::Function<false, typename c::type>::to_const_lvalue remove_noexcept;
#			endif
		};

		template <class c> struct ConstRValueFunction : QualifiedFunction<c> {
			enum {	is_const	 = true,
				is_const_rvalue  = true,
				is_rvalue	 = true,
				iss_const_rvalue = true
			};

			typedef typename c::to_const_rvalue	     type;
			typedef typename c::to_const_rvalue	     add_const;
			typedef typename c::to_const_volatile_rvalue add_const_volatile;
			typedef typename c::to_const_lvalue	     add_lvalue;
			typedef typename c::to_const_rvalue	     add_rvalue;
			typedef typename c::to_const_volatile_rvalue add_volatile;
			typedef typename c::to_const_volatile_lvalue add_volatile_lvalue;
			typedef typename c::to_const_volatile_rvalue add_volatile_rvalue;
			typedef typename c::to_rvalue		     remove_const;
			typedef typename c::to_rvalue		     remove_const_volatile;
			typedef typename c::to_const		     remove_this;
			typedef typename c::to_const_rvalue	     remove_volatile;
			typedef typename c::to_const		     remove_volatile_this;

#			if Z_DIALECT_HAS(CPP17, NOEXCEPT_AS_PART_OF_THE_FUNCTION_TYPE)
				typedef typename Abstract::Function<true,  typename c::type>::to_const_rvalue add_noexcept;
				typedef typename Abstract::Function<false, typename c::type>::to_const_rvalue remove_noexcept;
#			endif
		};

		template <class c> struct VolatileLValueFunction : QualifiedFunction<c> {
			enum {	is_lvalue	    = true,
				is_volatile	    = true,
				is_volatile_lvalue  = true,
				iss_volatile_lvalue = true
			};

			typedef typename c::to_volatile_lvalue	     type;
			typedef typename c::to_const_volatile_lvalue add_const;
			typedef typename c::to_const_volatile_lvalue add_const_lvalue;
			typedef typename c::to_const_volatile_lvalue add_const_rvalue;
			typedef typename c::to_const_volatile_lvalue add_const_volatile;
			typedef typename c::to_const_volatile_lvalue add_const_volatile_vralue;
			typedef typename c::to_volatile_lvalue	     add_lvalue;
			typedef typename c::to_volatile_lvalue	     add_rvalue;
			typedef typename c::to_volatile_lvalue	     add_volatile;
			typedef typename c::to_volatile_lvalue	     add_volatile_rvalue;
			typedef typename c::to_volatile_lvalue	     remove_const;
			typedef typename c::to_volatile		     remove_const_this;
			typedef typename c::to_lvalue		     remove_const_volatile;
			typedef typename c::to_volatile		     remove_this;
			typedef typename c::to_lvalue		     remove_volatile;

#			if Z_DIALECT_HAS(CPP17, NOEXCEPT_AS_PART_OF_THE_FUNCTION_TYPE)
				typedef typename Abstract::Function<true,  typename c::type>::to_volatile_lvalue add_noexcept;
				typedef typename Abstract::Function<false, typename c::type>::to_volatile_lvalue remove_noexcept;
#			endif
		};

		template <class c> struct VolatileRValueFunction : QualifiedFunction<c> {
			enum {	is_rvalue	    = true,
				is_volatile	    = true,
				is_volatile_rvalue  = true,
				iss_volatile_rvalue = true
			};

			typedef typename c::to_volatile_rvalue	     type;
			typedef typename c::to_const_volatile_rvalue add_const;
			typedef typename c::to_const_volatile_lvalue add_const_lvalue;
			typedef typename c::to_const_volatile_rvalue add_const_rvalue;
			typedef typename c::to_const_volatile_rvalue add_const_volatile;
			typedef typename c::to_volatile_lvalue	     add_lvalue;
			typedef typename c::to_volatile_rvalue	     add_rvalue;
			typedef typename c::to_volatile_rvalue	     add_volatile;
			typedef typename c::to_volatile_rvalue	     remove_const;
			typedef typename c::to_volatile		     remove_const_this;
			typedef typename c::to_rvalue		     remove_const_volatile;
			typedef typename c::to_volatile		     remove_this;
			typedef typename c::to_rvalue		     remove_volatile;

#			if Z_DIALECT_HAS(CPP17, NOEXCEPT_AS_PART_OF_THE_FUNCTION_TYPE)
				typedef typename Abstract::Function<true,  typename c::type>::to_volatile_rvalue add_noexcept;
				typedef typename Abstract::Function<false, typename c::type>::to_volatile_rvalue remove_noexcept;
#			endif
		};

		template <class c> struct ConstVolatileLValueFunction : QualifiedFunction<c> {
			enum {	is_const		 = true,
				is_const_lvalue		 = true,
				is_const_volatile	 = true,
				is_const_volatile_lvalue = true,
				is_lvalue		 = true,
				is_volatile		 = true,
				is_volatile_lvalue	 = true
			};

			typedef typename c::to_const_volatile_lvalue type;
			typedef typename c::to_const_volatile_lvalue add_const;
			typedef typename c::to_const_volatile_lvalue add_const_lvalue;
			typedef typename c::to_const_volatile_lvalue add_const_rvalue;
			typedef typename c::to_const_volatile_lvalue add_const_volatile;
			typedef typename c::to_const_volatile_lvalue add_const_volatile_rvalue;
			typedef typename c::to_const_volatile_lvalue add_lvalue;
			typedef typename c::to_const_volatile_lvalue add_rvalue;
			typedef typename c::to_const_volatile_lvalue add_volatile;
			typedef typename c::to_const_volatile_lvalue add_volatile_lvalue;
			typedef typename c::to_const_volatile_lvalue add_volatile_rvalue;
			typedef typename c::to_volatile_lvalue	     remove_const;
			typedef typename c::to_volatile		     remove_const_this;
			typedef typename c::to_lvalue		     remove_const_volatile;
			typedef typename c::to_const_volatile	     remove_this;
			typedef typename c::to_const_lvalue	     remove_volatile;
			typedef typename c::to_const		     remove_volatile_this;

#			if Z_DIALECT_HAS(CPP17, NOEXCEPT_AS_PART_OF_THE_FUNCTION_TYPE)
				typedef typename Abstract::Function<true,  typename c::type>::to_const_volatile_lvalue add_noexcept;
				typedef typename Abstract::Function<false, typename c::type>::to_const_volatile_lvalue remove_noexcept;
#			endif
		};

		template <class c> struct ConstVolatileRValueFunction : QualifiedFunction<c> {
			enum {	is_const		 = true,
				is_const_rvalue		 = true,
				is_const_volatile	 = true,
				is_const_volatile_rvalue = true,
				is_rvalue		 = true,
				is_volatile		 = true,
				is_volatile_rvalue	 = true
			};

			typedef typename c::to_const_volatile_rvalue type;
			typedef typename c::to_const_volatile_rvalue add_const;
			typedef typename c::to_const_volatile_lvalue add_const_lvalue;
			typedef typename c::to_const_volatile_rvalue add_const_rvalue;
			typedef typename c::to_const_volatile_rvalue add_const_volatile;
			typedef typename c::to_const_volatile_lvalue add_lvalue;
			typedef typename c::to_const_volatile_rvalue add_rvalue;
			typedef typename c::to_const_volatile_rvalue add_volatile;
			typedef typename c::to_const_volatile_lvalue add_volatile_lvalue;
			typedef typename c::to_const_volatile_rvalue add_volatile_rvalue;
			typedef typename c::to_volatile_rvalue	     remove_const;
			typedef typename c::to_volatile		     remove_const_this;
			typedef typename c::to_rvalue		     remove_const_volatile;
			typedef typename c::to_const_volatile	     remove_this;
			typedef typename c::to_const_rvalue	     remove_volatile;
			typedef typename c::to_const		     remove_volatile_this;

#			if Z_DIALECT_HAS(CPP17, NOEXCEPT_AS_PART_OF_THE_FUNCTION_TYPE)
				typedef typename Abstract::Function<true,  typename c::type>::to_const_volatile_rvalue add_noexcept;
				typedef typename Abstract::Function<false, typename c::type>::to_const_volatile_rvalue remove_noexcept;
#			endif
		};

#	endif

	// MARK: - Mixins: Kind

	template <class c> struct StaticallyAllocatable : c {
		enum {can_form_reference = true};

		typedef typename c::type& add_lvalue_reference;

#		if Z_DIALECT_HAS(CPP11, RVALUE_REFERENCE)
			typedef typename c::type&& add_rvalue_reference;
#		endif

		typedef Z_PACKED_STRUCTURE_BEGIN {
			typename c::type value;
		} Z_PACKED_STRUCTURE_END to_wrap;

		typedef Z_PACKED_STRUCTURE_BEGIN {
			zchar data[sizeof(to_wrap)];
		} Z_PACKED_STRUCTURE_END to_opaque;
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

	template <zuint k, class c> struct Kind;

	// MARK: - Mixins: Kind (non-storable)

	template <class c> struct Kind<Void, c> : c {
		enum {	can_decorate_pointer = true,
			can_form_pointer     = true
		};

		typedef typename c::type* add_pointer;
		typedef typename c::type  remove_indirection;
		typedef typename c::type  remove_member_pointer;
		typedef typename c::type  remove_pointer;
		typedef typename c::type  remove_reference;
		typedef typename c::type* to_pointer;
	};

	template <class c> struct Kind<NonReferenceableFunction, c> : c {
		enum {	can_decorate_function	    = true,
			can_decorate_member_pointer = true,
			can_form_member_pointer	    = true
		};

		typedef typename c::type remove_indirection;
		typedef typename c::type remove_member_pointer;
		typedef typename c::type remove_pointer;
		typedef typename c::type remove_reference;
		typedef typename c::type to_function;
	};

	template <class c> struct Kind<ReferenceableFunction, c> : Kind<NonReferenceableFunction, c> {
		enum {	can_decorate_pointer   = true,
			can_decorate_reference = true,
			can_form_pointer       = true,
			can_form_reference     = true
		};

		typedef typename c::type& add_lvalue_reference;
		typedef typename c::type* add_pointer;
		typedef typename c::type& to_lvalue_reference;
		typedef typename c::type* to_pointer;

#		if Z_DIALECT_HAS(CPP11, RVALUE_REFERENCE)
			typedef typename c::type&& add_rvalue_reference;
			typedef typename c::type&& to_rvalue_reference;
#		endif
	};

	// MARK: - Mixins: Kind (storable)

	template <class c> struct Value : c {
		enum {	can_decorate_member_pointer = true,
			can_decorate_pointer	    = true,
			can_decorate_reference	    = true,
			can_form_member_pointer	    = true,
			can_form_pointer	    = true
		};

		typedef typename c::type* add_pointer;
		typedef typename c::type  remove_indirection;
		typedef typename c::type  remove_member_pointer;
		typedef typename c::type  remove_pointer;
		typedef typename c::type  remove_reference;
		typedef typename c::type& to_lvalue_reference;
		typedef typename c::type* to_pointer;

#		if Z_DIALECT_HAS(CPP11, RVALUE_REFERENCE)
			typedef typename c::type&& to_rvalue_reference;
#		endif
	};

	template <class c> struct Kind<NonStaticallyAllocatableValue, c> : Value<c> {
		enum {can_form_reference = true};

		typedef typename c::type& add_lvalue_reference;

#		if Z_DIALECT_HAS(CPP11, RVALUE_REFERENCE)
			typedef typename c::type&& add_rvalue_reference;
#		endif
	};

	template <class c> struct Kind<StaticallyAllocatableValue, c> : StaticallyAllocatable<Value<c> > {};

	template <class c> struct Kind<VoidPointer, c> : StaticallyAllocatable<c> {
		enum {	can_decorate_pointer	= true,
			can_form_member_pointer = true,
			can_form_pointer	= true
		};

		typedef typename c::type*	  add_pointer;
		typedef typename c::pointee_type  remove_indirection;
		typedef typename c::type	  remove_member_pointer;
		typedef typename c::pointee_type  remove_pointer;
		typedef typename c::type	  remove_reference;
		typedef typename c::pointee_type* to_pointer;
	};

	template <class c> struct Kind<Pointer, c> : Kind<VoidPointer, c> {
		enum {	can_decorate_member_pointer = true,
			can_decorate_reference	    = true
		};

		typedef typename c::pointee_type& to_lvalue_reference;

#		if Z_DIALECT_HAS(CPP11, RVALUE_REFERENCE)
			typedef typename c::pointee_type&& to_rvalue_reference;
#		endif
	};

	template <class c> struct Kind<FunctionPointer, c> : Kind<Pointer, c> {
		enum {can_decorate_function = true};

		typedef typename c::pointee_type to_function;
	};

	template <class c> struct Kind<Reference, c> : StaticallyAllocatable<c> {
		enum {	can_decorate_member_pointer = true,
			can_decorate_pointer	    = true,
			can_decorate_reference	    = true
		};

		typedef NaT			     add_const;
		typedef NaT			     add_const_volatile;
		typedef NaT			     add_volatile;
		typedef typename c::referencee_type  remove_indirection;
		typedef typename c::type	     remove_member_pointer;
		typedef typename c::type	     remove_pointer;
		typedef typename c::referencee_type  remove_reference;
		typedef NaT			     to_const;
		typedef NaT			     to_const_volatile;
		typedef typename c::referencee_type& to_lvalue_reference;
		typedef typename c::referencee_type* to_pointer;
		typedef NaT			     to_volatile;

#		if Z_DIALECT_HAS(CPP11, RVALUE_REFERENCE)
			typedef typename c::referencee_type&& to_rvalue_reference;
#		endif
	};

	template <class c> struct Kind<FunctionReference, c> : Kind<Reference, c> {
		enum {can_decorate_function = true};

		typedef typename c::referencee_type to_function;
	};

	template <class c> struct MemberPointer : StaticallyAllocatable<c> {
		enum {	can_decorate_member_pointer = true,
			can_form_member_pointer	    = true,
			can_form_pointer	    = true
		};

		typedef typename c::type*	 add_pointer;
		typedef typename c::pointee_type remove_indirection;
		typedef typename c::pointee_type remove_member_pointer;
		typedef typename c::type	 remove_pointer;
		typedef typename c::type	 remove_reference;
	};

	template <class c> struct Kind<DataMemberPointer, c> : MemberPointer<c> {
		enum {	can_decorate_pointer   = true,
			can_decorate_reference = true
		};

		typedef typename c::pointee_type& to_lvalue_reference;
		typedef typename c::pointee_type* to_pointer;

#		if Z_DIALECT_HAS(CPP11, RVALUE_REFERENCE)
			typedef typename c::pointee_type&& to_rvalue_reference;
#		endif
	};

	template <class c> struct Kind<NonConvertibleMemberFunctionPointer, c> : MemberPointer<c> {
		enum {can_decorate_function = true};

		typedef typename c::pointee_type to_function;
	};

	template <class c> struct Kind<ConvertibleMemberFunctionPointer, c> : Kind<NonConvertibleMemberFunctionPointer, c> {
		enum {	can_decorate_pointer   = true,
			can_decorate_reference = true
		};

		typedef typename c::pointee_type& to_lvalue_reference;
		typedef typename c::pointee_type* to_pointer;

#		if Z_DIALECT_HAS(CPP11, RVALUE_REFERENCE)
			typedef typename c::pointee_type&& to_rvalue_reference;
#		endif
	};
}}}}

namespace Zeta {namespace ZetaDetail {namespace Type {

	// MARK: - Specializations: Enumeration, structure, union and Objective-C instance types

	template <class t> struct Ambiguous {

#		if Z_DIALECT_HAS(CPP11, EXPRESSION_SFINAE)
			template <class tt = t, class = Maybe<> > struct IsClass : False {};

			template <class tt> struct IsClass<tt, Maybe<!!sizeof(int (tt::*))> > : True {};

#			if !Z_COMPILER_HAS_TRAIT(TYPE_IS_ENUMERATION)
				template <class tt = t, class = Maybe<> > struct IsNumberConstructible : False {};

				template <class tt> struct IsNumberConstructible<tt, Maybe<!!sizeof(tt(1))> > : True {};
#			endif
#		endif

		enum {	structure_detected =
#			if Z_COMPILER_HAS_TRAIT(TYPE_IS_STRUCTURE)
				Z_COMPILER_TRAIT(TYPE_IS_STRUCTURE)(t)
#			elif Z_COMPILER_HAS_TRAIT(TYPE_IS_UNION) && Z_DIALECT_HAS(CPP11, EXPRESSION_SFINAE)
				!Z_COMPILER_TRAIT(TYPE_IS_UNION)(t) && IsClass<>::value
#			else
				false
#			endif
		};

		enum {	union_detected =
#			if Z_COMPILER_HAS_TRAIT(TYPE_IS_UNION)
				Z_COMPILER_TRAIT(TYPE_IS_UNION)(t)
#			elif Z_COMPILER_HAS_TRAIT(TYPE_IS_STRUCTURE) && Z_DIALECT_HAS(CPP11, EXPRESSION_SFINAE)
				!Z_COMPILER_TRAIT(TYPE_IS_STRUCTURE)(t) && IsClass<>::value
#			else
				false
#			endif
		};

		enum {	class_detected = structure_detected || union_detected
#			if Z_DIALECT_HAS(CPP11, EXPRESSION_SFINAE)
				|| IsClass<>::value
#			endif
		};

		enum {	enumeration_detected =
#			if Z_COMPILER_HAS_TRAIT(TYPE_IS_ENUMERATION)
				Z_COMPILER_TRAIT(TYPE_IS_ENUMERATION)(t)
#			elif Z_DIALECT_HAS(CPP11, EXPRESSION_SFINAE)
				!class_detected && IsNumberConstructible<>::value
#			else
				false
#			endif
		};

		enum {	objective_c_instance_detected =
			Z_LANGUAGE_INCLUDES(OBJECTIVE_C)	&&
			Z_DIALECT_HAS(CPP11, EXPRESSION_SFINAE) &&
			!enumeration_detected			&&
			!class_detected
		};

		enum {	kind = enumeration_detected
				? Abstract::Enumeration
				: (union_detected
					? Abstract::Union
					: (objective_c_instance_detected
						? Abstract::ObjectiveCInstance
						: (structure_detected
							? Abstract::Structure
							: Abstract::PossibleTemplate)))
		};
	};

	template <Boolean e, class t> struct Case : Mixins::Unqualified<Abstract::Kind<e, Ambiguous<t>::kind, t> > {};

	// MARK: - Specializations: Standard C/C++ fundamental types

	template <Boolean e> struct Case<e, void  > : Mixins::Unqualified<Abstract::Void  > {};
	template <Boolean e> struct Case<e, Char  > : Mixins::Unqualified<Abstract::Char  > {};
	template <Boolean e> struct Case<e, UChar > : Mixins::Unqualified<Abstract::UChar > {};
	template <Boolean e> struct Case<e, SChar > : Mixins::Unqualified<Abstract::SChar > {};
	template <Boolean e> struct Case<e, UShort> : Mixins::Unqualified<Abstract::UShort> {};
	template <Boolean e> struct Case<e, SShort> : Mixins::Unqualified<Abstract::SShort> {};
	template <Boolean e> struct Case<e, UInt  > : Mixins::Unqualified<Abstract::UInt  > {};
	template <Boolean e> struct Case<e, SInt  > : Mixins::Unqualified<Abstract::SInt  > {};
	template <Boolean e> struct Case<e, ULong > : Mixins::Unqualified<Abstract::ULong > {};
	template <Boolean e> struct Case<e, SLong > : Mixins::Unqualified<Abstract::SLong > {};

#	ifdef Z_ULLONG
		template <Boolean e> struct Case<e, ULLong> : Mixins::Unqualified<Abstract::ULLong> {};
#	endif

#	ifdef Z_SLLONG
		template <Boolean e> struct Case<e, SLLong> : Mixins::Unqualified<Abstract::SLLong> {};
#	endif

#	ifdef Z_BOOL
		template <Boolean e> struct Case<e, Bool> : Mixins::Unqualified<Abstract::Bool> {};
#	endif

#	if Z_DIALECT_HAS_TYPE(CPP98, WCHAR_T)
		template <Boolean e> struct Case<e, WChar> : Mixins::Unqualified<Abstract::WChar> {};
#	endif

#	if Z_DIALECT_HAS_TYPE(CPP20, CHAR8_T)
		template <Boolean e> struct Case<e, Char8> : Mixins::Unqualified<Abstract::Char8> {};
#	endif

#	if Z_DIALECT_HAS_TYPE(CPP11, CHAR16_T)
		template <Boolean e> struct Case<e, Char16> : Mixins::Unqualified<Abstract::Char16> {};
#	endif

#	if Z_DIALECT_HAS_TYPE(CPP11, CHAR32_T)
		template <Boolean e> struct Case<e, Char32> : Mixins::Unqualified<Abstract::Char32> {};
#	endif

#	ifdef Z_FLOAT
		template <Boolean e> struct Case<e, Float> : Mixins::Unqualified<Abstract::Float> {};
#	endif

#	ifdef Z_DOUBLE
		template <Boolean e> struct Case<e, Double> : Mixins::Unqualified<Abstract::Double> {};
#	endif

#	ifdef Z_LDOUBLE
		template <Boolean e> struct Case<e, LDouble> : Mixins::Unqualified<Abstract::LDouble> {};
#	endif

#	ifdef Z_FLOAT16
		template <Boolean e> struct Case<e, Float16> : Mixins::Unqualified<Abstract::Float16> {};
#	endif

#	ifdef Z_FLOAT32
		template <Boolean e> struct Case<e, Float32> : Mixins::Unqualified<Abstract::Float32> {};
#	endif

#	ifdef Z_FLOAT64
		template <Boolean e> struct Case<e, Float64> : Mixins::Unqualified<Abstract::Float64> {};
#	endif

#	ifdef Z_FLOAT128
		template <Boolean e> struct Case<e, Float128> : Mixins::Unqualified<Abstract::Float128> {};
#	endif

#	ifdef Z_FLOAT32X
		template <Boolean e> struct Case<e, Float32x> : Mixins::Unqualified<Abstract::Float32x> {};
#	endif

#	ifdef Z_FLOAT64X
		template <Boolean e> struct Case<e, Float64x> : Mixins::Unqualified<Abstract::Float64x> {};
#	endif

#	ifdef Z_FLOAT128X
		template <Boolean e> struct Case<e, Float128x> : Mixins::Unqualified<Abstract::Float128x> {};
#	endif

#	ifdef Z_DECIMAL32
		template <Boolean e> struct Case<e, Decimal32> : Mixins::Unqualified<Abstract::Decimal32> {};
#	endif

#	ifdef Z_DECIMAL64
		template <Boolean e> struct Case<e, Decimal64> : Mixins::Unqualified<Abstract::Decimal64> {};
#	endif

#	ifdef Z_DECIMAL128
		template <Boolean e> struct Case<e, Decimal128> : Mixins::Unqualified<Abstract::Decimal128> {};
#	endif

#	ifdef Z_DECIMAL64X
		template <Boolean e> struct Case<e, Decimal64x> : Mixins::Unqualified<Abstract::Decimal64x> {};
#	endif

#	ifdef Z_DECIMAL128X
		template <Boolean e> struct Case<e, Decimal128x> : Mixins::Unqualified<Abstract::Decimal128x> {};
#	endif

#	if Z_HAS_MEMBER(Type, is_nullptr)
		template <Boolean e> struct Case<e, NullPtr> : Mixins::Unqualified<Abstract::NullPtr> {};
#	endif

	// MARK: - Specializations: Fixed-width integral types

#	if defined(Z_UINT8) && Z_UINT8_FUNDAMENTAL == Z_FUNDAMENTAL_UINT8
		template <Boolean e> struct Case<e, UInt8> : Mixins::Unqualified<Abstract::UInt8> {};
#	endif

#	if defined(Z_SINT8) && Z_SINT8_FUNDAMENTAL == Z_FUNDAMENTAL_SINT8
		template <Boolean e> struct Case<e, SInt8> : Mixins::Unqualified<Abstract::SInt8> {};
#	endif

#	if defined(Z_UINT16) && Z_UINT16_FUNDAMENTAL == Z_FUNDAMENTAL_UINT16
		template <Boolean e> struct Case<e, UInt16> : Mixins::Unqualified<Abstract::UInt16> {};
#	endif

#	if defined(Z_SINT16) && Z_SINT16_FUNDAMENTAL == Z_FUNDAMENTAL_SINT16
		template <Boolean e> struct Case<e, SInt16> : Mixins::Unqualified<Abstract::SInt16> {};
#	endif

#	if defined(Z_UINT24) && Z_UINT24_FUNDAMENTAL == Z_FUNDAMENTAL_UINT24
		template <Boolean e> struct Case<e, UInt24> : Mixins::Unqualified<Abstract::UInt24> {};
#	endif

#	if defined(Z_SINT24) && Z_SINT24_FUNDAMENTAL == Z_FUNDAMENTAL_SINT24
		template <Boolean e> struct Case<e, SInt24> : Mixins::Unqualified<Abstract::SInt24> {};
#	endif

#	if defined(Z_UINT32) && Z_UINT32_FUNDAMENTAL == Z_FUNDAMENTAL_UINT32
		template <Boolean e> struct Case<e, UInt32> : Mixins::Unqualified<Abstract::UInt32> {};
#	endif

#	if defined(Z_SINT32) && Z_SINT32_FUNDAMENTAL == Z_FUNDAMENTAL_SINT32
		template <Boolean e> struct Case<e, SInt32> : Mixins::Unqualified<Abstract::SInt32> {};
#	endif

#	if defined(Z_UINT40) && Z_UINT40_FUNDAMENTAL == Z_FUNDAMENTAL_UINT40
		template <Boolean e> struct Case<e, UInt40> : Mixins::Unqualified<Abstract::UInt40> {};
#	endif

#	if defined(Z_SINT40) && Z_SINT40_FUNDAMENTAL == Z_FUNDAMENTAL_SINT40
		template <Boolean e> struct Case<e, SInt40> : Mixins::Unqualified<Abstract::SInt40> {};
#	endif

#	if defined(Z_UINT48) && Z_UINT48_FUNDAMENTAL == Z_FUNDAMENTAL_UINT48
		template <Boolean e> struct Case<e, UInt48> : Mixins::Unqualified<Abstract::UInt48> {};
#	endif

#	if defined(Z_SINT48) && Z_SINT48_FUNDAMENTAL == Z_FUNDAMENTAL_SINT48
		template <Boolean e> struct Case<e, SInt48> : Mixins::Unqualified<Abstract::SInt48> {};
#	endif

#	if defined(Z_UINT56) && Z_UINT56_FUNDAMENTAL == Z_FUNDAMENTAL_UINT56
		template <Boolean e> struct Case<e, UInt56> : Mixins::Unqualified<Abstract::UInt56> {};
#	endif

#	if defined(Z_SINT56) && Z_SINT56_FUNDAMENTAL == Z_FUNDAMENTAL_SINT56
		template <Boolean e> struct Case<e, SInt56> : Mixins::Unqualified<Abstract::SInt56> {};
#	endif

#	if defined(Z_UINT64) && Z_UINT64_FUNDAMENTAL == Z_FUNDAMENTAL_UINT64
		template <Boolean e> struct Case<e, UInt64> : Mixins::Unqualified<Abstract::UInt64> {};
#	endif

#	if defined(Z_SINT64) && Z_SINT64_FUNDAMENTAL == Z_FUNDAMENTAL_SINT64
		template <Boolean e> struct Case<e, SInt64> : Mixins::Unqualified<Abstract::SInt64> {};
#	endif

#	if defined(Z_UINT128) && Z_UINT128_FUNDAMENTAL == Z_FUNDAMENTAL_UINT128
		template <Boolean e> struct Case<e, UInt128> : Mixins::Unqualified<Abstract::UInt128> {};
#	endif

#	if defined(Z_SINT128) && Z_SINT128_FUNDAMENTAL == Z_FUNDAMENTAL_SINT128
		template <Boolean e> struct Case<e, SInt128> : Mixins::Unqualified<Abstract::SInt128> {};
#	endif

	// MARK: - Specializations: Fixed-format real types

#	if defined(Z_BFP16) && Z_BFP16_FUNDAMENTAL == Z_FUNDAMENTAL_BFP16
		template <Boolean e> struct Case<e, BFP16> : Mixins::Unqualified<Abstract::BFP16> {};
#	endif

#	if defined(Z_BFP32) && Z_BFP32_FUNDAMENTAL == Z_FUNDAMENTAL_BFP32
		template <Boolean e> struct Case<e, BFP32> : Mixins::Unqualified<Abstract::BFP32> {};
#	endif

#	if defined(Z_BFP64) && Z_BFP64_FUNDAMENTAL == Z_FUNDAMENTAL_BFP64
		template <Boolean e> struct Case<e, BFP64> : Mixins::Unqualified<Abstract::BFP64> {};
#	endif

#	if defined(Z_BFP128) && Z_BFP128_FUNDAMENTAL == Z_FUNDAMENTAL_BFP128
		template <Boolean e> struct Case<e, BFP128> : Mixins::Unqualified<Abstract::BFP128> {};
#	endif

#	if defined(Z_DFP32) && Z_DFP32_FUNDAMENTAL == Z_FUNDAMENTAL_DFP32
		template <Boolean e> struct Case<e, DFP32> : Mixins::Unqualified<Abstract::DFP32> {};
#	endif

#	if defined(Z_DFP64) && Z_DFP64_FUNDAMENTAL == Z_FUNDAMENTAL_DFP64
		template <Boolean e> struct Case<e, DFP64> : Mixins::Unqualified<Abstract::DFP64> {};
#	endif

#	if defined(Z_DFP128) && Z_DFP128_FUNDAMENTAL == Z_FUNDAMENTAL_DFP128
		template <Boolean e> struct Case<e, DFP128> : Mixins::Unqualified<Abstract::DFP128> {};
#	endif

#	if defined(Z_X87_DE80) && Z_X87_DE80_FUNDAMENTAL == Z_FUNDAMENTAL_X87_DE80
		template <Boolean e> struct Case<e, x87_DE80> : Mixins::Unqualified<Abstract::x87_DE80> {};
#	endif

#	if defined(Z_X87_DE96) && Z_X87_DE96_FUNDAMENTAL == Z_FUNDAMENTAL_X87_DE96
		template <Boolean e> struct Case<e, x87_DE96> : Mixins::Unqualified<Abstract::x87_DE96> {};
#	endif

#	if defined(Z_X87_DE128) && Z_X87_DE128_FUNDAMENTAL == Z_FUNDAMENTAL_X87_DE128
		template <Boolean e> struct Case<e, x87_DE128> : Mixins::Unqualified<Abstract::x87_DE128> {};
#	endif

#	if defined(Z_IBM_ED) && Z_IBM_ED_FUNDAMENTAL == Z_FUNDAMENTAL_IBM_ED
		template <Boolean e> struct Case<e, IBM_ED> : Mixins::Unqualified<Abstract::IBM_ED> {};
#	endif

#	if defined(Z_BFLOAT16) && Z_BFLOAT16_FUNDAMENTAL == Z_FUNDAMENTAL_BFLOAT16
		template <Boolean e> struct Case<e, bfloat16> : Mixins::Unqualified<Abstract::bfloat16> {};
#	endif

	// MARK: - Specializations: Array types

	template <Boolean e, class t, USize n> struct Case<e,		     t[n]> : Mixins::Unqualified       <Abstract::SizedArray<e, t, n> > {};
	template <Boolean e, class t, USize n> struct Case<e, const	     t[n]> : Mixins::ConstArray	       <Abstract::SizedArray<e, t, n> > {};
	template <Boolean e, class t, USize n> struct Case<e,	    volatile t[n]> : Mixins::VolatileArray     <Abstract::SizedArray<e, t, n> > {};
	template <Boolean e, class t, USize n> struct Case<e, const volatile t[n]> : Mixins::ConstVolatileArray<Abstract::SizedArray<e, t, n> > {};

	template <Boolean e, class t> struct Case<e,		    t[]> : Mixins::Unqualified	     <Abstract::UnsizedArray<e, t> > {};
	template <Boolean e, class t> struct Case<e, const	    t[]> : Mixins::ConstArray	     <Abstract::UnsizedArray<e, t> > {};
	template <Boolean e, class t> struct Case<e,	   volatile t[]> : Mixins::VolatileArray     <Abstract::UnsizedArray<e, t> > {};
	template <Boolean e, class t> struct Case<e, const volatile t[]> : Mixins::ConstVolatileArray<Abstract::UnsizedArray<e, t> > {};

	// MARK: - Specializations: Pointer types

	template <Boolean e, class t> class Case<e, t*> : public Mixins::Unqualified<Abstract::Pointer<t> > {
		private:
		typedef Case<false, t> Pointee;

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

#			if Z_HAS_MEMBER(Type, is_objective_c_instance_pointer)
				enum {is_objective_c_instance_pointer = Pointee::is_objective_c_instance};
#			endif
#		endif

		enum {	indirection_level = Pointee::indirection_level + 1,
			pointer_level	  = Pointee::pointer_level     + 1
		};
	};

	template <Boolean e, class c, class m> class Case<e, m c::*> : public Mixins::Unqualified<Abstract::MemberPointer<m c::*, c, m> > {
		private:
		typedef Case<false, m> Pointee;

		public:
		enum {	has_qualified_indirectee   = Pointee::is_qualified,
			is_member_function_pointer = Pointee::is_function,
			is_data_member_pointer	   = !is_member_function_pointer
		};

		enum {indirection_level = Pointee::indirection_level + 1};
	};

	// MARK: - Specializations: Reference types

	template <Boolean e, class t> class Case<e, t&> : public Mixins::Unqualified<Abstract::LValueReference<t> > {
		private:
		typedef Case<false, t> Referencee;

		public:
		enum {	has_qualified_indirectee     = Referencee::is_qualified,
			is_function_reference	     = Referencee::is_function,
			is_function_lvalue_reference = is_function_reference,
			is_data_reference	     = !is_function_reference,
			is_data_lvalue_reference     = is_data_reference
		};

		enum {indirection_level = Referencee::indirection_level + 1};
	};

#	if Z_DIALECT_HAS(CPP11, RVALUE_REFERENCE)
		template <Boolean e, class t> class Case<e, t&&> : public Mixins::Unqualified<Abstract::RValueReference<t> > {
			private:
			typedef Case<false, t> Referencee;

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

	// http://www.open-std.org/jtc1/sc22/wg21/docs/cwg_closed.html#2355

#	define Z_z_NORMAL_SPECIALIZATION_GROUP(arity)			      \
		Z_z_SPECIALIZATION_PAIR(arity, Z_EMPTY	     , Unqualified  ) \
		Z_z_SPECIALIZATION_PAIR(arity, const	     , Const	    ) \
		Z_z_SPECIALIZATION_PAIR(arity, const volatile, ConstVolatile) \
		Z_z_SPECIALIZATION_PAIR(arity,	     volatile, Volatile	    )

#	if Z_DIALECT_HAS(CPP11, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)
#		define Z_z_REFERENCE_SPECIALIZATION_GROUP(arity)			       \
			Z_z_SPECIALIZATION_PAIR(arity,		      & , LValue	     ) \
			Z_z_SPECIALIZATION_PAIR(arity,		      &&, RValue	     ) \
			Z_z_SPECIALIZATION_PAIR(arity, const	      & , ConstLValue	     ) \
			Z_z_SPECIALIZATION_PAIR(arity, const	      &&, ConstRValue	     ) \
			Z_z_SPECIALIZATION_PAIR(arity, const volatile & , ConstVolatileLValue) \
			Z_z_SPECIALIZATION_PAIR(arity, const volatile &&, ConstVolatileRValue) \
			Z_z_SPECIALIZATION_PAIR(arity,	     volatile & , VolatileLValue     ) \
			Z_z_SPECIALIZATION_PAIR(arity,	     volatile &&, VolatileRValue     )
#	else
#		define Z_z_REFERENCE_SPECIALIZATION_GROUP(arity)
#	endif

#	if Z_DIALECT_HAS(GNUPP17, NOEXCEPT_OPERAND_DEDUCTION)
#		define Z_z_NOEXCEPT_PARAMETER Boolean x,
#		define Z_z_NOEXCEPT_SPECIFIER noexcept(x)
#		define Z_z_NOEXCEPT_ARGUMENT  x,
#	elif Z_DIALECT_HAS(CPP17, NOEXCEPT_AS_PART_OF_THE_FUNCTION_TYPE)
#		define Z_z_NOEXCEPT_PARAMETER
#		define Z_z_NOEXCEPT_SPECIFIER
#		define Z_z_NOEXCEPT_ARGUMENT  false,
#	else
#		define Z_z_NOEXCEPT_PARAMETER
#		define Z_z_NOEXCEPT_SPECIFIER
#		define Z_z_NOEXCEPT_ARGUMENT
#	endif

#	if Z_DIALECT_HAS(CPP11, VARIADIC_TEMPLATE)

#		define Z_z_SPECIALIZATION_PAIR(dummy, qualifiers, Qualifiers)						  \
															  \
			template <Boolean e, Z_z_NOEXCEPT_PARAMETER class r, class... p>				  \
			struct Case<e, r(p...) qualifiers Z_z_NOEXCEPT_SPECIFIER>					  \
			: Mixins::Qualifiers##Function<Abstract::NonVariadicFunction<Z_z_NOEXCEPT_ARGUMENT r, p...> > {}; \
															  \
			template <Boolean e, Z_z_NOEXCEPT_PARAMETER class r, class... p>				  \
			struct Case<e, r(p..., ...) qualifiers Z_z_NOEXCEPT_SPECIFIER>					  \
			: Mixins::Qualifiers##Function<Abstract::VariadicFunction<Z_z_NOEXCEPT_ARGUMENT r, p...> > {};

		Z_z_NORMAL_SPECIALIZATION_GROUP	  (-)
		Z_z_REFERENCE_SPECIALIZATION_GROUP(-)

#	else
#		define Z_z_SPECIALIZATION_PAIR(arity, qualifiers, Qualifiers)								       \
																	       \
			template <Boolean e, Z_z_NOEXCEPT_PARAMETER class r Z_IF(arity)(Z_COMMA) Z_APPEND_INDEX_FOR_##arity(class p, Z_COMMA)> \
			struct Case<e, r(Z_APPEND_INDEX_FOR_##arity(p, Z_COMMA)) qualifiers Z_z_NOEXCEPT_SPECIFIER>			       \
			: Mixins::Qualifiers##Function<Abstract::NonVariadicFunctionWith##arity##Parameters<				       \
				Z_z_NOEXCEPT_ARGUMENT r Z_IF(arity)(Z_COMMA) Z_APPEND_INDEX_FOR_##arity(p, Z_COMMA)			       \
			> > {};														       \
																	       \
			template <Boolean e, Z_z_NOEXCEPT_PARAMETER class r Z_IF(arity)(Z_COMMA) Z_APPEND_INDEX_FOR_##arity(class p, Z_COMMA)> \
			struct Case<e, r(Z_APPEND_INDEX_FOR_##arity(p, Z_COMMA) Z_IF(arity)(Z_COMMA) ...) qualifiers Z_z_NOEXCEPT_SPECIFIER>   \
			: Mixins::Qualifiers##Function<Abstract::VariadicFunctionWith##arity##Parameters<				       \
				Z_z_NOEXCEPT_ARGUMENT r Z_IF(arity)(Z_COMMA) Z_APPEND_INDEX_FOR_##arity(p, Z_COMMA)			       \
			> > {};

		Z_CALL_WITH_INDEX_FOR_32(Z_z_NORMAL_SPECIALIZATION_GROUP,    Z_EMPTY)
		Z_CALL_WITH_INDEX_FOR_32(Z_z_REFERENCE_SPECIALIZATION_GROUP, Z_EMPTY)
#	endif

#	if !Z_DIALECT_HAS(GNUPP17, NOEXCEPT_OPERAND_DEDUCTION) && Z_DIALECT_HAS(CPP17, NOEXCEPT_AS_PART_OF_THE_FUNCTION_TYPE)
#		undef  Z_z_NOEXCEPT_SPECIFIER
#		define Z_z_NOEXCEPT_SPECIFIER noexcept
#		undef  Z_z_NOEXCEPT_ARGUMENT
#		define Z_z_NOEXCEPT_ARGUMENT  true,

#		if Z_DIALECT_HAS(CPP11, VARIADIC_TEMPLATE)
			Z_z_NORMAL_SPECIALIZATION_GROUP	  (-)
			Z_z_REFERENCE_SPECIALIZATION_GROUP(-)
#		else
			Z_CALL_WITH_INDEX_FOR_32(Z_z_NORMAL_SPECIALIZATION_GROUP,    Z_EMPTY)
			Z_CALL_WITH_INDEX_FOR_32(Z_z_REFERENCE_SPECIALIZATION_GROUP, Z_EMPTY)
#		endif
#	endif

#	undef Z_z_NORMAL_SPECIALIZATION_GROUP
#	undef Z_z_REFERENCE_SPECIALIZATION_GROUP
#	undef Z_z_NOEXCEPT_PARAMETER
#	undef Z_z_NOEXCEPT_SPECIFIER
#	undef Z_z_NOEXCEPT_ARGUMENT
#	undef Z_z_SPECIALIZATION

	// MARK: - Specializations: Block object types (Apple extension)

#	if Z_DIALECT_HAS(APPLE_C, BLOCK_OBJECT)
#		if Z_DIALECT_HAS(CPP11, VARIADIC_TEMPLATE)
			template <Boolean e, class r, class... p> struct Case<e, r(^)(p...)> : Abstract::Valid {
				enum {is_block_object = true};
			};

#		else
			// TODO
#		endif
#	endif

	// MARK: - Specializations: Objective-C types

#	if Z_LANGUAGE_INCLUDES(OBJECTIVE_CPP)
		template <Boolean e> struct Case<e, TypeRemovePointer<id   >::type> : Mixins::Unqualified<Abstract::ObjectiveCObject> {};
		template <Boolean e> struct Case<e, TypeRemovePointer<Class>::type> : Mixins::Unqualified<Abstract::ObjectiveCClass > {};
#	endif

	// MARK: - Specializations: Type qualifiers

	template <Boolean e, class t> struct Case<e, const	    t> : Mixins::Const	      <Case<false, t>::is_number, Case<e, t> > {};
	template <Boolean e, class t> struct Case<e, const volatile t> : Mixins::ConstVolatile<Case<false, t>::is_number, Case<e, t> > {};
	template <Boolean e, class t> struct Case<e,	   volatile t> : Mixins::Volatile     <Case<false, t>::is_number, Case<e, t> > {};

	// MARK: - Detail build

	template <class t, class c = Case<true, t> > struct Build : Mixins::Kind<
		c::is_storable
			? (c::is_member_pointer
				? (c::is_member_function_pointer
					? (c::has_qualified_indirectee
						? Mixins::NonConvertibleMemberFunctionPointer
						: Mixins::ConvertibleMemberFunctionPointer)
					: Mixins::DataMemberPointer)
				: (c::is_pointer
					? (c::is_void_pointer
						? Mixins::VoidPointer
						: (c::is_function_pointer
							? Mixins::FunctionPointer
							: Mixins::Pointer))
					: (c::is_reference
						? (c::is_function_reference
							? Mixins::FunctionReference
							: Mixins::Reference)
						: (c::is_statically_allocatable
							? Mixins::StaticallyAllocatableValue
							: Mixins::NonStaticallyAllocatableValue))))
			: (c::is_void
				? Mixins::Void
				: (c::is_qualified
					? Mixins::NonReferenceableFunction
					: Mixins::ReferenceableFunction)),
	c> {
		enum {is_compound = !Build::is_fundamental};

		typedef typename TernaryType<Build::is_class,
			typename Build<const typename Build::remove_const_volatile>::add_lvalue_reference, // TODO: Preserve volatile?
			t
		>::type to_forwardable;
	};

	template <> struct Build<		NaT> : Abstract::Invalid {};
	template <> struct Build<const		NaT> : Abstract::Invalid {};
	template <> struct Build<const volatile NaT> : Abstract::Invalid {};
	template <> struct Build<      volatile NaT> : Abstract::Invalid {};
}}}

namespace Zeta {

	template <class t> struct Type : ZetaDetail::Type::Build<t> {

#		if Z_DIALECT_HAS(CPP11, TYPE_ALIAS_TEMPLATE)
			template <class klass> using add_member_pointer = typename TypeAddMemberPointer<t,				   klass>::type;
			template <class klass> using to_member_pointer	= typename TypeAddMemberPointer<typename Type::remove_indirection, klass>::type;
#		endif

#		if Z_COMPILER_HAS_MAGIC_CONSTANT(MANGLED_FUNCTION_NAME) && Z_DIALECT_HAS(CPP14, CONSTEXPR_FUNCTION)

#			define Z_z_STRING_MEMBER_FUNCTIONS							\
														\
				static Z_CT(CPP14) USize string_size()						\
					{return type_string_size<t>();}						\
														\
				static Z_CT(CPP14) SizedString<Char, string_size() + 1> string()		\
					{return type_string<t>();}

#			define Z_z_HASH_MEMBER_FUNCTIONS(bits)								    \
				static Z_CT(CPP14) UInt##bits fnv0_##bits () {return Zeta::fnv0_##bits (type_string<t>());} \
				static Z_CT(CPP14) UInt##bits fnv1_##bits () {return Zeta::fnv1_##bits (type_string<t>());} \
				static Z_CT(CPP14) UInt##bits fnv1a_##bits() {return Zeta::fnv1a_##bits(type_string<t>());}

			Z_z_STRING_MEMBER_FUNCTIONS
			Z_z_HASH_MEMBER_FUNCTIONS(32)

#			ifdef Z_UINT64
				Z_z_HASH_MEMBER_FUNCTIONS(64)
#			endif

#		else
#			define Z_z_STRING_MEMBER_FUNCTIONS
#			define Z_z_HASH_MEMBER_FUNCTIONS(bits)
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
				is_bool			      = Type::is_bool,
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

#			if Z_HAS_MEMBER(Type, has_virtual_destructor)
				enum {has_virtual_destructor = Type::has_virtual_destructor};
#			endif

#			if Z_HAS_MEMBER(Type, is_abstract)
				enum {is_abstract = Type::is_abstract};
#			endif

#			if Z_HAS_MEMBER(Type, is_aggregate)
				enum {is_aggregate = Type::is_aggregate};
#			endif

#			if Z_HAS_MEMBER(Type, is_default_constructible)
				enum {is_default_constructible = Type::is_default_constructible};
#			endif

#			if Z_HAS_MEMBER(Type, is_empty)
				enum {is_empty = Type::is_empty};
#			endif

#			if Z_HAS_MEMBER(Type, is_enumeration)
				enum {is_enumeration = Type::is_enumeration};
#			endif

#			if Z_HAS_MEMBER(Type, is_final)
				enum {is_final = Type::is_final};
#			endif

#			if Z_HAS_MEMBER(Type, is_interface_class)
				enum {is_interface_class = Type::is_interface_class};
#			endif

#			if Z_HAS_MEMBER(Type, is_literal)
				enum {is_literal = Type::is_literal};
#			endif

#			if Z_HAS_MEMBER(Type, is_noexcept)
				enum {is_noexcept = Type::is_noexcept};
#			endif

#			if Z_HAS_MEMBER(Type, is_nullptr)
				enum {is_nullptr = Type::is_nullptr};
#			endif

#			if Z_HAS_MEMBER(Type, is_pod)
				enum {is_pod = Type::is_pod};
#			endif

#			if Z_HAS_MEMBER(Type, is_polymorphic)
				enum {is_polymorphic = Type::is_polymorphic};
#			endif

#			if Z_HAS_MEMBER(Type, is_template)
				enum {is_template = Type::is_template};
#			endif

#			if Z_HAS_MEMBER(Type, is_trivially_copy_assignable)
				enum {is_trivially_copy_assignable = Type::is_trivially_copy_assignable};
#			endif

#			if Z_HAS_MEMBER(Type, is_trivially_copy_constructible)
				enum {is_trivially_copy_constructible = Type::is_trivially_copy_constructible};
#			endif

#			if Z_HAS_MEMBER(Type, is_trivially_copyable)
				enum {is_trivially_copyable = Type::is_trivially_copyable};
#			endif

#			if Z_HAS_MEMBER(Type, is_trivially_default_constructible)
				enum {is_trivially_default_constructible = Type::is_trivially_default_constructible};
#			endif

#			if Z_HAS_MEMBER(Type, is_trivially_destructible)
				enum {is_trivially_destructible = Type::is_trivially_destructible};
#			endif

#			if Z_HAS_MEMBER(Type, is_union)
				enum {is_union = Type::is_union};
#			endif

#			if Z_LANGUAGE_INCLUDES(OBJECTIVE_CPP) && Z_DIALECT_HAS(CPP11, EXPRESSION_SFINAE)
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

#			if Z_DIALECT_HAS(CPP11, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)
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

#			if Z_DIALECT_HAS(CPP17, NOEXCEPT_AS_PART_OF_THE_FUNCTION_TYPE)
				typedef typename Type<typename Type::add_noexcept   >::flow add_noexcept;
				typedef typename Type<typename Type::remove_noexcept>::flow remove_noexcept;
#			endif

#			if Z_DIALECT_HAS(CPP11, RVALUE_REFERENCE)
				typedef typename Type<typename Type::add_rvalue_reference>::flow add_rvalue_reference;
				typedef typename Type<typename Type::to_rvalue_reference >::flow to_rvalue_reference;
#			endif

#			if Z_HAS_MEMBER(Type, parameters)
				typedef typename Type::parameters parameters;
#			endif

#			if Z_HAS_MEMBER(Type, underlying_type)
				typedef typename Type<typename Type::underlying_type>::flow underlying_type;
#			endif

#			if Z_DIALECT_HAS(CPP11, TYPE_ALIAS_TEMPLATE)
				template <class klass> using add_member_pointer = typename Type<typename Type::template add_member_pointer<klass> >::flow;
				template <class klass> using to_member_pointer	= typename Type<typename Type::template to_member_pointer <klass> >::flow;
#			endif

#			if Z_HAS_MEMBER(Type, parameter)
				template <zuint index> using parameter = typename Type<typename Type::template parameter<index> >::flow;
#			endif

			Z_z_STRING_MEMBER_FUNCTIONS
			Z_z_HASH_MEMBER_FUNCTIONS(32)

#			ifdef Z_UINT64
				Z_z_HASH_MEMBER_FUNCTIONS(64)
#			endif
		};

#		undef Z_z_STRING_MEMBER_FUNCTIONS
#		undef Z_z_HASH_MEMBER_FUNCTIONS
	};

	template <class t> struct TypeArity			{enum {value = Type<t>::arity			     };};
	template <class t> struct TypeCanDecorateFunction	{enum {value = Type<t>::can_decorate_function	     };};
	template <class t> struct TypeCanDecorateMemberPointer	{enum {value = Type<t>::can_decorate_member_pointer  };};
	template <class t> struct TypeCanDecoratePointer	{enum {value = Type<t>::can_decorate_pointer	     };};
	template <class t> struct TypeCanDecorateReference	{enum {value = Type<t>::can_decorate_reference	     };};
	template <class t> struct TypeCanFormMemberPointer	{enum {value = Type<t>::can_form_member_pointer	     };};
	template <class t> struct TypeCanFormPointer		{enum {value = Type<t>::can_form_pointer	     };};
	template <class t> struct TypeCanFormReference		{enum {value = Type<t>::can_form_reference	     };};
	template <class t> struct TypeDimensionCount		{enum {value = Type<t>::dimension_count		     };};
	template <class t> struct TypeElementCount		{enum {value = Type<t>::element_count		     };};
	template <class t> struct TypeFixedFundamental		{enum {value = Type<t>::fixed_fundamental	     };};
	template <class t> struct TypeFundamental		{enum {value = Type<t>::fundamental		     };};
	template <class t> struct TypeHasQualifiedIndirectee	{enum {value = Type<t>::has_qualified_indirectee     };};
	template <class t> struct TypeIndirectionLevel		{enum {value = Type<t>::indirection_level	     };};
	template <class t> struct TypeIsArithmetic		{enum {value = Type<t>::is_arithmetic		     };};
	template <class t> struct TypeIsArray			{enum {value = Type<t>::is_array		     };};
	template <class t> struct TypeIsBlockObject		{enum {value = Type<t>::is_block_object		     };};
	template <class t> struct TypeIsBool			{enum {value = Type<t>::is_bool			     };};
	template <class t> struct TypeIsClass			{enum {value = Type<t>::is_class		     };};
	template <class t> struct TypeIsCompound		{enum {value = Type<t>::is_compound		     };};
	template <class t> struct TypeIsConst			{enum {value = Type<t>::is_const		     };};
	template <class t> struct TypeIsConstLValue		{enum {value = Type<t>::is_const_lvalue		     };};
	template <class t> struct TypeIsConstRValue		{enum {value = Type<t>::is_const_rvalue		     };};
	template <class t> struct TypeIsConstVolatile		{enum {value = Type<t>::is_const_volatile	     };};
	template <class t> struct TypeIsConstVolatileLValue	{enum {value = Type<t>::is_const_volatile_lvalue     };};
	template <class t> struct TypeIsConstVolatileRValue	{enum {value = Type<t>::is_const_volatile_rvalue     };};
	template <class t> struct TypeIsDataLValueReference	{enum {value = Type<t>::is_data_lvalue_reference     };};
	template <class t> struct TypeIsDataMemberPointer	{enum {value = Type<t>::is_data_member_pointer	     };};
	template <class t> struct TypeIsDataPointer		{enum {value = Type<t>::is_data_pointer		     };};
	template <class t> struct TypeIsDataReference		{enum {value = Type<t>::is_data_reference	     };};
	template <class t> struct TypeIsDataRValueReference	{enum {value = Type<t>::is_data_rvalue_reference     };};
	template <class t> struct TypeIsExact			{enum {value = Type<t>::is_exact		     };};
	template <class t> struct TypeIsIndirection		{enum {value = Type<t>::is_indirection		     };};
	template <class t> struct TypeIsInteger			{enum {value = Type<t>::is_integer		     };};
	template <class t> struct TypeIsIntegral		{enum {value = Type<t>::is_integral		     };};
	template <class t> struct TypeIsFloatingPoint		{enum {value = Type<t>::is_floating_point	     };};
	template <class t> struct TypeIsFunction		{enum {value = Type<t>::is_function		     };};
	template <class t> struct TypeIsFunctionLValueReference {enum {value = Type<t>::is_function_lvalue_reference };};
	template <class t> struct TypeIsFunctionPointer		{enum {value = Type<t>::is_function_pointer	     };};
	template <class t> struct TypeIsFunctionReference	{enum {value = Type<t>::is_function_reference	     };};
	template <class t> struct TypeIsFunctionRValueReference {enum {value = Type<t>::is_function_rvalue_reference };};
	template <class t> struct TypeIsFundamental		{enum {value = Type<t>::is_fundamental		     };};
	template <class t> struct TypeIsLValue			{enum {value = Type<t>::is_lvalue		     };};
	template <class t> struct TypeIsLValueReference		{enum {value = Type<t>::is_lvalue_reference	     };};
	template <class t> struct TypeIsMemberFunctionPointer	{enum {value = Type<t>::is_member_function_pointer   };};
	template <class t> struct TypeIsMemberPointer		{enum {value = Type<t>::is_member_pointer	     };};
	template <class t> struct TypeIsNaT			{enum {value = Type<t>::is_nat			     };};
	template <class t> struct TypeIsNatural			{enum {value = Type<t>::is_natural		     };};
	template <class t> struct TypeIsNumber			{enum {value = Type<t>::is_number		     };};
	template <class t> struct TypeIsObjectiveCClass		{enum {value = Type<t>::is_objective_c_class	     };};
	template <class t> struct TypeIsObjectiveCClassPointer	{enum {value = Type<t>::is_objective_c_class_pointer };};
	template <class t> struct TypeIsObjectiveCObject	{enum {value = Type<t>::is_objective_c_object	     };};
	template <class t> struct TypeIsObjectiveCObjectPointer	{enum {value = Type<t>::is_objective_c_object_pointer};};
	template <class t> struct TypeIsPointer			{enum {value = Type<t>::is_pointer		     };};
	template <class t> struct TypeIsQualified		{enum {value = Type<t>::is_qualified		     };};
	template <class t> struct TypeIsReal			{enum {value = Type<t>::is_real			     };};
	template <class t> struct TypeIsReference		{enum {value = Type<t>::is_reference		     };};
	template <class t> struct TypeIsRValue			{enum {value = Type<t>::is_rvalue		     };};
	template <class t> struct TypeIsRValueReference		{enum {value = Type<t>::is_rvalue_reference	     };};
	template <class t> struct TypeIsScalar			{enum {value = Type<t>::is_scalar		     };};
	template <class t> struct TypeIsSigned			{enum {value = Type<t>::is_signed		     };};
	template <class t> struct TypeIsSimple			{enum {value = Type<t>::is_simple		     };};
	template <class t> struct TypeIsSizedArray		{enum {value = Type<t>::is_sized_array		     };};
	template <class t> struct TypeIsStaticallyAllocatable	{enum {value = Type<t>::is_statically_allocatable    };};
	template <class t> struct TypeIsStorable		{enum {value = Type<t>::is_storable		     };};
	template <class t> struct TypeIsStructure		{enum {value = Type<t>::is_structure		     };};
	template <class t> struct TypeIsUnsigned		{enum {value = Type<t>::is_unsigned		     };};
	template <class t> struct TypeIsUnsizedArray		{enum {value = Type<t>::is_unsized_array	     };};
	template <class t> struct TypeIsValid			{enum {value = Type<t>::is_valid		     };};
	template <class t> struct TypeIsVariadic		{enum {value = Type<t>::is_variadic		     };};
	template <class t> struct TypeIsVariadicFunction	{enum {value = Type<t>::is_variadic_function	     };};
	template <class t> struct TypeIsVoid			{enum {value = Type<t>::is_void			     };};
	template <class t> struct TypeIsVoidPointer		{enum {value = Type<t>::is_void_pointer		     };};
	template <class t> struct TypeIsVolatile		{enum {value = Type<t>::is_volatile		     };};
	template <class t> struct TypeIsVolatileLValue		{enum {value = Type<t>::is_volatile_lvalue	     };};
	template <class t> struct TypeIsVolatileRValue		{enum {value = Type<t>::is_volatile_rvalue	     };};
	template <class t> struct TypeIssConst			{enum {value = Type<t>::iss_const		     };};
	template <class t> struct TypeIssConstLValue		{enum {value = Type<t>::iss_const_lvalue	     };};
	template <class t> struct TypeIssConstRValue		{enum {value = Type<t>::iss_const_rvalue	     };};
	template <class t> struct TypeIssConstVolatile		{enum {value = Type<t>::iss_const_volatile	     };};
	template <class t> struct TypeIssLValue			{enum {value = Type<t>::iss_lvalue		     };};
	template <class t> struct TypeIssRValue			{enum {value = Type<t>::iss_rvalue		     };};
	template <class t> struct TypeIssVolatile		{enum {value = Type<t>::iss_volatile		     };};
	template <class t> struct TypeIssVolatileLValue		{enum {value = Type<t>::iss_volatile_lvalue	     };};
	template <class t> struct TypeIssVolatileRValue		{enum {value = Type<t>::iss_volatile_rvalue	     };};
	template <class t> struct TypeNumberFormat		{enum {value = Type<t>::number_format		     };};
	template <class t> struct TypeNumberSet			{enum {value = Type<t>::number_set		     };};
	template <class t> struct TypePointerLevel		{enum {value = Type<t>::pointer_level		     };};

#	if Z_HAS(TypeHasVirtualDestructor)
		template <class t> struct TypeHasVirtualDestructor {enum {value = Type<t>::has_virtual_destructor};};
#	endif

#	if Z_HAS(TypeIsAbstract)
		template <class t> struct TypeIsAbstract {enum {value = Type<t>::is_abstract};};
#	endif

#	if Z_HAS(TypeIsAggregate)
		template <class t> struct TypeIsAggregate {enum {value = Type<t>::is_aggregate};};
#	endif

#	if Z_HAS(TypeIsDefaultConstructible)
		template <class t> struct TypeIsDefaultConstructible {enum {value = Type<t>::is_default_constructible};};
#	endif

#	if Z_HAS(TypeIsEmpty)
		template <class t> struct TypeIsEmpty {enum {value = Type<t>::is_empty};};
#	endif

#	if Z_HAS(TypeIsEnumeration)
		template <class t> struct TypeIsEnumeration {enum {value = Type<t>::is_enumeration};};
#	endif

#	if Z_HAS(TypeIsFinal)
		template <class t> struct TypeIsFinal {enum {value = Type<t>::is_final};};
#	endif

#	if Z_HAS(TypeIsInterfaceClass)
		template <class t> struct TypeIsInterfaceClass {enum {value = Type<t>::is_interface_class};};
#	endif

#	if Z_HAS(TypeIsLiteral)
		template <class t> struct TypeIsLiteral {enum {value = Type<t>::is_literal};};
#	endif

#	if Z_HAS(TypeIsNoexcept)
		template <class t> struct TypeIsNoexcept {enum {value = Type<t>::is_noexcept};};
#	endif

#	if Z_HAS(TypeIsNullPtr)
		template <class t> struct TypeIsNullPtr {enum {value = Type<t>::is_nullptr};};
#	endif

#	if Z_HAS(TypeIsPOD)
		template <class t> struct TypeIsPOD {enum {value = Type<t>::is_pod};};
#	endif

#	if Z_HAS(TypeIsPolymorphic)
		template <class t> struct TypeIsPolymorphic {enum {value = Type<t>::is_polymorphic};};
#	endif

#	if Z_HAS(TypeIsTemplate)
		template <class t> struct TypeIsTemplate {enum {value = Type<t>::is_template};};
#	endif

#	if Z_HAS(TypeIsTriviallyCopyAssignable)
		template <class t> struct TypeIsTriviallyCopyAssignable {enum {value = Type<t>::is_trivially_copy_assignable};};
#	endif

#	if Z_HAS(TypeIsTriviallyCopyConstructible)
		template <class t> struct TypeIsTriviallyCopyConstructible {enum {value = Type<t>::is_trivially_copy_constructible};};
#	endif

#	if Z_HAS(TypeIsTriviallyCopyable)
		template <class t> struct TypeIsTriviallyCopyable {enum {value = Type<t>::is_trivially_copyable};};
#	endif

#	if Z_HAS(TypeIsTriviallyDefaultConstructible)
		template <class t> struct TypeIsTriviallyDefaultConstructible {enum {value = Type<t>::is_trivially_default_constructible};};
#	endif

#	if Z_HAS(TypeIsTriviallyDestructible)
		template <class t> struct TypeIsTriviallyDestructible {enum {value = Type<t>::is_trivially_destructible};};
#	endif

#	if Z_HAS(TypeIsUnion)
		template <class t> struct TypeIsUnion {enum {value = Type<t>::is_union};};
#	endif

#	if Z_LANGUAGE_INCLUDES(OBJECTIVE_CPP) && Z_DIALECT_HAS(CPP11, EXPRESSION_SFINAE)
		template <class t> struct TypeIsObjectiveCInstance	  {enum {value = Type<t>::is_objective_c_instance	 };};
		template <class t> struct TypeIsObjectiveCInstancePointer {enum {value = Type<t>::is_objective_c_instance_pointer};};
#	endif

	template <class t> struct TypeAddConst		      {typedef typename Type<t>::add_const		    type;};
	template <class t> struct TypeAddConstVolatile	      {typedef typename Type<t>::add_const_volatile	    type;};
	template <class t> struct TypeAddLValueReference      {typedef typename Type<t>::add_lvalue_reference	    type;};
	template <class t> struct TypeAddPointer	      {typedef typename Type<t>::add_pointer		    type;};
	template <class t> struct TypeAddVolatile	      {typedef typename Type<t>::add_volatile		    type;};
	template <class t> struct TypeClassType		      {typedef typename Type<t>::class_type		    type;};
	template <class t> struct TypeElementType	      {typedef typename Type<t>::element_type		    type;};
	template <class t> struct TypeIndirecteeType	      {typedef typename Type<t>::indirectee_type	    type;};
	template <class t> struct TypePointeeType	      {typedef typename Type<t>::pointee_type		    type;};
	template <class t> struct TypeReferenceeType	      {typedef typename Type<t>::referencee_type	    type;};
	template <class t> struct TypeRemoveArray	      {typedef typename Type<t>::remove_array		    type;};
	template <class t> struct TypeRemoveConst	      {typedef typename Type<t>::remove_const		    type;};
	template <class t> struct TypeRemoveConstThis	      {typedef typename Type<t>::remove_const_this	    type;};
	template <class t> struct TypeRemoveConstVolatile     {typedef typename Type<t>::remove_const_volatile	    type;};
	template <class t> struct TypeRemoveConstVolatileThis {typedef typename Type<t>::remove_const_volatile_this type;};
	template <class t> struct TypeRemoveIndirection	      {typedef typename Type<t>::remove_indirection	    type;};
	template <class t> struct TypeRemoveMemberPointer     {typedef typename Type<t>::remove_member_pointer	    type;};
	template <class t> struct TypeRemoveReference	      {typedef typename Type<t>::remove_reference	    type;};
	template <class t> struct TypeRemoveThis	      {typedef typename Type<t>::remove_this		    type;};
	template <class t> struct TypeRemoveVolatile	      {typedef typename Type<t>::remove_volatile	    type;};
	template <class t> struct TypeRemoveVolatileThis      {typedef typename Type<t>::remove_volatile_this	    type;};
	template <class t> struct TypeReturnType	      {typedef typename Type<t>::return_type		    type;};
	template <class t> struct TypeToConst		      {typedef typename Type<t>::to_const		    type;};
	template <class t> struct TypeToConstVolatile	      {typedef typename Type<t>::to_const_volatile	    type;};
	template <class t> struct TypeToForwardable	      {typedef typename Type<t>::to_forwardable		    type;};
	template <class t> struct TypeToFunction	      {typedef typename Type<t>::to_function		    type;};
	template <class t> struct TypeToLValueReference	      {typedef typename Type<t>::to_lvalue_reference	    type;};
	template <class t> struct TypeToOpaque		      {typedef typename Type<t>::to_opaque		    type;};
	template <class t> struct TypeToPointer		      {typedef typename Type<t>::to_pointer		    type;};
	template <class t> struct TypeToSigned		      {typedef typename Type<t>::to_signed		    type;};
	template <class t> struct TypeToUnqualified	      {typedef typename Type<t>::to_unqualified		    type;};
	template <class t> struct TypeToUnsigned	      {typedef typename Type<t>::to_unsigned		    type;};
	template <class t> struct TypeToVolatile	      {typedef typename Type<t>::to_volatile		    type;};
	template <class t> struct TypeToWrap		      {typedef typename Type<t>::to_wrap		    type;};

	template <class t, class klass> struct TypeToMemberPointer {
		typedef typename TypeAddMemberPointer<typename Type<t>::remove_indirection, klass>::type type;
	};

#	if Z_DIALECT_HAS(CPP11, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)
		template <class t> struct TypeAddConstLValue	     {typedef typename Type<t>::add_const_lvalue	  type;};
		template <class t> struct TypeAddConstRValue	     {typedef typename Type<t>::add_const_rvalue	  type;};
		template <class t> struct TypeAddConstVolatileLValue {typedef typename Type<t>::add_const_volatile_lvalue type;};
		template <class t> struct TypeAddConstVolatileRValue {typedef typename Type<t>::add_const_volatile_rvalue type;};
		template <class t> struct TypeAddLValue		     {typedef typename Type<t>::add_lvalue		  type;};
		template <class t> struct TypeAddRValue		     {typedef typename Type<t>::add_rvalue		  type;};
		template <class t> struct TypeAddVolatileLValue	     {typedef typename Type<t>::add_volatile_lvalue	  type;};
		template <class t> struct TypeAddVolatileRValue	     {typedef typename Type<t>::add_volatile_rvalue	  type;};
		template <class t> struct TypeToConstLValue	     {typedef typename Type<t>::to_const_lvalue		  type;};
		template <class t> struct TypeToConstRValue	     {typedef typename Type<t>::to_const_rvalue		  type;};
		template <class t> struct TypeToConstVolatileLValue  {typedef typename Type<t>::to_const_volatile_lvalue  type;};
		template <class t> struct TypeToConstVolatileRValue  {typedef typename Type<t>::to_const_volatile_rvalue  type;};
		template <class t> struct TypeToLValue		     {typedef typename Type<t>::to_lvalue		  type;};
		template <class t> struct TypeToRValue		     {typedef typename Type<t>::to_rvalue		  type;};
		template <class t> struct TypeToVolatileLValue	     {typedef typename Type<t>::to_volatile_lvalue	  type;};
		template <class t> struct TypeToVolatileRValue	     {typedef typename Type<t>::to_volatile_rvalue	  type;};
#	endif

#	if Z_DIALECT_HAS(CPP17, NOEXCEPT_AS_PART_OF_THE_FUNCTION_TYPE)
		template <class t> struct TypeAddNoexcept    {typedef typename Type<t>::add_noexcept	type;};
		template <class t> struct TypeRemoveNoexcept {typedef typename Type<t>::remove_noexcept type;};
#	endif

#	if Z_DIALECT_HAS(CPP11, RVALUE_REFERENCE)
		template <class t> struct TypeAddRValueReference {typedef typename Type<t>::add_rvalue_reference type;};
		template <class t> struct TypeToRValueReference	 {typedef typename Type<t>::to_rvalue_reference	 type;};
#	endif

#	if Z_HAS(TypeParameters)
		template <class t> struct TypeParameters {typedef typename Type<t>::parameters type;};
#	endif

#	if Z_HAS(TypeUnderlyingType)
		template <class t> struct TypeUnderlyingType {typedef typename Type<t>::underlying_type	type;};
#	endif

#	if Z_HAS(TypeParameter)
		template <class t, UInt index> struct TypeParameter {
			typedef typename TypeListGet<typename Type<t>::parameters, index>::type type;
		};
#	endif

#	if Z_DIALECT_HAS(CPP14, VARIABLE_TEMPLATE) && Z_DIALECT_HAS_SPECIFIER(CPP11, CONSTEXPR)
		template <class t> static Z_CONSTANT USize   type_arity				= Type<t>::arity;
		template <class t> static Z_CONSTANT Boolean type_can_decorate_function		= Type<t>::can_decorate_function;
		template <class t> static Z_CONSTANT Boolean type_can_decorate_member_pointer	= Type<t>::can_decorate_member_pointer;
		template <class t> static Z_CONSTANT Boolean type_can_decorate_pointer		= Type<t>::can_decorate_pointer;
		template <class t> static Z_CONSTANT Boolean type_can_decorate_reference	= Type<t>::can_decorate_reference;
		template <class t> static Z_CONSTANT Boolean type_can_form_member_pointer	= Type<t>::can_form_member_pointer;
		template <class t> static Z_CONSTANT Boolean type_can_form_pointer		= Type<t>::can_form_pointer;
		template <class t> static Z_CONSTANT Boolean type_can_form_reference		= Type<t>::can_form_reference;
		template <class t> static Z_CONSTANT USize   type_dimension_count		= Type<t>::dimension_count;
		template <class t> static Z_CONSTANT USize   type_element_count			= Type<t>::element_count;
		template <class t> static Z_CONSTANT UInt8   type_fixed_fundamental		= Type<t>::fixed_fundamental;
		template <class t> static Z_CONSTANT UInt8   type_fundamental			= Type<t>::fundamental;
		template <class t> static Z_CONSTANT Boolean type_has_qualified_indirectee	= Type<t>::has_qualified_indirectee;
		template <class t> static Z_CONSTANT UInt    type_indirection_level		= Type<t>::indirection_level;
		template <class t> static Z_CONSTANT Boolean type_is_arithmetic			= Type<t>::is_arithmetic;
		template <class t> static Z_CONSTANT Boolean type_is_array			= Type<t>::is_array;
		template <class t> static Z_CONSTANT Boolean type_is_block_object		= Type<t>::is_block_object;
		template <class t> static Z_CONSTANT Boolean type_is_bool			= Type<t>::is_bool;
		template <class t> static Z_CONSTANT Boolean type_is_class			= Type<t>::is_class;
		template <class t> static Z_CONSTANT Boolean type_is_compound			= Type<t>::is_compound;
		template <class t> static Z_CONSTANT Boolean type_is_const			= Type<t>::is_const;
		template <class t> static Z_CONSTANT Boolean type_is_const_lvalue		= Type<t>::is_const_lvalue;
		template <class t> static Z_CONSTANT Boolean type_is_const_rvalue		= Type<t>::is_const_rvalue;
		template <class t> static Z_CONSTANT Boolean type_is_const_volatile		= Type<t>::is_const_volatile;
		template <class t> static Z_CONSTANT Boolean type_is_const_volatile_lvalue	= Type<t>::is_const_volatile_lvalue;
		template <class t> static Z_CONSTANT Boolean type_is_const_volatile_rvalue	= Type<t>::is_const_volatile_rvalue;
		template <class t> static Z_CONSTANT Boolean type_is_data_lvalue_reference	= Type<t>::is_data_lvalue_reference;
		template <class t> static Z_CONSTANT Boolean type_is_data_member_pointer	= Type<t>::is_data_member_pointer;
		template <class t> static Z_CONSTANT Boolean type_is_data_pointer		= Type<t>::is_data_pointer;
		template <class t> static Z_CONSTANT Boolean type_is_data_reference		= Type<t>::is_data_reference;
		template <class t> static Z_CONSTANT Boolean type_is_data_rvalue_reference	= Type<t>::is_data_rvalue_reference;
		template <class t> static Z_CONSTANT Boolean type_is_exact			= Type<t>::is_exact;
		template <class t> static Z_CONSTANT Boolean type_is_indirection		= Type<t>::is_indirection;
		template <class t> static Z_CONSTANT Boolean type_is_integer			= Type<t>::is_integer;
		template <class t> static Z_CONSTANT Boolean type_is_integral			= Type<t>::is_integral;
		template <class t> static Z_CONSTANT Boolean type_is_floating_point		= Type<t>::is_floating_point;
		template <class t> static Z_CONSTANT Boolean type_is_function			= Type<t>::is_function;
		template <class t> static Z_CONSTANT Boolean type_is_function_lvalue_reference	= Type<t>::is_function_lvalue_reference;
		template <class t> static Z_CONSTANT Boolean type_is_function_pointer		= Type<t>::is_function_pointer;
		template <class t> static Z_CONSTANT Boolean type_is_function_reference		= Type<t>::is_function_reference;
		template <class t> static Z_CONSTANT Boolean type_is_function_rvalue_reference	= Type<t>::is_function_rvalue_reference;
		template <class t> static Z_CONSTANT Boolean type_is_fundamental		= Type<t>::is_fundamental;
		template <class t> static Z_CONSTANT Boolean type_is_lvalue			= Type<t>::is_lvalue;
		template <class t> static Z_CONSTANT Boolean type_is_lvalue_reference		= Type<t>::is_lvalue_reference;
		template <class t> static Z_CONSTANT Boolean type_is_member_function_pointer	= Type<t>::is_member_function_pointer;
		template <class t> static Z_CONSTANT Boolean type_is_member_pointer		= Type<t>::is_member_pointer;
		template <class t> static Z_CONSTANT Boolean type_is_nat			= Type<t>::is_nat;
		template <class t> static Z_CONSTANT Boolean type_is_natural			= Type<t>::is_natural;
		template <class t> static Z_CONSTANT Boolean type_is_number			= Type<t>::is_number;
		template <class t> static Z_CONSTANT Boolean type_is_objective_c_class		= Type<t>::is_objective_c_class;
		template <class t> static Z_CONSTANT Boolean type_is_objective_c_class_pointer	= Type<t>::is_objective_c_class_pointer;
		template <class t> static Z_CONSTANT Boolean type_is_objective_c_object		= Type<t>::is_objective_c_object;
		template <class t> static Z_CONSTANT Boolean type_is_objective_c_object_pointer = Type<t>::is_objective_c_object_pointer;
		template <class t> static Z_CONSTANT Boolean type_is_pointer			= Type<t>::is_pointer;
		template <class t> static Z_CONSTANT Boolean type_is_qualified			= Type<t>::is_qualified;
		template <class t> static Z_CONSTANT Boolean type_is_real			= Type<t>::is_real;
		template <class t> static Z_CONSTANT Boolean type_is_reference			= Type<t>::is_reference;
		template <class t> static Z_CONSTANT Boolean type_is_rvalue			= Type<t>::is_rvalue;
		template <class t> static Z_CONSTANT Boolean type_is_rvalue_reference		= Type<t>::is_rvalue_reference;
		template <class t> static Z_CONSTANT Boolean type_is_scalar			= Type<t>::is_scalar;
		template <class t> static Z_CONSTANT Boolean type_is_signed			= Type<t>::is_signed;
		template <class t> static Z_CONSTANT Boolean type_is_simple			= Type<t>::is_simple;
		template <class t> static Z_CONSTANT Boolean type_is_sized_array		= Type<t>::is_sized_array;
		template <class t> static Z_CONSTANT Boolean type_is_statically_allocatable	= Type<t>::is_statically_allocatable;
		template <class t> static Z_CONSTANT Boolean type_is_storable			= Type<t>::is_storable;
		template <class t> static Z_CONSTANT Boolean type_is_structure			= Type<t>::is_structure;
		template <class t> static Z_CONSTANT Boolean type_is_unsigned			= Type<t>::is_unsigned;
		template <class t> static Z_CONSTANT Boolean type_is_unsized_array		= Type<t>::is_unsized_array;
		template <class t> static Z_CONSTANT Boolean type_is_valid			= Type<t>::is_valid;
		template <class t> static Z_CONSTANT Boolean type_is_variadic			= Type<t>::is_variadic;
		template <class t> static Z_CONSTANT Boolean type_is_variadic_function		= Type<t>::is_variadic_function;
		template <class t> static Z_CONSTANT Boolean type_is_void			= Type<t>::is_void;
		template <class t> static Z_CONSTANT Boolean type_is_void_pointer		= Type<t>::is_void_pointer;
		template <class t> static Z_CONSTANT Boolean type_is_volatile			= Type<t>::is_volatile;
		template <class t> static Z_CONSTANT Boolean type_is_volatile_lvalue		= Type<t>::is_volatile_lvalue;
		template <class t> static Z_CONSTANT Boolean type_is_volatile_rvalue		= Type<t>::is_volatile_rvalue;
		template <class t> static Z_CONSTANT Boolean type_iss_const			= Type<t>::iss_const;
		template <class t> static Z_CONSTANT Boolean type_iss_const_lvalue		= Type<t>::iss_const_lvalue;
		template <class t> static Z_CONSTANT Boolean type_iss_const_rvalue		= Type<t>::iss_const_rvalue;
		template <class t> static Z_CONSTANT Boolean type_iss_const_volatile		= Type<t>::iss_const_volatile;
		template <class t> static Z_CONSTANT Boolean type_iss_lvalue			= Type<t>::iss_lvalue;
		template <class t> static Z_CONSTANT Boolean type_iss_rvalue			= Type<t>::iss_rvalue;
		template <class t> static Z_CONSTANT Boolean type_iss_volatile			= Type<t>::iss_volatile;
		template <class t> static Z_CONSTANT Boolean type_iss_volatile_lvalue		= Type<t>::iss_volatile_lvalue;
		template <class t> static Z_CONSTANT Boolean type_iss_volatile_rvalue		= Type<t>::iss_volatile_rvalue;
		template <class t> static Z_CONSTANT UInt    type_number_format			= Type<t>::number_format;
		template <class t> static Z_CONSTANT UInt    type_number_set			= Type<t>::number_set;
		template <class t> static Z_CONSTANT UInt    type_pointer_level			= Type<t>::pointer_level;

		template <class a, class b> static Z_CONSTANT Boolean type_is_same = TypeIsSame<a, b>::value;

#		if Z_HAS(TypeIsBase)
			template <class t, class of_type>
			static Z_CONSTANT Boolean type_is_base = TypeIsBase<t, of_type>::value;
#		endif

#		if Z_HAS(TypeIsConvertible)
			template <class t, class to_type>
			static Z_CONSTANT Boolean type_is_convertible = TypeIsConvertible<t, to_type>::value;
#		endif

#		if Z_HAS(TypeIsConstructible)
			template <class t, class... parameters>
			static Z_CONSTANT Boolean type_is_constructible = TypeIsConstructible<t, parameters...>::value;
#		endif

#		if Z_HAS(TypeIsNothrowAssignable)
			template <class t, class from_type>
			static Z_CONSTANT Boolean type_is_nothrow_assignable = TypeIsNothrowAssignable<t, from_type>::value;
#		endif

#		if Z_HAS(TypeIsNothrowConstructible)
			template <class t, class... parameters>
			static Z_CONSTANT Boolean type_is_nothrow_constructible = TypeIsNothrowConstructible<t, parameters...>::value;
#		endif

#		if Z_HAS(TypeIsTriviallyAssignable)
			template <class t, class from_type>
			static Z_CONSTANT Boolean type_is_trivially_assignable = TypeIsTriviallyAssignable<t, from_type>::value;
#		endif

#		if Z_HAS(TypeIsTriviallyConstructible)
			template <class t, class... parameters>
			static Z_CONSTANT Boolean type_is_trivially_constructible = TypeIsTriviallyConstructible<t, parameters...>::value;
#		endif

#		if Z_HAS_MEMBER(Type, has_virtual_destructor)
			template <class t> static Z_CONSTANT Boolean type_has_virtual_destructor = Type<t>::has_virtual_destructor;
#		endif

#		if Z_HAS_MEMBER(Type, is_abstract)
			template <class t> static Z_CONSTANT Boolean type_is_abstract = Type<t>::is_abstract;
#		endif

#		if Z_HAS_MEMBER(Type, is_aggregate)
			template <class t> static Z_CONSTANT Boolean type_is_aggregate = Type<t>::is_aggregate;
#		endif

#		if Z_HAS_MEMBER(Type, is_default_constructible)
			template <class t> static Z_CONSTANT Boolean type_is_default_constructible = Type<t>::is_default_constructible;
#		endif

#		if Z_HAS_MEMBER(Type, is_empty)
			template <class t> static Z_CONSTANT Boolean type_is_empty = Type<t>::is_empty;
#		endif

#		if Z_HAS_MEMBER(Type, is_enumeration)
			template <class t> static Z_CONSTANT Boolean type_is_enumeration = Type<t>::is_enumeration;
#		endif

#		if Z_HAS_MEMBER(Type, is_final)
			template <class t> static Z_CONSTANT Boolean type_is_final = Type<t>::is_final;
#		endif

#		if Z_HAS_MEMBER(Type, is_interface_class)
			template <class t> static Z_CONSTANT Boolean type_is_interface_class = Type<t>::is_interface_class;
#		endif

#		if Z_HAS_MEMBER(Type, is_literal)
			template <class t> static Z_CONSTANT Boolean type_is_literal = Type<t>::is_literal;
#		endif

#		if Z_HAS_MEMBER(Type, is_noexcept)
			template <class t> static Z_CONSTANT Boolean type_is_noexcept = Type<t>::is_noexcept;
#		endif

#		if Z_HAS_MEMBER(Type, is_nullptr)
			template <class t> static Z_CONSTANT Boolean type_is_nullptr = Type<t>::is_nullptr;
#		endif

#		if Z_HAS_MEMBER(Type, is_pod)
			template <class t> static Z_CONSTANT Boolean type_is_pod = Type<t>::is_pod;
#		endif

#		if Z_HAS_MEMBER(Type, is_polymorphic)
			template <class t> static Z_CONSTANT Boolean type_is_polymorphic = Type<t>::is_polymorphic;
#		endif

#		if Z_HAS_MEMBER(Type, is_template)
			template <class t> static Z_CONSTANT Boolean type_is_template = Type<t>::is_template;
#		endif

#		if Z_HAS_MEMBER(Type, is_trivially_copy_assignable)
			template <class t> static Z_CONSTANT Boolean type_is_trivially_copy_assignable = Type<t>::is_trivially_copy_assignable;
#		endif

#		if Z_HAS_MEMBER(Type, is_trivially_copy_constructible)
			template <class t> static Z_CONSTANT Boolean type_is_trivially_copy_constructible = Type<t>::is_trivially_copy_constructible;
#		endif

#		if Z_HAS_MEMBER(Type, is_trivially_copyable)
			template <class t> static Z_CONSTANT Boolean type_is_trivially_copyable = Type<t>::is_trivially_copyable;
#		endif

#		if Z_HAS_MEMBER(Type, is_trivially_default_constructible)
			template <class t> static Z_CONSTANT Boolean type_is_trivially_default_constructible = Type<t>::is_trivially_default_constructible;
#		endif

#		if Z_HAS_MEMBER(Type, is_trivially_destructible)
			template <class t> static Z_CONSTANT Boolean type_is_trivially_destructible = Type<t>::is_trivially_destructible;
#		endif

#		if Z_HAS_MEMBER(Type, is_union)
			template <class t> static Z_CONSTANT Boolean type_is_union = Type<t>::is_union;
#		endif

#		if Z_LANGUAGE_INCLUDES(OBJECTIVE_CPP) && Z_DIALECT_HAS(CPP11, EXPRESSION_SFINAE)
			template <class t> static Z_CONSTANT Boolean type_is_objective_c_instance	  = Type<t>::is_objective_c_instance;
			template <class t> static Z_CONSTANT Boolean type_is_objective_c_instance_pointer = Type<t>::is_objective_c_instance_pointer;
#		endif
#	endif

#	if Z_DIALECT_HAS(CPP11, TYPE_ALIAS_TEMPLATE)
		template <class t> using type_add_const			 = typename Type<t>::add_const;
		template <class t> using type_add_const_volatile	 = typename Type<t>::add_const_volatile;
		template <class t> using type_add_lvalue_reference	 = typename Type<t>::add_lvalue_reference;
		template <class t> using type_add_pointer		 = typename Type<t>::add_pointer;
		template <class t> using type_add_volatile		 = typename Type<t>::add_volatile;
		template <class t> using type_class_type		 = typename Type<t>::class_type;
		template <class t> using type_element_type		 = typename Type<t>::element_type;
		template <class t> using type_indirectee_type		 = typename Type<t>::indirectee_type;
		template <class t> using type_pointee_type		 = typename Type<t>::pointee_type;
		template <class t> using type_referencee_type		 = typename Type<t>::referencee_type;
		template <class t> using type_remove_array		 = typename Type<t>::remove_array;
		template <class t> using type_remove_const		 = typename Type<t>::remove_const;
		template <class t> using type_remove_const_this		 = typename Type<t>::remove_const_this;
		template <class t> using type_remove_const_volatile	 = typename Type<t>::remove_const_volatile;
		template <class t> using type_remove_const_volatile_this = typename Type<t>::remove_const_volatile_this;
		template <class t> using type_remove_indirection	 = typename Type<t>::remove_indirection;
		template <class t> using type_remove_member_pointer	 = typename Type<t>::remove_member_pointer;
		template <class t> using type_remove_pointer		 = typename TypeRemovePointer<t>::type;
		template <class t> using type_remove_reference		 = typename Type<t>::remove_reference;
		template <class t> using type_remove_this		 = typename Type<t>::remove_this;
		template <class t> using type_remove_volatile		 = typename Type<t>::remove_volatile;
		template <class t> using type_remove_volatile_this	 = typename Type<t>::remove_volatile_this;
		template <class t> using type_return_type		 = typename Type<t>::return_type;
		template <class t> using type_to_const			 = typename Type<t>::to_const;
		template <class t> using type_to_const_volatile		 = typename Type<t>::to_const_volatile;
		template <class t> using type_to_forwardable		 = typename Type<t>::to_forwardable;
		template <class t> using type_to_function		 = typename Type<t>::to_function;
		template <class t> using type_to_lvalue_reference	 = typename Type<t>::to_lvalue_reference;
		template <class t> using type_to_opaque			 = typename Type<t>::to_opaque;
		template <class t> using type_to_pointer		 = typename Type<t>::to_pointer;
		template <class t> using type_to_signed			 = typename Type<t>::to_signed;
		template <class t> using type_to_unqualified		 = typename Type<t>::to_unqualified;
		template <class t> using type_to_unsigned		 = typename Type<t>::to_unsigned;
		template <class t> using type_to_volatile		 = typename Type<t>::to_volatile;
		template <class t> using type_to_wrap			 = typename Type<t>::to_wrap;

		template <class t, class klass> using type_add_member_pointer = typename TypeAddMemberPointer<t, klass>::type;
		template <class t, class klass> using type_to_member_pointer  = typename TypeToMemberPointer <t, klass>::type;

#		if Z_DIALECT_HAS(CPP11, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)
			template <class t> using type_add_const_lvalue		= typename Type<t>::add_const_lvalue;
			template <class t> using type_add_const_rvalue		= typename Type<t>::add_const_rvalue;
			template <class t> using type_add_const_volatile_lvalue = typename Type<t>::add_const_volatile_lvalue;
			template <class t> using type_add_const_volatile_rvalue = typename Type<t>::add_const_volatile_rvalue;
			template <class t> using type_add_lvalue		= typename Type<t>::add_lvalue;
			template <class t> using type_add_rvalue		= typename Type<t>::add_rvalue;
			template <class t> using type_add_volatile_lvalue	= typename Type<t>::add_volatile_lvalue;
			template <class t> using type_add_volatile_rvalue	= typename Type<t>::add_volatile_rvalue;
			template <class t> using type_to_const_lvalue		= typename Type<t>::to_const_lvalue;
			template <class t> using type_to_const_rvalue		= typename Type<t>::to_const_rvalue;
			template <class t> using type_to_const_volatile_lvalue	= typename Type<t>::to_const_volatile_lvalue;
			template <class t> using type_to_const_volatile_rvalue	= typename Type<t>::to_const_volatile_rvalue;
			template <class t> using type_to_lvalue			= typename Type<t>::to_lvalue;
			template <class t> using type_to_rvalue			= typename Type<t>::to_rvalue;
			template <class t> using type_to_volatile_lvalue	= typename Type<t>::to_volatile_lvalue;
			template <class t> using type_to_volatile_rvalue	= typename Type<t>::to_volatile_rvalue;
#		endif

#		if Z_DIALECT_HAS(CPP17, NOEXCEPT_AS_PART_OF_THE_FUNCTION_TYPE)
			template <class t> using type_add_noexcept    = typename Type<t>::add_noexcept;
			template <class t> using type_remove_noexcept = typename Type<t>::remove_noexcept;
#		endif

#		if Z_DIALECT_HAS(CPP11, RVALUE_REFERENCE)
			template <class t> using type_add_rvalue_reference = typename Type<t>::add_rvalue_reference;
			template <class t> using type_to_rvalue_reference  = typename Type<t>::to_rvalue_reference;
#		endif

#		if Z_HAS(type_parameters)
			template <class t> using type_parameters = typename Type<t>::parameters;
#		endif

#		if Z_HAS(type_underlying_type)
			template <class t> using type_underlying_type = typename Type<t>::underlying_type;
#		endif

#		if Z_HAS(type_parameter)
			template <class t, UInt index> using type_parameter = typename Type<t>::template parameter<index>;
#		endif
#	endif







#	if Z_DIALECT_HAS(CPP14, VARIABLE_TEMPLATE) && Z_DIALECT_HAS_SPECIFIER(CPP11, CONSTEXPR)
		template <class t> static Z_CONSTANT USize   arity			   = Type<t>::arity;
		template <class t> static Z_CONSTANT Boolean can_decorate_function	   = Type<t>::can_decorate_function;
		template <class t> static Z_CONSTANT Boolean can_decorate_member_pointer   = Type<t>::can_decorate_member_pointer;
		template <class t> static Z_CONSTANT Boolean can_decorate_pointer	   = Type<t>::can_decorate_pointer;
		template <class t> static Z_CONSTANT Boolean can_decorate_reference	   = Type<t>::can_decorate_reference;
		template <class t> static Z_CONSTANT Boolean can_form_member_pointer	   = Type<t>::can_form_member_pointer;
		template <class t> static Z_CONSTANT Boolean can_form_pointer		   = Type<t>::can_form_pointer;
		template <class t> static Z_CONSTANT Boolean can_form_reference		   = Type<t>::can_form_reference;
		template <class t> static Z_CONSTANT USize   dimension_count		   = Type<t>::dimension_count;
		template <class t> static Z_CONSTANT USize   element_count		   = Type<t>::element_count;
		template <class t> static Z_CONSTANT UInt8   fixed_fundamental		   = Type<t>::fixed_fundamental;
		template <class t> static Z_CONSTANT UInt8   fundamental		   = Type<t>::fundamental;
		template <class t> static Z_CONSTANT Boolean has_qualified_indirectee	   = Type<t>::has_qualified_indirectee;
		template <class t> static Z_CONSTANT UInt    indirection_level		   = Type<t>::indirection_level;
		template <class t> static Z_CONSTANT Boolean is_arithmetic		   = Type<t>::is_arithmetic;
		template <class t> static Z_CONSTANT Boolean is_array			   = Type<t>::is_array;
		template <class t> static Z_CONSTANT Boolean is_block_object		   = Type<t>::is_block_object;
		template <class t> static Z_CONSTANT Boolean is_bool			   = Type<t>::is_bool;
		template <class t> static Z_CONSTANT Boolean is_class			   = Type<t>::is_class;
		template <class t> static Z_CONSTANT Boolean is_compound		   = Type<t>::is_compound;
		template <class t> static Z_CONSTANT Boolean is_const			   = Type<t>::is_const;
		template <class t> static Z_CONSTANT Boolean is_const_lvalue		   = Type<t>::is_const_lvalue;
		template <class t> static Z_CONSTANT Boolean is_const_rvalue		   = Type<t>::is_const_rvalue;
		template <class t> static Z_CONSTANT Boolean is_const_volatile		   = Type<t>::is_const_volatile;
		template <class t> static Z_CONSTANT Boolean is_const_volatile_lvalue	   = Type<t>::is_const_volatile_lvalue;
		template <class t> static Z_CONSTANT Boolean is_const_volatile_rvalue	   = Type<t>::is_const_volatile_rvalue;
		template <class t> static Z_CONSTANT Boolean is_data_lvalue_reference	   = Type<t>::is_data_lvalue_reference;
		template <class t> static Z_CONSTANT Boolean is_data_member_pointer	   = Type<t>::is_data_member_pointer;
		template <class t> static Z_CONSTANT Boolean is_data_pointer		   = Type<t>::is_data_pointer;
		template <class t> static Z_CONSTANT Boolean is_data_reference		   = Type<t>::is_data_reference;
		template <class t> static Z_CONSTANT Boolean is_data_rvalue_reference	   = Type<t>::is_data_rvalue_reference;
		template <class t> static Z_CONSTANT Boolean is_exact			   = Type<t>::is_exact;
		template <class t> static Z_CONSTANT Boolean is_indirection		   = Type<t>::is_indirection;
		template <class t> static Z_CONSTANT Boolean is_integer			   = Type<t>::is_integer;
		template <class t> static Z_CONSTANT Boolean is_integral		   = Type<t>::is_integral;
		template <class t> static Z_CONSTANT Boolean is_floating_point		   = Type<t>::is_floating_point;
		template <class t> static Z_CONSTANT Boolean is_function		   = Type<t>::is_function;
		template <class t> static Z_CONSTANT Boolean is_function_lvalue_reference  = Type<t>::is_function_lvalue_reference;
		template <class t> static Z_CONSTANT Boolean is_function_pointer	   = Type<t>::is_function_pointer;
		template <class t> static Z_CONSTANT Boolean is_function_reference	   = Type<t>::is_function_reference;
		template <class t> static Z_CONSTANT Boolean is_function_rvalue_reference  = Type<t>::is_function_rvalue_reference;
		template <class t> static Z_CONSTANT Boolean is_fundamental		   = Type<t>::is_fundamental;
		template <class t> static Z_CONSTANT Boolean is_lvalue			   = Type<t>::is_lvalue;
		template <class t> static Z_CONSTANT Boolean is_lvalue_reference	   = Type<t>::is_lvalue_reference;
		template <class t> static Z_CONSTANT Boolean is_member_function_pointer	   = Type<t>::is_member_function_pointer;
		template <class t> static Z_CONSTANT Boolean is_member_pointer		   = Type<t>::is_member_pointer;
		template <class t> static Z_CONSTANT Boolean is_nat			   = Type<t>::is_nat;
		template <class t> static Z_CONSTANT Boolean is_natural			   = Type<t>::is_natural;
		template <class t> static Z_CONSTANT Boolean is_number			   = Type<t>::is_number;
		template <class t> static Z_CONSTANT Boolean is_objective_c_class	   = Type<t>::is_objective_c_class;
		template <class t> static Z_CONSTANT Boolean is_objective_c_class_pointer  = Type<t>::is_objective_c_class_pointer;
		template <class t> static Z_CONSTANT Boolean is_objective_c_object	   = Type<t>::is_objective_c_object;
		template <class t> static Z_CONSTANT Boolean is_objective_c_object_pointer = Type<t>::is_objective_c_object_pointer;
		template <class t> static Z_CONSTANT Boolean is_pointer			   = Type<t>::is_pointer;
		template <class t> static Z_CONSTANT Boolean is_qualified		   = Type<t>::is_qualified;
		template <class t> static Z_CONSTANT Boolean is_real			   = Type<t>::is_real;
		template <class t> static Z_CONSTANT Boolean is_reference		   = Type<t>::is_reference;
		template <class t> static Z_CONSTANT Boolean is_rvalue			   = Type<t>::is_rvalue;
		template <class t> static Z_CONSTANT Boolean is_rvalue_reference	   = Type<t>::is_rvalue_reference;
		template <class t> static Z_CONSTANT Boolean is_scalar			   = Type<t>::is_scalar;
		template <class t> static Z_CONSTANT Boolean is_signed			   = Type<t>::is_signed;
		template <class t> static Z_CONSTANT Boolean is_simple			   = Type<t>::is_simple;
		template <class t> static Z_CONSTANT Boolean is_sized_array		   = Type<t>::is_sized_array;
		template <class t> static Z_CONSTANT Boolean is_statically_allocatable	   = Type<t>::is_statically_allocatable;
		template <class t> static Z_CONSTANT Boolean is_storable		   = Type<t>::is_storable;
		template <class t> static Z_CONSTANT Boolean is_structure		   = Type<t>::is_structure;
		template <class t> static Z_CONSTANT Boolean is_unsigned		   = Type<t>::is_unsigned;
		template <class t> static Z_CONSTANT Boolean is_unsized_array		   = Type<t>::is_unsized_array;
		template <class t> static Z_CONSTANT Boolean is_valid			   = Type<t>::is_valid;
		template <class t> static Z_CONSTANT Boolean is_variadic		   = Type<t>::is_variadic;
		template <class t> static Z_CONSTANT Boolean is_variadic_function	   = Type<t>::is_variadic_function;
		template <class t> static Z_CONSTANT Boolean is_void			   = Type<t>::is_void;
		template <class t> static Z_CONSTANT Boolean is_void_pointer		   = Type<t>::is_void_pointer;
		template <class t> static Z_CONSTANT Boolean is_volatile		   = Type<t>::is_volatile;
		template <class t> static Z_CONSTANT Boolean is_volatile_lvalue		   = Type<t>::is_volatile_lvalue;
		template <class t> static Z_CONSTANT Boolean is_volatile_rvalue		   = Type<t>::is_volatile_rvalue;
		template <class t> static Z_CONSTANT Boolean iss_const			   = Type<t>::iss_const;
		template <class t> static Z_CONSTANT Boolean iss_const_lvalue		   = Type<t>::iss_const_lvalue;
		template <class t> static Z_CONSTANT Boolean iss_const_rvalue		   = Type<t>::iss_const_rvalue;
		template <class t> static Z_CONSTANT Boolean iss_const_volatile		   = Type<t>::iss_const_volatile;
		template <class t> static Z_CONSTANT Boolean iss_lvalue			   = Type<t>::iss_lvalue;
		template <class t> static Z_CONSTANT Boolean iss_rvalue			   = Type<t>::iss_rvalue;
		template <class t> static Z_CONSTANT Boolean iss_volatile		   = Type<t>::iss_volatile;
		template <class t> static Z_CONSTANT Boolean iss_volatile_lvalue	   = Type<t>::iss_volatile_lvalue;
		template <class t> static Z_CONSTANT Boolean iss_volatile_rvalue	   = Type<t>::iss_volatile_rvalue;
		template <class t> static Z_CONSTANT UInt    number_format		   = Type<t>::number_format;
		template <class t> static Z_CONSTANT UInt    number_set			   = Type<t>::number_set;
		template <class t> static Z_CONSTANT UInt    pointer_level		   = Type<t>::pointer_level;

		template <class a, class b> static Z_CONSTANT Boolean is_same = TypeIsSame<a, b>::value;

#		if Z_HAS(TypeIsBase)
			template <class t, class of_type>
			static Z_CONSTANT Boolean is_base = TypeIsBase<t, of_type>::value;
#		endif

#		if Z_HAS(TypeIsConvertible)
			template <class t, class to_type>
			static Z_CONSTANT Boolean is_convertible = TypeIsConvertible<t, to_type>::value;
#		endif

#		if Z_HAS(TypeIsConstructible)
			template <class t, class... parameters>
			static Z_CONSTANT Boolean is_constructible = TypeIsConstructible<t, parameters...>::value;
#		endif

#		if Z_HAS(TypeIsNothrowAssignable)
			template <class t, class from_type>
			static Z_CONSTANT Boolean is_nothrow_assignable = TypeIsNothrowAssignable<t, from_type>::value;
#		endif

#		if Z_HAS(TypeIsNothrowConstructible)
			template <class t, class... parameters>
			static Z_CONSTANT Boolean is_nothrow_constructible = TypeIsNothrowConstructible<t, parameters...>::value;
#		endif

#		if Z_HAS(TypeIsTriviallyAssignable)
			template <class t, class from_type>
			static Z_CONSTANT Boolean is_trivially_assignable = TypeIsTriviallyAssignable<t, from_type>::value;
#		endif

#		if Z_HAS(TypeIsTriviallyConstructible)
			template <class t, class... parameters>
			static Z_CONSTANT Boolean is_trivially_constructible = TypeIsTriviallyConstructible<t, parameters...>::value;
#		endif

#		if Z_HAS_MEMBER(Type, has_virtual_destructor)
			template <class t> static Z_CONSTANT Boolean has_virtual_destructor = Type<t>::has_virtual_destructor;
#		endif

#		if Z_HAS_MEMBER(Type, is_abstract)
			template <class t> static Z_CONSTANT Boolean is_abstract = Type<t>::is_abstract;
#		endif

#		if Z_HAS_MEMBER(Type, is_aggregate)
			template <class t> static Z_CONSTANT Boolean is_aggregate = Type<t>::is_aggregate;
#		endif

#		if Z_HAS_MEMBER(Type, is_default_constructible)
			template <class t> static Z_CONSTANT Boolean is_default_constructible = Type<t>::is_default_constructible;
#		endif

#		if Z_HAS_MEMBER(Type, is_empty)
			template <class t> static Z_CONSTANT Boolean is_empty = Type<t>::is_empty;
#		endif

#		if Z_HAS_MEMBER(Type, is_enumeration)
			template <class t> static Z_CONSTANT Boolean is_enumeration = Type<t>::is_enumeration;
#		endif

#		if Z_HAS_MEMBER(Type, is_final)
			template <class t> static Z_CONSTANT Boolean is_final = Type<t>::is_final;
#		endif

#		if Z_HAS_MEMBER(Type, is_interface_class)
			template <class t> static Z_CONSTANT Boolean is_interface_class = Type<t>::is_interface_class;
#		endif

#		if Z_HAS_MEMBER(Type, is_literal)
			template <class t> static Z_CONSTANT Boolean is_literal = Type<t>::is_literal;
#		endif

#		if Z_HAS_MEMBER(Type, is_noexcept)
			template <class t> static Z_CONSTANT Boolean is_noexcept = Type<t>::is_noexcept;
#		endif

#		if Z_HAS_MEMBER(Type, is_nullptr)
			template <class t> static Z_CONSTANT Boolean is_nullptr = Type<t>::is_nullptr;
#		endif

#		if Z_HAS_MEMBER(Type, is_pod)
			template <class t> static Z_CONSTANT Boolean is_pod = Type<t>::is_pod;
#		endif

#		if Z_HAS_MEMBER(Type, is_polymorphic)
			template <class t> static Z_CONSTANT Boolean is_polymorphic = Type<t>::is_polymorphic;
#		endif

#		if Z_HAS_MEMBER(Type, is_template)
			template <class t> static Z_CONSTANT Boolean is_template = Type<t>::is_template;
#		endif

#		if Z_HAS_MEMBER(Type, is_trivially_copy_assignable)
			template <class t> static Z_CONSTANT Boolean is_trivially_copy_assignable = Type<t>::is_trivially_copy_assignable;
#		endif

#		if Z_HAS_MEMBER(Type, is_trivially_copy_constructible)
			template <class t> static Z_CONSTANT Boolean is_trivially_copy_constructible = Type<t>::is_trivially_copy_constructible;
#		endif

#		if Z_HAS_MEMBER(Type, is_trivially_copyable)
			template <class t> static Z_CONSTANT Boolean is_trivially_copyable = Type<t>::is_trivially_copyable;
#		endif

#		if Z_HAS_MEMBER(Type, is_trivially_default_constructible)
			template <class t> static Z_CONSTANT Boolean is_trivially_default_constructible = Type<t>::is_trivially_default_constructible;
#		endif

#		if Z_HAS_MEMBER(Type, is_trivially_destructible)
			template <class t> static Z_CONSTANT Boolean is_trivially_destructible = Type<t>::is_trivially_destructible;
#		endif

#		if Z_HAS_MEMBER(Type, is_union)
			template <class t> static Z_CONSTANT Boolean is_union = Type<t>::is_union;
#		endif

#		if Z_LANGUAGE_INCLUDES(OBJECTIVE_CPP) && Z_DIALECT_HAS(CPP11, EXPRESSION_SFINAE)
			template <class t> static Z_CONSTANT Boolean is_objective_c_instance	     = Type<t>::is_objective_c_instance;
			template <class t> static Z_CONSTANT Boolean is_objective_c_instance_pointer = Type<t>::is_objective_c_instance_pointer;
#		endif
#	endif

#	if Z_DIALECT_HAS(CPP11, TYPE_ALIAS_TEMPLATE)
		template <class t> using add_const		    = typename Type<t>::add_const;
		template <class t> using add_const_volatile	    = typename Type<t>::add_const_volatile;
		template <class t> using add_lvalue_reference	    = typename Type<t>::add_lvalue_reference;
		template <class t> using add_pointer		    = typename Type<t>::add_pointer;
		template <class t> using add_volatile		    = typename Type<t>::add_volatile;
		template <class t> using class_type		    = typename Type<t>::class_type;
		template <class t> using element_type		    = typename Type<t>::element_type;
		template <class t> using indirectee_type	    = typename Type<t>::indirectee_type;
		template <class t> using pointee_type		    = typename Type<t>::pointee_type;
		template <class t> using referencee_type	    = typename Type<t>::referencee_type;
		template <class t> using remove_array		    = typename Type<t>::remove_array;
		template <class t> using remove_const		    = typename Type<t>::remove_const;
		template <class t> using remove_const_this	    = typename Type<t>::remove_const_this;
		template <class t> using remove_const_volatile	    = typename Type<t>::remove_const_volatile;
		template <class t> using remove_const_volatile_this = typename Type<t>::remove_const_volatile_this;
		template <class t> using remove_indirection	    = typename Type<t>::remove_indirection;
		template <class t> using remove_member_pointer	    = typename Type<t>::remove_member_pointer;
		template <class t> using remove_pointer		    = typename TypeRemovePointer<t>::type;
		template <class t> using remove_reference	    = typename Type<t>::remove_reference;
		template <class t> using remove_this		    = typename Type<t>::remove_this;
		template <class t> using remove_volatile	    = typename Type<t>::remove_volatile;
		template <class t> using remove_volatile_this	    = typename Type<t>::remove_volatile_this;
		template <class t> using return_type		    = typename Type<t>::return_type;
		template <class t> using to_const		    = typename Type<t>::to_const;
		template <class t> using to_const_volatile	    = typename Type<t>::to_const_volatile;
		template <class t> using to_forwardable		    = typename Type<t>::to_forwardable;
		template <class t> using to_function		    = typename Type<t>::to_function;
		template <class t> using to_lvalue_reference	    = typename Type<t>::to_lvalue_reference;
		template <class t> using to_opaque		    = typename Type<t>::to_opaque;
		template <class t> using to_pointer		    = typename Type<t>::to_pointer;
		template <class t> using to_signed		    = typename Type<t>::to_signed;
		template <class t> using to_unqualified		    = typename Type<t>::to_unqualified;
		template <class t> using to_unsigned		    = typename Type<t>::to_unsigned;
		template <class t> using to_volatile		    = typename Type<t>::to_volatile;
		template <class t> using to_wrap		    = typename Type<t>::to_wrap;

		template <class t, class klass> using add_member_pointer = typename TypeAddMemberPointer<t, klass>::type;
		template <class t, class klass> using to_member_pointer  = typename TypeToMemberPointer <t, klass>::type;

#		if Z_DIALECT_HAS(CPP11, REFERENCE_QUALIFIED_NON_STATIC_MEMBER_FUNCTION)
			template <class t> using add_const_lvalue	   = typename Type<t>::add_const_lvalue;
			template <class t> using add_const_rvalue	   = typename Type<t>::add_const_rvalue;
			template <class t> using add_const_volatile_lvalue = typename Type<t>::add_const_volatile_lvalue;
			template <class t> using add_const_volatile_rvalue = typename Type<t>::add_const_volatile_rvalue;
			template <class t> using add_lvalue		   = typename Type<t>::add_lvalue;
			template <class t> using add_rvalue		   = typename Type<t>::add_rvalue;
			template <class t> using add_volatile_lvalue	   = typename Type<t>::add_volatile_lvalue;
			template <class t> using add_volatile_rvalue	   = typename Type<t>::add_volatile_rvalue;
			template <class t> using to_const_lvalue	   = typename Type<t>::to_const_lvalue;
			template <class t> using to_const_rvalue	   = typename Type<t>::to_const_rvalue;
			template <class t> using to_const_volatile_lvalue  = typename Type<t>::to_const_volatile_lvalue;
			template <class t> using to_const_volatile_rvalue  = typename Type<t>::to_const_volatile_rvalue;
			template <class t> using to_lvalue		   = typename Type<t>::to_lvalue;
			template <class t> using to_rvalue		   = typename Type<t>::to_rvalue;
			template <class t> using to_volatile_lvalue	   = typename Type<t>::to_volatile_lvalue;
			template <class t> using to_volatile_rvalue	   = typename Type<t>::to_volatile_rvalue;
#		endif

#		if Z_DIALECT_HAS(CPP17, NOEXCEPT_AS_PART_OF_THE_FUNCTION_TYPE)
			template <class t> using add_noexcept    = typename Type<t>::add_noexcept;
			template <class t> using remove_noexcept = typename Type<t>::remove_noexcept;
#		endif

#		if Z_DIALECT_HAS(CPP11, RVALUE_REFERENCE)
			template <class t> using add_rvalue_reference = typename Type<t>::add_rvalue_reference;
			template <class t> using to_rvalue_reference  = typename Type<t>::to_rvalue_reference;
#		endif

#		if Z_HAS(type_parameters)
			template <class t> using parameters = typename Type<t>::parameters;
#		endif

#		if Z_HAS(type_underlying_type)
			template <class t> using underlying_type = typename Type<t>::underlying_type;
#		endif

#		if Z_HAS(type_parameter)
			template <class t, UInt index> using parameter = typename Type<t>::template parameter<index>;
#		endif
#	endif
}

#endif // Z_traits_type_HPP
