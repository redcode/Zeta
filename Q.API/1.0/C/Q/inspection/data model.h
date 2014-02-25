/* Q API - inspection/data model.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2014 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_inspection_data_model_H__
#define __Q_inspection_data_model_H__

#define Q_INSPECTING

#if defined(Q_USE_DATA_MODEL_LP32)
#	include <Q/formats/data model/LP32.h>

#elif defined(Q_USE_DATA_MODEL_ILP32)
#	include <Q/formats/data model/ILP32.h>

#elif defined(Q_USE_DATA_MODEL_ILP64)
#	include <Q/formats/data model/ILP64.h>

#elif defined(Q_USE_DATA_MODEL_LLP64)
#	include <Q/formats/data model/LLP64.h>

#elif defined(Q_USE_DATA_MODEL_LP64)
#	include <Q/formats/data model/LP64.h>

#else

#	if	defined(__LP32__)  || \
		defined(__LP32)    || \
		defined(_LP32_)    || \
		defined(_LP32)

#		include <Q/formats/data model/LP32.h>

#	elif	defined(__ILP32__) || \
		defined(__ILP32)   || \
		defined(_ILP32_)   || \
		defined(_ILP32)    || \
		defined(_WIN32)

#		include <Q/formats/data model/ILP32.h>

#	elif	defined(__ILP64__) || \
		defined(__ILP64)   || \
		defined(_ILP64_)   || \
		defined(_ILP64)

#		include <Q/formats/data model/ILP64.h>

#	elif	defined(__LLP64__) || \
		defined(__LLP64)   || \
		defined(_LLP64_)   || \
		defined(_LLP64)    || \
		defined(_WIN64)

#		include <Q/formats/data model/LLP64.h>

#	elif	defined(__LP64__)  || \
		defined(__LP64)    || \
		defined(_LP64_)    || \
		defined(_LP64)

#		include <Q/formats/data model/LP64.h>

#	else
#		include <Q/formats/data model/ILP32.h>
#	endif

#endif

#undef Q_INSPECTING

#include <Q/macros/preprocessor.h>
#include <Q/keys/data model.h>

#undef Q_
#undef _BITS_
#undef _TYPE_
#undef _BASE_TYPE_
#undef _SUFFIX_
#undef SUFFIX_

#define Q_DATA_MODEL		     Q_JOIN_2(Q_DATA_MODEL_, Q_DATA_MODEL_NAME)
#define Q_DATA_MODEL_STRING	     Q_JOIN_2(Q_DATA_MODEL_STRING_, Q_DATA_MODEL_NAME)
#define Q_DATA_MODEL_BITS(     TYPE) Q_JOIN_4(Q_, Q_DATA_MODEL_NAME, _BITS_, TYPE)
#define Q_DATA_MODEL_TYPE(     TYPE) Q_JOIN_4(Q_, Q_DATA_MODEL_NAME, _TYPE_, TYPE)
#define Q_DATA_MODEL_BASE_TYPE(TYPE) Q_JOIN_4(Q_, Q_DATA_MODEL_NAME, _BASE_TYPE_, TYPE)
#define Q_DATA_MODEL_SUFFIX(   TYPE) Q_JOIN_4(Q_, Q_DATA_MODEL_NAME, _SUFFIX_, TYPE)
#define Q_DATA_MODEL_LITERAL(  TYPE) Q_JOIN_3(Q_, SUFFIX_, Q_DATA_MODEL_SUFFIX(TYPE))

#endif /* __Q_inspection_data_model_H__ */
