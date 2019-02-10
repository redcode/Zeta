/* Z Kit - formats/snapshot/machine/computer/ZX Spectrum/SP.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2019 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.

.----------------------------------------------------------------------------.
| Extensions: sp							     |
| Endianness: Little							     |
|   Supports: 48K							     |
|    Used by: Spectrum / VGASpec (MS-DOS)				     |
|	      <http://www.formauri.es/personal/pgimeno/spec/spec.html>	     |
|     Author: Gimeno Fortea, Pedro <pgimeno@iname.com>			     |
|  Reference: <http://www.zx-modules.de/fileformats/snxformat.html>	     |
|	      [MAME sources]/src/mame/machine/spec_snqk.cpp		     |
|									     |
| From the sources of MESS:						     |
|									     |
| -- There are two kinds of .sp files: 'old' and 'new'.			     |
|									     |
| The old version is always 49184 bytes long and is created by a leaked copy |
| of the VGASpec emulator.						     |
|									     |
| Subsequently Pedro Gimeno (the author of VGASpec) renamed it to 'Spectrum' |
| (but it's colloquially known as the 'Spanish Spectrum emulator') and added |
| a header in the snapshot to break backward compatibility: the new format   |
| supports both 16K and 48K images and it's 16422 or 49190 bytes long. --    |
'---------------------------------------------------------------------------*/

#ifndef Z_formats_snapshot_machine_computer_ZX_Spectrum_SP_H_
#define Z_formats_snapshot_machine_computer_ZX_Spectrum_SP_H_

#include <Z/types/bitwise.h>

Z_DEFINE_PACKED_STRUCTURE_BEGIN {
	Z16Bit	bc,  de,  hl,  af,  ix, iy;
	Z16Bit	bc_, de_, hl_, af_;
	zuint8	r,   i;
	zuint16 sp,  pc;
	zuint16 zero_0; /* reserved for future use */
	zuint8	border_color;
	zuint8	zero_1; /* reserved for future use */

	struct {Z_BIT_FIELD(8, 7) (
		zuint8 zero	    :2, /* reserved for internal use */
		zuint8 flash_status :1, /* boolean */
		zuint8 int_pending  :1,
		zuint8 im_0	    :1,
		zuint8 iff2	    :1,
		zuint8 im	    :1,
		zuint8 iff1	    :1
	)} bits;

	zuint8 zero_2; /* reserved for future use */
	Z_FAM(zuint8 ram[];)
} Z_DEFINE_PACKED_STRUCTURE_END (ZSPOld);

#define Z_SP_FLASH_STATUS_NORMAL  0
#define Z_SP_FLASH_STATUS_INVERSE 1

#define Z_SP_IM(p) ((p)->bits.im_0 ? 0 : ((p)->bits.im ? 2 : 1))

Z_DEFINE_PACKED_STRUCTURE ({
	zuint8	signature[2];	  /* 'SP'	    */
	zuint16 ram_size;	  /* 16384 or 49152 */
	zuint16 ram_load_address; /* 16384	    */
}, ZSPNewHeader);

#endif /* Z_formats_snapshot_machine_computer_ZX_Spectrum_SP_H_ */
