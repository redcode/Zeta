/* Z Kit - hardware/machine/computer/ZX Spectrum.h
 _____ ___  ___   ______                  ___
/_   / |  |/  /  /  ___/_________________/  /_______ ________
 /  /__>     <  _\__  \/  _  /  -_/  __/_  __/  _/  /  /     \
/_____/__/|__| /______/  ___/\___/\____/__/ /__/ \____/__/_/_/
                     /__/
Copyright (C) 2006-2020 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_hardware_machine_computer_ZX_Spectrum_H
#define Z_hardware_machine_computer_ZX_Spectrum_H

#include <Z/types/integral.h>
#include <Z/macros/aggregate.h>
#include <Z/macros/language.h>

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

#define Z_ZX_SPECTRUM_SIZE_VIDEO_RAM	       6912
#define Z_ZX_SPECTRUM_SIZE_VIDEO_CHARACTER_RAM 6144
#define Z_ZX_SPECTRUM_SIZE_VIDEO_ATTRIBUTE_RAM	768

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

Z_DEFINE_PACKED_STRUCTURE ({Z_BIT_FIELD(8, 4) (
	zuint8 flash  :1,
	zuint8 bright :1,
	zuint8 paper  :3,
	zuint8 ink    :3
)}, ZZXSpectrumColorAttribute);

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

Z_DEFINE_PACKED_STRUCTURE ({
	zuint8			  characters[Z_ZX_SPECTRUM_SIZE_VIDEO_CHARACTER_RAM];
	ZZXSpectrumColorAttribute attributes[Z_ZX_SPECTRUM_SIZE_VIDEO_ATTRIBUTE_RAM];
}, ZZXSpectrumVRAM);

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

Z_DEFINE_PACKED_STRUCTURE ({Z_BIT_FIELD(8, 4) (
	zuint8 unused	    :3,
	zuint8 mic	    :1,
	zuint8 ear	    :1,
	zuint8 border_color :3
)}, ZZXSpectrumULAIO);

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

Z_DEFINE_PACKED_STRUCTURE ({Z_BIT_FIELD(8, 3) (
	zuint8 one	:1,
	zuint8 ear	:1,
	zuint8 key_mask :6
)}, ZZXSpectrumULAInput);

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

#define Z_ZX_SPECTRUM_KEY_ROW_ENTER	   6
#define Z_ZX_SPECTRUM_KEY_ROW_SHIFT	   0
#define Z_ZX_SPECTRUM_KEY_ROW_SPACE	   7
#define Z_ZX_SPECTRUM_KEY_ROW_0		   4
#define Z_ZX_SPECTRUM_KEY_ROW_1		   3
#define Z_ZX_SPECTRUM_KEY_ROW_2		   3
#define Z_ZX_SPECTRUM_KEY_ROW_3		   3
#define Z_ZX_SPECTRUM_KEY_ROW_4		   3
#define Z_ZX_SPECTRUM_KEY_ROW_5		   3
#define Z_ZX_SPECTRUM_KEY_ROW_6		   4
#define Z_ZX_SPECTRUM_KEY_ROW_7		   4
#define Z_ZX_SPECTRUM_KEY_ROW_8		   4
#define Z_ZX_SPECTRUM_KEY_ROW_9		   4
#define Z_ZX_SPECTRUM_KEY_ROW_A		   1
#define Z_ZX_SPECTRUM_KEY_ROW_B		   7
#define Z_ZX_SPECTRUM_KEY_ROW_C		   0
#define Z_ZX_SPECTRUM_KEY_ROW_D		   1
#define Z_ZX_SPECTRUM_KEY_ROW_E		   2
#define Z_ZX_SPECTRUM_KEY_ROW_F		   1
#define Z_ZX_SPECTRUM_KEY_ROW_G		   1
#define Z_ZX_SPECTRUM_KEY_ROW_H		   6
#define Z_ZX_SPECTRUM_KEY_ROW_I		   5
#define Z_ZX_SPECTRUM_KEY_ROW_J		   6
#define Z_ZX_SPECTRUM_KEY_ROW_K		   6
#define Z_ZX_SPECTRUM_KEY_ROW_L		   6
#define Z_ZX_SPECTRUM_KEY_ROW_M		   7
#define Z_ZX_SPECTRUM_KEY_ROW_N		   7
#define Z_ZX_SPECTRUM_KEY_ROW_O		   5
#define Z_ZX_SPECTRUM_KEY_ROW_P		   5
#define Z_ZX_SPECTRUM_KEY_ROW_Q		   2
#define Z_ZX_SPECTRUM_KEY_ROW_R		   2
#define Z_ZX_SPECTRUM_KEY_ROW_S		   1
#define Z_ZX_SPECTRUM_KEY_ROW_T		   2
#define Z_ZX_SPECTRUM_KEY_ROW_U		   5
#define Z_ZX_SPECTRUM_KEY_ROW_V		   0
#define Z_ZX_SPECTRUM_KEY_ROW_W		   2
#define Z_ZX_SPECTRUM_KEY_ROW_X		   0
#define Z_ZX_SPECTRUM_KEY_ROW_Y		   5
#define Z_ZX_SPECTRUM_KEY_ROW_Z		   0
#define Z_ZX_SPECTRUM_KEY_ROW_SYMBOL_SHIFT 7

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

/* MARK: - Firmware ADC
.--------------------------------------------------------.
|							 |
| High  _______		_______				 |
|      | Pulse | Pulse | Pulse | Pulse      Square wave  |
|      |       |_______|       |_______ ...		 |
| Low							 |
|							 |
|--------------------------------------------------------|
| 1) Pilot						 |
|  ______						 |
| | 2168 | 2168  x 8063 times (if block contains header) |
| |	 |______ x 3223 times (if block contains data)	 |
|							 |
|--------------------------------------------------------|
| 2) Sync						 |
|  _____						 |
| | 667 |  735						 |
| |     |_______					 |
|							 |
|--------------------------------------------------------|
| 3) Pause						 |
|							 |
|	     1 second					 |
| ______________________________			 |
|							 |
'-------------------------------------------------------*/

