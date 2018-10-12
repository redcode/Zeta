/* Z Kit - hardware/VDC/Ricoh/RP2C0x.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.

	 .----._.----.
 R/W -01-|    \_/    |-40- VCC
  D0 -02-|	     |-39- ALE
  D1 -03-|     _     |-38- AD0
  D2 -04-|    (_)    |-37- AD1
  D3 -05-|	     |-36- AD2
  D4 -06-|	     |-35- AD3
  D5 -07-|	     |-34- AD4
  D6 -08-|	     |-33- AD5
  D7 -09-|	     |-32- AD6
  A2 -10-|	     |-31- AD7
  A1 -11-|   RP2C02  |-30- A8
  A0 -12-|	     |-29- A9
 /CS -13-|	     |-28- A10
EXT0 -14-|	     |-27- A11
EXT1 -15-|	     |-26- A12
EXT2 -16-|     _     |-25- A13
EXT3 -17-|    (_)    |-24- /R
 CLK -18-|	     |-23- /W
/VBL -19-|	     |-22- /SYNC
 VEE -20-|	     |-21- VOUT
	 '-----------'		*/


/* .--------------------------.
   | Default background color |
   |   .--------------------------.
   |   | Sprites with priority 1  |
   |   |   .--------------------------.
   |   |   | Background		      |
   |   |   |   .--------------------------.
   |   |   |   | Sprites with priority 0  |
   '---|   |   |			  |
     | |   |   |			  |
     | '---|   |			  |
     |	 | |   |			  |
     |	 | '---|			  |
     |	 |   | |			  |
     |	 |   | '--------------------------'
     |	 |   |   |
     '---|---|---|---> Stored at 3F00h
	 |   '---|---> The ones with priority = 1
	 |	 '---> The ones with priority = 0
	 '----------->



	| Scanline	| 341	|
	| Frame		| 89342 |










   Sprite Rendering

          .--------.
          | Sprite |
          '--------'
              ||         .------------------.
       .------''-----.   | Control Register |
       |.-----------.|   '------------------'
      _||_         _||_         _||_ 
      \  /         \  /         \  /
       \/           \/           \/
   .---------.  .---------.  .---------.
   | Palette |  | Pattern |  | Pattern |
   |         |  |  index  |  |  table  |
   |---------|  '---------'  '---------'
   |  1 |  0 |      ||           ||
   '---------'      |'-----------'|
      |   |         '------..-----'
      |   |               _||_
      |   |               \  /
      |   |                \/
      |   |            .---------.
      |   |            | Pattern |
      |   |            '---------'
      |   |                ||
      |   |          .-----''-----.
      |   |          |.----------.|
      |   |         _||_        _||_
      |   |         \  /        \  /
      |   |          \/          \/
      |   |      .--------.  .--------.
      |   |      | Tile 0 |  | Tile 1 |
      |   |      '--------'  '--------'
      |   |   .------'           |
      |   |   |   .--------------'
      |   |   |   |
      v   v   v   v
    .---------------.
    | 3 | 2 | 1 | 0 |
    |---------------|
    |  Color Index  |
    |    (4 bit)    |
    '---------------'
      .------------.
      | Name table |
      '------------'
            ||
            |'---------------------.
            |.--------------------.|
           _||_                  _||_
           \  /                  \  /
            \/                    \/
   .-----------------.     .---------------.
   | Attribute table |     | Pattern table |
   '-----------------'     '---------------'
           _||_                  _||_
           \  /                  \  /
            \/                    \/
      .-----------.          .----------.
      | Attribute |          | Pattern  |
      '-----------'          '----------'
          |   |                   ||
          |   |             .-----''-----.
          |   |             |.----------.|
          |   |            _||_        _||_
          |   |            \  /        \  /
          |   |             \/          \/
          |   |         .--------.  .--------.
          |   |         | Tile 0 |  | Tile 1 |
     .----'   |         '--------'  '--------'
     |   .----'             |           |
     |   |   .--------------'           |
     |   |   |   .----------------------'
     |   |   |   |
     v   v   v   v
   .---------------.
   | 3 | 2 | 1 | 0 |
   |---------------|
   |  Color Index  |
   |    (4 bit)    |
   '---------------'












	 <--- 4 bit --->





	1. Draw background
	2. Draw sprites



	.--------------------------------.
	|	    For each		 |
	|     Index from Name Table      |
	|	and its asotiated	 |
	| Attribute from Attribute Table |
	'--------------------------------'
		      _|  |_
		      \    /
		       \  /
		        \/



	    		*/

