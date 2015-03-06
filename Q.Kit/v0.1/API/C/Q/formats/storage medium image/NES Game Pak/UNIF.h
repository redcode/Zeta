/* Q C API - formats/storage medium image/NES Game Pak/UNIF.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.
 _________________________________________
/\					  \
\_| Extensions: .unf .unif		   |
  | Endianness:	Little			   |
  | Created by: Carmel-Veilleux, Tennessee |
  | Used by:				   |
  |   _____________________________________|_
   \_/_____________________________________*/

#ifndef __Q_formats_storage_medium_image_NES_Game_Pak_UNIF_H__
#define __Q_formats_storage_medium_image_NES_Game_Pak_UNIF_H__

#include <Q/types/base.h>

Q_DEFINE_STRICT_STRUCTURE (
	quint8	unif[4]; /* 55 4E 49 46 ('UNIF') */
	quint32 minimum_version_required;
	quint8	zero[24];
) QUNIFHeader;

#define Q_UNIF_HEADER(p) ((QUNIFHeader *)(p))

#endif /* __Q_formats_storage_medium_image_NES_Game_Pak_UNIF_H__ */
