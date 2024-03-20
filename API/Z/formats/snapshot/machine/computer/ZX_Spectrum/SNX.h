/* Zeta API - Z/formats/snapshot/machine/computer/ZX_Spectrum/SNX.h
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.

 ______________________________________________________________________
|								       |
|	 Daft: Public.Snapshot.Computer.ZXSpectrum.SNX		       |
|      Author: Gandler, Christian				       |
|  Extensions: .snx						       |
|  Endianness: Little						       |
|    Supports: ZX Spectrum 48K					       |
|     Used by: ZX-Spectrum Emulator (aka Specci) (Atari ST)	       |
|								       |
|  Reference:							       |
|  http://cd.textfiles.com/crawlycrypt1/apps/misc/zx_sp207/specci.doc  |
|  http://www.zx-modules.de/fileformats/snxformat.html		       |
|  [MAME sources]/src/mame/machine/spec_snqk.cpp		       |
|								       |
'=====================================================================*/

#ifndef Z_formats_snapshot_machine_computer_ZX_Spectrum_SNX_H
#define Z_formats_snapshot_machine_computer_ZX_Spectrum_SNX_H

#include <Z/formats/snapshot/machine/computer/ZX_Spectrum/SNA.h>

typedef Z_PACKED_STRUCTURE_BEGIN {
	ZInt32	signature;   /* 'XSNA'	       */
	zuint16 header_size; /* 37, big endian */
	Z_SNA	sna;
	zuint8	emulate_interface_1;
	zuint8	emulate_flash;
	zuint8	emulate_vram_attributes;

	union {	zuint8 value;
		struct {Z_BIT_FIELD_MEMBERS(8, 4) (
			zuint8 keyboard	   :1,
			zuint8 emulate_ula :1,
			zuint8 unused	   :4,
			zuint8 joystick	   :2
		)} fields;
	} settings_0;

	union {	zuint8 value;
		struct {Z_BIT_FIELD_MEMBERS(8, 3) (
			zuint8 ear_mode	 :1,
			zuint8 unused	 :6,
			zuint8 emulate_r :1
		)} fields;
	} settings_1;

	zuint8 int_hz;
	zuint8 rs232_mode;

	union {	zuint8 value;
		struct {Z_BIT_FIELD_MEMBERS(8, 2) (
			zuint8 hz	      :4,
			zuint8 emulation_mode :1
		)} fields;
	} sound;

	zuint8 border_emulation_mode;
	zuint8 im2_pointer;
} Z_PACKED_STRUCTURE_END Z_SNX;

#define Z_SNX_RS232_REDIRECTION_RS232	   0
#define Z_SNX_RS232_REDIRECTION_CENTRONICS 1

#endif /* Z_formats_snapshot_machine_computer_ZX_Spectrum_SNX_H */