#ifndef _Z_hardware_VDC_Ricoh_RP2C0x_H_
#define _Z_hardware_VDC_Ricoh_RP2C0x_H_

#include <Z/types/base.h>

typedef struct {
	zuint8 y;
	zuint8 tile_index;
	zuint8 attributes;
	zuint8 x;
} ZRP2C0xSprite;

typedef struct {
	/* Registers */
	zuint8 control;		/* Read / Write  */
	zuint8 mask;		/* Read / Write  */
	zuint8 status;		/* Read		 */
	zuint8 oam_address;	/* Write	 */
	zuint8 oam_data;	/* Read / Write  */
	zuint8 scroll;		/* Write	 */
	zuint8 address;		/* Write	 */
	zuint8 data;		/* Read / Write  */

	/* On-Die Memory */
	ZRP2C0xSprite oam[64];	/* Not accesible */
	zuint8 palettes[28];	/* Not accesible */

} ZRP2C0xState;

#define Z_RP2C0X_STATE_REGISTER_OFFSET_CONTROL		0
#define Z_RP2C0X_STATE_REGISTER_OFFSET_MASK		1
#define Z_RP2C0X_STATE_REGISTER_OFFSET_STATUS		2
#define Z_RP2C0X_STATE_REGISTER_OFFSET_OAM_ADDRESS	3
#define Z_RP2C0X_STATE_REGISTER_OFFSET_OAM_DATA		4
#define Z_RP2C0X_STATE_REGISTER_OFFSET_SCROLL		5
#define Z_RP2C0X_STATE_REGISTER_OFFSET_ADDRESS		6
#define Z_RP2C0X_STATE_REGISTER_OFFSET_DATA		7

#define Z_RP2C0X_STATE_REGISTER_SIZE_CONTROL		1
#define Z_RP2C0X_STATE_REGISTER_SIZE_MASK		1
#define Z_RP2C0X_STATE_REGISTER_SIZE_STATUS		1
#define Z_RP2C0X_STATE_REGISTER_SIZE_OAM_ADDRESS	1
#define Z_RP2C0X_STATE_REGISTER_SIZE_OAM_DATA		1
#define Z_RP2C0X_STATE_REGISTER_SIZE_SCROLL		1
#define Z_RP2C0X_STATE_REGISTER_SIZE_ADDRESS		1
#define Z_RP2C0X_STATE_REGISTER_SIZE_DATA		1

/* Control Register
.-----------------.
| 7 6 5 4 3 2 1 0 |
'-|-|-|-|-|-|-\_/-'
  | | | | | |  '--> name table ---------------------------------------.
  | | | | | '-----> address increment --------------.		      |
  | | | | '-------> sprite patten table ---------.  |		      |
  | | | '---------> background pattern_table --. |  |		      |
  | | '-----------> use 8x16 sprites --------. | |  |		      |
  | '-------------> mode ------------------. | | |  |		      |
  '---------------> emit nmi on vblank --. | | | |  |		      |
					 | | | | |  |		      |
   .-------------------------------------' | | | |  |		      |
   |		    .----------------------' | | |  |		      |
   |   .------------|------------------------' | |  |		      |
   |   |	    |		 .-------------' |  |		      |
   |   |	    |		 |   .-----------'  |		      |
   |   |	    |		 |   |		    |		      |
   |   |	    |		 |   |		    |		      |
   v   v	    v		 v   v		    v		      v
.---------.  .------------.  .-----------.  .---------------.  .------------.
| 0 = NO  |  | 0 = Master |  | 0 = 0000h |  | 0 =  +1 (X++) |  | 00 = 2000h |
| 1 = YES |  | 1 = Slave  |  | 1 = 1000h |  | 1 = +32 (Y++) |  | 01 = 2400h |
'---------'  '------------'  '-----------'  '---------------'  | 10 = 2800h |
							       | 11 = 2C00h |
							       '------------' */

