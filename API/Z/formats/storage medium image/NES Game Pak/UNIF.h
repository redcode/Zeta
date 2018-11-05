/* Z Kit - formats/storage medium image/NES Game Pak/UNIF.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.

This library is  free software: you can redistribute it  and/or modify it under
the terms  of the GNU  Lesser General Public License  as published by  the Free
Software Foundation, either  version 3 of the License, or  (at your option) any
later version.

This library is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

You should have received  a copy of the GNU Lesser General Public License along
with this library. If not, see <http://www.gnu.org/licenses/>.

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
