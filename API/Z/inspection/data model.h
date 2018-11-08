/* Z Kit - inspection/data model.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_inspection_data_model_H_
#define _Z_inspection_data_model_H_

#include <Z/keys/data model.h>
#include <Z/keys/value.h>
#include <Z/inspection/language.h>
#include <Z/macros/pasting.h>

#ifndef Z_DATA_MODEL /* UDC */

#	ifdef Z_COMPILER_DATA_MODEL
#		define Z_DATA_MODEL Z_COMPILER_DATA_MODEL
#	else
#		include <Z/inspection/data model/detection.h>

#		ifndef Z_DATA_MODEL
#			include <Z/inspection/data model/deduction.h>
#		endif
#	endif

#endif

#if Z_DATA_MODEL == Z_DATA_MODEL_IP16L32

#	include <Z/formats/data model/IP16L32.h>

#	define Z_APPEND_DATA_MODEL(to)		to##IP16L32
#	define Z_APPEND_data_model(to)		to##ip16l32
#	define Z_INSERT_DATA_MODEL(left, right) left##IP16L32##right
#	define Z_INSERT_data_model(left, right) left##ip16l32##right

#elif Z_DATA_MODEL == Z_DATA_MODEL_I16LP32

#	include <Z/formats/data model/I16LP32.h>

#	define Z_APPEND_DATA_MODEL(to)		to##I16LP32
#	define Z_APPEND_data_model(to)		to##i16lp32
#	define Z_INSERT_DATA_MODEL(left, right) left##I16LP32##right
#	define Z_INSERT_data_model(left, right) left##i16lp32##right

#elif Z_DATA_MODEL == Z_DATA_MODEL_ILP32

#	include <Z/formats/data model/ILP32.h>

#	define Z_APPEND_DATA_MODEL(to)		to##ILP32
#	define Z_APPEND_data_model(to)		to##ilp32
#	define Z_INSERT_DATA_MODEL(left, right) left##ILP32##right
#	define Z_INSERT_data_model(left, right) left##ilp32##right

#elif Z_DATA_MODEL == Z_DATA_MODEL_ILP64

#	include <Z/formats/data model/ILP64.h>

#	define Z_APPEND_DATA_MODEL(to)		to##ILP64
#	define Z_APPEND_data_model(to)		to##ilp64
#	define Z_INSERT_DATA_MODEL(left, right) left##ILP64##right
#	define Z_INSERT_data_model(left, right) left##ilp64##right

#elif Z_DATA_MODEL == Z_DATA_MODEL_LLP64

#	include <Z/formats/data model/LLP64.h>

#	define Z_APPEND_DATA_MODEL(to)		to##LLP64
#	define Z_APPEND_data_model(to)		to##llp64
#	define Z_INSERT_DATA_MODEL(left, right) left##LLP64##right
#	define Z_INSERT_data_model(left, right) left##llp64##right

#elif Z_DATA_MODEL == Z_DATA_MODEL_LP32

#	include <Z/formats/data model/LP32.h>

#	define Z_APPEND_DATA_MODEL(to)		to##LP32
#	define Z_APPEND_data_model(to)		to##lp32
#	define Z_INSERT_DATA_MODEL(left, right) left##LP32##right
#	define Z_INSERT_data_model(left, right) left##lp32##right

#elif Z_DATA_MODEL == Z_DATA_MODEL_LP64

#	include <Z/formats/data model/LP64.h>

#	define Z_APPEND_DATA_MODEL(to)		to##LP64
#	define Z_APPEND_data_model(to)		to##lp64
#	define Z_INSERT_DATA_MODEL(left, right) left##LP64##right
#	define Z_INSERT_data_model(left, right) left##lp64##right

#elif Z_DATA_MODEL == Z_DATA_MODEL_SILP64

#	include <Z/formats/data model/SILP64.h>

#	define Z_APPEND_DATA_MODEL(to)		to##SILP64
#	define Z_APPEND_data_model(to)		to##silp64
#	define Z_INSERT_DATA_MODEL(left, right) left##SILP64##right
#	define Z_INSERT_data_model(left, right) left##silp64##right

#endif

#define Z_DATA_MODEL_STRING	       Z_APPEND_DATA_MODEL(Z_DATA_MODEL_STRING_)
#define Z_DATA_MODEL_BITS(	 TYPE) Z_INSERT_DATA_MODEL(Z_, _BITS_##TYPE)
#define Z_DATA_MODEL_HAS_TYPE(	 TYPE) Z_DATA_MODEL_HAS_TYPE_##TYPE
#define Z_DATA_MODEL_HAS_LITERAL(TYPE) Z_DATA_MODEL_HAS_LITERAL_##TYPE
#define Z_DATA_MODEL_LITERAL(	 TYPE) Z_DATA_MODEL_LITERAL_##TYPE
#define Z_DATA_MODEL_TYPE(	 TYPE) Z_DATA_MODEL_TYPE_##TYPE
#define Z_DATA_MODEL_VALUE_TYPE( TYPE) Z_DATA_MODEL_VALUE_TYPE_##TYPE

