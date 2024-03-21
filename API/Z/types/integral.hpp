/* Zeta API - Z/types/integral.hpp
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_types_integral_HPP
#define Z_types_integral_HPP

#include <Z/types/integral.h>

namespace Zeta {

	// MARK: - Fixed-width integral types

#	ifdef Z_UINT8
		typedef zuint8 UInt8;
#	endif

#	ifdef Z_SINT8
		typedef zsint8 SInt8;
#	endif

#	ifdef Z_UINT16
		typedef zuint16 UInt16;
#	endif

#	ifdef Z_SINT16
		typedef zsint16 SInt16;
#	endif

#	ifdef Z_UINT24
		typedef zuint24 UInt24;
#	endif

#	ifdef Z_SINT24
		typedef zsint24 SInt24;
#	endif

#	ifdef Z_UINT32
		typedef zuint32 UInt32;
#	endif

#	ifdef Z_SINT32
		typedef zsint32 SInt32;
#	endif

#	ifdef Z_UINT40
		typedef zuint40 UInt40;
#	endif

#	ifdef Z_SINT40
		typedef zsint40 SInt40;
#	endif

#	ifdef Z_UINT48
		typedef zuint48 UInt48;
#	endif

#	ifdef Z_SINT48
		typedef zsint48 SInt48;
#	endif

#	ifdef Z_UINT56
		typedef zuint56 UInt56;
#	endif

#	ifdef Z_SINT56
		typedef zsint56 SInt56;
#	endif

#	ifdef Z_UINT64
		typedef zuint64 UInt64;
#	endif

#	ifdef Z_SINT64
		typedef zsint64 SInt64;
#	endif

#	ifdef Z_UINT128
		typedef zuint128 UInt128;
#	endif

#	ifdef Z_SINT128
		typedef zsint128 SInt128;
#	endif

	// MARK: - Integral types with at least a certain width

#	ifdef Z_UINT_LEAST8
		typedef zuint_least8 UIntLeast8;
#	endif

#	ifdef Z_SINT_LEAST8
		typedef zsint_least8 SIntLeast8;
#	endif

#	ifdef Z_UINT_LEAST16
		typedef zuint_least16 UIntLeast16;
#	endif

#	ifdef Z_SINT_LEAST16
		typedef zsint_least16 SIntLeast16;
#	endif

#	ifdef Z_UINT_LEAST24
		typedef zuint_least24 UIntLeast24;
#	endif

#	ifdef Z_SINT_LEAST24
		typedef zsint_least24 SIntLeast24;
#	endif

#	ifdef Z_UINT_LEAST32
		typedef zuint_least32 UIntLeast32;
#	endif

#	ifdef Z_SINT_LEAST32
		typedef zsint_least32 SIntLeast32;
#	endif

#	ifdef Z_UINT_LEAST40
		typedef zuint_least40 UIntLeast40;
#	endif

#	ifdef Z_SINT_LEAST40
		typedef zsint_least40 SIntLeast40;
#	endif

#	ifdef Z_UINT_LEAST48
		typedef zuint_least48 UIntLeast48;
#	endif

#	ifdef Z_SINT_LEAST48
		typedef zsint_least48 SIntLeast48;
#	endif

#	ifdef Z_UINT_LEAST56
		typedef zuint_least56 UIntLeast56;
#	endif

#	ifdef Z_SINT_LEAST56
		typedef zsint_least56 SIntLeast56;
#	endif

#	ifdef Z_UINT_LEAST64
		typedef zuint_least64 UIntLeast64;
#	endif

#	ifdef Z_SINT_LEAST64
		typedef zsint_least64 SIntLeast64;
#	endif

	// MARK: - Standard integral types

	typedef zchar	Char;
	typedef zuchar	UChar;
	typedef zschar	SChar;
	typedef zushort UShort;
	typedef zsshort SShort;
	typedef zuint	UInt;
	typedef zsint	SInt;
	typedef zulong	ULong;
	typedef zslong	SLong;

#	ifdef Z_LLONG
		typedef zullong ULLong;
		typedef zsllong SLLong;
#	endif

#	ifdef Z_BOOL
		typedef zbool Bool;
#	endif

#	if Z_DIALECT_HAS_TYPE(CPP98, WCHAR_T)
		typedef wchar_t WChar;
#	endif

#	if Z_DIALECT_HAS_TYPE(CPP20, CHAR8_T)
		typedef char8_t Char8;
#	endif

#	if Z_DIALECT_HAS_TYPE(CPP11, CHAR16_T)
		typedef char16_t Char16;
#	endif

#	if Z_DIALECT_HAS_TYPE(CPP11, CHAR32_T)
		typedef char32_t Char32;
#	endif

	// MARK: - Object size integral types

	typedef zusize USize;
	typedef zssize SSize;

	// MARK: - Maximum size integral types

	typedef zuintmax UIntMax;
	typedef zsintmax SIntMax;

	// MARK: - Pointer size integral types

	typedef zuintptr UIntPtr;
	typedef zsintptr SIntPtr;

	// MARK: - Pointer difference type

	typedef zptrdiff PtrDiff;

	// MARK: - Default types

	typedef zboolean Boolean;
	typedef znatural Natural;
	typedef zinteger Integer;
}

#endif // Z_types_integral_HPP
