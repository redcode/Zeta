/* Z Kit - inspection/modules/CPU/AArch64.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.

This library is  free software: you can redistribute it  and/or modify it under
the terms  of the GNU  Lesser General Public License  as published by  the Free
Software Foundation, either  version 3 of the License, or  (at your option) any
later version.

This library is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

You should have received  a copy of the GNU Lesser General Public License along
with this library. If not, see <http://www.gnu.org/licenses/>. */

#ifndef _Z_inspection_CPU_modules_AArch64_H_
#define _Z_inspection_CPU_modules_AArch64_H_

#define Z_APPEND_CPU_ARCHITECTURE(to)	       to##AARCH64
#define Z_APPEND_CPUArchitecture( to)	       to##AArch64
#define Z_APPEND_cpu_architecture(to)	       to##aarch64
#define Z_INSERT_CPU_ARCHITECTURE(left, right) left##AARCH64##right
#define Z_INSERT_CPUArchitecture( left, right) left##AArch64##right
#define Z_INSERT_cpu_architecture(left, right) left##aarch64##right

#define Z_CPU_HAS_MMU			 TRUE
#define Z_CPU_HAS_FPU			 TRUE
#define Z_CPU_HAS_INTEGER_8BIT		 TRUE
#define Z_CPU_HAS_INTEGER_16BIT		 TRUE
#define Z_CPU_HAS_INTEGER_32BIT		 TRUE
#define Z_CPU_HAS_INTEGER_64BIT		 TRUE
#define Z_CPU_HAS_REAL_IEEE_754_BINARY32 TRUE
#define Z_CPU_HAS_REAL_IEEE_754_BINARY64 TRUE

#define Z_CPU_INTEGER_ENDIANNESS Z_ENDIANNESS_MIXED
#define Z_CPU_INTEGER_FORMAT	 Z_INTEGER_FORMAT_2S_COMPLEMENT

#define Z_CPU_BITS_TOP_INTEGER 64
#define Z_CPU_BITS_ADDRESSING  64

#endif /* _Z_inspection_CPU_modules_AArch64_H_ */
