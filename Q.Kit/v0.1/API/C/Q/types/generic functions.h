/* Q API - types/generic functions.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_types_generic_functions_H__
#define __Q_types_generic_functions_H__

#include <Q/types/base.h>

/* MARK: - General pourpose context access function types */

typedef void	(* QDo)			    (void* context);
typedef void	(* QSwitch)		    (void* context, qboolean state);

typedef quint8	(* Q16BitAddressRead8Bit )  (void* context, quint16 address);
typedef quint16 (* Q16BitAddressRead16Bit)  (void* context, quint16 address);
typedef quint32 (* Q16BitAddressRead32Bit)  (void* context, quint16 address);
typedef quint64 (* Q16BitAddressRead64Bit)  (void* context, quint16 address);

typedef void	(* Q16BitAddressWrite8Bit ) (void* context, quint16 address, quint8  value);
typedef void	(* Q16BitAddressWrite16Bit) (void* context, quint16 address, quint16 value);
typedef void	(* Q16BitAddressWrite32Bit) (void* context, quint16 address, quint32 value);
typedef void	(* Q16BitAddressWrite64Bit) (void* context, quint16 address, quint64 value);

typedef quint8	(* Q32BitAddressRead8Bit )  (void* context, quint32 address);
typedef quint16 (* Q32BitAddressRead16Bit)  (void* context, quint32 address);
typedef quint32 (* Q32BitAddressRead32Bit)  (void* context, quint32 address);
typedef quint64 (* Q32BitAddressRead64Bit)  (void* context, quint32 address);

typedef void	(* Q32BitAddressWrite8Bit ) (void* context, quint32 address, quint8  value);
typedef void	(* Q32BitAddressWrite16Bit) (void* context, quint32 address, quint16 value);
typedef void	(* Q32BitAddressWrite32Bit) (void* context, quint32 address, quint32 value);
typedef void	(* Q32BitAddressWrite64Bit) (void* context, quint32 address, quint64 value);

typedef quint8	(* Q64BitAddressRead8Bit )  (void* context, quint32 address);
typedef quint16 (* Q64BitAddressRead16Bit)  (void* context, quint32 address);
typedef quint32 (* Q64BitAddressRead32Bit)  (void* context, quint32 address);
typedef quint64 (* Q64BitAddressRead64Bit)  (void* context, quint32 address);

typedef void	(* Q64BitAddressWrite8Bit ) (void* context, quint32 index, quint8  value);
typedef void	(* Q64BitAddressWrite16Bit) (void* context, quint32 index, quint16 value);
typedef void	(* Q64BitAddressWrite32Bit) (void* context, quint32 index, quint32 value);
typedef void	(* Q64BitAddressWrite64Bit) (void* context, quint32 index, quint64 value);

typedef quint8	(* QRead8Bit )		    (void* context);
typedef quint16 (* QRead16Bit)		    (void* context);
typedef quint32 (* QRead32Bit)		    (void* context);
typedef quint64 (* QRead64Bit)		    (void* context);

typedef void	(* QWrite8Bit )		    (void* context, quint8  value);
typedef void	(* QWrite16Bit)		    (void* context, quint16 value);
typedef void	(* QWrite32Bit)		    (void* context, quint32 value);
typedef void	(* QWrite64Bit)		    (void* context, quint64 value);

/* MARK: - General pourpose function types */

typedef void	 (* QCopy)		     (void*  context,
					      void*  output);
	
typedef void	 (* QCopyData)		     (void*  context,
					      qsize  data_size,
					      void*  output);

typedef qsize	 (* QCopyAndSize)	     (void*  context,
					      void*  output);

typedef qsize	 (* QCopyDataAndSize)	     (void*  context,
					      qsize  data_size,
					      void*  output);

typedef void	 (* QCopyRange)		     (void*  context,
					      QRange range,
					      void*  output);

typedef void	 (* QCopyRangeData)	     (void*  context,
					      QRange range,
					      qsize  data_size,
					      void*  output);

typedef void	 (* QBoundedCopy)	     (void*  context_start,
					      void*  context_end,
					      void*  output);

typedef void	 (* QBoundedCopyData)	     (void*  context_start,
					      void*  context_end,
					      qsize  data_size,
					      void*  output);

typedef qsize	 (* QBoundedCopyAndSize)     (void*  context_start,
					      void*  context_end,
					      void*  output);

typedef qsize	 (* QBoundedCopyDataAndSize) (void*  context_start,
					      void*  context_end,
					      qsize  data_size,
					      void*  output);

typedef void	 (* QBoundedCopyRange)	     (void*  context_start,
					      void*  context_end,
					      void*  context_size,
					      QRange range,
					      void*  output);

typedef void	 (* QBoundedCopyRangeData)   (void*  context_start,
					      void*  context_end,
					      void*  context_size,
					      QRange range,
					      qsize  data_size,
					      void*  output);

typedef void	 (* QCopyMany)		     (void*  context,
					      quint  count,
					      void*  output);

typedef void	 (* QSkipOne)		     (void*  input);

typedef void	 (* QSkipMany)		     (void*  input,
					      quint  count);

typedef void	 (* QSwapHalves)	     (void*  context);

typedef qsize	 (* QSize)		     (void*  context);

typedef void*	 (* QElement)		     (void*  context,
					      qsize  index);

