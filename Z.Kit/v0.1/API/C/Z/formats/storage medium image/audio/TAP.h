/* Z Kit C API - formats/storage medium image/audio/TAP.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright © 2006-2017 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.

.---------------------------.
| Extensions: tap	    |
| Endianness: Little	    |
| Created by: Unknown	    |
|    Used by: Many programs |
'--------------------------*/

#ifndef __Z_formats_storage_medium_image_audio_TAP_H__
#define __Z_formats_storage_medium_image_audio_TAP_H__

#include <Z/macros/filtering.h>

Z_DEFINE_STRICT_STRUCTURE (
	zuint16 size;
	Z_FLEXIBLE_ARRAY_MEMBER(zuint8 data[];)
) ZTAPBlock;

#endif /* __Z_formats_storage_medium_image_audio_TAP_H__ */
