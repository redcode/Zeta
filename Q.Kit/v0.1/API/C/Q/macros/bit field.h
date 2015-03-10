/* Q Kit C API - macros/bit field.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_macros_bit_field_H__
#define __Q_macros_bit_field_H__

#include <Q/inspection/CPU.h>
#include <Q/macros/arguments.h>

#if	(Q_CPU_ENDIANNESS			      == Q_ENDIANNESS_LITTLE		&& \
	 Q_COMPILER_LITTLE_ENDIAN_8BIT_FIELD_ENCODING == Q_BIT_FIELD_ENCODING_REVERSED) || \
	(Q_CPU_ENDIANNESS			      == Q_ENDIANNESS_BIG		&& \
	 Q_COMPILER_BIG_ENDIAN_8BIT_FIELD_ENCODING    == Q_BIT_FIELD_ENCODING_LITERAL)

#	define Q_8BIT_FIELD(member_count) Q_JOIN_2(Q_MEMBERIZE_REVERSED_, member_count)

#else
#	define Q_8BIT_FIELD(member_count) Q_JOIN_2(Q_MEMBERIZE_, member_count)
#endif

#if	(Q_CPU_ENDIANNESS			     == Q_ENDIANNESS_LITTLE	       && \
	 Q_COMPILER_LITTLE_ENDIAN_BIT_FIELD_ENCODING == Q_BIT_FIELD_ENCODING_REVERSED) || \
	(Q_CPU_ENDIANNESS			     == Q_ENDIANNESS_BIG	       && \
	 Q_COMPILER_BIG_ENDIAN_BIT_FIELD_ENCODING    == Q_BIT_FIELD_ENCODING_LITERAL)

#	define Q_BIT_FIELD(member_count) Q_JOIN_2(Q_MEMBERIZE_REVERSED_, member_count)
#else
#	define Q_BIT_FIELD(member_count) Q_JOIN_2(Q_MEMBERIZE_, member_count)
#endif

#endif /* __Q_macros_bit_field_H__ */
