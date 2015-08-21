/* Z Kit C API - types/generic functions.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_types_generic_functions_H__
#define __Z_types_generic_functions_H__

#include <Z/types/base.h>

/* MARK: - General pourpose context access function types */

typedef void	(* ZDo)			    (void* context);
typedef void	(* ZSwitch)		    (void* context, zboolean state);

typedef void	(* ZRead)		    (void* context, void* input );
typedef void	(* ZWrite)		    (void* context, void* output);

typedef zuint8	(* Z16BitAddressRead8Bit )  (void* context, zuint16 address);
typedef zuint16 (* Z16BitAddressRead16Bit)  (void* context, zuint16 address);
typedef zuint32 (* Z16BitAddressRead32Bit)  (void* context, zuint16 address);
typedef zuint64 (* Z16BitAddressRead64Bit)  (void* context, zuint16 address);

typedef void	(* Z16BitAddressWrite8Bit ) (void* context, zuint16 address, zuint8  value);
typedef void	(* Z16BitAddressWrite16Bit) (void* context, zuint16 address, zuint16 value);
typedef void	(* Z16BitAddressWrite32Bit) (void* context, zuint16 address, zuint32 value);
typedef void	(* Z16BitAddressWrite64Bit) (void* context, zuint16 address, zuint64 value);

typedef zuint8	(* Z32BitAddressRead8Bit )  (void* context, zuint32 address);
typedef zuint16 (* Z32BitAddressRead16Bit)  (void* context, zuint32 address);
typedef zuint32 (* Z32BitAddressRead32Bit)  (void* context, zuint32 address);
typedef zuint64 (* Z32BitAddressRead64Bit)  (void* context, zuint32 address);

typedef void	(* Z32BitAddressWrite8Bit ) (void* context, zuint32 address, zuint8  value);
typedef void	(* Z32BitAddressWrite16Bit) (void* context, zuint32 address, zuint16 value);
typedef void	(* Z32BitAddressWrite32Bit) (void* context, zuint32 address, zuint32 value);
typedef void	(* Z32BitAddressWrite64Bit) (void* context, zuint32 address, zuint64 value);

typedef zuint8	(* Z64BitAddressRead8Bit )  (void* context, zuint32 address);
typedef zuint16 (* Z64BitAddressRead16Bit)  (void* context, zuint32 address);
typedef zuint32 (* Z64BitAddressRead32Bit)  (void* context, zuint32 address);
typedef zuint64 (* Z64BitAddressRead64Bit)  (void* context, zuint32 address);

typedef void	(* Z64BitAddressWrite8Bit ) (void* context, zuint32 index, zuint8  value);
typedef void	(* Z64BitAddressWrite16Bit) (void* context, zuint32 index, zuint16 value);
typedef void	(* Z64BitAddressWrite32Bit) (void* context, zuint32 index, zuint32 value);
typedef void	(* Z64BitAddressWrite64Bit) (void* context, zuint32 index, zuint64 value);

typedef zuint8	(* ZRead8Bit )		    (void* context);
typedef zuint16 (* ZRead16Bit)		    (void* context);
typedef zuint32 (* ZRead32Bit)		    (void* context);
typedef zuint64 (* ZRead64Bit)		    (void* context);

typedef void	(* ZWrite8Bit )		    (void* context, zuint8  value);
typedef void	(* ZWrite16Bit)		    (void* context, zuint16 value);
typedef void	(* ZWrite32Bit)		    (void* context, zuint32 value);
typedef void	(* ZWrite64Bit)		    (void* context, zuint64 value);

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

/* MARK: - Generic handler types */

typedef void (* ZHandleUInt8  )			   (zuint8   value  );
typedef void (* ZHandleUInt16 )			   (zuint16  value  );
typedef void (* ZHandleUInt32 )			   (zuint32  value  );
typedef void (* ZHandleUInt64 )			   (zuint64  value  );
typedef void (* ZHandleInt8   )			   (zint8    value  );
typedef void (* ZHandleInt16  )			   (zint16   value  );
typedef void (* ZHandleInt32  )			   (zint32   value  );
typedef void (* ZHandleInt64  )			   (zint64   value  );
typedef void (* ZHandleFloat  )			   (zfloat   value  );
typedef void (* ZHandleDouble )			   (zdouble  value  );
typedef void (* ZHandleLDouble)			   (zldouble value  );
typedef void (* ZHandlePointer)			   (void*    pointer);

typedef void (* ZHandleUInt8AndData  )		   (zuint8   value,   void* data);
typedef void (* ZHandleUInt16AndData )		   (zuint16  value,   void* data);
typedef void (* ZHandleUInt32AndData )		   (zuint32  value,   void* data);
typedef void (* ZHandleUInt64AndData )		   (zuint64  value,   void* data);
typedef void (* ZHandleInt8AndData   )		   (zint8    value,   void* data);
typedef void (* ZHandleInt16AndData  )		   (zint16   value,   void* data);
typedef void (* ZHandleInt32AndData  )		   (zint32   value,   void* data);
typedef void (* ZHandleInt64AndData  )		   (zint64   value,   void* data);
typedef void (* ZHandleFloatAndData  )		   (zfloat   value,   void* data);
typedef void (* ZHandleDoubleAndData )		   (zdouble  value,   void* data);
typedef void (* ZHandleLDoubleAndData)		   (zldouble value,   void* data);
typedef void (* ZHandlePointerAndData)		   (void*    pointer, void* data);

