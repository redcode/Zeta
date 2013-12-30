/* Q API - formats/storage medium image/magnetic disk/FDI.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2014 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_formats_storage_medium_image_magnetic_disk_FDI_H__
#define __Q_formats_storage_medium_image_magnetic_disk_FDI_H__

#include <Q/types/base.h>
#include <Q/macros/bit field.h>

Q_DEFINE_STRICT_STRUCTURE (
	quint8	signature[3]; /* 'FDI' */
	quint8	write_protection;
	quint16 cylinder_count;
	quint16 head_count;
	quint16 disk_description_offset;
	quint16 data_offset;
	quint16 header_additional_information_size;
	quint8	additional_information[];
) QFDIHeader;

#define Q_FDI_HEADER(p) ((QFDIHeader *)(p))

Q_DEFINE_STRICT_STRUCTURE (
	quint8 cylinder;
	quint8 head;
	quint8 size;

	Q_8BIT_FIELD (
		quint8 data_deleted: 1,
		quint8 zero:	     1,
		quint8 crc_errors:   6
	) flags;

	quint16 offset;
) QFDISectorEntry;

#define Q_DSK_SECTOR_ENTRY(p) ((QFDISectorEntry *)(p))

Q_DEFINE_STRICT_STRUCTURE (
	quint32		data_offset;
	quint16		zero; /* Always 0000h */
	quint8		sector_count;
	QFDISectorEntry sectors_entries[];
) QFDITrackHeader;

#define Q_FDI_TRACK_HEADER(p) ((QFDITrackHeader *)(p))

#endif /* __Q_formats_storage_medium_image_magnetic_disk_FDI_H__ */
