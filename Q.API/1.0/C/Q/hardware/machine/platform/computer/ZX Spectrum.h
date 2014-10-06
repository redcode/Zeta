/* Q API - hardware/machine/platform/computer/ZX Spectrum.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2014 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_hardware_machine_platform_computer_ZX_Spectrum_H__
#define __Q_hardware_machine_platform_computer_ZX_Spectrum_H__

#include <Q/types/base.h>
#include <Q/macros/bit field.h>

/* MARK: - Memory Structure
.-------------------------------------.
| Type | Location  | Content	      |
|------+-----------+------------------|
| ROM  | 0000-3FFF | Firmware	      |
|------+-----------+------------------|
| VRAM | 4000-57FF | Video Characters |
|      | 5800-5AFF | Video Attributes |
|------+-----------+------------------|
| RAM  | 5B00-FFFF | User programs    |
'------------------------------------*/

#define Q_ZX_SPECTRUM_ADDRESS_ROM		  0x0000
#define Q_ZX_SPECTRUM_ADDRESS_RAM		  0x4000
#define Q_ZX_SPECTRUM_ADDRESS_VIDEO_CHARACTER_RAM 0x4000
#define Q_ZX_SPECTRUM_ADDRESS_VIDEO_ATTRIBUTE_RAM 0x5800
#define Q_ZX_SPECTRUM_ADDRESS_USER_PROGRAMS	  0x5B00

#define Q_ZX_SPECTRUM_VIDEO_RAM_SIZE		  ((1024 * 6) + 768)
#define Q_ZX_SPECTRUM_VIDEO_CHARACTER_RAM_SIZE	   (1024 * 6)
#define Q_ZX_SPECTRUM_VIDEO_ATTRIBUTE_RAM_SIZE			768

/* MARK: - Video

 0  1  2	    29 30 31
.---------------------------.
|  |  |  |   ...   |  |  |  | 0
|--+--+--|	   |--+--+--|
|  |  |  |   ...   |  |  |  | 1
|--+--+--|	   |--+--+--|
|  |  |  |   ...   |  |  |  | 3
|--------'	   '--------|
|   ...		      ...   |
|   ...		      ...   |
|   ...		      ...   |
|--------.	   .--------|
|  |  |  |   ...   |  |  |  | 21
|--+--+--|	   |--+--+--|
|  |  |  |   ...   |  |  |  | 22
|--+--+--|	   |--+--+--|
|  |  |  |   ...   |  |  |  | 23
'--------------------------*/

/* Color Attribute
.-----------------.
| 7 6 5 4 3 2 1 0 |
'-|-|-\___/-\___/-'
  | |   |     '---> ink ----------------.
  | |   '---------> paper --------.	|
  | '-------------> bright ----.  |	|
  '---------------> flash ---. |  |	|
			     | |  |	|
     .-----------------------' |  |	|
     |		    .----------'  |	|
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
Q_DEFINE_STRICT_STRUCTURE (Q_8BIT_FIELD(4) (
	quint8 flash  :1,
	quint8 bright :1,
	quint8 paper  :3,
	quint8 ink    :3
)) QZXSpectrumColorAttribute;

#define Q_ZX_SPECTRUM_COLOR_BLACK   0
#define Q_ZX_SPECTRUM_COLOR_BLUE    1
#define Q_ZX_SPECTRUM_COLOR_RED     2
#define Q_ZX_SPECTRUM_COLOR_MAGENTA 3
#define Q_ZX_SPECTRUM_COLOR_GREEN   4
#define Q_ZX_SPECTRUM_COLOR_CYAN    5
#define Q_ZX_SPECTRUM_COLOR_YELLOW  6
#define Q_ZX_SPECTRUM_COLOR_WHITE   7

#define Q_ZX_SPECTRUM_ATTRIBUTE_SQUARE_WIDTH  8
#define Q_ZX_SPECTRUM_ATTRIBUTE_SQUARE_HEIGHT 8

#define Q_ZX_SPECTRUM_BRIGHT_COLOR_PALETTE(RGB)	 \
	RGB(0.0, 0.0, 0.0), /* Bright Black   */ \
	RGB(0.0, 0.0, 0.0), /* Bright Black   */ \
	RGB(0.0, 0.0, 1.0), /* Bright Blue    */ \
	RGB(1.0, 0.0, 0.0), /* Bright Red     */ \
	RGB(1.0, 0.0, 1.0), /* Bright Magenta */ \
	RGB(0.0, 1.0, 0.0), /* Bright Green   */ \
	RGB(0.0, 1.0, 1.0), /* Bright Cyan    */ \
	RGB(1.0, 1.0, 0.0), /* Bright Yellow  */ \
	RGB(1.0, 1.0, 1.0)  /* Bright White   */

