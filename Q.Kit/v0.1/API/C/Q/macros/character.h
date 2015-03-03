/* Q API - macros/characters.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_macros_characters_H__
#define __Q_macros_characters_H__

#include <Q/inspection/character set.h>
#include <Q/macros/pointer.h>

#define Q_IS_ASCII(c)				((c) >= 0x00 && (c) <= 0x7F)
#define Q_IS_BLANK(c)				((c) ==  ' ' || (c) == '\t')
#define Q_IS_BINAY(c)				((c) ==  '0' || (c) ==  '1')

#if Q_CHARACTER_SET_IS_ASCII

#	define Q_IS_CONTROL(c)			(((c) & 0xE0) ==   0 || (c) == 0x7F)
#	define Q_IS_PRINTABLE(c)		( (c)	      >= ' ' && (c) <=	'~')
#	define Q_IS_GRAPHICAL(c)		( (c)	      >= '!' && (c) <=	'~')

#	define Q_SKIP_CONTROL(	    pointer)	Q_SKIP	  (CONTROL,   pointer)
#	define Q_SKIP_PRINTABLE(    pointer)	Q_SKIP	  (PRINTABLE, pointer)
#	define Q_SKIP_GRAPHICAL(    pointer)	Q_SKIP	  (GRAPHICAL, pointer)
#	define Q_SKIP_NON_CONTROL(  pointer)	Q_SKIP_NON(CONTROL,   pointer)
#	define Q_SKIP_NON_PRINTABLE(pointer)	Q_SKIP_NON(PRINTABLE, pointer)
#	define Q_SKIP_NON_GRAPHICAL(pointer)	Q_SKIP_NON(GRAPHICAL, pointer)

#endif

#if Q_DIGITS_ARE_CONSECUTIVE

#	define Q_IS_OCTAL_NUMBER(  c)		((c) >= '0' && (c) <= '7')
#	define Q_IS_DECIMAL_NUMBER(c)		((c) >= '0' && (c) <= '9')

#else

#	define Q_IS_OCTAL_NUMBER(  c)		((c) == '0' || (c) == '1' || (c) == '2' || \
						 (c) == '3' || (c) == '4' || (c) == '5' || \
						 (c) == '6' || (c) == '7')

#	define Q_IS_DECIMAL_NUMBER(c)		((c) == '0' || (c) == '1' || (c) == '2' || \
						 (c) == '3' || (c) == '4' || (c) == '5' || \
						 (c) == '6' || (c) == '7' || (c) == '8' || \
						 (c) == '9')
#endif

#if Q_LOWERCASE_LETTERS_ARE_CONSECUTIVE

#	define Q_IS_LOWERCASE_LETTER(c)		((c) >= 'a' && (c) <= 'z')

#else

#	define Q_IS_LOWERCASE_LETTER(c)		((c) == 'a' || (c) == 'b' || (c) == 'c' || \
						 (c) == 'd' || (c) == 'e' || (c) == 'f' || \
						 (c) == 'g' || (c) == 'h' || (c) == 'i' || \
						 (c) == 'j' || (c) == 'k' || (c) == 'l' || \
						 (c) == 'm' || (c) == 'n' || (c) == 'o' || \
						 (c) == 'p' || (c) == 'q' || (c) == 'r' || \
						 (c) == 's' || (c) == 't' || (c) == 'u' || \
						 (c) == 'v' || (c) == 'y' || (c) == 'x' || \
						 (c) == 'z')
#endif

#if Q_UPPERCASE_LETTERS_ARE_CONSECUTIVE

#	define Q_IS_UPPERCASE_LETTER(c)		((c) >= 'a' && (c) <= 'z')

#else

#	define Q_IS_UPPERCASE_LETTER(c)		((c) == 'A' || (c) == 'B' || (c) == 'C' || \
						 (c) == 'D' || (c) == 'E' || (c) == 'F' || \
						 (c) == 'G' || (c) == 'H' || (c) == 'I' || \
						 (c) == 'J' || (c) == 'K' || (c) == 'L' || \
						 (c) == 'M' || (c) == 'N' || (c) == 'O' || \
						 (c) == 'P' || (c) == 'Q' || (c) == 'R' || \
						 (c) == 'S' || (c) == 'T' || (c) == 'U' || \
						 (c) == 'V' || (c) == 'Y' || (c) == 'X' || \
						 (c) == 'Z')
#endif

#if Q_UPPERCASE_LETTERS_ARE_CONSECUTIVE && Q_LOWERCASE_LETTERS_ARE_CONSECUTIVE

#	if Q_CHARACTER_SET_IS_ASCII
#		define Q_IS_ALPHA(c)		(((c) & 0xDF) >= 'A' && ((c) & 0xDF) <= 'Z')
#	else
#		define Q_IS_ALPHA(c)		(((c) >= 'A' && (c) <= 'Z') || (((c) >= 'a' && (c) <= 'z')))
#	endif

#	define Q_LETTER_TO_LOWERCASE(c)		((c) >= 'A' && (c) <= 'Z' ? (c) - 'A' + 'a' : (c))
#	define Q_LETTER_TO_UPPERCASE(c)		((c) >= 'a' && (c) <= 'z' ? (c) - 'a' + 'A' : (c))

#endif

#define Q_IS_ALPHANUMERIC(c)			(Q_IS_DECIMAL(c) || Q_IS_ALPHA(c))

#define Q_IS_HEXADECIMAL_NUMBER	/* CORREGIR */	(Q_IS_DECIMAL	        (c) || \
						 Q_IS_UPPERERCASE_LETTER(c) || \
						 Q_IS_LOWERCASE_LETTER	(c))

