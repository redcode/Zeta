/* Q API - formats/hardware snapshot/machine/ZX Spectrum/SIT.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2013 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3.

File extensions: sit
     Endianness: Little
     Created by: Pedro M. R. Salas
	Used by: Sinclair [MS-DOS]
 Last known URL: http://www.ugr.es/~pedrom/sinclair.htm */

#ifndef __Q_formats_hardware_snapshot_machine_ZX_Spectrum_SIT_H__
#define __Q_formats_hardware_snapshot_machine_ZX_Spectrum_SIT_H__

#include <Q/types/basics.h>

typedef Q_STRICT_STRUCTURE (

	Q16Bit	bc,  de,  hl,  af,  ix,  iy;
	quint16 sp,  pc;
	quint8	r,   i;
	Q16Bit	bc_, de_, hl_, af_;
	quint8	im;
	quint8	border_color;

	/* complete ROM+RAM memory of a standard ZX Spectrum 48K */
	quint8 memory[1024 * 64];

) QSIT;

#define Q_SIT(p) ((QSIT *)(p))

#endif /* __Q_formats_hardware_snapshot_machine_ZX_Spectrum_SIT_H__ */
