/* Z Kit C API - private/C/KR C.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_private_C_KR_C_H__
#define __Z_private_C_KR_C_H__

/* MARK: - Identification */

#ifndef Z_C
#	include <Z/keys/C.h>

#	define Z_C Z_KR_C
#	define Z_C_STRING Z_C_STRING_KR_C
#endif

/* MARK: - Types */

#define Z_C_HAS_TYPE_FLOAT
#define Z_C_HAS_TYPE_DOUBLE
#define Z_C_HAS_TYPE_LDOUBLE /* long double */

/* MARK: - Type qualifiers */

#define Z_C_HAS_TYPE_QUALIFIER_CONSTANT /* const    */
#define Z_C_HAS_TYPE_QUALIFIER_VOLATILE /* volatile */

/* MARK: - Storage classes */

#define Z_C_HAS_STORAGE_CLASS_AUTO     /* auto	   */
#define Z_C_HAS_STORAGE_CLASS_EXTERN   /* extern   */
#define Z_C_HAS_STORAGE_CLASS_REGISTER /* register */
#define Z_C_HAS_STORAGE_CLASS_STATIC   /* static   */

/* MARK: - Operators */

#define Z_C_HAS_OPERATOR_SIZE_OF /* sizeof() */

#endif /* __Z_private_C_KR_C_H__ */
