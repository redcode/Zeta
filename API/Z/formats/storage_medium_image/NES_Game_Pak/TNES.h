/* Zeta API - Z/formats/storage_medium_image/NES_Game_Pak/TNES.h
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.

 ____________________________________________
|					     |
|  Extensions: ?			     |
|  Created by: Nintendo			     |
|					     |
|  Reference:				     |
|  https://wiki.nesdev.com/w/index.php/TNES  |
|					     |
'===========================================*/

#ifndef Z_formats_storage_medium_image_NES_Game_Pak_TNES_H
#define Z_formats_storage_medium_image_NES_Game_Pak_TNES_H

#include <Z/types/bitwise.h>

typedef Z_PACKED_STRUCTURE_BEGIN {
/* 0 */ ZInt32 signature; /* 54h, 4Eh, 45h, 53h ('TNES') */
/* 4 */ zuint8 mapper;
/* 5 */ zuint8 prg_rom_size;
/* 6 */ zuint8 chr_rom_size;
/* 7 */ zuint8 has_wram;
/* 8 */ zuint8 mirroring;
/* 9 */ zuint8 has_battery;
/* A */ zuint8 unknown[2];
/* C */ zuint8 zero[4];
} Z_PACKED_STRUCTURE_END Z_TNESHeader;

#if Z_ISA_INTEGRAL_ENDIANNESS == Z_ENDIANNESS_LITTLE
#	define Z_TNES_SIGNATURE 0x53454E54
#else
#	define Z_TNES_SIGNATURE 0x544E4553
#endif

#define Z_TNES_ROM_SIZE_UNIT 8192

#define Z_TNES_MIRRORING_MAPPER_CONTROLLED 0
#define Z_TNES_MIRRORING_HORIZONTAL	   1
#define Z_TNES_MIRRORING_VERTICAL	   2

#define Z_TNES_MAPPER_NROM	 0
#define Z_TNES_MAPPER_SXROM_MMC1 1
#define Z_TNES_MAPPER_PNROM_MMC2 2
#define Z_TNES_MAPPER_TXROM_MMC3 3
#define Z_TNES_MAPPER_FXROM_MMC4 4
#define Z_TNES_MAPPER_EXROM_MMC5 5
#define Z_TNES_MAPPER_UXROM	 6
#define Z_TNES_MAPPER_CNROM	 7
#define Z_TNES_MAPPER_AXROM	 9
#define Z_TNES_MAPPER_FDS	 100

#endif /* Z_formats_storage_medium_image_NES_Game_Pak_TNES_H */
