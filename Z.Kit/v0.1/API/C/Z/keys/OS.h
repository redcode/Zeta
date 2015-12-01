/* Z Kit C API - keys/OS.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_keys_OS_H__
#define __Z_keys_OS_H__

#define Z_OS_VENUS	       0
#define Z_OS_AIX	       1 /* IBM */
#define Z_OS_ANDROID	       2
#define Z_OS_AMIGA_OS	       3
#define Z_OS_AEGIS	       4 /* Apollo Computer */
#define Z_OS_DOMAIN_OS	       5 /* Apollo Computer */
#define Z_OS_BADA	       6 /* Samsung Electronics */
#define Z_OS_BE_OS	       7 /* Be */
#define Z_OS_BLUE_GENE	       8 /* IBM */
#define Z_OS_BSD_386	       9 
#define Z_OS_BSD_I	       Z_OS_BSD_386
#define Z_OS_BSD_OS	       Z_OS_BSD_386
#define Z_OS_CONVEX_OS	       10
#define Z_OS_DC_OSX	       11 /* Pyramid Technology */
#define Z_OS_DEC_OSF_1	       12
#define Z_OS_DIGITAL_UNIX      Z_OS_DEC_OSF_1
#define Z_OS_TRU64_UNIX	       Z_OS_DEC_OSF_1
#define Z_OS_DG_UX	       13
#define Z_OS_DRAGONFLY_BSD     14
#define Z_OS_DYNIX	       15
#define Z_OS_DYNIX_PTX	       16
#define Z_OS_ECOS	       17
#define Z_OS_FREE_BSD	       18
#define Z_OS_GNU_HURD	       19
#define Z_OS_HI_UX_MPP	       20 /* Hitachi */
#define Z_OS_HP_UX	       21 /* Hewlett-Packard */
#define Z_OS_INTEGRITY	       22
#define Z_OS_IPHONE_OS	       23 /* Apple */
#define Z_OS_IOS	       Z_OS_IPHONE_OS
#define Z_OS_IRIX	       24 /* Silicon Graphics */
#define Z_OS_LINUX	       25
#define Z_OS_LYNX_OS	       26
#define Z_OS_MAC_OS	       27 /* Apple Computer */
#define Z_OS_MAC_OS_X	       28 /* Apple Computer */
#define Z_OS_OS_X	       Z_OS_MAC_OS_X
#define Z_OS_MINIX	       29
#define Z_OS_MORPH_OS	       30
#define Z_OS_MPE	       31
#define Z_OS_MPE_IX	       32
#define Z_OS_MPE_XL	       33
#define Z_OS_MS_DOS	       34 /* Microsoft */
#define Z_OS_MVS	       35 /* IBM */
#define Z_OS_NET_BSD	       36
#define Z_OS_NETWARE	       37
#define Z_OS_NEXTSTEP	       38
#define Z_OS_NON_STOP_OS       39 /* Tandem Computers */
#define Z_OS_NUCLEUS_RTOS      40
#define Z_OS_OPEN_BSD	       41
#define Z_OS_OS_2	       42
#define Z_OS_OS_9	       43 /* Microware Systems Corporation */
#define Z_OS_OS_360	       44 /* IBM */
#define Z_OS_OS_390	       45 /* IBM */
#define Z_OS_OS_400	       46
#define Z_OS_I5_OS	       Z_OS_OS_400
#define Z_OS_IBM_I	       Z_OS_OS_400
#define Z_OS_PALM_OS	       47
#define Z_OS_PLAN_9	       48
#define Z_OS_QNX	       49
#define Z_OS_SCO_UNIX_SYSTEM_V 50
#define Z_OS_OPEN_DESKTOP      Z_OS_SCO_UNIX_SYSTEM_V
#define Z_OS_SCO_UNIX	       Z_OS_SCO_UNIX_SYSTEM_V
#define Z_OS_SCO_OPEN_SERVER   Z_OS_SCO_UNIX_SYSTEM_V
#define Z_OS_SINIX	       51 /* Siemens Nixdorf Informationssysteme */
#define Z_OS_RELIANT_UNIX      Z_OS_SINIX /* Fujitsu Siemens Computers */
#define Z_OS_SOLARIS	       52
#define Z_OS_SUN_OS	       53
#define Z_OS_SYLLABLE	       54
#define Z_OS_SYMBIAN	       55
#define Z_OS_ULTRIX	       56
#define Z_OS_UNICOS	       57
#define Z_OS_UNICOS_MP	       58
#define Z_OS_UNIX_WARE	       59
#define Z_OS_OPEN_UNIX	       Z_OS_UNIX_WARE
#define Z_OS_UTS	       60 /* Amdahl Corporation */
#define Z_OS_VMS	       61
#define Z_OS_VOS	       62 /* Stratus Technologies */
#define Z_OS_VX_WORKS	       63
#define Z_OS_WINDOWS	       64 /* Microsoft */
#define Z_OS_WINDOWS_CE	       65 /* Microsoft */
#define Z_OS_XENIX	       66
#define Z_OS_Z_OS	       67 /* IBM */
#define Z_OS_Z_TPF	       68 /* IBM */
#define Z_OS_Z_VM	       69 /* IBM */
#define Z_OS_Z_VSE	       70 /* IBM */

