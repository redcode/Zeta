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

typedef void (* ZHandleUInt8			   )(				 zuint8 value				 );
typedef void (* ZHandleUInt8AndData		   )(				 zuint8 value, void *data		 );
typedef void (* ZHandleIndexAndUInt8		   )(		    zsize index, zuint8 value				 );
typedef void (* ZHandleIndexUInt8AndData	   )(		    zsize index, zuint8 value, void *data		 );
typedef void (* ZHandleContextAndUInt8		   )(void *context,		 zuint8 value				 );
typedef void (* ZHandleContextUInt8AndData	   )(void *context,		 zuint8 value, void *data		 );
typedef void (* ZHandleContextIndexAndUInt8	   )(void *context, zsize index, zuint8 value				 );
typedef void (* ZHandleContextIndexUInt8AndData	   )(void *context, zsize index, zuint8 value, void *data		 );
typedef void (* ZHandleUInt8AndStop		   )(				 zuint8 value,		   zboolean *stop);
typedef void (* ZHandleUInt8DataAndStop		   )(				 zuint8 value, void *data, zboolean *stop);
typedef void (* ZHandleIndexUInt8AndStop	   )(		    zsize index, zuint8 value,		   zboolean *stop);
typedef void (* ZHandleIndexUInt8DataAndStop	   )(		    zsize index, zuint8 value, void *data, zboolean *stop);
typedef void (* ZHandleContextUInt8AndStop	   )(void *context,		 zuint8 value,		   zboolean *stop);
typedef void (* ZHandleContextUInt8DataAndStop	   )(void *context,		 zuint8 value, void *data, zboolean *stop);
typedef void (* ZHandleContextIndexUInt8AndStop	   )(void *context, zsize index, zuint8 value,		   zboolean *stop);
typedef void (* ZHandleContextIndexUInt8DataAndStop)(void *context, zsize index, zuint8 value, void *data, zboolean *stop);

typedef void (* ZHandleUInt16			    )(				  zuint16 value				   );
typedef void (* ZHandleUInt16AndData		    )(				  zuint16 value, void *data		   );
typedef void (* ZHandleIndexAndUInt16		    )(		     zsize index, zuint16 value				   );
typedef void (* ZHandleIndexUInt16AndData	    )(		     zsize index, zuint16 value, void *data		   );
typedef void (* ZHandleContextAndUInt16		    )(void *context,		  zuint16 value				   );
typedef void (* ZHandleContextUInt16AndData	    )(void *context,		  zuint16 value, void *data		   );
typedef void (* ZHandleContextIndexAndUInt16	    )(void *context, zsize index, zuint16 value				   );
typedef void (* ZHandleContextIndexUInt16AndData    )(void *context, zsize index, zuint16 value, void *data		   );
typedef void (* ZHandleUInt16AndStop		    )(				  zuint16 value,	     zboolean *stop);
typedef void (* ZHandleUInt16DataAndStop	    )(				  zuint16 value, void *data, zboolean *stop);
typedef void (* ZHandleIndexUInt16AndStop	    )(		     zsize index, zuint16 value,	     zboolean *stop);
typedef void (* ZHandleIndexUInt16DataAndStop	    )(		     zsize index, zuint16 value, void *data, zboolean *stop);
typedef void (* ZHandleContextUInt16AndStop	    )(void *context,		  zuint16 value,	     zboolean *stop);
typedef void (* ZHandleContextUInt16DataAndStop	    )(void *context,		  zuint16 value, void *data, zboolean *stop);
typedef void (* ZHandleContextIndexUInt16AndStop    )(void *context, zsize index, zuint16 value,	     zboolean *stop);
typedef void (* ZHandleContextIndexUInt16DataAndStop)(void *context, zsize index, zuint16 value, void *data, zboolean *stop);

typedef void (* ZHandleUInt32			    )(				  zuint32 value				   );
typedef void (* ZHandleUInt32AndData		    )(				  zuint32 value, void *data		   );
typedef void (* ZHandleIndexAndUInt32		    )(		     zsize index, zuint32 value				   );
typedef void (* ZHandleIndexUInt32AndData	    )(		     zsize index, zuint32 value, void *data		   );
typedef void (* ZHandleContextAndUInt32		    )(void *context,		  zuint32 value				   );
typedef void (* ZHandleContextUInt32AndData	    )(void *context,		  zuint32 value, void *data		   );
typedef void (* ZHandleContextIndexAndUInt32	    )(void *context, zsize index, zuint32 value				   );
typedef void (* ZHandleContextIndexUInt32AndData    )(void *context, zsize index, zuint32 value, void *data		   );
typedef void (* ZHandleUInt32AndStop		    )(				  zuint32 value,	     zboolean *stop);
typedef void (* ZHandleUInt32DataAndStop	    )(				  zuint32 value, void *data, zboolean *stop);
typedef void (* ZHandleIndexUInt32AndStop	    )(		     zsize index, zuint32 value,	     zboolean *stop);
typedef void (* ZHandleIndexUInt32DataAndStop	    )(		     zsize index, zuint32 value, void *data, zboolean *stop);
typedef void (* ZHandleContextUInt32AndStop	    )(void *context,		  zuint32 value,	     zboolean *stop);
typedef void (* ZHandleContextUInt32DataAndStop	    )(void *context,		  zuint32 value, void *data, zboolean *stop);
typedef void (* ZHandleContextIndexUInt32AndStop    )(void *context, zsize index, zuint32 value,	     zboolean *stop);
typedef void (* ZHandleContextIndexUInt32DataAndStop)(void *context, zsize index, zuint32 value, void *data, zboolean *stop);

