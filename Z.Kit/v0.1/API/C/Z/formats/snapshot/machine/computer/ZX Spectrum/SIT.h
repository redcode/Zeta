/* Z Kit C API - formats/snapshot/machine/computer/ZX Spectrum/SIT.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.
 ___________________________________________
/\					    \
\_| Extensions: .sit			     |
  | Endianness: Little			     |
  | Created by: Pedro Manuel Rodríguez Salas |
  |    Used by: SINCLAIR [DOS]		     |
  |					     |
  | http://www.ugr.es/~pedrom/sinclair.htm   |
  |   _______________________________________|_
   \_/_______________________________________*/

#ifndef __Z_formats_snapshot_machine_computer_ZX_Spectrum_SIT_H__
#define __Z_formats_snapshot_machine_computer_ZX_Spectrum_SIT_H__

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

#endif /* __Z_formats_snapshot_machine_computer_ZX_Spectrum_SIT_H__ */
