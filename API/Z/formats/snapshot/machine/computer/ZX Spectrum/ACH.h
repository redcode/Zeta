/* Z Kit - formats/snapshot/machine/computer/ZX Spectrum/ACH.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.

.-------------------------------------------------------------------.
| Extensions: ach, archimedes					    |
| Endianness: Little						    |
|   Supports: 48K						    |
|    Used by: !Speccy (RISC OS)					    |
|     Author: Witt, Carsten					    |
|  Reference: <http://rk.nvg.ntnu.no/sinclair/faq/fileform.html>    |
|	      <http://www.zx-modules.de/fileformats/achformat.html> |
|	      [MAME sources]/src/mame/machine/spec_snqk.cpp	    |
'------------------------------------------------------------------*/

#ifndef _Z_formats_snapshot_machine_computer_ZX_Spectrum_ACH_H_
#define _Z_formats_snapshot_machine_computer_ZX_Spectrum_ACH_H_

#include <Z/types/bitwise.h>

Z_DEFINE_STRICT_STRUCTURE_BEGIN {
	zuint8	a;	       zuint8 zero_00[	3];
	zuint8	f;	       zuint8 zero_01[	3];
	zuint8	b;	       zuint8 zero_02[	3];
	zuint8	c;	       zuint8 zero_03[	3];
	zuint8	d;	       zuint8 zero_04[	3];
	zuint8	e;	       zuint8 zero_05[	3];
	zuint8	h;	       zuint8 zero_06[	3];
	zuint8	l;	       zuint8 zero_07[	3];
	zuint16 pc;	       zuint8 zero_08[	6];
	zuint16 sp,	       zuint8 zero_09[106];
	zuint8	r;	       zuint8 zero_10[	7];
	zuint8	border_color;  zuint8 zero_11[	7];
	zuint8	im;	       zuint8 zero_12[ 25];
	zuint8	i,  iff2;      zuint8 zero_13[ 44];
	zuint8	a_, f_;	       zuint8 zero_14[	2];
	zuint8	b_, c_;	       zuint8 zero_15[	2];
	zuint8	d_, e_,
	zuint8	h_, l_;
	Z16Bit	ix;	       zuint8 zero_16[	2];
	Z16Bit	iy;	       zuint8 zero_17[	2];
	zuint8	memory[65536];
} Z_DEFINE_STRICT_STRUCTURE_END (ZACH);

#endif /* _Z_formats_snapshot_machine_computer_ZX_Spectrum_ACH_H_ */
