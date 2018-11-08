/* Z Kit - formats/storage medium image/NES Game Pak/UNIF.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.

.----------------------------------------.
| Extensions: unf, unif			 |
| Endianness: Little			 |
| Created by: Carmel-Veilleux, Tennessee |
|    Used by:				 |
'---------------------------------------*/

#ifndef _Z_formats_storage_medium_image_NES_Game_Pak_UNIF_H_
#define _Z_formats_storage_medium_image_NES_Game_Pak_UNIF_H_

#include <Z/types/base.h>

Z_DEFINE_STRICT_STRUCTURE (
	zuint8	unif[4]; /* 55 4E 49 46 ('UNIF') */
	zuint32 minimum_version_required;
	zuint8	zero[24];
) ZUNIFHeader;

#endif /* _Z_formats_storage_medium_image_NES_Game_Pak_UNIF_H_ */
