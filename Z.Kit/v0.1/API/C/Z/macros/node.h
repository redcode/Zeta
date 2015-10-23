/* Z Kit C API - macros/node.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_macros_node_H__
#define __Z_macros_node_H__

#include <Z/types/base.h>

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
			type *children[2], *parent;			\
			__VA_ARGS__					\
		)

#	define Z_DEFINE_STRICT_BINARY_TREE_NODE(type, ...)		\
		Z_DEFINE_STRICT_STRUCTURE_WITH_NAME (type,		\
			type *children[2], *parent;			\
			__VA_ARGS__					\
		)

#	define Z_DEFINE_RB_TREE_NODE(type, ...)				\
		Z_DEFINE_STRUCTURE_WITH_NAME (type,			\
			type *children[2], *parent;			\
			zuint8 color;					\
			__VA_ARGS__					\
		)

#	define Z_DEFINE_STRICT_RB_TREE_NODE(type, ...)			\
		Z_DEFINE_STRICT_STRUCTURE_WITH_NAME (type,		\
			type *children[2], *parent;			\
			zuint8 color;					\
			__VA_ARGS__					\
		)

#	define Z_DEFINE_QUADTREE_NODE(type, ...)			\
		Z_DEFINE_STRUCTURE_WITH_NAME (type,			\
			type *parent, *children[4];			\
			__VA_ARGS__					\
		)

#	define Z_DEFINE_STRICT_QUADTREE_NODE(type, ...)			\
		Z_DEFINE_STRICT_STRUCTURE_WITH_NAME (type,		\
			type *parent, *children[4];			\
			__VA_ARGS__					\
		)

#	define Z_DEFINE_OCTREE_NODE(type, ...)				\
		Z_DEFINE_STRUCTURE_WITH_NAME (type,			\
			type *parent, *children[8];			\
			__VA_ARGS__					\
		)

#	define Z_DEFINE_STRICT_OCTREE_NODE(type, ...)			\
		Z_DEFINE_STRICT_STRUCTURE_WITH_NAME (type,		\
			type *parent, *children[8];			\
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
			type *children[2];				\
			type *parent;					\
			members						\
		)

#	define Z_DEFINE_STRICT_BINARY_TREE_NODE(type, members)		\
		Z_DEFINE_STRICT_STRUCTURE_WITH_NAME (type,		\
			type *children[2];				\
			type *parent;					\
			members						\
		)

#	define Z_DEFINE_RB_TREE_NODE(type, members)			\
		Z_DEFINE_STRUCTURE_WITH_NAME (type,			\
			type *children[2];				\
			type *parent;					\
			zuint8 color;					\
			members						\
		)

#	define Z_DEFINE_STRICT_RB_TREE_NODE(type, members)		\
		Z_DEFINE_STRICT_STRUCTURE_WITH_NAME (type,		\
			type *children[2];				\
			type *parent;					\
			zuint8 color;					\
			members						\
		)

#	define Z_DEFINE_QUADTREE_NODE(type, members)			\
		Z_DEFINE_STRUCTURE_WITH_NAME (type,			\
			type *parent;					\
			type *children[4];				\
			members						\
		)

#	define Z_DEFINE_STRICT_QUADTREE_NODE(type, members)		\
		Z_DEFINE_STRICT_STRUCTURE_WITH_NAME (type,		\
			type *parent;					\
			type *children[4];				\
			members						\
		)

#	define Z_DEFINE_OCTREE_NODE(type, members)			\
		Z_DEFINE_STRUCTURE_WITH_NAME (type,			\
			type *parent;					\
			type *children[8];				\
			members						\
		)

#	define Z_DEFINE_STRICT_OCTREE_NODE(type, members)		\
		Z_DEFINE_STRICT_STRUCTURE_WITH_NAME (type,		\
			type *parent;					\
			type *children[8];				\
			members						\
		)

#endif

#endif /* __Z_macros_node_H__ */
