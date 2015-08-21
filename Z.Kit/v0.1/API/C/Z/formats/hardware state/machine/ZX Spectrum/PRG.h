/* Z Kit C API - formats/hardware snapshot/machine/ZX Spectrum/PRG.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © Kevin Phair.
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.
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

#ifndef __Z_formats_hardware_snapshot_machine_ZX_Spectrum_PRG_H__
#define __Z_formats_hardware_snapshot_machine_ZX_Spectrum_PRG_H__

#include <Z/types/base.h>

Z_DEFINE_STRICT_STRUCTURE (
	zuint8	file_type;	   /* Always 05h */
	zuint8	program_name[10];  /* 20h, name[], 20h */
	zuint16	file_sector_count; /* BIG ENDIAN */
	zuint8	file_first_sector_track_index;
	zuint8	file_first_sector_sector_index;
	zuint8	sector_allocation_bitmap[195];
	/* ..... TO DO */
) ZPRG;

#define Z_PRG(p) ((ZPRG *)(p))

#endif /* __Z_formats_hardware_snapshot_machine_ZX_Spectrum_PRG_H__ */
