/* Q API - types/data.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2014 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_types_data_H__
#define __Q_types_data_H__

#include <Q/types/base.h>
#include <Q/macros/node.h>

/* MARK: - Arrays */

typedef struct {
	void* data;
	qsize size;
} QArray;

typedef struct {
	void* data;
	qsize size;
	qsize block_size;
} QBlockArray;

/* MARK: - Nodes */

Q_DEFINE_LIST_NODE	 (QListNode,	  );
Q_DEFINE_CHAIN_NODE	 (QChainNode,	  );
Q_DEFINE_TREE_NODE	 (QTreeNode,      );
Q_DEFINE_BINARY_TREE_NODE(QBinaryTreeNode,);

Q_DEFINE_LIST_NODE	 (QDataListNode,	  void *data;);
Q_DEFINE_CHAIN_NODE	 (QDataChainNode,	  void *data;);
Q_DEFINE_TREE_NODE	 (QDataTreeNode,	  void *data;);
Q_DEFINE_BINARY_TREE_NODE(QDataBinaryTreeNode,	  void *data;);

Q_DEFINE_LIST_NODE	 (QKeyDataListNode,	  void *data; quintptr key;);
Q_DEFINE_CHAIN_NODE	 (QKeyDataChainNode,	  void *data; quintptr key;);
Q_DEFINE_TREE_NODE	 (QKeyDataTreeNode,	  void *data; quintptr key;);
Q_DEFINE_BINARY_TREE_NODE(QKeyDataBinaryTreeNode, void *data; quintptr key;);

/* MARK: - Casts */

#define Q_ARRAY(		    p) ((QArray			*)(p))
#define Q_BLOCK_ARRAY(		    p) ((QBlockArray		*)(p))
#define Q_LIST_NODE(		    p) ((QListNode		*)(p))
#define Q_CHAIN_NODE(		    p) ((QChainNode		*)(p))
#define Q_TREE_NODE(		    p) ((QTreeNode		*)(p))
#define Q_BINARY_TREE_NODE	    p) ((QBinaryTreeNode	*)(p))
#define Q_DATA_LIST_NODE(	    p) ((QDataListNode		*)(p))
#define Q_DATA_CHAIN_NODE(	    p) ((QDataChainNode		*)(p))
#define Q_DATA_TREE_NODE(	    p) ((QDataTreeNode		*)(p))
#define Q_DATA_BINARY_TREE_NODE(    p) ((QDataBinaryTreeNode	*)(p))
#define Q_KEY_DATA_LIST_NODE(	    p) ((QKeyDataListNode	*)(p))
#define Q_KEY_DATA_CHAIN_NODE(	    p) ((QKeyDataChainNode	*)(p))
#define Q_KEY_DATA_TREE_NODE(	    p) ((QKeyDataTreeNode	*)(p))
#define Q_KEY_DATA_BINARY_TREE_NODE(p) ((QKeyDataBinaryTreeNode *)(p))

#endif /* __Q_types_data_H__ */
