/* Q API - formats/storage medium image/audio/TZX.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © Tomaz Kac.
Copyright © Martijn v.d. Heide.
Copyright © Ramsoft.
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3.
 ____________________________
/\			     \
\_| Extensions: .tap, .cdt    |
  | Endianness: Little	      |
  | Created by: Tomaz Kac     |
  | Used by:	Many programs |
  |   ________________________|_
   \_/_________________________/

.------------------------------------------------------------------------------.
| Format revision: v1.20 (2006-12-19)					       |
|									       |
| 1) Introduction							       |
| ---------------							       |
|									       |
|    TZX is a file format designed to preserve all (hopefully) of the tapes    |
| with turbo or custom loading routines. Even though some of the newer and     |
| 'smarter' emulators can find most of the info about the loader from the code |
| itself, this isn't possible if you want to save the file to tape, or to a    |
| real Spectrum.							       |
| And with all this information in the file, the emulators don't have to       |
| bother with finding out the timings and other things.			       |
|									       |
|    This file format is explicitly targeted to the ZX Spectrum compatible     |
| computers only. Specialized versions of the TZX format have been defined for |
| other machines too, e.g. the Amstrad CPC and C64, but they are now available |
| as distinct file formats with other filename extensions.		       |
|									       |
|    At the end of this document you can find a description of encoding	       |
| differences between these machines and a table which displays timings used   |
| by their respective ROM loading routines (some of them are not official).    |
| If you know of any other machines that have similar encoding that could be   |
| represented with this file format then let us know.			       |
|									       |
|    If you're looking for TZX files, you can find an extensive collection at  |
| Martijn van der Heide's 'World of Spectrum': http://www.worldofspectrum.org  |
|									       |
|    The format was first started off by Tomaz Kac who was maintainer until    |
| revision 1.13, and then passed to Martijn v.d. Heide. After that, Ramsoft    |
| were the maintainers for a brief period during which the v1.20 revision was  |
| put together. If you have any questions about the format, visit the forums   |
| at World of Spectrum and ask.						       |
|									       |
|    The default format file extension is "TZX" and hopefully this won't have  |
| to change in the future; for RISC OS the current TAP file type will be used. |
| Amstrad CPC files should use the extension "CDT" to distinguish them  from   |
| the ZX Spectrum files, otherwise the inner structure is totally the same.    |
|									       |
| 2) Rules and definitions						       |
| ------------------------						       |
|									       |
| - Any value requiring more than one byte is stored in little endian format   |
|   (i.e. LSB first).							       |
|									       |
| - All unused bits should be set to zero.				       |
|									       |
| - The timings are given in Z80 clock ticks (T states) unless otherwise       |
|   stated.								       |
|   1 T state = (1/3500000)s						       |
|									       |
| - All ASCII texts use the ISO 8859-1 (Latin 1) encoding; some of them can    |
|   have several lines, which should be separated by ASCII code 13 decimal     |
|   (0Dh).								       |
|									       |
| - You might interpret 'full-period' as ----____ or ____----, and	       |
|   'half-period' as ---- or ____. One 'half-period' will also be referred to  |
|   as a 'pulse'.							       |
|									       |
| - The values in curly brackets {} are the default values that are used in    |
|   the Spectrum ROM saving routines. These values are in decimal.	       |
|									       |
| - If there is no pause between two data blocks then the second one should    |
|   follow immediately; not even so much as one T state between them.	       |
|									       |
| - This document refers to 'high' and 'low' pulse levels. Whether this is     |
|   implemented as EAR=1 and EAR=0 respectively or the other way around is not |
|   important, as long as it is done consistently.			       |
|									       |
| - Zeros and ones in 'Direct recording' blocks mean low and high pulse levels |
|   respectively. The 'current pulse level' after playing a Direct Recording   |
|   block of CSW recording block is the last level played.		       |
|									       |
| - The 'current pulse level' after playing the blocks ID 10,11,12,13,14 or 19 |
|   is the opposite of the last pulse level played, so that a subsequent pulse |
|   will produce an edge.						       |
|									       |
| - A 'Pause' block consists of a 'low' pulse level of some duration.	       |
|   To ensure that the last edge produced is properly finished there should be |
|   at least 1ms pause of the opposite level and only after that the pulse     |
|   should go to 'low'. At the end of a 'Pause' block the 'current pulse       |
|   level' is low (note that the first pulse will therefore not immediately    |
|   produce an edge). A 'Pause' block of zero duration is completely ignored,  |
|   so the 'current pulse level' will NOT change in this case. This also       |
|   applies to 'Data' blocks that have some pause duration included in them.   |
|									       |
| - An emulator should put the 'current pulse level' to 'low' when starting to |
|   play a TZX file, either from the start or from a certain position. The     |
|   writer of a TZX file should ensure that the 'current pulse level' is       |
|   well-defined in every sequence of blocks where this is important, i.e. in  |
|   any sequence that includes a 'Direct recording' block, or that depends on  |
|   edges generated by 'Pause' blocks. The recommended way of doing this is to |
|   include a Pause after each sequence of blocks.			       |
|									       |
| - When creating a 'Direct recording' block please stick to the standard      |
|   sampling frequencies of 22050 or 44100 Hz. This will ensure correct	       |
|   playback when using modern soundcards.				       |
|									       |
| - The length of a block is given in the following format: numbers in square  |
|   brackets [] mean that the value must be read from the offset in the	       |
|   brackets. Other values are normal numbers.				       |
|   Example: [02,03]+0A means: get number (16bit) from offset 02 and add 0A.   |
|   All numbers are in hexadecimal.					       |
|									       |
| - General Extension Rule: ALL custom blocks that will be added after version |
|   1.10 will have the length of the block in first 4 bytes (long word) after  |
|   the ID (this length does not include these 4 length bytes). This should    |
|   enable programs that can only handle older versions to skip that block.    |
|									       |
| - Just in case:							       |
|   MSB = most significant byte						       |
|   LSB = least significant byte					       |
|   MSb = most significant bit						       |
|   LSb = least significant bit						       |
'-----------------------------------------------------------------------------*/

