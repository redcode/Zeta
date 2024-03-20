/* Zeta API - Z/formats/snapshot/machine/computer/ZX_Spectrum/+D.h
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.

 _________________________________________________________
|							  |
|	 Daft: Public.Snapshot.Computer.ZXSpectrum.PlusD  |
|      Author: Samir, Ribic				  |
|  Extensions: .plusd					  |
|  Endianness: Little?					  |
|    Supports:						  |
|     Used by:						  |
|							  |
|  Reference:						  |
|							  |
'========================================================*/

#ifndef Z_formats_snapshot_machine_computer_ZX_Spectrum_PlusD_H
#define Z_formats_snapshot_machine_computer_ZX_Spectrum_PlusD_H

#include <Z/types/bitwise.h>
#include <Z/hardware/machine/computer/ZX_Spectrum.h>

typedef Z_PACKED_STRUCTURE_BEGIN {
	ZInt16 iy, ix, de_, bc_, hl_, af_, de, bc, hl;
	zuint8 i_junk;
	zuint8 i;
	ZInt16 sp;
} Z_PACKED_STRUCTURE_END Z_PlusDCPU;

typedef Z_PACKED_STRUCTURE_BEGIN {
	Z_PlusDCPU cpu;
	zuint8	   ram[Z_ZX_SPECTRUM_48K_SIZE_RAM];
} Z_PACKED_STRUCTURE_END Z_PlusDv48K;

typedef Z_PACKED_STRUCTURE_BEGIN {
	Z_PlusDCPU		       cpu;
	Z_ZXSpectrumPlus128KBankSwitch bank_switch;
	zuint8			       ram[Z_ZX_SPECTRUM_PLUS_128K_SIZE_RAM];
} Z_PACKED_STRUCTURE_END Z_PlusDv128K;

#endif /* Z_formats_snapshot_machine_computer_ZX_Spectrum_PlusD_H */
