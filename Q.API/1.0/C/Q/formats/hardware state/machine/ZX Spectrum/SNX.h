/* Q API - formats/hardware snapshot/machine/ZX Spectrum/SNX.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2013 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3.

File extensions: snx
     Endianness: Little
     Created by: Christian Gandler
	Used by: Specci [ST]
 Last known URL: http://cd.textfiles.com/crawlycrypt1/apps/misc/zx_sp207 */

#ifndef __Q_formats_hardware_snapshot_machine_ZX_Spectrum_SNX_H__
#define __Q_formats_hardware_snapshot_machine_ZX_Spectrum_SNX_H__

#include <Q/types/basics.h>

typedef Q_STRICT_STRUCTURE (

) QSNX;

#define Q_SNX(p) ((QSNX *)(p))

#endif /* __Q_formats_hardware_snapshot_machine_ZX_Spectrum_SNX_H__ */