#ifndef __Q_formats_storage_medium_image_audio_TZX_H__
#define __Q_formats_storage_medium_image_audio_TZX_H__

#include <Q/types/base.h>

/* MARK: - File Header
.--------------------------------------------------------------------------.
| The file is identified with the first 8 bytes being 'ZXTape!' plus the   |
| 'end of file' byte 26 (1Ah). This is followed by two bytes containing    |
| the major and minor version numbers.					   |
|									   |
| To be able to use a TZX file, your program must be able to handle files  |
| of at least its major version number. If your program can handle (say)   |
| version 1.05 and you encounter a file with version number 1.06, your     |
| program must be able to handle it, even if it cannot handle all the data |
| in the file.								   |
|									   |
| Then the main body of the file follows. It consists of a mixture of	   |
| blocks, each preceded and identified by an ID byte.			   |
'-------------------------------------------------------------------------*/

Q_DEFINE_STRICT_STRUCTURE (
	QString	signature[7];		/* 'ZXTape!' */
	quint8	eof_marker;		/* 1Ah	     */
	quint8	major_revision_number;
	quint8	minor_revision_number;
) QTZXHeader;

/* MARK: - Block ID */

#define Q_TZX_BLOCK_ID_STANDARD_SPEED_DATA	0x10
#define Q_TZX_BLOCK_ID_TURBO_SPEED_DATA		0x11
#define Q_TZX_BLOCK_ID_PURE_TONE		0x12
#define Q_TZX_BLOCK_ID_PULSE_SEQUENCE		0x13
#define Q_TZX_BLOCK_ID_PURE_DATA		0x14
#define Q_TZX_BLOCK_ID_DIRECT_RECORDING		0x15
#define Q_TZX_BLOCK_ID_CSW_RECORDING		0x18 /* Added in v1.20 */
#define Q_TZX_BLOCK_ID_GENERALIZED_DATA		0x19 /* Added in v1.20 */
#define Q_TZX_BLOCK_ID_PAUSE			0x20
#define Q_TZX_BLOCK_ID_GROUP_START		0x21
#define Q_TZX_BLOCK_ID_GROUP_END		0x22
#define Q_TZX_BLOCK_ID_JUMP			0x23
#define Q_TZX_BLOCK_ID_LOOP_START		0x24 /* Added in v1.10 */
#define Q_TZX_BLOCK_ID_LOOP_END			0x25 /* Added in v1.10 */
#define Q_TZX_BLOCK_ID_CALL_SEQUENCE		0x26 /* Added in v1.10 */
#define Q_TZX_BLOCK_ID_RETURN_FROM_SEQUENCE	0x27 /* Added in v1.10 */
#define Q_TZX_BLOCK_ID_SELECT			0x28 /* Added in v1.10 */
#define Q_TZX_BLOCK_ID_STOP_IF_48K		0x2A
#define Q_TZX_BLOCK_ID_SET_SIGNAL_LEVEL		0x2B /* Added in v1.20 */
#define Q_TZX_BLOCK_ID_DESCRIPTION_TEXT		0x30
#define Q_TZX_BLOCK_ID_MESSAGE			0x31
#define Q_TZX_BLOCK_ID_ARCHIVE_INFORMATION	0x32
#define Q_TZX_BLOCK_ID_HARDWARE_TYPE		0x33
#define Q_TZX_BLOCK_ID_CUSTOM_INFORMATION	0x35
#define Q_TZX_BLOCK_ID_GLUE			0x5A

 /* Deprecated. These should not be used in v1.20 and later. */
