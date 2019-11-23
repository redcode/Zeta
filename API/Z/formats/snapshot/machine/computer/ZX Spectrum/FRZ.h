/* Z Kit - formats/snapshot/machine/computer/ZX Spectrum/FRZ.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//__/__| Kit
Copyright (C) 2006-2020 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.

.---------------------------------------------------------------.
| Extensions: .frz						|
| Endianness: Big						|
|   Supports: 128K						|
|    Used by: CBSpeccy (AmigaOS)				|
|	      <http://www.neworder.spb.ru/cbspeccy/>		|
|    Authors: Code Busters (Iwamoto, Max - alias Rst7)		|
|  Reference: [MAME sources]/src/mame/machine/spec_snqk.cpp	|
|								|
| Special thanks to Dmitriy Zhivilov and Ian Greenway, who      |
| reverse-engineered and shared the description of this format. |
'--------------------------------------------------------------*/

#ifndef Z_formats_snapshot_machine_computer_ZX_Spectrum_FRZ_H
#define Z_formats_snapshot_machine_computer_ZX_Spectrum_FRZ_H

#include <Z/types/bitwise.h>

Z_DEFINE_PACKED_STRUCTURE_BEGIN {
	zuint8	zero_0;
	zuint8	port_7ffd_data;
	Z16Bit	hl_, hl, de_, de, bc_, bc, af_, af;
	zuint8	disk_and_t_states[7];
	zuint8	r;
	zuint16 pc, sp;
	zuint8	i;
	zuint8	reserved; /* must be FFh */
	zuint8	zero_1;
	zuint8	im;
	zuint8	zero_2[3];

	struct {Z_BIT_FIELD(8, 3) (
		zuint8 unused_1 :5,
		zuint8 iff1	:1,
		zuint8 unused_0 :2
	)} interrupt;

	Z16Bit	iy, ix;

	struct {zuint8 bank_5[16384];
		zuint8 bank_2[16384];
		zuint8 bank_0[16384];
		zuint8 bank_1[16384];
		zuint8 bank_3[16384];
		zuint8 bank_4[16384];
		zuint8 bank_6[16384];
		zuint8 bank_7[16384];
	} ram;
} Z_DEFINE_PACKED_STRUCTURE_END (ZFRZ);

#endif /* Z_formats_snapshot_machine_computer_ZX_Spectrum_FRZ_H */
