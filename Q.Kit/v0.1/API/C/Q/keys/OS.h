/* Q Kit C API - keys/OS.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_keys_OS_H__
#define __Q_keys_OS_H__

#define Q_OS_VENUS		0
#define Q_OS_AIX		1 /* IBM */
#define Q_OS_ANDROID		2
#define Q_OS_AMIGA_OS		3
#define Q_OS_AEGIS		4 /* Apollo Computer */
#define Q_OS_DOMAIN_OS		5 /* Apollo Computer */
#define Q_OS_BADA		6 /* Samsung Electronics */
#define Q_OS_BE_OS		7 /* Be */
#define Q_OS_BLUE_GENE		8 /* IBM */
#define Q_OS_BSD_386		9 
#define Q_OS_BSD_I		Q_OS_BSD_386
#define Q_OS_BSD_OS		Q_OS_BSD_386
#define Q_OS_CONVEX_OS		10
#define Q_OS_DC_OSX		11 /* Pyramid Technology */
#define Q_OS_DEC_OSF_1		12
#define Q_OS_DIGITAL_UNIX	Q_OS_DEC_OSF_1
#define Q_OS_TRU64_UNIX		Q_OS_DEC_OSF_1
#define Q_OS_DG_UX		13
#define Q_OS_DRAGONFLY_BSD	14
#define Q_OS_DYNIX		15
#define Q_OS_DYNIX_PTX		16
#define Q_OS_ECOS		17
#define Q_OS_FREE_BSD		18
#define Q_OS_GNU_HURD		19
#define Q_OS_HI_UX_MPP		20 /* Hitachi */
#define Q_OS_HP_UX		21 /* Hewlett-Packard */
#define Q_OS_INTEGRITY		22
#define Q_OS_IPHONE_OS		23 /* Apple */
#define Q_OS_IOS		Q_OS_IPHONE_OS
#define Q_OS_IRIX		24 /* Silicon Graphics */
#define Q_OS_LINUX		25
#define Q_OS_LYNX_OS		26
#define Q_OS_MAC_OS		27 /* Apple Computer */
#define Q_OS_MAC_OS_X		28 /* Apple Computer */
#define Q_OS_OS_X		Q_OS_MAC_OS_X
#define Q_OS_MINIX		29
#define Q_OS_MORPH_OS		30
#define Q_OS_MPE		31
#define Q_OS_MPE_IX		32
#define Q_OS_MPE_XL		33
#define Q_OS_MS_DOS		34 /* Microsoft */
#define Q_OS_MVS		35 /* IBM */
#define Q_OS_NET_BSD		36
#define Q_OS_NON_STOP_OS	37 /* Tandem Computers */
#define Q_OS_NUCLEUS_RTOS	38
#define Q_OS_OPEN_BSD		39
#define Q_OS_OS_2		40
#define Q_OS_OS_9		41 /* Microware Systems Corporation */
#define Q_OS_OS_360		42 /* IBM */
#define Q_OS_OS_390		43 /* IBM */
#define Q_OS_OS_400		44
#define Q_OS_I5_OS		Q_OS_OS_400
#define Q_OS_IBM_I		Q_OS_OS_400
#define Q_OS_PALM_OS		45
#define Q_OS_PLAN_9		46
#define Q_OS_QNX		47
#define Q_OS_SCO_UNIX_SYSTEM_V	48
#define Q_OS_OPEN_DESKTOP	Q_OS_SCO_UNIX_SYSTEM_V
#define Q_OS_SCO_UNIX		Q_OS_SCO_UNIX_SYSTEM_V
#define Q_OS_SCO_OPEN_SERVER	Q_OS_SCO_UNIX_SYSTEM_V
#define Q_OS_SINIX		49 /* Siemens Nixdorf Informationssysteme */
#define Q_OS_RELIANT_UNIX	Q_OS_SINIX /* Fujitsu Siemens Computers */
#define Q_OS_SUN_OS		50
#define Q_OS_SOLARIS		Q_OS_SUN_OS
#define Q_OS_SYLLABLE		51
#define Q_OS_SYMBIAN		52
#define Q_OS_ULTRIX		53
#define Q_OS_UNICOS		54
#define Q_OS_UNICOS_MP		55
#define Q_OS_UNIX_WARE		56
#define Q_OS_OPEN_UNIX		Q_OS_UNIX_WARE
#define Q_OS_UTS		57 /* Amdahl Corporation */
#define Q_OS_VMS		58
#define Q_OS_VOS		59 /* Stratus Technologies */
#define Q_OS_VX_WORKS		60
#define Q_OS_WINDOWS		61 /* Microsoft */
#define Q_OS_WINDOWS_CE		62 /* Microsoft */
#define Q_OS_XENIX		63
#define Q_OS_Z_OS		64 /* IBM */
#define Q_OS_Z_TPF		65 /* IBM */
#define Q_OS_Z_VM		66 /* IBM */
#define Q_OS_Z_VSE		67 /* IBM */