#define Q_TZX_BLOCK_ID_C64_ROM_TYPE_DATA	0x16 /* Added in v1.13, deprecated in v1.20 */
#define Q_TZX_BLOCK_ID_C64_TURBO_TAPE_DATA	0x17 /* Added in v1.13, deprecated in v1.20 */
#define Q_TZX_BLOCK_ID_EMULATION_INFORMATION	0x34 /* Deprecated in v1.20 */
#define Q_TZX_BLOCK_ID_CUSTOM_INFORMATION	0x35 /* Added in v1.01, deprecated in v1.20 */
#define Q_TZX_BLOCK_ID_SNAPSHOT			0x40 /* Added in v1.10, deprecated in v1.20 */

/* MARK: - ID 10 - Standard Speed Data
.-----------------------------------------------------------------------------.
| This block must be replayed with the standard Spectrum ROM timing values    |
| (see the values in curly brackets in block ID 11). The pilot tone consists  |
| in 8063 pulses if the first data byte (flag byte) is < 128, 3223 otherwise. |
| This block can be used for the ROM loading routines AND for custom loading  |
| routines that use the same timings as ROM ones do.			      |
'----------------------------------------------------------------------------*/

Q_DEFINE_STRICT_STRUCTURE (
	quint16 pause;
	quint16 data_size;
	quint8	data[];
) QTZXStandardSpeedData;

/* MARK: - ID 11 - Turbo Speed Data
.-----------------------------------------------------------------------------.
| This block is very similar to the normal TAP block but with some additional |
| info on the timings and other important differences. The same tape encoding |
| is used as for the standard speed data block. If a block should use some    |
| non-standard sync or pilot tones (i.e. all sorts of protection schemes)     |
| then use the next three blocks to describe it.			      |
'----------------------------------------------------------------------------*/

Q_DEFINE_STRICT_STRUCTURE (
	quint16 pilot_pulse_duration;		/* {2168}	*/
	quint16 sync_1_pulse_duration;		/* {667}	*/
	quint16 sync_2_pulse_duration;		/* {735}	*/
	quint16 bit_0_pulse_duration;		/* {855}	*/
	quint16 bit_1_pulse_duration;		/* {1710}	*/
	quint16 pilot_tone_duration;		/* TO DO	*/
	quint8	last_byte_bit_count;		/* TO DO	*/
	quint16 pause_after_this_block_ms;	/* {1000}	*/
	quint8	data_size[3];
	quint8	data[];
) QTZXTurboSpeedData;

/* MARK: - ID 12 - Pure Tone
.------------------------------------------------------------------------.
| This will produce a tone which is basically the same as the pilot tone |
| the ID 10, ID 11 blocks. You can define how long the pulse is and how  |
| many pulses are in the tone.						 |
'-----------------------------------------------------------------------*/

Q_DEFINE_STRICT_STRUCTURE (
	quint16 pulse_t_states;
	quint16 pulse_count;
) QTZXPureTone;

/* MARK: - ID 13 - Pulse Sequence
.--------------------------------------------------------------.
| This will produce N pulses, each having its own timing.      |
| Up to 255 pulses can be stored in this block; this is useful |
| for non-standard sync tones used by some protection schemes. |
'-------------------------------------------------------------*/

Q_DEFINE_STRICT_STRUCTURE (
	quint8	pulse_count;
	quint16 pulse_duration[];
) QTZXPulseSequence;

/* MARK: - ID 14 - Pure Data
.------------------------------------------------------.
| This is the same as in the turbo loading data block, |
| except that it has no pilot or sync pulses.	       |
'-----------------------------------------------------*/

Q_DEFINE_STRICT_STRUCTURE (
	quint16 bit_0_pulse_duration;
	quint16 bit_1_pulse_duration;
	quint8	last_byte_bit_count;
	quint16 pause_after_this_block_ms;
	quint8	data_size[3];
	quint8	data[];
) QTZXPureData;

/* MARK: - ID 15 - Direct Recording
.---------------------------------------------------------------------------.
| This block is used for tapes which have some parts in a format such that  |
| the turbo loader block cannot be used. This is not like a VOC file, since |
| the information is much more compact. Each sample value is represented by |
| one bit only (0 for low, 1 for high) which means that the block will be   |
| at most 1/8 the size of the equivalent VOC.				    |
|									    |
| The preferred sampling frequencies are 22050 or 44100 Hz		    |
| (158 or 79 T-states per sample).					    |
|									    |
| Please, if you can, don't use other sampling frequencies and only use	    |
| this block if you can not use any other one.				    |
'--------------------------------------------------------------------------*/

Q_DEFINE_STRICT_STRUCTURE (
	quint16 t_states_per_sample;
	quint16 pause_after_this_block_ms;
	quint8	last_byte_bit_count;
	quint8	data_size[3];
	quint8	data[];
) QTZXDirectRecording;

