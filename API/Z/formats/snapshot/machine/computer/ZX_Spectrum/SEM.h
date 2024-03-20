/* Zeta API - Z/formats/snapshot/machine/computer/ZX_Spectrum/SEM.h
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.

 _______________________________________________________
|							|
|	 Daft: Public.Snapshot.Computer.ZXSpectrum.SEM  |
|      Author: Waschke, Bernd				|
|  Extensions: .sem					|
|  Endianness: Little					|
|    Supports: ZX Spectrum 48K				|
|     Used by: ZX Spectrum-Emulator / SpecEmu (MS-DOS)	|
|							|
|  Reference:						|
|  http://www.zx-modules.de/fileformats/semformat.html	|
|  [MAME sources]/src/mame/machine/spec_snqk.cpp	|
|							|
'======================================================*/

#ifndef Z_formats_snapshot_machine_computer_ZX_Spectrum_SEM_H
#define Z_formats_snapshot_machine_computer_ZX_Spectrum_SEM_H

#include <Z/types/bitwise.h>
#include <Z/hardware/machine/computer/ZX_Spectrum.h>

typedef Z_PACKED_STRUCTURE_BEGIN {
	zuint8 signature_size; /* 5	  */
	zuint8 signature[5];   /* 'SPEC1' */
	zuint8 ram[Z_ZX_SPECTRUM_48K_SIZE_RAM];
	ZInt16 af, bc, de, hl, af_, bc_, de_, hl_, pc, sp, ix, iy;
	zuint8 i,    zero_0;
	zuint8 r,    zero_1;
	zuint8 iff1, zero_2;
	zuint8 iff2, zero_3;
	zuint8 im,   zero_4;
} Z_PACKED_STRUCTURE_END Z_SEMSnapshot;

typedef Z_PACKED_STRUCTURE_BEGIN {
	zuint16 address;
	zuint8	value;
	zuint8	unused;
} Z_PACKED_STRUCTURE_END Z_SEMPoke;

typedef Z_PACKED_STRUCTURE_BEGIN {
	Z_SEMSnapshot snapshot;
	Z_SEMPoke     poke;	    /* Optional */
	zuint16	      speed_factor; /* Optional (only if poke included) */
} Z_PACKED_STRUCTURE_END Z_SEM;

#endif /* Z_formats_snapshot_machine_computer_ZX_Spectrum_SEM_H */
