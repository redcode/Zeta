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


Q_INLINE QListNode *q_list_node_last(QListNode *object)
	{
	while (object->next != NULL) object = object->next;
	return object;
	}


#endif /* __Q_functions_data_QListNode_H__ */
