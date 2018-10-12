/* Z Kit - formats/snapshot/machine/computer/ZX Spectrum/FRZ.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) Dmitriy Zhivilov.
Copyright (C) Ian Greenway.
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.

.------------------------------.
| Extensions: frz	       |
| Endianness: Big	       |
| Created by: CodeBusters      |
|    Used by: CBSpeccy [Amiga] |
'-----------------------------*/

#ifndef _Z_formats_snapshot_machine_computer_ZX_Spectrum_FRZ_H_
#define _Z_formats_snapshot_machine_computer_ZX_Spectrum_FRZ_H_

#include <Z/types/base.h>

Z_DEFINE_STRICT_STRUCTURE_BEGIN
	zuint8	zero_0;
	zuint8	port_7ffd_value;
	Z16Bit	hl_, hl, de_, de, bc_, bc, af_, af;
	zuint8	disk_and_t_states[7];
	zuint8	r;
	zuint16 pc, sp;
	zuint8	i;
	zuint8	reserved; /* Must be FFh */
	zuint8	zero_1;
	zuint8	im;
	zuint8	zero_2[3];

	struct {Z_BIT_FIELD(8, 3) (
		zuint8 unused1 :5,
		zuint8 iff1    :1,
		zuint8 unused2 :2
	)} interrupt;

	Z16Bit	iy, ix;

	struct {zuint8 bank_5[1024 * 16];
		zuint8 bank_2[1024 * 16];
		zuint8 bank_0[1024 * 16];
		zuint8 bank_1[1024 * 16];
		zuint8 bank_3[1024 * 16];
		zuint8 bank_4[1024 * 16];
		zuint8 bank_6[1024 * 16];
		zuint8 bank_7[1024 * 16];
	} ram;
Z_DEFINE_STRICT_STRUCTURE_END ZFRZ;

#endif /* _Z_formats_snapshot_machine_computer_ZX_Spectrum_FRZ_H_ */
