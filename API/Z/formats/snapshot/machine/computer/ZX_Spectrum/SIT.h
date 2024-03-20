/* Zeta API - Z/formats/snapshot/machine/computer/ZX_Spectrum/SIT.h
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.

 ____________________________________________________________________
|								     |
|	 Daft: Public.Snapshot.Computer.ZXSpectrum.SIT		     |
|      Author: Rodríguez Salas, Pedro Manuel <pedrom@goliat.ugr.es>  |
|  Extensions: .sit						     |
|  Endianness: Little						     |
|    Supports: ZX Spectrum 48K					     |
|     Used by: Sinclair (MS-DOS)				     |
|	       <http://www.ugr.es/~pedrom/sinclair.htm>		     |
|								     |
|  Reference:							     |
|  http://www.zx-modules.de/fileformats/sitformat.html		     |
|  [MAME sources]/src/mame/machine/spec_snqk.cpp		     |
|								     |
'===================================================================*/

#ifndef Z_formats_snapshot_machine_computer_ZX_Spectrum_SIT_H
#define Z_formats_snapshot_machine_computer_ZX_Spectrum_SIT_H

#include <Z/types/bitwise.h>
#include <Z/hardware/machine/computer/ZX_Spectrum.h>

typedef Z_PACKED_STRUCTURE_BEGIN {
	ZInt16 bc, de, hl, af, ix, iy, sp, pc;
	zuint8 r, i;
	ZInt16 bc_, de_, hl_, af_;
	zuint8 im;
	zuint8 border_color;
	zuint8 memory[Z_ZX_SPECTRUM_48K_SIZE_MEMORY];
} Z_PACKED_STRUCTURE_END Z_SIT;

#endif /* Z_formats_snapshot_machine_computer_ZX_Spectrum_SIT_H */
