/* Q API - inspection/private/OS/Mac OS X.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2010 RedCode Software.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_inspection_private_OS_H__
#define __Q_inspection_private_OS_H__

#include <Q/constants/base.h>
#include <Q/keys/OS.h>

#define Q_OS				Q_OS_MAC_OS_X
#define Q_OS_STRING			Q_OS_STRING_MAC_OS_X
#define Q_OS_IS_UNIX
#define Q_OS_IS_POSIX
#define Q_OS_HAS_POSIX_THREADING
#define Q_OS_HAS_NETWORKING

#define Q_SYSTEM_TOKEN			POSIX

#endif /* __Q_inspection_private_OS_H__ */