#define Q_SKIP_ASCII(		    pointer)	Q_SKIP	  (ASCII,	     pointer)
#define Q_SKIP_BLANK(		    pointer)	Q_SKIP	  (BLANK,	     pointer)
#define Q_SKIP_BINARY(		    pointer)	Q_SKIP	  (BINARY,	     pointer)
#define Q_SKIP_OCTAL(		    pointer)	Q_SKIP	  (OCTAL,	     pointer)
#define Q_SKIP_DECIMAL(		    pointer)	Q_SKIP	  (DECIMAL,	     pointer)
#define Q_SKIP_HEXADECIMAL(	    pointer)	Q_SKIP	  (HEXADECIMAL,	     pointer)
#define Q_SKIP_LOWERCASE_LETTER(    pointer)	Q_SKIP	  (LOWERCASE_LETTER, pointer)
#define Q_SKIP_UPPERCASE_LETTER(    pointer)	Q_SKIP	  (UPPERCASE_LETTER, pointer)
#define Q_SKIP_ALPHA(		    pointer)	Q_SKIP	  (ALPHA,	     pointer)
#define Q_SKIP_ALPHANUMERIC(	    pointer)	Q_SKIP	  (ALPHANUMERIC,     pointer)
#define Q_SKIP_NON_ASCII(	    pointer)	Q_SKIP_NON(ASCII,	     pointer)
#define Q_SKIP_NON_BLANK(	    pointer)	Q_SKIP_NON(BLANK,	     pointer)
#define Q_SKIP_NON_BINARY(	    pointer)	Q_SKIP_NON(BINARY,	     pointer)
#define Q_SKIP_NON_OCTAL(	    pointer)	Q_SKIP_NON(OCTAL,	     pointer)
#define Q_SKIP_NON_DECIMAL(	    pointer)	Q_SKIP_NON(DECIMAL,	     pointer)
#define Q_SKIP_NON_HEXADECIMAL(	    pointer)	Q_SKIP_NON(HEXADECIMAL,	     pointer)
#define Q_SKIP_NON_LOWERCASE_LETTER(pointer)	Q_SKIP_NON(LOWERCASE_LETTER, pointer)
#define Q_SKIP_NON_UPPERCASE_LETTER(pointer)	Q_SKIP_NON(UPPERCASE_LETTER, pointer)
#define Q_SKIP_NON_ALPHA(	    pointer)	Q_SKIP_NON(ALPHA,	     pointer)
#define Q_SKIP_NON_ALPHANUMERIC(    pointer)	Q_SKIP_NON(ALPHANUMERIC,     pointer)

#endif /* __Q_macros_characters_H__ */
