/* Q API - hardware/machine/platform/console/Nintendo Entertainment System.h
 __ __		  _		   _
|  \  | _  ____  | |  ___  ____  _| | ___
|     |(_)|    ||_ _|/ -_)|    |/ _ |/ . \
|__\__||_||__|_| |_| \___/|__|_|\___|\___/
 ENTERTAINMENT SYSTEM HARDWARE HEADER
Copyright © 2006-2014 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3.

 CPU: Ricoh RP2A03 (see <Q/hardware/CPU/RP2A03.h>)
 GPU: Ricoh RP2C02 (see <Q/hardware/GPU/RP2C02.h>)
 APU:							*/

#ifndef __Q_hardware_machine_platform_console_Nintendo_Entertainment_System_H__
#define __Q_hardware_machine_platform_console_Nintendo_Entertainment_System_H__

#include <Q/types/base.h>
#include <Q/macros/bit field.h>

#define Q_NES_6502_HZ		1789773
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
| 4000	 |     1 | MMR | APU register: square_wave_0_a |
| 4001	 |     1 | MMR | APU register: square_wave_0_b |
| 4002	 |     1 | MMR | APU register: square_wave_0_c |
| 4003	 |     1 | MMR | APU register: square_wave_0_d |
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











/* PPU (Picture Processing Unit) */





typedef Q_8BIT_FIELD_WITH_8_MEMBERS (

) QNESSquareWaveRegisterA;


/*
      .---.
GND --| O  \
CLK --| O O |-- +5V
OUT --| O O |-- D3
 D0 --| O O |-- D4
      '-----'		*/


/* Square Wave Register A 
.-----------------.
| 7 6 5 4 3 2 1 0 |
'-\_/-|-|-\_____/-'
   |  | |    '----> Volume / Envelope decay rate
   |  | '---------> Envelope decay disable
   |  '-----------> Length counter clock disable / Envelope decay looping enable
   '--------------> Duty cycle type (Unused on noise channel) */

typedef Q_STRICT_8BIT_FIELD (
	quint8 duty_cycle_type		    :2,
	quint8 envelope_decay_disable	    :1,
	quint8 length_counter_clock_disable :1,
	quint8 volume			    :4
) QNESSquareWaveA;

/* Square Wave Register B
.-----------------.
| 7 6 5 4 3 2 1 0 |
'-|-\___/-|-\___/-'
  |   |   |   '---> Right shift amount
  |   |   '-------> Decrease / Increase (1/0) wavelength
  |   '-----------> Sweep update rate
  '---------------> Sweep enable */

typedef Q_STRICT_8BIT_FIELD (
	quint8 sweep_enable		       :1,
	quint8 sweep_update_rate	       :3,
	quint8 decrease_or_increase_wavelength :1,
	quint8 right_shift_amount	       :3
) QNESSquareWaveB;

/* Square Wave Register C */

typedef quint8 QNESSquareWaveC;

/* Square Wave Register D
.-----------------.
| 7 6 5 4 3 2 1 0 |
'-\_______/-\___/-'
      |       '---> 3 MSB of wavelength (Unused on noise channel)
      '-----------> Length counter load register */

typedef Q_STRICT_8BIT_FIELD (
) QNESSquareWaveD;

/* Triangle Wave Register A
.-----------------.
| 7 6 5 4 3 2 1 0 |
'-|-\___________/-'
  |	  '-------> Linear counter load register
  '---------------> Length counter clock disable / Linear counter start */

typedef Q_STRICT_8BIT_FIELD (
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

typedef Q_STRICT_8BIT_FIELD (
) QNESTriangleWaveD;

/* Noise Register A
.-----------------.
| 7 6 5 4 3 2 1 0 |
'-\_/-|-|-\_____/-'
   |  | |    '----> Volume / Envelope decay rate
   |  | '---------> Envelope decay disable
   |  '-----------> Length counter clock disable / Envelope decay looping enable
   '--------------> Duty cycle type (Unused on noise channel) */

typedef Q_STRICT_8BIT_FIELD (
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

typedef Q_STRICT_8BIT_FIELD (
) QNESNoiseC;

/* Noise Register D
.-----------------.
| 7 6 5 4 3 2 1 0 |
'-\_______/-\___/-'
      |       '---> 3 MSB of wavelength (Unused on noise channel)
      '-----------> Length counter load register */

typedef Q_STRICT_8BIT_FIELD_WITH_2_MEMBERS (
) QNESNoiseD;

#endif /* __Q_hardware_machine_platform_console_Nintendo_Entertainment_System_H__ */
