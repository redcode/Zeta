/* Zeta API - Z/classes/StringView.hpp
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_classes_StringView_HPP
#define Z_classes_StringView_HPP

#include <Z/constants/pointer.h>
#include <Z/macros/language.hpp>
#include <Z/types/integral.hpp>
#include <Z/classes/Iterator.hpp>

#ifdef Z_WITH_STDCPP
#	include <cstring>
#endif

namespace Zeta {template <class t = Char> struct StringView {
//	typedef Iterator<t*> const_iterator;
//	typedef Iterator<t*> const_reverse_iterator;
	typedef const t*     const_pointer;
	typedef const t&     const_reference;
	typedef PtrDiff	     difference_type;
//	typedef Iterator<t*> iterator;
	typedef t*	     pointer;
	typedef t&	     reference;
//	typedef Iterator<t*> reverse_iterator;
	typedef USize	     size_type;
	typedef t	     value_type;

	const t* data;
	USize	 size;


	Z_CT(CPP11) StringView() Z_NOTHROW
	: data(Z_NULL), size(0) {}


	Z_CT(CPP11) StringView(const t *data_, USize size_) Z_NOTHROW
	: data(data_), size(size_) {}


	template <USize s>
	Z_CT(CPP11) StringView(const t (&data_)[s]) Z_NOTHROW
	: data(data_), size(s - 1) {}


	Z_CT(CPP11) const t &operator [](USize index) const Z_NOTHROW
		{return data[index];}


/*	Z_CT(CPP11) iterator begin() const Z_NOTHROW
		{}


	Z_CT(CPP11) iterator end() const Z_NOTHROW
		{}*/


#	ifdef Z_WITH_STDCPP

		friend Z_INLINE Boolean operator ==(const StringView &lhs, const StringView &rhs) Z_NOTHROW
			{return lhs.size == rhs.size && !std::memcmp(lhs.data, rhs.data, lhs.size * sizeof(t));}


		friend Z_INLINE Boolean operator !=(const StringView &lhs, const StringView &rhs) Z_NOTHROW
			{return lhs.size != rhs.size || std::memcmp(lhs.data, rhs.data, lhs.size * sizeof(t));}


		template <USize s>
		friend Z_INLINE Boolean operator ==(const StringView &lhs, const t (&rhs)[s]) Z_NOTHROW
			{return lhs.size == (s - 1) && !std::memcmp(lhs.data, rhs, (s - 1) * sizeof(t));}


		template <USize s>
		friend Z_INLINE Boolean operator !=(const StringView &lhs, const t (&rhs)[s]) Z_NOTHROW
			{return lhs.size != (s - 1) || std::memcmp(lhs.data, rhs, (s - 1) * sizeof(t));}


		friend Z_INLINE Boolean operator ==(const StringView &lhs, const t *rhs) Z_NOTHROW
			{return	lhs.size * sizeof(t) == std::strlen(rhs) && !std::memcmp(lhs.data, rhs, lhs.size * sizeof(t));}


		friend Z_INLINE Boolean operator !=(const StringView &lhs, const t *rhs) Z_NOTHROW
			{return lhs.size * sizeof(t) != std::strlen(rhs) || std::memcmp(lhs.data, rhs, lhs.size * sizeof(t));}


		template <USize s>
		friend Z_INLINE Boolean operator ==(const t (&lhs)[s], const StringView &rhs) Z_NOTHROW
			{return rhs.size == (s - 1) && !std::memcmp(rhs.data, lhs, (s - 1) * sizeof(t));}


		template <USize s>
		friend Z_INLINE Boolean operator !=(const t (&lhs)[s], const StringView &rhs) Z_NOTHROW
			{return rhs.size != (s - 1) || std::memcmp(rhs.data, lhs, (s - 1) * sizeof(t));}


		friend Z_INLINE Boolean operator ==(const t *lhs, const StringView &rhs) Z_NOTHROW
			{return	rhs.size * sizeof(t) == std::strlen(lhs) && !std::memcmp(rhs.data, lhs, rhs.size * sizeof(t));}


		friend Z_INLINE Boolean operator !=(const t *lhs, const StringView &rhs) Z_NOTHROW
			{return rhs.size * sizeof(t) != std::strlen(lhs) || std::memcmp(rhs.data, lhs, rhs.size * sizeof(t));}

#	endif
};}


#endif // Z_classes_StringView_HPP