#if Z_IS_AVAILABLE(UINT64)
	typedef void (* ZHandleUInt64			    )(				  zuint64 value				   );
	typedef void (* ZHandleUInt64AndData		    )(				  zuint64 value, void *data		   );
	typedef void (* ZHandleIndexAndUInt64		    )(		     zsize index, zuint64 value				   );
	typedef void (* ZHandleIndexUInt64AndData	    )(		     zsize index, zuint64 value, void *data		   );
	typedef void (* ZHandleContextAndUInt64		    )(void *context,		  zuint64 value				   );
	typedef void (* ZHandleContextUInt64AndData	    )(void *context,		  zuint64 value, void *data		   );
	typedef void (* ZHandleContextIndexAndUInt64	    )(void *context, zsize index, zuint64 value				   );
	typedef void (* ZHandleContextIndexUInt64AndData    )(void *context, zsize index, zuint64 value, void *data		   );
	typedef void (* ZHandleUInt64AndStop		    )(				  zuint64 value,	     zboolean *stop);
	typedef void (* ZHandleUInt64DataAndStop	    )(				  zuint64 value, void *data, zboolean *stop);
	typedef void (* ZHandleIndexUInt64AndStop	    )(		     zsize index, zuint64 value,	     zboolean *stop);
	typedef void (* ZHandleIndexUInt64DataAndStop	    )(		     zsize index, zuint64 value, void *data, zboolean *stop);
	typedef void (* ZHandleContextUInt64AndStop	    )(void *context,		  zuint64 value,	     zboolean *stop);
	typedef void (* ZHandleContextUInt64DataAndStop	    )(void *context,		  zuint64 value, void *data, zboolean *stop);
	typedef void (* ZHandleContextIndexUInt64AndStop    )(void *context, zsize index, zuint64 value,	     zboolean *stop);
	typedef void (* ZHandleContextIndexUInt64DataAndStop)(void *context, zsize index, zuint64 value, void *data, zboolean *stop);
#endif

#if Z_IS_AVAILABLE(UINT128)
	typedef void (* ZHandleUInt128			     )(				   zuint128 value			     );
	typedef void (* ZHandleUInt128AndData		     )(				   zuint128 value, void *data		     );
	typedef void (* ZHandleIndexAndUInt128		     )(		      zsize index, zuint128 value			     );
	typedef void (* ZHandleIndexUInt128AndData	     )(		      zsize index, zuint128 value, void *data		     );
	typedef void (* ZHandleContextAndUInt128	     )(void *context,		   zuint128 value			     );
	typedef void (* ZHandleContextUInt128AndData	     )(void *context,		   zuint128 value, void *data		     );
	typedef void (* ZHandleContextIndexAndUInt128	     )(void *context, zsize index, zuint128 value			     );
	typedef void (* ZHandleContextIndexUInt128AndData    )(void *context, zsize index, zuint128 value, void *data		     );
	typedef void (* ZHandleUInt128AndStop		     )(				   zuint128 value,	       zboolean *stop);
	typedef void (* ZHandleUInt128DataAndStop	     )(				   zuint128 value, void *data, zboolean *stop);
	typedef void (* ZHandleIndexUInt128AndStop	     )(		      zsize index, zuint128 value,	       zboolean *stop);
	typedef void (* ZHandleIndexUInt128DataAndStop	     )(		      zsize index, zuint128 value, void *data, zboolean *stop);
	typedef void (* ZHandleContextUInt128AndStop	     )(void *context,		   zuint128 value,	       zboolean *stop);
	typedef void (* ZHandleContextUInt128DataAndStop     )(void *context,		   zuint128 value, void *data, zboolean *stop);
	typedef void (* ZHandleContextIndexUInt128AndStop    )(void *context, zsize index, zuint128 value,	       zboolean *stop);
	typedef void (* ZHandleContextIndexUInt128DataAndStop)(void *context, zsize index, zuint128 value, void *data, zboolean *stop);
#endif

