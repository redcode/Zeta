/* Z Kit - macros/templating.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2019 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_macros_templating_H
#define Z_macros_templating_H

/* MARK: - Type tokens: Standard C/C++ fundamental types */

#define Z_APPEND_TYPE_1(to)	      to##CHAR
#define Z_APPEND_Type_1(to)	      to##Char
#define Z_APPEND_type_1(to)	      to##char
#define Z_INSERT_TYPE_1(left, right)  left##CHAR##right
#define Z_INSERT_Type_1(left, right)  left##Char##right
#define Z_INSERT_type_1(left, right)  left##char##right

#define Z_APPEND_TYPE_2(to)	      to##UCHAR
#define Z_APPEND_Type_2(to)	      to##UChar
#define Z_APPEND_type_2(to)	      to##uchar
#define Z_INSERT_TYPE_2(left, right)  left##UCHAR##right
#define Z_INSERT_Type_2(left, right)  left##UChar##right
#define Z_INSERT_type_2(left, right)  left##uchar##right

#define Z_APPEND_TYPE_3(to)	      to##SCHAR
#define Z_APPEND_Type_3(to)	      to##SChar
#define Z_APPEND_type_3(to)	      to##schar
#define Z_INSERT_TYPE_3(left, right)  left##SCHAR##right
#define Z_INSERT_Type_3(left, right)  left##SChar##right
#define Z_INSERT_type_3(left, right)  left##schar##right

#define Z_APPEND_TYPE_4(to)	      to##USHORT
#define Z_APPEND_Type_4(to)	      to##UShort
#define Z_APPEND_type_4(to)	      to##ushort
#define Z_INSERT_TYPE_4(left, right)  left##USHORT##right
#define Z_INSERT_Type_4(left, right)  left##UShort##right
#define Z_INSERT_type_4(left, right)  left##ushort##right

#define Z_APPEND_TYPE_5(to)	      to##SSHORT
#define Z_APPEND_Type_5(to)	      to##SShort
#define Z_APPEND_type_5(to)	      to##sshort
#define Z_INSERT_TYPE_5(left, right)  left##SSHORT##right
#define Z_INSERT_Type_5(left, right)  left##SShort##right
#define Z_INSERT_type_5(left, right)  left##sshort##right

#define Z_APPEND_TYPE_6(to)	      to##UINT
#define Z_APPEND_Type_6(to)	      to##UInt
#define Z_APPEND_type_6(to)	      to##uint
#define Z_INSERT_TYPE_6(left, right)  left##UINT##right
#define Z_INSERT_Type_6(left, right)  left##UInt##right
#define Z_INSERT_type_6(left, right)  left##uint##right

#define Z_APPEND_TYPE_7(to)	      to##SINT
#define Z_APPEND_Type_7(to)	      to##SInt
#define Z_APPEND_type_7(to)	      to##sint
#define Z_INSERT_TYPE_7(left, right)  left##SINT##right
#define Z_INSERT_Type_7(left, right)  left##SInt##right
#define Z_INSERT_type_7(left, right)  left##sint##right

#define Z_APPEND_TYPE_8(to)	      to##ULONG
#define Z_APPEND_Type_8(to)	      to##ULong
#define Z_APPEND_type_8(to)	      to##ulong
#define Z_INSERT_TYPE_8(left, right)  left##ULONG##right
#define Z_INSERT_Type_8(left, right)  left##ULong##right
#define Z_INSERT_type_8(left, right)  left##ulong##right

#define Z_APPEND_TYPE_9(to)	      to##SLONG
#define Z_APPEND_Type_9(to)	      to##SLong
#define Z_APPEND_type_9(to)	      to##slong
#define Z_INSERT_TYPE_9(left, right)  left##SLONG##right
#define Z_INSERT_Type_9(left, right)  left##SLong##right
#define Z_INSERT_type_9(left, right)  left##slong##right

#define Z_APPEND_TYPE_10(to)	      to##ULLONG
#define Z_APPEND_Type_10(to)	      to##ULLong
#define Z_APPEND_type_10(to)	      to##ullong
#define Z_INSERT_TYPE_10(left, right) left##ULLONG##right
#define Z_INSERT_Type_10(left, right) left##ULLong##right
#define Z_INSERT_type_10(left, right) left##ullong##right

