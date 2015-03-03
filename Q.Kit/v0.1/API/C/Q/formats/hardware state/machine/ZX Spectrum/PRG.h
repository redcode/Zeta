/* Q Kit API - formats/hardware snapshot/machine/ZX Spectrum/PRG.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © Kevin Phair.
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3.
 ______________________________________
/\				       \
\_| Extensions: .prg			|
  | Endianness: Little			|
  | Created by: Kevin Phair		|
  | Used by:	Spectrum Emulator [DOS] |
  |					|
  | http://code.google.com/p/specem	|
  |   __________________________________|_
   \_/__________________________________*/

#ifndef __Q_formats_hardware_snapshot_machine_ZX_Spectrum_PRG_H__
#define __Q_formats_hardware_snapshot_machine_ZX_Spectrum_PRG_H__

#include <Q/types/base.h>

Q_DEFINE_STRICT_STRUCTURE (
	quint8	file_type;	   /* Always 05h */
	quint8	program_name[10];  /* 20h, name[], 20h */
	quint16	file_sector_count; /* BIG ENDIAN */
	quint8	file_first_sector_track_index;
	quint8	file_first_sector_sector_index;
	quint8	sector_allocation_bitmap[195];

	/* ..... TO DO */
) QPRG;

#define Q_PRG(p) ((QPRG *)(p))

#endif /* __Q_formats_hardware_snapshot_machine_ZX_Spectrum_PRG_H__ */