typedef void (* ZHandleInt8			  )(				zint8 value			       );
typedef void (* ZHandleInt8AndData		  )(				zint8 value, void *data		       );
typedef void (* ZHandleIndexAndInt8		  )(		   zsize index, zint8 value			       );
typedef void (* ZHandleIndexInt8AndData		  )(		   zsize index, zint8 value, void *data		       );
typedef void (* ZHandleContextAndInt8		  )(void *context,		zint8 value			       );
typedef void (* ZHandleContextInt8AndData	  )(void *context,		zint8 value, void *data		       );
typedef void (* ZHandleContextIndexAndInt8	  )(void *context, zsize index, zint8 value			       );
typedef void (* ZHandleContextIndexInt8AndData	  )(void *context, zsize index, zint8 value, void *data		       );
typedef void (* ZHandleInt8AndStop		  )(				zint8 value,		 zboolean *stop);
typedef void (* ZHandleInt8DataAndStop		  )(				zint8 value, void *data, zboolean *stop);
typedef void (* ZHandleIndexInt8AndStop		  )(		   zsize index, zint8 value,		 zboolean *stop);
typedef void (* ZHandleIndexInt8DataAndStop	  )(		   zsize index, zint8 value, void *data, zboolean *stop);
typedef void (* ZHandleContextInt8AndStop	  )(void *context,		zint8 value,		 zboolean *stop);
typedef void (* ZHandleContextInt8DataAndStop	  )(void *context,		zint8 value, void *data, zboolean *stop);
typedef void (* ZHandleContextIndexInt8AndStop	  )(void *context, zsize index, zint8 value,		 zboolean *stop);
typedef void (* ZHandleContextIndexInt8DataAndStop)(void *context, zsize index, zint8 value, void *data, zboolean *stop);

typedef void (* ZHandleInt16			   )(				 zint16 value				 );
typedef void (* ZHandleInt16AndData		   )(				 zint16 value, void *data		 );
typedef void (* ZHandleIndexAndInt16		   )(		    zsize index, zint16 value				 );
typedef void (* ZHandleIndexInt16AndData	   )(		    zsize index, zint16 value, void *data		 );
typedef void (* ZHandleContextAndInt16		   )(void *context,		 zint16 value				 );
typedef void (* ZHandleContextInt16AndData	   )(void *context,		 zint16 value, void *data		 );
typedef void (* ZHandleContextIndexAndInt16	   )(void *context, zsize index, zint16 value				 );
typedef void (* ZHandleContextIndexInt16AndData	   )(void *context, zsize index, zint16 value, void *data		 );
typedef void (* ZHandleInt16AndStop		   )(				 zint16 value,		   zboolean *stop);
typedef void (* ZHandleInt16DataAndStop		   )(				 zint16 value, void *data, zboolean *stop);
typedef void (* ZHandleIndexInt16AndStop	   )(		    zsize index, zint16 value,		   zboolean *stop);
typedef void (* ZHandleIndexInt16DataAndStop	   )(		    zsize index, zint16 value, void *data, zboolean *stop);
typedef void (* ZHandleContextInt16AndStop	   )(void *context,		 zint16 value,		   zboolean *stop);
typedef void (* ZHandleContextInt16DataAndStop	   )(void *context,		 zint16 value, void *data, zboolean *stop);
typedef void (* ZHandleContextIndexInt16AndStop	   )(void *context, zsize index, zint16 value,		   zboolean *stop);
typedef void (* ZHandleContextIndexInt16DataAndStop)(void *context, zsize index, zint16 value, void *data, zboolean *stop);

typedef void (* ZHandleInt32			   )(				 zint32 value				 );
typedef void (* ZHandleInt32AndData		   )(				 zint32 value, void *data		 );
typedef void (* ZHandleIndexAndInt32		   )(		    zsize index, zint32 value				 );
typedef void (* ZHandleIndexInt32AndData	   )(		    zsize index, zint32 value, void *data		 );
typedef void (* ZHandleContextAndInt32		   )(void *context,		 zint32 value				 );
typedef void (* ZHandleContextInt32AndData	   )(void *context,		 zint32 value, void *data		 );
typedef void (* ZHandleContextIndexAndInt32	   )(void *context, zsize index, zint32 value				 );
typedef void (* ZHandleContextIndexInt32AndData	   )(void *context, zsize index, zint32 value, void *data		 );
typedef void (* ZHandleInt32AndStop		   )(				 zint32 value,		   zboolean *stop);
typedef void (* ZHandleInt32DataAndStop		   )(				 zint32 value, void *data, zboolean *stop);
typedef void (* ZHandleIndexInt32AndStop	   )(		    zsize index, zint32 value,		   zboolean *stop);
typedef void (* ZHandleIndexInt32DataAndStop	   )(		    zsize index, zint32 value, void *data, zboolean *stop);
typedef void (* ZHandleContextInt32AndStop	   )(void *context,		 zint32 value,		   zboolean *stop);
typedef void (* ZHandleContextInt32DataAndStop	   )(void *context,		 zint32 value, void *data, zboolean *stop);
typedef void (* ZHandleContextIndexInt32AndStop	   )(void *context, zsize index, zint32 value,		   zboolean *stop);
typedef void (* ZHandleContextIndexInt32DataAndStop)(void *context, zsize index, zint32 value, void *data, zboolean *stop);

