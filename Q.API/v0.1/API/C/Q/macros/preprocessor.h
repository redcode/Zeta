/* Q API - macros/preprocessor.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Copyright © 2006 Laurent Deniau <laurent.deniau@cern.ch>.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_macros_preprocessor_H__
#define __Q_macros_preprocessor_H__

#define Q_SAME(	  what)				  what
#define Q_QUOTED_(what)				  #what
#define Q_QUOTED( what)				  Q_QUOTED_(what)

#define Q_PREFIX_				  Q_SAME
#define Q_PREFIX_0_(	 what)			  0##what
#define Q_PREFIX_0x_(	 what)			  0x##what
#define Q_PREFIX_Q_(	 what)			  Q##what
#define Q_PREFIX_Q_UINT_(what)			  Q_UINT##what
#define Q_PREFIX_Q_INT_( what)			  Q_INT##what
#define Q_SUFFIX_				  Q_SAME
#define Q_SUFFIX_DD_(	 what)			  what##DD
#define Q_SUFFIX_DF_(	 what)			  what##DF
#define Q_SUFFIX_DL_(	 what)			  what##DL
#define Q_SUFFIX_F_(	 what)			  what##F
#define Q_SUFFIX_L_(	 what)			  what##L
#define Q_SUFFIX_LL_(	 what)			  what##LL
#define Q_SUFFIX_UL_(	 what)			  what##UL
#define Q_SUFFIX_ULL_(	 what)			  what##ULL

#define Q_PREFIX_0(	what)			  Q_PREFIX_0_(	   what)
#define Q_PREFIX_0x(	what)			  Q_PREFIX_0x_(	   what)
#define Q_PREFIX_Q(	what)			  Q_PREFIX_Q_(	   what)
#define Q_PREFIX_Q_UINT(what)			  Q_PREFIX_Q_UINT_(what)
#define Q_PREFIX_Q_INT( what)			  Q_PREFIX_Q_INT_( what)
#define Q_SUFFIX_DD(	what)			  Q_SUFFIX_DD_(	   what)
#define Q_SUFFIX_DF(	what)			  Q_SUFFIX_DF_(	   what)
#define Q_SUFFIX_DL(	what)			  Q_SUFFIX_DL_(	   what)
#define Q_SUFFIX_F(	what)			  Q_SUFFIX_F_(	   what)
#define Q_SUFFIX_L(	what)			  Q_SUFFIX_L_(	   what)
#define Q_SUFFIX_LL(	what)			  Q_SUFFIX_LL_(	   what)
#define Q_SUFFIX_UL(	what)			  Q_SUFFIX_UL_(	   what)
#define Q_SUFFIX_ULL(	what)			  Q_SUFFIX_ULL_(   what)

#define Q_UNDERSCORE_(		what)		  _##what##_
#define Q_UNDERSCORE_X2_(	what)		  __##what##__
#define Q_PREFIX_UNDERSCORE_(	what)		  _##what
#define Q_PREFIX_UNDERSCORE_X2_(what)		  __##what
#define Q_SUFFIX_UNDERSCORE_(	what)		  what##_
#define Q_SUFFIX_UNDERSCORE_X2_(what)		  what##__

#define Q_UNDERSCORE(		what)		  Q_UNDERSCORE_(	  what)
#define Q_UNDERSCORE_X2(	what)		  Q_UNDERSCORE_X2_(	  what)
#define Q_PREFIX_UNDERSCORE(	what)		  Q_PREFIX_UNDERSCORE_(   what)
#define Q_PREFIX_UNDERSCORE_X2( what)		  Q_PREFIX_UNDERSCORE_X2_(what)
#define Q_SUFFIX_UNDERSCORE(	what)		  Q_SUFFIX_UNDERSCORE_(   what)
#define Q_SUFFIX_UNDERSCORE_X2( what)		  Q_SUFFIX_UNDERSCORE_X2_(what)

#define Q_HEADER(      header)			  <header>
#define Q_LOCAL_HEADER(header)			  Q_QUOTED(header)

#define Q_JOIN_2_(a, b)				  a##b
#define Q_JOIN_3_(a, b, c)			  a##b##c
#define Q_JOIN_4_(a, b, c, d)			  a##b##c##d
#define Q_JOIN_5_(a, b, c, d, e)		  a##b##c##d##e
#define Q_JOIN_6_(a, b, c, d, e, f)		  a##b##c##d##e##f
#define Q_JOIN_7_(a, b, c, d, e, f, g)		  a##b##c##d##e##f##g
#define Q_JOIN_8_(a, b, c, d, e, f, g, h)	  a##b##c##d##e##f##g##h

#define Q_JOIN_2(a, b)				  Q_JOIN_2_(a, b)
#define Q_JOIN_3(a, b, c)			  Q_JOIN_3_(a, b, c)
#define Q_JOIN_4(a, b, c, d)			  Q_JOIN_4_(a, b, c, d)
#define Q_JOIN_5(a, b, c, d, e)			  Q_JOIN_5_(a, b, c, d, e)
#define Q_JOIN_6(a, b, c, d, e, f)		  Q_JOIN_6_(a, b, c, d, e, f)
#define Q_JOIN_7(a, b, c, d, e, f, g)		  Q_JOIN_7_(a, b, c, d, e, f, g)
#define Q_JOIN_8(a, b, c, d, e, f, g, h)	  Q_JOIN_8_(a, b, c, d, e, f, g, h)

#define Q_JOIN_2_DEFINED_(a, b)			  (defined a##b)
#define Q_JOIN_3_DEFINED_(a, b, c)		  (defined a##b##c)
#define Q_JOIN_4_DEFINED_(a, b, c, d)		  (defined a##b##c##d)
#define Q_JOIN_5_DEFINED_(a, b, c, d, e)	  (defined a##b##c##d##e)
#define Q_JOIN_6_DEFINED_(a, b, c, d, e, f)	  (defined a##b##c##d##e##f)
#define Q_JOIN_7_DEFINED_(a, b, c, d, e, f, g)	  (defined a##b##c##d##e##f##g)
#define Q_JOIN_8_DEFINED_(a, b, c, d, e, f, g, h) (defined a##b##c##d##e##f##g##h)

#define Q_JOIN_2_DEFINED(a, b)			  Q_JOIN_2_DEFINED_(a, b)
#define Q_JOIN_3_DEFINED(a, b, c)		  Q_JOIN_3_DEFINED_(a, b, c)
#define Q_JOIN_4_DEFINED(a, b, c, d)		  Q_JOIN_4_DEFINED_(a, b, c, d)
#define Q_JOIN_5_DEFINED(a, b, c, d, e)		  Q_JOIN_5_DEFINED_(a, b, c, d, e)
#define Q_JOIN_6_DEFINED(a, b, c, d, e, f)	  Q_JOIN_6_DEFINED_(a, b, c, d, e, f)
#define Q_JOIN_7_DEFINED(a, b, c, d, e, f, g)	  Q_JOIN_7_DEFINED_(a, b, c, d, e, f, g)
#define Q_JOIN_8_DEFINED(a, b, c, d, e, f, g, h)  Q_JOIN_8_DEFINED_(a, b, c, d, e, f, g, h)

#ifndef Q_AVOID_VARIADIC_MACROS

#	define L_PP_ARG_N( \
		 _1,  _2,  _3,	_4,  _5,  _6,  _7,  _8,  _9, _10, _11, _12, _13, _14, _15, _16, \
		_17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, \
		_33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, \
		_49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63,   N, \
		... \
	) N

#	define L_PP_RSEQ_N() \
		63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, \
		47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, \
		31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, \
		15, 14, 13, 12, 11, 10,  9,  8,  7,  6,  5,  4,  3,  2,  1,  0

#	define Q_ARGUMENT_COUNT_(...) Q_SAME(L_PP_ARG_N(__VA_ARGS__))
#	define Q_ARGUMENT_COUNT( ...) Q_ARGUMENT_COUNT_(__VA_ARGS__, L_PP_RSEQ_N())
#	define Q_JOIN_N(	 n  ) Q_JOIN_2_(Q_JOIN_, n) /* Needed for Q_JOIN(...) only */
#	define Q_JOIN(		 ...) Q_SAME(Q_JOIN_N(Q_ARGUMENT_COUNT_(__VA_ARGS__, L_PP_RSEQ_N())))(__VA_ARGS__)

#endif

#endif /* __Q_macros_preprocessor_H__ */
