/* Q API - functions/data/QChainNode.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2014 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_functions_data_QChainNode_H__
#define __Q_functions_data_QChainNode_H__

#include <Q/types/data.h>


Q_INLINE QChainNode *q_chain_node_first(QChainNode *object)
	{
	while (object->previous != NULL) object = object->previous;
	return object;
	}


#endif /* __Q_functions_data_QChainNode_H__ */
