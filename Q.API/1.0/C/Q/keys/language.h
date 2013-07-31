/* Q API - keys/language.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2012 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_keys_language_H__
#define __Q_keys_language_H__

#pragma mark - C

#define Q_C_KR		0
#define Q_C89		1
#define Q_C90		2
#define Q_C94		3
#define Q_C99		4
#define Q_C11		5

#define Q_STRING_C_KR	"K&R C"
#define Q_STRING_C89	"ANSI X3.159-1989 (C89)"
#define Q_STRING_C90	"ISO/IEC 9899:1990 (C90)"
#define Q_STRING_C94	"ISO/IEC 9899-1:1994 (C94)"
#define Q_STRING_C99	"ISO/IEC 9899:1999 (99)"
#define Q_STRING_C11	"ISO/IEC 9899:2011 (C11)"

#pragma mark - C++

#define Q_CPP98		1
#define Q_CPP03		2
#define Q_CPPTR1	3
#define Q_CPP11		4

#define Q_STRING_CPP98	"ISO/IEC 14882:1998 (C++98)"
#define Q_STRING_CPP03	"ISO/IEC 14882:2003 (C++03)"
#define Q_STRING_CPPTR1	"ISO/IEC TR 19768:2007 (C++TR1)"
#define Q_STRING_CPP11	"ISO/IEC 14882:2011 (C++11)"

#endif /* __Q_keys_language_H__ */
