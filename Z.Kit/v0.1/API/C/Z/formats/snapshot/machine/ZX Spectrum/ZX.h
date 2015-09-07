/* Z Kit C API - formats/hardware snapshot/machine/ZX Spectrum/ZX.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Information contributed by Troels Norgaard.
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.
 ______________________________
/\			       \
\_| Extensions: .zx		|
  | Endianness: Big		|
  | Created by: KGB support BBS	|
  | Used by:	KGB [Amiga]	|
  |   __________________________|_
   \_/__________________________*/

#ifndef __Z_formats_hardware_snapshot_machine_ZX_Spectrum_ZX_H__
#define __Z_formats_hardware_snapshot_machine_ZX_Spectrum_ZX_H__

#include <Z/types/base.h>

Z_DEFINE_STRICT_STRUCTURE_BEGIN
	zuint8	rom_tail[132]; /* Last 132 bytes of ROM */
	zuint8	ram[1024 * 48];
	zuint8	zero_0[132];
	zuint16	settings[5]; /* KGB settings, usually = {10, 10, 4, 1, 1} */
	zuint8	iff;
	zuint8	constants[2]; /* {0, 3} */
	zuint8	color_mode;
	zuint32	zero_1;
	Z16Bit	bc, bc_, de, de_, hl, hl_, ix, iy;
	zuint8	i, r;
	zuint8	zero_2[3];
	zuint8	a_, zero_3;
	zuint8	a,  zero_4;
	zuint8	f_, zero_5;
	zuint8	f;
	zuint16	zero_6, pc;
	zuint16	zero_7, sp;
	zuint16 sound_mode;
	zuint16	halt; /* boolean */
	zint16	im;
	zuint8	zero_8[10];
Z_DEFINE_STRICT_STRUCTURE_END ZZX;

#define Z_ZX_COLOR_MODE_BW    0
#define Z_ZX_COLOR_MODE_COLOR 1

#define Z_ZX_SOUND_MODE_SIMPLE	 0
#define Z_ZX_SOUND_MODE_PITCH	 1
#define Z_ZX_SOUND_MODE_ROM_ONLY 2

#define Z_ZX_IM_0 -1
#define Z_ZX_IM_1  0
#define Z_ZX_IM_2  1

#endif /* __Z_formats_hardware_snapshot_machine_ZX_Spectrum_ZX_H__ */