typedef void (* ZHandleIndex	   )		   (zsize index		   );
typedef void (* ZHandleIndexAndData)		   (zsize index, void *data);

typedef void (* ZHandleIndexAndUInt8  )		   (zsize index, zuint8   value  );
typedef void (* ZHandleIndexAndUInt16 )		   (zsize index, zuint16  value  );
typedef void (* ZHandleIndexAndUInt32 )		   (zsize index, zuint32  value  );
typedef void (* ZHandleIndexAndUInt64 )		   (zsize index, zuint64  value  );
typedef void (* ZHandleIndexAndInt8   )		   (zsize index, zint8    value  );
typedef void (* ZHandleIndexAndInt16  )		   (zsize index, zint16   value  );
typedef void (* ZHandleIndexAndInt32  )		   (zsize index, zint32   value  );
typedef void (* ZHandleIndexAndInt64  )		   (zsize index, zint64   value  );
typedef void (* ZHandleIndexAndFloat  )		   (zsize index, zfloat   value  );
typedef void (* ZHandleIndexAndDouble )		   (zsize index, zdouble  value  );
typedef void (* ZHandleIndexAndLDouble)		   (zsize index, zldouble value  );
typedef void (* ZHandleIndexAndPointer)		   (zsize index, void*    pointer);

typedef void (* ZHandleIndexUInt8AndData  )	   (zsize index, zuint8   value,   void* data);
typedef void (* ZHandleIndexUInt16AndData )	   (zsize index, zuint16  value,   void* data);
typedef void (* ZHandleIndexUInt32AndData )	   (zsize index, zuint32  value,   void* data);
typedef void (* ZHandleIndexUInt64AndData )	   (zsize index, zuint64  value,   void* data);
typedef void (* ZHandleIndexInt8AndData   )	   (zsize index, zint8    value,   void* data);
typedef void (* ZHandleIndexInt16AndData  )	   (zsize index, zint16   value,   void* data);
typedef void (* ZHandleIndexInt32AndData  )	   (zsize index, zint32   value,   void* data);
typedef void (* ZHandleIndexInt64AndData  )	   (zsize index, zint64   value,   void* data);
typedef void (* ZHandleIndexFloatAndData  )	   (zsize index, zfloat   value,   void* data);
typedef void (* ZHandleIndexDoubleAndData )	   (zsize index, zdouble  value,   void* data);
typedef void (* ZHandleIndexLDoubleAndData)	   (zsize index, zldouble value,   void* data);
typedef void (* ZHandleIndexPointerAndData)	   (zsize index, void*    pointer, void* data);

typedef void (* ZHandleContextAndUInt8	)	   (void* context, zuint8   value  );
typedef void (* ZHandleContextAndUInt16	)	   (void* context, zuint16  value  );
typedef void (* ZHandleContextAndUInt32	)	   (void* context, zuint32  value  );
typedef void (* ZHandleContextAndUInt64	)	   (void* context, zuint64  value  );
typedef void (* ZHandleContextAndInt8	)	   (void* context, zint8    value  );
typedef void (* ZHandleContextAndInt16	)	   (void* context, zint16   value  );
typedef void (* ZHandleContextAndInt32	)	   (void* context, zint32   value  );
typedef void (* ZHandleContextAndInt64	)	   (void* context, zint64   value  );
typedef void (* ZHandleContextAndFloat	)	   (void* context, zfloat   value  );
typedef void (* ZHandleContextAndDouble	)	   (void* context, zdouble  value  );
typedef void (* ZHandleContextAndLDouble)	   (void* context, zldouble value  );
typedef void (* ZHandleContextAndPointer)	   (void* context, void*    pointer);

typedef void (* ZHandleContextUInt8AndData  )	   (void* context, zuint8   value,   void* data);
typedef void (* ZHandleContextUInt16AndData )	   (void* context, zuint16  value,   void* data);
typedef void (* ZHandleContextUInt32AndData )	   (void* context, zuint32  value,   void* data);
typedef void (* ZHandleContextUInt64AndData )	   (void* context, zuint64  value,   void* data);
typedef void (* ZHandleContextInt8AndData   )	   (void* context, zint8    value,   void* data);
typedef void (* ZHandleContextInt16AndData  )	   (void* context, zint16   value,   void* data);
typedef void (* ZHandleContextInt32AndData  )	   (void* context, zint32   value,   void* data);
typedef void (* ZHandleContextInt64AndData  )	   (void* context, zint64   value,   void* data);
typedef void (* ZHandleContextFloatAndData  )	   (void* context, zfloat   value,   void* data);
typedef void (* ZHandleContextDoubleAndData )	   (void* context, zdouble  value,   void* data);
typedef void (* ZHandleContextLDoubleAndData)	   (void* context, zldouble value,   void* data);
typedef void (* ZHandleContextPointerAndData)	   (void* context, void*    pointer, void* data);

