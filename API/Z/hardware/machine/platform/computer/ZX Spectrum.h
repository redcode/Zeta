/* Z Kit - hardware/machine/platform/computer/ZX Spectrum.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_hardware_machine_platform_computer_ZX_Spectrum_H_
#define _Z_hardware_machine_platform_computer_ZX_Spectrum_H_

#include <Z/types/base.h>

/* MARK: - Memory map
.-------------------------------------.
| Location  | Type | Content	      |
|-----------+------+------------------|
| 0000-3FFF | ROM  | Firmware	      |
|-----------+------+------------------|
| 4000-57FF | VRAM | Video Characters |
| 5800-5AFF | VRAM | Video Attributes |
|-----------+------+------------------|
| 5B00-FFFF | RAM  | User programs    |
'------------------------------------*/

#define Z_ZX_SPECTRUM_ADDRESS_ROM		  0x0000
#define Z_ZX_SPECTRUM_ADDRESS_RAM		  0x4000
#define Z_ZX_SPECTRUM_ADDRESS_VIDEO_CHARACTER_RAM 0x4000
#define Z_ZX_SPECTRUM_ADDRESS_VIDEO_ATTRIBUTE_RAM 0x5800
#define Z_ZX_SPECTRUM_ADDRESS_USER_PROGRAMS	  0x5B00

#define Z_ZX_SPECTRUM_SIZE_VIDEO_RAM		  6912
#define Z_ZX_SPECTRUM_SIZE_VIDEO_CHARACTER_RAM	  6144
#define Z_ZX_SPECTRUM_SIZE_VIDEO_ATTRIBUTE_RAM	  768

/* MARK: - Video: Color Attribute
.-----------------.
| 7 6 5 4 3 2 1 0 |
'-|-|-\___/-\___/-'
  | |	|     '---> Ink ----------------.
  | |	'---------> Paper --------.	|
  | '-------------> Bright ---.	  |	|
  '---------------> Flash     |	  |	|
		      |	      |	  |	|
     .----------------'	      |	  |	|
     |		    .---------'	  |	|
     |		    |		  |	|
     v		    v		  v	v
.---------.  .------------.  .---------------.
| 0 = NO  |  | 0 = Normal |  | 000 = Black   |
| 1 = YES |  | 1 = Bright |  | 001 = Blue    |
'---------'  '------------'  | 010 = Red     |
			     | 011 = Magenta |
			     | 100 = Green   |
			     | 101 = Cyan    |
			     | 110 = Yellow  |
			     | 111 = White   |
			     '--------------*/

#define Z_ZX_SPECTRUM_COLOR_BLACK   0
#define Z_ZX_SPECTRUM_COLOR_BLUE    1
#define Z_ZX_SPECTRUM_COLOR_RED	    2
#define Z_ZX_SPECTRUM_COLOR_MAGENTA 3
#define Z_ZX_SPECTRUM_COLOR_GREEN   4
#define Z_ZX_SPECTRUM_COLOR_CYAN    5
#define Z_ZX_SPECTRUM_COLOR_YELLOW  6
#define Z_ZX_SPECTRUM_COLOR_WHITE   7

Z_DEFINE_STRICT_STRUCTURE (Z_BIT_FIELD(8, 4) (
	zuint8 flash  :1,
	zuint8 bright :1,
	zuint8 paper  :3,
	zuint8 ink    :3
)) ZZXSpectrumColorAttribute;

#define Z_ZX_SPECTRUM_ATTRIBUTE_SQUARE_WIDTH  8
#define Z_ZX_SPECTRUM_ATTRIBUTE_SQUARE_HEIGHT 8

#define Z_ZX_SPECTRUM_BRIGHT_COLOR_PALETTE(RGB)	 \
	RGB(0.0, 0.0, 0.0), /* Bright Black   */ \
	RGB(0.0, 0.0, 0.0), /* Bright Black   */ \
	RGB(0.0, 0.0, 1.0), /* Bright Blue    */ \
	RGB(1.0, 0.0, 0.0), /* Bright Red     */ \
	RGB(1.0, 0.0, 1.0), /* Bright Magenta */ \
	RGB(0.0, 1.0, 0.0), /* Bright Green   */ \
	RGB(0.0, 1.0, 1.0), /* Bright Cyan    */ \
	RGB(1.0, 1.0, 0.0), /* Bright Yellow  */ \
	RGB(1.0, 1.0, 1.0)  /* Bright White   */

