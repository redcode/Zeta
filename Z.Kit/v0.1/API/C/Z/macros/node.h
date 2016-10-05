/* Z Kit C API - macros/node.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_macros_node_H__
#define __Z_macros_node_H__

#include <Z/types/base.h>

#if !defined(Z_AVOID_VARIADIC_MACROS) && Z_LANGUAGE_HAS(C, VARIADIC_MACRO)

#	define Z_DEFINE_LIST_NODE(type, qualifiers, ...)			\
		Z_DEFINE_STRUCTURE_WITH_NAME (type,				\
			type qualifiers *next;					\
			__VA_ARGS__						\
		)

#	define Z_DEFINE_STRICT_LIST_NODE(type, qualifiers, ...)			\
		Z_DEFINE_STRICT_STRUCTURE_WITH_NAME (type,			\
			type qualifiers *next;					\
			__VA_ARGS__						\
		)

#	define Z_DEFINE_CHAIN_NODE(type, qualifiers, ...)			\
		Z_DEFINE_STRUCTURE_WITH_NAME (type,				\
			type qualifiers *next, *previous;			\
			__VA_ARGS__						\
		)

#	define Z_DEFINE_STRICT_CHAIN_NODE(type, qualifiers, ...)		\
		Z_DEFINE_STRICT_STRUCTURE_WITH_NAME (type,			\
			type qualifiers *next, *previous;			\
			__VA_ARGS__						\
		)

#	define Z_DEFINE_TREE_NODE(type, qualifiers, ...)			\
		Z_DEFINE_STRUCTURE_WITH_NAME (type,				\
			type qualifiers *next, *previous, *parent, *children;	\
			__VA_ARGS__						\
		)

#	define Z_DEFINE_STRICT_TREE_NODE(type, qualifiers, ...)			\
		Z_DEFINE_STRICT_STRUCTURE_WITH_NAME (type,			\
			type qualifiers *next, *previous, *parent, *children;	\
			__VA_ARGS__						\
		)

#	define Z_DEFINE_BINARY_TREE_NODE(type, qualifiers, ...)			\
		Z_DEFINE_STRUCTURE_WITH_NAME (type,				\
			type qualifiers *parent, *children[2];			\
			__VA_ARGS__						\
		)

#	define Z_DEFINE_STRICT_BINARY_TREE_NODE(type, qualifiers, ...)		\
		Z_DEFINE_STRICT_STRUCTURE_WITH_NAME (type,			\
			type qualifiers *parent, *children[2];			\
			__VA_ARGS__						\
		)

#	define Z_DEFINE_RB_TREE_NODE(type, qualifiers, ...)			\
		Z_DEFINE_STRUCTURE_WITH_NAME (type,				\
			type qualifiers *parent, *children[2];			\
			zuint8 color;						\
			__VA_ARGS__						\
		)

#	define Z_DEFINE_STRICT_RB_TREE_NODE(type, qualifiers, ...)		\
		Z_DEFINE_STRICT_STRUCTURE_WITH_NAME (type,			\
			type qualifiers *parent, *children[2];			\
			zuint8 color;						\
			__VA_ARGS__						\
		)

#	define Z_DEFINE_QUADTREE_NODE(type, qualifiers, ...)			\
		Z_DEFINE_STRUCTURE_WITH_NAME (type,				\
			type qualifiers *parent, *children[4];			\
			__VA_ARGS__						\
		)

#	define Z_DEFINE_STRICT_QUADTREE_NODE(type, qualifiers, ...)		\
		Z_DEFINE_STRICT_STRUCTURE_WITH_NAME (type,			\
			type qualifiers *parent, *children[4];			\
			__VA_ARGS__						\
		)

#	define Z_DEFINE_OCTREE_NODE(type, qualifiers, ...)			\
		Z_DEFINE_STRUCTURE_WITH_NAME (type,				\
			type qualifiers *parent, *children[8];			\
			__VA_ARGS__						\
		)

#	define Z_DEFINE_STRICT_OCTREE_NODE(type, qualifiers, ...)		\
		Z_DEFINE_STRICT_STRUCTURE_WITH_NAME (type,			\
			type qualifiers *parent, *children[8];			\
			__VA_ARGS__						\
		)

#	define Z_DEFINE_ARRAY_TREE_NODE(type, qualifiers, ...)			\
		Z_DEFINE_STRUCTURE_WITH_NAME(type,				\
			type qualifiers *parent;				\
										\
			struct {type qualifiers* data;				\
				zsize size;					\
			} children;						\
										\
			__VA_ARGS__						\
		)

#	define Z_DEFINE_STRICT_ARRAY_TREE_NODE(type, qualifiers, ...)		\
		Z_DEFINE_STRICT_STRUCTURE_WITH_NAME(type,			\
			type qualifiers *parent;				\
										\
			struct {type qualifiers* data;				\
				zsize size;					\
			} children;						\
										\
			__VA_ARGS__						\
		)

#else

#	define Z_DEFINE_LIST_NODE(type, qualifiers, members)			\
		Z_DEFINE_STRUCTURE_WITH_NAME (type,				\
			type qualifiers *next;					\
			members							\
		)

#	define Z_DEFINE_STRICT_LIST_NODE(type, qualifiers, members)		\
		Z_DEFINE_STRICT_STRUCTURE_WITH_NAME (type,			\
			type qualifiers *next;					\
			members							\
		)

#	define Z_DEFINE_CHAIN_NODE(type, qualifiers, members)			\
		Z_DEFINE_STRUCTURE_WITH_NAME (type,				\
			type qualifiers *next;					\
			type qualifiers *previous;				\
			members							\
		)

#	define Z_DEFINE_STRICT_CHAIN_NODE(type, qualifiers, members)		\
		Z_DEFINE_STRICT_STRUCTURE_WITH_NAME (type,			\
			type qualifiers *next;					\
			type qualifiers *previous;				\
			members							\
		)

#	define Z_DEFINE_TREE_NODE(type, qualifiers, members)			\
		Z_DEFINE_STRUCTURE_WITH_NAME (type,				\
			type qualifiers *next;					\
			type qualifiers *previous;				\
			type qualifiers *parent;				\
			type qualifiers *children;				\
			members							\
		)

#	define Z_DEFINE_STRICT_TREE_NODE(type, qualifiers, members)		\
		Z_DEFINE_STRICT_STRUCTURE_WITH_NAME (type,			\
			type qualifiers *next;					\
			type qualifiers *previous;				\
			type qualifiers *parent;				\
			type qualifiers *children;				\
			members							\
		)

#	define Z_DEFINE_BINARY_TREE_NODE(type, qualifiers, members)		\
		Z_DEFINE_STRUCTURE_WITH_NAME (type,				\
			type qualifiers *parent;				\
			type qualifiers *children[2];				\
			members							\
		)

#	define Z_DEFINE_STRICT_BINARY_TREE_NODE(type, qualifiers, members)	\
		Z_DEFINE_STRICT_STRUCTURE_WITH_NAME (type,			\
			type qualifiers *parent;				\
			type qualifiers *children[2];				\
			members							\
		)

#	define Z_DEFINE_RB_TREE_NODE(type, qualifiers, members)			\
		Z_DEFINE_STRUCTURE_WITH_NAME (type,				\
			type qualifiers *parent;				\
			type qualifiers *children[2];				\
			zuint8 color;						\
			members							\
		)

#	define Z_DEFINE_STRICT_RB_TREE_NODE(type, qualifiers, members)		\
		Z_DEFINE_STRICT_STRUCTURE_WITH_NAME (type,			\
			type qualifiers *parent;				\
			type qualifiers *children[2];				\
			zuint8 color;						\
			members							\
		)

#	define Z_DEFINE_QUADTREE_NODE(type, qualifiers, members)		\
		Z_DEFINE_STRUCTURE_WITH_NAME (type,				\
			type qualifiers *parent;				\
			type qualifiers *children[4];				\
			members							\
		)

#	define Z_DEFINE_STRICT_QUADTREE_NODE(type, qualifiers, members)		\
		Z_DEFINE_STRICT_STRUCTURE_WITH_NAME (type,			\
			type qualifiers *parent;				\
			type qualifiers *children[4];				\
			members							\
		)

#	define Z_DEFINE_OCTREE_NODE(type, qualifiers, members)			\
		Z_DEFINE_STRUCTURE_WITH_NAME (type,				\
			type qualifiers *parent;				\
			type qualifiers *children[8];				\
			members							\
		)

#	define Z_DEFINE_STRICT_OCTREE_NODE(type, qualifiers, members)		\
		Z_DEFINE_STRICT_STRUCTURE_WITH_NAME (type,			\
			type qualifiers *parent;				\
			type qualifiers *children[8];				\
			members							\
		)

#	define Z_DEFINE_ARRAY_TREE_NODE(type, qualifiers, members)		\
		Z_DEFINE_STRUCTURE_WITH_NAME(type,				\
			type qualifiers *parent;				\
										\
			struct {type qualifiers* data;				\
				zsize size;					\
			} children;						\
										\
			members							\
		)

#	define Z_DEFINE_STRICT_ARRAY_TREE_NODE(type, qualifiers, members)	\
		Z_DEFINE_STRICT_STRUCTURE_WITH_NAME(type,			\
			type qualifiers *parent;				\
										\
			struct {type qualifiers* data;				\
				zsize size;					\
			} children;						\
										\
			members							\
		)

#endif

#endif /* __Z_macros_node_H__ */