Z_DEFINE_STRICT_STRUCTURE (Z_BIT_FIELD(8, 7) (
	zuint8 emit_nmi_on_vblank	:2,
	zuint8 mode			:1,
	zuint8 use_8x16_sprites		:1,
	zuint8 background_pattern_table :1,
	zuint8 sprite_pattern_table	:1,
	zuint8 address_increment	:1,
	zuint8 name_table		:1
)) RP2C0xControlRegister;


#define Z_RP2C0X_CONTROL_OPTION_NAMETABLE_0			0
#define Z_RP2C0X_CONTROL_OPTION_NAMETABLE_1			1
#define Z_RP2C0X_CONTROL_OPTION_NAMETABLE_2			2
#define Z_RP2C0X_CONTROL_OPTION_NAMETABLE_3			3


#define Z_RP2C0X_CONTROL_GET_NAME_TABLE(v)			(0x2000 | ((((zuint16)(v)) & 3) << 10))
#define Z_RP2C0X_CONTROL_GET_ADDRESS_INCREMENT(v)		(Z_BIT_2(v) ? 32 : 1)
#define Z_RP2C0X_CONTROL_GET_SPRITE_PATTERN_TABLE(v)		Z_BIT_3(v)
#define Z_RP2C0X_CONTROL_GET_BACKGROUND_PATTERN_TABLE(v)	Z_BIT_4(v)
#define Z_RP2C0X_CONTROL_GET_USE_8X16_SPRITES(v)		Z_BIT_5(v)
#define Z_RP2C0X_CONTROL_GET_PPU_MODE(v)			Z_BIT_6(v)
#define Z_RP2C0X_CONTROL_GET_EMIT_NMI_ON_VBLANK(v)		Z_BIT_7(v)

/* Mask Register
.-----------------.
| 7 6 5 4 3 2 1 0 |
'-|-|-|-|-|-|-|-|-'
  | | | | | | | '-> use_grayscale
  | | | | | | '---> disable_background_clipping
  | | | | | '-----> disable_sprite_clipping
  | | | | '-------> enable_background
  | | | '---------> enable_sprites
  | | '-----------> intensify_red
  | '-------------> intensify_green
  '---------------> intensify_blue */

Z_DEFINE_STRICT_STRUCTURE (Z_BIT_FIELD(8, 8) (
	zuint8 intensify_blue		   :1,
	zuint8 intensify_green		   :1,
	zuint8 intensify_red		   :1,
	zuint8 enable_sprites		   :1,
	zuint8 enable_background	   :1,
	zuint8 disable_sprite_clipping	   :1,
	zuint8 disable_background_clipping :1,
	zuint8 use_grayscale		   :1
)) RP2C0xMaskRegister;

#define Z_RP2C0X_MASK_OPTION_USE_GRAYSCALE			  1
#define Z_RP2C0X_MASK_OPTION_DISABLE_BACKGROUND_CLIPPING	  2
#define Z_RP2C0X_MASK_OPTION_DISABLE_SPRITE_CLIPPING		  4
#define Z_RP2C0X_MASK_OPTION_ENABLE_BACKGROUND			  8
#define Z_RP2C0X_MASK_OPTION_ENABLE_SPRITES			 16
#define Z_RP2C0X_MASK_OPTION_INTENSITY_RED			 32
#define Z_RP2C0X_MASK_OPTION_INTENSITY_GREEN			 64
#define Z_RP2C0X_MASK_OPTION_INTENSITY_BLUE			128

