/* Z Kit C API - hardware/CPU/model/x86/Am386SX SXL-25.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.

 /\ ||||||||||||||||| /\
 \ '-----------------' /
==|  _____	      |==
==|  \__  |ADVANCED   |==
==|  /|_| |MICRO      |==
==| |___/\|DEVICES    |==
==| Am386™SX/SXL-25   |==
==| NG80386SXL-25     |==
==| NG80386SX-25      |==
==| B 1386VE7	      |==
==|   (m) AMD	      |==
 / .-----------------. \
 \/ ||||||||||||||||| \/ */

#ifndef __Z_hardware_CPU_model_x86_Am386SX_SXL_25_H__
#define __Z_hardware_CPU_model_x86_Am386SX_SXL_25_H__

#include <Z/keys/hardware/IC.h>

#define Z_AM386SX_SXL_25_CORE_HZ		25000000
#define Z_AM386SX_SXL_25_FSB_HZ			25000000
#define Z_AM386SX_SXL_25_DATA_BUS_BITS		16
#define Z_AM386SX_SXL_25_ADDRESS_BUS_BITS	24
#define Z_AM386SX_SXL_25_TRANSISTOR_COUNT	275000
#define Z_AM386SX_SXL_25_CIRCUIT_SIZE		0.8 /* µm */
#define Z_AM386SX_SXL_25_VOLTAGE		5.0 /* V  */
#define Z_AM386SX_SXL_25_ENCAPSULATION		Z_IC_ENCAPSULATION_PLASTIC_PQFP_100

#endif /* __Z_hardware_CPU_model_x86_Am386SX_SXL_25_H__ */
