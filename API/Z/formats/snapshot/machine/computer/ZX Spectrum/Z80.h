/* Z Kit - formats/snapshot/machine/computer/ZX Spectrum/Z80.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.

.---------------------------------------------.
| Extensions: z80			      |
| Endianness: Little			      |
| Created by: Lunter, Gerton		      |
|    Used by: Any decent ZX Spectrum emulator |
'--------------------------------------------*/

#ifndef _Z_formats_snapshot_machine_computer_ZX_Spectrum_Z80_H_
#define _Z_formats_snapshot_machine_computer_ZX_Spectrum_Z80_H_

#include <Z/types/base.h>

Z_DEFINE_STRICT_STRUCTURE_BEGIN
	zuint8	a, f;
	zuint16 bc, hl, pc, sp;
	zuint8	i, r;

	struct {Z_BIT_FIELD(8, 5) (
		zuint8 r7			:1,
		zuint8 border_color		:3,
		zuint8 basic_samrom		:1,
		zuint8 data_block_is_compressed :1,
		zuint8 unused			:2
	)} bitfield1;

	zuint16 de;
	zuint16 bc_, de_, hl_;
	zuint8	a_, f_;
	zuint16 iy, ix;
	zuint8 iff1, iff2;

	struct {Z_BIT_FIELD(8, 5) (
		zuint8 im		     :2,
		zuint8 issue_2_emulation     :1,
		zuint8 int_frequency	     :1,
		zuint8 video_synchronization :2,
		zuint8 joystick_type	     :2
	)} bitfield2;
Z_DEFINE_STRICT_STRUCTURE_END ZZ80v1Header;

Z_DEFINE_STRICT_STRUCTURE (
	zuint16 pc;
	zuint8	hardware;
	zuint8	output_state;
	zuint8	interface_1_paginated_or_timex_output_state;

	struct {Z_BIT_FIELD(8, 4) (
		zuint8 r_register_emulation	  :1,
		zuint8 ldir_instruction_emulation :1,
		zuint8 zero			  :5,
		zuint8 hardware_modification	  :1
	)} bitfield;

	zuint8 last_output_to_fffd;
	zuint8 sound_chip_registers;
) ZZ80v2AdditionalHeader;

#define Z_Z80_HARDWARE_SAM_RAM				 2
#define Z_Z80_HARDWARE_PENTAGON_128K			 9
#define Z_Z80_HARDWARE_SCORPION_256K			10
#define Z_Z80_HARDWARE_DIDAKTIK_KOMPAKT			11
#define Z_Z80_HARDWARE_ZX_SPECTRUM_PLUS_2		12
#define Z_Z80_HARDWARE_ZX_SPECTRUM_PLUS_2A		13
#define Z_Z80_HARDWARE_TIMEX_TC_2048			14
#define Z_Z80_HARDWARE_TIMEX_TC_2068			15
#define Z_Z80_HARDWARE_TIMEX_TS_2068			128

#define Z_Z80_HARDWARE_A_ZX_SPECTRUM_48K		0
#define Z_Z80_HARDWARE_A_ZX_SPECTRUM_48K_AND_IF1	1
#define Z_Z80_HARDWARE_A_ZX_SPECTRUM_128K_AND_IF1	5
#define Z_Z80_HARDWARE_A_ZX_SPECTRUM_128K_AND_MGT	6
#define Z_Z80_HARDWARE_A_ZX_SPECTRUM_PLUS_3		7
#define Z_Z80_HARDWARE_A_ZX_SPECTRUM_PLUS_3_		8

#define Z_Z80_HARDWARE_B_ZX_SPECTRUM_16K		0
#define Z_Z80_HARDWARE_B_ZX_SPECTRUM_16K_AND_IF1	1
#define Z_Z80_HARDWARE_A_ZX_SPECTRUM_PLUS_2_AND_IF1	5
#define Z_Z80_HARDWARE_A_ZX_SPECTRUM_PLUS_2_AND_MGT	6
#define Z_Z80_HARDWARE_B_ZX_SPECTRUM_PLUS_2A		7
#define Z_Z80_HARDWARE_B_ZX_SPECTRUM_PLUS_2A_		8

#define Z_Z80_V2_HARDWARE_A_ZX_SPECTRUM_128K		3
#define Z_Z80_V2_HARDWARE_A_ZX_SPECTRUM_128K_AND_IF1	4

#define Z_Z80_V2_HARDWARE_B_ZX_SPECTRUM_PLUS_2		3
#define Z_Z80_V2_HARDWARE_B_ZX_SPECTRUM_PLUS_2_AND_IF1	4

#define Z_Z80_V3_HARDWARE_A_ZX_SPECTRUM_48K_AND_MGT	3
#define Z_Z80_V3_HARDWARE_A_ZX_SPECTRUM_128K		4

#define Z_Z80_V3_HARDWARE_B_ZX_SPECTRUM_PLUS_2_AND_MGT	3
#define Z_Z80_V3_HARDWARE_B_ZX_SPECTRUM_PLUS_2		4

Z_DEFINE_STRICT_STRUCTURE (
	zuint16 low_t_state_counter;
	zuint8	high_t_state_counter;
	zuint8	zero[3];
	zuint8	mgt_rom_paged;
	zuint8	multiface_rom_paged;
	zuint8	memory_type_between_0000_and_1fff;
	zuint8	memory_type_between_2000_and_3fff;
	zuint16	keyboard_mappings[5];
	zuint16	ascii_values[5];
	zuint8	mgt_type;
	zuint8	disciple_inhibitor_button_state;
	zuint8	disciple_inhibitor_button_flag;
	zuint8	last_output_to_1ffd;
) ZZ80v3ExtendedHeader;

#endif /* _Z_formats_snapshot_machine_computer_ZX_Spectrum_Z80_H_ */
