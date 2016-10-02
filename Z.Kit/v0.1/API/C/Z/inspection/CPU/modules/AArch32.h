/* Z Kit C API - inspection/modules/CPU/AArch32.h
 _____ 	_______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_|
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_inspection_CPU_modules_AArch32_H__
#define __Z_inspection_CPU_modules_AArch32_H__

#define Z_INSERT_CPU_ARCHITECTURE(left, right) left##AARCH32##right
#define Z_INSERT_CPUArchitecture( left, right) left##AArch32##right
#define Z_INSERT_cpu_architecture(left, right) left##aarch32##right

#define Z_CPU_INTEGER_ENDIANNESS_ALL Z_ENDIANNESS_MIXED
#define Z_CPU_INTEGER_FORMAT_ALL     Z_INTEGER_FORMAT_2S_COMPLEMENT

#define Z_CPU_HAS_MMU TRUE
#define Z_CPU_HAS_FPU TRUE

#define Z_CPU_BITS_TOP_INTEGER 32
#define Z_CPU_BITS_ADDRESSING  32

#endif /* __Z_inspection_CPU_modules_AArch32_H__ */
