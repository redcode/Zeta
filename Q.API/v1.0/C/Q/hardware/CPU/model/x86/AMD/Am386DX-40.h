/* Q API - hardware/CPU/x86/Am386DX-40.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2014 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3.

   Encapsulation: Plastic PQFP-132 on PGA-132

   .-----------------------------.   .-----------------------------.
   |				 |   | o o o o o o o o o o o o o o |
   |	/\_|||||||||||||||_/\	 |   | o o o o o o o o o o o o o o |
   |	\  '-------------'  /	 |   | o o o o o o o o o o o o o o |
   |   ==|  _____          |==	 |   | o o o		     o o o |
   |   ==|  \__  |ADVANCED |==	 |   | o o o		     o o o |
   |   ==|  /|_| |MICRO    |==	 |   | o o o		     o o o |
   |   ==| |___/\|DEVICES  |==	 |   | o o o		     o o o |
   |   ==| Am386™DX-40     |==	 |   | o o o		     o o o |
   |   ==| NG80386DX-40    |==	 |   | o o o		     o o o |
   |   ==| D 312NJG8       |==	 |   | o o o		     o o o |
   |   ==| (m) AMD         |==	 |   | o o o		     o o o |
   |	/ .---------------. \	 |   | o o o o o o o o o o o o o o |
   |	\/|||||||||||||||||\/	 |   | o o o o o o o o o o o o o o |
   |				 |   | o o o o o o o o o o o o o o |
    '----------------------------'    '----------------------------'
		Front				   Back			*/

#ifndef __Q_hardware_CPU_x86_Am386DX_40_H__
#define __Q_hardware_CPU_x86_Am386DX_40_H__

#include <Q/keys/hardware/IC.h>

#define Q_AM386DX_40_CORE_HZ		40000000
#define Q_AM386DX_40_FSB_HZ		40000000
#define Q_AM386DX_40_DATA_BUS_BITS	32
#define Q_AM386DX_40_ADDRESS_BUS_BITS	32
#define Q_AM386DX_40_TRANSISTOR_COUNT	275000
#define Q_AM386DX_40_CIRCUIT_SIZE	1.5 /* µm */
#define Q_AM386DX_40_VOLTAGE		5.0 /* V  */
#define Q_AM386DX_40_ENCAPSULATION	Q_IC_ENCAPSULATION_PLASTIC_PQFP_132_ON_PGA_132

#endif /* __Q_hardware_CPU_x86_Am386DX_40_H__ */