typedef void	 (* QSetElement)	     (void*  context,
					      qsize  index,
					      void*  value);

typedef void	 (* QMoveElement)	     (void*  context,
					      qsize  old_index,
					      qsize  new_index);

typedef qint	 (* QCompareElements)	     (void*  context,
					      qsize  a_index,
					      qsize  b_index);

typedef void	 (* QSwapElements)	     (void*  context,
					      qsize  a_index,
					      qsize  b_index);

typedef qboolean (* QIsValid)		     (void*  context);

typedef qboolean (* QAreEqual)		     (void*  a,
					      void*  b);

typedef qboolean (* QAreEqualWithData)	     (void*  a,
					      void*  b,
					      void*  data);

typedef qint	 (* QCompare)		     (void*  a,
					      void*  b);

typedef qint	 (* QCompareWithData)	     (void*  a,
					      void*  b,
					      void*  data);

typedef void	 (* QSwap)		     (void*  a,
					      void*  b);

/* MARK: - Generic handler types */

typedef void (* QHandleUInt8  )			   (quint8   value  );
typedef void (* QHandleUInt16 )			   (quint16  value  );
typedef void (* QHandleUInt32 )			   (quint32  value  );
typedef void (* QHandleUInt64 )			   (quint64  value  );
typedef void (* QHandleInt8   )			   (qint8    value  );
typedef void (* QHandleInt16  )			   (qint16   value  );
typedef void (* QHandleInt32  )			   (qint32   value  );
typedef void (* QHandleInt64  )			   (qint64   value  );
typedef void (* QHandleFloat  )			   (qfloat   value  );
typedef void (* QHandleDouble )			   (qdouble  value  );
typedef void (* QHandleLDouble)			   (qldouble value  );
typedef void (* QHandlePointer)			   (void*    pointer);

typedef void (* QHandleUInt8AndData  )		   (quint8   value,   void* data);
typedef void (* QHandleUInt16AndData )		   (quint16  value,   void* data);
typedef void (* QHandleUInt32AndData )		   (quint32  value,   void* data);
typedef void (* QHandleUInt64AndData )		   (quint64  value,   void* data);
typedef void (* QHandleInt8AndData   )		   (qint8    value,   void* data);
typedef void (* QHandleInt16AndData  )		   (qint16   value,   void* data);
typedef void (* QHandleInt32AndData  )		   (qint32   value,   void* data);
typedef void (* QHandleInt64AndData  )		   (qint64   value,   void* data);
typedef void (* QHandleFloatAndData  )		   (qfloat   value,   void* data);
typedef void (* QHandleDoubleAndData )		   (qdouble  value,   void* data);
typedef void (* QHandleLDoubleAndData)		   (qldouble value,   void* data);
typedef void (* QHandlePointerAndData)		   (void*    pointer, void* data);

typedef void (* QHandleIndex	   )		   (qsize index		   );
typedef void (* QHandleIndexAndData)		   (qsize index, void *data);

typedef void (* QHandleIndexAndUInt8  )		   (qsize index, quint8   value  );
typedef void (* QHandleIndexAndUInt16 )		   (qsize index, quint16  value  );
typedef void (* QHandleIndexAndUInt32 )		   (qsize index, quint32  value  );
typedef void (* QHandleIndexAndUInt64 )		   (qsize index, quint64  value  );
typedef void (* QHandleIndexAndInt8   )		   (qsize index, qint8    value  );
typedef void (* QHandleIndexAndInt16  )		   (qsize index, qint16   value  );
typedef void (* QHandleIndexAndInt32  )		   (qsize index, qint32   value  );
typedef void (* QHandleIndexAndInt64  )		   (qsize index, qint64   value  );
typedef void (* QHandleIndexAndFloat  )		   (qsize index, qfloat   value  );
typedef void (* QHandleIndexAndDouble )		   (qsize index, qdouble  value  );
typedef void (* QHandleIndexAndLDouble)		   (qsize index, qldouble value  );
typedef void (* QHandleIndexAndPointer)		   (qsize index, void*    pointer);

typedef void (* QHandleIndexUInt8AndData  )	   (qsize index, quint8   value,   void* data);
typedef void (* QHandleIndexUInt16AndData )	   (qsize index, quint16  value,   void* data);
typedef void (* QHandleIndexUInt32AndData )	   (qsize index, quint32  value,   void* data);
typedef void (* QHandleIndexUInt64AndData )	   (qsize index, quint64  value,   void* data);
typedef void (* QHandleIndexInt8AndData   )	   (qsize index, qint8    value,   void* data);
typedef void (* QHandleIndexInt16AndData  )	   (qsize index, qint16   value,   void* data);
typedef void (* QHandleIndexInt32AndData  )	   (qsize index, qint32   value,   void* data);
typedef void (* QHandleIndexInt64AndData  )	   (qsize index, qint64   value,   void* data);
typedef void (* QHandleIndexFloatAndData  )	   (qsize index, qfloat   value,   void* data);
typedef void (* QHandleIndexDoubleAndData )	   (qsize index, qdouble  value,   void* data);
typedef void (* QHandleIndexLDoubleAndData)	   (qsize index, qldouble value,   void* data);
typedef void (* QHandleIndexPointerAndData)	   (qsize index, void*    pointer, void* data);

