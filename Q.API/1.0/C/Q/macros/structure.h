/* Q API - macros/structure.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2014 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_macros_structure_H__
#define __Q_macros_structure_H__

#include <Q/inspection/C.h>

#if !defined(Q_AVOID_VARIADIC_MACROS) && Q_C_HAS(VARIADIC_MACRO)

#	define Q_STRICT_STRUCTURE(...)					\
		Q_BEGIN_STRICT_SIZE					\
		struct {__VA_ARGS__}					\
		Q_END_STRICT_SIZE

#	define Q_STRICT_UNION(...)					\
		Q_BEGIN_STRICT_SIZE					\
		union {__VA_ARGS__}					\
		Q_END_STRICT_SIZE

#	define Q_DEFINE_STRICT_STRUCTURE(...)				\
		Q_BEGIN_STRICT_SIZE					\
		typedef struct {__VA_ARGS__}				\
		Q_END_STRICT_SIZE

#	define Q_DEFINE_STRICT_UNION(...)				\
		Q_BEGIN_STRICT_SIZE					\
		typedef union {__VA_ARGS__}				\
		Q_END_STRICT_SIZE

#	define Q_DEFINE_STRUCTURE_WITH_NAME(name, ...)			\
		typedef struct name name;				\
		struct name {__VA_ARGS__}

#	define Q_DEFINE_STRICT_STRUCTURE_WITH_NAME(name, ...)		\
		Q_BEGIN_STRICT_SIZE					\
		Q_DEFINE_STRUCTURE_WITH_NAME(name, __VA_ARGS__)		\
		Q_END_STRICT_SIZE

#else

#	define Q_STRICT_STRUCTURE(members)				\
		Q_BEGIN_STRICT_SIZE					\
		struct {members}					\
		Q_END_STRICT_SIZE

#	define Q_STRICT_UNION(members)					\
		Q_BEGIN_STRICT_SIZE					\
		union {__VA_ARGS__}					\
		Q_END_STRICT_SIZE

#	define Q_DEFINE_STRICT_STRUCTURE(members)			\
		Q_BEGIN_STRICT_SIZE					\
		typedef struct {members}				\
		Q_END_STRICT_SIZE

#	define Q_DEFINE_STRICT_UNION(members)				\
		Q_BEGIN_STRICT_SIZE					\
		typedef union {members}					\
		Q_END_STRICT_SIZE

#	define Q_DEFINE_STRUCTURE_WITH_NAME(name, members)		\
		typedef struct name name;				\
		struct name {members}

#	define Q_DEFINE_STRICT_STRUCTURE_WITH_NAME(name, members)	\
		Q_BEGIN_STRICT_SIZE					\
		Q_DEFINE_STRUCTURE_WITH_NAME(name, members)		\
		Q_END_STRICT_SIZE

#endif

#define Q_BEGIN_DEFINE_STRICT_STRUCTURE Q_BEGIN_STRICT_SIZE typedef struct {
#define Q_END_DEFINE_STRICT_UNION	} Q_END_STRICT_SIZE
#define Q_BEGIN_DEFINE_STRICT_UNION	Q_BEGIN_STRICT_SIZE typedef union {
#define Q_END_DEFINE_STRICT_UNION	} Q_END_STRICT_SIZE

#if Q_COMPILER_HAS_FUNCTION(OFFSETOF)
#	define Q_STRUCTURE_MEMBER_OFFSET Q_COMPILER_FUNCTION(OFFSETOF)
#else
#	define Q_STRUCTURE_MEMBER_OFFSET(type, member) ((unsigned long)&((type *)(0))->member)
#endif

#endif /* __Q_macros_structure_H__ */
