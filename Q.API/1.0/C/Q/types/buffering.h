/* Q API - types/buffering.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2014 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_types_buffering_H__
#define __Q_types_buffering_H__

typedef struct {
	void* dirty;
	void* clean;
	void* snap;
} QTripleBuffer;

#endif /* __Q_types_buffering_H__ */
