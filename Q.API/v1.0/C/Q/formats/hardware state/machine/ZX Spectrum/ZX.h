/* Q API - formats/hardware snapshot/machine/ZX Spectrum/ZX.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Information contributed by Troels Norgaard.
Copyright © 2006-2014 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3.

.-----------------------------.
| Extensions: .zx	      |
| Endianness: Big	      |
| Created by: KGB support BBS |
|    Used by: KGB [Amiga]     |
'----------------------------*/

#ifndef __Q_formats_hardware_snapshot_machine_ZX_Spectrum_ZX_H__
#define __Q_formats_hardware_snapshot_machine_ZX_Spectrum_ZX_H__

#include <Q/types/base.h>

Q_DEFINE_STRICT_STRUCTURE (
	quint8	rom_tail[132];	/* Last 132 bytes of ROM */
	quint8	ram[1024 * 48];
	quint8	zero1[132];
	quint16	settings[5];	/* KGB settings, usually = {10, 10, 4, 1, 1} */
	quint8	iff;
	quint8	constants[2];	/* {0, 3} */
	quint8	color_mode;
	quint32	zero2;
	Q16Bit	bc, bc_, de, de_, hl, hl_, ix, iy;
	quint8	i, r;
	quint8	zero3[3];
	quint8	a_, zero4;
	quint8	a,  zero5;
	quint8	f_, zero6;
	quint8	f;
	quint16	zero7, pc;
	quint16	zero8, sp;
	quint16 sound_mode;
	quint16	halt;		/* boolean */
	qint16	im;
	quint8	zero9[10];
) QZX;

#define Q_ZX(p) ((QZX *)(p))

#define Q_ZX_COLOR_MODE_BW		 0
#define Q_ZX_COLOR_MODE_COLOR		 1

#define Q_ZX_SOUND_MODE_SIMPLE		 0
#define Q_ZX_SOUND_MODE_PITCH		 1
#define Q_ZX_SOUND_MODE_ROM_ONLY	 2

#define Q_ZX_IM_0			-1
#define Q_ZX_IM_1			 0
#define Q_ZX_IM_2			 1

#endif /* __Q_formats_hardware_snapshot_machine_ZX_Spectrum_ZX_H__ */
