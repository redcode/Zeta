/* Z Kit - macros/character.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2019 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_macros_character_H
#define Z_macros_character_H

#include <Z/inspection/character set.h>

#if ('\0' - 1) > 0
#	define Z_CHARACTER_IS_ASCII(character) \
		((character) <= 0x7F)
#else
#	define Z_CHARACTER_IS_ASCII(character) \
		((character) >= 0x00 && (character) <= 0x7F)
#endif

#define Z_CHARACTER_IS_BASE_2_DIGIT(character) \
	((character) == '0' || (character) == '1')

#define Z_CHARACTER_IS_BLANK(character) \
	((character) == ' ' || (character) == '\t')

#if Z_CHARACTER_SET_IS_ASCII

#	define Z_CHARACTER_IS_CONTROL(character) \
		(((character) & 0xE0) == 0 || (character) == 0x7F)

#	define Z_CHARACTER_IS_GRAPHICAL(character) \
		((character) >= '!' && (character) <= '~')

#	define Z_CHARACTER_IS_PRINTABLE(character) \
		((character) >= ' ' && (character) <= '~')

#endif

#if Z_CHARACTER_SET_DIGITS_ARE_CONSECUTIVE

#	define Z_CHARACTER_IS_BASE_8_DIGIT(character) \
		((character) >= '0' && (character) <= '7')

#	define Z_CHARACTER_IS_BASE_10_DIGIT(character) \
		((character) >= '0' && (character) <= '9')

#else

#	define Z_CHARACTER_IS_BASE_8_DIGIT(character)	     \
		((character) == '0' || (character) == '1' || \
		 (character) == '2' || (character) == '3' || \
		 (character) == '4' || (character) == '5' || \
		 (character) == '6' || (character) == '7')

#	define Z_CHARACTER_IS_BASE_10_DIGIT(character)	     \
		((character) == '0' || (character) == '1' || \
		 (character) == '2' || (character) == '3' || \
		 (character) == '4' || (character) == '5' || \
		 (character) == '6' || (character) == '7' || \
		 (character) == '8' || (character) == '9')

#endif

#if Z_CHARACTER_SET_LOWERCASE_LETTERS_ARE_CONSECUTIVE

#	define Z_CHARACTER_IS_BASE_16_LOWERCASE_LETTER(character) \
		((character) >= 'a' && (character) <= 'f')

#	define Z_CHARACTER_IS_LOWERCASE_LETTER(character) \
		((character) >= 'a' && (character) <= 'z')

#else

#	define Z_CHARACTER_IS_BASE_16_LOWERCASE_LETTER(character) \
		((character) == 'a' || (character) == 'b' ||	  \
		 (character) == 'c' || (character) == 'd' ||	  \
		 (character) == 'e' || (character) == 'f')

#	define Z_CHARACTER_IS_LOWERCASE_LETTER(character)    \
		((character) == 'a' || (character) == 'b' || \
		 (character) == 'c' || (character) == 'd' || \
		 (character) == 'e' || (character) == 'f' || \
		 (character) == 'g' || (character) == 'h' || \
		 (character) == 'i' || (character) == 'j' || \
		 (character) == 'k' || (character) == 'l' || \
		 (character) == 'm' || (character) == 'n' || \
		 (character) == 'o' || (character) == 'p' || \
		 (character) == 'q' || (character) == 'r' || \
		 (character) == 's' || (character) == 't' || \
		 (character) == 'u' || (character) == 'v' || \
		 (character) == 'y' || (character) == 'x' || \
		 (character) == 'z')

#endif

#if Z_CHARACTER_SET_UPPERCASE_LETTERS_ARE_CONSECUTIVE

#	define Z_CHARACTER_IS_BASE_16_UPPERCASE_LETTER(character) \
		((character) >= 'A' && (character) <= 'F')

#	define Z_CHARACTER_IS_UPPERCASE_LETTER(character) \
		((character) >= 'A' && (character) <= 'Z')

#else

#	define Z_CHARACTER_IS_BASE_16_UPPERCASE_LETTER(character) \
		((character) == 'A' || (character) == 'B' ||	  \
		 (character) == 'C' || (character) == 'D' ||	  \
		 (character) == 'E' || (character) == 'F')

#	define Z_CHARACTER_IS_UPPERCASE_LETTER(character)    \
		((character) == 'A' || (character) == 'B' || \
		 (character) == 'C' || (character) == 'D' || \
		 (character) == 'E' || (character) == 'F' || \
		 (character) == 'G' || (character) == 'H' || \
		 (character) == 'I' || (character) == 'J' || \
		 (character) == 'K' || (character) == 'L' || \
		 (character) == 'M' || (character) == 'N' || \
		 (character) == 'O' || (character) == 'P' || \
		 (character) == 'Q' || (character) == 'R' || \
		 (character) == 'S' || (character) == 'T' || \
		 (character) == 'U' || (character) == 'V' || \
		 (character) == 'Y' || (character) == 'X' || \
		 (character) == 'Z')

#endif

#define Z_CHARACTER_IS_BASE_16_LOWERCASE_DIGIT(character)      \
	(Z_CHARACTER_IS_BASE_10_DIGIT		(character) || \
	 Z_CHARACTER_IS_BASE_16_LOWERCASE_LETTER(character))

#define Z_CHARACTER_IS_BASE_16_UPPERCASE_DIGIT(character)      \
	(Z_CHARACTER_IS_BASE_10_DIGIT		(character) || \
	 Z_CHARACTER_IS_BASE_16_UPPERCASE_LETTER(character))

#if Z_CHARACTER_SET_IS_ASCII

#	define Z_CHARACTER_IS_BASE_16_DIGIT(character) \
		(((character) >= '0' && (character) <= '9') || \
		 (((character) & 0xDF) >= 'A' && ((character) & 0xDF) <= 'F'))

#	define Z_CHARACTER_IS_LETTER(character) \
		(((character) & 0xDF) >= 'A' && ((character) & 0xDF) <= 'Z')

#else

#	define Z_CHARACTER_IS_BASE_16_DIGIT(character)		       \
		(Z_CHARACTER_IS_BASE_10_DIGIT		(character) || \
		 Z_CHARACTER_IS_BASE_16_LOWERCASE_LETTER(character) || \
		 Z_CHARACTER_IS_BASE_16_UPPERCASE_LETTER(character))

#	define Z_CHARACTER_IS_LETTER(character)		       \
		(Z_CHARACTER_IS_LOWERCASE_LETTER(character) || \
		 Z_CHARACTER_IS_UPPERCASE_LETTER(character))

#endif

#if	Z_CHARACTER_SET_UPPERCASE_LETTERS_ARE_CONSECUTIVE && \
	Z_CHARACTER_SET_LOWERCASE_LETTERS_ARE_CONSECUTIVE

#	define Z_CHARACTER_LOWERCASE(character)		  \
		((character) >= 'A' && (character) <= 'Z' \
			? (character) - 'A' + 'a'	  \
			: (character))

#	define Z_CHARACTER_UPPERCASE(character)		  \
		((character) >= 'a' && (character) <= 'z' \
			? (character) - 'a' + 'A'	  \
			: (character))

#endif

#define Z_CHARACTER_IS_ALPHANUMERIC(character)	    \
	(Z_CHARACTER_IS_BASE_10_DIGIT(character) || \
	 Z_CHARACTER_IS_LETTER	     (character))

#endif /* Z_macros_character_H */
