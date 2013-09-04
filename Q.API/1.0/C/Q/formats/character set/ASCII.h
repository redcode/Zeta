/* Q API - formats/character set/ASCII.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2012 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_formats_character_set_ASCII_H__
#define __Q_formats_character_set_ASCII_H__

#include <Q/types/basics.h>

typedef quint8 QASCII;

/* MARK: - Controls and Basic Latin */

#define Q_ASCII_NULL			        0x00
#define Q_ASCII_START_OF_HEADING	        0x01
#define Q_ASCII_START_OF_TEXT		        0x02
#define Q_ASCII_END_OF_TEXT		        0x03
#define Q_ASCII_END_OF_TRANSMISSION	        0x04
#define Q_ASCII_ENQUIRY			        0x05
#define Q_ASCII_ACKNOWLEDGE		        0x06
#define Q_ASCII_BELL			        0x07
#define Q_ASCII_BACKSPACE		        0x08
#define Q_ASCII_HORIZONTAL_TAB		        0x09
#define Q_ASCII_LINE_FEED		        0x0A
#define Q_ASCII_VERTICAL_TAB		        0x0B
#define Q_ASCII_FORM_FEED		        0x0C
#define Q_ASCII_CARRIAGE_RETURN		        0x0D
#define Q_ASCII_SHIFT_OOUT		        0x0E
#define Q_ASCII_SHIFT_IN		        0x0F
#define Q_ASCII_DATA_LINK_ESCAPE	        0x10
#define Q_ASCII_DEVICE_CONTROL_1	        0x11
#define Q_ASCII_DEVICE_CONTROL_2	        0x12
#define Q_ASCII_DEVICE_CONTROL_3	        0x13
#define Q_ASCII_DEVICE_CONTROL_4	        0x14
#define Q_ASCII_NEGATIVE_ACKNOWLEDGE	        0x15
#define Q_ASCII_SYNCHRONOUS_IDLE	        0x16
#define Q_ASCII_END_OF_TRANSMISSION_BLOCK       0x17
#define Q_ASCII_CANCEL			        0x18
#define Q_ASCII_END_OF_MEDIUM		        0x19
#define Q_ASCII_SUBSTITUTE		        0x1A
#define Q_ASCII_ESCAPE			        0x1B
#define Q_ASCII_FILE_SEPARATOR		        0x1C
#define Q_ASCII_GROUP_SEPARATOR		        0x1D
#define Q_ASCII_RECORD_SEPARATOR	        0x1E
#define Q_ASCII_UNIT_SEPARATOR		        0x1F
#define Q_ASCII_SPACE			        0x20
#define Q_ASCII_EXCLAMATION_MARK	        0x21 /* ! */
#define Q_ASCII_QUOTATION_MARK		        0x22 /* " */
#define Q_ASCII_NUMBER_SIGN_HASH_TAG	        0x23 /* # */
#define Q_ASCII_DOLLAR_SIGN		        0x24 /* $ */
#define Q_ASCII_PERCENT_SIGN		        0x25 /* % */
#define Q_ASCII_AMPERSAND		        0x26 /* & */
#define Q_ASCII_APOSTROPHE		        0x27 /* ' */
#define Q_ASCII_LEFT_PARENTHESIS	        0x28 /* ( */
#define Q_ASCII_RIGHT_PARENTHESIS	        0x29 /* ) */
#define Q_ASCII_ASTERISK		        0x2A /* * */
#define Q_ASCII_PLUS_SIGN		        0x2B /* + */
#define Q_ASCII_COMMA			        0x2C /* , */
#define Q_ASCII_HYPHEN_MINUS		        0x2D /* - */
#define Q_ASCII_FULL_STOP		        0x2E /* . */
#define Q_ASCII_SLASH_SOLIDUS		        0x2F /* / */
#define Q_ASCII_DIGIT_ZERO		        0x30 /* 0 */
#define Q_ASCII_DIGIT_ONE		        0x31 /* 1 */
#define Q_ASCII_DIGIT_TWO		        0x32 /* 2 */
#define Q_ASCII_DIGIT_THREE		        0x33 /* 3 */
#define Q_ASCII_DIGIT_FOUR		        0x34 /* 4 */
#define Q_ASCII_DIGIT_FIVE		        0x35 /* 5 */
#define Q_ASCII_DIGIT_SIX		        0x36 /* 6 */
#define Q_ASCII_DIGIT_SEVEN		        0x37 /* 7 */
#define Q_ASCII_DIGIT_EIGHT		        0x38 /* 8 */
#define Q_ASCII_DIGIT_NINE		        0x39 /* 9 */
#define Q_ASCII_COLON			        0x3A /* : */
#define Q_ASCII_SEMICOLON		        0x3B /* ; */
#define Q_ASCII_LESS_THAN_SIGN		        0x3C /* < */
#define Q_ASCII_EQUAL_SIGN		        0x3D /* = */
#define Q_ASCII_GREATER_THAN_SIGN	        0x3E /* > */
#define Q_ASCII_QUESTION_MARK		        0x3F /* ? */
#define Q_ASCII_AT_SIGN			        0x40 /* @ */
#define Q_ASCII_LATIN_CAPITAL_LETTER_A	        0x41 /* A */
#define Q_ASCII_LATIN_CAPITAL_LETTER_B	        0x42 /* B */
#define Q_ASCII_LATIN_CAPITAL_LETTER_C	        0x43 /* C */
#define Q_ASCII_LATIN_CAPITAL_LETTER_D	        0x44 /* D */
#define Q_ASCII_LATIN_CAPITAL_LETTER_E	        0x45 /* E */
#define Q_ASCII_LATIN_CAPITAL_LETTER_F	        0x46 /* F */
#define Q_ASCII_LATIN_CAPITAL_LETTER_G	        0x47 /* G */
#define Q_ASCII_LATIN_CAPITAL_LETTER_H	        0x48 /* H */
#define Q_ASCII_LATIN_CAPITAL_LETTER_I	        0x49 /* I */
#define Q_ASCII_LATIN_CAPITAL_LETTER_J	        0x4A /* J */
#define Q_ASCII_LATIN_CAPITAL_LETTER_K	        0x4B /* K */
#define Q_ASCII_LATIN_CAPITAL_LETTER_L	        0x4C /* L */
#define Q_ASCII_LATIN_CAPITAL_LETTER_M	        0x4D /* M */
#define Q_ASCII_LATIN_CAPITAL_LETTER_N	        0x4E /* N */
#define Q_ASCII_LATIN_CAPITAL_LETTER_O	        0x4F /* O */
#define Q_ASCII_LATIN_CAPITAL_LETTER_P	        0x50 /* P */
#define Q_ASCII_LATIN_CAPITAL_LETTER_Q	        0x51 /* Q */
#define Q_ASCII_LATIN_CAPITAL_LETTER_R	        0x52 /* R */
#define Q_ASCII_LATIN_CAPITAL_LETTER_S	        0x53 /* S */
#define Q_ASCII_LATIN_CAPITAL_LETTER_T	        0x54 /* T */
#define Q_ASCII_LATIN_CAPITAL_LETTER_U	        0x55 /* U */
#define Q_ASCII_LATIN_CAPITAL_LETTER_V	        0x56 /* V */
#define Q_ASCII_LATIN_CAPITAL_LETTER_W	        0x57 /* W */
#define Q_ASCII_LATIN_CAPITAL_LETTER_X	        0x58 /* X */
#define Q_ASCII_LATIN_CAPITAL_LETTER_Y	        0x59 /* Y */
#define Q_ASCII_LATIN_CAPITAL_LETTER_Z	        0x5A /* Z */
#define Q_ASCII_LEFT_SQUARE_BRACKET	        0x5B /* [ */
#define Q_ASCII_BACKSLASH		        0x5C /* \ */
#define Q_ASCII_RIGHT_SQUARE_BRACKET	        0x5D /* ] */
#define Q_ASCII_CIRCUMFLEX_ACCENT	        0x5E /* ^ */
#define Q_ASCII_LOW_LINE		        0x5F /* _ */
#define Q_ASCII_GRAVE_ACCENT		        0x60 /* ` */
#define Q_ASCII_LATIN_SMALL_LETTER_A	        0x61 /* a */
#define Q_ASCII_LATIN_SMALL_LETTER_B	        0x62 /* b */
#define Q_ASCII_LATIN_SMALL_LETTER_C	        0x63 /* c */
#define Q_ASCII_LATIN_SMALL_LETTER_D	        0x64 /* d */
#define Q_ASCII_LATIN_SMALL_LETTER_E	        0x65 /* e */
#define Q_ASCII_LATIN_SMALL_LETTER_F	        0x66 /* f */
#define Q_ASCII_LATIN_SMALL_LETTER_G	        0x67 /* g */
#define Q_ASCII_LATIN_SMALL_LETTER_H	        0x68 /* h */
#define Q_ASCII_LATIN_SMALL_LETTER_I	        0x69 /* i */
#define Q_ASCII_LATIN_SMALL_LETTER_J	        0x6A /* j */
#define Q_ASCII_LATIN_SMALL_LETTER_K	        0x6B /* k */
#define Q_ASCII_LATIN_SMALL_LETTER_L	        0x6C /* l */
#define Q_ASCII_LATIN_SMALL_LETTER_M	        0x6D /* m */
#define Q_ASCII_LATIN_SMALL_LETTER_N	        0x6E /* n */
#define Q_ASCII_LATIN_SMALL_LETTER_O	        0x6F /* o */
#define Q_ASCII_LATIN_SMALL_LETTER_P	        0x70 /* p */
#define Q_ASCII_LATIN_SMALL_LETTER_Q	        0x71 /* q */
#define Q_ASCII_LATIN_SMALL_LETTER_R	        0x72 /* r */
#define Q_ASCII_LATIN_SMALL_LETTER_S	        0x73 /* s */
#define Q_ASCII_LATIN_SMALL_LETTER_T	        0x74 /* t */
#define Q_ASCII_LATIN_SMALL_LETTER_U	        0x75 /* u */
#define Q_ASCII_LATIN_SMALL_LETTER_V	        0x76 /* v */
#define Q_ASCII_LATIN_SMALL_LETTER_W	        0x77 /* w */
#define Q_ASCII_LATIN_SMALL_LETTER_X	        0x78 /* x */
#define Q_ASCII_LATIN_SMALL_LETTER_Y	        0x79 /* y */
#define Q_ASCII_LATIN_SMALL_LETTER_Z	        0x7A /* z */
#define Q_ASCII_LEFT_CURLY_BRACKET	        0x7B /* { */
#define Q_ASCII_VERTICAL_BAR		        0x7C /* | */
#define Q_ASCII_RIGHT_CURLY_BRACKET	        0x7D /* } */
#define Q_ASCII_TILDE			        0x7E /* ~ */
#define Q_ASCII_DELETE			        0x7F

#endif /* __Q_formats_character_set_ASCII_H__ */
