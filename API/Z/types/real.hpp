/* Zeta API - Z/types/real.hpp
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_types_real_HPP
#define Z_types_real_HPP

#include <Z/types/real.h>

namespace Zeta {

	// MARK: - Fixed-format real types

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

#	ifdef Z_X87_DE80
		typedef zx87_de80 x87_DE80;
#	endif

#	ifdef Z_X87_DE96
		typedef zx87_de96 x87_DE96;
#	endif

#	ifdef Z_X87_DE128
		typedef zx87_de128 x87_DE128;
#	endif

#	ifdef Z_IBM_ED
		typedef zibm_ed IBM_ED;
#	endif

#	ifdef Z_BFLOAT16
		typedef zbfloat16 bfloat16;
#	endif

	// MARK: - Standard real types

#	ifdef Z_FLOAT
		typedef zfloat Float;
#	endif

#	ifdef Z_DOUBLE
		typedef zdouble Double;
#	endif

#	ifdef Z_LDOUBLE
		typedef zldouble LDouble;
#	endif

#	ifdef Z_FLOAT16
		typedef zfloat16 Float16;
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

#	ifdef Z_FLOAT32X
		typedef zfloat32x Float32x;
#	endif

#	ifdef Z_FLOAT64X
		typedef zfloat64x Float64x;
#	endif

#	ifdef Z_FLOAT128X
		typedef zfloat128x Float128x;
#	endif

#	ifdef Z_DECIMAL32
		typedef zdecimal32 Decimal32;
#	endif

#	ifdef Z_DECIMAL64
		typedef zdecimal64 Decimal64;
#	endif

#	ifdef Z_DECIMAL128
		typedef zdecimal128 Decimal128;
#	endif

#	ifdef Z_DECIMAL64X
		typedef zdecimal64x Decimal64x;
#	endif

#	ifdef Z_DECIMAL128X
		typedef zdecimal128x Decimal128x;
#	endif

	// MARK: - Default real type

#	ifdef Z_REAL
		typedef zreal Real;
#	endif
}

#endif // Z_types_real_HPP
