/* Q Kit C API - hardware/CPU/RP2A03.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_hardware_CPU_RP2A03_H__
#define __Q_hardware_CPU_RP2A03_H__

#include <Q/hardware/CPU/6502.h>

typedef Q6502State RP2A03State;

#define Q_RP2A03_STATE Q_6502_STATE

typedef Q6502Instruction QRP2A03Instruction;

#define Q_RP2A03_ADDRESS_NMI_POINTER	Q_6502_ADDRESS_NMI_POINTER
#define Q_RP2A03_ADDRESS_RESET_POINTER	Q_6502_ADDRESS_RESET_POINTER
#define Q_RP2A03_ADDRESS_IRQ_POINTER	Q_6502_ADDRESS_IRQ_POINTER
#define Q_RP2A03_ADDRESS_STACK		Q_6502_ADDRESS_STACK

#endif /* __Q_hardware_CPU_RP2A03_H__ */
