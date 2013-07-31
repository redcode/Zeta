/* Q API - types/validation.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2012 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_types_validation_H__
#define __Q_types_validation_H__

#include <Q/types/basics.h>

#pragma mark - Generic validator types

typedef qboolean	(* QValidateUInt8  )			(quint8   value  );
typedef qboolean	(* QValidateUInt16 )			(quint8   value  );
typedef qboolean	(* QValidateUInt32 )			(quint8   value  );
typedef qboolean	(* QValidateUInt64 )			(quint8   value  );
typedef qboolean	(* QValidateInt8   )			(qint8	  value  );
typedef qboolean	(* QValidateInt16  )			(qint8	  value  );
typedef qboolean	(* QValidateInt32  )			(qint8	  value  );
typedef qboolean	(* QValidateInt64  )			(qint8	  value  );
typedef qboolean	(* QValidateFloat  )			(qfloat   value  );
typedef qboolean	(* QValidateDouble )			(qdouble  value  );
typedef qboolean	(* QValidateLDouble)			(qldouble value  );
typedef qboolean	(* QValidatePointer)			(void*	  pointer);

typedef qboolean	(* QValidateUInt8AndData  )		(quint8   value,   void* data);
typedef qboolean	(* QValidateUInt16AndData )		(quint8   value,   void* data);
typedef qboolean	(* QValidateUInt32AndData )		(quint8   value,   void* data);
typedef qboolean	(* QValidateUInt64AndData )		(quint8   value,   void* data);
typedef qboolean	(* QValidateInt8AndData   )		(qint8	  value,   void* data);
typedef qboolean	(* QValidateInt16AndData  )		(qint8	  value,   void* data);
typedef qboolean	(* QValidateInt32AndData  )		(qint8	  value,   void* data);
typedef qboolean	(* QValidateInt64AndData  )		(qint8	  value,   void* data);
typedef qboolean	(* QValidateFloatAndData  )		(qfloat   value,   void* data);
typedef qboolean	(* QValidateDoubleAndData )		(qdouble  value,   void* data);
typedef qboolean	(* QValidateLDoubleAndData)		(qldouble value,   void* data);
typedef qboolean	(* QValidatePointerAndData)		(void*	  pointer, void* data);

typedef qboolean	(* QValidateIndex	   )		(qsize index		      );
typedef qboolean	(* QValidateIndexAndData   )		(qsize index, void*    data   );
typedef qboolean	(* QValidateIndexAndUInt8  )		(qsize index, quint8   value  );
typedef qboolean	(* QValidateIndexAndUInt16 )		(qsize index, quint8   value  );
typedef qboolean	(* QValidateIndexAndUInt32 )		(qsize index, quint8   value  );
typedef qboolean	(* QValidateIndexAndUInt64 )		(qsize index, quint8   value  );
typedef qboolean	(* QValidateIndexAndInt8   )		(qsize index, qint8    value  );
typedef qboolean	(* QValidateIndexAndInt16  )		(qsize index, qint8    value  );
typedef qboolean	(* QValidateIndexAndInt32  )		(qsize index, qint8    value  );
typedef qboolean	(* QValidateIndexAndInt64  )		(qsize index, qint8    value  );
typedef qboolean	(* QValidateIndexAndFloat  )		(qsize index, qfloat   value  );
typedef qboolean	(* QValidateIndexAndDouble )		(qsize index, qdouble  value  );
typedef qboolean	(* QValidateIndexAndLDouble)		(qsize index, qldouble value  );
typedef qboolean	(* QValidateIndexAndPointer)		(qsize index, void*    pointer);

typedef qboolean	(* QValidateIndexUInt8AndData  )	(qsize index, quint8   value,	void* data);
typedef qboolean	(* QValidateIndexUInt16AndData )	(qsize index, quint8   value,	void* data);
typedef qboolean	(* QValidateIndexUInt32AndData )	(qsize index, quint8   value,	void* data);
typedef qboolean	(* QValidateIndexUInt64AndData )	(qsize index, quint8   value,	void* data);
typedef qboolean	(* QValidateIndexInt8AndData   )	(qsize index, qint8    value,	void* data);
typedef qboolean	(* QValidateIndexInt16AndData  )	(qsize index, qint8    value,	void* data);
typedef qboolean	(* QValidateIndexInt32AndData  )	(qsize index, qint8    value,	void* data);
typedef qboolean	(* QValidateIndexInt64AndData  )	(qsize index, qint8    value,	void* data);
typedef qboolean	(* QValidateIndexFloatAndData  )	(qsize index, qfloat   value,	void* data);
typedef qboolean	(* QValidateIndexDoubleAndData )	(qsize index, qdouble  value,	void* data);
typedef qboolean	(* QValidateIndexLDoubleAndData)	(qsize index, qldouble value,	void* data);
typedef qboolean	(* QValidateIndexPointerAndData)	(qsize index, void*    pointer, void* data);

typedef qboolean	(* QValidateContextAndUInt8  )		(void* context, quint8	 value	);
typedef qboolean	(* QValidateContextAndUInt16 )		(void* context, quint8	 value	);
typedef qboolean	(* QValidateContextAndUInt32 )		(void* context, quint8	 value	);
typedef qboolean	(* QValidateContextAndUInt64 )		(void* context, quint8	 value	);
typedef qboolean	(* QValidateContextAndInt8   )		(void* context, qint8	 value	);
typedef qboolean	(* QValidateContextAndInt16  )		(void* context, qint8	 value	);
typedef qboolean	(* QValidateContextAndInt32  )		(void* context, qint8	 value	);
typedef qboolean	(* QValidateContextAndInt64  )		(void* context, qint8	 value	);
typedef qboolean	(* QValidateContextAndFloat  )		(void* context, qfloat	 value	);
typedef qboolean	(* QValidateContextAndDouble )		(void* context, qdouble  value	);
typedef qboolean	(* QValidateContextAndLDouble)		(void* context, qldouble value	);
typedef qboolean	(* QValidateContextAndPointer)		(void* context, void*	 pointer);

typedef qboolean	(* QValidateContextUInt8AndData  )	(void* context, quint8	 value,   void* data);
typedef qboolean	(* QValidateContextUInt16AndData )	(void* context, quint8	 value,   void* data);
typedef qboolean	(* QValidateContextUInt32AndData )	(void* context, quint8	 value,   void* data);
typedef qboolean	(* QValidateContextUInt64AndData )	(void* context, quint8	 value,   void* data);
typedef qboolean	(* QValidateContextInt8AndData	 )	(void* context, qint8	 value,   void* data);
typedef qboolean	(* QValidateContextInt16AndData  )	(void* context, qint8	 value,   void* data);
typedef qboolean	(* QValidateContextInt32AndData  )	(void* context, qint8	 value,   void* data);
typedef qboolean	(* QValidateContextInt64AndData  )	(void* context, qint8	 value,   void* data);
typedef qboolean	(* QValidateContextFloatAndData  )	(void* context, qfloat	 value,   void* data);
typedef qboolean	(* QValidateContextDoubleAndData )	(void* context, qdouble  value,   void* data);
typedef qboolean	(* QValidateContextLDoubleAndData)	(void* context, qldouble value,   void* data);
typedef qboolean	(* QValidateContextPointerAndData)	(void* context, void*	 pointer, void* data);

typedef qboolean	(* QValidateContextAndIndex    )	(void* context, qsize index	       );
typedef qboolean	(* QValidateContextIndexAndData)	(void* context, qsize index, void* data);

typedef qboolean	(* QValidateContextIndexAndUInt8  )	(void* context, qsize index, quint8   value  );
typedef qboolean	(* QValidateContextIndexAndUInt16 )	(void* context, qsize index, quint8   value  );
typedef qboolean	(* QValidateContextIndexAndUInt32 )	(void* context, qsize index, quint8   value  );
typedef qboolean	(* QValidateContextIndexAndUInt64 )	(void* context, qsize index, quint8   value  );
typedef qboolean	(* QValidateContextIndexAndInt8   )	(void* context, qsize index, qint8    value  );
typedef qboolean	(* QValidateContextIndexAndInt16  )	(void* context, qsize index, qint8    value  );
typedef qboolean	(* QValidateContextIndexAndInt32  )	(void* context, qsize index, qint8    value  );
typedef qboolean	(* QValidateContextIndexAndInt64  )	(void* context, qsize index, qint8    value  );
typedef qboolean	(* QValidateContextIndexAndFloat  )	(void* context, qsize index, qfloat   value  );
typedef qboolean	(* QValidateContextIndexAndDouble )	(void* context, qsize index, qdouble  value  );
typedef qboolean	(* QValidateContextIndexAndLDouble)	(void* context, qsize index, qldouble value  );
typedef qboolean	(* QValidateContextIndexAndPointer)	(void* context, qsize index, void*    pointer);

typedef qboolean	(* QValidateContextIndexUInt8AndData  )	(void* context, qsize index, quint8   value,   void* data);
typedef qboolean	(* QValidateContextIndexUInt16AndData )	(void* context, qsize index, quint8   value,   void* data);
typedef qboolean	(* QValidateContextIndexUInt32AndData )	(void* context, qsize index, quint8   value,   void* data);
typedef qboolean	(* QValidateContextIndexUInt64AndData )	(void* context, qsize index, quint8   value,   void* data);
typedef qboolean	(* QValidateContextIndexInt8AndData   )	(void* context, qsize index, qint8    value,   void* data);
typedef qboolean	(* QValidateContextIndexInt16AndData  )	(void* context, qsize index, qint8    value,   void* data);
typedef qboolean	(* QValidateContextIndexInt32AndData  )	(void* context, qsize index, qint8    value,   void* data);
typedef qboolean	(* QValidateContextIndexInt64AndData  )	(void* context, qsize index, qint8    value,   void* data);
typedef qboolean	(* QValidateContextIndexFloatAndData  )	(void* context, qsize index, qfloat   value,   void* data);
typedef qboolean	(* QValidateContextIndexDoubleAndData )	(void* context, qsize index, qdouble  value,   void* data);
typedef qboolean	(* QValidateContextIndexLDoubleAndData)	(void* context, qsize index, qldouble value,   void* data);
typedef qboolean	(* QValidateContextIndexPointerAndData)	(void* context, qsize index, void*    pointer, void* data);

#pragma mark - Per type redefinitions

#if Q_SHORT_BITS == 16
	typedef	QValidateUInt16				QValidateUShort;
	typedef QValidateInt16				QValidateShort;
	typedef QValidateUInt16AndData			QValidateUShortAndData;
	typedef QValidateInt16AndData			QValidateShortAndData;
	typedef QValidateIndexAndUInt16			QValidateIndexAndUShort;
	typedef QValidateIndexAndInt16			QValidateIndexAndShort;
	typedef QValidateIndexUInt16AndData		QValidateIndexUShortAndData;
	typedef QValidateIndexInt16AndData		QValidateIndexShortAndData;
	typedef QValidateContextAndUInt16		QValidateContextAndUShort;
	typedef QValidateContextAndInt16		QValidateContextAndShort;
	typedef QValidateContextUInt16AndData		QValidateContextUShortAndData;
	typedef QValidateContextInt16AndData		QValidateContextShortAndData;
	typedef QValidateContextIndexAndUInt16		QValidateContextIndexAndUShort;
	typedef QValidateContextIndexAndInt16		QValidateContextIndexAndShort;
	typedef QValidateContextIndexUInt16AndData	QValidateContextIndexUShortAndData;
	typedef QValidateContextIndexInt16AndData	QValidateContextIndexShortAndData;
#elif Q_SHORT_BITS == 32
	typedef	QValidateUInt32				QValidateUShort;
	typedef QValidateInt32				QValidateShort;
	typedef QValidateUInt32AndData			QValidateUShortAndData;
	typedef QValidateInt32AndData			QValidateShortAndData;
	typedef QValidateIndexAndUInt32			QValidateIndexAndUShort;
	typedef QValidateIndexAndInt32			QValidateIndexAndShort;
	typedef QValidateIndexUInt32AndData		QValidateIndexUShortAndData;
	typedef QValidateIndexInt32AndData		QValidateIndexShortAndData;
	typedef QValidateContextAndUInt32		QValidateContextAndUShort;
	typedef QValidateContextAndInt32		QValidateContextAndShort;
	typedef QValidateContextUInt32AndData		QValidateContextUShortAndData;
	typedef QValidateContextInt32AndData		QValidateContextShortAndData;
	typedef QValidateContextIndexAndUInt32		QValidateContextIndexAndUShort;
	typedef QValidateContextIndexAndInt32		QValidateContextIndexAndShort;
	typedef QValidateContextIndexUInt32AndData	QValidateContextIndexUShortAndData;
	typedef QValidateContextIndexInt32AndData	QValidateContextIndexShortAndData;
#endif

#if Q_INT_BITS == 16
	typedef	QValidateUInt16				QValidateUInt;
	typedef QValidateInt16				QValidateInt;
	typedef QValidateUInt16AndData			QValidateUIntAndData;
	typedef QValidateInt16AndData			QValidateIntAndData;
	typedef QValidateIndexAndUInt16			QValidateIndexAndUInt;
	typedef QValidateIndexAndInt16			QValidateIndexAndInt;
	typedef QValidateIndexUInt16AndData		QValidateIndexUIntAndData;
	typedef QValidateIndexInt16AndData		QValidateIndexIntAndData;
	typedef QValidateContextAndUInt16		QValidateContextAndUInt;
	typedef QValidateContextAndInt16		QValidateContextAndInt;
	typedef QValidateContextUInt16AndData		QValidateContextUIntAndData;
	typedef QValidateContextInt16AndData		QValidateContextIntAndData;
	typedef QValidateContextIndexAndUInt16		QValidateContextIndexAndUInt;
	typedef QValidateContextIndexAndInt16		QValidateContextIndexAndInt;
	typedef QValidateContextIndexUInt16AndData	QValidateContextIndexUIntAndData;
	typedef QValidateContextIndexInt16AndData	QValidateContextIndexIntAndData;
#elif Q_INT_BITS == 32
	typedef	QValidateUInt32				QValidateUInt;
	typedef QValidateInt32				QValidateInt;
	typedef QValidateUInt32AndData			QValidateUIntAndData;
	typedef QValidateInt32AndData			QValidateIntAndData;
	typedef QValidateIndexAndUInt32			QValidateIndexAndUInt;
	typedef QValidateIndexAndInt32			QValidateIndexAndInt;
	typedef QValidateIndexUInt32AndData		QValidateIndexUIntAndData;
	typedef QValidateIndexInt32AndData		QValidateIndexIntAndData;
	typedef QValidateContextAndUInt32		QValidateContextAndUInt;
	typedef QValidateContextAndInt32		QValidateContextAndInt;
	typedef QValidateContextUInt32AndData		QValidateContextUIntAndData;
	typedef QValidateContextInt32AndData		QValidateContextIntAndData;
	typedef QValidateContextIndexAndUInt32		QValidateContextIndexAndUInt;
	typedef QValidateContextIndexAndInt32		QValidateContextIndexAndInt;
	typedef QValidateContextIndexUInt32AndData	QValidateContextIndexUIntAndData;
	typedef QValidateContextIndexInt32AndData	QValidateContextIndexIntAndData;
#elif Q_INT_BITS == 64
	typedef	QValidateUInt64				QValidateUInt;
	typedef QValidateInt64				QValidateInt;
	typedef QValidateUInt64AndData			QValidateUIntAndData;
	typedef QValidateInt64AndData			QValidateIntAndData;
	typedef QValidateIndexAndUInt64			QValidateIndexAndUInt;
	typedef QValidateIndexAndInt64			QValidateIndexAndInt;
	typedef QValidateIndexUInt64AndData		QValidateIndexUIntAndData;
	typedef QValidateIndexInt64AndData		QValidateIndexIntAndData;
	typedef QValidateContextAndUInt64		QValidateContextAndUInt;
	typedef QValidateContextAndInt64		QValidateContextAndInt;
	typedef QValidateContextUInt64AndData		QValidateContextUIntAndData;
	typedef QValidateContextInt64AndData		QValidateContextIntAndData;
	typedef QValidateContextIndexAndUInt64		QValidateContextIndexAndUInt;
	typedef QValidateContextIndexAndInt64		QValidateContextIndexAndInt;
	typedef QValidateContextIndexUInt64AndData	QValidateContextIndexUIntAndData;
	typedef QValidateContextIndexInt64AndData	QValidateContextIndexIntAndData;
#endif

#if Q_LONG_BITS == 32
	typedef	QValidateUInt32				QValidateULong;
	typedef QValidateInt32				QValidateLong;
	typedef QValidateUInt32AndData			QValidateULongAndData;
	typedef QValidateInt32AndData			QValidateLongAndData;
	typedef QValidateIndexAndUInt32			QValidateIndexAndULong;
	typedef QValidateIndexAndInt32			QValidateIndexAndLong;
	typedef QValidateIndexUInt32AndData		QValidateIndexULongAndData;
	typedef QValidateIndexInt32AndData		QValidateIndexLongAndData;
	typedef QValidateContextAndUInt32		QValidateContextAndULong;
	typedef QValidateContextAndInt32		QValidateContextAndLong;
	typedef QValidateContextUInt32AndData		QValidateContextULongAndData;
	typedef QValidateContextInt32AndData		QValidateContextLongAndData;
	typedef QValidateContextIndexAndUInt32		QValidateContextIndexAndULong;
	typedef QValidateContextIndexAndInt32		QValidateContextIndexAndLong;
	typedef QValidateContextIndexUInt32AndData	QValidateContextIndexULongAndData;
	typedef QValidateContextIndexInt32AndData	QValidateContextIndexLongAndData;
#elif Q_LONG_BITS == 64
	typedef	QValidateUInt64				QValidateULong;
	typedef QValidateInt64				QValidateLong;
	typedef QValidateUInt64AndData			QValidateULongAndData;
	typedef QValidateInt64AndData			QValidateLongAndData;
	typedef QValidateIndexAndUInt64			QValidateIndexAndULong;
	typedef QValidateIndexAndInt64			QValidateIndexAndLong;
	typedef QValidateIndexUInt64AndData		QValidateIndexULongAndData;
	typedef QValidateIndexInt64AndData		QValidateIndexLongAndData;
	typedef QValidateContextAndUInt64		QValidateContextAndULong;
	typedef QValidateContextAndInt64		QValidateContextAndLong;
	typedef QValidateContextUInt64AndData		QValidateContextULongAndData;
	typedef QValidateContextInt64AndData		QValidateContextLongAndData;
	typedef QValidateContextIndexAndUInt64		QValidateContextIndexAndULong;
	typedef QValidateContextIndexAndInt64		QValidateContextIndexAndLong;
	typedef QValidateContextIndexUInt64AndData	QValidateContextIndexULongAndData;
	typedef QValidateContextIndexInt64AndData	QValidateContextIndexLongAndData;
#endif

#if Q_LLONG_BITS == 32
	typedef	QValidateUInt32				QValidateULLong;
	typedef QValidateInt32				QValidateLLong;
	typedef QValidateUInt32AndData			QValidateULLongAndData;
	typedef QValidateInt32AndData			QValidateLLongAndData;
	typedef QValidateIndexAndUInt32			QValidateIndexAndULLong;
	typedef QValidateIndexAndInt32			QValidateIndexAndLLong;
	typedef QValidateIndexUInt32AndData		QValidateIndexULLongAndData;
	typedef QValidateIndexInt32AndData		QValidateIndexLLongAndData;
	typedef QValidateContextAndUInt32		QValidateContextAndULLong;
	typedef QValidateContextAndInt32		QValidateContextAndLLong;
	typedef QValidateContextUInt32AndData		QValidateContextULLongAndData;
	typedef QValidateContextInt32AndData		QValidateContextLLongAndData;
	typedef QValidateContextIndexAndUInt32		QValidateContextIndexAndULLong;
	typedef QValidateContextIndexAndInt32		QValidateContextIndexAndLLong;
	typedef QValidateContextIndexUInt32AndData	QValidateContextIndexULLongAndData;
	typedef QValidateContextIndexInt32AndData	QValidateContextIndexLLongAndData;
#elif Q_LLONG_BITS == 64
	typedef	QValidateUInt64				QValidateULLong;
	typedef QValidateInt64				QValidateLLong;
	typedef QValidateUInt64AndData			QValidateULLongAndData;
	typedef QValidateInt64AndData			QValidateLLongAndData;
	typedef QValidateIndexAndUInt64			QValidateIndexAndULLong;
	typedef QValidateIndexAndInt64			QValidateIndexAndLLong;
	typedef QValidateIndexUInt64AndData		QValidateIndexULLongAndData;
	typedef QValidateIndexInt64AndData		QValidateIndexLLongAndData;
	typedef QValidateContextAndUInt64		QValidateContextAndULLong;
	typedef QValidateContextAndInt64		QValidateContextAndLLong;
	typedef QValidateContextUInt64AndData		QValidateContextULLongAndData;
	typedef QValidateContextInt64AndData		QValidateContextLLongAndData;
	typedef QValidateContextIndexAndUInt64		QValidateContextIndexAndULLong;
	typedef QValidateContextIndexAndInt64		QValidateContextIndexAndLLong;
	typedef QValidateContextIndexUInt64AndData	QValidateContextIndexULLongAndData;
	typedef QValidateContextIndexInt64AndData	QValidateContextIndexLLongAndData;
#endif

#if Q_SIZE_BITS == 32
	typedef	QValidateUInt32				QValidateSize;
	typedef QValidateInt32				QValidateSSize;
	typedef QValidateUInt32AndData			QValidateSizeAndData;
	typedef QValidateInt32AndData			QValidateSSizeAndData;
	typedef QValidateIndexAndUInt32			QValidateIndexAndSize;
	typedef QValidateIndexAndInt32			QValidateIndexAndSSize;
	typedef QValidateIndexUInt32AndData		QValidateIndexSizeAndData;
	typedef QValidateIndexInt32AndData		QValidateIndexSSizeAndData;
	typedef QValidateContextAndUInt32		QValidateContextAndSize;
	typedef QValidateContextAndInt32		QValidateContextAndSSize;
	typedef QValidateContextUInt32AndData		QValidateContextSizeAndData;
	typedef QValidateContextInt32AndData		QValidateContextSSizeAndData;
	typedef QValidateContextIndexAndUInt32		QValidateContextIndexAndSize;
	typedef QValidateContextIndexAndInt32		QValidateContextIndexAndSSize;
	typedef QValidateContextIndexUInt32AndData	QValidateContextIndexSizeAndData;
	typedef QValidateContextIndexInt32AndData	QValidateContextIndexSSizeAndData;
#elif Q_SIZE_BITS == 64
	typedef	QValidateUInt64				QValidateSize;
	typedef QValidateInt64				QValidateSSize;
	typedef QValidateUInt64AndData			QValidateSizeAndData;
	typedef QValidateInt64AndData			QValidateSSizeAndData;
	typedef QValidateIndexAndUInt64			QValidateIndexAndSize;
	typedef QValidateIndexAndInt64			QValidateIndexAndSSize;
	typedef QValidateIndexUInt64AndData		QValidateIndexSizeAndData;
	typedef QValidateIndexInt64AndData		QValidateIndexSSizeAndData;
	typedef QValidateContextAndUInt64		QValidateContextAndSize;
	typedef QValidateContextAndInt64		QValidateContextAndSSize;
	typedef QValidateContextUInt64AndData		QValidateContextSizeAndData;
	typedef QValidateContextInt64AndData		QValidateContextSSizeAndData;
	typedef QValidateContextIndexAndUInt64		QValidateContextIndexAndSize;
	typedef QValidateContextIndexAndInt64		QValidateContextIndexAndSSize;
	typedef QValidateContextIndexUInt64AndData	QValidateContextIndexSizeAndData;
	typedef QValidateContextIndexInt64AndData	QValidateContextIndexSSizeAndData;
#endif

#pragma mark - Indirect validate call type

typedef qboolean	(* QCallValidate)	(QFunctionContextAndData* call,
						 QPointerAndIndex*	  data);

#endif /* __Q_types_validation_H__ */
