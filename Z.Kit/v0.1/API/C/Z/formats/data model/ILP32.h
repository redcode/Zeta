/* Z Kit C API - formats/data model/ILP32.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_formats_data_model_ILP32_Ha__
#define __Z_formats_data_model_ILP32_Ha__

#include <Z/keys/value.h>

#define Z_ILP32_BITS_CHAR     8
#define Z_ILP32_BITS_SHORT   16
#define Z_ILP32_BITS_INT     32
#define Z_ILP32_BITS_LONG    32
#define Z_ILP32_BITS_LLONG   64
#define Z_ILP32_BITS_POINTER 32
#define Z_ILP32_BITS_SIZE    32
	
#define Z_ILP32_TYPE_UINT8  unsigned char
#define Z_ILP32_TYPE_UINT16 unsigned short int
#define Z_ILP32_TYPE_UINT32 unsigned int
#define Z_ILP32_TYPE_UINT64 unsigned long long int
#define Z_ILP32_TYPE_SIZE   unsigned long int
#define Z_ILP32_TYPE_INT8   signed char
#define Z_ILP32_TYPE_INT16  signed short int
#define Z_ILP32_TYPE_INT32  signed int
#define Z_ILP32_TYPE_INT64  signed long long int
#define Z_ILP32_TYPE_SSIZE  signed long int

#define Z_ILP32_VALUE_TYPE_UINT8  Z_VALUE_TYPE_UCHAR
#define Z_ILP32_VALUE_TYPE_UINT16 Z_VALUE_TYPE_USHORT
#define Z_ILP32_VALUE_TYPE_UINT32 Z_VALUE_TYPE_UINT
#define Z_ILP32_VALUE_TYPE_UINT64 Z_VALUE_TYPE_ULLONG
#define Z_ILP32_VALUE_TYPE_INT8	  Z_VALUE_TYPE_CHAR
#define Z_ILP32_VALUE_TYPE_INT16  Z_VALUE_TYPE_SHORT
#define Z_ILP32_VALUE_TYPE_INT32  Z_VALUE_TYPE_INT
#define Z_ILP32_VALUE_TYPE_INT64  Z_VALUE_TYPE_LLONG

#endif /* __Z_formats_data_model_ILP32_Ha__ */

#ifdef Z_INSPECTING_DATA_MODEL
#	ifndef __Z_formats_data_model_ILP32_Hb__
#	define __Z_formats_data_model_ILP32_Hb__

#	define Z_DATA_MODEL	  Z_DATA_MODEL_ILP32
#	define Z_DATA_MODE_STRING Z_DATA_MODEL_STRING_ILP32

#	define Z_DATA_MODEL_SUFFIX_UINT8  Z_SAME
#	define Z_DATA_MODEL_SUFFIX_UINT16 Z_SAME
#	define Z_DATA_MODEL_SUFFIX_UINT32 Z_SAME
#	define Z_DATA_MODEL_SUFFIX_UINT64 Z_SUFFIX_ULL
#	define Z_DATA_MODEL_SUFFIX_INT8	  Z_SAME
#	define Z_DATA_MODEL_SUFFIX_INT16  Z_SAME
#	define Z_DATA_MODEL_SUFFIX_INT32  Z_SAME
#	define Z_DATA_MODEL_SUFFIX_INT64  Z_SUFFIX_LL

#	define Z_INSERT_DATA_MODEL(left, right) left##ILP32##right
#	define Z_INSERT_data_model(left, right) left##ilp32##right

#	endif /* __Z_formats_data_model_ILP32_Hb__ */
#endif
