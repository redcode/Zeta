/* Zeta API - Z/inspection/OS/detection.h
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_inspection_OS_detection_H
#define Z_inspection_OS_detection_H

#if	defined(__ANDROID__)

#	define Z_OS Z_OS_ANDROID

#elif	defined(__TOS_LINUX__) || \
	defined(__gnu_linux__) || \
	defined(__linux	     ) || \
	defined(__linux__    ) || \
	defined(linux)

#	define Z_OS Z_OS_LINUX

#elif defined(__ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__)
#	define Z_OS Z_OS_MAC_OS_X

#elif defined(__ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__)
#	define Z_OS Z_OS_IPHONE_OS

#elif defined(__ENVIRONMENT_TV_OS_VERSION_MIN_REQUIRED__)
#	define Z_OS Z_OS_TVOS

#elif defined(__ENVIRONMENT_WATCH_OS_VERSION_MIN_REQUIRED__)
#	define Z_OS Z_OS_WATCH_OS

#elif	defined(__APPLE_CC__ ) || \
	defined(__APPLE_CPP__) || \
	(defined(__APPLE__) && defined(__MACH__))

#	include <TargetConditionals.h>

	/* Review this */
#	if defined(TARGET_OS_IPHONE) && TARGET_OS_IPHONE

#		if defined(TARGET_OS_TV) && TARGET_OS_TV
#			define Z_OS Z_OS_TVOS

#		elif defined(TARGET_OS_WATCH) && TARGET_OS_WATCH
#			define Z_OS Z_OS_WATCH_OS

#		else
#			define Z_OS Z_OS_IPHONE_OS
#		endif

#	else
#		define Z_OS Z_OS_MAC_OS_X
#	endif

#elif	defined(__DOS__	 ) || \
	defined(__MSDOS__) || \
	defined(_MSDOS	 ) || \
	defined(MSDOS	 )

#	define Z_OS Z_OS_MS_DOS

#elif	defined(__NT__	       ) || \
	defined(__TOS_WIN__    ) || \
	defined(__WIN32	       ) || \
	defined(__WIN32__      ) || \
	defined(__WIN64	       ) || \
	defined(__WIN64__      ) || \
	defined(__WINDOWS__    ) || \
	defined(__WINDOWS_386__) || \
	defined(__WINNT	       ) || \
	defined(__WINNT__      ) || \
	defined(_WIN16	       ) || \
	defined(_WIN32	       ) || \
	defined(_WIN64	       ) || \
	defined(WIN32	       ) || \
	defined(WIN64	       ) || \
	defined(WINNT	       )

#	define Z_OS Z_OS_WINDOWS

#elif	defined(_WIN32_WCE	      ) || \
	defined(WIN32_PLATFORM_HPC2000) || \
	defined(WIN32_PLATFORM_HPCPRO ) || \
	defined(WIN32_PLATFORM_PSPC   ) || \
	defined(WIN32_PLATFORM_WFSP   )

#	define Z_OS Z_OS_WINDOWS_CE

#elif defined(aegis)
#	define Z_OS Z_OS_AEGIS

#elif	defined(_AIX	   ) || \
	defined(__TOS_AIX__)

#	define Z_OS Z_OS_AIX

#elif	defined(__amigaos__) || \
	defined(AMIGA	   )

#	define Z_OS Z_OS_AMIGA_OS

#elif defined(__Ananas__)
#	define Z_OS Z_OS_ANANAS_OS

#elif defined(__AROS__)
#	define Z_OS Z_OS_AROS

#elif defined(__BEOS__)
#	ifdef __ZETA__
#		define Z_OS Z_OS_ZETA
#	else
#		define Z_OS Z_OS_BE_OS
#	endif

#elif defined(__Bitrig__)
#	define Z_OS Z_OS_BITRIG

#elif defined(__bsdi__)
#	define Z_OS Z_OS_BSD_386

#elif defined(__CELLOS_LV2__)
#	define Z_OS Z_OS_CELL_OS

#elif	defined(__bg__		) || \
	defined(__bgp__		) || \
	defined(__bgq__		) || \
	defined(__blrts		) || \
	defined(__blrts__	) || \
	defined(__THW_BLUEGENE__) || \
	defined(__TOS_BGQ__	) || \
	defined(__TOS_BGP__	) || \
	defined(__TOS_BLRTS__	)

#	define Z_OS Z_OS_CNK

#elif defined(__convex__)
#	define Z_OS Z_OS_CONVEX_UNIX

#elif	defined(__CYGWIN__  ) || \
	defined(__CYGWIN32__) || \
	defined(__CYGWIN64__)

#	define Z_OS Z_OS_CYGWIN

#elif defined(pyr)
#	define Z_OS Z_OS_DC_OSX

#elif	defined(__dgux__) || \
	defined(__DGUX__) || \
	defined(DGUX	)

#	define Z_OS Z_OS_DG_UX

#elif defined(apollo)
#	define Z_OS Z_OS_DOMAIN_OS

#elif defined(__DragonFly__)
#	define Z_OS Z_OS_DRAGONFLY_BSD

#elif	defined(_SEQUENT_) || \
	defined(sequent	 )

#	define Z_OS Z_OS_DYNIX_PTX

#elif defined(__ECOS)
#	define Z_OS Z_OS_ECOS

#elif	!defined(__ORBIS__) &&		\
	(defined(__FreeBSD__	   ) || \
	 defined(__FreeBSD_kernel__))

