/* Zeta API - Z/formats/recording/machine/computer/ZX_Spectrum/RZX.h
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_formats_recording_machine_computer_ZX_Spectrum_RZX_H
#define Z_formats_recording_machine_computer_ZX_Spectrum_RZX_H

#include <Z/types/bitwise.h>

typedef Z_PACKED_STRUCTURE_BEGIN {
	ZInt32	signature; /* 'RZX!' */
	zuint8	version_major;
	zuint8	version_minor;
	zuint32 flags;
} Z_PACKED_STRUCTURE_END Z_RZXHeader;

#define Z_RZX_BLOCK_ID_CREATOR_INFO	  0x10
#define Z_RZX_BLOCK_ID_SECURITY_INFO	  0x20
#define Z_RZX_BLOCK_ID_SECURITY_SIGNATURE 0x21
#define Z_RZX_BLOCK_ID_SNAPSHOT		  0x30
#define Z_RZX_BLOCK_ID_INPUT_RECORDING	  0x80

typedef Z_PACKED_STRUCTURE_BEGIN {
	zuint8	block_id;
	zuint32 block_size;
} Z_PACKED_STRUCTURE_END Z_RZXBlockHeader;

/* MARK: - ID 10h - Creator Information */

typedef Z_PACKED_STRUCTURE_BEGIN {
	Z_RZXBlockHeader header;
	zuint8	identifier;
	zuint16 version_major;
	zuint16 version_minor;
	Z_FAM(zuint8 custom_data[];)
} Z_PACKED_STRUCTURE_END Z_RZXCreatorInfo;

/* MARK: - ID 20h - Security Information */

typedef Z_PACKED_STRUCTURE_BEGIN {
	Z_RZXBlockHeader header;
	zuint32 key_id;
	zuint32 week_code;
} Z_PACKED_STRUCTURE_END Z_RZXSecurityInfo;

/* MARK: - ID 21h - Security Signature */

typedef Z_PACKED_STRUCTURE_BEGIN {
	Z_RZXBlockHeader header;
	Z_FAM(zuint8 r_s[];)
} Z_PACKED_STRUCTURE_END Z_RZXSecuritySignature;

/* MARK: - ID 21h - Snapshot */

typedef Z_PACKED_STRUCTURE_BEGIN {
	Z_RZXBlockHeader header;
	zuint32 flags;
	ZInt32  filename_extension;
	zuint32 size_uncompressed;
	Z_FAM(zuint8 data[];)
} Z_PACKED_STRUCTURE_END Z_RZXSnapshot;

#define Z_RZX_SNAPSHOT_FLAG_EXTERNAL   1
#define Z_RZX_SNAPSHOT_FLAG_COMPRESSED 2

typedef Z_PACKED_STRUCTURE_BEGIN {
	zuint32 checksum;
	Z_FAM(zuint8 filename[];)
} Z_PACKED_STRUCTURE_END Z_RZXSnapshotDescriptor;

/* MARK: - ID 80h - Input Recording */

typedef Z_PACKED_STRUCTURE_BEGIN {
	Z_RZXBlockHeader header;
	zuint32 frame_count;
	zuint8	reserved;
	zuint32 t_states;
	zuint32 flags;
} Z_PACKED_STRUCTURE_END Z_RZXInputRecording;

#define Z_RZX_INPUT_RECORDING_FLAG_CYPHERED   1
#define Z_RZX_INPUT_RECORDING_FLAG_COMPRESSED 2

typedef Z_PACKED_STRUCTURE_BEGIN {
	zuint16 opcode_fetch_count;
	zuint16 in_count;
	Z_FAM(zuint8 values[];)
} Z_PACKED_STRUCTURE_END Z_RZXInputRecordingFrame;

/* MARK: - Block union */

typedef union {
	Z_RZXBlockHeader       header;
	Z_RZXCreatorInfo       creator_info;
	Z_RZXSecurityInfo      security_info;
	Z_RZXSecuritySignature security_signature;
	Z_RZXSnapshot	       snapshot;
	Z_RZXInputRecording    input_recording;
} Z_RZXBlock;

#endif /* Z_formats_recording_machine_computer_ZX_Spectrum_RZX_H */
