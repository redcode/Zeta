/* Z Kit C API - inspection/private/OS/iPhone OS.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_inspection_private_OS_H__
#define __Z_inspection_private_OS_H__

#include <Z/keys/OS.h>

#define Z_OS	    Z_OS_IPHONE_OS
#define Z_OS_STRING Z_OS_STRING_IPHONE_OS

#define Z_OS_IS_UNIX
#define Z_OS_IS_POSIX
#define Z_OS_HAS_POSIX_THREADING
#define Z_OS_HAS_NETWORKING

#define Z_SYSTEM_TOKEN POSIX

#endif /* __Z_inspection_private_OS_H__ */
