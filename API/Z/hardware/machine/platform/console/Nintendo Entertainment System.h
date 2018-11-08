/* Z Kit - hardware/machine/platform/console/Nintendo Entertainment System.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.

.-------------------------------------------.
|   Vendor: Nintendo			    |
| Released: 1983-07-15 (JP)		    |
|	    1985-10-18 (KR - North America) |
|	    1986-09-01 (Europe)		    |
|	    1986       (CA)		    |
|	    1987       (Australasia)	    |
'-------------------------------------------'


Front view
 ___ __________________________________ ______ ______
|   |				       |______|	     |
|   | Nintendo®			       |      |	     |
|   | ENTERTAINMENT SYSTEM™	       |      |	     |
|   |__________________________________|______|	     |
|______________________________________|______|______|
|   |	 _____	 _____	|	       | 1  2 |	     |
 \  | o [POWER] [RESET] |	       ||\ |\ |	    /
  \ |___________________|	       ||_||_||	   /
   \___________________________________|______|___/


Back view
 ______ ______ ______________________________________
|      |______|					     |
|      |      |					     |
|      |      |					     |
|      |______|					     |
|______|______|______________________________________|
|   | o   [] O  |				     |
 \  |___________|				    /
  \ | AC  CH RF	|		 __		   /
   \|___________|_______________/__\______________/


Top view
 ______________________________________ ______ ______
|				       |      |	     |
|				       |______|	     |
|				       |      |	     |
|				       |======|	     |
|				       |======|	     |
|				       |======|	     |
|				       |======|	     |
|				       |======|	     |
|				       |======|	     |
|				       |======|	     |
|				       |======|	     |
|				       |======|	     |
|				       |======|	     |
|				       |======|	     |
|				       |======|	     |
|				       |======|	     |
|    __________________________________|======|______|
|   |				       |      |	     |
|   |				       |______|	     |
|   |				       |      |	     |
'___|__________________________________'______'______'


Bottom view
 ____________________________________________________
| O |			      O	|  |		 O   |
|   |  _     ________________	|  |	      _  |   |
|   | (_)   |		     |	|  |	     (_) |   |
|   |	    |		     |	|  |		 |   |
|   |=====  |		     |	|  |		 |   |
|   |=====  |________________|	|  |		 |   |
|   |				|  |		 |   |
|   |				|  |		 |   |
|   |				|  |		 |   |
|   |				|  |		 |   |
|   |=====		  ______|  |_____   =====|   |
|   |=====		 |.-------------.|  =====|   |
|   |=====		 ||   _______	||  =====|   |
|   --------------------- |  |_______|	|'--------   |
|   _____________________ |_____________||________   |
|   |			 |_______________|	 |   |
|   |			  			 |   |
|   |  _				      _  |   |
|   | (_)				     (_) |   |
|   |	  ______	      O			 |   |
'___O____|_o__o_|________________________________O___'


Controller	 | |					Controller Connector
 ________________|_|_________________________________	      .---.
|						     |	GND ->| O  \
|  ________________________________________________  |	CLK ->| O O |<- +5V
| |		    |_____________|		   | |	OUT ->| O O |<- D3
| |	  ___	     _____________		   | |	 D0 ->| O O |<- D4
| |	 |   |	    |_____________|   Nintendo®	   | |	      '-----'
| |   ___| | |___    _____________		   | |
| |  | __ ,-. __ |  |SELECT__START|   ___   ___	   | |
| |  |___ `-' ___|   _____________   |,-.| |,-.|   | |
| |	 | | |	    |_(___)_(___)_|  |._,| |._,|   | |
| |	 |___|	     _____________   '---B '---A   | |
| |_________________|_____________|________________| |
'____________________________________________________' */


#ifndef _Z_hardware_machine_platform_console_Nintendo_Entertainment_System_H_
#define _Z_hardware_machine_platform_console_Nintendo_Entertainment_System_H_

#include <Z/types/base.h>

