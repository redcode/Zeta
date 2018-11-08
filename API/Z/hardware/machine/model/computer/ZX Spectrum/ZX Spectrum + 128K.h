/* Z Kit - hardware/machine/model/computer/ZX Spectrum/ZX Spectrum + 128K.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.

.----------------------------------------------.
|   Vendor: Sinclair Research - Investronica   |
| Released: 1985-09			       |
|      CPU: Zilog Z80 @ 3.5469 MHz	       |
|      ROM: 48K				       |
|      RAM: 128K			       |
|    Sound: General Instrument AY-3-8912 (PSG) |
'----------------------------------------------'

 _____________________________				  ________________
|  ___. __  __	  __ . __     ''''''''''''''''''''''''''''	     |====|
| __\ ||  ||__|__|--|||						     |====|
|--------------------------------------------------------------------|====|
| ZX Spectrum +							     |====|
|--.-----------------------------------------------------.-----------|====|
|  |( )|( )|(1)|(2)|(3)|(4)|(5)|(6)|(7)|(1)|(1)|(1)|(BRK)|	     |====|
|--|-----------------------------------------------------|-----------|====|
|  |(DEL)|(1)|(Q)|(W)|(E)|(R)|(T)|(Y)|(U)|(I)|(O)|(P)|.-.|	     |====|
|--|-------------------------------------------------|| ||-----------|====|
|  |(EXT)|(ED)|(A)|(S)|(D)|(F)|(G)|(H)|(J)|(K)|(L)|(____'|	     |====|
|--|-----------------------------------------------------|-----------|====|
|  |(CAPS S)|( )|(Z)|(X)|(C)|(V)|(B)|(N)|(M)|(.)|(CAPS S)|	     |====|
|--|-----------------------------------------------------|-----------|====|
|  |( )|(;)|(")|(_)|(_)|(_______________)|(_)|(_)|(,)|(_)|  128K//// |====|
|--'-----------------------------------------------------'-----------|====|
|____________________________________________________________________|====| */

#ifndef _Z_hardware_machine_model_computer_ZX_Spectrum_ZX_Spectrum_Plus_128K_H_
#define _Z_hardware_machine_model_computer_ZX_Spectrum_ZX_Spectrum_Plus_128K_H_

#include <Z/hardware/machine/model/computer/ZX Spectrum/ZX Spectrum.h>
#include <Z/types/base.h>

/* MARK: - Memory

     .-----------------.
0000 | ROM 0  | ROM 1  | Either ROM may be switched in.
     |	      |	       |
     |	      |	       |
3FFF |	      |	       |
     |--------+--------'
4000 | Bank 5 |
     |	      |
     |	      |
7FFF | screen |
     |--------|
8000 | Bank 2 |        Any one of these pages may be switched in.
     |	      |
     |	      |
BFFF |	      |
     |--------+--------------------------------------------------------------.
C000 | Bank 0 | Bank 1 | Bank 2 | Bank 3 | Bank 4 | Bank 5 | Bank 6 | Bank 7 |
     |	      |	       |(also at|	 |	  |(also at|	    |	     |
     |	      |	       | 8000)  |	 |	  | 4000)  |	    |	     |
FFFF |	      |	       |	|	 |	  | screen |	    | screen |
     '----------------------------------------------------------------------*/

#define Z_ZX_SPECTRUM_PLUS_128K_SIZE_ROM    32768  /* 1024 * 32		*/
#define Z_ZX_SPECTRUM_PLUS_128K_SIZE_RAM    131072 /* 1024 * 128	*/
#define Z_ZX_SPECTRUM_PLUS_128K_SIZE_MEMORY 163840 /* 1024 * (32 + 128) */

/* MARK: - I/O Ports */

#define Z_ZX_SPECTRUM_PLUS_128K_IO_PORT_BANK_SWITCH 0x7FFD /* Read / Write */
#define Z_ZX_SPECTRUM_PLUS_128K_IO_PORT_PSG	    0xFFFD /* Read / Write */

