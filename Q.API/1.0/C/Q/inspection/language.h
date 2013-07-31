/* Q API - inspection/language.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2010-2013 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v2. */

#ifndef __Q_inspection_language_H__
#define __Q_inspection_language_H__

#if defined(__STDC__)
#	if defined(__STDC_VERSION__)

#		if   __STDC_VERSION__ >= 201112L
#			define Q_C_NAME			C11
#		elif __STDC_VERSION__ >= 199901L
#			define Q_C_NAME			C99
#		elif __STDC_VERSION__ >= 199409L
#			define Q_C_NAME			C94
#		else
#			define Q_C_NAME			C90
#		endif
#	else
#		define Q_C_NAME				C89
#	endif
#else
#	define Q_C_NAME					K&R
#endif

#define Q_C_HAS(what) defined(Q_C_HAS_##what)

#define Q_LANGUAGE_HEADER <Q/inspection/private/language/Q_C_NAME.h>
#include Q_LANGUAGE_HEADER

#endif /* __Q_inspection_language_H__ */
