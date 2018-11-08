/* Z Kit - keys/value.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_keys_value_H_
#define _Z_keys_value_H_

/* Standard C/C++ base types */

#define Z_VALUE_TYPE_POINTER	    0
#define Z_VALUE_TYPE_CHAR	    1 /* char			 */
#define Z_VALUE_TYPE_UCHAR	    2 /* unsigned char		 */
#define Z_VALUE_TYPE_USHORT	    3 /* unsigned short int	 */
#define Z_VALUE_TYPE_UINT	    4 /* unsigned int		 */
#define Z_VALUE_TYPE_ULONG	    5 /* unsigned long int	 */
#define Z_VALUE_TYPE_ULLONG	    6 /* unsigned long long int	 */
#define Z_VALUE_TYPE_SCHAR	    7 /* signed char		 */
#define Z_VALUE_TYPE_SSHORT	    8 /* signed short int	 */
#define Z_VALUE_TYPE_SINT	    9 /* signed int		 */
#define Z_VALUE_TYPE_SLONG	   10 /* signed long int	 */
#define Z_VALUE_TYPE_SLLONG	   11 /* signed long long int	 */
#define Z_VALUE_TYPE_FLOAT	   12 /* float			 */
#define Z_VALUE_TYPE_DOUBLE	   13 /* double			 */
#define Z_VALUE_TYPE_LDOUBLE	   14 /* long double		 */
#define Z_VALUE_TYPE_BOOLEAN	   15 /* (C) _Bool / (C++) bool	 */
#define Z_VALUE_TYPE_WCHAR	   16 /* (C++) wchar_t		 */
#define Z_VALUE_TYPE_CHAR16	   17 /* (C++) char16_t		 */
#define Z_VALUE_TYPE_CHAR32	   18 /* (C++) char32_t		 */
#define Z_VALUE_TYPE_NULL_POINTER  19 /* (C++) decltype(nullptr) */
#define Z_VALUE_TYPE_UINT8	  128
#define Z_VALUE_TYPE_SINT8	  129
#define Z_VALUE_TYPE_UINT16	  130 /* Base type in SILP64 data model only. */
#define Z_VALUE_TYPE_SINT16	  131 /* Base type in SILP64 data model only. */
#define Z_VALUE_TYPE_UINT32	  132 /* Base type in ILP64 and SILP64 data models only. */
#define Z_VALUE_TYPE_SINT32	  133 /* Base type in ILP64 and SILP64 data models only. */
#define Z_VALUE_TYPE_UINT64	  134
#define Z_VALUE_TYPE_SINT64	  135
#define Z_VALUE_TYPE_UINT128	  136
#define Z_VALUE_TYPE_SINT128	  137
#define Z_VALUE_TYPE_FLOAT16	  192
#define Z_VALUE_TYPE_FLOAT32	  193
#define Z_VALUE_TYPE_FLOAT64	  194
#define Z_VALUE_TYPE_FLOAT128	  195
#define Z_VALUE_TYPE_FLOAT80_X87  196
#define Z_VALUE_TYPE_FLOAT96_X87  197
#define Z_VALUE_TYPE_FLOAT128_X87 198

#define Z_KEY_INDEX_VALUE_TYPE_FIXED_NATURAL 128 
#define Z_KEY_INDEX_VALUE_TYPE_FIXED_INTEGER 160
#define Z_KEY_INDEX_VALUE_TYPE_FIXED_REAL    192
#define Z_KEY_BITS_VALUE_TYPE		     8
#define Z_KEY_LAST_VALUE_TYPE		     Z_VALUE_TYPE_FLOAT128_X87

#define Z_INTEGER_FORMAT_1S_COMPLEMENT 0
#define Z_INTEGER_FORMAT_2S_COMPLEMENT 1

#define Z_KEY_BITS_INTEGER_FORMAT 8
#define Z_KEY_LAST_INTEGER_FORMAT Z_INTEGER_FORMAT_2S_COMPLEMENT

#define Z_VALUE_FORMAT_8BIT_NATURAL		     1
#define Z_VALUE_FORMAT_16BIT_NATURAL		     2
#define Z_VALUE_FORMAT_32BIT_NATURAL		     3
#define Z_VALUE_FORMAT_64BIT_NATURAL		     4
#define Z_VALUE_FORMAT_128BIT_NATURAL		     5
#define Z_VALUE_FORMAT_8BIT_2S_COMPLEMENT_INTEGER    6
#define Z_VALUE_FORMAT_16BIT_2S_COMPLEMENT_INTEGER   7
#define Z_VALUE_FORMAT_32BIT_2S_COMPLEMENT_INTEGER   8
#define Z_VALUE_FORMAT_64BIT_2S_COMPLEMENT_INTEGER   9
#define Z_VALUE_FORMAT_128BIT_2S_COMPLEMENT_INTEGER 10
#define Z_VALUE_FORMAT_IEEE_754_BINARY16	    11
#define Z_VALUE_FORMAT_IEEE_754_BINARY32	    12
#define Z_VALUE_FORMAT_IEEE_754_BINARY64	    13
#define Z_VALUE_FORMAT_IEEE_754_BINARY128	    14
#define Z_VALUE_FORMAT_IEEE_754_BINARY256	    15
#define Z_VALUE_FORMAT_IEEE_754_DECIMAL32	    16
#define Z_VALUE_FORMAT_IEEE_754_DECIMAL64	    17
#define Z_VALUE_FORMAT_IEEE_754_DECIMAL128	    18
#define Z_VALUE_FORMAT_X87_BINARY80		    19
#define Z_VALUE_FORMAT_X87_BINARY96		    20
#define Z_VALUE_FORMAT_X87_BINARY128		    21

#define Z_KEY_BITS_VALUE_FORMAT	8
#define Z_KEY_LAST_VALUE_FORMAT	Z_VALUE_FORMAT_INTEL_FLOAT128

#endif /* _Z_keys_value_H_ */