#define Z_OS_STRING_VENUS	      "Venus"
#define Z_OS_STRING_AIX		      "AIX"
#define Z_OS_STRING_ANDROID	      "Android"
#define Z_OS_STRING_AMIGA_OS	      "AmigaOS"
#define Z_OS_STRING_AEGIS	      "AEGIS"
#define Z_OS_STRING_DOMAIN_OS	      "Domain/OS"
#define Z_OS_STRING_BADA	      "Bada"
#define Z_OS_STRING_BE_OS	      "BeOS"
#define Z_OS_STRING_BLUE_GENE	      "Blue Gene"
#define Z_OS_STRING_BSD_386	      "BSD/386"
#define Z_OS_STRING_BSD_I	      "BSDi"
#define Z_OS_STRING_BSD_OS	      "BSD/OS"
#define Z_OS_STRING_CONVEX_OS	      "ConvexOS"
#define Z_OS_STRING_DC_OSX	      "DC/OSx"
#define Z_OS_STRING_DEC_OSF_1	      "DEC OSF/1"
#define Z_OS_STRING_DIGITAL_UNIX      "Digital UNIX"
#define Z_OS_STRING_TRU64_UNIX	      "Tru64 UNIX"
#define Z_OS_STRING_DG_UX	      "DG/UX"
#define Z_OS_STRING_DRAGONFLY_BSD     "DragonFly BSD"
#define Z_OS_STRING_DYNIX	      "DYNIX"
#define Z_OS_STRING_DYNIX_PTX	      "DYNIX/ptx"
#define Z_OS_STRING_ECOS	      "eCos"
#define Z_OS_STRING_FREE_BSD	      "FreeBSD"
#define Z_OS_STRING_GNU_HURD	      "GNU/Hurd"
#define Z_OS_STRING_HI_UX_MPP	      "HI-UX/MPP"
#define Z_OS_STRING_HP_UX	      "HP-UX"
#define Z_OS_STRING_INTEGRITY	      "INTEGRITY"
#define Z_OS_STRING_IPHONE_OS	      "iPhone OS"
#define Z_OS_STRING_IOS		      "iOS"
#define Z_OS_STRING_IRIX	      "IRIX"
#define Z_OS_STRING_LINUX	      "Linux"
#define Z_OS_STRING_LYNX_OS	      "LynxOS"
#define Z_OS_STRING_MAC_OS	      "Mac OS"
#define Z_OS_STRING_MAC_OS_X	      "Mac OS X"
#define Z_OS_STRING_OS_X	      "OS X"
#define Z_OS_STRING_MINIX	      "MINIX"
#define Z_OS_STRING_MORPH_OS	      "MorphOS"
#define Z_OS_STRING_MPE		      "MPE"
#define Z_OS_STRING_MPE_IX	      "MPE/iX"
#define Z_OS_STRING_MPE_XL	      "MPE/XL"
#define Z_OS_STRING_MS_DOS	      "MS-DOS"
#define Z_OS_STRING_MVS		      "MVS"
#define Z_OS_STRING_NET_BSD	      "NetBSD"
#define Z_OS_STRING_NETWARE	      "NetWare"
#define Z_OS_STRING_NEXTSTEP	      "NeXTSTEP"
#define Z_OS_STRING_NON_STOP_OS	      "NonStop OS"
#define Z_OS_STRING_NUCLEUS_RTOS      "Nucleus RTOS"
#define Z_OS_STRING_OPEN_BSD	      "OpenBSD"
#define Z_OS_STRING_OS_2	      "OS/2"
#define Z_OS_STRING_OS_9	      "OS-9"
#define Z_OS_STRING_OS_360	      "OS/360"
#define Z_OS_STRING_OS_390	      "OS/390"
#define Z_OS_STRING_OS_400	      "OS/400"
#define Z_OS_STRING_I5_OS	      "i5/OS"
#define Z_OS_STRING_IBM_I	      "IBM i"
#define Z_OS_STRING_PALM_OS	      "Palm OS"
#define Z_OS_STRING_PLAN_9	      "Plan 9"
#define Z_OS_STRING_QNX		      "QNX"
#define Z_OS_STRING_SCO_UNIX_SYSTEM_V "SCO UNIX System V"
#define Z_OS_STRING_OPEN_DESKTOP      "Open Desktop"
#define Z_OS_STRING_SCO_UNIX	      "SCO UNIX"
#define Z_OS_STRING_SCO_OPEN_SERVER   "SCO OpenServer"
#define Z_OS_STRING_SINIX	      "SINIX"
#define Z_OS_STRING_RELIANT_UNIX      "Reliant UNIX"
#define Z_OS_STRING_SOLARIS	      "Solaris"
#define Z_OS_STRING_SUN_OS	      "SunOS"
#define Z_OS_STRING_SYLLABLE	      "Syllable"
#define Z_OS_STRING_SYMBIAN	      "Symbian"
#define Z_OS_STRING_ULTRIX	      "ULTRIX"
#define Z_OS_STRING_UNICOS	      "UNICOS"
#define Z_OS_STRING_UNICOS_MP	      "UNICOS/mp"
#define Z_OS_STRING_UNIX_WARE	      "UnixWare"
#define Z_OS_STRING_OPEN_UNIX	      "Open UNIX"
#define Z_OS_STRING_UTS		      "UTS"
#define Z_OS_STRING_VMS		      "VMS"
#define Z_OS_STRING_VOS		      "VOS"
#define Z_OS_STRING_VX_WORKS	      "VxWorks"
#define Z_OS_STRING_WINDOWS	      "Windows"
#define Z_OS_STRING_WINDOWS_CE	      "Windows CE"
#define Z_OS_STRING_XENIX	      "Xenix"
#define Z_OS_STRING_Z_OS	      "z/OS"
#define Z_OS_STRING_Z_TPF	      "z/TPF"
#define Z_OS_STRING_Z_VM	      "z/VM"
#define Z_OS_STRING_Z_VSE	      "z/VSE"

#endif /* __Z_keys_OS_H__ */
