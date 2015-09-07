/* Z Kit C API - hardware/machine/model/computer/ZX Spectrum/ZX Spectrum +.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.
 ________________________________
/\				 \
\_| Vendor:   Sinclair Research   |
  | Released: 1984-10		  |
  | CPU:      Zilog Z80 @ 3.5 MHz |
  | ROM:      16K		  |
  | RAM:      48K		  |
  | Sound:    Internal speaker	  |
  |   ____________________________|_
   \_/_____________________________/

 ____________________________				  ___________
|  ___. __  _	  __ . __    '''''''''''''''''''''''''''''	     |
| __\ ||  ||__|__|--|||						     |
|--------------------------------------------------------------------|
| ZX Spectrum +							     |
|--.-----------------------------------------------------.-----------|
|  |( )|( )|(1)|(2)|(3)|(4)|(5)|(6)|(7)|(1)|(1)|(1)|(BRK)|	     |
|--|-----------------------------------------------------|-----------|
|  |(DEL)|(1)|(Q)|(W)|(E)|(R)|(T)|(Y)|(U)|(I)|(O)|(P)|.-.|	     |
|--|-------------------------------------------------|| ||-----------|
|  |(EXT)|(ED)|(A)|(S)|(D)|(F)|(G)|(H)|(J)|(K)|(L)|(____'|	     |
|--|-----------------------------------------------------|-----------|
|  |(CAPS S)|( )|(Z)|(X)|(C)|(V)|(B)|(N)|(M)|(.)|(CAPS S)|	     |
|--|-----------------------------------------------------|-----------|
|  |( )|(;)|(")|(_)|(_)|(_______________)|(_)|(_)|(,)|(_)|	//// |
|--'-----------------------------------------------------'-----------|
|____________________________________________________________________| */

#ifndef __Z_hardware_machine_model_computer_ZX_Spectrum_ZX_Spectrum_Plus_H__
#define __Z_hardware_machine_model_computer_ZX_Spectrum_ZX_Spectrum_Plus_H__

/* MARK: - Memory */

#define Z_ZX_SPECTRUM_PLUS_RAM_SIZE    (1024 * 48)
#define Z_ZX_SPECTRUM_PLUS_ROM_SIZE    Z_ZX_SPECTRUM_ROM_SIZE
#define Z_ZX_SPECTRUM_PLUS_MEMORY_SIZE (1024 * (16 + 48))

/* MARK: - Screen */

#define Z_ZX_SPECTRUM_PLUS_SCREEN_FPS			      Z_ZX_SPECTRUM_SCREEN_FPS
#define Z_ZX_SPECTRUM_PLUS_SCREEN_WIDTH			      Z_ZX_SPECTRUM_SCREEN_WIDTH
#define Z_ZX_SPECTRUM_PLUS_SCREEN_HEIGHT		      Z_ZX_SPECTRUM_SCREEN_HEIGHT
#define Z_ZX_SPECTRUM_PLUS_SCREEN_PIXELS		      Z_ZX_SPECTRUM_SCREEN_PIXELS
#define Z_ZX_SPECTRUM_PLUS_SCREEN_PAPER_WIDTH		      Z_ZX_SPECTRUM_SCREEN_PAPER_WIDTH
#define Z_ZX_SPECTRUM_PLUS_SCREEN_PAPER_HEIGHT		      Z_ZX_SPECTRUM_SCREEN_PAPER_HEIGHT
#define Z_ZX_SPECTRUM_PLUS_SCREEN_PAPER_PIXELS		      Z_ZX_SPECTRUM_SCREEN_PAPER_PIXELS
#define Z_ZX_SPECTRUM_PLUS_SCREEN_TOP_BORDER_HEIGHT	      Z_ZX_SPECTRUM_SCREEN_TOP_BORDER_HEIGHT
#define Z_ZX_SPECTRUM_PLUS_SCREEN_INVISIBLE_TOP_BORDER_HEIGHT Z_ZX_SPECTRUM_SCREEN_INVISIBLE_TOP_BORDER_HEIGHT
#define Z_ZX_SPECTRUM_PLUS_SCREEN_VISIBLE_TOP_BORDER_HEIGHT   Z_ZX_SPECTRUM_SCREEN_VISIBLE_TOP_BORDER_HEIGHT
#define Z_ZX_SPECTRUM_PLUS_SCREEN_BOTTOM_BORDER_HEIGHT	      Z_ZX_SPECTRUM_SCREEN_BOTTOM_BORDER_HEIGHT
#define Z_ZX_SPECTRUM_PLUS_SCREEN_LEFT_BORDER_WIDTH	      Z_ZX_SPECTRUM_SCREEN_LEFT_BORDER_WIDTH
#define Z_ZX_SPECTRUM_PLUS_SCREEN_RIGHT_BORDER_WIDTH	      Z_ZX_SPECTRUM_SCREEN_RIGHT_BORDER_WIDTH

