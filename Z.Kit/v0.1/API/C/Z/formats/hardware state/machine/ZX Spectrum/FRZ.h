/* Z Kit C API - formats/hardware snapshot/machine/ZX Spectrum/FRZ.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © Dmitriy Zhivilov.
Copyright © Ian Greenway.
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.
 _______________________________
/\				\
\_| Extensions: .frz		 |
  | Endianness: Big		 |
  | Created by: CodeBusters	 |
  | Used by:	CBSpeccy [Amiga] |
  |   ___________________________|_
   \_/___________________________*/

#ifndef __Z_formats_hardware_snapshot_machine_ZX_Spectrum_FRZ_H__
#define __Z_formats_hardware_snapshot_machine_ZX_Spectrum_FRZ_H__

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

	struct {Z_8BIT_FIELD(3) (
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

#define Z_FRZ(p) ((ZFRZ *)(p))

#endif /* __Z_formats_hardware_snapshot_machine_ZX_Spectrum_FRZ_H__ */