#define Z_APPEND_TYPE_11(to)	      to##SLLONG
#define Z_APPEND_Type_11(to)	      to##SLLong
#define Z_APPEND_type_11(to)	      to##sllong
#define Z_INSERT_TYPE_11(left, right) left##SLLONG##right
#define Z_INSERT_Type_11(left, right) left##SLLong##right
#define Z_INSERT_type_11(left, right) left##sllong##right

#define Z_APPEND_TYPE_13(to)	      to##WCHAR
#define Z_APPEND_Type_13(to)	      to##WChar
#define Z_APPEND_type_13(to)	      to##wchar
#define Z_INSERT_TYPE_13(left, right) left##WCHAR##right
#define Z_INSERT_Type_13(left, right) left##WChar##right
#define Z_INSERT_type_13(left, right) left##wchar##right

#define Z_APPEND_TYPE_14(to)	      to##CHAR8
#define Z_APPEND_Type_14(to)	      to##Char8
#define Z_APPEND_type_14(to)	      to##char8
#define Z_INSERT_TYPE_14(left, right) left##CHAR8##right
#define Z_INSERT_Type_14(left, right) left##Char8##right
#define Z_INSERT_type_14(left, right) left##char8##right

#define Z_APPEND_TYPE_15(to)	      to##CHAR16
#define Z_APPEND_Type_15(to)	      to##Char16
#define Z_APPEND_type_15(to)	      to##char16
#define Z_INSERT_TYPE_15(left, right) left##CHAR16##right
#define Z_INSERT_Type_15(left, right) left##Char16##right
#define Z_INSERT_type_15(left, right) left##char16##right

#define Z_APPEND_TYPE_16(to)	      to##CHAR32
#define Z_APPEND_Type_16(to)	      to##Char32
#define Z_APPEND_type_16(to)	      to##char32
#define Z_INSERT_TYPE_16(left, right) left##CHAR32##right
#define Z_INSERT_Type_16(left, right) left##Char32##right
#define Z_INSERT_type_16(left, right) left##char32##right

#define Z_APPEND_TYPE_17(to)	      to##FLOAT
#define Z_APPEND_Type_17(to)	      to##Float
#define Z_APPEND_type_17(to)	      to##float
#define Z_INSERT_TYPE_17(left, right) left##FLOAT##right
#define Z_INSERT_Type_17(left, right) left##Float##right
#define Z_INSERT_type_17(left, right) left##float##right

#define Z_APPEND_TYPE_18(to)	      to##DOUBLE
#define Z_APPEND_Type_18(to)	      to##Double
#define Z_APPEND_type_18(to)	      to##double
#define Z_INSERT_TYPE_18(left, right) left##DOUBLE##right
#define Z_INSERT_Type_18(left, right) left##Double##right
#define Z_INSERT_type_18(left, right) left##double##right

#define Z_APPEND_TYPE_19(to)	      to##LDOUBLE
#define Z_APPEND_Type_19(to)	      to##LDouble
#define Z_APPEND_type_19(to)	      to##ldouble
#define Z_INSERT_TYPE_19(left, right) left##LDOUBLE##right
#define Z_INSERT_Type_19(left, right) left##LDouble##right
#define Z_INSERT_type_19(left, right) left##ldouble##right

#define Z_APPEND_TYPE_20(to)	      to##FLOAT16
#define Z_APPEND_Type_20(to)	      to##Float16
#define Z_APPEND_type_20(to)	      to##float16
#define Z_INSERT_TYPE_20(left, right) left##FLOAT16##right
#define Z_INSERT_Type_20(left, right) left##Float16##right
#define Z_INSERT_type_20(left, right) left##float16##right

#define Z_APPEND_TYPE_21(to)	      to##FLOAT32
#define Z_APPEND_Type_21(to)	      to##Float32
#define Z_APPEND_type_21(to)	      to##float32
#define Z_INSERT_TYPE_21(left, right) left##FLOAT32##right
#define Z_INSERT_Type_21(left, right) left##Float32##right
#define Z_INSERT_type_21(left, right) left##float32##right

#define Z_APPEND_TYPE_22(to)	      to##FLOAT64
#define Z_APPEND_Type_22(to)	      to##Float64
#define Z_APPEND_type_22(to)	      to##float64
#define Z_INSERT_TYPE_22(left, right) left##FLOAT64##right
#define Z_INSERT_Type_22(left, right) left##Float64##right
#define Z_INSERT_type_22(left, right) left##float64##right

#define Z_APPEND_TYPE_23(to)	      to##FLOAT128
#define Z_APPEND_Type_23(to)	      to##Float128
#define Z_APPEND_type_23(to)	      to##float128
#define Z_INSERT_TYPE_23(left, right) left##FLOAT128##right
#define Z_INSERT_Type_23(left, right) left##Float128##right
#define Z_INSERT_type_23(left, right) left##float128##right