/* MARK: - Memory map
.---------------------------------------------------------------.
| Location    | Size | Type| Content				|
|-------------+------+-----+------------------------------------|
| 2000	      |    1 | MMR | PPU register: Control		|
| 2001	      |    1 | MMR | PPU register: Mask			|
| 2002	      |    1 | MMR | PPU register: Status		|
| 2003	      |    1 | MMR | PPU register: OAM address		|
| 2004	      |    1 | MMR | PPU register: OAM data		|
| 2005	      |    1 | MMR | PPU register: Scroll		|
| 2006	      |    1 | MMR | PPU register: Address		|
| 2007	      |    1 | MMR | PPU register: Data			|
|-------------+------+-----+------------------------------------|
| 4000	      |    1 | MMR | APU register: APU square wave #0 A |
| 4001	      |    1 | MMR | APU register: APU square wave #0 B |
| 4002	      |    1 | MMR | APU register: APU square wave #0 C |
| 4003	      |    1 | MMR | APU register: APU square wave #0 D |
| 4004	      |    1 | MMR | APU register: APU square wave #1 A |
| 4005	      |    1 | MMR | APU register: APU square wave #1 B |
| 4006	      |    1 | MMR | APU register: APU square wave #1 c |
| 4007	      |    1 | MMR | APU register: APU square wave #1 D |
| 4008	      |    1 | MMR | APU register: APU triangle wave A	|
| 4009	      |    1 | MMR | APU register: APU triangle wave B	|
| 400A	      |    1 | MMR | APU register: APU triangle wave C	|
| 400B	      |    1 | MMR | APU register: APU triangle wave D	|
| 400C	      |    1 | MMR | APU register: APU noise A		|
| 400D	      |    1 | MMR | APU register: APU noise B		|
| 400E	      |    1 | MMR | APU register: APU noise C		|
| 400F	      |    1 | MMR | APU register: APU noise D		|
|-------------+------+-----+------------------------------------|
| 4014	      |    1 | I/O | DMA				|
| 4016	      |    1 | I/O | Joystick 1				|
| 4017	      |    1 | I/O | Joystick 2				|
|-------------+------+-----+------------------------------------|
| 5000	      |      |     | Expansion modules			|
|-------------+------+-----+------------------------------------|
| 6000	      |      | RAM | Cartridge RAM			|
|-------------+------+-----+------------------------------------|
| 8000	      |      | ROM | Lower Bank of Cartridge ROM	|
| C000	      |      | ROM | Upper Bank of Cartridge ROM	|
'--------------------------------------------------------------*/

#define Z_NES_ADDRESS_PPU_PATTERN_TABLE_0	     0x0000
#define Z_NES_ADDRESS_PPU_PATTERN_TABLE_1	     0x1000
#define Z_NES_ADDRESS_PPU_UNIVERSAL_BACKGROUND_COLOR 0x3F00
#define Z_NES_ADDRESS_PPU_BACKGROUND_PALETTE_0
#define Z_NES_ADDRESS_PPU_BACKGROUND_PALETTE_1
#define Z_NES_ADDRESS_PPU_BACKGROUND_PALETTE_2
#define Z_NES_ADDRESS_PPU_BACKGROUND_PALETTE_3
#define Z_NES_ADDRESS_PPU_SPRITE_PALETTE_0
#define Z_NES_ADDRESS_PPU_SPRITE_PALETTE_1
#define Z_NES_ADDRESS_PPU_SPRITE_PALETTE_2
#define Z_NES_ADDRESS_PPU_SPRITE_PALETTE_3

#define Z_NES_MMR_PPU_CONTROL	      0x2000 /* Write	     */
#define Z_NES_MMR_PPU_MASK	      0x2001 /* Write	     */
#define Z_NES_MMR_PPU_STATUS	      0x2002 /* Read	     */
#define Z_NES_MMR_PPU_OAM_ADDRESS     0x2003 /* Write	     */
#define Z_NES_MMR_PPU_OAM_DATA	      0x2004 /* Read / Write */
#define Z_NES_MMR_PPU_SCROLL	      0x2005 /* Write	     */
#define Z_NES_MMR_PPU_ADDRESS	      0x2006 /* Write	     */
#define Z_NES_MMR_PPU_DATA	      0x2007 /* Read / Write */
#define Z_NES_MMR_APU_SQUARE_WAVE_0A  0x4000
#define Z_NES_MMR_APU_SQUARE_WAVE_0B  0x4001
#define Z_NES_MMR_APU_SQUARE_WAVE_0C  0x4002
#define Z_NES_MMR_APU_SQUARE_WAVE_0D  0x4003
#define Z_NES_MMR_APU_SQUARE_WAVE_1A  0x4004
#define Z_NES_MMR_APU_SQUARE_WAVE_1B  0x4005
#define Z_NES_MMR_APU_SQUARE_WAVE_1C  0x4006
#define Z_NES_MMR_APU_SQUARE_WAVE_1D  0x4007
#define Z_NES_MMR_APU_TRIANGLE_WAVE_A 0x4008
#define Z_NES_MMR_APU_TRIANGLE_WAVE_B 0x4009
#define Z_NES_MMR_APU_TRIANGLE_WAVE_C 0x400A
#define Z_NES_MMR_APU_TRIANGLE_WAVE_D 0x400B
#define Z_NES_MMR_APU_NOISE_A	      0x400C
#define Z_NES_MMR_APU_NOISE_B	      0x400D
#define Z_NES_MMR_APU_NOISE_C	      0x400E
#define Z_NES_MMR_APU_NOISE_D	      0x400F
#define Z_NES_MMR_DMA		      0x4014
#define Z_NES_MMR_JOYSTICK_1	      0x4016 /* Read / Write */
#define Z_NES_MMR_JOYSTICK_2	      0x4017 /* Read / Write */

/* MARK: - Video */

#define Z_NES_PPU_GREYSCALE_MODE_NORMAL_COLOR	0
#define Z_NES_PPU_GREYSCALE_MODE_AND_ALL_COLORS	1

/* MARK: - Input */

