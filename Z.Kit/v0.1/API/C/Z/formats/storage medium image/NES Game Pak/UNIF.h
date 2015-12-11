/* Z Kit C API - formats/storage medium image/NES Game Pak/UNIF.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.

.----------------------------------------.
| Extensions: unf, unif			 |
| Endianness:	Little			 |
| Created by: Carmel-Veilleux, Tennessee |
|    Used by:				 |
'---------------------------------------*/

#ifndef __Z_formats_storage_medium_image_NES_Game_Pak_UNIF_H__
#define __Z_formats_storage_medium_image_NES_Game_Pak_UNIF_H__

#include <Z/types/base.h>

Z_DEFINE_STRICT_STRUCTURE (
	zuint8	unif[4]; /* 55 4E 49 46 ('UNIF') */
	zuint32 minimum_version_required;
	zuint8	zero[24];
) ZUNIFHeader;

#endif /* __Z_formats_storage_medium_image_NES_Game_Pak_UNIF_H__ */