typedef void (* ZHandleContextAndIndex	  )	   (void* context, zsize index		  );
typedef void (* ZHandleContextIndexAndData)	   (void* context, zsize index, void* data);

typedef void (* ZHandleContextIndexAndUInt8  )	   (void* context, zsize index, zuint8	 value	);
typedef void (* ZHandleContextIndexAndUInt16 )	   (void* context, zsize index, zuint16	 value	);
typedef void (* ZHandleContextIndexAndUInt32 )	   (void* context, zsize index, zuint32	 value	);
typedef void (* ZHandleContextIndexAndUInt64 )	   (void* context, zsize index, zuint64	 value	);
typedef void (* ZHandleContextIndexAndInt8   )	   (void* context, zsize index, zint8	 value	);
typedef void (* ZHandleContextIndexAndInt16  )	   (void* context, zsize index, zint16	 value	);
typedef void (* ZHandleContextIndexAndInt32  )	   (void* context, zsize index, zint32	 value	);
typedef void (* ZHandleContextIndexAndInt64  )	   (void* context, zsize index, zint64	 value	);
typedef void (* ZHandleContextIndexAndFloat  )	   (void* context, zsize index, zfloat	 value	);
typedef void (* ZHandleContextIndexAndDouble )	   (void* context, zsize index, zdouble	 value	);
typedef void (* ZHandleContextIndexAndLDouble)	   (void* context, zsize index, zldouble value	);
typedef void (* ZHandleContextIndexAndPointer)	   (void* context, zsize index, void*	 pointer);

typedef void (* ZHandleContextIndexUInt8AndData	 ) (void* context, zsize index, zuint8	 value,   void* data);
typedef void (* ZHandleContextIndexUInt16AndData ) (void* context, zsize index, zuint16	 value,   void* data);
typedef void (* ZHandleContextIndexUInt32AndData ) (void* context, zsize index, zuint32	 value,   void* data);
typedef void (* ZHandleContextIndexUInt64AndData ) (void* context, zsize index, zuint64	 value,   void* data);
typedef void (* ZHandleContextIndexInt8AndData	 ) (void* context, zsize index, zint8	 value,   void* data);
typedef void (* ZHandleContextIndexInt16AndData	 ) (void* context, zsize index, zint16	 value,   void* data);
typedef void (* ZHandleContextIndexInt32AndData	 ) (void* context, zsize index, zint32	 value,   void* data);
typedef void (* ZHandleContextIndexInt64AndData	 ) (void* context, zsize index, zint64	 value,   void* data);
typedef void (* ZHandleContextIndexFloatAndData	 ) (void* context, zsize index, zfloat	 value,   void* data);
typedef void (* ZHandleContextIndexDoubleAndData ) (void* context, zsize index, zdouble	 value,   void* data);
typedef void (* ZHandleContextIndexLDoubleAndData) (void* context, zsize index, zldouble value,   void* data);
typedef void (* ZHandleContextIndexPointerAndData) (void* context, zsize index, void*	 pointer, void* data);

#define ZHandleValue(			TYPE) Z_JOIN_2(ZHandle,		       Z_##TYPE##_FIXED_TYPE_Name	  )
#define ZHandleValueAndData(		TYPE) Z_JOIN_3(ZHandle,		       Z_##TYPE##_FIXED_TYPE_Name, AndData)
#define ZHandleIndexAndValue(		TYPE) Z_JOIN_2(ZHandleIndexAnd,	       Z_##TYPE##_FIXED_TYPE_Name	  )
#define ZHandleIndexValueAndData(	TYPE) Z_JOIN_3(ZHandleIndex,	       Z_##TYPE##_FIXED_TYPE_Name, AndData)
#define ZHandleContextAndValue(		TYPE) Z_JOIN_2(ZHandleContextAnd,      Z_##TYPE##_FIXED_TYPE_Name	  )
#define ZHandleContextValueAndData(	TYPE) Z_JOIN_3(ZHandleContext,	       Z_##TYPE##_FIXED_TYPE_Name, AndData)
#define ZHandleContextIndexAndValue(	TYPE) Z_JOIN_2(ZHandleContextIndexAnd, Z_##TYPE##_FIXED_TYPE_Name	  )
#define ZHandleContextIndexValueAndData(TYPE) Z_JOIN_3(ZHandleContextIndex,    Z_##TYPE##_FIXED_TYPE_Name, AndData)

/* MARK: - Generic handler with stop types */

