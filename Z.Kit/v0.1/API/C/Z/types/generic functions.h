/* Z Kit C API - types/generic functions.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_types_generic_functions_H__
#define __Z_types_generic_functions_H__

#include <Z/types/base.h>

/* MARK: - General pourpose context access function types */

typedef void (* ZContextDo    ) (void* context);
typedef void (* ZContextSwitch) (void* context, zboolean state);
typedef void (* ZContextRead  ) (void* context, void* input );
typedef void (* ZContextWrite ) (void* context, void* output);

typedef zuint8	(* ZContextRead8Bit  ) (void* context);
typedef zuint16 (* ZContextRead16Bit ) (void* context);
typedef zuint32 (* ZContextRead32Bit ) (void* context);
typedef void	(* ZContextWrite8Bit ) (void* context, zuint8  value);
typedef void	(* ZContextWrite16Bit) (void* context, zuint16 value);
typedef void	(* ZContextWrite32Bit) (void* context, zuint32 value);
						
typedef zuint8	(* ZContext16BitAddressRead8Bit	 ) (void* context, zuint16 address);
typedef zuint16 (* ZContext16BitAddressRead16Bit ) (void* context, zuint16 address);
typedef zuint32 (* ZContext16BitAddressRead32Bit ) (void* context, zuint16 address);
typedef zuint8	(* ZContext32BitAddressRead8Bit	 ) (void* context, zuint32 address);
typedef zuint16 (* ZContext32BitAddressRead16Bit ) (void* context, zuint32 address);
typedef zuint32 (* ZContext32BitAddressRead32Bit ) (void* context, zuint32 address);
typedef void	(* ZContext16BitAddressWrite8Bit ) (void* context, zuint16 address, zuint8  value);
typedef void	(* ZContext16BitAddressWrite16Bit) (void* context, zuint16 address, zuint16 value);
typedef void	(* ZContext16BitAddressWrite32Bit) (void* context, zuint16 address, zuint32 value);
typedef void	(* ZContext32BitAddressWrite8Bit ) (void* context, zuint32 address, zuint8  value);
typedef void	(* ZContext32BitAddressWrite16Bit) (void* context, zuint32 address, zuint16 value);
typedef void	(* ZContext32BitAddressWrite32Bit) (void* context, zuint32 address, zuint32 value);

#if Z_IS_AVAILABLE(UINT64)
	typedef zuint64 (* ZContextRead64Bit ) (void* context);
	typedef void	(* ZContextWrite64Bit) (void* context, zuint64 value);

	typedef zuint64 (* ZContext16BitAddressRead64Bit ) (void* context, zuint16 address);
	typedef zuint64 (* ZContext32BitAddressRead64Bit ) (void* context, zuint32 address);
	typedef zuint8	(* ZContext64BitAddressRead8Bit	 ) (void* context, zuint64 address);
	typedef zuint16 (* ZContext64BitAddressRead16Bit ) (void* context, zuint64 address);
	typedef zuint32 (* ZContext64BitAddressRead32Bit ) (void* context, zuint64 address);
	typedef zuint64 (* ZContext64BitAddressRead64Bit ) (void* context, zuint64 address);
	typedef void	(* ZContext16BitAddressWrite64Bit) (void* context, zuint16 address, zuint64 value);
	typedef void	(* ZContext32BitAddressWrite64Bit) (void* context, zuint32 address, zuint64 value);
	typedef void	(* ZContext64BitAddressWrite8Bit ) (void* context, zuint64 address, zuint8  value);
	typedef void	(* ZContext64BitAddressWrite16Bit) (void* context, zuint64 address, zuint16 value);
	typedef void	(* ZContext64BitAddressWrite32Bit) (void* context, zuint64 address, zuint32 value);
	typedef void	(* ZContext64BitAddressWrite64Bit) (void* context, zuint64 address, zuint64 value);
#endif

#endif /* __Z_types_generic_functions_H__ */
