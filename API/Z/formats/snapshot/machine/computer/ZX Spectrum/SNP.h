/* Z Kit - formats/snapshot/machine/computer/ZX Spectrum/SNP.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.

This library is free software: you can redistribute it and/or modify it
under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this library.  If not, see <http://www.gnu.org/licenses/>.

.--------------------------------------------------.
| Extensions: snp				   |
| Endianness: Little				   |
| Created by: Garabik, Radovan - Salanci, Lubomir  |
|    Used by: Nuclear ZX [DOS]			   |
|						   |
| http://korpus.juls.savba.sk/~garabik/old/zx.html |
'-------------------------------------------------*/

#ifndef _Z_formats_snapshot_machine_computer_ZX_Spectrum_SNP_H_
#define _Z_formats_snapshot_machine_computer_ZX_Spectrum_SNP_H_

#include <Z/types/base.h>

Z_DEFINE_STRICT_STRUCTURE_BEGIN
	zuint8	ram[1024 * 48];
	Z16Bit	af;
	zuint8	border_color;
	zuint8	reserved;
	Z16Bit	bc, de, hl;
	zuint16	pc, sp;
	Z16Bit	ix, iy;
	zuint8	iff2; /* not used actually */
	zuint8	iff1;
	zuint8	im;
	zuint8	r, i;
	Z16Bit	af_, bc_, de_, hl_;
Z_DEFINE_STRICT_STRUCTURE_END ZSNP;

#endif /* _Z_formats_snapshot_machine_computer_ZX_Spectrum_SNP_H_ */
