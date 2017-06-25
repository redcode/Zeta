/* Z Kit C API - functions/base/character.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2017 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_functions_base_character_H__
#define __Z_functions_base_character_H__

#include <Z/types/base.h>
#include <Z/macros/character.h>


#define Z_IMPLEMENTATION_CHARACTER(export, prefix)										     \
																     \
export zboolean prefix##is_alphanumeric		  (zcharacter character) {return Z_CHARACTER_IS_ALPHANUMERIC	       (character);} \
export zboolean prefix##is_ascii		  (zcharacter character) {return Z_CHARACTER_IS_ASCII		       (character);} \
export zboolean prefix##is_base_2_digit		  (zcharacter character) {return Z_CHARACTER_IS_BASE_2_DIGIT	       (character);} \
export zboolean prefix##is_base_8_digit		  (zcharacter character) {return Z_CHARACTER_IS_BASE_8_DIGIT	       (character);} \
export zboolean prefix##is_base_10_digit	  (zcharacter character) {return Z_CHARACTER_IS_BASE_10_DIGIT	       (character);} \
export zboolean prefix##is_base_16_digit	  (zcharacter character) {return Z_CHARACTER_IS_BASE_16_DIGIT	       (character);} \
export zboolean prefix##is_base_16_lowercase_digit(zcharacter character) {return Z_CHARACTER_IS_BASE_16_LOWERCASE_DIGIT(character);} \
export zboolean prefix##is_base_16_uppercase_digit(zcharacter character) {return Z_CHARACTER_IS_BASE_16_UPPERCASE_DIGIT(character);} \
export zboolean prefix##is_blank		  (zcharacter character) {return Z_CHARACTER_IS_BLANK		       (character);} \
export zboolean prefix##is_control		  (zcharacter character) {return Z_CHARACTER_IS_CONTROL		       (character);} \
export zboolean prefix##is_graphical		  (zcharacter character) {return Z_CHARACTER_IS_GRAPHICAL	       (character);} \
export zboolean prefix##is_lowercase_letter	  (zcharacter character) {return Z_CHARACTER_IS_LOWERCASE_LETTER       (character);} \
export zboolean prefix##is_printable		  (zcharacter character) {return Z_CHARACTER_IS_PRINTABLE	       (character);} \
export zboolean prefix##is_uppercase_letter	  (zcharacter character) {return Z_CHARACTER_IS_UPPERCASE_LETTER       (character);} \
																     \
export zcharacter prefix##lowercase(zcharacter character) {return Z_CHARACTER_UPPERCASE(character);}				     \
export zcharacter prefix##uppercase(zcharacter character) {return Z_CHARACTER_UPPERCASE(character);}


Z_IMPLEMENTATION_CHARACTER(Z_INLINE, z_character_)


#endif /* __Z_functions_base_character_H__ */
