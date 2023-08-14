

	// BUG
	// https://baptiste-wicht.com/posts/2017/08/simplify-your-type-traits-with-c%2B%2B14-variable-templates.html
#	if	(defined(__cpp_variable_templates) && __cpp_variable_templates >= 201304L) || \
		__has_feature(cxx_variable_templates)

#		define Z_COMPILER_CPP_HAS_VARIABLE_TEMPLATE 1 /* v3.4 */
#	endif



#	if	(defined(__cpp_decltype_auto) && __cpp_decltype_auto >= 201304L) || \
		__has_feature(cxx_decltype_auto)				 || \
	       (Z_COMPILER_VERSION >= Z_VERSION(3,3,0) &&			    \
		Z_COMPILER_VERSION <  Z_VERSION(3,5,0) &&			    \
		__cplusplus	   >= 201402L)

#		define Z_COMPILER_CPP_HAS_SPECIFIER_CASE_DECLTYPE_AUTO 1 /* v3.3 */
#	endif











#	if __cplusplus >= 201703L
#		define Z_COMPILER_CPP_HAS_NOEXCEPT_AS_PART_OF_THE_FUNCTION_TYPE		   1 /* P0012R1  __cpp_noexcept_function_type	  >= 201510L (!) */
#		define Z_COMPILER_CPP_HAS_NON_TYPE_TEMPLATE_PARAMETER_WITH_AUTO_TYPE	   1
#	endif

#if	__cplusplus >= 201703L
#		define Z_COMPILER_CPP_HAS_LITERAL_HEXADECIMAL_FLOATING_POINT 1 /* All versions? */
#	endif

	/*#define Z_COMPILER_CPP_HAS_LITERAL_UTF8_CHARACTER*/

#	define Z_COMPILER_CPP_HAS_PREPROCESSOR_OPERATOR_HAS_INCLUDE 1 /* All versions? (NO) */


std::is_nothrow_destructible -> std::integral_constant<bool, noexcept(declval<T>().~T())>