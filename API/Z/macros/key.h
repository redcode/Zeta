/* Z Kit - macros/key.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.

This library is  free software: you can redistribute it  and/or modify it under
the terms  of the GNU  Lesser General Public License  as published by  the Free
Software Foundation, either  version 3 of the License, or  (at your option) any
later version.

This library is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

You should have received  a copy of the GNU Lesser General Public License along
with this library. If not, see <http://www.gnu.org/licenses/>. */

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