typedef void (* ZHandleUInt8AndStop  )		       (zuint8	 value,   zboolean *stop);
typedef void (* ZHandleUInt16AndStop )		       (zuint16	 value,   zboolean *stop);
typedef void (* ZHandleUInt32AndStop )		       (zuint32	 value,   zboolean *stop);
typedef void (* ZHandleUInt64AndStop )		       (zuint64	 value,   zboolean *stop);
typedef void (* ZHandleInt8AndStop   )		       (zint8	 value,   zboolean *stop);
typedef void (* ZHandleInt16AndStop  )		       (zint16	 value,   zboolean *stop);
typedef void (* ZHandleInt32AndStop  )		       (zint32	 value,   zboolean *stop);
typedef void (* ZHandleInt64AndStop  )		       (zint64	 value,   zboolean *stop);
typedef void (* ZHandleFloatAndStop  )		       (zfloat	 value,   zboolean *stop);
typedef void (* ZHandleDoubleAndStop )		       (zdouble	 value,   zboolean *stop);
typedef void (* ZHandleLDoubleAndStop)		       (zldouble value,   zboolean *stop);
typedef void (* ZHandlePointerAndStop)		       (void*	 pointer, zboolean *stop);

typedef void (* ZHandleUInt8DataAndStop	 )	       (zuint8	 value,   void* data, zboolean *stop);
typedef void (* ZHandleUInt16DataAndStop )	       (zuint16	 value,   void* data, zboolean *stop);
typedef void (* ZHandleUInt32DataAndStop )	       (zuint32	 value,   void* data, zboolean *stop);
typedef void (* ZHandleUInt64DataAndStop )	       (zuint64	 value,   void* data, zboolean *stop);
typedef void (* ZHandleInt8DataAndStop	 )	       (zint8	 value,   void* data, zboolean *stop);
typedef void (* ZHandleInt16DataAndStop	 )	       (zint16	 value,   void* data, zboolean *stop);
typedef void (* ZHandleInt32DataAndStop	 )	       (zint32	 value,   void* data, zboolean *stop);
typedef void (* ZHandleInt64DataAndStop	 )	       (zint64	 value,   void* data, zboolean *stop);
typedef void (* ZHandleFloatDataAndStop	 )	       (zfloat	 value,   void* data, zboolean *stop);
typedef void (* ZHandleDoubleDataAndStop )	       (zdouble	 value,   void* data, zboolean *stop);
typedef void (* ZHandleLDoubleDataAndStop)	       (zldouble value,   void* data, zboolean *stop);
typedef void (* ZHandlePointerDataAndStop)	       (void*	 pointer, void* data, zboolean *stop);

typedef void (* ZHandleIndexAndStop    )	       (zsize index,		 zboolean *stop);
typedef void (* ZHandleIndexDataAndStop)	       (zsize index, void *data, zboolean *stop);

typedef void (* ZHandleIndexUInt8AndStop  )	       (zsize index, zuint8   value,   zboolean *stop);
typedef void (* ZHandleIndexUInt16AndStop )	       (zsize index, zuint16  value,   zboolean *stop);
typedef void (* ZHandleIndexUInt32AndStop )	       (zsize index, zuint32  value,   zboolean *stop);
typedef void (* ZHandleIndexUInt64AndStop )	       (zsize index, zuint64  value,   zboolean *stop);
typedef void (* ZHandleIndexInt8AndStop	  )	       (zsize index, zint8    value,   zboolean *stop);
typedef void (* ZHandleIndexInt16AndStop  )	       (zsize index, zint16   value,   zboolean *stop);
typedef void (* ZHandleIndexInt32AndStop  )	       (zsize index, zint32   value,   zboolean *stop);
typedef void (* ZHandleIndexInt64AndStop  )	       (zsize index, zint64   value,   zboolean *stop);
typedef void (* ZHandleIndexFloatAndStop  )	       (zsize index, zfloat   value,   zboolean *stop);
typedef void (* ZHandleIndexDoubleAndStop )	       (zsize index, zdouble  value,   zboolean *stop);
typedef void (* ZHandleIndexLDoubleAndStop)	       (zsize index, zldouble value,   zboolean *stop);
typedef void (* ZHandleIndexPointerAndStop)	       (zsize index, void*    pointer, zboolean *stop);

typedef void (* ZHandleIndexUInt8DataAndStop  )	       (zsize index, zuint8   value,   void* data, zboolean *stop);
typedef void (* ZHandleIndexUInt16DataAndStop )	       (zsize index, zuint16  value,   void* data, zboolean *stop);
typedef void (* ZHandleIndexUInt32DataAndStop )	       (zsize index, zuint32  value,   void* data, zboolean *stop);
typedef void (* ZHandleIndexUInt64DataAndStop )	       (zsize index, zuint64  value,   void* data, zboolean *stop);
typedef void (* ZHandleIndexInt8DataAndStop   )	       (zsize index, zint8    value,   void* data, zboolean *stop);
typedef void (* ZHandleIndexInt16DataAndStop  )	       (zsize index, zint16   value,   void* data, zboolean *stop);
typedef void (* ZHandleIndexInt32DataAndStop  )	       (zsize index, zint32   value,   void* data, zboolean *stop);
typedef void (* ZHandleIndexInt64DataAndStop  )	       (zsize index, zint64   value,   void* data, zboolean *stop);
typedef void (* ZHandleIndexFloatDataAndStop  )	       (zsize index, zfloat   value,   void* data, zboolean *stop);
typedef void (* ZHandleIndexDoubleDataAndStop )	       (zsize index, zdouble  value,   void* data, zboolean *stop);
typedef void (* ZHandleIndexLDoubleDataAndStop)	       (zsize index, zldouble value,   void* data, zboolean *stop);
typedef void (* ZHandleIndexPointerDataAndStop)	       (zsize index, void*    pointer, void* data, zboolean *stop);

