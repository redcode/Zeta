/* Q API - macros/pointer.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2013 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_macros_pointer_H__
#define __Q_macros_pointer_H__

#include <Q/types/basics.h>

/* MARK: - Logic operations */

#define Q_POINTER_AND(pointer, value)	(pointer = (void *)( (quintptr)pointer & (value)));
#define Q_POINTER_OR( pointer, value)	(pointer = (void *)( (quintptr)pointer | (value)));
#define Q_POINTER_XOR(pointer, value)	(pointer = (void *)( (quintptr)pointer ^ (value)));
#define Q_POINTER_NOT(pointer)		(pointer = (void *)(~(quintptr)pointer));

/* MARK: - Pointer from base + index */

#define Q_BIP(type, base, index)	(((type)(base)) + (index))

#define Q_UCHAR_BIP(  base, index)	Q_BIP(quchar   *, base, index)
#define Q_USHORT_BIP( base, index)	Q_BIP(qushort  *, base, index)
#define Q_UINT_BIP(   base, index)	Q_BIP(quint    *, base, index)
#define Q_ULONG_BIP(  base, index)	Q_BIP(qulong   *, base, index)
#define Q_ULLONG_BIP( base, index)	Q_BIP(qullong  *, base, index)
#define Q_CHAR_BIP(   base, index)	Q_BIP(qchar    *, base, index)
#define Q_SHORT_BIP(  base, index)	Q_BIP(qshort   *, base, index)
#define Q_INT_BIP(    base, index)	Q_BIP(qint     *, base, index)
#define Q_LONG_BIP(   base, index)	Q_BIP(qlong    *, base, index)
#define Q_LLONG_BIP(  base, index)	Q_BIP(qllong   *, base, index)
#define Q_FLOAT_BIP(  base, index)	Q_BIP(qfloat   *, base, index)
#define Q_DOUBLE_BIP( base, index)	Q_BIP(qdouble  *, base, index)
#define Q_LDOUBLE_BIP(base, index)	Q_BIP(qldouble *, base, index)
#define Q_UINT8_BIP(  base, index)	Q_BIP(quint8   *, base, index)
#define Q_UINT16_BIP( base, index)	Q_BIP(quint16  *, base, index)
#define Q_UINT32_BIP( base, index)	Q_BIP(quint32  *, base, index)
#define Q_UINT64_BIP( base, index)	Q_BIP(quint64  *, base, index)
#define Q_INT8_BIP(   base, index)	Q_BIP(qint8    *, base, index)
#define Q_INT16_BIP(  base, index)	Q_BIP(qint16   *, base, index)
#define Q_INT32_BIP(  base, index)	Q_BIP(qint32   *, base, index)
#define Q_INT64_BIP(  base, index)	Q_BIP(qint64   *, base, index)
#define Q_INT128_BIP( base, index)	Q_BIP(qint128  *, base, index)
#define Q_SIZE_BIP(   base, index)	Q_BIP(qsize    *, base, index)
#define Q_UINTPTR_BIP(base, index)	Q_BIP(quintptr *, base, index)
#define Q_UINTTOP_BIP(base, index)	Q_BIP(quinttop *, base, index)
#define Q_UINTMAX_BIP(base, index)	Q_BIP(quintmax *, base, index)
#define Q_SSIZE_BIP(  base, index)	Q_BIP(qssize   *, base, index)
#define Q_INTPTR_BIP( base, index)	Q_BIP(qintptr  *, base, index)
#define Q_INTTOP_BIP( base, index)	Q_BIP(qinttop  *, base, index)
#define Q_INTMAX_BIP( base, index)	Q_BIP(qintmax  *, base, index)
#define Q_BOOLEAN_BIP(base, index)	Q_BIP(qboolean *, base, index)
#define Q_NATURAL_BIP(base, index)	Q_BIP(qnatural *, base, index)
#define Q_INTEGER_BIP(base, index)	Q_BIP(qinteger *, base, index)
#define Q_REAL_BIP(   base, index)	Q_BIP(qreal	, base, index)

