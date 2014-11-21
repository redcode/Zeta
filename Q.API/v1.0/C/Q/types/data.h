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

Q_DEFINE_LIST_NODE	 (QDataListNode,       void *data;);
Q_DEFINE_CHAIN_NODE	 (QDataChainNode,      void *data;);
Q_DEFINE_TREE_NODE	 (QDataTreeNode,       void *data;);
Q_DEFINE_BINARY_TREE_NODE(QDataBinaryTreeNode, void *data;);

Q_DEFINE_CHAIN_NODE (QUInt8HashNode,  void *data; quint8  key;);
Q_DEFINE_CHAIN_NODE (QUInt16HashNode, void *data; quint16 key;);
Q_DEFINE_CHAIN_NODE (QUInt32HashNode, void *data; quint32 key;);
Q_DEFINE_CHAIN_NODE (QUInt64HashNode, void *data; quint64 key;);
Q_DEFINE_CHAIN_NODE (QInt8HashNode,   void *data; qint8   key;);
Q_DEFINE_CHAIN_NODE (QInt16HashNode,  void *data; qint16  key;);
Q_DEFINE_CHAIN_NODE (QInt32HashNode,  void *data; qint32  key;);
Q_DEFINE_CHAIN_NODE (QInt64HashNode,  void *data; qint64  key;);

#if Q_IS_AVAILABLE(UINT128) && Q_IS_AVAILABLE(INT128)
	Q_DEFINE_CHAIN_NODE (QUInt128HashNode, void *data; quint128 key;);
	Q_DEFINE_CHAIN_NODE (QInt128HashNode, void *data; qint128 key;);
#endif

#define QHashNode(TYPE) Q_PREFIX_Q(Q_JOIN_2(Q_##TYPE##_FIXED_TYPE_Name, HashNode))

/* MARK: - Casts */

#define Q_ARRAY(		p) ((QArray		 *)(p))
#define Q_BLOCK_ARRAY(		p) ((QBlockArray	 *)(p))
#define Q_LIST_NODE(		p) ((QListNode		 *)(p))
#define Q_CHAIN_NODE(		p) ((QChainNode		 *)(p))
#define Q_TREE_NODE(		p) ((QTreeNode		 *)(p))
#define Q_BINARY_TREE_NODE	p) ((QBinaryTreeNode	 *)(p))
#define Q_DATA_LIST_NODE(	p) ((QDataListNode	 *)(p))
#define Q_DATA_CHAIN_NODE(	p) ((QDataChainNode	 *)(p))
#define Q_DATA_TREE_NODE(	p) ((QDataTreeNode	 *)(p))
#define Q_DATA_BINARY_TREE_NODE(p) ((QDataBinaryTreeNode *)(p))
#define Q_UINT8_HASH_NODE(	p) ((QUInt8HashNode	 *)(p))
#define Q_UINT16_HASH_NODE(	p) ((QUInt16HashNode	 *)(p))
#define Q_UINT32_HASH_NODE(	p) ((QUInt32HashNode	 *)(p))
#define Q_UINT64_HASH_NODE(	p) ((QUInt64HashNode	 *)(p))
#define Q_INT8_HASH_NODE(	p) ((QInt8HashNode	 *)(p))
#define Q_INT16_HASH_NODE(	p) ((QInt16HashNode	 *)(p))
#define Q_INT32_HASH_NODE(	p) ((QInt32HashNode	 *)(p))
#define Q_INT64_HASH_NODE(	p) ((QInt64HashNode	 *)(p))

#if Q_IS_AVAILABLE(UINT128) && Q_IS_AVAILABLE(INT128)
	Q_UINT128_HASH_NODE(p) ((QUInt128HashNode *)(p))
	Q_INT128_HASH_NODE( p) ((QInt128HashNode  *)(p))
#endif

#define Q_HASH_NODE(TYPE) Q_JOIN_3(Q_, Q_##TYPE##_FIXED_TYPE_NAME, _HASH_NODE)

#endif /* __Q_types_data_H__ */
