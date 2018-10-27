/* Z Kit - formats/snapshot/machine/computer/ZX Spectrum/SNA.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.

.---------------------------------------------.
| Extensions: sna, snap, snapshot	      |
| Endianness: Little			      |
| Created by: McGavin, Peter		      |
|    Used by: Any decent ZX Spectrum emulator |
'--------------------------------------------*/

#ifndef _Z_formats_snapshot_machine_computer_ZX_Spectrum_SNA_H_
#define _Z_formats_snapshot_machine_computer_ZX_Spectrum_SNA_H_

#include <Z/types/base.h>

/* MARK: - v48K
.-------------------------------------------------------------------------.
| From SinclairFAQ:							  |
|									  |
| "  This format is one of the most well-supported of all snapshot	  |
| formats (for the ZX Spectrum), but has a drawback:			  |
|									  |
|    As the program counter is pushed onto the stack so that a RETN	  |
| instruction can restart the program, 2 bytes of memory are overwritten. |
| This will usually not matter; the game (or whatever) will have stack	  |
| space that can be used for this. However, if this space is all in use	  |
| when the snap is made, memory below the stack space will be corrupted.  |
| According to Rui Ribeiro (Author of WSpecEm), the effects of this can	  |
| sometimes be avoided by replacing the corrupted bytes with zeros; e.g.  |
| take the PC from the stack pointer, replace that word with 0000 and	  |
| then increment SP. This worked with snapshots of Batman, Bounder and	  |
| others which had been saved at critical points. Theoretically, this	  |
| problem could cause a complete crash on a real Spectrum if the stack	  |
| pointer happened to be at address 16384; the push would try and write	  |
| to the ROM.								  |
|									  |
|    When the registers have been loaded, a RETN command is required to	  |
| start the program. IFF2 is short for interrupt flip-flop 2, and for all |
| practical purposes is the interrupt-enabled flag. Set means enabled.	" |
'------------------------------------------------------------------------*/

#define Z_SNA_V48K_PC_VALUE 0x72

Z_DEFINE_STRICT_STRUCTURE_BEGIN
	zuint8	i;
	Z16Bit	hl_, de_, bc_, af_;
	Z16Bit	hl, de, bc, iy, ix;

	struct {Z_BIT_FIELD(8, 3) (
		zuint8 unused_0 :5,
		zuint8 iff2	:1,
		zuint8 unused_1 :2
	)} interrupt;

	zuint8	r;
	Z16Bit	af;
	zuint16	sp;
	zuint8	im;
	zuint8	border_color;
	zuint8	ram[1024 * 48];	/* RAM dump [16384-65535] */
Z_DEFINE_STRICT_STRUCTURE_END ZSNAv48K;

#define Z_SNA_IM_0 0
#define Z_SNA_IM_1 1
#define Z_SNA_IM_2 2

/* MARK: - v128K
.-------------------------------------------------------------------------.
| From SinclairFAQ:							  |
|									  |
| "  The 128K version of the SNA format is the same as above, with	  |
| extensions to include the extra memory banks of the 128K/+2 machines,	  |
| and fixes the problem with the PC being pushed onto the stack - now it  |
| is located in an extra variable in the file (and is not pushed onto the |
| stack at all). The first 49179 bytes of the snapshot are otherwise	  |
| exactly as described above.						  |
|									  |
|    The third RAM bank saved (ram_bank_n) is always the one currently    |
| paged, even if this is page 5 or 2 - in this case, the bank is actually |
| included twice. The remaining RAM banks are saved in ascending order.	  |
|									  |
|    Example: If RAM bank 4 is paged in, the snapshot is made up of banks |
| 5, 2 and 4 to start with, and banks 0, 1, 3, 6 and 7 afterwards. If RAM |
| bank 5 is paged in, the snapshot is made up of banks 5, 2 and 5 again,  |
| followed by banks 0, 1, 3, 4, 6 and 7.  "				  |
'------------------------------------------------------------------------*/

Z_DEFINE_STRICT_STRUCTURE_BEGIN
	zuint8	i;
	Z16Bit	hl_, de_, bc_, af_;
	Z16Bit	hl, de, bc, iy, ix;

	struct {Z_BIT_FIELD(8, 3) (
		zuint8 unused_0 :5,
		zuint8 iff2	:1,
		zuint8 unused_1 :2
	)} interrupt;

	zuint8	r;
	Z16Bit	af;
	zuint16	sp;
	zuint8	im;
	zuint8	border_color;
	zuint8	ram_bank_5[1024 * 16];
	zuint8	ram_bank_2[1024 * 16];
	zuint8	ram_bank_n[1024 * 16];
	zuint16	pc;
	zuint8	port_7ffd_value;
	zuint8	tr_dos_rom_paged; /* boolean */
	zuint8	remaining_ram_banks[1024 * 16 * 6];
Z_DEFINE_STRICT_STRUCTURE_END ZSNAv128K;

#endif /* _Z_formats_snapshot_machine_computer_ZX_Spectrum_SNA_H_ */
