/* Z Kit - types/base.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Copyright (C) 2018 Agaxia.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_types_base_HPP__
#define __Z_types_base_HPP__

#include <Z/types/base.h>
#include <Z/macros/language.hpp>

namespace Zeta {
	typedef zuint8	UInt8;
	typedef zuint16 UInt16;
	typedef zuint32 UInt32;

#	ifdef Z_UINT64
		typedef zuint64 UInt64;
#	endif

#	ifdef Z_UINT128
		typedef zuint128 UInt128;
#	endif

	typedef zsint8	SInt8;
	typedef zsint16 SInt16;
	typedef zsint32 SInt32;

#	ifdef Z_SINT64
		typedef zsint64 SInt64;
#	endif

#	ifdef Z_SINT128
		typedef zsint128 SInt128;
#	endif

#	ifdef Z_FLOAT32
		typedef zfloat32 Float32;
#	endif

#	ifdef Z_FLOAT64
		typedef zfloat64 Float64;
#	endif

#	ifdef Z_FLOAT128
		typedef zfloat128 Float128;
#	endif

#	ifdef Z_FLOAT80_X87
		typedef zfloat80_x87 Float80_x87;
#	endif

#	ifdef Z_FLOAT96_X87
		typedef zfloat96_x87 Float96_x87;
#	endif

#	ifdef Z_FLOAT128_X87
		typedef zfloat128_x87 Float128_x87;
#	endif

	typedef zbint8	BInt8;
	typedef zbint16 BInt16;
	typedef zbint32 BInt32;

#	ifdef Z_BINT64
		typedef zbint64 BInt64;
#	endif

#	ifdef Z_BINT128
		typedef zbint128 BInt128;
#	endif

	typedef zchar	Char;
	typedef zuchar	UChar;
	typedef zushort UShort;
	typedef zuint	UInt;
	typedef zulong	ULong;

#	ifdef Z_ULLONG
		typedef zullong ULLong;
#	endif

	typedef zschar	SChar;
	typedef zsshort SShort;
	typedef zsint	SInt;
	typedef zslong	SLong;

#	ifdef Z_SLLONG
		typedef zsllong SLLong;
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

	typedef zusize USize;
	typedef zssize SSize;

	typedef zuintmax UIntMax;
	typedef zsintmax SIntMax;

	typedef zuintptr UIntPtr;
	typedef zsintptr SIntPtr;

	typedef zuinttop UIntTop;
	typedef zsinttop SIntTop;

#	if Z_LANGUAGE_HAS_TYPE(CPP, BOOLEAN)
		typedef bool Boolean;
#	else
		typedef zboolean Boolean;
#	endif

#	if Z_LANGUAGE_HAS_SPECIFIER(CPP, DECLARED_TYPE) && Z_LANGUAGE_HAS_LITERAL(CPP, NULL_POINTER)
		typedef decltype(nullptr) NullPointer;
#	endif

	typedef znatural Natural;
	typedef zinteger Integer;

#	ifdef Z_REAL
		typedef zreal Real;
#	endif

	typedef ZPointer Pointer;

	struct NaT {
#		if Z_LANGUAGE_HAS(CPP, DELETED_FUNCTION)
			NaT()			     = delete;
			NaT(const NaT &)	     = delete;
			~NaT()			     = delete;
			NaT &operator =(const NaT &) = delete;
#		endif
	};
};

#endif // __Z_types_base_HPP__
