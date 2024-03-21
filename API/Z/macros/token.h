/* Zeta API - Z/macros/token.h
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_macros_token_H
#define Z_macros_token_H

#define Z_COMMA ,

#define Z_z_EMPTY(dummy)
#define Z_EMPTY Z_z_EMPTY(~)

#define Z_SAME(token) token

#define Z_z_STRINGIFY(token) #token
#define Z_STRINGIFY( token) Z_z_STRINGIFY(token)

#define Z_z_PREFIX_0(	 rht)   0##rht
#define Z_z_PREFIX_0x(	 rht)  0x##rht
#define Z_z_PREFIX_0b(	 rht)  0b##rht
#define Z_z_PREFIX_Z(	 rht)   Z##rht
#define Z_z_PREFIX_Z_(	 rht)  Z_##rht
#define Z_z_PREFIX_z(	 rht)   z##rht
#define Z_z_PREFIX_z_(	 rht)  z_##rht
#define Z_z_SUFFIX_D32(	 lht) lht##D32
#define Z_z_SUFFIX_D64(	 lht) lht##D64
#define Z_z_SUFFIX_D64x( lht) lht##D64x
#define Z_z_SUFFIX_D128( lht) lht##D128
#define Z_z_SUFFIX_D128x(lht) lht##D128x
#define Z_z_SUFFIX_DD(	 lht) lht##DD
#define Z_z_SUFFIX_DF(	 lht) lht##DF
#define Z_z_SUFFIX_DL(	 lht) lht##DL
#define Z_z_SUFFIX_F(	 lht) lht##F
#define Z_z_SUFFIX_F16(	 lht) lht##F16
#define Z_z_SUFFIX_F32(	 lht) lht##F32
#define Z_z_SUFFIX_F32x( lht) lht##F32x
#define Z_z_SUFFIX_F64(	 lht) lht##F64
#define Z_z_SUFFIX_F64x( lht) lht##F64x
#define Z_z_SUFFIX_F128( lht) lht##F128
#define Z_z_SUFFIX_F128x(lht) lht##F128x
#define Z_z_SUFFIX_i32(	 lht) lht##i32
#define Z_z_SUFFIX_i64(	 lht) lht##i64
#define Z_z_SUFFIX_L(	 lht) lht##L
#define Z_z_SUFFIX_LL(	 lht) lht##LL
#define Z_z_SUFFIX_Q(	 lht) lht##Q
#define Z_z_SUFFIX_U(	 lht) lht##U
#define Z_z_SUFFIX_Ui32( lht) lht##Ui32
#define Z_z_SUFFIX_Ui64( lht) lht##Ui64
#define Z_z_SUFFIX_UL(	 lht) lht##UL
#define Z_z_SUFFIX_ULL(	 lht) lht##ULL
#define Z_z_SUFFIX_UZ(	 lht) lht##UZ
#define Z_z_SUFFIX_W(	 lht) lht##W
#define Z_z_SUFFIX_Z(	 lht) lht##Z

#define Z_PREFIX_	    Z_SAME
#define Z_PREFIX_0(    rht) Z_z_PREFIX_0    (rht)
#define Z_PREFIX_0x(   rht) Z_z_PREFIX_0x   (rht)
#define Z_PREFIX_0b(   rht) Z_z_PREFIX_0b   (rht)
#define Z_PREFIX_Z(    rht) Z_z_PREFIX_Z    (rht)
#define Z_PREFIX_Z_(   rht) Z_z_PREFIX_Z_   (rht)
#define Z_PREFIX_z(    rht) Z_z_PREFIX_z    (rht)
#define Z_PREFIX_z_(   rht) Z_z_PREFIX_z_   (rht)
#define Z_SUFFIX_	    Z_SAME
#define Z_SUFFIX_D32(  lht) Z_z_SUFFIX_D32  (lht)
#define Z_SUFFIX_D64(  lht) Z_z_SUFFIX_D64  (lht)
#define Z_SUFFIX_D64x( lht) Z_z_SUFFIX_D64x (lht)
#define Z_SUFFIX_D128( lht) Z_z_SUFFIX_D128 (lht)
#define Z_SUFFIX_D128x(lht) Z_z_SUFFIX_D128x(lht)
#define Z_SUFFIX_DD(   lht) Z_z_SUFFIX_DD   (lht)
#define Z_SUFFIX_DF(   lht) Z_z_SUFFIX_DF   (lht)
#define Z_SUFFIX_DL(   lht) Z_z_SUFFIX_DL   (lht)
#define Z_SUFFIX_F(    lht) Z_z_SUFFIX_F    (lht)
#define Z_SUFFIX_F16(  lht) Z_z_SUFFIX_F16  (lht)
#define Z_SUFFIX_F32(  lht) Z_z_SUFFIX_F32  (lht)
#define Z_SUFFIX_F32x( lht) Z_z_SUFFIX_F32x (lht)
#define Z_SUFFIX_F64(  lht) Z_z_SUFFIX_F64  (lht)
#define Z_SUFFIX_F64x( lht) Z_z_SUFFIX_F64x (lht)
#define Z_SUFFIX_F128( lht) Z_z_SUFFIX_F128 (lht)
#define Z_SUFFIX_F128x(lht) Z_z_SUFFIX_F128x(lht)
#define Z_SUFFIX_i32(  lht) Z_z_SUFFIX_i32  (lht)
#define Z_SUFFIX_i64(  lht) Z_z_SUFFIX_i64  (lht)
#define Z_SUFFIX_L(    lht) Z_z_SUFFIX_L    (lht)
#define Z_SUFFIX_LL(   lht) Z_z_SUFFIX_LL   (lht)
#define Z_SUFFIX_Q(    lht) Z_z_SUFFIX_Q    (lht)
#define Z_SUFFIX_U(    lht) Z_z_SUFFIX_U    (lht)
#define Z_SUFFIX_Ui32( lht) Z_z_SUFFIX_Ui32 (lht)
#define Z_SUFFIX_Ui64( lht) Z_z_SUFFIX_Ui64 (lht)
#define Z_SUFFIX_UL(   lht) Z_z_SUFFIX_UL   (lht)
#define Z_SUFFIX_ULL(  lht) Z_z_SUFFIX_ULL  (lht)
#define Z_SUFFIX_UZ(   lht) Z_z_SUFFIX_UZ   (lht)
#define Z_SUFFIX_W(    lht) Z_z_SUFFIX_W    (lht)
#define Z_SUFFIX_Z(    lht) Z_z_SUFFIX_Z    (lht)

#define Z_PASTE_2( _1, _2)																		  _1##_2
#define Z_PASTE_3( _1, _2, _3)																		  _1##_2##_3
#define Z_PASTE_4( _1, _2, _3, _4)																	  _1##_2##_3##_4
#define Z_PASTE_5( _1, _2, _3, _4, _5)																	  _1##_2##_3##_4##_5
#define Z_PASTE_6( _1, _2, _3, _4, _5, _6)																  _1##_2##_3##_4##_5##_6
#define Z_PASTE_7( _1, _2, _3, _4, _5, _6, _7)																  _1##_2##_3##_4##_5##_6##_7
#define Z_PASTE_8( _1, _2, _3, _4, _5, _6, _7, _8)															  _1##_2##_3##_4##_5##_6##_7##_8
#define Z_PASTE_9( _1, _2, _3, _4, _5, _6, _7, _8, _9)															  _1##_2##_3##_4##_5##_6##_7##_8##_9
#define Z_PASTE_10(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10)														  _1##_2##_3##_4##_5##_6##_7##_8##_9##_10
#define Z_PASTE_11(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11)													  _1##_2##_3##_4##_5##_6##_7##_8##_9##_10##_11
#define Z_PASTE_12(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12)													  _1##_2##_3##_4##_5##_6##_7##_8##_9##_10##_11##_12
#define Z_PASTE_13(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13)												  _1##_2##_3##_4##_5##_6##_7##_8##_9##_10##_11##_12##_13
#define Z_PASTE_14(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14)												  _1##_2##_3##_4##_5##_6##_7##_8##_9##_10##_11##_12##_13##_14
#define Z_PASTE_15(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15)											  _1##_2##_3##_4##_5##_6##_7##_8##_9##_10##_11##_12##_13##_14##_15
#define Z_PASTE_16(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16)										  _1##_2##_3##_4##_5##_6##_7##_8##_9##_10##_11##_12##_13##_14##_15##_16
#define Z_PASTE_17(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17)										  _1##_2##_3##_4##_5##_6##_7##_8##_9##_10##_11##_12##_13##_14##_15##_16##_17
#define Z_PASTE_18(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18)									  _1##_2##_3##_4##_5##_6##_7##_8##_9##_10##_11##_12##_13##_14##_15##_16##_17##_18
#define Z_PASTE_19(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19)								  _1##_2##_3##_4##_5##_6##_7##_8##_9##_10##_11##_12##_13##_14##_15##_16##_17##_18##_19
#define Z_PASTE_20(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20)								  _1##_2##_3##_4##_5##_6##_7##_8##_9##_10##_11##_12##_13##_14##_15##_16##_17##_18##_19##_20
#define Z_PASTE_21(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21)							  _1##_2##_3##_4##_5##_6##_7##_8##_9##_10##_11##_12##_13##_14##_15##_16##_17##_18##_19##_20##_21
#define Z_PASTE_22(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22)							  _1##_2##_3##_4##_5##_6##_7##_8##_9##_10##_11##_12##_13##_14##_15##_16##_17##_18##_19##_20##_21##_22
#define Z_PASTE_23(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23)						  _1##_2##_3##_4##_5##_6##_7##_8##_9##_10##_11##_12##_13##_14##_15##_16##_17##_18##_19##_20##_21##_22##_23
#define Z_PASTE_24(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24)					  _1##_2##_3##_4##_5##_6##_7##_8##_9##_10##_11##_12##_13##_14##_15##_16##_17##_18##_19##_20##_21##_22##_23##_24
#define Z_PASTE_25(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25)					  _1##_2##_3##_4##_5##_6##_7##_8##_9##_10##_11##_12##_13##_14##_15##_16##_17##_18##_19##_20##_21##_22##_23##_24##_25
#define Z_PASTE_26(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26)				  _1##_2##_3##_4##_5##_6##_7##_8##_9##_10##_11##_12##_13##_14##_15##_16##_17##_18##_19##_20##_21##_22##_23##_24##_25##_26
#define Z_PASTE_27(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27)			  _1##_2##_3##_4##_5##_6##_7##_8##_9##_10##_11##_12##_13##_14##_15##_16##_17##_18##_19##_20##_21##_22##_23##_24##_25##_26##_27
#define Z_PASTE_28(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28)			  _1##_2##_3##_4##_5##_6##_7##_8##_9##_10##_11##_12##_13##_14##_15##_16##_17##_18##_19##_20##_21##_22##_23##_24##_25##_26##_27##_28
#define Z_PASTE_29(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29)		  _1##_2##_3##_4##_5##_6##_7##_8##_9##_10##_11##_12##_13##_14##_15##_16##_17##_18##_19##_20##_21##_22##_23##_24##_25##_26##_27##_28##_29
#define Z_PASTE_30(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30)		  _1##_2##_3##_4##_5##_6##_7##_8##_9##_10##_11##_12##_13##_14##_15##_16##_17##_18##_19##_20##_21##_22##_23##_24##_25##_26##_27##_28##_29##_30
#define Z_PASTE_31(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31)	  _1##_2##_3##_4##_5##_6##_7##_8##_9##_10##_11##_12##_13##_14##_15##_16##_17##_18##_19##_20##_21##_22##_23##_24##_25##_26##_27##_28##_29##_30##_31
#define Z_PASTE_32(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32) _1##_2##_3##_4##_5##_6##_7##_8##_9##_10##_11##_12##_13##_14##_15##_16##_17##_18##_19##_20##_21##_22##_23##_24##_25##_26##_27##_28##_29##_30##_31##_32

#define Z_JOIN_2( _1, _2)																		 Z_PASTE_2 (_1, _2)
#define Z_JOIN_3( _1, _2, _3)																		 Z_PASTE_3 (_1, _2, _3)
#define Z_JOIN_4( _1, _2, _3, _4)																	 Z_PASTE_4 (_1, _2, _3, _4)
#define Z_JOIN_5( _1, _2, _3, _4, _5)																	 Z_PASTE_5 (_1, _2, _3, _4, _5)
#define Z_JOIN_6( _1, _2, _3, _4, _5, _6)																 Z_PASTE_6 (_1, _2, _3, _4, _5, _6)
#define Z_JOIN_7( _1, _2, _3, _4, _5, _6, _7)																 Z_PASTE_7 (_1, _2, _3, _4, _5, _6, _7)
#define Z_JOIN_8( _1, _2, _3, _4, _5, _6, _7, _8)															 Z_PASTE_8 (_1, _2, _3, _4, _5, _6, _7, _8)
#define Z_JOIN_9( _1, _2, _3, _4, _5, _6, _7, _8, _9)															 Z_PASTE_9 (_1, _2, _3, _4, _5, _6, _7, _8, _9)
#define Z_JOIN_10(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10)														 Z_PASTE_10(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10)
#define Z_JOIN_11(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11)														 Z_PASTE_11(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11)
#define Z_JOIN_12(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12)													 Z_PASTE_12(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12)
#define Z_JOIN_13(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13)												 Z_PASTE_13(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13)
#define Z_JOIN_14(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14)												 Z_PASTE_14(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14)
#define Z_JOIN_15(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15)											 Z_PASTE_15(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15)
#define Z_JOIN_16(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16)										 Z_PASTE_16(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16)
#define Z_JOIN_17(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17)										 Z_PASTE_17(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17)
#define Z_JOIN_18(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18)									 Z_PASTE_18(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18)
#define Z_JOIN_19(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19)									 Z_PASTE_19(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19)
#define Z_JOIN_20(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20)								 Z_PASTE_20(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20)
#define Z_JOIN_21(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21)							 Z_PASTE_21(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21)
#define Z_JOIN_22(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22)							 Z_PASTE_22(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22)
#define Z_JOIN_23(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23)						 Z_PASTE_23(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23)
#define Z_JOIN_24(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24)					 Z_PASTE_24(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24)
#define Z_JOIN_25(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25)					 Z_PASTE_25(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25)
#define Z_JOIN_26(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26)				 Z_PASTE_26(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26)
#define Z_JOIN_27(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27)				 Z_PASTE_27(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27)
#define Z_JOIN_28(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28)			 Z_PASTE_28(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28)
#define Z_JOIN_29(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29)		 Z_PASTE_29(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29)
#define Z_JOIN_30(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30)		 Z_PASTE_31(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30)
#define Z_JOIN_31(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31)	 Z_PASTE_31(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31)
#define Z_JOIN_32(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32) Z_PASTE_32(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32)

#define Z_APPEND_NUMBER_0(   lht) lht##0
#define Z_APPEND_NUMBER_1(   lht) lht##1
#define Z_APPEND_NUMBER_2(   lht) lht##2
#define Z_APPEND_NUMBER_3(   lht) lht##3
#define Z_APPEND_NUMBER_4(   lht) lht##4
#define Z_APPEND_NUMBER_5(   lht) lht##5
#define Z_APPEND_NUMBER_6(   lht) lht##6
#define Z_APPEND_NUMBER_7(   lht) lht##7
#define Z_APPEND_NUMBER_8(   lht) lht##8
#define Z_APPEND_NUMBER_9(   lht) lht##9
#define Z_APPEND_NUMBER_10(  lht) lht##10
#define Z_APPEND_NUMBER_11(  lht) lht##11
#define Z_APPEND_NUMBER_12(  lht) lht##12
#define Z_APPEND_NUMBER_13(  lht) lht##13
#define Z_APPEND_NUMBER_14(  lht) lht##14
#define Z_APPEND_NUMBER_15(  lht) lht##15
#define Z_APPEND_NUMBER_16(  lht) lht##16
#define Z_APPEND_NUMBER_17(  lht) lht##17
#define Z_APPEND_NUMBER_18(  lht) lht##18
#define Z_APPEND_NUMBER_19(  lht) lht##19
#define Z_APPEND_NUMBER_20(  lht) lht##20
#define Z_APPEND_NUMBER_21(  lht) lht##21
#define Z_APPEND_NUMBER_22(  lht) lht##22
#define Z_APPEND_NUMBER_23(  lht) lht##23
#define Z_APPEND_NUMBER_24(  lht) lht##24
#define Z_APPEND_NUMBER_25(  lht) lht##25
#define Z_APPEND_NUMBER_26(  lht) lht##26
#define Z_APPEND_NUMBER_27(  lht) lht##27
#define Z_APPEND_NUMBER_28(  lht) lht##28
#define Z_APPEND_NUMBER_29(  lht) lht##29
#define Z_APPEND_NUMBER_30(  lht) lht##30
#define Z_APPEND_NUMBER_31(  lht) lht##31
#define Z_APPEND_NUMBER_32(  lht) lht##32
#define Z_APPEND_NUMBER_48(  lht) lht##48
#define Z_APPEND_NUMBER_64(  lht) lht##64
#define Z_APPEND_NUMBER_72(  lht) lht##72
#define Z_APPEND_NUMBER_80(  lht) lht##80
#define Z_APPEND_NUMBER_96(  lht) lht##96
#define Z_APPEND_NUMBER_128( lht) lht##128
#define Z_APPEND_NUMBER_256( lht) lht##256
#define Z_APPEND_NUMBER_512( lht) lht##512
#define Z_APPEND_NUMBER_1024(lht) lht##1024

#define Z_PREPEND_NUMBER_0(   rht) 0##rht
#define Z_PREPEND_NUMBER_1(   rht) 1##rht
#define Z_PREPEND_NUMBER_2(   rht) 2##rht
#define Z_PREPEND_NUMBER_3(   rht) 3##rht
#define Z_PREPEND_NUMBER_4(   rht) 4##rht
#define Z_PREPEND_NUMBER_5(   rht) 5##rht
#define Z_PREPEND_NUMBER_6(   rht) 6##rht
#define Z_PREPEND_NUMBER_7(   rht) 7##rht
#define Z_PREPEND_NUMBER_8(   rht) 8##rht
#define Z_PREPEND_NUMBER_9(   rht) 9##rht
#define Z_PREPEND_NUMBER_10(  rht) 10##rht
#define Z_PREPEND_NUMBER_11(  rht) 11##rht
#define Z_PREPEND_NUMBER_12(  rht) 12##rht
#define Z_PREPEND_NUMBER_13(  rht) 13##rht
#define Z_PREPEND_NUMBER_14(  rht) 14##rht
#define Z_PREPEND_NUMBER_15(  rht) 15##rht
#define Z_PREPEND_NUMBER_16(  rht) 16##rht
#define Z_PREPEND_NUMBER_17(  rht) 17##rht
#define Z_PREPEND_NUMBER_18(  rht) 18##rht
#define Z_PREPEND_NUMBER_19(  rht) 19##rht
#define Z_PREPEND_NUMBER_20(  rht) 20##rht
#define Z_PREPEND_NUMBER_21(  rht) 21##rht
#define Z_PREPEND_NUMBER_22(  rht) 22##rht
#define Z_PREPEND_NUMBER_23(  rht) 23##rht
#define Z_PREPEND_NUMBER_24(  rht) 24##rht
#define Z_PREPEND_NUMBER_25(  rht) 25##rht
#define Z_PREPEND_NUMBER_26(  rht) 26##rht
#define Z_PREPEND_NUMBER_27(  rht) 27##rht
#define Z_PREPEND_NUMBER_28(  rht) 28##rht
#define Z_PREPEND_NUMBER_29(  rht) 29##rht
#define Z_PREPEND_NUMBER_30(  rht) 30##rht
#define Z_PREPEND_NUMBER_31(  rht) 31##rht
#define Z_PREPEND_NUMBER_32(  rht) 32##rht
#define Z_PREPEND_NUMBER_48(  rht) 48##rht
#define Z_PREPEND_NUMBER_64(  rht) 64##rht
#define Z_PREPEND_NUMBER_72(  rht) 72##rht
#define Z_PREPEND_NUMBER_80(  rht) 80##rht
#define Z_PREPEND_NUMBER_96(  rht) 96##rht
#define Z_PREPEND_NUMBER_128( rht) 128##rht
#define Z_PREPEND_NUMBER_256( rht) 256##rht
#define Z_PREPEND_NUMBER_512( rht) 512##rht
#define Z_PREPEND_NUMBER_1024(rht) 1024##rht

#define Z_INSERT_NUMBER_0(   lht, rht) lht##0##rht
#define Z_INSERT_NUMBER_1(   lht, rht) lht##1##rht
#define Z_INSERT_NUMBER_2(   lht, rht) lht##2##rht
#define Z_INSERT_NUMBER_3(   lht, rht) lht##3##rht
#define Z_INSERT_NUMBER_4(   lht, rht) lht##4##rht
#define Z_INSERT_NUMBER_5(   lht, rht) lht##5##rht
#define Z_INSERT_NUMBER_6(   lht, rht) lht##6##rht
#define Z_INSERT_NUMBER_7(   lht, rht) lht##7##rht
#define Z_INSERT_NUMBER_8(   lht, rht) lht##8##rht
#define Z_INSERT_NUMBER_9(   lht, rht) lht##9##rht
#define Z_INSERT_NUMBER_10(  lht, rht) lht##10##rht
#define Z_INSERT_NUMBER_11(  lht, rht) lht##11##rht
#define Z_INSERT_NUMBER_12(  lht, rht) lht##12##rht
#define Z_INSERT_NUMBER_13(  lht, rht) lht##13##rht
#define Z_INSERT_NUMBER_14(  lht, rht) lht##14##rht
#define Z_INSERT_NUMBER_15(  lht, rht) lht##15##rht
#define Z_INSERT_NUMBER_16(  lht, rht) lht##16##rht
#define Z_INSERT_NUMBER_17(  lht, rht) lht##17##rht
#define Z_INSERT_NUMBER_18(  lht, rht) lht##18##rht
#define Z_INSERT_NUMBER_19(  lht, rht) lht##19##rht
#define Z_INSERT_NUMBER_20(  lht, rht) lht##20##rht
#define Z_INSERT_NUMBER_21(  lht, rht) lht##21##rht
#define Z_INSERT_NUMBER_22(  lht, rht) lht##22##rht
#define Z_INSERT_NUMBER_23(  lht, rht) lht##23##rht
#define Z_INSERT_NUMBER_24(  lht, rht) lht##24##rht
#define Z_INSERT_NUMBER_25(  lht, rht) lht##25##rht
#define Z_INSERT_NUMBER_26(  lht, rht) lht##26##rht
#define Z_INSERT_NUMBER_27(  lht, rht) lht##27##rht
#define Z_INSERT_NUMBER_28(  lht, rht) lht##28##rht
#define Z_INSERT_NUMBER_29(  lht, rht) lht##29##rht
#define Z_INSERT_NUMBER_30(  lht, rht) lht##30##rht
#define Z_INSERT_NUMBER_31(  lht, rht) lht##31##rht
#define Z_INSERT_NUMBER_32(  lht, rht) lht##32##rht
#define Z_INSERT_NUMBER_48(  lht, rht) lht##48##rht
#define Z_INSERT_NUMBER_64(  lht, rht) lht##64##rht
#define Z_INSERT_NUMBER_72(  lht, rht) lht##72##rht
#define Z_INSERT_NUMBER_80(  lht, rht) lht##80##rht
#define Z_INSERT_NUMBER_96(  lht, rht) lht##96##rht
#define Z_INSERT_NUMBER_128( lht, rht) lht##128##rht
#define Z_INSERT_NUMBER_256( lht, rht) lht##256##rht
#define Z_INSERT_NUMBER_512( lht, rht) lht##512##rht
#define Z_INSERT_NUMBER_1024(lht, rht) lht##1024##rht

#define Z_z_IS_RESULT(padding1, result, padding2, padding3) result

#define Z_z_IS_TEST(split, merge_begin, merge_end) \
	Z_SAME(Z_z_IS_RESULT(~ split 1, 0, ~ merge_begin , merge_end ~))

#define Z_z_IS_NOT_TEST(split, merge_begin, merge_end) \
	Z_SAME(Z_z_IS_RESULT(~ split 0, 1, ~ merge_begin , merge_end ~))

#define Z_z_IS_0_SPLIT_0       ,
#define Z_z_IS_0_MERGE_BEGIN_0 Z_EMPTY (
#define Z_z_IS_0_MERGE_END_0   Z_EMPTY )
#define Z_z_IS_1_SPLIT_1       ,
#define Z_z_IS_1_MERGE_BEGIN_1 Z_EMPTY (
#define Z_z_IS_1_MERGE_END_1   Z_EMPTY )

#define Z_IS_0(token) Z_z_IS_TEST(		\
	Z_JOIN_2(Z_z_IS_0_SPLIT_,	token), \
	Z_JOIN_2(Z_z_IS_0_MERGE_BEGIN_, token), \
	Z_JOIN_2(Z_z_IS_0_MERGE_END_,	token))

#define Z_IS_1(token) Z_z_IS_TEST(		\
	Z_JOIN_2(Z_z_IS_1_SPLIT_,	token), \
	Z_JOIN_2(Z_z_IS_1_MERGE_BEGIN_, token), \
	Z_JOIN_2(Z_z_IS_1_MERGE_END_,	token))

#define Z_IS_NOT_0(token) Z_z_IS_NOT_TEST(	\
	Z_JOIN_2(Z_z_IS_0_SPLIT_,	token), \
	Z_JOIN_2(Z_z_IS_0_MERGE_BEGIN_, token), \
	Z_JOIN_2(Z_z_IS_0_MERGE_END_,	token))

#define Z_IS_NOT_1(token) Z_z_IS_NOT_TEST(	\
	Z_JOIN_2(Z_z_IS_1_SPLIT_,	token), \
	Z_JOIN_2(Z_z_IS_1_MERGE_BEGIN_, token), \
	Z_JOIN_2(Z_z_IS_1_MERGE_END_,	token))

#define Z_BOOLEANIZE Z_IS_NOT_0
#define Z_NOT	     Z_IS_0
#define Z_IS_TRUE    Z_IS_1
#define Z_IS_FALSE   Z_IS_0

#define Z_z_IF_1(body) body
#define Z_z_IF_0(body)

#define Z_IF(booleanizable) \
	Z_JOIN_2(Z_z_IF_, Z_BOOLEANIZE(booleanizable))

#define Z_z_UNLESS_1(body)
#define Z_z_UNLESS_0(body) body

#define Z_UNLESS(booleanizable) \
	Z_JOIN_2(Z_z_UNLESS_, Z_BOOLEANIZE(booleanizable))

#define Z_z_TERNARY_1(a, b) a
#define Z_z_TERNARY_0(a, b) b

#define Z_TERNARY(booleanizable) \
	Z_JOIN_2(Z_z_TERNARY_, Z_BOOLEANIZE(booleanizable))

#define Z_z_APPEND_TERNARY_1(lht, a, b) lht##a
#define Z_z_APPEND_TERNARY_0(lht, a, b) lht##b

#define Z_APPEND_TERNARY(booleanizable) \
	Z_JOIN_2(Z_z_APPEND_TERNARY_, Z_BOOLEANIZE(booleanizable))

#define Z_z_PREPEND_TERNARY_1(rht, a, b) a##rht
#define Z_z_PREPEND_TERNARY_0(rht, a, b) b##rht

#define Z_PREPEND_TERNARY(booleanizable) \
	Z_JOIN_2(Z_z_PREPEND_TERNARY_, Z_BOOLEANIZE(booleanizable))

#define Z_z_INSERT_TERNARY_1(lht, rht, a, b) lht##a##rht
#define Z_z_INSERT_TERNARY_0(lht, rht, a, b) lht##b##rht

#define Z_INSERT_TERNARY(booleanizable) \
	Z_JOIN_2(Z_z_INSERT_TERNARY_, Z_BOOLEANIZE(booleanizable))

#endif /* Z_macros_token_H */
