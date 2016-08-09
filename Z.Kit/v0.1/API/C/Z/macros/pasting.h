/* Z Kit C API - macros/pasting.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_macros_pasting_H__
#define __Z_macros_pasting_H__

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
#define Z_EXPAND_SUFFIX_U(  what) what##U
#define Z_EXPAND_SUFFIX_UL( what) what##UL
#define Z_EXPAND_SUFFIX_ULL(what) what##ULL

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
#define Z_SUFFIX_U(  what) Z_EXPAND_SUFFIX_U  (what)
#define Z_SUFFIX_UL( what) Z_EXPAND_SUFFIX_UL (what)
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

#endif /* __Z_macros_pasting_H__ */
