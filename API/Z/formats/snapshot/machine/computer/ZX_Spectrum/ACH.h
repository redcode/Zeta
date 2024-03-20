/* Zeta API - Z/formats/snapshot/machine/computer/ZX_Spectrum/ACH.h
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.

 _______________________________________________________
|							|
|	 Daft: Public.Snapshot.Computer.ZXSpectrum.ACH	|
|      Author: Witt, Carsten				|
|  Extensions: .ach, .archimedes			|
|  Endianness: Little					|
|    Supports: ZX Spectrum 48K				|
|     Used by: !Speccy (RISC OS)			|
|							|
|  Reference:						|
|  http://rk.nvg.ntnu.no/sinclair/faq/fileform.html	|
|  http://www.zx-modules.de/fileformats/achformat.html	|
|  [MAME sources]/src/mame/machine/spec_snqk.cpp	|
|							|
'======================================================*/

#ifndef Z_formats_snapshot_machine_computer_ZX_Spectrum_ACH_H
#define Z_formats_snapshot_machine_computer_ZX_Spectrum_ACH_H

#include <Z/types/bitwise.h>
#include <Z/hardware/machine/computer/ZX_Spectrum.h>

typedef Z_PACKED_STRUCTURE_BEGIN {
	zuint8 a;	       zuint8 zero_00[  3];
	zuint8 f;	       zuint8 zero_01[  3];
	zuint8 b;	       zuint8 zero_02[  3];
	zuint8 c;	       zuint8 zero_03[  3];
	zuint8 d;	       zuint8 zero_04[  3];
	zuint8 e;	       zuint8 zero_05[  3];
	zuint8 h;	       zuint8 zero_06[  3];
	zuint8 l;	       zuint8 zero_07[  3];
	ZInt16 pc;	       zuint8 zero_08[  6];
	ZInt16 sp;	       zuint8 zero_09[106];
	zuint8 r;	       zuint8 zero_10[  7];
	zuint8 border_color;   zuint8 zero_11[  7];
	zuint8 im;	       zuint8 zero_12[ 25];
	zuint8 i,  iff2;       zuint8 zero_13[ 44];
	zuint8 a_, f_;	       zuint8 zero_14[  2];
	zuint8 b_, c_;	       zuint8 zero_15[  2];
	zuint8 d_, e_, h_, l_;
	ZInt16 ix;	       zuint8 zero_16[  2];
	ZInt16 iy;	       zuint8 zero_17[  2];
	zuint8 memory[Z_ZX_SPECTRUM_48K_SIZE_MEMORY];
} Z_PACKED_STRUCTURE_END Z_ACH;

#endif /* Z_formats_snapshot_machine_computer_ZX_Spectrum_ACH_H */
