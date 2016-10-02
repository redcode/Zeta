/* Z Kit C++ API - types/base.hpp
 _____ 	_______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_|
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_types_base_HPP__
#define __Z_types_base_HPP__

#include <Z/types/base.h>

namespace Zeta {
	typedef zuint8			UInt8;
	typedef zuint16			UInt16;
	typedef zuint32			UInt32;

#	ifdef Z_UINT64
		typedef zuint64		UInt64;
#	endif

#	ifdef Z_UINT128
		typedef zuint128	UInt128;
#	endif

	typedef zint8			Int8;
	typedef zint16			Int16;
	typedef zint32			Int32;

#	ifdef Z_INT64
		typedef zint64		Int64;
#	endif

#	ifdef Z_INT128
		typedef zint128		Int128;
#	endif

#	ifdef Z_FLOAT16
		typedef zfloat16	Float16;
#	endif

#	ifdef Z_FLOAT24
		typedef zfloat24	Float24;
#	endif

#	ifdef Z_FLOAT32
		typedef zfloat32	Float32;
#	endif

#	ifdef Z_FLOAT48
		typedef zfloat48	Float48;
#	endif

#	ifdef Z_FLOAT64
		typedef zfloat64	Float64;
#	endif

#	ifdef Z_FLOAT72
		typedef zfloat72	Float72;
#	endif

#	ifdef Z_FLOAT80
		typedef zfloat80	Float80;
#	endif

#	ifdef Z_FLOAT96
		typedef zfloat96	Float96;
#	endif

#	ifdef Z_FLOAT128
		typedef zfloat128	Float128;
#	endif

	typedef zuchar			UChar;
	typedef zushort			UShort;
	typedef zuint			UInt;
	typedef zulong			ULong;

#	ifdef Z_ULLONG
		typedef zullong		ULLong;
#	endif

	typedef zchar			Char;
	typedef zshort			Short;
	typedef zint			Int;
	typedef zlong			Long;

#	ifdef Z_LLONG
		typedef zllong		LLong;
#	endif

#	ifdef Z_FLOAT
		typedef zfloat		Float;
#	endif

#	ifdef Z_DOUBLE
		typedef zdouble		Double;
#	endif

#	ifdef Z_LDOUBLE
		typedef zldouble	LDouble;
#	endif

	typedef zsize			Size;
	typedef zssize			SSize;

	typedef zuintmax		UIntMax;
	typedef zuintptr		UIntPtr;
	typedef zuinttop		UIntTop;

	typedef zintmax			IntMax;
	typedef zintptr			IntPtr;
	typedef zinttop			IntTop;

	typedef zboolean		Boolean;
	typedef zcharacter		Character;
	typedef znatural		Natural;
	typedef zinteger		Integer;

#	ifdef Z_REAL
		typedef zreal		Real;
#	endif

	typedef ZOrder			Order;

	typedef ZPointer		Pointer;
};

#endif // __Z_types_base_HPP__