/* 7FFD - Bank Switch
.-----------------.
| 7 6 5 4 3 2 1 0 |
'-\_/-|-|-|-\___/-'
   |  | | |   '---> user (C000h)
   |  | | '-------> VRAM
   |  | '---------> ROM
   |  '-----------> disable
   '--------------> unused */

Z_DEFINE_STRICT_STRUCTURE (Z_BIT_FIELD(8, 5) (
	zuint8 unused  :2,
	zuint8 disable :1,
	zuint8 rom     :1,
	zuint8 vram    :1,
	zuint8 user    :3
)) ZZXSpectrumPlus128KBankSwitch;

/* FFFD - Read/Select */

/* MARK: - Screen
				     ---
       Invisible Top Border	      | 7
.---------------------------------.  ---   ---
|	Visible Top Border	  |   | 48  |
|----.-----------------------.----|  ---    |
|L   |			     |R	  |   |	    |
|e   |			     |i	  |   |	    |
|f  B|			     |g  B|   |	    |
|t  o|	       Paper	     |h  o|   | 192 | 296
|   r|			     |t  r|   |	    |
|   d|			     |	 d|   |	    |
|   e|			     |	 e|   |	    |
|   r|			     |	 r|   |	    |
|----'-----------------------'----|  ---    |
|	   Bottom Border	  |   | 56  |
'---------------------------------'  ---   ---

|----|-----------------------|----|
  48		256	       48
|---------------------------------|
		352			*/

#define Z_ZX_SPECTRUM_PLUS_128K_SCREEN_FPS			   Z_ZX_SPECTRUM_SCREEN_FPS
#define Z_ZX_SPECTRUM_PLUS_128K_SCREEN_WIDTH			   Z_ZX_SPECTRUM_SCREEN_WIDTH
#define Z_ZX_SPECTRUM_PLUS_128K_SCREEN_HEIGHT			   Z_ZX_SPECTRUM_SCREEN_HEIGHT
#define Z_ZX_SPECTRUM_PLUS_128K_SCREEN_PIXELS			   Z_ZX_SPECTRUM_SCREEN_PIXELS
#define Z_ZX_SPECTRUM_PLUS_128K_SCREEN_PAPER_WIDTH		   Z_ZX_SPECTRUM_SCREEN_PAPER_WIDTH
#define Z_ZX_SPECTRUM_PLUS_128K_SCREEN_PAPER_HEIGHT		   Z_ZX_SPECTRUM_SCREEN_PAPER_HEIGHT
#define Z_ZX_SPECTRUM_PLUS_128K_SCREEN_PAPER_PIXELS		   Z_ZX_SPECTRUM_SCREEN_PAPER_PIXELS
#define Z_ZX_SPECTRUM_PLUS_128K_SCREEN_TOP_BORDER_HEIGHT	   55
#define Z_ZX_SPECTRUM_PLUS_128K_SCREEN_INVISIBLE_TOP_BORDER_HEIGHT 7
#define Z_ZX_SPECTRUM_PLUS_128K_SCREEN_VISIBLE_TOP_BORDER_HEIGHT   Z_ZX_SPECTRUM_SCREEN_VISIBLE_TOP_BORDER_HEIGHT
#define Z_ZX_SPECTRUM_PLUS_128K_SCREEN_BOTTOM_BORDER_HEIGHT	   Z_ZX_SPECTRUM_SCREEN_BOTTOM_BORDER_HEIGHT
#define Z_ZX_SPECTRUM_PLUS_128K_SCREEN_LEFT_BORDER_WIDTH	   Z_ZX_SPECTRUM_SCREEN_LEFT_BORDER_WIDTH
#define Z_ZX_SPECTRUM_PLUS_128K_SCREEN_RIGHT_BORDER_WIDTH	   Z_ZX_SPECTRUM_SCREEN_RIGHT_BORDER_WIDTH

/* MARK: - Timmings */

