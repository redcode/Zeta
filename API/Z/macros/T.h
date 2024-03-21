/* Zeta API - Z/macros/T.h
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_macros_T_H
#define Z_macros_T_H

/* MARK: - Type name tokens: Standard C/C++ fundamental types */

#define Z_z_APPEND_TYPE_1(lht)	     lht##CHAR
#define Z_z_APPEND_Type_1(lht)	     lht##Char
#define Z_z_APPEND_type_1(lht)	     lht##char
#define Z_z_INSERT_TYPE_1(lht, rht)  lht##CHAR##rht
#define Z_z_INSERT_Type_1(lht, rht)  lht##Char##rht
#define Z_z_INSERT_type_1(lht, rht)  lht##char##rht

#define Z_z_APPEND_TYPE_2(lht)	     lht##UCHAR
#define Z_z_APPEND_Type_2(lht)	     lht##UChar
#define Z_z_APPEND_type_2(lht)	     lht##uchar
#define Z_z_INSERT_TYPE_2(lht, rht)  lht##UCHAR##rht
#define Z_z_INSERT_Type_2(lht, rht)  lht##UChar##rht
#define Z_z_INSERT_type_2(lht, rht)  lht##uchar##rht

#define Z_z_APPEND_TYPE_3(lht)	     lht##SCHAR
#define Z_z_APPEND_Type_3(lht)	     lht##SChar
#define Z_z_APPEND_type_3(lht)	     lht##schar
#define Z_z_INSERT_TYPE_3(lht, rht)  lht##SCHAR##rht
#define Z_z_INSERT_Type_3(lht, rht)  lht##SChar##rht
#define Z_z_INSERT_type_3(lht, rht)  lht##schar##rht

#define Z_z_APPEND_TYPE_4(lht)	     lht##USHORT
#define Z_z_APPEND_Type_4(lht)	     lht##UShort
#define Z_z_APPEND_type_4(lht)	     lht##ushort
#define Z_z_INSERT_TYPE_4(lht, rht)  lht##USHORT##rht
#define Z_z_INSERT_Type_4(lht, rht)  lht##UShort##rht
#define Z_z_INSERT_type_4(lht, rht)  lht##ushort##rht

#define Z_z_APPEND_TYPE_5(lht)	     lht##SSHORT
#define Z_z_APPEND_Type_5(lht)	     lht##SShort
#define Z_z_APPEND_type_5(lht)	     lht##sshort
#define Z_z_INSERT_TYPE_5(lht, rht)  lht##SSHORT##rht
#define Z_z_INSERT_Type_5(lht, rht)  lht##SShort##rht
#define Z_z_INSERT_type_5(lht, rht)  lht##sshort##rht

#define Z_z_APPEND_TYPE_6(lht)	     lht##UINT
#define Z_z_APPEND_Type_6(lht)	     lht##UInt
#define Z_z_APPEND_type_6(lht)	     lht##uint
#define Z_z_INSERT_TYPE_6(lht, rht)  lht##UINT##rht
#define Z_z_INSERT_Type_6(lht, rht)  lht##UInt##rht
#define Z_z_INSERT_type_6(lht, rht)  lht##uint##rht

#define Z_z_APPEND_TYPE_7(lht)	     lht##SINT
#define Z_z_APPEND_Type_7(lht)	     lht##SInt
#define Z_z_APPEND_type_7(lht)	     lht##sint
#define Z_z_INSERT_TYPE_7(lht, rht)  lht##SINT##rht
#define Z_z_INSERT_Type_7(lht, rht)  lht##SInt##rht
#define Z_z_INSERT_type_7(lht, rht)  lht##sint##rht

#define Z_z_APPEND_TYPE_8(lht)	     lht##ULONG
#define Z_z_APPEND_Type_8(lht)	     lht##ULong
#define Z_z_APPEND_type_8(lht)	     lht##ulong
#define Z_z_INSERT_TYPE_8(lht, rht)  lht##ULONG##rht
#define Z_z_INSERT_Type_8(lht, rht)  lht##ULong##rht
#define Z_z_INSERT_type_8(lht, rht)  lht##ulong##rht

