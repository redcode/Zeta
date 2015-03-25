/* Q Kit C API - inspection/private/compiler/Microsoft Visual C++.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_inspection_private_compiler_Microsoft_Visual_CPP_H__
#define __Q_inspection_private_compiler_Microsoft_Visual_CPP_H__

#define Q_AVOID_VARIADIC_MACROS

/* MARK: - Identification */

#ifndef Q_COMPILER
#	include <Q/keys/compiler.h>

#	define Q_COMPILER				Q_COMPILER_MICROSOFT_VISUAL_CPP
#	define Q_COMPILER_STRING			Q_COMPILER_STRING_MICROSOFT_VISUAL_CPP
#	define Q_COMPILER_VERSION
#	define Q_COMPILER_VERSION_STRING
#endif

/* MARK: - Bit field encoding */

#include <Q/keys/bit field.h>

#define Q_COMPILER_LITTLE_ENDIAN_8BIT_FIELD_ENCODING	Q_BIT_FIELD_ENCODING_REVERSED
#define Q_COMPILER_LITTLE_ENDIAN_BIT_FIELD_ENCODING	Q_BIT_FIELD_ENCODING_REVERSED
#define Q_COMPILER_BIG_ENDIAN_8BIT_FIELD_ENCODING	Q_BIT_FIELD_ENCODING_LITERAL
#define Q_COMPILER_BIG_ENDIAN_BIT_FIELD_ENCODING	Q_BIT_FIELD_ENCODING_LITERAL

/* MARK: - C features */

/* MARK: - C types */

#define Q_COMPILER_C_HAS_TYPE_LLONG
#define Q_COMPILER_C_HAS_TYPE_LDOUBLE
/*#define Q_COMPILER_LACKS_TYPE_LDOUBLE*/

/* MARK: - C attributes */

#define Q_COMPILER_C_ATTRIBUTE_ALIAS(name)
#define Q_COMPILER_C_ATTRIBUTE_INLINE		 static __forceinline

#define Q_COMPILER_C_ATTRIBUTE_THREAD_LOCAL	 __declspec(thread)
#define Q_COMPILER_C_ATTRIBUTE_PRIVATE		 static
#define Q_COMPILER_C_ATTRIBUTE_API		 __declspec(dllimport)
#define Q_COMPILER_C_ATTRIBUTE_API_EXPORT	 __declspec(dllexport)
#define Q_COMPILER_C_ATTRIBUTE_STRICT_SIZE_BEGIN __pragma(pack(push, 1))
#define Q_COMPILER_C_ATTRIBUTE_STRICT_SIZE_END	 __pragma(pack(pop))

/* MARK: - Specific constants */

#define Q_COMPILER_CONSTANT_FLOAT_MAXIMUM 3.402823466e+38

/* MARK: - Built-in constants */

/* MARK: - Built-in types */

/* MARK: - Built-in functions: Struture */

/* MARK: - Built-in functions: VAL */

/* MARK: - Built-in functions: Atomic operations */

#endif /* __Q_inspection_private_compiler_Microsoft_Visual_CPP_H__ */
