/* Z Kit - formats/storage medium image/audio/TAP.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.

.---------------------------.
| Extensions: tap	    |
| Endianness: Little	    |
| Created by: Unknown	    |
|    Used by: Many programs |
'--------------------------*/

#ifndef _Z_formats_storage_medium_image_audio_TAP_H_
#define _Z_formats_storage_medium_image_audio_TAP_H_

#include <Z/types/base.h>

Z_DEFINE_STRICT_STRUCTURE (
	zuint16 size;
	Z_FLEXIBLE_ARRAY_MEMBER(zuint8 data[];)
) ZTAPBlock;

#endif /* _Z_formats_storage_medium_image_audio_TAP_H_ */