#define Z_z_APPEND_TYPE_9(lht)	     lht##SLONG
#define Z_z_APPEND_Type_9(lht)	     lht##SLong
#define Z_z_APPEND_type_9(lht)	     lht##slong
#define Z_z_INSERT_TYPE_9(lht, rht)  lht##SLONG##rht
#define Z_z_INSERT_Type_9(lht, rht)  lht##SLong##rht
#define Z_z_INSERT_type_9(lht, rht)  lht##slong##rht

#define Z_z_APPEND_TYPE_10(lht)	     lht##ULLONG
#define Z_z_APPEND_Type_10(lht)	     lht##ULLong
#define Z_z_APPEND_type_10(lht)	     lht##ullong
#define Z_z_INSERT_TYPE_10(lht, rht) lht##ULLONG##rht
#define Z_z_INSERT_Type_10(lht, rht) lht##ULLong##rht
#define Z_z_INSERT_type_10(lht, rht) lht##ullong##rht

#define Z_z_APPEND_TYPE_11(lht)	     lht##SLLONG
#define Z_z_APPEND_Type_11(lht)	     lht##SLLong
#define Z_z_APPEND_type_11(lht)	     lht##sllong
#define Z_z_INSERT_TYPE_11(lht, rht) lht##SLLONG##rht
#define Z_z_INSERT_Type_11(lht, rht) lht##SLLong##rht
#define Z_z_INSERT_type_11(lht, rht) lht##sllong##rht

#define Z_z_APPEND_TYPE_13(lht)	     lht##WCHAR
#define Z_z_APPEND_Type_13(lht)	     lht##WChar
#define Z_z_APPEND_type_13(lht)	     lht##wchar
#define Z_z_INSERT_TYPE_13(lht, rht) lht##WCHAR##rht
#define Z_z_INSERT_Type_13(lht, rht) lht##WChar##rht
#define Z_z_INSERT_type_13(lht, rht) lht##wchar##rht

#define Z_z_APPEND_TYPE_14(lht)	     lht##CHAR8
#define Z_z_APPEND_Type_14(lht)	     lht##Char8
#define Z_z_APPEND_type_14(lht)	     lht##char8
#define Z_z_INSERT_TYPE_14(lht, rht) lht##CHAR8##rht
#define Z_z_INSERT_Type_14(lht, rht) lht##Char8##rht
#define Z_z_INSERT_type_14(lht, rht) lht##char8##rht

#define Z_z_APPEND_TYPE_15(lht)	     lht##CHAR16
#define Z_z_APPEND_Type_15(lht)	     lht##Char16
#define Z_z_APPEND_type_15(lht)	     lht##char16
#define Z_z_INSERT_TYPE_15(lht, rht) lht##CHAR16##rht
#define Z_z_INSERT_Type_15(lht, rht) lht##Char16##rht
#define Z_z_INSERT_type_15(lht, rht) lht##char16##rht

#define Z_z_APPEND_TYPE_16(lht)	     lht##CHAR32
#define Z_z_APPEND_Type_16(lht)	     lht##Char32
#define Z_z_APPEND_type_16(lht)	     lht##char32
#define Z_z_INSERT_TYPE_16(lht, rht) lht##CHAR32##rht
#define Z_z_INSERT_Type_16(lht, rht) lht##Char32##rht
#define Z_z_INSERT_type_16(lht, rht) lht##char32##rht

#define Z_z_APPEND_TYPE_17(lht)	     lht##FLOAT
#define Z_z_APPEND_Type_17(lht)	     lht##Float
#define Z_z_APPEND_type_17(lht)	     lht##float
#define Z_z_INSERT_TYPE_17(lht, rht) lht##FLOAT##rht
#define Z_z_INSERT_Type_17(lht, rht) lht##Float##rht
#define Z_z_INSERT_type_17(lht, rht) lht##float##rht