#define Z_APPEND_TYPE_24(to)	      to##FLOAT32X
#define Z_APPEND_Type_24(to)	      to##Float32x
#define Z_APPEND_type_24(to)	      to##float32x
#define Z_INSERT_TYPE_24(left, right) left##FLOAT32X##right
#define Z_INSERT_Type_24(left, right) left##Float32x##right
#define Z_INSERT_type_24(left, right) left##float32x##right

#define Z_APPEND_TYPE_25(to)	      to##FLOAT64X
#define Z_APPEND_Type_25(to)	      to##Float64x
#define Z_APPEND_type_25(to)	      to##float64x
#define Z_INSERT_TYPE_25(left, right) left##FLOAT64X##right
#define Z_INSERT_Type_25(left, right) left##Float64x##right
#define Z_INSERT_type_25(left, right) left##float64x##right

#define Z_APPEND_TYPE_26(to)	      to##FLOAT128X
#define Z_APPEND_Type_26(to)	      to##Float128x
#define Z_APPEND_type_26(to)	      to##float128x
#define Z_INSERT_TYPE_26(left, right) left##FLOAT128X##right
#define Z_INSERT_Type_26(left, right) left##Float128x##right
#define Z_INSERT_type_26(left, right) left##float128x##right

#define Z_APPEND_TYPE_27(to)	      to##DECIMAL32
#define Z_APPEND_Type_27(to)	      to##Decimal32
#define Z_APPEND_type_27(to)	      to##decimal32
#define Z_INSERT_TYPE_27(left, right) left##DECIMAL32##right
#define Z_INSERT_Type_27(left, right) left##Decimal32##right
#define Z_INSERT_type_27(left, right) left##decimal32##right

#define Z_APPEND_TYPE_28(to)	      to##DECIMAL64
#define Z_APPEND_Type_28(to)	      to##Decimal64
#define Z_APPEND_type_28(to)	      to##decimal64
#define Z_INSERT_TYPE_28(left, right) left##DECIMAL64##right
#define Z_INSERT_Type_28(left, right) left##Decimal64##right
#define Z_INSERT_type_28(left, right) left##decimal64##right

#define Z_APPEND_TYPE_29(to)	      to##DECIMAL128
#define Z_APPEND_Type_29(to)	      to##Decimal128
#define Z_APPEND_type_29(to)	      to##decimal128
#define Z_INSERT_TYPE_29(left, right) left##DECIMAL128##right
#define Z_INSERT_Type_29(left, right) left##Decimal128##right
#define Z_INSERT_type_29(left, right) left##decimal128##right

#define Z_APPEND_TYPE_30(to)	      to##DECIMAL64X
#define Z_APPEND_Type_30(to)	      to##Decimal64x
#define Z_APPEND_type_30(to)	      to##decimal64x
#define Z_INSERT_TYPE_30(left, right) left##DECIMAL64X##right
#define Z_INSERT_Type_30(left, right) left##Decimal64x##right
#define Z_INSERT_type_30(left, right) left##decimal64x##right

#define Z_APPEND_TYPE_31(to)	      to##DECIMAL128X
#define Z_APPEND_Type_31(to)	      to##Decimal128x
#define Z_APPEND_type_31(to)	      to##decimal128x
#define Z_INSERT_TYPE_31(left, right) left##DECIMAL128X##right
#define Z_INSERT_Type_31(left, right) left##Decimal128x##right
#define Z_INSERT_type_31(left, right) left##decimal128x##right

/* MARK: - Type tokens: Fixed width integral types */

#define Z_APPEND_TYPE_100(to)	       to##UINT8
#define Z_APPEND_Type_100(to)	       to##UInt8
#define Z_APPEND_type_100(to)	       to##uint8
#define Z_INSERT_TYPE_100(left, right) left##UINT8##right
#define Z_INSERT_Type_100(left, right) left##UInt8##right
#define Z_INSERT_type_100(left, right) left##uint8##right

#define Z_APPEND_TYPE_101(to)	       to##SINT8
#define Z_APPEND_Type_101(to)	       to##SInt8
#define Z_APPEND_type_101(to)	       to##sint8
#define Z_INSERT_TYPE_101(left, right) left##SINT8##right
#define Z_INSERT_Type_101(left, right) left##SInt8##right
#define Z_INSERT_type_101(left, right) left##sint8##right