typedef void (* ZHandleContextUInt8AndStop  )	       (void* context, zuint8	value,	 zboolean *stop);
typedef void (* ZHandleContextUInt16AndStop )	       (void* context, zuint16	value,	 zboolean *stop);
typedef void (* ZHandleContextUInt32AndStop )	       (void* context, zuint32	value,	 zboolean *stop);
typedef void (* ZHandleContextUInt64AndStop )	       (void* context, zuint64	value,	 zboolean *stop);
typedef void (* ZHandleContextInt8AndStop   )	       (void* context, zint8	value,	 zboolean *stop);
typedef void (* ZHandleContextInt16AndStop  )	       (void* context, zint16	value,	 zboolean *stop);
typedef void (* ZHandleContextInt32AndStop  )	       (void* context, zint32	value,	 zboolean *stop);
typedef void (* ZHandleContextInt64AndStop  )	       (void* context, zint64	value,	 zboolean *stop);
typedef void (* ZHandleContextFloatAndStop  )	       (void* context, zfloat	value,	 zboolean *stop);
typedef void (* ZHandleContextDoubleAndStop )	       (void* context, zdouble  value,	 zboolean *stop);
typedef void (* ZHandleContextLDoubleAndStop)	       (void* context, zldouble value,	 zboolean *stop);
typedef void (* ZHandleContextPointerAndStop)	       (void* context, void*	pointer, zboolean *stop);

typedef void (* ZHandleContextUInt8DataAndStop	)      (void* context, zuint8	value,	 void* data, zboolean *stop);
typedef void (* ZHandleContextUInt16DataAndStop	)      (void* context, zuint16	value,	 void* data, zboolean *stop);
typedef void (* ZHandleContextUInt32DataAndStop	)      (void* context, zuint32	value,	 void* data, zboolean *stop);
typedef void (* ZHandleContextUInt64DataAndStop	)      (void* context, zuint64	value,	 void* data, zboolean *stop);
typedef void (* ZHandleContextInt8DataAndStop	)      (void* context, zint8	value,	 void* data, zboolean *stop);
typedef void (* ZHandleContextInt16DataAndStop	)      (void* context, zint16	value,	 void* data, zboolean *stop);
typedef void (* ZHandleContextInt32DataAndStop	)      (void* context, zint32	value,	 void* data, zboolean *stop);
typedef void (* ZHandleContextInt64DataAndStop	)      (void* context, zint64	value,	 void* data, zboolean *stop);
typedef void (* ZHandleContextFloatDataAndStop	)      (void* context, zfloat	value,	 void* data, zboolean *stop);
typedef void (* ZHandleContextDoubleDataAndStop	)      (void* context, zdouble  value,	 void* data, zboolean *stop);
typedef void (* ZHandleContextLDoubleDataAndStop)      (void* context, zldouble value,	 void* data, zboolean *stop);
typedef void (* ZHandleContextPointerDataAndStop)      (void* context, void*	pointer, void* data, zboolean *stop);

typedef void (* ZHandleContextIndexAndStop    )	       (void* context, zsize index,		zboolean *stop);
typedef void (* ZHandleContextIndexDataAndStop)	       (void* context, zsize index, void* data, zboolean *stop);

typedef void (* ZHandleContextIndexUInt8AndStop	 )     (void* context, zsize index, zuint8   value,   zboolean *stop);
typedef void (* ZHandleContextIndexUInt16AndStop )     (void* context, zsize index, zuint16  value,   zboolean *stop);
typedef void (* ZHandleContextIndexUInt32AndStop )     (void* context, zsize index, zuint32  value,   zboolean *stop);
typedef void (* ZHandleContextIndexUInt64AndStop )     (void* context, zsize index, zuint64  value,   zboolean *stop);
typedef void (* ZHandleContextIndexInt8AndStop	 )     (void* context, zsize index, zint8    value,   zboolean *stop);
typedef void (* ZHandleContextIndexInt16AndStop	 )     (void* context, zsize index, zint16   value,   zboolean *stop);
typedef void (* ZHandleContextIndexInt32AndStop	 )     (void* context, zsize index, zint32   value,   zboolean *stop);
typedef void (* ZHandleContextIndexInt64AndStop	 )     (void* context, zsize index, zint64   value,   zboolean *stop);
typedef void (* ZHandleContextIndexFloatAndStop	 )     (void* context, zsize index, zfloat   value,   zboolean *stop);
typedef void (* ZHandleContextIndexDoubleAndStop )     (void* context, zsize index, zdouble  value,   zboolean *stop);
typedef void (* ZHandleContextIndexLDoubleAndStop)     (void* context, zsize index, zldouble value,   zboolean *stop);
typedef void (* ZHandleContextIndexPointerAndStop)     (void* context, zsize index, void*    pointer, zboolean *stop);

