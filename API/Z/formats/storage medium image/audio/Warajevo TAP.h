/* Zeta API - Z/formats/storage medium image/audio/Warajevo TAP.h
 ______ ____________  ___
|__   /|  ___|__  __|/   \
  /  /_|  __|  |  | /  *  \
 /_____|_____| |__|/__/ \__\
Copyright (C) 2006-2022 Manuel Sainz de Baranda y Goñi.
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

Z_DEFINE_PACKED_STRUCTURE ({
	zsint32 first_block_offset;
	zsint32 last_block_offset;
	zuint32 eof_marker;
}, Z_WarajevoTAPHeader);

Z_DEFINE_PACKED_STRUCTURE ({
	zsint32 previous_block_offset;
	zsint32 next_block_offset;
	zuint16 data_size;
}, Z_WarajevoTAPBlockHeader);

#endif /* Z_formats_storage_medium_image_audio_Warajevo_TAP_H */
