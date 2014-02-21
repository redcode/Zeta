/* Q API - inspection/C.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2014 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_inspection_C_H__
#define __Q_inspection_C_H__

#include <Q/inspection/compiler.h>

#if defined(Q_COMPILER_C) && defined(Q_COMPILER_C_FILE)

#	define Q_C	Q_COMPILER_C
#	define Q_C_FILE	Q_COMPILER_C_FILE

#else

#	if defined(__STDC__)
#		if defined(__STDC_VERSION__)
#			if   __STDC_VERSION__ >= 201112L
#				define Q_C_FILE C11
#			elif __STDC_VERSION__ >= 199901L
#				define Q_C_FILE C99
#			elif __STDC_VERSION__ >= 199409L
#				define Q_C_FILE C94
#			else
#				define Q_C_FILE C90
#			endif
#		else
#			define Q_C_FILE C89
#		endif
#	else
#		define Q_C_FILE C89 /* KR */
#	endif

#endif

#define Q_C_HEADER <Q/inspection/private/C/Q_C_FILE.h>
#include Q_C_HEADER

#define Q_C_HAS(WHAT) (Q_JOIN_2_DEFINED(Q_C_HAS_,	   WHAT) || \
		       Q_JOIN_2_DEFINED(Q_COMPILER_C_HAS_, WHAT))

#endif /* __Q_inspection_C_H__ */