typedef void (* ZHandleContextIndexUInt8DataAndStop  ) (void* context, zsize index, zuint8   value,   void* data, zboolean *stop);
typedef void (* ZHandleContextIndexUInt16DataAndStop ) (void* context, zsize index, zuint16  value,   void* data, zboolean *stop);
typedef void (* ZHandleContextIndexUInt32DataAndStop ) (void* context, zsize index, zuint32  value,   void* data, zboolean *stop);
typedef void (* ZHandleContextIndexUInt64DataAndStop ) (void* context, zsize index, zuint64  value,   void* data, zboolean *stop);
typedef void (* ZHandleContextIndexInt8DataAndStop   ) (void* context, zsize index, zint8    value,   void* data, zboolean *stop);
typedef void (* ZHandleContextIndexInt16DataAndStop  ) (void* context, zsize index, zint16   value,   void* data, zboolean *stop);
typedef void (* ZHandleContextIndexInt32DataAndStop  ) (void* context, zsize index, zint32   value,   void* data, zboolean *stop);
typedef void (* ZHandleContextIndexInt64DataAndStop  ) (void* context, zsize index, zint64   value,   void* data, zboolean *stop);
typedef void (* ZHandleContextIndexFloatDataAndStop  ) (void* context, zsize index, zfloat   value,   void* data, zboolean *stop);
typedef void (* ZHandleContextIndexDoubleDataAndStop ) (void* context, zsize index, zdouble  value,   void* data, zboolean *stop);
typedef void (* ZHandleContextIndexLDoubleDataAndStop) (void* context, zsize index, zldouble value,   void* data, zboolean *stop);
typedef void (* ZHandleContextIndexPointerDataAndStop) (void* context, zsize index, void*    pointer, void* data, zboolean *stop);

#define ZHandleValueAndStop(		    TYPE) Z_JOIN_3(ZHandle,		Z_##TYPE##_FIXED_TYPE_Name, AndStop    )
#define ZHandleValueDataAndStop(	    TYPE) Z_JOIN_3(ZHandle,		Z_##TYPE##_FIXED_TYPE_Name, DataAndStop)
#define ZHandleIndexValueAndStop(	    TYPE) Z_JOIN_3(ZHandleIndex,	Z_##TYPE##_FIXED_TYPE_Name, AndStop    )
#define ZHandleIndexValueDataAndStop(	    TYPE) Z_JOIN_3(ZHandleIndex,	Z_##TYPE##_FIXED_TYPE_Name, DataAndStop)
#define ZHandleContextValueAndStop(	    TYPE) Z_JOIN_3(ZHandleContext,	Z_##TYPE##_FIXED_TYPE_Name, AndStop    )
#define ZHandleContextValueDataAndStop(	    TYPE) Z_JOIN_3(ZHandleContext,	Z_##TYPE##_FIXED_TYPE_Name, DataAndStop)
#define ZHandleContextIndexValueAndStop(    TYPE) Z_JOIN_3(ZHandleContextIndex, Z_##TYPE##_FIXED_TYPE_Name, AndStop    )
#define ZHandleContextIndexValueDataAndStop(TYPE) Z_JOIN_3(ZHandleContextIndex, Z_##TYPE##_FIXED_TYPE_Name, DataAndStop)

/* MARK: - Generic validator types */

typedef zboolean (* ZValidateUInt8  )			 (zuint8   value  );
typedef zboolean (* ZValidateUInt16 )			 (zuint16  value  );
typedef zboolean (* ZValidateUInt32 )			 (zuint32  value  );
typedef zboolean (* ZValidateUInt64 )			 (zuint64  value  );
typedef zboolean (* ZValidateInt8   )			 (zint8    value  );
typedef zboolean (* ZValidateInt16  )			 (zint16   value  );
typedef zboolean (* ZValidateInt32  )			 (zint32   value  );
typedef zboolean (* ZValidateInt64  )			 (zint64   value  );
typedef zboolean (* ZValidateFloat  )			 (zfloat   value  );
typedef zboolean (* ZValidateDouble )			 (zdouble  value  );
typedef zboolean (* ZValidateLDouble)			 (zldouble value  );
typedef zboolean (* ZValidatePointer)			 (void*    pointer);

typedef zboolean (* ZValidateUInt8AndData  )		 (zuint8   value,   void* data);
typedef zboolean (* ZValidateUInt16AndData )		 (zuint16  value,   void* data);
typedef zboolean (* ZValidateUInt32AndData )		 (zuint32  value,   void* data);
typedef zboolean (* ZValidateUInt64AndData )		 (zuint64  value,   void* data);
typedef zboolean (* ZValidateInt8AndData   )		 (zint8    value,   void* data);
typedef zboolean (* ZValidateInt16AndData  )		 (zint16   value,   void* data);
typedef zboolean (* ZValidateInt32AndData  )		 (zint32   value,   void* data);
typedef zboolean (* ZValidateInt64AndData  )		 (zint64   value,   void* data);
typedef zboolean (* ZValidateFloatAndData  )		 (zfloat   value,   void* data);
typedef zboolean (* ZValidateDoubleAndData )		 (zdouble  value,   void* data);
typedef zboolean (* ZValidateLDoubleAndData)		 (zldouble value,   void* data);
typedef zboolean (* ZValidatePointerAndData)		 (void*    pointer, void* data);

