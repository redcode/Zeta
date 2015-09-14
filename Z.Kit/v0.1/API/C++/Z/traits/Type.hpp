/* Z Kit C++ API - macros/templating.hpp
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_traits_Type_HPP__
#define __Z_traits_Type_HPP__

#include <Z/types/base.h>

namespace ZKit {
	namespace Abstract {namespace Type {
		struct Base {
			enum {	is_class    = false,
				is_const    = false,
				is_volatile = false,
				is_exact    = false,
				is_integer  = false,
				is_function = false,
				is_natural  = false,
				is_pointer  = false,
				is_real	    = false,
				is_signed   = false,
				is_union    = false,
				is_value    = false,
				is_void	    = false
			};
		};

		struct Value : public Base {enum {is_value = true};};

		struct Natural : public Value {
			enum {	is_exact   = true,
				is_natural = true,
			};

			enum {minimum = 0};
		};

		struct Integer : public Value {
			enum {	is_exact   = true,
				is_integer = true,
				is_signed  = true
			};
		};

		struct Real : public Value {
			enum {	is_real	   = true,
				is_signed  = true
			};
		};
	}}

	template <typename T> struct Type {};

	template <> struct Type<unsigned char> : public Abstract::Type::Natural {
		enum {	bits = Z_UCHAR_BITS,
			size = Z_UCHAR_SIZE
		};
		enum {maximum = Z_UCHAR_MAXIMUM};

		typedef		       unsigned char base_type;
		typedef const	       unsigned char const_type;
		typedef	      volatile unsigned char volatile_type;
		typedef const volatile unsigned char const_volatile_type;
	};

	template <> struct Type<const	       unsigned char> : public Type<	     unsigned char> {enum {is_const    = true};};
	template <> struct Type<      volatile unsigned char> : public Type<	     unsigned char> {enum {is_volatile = true};};
	template <> struct Type<const volatile unsigned char> : public Type<volatile unsigned char> {enum {is_const    = true};};

	template <> struct Type<unsigned short int> : public Abstract::Type::Natural {
		enum {	bits = Z_USHORT_BITS,
			size = Z_USHORT_SIZE
		};
		enum {maximum = Z_USHORT_MAXIMUM};

		typedef		       unsigned short int base_type;
		typedef const	       unsigned short int const_type;
		typedef	      volatile unsigned short int volatile_type;
		typedef const volatile unsigned short int const_volatile_type;
	};

	template <> struct Type<const	       unsigned short int> : public Type<	  unsigned short int> {enum {is_const	 = true};};
	template <> struct Type<volatile       unsigned short int> : public Type<	  unsigned short int> {enum {is_volatile = true};};
	template <> struct Type<const volatile unsigned short int> : public Type<volatile unsigned short int> {enum {is_const	 = true};};

	template <> struct Type<unsigned int> : public Abstract::Type::Natural {
		enum {	bits = Z_UINT_BITS,
			size = Z_UINT_SIZE
		};
		enum {maximum = Z_UINT_MAXIMUM};

		typedef		       unsigned int base_type;
		typedef const	       unsigned int const_type;
		typedef	      volatile unsigned int volatile_type;
		typedef const volatile unsigned int const_volatile_type;
	};

	template <> struct Type<const	       unsigned int> : public Type<	    unsigned int> {enum {is_const    = true};};
	template <> struct Type<      volatile unsigned int> : public Type<	    unsigned int> {enum {is_volatile = true};};
	template <> struct Type<const volatile unsigned int> : public Type<volatile unsigned int> {enum {is_const    = true};};

	template <> struct Type<unsigned long int> : public Abstract::Type::Natural {
		enum {	bits = Z_ULONG_BITS,
			size = Z_ULONG_SIZE
		};
		enum {maximum = Z_ULONG_MAXIMUM};

		typedef		       unsigned long int base_type;
		typedef const	       unsigned long int const_type;
		typedef	      volatile unsigned long int volatile_type;
		typedef const volatile unsigned long int const_volatile_type;
	};

	template <> struct Type<const	       unsigned long int> : public Type<	 unsigned long int> {enum {is_const    = true};};
	template <> struct Type<      volatile unsigned long int> : public Type<	 unsigned long int> {enum {is_volatile = true};};
	template <> struct Type<const volatile unsigned long int> : public Type<volatile unsigned long int> {enum {is_const    = true};};

	template <> struct Type<unsigned long long int> : public Abstract::Type::Natural {
		enum {	bits = Z_ULLONG_BITS,
			size = Z_ULLONG_SIZE
		};
		enum {maximum = Z_ULLONG_MAXIMUM};

		typedef		       unsigned long long int base_type;
		typedef const	       unsigned long long int const_type;
		typedef	      volatile unsigned long long int volatile_type;
		typedef const volatile unsigned long long int const_volatile_type;
	};

	template <> struct Type<const	       unsigned long long int> : public Type<	      unsigned long long int> {enum {is_const	 = true};};
	template <> struct Type<volatile       unsigned long long int> : public Type<	      unsigned long long int> {enum {is_volatile = true};};
	template <> struct Type<const volatile unsigned long long int> : public Type<volatile unsigned long long int> {enum {is_const	 = true};};

	template <> struct Type<signed char> : public Abstract::Type::Integer {
		enum {	bits = Z_CHAR_BITS,
			size = Z_CHAR_SIZE
		};
		enum {	maximum = Z_CHAR_MAXIMUM,
			minimum = Z_CHAR_MINIMUM
		};

		typedef		       signed char base_type;
		typedef const	       signed char const_type;
		typedef	      volatile signed char volatile_type;
		typedef const volatile signed char const_volatile_type;
	};

	template <> struct Type<const	       signed char> : public Type<	   signed char> {enum {is_const	   = true};};
	template <> struct Type<      volatile signed char> : public Type<	   signed char> {enum {is_volatile = true};};
	template <> struct Type<const volatile signed char> : public Type<volatile signed char> {enum {is_const	   = true};};

	template <> struct Type<signed short int> : public Abstract::Type::Integer {
		enum {	bits = Z_SHORT_BITS,
			size = Z_SHORT_SIZE
		};
		enum {	maximum = Z_SHORT_MAXIMUM,
			minimum = Z_SHORT_MINIMUM
		};

		typedef		       signed short int base_type;
		typedef const	       signed short int const_type;
		typedef	      volatile signed short int volatile_type;
		typedef const volatile signed short int const_volatile_type;
	};

	template <> struct Type<const	       signed short int> : public Type<	  	signed short int> {enum {is_const    = true};};
	template <> struct Type<volatile       signed short int> : public Type<	  	signed short int> {enum {is_volatile = true};};
	template <> struct Type<const volatile signed short int> : public Type<volatile	signed short int> {enum {is_const    = true};};

	template <> struct Type<signed int> : public Abstract::Type::Integer {
		enum {	bits = Z_INT_BITS,
			size = Z_INT_SIZE
		};
		enum {	maximum = Z_INT_MAXIMUM,
			minimum = Z_INT_MINIMUM
		};

		typedef		       signed int base_type;
		typedef const	       signed int const_type;
		typedef	      volatile signed int volatile_type;
		typedef const volatile signed int const_volatile_type;
	};

	template <> struct Type<const	       signed int> : public Type<	  signed int> {enum {is_const	 = true};};
	template <> struct Type<      volatile signed int> : public Type<	  signed int> {enum {is_volatile = true};};
	template <> struct Type<const volatile signed int> : public Type<volatile signed int> {enum {is_const	 = true};};

	template <> struct Type<signed long int> : public Abstract::Type::Integer {
		enum {	bits = Z_LONG_BITS,
			size = Z_LONG_SIZE
		};
		enum {	maximum = Z_LONG_MAXIMUM,
			minimum = Z_LONG_MINIMUM
		};

		typedef		       signed long int base_type;
		typedef const	       signed long int const_type;
		typedef	      volatile signed long int volatile_type;
		typedef const volatile signed long int const_volatile_type;
	};

	template <> struct Type<const	       signed long int> : public Type<	       signed long int> {enum {is_const	   = true};};
	template <> struct Type<      volatile signed long int> : public Type<	       signed long int> {enum {is_volatile = true};};
	template <> struct Type<const volatile signed long int> : public Type<volatile signed long int> {enum {is_const	   = true};};

	template <> struct Type<signed long long int> : public Abstract::Type::Integer {
		enum {	bits = Z_LLONG_BITS,
			size = Z_LLONG_SIZE
		};
		enum {	maximum = Z_LLONG_MAXIMUM,
			minimum = Z_LLONG_MINIMUM
		};

		typedef		       signed long long int base_type;
		typedef const	       signed long long int const_type;
		typedef	      volatile signed long long int volatile_type;
		typedef const volatile signed long long int const_volatile_type;
	};

	template <> struct Type<const	       signed long long int> : public Type<	    signed long long int> {enum {is_const    = true};};
	template <> struct Type<volatile       signed long long int> : public Type<	    signed long long int> {enum {is_volatile = true};};
	template <> struct Type<const volatile signed long long int> : public Type<volatile signed long long int> {enum {is_const    = true};};

	template <> struct Type<float> : public Abstract::Type::Real {
		enum {	bits		    = Z_FLOAT_BITS,
			size		    = Z_FLOAT_SIZE,
			bias		    = Z_FLOAT_BIAS,
			decimal_digits	    = Z_FLOAT_DECIMAL_DIGITS,
			significand_offset  = Z_FLOAT_SIGNIFICAND_OFFSET,
			significand_bits    = Z_FLOAT_SIGNIFICAND_BITS,
			significand_digits  = Z_FLOAT_SIGNIFICAND_DIGITS,
			exponent_offset	    = Z_FLOAT_EXPONENT_OFFSET,
			exponent_bits	    = Z_FLOAT_EXPONENT_BITS,
			exponent_radix	    = Z_FLOAT_EXPONENT_RADIX,
			exponent_minimum    = Z_FLOAT_EXPONENT_MINIMUM,
			exponent_maximum    = Z_FLOAT_EXPONENT_MAXIMUM,
			exponent_10_minimum = Z_FLOAT_EXPONENT_10_MINIMUM,
			exponent_10_maximum = Z_FLOAT_EXPONENT_10_MAXIMUM,
			sign_offset	    = Z_FLOAT_SIGN_OFFSET,
			sign_bits	    = Z_FLOAT_SIGN_BITS
		};

		typedef		       float base_type;
		typedef const	       float const_type;
		typedef	      volatile float volatile_type;
		typedef const volatile float const_volatile_type;
	};

	template <> struct Type<const	       float> : public Type<	     float> {enum {is_const    = true};};
	template <> struct Type<volatile       float> : public Type<	     float> {enum {is_volatile = true};};
	template <> struct Type<const volatile float> : public Type<volatile float> {enum {is_const    = true};};

	template <> struct Type<double> : public Abstract::Type::Real {
		enum {	bits		    = Z_DOUBLE_BITS,
			size		    = Z_DOUBLE_SIZE,
			bias		    = Z_DOUBLE_BIAS,
			decimal_digits	    = Z_DOUBLE_DECIMAL_DIGITS,
			significand_offset  = Z_DOUBLE_SIGNIFICAND_OFFSET,
			significand_bits    = Z_DOUBLE_SIGNIFICAND_BITS,
			significand_digits  = Z_DOUBLE_SIGNIFICAND_DIGITS,
			exponent_offset	    = Z_DOUBLE_EXPONENT_OFFSET,
			exponent_bits	    = Z_DOUBLE_EXPONENT_BITS,
			exponent_radix	    = Z_DOUBLE_EXPONENT_RADIX,
			exponent_minimum    = Z_DOUBLE_EXPONENT_MINIMUM,
			exponent_maximum    = Z_DOUBLE_EXPONENT_MAXIMUM,
			exponent_10_minimum = Z_DOUBLE_EXPONENT_10_MINIMUM,
			exponent_10_maximum = Z_DOUBLE_EXPONENT_10_MAXIMUM,
			sign_offset	    = Z_DOUBLE_SIGN_OFFSET,
			sign_bits	    = Z_DOUBLE_SIGN_BITS
		};

		typedef		       double base_type;
		typedef const	       double const_type;
		typedef	      volatile double volatile_type;
		typedef const volatile double const_volatile_type;
	};

	template <> struct Type<const	       double> : public Type<	      double> {enum {is_const	 = true};};
	template <> struct Type<volatile       double> : public Type<	      double> {enum {is_volatile = true};};
	template <> struct Type<const volatile double> : public Type<volatile double> {enum {is_const	 = true};};

	template <> struct Type<long double> : public Abstract::Type::Real {
		enum {	bits		    = Z_LDOUBLE_BITS,
			size		    = Z_LDOUBLE_SIZE,
			bias		    = Z_LDOUBLE_BIAS,
			decimal_digits	    = Z_LDOUBLE_DECIMAL_DIGITS,
			significand_offset  = Z_LDOUBLE_SIGNIFICAND_OFFSET,
			significand_bits    = Z_LDOUBLE_SIGNIFICAND_BITS,
			significand_digits  = Z_LDOUBLE_SIGNIFICAND_DIGITS,
			exponent_offset	    = Z_LDOUBLE_EXPONENT_OFFSET,
			exponent_bits	    = Z_LDOUBLE_EXPONENT_BITS,
			exponent_radix	    = Z_LDOUBLE_EXPONENT_RADIX,
			exponent_minimum    = Z_LDOUBLE_EXPONENT_MINIMUM,
			exponent_maximum    = Z_LDOUBLE_EXPONENT_MAXIMUM,
			exponent_10_minimum = Z_LDOUBLE_EXPONENT_10_MINIMUM,
			exponent_10_maximum = Z_LDOUBLE_EXPONENT_10_MAXIMUM,
			sign_offset	    = Z_LDOUBLE_SIGN_OFFSET,
			sign_bits	    = Z_LDOUBLE_SIGN_BITS
		};

		typedef		       long double base_type;
		typedef const	       long double const_type;
		typedef	      volatile long double volatile_type;
		typedef const volatile long double const_volatile_type;
	};

	template <> struct Type<const	       long double> : public Type<	   long double> {enum {is_const	   = true};};
	template <> struct Type<volatile       long double> : public Type<	   long double> {enum {is_volatile = true};};
	template <> struct Type<const volatile long double> : public Type<volatile long double> {enum {is_const	   = true};};
}

#endif // __Z_traits_Type_HPP__
