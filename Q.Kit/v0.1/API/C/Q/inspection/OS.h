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
#	include <Q/inspection/private/OS/Linux.h>

#elif defined(Q_USE_OS_ANDROID)
#	include <Q/inspection/private/OS/Android.h>

#elif defined(Q_USE_OS_FREE_BSD)
#	include <Q/inspection/private/OS/FreeBSD.h>

#elif defined(Q_USE_OS_NET_BSD)
#	include <Q/inspection/private/OS/NetBSD.h>

#elif defined(Q_USE_OS_OPEN_BSD)
#	include <Q/inspection/private/OS/OpenBSD.h>

#elif defined(Q_USE_OS_MAC_OS_X) || defined(Q_USE_OS_OS_X)
#	include <Q/inspection/private/OS/Mac OS X.h>

#elif defined(Q_USE_OS_IPHONE_OS) || defined(Q_USE_OS_IOS)
#	include <Q/inspection/private/OS/iPhone OS.h>

#elif defined(Q_USE_OS_WINDOWS)
#	include <Q/inspection/private/OS/Windows.h>

#elif defined(Q_USE_OS_AIX)
#	include <Q/inspection/private/OS/AIX.h>

#elif defined(Q_USE_OS_AMIGA_OS)
#	include <Q/inspection/private/OS/AmigaOS.h>

#elif defined(Q_USE_OS_AEGIS)
#	include <Q/inspection/private/OS/AEGIS.h>

#elif defined(Q_USE_OS_DOMAIN_OS)
#	include <Q/inspection/private/OS/Domain-OS.h>

#elif defined(Q_USE_OS_BADA)
#	include <Q/inspection/private/OS/Bada.h>

#elif defined(Q_USE_OS_BE_OS)
#	include <Q/inspection/private/OS/BeOS.h>

#elif defined(Q_USE_OS_BLUE_GENE)
#	include <Q/inspection/private/OS/Blue Gene.h>

#elif defined(Q_USE_OS_BSD_386) || defined(Q_USE_OS_BSD_I) || defined(Q_USE_OS_BSD_OS)
#	include <Q/inspection/private/OS/BSD-386.h>

#elif defined(Q_USE_OS_CONVEX_OS)
#	include <Q/inspection/private/OS/ConvexOS.h>

#elif defined(Q_USE_OS_DC_OSX)
#	include <Q/inspection/private/OS/DC-OSx.h>

#elif defined(Q_USE_OS_DEC_OSF_1) || defined(Q_USE_OS_DIGITAL_UNIX) || defined(Q_USE_OS_TRU64_UNIX)
#	include <Q/inspection/private/OS/DEC OSF-1.h>

#elif defined(Q_USE_OS_DG_UX)
#	include <Q/inspection/private/OS/DG-UX.h>

#elif defined(Q_USE_OS_DRAGONFLY_BSD)
#	include <Q/inspection/private/OS/DragonFly BSD.h>

#elif defined(Q_USE_OS_DYNIX)
#	include <Q/inspection/private/OS/DYNIX.h>

#elif defined(Q_USE_OS_DYNIX_PTX)
#	include <Q/inspection/private/OS/DYNIX-ptx.h>

#elif defined(Q_USE_OS_ECOS)
#	include <Q/inspection/private/OS/eCos.h>

#elif defined(Q_USE_OS_GNU_HURD)
#	include <Q/inspection/private/OS/GNU Hurd.h>

#elif defined(Q_USE_OS_HI_UX_MPP)
#	include <Q/inspection/private/OS/HI-UX MPP.h>

#elif defined(Q_USE_OS_HP_UX)
#	include <Q/inspection/private/OS/HP-UX.h>

#elif defined(Q_USE_OS_INTEGRITY)
#	include <Q/inspection/private/OS/INTEGRITY.h>

#elif defined(Q_USE_OS_IRIX)
#	include <Q/inspection/private/OS/IRIX.h>

#elif defined(Q_USE_OS_LYNX_OS)
#	include <Q/inspection/private/OS/LynxOS.h>

#elif defined(Q_USE_OS_MAC_OS)
#	include <Q/inspection/private/OS/Mac OS.h>

#elif defined(Q_USE_OS_MINIX)
#	include <Q/inspection/private/OS/MINIX.h>

