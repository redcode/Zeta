/* Z Kit C API - inspection/OS.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_inspection_OS_H__
#define __Z_inspection_OS_H__

#if defined(Z_USE_OS_VENUS)
#	include <Z/inspection/private/OS/Venus.h>

#elif defined(Z_USE_OS_LINUX)
#	include <Z/inspection/private/OS/Linux.h>

#elif defined(Z_USE_OS_ANDROID)
#	include <Z/inspection/private/OS/Android.h>

#elif defined(Z_USE_OS_FREE_BSD)
#	include <Z/inspection/private/OS/FreeBSD.h>

#elif defined(Z_USE_OS_NET_BSD)
#	include <Z/inspection/private/OS/NetBSD.h>

#elif defined(Z_USE_OS_OPEN_BSD)
#	include <Z/inspection/private/OS/OpenBSD.h>

#elif defined(Z_USE_OS_MAC_OS_X) || defined(Z_USE_OS_OS_X)
#	include <Z/inspection/private/OS/Mac OS X.h>

#elif defined(Z_USE_OS_IPHONE_OS) || defined(Z_USE_OS_IOS)
#	include <Z/inspection/private/OS/iPhone OS.h>

#elif defined(Z_USE_OS_WINDOWS)
#	include <Z/inspection/private/OS/Windows.h>

#elif defined(Z_USE_OS_AIX)
#	include <Z/inspection/private/OS/AIX.h>

#elif defined(Z_USE_OS_AMIGA_OS)
#	include <Z/inspection/private/OS/AmigaOS.h>

#elif defined(Z_USE_OS_AEGIS)
#	include <Z/inspection/private/OS/AEGIS.h>

#elif defined(Z_USE_OS_DOMAIN_OS)
#	include <Z/inspection/private/OS/Domain-OS.h>

#elif defined(Z_USE_OS_BADA)
#	include <Z/inspection/private/OS/Bada.h>

#elif defined(Z_USE_OS_BE_OS)
#	include <Z/inspection/private/OS/BeOS.h>

#elif defined(Z_USE_OS_BLUE_GENE)
#	include <Z/inspection/private/OS/Blue Gene.h>

#elif defined(Z_USE_OS_BSD_386) || defined(Z_USE_OS_BSD_I) || defined(Z_USE_OS_BSD_OS)
#	include <Z/inspection/private/OS/BSD-386.h>

#elif defined(Z_USE_OS_CONVEX_OS)
#	include <Z/inspection/private/OS/ConvexOS.h>

#elif defined(Z_USE_OS_DC_OSX)
#	include <Z/inspection/private/OS/DC-OSx.h>

#elif defined(Z_USE_OS_DEC_OSF_1) || defined(Z_USE_OS_DIGITAL_UNIX) || defined(Z_USE_OS_TRU64_UNIX)
#	include <Z/inspection/private/OS/DEC OSF-1.h>

#elif defined(Z_USE_OS_DG_UX)
#	include <Z/inspection/private/OS/DG-UX.h>

#elif defined(Z_USE_OS_DRAGONFLY_BSD)
#	include <Z/inspection/private/OS/DragonFly BSD.h>

#elif defined(Z_USE_OS_DYNIX)
#	include <Z/inspection/private/OS/DYNIX.h>

#elif defined(Z_USE_OS_DYNIX_PTX)
#	include <Z/inspection/private/OS/DYNIX-ptx.h>

#elif defined(Z_USE_OS_ECOS)
#	include <Z/inspection/private/OS/eCos.h>

#elif defined(Z_USE_OS_GNU_HURD)
#	include <Z/inspection/private/OS/GNU Hurd.h>

#elif defined(Z_USE_OS_HI_UX_MPP)
#	include <Z/inspection/private/OS/HI-UX MPP.h>

#elif defined(Z_USE_OS_HP_UX)
#	include <Z/inspection/private/OS/HP-UX.h>

#elif defined(Z_USE_OS_INTEGRITY)
#	include <Z/inspection/private/OS/INTEGRITY.h>

#elif defined(Z_USE_OS_IRIX)
#	include <Z/inspection/private/OS/IRIX.h>

#elif defined(Z_USE_OS_LYNX_OS)
#	include <Z/inspection/private/OS/LynxOS.h>

#elif defined(Z_USE_OS_MAC_OS)
#	include <Z/inspection/private/OS/Mac OS.h>

#elif defined(Z_USE_OS_MINIX)
#	include <Z/inspection/private/OS/MINIX.h>

#elif defined(Z_USE_OS_MORPH_OS)
#	include <Z/inspection/private/OS/MorphOS.h>

#elif defined(Z_USE_OS_MPE)
#	include <Z/inspection/private/OS/MPE.h>

#elif defined(Z_USE_OS_MPE_IX)
#	include <Z/inspection/private/OS/MPE-iX.h>

#elif defined(Z_USE_OS_MPE_XL)
#	include <Z/inspection/private/OS/MPE-XL.h>

#elif defined(Z_USE_OS_MS_DOS)
#	include <Z/inspection/private/OS/MS-DOS.h>

#elif defined(Z_USE_OS_MVS)
#	include <Z/inspection/private/OS/MVS.h>

#elif defined(Z_USE_OS_NON_STOP_OS)
#	include <Z/inspection/private/OS/NonStop OS.h>

#elif defined(Z_USE_OS_NUCLEUS_RTOS)
#	include <Z/inspection/private/OS/Nucleus RTOS.h>

#elif defined(Z_USE_OS_OS_2)
#	include <Z/inspection/private/OS/OS-2.h>

#elif defined(Z_USE_OS_OS_9)
#	include <Z/inspection/private/OS/OS-9.h>

#elif defined(Z_USE_OS_OS_360)
#	include <Z/inspection/private/OS/OS-360.h>

#elif defined(Z_USE_OS_OS_390)
#	include <Z/inspection/private/OS/OS-390.h>

#elif defined(Z_USE_OS_OS_400) || defined(Z_USE_OS_I5_OS) || defined(Z_USE_OS_IBM_I)
#	include <Z/inspection/private/OS/OS-400.h>

#elif defined(Z_USE_OS_PALM_OS)
#	include <Z/inspection/private/OS/Palm OS.h>

#elif defined(Z_USE_OS_PLAN_9)
#	include <Z/inspection/private/OS/Plan 9.h>

#elif defined(Z_USE_OS_QNX)
#	include <Z/inspection/private/OS/QNX.h>

#elif defined(Z_USE_OS_SCO_UNIX_SYSTEM_V) || defined(Z_USE_OS_OPEN_DESKTOP) || \
      defined(Z_USE_OS_SCO_UNIX)	  || defined(Z_USE_OS_SCO_OPEN_SERVER)
#	include <Z/inspection/private/OS/SCO UNIX System V.h>

#elif defined(Z_USE_OS_SINIX) || defined(Z_USE_OS_RELIANT_UNIX)
#	include <Z/inspection/private/OS/SINIX.h>

#elif defined(Z_USE_OS_SUN_OS) || defined(Z_USE_OS_SOLARIS)
#	include <Z/inspection/private/OS/SunOS.h>

#elif defined(Z_USE_OS_SYLLABLE)
#	include <Z/inspection/private/OS/Syllable.h>

#elif defined(Z_USE_OS_SYMBIAN)
#	include <Z/inspection/private/OS/Symbian.h>

#elif defined(Z_USE_OS_ULTRIX)
#	include <Z/inspection/private/OS/ULTRIX.h>

#elif defined(Z_USE_OS_UNICOS)
#	include <Z/inspection/private/OS/UNICOS.h>

#elif defined(Z_USE_OS_UNICOS_MP)
#	include <Z/inspection/private/OS/UNICOS-mp.h>

#elif defined(Z_USE_OS_UNIX_WARE) || defined(Z_USE_OS_OPEN_UNIX)
#	include <Z/inspection/private/OS/UnixWare.h>

#elif defined(Z_USE_OS_UTS)
#	include <Z/inspection/private/OS/UTS.h>

#elif defined(Z_USE_OS_VMS)
#	include <Z/inspection/private/OS/VMS.h>

#elif defined(Z_USE_OS_VOS)
#	include <Z/inspection/private/OS/VOS.h>

#elif defined(Z_OS_VX_WORKS)
#	include <Z/inspection/private/OS/VxWorks.h>

#elif defined(Z_USE_OS_WINDOWS_CE)
#	include <Z/inspection/private/OS/Windows CE.h>

#elif defined(Z_USE_OS_XENIX)
#	include <Z/inspection/private/OS/Xenix.h>

#elif defined(Z_USE_OS_Z_OS)
#	include <Z/inspection/private/OS/z-OS.h>

#elif defined(Z_USE_OS_Z_TPF)
#	include <Z/inspection/private/OS/z-TPF.h>

#elif defined(Z_USE_OS_Z_VM)
#	include <Z/inspection/private/OS/z-VM.h>

#elif defined(Z_USE_OS_Z_VSE)
#	include <Z/inspection/private/OS/z-VSE.h>

#else

#	if defined(__Venus__)
#		include <Z/inspection/private/OS/Venus.h>

#	elif defined(__linux__) || defined(__linux) || defined(linux)
#		include <Z/inspection/private/OS/Linux.h>

#	elif defined(__ANDROID__)
#		include <Z/inspection/private/OS/Android.h>

#	elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
#		include <Z/inspection/private/OS/FreeBSD.h>

#	elif defined(__NetBSD__)
#		include <Z/inspection/private/OS/NetBSD.h>

#	elif defined(__OpenBSD__)
#		include <Z/inspection/private/OS/OpenBSD.h>

#	elif defined(__APPLE__)	&& defined(__MACH__)
#		include <TargetConditionals.h>

#		if TARGET_OS_IPHONE
#			include <Z/inspection/private/OS/iPhone OS.h>
#		else
#			include <Z/inspection/private/OS/Mac OS X.h>
#		endif

#	elif defined(_WIN16)	|| defined(_WIN32)	|| defined(_WIN64) || \
	     defined(__WIN32__)	|| defined(__TOS_WIN__)	|| defined(__WINDOWS__)
#		include <Z/inspection/private/OS/Windows.h>

#	elif defined(_AIX) || defined(__TOS_AIX__)
#		include <Z/inspection/private/OS/AIX.h>

#	elif defined(__amigaos__) || defined(AMIGA)
#		include <Z/inspection/private/OS/AmigaOS.h>

#	elif defined(aegis)
#		include <Z/inspection/private/OS/AEGIS.h>

#	elif defined(apollo)
#		include <Z/inspection/private/OS/Domain-OS.h>

/*#	elif defined()
#		include <Z/inspection/private/OS/Bada.h>*/

