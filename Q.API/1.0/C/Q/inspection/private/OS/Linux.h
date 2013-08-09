/* Q API - inspection/private/OS/Linux.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2010 RedCode Software.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_inspection_private_OS_H__
#define __Q_inspection_private_OS_H__

#include <Q/constants/basic.h>
#include <Q/keys/OS.h>

#define Q_OS				Q_OS_LINUX
#define Q_OS_STRING			Q_OS_STRING_LINUX
#define Q_OS_IS_POSIX
#define Q_OS_HAS_POSIX_THREADING
#define Q_OS_HAS_NETWORKING
#define Q_OS_HAS_THREAD_LOCAL_STORAGE

#define Q_SYSTEM_TOKEN			POSIX

#endif /* __Q_inspection_private_OS_H__ */
