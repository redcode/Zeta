/* Z Kit C API - formats/data model/SILP64.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_formats_data_model_SILP64_H__
#define __Z_formats_data_model_SILP64_H__

#include <Z/keys/value.h>

#define Z_SILP64_BITS_CHAR    8
#define Z_SILP64_BITS_SHORT   64
#define Z_SILP64_BITS_INT     64
#define Z_SILP64_BITS_LONG    64
#define Z_SILP64_BITS_LLONG   64
#define Z_SILP64_BITS_POINTER 64
#define Z_SILP64_BITS_SIZE    64

#define Z_SILP32_TYPE_UINT8  unsigned char
#define Z_SILP32_TYPE_UINT16 unsigned short int
#define Z_SILP32_TYPE_UINT32 unsigned short int
#define Z_SILP32_TYPE_UINT64 unsigned short int
#define Z_SILP32_TYPE_SIZE   unsigned short int
#define Z_SILP32_TYPE_INT8   signed char
#define Z_SILP32_TYPE_INT16  signed short int
#define Z_SILP32_TYPE_INT32  signed short int
#define Z_SILP32_TYPE_INT64  signed short int
#define Z_SILP32_TYPE_SSIZE  signed short int

#define Z_SILP64_VALUE_TYPE_UINT8  Z_VALUE_TYPE_UCHAR
#define Z_SILP64_VALUE_TYPE_UINT16 /* ? */
#define Z_SILP64_VALUE_TYPE_UINT32 /* ? */
#define Z_SILP64_VALUE_TYPE_UINT64 Z_VALUE_TYPE_USHORT
#define Z_SILP64_VALUE_TYPE_INT8   Z_VALUE_TYPE_CHAR
#define Z_SILP64_VALUE_TYPE_INT16  /* ? */
#define Z_SILP64_VALUE_TYPE_INT32  /* ? */
#define Z_SILP64_VALUE_TYPE_INT64  Z_VALUE_TYPE_SHORT

#endif /* __Z_formats_data_model_SILP64_H__ */

#ifdef Z_INSPECTING_DATA_MODEL

#	ifndef __Z_formats_data_model_SILP64_H__INSPECTION
#	define __Z_formats_data_model_SILP64_H__INSPECTION

#	define Z_DATA_MODEL_SUFFIX_UINT8  Z_SUFFIX_U
#	define Z_DATA_MODEL_SUFFIX_UINT16 Z_SUFFIX_U
#	define Z_DATA_MODEL_SUFFIX_UINT32 Z_SUFFIX_U
#	define Z_DATA_MODEL_SUFFIX_UINT64 Z_SUFFIX_U
#	define Z_DATA_MODEL_SUFFIX_INT8	  Z_SAME
#	define Z_DATA_MODEL_SUFFIX_INT16  Z_SAME
#	define Z_DATA_MODEL_SUFFIX_INT32  Z_SAME
#	define Z_DATA_MODEL_SUFFIX_INT64  Z_SAME

#	define Z_PASTE_DATA_MODEL(left, right) left##SILP64##right
#	define Z_PASTE_data_model(left, right) left##silp64##right

#	define Z_IS_DEFINED_INSERT_DATA_MODEL(left, right) \
		(defined left##SILP64##right)

#	endif /* __Z_formats_data_model_SILP64_H__INSPECTION */

#endif
