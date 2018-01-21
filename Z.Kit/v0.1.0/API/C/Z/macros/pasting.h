/* Z Kit C API - macros/pasting.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_macros_pasting_H__
#define __Z_macros_pasting_H__

#define Z_EMPTY_(dummy)
#define Z_EMPTY Z_EMPTY_(.)

#define Z_QUOTED_(what) #what
#define Z_QUOTED( what) Z_QUOTED_(what)
#define Z_SAME(	  what) what

#define Z_EXPAND_PREFIX_0(  what) 0##what
#define Z_EXPAND_PREFIX_0x( what) 0x##what
#define Z_EXPAND_PREFIX_Z(  what) Z##what
#define Z_EXPAND_PREFIX_Z_( what) Z_##what
#define Z_EXPAND_PREFIX_z(  what) z##what
#define Z_EXPAND_PREFIX_z_( what) z_##what
#define Z_EXPAND_PREFIX_zb_(what) zb_##what
#define Z_EXPAND_SUFFIX_DD( what) what##DD
#define Z_EXPAND_SUFFIX_DF( what) what##DF
#define Z_EXPAND_SUFFIX_DL( what) what##DL
#define Z_EXPAND_SUFFIX_F(  what) what##F
#define Z_EXPAND_SUFFIX_L(  what) what##L
#define Z_EXPAND_SUFFIX_LL( what) what##LL
#define Z_EXPAND_SUFFIX_Q(  what) what##Q
#define Z_EXPAND_SUFFIX_U(  what) what##U
#define Z_EXPAND_SUFFIX_UL( what) what##UL
#define Z_EXPAND_SUFFIX_ULL(what) what##ULL
#define Z_EXPAND_SUFFIX_W(  what) what##W

#define Z_PREFIX_	   Z_SAME
#define Z_PREFIX_0(  what) Z_EXPAND_PREFIX_0  (what)
#define Z_PREFIX_0x( what) Z_EXPAND_PREFIX_0x (what)
#define Z_PREFIX_Z(  what) Z_EXPAND_PREFIX_Z  (what)
#define Z_PREFIX_Z_( what) Z_EXPAND_PREFIX_Z_ (what)
#define Z_PREFIX_z(  what) Z_EXPAND_PREFIX_z  (what)
#define Z_PREFIX_z_( what) Z_EXPAND_PREFIX_z_ (what)
#define Z_PREFIX_zb_(what) Z_EXPAND_PREFIX_zb_(what)
#define Z_SUFFIX_	   Z_SAME
#define Z_SUFFIX_DD( what) Z_EXPAND_SUFFIX_DD (what)
#define Z_SUFFIX_DF( what) Z_EXPAND_SUFFIX_DF (what)
#define Z_SUFFIX_DL( what) Z_EXPAND_SUFFIX_DL (what)
#define Z_SUFFIX_F(  what) Z_EXPAND_SUFFIX_F  (what)
#define Z_SUFFIX_L(  what) Z_EXPAND_SUFFIX_L  (what)
#define Z_SUFFIX_LL( what) Z_EXPAND_SUFFIX_LL (what)
#define Z_SUFFIX_Q(  what) Z_EXPAND_SUFFIX_Q  (what)
#define Z_SUFFIX_U(  what) Z_EXPAND_SUFFIX_U  (what)
#define Z_SUFFIX_UL( what) Z_EXPAND_SUFFIX_UL (what)
#define Z_SUFFIX_ULL(what) Z_EXPAND_SUFFIX_ULL(what)
#define Z_SUFFIX_W(  what) Z_EXPAND_SUFFIX_W  (what)

#define Z_EXPAND_UNDERSCORE_(	       what) _##what##_
#define Z_EXPAND_UNDERSCORE_X2_(       what) __##what##__
#define Z_EXPAND_PREFIX_UNDERSCORE_(   what) _##what
#define Z_EXPAND_PREFIX_UNDERSCORE_X2_(what) __##what
#define Z_EXPAND_SUFFIX_UNDERSCORE_(   what) what##_
#define Z_EXPAND_SUFFIX_UNDERSCORE_X2_(what) what##__

#define Z_UNDERSCORE(		what) Z_EXPAND_UNDERSCORE_	    (what)
#define Z_UNDERSCORE_X2(	what) Z_EXPAND_UNDERSCORE_X2_	    (what)
#define Z_PREFIX_UNDERSCORE(	what) Z_EXPAND_PREFIX_UNDERSCORE_   (what)
#define Z_PREFIX_UNDERSCORE_X2( what) Z_EXPAND_PREFIX_UNDERSCORE_X2_(what)
#define Z_SUFFIX_UNDERSCORE(	what) Z_EXPAND_SUFFIX_UNDERSCORE_   (what)
#define Z_SUFFIX_UNDERSCORE_X2( what) Z_EXPAND_SUFFIX_UNDERSCORE_X2_(what)

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

#define Z_PREPEND_NUMBER_0(   to) 0##to
#define Z_PREPEND_NUMBER_1(   to) 1##to
#define Z_PREPEND_NUMBER_2(   to) 2##to
#define Z_PREPEND_NUMBER_3(   to) 3##to
#define Z_PREPEND_NUMBER_4(   to) 4##to
#define Z_PREPEND_NUMBER_5(   to) 5##to
#define Z_PREPEND_NUMBER_6(   to) 6##to
#define Z_PREPEND_NUMBER_7(   to) 7##to
#define Z_PREPEND_NUMBER_8(   to) 8##to
#define Z_PREPEND_NUMBER_9(   to) 9##to
#define Z_PREPEND_NUMBER_10(  to) 10##to
#define Z_PREPEND_NUMBER_11(  to) 11##to
#define Z_PREPEND_NUMBER_12(  to) 12##to
#define Z_PREPEND_NUMBER_13(  to) 13##to
#define Z_PREPEND_NUMBER_14(  to) 14##to
#define Z_PREPEND_NUMBER_15(  to) 15##to
#define Z_PREPEND_NUMBER_16(  to) 16##to
#define Z_PREPEND_NUMBER_17(  to) 17##to
#define Z_PREPEND_NUMBER_18(  to) 18##to
#define Z_PREPEND_NUMBER_19(  to) 19##to
#define Z_PREPEND_NUMBER_20(  to) 20##to
#define Z_PREPEND_NUMBER_21(  to) 21##to
#define Z_PREPEND_NUMBER_22(  to) 22##to
#define Z_PREPEND_NUMBER_23(  to) 23##to
#define Z_PREPEND_NUMBER_24(  to) 24##to
#define Z_PREPEND_NUMBER_25(  to) 25##to
#define Z_PREPEND_NUMBER_26(  to) 26##to
#define Z_PREPEND_NUMBER_27(  to) 27##to
#define Z_PREPEND_NUMBER_28(  to) 28##to
#define Z_PREPEND_NUMBER_29(  to) 29##to
#define Z_PREPEND_NUMBER_30(  to) 30##to
#define Z_PREPEND_NUMBER_31(  to) 31##to
#define Z_PREPEND_NUMBER_32(  to) 32##to
#define Z_PREPEND_NUMBER_48(  to) 48##to
#define Z_PREPEND_NUMBER_64(  to) 64##to
#define Z_PREPEND_NUMBER_72(  to) 72##to
#define Z_PREPEND_NUMBER_80(  to) 80##to
#define Z_PREPEND_NUMBER_96(  to) 96##to
#define Z_PREPEND_NUMBER_128( to) 128##to
#define Z_PREPEND_NUMBER_256( to) 256##to
#define Z_PREPEND_NUMBER_512( to) 512##to
#define Z_PREPEND_NUMBER_1024(to) 1024##to

#define Z_INSERT_NUMBER_0(   left, right) left##0##right
#define Z_INSERT_NUMBER_1(   left, right) left##1##right
#define Z_INSERT_NUMBER_2(   left, right) left##2##right
#define Z_INSERT_NUMBER_3(   left, right) left##3##right
#define Z_INSERT_NUMBER_4(   left, right) left##4##right
#define Z_INSERT_NUMBER_5(   left, right) left##5##right
#define Z_INSERT_NUMBER_6(   left, right) left##6##right
#define Z_INSERT_NUMBER_7(   left, right) left##7##right
#define Z_INSERT_NUMBER_8(   left, right) left##8##right
#define Z_INSERT_NUMBER_9(   left, right) left##9##right
#define Z_INSERT_NUMBER_10(  left, right) left##10##right
#define Z_INSERT_NUMBER_11(  left, right) left##11##right
#define Z_INSERT_NUMBER_12(  left, right) left##12##right
#define Z_INSERT_NUMBER_13(  left, right) left##13##right
#define Z_INSERT_NUMBER_14(  left, right) left##14##right
#define Z_INSERT_NUMBER_15(  left, right) left##15##right
#define Z_INSERT_NUMBER_16(  left, right) left##16##right
#define Z_INSERT_NUMBER_17(  left, right) left##17##right
#define Z_INSERT_NUMBER_18(  left, right) left##18##right
#define Z_INSERT_NUMBER_19(  left, right) left##19##right
#define Z_INSERT_NUMBER_20(  left, right) left##20##right
#define Z_INSERT_NUMBER_21(  left, right) left##21##right
#define Z_INSERT_NUMBER_22(  left, right) left##22##right
#define Z_INSERT_NUMBER_23(  left, right) left##23##right
#define Z_INSERT_NUMBER_24(  left, right) left##24##right
#define Z_INSERT_NUMBER_25(  left, right) left##25##right
#define Z_INSERT_NUMBER_26(  left, right) left##26##right
#define Z_INSERT_NUMBER_27(  left, right) left##27##right
#define Z_INSERT_NUMBER_28(  left, right) left##28##right
#define Z_INSERT_NUMBER_29(  left, right) left##29##right
#define Z_INSERT_NUMBER_30(  left, right) left##30##right
#define Z_INSERT_NUMBER_31(  left, right) left##31##right
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

#define Z_APPEND_NUMBER_0(   to) to##0
#define Z_APPEND_NUMBER_1(   to) to##1
#define Z_APPEND_NUMBER_2(   to) to##2
#define Z_APPEND_NUMBER_3(   to) to##3
#define Z_APPEND_NUMBER_4(   to) to##4
#define Z_APPEND_NUMBER_5(   to) to##5
#define Z_APPEND_NUMBER_6(   to) to##6
#define Z_APPEND_NUMBER_7(   to) to##7
#define Z_APPEND_NUMBER_8(   to) to##8
#define Z_APPEND_NUMBER_9(   to) to##9
#define Z_APPEND_NUMBER_10(  to) to##10
#define Z_APPEND_NUMBER_11(  to) to##11
#define Z_APPEND_NUMBER_12(  to) to##12
#define Z_APPEND_NUMBER_13(  to) to##13
#define Z_APPEND_NUMBER_14(  to) to##14
#define Z_APPEND_NUMBER_15(  to) to##15
#define Z_APPEND_NUMBER_16(  to) to##16
#define Z_APPEND_NUMBER_17(  to) to##17
#define Z_APPEND_NUMBER_18(  to) to##18
#define Z_APPEND_NUMBER_19(  to) to##19
#define Z_APPEND_NUMBER_20(  to) to##20
#define Z_APPEND_NUMBER_21(  to) to##21
#define Z_APPEND_NUMBER_22(  to) to##22
#define Z_APPEND_NUMBER_23(  to) to##23
#define Z_APPEND_NUMBER_24(  to) to##24
#define Z_APPEND_NUMBER_25(  to) to##25
#define Z_APPEND_NUMBER_26(  to) to##26
#define Z_APPEND_NUMBER_27(  to) to##27
#define Z_APPEND_NUMBER_28(  to) to##28
#define Z_APPEND_NUMBER_29(  to) to##29
#define Z_APPEND_NUMBER_30(  to) to##30
#define Z_APPEND_NUMBER_31(  to) to##31
#define Z_APPEND_NUMBER_32(  to) to##32
#define Z_APPEND_NUMBER_48(  to) to##48
#define Z_APPEND_NUMBER_64(  to) to##64
#define Z_APPEND_NUMBER_72(  to) to##72
#define Z_APPEND_NUMBER_80(  to) to##80
#define Z_APPEND_NUMBER_96(  to) to##96
#define Z_APPEND_NUMBER_128( to) to##128
#define Z_APPEND_NUMBER_256( to) to##256
#define Z_APPEND_NUMBER_512( to) to##512
#define Z_APPEND_NUMBER_1024(to) to##1024

#define Z_TERNARY_PREPEND_1(	to, a, b) a##to
#define Z_TERNARY_PREPEND_0(	to, a, b) b##to
#define Z_TERNARY_PREPEND_TRUE( to, a, b) a##to
#define Z_TERNARY_PREPEND_FALSE(to, a, b) b##to

#define Z_TERNARY_PREPEND(condition) Z_JOIN_2(Z_TERNARY_PREPEND_, condition)

#define Z_TERNARY_INSERT_1(    left, right, a, b) left##a##right
#define Z_TERNARY_INSERT_0(    left, right, a, b) left##b##right
#define Z_TERNARY_INSERT_TRUE( left, right, a, b) left##a##right
#define Z_TERNARY_INSERT_FALSE(left, right, a, b) left##b##right

#define Z_TERNARY_INSERT(condition) Z_JOIN_2(Z_TERNARY_INSERT_, condition)

#define Z_TERNARY_APPEND_1(    to, a, b) to##a
#define Z_TERNARY_APPEND_0(    to, a, b) to##b
#define Z_TERNARY_APPEND_TRUE( to, a, b) to##a
#define Z_TERNARY_APPEND_FALSE(to, a, b) to##b

#define Z_TERNARY_APPEND(condition) Z_JOIN_2(Z_TERNARY_APPEND_, condition)

#define Z_IF_1(	   what) what
#define Z_IF_0(	   what)
#define Z_IF_TRUE( what) what
#define Z_IF_FALSE(what)

#define Z_IF(condition) Z_JOIN_2(Z_IF_, condition)

#define Z_UNLESS_1(    what)
#define Z_UNLESS_0(    what) what
#define Z_UNLESS_TRUE( what)
#define Z_UNLESS_FALSE(what) what

#define Z_UNLESS(condition) Z_JOIN_2(Z_UNLESS_, condition)

#define Z_TERNARY_1(	a, b) a
#define Z_TERNARY_0(	a, b) b
#define Z_TERNARY_TRUE( a, b) a
#define Z_TERNARY_FALSE(a, b) b

#define Z_TERNARY(condition) Z_JOIN_2(Z_TERNARY_, condition)

#endif /* __Z_macros_pasting_H__ */
