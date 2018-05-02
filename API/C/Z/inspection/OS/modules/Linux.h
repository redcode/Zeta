/* Z Kit - inspection/modules/OS/Linux.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_inspection_modules_OS_Linux_H__
#define __Z_inspection_modules_OS_Linux_H__

#define Z_OS_STRING Z_OS_STRING_LINUX

#define Z_OS_HAS_POSIX_THREADING TRUE
#define Z_OS_HAS_NETWORKING	 TRUE
#define Z_OS_HAS_TLS		 TRUE
#define Z_OS_IS_POSIX_LIKE	 TRUE
#define Z_OS_IS_UNIX_LIKE	 TRUE

#define Z_OS_PATH_SLASH_CHARACTER '/'
#define Z_OS_PATH_SLASH_STRING	  "/"

#endif /* __Z_inspection_modules_OS_Linux_H__ */
