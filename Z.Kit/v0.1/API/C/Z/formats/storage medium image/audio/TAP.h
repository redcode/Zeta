/* Z Kit C API - formats/storage medium image/audio/TAP.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.
 ____________________________
/\			     \
\_| Extensions: .tap	      |
  | Endianness: Little	      |
  | Created by: Unknown	      |
  |    Used by: Many programs |
  |   ________________________|_
   \_/________________________*/

#ifndef __Z_formats_storage_medium_image_audio_TAP_H__
#define __Z_formats_storage_medium_image_audio_TAP_H__

#include <Z/types/base.h>

Z_DEFINE_STRICT_STRUCTURE (
	zuint16 size;
	zuint8	data[];
) ZTAPBlock;

#endif /* __Z_formats_storage_medium_image_audio_TAP_H__ */
