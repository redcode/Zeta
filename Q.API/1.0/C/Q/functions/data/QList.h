/* Q API - functions/data/QList.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2014 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_functions_data_QList_H__
#define __Q_functions_data_QList_H__

#include <Q/types/data.h>


#define Q_IMPLEMENTATION_LIST_NODE(export)			\
								\
export QListNode *q_list_node(QListNode *object, qsize index)	\
	{							\
	for (; index; index--) object = object->next;		\
	return object;						\
	}


#define Q_IMPLEMENTATION_LIST_LAST(export)			\
								\
export QListNode *q_list_last(QListNode *object)		\
	{							\
	while (object->next != NULL) object = object->next;	\
	return object;						\
	}


#define Q_IMPLEMENTATION_LIST_SIZE(export)			\
								\
export qsize q_list_size(QListNode *object)			\
	{							\
	qsize size = 0;						\
								\
	for (; object != NULL; object = object->next) size++;	\
	return size;						\
	}


#define Q_IMPLEMENTATION_LIST(export)	\
					\
Q_IMPLEMENTATION_LIST_NODE(Q_INLINE)	\
Q_IMPLEMENTATION_LIST_LAST(Q_INLINE)	\
Q_IMPLEMENTATION_LIST_SIZE(Q_INLINE)


#ifdef Q_USE_INLINE_IMPLEMENTATION_LIST
	Q_IMPLEMENTATION_LIST(Q_INLINE)

#else
#	ifdef Q_USE_INLINE_IMPLEMENTATION_LIST_NODE
		Q_IMPLEMENTATION_LIST_NODE(Q_INLINE)
#	endif

#	ifdef Q_USE_INLINE_IMPLEMEMTATION_LIST_LAST
		Q_IMPLEMENTATION_LIST_LAST(Q_INLINE)
#	endif

#	ifdef Q_USE_INLINE_IMPLEMENTATION_LIST_SIZE
		Q_IMPLEMENTATION_LIST_SIZE(Q_INLINE)
#	endif
#endif


#endif /* __Q_functions_data_QList_H__ */
