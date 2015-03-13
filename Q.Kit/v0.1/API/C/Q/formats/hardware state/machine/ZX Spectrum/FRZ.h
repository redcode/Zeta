/* Q Kit C API - formats/hardware snapshot/machine/ZX Spectrum/FRZ.h
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

#ifndef __Q_formats_hardware_snapshot_machine_ZX_Spectrum_FRZ_H__
#define __Q_formats_hardware_snapshot_machine_ZX_Spectrum_FRZ_H__

#include <Q/types/base.h>

Q_DEFINE_STRICT_STRUCTURE_BEGIN
	quint8	zero_0;
	quint8	port_7ffd_value;
	Q16Bit	hl_, hl, de_, de, bc_, bc, af_, af;
	quint8	disk_and_t_states[7];
	quint8	r;
	quint16 pc, sp;
	quint8	i;
	quint8	reserved; /* Must be FFh */
	quint8	zero_1;
	quint8	im;
	quint8	zero_2[3];

	struct {Q_8BIT_FIELD(3) (
		quint8 unused1 :5,
		quint8 iff1    :1,
		quint8 unused2 :2
	)} interrupt;

	Q16Bit	iy, ix;

	struct {quint8 bank_5[1024 * 16];
		quint8 bank_2[1024 * 16];
		quint8 bank_0[1024 * 16];
		quint8 bank_1[1024 * 16];
		quint8 bank_3[1024 * 16];
		quint8 bank_4[1024 * 16];
		quint8 bank_6[1024 * 16];
		quint8 bank_7[1024 * 16];
	} ram;
Q_DEFINE_STRICT_STRUCTURE_END QFRZ;

#define Q_FRZ(p) ((QFRZ *)(p))

#endif /* __Q_formats_hardware_snapshot_machine_ZX_Spectrum_FRZ_H__ */