#define Z_RP2C0X_MASK_GET_USE_GRAYSCALE(v)			Z_BIT_0(v)
#define Z_RP2C0X_MASK_GET_DISABLE_BACKGROUND_CLIPPING(v)	Z_BIT_1(v)
#define Z_RP2C0X_MASK_GET_DISABLE_SPRITE_CLIPPING(v)		Z_BIT_2(v)
#define Z_RP2C0X_MASK_GET_ENABLE_BACKGROUND(v)			Z_BIT_3(v)
#define Z_RP2C0X_MASK_GET_ENABLE_SPRITES(v)			Z_BIT_4(v)
#define Z_RP2C0X_MASK_GET_INTENSIFY_RED(v)			Z_BIT_5(v)
#define Z_RP2C0X_MASK_GET_INTENSIFY_GREEN(v)			Z_BIT_6(v)
#define Z_RP2C0X_MASK_GET_INTENSIFY_BLUE(v)			Z_BIT_7(v)

/* Status Register
.-----------------.
| 7 6 5 4 3 2 1 0 |
'-|-|-|-\_______/-'
  | | |     '-----> unused
  | | '-----------> sprite_overflow
  | '-------------> sprite_hit
  '---------------> vblank

   Reading resets the 1st/2nd-write flipflop (used by register scroll and 2006h).
Reading resets Bit 7, can be used to acknowledge NMIs, Bit 7 is also automatically reset at the end of VBlank, so manual acknowledge is normally not required (unless one wants to free the NMI signal for external NMI inputs).

*/

Z_DEFINE_STRICT_STRUCTURE (Z_BIT_FIELD(8, 4) (
	zuint8 vblank	       :1,
	zuint8 sprite_hit      :1,
	zuint8 sprite_overflow :1,
	zuint8 unused	       :5
)) RP2C0xStatusRegister;


#define Z_RP2C0X_STATUS_GET_SPRITE_OVERFLOW(v)			Z_BIT_5(v)
#define Z_RP2C0X_STATUS_GET_SPRITE_HIT(v)			Z_BIT_6(v)
#define Z_RP2C0X_STATUS_GET_VBLANK(v)				Z_BIT_7(v)

/* Sprite

Y Coordinate
.-----------------.
| 7 6 5 4 3 2 1 0 |
'-----------------'

Tile Index
.-----------------.
| 7 6 5 4 3 2 1 0 |
'-\___________/-|-'
	|	|
	|	'-> patern_table
	'---------> pattern_index

   Attributes
   .-----------------.
   | 7 6 5 4 3 2 1 0 |
   '-|-|-|-\___/-\_/-'
     | | |   |	  '--> palette ----------------.
     | | |   '-------> Unused		       |
     | | '-----------> priority -----------.   |
     | '-------------> horizontal_flip --. |   |
     '---------------> vertical_flip --. | |   |
				       | | |   |
      .--------------------------------' | |   |
      |   .------------------------------' |   |
      |   |		    .--------------'   |
      |   |		    |		       |
      v   v		    v		       v
   .---------.  .----------------------.  .--------.
   | 0 = NO  |  | 0 = over background  |  | 00 = 4 |
   | 1 = YES |  | 1 = under background |  | 01 = 5 |
   '---------'  '----------------------'  | 10 = 6 |
					  | 11 = 7 |
					  '--------'
   .-------------------------------.
   | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |	X Coordinate
   '-------------------------------' */

#define Z_RP2C0X_SPRITE_GET_X(p)
#define Z_RP2C0X_SPRITE_GET_Y(p)
#define Z_RP2C0X_SPRITE_GET_TILE_BANK(p)
#define Z_RP2C0X_SPRITE_GET_TILE_NUMBER(p)
#define Z_RP2C0X_SPRITE_GET_TILE_BANK(p)
#define Z_RP2C0X_SPRITE_GET_PALETTE(p)
#define Z_RP2C0X_SPRITE_GET_PRIORITY(P)		((p)->attributes & 4)
#define Z_RP2C0X_SPRITE_GET_HORIZONTAL_FLIP(p)	((p)->attributes & 2)
#define Z_RP2C0X_SPRITE_GET_VERTICAL_FLIP(p)	((p)->attributes & 1)

/* Palette
.-----------------.
| 7 6 5 4 3 2 1 0 |
'-\_/-\_/-\_____/-'
   |   |     '----> hue
   |   '----------> value
   '--------------> unused (0 when read) */

