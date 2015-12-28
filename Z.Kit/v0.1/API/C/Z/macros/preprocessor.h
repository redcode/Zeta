/* Z Kit C API - macros/preprocessor.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Copyright © 2006 Laurent Deniau <laurent.deniau@cern.ch>.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_macros_preprocessor_H__
#define __Z_macros_preprocessor_H__

#define Z_ALLOW(  what) what
#define Z_AVOID(  what)
#define Z_QUOTED_(what) #what
#define Z_QUOTED( what) Z_QUOTED_(what)
#define Z_SAME(	  what) what

#define Z_EXPAND_PREFIX_0(  what) 0##what
#define Z_EXPAND_PREFIX_0x( what) 0x##what
#define Z_EXPAND_PREFIX_Z(  what) Z##what
#define Z_EXPAND_PREFIX_Z_( what) Z_##what
#define Z_EXPAND_PREFIX_z(  what) z##what
#define Z_EXPAND_PREFIX_z_( what) z_##what
#define Z_EXPAND_SUFFIX_DD( what) what##DD
#define Z_EXPAND_SUFFIX_DF( what) what##DF
#define Z_EXPAND_SUFFIX_DL( what) what##DL
#define Z_EXPAND_SUFFIX_F(  what) what##F
#define Z_EXPAND_SUFFIX_L(  what) what##L
#define Z_EXPAND_SUFFIX_LL( what) what##LL
#define Z_EXPAND_SUFFIX_U(  what) what##U
#define Z_EXPAND_SUFFIX_UL( what) what##UL
#define Z_EXPAND_SUFFIX_ULL(what) what##ULL

#define Z_PREFIX_	   Z_SAME
#define Z_PREFIX_0(  what) Z_EXPAND_PREFIX_0	(what)
#define Z_PREFIX_0x( what) Z_EXPAND_PREFIX_0x	(what)
#define Z_PREFIX_Z(  what) Z_EXPAND_PREFIX_Z	(what)
#define Z_PREFIX_Z_( what) Z_EXPAND_PREFIX_Z_	(what)
#define Z_PREFIX_z(  what) Z_EXPAND_PREFIX_z	(what)
#define Z_PREFIX_z_( what) Z_EXPAND_PREFIX_z_	(what)
#define Z_SUFFIX_	   Z_SAME
#define Z_SUFFIX_DD( what) Z_EXPAND_SUFFIX_DD	(what)
#define Z_SUFFIX_DF( what) Z_EXPAND_SUFFIX_DF	(what)
#define Z_SUFFIX_DL( what) Z_EXPAND_SUFFIX_DL	(what)
#define Z_SUFFIX_F(  what) Z_EXPAND_SUFFIX_F	(what)
#define Z_SUFFIX_L(  what) Z_EXPAND_SUFFIX_L	(what)
#define Z_SUFFIX_LL( what) Z_EXPAND_SUFFIX_LL	(what)
#define Z_SUFFIX_U(  what) Z_EXPAND_SUFFIX_U	(what)
#define Z_SUFFIX_UL( what) Z_EXPAND_SUFFIX_UL	(what)
#define Z_SUFFIX_ULL(what) Z_EXPAND_SUFFIX_ULL(what)

#define Z_UNDERSCORE_(		what) _##what##_
#define Z_UNDERSCORE_X2_(	what) __##what##__
#define Z_PREFIX_UNDERSCORE_(	what) _##what
#define Z_PREFIX_UNDERSCORE_X2_(what) __##what
#define Z_SUFFIX_UNDERSCORE_(	what) what##_
#define Z_SUFFIX_UNDERSCORE_X2_(what) what##__

#define Z_UNDERSCORE(		what) Z_UNDERSCORE_	     (what)
#define Z_UNDERSCORE_X2(	what) Z_UNDERSCORE_X2_	     (what)
#define Z_PREFIX_UNDERSCORE(	what) Z_PREFIX_UNDERSCORE_   (what)
#define Z_PREFIX_UNDERSCORE_X2( what) Z_PREFIX_UNDERSCORE_X2_(what)
#define Z_SUFFIX_UNDERSCORE(	what) Z_SUFFIX_UNDERSCORE_   (what)
#define Z_SUFFIX_UNDERSCORE_X2( what) Z_SUFFIX_UNDERSCORE_X2_(what)

#define Z_HEADER(      header) <header>
#define Z_LOCAL_HEADER(header) Z_QUOTED(header)

#define Z_PASTE_2(a, b)			  a##b
#define Z_PASTE_3(a, b, c)		  a##b##c
#define Z_PASTE_4(a, b, c, d)		  a##b##c##d
#define Z_PASTE_5(a, b, c, d, e)	  a##b##c##d##e
#define Z_PASTE_6(a, b, c, d, e, f)	  a##b##c##d##e##f
#define Z_PASTE_7(a, b, c, d, e, f, g)	  a##b##c##d##e##f##g
#define Z_PASTE_8(a, b, c, d, e, f, g, h) a##b##c##d##e##f##g##h

#define Z_JOIN_2(a, b)			 Z_PASTE_2(a, b)
#define Z_JOIN_3(a, b, c)		 Z_PASTE_3(a, b, c)
#define Z_JOIN_4(a, b, c, d)		 Z_PASTE_4(a, b, c, d)
#define Z_JOIN_5(a, b, c, d, e)		 Z_PASTE_5(a, b, c, d, e)
#define Z_JOIN_6(a, b, c, d, e, f)	 Z_PASTE_6(a, b, c, d, e, f)
#define Z_JOIN_7(a, b, c, d, e, f, g)	 Z_PASTE_7(a, b, c, d, e, f, g)
#define Z_JOIN_8(a, b, c, d, e, f, g, h) Z_PASTE_8(a, b, c, d, e, f, g, h)

#define Z_INSERT_NUMBER_8(   left, right) left##8##right
#define Z_INSERT_NUMBER_16(  left, right) left##16##right
#define Z_INSERT_NUMBER_24(  left, right) left##24##right
#define Z_INSERT_NUMBER_32(  left, right) left##32##right
#define Z_INSERT_NUMBER_48(  left, right) left##48##right
#define Z_INSERT_NUMBER_64(  left, right) left##64##right
#define Z_INSERT_NUMBER_72(  left, right) left##72##right
#define Z_INSERT_NUMBER_80(  left, right) left##80##right
#define Z_INSERT_NUMBER_96(  left, right) left##96##right
#define Z_INSERT_NUMBER_128( left, right) left##128##right
#define Z_INSERT_NUMBER_256( left, right) left##256##right
#define Z_INSERT_NUMBER_512( left, right) left##512##right
#define Z_INSERT_NUMBER_1024(left, right) left##1024##right

#ifndef Z_AVOID_VARIADIC_MACROS

#	define L_PP_ARG_N( \
		 _1,  _2,  _3,	_4,  _5,  _6,  _7,  _8, \
		 _9, _10, _11, _12, _13, _14, _15, _16, \
		_17, _18, _19, _20, _21, _22, _23, _24, \
		_25, _26, _27, _28, _29, _30, _31, _32, \
		_33, _34, _35, _36, _37, _38, _39, _40, \
		_41, _42, _43, _44, _45, _46, _47, _48, \
		_49, _50, _51, _52, _53, _54, _55, _56, \
		_57, _58, _59, _60, _61, _62, _63,   N, \
		... \
	) N

#	define L_PP_RSEQ_N() \
		63, 62, 61, 60, 59, 58, 57, 56, \
		55, 54, 53, 52, 51, 50, 49, 48, \
		47, 46, 45, 44, 43, 42, 41, 40, \
		39, 38, 37, 36, 35, 34, 33, 32, \
		31, 30, 29, 28, 27, 26, 25, 24, \
		23, 22, 21, 20, 19, 18, 17, 16, \
		15, 14, 13, 12, 11, 10,  9,  8, \
		 7,  6,  5,  4,  3,  2,  1,  0

#	define Z_ARGUMENT_COUNT_(...) Z_SAME(L_PP_ARG_N(__VA_ARGS__))
#	define Z_ARGUMENT_COUNT( ...) Z_ARGUMENT_COUNT_(__VA_ARGS__, L_PP_RSEQ_N())
#	define Z_JOIN_N(	 n  ) Z_PASTE_2(Z_JOIN_, n) /* Needed for Z_JOIN(...) only */
#	define Z_JOIN(		 ...) Z_SAME(Z_JOIN_N(Z_ARGUMENT_COUNT_(__VA_ARGS__, L_PP_RSEQ_N())))(__VA_ARGS__)

#endif

#endif /* __Z_macros_preprocessor_H__ */