#define Z_ZX_SPECTRUM_ADC_PULSES_PER_HEADER_PILOT     8063 /* 5 seconds */
#define Z_ZX_SPECTRUM_ADC_PULSES_PER_DATA_PILOT	      3223 /* 2 seconds */
#define Z_ZX_SPECTRUM_ADC_CYCLES_PER_PILOT_PULSE      2168 /*  807.2 Hz */
#define Z_ZX_SPECTRUM_ADC_CYCLES_PER_SYNC_HIGH_PULSE   667 /* 2623.7 Hz */
#define Z_ZX_SPECTRUM_ADC_CYCLES_PER_SYNC_LOW_PULSE    735 /* 2381   Hz */
#define Z_ZX_SPECTRUM_ADC_CYCLES_PER_BIT_0_PULSE       855 /* 2046.8 Hz */
#define Z_ZX_SPECTRUM_ADC_CYCLES_PER_BIT_1_PULSE      1710 /* 1023.4 Hz */
#define Z_ZX_SPECTRUM_ADC_CYCLES_PER_TAIL	       945
#define Z_ZX_SPECTRUM_ADC_CYCLES_PER_PAUSE	   3500000
#define Z_ZX_SPECTRUM_ADC_CYCLES_PER_HEADER_PILOT 17482752 /* 2168 * 8064 */
#define Z_ZX_SPECTRUM_ADC_CYCLES_PER_DATA_PILOT	   6989632 /* 2168 * 3224 */
#define Z_ZX_SPECTRUM_ADC_BLOCK_CONTENT_HEADER		 0
#define Z_ZX_SPECTRUM_ADC_BLOCK_CONTENT_DATA	       255

Z_DEFINE_PACKED_STRUCTURE ({
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
}, ZZXSpectrumADCBlockHeader);