#if Z_IS_AVAILABLE(INT64)
	typedef void (* ZHandleInt64			   )(				 zint64 value				 );
	typedef void (* ZHandleInt64AndData		   )(				 zint64 value, void *data		 );
	typedef void (* ZHandleIndexAndInt64		   )(		    zsize index, zint64 value				 );
	typedef void (* ZHandleIndexInt64AndData	   )(		    zsize index, zint64 value, void *data		 );
	typedef void (* ZHandleContextAndInt64		   )(void *context,		 zint64 value				 );
	typedef void (* ZHandleContextInt64AndData	   )(void *context,		 zint64 value, void *data		 );
	typedef void (* ZHandleContextIndexAndInt64	   )(void *context, zsize index, zint64 value				 );
	typedef void (* ZHandleContextIndexInt64AndData	   )(void *context, zsize index, zint64 value, void *data		 );
	typedef void (* ZHandleInt64AndStop		   )(				 zint64 value,		   zboolean *stop);
	typedef void (* ZHandleInt64DataAndStop		   )(				 zint64 value, void *data, zboolean *stop);
	typedef void (* ZHandleIndexInt64AndStop	   )(		    zsize index, zint64 value,		   zboolean *stop);
	typedef void (* ZHandleIndexInt64DataAndStop	   )(		    zsize index, zint64 value, void *data, zboolean *stop);
	typedef void (* ZHandleContextInt64AndStop	   )(void *context,		 zint64 value,		   zboolean *stop);
	typedef void (* ZHandleContextInt64DataAndStop	   )(void *context,		 zint64 value, void *data, zboolean *stop);
	typedef void (* ZHandleContextIndexInt64AndStop	   )(void *context, zsize index, zint64 value,		   zboolean *stop);
	typedef void (* ZHandleContextIndexInt64DataAndStop)(void *context, zsize index, zint64 value, void *data, zboolean *stop);
#endif

#if Z_IS_AVAILABLE(INT128)
	typedef void (* ZHandleInt128			    )(				  zint128 value				   );
	typedef void (* ZHandleInt128AndData		    )(				  zint128 value, void *data		   );
	typedef void (* ZHandleIndexAndInt128		    )(		     zsize index, zint128 value				   );
	typedef void (* ZHandleIndexInt128AndData	    )(		     zsize index, zint128 value, void *data		   );
	typedef void (* ZHandleContextAndInt128		    )(void *context,		  zint128 value				   );
	typedef void (* ZHandleContextInt128AndData	    )(void *context,		  zint128 value, void *data		   );
	typedef void (* ZHandleContextIndexAndInt128	    )(void *context, zsize index, zint128 value				   );
	typedef void (* ZHandleContextIndexInt128AndData    )(void *context, zsize index, zint128 value, void *data		   );
	typedef void (* ZHandleInt128AndStop		    )(				  zint128 value,	     zboolean *stop);
	typedef void (* ZHandleInt128DataAndStop	    )(				  zint128 value, void *data, zboolean *stop);
	typedef void (* ZHandleIndexInt128AndStop	    )(		     zsize index, zint128 value,	     zboolean *stop);
	typedef void (* ZHandleIndexInt128DataAndStop	    )(		     zsize index, zint128 value, void *data, zboolean *stop);
	typedef void (* ZHandleContextInt128AndStop	    )(void *context,		  zint128 value,	     zboolean *stop);
	typedef void (* ZHandleContextInt128DataAndStop	    )(void *context,		  zint128 value, void *data, zboolean *stop);
	typedef void (* ZHandleContextIndexInt128AndStop    )(void *context, zsize index, zint128 value,	     zboolean *stop);
	typedef void (* ZHandleContextIndexInt128DataAndStop)(void *context, zsize index, zint128 value, void *data, zboolean *stop);
#endif