#	elif defined(__BEOS__)
#		include <Z/inspection/private/OS/BeOS.h>

#	elif defined(__bg__) || defined(__THW_BLUEGENE__)
#		include <Z/inspection/private/OS/Blue Gene.h>

#	elif defined(__bsdi__)
#		include <Z/inspection/private/OS/BSD-386.h>

#	elif defined(__convex__)
#		include <Z/inspection/private/OS/ConvexOS.h>

#	elif defined(pyr)
#		include <Z/inspection/private/OS/DC-OSx.h>

#	elif defined(__osf__) || defined(__osf)
#		include <Z/inspection/private/OS/DEC OSF-1.h>

#	elif defined(__DGUX__) || defined(__dgux__) || defined(DGUX)
#		include <Z/inspection/private/OS/DG-UX.h>

#	elif defined(__DragonFly__)
#		include <Z/inspection/private/OS/DragonFly BSD.h>

/*#	elif defined()
#		include <Z/inspection/private/OS/DYNIX.h>*/

#	elif defined(_SEQUENT_)	|| defined(sequent)
#		include <Z/inspection/private/OS/DYNIX-ptx.h>

#	elif defined(__ECOS)
#		include <Z/inspection/private/OS/eCos.h>

#	elif defined(__gnu_hurd__) /*|| defined(__GNU__)*/
#		include <Z/inspection/private/OS/GNU Hurd.h>