#define Z_ZX_SPECTRUM_ADC_BLOCK_TYPE_PROGRAM	     0
#define Z_ZX_SPECTRUM_ADC_BLOCK_TYPE_NUMBER_ARRAY    1
#define Z_ZX_SPECTRUM_ADC_BLOCK_TYPE_CHARACTER_ARRAY 2
#define Z_ZX_SPECTRUM_ADC_BLOCK_TYPE_CODE_FILE	     3

/* MARK: - ZX Spectrum

.---------------------------------.
| Model name: ZX Spectrum	  |
|     Vendor: Sinclair Research	  |
|   Released: 1982-04-23	  |
|	 CPU: Zilog Z80 @ 3.5 MHz |
|	 ROM: 16K		  |
|	 RAM: 16K / 48K		  |
|      Sound: Internal speaker	  |
'---------------------------------'
 __________________________________________________
|  ___. __  _	  __ . __			   |
| __\ ||  ||__|__|--|||				   |
| ZX Spectrum					   |
|						   |
| ________________________________________________ |
|/________________________________________________\|
|  _   _   _   _   _   _   _   _   _   _	   |
| [1] [2] [3] [4] [5] [6] [7] [8] [9] [0]	   |
|     _   _   _   _   _   _   _   _   _   _	   |
|    [Q] [W] [E] [R] [T] [Y] [U] [I] [O] [P]	  /|
|	_   _	_   _	_   _	_   _	_   _____//|
|      [A] [S] [D] [F] [G] [H] [J] [K] [L] [ENTER]/|
|  _____   _   _   _   _   _   _   _   __   ___////|
| [SHIFT] [Z] [X] [C] [V] [B] [N] [M] [SS] [SPACE] |
|____________________________________________////__|
(__________________________________________________)

.---------------------------------.
| Model name: ZX Spectrum +	  |
|     Vendor: Sinclair Research	  |
|   Released: 1984-10		  |
|	 CPU: Zilog Z80 @ 3.5 MHz |
|	 ROM: 16K		  |
|	 RAM: 48K		  |
|      Sound: Internal speaker	  |
'---------------------------------'
 ____________________________				  ___________
|  ___. __  _	  __ . __    '''''''''''''''''''''''''''''	     |
| __\ ||  ||__|__|--|||						     |
|--------------------------------------------------------------------|
| ZX Spectrum +							     |
|--.-----------------------------------------------------.-----------|
|  |( )|( )|(1)|(2)|(3)|(4)|(5)|(6)|(7)|(1)|(1)|(1)|(BRK)|	     |
|--|-----------------------------------------------------|-----------|
|  |(DEL)|(1)|(Q)|(W)|(E)|(R)|(T)|(Y)|(U)|(I)|(O)|(P)|.-.|	     |
|--|-------------------------------------------------|| ||-----------|
|  |(EXT)|(ED)|(A)|(S)|(D)|(F)|(G)|(H)|(J)|(K)|(L)|(____'|	     |
|--|-----------------------------------------------------|-----------|
|  |(CAPS S)|( )|(Z)|(X)|(C)|(V)|(B)|(N)|(M)|(.)|(CAPS S)|	     |
|--|-----------------------------------------------------|-----------|
|  |( )|(;)|(")|(_)|(_)|(_______________)|(_)|(_)|(,)|(_)|	//// |
|--'-----------------------------------------------------'-----------|
|____________________________________________________________________| */

/* MARK: - ZX Spectrum - Memory */

#define Z_ZX_SPECTRUM_SIZE_ROM	      16384 /* 1024 * 16	*/
#define Z_ZX_SPECTRUM_16K_SIZE_RAM    16384 /* 1024 * 16	*/
#define Z_ZX_SPECTRUM_16K_SIZE_MEMORY 32768 /* 1024 * (16 + 16)	*/
#define Z_ZX_SPECTRUM_48K_SIZE_RAM    49152 /* 1024 * 48	*/
#define Z_ZX_SPECTRUM_48K_SIZE_MEMORY 65536 /* 1024 * (16 + 48) */

