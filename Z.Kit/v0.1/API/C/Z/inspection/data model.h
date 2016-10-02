/* Z Kit C API - inspection/data model.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_|
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_inspection_data_model_H__
#define __Z_inspection_data_model_H__

#include <Z/keys/data model.h>
#include <Z/keys/value.h>
#include <Z/inspection/language.h>
#include <Z/macros/pasting.h>

#ifndef Z_DATA_MODEL

#	ifdef Z_COMPILER_DATA_MODEL
#		define Z_DATA_MODEL Z_COMPILER_DATA_MODEL
#	else
#		include <Z/inspection/data model/detection.h>
#	endif

#	ifndef Z_DATA_MODEL
#		include <Z/inspection/data model/deduction.h>
#	endif

#endif

#if Z_DATA_MODEL == Z_DATA_MODEL_ILP32

#	include <Z/formats/data model/ILP32.h>

#	define Z_INSERT_DATA_MODEL(left, right) left##ILP32##right

#elif Z_DATA_MODEL == Z_DATA_MODEL_ILP64

#	include <Z/formats/data model/ILP64.h>

#	define Z_INSERT_DATA_MODEL(left, right) left##ILP64##right

#elif Z_DATA_MODEL == Z_DATA_MODEL_LLP64

#	include <Z/formats/data model/LLP64.h>

#	define Z_INSERT_DATA_MODEL(left, right) left##LLP64##right

#elif Z_DATA_MODEL == Z_DATA_MODEL_LP32

#	include <Z/formats/data model/LP32.h>

#	define Z_INSERT_DATA_MODEL(left, right) left##LP32##right

#elif Z_DATA_MODEL == Z_DATA_MODEL_LP64

#	include <Z/formats/data model/LP64.h>

#	define Z_INSERT_DATA_MODEL(left, right) left##LP64##right

#elif Z_DATA_MODEL == Z_DATA_MODEL_SILP64

#	include <Z/formats/data model/SILP64.h>

#	define Z_PASTE_DATA_MODEL(left, right) left##SILP64##right

#endif

#define Z_DATA_MODEL_STRING	       Z_INSERT_DATA_MODEL(Z_DATA_MODEL_STRING_,)
#define Z_DATA_MODEL_HAS_TYPE(	 TYPE) Z_DATA_MODEL_HAS_TYPE_##TYPE
#define Z_DATA_MODEL_HAS_LITERAL(TYPE) Z_DATA_MODEL_HAS_LITERAL_##TYPE
#define Z_DATA_MODEL_TYPE(	 TYPE) Z_DATA_MODEL_TYPE_##TYPE
#define Z_DATA_MODEL_LITERAL(	 TYPE) Z_DATA_MODEL_LITERAL_##TYPE
#define Z_DATA_MODEL_VALUE_TYPE( TYPE) Z_DATA_MODEL_VALUE_TYPE_##TYPE
#define Z_DATA_MODEL_BITS(	 TYPE) Z_INSERT_DATA_MODEL(Z_, _BITS_##TYPE)

/* MARK: - uint8 */

#define Z_DATA_MODEL_HAS_TYPE_UINT8    TRUE
#define Z_DATA_MODEL_HAS_LITERAL_UINT8 TRUE

#if Z_DATA_MODEL_BITS(UCHAR) == 8

#	define Z_DATA_MODEL_TYPE_UINT8	     unsigned char
#	define Z_DATA_MODEL_VALUE_TYPE_UINT8 Z_VALUE_TYPE_UCHAR
#	define Z_DATA_MODEL_LITERAL_UINT8    Z_SUFFIX_U

#elif Z_DATA_MODEL_BITS(USHORT) == 8

#	define Z_DATA_MODEL_TYPE_UINT8	     unsigned short int
#	define Z_DATA_MODEL_VALUE_TYPE_UINT8 Z_VALUE_TYPE_USHORT
#	define Z_DATA_MODEL_LITERAL_UINT8    Z_SUFFIX_U

#else

#	define Z_DATA_MODEL_TYPE_UINT8	     Z_COMPILER_TYPE(UINT8)
#	define Z_DATA_MODEL_VALUE_TYPE_UINT8 Z_VALUE_TYPE_UINT8

