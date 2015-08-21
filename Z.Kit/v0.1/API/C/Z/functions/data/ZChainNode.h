/* Z Kit C API - functions/data/ZChain.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_functions_data_ZChain_H__
#define __Z_functions_data_ZChain_H__

#include <Z/functions/data/ZList.h>

#ifndef Z_CHAIN_EXPORT
#	define Z_CHAIN_EXPORT Z_INLINE
#	define Z_AVAILABLE_INLINE_CHAIN
#endif

#define z_chain_last(object) \
	Z_CHAIN_NODE(z_list_last(Z_LIST_NODE(object)))


Z_CHAIN_EXPORT ZChainNode *z_chain_first(ZChainNode *object)
	{
	while (object->previous != NULL) object = object->previous;
	return object;
	}


Z_CHAIN_EXPORT ZChainNode *z_chain_node(ZChainNode *object, zsize index)
	{
	object = z_chain_first(object);
	return Z_CHAIN_NODE(z_list_node(Z_LIST_NODE(object), index));
	}


Z_CHAIN_EXPORT zsize z_chain_left_index(ZChainNode *object)
	{
	zsize index = 0;

	for (; object->previous != NULL; object = object->previous) index++;
	return index;
	}


Z_CHAIN_EXPORT zsize z_chain_right_index(ZChainNode *object)
	{
	zsize index = 0;

	for (; object != NULL; object = object->next) index++;
	return index;
	}


Z_CHAIN_EXPORT void z_chain_unlink(ZChainNode *object)
	{
	if (object->next    ) object->next->previous = object->previous;
	if (object->previous) object->previous->next = object->next;

	object->next	 = NULL;
	object->previous = NULL;
	}


Z_CHAIN_EXPORT zsize z_chain_size(ZChainNode *object)
	{
	zsize size = 1;
	ZChainNode *node = object->previous;

	for (; node != NULL; node = node->previous) size++;
	for (node = object->next; node != NULL; node = node->next) size++;
	return size;
	}


Z_CHAIN_EXPORT void z_chain_move_to_first(ZChainNode *object)
	{
	ZChainNode *node = z_chain_first(object);

	if (node != object)
		{
		object->previous->next = object->next;
		if (object->next != NULL) object->next->previous = object->previous;
		(node->previous = object)->next = node;
		object->previous = NULL;
		}
	}


Z_CHAIN_EXPORT void z_chain_move_to_last(ZChainNode *object)
	{
	ZChainNode *node = z_chain_last(object);

	if (node != object)
		{
		object->next->previous = object->previous;
		if (object->previous != NULL) object->previous->next = object->next;
		(node->next = object)->previous = node;
		object->next = NULL;
		}
	}


Z_CHAIN_EXPORT void z_chain_move_forwards(ZChainNode *object)
	{
	}


Z_CHAIN_EXPORT void z_chain_move_backwards(ZChainNode *object)
	{
	}


#endif /* __Z_functions_data_ZChain_H__ */
