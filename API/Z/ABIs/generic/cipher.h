/* Z Kit - ABIs/generic/cipher.h
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

#ifndef _Z_ABIs_generic_cipher_H_
#define _Z_ABIs_generic_cipher_H_

#include <Z/types/base.h>

#define Z_CIPHER_FEATURE_SEQUENTIAL 1

typedef ZStatus (* ZCipherTestKey)   (void const* key,
				      zusize	  key_size);

typedef void	(* ZCipherSetKey)    (void*	  context,
				      void const* key,
				      zusize	  key_size);

typedef void	(* ZCipherProcess)   (void*	  context,
				      void const* block,
				      zusize	  block_size,
				      void*	  output);

typedef zusize	(* ZCipherOutputSize)(void*	  context,
				      void const* block,
				      zusize	  block_size);

typedef struct {
	ZCipherTestKey	  test_key;
	ZCipherSetKey	  set_key;
	ZCipherProcess	  encipher;
	ZCipherProcess	  decipher;
	ZCipherOutputSize enciphering_size;
	ZCipherOutputSize deciphering_size;
	zusize		  instance_size;
	zusize		  key_minimum_size;
	zusize		  key_maximum_size;
	zusize		  key_word_size;
	zusize		  enciphering_word_size;
	zusize		  deciphering_word_size;
	zuint8		  features;
} ZCipherABI;

#endif /* _Z_ABIs_generic_cipher_H_ */
