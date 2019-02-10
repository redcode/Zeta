/* Z Kit - formats/snapshot/machine/computer/ZX Spectrum/ZX.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Information contributed by Troels Norgaard.
Copyright (C) 2006-2019 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.

.-----------------------------------------------------------------------.
| Extensions: zx							|
| Endianness: Big							|
|   Supports: 48K							|
|    Used by: KGB (AmigaOS)						|
|	      <http://www.cybercity.dk/users/ccc14241/home.html>	|
|     Author: Noerdergard, Troels					|
|  Reference: <http://rk.nvg.ntnu.no/sinclair/faq/fileform.html>	|
|	      [MAME sources]/src/mame/machine/spec_snqk.cpp		|
|									|
| Thanks to Troels Norgaard for sharing the description of this format. |
'----------------------------------------------------------------------*/

#ifndef Z_formats_snapshot_machine_computer_ZX_Spectrum_ZX_H_
#define Z_formats_snapshot_machine_computer_ZX_Spectrum_ZX_H_

#include <Z/types/bitwise.h>

Z_DEFINE_PACKED_STRUCTURE_BEGIN {
	zuint8	rom_tail[132]; /* last 132 bytes of ROM			    */
	zuint8	ram[49152];
	zuint8	zero_0[132];
	zuint16	settings[5];   /* KGB settings, usually = {10, 10, 4, 1, 1} */
	zuint8	iff;	       /* IFF1 and IFF2				    */
	zuint8	constants[2];  /* must be {0, 3}			    */
	zuint8	color_mode;
	zuint8	zero_1[4];
	Z16Bit	bc, bc_, de, de_, hl, hl_, ix, iy;
	zuint8	i;
	zuint8	r,  zero_2[3];
	zuint8	a_, zero_3;
	zuint8	a,  zero_4;
	zuint8	f_, zero_5;
	zuint8	f,  zero_6[2];
	zuint16	pc, zero_7;
	zuint16	sp;
	zuint16 sound_mode;
	zuint16	halt; /* boolean */
	zsint16 im;
	zuint8	zero_8[10];
} Z_DEFINE_PACKED_STRUCTURE_END (ZZX);

#define Z_ZX_COLOR_MODE_BW	 0
#define Z_ZX_COLOR_MODE_COLOR	 1

#define Z_ZX_SOUND_MODE_SIMPLE	 0
#define Z_ZX_SOUND_MODE_PITCH	 1
#define Z_ZX_SOUND_MODE_ROM_ONLY 2

#define Z_ZX_IM_0		-1
#define Z_ZX_IM_1		 0
#define Z_ZX_IM_2		 1

#endif /* Z_formats_snapshot_machine_computer_ZX_Spectrum_ZX_H_ */
