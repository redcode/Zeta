/* Q C API - inspection/C.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_inspection_C_H__
#define __Q_inspection_C_H__

#if defined(Q_USE_C11)
#	include <Q/inspection/private/C/C11.h>

#elif defined(Q_USE_C99)
#	include <Q/inspection/private/C/C99.h>

#elif defined(Q_USE_C94)
#	include <Q/inspection/private/C/C94.h>

#elif defined(Q_USE_C90)
#	include <Q/inspection/private/C/C90.h>

#elif defined(Q_USE_C89)
#	include <Q/inspection/private/C/C89.h>

#elif defined(__STDC__)
#	if defined(__STDC_VERSION__)

#		if __STDC_VERSION__ >= 201112L
#			include <Q/inspection/private/C/C11.h>

#		elif __STDC_VERSION__ >= 199901L
#			include <Q/inspection/private/C/C99.h>

#		elif __STDC_VERSION__ >= 199409L
#			include <Q/inspection/private/C/C94.h>

#		else
#			include <Q/inspection/private/C/C90.h>
#		endif
#	else
#		include <Q/inspection/private/C/C89.h>
#	endif
#else
#	include <Q/inspection/private/C/C89.h>
#endif

#define Q_C_HAS(WHAT) ((defined Q_C_HAS_##WHAT) || (defined Q_COMPILER_C_HAS_##WHAT))

#endif /* __Q_inspection_C_H__ */
