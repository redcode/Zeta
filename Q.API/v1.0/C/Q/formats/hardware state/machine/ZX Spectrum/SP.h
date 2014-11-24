/* Q API - formats/hardware snapshot/machine/ZX Spectrum/SP.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2014 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3.
 _____________________________________________________________________________
/\									      \
\_| Extensions: .sp							       |
  | Endianness: Little							       |
  | Created by: Pedro Gimeno Fortea					       |
  | Used by:	VGASpec, SPECTRUM [MS-DOS]				       |
  |									       |
  | http://www.formauri.es/personal/pgimeno/spec/spec.html		       |
  |									       |
  | From the sources of MESS:						       |
  |									       |
  | " There are two kinds of .sp files: 'old' and 'new'.		       |
  | The old version is always 49184 bytes long and is created by a leaked copy |
  | of the VGASpec emulator.						       |
  | Subsequently Pedro Gimeno (the author of VGASpec) renamed it to 'Spectrum' |
  | (but it's colloquially known as the 'Spanish Spectrum emulator') and added |
  | a header in the snapshot to break backward compatibility: the new format   |
  | supports both 16K and 48K images and it's 16422 or 49190 bytes long. "     |
  |   _________________________________________________________________________|_
   \_/_________________________________________________________________________*/

#ifndef __Q_formats_hardware_snapshot_machine_ZX_Spectrum_SP_H__
#define __Q_formats_hardware_snapshot_machine_ZX_Spectrum_SP_H__

#include <Q/types/base.h>
#include <Q/macros/bit field.h>

Q_DEFINE_STRICT_STRUCTURE (
	quint8	signature[2];		/* 'SP'				*/
	quint16 ram_size;		/* 1024 * 16 or 1024 * 48	*/
	quint16 ram_load_address;	/* 1024 * 16			*/
) QSPHeader;

Q_DEFINE_STRICT_STRUCTURE (
	Q16Bit	bc,  de,  hl,  af,  ix, iy;
	Q16Bit	bc_, de_, hl_, af_;
	quint8	r,   i;
	quint16 sp,  pc;
	quint16 zero1;			/* reserved for future use	*/
	quint8	border_color;
	quint8	zero2;			/* reserved for future use	*/

	struct {Q_8BIT_FIELD(7) (
		quint8 zero	   :2;	/* reserved for internal use	*/
		quint8 flash	   :1;	/* boolean			*/
		quint8 int_pending :1;
		quint8 im_0	   :1;
		quint8 iff2	   :1;
		quint8 im	   :1;
		quint8 iff1	   :1;
	)} status;

	quint8 ram[];
) QSPBody;

#define Q_SP_HEADER(p) ((QSPHeader *)(p))
#define Q_SP_BODY(  p) ((QSPBody   *)(p))

#define Q_SP_BODY_IM(p) (Q_SP_BODY(p)->im_0 ? 0 : ((p)->im ? 2 : 1))

#endif /* __Q_formats_hardware_snapshot_machine_ZX_Spectrum_SP_H__ */
