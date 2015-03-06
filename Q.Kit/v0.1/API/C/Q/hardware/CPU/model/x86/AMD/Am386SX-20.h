/* Q C API - hardware/CPU/x86/Am386SX-20.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.

   Encapsulation: Plastic PQFP-100

    /\_|||||||||||||||||_/\
    \  '---------------'  /
   ==|  _____		 |==
   ==|  \__  |ADVANCED	 |==
   ==|  /|_| |MICRO	 |==
   ==| |___/\|DEVICES	 |==
   ==| Am386™SX-20	 |==
   ==| NG80386SX-20	 |==
   ==| A1 129A587	 |==
   ==|	  (m) AMD	 |==
   ==|			 |==
    / .-----------------. \
    \/|||||||||||||||||||\/	*/

#ifndef __Q_hardware_CPU_x86_Am386SX_20_H__
#define __Q_hardware_CPU_x86_Am386SX_20_H__

#include <Q/keys/hardware/IC.h>

#define Q_AM386SX_20_CORE_HZ		20000000
#define Q_AM386SX_20_FSB_HZ		20000000
#define Q_AM386SX_20_DATA_BUS_BITS	16
#define Q_AM386SX_20_ADDRESS_BUS_BITS	24
#define Q_AM386SX_20_TRANSISTOR_COUNT	275000
#define Q_AM386SX_20_CIRCUIT_SIZE	0.8 /* µm */
#define Q_AM386SX_20_VOLTAGE		5.0 /* V  */
#define Q_AM386SX_20_ENCAPSULATION	Q_IC_ENCAPSULATION_PLASTIC_PQFP_100

#endif /* __Q_hardware_CPU_x86_Am386SX_20_H__ */
