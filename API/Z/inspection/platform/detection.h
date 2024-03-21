/* Zeta API - Z/inspection/platform/detection.h
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_inspection_platform_detection_H
#define Z_inspection_platform_detection_H

/* Computers */

#if defined(__APPLE2__) || (__APPLE2ENH__)
#	define Z_PLATFORM Z_PLATFORM_APPLE_II

#elif defined(__ATMOS__)
#	define Z_PLATFORM Z_PLATFORM_ATMOS

#elif defined(__BBC__)
#	define Z_PLATFORM Z_PLATFORM_BBC_MICRO

#elif defined(__CBM610__)
#	define Z_PLATFORM Z_PLATFORM_CBM_IIB

#elif defined(__CBM510__)
#	define Z_PLATFORM Z_PLATFORM_CBM_IIP

#elif defined(__OSIC1P__)
#	define Z_PLATFORM Z_PLATFORM_CHALLENGER_1P

#elif defined(__CX16__)
#	define Z_PLATFORM Z_PLATFORM_COMMANDER_X16

#elif defined(__C16__) && !defined(__PLUS4__)
#	define Z_PLATFORM Z_PLATFORM_COMMODORE_16

#elif defined(__C64__)
#	define Z_PLATFORM Z_PLATFORM_COMMODORE_64

#elif defined(__C128__)
#	define Z_PLATFORM Z_PLATFORM_COMMODORE_128

#elif defined(_M_MPPC)
#	define Z_PLATFORM Z_PLATFORM_MACINTOSH

#elif defined(__PLUS4__)
#	define Z_PLATFORM Z_PLATFORM_PLUS_4

#elif defined(__PET__)
#	define Z_PLATFORM Z_PLATFORM_PET

/*#elif defined(__TELESTRAT__)
#	define Z_PLATFORM Z_PLATFORM_TELESTRAT*/

#elif defined(__VIC20__)
#	define Z_PLATFORM Z_PLATFORM_VIC_20

/* Consoles */

#elif defined(__ATARI2600__)
#	define Z_PLATFORM Z_PLATFORM_ATARI_2600

#elif defined(__ATARI5200__)
#	define Z_PLATFORM Z_PLATFORM_ATARI_5200

#elif defined(__CREATIVISION__)
#	define Z_PLATFORM Z_PLATFORM_CREATIVISION

#elif defined(__GAMATE__)
#	define Z_PLATFORM Z_PLATFORM_GAMATE

#elif defined(__LYNX__)
#	define Z_PLATFORM Z_PLATFORM_LYNX

#elif defined(__NES__)
#	define Z_PLATFORM Z_PLATFORM_NES

#elif defined(__PCE__)
#	define Z_PLATFORM Z_PLATFORM_PC_ENGINE

#elif defined(__CELLOS_LV2__) /* (Revisar, puede que sólo para la PPU) */
#	define Z_PLATFORM Z_PLATFORM_PS3

#elif defined(__ORBIS__)
#	define Z_PLATFORM Z_PLATFORM_PS4

#elif	defined(__psp__) || \
	defined(_PSP   )/* || \
	defined(PSP    )*/

#	define Z_PLATFORM Z_PLATFORM_PSP

#elif defined(__SUPERVISION__)
#	define Z_PLATFORM Z_PLATFORM_SUPERVISION
#endif

#endif /* Z_inspection_platform_detection_H */