#elif defined(Q_USE_OS_MORPH_OS)
#	include <Q/inspection/private/OS/MorphOS.h>

#elif defined(Q_USE_OS_MPE)
#	include <Q/inspection/private/OS/MPE.h>

#elif defined(Q_USE_OS_MPE_IX)
#	include <Q/inspection/private/OS/MPE-iX.h>

#elif defined(Q_USE_OS_MPE_XL)
#	include <Q/inspection/private/OS/MPE-XL.h>

#elif defined(Q_USE_OS_MS_DOS)
#	include <Q/inspection/private/OS/MS-DOS.h>

#elif defined(Q_USE_OS_MVS)
#	include <Q/inspection/private/OS/MVS.h>

#elif defined(Q_USE_OS_NON_STOP_OS)
#	include <Q/inspection/private/OS/NonStop OS.h>

#elif defined(Q_USE_OS_NUCLEUS_RTOS)
#	include <Q/inspection/private/OS/Nucleus RTOS.h>

#elif defined(Q_USE_OS_OS_2)
#	include <Q/inspection/private/OS/OS-2.h>

#elif defined(Q_USE_OS_OS_9)
#	include <Q/inspection/private/OS/OS-9.h>

#elif defined(Q_USE_OS_OS_360)
#	include <Q/inspection/private/OS/OS-360.h>

#elif defined(Q_USE_OS_OS_390)
#	include <Q/inspection/private/OS/OS-390.h>

#elif defined(Q_USE_OS_OS_400) || defined(Q_USE_OS_I5_OS) || defined(Q_USE_OS_IBM_I)
#	include <Q/inspection/private/OS/OS-400.h>

#elif defined(Q_USE_OS_PALM_OS)
#	include <Q/inspection/private/OS/Palm OS.h>

#elif defined(Q_USE_OS_PLAN_9)
#	include <Q/inspection/private/OS/Plan 9.h>

#elif defined(Q_USE_OS_QNX)
#	include <Q/inspection/private/OS/QNX.h>

#elif defined(Q_USE_OS_SCO_UNIX_SYSTEM_V) || defined(Q_USE_OS_OPEN_DESKTOP) || \
      defined(Q_USE_OS_SCO_UNIX)	  || defined(Q_USE_OS_SCO_OPEN_SERVER)
#	include <Q/inspection/private/OS/SCO UNIX System V.h>

#elif defined(Q_USE_OS_SINIX) || defined(Q_USE_OS_RELIANT_UNIX)
#	include <Q/inspection/private/OS/SINIX.h>

#elif defined(Q_USE_OS_SUN_OS) || defined(Q_USE_OS_SOLARIS)
#	include <Q/inspection/private/OS/SunOS.h>

#elif defined(Q_USE_OS_SYLLABLE)
#	include <Q/inspection/private/OS/Syllable.h>

#elif defined(Q_USE_OS_SYMBIAN)
#	include <Q/inspection/private/OS/Symbian.h>

#elif defined(Q_USE_OS_ULTRIX)
#	include <Q/inspection/private/OS/ULTRIX.h>

#elif defined(Q_USE_OS_UNICOS)
#	include <Q/inspection/private/OS/UNICOS.h>

#elif defined(Q_USE_OS_UNICOS_MP)
#	include <Q/inspection/private/OS/UNICOS-mp.h>

#elif defined(Q_USE_OS_UNIX_WARE) || defined(Q_USE_OS_OPEN_UNIX)
#	include <Q/inspection/private/OS/UnixWare.h>

#elif defined(Q_USE_OS_UTS)
#	include <Q/inspection/private/OS/UTS.h>

#elif defined(Q_USE_OS_VMS)
#	include <Q/inspection/private/OS/VMS.h>

#elif defined(Q_USE_OS_VOS)
#	include <Q/inspection/private/OS/VOS.h>

#elif defined(Q_OS_VX_WORKS)
#	include <Q/inspection/private/OS/VxWorks.h>

#elif defined(Q_USE_OS_WINDOWS_CE)
#	include <Q/inspection/private/OS/Windows CE.h>

#elif defined(Q_USE_OS_XENIX)
#	include <Q/inspection/private/OS/Xenix.h>

#elif defined(Q_USE_OS_Z_OS)
#	include <Q/inspection/private/OS/z-OS.h>

