/* Z Kit C++ API - traits/SizedNumber.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_traits_SizedNumber_HPP__
#define __Z_traits_SizedNumber_HPP__

#include <Z/types/base.hpp>

namespace Zeta {

	template <UInt S> struct SizedNumber;

	template <> struct SizedNumber<1> {
		typedef UInt8 natural;
		typedef Int8  integer;
	};

	template <> struct SizedNumber<2> {
		typedef UInt16 natural;
		typedef Int16  integer;

#		ifdef Z_FLOAT16
			typedef Float16 real;
#		endif
	};

#	ifdef Z_FLOAT24
		template <> struct SizedNumber<3> {
			typedef Float24 real;
		};
#	endif

	template <> struct SizedNumber<4> {
		typedef UInt32 natural;
		typedef Int32  integer;

#		ifdef Z_FLOAT32
			typedef Float32 real;
#		endif
	};

#	ifdef Z_FLOAT48
		template <> struct SizedNumber<6> {
			typedef Float48 real;
		};
#	endif

#	if defined(Z_BINT64) || defined(Z_FLOAT64)
		template <> struct SizedNumber<8> {
#			ifdef Z_UINT64
				typedef UInt64 natural;
#			endif

#			ifdef Z_INT64
				typedef Int64 integer;
#			endif

#			ifdef Z_FLOAT64
				typedef Float64 real;
#			endif
		};
#	endif

#	ifdef Z_FLOAT72
		template <> struct SizedNumber<9> {
			typedef Float72 real;
		};
#	endif

#	ifdef Z_FLOAT80
		template <> struct SizedNumber<10> {
			typedef Float80 real;
		};
#	endif

#	ifdef Z_FLOAT96
		template <> struct SizedNumber<12> {
			typedef Float96 real;
		};
#	endif

#	if defined(Z_BINT128) || defined(Z_FLOAT128)
		template <> struct SizedNumber<16> {
#			ifdef Z_UINT128
				typedef UInt128 natural;
#			endif

#			ifdef Z_INT128
				typedef Int128 integer;
#			endif

#			ifdef Z_FLOAT128
				typedef Float128 real;
#			endif
		};
#	endif

}

#endif // __Z_traits_SizedNumber_HPP__
