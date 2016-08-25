/* Z Kit C API - formats/data model/SILP64.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_formats_data_model_SILP64_H__
#define __Z_formats_data_model_SILP64_H__

#define Z_SILP64_BITS_UCHAR   8
#define Z_SILP64_BITS_USHORT  64
#define Z_SILP64_BITS_UINT    64
#define Z_SILP64_BITS_ULONG   64
#define Z_SILP64_BITS_ULLONG  64
#define Z_SILP64_BITS_SIZE    64
#define Z_SILP64_BITS_CHAR    8
#define Z_SILP64_BITS_SHORT   64
#define Z_SILP64_BITS_INT     64
#define Z_SILP64_BITS_LONG    64
#define Z_SILP64_BITS_LLONG   64
#define Z_SILP64_BITS_SSIZE   64
#define Z_SILP64_BITS_POINTER 64

#endif /* __Z_formats_data_model_SILP64_H__ */

#ifdef Z_INSPECTING_DATA_MODEL

#	ifndef __Z_formats_data_model_SILP64_H__INSPECTION
#	define __Z_formats_data_model_SILP64_H__INSPECTION

#	define Z_PASTE_DATA_MODEL(left, right) left##SILP64##right
#	define Z_PASTE_data_model(left, right) left##silp64##right

#	endif /* __Z_formats_data_model_SILP64_H__INSPECTION */

#endif
