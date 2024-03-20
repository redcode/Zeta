/* Zeta API - Z/formats/snapshot/machine/computer/ZX_Spectrum/FRZ.h
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.

 _________________________________________________________________
|								  |
|	 Daft: Public.Snapshot.Computer.ZXSpectrum.FRZ		  |
|     Authors: Code Busters (Iwamoto, Max - alias Rst7)		  |
|  Extensions: .frz						  |
|  Endianness: Big						  |
|    Supports: ZX Spectrum + 128K				  |
|     Used by: CBSpeccy (AmigaOS)				  |
|	       <http://www.neworder.spb.ru/cbspeccy/>		  |
|								  |
|  Reference:							  |
|  [MAME sources]/src/mame/machine/spec_snqk.cpp		  |
|								  |
|  Special thanks to Dmitriy Zhivilov and Ian Greenway, who       |
|  reverse-engineered and shared the description of this format.  |
|								  |
'================================================================*/

#ifndef Z_formats_snapshot_machine_computer_ZX_Spectrum_FRZ_H
#define Z_formats_snapshot_machine_computer_ZX_Spectrum_FRZ_H

#include <Z/types/bitwise.h>
#include <Z/hardware/machine/computer/ZX_Spectrum.h>

typedef Z_PACKED_STRUCTURE_BEGIN {
	zuint8 zero_0;

	Z_ZXSpectrumPlus128KBankSwitch bank_switch;

	ZInt16 hl_, hl, de_, de, bc_, bc, af_, af;
	zuint8 disk_and_t_states[7];
	zuint8 r;
	ZInt16 pc, sp;
	zuint8 i;
	zuint8 reserved; /* must be FFh */
	zuint8 zero_1;
	zuint8 im;
	zuint8 zero_2[3];

	union {	zuint8 value;
		struct {Z_BIT_FIELD_MEMBERS(8, 3) (
			zuint8 unused_1 :5,
			zuint8 iff1	:1,
			zuint8 unused_0 :2
		)} fields;
	} interrupt;

	ZInt16 iy, ix;

	zuint8 ram_bank_5[Z_ZX_SPECTRUM_PLUS_128K_SIZE_BANK];
	zuint8 ram_bank_2[Z_ZX_SPECTRUM_PLUS_128K_SIZE_BANK];
	zuint8 ram_bank_0[Z_ZX_SPECTRUM_PLUS_128K_SIZE_BANK];
	zuint8 ram_bank_1[Z_ZX_SPECTRUM_PLUS_128K_SIZE_BANK];
	zuint8 ram_bank_3[Z_ZX_SPECTRUM_PLUS_128K_SIZE_BANK];
	zuint8 ram_bank_4[Z_ZX_SPECTRUM_PLUS_128K_SIZE_BANK];
	zuint8 ram_bank_6[Z_ZX_SPECTRUM_PLUS_128K_SIZE_BANK];
	zuint8 ram_bank_7[Z_ZX_SPECTRUM_PLUS_128K_SIZE_BANK];
} Z_PACKED_STRUCTURE_END Z_FRZ;

#endif /* Z_formats_snapshot_machine_computer_ZX_Spectrum_FRZ_H */
