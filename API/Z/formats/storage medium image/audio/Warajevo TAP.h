/* Z Kit - formats/storage medium image/audio/Warajevo TAP.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 1993-2006 Zeljko Juric.
Copyright (C) 1993-2006 Samir Ribic.
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.

This library is free software: you can redistribute it and/or modify it
under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this library.  If not, see <http://www.gnu.org/licenses/>.

.------------------------------------------------------------------.
| Extensions: tap						   |
| Endianness: Little						   |
| Created by: Zeljko Juric - Samir Ribic (aka Megaribi)		   |
|    Used by: Warajevo [MS-DOS] and some old ZX Spectrum emulators |
'-----------------------------------------------------------------*/

#ifndef _Z_formats_storage_medium_image_audio_Warajevo_TAP_H_
#define _Z_formats_storage_medium_image_audio_Warajevo_TAP_H_

#include <Z/types/base.h>

Z_DEFINE_STRICT_STRUCTURE (
	zsint32 first_block_offset;
	zsint32 last_block_offset;
	zuint32 eof_marker;
) ZWarajevoTAPHeader;

Z_DEFINE_STRICT_STRUCTURE (
	zsint32 previous_block_offset;
	zsint32 next_block_offset;
	zuint16 data_size;
) ZWarajevoTAPBlockHeader;

#endif /* _Z_formats_storage_medium_image_audio_Warajevo_TAP_H_ */
