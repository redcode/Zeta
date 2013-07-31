/* Q API - types/input.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2012 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_types_input_H__
#define __Q_types_input_H__

#include <Q/types/mathematics.h>

typedef struct {
	Q2D point;
	Q2D delta;
} QPointerInput;

typedef struct {
} QKeyboardInput;

typedef struct {
} QTabletInput;

#endif /* __Q_types_input_H__ */