#define Z_ZX_SPECTRUM_BASIC_COLOR_PALETTE(RGB)	   \
	RGB(0.0,  0.0,	0.0 ), /* Black		*/ \
	RGB(0.0,  0.0,	0.84), /* Basic Blue	*/ \
	RGB(0.84, 0.0,	0.0 ), /* Basic Red	*/ \
	RGB(0.84, 0.0,	0.84), /* Basic Magenta */ \
	RGB(0.0,  0.84, 0.0 ), /* Basic Green	*/ \
	RGB(0.0,  0.84, 0.84), /* Basic Cyan	*/ \
	RGB(0.84, 0.84, 0.0 ), /* Basic Yellow	*/ \
	RGB(0.84, 0.84, 0.84)  /* Basic White	*/

Z_DEFINE_STRICT_STRUCTURE (
	zuint8			  characters[Z_ZX_SPECTRUM_SIZE_VIDEO_CHARACTER_RAM];
	ZZXSpectrumColorAttribute attributes[Z_ZX_SPECTRUM_SIZE_VIDEO_ATTRIBUTE_RAM];
) ZZXSpectrumVRAM;

/* MARK: - I/O ports */

#define Z_ZX_SPECTRUM_IO_PORT_ULA		0x01 /* Read */
#define Z_ZX_SPECTRUM_IO_PORT_KEMPSTON_JOYSTICK	0x1F /* Read */
#define Z_ZX_SPECTRUM_IO_PORT_FULLER_JOYSTICK	0x7F /* Read */
#define Z_ZX_SPECTRUM_IO_PORT_MIKROGEN_JOYSTICK	0xDF /* Read */
#define Z_ZX_SPECTRUM_IO_PORT_MULTI_IO		0xFE /* Read / Write */

#define Z_ZX_SPECTRUM_UNASSIGNED_IO_PORT_INPUT	0xFF

/* MARK: - ULA I/O port
.-----------------.-----------------.
| 7 6 5 4 3 2 1 0 | 7 6 5 4 3 2 1 0 |
'-\_____________/-'-\___/-|-|-\___/-'
	 |	      |	  | |   '---> Border color
  Keyboard (Read)     |	  | '-------> MIC / tape output
	 |	      |	  '---------> EAR output / speaker
	 '-------.    '-------------> Unused
		 |
		 V
	      76543210	   0	   1	   2	   3	   4
	    .--------------------------------------------------.
   .--------| _______0 | SHIFT |   Z   |   X   |   C   |   V   |
   |	    |----------+-------+-------+-------+-------+-------|
   | .------| ______0_ |   A   |   S   |   D   |   F   |   G   |
   | |	    |----------+-------+-------+-------+-------+-------|
   | | .----| _____0__ |   Q   |   W   |   E   |   R   |   T   |
   | | |    |----------+-------+-------+-------+-------+-------|
   | | | .--| ____0___ |   1   |   2   |   3   |   4   |   5   |
   | | | |  |----------+-------+-------+-------+-------+-------|
   | | | |  | ___0____ |   0   |   9   |   8   |   7   |   6   |-------------.
 N | | | |  |----------+-------+-------+-------+-------+-------|	     | R
 O | | | |  | __0_____ |   P   |   O   |   I   |   U   |   Y   |-----------. | E
 R | | | |  |----------+-------+-------+-------+-------+-------|	   | | V
 M | | | |  | _0______ | ENTER |   L   |   K   |   J   |   H   |---------. | | E
 A | | | |  |----------+-------+-------+-------+-------+-------|	 | | | R
 L | | | |  | 0_______ | SPACE | SY/SH |   M   |   N   |   B   |-------. | | | S
   | | | |  '--------------------------------------------------'       | | | | E
 M | | | |							       | | | | D
 A | | | |   ____________________________    _______________________   | | | |
 T | | | |  |  ___. __  _     __ . __	/\  /			    |  | | | | M
 R | | | |  | __\ ||  ||__|__|--|||    / / /			    |  | | | | A
 I | | | |  | ZX Spectrum	      / / /			    |  | | | | T
 X | | | |  |			     / / /			    |  | | | | R
   | | | |  | ______________________/ / /__________________________ |  | | | | I
   | | | |  |/_____________________/ / /___________________________\|  | | | | I
   | | | |  |  _   _   _   _   _  / / / _   _	_   _	_	    |  | | | | X
   | | | '--> [1] [2] [3] [4] [5] \/  \[6] [7] [8] [9] [0] <-----------------'
   | | |    |	  _   _   _   _   _\   \   _   _   _   _   _	    |  | | |
   | | '-------> [Q] [W] [E] [R] [T]\	\ [Y] [U] [I] [O] [P] <------------'
   | |	    |	    _	_   _	_   _\	 \   _	 _   _	 _   _____//|  | |
   | '-----------> [A] [S] [D] [F] [G]\	  \ [H] [J] [K] [L] [ENTER] <----'
   |	    |  _____   _   _   _   _  /\  / _	_   _	__   ___////|  |
   '--------> [SHIFT] [Z] [X] [C] [V]/ / / [B] [N] [M] [SS] [SPACE] <--'
	    |_______________________/ / /_____________________////__|
	    (_______________________\/	\___________________________) */