/* MARK: - Screen
				     ---
       Invisible Top Border	      | 8
.---------------------------------.  ---   ---
|	Visible Top Border	  |   | 48  |
|----.-----------------------.----|  ---    |
|L   |			     |R   |   |	    |
|e   |			     |i   |   |	    |
|f  B|			     |g  B|   |	    |
|t  o|	       Paper	     |h  o|   | 192 | 296
|   r|			     |t  r|   |	    |
|   d|			     |   d|   |	    |
|   e|			     |   e|   |	    |
|   r|			     |   r|   |	    |
|----'-----------------------'----|  ---    |
|	   Bottom Border	  |   | 56  |
'---------------------------------'  ---   ---

|----|-----------------------|----|
  48		256	       48
|---------------------------------|
		352			*/

#define Z_ZX_SPECTRUM_SCREEN_FPS 			     50
#define Z_ZX_SPECTRUM_SCREEN_WIDTH			    352
#define Z_ZX_SPECTRUM_SCREEN_HEIGHT			    296
#define Z_ZX_SPECTRUM_SCREEN_PIXELS			 104192 /* 352 * 296 */
#define Z_ZX_SPECTRUM_SCREEN_PAPER_WIDTH		    256
#define Z_ZX_SPECTRUM_SCREEN_PAPER_HEIGHT		    192
#define Z_ZX_SPECTRUM_SCREEN_PAPER_PIXELS		  49152	/* 256 * 192 */
#define Z_ZX_SPECTRUM_SCREEN_TOP_BORDER_HEIGHT		     56
#define Z_ZX_SPECTRUM_SCREEN_INVISIBLE_TOP_BORDER_HEIGHT      8
#define Z_ZX_SPECTRUM_SCREEN_VISIBLE_TOP_BORDER_HEIGHT	     48
#define Z_ZX_SPECTRUM_SCREEN_BOTTOM_BORDER_HEIGHT	     56
#define Z_ZX_SPECTRUM_SCREEN_LEFT_BORDER_WIDTH		     48
#define Z_ZX_SPECTRUM_SCREEN_RIGHT_BORDER_WIDTH		     48

/* MARK: - ZX Spectrum - Timmings */

#define Z_ZX_SPECTRUM_CPU_HZ			     3500000
#define Z_ZX_SPECTRUM_CYCLES_PER_FRAME		       69888
#define Z_ZX_SPECTRUM_CYCLES_PER_SCANLINE		 224
#define Z_ZX_SPECTRUM_CYCLES_PER_HBLANK			  48
#define Z_ZX_SPECTRUM_CYCLES_PER_VBLANK			1792
#define Z_ZX_SPECTRUM_CYCLES_PER_TOP_BORDER_LINE	 176
#define Z_ZX_SPECTRUM_CYCLES_PER_LEFT_BORDER_LINE	  24
#define Z_ZX_SPECTRUM_CYCLES_PER_RIGHT_BORDER_LINE	  24
#define Z_ZX_SPECTRUM_CYCLES_PER_BOTTOM_BORDER_LINE	 176
#define Z_ZX_SPECTRUM_CYCLES_PER_PAPER_LINE		 128
#define Z_ZX_SPECTRUM_CYCLES_PER_INT			  32
#define Z_ZX_SPECTRUM_CYCLES_AT_VBLANK			   0
#define Z_ZX_SPECTRUM_CYCLES_AT_INT			  24
#define Z_ZX_SPECTRUM_CYCLES_AT_INVISIBLE_TOP_BORDER	1792
#define Z_ZX_SPECTRUM_CYCLES_AT_VISIBLE_TOP_BORDER	3584
#define Z_ZX_SPECTRUM_CYCLES_AT_PAPER_REGION	       14336
#define Z_ZX_SPECTRUM_CYCLES_AT_BOTTOM_BORDER	       57344