#define Z_z_APPEND_TYPE_18(lht)	     lht##DOUBLE
#define Z_z_APPEND_Type_18(lht)	     lht##Double
#define Z_z_APPEND_type_18(lht)	     lht##double
#define Z_z_INSERT_TYPE_18(lht, rht) lht##DOUBLE##rht
#define Z_z_INSERT_Type_18(lht, rht) lht##Double##rht
#define Z_z_INSERT_type_18(lht, rht) lht##double##rht

#define Z_z_APPEND_TYPE_19(lht)	     lht##LDOUBLE
#define Z_z_APPEND_Type_19(lht)	     lht##LDouble
#define Z_z_APPEND_type_19(lht)	     lht##ldouble
#define Z_z_INSERT_TYPE_19(lht, rht) lht##LDOUBLE##rht
#define Z_z_INSERT_Type_19(lht, rht) lht##LDouble##rht
#define Z_z_INSERT_type_19(lht, rht) lht##ldouble##rht

#define Z_z_APPEND_TYPE_20(lht)	     lht##FLOAT16
#define Z_z_APPEND_Type_20(lht)	     lht##Float16
#define Z_z_APPEND_type_20(lht)	     lht##float16
#define Z_z_INSERT_TYPE_20(lht, rht) lht##FLOAT16##rht
#define Z_z_INSERT_Type_20(lht, rht) lht##Float16##rht
#define Z_z_INSERT_type_20(lht, rht) lht##float16##rht

#define Z_z_APPEND_TYPE_21(lht)	     lht##FLOAT32
#define Z_z_APPEND_Type_21(lht)	     lht##Float32
#define Z_z_APPEND_type_21(lht)	     lht##float32
#define Z_z_INSERT_TYPE_21(lht, rht) lht##FLOAT32##rht
#define Z_z_INSERT_Type_21(lht, rht) lht##Float32##rht
#define Z_z_INSERT_type_21(lht, rht) lht##float32##rht

#define Z_z_APPEND_TYPE_22(lht)	     lht##FLOAT64
#define Z_z_APPEND_Type_22(lht)	     lht##Float64
#define Z_z_APPEND_type_22(lht)	     lht##float64
#define Z_z_INSERT_TYPE_22(lht, rht) lht##FLOAT64##rht
#define Z_z_INSERT_Type_22(lht, rht) lht##Float64##rht
#define Z_z_INSERT_type_22(lht, rht) lht##float64##rht

#define Z_z_APPEND_TYPE_23(lht)	     lht##FLOAT128
#define Z_z_APPEND_Type_23(lht)	     lht##Float128
#define Z_z_APPEND_type_23(lht)	     lht##float128
#define Z_z_INSERT_TYPE_23(lht, rht) lht##FLOAT128##rht
#define Z_z_INSERT_Type_23(lht, rht) lht##Float128##rht
#define Z_z_INSERT_type_23(lht, rht) lht##float128##rht

#define Z_z_APPEND_TYPE_24(lht)	     lht##FLOAT32X
#define Z_z_APPEND_Type_24(lht)	     lht##Float32x
#define Z_z_APPEND_type_24(lht)	     lht##float32x
#define Z_z_INSERT_TYPE_24(lht, rht) lht##FLOAT32X##rht
#define Z_z_INSERT_Type_24(lht, rht) lht##Float32x##rht
#define Z_z_INSERT_type_24(lht, rht) lht##float32x##rht

#define Z_z_APPEND_TYPE_25(lht)	     lht##FLOAT64X
#define Z_z_APPEND_Type_25(lht)	     lht##Float64x
#define Z_z_APPEND_type_25(lht)	     lht##float64x
#define Z_z_INSERT_TYPE_25(lht, rht) lht##FLOAT64X##rht
#define Z_z_INSERT_Type_25(lht, rht) lht##Float64x##rht
#define Z_z_INSERT_type_25(lht, rht) lht##float64x##rht

#define Z_z_APPEND_TYPE_26(lht)	     lht##FLOAT128X
#define Z_z_APPEND_Type_26(lht)	     lht##Float128x
#define Z_z_APPEND_type_26(lht)	     lht##float128x
#define Z_z_INSERT_TYPE_26(lht, rht) lht##FLOAT128X##rht
#define Z_z_INSERT_Type_26(lht, rht) lht##Float128x##rht
#define Z_z_INSERT_type_26(lht, rht) lht##float128x##rht

