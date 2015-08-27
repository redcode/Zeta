/* Z Kit C API - macros/members.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_macros_members_H__
#define __Z_macros_members_H__

#include <Z/inspection/compiler.h>
#include <Z/inspection/CPU.h>
#include <Z/macros/arguments.h>

#if	(Z_CPU_ENDIANNESS			   == Z_ENDIANNESS_LITTLE && \
	 Z_COMPILER_LITTLE_ENDIAN_8BIT_FIELD_ORDER == Z_ORDER_REVERSED)	  || \
	(Z_CPU_ENDIANNESS			   == Z_ENDIANNESS_BIG	  && \
	 Z_COMPILER_BIG_ENDIAN_8BIT_FIELD_ORDER	   == Z_ORDER_NORMAL)

#	define Z_8BIT_FIELD(member_count) Z_MEMBERIZE_REVERSED_##member_count

#else
#	define Z_8BIT_FIELD(member_count) Z_MEMBERIZE_##member_count
#endif

#if	(Z_CPU_ENDIANNESS			  == Z_ENDIANNESS_LITTLE && \
	 Z_COMPILER_LITTLE_ENDIAN_BIT_FIELD_ORDER == Z_ORDER_REVERSED)	 || \
	(Z_CPU_ENDIANNESS			  == Z_ENDIANNESS_BIG	 && \
	 Z_COMPILER_BIG_ENDIAN_BIT_FIELD_ORDER	  == Z_ORDER_NORMAL)

#	define Z_BIT_FIELD(member_count) Z_MEMBERIZE_REVERSED_##member_count
#else
#	define Z_BIT_FIELD(member_count) Z_MEMBERIZE_##member_count
#endif

#define Z_ENDIANIZED_MEMBERS(member_count, BITS)

#endif /* __Z_macros_members_H__ */
