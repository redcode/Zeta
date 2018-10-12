/* Z Kit - types/data.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_types_data_H_
#define _Z_types_data_H_

#include <Z/macros/node.h>

/* MARK: - Arrays */

typedef struct {
	ZPointer data;
	zusize	 size;
} ZArray;

typedef struct {
	void*  data;
	zusize size;
	zusize block_size;
} ZBlockArray;

/* MARK: - Abstract nodes */

Z_DEFINE_LIST_NODE	 (ZListNode,,	   );
Z_DEFINE_CHAIN_NODE	 (ZChainNode,,	   );
Z_DEFINE_TREE_NODE	 (ZTreeNode,,	   );
Z_DEFINE_BINARY_TREE_NODE(ZBinaryTreeNode,,);
Z_DEFINE_RB_TREE_NODE	 (ZRBTreeNode,,	   );
Z_DEFINE_QUADTREE_NODE	 (ZQuadtreeNode,,  );
Z_DEFINE_OCTREE_NODE	 (ZOctreeNode,,	   );
Z_DEFINE_ARRAY_TREE_NODE (ZArrayTreeNode,, );

/* MARK: - Nodes */

Z_DEFINE_LIST_NODE	 (ZListNodeWithData,,	    ZPointer data;);
Z_DEFINE_CHAIN_NODE	 (ZChainNodeWithData,,	    ZPointer data;);
Z_DEFINE_TREE_NODE	 (ZTreeNodeWithData,,	    ZPointer data;);
Z_DEFINE_BINARY_TREE_NODE(ZBinaryTreeNodeWithData,, ZPointer data;);
Z_DEFINE_RB_TREE_NODE	 (ZRBTreeNodeWithData,,	    ZPointer data;);
Z_DEFINE_QUADTREE_NODE	 (ZQuadtreeNodeWithData,,   ZPointer data;);
Z_DEFINE_OCTREE_NODE	 (ZOctreeNodeWithData,,	    ZPointer data;);
Z_DEFINE_ARRAY_TREE_NODE (ZArrayTreeNodeWithData,,  ZPointer data;);

/* MARK: - Node containers */

typedef struct {
	ZListNode* first_node;
	zusize	   size;
	ZListNode* last_node;
} ZList;	

typedef struct {
	ZChainNode* first_node;
	zusize	    size;
	ZChainNode* last_node;
} ZChain;

#endif /* _Z_types_data_H_ */
