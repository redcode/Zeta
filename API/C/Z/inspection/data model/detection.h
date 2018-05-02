/* Z Kit - inspection/data model/detection.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

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
