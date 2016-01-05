/* Z Kit C API - types/comparison.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_types_comparison_H__
#define __Z_types_comparison_H__

#include <Z/types/base.h>

typedef int (* ZCompare	       )(void *a, void *b	     );
typedef int (* ZCompareWithData)(void *a, void *b, void *data);

typedef int (* ZCompareUInt8	     )(zuint8  a, zuint8  b		);
typedef int (* ZCompareUInt8WithData )(zuint8  a, zuint8  b, void *data);
typedef int (* ZCompareUInt16	     )(zuint16 a, zuint16 b		);
typedef int (* ZCompareUInt16WithData)(zuint16 a, zuint16 b, void *data);
typedef int (* ZCompareUInt32	     )(zuint32 a, zuint32 b		);
typedef int (* ZCompareUInt32WithData)(zuint32 a, zuint32 b, void *data);

#if Z_IS_AVAILABLE(UINT64)
	typedef int (* ZCompareUInt64	     )(zuint64 a, zuint64 b	       );
	typedef int (* ZCompareUInt64WithData)(zuint64 a, zuint64 b, void *data);
#endif

#if Z_IS_AVAILABLE(UINT128)
	typedef int (* ZCompareUInt128	      )(zuint128 a, zuint128 b		  );
	typedef int (* ZCompareUInt128WithData)(zuint128 a, zuint128 b, void *data);
#endif

typedef int (* ZCompareInt8	    )(zuint8  a, zuint8  b	      );
typedef int (* ZCompareInt8WithData )(zuint8  a, zuint8  b, void *data);
typedef int (* ZCompareInt16	    )(zuint16 a, zuint16 b	      );
typedef int (* ZCompareInt16WithData)(zuint16 a, zuint16 b, void *data);
typedef int (* ZCompareInt32	    )(zuint32 a, zuint32 b	      );
typedef int (* ZCompareInt32WithData)(zuint32 a, zuint32 b, void *data);

#if Z_IS_AVAILABLE(INT64)
	typedef int (* ZCompareInt64	    )(zuint64 a, zuint64 b	      );
	typedef int (* ZCompareInt64WithData)(zuint64 a, zuint64 b, void *data);
#endif

#if Z_IS_AVAILABLE(INT128)
	typedef int (* ZCompareInt128	     )(zuint128 a, zuint128 b		 );
	typedef int (* ZCompareInt128WithData)(zuint128 a, zuint128 b, void *data);
#endif

#if Z_IS_AVAILABLE(FLOAT16)
	typedef int (* ZCompareFloat16	      )(zfloat16 a, zfloat16 b		  );
	typedef int (* ZCompareFloat16WithData)(zfloat16 a, zfloat16 b, void *data);
#endif

#if Z_IS_AVAILABLE(FLOAT24)
	typedef int (* ZCompareFloat24	      )(zfloat24 a, zfloat24 b		  );
	typedef int (* ZCompareFloat24WithData)(zfloat24 a, zfloat24 b, void *data);
#endif

#if Z_IS_AVAILABLE(FLOAT32)
	typedef int (* ZCompareFloat32	      )(zfloat32 a, zfloat32 b		  );
	typedef int (* ZCompareFloat32WithData)(zfloat32 a, zfloat32 b, void *data);
#endif

#if Z_IS_AVAILABLE(FLOAT48)
	typedef int (* ZCompareFloat48	      )(zfloat48 a, zfloat48 b		  );
	typedef int (* ZCompareFloat48WithData)(zfloat48 a, zfloat48 b, void *data);
#endif

#if Z_IS_AVAILABLE(FLOAT64)
	typedef int (* ZCompareFloat64	      )(zfloat64 a, zfloat64 b		  );
	typedef int (* ZCompareFloat64WithData)(zfloat64 a, zfloat64 b, void *data);
#endif

#if Z_IS_AVAILABLE(FLOAT72)
	typedef int (* ZCompareFloat72	      )(zfloat72 a, zfloat72 b		   );
	typedef int (* ZCompareFloat72WithData)(zfloat72 a, zfloat72 b, void *data);
#endif

#if Z_IS_AVAILABLE(FLOAT80)
	typedef int (* ZCompareFloat80	      )(zfloat80 a, zfloat80 b		  );
	typedef int (* ZCompareFloat80WithData)(zfloat80 a, zfloat80 b, void *data);
#endif

#if Z_IS_AVAILABLE(FLOAT96)
	typedef int (* ZCompareFloat96	      )(zfloat96 a, zfloat96 b		  );
	typedef int (* ZCompareFloat96WithData)(zfloat96 a, zfloat96 b, void *data);
#endif

#if Z_IS_AVAILABLE(FLOAT128)
	typedef int (* ZCompareFloat128	       )(zfloat128 a, zfloat128 b	     );
	typedef int (* ZCompareFloat128WithData)(zfloat128 a, zfloat128 b, void *data);
#endif

#define ZCompareType(	     TYPE) Z_INSERT_##TYPE##_FixedType(ZCompare,	 )
#define ZCompareTypeWithData(TYPE) Z_INSERT_##TYPE##_FixedType(ZCompare, WithData)

typedef int (* ZCompare8Bit	     )(Z8Bit   a, Z8Bit   b	       );
typedef int (* ZCompare8BitWithData  )(Z8Bit   a, Z8Bit   b, void *data);
typedef int (* ZCompare16Bit	     )(Z16Bit  a, Z16Bit  b	       );
typedef int (* ZCompare16BitWithData )(Z16Bit  a, Z16Bit  b, void *data);
typedef int (* ZCompare32Bit	     )(Z32Bit  a, Z32Bit  b	       );
typedef int (* ZCompare32BitWithData )(Z32Bit  a, Z32Bit  b, void *data);
typedef int (* ZCompare64Bit	     )(Z64Bit  a, Z64Bit  b	       );
typedef int (* ZCompare64BitWithData )(Z64Bit  a, Z64Bit  b, void *data);
typedef int (* ZCompare128Bit	     )(Z128Bit a, Z128Bit b	       );
typedef int (* ZCompare128BitWithData)(Z128Bit a, Z128Bit b, void *data);

typedef int (* ZComparePointer	      )(ZPointer a, ZPointer b		  );
typedef int (* ZComparePointerWithData)(ZPointer a, ZPointer b, void *data);

#endif /* __Z_types_handling_H__ */
