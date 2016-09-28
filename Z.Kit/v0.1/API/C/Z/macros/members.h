/* Z Kit C API - macros/members.h
	      ___
 _____	____ /	/______
/_   /_/  -_)  __/  _ /
 /____/\___/\__/ \__,_/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_macros_members_H__
#define __Z_macros_members_H__

#include <Z/inspection/compiler.h>
#include <Z/inspection/CPU.h>
#include <Z/macros/pasting.h>

#define Z_MEMBERIZE_2(		m1, m2																		     ) m1; m2;
#define Z_MEMBERIZE_3(		m1, m2, m3																	     ) m1; m2; m3;
#define Z_MEMBERIZE_4(		m1, m2, m3, m4																	     ) m1; m2; m3; m4;
#define Z_MEMBERIZE_5(		m1, m2, m3, m4, m5																     ) m1; m2; m3; m4; m5;
#define Z_MEMBERIZE_6(		m1, m2, m3, m4, m5, m6																     ) m1; m2; m3; m4; m5; m6;
#define Z_MEMBERIZE_7(		m1, m2, m3, m4, m5, m6, m7															     ) m1; m2; m3; m4; m5; m6; m7;
#define Z_MEMBERIZE_8(		m1, m2, m3, m4, m5, m6, m7, m8															     ) m1; m2; m3; m4; m5; m6; m7; m8;
#define Z_MEMBERIZE_9(		m1, m2, m3, m4, m5, m6, m7, m8, m9														     ) m1; m2; m3; m4; m5; m6; m7; m8; m9;
#define Z_MEMBERIZE_10(		m1, m2, m3, m4, m5, m6, m7, m8, m9, m10														     ) m1; m2; m3; m4; m5; m6; m7; m8; m9; m10;
#define Z_MEMBERIZE_11(		m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11													     ) m1; m2; m3; m4; m5; m6; m7; m8; m9; m10; m11;
#define Z_MEMBERIZE_12(		m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12												     ) m1; m2; m3; m4; m5; m6; m7; m8; m9; m10; m11; m12;
#define Z_MEMBERIZE_13(		m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13												     ) m1; m2; m3; m4; m5; m6; m7; m8; m9; m10; m11; m12; m13;
#define Z_MEMBERIZE_14(		m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14											     ) m1; m2; m3; m4; m5; m6; m7; m8; m9; m10; m11; m12; m13; m14;
#define Z_MEMBERIZE_15(		m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15										     ) m1; m2; m3; m4; m5; m6; m7; m8; m9; m10; m11; m12; m13; m14; m15;
#define Z_MEMBERIZE_16(		m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16										     ) m1; m2; m3; m4; m5; m6; m7; m8; m9; m10; m11; m12; m13; m14; m15; m16;
#define Z_MEMBERIZE_17(		m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17									     ) m1; m2; m3; m4; m5; m6; m7; m8; m9; m10; m11; m12; m13; m14; m15; m16; m17;
#define Z_MEMBERIZE_18(		m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18									     ) m1; m2; m3; m4; m5; m6; m7; m8; m9; m10; m11; m12; m13; m14; m15; m16; m17; m18;
#define Z_MEMBERIZE_19(		m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19								     ) m1; m2; m3; m4; m5; m6; m7; m8; m9; m10; m11; m12; m13; m14; m15; m16; m17; m18; m19;
#define Z_MEMBERIZE_20(		m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20							     ) m1; m2; m3; m4; m5; m6; m7; m8; m9; m10; m11; m12; m13; m14; m15; m16; m17; m18; m19; m20;
#define Z_MEMBERIZE_21(		m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21							     ) m1; m2; m3; m4; m5; m6; m7; m8; m9; m10; m11; m12; m13; m14; m15; m16; m17; m18; m19; m20; m21;
#define Z_MEMBERIZE_22(		m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22						     ) m1; m2; m3; m4; m5; m6; m7; m8; m9; m10; m11; m12; m13; m14; m15; m16; m17; m18; m19; m20; m21; m22;
#define Z_MEMBERIZE_23(		m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23					     ) m1; m2; m3; m4; m5; m6; m7; m8; m9; m10; m11; m12; m13; m14; m15; m16; m17; m18; m19; m20; m21; m22; m23;
#define Z_MEMBERIZE_24(		m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24					     ) m1; m2; m3; m4; m5; m6; m7; m8; m9; m10; m11; m12; m13; m14; m15; m16; m17; m18; m19; m20; m21; m22; m23; m24;
#define Z_MEMBERIZE_25(		m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24, m25				     ) m1; m2; m3; m4; m5; m6; m7; m8; m9; m10; m11; m12; m13; m14; m15; m16; m17; m18; m19; m20; m21; m22; m23; m24; m25;
#define Z_MEMBERIZE_26(		m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24, m25, m26				     ) m1; m2; m3; m4; m5; m6; m7; m8; m9; m10; m11; m12; m13; m14; m15; m16; m17; m18; m19; m20; m21; m22; m23; m24; m25; m26;
#define Z_MEMBERIZE_27(		m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24, m25, m26, m27			     ) m1; m2; m3; m4; m5; m6; m7; m8; m9; m10; m11; m12; m13; m14; m15; m16; m17; m18; m19; m20; m21; m22; m23; m24; m25; m26; m27;
#define Z_MEMBERIZE_28(		m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24, m25, m26, m27, m28		     ) m1; m2; m3; m4; m5; m6; m7; m8; m9; m10; m11; m12; m13; m14; m15; m16; m17; m18; m19; m20; m21; m22; m23; m24; m25; m26; m27; m28;
#define Z_MEMBERIZE_29(		m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24, m25, m26, m27, m28, m29		     ) m1; m2; m3; m4; m5; m6; m7; m8; m9; m10; m11; m12; m13; m14; m15; m16; m17; m18; m19; m20; m21; m22; m23; m24; m25; m26; m27; m28; m29;
#define Z_MEMBERIZE_30(		m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24, m25, m26, m27, m28, m29, m30	     ) m1; m2; m3; m4; m5; m6; m7; m8; m9; m10; m11; m12; m13; m14; m15; m16; m17; m18; m19; m20; m21; m22; m23; m24; m25; m26; m27; m28; m29; m30;
#define Z_MEMBERIZE_31(		m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24, m25, m26, m27, m28, m29, m30, m31     ) m1; m2; m3; m4; m5; m6; m7; m8; m9; m10; m11; m12; m13; m14; m15; m16; m17; m18; m19; m20; m21; m22; m23; m24; m25; m26; m27; m28; m29; m30; m31;
#define Z_MEMBERIZE_32(		m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24, m25, m26, m27, m28, m29, m30, m31, m32) m1; m2; m3; m4; m5; m6; m7; m8; m9; m10; m11; m12; m13; m14; m15; m16; m17; m18; m19; m20; m21; m22; m23; m24; m25; m26; m27; m28; m29; m30; m31; m32;
#define Z_MEMBERIZE_REVERSED_2( m1, m2																		     )																		      m2; m1;
#define Z_MEMBERIZE_REVERSED_3( m1, m2, m3																	     )																		  m3; m2; m1;
#define Z_MEMBERIZE_REVERSED_4( m1, m2, m3, m4																	     )																	      m4; m3; m2; m1;
#define Z_MEMBERIZE_REVERSED_5( m1, m2, m3, m4, m5																     )																	  m5; m4; m3; m2; m1;
#define Z_MEMBERIZE_REVERSED_6( m1, m2, m3, m4, m5, m6																     )																      m6; m5; m4; m3; m2; m1;
#define Z_MEMBERIZE_REVERSED_7( m1, m2, m3, m4, m5, m6, m7															     )																  m7; m6; m5; m4; m3; m2; m1;
#define Z_MEMBERIZE_REVERSED_8( m1, m2, m3, m4, m5, m6, m7, m8															     )															      m8; m7; m6; m5; m4; m3; m2; m1;
#define Z_MEMBERIZE_REVERSED_9( m1, m2, m3, m4, m5, m6, m7, m8, m9														     )															  m9; m8; m7; m6; m5; m4; m3; m2; m1;
#define Z_MEMBERIZE_REVERSED_10(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10														     )														     m10; m9; m8; m7; m6; m5; m4; m3; m2; m1;
#define Z_MEMBERIZE_REVERSED_11(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11													     )														m11; m10; m9; m8; m7; m6; m5; m4; m3; m2; m1;
#define Z_MEMBERIZE_REVERSED_12(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12												     )													   m12; m11; m10; m9; m8; m7; m6; m5; m4; m3; m2; m1;
#define Z_MEMBERIZE_REVERSED_13(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13												     )												      m13; m12; m11; m10; m9; m8; m7; m6; m5; m4; m3; m2; m1;
#define Z_MEMBERIZE_REVERSED_14(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14											     )												 m14; m13; m12; m11; m10; m9; m8; m7; m6; m5; m4; m3; m2; m1;
#define Z_MEMBERIZE_REVERSED_15(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15										     )											    m15; m14; m13; m12; m11; m10; m9; m8; m7; m6; m5; m4; m3; m2; m1;
#define Z_MEMBERIZE_REVERSED_16(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16										     )										       m16; m15; m14; m13; m12; m11; m10; m9; m8; m7; m6; m5; m4; m3; m2; m1;
#define Z_MEMBERIZE_REVERSED_17(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17									     )										  m17; m16; m15; m14; m13; m12; m11; m10; m9; m8; m7; m6; m5; m4; m3; m2; m1;
#define Z_MEMBERIZE_REVERSED_18(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18									     )									     m18; m17; m16; m15; m14; m13; m12; m11; m10; m9; m8; m7; m6; m5; m4; m3; m2; m1;
#define Z_MEMBERIZE_REVERSED_19(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19								     )									m19; m18; m17; m16; m15; m14; m13; m12; m11; m10; m9; m8; m7; m6; m5; m4; m3; m2; m1;
#define Z_MEMBERIZE_REVERSED_20(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20							     )								   m20; m19; m18; m17; m16; m15; m14; m13; m12; m11; m10; m9; m8; m7; m6; m5; m4; m3; m2; m1;
#define Z_MEMBERIZE_REVERSED_21(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21							     )							      m21; m20; m19; m18; m17; m16; m15; m14; m13; m12; m11; m10; m9; m8; m7; m6; m5; m4; m3; m2; m1;
#define Z_MEMBERIZE_REVERSED_22(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22						     )							 m22; m21; m20; m19; m18; m17; m16; m15; m14; m13; m12; m11; m10; m9; m8; m7; m6; m5; m4; m3; m2; m1;
#define Z_MEMBERIZE_REVERSED_23(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23					     )						    m23; m22; m21; m20; m19; m18; m17; m16; m15; m14; m13; m12; m11; m10; m9; m8; m7; m6; m5; m4; m3; m2; m1;
#define Z_MEMBERIZE_REVERSED_24(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24					     )					       m24; m23; m22; m21; m20; m19; m18; m17; m16; m15; m14; m13; m12; m11; m10; m9; m8; m7; m6; m5; m4; m3; m2; m1;
#define Z_MEMBERIZE_REVERSED_25(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24, m25				     )					  m25; m24; m23; m22; m21; m20; m19; m18; m17; m16; m15; m14; m13; m12; m11; m10; m9; m8; m7; m6; m5; m4; m3; m2; m1;
#define Z_MEMBERIZE_REVERSED_26(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24, m25, m26				     )				     m26; m25; m24; m23; m22; m21; m20; m19; m18; m17; m16; m15; m14; m13; m12; m11; m10; m9; m8; m7; m6; m5; m4; m3; m2; m1;
#define Z_MEMBERIZE_REVERSED_27(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24, m25, m26, m27			     )				m27; m26; m25; m24; m23; m22; m21; m20; m19; m18; m17; m16; m15; m14; m13; m12; m11; m10; m9; m8; m7; m6; m5; m4; m3; m2; m1;
#define Z_MEMBERIZE_REVERSED_28(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24, m25, m26, m27, m28		     )			   m28; m27; m26; m25; m24; m23; m22; m21; m20; m19; m18; m17; m16; m15; m14; m13; m12; m11; m10; m9; m8; m7; m6; m5; m4; m3; m2; m1;
#define Z_MEMBERIZE_REVERSED_29(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24, m25, m26, m27, m28, m29		     )		      m29; m28; m27; m26; m25; m24; m23; m22; m21; m20; m19; m18; m17; m16; m15; m14; m13; m12; m11; m10; m9; m8; m7; m6; m5; m4; m3; m2; m1;
#define Z_MEMBERIZE_REVERSED_30(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24, m25, m26, m27, m28, m29, m30	     )		 m30; m29; m28; m27; m26; m25; m24; m23; m22; m21; m20; m19; m18; m17; m16; m15; m14; m13; m12; m11; m10; m9; m8; m7; m6; m5; m4; m3; m2; m1;
#define Z_MEMBERIZE_REVERSED_31(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24, m25, m26, m27, m28, m29, m30, m31     )	    m31; m30; m29; m28; m27; m26; m25; m24; m23; m22; m21; m20; m19; m18; m17; m16; m15; m14; m13; m12; m11; m10; m9; m8; m7; m6; m5; m4; m3; m2; m1;
#define Z_MEMBERIZE_REVERSED_32(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24, m25, m26, m27, m28, m29, m30, m31, m32) m32; m31; m30; m29; m28; m27; m26; m25; m24; m23; m22; m21; m20; m19; m18; m17; m16; m15; m14; m13; m12; m11; m10; m9; m8; m7; m6; m5; m4; m3; m2; m1;

#if Z_COMPILER_HAS_KEY(BIT_FIELD_ORDER)

#	define Z_BIT_FIELD(bits, member_count)			  \
		Z_TERNARY_INSERT(Z_COMPILER_KEY(BIT_FIELD_ORDER)) \
			(Z_MEMBERIZE_, member_count, REVERSED_,)

#else

#	define Z_BIT_FIELD(bits, member_count)				      \
		Z_TERNARY_INSERT(Z_COMPILER_KEY(BIT_FIELD_ORDER_##bits##BIT)) \
			(Z_MEMBERIZE_, member_count, REVERSED_,)

#endif

#define Z_ENDIANIZED_MEMBERS(bits, member_count)	 \
	Z_TERNARY_INSERT(Z_CPU_INTEGER_ENDIANNESS(bits)) \
		(Z_MEMBERIZE_, member_count, REVERSED_,)

#endif /* __Z_macros_members_H__ */
