/* Z Kit C API - types/handling.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_types_handling_H__
#define __Z_types_handling_H__

#include <Z/types/base.h>

typedef void (* ZHandleIndex		      )(	       zsize index			      );
typedef void (* ZHandleIndexAndData	      )(	       zsize index, void *data		      );
typedef void (* ZHandleContextAndIndex	      )(void *context, zsize index			      );
typedef void (* ZHandleContextIndexAndData    )(void *context, zsize index, void *data		      );
typedef void (* ZHandleIndexAndStop	      )(	       zsize index,		zboolean *stop);
typedef void (* ZHandleIndexDataAndStop	      )(	       zsize index, void *data, zboolean *stop);
typedef void (* ZHandleContextIndexAndStop    )(void *context, zsize index,		zboolean *stop);
typedef void (* ZHandleContextIndexDataAndStop)(void *context, zsize index, void *data, zboolean *stop);

#define Z_TEMPLATE_HANDLING_TYPES(Type, value)									        \
typedef void (* ZHandle##Type			      )(			    value			     ); \
typedef void (* ZHandle##Type##AndData		      )(			    value, void *data		     ); \
typedef void (* ZHandleIndexAnd##Type		      )(	       zsize index, value			     ); \
typedef void (* ZHandleIndex##Type##AndData	      )(	       zsize index, value, void *data		     ); \
typedef void (* ZHandleContextAnd##Type		      )(void *context,		    value			     ); \
typedef void (* ZHandleContext##Type##AndData	      )(void *context,		    value, void *data		     ); \
typedef void (* ZHandleContextIndexAnd##Type	      )(void *context, zsize index, value			     ); \
typedef void (* ZHandleContextIndex##Type##AndData    )(void *context, zsize index, value, void *data		     ); \
typedef void (* ZHandle##Type##AndStop		      )(			    value,	       zboolean *stop); \
typedef void (* ZHandle##Type##DataAndStop	      )(			    value, void *data, zboolean *stop); \
typedef void (* ZHandleIndex##Type##AndStop	      )(	       zsize index, value,	       zboolean *stop); \
typedef void (* ZHandleIndex##Type##DataAndStop	      )(	       zsize index, value, void *data, zboolean *stop); \
typedef void (* ZHandleContext##Type##AndStop	      )(void *context,		    value,	       zboolean *stop); \
typedef void (* ZHandleContext##Type##DataAndStop     )(void *context,		    value, void *data, zboolean *stop); \
typedef void (* ZHandleContextIndex##Type##AndStop    )(void *context, zsize index, value,	       zboolean *stop); \
typedef void (* ZHandleContextIndex##Type##DataAndStop)(void *context, zsize index, value, void *data, zboolean *stop);

#define ZHandleType(			   TYPE) Z_INSERT_##TYPE##_FixedType(ZHandle,				)
#define ZHandleTypeAndData(		   TYPE) Z_INSERT_##TYPE##_FixedType(ZHandle,		     AndData	)
#define ZHandleIndexAndType(		   TYPE) Z_INSERT_##TYPE##_FixedType(ZHandleIndexAnd,			)
#define ZHandleIndexTypeAndData(	   TYPE) Z_INSERT_##TYPE##_FixedType(ZHandleIndex,	     AndData	)
#define ZHandleContextAndType(		   TYPE) Z_INSERT_##TYPE##_FixedType(ZHandleContextAnd,			)
#define ZHandleContextTypeAndData(	   TYPE) Z_INSERT_##TYPE##_FixedType(ZHandleContext,	     AndData	)
#define ZHandleContextIndexAndType(	   TYPE) Z_INSERT_##TYPE##_FixedType(ZHandleContextIndexAnd,		)
#define ZHandleContextIndexTypeAndData(	   TYPE) Z_INSERT_##TYPE##_FixedType(ZHandleContextIndex,    AndData	)
#define ZHandleTypeAndStop(		   TYPE) Z_INSERT_##TYPE##_FixedType(ZHandle,		     AndStop    )
#define ZHandleTypeDataAndStop(		   TYPE) Z_INSERT_##TYPE##_FixedType(ZHandle,		     DataAndStop)
#define ZHandleIndexTypeAndStop(	   TYPE) Z_INSERT_##TYPE##_FixedType(ZHandleIndex,	     AndStop    )
#define ZHandleIndexTypeDataAndStop(	   TYPE) Z_INSERT_##TYPE##_FixedType(ZHandleIndex,	     DataAndStop)
#define ZHandleContextTypeAndStop(	   TYPE) Z_INSERT_##TYPE##_FixedType(ZHandleContext,	     AndStop    )
#define ZHandleContextTypeDataAndStop(	   TYPE) Z_INSERT_##TYPE##_FixedType(ZHandleContext,	     DataAndStop)
#define ZHandleContextIndexTypeAndStop(    TYPE) Z_INSERT_##TYPE##_FixedType(ZHandleContextIndex,    AndStop    )
#define ZHandleContextIndexTypeDataAndStop(TYPE) Z_INSERT_##TYPE##_FixedType(ZHandleContextIndex,    DataAndStop)

Z_TEMPLATE_HANDLING_TYPES(UInt8,  zuint8  value)
Z_TEMPLATE_HANDLING_TYPES(UInt16, zuint16 value)
Z_TEMPLATE_HANDLING_TYPES(UInt32, zuint32 value)

#if Z_IS_AVAILABLE(UINT64)
	Z_TEMPLATE_HANDLING_TYPES(UInt64, zuint64 value)
#endif

#if Z_IS_AVAILABLE(UINT128)
	Z_TEMPLATE_HANDLING_TYPES(UInt128, zuint128 value)
#endif

Z_TEMPLATE_HANDLING_TYPES(Int8,  zint8  value)
Z_TEMPLATE_HANDLING_TYPES(Int16, zint16 value)
Z_TEMPLATE_HANDLING_TYPES(Int32, zint32 value)

#if Z_IS_AVAILABLE(INT64)
	Z_TEMPLATE_HANDLING_TYPES(Int64, zint64 value)
#endif

#if Z_IS_AVAILABLE(INT128)
	Z_TEMPLATE_HANDLING_TYPES(Int128, zint128 value)
#endif

#if Z_IS_AVAILABLE(FLOAT16)
	Z_TEMPLATE_HANDLING_TYPES(Float16, zfloat16 value)
#endif

#if Z_IS_AVAILABLE(FLOAT24)
	Z_TEMPLATE_HANDLING_TYPES(Float24, zfloat24 value)
#endif

#if Z_IS_AVAILABLE(FLOAT32)
	Z_TEMPLATE_HANDLING_TYPES(Float32, zfloat32 value)
#endif

#if Z_IS_AVAILABLE(FLOAT48)
	Z_TEMPLATE_HANDLING_TYPES(Float48, zfloat48 value)
#endif

#if Z_IS_AVAILABLE(FLOAT64)
	Z_TEMPLATE_HANDLING_TYPES(Float64, zfloat64 value)
#endif

#if Z_IS_AVAILABLE(FLOAT72)
	Z_TEMPLATE_HANDLING_TYPES(Float72, zfloat72 value)
#endif

#if Z_IS_AVAILABLE(FLOAT80)
	Z_TEMPLATE_HANDLING_TYPES(Float80, zfloat80 value)
#endif

#if Z_IS_AVAILABLE(FLOAT96)
	Z_TEMPLATE_HANDLING_TYPES(Float96, zfloat96 value)
#endif

#if Z_IS_AVAILABLE(FLOAT128)
	Z_TEMPLATE_HANDLING_TYPES(Float128, zfloat128 value)
#endif

Z_TEMPLATE_HANDLING_TYPES(Pointer, void *pointer)

#endif /* __Z_types_handling_H__ */