/* MARK: -  ID 16 - C64 ROM Type Data (DEPRECATED)
.------------------------------------------------------------------------------.
| This block was created to support the Commodore 64 standard ROM and similar  |
| tape blocks. It is made so basically anything that uses two or four pulses   |
| (which are the same in pairs) per bit can be written with it.		       |
|									       |
| Some explanation:							       |
| - A wave consists of 2 pulses. The structure contains the length of 1 pulse. |
| - The wave MUST always start with the LOW amplitude, since the C64 can only  |
|   detect the transition HIGH -> LOW.					       |
| - If some pulse length is 0 then the whole wave must not be present. This    |
|    applies to DATA too.						       |
| - The XOR checksum (if it is set to 0 or 1) is a XOR of all bits in the byte |
|   XOR-ed with the value in this field as the start value.		       |
| - Finish Byte waves should be played after each byte EXCEPT last one.	       |
| - Finish Data waves should be ONLY played after last byte of data.	       |
| - When all the Data has finished there is an optional Trailer Tone, which is |
|   standard for the Repeated Blocks in C64 ROM Loader.			       |
|									       |
| The replay procedure looks like this:					       |
| - Pilot Tone								       |
| - Sync waves								       |
| - Data Bytes (with XOR and/or Finish Byte waves)			       |
| - Finish Data pulses							       |
| - Trailing Tone							       |
'-----------------------------------------------------------------------------*/

Q_DEFINE_STRICT_STRUCTURE (
	quint32 complete_block_size;
	/* TO DO */
) QTZXC64ROMTypeData;

/* MARK: - ID 17 - C64 Turbo Tape Data (DEPRECATED)
.------------------------------------------------------------------------------.
| This block is made to support another type of encoding that is commonly used |
| by the C64. Most of the commercial software uses this type of encoding, i.e. |
| the pilot tone is not made from one type of wave only, but it is made from   |
| actual data byte which is repeated many times. As the sync value another,    |
| different, data byte is sent to signal the start of the data. The data bits  |
| are made from ONE wave only and there is NO XOR checksum either! Trailing    |
| byte is played AFTER the DATA has ended.				       |
'-----------------------------------------------------------------------------*/

Q_DEFINE_STRICT_STRUCTURE (
	quint32 complete_block_size;
	/* TO DO */
) QTZXC64TurboTapeData;


/* MARK: - ID 18 - CSW Recording
.----------------------------------------------------.
| This block contains a sequence of raw pulses	     |
| encoded in CSW format v2 (Compressed Square Wave). |
'---------------------------------------------------*/

#define Q_TZX_CSW_COMPRESSION_TYPE_RLE	 1
#define Q_TZX_CSW_COMPRESSION_TYPE_Z_RLE 2

Q_DEFINE_STRICT_STRUCTURE (
	quint32 block_size;
	quint16 pause_after_this_block_ms;
	quint8	sampling_rate[3];
	quint8	compression_type;
	quint32 pulse_count;
	quint8	csw_data[];
) QTZXCSWRecording;

/* MARK: - ID 19 - Generalized Data
.-----------------------------------------------------------------------------.
| This block has been specifically developed to represent an extremely wide   |
| range of data encoding techniques. The basic idea is that each loading      |
| component (pilot tone, sync pulses, data) is associated to a specific	      |
| sequence of pulses, where each sequence (wave) can contain a different      |
| number of pulses from the others. In this way we can have a situation where |
| bit 0 is represented with 4 pulses and bit 1 with 8 pulses.		      |
'----------------------------------------------------------------------------*/

Q_DEFINE_STRICT_STRUCTURE (
	quint32 block_size;
	quint16 pause_after_this_block_ms;
	quint32 symbol_count;
	quint8	pulses_per_symbol_maximum;

	/* TO DO */
) QTZXGeneralizedData;

/*---------------------------------------------------------------------------.
| The alphabet is stored using a table where each symbol is a row of pulses. |
| The number of columns (i.e. pulses) of the table is the length of the	     |
| longest sequence amongst all (MAXP = NPP or NPD, for pilot/sync or data    |
| blocks respectively); shorter waves are terminated by a zero-length pulse  |
| in the sequence.							     |
|									     |
| Any number of data symbols is allowed, so we can have more than two	     |
| distinct waves; for example, imagine a loader which writes two bits at a   |
| time by encoding them with four distinct pulse lengths: this loader would  |
| have an alphabet of four symbols, each associated to a specific sequence   |
| of pulses (wave).							     |
'---------------------------------------------------------------------------*/

#define Q_TZX_SYMBOL_DEFINITION_FLAG_POLARITY_CURRENT	       0
#define Q_TZX_SYMBOL_DEFINITION_FLAG_POLARITY_CURRENT_NEGATIVE 1
#define Q_TZX_SYMBOL_DEFINITION_FLAG_POLARITY_LOW	       2
#define Q_TZX_SYMBOL_DEFINITION_FLAG_POLARITY_HIGH	       3

