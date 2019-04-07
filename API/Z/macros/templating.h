/* Z Kit - macros/templating.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2019 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_macros_templating_H
#define Z_macros_templating_H

/* MARK: - Standard C types */

#define Z_APPEND_TYPE_3(to)	       to##CHAR
#define Z_APPEND_Type_3(to)	       to##Char
#define Z_APPEND_type_3(to)	       to##char
#define Z_INSERT_TYPE_3(left, right)   left##CHAR##right
#define Z_INSERT_Type_3(left, right)   left##Char##right
#define Z_INSERT_type_3(left, right)   left##char##right

#define Z_APPEND_TYPE_4(to)	       to##UCHAR
#define Z_APPEND_Type_4(to)	       to##UChar
#define Z_APPEND_type_4(to)	       to##uchar
#define Z_INSERT_TYPE_4(left, right)   left##UCHAR##right
#define Z_INSERT_Type_4(left, right)   left##UChar##right
#define Z_INSERT_type_4(left, right)   left##uchar##right

#define Z_APPEND_TYPE_5(to)	       to##SCHAR
#define Z_APPEND_Type_5(to)	       to##SChar
#define Z_APPEND_type_5(to)	       to##schar
#define Z_INSERT_TYPE_5(left, right)   left##SCHAR##right
#define Z_INSERT_Type_5(left, right)   left##SChar##right
#define Z_INSERT_type_5(left, right)   left##schar##right

#define Z_APPEND_TYPE_6(to)	       to##USHORT
#define Z_APPEND_Type_6(to)	       to##UShort
#define Z_APPEND_type_6(to)	       to##ushort
#define Z_INSERT_TYPE_6(left, right)   left##USHORT##right
#define Z_INSERT_Type_6(left, right)   left##UShort##right
#define Z_INSERT_type_6(left, right)   left##ushort##right

#define Z_APPEND_TYPE_7(to)	       to##SSHORT
#define Z_APPEND_Type_7(to)	       to##SShort
#define Z_APPEND_type_7(to)	       to##sshort
#define Z_INSERT_TYPE_7(left, right)   left##SSHORT##right
#define Z_INSERT_Type_7(left, right)   left##SShort##right
#define Z_INSERT_type_7(left, right)   left##sshort##right

#define Z_APPEND_TYPE_8(to)	       to##UINT
#define Z_APPEND_Type_8(to)	       to##UInt
#define Z_APPEND_type_8(to)	       to##uint
#define Z_INSERT_TYPE_8(left, right)   left##UINT##right
#define Z_INSERT_Type_8(left, right)   left##UInt##right
#define Z_INSERT_type_8(left, right)   left##uint##right

#define Z_APPEND_TYPE_9(to)	       to##SINT
#define Z_APPEND_Type_9(to)	       to##SInt
#define Z_APPEND_type_9(to)	       to##sint
#define Z_INSERT_TYPE_9(left, right)   left##SINT##right
#define Z_INSERT_Type_9(left, right)   left##SInt##right
#define Z_INSERT_type_9(left, right)   left##sint##right

#define Z_APPEND_TYPE_10(to)	       to##ULONG
#define Z_APPEND_Type_10(to)	       to##ULong
#define Z_APPEND_type_10(to)	       to##ulong
#define Z_INSERT_TYPE_10(left, right)  left##ULONG##right
#define Z_INSERT_Type_10(left, right)  left##ULong##right
#define Z_INSERT_type_10(left, right)  left##ulong##right

#define Z_APPEND_TYPE_11(to)	       to##SLONG
#define Z_APPEND_Type_11(to)	       to##SLong
#define Z_APPEND_type_11(to)	       to##slong
#define Z_INSERT_TYPE_11(left, right)  left##SLONG##right
#define Z_INSERT_Type_11(left, right)  left##SLong##right
#define Z_INSERT_type_11(left, right)  left##slong##right

#define Z_APPEND_TYPE_12(to)	       to##ULLONG
#define Z_APPEND_Type_12(to)	       to##ULLong
#define Z_APPEND_type_12(to)	       to##ullong
#define Z_INSERT_TYPE_12(left, right)  left##ULLONG##right
#define Z_INSERT_Type_12(left, right)  left##ULLong##right
#define Z_INSERT_type_12(left, right)  left##ullong##right

#define Z_APPEND_TYPE_13(to)	       to##SLLONG
#define Z_APPEND_Type_13(to)	       to##SLLong
#define Z_APPEND_type_13(to)	       to##sllong
#define Z_INSERT_TYPE_13(left, right)  left##SLLONG##right
#define Z_INSERT_Type_13(left, right)  left##SLLong##right
#define Z_INSERT_type_13(left, right)  left##sllong##right

