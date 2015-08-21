/* Z Kit C API - hardware/CPU/architecture/650x.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.

	 .----._.----.
 Vss -01-|    \_/    |-40- RES
 RDY -02-|	     |-39-
     -03-|     _     |-38-
 IRQ -04-|    (_)    |-37-
     -05-|	     |-36-
 NMI -06-|	     |-35-
SYNC -07-|	     |-34-
 Vcc -08-|	     |-33- D0
  A0 -09-|	     |-32- D1
  A1 -10-|	     |-31- D2
  A2 -11-|    6502   |-30- D3
  A3 -12-|	     |-29- D4
  A4 -13-|	     |-28- D5
  A5 -14-|	     |-27- D6
  A6 -15-|	     |-26- D7
  A7 -16-|     _     |-25- A15
  A8 -17-|    (_)    |-24- A14
  A9 -18-|	     |-23- A13
 A10 -19-|	     |-22- A12
 A11 -20-|	     |-21- Vss
	 '-----------'

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

Status (P register)
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

#ifdef Z_INSPECTING_CPU_ARCHITECTURE

#else

#	include <Z/types/base.h>

	/* MARK: - State storage type */

	typedef struct {
		zuint16	pc;
		zuint8	s, p, a, x, y;
	} Z6502State;

#	define Z_6502_STATE(p) ((Z6502State *)(p))

#	define Z_6502_STATE_PC(object) (object)->pc
#	define Z_6502_STATE_S( object) (object)->s
#	define Z_6502_STATE_P( object) (object)->p
#	define Z_6502_STATE_A( object) (object)->a
#	define Z_6502_STATE_X( object) (object)->x
#	define Z_6502_STATE_Y( object) (object)->y

#	define Z_6502_STATE_MEMBER_PC  pc
#	define Z_6502_STATE_MEMBER_S   s
#	define Z_6502_STATE_MEMBER_P   p
#	define Z_6502_STATE_MEMBER_A   a
#	define Z_6502_STATE_MEMBER_X   x
#	define Z_6502_STATE_MEMBER_Y   y

#endif

/* MARK: - Addresses */

#define Z_6502_ADDRESS_NMI_POINTER	0xFFFA
#define Z_6502_ADDRESS_RESET_POINTER	0XFFFC
#define Z_6502_ADDRESS_IRQ_POINTER	0xFFFE
#define Z_6502_ADDRESS_BRK_POINTER	0xFFFE
#define Z_6502_ADDRESS_STACK		0x0100

/* MARK: - Values after power on */

#define Z_6502_PC_VALUE_AFTER_POWER_ON	0x0000
#define Z_6502_S_VALUE_AFTER_POWER_ON	0x00
#define Z_6502_P_VALUE_AFTER_POWER_ON	0x00
#define Z_6502_A_VALUE_AFTER_POWER_ON	0x00
#define Z_6502_X_VALUE_AFTER_POWER_ON	0x00
#define Z_6502_Y_VALUE_AFTER_POWER_ON	0x00

/* MARK: - Values after reset */

#define Z_6502_PC_VALUE_AFTER_RESET	Z_6502_PC_VALUE_AFTER_POWER_ON
#define Z_6502_S_VALUE_AFTER_RESET	Z_6502_S_VALUE_AFTER_POWER_ON
#define Z_6502_P_VALUE_AFTER_RESET	Z_6502_P_VALUE_AFTER_POWER_ON
#define Z_6502_A_VALUE_AFTER_RESET	Z_6502_A_VALUE_AFTER_POWER_ON
#define Z_6502_X_VALUE_AFTER_RESET	Z_6502_X_VALUE_AFTER_POWER_ON
#define Z_6502_Y_VALUE_AFTER_RESET	Z_6502_Y_VALUE_AFTER_POWER_ON

/* MARK: - Information for emulation */

#define Z_6502_POWER_ON_IS_EQUAL_TO_RESET TRUE

#endif /* __Z_hardware_CPU_architecture_650x_H__ */
