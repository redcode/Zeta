/* Z Kit - hardware/CPU/architecture/Z80.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.

Registers:
.-----------------------------------.
| F E D C B A 9 8 | 7 6 5 4 3 2 1 0 |
|-----------------------------------|
|		 PC		    |
|-----------------------------------|
|		 SP		    |
|-----------------------------------|
|	 A	 AF	   F	    |
|-----------------------------------|
|	 B	 BC	   C	    |
|-----------------------------------|
|	 D	 DE	   E	    |
|-----------------------------------|
|	 H	 HL	   L	    |
|-----------------------------------|
|	IXH	 IX	  IXL	    |
|-----------------------------------|
|	IYH	 IY	  IYL	    |
|-----------------------------------|
|		 AF'		    |
|-----------------------------------|
|		 BC'		    |
|-----------------------------------|
|		 DE'		    |
|-----------------------------------|
|		 HL'		    |
'-----------------------------------|
		  |	   I	    |
		  |-----------------|
		  |	   R	    |
		  '-----------------'

Flags (F register):
.-----------------.
| 7 6 5 4 3 2 1 0 |
| S Z Y H X P N C |
'-|-|-|-|-|-|-|-|-'
  | | | | | | | '-> carry
  | | | | | | '---> addition / subtraction
  | | | | | '-----> parity / 2-compliment signed overflow
  | | | | '-------> result bit 3 copy (undocumented)
  | | | '---------> half carry
  | | '-----------> result bit 5 copy (undocumented)
  | '-------------> zero
  '---------------> sign */

#ifndef _Z_hardware_CPU_architecture_Z80_H_
#define _Z_hardware_CPU_architecture_Z80_H_

#include <Z/types/base.h>

/* MARK: - Limits and features */

#define Z_Z80_MINIMUM_CYCLES_PER_INSTRUCTION 4
#define Z_Z80_MAXIMUM_CYCLES_PER_INSTRUCTION 23
#define Z_Z80_MINIMUM_BITS_INSTRUCTION	     8
#define Z_Z80_MAXIMUM_BITS_INSTRUCTION	     32
#define Z_Z80_BITS_ADDRESS_BUS		     16
#define Z_Z80_BITS_DATA_BUS		     8
#define Z_Z80_BITS_ADDRESSING		     16

/* MARK: - Addresses */

#define Z_Z80_ADDRESS_NMI_POINTER 0x0066

/* MARK: - Values after power on */
/*
#define Z_Z80_VALUE_AFTER_POWER_ON_PC	  0x0000
#define Z_Z80_VALUE_AFTER_POWER_ON_SP	  0x0000
#define Z_Z80_VALUE_AFTER_POWER_ON_AF	  0x0040
#define Z_Z80_VALUE_AFTER_POWER_ON_BC	  0x0000
#define Z_Z80_VALUE_AFTER_POWER_ON_DE	  0x0000
#define Z_Z80_VALUE_AFTER_POWER_ON_HL	  0x0000
#define Z_Z80_VALUE_AFTER_POWER_ON_IX	  0x0000
#define Z_Z80_VALUE_AFTER_POWER_ON_IY	  0xFFFF
#define Z_Z80_VALUE_AFTER_POWER_ON_AF_	  0x0000
#define Z_Z80_VALUE_AFTER_POWER_ON_BC_	  0x0000
#define Z_Z80_VALUE_AFTER_POWER_ON_DE_	  0x0000
#define Z_Z80_VALUE_AFTER_POWER_ON_HL_	  0x0000
#define Z_Z80_VALUE_AFTER_POWER_ON_I	  0x00
#define Z_Z80_VALUE_AFTER_POWER_ON_R	  0x00
#define Z_Z80_VALUE_AFTER_POWER_ON_MEMPTR 0x0000
#define Z_Z80_VALUE_AFTER_POWER_ON_IFF1	  0
#define Z_Z80_VALUE_AFTER_POWER_ON_IFF2	  0
#define Z_Z80_VALUE_AFTER_POWER_ON_IM	  1*/

