/* Zeta API - Z/formats/storage_medium_image/audio/Warajevo TAP.h
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.

.------------------------------------------------------------------.
| Extensions: tap						   |
| Endianness: Little						   |
| Created by: Juric, Zeljko - Ribic, Samir (aka Megaribi)	   |
|    Used by: Warajevo [MS-DOS] and some old ZX Spectrum emulators |
'=================================================================*/

#ifndef Z_formats_storage_medium_image_audio_Warajevo_TAP_H
#define Z_formats_storage_medium_image_audio_Warajevo_TAP_H

#include <Z/types/integral.h>
#include <Z/macros/language.h>

typedef Z_PACKED_STRUCTURE_BEGIN {
	zsint32 first_block_offset;
	zsint32 last_block_offset;
	zuint32 eof_marker;
} Z_PACKED_STRUCTURE_END Z_WarajevoTAPHeader;

typedef Z_PACKED_STRUCTURE_BEGIN {
	zsint32 previous_block_offset;
	zsint32 next_block_offset;
	zuint16 data_size;
} Z_PACKED_STRUCTURE_END Z_WarajevoTAPBlockHeader;

#endif /* Z_formats_storage_medium_image_audio_Warajevo_TAP_H */
