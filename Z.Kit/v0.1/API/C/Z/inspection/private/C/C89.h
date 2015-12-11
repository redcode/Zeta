/* Z Kit C API - private/C/C89.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_private_C_C89_H__
#define __Z_private_C_C89_H__

/* MARK: - Identification */

#ifndef Z_C
#	include <Z/keys/C.h>

#	define Z_C Z_C89
#	define Z_C_STRING Z_C_STRING_C89
#endif

/* MARK: - Inherited */

#include <Z/inspection/private/C/KR C.h>

/* MARK: - Features */

#define Z_C_HAS_ENUMERATION

#endif /* __Z_private_C_C89_H__ */
