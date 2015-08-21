/* Z Kit C API - keys/introspection.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_keys_introspection_H__
#define __Z_keys_introspection_H__

#define Z_VARIABLE_TYPE_VALUE		     0
#define Z_VARIABLE_TYPE_STRUCTURE	     1
#define Z_VARIABLE_TYPE_POINTER		     2
#define Z_VARIABLE_TYPE_POINTER_TO_VALUE     3
#define Z_VARIABLE_TYPE_POINTER_TO_STRUCTURE 4

#define Z_KEY_BITS_VARIABLE_TYPE 8
#define Z_KEY_LAST_VARIABLE_TYPE Z_VARIABLE_TYPE_POINTER_TO_STRUCTURE

#endif /* __Z_keys_introspection_H__ */
