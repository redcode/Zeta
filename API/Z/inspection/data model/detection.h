/* Z Kit - inspection/data model/detection.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.

This library  is free software: you  can redistribute it and/or  modify it under
the terms  of the  GNU Lesser General  Public License as  published by  the Free
Software Foundation,  either version 3 of  the License, or (at  your option) any
later version.

This library is distributed in the hope  that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty  of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

You should have received  a copy of the GNU Lesser  General Public License along
with this library. If not, see <http://www.gnu.org/licenses/>. */

#if	defined(__ILP32__) || /* Clang, GCC		    */ \
	defined(__ILP32	 ) ||				       \
	defined(_ILP32_	 ) ||				       \
	defined(_ILP32	 )    /* Clang, HP aC++, Sun Studio */

#	define Z_DATA_MODEL Z_DATA_MODEL_ILP32

#elif	defined(__ILP64__) || \
	defined(__ILP64	 ) || \
	defined(_ILP64_	 ) || \
	defined(_ILP64	 )

#	define Z_DATA_MODEL Z_DATA_MODEL_ILP64

#elif	defined(__LLP64__) || \
	defined(__LLP64	 ) || \
	defined(_LLP64_	 ) || \
	defined(_LLP64	 )

#	define Z_DATA_MODEL Z_DATA_MODEL_LLP64

#elif	defined(__LP32__) || /* Clang */ \
	defined(__LP32	) ||		 \
	defined(_LP32_	) ||		 \
	defined(_LP32	)

#	define Z_DATA_MODEL Z_DATA_MODEL_LP32

#elif	defined(__LP64__) || /* Clang, GCC		   */ \
	defined(__LP64	) ||				      \
	defined(_LP64_	) ||				      \
	defined(_LP64	)    /* Clang, HP aC++, Sun Studio */ \

#	define Z_DATA_MODEL Z_DATA_MODEL_LP64

#endif

/* inspection/data model/detection.h EOF */
