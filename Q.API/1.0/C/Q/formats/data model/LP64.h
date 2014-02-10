/* Q API - formats/data model/LP64.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2014 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_formats_data_model_LP64_H__
#define __Q_formats_data_model_LP64_H__

#include <Q/keys/value.h>

#define Q_LP64_BITS_CHAR		 8
#define Q_LP64_BITS_SHORT		16
#define Q_LP64_BITS_INT			32
#define Q_LP64_BITS_LONG		64
#define Q_LP64_BITS_LLONG		64
#define Q_LP64_BITS_POINTER		64
#define Q_LP64_BITS_SIZE		64

#define Q_LP64_TYPE_UINT8		unsigned char
#define Q_LP64_TYPE_UINT16		unsigned short int
#define Q_LP64_TYPE_UINT32		unsigned int
#define Q_LP64_TYPE_UINT64		unsigned long int
#define Q_LP64_TYPE_SIZE		unsigned long int
#define Q_LP64_TYPE_INT8		signed char
#define Q_LP64_TYPE_INT16		signed short int
#define Q_LP64_TYPE_INT32		signed int
#define Q_LP64_TYPE_INT64		signed long int
#define Q_LP64_TYPE_SSIZE		signed long int

#define Q_LP64_BASE_TYPE_UINT8		Q_VALUE_TYPE_UCHAR
#define Q_LP64_BASE_TYPE_UINT16		Q_VALUE_TYPE_USHORT
#define Q_LP64_BASE_TYPE_UINT32		Q_VALUE_TYPE_UINT
#define Q_LP64_BASE_TYPE_UINT64		Q_VALUE_TYPE_ULONG
#define Q_LP64_BASE_TYPE_INT8		Q_VALUE_TYPE_CHAR
#define Q_LP64_BASE_TYPE_INT16		Q_VALUE_TYPE_SHORT
#define Q_LP64_BASE_TYPE_INT32		Q_VALUE_TYPE_INT
#define Q_LP64_BASE_TYPE_INT64		Q_VALUE_TYPE_LONG

#define Q_LP64_SUFFIX_UINT8
#define Q_LP64_SUFFIX_UINT16
#define Q_LP64_SUFFIX_UINT32
#define Q_LP64_SUFFIX_UINT64		UL
#define Q_LP64_SUFFIX_INT8
#define Q_LP64_SUFFIX_INT16
#define Q_LP64_SUFFIX_INT32
#define Q_LP64_SUFFIX_INT64		L

#define Q_LP64_LITERAL_UINT8( value)	value
#define Q_LP64_LITERAL_UINT16(value)	value
#define Q_LP64_LITERAL_UINT32(value)	value
#define Q_LP64_LITERAL_UINT64(value)	value##UL
#define Q_LP64_LITERAL_INT8(  value)	value
#define Q_LP64_LITERAL_INT16( value)	value
#define Q_LP64_LITERAL_INT32( value)	value
#define Q_LP64_LITERAL_INT64( value)	value##L

#endif /* __Q_formats_data_model_LP64_H__ */

#ifdef Q_INSPECTING

#	define Q_DATA_MODEL_NAME LP64
#	define Q_DATA_MODEL_Name LP64
#	define Q_DATA_MODEL_name lp64

#endif
