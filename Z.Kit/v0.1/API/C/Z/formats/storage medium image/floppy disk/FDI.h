/* Z Kit C API - formats/storage medium image/floppy disk/FDI.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_formats_storage_medium_image_floppy_disk_FDI_H__
#define __Z_formats_storage_medium_image_floppy_disk_FDI_H__

#include <Z/types/base.h>
#include <Z/macros/bit field.h>

Z_DEFINE_STRICT_STRUCTURE (
	zuint8	signature[3]; /* 'FDI' */
	zuint8	write_protection;
	zuint16 cylinder_count;
	zuint16 head_count;
	zuint16 disk_description_offset;
	zuint16 data_offset;
	zuint16 header_additional_information_size;
	zuint8	additional_information[];
) ZFDIHeader;

Z_DEFINE_STRICT_STRUCTURE (
	zuint8 cylinder;
	zuint8 head;
	zuint8 size;

	struct {Z_8BIT_FIELD(3) (
		zuint8 data_deleted: 1,
		zuint8 zero:	     1,
		zuint8 crc_errors:   6
	)} flags;

	zuint16 offset;
) ZFDISectorEntry;

Z_DEFINE_STRICT_STRUCTURE (
	zuint32		data_offset;
	zuint16		zero; /* Always 0000h */
	zuint8		sector_count;
	ZFDISectorEntry sectors_entries[];
) ZFDITrackHeader;

#define Z_FDI_HEADER(	   p) ((ZFDIHeader	*)(p))
#define Z_DSK_SECTOR_ENTRY(p) ((ZFDISectorEntry *)(p))
#define Z_FDI_TRACK_HEADER(p) ((ZFDITrackHeader *)(p))

#endif /* __Z_formats_storage_medium_image_floppy_disk_FDI_H__ */
