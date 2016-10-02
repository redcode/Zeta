/* Z Kit C API - types/generic functions.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_|
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_types_generic_functions_H__
#define __Z_types_generic_functions_H__

#include <Z/types/base.h>

/* MARK: - General purpose function types for operations over contexts */

typedef void	(* ZContextDo		  )(void *context);
typedef void	(* ZContextSwitch	  )(void *context, zboolean state);
typedef void	(* ZContextRead		  )(void *context, void *input );
typedef void	(* ZContextWrite	  )(void *context, void *output);
typedef int	(* ZContextCompare	  )(void const *a, void const *b);
typedef int	(* ZContextCompareWithData)(void const *a, void const *b, void *data);
typedef void	(* ZContextSize		  )(void const *context);
typedef ZStatus (* ZContextSetSize	  )(void *context, zsize size);
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

#ifdef Z_DINT64
	typedef zdint64 (* ZContextRead64Bit )(void *context);
	typedef void	(* ZContextWrite64Bit)(void *context, zdint64 value);

	typedef zdint64 (* ZContext16BitAddressRead64Bit )(void *context, zuint16 address);
	typedef zdint64 (* ZContext32BitAddressRead64Bit )(void *context, zuint32 address);
	typedef zuint8	(* ZContext64BitAddressRead8Bit	 )(void *context, zdint64 address);
	typedef zuint16 (* ZContext64BitAddressRead16Bit )(void *context, zdint64 address);
	typedef zuint32 (* ZContext64BitAddressRead32Bit )(void *context, zdint64 address);
	typedef zdint64 (* ZContext64BitAddressRead64Bit )(void *context, zdint64 address);
	typedef void	(* ZContext16BitAddressWrite64Bit)(void *context, zuint16 address, zdint64 value);
	typedef void	(* ZContext32BitAddressWrite64Bit)(void *context, zuint32 address, zdint64 value);
	typedef void	(* ZContext64BitAddressWrite8Bit )(void *context, zdint64 address, zuint8  value);
	typedef void	(* ZContext64BitAddressWrite16Bit)(void *context, zdint64 address, zuint16 value);
	typedef void	(* ZContext64BitAddressWrite32Bit)(void *context, zdint64 address, zuint32 value);
	typedef void	(* ZContext64BitAddressWrite64Bit)(void *context, zdint64 address, zdint64 value);
#endif

/* MARK: - General purpose comparison, handling and validation function types */

typedef void (* ZHandleContextAndIndex	      )(void *context, zsize index			      );
typedef void (* ZHandleContextIndexAndStop    )(void *context, zsize index,		zboolean *stop);
typedef void (* ZHandleContextIndexAndData    )(void *context, zsize index, void *data		      );
typedef void (* ZHandleContextIndexDataAndStop)(void *context, zsize index, void *data, zboolean *stop);
typedef void (* ZHandleIndex		      )(	       zsize index			      );
typedef void (* ZHandleIndexAndStop	      )(	       zsize index,		zboolean *stop);
typedef void (* ZHandleIndexAndData	      )(	       zsize index, void *data		      );
typedef void (* ZHandleIndexDataAndStop	      )(	       zsize index, void *data, zboolean *stop);

typedef zboolean (* ZValidateContextAndIndex	)(void *context, zsize index		);
typedef zboolean (* ZValidateContextIndexAndData)(void *context, zsize index, void *data);
typedef zboolean (* ZValidateIndex		)(		 zsize index		);
typedef zboolean (* ZValidateIndexAndData	)(		 zsize index, void *data);

#define Z_TYPES_GENERIC_FUNCTIONS(Type, pointer_type, value)								\
															\