typedef void (* QHandleContextAndUInt8	)	   (void* context, quint8   value  );
typedef void (* QHandleContextAndUInt16	)	   (void* context, quint16  value  );
typedef void (* QHandleContextAndUInt32	)	   (void* context, quint32  value  );
typedef void (* QHandleContextAndUInt64	)	   (void* context, quint64  value  );
typedef void (* QHandleContextAndInt8	)	   (void* context, qint8    value  );
typedef void (* QHandleContextAndInt16	)	   (void* context, qint16   value  );
typedef void (* QHandleContextAndInt32	)	   (void* context, qint32   value  );
typedef void (* QHandleContextAndInt64	)	   (void* context, qint64   value  );
typedef void (* QHandleContextAndFloat	)	   (void* context, qfloat   value  );
typedef void (* QHandleContextAndDouble	)	   (void* context, qdouble  value  );
typedef void (* QHandleContextAndLDouble)	   (void* context, qldouble value  );
typedef void (* QHandleContextAndPointer)	   (void* context, void*    pointer);

typedef void (* QHandleContextUInt8AndData  )	   (void* context, quint8   value,   void* data);
typedef void (* QHandleContextUInt16AndData )	   (void* context, quint16  value,   void* data);
typedef void (* QHandleContextUInt32AndData )	   (void* context, quint32  value,   void* data);
typedef void (* QHandleContextUInt64AndData )	   (void* context, quint64  value,   void* data);
typedef void (* QHandleContextInt8AndData   )	   (void* context, qint8    value,   void* data);
typedef void (* QHandleContextInt16AndData  )	   (void* context, qint16   value,   void* data);
typedef void (* QHandleContextInt32AndData  )	   (void* context, qint32   value,   void* data);
typedef void (* QHandleContextInt64AndData  )	   (void* context, qint64   value,   void* data);
typedef void (* QHandleContextFloatAndData  )	   (void* context, qfloat   value,   void* data);
typedef void (* QHandleContextDoubleAndData )	   (void* context, qdouble  value,   void* data);
typedef void (* QHandleContextLDoubleAndData)	   (void* context, qldouble value,   void* data);
typedef void (* QHandleContextPointerAndData)	   (void* context, void*    pointer, void* data);

typedef void (* QHandleContextAndIndex	  )	   (void* context, qsize index		  );
typedef void (* QHandleContextIndexAndData)	   (void* context, qsize index, void* data);

typedef void (* QHandleContextIndexAndUInt8  )	   (void* context, qsize index, quint8	 value	);
typedef void (* QHandleContextIndexAndUInt16 )	   (void* context, qsize index, quint16	 value	);
typedef void (* QHandleContextIndexAndUInt32 )	   (void* context, qsize index, quint32	 value	);
typedef void (* QHandleContextIndexAndUInt64 )	   (void* context, qsize index, quint64	 value	);
typedef void (* QHandleContextIndexAndInt8   )	   (void* context, qsize index, qint8	 value	);
typedef void (* QHandleContextIndexAndInt16  )	   (void* context, qsize index, qint16	 value	);
typedef void (* QHandleContextIndexAndInt32  )	   (void* context, qsize index, qint32	 value	);
typedef void (* QHandleContextIndexAndInt64  )	   (void* context, qsize index, qint64	 value	);
typedef void (* QHandleContextIndexAndFloat  )	   (void* context, qsize index, qfloat	 value	);
typedef void (* QHandleContextIndexAndDouble )	   (void* context, qsize index, qdouble	 value	);
typedef void (* QHandleContextIndexAndLDouble)	   (void* context, qsize index, qldouble value	);
typedef void (* QHandleContextIndexAndPointer)	   (void* context, qsize index, void*	 pointer);

typedef void (* QHandleContextIndexUInt8AndData	 ) (void* context, qsize index, quint8	 value,   void* data);
typedef void (* QHandleContextIndexUInt16AndData ) (void* context, qsize index, quint16	 value,   void* data);
typedef void (* QHandleContextIndexUInt32AndData ) (void* context, qsize index, quint32	 value,   void* data);
typedef void (* QHandleContextIndexUInt64AndData ) (void* context, qsize index, quint64	 value,   void* data);
typedef void (* QHandleContextIndexInt8AndData	 ) (void* context, qsize index, qint8	 value,   void* data);
typedef void (* QHandleContextIndexInt16AndData	 ) (void* context, qsize index, qint16	 value,   void* data);
typedef void (* QHandleContextIndexInt32AndData	 ) (void* context, qsize index, qint32	 value,   void* data);
typedef void (* QHandleContextIndexInt64AndData	 ) (void* context, qsize index, qint64	 value,   void* data);
typedef void (* QHandleContextIndexFloatAndData	 ) (void* context, qsize index, qfloat	 value,   void* data);
typedef void (* QHandleContextIndexDoubleAndData ) (void* context, qsize index, qdouble	 value,   void* data);
typedef void (* QHandleContextIndexLDoubleAndData) (void* context, qsize index, qldouble value,   void* data);
typedef void (* QHandleContextIndexPointerAndData) (void* context, qsize index, void*	 pointer, void* data);

