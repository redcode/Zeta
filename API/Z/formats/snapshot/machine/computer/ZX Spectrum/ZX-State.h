/* Zeta API - Z/formats/snapshot/machine/computer/ZX Spectrum/ZX-State.h
 ______ ____________  ___
|__   /|  ___|__  __|/   \
  /  /_|  __|  |  | /  *  \
 /_____|_____| |__|/__/ \__\
Copyright (C) 2006-2023 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.

 _____________________________________________________________
|							      |
|	 Daft: Public.Snapshot.Computer.ZXSpectrum.ZXState    |
|      Author:						      |
|  Extensions: .szx					      |
|  Endianness:						      |
|    Supports:						      |
|     Used by: Spectaculator <https://www.spectaculator.com>  |
|	       Fuse <http://fuse-emulator.sourceforge.net>    |
|							      |
|  Reference:						      |
|  https://www.spectaculator.com/docs/zx-state/intro.shtml    |
|  https://sinclair.wiki.zxnet.co.uk/wiki/ZX-State_format     |
|							      |
'============================================================*/

#ifndef Z_formats_snapshot_machine_computer_ZX_Spectrum_ZX_State_H
#define Z_formats_snapshot_machine_computer_ZX_Spectrum_ZX_State_H

#include <Z/types/bitwise.h>

#define ZX_STATE_BLOCK_ID_ZXATASP
#define ZX_STATE_BLOCK_ID_ZXATASP_RAM
#define ZX_STATE_BLOCK_ID_AY
#define ZX_STATE_BLOCK_ID_ZXCF
#define ZX_STATE_BLOCK_ID_ZXCF_RAM
#define ZX_STATE_BLOCK_ID_
#define ZX_STATE_BLOCK_ID_
#define ZX_STATE_BLOCK_ID_
#define ZX_STATE_BLOCK_ID_
#define ZX_STATE_BLOCK_ID_
#define ZX_STATE_BLOCK_ID_
#define ZX_STATE_BLOCK_ID_
#define ZX_STATE_BLOCK_ID_
#define ZX_STATE_BLOCK_ID_
#define ZX_STATE_BLOCK_ID_
#define ZX_STATE_BLOCK_ID_
#define ZX_STATE_BLOCK_ID_
#define ZX_STATE_BLOCK_ID_
#define ZX_STATE_BLOCK_ID_
#define ZX_STATE_BLOCK_ID_
#define ZX_STATE_BLOCK_ID_
#define ZX_STATE_BLOCK_ID_
#define ZX_STATE_BLOCK_ID_




Z_DEFINE_PACKED_STRUCTURE({
	zuint8 signature;
	zuint8 version_major;
	zuint8 version_minor;
	zuint8 machine_id;
	zuint8 flags;
}, Z_ZXStateHeader);

#define Z_ZX_STATE_MACHINE_ID_16K          0
#define Z_ZX_STATE_MACHINE_ID_48K          1
#define Z_ZX_STATE_MACHINE_ID_128K         2
#define Z_ZX_STATE_MACHINE_ID_PLUS2        3
#define Z_ZX_STATE_MACHINE_ID_PLUS2A       4
#define Z_ZX_STATE_MACHINE_ID_PLUS3        5
#define Z_ZX_STATE_MACHINE_ID_PLUS3E       6
#define Z_ZX_STATE_MACHINE_ID_PENTAGON128  7
#define Z_ZX_STATE_MACHINE_ID_TC2048       8
#define Z_ZX_STATE_MACHINE_ID_TC2068       9
#define Z_ZX_STATE_MACHINE_ID_SCORPION     10
#define Z_ZX_STATE_MACHINE_ID_SE           11
#define Z_ZX_STATE_MACHINE_ID_TS2068       12
#define Z_ZX_STATE_MACHINE_ID_PENTAGON512  13
#define Z_ZX_STATE_MACHINE_ID_PENTAGON1024 14
#define Z_ZX_STATE_MACHINE_ID_NTSC48K      15
#define Z_ZX_STATE_MACHINE_ID_128KE        16

#define ZXSTMF_ALTERNATETIMINGS	1

Z_DEFINE_PACKED_STRUCTURE({
	zuint32 id;
	zuint32 size;
}, Z_ZXStateBlockHeader);



