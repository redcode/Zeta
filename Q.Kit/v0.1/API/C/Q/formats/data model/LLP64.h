/* Q API - formats/data model/LLP64.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_formats_data_model_LLP64_Ha__
#define __Q_formats_data_model_LLP64_Ha__

#include <Q/keys/value.h>

#define Q_LLP64_BITS_CHAR	  8
#define Q_LLP64_BITS_SHORT	 16
#define Q_LLP64_BITS_INT	 32
#define Q_LLP64_BITS_LONG	 32
#define Q_LLP64_BITS_LLONG	 64
#define Q_LLP64_BITS_POINTER	 64
#define Q_LLP64_BITS_SIZE	 64

#define Q_LLP64_TYPE_UINT8	 unsigned char
#define Q_LLP64_TYPE_UINT16	 unsigned short int
#define Q_LLP64_TYPE_UINT32	 unsigned int
#define Q_LLP64_TYPE_UINT64	 unsigned long long int
#define Q_LLP64_TYPE_SIZE	 unsigned long long int
#define Q_LLP64_TYPE_INT8	 signed char
#define Q_LLP64_TYPE_INT16	 signed short int
#define Q_LLP64_TYPE_INT32	 signed int
#define Q_LLP64_TYPE_INT64	 signed long long int
#define Q_LLP64_TYPE_SSIZE	 signed long long int

#define Q_LLP64_BASE_TYPE_UINT8	 Q_VALUE_TYPE_UCHAR
#define Q_LLP64_BASE_TYPE_UINT16 Q_VALUE_TYPE_USHORT
#define Q_LLP64_BASE_TYPE_UINT32 Q_VALUE_TYPE_UINT
#define Q_LLP64_BASE_TYPE_UINT64 Q_VALUE_TYPE_ULLONG
#define Q_LLP64_BASE_TYPE_INT8	 Q_VALUE_TYPE_CHAR
#define Q_LLP64_BASE_TYPE_INT16	 Q_VALUE_TYPE_SHORT
#define Q_LLP64_BASE_TYPE_INT32	 Q_VALUE_TYPE_INT
#define Q_LLP64_BASE_TYPE_INT64	 Q_VALUE_TYPE_LLONG

#define Q_LLP64_SUFFIX_UINT8
#define Q_LLP64_SUFFIX_UINT16
#define Q_LLP64_SUFFIX_UINT32
#define Q_LLP64_SUFFIX_UINT64	 ULL
#define Q_LLP64_SUFFIX_INT8
#define Q_LLP64_SUFFIX_INT16
#define Q_LLP64_SUFFIX_INT32
#define Q_LLP64_SUFFIX_INT64	 LL

#endif /* __Q_formats_data_model_LLP64_Ha__ */

#ifdef Q_INSPECTING
#	ifndef __Q_formats_data_model_LLP64_Hb__
#	define __Q_formats_data_model_LLP64_Hb__

#	undef LLP64
#	undef llp64

#	define Q_DATA_MODEL_NAME LLP64
#	define Q_DATA_MODEL_Name LLP64
#	define Q_DATA_MODEL_name llp64

#	endif /* __Q_formats_data_model_LLP64_Hb__ */
#endif
