/* Z Kit - types/pointer.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2019 Manuel Sainz de Baranda y Goñi.
Copyright (C) 2018 Sofía Ortega Sosa.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_types_pointer_HPP
#define Z_types_pointer_HPP

#include <Z/inspection/language.h>

namespace Zeta {

#	if	Z_DIALECT_HAS_SPECIFIER(CPP, DECLTYPE) && \
		Z_DIALECT_HAS_LITERAL  (CPP, NULLPTR )

		typedef decltype(nullptr) NullPointer;
#		define Z_NULL_POINTER
#	endif

};

#endif // Z_types_pointer_HPP