#if Z_IS_AVAILABLE(FLOAT16)
	typedef void (* ZHandleFloat16			     )(				   zfloat16 value			     );
	typedef void (* ZHandleFloat16AndData		     )(				   zfloat16 value, void *data		     );
	typedef void (* ZHandleIndexAndFloat16		     )(		      zsize index, zfloat16 value			     );
	typedef void (* ZHandleIndexFloat16AndData	     )(		      zsize index, zfloat16 value, void *data		     );
	typedef void (* ZHandleContextAndFloat16	     )(void *context,		   zfloat16 value			     );
	typedef void (* ZHandleContextFloat16AndData	     )(void *context,		   zfloat16 value, void *data		     );
	typedef void (* ZHandleContextIndexAndFloat16	     )(void *context, zsize index, zfloat16 value			     );
	typedef void (* ZHandleContextIndexFloat16AndData    )(void *context, zsize index, zfloat16 value, void *data		     );
	typedef void (* ZHandleFloat16AndStop		     )(				   zfloat16 value,	       zboolean *stop);
	typedef void (* ZHandleFloat16DataAndStop	     )(				   zfloat16 value, void *data, zboolean *stop);
	typedef void (* ZHandleIndexFloat16AndStop	     )(		      zsize index, zfloat16 value,	       zboolean *stop);
	typedef void (* ZHandleIndexFloat16DataAndStop	     )(		      zsize index, zfloat16 value, void *data, zboolean *stop);
	typedef void (* ZHandleContextFloat16AndStop	     )(void *context,		   zfloat16 value,	       zboolean *stop);
	typedef void (* ZHandleContextFloat16DataAndStop     )(void *context,		   zfloat16 value, void *data, zboolean *stop);
	typedef void (* ZHandleContextIndexFloat16AndStop    )(void *context, zsize index, zfloat16 value,	       zboolean *stop);
	typedef void (* ZHandleContextIndexFloat16DataAndStop)(void *context, zsize index, zfloat16 value, void *data, zboolean *stop);
#endif

#if Z_IS_AVAILABLE(FLOAT24)
	typedef void (* ZHandleFloat24			     )(				   zfloat24 value			     );
	typedef void (* ZHandleFloat24AndData		     )(				   zfloat24 value, void *data		     );
	typedef void (* ZHandleIndexAndFloat24		     )(		      zsize index, zfloat24 value			     );
	typedef void (* ZHandleIndexFloat24AndData	     )(		      zsize index, zfloat24 value, void *data		     );
	typedef void (* ZHandleContextAndFloat24	     )(void *context,		   zfloat24 value			     );
	typedef void (* ZHandleContextFloat24AndData	     )(void *context,		   zfloat24 value, void *data		     );
	typedef void (* ZHandleContextIndexAndFloat24	     )(void *context, zsize index, zfloat24 value			     );
	typedef void (* ZHandleContextIndexFloat24AndData    )(void *context, zsize index, zfloat24 value, void *data		     );
	typedef void (* ZHandleFloat24AndStop		     )(				   zfloat24 value,	       zboolean *stop);
	typedef void (* ZHandleFloat24DataAndStop	     )(				   zfloat24 value, void *data, zboolean *stop);
	typedef void (* ZHandleIndexFloat24AndStop	     )(		      zsize index, zfloat24 value,	       zboolean *stop);
	typedef void (* ZHandleIndexFloat24DataAndStop	     )(		      zsize index, zfloat24 value, void *data, zboolean *stop);
	typedef void (* ZHandleContextFloat24AndStop	     )(void *context,		   zfloat24 value,	       zboolean *stop);
	typedef void (* ZHandleContextFloat24DataAndStop     )(void *context,		   zfloat24 value, void *data, zboolean *stop);
	typedef void (* ZHandleContextIndexFloat24AndStop    )(void *context, zsize index, zfloat24 value,	       zboolean *stop);
	typedef void (* ZHandleContextIndexFloat24DataAndStop)(void *context, zsize index, zfloat24 value, void *data, zboolean *stop);
#endif

#if Z_IS_AVAILABLE(FLOAT32)
	typedef void (* ZHandleFloat32			     )(				   zfloat32 value			     );
	typedef void (* ZHandleFloat32AndData		     )(				   zfloat32 value, void *data		     );
	typedef void (* ZHandleIndexAndFloat32		     )(		      zsize index, zfloat32 value			     );
	typedef void (* ZHandleIndexFloat32AndData	     )(		      zsize index, zfloat32 value, void *data		     );
	typedef void (* ZHandleContextAndFloat32	     )(void *context,		   zfloat32 value			     );
	typedef void (* ZHandleContextFloat32AndData	     )(void *context,		   zfloat32 value, void *data		     );
	typedef void (* ZHandleContextIndexAndFloat32	     )(void *context, zsize index, zfloat32 value			     );
	typedef void (* ZHandleContextIndexFloat32AndData    )(void *context, zsize index, zfloat32 value, void *data		     );
	typedef void (* ZHandleFloat32AndStop		     )(				   zfloat32 value,	       zboolean *stop);
	typedef void (* ZHandleFloat32DataAndStop	     )(				   zfloat32 value, void *data, zboolean *stop);
	typedef void (* ZHandleIndexFloat32AndStop	     )(		      zsize index, zfloat32 value,	       zboolean *stop);
	typedef void (* ZHandleIndexFloat32DataAndStop	     )(		      zsize index, zfloat32 value, void *data, zboolean *stop);
	typedef void (* ZHandleContextFloat32AndStop	     )(void *context,		   zfloat32 value,	       zboolean *stop);
	typedef void (* ZHandleContextFloat32DataAndStop     )(void *context,		   zfloat32 value, void *data, zboolean *stop);
	typedef void (* ZHandleContextIndexFloat32AndStop    )(void *context, zsize index, zfloat32 value,	       zboolean *stop);
	typedef void (* ZHandleContextIndexFloat32DataAndStop)(void *context, zsize index, zfloat32 value, void *data, zboolean *stop);
