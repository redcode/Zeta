/* Zeta API - Z/formats/keymap/Z.h
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_formats_keymap_Z_H
#define Z_formats_keymap_Z_H

#define Z_KEY_CODE_UP				   0
#define Z_KEY_CODE_RIGHT			   1
#define Z_KEY_CODE_DOWN				   2
#define Z_KEY_CODE_LEFT				   3
#define Z_KEY_CODE_HOME				   4
#define Z_KEY_CODE_END				   5
#define Z_KEY_CODE_PAGE_UP			   6
#define Z_KEY_CODE_PAGE_DOWN			   7
#define Z_KEY_CODE_BACKSPACE			   8 /* Like ASCII */
#define Z_KEY_CODE_TAB				   9 /* Like ASCII */
#define Z_KEY_CODE_RETURN			  10 /* Like ASCII */
#define Z_KEY_CODE_F1				  11
#define Z_KEY_CODE_F2				  12
#define Z_KEY_CODE_F3				  13
#define Z_KEY_CODE_F4				  14
#define Z_KEY_CODE_F5				  15
#define Z_KEY_CODE_F6				  16
#define Z_KEY_CODE_F7				  17
#define Z_KEY_CODE_F8				  18
#define Z_KEY_CODE_F9				  19
#define Z_KEY_CODE_F10				  20
#define Z_KEY_CODE_F11				  21
#define Z_KEY_CODE_F12				  22
#define Z_KEY_CODE_PRINT_SCREEN			  23
#define Z_KEY_CODE_SCROLL_LOCK			  24
#define Z_KEY_CODE_PAUSE			  25
#define Z_KEY_CODE_CAPS_LOCK			  26
#define Z_KEY_CODE_ESCAPE			  27 /* Like ASCII */
#define Z_KEY_CODE_LEFT_SHIFT			  28
#define Z_KEY_CODE_LEFT_CONTROL			  29
#define Z_KEY_CODE_LEFT_COMMAND			  30
#define Z_KEY_CODE_LEFT_OPTION			  31
#define Z_KEY_CODE_SPACE			  32 /* Like ASCII */
#define Z_KEY_CODE_RIGHT_OPTION			  33
#define Z_KEY_CODE_RIGHT_COMMAND		  34
#define Z_KEY_CODE_APPLICATION			  35
#define Z_KEY_CODE_RIGHT_CONTROL		  36
#define Z_KEY_CODE_RIGHT_SHIFT			  37
#define Z_KEY_CODE_INSERT			  38
#define Z_KEY_CODE_ANSI_APOSTROPHE		  39 /* Like ASCII */
#define Z_KEY_CODE_ANSI_KEYPAD_SOLIDUS		  40
#define Z_KEY_CODE_ANSI_KEYPAD_HYPHEN_MINUS	  41
#define Z_KEY_CODE_ANSI_KEYPAD_ASTERISK		  42 /* Like ASCII */
#define Z_KEY_CODE_ANSI_KEYPAD_PLUS_SIGN	  43 /* Like ASCII */
#define Z_KEY_CODE_ANSI_COMMA			  44 /* Like ASCII */
#define Z_KEY_CODE_ANSI_HYPHEN_MINUS		  45 /* Like ASCII */
#define Z_KEY_CODE_ANSI_FULL_STOP		  46 /* Like ASCII */
#define Z_KEY_CODE_ANSI_SOLIDUS			  47 /* Like ASCII */
#define Z_KEY_CODE_ANSI_0			  48 /* Like ASCII */
#define Z_KEY_CODE_ANSI_1			  49 /* Like ASCII */
#define Z_KEY_CODE_ANSI_2			  50 /* Like ASCII */
#define Z_KEY_CODE_ANSI_3			  51 /* Like ASCII */
#define Z_KEY_CODE_ANSI_4			  52 /* Like ASCII */
#define Z_KEY_CODE_ANSI_5			  53 /* Like ASCII */
#define Z_KEY_CODE_ANSI_6			  54 /* Like ASCII */
#define Z_KEY_CODE_ANSI_7			  55 /* Like ASCII */
#define Z_KEY_CODE_ANSI_8			  56 /* Like ASCII */
#define Z_KEY_CODE_ANSI_9			  57 /* Like ASCII */
#define Z_KEY_CODE_ANSI_KEYPAD_ENTER		  58
#define Z_KEY_CODE_ANSI_SEMICOLON		  59 /* Like ASCII */
#define Z_KEY_CODE_ANSI_KEYPAD_DECIMAL_SEPARATOR  60
#define Z_KEY_CODE_ANSI_EQUALS_SIGN		  61 /* Like ASCII */
#define Z_KEY_CODE_ANSI_KEYPAD_NUM_LOCK		  62
#define Z_KEY_CODE_ANSI_KEYPAD_0		  63
#define Z_KEY_CODE_ANSI_KEYPAD_1		  64
#define Z_KEY_CODE_ANSI_A			  65 /* Like ASCII */
#define Z_KEY_CODE_ANSI_B			  66 /* Like ASCII */
#define Z_KEY_CODE_ANSI_C			  67 /* Like ASCII */
#define Z_KEY_CODE_ANSI_D			  68 /* Like ASCII */
#define Z_KEY_CODE_ANSI_E			  69 /* Like ASCII */
#define Z_KEY_CODE_ANSI_F			  70 /* Like ASCII */
#define Z_KEY_CODE_ANSI_G			  71 /* Like ASCII */
#define Z_KEY_CODE_ANSI_H			  72 /* Like ASCII */
#define Z_KEY_CODE_ANSI_I			  73 /* Like ASCII */
#define Z_KEY_CODE_ANSI_J			  74 /* Like ASCII */
#define Z_KEY_CODE_ANSI_K			  75 /* Like ASCII */
#define Z_KEY_CODE_ANSI_L			  76 /* Like ASCII */
#define Z_KEY_CODE_ANSI_M			  77 /* Like ASCII */
#define Z_KEY_CODE_ANSI_N			  78 /* Like ASCII */
#define Z_KEY_CODE_ANSI_O			  79 /* Like ASCII */
#define Z_KEY_CODE_ANSI_P			  80 /* Like ASCII */
#define Z_KEY_CODE_ANSI_Q			  81 /* Like ASCII */
#define Z_KEY_CODE_ANSI_R			  82 /* Like ASCII */
#define Z_KEY_CODE_ANSI_S			  83 /* Like ASCII */
#define Z_KEY_CODE_ANSI_T			  84 /* Like ASCII */
#define Z_KEY_CODE_ANSI_U			  85 /* Like ASCII */
#define Z_KEY_CODE_ANSI_V			  86 /* Like ASCII */
#define Z_KEY_CODE_ANSI_W			  87 /* Like ASCII */
#define Z_KEY_CODE_ANSI_X			  88 /* Like ASCII */
#define Z_KEY_CODE_ANSI_Y			  89 /* Like ASCII */
#define Z_KEY_CODE_ANSI_Z			  90 /* Like ASCII */
#define Z_KEY_CODE_ANSI_LEFT_SQUARE_BRACKET	  91 /* Like ASCII */
#define Z_KEY_CODE_ANSI_REVERSE_SOLIDUS		  92 /* Like ASCII */
#define Z_KEY_CODE_ANSI_RIGHT_SQUARE_BRACKET	  93 /* Like ASCII */
#define Z_KEY_CODE_ANSI_KEYPAD_2		  94
#define Z_KEY_CODE_ANSI_KEYPAD_3		  95
#define Z_KEY_CODE_ANSI_GRAVE_ACCENT		  96 /* Like ASCII */
#define Z_KEY_CODE_ANSI_KEYPAD_4		  97
#define Z_KEY_CODE_ANSI_KEYPAD_5		  98
#define Z_KEY_CODE_ANSI_KEYPAD_6		  99
#define Z_KEY_CODE_ANSI_KEYPAD_7		 100
#define Z_KEY_CODE_ANSI_KEYPAD_8		 101
#define Z_KEY_CODE_ANSI_KEYPAD_9		 102
#define Z_KEY_CODE_APPLE_ANSI_KEYPAD_EQUALS_SIGN 103 /* Apple keyboards */
#define Z_KEY_CODE_F13				 104
#define Z_KEY_CODE_F14				 105
#define Z_KEY_CODE_F15				 106
#define Z_KEY_CODE_F16				 107
#define Z_KEY_CODE_F17				 108
#define Z_KEY_CODE_F18				 109
#define Z_KEY_CODE_F19				 110
#define Z_KEY_CODE_F20				 111
#define Z_KEY_CODE_F21				 112
#define Z_KEY_CODE_F22				 113
#define Z_KEY_CODE_F23				 114
#define Z_KEY_CODE_F24				 115
#define Z_KEY_CODE_JIS_EISU			 116 /* Japanese keyboards */
#define Z_KEY_CODE_JIS_KANA			 117 /* Japanese keyboards */
#define Z_KEY_CODE_JIS_LOW_LINE			 118 /* Japanese keyboards */
#define Z_KEY_CODE_JIS_YEN_SIGN			 119 /* Japanese keyboards */
#define Z_KEY_CODE_JIS_KEYPAD_COMMA		 120 /* Japanese keyboards */
#define Z_KEY_CODE_ISO_SECTION			 121 /* ISO keyboards */
#define Z_KEY_CODE_VOLUME_UP			 122
#define Z_KEY_CODE_VOLUME_DOWN			 123
#define Z_KEY_CODE_MUTE				 124
#define Z_KEY_CODE_UNUSED_0			 125
#define Z_KEY_CODE_FUNCTION			 126
#define Z_KEY_CODE_DELETE			 127 /* Similar to ASCII */
#define Z_KEY_CODE_INVALID			 Z_KEY_CODE_UNUSED_0

#endif /* Z_formats_keymap_Z_H */
