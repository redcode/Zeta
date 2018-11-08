/* Z Kit - formats/snapshot/machine/computer/ZX Spectrum/SIT.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
-------------------------------------------------------------------------------
This library is  free software: you can redistribute it  and/or modify it under
the terms  of the GNU  Lesser General Public License  as published by  the Free
Software Foundation, either  version 3 of the License, or  (at your option) any
later version.

This library is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

You should have received  a copy of the GNU Lesser General Public License along
with this library. If not, see <http://www.gnu.org/licenses/>.
-------------------------------------------------------------------------------

.-------------------------------------------.
| Extensions: sit			    |
| Endianness: Little			    |
| Created by: Rodríguez Salas, Pedro Manuel |
|    Used by: SINCLAIR [DOS]		    |
|					    |
| http://www.ugr.es/~pedrom/sinclair.htm    |
'------------------------------------------*/

#ifndef _Z_formats_snapshot_machine_computer_ZX_Spectrum_SIT_H_
#define _Z_formats_snapshot_machine_computer_ZX_Spectrum_SIT_H_

#include <Z/types/base.h>

Z_DEFINE_STRICT_STRUCTURE_BEGIN
	Z16Bit	bc,  de,  hl,  af,  ix,  iy;
	zuint16 sp,  pc;
	zuint8	r,   i;
	Z16Bit	bc_, de_, hl_, af_;
	zuint8	im;
	zuint8	border_color;

	/* complete ROM+RAM memory of a standard ZX Spectrum 48K */
	zuint8 memory[1024 * 64];
Z_DEFINE_STRICT_STRUCTURE_END ZSIT;

#endif /* _Z_formats_snapshot_machine_computer_ZX_Spectrum_SIT_H_ */