#define Z_z_APPEND_TYPE_27(lht)	     lht##DECIMAL32
#define Z_z_APPEND_Type_27(lht)	     lht##Decimal32
#define Z_z_APPEND_type_27(lht)	     lht##decimal32
#define Z_z_INSERT_TYPE_27(lht, rht) lht##DECIMAL32##rht
#define Z_z_INSERT_Type_27(lht, rht) lht##Decimal32##rht
#define Z_z_INSERT_type_27(lht, rht) lht##decimal32##rht

#define Z_z_APPEND_TYPE_28(lht)	     lht##DECIMAL64
#define Z_z_APPEND_Type_28(lht)	     lht##Decimal64
#define Z_z_APPEND_type_28(lht)	     lht##decimal64
#define Z_z_INSERT_TYPE_28(lht, rht) lht##DECIMAL64##rht
#define Z_z_INSERT_Type_28(lht, rht) lht##Decimal64##rht
#define Z_z_INSERT_type_28(lht, rht) lht##decimal64##rht

#define Z_z_APPEND_TYPE_29(lht)	     lht##DECIMAL128
#define Z_z_APPEND_Type_29(lht)	     lht##Decimal128
#define Z_z_APPEND_type_29(lht)	     lht##decimal128
#define Z_z_INSERT_TYPE_29(lht, rht) lht##DECIMAL128##rht
#define Z_z_INSERT_Type_29(lht, rht) lht##Decimal128##rht
#define Z_z_INSERT_type_29(lht, rht) lht##decimal128##rht

#define Z_z_APPEND_TYPE_30(lht)	     lht##DECIMAL64X
#define Z_z_APPEND_Type_30(lht)	     lht##Decimal64x
#define Z_z_APPEND_type_30(lht)	     lht##decimal64x
#define Z_z_INSERT_TYPE_30(lht, rht) lht##DECIMAL64X##rht
#define Z_z_INSERT_Type_30(lht, rht) lht##Decimal64x##rht
#define Z_z_INSERT_type_30(lht, rht) lht##decimal64x##rht

#define Z_z_APPEND_TYPE_31(lht)	     lht##DECIMAL128X
#define Z_z_APPEND_Type_31(lht)	     lht##Decimal128x
#define Z_z_APPEND_type_31(lht)	     lht##decimal128x
#define Z_z_INSERT_TYPE_31(lht, rht) lht##DECIMAL128X##rht
#define Z_z_INSERT_Type_31(lht, rht) lht##Decimal128x##rht
#define Z_z_INSERT_type_31(lht, rht) lht##decimal128x##rht

/* MARK: - Type name tokens: Fixed width integral types */

#define Z_z_APPEND_TYPE_100(lht)      lht##UINT8
#define Z_z_APPEND_Type_100(lht)      lht##UInt8
#define Z_z_APPEND_type_100(lht)      lht##uint8
#define Z_z_INSERT_TYPE_100(lht, rht) lht##UINT8##rht
#define Z_z_INSERT_Type_100(lht, rht) lht##UInt8##rht
#define Z_z_INSERT_type_100(lht, rht) lht##uint8##rht

#define Z_z_APPEND_TYPE_101(lht)      lht##SINT8
#define Z_z_APPEND_Type_101(lht)      lht##SInt8
#define Z_z_APPEND_type_101(lht)      lht##sint8
#define Z_z_INSERT_TYPE_101(lht, rht) lht##SINT8##rht
#define Z_z_INSERT_Type_101(lht, rht) lht##SInt8##rht
#define Z_z_INSERT_type_101(lht, rht) lht##sint8##rht

#define Z_z_APPEND_TYPE_102(lht)      lht##UINT16
#define Z_z_APPEND_Type_102(lht)      lht##UInt16
#define Z_z_APPEND_type_102(lht)      lht##uint16
#define Z_z_INSERT_TYPE_102(lht, rht) lht##UINT16##rht
#define Z_z_INSERT_Type_102(lht, rht) lht##UInt16##rht
#define Z_z_INSERT_type_102(lht, rht) lht##uint16##rht

