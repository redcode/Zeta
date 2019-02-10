/* Z Kit - formats/storage medium image/audio/TAP.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2019 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.

.---------------------------.
| Extensions: tap	    |
| Endianness: Little	    |
| Created by: Unknown	    |
|    Used by: Many programs |
'--------------------------*/

#ifndef Z_formats_storage_medium_image_audio_TAP_H_
#define Z_formats_storage_medium_image_audio_TAP_H_

#include <Z/types/fundamental.h>
#include <Z/macros/structure.h>

Z_DEFINE_PACKED_STRUCTURE ({
	zuint16 size;
	Z_FAM(zuint8 data[];)
}, ZTAPBlock);

#endif /* Z_formats_storage_medium_image_audio_TAP_H_ */
