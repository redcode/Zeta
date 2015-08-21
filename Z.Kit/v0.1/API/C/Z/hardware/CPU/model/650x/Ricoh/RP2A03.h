/* Z Kit C API - hardware/CPU/RP2A03.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_hardware_CPU_RP2A03_H__
#define __Z_hardware_CPU_RP2A03_H__

#include <Z/hardware/CPU/6502.h>

typedef Z6502State RP2A03State;

#define Z_RP2A03_STATE Z_6502_STATE

typedef Z6502Instruction ZRP2A03Instruction;

#define Z_RP2A03_ADDRESS_NMI_POINTER	Z_6502_ADDRESS_NMI_POINTER
#define Z_RP2A03_ADDRESS_RESET_POINTER	Z_6502_ADDRESS_RESET_POINTER
#define Z_RP2A03_ADDRESS_IRQ_POINTER	Z_6502_ADDRESS_IRQ_POINTER
#define Z_RP2A03_ADDRESS_STACK		Z_6502_ADDRESS_STACK

#endif /* __Z_hardware_CPU_RP2A03_H__ */
