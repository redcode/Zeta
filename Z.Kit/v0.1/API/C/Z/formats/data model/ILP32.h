/* Z Kit C API - formats/data model/ILP32.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_formats_data_model_ILP32_H__
#define __Z_formats_data_model_ILP32_H__

#define Z_ILP32_BITS_UCHAR    8
#define Z_ILP32_BITS_USHORT  16
#define Z_ILP32_BITS_UINT    32
#define Z_ILP32_BITS_ULONG   32
#define Z_ILP32_BITS_ULLONG  64
#define Z_ILP32_BITS_SIZE    32
#define Z_ILP32_BITS_CHAR     8
#define Z_ILP32_BITS_SHORT   16
#define Z_ILP32_BITS_INT     32
#define Z_ILP32_BITS_LONG    32
#define Z_ILP32_BITS_LLONG   64
#define Z_ILP32_BITS_SSIZE   32
#define Z_ILP32_BITS_POINTER 32
	
#endif /* __Z_formats_data_model_ILP32_H__ */

#ifdef Z_INSPECTING_DATA_MODEL

#	ifndef __Z_formats_data_model_ILP32_H__INSPECTION
#	define __Z_formats_data_model_ILP32_H__INSPECTION

#	define Z_INSERT_DATA_MODEL(left, right) left##ILP32##right
#	define Z_INSERT_data_model(left, right) left##ilp32##right

#	endif /* __Z_formats_data_model_ILP32_H__INSPECTION */

#endif
