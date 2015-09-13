/* Z Kit C++ API - macros/templating.hpp
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_macros_templating_HPP__
#define __Z_macros_templating_HPP__

#define ZTypeSelectorNatural(container, selector)					       \
namespace TypeSelectors {								       \
	template <typename T> struct container{};					       \
	template <> struct container<unsigned char	   > {typedef selector(UCHAR ) type;}; \
	template <> struct container<unsigned short int	   > {typedef selector(USHORT) type;}; \
	template <> struct container<unsigned int	   > {typedef selector(UINT  ) type;}; \
	template <> struct container<unsigned long int	   > {typedef selector(ULONG ) type;}; \
	template <> struct container<unsigned long long int> {typedef selector(ULONG ) type;}; \
}

#define ZTypeSelectorInteger(container, selector)					    \
namespace TypeSelectors {								    \
	template <typename T> struct container{};					    \
	template <> struct container<signed char	 > {typedef selector(CHAR ) type;}; \
	template <> struct container<signed short int	 > {typedef selector(SHORT) type;}; \
	template <> struct container<signed int		 > {typedef selector(INT  ) type;}; \
	template <> struct container<signed long int	 > {typedef selector(LONG ) type;}; \
	template <> struct container<signed long long int> {typedef selector(LONG ) type;}; \
}

#define ZTypeSelectorReal(container, selector)					     \
namespace TypeSelectors {							     \
	template <typename T> struct container{};				     \
	template <> struct container<float	> {typedef selector(FLOAT  ) type;}; \
	template <> struct container<double	> {typedef selector(DOUBLE ) type;}; \
	template <> struct container<long double> {typedef selector(LDOUBLE) type;}; \
}

#define ZTypeSelectorNaturalAndInteger(container, selector)				       \
namespace TypeSelectors {								       \
	template <typename T> struct container{};					       \
	template <> struct container<unsigned char	   > {typedef selector(UCHAR ) type;}; \
	template <> struct container<unsigned short int	   > {typedef selector(USHORT) type;}; \
	template <> struct container<unsigned int	   > {typedef selector(UINT  ) type;}; \
	template <> struct container<unsigned long int	   > {typedef selector(ULONG ) type;}; \
	template <> struct container<unsigned long long int> {typedef selector(ULONG ) type;}; \
	template <> struct container<signed char	   > {typedef selector(CHAR  ) type;}; \
	template <> struct container<signed short int	   > {typedef selector(SHORT ) type;}; \
	template <> struct container<signed int		   > {typedef selector(INT   ) type;}; \
	template <> struct container<signed long int	   > {typedef selector(LONG  ) type;}; \
	template <> struct container<signed long long int  > {typedef selector(LONG  ) type;}; \
}

#define ZTypeSelectorNaturalIntegerAndReal(container, selector)				        \
namespace TypeSelectors {								        \
	template <typename T> struct container{};					        \
	template <> struct container<unsigned char	   > {typedef selector(UCHAR  ) type;}; \
	template <> struct container<unsigned short int	   > {typedef selector(USHORT ) type;}; \
	template <> struct container<unsigned int	   > {typedef selector(UINT   ) type;}; \
	template <> struct container<unsigned long int	   > {typedef selector(ULONG  ) type;}; \
	template <> struct container<unsigned long long int> {typedef selector(ULONG  ) type;}; \
	template <> struct container<signed char	   > {typedef selector(CHAR   ) type;}; \
	template <> struct container<signed short int	   > {typedef selector(SHORT  ) type;}; \
	template <> struct container<signed int		   > {typedef selector(INT    ) type;}; \
	template <> struct container<signed long int	   > {typedef selector(LONG   ) type;}; \
	template <> struct container<signed long long int  > {typedef selector(LONG   ) type;}; \
	template <> struct container<float		   > {typedef selector(FLOAT  ) type;}; \
	template <> struct container<double		   > {typedef selector(DOUBLE ) type;}; \
	template <> struct container<long double	   > {typedef selector(LDOUBLE) type;}; \
}

#endif // __Z_classes_base_Range_HPP__
