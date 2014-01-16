/* Q API - functioms/QTripleBuffer.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2014 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_functions_QTripleBuffer_H__
#define __Q_functions_QTripleBuffer_H__

#include <Q/types/base.h>
#include <Q/types/buffering.h>


Q_INLINE
void q_triple_buffer_initialize(
	QTripleBuffer* object,
	void*	       data,
	qsize	       buffer_size
)
	{
	object->dirty = data;
	object->clean = data + buffer_size;
	object->snap  = data + buffer_size * 2;
	}


/* TO DO: needs inline atomics */
/*
Q_INLINE
void q_triple_buffer_flip_writter(QTripleBuffer *object)
	{
	}


Q_INLINE
void q_triple_buffer_new_snap(QTripleBuffer *object)
	{
	}
*/


#endif /* __Q_functions_QTripleBuffer_H__ */
