/* Z Kit - formats/snapshot/machine/computer/ZX Spectrum/SEM.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.

.-----------------------------------------------------.
| Extensions: sem				      |
| Endianness: Little				      |
| Created by: Waschke, Bernd			      |
|    Used by: ZX Spectrum-Emulator (SpecEmu) [MS-DOS] |
'----------------------------------------------------*/

#ifndef _Z_formats_snapshot_machine_computer_ZX_Spectrum_SEM_H_
#define _Z_formats_snapshot_machine_computer_ZX_Spectrum_SEM_H_

#include <Z/types/base.h>

Z_DEFINE_STRICT_STRUCTURE_BEGIN
	zuint8	signature_size;	/* 5 */
	zuint8	signature[5];	/* 'SPEC1' */
	zuint8	ram[1024 * 48];
	Z16Bit	af,   bc,  de,	hl;
	Z16Bit	af_,  bc_, de_, hl_;
	zuint16 pc,   sp;
	Z16Bit	ix,   iy;
	zuint8	i,    zero_0;
	zuint8	r,    zero_1;
	zuint8	iff1, zero_2;
	zuint8	iff2, zero_3;
	zuint8	im,   zero_4;
Z_DEFINE_STRICT_STRUCTURE_END ZSEMSnapshot;

Z_DEFINE_STRICT_STRUCTURE (
	zuint16 address;
	zuint8	value;
) ZSEMPoke;

Z_DEFINE_STRICT_STRUCTURE (
	ZSEMSnapshot snapshot;
	ZSEMPoke     poke;	   /* Optional */
	zuint16	     speed_factor; /* Optional (only if poke included) */
) ZSEM;

#endif /* _Z_formats_snapshot_machine_computer_ZX_Spectrum_SEM_H_ */
