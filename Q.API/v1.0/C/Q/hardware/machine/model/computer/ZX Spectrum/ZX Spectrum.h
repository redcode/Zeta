/* Q API - hardware/machine/model/computer/ZX Spectrum/ZX Spectrum.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2014 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3.

.-------------------------------.
|   Vendor: Sinclair Research	|
| Released: 1982-04-23		|
|      CPU: Zilog Z80 @ 3.5 MHz |
|      ROM: 16K			|
|      RAM: 16K / 48K		|
|    Sound: Internal speaker	|
'-------------------------------'

 __________________________________________________
|  ___. __  _	  __ . __			   |
| __\ ||  ||__|__|--|||				   |
| ZX Spectrum					   |
|						   |
| ================================================ |
|/ _   _   _   _   _   _   _   _   _   _	  \|
| [1] [2] [3] [4] [5] [6] [7] [8] [9] [0]	   |
|     _   _   _   _   _   _   _   _   _   _	   |
|    [Q] [W] [E] [R] [T] [Y] [U] [I] [O] [P]      /|
|	_   _	_   _	_   _	_   _	_   _____//|
|      [A] [S] [D] [F] [G] [H] [J] [K] [L] [ENTER]/|
|  _____   _   _   _   _   _   _   _   __   ___////|
| [SHIFT] [Z] [X] [C] [V] [B] [N] [M] [SS] [SPACE] |
|____________________________________________////__|
(__________________________________________________) */

#ifndef __Q_hardware_machine_model_computer_ZX_Spectrum_ZX_Spectrum_H__
#define __Q_hardware_machine_model_computer_ZX_Spectrum_ZX_Spectrum_H__

/* MARK: - Memory */

#define Q_ZX_SPECTRUM_ROM_SIZE		      (1024 * 16)
#define Q_ZX_SPECTRUM_16K_ISSUE_1_RAM_SIZE    (1024 * 16)
#define Q_ZX_SPECTRUM_16K_ISSUE_1_MEMORY_SIZE (1024 * (16 + 16))
#define Q_ZX_SPECTRUM_48K_ISSUE_2_RAM_SIZE    (1024 * 48)
#define Q_ZX_SPECTRUM_48K_ISSUE_2_MEMORY_SIZE (1024 * (16 + 48))
#define Q_ZX_SPECTRUM_48K_ISSUE_3_RAM_SIZE    (1024 * 48)
#define Q_ZX_SPECTRUM_48K_ISSUE_3_MEMORY_SIZE (1024 * (16 + 48))

/* MARK: - Screen
				     ---
       Invisible Top Border	      | 8
.---------------------------------.  ---   ---
|	Visible Top Border	  |   | 48  |
|----.-----------------------.----|  ---    |
|L   |			     |R   |   |     |
|e   |			     |i   |   |     |
|f  B|			     |g  B|   |     |
|t  o|	       Paper	     |h  o|   | 192 | 296
|   r|			     |t  r|   |     |
|   d|			     |   d|   |     |
|   e|			     |   e|   |     |
|   r|			     |   r|   |     |
|----'-----------------------'----|  ---    |
|	   Bottom Border	  |   | 56  |
'---------------------------------'  ---   ---

|----|-----------------------|----|
  48		256	       48
|---------------------------------|
		352			*/

#define Q_ZX_SPECTRUM_SCREEN_WIDTH			 352
#define Q_ZX_SPECTRUM_SCREEN_HEIGHT			 296
#define Q_ZX_SPECTRUM_SCREEN_PIXELS			 (352 * 296)
#define Q_ZX_SPECTRUM_SCREEN_PAPER_WIDTH		 256
#define Q_ZX_SPECTRUM_SCREEN_PAPER_HEIGHT		 192
#define Q_ZX_SPECTRUM_SCREEN_PAPER_PIXELS		 (256 * 192)
#define Q_ZX_SPECTRUM_SCREEN_TOP_BORDER_HEIGHT		 56
#define Q_ZX_SPECTRUM_SCREEN_INVISIBLE_TOP_BORDER_HEIGHT 8
#define Q_ZX_SPECTRUM_SCREEN_VISIBLE_TOP_BORDER_HEIGHT	 48
#define Q_ZX_SPECTRUM_SCREEN_BOTTOM_BORDER_HEIGHT	 56
#define Q_ZX_SPECTRUM_SCREEN_LEFT_BORDER_WIDTH		 48
#define Q_ZX_SPECTRUM_SCREEN_RIGHT_BORDER_WIDTH		 48

/* MARK: - Timmings */

#define Q_ZX_SPECTRUM_CPU_HZ				 3500000
#define Q_ZX_SPECTRUM_CYCLES_PER_FRAME			 69888
#define Q_ZX_SPECTRUM_CYCLES_PER_SCANLINE		 224
#define Q_ZX_SPECTRUM_CYCLES_PER_HBLANK			 48
#define Q_ZX_SPECTRUM_CYCLES_PER_VBLANK			 1792
#define Q_ZX_SPECTRUM_CYCLES_PER_TOP_BORDER_LINE	 176
#define Q_ZX_SPECTRUM_CYCLES_PER_LEFT_BORDER_LINE	 24
#define Q_ZX_SPECTRUM_CYCLES_PER_RIGHT_BORDER_LINE	 24
#define Q_ZX_SPECTRUM_CYCLES_PER_BOTTOM_BORDER_LINE	 176
#define Q_ZX_SPECTRUM_CYCLES_PER_PAPER_LINE		 128
#define Q_ZX_SPECTRUM_CYCLES_PER_INT			 32
#define Q_ZX_SPECTRUM_CYCLES_AT_VBLANK			 0
#define Q_ZX_SPECTRUM_CYCLES_AT_INT			 24
#define Q_ZX_SPECTRUM_CYCLES_AT_INVISIBLE_TOP_BORDER	 Q_ZX_SPECTRUM_CYCLES_PER_VBLANK

#define Q_ZX_SPECTRUM_CYCLES_AT_VISIBLE_TOP_BORDER	 (Q_ZX_SPECTRUM_CYCLES_AT_INVISIBLE_TOP_BORDER + \
							  Q_ZX_SPECTRUM_CYCLES_PER_SCANLINE	       * \
							  Q_ZX_SPECTRUM_SCREEN_INVISIBLE_TOP_BORDER_HEIGHT)

#define Q_ZX_SPECTRUM_CYCLES_AT_PAPER_REGION		(Q_ZX_SPECTRUM_CYCLES_AT_VISIBLE_TOP_BORDER + \
							 Q_ZX_SPECTRUM_CYCLES_PER_SCANLINE	    * \
							 Q_ZX_SPECTRUM_SCREEN_VISIBLE_TOP_BORDER_HEIGHT)

#define Q_ZX_SPECTRUM_CYCLES_AT_BOTTOM_BORDER		(Q_ZX_SPECTRUM_CYCLES_AT_PAPER_REGION + \
							 Q_ZX_SPECTRUM_CYCLES_PER_SCANLINE    * \
							 Q_ZX_SPECTRUM_SCREEN_PAPER_HEIGHT)

#define Q_ZX_SPECTRUM_CYCLES_AT_LINE(region, line)	(Q_ZX_SPECTRUM_CYCLES_AT_##region  + \
							 Q_ZX_SPECTRUM_CYCLES_PER_SCANLINE * line)

#endif /* __Q_hardware_machine_model_computer_ZX_Spectrum_ZX_Spectrum_H__ */