#define Z_z_APPEND_TYPE_103(lht)      lht##SINT16
#define Z_z_APPEND_Type_103(lht)      lht##SInt16
#define Z_z_APPEND_type_103(lht)      lht##sint16
#define Z_z_INSERT_TYPE_103(lht, rht) lht##SINT16##rht
#define Z_z_INSERT_Type_103(lht, rht) lht##SInt16##rht
#define Z_z_INSERT_type_103(lht, rht) lht##sint16##rht

#define Z_z_APPEND_TYPE_104(lht)      lht##UINT24
#define Z_z_APPEND_Type_104(lht)      lht##UInt24
#define Z_z_APPEND_type_104(lht)      lht##uint24
#define Z_z_INSERT_TYPE_104(lht, rht) lht##UINT24##rht
#define Z_z_INSERT_Type_104(lht, rht) lht##UInt24##rht
#define Z_z_INSERT_type_104(lht, rht) lht##uint24##rht

#define Z_z_APPEND_TYPE_105(lht)      lht##SINT24
#define Z_z_APPEND_Type_105(lht)      lht##SInt24
#define Z_z_APPEND_type_105(lht)      lht##sint24
#define Z_z_INSERT_TYPE_105(lht, rht) lht##SINT24##rht
#define Z_z_INSERT_Type_105(lht, rht) lht##SInt24##rht
#define Z_z_INSERT_type_105(lht, rht) lht##sint24##rht

#define Z_z_APPEND_TYPE_106(lht)      lht##UINT32
#define Z_z_APPEND_Type_106(lht)      lht##UInt32
#define Z_z_APPEND_type_106(lht)      lht##uint32
#define Z_z_INSERT_TYPE_106(lht, rht) lht##UINT32##rht
#define Z_z_INSERT_Type_106(lht, rht) lht##UInt32##rht
#define Z_z_INSERT_type_106(lht, rht) lht##uint32##rht

#define Z_z_APPEND_TYPE_107(lht)      lht##SINT32
#define Z_z_APPEND_Type_107(lht)      lht##SInt32
#define Z_z_APPEND_type_107(lht)      lht##sint32
#define Z_z_INSERT_TYPE_107(lht, rht) lht##SINT32##rht
#define Z_z_INSERT_Type_107(lht, rht) lht##SInt32##rht
#define Z_z_INSERT_type_107(lht, rht) lht##sint32##rht

#define Z_z_APPEND_TYPE_108(lht)      lht##UINT40
#define Z_z_APPEND_Type_108(lht)      lht##UInt40
#define Z_z_APPEND_type_108(lht)      lht##uint40
#define Z_z_INSERT_TYPE_108(lht, rht) lht##UINT40##rht
#define Z_z_INSERT_Type_108(lht, rht) lht##UInt40##rht
#define Z_z_INSERT_type_108(lht, rht) lht##uint40##rht

#define Z_z_APPEND_TYPE_109(lht)      lht##SINT40
#define Z_z_APPEND_Type_109(lht)      lht##SInt40
#define Z_z_APPEND_type_109(lht)      lht##sint40
#define Z_z_INSERT_TYPE_109(lht, rht) lht##SINT40##rht
#define Z_z_INSERT_Type_109(lht, rht) lht##SInt40##rht
#define Z_z_INSERT_type_109(lht, rht) lht##sint40##rht

#define Z_z_APPEND_TYPE_110(lht)      lht##UINT48
#define Z_z_APPEND_Type_110(lht)      lht##UInt48
#define Z_z_APPEND_type_110(lht)      lht##uint48
#define Z_z_INSERT_TYPE_110(lht, rht) lht##UINT48##rht
#define Z_z_INSERT_Type_110(lht, rht) lht##UInt48##rht
#define Z_z_INSERT_type_110(lht, rht) lht##uint48##rht

