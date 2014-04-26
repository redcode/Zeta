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


#define Q_IMPLEMENTATION_LIST_NODE(Type, export, prefix)	\
								\
								\
export Type *prefix##node(Type *object, qsize index)		\
	{							\
	for (; index; index--) object = object->next;		\
	return object;						\
	}							\
								\
								\
export Type *prefix##last(Type *object)				\
	{							\
	while (object->next != NULL) object = object->next;	\
	return object;						\
	}							\
								\
								\
export qsize prefix##size(Type *object)				\
	{							\
	qsize size = 0;						\
								\
	for (; object != NULL; object = object->next) size++;	\
	return size;						\
	}


Q_IMPLEMENTATION_LIST_NODE(QListNode, Q_INLINE, q_inline_list_node_)


#endif /* __Q_functions_data_QListNode_H__ */
