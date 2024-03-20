/* Zeta API - Z/formats/snapshot/machine/computer/ZX_Spectrum/ZX.h
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Information contributed by Troels Norgaard.
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.

 _________________________________________________________________________
|									  |
|	 Daft: Public.Snapshot.Computer.ZXSpectrum.ZX			  |
|      Author: Noerdergard, Troels					  |
|  Extensions: .zx							  |
|  Endianness: Big							  |
|    Supports: ZX Spectrum 48K						  |
|     Used by: KGB Spectrum Emulator (AmigaOS)				  |
|	       <http://www.cybercity.dk/users/ccc14241/home.html>	  |
|									  |
|  Reference:								  |
|  http://rk.nvg.ntnu.no/sinclair/faq/fileform.html			  |
|  [MAME sources]/src/mame/machine/spec_snqk.cpp			  |
|									  |
|  Thanks to Troels Norgaard for sharing the description of this format.  |
|									  |
'========================================================================*/

#ifndef Z_formats_snapshot_machine_computer_ZX_Spectrum_ZX_H
#define Z_formats_snapshot_machine_computer_ZX_Spectrum_ZX_H

#include <Z/types/bitwise.h>
#include <Z/hardware/machine/computer/ZX_Spectrum.h>

typedef Z_PACKED_STRUCTURE_BEGIN {
	zuint8	rom_tail[132]; /* last 132 bytes of ROM			    */
	zuint8	ram[Z_ZX_SPECTRUM_48K_SIZE_RAM];
	zuint8	zero_0[132];
	zuint16	settings[5];   /* KGB settings, usually = {10, 10, 4, 1, 1} */
	zuint8	iff;	       /* IFF1 and IFF2				    */
	zuint8	constants[2];  /* must be {0, 3}			    */
	zuint8	color_mode;
	zuint32	zero_1;
	ZInt16	bc, bc_, de, de_, hl, hl_, ix, iy;
	zuint8	i, r;
	zuint16	zero_2;
	zuint8	zero_3, a_;
	zuint8	zero_4, a;
	zuint8	zero_5, f_;
	zuint8	zero_6, f;
	ZInt16	zero_7, pc;
	ZInt16	zero_8, sp;
	zuint16 sound_mode;
	zuint8  zero_9;
	zuint8	halt_line; /* boolean */
	zsint16 im;
	zuint8	zero_10[10];
} Z_PACKED_STRUCTURE_END Z_ZX;

#define Z_ZX_COLOR_MODE_BW	 0
#define Z_ZX_COLOR_MODE_COLOR	 1

#define Z_ZX_SOUND_MODE_SIMPLE	 0
#define Z_ZX_SOUND_MODE_PITCH	 1
#define Z_ZX_SOUND_MODE_ROM_ONLY 2

#define Z_ZX_IM_0		-1
#define Z_ZX_IM_1		 0
#define Z_ZX_IM_2		 1

#endif /* Z_formats_snapshot_machine_computer_ZX_Spectrum_ZX_H */
