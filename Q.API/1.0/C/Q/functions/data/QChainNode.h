/* Q API - functions/data/QChainNode.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2014 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_functions_data_QChainNode_H__
#define __Q_functions_data_QChainNode_H__

#include <Q/functions/data/QListNode.h>


Q_INLINE qsize q_chain_node_left_index(QChainNode *object)
	{
	qsize index = 0;

	for (; object != NULL; object = object->previous) index++;
	return index;
	}


Q_INLINE qsize q_chain_node_right_index(QChainNode *object)
	{
	qsize index = 0;

	for (; object != NULL; object = object->next) index++;
	return index;
	}


Q_INLINE void q_chain_node_unlink(QChainNode *object)
	{
	if (object->next    ) object->next->previous = object->previous;
	if (object->previous) object->previous->next = object->next;

	object->next	 = NULL;
	object->previous = NULL;
	}


Q_INLINE QChainNode *q_raw_chain_first(QChainNode *object)
	{
	while (object->previous != NULL) object = object->previous;
	return object;
	}


#define q_raw_chain_last(object) \
	Q_CHAIN_NODE(q_raw_list_last(Q_LIST_NODE(object)))


Q_INLINE QChainNode *q_raw_chain_node(QChainNode *object, qsize index)
	{
	object = q_chain_node_first(node);
	return Q_CHAIN_NODE(q_list_node_index(Q_LIST_NODE(node), index));
	}


Q_INLINE QChainNode *q_raw_chain_size(QChainNode *node)
	{
	return	q_chain_node_left_index (node) +
		q_chain_node_right_index(node) +
		1;
	}


#endif /* __Q_functions_data_QChainNode_H__ */
