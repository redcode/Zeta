/* Z Kit - hardware/machine/model/computer/ZX Spectrum/Inves Spectrum +.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.

.------------------------------------.
|   Vendor: Investronica	     |
| Released: 1986		     |
|      CPU: Zilog Z80-A @ 3.5469 MHz |
|      ROM: 48K			     |
|      RAM: 128K		     |
|    Sound: Internal speaker	     |
'------------------------------------'

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

#ifndef _Z_hardware_machine_model_ZX_Spectrum_Inves_Spectrum_Plus_H_
#define _Z_hardware_machine_model_ZX_Spectrum_Inves_Spectrum_Plus_H_

#define Z_INVES_SPECTRUM_PLUS_SIZE_MEMORY	    (1024 * 16 + 1024 * 48)
#define Z_INVES_SPECTRUM_PLUS_FIRMWARE_BASE_ADDRESS 0
#define Z_INVES_SPECTRUM_PLUS_SIZE_FIRMWARE	    (1024 * 16)

/* MARK: - Timmings */

#define Z_INVES_SPECTRUM_PLUS_MASTER_CLOCK_HZ 177345
#define Z_INVES_SPECTRUM_PLUS_CPU_HZ	      3546900

#endif /* _Z_hardware_machine_model_ZX_Spectrum_Inves_Spectrum_Plus_H_ */
