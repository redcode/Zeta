/* Z Kit C API - macros/key.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_macros_key_H__
#define __Z_macros_key_H__

#undef UINT
#undef _FIXED_TYPE
#undef _BASE_TYPE
#undef _FORMAT
#undef _NAME
#undef _Name
#undef _name

#include <Z/types/base.h>

#define ZKey(		      NAME) Z_JOIN_2(zuint, Z_KEY_BITS_##NAME)
#define Z_KEY_TYPE(	      NAME) Z_JOIN_4(Z_, UINT, Z_KEY_BITS_##NAME, _FIXED_TYPE)
#define Z_KEY_FIXED_TYPE(     NAME) Z_JOIN_4(Z_, UINT, Z_KEY_BITS_##NAME, _FIXED_TYPE)
#define Z_KEY_BASE_TYPE(      NAME) Z_JOIN_4(Z_, UINT, Z_KEY_BITS_##NAME, _BASE_TYPE)
#define Z_KEY_FORMAT(	      NAME) Z_JOIN_4(Z_, UINT, Z_KEY_BITS_##NAME, _FORMAT)
#define Z_KEY_BITS(	      NAME) Z_KEY_BITS_##NAME
#define Z_KEY_SIZE(	      NAME) (Z_KEY_BITS_##NAME / 8)
#define Z_KEY_FIXED_TYPE_NAME(NAME) Z_JOIN_4(Z_, UINT, Z_KEY_BITS_##NAME, _NAME)
#define Z_KEY_FIXED_TYPE_Name(NAME) Z_JOIN_4(Z_, UINT, Z_KEY_BITS_##NAME, _Name)
#define Z_KEY_FIXED_TYPE_name(NAME) Z_JOIN_4(Z_, UINT, Z_KEY_BITS_##NAME, _name)

#endif /* __Z_macros_key_H__ */
