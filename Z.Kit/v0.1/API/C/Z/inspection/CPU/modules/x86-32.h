/* Z Kit C API - inspection/completions/CPU/x86-32.h
	      ___
 _____	____ /	/______
/_   /_/  -_)  __/  _ /
 /____/\___/\__/ \__,_/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_inspection_CPU_modules_x86_32_H__
#define __Z_inspection_CPU_modules_x86_32_H__

#define Z_INSERT_CPU_ARCHITECTURE(left, right) left##X86_32##right
#define Z_INSERT_CPUArchitecture( left, right) left##X8632##right
#define Z_INSERT_cpu_architecture(left, right) left##x86_32##right

#define Z_CPU_INTEGER_ENDIANNESS_ALL Z_ENDIANNESS_LITTLE
#define Z_CPU_INTEGER_FORMAT_ALL     Z_INTEGER_FORMAT_2S_COMPLEMENT

#define Z_CPU_LIMIT_MINIMUM_LOAD_BITS  8
#define Z_CPU_LIMIT_MINIMUM_STORE_BITS 8
#define Z_CPU_LIMIT_MINIMUM_COPY_BITS  8
#define Z_CPU_LIMIT_MAXIMUM_LOAD_BITS  64
#define Z_CPU_LIMIT_MAXIMUM_STORE_BITS 64
#define Z_CPU_LIMIT_MAXIMUM_COPY_BITS  64

#define Z_CPU_ARCHITECTURE_HAS_MMU TRUE
#define Z_CPU_ARCHITECTURE_HAS_FPU TRUE

#endif /* __Z_inspection_CPU_modules_x86_32_H__ */
