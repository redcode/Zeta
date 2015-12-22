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

typedef zboolean (* ZValidateIndex		) (		  zsize index		 );
typedef zboolean (* ZValidateIndexAndData	) (		  zsize index, void *data);
typedef zboolean (* ZValidateContextAndIndex	) (void *context, zsize index		 );
typedef zboolean (* ZValidateContextIndexAndData) (void *context, zsize index, void *data);

typedef zboolean (* ZValidateUInt8		     ) (			    zuint8 value	    );
typedef zboolean (* ZValidateUInt8AndData	     ) (			    zuint8 value, void *data);
typedef zboolean (* ZValidateIndexAndUInt8	     ) (	       zsize index, zuint8 value	    );
typedef zboolean (* ZValidateIndexUInt8AndData	     ) (	       zsize index, zuint8 value, void *data);
typedef zboolean (* ZValidateContextAndUInt8	     ) (void *context,		    zuint8 value	    );
typedef zboolean (* ZValidateContextUInt8AndData     ) (void *context,		    zuint8 value, void *data);
typedef zboolean (* ZValidateContextIndexAndUInt8    ) (void *context, zsize index, zuint8 value	    );
typedef zboolean (* ZValidateContextIndexUInt8AndData) (void *context, zsize index, zuint8 value, void *data);

typedef zboolean (* ZValidateUInt16		      ) (			     zuint16 value	      );
typedef zboolean (* ZValidateUInt16AndData	      ) (			     zuint16 value, void *data);
typedef zboolean (* ZValidateIndexAndUInt16	      ) (		zsize index, zuint16 value	      );
typedef zboolean (* ZValidateIndexUInt16AndData	      ) (		zsize index, zuint16 value, void *data);
typedef zboolean (* ZValidateContextAndUInt16	      ) (void *context,		     zuint16 value	      );
typedef zboolean (* ZValidateContextUInt16AndData     ) (void *context,		     zuint16 value, void *data);
typedef zboolean (* ZValidateContextIndexAndUInt16    ) (void *context, zsize index, zuint16 value	      );
typedef zboolean (* ZValidateContextIndexUInt16AndData) (void *context, zsize index, zuint16 value, void *data);

typedef zboolean (* ZValidateUInt32		      ) (			     zuint32 value	      );
typedef zboolean (* ZValidateUInt32AndData	      ) (			     zuint32 value, void *data);
typedef zboolean (* ZValidateIndexAndUInt32	      ) (		zsize index, zuint32 value	      );
typedef zboolean (* ZValidateIndexUInt32AndData	      ) (		zsize index, zuint32 value, void *data);
typedef zboolean (* ZValidateContextAndUInt32	      ) (void *context,		     zuint32 value	      );
typedef zboolean (* ZValidateContextUInt32AndData     ) (void *context,		     zuint32 value, void *data);
typedef zboolean (* ZValidateContextIndexAndUInt32    ) (void *context, zsize index, zuint32 value	      );
typedef zboolean (* ZValidateContextIndexUInt32AndData) (void *context, zsize index, zuint32 value, void *data);

#if Z_IS_AVAILABLE(UINT64)
	typedef zboolean (* ZValidateUInt64		      ) (			     zuint64 value	      );
	typedef zboolean (* ZValidateUInt64AndData	      ) (			     zuint64 value, void *data);
	typedef zboolean (* ZValidateIndexAndUInt64	      ) (		zsize index, zuint64 value	      );
	typedef zboolean (* ZValidateIndexUInt64AndData	      ) (		zsize index, zuint64 value, void *data);
	typedef zboolean (* ZValidateContextAndUInt64	      ) (void *context,		     zuint64 value	      );
	typedef zboolean (* ZValidateContextUInt64AndData     ) (void *context,		     zuint64 value, void *data);
	typedef zboolean (* ZValidateContextIndexAndUInt64    ) (void *context, zsize index, zuint64 value	      );
	typedef zboolean (* ZValidateContextIndexUInt64AndData) (void *context, zsize index, zuint64 value, void *data);
#endif

