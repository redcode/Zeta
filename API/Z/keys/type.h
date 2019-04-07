/* Z Kit - keys/type.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2019 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_keys_type_H
#define Z_keys_type_H

/* MARK: - Standard C/C++ fundamental types */

#define Z_FUNDAMENTAL_VOID	    1
#define Z_FUNDAMENTAL_POINTER	    2
#define Z_FUNDAMENTAL_CHAR	    3 /* char				    */
#define Z_FUNDAMENTAL_UCHAR	    4 /* unsigned char			    */
#define Z_FUNDAMENTAL_SCHAR	    5 /* signed char			    */
#define Z_FUNDAMENTAL_USHORT	    6 /* unsigned short int		    */
#define Z_FUNDAMENTAL_SSHORT	    7 /* signed short int		    */
#define Z_FUNDAMENTAL_UINT	    8 /* unsigned int			    */
#define Z_FUNDAMENTAL_SINT	    9 /* signed int			    */
#define Z_FUNDAMENTAL_ULONG	   10 /* unsigned long int		    */
#define Z_FUNDAMENTAL_SLONG	   11 /* signed long int		    */
#define Z_FUNDAMENTAL_ULLONG	   12 /* (C99/C++11) unsigned long long int */
#define Z_FUNDAMENTAL_SLLONG	   13 /* (C99/C++11) signed long long int   */
#define Z_FUNDAMENTAL_FLOAT	   14 /* float				    */
#define Z_FUNDAMENTAL_DOUBLE	   15 /* double				    */
#define Z_FUNDAMENTAL_LDOUBLE	   16 /* long double			    */
#define Z_FUNDAMENTAL_BOOL	   17 /* (C99) _Bool / (C++98) bool	    */
#define Z_FUNDAMENTAL_WCHAR	   18 /* (C++98) wchar_t		    */
#define Z_FUNDAMENTAL_CHAR8	   19 /* char8_t			    */
#define Z_FUNDAMENTAL_CHAR16	   20 /* (C++11) char16_t		    */
#define Z_FUNDAMENTAL_CHAR32	   21 /* (C++11) char32_t		    */
#define Z_FUNDAMENTAL_FLOAT16	   22 /* _Float16			    */
#define Z_FUNDAMENTAL_FLOAT32	   23 /* _Float32			    */
#define Z_FUNDAMENTAL_FLOAT64	   24 /* _Float64			    */
#define Z_FUNDAMENTAL_FLOAT128	   25 /* _Float128			    */
#define Z_FUNDAMENTAL_FLOAT32X	   26 /* _Float32x			    */
#define Z_FUNDAMENTAL_FLOAT64X	   27 /* _Float64x			    */
#define Z_FUNDAMENTAL_FLOAT128X	   28 /* _Float128x			    */
#define Z_FUNDAMENTAL_DECIMAL32	   29 /* _Decimal32			    */
#define Z_FUNDAMENTAL_DECIMAL64	   30 /* _Decimal64			    */
#define Z_FUNDAMENTAL_DECIMAL128   31 /* _Decimal128			    */
#define Z_FUNDAMENTAL_DECIMAL64X   30 /* _Decimal64x			    */
#define Z_FUNDAMENTAL_DECIMAL128X  31 /* _Decimal128x			    */
#define Z_FUNDAMENTAL_NULLPTR	   32 /* (C++11) decltype(nullptr)	    */

/* MARK: - Fixed width integral types */

#define Z_FUNDAMENTAL_UINT8	  100 /* 8-bit natural	 */
#define Z_FUNDAMENTAL_SINT8	  101 /* 8-bit integer	 */
#define Z_FUNDAMENTAL_UINT16	  102 /* 16-bit natural	 */
#define Z_FUNDAMENTAL_SINT16	  103 /* 16-bit integer	 */
#define Z_FUNDAMENTAL_UINT24	  104 /* 24-bit natural	 */
#define Z_FUNDAMENTAL_SINT24	  105 /* 24-bit integer	 */
#define Z_FUNDAMENTAL_UINT32	  106 /* 32-bit natural	 */
#define Z_FUNDAMENTAL_SINT32	  107 /* 32-bit integer	 */
#define Z_FUNDAMENTAL_UINT40	  108 /* 40-bit natural	 */
#define Z_FUNDAMENTAL_SINT40	  109 /* 40-bit integer	 */
#define Z_FUNDAMENTAL_UINT48	  110 /* 48-bit natural	 */
#define Z_FUNDAMENTAL_SINT48	  111 /* 48-bit integer	 */
#define Z_FUNDAMENTAL_UINT56	  112 /* 56-bit natural	 */
#define Z_FUNDAMENTAL_SINT56	  113 /* 56-bit integer	 */
#define Z_FUNDAMENTAL_UINT64	  114 /* 64-bit natural	 */
#define Z_FUNDAMENTAL_SINT64	  115 /* 64-bit integer	 */
#define Z_FUNDAMENTAL_UINT128	  116 /* 128-bit natural */
#define Z_FUNDAMENTAL_SINT128	  117 /* 128-bit integer */

/* MARK: - Fixed format real types */

#define Z_FUNDAMENTAL_BFP16	  150 /* IEEE 754 binary16				  */
#define Z_FUNDAMENTAL_BFP32	  151 /* IEEE 754 binary32				  */
#define Z_FUNDAMENTAL_BFP64	  152 /* IEEE 754 binary64				  */
#define Z_FUNDAMENTAL_BFP128	  153 /* IEEE 754 binary128				  */
#define Z_FUNDAMENTAL_DFP32	  154 /* IEEE 754 decimal32				  */
#define Z_FUNDAMENTAL_DFP64	  155 /* IEEE 754 decimal64				  */
#define Z_FUNDAMENTAL_DFP128	  156 /* IEEE 754 decimal128				  */
#define Z_FUNDAMENTAL_BFLOAT16	  157
#define Z_FUNDAMENTAL_X87_DE80	  158 /* 80-bit x87 double extended			  */
#define Z_FUNDAMENTAL_X87_DE96	  159 /* 80-bit x87 double extended (with 16-bit padding) */
#define Z_FUNDAMENTAL_X87_DE128	  160 /* 80-bit x87 double extended (with 48-bit padding) */
#define Z_FUNDAMENTAL_ARM_FP16	  161

#endif /* Z_keys_type_H */