#endif

#if Z_IS_AVAILABLE(FLOAT48)
	typedef void (* ZHandleFloat48			     )(				   zfloat48 value			     );
	typedef void (* ZHandleFloat48AndData		     )(				   zfloat48 value, void *data		     );
	typedef void (* ZHandleIndexAndFloat48		     )(		      zsize index, zfloat48 value			     );
	typedef void (* ZHandleIndexFloat48AndData	     )(		      zsize index, zfloat48 value, void *data		     );
	typedef void (* ZHandleContextAndFloat48	     )(void *context,		   zfloat48 value			     );
	typedef void (* ZHandleContextFloat48AndData	     )(void *context,		   zfloat48 value, void *data		     );
	typedef void (* ZHandleContextIndexAndFloat48	     )(void *context, zsize index, zfloat48 value			     );
	typedef void (* ZHandleContextIndexFloat48AndData    )(void *context, zsize index, zfloat48 value, void *data		     );
	typedef void (* ZHandleFloat48AndStop		     )(				   zfloat48 value,	       zboolean *stop);
	typedef void (* ZHandleFloat48DataAndStop	     )(				   zfloat48 value, void *data, zboolean *stop);
	typedef void (* ZHandleIndexFloat48AndStop	     )(		      zsize index, zfloat48 value,	       zboolean *stop);
	typedef void (* ZHandleIndexFloat48DataAndStop	     )(		      zsize index, zfloat48 value, void *data, zboolean *stop);
	typedef void (* ZHandleContextFloat48AndStop	     )(void *context,		   zfloat48 value,	       zboolean *stop);
	typedef void (* ZHandleContextFloat48DataAndStop     )(void *context,		   zfloat48 value, void *data, zboolean *stop);
	typedef void (* ZHandleContextIndexFloat48AndStop    )(void *context, zsize index, zfloat48 value,	       zboolean *stop);
	typedef void (* ZHandleContextIndexFloat48DataAndStop)(void *context, zsize index, zfloat48 value, void *data, zboolean *stop);
#endif

#if Z_IS_AVAILABLE(FLOAT64)
	typedef void (* ZHandleFloat64			     )(				   zfloat64 value			     );
	typedef void (* ZHandleFloat64AndData		     )(				   zfloat64 value, void *data		     );
	typedef void (* ZHandleIndexAndFloat64		     )(		      zsize index, zfloat64 value			     );
	typedef void (* ZHandleIndexFloat64AndData	     )(		      zsize index, zfloat64 value, void *data		     );
	typedef void (* ZHandleContextAndFloat64	     )(void *context,		   zfloat64 value			     );
	typedef void (* ZHandleContextFloat64AndData	     )(void *context,		   zfloat64 value, void *data		     );
	typedef void (* ZHandleContextIndexAndFloat64	     )(void *context, zsize index, zfloat64 value			     );
	typedef void (* ZHandleContextIndexFloat64AndData    )(void *context, zsize index, zfloat64 value, void *data		     );
	typedef void (* ZHandleFloat64AndStop		     )(				   zfloat64 value,	       zboolean *stop);
	typedef void (* ZHandleFloat64DataAndStop	     )(				   zfloat64 value, void *data, zboolean *stop);
	typedef void (* ZHandleIndexFloat64AndStop	     )(		      zsize index, zfloat64 value,	       zboolean *stop);
	typedef void (* ZHandleIndexFloat64DataAndStop	     )(		      zsize index, zfloat64 value, void *data, zboolean *stop);
	typedef void (* ZHandleContextFloat64AndStop	     )(void *context,		   zfloat64 value,	       zboolean *stop);
	typedef void (* ZHandleContextFloat64DataAndStop     )(void *context,		   zfloat64 value, void *data, zboolean *stop);
	typedef void (* ZHandleContextIndexFloat64AndStop    )(void *context, zsize index, zfloat64 value,	       zboolean *stop);
	typedef void (* ZHandleContextIndexFloat64DataAndStop)(void *context, zsize index, zfloat64 value, void *data, zboolean *stop);
#endif

