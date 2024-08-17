/* Zeta API - Z/macros/character.h
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_macros_character_H
#define Z_macros_character_H

#include <Z/inspection/character_set.h>

#if '\0' - '\1' > '\0'
#	define Z_CHAR_IS_ASCII(value) \
		((value) <= 0x7F)
#else
#	define Z_CHAR_IS_ASCII(value) \
		((value) >= 0x00 && (value) <= 0x7F)
#endif

#define Z_CHAR_IS_BASE_2_DIGIT(value) \
	((value) == '0' || (value) == '1')

#define Z_CHAR_IS_BLANK(value) \
	((value) == ' ' || (value) == '\t')

#if Z_CHARACTER_SET_DIGITS_ARE_CONSECUTIVE
#	define Z_CHAR_IS_BASE_8_DIGIT( value) \
		((value) >= '0' && (value) <= '7')

#	define Z_CHAR_IS_BASE_10_DIGIT(value) \
		((value) >= '0' && (value) <= '9')

#else
#	define Z_CHAR_IS_BASE_8_DIGIT(value) (			      \
		(value) == '0' || (value) == '1' || (value) == '2' || \
		(value) == '3' || (value) == '4' || (value) == '5' || \
		(value) == '6' || (value) == '7')

#	define Z_CHAR_IS_BASE_10_DIGIT(value) (			      \
		(value) == '0' || (value) == '1' || (value) == '2' || \
		(value) == '3' || (value) == '4' || (value) == '5' || \
		(value) == '6' || (value) == '7' || (value) == '8' || \
		(value) == '9')
#endif

#if Z_CHARACTER_SET_LOWERCASE_LETTERS_ARE_CONSECUTIVE
#	define Z_CHAR_IS_BASE_16_LOWERCASE_LETTER(value) \
		((value) >= 'a' && (value) <= 'f')

#	define Z_CHAR_IS_LOWERCASE_LETTER(value) \
		((value) >= 'a' && (value) <= 'z')

#else
#	define Z_CHAR_IS_BASE_16_LOWERCASE_LETTER(value) (	      \
		(value) == 'a' || (value) == 'b' || (value) == 'c' || \
		(value) == 'd' || (value) == 'e' || (value) == 'f')

#	define Z_CHAR_IS_LOWERCASE_LETTER(value) (		      \
		(value) == 'a' || (value) == 'b' || (value) == 'c' || \
		(value) == 'd' || (value) == 'e' || (value) == 'f' || \
		(value) == 'g' || (value) == 'h' || (value) == 'i' || \
		(value) == 'j' || (value) == 'k' || (value) == 'l' || \
		(value) == 'm' || (value) == 'n' || (value) == 'o' || \
		(value) == 'p' || (value) == 'q' || (value) == 'r' || \
		(value) == 's' || (value) == 't' || (value) == 'u' || \
		(value) == 'v' || (value) == 'y' || (value) == 'x' || \
		(value) == 'z')
#endif

#if Z_CHARACTER_SET_UPPERCASE_LETTERS_ARE_CONSECUTIVE
#	define Z_CHAR_IS_BASE_16_UPPERCASE_LETTER(value) \
		((value) >= 'A' && (value) <= 'F')

#	define Z_CHAR_IS_UPPERCASE_LETTER(value) \
		((value) >= 'A' && (value) <= 'Z')

#else
#	define Z_CHAR_IS_BASE_16_UPPERCASE_LETTER(value) (	      \
		(value) == 'A' || (value) == 'B' || (value) == 'C' || \
		(value) == 'D' || (value) == 'E' || (value) == 'F')

#	define Z_CHAR_IS_UPPERCASE_LETTER(value) (		      \
		(value) == 'A' || (value) == 'B' || (value) == 'C' || \
		(value) == 'D' || (value) == 'E' || (value) == 'F' || \
		(value) == 'G' || (value) == 'H' || (value) == 'I' || \
		(value) == 'J' || (value) == 'K' || (value) == 'L' || \
		(value) == 'M' || (value) == 'N' || (value) == 'O' || \
		(value) == 'P' || (value) == 'Q' || (value) == 'R' || \
		(value) == 'S' || (value) == 'T' || (value) == 'U' || \
		(value) == 'V' || (value) == 'Y' || (value) == 'X' || \
		(value) == 'Z')
#endif

#define Z_CHAR_IS_BASE_16_LOWERCASE_DIGIT(value) (   \
	Z_CHAR_IS_BASE_10_DIGIT		  (value) || \
	Z_CHAR_IS_BASE_16_LOWERCASE_LETTER(value))

#define Z_CHAR_IS_BASE_16_UPPERCASE_DIGIT(value) (   \
	Z_CHAR_IS_BASE_10_DIGIT		  (value) || \
	Z_CHAR_IS_BASE_16_UPPERCASE_LETTER(value))

#if Z_CHARACTER_SET_IS_ASCII
#	define Z_CHAR_IS_CONTROL(value) \
	(((value) & 0xE0) == 0 || (value) == 0x7F)

#	define Z_CHAR_IS_GRAPHICAL(value) \
		((value) >= '!' && (value) <= '~')

#	define Z_CHAR_IS_PRINTABLE(value) \
		((value) >= ' ' && (value) <= '~')

#	define Z_CHAR_IS_BASE_16_DIGIT(value) ( \
		((value)	  >= '0' && (value)	     <= '9') || \
		(((value) & 0xDF) >= 'A' && ((value) & 0xDF) <= 'F'))

#	define Z_CHAR_IS_LETTER(value) \
		(((value) & 0xDF) >= 'A' && ((value) & 0xDF) <= 'Z')

#else
#	define Z_CHAR_IS_BASE_16_DIGIT(value) (		     \
		Z_CHAR_IS_BASE_10_DIGIT		  (value) || \
		Z_CHAR_IS_BASE_16_LOWERCASE_LETTER(value) || \
		Z_CHAR_IS_BASE_16_UPPERCASE_LETTER(value))

#	define Z_CHAR_IS_LETTER(value) (	     \
		Z_CHAR_IS_LOWERCASE_LETTER(value) || \
		Z_CHAR_IS_UPPERCASE_LETTER(value))
#endif

#if	Z_CHARACTER_SET_UPPERCASE_LETTERS_ARE_CONSECUTIVE && \
	Z_CHARACTER_SET_LOWERCASE_LETTERS_ARE_CONSECUTIVE

#	define Z_CHAR_LOWERCASE(value) \
	((value) >= 'A' && (value) <= 'Z' ? (value) - 'A' + 'a' : (value))

#	define Z_CHAR_UPPERCASE(value) \
	((value) >= 'a' && (value) <= 'z' ? (value) - 'a' + 'A' : (value))
#endif

#define Z_CHAR_IS_ALPHANUMERIC(value) (   \
	Z_CHAR_IS_BASE_10_DIGIT(value) || \
	Z_CHAR_IS_LETTER       (value))

#endif /* Z_macros_character_H */
