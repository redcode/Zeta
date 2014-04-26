/* Q API - functions/data/QChain.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2014 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_functions_data_QChain_H__
#define __Q_functions_data_QChain_H__

#include <Q/functions/data/QList.h>

#ifndef Q_CHAIN_EXPORT
#	define Q_CHAIN_EXPORT Q_INLINE
#	define Q_AVAILABLE_INLINE_CHAIN
#endif

#define q_chain_last(object) \
	Q_CHAIN_NODE(q_list_last(Q_LIST_NODE(object)))


Q_CHAIN_EXPORT QChainNode *q_chain_first(QChainNode *object)
	{
	while (object->previous != NULL) object = object->previous;
	return object;
	}


Q_CHAIN_EXPORT QChainNode *q_chain_node(QChainNode *object, qsize index)
	{
	object = q_chain_first(object);
	return Q_CHAIN_NODE(q_list_node(Q_LIST_NODE(object), index));
	}


Q_CHAIN_EXPORT qsize q_chain_left_index(QChainNode *object)
	{
	qsize index = 0;

	for (; object != NULL; object = object->previous) index++;
	return index;
	}


Q_CHAIN_EXPORT qsize q_chain_right_index(QChainNode *object)
	{
	qsize index = 0;

	for (; object != NULL; object = object->next) index++;
	return index;
	}


Q_CHAIN_EXPORT void q_chain_unlink(QChainNode *object)
	{
	if (object->next    ) object->next->previous = object->previous;
	if (object->previous) object->previous->next = object->next;

	object->next	 = NULL;
	object->previous = NULL;
	}


Q_CHAIN_EXPORT qsize q_chain_size(QChainNode *object)
	{
	qsize size = 1;
	QChainNode *node = object->previous;

	for (; node != NULL; node = node->previous) size++;
	for (node = object->next; node != NULL; node = node->next) size++;
	return size;
	}


Q_CHAIN_EXPORT void q_chain_move_to_first(QChainNode *object)
	{
	QChainNode *node = q_chain_first(object);

	if (node != object)
		{
		object->previous->next = object->next;
		if (object->next != NULL) object->next->previous = object->previous;
		(node->previous = object)->next = node;
		object->previous = NULL;
		}
	}


Q_CHAIN_EXPORT void q_chain_move_to_last(QChainNode *object)
	{
	QChainNode *node = q_chain_last(object);

	if (node != object)
		{
		object->next->previous = object->previous;
		if (object->previous != NULL) object->previous->next = object->next;
		(node->next = object)->previous = node;
		object->next = NULL;
		}
	}


Q_CHAIN_EXPORT void q_chain_move_forwards(QChainNode *object)
	{
	}


Q_CHAIN_EXPORT void q_chain_move_backwards(QChainNode *object)
	{
	}


#endif /* __Q_functions_data_QChain_H__ */
