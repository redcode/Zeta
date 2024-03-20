/* Zeta API - Z/formats/snapshot/machine/computer/ZX_Spectrum/SNP.h
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.

 ___________________________________________________________________
|								    |
|	 Daft: Public.Snapshot.Computer.ZXSpectrum.SNP		    |
|     Authors: Garabik, Radovan <garabik@melkor.dnp.fmph.uniba.sk>  |
|	       Salanci, Lubomir <salanci@center.fmph.uniba.sk>	    |
|  Extensions: .snp						    |
|  Endianness: Little						    |
|    Supports: ZX Spectrum 48K					    |
|     Used by: Nuclear ZX (MS-DOS)				    |
|	       <http://korpus.juls.savba.sk/~garabik/old/zx.html>   |
|								    |
|  Reference:							    |
|  http://www.zx-modules.de/fileformats/snpformat.html		    |
|  [MAME sources]/src/mame/machine/spec_snqk.cpp		    |
|								    |
'==================================================================*/

#ifndef Z_formats_snapshot_machine_computer_ZX_Spectrum_SNP_H
#define Z_formats_snapshot_machine_computer_ZX_Spectrum_SNP_H

#include <Z/types/bitwise.h>
#include <Z/hardware/machine/computer/ZX_Spectrum.h>

typedef Z_PACKED_STRUCTURE_BEGIN {
	zuint8 ram[Z_ZX_SPECTRUM_48K_SIZE_RAM];
	ZInt16 af;
	zuint8 border_color;
	zuint8 zero;
	ZInt16 bc, de, hl, pc, sp, ix, iy;
	zuint8 not_iff2; /* Not used (must be 0?) */
	zuint8 iff1;
	zuint8 im;
	zuint8 r, i;
	ZInt16 af_, bc_, de_, hl_;
} Z_PACKED_STRUCTURE_END Z_SNP;

#endif /* Z_formats_snapshot_machine_computer_ZX_Spectrum_SNP_H */
