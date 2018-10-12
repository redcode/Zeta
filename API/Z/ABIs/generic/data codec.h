/* Z Kit - ABIs/generic/data codec.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_ABIs_generic_data_codec_H_
#define _Z_ABIs_generic_data_codec_H_

#include <Z/types/base.h>

typedef zusize	(* ZDataCodecProcess)	(void const* block,
					 zusize	     block_size,
					 void*	     output);

typedef zusize	(* ZDataCodecOutputSize)(void const* block,
					 zusize	     block_size);

typedef ZStatus (* ZDataCodecValidate)	(void const* block,
					 zusize	     block_size,
					 zusize*     error_offset);

typedef struct {
	ZDataCodecProcess    encode;
	ZDataCodecProcess    decode;
	ZDataCodecOutputSize encoding_size;
	ZDataCodecOutputSize decoding_size;
	ZDataCodecValidate   validate_encoding;
	zboolean	     sequential;
} ZDataCodecABI;

#endif /* _Z_ABIs_generic_data_codec_H_ */
