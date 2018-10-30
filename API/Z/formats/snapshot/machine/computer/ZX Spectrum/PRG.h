/* Z Kit - formats/snapshot/machine/computer/ZX Spectrum/PRG.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) Kevin Phair.
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.

This library  is free software: you  can redistribute it and/or  modify it under
the terms  of the  GNU Lesser General  Public License as  published by  the Free
Software Foundation,  either version 3 of  the License, or (at  your option) any
later version.

This library is distributed in the hope  that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty  of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

You should have received  a copy of the GNU Lesser  General Public License along
with this library. If not, see <http://www.gnu.org/licenses/>.

.-------------------------------------.
| Extensions: prg		      |
| Endianness: Little		      |
| Created by: Phair, Kevin	      |
|    Used by: Spectrum Emulator [DOS] |
|				      |
| http://code.google.com/p/specem     |
'------------------------------------*/

#ifndef _Z_formats_snapshot_machine_computer_ZX_Spectrum_PRG_H_
#define _Z_formats_snapshot_machine_computer_ZX_Spectrum_PRG_H_

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

#endif /* _Z_formats_snapshot_machine_computer_ZX_Spectrum_PRG_H_ */
