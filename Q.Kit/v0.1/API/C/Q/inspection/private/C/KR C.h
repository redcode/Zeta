/* Q Kit C API - private/C/KR C.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_private_C_KR_C_H__
#define __Q_private_C_KR_C_H__

/* MARK: - Identification */

#ifndef Q_C
#	include <Q/keys/C.h>

#	define Q_C Q_KR_C
#	define Q_C_STRING Q_C_STRING_KR_C
#endif

/* MARK: - Types */

#define Q_C_HAS_TYPE_LDOUBLE

/* MARK: - Type qualifiers */

#define Q_C_HAS_TYPE_QUALIFIER_CONSTANT
#define Q_C_HAS_TYPE_QUALIFIER_VOLATILE

/* MARK: - Storage classes */

#define Q_C_HAS_STORAGE_CLASS_AUTO
#define Q_C_HAS_STORAGE_CLASS_REGISTER
#define Q_C_HAS_STORAGE_CLASS_STATIC
#define Q_C_HAS_STORAGE_CLASS_EXTERN

/* MARK: - Operators */

#define Q_C_HAS_OPERATOR_SIZE_OF

#endif /* __Q_private_C_KR_C_H__ */