#define QHandleValue(			TYPE) Q_JOIN_2(QHandle,		       Q_##TYPE##_FIXED_TYPE_Name	  )
#define QHandleValueAndData(		TYPE) Q_JOIN_3(QHandle,		       Q_##TYPE##_FIXED_TYPE_Name, AndData)
#define QHandleIndexAndValue(		TYPE) Q_JOIN_2(QHandleIndexAnd,	       Q_##TYPE##_FIXED_TYPE_Name	  )
#define QHandleIndexValueAndData(	TYPE) Q_JOIN_3(QHandleIndex,	       Q_##TYPE##_FIXED_TYPE_Name, AndData)
#define QHandleContextAndValue(		TYPE) Q_JOIN_2(QHandleContextAnd,      Q_##TYPE##_FIXED_TYPE_Name	  )
#define QHandleContextValueAndData(	TYPE) Q_JOIN_3(QHandleContext,	       Q_##TYPE##_FIXED_TYPE_Name, AndData)
#define QHandleContextIndexAndValue(	TYPE) Q_JOIN_2(QHandleContextIndexAnd, Q_##TYPE##_FIXED_TYPE_Name	  )
#define QHandleContextIndexValueAndData(TYPE) Q_JOIN_3(QHandleContextIndex,    Q_##TYPE##_FIXED_TYPE_Name, AndData)

/* MARK: - Generic handler with stop types */

typedef void (* QHandleUInt8AndStop  )		       (quint8	 value,   qboolean *stop);
typedef void (* QHandleUInt16AndStop )		       (quint16	 value,   qboolean *stop);
typedef void (* QHandleUInt32AndStop )		       (quint32	 value,   qboolean *stop);
typedef void (* QHandleUInt64AndStop )		       (quint64	 value,   qboolean *stop);
typedef void (* QHandleInt8AndStop   )		       (qint8	 value,   qboolean *stop);
typedef void (* QHandleInt16AndStop  )		       (qint16	 value,   qboolean *stop);
typedef void (* QHandleInt32AndStop  )		       (qint32	 value,   qboolean *stop);
typedef void (* QHandleInt64AndStop  )		       (qint64	 value,   qboolean *stop);
typedef void (* QHandleFloatAndStop  )		       (qfloat	 value,   qboolean *stop);
typedef void (* QHandleDoubleAndStop )		       (qdouble	 value,   qboolean *stop);
typedef void (* QHandleLDoubleAndStop)		       (qldouble value,   qboolean *stop);
typedef void (* QHandlePointerAndStop)		       (void*	 pointer, qboolean *stop);

typedef void (* QHandleUInt8DataAndStop	 )	       (quint8	 value,   void* data, qboolean *stop);
typedef void (* QHandleUInt16DataAndStop )	       (quint16	 value,   void* data, qboolean *stop);
typedef void (* QHandleUInt32DataAndStop )	       (quint32	 value,   void* data, qboolean *stop);
typedef void (* QHandleUInt64DataAndStop )	       (quint64	 value,   void* data, qboolean *stop);
typedef void (* QHandleInt8DataAndStop	 )	       (qint8	 value,   void* data, qboolean *stop);
typedef void (* QHandleInt16DataAndStop	 )	       (qint16	 value,   void* data, qboolean *stop);
typedef void (* QHandleInt32DataAndStop	 )	       (qint32	 value,   void* data, qboolean *stop);
typedef void (* QHandleInt64DataAndStop	 )	       (qint64	 value,   void* data, qboolean *stop);
typedef void (* QHandleFloatDataAndStop	 )	       (qfloat	 value,   void* data, qboolean *stop);
typedef void (* QHandleDoubleDataAndStop )	       (qdouble	 value,   void* data, qboolean *stop);
typedef void (* QHandleLDoubleDataAndStop)	       (qldouble value,   void* data, qboolean *stop);
typedef void (* QHandlePointerDataAndStop)	       (void*	 pointer, void* data, qboolean *stop);

typedef void (* QHandleIndexAndStop    )	       (qsize index,		 qboolean *stop);
typedef void (* QHandleIndexDataAndStop)	       (qsize index, void *data, qboolean *stop);

typedef void (* QHandleIndexUInt8AndStop  )	       (qsize index, quint8   value,   qboolean *stop);
typedef void (* QHandleIndexUInt16AndStop )	       (qsize index, quint16  value,   qboolean *stop);
typedef void (* QHandleIndexUInt32AndStop )	       (qsize index, quint32  value,   qboolean *stop);
typedef void (* QHandleIndexUInt64AndStop )	       (qsize index, quint64  value,   qboolean *stop);
typedef void (* QHandleIndexInt8AndStop	  )	       (qsize index, qint8    value,   qboolean *stop);
typedef void (* QHandleIndexInt16AndStop  )	       (qsize index, qint16   value,   qboolean *stop);
typedef void (* QHandleIndexInt32AndStop  )	       (qsize index, qint32   value,   qboolean *stop);
typedef void (* QHandleIndexInt64AndStop  )	       (qsize index, qint64   value,   qboolean *stop);
typedef void (* QHandleIndexFloatAndStop  )	       (qsize index, qfloat   value,   qboolean *stop);
typedef void (* QHandleIndexDoubleAndStop )	       (qsize index, qdouble  value,   qboolean *stop);
typedef void (* QHandleIndexLDoubleAndStop)	       (qsize index, qldouble value,   qboolean *stop);
typedef void (* QHandleIndexPointerAndStop)	       (qsize index, void*    pointer, qboolean *stop);