#define Z_APPEND_TYPE_14(to)	       to##FLOAT
#define Z_APPEND_Type_14(to)	       to##Float
#define Z_APPEND_type_14(to)	       to##float
#define Z_INSERT_TYPE_14(left, right)  left##FLOAT##right
#define Z_INSERT_Type_14(left, right)  left##Float##right
#define Z_INSERT_type_14(left, right)  left##float##right

#define Z_APPEND_TYPE_15(to)	       to##DOUBLE
#define Z_APPEND_Type_15(to)	       to##Double
#define Z_APPEND_type_15(to)	       to##double
#define Z_INSERT_TYPE_15(left, right)  left##DOUBLE##right
#define Z_INSERT_Type_15(left, right)  left##Double##right
#define Z_INSERT_type_15(left, right)  left##double##right

#define Z_APPEND_TYPE_16(to)	       to##LDOUBLE
#define Z_APPEND_Type_16(to)	       to##LDouble
#define Z_APPEND_type_16(to)	       to##ldouble
#define Z_INSERT_TYPE_16(left, right)  left##LDOUBLE##right
#define Z_INSERT_Type_16(left, right)  left##LDouble##right
#define Z_INSERT_type_16(left, right)  left##ldouble##right

#define Z_APPEND_TYPE_17(to)	       to##BOOLEAN
#define Z_APPEND_Type_17(to)	       to##Boolean
#define Z_APPEND_type_17(to)	       to##boolean
#define Z_INSERT_TYPE_17(left, right)  left##BOOLEAN##right
#define Z_INSERT_Type_17(left, right)  left##Boolean##right
#define Z_INSERT_type_17(left, right)  left##boolean##right

/* MARK: - Fixed width integral types */

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

/* MARK: - Fixed format floating-point types */

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

#define Z_INSERT_NUMBER_FORMAT_28(left, right) left##IEEE_754_BINARY16##right
#define Z_INSERT_NUMBER_FORMAT_29(left, right) left##IEEE_754_BINARY32##right
#define Z_INSERT_NUMBER_FORMAT_30(left, right) left##IEEE_754_BINARY64##right
#define Z_INSERT_NUMBER_FORMAT_31(left, right) left##IEEE_754_BINARY128##right
#define Z_INSERT_NUMBER_FORMAT_32(left, right) left##IEEE_754_DECIMAL32##right
#define Z_INSERT_NUMBER_FORMAT_33(left, right) left##IEEE_754_DECIMAL64##right
#define Z_INSERT_NUMBER_FORMAT_34(left, right) left##IEEE_754_DECIMAL128##right
#define Z_INSERT_NUMBER_FORMAT_35(left, right) left##X87_DOUBLE_EXTENDED##right

/* MARK: - Macro selectors */

#define Z_APPEND_BASE_TYPE(    TYPE) Z_JOIN_2(Z_APPEND_TYPE_,	       TYPE##_FUNDAMENTAL      )
#define Z_APPEND_BaseType(     TYPE) Z_JOIN_2(Z_APPEND_Type_,	       TYPE##_FUNDAMENTAL      )
#define Z_APPEND_base_type(    TYPE) Z_JOIN_2(Z_APPEND_type_,	       TYPE##_FUNDAMENTAL      )
#define Z_APPEND_FIXED_TYPE(   TYPE) Z_JOIN_2(Z_APPEND_TYPE_,	       TYPE##_FIXED_FUNDAMENTAL)
#define Z_APPEND_FixedType(    TYPE) Z_JOIN_2(Z_APPEND_Type_,	       TYPE##_FIXED_FUNDAMENTAL)
#define Z_APPEND_fixed_type(   TYPE) Z_JOIN_2(Z_APPEND_type_,	       TYPE##_FIXED_FUNDAMENTAL)
#define Z_INSERT_BASE_TYPE(    TYPE) Z_JOIN_2(Z_INSERT_TYPE_,	       TYPE##_FUNDAMENTAL      )
#define Z_INSERT_BaseType(     TYPE) Z_JOIN_2(Z_INSERT_Type_,	       TYPE##_FUNDAMENTAL      )
#define Z_INSERT_base_type(    TYPE) Z_JOIN_2(Z_INSERT_type_,	       TYPE##_FUNDAMENTAL      )
#define Z_INSERT_FIXED_TYPE(   TYPE) Z_JOIN_2(Z_INSERT_TYPE_,	       TYPE##_FIXED_FUNDAMENTAL)
#define Z_INSERT_FixedType(    TYPE) Z_JOIN_2(Z_INSERT_Type_,	       TYPE##_FIXED_FUNDAMENTAL)
#define Z_INSERT_fixed_type(   TYPE) Z_JOIN_2(Z_INSERT_type_,	       TYPE##_FIXED_FUNDAMENTAL)
#define Z_INSERT_NUMBER_FORMAT(TYPE) Z_JOIN_2(Z_INSERT_NUMBER_FORMAT_, TYPE##_NUMBER_FORMAT    )

#endif /* Z_macros_templating_H */
