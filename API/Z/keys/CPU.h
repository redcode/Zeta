/* Z Kit - keys/CPU.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2019 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_keys_CPU_H_
#define Z_keys_CPU_H_

#define Z_CPU_ARCHITECTURE_UNKNOWN		0
#define Z_CPU_ARCHITECTURE_6502			1 /* MOS Technology			*/
#define Z_CPU_ARCHITECTURE_AARCH32		2 /* Acorn Computers			*/
#define Z_CPU_ARCHITECTURE_AARCH64		3 /* ARM				*/
#define Z_CPU_ARCHITECTURE_ALPHA		4 /* DEC				*/
#define Z_CPU_ARCHITECTURE_BLACKFIN		5 /* Analog Devices			*/
#define Z_CPU_ARCHITECTURE_CONVEX		6 /* Convex Computer			*/
#define Z_CPU_ARCHITECTURE_EPIPHANY		7 /* Adapteva				*/
#define Z_CPU_ARCHITECTURE_ESA_370		8 /* IBM				*/
#define Z_CPU_ARCHITECTURE_ESA_390		9 /* IBM				*/
#define Z_CPU_ARCHITECTURE_HEXAGON	       10 /* Qualcomm				*/
#define Z_CPU_ARCHITECTURE_ITANIUM	       11 /* Hewlett-Packard / Intel		*/
#define Z_CPU_ARCHITECTURE_LANAI	       12 /* Google (?)				*/
#define Z_CPU_ARCHITECTURE_M68K		       13 /* Motorola				*/
#define Z_CPU_ARCHITECTURE_MIPS		       14 /* MIPS Computer Systems		*/
#define Z_CPU_ARCHITECTURE_MIPS64	       15 /* MIPS Computer Systems		*/
#define Z_CPU_ARCHITECTURE_MSP430	       16 /* Texas Instruments			*/
#define Z_CPU_ARCHITECTURE_PA_RISC	       17 /* Hewlett-Packard			*/
#define Z_CPU_ARCHITECTURE_PA_RISC_2	       18 /* Hewlett-Packard			*/
#define Z_CPU_ARCHITECTURE_POWERPC_32BIT       19 /* AIM alliance			*/
#define Z_CPU_ARCHITECTURE_POWERPC_64BIT       20 /* IBM				*/
#define Z_CPU_ARCHITECTURE_RV32E	       21 /* University of California, Berkeley */
#define Z_CPU_ARCHITECTURE_RV32I	       22 /* University of California, Berkeley */
#define Z_CPU_ARCHITECTURE_RV64I	       23 /* University of California, Berkeley */
#define Z_CPU_ARCHITECTURE_RV128I	       24 /* University of California, Berkeley */
#define Z_CPU_ARCHITECTURE_SPARC	       25 /* Sun Microsystems			*/
#define Z_CPU_ARCHITECTURE_SPARC_V9	       26 /* SPARC International		*/
#define Z_CPU_ARCHITECTURE_SUPERH	       27 /* Hitachi				*/
#define Z_CPU_ARCHITECTURE_SUPERH_5	       28 /* Hitachi				*/
#define Z_CPU_ARCHITECTURE_X86_16	       29 /* Intel				*/
#define Z_CPU_ARCHITECTURE_X86_32	       30 /* Intel				*/
#define Z_CPU_ARCHITECTURE_X86_64	       31 /* AMD				*/
#define Z_CPU_ARCHITECTURE_XCORE	       32 /* XMOS				*/
#define Z_CPU_ARCHITECTURE_Z_ARCHITECTURE      33 /* IBM				*/
#define Z_CPU_ARCHITECTURE_Z80		       34 /* Zilog				*/

#define Z_CPU_ARCHITECTURE_NAME_6502	       "6502"
#define Z_CPU_ARCHITECTURE_NAME_AARCH32	       "AArch32"
#define Z_CPU_ARCHITECTURE_NAME_AARCH64	       "AArch64"
#define Z_CPU_ARCHITECTURE_NAME_ALPHA	       "Alpha"
#define Z_CPU_ARCHITECTURE_NAME_BLACKFIN       "Blackfin"
#define Z_CPU_ARCHITECTURE_NAME_CONVEX	       "Convex"
#define Z_CPU_ARCHITECTURE_NAME_EPIPHANY       "Epiphany"
#define Z_CPU_ARCHITECTURE_NAME_ESA_370	       "ESA/370"
#define Z_CPU_ARCHITECTURE_NAME_ESA_390	       "ESA/390"
#define Z_CPU_ARCHITECTURE_NAME_HEXAGON	       "Hexagon"
#define Z_CPU_ARCHITECTURE_NAME_ITANIUM	       "Itanium"
#define Z_CPU_ARCHITECTURE_NAME_LANAI	       "Lanai"
#define Z_CPU_ARCHITECTURE_NAME_M68K	       "M68K"
#define Z_CPU_ARCHITECTURE_NAME_MIPS	       "MIPS"
#define Z_CPU_ARCHITECTURE_NAME_MIPS64	       "MIPS64"
#define Z_CPU_ARCHITECTURE_NAME_MSP430	       "MSP430"
#define Z_CPU_ARCHITECTURE_NAME_PA_RISC	       "PA-RISC"
#define Z_CPU_ARCHITECTURE_NAME_PA_RISC_2      "PA-RISC 2.0"
#define Z_CPU_ARCHITECTURE_NAME_POWERPC_32BIT  "PowerPC 32-bit"
#define Z_CPU_ARCHITECTURE_NAME_POWERPC_64BIT  "PowerPC 64-bit"
#define Z_CPU_ARCHITECTURE_NAME_RV32E	       "RV32E"
#define Z_CPU_ARCHITECTURE_NAME_RV32I	       "RV32I"
#define Z_CPU_ARCHITECTURE_NAME_RV64I	       "RV64I"
#define Z_CPU_ARCHITECTURE_NAME_RV128I	       "RV128I"
#define Z_CPU_ARCHITECTURE_NAME_SPARC	       "SPARC"
#define Z_CPU_ARCHITECTURE_NAME_SPARC_V9       "SPARC V9"
#define Z_CPU_ARCHITECTURE_NAME_SUPERH	       "SuperH"
#define Z_CPU_ARCHITECTURE_NAME_SUPERH_5       "SuperH 5"
#define Z_CPU_ARCHITECTURE_NAME_X86_16	       "x86-16"
#define Z_CPU_ARCHITECTURE_NAME_X86_32	       "x86-32"
#define Z_CPU_ARCHITECTURE_NAME_X86_64	       "x86-64"
#define Z_CPU_ARCHITECTURE_NAME_XCORE	       "xCORE"
#define Z_CPU_ARCHITECTURE_NAME_Z_ARCHITECTURE "z/Architecture"
#define Z_CPU_ARCHITECTURE_NAME_Z80	       "Z80"

#endif /* Z_keys_CPU_H_ */
