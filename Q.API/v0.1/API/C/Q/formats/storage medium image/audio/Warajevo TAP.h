/* Q API - formats/storage medium image/audio/Warajevo TAP.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 1993-2006 Zeljko Juric
Copyright © 1993-2006 Samir Ribic
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3.
 ___________________________________________________________________
/\								    \
\_| Extensions: .tap						     |
  | Endianness: Little						     |
  | Created by: Zeljko Juric - Samir Ribic (aka Megaribi)	     |
  | Used by:	Warajevo [MS-DOS] and some old ZX Spectrum emulators |
  |   _______________________________________________________________|_
   \_/_______________________________________________________________*/

#ifndef __Q_formats_storage_medium_image_audio_TAP_H__
#define __Q_formats_storage_medium_image_audio_TAP_H__

#include <Q/types/base.h>

Q_DEFINE_STRICT_STRUCTURE (
	qint32	first_block_offset;
	qint32	last_block_offset;
	quint32 eof_marker;
) QWarajevoTAPHeader;

Q_DEFINE_STRICT_STRUCTURE (
	qint32	previous_block_offset;
	qint32	next_block_offset;
	quint16 data_size;
) QWarajevoTAPBlockHeader;

#endif /* __Q_formats_storage_medium_image_audio_TAP_H__ */
