/* Z Kit - types/base.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Copyright (C) 2018 Agaxia.

This library  is free software: you  can redistribute it and/or  modify it under
the terms  of the  GNU Lesser General  Public License as  published by  the Free
Software Foundation,  either version 3 of  the License, or (at  your option) any
later version.

This library is distributed in the hope  that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty  of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

You should have received  a copy of the GNU Lesser  General Public License along
with this library. If not, see <http://www.gnu.org/licenses/>. */

#ifndef _Z_types_base_HPP_
#define _Z_types_base_HPP_

#include <Z/types/base.h>
#include <Z/macros/language.hpp>

namespace Zeta {

	/* MARK: - Fixed width types */

	typedef zuint8	UInt8;
	typedef zsint8	SInt8;
	typedef zuint16 UInt16;
	typedef zsint16 SInt16;
	typedef zuint32 UInt32;
	typedef zsint32 SInt32;

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

	/* MARK: - C/C++ fundamental types */

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

#	ifdef Z_FLOAT
		typedef zfloat Float;
#	endif

#	ifdef Z_DOUBLE
		typedef zdouble Double;
#	endif

#	ifdef Z_LDOUBLE
		typedef zldouble LDouble;
#	endif

#	if Z_LANGUAGE_HAS_TYPE(CPP, BOOLEAN)
		typedef bool Boolean;
#	elif Z_LANGUAGE_HAS_TYPE(C, BOOLEAN)
		typedef _Bool Boolean;
#	else
		typedef zboolean Boolean;
#	endif

	/* MARK: - C++ specific fundamental types */

#	if Z_LANGUAGE_HAS_TYPE(CPP, WCHAR)
		typedef wchar_t WChar;
#	endif

#	if Z_LANGUAGE_HAS_TYPE(CPP, CHAR16)
		typedef char16_t Char16;
#	endif

#	if Z_LANGUAGE_HAS_TYPE(CPP, CHAR32)
		typedef char32_t Char32;
#	endif

#	if	Z_LANGUAGE_HAS_SPECIFIER(CPP, DECLARED_TYPE) && \
		Z_LANGUAGE_HAS_LITERAL(CPP, NULL_POINTER)

		typedef decltype(nullptr) NullPointer;
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

	/* MARK: - Pointer type-casting type */

	typedef ZPointer Pointer;

	/* MARK: - Not a type */

	struct NaT {
#		if Z_LANGUAGE_HAS(CPP, DELETED_FUNCTION)
			NaT()			     = delete;
			NaT(const NaT &)	     = delete;
			~NaT()			     = delete;
			NaT &operator =(const NaT &) = delete;
#		endif
	};
};

#endif // _Z_types_base_HPP_
