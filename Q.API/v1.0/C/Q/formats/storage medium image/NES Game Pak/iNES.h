/* Q API - formats/storage medium image/NES Game Pak/iNES.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2014 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3.
 _______________________________
/\				\
\_| Extensions: .nes		 |
  | Endianness: Little		 |
  | Created by: Marat Fayzullin  |
  | Used by:	Any NES emulator |
  |   ___________________________|_
   \_/___________________________*/

#ifndef __Q_formats_storage_medium_image_NES_Game_Pak_iNES_H__
#define __Q_formats_storage_medium_image_NES_Game_Pak_iNES_H__

#include <Q/types/base.h>

#define Q_INES_MAPPER_NONE			00
#define Q_INES_MAPPER_NINTENDO_MMC1_CHIPSET	01
#define Q_INES_MAPPER_PRG_ROM_SWITCH		02
#define Q_INES_MAPPER_CHR_VROM_SWITCH		03
#define Q_INES_MAPPER_NINTENDO_MMC3_CHIPSET	04
#define Q_INES_MAPPER_NINTENDO_MMC5_CHIPSET	05
#define Q_INES_MAPPER_FFE_F4XXX_GAMES		06
#define Q_INES_MAPPER_32K_PRG_ROM_SWITCH	07
#define Q_INES_MAPPER_FFE_F3XXX_GAMES		08
#define Q_INES_MAPPER_NINTENDO_MMC2_CHIPSET	09
#define Q_INES_MAPPER_NINTENDO_MMC4_CHIPSET	10
#define Q_INES_MAPPER_COLOR_DREAMS_CHIPSET	11
#define Q_INES_MAPPER_FFE_F6XXX_GAMES		12
#define Q_INES_MAPPER_100_IN_1_CART_SWITCH	15
#define Q_INES_MAPPER_BAN_DAI_CHIPSET		16
#define Q_INES_MAPPER_FFE_F8XXX_GAMES		17
#define Q_INES_MAPPER_JALECO_SS8806_CHIPSET	18
#define Q_INES_MAPPER_NAMCOT_106_CHIPSET	19
#define Q_INES_MAPPER_FAMICOM_DISK_SYSTEM	20
#define Q_INES_MAPPER_KONAMI_VRC4_2A_CHIPSET	21
#define Q_INES_MAPPER_KONAMI_VRC4_1B_CHIPSET	22
#define Q_INES_MAPPER_KONAMI_VRC4_1A_CHIPSET	23
#define Q_INES_MAPPER_KONAMI_VRC6_CHIPSET	24
#define Q_INES_MAPPER_KONAMI_VRC4_CHIPSET	25
#define Q_INES_MAPPER_IREM_G_101_CHIPSET	32
#define Q_INES_MAPPER_TAITO_TC0190_TC0350	33
#define Q_INES_MAPPER_32K_PRG_ROM_SWITCH	34
#define Q_INES_MAPPER_IREM_H3001_CHIPSET	65
#define Q_INES_MAPPER_74161_32_CHIPSET		66
#define Q_INES_MAPPER_SUNSOFT_MAPPER_3		67
#define Q_INES_MAPPER_SUNSOFT_MAPPER_4		69
#define Q_INES_MAPPER_74161_32_CHIPSET		70
#define Q_INES_MAPPER_X_005_CHIPSET		80
#define Q_INES_MAPPER_C075_CHIPSET		81
#define Q_INES_MAPPER_X1_17_CHIPSET		82
#define Q_INES_MAPPER_CONY_MAPPER		83
#define Q_INES_MAPPER_PASOFAMI_MAPPER		84

Q_DEFINE_STRICT_STRUCTURE(
	quint8 nes[4]; /* 4E 45 53 1A ('NES' + MS-DOS EOF) */
	quint8 prg_rom_page_count;
	quint8 chr_rom_page_count;
	quint8 rom_control_0;
	quint8 rom_control_1;
	quint8 nes_rom;
	quint8 vs_unisystem_rom;
	quint8 playchoice_rom;
	quint8 zero_0;
	quint8 zero_1;
	quint8 full_compatible_with_ntsc_console;
	quint8 not_necessarily_full_compatible_with_pal_console;
	quint8 extra_ram_at_6000h_7fffh;
	quint8 dont_have_bus_conflicts;
	quint8 zero_2[6];
) QiNESHeader;

#define Q_INES_HEADER(p) ((QiNESHeader *)(p))

#endif /* __Q_formats_storage_medium_image_NES_Game_Pak_iNES_H__ */
