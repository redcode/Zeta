/* Z Kit C API - ABIs/generic/emulation.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_ABIs_generic_emulation_H__
#define __Z_ABIs_generic_emulation_H__

#include <Z/types/generic functions.h>
#include <Z/macros/key.h>

#define Z_EMULATOR_FUNCTION_POWER		0
#define Z_EMULATOR_FUNCTION_RESET		1
#define Z_EMULATOR_FUNCTION_RUN			2
#define Z_EMULATOR_FUNCTION_RUN_ONE_SCANLINE
#define Z_EMULATOR_FUNCTION_RUN_ONE_FRAME
#define Z_EMULATOR_FUNCTION_WILL_READ_STATE	3
#define Z_EMULATOR_FUNCTION_DID_WRITE_STATE	4
#define Z_EMULATOR_FUNCTION_HALT		8
#define Z_EMULATOR_FUNCTION_NMI			4
#define Z_EMULATOR_FUNCTION_INT			5
#define Z_EMULATOR_FUNCTION_INT_DATA		9
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

typedef struct {
	zuintptr id;

	struct {zsize cycles;
		/* ... */
	} context;
} ZEmulatorComponent;

Z_DEFINE_STRICT_STRUCTURE (
) ZEmulatorDependency;

typedef ZContextDo ZEmulatorFunction;

Z_DEFINE_STRICT_STRUCTURE (
	ZKey(EMULATOR_FUNCTION) key;
	ZEmulatorFunction	function;
) ZEmulatorExport;

Z_DEFINE_STRICT_STRUCTURE (
	ZKey(EMULATOR_FUNCTION) key;
	zsize			offset;
) ZEmulatorInstanceImport;

typedef ZEmulatorExport		ZCPUEmulatorExport;
typedef ZEmulatorInstanceImport ZCPUEmulatorInstanceImport;

Z_DEFINE_STRICT_STRUCTURE (
	zsize			       dependency_count;
	ZEmulatorDependency const*     dependencies;
	zsize			       function_export_count;
	ZEmulatorExport const*	       function_exports;
	zsize			       instance_size;
	zsize			       instance_state_offset;
	zsize			       instance_state_size;
	zsize			       instance_import_count;
	ZEmulatorInstanceImport const* instance_imports;
) ZCPUEmulatorABI;

typedef struct {
} ZMachineEmulatorABI;

typedef zsize (* ZEmulatorRun)	(void*    object,
				 zsize    cycles);

typedef void  (* ZEmulatorPower)(void*    object,
				 zboolean power_state);

typedef ZContextDo ZEmulatorWillReadState;
typedef ZContextDo ZEmulatorDidWriteState;

#endif /* __Z_ABIs_generic_emulation_H__ */
