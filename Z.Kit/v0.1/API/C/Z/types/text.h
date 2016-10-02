/* Z Kit C API - types/text.h
 _____ 	_______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_|
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_types_text_H__
#define __Z_types_text_H__

#include <Z/types/base.h>
#include <Z/keys/text.h>
#include <Z/keys/formats/character set.h>
#include <Z/macros/key>

typedef struct {
	void*		    data;
	zsize		    size;
	zsize		    character_count;
	ZKey(CHARACTER_SET) character_set;
} ZText;

#endif /* __Z_types_text_H__ */
