/* Q Kit API - hardware/machine/platform/arcade/Neo-Geo MVS.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_hardware_machine_platform_arcade_Neo_Geo_MVS_H__
#define __Q_hardware_machine_platform_arcade_Neo_Geo_MVS_H__

#include <Q/types/base.h>

/*    .-------------------------------------------------.
     /							 \
    /							  \
   /		       Cartridge Pinouts		   \
  /							    \
 /		 CHA			    PROG	     \
.--------------------------------------------------------------.
| .----------------------------------------------------------. |
| |		 .-.			     .-.	     | |
| |     GND -01A-|=|-01B- GND        GND-01A-|=|-01B-GND     | |
| |     GND -02A-|=|-02B- GND        GND-02A-|=|-02B-GND     | |
| |      P0 -03A-|=|-03B- P1         GND-03A-|=|-03B-GND     | |
| |      P2 -04A-|=|-04B- P3         GND-04A-|=|-04B-GND     | |
| |      P4 -05A-|=|-05B- P5          D0-05A-|=|-05B-A1      | |
| |      P6 -06A-|=|-06B- P7          D1-06A-|=|-06B-A2      | |
| |      P8 -07A-|=|-07B- P9          D2-07A-|=|-07B-A3      | |
| |     P10 -08A-|=|-08B- P11         D3-08A-|=|-08B-A4      | |
| |     P12 -09A-|=|-09B- P13         D4-09A-|=|-09B-A5      | |
| |     P14 -10A-|=|-10B- P15         D5-10A-|=|-10B-A6      | |
| |     P16 -11A-|=|-11B- P17         D6-11A-|=|-11B-A7      | |
| |     P18 -12A-|=|-12B- P19         D7-12A-|=|-12B-A8      | |
| |     P20 -13A-|=|-13B- P21         D8-13A-|=|-13B-A9      | |
| |     P22 -14A-|=|-14B- P23         D9-14A-|=|-14B-A10     | |
| |   PCK1B -15A-|=|-15B- 24M        D10-15A-|=|-15B-A11     | |
| |   PCK2B -16A-|=|-16B- 12M        D11-16A-|=|-16B-A12     | |
| |     2H1 -17A-|=|-17B- 8M         D12-17A-|=|-17B-A13     | |
| |     CA4 -18A-|=|-18B- RESET      D13-18A-|=|-18B-A14     | |
| |     CR0 -19A-|=|-19B- CR1        D14-19A-|=|-19B-A15     | |
| |     CR2 -20A-|=|-20B- CR3        D15-20A-|=|-20B-A16     | |
| |     CR4 -21A-|=|-21B- CR5        R/W-21A-|=|-21B-A17     | |
| |     CR6 -22A-|=|-22B- CR7         AS-22A-|=|-22B-A18     | |
| |     CR8 -23A-|=|-23B- CR9     ROMOEU-23A-|=|-23B-A19     | |
| |    CR10 -24A-|=|-24B- CR11    ROMOEL-24A-|=|-24B-68KCLKB | |
| |    CR12 -25A-|=|-25B- CR13   PORTOEU-25A-|=|-25B-ROMWAIT | |
| |    CR14 -26A-|=|-26B- CR15   PORTOEL-26A-|=|-26B-PWAIT0  | |
| |    CR16 -27A-|=|-27B- CR17   PORTWEU-27A-|=|-27B-PWAIT1  | |
| |    CR18 -28A-|=|-28B- CR19   PORTWEL-28A-|=|-28B-PDTACT  | |
| |     VCC -29A-|=|-29B- VCC        VCC-29A-|=|-29B-VCC     | |
| |     VCC -30A-|=|-30B- VCC        VCC-30A-|=|-30B-VCC     | |
| |     VCC -31A-|=|-31B- VCC        VCC-31A-|=|-31B-VCC     | |
| |     VCC -32A-|=|-32B- VCC        VCC-32A-|=|-32B-VCC     | |
| |    CR20 -33A-|=|-33B- CR21  PORTADRS-33A-|=|-33B-4MB     | |
| |    CR22 -34A-|=|-34B- CR23        NC-34A-|=|-34B-ROMOE   | |
| |    CR24 -35A-|=|-35B- CR25        NC-35A-|=|-35B-RESET   | |
| |    CR26 -36A-|=|-36B- CR27        NC-36A-|=|-36B-NC      | |
| |    CR28 -37A-|=|-37B- CR29        NC-37A-|=|-37B-NC      | |
| |    CR30 -38A-|=|-38B- CR31        NC-38A-|=|-38B-NC      | |
| |      NC -39A-|=|-39B- FIX00       NC-39A-|=|-39B-NC      | |
| |      NC -40A-|=|-40B- FIX01       NC-40A-|=|-40B-NC      | |
| |      NC -41A-|=|-41B- FIX02       NC-41A-|=|-41B-SDPAD0  | |
| | SYSTEMB -42A-|=|-42B- FIX03  SYSTEMB-42A-|=|-42B-SDPAD1  | |
| |    SDA0 -43A-|=|-43B- FIX04    SDPA8-43A-|=|-43B-SDPAD2  | |
| |    SDA1 -44A-|=|-44B- FIX05    SDPA9-44A-|=|-44B-SDPAD3  | |
| |    SDA2 -45A-|=|-45B- FIX06   SDPA10-45A-|=|-45B-SDPAD4  | |
| |    SDA3 -46A-|=|-46B- FIX07   SDPA11-46A-|=|-46B-SDPAD5  | |
| |    SDA4 -47A-|=|-47B- SDRD0   SDPMPX-47A-|=|-47B-SDPAD6  | |
| |    SDA5 -48A-|=|-48B- SDRD1    SDPOE-48A-|=|-48B-SDPAD7  | |
| |    SDA6 -49A-|=|-49B- SDROM    SDRA8-49A-|=|-49B-SDRA00  | |
| |    SDA7 -50A-|=|-50B- SDMRD    SDRA9-50A-|=|-50B-SDRA01  | |
| |    SDA8 -51A-|=|-51B- SDDO    SDRA20-51A-|=|-51B-SDRA02  | |
| |    SDA9 -52A-|=|-52B- SDD1    SDRA21-52A-|=|-52B-SDRA03  | |
| |   SDA10 -53A-|=|-53B- SDD2    SDRA22-53A-|=|-53B-SDRA04  | |
| |   SDA11 -54A-|=|-54B- SDD3    SDRA23-54A-|=|-54B-SDRA05  | |
| |   SDA12 -55A-|=|-55B- SDD4    SDRMPX-55A-|=|-55B-SDRA06  | |
| |   SDA13 -56A-|=|-56B- SDD5     SDROE-56A-|=|-56B-SDRA07  | |
| |   SDA14 -57A-|=|-57B- SDD6       GND-57A-|=|-57B-GND     | |
| |   SDA15 -58A-|=|-58B- SDD7       GND-58A-|=|-58B-GND     | |
| |     GND -59A-|=|-59B- GND        GND-59A-|=|-59B-GND     | |
| |     GND -60A-|=|-60B- GND        GND-60A-|=|-60B-GND     | |
| |		 '-'			     '-'	     | |
| '----------------------------------------------------------' |
'-------------------------------------------------------------*/

