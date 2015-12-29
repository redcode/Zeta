/* Z Kit C API - types/validation.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_types_validation_H__
#define __Z_types_validation_H__

#include <Z/types/base.h>

typedef zboolean (* ZValidateIndex		)(		 zsize index		);
typedef zboolean (* ZValidateIndexAndData	)(		 zsize index, void *data);
typedef zboolean (* ZValidateContextAndIndex	)(void *context, zsize index		);
typedef zboolean (* ZValidateContextIndexAndData)(void *context, zsize index, void *data);

#define Z_TEMPLATE_VALIDATION_TYPES(Type, value)							  \
typedef zboolean (* ZValidate##Type			)(			      value	       ); \
typedef zboolean (* ZValidate##Type##AndData		)(			      value, void *data); \
typedef zboolean (* ZValidateIndexAnd##Type		)(		 zsize index, value	       ); \
typedef zboolean (* ZValidateIndex##Type##AndData	)(		 zsize index, value, void *data); \
typedef zboolean (* ZValidateContextAnd##Type		)(void *context,	      value	       ); \
typedef zboolean (* ZValidateContext##Type##AndData	)(void *context,	      value, void *data); \
typedef zboolean (* ZValidateContextIndexAnd##Type	)(void *context, zsize index, value	       ); \
typedef zboolean (* ZValidateContextIndex##Type##AndData)(void *context, zsize index, value, void *data);

#define ZValidateType(			 TYPE) Z_INSERT_##TYPE##_FixedType(ZValidate,			    )
#define ZValidateTypeAndData(		 TYPE) Z_INSERT_##TYPE##_FixedType(ZValidate,		     AndData)
#define ZValidateIndexAndType(		 TYPE) Z_INSERT_##TYPE##_FixedType(ZValidateIndexAnd,		    )
#define ZValidateIndexTypeAndData(	 TYPE) Z_INSERT_##TYPE##_FixedType(ZValidateIndex,	     AndData)
#define ZValidateContextAndType(	 TYPE) Z_INSERT_##TYPE##_FixedType(ZValidateContextAnd,		    )
#define ZValidateContextTypeAndData(	 TYPE) Z_INSERT_##TYPE##_FixedType(ZValidateContext,	     AndData)
#define ZValidateContextIndexAndType(	 TYPE) Z_INSERT_##TYPE##_FixedType(ZValidateContextIndexAnd,	    )
#define ZValidateContextIndexTypeAndData(TYPE) Z_INSERT_##TYPE##_FixedType(ZValidateContextIndex,    AndData)

Z_TEMPLATE_VALIDATION_TYPES(UInt8,  zuint8  value)
Z_TEMPLATE_VALIDATION_TYPES(UInt16, zuint16 value)
Z_TEMPLATE_VALIDATION_TYPES(UInt32, zuint32 value)

#if Z_IS_AVAILABLE(UINT64)
	Z_TEMPLATE_VALIDATION_TYPES(UInt64, zuint64 value)
#endif

#if Z_IS_AVAILABLE(UINT128)
	Z_TEMPLATE_VALIDATION_TYPES(UInt128, zuint128 value)
#endif

Z_TEMPLATE_VALIDATION_TYPES(Int8,  zint8  value)
Z_TEMPLATE_VALIDATION_TYPES(Int16, zint16 value)
Z_TEMPLATE_VALIDATION_TYPES(Int32, zint32 value)

#if Z_IS_AVAILABLE(INT64)
	Z_TEMPLATE_VALIDATION_TYPES(Int64, zint64 value)
#endif

#if Z_IS_AVAILABLE(INT128)
	Z_TEMPLATE_VALIDATION_TYPES(Int128, zint128 value)
#endif

#if Z_IS_AVAILABLE(FLOAT16)
	Z_TEMPLATE_VALIDATION_TYPES(Float16, zfloat16 value)
#endif

#if Z_IS_AVAILABLE(FLOAT24)
	Z_TEMPLATE_VALIDATION_TYPES(Float24, zfloat24 value)
#endif

#if Z_IS_AVAILABLE(FLOAT32)
	Z_TEMPLATE_VALIDATION_TYPES(Float32, zfloat32 value)
#endif

#if Z_IS_AVAILABLE(FLOAT48)
	Z_TEMPLATE_VALIDATION_TYPES(Float48, zfloat48 value)
#endif

#if Z_IS_AVAILABLE(FLOAT64)
	Z_TEMPLATE_VALIDATION_TYPES(Float64, zfloat64 value)
#endif

#if Z_IS_AVAILABLE(FLOAT72)
	Z_TEMPLATE_VALIDATION_TYPES(Float72, zfloat72 value)
#endif

#if Z_IS_AVAILABLE(FLOAT80)
	Z_TEMPLATE_VALIDATION_TYPES(Float80, zfloat80 value)
#endif

#if Z_IS_AVAILABLE(FLOAT96)
	Z_TEMPLATE_VALIDATION_TYPES(Float96, zfloat96 value)
#endif

#if Z_IS_AVAILABLE(FLOAT128)
	Z_TEMPLATE_VALIDATION_TYPES(Float128, zfloat128 value)
#endif

Z_TEMPLATE_VALIDATION_TYPES(Pointer, void *pointer)

#endif /* __Z_types_validation_H__ */
