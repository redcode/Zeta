/* Q C API - ABIs/emulation.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_ABIs_emulation_H__
#define __Q_ABIs_emulation_H__

#include <Q/types/generic functions.h>
#include <Q/macros/key.h>

#define Q_EMULATOR_OBJECT_MACHINE 0
#define Q_EMULATOR_OBJECT_MEMORY  1
#define Q_EMULATOR_OBJECT_IO	  2
#define Q_EMULATOR_OBJECT_CPU	  3
#define Q_EMULATOR_OBJECT_DEVICE  4

#define Q_KEY_BITS_EMULATOR_OBJECT 8

#define Q_EMULATOR_ACTION_POWER			0
#define Q_EMULATOR_ACTION_RESET			1
#define Q_EMULATOR_ACTION_RUN			2
#define Q_EMULATOR_ACTION_RUN_ONE_SCANLINE
#define Q_EMULATOR_ACTION_RUN_ONE_FRAME
#define Q_EMULATOR_ACTION_AFTER_STATE_READED	3
#define Q_EMULATOR_ACTION_AFTER_STATE_WRITTEN	4
#define Q_EMULATOR_ACTION_HALT			8
#define Q_EMULATOR_ACTION_NMI			4
#define Q_EMULATOR_ACTION_INT			5
#define Q_EMULATOR_ACTION_INT_DATA		9
#define Q_EMULATOR_ACTION_READ_8BIT		6
#define Q_EMULATOR_ACTION_READ_16BIT
#define Q_EMULATOR_ACTION_READ_32BIT
#define Q_EMULATOR_ACTION_READ_64BIT
#define Q_EMULATOR_ACTION_READ_128BIT
#define Q_EMULATOR_ACTION_READ_256BIT
#define Q_EMULATOR_ACTION_READ_512BIT
#define Q_EMULATOR_ACTION_READ_1024BIT
#define Q_EMULATOR_ACTION_WRITE_8BIT		20
#define Q_EMULATOR_ACTION_WRITE_16BIT
#define Q_EMULATOR_ACTION_WRITE_32BIT
#define Q_EMULATOR_ACTION_WRITE_64BIT
#define Q_EMULATOR_ACTION_WRITE_128BIT
#define Q_EMULATOR_ACTION_WRITE_256BIT
#define Q_EMULATOR_ACTION_WRITE_512BIT
#define Q_EMULATOR_ACTION_WRITE_1024BIT
#define Q_EMULATOR_ACTION_IN_8BIT		30
#define Q_EMULATOR_ACTION_IN_16BIT
#define Q_EMULATOR_ACTION_IN_32BIT
#define Q_EMULATOR_ACTION_IN_64BIT
#define Q_EMULATOR_ACTION_IN_128BIT
#define Q_EMULATOR_ACTION_IN_256BIT
#define Q_EMULATOR_ACTION_IN_512BIT
#define Q_EMULATOR_ACTION_IN_1024BIT
#define Q_EMULATOR_ACTION_OUT_8BIT		40
#define Q_EMULATOR_ACTION_OUT_16BIT
#define Q_EMULATOR_ACTION_OUT_32BIT
#define Q_EMULATOR_ACTION_OUT_64BIT
#define Q_EMULATOR_ACTION_OUT_128BIT
#define Q_EMULATOR_ACTION_OUT_256BIT
#define Q_EMULATOR_ACTION_OUT_512BIT
#define Q_EMULATOR_ACTION_OUT_1024BIT

#define Q_KEY_BITS_EMULATOR_ACTION 8

typedef struct {
	quintptr id;
	qsize	 cycles;
} QEmulatorComponent;

Q_DEFINE_STRICT_STRUCTURE (
) QEmulatorDependency;

Q_DEFINE_STRICT_STRUCTURE (
	QKey(EMULATOR_ACTION) key;
	QDo		      action;
) QEmulatorExport;

Q_DEFINE_STRICT_STRUCTURE (
	QKey(EMULATOR_OBJECT) object_key;
	QKey(EMULATOR_ACTION) action_key;
	qsize		      offset;
) QEmulatorSlotLinkage;

Q_DEFINE_STRICT_STRUCTURE (
	qsize		     dependency_count;
	QEmulatorDependency* dependencies;
	qsize		     export_count;
	QEmulatorExport*     exports;

	struct {qsize		      size;
		qsize		      state_offset;
		qsize		      slot_linkage_count;
		QEmulatorSlotLinkage* slot_linkages;
	} object;
) QCPUEmulatorABI;

typedef struct {
} QMachineEmulatorABI;

#define Q_EMULATOR_COMPONENT(	p) ((QEmulatorComponent   *)(p))
#define Q_EMULATOR_DEPENDENCY(	p) ((QEmulatorDependency  *)(p))
#define Q_EMULATOR_EXPORT(	p) ((QEmulatorExport	  *)(p))
#define Q_EMULATOR_SLOT_LINKAGE(p) ((QEmulatorSlotLinkage *)(p))
#define Q_EMULATOR_ABI(		p) ((QCPUEmulatorABI	  *)(p))

typedef qsize (* QMachineEmulatorRunOneFrame) (void *object);
typedef qsize (* QEmulatorRun		   ) (void* object, qsize    cycles	);
typedef void  (* QEmulatorPower		   ) (void* object, qboolean power_state);
typedef void  (* QEmulatorAfterStateReaded ) (void* object, void*    state	);
typedef void  (* QEmulatorAfterStateWritten) (void* object);

#endif /* __Q_ABIs_emulation_H__ */