#if Z_IS_AVAILABLE(UINT128)
	typedef zboolean (* ZValidateUInt128		       ) (			      zuint128 value		);
	typedef zboolean (* ZValidateUInt128AndData	       ) (			      zuint128 value, void *data);
	typedef zboolean (* ZValidateIndexAndUInt128	       ) (		 zsize index, zuint128 value		);
	typedef zboolean (* ZValidateIndexUInt128AndData       ) (		 zsize index, zuint128 value, void *data);
	typedef zboolean (* ZValidateContextAndUInt128	       ) (void *context,	      zuint128 value		);
	typedef zboolean (* ZValidateContextUInt128AndData     ) (void *context,	      zuint128 value, void *data);
	typedef zboolean (* ZValidateContextIndexAndUInt128    ) (void *context, zsize index, zuint128 value		);
	typedef zboolean (* ZValidateContextIndexUInt128AndData) (void *context, zsize index, zuint128 value, void *data);
#endif

typedef zboolean (* ZValidateInt8		    ) (				   zint8 value		  );
typedef zboolean (* ZValidateInt8AndData	    ) (				   zint8 value, void *data);
typedef zboolean (* ZValidateIndexAndInt8	    ) (		      zsize index, zint8 value		  );
typedef zboolean (* ZValidateIndexInt8AndData	    ) (		      zsize index, zint8 value, void *data);
typedef zboolean (* ZValidateContextAndInt8	    ) (void *context,		   zint8 value		  );
typedef zboolean (* ZValidateContextInt8AndData	    ) (void *context,		   zint8 value, void *data);
typedef zboolean (* ZValidateContextIndexAndInt8    ) (void *context, zsize index, zint8 value		  );
typedef zboolean (* ZValidateContextIndexInt8AndData) (void *context, zsize index, zint8 value, void *data);

typedef zboolean (* ZValidateInt16		     ) (			    zint16 value	    );
typedef zboolean (* ZValidateInt16AndData	     ) (			    zint16 value, void *data);
typedef zboolean (* ZValidateIndexAndInt16	     ) (	       zsize index, zint16 value	    );
typedef zboolean (* ZValidateIndexInt16AndData	     ) (	       zsize index, zint16 value, void *data);
typedef zboolean (* ZValidateContextAndInt16	     ) (void *context,		    zint16 value	    );
typedef zboolean (* ZValidateContextInt16AndData     ) (void *context,		    zint16 value, void *data);
typedef zboolean (* ZValidateContextIndexAndInt16    ) (void *context, zsize index, zint16 value	    );
typedef zboolean (* ZValidateContextIndexInt16AndData) (void *context, zsize index, zint16 value, void *data);

typedef zboolean (* ZValidateInt32		     ) (			    zint32 value	    );
typedef zboolean (* ZValidateInt32AndData	     ) (			    zint32 value, void *data);
typedef zboolean (* ZValidateIndexAndInt32	     ) (	       zsize index, zint32 value	    );
typedef zboolean (* ZValidateIndexInt32AndData	     ) (	       zsize index, zint32 value, void *data);
typedef zboolean (* ZValidateContextAndInt32	     ) (void *context,		    zint32 value	    );
typedef zboolean (* ZValidateContextInt32AndData     ) (void *context,		    zint32 value, void *data);
typedef zboolean (* ZValidateContextIndexAndInt32    ) (void *context, zsize index, zint32 value	    );
typedef zboolean (* ZValidateContextIndexInt32AndData) (void *context, zsize index, zint32 value, void *data);

#if Z_IS_AVAILABLE(INT64)
	typedef zboolean (* ZValidateInt64		     ) (			    zint64 value	    );
	typedef zboolean (* ZValidateInt64AndData	     ) (			    zint64 value, void *data);
	typedef zboolean (* ZValidateIndexAndInt64	     ) (	       zsize index, zint64 value	    );
	typedef zboolean (* ZValidateIndexInt64AndData	     ) (	       zsize index, zint64 value, void *data);
	typedef zboolean (* ZValidateContextAndInt64	     ) (void *context,		    zint64 value	    );
	typedef zboolean (* ZValidateContextInt64AndData     ) (void *context,		    zint64 value, void *data);
	typedef zboolean (* ZValidateContextIndexAndInt64    ) (void *context, zsize index, zint64 value	    );
	typedef zboolean (* ZValidateContextIndexInt64AndData) (void *context, zsize index, zint64 value, void *data);
