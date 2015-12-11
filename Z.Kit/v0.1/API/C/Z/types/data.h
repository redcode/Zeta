/* Z Kit C API - types/data.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_types_data_H__
#define __Z_types_data_H__

#include <Z/macros/node.h>

/* MARK: - Arrays */

typedef struct {
	ZPointer data;
	zsize	 size;
} ZArray;

typedef struct {
	void* data;
	zsize size;
	zsize block_size;
} ZBlockArray;

/* MARK: - Nodes */

Z_DEFINE_LIST_NODE	 (ZListNode,	  );
Z_DEFINE_CHAIN_NODE	 (ZChainNode,	  );
Z_DEFINE_TREE_NODE	 (ZTreeNode,	  );
Z_DEFINE_BINARY_TREE_NODE(ZBinaryTreeNode,);
Z_DEFINE_RB_TREE_NODE	 (ZRBTreeNode,	  );
Z_DEFINE_QUADTREE_NODE	 (ZQuadtreeNode,  );
Z_DEFINE_OCTREE_NODE	 (ZOctreeNode,	  );
Z_DEFINE_ARRAY_TREE_NODE (ZArrayTreeNode, );

Z_DEFINE_LIST_NODE	 (ZListNodeWithData,       void* data;);
Z_DEFINE_CHAIN_NODE	 (ZChainNodeWithData,      void* data;);
Z_DEFINE_TREE_NODE	 (ZTreeNodeWithData,       void* data;);
Z_DEFINE_BINARY_TREE_NODE(ZBinaryTreeNodeWithData, void* data;);
Z_DEFINE_RB_TREE_NODE	 (ZRBTreeNodeWithData,	   void* data;);
Z_DEFINE_QUADTREE_NODE	 (ZQuadtreeNodeWithData,   void* data;);
Z_DEFINE_OCTREE_NODE	 (ZOctreeNodeWithData,	   void* data;);
Z_DEFINE_ARRAY_TREE_NODE (ZArrayTreeNodeWithData,  void* data;);

/* MARK: - Node containers */

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

#endif /* __Z_types_data_H__ */