/* MARK: - ZX Spectrum + 128K

.------------------------------------------------.
| Model name: ZX Spectrum + 128K		 |
|     Vendor: Sinclair Research - Investronica	 |
|   Released: 1985-09				 |
|	 CPU: Zilog Z80 @ 3.5469 MHz		 |
|	 ROM: 48K				 |
|	 RAM: 128K				 |
|      Sound: General Instrument AY-3-8912 (PSG) |
'------------------------------------------------'
 _____________________________				  ________________
|  ___. __  __	  __ . __     ''''''''''''''''''''''''''''	     |====|
| __\ ||  ||__|__|--|||						     |====|
|--------------------------------------------------------------------|====|
| ZX Spectrum +							     |====|
|--.-----------------------------------------------------.-----------|====|
|  |( )|( )|(1)|(2)|(3)|(4)|(5)|(6)|(7)|(1)|(1)|(1)|(BRK)|	     |====|
|--|-----------------------------------------------------|-----------|====|
|  |(DEL)|(1)|(Q)|(W)|(E)|(R)|(T)|(Y)|(U)|(I)|(O)|(P)|.-.|	     |====|
|--|-------------------------------------------------|| ||-----------|====|
|  |(EXT)|(ED)|(A)|(S)|(D)|(F)|(G)|(H)|(J)|(K)|(L)|(____'|	     |====|
|--|-----------------------------------------------------|-----------|====|
|  |(CAPS S)|( )|(Z)|(X)|(C)|(V)|(B)|(N)|(M)|(.)|(CAPS S)|	     |====|
|--|-----------------------------------------------------|-----------|====|
|  |( )|(;)|(")|(_)|(_)|(_______________)|(_)|(_)|(,)|(_)|  128K//// |====|
|--'-----------------------------------------------------'-----------|====|
|____________________________________________________________________|====| */

/* MARK: - ZX Spectrum + 128K: Memory

     .-----------------.
0000 | ROM 0  | ROM 1  | Either ROM may be switched in.
     |	      |	       |
     |	      |	       |
3FFF |	      |	       |
     |--------+--------'
4000 | Bank 5 |
     |	      |
     |	      |
7FFF | screen |
     |--------|
8000 | Bank 2 |        Any one of these pages may be switched in.
     |	      |
     |	      |
BFFF |	      |
     |--------+--------------------------------------------------------------.
C000 | Bank 0 | Bank 1 | Bank 2 | Bank 3 | Bank 4 | Bank 5 | Bank 6 | Bank 7 |
     |	      |	       |(also at|	 |	  |(also at|	    |	     |
     |	      |	       | 8000)  |	 |	  | 4000)  |	    |	     |
FFFF |	      |	       |	|	 |	  | screen |	    | screen |
     '----------------------------------------------------------------------*/

#define Z_ZX_SPECTRUM_PLUS_128K_SIZE_ROM    32768  /* 1024 * 32		*/
#define Z_ZX_SPECTRUM_PLUS_128K_SIZE_RAM    131072 /* 1024 * 128	*/
#define Z_ZX_SPECTRUM_PLUS_128K_SIZE_MEMORY 163840 /* 1024 * (32 + 128) */

/* MARK: - ZX Spectrum + 128K: I/O Ports */

#define Z_ZX_SPECTRUM_PLUS_128K_IO_PORT_BANK_SWITCH 0x7FFD /* Read / Write */
#define Z_ZX_SPECTRUM_PLUS_128K_IO_PORT_PSG	    0xFFFD /* Read / Write */

/* 7FFD - Bank Switch
.-----------------.
| 7 6 5 4 3 2 1 0 |
'-\_/-|-|-|-\___/-'
   |  | | |   '---> user (C000h)
   |  | | '-------> VRAM
   |  | '---------> ROM
   |  '-----------> disable
   '--------------> unused */

Z_DEFINE_PACKED_STRUCTURE ({Z_BIT_FIELD(8, 5) (
	zuint8 unused  :2,
	zuint8 disable :1,
	zuint8 rom     :1,
	zuint8 vram    :1,
	zuint8 user    :3
)}, ZZXSpectrumPlus128KBankSwitch);

/* FFFD - Read/Select */

