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
#define Q_ZX_SPECTRUM_VIDEO_CHARACTER_RAM_SIZE	  (1024 * 6)
#define Q_ZX_SPECTRUM_VIDEO_ATTRIBUTE_RAM_SIZE	  768

Q_DEFINE_STRICT_STRUCTURE (
	quint8 characters[Q_ZX_SPECTRUM_VIDEO_CHARACTER_RAM_SIZE];
	quint8 attributes[Q_ZX_SPECTRUM_VIDEO_ATTRIBUTE_RAM_SIZE];
) QZXSpectrumVRAM;

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
typedef Q_STRICT_8BIT_FIELD (
	quint8 flash  :1,
	quint8 bright :1,
	quint8 paper  :3,
	quint8 ink    :3
) QZXSpectrumColorAttribute;

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

/* MARK: - I/O ports */

#define Q_ZX_SPECTRUM_IO_PORT_ULA		0x01 /* Read */
#define Q_ZX_SPECTRUM_IO_PORT_KEMPSTON_JOYSTICK	0x1F /* Read */
#define Q_ZX_SPECTRUM_IO_PORT_FULLER_JOYSTICK	0x7F /* Read */
#define Q_ZX_SPECTRUM_IO_PORT_MIKROGEN_JOYSTICK	0xDF /* Read */
#define Q_ZX_SPECTRUM_IO_PORT_MULTI_IO		0xFE /* Read / Write */

#define Q_ZX_SPECTRUM_UNASSIGNED_IO_PORT_INPUT	0xFF

/* ULA IO port
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
   | | | |  |----------+-------+-------+-------+-------+-------|	     | R
   | | | |  | __0_____ |   P   |   O   |   I   |   U   |   Y   |-----------. | E
 N | | | |  |----------+-------+-------+-------+-------+-------|	   | | V
 O | | | |  | _0______ | ENTER |   L   |   K   |   J   |   H   |---------. | | E
 R | | | |  |----------+-------+-------+-------+-------+-------|	 | | | R
 M | | | |  | 0_______ | SPACE | SY/SH |   M   |   N   |   B   |-------. | | | S
 A | | | |  '--------------------------------------------------'       | | | | E
 L | | | |							       | | | | D
   | | | |  .--------------------------.    .-----------------------.  | | | |
 M | | | |  |  ___. __  __    __ . __  /\  /                        |  | | | | M
 A | | | |  | __\ ||  ||__|__|--|||   / / /                         |  | | | | A
 T | | | |  | ZX Spectrum            / / /                          |  | | | | T
 R | | | |  |                       / / /                           |  | | | | R
 I | | | |  '_=====================/ / /===========================_'  | | | | I
 X | | | |  |´ _   _   _   _   _  / / / _   _   _   _   _          `|  | | | | X
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

typedef Q_STRICT_8BIT_FIELD (
	quint8 unused	    :3,
	quint8 mic	    :1,
	quint8 ear	    :1,
	quint8 border_color :3
) QZXSpectrumULAIO;

/* MARK: - Firmware ADC */

#define Q_ZX_SPECTRUM_ADC_TIMING_PILOT 2168
#define Q_ZX_SPECTRUM_ADC_TIMING_SYNC1  667
#define Q_ZX_SPECTRUM_ADC_TIMING_SYNC2  735
#define Q_ZX_SPECTRUM_ADC_TIMING_DATA0  855
#define Q_ZX_SPECTRUM_ADC_TIMING_DATA1 1710
#define Q_ZX_SPECTRUM_ADC_TIMING_TAIL   945

Q_DEFINE_STRICT_STRUCTURE (
	quint8	type;
	quint8	file_name[10];
	quint16	data_size;

	union {	struct {quint16 autostart_line;
			quint16 program_size;
		} program;

		struct {quint8	unused1;
			quint8	variable_name;
			quint16	unused2;
		} array;

		struct {quint16 start_address;
			quint16 unused;
		} code_file;
	} information;

	quint8 checksum;
) QZXSpectrumADCBlockHeader;

#define Q_ZX_SPECTRUM_FAS_BLOCK_HEADER(p) ((QZXSpectrumADCBlockHeader *)(p))

#define Q_ZX_SPECTRUM_ADC_BLOCK_TYPE_PROGRAM	     0
#define Q_ZX_SPECTRUM_ADC_BLOCK_TYPE_NUMBER_ARRAY    1
#define Q_ZX_SPECTRUM_ADC_BLOCK_TYPE_CHARACTER_ARRAY 2
#define Q_ZX_SPECTRUM_ADC_BLOCK_TYPE_CODE_FILE	     3

/* MARK: - State storage type */

typedef struct {
	Q64Bit	 keyboard;
	qboolean flash;

	Q_STRICT_UNION (
		QZXSpectrumULAIO fields;
		quint8		 value;
	) ula_io;
} QZXSpectrumState;

#endif /* __Q_hardware_machine_platform_computer_ZX_Spectrum_H__ */
