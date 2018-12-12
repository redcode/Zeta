/* Z Kit - types/segmental.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_types_segmental_H_
#define _Z_types_segmental_H_

#include <Z/types/fundamental.h>

typedef struct {zuint8 index, size;} ZRangeUInt8;
typedef struct {zuint8 a, b;}	     ZIntervalUInt8;

typedef struct {zuint16 index, size;} ZRangeUInt16;
typedef struct {zuint16 a, b;}	      ZIntervalUInt16;

typedef struct {zuint32 index, size;} ZRangeUInt32;
typedef struct {zuint32 a, b;}	      ZIntervalUInt32;

#ifdef Z_UINT64
	typedef struct {zuint64 index, size;} ZRangeUInt64;
	typedef struct {zuint64 a, b;}	      ZIntervalUInt64;
#endif

#ifdef Z_UINT128
	typedef struct {zuint128 index, size;} ZRangeUInt128;
	typedef struct {zuint128 a, b;}	       ZIntervalUInt128;
#endif

#ifdef Z_FLOAT16
	typedef struct {zfloat16 a, b;} ZIntervalFloat16;
#endif

#ifdef Z_FLOAT32
	typedef struct {zfloat32 a, b;} ZIntervalFloat32;
#endif

#ifdef Z_FLOAT64
	typedef struct {zfloat64 a, b;} ZIntervalFloat64;
#endif

#ifdef Z_FLOAT64
	typedef struct {zfloat64 a, b;} ZIntervalFloat64;
#endif

#ifdef Z_FLOAT128
	typedef struct {zfloat128 a, b;} ZIntervalFloat128;
#endif

#ifdef Z_FLOAT80_X87
	typedef struct {zfloat80_x87 a, b;} ZIntervalFloat80_x87;
#endif

#ifdef Z_FLOAT96_X87
	typedef struct {zfloat96_x87 a, b;} ZIntervalFloat96_x87;
#endif

#ifdef Z_FLOAT128_X87
	typedef struct {zfloat128_x87 a, b;} ZIntervalFloat128_x87;
#endif

#define ZRangeType(   TYPE) Z_APPEND_##TYPE##_FixedType(ZRange	 )
#define ZIntervalType(TYPE) Z_APPEND_##TYPE##_FixedType(ZInterval)

typedef ZRangeType(UCHAR ) ZRangeUChar;
typedef ZRangeType(USHORT) ZRangeUShort;
typedef ZRangeType(UINT	 ) ZRangeUInt;
typedef ZRangeType(ULONG ) ZRangeULong;

#ifdef Z_ULLONG
	typedef ZRangeType(ULLONG) ZRangeULLong;
#endif

typedef ZRangeType(USIZE  ) ZRangeUSize;
typedef ZRangeType(UINTMAX) ZRangeUIntMax;
typedef ZRangeType(UINTPTR) ZRangeUIntPtr;
typedef ZRangeType(UINTTOP) ZRangeUIntTop;
typedef ZRangeType(NATURAL) ZRangeNatural;
typedef ZRangeUSize	    ZRange;

#if Z_LANGUAGE_HAS(C, COMPOUND_LITERAL)

#	define z_2d_uint8( x, y	     ) ((Z2DUInt8 ){x, y      })
#	define z_3d_uint8( x, y, z   ) ((Z3DUInt8 ){x, y, z   })
#	define z_4d_uint8( x, y, z, w) ((Z4DUInt8 ){x, y, z, w})
#	define z_2d_sint8( x, y	     ) ((Z2DSInt8 ){x, y      })
#	define z_3d_sint8( x, y, z   ) ((Z3DSInt8 ){x, y, z   })
#	define z_4d_sint8( x, y, z, w) ((Z4DSInt8 ){x, y, z, w})
#	define z_2d_uint16(x, y	     ) ((Z2DUInt16){x, y      })
#	define z_3d_uint16(x, y, z   ) ((Z3DUInt16){x, y, z   })
#	define z_4d_uint16(x, y, z, w) ((Z4DUInt16){x, y, z, w})
#	define z_2d_sint16(x, y	     ) ((Z2DSInt16){x, y      })
#	define z_3d_sint16(x, y, z   ) ((Z3DSInt16){x, y, z   })
#	define z_4d_sint16(x, y, z, w) ((Z4DSInt16){x, y, z, w})
#	define z_2d_uint32(x, y	     ) ((Z2DUInt32){x, y      })
#	define z_3d_uint32(x, y, z   ) ((Z3DUInt32){x, y, z   })
#	define z_4d_uint32(x, y, z, w) ((Z4DUInt32){x, y, z, w})
#	define z_2d_sint32(x, y	     ) ((Z2DSInt32){x, y      })
#	define z_3d_sint32(x, y, z   ) ((Z3DSInt32){x, y, z   })
#	define z_4d_sint32(x, y, z, w) ((Z4DSInt32){x, y, z, w})

#else

#endif

#endif /* _Z_types_segmental_H_ */