Q_DEFINE_STRICT_STRUCTURE (
	quint8	flags;
	quint16 pulse_duration[];
) QTZXSymbolDefinition;

/*----------------------------------------------------------------------------.
| Most commonly, pilot and sync are repetitions of the same pulse, thus they  |
| are represented using a very simple RLE encoding structure which stores the |
| symbol and the number of times it must be repeated.			      |
|									      |
| Each symbol in the data stream is represented by a string of NB bits of the |
| block data, where NB = ceil(log2(ASD)). Thus the length of the whole data   |
| stream in bits is NB * TOTD, or in bytes DS = ceil(NB * TOTD / 8).	      |
'----------------------------------------------------------------------------*/

Q_DEFINE_STRICT_STRUCTURE (
	quint8	symbol;
	quint16	repetitions;
) QTZXPulseRLE;

/* MARK: EXAMPLE
A typical Spectrum's standard loading header can be represented like this:

Offset	   Value			Description
.----+-----------------+----------------------------------------------.
| 00 | 59 (3Bh)	       | Total block length			      |
|----+-----------------+----------------------------------------------|
| 04 | 1000 (03E8h)    | Pause after this block (ms.)		      |
|----+-----------------+----------------------------------------------|
| 06 | 2	       | Total number of symbols in pilot/sync block  |
|----+-----------------+----------------------------------------------|
| 0A | 2	       | Max pulses per symbol			      |
|----+-----------------+----------------------------------------------|
| 0B | 2	       | Number of symbols in pilot/sync alphabet     |
|----+-----------------+----------------------------------------------|
| 0C | 152 (98h)       | Total number of symbols (bits, in this case) |
|    |		       | in data stream				      |
|----+-----------------+----------------------------------------------|
| 10 | 2	       | Max pulses per data symbol		      |
|----+-----------------+----------------------------------------------|
| 11 | 2	       | Number of symbols in data alphabet	      |
|----+-----------------+----------------------------------------------|
| 12 | (0, 2168, 0)    | Pilot/sync symbol definitions		      |
|    | (0, 667, 735)   |					      |
|----+-----------------+----------------------------------------------|
| 1C | (0, 8063)       | Pilot/sync data block			      |
|    | (1, 1)	       |					      |
|----+-----------------+----------------------------------------------|
| 22 | (0, 855, 855)   | Data symbol definitions		      |
|    | (0, 1710, 1710) |					      |
|----+-----------------+----------------------------------------------|
| 2C | 00000000b (00h) |- Floading flag (00h = header)		      |
|    | 00000011b (03h) |- Data type (03h = "Bytes:")		      |
|    | 01001010b (4Ah) |\					      |
|    | 01010000b (50h) | |					      |
|    | 01010011b (53h) | |					      |
|    | 01010000b (50h) | |					      |
|    | 00100000b (20h) | | File name ("JPSP")			      |
|    | 00100000b (20h) | |					      |
|    | 00100000b (20h) | |					      |
|    | 00100000b (20h) | |					      |
|    | 00100000b (20h) | |					      |
|    | 00100000b (20h) |/					      |
|    | 00000000b (00h) |\ Data length				      |
|    | 00011011b (1Bh) |/					      |
|    | 00000000b (00h) |\ Start address				      |
|    | 01000000b (40h) |/					      |
|    | 00000000b (00h) |\ Autostart (no meaning here)		      |
|    | 10000000b (80h) |/					      |
|    | 11000001b (C1h) |- Checksum				      |
'--------------------------------------------------------------------*/

/* MARK: - ID 20 - Pause (Silence) or 'Stop the Tape' Command
.------------------------------------------------------------------------.
| This will make a silence (low amplitude level (0)) for a given time in |
| milliseconds. If the value is 0 then the emulator or utility should	 |
| (in effect) STOP THE TAPE, i.e. should not continue loading until the	 |
| user or emulator requests it.						 |
'-----------------------------------------------------------------------*/

Q_DEFINE_STRICT_STRUCTURE(
	quint16 duration_ms;
) QTZXPause;

/* MARK: - ID 21 - Group Start
.----------------------------------------------------------------------------.
| This block marks the start of a group of blocks which are to be treated as |
| one single (composite) block. This is very handy for tapes that use lots   |
| of subblocks like Bleepload (which may well have over 160 custom loading   |
| blocks). You can also give the group a name (example 'Bleepload Block 1'). |
|									     |
| For each group start block, there must be a group end block. Nesting of    |
| groups is not allowed.						     |
'---------------------------------------------------------------------------*/

Q_DEFINE_STRICT_STRUCTURE (
	quint8 name_size;
	quint8 name_ascii[];
) QTZXGroupStart;