/* Color
      .-----------------------------.
      | Blue %  | Green % | Red %   |
.-----+---------+---------+---------|
| 001 |    74.3 |    91.5 |   123.9 |
| 010 |    88.2 |   108.6 |    79.4 |
| 011 |    65.3 |    98   |   101.9 |
| 100 |   127.7 |   102.6 |    90.5 |
| 101 |    97.9 |    90.8 |   102.3 |
| 110 |   100.1 |    98.7 |    74.1 |
| 111 |    75   |    75   |    75   |
'-----------------------------------' */

/* External Memory Structure
.------------------------------------------------.
| Address     | Size  | Content			 |
|-------------+-------+--------------------------|
| 0000 - 0FFF |  4096 | Pattern table #0	 |
| 1000 - 1FFF |  4096 | Pattern table #1	 |
|-------------+-------+--------------------------|
| 2000 - 23BF |   960 | Name table #0		 |
| 23C0 - 23FF |    64 | Attribute table #0	 |
| 2400 - 27BF |   960 | Name table #1		 |
| 27C0 - 27FF |    64 | Attribute table #1	 |
| 2800 - 2BBF |   960 | Name table #2		 |
| 2BC0 - 2BFF |    64 | Attribute table #2	 |
| 2C00 - 2FBF |   960 | Name table #3		 |
| 2FC0 - 2FFF |    64 | Attribute table #3	 |
|-------------+-------+--------------------------|
| 3000 - 3EFF |  3839 | Name Table Mirror *1	 |
|-------------+-------+--------------------------|
| 3F00	      |     1 | Default background color |
| 3F01 - 3F03 |     2 | Background palette #0	 |
| 3F04	      |     1 | Unused			 |
| 3F05 - 3F07 |     2 | Background palette #1	 |
| 3F08	      |     1 | Unused			 |
| 3F09 - 3F0B |     2 | Background palette #2	 |
| 3F0C	      |     1 | Unused			 |
| 3F0D - 3F0F |     2 | Background palette #3	 |
|-------------+-------+--------------------------|
| 3F10	      |     1 | Mirror of 3F00h		 |
| 3F11 - 3F13 |     2 | Sprite palette #0	 |
| 3F14	      |     1 | Mirror of 3F04h		 |
| 3F15 - 3F17 |     2 | Sprite palette #1	 |
| 3F18	      |     1 | Mirror of 3F08h		 |
| 3F19 - 3F1B |     2 | Sprite palette #2	 |
| 3F1C	      |     1 | Mirror of 3F0Ch		 |
| 3F1D - 3F1F |     2 | Sprite palette #3	 |
|-------------+-------+--------------------------|
| 3F00 - 3FFF |    20 | Palette *2		 |
| 4000 - FFFF | 49152 | Mirrors of Above *3	 |
'------------------------------------------------'

	Pattern Table:
	

	Tile table:		256 tiles
	Attribute table:	


	Name table:
	Used to select tiles for the background. Each element is a tile index.

	Attribute table:
   

*/




typedef struct {
	zuint indexes[32 * 30];
	zuint attributes[];
} ZRP2C0xNameTable;


#define Z_RP2C0X_ADDRESS_PATTERN_TABLE_0		0x0000
#define Z_RP2C0X_ADDRESS_PATTERN_TABLE_1		0x1000
#define Z_RP2C0X_ADDRESS_NAME_TABLE_0			0x2000
#define Z_RP2C0X_ADDRESS_NAME_TABLE_1			0x2400
#define Z_RP2C0X_ADDRESS_NAME_TABLE_2			0x2800
#define Z_RP2C0X_ADDRESS_NAME_TABLE_3			0x2C00
#define Z_RP2C0X_ADDRESS_ATTRIBUTE_TABLE_0		0x23C0
#define Z_RP2C0X_ADDRESS_ATTRIBUTE_TABLE_1		0x27C0
#define Z_RP2C0X_ADDRESS_ATTRIBUTE_TABLE_2		0x2BC0
#define Z_RP2C0X_ADDRESS_ATTRIBUTE_TABLE_3		0x2FC0

