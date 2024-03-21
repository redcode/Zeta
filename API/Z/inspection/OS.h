/* Zeta API - Z/inspection/OS.h
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_inspection_OS_H
#define Z_inspection_OS_H

#include <Z/keys/OS.h>
#include <Z/macros/token.h>

#ifndef Z_OS
#	include <Z/inspection/compiler.h>

#	ifdef Z_COMPILER_OS
#		define Z_OS Z_COMPILER_OS
#	else
#		include <Z/inspection/OS/detection.h>
#	endif
#endif

#ifndef Z_OS
#	define Z_OS			   Z_OS_UNKNOWN
#	define Z_OS_IS_UNKNOWN		   1
#	define Z_OS_NAME		   "unknown OS"
#elif Z_OS == Z_OS_AEGIS
#	define Z_OS_IS_AEGIS		   1
#	define Z_OS_NAME		   Z_OS_NAME_AEGIS
#elif Z_OS == Z_OS_AIX
#	define Z_OS_IS_AIX		   1
#	define Z_OS_NAME		   Z_OS_NAME_AIX
#elif Z_OS == Z_OS_AMIGA_OS
#	define Z_OS_IS_AMIGA_OS		   1
#	define Z_OS_NAME		   Z_OS_NAME_AMIGA_OS
#elif Z_OS == Z_OS_ANANAS_OS
#	define Z_OS_IS_ANANAS_OS	   1
#	define Z_OS_NAME		   Z_OS_NAME_ANANAS_OS
#elif Z_OS == Z_OS_ANDROID
#	define Z_OS_IS_ANDROID		   1
#	define Z_OS_NAME		   Z_OS_NAME_ANDROID
#elif Z_OS == Z_OS_AROS
#	define Z_OS_IS_AROS		   1
#	define Z_OS_NAME		   Z_OS_NAME_AROS
#elif Z_OS == Z_OS_BE_OS
#	define Z_OS_IS_BE_OS		   1
#	define Z_OS_NAME		   Z_OS_NAME_BE_OS
#elif Z_OS == Z_OS_BITRIG
#	define Z_OS_IS_BITRIG		   1
#	define Z_OS_NAME		   Z_OS_NAME_BITRIG
#elif Z_OS == Z_OS_BSD_386
#	define Z_OS_IS_BSD_386		   1
#	define Z_OS_IS_BSD_I		   1
#	define Z_OS_IS_BSD_OS		   1
#	define Z_OS_NAME		   Z_OS_NAME_BSD_OS
#elif Z_OS == Z_OS_CELL_OS
#	define Z_OS_IS_CELL_OS		   1
#	define Z_OS_NAME		   Z_OS_NAME_CELL_OS
#elif Z_OS == Z_OS_CNK
#	define Z_OS_IS_CNK		   1
#	define Z_OS_NAME		   Z_OS_NAME_CNK
#elif Z_OS == Z_OS_CONVEX_UNIX
#	define Z_OS_IS_CONVEX_UNIX	   1
#	define Z_OS_IS_CONVEX_OS	   1
#	define Z_OS_NAME		   Z_OS_NAME_CONVEX_OS
#elif Z_OS == Z_OS_CYGWIN
#	define Z_OS_IS_CYGWIN		   1
#	define Z_OS_NAME		   Z_OS_NAME_CYGWIN
#elif Z_OS == Z_OS_DC_OSX
#	define Z_OS_IS_DC_OSX		   1
#	define Z_OS_NAME		   Z_OS_NAME_DC_OSX
#elif Z_OS == Z_OS_DG_UX
#	define Z_OS_IS_DG_UX		   1
#	define Z_OS_NAME		   Z_OS_NAME_DG_UX
#elif Z_OS == Z_OS_DOMAIN_OS
#	define Z_OS_IS_DOMAIN_OS	   1
#	define Z_OS_NAME		   Z_OS_NAME_DOMAIN_OS
#elif Z_OS == Z_OS_DRAGONFLY_BSD
#	define Z_OS_IS_DRAGONFLY_BSD	   1
#	define Z_OS_NAME		   Z_OS_NAME_DRAGONFLY_BSD
#elif Z_OS == Z_OS_DYNIX_PTX
#	define Z_OS_IS_DYNIX_PTX	   1
#	define Z_OS_NAME		   Z_OS_NAME_DYNIX_PTX
#elif Z_OS == Z_OS_ECOS
#	define Z_OS_IS_ECOS		   1
#	define Z_OS_NAME		   Z_OS_NAME_ECOS
#elif Z_OS == Z_OS_FREE_BSD
#	define Z_OS_IS_FREE_BSD		   1
#	define Z_OS_NAME		   Z_OS_NAME_FREE_BSD
#elif Z_OS == Z_OS_FUCHSIA
#	define Z_OS_IS_FUCHSIA		   1
#	define Z_OS_NAME		   Z_OS_NAME_FUCHSIA
#elif Z_OS == Z_OS_GNU_HURD
#	define Z_OS_IS_GNU_HURD		   1
#	define Z_OS_NAME		   Z_OS_NAME_GNU_HURD
#elif Z_OS == Z_OS_HAIKU
#	define Z_OS_IS_HAIKU		   1
#	define Z_OS_NAME		   Z_OS_NAME_HAIKU
#elif Z_OS == Z_OS_HI_UX_MPP
#	define Z_OS_IS_HI_UX_MPP	   1
#	define Z_OS_NAME		   Z_OS_NAME_HI_UX_MPP
#elif Z_OS == Z_OS_HP_UX
#	define Z_OS_IS_HP_UX		   1
#	define Z_OS_NAME		   Z_OS_NAME_HP_UX
#elif Z_OS == Z_OS_INTEGRITY
#	define Z_OS_IS_INTEGRITY	   1
#	define Z_OS_NAME		   Z_OS_NAME_INTEGRITY
#elif Z_OS == Z_OS_IPHONE_OS
#	define Z_OS_IS_IPHONE_OS	   1
#	define Z_OS_IS_IOS		   1
#	define Z_OS_NAME		   Z_OS_NAME_IOS
#elif Z_OS == Z_OS_IRIX
#	define Z_OS_IS_IRIX		   1
#	define Z_OS_NAME		   Z_OS_NAME_IRIX
#elif Z_OS == Z_OS_LEMON_OS
#	define Z_OS_IS_LEMON_OS		   1
#	define Z_OS_NAME		   Z_OS_NAME_LEMON_OS
#elif Z_OS == Z_OS_LINUX
#	define Z_OS_IS_LINUX		   1
#	define Z_OS_NAME		   Z_OS_NAME_LINUX
#elif Z_OS == Z_OS_LUNIX
#	define Z_OS_IS_LUNIX		   1
#	define Z_OS_NAME		   Z_OS_NAME_LUNIX
#elif Z_OS == Z_OS_LYNX_OS
#	define Z_OS_IS_LYNX_OS		   1
#	define Z_OS_NAME		   Z_OS_NAME_LYNX_OS
#elif Z_OS == Z_OS_MAC_OS
#	define Z_OS_IS_MAC_OS		   1
#	define Z_OS_NAME		   Z_OS_NAME_MAC_OS
#elif Z_OS == Z_OS_MAC_OS_X
#	define Z_OS_IS_MAC_OS_X		   1
#	define Z_OS_IS_OS_X		   1
#	define Z_OS_IS_MACOS		   1
#	define Z_OS_NAME		   Z_OS_NAME_MACOS
#elif Z_OS == Z_OS_MINIX
#	define Z_OS_IS_MINIX		   1
#	define Z_OS_NAME		   Z_OS_NAME_MINIX
#elif Z_OS == Z_OS_MORPH_OS
#	define Z_OS_IS_MORPH_OS		   1
#	define Z_OS_NAME		   Z_OS_NAME_MORPH_OS
#elif Z_OS == Z_OS_MPE_XL
#	define Z_OS_IS_MPE_XL		   1
#	define Z_OS_NAME		   Z_OS_NAME_MPE_XL
#elif Z_OS == Z_OS_MS_DOS
#	define Z_OS_IS_MS_DOS		   1
#	define Z_OS_NAME		   Z_OS_NAME_MS_DOS
#elif Z_OS == Z_OS_NET_BSD
#	define Z_OS_IS_NET_BSD		   1
#	define Z_OS_NAME		   Z_OS_NAME_NET_BSD
#elif Z_OS == Z_OS_NETWARE
#	define Z_OS_IS_NETWARE		   1
#	define Z_OS_NAME		   Z_OS_NAME_NETWARE
#elif Z_OS == Z_OS_NEXTSTEP
#	define Z_OS_IS_NEXTSTEP		   1
#	define Z_OS_NAME		   Z_OS_NAME_NEXTSTEP
#elif Z_OS == Z_OS_NON_STOP_OS
#	define Z_OS_IS_NON_STOP_OS	   1
#	define Z_OS_NAME		   Z_OS_NAME_NON_STOP_OS
#elif Z_OS == Z_OS_NUCLEUS_RTOS
#	define Z_OS_IS_NUCLEUS_RTOS	   1
#	define Z_OS_NAME		   Z_OS_NAME_NUCLEUS_RTOS
#elif Z_OS == Z_OS_OPEN_BSD
#	define Z_OS_IS_OPEN_BSD		   1
#	define Z_OS_NAME		   Z_OS_NAME_OPEN_BSD
#elif Z_OS == Z_OS_OPEN_VMS
#	define Z_OS_IS_OPEN_VMS		   1
#	define Z_OS_NAME		   Z_OS_NAME_OPEN_VMS
#elif Z_OS == Z_OS_ORBIS_OS
#	define Z_OS_IS_ORBIS_OS		   1
#	define Z_OS_NAME		   Z_OS_NAME_ORBIS_OS
#elif Z_OS == Z_OS_OS_2
#	define Z_OS_IS_OS_2		   1
#	define Z_OS_NAME		   Z_OS_NAME_OS_2
#elif Z_OS == Z_OS_OS_9
#	define Z_OS_IS_OS_9		   1
#	define Z_OS_NAME		   Z_OS_NAME_OS_9
#elif Z_OS == Z_OS_OS_400
#	define Z_OS_IS_OS_400		   1
#	define Z_OS_IS_I5_OS		   1
#	define Z_OS_IS_IBM_I		   1
#	define Z_OS_NAME		   Z_OS_NAME_IBM_I
#elif Z_OS == Z_OS_OSF_1
#	define Z_OS_IS_OSF_1		   1
#	define Z_OS_IS_DIGITAL_UNIX	   1
#	define Z_OS_IS_TRU64_UNIX	   1
#	define Z_OS_NAME		   Z_OS_NAME_TRU64_UNIX
#elif Z_OS == Z_OS_PALM_OS
#	define Z_OS_IS_PALM_OS		   1
#	define Z_OS_NAME		   Z_OS_NAME_PALM_OS
#elif Z_OS == Z_OS_PLAN_9
#	define Z_OS_IS_PLAN_9		   1
#	define Z_OS_NAME		   Z_OS_NAME_PLAN_9
#elif Z_OS == Z_OS_PSP_SYSTEM_SOFTWARE
#	define Z_OS_IS_PSP_SYSTEM_SOFTWARE 1
#	define Z_OS_NAME		   Z_OS_NAME_PSP_SYSTEM_SOFTWARE
#elif Z_OS == Z_OS_QNX
#	define Z_OS_IS_QNX		   1
#	define Z_OS_NAME		   Z_OS_NAME_QNX
#elif Z_OS == Z_OS_RTEMS
#	define Z_OS_IS_RTEMS		   1
#	define Z_OS_NAME		   Z_OS_NAME_RTEMS
#elif Z_OS == Z_OS_SCO_UNIX_SYSTEM_V
#	define Z_OS_IS_SCO_UNIX_SYSTEM_V   1
#	define Z_OS_IS_OPEN_DESKTOP	   1
#	define Z_OS_IS_SCO_UNIX		   1
#	define Z_OS_IS_OPEN_SERVER	   1
#	define Z_OS_NAME		   Z_OS_NAME_OPEN_SERVER
#elif Z_OS == Z_OS_SERENITY_OS
#	define Z_OS_IS_SERENITY_OS	   1
#	define Z_OS_NAME		   Z_OS_NAME_SERENITY_OS
#elif Z_OS == Z_OS_SINIX
#	define Z_OS_IS_SINIX		   1
#	define Z_OS_IS_RELIANT_UNIX	   1
#	define Z_OS_NAME		   Z_OS_NAME_RELIANT_UNIX
#elif Z_OS == Z_OS_SOLARIS
#	define Z_OS_IS_SOLARIS		   1
#	define Z_OS_NAME		   Z_OS_NAME_SOLARIS
#elif Z_OS == Z_OS_SUN_OS
#	define Z_OS_IS_SUN_OS		   1
#	define Z_OS_NAME		   Z_OS_NAME_SUN_OS
#elif Z_OS == Z_OS_SYLLABLE
#	define Z_OS_IS_SYLLABLE		   1
#	define Z_OS_NAME		   Z_OS_NAME_SYLLABLE
#elif Z_OS == Z_OS_SYMBIAN
#	define Z_OS_IS_SYMBIAN		   1
#	define Z_OS_NAME		   Z_OS_NAME_SYMBIAN
#elif Z_OS == Z_OS_TVOS
#	define Z_OS_IS_TVOS		   1
#	define Z_OS_NAME		   Z_OS_NAME_TVOS
#elif Z_OS == Z_OS_ULTRIX
#	define Z_OS_IS_ULTRIX		   1
#	define Z_OS_NAME		   Z_OS_NAME_ULTRIX
#elif Z_OS == Z_OS_UNICOS
#	define Z_OS_IS_UNICOS		   1
#	define Z_OS_NAME		   Z_OS_NAME_UNICOS
#elif Z_OS == Z_OS_UNICOS_MP
#	define Z_OS_IS_UNICOS_MP	   1
#	define Z_OS_NAME		   Z_OS_NAME_UNICOS_MP
#elif Z_OS == Z_OS_UNIXWARE
#	define Z_OS_IS_UNIXWARE		   1
#	define Z_OS_IS_OPEN_UNIX	   1
#	define Z_OS_NAME		   Z_OS_NAME_UNIXWARE
#elif Z_OS == Z_OS_UTS
#	define Z_OS_IS_UTS		   1
#	define Z_OS_NAME		   Z_OS_NAME_UTS
#elif Z_OS == Z_OS_VOS
#	define Z_OS_IS_VOS		   1
#	define Z_OS_NAME		   Z_OS_NAME_VOS
#elif Z_OS == Z_OS_VX_WORKS
#	define Z_OS_IS_VX_WORKS		   1
#	define Z_OS_NAME		   Z_OS_NAME_VX_WORKS
#elif Z_OS == Z_OS_WATCH_OS
#	define Z_OS_IS_WATCH_OS		   1
#	define Z_OS_IS_WATCHOS		   1
#	define Z_OS_NAME		   Z_OS_NAME_WATCHOS
#elif Z_OS == Z_OS_WINDOWS
#	define Z_OS_IS_WINDOWS		   1
#	define Z_OS_NAME		   Z_OS_NAME_WINDOWS
#elif Z_OS == Z_OS_WINDOWS_CE
#	define Z_OS_IS_WINDOWS_CE	   1
#	define Z_OS_NAME		   Z_OS_NAME_WINDOWS_CE
#elif Z_OS == Z_OS_XENIX
#	define Z_OS_IS_XENIX		   1
#	define Z_OS_NAME		   Z_OS_NAME_XENIX
#elif Z_OS == Z_OS_Z_OS
#	define Z_OS_IS_Z_OS		   1
#	define Z_OS_NAME		   Z_OS_NAME_Z_OS
#elif Z_OS == Z_OS_ZETA
#	define Z_OS_IS_ZETA		   1
#	define Z_OS_NAME		   Z_OS_NAME_ZETA
#elif
#	error "Invalid Z_OS key."
#endif

#if	Z_OS == Z_OS_AIX	       || \
	Z_OS == Z_OS_ANANAS_OS	       || \
	Z_OS == Z_OS_ANDROID	       || \
	Z_OS == Z_OS_BE_OS	       || \
	Z_OS == Z_OS_BITRIG	       || \
	Z_OS == Z_OS_BSD_386	       || \
	Z_OS == Z_OS_CONVEX_UNIX       || \
	Z_OS == Z_OS_CYGWIN	       || \
	Z_OS == Z_OS_DC_OSX	       || \
	Z_OS == Z_OS_DG_UX	       || \
	Z_OS == Z_OS_DOMAIN_OS	       || \
	Z_OS == Z_OS_DRAGONFLY_BSD     || \
	Z_OS == Z_OS_DYNIX_PTX	       || \
	Z_OS == Z_OS_ECOS	       || \
	Z_OS == Z_OS_FREE_BSD	       || \
	Z_OS == Z_OS_GNU_HURD	       || \
	Z_OS == Z_OS_HAIKU	       || \
	Z_OS == Z_OS_HI_UX_MPP	       || \
	Z_OS == Z_OS_HP_UX	       || \
	Z_OS == Z_OS_INTEGRITY	       || \
	Z_OS == Z_OS_IPHONE_OS	       || \
	Z_OS == Z_OS_IRIX	       || \
	Z_OS == Z_OS_LEMON_OS	       || \
	Z_OS == Z_OS_LINUX	       || \
	Z_OS == Z_OS_LYNX_OS	       || \
	Z_OS == Z_OS_MAC_OS_X	       || \
	Z_OS == Z_OS_MINIX	       || \
	Z_OS == Z_OS_MPE_XL	       || \
	Z_OS == Z_OS_NET_BSD	       || \
	Z_OS == Z_OS_NEXTSTEP	       || \
	Z_OS == Z_OS_NON_STOP_OS       || \
	Z_OS == Z_OS_NUCLEUS_RTOS      || \
	Z_OS == Z_OS_OPEN_BSD	       || \
	Z_OS == Z_OS_ORBIS_OS	       || \
	Z_OS == Z_OS_OSF_1	       || \
	Z_OS == Z_OS_QNX	       || \
	Z_OS == Z_OS_RTEMS	       || \
	Z_OS == Z_OS_SCO_UNIX_SYSTEM_V || \
	Z_OS == Z_OS_SERENITY_OS       || \
	Z_OS == Z_OS_SINIX	       || \
	Z_OS == Z_OS_SOLARIS	       || \
	Z_OS == Z_OS_SUN_OS	       || \
	Z_OS == Z_OS_SYLLABLE	       || \
	Z_OS == Z_OS_TVOS	       || \
	Z_OS == Z_OS_ULTRIX	       || \
	Z_OS == Z_OS_UNICOS	       || \
	Z_OS == Z_OS_UNICOS_MP	       || \
	Z_OS == Z_OS_UNIXWARE	       || \
	Z_OS == Z_OS_UTS	       || \
	Z_OS == Z_OS_VX_WORKS	       || \
	Z_OS == Z_OS_WATCH_OS	       || \
	Z_OS == Z_OS_XENIX	       || \
	Z_OS == Z_OS_Z_OS	       || \
	Z_OS == Z_OS_ZETA

#	define Z_OS_HAS_POSIX 1
#endif

/* MARK: - Getters */

#define Z_OS_IS( OS  ) Z_IS_TRUE(Z_OS_IS_##OS   )
#define Z_OS_HAS(WHAT) Z_IS_TRUE(Z_OS_HAS_##WHAT)

#endif /* Z_inspection_OS_H */
