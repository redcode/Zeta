/* Q API - formats/hardware snapshot/machine/ZX Spectrum/Z80.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2013 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_formats_hardware_snapshot_machine_ZX_Spectrum_Z80_H__
#define __Q_formats_hardware_snapshot_machine_ZX_Spectrum_Z80_H__

#include <Q/types/basics.h>
#include <Q/keys/hardware/machine.h>

typedef Q_STRICT_STRUCTURE (

	quint16 af, bc, hl, pc, sp;
	quint8	i, r;

	struct {quint8 r7			:1;
		quint8 border_color		:3;
		quint8 basic_samrom		:1;
		quint8 data_block_is_compressed :1;
		quint8 unused			:2;
	} bitfield1;

	quint16 de;
	quint16 bc_, de_, hl_, af_;
	quint16 iy, ix;
	quint8 iff1, iff2;

	struct {quint8 im			:2;
		quint8 issue_2_emulation	:1;
		quint8 int_frequency		:1;
		quint8 video_synchronization	:2;
		quint8 joystick_type		:2;
	} bitfield2;

) QZ80v1Header;

#define Q_Z80_V1_HEADER(p) ((QZ80v1Header *)(p))

typedef Q_STRICT_STRUCTURE (

	quint16 pc;
	quint8	hardware_mode;
	quint8	output_state;
	quint8	interface_1_paginated_or_timex_output_state;

	struct {quint8 r_register_emulation	  :1;
		quint8 ldir_instruction_emulation :1;
		quint8 zero			  :5;
		quint8 hardware_modification	  :1;
	} bitfield;

	quint8	last_output_to_fffd;
	quint8	sound_chip_registers;

) QZ80v2AdditionalHeader;

#define Q_Z80_V2_ADDITIONAL_HEADER(p) ((QZ80v2AdditionalHeader *)(p))

typedef Q_STRICT_STRUCTURE (

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

#define Q_Z80_V3_EXTENDED_HEADER(p) ((QZ80v3ExtendedHeader *)(p))

#endif /* __Q_formats_hardware_snapshot_machine_ZX_Spectrum_Z80_H__ */
