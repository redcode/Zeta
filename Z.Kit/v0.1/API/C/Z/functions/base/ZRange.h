/* Z Kit C API - functions/base/ZRange.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_functions_base_ZRange_H__
#define __Z_functions_base_ZRange_H__

#include <Z/functions/base/constructors.h>
#include <Z/functions/base/value.h>


Z_INLINE zboolean z_range_are_equal(ZRange a, ZRange b)
	{return a.index == b.index && a.size == b.size;}


Z_INLINE void z_range_swap(ZRange *a, ZRange *b)
	{
	ZRange t = *a;

	*a = *b; *b = t;
	}


Z_INLINE zboolean z_range_contains(ZRange a, ZRange b)
	{return a.index <= b.index && a.index + a.size >= b.index + b.size;}


Z_INLINE zboolean z_range_collide(ZRange a, ZRange b)
	{return a.index < b.index + b.size && b.index < a.index + a.size;}


Z_INLINE ZRange z_range_intersection(ZRange a, ZRange b)
	{
	zsize index   = (a.index > b.index) ? a.index : b.index;
	zsize minimum = z_value_minimum(SIZE)(a.index + a.size, b.index + b.size);

	return minimum > index ? z_range(index, minimum - index) : z_range_zero;
	}


Z_INLINE ZRange z_range_union(ZRange a, ZRange b)
	{
	zsize	index	  = (a.index < b.index) ? a.index : b.index,
		a_maximum = a.index + a.size,
		b_maximum = b.index + b.size;

	return z_range(index, ((a_maximum > b_maximum) ? a_maximum : b_maximum) - index);
	}


Z_INLINE ZRange z_range_from_indices(zsize a, zsize b)
	{return a < b ? z_range(a, b - a) : z_range(b, a - b);}


Z_INLINE zboolean z_range_is_zero(ZRange object)
	{return object.index == 0 && object.size == 0;}


Z_INLINE zsize z_range_end(ZRange object)
	{return object.index + object.size;}


Z_INLINE zboolean z_range_contains_index(ZRange object, zsize index)
	{return index >= object.index && index < object.index + object.size;}


#endif /* __Z_functions_base_ZRange_H__ */