#	if Z_COMPILER_HAS_LITERAL(UINT8)
#		define Z_DATA_MODEL_LITERAL_UINT8 Z_COMPILER_LITERAL(UINT8)
#	else
#		define Z_DATA_MODEL_LITERAL_UINT8 Z_SUFFIX_U
#	endif

#endif

/* MARK: - uint16 */

#define Z_DATA_MODEL_HAS_TYPE_UINT16	TRUE
#define Z_DATA_MODEL_HAS_LITERAL_UINT16 TRUE

#if Z_DATA_MODEL_BITS(UCHAR) == 16

#	define Z_DATA_MODEL_TYPE_UINT16	      unsigned char
#	define Z_DATA_MODEL_VALUE_TYPE_UINT16 Z_VALUE_TYPE_UCHAR
#	define Z_DATA_MODEL_LITERAL_UINT16    Z_SUFFIX_U

#elif Z_DATA_MODEL_BITS(USHORT) == 16

#	define Z_DATA_MODEL_TYPE_UINT16	      unsigned short int
#	define Z_DATA_MODEL_VALUE_TYPE_UINT16 Z_VALUE_TYPE_USHORT
#	define Z_DATA_MODEL_LITERAL_UINT16    Z_SUFFIX_U

#elif Z_DATA_MODEL_BITS(UINT) == 16

#	define Z_DATA_MODEL_TYPE_UINT16	      unsigned int
#	define Z_DATA_MODEL_VALUE_TYPE_UINT16 Z_VALUE_TYPE_UINT
#	define Z_DATA_MODEL_LITERAL_UINT16    Z_SUFFIX_U

#else

#	define Z_DATA_MODEL_TYPE_UINT16	      Z_COMPILER_TYPE(UINT16)
#	define Z_DATA_MODEL_VALUE_TYPE_UINT16 Z_VALUE_TYPE_UINT16

#	if Z_COMPILER_HAS_LITERAL(UINT16)
#		define Z_DATA_MODEL_LITERAL_UINT16 Z_COMPILER_LITERAL(UINT16)
#	else
#		define Z_DATA_MODEL_LITERAL_UINT16 Z_SUFFIX_U
#	endif

#endif

/* MARK: - uint32 */

#define Z_DATA_MODEL_HAS_TYPE_UINT32	TRUE
#define Z_DATA_MODEL_HAS_LITERAL_UINT32 TRUE

#if Z_DATA_MODEL_BITS(USHORT) == 32

#	define Z_DATA_MODEL_TYPE_UINT32	      unsigned short int
#	define Z_DATA_MODEL_VALUE_TYPE_UINT32 Z_VALUE_TYPE_USHORT
#	define Z_DATA_MODEL_LITERAL_UINT32    Z_SUFFIX_U

#elif Z_DATA_MODEL_BITS(UINT) == 32

#	define Z_DATA_MODEL_TYPE_UINT32	      unsigned int
#	define Z_DATA_MODEL_VALUE_TYPE_UINT32 Z_VALUE_TYPE_UINT
#	define Z_DATA_MODEL_LITERAL_UINT32    Z_SUFFIX_U

#elif Z_DATA_MODEL_BITS(ULONG) == 32

#	define Z_DATA_MODEL_TYPE_UINT32	      unsigned long int
#	define Z_DATA_MODEL_VALUE_TYPE_UINT32 Z_VALUE_TYPE_ULONG
#	define Z_DATA_MODEL_LITERAL_UINT32    Z_SUFFIX_UL

#else

#	define Z_DATA_MODEL_TYPE_UINT32	      Z_COMPILER_TYPE(UINT32)
#	define Z_DATA_MODEL_VALUE_TYPE_UINT32 Z_VALUE_TYPE_UINT32

#	if Z_COMPILER_HAS_LITERAL(UINT32)
#		define Z_DATA_MODEL_LITERAL_UINT32 Z_COMPILER_LITERAL(UINT32)
#	else
#		define Z_DATA_MODEL_LITERAL_UINT32 Z_SUFFIX_U
#	endif

#endif

/* MARK: - uint64 */

#define Z_DATA_MODEL_HAS_TYPE_UINT64	TRUE
#define Z_DATA_MODEL_HAS_LITERAL_UINT64 TRUE

#if Z_DATA_MODEL_BITS(UINT) == 64

