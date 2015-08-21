/* Z Kit C API - macros/node.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_macros_node_H__
#define __Z_macros_node_H__

#include <Z/macros/structure.h>

#if !defined(Z_AVOID_VARIADIC_MACROS) && Z_LANGUAGE_HAS(VARIADIC_MACRO)

#	define Z_DEFINE_LIST_NODE(type, ...)				\
		Z_DEFINE_STRUCTURE_WITH_NAME (type,			\
			type *next;					\
			__VA_ARGS__					\
		)

#	define Z_DEFINE_STRICT_LIST_NODE(type, ...)			\
		Z_DEFINE_STRICT_STRUCTURE_WITH_NAME (type,		\
			type *next;					\
			__VA_ARGS__					\
		)

#	define Z_DEFINE_CHAIN_NODE(type, ...)				\
		Z_DEFINE_STRUCTURE_WITH_NAME (type,			\
			type *next, *previous;				\
			__VA_ARGS__					\
		)

#	define Z_DEFINE_STRICT_CHAIN_NODE(type, ...)			\
		Z_DEFINE_STRICT_STRUCTURE_WITH_NAME (type,		\
			type *next, *previous;				\
			__VA_ARGS__					\
		)

#	define Z_DEFINE_TREE_NODE(type, ...)				\
		Z_DEFINE_STRUCTURE_WITH_NAME (type,			\
			type *next, *previous, *parent, *children;	\
			__VA_ARGS__					\
		)

#	define Z_DEFINE_STRICT_TREE_NODE(type, ...)			\
		Z_DEFINE_STRICT_STRUCTURE_WITH_NAME (type,		\
			type *next, *previous, *parent, *children;	\
			__VA_ARGS__					\
		)

#	define Z_DEFINE_BINARY_TREE_NODE(type, ...)			\
		Z_DEFINE_STRUCTURE_WITH_NAME (type,			\
			type *child_a, *child_b, *parent;		\
			__VA_ARGS__					\
		)

#	define Z_DEFINE_STRICT_BINARY_TREE_NODE(type, ...)		\
		Z_DEFINE_STRICT_STRUCTURE_WITH_NAME (type,		\
			type *child_a, *child_b, *parent;		\
			__VA_ARGS__					\
		)

#else

#	define Z_DEFINE_LIST_NODE(type, members)			\
		Z_DEFINE_STRUCTURE_WITH_NAME (type,			\
			type *next;					\
			members						\
		)

#	define Z_DEFINE_STRICT_LIST_NODE(type, members)			\
		Z_DEFINE_STRICT_STRUCTURE_WITH_NAME (type,		\
			type *next;					\
			members						\
		)

#	define Z_DEFINE_CHAIN_NODE(type, members)			\
		Z_DEFINE_STRUCTURE_WITH_NAME (type,			\
			type *next;					\
			type *previous;					\
			members						\
		)

#	define Z_DEFINE_STRICT_CHAIN_NODE(type, members)		\
		Z_DEFINE_STRICT_STRUCTURE_WITH_NAME (type,		\
			type *next;					\
			type *previous;					\
			members						\
		)

#	define Z_DEFINE_TREE_NODE(type, members)			\
		Z_DEFINE_STRUCTURE_WITH_NAME (type,			\
			type *next;					\
			type *previous;					\
			type *parent;					\
			type *children;					\
			members						\
		)

#	define Z_DEFINE_STRICT_TREE_NODE(type, members)			\
		Z_DEFINE_STRICT_STRUCTURE_WITH_NAME (type,		\
			type *next;					\
			type *previous;					\
			type *parent;					\
			type *children;					\
			members						\
		)

#	define Z_DEFINE_BINARY_TREE_NODE(type, members)			\
		Z_DEFINE_STRUCTURE_WITH_NAME (type,			\
			type *child_a;					\
			type *child_b;					\
			type *parent;					\
			members						\
		)

#	define Z_DEFINE_STRICT_BINARY_TREE_NODE(type, members)		\
		Z_DEFINE_STRICT_STRUCTURE_WITH_NAME (type,		\
			type *child_a;					\
			type *child_b;					\
			type *parent;					\
			members						\
		)

#endif

#endif /* __Z_macros_node_H__ */
