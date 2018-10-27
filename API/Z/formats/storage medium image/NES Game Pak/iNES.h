/* Z Kit - formats/storage medium image/NES Game Pak/iNES.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.

.------------------------------.
| Extensions: nes	       |
| Endianness: Little	       |
| Created by: Fayzullin, Marat |
|    Used by: Any NES emulator |
'-----------------------------*/

#ifndef _Z_formats_storage_medium_image_NES_Game_Pak_iNES_H_
#define _Z_formats_storage_medium_image_NES_Game_Pak_iNES_H_

#include <Z/types/base.h>

Z_DEFINE_STRICT_STRUCTURE (
	zuint8 nes[4]; /* 4E 45 53 1A ('NES' + MS-DOS EOF) */
	zuint8 prg_rom_page_count;
	zuint8 chr_rom_page_count;
	zuint8 rom_control_0;
	zuint8 rom_control_1;
	zuint8 nes_rom;
	zuint8 vs_unisystem_rom;
	zuint8 playchoice_rom;
	zuint8 zero_0;
	zuint8 zero_1;
	zuint8 full_ntsc_compatible;
	zuint8 not_necessarily_pal_compatible;
	zuint8 extra_ram_at_6000h_7fffh;
	zuint8 dont_have_bus_conflicts;
	zuint8 zero_2[6];
) ZiNESHeader;

/*#define Z_INES_MAPPER_NONE			00
#define Z_INES_MAPPER_NINTENDO_MMC1_CHIPSET	01
#define Z_INES_MAPPER_PRG_ROM_SWITCH		02
#define Z_INES_MAPPER_CHR_VROM_SWITCH		03
#define Z_INES_MAPPER_NINTENDO_MMC3_CHIPSET	04
#define Z_INES_MAPPER_NINTENDO_MMC5_CHIPSET	05
#define Z_INES_MAPPER_FFE_F4XXX_GAMES		06
#define Z_INES_MAPPER_32K_PRG_ROM_SWITCH	07
#define Z_INES_MAPPER_FFE_F3XXX_GAMES		08
#define Z_INES_MAPPER_NINTENDO_MMC2_CHIPSET	09
#define Z_INES_MAPPER_NINTENDO_MMC4_CHIPSET	10
#define Z_INES_MAPPER_COLOR_DREAMS_CHIPSET	11
#define Z_INES_MAPPER_FFE_F6XXX_GAMES		12
#define Z_INES_MAPPER_100_IN_1_CART_SWITCH	15
#define Z_INES_MAPPER_BAN_DAI_CHIPSET		16
#define Z_INES_MAPPER_FFE_F8XXX_GAMES		17
#define Z_INES_MAPPER_JALECO_SS8806_CHIPSET	18
#define Z_INES_MAPPER_NAMCOT_106_CHIPSET	19
#define Z_INES_MAPPER_FAMICOM_DISK_SYSTEM	20
#define Z_INES_MAPPER_KONAMI_VRC4_2A_CHIPSET	21
#define Z_INES_MAPPER_KONAMI_VRC4_1B_CHIPSET	22
#define Z_INES_MAPPER_KONAMI_VRC4_1A_CHIPSET	23
#define Z_INES_MAPPER_KONAMI_VRC6_CHIPSET	24
#define Z_INES_MAPPER_KONAMI_VRC4_CHIPSET	25
#define Z_INES_MAPPER_IREM_G_101_CHIPSET	32
#define Z_INES_MAPPER_TAITO_TC0190_TC0350	33
#define Z_INES_MAPPER_32K_PRG_ROM_SWITCH	34
#define Z_INES_MAPPER_IREM_H3001_CHIPSET	65
#define Z_INES_MAPPER_74161_32_CHIPSET		66
#define Z_INES_MAPPER_SUNSOFT_MAPPER_3		67
#define Z_INES_MAPPER_SUNSOFT_MAPPER_4		69
#define Z_INES_MAPPER_74161_32_CHIPSET		70
#define Z_INES_MAPPER_X_005_CHIPSET		80
#define Z_INES_MAPPER_C075_CHIPSET		81
#define Z_INES_MAPPER_X1_17_CHIPSET		82
#define Z_INES_MAPPER_CONY_MAPPER		83
#define Z_INES_MAPPER_PASOFAMI_MAPPER		84*/

#endif /* _Z_formats_storage_medium_image_NES_Game_Pak_iNES_H_ */
