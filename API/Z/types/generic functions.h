/* Z Kit - types/generic functions.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_types_generic_functions_H_
#define _Z_types_generic_functions_H_

#include <Z/types/base.h>

/* MARK: - General purpose function types for operations over contexts */

typedef void	(* ZContextDo		  )(void *context);
typedef void	(* ZContextSwitch	  )(void *context, zboolean state);
typedef void	(* ZContextRead		  )(void *context, void *input );
typedef void	(* ZContextWrite	  )(void *context, void *output);
typedef zsint	(* ZContextCompare	  )(void const *a, void const *b);
typedef zsint	(* ZContextCompareWithData)(void const *a, void const *b, void *data);
typedef void	(* ZContextSize		  )(void const *context);
typedef ZStatus (* ZContextSetSize	  )(void *context, zusize size);
typedef void	(* ZContextCopy		  )(void const *context, void* output);

typedef zuint8	(* ZContextRead8Bit  )(void *context);
typedef zuint16 (* ZContextRead16Bit )(void *context);
typedef zuint32 (* ZContextRead32Bit )(void *context);
typedef void	(* ZContextWrite8Bit )(void *context, zuint8  value);
typedef void	(* ZContextWrite16Bit)(void *context, zuint16 value);
typedef void	(* ZContextWrite32Bit)(void *context, zuint32 value);

typedef zuint8	(* ZContext16BitAddressRead8Bit	 )(void *context, zuint16 address);
typedef zuint16 (* ZContext16BitAddressRead16Bit )(void *context, zuint16 address);
typedef zuint32 (* ZContext16BitAddressRead32Bit )(void *context, zuint16 address);
typedef zuint8	(* ZContext32BitAddressRead8Bit	 )(void *context, zuint32 address);
typedef zuint16 (* ZContext32BitAddressRead16Bit )(void *context, zuint32 address);
typedef zuint32 (* ZContext32BitAddressRead32Bit )(void *context, zuint32 address);
typedef void	(* ZContext16BitAddressWrite8Bit )(void *context, zuint16 address, zuint8  value);
typedef void	(* ZContext16BitAddressWrite16Bit)(void *context, zuint16 address, zuint16 value);
typedef void	(* ZContext16BitAddressWrite32Bit)(void *context, zuint16 address, zuint32 value);
typedef void	(* ZContext32BitAddressWrite8Bit )(void *context, zuint32 address, zuint8  value);
typedef void	(* ZContext32BitAddressWrite16Bit)(void *context, zuint32 address, zuint16 value);
typedef void	(* ZContext32BitAddressWrite32Bit)(void *context, zuint32 address, zuint32 value);

#ifdef Z_UINT64
	typedef zuint64 (* ZContextRead64Bit )(void *context);
	typedef void	(* ZContextWrite64Bit)(void *context, zuint64 value);

	typedef zuint64 (* ZContext16BitAddressRead64Bit )(void *context, zuint16 address);
	typedef zuint64 (* ZContext32BitAddressRead64Bit )(void *context, zuint32 address);
	typedef zuint8	(* ZContext64BitAddressRead8Bit	 )(void *context, zuint64 address);
	typedef zuint16 (* ZContext64BitAddressRead16Bit )(void *context, zuint64 address);
	typedef zuint32 (* ZContext64BitAddressRead32Bit )(void *context, zuint64 address);
	typedef zuint64 (* ZContext64BitAddressRead64Bit )(void *context, zuint64 address);
	typedef void	(* ZContext16BitAddressWrite64Bit)(void *context, zuint16 address, zuint64 value);
	typedef void	(* ZContext32BitAddressWrite64Bit)(void *context, zuint32 address, zuint64 value);
	typedef void	(* ZContext64BitAddressWrite8Bit )(void *context, zuint64 address, zuint8  value);
	typedef void	(* ZContext64BitAddressWrite16Bit)(void *context, zuint64 address, zuint16 value);
	typedef void	(* ZContext64BitAddressWrite32Bit)(void *context, zuint64 address, zuint32 value);
	typedef void	(* ZContext64BitAddressWrite64Bit)(void *context, zuint64 address, zuint64 value);
#endif

/* MARK: - General purpose comparison, handling and validation function types */

typedef void (* ZHandleContextAndIndex	      )(void *context, zusize index			       );
typedef void (* ZHandleContextIndexAndStop    )(void *context, zusize index,		 zboolean *stop);
typedef void (* ZHandleContextIndexAndData    )(void *context, zusize index, void *data		       );
typedef void (* ZHandleContextIndexDataAndStop)(void *context, zusize index, void *data, zboolean *stop);
typedef void (* ZHandleIndex		      )(	       zusize index			       );
typedef void (* ZHandleIndexAndStop	      )(	       zusize index,		 zboolean *stop);
typedef void (* ZHandleIndexAndData	      )(	       zusize index, void *data		       );
typedef void (* ZHandleIndexDataAndStop	      )(	       zusize index, void *data, zboolean *stop);