typedef void (* QHandleIndexUInt8DataAndStop  )	       (qsize index, quint8   value,   void* data, qboolean *stop);
typedef void (* QHandleIndexUInt16DataAndStop )	       (qsize index, quint16  value,   void* data, qboolean *stop);
typedef void (* QHandleIndexUInt32DataAndStop )	       (qsize index, quint32  value,   void* data, qboolean *stop);
typedef void (* QHandleIndexUInt64DataAndStop )	       (qsize index, quint64  value,   void* data, qboolean *stop);
typedef void (* QHandleIndexInt8DataAndStop   )	       (qsize index, qint8    value,   void* data, qboolean *stop);
typedef void (* QHandleIndexInt16DataAndStop  )	       (qsize index, qint16   value,   void* data, qboolean *stop);
typedef void (* QHandleIndexInt32DataAndStop  )	       (qsize index, qint32   value,   void* data, qboolean *stop);
typedef void (* QHandleIndexInt64DataAndStop  )	       (qsize index, qint64   value,   void* data, qboolean *stop);
typedef void (* QHandleIndexFloatDataAndStop  )	       (qsize index, qfloat   value,   void* data, qboolean *stop);
typedef void (* QHandleIndexDoubleDataAndStop )	       (qsize index, qdouble  value,   void* data, qboolean *stop);
typedef void (* QHandleIndexLDoubleDataAndStop)	       (qsize index, qldouble value,   void* data, qboolean *stop);
typedef void (* QHandleIndexPointerDataAndStop)	       (qsize index, void*    pointer, void* data, qboolean *stop);

typedef void (* QHandleContextUInt8AndStop  )	       (void* context, quint8	value,	 qboolean *stop);
typedef void (* QHandleContextUInt16AndStop )	       (void* context, quint16	value,	 qboolean *stop);
typedef void (* QHandleContextUInt32AndStop )	       (void* context, quint32	value,	 qboolean *stop);
typedef void (* QHandleContextUInt64AndStop )	       (void* context, quint64	value,	 qboolean *stop);
typedef void (* QHandleContextInt8AndStop   )	       (void* context, qint8	value,	 qboolean *stop);
typedef void (* QHandleContextInt16AndStop  )	       (void* context, qint16	value,	 qboolean *stop);
typedef void (* QHandleContextInt32AndStop  )	       (void* context, qint32	value,	 qboolean *stop);
typedef void (* QHandleContextInt64AndStop  )	       (void* context, qint64	value,	 qboolean *stop);
typedef void (* QHandleContextFloatAndStop  )	       (void* context, qfloat	value,	 qboolean *stop);
typedef void (* QHandleContextDoubleAndStop )	       (void* context, qdouble  value,	 qboolean *stop);
typedef void (* QHandleContextLDoubleAndStop)	       (void* context, qldouble value,	 qboolean *stop);
typedef void (* QHandleContextPointerAndStop)	       (void* context, void*	pointer, qboolean *stop);

typedef void (* QHandleContextUInt8DataAndStop	)      (void* context, quint8	value,	 void* data, qboolean *stop);
typedef void (* QHandleContextUInt16DataAndStop	)      (void* context, quint16	value,	 void* data, qboolean *stop);
typedef void (* QHandleContextUInt32DataAndStop	)      (void* context, quint32	value,	 void* data, qboolean *stop);
typedef void (* QHandleContextUInt64DataAndStop	)      (void* context, quint64	value,	 void* data, qboolean *stop);
typedef void (* QHandleContextInt8DataAndStop	)      (void* context, qint8	value,	 void* data, qboolean *stop);
typedef void (* QHandleContextInt16DataAndStop	)      (void* context, qint16	value,	 void* data, qboolean *stop);
typedef void (* QHandleContextInt32DataAndStop	)      (void* context, qint32	value,	 void* data, qboolean *stop);
typedef void (* QHandleContextInt64DataAndStop	)      (void* context, qint64	value,	 void* data, qboolean *stop);
typedef void (* QHandleContextFloatDataAndStop	)      (void* context, qfloat	value,	 void* data, qboolean *stop);
typedef void (* QHandleContextDoubleDataAndStop	)      (void* context, qdouble  value,	 void* data, qboolean *stop);
typedef void (* QHandleContextLDoubleDataAndStop)      (void* context, qldouble value,	 void* data, qboolean *stop);
typedef void (* QHandleContextPointerDataAndStop)      (void* context, void*	pointer, void* data, qboolean *stop);

typedef void (* QHandleContextIndexAndStop    )	       (void* context, qsize index,		qboolean *stop);
typedef void (* QHandleContextIndexDataAndStop)	       (void* context, qsize index, void* data, qboolean *stop);

