 /* Z Kit C++ API - macros/type selector.hpp
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_macros_type_selector_HPP__
#define __Z_macros_type_selector_HPP__

template <typename T> struct NumberTypeIndex {};
template <> struct NumberTypeIndex<unsigned char	 > {enum {value = 0};};
template <> struct NumberTypeIndex<unsigned short int    > {enum {value = 1};};
template <> struct NumberTypeIndex<unsigned int		 > {enum {value = 2};};
template <> struct NumberTypeIndex<unsigned long int	 > {enum {value = 3};};
template <> struct NumberTypeIndex<unsigned long long int> {enum {value = 4};};
template <> struct NumberTypeIndex<signed char		 > {enum {value = 5};};
template <> struct NumberTypeIndex<signed short int	 > {enum {value = 6};};
template <> struct NumberTypeIndex<signed int		 > {enum {value = 7};};
template <> struct NumberTypeIndex<signed long int	 > {enum {value = 8};};
template <> struct NumberTypeIndex<signed long long int	 > {enum {value = 9};};
template <> struct NumberTypeIndex<float		 > {enum {value = 10};};
template <> struct NumberTypeIndex<double		 > {enum {value = 11};};
template <> struct NumberTypeIndex<long double		 > {enum {value = 12};};



#define Z_TYPE_SELECTOR_NATURAL(name, type_macro)				    \
template <typename T> struct name {};						    \
template <> struct name<unsigned char	      > {typedef type_macro(UCHAR ) type;}; \
template <> struct name<unsigned short int    > {typedef type_macro(USHORT) type;}; \
template <> struct name<unsigned int	      > {typedef type_macro(UINT  ) type;}; \
template <> struct name<unsigned long int     > {typedef type_macro(ULONG ) type;}; \
template <> struct name<unsigned long long int> {typedef type_macro(ULONG ) type;};

#define Z_TYPE_SELECTOR_INTEGER(name, type_macro)				 \
template <typename T> struct name {};						 \
template <> struct name<signed char	    > {typedef type_macro(CHAR ) type;}; \
template <> struct name<signed short int    > {typedef type_macro(SHORT) type;}; \
template <> struct name<signed int	    > {typedef type_macro(INT  ) type;}; \
template <> struct name<signed long int	    > {typedef type_macro(LONG ) type;}; \
template <> struct name<signed long long int> {typedef type_macro(LONG ) type;};

#define Z_TYPE_SELECTOR_REAL(name, type_macro)				  \
template <typename T> struct name {};					  \
template <> struct name<float	   > {typedef type_macro(FLOAT	) type;}; \
template <> struct name<double	   > {typedef type_macro(DOUBLE ) type;}; \
template <> struct name<long double> {typedef type_macro(LDOUBLE) type;};

#define Z_TYPE_SELECTOR_NON_REAL(name, type_macro)				    \
template <typename T> struct name {};						    \
template <> struct name<unsigned char	      > {typedef type_macro(UCHAR ) type;}; \
template <> struct name<unsigned short int    > {typedef type_macro(USHORT) type;}; \
template <> struct name<unsigned int	      > {typedef type_macro(UINT  ) type;}; \
template <> struct name<unsigned long int     > {typedef type_macro(ULONG ) type;}; \
template <> struct name<unsigned long long int> {typedef type_macro(ULONG ) type;}; \
template <> struct name<signed char	      > {typedef type_macro(CHAR  ) type;}; \
template <> struct name<signed short int      > {typedef type_macro(SHORT ) type;}; \
template <> struct name<signed int	      > {typedef type_macro(INT	  ) type;}; \
template <> struct name<signed long int	      > {typedef type_macro(LONG  ) type;}; \
template <> struct name<signed long long int  > {typedef type_macro(LONG  ) type;}; \

#define Z_TYPE_SELECTOR_SIGNED(name, type_macro)				     \
template <typename T> struct name {};						     \
template <> struct name<signed char	      > {typedef type_macro(CHAR   ) type;}; \
template <> struct name<signed short int      > {typedef type_macro(SHORT  ) type;}; \
template <> struct name<signed int	      > {typedef type_macro(INT	   ) type;}; \
template <> struct name<signed long int	      > {typedef type_macro(LONG   ) type;}; \
template <> struct name<signed long long int  > {typedef type_macro(LONG   ) type;}; \
template <> struct name<float		      > {typedef type_macro(FLOAT  ) type;}; \
template <> struct name<double		      > {typedef type_macro(DOUBLE ) type;}; \
template <> struct name<long double	      > {typedef type_macro(LDOUBLE) type;};

#define Z_TYPE_SELECTOR(name, type_macro)					     \
template <typename T> struct name {};						     \
template <> struct name<unsigned char	      > {typedef type_macro(UCHAR  ) type;}; \
template <> struct name<unsigned short int    > {typedef type_macro(USHORT ) type;}; \
template <> struct name<unsigned int	      > {typedef type_macro(UINT   ) type;}; \
template <> struct name<unsigned long int     > {typedef type_macro(ULONG  ) type;}; \
template <> struct name<unsigned long long int> {typedef type_macro(ULONG  ) type;}; \
template <> struct name<signed char	      > {typedef type_macro(CHAR   ) type;}; \
template <> struct name<signed short int      > {typedef type_macro(SHORT  ) type;}; \
template <> struct name<signed int	      > {typedef type_macro(INT	   ) type;}; \
template <> struct name<signed long int	      > {typedef type_macro(LONG   ) type;}; \
template <> struct name<signed long long int  > {typedef type_macro(LONG   ) type;}; \
template <> struct name<float		      > {typedef type_macro(FLOAT  ) type;}; \
template <> struct name<double		      > {typedef type_macro(DOUBLE ) type;}; \
template <> struct name<long double	      > {typedef type_macro(LDOUBLE) type;};

#endif // __Z_macros_type_selector_HPP__
