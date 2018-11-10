/* Z Kit - keys/OS.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_keys_OS_H_
#define _Z_keys_OS_H_

#define Z_OS_UNKNOWN			 0
#define Z_OS_AEGIS			 1 /* Apollo Computer		  */
#define Z_OS_AIX			 2 /* IBM			  */
#define Z_OS_AMIGA_OS			 3 /* Commodore			  */
#define Z_OS_ANDROID			 4 /* Google			  */
#define Z_OS_BE_OS			 5 /* Be			  */
#define Z_OS_BITRIG			 6
#define Z_OS_BSD_386			 7
#define Z_OS_CELL_OS			 8 /* Sony (PlayStation 3)	  */
#define Z_OS_CNK			 9 /* IBM			  */
#define Z_OS_CONVEX_UNIX		10 /* Convex Computer		  */
#define Z_OS_CYGWIN			11 /* Cygnus Solutions		  */
#define Z_OS_DC_OSX			12 /* Pyramid Technology	  */
#define Z_OS_DG_UX			13 /* Data General		  */
#define Z_OS_DOMAIN_OS			14 /* Apollo Computer		  */
#define Z_OS_DRAGONFLY_BSD		15
#define Z_OS_DYNIX_PTX			16 /* Sequent Computer Systems	  */
#define Z_OS_ECOS			17 /* Cygnus Solutions		  */
#define Z_OS_FREE_BSD			18
#define Z_OS_GNU_HURD			19
#define Z_OS_HAIKU			20
#define Z_OS_HI_UX_MPP			21 /* Hitachi			  */
#define Z_OS_HP_UX			22 /* Hewlett-Packard		  */
#define Z_OS_INTEGRITY			23 /* Green Hills Software	  */
#define Z_OS_IPHONE_OS			24 /* Apple			  */
#define Z_OS_IRIX			25 /* SGI			  */
#define Z_OS_LINUX			26 /* Torvalds, Linus		  */
#define Z_OS_LYNX_OS			27 /* Lynx Software Technologies */
#define Z_OS_MAC_OS			28 /* Apple Computer		  */
#define Z_OS_MAC_OS_X			29 /* Apple Computer		  */
#define Z_OS_MINIX			30 /* Tanenbaum, Andrew Stuart	  */
#define Z_OS_MORPH_OS			31
#define Z_OS_MPE_XL			32 /* Hewlett-Packard		  */
#define Z_OS_MS_DOS			33 /* Microsoft		  */
#define Z_OS_NET_BSD			34
#define Z_OS_NET_WARE			35 /* Novell			  */
#define Z_OS_NON_STOP_OS		36 /* Hewlett-Packard		  */
#define Z_OS_NUCLEUS_RTOS		37 /* Mentor Graphics		  */
#define Z_OS_OPEN_BSD			38
#define Z_OS_ORBIS_OS			39 /* Sony (PlayStation 4)	  */
#define Z_OS_OS_2			40 /* IBM / Microsoft		  */
#define Z_OS_OS_9			41 /* Microware Systems	  */
#define Z_OS_OS_400			42 /* IBM			  */
#define Z_OS_OSF_1			43 /* OSF			  */
#define Z_OS_PALM_OS			44 /* Palm			  */
#define Z_OS_PLAN_9			45 /* Bell Labs		  */
#define Z_OS_PSP_SYSTEM_SOFTWARE	46 /* Sony			  */
#define Z_OS_QNX			47 /* Quantum Software Systems	  */
#define Z_OS_RTEMS			48 /* OAR Corporation (?)	  */
#define Z_OS_SCO_UNIX_SYSTEM_V		49 /* SCO			  */
#define Z_OS_SINIX			50 /* Siemens Nixdorf		  */
#define Z_OS_SOLARIS			51 /* Sun Microsystems		  */
#define Z_OS_SUN_OS			52 /* Sun Microsystems		  */
#define Z_OS_SYLLABLE			53
#define Z_OS_SYMBIAN			54 /* Symbian			  */
#define Z_OS_TVOS			55 /* Apple			  */
#define Z_OS_ULTRIX			56 /* DEC			  */
#define Z_OS_UNICOS			57 /* Cray			  */
#define Z_OS_UNICOS_MP			58 /* SGI (?)			  */
#define Z_OS_UNIX_WARE			59 /* Univel			  */
#define Z_OS_UTS			60 /* Amdahl			  */
#define Z_OS_VMS			61 /* DEC			  */
#define Z_OS_VOS			62 /* Stratus Technologies	  */
#define Z_OS_VX_WORKS			63 /* Wind River Systems	  */
#define Z_OS_WATCH_OS			64 /* Apple			  */
#define Z_OS_WINDOWS			65 /* Microsoft		  */
#define Z_OS_WINDOWS_CE			66 /* Microsoft		  */
#define Z_OS_Z_OS			67 /* IBM			  */

