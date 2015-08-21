/* Z Kit C API - formats/data model/SILP64.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_formats_data_model_SILP64_Ha__
#define __Z_formats_data_model_SILP64_Ha__

#include <Z/keys/value.h>

#define Z_SILP64_BITS_CHAR	  8
#define Z_SILP64_BITS_SHORT	 64
#define Z_SILP64_BITS_INT	 64
#define Z_SILP64_BITS_LONG	 64
#define Z_SILP64_BITS_LLONG	 64
#define Z_SILP64_BITS_POINTER	 64
#define Z_SILP64_BITS_SIZE	 64

#define Z_ILP32_TYPE_UINT8
#define Z_ILP32_TYPE_UINT16
#define Z_ILP32_TYPE_UINT32
#define Z_ILP32_TYPE_UINT64
#define Z_ILP32_TYPE_SIZE
#define Z_ILP32_TYPE_INT8
#define Z_ILP32_TYPE_INT16
#define Z_ILP32_TYPE_INT32
#define Z_ILP32_TYPE_INT64
#define Z_ILP32_TYPE_SSIZE

#define Z_SILP64_BASE_TYPE_UINT8
#define Z_SILP64_BASE_TYPE_UINT16
#define Z_SILP64_BASE_TYPE_UINT32
#define Z_SILP64_BASE_TYPE_UINT64
#define Z_SILP64_BASE_TYPE_INT8
#define Z_SILP64_BASE_TYPE_INT16
#define Z_SILP64_BASE_TYPE_INT32
#define Z_SILP64_BASE_TYPE_INT64

#define Z_SILP64_SUFFIX_UINT8
#define Z_SILP64_SUFFIX_UINT16
#define Z_SILP64_SUFFIX_UINT32
#define Z_SILP64_SUFFIX_UINT64
#define Z_SILP64_SUFFIX_INT8
#define Z_SILP64_SUFFIX_INT16
#define Z_SILP64_SUFFIX_INT32
#define Z_SILP64_SUFFIX_INT64

#endif /* __Z_formats_data_model_SILP64_Ha__ */

#ifdef Z_INSPECTING_DATA_MODEL
#	ifndef __Z_formats_data_model_SILP64_Hb__
#	define __Z_formats_data_model_SILP64_Hb__

#	undef SILP64
#	undef silp64

#	define Z_DATA_MODEL_NAME SILP64
#	define Z_DATA_MODEL_Name SILP64
#	define Z_DATA_MODEL_name silp64

#	endif /* __Z_formats_data_model_SILP64_Hb__ */
#endif