#	elif defined(__hiuxmpp)
#		include <Z/inspection/private/OS/HI-UX MPP.h>

#	elif defined(__hpux) || defined(_hpux) || defined(hpux)
#		include <Z/inspection/private/OS/HP-UX.h>

#	elif defined(__INTEGRITY)
#		include <Z/inspection/private/OS/INTEGRITY.h>

#	elif defined(__sgi) || defined(sgi)
#		include <Z/inspection/private/OS/IRIX.h>

#	elif defined(__Lynx__)
#		include <Z/inspection/private/OS/LynxOS.h>

#	elif defined(Macintosh) || defined(macintosh)
#		include <Z/inspection/private/OS/Mac OS.h>

#	elif defined(__minix)
#		include <Z/inspection/private/OS/MINIX.h>

#	elif defined(__MORPHOS__)
#		include <Z/inspection/private/OS/MorphOS.h>

/*#	elif defined()
#		include <Z/inspection/private/OS/MPE.h>*/

#	elif defined(__mpexl) || defined(mpeix)
#		include <Z/inspection/private/OS/MPE-iX.h>

/*#	elif defined()
#		include <Z/inspection/private/OS/MPE-XL.h>*/

#	elif defined(__DOS__) || defined(__MSDOS__) || defined(_MSDOS) || defined(MSDOS)
#		include <Z/inspection/private/OS/MS-DOS.h>

