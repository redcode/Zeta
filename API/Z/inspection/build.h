/* Z Kit - inspection/build.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_inspection_build_H_
#define _Z_inspection_build_H_

#ifdef Z_BUILD_TIME

#	define Z_BUILD_YEAR	(Z_BUILD_TIME		       / 10000000000)
#	define Z_BUILD_MONTH   ((Z_BUILD_TIME - ((Z_BUILD_TIME / 10000000000) * 10000000000)) / 100000000)
#	define Z_BUILD_DAY     ((Z_BUILD_TIME - ((Z_BUILD_TIME /   100000000) *	  100000000)) /   1000000)
#	define Z_BUILD_HOUR    ((Z_BUILD_TIME - ((Z_BUILD_TIME /     1000000) *	    1000000)) /     10000)
#	define Z_BUILD_MINUTES ((Z_BUILD_TIME - ((Z_BUILD_TIME /       10000) *	      10000)) /       100)
#	define Z_BUILD_SECONDS	(Z_BUILD_TIME - ((Z_BUILD_TIME /	 100) *		100))

#endif

#endif /* _Z_inspection_build_H_ */