#define Z_APPEND_TYPE_102(to)	       to##UINT16
#define Z_APPEND_Type_102(to)	       to##UInt16
#define Z_APPEND_type_102(to)	       to##uint16
#define Z_INSERT_TYPE_102(left, right) left##UINT16##right
#define Z_INSERT_Type_102(left, right) left##UInt16##right
#define Z_INSERT_type_102(left, right) left##uint16##right

#define Z_APPEND_TYPE_103(to)	       to##SINT16
#define Z_APPEND_Type_103(to)	       to##SInt16
#define Z_APPEND_type_103(to)	       to##sint16
#define Z_INSERT_TYPE_103(left, right) left##SINT16##right
#define Z_INSERT_Type_103(left, right) left##SInt16##right
#define Z_INSERT_type_103(left, right) left##sint16##right

#define Z_APPEND_TYPE_104(to)	       to##UINT24
#define Z_APPEND_Type_104(to)	       to##UInt24
#define Z_APPEND_type_104(to)	       to##uint24
#define Z_INSERT_TYPE_104(left, right) left##UINT24##right
#define Z_INSERT_Type_104(left, right) left##UInt24##right
#define Z_INSERT_type_104(left, right) left##uint24##right

#define Z_APPEND_TYPE_105(to)	       to##SINT24
#define Z_APPEND_Type_105(to)	       to##SInt24
#define Z_APPEND_type_105(to)	       to##sint24
#define Z_INSERT_TYPE_105(left, right) left##SINT24##right
#define Z_INSERT_Type_105(left, right) left##SInt24##right
#define Z_INSERT_type_105(left, right) left##sint24##right

#define Z_APPEND_TYPE_106(to)	       to##UINT32
#define Z_APPEND_Type_106(to)	       to##UInt32
#define Z_APPEND_type_106(to)	       to##uint32
#define Z_INSERT_TYPE_106(left, right) left##UINT32##right
#define Z_INSERT_Type_106(left, right) left##UInt32##right
#define Z_INSERT_type_106(left, right) left##uint32##right

#define Z_APPEND_TYPE_107(to)	       to##SINT32
#define Z_APPEND_Type_107(to)	       to##SInt32
#define Z_APPEND_type_107(to)	       to##sint32
#define Z_INSERT_TYPE_107(left, right) left##SINT32##right
#define Z_INSERT_Type_107(left, right) left##SInt32##right
#define Z_INSERT_type_107(left, right) left##sint32##right

#define Z_APPEND_TYPE_108(to)	       to##UINT40
#define Z_APPEND_Type_108(to)	       to##UInt40
#define Z_APPEND_type_108(to)	       to##uint40
#define Z_INSERT_TYPE_108(left, right) left##UINT40##right
#define Z_INSERT_Type_108(left, right) left##UInt40##right
#define Z_INSERT_type_108(left, right) left##uint40##right

#define Z_APPEND_TYPE_109(to)	       to##SINT40
#define Z_APPEND_Type_109(to)	       to##SInt40
#define Z_APPEND_type_109(to)	       to##sint40
#define Z_INSERT_TYPE_109(left, right) left##SINT40##right
#define Z_INSERT_Type_109(left, right) left##SInt40##right
#define Z_INSERT_type_109(left, right) left##sint40##right

#define Z_APPEND_TYPE_110(to)	       to##UINT48
#define Z_APPEND_Type_110(to)	       to##UInt48
#define Z_APPEND_type_110(to)	       to##uint48
#define Z_INSERT_TYPE_110(left, right) left##UINT48##right
#define Z_INSERT_Type_110(left, right) left##UInt48##right
#define Z_INSERT_type_110(left, right) left##uint48##right

#define Z_APPEND_TYPE_111(to)	       to##SINT48
#define Z_APPEND_Type_111(to)	       to##SInt48
#define Z_APPEND_type_111(to)	       to##sint48
#define Z_INSERT_TYPE_111(left, right) left##SINT48##right
#define Z_INSERT_Type_111(left, right) left##SInt48##right
#define Z_INSERT_type_111(left, right) left##sint48##right

#define Z_APPEND_TYPE_112(to)	       to##UINT56
#define Z_APPEND_Type_112(to)	       to##UInt56
#define Z_APPEND_type_112(to)	       to##uint56
#define Z_INSERT_TYPE_112(left, right) left##UINT56##right
#define Z_INSERT_Type_112(left, right) left##UInt56##right
#define Z_INSERT_type_112(left, right) left##uint56##right

