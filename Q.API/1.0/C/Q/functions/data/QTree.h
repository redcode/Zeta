/* Q API - functions/data/QTree.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2014 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_functions_data_QTree_H__
#define __Q_functions_data_QTree_H__

#include <Q/functions/data/QChain.h>


#define q_tree_children_count(object) \
	q_list_size(Q_LIST_NODE(object->children))

#define q_tree_node(object, index) \
	Q_TREE_NODE(q_chain_node(Q_CHAIN_NODE(object), index))

#define q_tree_first(object) \
	Q_TREE_NODE(q_chain_first(Q_CHAIN_NODE(object)))

#define q_tree_last(object) \
	Q_TREE_NODE(q_chain_last(Q_CHAIN_NODE(object)))

#define q_tree_move_to_last(object) \
	q_chain_move_to_last(Q_CHAIN_NODE(object))


Q_INLINE QTreeNode *q_tree_root(QTreeNode *object)
	{
	while (object->parent != NULL) object = object->parent;
	return object;
	}


Q_INLINE void q_tree_set_children(QTreeNode *object, QTreeNode *children)
	{
	QTreeNode *node = children;

	for (; node->previous != NULL; node = node->previous)
		node->previous->parent = object;

	object->children = node;

	for (; children != NULL; children = children->next)
		children->parent = object;
	}


Q_INLINE void q_tree_set_aligned_children(QTreeNode *object, QTreeNode *children)
	{
	object->children = children;

	for (; children != NULL; children = children->next)
		children->parent = object;
	}


Q_INLINE void q_tree_move_to_first(QTreeNode *object)
	{
	QTreeNode *node = q_tree_first(object);

	if (node != object)
		{
		object->previous->next = object->next;
		if (object->next != NULL) object->next->previous = object->previous;
		(node->previous = object)->next = node;
		object->previous = NULL;
		if (object->parent != NULL) object->parent->children = object;
		}
	}


#endif /* __Q_functions_data_QTree_H__ */
