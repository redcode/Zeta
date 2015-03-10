/* Q Kit C API - private/C/C94.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_private_C_H__
#define __Q_private_C_H__

#include <Q/keys/C.h>

/* MARK: - Identification */

#define Q_C	   Q_C94
#define Q_C_STRING Q_C_STRING_C94

/* MARK: - Features */

#define Q_C_HAS_DIGRAPH
#define Q_C_HAS_ENUMERATION

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

#endif /* __Q_private_C_H__ */
