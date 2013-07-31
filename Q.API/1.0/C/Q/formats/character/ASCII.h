/* Q API - formats/character/ASCII.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2012 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_formats_character_ASCII_H__
#define __Q_formats_character_ASCII_H__

#include <Q/types/basics.h>

typedef quint8 QASCII;

#pragma mark - Controls and Basic Latin

#define Q_ASCII_NULL			        0x0000
#define Q_ASCII_START_OF_HEADING	        0x0001
#define Q_ASCII_START_OF_TEXT		        0x0002
#define Q_ASCII_END_OF_TEXT		        0x0003
#define Q_ASCII_END_OF_TRANSMISSION	        0x0004
#define Q_ASCII_ENQUIRY			        0x0005
#define Q_ASCII_ACKNOWLEDGE		        0x0006
#define Q_ASCII_BELL			        0x0007
#define Q_ASCII_BACKSPACE		        0x0008
#define Q_ASCII_HORIZONTAL_TAB		        0x0009
#define Q_ASCII_LINE_FEED		        0x000A
#define Q_ASCII_VERTICAL_TAB		        0x000B
#define Q_ASCII_FORM_FEED		        0x000C
#define Q_ASCII_CARRIAGE_RETURN		        0x000D
#define Q_ASCII_SHIFT_OOUT		        0x000E
#define Q_ASCII_SHIFT_IN		        0x000F
#define Q_ASCII_DATA_LINK_ESCAPE	        0x0010
#define Q_ASCII_DEVICE_CONTROL_1	        0x0011
#define Q_ASCII_DEVICE_CONTROL_2	        0x0012
#define Q_ASCII_DEVICE_CONTROL_3	        0x0013
#define Q_ASCII_DEVICE_CONTROL_4	        0x0014
#define Q_ASCII_NEGATIVE_ACKNOWLEDGE	        0x0015
#define Q_ASCII_SYNCHRONOUS_IDLE	        0x0016
#define Q_ASCII_END_OF_TRANSMISSION_BLOCK       0x0017
#define Q_ASCII_CANCEL			        0x0018
#define Q_ASCII_END_OF_MEDIUM		        0x0019
#define Q_ASCII_SUBSTITUTE		        0x001A
#define Q_ASCII_ESCAPE			        0x001B
#define Q_ASCII_FILE_SEPARATOR		        0x001C
#define Q_ASCII_GROUP_SEPARATOR		        0x001D
#define Q_ASCII_RECORD_SEPARATOR	        0x001E
#define Q_ASCII_UNIT_SEPARATOR		        0x001F
#define Q_ASCII_SPACE			        0x0020
#define Q_ASCII_EXCLAMATION_MARK	        0x0021 /* ! */
#define Q_ASCII_QUOTATION_MARK		        0x0022 /* " */
#define Q_ASCII_NUMBER_SIGN_HASH_TAG	        0x0023 /* # */
#define Q_ASCII_DOLLAR_SIGN		        0x0024 /* $ */
#define Q_ASCII_PERCENT_SIGN		        0x0025 /* % */
#define Q_ASCII_AMPERSAND		        0x0026 /* & */
#define Q_ASCII_APOSTROPHE		        0x0027 /* ' */
#define Q_ASCII_LEFT_PARENTHESIS	        0x0028 /* ( */
#define Q_ASCII_RIGHT_PARENTHESIS	        0x0029 /* ) */
#define Q_ASCII_ASTERISK		        0x002A /* * */
#define Q_ASCII_PLUS_SIGN		        0x002B /* + */
#define Q_ASCII_COMMA			        0x002C /* , */
#define Q_ASCII_HYPHEN_MINUS		        0x002D /* - */
#define Q_ASCII_FULL_STOP		        0x002E /* . */
#define Q_ASCII_SLASH_SOLIDUS		        0x002F /* / */
#define Q_ASCII_DIGIT_ZERO		        0x0030 /* 0 */
#define Q_ASCII_DIGIT_ONE		        0x0031 /* 1 */
#define Q_ASCII_DIGIT_TWO		        0x0032 /* 2 */
#define Q_ASCII_DIGIT_THREE		        0x0033 /* 3 */
#define Q_ASCII_DIGIT_FOUR		        0x0034 /* 4 */
#define Q_ASCII_DIGIT_FIVE		        0x0035 /* 5 */
#define Q_ASCII_DIGIT_SIX		        0x0036 /* 6 */
#define Q_ASCII_DIGIT_SEVEN		        0x0037 /* 7 */
#define Q_ASCII_DIGIT_EIGHT		        0x0038 /* 8 */
#define Q_ASCII_DIGIT_NINE		        0x0039 /* 9 */
#define Q_ASCII_COLON			        0x003A /* : */
#define Q_ASCII_SEMICOLON		        0x003B /* ; */
#define Q_ASCII_LESS_THAN_SIGN		        0x003C /* < */
#define Q_ASCII_EQUAL_SIGN		        0x003D /* = */
#define Q_ASCII_GREATER_THAN_SIGN	        0x003E /* > */
#define Q_ASCII_QUESTION_MARK		        0x003F /* ? */
#define Q_ASCII_AT_SIGN			        0x0040 /* @ */
#define Q_ASCII_LATIN_CAPITAL_LETTER_A	        0x0041 /* A */
#define Q_ASCII_LATIN_CAPITAL_LETTER_B	        0x0042 /* B */
#define Q_ASCII_LATIN_CAPITAL_LETTER_C	        0x0043 /* C */
#define Q_ASCII_LATIN_CAPITAL_LETTER_D	        0x0044 /* D */
#define Q_ASCII_LATIN_CAPITAL_LETTER_E	        0x0045 /* E */
#define Q_ASCII_LATIN_CAPITAL_LETTER_F	        0x0046 /* F */
#define Q_ASCII_LATIN_CAPITAL_LETTER_G	        0x0047 /* G */
#define Q_ASCII_LATIN_CAPITAL_LETTER_H	        0x0048 /* H */
#define Q_ASCII_LATIN_CAPITAL_LETTER_I	        0x0049 /* I */
#define Q_ASCII_LATIN_CAPITAL_LETTER_J	        0x004A /* J */
#define Q_ASCII_LATIN_CAPITAL_LETTER_K	        0x004B /* K */
#define Q_ASCII_LATIN_CAPITAL_LETTER_L	        0x004C /* L */
#define Q_ASCII_LATIN_CAPITAL_LETTER_M	        0x004D /* M */
#define Q_ASCII_LATIN_CAPITAL_LETTER_N	        0x004E /* N */
#define Q_ASCII_LATIN_CAPITAL_LETTER_O	        0x004F /* O */
#define Q_ASCII_LATIN_CAPITAL_LETTER_P	        0x0050 /* P */
#define Q_ASCII_LATIN_CAPITAL_LETTER_Q	        0x0051 /* Q */
#define Q_ASCII_LATIN_CAPITAL_LETTER_R	        0x0052 /* R */
#define Q_ASCII_LATIN_CAPITAL_LETTER_S	        0x0053 /* S */
#define Q_ASCII_LATIN_CAPITAL_LETTER_T	        0x0054 /* T */
#define Q_ASCII_LATIN_CAPITAL_LETTER_U	        0x0055 /* U */
#define Q_ASCII_LATIN_CAPITAL_LETTER_V	        0x0056 /* V */
#define Q_ASCII_LATIN_CAPITAL_LETTER_W	        0x0057 /* W */
#define Q_ASCII_LATIN_CAPITAL_LETTER_X	        0x0058 /* X */
#define Q_ASCII_LATIN_CAPITAL_LETTER_Y	        0x0059 /* Y */
#define Q_ASCII_LATIN_CAPITAL_LETTER_Z	        0x005A /* Z */
#define Q_ASCII_LEFT_SQUARE_BRACKET	        0x005B /* [ */
#define Q_ASCII_BACKSLASH		        0x005C /* \ */
#define Q_ASCII_RIGHT_SQUARE_BRACKET	        0x005D /* ] */
#define Q_ASCII_CIRCUMFLEX_ACCENT	        0x005E /* ^ */
#define Q_ASCII_LOW_LINE		        0x005F /* _ */
#define Q_ASCII_GRAVE_ACCENT		        0x0060 /* ` */
#define Q_ASCII_LATIN_SMALL_LETTER_A	        0x0061 /* a */
#define Q_ASCII_LATIN_SMALL_LETTER_B	        0x0062 /* b */
#define Q_ASCII_LATIN_SMALL_LETTER_C	        0x0063 /* c */
#define Q_ASCII_LATIN_SMALL_LETTER_D	        0x0064 /* d */
#define Q_ASCII_LATIN_SMALL_LETTER_E	        0x0065 /* e */
#define Q_ASCII_LATIN_SMALL_LETTER_F	        0x0066 /* f */
#define Q_ASCII_LATIN_SMALL_LETTER_G	        0x0067 /* g */
#define Q_ASCII_LATIN_SMALL_LETTER_H	        0x0068 /* h */
#define Q_ASCII_LATIN_SMALL_LETTER_I	        0x0069 /* i */
#define Q_ASCII_LATIN_SMALL_LETTER_J	        0x006A /* j */
#define Q_ASCII_LATIN_SMALL_LETTER_K	        0x006B /* k */
#define Q_ASCII_LATIN_SMALL_LETTER_L	        0x006C /* l */
#define Q_ASCII_LATIN_SMALL_LETTER_M	        0x006D /* m */
#define Q_ASCII_LATIN_SMALL_LETTER_N	        0x006E /* n */
#define Q_ASCII_LATIN_SMALL_LETTER_O	        0x006F /* o */
#define Q_ASCII_LATIN_SMALL_LETTER_P	        0x0070 /* p */
#define Q_ASCII_LATIN_SMALL_LETTER_Q	        0x0071 /* q */
#define Q_ASCII_LATIN_SMALL_LETTER_R	        0x0072 /* r */
#define Q_ASCII_LATIN_SMALL_LETTER_S	        0x0073 /* s */
#define Q_ASCII_LATIN_SMALL_LETTER_T	        0x0074 /* t */
#define Q_ASCII_LATIN_SMALL_LETTER_U	        0x0075 /* u */
#define Q_ASCII_LATIN_SMALL_LETTER_V	        0x0076 /* v */
#define Q_ASCII_LATIN_SMALL_LETTER_W	        0x0077 /* w */
#define Q_ASCII_LATIN_SMALL_LETTER_X	        0x0078 /* x */
#define Q_ASCII_LATIN_SMALL_LETTER_Y	        0x0079 /* y */
#define Q_ASCII_LATIN_SMALL_LETTER_Z	        0x007A /* z */
#define Q_ASCII_LEFT_CURLY_BRACKET	        0x007B /* { */
#define Q_ASCII_VERTICAL_BAR		        0x007C /* | */
#define Q_ASCII_RIGHT_CURLY_BRACKET	        0x007D /* } */
#define Q_ASCII_TILDE			        0x007E /* ~ */
#define Q_ASCII_DELETE			        0x007F

#endif /* __Q_formats_character_ASCII_H__ */
