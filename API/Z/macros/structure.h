/* Z Kit - macros/structure.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_macros_structure_H_
#define _Z_macros_structure_H_

#include <Z/macros/language.h>

#if	!defined(Z_AVOID_VARIADIC_MACROS) && \
	(Z_LANGUAGE_HAS(C, VARIADIC_MACRO) || Z_LANGUAGE_HAS(CPP, C99_PREPROCESSOR))

#	define Z_STRICT_STRUCTURE(...)					\
		Z_STRICT_SIZE_BEGIN					\
		struct {__VA_ARGS__}					\
		Z_STRICT_SIZE_END

#	define Z_STRICT_UNION(...)					\
		Z_STRICT_SIZE_BEGIN					\
		union {__VA_ARGS__}					\
		Z_STRICT_SIZE_END

#	define Z_DEFINE_STRICT_STRUCTURE(...)				\
		Z_STRICT_SIZE_BEGIN					\
		typedef struct {__VA_ARGS__}				\
		Z_STRICT_SIZE_END

#	define Z_DEFINE_STRICT_UNION(...)				\
		Z_STRICT_SIZE_BEGIN					\
		typedef union {__VA_ARGS__}				\
		Z_STRICT_SIZE_END

#	ifdef __cplusplus
#		define Z_DEFINE_STRUCTURE_WITH_NAME(name, ...)		\
			typedef struct name {__VA_ARGS__} name
#	else
#		define Z_DEFINE_STRUCTURE_WITH_NAME(name, ...)		\
			typedef struct name name;			\
			struct name {__VA_ARGS__}
#	endif

#	define Z_DEFINE_STRICT_STRUCTURE_WITH_NAME(name, ...)		\
		Z_STRICT_SIZE_BEGIN					\
		Z_DEFINE_STRUCTURE_WITH_NAME(name, __VA_ARGS__)		\
		Z_STRICT_SIZE_END

#else

#	define Z_STRICT_STRUCTURE(members)				\
		Z_STRICT_SIZE_BEGIN					\
		struct {members}					\
		Z_STRICT_SIZE_END

#	define Z_STRICT_UNION(members)					\
		Z_STRICT_SIZE_BEGIN					\
		union {members}						\
		Z_STRICT_SIZE_END

#	define Z_DEFINE_STRICT_STRUCTURE(members)			\
		Z_STRICT_SIZE_BEGIN					\
		typedef struct {members}				\
		Z_STRICT_SIZE_END

#	define Z_DEFINE_STRICT_UNION(members)				\
		Z_STRICT_SIZE_BEGIN					\
		typedef union {members}					\
		Z_STRICT_SIZE_END

#	ifdef __cplusplus
#		define Z_DEFINE_STRUCTURE_WITH_NAME(name, members)	\
			typedef struct name {members} name
#	else
#		define Z_DEFINE_STRUCTURE_WITH_NAME(name, ...)		\
			typedef struct name name;			\
			struct name {members}
#	endif

#	define Z_DEFINE_STRICT_STRUCTURE_WITH_NAME(name, members)	\
		Z_STRICT_SIZE_BEGIN					\
		Z_DEFINE_STRUCTURE_WITH_NAME(name, members)		\
		Z_STRICT_SIZE_END

#endif

#define Z_STRICT_STRUCTURE_BEGIN Z_STRICT_SIZE_BEGIN struct {
#define Z_STRICT_STRUCTURE_END	 } Z_STRICT_SIZE_END
#define Z_STRICT_UNION_BEGIN	 Z_STRICT_SIZE_BEGIN union {
#define Z_STRICT_UNION_END	 } Z_STRICT_SIZE_END

#define Z_DEFINE_STRICT_STRUCTURE_BEGIN Z_STRICT_SIZE_BEGIN typedef struct {
#define Z_DEFINE_STRICT_STRUCTURE_END	} Z_STRICT_SIZE_END
#define Z_DEFINE_STRICT_UNION_BEGIN	Z_STRICT_SIZE_BEGIN typedef union {
#define Z_DEFINE_STRICT_UNION_END	} Z_STRICT_SIZE_END

#if Z_LANGUAGE_HAS(C, FLEXIBLE_ARRAY_MEMBER)
#	define Z_FLEXIBLE_ARRAY_MEMBER(member) member
#else
#	define Z_FLEXIBLE_ARRAY_MEMBER(member)
#endif

#endif /* _Z_macros_structure_H_ */
