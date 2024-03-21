/* Zeta API - Z/classes/Reference.hpp
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_classes_Reference_HPP
#define Z_classes_Reference_HPP

#include <Z/macros/language.hpp>


namespace Zeta {template <class t> struct Reference {
	typedef t type;

	t *value;


	Z_CT(CPP11) Reference(t &value_) Z_NOTHROW
	: value(&value_) {}


#	if Z_DIALECT_HAS(CPP11, DELETED_FUNCTION)
		Z_CT(CPP11) Reference(t &&value_) = delete;
#	endif


	Z_CT(CPP11) operator t &() const Z_NOTHROW
		{return *value;}


	Z_CT(CPP11) t &get() const Z_NOTHROW
		{return *value;}
};}


#endif // Z_classes_Span_HPP