// ZXATASP jumper settings
#define ZXSTAF_UPLOADJUMPER     1
#define ZXSTAF_WRITEPROTECT     2

// ZXATASP IDE interface
Z_DEFINE_PACKED_STRUCTURE_BEGIN {
	zuint16 wFlags;
	zuint8 chPortA;
	zuint8 chPortB;
	zuint8 chPortC;
	zuint8 chControl;
	zuint8 chNumRamPages;
	zuint8 chActivePage;
} Z_DEFINE_PACKED_STRUCTURE_END (Z_ZXStateZXATASP);


// Ram pages are compressed using Zlib
#define ZXSTAF_COMPRESSED       1

// ZXATASP IDE Interface RAM page
Z_DEFINE_PACKED_STRUCTURE_BEGIN {
	zuint16 wFlags;
	zuint8 chPageNo;
	zuint8 chData[1];
} Z_DEFINE_PACKED_STRUCTURE_END (Z_ZXStateZXATASPRAM);

// AY Block flags
#define ZXSTAYF_FULLERBOX  1
#define ZXSTAYF_128AY      2

// AY Block. Contains the AY register values
Z_DEFINE_PACKED_STRUCTURE_BEGIN {
	zuint8 chFlags;
	zuint8 chCurrentRegister;
	zuint8 chAyRegs[16];
} Z_DEFINE_PACKED_STRUCTURE_END (Z_ZXStateAY);

// ZXCF jumper settings
#define ZXSTCF_UPLOADJUMPER     1

// ZXCF CompactFlash interface
Z_DEFINE_PACKED_STRUCTURE_BEGIN {
	zuint16 wFlags;
	zuint8 chMemCtrl;
	zuint8 chNumRamPages;
} Z_DEFINE_PACKED_STRUCTURE_END (Z_ZXStateZXCF);

// Ram pages are compressed using Zlib
#define ZXSTCRF_COMPRESSED       1

// ZXCF CompactFlash Interface RAM page
Z_DEFINE_PACKED_STRUCTURE_BEGIN {
	zuint16 wFlags;
	zuint8 chPageNo;
	zuint8 chData[1];
} Z_DEFINE_PACKED_STRUCTURE_END (Z_ZXStateZXCFRAM);







// Covox state
typedef struct _tagZXSTCOVOX {
	zuint8 chCurrentVolume;
	zuint8 chReserved[3];
} ZXSTCOVOX;







// Beta 128 disk interface used by the Pentagon and Scorpion
#define ZXSTBETAF_CONNECTED   1
#define ZXSTBETAF_CUSTOMROM   2
#define ZXSTBETAF_PAGED       4
#define ZXSTBETAF_AUTOBOOT    8
#define ZXSTBETAF_SEEKLOWER  16
#define ZXSTBETAF_COMPRESSED 32

typedef struct _tagZXSTBETA128 {
	zuint32 dwFlags;
	zuint8 chNumDrives;
	zuint8 chSysReg;
	zuint8 chTrackReg;
	zuint8 chSectorReg;
	zuint8 chDataReg;
	zuint8 chStatusReg;
	zuint8 chRomData[1];
} ZXSTBETA128;








// Beta 128 disk image

// Flags
#define ZXSTBDF_EMBEDDED      1
#define ZXSTBDF_COMPRESSED    2
#define ZXSTBDF_WRITEPROTECT  4

// Disk image types
#define ZXSTBDT_TRD         0
#define ZXSTBDT_SCL         1
#define ZXSTBDT_FDI         2
#define ZXSTBDT_UDI         3

typedef struct _tagZXSTBETADISK {
	zuint32 dwFlags;
	zuint8 chDriveNum;
	zuint8 chCylinder;
	zuint8 chDiskType;
	union {	char szFileName[1];
		zuint8 chDiskImage[1];
	};
} ZXSTBETADISK;







typedef struct _tagZXSTCREATOR {
	char szCreator[32];
	zuint16 chMajorVersion;
	zuint16 chMinorVersion;
	zuint8 chData[1];
} ZXSTCREATOR;







