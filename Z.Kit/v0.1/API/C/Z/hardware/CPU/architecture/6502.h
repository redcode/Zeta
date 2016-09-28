/* Z Kit C API - hardware/CPU/architecture/6502.h
	      ___
 _____	____ /	/______
/_   /_/  -_)  __/  _ /
 /____/\___/\__/ \__,_/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.

Registers:
.-----------------------------------.
| F E D C B A 9 8 | 7 6 5 4 3 2 1 0 |
|-----------------------------------|
|		 PC		    | Program Counter
'-----------------------------------|
		  |	   S	    | Stack Pointer
		  |-----------------|
		  |	   P	    | Program Status (flags)
		  |-----------------|
		  |	   A	    | Accumulator
		  |-----------------|
		  |	   X	    | X Index
		  |-----------------|
		  |	   Y	    | Y Index
		  '-----------------'

Status (P register):
.-----------------.
| 7 6 5 4 3 2 1 0 |
| N V - B D I Z C |
'-|-|-|-|-|-|-|-|-'
  | | | | | | | '-> carry
  | | | | | | '---> zero
  | | | | | '-----> interrupt (IRQ disable)
  | | | | '-------> decimal (use BCD for arithmetics)
  | | | '---------> break
  | | '-----------> (ignored)
  | '-------------> overflow
  '---------------> negative */

#ifndef __Z_hardware_CPU_architecture_6502_H__
#define __Z_hardware_CPU_architecture_6502_H__

#include <Z/types/base.h>

/* MARK: - Addresses */

#define Z_6502_ADDRESS_NMI_POINTER   0xFFFA
#define Z_6502_ADDRESS_RESET_POINTER 0XFFFC
#define Z_6502_ADDRESS_IRQ_POINTER   0xFFFE
#define Z_6502_ADDRESS_BRK_POINTER   0xFFFE
#define Z_6502_ADDRESS_STACK	     0x0100

/* MARK: - Values after power on */

#define Z_6502_PC_VALUE_AFTER_POWER_ON 0x0000
#define Z_6502_S_VALUE_AFTER_POWER_ON  0xFD
#define Z_6502_P_VALUE_AFTER_POWER_ON  0x36
#define Z_6502_A_VALUE_AFTER_POWER_ON  0x00
#define Z_6502_X_VALUE_AFTER_POWER_ON  0x00
#define Z_6502_Y_VALUE_AFTER_POWER_ON  0x00

/* MARK: - State storage type */

typedef struct {
	zuint16	pc;
	zuint8	s, p, a, x, y;
} Z6502State;

/* MARK: - State structure macros */

#define Z_6502_STATE_PC(object) (object)->pc
#define Z_6502_STATE_S( object) (object)->s
#define Z_6502_STATE_P( object) (object)->p
#define Z_6502_STATE_A( object) (object)->a
#define Z_6502_STATE_X( object) (object)->x
#define Z_6502_STATE_Y( object) (object)->y

#define Z_6502_STATE_MEMBER_PC pc
#define Z_6502_STATE_MEMBER_S  s
#define Z_6502_STATE_MEMBER_P  p
#define Z_6502_STATE_MEMBER_A  a
#define Z_6502_STATE_MEMBER_X  x
#define Z_6502_STATE_MEMBER_Y  y

#endif /* __Z_hardware_CPU_architecture_6502_H__ */
