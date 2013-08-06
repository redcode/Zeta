/* Q API - hardware/machine/model/computer/ZX Spectrum/ZX Spectrum + 128K.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2009 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3.

   .-----------------------------............................-----------.====.
   |  ___. __  __    __ . __						|====|
   | __\ ||  ||__|__|--|||						|====|
   |--------------------------------------------------------------------|====|
   | ZX Spectrum +							|====|
   |--.-----------------------------------------------------.-----------|====|
   |  |( )|( )|(1)|(2)|(3)|(4)|(5)|(6)|(7)|(1)|(1)|(1)|(BRK)|		|====|
   |--|-----------------------------------------------------|-----------|====|
   |  |(DEL)|(1)|(Q)|(W)|(E)|(R)|(T)|(Y)|(U)|(I)|(O)|(P)|.-.|		|====|
   |--|-------------------------------------------------|| ||-----------|====|
   |  |(EXT)|(ED)|(A)|(S)|(D)|(F)|(G)|(H)|(J)|(K)|(L)|(____'|		|====|
   |--|-----------------------------------------------------|-----------|====|
   |  |(CAPS S)|( )|(Z)|(X)|(C)|(V)|(B)|(N)|(M)|(.)|(CAPS S)|		|====|
   |--|-----------------------------------------------------|-----------|====|
   |  |( )|(;)|(")|(_)|(_)|(_______________)|(_)|(_)|(,)|(_)|  128K//// |====|
   |--'-----------------------------------------------------'-----------|====|
   |									|====|
   '--------------------------------------------------------------------'===='

	 Vendor: Sinclair Research - Investronica
   Release date: 1985
	    CPU: Zilog Z80 @ 3.5469 MHz
	    ROM: 48K
	    RAM: 128K
	  Sound: General Instrument AY-3-8912 */

#ifndef __Q_hardware_machine_model_computer_ZX_Spectrum_ZX_Spectrum_Plus_128K_H__
#define __Q_hardware_machine_model_computer_ZX_Spectrum_ZX_Spectrum_Plus_128K_H__

#include <Q/hardware/machine/model/computer/ZX Spectrum/ZX Spectrum.h>

/* MARK: - Screen */

/*					---
	  Invisible Top Border		 | 7
   .---------------------------------.  ---   ---
   |	   Visible Top Border	     |	 | 48  |
   |----.-----------------------.----|  ---    |
   |L   |			|R   |	 |     |
   |e   |			|i   |	 |     |
   |f  B|			|g  B|	 |     |
   |t  o|	  Paper		|h  o|   | 192 | 296
   |   r|			|t  r|	 |     |
   |   d|			|   d|	 |     |
   |   e|			|   e|	 |     |
   |   r|			|   r|	 |     |
   |----'-----------------------'----|  ---    |
   |	      Bottom Border	     |	 | 56  |
   '---------------------------------'  ---   ---

   |----|-----------------------|----|
     48		   256		  48
   |---------------------------------|
		   352			*/

#define Q_ZX_SPECTRUM_PLUS_128K_SCREEN_WIDTH				Q_ZX_SPECTRUM_SCREEN_WIDTH
#define Q_ZX_SPECTRUM_PLUS_128K_SCREEN_HEIGHT				Q_ZX_SPECTRUM_SCREEN_HEIGHT
#define Q_ZX_SPECTRUM_PLUS_128K_SCREEN_PIXELS				Q_ZX_SPECTRUM_SCREEN_PIXELS
#define Q_ZX_SPECTRUM_PLUS_128K_SCREEN_PAPER_WIDTH			Q_ZX_SPECTRUM_SCREEN_PAPER_WIDTH
#define Q_ZX_SPECTRUM_PLUS_128K_SCREEN_PAPER_HEIGHT			Q_ZX_SPECTRUM_SCREEN_PAPER_HEIGHT
#define Q_ZX_SPECTRUM_PLUS_128K_SCREEN_PAPER_PIXELS			Q_ZX_SPECTRUM_SCREEN_PAPER_PIXELS
#define Q_ZX_SPECTRUM_PLUS_128K_SCREEN_TOP_BORDER_HEIGHT		55
#define Q_ZX_SPECTRUM_PLUS_128K_SCREEN_INVISIBLE_TOP_BORDER_HEIGHT	7
#define Q_ZX_SPECTRUM_PLUS_128K_SCREEN_VISIBLE_TOP_BORDER_HEIGHT	Q_ZX_SPECTRUM_SCREEN_VISIBLE_TOP_BORDER_HEIGHT
#define Q_ZX_SPECTRUM_PLUS_128K_SCREEN_BOTTOM_BORDER_HEIGHT		Q_ZX_SPECTRUM_SCREEN_BOTTOM_BORDER_HEIGHT
#define Q_ZX_SPECTRUM_PLUS_128K_SCREEN_LEFT_BORDER_WIDTH		Q_ZX_SPECTRUM_SCREEN_LEFT_BORDER_WIDTH
#define Q_ZX_SPECTRUM_PLUS_128K_SCREEN_RIGHT_BORDER_WIDTH		Q_ZX_SPECTRUM_SCREEN_RIGHT_BORDER_WIDTH

/* MARK: - Timmings */

