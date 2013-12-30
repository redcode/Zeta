/* Q API - ABIs/QDataCodecABI.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2014 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_ABIs_QDataCodecABI_H__
#define __Q_ABIs_QDataCodecABI_H__

#include <Q/types/base.h>

typedef struct {

	qsize	(* encode)		(void*  block,
					 qsize  block_size,
					 void*  output);

	qsize	(* decode)		(void*  block,
					 qsize  block_size,
					 void*  output);

	qsize	(* encoding_size)	(void*  block,
					 qsize  block_size);

	qsize	(* decoding_size)	(void*  block,
					 qsize  block_size);

	QStatus	(* validate_encoding)	(void*  block,
					 qsize  block_size,
					 qsize* error_offset);

	qboolean sequential;

} QDataCodecABI;

#define Q_DATA_CODEC_ABI(p) ((QDataCodecABI *)(p))

#endif /* __Q_ABIs_QDataCodecABI_H__ */
