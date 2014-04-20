/* Q API - functions/data/QListNode.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2014 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_functions_data_QListNode_H__
#define __Q_functions_data_QListNode_H__

#include <Q/types/data.h>


Q_INLINE QListNode *q_raw_list_last(QListNode *object)
	{
	while (object->next != NULL) object = object->next;
	return object;
	}


Q_INLINE QListNode *q_raw_list_node(QListNode *object, qsize index)
	{
	for (; index; index--) object = object->next;
	return object;
	}


Q_INLINE qsize q_raw_list_size(QListNode *object)
	{
	qsize size = 0;

	for (; object != NULL; object = object->next) size++;
	return size;
	}


#endif /* __Q_functions_data_QListNode_H__ */
