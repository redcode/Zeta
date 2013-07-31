/* Q API - formats/hardware snapshot/machine/ZX Spectrum/SNP.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2013 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3.

File extensions: snp
     Endianness: Little
     Created by: Radovan Garabik and Lubomir Salanci
	Used by: Nuclear ZX [MS-DOS]
 Last known URL: http://korpus.juls.savba.sk/~garabik/old/zx.html */

#ifndef __Q_formats_hardware_snapshot_machine_ZX_Spectrum_SNP_H__
#define __Q_formats_hardware_snapshot_machine_ZX_Spectrum_SNP_H__

#include <Q/types/basics.h>

typedef Q_STRICT_STRUCTURE (
	quint8	ram[1024 * 48];
	Q16Bit	af;
	quint8	border_color;
	quint8	reserved;
	Q16Bit	bc, de, hl;
	quint16	pc, sp;
	Q16Bit	ix, iy;
	quint8	iff2;	/* not used actually */
	quint8	iff1;
	quint8	im;
	quint8	r, i;
	Q16Bit	af_, bc_, de_, hl_;
) QSNP;

#define Q_SNP(p) ((QSNP *)(p))

#endif /* __Q_formats_hardware_snapshot_machine_ZX_Spectrum_SNP_H__ */
