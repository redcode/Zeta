/* Zeta API - Z/formats/snapshot/machine/computer/ZX_Spectrum/PRG.h
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.

 _______________________________________________________
|							|
|	 Daft: Public.Snapshot.Computer.ZXSpectrum.PRG  |
|      Author: Phair, Kevin J.				|
|  Extensions: .prg					|
|  Endianness: Little					|
|    Supports: ZX Spectrum 48K				|
|     Used by: Spectrum Emulator, The (MS-DOS)		|
|	      <http://code.google.com/p/specem>		|
|							|
|  Reference:						|
|  [MAME sources]/src/mame/machine/spec_snqk.cpp	|
|							|
'======================================================*/

#ifndef Z_formats_snapshot_machine_computer_ZX_Spectrum_PRG_H
#define Z_formats_snapshot_machine_computer_ZX_Spectrum_PRG_H

#include <Z/formats/snapshot/machine/computer/ZX_Spectrum/+D.h>
#include <Z/hardware/machine/computer/ZX_Spectrum.h>

typedef Z_PACKED_STRUCTURE_BEGIN {
	zuint8	   file_type;	      /* 05h */
	zuint8	   program_name[10];
	zuint16	   file_sector_count; /* big endian */
	zuint8	   file_track_index;
	zuint8	   file_sector_index;
	zuint8	   sector_allocation_bitmap[195];
	zuint8	   zero_0[10];
	Z_PlusDCPU cpu;
	zuint8	   zero_1[14];
	zuint8	   ram[Z_ZX_SPECTRUM_48K_SIZE_RAM];
} Z_PACKED_STRUCTURE_END Z_PRG;

typedef Z_PACKED_STRUCTURE_BEGIN {
	union {	zuint8 value;
		struct {Z_BIT_FIELD_MEMBERS(8, 3) (
			zuint8 unused_1 :5,
			zuint8 iff1	:1,
			zuint8 unused_0 :2
		)} fields;
	} interrupt;

	zuint8	r;
	ZInt16	af;
	zuint16 pc;
} Z_PACKED_STRUCTURE_END Z_PRGStack;

#define Z_PRG_FILE_TYPE_48K 0x05

#endif /* Z_formats_snapshot_machine_computer_ZX_Spectrum_PRG_H */
