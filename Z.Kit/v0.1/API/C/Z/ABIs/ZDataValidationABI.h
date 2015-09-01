/* Z Kit C API - ABIs/ZDataCodecABI.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_ABIs_ZDataCodecABI_H__
#define __Z_ABIs_ZDataCodecABI_H__

#include <Z/types/base.h>

typedef struct {
	ZStatus (* validate) (void*  block, zsize  block_size, zsize* error_offset);

	zboolean sequential;
} ZDataCodecABI;

#endif /* __Z_ABIs_ZDataCodecABI_H__ */