/* MARK: - ID 22 - Group End
.------------------------------------------------------------.
| This indicates the end of a group. This block has no body. |
'-----------------------------------------------------------*/

/* MARK: - ID 23 - Jump
.---------------------------------------------------------------------.
| This block will enable you to jump from one block to another within |
| the file. Some examples:					      |
|								      |
| Jump  0 = 'Loop Forever' - this should never happen		      |
| Jump  1 = 'Go to the next block' - it is like NOP in assembler ;)   |
| Jump  2 = 'Skip one block'					      |
| Jump -1 = 'Go to the previous block'				      |
|								      |
|All blocks are included in the block count!			      |
'--------------------------------------------------------------------*/

Q_DEFINE_STRICT_STRUCTURE(
	quint16 relative_offset;
) QTZXJump;

/* MARK: - ID 24 - Loop Start
.-----------------------------------------------------------------------.
| If you have a sequence of identical blocks, or of identical groups of |
| blocks, you can use this block to tell how many times they should be	|
| repeated. This block is the same as the FOR statement in BASIC.	|
|									|
| For simplicity reasons don't nest loop blocks!			|
'----------------------------------------------------------------------*/

Q_DEFINE_STRICT_STRUCTURE (
	quint16 count;
) QTZXLoopStart;

/* MARK: - ID 25 - Loop End
.-----------------------------------------------------------------------.
| This is the same as BASIC's NEXT statement. It means that the utility |
| should jump back to the start of the loop if it hasn't been run for	|
| the specified number of times.					|
|									|
| This block has no body.						|
'----------------------------------------------------------------------*/

/* MARK: - ID 26 - Call Sequence
.----------------------------------------------------------------------------.
| This block is an analogue of the CALL Subroutine statement. It basically   |
| executes a sequence of blocks that are somewhere else and then goes back   |
| to the next block. Because more than one call can be normally used you can |
| include a list of sequences to be called. The 'nesting' of call blocks is  |
| also not allowed for the simplicity reasons. You can, of course, use the   |
| CALL blocks in the LOOP sequences and vice versa. The value is relative    |
| for the obvious reasons - so that you can add some blocks in the beginning |
| of the file without disturbing the call values. Please take a look at	     |
| 'Jump To Block' for reference on the values.				     |
'---------------------------------------------------------------------------*/

Q_DEFINE_STRICT_STRUCTURE (
	quint16 count;
	quint16 relative_offset[];
) QTZXCallSequence;

/* MARK: - ID 27 - Return from Sequence
.----------------------------------------------------------------------------.
| This block indicates the end of the Called Sequence. The next block played |
| will be the block after the last CALL block (or the next Call, if the Call |
| block had multiple calls).						     |
|									     |
| This block has no body.						     |
'---------------------------------------------------------------------------*/

/* MARK: - ID 28 - Select
.------------------------------------------------------------------------------.
| This block is useful when the tape consists of two or more separately	       |
| loadable parts. With this block, you are able to select one of the parts and |
| the utility/emulator will start loading from that block. For example you can |
| use it when the game has a separate Trainer or when it is a multiload.       |
| Of course, to make some use of it the emulator/utility has to show a menu    |
| with the selections when it encounters such a block.			       |
| All offsets are relative signed words.				       |
'-----------------------------------------------------------------------------*/

Q_DEFINE_STRICT_STRUCTURE (
	quint32	block_size;
	quint8	selection_count;
	quint8	selection[]; /* QTZXSelectItem */
) QTZXSelect;

Q_DEFINE_STRICT_STRUCTURE (
	quint16 relative_offset;
	quint8	description_size;
	quint8	description_ascii[];
) QTZXSelectItem;

/* MARK: - ID 2A - Stop Tape if in 48K Mode
.----------------------------------------------------------------------------.
| When this block is encountered, the tape will stop ONLY if the machine is  |
| an 48K Spectrum. This block is to be used for multiloading games that load |
| one level at a time in 48K mode, but load the entire tape at once if in    |
| 128K mode.								     |
| This block has no body of its own, but follows the extension rule.	     |
'---------------------------------------------------------------------------*/

Q_DEFINE_STRICT_STRUCTURE (
	quint32 block_size;
) QTZXStopIf48K;

/* MARK: - ID 2B - Set Signal Level
.----------------------------------------------------------------------.
| This block sets the current signal level to the specified value      |
| (high or low). It should be used whenever it is necessary to avoid   |
| any ambiguities, e.g. with custom loaders which are level-sensitive. |
'---------------------------------------------------------------------*/

#define Q_TZX_SIGNAL_LEVEL_LOW	0
#define Q_TZX_SIGNAL_LEVEL_HIGH	1

Q_DEFINE_STRICT_STRUCTURE (
	quint32 block_size;
	quint8	level;
) QTZXSetSignalLevel;

