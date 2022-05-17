/* Zeta API - Z/classes/StringView.hpp
 ______ ____________  ___
|__   /|  ___|__  __|/   \
  /  /_|  __|  |  | /  *  \
 /_____|_____| |__|/__/ \__\
Copyright (C) 2006-2022 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_classes_StringView_HPP
#define Z_classes_StringView_HPP

#include <Z/constants/pointer.h>
#include <Z/macros/language.hpp>
#include <Z/types/integral.hpp>
#include <Z/classes/Iterator.hpp>


namespace Zeta {template <class t> struct StringView {
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


	Z_CT(CPP11) const t &operator [](USize index) const Z_NOTHROW
		{return data[index];}


/*	Z_CT(CPP11) iterator begin() const Z_NOTHROW
		{}


	Z_CT(CPP11) iterator end() const Z_NOTHROW
		{}*/
};}


#endif // Z_classes_StringView_HPP