/* MARK: - ZX Spectrum + 128K: Screen
				     ---
       Invisible Top Border	      | 7
.---------------------------------.  ---   ---
|	Visible Top Border	  |   | 48  |
|----.-----------------------.----|  ---    |
|L   |			     |R	  |   |	    |
|e   |			     |i	  |   |	    |
|f  B|			     |g  B|   |	    |
|t  o|	       Paper	     |h  o|   | 192 | 296
|   r|			     |t  r|   |	    |
|   d|			     |	 d|   |	    |
|   e|			     |	 e|   |	    |
|   r|			     |	 r|   |	    |
|----'-----------------------'----|  ---    |
|	   Bottom Border	  |   | 56  |
'---------------------------------'  ---   ---

|----|-----------------------|----|
  48		256	       48
|---------------------------------|
		352			*/

#define Z_ZX_SPECTRUM_PLUS_128K_SCREEN_TOP_BORDER_HEIGHT	   55
#define Z_ZX_SPECTRUM_PLUS_128K_SCREEN_INVISIBLE_TOP_BORDER_HEIGHT  7
#define Z_ZX_SPECTRUM_PLUS_128K_SCREEN_FPS			   Z_ZX_SPECTRUM_SCREEN_FPS
#define Z_ZX_SPECTRUM_PLUS_128K_SCREEN_WIDTH			   Z_ZX_SPECTRUM_SCREEN_WIDTH
#define Z_ZX_SPECTRUM_PLUS_128K_SCREEN_HEIGHT			   Z_ZX_SPECTRUM_SCREEN_HEIGHT
#define Z_ZX_SPECTRUM_PLUS_128K_SCREEN_PIXELS			   Z_ZX_SPECTRUM_SCREEN_PIXELS
#define Z_ZX_SPECTRUM_PLUS_128K_SCREEN_PAPER_WIDTH		   Z_ZX_SPECTRUM_SCREEN_PAPER_WIDTH
#define Z_ZX_SPECTRUM_PLUS_128K_SCREEN_PAPER_HEIGHT		   Z_ZX_SPECTRUM_SCREEN_PAPER_HEIGHT
#define Z_ZX_SPECTRUM_PLUS_128K_SCREEN_PAPER_PIXELS		   Z_ZX_SPECTRUM_SCREEN_PAPER_PIXELS
#define Z_ZX_SPECTRUM_PLUS_128K_SCREEN_VISIBLE_TOP_BORDER_HEIGHT   Z_ZX_SPECTRUM_SCREEN_VISIBLE_TOP_BORDER_HEIGHT
#define Z_ZX_SPECTRUM_PLUS_128K_SCREEN_BOTTOM_BORDER_HEIGHT	   Z_ZX_SPECTRUM_SCREEN_BOTTOM_BORDER_HEIGHT
#define Z_ZX_SPECTRUM_PLUS_128K_SCREEN_LEFT_BORDER_WIDTH	   Z_ZX_SPECTRUM_SCREEN_LEFT_BORDER_WIDTH
#define Z_ZX_SPECTRUM_PLUS_128K_SCREEN_RIGHT_BORDER_WIDTH	   Z_ZX_SPECTRUM_SCREEN_RIGHT_BORDER_WIDTH

/* MARK: - ZX Spectrum + 128K: Timmings */