#define Q_NEO_GEO_MMR_P1CNT	0x300000
#define Q_NEO_GEO_MMR_DIPSW	0x300001
#define Q_NEO_GEO_MMR_UNKNOWN_1	0x300080
#define Q_NEO_GEO_MMR_UNKNOWN_2	0x300081
#define Q_NEO_GEO_MMR_UNKNOWN_3	0x31001C
#define Q_NEO_GEO_MMR_SOUND	0x320000
#define Q_NEO_GEO_MMR_STATUS_A	0x320001
#define Q_NEO_GEO_MMR_P2CNT	0x340000
#define Q_NEO_GEO_MMR_STATUS_B	0x380000
#define Q_NEO_GEO_MMR_UNKNOWN_4	0x380030
#define Q_NEO_GEO_MMR_UNKNOWN_5	0x380040
#define Q_NEO_GEO_MMR_SCLKCMD	0x380051
#define Q_NEO_GEO_MMR_UNKNOWN_6	0x380060
#define Q_NEO_GEO_MMR_DISPENABL	0x3A0001
#define Q_NEO_GEO_MMR_SWPBIOS	0x3A0003
#define Q_NEO_GEO_MMR_BRDFIX	0x3A000A
#define Q_NEO_GEO_MMR_SRAMLOCK	0x3A000C
#define Q_NEO_GEO_MMR_PALBANK1	0x3A000E
#define Q_NEO_GEO_MMR_DISPDSABL	0x3A0011
#define Q_NEO_GEO_MMR_SWPROM	0x3A0013
#define Q_NEO_GEO_MMR_CRTFIX	0x3A001A
#define Q_NEO_GEO_MMR_SRAMULOCK	0x3A001C
#define Q_NEO_GEO_MMR_PALBANK0	0x3A001E
#define Q_NEO_GEO_MMR_VRAMADR	0x3C0000
#define Q_NEO_GEO_MMR_VRAMRW	0x3C0002
#define Q_NEO_GEO_MMR_VRAMINC	0x3C0004
#define Q_NEO_GEO_MMR_HBLANKCNT	0x3C0006
#define Q_NEO_GEO_MMR_HBLANKPOS	0x3C0008
#define Q_NEO_GEO_MMR_IRQACK	0x3C000C

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

#endif /* __Q_hardware_machine_platform_arcade_Neo_Geo_MVS_H__ */
