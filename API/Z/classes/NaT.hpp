/* Z Kit - classes/NaT.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//__/__| Kit
Copyright (C) 2006-2020 Manuel Sainz de Baranda y Goñi.
Copyright (C) 2018 Sofía Ortega Sosa.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_classes_NaT_HPP
#define Z_classes_NaT_HPP

#include <Z/macros/language.hpp>


namespace Zeta {struct NaT Z_FINAL {
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
};}


#endif // Z_classes_NaT_HPP
