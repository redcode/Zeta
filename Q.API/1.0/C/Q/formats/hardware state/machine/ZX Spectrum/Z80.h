/* Q API - formats/hardware snapshot/machine/ZX Spectrum/Z80.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2014 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_formats_hardware_snapshot_machine_ZX_Spectrum_Z80_H__
#define __Q_formats_hardware_snapshot_machine_ZX_Spectrum_Z80_H__

#include <Q/types/base.h>
#include <Q/macros/bit field.h>

Q_DEFINE_STRICT_STRUCTURE (
	quint8	a, f;
	quint16 bc, hl, pc, sp;
	quint8	i, r;

	Q_8BIT_FIELD (
		quint8 r7			:1,
		quint8 border_color		:3,
		quint8 basic_samrom		:1,
		quint8 data_block_is_compressed :1,
		quint8 unused			:2
	) bitfield1;

	quint16 de;
	quint16 bc_, de_, hl_;
	quint8	a_, f_;
	quint16 iy, ix;
	quint8 iff1, iff2;

	Q_8BIT_FIELD (
		quint8 im			:2,
		quint8 issue_2_emulation	:1,
		quint8 int_frequency		:1,
		quint8 video_synchronization	:2,
		quint8 joystick_type		:2
	) bitfield2;
) QZ80v1Header;

Q_DEFINE_STRICT_STRUCTURE (
	quint16 pc;
	quint8	hardware;
	quint8	output_state;
	quint8	interface_1_paginated_or_timex_output_state;

	Q_8BIT_FIELD (
		quint8 r_register_emulation	  :1,
		quint8 ldir_instruction_emulation :1,
		quint8 zero			  :5,
		quint8 hardware_modification	  :1
	) bitfield;

	quint8	last_output_to_fffd;
	quint8	sound_chip_registers;
) QZ80v2AdditionalHeader;



#define Q_Z80_HARDWARE_SAM_RAM				 2
#define Q_Z80_HARDWARE_PENTAGON_128K			 9
#define Q_Z80_HARDWARE_SCORPION_256K			10
#define Q_Z80_HARDWARE_DIDAKTIK_KOMPAKT			11
#define Q_Z80_HARDWARE_ZX_SPECTRUM_PLUS_2		12
#define Q_Z80_HARDWARE_ZX_SPECTRUM_PLUS_2A		13
#define Q_Z80_HARDWARE_TIMEX_TC_2048			14
#define Q_Z80_HARDWARE_TIMEX_TC_2068			15
#define Q_Z80_HARDWARE_TIMEX_TS_2068			128

#define Q_Z80_HARDWARE_A_ZX_SPECTRUM_48K		0
#define Q_Z80_HARDWARE_A_ZX_SPECTRUM_48K_AND_IF1	1
#define Q_Z80_HARDWARE_A_ZX_SPECTRUM_128K_AND_IF1	5
#define Q_Z80_HARDWARE_A_ZX_SPECTRUM_128K_AND_MGT	6
#define Q_Z80_HARDWARE_A_ZX_SPECTRUM_PLUS_3		7
#define Q_Z80_HARDWARE_A_ZX_SPECTRUM_PLUS_3_		8

#define Q_Z80_HARDWARE_B_ZX_SPECTRUM_16K		0
#define Q_Z80_HARDWARE_B_ZX_SPECTRUM_16K_AND_IF1	1
#define Q_Z80_HARDWARE_A_ZX_SPECTRUM_PLUS_2_AND_IF1	5
#define Q_Z80_HARDWARE_A_ZX_SPECTRUM_PLUS_2_AND_MGT	6
#define Q_Z80_HARDWARE_B_ZX_SPECTRUM_PLUS_2A		7
#define Q_Z80_HARDWARE_B_ZX_SPECTRUM_PLUS_2A_		8

#define Q_Z80_V2_HARDWARE_A_ZX_SPECTRUM_128K		3
#define Q_Z80_V2_HARDWARE_A_ZX_SPECTRUM_128K_AND_IF1	4

#define Q_Z80_V2_HARDWARE_B_ZX_SPECTRUM_PLUS_2		3
#define Q_Z80_V2_HARDWARE_B_ZX_SPECTRUM_PLUS_2_AND_IF1	4

#define Q_Z80_V3_HARDWARE_A_ZX_SPECTRUM_48K_AND_MGT	3
#define Q_Z80_V3_HARDWARE_A_ZX_SPECTRUM_128K		4

#define Q_Z80_V3_HARDWARE_B_ZX_SPECTRUM_PLUS_2_AND_MGT	3
#define Q_Z80_V3_HARDWARE_B_ZX_SPECTRUM_PLUS_2		4

Q_DEFINE_STRICT_STRUCTURE (
	quint16 low_t_state_counter;
	quint8	high_t_state_counter;
	quint8	zero[3];
	quint8	mgt_rom_paged;
	quint8	multiface_rom_paged;
	quint8	memory_type_between_0000_and_1fff;
	quint8	memory_type_between_2000_and_3fff;
	quint16	keyboard_mappings[5];
	quint16	ascii_values[5];
	quint8	mgt_type;
	quint8	disciple_inhibitor_button_state;
	quint8	disciple_inhibitor_button_flag;
	quint8	last_output_to_1ffd;
) QZ80v3ExtendedHeader;

#define Q_Z80_V1_HEADER(	   p) ((QZ80v1Header	       *)(p))
#define Q_Z80_V2_ADDITIONAL_HEADER(p) ((QZ80v2AdditionalHeader *)(p))
#define Q_Z80_V3_EXTENDED_HEADER(  p) ((QZ80v3ExtendedHeader   *)(p))

#endif /* __Q_formats_hardware_snapshot_machine_ZX_Spectrum_Z80_H__ */
