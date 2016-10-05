/* Z Kit C API - functions/base/character.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_functions_base_character_H__
#define __Z_functions_base_character_H__

#include <Z/types/base.h>
#include <Z/macros/character.h>


Z_INLINE zboolean z_is_ascii(zcharacter character)
	{return Z_IS_ASCII(character);}


Z_INLINE zboolean z_is_blank(zcharacter character)
	{return Z_IS_BLANK(character);}


Z_INLINE zboolean z_is_binary_digit(zcharacter character)
	{return Z_IS_BINARY_DIGIT(character);}


Z_INLINE zboolean z_is_control(zcharacter character)
	{return Z_IS_CONTROL(character);}


Z_INLINE zboolean z_is_graphical(zcharacter character)
	{return Z_IS_GRAPHICAL(character);}


Z_INLINE zboolean z_is_printable(zcharacter character)
	{return Z_IS_PRINTABLE(character);}


Z_INLINE zboolean z_is_octal_digit(zcharacter character)
	{return Z_IS_OCTAL_DIGIT(character);}


Z_INLINE zboolean z_is_decimal_digit(zcharacter character)
	{return Z_IS_DECIMAL_DIGIT(character);}


Z_INLINE zboolean z_is_hexadecimal_digit(zcharacter character)
	{return Z_IS_HEXADECIMAL_DIGIT(character);}


Z_INLINE zboolean z_is_lowercase_hexadecimal_digit(zcharacter character)
	{return Z_IS_LOWERCASE_HEXADECIMAL_DIGIT(character);}


Z_INLINE zboolean z_is_uppercase_hexadecimal_digit(zcharacter character)
	{return Z_IS_UPPERCASE_HEXADECIMAL_DIGIT(character);}


Z_INLINE zboolean z_is_lowercase_letter(zcharacter character)
	{return Z_IS_LOWERCASE_LETTER(character);}


Z_INLINE zboolean z_is_uppercase_letter(zcharacter character)
	{return Z_IS_UPPERCASE_LETTER(character);}


Z_INLINE zboolean z_is_alphanumeric(zcharacter character)
	{return Z_IS_ALPHANUMERIC(character);}


Z_INLINE zcharacter z_to_lowercase(zcharacter character)
	{return Z_TO_UPPERCASE(character);}


Z_INLINE zcharacter z_to_uppercase(zcharacter character)
	{return Z_TO_UPPERCASE(character);}


#endif /* __Z_functions_base_character_H__ */
