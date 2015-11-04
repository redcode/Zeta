/* Z Kit C API - inspection/private/OS/Windows.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_inspection_private_OS_Windows_H__
#define __Z_inspection_private_OS_Windows_H__

#include <Z/keys/OS.h>

#define Z_OS	    Z_OS_WINDOWS
#define Z_OS_STRING Z_OS_STRING_WINDOWS

#define Z_OS_HAS_NETWORKING
#define Z_OS_HAS_THREAD_LOCAL_STORAGE

#define Z_OS_PATH_SLASH_CHARACTER '\\'
#define Z_OS_PATH_SLASH_STRING	  "\\"

#endif /* __Z_inspection_private_OS_Windows_H__ */
