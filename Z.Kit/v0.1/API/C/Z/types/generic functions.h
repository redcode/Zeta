/* Z Kit C API - types/generic functions.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_types_generic_functions_H__
#define __Z_types_generic_functions_H__

#include <Z/macros/templating.h>

/* MARK: - General pourpose context access function types */

typedef void (* ZDo) (void* context);

typedef void (* ZSwitch) (void* context, zboolean state);

typedef void (* ZRead ) (void* context, void* input );
typedef void (* ZWrite) (void* context, void* output);

typedef zuint8	(* Z16BitAddressRead8Bit ) (void* context, zuint16 address);
typedef zuint16 (* Z16BitAddressRead16Bit) (void* context, zuint16 address);
typedef zuint32 (* Z16BitAddressRead32Bit) (void* context, zuint16 address);
typedef zuint64 (* Z16BitAddressRead64Bit) (void* context, zuint16 address);

typedef void (* Z16BitAddressWrite8Bit ) (void* context, zuint16 address, zuint8  value);
typedef void (* Z16BitAddressWrite16Bit) (void* context, zuint16 address, zuint16 value);
typedef void (* Z16BitAddressWrite32Bit) (void* context, zuint16 address, zuint32 value);
typedef void (* Z16BitAddressWrite64Bit) (void* context, zuint16 address, zuint64 value);

typedef zuint8	(* Z32BitAddressRead8Bit ) (void* context, zuint32 address);
typedef zuint16 (* Z32BitAddressRead16Bit) (void* context, zuint32 address);
typedef zuint32 (* Z32BitAddressRead32Bit) (void* context, zuint32 address);
typedef zuint64 (* Z32BitAddressRead64Bit) (void* context, zuint32 address);

typedef void (* Z32BitAddressWrite8Bit ) (void* context, zuint32 address, zuint8  value);
typedef void (* Z32BitAddressWrite16Bit) (void* context, zuint32 address, zuint16 value);
typedef void (* Z32BitAddressWrite32Bit) (void* context, zuint32 address, zuint32 value);
typedef void (* Z32BitAddressWrite64Bit) (void* context, zuint32 address, zuint64 value);

typedef zuint8	(* Z64BitAddressRead8Bit ) (void* context, zuint32 address);
typedef zuint16 (* Z64BitAddressRead16Bit) (void* context, zuint32 address);
typedef zuint32 (* Z64BitAddressRead32Bit) (void* context, zuint32 address);
typedef zuint64 (* Z64BitAddressRead64Bit) (void* context, zuint32 address);

typedef void (* Z64BitAddressWrite8Bit ) (void* context, zuint32 index, zuint8  value);
typedef void (* Z64BitAddressWrite16Bit) (void* context, zuint32 index, zuint16 value);
typedef void (* Z64BitAddressWrite32Bit) (void* context, zuint32 index, zuint32 value);
typedef void (* Z64BitAddressWrite64Bit) (void* context, zuint32 index, zuint64 value);

typedef zuint8	(* ZRead8Bit ) (void* context);
typedef zuint16 (* ZRead16Bit) (void* context);
typedef zuint32 (* ZRead32Bit) (void* context);
typedef zuint64 (* ZRead64Bit) (void* context);

typedef void (* ZWrite8Bit ) (void* context, zuint8  value);
typedef void (* ZWrite16Bit) (void* context, zuint16 value);
typedef void (* ZWrite32Bit) (void* context, zuint32 value);
typedef void (* ZWrite64Bit) (void* context, zuint64 value);

/* MARK: - General pourpose function types */

typedef void	 (* ZCopy)		     (void*  context,
					      void*  output);
	
typedef void	 (* ZCopyData)		     (void*  context,
					      zsize  data_size,
					      void*  output);

typedef zsize	 (* ZCopyAndSize)	     (void*  context,
					      void*  output);

typedef zsize	 (* ZCopyDataAndSize)	     (void*  context,
					      zsize  data_size,
					      void*  output);

typedef void	 (* ZCopyRange)		     (void*  context,
					      ZRange range,
					      void*  output);

typedef void	 (* ZCopyRangeData)	     (void*  context,
					      ZRange range,
					      zsize  data_size,
					      void*  output);

typedef void	 (* ZBoundedCopy)	     (void*  context_start,
					      void*  context_end,
					      void*  output);

typedef void	 (* ZBoundedCopyData)	     (void*  context_start,
					      void*  context_end,
					      zsize  data_size,
					      void*  output);

typedef zsize	 (* ZBoundedCopyAndSize)     (void*  context_start,
					      void*  context_end,
					      void*  output);

typedef zsize	 (* ZBoundedCopyDataAndSize) (void*  context_start,
					      void*  context_end,
					      zsize  data_size,
					      void*  output);

typedef void	 (* ZBoundedCopyRange)	     (void*  context_start,
					      void*  context_end,
					      void*  context_size,
					      ZRange range,
					      void*  output);

typedef void	 (* ZBoundedCopyRangeData)   (void*  context_start,
					      void*  context_end,
					      void*  context_size,
					      ZRange range,
					      zsize  data_size,
					      void*  output);

typedef void	 (* ZCopyMany)		     (void*  context,
					      zuint  count,
					      void*  output);

typedef void	 (* ZSkipOne)		     (void*  input);

typedef void	 (* ZSkipMany)		     (void*  input,
					      zuint  count);

typedef void	 (* ZSwapHalves)	     (void*  context);

typedef zsize	 (* ZSize)		     (void*  context);

typedef void*	 (* ZElement)		     (void*  context,
					      zsize  index);

typedef void	 (* ZSetElement)	     (void*  context,
					      zsize  index,
					      void*  value);

typedef void	 (* ZMoveElement)	     (void*  context,
					      zsize  old_index,
					      zsize  new_index);

typedef zint	 (* ZCompareElements)	     (void*  context,
					      zsize  a_index,
					      zsize  b_index);

typedef void	 (* ZSwapElements)	     (void*  context,
					      zsize  a_index,
					      zsize  b_index);

typedef zboolean (* ZIsValid)		     (void*  context);

typedef zboolean (* ZAreEzual)		     (void*  a,
					      void*  b);

typedef zboolean (* ZAreEzualWithData)	     (void*  a,
					      void*  b,
					      void*  data);

typedef zint	 (* ZCompare)		     (void*  a,
					      void*  b);

typedef zint	 (* ZCompareWithData)	     (void*  a,
					      void*  b,
					      void*  data);

typedef void	 (* ZSwap)		     (void*  a,
					      void*  b);

#endif /* __Z_types_generic_functions_H__ */
