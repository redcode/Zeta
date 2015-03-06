/* Q C API - formats/file system/FAT12.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_formats_file_system_FAT12_H__
#define __Q_formats_file_system_FAT12_H__

#include <Q/types/base.h>

#define Q_FAT_12_DEFAULT_VOLUME_LABEL	 "NO NAME    "
#define Q_FAT_12_FILE_SYSTEM_TYPE_FAT_12 "FAT12   "
#define Q_FAT_12_FILE_SYSTEM_TYPE_FAT_16 "FAT16   "
#define Q_FAT_12_FILE_SYSTEM_TYPE_FAT	 "FAT     "

Q_DEFINE_STRICT_STRUCTURE (
	quint8	ignored_1[11];
	quint16 bytes_per_sector;
	quint8	sectors_per_cluster;
	quint16	reserved_sector_count;
	quint8	fat_count;
	quint16	directory_entry_maximum;
	quint16	total_sector_count;
	quint8	ignored_2;
	quint16	sectors_per_fat;
	quint16	sectors_per_track;
	quint16	head_count;
	quint8	ignored_3[4];
	quint32	fat32_total_sector_count;
	quint8	ignored_4[2];
	quint8	boot_signature;
	quint32	volume_id;
	quint8	volume_label[11];
	quint8	file_system_type[8];
) QFAT12BootSector;

#define Q_FAT_12_FILE_ATTRIBUTE_READ_ONLY     1
#define Q_FAT_12_FILE_ATTRIBUTE_HIDDEN	      2
#define Q_FAT_12_FILE_ATTRIBUTE_SYSTEM	      4
#define Q_FAT_12_FILE_ATTRIBUTE_VOLUME_LABEL  8
#define Q_FAT_12_FILE_ATTRIBUTE_SUBDIRECTORY 16
#define Q_FAT_12_FILE_ATTRIBUTE_ARCHIVE	     32

Q_DEFINE_STRICT_STRUCTURE (
	quint8	file_name[8];
	quint8	extension[3];
	quint8	attributes;
	quint8	reserved[2];
	quint16	creation_time;
	quint16	creation_date;
	quint16	last_access_date;
	quint8	ignored[2];
	quint16	last_write_time;
	quint16	last_write_date;
	quint16	first_logical_cluster;
	quint32	file_size;
) QFAT12DirectoryEntry;

#define Q_FAT_12_BOOT_SECTOR(	 p) ((QFAT12BootSector	   *)(p))
#define Q_FAT_12_DIRECTORY_ENTRY(p) ((QFAT12DirectoryEntry *)(p))

#endif /* __Q_formats_file_system_FAT12_H__ */
