/* Z Kit - types/fundamental.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2019 Manuel Sainz de Baranda y Goñi.
Copyright (C) 2018 Sofía Ortega Sosa.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_types_fundamental_HPP
#define Z_types_fundamental_HPP

#include <Z/types/integral.h>
#include <Z/macros/language.hpp>

namespace Zeta {

	/* MARK: - Fixed width integral types */

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

	/* MARK: - Fixed format real types */

#	ifdef Z_BFP16
		typedef zbfp16 BFP16;
#	endif

#	ifdef Z_BFP32
		typedef zbfp32 BFP32;
#	endif

#	ifdef Z_BFP64
		typedef zbfp64 BFP64;
#	endif

#	ifdef Z_BFP128
		typedef zbfp128 BFP128;
#	endif

#	ifdef Z_DFP32
		typedef zdfp32 DFP32;
#	endif

#	ifdef Z_DFP64
		typedef zdfp64 DFP64;
#	endif

#	ifdef Z_DFP128
		typedef zdfp128 DFP128;
#	endif

#	ifdef Z_BFLOAT16
		typedef zbfloat16 bfloat16;
#	endif

#	ifdef Z_ARM_FP16
		typedef zarm_fp16 ARM_FP16;
#	endif

#	ifdef Z_X87DE80
		typedef zx87de80 x87_DE80;
#	endif

#	ifdef Z_X87DE96
		typedef zx87de96 x87_DE96;
#	endif

#	ifdef Z_X87DE128
		typedef zx87de128 x87_DE128;
#	endif

	/* MARK: - Integral types with at least a certain width */

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

	/* MARK: - Standard base types */

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

#	if Z_DIALECT_HAS_TYPE(CPP, BOOL)
		typedef bool Boolean;
#	elif Z_DIALECT_HAS_TYPE(C, BOOL)
		typedef _Bool Boolean;
#	else
		typedef zboolean Boolean;
#	endif

#	if Z_DIALECT_HAS_TYPE(CPP, WCHAR_T)
		typedef wchar_t WChar;
#	endif

#	if Z_DIALECT_HAS_TYPE(CPP, CHAR8_T)
		typedef char8_t Char8;
#	endif

#	if Z_DIALECT_HAS_TYPE(CPP, CHAR16_T)
		typedef char16_t Char16;
#	endif

#	if Z_DIALECT_HAS_TYPE(CPP, CHAR32_T)
		typedef char32_t Char32;
#	endif

#	ifdef Z_FLOAT
		typedef zfloat Float;
#	endif

#	ifdef Z_DOUBLE
		typedef zdouble Double;
#	endif

#	ifdef Z_LDOUBLE
		typedef zldouble LDouble;
#	endif

#	if	Z_DIALECT_HAS_SPECIFIER(CPP, DECLTYPE) && \
		Z_DIALECT_HAS_LITERAL  (CPP, NULLPTR )

		typedef decltype(nullptr) NullPointer;
#		define Z_NULL_POINTER	  Z_SAME
#	endif

	/* MARK: - Object size integral types */

	typedef zusize USize;
	typedef zssize SSize;

	/* MARK: - Maximum size integral types */

	typedef zuintmax UIntMax;
	typedef zsintmax SIntMax;

	/* MARK: - Pointer size integral types */

	typedef zuintptr UIntPtr;
	typedef zsintptr SIntPtr;

	/* MARK: - Optimum maximum size integral types */

	typedef zuinttop UIntTop;
	typedef zsinttop SIntTop;

	/* MARK: - Default types */

	typedef znatural Natural;
	typedef zinteger Integer;

#	ifdef Z_REAL
		typedef zreal Real;
#	endif
};

#endif // Z_types_fundamental_HPP
