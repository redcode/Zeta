/* Z Kit - functions/base/character.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_functions_base_character_H_
#define _Z_functions_base_character_H_

#include <Z/types/base.h>
#include <Z/macros/character.h>


#define Z_IMPLEMENTATION_CHARACTER(export, prefix, type)										 \
																	 \
export zboolean prefix##type##_is_alphanumeric		 (z##type character) {return Z_CHARACTER_IS_ALPHANUMERIC	   (character);} \
export zboolean prefix##type##_is_ascii			 (z##type character) {return Z_CHARACTER_IS_ASCII		   (character);} \
export zboolean prefix##type##_is_base_2_digit		 (z##type character) {return Z_CHARACTER_IS_BASE_2_DIGIT	   (character);} \
export zboolean prefix##type##_is_base_8_digit		 (z##type character) {return Z_CHARACTER_IS_BASE_8_DIGIT	   (character);} \
export zboolean prefix##type##_is_base_10_digit		 (z##type character) {return Z_CHARACTER_IS_BASE_10_DIGIT	   (character);} \
export zboolean prefix##type##_is_base_16_digit		 (z##type character) {return Z_CHARACTER_IS_BASE_16_DIGIT	   (character);} \
export zboolean prefix##type##_is_base_16_lowercase_digit(z##type character) {return Z_CHARACTER_IS_BASE_16_LOWERCASE_DIGIT(character);} \
export zboolean prefix##type##_is_base_16_uppercase_digit(z##type character) {return Z_CHARACTER_IS_BASE_16_UPPERCASE_DIGIT(character);} \
export zboolean prefix##type##_is_blank			 (z##type character) {return Z_CHARACTER_IS_BLANK		   (character);} \
export zboolean prefix##type##_is_control		 (z##type character) {return Z_CHARACTER_IS_CONTROL		   (character);} \
export zboolean prefix##type##_is_graphical		 (z##type character) {return Z_CHARACTER_IS_GRAPHICAL		   (character);} \
export zboolean prefix##type##_is_lowercase_letter	 (z##type character) {return Z_CHARACTER_IS_LOWERCASE_LETTER	   (character);} \
export zboolean prefix##type##_is_printable		 (z##type character) {return Z_CHARACTER_IS_PRINTABLE		   (character);} \
export zboolean prefix##type##_is_uppercase_letter	 (z##type character) {return Z_CHARACTER_IS_UPPERCASE_LETTER	   (character);} \
export z##type	prefix##type##_lowercase		 (z##type character) {return Z_CHARACTER_UPPERCASE		   (character);} \
export z##type	prefix##type##_uppercase		 (z##type character) {return Z_CHARACTER_UPPERCASE		   (character);}


Z_IMPLEMENTATION_CHARACTER(static Z_INLINE, z_, char)


#endif /* _Z_functions_base_character_H_ */
