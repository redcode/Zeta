/* Z Kit C API - ABIs/ZValueCodecABI.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_ABIs_ZValueCodecABI_H__
#define __Z_ABIs_ZValueCodecABI_H__

#include <Z/types/base.h>

typedef zuint8	ZDecodeUInt8		(void*	 block,
					 zsize	 block_size);

typedef zuint16	ZDecodeUInt16		(void*	 block,
					 zsize	 block_size);

typedef zuint32 ZDecodeUInt32		(void*	 block,
					 zsize	 block_size);

typedef zuint64 ZDecodeUInt64		(void*	 block,
					 zsize	 block_size);

typedef zint8	ZDecodeInt8		(void*	 block,
					 zsize	 block_size);

typedef zuint16	ZDecodeInt16		(void*	 block,
					 zsize	 block_size);

typedef zuint32 ZDecodeInt32		(void*	 block,
					 zsize	 block_size);

typedef zuint64 ZDecodeInt64		(void*	 block,
					 zsize	 block_size);

typedef zsize	ZEncodeUInt8		(zuint8	 value,
					 void*	 block);

typedef zsize	ZEncodeUInt16		(zuint16 value,
					 void*	 block);

typedef zsize	ZEncodeUInt32		(zuint32 value,
					 void*	 block);

typedef zsize	ZEncodeUInt64		(zuint64 value,
					 void*	 block);

typedef zsize	ZEncodeInt8		(zint8	 value,
					 void*	 block);

typedef zsize	ZEncodeInt16		(zint16	 value,
					 void*	 block);

typedef zsize	ZEncodeInt32		(zint32	 value,
					 void*	 block);

typedef zsize	ZEncodeInt64		(zint64	 value,
					 void*	 block);

typedef struct {
	ZDecodeUInt8	decode_uint8,
	ZDecodeUInt16	decode_uint16,
	ZDecodeUInt32	decode_uint32,
	ZDecodeUInt64	decode_uint64,
	ZDecodeInt8	decode_int8,
	ZDecodeInt16	decode_int16,
	ZDecodeInt32	decode_int32,
	ZDecodeInt64	decode_int64,
	ZEncodeUInt8	encode_uint8,
	ZEncodeUInt16	encode_uint16,
	ZEncodeUInt32	encode_uint32,
	ZEncodeUInt64	encode_uint64,
	ZEncodeInt8	encode_int8,
	ZEncodeInt16	encode_int16,
	ZEncodeInt32	encode_int32,
	ZEncodeInt64	encode_int64,
} ZValueCodecABI;

#endif /* __Z_ABIs_ZValueCodecABI_H__ */
