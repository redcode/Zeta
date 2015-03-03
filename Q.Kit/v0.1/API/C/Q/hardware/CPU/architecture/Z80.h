/* Q API - hardware/CPU/architecture/Z80.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
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

Flags (F register)
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

#ifndef __Q_hardware_CPU_architecture_Z80_Ha__
#define __Q_hardware_CPU_architecture_Z80_Ha__

#include <Q/keys/endianness.h>

/* MARK: - Limits and features */

#define Q_Z80_MINIMUM_CYCLES_PER_INSTRUCTION	 4
#define Q_Z80_MINIMUM_INSTRUCTION_SIZE		 1
#define Q_Z80_MINIMUM_LOAD_BITS			 8
#define Q_Z80_MINIMUM_STORE_BITS		 8
#define Q_Z80_MINIMUM_COPY_BITS			 8
#define Q_Z80_MAXIMUM_CYCLES_PER_INSTRUCTION	23
#define Q_Z80_MAXIMUM_INSTRUCTION_SIZE		 4
#define Q_Z80_MAXIMUM_LOAD_BITS			16
#define Q_Z80_MAXIMUM_STORE_BITS		16
#define Q_Z80_MAXIMUM_COPY_BITS			16
#define Q_Z80_ADDRESS_BUS_BITS			16
#define Q_Z80_DATA_BUS_BITS			 8
#define Q_Z80_ADDRESSING_BITS			16
#define Q_Z80_ENDIANNESS			Q_ENDIANNESS_LITTLE

/* MARK: - Addresses */

#define Q_Z80_ADDRESS_NMI_POINTER		0x0066

/* MARK: - Values after power on */

/*
#define Q_Z80_PC_VALUE_AFTER_POWER_ON		0x0000
#define Q_Z80_SP_VALUE_AFTER_POWER_ON		0x0000
#define Q_Z80_AF_VALUE_AFTER_POWER_ON		0x0040
#define Q_Z80_BC_VALUE_AFTER_POWER_ON		0x0000
#define Q_Z80_DE_VALUE_AFTER_POWER_ON		0x0000
#define Q_Z80_HL_VALUE_AFTER_POWER_ON		0x0000
#define Q_Z80_IX_VALUE_AFTER_POWER_ON		0x0000
#define Q_Z80_IY_VALUE_AFTER_POWER_ON		0xFFFF
#define Q_Z80_AF__VALUE_AFTER_POWER_ON		0x0000
#define Q_Z80_BC__VALUE_AFTER_POWER_ON		0x0000
#define Q_Z80_DE__VALUE_AFTER_POWER_ON		0x0000
#define Q_Z80_HL__VALUE_AFTER_POWER_ON		0x0000
#define Q_Z80_I_VALUE_AFTER_POWER_ON		0x00
#define Q_Z80_R_VALUE_AFTER_POWER_ON		0x00
#define Q_Z80_IFF1_VALUE_AFTER_POWER_ON		0
#define Q_Z80_IFF2_VALUE_AFTER_POWER_ON		0
#define Q_Z80_IM_VALUE_AFTER_POWER_ON		1
*/

#define Q_Z80_VALUE_AFTER_POWER_ON_PC		0x0000
#define Q_Z80_VALUE_AFTER_POWER_ON_SP		0xFFFF
#define Q_Z80_VALUE_AFTER_POWER_ON_AF		0xFFFF
#define Q_Z80_VALUE_AFTER_POWER_ON_BC		0xFFFF
#define Q_Z80_VALUE_AFTER_POWER_ON_DE		0xFFFF
#define Q_Z80_VALUE_AFTER_POWER_ON_HL		0xFFFF
#define Q_Z80_VALUE_AFTER_POWER_ON_IX		0xFFFF
#define Q_Z80_VALUE_AFTER_POWER_ON_IY		0xFFFF
#define Q_Z80_VALUE_AFTER_POWER_ON_AF_		0xFFFF
#define Q_Z80_VALUE_AFTER_POWER_ON_BC_		0xFFFF
#define Q_Z80_VALUE_AFTER_POWER_ON_DE_		0xFFFF
#define Q_Z80_VALUE_AFTER_POWER_ON_HL_		0xFFFF
#define Q_Z80_VALUE_AFTER_POWER_ON_I		0x00
#define Q_Z80_VALUE_AFTER_POWER_ON_R		0x00
#define Q_Z80_VALUE_AFTER_POWER_ON_IFF1		0
#define Q_Z80_VALUE_AFTER_POWER_ON_IFF2		0
#define Q_Z80_VALUE_AFTER_POWER_ON_IM		0

/* MARK: - Values after reset */

