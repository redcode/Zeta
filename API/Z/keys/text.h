/* Z Kit - keys/text.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.

This library is free software: you can redistribute it and/or modify it
under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this library.  If not, see <http://www.gnu.org/licenses/>. */

#ifndef _Z_keys_allocation_H_
#define _Z_keys_allocation_H_

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

#endif /* _Z_keys_text_H_ */
