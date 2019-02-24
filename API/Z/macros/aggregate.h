/* Z Kit - macros/aggregate.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2019 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_macros_aggregate_H
#define Z_macros_aggregate_H

#include <Z/keys/order.h>
#include <Z/inspection/CPU.h>
#include <Z/inspection/language.h>
#include <Z/macros/pasting.h>

#define Z_ARRAY_SIZE(array) \
	(sizeof((array)) / sizeof((array)[0]))

#if Z_COMPILER_HAS_MACRO(MEMBER_OFFSET)
#	define Z_MEMBER_OFFSET Z_COMPILER_MACRO(MEMBER_OFFSET)

#elif Z_DIALECT_HAS_TYPE(C, LONG_LONG) || Z_DIALECT_HAS_TYPE(CPP, LONG_LONG)
#	define Z_MEMBER_OFFSET(type, member) \
		((unsigned long int)(unsigned long long int)&((type *)(0))->member)

#else
#	define Z_MEMBER_OFFSET(type, member) \
		((unsigned long int)&((type *)(0))->member)
#endif

#define Z_DEFINE_PACKED_STRUCTURE(body, type)			  \
	Z_COMPILER_DEFINE_PACKED_STRUCTURE_BEFORE_TYPEDEF typedef \
	Z_COMPILER_DEFINE_PACKED_STRUCTURE_BEFORE_STRUCT  struct  \
	Z_COMPILER_DEFINE_PACKED_STRUCTURE_BEFORE_BODY	  body	  \
	Z_COMPILER_DEFINE_PACKED_STRUCTURE_BEFORE_TYPE	  type	  \
	Z_COMPILER_DEFINE_PACKED_STRUCTURE_AFTER_TYPE

#define Z_DEFINE_PACKED_STRUCTURE_BEGIN				  \
	Z_COMPILER_DEFINE_PACKED_STRUCTURE_BEFORE_TYPEDEF typedef \
	Z_COMPILER_DEFINE_PACKED_STRUCTURE_BEFORE_STRUCT  struct  \
	Z_COMPILER_DEFINE_PACKED_STRUCTURE_BEFORE_BODY

#define Z_DEFINE_PACKED_STRUCTURE_END(type)		    \
	Z_COMPILER_DEFINE_PACKED_STRUCTURE_BEFORE_TYPE type \
	Z_COMPILER_DEFINE_PACKED_STRUCTURE_AFTER_TYPE

#define Z_DEFINE_PACKED_UNION(body, type)		      \
	Z_COMPILER_DEFINE_PACKED_UNION_BEFORE_TYPEDEF typedef \
	Z_COMPILER_DEFINE_PACKED_UNION_BEFORE_UNION   union   \
	Z_COMPILER_DEFINE_PACKED_UNION_BEFORE_BODY    body    \
	Z_COMPILER_DEFINE_PACKED_UNION_BEFORE_TYPE    type    \
	Z_COMPILER_DEFINE_PACKED_UNION_AFTER_TYPE

#define Z_DEFINE_PACKED_UNION_BEGIN			      \
	Z_COMPILER_DEFINE_PACKED_UNION_BEFORE_TYPEDEF typedef \
	Z_COMPILER_DEFINE_PACKED_UNION_BEFORE_UNION   union   \
	Z_COMPILER_DEFINE_PACKED_UNION_BEFORE_BODY

#define Z_DEFINE_PACKED_UNION_END(type)			\
	Z_COMPILER_DEFINE_PACKED_UNION_BEFORE_TYPE type	\
	Z_COMPILER_DEFINE_PACKED_UNION_AFTER_TYPE

#define Z_PACKED_NAMED_STRUCTURE(type, body)		       \
	Z_COMPILER_PACKED_NAMED_STRUCTURE_BEFORE_STRUCT struct \
	Z_COMPILER_PACKED_NAMED_STRUCTURE_BEFORE_TYPE	type   \
	Z_COMPILER_PACKED_NAMED_STRUCTURE_BEFORE_BODY	body   \
	Z_COMPILER_PACKED_NAMED_STRUCTURE_AFTER_BODY

#define Z_PACKED_NAMED_STRUCTURE_BEGIN(type)		       \
	Z_COMPILER_PACKED_NAMED_STRUCTURE_BEFORE_STRUCT struct \
	Z_COMPILER_PACKED_NAMED_STRUCTURE_BEFORE_TYPE	type   \
	Z_COMPILER_PACKED_NAMED_STRUCTURE_BEFORE_BODY

#define Z_PACKED_NAMED_STRUCTURE_END \
	Z_COMPILER_PACKED_NAMED_STRUCTURE_AFTER_BODY

#define Z_PACKED_NAMED_UNION(type, body)		 \
	Z_COMPILER_PACKED_NAMED_UNION_BEFORE_UNION union \
	Z_COMPILER_PACKED_NAMED_UNION_BEFORE_TYPE  type	 \
	Z_COMPILER_PACKED_NAMED_UNION_BEFORE_BODY  body	 \
	Z_COMPILER_PACKED_NAMED_UNION_AFTER_BODY

#define Z_PACKED_NAMED_UNION_BEGIN(type)		 \
	Z_COMPILER_PACKED_NAMED_UNION_BEFORE_UNION union \
	Z_COMPILER_PACKED_NAMED_UNION_BEFORE_TYPE  type	 \
	Z_COMPILER_PACKED_NAMED_UNION_BEFORE_BODY

#define Z_PACKED_NAMED_UNION_END \
	Z_COMPILER_PACKED_NAMED_UNION_AFTER_BODY

#define Z_PACKED_UNNAMED_STRUCTURE(body, identifier)			\
	Z_COMPILER_PACKED_UNNAMED_STRUTURE_BEFORE_STRUCT     struct	\
	Z_COMPILER_PACKED_UNNAMED_STRUTURE_BEFORE_BODY	     body	\
	Z_COMPILER_PACKED_UNNAMED_STRUTURE_BEFORE_IDENTIFIER identifier \
	Z_COMPILER_PACKED_UNNAMED_STRUTURE_AFTER_IDENTIFIER

#define Z_PACKED_UNNAMED_STRUCTURE_BEGIN			\
	Z_COMPILER_PACKED_UNNAMED_STRUTURE_BEFORE_STRUCT struct	\
	Z_COMPILER_PACKED_UNNAMED_STRUTURE_BEFORE_BODY

#define Z_PACKED_UNNAMED_STRICTURE_END(identifier)			\
	Z_COMPILER_PACKED_UNNAMED_STRUTURE_BEFORE_IDENTIFIER identifier \
	Z_COMPILER_PACKED_UNNAMED_STRUTURE_AFTER_IDENTIFIER

#define Z_PACKED_UNNAMED_UNION(body, identifier)		     \
	Z_COMPILER_PACKED_UNNAMED_UNION_BEFORE_STRUCT     union	     \
	Z_COMPILER_PACKED_UNNAMED_UNION_BEFORE_BODY	  body	     \
	Z_COMPILER_PACKED_UNNAMED_UNION_BEFORE_IDENTIFIER identifier \
	Z_COMPILER_PACKED_UNNAMED_UNION_AFTER_IDENTIFIER

#define Z_PACKED_UNNAMED_UNION_BEGIN			    \
	Z_COMPILER_PACKED_UNNAMED_UNION_BEFORE_STRUCT union \
	Z_COMPILER_PACKED_UNNAMED_UNION_BEFORE_BODY

#define Z_PACKED_UNNAMED_UNION_END(identifier)			     \
	Z_COMPILER_PACKED_UNNAMED_UNION_BEFORE_IDENTIFIER identifier \
	Z_COMPILER_PACKED_UNNAMED_UNION_AFTER_IDENTIFIER

#if Z_DIALECT_HAS(C, FLEXIBLE_ARRAY_MEMBER)
#	define Z_FAM(member) member
#else
#	define Z_FAM(member)
#endif

#define Z_MEMBERIZE_2( m1, m2)																		      m1; m2;
#define Z_MEMBERIZE_3( m1, m2, m3)																	      m1; m2; m3;
#define Z_MEMBERIZE_4( m1, m2, m3, m4)																	      m1; m2; m3; m4;
#define Z_MEMBERIZE_5( m1, m2, m3, m4, m5)																      m1; m2; m3; m4; m5;
#define Z_MEMBERIZE_6( m1, m2, m3, m4, m5, m6)																      m1; m2; m3; m4; m5; m6;
#define Z_MEMBERIZE_7( m1, m2, m3, m4, m5, m6, m7)															      m1; m2; m3; m4; m5; m6; m7;
#define Z_MEMBERIZE_8( m1, m2, m3, m4, m5, m6, m7, m8)															      m1; m2; m3; m4; m5; m6; m7; m8;
#define Z_MEMBERIZE_9( m1, m2, m3, m4, m5, m6, m7, m8, m9)														      m1; m2; m3; m4; m5; m6; m7; m8; m9;
#define Z_MEMBERIZE_10(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10)														      m1; m2; m3; m4; m5; m6; m7; m8; m9; m10;
#define Z_MEMBERIZE_11(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11)													      m1; m2; m3; m4; m5; m6; m7; m8; m9; m10; m11;
#define Z_MEMBERIZE_12(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12)												      m1; m2; m3; m4; m5; m6; m7; m8; m9; m10; m11; m12;
#define Z_MEMBERIZE_13(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13)												      m1; m2; m3; m4; m5; m6; m7; m8; m9; m10; m11; m12; m13;
#define Z_MEMBERIZE_14(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14)											      m1; m2; m3; m4; m5; m6; m7; m8; m9; m10; m11; m12; m13; m14;
#define Z_MEMBERIZE_15(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15)										      m1; m2; m3; m4; m5; m6; m7; m8; m9; m10; m11; m12; m13; m14; m15;
#define Z_MEMBERIZE_16(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16)										      m1; m2; m3; m4; m5; m6; m7; m8; m9; m10; m11; m12; m13; m14; m15; m16;
#define Z_MEMBERIZE_17(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17)									      m1; m2; m3; m4; m5; m6; m7; m8; m9; m10; m11; m12; m13; m14; m15; m16; m17;
#define Z_MEMBERIZE_18(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18)									      m1; m2; m3; m4; m5; m6; m7; m8; m9; m10; m11; m12; m13; m14; m15; m16; m17; m18;
#define Z_MEMBERIZE_19(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19)								      m1; m2; m3; m4; m5; m6; m7; m8; m9; m10; m11; m12; m13; m14; m15; m16; m17; m18; m19;
#define Z_MEMBERIZE_20(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20)							      m1; m2; m3; m4; m5; m6; m7; m8; m9; m10; m11; m12; m13; m14; m15; m16; m17; m18; m19; m20;
#define Z_MEMBERIZE_21(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21)							      m1; m2; m3; m4; m5; m6; m7; m8; m9; m10; m11; m12; m13; m14; m15; m16; m17; m18; m19; m20; m21;
#define Z_MEMBERIZE_22(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22)						      m1; m2; m3; m4; m5; m6; m7; m8; m9; m10; m11; m12; m13; m14; m15; m16; m17; m18; m19; m20; m21; m22;
#define Z_MEMBERIZE_23(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23)					      m1; m2; m3; m4; m5; m6; m7; m8; m9; m10; m11; m12; m13; m14; m15; m16; m17; m18; m19; m20; m21; m22; m23;
#define Z_MEMBERIZE_24(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24)					      m1; m2; m3; m4; m5; m6; m7; m8; m9; m10; m11; m12; m13; m14; m15; m16; m17; m18; m19; m20; m21; m22; m23; m24;
#define Z_MEMBERIZE_25(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24, m25)				      m1; m2; m3; m4; m5; m6; m7; m8; m9; m10; m11; m12; m13; m14; m15; m16; m17; m18; m19; m20; m21; m22; m23; m24; m25;
#define Z_MEMBERIZE_26(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24, m25, m26)				      m1; m2; m3; m4; m5; m6; m7; m8; m9; m10; m11; m12; m13; m14; m15; m16; m17; m18; m19; m20; m21; m22; m23; m24; m25; m26;
#define Z_MEMBERIZE_27(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24, m25, m26, m27)			      m1; m2; m3; m4; m5; m6; m7; m8; m9; m10; m11; m12; m13; m14; m15; m16; m17; m18; m19; m20; m21; m22; m23; m24; m25; m26; m27;
#define Z_MEMBERIZE_28(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24, m25, m26, m27, m28)		      m1; m2; m3; m4; m5; m6; m7; m8; m9; m10; m11; m12; m13; m14; m15; m16; m17; m18; m19; m20; m21; m22; m23; m24; m25; m26; m27; m28;
#define Z_MEMBERIZE_29(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24, m25, m26, m27, m28, m29)		      m1; m2; m3; m4; m5; m6; m7; m8; m9; m10; m11; m12; m13; m14; m15; m16; m17; m18; m19; m20; m21; m22; m23; m24; m25; m26; m27; m28; m29;
#define Z_MEMBERIZE_30(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24, m25, m26, m27, m28, m29, m30)	      m1; m2; m3; m4; m5; m6; m7; m8; m9; m10; m11; m12; m13; m14; m15; m16; m17; m18; m19; m20; m21; m22; m23; m24; m25; m26; m27; m28; m29; m30;
#define Z_MEMBERIZE_31(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24, m25, m26, m27, m28, m29, m30, m31)      m1; m2; m3; m4; m5; m6; m7; m8; m9; m10; m11; m12; m13; m14; m15; m16; m17; m18; m19; m20; m21; m22; m23; m24; m25; m26; m27; m28; m29; m30; m31;
#define Z_MEMBERIZE_32(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24, m25, m26, m27, m28, m29, m30, m31, m32) m1; m2; m3; m4; m5; m6; m7; m8; m9; m10; m11; m12; m13; m14; m15; m16; m17; m18; m19; m20; m21; m22; m23; m24; m25; m26; m27; m28; m29; m30; m31; m32;

#define Z_MEMBERIZE_REVERSED_2( m1, m2)																																				      m2; m1;
#define Z_MEMBERIZE_REVERSED_3( m1, m2, m3)																																			  m3; m2; m1;
#define Z_MEMBERIZE_REVERSED_4( m1, m2, m3, m4)																																		      m4; m3; m2; m1;
#define Z_MEMBERIZE_REVERSED_5( m1, m2, m3, m4, m5)																																	  m5; m4; m3; m2; m1;
#define Z_MEMBERIZE_REVERSED_6( m1, m2, m3, m4, m5, m6)																																      m6; m5; m4; m3; m2; m1;
#define Z_MEMBERIZE_REVERSED_7( m1, m2, m3, m4, m5, m6, m7)																															  m7; m6; m5; m4; m3; m2; m1;
#define Z_MEMBERIZE_REVERSED_8( m1, m2, m3, m4, m5, m6, m7, m8)																														      m8; m7; m6; m5; m4; m3; m2; m1;
#define Z_MEMBERIZE_REVERSED_9( m1, m2, m3, m4, m5, m6, m7, m8, m9)																													  m9; m8; m7; m6; m5; m4; m3; m2; m1;
#define Z_MEMBERIZE_REVERSED_10(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10)																											     m10; m9; m8; m7; m6; m5; m4; m3; m2; m1;
#define Z_MEMBERIZE_REVERSED_11(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11)																											m11; m10; m9; m8; m7; m6; m5; m4; m3; m2; m1;
#define Z_MEMBERIZE_REVERSED_12(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12)																									   m12; m11; m10; m9; m8; m7; m6; m5; m4; m3; m2; m1;
#define Z_MEMBERIZE_REVERSED_13(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13)																								      m13; m12; m11; m10; m9; m8; m7; m6; m5; m4; m3; m2; m1;
#define Z_MEMBERIZE_REVERSED_14(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14)																							 m14; m13; m12; m11; m10; m9; m8; m7; m6; m5; m4; m3; m2; m1;
#define Z_MEMBERIZE_REVERSED_15(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15)																					    m15; m14; m13; m12; m11; m10; m9; m8; m7; m6; m5; m4; m3; m2; m1;
#define Z_MEMBERIZE_REVERSED_16(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16)																				       m16; m15; m14; m13; m12; m11; m10; m9; m8; m7; m6; m5; m4; m3; m2; m1;
#define Z_MEMBERIZE_REVERSED_17(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17)																			  m17; m16; m15; m14; m13; m12; m11; m10; m9; m8; m7; m6; m5; m4; m3; m2; m1;
#define Z_MEMBERIZE_REVERSED_18(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18)																	     m18; m17; m16; m15; m14; m13; m12; m11; m10; m9; m8; m7; m6; m5; m4; m3; m2; m1;
#define Z_MEMBERIZE_REVERSED_19(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19)																	m19; m18; m17; m16; m15; m14; m13; m12; m11; m10; m9; m8; m7; m6; m5; m4; m3; m2; m1;
#define Z_MEMBERIZE_REVERSED_20(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20)															   m20; m19; m18; m17; m16; m15; m14; m13; m12; m11; m10; m9; m8; m7; m6; m5; m4; m3; m2; m1;
#define Z_MEMBERIZE_REVERSED_21(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21)														      m21; m20; m19; m18; m17; m16; m15; m14; m13; m12; m11; m10; m9; m8; m7; m6; m5; m4; m3; m2; m1;
#define Z_MEMBERIZE_REVERSED_22(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22)													 m22; m21; m20; m19; m18; m17; m16; m15; m14; m13; m12; m11; m10; m9; m8; m7; m6; m5; m4; m3; m2; m1;
#define Z_MEMBERIZE_REVERSED_23(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23)											    m23; m22; m21; m20; m19; m18; m17; m16; m15; m14; m13; m12; m11; m10; m9; m8; m7; m6; m5; m4; m3; m2; m1;
#define Z_MEMBERIZE_REVERSED_24(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24)										       m24; m23; m22; m21; m20; m19; m18; m17; m16; m15; m14; m13; m12; m11; m10; m9; m8; m7; m6; m5; m4; m3; m2; m1;
#define Z_MEMBERIZE_REVERSED_25(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24, m25)									  m25; m24; m23; m22; m21; m20; m19; m18; m17; m16; m15; m14; m13; m12; m11; m10; m9; m8; m7; m6; m5; m4; m3; m2; m1;
#define Z_MEMBERIZE_REVERSED_26(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24, m25, m26)							     m26; m25; m24; m23; m22; m21; m20; m19; m18; m17; m16; m15; m14; m13; m12; m11; m10; m9; m8; m7; m6; m5; m4; m3; m2; m1;
#define Z_MEMBERIZE_REVERSED_27(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24, m25, m26, m27)							m27; m26; m25; m24; m23; m22; m21; m20; m19; m18; m17; m16; m15; m14; m13; m12; m11; m10; m9; m8; m7; m6; m5; m4; m3; m2; m1;
#define Z_MEMBERIZE_REVERSED_28(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24, m25, m26, m27, m28)					   m28; m27; m26; m25; m24; m23; m22; m21; m20; m19; m18; m17; m16; m15; m14; m13; m12; m11; m10; m9; m8; m7; m6; m5; m4; m3; m2; m1;
#define Z_MEMBERIZE_REVERSED_29(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24, m25, m26, m27, m28, m29)				      m29; m28; m27; m26; m25; m24; m23; m22; m21; m20; m19; m18; m17; m16; m15; m14; m13; m12; m11; m10; m9; m8; m7; m6; m5; m4; m3; m2; m1;
#define Z_MEMBERIZE_REVERSED_30(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24, m25, m26, m27, m28, m29, m30)			 m30; m29; m28; m27; m26; m25; m24; m23; m22; m21; m20; m19; m18; m17; m16; m15; m14; m13; m12; m11; m10; m9; m8; m7; m6; m5; m4; m3; m2; m1;
#define Z_MEMBERIZE_REVERSED_31(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24, m25, m26, m27, m28, m29, m30, m31)	    m31; m30; m29; m28; m27; m26; m25; m24; m23; m22; m21; m20; m19; m18; m17; m16; m15; m14; m13; m12; m11; m10; m9; m8; m7; m6; m5; m4; m3; m2; m1;
#define Z_MEMBERIZE_REVERSED_32(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m20, m21, m22, m23, m24, m25, m26, m27, m28, m29, m30, m31, m32) m32; m31; m30; m29; m28; m27; m26; m25; m24; m23; m22; m21; m20; m19; m18; m17; m16; m15; m14; m13; m12; m11; m10; m9; m8; m7; m6; m5; m4; m3; m2; m1;

#define Z_BIT_FIELD(bits, member_count)			  \
	Z_APPEND_TERNARY(Z_COMPILER_BIT_FIELD_ORDER(bits)) \
		(Z_MEMBERIZE_, REVERSED_##member_count, member_count)

#define Z_ENDIANIZED_MEMBERS(bits, member_count)	  \
	Z_APPEND_TERNARY(Z_CPU_ENDIANNESS(INTEGRAL, bits)) \
		(Z_MEMBERIZE_, REVERSED_##member_count, member_count)

#endif /* Z_macros_aggregate_H */
