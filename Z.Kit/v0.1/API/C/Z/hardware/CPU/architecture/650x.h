/* Z Kit C API - hardware/CPU/architecture/650x.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
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

#ifndef __Z_hardware_CPU_architecture_650x_H__
#define __Z_hardware_CPU_architecture_650x_H__

#include <Z/keys/endianness.h>

/* MARK: - Addresses */

#define Z_6502_ADDRESS_NMI_POINTER   0xFFFA
#define Z_6502_ADDRESS_RESET_POINTER 0XFFFC
#define Z_6502_ADDRESS_IRQ_POINTER   0xFFFE
#define Z_6502_ADDRESS_BRK_POINTER   0xFFFE
#define Z_6502_ADDRESS_STACK	     0x0100

/* MARK: - Values after power on */

#define Z_6502_PC_VALUE_AFTER_POWER_ON 0x0000
#define Z_6502_S_VALUE_AFTER_POWER_ON  0x00
#define Z_6502_P_VALUE_AFTER_POWER_ON  0x00
#define Z_6502_A_VALUE_AFTER_POWER_ON  0x00
#define Z_6502_X_VALUE_AFTER_POWER_ON  0x00
#define Z_6502_Y_VALUE_AFTER_POWER_ON  0x00

/* MARK: - Values after reset */

#define Z_6502_PC_VALUE_AFTER_RESET Z_6502_PC_VALUE_AFTER_POWER_ON
#define Z_6502_S_VALUE_AFTER_RESET  Z_6502_S_VALUE_AFTER_POWER_ON
#define Z_6502_P_VALUE_AFTER_RESET  Z_6502_P_VALUE_AFTER_POWER_ON
#define Z_6502_A_VALUE_AFTER_RESET  Z_6502_A_VALUE_AFTER_POWER_ON
#define Z_6502_X_VALUE_AFTER_RESET  Z_6502_X_VALUE_AFTER_POWER_ON
#define Z_6502_Y_VALUE_AFTER_RESET  Z_6502_Y_VALUE_AFTER_POWER_ON

/* MARK: - Information for emulation */

#define Z_6502_POWER_ON_IS_EQUAL_TO_RESET TRUE

#endif /* __Z_hardware_CPU_architecture_650x_H__ */

#ifdef Z_INSPECTING_CPU_ARCHITECTURE

#	ifndef __Z_hardware_CPU_architecture_650x_H__INSPECTION
#	define __Z_hardware_CPU_architecture_650x_H__INSPECTION

#	define Z_INSERT_CPU_ARCHITECTURE(left, right) left##650X##right
#	define Z_INSERT_CPUArchitecture( left, right) left##650x##right
#	define Z_INSERT_cpu_architecture Z_INSERT_CPUArchitecture

#	define Z_IS_DEFINED_INSERT_CPU_ARCHITECTURE(left, right) \
		(defined left##650X##right)

#	endif /* __Z_hardware_CPU_architecture_650x_H__INSPECTION */

#else

#	ifndef __Z_hardware_CPU_architecture_650x_H__NO_INSPECTION
#	define __Z_hardware_CPU_architecture_650x_H__NO_INSPECTION

#	include <Z/types/base.h>

	/* MARK: - State storage type */

	typedef struct {
		zuint16	pc;
		zuint8	s, p, a, x, y;
	} Z6502State;

	/* MARK: - State structure macros */

#	define Z_6502_STATE_PC(object) (object)->pc
#	define Z_6502_STATE_S( object) (object)->s
#	define Z_6502_STATE_P( object) (object)->p
#	define Z_6502_STATE_A( object) (object)->a
#	define Z_6502_STATE_X( object) (object)->x
#	define Z_6502_STATE_Y( object) (object)->y

#	define Z_6502_STATE_MEMBER_PC pc
#	define Z_6502_STATE_MEMBER_S  s
#	define Z_6502_STATE_MEMBER_P  p
#	define Z_6502_STATE_MEMBER_A  a
#	define Z_6502_STATE_MEMBER_X  x
#	define Z_6502_STATE_MEMBER_Y  y

#	endif /* __Z_hardware_CPU_architecture_650x_H__NO_INSPECTION */

#endif
