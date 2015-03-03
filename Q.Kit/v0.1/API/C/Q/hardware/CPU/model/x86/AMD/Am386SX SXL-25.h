/* Q Kit API - hardware/CPU/x86/Am386SX SXL-25.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3.

   Encapsulation: Plastic PQFP-100

    /\_|||||||||||||||||_/\
    \  '---------------'  /
   ==|  _____		 |==
   ==|  \__  |ADVANCED	 |==
   ==|  /|_| |MICRO	 |==
   ==| |___/\|DEVICES	 |==
   ==| Am386™SX/SXL-25	 |==
   ==| NG80386SXL-25	 |==
   ==| NG80386SX-25	 |==
   ==| B 1386VE7	 |==
   ==|	 (m) AMD	 |==
    / .-----------------. \
    \/|||||||||||||||||||\/	*/

#ifndef __Q_hardware_CPU_x86_Am386SX_SXL_25_H__
#define __Q_hardware_CPU_x86_Am386SX_SXL_25_H__

#include <Q/keys/hardware/IC.h>

#define Q_AM386SX_SXL_25_CORE_HZ		25000000
#define Q_AM386SX_SXL_25_FSB_HZ			25000000
#define Q_AM386SX_SXL_25_DATA_BUS_BITS		16
#define Q_AM386SX_SXL_25_ADDRESS_BUS_BITS	24
#define Q_AM386SX_SXL_25_TRANSISTOR_COUNT	275000
#define Q_AM386SX_SXL_25_CIRCUIT_SIZE		0.8 /* µm */
#define Q_AM386SX_SXL_25_VOLTAGE		5.0 /* V  */
#define Q_AM386SX_SXL_25_ENCAPSULATION		Q_IC_ENCAPSULATION_PLASTIC_PQFP_100

#endif /* __Q_hardware_CPU_x86_Am386SX_SXL_25_H__ */