/* MARK: - ID 30 - Description Text
.------------------------------------------------------------------------------.
| This is meant to identify parts of the tape, so you know where level 1       |
| starts, where to rewind to when the game ends, etc. This description is not  |
| guaranteed to be shown while the tape is playing, but can be read while      |
| browsing the tape or changing the tape pointer.			       |
|									       |
| The description can be up to 255 characters long but please keep it down to  |
| about 30 so the program can show it in one line (where this is appropriate). |
|									       |
| Please use 'Archive Information' block for title, authors, publisher, etc.   |
'-----------------------------------------------------------------------------*/

Q_DEFINE_STRICT_STRUCTURE (
	quint8 size;
	quint8 ascii[];
) QTZXDescriptionText;

/* MARK: - ID 31 - Message
.----------------------------------------------------------------------------.
| This will enable the emulators to display a message for a given time. This |
| should not stop the tape and it should not make silence. If the time is 0  |
| then the emulator should wait for the user to press a key.		     |
|									     |
| The text message should:						     |
| - stick to a maximum of 30 chars per line;				     |
| - use single 0x0D (13 decimal) to separate lines;			     |
| - stick to a maximum of 8 lines.					     |
|									     |
| If you do not obey these rules, emulators may display your message in any  |
| way they like.							     |
'---------------------------------------------------------------------------*/

Q_DEFINE_STRICT_STRUCTURE (
	quint8 display_seconds;
	quint8 size;
	quint8 ascii[];
) QTZXMessage;

/* MARK: - ID 32 - Archive Information
.------------------------------------------------------------------------------.
| Use this block at the beginning of the tape to identify the title of the     |
| game, author, publisher, year of publication, price (including the	       |
| currency), type of software (arcade adventure, puzzle, word processor, ...), |
| protection scheme it uses (Speedlock 1, Alkatraz, ...) and its origin	       |
| (Original, Budget re-release, ...), etc. This block is built in a way that   |
| allows easy future expansion. The block consists of a series of text	       |
| strings. Each text has its identification number (which tells us what the    |
| text means) and then the ASCII text. To make it possible to skip this block, |
| if needed, the length of the whole block is at the beginning of it.	       |
|									       |
| If all texts on the tape are in English language then you don't have to      |
| supply the 'Language' field.						       |
|									       |
| The information about what hardware the tape uses is in the 'Hardware Type'  |
| block, so no need for it here.					       |
'-----------------------------------------------------------------------------*/

Q_DEFINE_STRICT_STRUCTURE (
	quint8 id;
	quint8 size;
	quint8 ascii[];
) QTZXText;

Q_DEFINE_STRICT_STRUCTURE (
	quint32 block_size;
	quint8	text_count;
	quint8	text[]; /* QTZXText */
) QTZXArchiveInformation;

/* MARK: - ID 33 - Hardware Type
.----------------------------------------------------------------------------.
| This blocks contains information about the hardware that the programs on   |
| this tape use. Please include only machines and hardware for which you are |
| 100% sure that it either runs (or doesn't run) on or with, or you know it  |
| uses (or doesn't use) the hardware or special features of that machine.    |
|									     |
| If the tape runs only on the ZX81 (and TS1000, etc.) then it clearly won't |
| work on any Spectrum or Spectrum variant, so there's no need to list this  |
| information.								     |
|									     |
| If you are not sure or you haven't tested a tape on some particular	     |
| machine/hardware combination then do not include it in the list.	     |
|									     |
| The list of hardware types and IDs is somewhat large, and may be found at  |
| the end of the format description.					     |
'---------------------------------------------------------------------------*/

#define Q_TZX_HARDWARE_COMPATIBILITY_COMPATIBLE	  0
#define Q_TZX_HARDWARE_COMPATIBILITY_NEEDED	  1
#define Q_TZX_HARDWARE_COMPATIBILITY_UNNEEDED	  2
#define Q_TZX_HARDWARE_COMPATIBILITY_INCOMPATIBLE 3

Q_DEFINE_STRICT_STRUCTURE(
	quint8 type;
	quint8 id;
	quint8 compatibility;
) QTZXHardware;

Q_DEFINE_STRICT_STRUCTURE (
	quint8	     count;
	QTZXHardware hardware[];
) QTZXHardwareType;

/* MARK: - ID 34 - Emulation Information (DEPRECATED)
.------------------------------------------------------------------------------.
| This is a special block that would normally be generated only by emulators.  |
| For now it contains information on everything the authors could find that    |
| other formats support. Please inform them of any additions/corrections since |
| this is a very important part for emulators.				       |
| Those bits that are not used by the emulator that stored the info, should be |
| left at their DEFAULT values.						       |
'-----------------------------------------------------------------------------*/

Q_DEFINE_STRICT_STRUCTURE (
	/* TO DO */
) QTZXEmulationInformation;

