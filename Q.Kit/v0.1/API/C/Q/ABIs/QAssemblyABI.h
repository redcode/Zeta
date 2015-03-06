/* Q C API - ABIs/QAssemblyABI.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_ABIs_QAssemblyABI_H__
#define __Q_ABIs_QAssemblyABI_H__

#include <Q/types/base.h>

typedef quint8 QInstructionFeature;

typedef struct {
	quint8 type 
} QAssemblyOperandPrototype;


typedef struct {
	quint instruction_index;
	quint operand_count;
} QAssemblyInstructionPrototype;

typedef struct {
} QAssemblyInstruction;

typedef struct {
} QAssemblyInstructionValue;

typedef struct {
	
} QInstructionPrototype;


typedef struct {

} QInstructionOpcodePrototype;


typedef Q_STRICT_STRUCTURE (
	quint16		offset;
	struct {quint8	endianness:2;
		quint8	type:2;
	} encoding;
) QInstructionValuePrototype;



/*
Number
	Offset
	Endianness
	Type

Register
	Index


*/

typedef qboolean (* QAssemble)		(QString*	assembly);

typedef qboolean (* QDisassemble)	(void*		block,
					 qsize		block_size);

typedef struct {

	QAssemble	assemble;
	QDisassemble	disassemble;

	quint		maximum_instruction_size;

	QString*	operand_separator;
	QString*	register_prefix;
	QString*	register_suffix;
	QString*	absolute_address_prefix;
	QString*	absolute_address_suffix;
	QString*	relative_address_prefix;
	QString*	relative_address_suffix;
	QString*	port_prefix;
	QString*	port_suffix;

	QString**	instructions;
	QString**	registers;
	QString**	conditions;

} QAssemblyABI;

#define Q_ASSEMBLY_ABI(p) ((QAssemblyABI *)(p))

#endif /* __Q_ABIs_QAssemblyABI_H__ */