#endif

#if Z_IS_AVAILABLE(INT128)
	typedef zboolean (* ZValidateInt128		      ) (			     zint128 value	      );
	typedef zboolean (* ZValidateInt128AndData	      ) (			     zint128 value, void *data);
	typedef zboolean (* ZValidateIndexAndInt128	      ) (		zsize index, zint128 value	      );
	typedef zboolean (* ZValidateIndexInt128AndData	      ) (		zsize index, zint128 value, void *data);
	typedef zboolean (* ZValidateContextAndInt128	      ) (void *context,		     zint128 value	      );
	typedef zboolean (* ZValidateContextInt128AndData     ) (void *context,		     zint128 value, void *data);
	typedef zboolean (* ZValidateContextIndexAndInt128    ) (void *context, zsize index, zint128 value	      );
	typedef zboolean (* ZValidateContextIndexInt128AndData) (void *context, zsize index, zint128 value, void *data);

#endif

#if Z_IS_AVAILABLE(FLOAT16)
	typedef zboolean (* ZValidateFloat16		       ) (			      zfloat16 value		);
	typedef zboolean (* ZValidateFloat16AndData	       ) (			      zfloat16 value, void *data);
	typedef zboolean (* ZValidateIndexAndFloat16	       ) (		 zsize index, zfloat16 value		);
	typedef zboolean (* ZValidateIndexFloat16AndData       ) (		 zsize index, zfloat16 value, void *data);
	typedef zboolean (* ZValidateContextAndFloat16	       ) (void *context,	      zfloat16 value		);
	typedef zboolean (* ZValidateContextFloat16AndData     ) (void *context,	      zfloat16 value, void *data);
	typedef zboolean (* ZValidateContextIndexAndFloat16    ) (void *context, zsize index, zfloat16 value		);
	typedef zboolean (* ZValidateContextIndexFloat16AndData) (void *context, zsize index, zfloat16 value, void *data);
#endif

#if Z_IS_AVAILABLE(FLOAT24)
	typedef zboolean (* ZValidateFloat24		       ) (			      zfloat24 value		);
	typedef zboolean (* ZValidateFloat24AndData	       ) (			      zfloat24 value, void *data);
	typedef zboolean (* ZValidateIndexAndFloat24	       ) (		 zsize index, zfloat24 value		);
	typedef zboolean (* ZValidateIndexFloat24AndData       ) (		 zsize index, zfloat24 value, void *data);
	typedef zboolean (* ZValidateContextAndFloat24	       ) (void *context,	      zfloat24 value		);
	typedef zboolean (* ZValidateContextFloat24AndData     ) (void *context,	      zfloat24 value, void *data);
	typedef zboolean (* ZValidateContextIndexAndFloat24    ) (void *context, zsize index, zfloat24 value		);
	typedef zboolean (* ZValidateContextIndexFloat24AndData) (void *context, zsize index, zfloat24 value, void *data);
#endif

#if Z_IS_AVAILABLE(FLOAT32)
	typedef zboolean (* ZValidateFloat32		       ) (			      zfloat32 value		);
	typedef zboolean (* ZValidateFloat32AndData	       ) (			      zfloat32 value, void *data);
	typedef zboolean (* ZValidateIndexAndFloat32	       ) (		 zsize index, zfloat32 value		);
	typedef zboolean (* ZValidateIndexFloat32AndData       ) (		 zsize index, zfloat32 value, void *data);
	typedef zboolean (* ZValidateContextAndFloat32	       ) (void *context,	      zfloat32 value		);
	typedef zboolean (* ZValidateContextFloat32AndData     ) (void *context,	      zfloat32 value, void *data);
	typedef zboolean (* ZValidateContextIndexAndFloat32    ) (void *context, zsize index, zfloat32 value		);
	typedef zboolean (* ZValidateContextIndexFloat32AndData) (void *context, zsize index, zfloat32 value, void *data);