#define Q_OS_STRING_VENUS		"Venus"
#define Q_OS_STRING_AIX			"AIX"
#define Q_OS_STRING_ANDROID		"Android"
#define Q_OS_STRING_AMIGA_OS		"AmigaOS"
#define Q_OS_STRING_AEGIS		"AEGIS"
#define Q_OS_STRING_DOMAIN_OS		"Domain/OS"
#define Q_OS_STRING_BADA		"Bada"
#define Q_OS_STRING_BE_OS		"BeOS"
#define Q_OS_STRING_BLUE_GENE		"Blue Gene"
#define Q_OS_STRING_BSD_386		"BSD/386"
#define Q_OS_STRING_BSD_I		"BSDi"
#define Q_OS_STRING_BSD_OS		"BSD/OS"
#define Q_OS_STRING_CONVEX_OS		"ConvexOS"
#define Q_OS_STRING_DC_OSX		"DC/OSx"
#define Q_OS_STRING_DEC_OSF_1		"DEC OSF/1"
#define Q_OS_STRING_DIGITAL_UNIX	"Digital UNIX"
#define Q_OS_STRING_TRU64_UNIX		"Tru64 UNIX"
#define Q_OS_STRING_DG_UX		"DG/UX"
#define Q_OS_STRING_DRAGONFLY_BSD	"DragonFly BSD"
#define Q_OS_STRING_DYNIX		"DYNIX"
#define Q_OS_STRING_DYNIX_PTX		"DYNIX/ptx"
#define Q_OS_STRING_ECOS		"eCos"
#define Q_OS_STRING_FREE_BSD		"FreeBSD"
#define Q_OS_STRING_GNU_HURD		"GNU/Hurd"
#define Q_OS_STRING_HI_UX_MPP		"HI-UX/MPP"
#define Q_OS_STRING_HP_UX		"HP-UX"
#define Q_OS_STRING_INTEGRITY		"INTEGRITY"
#define Q_OS_STRING_IPHONE_OS		"iPhone OS"
#define Q_OS_STRING_IOS			"iOS"
#define Q_OS_STRING_IRIX		"IRIX"
#define Q_OS_STRING_LINUX		"Linux"
#define Q_OS_STRING_LYNX_OS		"LynxOS"
#define Q_OS_STRING_MAC_OS		"Mac OS"
#define Q_OS_STRING_MAC_OS_X		"Mac OS X"
#define Q_OS_STRING_OS_X		"OS X"
#define Q_OS_STRING_MINIX		"MINIX"
#define Q_OS_STRING_MORPH_OS		"MorphOS"
#define Q_OS_STRING_MPE			"MPE"
#define Q_OS_STRING_MPE_IX		"MPE/iX"
#define Q_OS_STRING_MPE_XL		"MPE/XL"
#define Q_OS_STRING_MS_DOS		"MS-DOS"
#define Q_OS_STRING_MVS			"MVS"
#define Q_OS_STRING_NET_BSD		"NetBSD"
#define Q_OS_STRING_NON_STOP_OS		"NonStop OS"
#define Q_OS_STRING_NUCLEUS_RTOS	"Nucleus RTOS"
#define Q_OS_STRING_OPEN_BSD		"OpenBSD"
#define Q_OS_STRING_OS_2		"OS/2"
#define Q_OS_STRING_OS_9		"OS-9"
#define Q_OS_STRING_OS_360		"OS/360"
#define Q_OS_STRING_OS_390		"OS/390"
#define Q_OS_STRING_OS_400		"OS/400"
#define Q_OS_STRING_I5_OS		"i5/OS"
#define Q_OS_STRING_IBM_I		"IBM i"
#define Q_OS_STRING_PALM_OS		"Palm OS"
#define Q_OS_STRING_PLAN_9		"Plan 9"
#define Q_OS_STRING_QNX			"QNX"
#define Q_OS_STRING_SCO_UNIX_SYSTEM_V	"SCO UNIX System V"
#define Q_OS_STRING_OPEN_DESKTOP	"Open Desktop"
#define Q_OS_STRING_SCO_UNIX		"SCO UNIX"
#define Q_OS_STRING_SCO_OPEN_SERVER	"SCO OpenServer"
#define Q_OS_STRING_SINIX		"SINIX"
#define Q_OS_STRING_RELIANT_UNIX	"Reliant UNIX"
#define Q_OS_STRING_SUN_OS		"SunOS"
#define Q_OS_STRING_SOLARIS		"Solaris"
#define Q_OS_STRING_SYLLABLE		"Syllable"
#define Q_OS_STRING_SYMBIAN		"Symbian"
#define Q_OS_STRING_ULTRIX		"ULTRIX"
#define Q_OS_STRING_UNICOS		"UNICOS"
#define Q_OS_STRING_UNICOS_MP		"UNICOS/mp"
#define Q_OS_STRING_UNIX_WARE		"UnixWare"
#define Q_OS_STRING_OPEN_UNIX		"Open UNIX"
#define Q_OS_STRING_UTS			"UTS"
#define Q_OS_STRING_VMS			"VMS"
#define Q_OS_STRING_VOS			"VOS"
#define Q_OS_STRING_VX_WORKS		"VxWorks"
#define Q_OS_STRING_WINDOWS		"Windows"
#define Q_OS_STRING_WINDOWS_CE		"Windows CE"
#define Q_OS_STRING_XENIX		"Xenix"
#define Q_OS_STRING_Z_OS		"z/OS"
#define Q_OS_STRING_Z_TPF		"z/TPF"
#define Q_OS_STRING_Z_VM		"z/VM"
#define Q_OS_STRING_Z_VSE		"z/VSE"


#endif /* __Q_keys_OS_H__ */
