/* Q API - hardware/CPU/x86/Am386DX DXL-40.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2009 RedCode Software.
Released under the terms of the GNU General Public License v2.

   Encapsulation: Ceramic PGA-132

   .-----------------------------.   .-----------------------------.
   |   _____			 |   | o o o o o o o o o o o o o o |
   |   \__  |ADVANCED		 |   | o o o o o o o o o o o o o o |
   |   /|_| |MICRO		 |   | o o o o o o o o o o o o o o |
   |  |___/\|DEVICES		 |   | o o o .-------------. o o o |
   |  Am386™DX/DXL-40		 |   | o o o |             | o o o |
   |  A80386DXL-40		 |   | o o o |  MALAYSIA   | o o o |
   |  A80386DX-33		 |   | o o o |  9240EP W   | o o o |
   |  C 243H5W9			 |   | o o o |  5983C      | o o o |
   |  (m) AMD			 |   | o o o |             | o o o |
   |				 |   | o o o |             | o o o |
   |				 |   | o o o '-------------' o o o |
   |				 |   | o o o o o o o o o o o o o o |
   |				 |   | o o o o o o o o o o o o o o |
   |  23936			 |   | o o o o o o o o o o o o o o |
    '----------------------------'    '----------------------------'
		Front				   Back			*/

#ifndef __Q_hardware_CPU_x86_Am386DX_DXL_40_H__
#define __Q_hardware_CPU_x86_Am386DX_DXL_40_H__

#include <Q/keys/hardware/IC.h>

#define Q_AM386DX_DXL_40_CORE_HZ		40000000
#define Q_AM386DX_DXL_40_FSB_HZ			40000000
#define Q_AM386DX_DXL_40_DATA_BUS_BITS		32
#define Q_AM386DX_DXL_40_ADDRESS_BUS_BITS	32
#define Q_AM386DX_DXL_40_TRANSISTOR_COUNT	275000
#define Q_AM386DX_DXL_40_CIRCUIT_SIZE		1.5 /* µm */
#define Q_AM386DX_DXL_40_VOLTAGE		5.0 /* V  */
#define Q_AM386DX_DXL_40_ENCAPSULATION		Q_IC_ENCAPSULATION_CERAMIC_PGA_132

#endif /* __Q_hardware_CPU_x86_Am386DX_DXL_40_H__ */
