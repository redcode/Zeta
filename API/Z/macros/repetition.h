/* Z Kit - macros/repetition.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_macros_repetition_H_
#define _Z_macros_repetition_H_

#define Z_FOR_0_CALL_WITH_INDEX( f, _)
#define Z_FOR_1_CALL_WITH_INDEX( f, _) f(0)
#define Z_FOR_2_CALL_WITH_INDEX( f, _) f(0) _ f(1)
#define Z_FOR_3_CALL_WITH_INDEX( f, _) f(0) _ f(1) _ f(2)
#define Z_FOR_4_CALL_WITH_INDEX( f, _) f(0) _ f(1) _ f(2) _ f(3)
#define Z_FOR_5_CALL_WITH_INDEX( f, _) f(0) _ f(1) _ f(2) _ f(3) _ f(4)
#define Z_FOR_6_CALL_WITH_INDEX( f, _) f(0) _ f(1) _ f(2) _ f(3) _ f(4) _ f(5)
#define Z_FOR_7_CALL_WITH_INDEX( f, _) f(0) _ f(1) _ f(2) _ f(3) _ f(4) _ f(5) _ f(6)
#define Z_FOR_8_CALL_WITH_INDEX( f, _) f(0) _ f(1) _ f(2) _ f(3) _ f(4) _ f(5) _ f(6) _ f(7)
#define Z_FOR_9_CALL_WITH_INDEX( f, _) f(0) _ f(1) _ f(2) _ f(3) _ f(4) _ f(5) _ f(6) _ f(7) _ f(8)
#define Z_FOR_10_CALL_WITH_INDEX(f, _) f(0) _ f(1) _ f(2) _ f(3) _ f(4) _ f(5) _ f(6) _ f(7) _ f(8) _ f(9)
#define Z_FOR_11_CALL_WITH_INDEX(f, _) f(0) _ f(1) _ f(2) _ f(3) _ f(4) _ f(5) _ f(6) _ f(7) _ f(8) _ f(9) _ f(10)
#define Z_FOR_12_CALL_WITH_INDEX(f, _) f(0) _ f(1) _ f(2) _ f(3) _ f(4) _ f(5) _ f(6) _ f(7) _ f(8) _ f(9) _ f(10) _ f(11)
#define Z_FOR_13_CALL_WITH_INDEX(f, _) f(0) _ f(1) _ f(2) _ f(3) _ f(4) _ f(5) _ f(6) _ f(7) _ f(8) _ f(9) _ f(10) _ f(11) _ f(12)
#define Z_FOR_14_CALL_WITH_INDEX(f, _) f(0) _ f(1) _ f(2) _ f(3) _ f(4) _ f(5) _ f(6) _ f(7) _ f(8) _ f(9) _ f(10) _ f(11) _ f(12) _ f(13)
#define Z_FOR_15_CALL_WITH_INDEX(f, _) f(0) _ f(1) _ f(2) _ f(3) _ f(4) _ f(5) _ f(6) _ f(7) _ f(8) _ f(9) _ f(10) _ f(11) _ f(12) _ f(13) _ f(14)
#define Z_FOR_16_CALL_WITH_INDEX(f, _) f(0) _ f(1) _ f(2) _ f(3) _ f(4) _ f(5) _ f(6) _ f(7) _ f(8) _ f(9) _ f(10) _ f(11) _ f(12) _ f(13) _ f(14) _ f(15)
#define Z_FOR_17_CALL_WITH_INDEX(f, _) f(0) _ f(1) _ f(2) _ f(3) _ f(4) _ f(5) _ f(6) _ f(7) _ f(8) _ f(9) _ f(10) _ f(11) _ f(12) _ f(13) _ f(14) _ f(15) _ f(16)
#define Z_FOR_18_CALL_WITH_INDEX(f, _) f(0) _ f(1) _ f(2) _ f(3) _ f(4) _ f(5) _ f(6) _ f(7) _ f(8) _ f(9) _ f(10) _ f(11) _ f(12) _ f(13) _ f(14) _ f(15) _ f(16) _ f(17)
#define Z_FOR_19_CALL_WITH_INDEX(f, _) f(0) _ f(1) _ f(2) _ f(3) _ f(4) _ f(5) _ f(6) _ f(7) _ f(8) _ f(9) _ f(10) _ f(11) _ f(12) _ f(13) _ f(14) _ f(15) _ f(16) _ f(17) _ f(18)
#define Z_FOR_20_CALL_WITH_INDEX(f, _) f(0) _ f(1) _ f(2) _ f(3) _ f(4) _ f(5) _ f(6) _ f(7) _ f(8) _ f(9) _ f(10) _ f(11) _ f(12) _ f(13) _ f(14) _ f(15) _ f(16) _ f(17) _ f(18) _ f(19)
#define Z_FOR_21_CALL_WITH_INDEX(f, _) f(0) _ f(1) _ f(2) _ f(3) _ f(4) _ f(5) _ f(6) _ f(7) _ f(8) _ f(9) _ f(10) _ f(11) _ f(12) _ f(13) _ f(14) _ f(15) _ f(16) _ f(17) _ f(18) _ f(19) _ f(20)
#define Z_FOR_22_CALL_WITH_INDEX(f, _) f(0) _ f(1) _ f(2) _ f(3) _ f(4) _ f(5) _ f(6) _ f(7) _ f(8) _ f(9) _ f(10) _ f(11) _ f(12) _ f(13) _ f(14) _ f(15) _ f(16) _ f(17) _ f(18) _ f(19) _ f(20) _ f(21)
#define Z_FOR_23_CALL_WITH_INDEX(f, _) f(0) _ f(1) _ f(2) _ f(3) _ f(4) _ f(5) _ f(6) _ f(7) _ f(8) _ f(9) _ f(10) _ f(11) _ f(12) _ f(13) _ f(14) _ f(15) _ f(16) _ f(17) _ f(18) _ f(19) _ f(20) _ f(21) _ f(22)
#define Z_FOR_24_CALL_WITH_INDEX(f, _) f(0) _ f(1) _ f(2) _ f(3) _ f(4) _ f(5) _ f(6) _ f(7) _ f(8) _ f(9) _ f(10) _ f(11) _ f(12) _ f(13) _ f(14) _ f(15) _ f(16) _ f(17) _ f(18) _ f(19) _ f(20) _ f(21) _ f(22) _ f(23)
#define Z_FOR_25_CALL_WITH_INDEX(f, _) f(0) _ f(1) _ f(2) _ f(3) _ f(4) _ f(5) _ f(6) _ f(7) _ f(8) _ f(9) _ f(10) _ f(11) _ f(12) _ f(13) _ f(14) _ f(15) _ f(16) _ f(17) _ f(18) _ f(19) _ f(20) _ f(21) _ f(22) _ f(23) _ f(24)
#define Z_FOR_26_CALL_WITH_INDEX(f, _) f(0) _ f(1) _ f(2) _ f(3) _ f(4) _ f(5) _ f(6) _ f(7) _ f(8) _ f(9) _ f(10) _ f(11) _ f(12) _ f(13) _ f(14) _ f(15) _ f(16) _ f(17) _ f(18) _ f(19) _ f(20) _ f(21) _ f(22) _ f(23) _ f(24) _ f(25)
#define Z_FOR_27_CALL_WITH_INDEX(f, _) f(0) _ f(1) _ f(2) _ f(3) _ f(4) _ f(5) _ f(6) _ f(7) _ f(8) _ f(9) _ f(10) _ f(11) _ f(12) _ f(13) _ f(14) _ f(15) _ f(16) _ f(17) _ f(18) _ f(19) _ f(20) _ f(21) _ f(22) _ f(23) _ f(24) _ f(25) _ f(26)
#define Z_FOR_28_CALL_WITH_INDEX(f, _) f(0) _ f(1) _ f(2) _ f(3) _ f(4) _ f(5) _ f(6) _ f(7) _ f(8) _ f(9) _ f(10) _ f(11) _ f(12) _ f(13) _ f(14) _ f(15) _ f(16) _ f(17) _ f(18) _ f(19) _ f(20) _ f(21) _ f(22) _ f(23) _ f(24) _ f(25) _ f(26) _ f(27)
#define Z_FOR_29_CALL_WITH_INDEX(f, _) f(0) _ f(1) _ f(2) _ f(3) _ f(4) _ f(5) _ f(6) _ f(7) _ f(8) _ f(9) _ f(10) _ f(11) _ f(12) _ f(13) _ f(14) _ f(15) _ f(16) _ f(17) _ f(18) _ f(19) _ f(20) _ f(21) _ f(22) _ f(23) _ f(24) _ f(25) _ f(26) _ f(27) _ f(28)
#define Z_FOR_30_CALL_WITH_INDEX(f, _) f(0) _ f(1) _ f(2) _ f(3) _ f(4) _ f(5) _ f(6) _ f(7) _ f(8) _ f(9) _ f(10) _ f(11) _ f(12) _ f(13) _ f(14) _ f(15) _ f(16) _ f(17) _ f(18) _ f(19) _ f(20) _ f(21) _ f(22) _ f(23) _ f(24) _ f(25) _ f(26) _ f(27) _ f(28) _ f(29)
#define Z_FOR_31_CALL_WITH_INDEX(f, _) f(0) _ f(1) _ f(2) _ f(3) _ f(4) _ f(5) _ f(6) _ f(7) _ f(8) _ f(9) _ f(10) _ f(11) _ f(12) _ f(13) _ f(14) _ f(15) _ f(16) _ f(17) _ f(18) _ f(19) _ f(20) _ f(21) _ f(22) _ f(23) _ f(24) _ f(25) _ f(26) _ f(27) _ f(28) _ f(29) _ f(30)
#define Z_FOR_32_CALL_WITH_INDEX(f, _) f(0) _ f(1) _ f(2) _ f(3) _ f(4) _ f(5) _ f(6) _ f(7) _ f(8) _ f(9) _ f(10) _ f(11) _ f(12) _ f(13) _ f(14) _ f(15) _ f(16) _ f(17) _ f(18) _ f(19) _ f(20) _ f(21) _ f(22) _ f(23) _ f(24) _ f(25) _ f(26) _ f(27) _ f(28) _ f(29) _ f(30) _ f(31)

#define Z_FOR_0_CALL_WITH_TIME( f, _)
#define Z_FOR_1_CALL_WITH_TIME( f, _) f(1)
#define Z_FOR_2_CALL_WITH_TIME( f, _) f(1) _ f(2)
#define Z_FOR_3_CALL_WITH_TIME( f, _) f(1) _ f(2) _ f(3)
#define Z_FOR_4_CALL_WITH_TIME( f, _) f(1) _ f(2) _ f(3) _ f(4)
#define Z_FOR_5_CALL_WITH_TIME( f, _) f(1) _ f(2) _ f(3) _ f(4) _ f(5)
#define Z_FOR_6_CALL_WITH_TIME( f, _) f(1) _ f(2) _ f(3) _ f(4) _ f(5) _ f(6)
#define Z_FOR_7_CALL_WITH_TIME( f, _) f(1) _ f(2) _ f(3) _ f(4) _ f(5) _ f(6) _ f(7)
#define Z_FOR_8_CALL_WITH_TIME( f, _) f(1) _ f(2) _ f(3) _ f(4) _ f(5) _ f(6) _ f(7) _ f(8)
#define Z_FOR_9_CALL_WITH_TIME( f, _) f(1) _ f(2) _ f(3) _ f(4) _ f(5) _ f(6) _ f(7) _ f(8) _ f(9)
#define Z_FOR_10_CALL_WITH_TIME(f, _) f(1) _ f(2) _ f(3) _ f(4) _ f(5) _ f(6) _ f(7) _ f(8) _ f(9) _ f(10)
#define Z_FOR_11_CALL_WITH_TIME(f, _) f(1) _ f(2) _ f(3) _ f(4) _ f(5) _ f(6) _ f(7) _ f(8) _ f(9) _ f(10) _ f(11)
#define Z_FOR_12_CALL_WITH_TIME(f, _) f(1) _ f(2) _ f(3) _ f(4) _ f(5) _ f(6) _ f(7) _ f(8) _ f(9) _ f(10) _ f(11) _ f(12)
#define Z_FOR_13_CALL_WITH_TIME(f, _) f(1) _ f(2) _ f(3) _ f(4) _ f(5) _ f(6) _ f(7) _ f(8) _ f(9) _ f(10) _ f(11) _ f(12) _ f(13)
#define Z_FOR_14_CALL_WITH_TIME(f, _) f(1) _ f(2) _ f(3) _ f(4) _ f(5) _ f(6) _ f(7) _ f(8) _ f(9) _ f(10) _ f(11) _ f(12) _ f(13) _ f(14)
#define Z_FOR_15_CALL_WITH_TIME(f, _) f(1) _ f(2) _ f(3) _ f(4) _ f(5) _ f(6) _ f(7) _ f(8) _ f(9) _ f(10) _ f(11) _ f(12) _ f(13) _ f(14) _ f(15)
#define Z_FOR_16_CALL_WITH_TIME(f, _) f(1) _ f(2) _ f(3) _ f(4) _ f(5) _ f(6) _ f(7) _ f(8) _ f(9) _ f(10) _ f(11) _ f(12) _ f(13) _ f(14) _ f(15) _ f(16)
#define Z_FOR_17_CALL_WITH_TIME(f, _) f(1) _ f(2) _ f(3) _ f(4) _ f(5) _ f(6) _ f(7) _ f(8) _ f(9) _ f(10) _ f(11) _ f(12) _ f(13) _ f(14) _ f(15) _ f(16) _ f(17)
#define Z_FOR_18_CALL_WITH_TIME(f, _) f(1) _ f(2) _ f(3) _ f(4) _ f(5) _ f(6) _ f(7) _ f(8) _ f(9) _ f(10) _ f(11) _ f(12) _ f(13) _ f(14) _ f(15) _ f(16) _ f(17) _ f(18)
#define Z_FOR_19_CALL_WITH_TIME(f, _) f(1) _ f(2) _ f(3) _ f(4) _ f(5) _ f(6) _ f(7) _ f(8) _ f(9) _ f(10) _ f(11) _ f(12) _ f(13) _ f(14) _ f(15) _ f(16) _ f(17) _ f(18) _ f(19)
#define Z_FOR_20_CALL_WITH_TIME(f, _) f(1) _ f(2) _ f(3) _ f(4) _ f(5) _ f(6) _ f(7) _ f(8) _ f(9) _ f(10) _ f(11) _ f(12) _ f(13) _ f(14) _ f(15) _ f(16) _ f(17) _ f(18) _ f(19) _ f(20)
#define Z_FOR_21_CALL_WITH_TIME(f, _) f(1) _ f(2) _ f(3) _ f(4) _ f(5) _ f(6) _ f(7) _ f(8) _ f(9) _ f(10) _ f(11) _ f(12) _ f(13) _ f(14) _ f(15) _ f(16) _ f(17) _ f(18) _ f(19) _ f(20) _ f(21)
#define Z_FOR_22_CALL_WITH_TIME(f, _) f(1) _ f(2) _ f(3) _ f(4) _ f(5) _ f(6) _ f(7) _ f(8) _ f(9) _ f(10) _ f(11) _ f(12) _ f(13) _ f(14) _ f(15) _ f(16) _ f(17) _ f(18) _ f(19) _ f(20) _ f(21) _ f(22)
#define Z_FOR_23_CALL_WITH_TIME(f, _) f(1) _ f(2) _ f(3) _ f(4) _ f(5) _ f(6) _ f(7) _ f(8) _ f(9) _ f(10) _ f(11) _ f(12) _ f(13) _ f(14) _ f(15) _ f(16) _ f(17) _ f(18) _ f(19) _ f(20) _ f(21) _ f(22) _ f(23)
#define Z_FOR_24_CALL_WITH_TIME(f, _) f(1) _ f(2) _ f(3) _ f(4) _ f(5) _ f(6) _ f(7) _ f(8) _ f(9) _ f(10) _ f(11) _ f(12) _ f(13) _ f(14) _ f(15) _ f(16) _ f(17) _ f(18) _ f(19) _ f(20) _ f(21) _ f(22) _ f(23) _ f(24)
#define Z_FOR_25_CALL_WITH_TIME(f, _) f(1) _ f(2) _ f(3) _ f(4) _ f(5) _ f(6) _ f(7) _ f(8) _ f(9) _ f(10) _ f(11) _ f(12) _ f(13) _ f(14) _ f(15) _ f(16) _ f(17) _ f(18) _ f(19) _ f(20) _ f(21) _ f(22) _ f(23) _ f(24) _ f(25)
#define Z_FOR_26_CALL_WITH_TIME(f, _) f(1) _ f(2) _ f(3) _ f(4) _ f(5) _ f(6) _ f(7) _ f(8) _ f(9) _ f(10) _ f(11) _ f(12) _ f(13) _ f(14) _ f(15) _ f(16) _ f(17) _ f(18) _ f(19) _ f(20) _ f(21) _ f(22) _ f(23) _ f(24) _ f(25) _ f(26)
#define Z_FOR_27_CALL_WITH_TIME(f, _) f(1) _ f(2) _ f(3) _ f(4) _ f(5) _ f(6) _ f(7) _ f(8) _ f(9) _ f(10) _ f(11) _ f(12) _ f(13) _ f(14) _ f(15) _ f(16) _ f(17) _ f(18) _ f(19) _ f(20) _ f(21) _ f(22) _ f(23) _ f(24) _ f(25) _ f(26) _ f(27)
#define Z_FOR_28_CALL_WITH_TIME(f, _) f(1) _ f(2) _ f(3) _ f(4) _ f(5) _ f(6) _ f(7) _ f(8) _ f(9) _ f(10) _ f(11) _ f(12) _ f(13) _ f(14) _ f(15) _ f(16) _ f(17) _ f(18) _ f(19) _ f(20) _ f(21) _ f(22) _ f(23) _ f(24) _ f(25) _ f(26) _ f(27) _ f(28)
#define Z_FOR_29_CALL_WITH_TIME(f, _) f(1) _ f(2) _ f(3) _ f(4) _ f(5) _ f(6) _ f(7) _ f(8) _ f(9) _ f(10) _ f(11) _ f(12) _ f(13) _ f(14) _ f(15) _ f(16) _ f(17) _ f(18) _ f(19) _ f(20) _ f(21) _ f(22) _ f(23) _ f(24) _ f(25) _ f(26) _ f(27) _ f(28) _ f(29)
#define Z_FOR_30_CALL_WITH_TIME(f, _) f(1) _ f(2) _ f(3) _ f(4) _ f(5) _ f(6) _ f(7) _ f(8) _ f(9) _ f(10) _ f(11) _ f(12) _ f(13) _ f(14) _ f(15) _ f(16) _ f(17) _ f(18) _ f(19) _ f(20) _ f(21) _ f(22) _ f(23) _ f(24) _ f(25) _ f(26) _ f(27) _ f(28) _ f(29) _ f(30)
#define Z_FOR_31_CALL_WITH_TIME(f, _) f(1) _ f(2) _ f(3) _ f(4) _ f(5) _ f(6) _ f(7) _ f(8) _ f(9) _ f(10) _ f(11) _ f(12) _ f(13) _ f(14) _ f(15) _ f(16) _ f(17) _ f(18) _ f(19) _ f(20) _ f(21) _ f(22) _ f(23) _ f(24) _ f(25) _ f(26) _ f(27) _ f(28) _ f(29) _ f(30) _ f(31)
#define Z_FOR_32_CALL_WITH_TIME(f, _) f(1) _ f(2) _ f(3) _ f(4) _ f(5) _ f(6) _ f(7) _ f(8) _ f(9) _ f(10) _ f(11) _ f(12) _ f(13) _ f(14) _ f(15) _ f(16) _ f(17) _ f(18) _ f(19) _ f(20) _ f(21) _ f(22) _ f(23) _ f(24) _ f(25) _ f(26) _ f(27) _ f(28) _ f(29) _ f(30) _ f(31) _ f(32)

#define Z_FOR_0_CALL_WITH_TOKEN_AND_INDEX( f, t, _)
#define Z_FOR_1_CALL_WITH_TOKEN_AND_INDEX( f, t, _) f(t, 0)
#define Z_FOR_2_CALL_WITH_TOKEN_AND_INDEX( f, t, _) f(t, 0) _ f(t, 1)
#define Z_FOR_3_CALL_WITH_TOKEN_AND_INDEX( f, t, _) f(t, 0) _ f(t, 1) _ f(t, 2)
#define Z_FOR_4_CALL_WITH_TOKEN_AND_INDEX( f, t, _) f(t, 0) _ f(t, 1) _ f(t, 2) _ f(t, 3)
#define Z_FOR_5_CALL_WITH_TOKEN_AND_INDEX( f, t, _) f(t, 0) _ f(t, 1) _ f(t, 2) _ f(t, 3) _ f(t, 4)
#define Z_FOR_6_CALL_WITH_TOKEN_AND_INDEX( f, t, _) f(t, 0) _ f(t, 1) _ f(t, 2) _ f(t, 3) _ f(t, 4) _ f(t, 5)
#define Z_FOR_7_CALL_WITH_TOKEN_AND_INDEX( f, t, _) f(t, 0) _ f(t, 1) _ f(t, 2) _ f(t, 3) _ f(t, 4) _ f(t, 5) _ f(t, 6)
#define Z_FOR_8_CALL_WITH_TOKEN_AND_INDEX( f, t, _) f(t, 0) _ f(t, 1) _ f(t, 2) _ f(t, 3) _ f(t, 4) _ f(t, 5) _ f(t, 6) _ f(t, 7)
#define Z_FOR_9_CALL_WITH_TOKEN_AND_INDEX( f, t, _) f(t, 0) _ f(t, 1) _ f(t, 2) _ f(t, 3) _ f(t, 4) _ f(t, 5) _ f(t, 6) _ f(t, 7) _ f(t, 8)
#define Z_FOR_10_CALL_WITH_TOKEN_AND_INDEX(f, t, _) f(t, 0) _ f(t, 1) _ f(t, 2) _ f(t, 3) _ f(t, 4) _ f(t, 5) _ f(t, 6) _ f(t, 7) _ f(t, 8) _ f(t, 9)
#define Z_FOR_11_CALL_WITH_TOKEN_AND_INDEX(f, t, _) f(t, 0) _ f(t, 1) _ f(t, 2) _ f(t, 3) _ f(t, 4) _ f(t, 5) _ f(t, 6) _ f(t, 7) _ f(t, 8) _ f(t, 9) _ f(t, 10)
#define Z_FOR_12_CALL_WITH_TOKEN_AND_INDEX(f, t, _) f(t, 0) _ f(t, 1) _ f(t, 2) _ f(t, 3) _ f(t, 4) _ f(t, 5) _ f(t, 6) _ f(t, 7) _ f(t, 8) _ f(t, 9) _ f(t, 10) _ f(t, 11)
#define Z_FOR_13_CALL_WITH_TOKEN_AND_INDEX(f, t, _) f(t, 0) _ f(t, 1) _ f(t, 2) _ f(t, 3) _ f(t, 4) _ f(t, 5) _ f(t, 6) _ f(t, 7) _ f(t, 8) _ f(t, 9) _ f(t, 10) _ f(t, 11) _ f(t, 12)
#define Z_FOR_14_CALL_WITH_TOKEN_AND_INDEX(f, t, _) f(t, 0) _ f(t, 1) _ f(t, 2) _ f(t, 3) _ f(t, 4) _ f(t, 5) _ f(t, 6) _ f(t, 7) _ f(t, 8) _ f(t, 9) _ f(t, 10) _ f(t, 11) _ f(t, 12) _ f(t, 13)
#define Z_FOR_15_CALL_WITH_TOKEN_AND_INDEX(f, t, _) f(t, 0) _ f(t, 1) _ f(t, 2) _ f(t, 3) _ f(t, 4) _ f(t, 5) _ f(t, 6) _ f(t, 7) _ f(t, 8) _ f(t, 9) _ f(t, 10) _ f(t, 11) _ f(t, 12) _ f(t, 13) _ f(t, 14)
#define Z_FOR_16_CALL_WITH_TOKEN_AND_INDEX(f, t, _) f(t, 0) _ f(t, 1) _ f(t, 2) _ f(t, 3) _ f(t, 4) _ f(t, 5) _ f(t, 6) _ f(t, 7) _ f(t, 8) _ f(t, 9) _ f(t, 10) _ f(t, 11) _ f(t, 12) _ f(t, 13) _ f(t, 14) _ f(t, 15)
#define Z_FOR_17_CALL_WITH_TOKEN_AND_INDEX(f, t, _) f(t, 0) _ f(t, 1) _ f(t, 2) _ f(t, 3) _ f(t, 4) _ f(t, 5) _ f(t, 6) _ f(t, 7) _ f(t, 8) _ f(t, 9) _ f(t, 10) _ f(t, 11) _ f(t, 12) _ f(t, 13) _ f(t, 14) _ f(t, 15) _ f(t, 16)
#define Z_FOR_18_CALL_WITH_TOKEN_AND_INDEX(f, t, _) f(t, 0) _ f(t, 1) _ f(t, 2) _ f(t, 3) _ f(t, 4) _ f(t, 5) _ f(t, 6) _ f(t, 7) _ f(t, 8) _ f(t, 9) _ f(t, 10) _ f(t, 11) _ f(t, 12) _ f(t, 13) _ f(t, 14) _ f(t, 15) _ f(t, 16) _ f(t, 17)
#define Z_FOR_19_CALL_WITH_TOKEN_AND_INDEX(f, t, _) f(t, 0) _ f(t, 1) _ f(t, 2) _ f(t, 3) _ f(t, 4) _ f(t, 5) _ f(t, 6) _ f(t, 7) _ f(t, 8) _ f(t, 9) _ f(t, 10) _ f(t, 11) _ f(t, 12) _ f(t, 13) _ f(t, 14) _ f(t, 15) _ f(t, 16) _ f(t, 17) _ f(t, 18)
#define Z_FOR_20_CALL_WITH_TOKEN_AND_INDEX(f, t, _) f(t, 0) _ f(t, 1) _ f(t, 2) _ f(t, 3) _ f(t, 4) _ f(t, 5) _ f(t, 6) _ f(t, 7) _ f(t, 8) _ f(t, 9) _ f(t, 10) _ f(t, 11) _ f(t, 12) _ f(t, 13) _ f(t, 14) _ f(t, 15) _ f(t, 16) _ f(t, 17) _ f(t, 18) _ f(t, 19)
#define Z_FOR_21_CALL_WITH_TOKEN_AND_INDEX(f, t, _) f(t, 0) _ f(t, 1) _ f(t, 2) _ f(t, 3) _ f(t, 4) _ f(t, 5) _ f(t, 6) _ f(t, 7) _ f(t, 8) _ f(t, 9) _ f(t, 10) _ f(t, 11) _ f(t, 12) _ f(t, 13) _ f(t, 14) _ f(t, 15) _ f(t, 16) _ f(t, 17) _ f(t, 18) _ f(t, 19) _ f(t, 20)
#define Z_FOR_22_CALL_WITH_TOKEN_AND_INDEX(f, t, _) f(t, 0) _ f(t, 1) _ f(t, 2) _ f(t, 3) _ f(t, 4) _ f(t, 5) _ f(t, 6) _ f(t, 7) _ f(t, 8) _ f(t, 9) _ f(t, 10) _ f(t, 11) _ f(t, 12) _ f(t, 13) _ f(t, 14) _ f(t, 15) _ f(t, 16) _ f(t, 17) _ f(t, 18) _ f(t, 19) _ f(t, 20) _ f(t, 21)
#define Z_FOR_23_CALL_WITH_TOKEN_AND_INDEX(f, t, _) f(t, 0) _ f(t, 1) _ f(t, 2) _ f(t, 3) _ f(t, 4) _ f(t, 5) _ f(t, 6) _ f(t, 7) _ f(t, 8) _ f(t, 9) _ f(t, 10) _ f(t, 11) _ f(t, 12) _ f(t, 13) _ f(t, 14) _ f(t, 15) _ f(t, 16) _ f(t, 17) _ f(t, 18) _ f(t, 19) _ f(t, 20) _ f(t, 21) _ f(t, 22)
#define Z_FOR_24_CALL_WITH_TOKEN_AND_INDEX(f, t, _) f(t, 0) _ f(t, 1) _ f(t, 2) _ f(t, 3) _ f(t, 4) _ f(t, 5) _ f(t, 6) _ f(t, 7) _ f(t, 8) _ f(t, 9) _ f(t, 10) _ f(t, 11) _ f(t, 12) _ f(t, 13) _ f(t, 14) _ f(t, 15) _ f(t, 16) _ f(t, 17) _ f(t, 18) _ f(t, 19) _ f(t, 20) _ f(t, 21) _ f(t, 22) _ f(t, 23)
#define Z_FOR_25_CALL_WITH_TOKEN_AND_INDEX(f, t, _) f(t, 0) _ f(t, 1) _ f(t, 2) _ f(t, 3) _ f(t, 4) _ f(t, 5) _ f(t, 6) _ f(t, 7) _ f(t, 8) _ f(t, 9) _ f(t, 10) _ f(t, 11) _ f(t, 12) _ f(t, 13) _ f(t, 14) _ f(t, 15) _ f(t, 16) _ f(t, 17) _ f(t, 18) _ f(t, 19) _ f(t, 20) _ f(t, 21) _ f(t, 22) _ f(t, 23) _ f(t, 24)
#define Z_FOR_26_CALL_WITH_TOKEN_AND_INDEX(f, t, _) f(t, 0) _ f(t, 1) _ f(t, 2) _ f(t, 3) _ f(t, 4) _ f(t, 5) _ f(t, 6) _ f(t, 7) _ f(t, 8) _ f(t, 9) _ f(t, 10) _ f(t, 11) _ f(t, 12) _ f(t, 13) _ f(t, 14) _ f(t, 15) _ f(t, 16) _ f(t, 17) _ f(t, 18) _ f(t, 19) _ f(t, 20) _ f(t, 21) _ f(t, 22) _ f(t, 23) _ f(t, 24) _ f(t, 25)
#define Z_FOR_27_CALL_WITH_TOKEN_AND_INDEX(f, t, _) f(t, 0) _ f(t, 1) _ f(t, 2) _ f(t, 3) _ f(t, 4) _ f(t, 5) _ f(t, 6) _ f(t, 7) _ f(t, 8) _ f(t, 9) _ f(t, 10) _ f(t, 11) _ f(t, 12) _ f(t, 13) _ f(t, 14) _ f(t, 15) _ f(t, 16) _ f(t, 17) _ f(t, 18) _ f(t, 19) _ f(t, 20) _ f(t, 21) _ f(t, 22) _ f(t, 23) _ f(t, 24) _ f(t, 25) _ f(t, 26)
#define Z_FOR_28_CALL_WITH_TOKEN_AND_INDEX(f, t, _) f(t, 0) _ f(t, 1) _ f(t, 2) _ f(t, 3) _ f(t, 4) _ f(t, 5) _ f(t, 6) _ f(t, 7) _ f(t, 8) _ f(t, 9) _ f(t, 10) _ f(t, 11) _ f(t, 12) _ f(t, 13) _ f(t, 14) _ f(t, 15) _ f(t, 16) _ f(t, 17) _ f(t, 18) _ f(t, 19) _ f(t, 20) _ f(t, 21) _ f(t, 22) _ f(t, 23) _ f(t, 24) _ f(t, 25) _ f(t, 26) _ f(t, 27)
#define Z_FOR_29_CALL_WITH_TOKEN_AND_INDEX(f, t, _) f(t, 0) _ f(t, 1) _ f(t, 2) _ f(t, 3) _ f(t, 4) _ f(t, 5) _ f(t, 6) _ f(t, 7) _ f(t, 8) _ f(t, 9) _ f(t, 10) _ f(t, 11) _ f(t, 12) _ f(t, 13) _ f(t, 14) _ f(t, 15) _ f(t, 16) _ f(t, 17) _ f(t, 18) _ f(t, 19) _ f(t, 20) _ f(t, 21) _ f(t, 22) _ f(t, 23) _ f(t, 24) _ f(t, 25) _ f(t, 26) _ f(t, 27) _ f(t, 28)
#define Z_FOR_30_CALL_WITH_TOKEN_AND_INDEX(f, t, _) f(t, 0) _ f(t, 1) _ f(t, 2) _ f(t, 3) _ f(t, 4) _ f(t, 5) _ f(t, 6) _ f(t, 7) _ f(t, 8) _ f(t, 9) _ f(t, 10) _ f(t, 11) _ f(t, 12) _ f(t, 13) _ f(t, 14) _ f(t, 15) _ f(t, 16) _ f(t, 17) _ f(t, 18) _ f(t, 19) _ f(t, 20) _ f(t, 21) _ f(t, 22) _ f(t, 23) _ f(t, 24) _ f(t, 25) _ f(t, 26) _ f(t, 27) _ f(t, 28) _ f(t, 29)
#define Z_FOR_31_CALL_WITH_TOKEN_AND_INDEX(f, t, _) f(t, 0) _ f(t, 1) _ f(t, 2) _ f(t, 3) _ f(t, 4) _ f(t, 5) _ f(t, 6) _ f(t, 7) _ f(t, 8) _ f(t, 9) _ f(t, 10) _ f(t, 11) _ f(t, 12) _ f(t, 13) _ f(t, 14) _ f(t, 15) _ f(t, 16) _ f(t, 17) _ f(t, 18) _ f(t, 19) _ f(t, 20) _ f(t, 21) _ f(t, 22) _ f(t, 23) _ f(t, 24) _ f(t, 25) _ f(t, 26) _ f(t, 27) _ f(t, 28) _ f(t, 29) _ f(t, 30)
#define Z_FOR_32_CALL_WITH_TOKEN_AND_INDEX(f, t, _) f(t, 0) _ f(t, 1) _ f(t, 2) _ f(t, 3) _ f(t, 4) _ f(t, 5) _ f(t, 6) _ f(t, 7) _ f(t, 8) _ f(t, 9) _ f(t, 10) _ f(t, 11) _ f(t, 12) _ f(t, 13) _ f(t, 14) _ f(t, 15) _ f(t, 16) _ f(t, 17) _ f(t, 18) _ f(t, 19) _ f(t, 20) _ f(t, 21) _ f(t, 22) _ f(t, 23) _ f(t, 24) _ f(t, 25) _ f(t, 26) _ f(t, 27) _ f(t, 28) _ f(t, 29) _ f(t, 30) _ f(t, 31)

#define Z_FOR_0_CALL_WITH_TOKEN_AND_TIME( f, t, _)
#define Z_FOR_1_CALL_WITH_TOKEN_AND_TIME( f, t, _) f(t, 1)
#define Z_FOR_2_CALL_WITH_TOKEN_AND_TIME( f, t, _) f(t, 1) _ f(t, 2)
#define Z_FOR_3_CALL_WITH_TOKEN_AND_TIME( f, t, _) f(t, 1) _ f(t, 2) _ f(t, 3)
#define Z_FOR_4_CALL_WITH_TOKEN_AND_TIME( f, t, _) f(t, 1) _ f(t, 2) _ f(t, 3) _ f(t, 4)
#define Z_FOR_5_CALL_WITH_TOKEN_AND_TIME( f, t, _) f(t, 1) _ f(t, 2) _ f(t, 3) _ f(t, 4) _ f(t, 5)
#define Z_FOR_6_CALL_WITH_TOKEN_AND_TIME( f, t, _) f(t, 1) _ f(t, 2) _ f(t, 3) _ f(t, 4) _ f(t, 5) _ f(t, 6)
#define Z_FOR_7_CALL_WITH_TOKEN_AND_TIME( f, t, _) f(t, 1) _ f(t, 2) _ f(t, 3) _ f(t, 4) _ f(t, 5) _ f(t, 6) _ f(t, 7)
#define Z_FOR_8_CALL_WITH_TOKEN_AND_TIME( f, t, _) f(t, 1) _ f(t, 2) _ f(t, 3) _ f(t, 4) _ f(t, 5) _ f(t, 6) _ f(t, 7) _ f(t, 8)
#define Z_FOR_9_CALL_WITH_TOKEN_AND_TIME( f, t, _) f(t, 1) _ f(t, 2) _ f(t, 3) _ f(t, 4) _ f(t, 5) _ f(t, 6) _ f(t, 7) _ f(t, 8) _ f(t, 9)
#define Z_FOR_10_CALL_WITH_TOKEN_AND_TIME(f, t, _) f(t, 1) _ f(t, 2) _ f(t, 3) _ f(t, 4) _ f(t, 5) _ f(t, 6) _ f(t, 7) _ f(t, 8) _ f(t, 9) _ f(t, 10)
#define Z_FOR_11_CALL_WITH_TOKEN_AND_TIME(f, t, _) f(t, 1) _ f(t, 2) _ f(t, 3) _ f(t, 4) _ f(t, 5) _ f(t, 6) _ f(t, 7) _ f(t, 8) _ f(t, 9) _ f(t, 10) _ f(t, 11)
#define Z_FOR_12_CALL_WITH_TOKEN_AND_TIME(f, t, _) f(t, 1) _ f(t, 2) _ f(t, 3) _ f(t, 4) _ f(t, 5) _ f(t, 6) _ f(t, 7) _ f(t, 8) _ f(t, 9) _ f(t, 10) _ f(t, 11) _ f(t, 12)
#define Z_FOR_13_CALL_WITH_TOKEN_AND_TIME(f, t, _) f(t, 1) _ f(t, 2) _ f(t, 3) _ f(t, 4) _ f(t, 5) _ f(t, 6) _ f(t, 7) _ f(t, 8) _ f(t, 9) _ f(t, 10) _ f(t, 11) _ f(t, 12) _ f(t, 13)
#define Z_FOR_14_CALL_WITH_TOKEN_AND_TIME(f, t, _) f(t, 1) _ f(t, 2) _ f(t, 3) _ f(t, 4) _ f(t, 5) _ f(t, 6) _ f(t, 7) _ f(t, 8) _ f(t, 9) _ f(t, 10) _ f(t, 11) _ f(t, 12) _ f(t, 13) _ f(t, 14)
#define Z_FOR_15_CALL_WITH_TOKEN_AND_TIME(f, t, _) f(t, 1) _ f(t, 2) _ f(t, 3) _ f(t, 4) _ f(t, 5) _ f(t, 6) _ f(t, 7) _ f(t, 8) _ f(t, 9) _ f(t, 10) _ f(t, 11) _ f(t, 12) _ f(t, 13) _ f(t, 14) _ f(t, 15)
#define Z_FOR_16_CALL_WITH_TOKEN_AND_TIME(f, t, _) f(t, 1) _ f(t, 2) _ f(t, 3) _ f(t, 4) _ f(t, 5) _ f(t, 6) _ f(t, 7) _ f(t, 8) _ f(t, 9) _ f(t, 10) _ f(t, 11) _ f(t, 12) _ f(t, 13) _ f(t, 14) _ f(t, 15) _ f(t, 16)
#define Z_FOR_17_CALL_WITH_TOKEN_AND_TIME(f, t, _) f(t, 1) _ f(t, 2) _ f(t, 3) _ f(t, 4) _ f(t, 5) _ f(t, 6) _ f(t, 7) _ f(t, 8) _ f(t, 9) _ f(t, 10) _ f(t, 11) _ f(t, 12) _ f(t, 13) _ f(t, 14) _ f(t, 15) _ f(t, 16) _ f(t, 17)
#define Z_FOR_18_CALL_WITH_TOKEN_AND_TIME(f, t, _) f(t, 1) _ f(t, 2) _ f(t, 3) _ f(t, 4) _ f(t, 5) _ f(t, 6) _ f(t, 7) _ f(t, 8) _ f(t, 9) _ f(t, 10) _ f(t, 11) _ f(t, 12) _ f(t, 13) _ f(t, 14) _ f(t, 15) _ f(t, 16) _ f(t, 17) _ f(t, 18)
#define Z_FOR_19_CALL_WITH_TOKEN_AND_TIME(f, t, _) f(t, 1) _ f(t, 2) _ f(t, 3) _ f(t, 4) _ f(t, 5) _ f(t, 6) _ f(t, 7) _ f(t, 8) _ f(t, 9) _ f(t, 10) _ f(t, 11) _ f(t, 12) _ f(t, 13) _ f(t, 14) _ f(t, 15) _ f(t, 16) _ f(t, 17) _ f(t, 18) _ f(t, 19)
#define Z_FOR_20_CALL_WITH_TOKEN_AND_TIME(f, t, _) f(t, 1) _ f(t, 2) _ f(t, 3) _ f(t, 4) _ f(t, 5) _ f(t, 6) _ f(t, 7) _ f(t, 8) _ f(t, 9) _ f(t, 10) _ f(t, 11) _ f(t, 12) _ f(t, 13) _ f(t, 14) _ f(t, 15) _ f(t, 16) _ f(t, 17) _ f(t, 18) _ f(t, 19) _ f(t, 20)
#define Z_FOR_21_CALL_WITH_TOKEN_AND_TIME(f, t, _) f(t, 1) _ f(t, 2) _ f(t, 3) _ f(t, 4) _ f(t, 5) _ f(t, 6) _ f(t, 7) _ f(t, 8) _ f(t, 9) _ f(t, 10) _ f(t, 11) _ f(t, 12) _ f(t, 13) _ f(t, 14) _ f(t, 15) _ f(t, 16) _ f(t, 17) _ f(t, 18) _ f(t, 19) _ f(t, 20) _ f(t, 21)
#define Z_FOR_22_CALL_WITH_TOKEN_AND_TIME(f, t, _) f(t, 1) _ f(t, 2) _ f(t, 3) _ f(t, 4) _ f(t, 5) _ f(t, 6) _ f(t, 7) _ f(t, 8) _ f(t, 9) _ f(t, 10) _ f(t, 11) _ f(t, 12) _ f(t, 13) _ f(t, 14) _ f(t, 15) _ f(t, 16) _ f(t, 17) _ f(t, 18) _ f(t, 19) _ f(t, 20) _ f(t, 21) _ f(t, 22)
#define Z_FOR_23_CALL_WITH_TOKEN_AND_TIME(f, t, _) f(t, 1) _ f(t, 2) _ f(t, 3) _ f(t, 4) _ f(t, 5) _ f(t, 6) _ f(t, 7) _ f(t, 8) _ f(t, 9) _ f(t, 10) _ f(t, 11) _ f(t, 12) _ f(t, 13) _ f(t, 14) _ f(t, 15) _ f(t, 16) _ f(t, 17) _ f(t, 18) _ f(t, 19) _ f(t, 20) _ f(t, 21) _ f(t, 22) _ f(t, 23)
#define Z_FOR_24_CALL_WITH_TOKEN_AND_TIME(f, t, _) f(t, 1) _ f(t, 2) _ f(t, 3) _ f(t, 4) _ f(t, 5) _ f(t, 6) _ f(t, 7) _ f(t, 8) _ f(t, 9) _ f(t, 10) _ f(t, 11) _ f(t, 12) _ f(t, 13) _ f(t, 14) _ f(t, 15) _ f(t, 16) _ f(t, 17) _ f(t, 18) _ f(t, 19) _ f(t, 20) _ f(t, 21) _ f(t, 22) _ f(t, 23) _ f(t, 24)
#define Z_FOR_25_CALL_WITH_TOKEN_AND_TIME(f, t, _) f(t, 1) _ f(t, 2) _ f(t, 3) _ f(t, 4) _ f(t, 5) _ f(t, 6) _ f(t, 7) _ f(t, 8) _ f(t, 9) _ f(t, 10) _ f(t, 11) _ f(t, 12) _ f(t, 13) _ f(t, 14) _ f(t, 15) _ f(t, 16) _ f(t, 17) _ f(t, 18) _ f(t, 19) _ f(t, 20) _ f(t, 21) _ f(t, 22) _ f(t, 23) _ f(t, 24) _ f(t, 25)
#define Z_FOR_26_CALL_WITH_TOKEN_AND_TIME(f, t, _) f(t, 1) _ f(t, 2) _ f(t, 3) _ f(t, 4) _ f(t, 5) _ f(t, 6) _ f(t, 7) _ f(t, 8) _ f(t, 9) _ f(t, 10) _ f(t, 11) _ f(t, 12) _ f(t, 13) _ f(t, 14) _ f(t, 15) _ f(t, 16) _ f(t, 17) _ f(t, 18) _ f(t, 19) _ f(t, 20) _ f(t, 21) _ f(t, 22) _ f(t, 23) _ f(t, 24) _ f(t, 25) _ f(t, 26)
#define Z_FOR_27_CALL_WITH_TOKEN_AND_TIME(f, t, _) f(t, 1) _ f(t, 2) _ f(t, 3) _ f(t, 4) _ f(t, 5) _ f(t, 6) _ f(t, 7) _ f(t, 8) _ f(t, 9) _ f(t, 10) _ f(t, 11) _ f(t, 12) _ f(t, 13) _ f(t, 14) _ f(t, 15) _ f(t, 16) _ f(t, 17) _ f(t, 18) _ f(t, 19) _ f(t, 20) _ f(t, 21) _ f(t, 22) _ f(t, 23) _ f(t, 24) _ f(t, 25) _ f(t, 26) _ f(t, 27)
#define Z_FOR_28_CALL_WITH_TOKEN_AND_TIME(f, t, _) f(t, 1) _ f(t, 2) _ f(t, 3) _ f(t, 4) _ f(t, 5) _ f(t, 6) _ f(t, 7) _ f(t, 8) _ f(t, 9) _ f(t, 10) _ f(t, 11) _ f(t, 12) _ f(t, 13) _ f(t, 14) _ f(t, 15) _ f(t, 16) _ f(t, 17) _ f(t, 18) _ f(t, 19) _ f(t, 20) _ f(t, 21) _ f(t, 22) _ f(t, 23) _ f(t, 24) _ f(t, 25) _ f(t, 26) _ f(t, 27) _ f(t, 28)
#define Z_FOR_29_CALL_WITH_TOKEN_AND_TIME(f, t, _) f(t, 1) _ f(t, 2) _ f(t, 3) _ f(t, 4) _ f(t, 5) _ f(t, 6) _ f(t, 7) _ f(t, 8) _ f(t, 9) _ f(t, 10) _ f(t, 11) _ f(t, 12) _ f(t, 13) _ f(t, 14) _ f(t, 15) _ f(t, 16) _ f(t, 17) _ f(t, 18) _ f(t, 19) _ f(t, 20) _ f(t, 21) _ f(t, 22) _ f(t, 23) _ f(t, 24) _ f(t, 25) _ f(t, 26) _ f(t, 27) _ f(t, 28) _ f(t, 29)
#define Z_FOR_30_CALL_WITH_TOKEN_AND_TIME(f, t, _) f(t, 1) _ f(t, 2) _ f(t, 3) _ f(t, 4) _ f(t, 5) _ f(t, 6) _ f(t, 7) _ f(t, 8) _ f(t, 9) _ f(t, 10) _ f(t, 11) _ f(t, 12) _ f(t, 13) _ f(t, 14) _ f(t, 15) _ f(t, 16) _ f(t, 17) _ f(t, 18) _ f(t, 19) _ f(t, 20) _ f(t, 21) _ f(t, 22) _ f(t, 23) _ f(t, 24) _ f(t, 25) _ f(t, 26) _ f(t, 27) _ f(t, 28) _ f(t, 29) _ f(t, 30)
#define Z_FOR_31_CALL_WITH_TOKEN_AND_TIME(f, t, _) f(t, 1) _ f(t, 2) _ f(t, 3) _ f(t, 4) _ f(t, 5) _ f(t, 6) _ f(t, 7) _ f(t, 8) _ f(t, 9) _ f(t, 10) _ f(t, 11) _ f(t, 12) _ f(t, 13) _ f(t, 14) _ f(t, 15) _ f(t, 16) _ f(t, 17) _ f(t, 18) _ f(t, 19) _ f(t, 20) _ f(t, 21) _ f(t, 22) _ f(t, 23) _ f(t, 24) _ f(t, 25) _ f(t, 26) _ f(t, 27) _ f(t, 28) _ f(t, 29) _ f(t, 30) _ f(t, 31)
#define Z_FOR_32_CALL_WITH_TOKEN_AND_TIME(f, t, _) f(t, 1) _ f(t, 2) _ f(t, 3) _ f(t, 4) _ f(t, 5) _ f(t, 6) _ f(t, 7) _ f(t, 8) _ f(t, 9) _ f(t, 10) _ f(t, 11) _ f(t, 12) _ f(t, 13) _ f(t, 14) _ f(t, 15) _ f(t, 16) _ f(t, 17) _ f(t, 18) _ f(t, 19) _ f(t, 20) _ f(t, 21) _ f(t, 22) _ f(t, 23) _ f(t, 24) _ f(t, 25) _ f(t, 26) _ f(t, 27) _ f(t, 28) _ f(t, 29) _ f(t, 30) _ f(t, 31) _ f(t, 32)

#define Z_FOR_0_APPEND_INDEX( p, _)
#define Z_FOR_1_APPEND_INDEX( p, _) p##0
#define Z_FOR_2_APPEND_INDEX( p, _) p##0 _ p##1
#define Z_FOR_3_APPEND_INDEX( p, _) p##0 _ p##1 _ p##2
#define Z_FOR_4_APPEND_INDEX( p, _) p##0 _ p##1 _ p##2 _ p##3
#define Z_FOR_5_APPEND_INDEX( p, _) p##0 _ p##1 _ p##2 _ p##3 _ p##4
#define Z_FOR_6_APPEND_INDEX( p, _) p##0 _ p##1 _ p##2 _ p##3 _ p##4 _ p##5
#define Z_FOR_7_APPEND_INDEX( p, _) p##0 _ p##1 _ p##2 _ p##3 _ p##4 _ p##5 _ p##6
#define Z_FOR_8_APPEND_INDEX( p, _) p##0 _ p##1 _ p##2 _ p##3 _ p##4 _ p##5 _ p##6 _ p##7
#define Z_FOR_9_APPEND_INDEX( p, _) p##0 _ p##1 _ p##2 _ p##3 _ p##4 _ p##5 _ p##6 _ p##7 _ p##8
#define Z_FOR_10_APPEND_INDEX(p, _) p##0 _ p##1 _ p##2 _ p##3 _ p##4 _ p##5 _ p##6 _ p##7 _ p##8 _ p##9
#define Z_FOR_11_APPEND_INDEX(p, _) p##0 _ p##1 _ p##2 _ p##3 _ p##4 _ p##5 _ p##6 _ p##7 _ p##8 _ p##9 _ p##10
#define Z_FOR_12_APPEND_INDEX(p, _) p##0 _ p##1 _ p##2 _ p##3 _ p##4 _ p##5 _ p##6 _ p##7 _ p##8 _ p##9 _ p##10 _ p##11
#define Z_FOR_13_APPEND_INDEX(p, _) p##0 _ p##1 _ p##2 _ p##3 _ p##4 _ p##5 _ p##6 _ p##7 _ p##8 _ p##9 _ p##10 _ p##11 _ p##12
#define Z_FOR_14_APPEND_INDEX(p, _) p##0 _ p##1 _ p##2 _ p##3 _ p##4 _ p##5 _ p##6 _ p##7 _ p##8 _ p##9 _ p##10 _ p##11 _ p##12 _ p##13
#define Z_FOR_15_APPEND_INDEX(p, _) p##0 _ p##1 _ p##2 _ p##3 _ p##4 _ p##5 _ p##6 _ p##7 _ p##8 _ p##9 _ p##10 _ p##11 _ p##12 _ p##13 _ p##14
#define Z_FOR_16_APPEND_INDEX(p, _) p##0 _ p##1 _ p##2 _ p##3 _ p##4 _ p##5 _ p##6 _ p##7 _ p##8 _ p##9 _ p##10 _ p##11 _ p##12 _ p##13 _ p##14 _ p##15
#define Z_FOR_17_APPEND_INDEX(p, _) p##0 _ p##1 _ p##2 _ p##3 _ p##4 _ p##5 _ p##6 _ p##7 _ p##8 _ p##9 _ p##10 _ p##11 _ p##12 _ p##13 _ p##14 _ p##15 _ p##16
#define Z_FOR_18_APPEND_INDEX(p, _) p##0 _ p##1 _ p##2 _ p##3 _ p##4 _ p##5 _ p##6 _ p##7 _ p##8 _ p##9 _ p##10 _ p##11 _ p##12 _ p##13 _ p##14 _ p##15 _ p##16 _ p##17
#define Z_FOR_19_APPEND_INDEX(p, _) p##0 _ p##1 _ p##2 _ p##3 _ p##4 _ p##5 _ p##6 _ p##7 _ p##8 _ p##9 _ p##10 _ p##11 _ p##12 _ p##13 _ p##14 _ p##15 _ p##16 _ p##17 _ p##18
#define Z_FOR_20_APPEND_INDEX(p, _) p##0 _ p##1 _ p##2 _ p##3 _ p##4 _ p##5 _ p##6 _ p##7 _ p##8 _ p##9 _ p##10 _ p##11 _ p##12 _ p##13 _ p##14 _ p##15 _ p##16 _ p##17 _ p##18 _ p##19
#define Z_FOR_21_APPEND_INDEX(p, _) p##0 _ p##1 _ p##2 _ p##3 _ p##4 _ p##5 _ p##6 _ p##7 _ p##8 _ p##9 _ p##10 _ p##11 _ p##12 _ p##13 _ p##14 _ p##15 _ p##16 _ p##17 _ p##18 _ p##19 _ p##20
#define Z_FOR_22_APPEND_INDEX(p, _) p##0 _ p##1 _ p##2 _ p##3 _ p##4 _ p##5 _ p##6 _ p##7 _ p##8 _ p##9 _ p##10 _ p##11 _ p##12 _ p##13 _ p##14 _ p##15 _ p##16 _ p##17 _ p##18 _ p##19 _ p##20 _ p##21
#define Z_FOR_23_APPEND_INDEX(p, _) p##0 _ p##1 _ p##2 _ p##3 _ p##4 _ p##5 _ p##6 _ p##7 _ p##8 _ p##9 _ p##10 _ p##11 _ p##12 _ p##13 _ p##14 _ p##15 _ p##16 _ p##17 _ p##18 _ p##19 _ p##20 _ p##21 _ p##22
#define Z_FOR_24_APPEND_INDEX(p, _) p##0 _ p##1 _ p##2 _ p##3 _ p##4 _ p##5 _ p##6 _ p##7 _ p##8 _ p##9 _ p##10 _ p##11 _ p##12 _ p##13 _ p##14 _ p##15 _ p##16 _ p##17 _ p##18 _ p##19 _ p##20 _ p##21 _ p##22 _ p##23
#define Z_FOR_25_APPEND_INDEX(p, _) p##0 _ p##1 _ p##2 _ p##3 _ p##4 _ p##5 _ p##6 _ p##7 _ p##8 _ p##9 _ p##10 _ p##11 _ p##12 _ p##13 _ p##14 _ p##15 _ p##16 _ p##17 _ p##18 _ p##19 _ p##20 _ p##21 _ p##22 _ p##23 _ p##24
#define Z_FOR_26_APPEND_INDEX(p, _) p##0 _ p##1 _ p##2 _ p##3 _ p##4 _ p##5 _ p##6 _ p##7 _ p##8 _ p##9 _ p##10 _ p##11 _ p##12 _ p##13 _ p##14 _ p##15 _ p##16 _ p##17 _ p##18 _ p##19 _ p##20 _ p##21 _ p##22 _ p##23 _ p##24 _ p##25
#define Z_FOR_27_APPEND_INDEX(p, _) p##0 _ p##1 _ p##2 _ p##3 _ p##4 _ p##5 _ p##6 _ p##7 _ p##8 _ p##9 _ p##10 _ p##11 _ p##12 _ p##13 _ p##14 _ p##15 _ p##16 _ p##17 _ p##18 _ p##19 _ p##20 _ p##21 _ p##22 _ p##23 _ p##24 _ p##25 _ p##26
#define Z_FOR_28_APPEND_INDEX(p, _) p##0 _ p##1 _ p##2 _ p##3 _ p##4 _ p##5 _ p##6 _ p##7 _ p##8 _ p##9 _ p##10 _ p##11 _ p##12 _ p##13 _ p##14 _ p##15 _ p##16 _ p##17 _ p##18 _ p##19 _ p##20 _ p##21 _ p##22 _ p##23 _ p##24 _ p##25 _ p##26 _ p##27
#define Z_FOR_29_APPEND_INDEX(p, _) p##0 _ p##1 _ p##2 _ p##3 _ p##4 _ p##5 _ p##6 _ p##7 _ p##8 _ p##9 _ p##10 _ p##11 _ p##12 _ p##13 _ p##14 _ p##15 _ p##16 _ p##17 _ p##18 _ p##19 _ p##20 _ p##21 _ p##22 _ p##23 _ p##24 _ p##25 _ p##26 _ p##27 _ p##28
#define Z_FOR_30_APPEND_INDEX(p, _) p##0 _ p##1 _ p##2 _ p##3 _ p##4 _ p##5 _ p##6 _ p##7 _ p##8 _ p##9 _ p##10 _ p##11 _ p##12 _ p##13 _ p##14 _ p##15 _ p##16 _ p##17 _ p##18 _ p##19 _ p##20 _ p##21 _ p##22 _ p##23 _ p##24 _ p##25 _ p##26 _ p##27 _ p##28 _ p##29
#define Z_FOR_31_APPEND_INDEX(p, _) p##0 _ p##1 _ p##2 _ p##3 _ p##4 _ p##5 _ p##6 _ p##7 _ p##8 _ p##9 _ p##10 _ p##11 _ p##12 _ p##13 _ p##14 _ p##15 _ p##16 _ p##17 _ p##18 _ p##19 _ p##20 _ p##21 _ p##22 _ p##23 _ p##24 _ p##25 _ p##26 _ p##27 _ p##28 _ p##29 _ p##30
#define Z_FOR_32_APPEND_INDEX(p, _) p##0 _ p##1 _ p##2 _ p##3 _ p##4 _ p##5 _ p##6 _ p##7 _ p##8 _ p##9 _ p##10 _ p##11 _ p##12 _ p##13 _ p##14 _ p##15 _ p##16 _ p##17 _ p##18 _ p##19 _ p##20 _ p##21 _ p##22 _ p##23 _ p##24 _ p##25 _ p##26 _ p##27 _ p##28 _ p##29 _ p##30 _ p##31

#define Z_FOR_0_APPEND_TIME( p, _)
#define Z_FOR_1_APPEND_TIME( p, _) p##1
#define Z_FOR_2_APPEND_TIME( p, _) p##1 _ p##2
#define Z_FOR_3_APPEND_TIME( p, _) p##1 _ p##2 _ p##3
#define Z_FOR_4_APPEND_TIME( p, _) p##1 _ p##2 _ p##3 _ p##4
#define Z_FOR_5_APPEND_TIME( p, _) p##1 _ p##2 _ p##3 _ p##4 _ p##5
#define Z_FOR_6_APPEND_TIME( p, _) p##1 _ p##2 _ p##3 _ p##4 _ p##5 _ p##6
#define Z_FOR_7_APPEND_TIME( p, _) p##1 _ p##2 _ p##3 _ p##4 _ p##5 _ p##6 _ p##7
#define Z_FOR_8_APPEND_TIME( p, _) p##1 _ p##2 _ p##3 _ p##4 _ p##5 _ p##6 _ p##7 _ p##8
#define Z_FOR_9_APPEND_TIME( p, _) p##1 _ p##2 _ p##3 _ p##4 _ p##5 _ p##6 _ p##7 _ p##8 _ p##9
#define Z_FOR_10_APPEND_TIME(p, _) p##1 _ p##2 _ p##3 _ p##4 _ p##5 _ p##6 _ p##7 _ p##8 _ p##9 _ p##10
#define Z_FOR_11_APPEND_TIME(p, _) p##1 _ p##2 _ p##3 _ p##4 _ p##5 _ p##6 _ p##7 _ p##8 _ p##9 _ p##10 _ p##11
#define Z_FOR_12_APPEND_TIME(p, _) p##1 _ p##2 _ p##3 _ p##4 _ p##5 _ p##6 _ p##7 _ p##8 _ p##9 _ p##10 _ p##11 _ p##12
#define Z_FOR_13_APPEND_TIME(p, _) p##1 _ p##2 _ p##3 _ p##4 _ p##5 _ p##6 _ p##7 _ p##8 _ p##9 _ p##10 _ p##11 _ p##12 _ p##13
#define Z_FOR_14_APPEND_TIME(p, _) p##1 _ p##2 _ p##3 _ p##4 _ p##5 _ p##6 _ p##7 _ p##8 _ p##9 _ p##10 _ p##11 _ p##12 _ p##13 _ p##14
#define Z_FOR_15_APPEND_TIME(p, _) p##1 _ p##2 _ p##3 _ p##4 _ p##5 _ p##6 _ p##7 _ p##8 _ p##9 _ p##10 _ p##11 _ p##12 _ p##13 _ p##14 _ p##15
#define Z_FOR_16_APPEND_TIME(p, _) p##1 _ p##2 _ p##3 _ p##4 _ p##5 _ p##6 _ p##7 _ p##8 _ p##9 _ p##10 _ p##11 _ p##12 _ p##13 _ p##14 _ p##15 _ p##16
#define Z_FOR_17_APPEND_TIME(p, _) p##1 _ p##2 _ p##3 _ p##4 _ p##5 _ p##6 _ p##7 _ p##8 _ p##9 _ p##10 _ p##11 _ p##12 _ p##13 _ p##14 _ p##15 _ p##16 _ p##17
#define Z_FOR_18_APPEND_TIME(p, _) p##1 _ p##2 _ p##3 _ p##4 _ p##5 _ p##6 _ p##7 _ p##8 _ p##9 _ p##10 _ p##11 _ p##12 _ p##13 _ p##14 _ p##15 _ p##16 _ p##17 _ p##18
#define Z_FOR_19_APPEND_TIME(p, _) p##1 _ p##2 _ p##3 _ p##4 _ p##5 _ p##6 _ p##7 _ p##8 _ p##9 _ p##10 _ p##11 _ p##12 _ p##13 _ p##14 _ p##15 _ p##16 _ p##17 _ p##18 _ p##19
#define Z_FOR_20_APPEND_TIME(p, _) p##1 _ p##2 _ p##3 _ p##4 _ p##5 _ p##6 _ p##7 _ p##8 _ p##9 _ p##10 _ p##11 _ p##12 _ p##13 _ p##14 _ p##15 _ p##16 _ p##17 _ p##18 _ p##19 _ p##20
#define Z_FOR_21_APPEND_TIME(p, _) p##1 _ p##2 _ p##3 _ p##4 _ p##5 _ p##6 _ p##7 _ p##8 _ p##9 _ p##10 _ p##11 _ p##12 _ p##13 _ p##14 _ p##15 _ p##16 _ p##17 _ p##18 _ p##19 _ p##20 _ p##21
#define Z_FOR_22_APPEND_TIME(p, _) p##1 _ p##2 _ p##3 _ p##4 _ p##5 _ p##6 _ p##7 _ p##8 _ p##9 _ p##10 _ p##11 _ p##12 _ p##13 _ p##14 _ p##15 _ p##16 _ p##17 _ p##18 _ p##19 _ p##20 _ p##21 _ p##22
#define Z_FOR_23_APPEND_TIME(p, _) p##1 _ p##2 _ p##3 _ p##4 _ p##5 _ p##6 _ p##7 _ p##8 _ p##9 _ p##10 _ p##11 _ p##12 _ p##13 _ p##14 _ p##15 _ p##16 _ p##17 _ p##18 _ p##19 _ p##20 _ p##21 _ p##22 _ p##23
#define Z_FOR_24_APPEND_TIME(p, _) p##1 _ p##2 _ p##3 _ p##4 _ p##5 _ p##6 _ p##7 _ p##8 _ p##9 _ p##10 _ p##11 _ p##12 _ p##13 _ p##14 _ p##15 _ p##16 _ p##17 _ p##18 _ p##19 _ p##20 _ p##21 _ p##22 _ p##23 _ p##24
#define Z_FOR_25_APPEND_TIME(p, _) p##1 _ p##2 _ p##3 _ p##4 _ p##5 _ p##6 _ p##7 _ p##8 _ p##9 _ p##10 _ p##11 _ p##12 _ p##13 _ p##14 _ p##15 _ p##16 _ p##17 _ p##18 _ p##19 _ p##20 _ p##21 _ p##22 _ p##23 _ p##24 _ p##25
#define Z_FOR_26_APPEND_TIME(p, _) p##1 _ p##2 _ p##3 _ p##4 _ p##5 _ p##6 _ p##7 _ p##8 _ p##9 _ p##10 _ p##11 _ p##12 _ p##13 _ p##14 _ p##15 _ p##16 _ p##17 _ p##18 _ p##19 _ p##20 _ p##21 _ p##22 _ p##23 _ p##24 _ p##25 _ p##26
#define Z_FOR_27_APPEND_TIME(p, _) p##1 _ p##2 _ p##3 _ p##4 _ p##5 _ p##6 _ p##7 _ p##8 _ p##9 _ p##10 _ p##11 _ p##12 _ p##13 _ p##14 _ p##15 _ p##16 _ p##17 _ p##18 _ p##19 _ p##20 _ p##21 _ p##22 _ p##23 _ p##24 _ p##25 _ p##26 _ p##27
#define Z_FOR_28_APPEND_TIME(p, _) p##1 _ p##2 _ p##3 _ p##4 _ p##5 _ p##6 _ p##7 _ p##8 _ p##9 _ p##10 _ p##11 _ p##12 _ p##13 _ p##14 _ p##15 _ p##16 _ p##17 _ p##18 _ p##19 _ p##20 _ p##21 _ p##22 _ p##23 _ p##24 _ p##25 _ p##26 _ p##27 _ p##28
#define Z_FOR_29_APPEND_TIME(p, _) p##1 _ p##2 _ p##3 _ p##4 _ p##5 _ p##6 _ p##7 _ p##8 _ p##9 _ p##10 _ p##11 _ p##12 _ p##13 _ p##14 _ p##15 _ p##16 _ p##17 _ p##18 _ p##19 _ p##20 _ p##21 _ p##22 _ p##23 _ p##24 _ p##25 _ p##26 _ p##27 _ p##28 _ p##29
#define Z_FOR_30_APPEND_TIME(p, _) p##1 _ p##2 _ p##3 _ p##4 _ p##5 _ p##6 _ p##7 _ p##8 _ p##9 _ p##10 _ p##11 _ p##12 _ p##13 _ p##14 _ p##15 _ p##16 _ p##17 _ p##18 _ p##19 _ p##20 _ p##21 _ p##22 _ p##23 _ p##24 _ p##25 _ p##26 _ p##27 _ p##28 _ p##29 _ p##30
#define Z_FOR_31_APPEND_TIME(p, _) p##1 _ p##2 _ p##3 _ p##4 _ p##5 _ p##6 _ p##7 _ p##8 _ p##9 _ p##10 _ p##11 _ p##12 _ p##13 _ p##14 _ p##15 _ p##16 _ p##17 _ p##18 _ p##19 _ p##20 _ p##21 _ p##22 _ p##23 _ p##24 _ p##25 _ p##26 _ p##27 _ p##28 _ p##29 _ p##30 _ p##31
#define Z_FOR_32_APPEND_TIME(p, _) p##1 _ p##2 _ p##3 _ p##4 _ p##5 _ p##6 _ p##7 _ p##8 _ p##9 _ p##10 _ p##11 _ p##12 _ p##13 _ p##14 _ p##15 _ p##16 _ p##17 _ p##18 _ p##19 _ p##20 _ p##21 _ p##22 _ p##23 _ p##24 _ p##25 _ p##26 _ p##27 _ p##28 _ p##29 _ p##30 _ p##31 _ p##32

#define Z_FOR_0_INSERT_INDEX( p, s, _)
#define Z_FOR_1_INSERT_INDEX( p, s, _) p##0##s
#define Z_FOR_2_INSERT_INDEX( p, s, _) p##0##s _ p##1##s
#define Z_FOR_3_INSERT_INDEX( p, s, _) p##0##s _ p##1##s _ p##2##s
#define Z_FOR_4_INSERT_INDEX( p, s, _) p##0##s _ p##1##s _ p##2##s _ p##3##s
#define Z_FOR_5_INSERT_INDEX( p, s, _) p##0##s _ p##1##s _ p##2##s _ p##3##s _ p##4##s
#define Z_FOR_6_INSERT_INDEX( p, s, _) p##0##s _ p##1##s _ p##2##s _ p##3##s _ p##4##s _ p##5##s
#define Z_FOR_7_INSERT_INDEX( p, s, _) p##0##s _ p##1##s _ p##2##s _ p##3##s _ p##4##s _ p##5##s _ p##6##s
#define Z_FOR_8_INSERT_INDEX( p, s, _) p##0##s _ p##1##s _ p##2##s _ p##3##s _ p##4##s _ p##5##s _ p##6##s _ p##7##s
#define Z_FOR_9_INSERT_INDEX( p, s, _) p##0##s _ p##1##s _ p##2##s _ p##3##s _ p##4##s _ p##5##s _ p##6##s _ p##7##s _ p##8##s
#define Z_FOR_10_INSERT_INDEX(p, s, _) p##0##s _ p##1##s _ p##2##s _ p##3##s _ p##4##s _ p##5##s _ p##6##s _ p##7##s _ p##8##s _ p##9##s
#define Z_FOR_11_INSERT_INDEX(p, s, _) p##0##s _ p##1##s _ p##2##s _ p##3##s _ p##4##s _ p##5##s _ p##6##s _ p##7##s _ p##8##s _ p##9##s _ p##10##s
#define Z_FOR_12_INSERT_INDEX(p, s, _) p##0##s _ p##1##s _ p##2##s _ p##3##s _ p##4##s _ p##5##s _ p##6##s _ p##7##s _ p##8##s _ p##9##s _ p##10##s _ p##11##s
#define Z_FOR_13_INSERT_INDEX(p, s, _) p##0##s _ p##1##s _ p##2##s _ p##3##s _ p##4##s _ p##5##s _ p##6##s _ p##7##s _ p##8##s _ p##9##s _ p##10##s _ p##11##s _ p##12##s
#define Z_FOR_14_INSERT_INDEX(p, s, _) p##0##s _ p##1##s _ p##2##s _ p##3##s _ p##4##s _ p##5##s _ p##6##s _ p##7##s _ p##8##s _ p##9##s _ p##10##s _ p##11##s _ p##12##s _ p##13##s
#define Z_FOR_15_INSERT_INDEX(p, s, _) p##0##s _ p##1##s _ p##2##s _ p##3##s _ p##4##s _ p##5##s _ p##6##s _ p##7##s _ p##8##s _ p##9##s _ p##10##s _ p##11##s _ p##12##s _ p##13##s _ p##14##s
#define Z_FOR_16_INSERT_INDEX(p, s, _) p##0##s _ p##1##s _ p##2##s _ p##3##s _ p##4##s _ p##5##s _ p##6##s _ p##7##s _ p##8##s _ p##9##s _ p##10##s _ p##11##s _ p##12##s _ p##13##s _ p##14##s _ p##15##s
#define Z_FOR_17_INSERT_INDEX(p, s, _) p##0##s _ p##1##s _ p##2##s _ p##3##s _ p##4##s _ p##5##s _ p##6##s _ p##7##s _ p##8##s _ p##9##s _ p##10##s _ p##11##s _ p##12##s _ p##13##s _ p##14##s _ p##15##s _ p##16##s
#define Z_FOR_18_INSERT_INDEX(p, s, _) p##0##s _ p##1##s _ p##2##s _ p##3##s _ p##4##s _ p##5##s _ p##6##s _ p##7##s _ p##8##s _ p##9##s _ p##10##s _ p##11##s _ p##12##s _ p##13##s _ p##14##s _ p##15##s _ p##16##s _ p##17##s
#define Z_FOR_19_INSERT_INDEX(p, s, _) p##0##s _ p##1##s _ p##2##s _ p##3##s _ p##4##s _ p##5##s _ p##6##s _ p##7##s _ p##8##s _ p##9##s _ p##10##s _ p##11##s _ p##12##s _ p##13##s _ p##14##s _ p##15##s _ p##16##s _ p##17##s _ p##18##s
#define Z_FOR_20_INSERT_INDEX(p, s, _) p##0##s _ p##1##s _ p##2##s _ p##3##s _ p##4##s _ p##5##s _ p##6##s _ p##7##s _ p##8##s _ p##9##s _ p##10##s _ p##11##s _ p##12##s _ p##13##s _ p##14##s _ p##15##s _ p##16##s _ p##17##s _ p##18##s _ p##19##s
#define Z_FOR_21_INSERT_INDEX(p, s, _) p##0##s _ p##1##s _ p##2##s _ p##3##s _ p##4##s _ p##5##s _ p##6##s _ p##7##s _ p##8##s _ p##9##s _ p##10##s _ p##11##s _ p##12##s _ p##13##s _ p##14##s _ p##15##s _ p##16##s _ p##17##s _ p##18##s _ p##19##s _ p##20##s
#define Z_FOR_22_INSERT_INDEX(p, s, _) p##0##s _ p##1##s _ p##2##s _ p##3##s _ p##4##s _ p##5##s _ p##6##s _ p##7##s _ p##8##s _ p##9##s _ p##10##s _ p##11##s _ p##12##s _ p##13##s _ p##14##s _ p##15##s _ p##16##s _ p##17##s _ p##18##s _ p##19##s _ p##20##s _ p##21##s
#define Z_FOR_23_INSERT_INDEX(p, s, _) p##0##s _ p##1##s _ p##2##s _ p##3##s _ p##4##s _ p##5##s _ p##6##s _ p##7##s _ p##8##s _ p##9##s _ p##10##s _ p##11##s _ p##12##s _ p##13##s _ p##14##s _ p##15##s _ p##16##s _ p##17##s _ p##18##s _ p##19##s _ p##20##s _ p##21##s _ p##22##s
#define Z_FOR_24_INSERT_INDEX(p, s, _) p##0##s _ p##1##s _ p##2##s _ p##3##s _ p##4##s _ p##5##s _ p##6##s _ p##7##s _ p##8##s _ p##9##s _ p##10##s _ p##11##s _ p##12##s _ p##13##s _ p##14##s _ p##15##s _ p##16##s _ p##17##s _ p##18##s _ p##19##s _ p##20##s _ p##21##s _ p##22##s _ p##23##s
#define Z_FOR_25_INSERT_INDEX(p, s, _) p##0##s _ p##1##s _ p##2##s _ p##3##s _ p##4##s _ p##5##s _ p##6##s _ p##7##s _ p##8##s _ p##9##s _ p##10##s _ p##11##s _ p##12##s _ p##13##s _ p##14##s _ p##15##s _ p##16##s _ p##17##s _ p##18##s _ p##19##s _ p##20##s _ p##21##s _ p##22##s _ p##23##s _ p##24##s
#define Z_FOR_26_INSERT_INDEX(p, s, _) p##0##s _ p##1##s _ p##2##s _ p##3##s _ p##4##s _ p##5##s _ p##6##s _ p##7##s _ p##8##s _ p##9##s _ p##10##s _ p##11##s _ p##12##s _ p##13##s _ p##14##s _ p##15##s _ p##16##s _ p##17##s _ p##18##s _ p##19##s _ p##20##s _ p##21##s _ p##22##s _ p##23##s _ p##24##s _ p##25##s
#define Z_FOR_27_INSERT_INDEX(p, s, _) p##0##s _ p##1##s _ p##2##s _ p##3##s _ p##4##s _ p##5##s _ p##6##s _ p##7##s _ p##8##s _ p##9##s _ p##10##s _ p##11##s _ p##12##s _ p##13##s _ p##14##s _ p##15##s _ p##16##s _ p##17##s _ p##18##s _ p##19##s _ p##20##s _ p##21##s _ p##22##s _ p##23##s _ p##24##s _ p##25##s _ p##26##s
#define Z_FOR_28_INSERT_INDEX(p, s, _) p##0##s _ p##1##s _ p##2##s _ p##3##s _ p##4##s _ p##5##s _ p##6##s _ p##7##s _ p##8##s _ p##9##s _ p##10##s _ p##11##s _ p##12##s _ p##13##s _ p##14##s _ p##15##s _ p##16##s _ p##17##s _ p##18##s _ p##19##s _ p##20##s _ p##21##s _ p##22##s _ p##23##s _ p##24##s _ p##25##s _ p##26##s _ p##27##s
#define Z_FOR_29_INSERT_INDEX(p, s, _) p##0##s _ p##1##s _ p##2##s _ p##3##s _ p##4##s _ p##5##s _ p##6##s _ p##7##s _ p##8##s _ p##9##s _ p##10##s _ p##11##s _ p##12##s _ p##13##s _ p##14##s _ p##15##s _ p##16##s _ p##17##s _ p##18##s _ p##19##s _ p##20##s _ p##21##s _ p##22##s _ p##23##s _ p##24##s _ p##25##s _ p##26##s _ p##27##s _ p##28##s
#define Z_FOR_30_INSERT_INDEX(p, s, _) p##0##s _ p##1##s _ p##2##s _ p##3##s _ p##4##s _ p##5##s _ p##6##s _ p##7##s _ p##8##s _ p##9##s _ p##10##s _ p##11##s _ p##12##s _ p##13##s _ p##14##s _ p##15##s _ p##16##s _ p##17##s _ p##18##s _ p##19##s _ p##20##s _ p##21##s _ p##22##s _ p##23##s _ p##24##s _ p##25##s _ p##26##s _ p##27##s _ p##28##s _ p##29##s
#define Z_FOR_31_INSERT_INDEX(p, s, _) p##0##s _ p##1##s _ p##2##s _ p##3##s _ p##4##s _ p##5##s _ p##6##s _ p##7##s _ p##8##s _ p##9##s _ p##10##s _ p##11##s _ p##12##s _ p##13##s _ p##14##s _ p##15##s _ p##16##s _ p##17##s _ p##18##s _ p##19##s _ p##20##s _ p##21##s _ p##22##s _ p##23##s _ p##24##s _ p##25##s _ p##26##s _ p##27##s _ p##28##s _ p##29##s _ p##30##s
#define Z_FOR_32_INSERT_INDEX(p, s, _) p##0##s _ p##1##s _ p##2##s _ p##3##s _ p##4##s _ p##5##s _ p##6##s _ p##7##s _ p##8##s _ p##9##s _ p##10##s _ p##11##s _ p##12##s _ p##13##s _ p##14##s _ p##15##s _ p##16##s _ p##17##s _ p##18##s _ p##19##s _ p##20##s _ p##21##s _ p##22##s _ p##23##s _ p##24##s _ p##25##s _ p##26##s _ p##27##s _ p##28##s _ p##29##s _ p##30##s _ p##31##s

#define Z_FOR_0_INSERT_TIME( p, s, _)
#define Z_FOR_1_INSERT_TIME( p, s, _) p##1##s
#define Z_FOR_2_INSERT_TIME( p, s, _) p##1##s _ p##2##s
#define Z_FOR_3_INSERT_TIME( p, s, _) p##1##s _ p##2##s _ p##3##s
#define Z_FOR_4_INSERT_TIME( p, s, _) p##1##s _ p##2##s _ p##3##s _ p##4##s
#define Z_FOR_5_INSERT_TIME( p, s, _) p##1##s _ p##2##s _ p##3##s _ p##4##s _ p##5##s
#define Z_FOR_6_INSERT_TIME( p, s, _) p##1##s _ p##2##s _ p##3##s _ p##4##s _ p##5##s _ p##6##s
#define Z_FOR_7_INSERT_TIME( p, s, _) p##1##s _ p##2##s _ p##3##s _ p##4##s _ p##5##s _ p##6##s _ p##7##s
#define Z_FOR_8_INSERT_TIME( p, s, _) p##1##s _ p##2##s _ p##3##s _ p##4##s _ p##5##s _ p##6##s _ p##7##s _ p##8##s
#define Z_FOR_9_INSERT_TIME( p, s, _) p##1##s _ p##2##s _ p##3##s _ p##4##s _ p##5##s _ p##6##s _ p##7##s _ p##8##s _ p##9##s
#define Z_FOR_10_INSERT_TIME(p, s, _) p##1##s _ p##2##s _ p##3##s _ p##4##s _ p##5##s _ p##6##s _ p##7##s _ p##8##s _ p##9##s _ p##10##s
#define Z_FOR_11_INSERT_TIME(p, s, _) p##1##s _ p##2##s _ p##3##s _ p##4##s _ p##5##s _ p##6##s _ p##7##s _ p##8##s _ p##9##s _ p##10##s _ p##11##s
#define Z_FOR_12_INSERT_TIME(p, s, _) p##1##s _ p##2##s _ p##3##s _ p##4##s _ p##5##s _ p##6##s _ p##7##s _ p##8##s _ p##9##s _ p##10##s _ p##11##s _ p##12##s
#define Z_FOR_13_INSERT_TIME(p, s, _) p##1##s _ p##2##s _ p##3##s _ p##4##s _ p##5##s _ p##6##s _ p##7##s _ p##8##s _ p##9##s _ p##10##s _ p##11##s _ p##12##s _ p##13##s
#define Z_FOR_14_INSERT_TIME(p, s, _) p##1##s _ p##2##s _ p##3##s _ p##4##s _ p##5##s _ p##6##s _ p##7##s _ p##8##s _ p##9##s _ p##10##s _ p##11##s _ p##12##s _ p##13##s _ p##14##s
#define Z_FOR_15_INSERT_TIME(p, s, _) p##1##s _ p##2##s _ p##3##s _ p##4##s _ p##5##s _ p##6##s _ p##7##s _ p##8##s _ p##9##s _ p##10##s _ p##11##s _ p##12##s _ p##13##s _ p##14##s _ p##15##s
#define Z_FOR_16_INSERT_TIME(p, s, _) p##1##s _ p##2##s _ p##3##s _ p##4##s _ p##5##s _ p##6##s _ p##7##s _ p##8##s _ p##9##s _ p##10##s _ p##11##s _ p##12##s _ p##13##s _ p##14##s _ p##15##s _ p##16##s
#define Z_FOR_17_INSERT_TIME(p, s, _) p##1##s _ p##2##s _ p##3##s _ p##4##s _ p##5##s _ p##6##s _ p##7##s _ p##8##s _ p##9##s _ p##10##s _ p##11##s _ p##12##s _ p##13##s _ p##14##s _ p##15##s _ p##16##s _ p##17##s
#define Z_FOR_18_INSERT_TIME(p, s, _) p##1##s _ p##2##s _ p##3##s _ p##4##s _ p##5##s _ p##6##s _ p##7##s _ p##8##s _ p##9##s _ p##10##s _ p##11##s _ p##12##s _ p##13##s _ p##14##s _ p##15##s _ p##16##s _ p##17##s _ p##18##s
#define Z_FOR_19_INSERT_TIME(p, s, _) p##1##s _ p##2##s _ p##3##s _ p##4##s _ p##5##s _ p##6##s _ p##7##s _ p##8##s _ p##9##s _ p##10##s _ p##11##s _ p##12##s _ p##13##s _ p##14##s _ p##15##s _ p##16##s _ p##17##s _ p##18##s _ p##19##s
#define Z_FOR_20_INSERT_TIME(p, s, _) p##1##s _ p##2##s _ p##3##s _ p##4##s _ p##5##s _ p##6##s _ p##7##s _ p##8##s _ p##9##s _ p##10##s _ p##11##s _ p##12##s _ p##13##s _ p##14##s _ p##15##s _ p##16##s _ p##17##s _ p##18##s _ p##19##s _ p##20##s
#define Z_FOR_21_INSERT_TIME(p, s, _) p##1##s _ p##2##s _ p##3##s _ p##4##s _ p##5##s _ p##6##s _ p##7##s _ p##8##s _ p##9##s _ p##10##s _ p##11##s _ p##12##s _ p##13##s _ p##14##s _ p##15##s _ p##16##s _ p##17##s _ p##18##s _ p##19##s _ p##20##s _ p##21##s
#define Z_FOR_22_INSERT_TIME(p, s, _) p##1##s _ p##2##s _ p##3##s _ p##4##s _ p##5##s _ p##6##s _ p##7##s _ p##8##s _ p##9##s _ p##10##s _ p##11##s _ p##12##s _ p##13##s _ p##14##s _ p##15##s _ p##16##s _ p##17##s _ p##18##s _ p##19##s _ p##20##s _ p##21##s _ p##22##s
#define Z_FOR_23_INSERT_TIME(p, s, _) p##1##s _ p##2##s _ p##3##s _ p##4##s _ p##5##s _ p##6##s _ p##7##s _ p##8##s _ p##9##s _ p##10##s _ p##11##s _ p##12##s _ p##13##s _ p##14##s _ p##15##s _ p##16##s _ p##17##s _ p##18##s _ p##19##s _ p##20##s _ p##21##s _ p##22##s _ p##23##s
#define Z_FOR_24_INSERT_TIME(p, s, _) p##1##s _ p##2##s _ p##3##s _ p##4##s _ p##5##s _ p##6##s _ p##7##s _ p##8##s _ p##9##s _ p##10##s _ p##11##s _ p##12##s _ p##13##s _ p##14##s _ p##15##s _ p##16##s _ p##17##s _ p##18##s _ p##19##s _ p##20##s _ p##21##s _ p##22##s _ p##23##s _ p##24##s
#define Z_FOR_25_INSERT_TIME(p, s, _) p##1##s _ p##2##s _ p##3##s _ p##4##s _ p##5##s _ p##6##s _ p##7##s _ p##8##s _ p##9##s _ p##10##s _ p##11##s _ p##12##s _ p##13##s _ p##14##s _ p##15##s _ p##16##s _ p##17##s _ p##18##s _ p##19##s _ p##20##s _ p##21##s _ p##22##s _ p##23##s _ p##24##s _ p##25##s
#define Z_FOR_26_INSERT_TIME(p, s, _) p##1##s _ p##2##s _ p##3##s _ p##4##s _ p##5##s _ p##6##s _ p##7##s _ p##8##s _ p##9##s _ p##10##s _ p##11##s _ p##12##s _ p##13##s _ p##14##s _ p##15##s _ p##16##s _ p##17##s _ p##18##s _ p##19##s _ p##20##s _ p##21##s _ p##22##s _ p##23##s _ p##24##s _ p##25##s _ p##26##s
#define Z_FOR_27_INSERT_TIME(p, s, _) p##1##s _ p##2##s _ p##3##s _ p##4##s _ p##5##s _ p##6##s _ p##7##s _ p##8##s _ p##9##s _ p##10##s _ p##11##s _ p##12##s _ p##13##s _ p##14##s _ p##15##s _ p##16##s _ p##17##s _ p##18##s _ p##19##s _ p##20##s _ p##21##s _ p##22##s _ p##23##s _ p##24##s _ p##25##s _ p##26##s _ p##27##s
#define Z_FOR_28_INSERT_TIME(p, s, _) p##1##s _ p##2##s _ p##3##s _ p##4##s _ p##5##s _ p##6##s _ p##7##s _ p##8##s _ p##9##s _ p##10##s _ p##11##s _ p##12##s _ p##13##s _ p##14##s _ p##15##s _ p##16##s _ p##17##s _ p##18##s _ p##19##s _ p##20##s _ p##21##s _ p##22##s _ p##23##s _ p##24##s _ p##25##s _ p##26##s _ p##27##s _ p##28##s
#define Z_FOR_29_INSERT_TIME(p, s, _) p##1##s _ p##2##s _ p##3##s _ p##4##s _ p##5##s _ p##6##s _ p##7##s _ p##8##s _ p##9##s _ p##10##s _ p##11##s _ p##12##s _ p##13##s _ p##14##s _ p##15##s _ p##16##s _ p##17##s _ p##18##s _ p##19##s _ p##20##s _ p##21##s _ p##22##s _ p##23##s _ p##24##s _ p##25##s _ p##26##s _ p##27##s _ p##28##s _ p##29##s
#define Z_FOR_30_INSERT_TIME(p, s, _) p##1##s _ p##2##s _ p##3##s _ p##4##s _ p##5##s _ p##6##s _ p##7##s _ p##8##s _ p##9##s _ p##10##s _ p##11##s _ p##12##s _ p##13##s _ p##14##s _ p##15##s _ p##16##s _ p##17##s _ p##18##s _ p##19##s _ p##20##s _ p##21##s _ p##22##s _ p##23##s _ p##24##s _ p##25##s _ p##26##s _ p##27##s _ p##28##s _ p##29##s _ p##30##s
#define Z_FOR_31_INSERT_TIME(p, s, _) p##1##s _ p##2##s _ p##3##s _ p##4##s _ p##5##s _ p##6##s _ p##7##s _ p##8##s _ p##9##s _ p##10##s _ p##11##s _ p##12##s _ p##13##s _ p##14##s _ p##15##s _ p##16##s _ p##17##s _ p##18##s _ p##19##s _ p##20##s _ p##21##s _ p##22##s _ p##23##s _ p##24##s _ p##25##s _ p##26##s _ p##27##s _ p##28##s _ p##29##s _ p##30##s _ p##31##s
#define Z_FOR_32_INSERT_TIME(p, s, _) p##1##s _ p##2##s _ p##3##s _ p##4##s _ p##5##s _ p##6##s _ p##7##s _ p##8##s _ p##9##s _ p##10##s _ p##11##s _ p##12##s _ p##13##s _ p##14##s _ p##15##s _ p##16##s _ p##17##s _ p##18##s _ p##19##s _ p##20##s _ p##21##s _ p##22##s _ p##23##s _ p##24##s _ p##25##s _ p##26##s _ p##27##s _ p##28##s _ p##29##s _ p##30##s _ p##31##s _ p##32##s

#endif /* _Z_macros_repetition_H_ */
