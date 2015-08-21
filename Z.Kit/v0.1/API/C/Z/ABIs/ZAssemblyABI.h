/* Z Kit C API - ABIs/ZAssemblyABI.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_ABIs_ZAssemblyABI_H__
#define __Z_ABIs_ZAssemblyABI_H__

#include <Z/types/base.h>

typedef zuint8 ZInstructionFeature;

typedef struct {
	zuint8 type 
} ZAssemblyOperandPrototype;


typedef struct {
	zuint instruction_index;
	zuint operand_count;
} ZAssemblyInstructionPrototype;

typedef struct {
} ZAssemblyInstruction;

typedef struct {
} ZAssemblyInstructionValue;

typedef struct {
	
} ZInstructionPrototype;


typedef struct {

} ZInstructionOpcodePrototype;


typedef Z_STRICT_STRUCTURE (
	zuint16		offset;
	struct {zuint8	endianness:2;
		zuint8	type:2;
	} encoding;
) ZInstructionValuePrototype;



/*
Number
	Offset
	Endianness
	Type

Register
	Index


*/

typedef zboolean (* ZAssemble)		(ZString*	assembly);

typedef zboolean (* ZDisassemble)	(void*		block,
					 zsize		block_size);

typedef struct {

	ZAssemble	assemble;
	ZDisassemble	disassemble;

	zuint		maximum_instruction_size;

	ZString*	operand_separator;
	ZString*	register_prefix;
	ZString*	register_suffix;
	ZString*	absolute_address_prefix;
	ZString*	absolute_address_suffix;
	ZString*	relative_address_prefix;
	ZString*	relative_address_suffix;
	ZString*	port_prefix;
	ZString*	port_suffix;

	ZString**	instructions;
	ZString**	registers;
	ZString**	conditions;

} ZAssemblyABI;

#define Z_ASSEMBLY_ABI(p) ((ZAssemblyABI *)(p))

#endif /* __Z_ABIs_ZAssemblyABI_H__ */
