/* Z Kit - formats/file system/FAT12.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_formats_file_system_FAT12_H_
#define _Z_formats_file_system_FAT12_H_

#include <Z/types/base.h>

Z_DEFINE_STRICT_STRUCTURE (
	zuint8	ignored_0[11];
	zuint16 bytes_per_sector;
	zuint8	sectors_per_cluster;
	zuint16	reserved_sector_count;
	zuint8	fat_count;
	zuint16	directory_entry_maximum;
	zuint16	total_sector_count;
	zuint8	ignored_1;
	zuint16	sectors_per_fat;
	zuint16	sectors_per_track;
	zuint16	head_count;
	zuint8	ignored_2[4];
	zuint32	fat32_total_sector_count;
	zuint8	ignored_3[2];
	zuint8	boot_signature;
	zuint32	volume_id;
	zuint8	volume_label[11];
	zuint8	file_system_type[8];
) ZFAT12BootSector;

#define Z_FAT_12_DEFAULT_VOLUME_LABEL	 "NO NAME    "
#define Z_FAT_12_FILE_SYSTEM_TYPE_FAT_12 "FAT12   "
#define Z_FAT_12_FILE_SYSTEM_TYPE_FAT_16 "FAT16   "
#define Z_FAT_12_FILE_SYSTEM_TYPE_FAT	 "FAT     "

Z_DEFINE_STRICT_STRUCTURE (
	zuint8	file_name[8];
	zuint8	extension[3];
	zuint8	attributes;
	zuint8	reserved[2];
	zuint16	creation_time;
	zuint16	creation_date;
	zuint16	last_access_date;
	zuint8	ignored[2];
	zuint16	last_write_time;
	zuint16	last_write_date;
	zuint16	first_logical_cluster;
	zuint32	file_size;
) ZFAT12DirectoryEntry;

#define Z_FAT_12_FILE_ATTRIBUTE_READ_ONLY     1
#define Z_FAT_12_FILE_ATTRIBUTE_HIDDEN	      2
#define Z_FAT_12_FILE_ATTRIBUTE_SYSTEM	      4
#define Z_FAT_12_FILE_ATTRIBUTE_VOLUME_LABEL  8
#define Z_FAT_12_FILE_ATTRIBUTE_SUBDIRECTORY 16
#define Z_FAT_12_FILE_ATTRIBUTE_ARCHIVE	     32

#endif /* _Z_formats_file_system_FAT12_H_ */
