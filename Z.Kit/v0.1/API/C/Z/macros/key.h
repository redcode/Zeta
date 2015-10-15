/* Z Kit C API - macros/key.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_macros_key_H__
#define __Z_macros_key_H__

#include <Z/types/base.h>

#define ZKey(		       NAME) zuintN		    (Z_KEY_BITS_##NAME)
#define Z_KEY_BASE_VALUE_TYPE( NAME) Z_UINTN_BASE_VALUE_TYPE(Z_KEY_BITS_##NAME)
#define Z_KEY_FIXED_VALUE_TYPE(NAME) Z_UINTN_VALUE_TYPE	    (Z_KEY_BITS_##NAME)
#define Z_KEY_VALUE_TYPE(      NAME) Z_UINTN_VALUE_TYPE	    (Z_KEY_BITS_##NAME)
#define Z_KEY_VALUE_FORMAT(    NAME) Z_UINTN_VALUE_FORMAT   (Z_KEY_BITS_##NAME)
#define Z_KEY_BITS(	       NAME) Z_KEY_BITS_##NAME
#define Z_KEY_SIZE(	       NAME) Z_UINTN_SIZE	    (Z_KEY_BITS_##NAME)

#endif /* __Z_macros_key_H__ */
