/* Z Kit C API - macros/templating.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_|
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_macros_templating_H__
#define __Z_macros_templating_H__

#define Z_INSERT_UINT8(	 left, right) left##UINT8##right
#define Z_INSERT_UInt8(	 left, right) left##UInt8##right
#define Z_INSERT_uint8(	 left, right) left##uint8##right
#define Z_INSERT_UINT16( left, right) left##UINT16##right
#define Z_INSERT_UInt16( left, right) left##UInt16##right
#define Z_INSERT_uint16( left, right) left##uint16##right
#define Z_INSERT_UINT32( left, right) left##UINT32##right
#define Z_INSERT_UInt32( left, right) left##UInt32##right
#define Z_INSERT_uint32( left, right) left##uint32##right
#define Z_INSERT_UINT64( left, right) left##UINT64##right
#define Z_INSERT_UInt64( left, right) left##UInt64##right
#define Z_INSERT_uint64( left, right) left##uint64##right
#define Z_INSERT_UINT128(left, right) left##UINT128##right
#define Z_INSERT_UInt128(left, right) left##UInt128##right
#define Z_INSERT_uint128(left, right) left##uint128##right

#define Z_INSERT_INT8(	left, right) left##INT8##right
#define Z_INSERT_Int8(	left, right) left##Int8##right
#define Z_INSERT_int8(	left, right) left##int8##right
#define Z_INSERT_INT16(	left, right) left##INT16##right
#define Z_INSERT_Int16(	left, right) left##Int16##right
#define Z_INSERT_int16(	left, right) left##int16##right
#define Z_INSERT_INT32(	left, right) left##INT32##right
#define Z_INSERT_Int32(	left, right) left##Int32##right
#define Z_INSERT_int32(	left, right) left##int32##right
#define Z_INSERT_INT64(	left, right) left##INT64##right
#define Z_INSERT_Int64(	left, right) left##Int64##right
#define Z_INSERT_int64(	left, right) left##int64##right
#define Z_INSERT_INT128(left, right) left##INT128##right
#define Z_INSERT_Int128(left, right) left##Int128##right
#define Z_INSERT_int128(left, right) left##int128##right

#define Z_INSERT_FLOAT16( left, right) left##FLOAT16##right
#define Z_INSERT_Float16( left, right) left##Float16##right
#define Z_INSERT_float16( left, right) left##float16##right
#define Z_INSERT_FLOAT24( left, right) left##FLOAT24##right
#define Z_INSERT_Float24( left, right) left##Float24##right
#define Z_INSERT_float24( left, right) left##float24##right
#define Z_INSERT_FLOAT32( left, right) left##FLOAT32##right
#define Z_INSERT_Float32( left, right) left##Float32##right
#define Z_INSERT_float32( left, right) left##float32##right
#define Z_INSERT_FLOAT48( left, right) left##FLOAT48##right
#define Z_INSERT_Float48( left, right) left##Float48##right
#define Z_INSERT_float48( left, right) left##float48##right
#define Z_INSERT_FLOAT64( left, right) left##FLOAT64##right
#define Z_INSERT_Float64( left, right) left##Float64##right
#define Z_INSERT_float64( left, right) left##float64##right
#define Z_INSERT_FLOAT72( left, right) left##FLOAT72##right
#define Z_INSERT_Float72( left, right) left##Float72##right
#define Z_INSERT_float72( left, right) left##float72##right
#define Z_INSERT_FLOAT80( left, right) left##FLOAT80##right
#define Z_INSERT_Float80( left, right) left##Float80##right
#define Z_INSERT_float80( left, right) left##float80##right
#define Z_INSERT_FLOAT96( left, right) left##FLOAT96##right
#define Z_INSERT_Float96( left, right) left##Float96##right
#define Z_INSERT_float96( left, right) left##float96##right
#define Z_INSERT_FLOAT128(left, right) left##FLOAT128##right
#define Z_INSERT_Float128(left, right) left##Float128##right
#define Z_INSERT_float128(left, right) left##float128##right

#define Z_INSERT_UCHAR_BITS	    Z_JOIN_2(Z_INSERT_NUMBER_, Z_UCHAR_BITS  )
#define Z_INSERT_UCHAR_FIXED_TYPE   Z_JOIN_2(Z_INSERT_UINT,    Z_UCHAR_BITS  )
#define Z_INSERT_UCHAR_FixedType    Z_JOIN_2(Z_INSERT_UInt,    Z_UCHAR_BITS  )
#define Z_INSERT_UCHAR_fixed_type   Z_JOIN_2(Z_INSERT_uint,    Z_UCHAR_BITS  )
#define Z_INSERT_USHORT_BITS	    Z_JOIN_2(Z_INSERT_NUMBER_, Z_USHORT_BITS )
#define Z_INSERT_USHORT_FIXED_TYPE  Z_JOIN_2(Z_INSERT_UINT,    Z_USHORT_BITS )
#define Z_INSERT_USHORT_FixedType   Z_JOIN_2(Z_INSERT_UInt,    Z_USHORT_BITS )
#define Z_INSERT_USHORT_fixed_type  Z_JOIN_2(Z_INSERT_uint,    Z_USHORT_BITS )
#define Z_INSERT_UINT_BITS	    Z_JOIN_2(Z_INSERT_NUMBER_, Z_UINT_BITS   )
#define Z_INSERT_UINT_FIXED_TYPE    Z_JOIN_2(Z_INSERT_UINT,    Z_UINT_BITS   )
#define Z_INSERT_UINT_FixedType	    Z_JOIN_2(Z_INSERT_UInt,    Z_UINT_BITS   )
#define Z_INSERT_UINT_fixed_type    Z_JOIN_2(Z_INSERT_uint,    Z_UINT_BITS   )
#define Z_INSERT_ULONG_BITS	    Z_JOIN_2(Z_INSERT_NUMBER_, Z_ULONG_BITS  )
#define Z_INSERT_ULONG_FIXED_TYPE   Z_JOIN_2(Z_INSERT_UINT,    Z_ULONG_BITS  )
#define Z_INSERT_ULONG_FixedType    Z_JOIN_2(Z_INSERT_UInt,    Z_ULONG_BITS  )
#define Z_INSERT_ULONG_fixed_type   Z_JOIN_2(Z_INSERT_uint,    Z_ULONG_BITS  )
#define Z_INSERT_ULLONG_BITS	    Z_JOIN_2(Z_INSERT_NUMBER_, Z_ULLONG_BITS )
#define Z_INSERT_ULLONG_FIXED_TYPE  Z_JOIN_2(Z_INSERT_UINT,    Z_ULLONG_BITS )
#define Z_INSERT_ULLONG_FixedType   Z_JOIN_2(Z_INSERT_UInt,    Z_ULLONG_BITS )
#define Z_INSERT_ULLONG_fixed_type  Z_JOIN_2(Z_INSERT_uint,    Z_ULLONG_BITS )
#define Z_INSERT_CHAR_BITS	    Z_JOIN_2(Z_INSERT_NUMBER_, Z_CHAR_BITS   )
#define Z_INSERT_CHAR_FIXED_TYPE    Z_JOIN_2(Z_INSERT_INT,     Z_CHAR_BITS   )
#define Z_INSERT_CHAR_FixedType	    Z_JOIN_2(Z_INSERT_Int,     Z_CHAR_BITS   )
#define Z_INSERT_CHAR_fixed_type    Z_JOIN_2(Z_INSERT_int,     Z_CHAR_BITS   )
#define Z_INSERT_SHORT_BITS	    Z_JOIN_2(Z_INSERT_NUMBER_, Z_SHORT_BITS  )
#define Z_INSERT_SHORT_FIXED_TYPE   Z_JOIN_2(Z_INSERT_INT,     Z_SHORT_BITS  )
#define Z_INSERT_SHORT_FixedType    Z_JOIN_2(Z_INSERT_Int,     Z_SHORT_BITS  )
#define Z_INSERT_SHORT_fixed_type   Z_JOIN_2(Z_INSERT_int,     Z_SHORT_BITS  )
#define Z_INSERT_INT_BITS	    Z_JOIN_2(Z_INSERT_NUMBER_, Z_INT_BITS    )
#define Z_INSERT_INT_FIXED_TYPE	    Z_JOIN_2(Z_INSERT_INT,     Z_INT_BITS    )
#define Z_INSERT_INT_FixedType	    Z_JOIN_2(Z_INSERT_Int,     Z_INT_BITS    )
#define Z_INSERT_INT_fixed_type	    Z_JOIN_2(Z_INSERT_int,     Z_INT_BITS    )
#define Z_INSERT_LONG_BITS	    Z_JOIN_2(Z_INSERT_NUMBER_, Z_LONG_BITS   )
#define Z_INSERT_LONG_FIXED_TYPE    Z_JOIN_2(Z_INSERT_INT,     Z_LONG_BITS   )
#define Z_INSERT_LONG_FixedType	    Z_JOIN_2(Z_INSERT_Int,     Z_LONG_BITS   )
#define Z_INSERT_LONG_fixed_type    Z_JOIN_2(Z_INSERT_int,     Z_LONG_BITS   )
#define Z_INSERT_LLONG_BITS	    Z_JOIN_2(Z_INSERT_NUMBER_, Z_LLONG_BITS  )
#define Z_INSERT_LLONG_FIXED_TYPE   Z_JOIN_2(Z_INSERT_INT,     Z_LLONG_BITS  )
#define Z_INSERT_LLONG_FixedType    Z_JOIN_2(Z_INSERT_Int,     Z_LLONG_BITS  )
#define Z_INSERT_LLONG_fixed_type   Z_JOIN_2(Z_INSERT_int,     Z_LLONG_BITS  )
#define Z_INSERT_FLOAT_BITS	    Z_JOIN_2(Z_INSERT_NUMBER_, Z_FLOAT_BITS  )
#define Z_INSERT_FLOAT_FIXED_TYPE   Z_JOIN_2(Z_INSERT_FLOAT,   Z_FLOAT_BITS  )
#define Z_INSERT_FLOAT_FixedType    Z_JOIN_2(Z_INSERT_Float,   Z_FLOAT_BITS  )
#define Z_INSERT_FLOAT_fixed_type   Z_JOIN_2(Z_INSERT_float,   Z_FLOAT_BITS  )
#define Z_INSERT_DOUBLE_BITS	    Z_JOIN_2(Z_INSERT_NUMBER_, Z_DOUBLE_BITS )
#define Z_INSERT_DOUBLE_FIXED_TYPE  Z_JOIN_2(Z_INSERT_FLOAT,   Z_DOUBLE_BITS )
#define Z_INSERT_DOUBLE_FixedType   Z_JOIN_2(Z_INSERT_Float,   Z_DOUBLE_BITS )
#define Z_INSERT_DOUBLE_fixed_type  Z_JOIN_2(Z_INSERT_float,   Z_DOUBLE_BITS )
#define Z_INSERT_LDOUBLE_BITS	    Z_JOIN_2(Z_INSERT_NUMBER_, Z_LDOUBLE_BITS)
#define Z_INSERT_LDOUBLE_FIXED_TYPE Z_JOIN_2(Z_INSERT_FLOAT,   Z_LDOUBLE_BITS)
#define Z_INSERT_LDOUBLE_FixedType  Z_JOIN_2(Z_INSERT_Float,   Z_LDOUBLE_BITS)
#define Z_INSERT_LDOUBLE_fixed_type Z_JOIN_2(Z_INSERT_float,   Z_LDOUBLE_BITS)

#define Z_INSERT_SIZE_BITS	  Z_JOIN_2(Z_INSERT_NUMBER_,  Z_SIZE_BITS )
#define Z_INSERT_SIZE_FIXED_TYPE  Z_JOIN_2(Z_INSERT_UINT,     Z_SIZE_BITS )
#define Z_INSERT_SIZE_FixedType	  Z_JOIN_2(Z_INSERT_UInt,     Z_SIZE_BITS )
#define Z_INSERT_SIZE_fixed_type  Z_JOIN_2(Z_INSERT_uint,     Z_SIZE_BITS )
#define Z_INSERT_SSIZE_BITS	  Z_JOIN_2(Z_INSERT_NUMBER_,  Z_SSIZE_BITS)
#define Z_INSERT_SSIZE_FIXED_TYPE Z_JOIN_2(Z_INSERT_INT,      Z_SSIZE_BITS)
#define Z_INSERT_SSIZE_FixedType  Z_JOIN_2(Z_INSERT_Int,      Z_SSIZE_BITS)
#define Z_INSERT_SSIZE_fixed_type Z_JOIN_2(Z_INSERT_int,      Z_SSIZE_BITS)

#define Z_INSERT_UINTMAX_BITS	    Z_JOIN_2(Z_INSERT_NUMBER_, Z_UINTMAX_BITS)
#define Z_INSERT_UINTMAX_FIXED_TYPE Z_JOIN_2(Z_INSERT_UINT,    Z_UINTMAX_BITS)
#define Z_INSERT_UINTMAX_FixedType  Z_JOIN_2(Z_INSERT_UInt,    Z_UINTMAX_BITS)
#define Z_INSERT_UINTMAX_fixed_type Z_JOIN_2(Z_INSERT_uint,    Z_UINTMAX_BITS)
#define Z_INSERT_UINTPTR_BITS	    Z_JOIN_2(Z_INSERT_NUMBER_, Z_UINTPTR_BITS)
#define Z_INSERT_UINTPTR_FIXED_TYPE Z_JOIN_2(Z_INSERT_UINT,    Z_UINTPTR_BITS)
#define Z_INSERT_UINTPTR_FixedType  Z_JOIN_2(Z_INSERT_UInt,    Z_UINTPTR_BITS)
#define Z_INSERT_UINTPTR_fixed_type Z_JOIN_2(Z_INSERT_uint,    Z_UINTPTR_BITS)
#define Z_INSERT_UINTTOP_BITS	    Z_JOIN_2(Z_INSERT_NUMBER_, Z_UINTTOP_BITS)
#define Z_INSERT_UINTTOP_FIXED_TYPE Z_JOIN_2(Z_INSERT_UINT,    Z_UINTTOP_BITS)
#define Z_INSERT_UINTTOP_FixedType  Z_JOIN_2(Z_INSERT_UInt,    Z_UINTTOP_BITS)
#define Z_INSERT_UINTTOP_fixed_type Z_JOIN_2(Z_INSERT_uint,    Z_UINTTOP_BITS)

#define Z_INSERT_INTMAX_BITS	    Z_JOIN_2(Z_INSERT_NUMBER_, Z_INTMAX_BITS)
#define Z_INSERT_INTMAX_FIXED_TYPE  Z_JOIN_2(Z_INSERT_INT,     Z_INTMAX_BITS)
#define Z_INSERT_INTMAX_FixedType   Z_JOIN_2(Z_INSERT_Int,     Z_INTMAX_BITS)
#define Z_INSERT_INTMAX_fixed_type  Z_JOIN_2(Z_INSERT_int,     Z_INTMAX_BITS)
#define Z_INSERT_INTPTR_BITS	    Z_JOIN_2(Z_INSERT_NUMBER_, Z_INTPTR_BITS)
#define Z_INSERT_INTPTR_FIXED_TYPE  Z_JOIN_2(Z_INSERT_INT,     Z_INTPTR_BITS)
#define Z_INSERT_INTPTR_FixedType   Z_JOIN_2(Z_INSERT_Int,     Z_INTPTR_BITS)
#define Z_INSERT_INTPTR_fixed_type  Z_JOIN_2(Z_INSERT_int,     Z_INTPTR_BITS)
#define Z_INSERT_INTTOP_BITS	    Z_JOIN_2(Z_INSERT_NUMBER_, Z_INTTOP_BITS)
#define Z_INSERT_INTTOP_FIXED_TYPE  Z_JOIN_2(Z_INSERT_INT,     Z_INTTOP_BITS)
#define Z_INSERT_INTTOP_FixedType   Z_JOIN_2(Z_INSERT_Int,     Z_INTTOP_BITS)
#define Z_INSERT_INTTOP_fixed_type  Z_JOIN_2(Z_INSERT_int,     Z_INTTOP_BITS)

#if ('\0' - 1) > 0
#	define Z_INSERT_CHARACTER_BITS	     Z_INSERT_UCHAR_BITS
#	define Z_INSERT_CHARACTER_FIXED_TYPE Z_INSERT_UCHAR_FIXED_TYPE
#	define Z_INSERT_CHARACTER_FixedType  Z_INSERT_UCHAR_FixedType
#	define Z_INSERT_CHARACTER_fixed_type Z_INSERT_UCHAR_fixed_type
#else
#	define Z_INSERT_CHARACTER_BITS	     Z_INSERT_CHAR_BITS
#	define Z_INSERT_CHARACTER_FIXED_TYPE Z_INSERT_CHAR_FIXED_TYPE
#	define Z_INSERT_CHARACTER_FixedType  Z_INSERT_CHAR_FixedType
#	define Z_INSERT_CHARACTER_fixed_type Z_INSERT_CHAR_fixed_type
#endif

#define Z_INSERT_NATURAL_BITS	    Z_JOIN_2(Z_INSERT_NUMBER_, Z_NATURAL_BITS)
#define Z_INSERT_NATURAL_FIXED_TYPE Z_JOIN_2(Z_INSERT_UINT,    Z_NATURAL_BITS)
#define Z_INSERT_NATURAL_FixedType  Z_JOIN_2(Z_INSERT_UInt,    Z_NATURAL_BITS)
#define Z_INSERT_NATURAL_fixed_type Z_JOIN_2(Z_INSERT_uint,    Z_NATURAL_BITS)
#define Z_INSERT_INTEGER_BITS	    Z_JOIN_2(Z_INSERT_NUMBER_, Z_INTEGER_BITS)
#define Z_INSERT_INTEGER_FIXED_TYPE Z_JOIN_2(Z_INSERT_INT,     Z_INTEGER_BITS)
#define Z_INSERT_INTEGER_FixedType  Z_JOIN_2(Z_INSERT_Int,     Z_INTEGER_BITS)
#define Z_INSERT_INTEGER_fixed_type Z_JOIN_2(Z_INSERT_int,     Z_INTEGER_BITS)
#define Z_INSERT_REAL_BITS	    Z_JOIN_2(Z_INSERT_NUMBER_, Z_REAL_BITS   )
#define Z_INSERT_REAL_FIXED_TYPE    Z_JOIN_2(Z_INSERT_FLOAT,   Z_REAL_BITS   )
#define Z_INSERT_REAL_FixedType	    Z_JOIN_2(Z_INSERT_Float,   Z_REAL_BITS   )
#define Z_INSERT_REAL_fixed_type    Z_JOIN_2(Z_INSERT_float,   Z_REAL_BITS   )

#ifndef __Z_types_base_H__
#	include <Z/types/base.h>
#endif

#endif /* __Z_macros_templating_H__ */
