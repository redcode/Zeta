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


#define q_tree_child_level_size(object) \
	q_list_size(Q_LIST_NODE(object->children))

#define q_tree_node(object, index) \
	Q_TREE_NODE(q_chain_node(Q_CHAIN_NODE(object), index))

#define q_tree_first(object) \
	Q_TREE_NODE(q_chain_first(Q_CHAIN_NODE(object)))

#define q_tree_last(object) \
	Q_TREE_NODE(q_chain_last(Q_CHAIN_NODE(object)))


Q_INLINE
QTreeNode *q_tree_node_root(QTreeNode *object)
	{
	while (object->parent != NULL) object = object->parent;
	return object;
	}


Q_INLINE
void q_tree_node_set_children(QTreeNode *object, QTreeNode *children)
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


Q_INLINE
void q_tree_node_move_to_first(QTreeNode *object)
	{
	QTreeNode *node = q_tree_first(object);

	if (node != object)
		{
		object->previous->next = object->next;

		if (object->next != NULL)
			object->next->previous = object->previous;

		(node->previous = object)->next = node;
		object->previous = NULL;
		if (object->parent != NULL) object->parent->children = object;
		}
	}


Q_INLINE
void q_tree_node_move_to_last(QTreeNode *object)
	{
	if (object->next != NULL)
		{
		QTreeNode *node = object->next;

		if ((node->previous = object->previous) == NULL)
			object->parent->children = node;

		while (node->next != NULL) node = node->next;
		(node->next = object)->previous = node;
		object->next = NULL;
		}
	}



Q_INLINE
void q_tree_node_move_to_index(QTreeNode *object, qsize new_index)
	{
	}



Q_INLINE
void q_tree_node_unlink(QTreeNode *object)
	{
	if	(object->previous != NULL) object->previous->next = object->next;
	else if (object->parent != NULL) object->parent->children = object->next;
	if	(object->next != NULL) object->next->previous = object->previous;

	object->previous = NULL;
	object->next	 = NULL;
	object->parent	 = NULL;
	}


Q_INLINE
QTreeNode *q_tree_node_child(QTreeNode *object, qsize index)
	{
	for (object = object->children; index; index--) object = object->next;
	return object;
	}


Q_INLINE
void q_tree_node_preppend_child(QTreeNode *object, QTreeNode *child)
	{
	if ((child->next = object->children) != NULL)
		child->next->previous = child;

	child->parent = object;
	object->children = child;
	}


Q_INLINE
void q_tree_node_append_child(QTreeNode *object, QTreeNode *child)
	{
	child->parent = object;

	if (object->children == NULL) object->children = child;

	else	{
		QTreeNode *node = object->children;

		while (node->next != NULL) node = node->next;
		(node->next = child)->previous = node;
		}
	}


Q_INLINE
void q_tree_node_insert_child(QTreeNode *object, qsize index, QTreeNode *child)
	{
	child->parent = object;

	if (index)
		{
		for (object = object->children; --index; object = object->next);

		if ((child->next = object->next) != NULL)
			object->next->previous = child;

		child->previous = object;
		object->next = child;
		}

	else	{
		child->next = object->children;
		object->children = child;
		}
	}


Q_INLINE
qboolean q_tree_node_is_ancestor_of_node(QTreeNode *object, QTreeNode *node)
	{
	for (; node->parent != NULL; node = node->parent)
		if (node == object) return TRUE;

	return FALSE;
	}


Q_INLINE
qboolean q_tree_node_is_descendant_of_node(QTreeNode *object, QTreeNode *node)
	{
	for (; object->parent != NULL; object = object->parent)
		if (object == node) return TRUE;

	return FALSE;
	}


#endif /* __Q_functions_data_QTree_H__ */