#define Z_OS_STRING_AEGIS		"AEGIS"
#define Z_OS_STRING_AIX			"AIX"
#define Z_OS_STRING_AMIGA_OS		"AmigaOS"
#define Z_OS_STRING_ANDROID		"Android"
#define Z_OS_STRING_BE_OS		"BeOS"
#define Z_OS_STRING_BITRIG		"Bitrig"
#define Z_OS_STRING_BSD_386		"BSD/386"
#define Z_OS_STRING_CELL_OS		"CellOS"
#define Z_OS_STRING_CNK			"CNK"
#define Z_OS_STRING_CONVEX_UNIX		"Convex UNIX"
#define Z_OS_STRING_CYGWIN		"Cygwin"
#define Z_OS_STRING_DC_OSX		"DC/OSx"
#define Z_OS_STRING_DG_UX		"DG/UX"
#define Z_OS_STRING_DOMAIN_OS		"Domain/OS"
#define Z_OS_STRING_DRAGONFLY_BSD	"DragonFly BSD"
#define Z_OS_STRING_DYNIX_PTX		"DYNIX/ptx"
#define Z_OS_STRING_ECOS		"eCos"
#define Z_OS_STRING_FREE_BSD		"FreeBSD"
#define Z_OS_STRING_GNU_HURD		"GNU Hurd"
#define Z_OS_STRING_HAIKU		"Haiku"
#define Z_OS_STRING_HI_UX_MPP		"HI-UX/MPP"
#define Z_OS_STRING_HP_UX		"HP-UX"
#define Z_OS_STRING_INTEGRITY		"INTEGRITY"
#define Z_OS_STRING_IPHONE_OS		"iPhone OS"
#define Z_OS_STRING_IRIX		"IRIX"
#define Z_OS_STRING_LINUX		"Linux"
#define Z_OS_STRING_LYNX_OS		"LynxOS"
#define Z_OS_STRING_MAC_OS		"Mac OS"
#define Z_OS_STRING_MAC_OS_X		"Mac OS X"
#define Z_OS_STRING_MINIX		"MINIX"
#define Z_OS_STRING_MORPH_OS		"MorphOS"
#define Z_OS_STRING_MPE_XL		"MPE XL"
#define Z_OS_STRING_MS_DOS		"MS-DOS"
#define Z_OS_STRING_NET_BSD		"NetBSD"
#define Z_OS_STRING_NETWARE		"NetWare"
#define Z_OS_STRING_NON_STOP_OS		"NonStop OS"
#define Z_OS_STRING_NUCLEUS_RTOS	"Nucleus RTOS"
#define Z_OS_STRING_OPEN_BSD		"OpenBSD"
#define Z_OS_STRING_ORBIS_OS		"Orbis OS"
#define Z_OS_STRING_OS_2		"OS/2"
#define Z_OS_STRING_OS_9		"OS-9"
#define Z_OS_STRING_OS_400		"OS/400"
#define Z_OS_STRING_OSF_1		"OSF/1"
#define Z_OS_STRING_PALM_OS		"Palm OS"
#define Z_OS_STRING_PLAN_9		"Plan 9"
#define Z_OS_STRING_PSP_SYSTEM_SOFTWARE "PlayStation Portable System Software"
#define Z_OS_STRING_QNX			"QNX"
#define Z_OS_STRING_RTEMS		"RTEMS"
#define Z_OS_STRING_SCO_UNIX_SYSTEM_V	"SCO UNIX System V"
#define Z_OS_STRING_SINIX		"SINIX"
#define Z_OS_STRING_SOLARIS		"Solaris"
#define Z_OS_STRING_SUN_OS		"SunOS"
#define Z_OS_STRING_SYLLABLE		"Syllable"
#define Z_OS_STRING_SYMBIAN		"Symbian"
#define Z_OS_STRING_TVOS		"tvOS"
#define Z_OS_STRING_ULTRIX		"ULTRIX"
#define Z_OS_STRING_UNICOS		"UNICOS"
#define Z_OS_STRING_UNICOS_MP		"UNICOS/mp"
#define Z_OS_STRING_UNIX_WARE		"UnixWare"
#define Z_OS_STRING_UTS			"UTS"
#define Z_OS_STRING_VMS			"VMS"
#define Z_OS_STRING_VOS			"VOS"
#define Z_OS_STRING_VX_WORKS		"VxWorks"
#define Z_OS_STRING_WATCH_OS		"Watch OS"
#define Z_OS_STRING_WINDOWS		"Windows"
#define Z_OS_STRING_WINDOWS_CE		"Windows CE"
#define Z_OS_STRING_Z_OS		"z/OS"

