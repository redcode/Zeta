/* Z Kit - inspection/modules/CPU/Z80.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_inspection_CPU_modules_Z80_H_
#define _Z_inspection_CPU_modules_Z80_H_

#define Z_APPEND_CPU_ARCHITECTURE(to)	       to##Z80
#define Z_APPEND_CPUArchitecture( to)	       to##Z80
#define Z_APPEND_cpu_architecture(to)	       to##z80
#define Z_INSERT_CPU_ARCHITECTURE(left, right) left##Z80##right
#define Z_INSERT_CPUArchitecture( left, right) left##Z80##right
#define Z_INSERT_cpu_architecture(left, right) left##z80##right

#define Z_CPU_HAS_INTEGER_8BIT	TRUE
#define Z_CPU_HAS_INTEGER_16BIT TRUE

#define Z_CPU_INTEGER_ENDIANNESS Z_ENDIANNESS_LITTLE

#define Z_CPU_BITS_TOP_INTEGER 16
#define Z_CPU_BITS_ADDRESSING  16

#endif /* _Z_inspection_CPU_modules_Z80_H_ */