// Ram pages are compressed using Zlib
#define ZXSTDF_COMPRESSED       1
#define ZXSTDF_RAM              2
#define ZXSTDF_EXROMDOCK        3

// Timex Sinclair DOCK memory
typedef struct _tagZXSTDOCK {
	zuint16 wFlags;
	zuint8 chPageNo;
	zuint8 chData[1];
} ZXSTDOCK;









// +3 Disk image
// Each drive that has a disk in it has one of
// these blocks.
#define ZXSTDSKF_COMPRESSED  1
#define ZXSTDSKF_EMBEDDED    2
#define ZXSTDSKF_SIDEB       4

typedef struct _tagZXSTDSKFILE {
	zuint16 wFlags;
	zuint8 chDriveNum;
	zuint32 dwUncompressedSize;
	zuint8 chData[1];
} ZXSTDSKFILE;









// General Sound

// Flags
#define ZXSTZF_EILAST         1
#define ZXSTZF_HALTED         2
#define ZXSTGSF_CUSTOMROM     64
#define ZXSTGSF_COMPRESSED    128

// GS model
#define ZXSTGSM_128   0
#define ZXSTGSM_512   1

typedef struct _tagZXSTGS {
	zuint8 chModel;
	zuint8 chUpperPage;
	zuint8 chGsChanVol[4];
	zuint8 chGsChanOut[4];
	zuint8 chFlags;
	zuint16 AF, BC, DE, HL;
	zuint16 AF1, BC1, DE1, HL1;
	zuint16 IX, IY, SP, PC;
	zuint8 I;
	zuint8 R;
	zuint8 IFF1, IFF2;
	zuint8 IM;
	zuint32 dwCyclesStart;
	zuint8 chHoldIntReqCycles;
	zuint8 chBitReg;
	zuint8 chRomData[1];
} ZXSTGS;










// General Sound 32KB RAM page
// Ram pages are compressed using Zlib
#define ZXSTGSRF_COMPRESSED       1

// 32KB GS Ram page
typedef struct _tagZXSTGSRAMPAGE {
	zuint16 wFlags;
	zuint8 chPageNo;
	zuint8 chData[1];
} ZXSTGSRAMPAGE;









// Keyboard state
#define ZXSTKF_ISSUE2     1

// Supported joystick types
#define ZXSTKJT_KEMPSTON       0
#define ZXSTKJT_FULLER         1
#define ZXSTKJT_CURSOR         2
#define ZXSTKJT_SINCLAIR1      3
#define ZXSTKJT_SINCLAIR2      4
#define ZXSTKJT_SPECTRUMPLUS   5
#define ZXSTKJT_TIMEX1         6
#define ZXSTKJT_TIMEX2         7
#define ZXSTKJT_NONE           8

typedef struct _tagZXSTKEYBOARD {
	Z_ZXStateBlockHeader header;
	zuint32 dwFlags;
	zuint8 chKeyboardJoystick;
} ZXSTKEYBOARD;










// Interface 1
#define ZXSTIF1F_ENABLED     1
#define ZXSTIF1F_COMPRESSED  2
#define ZXSTIF1F_PAGED       4

typedef struct _tagZXSTIF1 {
	zuint16 wFlags;
	zuint8 chNumMicrodrives;
	zuint8  chReserved[3];
	zuint32 dwReserved[8];
	zuint16 wRomSize;
	zuint8 chRomData[1];
} ZXSTIF1;









// Loaded Interface II ROM cart
typedef struct _tagZXSTIF2ROM {
	zuint32 dwCartSize;
	zuint8 chData[1];
} ZXSTIF2ROM;









// Joystick options
#define ZXSTJOYF_ALWAYSPORT31   1    // Deprecated

// Supported joystick types
#define ZXSTJT_KEMPSTON   0
#define ZXSTJT_FULLER     1
#define ZXSTJT_CURSOR     2
#define ZXSTJT_SINCLAIR1  3
#define ZXSTJT_SINCLAIR2  4
#define ZXSTJT_COMCOM     5
#define ZXSTJT_TIMEX1     6
#define ZXSTJT_TIMEX2     7
#define ZXSTJT_DISABLED   8

