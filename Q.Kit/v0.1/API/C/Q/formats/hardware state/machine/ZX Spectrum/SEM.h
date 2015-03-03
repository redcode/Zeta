/* Q API - formats/hardware snapshot/machine/ZX Spectrum/SEM.h
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

#ifndef __Q_formats_hardware_snapshot_machine_ZX_Spectrum_SEM_H__
#define __Q_formats_hardware_snapshot_machine_ZX_Spectrum_SEM_H__

#include <Q/types/base.h>

Q_DEFINE_STRICT_STRUCTURE_BEGIN
	quint8	signature_size;	/* 5 */
	quint8	signature[5];	/* 'SPEC1' */
	quint8	ram[1024 * 48];
	Q16Bit	af,   bc,  de,	hl;
	Q16Bit	af_,  bc_, de_, hl_;
	quint16 pc,   sp;
	Q16Bit	ix,   iy;
	quint8	i,    zero1;
	quint8	r,    zero2;
	quint8	iff1, zero3;
	quint8	iff2, zero4;
	quint8	im,   zero5;
Q_DEFINE_STRICT_STRUCTURE_END QSEMSnapshot;

Q_DEFINE_STRICT_STRUCTURE (
	quint16 address;
	quint8	value;
) QSEMPoke;

Q_DEFINE_STRICT_STRUCTURE (
	QSEMSnapshot snapshot;
	QSEMPoke     poke;	   /* Optional */
	quint16	     speed_factor; /* Optional (only if poke included) */
) QSEM;

#define Q_SEM_SNAPSHOT(p) ((QSEMSnapshot *)(p))
#define Q_SEM_POKE(    p) ((QSEMPoke	 *)(p))
#define Q_SEM(	       p) ((QSEM	 *)(p))

#endif /* __Q_formats_hardware_snapshot_machine_ZX_Spectrum_SEM_H__ */
