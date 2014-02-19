/* Q API - constants/base.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2014 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_constants_base_H__
#define __Q_constants_base_H__

#ifndef NULL
#	define NULL	 ((void *)0)
#endif

#ifndef NIL
#	define NIL	 0
#endif

#ifndef TRUE
#	define TRUE	 1
#endif

#ifndef FALSE
#	define FALSE	 0
#endif

#ifndef ON
#	define ON	 1
#endif

#ifndef OFF
#	define OFF	 0
#endif

#ifndef POSITIVE
#	define POSITIVE	 1
#endif

#ifndef NEGATIVE
#	define NEGATIVE	-1
#endif

#ifndef CONTINUE
#	define CONTINUE	 0
#endif

#ifndef BREAK
#	define BREAK	 1
#endif

#ifndef REQUIRED
#	define REQUIRED	 1
#endif

#ifndef OPTIONAL
#	define OPTIONAL	 0
#endif

#ifndef NAN
#	define NAN	 (0.0 / 0.0)
#endif

#ifndef INFINITY
#	define INFINITY	 (1.0 / 0.0)
#endif

#endif /* __Q_constants_base_H__ */
