/* Q API - inspection/OS.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2014 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_inspection_OS_H__
#define __Q_inspection_OS_H__

#if defined(Q_USE_OS_QS)
#	define Q_OS_FILE QS

#elif defined(Q_USE_OS_LINUX)
#	define Q_OS_FILE Linux

#elif defined(Q_USE_OS_MAC_OS_X) || defined(Q_USE_OS_OS_X)
#	define Q_OS_FILE Mac OS X

#elif defined(Q_USE_OS_IRIX)
#	define Q_OS_FILE IRIX

#elif defined(Q_USE_OS_AIX)
#	define Q_OS_FILE AIX

#elif defined(Q_USE_OS_AMIGA_OS)
#	define Q_OS_FILE AmigaOS

#elif defined(Q_USE_OS_BE_OS)
#	define Q_OS_FILE BeOS

#elif defined(Q_USE_OS_BSD_OS)
#	define Q_OS_FILE BSD OS

#elif defined(Q_USE_OS_UNICOS)
#	define Q_OS_FILE UNICOS

#elif defined(Q_USE_OS_DG_UX)
#	define Q_OS_FILE DG UX

#elif defined(Q_USE_OS_DRAGON_FLY_BSD)
#	define Q_OS_TOKEN DragonFly BSD

#elif defined(Q_USE_OS_DYNIX_PTX)
#	define Q_OS_FILE DYNIX ptx

#elif defined(Q_USE_OS_ECOS)
#	define Q_OS_FILE eCos

#elif defined(Q_USE_OS_FREE_BSD)
#	define Q_OS_FILE FreeBSD

#elif defined(Q_USE_OS_GNU_HURD)
#	define Q_OS_FILE GNU Hurd

#elif defined(Q_USE_OS_HI_UX_MPP)
#	define Q_OS_FILE HI-UX MPP

#elif defined(Q_USE_OS_HP_UX)
#	define Q_OS_FILE HP-UX

#elif defined(Q_USE_OS_INTEGRITY)
#	define Q_OS_FILE INTEGRITY

#elif defined(Q_USE_OS_LYNX_OS)
#	define Q_OS_FILE LynxOS

#elif defined(Q_USE_OS_MAC_OS)
#	define Q_OS_FILE Mac OS

#elif defined(Q_USE_OS_OS_9)
#	define Q_OS_FILE OS-9

#elif defined(Q_USE_OS_MINIX)
#	define Q_OS_FILE MINIX

#elif defined(Q_USE_OS_MPE_IX)
#	define Q_OS_FILE MPE iX

#elif defined(Q_USE_OS_MS_DOS)
#	define Q_OS_FILE MS-DOS

#elif defined(Q_USE_OS_WINDOWS)
#	define Q_OS_FILE Windows

#elif defined(Q_USE_OS_WINDOWS_CE)
#	define Q_OS_FILE Windows CE

#elif defined(Q_USE_OS_NET_BSD)
#	define Q_OS_FILE NetBSD

#elif defined(Q_USE_OS_OPEN_BSD)
#	define Q_OS_FILE OpenBSD

#elif defined(Q_USE_OS_OS_2)
#	define Q_OS_FILE OS 2

#elif defined(Q_USE_OS_QNX)
#	define Q_OS_FILE QNX

#elif defined(Q_USE_OS_RELIANT_UNIX)
#	define Q_OS_FILE Reliant UNIX

#elif defined(Q_USE_OS_SCO_OPEN_SERVER)
#	define Q_OS_FILE SCO OpenServer

#elif defined(Q_USE_OS_TRU64_UNIX)
#	define Q_OS_FILE Tru64 UNIX

#elif defined(Q_USE_OS_ULTRIX)
#	define Q_OS_FILE ULTRIX

#elif defined(Q_USE_OS_UNIX_WARE)
#	define Q_OS_FILE UnixWare

#elif defined(Q_USE_OS_VMS)
#	define Q_OS_FILE VMS

#elif defined(Q_USE_OS_Z_OS)
#	define Q_OS_FILE z OS

#else

#	if	defined(__Venus__)

#		define Q_OS_FILE Venus

#	elif	defined(__linux__)	|| \
		defined(__linux)	|| \
		defined(linux)

#		define Q_OS_FILE Linux

#	elif	defined(__APPLE__)	&& \
		defined(__MACH__)

#		define Q_OS_FILE Mac OS X

#	elif	defined(sgi)		|| \
		defined(__sgi)

#		define Q_OS_FILE IRIX

#	elif	defined(_AIX)		|| \
		defined(__TOS_AIX__)

#		define Q_OS_FILE AIX

#	elif	defined(AMIGA)		|| \
		defined(__amigaos__)

#		define Q_OS_FILE AmigaOS

#	elif	defined(__BEOS__)

#		define Q_OS_FILE BeOS

#	elif	defined(__bsdi__)

#		define Q_OS_FILE BSD OS

#	elif	defined(_UNICOS)

#		define Q_OS_FILE UNICOS

#	elif	defined(DGUX)		|| \
		defined(__DGUX__)	|| \
		defined(__dgux__)

#		define Q_OS_FILE DG UX

#	elif	defined(__DragonFly__)

#		define Q_OS_TOKEN DragonFly BSD

#	elif	defined(_SEQUENT_)	|| \
		defined(sequent)

#		define Q_OS_FILE DYNIX ptx

#	elif	defined(__ECOS)

#		define Q_OS_FILE eCos

#	elif	defined(__FreeBSD__)

#		define Q_OS_FILE FreeBSD

#	elif	defined(__GNU__)

#		define Q_OS_FILE GNU Hurd

#	elif	defined(__hiuxmpp)

#		define Q_OS_FILE HI-UX MPP

#	elif	defined(hpux)		|| \
		defined(_hpux)		|| \
		defined(__hpux)

#		define Q_OS_FILE HP-UX

#	elif	defined(__INTEGRITY)

#		define Q_OS_FILE INTEGRITY

#	elif	defined(__Lynx__)

#		define Q_OS_FILE LynxOS

#	elif	defined(macintosh)	|| \
		defined(Macintosh)

#		define Q_OS_FILE Mac OS

#	elif	defined(__OS9000)	|| \
		defined(_OSK)

#		define Q_OS_FILE OS-9

#	elif	defined(__minix)

#		define Q_OS_FILE MINIX

#	elif	defined(mpeix)		|| \
		defined(__mpexl)

#		define Q_OS_FILE MPE iX

#	elif	defined(__DOS__)	|| \
		defined(MSDOS)		|| \
		defined(_MSDOS)		|| \
		defined(__MSDOS__)

#		define Q_OS_FILE MS-DOS

#	elif	defined(_WIN32)		|| \
		defined(_WIN64)		|| \
		defined(__WIN32__)	|| \
		defined(__TOS_WIN__)	|| \
		defined(__WINDOWS__)

#		define Q_OS_FILE Windows

#	elif	defined(_WIN32_WCE)

#		define Q_OS_FILE Windows CE

#	elif	defined(__NetBSD__)

#		define Q_OS_FILE NetBSD

#	elif	defined(__OpenBSD__)

#		define Q_OS_FILE OpenBSD
 
#	elif	defined(OS2)		|| \
		defined(_OS2)		|| \
		defined(__OS2__)	|| \
		defined(__TOS_OS2__)

#		define Q_OS_FILE OS 2

#	elif	defined(__QNX__)	|| \
		defined(__QNXNTO__)

#		define Q_OS_FILE QNX

#	elif	defined(sinux)

#		define Q_OS_FILE Reliant UNIX

#	elif	defined(M_I386)		|| \
		defined(M_XENIX)	|| \
		defined(_SCO_DS)

#		define Q_OS_FILE SCO OpenServer

/*		define Q_OS_FILE Solaris
		define Q_OS_FILE SunOS */

#	elif	defined(__osf__)	|| \
		defined(__osf)

#		define Q_OS_FILE Tru64 UNIX

#	elif	defined(ultrix)		|| \
		defined(__ultrix)	|| \
		defined(__ultrix__)
		/* Posiblemente también "unix & vax" */

#		define Q_OS_FILE ULTRIX

#	elif	defined(sco)		|| \
		defined(_UNIXWARE7)

#		define Q_OS_FILE UnixWare

#	elif	defined(VMS)		|| \
		defined(__VMS)

#		define Q_OS_FILE VMS


#	elif	defined(__MVS__)	|| \
		defined(__HOS_MVS__)	|| \
		defined(__TOS_MVS__)

#		define Q_OS_FILE z OS

#	endif

#endif

#define	 Q_OS_HEADER <Q/inspection/private/OS/Q_OS_FILE.h>
#include Q_OS_HEADER

#define Q_OS_HAS(feature)	defined(Q_OS_HAS_##feature)
#define Q_OS_IS(what)		defined(Q_OS_IS_##what)

#endif /* __Q_inspection_OS_H__ */