typedef zboolean (* ZValidateContextAndIndex	)(void *context, zusize index		 );
typedef zboolean (* ZValidateContextIndexAndData)(void *context, zusize index, void *data);
typedef zboolean (* ZValidateIndex		)(		 zusize index		 );
typedef zboolean (* ZValidateIndexAndData	)(		 zusize index, void *data);

#define Z_TYPES(Type, pointer_type, value)										 \
															 \
typedef zsint (* ZCompare##Type		 )(pointer_type a, pointer_type b);						 \
typedef zsint (* ZCompare##Type##WithData)(pointer_type a, pointer_type b, void *data);					 \
															 \
typedef void (* ZHandleContextIndexAnd##Type	      )(void *context, zusize index, value			      ); \
typedef void (* ZHandleContextIndex##Type##AndStop    )(void *context, zusize index, value,		zboolean *stop); \
typedef void (* ZHandleContextIndex##Type##AndData    )(void *context, zusize index, value, void *data		      ); \
typedef void (* ZHandleContextIndex##Type##DataAndStop)(void *context, zusize index, value, void *data, zboolean *stop); \
typedef void (* ZHandleContextAnd##Type		      )(void *context,		     value			      ); \
typedef void (* ZHandleContext##Type##AndStop	      )(void *context,		     value,		zboolean *stop); \
typedef void (* ZHandleContext##Type##AndData	      )(void *context,		     value, void *data		      ); \
typedef void (* ZHandleContext##Type##DataAndStop     )(void *context,		     value, void *data, zboolean *stop); \
typedef void (* ZHandleIndexAnd##Type		      )(	       zusize index, value			      ); \
typedef void (* ZHandleIndex##Type##AndStop	      )(	       zusize index, value,		zboolean *stop); \
typedef void (* ZHandleIndex##Type##AndData	      )(	       zusize index, value, void *data		      ); \
typedef void (* ZHandleIndex##Type##DataAndStop	      )(	       zusize index, value, void *data, zboolean *stop); \
typedef void (* ZHandle##Type			      )(			     value			      ); \
typedef void (* ZHandle##Type##AndStop		      )(			     value,		zboolean *stop); \
typedef void (* ZHandle##Type##AndData		      )(			     value, void *data		      ); \
typedef void (* ZHandle##Type##DataAndStop	      )(			     value, void *data, zboolean *stop); \
															 \
typedef zboolean (* ZValidateContextIndexAnd##Type	)(void *context, zusize index, value		);		 \
typedef zboolean (* ZValidateContextIndex##Type##AndData)(void *context, zusize index, value, void *data);		 \
typedef zboolean (* ZValidateContextAnd##Type		)(void *context,	       value		);		 \
typedef zboolean (* ZValidateContext##Type##AndData	)(void *context,	       value, void *data);		 \
typedef zboolean (* ZValidateIndexAnd##Type		)(		 zusize index, value		);		 \
typedef zboolean (* ZValidateIndex##Type##AndData	)(		 zusize index, value, void *data);		 \
typedef zboolean (* ZValidate##Type			)(			       value		);		 \
typedef zboolean (* ZValidate##Type##AndData		)(			       value, void *data);

#define ZCompareType(	     TYPE) Z_APPEND_##TYPE##_FixedType(ZCompare)
#define ZCompareTypeWithData(TYPE) Z_INSERT_##TYPE##_FixedType(ZCompare, WithData)

#define ZHandleContextIndexAndType(	   TYPE) Z_APPEND_##TYPE##_FixedType(ZHandleContextIndexAnd		)
#define ZHandleContextIndexTypeAndStop(	   TYPE) Z_INSERT_##TYPE##_FixedType(ZHandleContextIndex,    AndStop	)
#define ZHandleContextIndexTypeAndData(	   TYPE) Z_INSERT_##TYPE##_FixedType(ZHandleContextIndex,    AndData	)
#define ZHandleContextIndexTypeDataAndStop(TYPE) Z_INSERT_##TYPE##_FixedType(ZHandleContextIndex,    DataAndStop)
#define ZHandleContextAndType(		   TYPE) Z_APPEND_##TYPE##_FixedType(ZHandleContextAnd			)
#define ZHandleContextTypeAndStop(	   TYPE) Z_INSERT_##TYPE##_FixedType(ZHandleContext,	     AndStop	)
#define ZHandleContextTypeAndData(	   TYPE) Z_INSERT_##TYPE##_FixedType(ZHandleContext,	     AndData	)
#define ZHandleContextTypeDataAndStop(	   TYPE) Z_INSERT_##TYPE##_FixedType(ZHandleContext,	     DataAndStop)
#define ZHandleIndexAndType(		   TYPE) Z_APPEND_##TYPE##_FixedType(ZHandleIndexAnd			)
#define ZHandleIndexTypeAndStop(	   TYPE) Z_INSERT_##TYPE##_FixedType(ZHandleIndex,	     AndStop	)
#define ZHandleIndexTypeAndData(	   TYPE) Z_INSERT_##TYPE##_FixedType(ZHandleIndex,	     AndData	)
#define ZHandleIndexTypeDataAndStop(	   TYPE) Z_INSERT_##TYPE##_FixedType(ZHandleIndex,	     DataAndStop)
#define ZHandleType(			   TYPE) Z_APPEND_##TYPE##_FixedType(ZHandle				)
#define ZHandleTypeAndStop(		   TYPE) Z_INSERT_##TYPE##_FixedType(ZHandle,		     AndStop	)
#define ZHandleTypeAndData(		   TYPE) Z_INSERT_##TYPE##_FixedType(ZHandle,		     AndData	)
#define ZHandleTypeDataAndStop(		   TYPE) Z_INSERT_##TYPE##_FixedType(ZHandle,		     DataAndStop)

#define ZValidateContextIndexAndType(	 TYPE) Z_APPEND_##TYPE##_FixedType(ZValidateContextIndexAnd	    )
#define ZValidateContextIndexTypeAndData(TYPE) Z_INSERT_##TYPE##_FixedType(ZValidateContextIndex,    AndData)
#define ZValidateContextAndType(	 TYPE) Z_APPEND_##TYPE##_FixedType(ZValidateContextAnd		    )
#define ZValidateContextTypeAndData(	 TYPE) Z_INSERT_##TYPE##_FixedType(ZValidateContext,	     AndData)
#define ZValidateIndexAndType(		 TYPE) Z_APPEND_##TYPE##_FixedType(ZValidateIndexAnd		    )
#define ZValidateIndexTypeAndData(	 TYPE) Z_INSERT_##TYPE##_FixedType(ZValidateIndex,	     AndData)
#define ZValidateType(			 TYPE) Z_APPEND_##TYPE##_FixedType(ZValidate			    )
#define ZValidateTypeAndData(		 TYPE) Z_INSERT_##TYPE##_FixedType(ZValidate,		     AndData)

Z_TYPES(UInt8,	zuint8*,  zuint8  value)
Z_TYPES(SInt8,	zsint8*,  zsint8  value)
Z_TYPES(UInt16, zuint16*, zuint16 value)
Z_TYPES(SInt16, zsint16*, zsint16 value)
Z_TYPES(UInt32, zuint32*, zuint32 value)
Z_TYPES(SInt32, zsint32*, zsint32 value)

#ifdef Z_UINT64
	Z_TYPES(UInt64, zuint64*, zuint64 value)
#endif

#ifdef Z_SINT64
	Z_TYPES(SInt64, zsint64*, zsint64 value)
#endif

#ifdef Z_UINT128
	Z_TYPES(UInt128, zuint128*, zuint128 value)
#endif

#ifdef Z_SINT128
	Z_TYPES(SInt128, zsint128*, zsint128 value)
#endif

#ifdef Z_FLOAT16
	Z_TYPES(Float16, zfloat16*, zfloat16 value)
#endif

#ifdef Z_FLOAT32
	Z_TYPES(Float32, zfloat32*, zfloat32 value)
#endif

#ifdef Z_FLOAT64
	Z_TYPES(Float64, zfloat64*, zfloat64 value)
#endif

#ifdef Z_FLOAT128
	Z_TYPES(Float128, zfloat128*, zfloat128 value)
#endif

#ifdef Z_FLOAT80_X87
	Z_TYPES(Float80_x87, zfloat80_x87*, zfloat80_x87 value)
#endif

#ifdef Z_FLOAT96_X87
	Z_TYPES(Float96_x87, zfloat96_x87*, zfloat96_x87 value)
#endif

#ifdef Z_FLOAT128_X87
	Z_TYPES(Float128_x87, zfloat128_x87*, zfloat128_x87 value)
#endif

Z_TYPES(Pointer, ZPointer, void *pointer)

#undef Z_TYPES

typedef zsint (* ZCompare8Bit  )(Z8Bit	 a, Z8Bit   b);
typedef zsint (* ZCompare16Bit )(Z16Bit	 a, Z16Bit  b);
typedef zsint (* ZCompare32Bit )(Z32Bit	 a, Z32Bit  b);
typedef zsint (* ZCompare64Bit )(Z64Bit	 a, Z64Bit  b);
typedef zsint (* ZCompare128Bit)(Z128Bit a, Z128Bit b);

typedef zsint (* ZCompare8BitWithData  )(Z8Bit	 a, Z8Bit   b, void *data);
typedef zsint (* ZCompare16BitWithData )(Z16Bit	 a, Z16Bit  b, void *data);
typedef zsint (* ZCompare32BitWithData )(Z32Bit	 a, Z32Bit  b, void *data);
typedef zsint (* ZCompare64BitWithData )(Z64Bit	 a, Z64Bit  b, void *data);
typedef zsint (* ZCompare128BitWithData)(Z128Bit a, Z128Bit b, void *data);

#endif /* _Z_types_generic_functions_H_ */