#define Q_Z80_VALUE_AFTER_RESET_PC		Q_Z80_VALUE_AFTER_POWER_ON_PC
#define Q_Z80_VALUE_AFTER_RESET_SP		Q_Z80_VALUE_AFTER_POWER_ON_SP
#define Q_Z80_VALUE_AFTER_RESET_AF		Q_Z80_VALUE_AFTER_POWER_ON_AF
#define Q_Z80_VALUE_AFTER_RESET_BC		Q_Z80_VALUE_AFTER_POWER_ON_BC
#define Q_Z80_VALUE_AFTER_RESET_DE		Q_Z80_VALUE_AFTER_POWER_ON_DE
#define Q_Z80_VALUE_AFTER_RESET_HL		Q_Z80_VALUE_AFTER_POWER_ON_HL
#define Q_Z80_VALUE_AFTER_RESET_IX		Q_Z80_VALUE_AFTER_POWER_ON_IX
#define Q_Z80_VALUE_AFTER_RESET_IY		Q_Z80_VALUE_AFTER_POWER_ON_IY
#define Q_Z80_VALUE_AFTER_RESET_AF_		Q_Z80_VALUE_AFTER_POWER_ON_AF_
#define Q_Z80_VALUE_AFTER_RESET_BC_		Q_Z80_VALUE_AFTER_POWER_ON_BC_
#define Q_Z80_VALUE_AFTER_RESET_DE_		Q_Z80_VALUE_AFTER_POWER_ON_DE_
#define Q_Z80_VALUE_AFTER_RESET_HL_		Q_Z80_VALUE_AFTER_POWER_ON_HL_
#define Q_Z80_VALUE_AFTER_RESET_I		Q_Z80_VALUE_AFTER_POWER_ON_I
#define Q_Z80_VALUE_AFTER_RESET_R		Q_Z80_VALUE_AFTER_POWER_ON_R
#define Q_Z80_VALUE_AFTER_RESET_IFF1		Q_Z80_VALUE_AFTER_POWER_ON_IFF1
#define Q_Z80_VALUE_AFTER_RESET_IFF2		Q_Z80_VALUE_AFTER_POWER_ON_IFF2
#define Q_Z80_VALUE_AFTER_RESET_IM		Q_Z80_VALUE_AFTER_POWER_ON_IM

/* MARK: - Information for emulation */

#define Q_Z80_RESET_IS_EQUAL_TO_POWER_ON

#endif /* __Q_hardware_CPU_architecture_Z80_Ha__ */

#ifdef Q_INSPECTING

#	undef Z80
#	undef z80

#	define Q_CPU_ARCHITECTURE_NAME Z80
#	define Q_CPU_ARCHITECTURE_Name Z80
#	define Q_CPU_ARCHITECTURE_name z80

#else

#	ifndef __Q_hardware_CPU_architecture_Z80_Hb__
#	define __Q_hardware_CPU_architecture_Z80_Hb__

#	include <Q/types/base.h>
#	include <Q/macros/bit field.h>

#	pragma mark - State storage type

	typedef struct {
		quint16	pc,  sp;
		Q16Bit	af,  bc,  de,  hl,  ix,  iy;
		Q16Bit	af_, bc_, de_, hl_;
		quint8	i,   r;

		struct {quint8 halt :1;
			quint8 irq  :1;
			quint8 nmi  :1;
			quint8 iff1 :1;
			quint8 iff2 :1;
			quint8 ei   :1;
			quint8 im   :2;
		} internal;
	} QZ80State;

#	define Q_Z80_STATE(p) ((QZ80State *)(p))

	/* MARK: - State structure macros (16-bit registers) */

#	define Q_Z80_STATE_AF( object)	(object)->af.uint16_value
#	define Q_Z80_STATE_BC( object)	(object)->bc.uint16_value
#	define Q_Z80_STATE_DE( object)	(object)->de.uint16_value
#	define Q_Z80_STATE_HL( object)	(object)->hl.uint16_value
#	define Q_Z80_STATE_IX( object)	(object)->ix.uint16_value
#	define Q_Z80_STATE_IY( object)	(object)->iy.uint16_value
#	define Q_Z80_STATE_PC( object)	(object)->pc
#	define Q_Z80_STATE_SP( object)	(object)->sp
#	define Q_Z80_STATE_AF_(object)	(object)->af_.uint16_value
#	define Q_Z80_STATE_BC_(object)	(object)->bc_.uint16_value
#	define Q_Z80_STATE_DE_(object)	(object)->de_.uint16_value
#	define Q_Z80_STATE_HL_(object)	(object)->hl_.uint16_value

#	define Q_Z80_STATE_MEMBER_AF	af.uint16_value
#	define Q_Z80_STATE_MEMBER_BC	bc.uint16_value
#	define Q_Z80_STATE_MEMBER_DE	de.uint16_value
#	define Q_Z80_STATE_MEMBER_HL	hl.uint16_value
#	define Q_Z80_STATE_MEMBER_IX	ix.uint16_value
#	define Q_Z80_STATE_MEMBER_IY	iy.uint16_value
#	define Q_Z80_STATE_MEMBER_PC	pc
#	define Q_Z80_STATE_MEMBER_SP	sp
#	define Q_Z80_STATE_MEMBER_AF_	af_.uint16_value
#	define Q_Z80_STATE_MEMBER_BC_	bc_.uint16_value
#	define Q_Z80_STATE_MEMBER_DE_	de_.uint16_value
#	define Q_Z80_STATE_MEMBER_HL_	hl_.uint16_value

	/* MARK: - State structure macros (8-bit registers) */

