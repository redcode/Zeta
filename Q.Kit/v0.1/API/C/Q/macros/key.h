/* Q C API - macros/key.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_macros_key_H__
#define __Q_macros_key_H__

#undef UINT
#undef _FIXED_TYPE
#undef _BASE_TYPE
#undef _FORMAT
#undef _NAME
#undef _Name
#undef _name

#include <Q/types/base.h>

#define QKey(		      NAME) Q_JOIN_2(quint, Q_KEY_BITS_##NAME)
#define Q_KEY_TYPE(	      NAME) Q_JOIN_4(Q_, UINT, Q_KEY_BITS_##NAME, _FIXED_TYPE)
#define Q_KEY_FIXED_TYPE(     NAME) Q_JOIN_4(Q_, UINT, Q_KEY_BITS_##NAME, _FIXED_TYPE)
#define Q_KEY_BASE_TYPE(      NAME) Q_JOIN_4(Q_, UINT, Q_KEY_BITS_##NAME, _BASE_TYPE)
#define Q_KEY_FORMAT(	      NAME) Q_JOIN_4(Q_, UINT, Q_KEY_BITS_##NAME, _FORMAT)
#define Q_KEY_BITS(	      NAME) Q_KEY_BITS_##NAME
#define Q_KEY_SIZE(	      NAME) (Q_KEY_BITS_##NAME / 8)
#define Q_KEY_FIXED_TYPE_NAME(NAME) Q_JOIN_4(Q_, UINT, Q_KEY_BITS_##NAME, _NAME)
#define Q_KEY_FIXED_TYPE_Name(NAME) Q_JOIN_4(Q_, UINT, Q_KEY_BITS_##NAME, _Name)
#define Q_KEY_FIXED_TYPE_name(NAME) Q_JOIN_4(Q_, UINT, Q_KEY_BITS_##NAME, _name)

#endif /* __Q_macros_key_H__ */
