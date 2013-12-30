/* Q API - formats/hardware snapshot/machine/ZX Spectrum/SNA.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2014 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3.

.---------------------------------------------.
| Extensions: .sna, .snap, .snapshot	      |
| Endianness: Little			      |
| Created by: Unknown			      |
|    Used by: Any decent ZX Spectrum emulator |
'--------------------------------------------*/

#ifndef __Q_formats_hardware_snapshot_machine_ZX_Spectrum_SNA_H__
#define __Q_formats_hardware_snapshot_machine_ZX_Spectrum_SNA_H__

#include <Q/types/base.h>
#include <Q/macros/bit field.h>

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

Q_DEFINE_STRICT_STRUCTURE (
	quint8	i;
	Q16Bit	hl_, de_, bc_, af_;
	Q16Bit	hl, de, bc, iy, ix;

	Q_8BIT_FIELD (
		quint8 unused1	 :5,
		quint8 iff2	 :1,
		quint8 unused2	 :2
	) interrupt;

	/*quint8 iff2;*/

	quint8	r;
	Q16Bit	af;
	quint16	sp;
	quint8	im;
	quint8	border_color;
	quint8	ram[1024 * 48];	/* RAM dump [16384-65535] */
) QSNAv48K;

#define Q_SNA_V48K(p) ((QSNAv48K *)(p))

#define Q_SNA_V48K_PC_VALUE	0x72
#define Q_SNA_IM_0		0
#define Q_SNA_IM_1		1
#define Q_SNA_IM_2		2

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

Q_DEFINE_STRICT_STRUCTURE (
	quint8	i;
	Q16Bit	hl_, de_, bc_, af_;
	Q16Bit	hl, de, bc, iy, ix;

	Q_8BIT_FIELD (
		quint8 unused1	 :5,
		quint8 iff2	 :1,
		quint8 unused2	 :2
	) interrupt;

	/*quint8 iff2;*/

	quint8	r;
	Q16Bit	af;
	quint16	sp;
	quint8	im;
	quint8	border_color;
	quint8	ram_bank_5[1024 * 16];
	quint8	ram_bank_2[1024 * 16];
	quint8	ram_bank_n[1024 * 16];
	quint16	pc;
	quint8	port_7ffd_value;
	quint8	tr_dos_rom_paged; /* boolean */
	quint8	remaining_ram_banks[1024 * 16 * 6];
) QSNAv128K;

#define Q_SNA_V128K(p) ((QSNAv128K *)(p))

#endif /* __Q_formats_hardware_snapshot_machine_ZX_Spectrum_SNA_H__ */
