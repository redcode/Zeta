/* Zeta API - Z/inspection/data_model.h
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2025 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_inspection_data_model_H
#define Z_inspection_data_model_H

#include <Z/keys/data_model.h>
#include <Z/keys/fundamental.h>
#include <Z/inspection/language.h>

#ifndef Z_DATA_MODEL
#	ifdef Z_COMPILER_DATA_MODEL
#		define Z_DATA_MODEL Z_COMPILER_DATA_MODEL
#	else
#		include <Z/inspection/data_model/detection.h>

#		ifndef Z_DATA_MODEL
#			include <Z/inspection/data_model/deduction.h>

#			ifndef Z_DATA_MODEL
#				error "`Z_DATA_MODEL` key not defined."
#			endif
#		endif
#	endif
#endif

#if Z_DATA_MODEL == Z_DATA_MODEL_IP16L32
#	include <Z/formats/data_model/IP16L32.h>

#	define Z_DATA_MODEL_IS_IP16L32	     1
#	define Z_DATA_MODEL_NAME	     Z_DATA_MODEL_NAME_IP16L32
#	define Z_INSERT_DATA_MODEL(lht, rht) lht##IP16L32##rht

#elif Z_DATA_MODEL == Z_DATA_MODEL_I16LP32
#	include <Z/formats/data_model/I16LP32.h>

#	define Z_DATA_MODEL_IS_I16LP32	     1
#	define Z_DATA_MODEL_NAME	     Z_DATA_MODEL_NAME_I16LP32
#	define Z_INSERT_DATA_MODEL(lht, rht) lht##I16LP32##rht

#elif Z_DATA_MODEL == Z_DATA_MODEL_ILP32
#	include <Z/formats/data_model/ILP32.h>

#	define Z_DATA_MODEL_IS_ILP32	     1
#	define Z_DATA_MODEL_NAME	     Z_DATA_MODEL_NAME_ILP32
#	define Z_INSERT_DATA_MODEL(lht, rht) lht##ILP32##rht

#elif Z_DATA_MODEL == Z_DATA_MODEL_ILP64
#	include <Z/formats/data_model/ILP64.h>

#	define Z_DATA_MODEL_IS_ILP64	     1
#	define Z_DATA_MODEL_NAME	     Z_DATA_MODEL_NAME_ILP64
#	define Z_INSERT_DATA_MODEL(lht, rht) lht##ILP64##rht

#elif Z_DATA_MODEL == Z_DATA_MODEL_LLP64
#	include <Z/formats/data_model/LLP64.h>

#	define Z_DATA_MODEL_IS_LLP64	     1
#	define Z_DATA_MODEL_NAME	     Z_DATA_MODEL_NAME_LLP64
#	define Z_INSERT_DATA_MODEL(lht, rht) lht##LLP64##rht

#elif Z_DATA_MODEL == Z_DATA_MODEL_LP32
#	include <Z/formats/data_model/LP32.h>

#	define Z_DATA_MODEL_IS_LP32	     1
#	define Z_DATA_MODEL_NAME	     Z_DATA_MODEL_NAME_LP32
#	define Z_INSERT_DATA_MODEL(lht, rht) lht##LP32##rht

#elif Z_DATA_MODEL == Z_DATA_MODEL_LP64
#	include <Z/formats/data_model/LP64.h>

#	define Z_DATA_MODEL_IS_LP64	     1
#	define Z_DATA_MODEL_NAME	     Z_DATA_MODEL_NAME_LP64
#	define Z_INSERT_DATA_MODEL(lht, rht) lht##LP64##rht

#elif Z_DATA_MODEL == Z_DATA_MODEL_SILP64
#	include <Z/formats/data_model/SILP64.h>

#	define Z_DATA_MODEL_IS_SILP64	     1
#	define Z_DATA_MODEL_NAME	     Z_DATA_MODEL_NAME_SILP64
#	define Z_INSERT_DATA_MODEL(lht, rht) lht##SILP64##rht

#else
#	error "Invalid `Z_DATA_MODEL` key."
#endif

/* MARK: - Getters */