#define Z_Z80_VALUE_AFTER_POWER_ON_PC	  0x0000
#define Z_Z80_VALUE_AFTER_POWER_ON_SP	  0xFFFF
#define Z_Z80_VALUE_AFTER_POWER_ON_AF	  0xFFFF
#define Z_Z80_VALUE_AFTER_POWER_ON_BC	  0xFFFF
#define Z_Z80_VALUE_AFTER_POWER_ON_DE	  0xFFFF
#define Z_Z80_VALUE_AFTER_POWER_ON_HL	  0xFFFF
#define Z_Z80_VALUE_AFTER_POWER_ON_IX	  0xFFFF
#define Z_Z80_VALUE_AFTER_POWER_ON_IY	  0xFFFF
#define Z_Z80_VALUE_AFTER_POWER_ON_AF_	  0xFFFF
#define Z_Z80_VALUE_AFTER_POWER_ON_BC_	  0xFFFF
#define Z_Z80_VALUE_AFTER_POWER_ON_DE_	  0xFFFF
#define Z_Z80_VALUE_AFTER_POWER_ON_HL_	  0xFFFF
#define Z_Z80_VALUE_AFTER_POWER_ON_I	  0x00
#define Z_Z80_VALUE_AFTER_POWER_ON_R	  0x00
#define Z_Z80_VALUE_AFTER_POWER_ON_MEMPTR 0x0000
#define Z_Z80_VALUE_AFTER_POWER_ON_IFF1	  0
#define Z_Z80_VALUE_AFTER_POWER_ON_IFF2	  0
#define Z_Z80_VALUE_AFTER_POWER_ON_IM	  0

/* MARK: - Values after reset */

#define Z_Z80_VALUE_AFTER_RESET_PC     Z_Z80_VALUE_AFTER_POWER_ON_PC
#define Z_Z80_VALUE_AFTER_RESET_SP     Z_Z80_VALUE_AFTER_POWER_ON_SP
#define Z_Z80_VALUE_AFTER_RESET_AF     Z_Z80_VALUE_AFTER_POWER_ON_AF
#define Z_Z80_VALUE_AFTER_RESET_BC     Z_Z80_VALUE_AFTER_POWER_ON_BC
#define Z_Z80_VALUE_AFTER_RESET_DE     Z_Z80_VALUE_AFTER_POWER_ON_DE
#define Z_Z80_VALUE_AFTER_RESET_HL     Z_Z80_VALUE_AFTER_POWER_ON_HL
#define Z_Z80_VALUE_AFTER_RESET_IX     Z_Z80_VALUE_AFTER_POWER_ON_IX
#define Z_Z80_VALUE_AFTER_RESET_IY     Z_Z80_VALUE_AFTER_POWER_ON_IY
#define Z_Z80_VALUE_AFTER_RESET_AF_    Z_Z80_VALUE_AFTER_POWER_ON_AF_
#define Z_Z80_VALUE_AFTER_RESET_BC_    Z_Z80_VALUE_AFTER_POWER_ON_BC_
#define Z_Z80_VALUE_AFTER_RESET_DE_    Z_Z80_VALUE_AFTER_POWER_ON_DE_
#define Z_Z80_VALUE_AFTER_RESET_HL_    Z_Z80_VALUE_AFTER_POWER_ON_HL_
#define Z_Z80_VALUE_AFTER_RESET_I      Z_Z80_VALUE_AFTER_POWER_ON_I
#define Z_Z80_VALUE_AFTER_RESET_R      Z_Z80_VALUE_AFTER_POWER_ON_R
#define Z_Z80_VALUE_AFTER_RESET_MEMPTR Z_Z80_VALUE_AFTER_POWER_ON_MEMPTR
#define Z_Z80_VALUE_AFTER_RESET_IFF1   Z_Z80_VALUE_AFTER_POWER_ON_IFF1
#define Z_Z80_VALUE_AFTER_RESET_IFF2   Z_Z80_VALUE_AFTER_POWER_ON_IFF2
#define Z_Z80_VALUE_AFTER_RESET_IM     Z_Z80_VALUE_AFTER_POWER_ON_IM

