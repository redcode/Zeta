/* Zeta API - Z/formats/snapshot/machine/computer/ZX_Spectrum/SNA.h
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.

 ________________________________________________________________________
|									 |
|	 Daft: Public.Snapshot.Computer.ZXSpectrum.SNA			 |
|  Extensions: .sna, .snap, .snapshot					 |
|  Endianness: Little							 |
|									 |
|  Reference:								 |
|  http://rk.nvg.ntnu.no/sinclair/faq/fileform.html			 |
|  http://www.worldofspectrum.org/faq/reference/formats.htm		 |
|  http://www.zx-modules.de/fileformats/snaformat.html			 |
|  MAME sources]/src/mame/machine/spec_snqk.cpp				 |
|									 |
|  This format is based on the format used by the Mirage Microdriver,	 |
|  a backup device manufactured by Mirage Microcomputers Ltd.		 |
|  Reference: http://www.worldofspectrum.org/infoseekid.cgi?id=1000266	 |
|									 |
'=======================================================================*/

#ifndef Z_formats_snapshot_machine_computer_ZX_Spectrum_SNA_H
#define Z_formats_snapshot_machine_computer_ZX_Spectrum_SNA_H

#include <Z/types/bitwise.h>
#include <Z/hardware/machine/computer/ZX_Spectrum.h>

/* v48K
 ______________________________________________________________________________
|									       |
|      Daft: Public.Snapshot.Computer.ZXSpectrum.SNA[48K]		       |
|    Author: Gulbrandsen, Arnt <arnt@gulbrandsen.priv.no>		       |
|  Supports: ZX Spectrum 48K						       |
|   Used by: JPP (MS-DOS)						       |
|									       |
|  From comp.sys.sinclair Sinclair ZX Spectrum FAQ:			       |
|									       |
|  This format is one of the most well-supported of all snapshot formats       |
|  (for the ZX Spectrum), but has a drawback:				       |
|									       |
|  As the program counter is pushed onto the stack so that a RETN	       |
|  instruction can restart the program, 2 bytes of memory are overwritten.     |
|  This will usually not matter; the game (or whatever) will have stack space  |
|  that can be used for this. However, if this space is all in use when the    |
|  snap is made, memory below the stack space will be corrupted. According to  |
|  Rui Ribeiro, the effects of this can sometimes be avoided by replacing the  |
|  corrupted bytes with zeros; e.g. take the PC from the, stack pointer,       |
|  replace that word with 0000h and then increment SP. This worked with	       |
|  snapshots of Batman, Bounder and others which had been saved at critical    |
|  points. Theoretically, this problem could cause a complete crash on a real  |
|  Spectrum if the stack pointer happened to be at address 4000h; the push     |
|  would try and write to the ROM.					       |
|									       |
|  When the registers have been loaded, a RETN command is required to start    |
|  the program. IFF2 is short for interrupt flip-flop 2, and for all	       |
|  practical purposes is the interrupt-enabled flag. Set means enabled.        |
|									       |
'=============================================================================*/

#define Z_SNA_V48K_PC_VALUE 0x72

typedef Z_PACKED_STRUCTURE_BEGIN {
	zuint8 i;
	ZInt16 hl_, de_, bc_, af_, hl, de, bc, iy, ix;

	union {	zuint8 value;
		struct {Z_BIT_FIELD_MEMBERS(8, 4) (
			zuint8 unused_1 :5,
			zuint8 iff2	:1,
			zuint8 unused_0 :1,
			zuint8 iff1	:1
		)} fields;
	} interrupt;

	zuint8 r;
	ZInt16 af, sp;
	zuint8 im;
	zuint8 border_color;
} Z_PACKED_STRUCTURE_END Z_SNA;

typedef Z_PACKED_STRUCTURE_BEGIN {
	Z_SNA  sna;
	zuint8 ram[Z_ZX_SPECTRUM_48K_SIZE_RAM];
} Z_PACKED_STRUCTURE_END Z_SNAv48K;

/* v128K
 ______________________________________________________________________________
|									       |
|      Daft: Public.Snapshot.Computer.ZXSpectrum.SNA[128K]		       |
|    Author: McGavin, Peter <p.mcgavin@irl.cri.nz>			       |
|  Supports: ZX Spectrum + 128K						       |
|   Used by: Spectrum (AmigaOS)						       |
|									       |
|  From comp.sys.sinclair Sinclair ZX Spectrum FAQ:			       |
|									       |
|  The 128K version of the SNA format is the same as above, with extensions    |
|  to include the extra memory banks of the 128K/+2 machines, and fixes the    |
|  problem with the PC being pushed onto the stack - now it is located in an   |
|  extra variable in the file (and is not pushed onto the stack at all). The   |
|  first 49179 bytes of the snapshot are otherwise exactly as described        |
|  above.								       |
|									       |
|  The third RAM bank saved is always the one currently paged, even if this    |
|  is page 5 or 2 - in this case, the bank is actually included twice. The     |
|  remaining RAM banks are saved in ascending order - e.g. if RAM bank 4 is    |
|  paged in, the snapshot is made up of banks 5, 2 and 4 to start with, and    |
|  banks 0, 1, 3, 6 and 7 afterwards. If RAM bank 5 is paged in, the snapshot  |
|  is made up of banks 5, 2 and 5 again, followed by banks 0, 1, 3, 4, 6 and   |
|  7.									       |
|									       |
'=============================================================================*/

typedef Z_PACKED_STRUCTURE_BEGIN {
	Z_SNA  sna;
	zuint8 ram_bank_5[Z_ZX_SPECTRUM_PLUS_128K_SIZE_BANK];
	zuint8 ram_bank_2[Z_ZX_SPECTRUM_PLUS_128K_SIZE_BANK];
	zuint8 ram_bank_n[Z_ZX_SPECTRUM_PLUS_128K_SIZE_BANK];
	ZInt16 pc;

	Z_ZXSpectrumPlus128KBankSwitch bank_switch;

	zuint8 tr_dos_rom_is_paged; /* boolean */
	zuint8 remaining_ram_banks[5][Z_ZX_SPECTRUM_PLUS_128K_SIZE_BANK];
} Z_PACKED_STRUCTURE_END Z_SNAv128K;

#endif /* Z_formats_snapshot_machine_computer_ZX_Spectrum_SNA_H */
