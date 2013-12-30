/* Q API - formats/storage medium image/tape/TAP.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2013 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3.

.----------------------------------------.
| Extensions: .tap			 |
| Endianness: Little			 |
| Created by: Sinclair Research		 |
|    Used by: ZX Spectrum, many programs |
'---------------------------------------*/

#ifndef __Q_formats_storage_medium_image_tape_TAP_H__
#define __Q_formats_storage_medium_image_tape_TAP_H__

#include <Q/types/base.h>

typedef quint8 QTAPBlockID;

Q_DEFINE_STRICT_STRUCTURE (
	quint8	header_id;
	quint8	file_name[10];
	quint16	data_size;
) QTAPHeaderPrefix;

Q_DEFINE_STRICT_STRUCTURE (
	quint16 autostart_line;
	quint16 program_size;
	quint8	checksum;
) QTAPProgramHeader;

Q_DEFINE_STRICT_STRUCTURE (
	quint8	unused1;
	quint8	variable_name;
	quint16	unused2;
	quint8	checksum;
) QTAPDataHeader;

Q_DEFINE_STRICT_STRUCTURE (
	quint16 start_address;
	quint16 unused;
	quint8	checksum;
) QTAPScreenHeader;

Q_DEFINE_STRICT_STRUCTURE (
) QTAPDataBlock;

#endif /* __Q_formats_storage_medium_image_tape_TAP_H__ */
