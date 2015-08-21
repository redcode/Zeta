/* Z Kit C++ API - types/base.hpp
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_types_base_HPP__
#define __Z_types_base_HPP__

#include <Z/types/base.h>

namespace ZKit {
	typedef zuint8			UInt8;
	typedef zuint16			UInt16;
	typedef zuint32			UInt32;
	typedef zuint64			UInt64;

#	if Z_IS_AVAILABLE(UINT128)
		typedef zuint128	UInt128;
#	endif

	typedef zint8			Int8;
	typedef zint16			Int16;
	typedef zint32			Int32;
	typedef zint64			Int64;

#	if Z_IS_AVAILABLE(INT128)
		typedef zint128		Int128;
#	endif

	typedef unsigned char		UChar;
	typedef unsigned short int	UShort;
	typedef unsigned int		UInt;
	typedef unsigned long int	ULong;
	typedef unsigned long long int	ULLong;

	typedef signed char		Char;
	typedef signed short int	Short;
	typedef signed int		Int;
	typedef signed long int		Long;
	typedef signed long long int	LLong;

	typedef float			Float;
	typedef double			Double;
	typedef long double		LDouble;

	typedef zsize			Size;
	typedef zuintmax		UIntMax;
	typedef zuintptr		UIntPtr;
	typedef zuinttop		UIntTop;

	typedef zssize			SSize;
	typedef zintmax			IntMax;
	typedef zintptr			IntPtr;
	typedef zinttop			IntTop;

	typedef znatural		Natural;
	typedef zinteger		Integer;
	typedef zreal			Real;
	typedef zboolean		Boolean;

	typedef Int			Status;
};

#endif // __Z_types_base_HPP__