#define Z_z_APPEND_TYPE_111(lht)      lht##SINT48
#define Z_z_APPEND_Type_111(lht)      lht##SInt48
#define Z_z_APPEND_type_111(lht)      lht##sint48
#define Z_z_INSERT_TYPE_111(lht, rht) lht##SINT48##rht
#define Z_z_INSERT_Type_111(lht, rht) lht##SInt48##rht
#define Z_z_INSERT_type_111(lht, rht) lht##sint48##rht

#define Z_z_APPEND_TYPE_112(lht)      lht##UINT56
#define Z_z_APPEND_Type_112(lht)      lht##UInt56
#define Z_z_APPEND_type_112(lht)      lht##uint56
#define Z_z_INSERT_TYPE_112(lht, rht) lht##UINT56##rht
#define Z_z_INSERT_Type_112(lht, rht) lht##UInt56##rht
#define Z_z_INSERT_type_112(lht, rht) lht##uint56##rht

#define Z_z_APPEND_TYPE_113(lht)      lht##SINT56
#define Z_z_APPEND_Type_113(lht)      lht##SInt56
#define Z_z_APPEND_type_113(lht)      lht##sint56
#define Z_z_INSERT_TYPE_113(lht, rht) lht##SINT56##rht
#define Z_z_INSERT_Type_113(lht, rht) lht##SInt56##rht
#define Z_z_INSERT_type_113(lht, rht) lht##sint56##rht

#define Z_z_APPEND_TYPE_114(lht)      lht##UINT64
#define Z_z_APPEND_Type_114(lht)      lht##UInt64
#define Z_z_APPEND_type_114(lht)      lht##uint64
#define Z_z_INSERT_TYPE_114(lht, rht) lht##UINT64##rht
#define Z_z_INSERT_Type_114(lht, rht) lht##UInt64##rht
#define Z_z_INSERT_type_114(lht, rht) lht##uint64##rht

#define Z_z_APPEND_TYPE_115(lht)      lht##SINT64
#define Z_z_APPEND_Type_115(lht)      lht##SInt64
#define Z_z_APPEND_type_115(lht)      lht##sint64
#define Z_z_INSERT_TYPE_115(lht, rht) lht##SINT64##rht
#define Z_z_INSERT_Type_115(lht, rht) lht##SInt64##rht
#define Z_z_INSERT_type_115(lht, rht) lht##sint64##rht

#define Z_z_APPEND_TYPE_116(lht)      lht##UINT128
#define Z_z_APPEND_Type_116(lht)      lht##UInt128
#define Z_z_APPEND_type_116(lht)      lht##uint128
#define Z_z_INSERT_TYPE_116(lht, rht) lht##UINT128##rht
#define Z_z_INSERT_Type_116(lht, rht) lht##UInt128##rht
#define Z_z_INSERT_type_116(lht, rht) lht##uint128##rht

#define Z_z_APPEND_TYPE_117(lht)      lht##SINT128
#define Z_z_APPEND_Type_117(lht)      lht##SInt128
#define Z_z_APPEND_type_117(lht)      lht##sint128
#define Z_z_INSERT_TYPE_117(lht, rht) lht##SINT128##rht
#define Z_z_INSERT_Type_117(lht, rht) lht##SInt128##rht
#define Z_z_INSERT_type_117(lht, rht) lht##sint128##rht

/* MARK: - Type name tokens: Fixed format real types */

#define Z_z_APPEND_TYPE_150(lht)      lht##BFP16
#define Z_z_APPEND_Type_150(lht)      lht##BFP16
#define Z_z_APPEND_type_150(lht)      lht##bfp16
#define Z_z_INSERT_TYPE_150(lht, rht) lht##BFP16##rht
#define Z_z_INSERT_Type_150(lht, rht) lht##BFP16##rht
#define Z_z_INSERT_type_150(lht, rht) lht##bfp16##rht

#define Z_z_APPEND_TYPE_151(lht)      lht##BFP32
#define Z_z_APPEND_Type_151(lht)      lht##BFP32
#define Z_z_APPEND_type_151(lht)      lht##bfp32
#define Z_z_INSERT_TYPE_151(lht, rht) lht##BFP32##rht
#define Z_z_INSERT_Type_151(lht, rht) lht##BFP32##rht
#define Z_z_INSERT_type_151(lht, rht) lht##bfp32##rht