/* MARK: - Information for emulation */

#define Z_Z80_RESET_IS_EQUAL_TO_POWER_ON TRUE

/* MARK: - State storage type */

Z_DEFINE_STRICT_STRUCTURE_BEGIN
	zuint16	pc,  sp;
	Z16Bit	af,  bc,  de,  hl,  ix, iy;
	Z16Bit	af_, bc_, de_, hl_;
	zuint8	r,   i;

	zuint16 memptr;

	struct {zuint8 halt :1;
		zuint8 irq  :1;
		zuint8 nmi  :1;
		zuint8 iff1 :1;
		zuint8 iff2 :1;
		zuint8 ei   :1;
		zuint8 im   :2;
	} internal;
Z_DEFINE_STRICT_STRUCTURE_END ZZ80State;

#define Z_Z80_STATE_AF(	   object) (object)->af.value_uint16
#define Z_Z80_STATE_BC(	   object) (object)->bc.value_uint16
#define Z_Z80_STATE_DE(	   object) (object)->de.value_uint16
#define Z_Z80_STATE_HL(	   object) (object)->hl.value_uint16
#define Z_Z80_STATE_IX(	   object) (object)->ix.value_uint16
#define Z_Z80_STATE_IY(	   object) (object)->iy.value_uint16
#define Z_Z80_STATE_PC(	   object) (object)->pc
#define Z_Z80_STATE_SP(	   object) (object)->sp
#define Z_Z80_STATE_AF_(   object) (object)->af_.value_uint16
#define Z_Z80_STATE_BC_(   object) (object)->bc_.value_uint16
#define Z_Z80_STATE_DE_(   object) (object)->de_.value_uint16
#define Z_Z80_STATE_HL_(   object) (object)->hl_.value_uint16
#define Z_Z80_STATE_A(	   object) (object)->af.values_uint8.index1
#define Z_Z80_STATE_F(	   object) (object)->af.values_uint8.index0
#define Z_Z80_STATE_B(	   object) (object)->bc.values_uint8.index1
#define Z_Z80_STATE_C(	   object) (object)->bc.values_uint8.index0
#define Z_Z80_STATE_D(	   object) (object)->de.values_uint8.index1
#define Z_Z80_STATE_E(	   object) (object)->de.values_uint8.index0
#define Z_Z80_STATE_H(	   object) (object)->hl.values_uint8.index1
#define Z_Z80_STATE_L(	   object) (object)->hl.values_uint8.index0
#define Z_Z80_STATE_IXH(   object) (object)->ix.values_uint8.index1
#define Z_Z80_STATE_IXL(   object) (object)->ix.values_uint8.index0
#define Z_Z80_STATE_IYH(   object) (object)->iy.values_uint8.index1
#define Z_Z80_STATE_IYL(   object) (object)->iy.values_uint8.index0
#define Z_Z80_STATE_A_(	   object) (object)->af_.values_uint8.index1
#define Z_Z80_STATE_F_(	   object) (object)->af_.values_uint8.index0
#define Z_Z80_STATE_B_(	   object) (object)->bc_.values_uint8.index1
#define Z_Z80_STATE_C_(	   object) (object)->bc_.values_uint8.index0
#define Z_Z80_STATE_D_(	   object) (object)->de_.values_uint8.index1
#define Z_Z80_STATE_E_(	   object) (object)->de_.values_uint8.index0
#define Z_Z80_STATE_H_(	   object) (object)->hl_.values_uint8.index1
#define Z_Z80_STATE_L_(	   object) (object)->hl_.values_uint8.index0
#define Z_Z80_STATE_I(	   object) (object)->i
#define Z_Z80_STATE_R(	   object) (object)->r
#define Z_Z80_STATE_MEMPTR(object) (object)->memptr
#define Z_Z80_STATE_HALT(  object) (object)->internal.halt
#define Z_Z80_STATE_IFF1(  object) (object)->internal.iff1
#define Z_Z80_STATE_IFF2(  object) (object)->internal.iff2
#define Z_Z80_STATE_EI(	   object) (object)->internal.ei
#define Z_Z80_STATE_IM(	   object) (object)->internal.im
#define Z_Z80_STATE_NMI(   object) (object)->internal.nmi
#define Z_Z80_STATE_IRQ(   object) (object)->internal.irq

