/* Z Kit - types/dimensional.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2019 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_types_dimensional_H_
#define Z_types_dimensional_H_

#include <Z/types/fundamental.h>

#define Z_TYPES(Type, type)			\
typedef struct {z##type x, y;}	     Z2D##Type; \
typedef struct {z##type x, y, z;}    Z3D##Type; \
typedef struct {z##type x, y, z, w;} Z4D##Type;

#define Z2DType(TYPE) Z_APPEND_##TYPE##_FixedType(Z2D)
#define Z3DType(TYPE) Z_APPEND_##TYPE##_FixedType(Z3D)
#define Z4DType(TYPE) Z_APPEND_##TYPE##_FixedType(Z4D)

Z_TYPES(UInt8,	uint8 )
Z_TYPES(SInt8,	sint8 )
Z_TYPES(UInt16, uint16)
Z_TYPES(SInt16, sint16)
Z_TYPES(UInt32, uint32)
Z_TYPES(SInt32, sint32)

#ifdef Z_UINT64
	Z_TYPES(UInt64, uint64)
#endif

#ifdef Z_SINT64
	Z_TYPES(SInt64, sint64)
#endif

#ifdef Z_UINT128
	Z_TYPES(UInt128, uint128)
#endif

#ifdef Z_SINT128
	Z_TYPES(SInt128, sint128)
#endif

#ifdef Z_FLOAT16
	Z_TYPES(Float16, float16)
#endif

#ifdef Z_FLOAT32
	Z_TYPES(Float32, float32)
#endif

#ifdef Z_FLOAT64
	Z_TYPES(Float64, float64)
#endif

#ifdef Z_FLOAT128
	Z_TYPES(Float128, float128)
#endif

#ifdef Z_FLOAT80_X87
	Z_TYPES(Float80_x87, float80_x87)
#endif

#ifdef Z_FLOAT96_X87
	Z_TYPES(Float96_x87, float96_x87)
#endif

#ifdef Z_FLOAT128_X87
	Z_TYPES(Float128_x87, float128_x87)
#endif

#undef Z_TYPES

typedef Z2DType(UCHAR) Z2DUChar;
typedef Z3DType(UCHAR) Z3DUChar;
typedef Z4DType(UCHAR) Z4DUChar;

typedef Z2DType(SCHAR) Z2DSChar;
typedef Z3DType(SCHAR) Z3DSChar;
typedef Z4DType(SCHAR) Z4DSChar;

typedef Z2DType(USHORT) Z2DUShort;
typedef Z3DType(USHORT) Z3DUShort;
typedef Z4DType(USHORT) Z4DUShort;

typedef Z2DType(SSHORT) Z2DSShort;
typedef Z3DType(SSHORT) Z3DSShort;
typedef Z4DType(SSHORT) Z4DSShort;

typedef Z2DType(UINT) Z2DUInt;
typedef Z3DType(UINT) Z3DUInt;
typedef Z4DType(UINT) Z4DUInt;

typedef Z2DType(SINT) Z2DSInt;
typedef Z3DType(SINT) Z3DSInt;
typedef Z4DType(SINT) Z4DSInt;

typedef Z2DType(ULONG) Z2DULong;
typedef Z3DType(ULONG) Z3DULong;
typedef Z4DType(ULONG) Z4DULong;

typedef Z2DType(SLONG) Z2DSLong;
typedef Z3DType(SLONG) Z3DSLong;
typedef Z4DType(SLONG) Z4DSLong;

#ifdef Z_ULLONG
	typedef Z2DType(ULLONG) Z2DULLong;
	typedef Z3DType(ULLONG) Z3DULLong;
	typedef Z4DType(ULLONG) Z4DULLong;
#endif

#ifdef Z_SLLONG
	typedef Z2DType(SLLONG) Z2DSLLong;
	typedef Z3DType(SLLONG) Z3DSLLong;
	typedef Z4DType(SLLONG) Z4DSLLong;
#endif

#ifdef Z_FLOAT
	typedef Z2DType(FLOAT) Z2DFloat;
	typedef Z3DType(FLOAT) Z3DFloat;
	typedef Z4DType(FLOAT) Z4DFloat;
#endif

#ifdef Z_DOUBLE
	typedef Z2DType(DOUBLE) Z2DDouble;
	typedef Z3DType(DOUBLE) Z3DDouble;
	typedef Z4DType(DOUBLE) Z4DDouble;
#endif

#ifdef Z_LDOUBLE
	typedef Z2DType(LDOUBLE) Z2DLDouble;
	typedef Z3DType(LDOUBLE) Z3DLDouble;
	typedef Z4DType(LDOUBLE) Z4DLDouble;
#endif

typedef Z2DType(USIZE) Z2DUSize;
typedef Z3DType(USIZE) Z3DUSize;
typedef Z4DType(USIZE) Z4DUSize;

typedef Z2DType(SSIZE) Z2DSSize;
typedef Z3DType(SSIZE) Z3DSSize;
typedef Z4DType(SSIZE) Z4DSSize;

typedef Z2DType(UINTMAX) Z2DUIntMax;
typedef Z3DType(UINTMAX) Z3DUIntMax;
typedef Z4DType(UINTMAX) Z4DUIntMax;

typedef Z2DType(SINTMAX) Z2DSIntMax;
typedef Z3DType(SINTMAX) Z3DSIntMax;
typedef Z4DType(SINTMAX) Z4DSIntMax;

typedef Z2DType(UINTPTR) Z2DUIntPtr;
typedef Z3DType(UINTPTR) Z3DUIntPtr;
typedef Z4DType(UINTPTR) Z4DUIntPtr;

typedef Z2DType(SINTPTR) Z2DSIntPtr;
typedef Z3DType(SINTPTR) Z3DSIntPtr;
typedef Z4DType(SINTPTR) Z4DSIntPtr;

typedef Z2DType(UINTTOP) Z2DUIntTop;
typedef Z3DType(UINTTOP) Z3DUIntTop;
typedef Z4DType(UINTTOP) Z4DUIntTop;

typedef Z2DType(SINTTOP) Z2DSIntTop;
typedef Z3DType(SINTTOP) Z3DSIntTop;
typedef Z4DType(SINTTOP) Z4DSIntTop;

typedef Z2DType(NATURAL) Z2DNatural;
typedef Z3DType(NATURAL) Z3DNatural;
typedef Z4DType(NATURAL) Z4DNatural;

typedef Z2DType(INTEGER) Z2DInteger;
typedef Z3DType(INTEGER) Z3DInteger;
typedef Z4DType(INTEGER) Z4DInteger;

#ifdef Z_REAL
	typedef Z2DType(REAL) Z2DReal;
	typedef Z3DType(REAL) Z3DReal;
	typedef Z4DType(REAL) Z4DReal;
	typedef Z2DReal	      Z2D;
	typedef Z3DReal	      Z3D;
	typedef Z4DReal	      Z4D;
#endif

#if Z_DIALECT_HAS(C, COMPOUND_LITERAL)

#	define z_2d_uint8(x, y)	      ((Z2DUInt8){x, y})
#	define z_3d_uint8(x, y, z)    ((Z3DUInt8){x, y, z})
#	define z_4d_uint8(x, y, z, w) ((Z4DUInt8){x, y, z, w})

#	define z_2d_sint8(x, y)	      ((Z2DSInt8){x, y})
#	define z_3d_sint8(x, y, z)    ((Z3DSInt8){x, y, z})
#	define z_4d_sint8(x, y, z, w) ((Z4DSInt8){x, y, z, w})

#	define z_2d_uint16(x, y)       ((Z2DUInt16){x, y})
#	define z_3d_uint16(x, y, z)    ((Z3DUInt16){x, y, z})
#	define z_4d_uint16(x, y, z, w) ((Z4DUInt16){x, y, z, w})

#	define z_2d_sint16(x, y)       ((Z2DSInt16){x, y})
#	define z_3d_sint16(x, y, z)    ((Z3DSInt16){x, y, z})
#	define z_4d_sint16(x, y, z, w) ((Z4DSInt16){x, y, z, w})

#	define z_2d_uint32(x, y)       ((Z2DUInt32){x, y})
#	define z_3d_uint32(x, y, z)    ((Z3DUInt32){x, y, z})
#	define z_4d_uint32(x, y, z, w) ((Z4DUInt32){x, y, z, w})

#	define z_2d_sint32(x, y)       ((Z2DSInt32){x, y})
#	define z_3d_sint32(x, y, z)    ((Z3DSInt32){x, y, z})
#	define z_4d_sint32(x, y, z, w) ((Z4DSInt32){x, y, z, w})

#	ifdef Z_UINT64
#		define z_2d_uint64(x, y)       ((Z2DUInt64){x, y})
#		define z_3d_uint64(x, y, z)    ((Z3DUInt64){x, y, z})
#		define z_4d_uint64(x, y, z, w) ((Z4DUInt64){x, y, z, w})
#	endif

#	ifdef Z_SINT64
#		define z_2d_sint64(x, y)       ((Z2DSInt64){x, y})
#		define z_3d_sint64(x, y, z)    ((Z3DSInt64){x, y, z})
#		define z_4d_sint64(x, y, z, w) ((Z4DSInt64){x, y, z, w})
#	endif

#	ifdef Z_UINT128
#		define z_2d_uint128(x, y)	((Z2DUInt128){x, y})
#		define z_3d_uint128(x, y, z)	((Z3DUInt128){x, y, z})
#		define z_4d_uint128(x, y, z, w) ((Z4DUInt128){x, y, z, w})
#	endif

#	ifdef Z_SINT128
#		define z_2d_sint128(x, y)	((Z2DSInt128){x, y})
#		define z_3d_sint128(x, y, z)	((Z3DSInt128){x, y, z})
#		define z_4d_sint128(x, y, z, w) ((Z4DSInt128){x, y, z, w})
#	endif

#	ifdef Z_FLOAT16
#		define z_2d_float16(x, y)	((Z2DFloat32){x, y})
#		define z_3d_float16(x, y, z)	((Z3DFloat32){x, y, z})
#		define z_4d_float16(x, y, z, w) ((Z4DFloat32){x, y, z, w})
#	endif

#	ifdef Z_FLOAT32
#		define z_2d_float32(x, y)	((Z2DFloat32){x, y})
#		define z_3d_float32(x, y, z)	((Z3DFloat32){x, y, z})
#		define z_4d_float32(x, y, z, w) ((Z4DFloat32){x, y, z, w})
#	endif

#	ifdef Z_FLOAT64
#		define z_2d_float64(x, y)	((Z2DFloat64){x, y})
#		define z_3d_float64(x, y, z)	((Z3DFloat64){x, y, z})
#		define z_4d_float64(x, y, z, w) ((Z4DFloat64){x, y, z, w})
#	endif

#	ifdef Z_FLOAT128
#		define z_2d_float128(x, y)	 ((Z2DFloat128){x, y})
#		define z_3d_float128(x, y, z)	 ((Z3DFloat128){x, y, z})
#		define z_4d_float128(x, y, z, w) ((Z4DFloat128){x, y, z, w})
#	endif

#	ifdef Z_FLOAT80_X87
#		define z_2d_float80_x87(x, y)	    ((Z2DFloat80_x87){x, y})
#		define z_3d_float80_x87(x, y, z)    ((Z3DFloat80_x87){x, y, z})
#		define z_4d_float80_x87(x, y, z, w) ((Z4DFloat80_x87){x, y, z, w})
#	endif

#	ifdef Z_FLOAT96_X87
#		define z_2d_float96_x87(x, y)	    ((Z2DFloat96_x87){x, y})
#		define z_3d_float96_x87(x, y, z)    ((Z3DFloat96_x87){x, y, z})
#		define z_4d_float96_x87(x, y, z, w) ((Z4DFloat96_x87){x, y, z, w})
#	endif

#	ifdef Z_FLOAT128_X87
#		define z_2d_float128_x87(x, y)	     ((Z2DFloat128_x87){x, y})
#		define z_3d_float128_x87(x, y, z)    ((Z3DFloat128_x87){x, y, z})
#		define z_4d_float128_x87(x, y, z, w) ((Z4DFloat128_x87){x, y, z, w})
#	endif

#else

#	define Z_CONSTRUCTORS(Type, type)				  \
									  \
	static Z_INLINE							  \
	Z2D##Type z_2d_##type(z##type x, z##type y)			  \
		{							  \
		Z2D##Type object;					  \
									  \
		object.x = x; object.y = y;				  \
		return object;						  \
		}							  \
									  \
									  \
	static Z_INLINE							  \
	Z3D##Type z_3d_##type(z##type x, z##type y, z##type z)		  \
		{							  \
		Z3D##Type object;					  \
									  \
		object.x = x; object.y = y; object.z = z;		  \
		return object;						  \
		}							  \
									  \
									  \
	static Z_INLINE							  \
	Z4D##Type z_4d_##type(z##type x, z##type y, z##type z, z##type w) \
		{							  \
		Z4D##Type object;					  \
									  \
		object.x = x; object.y = y; object.z = z; object.w = w;	  \
		return object;						  \
		}


	Z_CONSTRUCTORS(UInt8,  uint8 )
	Z_CONSTRUCTORS(SInt8,  sint8 )
	Z_CONSTRUCTORS(UInt16, uint16)
	Z_CONSTRUCTORS(SInt16, sint16)
	Z_CONSTRUCTORS(UInt32, uint32)
	Z_CONSTRUCTORS(SInt32, sint32)

#	ifdef Z_UINT64
		Z_CONSTRUCTORS(UInt64, uint64)
#	endif

#	ifdef Z_SINT64
		Z_CONSTRUCTORS(SInt64, sint64)
#	endif

#	ifdef Z_UINT128
		Z_CONSTRUCTORS(UInt128, uint128)
#	endif

#	ifdef Z_SINT128
		Z_CONSTRUCTORS(SInt128, sint128)
#	endif

#	ifdef Z_FLOAT16
		Z_CONSTRUCTORS(Float16, float16)
#	endif

#	ifdef Z_FLOAT32
		Z_CONSTRUCTORS(Float32, float32)
#	endif

#	ifdef Z_FLOAT64
		Z_CONSTRUCTORS(Float64, float64)
#	endif

#	ifdef Z_FLOAT128
		Z_CONSTRUCTORS(Float128, float128)
#	endif

#	ifdef Z_FLOAT80_X87
		Z_CONSTRUCTORS(Float80_x87, float80_x87)
#	endif

#	ifdef Z_FLOAT96_X87
		Z_CONSTRUCTORS(Float96_x87, float96_x87)
#	endif

#	ifdef Z_FLOAT128_X87
		Z_CONSTRUCTORS(Float128_x87, float128_x87)
#	endif

#	undef Z_CONSTRUCTORS

#endif

#define z_2d_uint8_0 z_2d_uint8(0, 0)
#define z_3d_uint8_0 z_3d_uint8(0, 0, 0)
#define z_4d_uint8_0 z_4d_uint8(0, 0, 0, 0)

#define z_2d_sint8_0 z_2d_sint8(0, 0)
#define z_3d_sint8_0 z_3d_sint8(0, 0, 0)
#define z_4d_sint8_0 z_4d_sint8(0, 0, 0, 0)

#define z_2d_uint16_0 z_2d_uint16(0, 0)
#define z_3d_uint16_0 z_3d_uint16(0, 0, 0)
#define z_4d_uint16_0 z_4d_uint16(0, 0, 0, 0)

#define z_2d_sint16_0 z_2d_sint16(0, 0)
#define z_3d_sint16_0 z_3d_sint16(0, 0, 0)
#define z_4d_sint16_0 z_4d_sint16(0, 0, 0, 0)

#define z_2d_uint32_0 z_2d_uint32(0, 0)
#define z_3d_uint32_0 z_3d_uint32(0, 0, 0)
#define z_4d_uint32_0 z_4d_uint32(0, 0, 0, 0)

#define z_2d_sint32_0 z_2d_sint32(0, 0)
#define z_3d_sint32_0 z_3d_sint32(0, 0, 0)
#define z_4d_sint32_0 z_4d_sint32(0, 0, 0, 0)

#ifdef Z_UINT64
#	define z_2d_uint64_0 z_2d_uint64(0, 0)
#	define z_3d_uint64_0 z_3d_uint64(0, 0, 0)
#	define z_4d_uint64_0 z_4d_uint64(0, 0, 0, 0)
#endif

#ifdef Z_SINT64
#	define z_2d_sint64_0 z_2d_sint64(0, 0)
#	define z_3d_sint64_0 z_3d_sint64(0, 0, 0)
#	define z_4d_sint64_0 z_4d_sint64(0, 0, 0, 0)
#endif

#ifdef Z_UINT128
#	define z_2d_uint128_0 z_2d_uint128(0, 0)
#	define z_3d_uint128_0 z_3d_uint128(0, 0, 0)
#	define z_4d_uint128_0 z_4d_uint128(0, 0, 0, 0)
#endif

#ifdef Z_SINT128
#	define z_2d_sint128_0 z_2d_sint128(0, 0)
#	define z_3d_sint128_0 z_3d_sint128(0, 0, 0)
#	define z_4d_sint128_0 z_4d_sint128(0, 0, 0, 0)
#endif

#ifdef Z_FLOAT16
#	define z_2d_float16_0 z_2d_float16(0.0, 0.0)
#	define z_3d_float16_0 z_3d_float16(0.0, 0.0, 0.0)
#	define z_4d_float16_0 z_4d_float16(0.0, 0.0, 0.0, 0.0)
#endif

#ifdef Z_FLOAT32
#	define z_2d_float32_0 z_2d_float32(0.0, 0.0)
#	define z_3d_float32_0 z_3d_float32(0.0, 0.0, 0.0)
#	define z_4d_float32_0 z_4d_float32(0.0, 0.0, 0.0, 0.0)
#endif

#ifdef Z_FLOAT64
#	define z_2d_float64_0 z_2d_float64(0.0, 0.0)
#	define z_3d_float64_0 z_3d_float64(0.0, 0.0, 0.0)
#	define z_4d_float64_0 z_4d_float64(0.0, 0.0, 0.0, 0.0)
#endif

#ifdef Z_FLOAT128
#	define z_2d_float128_0 z_2d_float128(0.0, 0.0)
#	define z_3d_float128_0 z_3d_float128(0.0, 0.0, 0.0)
#	define z_4d_float128_0 z_4d_float128(0.0, 0.0, 0.0, 0.0)
#endif

#ifdef Z_FLOAT80_X87
#	define z_2d_float80_x87_0 z_2d_float80_x87(0.0, 0.0)
#	define z_3d_float80_x87_0 z_3d_float80_x87(0.0, 0.0, 0.0)
#	define z_4d_float80_x87_0 z_4d_float80_x87(0.0, 0.0, 0.0, 0.0)
#endif

#ifdef Z_FLOAT96_X87
#	define z_2d_float96_x87_0 z_2d_float96_x87(0.0, 0.0)
#	define z_3d_float96_x87_0 z_3d_float96_x87(0.0, 0.0, 0.0)
#	define z_4d_float96_x87_0 z_4d_float96_x87(0.0, 0.0, 0.0, 0.0)
#endif

#ifdef Z_FLOAT128_X87
#	define z_2d_float128_x87_0 z_2d_float128_x87(0.0, 0.0)
#	define z_3d_float128_x87_0 z_3d_float128_x87(0.0, 0.0, 0.0)
#	define z_4d_float128_x87_0 z_4d_float128_x87(0.0, 0.0, 0.0, 0.0)
#endif

#define z_2d_type(  TYPE) Z_APPEND_##TYPE##_fixed_type(z_2d_	)
#define z_2d_type_0(TYPE) Z_INSERT_##TYPE##_fixed_type(z_2d_, _0)
#define z_3d_type(  TYPE) Z_APPEND_##TYPE##_fixed_type(z_3d_	)
#define z_3d_type_0(TYPE) Z_INSERT_##TYPE##_fixed_type(z_3d_, _0)
#define z_4d_type(  TYPE) Z_APPEND_##TYPE##_fixed_type(z_4d_	)
#define z_4d_type_0(TYPE) Z_INSERT_##TYPE##_fixed_type(z_4d_, _0)

#ifdef Z_REAL
#	define z_2d   z_2d_type	 (REAL)
#	define z_2d_0 z_2d_type_0(REAL)
#	define z_3d   z_3d_type	 (REAL)
#	define z_3d_0 z_3d_type_0(REAL)
#	define z_4d   z_4d_type	 (REAL)
#	define z_4d_0 z_4d_type_0(REAL)
#endif

#endif /* Z_types_dimensional_H_ */
