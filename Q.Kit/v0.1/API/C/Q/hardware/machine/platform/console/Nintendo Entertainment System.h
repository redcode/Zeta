/* Q Kit C API - hardware/machine/platform/console/Nintendo Entertainment System.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.
 ___________________________________________
/\					    \
\_| Vendor:   Nintendo			     |
  | Released: 1983-07-15 (JP)		     |
  |	      1985-10-18 (US)		     |
  |	      1986-09-01 (DE-DK-FR-NL-NO-SE) |
  |	      1997	 (AU-IE-IT-NZ-UK)    |
  | CPU:      Ricoh RP2A03		     |
  | Video:    Ricoh RP2C02 (VCD) (PAL)	     |
  |           RP2C03 (VCD) (NTSC)	     |
  | Sound:    NES APU			     |
  |   _______________________________________|_
   \_/________________________________________/

 Front view						 Joystick Connector
 ___ __________________________________ ______ ______	       .---.
|   |				       |______|      |	 GND --| O  \
|   | Nintendo©			       |      |      |	 CLK --| O O |-- +5V
|   | ENTERTAINMENT SYSTEM™	       |      |      |	 OUT --| O O |-- D3
|   |__________________________________|______|      |	  D0 --| O O |-- D4
|______________________________________|______|______|	       '-----'
|   |	 _____	 _____	|	       | 1  2 |      |
 \  | o [POWER] [RESET] |	       ||\ |\ |     /
  \ |___________________|	       ||_||_||    /
   \___________________________________|______|___/

Back view
 ____________________________________________________
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
 ____________________________________________________
|				       |      |      |
|				       |______|      |
|				       |      |      |
|				       |======|      |
|				       |======|      |
|				       |======|      |
|				       |======|      |
|				       |======|      |
|				       |======|      |
|				       |======|      |
|				       |======|      |
|				       |======|      |
|				       |======|      |
|				       |======|      |
|				       |======|      |
|				       |======|      |
|    __________________________________|======|______|
|   |				       |      |      |
|   |				       |______|      |
|   |				       |      |      |
'___|__________________________________|______|______'

Bottom view
 ____________________________________________________
| O |   		      O	|  |		 O   |
|   |  _     ________________	|  |	      _  |   |
|   | (_)   |		     |	|  |	     (_) |   |
|   |	    |		     |	|  |		 |   |
|   |=====  |		     |	|  |	         |   |
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
'___O____|_o__o_|________________________________O__*/

#ifndef __Q_hardware_machine_platform_console_Nintendo_Entertainment_System_H__
#define __Q_hardware_machine_platform_console_Nintendo_Entertainment_System_H__

#include <Q/types/base.h>
#include <Q/macros/bit field.h>

/* MARK: - Timmings */

#define Q_NES_SCREEN_WIDTH	256
#define Q_NES_SCREEN_HEIGHT	240

/* MARK: - Memory Structure
.----------------------------------------------------------------.
| Address     | Size  | Type    | Content			    |
|-------------+-------+----------------------------------|
| 0000	 |       | RAM | PPU register: control	    |
|-------------+-------+-----+----------------------------|
| 2000	 |     1 | MMR | PPU register: control	    |
| 2001	 |     1 | MMR | PPU register: mask	    |
| 2002	 |     1 | MMR | PPU register: status	    |
| 2003	 |     1 | MMR | PPU register: oam_address  |
| 2004	 |     1 | MMR | PPU register: oam_data	    |
| 2005	 |     1 | MMR | PPU register: scroll	    |
| 2006	 |     1 | MMR | PPU register: address	    |
| 2007	 |     1 | MMR | PPU register: data	    |
|-------------+-------+-----+-------------------------------|
| 4000	 |     1 | MMR | APU register: APU Square Wave #0 A |
| 4001	 |     1 | MMR | APU register: APU Square Wave #0 B |
| 4002	 |     1 | MMR | APU register: APU Square Wave #0 C |
| 4003	 |     1 | MMR | APU register: APU Square Wave #0 D |
| 4004	 |     1 | MMR | APU register: square_wave_1_a |
| 4005	 |     1 | MMR | APU register: square_wave_1_b |
| 4006	 |     1 | MMR | APU register: square_wave_1_c |
| 4007	 |     1 | MMR | APU register: square_wave_1_d |
| 4008	 |     1 | MMR | APU register: triangle_wave_a |
| 4009	 |     1 | MMR | APU register: triangle_wave_b |
| 400A	 |     1 | MMR | APU register: triangle_wave_c |
| 400B	 |     1 | MMR | APU register: triangle_wave_d |
| 400C	 |     1 | MMR | APU register: noise_a	       |
| 400D	 |     1 | MMR | APU register: noise_b	       |
| 400E	 |     1 | MMR | APU register: noise_c	       |
| 400F	 |     1 | MMR | APU register: noise_d	       |
|-------------+-------+----------+--------------------------|
| 4014	 |     1 | I/O port | DMA			    |
| 4016	 |     1 | I/O port | Joystick 1		    |
| 4017	 |     1 | I/O port | Joystick 2		    |
|-------------+-------+----------+-------------------------------|
| 5000	 |       |          | Expansion modules		    |
|-------------+-------+----------+-------------------------------|
| 6000	 |       | RAM      | Cartridge RAM		    |
|-------------+-------+----------+-------------------------------|
| 8000	 |       | ROM      | Lower Bank of Cartridge ROM   |
| C000	 |       | ROM      | Upper Bank of Cartridge ROM   |
'----------------------------------------------------------------' */

