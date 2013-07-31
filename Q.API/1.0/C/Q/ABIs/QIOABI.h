/* Q API - ABIs/QIOABI.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2010 RedCode Software.
Released under the terms of the GNU General Public License v2. */

#ifndef __Q_ABIs_QIOABI_H__
#define __Q_ABIs_QIOABI_H__

#include <Q/types/basics.h>

typedef void*	(* QRead)	(void*	context,
				 qsize	size,
				 void*	buffer);

typedef void*	(* QWrite)	(void*	context,
				 void*	block,
				 qsize	block_size);

typedef struct {
	QRead	read;
	QWrite	write;
} QIOABI;

#define Q_IO_ABI(p) ((QIOABI *)(p))

#endif /* __Q_ABIs_QIOABI_H__ */
