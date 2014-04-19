/* Q API - functions/data/QTreeNode.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2014 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_functions_data_QTreeNode_H__
#define __Q_functions_data_QTreeNode_H__

#include <Q/types/data.h>


Q_INLINE QTreeNode *q_tree_node_root(QTreeNode *object)
	{
	while (object->parent != NULL) object = object->parent;
	return object;
	}


#endif /* __Q_functions_data_QTreeNode_H__ */
