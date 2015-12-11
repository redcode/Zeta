/* Z Kit C API - functions/data/ZTreeNode.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_functions_data_ZTreeNode_H__
#define __Z_functions_data_ZTreeNode_H__

#include <Z/functions/data/ZChain.h>


#define z_tree_child_level_size(object) \
	z_list_size(Z_LIST_NODE(object->children))

#define z_tree_node(object, index) \
	Z_TREE_NODE(z_chain_node(Z_CHAIN_NODE(object), index))

#define z_tree_first(object) \
	Z_TREE_NODE(z_chain_first(Z_CHAIN_NODE(object)))

#define z_tree_last(object) \
	Z_TREE_NODE(z_chain_last(Z_CHAIN_NODE(object)))


Z_INLINE
ZTreeNode *z_tree_node_root(ZTreeNode *object)
	{
	while (object->parent != NULL) object = object->parent;
	return object;
	}


Z_INLINE
void z_tree_node_set_children(ZTreeNode *object, ZTreeNode *children)
	{
	ZTreeNode *node = children;

	for (; node->previous != NULL; node = node->previous)
		node->previous->parent = object;

	object->children = node;

	for (; children != NULL; children = children->next)
		children->parent = object;
	}


Z_INLINE
void z_tree_node_set_aligned_children(ZTreeNode *object, ZTreeNode *children)
	{
	object->children = children;

	for (; children != NULL; children = children->next)
		children->parent = object;
	}


Z_INLINE
void z_tree_node_move_to_first(ZTreeNode *object)
	{
	ZTreeNode *node = z_tree_first(object);

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


Z_INLINE
void z_tree_node_move_to_last(ZTreeNode *object)
	{
	if (object->next != NULL)
		{
		ZTreeNode *node = object->next;

		if ((node->previous = object->previous) == NULL)
			object->parent->children = node;

		while (node->next != NULL) node = node->next;
		(node->next = object)->previous = node;
		object->next = NULL;
		}
	}


Z_INLINE
void z_tree_node_move_to_index(ZTreeNode *object, zsize new_index)
	{
	zsize index = 0;
	ZTreeNode *node = object;

	for (; node->previous != NULL; node = node->previous) index++;

	if (new_index < index)
		{
		if (new_index < (index >> 1))
			while (new_index--) node = node->next;

		else	{
			index -= new_index;
			for (node = object; index--; node = node->previous);
			}

		if ((object->previous->next = object->next) != NULL)
			object->next->previous = object->previous;

		if ((object->previous = node->previous) != NULL)
			node->previous->next = object;

		else if (object->parent != NULL)
			object->parent->children = object;

		(object->next = node)->previous = object;
		}

	else if (new_index > index)
		{
		new_index -= index;
		for (node = object->next; --new_index; node = node->next)

		if ((object->next->previous = object->previous) != NULL)
			object->previous->next = object->next;

		else if (object->parent != NULL)
			object->parent->children = object->next;

		if ((object->next = node->next) != NULL)
			node->next->previous = object;

		(object->previous = node)->next = object;
		}
	}



Z_INLINE
void z_tree_node_unlink(ZTreeNode *object)
	{
	if (object->previous != NULL) object->previous->next = object->next;
	else if (object->parent != NULL) object->parent->children = object->next;
	if (object->next != NULL) object->next->previous = object->previous;

	object->previous = NULL;
	object->next	 = NULL;
	object->parent	 = NULL;
	}


Z_INLINE
ZTreeNode *z_tree_node_child(ZTreeNode *object, zsize index)
	{
	for (object = object->children; index; index--) object = object->next;
	return object;
	}


Z_INLINE
void z_tree_node_preppend_child(ZTreeNode *object, ZTreeNode *child)
	{
	if ((child->next = object->children) != NULL)
		child->next->previous = child;

	child->parent = object;
	object->children = child;
	}


Z_INLINE
void z_tree_node_append_child(ZTreeNode *object, ZTreeNode *child)
	{
	child->parent = object;

	if (object->children == NULL) object->children = child;

	else	{
		ZTreeNode *node = object->children;

		while (node->next != NULL) node = node->next;
		(node->next = child)->previous = node;
		}
	}


Z_INLINE
void z_tree_node_insert_child(ZTreeNode *object, zsize index, ZTreeNode *child)
	{
	child->parent = object;

	if (index)
		{
		for (object = object->children; --index; object = object->next);

		if ((child->next = object->next) != NULL)
			object->next->previous = child;

		(child->previous = object)->next = child;
		}

	else	{
		if ((child->next = object->children) != NULL)
			object->children->previous = child;

		object->children = child;
		}
	}


Z_INLINE
zboolean z_tree_node_is_ancestor_of_node(ZTreeNode *object, ZTreeNode *node)
	{
	for (; node->parent != NULL; node = node->parent)
		if (node == object) return TRUE;

	return FALSE;
	}


Z_INLINE
zboolean z_tree_node_is_descendant_of_node(ZTreeNode *object, ZTreeNode *node)
	{
	for (; object->parent != NULL; object = object->parent)
		if (object == node) return TRUE;

	return FALSE;
	}


#endif /* __Z_functions_data_ZTreeNode_H__ */