Z_DEFINE_STRICT_STRUCTURE (Z_BIT_FIELD(8, 4) (
	zuint8 unused	    :3,
	zuint8 mic	    :1,
	zuint8 ear	    :1,
	zuint8 border_color :3
)) ZZXSpectrumULAIO;

#define Z_ZX_SPECTRUM_KEY_ROW_ENTER	      6
#define Z_ZX_SPECTRUM_KEY_ROW_SHIFT	      0
#define Z_ZX_SPECTRUM_KEY_ROW_SPACE	      7
#define Z_ZX_SPECTRUM_KEY_ROW_0		      4
#define Z_ZX_SPECTRUM_KEY_ROW_1		      3
#define Z_ZX_SPECTRUM_KEY_ROW_2		      3
#define Z_ZX_SPECTRUM_KEY_ROW_3		      3
#define Z_ZX_SPECTRUM_KEY_ROW_4		      3
#define Z_ZX_SPECTRUM_KEY_ROW_5		      3
#define Z_ZX_SPECTRUM_KEY_ROW_6		      4
#define Z_ZX_SPECTRUM_KEY_ROW_7		      4
#define Z_ZX_SPECTRUM_KEY_ROW_8		      4
#define Z_ZX_SPECTRUM_KEY_ROW_9		      4
#define Z_ZX_SPECTRUM_KEY_ROW_A		      1
#define Z_ZX_SPECTRUM_KEY_ROW_B		      7
#define Z_ZX_SPECTRUM_KEY_ROW_C		      0
#define Z_ZX_SPECTRUM_KEY_ROW_D		      1
#define Z_ZX_SPECTRUM_KEY_ROW_E		      2
#define Z_ZX_SPECTRUM_KEY_ROW_F		      1
#define Z_ZX_SPECTRUM_KEY_ROW_G		      1
#define Z_ZX_SPECTRUM_KEY_ROW_H		      6
#define Z_ZX_SPECTRUM_KEY_ROW_I		      5
#define Z_ZX_SPECTRUM_KEY_ROW_J		      6
#define Z_ZX_SPECTRUM_KEY_ROW_K		      6
#define Z_ZX_SPECTRUM_KEY_ROW_L		      6
#define Z_ZX_SPECTRUM_KEY_ROW_M		      7
#define Z_ZX_SPECTRUM_KEY_ROW_N		      7
#define Z_ZX_SPECTRUM_KEY_ROW_O		      5
#define Z_ZX_SPECTRUM_KEY_ROW_P		      5
#define Z_ZX_SPECTRUM_KEY_ROW_Q		      2
#define Z_ZX_SPECTRUM_KEY_ROW_R		      2
#define Z_ZX_SPECTRUM_KEY_ROW_S		      1
#define Z_ZX_SPECTRUM_KEY_ROW_T		      2
#define Z_ZX_SPECTRUM_KEY_ROW_U		      5
#define Z_ZX_SPECTRUM_KEY_ROW_V		      0
#define Z_ZX_SPECTRUM_KEY_ROW_W		      2
#define Z_ZX_SPECTRUM_KEY_ROW_X		      0
#define Z_ZX_SPECTRUM_KEY_ROW_Y		      5
#define Z_ZX_SPECTRUM_KEY_ROW_Z		      0
#define Z_ZX_SPECTRUM_KEY_ROW_SYMBOL_SHIFT    7

