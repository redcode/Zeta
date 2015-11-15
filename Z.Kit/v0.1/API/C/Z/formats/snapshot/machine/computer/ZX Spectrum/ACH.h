/* Z Kit C API - formats/snapshot/machine/computer/ZX Spectrum/ACH.h
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
  |    Used by: !Speccy [RISC OS] |
  |   ____________________________|_
   \_/____________________________*/

#ifndef __Z_formats_snapshot_machine_computer_ZX_Spectrum_ACH_H__
#define __Z_formats_snapshot_machine_computer_ZX_Spectrum_ACH_H__

#include <Z/types/base.h>

Z_DEFINE_STRICT_STRUCTURE_BEGIN
	zuint8	a,	      zero_00[ 3];
	zuint8	f,	      zero_01[ 3];
	zuint8	b,	      zero_02[ 3];
	zuint8	c,	      zero_03[ 3];
	zuint8	d,	      zero_04[ 3];
	zuint8	e,	      zero_05[ 3];
	zuint8	h,	      zero_06[ 3];
	zuint8	l,	      zero_07[ 3];
	zuint16 pc,	      zero_08[ 3];
	zuint16 sp,	      zero_09[53];
	zuint8	r,	      zero_10[ 7];
	zuint8	border_color, zero_11[ 7];
	zuint8	im,	      zero_12[25];
	zuint8	i,  iff2,     zero_13[44];
	zuint8	a_, f_,	      zero_14[ 2];
	zuint8	b_, c_,	      zero_15[ 2];
	zuint8	d_, e_;
	zuint8	h_, l_;
	Z16Bit	ix,	      zero_16;
	Z16Bit	iy,	      zero_17;
	zuint8	memory[1024 * 64]; /* Complete ZX Spectrum 48K memory */
Z_DEFINE_STRICT_STRUCTURE_END ZACH;

#endif /* __Z_formats_snapshot_machine_computer_ZX_Spectrum_ACH_H__ */
