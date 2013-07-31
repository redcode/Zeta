/* Q API - ABIs/QThreadingABI.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2010 RedCode Software.
Released under the terms of the GNU General Public License v2. */

#ifndef __Q_ABIs_QThreadingABI_H__
#define __Q_ABIs_QThreadingABI_H__

#include <Q/types/basics.h>

typedef struct {
} QThreadingABI;

#define Q_THREADING_ABI(p) ((QThreadingABI *)(p))

#endif /* __Q_ABIs_QThreadingABI_H__ */