#define Z_z_APPEND_TYPE_152(lht)      lht##BFP64
#define Z_z_APPEND_Type_152(lht)      lht##BFP64
#define Z_z_APPEND_type_152(lht)      lht##bfp64
#define Z_z_INSERT_TYPE_152(lht, rht) lht##BFP64##rht
#define Z_z_INSERT_Type_152(lht, rht) lht##BFP64##rht
#define Z_z_INSERT_type_152(lht, rht) lht##bfp64##rht

#define Z_z_APPEND_TYPE_153(lht)      lht##BFP128
#define Z_z_APPEND_Type_153(lht)      lht##BFP128
#define Z_z_APPEND_type_153(lht)      lht##bfp128
#define Z_z_INSERT_TYPE_153(lht, rht) lht##BFP128##rht
#define Z_z_INSERT_Type_153(lht, rht) lht##BFP128##rht
#define Z_z_INSERT_type_153(lht, rht) lht##bfp128##rht

#define Z_z_APPEND_TYPE_154(lht)      lht##DFP32
#define Z_z_APPEND_Type_154(lht)      lht##DFP32
#define Z_z_APPEND_type_154(lht)      lht##dfp32
#define Z_z_INSERT_TYPE_154(lht, rht) lht##DFP32##rht
#define Z_z_INSERT_Type_154(lht, rht) lht##DFP32##rht
#define Z_z_INSERT_type_154(lht, rht) lht##dfp32##rht

#define Z_z_APPEND_TYPE_155(lht)      lht##DFP64
#define Z_z_APPEND_Type_155(lht)      lht##DFP64
#define Z_z_APPEND_type_155(lht)      lht##dfp64
#define Z_z_INSERT_TYPE_155(lht, rht) lht##DFP64##rht
#define Z_z_INSERT_Type_155(lht, rht) lht##DFP64##rht
#define Z_z_INSERT_type_155(lht, rht) lht##dfp64##rht

#define Z_z_APPEND_TYPE_156(lht)      lht##DFP128
#define Z_z_APPEND_Type_156(lht)      lht##DFP128
#define Z_z_APPEND_type_156(lht)      lht##dfp128
#define Z_z_INSERT_TYPE_156(lht, rht) lht##DFP128##rht
#define Z_z_INSERT_Type_156(lht, rht) lht##DFP128##rht
#define Z_z_INSERT_type_156(lht, rht) lht##dfp128##rht

#define Z_z_APPEND_TYPE_157(lht)      lht##X87_DE80
#define Z_z_APPEND_Type_157(lht)      lht##x87_DE80
#define Z_z_APPEND_type_157(lht)      lht##x87_de80
#define Z_z_INSERT_TYPE_157(lht, rht) lht##X87_DE80##rht
#define Z_z_INSERT_Type_157(lht, rht) lht##x87_DE80##rht
#define Z_z_INSERT_type_157(lht, rht) lht##x87_de80##rht

#define Z_z_APPEND_TYPE_158(lht)      lht##X87_DE96
#define Z_z_APPEND_Type_158(lht)      lht##x87_DE96
#define Z_z_APPEND_type_158(lht)      lht##x87_de96
#define Z_z_INSERT_TYPE_158(lht, rht) lht##X87_DE96##rht
#define Z_z_INSERT_Type_158(lht, rht) lht##x87_DE96##rht
#define Z_z_INSERT_type_158(lht, rht) lht##x87_de96##rht

#define Z_z_APPEND_TYPE_159(lht)      lht##X87_DE128
#define Z_z_APPEND_Type_159(lht)      lht##x87_DE128
#define Z_z_APPEND_type_159(lht)      lht##x87_de128
#define Z_z_INSERT_TYPE_159(lht, rht) lht##X87_DE128##rht
#define Z_z_INSERT_Type_159(lht, rht) lht##x87_DE128##rht
#define Z_z_INSERT_type_159(lht, rht) lht##x87_de128##rht

