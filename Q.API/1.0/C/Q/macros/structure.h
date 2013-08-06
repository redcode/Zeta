/* Q API - macros/structure.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2012 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_macros_structure_H__
#define __Q_macros_structure_H__

#include <Q/inspection/compiler.h>

#define Q_DEFINE_STRICT_STRUCTURE	Q_STRICT_SIZE_BEGIN typedef struct {__VA_ARGS__} Q_STRICT_SIZE_END
#define Q_DEFINE_STRICT_UNION		Q_STRICT_SIZE_BEGIN typedef union  {__VA_ARGS__} Q_STRICT_SIZE_END

#define Q_STRICT_STRUCTURE		Q_STRICT_SIZE_BEGIN struct {__VA_ARGS__} Q_STRICT_SIZE_END
#define Q_STRICT_UNION			Q_STRICT_SIZE_BEGIN union  {__VA_ARGS__} Q_STRICT_SIZE_END

#define Q_DEFINE_STRUCTURE_WITH_NAME(name, ...)	\
	typedef struct name name;		\
	struct name {__VA_ARGS__}

#define Q_DEFINE_STRICT_STRUCTURE_WITH_NAME(name, ...)	\
	Q_STRICT_SIZE_BEGIN				\
	Q_DEFINE_STRUCTURE_WITH_NAME(name, __VA_ARGS__)
	Q_STRICT_SIZE_END

#if Q_COMPILER_HAS_FUNCTION(OFFSETOF)
#	define Q_STRUCTURE_MEMBER_OFFSET		Q_COMPILER_FUNCTION(OFFSETOF)
#else
#	define Q_STRUCTURE_MEMBER_OFFSET(type, member)	((unsigned long)&((type *)(0))->member)
#endif

#endif /* __Q_macros_structure_H__ */
