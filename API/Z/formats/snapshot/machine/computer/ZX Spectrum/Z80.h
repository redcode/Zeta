/* Zeta API - Z/formats/snapshot/machine/computer/ZX Spectrum/Z80.h
 ______ ____________  ___
|__   /|  ___|__  __|/   \
  /  /_|  __|  |  | /  *  \
 /_____|_____| |__|/__/ \__\
Copyright (C) 2006-2023 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.

 _______________________________________________________
|							|
|	 Daft: Public.Snapshot.Computer.ZXSpectrum.Z80	|
|      Author: Lunter, Gerton				|
|  Extensions: .z80					|
|  Endianness: Little					|
|    Supports:						|
|     Used by: Z80 (MS-DOS)				|
|							|
|  Reference:						|
|  http://www.zx-modules.de/fileformats/z80format.html	|
|							|
'======================================================*/

#ifndef Z_formats_snapshot_machine_computer_ZX_Spectrum_Z80_H
#define Z_formats_snapshot_machine_computer_ZX_Spectrum_Z80_H

#include <Z/types/bitwise.h>

Z_DEFINE_PACKED_STRUCTURE_BEGIN {
	ZInt16 af; /* big endian */
	ZInt16 bc, hl, pc, sp;
	zuint8 i, r;

	/* Additional info; if the byte= 255, it has to be
	interpreted as being = 1 */
	union {	zuint8 value;
		struct {Z_BIT_FIELD_MEMBERS(8, 5) (
			zuint8 zero		    :2,
			zuint8 ram_is_compressed    :1,
			zuint8 emulate_basic_samrom :1,
			zuint8 border_color	    :3,
			zuint8 r7		    :1
		)} fields;
	} flags_0;

	ZInt16 de, bc_, de_, hl_;
	ZInt16 af_; /* big endian */
	ZInt16 iy, ix;
	zuint8 iff1, iff2;

	union {	zuint8 value;
		struct {Z_BIT_FIELD_MEMBERS(8, 5) (
			zuint8 joystick_type	     :2,
			zuint8 video_synchronization :2,
			zuint8 double_int_frequency  :1,
			zuint8 emulate_issue_2	     :1,
			zuint8 im		     :2
		)} fields;
	} flags_1;
} Z_DEFINE_PACKED_STRUCTURE_END (Z_Z80v1);

Z_DEFINE_PACKED_STRUCTURE_BEGIN {
	zuint16 header_size;
	zuint16 pc;
	zuint8	hardware;
	zuint8	state_0;
	zuint8	state_1;

	struct {Z_BIT_FIELD_MEMBERS(8, 7) (
		zuint8 unused_1		     :1,
		zuint8 modify_hardware	     :1,
		zuint8 emulate_fuller_box_ay :1,
		zuint8 unused_0		     :2,
		zuint8 emulate_psg	     :1,
		zuint8 emulate_ldir	     :1,
		zuint8 emulate_r	     :1
	)} bitfield;

	zuint8 psg_register_index;
	zuint8 psg_registers[16];
} Z_DEFINE_PACKED_STRUCTURE_END (Z_Z80v2Extension);

Z_DEFINE_PACKED_STRUCTURE_BEGIN {
	Z_Z80v1		 v1;
	Z_Z80v2Extension v2;
} Z_DEFINE_PACKED_STRUCTURE_END (Z_Z80v2);

Z_DEFINE_PACKED_STRUCTURE_BEGIN {
	zuint16 t_states_low;
	zuint8	t_states_high;
	zuint8	zero[3];
	zuint8	mgt_rom_is_paged;
	zuint8	multiface_rom_is_paged;
	zuint8	page_0l_memory_type;
	zuint8	page_0h_memory_type;
	zuint16	keyboard_mappings[5];
	zuint16	ascii_values[5];
	zuint8	mgt_type;
	zuint8	disciple_inhibitor_button_state;
	zuint8	disciple_inhibitor_flag;
	zuint8	control;
} Z_DEFINE_PACKED_STRUCTURE_END (Z_Z80v3Extension);