#if Z_IS_AVAILABLE(FLOAT72)
	typedef void (* ZHandleFloat72			     )(				   zfloat72 value			     );
	typedef void (* ZHandleFloat72AndData		     )(				   zfloat72 value, void *data		     );
	typedef void (* ZHandleIndexAndFloat72		     )(		      zsize index, zfloat72 value			     );
	typedef void (* ZHandleIndexFloat72AndData	     )(		      zsize index, zfloat72 value, void *data		     );
	typedef void (* ZHandleContextAndFloat72	     )(void *context,		   zfloat72 value			     );
	typedef void (* ZHandleContextFloat72AndData	     )(void *context,		   zfloat72 value, void *data		     );
	typedef void (* ZHandleContextIndexAndFloat72	     )(void *context, zsize index, zfloat72 value			     );
	typedef void (* ZHandleContextIndexFloat72AndData    )(void *context, zsize index, zfloat72 value, void *data		     );
	typedef void (* ZHandleFloat72AndStop		     )(				   zfloat72 value,	       zboolean *stop);
	typedef void (* ZHandleFloat72DataAndStop	     )(				   zfloat72 value, void *data, zboolean *stop);
	typedef void (* ZHandleIndexFloat72AndStop	     )(		      zsize index, zfloat72 value,	       zboolean *stop);
	typedef void (* ZHandleIndexFloat72DataAndStop	     )(		      zsize index, zfloat72 value, void *data, zboolean *stop);
	typedef void (* ZHandleContextFloat72AndStop	     )(void *context,		   zfloat72 value,	       zboolean *stop);
	typedef void (* ZHandleContextFloat72DataAndStop     )(void *context,		   zfloat72 value, void *data, zboolean *stop);
	typedef void (* ZHandleContextIndexFloat72AndStop    )(void *context, zsize index, zfloat72 value,	       zboolean *stop);
	typedef void (* ZHandleContextIndexFloat72DataAndStop)(void *context, zsize index, zfloat72 value, void *data, zboolean *stop);
#endif

#if Z_IS_AVAILABLE(FLOAT80)
	typedef void (* ZHandleFloat80			     )(				   zfloat80 value			     );
	typedef void (* ZHandleFloat80AndData		     )(				   zfloat80 value, void *data		     );
	typedef void (* ZHandleIndexAndFloat80		     )(		      zsize index, zfloat80 value			     );
	typedef void (* ZHandleIndexFloat80AndData	     )(		      zsize index, zfloat80 value, void *data		     );
	typedef void (* ZHandleContextAndFloat80	     )(void *context,		   zfloat80 value			     );
	typedef void (* ZHandleContextFloat80AndData	     )(void *context,		   zfloat80 value, void *data		     );
	typedef void (* ZHandleContextIndexAndFloat80	     )(void *context, zsize index, zfloat80 value			     );
	typedef void (* ZHandleContextIndexFloat80AndData    )(void *context, zsize index, zfloat80 value, void *data		     );
	typedef void (* ZHandleFloat80AndStop		     )(				   zfloat80 value,	       zboolean *stop);
	typedef void (* ZHandleFloat80DataAndStop	     )(				   zfloat80 value, void *data, zboolean *stop);
	typedef void (* ZHandleIndexFloat80AndStop	     )(		      zsize index, zfloat80 value,	       zboolean *stop);
	typedef void (* ZHandleIndexFloat80DataAndStop	     )(		      zsize index, zfloat80 value, void *data, zboolean *stop);
	typedef void (* ZHandleContextFloat80AndStop	     )(void *context,		   zfloat80 value,	       zboolean *stop);
	typedef void (* ZHandleContextFloat80DataAndStop     )(void *context,		   zfloat80 value, void *data, zboolean *stop);
	typedef void (* ZHandleContextIndexFloat80AndStop    )(void *context, zsize index, zfloat80 value,	       zboolean *stop);
	typedef void (* ZHandleContextIndexFloat80DataAndStop)(void *context, zsize index, zfloat80 value, void *data, zboolean *stop);
#endif

#if Z_IS_AVAILABLE(FLOAT96)
	typedef void (* ZHandleFloat96			     )(				   zfloat96 value			     );
	typedef void (* ZHandleFloat96AndData		     )(				   zfloat96 value, void *data		     );
	typedef void (* ZHandleIndexAndFloat96		     )(		      zsize index, zfloat96 value			     );
	typedef void (* ZHandleIndexFloat96AndData	     )(		      zsize index, zfloat96 value, void *data		     );
	typedef void (* ZHandleContextAndFloat96	     )(void *context,		   zfloat96 value			     );
	typedef void (* ZHandleContextFloat96AndData	     )(void *context,		   zfloat96 value, void *data		     );
	typedef void (* ZHandleContextIndexAndFloat96	     )(void *context, zsize index, zfloat96 value			     );
	typedef void (* ZHandleContextIndexFloat96AndData    )(void *context, zsize index, zfloat96 value, void *data		     );
	typedef void (* ZHandleFloat96AndStop		     )(				   zfloat96 value,	       zboolean *stop);
	typedef void (* ZHandleFloat96DataAndStop	     )(				   zfloat96 value, void *data, zboolean *stop);
	typedef void (* ZHandleIndexFloat96AndStop	     )(		      zsize index, zfloat96 value,	       zboolean *stop);
	typedef void (* ZHandleIndexFloat96DataAndStop	     )(		      zsize index, zfloat96 value, void *data, zboolean *stop);
	typedef void (* ZHandleContextFloat96AndStop	     )(void *context,		   zfloat96 value,	       zboolean *stop);
	typedef void (* ZHandleContextFloat96DataAndStop     )(void *context,		   zfloat96 value, void *data, zboolean *stop);
	typedef void (* ZHandleContextIndexFloat96AndStop    )(void *context, zsize index, zfloat96 value,	       zboolean *stop);
	typedef void (* ZHandleContextIndexFloat96DataAndStop)(void *context, zsize index, zfloat96 value, void *data, zboolean *stop);