#	define Z_DATA_MODEL_TYPE_UINT64	      unsigned int
#	define Z_DATA_MODEL_VALUE_TYPE_UINT64 Z_VALUE_TYPE_UINT
#	define Z_DATA_MODEL_LITERAL_UINT64    Z_SUFFIX_U

#elif Z_DATA_MODEL_BITS(ULONG) == 64

#	define Z_DATA_MODEL_TYPE_UINT64	      unsigned long int
#	define Z_DATA_MODEL_VALUE_TYPE_UINT64 Z_VALUE_TYPE_ULONG
#	define Z_DATA_MODEL_LITERAL_UINT64    Z_SUFFIX_UL

#elif Z_DATA_MODEL_BITS(ULLONG) == 64 && (Z_LANGUAGE_HAS_TYPE(C, ULLONG) || Z_LANGUAGE_HAS_TYPE(CPP, ULLONG))

#	define Z_DATA_MODEL_TYPE_UINT64	      unsigned long long int
#	define Z_DATA_MODEL_VALUE_TYPE_UINT64 Z_VALUE_TYPE_ULLONG
#	define Z_DATA_MODEL_LITERAL_UINT64    Z_SUFFIX_ULL

#elif Z_COMPILER_HAS_TYPE(UINT64)

#	define Z_DATA_MODEL_TYPE_UINT64	      Z_COMPILER_TYPE(UINT64)
#	define Z_DATA_MODEL_VALUE_TYPE_UINT64 Z_VALUE_TYPE_UINT64

#	if Z_COMPILER_HAS_LITERAL(UINT64)
#		define Z_DATA_MODEL_LITERAL_UINT64 Z_COMPILER_LITERAL(UINT64)
#	else
#		undef  Z_DATA_MODEL_HAS_LITERAL_UINT64
#		define Z_DATA_MODEL_HAS_LITERAL_UINT64 FALSE
#	endif

#else
#	undef  Z_DATA_MODEL_HAS_TYPE_UINT64
#	define Z_DATA_MODEL_HAS_TYPE_UINT64    FALSE
#	undef  Z_DATA_MODEL_HAS_LITERAL_UINT64
#	define Z_DATA_MODEL_HAS_LITERAL_UINT64 FALSE
#endif

/* MARK: - uint128 */

#define Z_DATA_MODEL_HAS_TYPE_UINT128 TRUE

#if Z_DATA_MODEL_BITS(ULLONG) == 128 && (Z_LANGUAGE_HAS_TYPE(C, ULLONG) || Z_LANGUAGE_HAS_TYPE(CPP, ULLONG))

#	define Z_DATA_MODEL_TYPE_UINT128       unsigned long long int
#	define Z_DATA_MODEL_VALUE_TYPE_UINT128 Z_VALUE_TYPE_ULLONG
#	define Z_DATA_MODEL_LITERAL_UINT128    Z_SUFFIX_ULL

#elif Z_COMPILER_HAS_TYPE(UINT128)

#	define Z_DATA_MODEL_TYPE_UINT128       Z_COMPILER_TYPE(UINT128)
#	define Z_DATA_MODEL_VALUE_TYPE_UINT128 Z_VALUE_TYPE_UINT128

#	if Z_COMPILER_HAS_LITERAL(UINT128)
#		define Z_DATA_MODEL_LITERAL_UINT128 Z_COMPILER_LITERAL(UINT128)
#	else
#		undef  Z_DATA_MODEL_HAS_LITERAL_UINT128
#		define Z_DATA_MODEL_HAS_LITERAL_UINT128 FALSE
#	endif

#else
#	undef  Z_DATA_MODEL_HAS_TYPE_UINT128
#	define Z_DATA_MODEL_HAS_TYPE_UINT128	FALSE
#	undef  Z_DATA_MODEL_HAS_LITERAL_UINT128
#	define Z_DATA_MODEL_HAS_LITERAL_UINT128	FALSE
#endif

/* MARK: - int8 */

#define Z_DATA_MODEL_HAS_TYPE_INT8    TRUE
#define Z_DATA_MODEL_HAS_LITERAL_INT8 TRUE

#if Z_DATA_MODEL_BITS(CHAR) == 8

#	define Z_DATA_MODEL_TYPE_INT8	    signed char
#	define Z_DATA_MODEL_VALUE_TYPE_INT8 Z_VALUE_TYPE_CHAR
#	define Z_DATA_MODEL_LITERAL_INT8    Z_SAME