/* MARK: - Timmings */

#define Z_ZX_SPECTRUM_PLUS_Z80_HZ			  Z_ZX_SPECTRUM_Z80_HZ
#define Z_ZX_SPECTRUM_PLUS_CYCLES_PER_FRAME		  Z_ZX_SPECTRUM_CYCLES_PER_FRAME
#define Z_ZX_SPECTRUM_PLUS_CYCLES_PER_SCANLINE		  Z_ZX_SPECTRUM_CYCLES_PER_SCANLINE
#define Z_ZX_SPECTRUM_PLUS_CYCLES_PER_HBLANK		  Z_ZX_SPECTRUM_CYCLES_PER_HBLANK
#define Z_ZX_SPECTRUM_PLUS_CYCLES_PER_VBLANK		  Z_ZX_SPECTRUM_CYCLES_PER_VBLANK
#define Z_ZX_SPECTRUM_PLUS_CYCLES_PER_TOP_BORDER_LINE	  Z_ZX_SPECTRUM_CYCLES_PER_TOP_BORDER_LINE
#define Z_ZX_SPECTRUM_PLUS_CYCLES_PER_LEFT_BORDER_LINE	  Z_ZX_SPECTRUM_CYCLES_PER_LEFT_BORDER_LINE
#define Z_ZX_SPECTRUM_PLUS_CYCLES_PER_RIGHT_BORDER_LINE	  Z_ZX_SPECTRUM_CYCLES_PER_RIGHT_BORDER_LINE
#define Z_ZX_SPECTRUM_PLUS_CYCLES_PER_BOTTOM_BORDER_LINE  Z_ZX_SPECTRUM_CYCLES_PER_BOTTOM_BORDER_LINE
#define Z_ZX_SPECTRUM_PLUS_CYCLES_PER_PAPER_LINE	  Z_ZX_SPECTRUM_CYCLES_PER_PAPER_LINE
#define Z_ZX_SPECTRUM_PLUS_CYCLES_PER_INT		  Z_ZX_SPECTRUM_CYCLES_PER_INT
#define Z_ZX_SPECTRUM_PLUS_CYCLES_AT_VBLANK		  Z_ZX_SPECTRUM_CYCLES_AT_VBLANK
#define Z_ZX_SPECTRUM_PLUS_CYCLES_AT_INT		  Z_ZX_SPECTRUM_CYCLES_AT_INT
#define Z_ZX_SPECTRUM_PLUS_CYCLES_AT_INVISIBLE_TOP_BORDER Z_ZX_SPECTRUM_CYCLES_AT_INVISIBLE_TOP_BORDER
#define Z_ZX_SPECTRUM_PLUS_CYCLES_AT_VISIBLE_TOP_BORDER	  Z_ZX_SPECTRUM_CYCLES_AT_VISIBLE_TOP_BORDER
#define Z_ZX_SPECTRUM_PLUS_CYCLES_AT_PAPER_REGION	  Z_ZX_SPECTRUM_CYCLES_AT_PAPER_REGION
#define Z_ZX_SPECTRUM_PLUS_CYCLES_AT_BOTTOM_BORDER	  Z_ZX_SPECTRUM_CYCLES_AT_BOTTOM_BORDER
#define Z_ZX_SPECTRUM_PLUS_CYCLES_AT_LINE		  Z_ZX_SPECTRUM_CYCLES_AT_LINE

#endif /* __Z_hardware_machine_model_computer_ZX_Spectrum_ZX_Spectrum_Plus_H__ */