/* MARK: - 8-bit */

#if Z_DATA_MODEL_BITS(CHAR) == 8

#	define Z_DATA_MODEL_LITERAL_UINT8    Z_SUFFIX_U
#	define Z_DATA_MODEL_TYPE_UINT8	     unsigned char
#	define Z_DATA_MODEL_VALUE_TYPE_UINT8 Z_VALUE_TYPE_UCHAR

#	define Z_DATA_MODEL_LITERAL_SINT8    Z_SAME
#	define Z_DATA_MODEL_TYPE_SINT8	     signed char
#	define Z_DATA_MODEL_VALUE_TYPE_SINT8 Z_VALUE_TYPE_SCHAR

#elif Z_DATA_MODEL_BITS(SHORT) == 8

#	define Z_DATA_MODEL_LITERAL_UINT8    Z_SUFFIX_U
#	define Z_DATA_MODEL_TYPE_UINT8	     unsigned short int
#	define Z_DATA_MODEL_VALUE_TYPE_UINT8 Z_VALUE_TYPE_USHORT

#	define Z_DATA_MODEL_LITERAL_SINT8    Z_SAME
#	define Z_DATA_MODEL_TYPE_SINT8	     signed short int
#	define Z_DATA_MODEL_VALUE_TYPE_SINT8 Z_VALUE_TYPE_SSHORT

#else

#	if Z_COMPILER_HAS_LITERAL(UINT8)
#		define Z_DATA_MODEL_LITERAL_UINT8 Z_COMPILER_LITERAL(UINT8)
#	else
#		define Z_DATA_MODEL_LITERAL_UINT8 Z_SUFFIX_U
#	endif

#	define Z_DATA_MODEL_TYPE_UINT8	     Z_COMPILER_TYPE(UINT8)
#	define Z_DATA_MODEL_VALUE_TYPE_UINT8 Z_VALUE_TYPE_UINT8

#	if Z_COMPILER_HAS_LITERAL(SINT8)
#		define Z_DATA_MODEL_LITERAL_SINT8 Z_COMPILER_LITERAL(SINT8)
#	else
#		define Z_DATA_MODEL_LITERAL_SINT8 Z_SAME
#	endif

#	define Z_DATA_MODEL_TYPE_SINT8	     Z_COMPILER_TYPE(SINT8)
#	define Z_DATA_MODEL_VALUE_TYPE_SINT8 Z_VALUE_TYPE_SINT8

#endif

/* MARK: - 16-bit */

#if Z_DATA_MODEL_BITS(CHAR) == 16

#	define Z_DATA_MODEL_LITERAL_UINT16    Z_SUFFIX_U
#	define Z_DATA_MODEL_TYPE_UINT16	      unsigned char
#	define Z_DATA_MODEL_VALUE_TYPE_UINT16 Z_VALUE_TYPE_UCHAR

#	define Z_DATA_MODEL_LITERAL_SINT16    Z_SAME
#	define Z_DATA_MODEL_TYPE_SINT16	      signed char
#	define Z_DATA_MODEL_VALUE_TYPE_SINT16 Z_VALUE_TYPE_SCHAR

#elif Z_DATA_MODEL_BITS(SHORT) == 16

#	define Z_DATA_MODEL_LITERAL_UINT16    Z_SUFFIX_U
#	define Z_DATA_MODEL_TYPE_UINT16	      unsigned short int
#	define Z_DATA_MODEL_VALUE_TYPE_UINT16 Z_VALUE_TYPE_USHORT

#	define Z_DATA_MODEL_LITERAL_SINT16    Z_SAME
#	define Z_DATA_MODEL_TYPE_SINT16	      signed short int
#	define Z_DATA_MODEL_VALUE_TYPE_SINT16 Z_VALUE_TYPE_SSHORT

#elif Z_DATA_MODEL_BITS(INT) == 16

#	define Z_DATA_MODEL_LITERAL_UINT16    Z_SUFFIX_U
#	define Z_DATA_MODEL_TYPE_UINT16	      unsigned int
#	define Z_DATA_MODEL_VALUE_TYPE_UINT16 Z_VALUE_TYPE_UINT

#	define Z_DATA_MODEL_LITERAL_SINT16    Z_SAME
#	define Z_DATA_MODEL_TYPE_SINT16	      signed int
#	define Z_DATA_MODEL_VALUE_TYPE_SINT16 Z_VALUE_TYPE_SINT

