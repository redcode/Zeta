/* Z Kit C API - inspection/data model.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_inspection_data_model_H__
#define __Z_inspection_data_model_H__

#define Z_INSPECTING_DATA_MODEL

#	if defined(Z_USE_DATA_MODEL_LP32)
#		include <Z/formats/data model/LP32.h>

#	elif defined(Z_USE_DATA_MODEL_ILP32)
#		include <Z/formats/data model/ILP32.h>

#	elif defined(Z_USE_DATA_MODEL_ILP64)
#		include <Z/formats/data model/ILP64.h>

#	elif defined(Z_USE_DATA_MODEL_LLP64)
#		include <Z/formats/data model/LLP64.h>

#	elif defined(Z_USE_DATA_MODEL_LP64)
#		include <Z/formats/data model/LP64.h>

#	else
#		if	defined(__LP32__) || \
			defined(__LP32)	  || \
			defined(_LP32_)	  || \
			defined(_LP32)
#			include <Z/formats/data model/LP32.h>

#		elif	defined(__ILP32__) || \
			defined(__ILP32)   || \
			defined(_ILP32_)   || \
			defined(_ILP32)	   || \
			defined(_WIN32)
#			include <Z/formats/data model/ILP32.h>

#		elif	defined(__ILP64__) || \
			defined(__ILP64)   || \
			defined(_ILP64_)   || \
			defined(_ILP64)
#			include <Z/formats/data model/ILP64.h>

#		elif	defined(__LLP64__) || \
			defined(__LLP64)   || \
			defined(_LLP64_)   || \
			defined(_LLP64)	   || \
			defined(_WIN64)
#			include <Z/formats/data model/LLP64.h>

#		elif	defined(__LP64__) || \
			defined(__LP64)	  || \
			defined(_LP64_)	  || \
			defined(_LP64)
#			include <Z/formats/data model/LP64.h>

#		else
#			include <Z/formats/data model/ILP32.h>
#		endif
#	endif

#undef Z_INSPECTING_DATA_MODEL

#include <Z/macros/preprocessor.h>
#include <Z/keys/data model.h>

#undef _BITS_
#undef _TYPE_
#undef _BASE_TYPE_
#undef _SUFFIX_
#undef SUFFIX_

#define Z_DATA_MODEL		     Z_JOIN_2(Z_DATA_MODEL_, Z_DATA_MODEL_NAME)
#define Z_DATA_MODEL_STRING	     Z_JOIN_2(Z_DATA_MODEL_STRING_, Z_DATA_MODEL_NAME)
#define Z_DATA_MODEL_BITS(     TYPE) Z_JOIN_4(Z_, Z_DATA_MODEL_NAME, _BITS_, TYPE)
#define Z_DATA_MODEL_TYPE(     TYPE) Z_JOIN_4(Z_, Z_DATA_MODEL_NAME, _TYPE_, TYPE)
#define Z_DATA_MODEL_BASE_TYPE(TYPE) Z_JOIN_4(Z_, Z_DATA_MODEL_NAME, _BASE_TYPE_, TYPE)
#define Z_DATA_MODEL_SUFFIX(   TYPE) Z_JOIN_4(Z_, Z_DATA_MODEL_NAME, _SUFFIX_, TYPE)
#define Z_DATA_MODEL_LITERAL(  TYPE) Z_JOIN_3(Z_, SUFFIX_, Z_DATA_MODEL_SUFFIX(TYPE))

#endif /* __Z_inspection_data_model_H__ */
