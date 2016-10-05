/* Z Kit C API - inspection/modules/OS/Mac OS X.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_inspection_modules_OS_Mac_OS_X_H__
#define __Z_inspection_modules_OS_Mac_OS_X_H__

#include <Z/constants/base.h>
#include <Z/keys/OS.h>

#define Z_OS_STRING Z_OS_STRING_MAC_OS_X

#define Z_OS_HAS_POSIX_THREADING TRUE
#define Z_OS_HAS_NETWORKING	 TRUE
#define Z_OS_IS_POSIX		 TRUE
#define Z_OS_IS_UNIX		 TRUE

#define Z_OS_PATH_SLASH_CHARACTER '/'
#define Z_OS_PATH_SLASH_STRING	  "/"

#endif /* __Z_inspection_modules_OS_Mac_OS_X_H__ */
