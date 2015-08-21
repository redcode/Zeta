/* Z Kit C API - formats/hardware snapshot/machine/ZX Spectrum/SEM.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.
 ______________________________________________________
/\						       \
\_| Extensions: .sem					|
  | Endianness: Little					|
  | Created by: Bernd Waschke				|
  | Used by:	ZX Spectrum-Emulator (SpecEmu) [MS-DOS] |
  |   __________________________________________________|_
   \_/__________________________________________________*/

#ifndef __Z_formats_hardware_snapshot_machine_ZX_Spectrum_SEM_H__
#define __Z_formats_hardware_snapshot_machine_ZX_Spectrum_SEM_H__

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

#define Z_SEM_SNAPSHOT(p) ((ZSEMSnapshot *)(p))
#define Z_SEM_POKE(    p) ((ZSEMPoke	 *)(p))
#define Z_SEM(	       p) ((ZSEM	 *)(p))

#endif /* __Z_formats_hardware_snapshot_machine_ZX_Spectrum_SEM_H__ */