#endif

#if Z_IS_AVAILABLE(FLOAT48)
	typedef zboolean (* ZValidateFloat48		       ) (			      zfloat48 value		);
	typedef zboolean (* ZValidateFloat48AndData	       ) (			      zfloat48 value, void *data);
	typedef zboolean (* ZValidateIndexAndFloat48	       ) (		 zsize index, zfloat48 value		);
	typedef zboolean (* ZValidateIndexFloat48AndData       ) (		 zsize index, zfloat48 value, void *data);
	typedef zboolean (* ZValidateContextAndFloat48	       ) (void *context,	      zfloat48 value		);
	typedef zboolean (* ZValidateContextFloat48AndData     ) (void *context,	      zfloat48 value, void *data);
	typedef zboolean (* ZValidateContextIndexAndFloat48    ) (void *context, zsize index, zfloat48 value		);
	typedef zboolean (* ZValidateContextIndexFloat48AndData) (void *context, zsize index, zfloat48 value, void *data);
#endif

#if Z_IS_AVAILABLE(FLOAT64)
	typedef zboolean (* ZValidateFloat64		       ) (			      zfloat64 value		);
	typedef zboolean (* ZValidateFloat64AndData	       ) (			      zfloat64 value, void *data);
	typedef zboolean (* ZValidateIndexAndFloat64	       ) (		 zsize index, zfloat64 value		);
	typedef zboolean (* ZValidateIndexFloat64AndData       ) (		 zsize index, zfloat64 value, void *data);
	typedef zboolean (* ZValidateContextAndFloat64	       ) (void *context,	      zfloat64 value		);
	typedef zboolean (* ZValidateContextFloat64AndData     ) (void *context,	      zfloat64 value, void *data);
	typedef zboolean (* ZValidateContextIndexAndFloat64    ) (void *context, zsize index, zfloat64 value		);
	typedef zboolean (* ZValidateContextIndexFloat64AndData) (void *context, zsize index, zfloat64 value, void *data);
#endif

#if Z_IS_AVAILABLE(FLOAT72)
	typedef zboolean (* ZValidateFloat72		       ) (			      zfloat72 value		);
	typedef zboolean (* ZValidateFloat72AndData	       ) (			      zfloat72 value, void *data);
	typedef zboolean (* ZValidateIndexAndFloat72	       ) (		 zsize index, zfloat72 value		);
	typedef zboolean (* ZValidateIndexFloat72AndData       ) (		 zsize index, zfloat72 value, void *data);
	typedef zboolean (* ZValidateContextAndFloat72	       ) (void *context,	      zfloat72 value		);
	typedef zboolean (* ZValidateContextFloat72AndData     ) (void *context,	      zfloat72 value, void *data);
	typedef zboolean (* ZValidateContextIndexAndFloat72    ) (void *context, zsize index, zfloat72 value		);
	typedef zboolean (* ZValidateContextIndexFloat72AndData) (void *context, zsize index, zfloat72 value, void *data);
#endif

#if Z_IS_AVAILABLE(FLOAT80)
	typedef zboolean (* ZValidateFloat80		       ) (			      zfloat80 value		);
	typedef zboolean (* ZValidateFloat80AndData	       ) (			      zfloat80 value, void *data);
	typedef zboolean (* ZValidateIndexAndFloat80	       ) (		 zsize index, zfloat80 value		);
	typedef zboolean (* ZValidateIndexFloat80AndData       ) (		 zsize index, zfloat80 value, void *data);
	typedef zboolean (* ZValidateContextAndFloat80	       ) (void *context,	      zfloat80 value		);
	typedef zboolean (* ZValidateContextFloat80AndData     ) (void *context,	      zfloat80 value, void *data);
	typedef zboolean (* ZValidateContextIndexAndFloat80    ) (void *context, zsize index, zfloat80 value		);
	typedef zboolean (* ZValidateContextIndexFloat80AndData) (void *context, zsize index, zfloat80 value, void *data);