#elif Z_DATA_MODEL_BITS(SHORT) == 8

#	define Z_DATA_MODEL_TYPE_INT8	    signed short int
#	define Z_DATA_MODEL_VALUE_TYPE_INT8 Z_VALUE_TYPE_SHORT
#	define Z_DATA_MODEL_LITERAL_INT8    Z_SAME

#else

#	define Z_DATA_MODEL_TYPE_INT8	    Z_COMPILER_TYPE(INT8)
#	define Z_DATA_MODEL_VALUE_TYPE_INT8 Z_VALUE_TYPE_INT8

#	if Z_COMPILER_HAS_LITERAL(INT8)
#		define Z_DATA_MODEL_LITERAL_UINT8 Z_COMPILER_LITERAL(INT8)
#	else
#		define Z_DATA_MODEL_LITERAL_UINT8 Z_SAME
#	endif

#endif

/* MARK: - int16 */

#define Z_DATA_MODEL_HAS_TYPE_INT16    TRUE
#define Z_DATA_MODEL_HAS_LITERAL_INT16 TRUE

#if Z_DATA_MODEL_BITS(CHAR) == 16

#	define Z_DATA_MODEL_TYPE_INT16	     signed char
#	define Z_DATA_MODEL_VALUE_TYPE_INT16 Z_VALUE_TYPE_CHAR
#	define Z_DATA_MODEL_LITERAL_INT16    Z_SAME

#elif Z_DATA_MODEL_BITS(SHORT) == 16

#	define Z_DATA_MODEL_TYPE_INT16	     signed short int
#	define Z_DATA_MODEL_VALUE_TYPE_INT16 Z_VALUE_TYPE_SHORT
#	define Z_DATA_MODEL_LITERAL_INT16    Z_SAME

#elif Z_DATA_MODEL_BITS(INT) == 16

#	define Z_DATA_MODEL_TYPE_INT16	     signed int
#	define Z_DATA_MODEL_VALUE_TYPE_INT16 Z_VALUE_TYPE_INT
#	define Z_DATA_MODEL_LITERAL_INT16    Z_SAME

#else

#	define Z_DATA_MODEL_TYPE_INT16	     Z_COMPILER_TYPE(INT16)
#	define Z_DATA_MODEL_VALUE_TYPE_INT16 Z_VALUE_TYPE_INT16

#	if Z_COMPILER_HAS_LITERAL(INT16)
#		define Z_DATA_MODEL_LITERAL_UINT16 Z_COMPILER_LITERAL(INT16)
#	else
#		define Z_DATA_MODEL_LITERAL_UINT16 Z_SAME
#	endif

#endif

/* MARK: - int32 */

#define Z_DATA_MODEL_HAS_TYPE_INT32    TRUE
#define Z_DATA_MODEL_HAS_LITERAL_INT32 TRUE

#if Z_DATA_MODEL_BITS(SHORT) == 32

#	define Z_DATA_MODEL_TYPE_INT32	     signed short int
#	define Z_DATA_MODEL_VALUE_TYPE_INT32 Z_VALUE_TYPE_SHORT
#	define Z_DATA_MODEL_LITERAL_INT32    Z_SAME

#elif Z_DATA_MODEL_BITS(INT) == 32

#	define Z_DATA_MODEL_TYPE_INT32	     signed int
#	define Z_DATA_MODEL_VALUE_TYPE_INT32 Z_VALUE_TYPE_INT
#	define Z_DATA_MODEL_LITERAL_INT32    Z_SAME

#elif Z_DATA_MODEL_BITS(LONG) == 32

#	define Z_DATA_MODEL_TYPE_INT32	     signed long int
#	define Z_DATA_MODEL_VALUE_TYPE_INT32 Z_VALUE_TYPE_LONG
#	define Z_DATA_MODEL_LITERAL_INT32    Z_SUFFIX_L

#else

#	define Z_DATA_MODEL_TYPE_INT32	     Z_COMPILER_TYPE(INT32)
#	define Z_DATA_MODEL_VALUE_TYPE_INT32 Z_VALUE_TYPE_INT32

#	if Z_COMPILER_HAS_LITERAL(INT32)
#		define Z_DATA_MODEL_LITERAL_UINT32 Z_COMPILER_LITERAL(INT32)
#	else
#		define Z_DATA_MODEL_LITERAL_UINT32 Z_SAME
#	endif

