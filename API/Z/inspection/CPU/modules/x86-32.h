/* Z Kit - inspection/modules/CPU/x86-32.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_inspection_CPU_modules_x86_32_H_
#define _Z_inspection_CPU_modules_x86_32_H_

#define Z_APPEND_CPU_ARCHITECTURE(to)	       to##X86_32
#define Z_APPEND_CPUArchitecture( to)	       to##X8632
#define Z_APPEND_cpu_architecture(to)	       to##x86_32
#define Z_INSERT_CPU_ARCHITECTURE(left, right) left##X86_32##right
#define Z_INSERT_CPUArchitecture( left, right) left##X8632##right
#define Z_INSERT_cpu_architecture(left, right) left##x86_32##right

#define Z_CPU_HAS_MMU			 TRUE
#define Z_CPU_HAS_FPU			 TRUE
#define Z_CPU_HAS_INTEGER_8BIT		 TRUE
#define Z_CPU_HAS_INTEGER_16BIT		 TRUE
#define Z_CPU_HAS_INTEGER_32BIT		 TRUE
#define Z_CPU_HAS_REAL_IEEE_754_BINARY32 TRUE
#define Z_CPU_HAS_REAL_IEEE_754_BINARY64 TRUE

#define Z_CPU_INTEGER_ENDIANNESS Z_ENDIANNESS_LITTLE

#define Z_CPU_BITS_TOP_INTEGER 32
#define Z_CPU_BITS_ADDRESSING  32

#endif /* _Z_inspection_CPU_modules_x86_32_H_ */
