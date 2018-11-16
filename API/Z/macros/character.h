/* Z Kit - macros/character.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_macros_character_H_
#define _Z_macros_character_H_

#include <Z/inspection/character set.h>

#if ('\0' - 1) > 0
#	define Z_CHARACTER_IS_ASCII(c) \
		((c) <= 0x7F)
#else
#	define Z_CHARACTER_IS_ASCII(c) \
		((c) >= 0x00 && (c) <= 0x7F)
#endif

#define Z_CHARACTER_IS_BASE_2_DIGIT(c) \
	((c) == '0' || (c) == '1')

#define Z_CHARACTER_IS_BLANK(c) \
	((c) == ' ' || (c) == '\t')

#if Z_CHARACTER_SET_IS_ASCII

#	define Z_CHARACTER_IS_CONTROL(c) \
		(((c) & 0xE0) == 0 || (c) == 0x7F)

#	define Z_CHARACTER_IS_GRAPHICAL(c) \
		((c) >= '!' && (c) <= '~')

#	define Z_CHARACTER_IS_PRINTABLE(c) \
		((c) >= ' ' && (c) <= '~')

#endif

#if Z_CHARACTER_SET_DIGITS_ARE_CONSECUTIVE

#	define Z_CHARACTER_IS_BASE_8_DIGIT(c) \
		((c) >= '0' && (c) <= '7')

#	define Z_CHARACTER_IS_BASE_10_DIGIT(c) \
		((c) >= '0' && (c) <= '9')

#else

#	define Z_CHARACTER_IS_BASE_8_DIGIT(c)		   \
		((c) == '0' || (c) == '1' || (c) == '2' || \
		 (c) == '3' || (c) == '4' || (c) == '5' || \
		 (c) == '6' || (c) == '7')

#	define Z_CHARACTER_IS_BASE_10_DIGIT(c)		   \
		((c) == '0' || (c) == '1' || (c) == '2' || \
		 (c) == '3' || (c) == '4' || (c) == '5' || \
		 (c) == '6' || (c) == '7' || (c) == '8' || \
		 (c) == '9')

#endif

#if Z_CHARACTER_SET_LOWERCASE_LETTERS_ARE_CONSECUTIVE

#	define Z_CHARACTER_IS_BASE_16_LOWERCASE_LETTER(c) \
		((c) >= 'a' && (c) <= 'f')

#	define Z_CHARACTER_IS_LOWERCASE_LETTER(c) \
		((c) >= 'a' && (c) <= 'z')

#else

#	define Z_CHARACTER_IS_BASE_16_LOWERCASE_LETTER(c)  \
		((c) == 'a' || (c) == 'b' || (c) == 'c' || \
		 (c) == 'd' || (c) == 'e' || (c) == 'f')

#	define Z_CHARACTER_IS_LOWERCASE_LETTER(c)	   \
		((c) == 'a' || (c) == 'b' || (c) == 'c' || \
		 (c) == 'd' || (c) == 'e' || (c) == 'f' || \
		 (c) == 'g' || (c) == 'h' || (c) == 'i' || \
		 (c) == 'j' || (c) == 'k' || (c) == 'l' || \
		 (c) == 'm' || (c) == 'n' || (c) == 'o' || \
		 (c) == 'p' || (c) == 'q' || (c) == 'r' || \
		 (c) == 's' || (c) == 't' || (c) == 'u' || \
		 (c) == 'v' || (c) == 'y' || (c) == 'x' || \
		 (c) == 'z')

#endif

#if Z_CHARACTER_SET_UPPERCASE_LETTERS_ARE_CONSECUTIVE

#	define Z_CHARACTER_IS_BASE_16_UPPERCASE_LETTER(c) \
		((c) >= 'A' && (c) <= 'F')

#	define Z_CHARACTER_IS_UPPERCASE_LETTER(c) \
		((c) >= 'A' && (c) <= 'Z')

#else

#	define Z_CHARACTER_IS_BASE_16_UPPERCASE_LETTER(c)  \
		((c) == 'A' || (c) == 'B' || (c) == 'C' || \
		 (c) == 'D' || (c) == 'E' || (c) == 'F')

#	define Z_CHARACTER_IS_UPPERCASE_LETTER(c)			 \
		((c) == 'A' || (c) == 'B' || (c) == 'C' || (c) == 'D' || \
		 (c) == 'E' || (c) == 'F' || (c) == 'G' || (c) == 'H' || \
		 (c) == 'I' || (c) == 'J' || (c) == 'K' || (c) == 'L' || \
		 (c) == 'M' || (c) == 'N' || (c) == 'O' || (c) == 'P' || \
		 (c) == 'Q' || (c) == 'R' || (c) == 'S' || (c) == 'T' || \
		 (c) == 'U' || (c) == 'V' || (c) == 'Y' || (c) == 'X' || \
		 (c) == 'Z')

#endif

#define Z_CHARACTER_IS_BASE_16_LOWERCASE_DIGIT(c)      \
	(Z_CHARACTER_IS_BASE_10_DIGIT		(c) || \
	 Z_CHARACTER_IS_BASE_16_LOWERCASE_LETTER(c))

#define Z_CHARACTER_IS_BASE_16_UPPERCASE_DIGIT(c)      \
	(Z_CHARACTER_IS_BASE_10_DIGIT		(c) || \
	 Z_CHARACTER_IS_BASE_16_UPPERCASE_LETTER(c))

#if Z_CHARACTER_SET_IS_ASCII

#	define Z_CHARACTER_IS_BASE_16_DIGIT(c) \
		(((c) >= '0' && (c) <= '9') || \
		 (((c) & 0xDF) >= 'A' && ((c) & 0xDF) <= 'F'))

#	define Z_CHARACTER_IS_LETTER(c) \
		(((c) & 0xDF) >= 'A' && ((c) & 0xDF) <= 'Z')

#else

#	define Z_CHARACTER_IS_BASE_16_DIGIT(c)		       \
		(Z_CHARACTER_IS_BASE_10_DIGIT		(c) || \
		 Z_CHARACTER_IS_BASE_16_LOWERCASE_LETTER(c) || \
		 Z_CHARACTER_IS_BASE_16_UPPERCASE_LETTER(c))

#	define Z_CHARACTER_IS_LETTER(c) \
		(Z_CHARACTER_IS_LOWERCASE_LETTER(c) || \
		 Z_CHARACTER_IS_UPPERCASE_LETTER(c))

#endif

#if	Z_CHARACTER_SET_UPPERCASE_LETTERS_ARE_CONSECUTIVE && \
	Z_CHARACTER_SET_LOWERCASE_LETTERS_ARE_CONSECUTIVE

#	define Z_CHARACTER_LOWERCASE(c) \
		((c) >= 'A' && (c) <= 'Z' ? (c) - 'A' + 'a' : (c))

#	define Z_CHARACTER_UPPERCASE(c) \
		((c) >= 'a' && (c) <= 'z' ? (c) - 'a' + 'A' : (c))

#endif

#define Z_CHARACTER_IS_ALPHANUMERIC(c) \
	(Z_CHARACTER_IS_BASE_10_DIGIT(c) || Z_CHARACTER_IS_LETTER(c))

#endif /* _Z_macros_character_H_ */
