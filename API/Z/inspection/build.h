/* Z Kit - inspection/build.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.

This library is free software: you can redistribute it and/or modify it
under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this library.  If not, see <http://www.gnu.org/licenses/>. */

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