#	define Z_OS Z_OS_FREE_BSD

#elif defined(__Fuchsia__)
#	define Z_OS Z_OS_FUCHSIA

#elif defined(__gnu_hurd__) /*|| defined(__GNU__)*/
#	define Z_OS Z_OS_GNU_HURD

#elif defined(__HAIKU__)
#	define Z_OS Z_OS_HAIKU

#elif defined(__hiuxmpp)
#	define Z_OS Z_OS_HI_UX_MPP

#elif	defined(__hpux) || \
	defined(_hpux ) || \
	defined(hpux  )

#	define Z_OS Z_OS_HP_UX

#elif defined(__INTEGRITY)
#	define Z_OS Z_OS_INTEGRITY

#elif	defined(__sgi) || \
	defined(sgi  )

#	define Z_OS Z_OS_IRIX

#elif defined(__lemon__)
#	define Z_OS Z_OS_LEMON_OS

#elif defined(__LUNIX__)
#	define Z_OS Z_OS_LUNIX

#elif defined(__Lynx__)
#	define Z_OS Z_OS_LYNX_OS

#elif	defined(Macintosh) || \
	defined(macintosh)

#	define Z_OS Z_OS_MAC_OS

#elif defined(__minix)
#	define Z_OS Z_OS_MINIX

#elif defined(__MORPHOS__)
#	define Z_OS Z_OS_MORPH_OS

#elif	defined(__mpexl) || \
	defined(mpeix  )

#	define Z_OS Z_OS_MPE_XL

#elif defined(__NetBSD__)
#	define Z_OS Z_OS_NET_BSD

#elif	defined(__netware__    ) || \
	defined(__NETWARE_386__)

#	define Z_OS Z_OS_NETWARE

#elif defined(__TANDEM)
#	define Z_OS Z_OS_NON_STOP_OS

#elif defined(__nucleus__)
#	define Z_OS Z_OS_NUCLEUS_RTOS

#elif defined(__OpenBSD__)
#	define Z_OS Z_OS_OPEN_BSD

#elif	defined(__VMS) || \
	defined(VMS  )

#	define Z_OS Z_OS_OPEN_VMS

#elif defined(__ORBIS__)
#	define Z_OS Z_OS_ORBIS_OS

#elif	defined(__OS2__	   ) || \
	defined(__TOS_OS2__) || \
	defined(_OS2	   ) || \
	defined(OS2	   )

#	define Z_OS Z_OS_OS_2

#elif	defined(__OS9000) || \
	defined(_OSK	)

#	define Z_OS Z_OS_OS_9

#elif	defined(__OS400__    ) || \
	defined(__TOS_OS400__)

#	define Z_OS Z_OS_OS_400

#elif	defined(__osf__) || \
	defined(__osf  )

#	define Z_OS Z_OS_OSF_1

#elif defined(__palmos__)
#	define Z_OS Z_OS_PALM_OS

#elif defined(EPLAN9)
#	define Z_OS Z_OS_PLAN_9

#elif	defined(__psp__) || \
	defined(_PSP   ) || \
	defined(PSP    )

#	define Z_OS Z_OS_PSP_SYSTEM_SOFTWARE

#elif	defined(__QNX__	  ) || \
	defined(__QNXNTO__)

#	define Z_OS Z_OS_QNX

#elif defined(__rtems__)
#	define Z_OS Z_OS_RTEMS

#elif	defined(_SCO_DS) ||			    \
	defined(M_I386 ) || /* TODO: Investigate */ \
	defined(M_XENIX)    /* TODO: Investigate */

#	define Z_OS Z_OS_SCO_UNIX_SYSTEM_V

#elif defined(__serenity__)
#	define Z_OS Z_OS_SERENITY_OS

#elif defined(sinux)
#	define Z_OS Z_OS_SINIX

#elif	defined(__sun  ) || \
	defined(__sun__) || \
	defined(__SunOS) || \
	defined(sun    )

#	if	defined(__svr4__) || \
		defined(__SVR4	)

#		define Z_OS Z_OS_SOLARIS
#	else
#		define Z_OS Z_OS_SUN_OS
#	endif

#elif defined(__SYLLABLE__)
#	define Z_OS Z_OS_SYLLABLE

#elif defined(__SYMBIAN32__)
#	define Z_OS Z_OS_SYMBIAN

#elif	defined(__ultrix__) || \
	defined(__ultrix  ) || \
	defined(ultrix	  ) /* "unix & vax"? */

#	define Z_OS Z_OS_ULTRIX

#elif defined(_UNICOS)
#	define Z_OS Z_OS_UNICOS

#elif	defined(__crayx1) || \
	defined(_CRAY	)

#	define Z_OS Z_OS_UNICOS_MP

#elif	defined(_UNIXWARE7) || \
	defined(sco	  )

#	define Z_OS Z_OS_UNIXWARE

#elif defined(UTS)
#	define Z_OS Z_OS_UTS

#elif defined(__VOS__)
#	define Z_OS Z_OS_VOS

#elif	defined(__vxworks  ) || \
	defined(__VXWORKS__)

#	define Z_OS Z_OS_VX_WORKS

#elif	defined(__MVS__	   ) || \
	defined(__HOS_MVS__) || \
	defined(__TOS_MVS__)

#	define Z_OS Z_OS_Z_OS
#endif

#endif /* Z_inspection_OS_detection_H */
