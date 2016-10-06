/* Z Kit C++ API - classes/base/InitializerList.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_classes_base_InitializerList_HPP__
#define __Z_classes_base_InitializerList_HPP__

#include <Z/types/base.hpp>

namespace Zeta {template <class T> struct Shared;}


template <class T> class Zeta::InitializerList {
	private:
	const T* _begin;
	Size	 _size;

	public:
	Z_INLINE_MEMBER Size	 size () const {return _size;}
	Z_INLINE_MEMBER const T *begin() const {return _begin;}
	Z_INLINE_MEMBER const T *end  () const {return _begin + _size;} 
};

template<class _Ep>
class _LIBCPP_TYPE_VIS_ONLY initializer_list
{
    const _Ep* __begin_;
    size_t    __size_;

    _LIBCPP_ALWAYS_INLINE
    _LIBCPP_CONSTEXPR_AFTER_CXX11
    initializer_list(const _Ep* __b, size_t __s) _NOEXCEPT
        : __begin_(__b),
          __size_(__s)
        {}
public:
    typedef _Ep        value_type;
    typedef const _Ep& reference;
    typedef const _Ep& const_reference;
    typedef size_t    size_type;

    typedef const _Ep* iterator;
    typedef const _Ep* const_iterator;

    _LIBCPP_ALWAYS_INLINE
    _LIBCPP_CONSTEXPR_AFTER_CXX11
    initializer_list() _NOEXCEPT : __begin_(nullptr), __size_(0) {}

    _LIBCPP_ALWAYS_INLINE
    _LIBCPP_CONSTEXPR_AFTER_CXX11
    size_t    size()  const _NOEXCEPT {return __size_;}
    
    _LIBCPP_ALWAYS_INLINE
    _LIBCPP_CONSTEXPR_AFTER_CXX11
    const _Ep* begin() const _NOEXCEPT {return __begin_;}

    _LIBCPP_ALWAYS_INLINE
    _LIBCPP_CONSTEXPR_AFTER_CXX11
    const _Ep* end()   const _NOEXCEPT {return __begin_ + __size_;}
};

#endif // __Z_classes_base_InitializerList_HPP__
