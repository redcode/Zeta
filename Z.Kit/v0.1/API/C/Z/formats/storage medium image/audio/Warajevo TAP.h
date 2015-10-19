/* Z Kit C API - formats/storage medium image/audio/Warajevo TAP.h

Copyright © 1993-2006 Zeljko Juric
Copyright © 1993-2006 Samir Ribic
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.
 ___________________________________________________________________
/\								    \
\_| Extensions: .tap						     |
  | Endianness: Little						     |
  | Created by: Zeljko Juric - Samir Ribic (aka Megaribi)	     |
  | Used by:	Warajevo [MS-DOS] and some old ZX Spectrum emulators |
  |   _______________________________________________________________|_
   \_/_______________________________________________________________*/

#ifndef __Z_formats_storage_medium_image_audio_Warajevo_TAP_H__
#define __Z_formats_storage_medium_image_audio_Warajevo_TAP_H__

#include <Z/types/base.h>

Z_DEFINE_STRICT_STRUCTURE (
	zint32	first_block_offset;
	zint32	last_block_offset;
	zuint32 eof_marker;
) ZWarajevoTAPHeader;

Z_DEFINE_STRICT_STRUCTURE (
	zint32	previous_block_offset;
	zint32	next_block_offset;
	zuint16 data_size;
) ZWarajevoTAPBlockHeader;

#endif /* __Z_formats_storage_medium_image_audio_Warajevo_TAP_H__ */
