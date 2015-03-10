/* Q Kit C API - keys/text.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_keys_allocation_H__
#define __Q_keys_allocation_H__

#define Q_TEXT_ALIGNMENT_CENTER 0
#define Q_TEXT_ALIGNMENT_LEFT	1
#define Q_TEXT_ALIGNMENT_RIGHT	2

#define Q_KEY_BITS_TEXT_ALIGNMENT 8
#define Q_KEY_LAST_TEXT_ALIGNMENT Q_TEXT_ALIGNMENT_RIGHT

#define Q_TEXT_LINE_BREAK_MODE_WORD_WRAP	 0
#define Q_TEXT_LINE_BREAK_MODE_CLIP		 1
#define Q_TEXT_LINE_BREAK_MODE_HEAD_TRUNCATION	 2
#define Q_TEXT_LINE_BREAK_MODE_TAIL_TRUNCATION	 3
#define Q_TEXT_LINE_BREAK_MODE_MIDDLE_TRUNCATION 4

#define Q_KEY_BITS_TEXT_LINE_BREAK_MODE 8
#define Q_KEY_LAST_TEXT_LINE_BREAK_MODE Q_TEXT_LINE_BREAK_MODE_MIDDLE_TRUNCATION

#endif /* __Q_keys_text_H__ */
