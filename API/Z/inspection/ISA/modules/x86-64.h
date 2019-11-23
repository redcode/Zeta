/* Z Kit - inspection/ISA/modules/x86-64.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//__/__| Kit
Copyright (C) 2006-2020 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_inspection_ISA_modules_x86_64_H
#define Z_inspection_ISA_modules_x86_64_H

#define Z_ISA_NAME			 Z_ISA_NAME_X86_64
#define Z_ISA_HAS_INTEGRAL_8BIT		 TRUE
#define Z_ISA_HAS_INTEGRAL_16BIT	 TRUE
#define Z_ISA_HAS_INTEGRAL_32BIT	 TRUE
#define Z_ISA_HAS_INTEGRAL_64BIT	 TRUE
#define Z_ISA_HAS_REAL_IEEE_754_BINARY32 TRUE
#define Z_ISA_HAS_REAL_IEEE_754_BINARY64 TRUE
#define Z_ISA_INTEGRAL_ENDIANNESS_ALL	 Z_ENDIANNESS_LITTLE
#define Z_ISA_INTEGER_FORMAT_ALL	 Z_INTEGER_FORMAT_2S_COMPLEMENT
#define Z_ISA_BITS_TOP_INTEGRAL		 64
#define Z_ISA_BITS_ADDRESSING		 64

#endif /* Z_inspection_ISA_modules_x86_64_H */
