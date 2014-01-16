/* Q API - functions/base/QRange.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2014 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_functions_base_QRange_H__
#define __Q_functions_base_QRange_H__

#include <Q/functions/value.h>

#if Q_C_HAS(COMPOUND_LITERAL)
#	define q_range(index, size) ((QRange){index, size})
#else
	Q_INLINE QRange q_range(qsize index, qsize size)
		{QRange range = {index, size}; return range;}
#endif

#define q_range_zero q_range(0, 0)


Q_INLINE
qboolean q_range_are_equal(QRange a, QRange b)
	{return a.index == b.index && a.size == b.size;}


Q_INLINE
void q_range_swap(QRange *a, QRange *b)
	{
	QRange t = *a;

	*a = *b; *b = t;
	}


Q_INLINE
qboolean q_range_contains(QRange a, QRange b)
	{return b.index >= a.index && b.index + b.size <= a.index + a.size;}


Q_INLINE
qboolean q_range_collision(QRange a, QRange b)
	{return a.index < b.index + b.size && b.index < a.index + a.size;}


Q_INLINE
QRange q_range_intersection(QRange a, QRange b)
	{
	qsize	minimum = q_size_minimum(a.index + a.size, b.index + b.size),
		index	= (a.index > b.index) ? a.index : b.index;

	return minimum <= index ? q_range_zero : q_range(index, minimum - index);
	}


Q_INLINE
QRange q_range_union(QRange a, QRange b)
	{
	qsize	a_maximum = a.index + a.size,
		b_maximum = b.index + b.size,
		index	  = (a.index < b.index) ? a.index : b.index;

	return q_range
		(index,
		 ((a_maximum > b_maximum) ? a_maximum : b_maximum) - index);
	}


Q_INLINE
QRange q_range_from_indices(qsize a, qsize b)
	{return a < b ? q_range(a, b - a) : q_range(b, a - b);}


Q_INLINE
qboolean q_range_is_zero(QRange range)
	{return range.index == 0 && range.size == 0;}


Q_INLINE
qsize q_range_end(QRange range)
	{return range.index + range.size;}


Q_INLINE
qboolean q_range_contains_index(QRange range, qsize index)
	{return index >= range.index && index < range.index + range.size;}


#endif /* __Q_functions_base_QRange_H__ */