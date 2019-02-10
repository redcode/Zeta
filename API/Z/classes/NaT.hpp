/* Z Kit - classes/NaT.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2019 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_classes_NaT_HPP_
#define Z_classes_NaT_HPP_

#include <Z/inspection/language.h>


namespace Zeta {struct NaT {
#	if Z_DIALECT_HAS(CPP, DELETED_FUNCTION)
		NaT()			     = delete;
		NaT(const NaT &)	     = delete;
		~NaT()			     = delete;
		NaT &operator =(const NaT &) = delete;

#		if Z_DIALECT_HAS(CPP, RVALUE_REFERENCE)
			NaT(NaT &&)	       = delete;
			NaT &operator =(NaT &) = delete;
#		endif
#	endif
	};
}


#endif // Z_classes_NaT_HPP_