#define Z_ZX_SPECTRUM_PLUS_128K_CPU_HZ			       3546900
#define Z_ZX_SPECTRUM_PLUS_128K_PSG_HZ			       1773400
#define Z_ZX_SPECTRUM_PLUS_128K_CYCLES_PER_FRAME	       70908
#define Z_ZX_SPECTRUM_PLUS_128K_CYCLES_PER_SCANLINE	       228
#define Z_ZX_SPECTRUM_PLUS_128K_CYCLES_PER_HBLANK	       52
#define Z_ZX_SPECTRUM_PLUS_128K_CYCLES_PER_VBLANK	       1824
#define Z_ZX_SPECTRUM_PLUS_128K_CYCLES_PER_TOP_BORDER_LINE     Z_ZX_SPECTRUM_CYCLES_PER_TOP_BORDER_LINE
#define Z_ZX_SPECTRUM_PLUS_128K_CYCLES_PER_LEFT_BORDER_LINE    Z_ZX_SPECTRUM_CYCLES_PER_LEFT_BORDER_LINE
#define Z_ZX_SPECTRUM_PLUS_128K_CYCLES_PER_RIGHT_BORDER_LINE   Z_ZX_SPECTRUM_CYCLES_PER_RIGHT_BORDER_LINE
#define Z_ZX_SPECTRUM_PLUS_128K_CYCLES_PER_BOTTOM_BORDER_LINE  Z_ZX_SPECTRUM_CYCLES_PER_BOTTOM_BORDER_LINE
#define Z_ZX_SPECTRUM_PLUS_128K_CYCLES_PER_PAPER_LINE	       Z_ZX_SPECTRUM_CYCLES_PER_PAPER_LINE
#define Z_ZX_SPECTRUM_PLUS_128K_CYCLES_PER_INT		       Z_ZX_SPECTRUM_CYCLES_PER_INT
#define Z_ZX_SPECTRUM_PLUS_128K_CYCLES_AT_VBLANK	       Z_ZX_SPECTRUM_CYCLES_AT_VBLANK
#define Z_ZX_SPECTRUM_PLUS_128K_CYCLES_AT_INT		       Z_ZX_SPECTRUM_CYCLES_AT_INT
#define Z_ZX_SPECTRUM_PLUS_128K_CYCLES_AT_INVISIBLE_TOP_BORDER 1824  /* Z_ZX_SPECTRUM_PLUS_128K_CYCLES_PER_VBLANK		   */
#define Z_ZX_SPECTRUM_PLUS_128K_CYCLES_AT_VISIBLE_TOP_BORDER   3420  /* Z_ZX_SPECTRUM_PLUS_128K_CYCLES_AT_INVISIBLE_TOP_BORDER +
									Z_ZX_SPECTRUM_PLUS_128K_CYCLES_PER_SCANLINE	       *
									Z_ZX_SPECTRUM_PLUS_128K_SCREEN_INVISIBLE_TOP_BORDER_HEIGHT */
#define Z_ZX_SPECTRUM_PLUS_128K_CYCLES_AT_PAPER_REGION	       14364 /* Z_ZX_SPECTRUM_PLUS_128K_CYCLES_AT_VISIBLE_TOP_BORDER +
									Z_ZX_SPECTRUM_PLUS_128K_CYCLES_PER_SCANLINE	     *
									Z_ZX_SPECTRUM_PLUS_128K_SCREEN_VISIBLE_TOP_BORDER_HEIGHT   */
#define Z_ZX_SPECTRUM_PLUS_128K_CYCLES_AT_BOTTOM_BORDER	       58140 /* Z_ZX_SPECTRUM_PLUS_128K_CYCLES_AT_PAPER_REGION +
									Z_ZX_SPECTRUM_PLUS_128K_CYCLES_PER_SCANLINE    *
									Z_ZX_SPECTRUM_PLUS_128K_SCREEN_PAPER_HEIGHT		   */

#endif /* _Z_hardware_machine_model_computer_ZX_Spectrum_ZX_Spectrum_Plus_128K_H_ */
