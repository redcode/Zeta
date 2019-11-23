/* Z Kit - keys/ISA.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//__/__| Kit
Copyright (C) 2006-2020 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_keys_ISA_H
#define Z_keys_ISA_H

#define Z_ISA_UNKNOWN	      0
#define Z_ISA_6502	      1 /* MOS Technology		      */
#define Z_ISA_AARCH32	      2 /* Acorn Computers		      */
#define Z_ISA_AARCH64	      3 /* ARM				      */
#define Z_ISA_ALPHA	      4 /* DEC				      */
#define Z_ISA_BLACKFIN	      5 /* Analog Devices		      */
#define Z_ISA_CONVEX	      6 /* Convex Computer		      */
#define Z_ISA_EPIPHANY	      7 /* Adapteva			      */
#define Z_ISA_ESA_370	      8 /* IBM				      */
#define Z_ISA_ESA_390	      9 /* IBM				      */
#define Z_ISA_HEXAGON	     10 /* Qualcomm			      */
#define Z_ISA_ITANIUM	     11 /* Hewlett-Packard / Intel	      */
#define Z_ISA_LANAI	     12 /* Google (?)			      */
#define Z_ISA_M68K	     13 /* Motorola			      */
#define Z_ISA_MIPS	     14 /* MIPS Computer Systems	      */
#define Z_ISA_MIPS64	     15 /* MIPS Computer Systems	      */
#define Z_ISA_MSP430	     16 /* Texas Instruments		      */
#define Z_ISA_PA_RISC	     17 /* Hewlett-Packard		      */
#define Z_ISA_PA_RISC_2	     18 /* Hewlett-Packard		      */
#define Z_ISA_POWERPC_32BIT  19 /* AIM alliance			      */
#define Z_ISA_POWERPC_64BIT  20 /* IBM				      */
#define Z_ISA_RV32E	     21 /* University of California, Berkeley */
#define Z_ISA_RV32I	     22 /* University of California, Berkeley */
#define Z_ISA_RV64I	     23 /* University of California, Berkeley */
#define Z_ISA_RV128I	     24 /* University of California, Berkeley */
#define Z_ISA_SPARC	     25 /* Sun Microsystems		      */
#define Z_ISA_SPARC_V9	     26 /* SPARC International		      */
#define Z_ISA_SUPERH	     27 /* Hitachi			      */
#define Z_ISA_SUPERH_5	     28 /* Hitachi			      */
#define Z_ISA_X86_16	     29 /* Intel			      */
#define Z_ISA_X86_32	     30 /* Intel			      */
#define Z_ISA_X86_64	     31 /* AMD				      */
#define Z_ISA_XCORE	     32 /* XMOS				      */
#define Z_ISA_Z_ARCHITECTURE 33 /* IBM				      */
#define Z_ISA_Z80	     34 /* Zilog			      */

#define Z_ISA_NAME_6502		  "6502"
#define Z_ISA_NAME_AARCH32	  "AArch32"
#define Z_ISA_NAME_AARCH64	  "AArch64"
#define Z_ISA_NAME_ALPHA	  "Alpha"
#define Z_ISA_NAME_BLACKFIN	  "Blackfin"
#define Z_ISA_NAME_CONVEX	  "Convex"
#define Z_ISA_NAME_EPIPHANY	  "Epiphany"
#define Z_ISA_NAME_ESA_370	  "ESA/370"
#define Z_ISA_NAME_ESA_390	  "ESA/390"
#define Z_ISA_NAME_HEXAGON	  "Hexagon"
#define Z_ISA_NAME_ITANIUM	  "Itanium"
#define Z_ISA_NAME_LANAI	  "Lanai"
#define Z_ISA_NAME_M68K		  "M68K"
#define Z_ISA_NAME_MIPS		  "MIPS"
#define Z_ISA_NAME_MIPS64	  "MIPS64"
#define Z_ISA_NAME_MSP430	  "MSP430"
#define Z_ISA_NAME_PA_RISC	  "PA-RISC"
#define Z_ISA_NAME_PA_RISC_2	  "PA-RISC 2.0"
#define Z_ISA_NAME_POWERPC_32BIT  "PowerPC 32-bit"
#define Z_ISA_NAME_POWERPC_64BIT  "PowerPC 64-bit"
#define Z_ISA_NAME_RV32E	  "RV32E"
#define Z_ISA_NAME_RV32I	  "RV32I"
#define Z_ISA_NAME_RV64I	  "RV64I"
#define Z_ISA_NAME_RV128I	  "RV128I"
#define Z_ISA_NAME_SPARC	  "SPARC"
#define Z_ISA_NAME_SPARC_V9	  "SPARC V9"
#define Z_ISA_NAME_SUPERH	  "SuperH"
#define Z_ISA_NAME_SUPERH_5	  "SuperH 5"
#define Z_ISA_NAME_X86_16	  "x86-16"
#define Z_ISA_NAME_X86_32	  "x86-32"
#define Z_ISA_NAME_X86_64	  "x86-64"
#define Z_ISA_NAME_XCORE	  "xCORE"
#define Z_ISA_NAME_Z_ARCHITECTURE "z/Architecture"
#define Z_ISA_NAME_Z80		  "Z80"

#endif /* Z_keys_ISA_H */
