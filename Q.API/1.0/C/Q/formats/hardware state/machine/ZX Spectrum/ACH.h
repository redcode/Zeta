/* Q API - formats/hardware snapshot/machine/ZX Spectrum/ACH.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2013 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3.

.-------------------------------.
| Extensions: .ach, .archimedes |
| Endianness: Little		|
| Created by: Carsten Witt	|
|    Used by: !Speccy [RISC OS] |
'------------------------------*/

#ifndef __Q_formats_hardware_snapshot_machine_ZX_Spectrum_ACH_H__
#define __Q_formats_hardware_snapshot_machine_ZX_Spectrum_ACH_H__

#include <Q/types/basics.h>

Q_DEFINE_STRICT_STRUCTURE (
	quint8	a,	      zero01[ 3];
	quint8	f,	      zero02[ 3];
	quint8	b,	      zero03[ 3];
	quint8	c,	      zero04[ 3];
	quint8	d,	      zero05[ 3];
	quint8	e,	      zero06[ 3];
	quint8	h,	      zero07[ 3];
	quint8	l,	      zero08[ 3];
	quint16 pc,	      zero09[ 3];
	quint16 sp,	      zero10[53];
	quint8	r,	      zero11[ 7];
	quint8	border_color, zero12[ 7];
	quint8	im,	      zero13[25];
	quint8	i,  iff2,     zero14[44];
	quint8	a_, f_,	      zero15[ 2];
	quint8	b_, c_,	      zero16[ 2];
	quint8	d_, e_;
	quint8	h_, l_;
	Q16Bit	ix,	      zero17;
	Q16Bit	iy,	      zero18;
	quint8	memory[1024 * 64]; /* Complete ZX Spectrum 48K memory */
) QACH;

#define Q_ACH(p) ((QACH *)(p))

#endif /* __Q_formats_hardware_snapshot_machine_ZX_Spectrum_ACH_H__ */