/* MARK: - I/O Ports */

#define Q_NES_MMR_PPU_CONTROL		0x2000	/* Write	*/
#define Q_NES_MMR_PPU_MASK		0x2001	/* Write	*/
#define Q_NES_MMR_PPU_STATUS		0x2002	/* Read		*/
#define Q_NES_MMR_PPU_OAM_ADDRESS	0x2003	/* Write	*/
#define Q_NES_MMR_PPU_OAM_DATA		0x2004	/* Read / Write */
#define Q_NES_MMR_PPU_SCROLL		0x2005	/* Write	*/
#define Q_NES_MMR_PPU_ADDRESS		0x2006	/* Write	*/
#define Q_NES_MMR_PPU_DATA		0x2007	/* Read / Write */
#define Q_NES_MMR_APU_SQUARE_WAVE_0A	0x4000	/*		*/
#define Q_NES_MMR_APU_SQUARE_WAVE_0B	0x4001
#define Q_NES_MMR_APU_SQUARE_WAVE_0C	0x4002
#define Q_NES_MMR_APU_SQUARE_WAVE_0D	0x4003
#define Q_NES_MMR_APU_SQUARE_WAVE_1A	0x4004
#define Q_NES_MMR_APU_SQUARE_WAVE_1B	0x4005
#define Q_NES_MMR_APU_SQUARE_WAVE_1C	0x4006
#define Q_NES_MMR_APU_SQUARE_WAVE_1D	0x4007
#define Q_NES_MMR_APU_TRIANGLE_WAVE_A	0x4008
#define Q_NES_MMR_APU_TRIANGLE_WAVE_B	0x4009
#define Q_NES_MMR_APU_TRIANGLE_WAVE_C	0x400A
#define Q_NES_MMR_APU_TRIANGLE_WAVE_D	0x400B
#define Q_NES_MMR_APU_NOISE_A		0x400C
#define Q_NES_MMR_APU_NOISE_B		0x400D
#define Q_NES_MMR_APU_NOISE_C		0x400E
#define Q_NES_MMR_APU_NOISE_D		0x400F
#define Q_NES_MMR_DMA			0x4014
#define Q_NES_MMR_JOYSTICK_1		0x4016	/* Read / Write */
#define Q_NES_MMR_JOYSTICK_2		0x4017	/* Read / Write */

/* MARK: - Memory addresses */

#define Q_NES_ADDRESS_PPU_PATTERN_TABLE_0		0x0000
#define Q_NES_ADDRESS_PPU_PATTERN_TABLE_1		0x1000
#define Q_NES_ADDRESS_PPU_UNIVERSAL_BACKGROUND_COLOR	0x3F00
#define Q_NES_ADDRESS_PPU_BACKGROUND_PALETTE_0
#define Q_NES_ADDRESS_PPU_BACKGROUND_PALETTE_1
#define Q_NES_ADDRESS_PPU_BACKGROUND_PALETTE_2
#define Q_NES_ADDRESS_PPU_BACKGROUND_PALETTE_3
#define Q_NES_ADDRESS_PPU_SPRITE_PALETTE_0
#define Q_NES_ADDRESS_PPU_SPRITE_PALETTE_1
#define Q_NES_ADDRESS_PPU_SPRITE_PALETTE_2
#define Q_NES_ADDRESS_PPU_SPRITE_PALETTE_3

