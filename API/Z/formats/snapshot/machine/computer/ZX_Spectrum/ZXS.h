/* Zeta API - Z/formats/snapshot/machine/computer/ZX_Spectrum/ZXS.h
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.

 __________________________________________________________________
|								   |
|	 Daft: Public.Snapshot.Computer.ZXSpectrum.ZXS		   |
|      Author: Kapartzianis, Vaggelis				   |
|  Extensions: .zxs						   |
|  Endianness: Little						   |
|    Supports:							   |
|     Used by: zx32 (Windows)					   |
|	       <http://www.geocities.com/SiliconValley/Bay/9932/>  |
|	       Fuse <http://fuse-emulator.sourceforge.net>	   |
|								   |
|  Reference:							   |
|  http://www.geocities.com/SiliconValley/Bay/9932/		   |
|								   |
'=================================================================*/

#ifndef Z_formats_snapshot_machine_computer_ZX_Spectrum_ZXS_H
#define Z_formats_snapshot_machine_computer_ZX_Spectrum_ZXS_H

#include <Z/types/bitwise.h>
#include <Z/hardware/machine/computer/ZX_Spectrum.h>

#define Z_ZXS_MACHINE_DEFAULT	  0
#define Z_ZXS_MACHINE_48K_ISSUE_2 0x10  // ZX Spectrum 48K (Issue 2)
#define Z_ZXS_MACHINE_PLUS	  0x20  // ZX Spectrum +   (Model 3)
#define Z_ZXS_MACHINE_PLUS_128K	  0x30  // ZX Spectrum 128
#define Z_ZXS_MACHINE_PLUS2	  0x40  // ZX Spectrum +2
#define Z_ZXS_MACHINE_PLUS2A	  0x50  // ZX Spectrum +2A
#define Z_ZXS_MACHINE_PLUS3	  0x60  // ZX Spectrum +3

#define ZXH_NONSTANDARD 0x0001  // peripheral hardware

#define Z_ZXS_ZIP_METHOD_STORE    0       // compression methods
#define Z_ZXS_ZIP_METHOD_SHRINK   0x0001
#define Z_ZXS_ZIP_METHOD_REDUCE_1 0x0002
#define Z_ZXS_ZIP_METHOD_REDUCE_2 0x0003
#define Z_ZXS_ZIP_METHOD_REDUCE_3 0x0004
#define Z_ZXS_ZIP_METHOD_REDUCE_4 0x0005
#define Z_ZXS_ZIP_METHOD_IMPLODE  0x0006
#define Z_ZXS_ZIP_METHOD_TOKENIZE 0x0007
#define Z_ZXS_ZIP_METHOD_DEFLATE  0x0008
#define Z_ZXS_ZIP_METHOD_NONE	  0xFFFF

#if Z_ISA_INTEGRAL_ENDIANNESS == Z_ENDIANNESS_LITTLE
#	define Z_UINT16_STRING(_1, _0) \
		(((zuint16)(_0) << 8) | (zuint16)(_1))


#	define Z_UINT32_STRING(_3, _2, _1, _0) ( \
		((zuint32)(_0) << 24) |		 \
		((zuint32)(_1) << 16) |		 \
		((zuint32)(_2) <<  8) |		 \
		 (zuint32)(_3))

#else
#	define Z_UINT16_STRING(_1, _0) \
		(((zuint16)(_1) << 8) | (zuint16)(_0))

#	define Z_UINT32_STRING(_3, _2, _1, _0) ( \
		((zuint32)(_3) << 24) |		 \
		((zuint32)(_2) << 16) |		 \
		((zuint32)(_1) <<  8) |		 \
		 (zuint32)(_0))
#endif