#define Z_ZX_SPECTRUM_KEY_OFFSET_ENTER	      0
#define Z_ZX_SPECTRUM_KEY_OFFSET_SHIFT	      0
#define Z_ZX_SPECTRUM_KEY_OFFSET_SPACE	      0
#define Z_ZX_SPECTRUM_KEY_OFFSET_0	      0
#define Z_ZX_SPECTRUM_KEY_OFFSET_1	      0
#define Z_ZX_SPECTRUM_KEY_OFFSET_2	      1
#define Z_ZX_SPECTRUM_KEY_OFFSET_3	      2
#define Z_ZX_SPECTRUM_KEY_OFFSET_4	      3
#define Z_ZX_SPECTRUM_KEY_OFFSET_5	      4
#define Z_ZX_SPECTRUM_KEY_OFFSET_6	      4
#define Z_ZX_SPECTRUM_KEY_OFFSET_7	      3
#define Z_ZX_SPECTRUM_KEY_OFFSET_8	      2
#define Z_ZX_SPECTRUM_KEY_OFFSET_9	      1
#define Z_ZX_SPECTRUM_KEY_OFFSET_A	      0
#define Z_ZX_SPECTRUM_KEY_OFFSET_B	      4
#define Z_ZX_SPECTRUM_KEY_OFFSET_C	      3
#define Z_ZX_SPECTRUM_KEY_OFFSET_D	      2
#define Z_ZX_SPECTRUM_KEY_OFFSET_E	      2
#define Z_ZX_SPECTRUM_KEY_OFFSET_F	      3
#define Z_ZX_SPECTRUM_KEY_OFFSET_G	      4
#define Z_ZX_SPECTRUM_KEY_OFFSET_H	      4
#define Z_ZX_SPECTRUM_KEY_OFFSET_I	      2
#define Z_ZX_SPECTRUM_KEY_OFFSET_J	      3
#define Z_ZX_SPECTRUM_KEY_OFFSET_K	      2
#define Z_ZX_SPECTRUM_KEY_OFFSET_L	      1
#define Z_ZX_SPECTRUM_KEY_OFFSET_M	      2
#define Z_ZX_SPECTRUM_KEY_OFFSET_N	      3
#define Z_ZX_SPECTRUM_KEY_OFFSET_O	      1
#define Z_ZX_SPECTRUM_KEY_OFFSET_P	      0
#define Z_ZX_SPECTRUM_KEY_OFFSET_Q	      0
#define Z_ZX_SPECTRUM_KEY_OFFSET_R	      3
#define Z_ZX_SPECTRUM_KEY_OFFSET_S	      1
#define Z_ZX_SPECTRUM_KEY_OFFSET_T	      4
#define Z_ZX_SPECTRUM_KEY_OFFSET_U	      3
#define Z_ZX_SPECTRUM_KEY_OFFSET_V	      4
#define Z_ZX_SPECTRUM_KEY_OFFSET_W	      1
#define Z_ZX_SPECTRUM_KEY_OFFSET_X	      2
#define Z_ZX_SPECTRUM_KEY_OFFSET_Y	      4
#define Z_ZX_SPECTRUM_KEY_OFFSET_Z	      1
#define Z_ZX_SPECTRUM_KEY_OFFSET_SYMBOL_SHIFT 1

