/* Z Kit C++ API - classes/base/Range.hpp
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_macros_templating_HPP__
#define __Z_macros_templating_HPP__

#define ZMetaTypeSelectorNatural(container, selector)				    \
template <typename T> struct container{};					    \
template <> struct container<unsigned char	   > {typedef selector(UCHAR ) V;}; \
template <> struct container<unsigned short int	   > {typedef selector(USHORT) V;}; \
template <> struct container<unsigned int	   > {typedef selector(UINT  ) V;}; \
template <> struct container<unsigned long int	   > {typedef selector(ULONG ) V;}; \
template <> struct container<unsigned long long int> {typedef selector(ULONG ) V;}; \

#define ZMetaTypeSelectorIntegerOnly(container, selector)			 \
template <typename T> struct container{};					 \
template <> struct container<signed char	 > {typedef selector(CHAR ) V;}; \
template <> struct container<signed short int	 > {typedef selector(SHORT) V;}; \
template <> struct container<signed int		 > {typedef selector(INT  ) V;}; \
template <> struct container<signed long int	 > {typedef selector(LONG ) V;}; \
template <> struct container<signed long long int> {typedef selector(LONG ) V;}; \

#define ZMetaTypeSelectorRealOnly(container, selector)			  \
template <typename T> struct container{};				  \
template <> struct container<float	> {typedef selector(FLOAT  ) V;}; \
template <> struct container<double	> {typedef selector(DOUBLE ) V;}; \
template <> struct container<long double> {typedef selector(LDOUBLE) V;};

#define ZMetaTypeSelectorInteger(container, selector)				    \
template <typename T> struct container{};					    \
template <> struct container<unsigned char	   > {typedef selector(UCHAR ) V;}; \
template <> struct container<unsigned short int	   > {typedef selector(USHORT) V;}; \
template <> struct container<unsigned int	   > {typedef selector(UINT  ) V;}; \
template <> struct container<unsigned long int	   > {typedef selector(ULONG ) V;}; \
template <> struct container<unsigned long long int> {typedef selector(ULONG ) V;}; \
template <> struct container<signed char	   > {typedef selector(CHAR  ) V;}; \
template <> struct container<signed short int	   > {typedef selector(SHORT ) V;}; \
template <> struct container<signed int		   > {typedef selector(INT   ) V;}; \
template <> struct container<signed long int	   > {typedef selector(LONG  ) V;}; \
template <> struct container<signed long long int  > {typedef selector(LONG  ) V;}; \

#define ZMetaTypeSelectorReal(container, selector)				     \
template <typename T> struct container{};					     \
template <> struct container<unsigned char	   > {typedef selector(UCHAR  ) V;}; \
template <> struct container<unsigned short int	   > {typedef selector(USHORT ) V;}; \
template <> struct container<unsigned int	   > {typedef selector(UINT   ) V;}; \
template <> struct container<unsigned long int	   > {typedef selector(ULONG  ) V;}; \
template <> struct container<unsigned long long int> {typedef selector(ULONG  ) V;}; \
template <> struct container<signed char	   > {typedef selector(CHAR   ) V;}; \
template <> struct container<signed short int	   > {typedef selector(SHORT  ) V;}; \
template <> struct container<signed int		   > {typedef selector(INT    ) V;}; \
template <> struct container<signed long int	   > {typedef selector(LONG   ) V;}; \
template <> struct container<signed long long int  > {typedef selector(LONG   ) V;}; \
template <> struct container<float		   > {typedef selector(FLOAT  ) V;}; \
template <> struct container<double		   > {typedef selector(DOUBLE ) V;}; \
template <> struct container<long double	   > {typedef selector(LDOUBLE) V;};

#endif // __Z_classes_base_Range_HPP__