typedef void (* QHandleContextIndexUInt8AndStop	 )     (void* context, qsize index, quint8   value,   qboolean *stop);
typedef void (* QHandleContextIndexUInt16AndStop )     (void* context, qsize index, quint16  value,   qboolean *stop);
typedef void (* QHandleContextIndexUInt32AndStop )     (void* context, qsize index, quint32  value,   qboolean *stop);
typedef void (* QHandleContextIndexUInt64AndStop )     (void* context, qsize index, quint64  value,   qboolean *stop);
typedef void (* QHandleContextIndexInt8AndStop	 )     (void* context, qsize index, qint8    value,   qboolean *stop);
typedef void (* QHandleContextIndexInt16AndStop	 )     (void* context, qsize index, qint16   value,   qboolean *stop);
typedef void (* QHandleContextIndexInt32AndStop	 )     (void* context, qsize index, qint32   value,   qboolean *stop);
typedef void (* QHandleContextIndexInt64AndStop	 )     (void* context, qsize index, qint64   value,   qboolean *stop);
typedef void (* QHandleContextIndexFloatAndStop	 )     (void* context, qsize index, qfloat   value,   qboolean *stop);
typedef void (* QHandleContextIndexDoubleAndStop )     (void* context, qsize index, qdouble  value,   qboolean *stop);
typedef void (* QHandleContextIndexLDoubleAndStop)     (void* context, qsize index, qldouble value,   qboolean *stop);
typedef void (* QHandleContextIndexPointerAndStop)     (void* context, qsize index, void*    pointer, qboolean *stop);

typedef void (* QHandleContextIndexUInt8DataAndStop  ) (void* context, qsize index, quint8   value,   void* data, qboolean *stop);
typedef void (* QHandleContextIndexUInt16DataAndStop ) (void* context, qsize index, quint16  value,   void* data, qboolean *stop);
typedef void (* QHandleContextIndexUInt32DataAndStop ) (void* context, qsize index, quint32  value,   void* data, qboolean *stop);
typedef void (* QHandleContextIndexUInt64DataAndStop ) (void* context, qsize index, quint64  value,   void* data, qboolean *stop);
typedef void (* QHandleContextIndexInt8DataAndStop   ) (void* context, qsize index, qint8    value,   void* data, qboolean *stop);
typedef void (* QHandleContextIndexInt16DataAndStop  ) (void* context, qsize index, qint16   value,   void* data, qboolean *stop);
typedef void (* QHandleContextIndexInt32DataAndStop  ) (void* context, qsize index, qint32   value,   void* data, qboolean *stop);
typedef void (* QHandleContextIndexInt64DataAndStop  ) (void* context, qsize index, qint64   value,   void* data, qboolean *stop);
typedef void (* QHandleContextIndexFloatDataAndStop  ) (void* context, qsize index, qfloat   value,   void* data, qboolean *stop);
typedef void (* QHandleContextIndexDoubleDataAndStop ) (void* context, qsize index, qdouble  value,   void* data, qboolean *stop);
typedef void (* QHandleContextIndexLDoubleDataAndStop) (void* context, qsize index, qldouble value,   void* data, qboolean *stop);
typedef void (* QHandleContextIndexPointerDataAndStop) (void* context, qsize index, void*    pointer, void* data, qboolean *stop);

#define QHandleValueAndStop(		    TYPE) Q_JOIN_3(QHandle,		Q_##TYPE##_FIXED_TYPE_Name, AndStop    )
#define QHandleValueDataAndStop(	    TYPE) Q_JOIN_3(QHandle,		Q_##TYPE##_FIXED_TYPE_Name, DataAndStop)
#define QHandleIndexValueAndStop(	    TYPE) Q_JOIN_3(QHandleIndex,	Q_##TYPE##_FIXED_TYPE_Name, AndStop    )
#define QHandleIndexValueDataAndStop(	    TYPE) Q_JOIN_3(QHandleIndex,	Q_##TYPE##_FIXED_TYPE_Name, DataAndStop)
#define QHandleContextValueAndStop(	    TYPE) Q_JOIN_3(QHandleContext,	Q_##TYPE##_FIXED_TYPE_Name, AndStop    )
#define QHandleContextValueDataAndStop(	    TYPE) Q_JOIN_3(QHandleContext,	Q_##TYPE##_FIXED_TYPE_Name, DataAndStop)
#define QHandleContextIndexValueAndStop(    TYPE) Q_JOIN_3(QHandleContextIndex, Q_##TYPE##_FIXED_TYPE_Name, AndStop    )
#define QHandleContextIndexValueDataAndStop(TYPE) Q_JOIN_3(QHandleContextIndex, Q_##TYPE##_FIXED_TYPE_Name, DataAndStop)

/* MARK: - Generic validator types */

typedef qboolean (* QValidateUInt8  )			 (quint8   value  );
typedef qboolean (* QValidateUInt16 )			 (quint16  value  );
typedef qboolean (* QValidateUInt32 )			 (quint32  value  );
typedef qboolean (* QValidateUInt64 )			 (quint64  value  );
typedef qboolean (* QValidateInt8   )			 (qint8    value  );
typedef qboolean (* QValidateInt16  )			 (qint16   value  );
typedef qboolean (* QValidateInt32  )			 (qint32   value  );
typedef qboolean (* QValidateInt64  )			 (qint64   value  );
typedef qboolean (* QValidateFloat  )			 (qfloat   value  );
typedef qboolean (* QValidateDouble )			 (qdouble  value  );
typedef qboolean (* QValidateLDouble)			 (qldouble value  );
typedef qboolean (* QValidatePointer)			 (void*    pointer);