/* MARK: - Pointer from base + offset */

#define Q_BOP(type, base, offset)	((type)(((void *)(base)) + (offset)))

#define Q_UCHAR_BOP(  base, offset)	Q_BOP(quchar   *, base, offset)
#define Q_USHORT_BOP( base, offset)	Q_BOP(qushort  *, base, offset)
#define Q_UINT_BOP(   base, offset)	Q_BOP(quint    *, base, offset)
#define Q_ULONG_BOP(  base, offset)	Q_BOP(qulong   *, base, offset)
#define Q_ULLONG_BOP( base, offset)	Q_BOP(qullong  *, base, offset)
#define Q_CHAR_BOP(   base, offset)	Q_BOP(qchar    *, base, offset)
#define Q_SHORT_BOP(  base, offset)	Q_BOP(qshort   *, base, offset)
#define Q_INT_BOP(    base, offset)	Q_BOP(qint     *, base, offset)
#define Q_LONG_BOP(   base, offset)	Q_BOP(qlong    *, base, offset)
#define Q_LLONG_BOP(  base, offset)	Q_BOP(qllong   *, base, offset)
#define Q_FLOAT_BOP(  base, offset)	Q_BOP(qfloat   *, base, offset)
#define Q_DOUBLE_BOP( base, offset)	Q_BOP(qdouble  *, base, offset)
#define Q_LDOUBLE_BOP(base, offset)	Q_BOP(qldouble *, base, offset)
#define Q_UINT8_BOP(  base, offset)	Q_BOP(quint8   *, base, offset)
#define Q_UINT16_BOP( base, offset)	Q_BOP(quint16  *, base, offset)
#define Q_UINT32_BOP( base, offset)	Q_BOP(quint32  *, base, offset)
#define Q_UINT64_BOP( base, offset)	Q_BOP(quint64  *, base, offset)
#define Q_INT8_BOP(   base, offset)	Q_BOP(qint8    *, base, offset)
#define Q_INT16_BOP(  base, offset)	Q_BOP(qint16   *, base, offset)
#define Q_INT32_BOP(  base, offset)	Q_BOP(qint32   *, base, offset)
#define Q_INT64_BOP(  base, offset)	Q_BOP(qint64   *, base, offset)
#define Q_INT128_BOP( base, offset)	Q_BOP(qint128  *, base, offset)
#define Q_SIZE_BOP(   base, offset)	Q_BOP(qsize    *, base, offset)
#define Q_UINTPTR_BOP(base, offset)	Q_BOP(quintptr *, base, offset)
#define Q_UINTTOP_BOP(base, offset)	Q_BOP(quinttop *, base, offset)
#define Q_UINTMAX_BOP(base, offset)	Q_BOP(quintmax *, base, offset)
#define Q_SSIZE_BOP(  base, offset)	Q_BOP(qssize   *, base, offset)
#define Q_INTPTR_BOP( base, offset)	Q_BOP(qintptr  *, base, offset)
#define Q_INTTOP_BOP( base, offset)	Q_BOP(qinttop  *, base, offset)
#define Q_INTMAX_BOP( base, offset)	Q_BOP(qintmax  *, base, offset)
#define Q_BOOLEAN_BOP(base, offset)	Q_BOP(qboolean *, base, offset)
#define Q_NATURAL_BOP(base, offset)	Q_BOP(qnatural *, base, offset)
#define Q_INTEGER_BOP(base, offset)	Q_BOP(qinteger *, base, offset)
#define Q_REAL_BOP(   base, offset)	Q_BOP(qreal	, base, offset)

/* MARK: - Index from base calculations */

#define Q_INDEX(type, base, pointer)		 ((qsize)(((quintptr)pointer - (quintptr)base) / sizeof(type)))
#define Q_BLOCK_INDEX(base, pointer, block_size) ((qsize)(((quintptr)pointer - (quintptr)base) / block_size))

#endif /* __Q_macros_pointer_H__ */