#define Z_DATA_MODEL_IS(DATA_MODEL) \
	Z_IS_TRUE(Z_DATA_MODEL_IS_##DATA_MODEL)

#define Z_DATA_MODEL_HAS_LITERAL(TYPE) \
	Z_IS_TRUE(Z_DATA_MODEL_HAS_LITERAL_##TYPE)

#define Z_DATA_MODEL_HAS_TYPE(TYPE) \
	Z_IS_TRUE(Z_DATA_MODEL_HAS_TYPE_##TYPE)

#define Z_DATA_MODEL_WIDTH(TYPE) \
	Z_INSERT_DATA_MODEL(Z_, _WIDTH_##TYPE)

#define Z_DATA_MODEL_FUNDAMENTAL(TYPE) \
	Z_DATA_MODEL_FUNDAMENTAL_##TYPE

#define Z_DATA_MODEL_LITERAL(TYPE) \
	Z_DATA_MODEL_LITERAL_##TYPE

#define Z_DATA_MODEL_TYPE(TYPE) \
	Z_DATA_MODEL_TYPE_##TYPE

/* MARK: - Selection: int8 */

#if Z_DATA_MODEL_WIDTH(CHAR) == 8
#	define Z_DATA_MODEL_TYPE_UINT8	      unsigned char
#	define Z_DATA_MODEL_FUNDAMENTAL_UINT8 Z_FUNDAMENTAL_UCHAR
#	define Z_DATA_MODEL_LITERAL_UINT8     Z_SUFFIX_U

#	define Z_DATA_MODEL_TYPE_SINT8	      signed char
#	define Z_DATA_MODEL_FUNDAMENTAL_SINT8 Z_FUNDAMENTAL_SCHAR
#	define Z_DATA_MODEL_LITERAL_SINT8     Z_SAME

#else
#	if Z_COMPILER_HAS_TYPE(UINT8)
#		define Z_DATA_MODEL_TYPE_UINT8	      Z_COMPILER_TYPE(UINT8)
#		define Z_DATA_MODEL_FUNDAMENTAL_UINT8 Z_FUNDAMENTAL_UINT8

#		if Z_COMPILER_HAS_LITERAL(UINT8)
#			define Z_DATA_MODEL_LITERAL_UINT8 Z_COMPILER_LITERAL(UINT8)
#		endif
#	endif

#	if Z_COMPILER_HAS_TYPE(SINT8)
#		define Z_DATA_MODEL_TYPE_SINT8	      Z_COMPILER_TYPE(SINT8)
#		define Z_DATA_MODEL_FUNDAMENTAL_SINT8 Z_FUNDAMENTAL_SINT8

#		if Z_COMPILER_HAS_LITERAL(SINT8)
#			define Z_DATA_MODEL_LITERAL_SINT8 Z_COMPILER_LITERAL(SINT8)
#		endif
#	endif
#endif

#ifdef Z_DATA_MODEL_TYPE_UINT8
#	define Z_DATA_MODEL_HAS_TYPE_UINT8 1

#	ifdef Z_DATA_MODEL_LITERAL_UINT8
#		define Z_DATA_MODEL_HAS_LITERAL_UINT8 1
#	else
#		define Z_DATA_MODEL_LITERAL_UINT8 Z_SUFFIX_U
#	endif
#endif

#ifdef Z_DATA_MODEL_TYPE_SINT8
#	define Z_DATA_MODEL_HAS_TYPE_SINT8 1

#	ifdef Z_DATA_MODEL_LITERAL_SINT8
#		define Z_DATA_MODEL_HAS_LITERAL_SINT8 1
#	else
#		define Z_DATA_MODEL_LITERAL_SINT8 Z_SAME
#	endif
#endif

/* MARK: - Selection: int16 */

#if Z_DATA_MODEL_WIDTH(CHAR) == 16
#	define Z_DATA_MODEL_TYPE_UINT16	       unsigned char
#	define Z_DATA_MODEL_FUNDAMENTAL_UINT16 Z_FUNDAMENTAL_UCHAR
#	define Z_DATA_MODEL_LITERAL_UINT16     Z_SUFFIX_U

#	define Z_DATA_MODEL_TYPE_SINT16	       signed char
#	define Z_DATA_MODEL_FUNDAMENTAL_SINT16 Z_FUNDAMENTAL_SCHAR
#	define Z_DATA_MODEL_LITERAL_SINT16     Z_SAME

#elif Z_DATA_MODEL_WIDTH(INT) == 16
#	define Z_DATA_MODEL_TYPE_UINT16	       unsigned int
#	define Z_DATA_MODEL_FUNDAMENTAL_UINT16 Z_FUNDAMENTAL_UINT
#	define Z_DATA_MODEL_LITERAL_UINT16     Z_SUFFIX_U

#	define Z_DATA_MODEL_TYPE_SINT16	       int
#	define Z_DATA_MODEL_FUNDAMENTAL_SINT16 Z_FUNDAMENTAL_SINT
#	define Z_DATA_MODEL_LITERAL_SINT16     Z_SAME

#elif Z_DATA_MODEL_WIDTH(SHORT) == 16
#	define Z_DATA_MODEL_TYPE_UINT16	       unsigned short int
#	define Z_DATA_MODEL_FUNDAMENTAL_UINT16 Z_FUNDAMENTAL_USHORT
#	define Z_DATA_MODEL_LITERAL_UINT16     Z_SUFFIX_U

#	define Z_DATA_MODEL_TYPE_SINT16	       short int
#	define Z_DATA_MODEL_FUNDAMENTAL_SINT16 Z_FUNDAMENTAL_SSHORT
#	define Z_DATA_MODEL_LITERAL_SINT16     Z_SAME

#else
#	if Z_COMPILER_HAS_TYPE(UINT16)
#		define Z_DATA_MODEL_TYPE_UINT16	       Z_COMPILER_TYPE(UINT16)
#		define Z_DATA_MODEL_FUNDAMENTAL_UINT16 Z_FUNDAMENTAL_UINT16

#		if Z_COMPILER_HAS_LITERAL(UINT16)
#			define Z_DATA_MODEL_LITERAL_UINT16 Z_COMPILER_LITERAL(UINT16)
#		endif
#	endif

#	if Z_COMPILER_HAS_TYPE(SINT16)
#		define Z_DATA_MODEL_TYPE_SINT16	       Z_COMPILER_TYPE(SINT16)
#		define Z_DATA_MODEL_FUNDAMENTAL_SINT16 Z_FUNDAMENTAL_SINT16

#		if Z_COMPILER_HAS_LITERAL(SINT16)
#			define Z_DATA_MODEL_LITERAL_SINT16 Z_COMPILER_LITERAL(SINT16)
#		endif
#	endif
#endif

#ifdef Z_DATA_MODEL_TYPE_UINT16
#	define Z_DATA_MODEL_HAS_TYPE_UINT16 1

#	ifdef Z_DATA_MODEL_LITERAL_UINT16
#		define Z_DATA_MODEL_HAS_LITERAL_UINT16 1
#	else
#		define Z_DATA_MODEL_LITERAL_UINT16 Z_SUFFIX_U
#	endif
#endif

#ifdef Z_DATA_MODEL_TYPE_SINT16
#	define Z_DATA_MODEL_HAS_TYPE_SINT16 1

#	ifdef Z_DATA_MODEL_LITERAL_SINT16
#		define Z_DATA_MODEL_HAS_LITERAL_SINT16 1
#	else
#		define Z_DATA_MODEL_LITERAL_SINT16 Z_SAME
#	endif
#endif

/* MARK: - Selection: int32 */

#if Z_DATA_MODEL_WIDTH(INT) == 32
#	define Z_DATA_MODEL_TYPE_UINT32	       unsigned int
#	define Z_DATA_MODEL_FUNDAMENTAL_UINT32 Z_FUNDAMENTAL_UINT
#	define Z_DATA_MODEL_LITERAL_UINT32     Z_SUFFIX_U

#	define Z_DATA_MODEL_TYPE_SINT32	       int
#	define Z_DATA_MODEL_FUNDAMENTAL_SINT32 Z_FUNDAMENTAL_SINT
#	define Z_DATA_MODEL_LITERAL_SINT32     Z_SAME

#elif Z_DATA_MODEL_WIDTH(SHORT) == 32
#	define Z_DATA_MODEL_TYPE_UINT32	       unsigned short int
#	define Z_DATA_MODEL_FUNDAMENTAL_UINT32 Z_FUNDAMENTAL_USHORT
#	define Z_DATA_MODEL_LITERAL_UINT32     Z_SUFFIX_U

#	define Z_DATA_MODEL_TYPE_SINT32	       short int
#	define Z_DATA_MODEL_FUNDAMENTAL_SINT32 Z_FUNDAMENTAL_SSHORT
#	define Z_DATA_MODEL_LITERAL_SINT32     Z_SAME

#elif Z_DATA_MODEL_WIDTH(LONG) == 32
#	define Z_DATA_MODEL_TYPE_UINT32	       unsigned long int
#	define Z_DATA_MODEL_FUNDAMENTAL_UINT32 Z_FUNDAMENTAL_ULONG
#	define Z_DATA_MODEL_LITERAL_UINT32     Z_SUFFIX_UL

#	define Z_DATA_MODEL_TYPE_SINT32	       long int
#	define Z_DATA_MODEL_FUNDAMENTAL_SINT32 Z_FUNDAMENTAL_SLONG
#	define Z_DATA_MODEL_LITERAL_SINT32     Z_SUFFIX_L

#else
#	if Z_COMPILER_HAS_TYPE(UINT32)
#		define Z_DATA_MODEL_TYPE_UINT32	       Z_COMPILER_TYPE(UINT32)
#		define Z_DATA_MODEL_FUNDAMENTAL_UINT32 Z_FUNDAMENTAL_UINT32

#		if Z_COMPILER_HAS_LITERAL(UINT32)
#			define Z_DATA_MODEL_LITERAL_UINT32 Z_COMPILER_LITERAL(UINT32)
#		endif
#	endif

#	if Z_COMPILER_HAS_TYPE(SINT32)
#		define Z_DATA_MODEL_TYPE_SINT32	       Z_COMPILER_TYPE(SINT32)
#		define Z_DATA_MODEL_FUNDAMENTAL_SINT32 Z_FUNDAMENTAL_SINT32

#		if Z_COMPILER_HAS_LITERAL(SINT32)
#			define Z_DATA_MODEL_LITERAL_SINT32 Z_COMPILER_LITERAL(SINT32)
#		endif
#	endif
#endif

#ifdef Z_DATA_MODEL_TYPE_UINT32
#	define Z_DATA_MODEL_HAS_TYPE_UINT32 1

#	ifdef Z_DATA_MODEL_LITERAL_UINT32
#		define Z_DATA_MODEL_HAS_LITERAL_UINT32 1
#	else
#		define Z_DATA_MODEL_LITERAL_UINT32 Z_SUFFIX_U
#	endif
#endif

#ifdef Z_DATA_MODEL_TYPE_SINT32
#	define Z_DATA_MODEL_HAS_TYPE_SINT32 1

#	ifdef Z_DATA_MODEL_LITERAL_SINT32
#		define Z_DATA_MODEL_HAS_LITERAL_SINT32 1
#	else
#		define Z_DATA_MODEL_LITERAL_SINT32 Z_SAME
#	endif
#endif

/* MARK: - Selection: int64 */

#if Z_DATA_MODEL_WIDTH(INT) == 64
#	define Z_DATA_MODEL_TYPE_UINT64	       unsigned int
#	define Z_DATA_MODEL_FUNDAMENTAL_UINT64 Z_FUNDAMENTAL_UINT
#	define Z_DATA_MODEL_LITERAL_UINT64     Z_SUFFIX_U

#	define Z_DATA_MODEL_TYPE_SINT64	       int
#	define Z_DATA_MODEL_FUNDAMENTAL_SINT64 Z_FUNDAMENTAL_SINT
#	define Z_DATA_MODEL_LITERAL_SINT64     Z_SAME

#elif Z_DATA_MODEL_WIDTH(LONG) == 64
#	define Z_DATA_MODEL_TYPE_UINT64	       unsigned long int
#	define Z_DATA_MODEL_FUNDAMENTAL_UINT64 Z_FUNDAMENTAL_ULONG
#	define Z_DATA_MODEL_LITERAL_UINT64     Z_SUFFIX_UL

#	define Z_DATA_MODEL_TYPE_SINT64	       long int
#	define Z_DATA_MODEL_FUNDAMENTAL_SINT64 Z_FUNDAMENTAL_SLONG
#	define Z_DATA_MODEL_LITERAL_SINT64     Z_SUFFIX_L

#elif	Z_DATA_MODEL_WIDTH(LLONG) == 64 && \
	(Z_DIALECT_HAS_TYPE(C99, LONG_LONG) || Z_DIALECT_HAS_TYPE(CPP11, LONG_LONG))

#	define Z_DATA_MODEL_TYPE_UINT64	       unsigned long long int
#	define Z_DATA_MODEL_FUNDAMENTAL_UINT64 Z_FUNDAMENTAL_ULLONG
#	define Z_DATA_MODEL_LITERAL_UINT64     Z_SUFFIX_ULL

#	define Z_DATA_MODEL_TYPE_SINT64	       long long int
#	define Z_DATA_MODEL_FUNDAMENTAL_SINT64 Z_FUNDAMENTAL_SLLONG
#	define Z_DATA_MODEL_LITERAL_SINT64     Z_SUFFIX_LL

#else
#	if Z_COMPILER_HAS_TYPE(UINT64)
#		define Z_DATA_MODEL_TYPE_UINT64	       Z_COMPILER_TYPE(UINT64)
#		define Z_DATA_MODEL_FUNDAMENTAL_UINT64 Z_FUNDAMENTAL_UINT64

#		if Z_COMPILER_HAS_LITERAL(UINT64)
#			define Z_DATA_MODEL_LITERAL_UINT64 Z_COMPILER_LITERAL(UINT64)
#		endif
#	endif

#	if Z_COMPILER_HAS_TYPE(SINT64)
#		define Z_DATA_MODEL_TYPE_SINT64	       Z_COMPILER_TYPE(SINT64)
#		define Z_DATA_MODEL_FUNDAMENTAL_SINT64 Z_FUNDAMENTAL_SINT64

#		if Z_COMPILER_HAS_LITERAL(SINT64)
#			define Z_DATA_MODEL_LITERAL_SINT64 Z_COMPILER_LITERAL(SINT64)
#		endif
#	endif
#endif

#ifdef Z_DATA_MODEL_TYPE_UINT64
#	define Z_DATA_MODEL_HAS_TYPE_UINT64 1

#	ifdef Z_DATA_MODEL_LITERAL_UINT64
#		define Z_DATA_MODEL_HAS_LITERAL_UINT64 1
#	else
#		define Z_DATA_MODEL_LITERAL_UINT64 Z_SUFFIX_U
#	endif
#endif

#ifdef Z_DATA_MODEL_TYPE_SINT64
#	define Z_DATA_MODEL_HAS_TYPE_SINT64 1

#	ifdef Z_DATA_MODEL_LITERAL_SINT64
#		define Z_DATA_MODEL_HAS_LITERAL_SINT64 1
#	else
#		define Z_DATA_MODEL_LITERAL_SINT64 Z_SAME
#	endif
#endif

/* MARK: - Selection: int128 */

#if	Z_DATA_MODEL_WIDTH(LLONG) == 128 && \
	(Z_DIALECT_HAS_TYPE(C99, LONG_LONG) || Z_DIALECT_HAS_TYPE(CPP11, LONG_LONG))

#	define Z_DATA_MODEL_TYPE_UINT128	unsigned long long int
#	define Z_DATA_MODEL_FUNDAMENTAL_UINT128 Z_FUNDAMENTAL_ULLONG
#	define Z_DATA_MODEL_LITERAL_UINT128	Z_SUFFIX_ULL

#	define Z_DATA_MODEL_TYPE_SINT128	long long int
#	define Z_DATA_MODEL_FUNDAMENTAL_SINT128 Z_FUNDAMENTAL_SLLONG
#	define Z_DATA_MODEL_LITERAL_SINT128	Z_SUFFIX_LL

#else
#	if Z_COMPILER_HAS_TYPE(UINT128)
#		define Z_DATA_MODEL_TYPE_UINT128	Z_COMPILER_TYPE(UINT128)
#		define Z_DATA_MODEL_FUNDAMENTAL_UINT128 Z_FUNDAMENTAL_UINT128

#		if Z_COMPILER_HAS_LITERAL(UINT128)
#			define Z_DATA_MODEL_LITERAL_UINT128 Z_COMPILER_LITERAL(UINT128)
#		endif
#	endif

#	if Z_COMPILER_HAS_TYPE(SINT128)
#		define Z_DATA_MODEL_TYPE_SINT128	Z_COMPILER_TYPE(SINT128)
#		define Z_DATA_MODEL_FUNDAMENTAL_SINT128 Z_FUNDAMENTAL_SINT128

#		if Z_COMPILER_HAS_LITERAL(SINT128)
#			define Z_DATA_MODEL_LITERAL_SINT128 Z_COMPILER_LITERAL(SINT128)
#		endif
#	endif
#endif

#ifdef Z_DATA_MODEL_TYPE_UINT128
#	define Z_DATA_MODEL_HAS_TYPE_UINT128 1

#	ifdef Z_DATA_MODEL_LITERAL_UINT128
#		define Z_DATA_MODEL_HAS_LITERAL_UINT128 1
#	else
#		define Z_DATA_MODEL_LITERAL_UINT128 Z_SUFFIX_U
#	endif
#endif

#ifdef Z_DATA_MODEL_TYPE_SINT128
#	define Z_DATA_MODEL_HAS_TYPE_SINT128 1

#	ifdef Z_DATA_MODEL_LITERAL_SINT128
#		define Z_DATA_MODEL_HAS_LITERAL_SINT128 1
#	else
#		define Z_DATA_MODEL_LITERAL_SINT128 Z_SAME
#	endif
#endif

#endif /* Z_inspection_data_model_H */