typedef qboolean (* QValidateUInt8AndData  )		 (quint8   value,   void* data);
typedef qboolean (* QValidateUInt16AndData )		 (quint16  value,   void* data);
typedef qboolean (* QValidateUInt32AndData )		 (quint32  value,   void* data);
typedef qboolean (* QValidateUInt64AndData )		 (quint64  value,   void* data);
typedef qboolean (* QValidateInt8AndData   )		 (qint8    value,   void* data);
typedef qboolean (* QValidateInt16AndData  )		 (qint16   value,   void* data);
typedef qboolean (* QValidateInt32AndData  )		 (qint32   value,   void* data);
typedef qboolean (* QValidateInt64AndData  )		 (qint64   value,   void* data);
typedef qboolean (* QValidateFloatAndData  )		 (qfloat   value,   void* data);
typedef qboolean (* QValidateDoubleAndData )		 (qdouble  value,   void* data);
typedef qboolean (* QValidateLDoubleAndData)		 (qldouble value,   void* data);
typedef qboolean (* QValidatePointerAndData)		 (void*    pointer, void* data);

typedef qboolean (* QValidateIndex	    )		 (qsize index		 );
typedef qboolean (* QValidateIndexAndData   )		 (qsize index, void* data);

typedef qboolean (* QValidateIndexAndUInt8  )		 (qsize index, quint8	value  );
typedef qboolean (* QValidateIndexAndUInt16 )		 (qsize index, quint16	value  );
typedef qboolean (* QValidateIndexAndUInt32 )		 (qsize index, quint32	value  );
typedef qboolean (* QValidateIndexAndUInt64 )		 (qsize index, quint64	value  );
typedef qboolean (* QValidateIndexAndInt8   )		 (qsize index, qint8	value  );
typedef qboolean (* QValidateIndexAndInt16  )		 (qsize index, qint16	value  );
typedef qboolean (* QValidateIndexAndInt32  )		 (qsize index, qint32	value  );
typedef qboolean (* QValidateIndexAndInt64  )		 (qsize index, qint64	value  );
typedef qboolean (* QValidateIndexAndFloat  )		 (qsize index, qfloat	value  );
typedef qboolean (* QValidateIndexAndDouble )		 (qsize index, qdouble	value  );
typedef qboolean (* QValidateIndexAndLDouble)		 (qsize index, qldouble value  );
typedef qboolean (* QValidateIndexAndPointer)		 (qsize index, void*	pointer);

typedef qboolean (* QValidateIndexUInt8AndData	)	 (qsize index, quint8	value,	 void* data);
typedef qboolean (* QValidateIndexUInt16AndData	)	 (qsize index, quint16	value,	 void* data);
typedef qboolean (* QValidateIndexUInt32AndData	)	 (qsize index, quint32	value,	 void* data);
typedef qboolean (* QValidateIndexUInt64AndData	)	 (qsize index, quint64	value,	 void* data);
typedef qboolean (* QValidateIndexInt8AndData	)	 (qsize index, qint8	value,	 void* data);
typedef qboolean (* QValidateIndexInt16AndData	)	 (qsize index, qint16	value,	 void* data);
typedef qboolean (* QValidateIndexInt32AndData	)	 (qsize index, qint32	value,	 void* data);
typedef qboolean (* QValidateIndexInt64AndData	)	 (qsize index, qint64	value,	 void* data);
typedef qboolean (* QValidateIndexFloatAndData	)	 (qsize index, qfloat	value,	 void* data);
typedef qboolean (* QValidateIndexDoubleAndData	)	 (qsize index, qdouble	value,	 void* data);
typedef qboolean (* QValidateIndexLDoubleAndData)	 (qsize index, qldouble value,	 void* data);
typedef qboolean (* QValidateIndexPointerAndData)	 (qsize index, void*	pointer, void* data);

typedef qboolean (* QValidateContextAndUInt8  )		 (void* context, quint8	  value  );
typedef qboolean (* QValidateContextAndUInt16 )		 (void* context, quint16  value  );
typedef qboolean (* QValidateContextAndUInt32 )		 (void* context, quint32  value  );
typedef qboolean (* QValidateContextAndUInt64 )		 (void* context, quint64  value  );
typedef qboolean (* QValidateContextAndInt8   )		 (void* context, qint8	  value  );
typedef qboolean (* QValidateContextAndInt16  )		 (void* context, qint16	  value  );
typedef qboolean (* QValidateContextAndInt32  )		 (void* context, qint32	  value  );
typedef qboolean (* QValidateContextAndInt64  )		 (void* context, qint64	  value  );
typedef qboolean (* QValidateContextAndFloat  )		 (void* context, qfloat	  value  );
typedef qboolean (* QValidateContextAndDouble )		 (void* context, qdouble  value  );
typedef qboolean (* QValidateContextAndLDouble)		 (void* context, qldouble value  );
typedef qboolean (* QValidateContextAndPointer)		 (void* context, void*	  pointer);

