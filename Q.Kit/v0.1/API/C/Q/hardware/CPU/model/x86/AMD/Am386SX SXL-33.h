/* Q Kit API - hardware/CPU/x86/Am386SX SXL-33.h
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
   ==| Am386™SX/SXL-33	 |==
   ==| NG80386SXL-33	 |==
   ==| NG80386SX-33	 |==
   ==| C 224A3J5	 |==
   ==|	 (m) AMD	 |==
    / .-----------------. \
    \/|||||||||||||||||||\/	*/

#ifndef __Q_hardware_CPU_x86_Am386SX_SXL_33_H__
#define __Q_hardware_CPU_x86_Am386SX_SXL_33_H__

#include <Q/keys/hardware/IC.h>

#define Q_AM386SX_SXL_33_CORE_HZ		33000000
#define Q_AM386SX_SXL_33_FSB_HZ			33000000
#define Q_AM386SX_SXL_33_DATA_BUS_BITS		16
#define Q_AM386SX_SXL_33_ADDRESS_BUS_BITS	24
#define Q_AM386SX_SXL_33_TRANSISTOR_COUNT	275000
#define Q_AM386SX_SXL_33_CIRCUIT_SIZE		0.8 /* µm */
#define Q_AM386SX_SXL_33_VOLTAGE		5.0 /* V  */
#define Q_AM386SX_SXL_33_ENCAPSULATION		Q_IC_ENCAPSULATION_PLASTIC_PQFP_100

#endif /* __Q_hardware_CPU_x86_Am386SX_SXL_33_H__ */
