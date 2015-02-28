/* Q API - constants/map.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2014 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_constants_map_H__
#define __Q_constants_map_H__

#include <Q/types/base.h>

#define Q_SOURCE_BLOCK					 4
#define Q_SOURCE_8BIT					 5
#define Q_SOURCE_16BIT					 6
#define Q_SOURCE_32BIT					 7
#define Q_SOURCE_64BIT					 8
#define Q_SOURCE_FLOAT					 9
#define Q_SOURCE_DOUBLE					10
#define Q_SOURCE_LDOUBLE				11

#if Q_POINTER_BITS == 32
#	define Q_SOURCE_POINTER				Q_SOURCE_32BIT
#elif Q_POINTER_BITS == 64
#	define Q_SOURCE_POINTER				Q_SOURCE_32BIT
#endif

#define Q_CONTENT_ALL					0
#define Q_CONTENT_RANGE					1
#define Q_CONTENT_SELECTION				2
#define Q_CONTENT_ELEMENT				3
#define Q_CONTENT_ELEMENTS				4

#define Q_VALIDATE_VALUE				( 1 << 24)
#define Q_VALIDATE_VALUE_AND_DATA			( 2 << 24)
#define Q_VALIDATE_INDEX				( 3 << 24)
#define Q_VALIDATE_INDEX_AND_DATA			( 4 << 24)
#define Q_VALIDATE_INDEX_AND_VALUE			( 5 << 24)
#define Q_VALIDATE_INDEX_VALUE_AND_DATA			( 6 << 24)
#define Q_VALIDATE_CONTEXT_AND_VALUE			( 7 << 24)
#define Q_VALIDATE_CONTEXT_VALUE_AND_DATA		( 8 << 24)
#define Q_VALIDATE_CONTEXT_AND_INDEX			( 9 << 24)
#define Q_VALIDATE_CONTEXT_INDEX_AND_DATA		(10 << 24)
#define Q_VALIDATE_CONTEXT_INDEX_AND_VALUE		(11 << 24)
#define Q_VALIDATE_CONTEXT_INDEX_VALUE_AND_DATA		(12 << 24)

#define Q_HANDLE_VALUE					( 1 << 20)
#define Q_HANDLE_VALUE_AND_DATA				( 2 << 20)
#define Q_HANDLE_INDEX					( 3 << 20)
#define Q_HANDLE_INDEX_AND_DATA				( 4 << 20)
#define Q_HANDLE_INDEX_AND_VALUE			( 5 << 20)
#define Q_HANDLE_INDEX_VALUE_AND_DATA			( 6 << 20)
#define Q_HANDLE_CONTEXT_AND_VALUE			( 7 << 20)
#define Q_HANDLE_CONTEXT_VALUE_AND_DATA			( 8 << 20)
#define Q_HANDLE_CONTEXT_AND_INDEX			( 9 << 20)
#define Q_HANDLE_CONTEXT_INDEX_AND_DATA			(10 << 20)
#define Q_HANDLE_CONTEXT_INDEX_AND_VALUE		(11 << 20)
#define Q_HANDLE_CONTEXT_INDEX_VALUE_AND_DATA		(12 << 20)

#define Q_DO_HANDLE_VALUE				( 1 << 20)
#define Q_DO_HANDLE_VALUE_AND_DATA			( 2 << 20)
#define Q_DO_HANDLE_INDEX				( 3 << 20)
#define Q_DO_HANDLE_INDEX_AND_DATA			( 4 << 20)
#define Q_DO_HANDLE_INDEX_AND_VALUE			( 5 << 20)
#define Q_DO_HANDLE_INDEX_VALUE_AND_DATA		( 6 << 20)
#define Q_DO_HANDLE_CONTEXT_AND_VALUE			( 7 << 20)
#define Q_DO_HANDLE_CONTEXT_VALUE_AND_DATA		( 8 << 20)
#define Q_DO_HANDLE_CONTEXT_AND_INDEX			( 9 << 20)
#define Q_DO_HANDLE_CONTEXT_INDEX_AND_DATA		(10 << 20)
#define Q_DO_HANDLE_CONTEXT_INDEX_AND_VALUE		(11 << 20)
#define Q_DO_HANDLE_CONTEXT_INDEX_VALUE_AND_DATA	(12 << 20)

#define Q_REVERSE_ORDER					( 1 << 30)
#define Q_END						Q_UINT32(0xFFFFFFFF)

#define Q_CONTENT_MASK					3
#define Q_VALIDATE_MASK					Q_UINT32(0x0F000000)
#define Q_HANDLE_MASK					Q_UINT32(0x00F00000)

#endif /* __Q_constants_map_H__ */