#endif

/* MARK: - int64 */

#define Z_DATA_MODEL_HAS_TYPE_INT64    TRUE
#define Z_DATA_MODEL_HAS_LITERAL_INT64 TRUE

#if Z_DATA_MODEL_BITS(INT) == 64

#	define Z_DATA_MODEL_TYPE_INT64	     signed int
#	define Z_DATA_MODEL_VALUE_TYPE_INT64 Z_VALUE_TYPE_INT
#	define Z_DATA_MODEL_LITERAL_INT64    Z_SAME

#elif Z_DATA_MODEL_BITS(LONG) == 64

#	define Z_DATA_MODEL_TYPE_INT64	     signed long int
#	define Z_DATA_MODEL_VALUE_TYPE_INT64 Z_VALUE_TYPE_LONG
#	define Z_DATA_MODEL_LITERAL_INT64    Z_SUFFIX_L

#elif Z_DATA_MODEL_BITS(LLONG) == 64 && (Z_LANGUAGE_HAS_TYPE(C, LLONG) || Z_LANGUAGE_HAS_TYPE(CPP, LLONG))

#	define Z_DATA_MODEL_TYPE_INT64	     signed long long int
#	define Z_DATA_MODEL_VALUE_TYPE_INT64 Z_VALUE_TYPE_LLONG
#	define Z_DATA_MODEL_LITERAL_INT64    Z_SUFFIX_LL

#elif Z_COMPILER_HAS_TYPE(INT64)

#	define Z_DATA_MODEL_TYPE_INT64	     Z_COMPILER_TYPE(INT64)
#	define Z_DATA_MODEL_VALUE_TYPE_INT64 Z_VALUE_TYPE_INT64

#	if Z_COMPILER_HAS_LITERAL(INT64)
#		define Z_DATA_MODEL_LITERAL_INT64 Z_COMPILER_LITERAL(INT64)
#	else
#		undef  Z_DATA_MODEL_HAS_LITERAL_INT64
#		define Z_DATA_MODEL_HAS_LITERAL_INT64 FALSE
#	endif

#else
#	undef  Z_DATA_MODEL_HAS_TYPE_INT64
#	define Z_DATA_MODEL_HAS_TYPE_INT64    FALSE
#	undef  Z_DATA_MODEL_HAS_LITERAL_INT64
#	define Z_DATA_MODEL_HAS_LITERAL_INT64 FALSE
#endif

/* MARK: - int128 */

#define Z_DATA_MODEL_HAS_TYPE_INT128	TRUE
#define Z_DATA_MODEL_HAS_LITERAL_INT128 TRUE

#if Z_DATA_MODEL_BITS(LLONG) == 128 && (Z_LANGUAGE_HAS_TYPE(C, LLONG) || Z_LANGUAGE_HAS_TYPE(CPP, LLONG))

#	define Z_DATA_MODEL_TYPE_INT128	      signed long long int
#	define Z_DATA_MODEL_VALUE_TYPE_INT128 Z_VALUE_TYPE_LLONG
#	define Z_DATA_MODEL_LITERAL_INT128    Z_SUFFIX_LL

#elif Z_COMPILER_HAS_TYPE(INT128)

#	define Z_DATA_MODEL_TYPE_INT128	      Z_COMPILER_TYPE(INT128)
#	define Z_DATA_MODEL_VALUE_TYPE_INT128 Z_VALUE_TYPE_INT128

#	if Z_COMPILER_HAS_LITERAL(INT128)
#		define Z_DATA_MODEL_LITERAL_INT128 Z_COMPILER_LITERAL(INT128)
#	else
#		undef  Z_DATA_MODEL_HAS_LITERAL_INT128
#		define Z_DATA_MODEL_HAS_LITERAL_INT128 FALSE
#	endif

#else
#	undef  Z_DATA_MODEL_HAS_TYPE_INT128
#	define Z_DATA_MODEL_HAS_TYPE_INT128    FALSE
#	undef  Z_DATA_MODEL_HAS_LITERAL_INT128
#	define Z_DATA_MODEL_HAS_LITERAL_INT128 FALSE
#endif

#endif /* __Z_inspection_data_model_H__ */