#define Z_RP2C0X_ADDRESS_DEFAULT_BACKGROUND_COLOR	0x3F00
#define Z_RP2C0X_ADDRESS_BACKGROUND_PALETTE_0		0x3F01
#define Z_RP2C0X_ADDRESS_BACKGROUND_PALETTE_1		0x3F05
#define Z_RP2C0X_ADDRESS_BACKGROUND_PALETTE_2		0x3F09
#define Z_RP2C0X_ADDRESS_BACKGROUND_PALETTE_3		0x3F0D
#define Z_RP2C0X_ADDRESS_SPRITE_PALETTE_0		0x3F11
#define Z_RP2C0X_ADDRESS_SPRITE_PALETTE_1		0x3F15
#define Z_RP2C0X_ADDRESS_SPRITE_PALETTE_2		0x3F19
#define Z_RP2C0X_ADDRESS_SPRITE_PALETTE_3		0x3F1D

#define Z_RP2C0X_TILE_SIZE		8
#define Z_RP2C0X_PATTERN_SIZE		Z_RP2C0X_TILE_SIZE * 2
#define Z_RP2C0X_PATTERN_TABLE_SIZE	Z_RP2C0X_PATTERN_SIZE * 256
#define Z_RP2C0X_NAME_TABLE_SIZE	Z_UINT8_SIZE * 32 * 30



/* Tile 8x8
	     <--------------- 8 bit -------------->
	    .---------------------------------------.
	  A |  0 |  1 |  2 |  3 |  4 |  5 |  6 |  7 |
	  | |----+----+----+----+----+----+----+----|
	  | |  8 |  9 | 10 | 11 | 12 | 13 | 14 | 15 |
	  | |----+----+----+----+----+----+----+----|
	  | | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 |
	  | |----+----+----+----+----+----+----+----|
	  | | 24 | 25 | 26 | 27 | 28 | 29 | 30 | 31 |
   8 byte | |----+----+----+----+----+----+----+----|
	  | | 32 | 33 | 34 | 35 | 36 | 37 | 38 | 39 |
	  | |----+----+----+----+----+----+----+----|
	  | | 40 | 41 | 42 | 43 | 44 | 45 | 46 | 47 |
	  | |----+----+----+----+----+----+----+----|
	  | | 48 | 49 | 50 | 51 | 52 | 53 | 54 | 55 |
	  | |----+----+----+----+----+----+----+----|
	  V | 56 | 57 | 58 | 59 | 60 | 61 | 62 | 63 |
	    '---------------------------------------'	*/





/*








	<----------------- 512 ----------------->

	(0,0)	    (255,0)  (256,0)	  (511,0)
	  +-------------+	+-------------+
	  |2000	    20FF|	|2000     20FF|
	  |		|	|	      |
	  |		|	|	      |
	  |		|	|	      |
	  |2300	    23FF|	|2300	  23FF|
	  +-------------+	+-------------+
	(0,240)	    (255,255) (0,240)	    (255,255)5)



			*/




#define Z_RP2C0X_ADDRESS_TILE_SET_0
#define Z_RP2C0X_ADDRESS_TILE_SET_1






typedef struct {
	zuint8 tile_0[8];
	zuint8 tile_1[8];
} ZRP2C0xPattern;

typedef struct {
} ZRP2C0xPatternTable;

/*
typedef struct {
} ZRP2C0xNameTable;*/


#define Z_RP2C0X_TILE_GET_PIXEL(tile, index) \
	(tile[(index) / 8] >> (7 - ((index) % 8)) & 1)

#define Z_RP2C0X_PATTERN_GET_PIXEL(pattern, index)		\
	Z_RP2C0X_TILE_GET_PIXEL(pattern->plane_a, index) |	\
	(Z_RP2C0X_TILE_GET_PIXEL(pattern->plane_b, index) << 1)












/*
typedef struct {
	
} ZRP2C0xNameTable;*/










#define Z_RP2C0X_MASK_GET_GRAYSCALE_MODE



#endif /* _Z_hardware_VDC_Ricoh_RP2C0x_H_ */