#define Z_APPEND_TYPE_113(to)	       to##SINT56
#define Z_APPEND_Type_113(to)	       to##SInt56
#define Z_APPEND_type_113(to)	       to##sint56
#define Z_INSERT_TYPE_113(left, right) left##SINT56##right
#define Z_INSERT_Type_113(left, right) left##SInt56##right
#define Z_INSERT_type_113(left, right) left##sint56##right

#define Z_APPEND_TYPE_114(to)	       to##UINT64
#define Z_APPEND_Type_114(to)	       to##UInt64
#define Z_APPEND_type_114(to)	       to##uint64
#define Z_INSERT_TYPE_114(left, right) left##UINT64##right
#define Z_INSERT_Type_114(left, right) left##UInt64##right
#define Z_INSERT_type_114(left, right) left##uint64##right

#define Z_APPEND_TYPE_115(to)	       to##SINT64
#define Z_APPEND_Type_115(to)	       to##SInt64
#define Z_APPEND_type_115(to)	       to##sint64
#define Z_INSERT_TYPE_115(left, right) left##SINT64##right
#define Z_INSERT_Type_115(left, right) left##SInt64##right
#define Z_INSERT_type_115(left, right) left##sint64##right

#define Z_APPEND_TYPE_116(to)	       to##UINT128
#define Z_APPEND_Type_116(to)	       to##UInt128
#define Z_APPEND_type_116(to)	       to##uint128
#define Z_INSERT_TYPE_116(left, right) left##UINT128##right
#define Z_INSERT_Type_116(left, right) left##UInt128##right
#define Z_INSERT_type_116(left, right) left##uint128##right

#define Z_APPEND_TYPE_117(to)	       to##SINT128
#define Z_APPEND_Type_117(to)	       to##SInt128
#define Z_APPEND_type_117(to)	       to##sint128
#define Z_INSERT_TYPE_117(left, right) left##SINT128##right
#define Z_INSERT_Type_117(left, right) left##SInt128##right
#define Z_INSERT_type_117(left, right) left##sint128##right

/* MARK: - Type tokens: Fixed format real types */

#define Z_APPEND_TYPE_150(to)	       to##BFP16
#define Z_APPEND_Type_150(to)	       to##BFP16
#define Z_APPEND_type_150(to)	       to##bfp16
#define Z_INSERT_TYPE_150(left, right) left##BFP16##right
#define Z_INSERT_Type_150(left, right) left##BFP16##right
#define Z_INSERT_type_150(left, right) left##bfp16##right

#define Z_APPEND_TYPE_151(to)	       to##BFP32
#define Z_APPEND_Type_151(to)	       to##BFP32
#define Z_APPEND_type_151(to)	       to##bfp32
#define Z_INSERT_TYPE_151(left, right) left##BFP32##right
#define Z_INSERT_Type_151(left, right) left##BFP32##right
#define Z_INSERT_type_151(left, right) left##bfp32##right

#define Z_APPEND_TYPE_152(to)	       to##BFP64
#define Z_APPEND_Type_152(to)	       to##BFP64
#define Z_APPEND_type_152(to)	       to##bfp64
#define Z_INSERT_TYPE_152(left, right) left##BFP64##right
#define Z_INSERT_Type_152(left, right) left##BFP64##right
#define Z_INSERT_type_152(left, right) left##bfp64##right

#define Z_APPEND_TYPE_153(to)	       to##BFP128
#define Z_APPEND_Type_153(to)	       to##BFP128
#define Z_APPEND_type_153(to)	       to##bfp128
#define Z_INSERT_TYPE_153(left, right) left##BFP128##right
#define Z_INSERT_Type_153(left, right) left##BFP128##right
#define Z_INSERT_type_153(left, right) left##bfp128##right

#define Z_APPEND_TYPE_154(to)	       to##DFP32
#define Z_APPEND_Type_154(to)	       to##DFP32
#define Z_APPEND_type_154(to)	       to##dfp32
#define Z_INSERT_TYPE_154(left, right) left##DFP32##right
#define Z_INSERT_Type_154(left, right) left##DFP32##right
#define Z_INSERT_type_154(left, right) left##dfp32##right

#define Z_APPEND_TYPE_155(to)	       to##DFP64
#define Z_APPEND_Type_155(to)	       to##DFP64
#define Z_APPEND_type_155(to)	       to##dfp64
#define Z_INSERT_TYPE_155(left, right) left##DFP64##right
#define Z_INSERT_Type_155(left, right) left##DFP64##right
#define Z_INSERT_type_155(left, right) left##dfp64##right