#define Q_ZX_SPECTRUM_BASIC_COLOR_PALETTE(RGB)	   \
	RGB(0.0,  0.0,	0.0 ), /* Black		*/ \
	RGB(0.0,  0.0,	0.84), /* Basic Blue	*/ \
	RGB(0.84, 0.0,	0.0 ), /* Basic Red	*/ \
	RGB(0.84, 0.0,	0.84), /* Basic Magenta */ \
	RGB(0.0,  0.84, 0.0 ), /* Basic Green	*/ \
	RGB(0.0,  0.84, 0.84), /* Basic Cyan	*/ \
	RGB(0.84, 0.84, 0.0 ), /* Basic Yellow	*/ \
	RGB(0.84, 0.84, 0.84)  /* Basic White	*/

Q_DEFINE_STRICT_STRUCTURE (
	quint8			  characters[Q_ZX_SPECTRUM_VIDEO_CHARACTER_RAM_SIZE];
	QZXSpectrumColorAttribute attributes[Q_ZX_SPECTRUM_VIDEO_ATTRIBUTE_RAM_SIZE];
) QZXSpectrumVRAM;

/* MARK: - I/O ports */

#define Q_ZX_SPECTRUM_IO_PORT_ULA		0x01 /* Read */
#define Q_ZX_SPECTRUM_IO_PORT_KEMPSTON_JOYSTICK	0x1F /* Read */
#define Q_ZX_SPECTRUM_IO_PORT_FULLER_JOYSTICK	0x7F /* Read */
#define Q_ZX_SPECTRUM_IO_PORT_MIKROGEN_JOYSTICK	0xDF /* Read */
#define Q_ZX_SPECTRUM_IO_PORT_MULTI_IO		0xFE /* Read / Write */

#define Q_ZX_SPECTRUM_UNASSIGNED_IO_PORT_INPUT	0xFF

