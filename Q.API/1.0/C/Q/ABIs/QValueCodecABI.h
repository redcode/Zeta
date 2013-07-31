/* Q API - ABIs/QValueCodecABI.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2010 RedCode Software.
Released under the terms of the GNU General Public License v2. */

#ifndef __Q_ABIs_QValueCodecABI_H__
#define __Q_ABIs_QValueCodecABI_H__

#include <Q/types/basics.h>

typedef quint8	QDecodeUInt8		(void*	 block,
					 qsize	 block_size);

typedef quint16	QDecodeUInt16		(void*	 block,
					 qsize	 block_size);

typedef quint32 QDecodeUInt32		(void*	 block,
					 qsize	 block_size);

typedef quint64 QDecodeUInt64		(void*	 block,
					 qsize	 block_size);

typedef qint8	QDecodeInt8		(void*	 block,
					 qsize	 block_size);

typedef quint16	QDecodeInt16		(void*	 block,
					 qsize	 block_size);

typedef quint32 QDecodeInt32		(void*	 block,
					 qsize	 block_size);

typedef quint64 QDecodeInt64		(void*	 block,
					 qsize	 block_size);

typedef qsize	QEncodeUInt8		(quint8	 value,
					 void*	 block);

typedef qsize	QEncodeUInt16		(quint16 value,
					 void*	 block);

typedef qsize	QEncodeUInt32		(quint32 value,
					 void*	 block);

typedef qsize	QEncodeUInt64		(quint64 value,
					 void*	 block);

typedef qsize	QEncodeInt8		(qint8	 value,
					 void*	 block);

typedef qsize	QEncodeInt16		(qint16	 value,
					 void*	 block);

typedef qsize	QEncodeInt32		(qint32	 value,
					 void*	 block);

typedef qsize	QEncodeInt64		(qint64	 value,
					 void*	 block);

typedef struct {
	QDecodeUInt8	decode_uint8,
	QDecodeUInt16	decode_uint16,
	QDecodeUInt32	decode_uint32,
	QDecodeUInt64	decode_uint64,
	QDecodeInt8	decode_int8,
	QDecodeInt16	decode_int16,
	QDecodeInt32	decode_int32,
	QDecodeInt64	decode_int64,
	QEncodeUInt8	encode_uint8,
	QEncodeUInt16	encode_uint16,
	QEncodeUInt32	encode_uint32,
	QEncodeUInt64	encode_uint64,
	QEncodeInt8	encode_int8,
	QEncodeInt16	encode_int16,
	QEncodeInt32	encode_int32,
	QEncodeInt64	encode_int64,
} QValueCodecABI;

#define Q_VALUE_CODEC_ABI(p) ((QValueCodecABI *)(p))

#endif /* __Q_ABIs_QValueCodecABI_H__ */