#else

#	if Z_COMPILER_HAS_LITERAL(UINT16)
#		define Z_DATA_MODEL_LITERAL_UINT16 Z_COMPILER_LITERAL(UINT16)
#	else
#		define Z_DATA_MODEL_LITERAL_UINT16 Z_SUFFIX_U
#	endif

#	define Z_DATA_MODEL_TYPE_UINT16	      Z_COMPILER_TYPE(UINT16)
#	define Z_DATA_MODEL_VALUE_TYPE_UINT16 Z_VALUE_TYPE_UINT16

#	if Z_COMPILER_HAS_LITERAL(SINT16)
#		define Z_DATA_MODEL_LITERAL_SINT16 Z_COMPILER_LITERAL(SINT16)
#	else
#		define Z_DATA_MODEL_LITERAL_SINT16 Z_SAME
#	endif

#	define Z_DATA_MODEL_TYPE_SINT16	      Z_COMPILER_TYPE(SINT16)
#	define Z_DATA_MODEL_VALUE_TYPE_SINT16 Z_VALUE_TYPE_SINT16

#endif

/* MARK: - 32-bit */

#if Z_DATA_MODEL_BITS(SHORT) == 32

#	define Z_DATA_MODEL_LITERAL_UINT32    Z_SUFFIX_U
#	define Z_DATA_MODEL_TYPE_UINT32	      unsigned short int
#	define Z_DATA_MODEL_VALUE_TYPE_UINT32 Z_VALUE_TYPE_USHORT

#	define Z_DATA_MODEL_LITERAL_SINT32    Z_SAME
#	define Z_DATA_MODEL_TYPE_SINT32	      signed short int
#	define Z_DATA_MODEL_VALUE_TYPE_SINT32 Z_VALUE_TYPE_SSHORT

#elif Z_DATA_MODEL_BITS(INT) == 32

#	define Z_DATA_MODEL_LITERAL_UINT32    Z_SUFFIX_U
#	define Z_DATA_MODEL_TYPE_UINT32	      unsigned int
#	define Z_DATA_MODEL_VALUE_TYPE_UINT32 Z_VALUE_TYPE_UINT

#	define Z_DATA_MODEL_LITERAL_SINT32    Z_SAME
#	define Z_DATA_MODEL_TYPE_SINT32	      signed int
#	define Z_DATA_MODEL_VALUE_TYPE_SINT32 Z_VALUE_TYPE_SINT

#elif Z_DATA_MODEL_BITS(LONG) == 32

#	define Z_DATA_MODEL_LITERAL_UINT32    Z_SUFFIX_UL
#	define Z_DATA_MODEL_TYPE_UINT32	      unsigned long int
#	define Z_DATA_MODEL_VALUE_TYPE_UINT32 Z_VALUE_TYPE_ULONG

#	define Z_DATA_MODEL_LITERAL_SINT32    Z_SUFFIX_L
#	define Z_DATA_MODEL_TYPE_SINT32	      signed long int
#	define Z_DATA_MODEL_VALUE_TYPE_SINT32 Z_VALUE_TYPE_SLONG

#else

#	if Z_COMPILER_HAS_LITERAL(UINT32)
#		define Z_DATA_MODEL_LITERAL_UINT32 Z_COMPILER_LITERAL(UINT32)
#	else
#		define Z_DATA_MODEL_LITERAL_UINT32 Z_SUFFIX_U
#	endif

#	define Z_DATA_MODEL_TYPE_UINT32	      Z_COMPILER_TYPE(UINT32)
#	define Z_DATA_MODEL_VALUE_TYPE_UINT32 Z_VALUE_TYPE_UINT32

#	if Z_COMPILER_HAS_LITERAL(SINT32)
#		define Z_DATA_MODEL_LITERAL_SINT32 Z_COMPILER_LITERAL(SINT32)
#	else
#		define Z_DATA_MODEL_LITERAL_SINT32 Z_SAME
#	endif

#	define Z_DATA_MODEL_TYPE_SINT32	      Z_COMPILER_TYPE(SINT32)
#	define Z_DATA_MODEL_VALUE_TYPE_SINT32 Z_VALUE_TYPE_SINT32

#endif

/* MARK: - 64-bit */

#if Z_DATA_MODEL_BITS(INT) == 64

#	define Z_DATA_MODEL_LITERAL_UINT64    Z_SUFFIX_U
#	define Z_DATA_MODEL_TYPE_UINT64	      unsigned int
#	define Z_DATA_MODEL_VALUE_TYPE_UINT64 Z_VALUE_TYPE_UINT

