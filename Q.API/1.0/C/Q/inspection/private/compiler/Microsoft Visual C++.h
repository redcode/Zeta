/* Q API - inspection/private/compiler/GCC.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2010-2013 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v2. */

#ifndef __Q_inspection_private_compiler_H__
#define __Q_inspection_private_compiler_H__

#include <Q/constants/basics.h>
#include <Q/keys/compiler.h>
#include <Q/keys/bit field.h>

#pragma mark - Identification

#define Q_COMPILER						Q_COMPILER_MICROSOFT_VISUAL_CPP
#define Q_COMPILER_STRING					Q_COMPILER_STRING_MICROSOFT_VISUAL_CPP
#define Q_COMPILER_VERSION
#define Q_COMPILER_VERSION_STRING

#pragma mark - Extensions

#define Q_COMPILER_HAS_ALIAS

#pragma mark - Bit field encoding

#define Q_COMPILER_LITTLE_ENDIAN_8BIT_FIELD_ENCODING		Q_BIT_FIELD_ENCODING_REVERSED
#define Q_COMPILER_LITTLE_ENDIAN_BIT_FIELD_ENCODING		Q_BIT_FIELD_ENCODING_REVERSED
#define Q_COMPILER_BIG_ENDIAN_8BIT_FIELD_ENCODING		Q_BIT_FIELD_ENCODING_LITERAL
#define Q_COMPILER_BIG_ENDIAN_BIT_FIELD_ENCODING		Q_BIT_FIELD_ENCODING_LITERAL

#pragma mark - Custom types

#define Q_COMPILER_TYPE_UINT128					__uint128_t
#define Q_COMPILER_TYPE_INT128					__int128_t
#define Q_COMPILER_TYPE_VAL					__builtin_va_list

#pragma mark - Built-in functions

#define Q_COMPILER_FUNCTION_VAL_INITIALIZE			__builtin_va_start
#define Q_COMPILER_FUNCTION_VAL_FINALIZE			__builtin_va_end
#define Q_COMPILER_FUNCTION_VAL_READ				__builtin_va_arg


#pragma mark - Keywords and attributes

#define Q_ASSEMBLY
#define Q_THREAD_LOCAL(type, name)				type __thread name
#define Q_ATTRIBUTE_PRIVATE					__attribute__((visibility("hidden"))) static
#define Q_ATTRIBUTE_PUBLIC					__attribute__((visibility("default"))
#define Q_ATTRIBUTE_ALIAS(name)					__attribute__((weak, alias(name)))
#define Q_ATTRIBUTE_STRICT_SIZE					__attribute__((packed))
#define Q_ATTRIBUTE_ERROR(message)				__attribute__((error(message)))
#define Q_ATTRIBUTE_UNAVAILABLE(message)			__attribute__((unavailable(message)))

#define Q_INLINE						static __inline


#endif /* __Q_inspection_private_compiler_H__ */
