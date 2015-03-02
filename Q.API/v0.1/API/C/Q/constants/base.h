/* Q API - constants/base.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_constants_base_H__
#define __Q_constants_base_H__

#ifndef NULL
#	ifdef __cplusplus
#		define NULL 0
#	else
#		define NULL ((void *)0)
#	endif
#endif

#ifndef NIL
#	define NIL 0
#endif

#ifndef TRUE
#	define TRUE 1
#endif

#ifndef FALSE
#	define FALSE 0
#endif

#ifndef ON
#	define ON 1
#endif

#ifndef OFF
#	define OFF 0
#endif

#endif /* __Q_constants_base_H__ */
