/* Q Kit C++ API - types/base.hpp
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_types_base_HPP__
#define __Q_types_base_HPP__

#include <Q/types/base.h>

namespace QKit {
	typedef quint8			UInt8;
	typedef quint16			UInt16;
	typedef quint32			UInt32;
	typedef quint64			UInt64;

#	if Q_IS_AVAILABLE(UINT128)
		typedef quint128	UInt128;
#	endif

	typedef qint8			Int8;
	typedef qint16			Int16;
	typedef qint32			Int32;
	typedef qint64			Int64;

#	if Q_IS_AVAILABLE(INT128)
		typedef qint128		Int128;
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

	typedef qsize			Size;
	typedef quintmax		UIntMax;
	typedef quintptr		UIntPtr;
	typedef quinttop		UIntTop;

	typedef qssize			SSize;
	typedef qintmax			IntMax;
	typedef qintptr			IntPtr;
	typedef qinttop			IntTop;

	typedef qnatural		Natural;
	typedef qinteger		Integer;
	typedef qreal			Real;
	typedef qboolean		Boolean;
	typedef Int			Status;
};

#endif // __Q_types_base_HPP__
