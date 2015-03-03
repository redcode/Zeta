/* Q Kit API - keys/introspection.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_keys_introspection_H__
#define __Q_keys_introspection_H__

#define Q_VARIABLE_TYPE_VALUE		     0
#define Q_VARIABLE_TYPE_STRUCTURE	     1
#define Q_VARIABLE_TYPE_POINTER		     2
#define Q_VARIABLE_TYPE_POINTER_TO_VALUE     3
#define Q_VARIABLE_TYPE_POINTER_TO_STRUCTURE 4

#define Q_KEY_BITS_VARIABLE_TYPE 8
#define Q_KEY_LAST_VARIABLE_TYPE Q_VARIABLE_TYPE_POINTER_TO_STRUCTURE

#endif /* __Q_keys_introspection_H__ */
