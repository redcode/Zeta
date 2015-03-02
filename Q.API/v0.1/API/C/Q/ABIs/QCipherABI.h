/* Q API - ABIs/QCipherABI.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_ABIs_QCipherABI_H__
#define __Q_ABIs_QCipherABI_H__

#include <Q/types/base.h>

#define Q_CIPHERING_FEATURE_SEQUENTIAL	1
#define Q_CIPHERING_FEATURE_INESTABLE	2

typedef struct {

	void	(* initialize)		(void*	 context,
					 quint8* key,
					 qsize	 key_size);

	void	(* encipher)		(void*	 context,
					 void*	 block,
					 qsize	 block_size,
					 void*	 output);

	void	(* decipher)		(void*	 context,
					 void*	 block,
					 qsize	 block_size,
					 void*	 output);

	qsize	(* enciphering_size)	(void*	 context,
					 void*	 block,
					 qsize	 block_size);

	qsize	(* deciphering_size)	(void*	 context,
					 void*	 block,
					 qsize	 block_size);

	qsize	context_size;
	qsize	minimum_key_size;
	qsize	maximum_key_size;
	qsize	word_size;
	QRatio	ratio;
	quint8	features;

} QCipherABI;

#define Q_CIPHER_ABI(p) ((QCipherABI *)(p))

#endif /* __Q_ABIs_QCipheringABI_H__ */
