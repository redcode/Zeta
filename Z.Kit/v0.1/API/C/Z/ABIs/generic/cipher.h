/* Z Kit C API - ABIs/generic/cipher.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright © 2006-2017 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_ABIs_generic_cipher_H__
#define __Z_ABIs_generic_cipher_H__

#include <Z/types/base.h>

#define Z_CIPHER_FEATURE_SEQUENTIAL 1

typedef ZStatus (* ZCipherTestKey)   (void const* key,
				      zsize	   key_size);

typedef void	(* ZCipherSetKey)    (void*	   context,
				      void const* key,
				      zsize	   key_size);

typedef void	(* ZCipherProcess)   (void*	   context,
				      void const* block,
				      zsize	   block_size,
				      void*	   output);

typedef zsize	(* ZCipherOutputSize)(void*	   context,
				      void const* block,
				      zsize	   block_size);

typedef struct {
	ZCipherTestKey	  test_key;
	ZCipherSetKey	  set_key;
	ZCipherProcess	  encipher;
	ZCipherProcess	  decipher;
	ZCipherOutputSize enciphering_size;
	ZCipherOutputSize deciphering_size;
	zsize		  instance_size;
	zsize		  key_minimum_size;
	zsize		  key_maximum_size;
	zsize		  key_word_size;
	zsize		  enciphering_word_size;
	zsize		  deciphering_word_size;
	zuint8		  features;
} ZCipherABI;

#endif /* __Z_ABIs_generic_cipher_H__ */