/* MARK: - Video */

#define Q_NES_PPU_GREYSCALE_MODE_NORMAL_COLOR	0
#define Q_NES_PPU_GREYSCALE_MODE_AND_ALL_COLORS	1

/* MARK: - Input */

#define Q_NES_CONTROLLER_BUTTON_A	0x01
#define Q_NES_CONTROLLER_BUTTON_B	0x02
#define Q_NES_CONTROLLER_BUTTON_SELECT	0x04
#define Q_NES_CONTROLLER_BUTTON_START	0x08
#define Q_NES_CONTROLLER_BUTTON_UP	0x10
#define Q_NES_CONTROLLER_BUTTON_DOWN	0x20
#define Q_NES_CONTROLLER_BUTTON_LEFT	0x40
#define Q_NES_CONTROLLER_BUTTON_RIGHT	0x80







/* PPU (Picture Processing Unit) */







/*typedef Q_8BIT_FIELD_WITH_8_MEMBERS (

) QNESSquareWaveRegisterA;*/


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

Q_DEFINE_STRICT_STRUCTURE (Q_8BIT_FIELD(4) (
	quint8 duty_cycle_type		    :2,
	quint8 envelope_decay_disable	    :1,
	quint8 length_counter_clock_disable :1,
	quint8 volume			    :4
)) QNESSquareWaveA;

/* Square Wave Register B
.-----------------.
| 7 6 5 4 3 2 1 0 |
'-|-\___/-|-\___/-'
  |   |   |   '---> Right shift amount
  |   |   '-------> Decrease / Increase (1/0) wavelength
  |   '-----------> Sweep update rate
  '---------------> Sweep enable */

Q_DEFINE_STRICT_STRUCTURE (Q_8BIT_FIELD(4) (
	quint8 sweep_enable		       :1,
	quint8 sweep_update_rate	       :3,
	quint8 decrease_or_increase_wavelength :1,
	quint8 right_shift_amount	       :3
)) QNESSquareWaveB;

/* Square Wave Register C */

typedef quint8 QNESSquareWaveC;

/* Square Wave Register D
.-----------------.
| 7 6 5 4 3 2 1 0 |
'-\_______/-\___/-'
      |       '---> 3 MSB of wavelength (Unused on noise channel)
      '-----------> Length counter load register */

Q_DEFINE_STRICT_STRUCTURE (
) QNESSquareWaveD;

/* Triangle Wave Register A
.-----------------.
| 7 6 5 4 3 2 1 0 |
'-|-\___________/-'
  |	  '-------> Linear counter load register
  '---------------> Length counter clock disable / Linear counter start */

Q_DEFINE_STRICT_STRUCTURE (
) QNESTriangleWaveA;

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

typedef quint8 QNESTriangleWaveC;

/* Triangle Wave Register D
.-----------------.
| 7 6 5 4 3 2 1 0 |
'-\_______/-\___/-'
      |       '---> 3 MSB of wavelength (Unused on noise channel)
      '-----------> Length counter load register */

Q_DEFINE_STRICT_STRUCTURE (
) QNESTriangleWaveD;

/* Noise Register A
.-----------------.
| 7 6 5 4 3 2 1 0 |
'-\_/-|-|-\_____/-'
   |  | |    '----> Volume / Envelope decay rate
   |  | '---------> Envelope decay disable
   |  '-----------> Length counter clock disable / Envelope decay looping enable
   '--------------> Duty cycle type (Unused on noise channel) */

Q_DEFINE_STRICT_STRUCTURE (
) QNESNoiseA;

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

Q_DEFINE_STRICT_STRUCTURE (
) QNESNoiseC;

/* Noise Register D
.-----------------.
| 7 6 5 4 3 2 1 0 |
'-\_______/-\___/-'
      |       '---> 3 MSB of wavelength (Unused on noise channel)
      '-----------> Length counter load register */

Q_DEFINE_STRICT_STRUCTURE (
) QNESNoiseD;

#endif /* __Q_hardware_machine_platform_console_Nintendo_Entertainment_System_H__ */
