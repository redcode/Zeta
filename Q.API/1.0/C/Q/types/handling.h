/* Q API - types/handling.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2012 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_types_handling_H__
#define __Q_types_handling_H__

#include <Q/types/basics.h>

#pragma mark - Generic handler types

typedef void	(* QHandleUInt8  )			(quint8   value  );
typedef void	(* QHandleUInt16 )			(quint8   value  );
typedef void	(* QHandleUInt32 )			(quint8   value  );
typedef void	(* QHandleUInt64 )			(quint8   value  );
typedef void	(* QHandleInt8	 )			(qint8	  value  );
typedef void	(* QHandleInt16  )			(qint8	  value  );
typedef void	(* QHandleInt32  )			(qint8	  value  );
typedef void	(* QHandleInt64  )			(qint8	  value  );
typedef void	(* QHandleFloat  )			(qfloat   value  );
typedef void	(* QHandleDouble )			(qdouble  value  );
typedef void	(* QHandleLDouble)			(qldouble value  );
typedef void	(* QHandlePointer)			(void*	  pointer);

typedef void	(* QHandleUInt8AndData	)		(quint8   value,   void* data);
typedef void	(* QHandleUInt16AndData )		(quint8   value,   void* data);
typedef void	(* QHandleUInt32AndData )		(quint8   value,   void* data);
typedef void	(* QHandleUInt64AndData )		(quint8   value,   void* data);
typedef void	(* QHandleInt8AndData	)		(qint8	  value,   void* data);
typedef void	(* QHandleInt16AndData	)		(qint8	  value,   void* data);
typedef void	(* QHandleInt32AndData	)		(qint8	  value,   void* data);
typedef void	(* QHandleInt64AndData	)		(qint8	  value,   void* data);
typedef void	(* QHandleFloatAndData	)		(qfloat   value,   void* data);
typedef void	(* QHandleDoubleAndData )		(qdouble  value,   void* data);
typedef void	(* QHandleLDoubleAndData)		(qldouble value,   void* data);
typedef void	(* QHandlePointerAndData)		(void*	  pointer, void* data);

typedef void	(* QHandleIndex       )			(qsize index		);
typedef void	(* QHandleIndexAndData)			(qsize index, void *data);

typedef void	(* QHandleIndexAndUInt8  )		(qsize index, quint8   value  );
typedef void	(* QHandleIndexAndUInt16 )		(qsize index, quint8   value  );
typedef void	(* QHandleIndexAndUInt32 )		(qsize index, quint8   value  );
typedef void	(* QHandleIndexAndUInt64 )		(qsize index, quint8   value  );
typedef void	(* QHandleIndexAndInt8   )		(qsize index, qint8    value  );
typedef void	(* QHandleIndexAndInt16  )		(qsize index, qint8    value  );
typedef void	(* QHandleIndexAndInt32  )		(qsize index, qint8    value  );
typedef void	(* QHandleIndexAndInt64  )		(qsize index, qint8    value  );
typedef void	(* QHandleIndexAndFloat  )		(qsize index, qfloat   value  );
typedef void	(* QHandleIndexAndDouble )		(qsize index, qdouble  value  );
typedef void	(* QHandleIndexAndLDouble)		(qsize index, qldouble value  );
typedef void	(* QHandleIndexAndPointer)		(qsize index, void*    pointer);

typedef void	(* QHandleIndexUInt8AndData  )		(qsize index, quint8   value,	void* data);
typedef void	(* QHandleIndexUInt16AndData )		(qsize index, quint8   value,	void* data);
typedef void	(* QHandleIndexUInt32AndData )		(qsize index, quint8   value,	void* data);
typedef void	(* QHandleIndexUInt64AndData )		(qsize index, quint8   value,	void* data);
typedef void	(* QHandleIndexInt8AndData   )		(qsize index, qint8    value,	void* data);
typedef void	(* QHandleIndexInt16AndData  )		(qsize index, qint8    value,	void* data);
typedef void	(* QHandleIndexInt32AndData  )		(qsize index, qint8    value,	void* data);
typedef void	(* QHandleIndexInt64AndData  )		(qsize index, qint8    value,	void* data);
typedef void	(* QHandleIndexFloatAndData  )		(qsize index, qfloat   value,	void* data);
typedef void	(* QHandleIndexDoubleAndData )		(qsize index, qdouble  value,	void* data);
typedef void	(* QHandleIndexLDoubleAndData)		(qsize index, qldouble value,	void* data);
typedef void	(* QHandleIndexPointerAndData)		(qsize index, void*    pointer, void* data);

typedef void	(* QHandleContextAndUInt8  )		(void* context, quint8	 value	);
typedef void	(* QHandleContextAndUInt16 )		(void* context, quint8	 value	);
typedef void	(* QHandleContextAndUInt32 )		(void* context, quint8	 value	);
typedef void	(* QHandleContextAndUInt64 )		(void* context, quint8	 value	);
typedef void	(* QHandleContextAndInt8   )		(void* context, qint8	 value	);
typedef void	(* QHandleContextAndInt16  )		(void* context, qint8	 value	);
typedef void	(* QHandleContextAndInt32  )		(void* context, qint8	 value	);
typedef void	(* QHandleContextAndInt64  )		(void* context, qint8	 value	);
typedef void	(* QHandleContextAndFloat  )		(void* context, qfloat	 value	);
typedef void	(* QHandleContextAndDouble )		(void* context, qdouble  value	);
typedef void	(* QHandleContextAndLDouble)		(void* context, qldouble value	);
typedef void	(* QHandleContextAndPointer)		(void* context, void*	 pointer);

typedef void	(* QHandleContextUInt8AndData  )	(void* context, quint8	 value,   void* data);
typedef void	(* QHandleContextUInt16AndData )	(void* context, quint8	 value,   void* data);
typedef void	(* QHandleContextUInt32AndData )	(void* context, quint8	 value,   void* data);
typedef void	(* QHandleContextUInt64AndData )	(void* context, quint8	 value,   void* data);
typedef void	(* QHandleContextInt8AndData   )	(void* context, qint8	 value,   void* data);
typedef void	(* QHandleContextInt16AndData  )	(void* context, qint8	 value,   void* data);
typedef void	(* QHandleContextInt32AndData  )	(void* context, qint8	 value,   void* data);
typedef void	(* QHandleContextInt64AndData  )	(void* context, qint8	 value,   void* data);
typedef void	(* QHandleContextFloatAndData  )	(void* context, qfloat	 value,   void* data);
typedef void	(* QHandleContextDoubleAndData )	(void* context, qdouble  value,   void* data);
typedef void	(* QHandleContextLDoubleAndData)	(void* context, qldouble value,   void* data);
typedef void	(* QHandleContextPointerAndData)	(void* context, void*	 pointer, void* data);

typedef void	(* QHandleContextAndIndex    )		(void* context, qsize index	       );
typedef void	(* QHandleContextIndexAndData)		(void* context, qsize index, void* data);

typedef void	(* QHandleContextIndexAndUInt8	)	(void* context, qsize index, quint8   value  );
typedef void	(* QHandleContextIndexAndUInt16 )	(void* context, qsize index, quint8   value  );
typedef void	(* QHandleContextIndexAndUInt32 )	(void* context, qsize index, quint8   value  );
typedef void	(* QHandleContextIndexAndUInt64 )	(void* context, qsize index, quint8   value  );
typedef void	(* QHandleContextIndexAndInt8	)	(void* context, qsize index, qint8    value  );
typedef void	(* QHandleContextIndexAndInt16	)	(void* context, qsize index, qint8    value  );
typedef void	(* QHandleContextIndexAndInt32	)	(void* context, qsize index, qint8    value  );
typedef void	(* QHandleContextIndexAndInt64	)	(void* context, qsize index, qint8    value  );
typedef void	(* QHandleContextIndexAndFloat	)	(void* context, qsize index, qfloat   value  );
typedef void	(* QHandleContextIndexAndDouble )	(void* context, qsize index, qdouble  value  );
typedef void	(* QHandleContextIndexAndLDouble)	(void* context, qsize index, qldouble value  );
typedef void	(* QHandleContextIndexAndPointer)	(void* context, qsize index, void*    pointer);

typedef void	(* QHandleContextIndexUInt8AndData  )	(void* context, qsize index, quint8   value,   void* data);
typedef void	(* QHandleContextIndexUInt16AndData )	(void* context, qsize index, quint8   value,   void* data);
typedef void	(* QHandleContextIndexUInt32AndData )	(void* context, qsize index, quint8   value,   void* data);
typedef void	(* QHandleContextIndexUInt64AndData )	(void* context, qsize index, quint8   value,   void* data);
typedef void	(* QHandleContextIndexInt8AndData   )	(void* context, qsize index, qint8    value,   void* data);
typedef void	(* QHandleContextIndexInt16AndData  )	(void* context, qsize index, qint8    value,   void* data);
typedef void	(* QHandleContextIndexInt32AndData  )	(void* context, qsize index, qint8    value,   void* data);
typedef void	(* QHandleContextIndexInt64AndData  )	(void* context, qsize index, qint8    value,   void* data);
typedef void	(* QHandleContextIndexFloatAndData  )	(void* context, qsize index, qfloat   value,   void* data);
typedef void	(* QHandleContextIndexDoubleAndData )	(void* context, qsize index, qdouble  value,   void* data);
typedef void	(* QHandleContextIndexLDoubleAndData)	(void* context, qsize index, qldouble value,   void* data);
typedef void	(* QHandleContextIndexPointerAndData)	(void* context, qsize index, void*    pointer, void* data);

#pragma mark - Generic handler with stop types

typedef void	(* QHandleUInt8AndStop  )			(quint8   value,   qboolean *stop);
typedef void	(* QHandleUInt16AndStop )			(quint8   value,   qboolean *stop);
typedef void	(* QHandleUInt32AndStop )			(quint8   value,   qboolean *stop);
typedef void	(* QHandleUInt64AndStop )			(quint8   value,   qboolean *stop);
typedef void	(* QHandleInt8AndStop	)			(qint8	  value,   qboolean *stop);
typedef void	(* QHandleInt16AndStop  )			(qint8	  value,   qboolean *stop);
typedef void	(* QHandleInt32AndStop  )			(qint8	  value,   qboolean *stop);
typedef void	(* QHandleInt64AndStop  )			(qint8	  value,   qboolean *stop);
typedef void	(* QHandleFloatAndStop  )			(qfloat   value,   qboolean *stop);
typedef void	(* QHandleDoubleAndStop )			(qdouble  value,   qboolean *stop);
typedef void	(* QHandleLDoubleAndStop)			(qldouble value,   qboolean *stop);
typedef void	(* QHandlePointerAndStop)			(void*	  pointer, qboolean *stop);

typedef void	(* QHandleUInt8DataAndStop  )			(quint8   value,   void* data, qboolean *stop);
typedef void	(* QHandleUInt16DataAndStop )			(quint8   value,   void* data, qboolean *stop);
typedef void	(* QHandleUInt32DataAndStop )			(quint8   value,   void* data, qboolean *stop);
typedef void	(* QHandleUInt64DataAndStop )			(quint8   value,   void* data, qboolean *stop);
typedef void	(* QHandleInt8DataAndStop   )			(qint8	  value,   void* data, qboolean *stop);
typedef void	(* QHandleInt16DataAndStop  )			(qint8	  value,   void* data, qboolean *stop);
typedef void	(* QHandleInt32DataAndStop  )			(qint8	  value,   void* data, qboolean *stop);
typedef void	(* QHandleInt64DataAndStop  )			(qint8	  value,   void* data, qboolean *stop);
typedef void	(* QHandleFloatDataAndStop  )			(qfloat   value,   void* data, qboolean *stop);
typedef void	(* QHandleDoubleDataAndStop )			(qdouble  value,   void* data, qboolean *stop);
typedef void	(* QHandleLDoubleDataAndStop)			(qldouble value,   void* data, qboolean *stop);
typedef void	(* QHandlePointerDataAndStop)			(void*	  pointer, void* data, qboolean *stop);

typedef void	(* QHandleIndexAndStop	  )			(qsize index,		  qboolean *stop);
typedef void	(* QHandleIndexDataAndStop)			(qsize index, void *data, qboolean *stop);

typedef void	(* QHandleIndexUInt8AndStop  )			(qsize index, quint8   value,	qboolean *stop);
typedef void	(* QHandleIndexUInt16AndStop )			(qsize index, quint8   value,	qboolean *stop);
typedef void	(* QHandleIndexUInt32AndStop )			(qsize index, quint8   value,	qboolean *stop);
typedef void	(* QHandleIndexUInt64AndStop )			(qsize index, quint8   value,	qboolean *stop);
typedef void	(* QHandleIndexInt8AndStop   )			(qsize index, qint8    value,	qboolean *stop);
typedef void	(* QHandleIndexInt16AndStop  )			(qsize index, qint8    value,	qboolean *stop);
typedef void	(* QHandleIndexInt32AndStop  )			(qsize index, qint8    value,	qboolean *stop);
typedef void	(* QHandleIndexInt64AndStop  )			(qsize index, qint8    value,	qboolean *stop);
typedef void	(* QHandleIndexFloatAndStop  )			(qsize index, qfloat   value,	qboolean *stop);
typedef void	(* QHandleIndexDoubleAndStop )			(qsize index, qdouble  value,	qboolean *stop);
typedef void	(* QHandleIndexLDoubleAndStop)			(qsize index, qldouble value,	qboolean *stop);
typedef void	(* QHandleIndexPointerAndStop)			(qsize index, void*    pointer, qboolean *stop);

typedef void	(* QHandleIndexUInt8DataAndStop  )		(qsize index, quint8   value,	void* data, qboolean *stop);
typedef void	(* QHandleIndexUInt16DataAndStop )		(qsize index, quint8   value,	void* data, qboolean *stop);
typedef void	(* QHandleIndexUInt32DataAndStop )		(qsize index, quint8   value,	void* data, qboolean *stop);
typedef void	(* QHandleIndexUInt64DataAndStop )		(qsize index, quint8   value,	void* data, qboolean *stop);
typedef void	(* QHandleIndexInt8DataAndStop   )		(qsize index, qint8    value,	void* data, qboolean *stop);
typedef void	(* QHandleIndexInt16DataAndStop  )		(qsize index, qint8    value,	void* data, qboolean *stop);
typedef void	(* QHandleIndexInt32DataAndStop  )		(qsize index, qint8    value,	void* data, qboolean *stop);
typedef void	(* QHandleIndexInt64DataAndStop  )		(qsize index, qint8    value,	void* data, qboolean *stop);
typedef void	(* QHandleIndexFloatDataAndStop  )		(qsize index, qfloat   value,	void* data, qboolean *stop);
typedef void	(* QHandleIndexDoubleDataAndStop )		(qsize index, qdouble  value,	void* data, qboolean *stop);
typedef void	(* QHandleIndexLDoubleDataAndStop)		(qsize index, qldouble value,	void* data, qboolean *stop);
typedef void	(* QHandleIndexPointerDataAndStop)		(qsize index, void*    pointer, void* data, qboolean *stop);

typedef void	(* QHandleContextUInt8AndStop  )		(void* context, quint8	 value,	  qboolean *stop);
typedef void	(* QHandleContextUInt16AndStop )		(void* context, quint8	 value,	  qboolean *stop);
typedef void	(* QHandleContextUInt32AndStop )		(void* context, quint8	 value,	  qboolean *stop);
typedef void	(* QHandleContextUInt64AndStop )		(void* context, quint8	 value,	  qboolean *stop);
typedef void	(* QHandleContextInt8AndStop   )		(void* context, qint8	 value,	  qboolean *stop);
typedef void	(* QHandleContextInt16AndStop  )		(void* context, qint8	 value,	  qboolean *stop);
typedef void	(* QHandleContextInt32AndStop  )		(void* context, qint8	 value,	  qboolean *stop);
typedef void	(* QHandleContextInt64AndStop  )		(void* context, qint8	 value,	  qboolean *stop);
typedef void	(* QHandleContextFloatAndStop  )		(void* context, qfloat	 value,	  qboolean *stop);
typedef void	(* QHandleContextDoubleAndStop )		(void* context, qdouble  value,	  qboolean *stop);
typedef void	(* QHandleContextLDoubleAndStop)		(void* context, qldouble value,	  qboolean *stop);
typedef void	(* QHandleContextPointerAndStop)		(void* context, void*	 pointer, qboolean *stop);

typedef void	(* QHandleContextUInt8DataAndStop  )		(void* context, quint8	 value,   void* data, qboolean *stop);
typedef void	(* QHandleContextUInt16DataAndStop )		(void* context, quint8	 value,   void* data, qboolean *stop);
typedef void	(* QHandleContextUInt32DataAndStop )		(void* context, quint8	 value,   void* data, qboolean *stop);
typedef void	(* QHandleContextUInt64DataAndStop )		(void* context, quint8	 value,   void* data, qboolean *stop);
typedef void	(* QHandleContextInt8DataAndStop   )		(void* context, qint8	 value,   void* data, qboolean *stop);
typedef void	(* QHandleContextInt16DataAndStop  )		(void* context, qint8	 value,   void* data, qboolean *stop);
typedef void	(* QHandleContextInt32DataAndStop  )		(void* context, qint8	 value,   void* data, qboolean *stop);
typedef void	(* QHandleContextInt64DataAndStop  )		(void* context, qint8	 value,   void* data, qboolean *stop);
typedef void	(* QHandleContextFloatDataAndStop  )		(void* context, qfloat	 value,   void* data, qboolean *stop);
typedef void	(* QHandleContextDoubleDataAndStop )		(void* context, qdouble  value,   void* data, qboolean *stop);
typedef void	(* QHandleContextLDoubleDataAndStop)		(void* context, qldouble value,   void* data, qboolean *stop);
typedef void	(* QHandleContextPointerDataAndStop)		(void* context, void*	 pointer, void* data, qboolean *stop);

typedef void	(* QHandleContextIndexAndStop    )		(void* context, qsize index,		 qboolean *stop);
typedef void	(* QHandleContextIndexDataAndStop)		(void* context, qsize index, void* data, qboolean *stop);

typedef void	(* QHandleContextIndexUInt8AndStop  )		(void* context, qsize index, quint8   value,   qboolean *stop);
typedef void	(* QHandleContextIndexUInt16AndStop )		(void* context, qsize index, quint8   value,   qboolean *stop);
typedef void	(* QHandleContextIndexUInt32AndStop )		(void* context, qsize index, quint8   value,   qboolean *stop);
typedef void	(* QHandleContextIndexUInt64AndStop )		(void* context, qsize index, quint8   value,   qboolean *stop);
typedef void	(* QHandleContextIndexInt8AndStop   )		(void* context, qsize index, qint8    value,   qboolean *stop);
typedef void	(* QHandleContextIndexInt16AndStop  )		(void* context, qsize index, qint8    value,   qboolean *stop);
typedef void	(* QHandleContextIndexInt32AndStop  )		(void* context, qsize index, qint8    value,   qboolean *stop);
typedef void	(* QHandleContextIndexInt64AndStop  )		(void* context, qsize index, qint8    value,   qboolean *stop);
typedef void	(* QHandleContextIndexFloatAndStop  )		(void* context, qsize index, qfloat   value,   qboolean *stop);
typedef void	(* QHandleContextIndexDoubleAndStop )		(void* context, qsize index, qdouble  value,   qboolean *stop);
typedef void	(* QHandleContextIndexLDoubleAndStop)		(void* context, qsize index, qldouble value,   qboolean *stop);
typedef void	(* QHandleContextIndexPointerAndStop)		(void* context, qsize index, void*    pointer, qboolean *stop);

typedef void	(* QHandleContextIndexUInt8DataAndStop  )	(void* context, qsize index, quint8   value,   void* data, qboolean *stop);
typedef void	(* QHandleContextIndexUInt16DataAndStop )	(void* context, qsize index, quint8   value,   void* data, qboolean *stop);
typedef void	(* QHandleContextIndexUInt32DataAndStop )	(void* context, qsize index, quint8   value,   void* data, qboolean *stop);
typedef void	(* QHandleContextIndexUInt64DataAndStop )	(void* context, qsize index, quint8   value,   void* data, qboolean *stop);
typedef void	(* QHandleContextIndexInt8DataAndStop   )	(void* context, qsize index, qint8    value,   void* data, qboolean *stop);
typedef void	(* QHandleContextIndexInt16DataAndStop  )	(void* context, qsize index, qint8    value,   void* data, qboolean *stop);
typedef void	(* QHandleContextIndexInt32DataAndStop  )	(void* context, qsize index, qint8    value,   void* data, qboolean *stop);
typedef void	(* QHandleContextIndexInt64DataAndStop  )	(void* context, qsize index, qint8    value,   void* data, qboolean *stop);
typedef void	(* QHandleContextIndexFloatDataAndStop  )	(void* context, qsize index, qfloat   value,   void* data, qboolean *stop);
typedef void	(* QHandleContextIndexDoubleDataAndStop )	(void* context, qsize index, qdouble  value,   void* data, qboolean *stop);
typedef void	(* QHandleContextIndexLDoubleDataAndStop)	(void* context, qsize index, qldouble value,   void* data, qboolean *stop);
typedef void	(* QHandleContextIndexPointerDataAndStop)	(void* context, qsize index, void*    pointer, void* data, qboolean *stop);

#pragma mark - Per type redefinitions

#if Q_SHORT_BITS == 16
	typedef	QHandleUInt16				QHandleUShort;
	typedef QHandleInt16				QHandleShort;
	typedef QHandleUInt16AndData			QHandleUShortAndData;
	typedef QHandleInt16AndData			QHandleShortAndData;
	typedef QHandleIndexAndUInt16			QHandleIndexAndUShort;
	typedef QHandleIndexAndInt16			QHandleIndexAndShort;
	typedef QHandleIndexUInt16AndData		QHandleIndexUShortAndData;
	typedef QHandleIndexInt16AndData		QHandleIndexShortAndData;
	typedef QHandleContextAndUInt16			QHandleContextAndUShort;
	typedef QHandleContextAndInt16			QHandleContextAndShort;
	typedef QHandleContextUInt16AndData		QHandleContextUShortAndData;
	typedef QHandleContextInt16AndData		QHandleContextShortAndData;
	typedef QHandleContextIndexAndUInt16		QHandleContextIndexAndUShort;
	typedef QHandleContextIndexAndInt16		QHandleContextIndexAndShort;
	typedef QHandleContextIndexUInt16AndData	QHandleContextIndexUShortAndData;
	typedef QHandleContextIndexInt16AndData		QHandleContextIndexShortAndData;
#elif Q_SHORT_BITS == 32
	typedef	QHandleUInt32				QHandleUShort;
	typedef QHandleInt32				QHandleShort;
	typedef QHandleUInt32AndData			QHandleUShortAndData;
	typedef QHandleInt32AndData			QHandleShortAndData;
	typedef QHandleIndexAndUInt32			QHandleIndexAndUShort;
	typedef QHandleIndexAndInt32			QHandleIndexAndShort;
	typedef QHandleIndexUInt32AndData		QHandleIndexUShortAndData;
	typedef QHandleIndexInt32AndData		QHandleIndexShortAndData;
	typedef QHandleContextAndUInt32			QHandleContextAndUShort;
	typedef QHandleContextAndInt32			QHandleContextAndShort;
	typedef QHandleContextUInt32AndData		QHandleContextUShortAndData;
	typedef QHandleContextInt32AndData		QHandleContextShortAndData;
	typedef QHandleContextIndexAndUInt32		QHandleContextIndexAndUShort;
	typedef QHandleContextIndexAndInt32		QHandleContextIndexAndShort;
	typedef QHandleContextIndexUInt32AndData	QHandleContextIndexUShortAndData;
	typedef QHandleContextIndexInt32AndData		QHandleContextIndexShortAndData;
#endif

#if Q_INT_BITS == 16
	typedef	QHandleUInt16				QHandleUInt;
	typedef QHandleInt16				QHandleInt;
	typedef QHandleUInt16AndData			QHandleUIntAndData;
	typedef QHandleInt16AndData			QHandleIntAndData;
	typedef QHandleIndexAndUInt16			QHandleIndexAndUInt;
	typedef QHandleIndexAndInt16			QHandleIndexAndInt;
	typedef QHandleIndexUInt16AndData		QHandleIndexUIntAndData;
	typedef QHandleIndexInt16AndData		QHandleIndexIntAndData;
	typedef QHandleContextAndUInt16			QHandleContextAndUInt;
	typedef QHandleContextAndInt16			QHandleContextAndInt;
	typedef QHandleContextUInt16AndData		QHandleContextUIntAndData;
	typedef QHandleContextInt16AndData		QHandleContextIntAndData;
	typedef QHandleContextIndexAndUInt16		QHandleContextIndexAndUInt;
	typedef QHandleContextIndexAndInt16		QHandleContextIndexAndInt;
	typedef QHandleContextIndexUInt16AndData	QHandleContextIndexUIntAndData;
	typedef QHandleContextIndexInt16AndData		QHandleContextIndexIntAndData;
#elif Q_INT_BITS == 32
	typedef	QHandleUInt32				QHandleUInt;
	typedef QHandleInt32				QHandleInt;
	typedef QHandleUInt32AndData			QHandleUIntAndData;
	typedef QHandleInt32AndData			QHandleIntAndData;
	typedef QHandleIndexAndUInt32			QHandleIndexAndUInt;
	typedef QHandleIndexAndInt32			QHandleIndexAndInt;
	typedef QHandleIndexUInt32AndData		QHandleIndexUIntAndData;
	typedef QHandleIndexInt32AndData		QHandleIndexIntAndData;
	typedef QHandleContextAndUInt32			QHandleContextAndUInt;
	typedef QHandleContextAndInt32			QHandleContextAndInt;
	typedef QHandleContextUInt32AndData		QHandleContextUIntAndData;
	typedef QHandleContextInt32AndData		QHandleContextIntAndData;
	typedef QHandleContextIndexAndUInt32		QHandleContextIndexAndUInt;
	typedef QHandleContextIndexAndInt32		QHandleContextIndexAndInt;
	typedef QHandleContextIndexUInt32AndData	QHandleContextIndexUIntAndData;
	typedef QHandleContextIndexInt32AndData		QHandleContextIndexIntAndData;
#elif Q_INT_BITS == 64
	typedef	QHandleUInt64				QHandleUInt;
	typedef QHandleInt64				QHandleInt;
	typedef QHandleUInt64AndData			QHandleUIntAndData;
	typedef QHandleInt64AndData			QHandleIntAndData;
	typedef QHandleIndexAndUInt64			QHandleIndexAndUInt;
	typedef QHandleIndexAndInt64			QHandleIndexAndInt;
	typedef QHandleIndexUInt64AndData		QHandleIndexUIntAndData;
	typedef QHandleIndexInt64AndData		QHandleIndexIntAndData;
	typedef QHandleContextAndUInt64			QHandleContextAndUInt;
	typedef QHandleContextAndInt64			QHandleContextAndInt;
	typedef QHandleContextUInt64AndData		QHandleContextUIntAndData;
	typedef QHandleContextInt64AndData		QHandleContextIntAndData;
	typedef QHandleContextIndexAndUInt64		QHandleContextIndexAndUInt;
	typedef QHandleContextIndexAndInt64		QHandleContextIndexAndInt;
	typedef QHandleContextIndexUInt64AndData	QHandleContextIndexUIntAndData;
	typedef QHandleContextIndexInt64AndData		QHandleContextIndexIntAndData;
#endif

#if Q_LONG_BITS == 32
	typedef	QHandleUInt32				QHandleULong;
	typedef QHandleInt32				QHandleLong;
	typedef QHandleUInt32AndData			QHandleULongAndData;
	typedef QHandleInt32AndData			QHandleLongAndData;
	typedef QHandleIndexAndUInt32			QHandleIndexAndULong;
	typedef QHandleIndexAndInt32			QHandleIndexAndLong;
	typedef QHandleIndexUInt32AndData		QHandleIndexULongAndData;
	typedef QHandleIndexInt32AndData		QHandleIndexLongAndData;
	typedef QHandleContextAndUInt32			QHandleContextAndULong;
	typedef QHandleContextAndInt32			QHandleContextAndLong;
	typedef QHandleContextUInt32AndData		QHandleContextULongAndData;
	typedef QHandleContextInt32AndData		QHandleContextLongAndData;
	typedef QHandleContextIndexAndUInt32		QHandleContextIndexAndULong;
	typedef QHandleContextIndexAndInt32		QHandleContextIndexAndLong;
	typedef QHandleContextIndexUInt32AndData	QHandleContextIndexULongAndData;
	typedef QHandleContextIndexInt32AndData		QHandleContextIndexLongAndData;
#elif Q_LONG_BITS == 64
	typedef	QHandleUInt64				QHandleULong;
	typedef QHandleInt64				QHandleLong;
	typedef QHandleUInt64AndData			QHandleULongAndData;
	typedef QHandleInt64AndData			QHandleLongAndData;
	typedef QHandleIndexAndUInt64			QHandleIndexAndULong;
	typedef QHandleIndexAndInt64			QHandleIndexAndLong;
	typedef QHandleIndexUInt64AndData		QHandleIndexULongAndData;
	typedef QHandleIndexInt64AndData		QHandleIndexLongAndData;
	typedef QHandleContextAndUInt64			QHandleContextAndULong;
	typedef QHandleContextAndInt64			QHandleContextAndLong;
	typedef QHandleContextUInt64AndData		QHandleContextULongAndData;
	typedef QHandleContextInt64AndData		QHandleContextLongAndData;
	typedef QHandleContextIndexAndUInt64		QHandleContextIndexAndULong;
	typedef QHandleContextIndexAndInt64		QHandleContextIndexAndLong;
	typedef QHandleContextIndexUInt64AndData	QHandleContextIndexULongAndData;
	typedef QHandleContextIndexInt64AndData		QHandleContextIndexLongAndData;
#endif

#if Q_LLONG_BITS == 32
	typedef	QHandleUInt32				QHandleULLong;
	typedef QHandleInt32				QHandleLLong;
	typedef QHandleUInt32AndData			QHandleULLongAndData;
	typedef QHandleInt32AndData			QHandleLLongAndData;
	typedef QHandleIndexAndUInt32			QHandleIndexAndULLong;
	typedef QHandleIndexAndInt32			QHandleIndexAndLLong;
	typedef QHandleIndexUInt32AndData		QHandleIndexULLongAndData;
	typedef QHandleIndexInt32AndData		QHandleIndexLLongAndData;
	typedef QHandleContextAndUInt32			QHandleContextAndULLong;
	typedef QHandleContextAndInt32			QHandleContextAndLLong;
	typedef QHandleContextUInt32AndData		QHandleContextULLongAndData;
	typedef QHandleContextInt32AndData		QHandleContextLLongAndData;
	typedef QHandleContextIndexAndUInt32		QHandleContextIndexAndULLong;
	typedef QHandleContextIndexAndInt32		QHandleContextIndexAndLLong;
	typedef QHandleContextIndexUInt32AndData	QHandleContextIndexULLongAndData;
	typedef QHandleContextIndexInt32AndData		QHandleContextIndexLLongAndData;
#elif Q_LLONG_BITS == 64
	typedef	QHandleUInt64				QHandleULLong;
	typedef QHandleInt64				QHandleLLong;
	typedef QHandleUInt64AndData			QHandleULLongAndData;
	typedef QHandleInt64AndData			QHandleLLongAndData;
	typedef QHandleIndexAndUInt64			QHandleIndexAndULLong;
	typedef QHandleIndexAndInt64			QHandleIndexAndLLong;
	typedef QHandleIndexUInt64AndData		QHandleIndexULLongAndData;
	typedef QHandleIndexInt64AndData		QHandleIndexLLongAndData;
	typedef QHandleContextAndUInt64			QHandleContextAndULLong;
	typedef QHandleContextAndInt64			QHandleContextAndLLong;
	typedef QHandleContextUInt64AndData		QHandleContextULLongAndData;
	typedef QHandleContextInt64AndData		QHandleContextLLongAndData;
	typedef QHandleContextIndexAndUInt64		QHandleContextIndexAndULLong;
	typedef QHandleContextIndexAndInt64		QHandleContextIndexAndLLong;
	typedef QHandleContextIndexUInt64AndData	QHandleContextIndexULLongAndData;
	typedef QHandleContextIndexInt64AndData		QHandleContextIndexLLongAndData;
#endif

#if Q_SIZE_BITS == 32
	typedef	QHandleUInt32				QHandleSize;
	typedef QHandleInt32				QHandleSSize;
	typedef QHandleUInt32AndData			QHandleSizeAndData;
	typedef QHandleInt32AndData			QHandleSSizeAndData;
	typedef QHandleIndexAndUInt32			QHandleIndexAndSize;
	typedef QHandleIndexAndInt32			QHandleIndexAndSSize;
	typedef QHandleIndexUInt32AndData		QHandleIndexSizeAndData;
	typedef QHandleIndexInt32AndData		QHandleIndexSSizeAndData;
	typedef QHandleContextAndUInt32			QHandleContextAndSize;
	typedef QHandleContextAndInt32			QHandleContextAndSSize;
	typedef QHandleContextUInt32AndData		QHandleContextSizeAndData;
	typedef QHandleContextInt32AndData		QHandleContextSSizeAndData;
	typedef QHandleContextIndexAndUInt32		QHandleContextIndexAndSize;
	typedef QHandleContextIndexAndInt32		QHandleContextIndexAndSSize;
	typedef QHandleContextIndexUInt32AndData	QHandleContextIndexSizeAndData;
	typedef QHandleContextIndexInt32AndData		QHandleContextIndexSSizeAndData;
#elif Q_SIZE_BITS == 64
	typedef	QHandleUInt64				QHandleSize;
	typedef QHandleInt64				QHandleSSize;
	typedef QHandleUInt64AndData			QHandleSizeAndData;
	typedef QHandleInt64AndData			QHandleSSizeAndData;
	typedef QHandleIndexAndUInt64			QHandleIndexAndSize;
	typedef QHandleIndexAndInt64			QHandleIndexAndSSize;
	typedef QHandleIndexUInt64AndData		QHandleIndexSizeAndData;
	typedef QHandleIndexInt64AndData		QHandleIndexSSizeAndData;
	typedef QHandleContextAndUInt64			QHandleContextAndSize;
	typedef QHandleContextAndInt64			QHandleContextAndSSize;
	typedef QHandleContextUInt64AndData		QHandleContextSizeAndData;
	typedef QHandleContextInt64AndData		QHandleContextSSizeAndData;
	typedef QHandleContextIndexAndUInt64		QHandleContextIndexAndSize;
	typedef QHandleContextIndexAndInt64		QHandleContextIndexAndSSize;
	typedef QHandleContextIndexUInt64AndData	QHandleContextIndexSizeAndData;
	typedef QHandleContextIndexInt64AndData		QHandleContextIndexSSizeAndData;
#endif

#pragma mark - Indirect handle call type

typedef void	(* QCallHandle)	(QFunctionContextAndData* call,
				 QBaseAndIndex*		  data);

#endif /* __Q_types_handling_H__ */
