/* Q API - formats/storage medium image/tape/TAP.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2014 Manuel Sainz de Baranda y Goñi.
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

Q_DEFINE_STRICT_STRUCTURE (
	quint16 size;
	quint8	data[];
) QTAPBlock;

Q_DEFINE_STRICT_STRUCTURE (
	quint8	type;
	quint8	file_name[10];
	quint16	data_size;

	union {	struct {quint16 autostart_line;
			quint16 program_size;
		} program;

		struct {quint8	unused1;
			quint8	variable_name;
			quint16	unused2;
		} array;

		struct {quint16 start_address;
			quint16 unused;
		} code_file;
	} information;

	quint8 checksum;
) QTAPBlockHeader;

#define Q_TAP_BLOCK_TYPE_PROGRAM	 0
#define Q_TAP_BLOCK_TYPE_NUMBER_ARRAY	 1
#define Q_TAP_BLOCK_TYPE_CHARACTER_ARRAY 2
#define Q_TAP_BLOCK_TYPE_CODE_FILE	 3

#define Q_TAP_BLOCK(	   p) ((QTAPBlock	*)(p))
#define Q_TAP_BLOCK_HEADER(p) ((QTAPBlockHeader *)(p))

#endif /* __Q_formats_storage_medium_image_tape_TAP_H__ */
