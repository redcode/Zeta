/* Z Kit - inspection/modules/OS/Linux.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
-------------------------------------------------------------------------------
This library is  free software: you can redistribute it  and/or modify it under
the terms  of the GNU  Lesser General Public License  as published by  the Free
Software Foundation, either  version 3 of the License, or  (at your option) any
later version.

This library is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

You should have received  a copy of the GNU Lesser General Public License along
with this library. If not, see <http://www.gnu.org/licenses/>.
---------------------------------------------------------------------------- */

#ifndef _Z_inspection_modules_OS_Linux_H_
#define _Z_inspection_modules_OS_Linux_H_

#define Z_OS_STRING Z_OS_STRING_LINUX

#define Z_OS_HAS_POSIX_THREADING TRUE
#define Z_OS_HAS_NETWORKING	 TRUE
#define Z_OS_HAS_TLS		 TRUE
#define Z_OS_IS_POSIX_LIKE	 TRUE
#define Z_OS_IS_UNIX_LIKE	 TRUE

#define Z_OS_PATH_SLASH_CHARACTER '/'
#define Z_OS_PATH_SLASH_STRING	  "/"

#endif /* _Z_inspection_modules_OS_Linux_H_ */