#define Z_ZX_SPECTRUM_PLUS_128K_CPU_HZ			       3546900
#define Z_ZX_SPECTRUM_PLUS_128K_PSG_HZ			       1773400
#define Z_ZX_SPECTRUM_PLUS_128K_CYCLES_PER_FRAME		 70908
#define Z_ZX_SPECTRUM_PLUS_128K_CYCLES_PER_SCANLINE		   228
#define Z_ZX_SPECTRUM_PLUS_128K_CYCLES_PER_HBLANK		    52
#define Z_ZX_SPECTRUM_PLUS_128K_CYCLES_PER_VBLANK		  1824
#define Z_ZX_SPECTRUM_PLUS_128K_CYCLES_AT_INVISIBLE_TOP_BORDER	  1824
#define Z_ZX_SPECTRUM_PLUS_128K_CYCLES_AT_VISIBLE_TOP_BORDER	  3420
#define Z_ZX_SPECTRUM_PLUS_128K_CYCLES_AT_PAPER_REGION		 14364
#define Z_ZX_SPECTRUM_PLUS_128K_CYCLES_AT_BOTTOM_BORDER		 58140
#define Z_ZX_SPECTRUM_PLUS_128K_CYCLES_PER_TOP_BORDER_LINE     Z_ZX_SPECTRUM_CYCLES_PER_TOP_BORDER_LINE
#define Z_ZX_SPECTRUM_PLUS_128K_CYCLES_PER_LEFT_BORDER_LINE    Z_ZX_SPECTRUM_CYCLES_PER_LEFT_BORDER_LINE
#define Z_ZX_SPECTRUM_PLUS_128K_CYCLES_PER_RIGHT_BORDER_LINE   Z_ZX_SPECTRUM_CYCLES_PER_RIGHT_BORDER_LINE
#define Z_ZX_SPECTRUM_PLUS_128K_CYCLES_PER_BOTTOM_BORDER_LINE  Z_ZX_SPECTRUM_CYCLES_PER_BOTTOM_BORDER_LINE
#define Z_ZX_SPECTRUM_PLUS_128K_CYCLES_PER_PAPER_LINE	       Z_ZX_SPECTRUM_CYCLES_PER_PAPER_LINE
#define Z_ZX_SPECTRUM_PLUS_128K_CYCLES_PER_INT		       Z_ZX_SPECTRUM_CYCLES_PER_INT
#define Z_ZX_SPECTRUM_PLUS_128K_CYCLES_AT_VBLANK	       Z_ZX_SPECTRUM_CYCLES_AT_VBLANK
#define Z_ZX_SPECTRUM_PLUS_128K_CYCLES_AT_INT		       Z_ZX_SPECTRUM_CYCLES_AT_INT




#define Z_INVES_SPECTRUM_PLUS_SIZE_MEMORY	    (1024 * 16 + 1024 * 48)
#define Z_INVES_SPECTRUM_PLUS_FIRMWARE_BASE_ADDRESS 0
#define Z_INVES_SPECTRUM_PLUS_SIZE_FIRMWARE	    (1024 * 16)

/* MARK: - Timmings */

#define Z_INVES_SPECTRUM_PLUS_MASTER_CLOCK_HZ 177345
#define Z_INVES_SPECTRUM_PLUS_CPU_HZ	      3546900

/* MARK: - Inves Spectrum +

.--------------------------------------.
| Model name: Inves Spectrum +	       |
|     Vendor: Investronica	       |
|   Released: 1986		       |
|	 CPU: Zilog Z80-A @ 3.5469 MHz |
|	 ROM: 48K		       |
|	 RAM: 128K		       |
|      Sound: Internal speaker	       |
'--------------------------------------'
 _____________________________				  ___________
|    .	 _    _  __	      ''''''''''''''''''''''''''''	     |
| __/\__| |\/|/__\						     |
|--------------------------------------------------------------------|
|	 Spectrum +						     |
|--.-----------------------------------------------------.-----------|
|  |( )|( )|(1)|(2)|(3)|(4)|(5)|(6)|(7)|(1)|(1)|(1)|(BRK)|	     |
|--|-----------------------------------------------------|-----------|
|  |(DEL)|(1)|(Q)|(W)|(E)|(R)|(T)|(Y)|(U)|(I)|(O)|(P)|.-.|	     |
|--|-------------------------------------------------|| ||-----------|
|  |(EXT)|(ED)|(A)|(S)|(D)|(F)|(G)|(H)|(J)|(K)|(L)|(____'|	     |
|--|-----------------------------------------------------|-----------|
|  |(  /\  )|( )|(Z)|(X)|(C)|(V)|(B)|(N)|(M)|(.)|(  /\  )|	     |
|--|-----------------------------------------------------|-----------|
|  |( )|(;)|(")|(<)|(>)|(_______________)|(A)|(V)|(,)|(_)|	     |
|--'-----------------------------------------------------'-----------|
|____________________________________________________________________| */


#endif /* Z_hardware_machine_computer_ZX_Spectrum_H */
