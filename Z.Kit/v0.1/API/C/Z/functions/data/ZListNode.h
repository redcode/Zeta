/* Z Kit C API - functions/data/ZListNode.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_functions_data_ZListNode_H__
#define __Z_functions_data_ZListNode_H__

#include <Z/types/data.h>


#define Z_IMPLEMENTATION_LIST_NODE(Type, export, prefix)	\
								\
								\
export Type *prefix##node(Type *object, zsize index)		\
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
export zsize prefix##size(Type *object)				\
	{							\
	zsize size = 0;						\
								\
	for (; object != NULL; object = object->next) size++;	\
	return size;						\
	}


Z_IMPLEMENTATION_LIST_NODE(ZListNode, Z_INLINE, z_inline_list_node_)


#endif /* __Z_functions_data_ZListNode_H__ */
