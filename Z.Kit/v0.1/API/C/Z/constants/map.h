/* Z Kit C API - constants/map.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_constants_map_H__
#define __Z_constants_map_H__

#include <Z/types/base.h>

#define Z_SOURCE_BLOCK					 4
#define Z_SOURCE_8BIT					 5
#define Z_SOURCE_16BIT					 6
#define Z_SOURCE_32BIT					 7
#define Z_SOURCE_64BIT					 8
#define Z_SOURCE_FLOAT					 9
#define Z_SOURCE_DOUBLE					10
#define Z_SOURCE_LDOUBLE				11

#if Z_POINTER_BITS == 32
#	define Z_SOURCE_POINTER				Z_SOURCE_32BIT
#elif Z_POINTER_BITS == 64
#	define Z_SOURCE_POINTER				Z_SOURCE_32BIT
#endif

#define Z_CONTENT_ALL					0
#define Z_CONTENT_RANGE					1
#define Z_CONTENT_SELECTION				2
#define Z_CONTENT_ELEMENT				3
#define Z_CONTENT_ELEMENTS				4

#define Z_VALIDATE_VALUE				( 1 << 24)
#define Z_VALIDATE_VALUE_AND_DATA			( 2 << 24)
#define Z_VALIDATE_INDEX				( 3 << 24)
#define Z_VALIDATE_INDEX_AND_DATA			( 4 << 24)
#define Z_VALIDATE_INDEX_AND_VALUE			( 5 << 24)
#define Z_VALIDATE_INDEX_VALUE_AND_DATA			( 6 << 24)
#define Z_VALIDATE_CONTEXT_AND_VALUE			( 7 << 24)
#define Z_VALIDATE_CONTEXT_VALUE_AND_DATA		( 8 << 24)
#define Z_VALIDATE_CONTEXT_AND_INDEX			( 9 << 24)
#define Z_VALIDATE_CONTEXT_INDEX_AND_DATA		(10 << 24)
#define Z_VALIDATE_CONTEXT_INDEX_AND_VALUE		(11 << 24)
#define Z_VALIDATE_CONTEXT_INDEX_VALUE_AND_DATA		(12 << 24)

#define Z_HANDLE_VALUE					( 1 << 20)
#define Z_HANDLE_VALUE_AND_DATA				( 2 << 20)
#define Z_HANDLE_INDEX					( 3 << 20)
#define Z_HANDLE_INDEX_AND_DATA				( 4 << 20)
#define Z_HANDLE_INDEX_AND_VALUE			( 5 << 20)
#define Z_HANDLE_INDEX_VALUE_AND_DATA			( 6 << 20)
#define Z_HANDLE_CONTEXT_AND_VALUE			( 7 << 20)
#define Z_HANDLE_CONTEXT_VALUE_AND_DATA			( 8 << 20)
#define Z_HANDLE_CONTEXT_AND_INDEX			( 9 << 20)
#define Z_HANDLE_CONTEXT_INDEX_AND_DATA			(10 << 20)
#define Z_HANDLE_CONTEXT_INDEX_AND_VALUE		(11 << 20)
#define Z_HANDLE_CONTEXT_INDEX_VALUE_AND_DATA		(12 << 20)

#define Z_DO_HANDLE_VALUE				( 1 << 20)
#define Z_DO_HANDLE_VALUE_AND_DATA			( 2 << 20)
#define Z_DO_HANDLE_INDEX				( 3 << 20)
#define Z_DO_HANDLE_INDEX_AND_DATA			( 4 << 20)
#define Z_DO_HANDLE_INDEX_AND_VALUE			( 5 << 20)
#define Z_DO_HANDLE_INDEX_VALUE_AND_DATA		( 6 << 20)
#define Z_DO_HANDLE_CONTEXT_AND_VALUE			( 7 << 20)
#define Z_DO_HANDLE_CONTEXT_VALUE_AND_DATA		( 8 << 20)
#define Z_DO_HANDLE_CONTEXT_AND_INDEX			( 9 << 20)
#define Z_DO_HANDLE_CONTEXT_INDEX_AND_DATA		(10 << 20)
#define Z_DO_HANDLE_CONTEXT_INDEX_AND_VALUE		(11 << 20)
#define Z_DO_HANDLE_CONTEXT_INDEX_VALUE_AND_DATA	(12 << 20)

#define Z_REVERSE_ORDER					( 1 << 30)
#define Z_END						Z_UINT32(0xFFFFFFFF)

#define Z_CONTENT_MASK					3
#define Z_VALIDATE_MASK					Z_UINT32(0x0F000000)
#define Z_HANDLE_MASK					Z_UINT32(0x00F00000)

#endif /* __Z_constants_map_H__ */
