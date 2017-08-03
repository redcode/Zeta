/* Z Kit C API - inspection/modules/compiler/Visual C++.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2017 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_inspection_modules_compiler_Visual_CPP_H__
#define __Z_inspection_modules_compiler_Visual_CPP_H__

#define Z_AVOID_VARIADIC_MACROS

/* MARK: - Identification */

#ifndef Z_COMPILER
#	include <Z/keys/compiler.h>

#	define Z_COMPILER		 Z_COMPILER_VISUAL_CPP
#	define Z_COMPILER_STRING	 Z_COMPILER_STRING_VISUAL_CPP
#	define Z_COMPILER_VERSION
#	define Z_COMPILER_VERSION_STRING
#endif

/* MARK: - Bit field encoding */

#include <Z/keys/order.h>

#define Z_COMPILER_LITTLE_ENDIAN_8BIT_FIELD_ORDER Z_BIT_FIELD_ENCODING_REVERSED
#define Z_COMPILER_LITTLE_ENDIAN_BIT_FIELD_ORDER  Z_BIT_FIELD_ENCODING_REVERSED
#define Z_COMPILER_BIG_ENDIAN_8BIT_FIELD_ORDER	  Z_BIT_FIELD_ENCODING_LITERAL
#define Z_COMPILER_BIG_ENDIAN_BIT_FIELD_ORDER	  Z_BIT_FIELD_ENCODING_LITERAL

/* MARK: - C features */

/* MARK: - C types */

#define Z_COMPILER_C_HAS_TYPE_LLONG TRUE
#define Z_COMPILER_C_HAS_TYPE_FLOAT TRUE
#define Z_COMPILER_C_HAS_TYPE_DOUBLE TRUE
/*#define Z_COMPILER_C_HAS_TYPE_LDOUBLE*/

/* MARK: - C attributes */

#define Z_COMPILER_C_ATTRIBUTE_ALIAS(name)
#define Z_COMPILER_C_ATTRIBUTE_API		 __declspec(dllimport)
/*#define Z_COMPILER_C_ATTRIBUTE_API_ALIAS*/
#define Z_COMPILER_C_ATTRIBUTE_API_EXPORT	 __declspec(dllexport)
/*#define Z_COMPILER_C_ATTRIBUTE_API_EXPORT_ALIAS*/
/*#define Z_COMPILER_C_ATTRIBUTE_API_WEAK_EXPORT*/
#define Z_COMPILER_C_ATTRIBUTE_INLINE		 static __forceinline
/*#define Z_COMPILER_C_ATTRIBUTE_NO_RETURN*/
/*#define Z_COMPILER_C_ATTRIBUTE_NULL_TERMINATED*/
#define Z_COMPILER_C_ATTRIBUTE_PRIVATE		 static
/*#define Z_COMPILER_C_ATTRIBUTE_PUBLIC*/
#define Z_COMPILER_C_ATTRIBUTE_STRICT_SIZE_BEGIN __pragma(pack(push, 1))
#define Z_COMPILER_C_ATTRIBUTE_STRICT_SIZE_END	 __pragma(pack(pop))
#define Z_COMPILER_C_ATTRIBUTE_THREAD_LOCAL	 __declspec(thread)
#define Z_COMPILER_C_ATTRIBUTE_WEAK		 __declspec(selectany)

/* MARK: - Specific constants */

/*#define Z_COMPILER_CONSTANT_FLOAT_MAXIMUM 3.402823466e+38*/

/* MARK: - Built-in constants */

/* MARK: - Built-in types */

#define Z_COMPILER_TYPE_UINT8  unsigned __int8
#define Z_COMPILER_TYPE_UINT16 unsigned __int16
#define Z_COMPILER_TYPE_UINT32 unsigned __int32
#define Z_COMPILER_TYPE_UINT64 unsigned __int64

#define Z_COMPILER_TYPE_INT8  __int8
#define Z_COMPILER_TYPE_INT16 __int16
#define Z_COMPILER_TYPE_INT32 __int32
#define Z_COMPILER_TYPE_INT64 __int64

/* MARK: - Built-in functions: Struture */

/* MARK: - Built-in functions: VAL */

/* MARK: - Built-in functions: Atomic operations */

#endif /* __Z_inspection_modules_compiler_Visual_CPP_H__ */
