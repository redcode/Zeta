/* Z Kit C API - ABIs/emulation.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_ABIs_emulation_H__
#define __Z_ABIs_emulation_H__

#include <Z/types/generic functions.h>
#include <Z/macros/key.h>

#define Z_EMULATOR_OBJECT_MACHINE 0
#define Z_EMULATOR_OBJECT_MEMORY  1
#define Z_EMULATOR_OBJECT_IO	  2
#define Z_EMULATOR_OBJECT_CPU	  3
#define Z_EMULATOR_OBJECT_DEVICE  4

#define Z_KEY_BITS_EMULATOR_OBJECT 8

#define Z_EMULATOR_ACTION_POWER			0
#define Z_EMULATOR_ACTION_RESET			1
#define Z_EMULATOR_ACTION_RUN			2
#define Z_EMULATOR_ACTION_RUN_ONE_SCANLINE
#define Z_EMULATOR_ACTION_RUN_ONE_FRAME
#define Z_EMULATOR_ACTION_AFTER_STATE_READED	3
#define Z_EMULATOR_ACTION_AFTER_STATE_WRITTEN	4
#define Z_EMULATOR_ACTION_HALT			8
#define Z_EMULATOR_ACTION_NMI			4
#define Z_EMULATOR_ACTION_INT			5
#define Z_EMULATOR_ACTION_INT_DATA		9
#define Z_EMULATOR_ACTION_READ_8BIT		6
#define Z_EMULATOR_ACTION_READ_16BIT
#define Z_EMULATOR_ACTION_READ_32BIT
#define Z_EMULATOR_ACTION_READ_64BIT
#define Z_EMULATOR_ACTION_READ_128BIT
#define Z_EMULATOR_ACTION_READ_256BIT
#define Z_EMULATOR_ACTION_READ_512BIT
#define Z_EMULATOR_ACTION_READ_1024BIT
#define Z_EMULATOR_ACTION_WRITE_8BIT		20
#define Z_EMULATOR_ACTION_WRITE_16BIT
#define Z_EMULATOR_ACTION_WRITE_32BIT
#define Z_EMULATOR_ACTION_WRITE_64BIT
#define Z_EMULATOR_ACTION_WRITE_128BIT
#define Z_EMULATOR_ACTION_WRITE_256BIT
#define Z_EMULATOR_ACTION_WRITE_512BIT
#define Z_EMULATOR_ACTION_WRITE_1024BIT
#define Z_EMULATOR_ACTION_IN_8BIT		30
#define Z_EMULATOR_ACTION_IN_16BIT
#define Z_EMULATOR_ACTION_IN_32BIT
#define Z_EMULATOR_ACTION_IN_64BIT
#define Z_EMULATOR_ACTION_IN_128BIT
#define Z_EMULATOR_ACTION_IN_256BIT
#define Z_EMULATOR_ACTION_IN_512BIT
#define Z_EMULATOR_ACTION_IN_1024BIT
#define Z_EMULATOR_ACTION_OUT_8BIT		40
#define Z_EMULATOR_ACTION_OUT_16BIT
#define Z_EMULATOR_ACTION_OUT_32BIT
#define Z_EMULATOR_ACTION_OUT_64BIT
#define Z_EMULATOR_ACTION_OUT_128BIT
#define Z_EMULATOR_ACTION_OUT_256BIT
#define Z_EMULATOR_ACTION_OUT_512BIT
#define Z_EMULATOR_ACTION_OUT_1024BIT

#define Z_KEY_BITS_EMULATOR_ACTION 8

typedef struct {
	zuintptr id;

	struct {zsize cycles;
		/* ... */
	} context;
} ZEmulatorComponent;

Z_DEFINE_STRICT_STRUCTURE (
) ZEmulatorDependency;

Z_DEFINE_STRICT_STRUCTURE (
	ZKey(EMULATOR_ACTION) key;
	ZDo		      action;
) ZEmulatorExport;

Z_DEFINE_STRICT_STRUCTURE (
	ZKey(EMULATOR_OBJECT) object_key;
	ZKey(EMULATOR_ACTION) action_key;
	zsize		      offset;
) ZEmulatorSlotLinkage;

Z_DEFINE_STRICT_STRUCTURE (
	zsize			   dependency_count;
	ZEmulatorDependency const* dependencies;
	zsize			   export_count;
	ZEmulatorExport const*     exports;

	struct {zsize			    size;
		zsize			    state_offset;
		zsize			    slot_linkage_count;
		ZEmulatorSlotLinkage const* slot_linkages;
	} object;
) ZCPUEmulatorABI;

typedef struct {
} ZMachineEmulatorABI;

typedef zsize (* ZMachineEmulatorRunOneFrame) (void *object);
typedef zsize (* ZEmulatorRun		   ) (void* object, zsize    cycles	);
typedef void  (* ZEmulatorPower		   ) (void* object, zboolean power_state);
typedef void  (* ZEmulatorAfterStateReaded ) (void* object, void*    state	);
typedef void  (* ZEmulatorAfterStateWritten) (void* object);

#endif /* __Z_ABIs_emulation_H__ */
