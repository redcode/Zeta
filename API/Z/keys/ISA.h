/* Zeta API - Z/keys/ISA.h
 ______ ____________  ___
|__   /|  ___|__  __|/   \
  /  /_|  __|  |  | /  *  \
 /_____|_____| |__|/__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_keys_ISA_H
#define Z_keys_ISA_H

#define Z_ISA_UNKNOWN	       0
#define Z_ISA_6502	       1 /* MOS Technology		       */
#define Z_ISA_AARCH32	       2 /* Acorn Computers		       */
#define Z_ISA_AARCH64	       3 /* ARM				       */
#define Z_ISA_ALPHA	       4 /* DEC				       */
#define Z_ISA_ARC	       5 /* ARC International		       */
#define Z_ISA_BLACKFIN	       6 /* Analog Devices		       */
#define Z_ISA_CONVEX	       7 /* Convex Computer		       */
#define Z_ISA_EPIPHANY	       8 /* Adapteva			       */
#define Z_ISA_ESA_370	       9 /* IBM				       */
#define Z_ISA_ESA_390	      10 /* IBM				       */
#define Z_ISA_HEXAGON	      11 /* Qualcomm			       */
#define Z_ISA_IA_64	      12 /* Hewlett-Packard / Intel	       */
#define Z_ISA_LANAI	      13 /* Myricom / Google (?)	       */ /* See: https://q3k.org/lanai.html */
#define Z_ISA_LATTICE_MICO_32 14 /* Lattice Semiconductor	       */
#define Z_ISA_M68K	      15 /* Motorola			       */
#define Z_ISA_MIPS	      16 /* MIPS Computer Systems	       */
#define Z_ISA_MIPS64	      17 /* MIPS Computer Systems	       */
#define Z_ISA_MSP430	      18 /* Texas Instruments		       */
#define Z_ISA_PA_RISC	      19 /* Hewlett-Packard		       */
#define Z_ISA_PA_RISC_2	      20 /* Hewlett-Packard		       */
#define Z_ISA_POWERPC_32BIT   21 /* AIM alliance		       */
#define Z_ISA_POWERPC_64BIT   22 /* IBM				       */
#define Z_ISA_RV32E	      23 /* University of California, Berkeley */
#define Z_ISA_RV32I	      24 /* University of California, Berkeley */
#define Z_ISA_RV64I	      25 /* University of California, Berkeley */
#define Z_ISA_RV128I	      26 /* University of California, Berkeley */
#define Z_ISA_SPARC	      27 /* Sun Microsystems		       */
#define Z_ISA_SPARC_V9	      28 /* SPARC International		       */
#define Z_ISA_SUPERH	      29 /* Hitachi			       */
#define Z_ISA_SUPERH_5	      30 /* Hitachi			       */
#define Z_ISA_VAX	      31 /* DEC				       */
#define Z_ISA_WASM32	      32 /* W3C				       */
#define Z_ISA_WASM64	      33 /* W3C				       */
#define Z_ISA_X86_16	      34 /* Intel			       */
#define Z_ISA_X86_32	      35 /* Intel			       */
#define Z_ISA_X86_64	      36 /* AMD				       */
#define Z_ISA_XCORE	      37 /* XMOS			       */
#define Z_ISA_Z_ARCHITECTURE  38 /* IBM				       */
#define Z_ISA_Z80	      39 /* Zilog			       */

#define Z_ISA_NAME_UNKNOWN	   "unknown ISA"
#define Z_ISA_NAME_6502		   "6502"
#define Z_ISA_NAME_AARCH32	   "AArch32"
#define Z_ISA_NAME_AARCH64	   "AArch64"
#define Z_ISA_NAME_ALPHA	   "Alpha"
#define Z_ISA_NAME_ARC		   "ARC"
#define Z_ISA_NAME_BLACKFIN	   "Blackfin"
#define Z_ISA_NAME_CONVEX	   "Convex"
#define Z_ISA_NAME_EPIPHANY	   "Epiphany"
#define Z_ISA_NAME_ESA_370	   "ESA/370"
#define Z_ISA_NAME_ESA_390	   "ESA/390"
#define Z_ISA_NAME_HEXAGON	   "Hexagon"
#define Z_ISA_NAME_IA_64	   "IA-64"
#define Z_ISA_NAME_LANAI	   "Lanai"
#define Z_ISA_NAME_LATTICE_MICO_32 "LatticeMico32"
#define Z_ISA_NAME_M68K		   "M68K"
#define Z_ISA_NAME_MIPS		   "MIPS"
#define Z_ISA_NAME_MIPS64	   "MIPS64"
#define Z_ISA_NAME_MSP430	   "MSP430"
#define Z_ISA_NAME_PA_RISC	   "PA-RISC"
#define Z_ISA_NAME_PA_RISC_2	   "PA-RISC 2.0"
#define Z_ISA_NAME_POWERPC_32BIT   "PowerPC 32-bit"
#define Z_ISA_NAME_POWERPC_64BIT   "PowerPC 64-bit"
#define Z_ISA_NAME_RV32E	   "RV32E"
#define Z_ISA_NAME_RV32I	   "RV32I"
#define Z_ISA_NAME_RV64I	   "RV64I"
#define Z_ISA_NAME_RV128I	   "RV128I"
#define Z_ISA_NAME_SPARC	   "SPARC"
#define Z_ISA_NAME_SPARC_V9	   "SPARC V9"
#define Z_ISA_NAME_SUPERH	   "SuperH"
#define Z_ISA_NAME_SUPERH_5	   "SuperH 5"
#define Z_ISA_NAME_VAX		   "VAX"
#define Z_ISA_NAME_WASM32	   "Wasm32"
#define Z_ISA_NAME_WASM64	   "Wasm64"
#define Z_ISA_NAME_X86_16	   "x86-16"
#define Z_ISA_NAME_X86_32	   "x86-32"
#define Z_ISA_NAME_X86_64	   "x86-64"
#define Z_ISA_NAME_XCORE	   "xCORE"
#define Z_ISA_NAME_Z_ARCHITECTURE  "z/Architecture"
#define Z_ISA_NAME_Z80		   "Z80"

#endif /* Z_keys_ISA_H */
