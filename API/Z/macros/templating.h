/* Z Kit - macros/templating.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_macros_templating_H_
#define _Z_macros_templating_H_

#define Z_APPEND_UINT8(to)		   to##UINT8
#define Z_APPEND_UInt8(to)		   to##UInt8
#define Z_APPEND_uint8(to)		   to##uint8
#define Z_INSERT_UINT8(left, right)	   left##UINT8##right
#define Z_INSERT_UInt8(left, right)	   left##UInt8##right
#define Z_INSERT_uint8(left, right)	   left##uint8##right

#define Z_APPEND_SINT8(to)		   to##SINT8
#define Z_APPEND_SInt8(to)		   to##SInt8
#define Z_APPEND_sint8(to)		   to##sint8
#define Z_INSERT_SINT8(left, right)	   left##SINT8##right
#define Z_INSERT_SInt8(left, right)	   left##SInt8##right
#define Z_INSERT_sint8(left, right)	   left##sint8##right

#define Z_APPEND_UINT16(to)		   to##UINT16
#define Z_APPEND_UInt16(to)		   to##UInt16
#define Z_APPEND_uint16(to)		   to##uint16
#define Z_INSERT_UINT16(left, right)	   left##UINT16##right
#define Z_INSERT_UInt16(left, right)	   left##UInt16##right
#define Z_INSERT_uint16(left, right)	   left##uint16##right

#define Z_APPEND_SINT16(to)		   to##SINT16
#define Z_APPEND_SInt16(to)		   to##SInt16
#define Z_APPEND_sint16(to)		   to##sint16
#define Z_INSERT_SINT16(left, right)	   left##SINT16##right
#define Z_INSERT_SInt16(left, right)	   left##SInt16##right
#define Z_INSERT_sint16(left, right)	   left##sint16##right

#define Z_APPEND_UINT32(to)		   to##UINT32
#define Z_APPEND_UInt32(to)		   to##UInt32
#define Z_APPEND_uint32(to)		   to##uint32
#define Z_INSERT_UINT32(left, right)	   left##UINT32##right
#define Z_INSERT_UInt32(left, right)	   left##UInt32##right
#define Z_INSERT_uint32(left, right)	   left##uint32##right

#define Z_APPEND_SINT32(to)		   to##SINT32
#define Z_APPEND_SInt32(to)		   to##SInt32
#define Z_APPEND_sint32(to)		   to##sint32
#define Z_INSERT_SINT32(left, right)	   left##SINT32##right
#define Z_INSERT_SInt32(left, right)	   left##SInt32##right
#define Z_INSERT_sint32(left, right)	   left##sint32##right

#define Z_APPEND_UINT64(to)		   to##UINT64
#define Z_APPEND_UInt64(to)		   to##UInt64
#define Z_APPEND_uint64(to)		   to##uint64
#define Z_INSERT_UINT64(left, right)	   left##UINT64##right
#define Z_INSERT_UInt64(left, right)	   left##UInt64##right
#define Z_INSERT_uint64(left, right)	   left##uint64##right

#define Z_APPEND_SINT64(to)		   to##SINT64
#define Z_APPEND_SInt64(to)		   to##SInt64
#define Z_APPEND_sint64(to)		   to##sint64
#define Z_INSERT_SINT64(left, right)	   left##SINT64##right
#define Z_INSERT_SInt64(left, right)	   left##SInt64##right
#define Z_INSERT_sint64(left, right)	   left##sint64##right

#define Z_APPEND_UINT128(to)		   to##UINT128
#define Z_APPEND_UInt128(to)		   to##UInt128
#define Z_APPEND_uint128(to)		   to##uint128
#define Z_INSERT_UINT128(left, right)	   left##UINT128##right
#define Z_INSERT_UInt128(left, right)	   left##UInt128##right
#define Z_INSERT_uint128(left, right)	   left##uint128##right

#define Z_APPEND_SINT128(to)		   to##SINT128
#define Z_APPEND_SInt128(to)		   to##SInt128
#define Z_APPEND_sint128(to)		   to##sint128
#define Z_INSERT_SINT128(left, right)	   left##SINT128##right
#define Z_INSERT_SInt128(left, right)	   left##SInt128##right
#define Z_INSERT_sint128(left, right)	   left##sint128##right

#define Z_APPEND_FLOAT16(to)		   to##FLOAT16
#define Z_APPEND_Float16(to)		   to##Float16
#define Z_APPEND_float16(to)		   to##float16
#define Z_INSERT_FLOAT16(left, right)	   left##FLOAT16##right
#define Z_INSERT_Float16(left, right)	   left##Float16##right
#define Z_INSERT_float16(left, right)	   left##float16##right

#define Z_APPEND_FIXED_TYPE_192		   Z_APPEND_FLOAT16
#define Z_APPEND_FixedType_192		   Z_APPEND_Float16
#define Z_APPEND_fixed_type_192		   Z_APPEND_float16
#define Z_INSERT_FIXED_TYPE_192		   Z_INSERT_FLOAT16
#define Z_INSERT_FixedType_192		   Z_INSERT_Float16
#define Z_INSERT_fixed_type_192		   Z_INSERT_float16

#define Z_APPEND_FLOAT32(to)		   to##FLOAT32
#define Z_APPEND_Float32(to)		   to##Float32
#define Z_APPEND_float32(to)		   to##float32
#define Z_INSERT_FLOAT32(left, right)	   left##FLOAT32##right
#define Z_INSERT_Float32(left, right)	   left##Float32##right
#define Z_INSERT_float32(left, right)	   left##float32##right

#define Z_APPEND_FIXED_TYPE_193		   Z_APPEND_FLOAT32
#define Z_APPEND_FixedType_193		   Z_APPEND_Float32
#define Z_APPEND_fixed_type_193		   Z_APPEND_float32
#define Z_INSERT_FIXED_TYPE_193		   Z_INSERT_FLOAT32
#define Z_INSERT_FixedType_193		   Z_INSERT_Float32
#define Z_INSERT_fixed_type_193		   Z_INSERT_float32

#define Z_APPEND_FLOAT64(to)		   to##FLOAT64
#define Z_APPEND_Float64(to)		   to##Float64
#define Z_APPEND_float64(to)		   to##float64
#define Z_INSERT_FLOAT64(left, right)	   left##FLOAT64##right
#define Z_INSERT_Float64(left, right)	   left##Float64##right
#define Z_INSERT_float64(left, right)	   left##float64##right

#define Z_APPEND_FIXED_TYPE_194		   Z_APPEND_FLOAT64
#define Z_APPEND_FixedType_194		   Z_APPEND_Float64
#define Z_APPEND_fixed_type_194		   Z_APPEND_float64
#define Z_INSERT_FIXED_TYPE_194		   Z_INSERT_FLOAT64
#define Z_INSERT_FixedType_194		   Z_INSERT_Float64
#define Z_INSERT_fixed_type_194		   Z_INSERT_float64

#define Z_APPEND_FLOAT128(to)		   to##FLOAT128
#define Z_APPEND_Float128(to)		   to##Float128
#define Z_APPEND_float128(to)		   to##float128
#define Z_INSERT_FLOAT128(left, right)	   left##FLOAT128##right
#define Z_INSERT_Float128(left, right)	   left##Float128##right
#define Z_INSERT_float128(left, right)	   left##float128##right

#define Z_APPEND_FIXED_TYPE_195		   Z_APPEND_FLOAT128
#define Z_APPEND_FixedType_195		   Z_APPEND_Float128
#define Z_APPEND_fixed_type_195		   Z_APPEND_float128
#define Z_INSERT_FIXED_TYPE_195		   Z_INSERT_FLOAT128
#define Z_INSERT_FixedType_195		   Z_INSERT_Float128
#define Z_INSERT_fixed_type_195		   Z_INSERT_float128

#define Z_APPEND_FLOAT80_X87(to)	   to##FLOAT80_X87
#define Z_APPEND_Float80_x87(to)	   to##Float80_x87
#define Z_APPEND_float80_x87(to)	   to##float80_x87
#define Z_INSERT_FLOAT80_X87(left, right)  left##FLOAT80_X87##right
#define Z_INSERT_Float80_x87(left, right)  left##Float80_x87##right
#define Z_INSERT_float80_x87(left, right)  left##float80_x87##right

#define Z_APPEND_FIXED_TYPE_196		   Z_APPEND_FLOAT80_X87
#define Z_APPEND_FixedType_196		   Z_APPEND_Float80_x87
#define Z_APPEND_fixed_type_196		   Z_APPEND_float80_x87
#define Z_INSERT_FIXED_TYPE_196		   Z_INSERT_FLOAT80_X87
#define Z_INSERT_FixedType_196		   Z_INSERT_Float80_x87
#define Z_INSERT_fixed_type_196		   Z_INSERT_float80_x87

#define Z_APPEND_FLOAT96_X87(to)	   to##FLOAT96_X87
#define Z_APPEND_Float96_x87(to)	   to##Float96_x87
#define Z_APPEND_float96_x87(to)	   to##float96_x87
#define Z_INSERT_FLOAT96_X87(left, right)  left##FLOAT96_X87##right
#define Z_INSERT_Float96_x87(left, right)  left##Float96_x87##right
#define Z_INSERT_float96_x87(left, right)  left##float96_x87##right

#define Z_APPEND_FIXED_TYPE_197		   Z_APPEND_FLOAT96_X87
#define Z_APPEND_FixedType_197		   Z_APPEND_Float96_x87
#define Z_APPEND_fixed_type_197		   Z_APPEND_float96_x87
#define Z_INSERT_FIXED_TYPE_197		   Z_INSERT_FLOAT96_X87
#define Z_INSERT_FixedType_197		   Z_INSERT_Float96_x87
#define Z_INSERT_fixed_type_197		   Z_INSERT_float96_x87

#define Z_APPEND_FLOAT128_X87(to)	   to##FLOAT128_X87
#define Z_APPEND_Float128_x87(to)	   to##Float128_x87
#define Z_APPEND_float128_x87(to)	   to##float128_x87
#define Z_INSERT_FLOAT128_X87(left, right) left##FLOAT128_X87##right
#define Z_INSERT_Float128_x87(left, right) left##Float128_x87##right
#define Z_INSERT_float128_x87(left, right) left##float128_x87##right

#define Z_APPEND_FIXED_TYPE_198		   Z_APPEND_FLOAT128_X87
#define Z_APPEND_FixedType_198		   Z_APPEND_Float128_x87
#define Z_APPEND_fixed_type_198		   Z_APPEND_float128_x87
#define Z_INSERT_FIXED_TYPE_198		   Z_INSERT_FLOAT128_X87
#define Z_INSERT_FixedType_198		   Z_INSERT_Float128_x87
#define Z_INSERT_fixed_type_198		   Z_INSERT_float128_x87

#if ('\0' - 1) > 0
#	define Z_APPEND_CHAR_BITS	Z_JOIN_2(Z_APPEND_NUMBER_, Z_UCHAR_BITS)
#	define Z_APPEND_CHAR_FIXED_TYPE Z_JOIN_2(Z_APPEND_UINT,	   Z_UCHAR_BITS)
#	define Z_APPEND_CHAR_FixedType	Z_JOIN_2(Z_APPEND_UInt,	   Z_UCHAR_BITS)
#	define Z_APPEND_CHAR_fixed_type Z_JOIN_2(Z_APPEND_uint,	   Z_UCHAR_BITS)
#	define Z_INSERT_CHAR_BITS	Z_JOIN_2(Z_INSERT_NUMBER_, Z_UCHAR_BITS)
#	define Z_INSERT_CHAR_FIXED_TYPE Z_JOIN_2(Z_INSERT_UINT,	   Z_UCHAR_BITS)
#	define Z_INSERT_CHAR_FixedType	Z_JOIN_2(Z_INSERT_UInt,	   Z_UCHAR_BITS)
#	define Z_INSERT_CHAR_fixed_type Z_JOIN_2(Z_INSERT_uint,	   Z_UCHAR_BITS)
#else
#	define Z_APPEND_CHAR_BITS	Z_JOIN_2(Z_APPEND_NUMBER_, Z_SCHAR_BITS)
#	define Z_APPEND_CHAR_FIXED_TYPE Z_JOIN_2(Z_APPEND_SINT,	   Z_SCHAR_BITS)
#	define Z_APPEND_CHAR_FixedType	Z_JOIN_2(Z_APPEND_SInt,	   Z_SCHAR_BITS)
#	define Z_APPEND_CHAR_fixed_type Z_JOIN_2(Z_APPEND_sint,	   Z_SCHAR_BITS)
#	define Z_INSERT_CHAR_BITS	Z_JOIN_2(Z_INSERT_NUMBER_, Z_SCHAR_BITS)
#	define Z_INSERT_CHAR_FIXED_TYPE Z_JOIN_2(Z_INSERT_SINT,	   Z_SCHAR_BITS)
#	define Z_INSERT_CHAR_FixedType	Z_JOIN_2(Z_INSERT_SInt,	   Z_SCHAR_BITS)
#	define Z_INSERT_CHAR_fixed_type Z_JOIN_2(Z_INSERT_sint,	   Z_SCHAR_BITS)
#endif

#define Z_APPEND_UCHAR_BITS	    Z_JOIN_2(Z_APPEND_NUMBER_, Z_UCHAR_BITS)
#define Z_APPEND_UCHAR_FIXED_TYPE   Z_JOIN_2(Z_APPEND_UINT,    Z_UCHAR_BITS)
#define Z_APPEND_UCHAR_FixedType    Z_JOIN_2(Z_APPEND_UInt,    Z_UCHAR_BITS)
#define Z_APPEND_UCHAR_fixed_type   Z_JOIN_2(Z_APPEND_uint,    Z_UCHAR_BITS)
#define Z_INSERT_UCHAR_BITS	    Z_JOIN_2(Z_INSERT_NUMBER_, Z_UCHAR_BITS)
#define Z_INSERT_UCHAR_FIXED_TYPE   Z_JOIN_2(Z_INSERT_UINT,    Z_UCHAR_BITS)
#define Z_INSERT_UCHAR_FixedType    Z_JOIN_2(Z_INSERT_UInt,    Z_UCHAR_BITS)
#define Z_INSERT_UCHAR_fixed_type   Z_JOIN_2(Z_INSERT_uint,    Z_UCHAR_BITS)

#define Z_APPEND_SCHAR_BITS	    Z_JOIN_2(Z_APPEND_NUMBER_, Z_SCHAR_BITS)
#define Z_APPEND_SCHAR_FIXED_TYPE   Z_JOIN_2(Z_APPEND_SINT,    Z_SCHAR_BITS)
#define Z_APPEND_SCHAR_FixedType    Z_JOIN_2(Z_APPEND_SInt,    Z_SCHAR_BITS)
#define Z_APPEND_SCHAR_fixed_type   Z_JOIN_2(Z_APPEND_sint,    Z_SCHAR_BITS)
#define Z_INSERT_SCHAR_BITS	    Z_JOIN_2(Z_INSERT_NUMBER_, Z_SCHAR_BITS)
#define Z_INSERT_SCHAR_FIXED_TYPE   Z_JOIN_2(Z_INSERT_SINT,    Z_SCHAR_BITS)
#define Z_INSERT_SCHAR_FixedType    Z_JOIN_2(Z_INSERT_SInt,    Z_SCHAR_BITS)
#define Z_INSERT_SCHAR_fixed_type   Z_JOIN_2(Z_INSERT_sint,    Z_SCHAR_BITS)

#define Z_APPEND_USHORT_BITS	    Z_JOIN_2(Z_APPEND_NUMBER_, Z_USHORT_BITS)
#define Z_APPEND_USHORT_FIXED_TYPE  Z_JOIN_2(Z_APPEND_UINT,    Z_USHORT_BITS)
#define Z_APPEND_USHORT_FixedType   Z_JOIN_2(Z_APPEND_UInt,    Z_USHORT_BITS)
#define Z_APPEND_USHORT_fixed_type  Z_JOIN_2(Z_APPEND_uint,    Z_USHORT_BITS)
#define Z_INSERT_USHORT_BITS	    Z_JOIN_2(Z_INSERT_NUMBER_, Z_USHORT_BITS)
#define Z_INSERT_USHORT_FIXED_TYPE  Z_JOIN_2(Z_INSERT_UINT,    Z_USHORT_BITS)
#define Z_INSERT_USHORT_FixedType   Z_JOIN_2(Z_INSERT_UInt,    Z_USHORT_BITS)
#define Z_INSERT_USHORT_fixed_type  Z_JOIN_2(Z_INSERT_uint,    Z_USHORT_BITS)

#define Z_APPEND_SSHORT_BITS	    Z_JOIN_2(Z_APPEND_NUMBER_, Z_SSHORT_BITS)
#define Z_APPEND_SSHORT_FIXED_TYPE  Z_JOIN_2(Z_APPEND_SINT,    Z_SSHORT_BITS)
#define Z_APPEND_SSHORT_FixedType   Z_JOIN_2(Z_APPEND_SInt,    Z_SSHORT_BITS)
#define Z_APPEND_SSHORT_fixed_type  Z_JOIN_2(Z_APPEND_sint,    Z_SSHORT_BITS)
#define Z_INSERT_SSHORT_BITS	    Z_JOIN_2(Z_INSERT_NUMBER_, Z_SSHORT_BITS)
#define Z_INSERT_SSHORT_FIXED_TYPE  Z_JOIN_2(Z_INSERT_SINT,    Z_SSHORT_BITS)
#define Z_INSERT_SSHORT_FixedType   Z_JOIN_2(Z_INSERT_SInt,    Z_SSHORT_BITS)
#define Z_INSERT_SSHORT_fixed_type  Z_JOIN_2(Z_INSERT_sint,    Z_SSHORT_BITS)

#define Z_APPEND_UINT_BITS	    Z_JOIN_2(Z_APPEND_NUMBER_, Z_UINT_BITS)
#define Z_APPEND_UINT_FIXED_TYPE    Z_JOIN_2(Z_APPEND_UINT,    Z_UINT_BITS)
#define Z_APPEND_UINT_FixedType	    Z_JOIN_2(Z_APPEND_UInt,    Z_UINT_BITS)
#define Z_APPEND_UINT_fixed_type    Z_JOIN_2(Z_APPEND_uint,    Z_UINT_BITS)
#define Z_INSERT_UINT_BITS	    Z_JOIN_2(Z_INSERT_NUMBER_, Z_UINT_BITS)
#define Z_INSERT_UINT_FIXED_TYPE    Z_JOIN_2(Z_INSERT_UINT,    Z_UINT_BITS)
#define Z_INSERT_UINT_FixedType	    Z_JOIN_2(Z_INSERT_UInt,    Z_UINT_BITS)
#define Z_INSERT_UINT_fixed_type    Z_JOIN_2(Z_INSERT_uint,    Z_UINT_BITS)

#define Z_APPEND_SINT_BITS	    Z_JOIN_2(Z_APPEND_NUMBER_, Z_SINT_BITS)
#define Z_APPEND_SINT_FIXED_TYPE    Z_JOIN_2(Z_APPEND_SINT,    Z_SINT_BITS)
#define Z_APPEND_SINT_FixedType	    Z_JOIN_2(Z_APPEND_SInt,    Z_SINT_BITS)
#define Z_APPEND_SINT_fixed_type    Z_JOIN_2(Z_APPEND_sint,    Z_SINT_BITS)
#define Z_INSERT_SINT_BITS	    Z_JOIN_2(Z_INSERT_NUMBER_, Z_SINT_BITS)
#define Z_INSERT_SINT_FIXED_TYPE    Z_JOIN_2(Z_INSERT_SINT,    Z_SINT_BITS)
#define Z_INSERT_SINT_FixedType	    Z_JOIN_2(Z_INSERT_SInt,    Z_SINT_BITS)
#define Z_INSERT_SINT_fixed_type    Z_JOIN_2(Z_INSERT_sint,    Z_SINT_BITS)

#define Z_APPEND_ULONG_BITS	    Z_JOIN_2(Z_APPEND_NUMBER_, Z_ULONG_BITS)
#define Z_APPEND_ULONG_FIXED_TYPE   Z_JOIN_2(Z_APPEND_UINT,    Z_ULONG_BITS)
#define Z_APPEND_ULONG_FixedType    Z_JOIN_2(Z_APPEND_UInt,    Z_ULONG_BITS)
#define Z_APPEND_ULONG_fixed_type   Z_JOIN_2(Z_APPEND_uint,    Z_ULONG_BITS)
#define Z_INSERT_ULONG_BITS	    Z_JOIN_2(Z_INSERT_NUMBER_, Z_ULONG_BITS)
#define Z_INSERT_ULONG_FIXED_TYPE   Z_JOIN_2(Z_INSERT_UINT,    Z_ULONG_BITS)
#define Z_INSERT_ULONG_FixedType    Z_JOIN_2(Z_INSERT_UInt,    Z_ULONG_BITS)
#define Z_INSERT_ULONG_fixed_type   Z_JOIN_2(Z_INSERT_uint,    Z_ULONG_BITS)

#define Z_APPEND_SLONG_BITS	    Z_JOIN_2(Z_APPEND_NUMBER_, Z_SLONG_BITS)
#define Z_APPEND_SLONG_FIXED_TYPE   Z_JOIN_2(Z_APPEND_SINT,    Z_SLONG_BITS)
#define Z_APPEND_SLONG_FixedType    Z_JOIN_2(Z_APPEND_SInt,    Z_SLONG_BITS)
#define Z_APPEND_SLONG_fixed_type   Z_JOIN_2(Z_APPEND_sint,    Z_SLONG_BITS)
#define Z_INSERT_SLONG_BITS	    Z_JOIN_2(Z_INSERT_NUMBER_, Z_SLONG_BITS)
#define Z_INSERT_SLONG_FIXED_TYPE   Z_JOIN_2(Z_INSERT_SINT,    Z_SLONG_BITS)
#define Z_INSERT_SLONG_FixedType    Z_JOIN_2(Z_INSERT_SInt,    Z_SLONG_BITS)
#define Z_INSERT_SLONG_fixed_type   Z_JOIN_2(Z_INSERT_sint,    Z_SLONG_BITS)

#define Z_APPEND_ULLONG_BITS	    Z_JOIN_2(Z_APPEND_NUMBER_, Z_ULLONG_BITS)
#define Z_APPEND_ULLONG_FIXED_TYPE  Z_JOIN_2(Z_APPEND_UINT,    Z_ULLONG_BITS)
#define Z_APPEND_ULLONG_FixedType   Z_JOIN_2(Z_APPEND_UInt,    Z_ULLONG_BITS)
#define Z_APPEND_ULLONG_fixed_type  Z_JOIN_2(Z_APPEND_uint,    Z_ULLONG_BITS)
#define Z_INSERT_ULLONG_BITS	    Z_JOIN_2(Z_INSERT_NUMBER_, Z_ULLONG_BITS)
#define Z_INSERT_ULLONG_FIXED_TYPE  Z_JOIN_2(Z_INSERT_UINT,    Z_ULLONG_BITS)
#define Z_INSERT_ULLONG_FixedType   Z_JOIN_2(Z_INSERT_UInt,    Z_ULLONG_BITS)
#define Z_INSERT_ULLONG_fixed_type  Z_JOIN_2(Z_INSERT_uint,    Z_ULLONG_BITS)

#define Z_APPEND_SLLONG_BITS	    Z_JOIN_2(Z_APPEND_NUMBER_, Z_SLLONG_BITS)
#define Z_APPEND_SLLONG_FIXED_TYPE  Z_JOIN_2(Z_APPEND_SINT,    Z_SLLONG_BITS)
#define Z_APPEND_SLLONG_FixedType   Z_JOIN_2(Z_APPEND_SInt,    Z_SLLONG_BITS)
#define Z_APPEND_SLLONG_fixed_type  Z_JOIN_2(Z_APPEND_sint,    Z_SLLONG_BITS)
#define Z_INSERT_SLLONG_BITS	    Z_JOIN_2(Z_INSERT_NUMBER_, Z_SLLONG_BITS)
#define Z_INSERT_SLLONG_FIXED_TYPE  Z_JOIN_2(Z_INSERT_SINT,    Z_SLLONG_BITS)
#define Z_INSERT_SLLONG_FixedType   Z_JOIN_2(Z_INSERT_SInt,    Z_SLLONG_BITS)
#define Z_INSERT_SLLONG_fixed_type  Z_JOIN_2(Z_INSERT_sint,    Z_SLLONG_BITS)

#define Z_APPEND_FLOAT_FIXED_TYPE   Z_JOIN_2(Z_APPEND_FIXED_TYPE_, Z_FLOAT_FIXED_VALUE_TYPE)
#define Z_APPEND_FLOAT_FixedType    Z_JOIN_2(Z_APPEND_FixedType_,  Z_FLOAT_FIXED_VALUE_TYPE)
#define Z_APPEND_FLOAT_fixed_type   Z_JOIN_2(Z_APPEND_fixed_type_, Z_FLOAT_FIXED_VALUE_TYPE)
#define Z_INSERT_FLOAT_FIXED_TYPE   Z_JOIN_2(Z_INSERT_FIXED_TYPE_, Z_FLOAT_FIXED_VALUE_TYPE)
#define Z_INSERT_FLOAT_FixedType    Z_JOIN_2(Z_INSERT_FixedType_,  Z_FLOAT_FIXED_VALUE_TYPE)
#define Z_INSERT_FLOAT_fixed_type   Z_JOIN_2(Z_INSERT_fixed_type_, Z_FLOAT_FIXED_VALUE_TYPE)

#define Z_APPEND_DOUBLE_FIXED_TYPE  Z_JOIN_2(Z_APPEND_FIXED_TYPE_, Z_DOUBLE_FIXED_VALUE_TYPE)
#define Z_APPEND_DOUBLE_FixedType   Z_JOIN_2(Z_APPEND_FixedType_,  Z_DOUBLE_FIXED_VALUE_TYPE)
#define Z_APPEND_DOUBLE_fixed_type  Z_JOIN_2(Z_APPEND_fixed_type_, Z_DOUBLE_FIXED_VALUE_TYPE)
#define Z_INSERT_DOUBLE_FIXED_TYPE  Z_JOIN_2(Z_INSERT_FIXED_TYPE_, Z_DOUBLE_FIXED_VALUE_TYPE)
#define Z_INSERT_DOUBLE_FixedType   Z_JOIN_2(Z_INSERT_FixedType_,  Z_DOUBLE_FIXED_VALUE_TYPE)
#define Z_INSERT_DOUBLE_fixed_type  Z_JOIN_2(Z_INSERT_fixed_type_, Z_DOUBLE_FIXED_VALUE_TYPE)

#define Z_APPEND_LDOUBLE_FIXED_TYPE Z_JOIN_2(Z_APPEND_FIXED_TYPE_, Z_LDOUBLE_FIXED_VALUE_TYPE)
#define Z_APPEND_LDOUBLE_FixedType  Z_JOIN_2(Z_APPEND_FixedType_,  Z_LDOUBLE_FIXED_VALUE_TYPE)
#define Z_APPEND_LDOUBLE_fixed_type Z_JOIN_2(Z_APPEND_fixed_type_, Z_LDOUBLE_FIXED_VALUE_TYPE)
#define Z_INSERT_LDOUBLE_FIXED_TYPE Z_JOIN_2(Z_INSERT_FIXED_TYPE_, Z_LDOUBLE_FIXED_VALUE_TYPE)
#define Z_INSERT_LDOUBLE_FixedType  Z_JOIN_2(Z_INSERT_FixedType_,  Z_LDOUBLE_FIXED_VALUE_TYPE)
#define Z_INSERT_LDOUBLE_fixed_type Z_JOIN_2(Z_INSERT_fixed_type_, Z_LDOUBLE_FIXED_VALUE_TYPE)

#define Z_APPEND_USIZE_BITS	    Z_JOIN_2(Z_APPEND_NUMBER_, Z_USIZE_BITS)
#define Z_APPEND_USIZE_FIXED_TYPE   Z_JOIN_2(Z_APPEND_UINT,    Z_USIZE_BITS)
#define Z_APPEND_USIZE_FixedType    Z_JOIN_2(Z_APPEND_UInt,    Z_USIZE_BITS)
#define Z_APPEND_USIZE_fixed_type   Z_JOIN_2(Z_APPEND_uint,    Z_USIZE_BITS)
#define Z_INSERT_USIZE_BITS	    Z_JOIN_2(Z_INSERT_NUMBER_, Z_USIZE_BITS)
#define Z_INSERT_USIZE_FIXED_TYPE   Z_JOIN_2(Z_INSERT_UINT,    Z_USIZE_BITS)
#define Z_INSERT_USIZE_FixedType    Z_JOIN_2(Z_INSERT_UInt,    Z_USIZE_BITS)
#define Z_INSERT_USIZE_fixed_type   Z_JOIN_2(Z_INSERT_uint,    Z_USIZE_BITS)

#define Z_APPEND_SSIZE_BITS	    Z_JOIN_2(Z_APPEND_NUMBER_, Z_SSIZE_BITS)
#define Z_APPEND_SSIZE_FIXED_TYPE   Z_JOIN_2(Z_APPEND_SINT,    Z_SSIZE_BITS)
#define Z_APPEND_SSIZE_FixedType    Z_JOIN_2(Z_APPEND_SInt,    Z_SSIZE_BITS)
#define Z_APPEND_SSIZE_fixed_type   Z_JOIN_2(Z_APPEND_sint,    Z_SSIZE_BITS)
#define Z_INSERT_SSIZE_BITS	    Z_JOIN_2(Z_INSERT_NUMBER_, Z_SSIZE_BITS)
#define Z_INSERT_SSIZE_FIXED_TYPE   Z_JOIN_2(Z_INSERT_SINT,    Z_SSIZE_BITS)
#define Z_INSERT_SSIZE_FixedType    Z_JOIN_2(Z_INSERT_SInt,    Z_SSIZE_BITS)
#define Z_INSERT_SSIZE_fixed_type   Z_JOIN_2(Z_INSERT_sint,    Z_SSIZE_BITS)

#define Z_APPEND_UINTMAX_BITS	    Z_JOIN_2(Z_APPEND_NUMBER_, Z_UINTMAX_BITS)
#define Z_APPEND_UINTMAX_FIXED_TYPE Z_JOIN_2(Z_APPEND_UINT,    Z_UINTMAX_BITS)
#define Z_APPEND_UINTMAX_FixedType  Z_JOIN_2(Z_APPEND_UInt,    Z_UINTMAX_BITS)
#define Z_APPEND_UINTMAX_fixed_type Z_JOIN_2(Z_APPEND_uint,    Z_UINTMAX_BITS)
#define Z_INSERT_UINTMAX_BITS	    Z_JOIN_2(Z_INSERT_NUMBER_, Z_UINTMAX_BITS)
#define Z_INSERT_UINTMAX_FIXED_TYPE Z_JOIN_2(Z_INSERT_UINT,    Z_UINTMAX_BITS)
#define Z_INSERT_UINTMAX_FixedType  Z_JOIN_2(Z_INSERT_UInt,    Z_UINTMAX_BITS)
#define Z_INSERT_UINTMAX_fixed_type Z_JOIN_2(Z_INSERT_uint,    Z_UINTMAX_BITS)

#define Z_APPEND_SINTMAX_BITS	    Z_JOIN_2(Z_APPEND_NUMBER_, Z_SINTMAX_BITS)
#define Z_APPEND_SINTMAX_FIXED_TYPE Z_JOIN_2(Z_APPEND_SINT,    Z_SINTMAX_BITS)
#define Z_APPEND_SINTMAX_FixedType  Z_JOIN_2(Z_APPEND_SInt,    Z_SINTMAX_BITS)
#define Z_APPEND_SINTMAX_fixed_type Z_JOIN_2(Z_APPEND_sint,    Z_SINTMAX_BITS)
#define Z_INSERT_SINTMAX_BITS	    Z_JOIN_2(Z_INSERT_NUMBER_, Z_SINTMAX_BITS)
#define Z_INSERT_SINTMAX_FIXED_TYPE Z_JOIN_2(Z_INSERT_SINT,    Z_SINTMAX_BITS)
#define Z_INSERT_SINTMAX_FixedType  Z_JOIN_2(Z_INSERT_SInt,    Z_SINTMAX_BITS)
#define Z_INSERT_SINTMAX_fixed_type Z_JOIN_2(Z_INSERT_sint,    Z_SINTMAX_BITS)

#define Z_APPEND_UINTPTR_BITS	    Z_JOIN_2(Z_APPEND_NUMBER_, Z_UINTPTR_BITS)
#define Z_APPEND_UINTPTR_FIXED_TYPE Z_JOIN_2(Z_APPEND_UINT,    Z_UINTPTR_BITS)
#define Z_APPEND_UINTPTR_FixedType  Z_JOIN_2(Z_APPEND_UInt,    Z_UINTPTR_BITS)
#define Z_APPEND_UINTPTR_fixed_type Z_JOIN_2(Z_APPEND_uint,    Z_UINTPTR_BITS)
#define Z_INSERT_UINTPTR_BITS	    Z_JOIN_2(Z_INSERT_NUMBER_, Z_UINTPTR_BITS)
#define Z_INSERT_UINTPTR_FIXED_TYPE Z_JOIN_2(Z_INSERT_UINT,    Z_UINTPTR_BITS)
#define Z_INSERT_UINTPTR_FixedType  Z_JOIN_2(Z_INSERT_UInt,    Z_UINTPTR_BITS)
#define Z_INSERT_UINTPTR_fixed_type Z_JOIN_2(Z_INSERT_uint,    Z_UINTPTR_BITS)

#define Z_APPEND_SINTPTR_BITS	    Z_JOIN_2(Z_APPEND_NUMBER_, Z_SINTPTR_BITS)
#define Z_APPEND_SINTPTR_FIXED_TYPE Z_JOIN_2(Z_APPEND_SINT,    Z_SINTPTR_BITS)
#define Z_APPEND_SINTPTR_FixedType  Z_JOIN_2(Z_APPEND_SInt,    Z_SINTPTR_BITS)
#define Z_APPEND_SINTPTR_fixed_type Z_JOIN_2(Z_APPEND_sint,    Z_SINTPTR_BITS)
#define Z_INSERT_SINTPTR_BITS	    Z_JOIN_2(Z_INSERT_NUMBER_, Z_SINTPTR_BITS)
#define Z_INSERT_SINTPTR_FIXED_TYPE Z_JOIN_2(Z_INSERT_SINT,    Z_SINTPTR_BITS)
#define Z_INSERT_SINTPTR_FixedType  Z_JOIN_2(Z_INSERT_SInt,    Z_SINTPTR_BITS)
#define Z_INSERT_SINTPTR_fixed_type Z_JOIN_2(Z_INSERT_sint,    Z_SINTPTR_BITS)

#define Z_APPEND_UINTTOP_BITS	    Z_JOIN_2(Z_APPEND_NUMBER_, Z_UINTTOP_BITS)
#define Z_APPEND_UINTTOP_FIXED_TYPE Z_JOIN_2(Z_APPEND_UINT,    Z_UINTTOP_BITS)
#define Z_APPEND_UINTTOP_FixedType  Z_JOIN_2(Z_APPEND_UInt,    Z_UINTTOP_BITS)
#define Z_APPEND_UINTTOP_fixed_type Z_JOIN_2(Z_APPEND_uint,    Z_UINTTOP_BITS)
#define Z_INSERT_UINTTOP_BITS	    Z_JOIN_2(Z_INSERT_NUMBER_, Z_UINTTOP_BITS)
#define Z_INSERT_UINTTOP_FIXED_TYPE Z_JOIN_2(Z_INSERT_UINT,    Z_UINTTOP_BITS)
#define Z_INSERT_UINTTOP_FixedType  Z_JOIN_2(Z_INSERT_UInt,    Z_UINTTOP_BITS)
#define Z_INSERT_UINTTOP_fixed_type Z_JOIN_2(Z_INSERT_uint,    Z_UINTTOP_BITS)

#define Z_APPEND_SINTTOP_BITS	    Z_JOIN_2(Z_APPEND_NUMBER_, Z_SINTTOP_BITS)
#define Z_APPEND_SINTTOP_FIXED_TYPE Z_JOIN_2(Z_APPEND_SINT,    Z_SINTTOP_BITS)
#define Z_APPEND_SINTTOP_FixedType  Z_JOIN_2(Z_APPEND_SInt,    Z_SINTTOP_BITS)
#define Z_APPEND_SINTTOP_fixed_type Z_JOIN_2(Z_APPEND_sint,    Z_SINTTOP_BITS)
#define Z_INSERT_SINTTOP_BITS	    Z_JOIN_2(Z_INSERT_NUMBER_, Z_SINTTOP_BITS)
#define Z_INSERT_SINTTOP_FIXED_TYPE Z_JOIN_2(Z_INSERT_SINT,    Z_SINTTOP_BITS)
#define Z_INSERT_SINTTOP_FixedType  Z_JOIN_2(Z_INSERT_SInt,    Z_SINTTOP_BITS)
#define Z_INSERT_SINTTOP_fixed_type Z_JOIN_2(Z_INSERT_sint,    Z_SINTTOP_BITS)

#define Z_APPEND_NATURAL_BITS	    Z_JOIN_2(Z_APPEND_NUMBER_, Z_NATURAL_BITS)
#define Z_APPEND_NATURAL_FIXED_TYPE Z_JOIN_2(Z_APPEND_UINT,    Z_NATURAL_BITS)
#define Z_APPEND_NATURAL_FixedType  Z_JOIN_2(Z_APPEND_UInt,    Z_NATURAL_BITS)
#define Z_APPEND_NATURAL_fixed_type Z_JOIN_2(Z_APPEND_uint,    Z_NATURAL_BITS)
#define Z_INSERT_NATURAL_BITS	    Z_JOIN_2(Z_INSERT_NUMBER_, Z_NATURAL_BITS)
#define Z_INSERT_NATURAL_FIXED_TYPE Z_JOIN_2(Z_INSERT_UINT,    Z_NATURAL_BITS)
#define Z_INSERT_NATURAL_FixedType  Z_JOIN_2(Z_INSERT_UInt,    Z_NATURAL_BITS)
#define Z_INSERT_NATURAL_fixed_type Z_JOIN_2(Z_INSERT_uint,    Z_NATURAL_BITS)

#define Z_APPEND_INTEGER_BITS	    Z_JOIN_2(Z_APPEND_NUMBER_, Z_INTEGER_BITS)
#define Z_APPEND_INTEGER_FIXED_TYPE Z_JOIN_2(Z_APPEND_SINT,    Z_INTEGER_BITS)
#define Z_APPEND_INTEGER_FixedType  Z_JOIN_2(Z_APPEND_SInt,    Z_INTEGER_BITS)
#define Z_APPEND_INTEGER_fixed_type Z_JOIN_2(Z_APPEND_sint,    Z_INTEGER_BITS)
#define Z_INSERT_INTEGER_BITS	    Z_JOIN_2(Z_INSERT_NUMBER_, Z_INTEGER_BITS)
#define Z_INSERT_INTEGER_FIXED_TYPE Z_JOIN_2(Z_INSERT_SINT,    Z_INTEGER_BITS)
#define Z_INSERT_INTEGER_FixedType  Z_JOIN_2(Z_INSERT_SInt,    Z_INTEGER_BITS)
#define Z_INSERT_INTEGER_fixed_type Z_JOIN_2(Z_INSERT_sint,    Z_INTEGER_BITS)

#define Z_APPEND_REAL_FIXED_TYPE    Z_JOIN_2(Z_APPEND_FIXED_TYPE_, Z_REAL_FIXED_VALUE_TYPE)
#define Z_APPEND_REAL_FixedType	    Z_JOIN_2(Z_APPEND_FixedType_,  Z_REAL_FIXED_VALUE_TYPE)
#define Z_APPEND_REAL_fixed_type    Z_JOIN_2(Z_APPEND_fixed_type_, Z_REAL_FIXED_VALUE_TYPE)
#define Z_INSERT_REAL_FIXED_TYPE    Z_JOIN_2(Z_INSERT_FIXED_TYPE_, Z_REAL_FIXED_VALUE_TYPE)
#define Z_INSERT_REAL_FixedType	    Z_JOIN_2(Z_INSERT_FixedType_,  Z_REAL_FIXED_VALUE_TYPE)
#define Z_INSERT_REAL_fixed_type    Z_JOIN_2(Z_INSERT_fixed_type_, Z_REAL_FIXED_VALUE_TYPE)

#endif /* _Z_macros_templating_H_ */
