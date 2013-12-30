/* Q API - macros/node.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2014 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_macros_node_H__
#define __Q_macros_node_H__

#include <Q/macros/structure.h>

#define Q_DEFINE_LIST_NODE(type, ...)	\
	Q_DEFINE_STRUCTURE_WITH_NAME(	\
		type,			\
		type *next;		\
		__VA_ARGS__		\
	)

#define Q_DEFINE_STRICT_LIST_NODE(type, ...)	\
	Q_DEFINE_STRICT_STRUCTURE_WITH_NAME(	\
		type,				\
		type *next;			\
		__VA_ARGS__			\
	)

#define Q_DEFINE_CHAIN_NODE(type, ...)	\
	Q_DEFINE_STRUCTURE_WITH_NAME(	\
		type,			\
		type *next, *previous;	\
		__VA_ARGS__		\
	)

#define Q_DEFINE_STRICT_CHAIN_NODE(type, ...)	\
	Q_DEFINE_STRICT_STRUCTURE_WITH_NAME(	\
		type,				\
		type *next, *previous;		\
		__VA_ARGS__			\
	)

#define Q_DEFINE_TREE_NODE(type, ...)				\
	Q_DEFINE_STRUCTURE_WITH_NAME(				\
		type,						\
		type *next, *previous, *parent, *children;	\
		__VA_ARGS__					\
	)

#define Q_DEFINE_STRICT_TREE_NODE(type, ...)			\
	Q_DEFINE_STRICT_STRUCTURE_WITH_NAME(			\
		type,						\
		type *next, *previous, *parent, *children;	\
		__VA_ARGS__					\
	)

#define Q_DEFINE_BINARY_TREE_NODE(type, ...)		\
	Q_DEFINE_STRUCTURE_WITH_NAME(			\
		type,					\
		type *child_a, *child_b, *parent;	\
		__VA_ARGS__				\
	)

#define Q_DEFINE_STRICT_BINARY_TREE_NODE(type, ...)	\
	Q_DEFINE_STRICT_STRUCTURE_WITH_NAME(		\
		type,					\
		type *child_a, *child_b, *parent;	\
		__VA_ARGS__				\
	)

#endif /* __Q_macros_node_H__ */
