/* Zeta API - Z/formats/snapshot/machine/computer/ZX_Spectrum/ZLS.h
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Information contributed by Troels Norgaard.
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.

 ___________________________________________________________________
|								    |
|	 Daft: Public.Snapshot.Computer.ZXSpectrum.ZLS		    |
|      Author: Zhivilov, Dmitriy Vladimirovich			    |
|  Extensions: .zls						    |
|  Endianness: Big						    |
|    Supports:							    |
|     Used by: ZX-Live <http://aminet.net/package/misc/emu/ZXLive>  |
|								    |
'==================================================================*/

#ifndef Z_formats_snapshot_machine_computer_ZX_Spectrum_ZLS_H
#define Z_formats_snapshot_machine_computer_ZX_Spectrum_ZLS_H

#include <Z/types/bitwise.h>

typedef Z_PACKED_STRUCTURE_BEGIN {
	ZInt64 signature; /* 'ZX-Live!' */
	ZInt16 af, bc, de, hl, ix, iy, af_, bc_, de_, hl_;
	zuint8 i, r;
	ZInt16 sp, pc;

	union {	zuint8 value;
		struct {Z_BIT_FIELD_MEMBERS(8, 4) (
			zuint8 unused :6,
			zuint8 iff2   :1,
			zuint8 iff1   :1,
			zuint8 im     :2
		)} fields;
	} interrupt;

	zuint8 halt_line;
} Z_PACKED_STRUCTURE_END Z_ZLS;

#endif /* Z_formats_snapshot_machine_computer_ZX_Spectrum_ZLS_H */