#	define Q_Z80_STATE_A(  object)	(object)->af.uint8_values.index1
#	define Q_Z80_STATE_F(  object)	(object)->af.uint8_values.index0
#	define Q_Z80_STATE_B(  object)	(object)->bc.uint8_values.index1
#	define Q_Z80_STATE_C(  object)	(object)->bc.uint8_values.index0
#	define Q_Z80_STATE_D(  object)	(object)->de.uint8_values.index1
#	define Q_Z80_STATE_E(  object)	(object)->de.uint8_values.index0
#	define Q_Z80_STATE_H(  object)	(object)->hl.uint8_values.index1
#	define Q_Z80_STATE_L(  object)	(object)->hl.uint8_values.index0
#	define Q_Z80_STATE_IXH(object)	(object)->ix.uint8_values.index1
#	define Q_Z80_STATE_IXL(object)	(object)->ix.uint8_values.index0
#	define Q_Z80_STATE_IYH(object)	(object)->iy.uint8_values.index1
#	define Q_Z80_STATE_IYL(object)	(object)->iy.uint8_values.index0
#	define Q_Z80_STATE_A_( object)	(object)->af_.uint8_values.index1
#	define Q_Z80_STATE_F_( object)	(object)->af_.uint8_values.index0
#	define Q_Z80_STATE_B_( object)	(object)->bc_.uint8_values.index1
#	define Q_Z80_STATE_C_( object)	(object)->bc_.uint8_values.index0
#	define Q_Z80_STATE_D_( object)	(object)->de_.uint8_values.index1
#	define Q_Z80_STATE_E_( object)	(object)->de_.uint8_values.index0
#	define Q_Z80_STATE_H_( object)	(object)->hl_.uint8_values.index1
#	define Q_Z80_STATE_L_( object)	(object)->hl_.uint8_values.index0
#	define Q_Z80_STATE_I(  object)	(object)->i
#	define Q_Z80_STATE_R(  object)	(object)->r

#	define Q_Z80_STATE_MEMBER_A	af.uint8_values.index1
#	define Q_Z80_STATE_MEMBER_F	af.uint8_values.index0
#	define Q_Z80_STATE_MEMBER_B	bc.uint8_values.index1
#	define Q_Z80_STATE_MEMBER_C	bc.uint8_values.index0
#	define Q_Z80_STATE_MEMBER_D	de.uint8_values.index1
#	define Q_Z80_STATE_MEMBER_E	de.uint8_values.index0
#	define Q_Z80_STATE_MEMBER_H	hl.uint8_values.index1
#	define Q_Z80_STATE_MEMBER_L	hl.uint8_values.index0
#	define Q_Z80_STATE_MEMBER_IXH	ix.uint8_values.index1
#	define Q_Z80_STATE_MEMBER_IXL	ix.uint8_values.index0
#	define Q_Z80_STATE_MEMBER_IYH	iy.uint8_values.index1
#	define Q_Z80_STATE_MEMBER_IYL	iy.uint8_values.index0
#	define Q_Z80_STATE_MEMBER_A_	af_.uint8_values.index1
#	define Q_Z80_STATE_MEMBER_F_	af_.uint8_values.index0
#	define Q_Z80_STATE_MEMBER_B_	bc_.uint8_values.index1
#	define Q_Z80_STATE_MEMBER_C_	bc_.uint8_values.index0
#	define Q_Z80_STATE_MEMBER_D_	de_.uint8_values.index1
#	define Q_Z80_STATE_MEMBER_E_	de_.uint8_values.index0
#	define Q_Z80_STATE_MEMBER_H_	hl_.uint8_values.index1
#	define Q_Z80_STATE_MEMBER_L_	hl_.uint8_values.index0
#	define Q_Z80_STATE_MEMBER_I	i
#	define Q_Z80_STATE_MEMBER_R	r

	/* MARK: - Macros (Internals) */

#	define Q_Z80_STATE_HALT(object)	(object)->internal.halt
#	define Q_Z80_STATE_IFF1(object)	(object)->internal.iff1
#	define Q_Z80_STATE_IFF2(object)	(object)->internal.iff2
#	define Q_Z80_STATE_EI(	object)	(object)->internal.ei
#	define Q_Z80_STATE_IM(	object)	(object)->internal.im
#	define Q_Z80_STATE_NMI( object)	(object)->internal.nmi
#	define Q_Z80_STATE_IRQ( object)	(object)->internal.irq

#	define Q_Z80_STATE_MEMBER_HALT	internal.halt
#	define Q_Z80_STATE_MEMBER_IFF1	internal.iff1
#	define Q_Z80_STATE_MEMBER_IFF2	internal.iff2
#	define Q_Z80_STATE_MEMBER_EI	internal.ei
#	define Q_Z80_STATE_MEMBER_IM	internal.im
#	define Q_Z80_STATE_MEMBER_NMI	internal.nmi
#	define Q_Z80_STATE_MEMBER_IRQ	internal.irq

#	endif /* __Q_hardware_CPU_architecture_Z80_Hb__ */

#endif
