/* Z Kit C API - ABIs/ZCipherABI.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_ABIs_ZCipherABI_H__
#define __Z_ABIs_ZCipherABI_H__

#include <Z/types/base.h>

#define Z_CIPHERING_FEATURE_SEZUENTIAL	1
#define Z_CIPHERING_FEATURE_INESTABLE	2

typedef struct {
	void  (* initialize)	   (void*   context,
				    zuint8* key,
				    zsize   key_size);

	void  (* encipher)	   (void*   context,
				    void*   block,
				    zsize   block_size,
				    void*   output);

	void  (* decipher)	   (void*   context,
				    void*   block,
				    zsize   block_size,
				    void*   output);

	zsize (* enciphering_size) (void*   context,
				    void*   block,
				    zsize   block_size);

	zsize (* deciphering_size) (void*   context,
				    void*   block,
				    zsize   block_size);

	zsize	context_size;
	zsize	minimum_key_size;
	zsize	maximum_key_size;
	zsize	word_size;
	ZRatio	ratio;
	zuint8	features;
} ZCipherABI;

#define Z_CIPHER_ABI(p) ((ZCipherABI *)(p))

#endif /* __Z_ABIs_ZCipheringABI_H__ */