#define Z_ZXS_FORM_TYPE				Z_UINT32_STRING('S','N','A','P')
#define Z_ZXS_CHUNK_ID_DISK_0			Z_UINT32_STRING('d','s','k','0')
#define Z_ZXS_CHUNK_ID_DISK_1			Z_UINT32_STRING('d','s','k','1')
#define Z_ZXS_CHUNK_ID_FORMAT_INFO		Z_UINT32_STRING('f','m','t','z')
#define Z_ZXS_CHUNK_ID_CPU			Z_UINT32_STRING('r','Z','8','0')
#define Z_ZXS_CHUNK_ID_ZX_SPECTRUM_PLUS3_IO	Z_UINT32_STRING('r','+','3',' ')
#define Z_ZXS_CHUNK_ID_ZX_SPECTRUM_48K_IO	Z_UINT32_STRING('r','0','4','8')
#define Z_ZXS_CHUNK_ID_ZX_SPECTRUM_PLUS_128K_IO Z_UINT32_STRING('r','1','2','8')
#define Z_ZXS_CHUNK_ID_RAM_0			Z_UINT32_STRING('r','a','m','0')
#define Z_ZXS_CHUNK_ID_RAM_1			Z_UINT32_STRING('r','a','m','1')
#define Z_ZXS_CHUNK_ID_RAM_2			Z_UINT32_STRING('r','a','m','2')
#define Z_ZXS_CHUNK_ID_RAM_3			Z_UINT32_STRING('r','a','m','3')
#define Z_ZXS_CHUNK_ID_RAM_4			Z_UINT32_STRING('r','a','m','4')
#define Z_ZXS_CHUNK_ID_RAM_5			Z_UINT32_STRING('r','a','m','5')
#define Z_ZXS_CHUNK_ID_RAM_6			Z_UINT32_STRING('r','a','m','6')
#define Z_ZXS_CHUNK_ID_RAM_7			Z_UINT32_STRING('r','a','m','7')
#define Z_ZXS_CHUNK_ID_TAPE			Z_UINT32_STRING('t','a','p','e')
#define Z_ZXS_CHUNK_ID_ZX32			Z_UINT32_STRING('z','x','3','2')

typedef Z_PACKED_STRUCTURE_BEGIN {
	zuint32 structure_size;     // structure size
	zuint32 crc32;   // crc
	zuint32 uncompressed_size;  // uncompressed size
	zuint8	data[1];
} Z_PACKED_STRUCTURE_END Z_ZXSZip;

typedef Z_PACKED_STRUCTURE_BEGIN {
	zuint16 version;
	zuint16 machine_model;
	zuint16 machine_flags;
	zuint16 zip_method;
} Z_PACKED_STRUCTURE_END Z_ZXSFormatInfo;

typedef Z_PACKED_STRUCTURE_BEGIN {
	ZInt16	af; /* big endian */
	ZInt16  bc, de, hl;
	ZInt16	af_; /* big endian */
	ZInt16	bc_, de_, hl_, ix, iy, pc, sp;
	zuint8  i,  r;
	zuint8	iff1, iff2;
	zuint8	im;
	zuint32 t_states;
} Z_PACKED_STRUCTURE_END Z_ZXSCPU;

typedef Z_PACKED_STRUCTURE_BEGIN {
	zuint8	port_1ffd;
} Z_PACKED_STRUCTURE_END Z_ZXSZXSpectrumPlus3IO;

typedef Z_PACKED_STRUCTURE_BEGIN {
	Z_ZXSpectrumULAIO ula_io;
	ZInt64		  keyboard;
} Z_PACKED_STRUCTURE_END Z_ZXSZXSpectrum48KIO;

typedef Z_PACKED_STRUCTURE_BEGIN {
	Z_ZXSpectrumPlus128KBankSwitch bank_switch;
	zuint8			       port_fffd;
	zuint8			       psg[16];
} Z_PACKED_STRUCTURE_END Z_ZXSZXSpectrumPlus128KIO;

typedef Z_PACKED_STRUCTURE_BEGIN {
	zuint32 current_position;
	zuint32 remain_block_size;
	zuint32 data_size;
	zuint8	data[1];
} Z_PACKED_STRUCTURE_END Z_ZXSTape;

typedef Z_PACKED_STRUCTURE_BEGIN {
	zuint32 id;
	zuint32 body_size;

	union {	zuint32			  type;
		Z_ZXSCPU		  cpu;
		Z_ZXSFormatInfo		  format_info;
		Z_ZXSTape		  tape;
		Z_ZXSZip		  zip;
		Z_ZXSZXSpectrum48KIO	  zx_spectrum_48k_io;
		Z_ZXSZXSpectrumPlus128KIO zx_spectrum_plus_128k_io;
		Z_ZXSZXSpectrumPlus3IO	  zx_spectrum_plus3_io;
	} body;
} Z_PACKED_STRUCTURE_END Z_ZXSChunk;

#endif /* Z_formats_snapshot_machine_computer_ZX_Spectrum_ZXS_H */
