/* Zeta API - Z/formats/storage_medium_image/NES_Game_Pak/iNES.h
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.

 ___________________________________________________________
|							    |
|	 Daft: Public.StorageMediumImage.NESGamePak.iNES    |
|      Author: Fayzullin, Marat				    |
|  Extensions: .nes					    |
|  Created by: aka kevtris				    |
|	       aka NewRisingSun				    |
|     Used by: Any NES emulator				    |
|							    |
|  Reference:						    |
|  https://wiki.nesdev.com/w/index.php/INES		    |
|  http://forums.nesdev.com/viewtopic.php?p=17727#p17727    |
|  http://forums.nesdev.com/viewtopic.php?p=220624#p220624  |
|							    |
'==========================================================*/

#ifndef Z_formats_storage_medium_image_NES_Game_Pak_iNES_H
#define Z_formats_storage_medium_image_NES_Game_Pak_iNES_H

#include <Z/types/bitwise.h>

typedef Z_PACKED_STRUCTURE_BEGIN {
/* 0 */ ZInt32 signature; /* 4Eh, 45h, 53h, 1Ah ('NES' + MS-DOS EOF) */
/* 4 */ zuint8 prg_rom_page_count;
/* 5 */ zuint8 chr_rom_page_count;

/* 6 */ struct {Z_BIT_FIELD_MEMBERS(8, 5) (
		zuint8 mapper_index_low_nibble	:4,
		zuint8 has_4_screen_vram_layout :1,
		zuint8 has_trainer		:1,
		zuint8 has_persistent_wram	:1,
		zuint8 mirroring		:1
	)} flags_6;

	union {	struct {
		/* 7 */ struct {Z_BIT_FIELD_MEMBERS(8, 4) (
				zuint8 mapper_index_high_nibble :4,
				zuint8 rom_image_format		:1,
				zuint8 is_play_choice_10	:1,
				zuint8 is_vs_system		:1
			)} flags_7;

			/*----------------------------------------.
			| This field was a later extension to the |
			| iNES format. It is not widely used.	  |
			'========================================*/
		/* 8 */ zuint8 wram_size;

			/*--------------------------------------------.
			| Though in the official specification, very  |
			| few programs honor yhis field, as virtually |
			| no ROM images in circulation make use of it.|
			'============================================*/
		/* 9 */ struct {Z_BIT_FIELD_MEMBERS(8, 2) (
				zuint8 zero   :7,
				zuint8 is_pal :1
			)} flags_9;

		/* A */ zuint8 unused[6];
		} v1;

		struct {
		} v2;
	} as;
} Z_PACKED_STRUCTURE_END Z_iNESHeader;

#if Z_ISA_INTEGRAL_ENDIANNESS == Z_ENDIANNESS_LITTLE
#	define Z_INES_SIGNATURE 0x1A53454E
#else
#	define Z_INES_SIGNATURE 0x4E45531A
#endif

#define Z_INES_PRG_ROM_SIZE_UNIT 16384
#define Z_INES_CHR_ROM_SIZE_UNIT 8192
#define Z_INES_WRAM_SIZE_UNIT	 8192

/* ZiNESHeader::flags_6.mirroring */

#define Z_INES_MIRRORING_VERTICAL   0
#define Z_INES_MIRRORING_HORIZONTAL 1

#define Z_INES_TV_SYSTEM_NTSC	0
#define Z_INES_TV_SYSTEM_DUAL_1 1
#define Z_INES_TV_SYSTEM_PAL	2
#define Z_INES_TV_SYSTEM_DUAL_3 3


/*#define Z_INES_MAPPER_NONE		      0
#define Z_INES_MAPPER_NINTENDO_MMC1	      1
#define Z_INES_MAPPER_PRG_ROM_SWITCH	      2
#define Z_INES_MAPPER_CHR_VROM_SWITCH	      3
#define Z_INES_MAPPER_NINTENDO_MMC3	      4
#define Z_INES_MAPPER_NINTENDO_MMC5	      5
#define Z_INES_MAPPER_FFE_F4XXX_GAMES	      6
#define Z_INES_MAPPER_32K_PRG_ROM_SWITCH      7
#define Z_INES_MAPPER_FFE_F3XXX_GAMES	      8
#define Z_INES_MAPPER_NINTENDO_MMC2	      9
#define Z_INES_MAPPER_NINTENDO_MMC4	     10
#define Z_INES_MAPPER_COLOR_DREAMS_CHIPSET   11
#define Z_INES_MAPPER_FFE_F6XXX_GAMES	     12
#define Z_INES_MAPPER_100_IN_1_CART_SWITCH   15
#define Z_INES_MAPPER_BAN_DAI_CHIPSET	     16
#define Z_INES_MAPPER_FFE_F8XXX_GAMES	     17
#define Z_INES_MAPPER_JALECO_SS8806_CHIPSET  18
#define Z_INES_MAPPER_NAMCOT_106_CHIPSET     19
#define Z_INES_MAPPER_FAMICOM_DISK_SYSTEM    20
#define Z_INES_MAPPER_KONAMI_VRC4_2A_CHIPSET 21
#define Z_INES_MAPPER_KONAMI_VRC4_1B_CHIPSET 22
#define Z_INES_MAPPER_KONAMI_VRC4_1A_CHIPSET 23
#define Z_INES_MAPPER_KONAMI_VRC6_CHIPSET    24
#define Z_INES_MAPPER_KONAMI_VRC4_CHIPSET    25
#define Z_INES_MAPPER_IREM_G_101_CHIPSET     32
#define Z_INES_MAPPER_TAITO_TC0190_TC0350    33
#define Z_INES_MAPPER_32K_PRG_ROM_SWITCH     34
#define Z_INES_MAPPER_IREM_H3001_CHIPSET     65
#define Z_INES_MAPPER_74161_32_CHIPSET	     66
#define Z_INES_MAPPER_SUNSOFT_MAPPER_3	     67
#define Z_INES_MAPPER_SUNSOFT_MAPPER_4	     69
#define Z_INES_MAPPER_74161_32_CHIPSET	     70
#define Z_INES_MAPPER_X_005_CHIPSET	     80
#define Z_INES_MAPPER_C075_CHIPSET	     81
#define Z_INES_MAPPER_X1_17_CHIPSET	     82
#define Z_INES_MAPPER_CONY_MAPPER	     83
#define Z_INES_MAPPER_PASOFAMI_MAPPER	     84*/

#endif /* Z_formats_storage_medium_image_NES_Game_Pak_iNES_H */
