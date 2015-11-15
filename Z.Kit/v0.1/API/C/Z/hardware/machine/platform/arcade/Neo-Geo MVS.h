/* Z Kit C API - hardware/machine/platform/arcade/Neo-Geo MVS.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_hardware_machine_platform_arcade_Neo_Geo_MVS_H__
#define __Z_hardware_machine_platform_arcade_Neo_Geo_MVS_H__

#include <Z/types/base.h>

#define Z_NEO_GEO_MMR_P1CNT	0x300000
#define Z_NEO_GEO_MMR_DIPSW	0x300001
#define Z_NEO_GEO_MMR_UNKNOWN_1	0x300080
#define Z_NEO_GEO_MMR_UNKNOWN_2	0x300081
#define Z_NEO_GEO_MMR_UNKNOWN_3	0x31001C
#define Z_NEO_GEO_MMR_SOUND	0x320000
#define Z_NEO_GEO_MMR_STATUS_A	0x320001
#define Z_NEO_GEO_MMR_P2CNT	0x340000
#define Z_NEO_GEO_MMR_STATUS_B	0x380000
#define Z_NEO_GEO_MMR_UNKNOWN_4	0x380030
#define Z_NEO_GEO_MMR_UNKNOWN_5	0x380040
#define Z_NEO_GEO_MMR_SCLKCMD	0x380051
#define Z_NEO_GEO_MMR_UNKNOWN_6	0x380060
#define Z_NEO_GEO_MMR_DISPENABL	0x3A0001
#define Z_NEO_GEO_MMR_SWPBIOS	0x3A0003
#define Z_NEO_GEO_MMR_BRDFIX	0x3A000A
#define Z_NEO_GEO_MMR_SRAMLOCK	0x3A000C
#define Z_NEO_GEO_MMR_PALBANK1	0x3A000E
#define Z_NEO_GEO_MMR_DISPDSABL	0x3A0011
#define Z_NEO_GEO_MMR_SWPROM	0x3A0013
#define Z_NEO_GEO_MMR_CRTFIX	0x3A001A
#define Z_NEO_GEO_MMR_SRAMULOCK	0x3A001C
#define Z_NEO_GEO_MMR_PALBANK0	0x3A001E
#define Z_NEO_GEO_MMR_VRAMADR	0x3C0000
#define Z_NEO_GEO_MMR_VRAMRW	0x3C0002
#define Z_NEO_GEO_MMR_VRAMINC	0x3C0004
#define Z_NEO_GEO_MMR_HBLANKCNT	0x3C0006
#define Z_NEO_GEO_MMR_HBLANKPOS	0x3C0008
#define Z_NEO_GEO_MMR_IRQACK	0x3C000C

/* RGB Color
.---------------------------------.
| F E D C B A 9 8 7 6 5 4 3 2 1 0 |
'-|-|-|-|-\_____/-\_____/-\_____/-'
.-' | | '----|-------|-------|----------------.
|   | |      |	     |	     '-----------.    |
|   | '------|-------|-------.		 |    |
|   |  .-----'	     |	     |		 |    |
|   '--|----.	     '--.    |		 |    |
|    __|__  |	      __|__  |	       __|__  |
| .-/     \-|---.  .-/     \-|---.  .-/     \-|---.
| | 5 4 3 2 1 0 |  | 5 4 3 2 1 0 |  | 5 4 3 2 1 0 |
| '----- R ---|-'  '----- G ---|-'  '----- B ---|-'
'-------------+----------------'		|
	      '---------------------------------'	*/


/* Sprite Attribute

.---------------------------------.
| F E D C B A 9 8 7 6 5 4 3 2 1 0 |
'-\_____________________________/-'
	  Character Name

.---------------------------------.
| F E D C B A 9 8 7 6 5 4 3 2 1 0 |
'-\_____________/-|-\___/-|-|-|-|-'
	 |	  |   |   | | | '-> X-Flip Enable
	 |	  |   |   | | '---> Y-Flip Enable
	 |	  |   |   | '-----> Unknown
	 |	  |   |   '-------> Unknown
	 |	  |   '-----------> Destination Bank Select
	 |	  '---------------> Unknown
	 '------------------------> Palette Number

Fix Layer Entry
.---------------------------------.
| F E D C B A 9 8 7 6 5 4 3 2 1 0 |
'-\_____/-\_____________________/-'
     |		     '------------> Character Index
     '----------------------------> Color Palette	*/


/*   .------------------------------------------------.
     |  00  |  01  |  02  | .... |  37  |  38  |  39  |
.----+------+------+------+------+------+------+------|
| 00 | 7000 | 7020 | 7040 | .... | 74A0 | 74C0 | 74E0 |
|----|------+------+------+------+------+------+------|
| 01 | 7001 | 7021 | 7041 | .... | 74A1 | 74C1 | 74E1 |
|----|------+------+------+------+------+------+------|
| 02 | 7002 | 7022 | 7042 | .... | 74A2 | 74C2 | 74E2 |
|----|------+------+------+------+------+------+------|
| .. | .... | .... | .... | .... | .... | .... | .... |
|----|------+------+------+------+------+------+------|
| 29 | 701D | 703D | 705D | .... | 74BD | 74DD | 74FD |
|----|------+------+------+------+------+------+------|
| 30 | 701E | 703E | 705E | .... | 74BE | 74DE | 74FE |
|----|------+------+------+------+------+------+------|
| 31 | 701F | 703F | 705F | .... | 74BF | 74DF | 74FF |
'-----------------------------------------------------' */


/* Memory Map


  07000 - 074FF
.----------------------------------------------
| 000000 - 0FFFFF | Cartridge P1 ROM
|-----------------+---------------------------------------
| 100000 - 1FFFFF | Work RAM (64K, mirrored every 64K)
|-----------------+
| 200000 - 2FFFFF | Unused
|-----------------+
| 300000 - 31FFFF | I/O port #1
| 320000 - 33FFFF | I/O port #2
| 340000 - 35FFFF | I/O port #3
| 360000 - 37FFFF | Unused
| 380000 - 39FFFF | I/O port #4
|-----------------+----------------------------------------------------
| 3A0000 - 3BFFFF | Write to set system control latch / Read is unused
| 3C0000 - 3DFFFF | Video registers
| 3E0000 - 3FFFFF | Unused
|-----------------+-------------------------------------------------
| 400000 - 401FFF | Color Palette RAM
| 402000 - 7FFFFF | x511 mirrors of 400000 - 401FFF
|-----------------+-------------------------------------------------

| 800000 - BFFFFF | JEIDA card interface
|-----------------+----------------------------------------------------
| C00000 - C1FFFF | Firmware ROM
| C20000 - CFFFFF | x7 mirrors of C00000 - C1FFFF
|-----------------+----------------------------------------------------
| D00000 - D0FFFF | Save RAM
| D10000 - DFFFFF | x mirrors of D00000 - D0FFFF
|-----------------+------------------------------------------
| E00000 - FFFFFF | Unused
'------------------------------------------------------------


	*/

#endif /* __Z_hardware_machine_platform_arcade_Neo_Geo_MVS_H__ */
