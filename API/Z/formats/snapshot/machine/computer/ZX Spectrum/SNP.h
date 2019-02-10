/* Z Kit - formats/snapshot/machine/computer/ZX Spectrum/SNP.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2019 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.

.-------------------------------------------------------------------.
| Extensions: snp						    |
| Endianness: Little						    |
|   Supports: 48K						    |
|    Used by: Nuclear ZX (MS-DOS)				    |
|	      <http://korpus.juls.savba.sk/~garabik/old/zx.html>    |
|    Authors: Garabik, Radovan <garabik@melkor.dnp.fmph.uniba.sk>   |
|	      Salanci, Lubomir <salanci@center.fmph.uniba.sk>	    |
|  Reference: <http://www.zx-modules.de/fileformats/snpformat.html> |
|	      [MAME sources]/src/mame/machine/spec_snqk.cpp	    |
'------------------------------------------------------------------*/

#ifndef Z_formats_snapshot_machine_computer_ZX_Spectrum_SNP_H_
#define Z_formats_snapshot_machine_computer_ZX_Spectrum_SNP_H_

#include <Z/types/bitwise.h>

Z_DEFINE_PACKED_STRUCTURE_BEGIN {
	zuint8	ram[49152];
	Z16Bit	af;
	zuint8	border_color;
	zuint8	zero;
	Z16Bit	bc, de, hl;
	zuint16	pc, sp;
	Z16Bit	ix, iy;
	zuint8	not_iff2; /* not used */
	zuint8	not_iff1;
	zuint8	im;
	zuint8	r, i;
	Z16Bit	af_, bc_, de_, hl_;
} Z_DEFINE_PACKED_STRUCTURE_END (ZSNP);

#endif /* Z_formats_snapshot_machine_computer_ZX_Spectrum_SNP_H_ */
