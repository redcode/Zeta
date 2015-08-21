/* Z Kit C API - types/data.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_types_data_H__
#define __Z_types_data_H__

#include <Z/types/base.h>
#include <Z/macros/node.h>

/* MARK: - Arrays */

typedef struct {
	void* data;
	zsize size;
} ZArray;

typedef struct {
	void* data;
	zsize size;
	zsize block_size;
} ZBlockArray;

/* MARK: - Nodes */

Z_DEFINE_LIST_NODE	 (ZListNode,	  );
Z_DEFINE_CHAIN_NODE	 (ZChainNode,	  );
Z_DEFINE_BINARY_TREE_NODE(ZBinaryTreeNode,);
Z_DEFINE_TREE_NODE	 (ZTreeNode,	  );

Z_DEFINE_LIST_NODE	 (ZDataListNode,       void* data;);
Z_DEFINE_CHAIN_NODE	 (ZDataChainNode,      void* data;);
Z_DEFINE_BINARY_TREE_NODE(ZDataBinaryTreeNode, void* data;);
Z_DEFINE_TREE_NODE	 (ZDataTreeNode,       void* data;);

typedef struct {
	ZListNode* first;
	zsize	   size;
	ZListNode* last;
} ZList;	

typedef struct {
	ZChainNode* first;
	zsize	    size;
	ZChainNode* last;
} ZChain;

typedef struct {
	ZBinaryTreeNode* root;
	zsize		 size;
} ZBinaryTree;

typedef struct {
	ZTreeNode* root;
	zsize	   size;
} ZTree;

typedef struct {
	ZTree*	   tree;
	ZTreeNode* node;
} ZTreeCursor;

/* MARK: - Casts */

#define Z_ARRAY(		p) ((ZArray		 *)(p))
#define Z_BLOCK_ARRAY(		p) ((ZBlockArray	 *)(p))
#define Z_LIST_NODE(		p) ((ZListNode		 *)(p))
#define Z_CHAIN_NODE(		p) ((ZChainNode		 *)(p))
#define Z_BINARY_TREE_NODE(	p) ((ZBinaryTreeNode	 *)(p))
#define Z_TREE_NODE(		p) ((ZTreeNode		 *)(p))
#define Z_DATA_LIST_NODE(	p) ((ZDataListNode	 *)(p))
#define Z_DATA_CHAIN_NODE(	p) ((ZDataChainNode	 *)(p))
#define Z_DATA_BINARY_TREE_NODE(p) ((ZDataBinaryTreeNode *)(p))
#define Z_DATA_TREE_NODE(	p) ((ZDataTreeNode	 *)(p))
#define Z_LIST(			p) ((ZList		 *)(p))
#define Z_CHAIN(		p) ((ZChain		 *)(p))
#define Z_BINARY_TREE(		p) ((ZBinaryTree	 *)(p))
#define Z_TREE(			p) ((ZTree		 *)(p))
#define Z_TREE_CURSOR(		p) ((ZTreeCursor	 *)(p))

#endif /* __Z_types_data_H__ */
