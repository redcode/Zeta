/* Zeta API - Z/functions/character.h
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_functions_character_H
#define Z_functions_character_H

#include <Z/types/integral.h>
#include <Z/macros/character.h>
#include <Z/macros/language.h>


static Z_INLINE zboolean z_char_is_alphanumeric(zchar value)
	{return Z_CHAR_IS_ALPHANUMERIC(value);}


static Z_INLINE zboolean z_char_is_ascii(zchar value)
	{return Z_CHAR_IS_ASCII(value);}


static Z_INLINE zboolean z_char_is_base_2_digit(zchar value)
	{return Z_CHAR_IS_BASE_2_DIGIT(value);}


static Z_INLINE zboolean z_char_is_base_8_digit(zchar value)
	{return Z_CHAR_IS_BASE_8_DIGIT(value);}


static Z_INLINE zboolean z_char_is_base_10_digit(zchar value)
	{return Z_CHAR_IS_BASE_10_DIGIT(value);}


static Z_INLINE zboolean z_char_is_base_16_digit(zchar value)
	{return Z_CHAR_IS_BASE_16_DIGIT(value);}


static Z_INLINE zboolean z_char_is_base_16_lowercase_digit(zchar value)
	{return Z_CHAR_IS_BASE_16_LOWERCASE_DIGIT(value);}


static Z_INLINE zboolean z_char_is_base_16_uppercase_digit(zchar value)
	{return Z_CHAR_IS_BASE_16_UPPERCASE_DIGIT(value);}


static Z_INLINE zboolean z_char_is_blank(zchar value)
	{return Z_CHAR_IS_BLANK(value);}


static Z_INLINE zboolean z_char_is_control(zchar value)
	{return Z_CHAR_IS_CONTROL(value);}


static Z_INLINE zboolean z_char_is_graphical(zchar value)
	{return Z_CHAR_IS_GRAPHICAL(value);}


static Z_INLINE zboolean z_char_is_letter(zchar value)
	{return Z_CHAR_IS_LETTER(value);}


static Z_INLINE zboolean z_char_is_lowercase_letter(zchar value)
	{return Z_CHAR_IS_LOWERCASE_LETTER(value);}


static Z_INLINE zboolean z_char_is_printable(zchar value)
	{return Z_CHAR_IS_PRINTABLE(value);}


static Z_INLINE zboolean z_char_is_uppercase_letter(zchar value)
	{return Z_CHAR_IS_UPPERCASE_LETTER(value);}


static Z_INLINE zchar z_char_lowercase(zchar value)
	{return Z_CHAR_LOWERCASE(value);}


static Z_INLINE zchar z_char_uppercase(zchar value)
	{return Z_CHAR_UPPERCASE(value);}


#endif /* Z_functions_character_H */
