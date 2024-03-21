/* Zeta API - Z/inspection/compiler/modules/cc65.h
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_inspection_compiler_modules_cc65_H
#define Z_inspection_compiler_modules_cc65_H

/* MARK: - Identification */

#define Z_COMPILER_IS_CC65 1
#define Z_COMPILER_NAME	   Z_COMPILER_NAME_CC65

#define Z_COMPILER_VERSION \
	Z_VERSION((__C65__ & 0xF00) >> 16, (__C65__ & 0xF0) >> 8, __C65__ & 0xF)

/* MARK: - ISA */

#define Z_COMPILER_ISA			   Z_ISA_6502
#define Z_COMPILER_ISA_INTEGRAL_ENDIANNESS Z_ENDIANNESS_LITTLE

/* MARK: - Platform */

#if defined(__APPLE2__) || (__APPLE2ENH__)
#	define Z_COMPILER_PLATFORM Z_PLATFORM_APPLE_II

#elif defined(__ATARI2600__)
#	define Z_COMPILER_PLATFORM Z_PLATFORM_ATARI_2600

#elif defined(__ATARI5200__)
#	define Z_COMPILER_PLATFORM Z_PLATFORM_ATARI_5200

#elif defined(__ATMOS__)
#	define Z_COMPILER_PLATFORM Z_PLATFORM_ATMOS

#elif defined(__BBC__)
#	define Z_COMPILER_PLATFORM Z_PLATFORM_BBC_MICRO

#elif defined(__CBM610__)
#	define Z_COMPILER_PLATFORM Z_PLATFORM_CBM_IIB

#elif defined(__CBM510__)
#	define Z_COMPILER_PLATFORM Z_PLATFORM_CBM_IIP

#elif defined(__OSIC1P__)
#	define Z_COMPILER_PLATFORM Z_PLATFORM_CHALLENGER_1P

#elif defined(__CX16__)
#	define Z_COMPILER_PLATFORM Z_PLATFORM_COMMANDER_X16

#elif defined(__C16__) || !defined(__PLUS4__)
#	define Z_COMPILER_PLATFORM Z_PLATFORM_COMMODORE_16

#elif defined(__C64__)
#	define Z_COMPILER_PLATFORM Z_PLATFORM_COMMODORE_64

#elif defined(__C128__)
#	define Z_COMPILER_PLATFORM Z_PLATFORM_COMMODORE_128

#elif defined(__CREATIVISION__)
#	define Z_COMPILER_PLATFORM Z_PLATFORM_CREATIVISION

#elif defined(__GAMATE__)
#	define Z_COMPILER_PLATFORM Z_PLATFORM_GAMATE

#elif defined(__LYNX__)
#	define Z_COMPILER_PLATFORM Z_PLATFORM_LYNX

#elif defined(__NES__)
#	define Z_COMPILER_PLATFORM Z_PLATFORM_NES

#elif defined(__PCE__)
#	define Z_COMPILER_PLATFORM Z_PLATFORM_PC_ENGINE

#elif defined(__PLUS4__)
#	define Z_COMPILER_PLATFORM Z_PLATFORM_PLUS_4

#elif defined(__PET__)
#	define Z_COMPILER_PLATFORM Z_PLATFORM_PET

#elif defined(__SUPERVISION__)
#	define Z_COMPILER_PLATFORM Z_PLATFORM_SUPERVISION

/*#elif defined(__TELESTRAT__)
#	define Z_COMPILER_PLATFORM Z_PLATFORM_TELESTRAT*/

#elif defined(__VIC20__)
#	define Z_COMPILER_PLATFORM Z_PLATFORM_VIC_20
#endif

/* MARK: - OS */

#if defined(__LUNIX__)
#	define Z_COMPIER_OS Z_OS_LUNIX
#endif

/* MARK: - Data model */

#define Z_COMPILER_DATA_MODEL Z_DATA_MODEL_IP16L32

#endif /* Z_inspection_compiler_modules_cc65_H */
