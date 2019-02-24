/* Z Kit - formats/snapshot/machine/computer/ZX Spectrum/PRG.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2019 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.

.-----------------------------------------------------------.
| Extensions: prg					    |
| Endianness: Little					    |
|   Supports: 48K					    |
|    Used by: Spectrum Emulator, The (MS-DOS)		    |
|	      <http://code.google.com/p/specem>		    |
|     Author: Phair, Kevin J.				    |
|  Reference: [MAME sources]/src/mame/machine/spec_snqk.cpp |
'----------------------------------------------------------*/

#ifndef Z_formats_snapshot_machine_computer_ZX_Spectrum_PRG_H
#define Z_formats_snapshot_machine_computer_ZX_Spectrum_PRG_H

#include <Z/types/bitwise.h>

Z_DEFINE_PACKED_STRUCTURE_BEGIN {
	zuint8	file_type;	   /* 05h		*/
	zuint8	program_name[10];  /* 20h, name[8], 20h */
	zuint16	file_sector_count; /* BIG ENDIAN	*/
	zuint8	file_track_index;
	zuint8	file_sector_index;
	zuint8	sector_allocation_bitmap[195];
	zuint8	zero_0[10];
	Z16Bit	iy, ix, de_, bc_, hl_, af_, de, bc, hl;
	zuint8	i_junk;
	zuint8	i;
	zuint16	sp;
	zuint8	zero_1[14];
	zuint8	ram[49152];
} Z_DEFINE_PACKED_STRUCTURE_END (ZPRG);

#endif /* Z_formats_snapshot_machine_computer_ZX_Spectrum_PRG_H */