#define Q_ZX_SPECTRUM_PLUS_128K_Z80_HZ				3546900
#define Q_ZX_SPECTRUM_PLUS_128K_PSG_HZ				1773400
#define Q_ZX_SPECTRUM_PLUS_128K_CYCLES_PER_FRAME		70908
#define Q_ZX_SPECTRUM_PLUS_128K_CYCLES_PER_SCANLINE		228
#define Q_ZX_SPECTRUM_PLUS_128K_CYCLES_PER_HBLANK		52
#define Q_ZX_SPECTRUM_PLUS_128K_CYCLES_PER_VBLANK		1824
#define Q_ZX_SPECTRUM_PLUS_128K_CYCLES_PER_TOP_BORDER_LINE	Q_ZX_SPECTRUM_CYCLES_PER_TOP_BORDER_LINE
#define Q_ZX_SPECTRUM_PLUS_128K_CYCLES_PER_LEFT_BORDER_LINE	Q_ZX_SPECTRUM_CYCLES_PER_LEFT_BORDER_LINE
#define Q_ZX_SPECTRUM_PLUS_128K_CYCLES_PER_RIGHT_BORDER_LINE	Q_ZX_SPECTRUM_CYCLES_PER_RIGHT_BORDER_LINE
#define Q_ZX_SPECTRUM_PLUS_128K_CYCLES_PER_BOTTOM_BORDER_LINE	Q_ZX_SPECTRUM_CYCLES_PER_BOTTOM_BORDER_LINE
#define Q_ZX_SPECTRUM_PLUS_128K_CYCLES_PER_PAPER_LINE		Q_ZX_SPECTRUM_CYCLES_PER_PAPER_LINE
#define Q_ZX_SPECTRUM_PLUS_128K_CYCLES_PER_INT			Q_ZX_SPECTRUM_CYCLES_PER_INT
#define Q_ZX_SPECTRUM_PLUS_128K_CYCLES_AT_VBLANK		Q_ZX_SPECTRUM_CYCLES_AT_VBLANK
#define Q_ZX_SPECTRUM_PLUS_128K_CYCLES_AT_INT			Q_ZX_SPECTRUM_CYCLES_AT_INT
#define Q_ZX_SPECTRUM_PLUS_128K_CYCLES_AT_INVISIBLE_TOP_BORDER	Q_ZX_SPECTRUM_PLUS_128K_CYCLES_PER_VBLANK

#define Q_ZX_SPECTRUM_PLUS_128K_CYCLES_AT_VISIBLE_TOP_BORDER	(Q_ZX_SPECTRUM_PLUS_128K_CYCLES_AT_INVISIBLE_TOP_BORDER	  + \
								 Q_ZX_SPECTRUM_PLUS_128K_CYCLES_PER_SCANLINE		  * \
								 Q_ZX_SPECTRUM_PLUS_128K_SCREEN_INVISIBLE_TOP_BORDER_HEIGHT)

#define Q_ZX_SPECTRUM_PLUS_128K_CYCLES_AT_PAPER_REGION		(Q_ZX_SPECTRUM_PLUS_128K_CYCLES_AT_VISIBLE_TOP_BORDER	+ \
								 Q_ZX_SPECTRUM_PLUS_128K_CYCLES_PER_SCANLINE		* \
								 Q_ZX_SPECTRUM_PLUS_128K_SCREEN_VISIBLE_TOP_BORDER_HEIGHT)

#define Q_ZX_SPECTRUM_PLUS_128K_CYCLES_AT_BOTTOM_BORDER		(Q_ZX_SPECTRUM_PLUS_128K_CYCLES_AT_PAPER_REGION + \
								 Q_ZX_SPECTRUM_PLUS_128K_CYCLES_PER_SCANLINE    * \
								 Q_ZX_SPECTRUM_PLUS_128K_SCREEN_PAPER_HEIGHT)

#define Q_ZX_SPECTRUM_PLUS_128K_CYCLES_AT_LINE(region, line)	(Q_ZX_SPECTRUM_PLUS_128K_CYCLES_AT_##region  + \
								 Q_ZX_SPECTRUM_PLUS_128K_CYCLES_PER_SCANLINE * line)

/* MARK: - Memory */

#define Q_ZX_SPECTRUM_PLUS_128K_ROM_SIZE	(1024 *	 32)
#define Q_ZX_SPECTRUM_PLUS_128K_RAM_SIZE	(1024 * 128)
#define Q_ZX_SPECTRUM_MEMORY_SIZE		(Q_ZX_SPECTRUM_16K_ISSUE_1_ROM_SIZE + Q_ZX_SPECTRUM_16K_ISSUE_1_RAM_SIZE)
#define Q_ZX_SPECTRUM_FIRMWARE_SIZE		(1024 *  32)
#define Q_ZX_SPECTRUM_FIRMWARE_BASE_ADDRESS	0x0000


/* MARK: - I/O Ports */

/* 7FFD - Memory bank switching
   .-----------------.
   | 7 6 5 4 3 2 1 0 |
   '-\_/-|-|-|-\___/-'
      |  | | |	 '---> user (C000h)
      |  | | '-------> VRAM
      |  | '---------> ROM
      |  '-----------> disable
      '--------------> unused	*/

typedef Q_STRICT_8BIT_FIELD (
	quint8 unused	:2,
	quint8 disable	:1,
	quint8 rom	:1,
	quint8 vram	:1,
	quint8 user	:3
) QZXSpectrumPlus128KMemoryBankSwitch;

#endif /* __Q_hardware_machine_model_computer_ZX_Spectrum_ZX_Spectrum_Plus_128K_H__ */
