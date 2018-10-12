/* Z Kit - formats/snapshot/machine/computer/ZX Spectrum/SP.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.

.----------------------------------------------------------------------------.
| Extensions: sp							     |
| Endianness: Little							     |
| Created by: Gimeno Fortea, Pedro					     |
|    Used by: VGASpec, Spectrum [DOS]					     |
|									     |
| http://www.formauri.es/personal/pgimeno/spec/spec.html		     |
|									     |
| From the sources of MESS:						     |
|									     |
| "  There are two kinds of .sp files: 'old' and 'new'.			     |
| The old version is always 49184 bytes long and is created by a leaked copy |
| of the VGASpec emulator.						     |
| Subsequently Pedro Gimeno (the author of VGASpec) renamed it to 'Spectrum' |
| (but it's colloquially known as the 'Spanish Spectrum emulator') and added |
| a header in the snapshot to break backward compatibility: the new format   |
| supports both 16K and 48K images and it's 16422 or 49190 bytes long.	"    |
'---------------------------------------------------------------------------*/

#ifndef _Z_formats_snapshot_machine_computer_ZX_Spectrum_SP_H_
#define _Z_formats_snapshot_machine_computer_ZX_Spectrum_SP_H_

#include <Z/types/base.h>

Z_DEFINE_STRICT_STRUCTURE (
	zuint8	signature[2];	  /* 'SP' */
	zuint16 ram_size;	  /* 1024 * 16 or 1024 * 48 */
	zuint16 ram_load_address; /* 1024 * 16 */
) ZSPHeader;

Z_DEFINE_STRICT_STRUCTURE_BEGIN
	Z16Bit	bc,  de,  hl,  af,  ix, iy;
	Z16Bit	bc_, de_, hl_, af_;
	zuint8	r,   i;
	zuint16 sp,  pc;
	zuint16 zero1; /* reserved for future use */
	zuint8	border_color;
	zuint8	zero2; /* reserved for future use */

	struct {Z_BIT_FIELD(8, 7) (
		zuint8 zero	   :2, /* reserved for internal use */
		zuint8 flash	   :1, /* boolean */
		zuint8 int_pending :1,
		zuint8 im_0	   :1,
		zuint8 iff2	   :1,
		zuint8 im	   :1,
		zuint8 iff1	   :1
	)} status;

	Z_FLEXIBLE_ARRAY_MEMBER(zuint8 ram[];)
Z_DEFINE_STRICT_STRUCTURE_END ZSPBody;

#define Z_SP_BODY_IM(p) (Z_SP_BODY(p)->im_0 ? 0 : ((p)->im ? 2 : 1))

#endif /* _Z_formats_snapshot_machine_computer_ZX_Spectrum_SP_H_ */
