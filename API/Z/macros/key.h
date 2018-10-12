/* Z Kit - macros/key.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_macros_key_H_
#define _Z_macros_key_H_

#include <Z/types/base.h>

#define ZKey(		       NAME) Z_JOIN_2(Z_APPEND_NUMBER_, Z_KEY_BITS_##NAME)(zuint)
#define Z_KEY_VALUE_TYPE(      NAME) Z_JOIN_2(Z_INSERT_NUMBER_, Z_KEY_BITS_##NAME)(Z_UINT, _VALUE_TYPE	    )
#define Z_KEY_FIXED_VALUE_TYPE(NAME) Z_JOIN_2(Z_INSERT_NUMBER_, Z_KEY_BITS_##NAME)(Z_UINT, _FIXED_VALUE_TYPE)
#define Z_KEY_VALUE_FORMAT(    NAME) Z_JOIN_2(Z_INSERT_NUMBER_, Z_KEY_BITS_##NAME)(Z_UINT, _VALUE_FORMAT    )
#define Z_KEY_BITS(	       NAME) Z_KEY_BITS_##NAME
#define Z_KEY_SIZE(	       NAME) Z_JOIN_2(Z_INSERT_NUMBER_, Z_KEY_BITS_##NAME)(Z_UINT, _SIZE	    )

#endif /* _Z_macros_key_H_ */
