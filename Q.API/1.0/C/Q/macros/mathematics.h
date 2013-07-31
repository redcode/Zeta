/* Q API - macros/mathematics.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2013 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_macros_mathematics_H__
#define __Q_macros_mathematics_H__

#define Q_NEXT_MULTIPLE(    number, base) ((number) + (base) - ((number) % (base)))
#define Q_PREVIOUS_MULTIPLE(number, base) ((((number) - 1) / (base)) * (base))

#endif /* __Q_macros_mathematics_H__ */
