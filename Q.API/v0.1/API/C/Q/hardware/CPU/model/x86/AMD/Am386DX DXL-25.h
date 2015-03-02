/* Q API - hardware/CPU/x86/Am386DX DXL-25.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3.

   Encapsulation: Ceramic PGA-132

   .-----------------------------.   .-----------------------------.
   |   _____			 |   | o o o o o o o o o o o o o o |
   |   \__  |ADVANCED		 |   | o o o o o o o o o o o o o o |
   |   /|_| |MICRO		 |   | o o o o o o o o o o o o o o |
   |  |___/\|DEVICES		 |   | o o o .-------------. o o o |
   |  Am386™DX/DXL-25		 |   | o o o |             | o o o |
   |  A80386DXL-25		 |   | o o o |  MALAYSIA   | o o o |
   |  A80386DX-25		 |   | o o o |  9129EP W   | o o o |
   |  B 138AKPM			 |   | o o o |  5983B1     | o o o |
   |  (m) AMD			 |   | o o o |             | o o o |
   |				 |   | o o o |             | o o o |
   |				 |   | o o o '-------------' o o o |
   |				 |   | o o o o o o o o o o o o o o |
   |				 |   | o o o o o o o o o o o o o o |
   |  23936			 |   | o o o o o o o o o o o o o o |
    '----------------------------'    '----------------------------'
		Front				   Back			*/

#ifndef __Q_hardware_CPU_x86_Am386DX_DXL_25_H__
#define __Q_hardware_CPU_x86_Am386DX_DXL_25_H__

#include <Q/keys/hardware/IC.h>

#define Q_AM386DX_DXL_25_CORE_HZ		25000000
#define Q_AM386DX_DXL_25_FSB_HZ			25000000
#define Q_AM386DX_DXL_25_DATA_BUS_BITS		32
#define Q_AM386DX_DXL_25_ADDRESS_BUS_BITS	32
#define Q_AM386DX_DXL_25_TRANSISTOR_COUNT	275000
#define Q_AM386DX_DXL_25_CIRCUIT_SIZE		1.5 /* µm */
#define Q_AM386DX_DXL_25_VOLTAGE		5.0 /* V  */
#define Q_AM386DX_DXL_25_ENCAPSULATION		Q_IC_ENCAPSULATION_CERAMIC_PGA_132

#endif /* __Q_hardware_CPU_x86_Am386DX_DXL_25_H__ */