Z_DEFINE_PACKED_STRUCTURE_BEGIN {
	Z_Z80v1		v1;
	Z_Z80v2Extension v2;
	Z_Z80v3Extension v3;
} Z_DEFINE_PACKED_STRUCTURE_END (Z_Z80v3);

/* TODO: Homogeneizar los joysticks con los de TZX. */
#define Z_Z80_JOYSTICK_TYPE_CURSOR_PROTEK_AGF 0
#define Z_Z80_JOYSTICK_TYPE_KEMPSTON	      1
#define Z_Z80_JOYSTICK_TYPE_SINCLAIR_2_LEFT   2
#define Z_Z80_JOYSTICK_TYPE_SINCLAIR_2_RIGHT  3

#define Z_Z80_VIDEO_SYNCHRONIZATION_NORMAL_1 0
#define Z_Z80_VIDEO_SYNCHRONIZATION_HIGH     1
#define Z_Z80_VIDEO_SYNCHRONIZATION_NORMAL_2 2
#define Z_Z80_VIDEO_SYNCHRONIZATION_LOW	     3

#define Z_Z80_HARDWARE_SAM_RAM				 2
#define Z_Z80_HARDWARE_PENTAGON_128			 9
#define Z_Z80_HARDWARE_SCORPION_ZS_256			10
#define Z_Z80_HARDWARE_DIDAKTIK_KOMPAKT			11
#define Z_Z80_HARDWARE_ZX_SPECTRUM_PLUS2		12
#define Z_Z80_HARDWARE_ZX_SPECTRUM_PLUS2A		13
#define Z_Z80_HARDWARE_TIMEX_COMPUTER_2048		14
#define Z_Z80_HARDWARE_TIMEX_COMPUTER_2068		15
#define Z_Z80_HARDWARE_TIMEX_SINCLAIR_2068		128

#define Z_Z80_HARDWARE_A_ZX_SPECTRUM_48K		0
#define Z_Z80_HARDWARE_A_ZX_SPECTRUM_48K_AND_IF1	1
#define Z_Z80_HARDWARE_A_ZX_SPECTRUM_128K_AND_IF1	5
#define Z_Z80_HARDWARE_A_ZX_SPECTRUM_128K_AND_MGT	6
#define Z_Z80_HARDWARE_A_ZX_SPECTRUM_PLUS3		7
#define Z_Z80_HARDWARE_A_ZX_SPECTRUM_PLUS3_		8

#define Z_Z80_HARDWARE_B_ZX_SPECTRUM_16K		0
#define Z_Z80_HARDWARE_B_ZX_SPECTRUM_16K_AND_IF1	1
#define Z_Z80_HARDWARE_A_ZX_SPECTRUM_PLUS2_AND_IF1	5
#define Z_Z80_HARDWARE_A_ZX_SPECTRUM_PLUS2_AND_MGT	6
#define Z_Z80_HARDWARE_B_ZX_SPECTRUM_PLUS2A		7
#define Z_Z80_HARDWARE_B_ZX_SPECTRUM_PLUS2A_		8

#define Z_Z80_V2_HARDWARE_A_ZX_SPECTRUM_128K		3
#define Z_Z80_V2_HARDWARE_A_ZX_SPECTRUM_128K_AND_IF1	4

#define Z_Z80_V2_HARDWARE_B_ZX_SPECTRUM_PLUS2		3
#define Z_Z80_V2_HARDWARE_B_ZX_SPECTRUM_PLUS2_AND_IF1	4

#define Z_Z80_V3_HARDWARE_A_ZX_SPECTRUM_48K_AND_MGT	3
#define Z_Z80_V3_HARDWARE_A_ZX_SPECTRUM_128K		4

#define Z_Z80_V3_HARDWARE_B_ZX_SPECTRUM_PLUS2_AND_MGT	3
#define Z_Z80_V3_HARDWARE_B_ZX_SPECTRUM_PLUS2		4

#endif /* Z_formats_snapshot_machine_computer_ZX_Spectrum_Z80_H */
