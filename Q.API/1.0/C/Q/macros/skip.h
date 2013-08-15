/* Q API - macros/skip.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2013 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_macros_skip_H__
#define __Q_macros_skip_H__

#define Q_SKIP(	   criteria, pointer) while ( Q_IS_##criteria(*pointer)) pointer++
#define Q_SKIP_NON(criteria, pointer) while (!Q_IS_##criteria(*pointer)) pointer++

#endif /* __Q_macros_skip_H__ */