#define Z_Z80_STATE_MEMBER_AF	  af.value_uint16
#define Z_Z80_STATE_MEMBER_BC	  bc.value_uint16
#define Z_Z80_STATE_MEMBER_DE	  de.value_uint16
#define Z_Z80_STATE_MEMBER_HL	  hl.value_uint16
#define Z_Z80_STATE_MEMBER_IX	  ix.value_uint16
#define Z_Z80_STATE_MEMBER_IY	  iy.value_uint16
#define Z_Z80_STATE_MEMBER_PC	  pc
#define Z_Z80_STATE_MEMBER_SP	  sp
#define Z_Z80_STATE_MEMBER_AF_	  af_.value_uint16
#define Z_Z80_STATE_MEMBER_BC_	  bc_.value_uint16
#define Z_Z80_STATE_MEMBER_DE_	  de_.value_uint16
#define Z_Z80_STATE_MEMBER_HL_	  hl_.value_uint16
#define Z_Z80_STATE_MEMBER_A	  af.values_uint8.index1
#define Z_Z80_STATE_MEMBER_F	  af.values_uint8.index0
#define Z_Z80_STATE_MEMBER_B	  bc.values_uint8.index1
#define Z_Z80_STATE_MEMBER_C	  bc.values_uint8.index0
#define Z_Z80_STATE_MEMBER_D	  de.values_uint8.index1
#define Z_Z80_STATE_MEMBER_E	  de.values_uint8.index0
#define Z_Z80_STATE_MEMBER_H	  hl.values_uint8.index1
#define Z_Z80_STATE_MEMBER_L	  hl.values_uint8.index0
#define Z_Z80_STATE_MEMBER_IXH	  ix.values_uint8.index1
#define Z_Z80_STATE_MEMBER_IXL	  ix.values_uint8.index0
#define Z_Z80_STATE_MEMBER_IYH	  iy.values_uint8.index1
#define Z_Z80_STATE_MEMBER_IYL	  iy.values_uint8.index0
#define Z_Z80_STATE_MEMBER_A_	  af_.values_uint8.index1
#define Z_Z80_STATE_MEMBER_F_	  af_.values_uint8.index0
#define Z_Z80_STATE_MEMBER_B_	  bc_.values_uint8.index1
#define Z_Z80_STATE_MEMBER_C_	  bc_.values_uint8.index0
#define Z_Z80_STATE_MEMBER_D_	  de_.values_uint8.index1
#define Z_Z80_STATE_MEMBER_E_	  de_.values_uint8.index0
#define Z_Z80_STATE_MEMBER_H_	  hl_.values_uint8.index1
#define Z_Z80_STATE_MEMBER_L_	  hl_.values_uint8.index0
#define Z_Z80_STATE_MEMBER_I	  i
#define Z_Z80_STATE_MEMBER_R	  r
#define Z_Z80_STATE_MEMPTR_MEMPTR memptr
#define Z_Z80_STATE_MEMBER_HALT	  internal.halt
#define Z_Z80_STATE_MEMBER_IFF1	  internal.iff1
#define Z_Z80_STATE_MEMBER_IFF2	  internal.iff2
#define Z_Z80_STATE_MEMBER_EI	  internal.ei
#define Z_Z80_STATE_MEMBER_IM	  internal.im
#define Z_Z80_STATE_MEMBER_NMI	  internal.nmi
#define Z_Z80_STATE_MEMBER_IRQ	  internal.irq

#endif /* _Z_hardware_CPU_architecture_Z80_H_ */