typedef int (* ZCompare##Type	       )(pointer_type a, pointer_type b);						\
typedef int (* ZCompare##Type##WithData)(pointer_type a, pointer_type b, void *data);					\
															\
typedef void (* ZHandleContextIndexAnd##Type	      )(void *context, zsize index, value			     ); \
typedef void (* ZHandleContextIndex##Type##AndStop    )(void *context, zsize index, value,	       zboolean *stop); \
typedef void (* ZHandleContextIndex##Type##AndData    )(void *context, zsize index, value, void *data		     ); \
typedef void (* ZHandleContextIndex##Type##DataAndStop)(void *context, zsize index, value, void *data, zboolean *stop); \
typedef void (* ZHandleContextAnd##Type		      )(void *context,		    value			     ); \
typedef void (* ZHandleContext##Type##AndStop	      )(void *context,		    value,	       zboolean *stop); \
typedef void (* ZHandleContext##Type##AndData	      )(void *context,		    value, void *data		     ); \
typedef void (* ZHandleContext##Type##DataAndStop     )(void *context,		    value, void *data, zboolean *stop); \
typedef void (* ZHandleIndexAnd##Type		      )(	       zsize index, value			     ); \
typedef void (* ZHandleIndex##Type##AndStop	      )(	       zsize index, value,	       zboolean *stop); \
typedef void (* ZHandleIndex##Type##AndData	      )(	       zsize index, value, void *data		     ); \
typedef void (* ZHandleIndex##Type##DataAndStop	      )(	       zsize index, value, void *data, zboolean *stop); \
typedef void (* ZHandle##Type			      )(			    value			     ); \
typedef void (* ZHandle##Type##AndStop		      )(			    value,	       zboolean *stop); \
typedef void (* ZHandle##Type##AndData		      )(			    value, void *data		     ); \
typedef void (* ZHandle##Type##DataAndStop	      )(			    value, void *data, zboolean *stop); \
															\
typedef zboolean (* ZValidateContextIndexAnd##Type	)(void *context, zsize index, value	       );		\
typedef zboolean (* ZValidateContextIndex##Type##AndData)(void *context, zsize index, value, void *data);		\
typedef zboolean (* ZValidateContextAnd##Type		)(void *context,	      value	       );		\
typedef zboolean (* ZValidateContext##Type##AndData	)(void *context,	      value, void *data);		\
typedef zboolean (* ZValidateIndexAnd##Type		)(		 zsize index, value	       );		\
typedef zboolean (* ZValidateIndex##Type##AndData	)(		 zsize index, value, void *data);		\
typedef zboolean (* ZValidate##Type			)(			      value	       );		\
typedef zboolean (* ZValidate##Type##AndData		)(			      value, void *data);

#define ZCompareType(	     TYPE) Z_INSERT_##TYPE##_FixedType(ZCompare,	 )
#define ZCompareTypeWithData(TYPE) Z_INSERT_##TYPE##_FixedType(ZCompare, WithData)

#define ZHandleContextIndexAndType(	   TYPE) Z_INSERT_##TYPE##_FixedType(ZHandleContextIndexAnd,		)
#define ZHandleContextIndexTypeAndStop(	   TYPE) Z_INSERT_##TYPE##_FixedType(ZHandleContextIndex,    AndStop	)
#define ZHandleContextIndexTypeAndData(	   TYPE) Z_INSERT_##TYPE##_FixedType(ZHandleContextIndex,    AndData	)
#define ZHandleContextIndexTypeDataAndStop(TYPE) Z_INSERT_##TYPE##_FixedType(ZHandleContextIndex,    DataAndStop)
#define ZHandleContextAndType(		   TYPE) Z_INSERT_##TYPE##_FixedType(ZHandleContextAnd,			)
#define ZHandleContextTypeAndStop(	   TYPE) Z_INSERT_##TYPE##_FixedType(ZHandleContext,	     AndStop	)
#define ZHandleContextTypeAndData(	   TYPE) Z_INSERT_##TYPE##_FixedType(ZHandleContext,	     AndData	)
#define ZHandleContextTypeDataAndStop(	   TYPE) Z_INSERT_##TYPE##_FixedType(ZHandleContext,	     DataAndStop)
#define ZHandleIndexAndType(		   TYPE) Z_INSERT_##TYPE##_FixedType(ZHandleIndexAnd,			)
#define ZHandleIndexTypeAndStop(	   TYPE) Z_INSERT_##TYPE##_FixedType(ZHandleIndex,	     AndStop	)
#define ZHandleIndexTypeAndData(	   TYPE) Z_INSERT_##TYPE##_FixedType(ZHandleIndex,	     AndData	)
#define ZHandleIndexTypeDataAndStop(	   TYPE) Z_INSERT_##TYPE##_FixedType(ZHandleIndex,	     DataAndStop)
#define ZHandleType(			   TYPE) Z_INSERT_##TYPE##_FixedType(ZHandle,				)
#define ZHandleTypeAndStop(		   TYPE) Z_INSERT_##TYPE##_FixedType(ZHandle,		     AndStop	)
#define ZHandleTypeAndData(		   TYPE) Z_INSERT_##TYPE##_FixedType(ZHandle,		     AndData	)
#define ZHandleTypeDataAndStop(		   TYPE) Z_INSERT_##TYPE##_FixedType(ZHandle,		     DataAndStop)

#define ZValidateContextIndexAndType(	 TYPE) Z_INSERT_##TYPE##_FixedType(ZValidateContextIndexAnd,	    )
#define ZValidateContextIndexTypeAndData(TYPE) Z_INSERT_##TYPE##_FixedType(ZValidateContextIndex,    AndData)
#define ZValidateContextAndType(	 TYPE) Z_INSERT_##TYPE##_FixedType(ZValidateContextAnd,		    )
#define ZValidateContextTypeAndData(	 TYPE) Z_INSERT_##TYPE##_FixedType(ZValidateContext,	     AndData)
#define ZValidateIndexAndType(		 TYPE) Z_INSERT_##TYPE##_FixedType(ZValidateIndexAnd,		    )
#define ZValidateIndexTypeAndData(	 TYPE) Z_INSERT_##TYPE##_FixedType(ZValidateIndex,	     AndData)
#define ZValidateType(			 TYPE) Z_INSERT_##TYPE##_FixedType(ZValidate,			    )
#define ZValidateTypeAndData(		 TYPE) Z_INSERT_##TYPE##_FixedType(ZValidate,		     AndData)

Z_TYPES_GENERIC_FUNCTIONS(UInt8,  zuint8*,  zuint8  value)
Z_TYPES_GENERIC_FUNCTIONS(UInt16, zuint16*, zuint16 value)
Z_TYPES_GENERIC_FUNCTIONS(UInt32, zuint32*, zuint32 value)

#ifdef Z_UINT64
	Z_TYPES_GENERIC_FUNCTIONS(UInt64, zuint64*, zuint64 value)
#endif

#ifdef Z_UINT128
	Z_TYPES_GENERIC_FUNCTIONS(UInt128, zuint128*, zuint128 value)
#endif

Z_TYPES_GENERIC_FUNCTIONS(Int8,  zint8*,  zint8  value)
Z_TYPES_GENERIC_FUNCTIONS(Int16, zint16*, zint16 value)
Z_TYPES_GENERIC_FUNCTIONS(Int32, zint32*, zint32 value)

#ifdef Z_INT64
	Z_TYPES_GENERIC_FUNCTIONS(Int64, zint64*, zint64 value)
#endif

#ifdef Z_INT128
	Z_TYPES_GENERIC_FUNCTIONS(Int128, zint128*, zint128 value)
#endif

#ifdef Z_FLOAT16
	Z_TYPES_GENERIC_FUNCTIONS(Float16, zfloat16*, zfloat16 value)
#endif

#ifdef Z_FLOAT24
	Z_TYPES_GENERIC_FUNCTIONS(Float24, zfloat24*, zfloat24 value)
#endif

#ifdef Z_FLOAT32
	Z_TYPES_GENERIC_FUNCTIONS(Float32, zfloat32*, zfloat32 value)
#endif

#ifdef Z_FLOAT48
	Z_TYPES_GENERIC_FUNCTIONS(Float48, zfloat48*, zfloat48 value)
#endif

#ifdef Z_FLOAT64
	Z_TYPES_GENERIC_FUNCTIONS(Float64, zfloat64*, zfloat64 value)
#endif

#ifdef Z_FLOAT72
	Z_TYPES_GENERIC_FUNCTIONS(Float72, zfloat72*, zfloat72 value)
#endif

#ifdef Z_FLOAT80
	Z_TYPES_GENERIC_FUNCTIONS(Float80, zfloat80*, zfloat80 value)
#endif

#ifdef Z_FLOAT96
	Z_TYPES_GENERIC_FUNCTIONS(Float96, zfloat96*, zfloat96 value)
#endif

#ifdef Z_FLOAT128
	Z_TYPES_GENERIC_FUNCTIONS(Float128, zfloat128*, zfloat128 value)
#endif

Z_TYPES_GENERIC_FUNCTIONS(Pointer, ZPointer, void *pointer)

typedef int (* ZCompare8Bit	     )(Z8Bit   a, Z8Bit   b	       );
typedef int (* ZCompare8BitWithData  )(Z8Bit   a, Z8Bit   b, void *data);
typedef int (* ZCompare16Bit	     )(Z16Bit  a, Z16Bit  b	       );
typedef int (* ZCompare16BitWithData )(Z16Bit  a, Z16Bit  b, void *data);
typedef int (* ZCompare32Bit	     )(Z32Bit  a, Z32Bit  b	       );
typedef int (* ZCompare32BitWithData )(Z32Bit  a, Z32Bit  b, void *data);
typedef int (* ZCompare64Bit	     )(Z64Bit  a, Z64Bit  b	       );
typedef int (* ZCompare64BitWithData )(Z64Bit  a, Z64Bit  b, void *data);
typedef int (* ZCompare128Bit	     )(Z128Bit a, Z128Bit b	       );
typedef int (* ZCompare128BitWithData)(Z128Bit a, Z128Bit b, void *data);

#endif /* __Z_types_generic_functions_H__ */
