/* Z Kit C API - keys/text.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2017 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_keys_allocation_H__
#define __Z_keys_allocation_H__

#define Z_TEXT_ALIGNMENT_CENTER 0
#define Z_TEXT_ALIGNMENT_LEFT	1
#define Z_TEXT_ALIGNMENT_RIGHT	2

#define Z_KEY_BITS_TEXT_ALIGNMENT 8
#define Z_KEY_LAST_TEXT_ALIGNMENT Z_TEXT_ALIGNMENT_RIGHT

#define Z_TEXT_LINE_BREAK_MODE_WORD_WRAP	 0
#define Z_TEXT_LINE_BREAK_MODE_CLIP		 1
#define Z_TEXT_LINE_BREAK_MODE_HEAD_TRUNCATION	 2
#define Z_TEXT_LINE_BREAK_MODE_TAIL_TRUNCATION	 3
#define Z_TEXT_LINE_BREAK_MODE_MIDDLE_TRUNCATION 4

#define Z_KEY_BITS_TEXT_LINE_BREAK_MODE 8
#define Z_KEY_LAST_TEXT_LINE_BREAK_MODE Z_TEXT_LINE_BREAK_MODE_MIDDLE_TRUNCATION

#endif /* __Z_keys_text_H__ */