typedef struct _tagZXSTJOYSTICK {
	zuint32 dwFlags;
	zuint8 chTypePlayer1;
	zuint8 chTypePlayer2;
} ZXSTJOYSTICK;








// Microdrive cartridge
// Each drive that has a cartridge in has one of
// these blocks.
#define ZXSTMDF_COMPRESSED  1
#define ZXSTMDF_EMBEDDED    2

typedef struct _tagZXSTMCART {
	zuint16 wFlags;
	zuint8 chDriveNum;
	zuint8 fDriveRunning;
	zuint16 wDrivePos;
	zuint16 wPreamble;
	zuint32 dwUncompressedSize;
	zuint8 chData[1];
} ZXSTMCART;








// Mouse (currently AMX and Kempston)
#define ZXSTM_NONE      0
#define ZXSTM_AMX       1
#define ZXSTM_KEMPSTON  2

typedef struct _tagZXSTMOUSE {
	zuint8 chType;
	zuint8 chCtrlA[3];
	zuint8 chCtrlB[3];
} ZXSTMOUSE;







// Multiface state
#define ZXSTMF_PAGEDIN            0x01
#define ZXSTMF_COMPRESSED         0x02
#define ZXSTMF_SOFTWARELOCKOUT    0x04
#define ZXSTMF_REDBUTTONDISABLED  0x08
#define ZXSTMF_DISABLED           0x10
#define ZXSTMF_16KRAMMODE         0x20

#define ZXSTMFM_1                 0
#define ZXSTMFM_128               1

typedef struct _tagZXSTMULTIFACE {
	zuint8 ch48kModel;
	zuint8 chFlags;
	zuint8 chData[1];
} ZXSTMULTIFACE;








// Flags
#define ZXSTOPUSF_PAGED        1
#define ZXSTOPUSF_COMPRESSED   2
#define ZXSTOPUSF_SEEKLOWER    4
#define ZXSTOPUSF_CUSTOMROM    8


typedef struct _tagZXSTOPUS {
	zuint32 dwFlags;
	zuint32 dwcbRam;
	zuint32 dwcbRom;
	zuint8 chCtrlRegA;
	zuint8 chPeripheralRegA;
	zuint8 chDataDirRegA;
	zuint8 chCtrlRegB;
	zuint8 chPeripheralRegB;
	zuint8 chDataDirRegB;
	zuint8 chNumDrives;
	zuint8 chTrackReg;
	zuint8 chSectorReg;
	zuint8 chDataReg;
	zuint8 chStatusReg;
	zuint8 chRam[1];
} ZXSTOPUS;






// Associated Opus Discovery disk images

// Disk image types
#define ZXSTOPDT_OPD           0
#define ZXSTOPDT_OPU           1
#define ZXSTOPDT_FLOPPY0       2
#define ZXSTOPDT_FLOPPY1       3

// Flags
#define ZXSTOPDF_EMBEDDED      1
#define ZXSTOPDF_COMPRESSED    2
#define ZXSTOPDF_WRITEPROTECT  4

typedef struct _tagZXSTOPUSDISK {
	zuint32 dwFlags;
	zuint8 chDriveNum;
	zuint8 chCylinder;
	zuint8 chDiskType;
	union {	char szFileName[1];
		zuint8 chDiskImage[1];
	};
} ZXSTOPUSDISK;








// +3 disk drives
typedef struct _tagZXSTPLUS3DISK {
	zuint8 chNumDrives;
	zuint8 fMotorOn;
} ZXSTPLUS3;






// Flags
#define ZXSTPLUSDF_PAGED        1
#define ZXSTPLUSDF_COMPRESSED   2
#define ZXSTPLUSDF_SEEKLOWER    4

// Rom types
#define ZXSTPDRT_GDOS           0
#define ZXSTPDRT_UNIDOS         1
#define ZXSTPDRT_CUSTOM         2

typedef struct _tagZXSTPLUSD {
	zuint32 dwFlags;
	zuint32 dwcbRam;
	zuint32 dwcbRom;
	zuint8 chRomType;
	zuint8 chCtrlReg;
	zuint8 chNumDrives;
	zuint8 chTrackReg;
	zuint8 chSectorReg;
	zuint8 chDataReg;
	zuint8 chStatusReg;
	zuint8 chRam[1];
} ZXSTPLUSD;






