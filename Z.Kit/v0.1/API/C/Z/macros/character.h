/* Z Kit C API - macros/characters.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_|
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_macros_characters_H__
#define __Z_macros_characters_H__

#include <Z/inspection/character set.h>

#define Z_IS_ASCII(	  c) ((c) >= 0x00 && (c) <= 0x7F)
#define Z_IS_BLANK(	  c) ((c) ==  ' ' || (c) == '\t')
#define Z_IS_BINARY_DIGIT(c) ((c) ==  '0' || (c) ==  '1')

#if Z_CHARACTER_SET_IS_ASCII

#	define Z_IS_CONTROL(  c) (((c) & 0xE0) ==  0  || (c) == 0x7F)
#	define Z_IS_GRAPHICAL(c) ( (c)	       >= '!' && (c) <=	'~' )
#	define Z_IS_PRINTABLE(c) ( (c)	       >= ' ' && (c) <=	'~' )

#endif

#if Z_CHARACTER_SET_DIGITS_ARE_CONSECUTIVE

#	define Z_IS_OCTAL_DIGIT(  c) ((c) >= '0' && (c) <= '7')
#	define Z_IS_DECIMAL_DIGIT(c) ((c) >= '0' && (c) <= '9')

#else

#	define Z_IS_OCTAL_DIGIT(c) \
		((c) == '0' || (c) == '1' || (c) == '2' || \
		 (c) == '3' || (c) == '4' || (c) == '5' || \
		 (c) == '6' || (c) == '7')

#	define Z_IS_DECIMAL_DIGIT(c) \
		((c) == '0' || (c) == '1' || (c) == '2' || \
		 (c) == '3' || (c) == '4' || (c) == '5' || \
		 (c) == '6' || (c) == '7' || (c) == '8' || \
		 (c) == '9')

#endif

#if Z_CHARACTER_SET_LOWERCASE_LETTERS_ARE_CONSECUTIVE

#	define Z_IS_LOWERCASE_LETTER(		 c) ((c) >= 'a' && (c) <= 'z')
#	define Z_IS_LOWERCASE_HEXADECIMAL_LETTER(c) ((c) >= 'a' && (c) <= 'f')

#else

#	define Z_IS_LOWERCASE_LETTER(c) \
		((c) == 'a' || (c) == 'b' || (c) == 'c' || \
		 (c) == 'd' || (c) == 'e' || (c) == 'f' || \
		 (c) == 'g' || (c) == 'h' || (c) == 'i' || \
		 (c) == 'j' || (c) == 'k' || (c) == 'l' || \
		 (c) == 'm' || (c) == 'n' || (c) == 'o' || \
		 (c) == 'p' || (c) == 'q' || (c) == 'r' || \
		 (c) == 's' || (c) == 't' || (c) == 'u' || \
		 (c) == 'v' || (c) == 'y' || (c) == 'x' || \
		 (c) == 'z')

#	define Z_IS_LOWERCASE_HEXADECIMAL_LETTER(c) \
		((c) == 'a' || (c) == 'b' || (c) == 'c' || \
		 (c) == 'd' || (c) == 'e' || (c) == 'f')

#endif

#if Z_CHARACTER_SET_UPPERCASE_LETTERS_ARE_CONSECUTIVE

#	define Z_IS_UPPERCASE_LETTER(		 c) ((c) >= 'A' && (c) <= 'Z')
#	define Z_IS_UPPERCASE_HEXADECIMAL_LETTER(c) ((c) >= 'A' && (c) <= 'F')

#else

#	define Z_IS_UPPERCASE_LETTER(c) \
		((c) == 'A' || (c) == 'B' || (c) == 'C' || \
		 (c) == 'D' || (c) == 'E' || (c) == 'F' || \
		 (c) == 'G' || (c) == 'H' || (c) == 'I' || \
		 (c) == 'J' || (c) == 'K' || (c) == 'L' || \
		 (c) == 'M' || (c) == 'N' || (c) == 'O' || \
		 (c) == 'P' || (c) == 'Q' || (c) == 'R' || \
		 (c) == 'S' || (c) == 'T' || (c) == 'U' || \
		 (c) == 'V' || (c) == 'Y' || (c) == 'X' || \
		 (c) == 'Z')

#	define Z_IS_UPPERCASE_HEXADECIMAL_LETTER(c) \
		((c) == 'A' || (c) == 'B' || (c) == 'C' || \
		 (c) == 'D' || (c) == 'E' || (c) == 'F')

#endif

#define Z_IS_LOWERCASE_HEXADECIMAL_DIGIT(c) \
	(Z_IS_DECIMAL_DIGIT(c) || Z_IS_LOWERCASE_HEXADECIMAL_LETTER(c))

#define Z_IS_UPPERCASE_HEXADECIMAL_DIGIT(c) \
	(Z_IS_DECIMAL_DIGIT(c) || Z_IS_UPPERCASE_HEXADECIMAL_LETTER(c))

#if Z_CHARACTER_SET_IS_ASCII

#	define Z_IS_HEXADECIMAL_DIGIT(c) \
		(((c) >= '0' && (c) <= '9') || \
		 (((c) & 0xDF) >= 'A' && ((c) & 0xDF) <= 'F'))

#	define Z_IS_LETTER(c) (((c) & 0xDF) >= 'A' && ((c) & 0xDF) <= 'Z')

#else

#	define Z_IS_HEXADECIMAL_DIGIT(c) \
		(Z_IS_DECIMAL_DIGIT		  (c) || \
		 Z_IS_LOWERCASE_HEXADECIMAL_LETTER(c) || \
		 Z_IS_UPPERCASE_HEXADECIMAL_LETTER(c))

#	define Z_IS_LETTER(c) (Z_IS_LOWERCASE_LETTER(c) || Z_IS_UPPERCASE_LETTER(c))

#endif

#if	Z_CHARACTER_SET_UPPERCASE_LETTERS_ARE_CONSECUTIVE && \
	Z_CHARACTER_SET_LOWERCASE_LETTERS_ARE_CONSECUTIVE

#	define Z_TO_LOWERCASE(c) ((c) >= 'A' && (c) <= 'Z' ? (c) - 'A' + 'a' : (c))
#	define Z_TO_UPPERCASE(c) ((c) >= 'a' && (c) <= 'z' ? (c) - 'a' + 'A' : (c))

#endif

#define Z_IS_ALPHANUMERIC(c) (Z_IS_DECIMAL_DIGIT(c) || Z_IS_LETTER(c))

#endif /* __Z_macros_characters_H__ */
