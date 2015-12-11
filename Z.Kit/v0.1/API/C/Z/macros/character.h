/* Z Kit C API - macros/characters.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_macros_characters_H__
#define __Z_macros_characters_H__

#include <Z/inspection/character set.h>
#include <Z/macros/pointer.h>

#define Z_IS_ASCII(c) ((c) >= 0x00 && (c) <= 0x7F)
#define Z_IS_BLANK(c) ((c) ==  ' ' || (c) == '\t')
#define Z_IS_BINAY(c) ((c) ==  '0' || (c) ==  '1')

#if Z_CHARACTER_SET_IS_ASCII

#	define Z_IS_CONTROL(  c) (((c) & 0xE0) ==  0  || (c) == 0x7F)
#	define Z_IS_PRINTABLE(c) ( (c)	       >= ' ' && (c) <=	'~' )
#	define Z_IS_GRAPHICAL(c) ( (c)	       >= '!' && (c) <=	'~' )

#	define Z_SKIP_CONTROL(	    pointer) Z_SKIP    (CONTROL,   pointer)
#	define Z_SKIP_PRINTABLE(    pointer) Z_SKIP    (PRINTABLE, pointer)
#	define Z_SKIP_GRAPHICAL(    pointer) Z_SKIP    (GRAPHICAL, pointer)
#	define Z_SKIP_NON_CONTROL(  pointer) Z_SKIP_NON(CONTROL,   pointer)
#	define Z_SKIP_NON_PRINTABLE(pointer) Z_SKIP_NON(PRINTABLE, pointer)
#	define Z_SKIP_NON_GRAPHICAL(pointer) Z_SKIP_NON(GRAPHICAL, pointer)

#endif

#if Z_DIGITS_ARE_CONSECUTIVE

#	define Z_IS_OCTAL_NUMBER(  c)	((c) >= '0' && (c) <= '7')
#	define Z_IS_DECIMAL_NUMBER(c)	((c) >= '0' && (c) <= '9')

#else

#	define Z_IS_OCTAL_NUMBER(  c)	((c) == '0' || (c) == '1' || (c) == '2' || \
					 (c) == '3' || (c) == '4' || (c) == '5' || \
					 (c) == '6' || (c) == '7')

#	define Z_IS_DECIMAL_NUMBER(c)	((c) == '0' || (c) == '1' || (c) == '2' || \
					 (c) == '3' || (c) == '4' || (c) == '5' || \
					 (c) == '6' || (c) == '7' || (c) == '8' || \
					 (c) == '9')
#endif

#if Z_LOWERCASE_LETTERS_ARE_CONSECUTIVE

#	define Z_IS_LOWERCASE_LETTER(c)	((c) >= 'a' && (c) <= 'z')

#else

#	define Z_IS_LOWERCASE_LETTER(c)	((c) == 'a' || (c) == 'b' || (c) == 'c' || \
					 (c) == 'd' || (c) == 'e' || (c) == 'f' || \
					 (c) == 'g' || (c) == 'h' || (c) == 'i' || \
					 (c) == 'j' || (c) == 'k' || (c) == 'l' || \
					 (c) == 'm' || (c) == 'n' || (c) == 'o' || \
					 (c) == 'p' || (c) == 'q' || (c) == 'r' || \
					 (c) == 's' || (c) == 't' || (c) == 'u' || \
					 (c) == 'v' || (c) == 'y' || (c) == 'x' || \
					 (c) == 'z')
#endif

#if Z_UPPERCASE_LETTERS_ARE_CONSECUTIVE

#	define Z_IS_UPPERCASE_LETTER(c)	((c) >= 'a' && (c) <= 'z')

#else

#	define Z_IS_UPPERCASE_LETTER(c)	((c) == 'A' || (c) == 'B' || (c) == 'C' || \
					 (c) == 'D' || (c) == 'E' || (c) == 'F' || \
					 (c) == 'G' || (c) == 'H' || (c) == 'I' || \
					 (c) == 'J' || (c) == 'K' || (c) == 'L' || \
					 (c) == 'M' || (c) == 'N' || (c) == 'O' || \
					 (c) == 'P' || (c) == 'Q' || (c) == 'R' || \
					 (c) == 'S' || (c) == 'T' || (c) == 'U' || \
					 (c) == 'V' || (c) == 'Y' || (c) == 'X' || \
					 (c) == 'Z')
#endif

#define Z_IS_HEXADECIMAL_NUMBER(c)	(Z_IS_DECIMAL_NUMBER    (c) || \
					 Z_IS_UPPERERCASE_LETTER(c) || \
					 Z_IS_LOWERCASE_LETTER  (c))

#if Z_UPPERCASE_LETTERS_ARE_CONSECUTIVE && Z_LOWERCASE_LETTERS_ARE_CONSECUTIVE

#	if Z_CHARACTER_SET_IS_ASCII
#		define Z_IS_ALPHA(c) (((c) & 0xDF) >= 'A' && ((c) & 0xDF) <= 'Z')
#	else
#		define Z_IS_ALPHA(c) (((c) >= 'A' && (c) <= 'Z') || (((c) >= 'a' && (c) <= 'z')))
#	endif

#	define Z_LETTER_TO_LOWERCASE(c) ((c) >= 'A' && (c) <= 'Z' ? (c) - 'A' + 'a' : (c))
#	define Z_LETTER_TO_UPPERCASE(c) ((c) >= 'a' && (c) <= 'z' ? (c) - 'a' + 'A' : (c))

#endif

#define Z_IS_ALPHANUMERIC(c) (Z_IS_DECIMAL(c) || Z_IS_ALPHA(c))

#define Z_SKIP_ASCII(		    pointer) Z_SKIP    (ASCII,		  pointer)
#define Z_SKIP_BLANK(		    pointer) Z_SKIP    (BLANK,		  pointer)
#define Z_SKIP_BINARY(		    pointer) Z_SKIP    (BINARY,		  pointer)
#define Z_SKIP_OCTAL(		    pointer) Z_SKIP    (OCTAL,		  pointer)
#define Z_SKIP_DECIMAL(		    pointer) Z_SKIP    (DECIMAL,	  pointer)
#define Z_SKIP_HEXADECIMAL(	    pointer) Z_SKIP    (HEXADECIMAL,	  pointer)
#define Z_SKIP_LOWERCASE_LETTER(    pointer) Z_SKIP    (LOWERCASE_LETTER, pointer)
#define Z_SKIP_UPPERCASE_LETTER(    pointer) Z_SKIP    (UPPERCASE_LETTER, pointer)
#define Z_SKIP_ALPHA(		    pointer) Z_SKIP    (ALPHA,		  pointer)
#define Z_SKIP_ALPHANUMERIC(	    pointer) Z_SKIP    (ALPHANUMERIC,	  pointer)
#define Z_SKIP_NON_ASCII(	    pointer) Z_SKIP_NON(ASCII,		  pointer)
#define Z_SKIP_NON_BLANK(	    pointer) Z_SKIP_NON(BLANK,		  pointer)
#define Z_SKIP_NON_BINARY(	    pointer) Z_SKIP_NON(BINARY,		  pointer)
#define Z_SKIP_NON_OCTAL(	    pointer) Z_SKIP_NON(OCTAL,		  pointer)
#define Z_SKIP_NON_DECIMAL(	    pointer) Z_SKIP_NON(DECIMAL,	  pointer)
#define Z_SKIP_NON_HEXADECIMAL(	    pointer) Z_SKIP_NON(HEXADECIMAL,	  pointer)
#define Z_SKIP_NON_LOWERCASE_LETTER(pointer) Z_SKIP_NON(LOWERCASE_LETTER, pointer)
#define Z_SKIP_NON_UPPERCASE_LETTER(pointer) Z_SKIP_NON(UPPERCASE_LETTER, pointer)
#define Z_SKIP_NON_ALPHA(	    pointer) Z_SKIP_NON(ALPHA,		  pointer)
#define Z_SKIP_NON_ALPHANUMERIC(    pointer) Z_SKIP_NON(ALPHANUMERIC,     pointer)

#endif /* __Z_macros_characters_H__ */
