/* Q C API - macros/bits.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_macros_bits_H__
#define __Q_macros_bits_H__

#define Q_BIT(value, index)	     !!((value) & (1 << (index)))
#define Q_SET_BIT_TO_0(value, index) ((value) &= ~(1 << (index)))
#define Q_SET_BIT_TO_1(value, index) ((value) |=  (1 << (index)))
#define Q_SET_BIT(value, index, bit) ((value) = (bit) ? (value) | (1 << (index)) : (value) & ~(1 << (index)))
#define Q_BIT_MASK(index, size)	     ((~(~0 << size)) << index)

#endif /* __Q_macros_bits_H__ */
