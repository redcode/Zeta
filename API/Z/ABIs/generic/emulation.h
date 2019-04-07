/* Z Kit - ABIs/generic/emulation.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2019 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_ABIs_generic_emulation_H
#define Z_ABIs_generic_emulation_H

#include <Z/macros/language.h>
#include <Z/macros/type.h>

#define Z_EMULATOR_FUNCTION_POWER		0
#define Z_EMULATOR_FUNCTION_RESET		1
#define Z_EMULATOR_FUNCTION_RUN			2
#define Z_EMULATOR_FUNCTION_RUN_ONE_SCANLINE
#define Z_EMULATOR_FUNCTION_RUN_ONE_FRAME
#define Z_EMULATOR_FUNCTION_WILL_READ_STATE	3
#define Z_EMULATOR_FUNCTION_DID_WRITE_STATE	4
#define Z_EMULATOR_FUNCTION_HALT		8
#define Z_EMULATOR_FUNCTION_NMI			4
#define Z_EMULATOR_FUNCTION_IRQ			5
#define Z_EMULATOR_FUNCTION_IRQ_DATA		9
#define Z_EMULATOR_FUNCTION_READ_8BIT		6
#define Z_EMULATOR_FUNCTION_READ_16BIT
#define Z_EMULATOR_FUNCTION_READ_32BIT
#define Z_EMULATOR_FUNCTION_READ_64BIT
#define Z_EMULATOR_FUNCTION_READ_128BIT
#define Z_EMULATOR_FUNCTION_READ_256BIT
#define Z_EMULATOR_FUNCTION_READ_512BIT
#define Z_EMULATOR_FUNCTION_READ_1024BIT
#define Z_EMULATOR_FUNCTION_WRITE_8BIT		20
#define Z_EMULATOR_FUNCTION_WRITE_16BIT
#define Z_EMULATOR_FUNCTION_WRITE_32BIT
#define Z_EMULATOR_FUNCTION_WRITE_64BIT
#define Z_EMULATOR_FUNCTION_WRITE_128BIT
#define Z_EMULATOR_FUNCTION_WRITE_256BIT
#define Z_EMULATOR_FUNCTION_WRITE_512BIT
#define Z_EMULATOR_FUNCTION_WRITE_1024BIT
#define Z_EMULATOR_FUNCTION_IN_8BIT		30
#define Z_EMULATOR_FUNCTION_IN_16BIT
#define Z_EMULATOR_FUNCTION_IN_32BIT
#define Z_EMULATOR_FUNCTION_IN_64BIT
#define Z_EMULATOR_FUNCTION_IN_128BIT
#define Z_EMULATOR_FUNCTION_IN_256BIT
#define Z_EMULATOR_FUNCTION_IN_512BIT
#define Z_EMULATOR_FUNCTION_IN_1024BIT
#define Z_EMULATOR_FUNCTION_OUT_8BIT		40
#define Z_EMULATOR_FUNCTION_OUT_16BIT
#define Z_EMULATOR_FUNCTION_OUT_32BIT
#define Z_EMULATOR_FUNCTION_OUT_64BIT
#define Z_EMULATOR_FUNCTION_OUT_128BIT
#define Z_EMULATOR_FUNCTION_OUT_256BIT
#define Z_EMULATOR_FUNCTION_OUT_512BIT
#define Z_EMULATOR_FUNCTION_OUT_1024BIT

#define Z_KEY_BITS_EMULATOR_FUNCTION 8

typedef void   (* ZEmulatorPower	)(void* object, zboolean state );
typedef zusize (* ZEmulatorRun		)(void* object, zusize   cycles);
typedef void   (* ZEmulatorWillReadState)(void* object);
typedef void   (* ZEmulatorDidWriteState)(void* object);

typedef struct {
	zuintptr id;

	struct {zusize cycles;
		/* ... */
	} context;
} ZEmulatorComponent;

Z_DEFINE_PACKED_STRUCTURE (
	zchar const* domain_identifier;
	zchar const* unit_identifier;
) ZEmulatorDependency;

Z_DEFINE_PACKED_STRUCTURE (
	ZKey(EMULATOR_FUNCTION) key;
	void (*)(void)		function;
) ZEmulatorFunctionExport;

Z_DEFINE_PACKED_STRUCTURE (
	ZKey(EMULATOR_FUNCTION) key;
	zusize			offset;
) ZEmulatorInstanceImport;

typedef ZEmulatorExport		ZCPUEmulatorExport;
typedef ZEmulatorInstanceImport ZCPUEmulatorInstanceImport;

Z_DEFINE_PACKED_STRUCTURE ({
	zchar const* name;
	zusize	     offset;
	zuint16	     bit_offset;
	zuint16	     bits;
	zuint16	     storage_bits;
	zuint8	     endianness;
}, ZEmulatorContextVariableExport);

Z_DEFINE_PACKED_STRUCTURE ({
	zusize			       dependency_count;
	ZEmulatorDependency const*     dependencies;
	zusize			       function_export_count;
	ZEmulatorExport const*	       function_exports;
	zusize			       instance_size;
	zusize			       instance_state_offset;
	zusize			       instance_state_size;
	zusize			       instance_import_count;
	ZEmulatorInstanceImport const* instance_imports;
}, ZCPUEmulatorABI);

#endif /* Z_ABIs_generic_emulation_H */