// Associated Plus D disk images

// Disk image types
#define ZXSTPDDT_MGT           0
#define ZXSTPDDT_IMG           1
#define ZXSTPDDT_FLOPPY0       2
#define ZXSTPDDT_FLOPPY1       3

// Flags
#define ZXSTPDDF_EMBEDDED      1
#define ZXSTPDDF_COMPRESSED    2
#define ZXSTPDDF_WRITEPROTECT  4

typedef struct _tagZXSTPLUSDDISK {
	zuint32 dwFlags;
	zuint8 chDriveNum;
	zuint8 chCylinder;
	zuint8 chDiskType;
	union {	char szFileName[1];
		zuint8 chDiskImage[1];
	};
} ZXSTPLUSDDISK;







// Ram pages are compressed using Zlib
#define ZXSTRF_COMPRESSED       1

// Standard 16kb Spectrum RAM page
typedef struct _tagZXSTRAMPAGE {
	zuint16 wFlags;
	zuint8 chPageNo;
	zuint8 chData[1];
} ZXSTRAMPAGE;






// Custom ROM for the current model
#define ZXSTRF_COMPRESSED   1

typedef struct _tagZXSTROM {
	zuint16 wFlags;
	zuint32 dwUncompressedSize;
	zuint8 chData[1];
} ZXSTROM;





// Timex Sinclair memory paging and screen modes
typedef struct _tagZXSTSCLDREGS {
	zuint8 chF4;
	zuint8 chFf;
} ZXSTSCLDREGS;







// Simple 8-bit IDE
typedef struct _tagZXSTSIDE {
	Z_ZXStateBlockHeader header;
} ZXSTSIDE;







// SpecDrum state
typedef struct _tagZXSTSPECDRUM {
	Z_ZXStateBlockHeader header;
	zuint8 chCurrentVolume;
} ZXSTSPECDRUM;






typedef struct _tagZXSTSPECREGS {
	Z_ZXStateBlockHeader header;
	zuint8 chBorder;
	zuint8 ch7ffd;
	union {	zuint8 ch1ffd;
		zuint8 chEff7;
	};
	zuint8 chFe;
	zuint8 chReserved[4];
} ZXSTSPECREGS;







// Cassette Recorder state
#define ZXSTTP_EMBEDDED     1
#define ZXSTTP_COMPRESSED   2

typedef struct _tagZXSTTAPE {
	Z_ZXStateBlockHeader header;
	zuint16 wCurrentBlockNo;
	zuint16 wFlags;
	zuint32 dwUncompressedSize;
	zuint32 dwCompressedSize;
	char szFileExtension[16];
	zuint8 chData[1];
} Z_ZXStateTape;







// uSpeech state
typedef struct _tagZXSTUSPEECH {
	Z_ZXStateBlockHeader header;
	zuint8 fPagedIn;
} Z_ZXStateUSpeech;







// ZX Printer
#define ZXSTPRF_ENABLED     1

typedef struct _tagZXSTZXPRINTER {
	Z_ZXStateBlockHeader header;
	zuint16 wFlags;
} Z_ZXStateZXPrinter;






#define ZXSTZF_EILAST	1
#define ZXSTZF_HALTED	2

Z_DEFINE_PACKED_STRUCTURE_BEGIN {
	Z_ZXStateBlockHeader header;
	ZInt16	af, bc, de, hl, af_, bc_, de_, hl_, ix, iy;
	zuint16 sp, pc;
	zuint8	i, r;
	zuint8	iff1, iff2;
	zuint8	im;
	zuint32	frame_cycles;
	zuint8	chHoldIntReqCycles;
	zuint8	chFlags;
	ZInt16	memptr;
} Z_DEFINE_PACKED_STRUCTURE_END (Z_ZXStateCPU);


typedef union {
	Z_ZXStateTape	   tape;
	Z_ZXStateUSpeech   u_speech;
	Z_ZXStateZXPrinter zx_printer;
	Z_ZXStateCPU	   cpu;
} Z_ZXStateBlock;




#endif /* Z_formats_snapshot_machine_computer_ZX_Spectrum_ZX_State_H */
