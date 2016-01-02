/* Z Kit C++ API - types/base.hpp
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_types_base_HPP__
#define __Z_types_base_HPP__

#include <Z/types/base.h>

namespace ZKit {
	typedef zuint8			UInt8;
	typedef zuint16			UInt16;
	typedef zuint32			UInt32;

#	if Z_IS_AVAILABLE(UINT64)
		typedef zuint64		UInt64;
#	endif

#	if Z_IS_AVAILABLE(UINT128)
		typedef zuint128	UInt128;
#	endif

	typedef zint8			Int8;
	typedef zint16			Int16;
	typedef zint32			Int32;

#	if Z_IS_AVAILABLE(INT64)
		typedef zint64		Int64;
#	endif

#	if Z_IS_AVAILABLE(INT128)
		typedef zint128		Int128;
#	endif

#	if Z_IS_AVAILABLE(FLOAT16)
		typedef zfloat16	Float16;
#	endif

#	if Z_IS_AVAILABLE(FLOAT24)
		typedef zfloat24	Float24;
#	endif

#	if Z_IS_AVAILABLE(FLOAT32)
		typedef zfloat32	Float32;
#	endif

#	if Z_IS_AVAILABLE(FLOAT48)
		typedef zfloat48	Float48;
#	endif

#	if Z_IS_AVAILABLE(FLOAT64)
		typedef zfloat64	Float64;
#	endif

#	if Z_IS_AVAILABLE(FLOAT72)
		typedef zfloat72	Float72;
#	endif

#	if Z_IS_AVAILABLE(FLOAT80)
		typedef zfloat80	Float80;
#	endif

#	if Z_IS_AVAILABLE(FLOAT96)
		typedef zfloat96	Float96;
#	endif

#	if Z_IS_AVAILABLE(FLOAT128)
		typedef zfloat128	Float128;
#	endif

	typedef zuchar			UChar;
	typedef zushort			UShort;
	typedef zuint			UInt;
	typedef zulong			ULong;
	typedef zullong			ULLong;

	typedef zchar			Char;
	typedef zshort			Short;
	typedef zint			Int;
	typedef zlong			Long;
	typedef zllong			LLong;

#	if Z_IS_AVAILABLE(FLOAT)
		typedef zfloat		Float;
#	endif

#	if Z_IS_AVAILABLE(DOUBLE)
		typedef zdouble		Double;
#	endif

#	if Z_IS_AVAILABLE(LDOUBLE)
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
	typedef zreal			Real;

	typedef ZOrder			Order;

	typedef ZPointer		Pointer;
};

#endif // __Z_types_base_HPP__