/*#	elif defined()
#		include <Z/inspection/private/OS/MVS.h>*/

#	elif defined(__TANDEM)
#		include <Z/inspection/private/OS/NonStop OS.h>

#	elif defined(__nucleus__)
#		include <Z/inspection/private/OS/Nucleus RTOS.h>

#	elif defined(__OS2__) || defined(_OS2) || defined(__TOS_OS2__) || defined(OS2)
#		include <Z/inspection/private/OS/OS-2.h>

#	elif defined(__OS9000) || defined(_OSK)
#		include <Z/inspection/private/OS/OS-9.h>

/*#	elif defined()
#		include <Z/inspection/private/OS/OS-360.h>*/

/*#	elif defined()
#		include <Z/inspection/private/OS/OS-390.h>*/

#	elif defined(__OS400__)
#		include <Z/inspection/private/OS/OS-400.h>

#	elif defined(__palmos__)
#		include <Z/inspection/private/OS/Palm OS.h>

#	elif defined(EPLAN9)
#		include <Z/inspection/private/OS/Plan 9.h>

#	elif defined(__QNX__) || defined(__QNXNTO__)
#		include <Z/inspection/private/OS/QNX.h>

#	elif defined(_SCO_DS) || defined(M_I386) || defined(M_XENIX)
#		include <Z/inspection/private/OS/SCO UNIX System V.h>

#	elif defined(sinux)
#		include <Z/inspection/private/OS/SINIX.h>

#	elif defined(__sun) || defined(sun)
#		include <Z/inspection/private/OS/SunOS.h>

#	elif defined(__SYLLABLE__)
#		include <Z/inspection/private/OS/Syllable.h>

#	elif defined(__SYMBIAN32__)
#		include <Z/inspection/private/OS/Symbian.h>

#	elif defined(__ultrix__) || defined(__ultrix) || defined(ultrix) /* "unix & vax"? */
#		include <Z/inspection/private/OS/ULTRIX.h>

#	elif defined(_UNICOS)
#		include <Z/inspection/private/OS/UNICOS.h>

#	elif defined(__crayx1) || defined(_CRAY)
#		include <Z/inspection/private/OS/UNICOS-mp.h>

#	elif defined(_UNIXWARE7) || defined(sco)
#		include <Z/inspection/private/OS/UnixWare.h>

#	elif defined(UTS)
#		include <Z/inspection/private/OS/UTS.h>

#	elif defined(__VMS) || defined(VMS)
#		include <Z/inspection/private/OS/VMS.h>

#	elif defined(__VOS__)
#		include <Z/inspection/private/OS/VOS.h>

#	elif defined(__VXWORKS__) || defined(__vxworks)
#		include <Z/inspection/private/OS/VxWorks.h>

#	elif defined(_WIN32_WCE)
#		include <Z/inspection/private/OS/Windows CE.h>

/*#	elif defined()
#		include <Z/inspection/private/OS/Xenix.h>*/

#	defined(__MVS__) || defined(__HOS_MVS__) || defined(__TOS_MVS__)
#		include <Z/inspection/private/OS/z-OS.h>

/*#	elif defined()
#		include <Z/inspection/private/OS/z-TPF.h>*/

/*#	elif defined()
#		include <Z/inspection/private/OS/z-VM.h>*/

/*#	elif defined()
#		include <Z/inspection/private/OS/z-VSE.h>*/

#	endif

#endif

#define Z_OS_HAS(feature) defined(Z_OS_HAS_##feature)
#define Z_OS_IS(what)	  defined(Z_OS_IS_##what)

#endif /* __Z_inspection_OS_H__ */
