/* Zeta API - Z/classes/Strid.hpp
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_classes_Strid_HPP
#define Z_classes_Strid_HPP

#include <Z/functions/hash.hpp>


namespace Zeta {struct Strid {
	UInt64 hash;


	Z_INLINE Strid() Z_NOTHROW
		Z_DEFAULTED({})


	Z_CT(CPP11) Strid(UInt64 hash_) Z_NOTHROW
	: hash(hash_) {}


	Z_CT(CPP14) Strid(const Char *string) Z_NOTHROW
	: hash(fnv1a_64(string)) {}


	Z_CT(CPP11) operator UInt64() const Z_NOTHROW
		{return hash;}


	friend Z_CT(CPP11) Boolean operator ==(const Strid &lhs, const Strid &rhs) Z_NOTHROW
		{return lhs.hash == rhs.hash;}


	friend Z_CT(CPP11) Boolean operator ==(const Strid &lhs, UInt64 rhs) Z_NOTHROW
		{return lhs.hash == rhs;}


	friend Z_CT(CPP11) Boolean operator ==(UInt64 lhs, const Strid &rhs) Z_NOTHROW
		{return lhs == rhs.hash;}


	friend Z_CT(CPP11) Boolean operator !=(const Strid &lhs, const Strid &rhs) Z_NOTHROW
		{return lhs.hash != rhs.hash;}


	friend Z_CT(CPP11) Boolean operator !=(const Strid &lhs, UInt64 rhs) Z_NOTHROW
		{return lhs.hash != rhs;}


	friend Z_CT(CPP11) Boolean operator !=(UInt64 lhs, const Strid &rhs) Z_NOTHROW
		{return lhs != rhs.hash;}
};}


#endif // Z_classes_Strid_HPP
