/* Z Kit C API - hardware/machine/model/computer/ZX Spectrum/Inves Spectrum +.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.

.----------------------------------------------.
|   Vendor: Investronica		       |
| Released: 1986			       |
|      CPU: Zilog Z80-A @ 3.5469 MHz	       |
|      ROM: 48K				       |
|      RAM: 128K			       |
|    Sound: General Instrument AY-3-8912 (PSG) |
'----------------------------------------------'

 _____________________________				  ___________
|    .	 _    _  __	      ''''''''''''''''''''''''''''	     |
| __/\__| |\/|/__\						     |
|--------------------------------------------------------------------|
|	 Spectrum +						     |
|--.-----------------------------------------------------.-----------|
|  |( )|( )|(1)|(2)|(3)|(4)|(5)|(6)|(7)|(1)|(1)|(1)|(BRK)|	     |
|--|-----------------------------------------------------|-----------|
|  |(DEL)|(1)|(Q)|(W)|(E)|(R)|(T)|(Y)|(U)|(I)|(O)|(P)|.-.|	     |
|--|-------------------------------------------------|| ||-----------|
|  |(EXT)|(ED)|(A)|(S)|(D)|(F)|(G)|(H)|(J)|(K)|(L)|(____'|	     |
|--|-----------------------------------------------------|-----------|
|  |(  /\  )|( )|(Z)|(X)|(C)|(V)|(B)|(N)|(M)|(.)|(  /\  )|	     |
|--|-----------------------------------------------------|-----------|
|  |( )|(;)|(")|(<)|(>)|(_______________)|(A)|(V)|(,)|(_)|	     |
|--'-----------------------------------------------------'-----------|
|____________________________________________________________________| */

#ifndef __Z_hardware_machine_model_ZX_Spectrum_Inves_Spectrum_Plus_H__
#define __Z_hardware_machine_model_ZX_Spectrum_Inves_Spectrum_Plus_H__

#define Z_INVES_SPECTRUM_PLUS_MEMORY_SIZE	    (1024 * 16 + 1024 * 48)
#define Z_INVES_SPECTRUM_PLUS_FIRMWARE_BASE_ADDRESS 0
#define Z_INVES_SPECTRUM_PLUS_FIRMWARE_SIZE	    (1024 * 16)

/* MARK: - Timmings */

#define Z_INVES_SPECTRUM_PLUS_MASTER_CLOCK_HZ 177345
#define Z_INVES_SPECTRUM_PLUS_CPU_HZ	      3546900

#endif /* __Z_hardware_machine_model_ZX_Spectrum_Inves_Spectrum_Plus_H__ */