#define Z_OS_BSD_I			Z_OS_BSD_386
#define Z_OS_BSD_OS			Z_OS_BSD_386
#define Z_OS_CONVEX_OS			Z_OS_CONVEX_UNIX
#define Z_OS_DIGITAL_UNIX		Z_OS_DEC_OSF_1
#define Z_OS_I5_OS			Z_OS_OS_400
#define Z_OS_IBM_I			Z_OS_OS_400
#define Z_OS_IOS			Z_OS_IPHONE_OS
#define Z_OS_MACOS			Z_OS_MAC_OS_X
#define Z_OS_OPEN_DESKTOP		Z_OS_SCO_UNIX_SYSTEM_V
#define Z_OS_OPEN_SERVER		Z_OS_SCO_UNIX_SYSTEM_V
#define Z_OS_OPEN_UNIX			Z_OS_UNIX_WARE
#define Z_OS_OS_X			Z_OS_MAC_OS_X
#define Z_OS_RELIANT_UNIX		Z_OS_SINIX
#define Z_OS_SCO_UNIX			Z_OS_SCO_UNIX_SYSTEM_V
#define Z_OS_TRU64_UNIX			Z_OS_DEC_OSF_1
#define Z_OS_WATCHOS			Z_OS_WATCH_OS

#define Z_OS_STRING_BSD_I		"BSDi"
#define Z_OS_STRING_BSD_OS		"BSD/OS"
#define Z_OS_STRING_CONVEX_OS		"ConvexOS"
#define Z_OS_STRING_DIGITAL_UNIX	"Digital UNIX"
#define Z_OS_STRING_I5_OS		"i5/OS"
#define Z_OS_STRING_IBM_I		"IBM i"
#define Z_OS_STRING_IOS			"iOS"
#define Z_OS_STRING_MACOS		"macOS"
#define Z_OS_STRING_OPEN_DESKTOP	"Open Desktop"
#define Z_OS_STRING_OPEN_SERVER		"OpenServer"
#define Z_OS_STRING_OPEN_UNIX		"Open UNIX"
#define Z_OS_STRING_OS_X		"OS X"
#define Z_OS_STRING_RELIANT_UNIX	"Reliant UNIX"
#define Z_OS_STRING_SCO_UNIX		"SCO UNIX"
#define Z_OS_STRING_TRU64_UNIX		"Tru64 UNIX"
#define Z_OS_STRING_WATCHOS		"watchOS"

#endif /* _Z_keys_OS_H_ */