#elif defined(Q_USE_OS_Z_TPF)
#	include <Q/inspection/private/OS/z-TPF.h>

#elif defined(Q_USE_OS_Z_VM)
#	include <Q/inspection/private/OS/z-VM.h>

#elif defined(Q_USE_OS_Z_VSE)
#	include <Q/inspection/private/OS/z-VSE.h>

#else

#	if defined(__Venus__)
#		include <Q/inspection/private/OS/Venus.h>

#	elif defined(__linux__) || defined(__linux) || defined(linux)
#		include <Q/inspection/private/OS/Linux.h>

#	elif defined(__ANDROID__)
#		include <Q/inspection/private/OS/Android.h>

#	elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
#		include <Q/inspection/private/OS/FreeBSD.h>

#	elif defined(__NetBSD__)
#		include <Q/inspection/private/OS/NetBSD.h>

#	elif defined(__OpenBSD__)
#		include <Q/inspection/private/OS/OpenBSD.h>

#	elif defined(__APPLE__)	&& defined(__MACH__)
#		include <TargetConditionals.h>

#		if TARGET_OS_IPHONE
#			include <Q/inspection/private/OS/iPhone OS.h>
#		else
#			include <Q/inspection/private/OS/Mac OS X.h>
#		endif

#	elif defined(_WIN16)	|| defined(_WIN32)	|| defined(_WIN64) || \
	     defined(__WIN32__)	|| defined(__TOS_WIN__)	|| defined(__WINDOWS__)
#		include <Q/inspection/private/OS/Windows.h>

#	elif defined(_AIX) || defined(__TOS_AIX__)
#		include <Q/inspection/private/OS/AIX.h>

#	elif defined(__amigaos__) || defined(AMIGA)
#		include <Q/inspection/private/OS/AmigaOS.h>

#	elif defined(aegis)
#		include <Q/inspection/private/OS/AEGIS.h>

#	elif defined(apollo)
#		include <Q/inspection/private/OS/Domain-OS.h>

/*#	elif defined()
#		include <Q/inspection/private/OS/Bada.h>*/

#	elif defined(__BEOS__)
#		include <Q/inspection/private/OS/BeOS.h>

#	elif defined(__bg__) || defined(__THW_BLUEGENE__)
#		include <Q/inspection/private/OS/Blue Gene.h>

#	elif defined(__bsdi__)
#		include <Q/inspection/private/OS/BSD-386.h>

#	elif defined(__convex__)
#		include <Q/inspection/private/OS/ConvexOS.h>

#	elif defined(pyr)
#		include <Q/inspection/private/OS/DC-OSx.h>

#	elif defined(__osf__) || defined(__osf)
#		include <Q/inspection/private/OS/DEC OSF-1.h>

#	elif defined(__DGUX__) || defined(__dgux__) || defined(DGUX)
#		include <Q/inspection/private/OS/DG-UX.h>

#	elif defined(__DragonFly__)
#		include <Q/inspection/private/OS/DragonFly BSD.h>

/*#	elif defined()
#		include <Q/inspection/private/OS/DYNIX.h>*/

#	elif defined(_SEQUENT_)	|| defined(sequent)
#		include <Q/inspection/private/OS/DYNIX-ptx.h>

#	elif defined(__ECOS)
#		include <Q/inspection/private/OS/eCos.h>

#	elif defined(__gnu_hurd__) /*|| defined(__GNU__)*/
#		include <Q/inspection/private/OS/GNU Hurd.h>

#	elif defined(__hiuxmpp)
#		include <Q/inspection/private/OS/HI-UX MPP.h>

#	elif defined(__hpux) || defined(_hpux) || defined(hpux)
#		include <Q/inspection/private/OS/HP-UX.h>

#	elif defined(__INTEGRITY)
#		include <Q/inspection/private/OS/INTEGRITY.h>

#	elif defined(__sgi) || defined(sgi)
#		include <Q/inspection/private/OS/IRIX.h>

#	elif defined(__Lynx__)
#		include <Q/inspection/private/OS/LynxOS.h>

#	elif defined(Macintosh) || defined(macintosh)
#		include <Q/inspection/private/OS/Mac OS.h>

