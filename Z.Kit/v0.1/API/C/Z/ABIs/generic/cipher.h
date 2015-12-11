/* Z Kit C API - ABIs/generic/cipher.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_ABIs_generic_cipher_H__
#define __Z_ABIs_generic_cipher_H__

#include <Z/types/base.h>

#define Z_CIPHERING_FEATURE_SECUENTIAL	1
#define Z_CIPHERING_FEATURE_INESTABLE	2

typedef ZStatus (* ZCipherTestKey)	     (void const* key,
					      zsize	  key_size);

typedef void	(* ZCipherSetKey)	     (void*	  context,
					      void const* key,
					      zsize	  key_size);

typedef void	(* ZCipherProcess)	     (void*	  context,
					      void const* block,
					      zsize	  block_size,
					      void*	  output);

typedef zsize	(* ZCipherProcessOutputSize) (void*	  context,
					      void const* block,
					      zsize	  block_size);

typedef struct {
	ZCipherTestKey		 test_key;
	ZCipherSetKey		 set_key;
	ZCipherProcess		 encipher;
	ZCipherProcess		 decipher;
	ZCipherProcessOutputSize enciphering_size;
	ZCipherProcessOutputSize deciphering_size;
	zsize			 context_size;
	zsize			 key_minimum_size;
	zsize			 key_maximum_size;
	zsize			 key_word_size;
	zsize			 deciphered_word_size;
	zsize			 enciphered_word_size;
	zuint8			 features;
} ZCipherABI;

#endif /* __Z_ABIs_generic_cipher_H__ */
