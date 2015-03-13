/* Q Kit C API - formats/hardware snapshot/machine/ZX Spectrum/ACH.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.
 ________________________________
/\				 \
\_| Extensions: .ach, .archimedes |
  | Endianness: Little		  |
  | Created by: Carsten Witt	  |
  | Used by:	!Speccy [RISC OS] |
  |   ____________________________|_
   \_/____________________________*/

#ifndef __Q_formats_hardware_snapshot_machine_ZX_Spectrum_ACH_H__
#define __Q_formats_hardware_snapshot_machine_ZX_Spectrum_ACH_H__

#include <Q/types/base.h>

Q_DEFINE_STRICT_STRUCTURE_BEGIN
	quint8	a,	      zero_00[ 3];
	quint8	f,	      zero_01[ 3];
	quint8	b,	      zero_02[ 3];
	quint8	c,	      zero_03[ 3];
	quint8	d,	      zero_04[ 3];
	quint8	e,	      zero_05[ 3];
	quint8	h,	      zero_06[ 3];
	quint8	l,	      zero_07[ 3];
	quint16 pc,	      zero_08[ 3];
	quint16 sp,	      zero_09[53];
	quint8	r,	      zero_10[ 7];
	quint8	border_color, zero_11[ 7];
	quint8	im,	      zero_12[25];
	quint8	i,  iff2,     zero_13[44];
	quint8	a_, f_,	      zero_14[ 2];
	quint8	b_, c_,	      zero_15[ 2];
	quint8	d_, e_;
	quint8	h_, l_;
	Q16Bit	ix,	      zero_16;
	Q16Bit	iy,	      zero_17;
	quint8	memory[1024 * 64]; /* Complete ZX Spectrum 48K memory */
Q_DEFINE_STRICT_STRUCTURE_END QACH;

#define Q_ACH(p) ((QACH *)(p))

#endif /* __Q_formats_hardware_snapshot_machine_ZX_Spectrum_ACH_H__ */