/* MARK: - ULA IO port
.-----------------.-----------------.
| 7 6 5 4 3 2 1 0 | 7 6 5 4 3 2 1 0 |
'-\_____________/-'-\___/-|-|-\___/-'
	 |	      |   | |   '---> border color
  Keyboard (Read)     |   | '-------> MIC / tape output
	 |	      |   '---------> EAR output / speaker
	 '-------.    '-------------> unused
		 |
                 V
	      76543210     4       3       2       1       0
	    .--------------------------------------------------.
   .--------| _______0 | SHIFT |   Z   |   X   |   C   |   V   |
   |	    |----------+-------+-------+-------+-------+-------|
   | .------| ______0_ |   A   |   S   |   D   |   F   |   G   |
   | |      |----------+-------+-------+-------+-------+-------|
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
 A | | | |  .--------------------------.    .-----------------------.  | | | |
 T | | | |  |  ___. __  _     __ . __  /\  /                        |  | | | | M
 R | | | |  | __\ ||  ||__|__|--|||   / / /                         |  | | | | A
 I | | | |  | ZX Spectrum            / / /                          |  | | | | T
 X | | | |  |                       / / /                           |  | | | | R
   | | | |  '_=====================/ / /===========================_'  | | | | I
   | | | |  |´ _   _   _   _   _  / / / _   _   _   _   _          `|  | | | | X
   | | | '--> [1] [2] [3] [4] [5] \/  \[6] [7] [8] [9] [0] <-----------------'
   | | |    |     _   _   _   _   _\   \   _   _   _   _   _        |  | | |
   | | '-------> [Q] [W] [E] [R] [T]\   \ [Y] [U] [I] [O] [P] <------------'
   | |      |       _   _   _   _   _\   \   _   _   _   _   _____//|  | |
   | '-----------> [A] [S] [D] [F] [G]\   \ [H] [J] [K] [L] [ENTER] <----'
   |        |  _____   _   _   _   _  /\  / _   _   _   __   ___////|  |
   '--------> [SHIFT] [Z] [X] [C] [V]/ / / [B] [N] [M] [SS] [SPACE] <--'
            |_______________________/ / /_____________________////__|
            (_______________________\/  \___________________________)

.------------------------------------.
|	     Special Keys	     |
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

Q_DEFINE_STRICT_STRUCTURE (Q_8BIT_FIELD(4) (
	quint8 unused	    :3,
	quint8 mic	    :1,
	quint8 ear	    :1,
	quint8 border_color :3
)) QZXSpectrumULAIO;

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

#define Q_ZX_SPECTRUM_ADC_PULSES_PER_HEADER_PILOT	8064 /* 5 seconds */
#define Q_ZX_SPECTRUM_ADC_PULSES_PER_DATA_PILOT		3224 /*	2 seconds */
#define Q_ZX_SPECTRUM_ADC_CYCLES_PER_PILOT_PULSE	2168 /*  807.2 Hz */
#define Q_ZX_SPECTRUM_ADC_CYCLES_PER_SYNC_HIGH_PULSE	 667 /* 2623.7 Hz */
#define Q_ZX_SPECTRUM_ADC_CYCLES_PER_SYNC_LOW_PULSE	 735 /* 2381   Hz */
#define Q_ZX_SPECTRUM_ADC_CYCLES_PER_BIT_0_PULSE	 855 /* 2046.8 Hz */
#define Q_ZX_SPECTRUM_ADC_CYCLES_PER_BIT_1_PULSE	1710 /* 1023.4 Hz */
#define Q_ZX_SPECTRUM_ADC_CYCLES_PER_TAIL		 945
#define Q_ZX_SPECTRUM_ADC_CYCLES_PER_PAUSE	     3500000
#define Q_ZX_SPECTRUM_ADC_CYCLES_PER_HEADER_PILOT    (Q_ZX_SPECTRUM_ADC_CYCLES_PER_PILOT_PULSE * 8064)
#define Q_ZX_SPECTRUM_ADC_CYCLES_PER_DATA_PILOT	     (Q_ZX_SPECTRUM_ADC_CYCLES_PER_PILOT_PULSE * 3224)

#define Q_ZX_SPECTRUM_ADC_BLOCK_CONTENT_HEADER   0
#define Q_ZX_SPECTRUM_ADC_BLOCK_CONTENT_DATA   255

Q_DEFINE_STRICT_STRUCTURE (
	quint8	type;
	quint8	file_name[10];
	quint16	data_size;

	union {	struct {quint16 autostart_line;
			quint16 size;
		} program;

		struct {quint8	unused1;
			quint8	variable_name;
			quint16	unused2;
		} array;

		struct {quint16 start_address;
			quint16 unused;
		} code_file;
	} parameters;

	quint8 checksum;
) QZXSpectrumADCBlockHeader;

#define Q_ZX_SPECTRUM_ADC_BLOCK_HEADER(p) ((QZXSpectrumADCBlockHeader *)(p))

#define Q_ZX_SPECTRUM_ADC_BLOCK_TYPE_PROGRAM	     0
#define Q_ZX_SPECTRUM_ADC_BLOCK_TYPE_NUMBER_ARRAY    1
#define Q_ZX_SPECTRUM_ADC_BLOCK_TYPE_CHARACTER_ARRAY 2
#define Q_ZX_SPECTRUM_ADC_BLOCK_TYPE_CODE_FILE	     3

/* MARK: - State storage type */

typedef struct {
	Q64Bit	 keyboard;
	qboolean flash;

	union {	QZXSpectrumULAIO fields;
		quint8		 value;
	} ula_io;
} QZXSpectrumState;

#endif /* __Q_hardware_machine_platform_computer_ZX_Spectrum_H__ */