/* MARK: - ID 35 - Custom Information
.------------------------------------------------------------------------.
| This block can be used to save any information you want. For example,	 |
| it might contain some information written by a utility, extra settings |
| required by a particular emulator, or even poke data.			 |
'-----------------------------------------------------------------------*/

Q_DEFINE_STRICT_STRUCTURE (
	quint8	ascii_id;
	quint32	data_size;
	quint8	data[];
) QTZXCustomInformation;

/* MARK: - ID 40 - Snapshot (DEPRECATED)
.------------------------------------------------------------------------------.
| This would enable one to snapshot the prgram at the start and still have all |
| the tape blocks in the same file. Only .Z80 and .SNA snapshots are supported |
| for compatibility reasons!.						       |
| The emulator should take care of that the snapshot is not taken while the    |
| actual tape loading is taking place (which doesn't do much sense). When an   |
| emulator encounters the snapshot block it should load it and then continue   |
| with the next block.							       |
'-----------------------------------------------------------------------------*/

#define Q_TZX_SNAPSHOT_FORMAT_Z80 0
#define Q_TZX_SNAPSHOT_FORMAT_SNA 1

Q_DEFINE_STRICT_STRUCTURE (
	quint8 format;
	quint8 size[3];
	quint8 data[];
) QTZXSnapshot;

/* MARK: - ID 5A - "Glue"
.------------------------------------------------------------------------------.
| This block is generated when you merge two ZX Tape files together. It is     |
| here so that you can easily copy the files together and use them. Of course, |
| this means that resulting file would be 10 bytes longer than if this block   |
| was not used. All you have to do if you encounter this block ID is to skip   |
| next 9 bytes.								       |
| If you can avoid using this block for this purpose, then do so; it is	       |
| preferable to use a utility to join the two files and ensure that they are   |
| both of the higher version number.					       |
'-----------------------------------------------------------------------------*/

Q_DEFINE_STRICT_STRUCTURE (
	quint8 data[9];
) QTZXGlue;

/* MARK: - Casts */

#define Q_TZX_STANDARD_SPEED_DATA(  p) ((QTZXStandardSpeedData	  *)(p))
#define Q_TZX_TURBO_SPEED_DATA(	    p) ((QTZXTurboSpeedData	  *)(p))
#define Q_TZX_PURE_TONE(	    p) ((QTZXPureTone		  *)(p))
#define Q_TZX_PULSE_SEQUENCE(	    p) ((QTZXPulseSequence	  *)(p))
#define Q_TZX_PURE_DATA(	    p) ((QTZXPureData		  *)(p))
#define Q_TZX_DIRECT_RECORDING(	    p) ((QTZXDirectRecording	  *)(p))
#define Q_TZX_C64_ROM_TYPE_DATA(    p) ((QTZXC64ROMTypeData	  *)(p))
#define Q_TZX_C64_TURBO_TAPE_DATA(  p) ((QTZXC64TurboTapeData	  *)(p))
#define Q_TZX_CSW_RECORDING(	    p) ((QTZXCSWRecording	  *)(p))
#define Q_TZX_GENERALIZED_DATA(	    p) ((QTZXGeneralizedData	  *)(p))
#define Q_TZX_PAUSE(		    p) ((QTZXPause		  *)(p))
#define Q_TZX_GROUP_START(	    p) ((QTZXGroupStart		  *)(p))
#define Q_TZX_JUMP(		    p) ((QTZXJump		  *)(p))
#define Q_TZX_LOOP_START(	    p) ((QTZXLoopStart		  *)(p))
#define Q_TZX_CALL_SEQUENCE(	    p) ((QTZXCallSequence	  *)(p))
#define Q_TZX_SELECT(		    p) ((QTZXSelect		  *)(p))
#define Q_TZX_STOP_IF_48K(	    p) ((QTZXStopIf48K		  *)(p))
#define Q_TZX_SET_SIGNAL_LEVEL(	    p) ((QTZXSetSignalLevel	  *)(p))
#define Q_TZX_DESCRIPTION_TEXT(	    p) ((QTZXDescriptionText	  *)(p))
#define Q_TZX_MESSAGE(		    p) ((QTZXMessage		  *)(p))
#define Q_TZX_ARCHIVE_INFORMATION(  p) ((QTZXArchiveInformation	  *)(p))
#define Q_TZX_HARDWARE_TYPE(	    p) ((QTZXHardwareType	  *)(p))
#define Q_TZX_EMULATION_INFORMATION(p) ((QTZXEmulationInformation *)(p))
#define Q_TZX_CUSTOM_INFORMATION(   p) ((QTZXCustomInformation	  *)(p))
#define Q_TZX_SNAPSHOT(		    p) ((QTZXSnapshot		  *)(p))
#define Q_TZX_GLUE(		    p) ((QTZXGlue		  *)(p))

#endif /* __Q_formats_storage_medium_image_audio_TZX_H__ */
