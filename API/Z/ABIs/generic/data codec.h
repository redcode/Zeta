/* Z Kit - ABIs/generic/data codec.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.

This library  is free software: you  can redistribute it and/or  modify it under
the terms  of the  GNU Lesser General  Public License as  published by  the Free
Software Foundation,  either version 3 of  the License, or (at  your option) any
later version.

This library is distributed in the hope  that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty  of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

You should have received  a copy of the GNU Lesser  General Public License along
with this library. If not, see <http://www.gnu.org/licenses/>. */

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
