/* Q API - functions/data/QTreeNode.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2014 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_functions_data_QTreeNode_H__
#define __Q_functions_data_QTreeNode_H__

#include <Q/functions/data/QChainNode.h>


Q_INLINE QTreeNode *q_tree_node_root(QTreeNode *object)
	{
	while (object->parent != NULL) object = object->parent;
	return object;
	}


Q_INLINE void q_tree_node_set_children(QTreeNode *object, QTreeNode *children)
	{
	QTreeNode *node = children;

	for (; node->previous != NULL; node = node->previous)
		node->previous->parent = object;

	object->children = node;

	for (; children != NULL; children = children->next)
		children->parent = object;
	}


Q_INLINE
void q_tree_node_set_aligned_children(QTreeNode *object, QTreeNode *children)
	{
	object->children = children;

	for (; children != NULL; children = children->next)
		children->parent = object;
	}


#define q_tree_node_children_count(object) \
	q_raw_list_size(Q_LIST_NODE(object->children))


#endif /* __Q_functions_data_QTreeNode_H__ */
