/* Zeta API - Z/formats/snapshot/machine/computer/ZX_Spectrum/SP.h
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.

 ______________________________________________________________________________
|									       |
|	 Daft: Public.Snapshot.Computer.ZXSpectrum.SP			       |
|      Author: Gimeno Fortea, Pedro <parigalo@formauri.es>		       |
|  Extensions: .sp							       |
|  Endianness: Little							       |
|    Supports: ZX Spectrum 48K						       |
|     Used by: Spectrum / VGASpec (MS-DOS)				       |
|	       <http://www.formauri.es/personal/pgimeno/spec/spec.html>	       |
|									       |
|  Reference:								       |
|  http://www.zx-modules.de/fileformats/spformat.html			       |
|  [MAME sources]/src/mame/machine/spec_snqk.cpp			       |
|									       |
|  From the sources of MESS:						       |
|									       |
|  There are two kinds of .sp files: 'old' and 'new'.			       |
|									       |
|  The old version is always 49184 bytes long and is created by a leaked copy  |
|  of the VGASpec emulator.						       |
|									       |
|  Subsequently Pedro Gimeno (the author of VGASpec) renamed it to 'Spectrum'  |
|  (but it's colloquially known as the 'Spanish Spectrum emulator') and added  |
|  a header in the snapshot to break backward compatibility: the new format    |
|  supports both 16K and 48K images and it's 16422 or 49190 bytes long.	       |
|									       |
'=============================================================================*/

#ifndef Z_formats_snapshot_machine_computer_ZX_Spectrum_SP_H
#define Z_formats_snapshot_machine_computer_ZX_Spectrum_SP_H

#include <Z/types/bitwise.h>
#include <Z/hardware/machine/computer/ZX_Spectrum.h>

typedef Z_PACKED_STRUCTURE_BEGIN {
	ZInt16	signature;	  /* ['S', 'P']	    */
	zuint16 ram_size;	  /* 16384 or 49152 */
	zuint16 ram_load_address; /* 16384	    */
} Z_PACKED_STRUCTURE_END Z_SPHeader;

typedef Z_PACKED_STRUCTURE_BEGIN {
	ZInt16	bc, de, hl, af, ix, iy, bc_, de_, hl_, af_;
	zuint8	r, i;
	ZInt16	sp, pc;
	zuint16 zero_0; /* reserved for future use */
	zuint8	border_color;
	zuint8	zero_1; /* reserved for future use */

	union {	zuint8 value;
		struct {Z_BIT_FIELD_MEMBERS(8, 7) (
			zuint8 zero	:2, /* reserved for internal use */
			zuint8 flash	:1, /* boolean */
			zuint8 int_line :1,
			zuint8 im0	:1,
			zuint8 iff2	:1, /* Added in v0.99C, always 0 in previous versions. */
			zuint8 im	:1,
			zuint8 iff1	:1
		)} fields;
	} status;

	zuint8 zero_2;	   /* reserved for future use */
	zuint8 ram[Z_ZX_SPECTRUM_16K_SIZE_RAM]; /* 16384 or 49152 */
} Z_PACKED_STRUCTURE_END Z_SPSnapshot;

typedef Z_PACKED_STRUCTURE_BEGIN {
	Z_SPHeader   header;
	Z_SPSnapshot snapshot;
} Z_PACKED_STRUCTURE_END Z_SP;

#define Z_SP_IM(p) ((p)->bits.im0 ? 0 : ((p)->bits.im + 1))

/*	0  1000
	1  0000
	2  0010
*/

#endif /* Z_formats_snapshot_machine_computer_ZX_Spectrum_SP_H */
