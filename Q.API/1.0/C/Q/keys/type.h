/* Q API - keys/type.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2013 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_keys_type_H__
#define __Q_keys_type_H__

#pragma mark - Standard C types

#define Q_TYPE_POINTER	 0
#define Q_TYPE_UCHAR	 1
#define Q_TYPE_USHORT	 2
#define Q_TYPE_UINT	 3
#define Q_TYPE_ULONG	 4
#define Q_TYPE_ULLONG	 5
#define Q_TYPE_CHAR	 6
#define Q_TYPE_SHORT	 7
#define Q_TYPE_INT	 8
#define Q_TYPE_LONG	 9
#define Q_TYPE_LLONG	10
#define Q_TYPE_FLOAT	11
#define Q_TYPE_DOUBLE	12
#define Q_TYPE_LDOUBLE	13

#pragma mark - Non standard types

#define Q_TYPE_UINT8	14
#define Q_TYPE_UINT16	15
#define Q_TYPE_UINT32	16 /* base type in ILP64 data model only */
#define Q_TYPE_UINT64	17
#define Q_TYPE_UINT128	18
#define Q_TYPE_UINT256	19
#define Q_TYPE_UINT512	20
#define Q_TYPE_UINT1024	21
#define Q_TYPE_INT8	22
#define Q_TYPE_INT16	23
#define Q_TYPE_INT32	24 /* base type in ILP64 data model only */
#define Q_TYPE_INT64	25
#define Q_TYPE_INT128	26
#define Q_TYPE_INT256	27
#define Q_TYPE_INT512	28
#define Q_TYPE_INT1024	29
#define Q_TYPE_SIZE	30
#define Q_TYPE_UINTPTR	31
#define Q_TYPE_UINTTOP	32
#define Q_TYPE_UINTMAX	33
#define Q_TYPE_SSIZE	34
#define Q_TYPE_INTPTR	35
#define Q_TYPE_INTTOP	36
#define Q_TYPE_INTMAX	37
#define Q_TYPE_BOOLEAN	38
#define Q_TYPE_NATURAL	39
#define Q_TYPE_INTEGER	40
#define Q_TYPE_REAL	41

#pragma mark - Last key index

#define Q_LAST_KEY_TYPE Q_TYPE_REAL

#endif /* __Q_keys_type_H__ */