#	elif defined(__minix)
#		include <Q/inspection/private/OS/MINIX.h>

#	elif defined(__MORPHOS__)
#		include <Q/inspection/private/OS/MorphOS.h>

/*#	elif defined()
#		include <Q/inspection/private/OS/MPE.h>*/

#	elif defined(__mpexl) || defined(mpeix)
#		include <Q/inspection/private/OS/MPE-iX.h>

/*#	elif defined()
#		include <Q/inspection/private/OS/MPE-XL.h>*/

#	elif defined(__DOS__) || defined(__MSDOS__) || defined(_MSDOS) || defined(MSDOS)
#		include <Q/inspection/private/OS/MS-DOS.h>

/*#	elif defined()
#		include <Q/inspection/private/OS/MVS.h>*/

#	elif defined(__TANDEM)
#		include <Q/inspection/private/OS/NonStop OS.h>

#	elif defined(__nucleus__)
#		include <Q/inspection/private/OS/Nucleus RTOS.h>

#	elif defined(__OS2__) || defined(_OS2) || defined(__TOS_OS2__) || defined(OS2)
#		include <Q/inspection/private/OS/OS-2.h>

#	elif defined(__OS9000) || defined(_OSK)
#		include <Q/inspection/private/OS/OS-9.h>

/*#	elif defined()
#		include <Q/inspection/private/OS/OS-360.h>*/

/*#	elif defined()
#		include <Q/inspection/private/OS/OS-390.h>*/

#	elif defined(__OS400__)
#		include <Q/inspection/private/OS/OS-400.h>

#	elif defined(__palmos__)
#		include <Q/inspection/private/OS/Palm OS.h>

#	elif defined(EPLAN9)
#		include <Q/inspection/private/OS/Plan 9.h>

#	elif defined(__QNX__) || defined(__QNXNTO__)
#		include <Q/inspection/private/OS/QNX.h>

#	elif defined(_SCO_DS) || defined(M_I386) || defined(M_XENIX)
#		include <Q/inspection/private/OS/SCO UNIX System V.h>

#	elif defined(sinux)
#		include <Q/inspection/private/OS/SINIX.h>

#	elif defined(__sun) || defined(sun)
#		include <Q/inspection/private/OS/SunOS.h>

#	elif defined(__SYLLABLE__)
#		include <Q/inspection/private/OS/Syllable.h>

#	elif defined(__SYMBIAN32__)
#		include <Q/inspection/private/OS/Symbian.h>

#	elif defined(__ultrix__) || defined(__ultrix) || defined(ultrix) /* "unix & vax"? */
#		include <Q/inspection/private/OS/ULTRIX.h>

#	elif defined(_UNICOS)
#		include <Q/inspection/private/OS/UNICOS.h>

#	elif defined(__crayx1) || defined(_CRAY)
#		include <Q/inspection/private/OS/UNICOS-mp.h>

#	elif defined(_UNIXWARE7) || defined(sco)
#		include <Q/inspection/private/OS/UnixWare.h>

#	elif defined(UTS)
#		include <Q/inspection/private/OS/UTS.h>

#	elif defined(__VMS) || defined(VMS)
#		include <Q/inspection/private/OS/VMS.h>

#	elif defined(__VOS__)
#		include <Q/inspection/private/OS/VOS.h>

#	elif defined(__VXWORKS__) || defined(__vxworks)
#		include <Q/inspection/private/OS/VxWorks.h>

#	elif defined(_WIN32_WCE)
#		include <Q/inspection/private/OS/Windows CE.h>

/*#	elif defined()
#		include <Q/inspection/private/OS/Xenix.h>*/

#	defined(__MVS__) || defined(__HOS_MVS__) || defined(__TOS_MVS__)
#		include <Q/inspection/private/OS/z-OS.h>

/*#	elif defined()
#		include <Q/inspection/private/OS/z-TPF.h>*/

/*#	elif defined()
#		include <Q/inspection/private/OS/z-VM.h>*/

/*#	elif defined()
#		include <Q/inspection/private/OS/z-VSE.h>*/

#	endif

#endif

#define Q_OS_HAS(feature) defined(Q_OS_HAS_##feature)
#define Q_OS_IS(what)	  defined(Q_OS_IS_##what)

#endif /* __Q_inspection_OS_H__ */
