/* Q API - types/context.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2012 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_types_context_H__
#define __Q_types_context_H__

#include <Q/types/basics.h>

#pragma mark - General pourpose context access function types

typedef void	(* QDo)				(void* context);
typedef void	(* QSwitch)			(void* context, qboolean state);

typedef quint8	(* Q16BitAddressRead8Bit )	(void* context, quint16 address);
typedef quint16	(* Q16BitAddressRead16Bit)	(void* context, quint16 address);
typedef quint32 (* Q16BitAddressRead32Bit)	(void* context, quint16 address);
typedef quint64 (* Q16BitAddressRead64Bit)	(void* context, quint16 address);

typedef void	(* Q16BitAddressWrite8Bit )	(void* context, quint16 address, quint8  value);
typedef void	(* Q16BitAddressWrite16Bit)	(void* context, quint16 address, quint16 value);
typedef void	(* Q16BitAddressWrite32Bit)	(void* context, quint16 address, quint32 value);
typedef void	(* Q16BitAddressWrite64Bit)	(void* context, quint16 address, quint64 value);

typedef quint8	(* Q32BitAddressRead8Bit )	(void* context, quint32 address);
typedef quint16	(* Q32BitAddressRead16Bit)	(void* context, quint32 address);
typedef quint32 (* Q32BitAddressRead32Bit)	(void* context, quint32 address);
typedef quint64 (* Q32BitAddressRead64Bit)	(void* context, quint32 address);

typedef void	(* Q32BitAddressWrite8Bit )	(void* context, quint32 address, quint8  value);
typedef void	(* Q32BitAddressWrite16Bit)	(void* context, quint32 address, quint16 value);
typedef void	(* Q32BitAddressWrite32Bit)	(void* context, quint32 address, quint32 value);
typedef void	(* Q32BitAddressWrite64Bit)	(void* context, quint32 address, quint64 value);

typedef quint8	(* Q64BitAddressRead8Bit )	(void* context, quint32 address);
typedef quint16	(* Q64BitAddressRead16Bit)	(void* context, quint32 address);
typedef quint32 (* Q64BitAddressRead32Bit)	(void* context, quint32 address);
typedef quint64 (* Q64BitAddressRead64Bit)	(void* context, quint32 address);

typedef void	(* Q64BitAddressWrite8Bit )	(void* context, quint32 index, quint8  value);
typedef void	(* Q64BitAddressWrite16Bit)	(void* context, quint32 index, quint16 value);
typedef void	(* Q64BitAddressWrite32Bit)	(void* context, quint32 index, quint32 value);
typedef void	(* Q64BitAddressWrite64Bit)	(void* context, quint32 index, quint64 value);

typedef quint8	(* QRead8Bit )		(void* context);
typedef quint16	(* QRead16Bit)		(void* context);
typedef quint32	(* QRead32Bit)		(void* context);
typedef quint64	(* QRead64Bit)		(void* context);

typedef void	(* QWrite8Bit )		(void* context, quint8	value);
typedef void	(* QWrite16Bit)		(void* context, quint16 value);
typedef void	(* QWrite32Bit)		(void* context, quint32 value);
typedef void	(* QWrite64Bit)		(void* context, quint64 value);

#pragma mark - General pourpose function types

typedef void		(* QCopy)			(void*	context,
							 void*	output);
	
typedef void		(* QCopyData)			(void*	context,
							 qsize	data_size,
							 void*	output);

typedef qsize		(* QCopyAndSize)		(void*	context,
							 void*	output);

typedef qsize		(* QCopyDataAndSize)		(void*	context,
							 qsize	data_size,
							 void*	output);

typedef void		(* QCopyRange)			(void*	context,
							 QRange	range,
							 void*	output);

typedef void		(* QCopyRangeData)		(void*	context,
							 QRange	range,
							 qsize	data_size,
							 void*	output);

typedef void		(* QBoundedCopy)		(void*	context_start,
							 void*	context_end,
							 void*	output);

typedef void		(* QBoundedCopyData)		(void*	context_start,
							 void*	context_end,
							 qsize	data_size,
							 void*	output);

typedef qsize		(* QBoundedCopyAndSize)		(void*	context_start,
							 void*	context_end,
							 void*	output);

typedef qsize		(* QBoundedCopyDataAndSize)	(void*	context_start,
							 void*	context_end,
							 qsize	data_size,
							 void*	output);

typedef void		(* QBoundedCopyRange)		(void*	context_start,
							 void*	context_end,
							 void*	context_size,
							 QRange	range,
							 void*	output);

typedef void		(* QBoundedCopyRangeData)	(void*	context_start,
							 void*	context_end,
							 void*	context_size,
							 QRange	range,
							 qsize	data_size,
							 void*	output);

typedef void		(* QCopyMany)			(void*	context,
							 quint	count,
							 void*	output);

typedef void		(* QSkipOne)			(void*	input);

typedef void		(* QSkipMany)			(void*	input,
							 quint	count);

typedef void		(* QSwapHalves)			(void*	context);

typedef qsize		(* QSize)			(void*	context);

typedef void*		(* QElement)			(void*	context,
							 qsize	index);

typedef void		(* QSetElement)			(void*	context,
							 qsize	index,
							 void*	value);

typedef void		(* QMoveElement)		(void*	context,
							 qsize	old_index,
							 qsize	new_index);

typedef qint		(* QCompareElements)		(void*	context,
							 qsize	a_index,
							 qsize	b_index);

typedef void		(* QSwapElements)		(void*	context,
							 qsize	a_index,
							 qsize	b_index);

typedef qboolean	(* QIsValid)			(void*	context);

typedef qboolean	(* QAreEqual)			(void*	a,
							 void*	b);

typedef qboolean	(* QAreEqualWithData)		(void*	a,
							 void*	b,
							 void*	data);

typedef qint		(* QCompare)			(void*	a,
							 void*	b);

typedef qint		(* QCompareWithData)		(void*	a,
							 void*	b,
							 void*	data);

typedef void		(* QSwap)			(void*	a,
							 void*	b);

#endif /* __Q_types_context_H__ */