/* MARK: - ULA I/O port: input value
.-----------------.
| 7 6 5 4 3 2 1 0 |
'-|-|-\_________/-'
  | |	   |
  | |	   '------> Key mask
  | '-------------> EAR input
  '---------------> 1

.------------------------------------.
|	     Special keys	     |
|------------------------------------|
| DELETE      = SHIFT + 0	     |
| EDIT	      = SHIFT + 1	     |
| CAPS LOCK   = SHIFT + 2	     |
| TRUE VIDEO  = SHIFT + 3	     |
| INV VIDEO   = SHIFT + 4	     |
| ↑	      = SHIFT + 7	     |
| ↓	      = SHIFT + 6	     |
| →	      = SHIFT + 5	     |
| ←	      = SHIFT + 8	     |
| GRAPH	      = SHIFT + 9	     |
| BREAK	      = SHIFT + SPACE	     |
| EXTEND MODE = SHIFT + SYMBOL SHIFT |
| .	      = SYMBOL SHIFT + M     |
| ,	      = SYMBOL SHIFT + N     |
| ;	      = SYMBOL SHIFT + O     |
| "	      = SYMBOL SHIFT + P     |
'-----------------------------------*/

Z_DEFINE_STRICT_STRUCTURE (Z_BIT_FIELD(8, 3) (
	zuint8 one	:1,
	zuint8 ear	:1,
	zuint8 key_mask :6
)) ZZXSpectrumULAInput;

#define Z_ZX_SPECTRUM_KEY_MASK_ENTER	    0x0F
#define Z_ZX_SPECTRUM_KEY_MASK_SHIFT	    0x0F
#define Z_ZX_SPECTRUM_KEY_MASK_SPACE	    0x0F
#define Z_ZX_SPECTRUM_KEY_MASK_0	    0x0F
#define Z_ZX_SPECTRUM_KEY_MASK_1	    0x0F
#define Z_ZX_SPECTRUM_KEY_MASK_2	    0x17
#define Z_ZX_SPECTRUM_KEY_MASK_3	    0x1B
#define Z_ZX_SPECTRUM_KEY_MASK_4	    0x1D
#define Z_ZX_SPECTRUM_KEY_MASK_5	    0x1E
#define Z_ZX_SPECTRUM_KEY_MASK_6	    0x1E
#define Z_ZX_SPECTRUM_KEY_MASK_7	    0x1D
#define Z_ZX_SPECTRUM_KEY_MASK_8	    0x1B
#define Z_ZX_SPECTRUM_KEY_MASK_9	    0x17
#define Z_ZX_SPECTRUM_KEY_MASK_A	    0x0F
#define Z_ZX_SPECTRUM_KEY_MASK_B	    0x1E
#define Z_ZX_SPECTRUM_KEY_MASK_C	    0x1D
#define Z_ZX_SPECTRUM_KEY_MASK_D	    0x1B
#define Z_ZX_SPECTRUM_KEY_MASK_E	    0x1B
#define Z_ZX_SPECTRUM_KEY_MASK_F	    0x1D
#define Z_ZX_SPECTRUM_KEY_MASK_G	    0x1E
#define Z_ZX_SPECTRUM_KEY_MASK_H	    0x1E
#define Z_ZX_SPECTRUM_KEY_MASK_I	    0x1B
#define Z_ZX_SPECTRUM_KEY_MASK_J	    0x1D
#define Z_ZX_SPECTRUM_KEY_MASK_K	    0x1B
#define Z_ZX_SPECTRUM_KEY_MASK_L	    0x17
#define Z_ZX_SPECTRUM_KEY_MASK_M	    0x1B
#define Z_ZX_SPECTRUM_KEY_MASK_N	    0x1D
#define Z_ZX_SPECTRUM_KEY_MASK_O	    0x17
#define Z_ZX_SPECTRUM_KEY_MASK_P	    0x0F
#define Z_ZX_SPECTRUM_KEY_MASK_Q	    0x0F
#define Z_ZX_SPECTRUM_KEY_MASK_R	    0x1D
#define Z_ZX_SPECTRUM_KEY_MASK_S	    0x17
#define Z_ZX_SPECTRUM_KEY_MASK_T	    0x1E
#define Z_ZX_SPECTRUM_KEY_MASK_U	    0x1D
#define Z_ZX_SPECTRUM_KEY_MASK_V	    0x1E
#define Z_ZX_SPECTRUM_KEY_MASK_W	    0x17
#define Z_ZX_SPECTRUM_KEY_MASK_X	    0x1B
#define Z_ZX_SPECTRUM_KEY_MASK_Y	    0x1E
#define Z_ZX_SPECTRUM_KEY_MASK_Z	    0x17
#define Z_ZX_SPECTRUM_KEY_MASK_SYMBOL_SHIFT 0x17

