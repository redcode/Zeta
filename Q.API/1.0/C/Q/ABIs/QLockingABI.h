/* Q API - ABIs/QLockingABI.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2010 RedCode Software.
Released under the terms of the GNU General Public License v2. */

#ifndef __Q_ABIs_QLockingABI_H__
#define __Q_ABIs_QLockingABI_H__

typedef struct {
	void (* initialize) (void* lock);
	void (* finalize  ) (void* lock);
	void (* will_read ) (void* lock);
	void (* will_write) (void* lock);
	void (* did_read  ) (void* lock);
	void (* did_write ) (void* lock);
} QLockingABI;

#define Q_LOCKING_ABI(p) ((QLockingABI *)(p))

#endif /* __Q_ABIs_QLockingABI_H__ */
