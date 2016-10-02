/* Z Kit C API - formats/storage medium image/floppy disk/FDI.h
 _____ 	_______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_|
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_formats_storage_medium_image_floppy_disk_FDI_H__
#define __Z_formats_storage_medium_image_floppy_disk_FDI_H__

#include <Z/types/base.h>

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

	struct {Z_BIT_FIELD(8, 3) (
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

#endif /* __Z_formats_storage_medium_image_floppy_disk_FDI_H__ */