#endif

#if Z_IS_AVAILABLE(FLOAT128)
	typedef void (* ZHandleFloat128			      )(			    zfloat128 value			       );
	typedef void (* ZHandleFloat128AndData		      )(			    zfloat128 value, void *data		       );
	typedef void (* ZHandleIndexAndFloat128		      )(	       zsize index, zfloat128 value			       );
	typedef void (* ZHandleIndexFloat128AndData	      )(	       zsize index, zfloat128 value, void *data		       );
	typedef void (* ZHandleContextAndFloat128	      )(void *context,		    zfloat128 value			       );
	typedef void (* ZHandleContextFloat128AndData	      )(void *context,		    zfloat128 value, void *data		       );
	typedef void (* ZHandleContextIndexAndFloat128	      )(void *context, zsize index, zfloat128 value			       );
	typedef void (* ZHandleContextIndexFloat128AndData    )(void *context, zsize index, zfloat128 value, void *data		       );
	typedef void (* ZHandleFloat128AndStop		      )(			    zfloat128 value,		 zboolean *stop);
	typedef void (* ZHandleFloat128DataAndStop	      )(			    zfloat128 value, void *data, zboolean *stop);
	typedef void (* ZHandleIndexFloat128AndStop	      )(	       zsize index, zfloat128 value,		 zboolean *stop);
	typedef void (* ZHandleIndexFloat128DataAndStop	      )(	       zsize index, zfloat128 value, void *data, zboolean *stop);
	typedef void (* ZHandleContextFloat128AndStop	      )(void *context,		    zfloat128 value,		 zboolean *stop);
	typedef void (* ZHandleContextFloat128DataAndStop     )(void *context,		    zfloat128 value, void *data, zboolean *stop);
	typedef void (* ZHandleContextIndexFloat128AndStop    )(void *context, zsize index, zfloat128 value,		 zboolean *stop);
	typedef void (* ZHandleContextIndexFloat128DataAndStop)(void *context, zsize index, zfloat128 value, void *data, zboolean *stop);
#endif

typedef void (* ZHandlePointer			     )(				   void *pointer			    );
typedef void (* ZHandlePointerAndData		     )(				   void *pointer, void *data		    );
typedef void (* ZHandleIndexAndPointer		     )(		      zsize index, void *pointer			    );
typedef void (* ZHandleIndexPointerAndData	     )(		      zsize index, void *pointer, void *data		    );
typedef void (* ZHandleContextAndPointer	     )(void *context,		   void *pointer			    );
typedef void (* ZHandleContextPointerAndData	     )(void *context,		   void *pointer, void *data		    );
typedef void (* ZHandleContextIndexAndPointer	     )(void *context, zsize index, void *pointer			    );
typedef void (* ZHandleContextIndexPointerAndData    )(void *context, zsize index, void *pointer, void *data		    );
typedef void (* ZHandlePointerAndStop		     )(				   void *pointer,	      zboolean *stop);
typedef void (* ZHandlePointerDataAndStop	     )(				   void *pointer, void *data, zboolean *stop);
typedef void (* ZHandleIndexPointerAndStop	     )(		      zsize index, void *pointer,	      zboolean *stop);
typedef void (* ZHandleIndexPointerDataAndStop	     )(		      zsize index, void *pointer, void *data, zboolean *stop);
typedef void (* ZHandleContextPointerAndStop	     )(void *context,		   void *pointer,	      zboolean *stop);
typedef void (* ZHandleContextPointerDataAndStop     )(void *context,		   void *pointer, void *data, zboolean *stop);
typedef void (* ZHandleContextIndexPointerAndStop    )(void *context, zsize index, void *pointer,	      zboolean *stop);
typedef void (* ZHandleContextIndexPointerDataAndStop)(void *context, zsize index, void *pointer, void *data, zboolean *stop);

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

#endif /* __Z_types_handling_H__ */
