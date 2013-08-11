/* Q API - inspection/data model.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2013 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_inspection_data_model_H__
#define __Q_inspection_data_model_H__

/*------------------------------------------------------.
| Type		|  LP32 | ILP32 | ILP64 | LLP64 |  LP64 |
|---------------+-------+-------+-------+-------+-------|
| char		|     8 |     8 |     8 |     8 |     8 |
|---------------+-------+-------+-------+-------+-------|
| short int	|    16 |    16 |    16 |    16 |    16 |
|---------------+-------+-------+-------+-------+-------|
| int		|    16 |    32 |    64 |    32 |    32 |
|---------------+-------+-------+-------+-------+-------|
| long int	|    32 |    32 |    64 |    32 |    64 |
|---------------+-------+-------+-------+-------+-------|
| long long int	|    64 |    64 |    64 |    64 |    64 |
|---------------+-------+-------+-------+-------+-------|
| pointer	|    32 |    32 |    64 |    64 |    64 |
|---------------+-------+-------+-------+-------+-------|
| size_t	|    32 |    32 |    64 |    64 |    64 |
'------------------------------------------------------*/

#if defined(Q_USE_DATA_MODEL_LP32)

#	define Q_DATA_MODEL_NAME LP32

#elif defined(Q_USE_DATA_MODEL_ILP32)

#	define Q_DATA_MODEL_NAME ILP32

#elif defined(Q_USE_DATA_MODEL_ILP64)

#	define Q_DATA_MODEL_NAME ILP64

#elif defined(Q_USE_DATA_MODEL_LLP64)

#	define Q_DATA_MODEL_NAME LLP64

#elif defined(Q_USE_DATA_MODEL_LP64)

#	define Q_DATA_MODEL_NAME LP64

#else

#	if	defined(__LP32__)	|| \
		defined(_LP32_)		|| \
		defined(_LP32)		|| \
		defined(LP32)

#		define Q_DATA_MODEL_NAME LP32

#	elif	defined(__ILP32__)	|| \
		defined(_ILP32_)	|| \
		defined(_ILP32)		|| \
		defined(ILP32)		|| \
		defined(_WIN32)

#		define Q_DATA_MODEL_NAME ILP32

#	elif	defined(__ILP64__)	|| \
		defined(_ILP64_)	|| \
		defined(_ILP64)		|| \
		defined(ILP64)

#		define Q_DATA_MODEL_NAME ILP64

#	elif	defined(__LLP64__)	|| \
		defined(_LLP64_)	|| \
		defined(_LLP64)		|| \
		defined(LLP64)		|| \
		defined(_WIN64)

#		define Q_DATA_MODEL_NAME LLP64

#	elif	defined(__LP64__)	|| \
		defined(_LP64_)		|| \
		defined(_LP64)		|| \
		defined(LP64)

#		define Q_DATA_MODEL_NAME LP64

#	else
#		define Q_DATA_MODEL_NAME ILP32
#	endif

#endif

#define Q_DATA_MODEL_HEADER		<Q/formats/data model/Q_DATA_MODEL_NAME.h>

#include Q_DATA_MODEL_HEADER
#include <Q/macros/preprocessor.h>
#include <Q/keys/data model.h>

#define Q_DATA_MODEL			Q_JOIN_2(Q_DATA_MODEL_, Q_DATA_MODEL_NAME)
#define Q_DATA_MODEL_STRING		Q_JOIN_2(Q_DATA_MODEL_STRING_, Q_DATA_MODEL_NAME)
#define Q_DATA_MODEL_BITS(type)		Q_JOIN_4(Q_, Q_DATA_MODEL_NAME, _BITS_, type)
#define Q_DATA_MODEL_TYPE(type)		Q_JOIN_4(Q_, Q_DATA_MODEL_NAME, _TYPE_, type)
#define Q_DATA_MODEL_BASE_TYPE(type)	Q_JOIN_4(Q_, Q_DATA_MODEL_NAME, _BASE_TYPE_, type)
#define Q_DATA_MODEL_SUFFIX(type)	Q_JOIN_4(Q_, Q_DATA_MODEL_NAME, _SUFFIX_, type)
#define Q_DATA_MODEL_LITERAL(type)	Q_JOIN_4(Q_, Q_DATA_MODEL_NAME, _LITERAL_, type)

#endif /* __Q_inspection_data_model_H__ */