#	define Z_DATA_MODEL_LITERAL_SINT64    Z_SAME
#	define Z_DATA_MODEL_TYPE_SINT64	      signed int
#	define Z_DATA_MODEL_VALUE_TYPE_SINT64 Z_VALUE_TYPE_SINT

#elif Z_DATA_MODEL_BITS(LONG) == 64

#	define Z_DATA_MODEL_LITERAL_UINT64    Z_SUFFIX_UL
#	define Z_DATA_MODEL_TYPE_UINT64	      unsigned long int
#	define Z_DATA_MODEL_VALUE_TYPE_UINT64 Z_VALUE_TYPE_ULONG

#	define Z_DATA_MODEL_LITERAL_SINT64    Z_SUFFIX_L
#	define Z_DATA_MODEL_TYPE_SINT64	      signed long int
#	define Z_DATA_MODEL_VALUE_TYPE_SINT64 Z_VALUE_TYPE_SLONG

#elif Z_DATA_MODEL_BITS(LLONG) == 64 && (Z_LANGUAGE_HAS_TYPE(C, LLONG) || Z_LANGUAGE_HAS_TYPE(CPP, LLONG))

#	define Z_DATA_MODEL_LITERAL_UINT64    Z_SUFFIX_ULL
#	define Z_DATA_MODEL_TYPE_UINT64	      unsigned long long int
#	define Z_DATA_MODEL_VALUE_TYPE_UINT64 Z_VALUE_TYPE_ULLONG

#	define Z_DATA_MODEL_LITERAL_SINT64    Z_SUFFIX_LL
#	define Z_DATA_MODEL_TYPE_SINT64	      signed long long int
#	define Z_DATA_MODEL_VALUE_TYPE_SINT64 Z_VALUE_TYPE_SLLONG

#else

#	if Z_COMPILER_HAS_TYPE(UINT64)

#		if Z_COMPILER_HAS_LITERAL(UINT64)
#			define Z_DATA_MODEL_LITERAL_UINT64 Z_COMPILER_LITERAL(UINT64)
#		endif

#		define Z_DATA_MODEL_TYPE_UINT64	      Z_COMPILER_TYPE(UINT64)
#		define Z_DATA_MODEL_VALUE_TYPE_UINT64 Z_VALUE_TYPE_UINT64

#	endif

#	if Z_COMPILER_HAS_TYPE(SINT64)

#		if Z_COMPILER_HAS_LITERAL(SINT64)
#			define Z_DATA_MODEL_LITERAL_SINT64 Z_COMPILER_LITERAL(SINT64)
#		endif

#		define Z_DATA_MODEL_TYPE_SINT64	      Z_COMPILER_TYPE(SINT64)
#		define Z_DATA_MODEL_VALUE_TYPE_SINT64 Z_VALUE_TYPE_SINT64

#	endif

#endif

/* MARK: - 128-bit */

#if Z_DATA_MODEL_BITS(LLONG) == 128 && (Z_LANGUAGE_HAS_TYPE(C, LLONG) || Z_LANGUAGE_HAS_TYPE(CPP, LLONG))

#	define Z_DATA_MODEL_LITERAL_UINT128    Z_SUFFIX_ULL
#	define Z_DATA_MODEL_TYPE_UINT128       unsigned long long int
#	define Z_DATA_MODEL_VALUE_TYPE_UINT128 Z_VALUE_TYPE_ULLONG

#	define Z_DATA_MODEL_LITERAL_SINT128    Z_SUFFIX_LL
#	define Z_DATA_MODEL_TYPE_SINT128       signed long long int
#	define Z_DATA_MODEL_VALUE_TYPE_SINT128 Z_VALUE_TYPE_SLLONG

#else

#	if Z_COMPILER_HAS_TYPE(UINT128)

#		if Z_COMPILER_HAS_LITERAL(UINT128)
#			define Z_DATA_MODEL_LITERAL_UINT128 Z_COMPILER_LITERAL(UINT128)
#		endif

#		define Z_DATA_MODEL_TYPE_UINT128       Z_COMPILER_TYPE(UINT128)
#		define Z_DATA_MODEL_VALUE_TYPE_UINT128 Z_VALUE_TYPE_UINT128

#	endif

#	if Z_COMPILER_HAS_TYPE(SINT128)

#		if Z_COMPILER_HAS_LITERAL(SINT128)
#			define Z_DATA_MODEL_LITERAL_SINT128 Z_COMPILER_LITERAL(SINT128)
#		endif

#		define Z_DATA_MODEL_TYPE_SINT128       Z_COMPILER_TYPE(SINT128)
#		define Z_DATA_MODEL_VALUE_TYPE_SINT128 Z_VALUE_TYPE_SINT128

#	endif

#endif

#include <Z/inspection/data model/completion.h>

#endif /* _Z_inspection_data_model_H_ */
