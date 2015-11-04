/* Z Kit C API - hardware/CPU/x86/Am386DX-33.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3.

	      Top			     Bottom
.-----------------------------.  .-----------------------------.
|   _____		      |  | o o o o o o o o o o o o o o |
|   \__  |ADVANCED	      |  | o o o o o o o o o o o o o o |
|   /|_| |MICRO		      |  | o o o o o o o o o o o o o o |
|  |___/\|DEVICES	      |  | o o o .-------------. o o o |
|  Am386™DX-33		      |  | o o o |	       | o o o |
|  A80386DX-33		      |  | o o o |  MALAYSIA   | o o o |
|  B 11ON99A		      |  | o o o |  9109CP W   | o o o |
|  (m) AMD		      |  | o o o |  5983       | o o o |
|			      |  | o o o |	       | o o o |
|			      |  | o o o |	       | o o o |
|			      |  | o o o '-------------' o o o |
|			      |  | o o o o o o o o o o o o o o |
|			      |  | o o o o o o o o o o o o o o |
|  23936		      |  | o o o o o o o o o o o o o o |
 '----------------------------'   '----------------------------' */

#ifndef __Z_hardware_CPU_x86_Am386DX_33_H__
#define __Z_hardware_CPU_x86_Am386DX_33_H__

#include <Z/keys/hardware/IC.h>

#define Z_AM386DX_33_CORE_HZ		33000000
#define Z_AM386DX_33_FSB_HZ		33000000
#define Z_AM386DX_33_DATA_BUS_BITS	32
#define Z_AM386DX_33_ADDRESS_BUS_BITS	32
#define Z_AM386DX_33_TRANSISTOR_COUNT	275000
#define Z_AM386DX_33_CIRCUIT_SIZE	1.5 /* µm */
#define Z_AM386DX_33_VOLTAGE		5.0 /* V  */
#define Z_AM386DX_33_ENCAPSULATION	Z_IC_ENCAPSULATION_CERAMIC_PGA_132

#endif /* __Z_hardware_CPU_x86_Am386DX_33_H__ */
