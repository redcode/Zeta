/* Q API - types/buffering.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2014 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_types_buffering_H__
#define __Q_types_buffering_H__

#include <Q/types/base.h>

typedef struct {
	void* slots[3];
	volatile quint8 flags;
} QTripleBuffer;

typedef struct {
	void* data;
	qsize slot_size;
	qsize slot_count;
	qsize consumption_index;
	qsize production_index;
} QRingBuffer;

#define Q_TRIPLE_BUFFER(p) ((QTripleBuffer *)(p))
#define Q_RING_BUFFER(	p) ((QRingBuffer   *)(p))

#endif /* __Q_types_buffering_H__ */
