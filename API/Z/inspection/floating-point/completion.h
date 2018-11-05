/* Z Kit - inspection/floating-point/completion.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.

This library is  free software: you can redistribute it  and/or modify it under
the terms  of the GNU  Lesser General Public License  as published by  the Free
Software Foundation, either  version 3 of the License, or  (at your option) any
later version.

This library is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

You should have received  a copy of the GNU Lesser General Public License along
with this library. If not, see <http://www.gnu.org/licenses/>. */

#ifdef Z_FLOATING_POINT_TYPE_FLOAT16
#	define Z_FLOATING_POINT_HAS_TYPE_FLOAT16 TRUE
#else
#	define Z_FLOATING_POINT_HAS_TYPE_FLOAT16 FALSE
#endif

#ifdef Z_FLOATING_POINT_TYPE_FLOAT32
#	define Z_FLOATING_POINT_HAS_TYPE_FLOAT32 TRUE
#else
#	define Z_FLOATING_POINT_HAS_TYPE_FLOAT32 FALSE
#endif

#ifdef Z_FLOATING_POINT_TYPE_FLOAT64
#	define Z_FLOATING_POINT_HAS_TYPE_FLOAT64 TRUE
#else
#	define Z_FLOATING_POINT_HAS_TYPE_FLOAT64 FALSE
#endif

#ifdef Z_FLOATING_POINT_TYPE_FLOAT128
#	define Z_FLOATING_POINT_HAS_TYPE_FLOAT128 TRUE
#else
#	define Z_FLOATING_POINT_HAS_TYPE_FLOAT128 FALSE
#endif

#ifdef Z_FLOATING_POINT_TYPE_FLOAT80_X87
#	define Z_FLOATING_POINT_HAS_TYPE_FLOAT80_X87 TRUE
#else
#	define Z_FLOATING_POINT_HAS_TYPE_FLOAT80_X87 FALSE
#endif

#ifdef Z_FLOATING_POINT_TYPE_FLOAT96_X87
#	define Z_FLOATING_POINT_HAS_TYPE_FLOAT96_X87 TRUE
#else
#	define Z_FLOATING_POINT_HAS_TYPE_FLOAT96_X87 FALSE
#endif

#ifdef Z_FLOATING_POINT_TYPE_FLOAT128_X87
#	define Z_FLOATING_POINT_HAS_TYPE_FLOAT128_X87 TRUE
#else
#	define Z_FLOATING_POINT_HAS_TYPE_FLOAT128_X87 FALSE
#endif

/* inspection/floating-point/completion.h EOF */
