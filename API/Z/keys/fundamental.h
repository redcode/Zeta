/* Zeta API - Z/keys/fundamental.h
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_keys_fundamental_H
#define Z_keys_fundamental_H

/* MARK: - Standard C/C++ fundamental types */

#define Z_FUNDAMENTAL_VOID	   0
#define Z_FUNDAMENTAL_CHAR	   1 /* char				   */
#define Z_FUNDAMENTAL_UCHAR	   2 /* unsigned char			   */
#define Z_FUNDAMENTAL_SCHAR	   3 /* signed char			   */
#define Z_FUNDAMENTAL_USHORT	   4 /* unsigned short int		   */
#define Z_FUNDAMENTAL_SSHORT	   5 /* signed short int		   */
#define Z_FUNDAMENTAL_UINT	   6 /* unsigned int			   */
#define Z_FUNDAMENTAL_SINT	   7 /* signed int			   */
#define Z_FUNDAMENTAL_ULONG	   8 /* unsigned long int		   */
#define Z_FUNDAMENTAL_SLONG	   9 /* signed long int			   */
#define Z_FUNDAMENTAL_ULLONG	  10 /* (C99/C++11) unsigned long long int */
#define Z_FUNDAMENTAL_SLLONG	  11 /* (C99/C++11) signed long long int   */
#define Z_FUNDAMENTAL_BOOL	  12 /* (C99) _Bool / (C++98) bool	   */
#define Z_FUNDAMENTAL_WCHAR	  13 /* (C++98) wchar_t			   */
#define Z_FUNDAMENTAL_CHAR8	  14 /* (C++20) char8_t			   */
#define Z_FUNDAMENTAL_CHAR16	  15 /* (C++11) char16_t		   */
#define Z_FUNDAMENTAL_CHAR32	  16 /* (C++11) char32_t		   */
#define Z_FUNDAMENTAL_FLOAT	  17 /* float				   */
#define Z_FUNDAMENTAL_DOUBLE	  18 /* double				   */
#define Z_FUNDAMENTAL_LDOUBLE	  19 /* long double			   */
#define Z_FUNDAMENTAL_FLOAT16	  20 /* _Float16			   */
#define Z_FUNDAMENTAL_FLOAT32	  21 /* _Float32			   */
#define Z_FUNDAMENTAL_FLOAT64	  22 /* _Float64			   */
#define Z_FUNDAMENTAL_FLOAT128	  23 /* _Float128			   */
#define Z_FUNDAMENTAL_FLOAT32X	  24 /* _Float32x			   */
#define Z_FUNDAMENTAL_FLOAT64X	  25 /* _Float64x			   */
#define Z_FUNDAMENTAL_FLOAT128X	  26 /* _Float128x			   */
#define Z_FUNDAMENTAL_DECIMAL32	  27 /* _Decimal32			   */
#define Z_FUNDAMENTAL_DECIMAL64	  28 /* _Decimal64			   */
#define Z_FUNDAMENTAL_DECIMAL128  29 /* _Decimal128			   */
#define Z_FUNDAMENTAL_DECIMAL64X  30 /* _Decimal64x			   */
#define Z_FUNDAMENTAL_DECIMAL128X 31 /* _Decimal128x			   */
#define Z_FUNDAMENTAL_NULLPTR	  32 /* (C++11) decltype(nullptr)	   */

/* MARK: - Fixed width integral types */

#define Z_FUNDAMENTAL_UINT8	 100 /*   8-bit natural */
#define Z_FUNDAMENTAL_SINT8	 101 /*   8-bit integer */
#define Z_FUNDAMENTAL_UINT16	 102 /*  16-bit natural */
#define Z_FUNDAMENTAL_SINT16	 103 /*  16-bit integer */
#define Z_FUNDAMENTAL_UINT24	 104 /*  24-bit natural */
#define Z_FUNDAMENTAL_SINT24	 105 /*  24-bit integer */
#define Z_FUNDAMENTAL_UINT32	 106 /*  32-bit natural */
#define Z_FUNDAMENTAL_SINT32	 107 /*  32-bit integer */
#define Z_FUNDAMENTAL_UINT40	 108 /*  40-bit natural */
#define Z_FUNDAMENTAL_SINT40	 109 /*  40-bit integer */
#define Z_FUNDAMENTAL_UINT48	 110 /*  48-bit natural */
#define Z_FUNDAMENTAL_SINT48	 111 /*  48-bit integer */
#define Z_FUNDAMENTAL_UINT56	 112 /*  56-bit natural */
#define Z_FUNDAMENTAL_SINT56	 113 /*  56-bit integer */
#define Z_FUNDAMENTAL_UINT64	 114 /*  64-bit natural */
#define Z_FUNDAMENTAL_SINT64	 115 /*  64-bit integer */
#define Z_FUNDAMENTAL_UINT128	 116 /* 128-bit natural */
#define Z_FUNDAMENTAL_SINT128	 117 /* 128-bit integer */

/* MARK: - Fixed format real types */

#define Z_FUNDAMENTAL_BFP16	 150 /* IEEE 754 binary16			  */
#define Z_FUNDAMENTAL_BFP32	 151 /* IEEE 754 binary32			  */
#define Z_FUNDAMENTAL_BFP64	 152 /* IEEE 754 binary64			  */
#define Z_FUNDAMENTAL_BFP128	 153 /* IEEE 754 binary128			  */
#define Z_FUNDAMENTAL_DFP32	 154 /* IEEE 754 decimal32			  */
#define Z_FUNDAMENTAL_DFP64	 155 /* IEEE 754 decimal64			  */
#define Z_FUNDAMENTAL_DFP128	 156 /* IEEE 754 decimal128			  */
#define Z_FUNDAMENTAL_X87_DE80	 157 /* x87 double extended			  */
#define Z_FUNDAMENTAL_X87_DE96	 158 /* x87 double extended (with 16-bit padding) */
#define Z_FUNDAMENTAL_X87_DE128	 159 /* x87 double extended (with 48-bit padding) */
#define Z_FUNDAMENTAL_IBM_ED	 160 /* IBM extended double			  */
#define Z_FUNDAMENTAL_BFLOAT16	 162 /* Brain Floating-Point			  */

#endif /* Z_keys_fundamental_H */