#define Z_z_APPEND_TYPE_160(lht)      lht##IBM_ED
#define Z_z_APPEND_Type_160(lht)      lht##IBM_ED
#define Z_z_APPEND_type_160(lht)      lht##ibm_ed
#define Z_z_INSERT_TYPE_160(lht, rht) lht##IBM_ED##rht
#define Z_z_INSERT_Type_160(lht, rht) lht##IBM_ED##rht
#define Z_z_INSERT_type_160(lht, rht) lht##ibm_ed##rht

#define Z_z_APPEND_TYPE_162(lht)      lht##BFLOAT16
#define Z_z_APPEND_Type_162(lht)      lht##bfloat16
#define Z_z_APPEND_type_162(lht)      lht##bfloat16
#define Z_z_INSERT_TYPE_162(lht, rht) lht##BFLOAT16##rht
#define Z_z_INSERT_Type_162(lht, rht) lht##bfloat16##rht
#define Z_z_INSERT_type_162(lht, rht) lht##bfloat16##rht

#define Z_PREPEND_TYPE(FUNDAMENTAL) Z_JOIN_2(Z_z_PREPEND_TYPE_, FUNDAMENTAL)
#define Z_PREPEND_Type(FUNDAMENTAL) Z_JOIN_2(Z_z_PREPEND_Type_, FUNDAMENTAL)
#define Z_PREPEND_type(FUNDAMENTAL) Z_JOIN_2(Z_z_PREPEND_type_, FUNDAMENTAL)
#define Z_APPEND_TYPE( FUNDAMENTAL) Z_JOIN_2(Z_z_APPEND_TYPE_,  FUNDAMENTAL)
#define Z_APPEND_Type( FUNDAMENTAL) Z_JOIN_2(Z_z_APPEND_Type_,  FUNDAMENTAL)
#define Z_APPEND_type( FUNDAMENTAL) Z_JOIN_2(Z_z_APPEND_type_,  FUNDAMENTAL)
#define Z_INSERT_TYPE( FUNDAMENTAL) Z_JOIN_2(Z_z_INSERT_TYPE_,  FUNDAMENTAL)
#define Z_INSERT_Type( FUNDAMENTAL) Z_JOIN_2(Z_z_INSERT_Type_,  FUNDAMENTAL)
#define Z_INSERT_type( FUNDAMENTAL) Z_JOIN_2(Z_z_INSERT_type_,  FUNDAMENTAL)

/* MARK: - Number format name tokens: Fixed format real types */

#define Z_z_INSERT_NUMBER_FORMAT_37(lht, rht) lht##IEEE_754_BINARY16##rht
#define Z_z_INSERT_NUMBER_FORMAT_38(lht, rht) lht##IEEE_754_BINARY32##rht
#define Z_z_INSERT_NUMBER_FORMAT_39(lht, rht) lht##IEEE_754_BINARY64##rht
#define Z_z_INSERT_NUMBER_FORMAT_40(lht, rht) lht##IEEE_754_BINARY128##rht
#define Z_z_INSERT_NUMBER_FORMAT_41(lht, rht) lht##IEEE_754_DECIMAL32##rht
#define Z_z_INSERT_NUMBER_FORMAT_42(lht, rht) lht##IEEE_754_DECIMAL64##rht
#define Z_z_INSERT_NUMBER_FORMAT_43(lht, rht) lht##IEEE_754_DECIMAL128##rht
#define Z_z_INSERT_NUMBER_FORMAT_44(lht, rht) lht##X87_DOUBLE_EXTENDED##rht
#define Z_z_INSERT_NUMBER_FORMAT_45(lht, rht) lht##IBM_EXTENDED_DOUBLE##rht
#define Z_z_INSERT_NUMBER_FORMAT_47(lht, rht) lht##BRAIN_FLOATING_POINT##rht

#define Z_INSERT_NUMBER_FORMAT(NUMBER_FORMAT) Z_JOIN_2(Z_z_INSERT_NUMBER_FORMAT_, NUMBER_FORMAT)

#endif /* Z_macros_T_H */