typedef qboolean (* QValidateContextUInt8AndData  )	 (void* context, quint8	  value,   void* data);
typedef qboolean (* QValidateContextUInt16AndData )	 (void* context, quint16  value,   void* data);
typedef qboolean (* QValidateContextUInt32AndData )	 (void* context, quint32  value,   void* data);
typedef qboolean (* QValidateContextUInt64AndData )	 (void* context, quint64  value,   void* data);
typedef qboolean (* QValidateContextInt8AndData   )	 (void* context, qint8	  value,   void* data);
typedef qboolean (* QValidateContextInt16AndData  )	 (void* context, qint16	  value,   void* data);
typedef qboolean (* QValidateContextInt32AndData  )	 (void* context, qint32	  value,   void* data);
typedef qboolean (* QValidateContextInt64AndData  )	 (void* context, qint64	  value,   void* data);
typedef qboolean (* QValidateContextFloatAndData  )	 (void* context, qfloat	  value,   void* data);
typedef qboolean (* QValidateContextDoubleAndData )	 (void* context, qdouble  value,   void* data);
typedef qboolean (* QValidateContextLDoubleAndData)	 (void* context, qldouble value,   void* data);
typedef qboolean (* QValidateContextPointerAndData)	 (void* context, void*	  pointer, void* data);

typedef qboolean (* QValidateContextAndIndex	)	 (void* context, qsize index		);
typedef qboolean (* QValidateContextIndexAndData)	 (void* context, qsize index, void* data);

typedef qboolean (* QValidateContextIndexAndUInt8  )	 (void* context, qsize index, quint8   value  );
typedef qboolean (* QValidateContextIndexAndUInt16 )	 (void* context, qsize index, quint16  value  );
typedef qboolean (* QValidateContextIndexAndUInt32 )	 (void* context, qsize index, quint32  value  );
typedef qboolean (* QValidateContextIndexAndUInt64 )	 (void* context, qsize index, quint64  value  );
typedef qboolean (* QValidateContextIndexAndInt8   )	 (void* context, qsize index, qint8    value  );
typedef qboolean (* QValidateContextIndexAndInt16  )	 (void* context, qsize index, qint16   value  );
typedef qboolean (* QValidateContextIndexAndInt32  )	 (void* context, qsize index, qint32   value  );
typedef qboolean (* QValidateContextIndexAndInt64  )	 (void* context, qsize index, qint64   value  );
typedef qboolean (* QValidateContextIndexAndFloat  )	 (void* context, qsize index, qfloat   value  );
typedef qboolean (* QValidateContextIndexAndDouble )	 (void* context, qsize index, qdouble  value  );
typedef qboolean (* QValidateContextIndexAndLDouble)	 (void* context, qsize index, qldouble value  );
typedef qboolean (* QValidateContextIndexAndPointer)	 (void* context, qsize index, void*    pointer);

typedef qboolean (* QValidateContextIndexUInt8AndData  ) (void* context, qsize index, quint8   value,	void* data);
typedef qboolean (* QValidateContextIndexUInt16AndData ) (void* context, qsize index, quint16  value,	void* data);
typedef qboolean (* QValidateContextIndexUInt32AndData ) (void* context, qsize index, quint32  value,	void* data);
typedef qboolean (* QValidateContextIndexUInt64AndData ) (void* context, qsize index, quint64  value,	void* data);
typedef qboolean (* QValidateContextIndexInt8AndData   ) (void* context, qsize index, qint8    value,	void* data);
typedef qboolean (* QValidateContextIndexInt16AndData  ) (void* context, qsize index, qint16   value,	void* data);
typedef qboolean (* QValidateContextIndexInt32AndData  ) (void* context, qsize index, qint32   value,	void* data);
typedef qboolean (* QValidateContextIndexInt64AndData  ) (void* context, qsize index, qint64   value,	void* data);
typedef qboolean (* QValidateContextIndexFloatAndData  ) (void* context, qsize index, qfloat   value,	void* data);
typedef qboolean (* QValidateContextIndexDoubleAndData ) (void* context, qsize index, qdouble  value,	void* data);
typedef qboolean (* QValidateContextIndexLDoubleAndData) (void* context, qsize index, qldouble value,	void* data);
typedef qboolean (* QValidateContextIndexPointerAndData) (void* context, qsize index, void*    pointer, void* data);

#define QValidateValue(			  TYPE) Q_JOIN_2(QValidate,		   Q_##TYPE##_FIXED_TYPE_Name	      )
#define QValidateValueAndData(		  TYPE) Q_JOIN_3(QValidate,		   Q_##TYPE##_FIXED_TYPE_Name, AndData)
#define QValidateIndexAndValue(		  TYPE) Q_JOIN_2(QValidateIndexAnd,	   Q_##TYPE##_FIXED_TYPE_Name	      )
#define QValidateIndexValueAndData(	  TYPE) Q_JOIN_3(QValidateIndex,	   Q_##TYPE##_FIXED_TYPE_Name, AndData)
#define QValidateContextAndValue(	  TYPE) Q_JOIN_2(QValidateContextAnd,      Q_##TYPE##_FIXED_TYPE_Name	      )
#define QValidateContextValueAndData(	  TYPE) Q_JOIN_3(QValidateContext,	   Q_##TYPE##_FIXED_TYPE_Name, AndData)
#define QValidateContextIndexAndValue(	  TYPE) Q_JOIN_2(QValidateContextIndexAnd, Q_##TYPE##_FIXED_TYPE_Name	      )
#define QValidateContextIndexValueAndData(TYPE) Q_JOIN_3(QValidateContextIndex,    Q_##TYPE##_FIXED_TYPE_Name, AndData)

#endif /* __Q_types_generic_functions_H__ */