/* MARK: - Firmware ADC
.------------------------------------------------------------------------.
|									 |
| High   _____	     _____	 _____					 |
|       |Pulse|     |Pulse|	|Pulse|       Square wave		 |
|	|     |_____|	  |_____|     |______				 |
| Low	       Pulse	   Pulse       Pulse				 |
|									 |
| 1) Pilot								 |
|  ______________							 |
| |	2168	 |     2168      x 8063 times (if block contains header) |
| |		 |______________ x 3223 times (if block contains data)	 |
|									 |
| 2) Sync								 |
|  _____								 |
| | 667 |  735								 |
| |     |_______							 |
|									 |
| 3) Pause								 |
|									 |
|	     1 second							 |
| ______________________________					 |
|									 |
'-----------------------------------------------------------------------*/

#define Z_ZX_SPECTRUM_ADC_PULSES_PER_HEADER_PILOT    8063     /* 5 seconds */
#define Z_ZX_SPECTRUM_ADC_PULSES_PER_DATA_PILOT	     3223     /* 2 seconds */
#define Z_ZX_SPECTRUM_ADC_CYCLES_PER_PILOT_PULSE     2168     /*  807.2 Hz */
#define Z_ZX_SPECTRUM_ADC_CYCLES_PER_SYNC_HIGH_PULSE 667      /* 2623.7 Hz */
#define Z_ZX_SPECTRUM_ADC_CYCLES_PER_SYNC_LOW_PULSE  735      /* 2381   Hz */
#define Z_ZX_SPECTRUM_ADC_CYCLES_PER_BIT_0_PULSE     855      /* 2046.8 Hz */
#define Z_ZX_SPECTRUM_ADC_CYCLES_PER_BIT_1_PULSE     1710     /* 1023.4 Hz */
#define Z_ZX_SPECTRUM_ADC_CYCLES_PER_TAIL	     945
#define Z_ZX_SPECTRUM_ADC_CYCLES_PER_PAUSE	     3500000
#define Z_ZX_SPECTRUM_ADC_CYCLES_PER_HEADER_PILOT    17482752 /* 2168 * 8064 */
#define Z_ZX_SPECTRUM_ADC_CYCLES_PER_DATA_PILOT	     6989632  /* 2168 * 3224 */

#define Z_ZX_SPECTRUM_ADC_BLOCK_CONTENT_HEADER 0
#define Z_ZX_SPECTRUM_ADC_BLOCK_CONTENT_DATA   255

Z_DEFINE_STRICT_STRUCTURE (
	zuint8	type;
	zuint8	file_name[10];
	zuint16	data_size;

	union {	struct {zuint16 autostart_line;
			zuint16 size;
		} program;

		struct {zuint8	unused1;
			zuint8	variable_name;
			zuint16	unused2;
		} array;

		struct {zuint16 start_address;
			zuint16 unused;
		} code_file;
	} parameters;

	zuint8 checksum;
) ZZXSpectrumADCBlockHeader;

#define Z_ZX_SPECTRUM_ADC_BLOCK_TYPE_PROGRAM	     0
#define Z_ZX_SPECTRUM_ADC_BLOCK_TYPE_NUMBER_ARRAY    1
#define Z_ZX_SPECTRUM_ADC_BLOCK_TYPE_CHARACTER_ARRAY 2
#define Z_ZX_SPECTRUM_ADC_BLOCK_TYPE_CODE_FILE	     3

/* MARK: - State storage type */

typedef struct {
	Z64Bit keyboard;
	zuint8 flash;

	union {	ZZXSpectrumULAIO fields;
		zuint8		 value;
	} ula_io;
} ZZXSpectrumState;

#endif /* _Z_hardware_machine_platform_computer_ZX_Spectrum_H_ */
