/* Z Kit C API - formats/snapshot/machine/computer/ZX Spectrum/PRG.h
 _____ 	_______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_|
Copyright © Kevin Phair.
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.

.-------------------------------------.
| Extensions: prg		      |
| Endianness: Little		      |
| Created by: Kevin Phair	      |
|    Used by: Spectrum Emulator [DOS] |
|				      |
| http://code.google.com/p/specem     |
'------------------------------------*/

#ifndef __Z_formats_snapshot_machine_computer_ZX_Spectrum_PRG_H__
#define __Z_formats_snapshot_machine_computer_ZX_Spectrum_PRG_H__

#include <Z/types/base.h>

Z_DEFINE_STRICT_STRUCTURE (
	zuint8	file_type;	   /* Always 05h */
	zuint8	program_name[10];  /* 20h, name[], 20h */
	zuint16	file_sector_count; /* BIG ENDIAN */
	zuint8	file_first_sector_track_index;
	zuint8	file_first_sector_sector_index;
	zuint8	sector_allocation_bitmap[195];
	/* ..... TO DO */
) ZPRG;

#endif /* __Z_formats_snapshot_machine_computer_ZX_Spectrum_PRG_H__ */
