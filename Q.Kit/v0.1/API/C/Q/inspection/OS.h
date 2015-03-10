/* Q Kit C API - inspection/OS.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_inspection_OS_H__
#define __Q_inspection_OS_H__

#if defined(Q_USE_OS_VENUS)
#	include <Q/inspection/private/OS/Venus.h>

#elif defined(Q_USE_OS_LINUX)
#	include <Q/inspection/private/OS/.h>

#elif defined(Q_USE_OS_MAC_OS_X) || defined(Q_USE_OS_OS_X)
#	include <Q/inspection/private/OS/Mac OS X.h>

#elif defined(Q_USE_OS_IRIX)
#	include <Q/inspection/private/OS/IRIX.h>

#elif defined(Q_USE_OS_AIX)
#	include <Q/inspection/private/OS/AIX.h>

#elif defined(Q_USE_OS_AMIGA_OS)
#	include <Q/inspection/private/OS/AmigaOS.h>

#elif defined(Q_USE_OS_BE_OS)
#	include <Q/inspection/private/OS/BeOS.h>

#elif defined(Q_USE_OS_BSD_OS)
#	include <Q/inspection/private/OS/BSD OS.h>

#elif defined(Q_USE_OS_UNICOS)
#	include <Q/inspection/private/OS/UNICOS.h>

#elif defined(Q_USE_OS_DG_UX)
#	include <Q/inspection/private/OS/DG UX.h>

#elif defined(Q_USE_OS_DRAGON_FLY_BSD)
#	include <Q/inspection/private/OS/DragonFly BSD.h>

#elif defined(Q_USE_OS_DYNIX_PTX)
#	include <Q/inspection/private/OS/DYNIX ptx.h>

#elif defined(Q_USE_OS_ECOS)
#	include <Q/inspection/private/OS/eCos.h>

#elif defined(Q_USE_OS_FREE_BSD)
#	include <Q/inspection/private/OS/FreeBSD.h>

#elif defined(Q_USE_OS_GNU_HURD)
#	include <Q/inspection/private/OS/GNU Hurd.h>

#elif defined(Q_USE_OS_HI_UX_MPP)
#	include <Q/inspection/private/OS/HI-UX MPP.h>

#elif defined(Q_USE_OS_HP_UX)
#	include <Q/inspection/private/OS/HP-UX.h>

#elif defined(Q_USE_OS_INTEGRITY)
#	include <Q/inspection/private/OS/INTEGRITY.h>

#elif defined(Q_USE_OS_LYNX_OS)
#	include <Q/inspection/private/OS/LynxOS.h>

#elif defined(Q_USE_OS_MAC_OS)
#	include <Q/inspection/private/OS/Mac OS.h>

#elif defined(Q_USE_OS_MINIX)
#	include <Q/inspection/private/OS/MINIX.h>

#elif defined(Q_USE_OS_MPE_IX)
#	include <Q/inspection/private/OS/MPE iX.h>

#elif defined(Q_USE_OS_MS_DOS)
#	include <Q/inspection/private/OS/MS-DOS.h>

#elif defined(Q_USE_OS_WINDOWS)
#	include <Q/inspection/private/OS/Windows.h>

#elif defined(Q_USE_OS_WINDOWS_CE)
#	include <Q/inspection/private/OS/Windows CE.h>

#elif defined(Q_USE_OS_NET_BSD)
#	include <Q/inspection/private/OS/NetBSD.h>

#elif defined(Q_USE_OS_OPEN_BSD)
#	include <Q/inspection/private/OS/OpenBSD.h>

#elif defined(Q_USE_OS_OS_2)
#	include <Q/inspection/private/OS/OS 2.h>

#elif defined(Q_USE_OS_OS_9)
#	include <Q/inspection/private/OS/OS-9.h>

#elif defined(Q_USE_OS_QNX)
#	include <Q/inspection/private/OS/QNX.h>

#elif defined(Q_USE_OS_RELIANT_UNIX)
#	include <Q/inspection/private/OS/Reliant UNIX.h>

#elif defined(Q_USE_OS_SCO_OPEN_SERVER)
#	include <Q/inspection/private/OS/SCO OpenServer.h>

#elif defined(Q_USE_OS_TRU64_UNIX)
#	include <Q/inspection/private/OS/Tru64 UNIX.h>

#elif defined(Q_USE_OS_ULTRIX)
#	include <Q/inspection/private/OS/ULTRIX.h>

#elif defined(Q_USE_OS_UNIX_WARE)
#	include <Q/inspection/private/OS/UnixWare.h>

#elif defined(Q_USE_OS_VMS)
#	include <Q/inspection/private/OS/VMS.h>

#elif defined(Q_USE_OS_Z_OS)
#	include <Q/inspection/private/OS/z OS.h>

#else

#	if	defined(__Venus__)
#		include <Q/inspection/private/OS/Venus.h>

#	elif	defined(__linux__)	|| \
		defined(__linux)	|| \
		defined(linux)
#		include <Q/inspection/private/OS/Linux.h>

#	elif	defined(__APPLE__)	&& \
		defined(__MACH__)
#		include <Q/inspection/private/OS/Mac OS X.h>

#	elif	defined(sgi)		|| \
		defined(__sgi)
#		include <Q/inspection/private/OS/IRIX.h>

#	elif	defined(_AIX)		|| \
		defined(__TOS_AIX__)
#		include <Q/inspection/private/OS/AIX.h>

#	elif	defined(AMIGA)		|| \
		defined(__amigaos__)
#		include <Q/inspection/private/OS/AmigaOS.h>

#	elif	defined(__BEOS__)
#		include <Q/inspection/private/OS/BeOS.h>

#	elif	defined(__bsdi__)
#		include <Q/inspection/private/OS/BSD OS.h>

#	elif	defined(_UNICOS)
#		include <Q/inspection/private/OS/UNICOS.h>

#	elif	defined(DGUX)		|| \
		defined(__DGUX__)	|| \
		defined(__dgux__)
#		include <Q/inspection/private/OS/DG UX.h>

#	elif	defined(__DragonFly__)
#		include <Q/inspection/private/OS/DragonFly BSD.h>

#	elif	defined(_SEQUENT_)	|| \
		defined(sequent)
#		include <Q/inspection/private/OS/DYNIX ptx.h>

#	elif	defined(__ECOS)
#		include <Q/inspection/private/OS/eCos.h>

#	elif	defined(__FreeBSD__)
#		include <Q/inspection/private/OS/FreeBSD.h>

#	elif	defined(__GNU__)
#		include <Q/inspection/private/OS/GNU Hurd.h>

#	elif	defined(__hiuxmpp)
#		include <Q/inspection/private/OS/HI-UX MPP.h>

#	elif	defined(hpux)		|| \
		defined(_hpux)		|| \
		defined(__hpux)
#		include <Q/inspection/private/OS/HP-UX.h>

#	elif	defined(__INTEGRITY)
#		include <Q/inspection/private/OS/INTEGRITY.h>

#	elif	defined(__Lynx__)
#		include <Q/inspection/private/OS/LynxOS.h>

#	elif	defined(macintosh)	|| \
		defined(Macintosh)
#		include <Q/inspection/private/OS/Mac OS.h>

#	elif	defined(__minix)
#		include <Q/inspection/private/OS/MINIX.h>

#	elif	defined(mpeix)		|| \
		defined(__mpexl)
#		include <Q/inspection/private/OS/MPE iX.h>

#	elif	defined(__DOS__)	|| \
		defined(MSDOS)		|| \
		defined(_MSDOS)		|| \
		defined(__MSDOS__)
#		include <Q/inspection/private/OS/MS-DOS.h>

#	elif	defined(_WIN32)		|| \
		defined(_WIN64)		|| \
		defined(__WIN32__)	|| \
		defined(__TOS_WIN__)	|| \
		defined(__WINDOWS__)
#		include <Q/inspection/private/OS/Windows.h>

#	elif	defined(_WIN32_WCE)
#		include <Q/inspection/private/OS/Windows CE.h>

#	elif	defined(__NetBSD__)
#		include <Q/inspection/private/OS/NetBSD.h>

#	elif	defined(__OpenBSD__)
#		include <Q/inspection/private/OS/OpenBSD.h>

#	elif	defined(OS2)		|| \
		defined(_OS2)		|| \
		defined(__OS2__)	|| \
		defined(__TOS_OS2__)
#		include <Q/inspection/private/OS/OS 2.h>

#	elif	defined(__OS9000)	|| \
		defined(_OSK)
#		include <Q/inspection/private/OS/OS-9.h>

#	elif	defined(__QNX__)	|| \
		defined(__QNXNTO__)
#		include <Q/inspection/private/OS/QNX.h>

#	elif	defined(sinux)
#		include <Q/inspection/private/OS/Reliant UNIX.h>

#	elif	defined(M_I386)		|| \
		defined(M_XENIX)	|| \
		defined(_SCO_DS)
#		include <Q/inspection/private/OS/SCO OpenServer.h>

/*		define Q_OS_FILE Solaris
		define Q_OS_FILE SunOS */

#	elif	defined(__osf__)	|| \
		defined(__osf)
#		include <Q/inspection/private/OS/Tru64 UNIX.h>

#	elif	defined(ultrix)		|| \
		defined(__ultrix)	|| \
		defined(__ultrix__)
		/* Posiblemente también "unix & vax" */
#		include <Q/inspection/private/OS/ULTRIX.h>

#	elif	defined(sco)		|| \
		defined(_UNIXWARE7)
#		include <Q/inspection/private/OS/UnixWare.h>

#	elif	defined(VMS)		|| \
		defined(__VMS)
#		include <Q/inspection/private/OS/VMS.h>


#	elif	defined(__MVS__)	|| \
		defined(__HOS_MVS__)	|| \
		defined(__TOS_MVS__)
#		include <Q/inspection/private/OS/z OS.h>

#	endif

#endif

#define Q_OS_HAS(feature) defined(Q_OS_HAS_##feature)
#define Q_OS_IS(what)	  defined(Q_OS_IS_##what)

#endif /* __Q_inspection_OS_H__ */
