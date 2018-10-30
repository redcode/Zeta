/* Z Kit - formats/snapshot/machine/computer/ZX Spectrum/ZX.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Information contributed by Troels Norgaard.
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

.-----------------------------.
| Extensions: zx	      |
| Endianness: Big	      |
| Created by: KGB support BBS |
|    Used by: KGB [Amiga]     |
'----------------------------*/

#ifndef _Z_formats_snapshot_machine_computer_ZX_Spectrum_ZX_H_
#define _Z_formats_snapshot_machine_computer_ZX_Spectrum_ZX_H_

#include <Z/types/base.h>

Z_DEFINE_STRICT_STRUCTURE_BEGIN
	zuint8	rom_tail[132]; /* Last 132 bytes of ROM */
	zuint8	ram[1024 * 48];
	zuint8	zero_0[132];
	zuint16	settings[5]; /* KGB settings, usually = {10, 10, 4, 1, 1} */
	zuint8	iff;
	zuint8	constants[2]; /* {0, 3} */
	zuint8	color_mode;
	zuint32	zero_1;
	Z16Bit	bc, bc_, de, de_, hl, hl_, ix, iy;
	zuint8	i, r;
	zuint8	zero_2[3];
	zuint8	a_, zero_3;
	zuint8	a,  zero_4;
	zuint8	f_, zero_5;
	zuint8	f;
	zuint16	zero_6, pc;
	zuint16	zero_7, sp;
	zuint16 sound_mode;
	zuint16	halt; /* boolean */
	zsint16 im;
	zuint8	zero_8[10];
Z_DEFINE_STRICT_STRUCTURE_END ZZX;

#define Z_ZX_COLOR_MODE_BW    0
#define Z_ZX_COLOR_MODE_COLOR 1

#define Z_ZX_SOUND_MODE_SIMPLE	 0
#define Z_ZX_SOUND_MODE_PITCH	 1
#define Z_ZX_SOUND_MODE_ROM_ONLY 2

#define Z_ZX_IM_0 -1
#define Z_ZX_IM_1  0
#define Z_ZX_IM_2  1

#endif /* _Z_formats_snapshot_machine_computer_ZX_Spectrum_ZX_H_ */
