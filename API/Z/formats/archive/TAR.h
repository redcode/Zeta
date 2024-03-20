/* Zeta API - Z/formats/archive/TAR.h
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_formats_archive_TAR_H
#define Z_formats_archive_TAR_H

#include <Z/macros/language.h>
#include <Z/types/integral.h>

/* http://www.gnu.org/software/tar/manual/html_node/Standard.html */

#define Z_TAR_BLOCK_SIZE 512

typedef Z_PACKED_STRUCTURE_BEGIN {	/* byte offset */
	zuint8 name[100];               /*   0 */
	zuint8 mode[8];                 /* 100 */
	zuint8 uid[8];                  /* 108 */
	zuint8 gid[8];                  /* 116 */
	zuint8 size[12];                /* 124 */
	zuint8 mtime[12];               /* 136 */
	zuint8 checksum[8];             /* 148 */
	zuint8 item_type;               /* 156 */
	zuint8 link_name[100];          /* 157 */
	zuint8 magic[6];                /* 257 */
	zuint8 version[2];              /* 263 */
	zuint8 uname[32];               /* 265 */
	zuint8 gname[32];               /* 297 */
	zuint8 device_major[8];         /* 329 */
	zuint8 device_minor[8];         /* 337 */
	zuint8 prefix[155];             /* 345 */
					/* 500 */
} Z_PACKED_STRUCTURE_END Z_TARPOSIXHeader;

typedef Z_TARPOSIXHeader Z_TARHeader;

#define Z_TAR_ITEM_TYPE_OLD_REGULAR_FILE 0
#define Z_TAR_ITEM_TYPE_REGULAR_FILE	 0x30
#define Z_TAR_ITEM_TYPE_LINK		 0x31
#define Z_TAR_ITEM_TYPE_SYMBOLIC_LINK	 0x32
#define Z_TAR_ITEM_TYPE_CHARACTER_DEVICE 0x33
#define Z_TAR_ITEM_TYPE_BLOCK_DEVICE	 0x34
#define Z_TAR_ITEM_TYPE_DIRECTORY	 0x35
#define Z_TAR_ITEM_TYPE_FIFO		 0x36
#define Z_TAR_ITEM_TYPE_CONTIGUOUS_FILE	 0x37

#define Z_TAR_ITEM_TYPE_GNU_DIRECTORY_DUMP 'D' /* file names from dumped directory */
#define Z_TAR_ITEM_TYPE_GNU_LONG_LINK	   'K' /* long link name */
#define Z_TAR_ITEM_TYPE_GNU_LONG_NAME	   'L' /* long file name */
#define Z_TAR_ITEM_TYPE_GNU_MULTIVOLUME	   'M' /* continuation of file from another volume */
#define Z_TAR_ITEM_TYPE_GNU_NAMES	   'N' /* file name that does not fit into main hdr */
#define Z_TAR_ITEM_TYPE_GNU_SPARSE	   'S' /* sparse file */
#define Z_TAR_ITEM_TYPE_GNU_VOLUME_HEADER  'V' /* tape/volume header */

#endif /* Z_formats_archive_TAR_H */
