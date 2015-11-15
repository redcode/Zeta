/* Z Kit C API - hardware/CPU/model/x86/AMD/i80386/Am386DX-40.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.

	      Top			     Bottom
.-----------------------------.  .-----------------------------.
|			      |  | o o o o o o o o o o o o o o |
|    /\ ||||||||||||||| /\    |  | o o o o o o o o o o o o o o |
|    \ '---------------' /    |  | o o o o o o o o o o o o o o |
|   ==|  _____		|==   |  | o o o		 o o o |
|   ==|  \__  |ADVANCED	|==   |  | o o o		 o o o |
|   ==|  /|_| |MICRO	|==   |  | o o o		 o o o |
|   ==| |___/\|DEVICES	|==   |  | o o o		 o o o |
|   ==| Am386™DX-40	|==   |  | o o o		 o o o |
|   ==| NG80386DX-40	|==   |  | o o o		 o o o |
|   ==| D 312NJG8	|==   |  | o o o		 o o o |
|   ==| (m) AMD		|==   |  | o o o		 o o o |
|    / .---------------. \    |  | o o o o o o o o o o o o o o |
|    \/ ||||||||||||||| \/    |  | o o o o o o o o o o o o o o |
|			      |  | o o o o o o o o o o o o o o |
 '----------------------------'   '----------------------------' */

#ifndef __Z_hardware_CPU_model_x86_AMD_i80386_Am386DX_40_H__
#define __Z_hardware_CPU_model_x86_AMD_i80386_Am386DX_40_H__

#include <Z/keys/hardware/IC.h>

#define Z_AM386DX_40_CORE_HZ		40000000
#define Z_AM386DX_40_FSB_HZ		40000000
#define Z_AM386DX_40_DATA_BUS_BITS	32
#define Z_AM386DX_40_ADDRESS_BUS_BITS	32
#define Z_AM386DX_40_TRANSISTOR_COUNT	275000
#define Z_AM386DX_40_CIRCUIT_SIZE	1.5 /* µm */
#define Z_AM386DX_40_VOLTAGE		5.0 /* V  */
#define Z_AM386DX_40_ENCAPSULATION	Z_IC_ENCAPSULATION_PLASTIC_PQFP_132_ON_PGA_132

#endif /* __Z_hardware_CPU_model_x86_AMD_i80386_Am386DX_40_H__ */
