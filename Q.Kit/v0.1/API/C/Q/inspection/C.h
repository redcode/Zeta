/* Q Kit API - inspection/C.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_inspection_C_H__
#define __Q_inspection_C_H__

#include <Q/inspection/compiler.h>

#if defined(Q_COMPILER_C)

#	include <Q/macros/preprocessor.h>
#	define  Q_C Q_COMPILER_C

#	if  defined(Q_COMPILER_C_FILE)
#		include	Q_HEADER(Q_COMPILER_C_FILE)
#	elif defined(Q_COMPILER_LOCAL_C_FILE)
#		include Q_LOCAL_HEADER(Q_COMPILER_LOCAL_C_FILE)
#	endif

#else

#	if defined(__STDC__)
#		if defined(__STDC_VERSION__)
#			if   __STDC_VERSION__ >= 201112L
#				include <Q/inspection/private/C/C11.h>
#			elif __STDC_VERSION__ >= 199901L
#				include <Q/inspection/private/C/C99.h>
#			elif __STDC_VERSION__ >= 199409L
#				include <Q/inspection/private/C/C94.h>
#			else
#				include <Q/inspection/private/C/C90.h>
#			endif
#		else
#			include <Q/inspection/private/C/C89.h>
#		endif
#	else
#		include <Q/inspection/private/C/C89.h> /* KR */
#	endif

#endif

#define Q_C_HAS(WHAT) ((defined Q_C_HAS_##WHAT) || (defined Q_COMPILER_C_HAS_##WHAT))

#endif /* __Q_inspection_C_H__ */
