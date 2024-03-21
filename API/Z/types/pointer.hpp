/* Zeta API - Z/types/pointer.hpp
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_types_pointer_HPP
#define Z_types_pointer_HPP

#include <Z/inspection/language.h>

#if	Z_DIALECT_HAS_SPECIFIER(CPP11, DECLTYPE) && \
	Z_DIALECT_HAS_LITERAL  (CPP11, NULLPTR )

	namespace Zeta {
		typedef decltype(nullptr) NullPtr;
#		define Z_NULLPTR	  Z_SAME
	}
#endif

#endif // Z_types_pointer_HPP
