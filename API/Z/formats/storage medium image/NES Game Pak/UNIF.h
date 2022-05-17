/* Zeta API - Z/formats/storage medium image/NES Game Pak/UNIF.h
 ______ ____________  ___
|__   /|  ___|__  __|/   \
  /  /_|  __|  |  | /  *  \
 /_____|_____| |__|/__/ \__\
Copyright (C) 2006-2022 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.

 ____________________________________________
|					     |
|  Extensions: unf, unif		     |
|  Created by: Carmel-Veilleux, Tennessee    |
|					     |
|  Reference:				     |
|  https://wiki.nesdev.com/w/index.php/UNIF  |
|					     |
'===========================================*/

#ifndef Z_formats_storage_medium_image_NES_Game_Pak_UNIF_H
#define Z_formats_storage_medium_image_NES_Game_Pak_UNIF_H

#include <Z/types/bitwise.h>

Z_DEFINE_PACKED_STRUCTURE ({
	ZInt32	signature; /* 55h, 4Eh, 49h, 46h ('UNIF') */
	zuint32 minimum_version_required;
	zuint8	zero[24];
}, Z_UNIFHeader);

#if Z_ISA_INTEGRAL_ENDIANNESS == Z_ENDIANNESS_LITTLE
#	define Z_UNIF_SIGNATURE 0x46494E55
#else
#	define Z_UNIF_SIGNATURE 0x554E4946
#endif

#endif /* Z_formats_storage_medium_image_NES_Game_Pak_UNIF_H */
