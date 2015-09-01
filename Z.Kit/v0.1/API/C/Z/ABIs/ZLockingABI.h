/* Z Kit C API - ABIs/ZLockingABI.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_ABIs_ZLockingABI_H__
#define __Z_ABIs_ZLockingABI_H__

typedef struct {
	void (* initialize) (void* lock);
	void (* finalize  ) (void* lock);
	void (* will_read ) (void* lock);
	void (* will_write) (void* lock);
	void (* did_read  ) (void* lock);
	void (* did_write ) (void* lock);
} ZLockingABI;

#endif /* __Z_ABIs_ZLockingABI_H__ */
