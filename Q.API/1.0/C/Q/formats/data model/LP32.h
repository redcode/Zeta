/* Q API - formats/data model/LP32.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2012 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v2. */

#ifndef __Q_formats_data_model_LP32_H__
#define __Q_formats_data_model_LP32_H__

#include <Q/keys/type.h>

#define Q_LP32_BITS_CHAR		 8
#define Q_LP32_BITS_SHORT		16
#define Q_LP32_BITS_INT			16
#define Q_LP32_BITS_LONG		32
#define Q_LP32_BITS_LLONG		64
#define Q_LP32_BITS_POINTER		32
#define Q_LP32_BITS_SIZE		32

#define Q_LP32_TYPE_UINT88		unsigned char
#define Q_LP32_TYPE_UINT16		unsigned short int
#define Q_LP32_TYPE_UINT32		unsigned long int
#define Q_LP32_TYPE_UINT64		unsigned long long int
#define Q_LP32_TYPE_SIZE		unsigned long int
#define Q_LP32_TYPE_INT8		signed char
#define Q_LP32_TYPE_INT16		signed short int
#define Q_LP32_TYPE_INT32		signed long int
#define Q_LP32_TYPE_INT64		signed long long int
#define Q_LP32_TYPE_SSIZE		signed long int

#define Q_LP32_BASE_TYPE_UINT8		Q_TYPE_UCHAR
#define Q_LP32_BASE_TYPE_UINT16		Q_TYPE_USHORT
#define Q_LP32_BASE_TYPE_UINT32		Q_TYPE_ULONG
#define Q_LP32_BASE_TYPE_UINT64		Q_TYPE_ULLONG
#define Q_LP32_BASE_TYPE_INT8		Q_TYPE_CHAR
#define Q_LP32_BASE_TYPE_INT16		Q_TYPE_SHORT
#define Q_LP32_BASE_TYPE_INT32		Q_TYPE_LONG
#define Q_LP32_BASE_TYPE_INT64		Q_TYPE_LLONG

#define Q_LP32_SUFFIX_UINT8
#define Q_LP32_SUFFIX_UINT16
#define Q_LP32_SUFFIX_UINT32		UL
#define Q_LP32_SUFFIX_UINT64		ULL
#define Q_LP32_SUFFIX_INT8
#define Q_LP32_SUFFIX_INT16
#define Q_LP32_SUFFIX_INT32		L
#define Q_LP32_SUFFIX_INT64		LL

#define Q_LP32_LITERAL_UINT8( value)	value
#define Q_LP32_LITERAL_UINT16(value)	value
#define Q_LP32_LITERAL_UINT32(value)	value##UL
#define Q_LP32_LITERAL_UINT64(value)	value##ULL
#define Q_LP32_LITERAL_INT8(  value)	value
#define Q_LP32_LITERAL_INT16( value)	value
#define Q_LP32_LITERAL_INT32( value)	value##L
#define Q_LP32_LITERAL_INT64( value)	value##LL

#endif /* __Q_formats_data_model_LP32_H__ */