#define Z_APPEND_TYPE_156(to)	       to##DFP128
#define Z_APPEND_Type_156(to)	       to##DFP128
#define Z_APPEND_type_156(to)	       to##dfp128
#define Z_INSERT_TYPE_156(left, right) left##DFP128##right
#define Z_INSERT_Type_156(left, right) left##DFP128##right
#define Z_INSERT_type_156(left, right) left##dfp128##right

#define Z_APPEND_TYPE_157(to)	       to##X87_DE80
#define Z_APPEND_Type_157(to)	       to##x87_DE80
#define Z_APPEND_type_157(to)	       to##x87_de80
#define Z_INSERT_TYPE_157(left, right) left##X87_DE80##right
#define Z_INSERT_Type_157(left, right) left##x87_DE80##right
#define Z_INSERT_type_157(left, right) left##x87_de80##right

#define Z_APPEND_TYPE_158(to)	       to##X87_DE96
#define Z_APPEND_Type_158(to)	       to##x87_DE96
#define Z_APPEND_type_158(to)	       to##x87_de96
#define Z_INSERT_TYPE_158(left, right) left##X87_DE96##right
#define Z_INSERT_Type_158(left, right) left##x87_DE96##right
#define Z_INSERT_type_158(left, right) left##x87_de96##right

#define Z_APPEND_TYPE_159(to)	       to##X87_DE128
#define Z_APPEND_Type_159(to)	       to##x87_DE128
#define Z_APPEND_type_159(to)	       to##x87_de128
#define Z_INSERT_TYPE_159(left, right) left##X87_DE128##right
#define Z_INSERT_Type_159(left, right) left##x87_DE128##right
#define Z_INSERT_type_159(left, right) left##x87_de128##right

/* MARK: - Number format tokens: Fixed format real types */

#define Z_INSERT_NUMBER_FORMAT_28(left, right) left##IEEE_754_BINARY16##right
#define Z_INSERT_NUMBER_FORMAT_29(left, right) left##IEEE_754_BINARY32##right
#define Z_INSERT_NUMBER_FORMAT_30(left, right) left##IEEE_754_BINARY64##right
#define Z_INSERT_NUMBER_FORMAT_31(left, right) left##IEEE_754_BINARY128##right
#define Z_INSERT_NUMBER_FORMAT_32(left, right) left##IEEE_754_DECIMAL32##right
#define Z_INSERT_NUMBER_FORMAT_33(left, right) left##IEEE_754_DECIMAL64##right
#define Z_INSERT_NUMBER_FORMAT_34(left, right) left##IEEE_754_DECIMAL128##right
#define Z_INSERT_NUMBER_FORMAT_35(left, right) left##X87_DOUBLE_EXTENDED##right

/* MARK: - Macro selectors */

#define Z_PREPEND_TYPE(FUNDAMENTAL) Z_JOIN_2(Z_PREPEND_TYPE_, FUNDAMENTAL)
#define Z_PREPEND_Type(FUNDAMENTAL) Z_JOIN_2(Z_PREPEND_Type_, FUNDAMENTAL)
#define Z_PREPEND_type(FUNDAMENTAL) Z_JOIN_2(Z_PREPEND_type_, FUNDAMENTAL)
#define Z_APPEND_TYPE( FUNDAMENTAL) Z_JOIN_2(Z_APPEND_TYPE_,  FUNDAMENTAL)
#define Z_APPEND_Type( FUNDAMENTAL) Z_JOIN_2(Z_APPEND_Type_,  FUNDAMENTAL)
#define Z_APPEND_type( FUNDAMENTAL) Z_JOIN_2(Z_APPEND_type_,  FUNDAMENTAL)
#define Z_INSERT_TYPE( FUNDAMENTAL) Z_JOIN_2(Z_INSERT_TYPE_,  FUNDAMENTAL)
#define Z_INSERT_Type( FUNDAMENTAL) Z_JOIN_2(Z_INSERT_Type_,  FUNDAMENTAL)
#define Z_INSERT_type( FUNDAMENTAL) Z_JOIN_2(Z_INSERT_type_,  FUNDAMENTAL)

#define Z_INSERT_NUMBER_FORMAT(NUMBER_FORMAT) Z_JOIN_2(Z_INSERT_NUMBER_FORMAT_, NUMBER_FORMAT)

#endif /* Z_macros_templating_H */