typedef zboolean (* ZValidateIndex	    )		 (zsize index		 );
typedef zboolean (* ZValidateIndexAndData   )		 (zsize index, void* data);

typedef zboolean (* ZValidateIndexAndUInt8  )		 (zsize index, zuint8	value  );
typedef zboolean (* ZValidateIndexAndUInt16 )		 (zsize index, zuint16	value  );
typedef zboolean (* ZValidateIndexAndUInt32 )		 (zsize index, zuint32	value  );
typedef zboolean (* ZValidateIndexAndUInt64 )		 (zsize index, zuint64	value  );
typedef zboolean (* ZValidateIndexAndInt8   )		 (zsize index, zint8	value  );
typedef zboolean (* ZValidateIndexAndInt16  )		 (zsize index, zint16	value  );
typedef zboolean (* ZValidateIndexAndInt32  )		 (zsize index, zint32	value  );
typedef zboolean (* ZValidateIndexAndInt64  )		 (zsize index, zint64	value  );
typedef zboolean (* ZValidateIndexAndFloat  )		 (zsize index, zfloat	value  );
typedef zboolean (* ZValidateIndexAndDouble )		 (zsize index, zdouble	value  );
typedef zboolean (* ZValidateIndexAndLDouble)		 (zsize index, zldouble value  );
typedef zboolean (* ZValidateIndexAndPointer)		 (zsize index, void*	pointer);

typedef zboolean (* ZValidateIndexUInt8AndData	)	 (zsize index, zuint8	value,	 void* data);
typedef zboolean (* ZValidateIndexUInt16AndData	)	 (zsize index, zuint16	value,	 void* data);
typedef zboolean (* ZValidateIndexUInt32AndData	)	 (zsize index, zuint32	value,	 void* data);
typedef zboolean (* ZValidateIndexUInt64AndData	)	 (zsize index, zuint64	value,	 void* data);
typedef zboolean (* ZValidateIndexInt8AndData	)	 (zsize index, zint8	value,	 void* data);
typedef zboolean (* ZValidateIndexInt16AndData	)	 (zsize index, zint16	value,	 void* data);
typedef zboolean (* ZValidateIndexInt32AndData	)	 (zsize index, zint32	value,	 void* data);
typedef zboolean (* ZValidateIndexInt64AndData	)	 (zsize index, zint64	value,	 void* data);
typedef zboolean (* ZValidateIndexFloatAndData	)	 (zsize index, zfloat	value,	 void* data);
typedef zboolean (* ZValidateIndexDoubleAndData	)	 (zsize index, zdouble	value,	 void* data);
typedef zboolean (* ZValidateIndexLDoubleAndData)	 (zsize index, zldouble value,	 void* data);
typedef zboolean (* ZValidateIndexPointerAndData)	 (zsize index, void*	pointer, void* data);

typedef zboolean (* ZValidateContextAndUInt8  )		 (void* context, zuint8	  value  );
typedef zboolean (* ZValidateContextAndUInt16 )		 (void* context, zuint16  value  );
typedef zboolean (* ZValidateContextAndUInt32 )		 (void* context, zuint32  value  );
typedef zboolean (* ZValidateContextAndUInt64 )		 (void* context, zuint64  value  );
typedef zboolean (* ZValidateContextAndInt8   )		 (void* context, zint8	  value  );
typedef zboolean (* ZValidateContextAndInt16  )		 (void* context, zint16	  value  );
typedef zboolean (* ZValidateContextAndInt32  )		 (void* context, zint32	  value  );
typedef zboolean (* ZValidateContextAndInt64  )		 (void* context, zint64	  value  );
typedef zboolean (* ZValidateContextAndFloat  )		 (void* context, zfloat	  value  );
typedef zboolean (* ZValidateContextAndDouble )		 (void* context, zdouble  value  );
typedef zboolean (* ZValidateContextAndLDouble)		 (void* context, zldouble value  );
typedef zboolean (* ZValidateContextAndPointer)		 (void* context, void*	  pointer);

typedef zboolean (* ZValidateContextUInt8AndData  )	 (void* context, zuint8	  value,   void* data);
typedef zboolean (* ZValidateContextUInt16AndData )	 (void* context, zuint16  value,   void* data);
typedef zboolean (* ZValidateContextUInt32AndData )	 (void* context, zuint32  value,   void* data);
typedef zboolean (* ZValidateContextUInt64AndData )	 (void* context, zuint64  value,   void* data);
typedef zboolean (* ZValidateContextInt8AndData   )	 (void* context, zint8	  value,   void* data);
typedef zboolean (* ZValidateContextInt16AndData  )	 (void* context, zint16	  value,   void* data);
typedef zboolean (* ZValidateContextInt32AndData  )	 (void* context, zint32	  value,   void* data);
typedef zboolean (* ZValidateContextInt64AndData  )	 (void* context, zint64	  value,   void* data);
typedef zboolean (* ZValidateContextFloatAndData  )	 (void* context, zfloat	  value,   void* data);
typedef zboolean (* ZValidateContextDoubleAndData )	 (void* context, zdouble  value,   void* data);
typedef zboolean (* ZValidateContextLDoubleAndData)	 (void* context, zldouble value,   void* data);
typedef zboolean (* ZValidateContextPointerAndData)	 (void* context, void*	  pointer, void* data);

