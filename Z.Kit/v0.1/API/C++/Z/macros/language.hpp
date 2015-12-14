/* Z Kit C++ API - macros/language.hpp
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_macros_language_HPP__
#define __Z_macros_language_HPP__

#if Z_COMPILER_HAS_MACRO(USING_NAMESPACE_BEGIN) && Z_COMPILER_HAS_MACRO(USING_NAMESPACE_END)
#	define Z_USING_NAMESPACE_BEGIN Z_COMPILER_MACRO(USING_NAMESPACE_BEGIN)
#	define Z_USING_NAMESPACE_END   Z_COMPILER_MACRO(USING_NAMESPACE_END  )
#else
#	define Z_USING_NAMESPACE_BEGIN(name) {using namespace name;
#	define Z_USING_NAMESPACE_END(  name) }
#endif

#endif // __Z_macros_language_HPP__