#define Z_NES_CONTROLLER_BUTTON_A      0x01
#define Z_NES_CONTROLLER_BUTTON_B      0x02
#define Z_NES_CONTROLLER_BUTTON_SELECT 0x04
#define Z_NES_CONTROLLER_BUTTON_START  0x08
#define Z_NES_CONTROLLER_BUTTON_UP     0x10
#define Z_NES_CONTROLLER_BUTTON_DOWN   0x20
#define Z_NES_CONTROLLER_BUTTON_LEFT   0x40
#define Z_NES_CONTROLLER_BUTTON_RIGHT  0x80

/* MARK: - Screen */

#define Z_NES_SCREEN_WIDTH  256
#define Z_NES_SCREEN_HEIGHT 240

/* PPU (Picture Processing Unit) */


/*typedef Z_8BIT_FIELD_WITH_8_MEMBERS (

) ZNESSquareWaveRegisterA;*/


/*
	*/


/* Square Wave Register A
.-----------------.
| 7 6 5 4 3 2 1 0 |
'-\_/-|-|-\_____/-'
   |  | |    '----> Volume / Envelope decay rate
   |  | '---------> Envelope decay disable
   |  '-----------> Length counter clock disable / Envelope decay looping enable
   '--------------> Duty cycle type (Unused on noise channel) */

Z_DEFINE_STRICT_STRUCTURE (Z_BIT_FIELD(8, 4) (
	zuint8 duty_cycle_type		    :2,
	zuint8 envelope_decay_disable	    :1,
	zuint8 length_counter_clock_disable :1,
	zuint8 volume			    :4
)) ZNESSquareWaveA;

/* Square Wave Register B
.-----------------.
| 7 6 5 4 3 2 1 0 |
'-|-\___/-|-\___/-'
  |   |	  |   '---> Right shift amount
  |   |	  '-------> Decrease / Increase (1/0) wavelength
  |   '-----------> Sweep update rate
  '---------------> Sweep enable */

Z_DEFINE_STRICT_STRUCTURE (Z_BIT_FIELD(8, 4) (
	zuint8 sweep_enable		       :1,
	zuint8 sweep_update_rate	       :3,
	zuint8 decrease_or_increase_wavelength :1,
	zuint8 right_shift_amount	       :3
)) ZNESSquareWaveB;

/* Square Wave Register C */

typedef zuint8 ZNESSquareWaveC;

/* Square Wave Register D
.-----------------.
| 7 6 5 4 3 2 1 0 |
'-\_______/-\___/-'
      |	      '---> 3 MSB of wavelength (Unused on noise channel)
      '-----------> Length counter load register */

Z_DEFINE_STRICT_STRUCTURE (
) ZNESSquareWaveD;

/* Triangle Wave Register A
.-----------------.
| 7 6 5 4 3 2 1 0 |
'-|-\___________/-'
  |	  '-------> Linear counter load register
  '---------------> Length counter clock disable / Linear counter start */

Z_DEFINE_STRICT_STRUCTURE (
) ZNESTriangleWaveA;

/* Triangle Wave Register B
   .-----------------.
   | 7 6 5 4 3 2 1 0 | Unused
   '-----------------'
*/

/* Triangle Wave Register C
   .-----------------.
   | 7 6 5 4 3 2 1 0 | Eight LSB of wavelength
   '-----------------'
*/

typedef zuint8 ZNESTriangleWaveC;

/* Triangle Wave Register D
.-----------------.
| 7 6 5 4 3 2 1 0 |
'-\_______/-\___/-'
      |       '---> 3 MSB of wavelength (Unused on noise channel)
      '-----------> Length counter load register */

Z_DEFINE_STRICT_STRUCTURE (
) ZNESTriangleWaveD;

/* Noise Register A
.-----------------.
| 7 6 5 4 3 2 1 0 |
'-\_/-|-|-\_____/-'
   |  | |    '----> Volume / Envelope decay rate
   |  | '---------> Envelope decay disable
   |  '-----------> Length counter clock disable / Envelope decay looping enable
   '--------------> Duty cycle type (Unused on noise channel) */

Z_DEFINE_STRICT_STRUCTURE (
) ZNESNoiseA;

/* Noise Register B
   .-----------------.
   | 7 6 5 4 3 2 1 0 |
   '-----------------'
	  Unused
*/

/* Noise Register C
.-----------------.
| 7 6 5 4 3 2 1 0 |
'-|-\___/-\_____/-'
  |   |	     '----> Playback sample rate
  |   '-----------> Unused
  '---------------> random number type generation */

Z_DEFINE_STRICT_STRUCTURE (
) ZNESNoiseC;

/* Noise Register D
.-----------------.
| 7 6 5 4 3 2 1 0 |
'-\_______/-\___/-'
      |       '---> 3 MSB of wavelength (Unused on noise channel)
      '-----------> Length counter load register */

Z_DEFINE_STRICT_STRUCTURE (
) ZNESNoiseD;

#endif /* _Z_hardware_machine_platform_console_Nintendo_Entertainment_System_H_ */
