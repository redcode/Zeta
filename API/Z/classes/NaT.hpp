/* Zeta API - Z/classes/NaT.hpp
 ______ ____________  ___
|__   /|  ___|__  __|/   \
  /  /_|  __|  |  | /  *  \
 /_____|_____| |__|/__/ \__\
Copyright (C) 2006-2022 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_classes_NaT_HPP
#define Z_classes_NaT_HPP

#include <Z/macros/language.hpp>


namespace Zeta {struct NaT Z_FINAL {
#	if Z_DIALECT_HAS(CPP11, DELETED_FUNCTION)
		NaT()			     = delete;
		NaT(const NaT &)	     = delete;
		~NaT()			     = delete;
		NaT &operator =(const NaT &) = delete;

#		if Z_DIALECT_HAS(CPP11, RVALUE_REFERENCE)
			NaT(NaT &&)		= delete;
			NaT &operator =(NaT &&) = delete;
#		endif
#	endif
};}


#endif // Z_classes_NaT_HPP
