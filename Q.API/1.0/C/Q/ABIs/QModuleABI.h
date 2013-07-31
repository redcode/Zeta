/* Q API - ABIs/QModuleABI.h>
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2010 RedCode Software.
Released under the terms of the GNU General Public License v2. */

#ifndef __Q_ABIs_QModuleABI_H__
#define __Q_ABIs_QModuleABI_H__

#include <Q/types/basics.h>

typedef struct {
	void*	(* load  )	(quchar *module_name);
	void	(* unload)	(void *module);
	void*	(* get_symbol)	(quchar *symbol);
} QModuleABI;

#define Q_MODULE_ABI(p) ((QModuleABI *)(p))

#endif /* __Q_ABIs_QModuleABI_H__ */
