/* Q Kit API - formats/storage medium image/audio/TAP.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3.
 ____________________________
/\			     \
\_| Extensions: .tap	      |
  | Endianness: Little	      |
  | Created by: Unknown	      |
  | Used by:	Many programs |
  |   ________________________|_
   \_/________________________*/

#ifndef __Q_formats_storage_medium_image_audio_TAP_H__
#define __Q_formats_storage_medium_image_audio_TAP_H__

#include <Q/types/base.h>

Q_DEFINE_STRICT_STRUCTURE (
	quint16 size;
	quint8	data[];
) QTAPBlock;

#define Q_TAP_BLOCK(p) ((QTAPBlock *)(p))

#endif /* __Q_formats_storage_medium_image_audio_TAP_H__ */
