/* Z Kit - hardware/CPU/architecture/6502.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
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

#ifndef _Z_hardware_CPU_architecture_6502_H_
#define _Z_hardware_CPU_architecture_6502_H_

#include <Z/types/base.h>

/* MARK: - Addresses */

#define Z_6502_ADDRESS_NMI_POINTER   0xFFFA
#define Z_6502_ADDRESS_RESET_POINTER 0XFFFC
#define Z_6502_ADDRESS_IRQ_POINTER   0xFFFE
#define Z_6502_ADDRESS_BRK_POINTER   0xFFFE
#define Z_6502_ADDRESS_STACK	     0x0100

/* MARK: - Values after power on */

#define Z_6502_VALUE_AFTER_POWER_ON_PC 0x0000
#define Z_6502_VALUE_AFTER_POWER_ON_S  0xFD
#define Z_6502_VALUE_AFTER_POWER_ON_P  0x36
#define Z_6502_VALUE_AFTER_POWER_ON_A  0x00
#define Z_6502_VALUE_AFTER_POWER_ON_X  0x00
#define Z_6502_VALUE_AFTER_POWER_ON_Y  0x00

/* MARK: - State storage type */

Z_DEFINE_STRICT_STRUCTURE_BEGIN
	zuint16 pc;
	zuint8	s, p, a, x, y;

	struct {zuint8 irq :1;
		zuint8 nmi :1;
	} internal;
Z_DEFINE_STRICT_STRUCTURE_END Z6502State;

#define Z_6502_STATE_PC( object) (object)->pc
#define Z_6502_STATE_S(	 object) (object)->s
#define Z_6502_STATE_P(	 object) (object)->p
#define Z_6502_STATE_A(	 object) (object)->a
#define Z_6502_STATE_X(	 object) (object)->x
#define Z_6502_STATE_Y(	 object) (object)->y
#define Z_6502_STATE_NMI(object) (object)->internal.nmi
#define Z_6502_STATE_IRQ(object) (object)->internal.irq

#define Z_6502_STATE_MEMBER_PC	pc
#define Z_6502_STATE_MEMBER_S	s
#define Z_6502_STATE_MEMBER_P	p
#define Z_6502_STATE_MEMBER_A	a
#define Z_6502_STATE_MEMBER_X	x
#define Z_6502_STATE_MEMBER_Y	y
#define Z_6502_STATE_MEMBER_NMI internal.nmi
#define Z_6502_STATE_MEMBER_IRQ internal.irq

#endif /* _Z_hardware_CPU_architecture_6502_H_ */