typedef zboolean (* ZValidateContextAndIndex	)	 (void* context, zsize index		);
typedef zboolean (* ZValidateContextIndexAndData)	 (void* context, zsize index, void* data);

typedef zboolean (* ZValidateContextIndexAndUInt8  )	 (void* context, zsize index, zuint8   value  );
typedef zboolean (* ZValidateContextIndexAndUInt16 )	 (void* context, zsize index, zuint16  value  );
typedef zboolean (* ZValidateContextIndexAndUInt32 )	 (void* context, zsize index, zuint32  value  );
typedef zboolean (* ZValidateContextIndexAndUInt64 )	 (void* context, zsize index, zuint64  value  );
typedef zboolean (* ZValidateContextIndexAndInt8   )	 (void* context, zsize index, zint8    value  );
typedef zboolean (* ZValidateContextIndexAndInt16  )	 (void* context, zsize index, zint16   value  );
typedef zboolean (* ZValidateContextIndexAndInt32  )	 (void* context, zsize index, zint32   value  );
typedef zboolean (* ZValidateContextIndexAndInt64  )	 (void* context, zsize index, zint64   value  );
typedef zboolean (* ZValidateContextIndexAndFloat  )	 (void* context, zsize index, zfloat   value  );
typedef zboolean (* ZValidateContextIndexAndDouble )	 (void* context, zsize index, zdouble  value  );
typedef zboolean (* ZValidateContextIndexAndLDouble)	 (void* context, zsize index, zldouble value  );
typedef zboolean (* ZValidateContextIndexAndPointer)	 (void* context, zsize index, void*    pointer);

typedef zboolean (* ZValidateContextIndexUInt8AndData  ) (void* context, zsize index, zuint8   value,	void* data);
typedef zboolean (* ZValidateContextIndexUInt16AndData ) (void* context, zsize index, zuint16  value,	void* data);
typedef zboolean (* ZValidateContextIndexUInt32AndData ) (void* context, zsize index, zuint32  value,	void* data);
typedef zboolean (* ZValidateContextIndexUInt64AndData ) (void* context, zsize index, zuint64  value,	void* data);
typedef zboolean (* ZValidateContextIndexInt8AndData   ) (void* context, zsize index, zint8    value,	void* data);
typedef zboolean (* ZValidateContextIndexInt16AndData  ) (void* context, zsize index, zint16   value,	void* data);
typedef zboolean (* ZValidateContextIndexInt32AndData  ) (void* context, zsize index, zint32   value,	void* data);
typedef zboolean (* ZValidateContextIndexInt64AndData  ) (void* context, zsize index, zint64   value,	void* data);
typedef zboolean (* ZValidateContextIndexFloatAndData  ) (void* context, zsize index, zfloat   value,	void* data);
typedef zboolean (* ZValidateContextIndexDoubleAndData ) (void* context, zsize index, zdouble  value,	void* data);
typedef zboolean (* ZValidateContextIndexLDoubleAndData) (void* context, zsize index, zldouble value,	void* data);
typedef zboolean (* ZValidateContextIndexPointerAndData) (void* context, zsize index, void*    pointer, void* data);

#define ZValidateValue(			  TYPE) Z_JOIN_2(ZValidate,		   Z_##TYPE##_FIXED_TYPE_Name	      )
#define ZValidateValueAndData(		  TYPE) Z_JOIN_3(ZValidate,		   Z_##TYPE##_FIXED_TYPE_Name, AndData)
#define ZValidateIndexAndValue(		  TYPE) Z_JOIN_2(ZValidateIndexAnd,	   Z_##TYPE##_FIXED_TYPE_Name	      )
#define ZValidateIndexValueAndData(	  TYPE) Z_JOIN_3(ZValidateIndex,	   Z_##TYPE##_FIXED_TYPE_Name, AndData)
#define ZValidateContextAndValue(	  TYPE) Z_JOIN_2(ZValidateContextAnd,      Z_##TYPE##_FIXED_TYPE_Name	      )
#define ZValidateContextValueAndData(	  TYPE) Z_JOIN_3(ZValidateContext,	   Z_##TYPE##_FIXED_TYPE_Name, AndData)
#define ZValidateContextIndexAndValue(	  TYPE) Z_JOIN_2(ZValidateContextIndexAnd, Z_##TYPE##_FIXED_TYPE_Name	      )
#define ZValidateContextIndexValueAndData(TYPE) Z_JOIN_3(ZValidateContextIndex,    Z_##TYPE##_FIXED_TYPE_Name, AndData)

#endif /* __Z_types_generic_functions_H__ */