#endif

#if Z_IS_AVAILABLE(FLOAT96)
	typedef zboolean (* ZValidateFloat96		       ) (			      zfloat96 value		);
	typedef zboolean (* ZValidateFloat96AndData	       ) (			      zfloat96 value, void *data);
	typedef zboolean (* ZValidateIndexAndFloat96	       ) (		 zsize index, zfloat96 value		);
	typedef zboolean (* ZValidateIndexFloat96AndData       ) (		 zsize index, zfloat96 value, void *data);
	typedef zboolean (* ZValidateContextAndFloat96	       ) (void *context,	      zfloat96 value		);
	typedef zboolean (* ZValidateContextFloat96AndData     ) (void *context,	      zfloat96 value, void *data);
	typedef zboolean (* ZValidateContextIndexAndFloat96    ) (void *context, zsize index, zfloat96 value		);
	typedef zboolean (* ZValidateContextIndexFloat96AndData) (void *context, zsize index, zfloat96 value, void *data);
#endif

#if Z_IS_AVAILABLE(FLOAT128)
	typedef zboolean (* ZValidateFloat128			) (			       zfloat128 value		  );
	typedef zboolean (* ZValidateFloat128AndData		) (			       zfloat128 value, void *data);
	typedef zboolean (* ZValidateIndexAndFloat128		) (		  zsize index, zfloat128 value		  );
	typedef zboolean (* ZValidateIndexFloat128AndData	) (		  zsize index, zfloat128 value, void *data);
	typedef zboolean (* ZValidateContextAndFloat128		) (void *context,	       zfloat128 value		  );
	typedef zboolean (* ZValidateContextFloat128AndData	) (void *context,	       zfloat128 value, void *data);
	typedef zboolean (* ZValidateContextIndexAndFloat128	) (void *context, zsize index, zfloat128 value		  );
	typedef zboolean (* ZValidateContextIndexFloat128AndData) (void *context, zsize index, zfloat128 value, void *data);
#endif

typedef zboolean (* ZValidatePointer		       ) (			      void *pointer	       );
typedef zboolean (* ZValidatePointerAndData	       ) (			      void *pointer, void *data);
typedef zboolean (* ZValidateIndexAndPointer	       ) (		 zsize index, void *pointer	       );
typedef zboolean (* ZValidateIndexPointerAndData       ) (		 zsize index, void *pointer, void *data);
typedef zboolean (* ZValidateContextAndPointer	       ) (void *context,	      void *pointer	       );
typedef zboolean (* ZValidateContextPointerAndData     ) (void *context,	      void *pointer, void *data);
typedef zboolean (* ZValidateContextIndexAndPointer    ) (void *context, zsize index, void *pointer	       );
typedef zboolean (* ZValidateContextIndexPointerAndData) (void *context, zsize index, void *pointer, void *data);

#define ZValidateType(			 TYPE) Z_INSERT_##TYPE##_FixedType(ZValidate,			    )
#define ZValidateTypeAndData(		 TYPE) Z_INSERT_##TYPE##_FixedType(ZValidate,		     AndData)
#define ZValidateIndexAndType(		 TYPE) Z_INSERT_##TYPE##_FixedType(ZValidateIndexAnd,		    )
#define ZValidateIndexTypeAndData(	 TYPE) Z_INSERT_##TYPE##_FixedType(ZValidateIndex,	     AndData)
#define ZValidateContextAndType(	 TYPE) Z_INSERT_##TYPE##_FixedType(ZValidateContextAnd,		    )
#define ZValidateContextTypeAndData(	 TYPE) Z_INSERT_##TYPE##_FixedType(ZValidateContext,	     AndData)
#define ZValidateContextIndexAndType(	 TYPE) Z_INSERT_##TYPE##_FixedType(ZValidateContextIndexAnd,	    )
#define ZValidateContextIndexTypeAndData(TYPE) Z_INSERT_##TYPE##_FixedType(ZValidateContextIndex,    AndData)

#endif /* __Z_types_validation_H__ */
