/* Z Kit - hardware/machine/model/computer/ZX Spectrum/ZX Spectrum.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.

.---------------------------------.
|   Vendor: Sinclair Research	  |
| Released: 1982-04-23		  |
|      CPU: Zilog Z80 @ 3.5 MHz	  |
|      ROM: 16K			  |
|      RAM: 16K / 48K		  |
|    Sound: Internal speaker	  |
'---------------------------------'

 __________________________________________________
|  ___. __  _	  __ . __			   |
| __\ ||  ||__|__|--|||				   |
| ZX Spectrum					   |
|						   |
| ________________________________________________ |
|/________________________________________________\|
|  _   _   _   _   _   _   _   _   _   _	   |
| [1] [2] [3] [4] [5] [6] [7] [8] [9] [0]	   |
|     _   _   _   _   _   _   _   _   _   _	   |
|    [Q] [W] [E] [R] [T] [Y] [U] [I] [O] [P]	  /|
|	_   _	_   _	_   _	_   _	_   _____//|
|      [A] [S] [D] [F] [G] [H] [J] [K] [L] [ENTER]/|
|  _____   _   _   _   _   _   _   _   __   ___////|
| [SHIFT] [Z] [X] [C] [V] [B] [N] [M] [SS] [SPACE] |
|____________________________________________////__|
(__________________________________________________) */

#ifndef _Z_hardware_machine_model_computer_ZX_Spectrum_ZX_Spectrum_H_
#define _Z_hardware_machine_model_computer_ZX_Spectrum_ZX_Spectrum_H_

/* MARK: - Memory */

#define Z_ZX_SPECTRUM_SIZE_ROM	      16384 /* 1024 * 16	*/
#define Z_ZX_SPECTRUM_16K_SIZE_RAM    16384 /* 1024 * 16	*/
#define Z_ZX_SPECTRUM_16K_SIZE_MEMORY 32768 /* 1024 * (16 + 16)	*/
#define Z_ZX_SPECTRUM_48K_SIZE_RAM    49152 /* 1024 * 48	*/
#define Z_ZX_SPECTRUM_48K_SIZE_MEMORY 65536 /* 1024 * (16 + 48) */

/* MARK: - Screen
				     ---
       Invisible Top Border	      | 8
.---------------------------------.  ---   ---
|	Visible Top Border	  |   | 48  |
|----.-----------------------.----|  ---    |
|L   |			     |R   |   |	    |
|e   |			     |i   |   |	    |
|f  B|			     |g  B|   |	    |
|t  o|	       Paper	     |h  o|   | 192 | 296
|   r|			     |t  r|   |	    |
|   d|			     |   d|   |	    |
|   e|			     |   e|   |	    |
|   r|			     |   r|   |	    |
|----'-----------------------'----|  ---    |
|	   Bottom Border	  |   | 56  |
'---------------------------------'  ---   ---

|----|-----------------------|----|
  48		256	       48
|---------------------------------|
		352			*/

#define Z_ZX_SPECTRUM_SCREEN_FPS			 50
#define Z_ZX_SPECTRUM_SCREEN_WIDTH			 352
#define Z_ZX_SPECTRUM_SCREEN_HEIGHT			 296
#define Z_ZX_SPECTRUM_SCREEN_PIXELS			 104192 /* 352 * 296 */
#define Z_ZX_SPECTRUM_SCREEN_PAPER_WIDTH		 256
#define Z_ZX_SPECTRUM_SCREEN_PAPER_HEIGHT		 192
#define Z_ZX_SPECTRUM_SCREEN_PAPER_PIXELS		 49152	/* 256 * 192 */
#define Z_ZX_SPECTRUM_SCREEN_TOP_BORDER_HEIGHT		 56
#define Z_ZX_SPECTRUM_SCREEN_INVISIBLE_TOP_BORDER_HEIGHT 8
#define Z_ZX_SPECTRUM_SCREEN_VISIBLE_TOP_BORDER_HEIGHT	 48
#define Z_ZX_SPECTRUM_SCREEN_BOTTOM_BORDER_HEIGHT	 56
#define Z_ZX_SPECTRUM_SCREEN_LEFT_BORDER_WIDTH		 48
#define Z_ZX_SPECTRUM_SCREEN_RIGHT_BORDER_WIDTH		 48

/* MARK: - Timmings */

#define Z_ZX_SPECTRUM_CPU_HZ			     3500000
#define Z_ZX_SPECTRUM_CYCLES_PER_FRAME		     69888
#define Z_ZX_SPECTRUM_CYCLES_PER_SCANLINE	     224
#define Z_ZX_SPECTRUM_CYCLES_PER_HBLANK		     48
#define Z_ZX_SPECTRUM_CYCLES_PER_VBLANK		     1792
#define Z_ZX_SPECTRUM_CYCLES_PER_TOP_BORDER_LINE     176
#define Z_ZX_SPECTRUM_CYCLES_PER_LEFT_BORDER_LINE    24
#define Z_ZX_SPECTRUM_CYCLES_PER_RIGHT_BORDER_LINE   24
#define Z_ZX_SPECTRUM_CYCLES_PER_BOTTOM_BORDER_LINE  176
#define Z_ZX_SPECTRUM_CYCLES_PER_PAPER_LINE	     128
#define Z_ZX_SPECTRUM_CYCLES_PER_INT		     32
#define Z_ZX_SPECTRUM_CYCLES_AT_VBLANK		     0
#define Z_ZX_SPECTRUM_CYCLES_AT_INT		     24
#define Z_ZX_SPECTRUM_CYCLES_AT_INVISIBLE_TOP_BORDER 1792  /* Z_ZX_SPECTRUM_CYCLES_PER_VBLANK		       */
#define Z_ZX_SPECTRUM_CYCLES_AT_VISIBLE_TOP_BORDER   3584  /* Z_ZX_SPECTRUM_CYCLES_AT_INVISIBLE_TOP_BORDER +
							      Z_ZX_SPECTRUM_CYCLES_PER_SCANLINE		   *
							      Z_ZX_SPECTRUM_SCREEN_INVISIBLE_TOP_BORDER_HEIGHT */
#define Z_ZX_SPECTRUM_CYCLES_AT_PAPER_REGION	     14336 /* Z_ZX_SPECTRUM_CYCLES_AT_VISIBLE_TOP_BORDER +
							      Z_ZX_SPECTRUM_CYCLES_PER_SCANLINE		 *
							      Z_ZX_SPECTRUM_SCREEN_VISIBLE_TOP_BORDER_HEIGHT   */
#define Z_ZX_SPECTRUM_CYCLES_AT_BOTTOM_BORDER	     57344 /* Z_ZX_SPECTRUM_CYCLES_AT_PAPER_REGION +
							      Z_ZX_SPECTRUM_CYCLES_PER_SCANLINE    *
							      Z_ZX_SPECTRUM_SCREEN_PAPER_HEIGHT		       */

#endif /* _Z_hardware_machine_model_computer_ZX_Spectrum_ZX_Spectrum_H_ */
