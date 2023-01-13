/* Zeta API - Z/macros/iteration.h
 ______ ____________  ___
|__   /|  ___|__  __|/   \
  /  /_|  __|  |  | /  *  \
 /_____|_____| |__|/__/ \__\
Copyright (C) 2006-2023 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_macros_iteration_H
#define Z_macros_iteration_H

#define Z_FOR_0_APPEND_INDEX( l, _)
#define Z_FOR_1_APPEND_INDEX( l, _) l##0
#define Z_FOR_2_APPEND_INDEX( l, _) l##0 _ l##1
#define Z_FOR_3_APPEND_INDEX( l, _) l##0 _ l##1 _ l##2
#define Z_FOR_4_APPEND_INDEX( l, _) l##0 _ l##1 _ l##2 _ l##3
#define Z_FOR_5_APPEND_INDEX( l, _) l##0 _ l##1 _ l##2 _ l##3 _ l##4
#define Z_FOR_6_APPEND_INDEX( l, _) l##0 _ l##1 _ l##2 _ l##3 _ l##4 _ l##5
#define Z_FOR_7_APPEND_INDEX( l, _) l##0 _ l##1 _ l##2 _ l##3 _ l##4 _ l##5 _ l##6
#define Z_FOR_8_APPEND_INDEX( l, _) l##0 _ l##1 _ l##2 _ l##3 _ l##4 _ l##5 _ l##6 _ l##7
#define Z_FOR_9_APPEND_INDEX( l, _) l##0 _ l##1 _ l##2 _ l##3 _ l##4 _ l##5 _ l##6 _ l##7 _ l##8
#define Z_FOR_10_APPEND_INDEX(l, _) l##0 _ l##1 _ l##2 _ l##3 _ l##4 _ l##5 _ l##6 _ l##7 _ l##8 _ l##9
#define Z_FOR_11_APPEND_INDEX(l, _) l##0 _ l##1 _ l##2 _ l##3 _ l##4 _ l##5 _ l##6 _ l##7 _ l##8 _ l##9 _ l##10
#define Z_FOR_12_APPEND_INDEX(l, _) l##0 _ l##1 _ l##2 _ l##3 _ l##4 _ l##5 _ l##6 _ l##7 _ l##8 _ l##9 _ l##10 _ l##11
#define Z_FOR_13_APPEND_INDEX(l, _) l##0 _ l##1 _ l##2 _ l##3 _ l##4 _ l##5 _ l##6 _ l##7 _ l##8 _ l##9 _ l##10 _ l##11 _ l##12
#define Z_FOR_14_APPEND_INDEX(l, _) l##0 _ l##1 _ l##2 _ l##3 _ l##4 _ l##5 _ l##6 _ l##7 _ l##8 _ l##9 _ l##10 _ l##11 _ l##12 _ l##13
#define Z_FOR_15_APPEND_INDEX(l, _) l##0 _ l##1 _ l##2 _ l##3 _ l##4 _ l##5 _ l##6 _ l##7 _ l##8 _ l##9 _ l##10 _ l##11 _ l##12 _ l##13 _ l##14
#define Z_FOR_16_APPEND_INDEX(l, _) l##0 _ l##1 _ l##2 _ l##3 _ l##4 _ l##5 _ l##6 _ l##7 _ l##8 _ l##9 _ l##10 _ l##11 _ l##12 _ l##13 _ l##14 _ l##15
#define Z_FOR_17_APPEND_INDEX(l, _) l##0 _ l##1 _ l##2 _ l##3 _ l##4 _ l##5 _ l##6 _ l##7 _ l##8 _ l##9 _ l##10 _ l##11 _ l##12 _ l##13 _ l##14 _ l##15 _ l##16
#define Z_FOR_18_APPEND_INDEX(l, _) l##0 _ l##1 _ l##2 _ l##3 _ l##4 _ l##5 _ l##6 _ l##7 _ l##8 _ l##9 _ l##10 _ l##11 _ l##12 _ l##13 _ l##14 _ l##15 _ l##16 _ l##17
#define Z_FOR_19_APPEND_INDEX(l, _) l##0 _ l##1 _ l##2 _ l##3 _ l##4 _ l##5 _ l##6 _ l##7 _ l##8 _ l##9 _ l##10 _ l##11 _ l##12 _ l##13 _ l##14 _ l##15 _ l##16 _ l##17 _ l##18
#define Z_FOR_20_APPEND_INDEX(l, _) l##0 _ l##1 _ l##2 _ l##3 _ l##4 _ l##5 _ l##6 _ l##7 _ l##8 _ l##9 _ l##10 _ l##11 _ l##12 _ l##13 _ l##14 _ l##15 _ l##16 _ l##17 _ l##18 _ l##19
#define Z_FOR_21_APPEND_INDEX(l, _) l##0 _ l##1 _ l##2 _ l##3 _ l##4 _ l##5 _ l##6 _ l##7 _ l##8 _ l##9 _ l##10 _ l##11 _ l##12 _ l##13 _ l##14 _ l##15 _ l##16 _ l##17 _ l##18 _ l##19 _ l##20
#define Z_FOR_22_APPEND_INDEX(l, _) l##0 _ l##1 _ l##2 _ l##3 _ l##4 _ l##5 _ l##6 _ l##7 _ l##8 _ l##9 _ l##10 _ l##11 _ l##12 _ l##13 _ l##14 _ l##15 _ l##16 _ l##17 _ l##18 _ l##19 _ l##20 _ l##21
#define Z_FOR_23_APPEND_INDEX(l, _) l##0 _ l##1 _ l##2 _ l##3 _ l##4 _ l##5 _ l##6 _ l##7 _ l##8 _ l##9 _ l##10 _ l##11 _ l##12 _ l##13 _ l##14 _ l##15 _ l##16 _ l##17 _ l##18 _ l##19 _ l##20 _ l##21 _ l##22
#define Z_FOR_24_APPEND_INDEX(l, _) l##0 _ l##1 _ l##2 _ l##3 _ l##4 _ l##5 _ l##6 _ l##7 _ l##8 _ l##9 _ l##10 _ l##11 _ l##12 _ l##13 _ l##14 _ l##15 _ l##16 _ l##17 _ l##18 _ l##19 _ l##20 _ l##21 _ l##22 _ l##23
#define Z_FOR_25_APPEND_INDEX(l, _) l##0 _ l##1 _ l##2 _ l##3 _ l##4 _ l##5 _ l##6 _ l##7 _ l##8 _ l##9 _ l##10 _ l##11 _ l##12 _ l##13 _ l##14 _ l##15 _ l##16 _ l##17 _ l##18 _ l##19 _ l##20 _ l##21 _ l##22 _ l##23 _ l##24
#define Z_FOR_26_APPEND_INDEX(l, _) l##0 _ l##1 _ l##2 _ l##3 _ l##4 _ l##5 _ l##6 _ l##7 _ l##8 _ l##9 _ l##10 _ l##11 _ l##12 _ l##13 _ l##14 _ l##15 _ l##16 _ l##17 _ l##18 _ l##19 _ l##20 _ l##21 _ l##22 _ l##23 _ l##24 _ l##25
#define Z_FOR_27_APPEND_INDEX(l, _) l##0 _ l##1 _ l##2 _ l##3 _ l##4 _ l##5 _ l##6 _ l##7 _ l##8 _ l##9 _ l##10 _ l##11 _ l##12 _ l##13 _ l##14 _ l##15 _ l##16 _ l##17 _ l##18 _ l##19 _ l##20 _ l##21 _ l##22 _ l##23 _ l##24 _ l##25 _ l##26
#define Z_FOR_28_APPEND_INDEX(l, _) l##0 _ l##1 _ l##2 _ l##3 _ l##4 _ l##5 _ l##6 _ l##7 _ l##8 _ l##9 _ l##10 _ l##11 _ l##12 _ l##13 _ l##14 _ l##15 _ l##16 _ l##17 _ l##18 _ l##19 _ l##20 _ l##21 _ l##22 _ l##23 _ l##24 _ l##25 _ l##26 _ l##27
#define Z_FOR_29_APPEND_INDEX(l, _) l##0 _ l##1 _ l##2 _ l##3 _ l##4 _ l##5 _ l##6 _ l##7 _ l##8 _ l##9 _ l##10 _ l##11 _ l##12 _ l##13 _ l##14 _ l##15 _ l##16 _ l##17 _ l##18 _ l##19 _ l##20 _ l##21 _ l##22 _ l##23 _ l##24 _ l##25 _ l##26 _ l##27 _ l##28
#define Z_FOR_30_APPEND_INDEX(l, _) l##0 _ l##1 _ l##2 _ l##3 _ l##4 _ l##5 _ l##6 _ l##7 _ l##8 _ l##9 _ l##10 _ l##11 _ l##12 _ l##13 _ l##14 _ l##15 _ l##16 _ l##17 _ l##18 _ l##19 _ l##20 _ l##21 _ l##22 _ l##23 _ l##24 _ l##25 _ l##26 _ l##27 _ l##28 _ l##29
#define Z_FOR_31_APPEND_INDEX(l, _) l##0 _ l##1 _ l##2 _ l##3 _ l##4 _ l##5 _ l##6 _ l##7 _ l##8 _ l##9 _ l##10 _ l##11 _ l##12 _ l##13 _ l##14 _ l##15 _ l##16 _ l##17 _ l##18 _ l##19 _ l##20 _ l##21 _ l##22 _ l##23 _ l##24 _ l##25 _ l##26 _ l##27 _ l##28 _ l##29 _ l##30
#define Z_FOR_32_APPEND_INDEX(l, _) l##0 _ l##1 _ l##2 _ l##3 _ l##4 _ l##5 _ l##6 _ l##7 _ l##8 _ l##9 _ l##10 _ l##11 _ l##12 _ l##13 _ l##14 _ l##15 _ l##16 _ l##17 _ l##18 _ l##19 _ l##20 _ l##21 _ l##22 _ l##23 _ l##24 _ l##25 _ l##26 _ l##27 _ l##28 _ l##29 _ l##30 _ l##31

#define Z_FOR_0_APPEND_TIME( l, _)
#define Z_FOR_1_APPEND_TIME( l, _) l##1
#define Z_FOR_2_APPEND_TIME( l, _) l##1 _ l##2
#define Z_FOR_3_APPEND_TIME( l, _) l##1 _ l##2 _ l##3
#define Z_FOR_4_APPEND_TIME( l, _) l##1 _ l##2 _ l##3 _ l##4
#define Z_FOR_5_APPEND_TIME( l, _) l##1 _ l##2 _ l##3 _ l##4 _ l##5
#define Z_FOR_6_APPEND_TIME( l, _) l##1 _ l##2 _ l##3 _ l##4 _ l##5 _ l##6
#define Z_FOR_7_APPEND_TIME( l, _) l##1 _ l##2 _ l##3 _ l##4 _ l##5 _ l##6 _ l##7
#define Z_FOR_8_APPEND_TIME( l, _) l##1 _ l##2 _ l##3 _ l##4 _ l##5 _ l##6 _ l##7 _ l##8
#define Z_FOR_9_APPEND_TIME( l, _) l##1 _ l##2 _ l##3 _ l##4 _ l##5 _ l##6 _ l##7 _ l##8 _ l##9
#define Z_FOR_10_APPEND_TIME(l, _) l##1 _ l##2 _ l##3 _ l##4 _ l##5 _ l##6 _ l##7 _ l##8 _ l##9 _ l##10
#define Z_FOR_11_APPEND_TIME(l, _) l##1 _ l##2 _ l##3 _ l##4 _ l##5 _ l##6 _ l##7 _ l##8 _ l##9 _ l##10 _ l##11
#define Z_FOR_12_APPEND_TIME(l, _) l##1 _ l##2 _ l##3 _ l##4 _ l##5 _ l##6 _ l##7 _ l##8 _ l##9 _ l##10 _ l##11 _ l##12
#define Z_FOR_13_APPEND_TIME(l, _) l##1 _ l##2 _ l##3 _ l##4 _ l##5 _ l##6 _ l##7 _ l##8 _ l##9 _ l##10 _ l##11 _ l##12 _ l##13
#define Z_FOR_14_APPEND_TIME(l, _) l##1 _ l##2 _ l##3 _ l##4 _ l##5 _ l##6 _ l##7 _ l##8 _ l##9 _ l##10 _ l##11 _ l##12 _ l##13 _ l##14
#define Z_FOR_15_APPEND_TIME(l, _) l##1 _ l##2 _ l##3 _ l##4 _ l##5 _ l##6 _ l##7 _ l##8 _ l##9 _ l##10 _ l##11 _ l##12 _ l##13 _ l##14 _ l##15
#define Z_FOR_16_APPEND_TIME(l, _) l##1 _ l##2 _ l##3 _ l##4 _ l##5 _ l##6 _ l##7 _ l##8 _ l##9 _ l##10 _ l##11 _ l##12 _ l##13 _ l##14 _ l##15 _ l##16
#define Z_FOR_17_APPEND_TIME(l, _) l##1 _ l##2 _ l##3 _ l##4 _ l##5 _ l##6 _ l##7 _ l##8 _ l##9 _ l##10 _ l##11 _ l##12 _ l##13 _ l##14 _ l##15 _ l##16 _ l##17
#define Z_FOR_18_APPEND_TIME(l, _) l##1 _ l##2 _ l##3 _ l##4 _ l##5 _ l##6 _ l##7 _ l##8 _ l##9 _ l##10 _ l##11 _ l##12 _ l##13 _ l##14 _ l##15 _ l##16 _ l##17 _ l##18
#define Z_FOR_19_APPEND_TIME(l, _) l##1 _ l##2 _ l##3 _ l##4 _ l##5 _ l##6 _ l##7 _ l##8 _ l##9 _ l##10 _ l##11 _ l##12 _ l##13 _ l##14 _ l##15 _ l##16 _ l##17 _ l##18 _ l##19
#define Z_FOR_20_APPEND_TIME(l, _) l##1 _ l##2 _ l##3 _ l##4 _ l##5 _ l##6 _ l##7 _ l##8 _ l##9 _ l##10 _ l##11 _ l##12 _ l##13 _ l##14 _ l##15 _ l##16 _ l##17 _ l##18 _ l##19 _ l##20
#define Z_FOR_21_APPEND_TIME(l, _) l##1 _ l##2 _ l##3 _ l##4 _ l##5 _ l##6 _ l##7 _ l##8 _ l##9 _ l##10 _ l##11 _ l##12 _ l##13 _ l##14 _ l##15 _ l##16 _ l##17 _ l##18 _ l##19 _ l##20 _ l##21
#define Z_FOR_22_APPEND_TIME(l, _) l##1 _ l##2 _ l##3 _ l##4 _ l##5 _ l##6 _ l##7 _ l##8 _ l##9 _ l##10 _ l##11 _ l##12 _ l##13 _ l##14 _ l##15 _ l##16 _ l##17 _ l##18 _ l##19 _ l##20 _ l##21 _ l##22
#define Z_FOR_23_APPEND_TIME(l, _) l##1 _ l##2 _ l##3 _ l##4 _ l##5 _ l##6 _ l##7 _ l##8 _ l##9 _ l##10 _ l##11 _ l##12 _ l##13 _ l##14 _ l##15 _ l##16 _ l##17 _ l##18 _ l##19 _ l##20 _ l##21 _ l##22 _ l##23
#define Z_FOR_24_APPEND_TIME(l, _) l##1 _ l##2 _ l##3 _ l##4 _ l##5 _ l##6 _ l##7 _ l##8 _ l##9 _ l##10 _ l##11 _ l##12 _ l##13 _ l##14 _ l##15 _ l##16 _ l##17 _ l##18 _ l##19 _ l##20 _ l##21 _ l##22 _ l##23 _ l##24
#define Z_FOR_25_APPEND_TIME(l, _) l##1 _ l##2 _ l##3 _ l##4 _ l##5 _ l##6 _ l##7 _ l##8 _ l##9 _ l##10 _ l##11 _ l##12 _ l##13 _ l##14 _ l##15 _ l##16 _ l##17 _ l##18 _ l##19 _ l##20 _ l##21 _ l##22 _ l##23 _ l##24 _ l##25
#define Z_FOR_26_APPEND_TIME(l, _) l##1 _ l##2 _ l##3 _ l##4 _ l##5 _ l##6 _ l##7 _ l##8 _ l##9 _ l##10 _ l##11 _ l##12 _ l##13 _ l##14 _ l##15 _ l##16 _ l##17 _ l##18 _ l##19 _ l##20 _ l##21 _ l##22 _ l##23 _ l##24 _ l##25 _ l##26
#define Z_FOR_27_APPEND_TIME(l, _) l##1 _ l##2 _ l##3 _ l##4 _ l##5 _ l##6 _ l##7 _ l##8 _ l##9 _ l##10 _ l##11 _ l##12 _ l##13 _ l##14 _ l##15 _ l##16 _ l##17 _ l##18 _ l##19 _ l##20 _ l##21 _ l##22 _ l##23 _ l##24 _ l##25 _ l##26 _ l##27
#define Z_FOR_28_APPEND_TIME(l, _) l##1 _ l##2 _ l##3 _ l##4 _ l##5 _ l##6 _ l##7 _ l##8 _ l##9 _ l##10 _ l##11 _ l##12 _ l##13 _ l##14 _ l##15 _ l##16 _ l##17 _ l##18 _ l##19 _ l##20 _ l##21 _ l##22 _ l##23 _ l##24 _ l##25 _ l##26 _ l##27 _ l##28
#define Z_FOR_29_APPEND_TIME(l, _) l##1 _ l##2 _ l##3 _ l##4 _ l##5 _ l##6 _ l##7 _ l##8 _ l##9 _ l##10 _ l##11 _ l##12 _ l##13 _ l##14 _ l##15 _ l##16 _ l##17 _ l##18 _ l##19 _ l##20 _ l##21 _ l##22 _ l##23 _ l##24 _ l##25 _ l##26 _ l##27 _ l##28 _ l##29
#define Z_FOR_30_APPEND_TIME(l, _) l##1 _ l##2 _ l##3 _ l##4 _ l##5 _ l##6 _ l##7 _ l##8 _ l##9 _ l##10 _ l##11 _ l##12 _ l##13 _ l##14 _ l##15 _ l##16 _ l##17 _ l##18 _ l##19 _ l##20 _ l##21 _ l##22 _ l##23 _ l##24 _ l##25 _ l##26 _ l##27 _ l##28 _ l##29 _ l##30
#define Z_FOR_31_APPEND_TIME(l, _) l##1 _ l##2 _ l##3 _ l##4 _ l##5 _ l##6 _ l##7 _ l##8 _ l##9 _ l##10 _ l##11 _ l##12 _ l##13 _ l##14 _ l##15 _ l##16 _ l##17 _ l##18 _ l##19 _ l##20 _ l##21 _ l##22 _ l##23 _ l##24 _ l##25 _ l##26 _ l##27 _ l##28 _ l##29 _ l##30 _ l##31
#define Z_FOR_32_APPEND_TIME(l, _) l##1 _ l##2 _ l##3 _ l##4 _ l##5 _ l##6 _ l##7 _ l##8 _ l##9 _ l##10 _ l##11 _ l##12 _ l##13 _ l##14 _ l##15 _ l##16 _ l##17 _ l##18 _ l##19 _ l##20 _ l##21 _ l##22 _ l##23 _ l##24 _ l##25 _ l##26 _ l##27 _ l##28 _ l##29 _ l##30 _ l##31 _ l##32

#define Z_FOR_0_INSERT_INDEX( l, r, _)
#define Z_FOR_1_INSERT_INDEX( l, r, _) l##0##r
#define Z_FOR_2_INSERT_INDEX( l, r, _) l##0##r _ l##1##r
#define Z_FOR_3_INSERT_INDEX( l, r, _) l##0##r _ l##1##r _ l##2##r
#define Z_FOR_4_INSERT_INDEX( l, r, _) l##0##r _ l##1##r _ l##2##r _ l##3##r
#define Z_FOR_5_INSERT_INDEX( l, r, _) l##0##r _ l##1##r _ l##2##r _ l##3##r _ l##4##r
#define Z_FOR_6_INSERT_INDEX( l, r, _) l##0##r _ l##1##r _ l##2##r _ l##3##r _ l##4##r _ l##5##r
#define Z_FOR_7_INSERT_INDEX( l, r, _) l##0##r _ l##1##r _ l##2##r _ l##3##r _ l##4##r _ l##5##r _ l##6##r
#define Z_FOR_8_INSERT_INDEX( l, r, _) l##0##r _ l##1##r _ l##2##r _ l##3##r _ l##4##r _ l##5##r _ l##6##r _ l##7##r
#define Z_FOR_9_INSERT_INDEX( l, r, _) l##0##r _ l##1##r _ l##2##r _ l##3##r _ l##4##r _ l##5##r _ l##6##r _ l##7##r _ l##8##r
#define Z_FOR_10_INSERT_INDEX(l, r, _) l##0##r _ l##1##r _ l##2##r _ l##3##r _ l##4##r _ l##5##r _ l##6##r _ l##7##r _ l##8##r _ l##9##r
#define Z_FOR_11_INSERT_INDEX(l, r, _) l##0##r _ l##1##r _ l##2##r _ l##3##r _ l##4##r _ l##5##r _ l##6##r _ l##7##r _ l##8##r _ l##9##r _ l##10##r
#define Z_FOR_12_INSERT_INDEX(l, r, _) l##0##r _ l##1##r _ l##2##r _ l##3##r _ l##4##r _ l##5##r _ l##6##r _ l##7##r _ l##8##r _ l##9##r _ l##10##r _ l##11##r
#define Z_FOR_13_INSERT_INDEX(l, r, _) l##0##r _ l##1##r _ l##2##r _ l##3##r _ l##4##r _ l##5##r _ l##6##r _ l##7##r _ l##8##r _ l##9##r _ l##10##r _ l##11##r _ l##12##r
#define Z_FOR_14_INSERT_INDEX(l, r, _) l##0##r _ l##1##r _ l##2##r _ l##3##r _ l##4##r _ l##5##r _ l##6##r _ l##7##r _ l##8##r _ l##9##r _ l##10##r _ l##11##r _ l##12##r _ l##13##r
#define Z_FOR_15_INSERT_INDEX(l, r, _) l##0##r _ l##1##r _ l##2##r _ l##3##r _ l##4##r _ l##5##r _ l##6##r _ l##7##r _ l##8##r _ l##9##r _ l##10##r _ l##11##r _ l##12##r _ l##13##r _ l##14##r
#define Z_FOR_16_INSERT_INDEX(l, r, _) l##0##r _ l##1##r _ l##2##r _ l##3##r _ l##4##r _ l##5##r _ l##6##r _ l##7##r _ l##8##r _ l##9##r _ l##10##r _ l##11##r _ l##12##r _ l##13##r _ l##14##r _ l##15##r
#define Z_FOR_17_INSERT_INDEX(l, r, _) l##0##r _ l##1##r _ l##2##r _ l##3##r _ l##4##r _ l##5##r _ l##6##r _ l##7##r _ l##8##r _ l##9##r _ l##10##r _ l##11##r _ l##12##r _ l##13##r _ l##14##r _ l##15##r _ l##16##r
#define Z_FOR_18_INSERT_INDEX(l, r, _) l##0##r _ l##1##r _ l##2##r _ l##3##r _ l##4##r _ l##5##r _ l##6##r _ l##7##r _ l##8##r _ l##9##r _ l##10##r _ l##11##r _ l##12##r _ l##13##r _ l##14##r _ l##15##r _ l##16##r _ l##17##r
#define Z_FOR_19_INSERT_INDEX(l, r, _) l##0##r _ l##1##r _ l##2##r _ l##3##r _ l##4##r _ l##5##r _ l##6##r _ l##7##r _ l##8##r _ l##9##r _ l##10##r _ l##11##r _ l##12##r _ l##13##r _ l##14##r _ l##15##r _ l##16##r _ l##17##r _ l##18##r
#define Z_FOR_20_INSERT_INDEX(l, r, _) l##0##r _ l##1##r _ l##2##r _ l##3##r _ l##4##r _ l##5##r _ l##6##r _ l##7##r _ l##8##r _ l##9##r _ l##10##r _ l##11##r _ l##12##r _ l##13##r _ l##14##r _ l##15##r _ l##16##r _ l##17##r _ l##18##r _ l##19##r
#define Z_FOR_21_INSERT_INDEX(l, r, _) l##0##r _ l##1##r _ l##2##r _ l##3##r _ l##4##r _ l##5##r _ l##6##r _ l##7##r _ l##8##r _ l##9##r _ l##10##r _ l##11##r _ l##12##r _ l##13##r _ l##14##r _ l##15##r _ l##16##r _ l##17##r _ l##18##r _ l##19##r _ l##20##r
#define Z_FOR_22_INSERT_INDEX(l, r, _) l##0##r _ l##1##r _ l##2##r _ l##3##r _ l##4##r _ l##5##r _ l##6##r _ l##7##r _ l##8##r _ l##9##r _ l##10##r _ l##11##r _ l##12##r _ l##13##r _ l##14##r _ l##15##r _ l##16##r _ l##17##r _ l##18##r _ l##19##r _ l##20##r _ l##21##r
#define Z_FOR_23_INSERT_INDEX(l, r, _) l##0##r _ l##1##r _ l##2##r _ l##3##r _ l##4##r _ l##5##r _ l##6##r _ l##7##r _ l##8##r _ l##9##r _ l##10##r _ l##11##r _ l##12##r _ l##13##r _ l##14##r _ l##15##r _ l##16##r _ l##17##r _ l##18##r _ l##19##r _ l##20##r _ l##21##r _ l##22##r
#define Z_FOR_24_INSERT_INDEX(l, r, _) l##0##r _ l##1##r _ l##2##r _ l##3##r _ l##4##r _ l##5##r _ l##6##r _ l##7##r _ l##8##r _ l##9##r _ l##10##r _ l##11##r _ l##12##r _ l##13##r _ l##14##r _ l##15##r _ l##16##r _ l##17##r _ l##18##r _ l##19##r _ l##20##r _ l##21##r _ l##22##r _ l##23##r
#define Z_FOR_25_INSERT_INDEX(l, r, _) l##0##r _ l##1##r _ l##2##r _ l##3##r _ l##4##r _ l##5##r _ l##6##r _ l##7##r _ l##8##r _ l##9##r _ l##10##r _ l##11##r _ l##12##r _ l##13##r _ l##14##r _ l##15##r _ l##16##r _ l##17##r _ l##18##r _ l##19##r _ l##20##r _ l##21##r _ l##22##r _ l##23##r _ l##24##r
#define Z_FOR_26_INSERT_INDEX(l, r, _) l##0##r _ l##1##r _ l##2##r _ l##3##r _ l##4##r _ l##5##r _ l##6##r _ l##7##r _ l##8##r _ l##9##r _ l##10##r _ l##11##r _ l##12##r _ l##13##r _ l##14##r _ l##15##r _ l##16##r _ l##17##r _ l##18##r _ l##19##r _ l##20##r _ l##21##r _ l##22##r _ l##23##r _ l##24##r _ l##25##r
#define Z_FOR_27_INSERT_INDEX(l, r, _) l##0##r _ l##1##r _ l##2##r _ l##3##r _ l##4##r _ l##5##r _ l##6##r _ l##7##r _ l##8##r _ l##9##r _ l##10##r _ l##11##r _ l##12##r _ l##13##r _ l##14##r _ l##15##r _ l##16##r _ l##17##r _ l##18##r _ l##19##r _ l##20##r _ l##21##r _ l##22##r _ l##23##r _ l##24##r _ l##25##r _ l##26##r
#define Z_FOR_28_INSERT_INDEX(l, r, _) l##0##r _ l##1##r _ l##2##r _ l##3##r _ l##4##r _ l##5##r _ l##6##r _ l##7##r _ l##8##r _ l##9##r _ l##10##r _ l##11##r _ l##12##r _ l##13##r _ l##14##r _ l##15##r _ l##16##r _ l##17##r _ l##18##r _ l##19##r _ l##20##r _ l##21##r _ l##22##r _ l##23##r _ l##24##r _ l##25##r _ l##26##r _ l##27##r
#define Z_FOR_29_INSERT_INDEX(l, r, _) l##0##r _ l##1##r _ l##2##r _ l##3##r _ l##4##r _ l##5##r _ l##6##r _ l##7##r _ l##8##r _ l##9##r _ l##10##r _ l##11##r _ l##12##r _ l##13##r _ l##14##r _ l##15##r _ l##16##r _ l##17##r _ l##18##r _ l##19##r _ l##20##r _ l##21##r _ l##22##r _ l##23##r _ l##24##r _ l##25##r _ l##26##r _ l##27##r _ l##28##r
#define Z_FOR_30_INSERT_INDEX(l, r, _) l##0##r _ l##1##r _ l##2##r _ l##3##r _ l##4##r _ l##5##r _ l##6##r _ l##7##r _ l##8##r _ l##9##r _ l##10##r _ l##11##r _ l##12##r _ l##13##r _ l##14##r _ l##15##r _ l##16##r _ l##17##r _ l##18##r _ l##19##r _ l##20##r _ l##21##r _ l##22##r _ l##23##r _ l##24##r _ l##25##r _ l##26##r _ l##27##r _ l##28##r _ l##29##r
#define Z_FOR_31_INSERT_INDEX(l, r, _) l##0##r _ l##1##r _ l##2##r _ l##3##r _ l##4##r _ l##5##r _ l##6##r _ l##7##r _ l##8##r _ l##9##r _ l##10##r _ l##11##r _ l##12##r _ l##13##r _ l##14##r _ l##15##r _ l##16##r _ l##17##r _ l##18##r _ l##19##r _ l##20##r _ l##21##r _ l##22##r _ l##23##r _ l##24##r _ l##25##r _ l##26##r _ l##27##r _ l##28##r _ l##29##r _ l##30##r
#define Z_FOR_32_INSERT_INDEX(l, r, _) l##0##r _ l##1##r _ l##2##r _ l##3##r _ l##4##r _ l##5##r _ l##6##r _ l##7##r _ l##8##r _ l##9##r _ l##10##r _ l##11##r _ l##12##r _ l##13##r _ l##14##r _ l##15##r _ l##16##r _ l##17##r _ l##18##r _ l##19##r _ l##20##r _ l##21##r _ l##22##r _ l##23##r _ l##24##r _ l##25##r _ l##26##r _ l##27##r _ l##28##r _ l##29##r _ l##30##r _ l##31##r

#define Z_FOR_0_INSERT_TIME( l, r, _)
#define Z_FOR_1_INSERT_TIME( l, r, _) l##1##r
#define Z_FOR_2_INSERT_TIME( l, r, _) l##1##r _ l##2##r
#define Z_FOR_3_INSERT_TIME( l, r, _) l##1##r _ l##2##r _ l##3##r
#define Z_FOR_4_INSERT_TIME( l, r, _) l##1##r _ l##2##r _ l##3##r _ l##4##r
#define Z_FOR_5_INSERT_TIME( l, r, _) l##1##r _ l##2##r _ l##3##r _ l##4##r _ l##5##r
#define Z_FOR_6_INSERT_TIME( l, r, _) l##1##r _ l##2##r _ l##3##r _ l##4##r _ l##5##r _ l##6##r
#define Z_FOR_7_INSERT_TIME( l, r, _) l##1##r _ l##2##r _ l##3##r _ l##4##r _ l##5##r _ l##6##r _ l##7##r
#define Z_FOR_8_INSERT_TIME( l, r, _) l##1##r _ l##2##r _ l##3##r _ l##4##r _ l##5##r _ l##6##r _ l##7##r _ l##8##r
#define Z_FOR_9_INSERT_TIME( l, r, _) l##1##r _ l##2##r _ l##3##r _ l##4##r _ l##5##r _ l##6##r _ l##7##r _ l##8##r _ l##9##r
#define Z_FOR_10_INSERT_TIME(l, r, _) l##1##r _ l##2##r _ l##3##r _ l##4##r _ l##5##r _ l##6##r _ l##7##r _ l##8##r _ l##9##r _ l##10##r
#define Z_FOR_11_INSERT_TIME(l, r, _) l##1##r _ l##2##r _ l##3##r _ l##4##r _ l##5##r _ l##6##r _ l##7##r _ l##8##r _ l##9##r _ l##10##r _ l##11##r
#define Z_FOR_12_INSERT_TIME(l, r, _) l##1##r _ l##2##r _ l##3##r _ l##4##r _ l##5##r _ l##6##r _ l##7##r _ l##8##r _ l##9##r _ l##10##r _ l##11##r _ l##12##r
#define Z_FOR_13_INSERT_TIME(l, r, _) l##1##r _ l##2##r _ l##3##r _ l##4##r _ l##5##r _ l##6##r _ l##7##r _ l##8##r _ l##9##r _ l##10##r _ l##11##r _ l##12##r _ l##13##r
#define Z_FOR_14_INSERT_TIME(l, r, _) l##1##r _ l##2##r _ l##3##r _ l##4##r _ l##5##r _ l##6##r _ l##7##r _ l##8##r _ l##9##r _ l##10##r _ l##11##r _ l##12##r _ l##13##r _ l##14##r
#define Z_FOR_15_INSERT_TIME(l, r, _) l##1##r _ l##2##r _ l##3##r _ l##4##r _ l##5##r _ l##6##r _ l##7##r _ l##8##r _ l##9##r _ l##10##r _ l##11##r _ l##12##r _ l##13##r _ l##14##r _ l##15##r
#define Z_FOR_16_INSERT_TIME(l, r, _) l##1##r _ l##2##r _ l##3##r _ l##4##r _ l##5##r _ l##6##r _ l##7##r _ l##8##r _ l##9##r _ l##10##r _ l##11##r _ l##12##r _ l##13##r _ l##14##r _ l##15##r _ l##16##r
#define Z_FOR_17_INSERT_TIME(l, r, _) l##1##r _ l##2##r _ l##3##r _ l##4##r _ l##5##r _ l##6##r _ l##7##r _ l##8##r _ l##9##r _ l##10##r _ l##11##r _ l##12##r _ l##13##r _ l##14##r _ l##15##r _ l##16##r _ l##17##r
#define Z_FOR_18_INSERT_TIME(l, r, _) l##1##r _ l##2##r _ l##3##r _ l##4##r _ l##5##r _ l##6##r _ l##7##r _ l##8##r _ l##9##r _ l##10##r _ l##11##r _ l##12##r _ l##13##r _ l##14##r _ l##15##r _ l##16##r _ l##17##r _ l##18##r
#define Z_FOR_19_INSERT_TIME(l, r, _) l##1##r _ l##2##r _ l##3##r _ l##4##r _ l##5##r _ l##6##r _ l##7##r _ l##8##r _ l##9##r _ l##10##r _ l##11##r _ l##12##r _ l##13##r _ l##14##r _ l##15##r _ l##16##r _ l##17##r _ l##18##r _ l##19##r
#define Z_FOR_20_INSERT_TIME(l, r, _) l##1##r _ l##2##r _ l##3##r _ l##4##r _ l##5##r _ l##6##r _ l##7##r _ l##8##r _ l##9##r _ l##10##r _ l##11##r _ l##12##r _ l##13##r _ l##14##r _ l##15##r _ l##16##r _ l##17##r _ l##18##r _ l##19##r _ l##20##r
#define Z_FOR_21_INSERT_TIME(l, r, _) l##1##r _ l##2##r _ l##3##r _ l##4##r _ l##5##r _ l##6##r _ l##7##r _ l##8##r _ l##9##r _ l##10##r _ l##11##r _ l##12##r _ l##13##r _ l##14##r _ l##15##r _ l##16##r _ l##17##r _ l##18##r _ l##19##r _ l##20##r _ l##21##r
#define Z_FOR_22_INSERT_TIME(l, r, _) l##1##r _ l##2##r _ l##3##r _ l##4##r _ l##5##r _ l##6##r _ l##7##r _ l##8##r _ l##9##r _ l##10##r _ l##11##r _ l##12##r _ l##13##r _ l##14##r _ l##15##r _ l##16##r _ l##17##r _ l##18##r _ l##19##r _ l##20##r _ l##21##r _ l##22##r
#define Z_FOR_23_INSERT_TIME(l, r, _) l##1##r _ l##2##r _ l##3##r _ l##4##r _ l##5##r _ l##6##r _ l##7##r _ l##8##r _ l##9##r _ l##10##r _ l##11##r _ l##12##r _ l##13##r _ l##14##r _ l##15##r _ l##16##r _ l##17##r _ l##18##r _ l##19##r _ l##20##r _ l##21##r _ l##22##r _ l##23##r
#define Z_FOR_24_INSERT_TIME(l, r, _) l##1##r _ l##2##r _ l##3##r _ l##4##r _ l##5##r _ l##6##r _ l##7##r _ l##8##r _ l##9##r _ l##10##r _ l##11##r _ l##12##r _ l##13##r _ l##14##r _ l##15##r _ l##16##r _ l##17##r _ l##18##r _ l##19##r _ l##20##r _ l##21##r _ l##22##r _ l##23##r _ l##24##r
#define Z_FOR_25_INSERT_TIME(l, r, _) l##1##r _ l##2##r _ l##3##r _ l##4##r _ l##5##r _ l##6##r _ l##7##r _ l##8##r _ l##9##r _ l##10##r _ l##11##r _ l##12##r _ l##13##r _ l##14##r _ l##15##r _ l##16##r _ l##17##r _ l##18##r _ l##19##r _ l##20##r _ l##21##r _ l##22##r _ l##23##r _ l##24##r _ l##25##r
#define Z_FOR_26_INSERT_TIME(l, r, _) l##1##r _ l##2##r _ l##3##r _ l##4##r _ l##5##r _ l##6##r _ l##7##r _ l##8##r _ l##9##r _ l##10##r _ l##11##r _ l##12##r _ l##13##r _ l##14##r _ l##15##r _ l##16##r _ l##17##r _ l##18##r _ l##19##r _ l##20##r _ l##21##r _ l##22##r _ l##23##r _ l##24##r _ l##25##r _ l##26##r
#define Z_FOR_27_INSERT_TIME(l, r, _) l##1##r _ l##2##r _ l##3##r _ l##4##r _ l##5##r _ l##6##r _ l##7##r _ l##8##r _ l##9##r _ l##10##r _ l##11##r _ l##12##r _ l##13##r _ l##14##r _ l##15##r _ l##16##r _ l##17##r _ l##18##r _ l##19##r _ l##20##r _ l##21##r _ l##22##r _ l##23##r _ l##24##r _ l##25##r _ l##26##r _ l##27##r
#define Z_FOR_28_INSERT_TIME(l, r, _) l##1##r _ l##2##r _ l##3##r _ l##4##r _ l##5##r _ l##6##r _ l##7##r _ l##8##r _ l##9##r _ l##10##r _ l##11##r _ l##12##r _ l##13##r _ l##14##r _ l##15##r _ l##16##r _ l##17##r _ l##18##r _ l##19##r _ l##20##r _ l##21##r _ l##22##r _ l##23##r _ l##24##r _ l##25##r _ l##26##r _ l##27##r _ l##28##r
#define Z_FOR_29_INSERT_TIME(l, r, _) l##1##r _ l##2##r _ l##3##r _ l##4##r _ l##5##r _ l##6##r _ l##7##r _ l##8##r _ l##9##r _ l##10##r _ l##11##r _ l##12##r _ l##13##r _ l##14##r _ l##15##r _ l##16##r _ l##17##r _ l##18##r _ l##19##r _ l##20##r _ l##21##r _ l##22##r _ l##23##r _ l##24##r _ l##25##r _ l##26##r _ l##27##r _ l##28##r _ l##29##r
#define Z_FOR_30_INSERT_TIME(l, r, _) l##1##r _ l##2##r _ l##3##r _ l##4##r _ l##5##r _ l##6##r _ l##7##r _ l##8##r _ l##9##r _ l##10##r _ l##11##r _ l##12##r _ l##13##r _ l##14##r _ l##15##r _ l##16##r _ l##17##r _ l##18##r _ l##19##r _ l##20##r _ l##21##r _ l##22##r _ l##23##r _ l##24##r _ l##25##r _ l##26##r _ l##27##r _ l##28##r _ l##29##r _ l##30##r
#define Z_FOR_31_INSERT_TIME(l, r, _) l##1##r _ l##2##r _ l##3##r _ l##4##r _ l##5##r _ l##6##r _ l##7##r _ l##8##r _ l##9##r _ l##10##r _ l##11##r _ l##12##r _ l##13##r _ l##14##r _ l##15##r _ l##16##r _ l##17##r _ l##18##r _ l##19##r _ l##20##r _ l##21##r _ l##22##r _ l##23##r _ l##24##r _ l##25##r _ l##26##r _ l##27##r _ l##28##r _ l##29##r _ l##30##r _ l##31##r
#define Z_FOR_32_INSERT_TIME(l, r, _) l##1##r _ l##2##r _ l##3##r _ l##4##r _ l##5##r _ l##6##r _ l##7##r _ l##8##r _ l##9##r _ l##10##r _ l##11##r _ l##12##r _ l##13##r _ l##14##r _ l##15##r _ l##16##r _ l##17##r _ l##18##r _ l##19##r _ l##20##r _ l##21##r _ l##22##r _ l##23##r _ l##24##r _ l##25##r _ l##26##r _ l##27##r _ l##28##r _ l##29##r _ l##30##r _ l##31##r _ l##32##r

#define Z_FOR_0_CALL_WITH_INDEX( c, _)
#define Z_FOR_1_CALL_WITH_INDEX( c, _) c(0)
#define Z_FOR_2_CALL_WITH_INDEX( c, _) c(0) _ c(1)
#define Z_FOR_3_CALL_WITH_INDEX( c, _) c(0) _ c(1) _ c(2)
#define Z_FOR_4_CALL_WITH_INDEX( c, _) c(0) _ c(1) _ c(2) _ c(3)
#define Z_FOR_5_CALL_WITH_INDEX( c, _) c(0) _ c(1) _ c(2) _ c(3) _ c(4)
#define Z_FOR_6_CALL_WITH_INDEX( c, _) c(0) _ c(1) _ c(2) _ c(3) _ c(4) _ c(5)
#define Z_FOR_7_CALL_WITH_INDEX( c, _) c(0) _ c(1) _ c(2) _ c(3) _ c(4) _ c(5) _ c(6)
#define Z_FOR_8_CALL_WITH_INDEX( c, _) c(0) _ c(1) _ c(2) _ c(3) _ c(4) _ c(5) _ c(6) _ c(7)
#define Z_FOR_9_CALL_WITH_INDEX( c, _) c(0) _ c(1) _ c(2) _ c(3) _ c(4) _ c(5) _ c(6) _ c(7) _ c(8)
#define Z_FOR_10_CALL_WITH_INDEX(c, _) c(0) _ c(1) _ c(2) _ c(3) _ c(4) _ c(5) _ c(6) _ c(7) _ c(8) _ c(9)
#define Z_FOR_11_CALL_WITH_INDEX(c, _) c(0) _ c(1) _ c(2) _ c(3) _ c(4) _ c(5) _ c(6) _ c(7) _ c(8) _ c(9) _ c(10)
#define Z_FOR_12_CALL_WITH_INDEX(c, _) c(0) _ c(1) _ c(2) _ c(3) _ c(4) _ c(5) _ c(6) _ c(7) _ c(8) _ c(9) _ c(10) _ c(11)
#define Z_FOR_13_CALL_WITH_INDEX(c, _) c(0) _ c(1) _ c(2) _ c(3) _ c(4) _ c(5) _ c(6) _ c(7) _ c(8) _ c(9) _ c(10) _ c(11) _ c(12)
#define Z_FOR_14_CALL_WITH_INDEX(c, _) c(0) _ c(1) _ c(2) _ c(3) _ c(4) _ c(5) _ c(6) _ c(7) _ c(8) _ c(9) _ c(10) _ c(11) _ c(12) _ c(13)
#define Z_FOR_15_CALL_WITH_INDEX(c, _) c(0) _ c(1) _ c(2) _ c(3) _ c(4) _ c(5) _ c(6) _ c(7) _ c(8) _ c(9) _ c(10) _ c(11) _ c(12) _ c(13) _ c(14)
#define Z_FOR_16_CALL_WITH_INDEX(c, _) c(0) _ c(1) _ c(2) _ c(3) _ c(4) _ c(5) _ c(6) _ c(7) _ c(8) _ c(9) _ c(10) _ c(11) _ c(12) _ c(13) _ c(14) _ c(15)
#define Z_FOR_17_CALL_WITH_INDEX(c, _) c(0) _ c(1) _ c(2) _ c(3) _ c(4) _ c(5) _ c(6) _ c(7) _ c(8) _ c(9) _ c(10) _ c(11) _ c(12) _ c(13) _ c(14) _ c(15) _ c(16)
#define Z_FOR_18_CALL_WITH_INDEX(c, _) c(0) _ c(1) _ c(2) _ c(3) _ c(4) _ c(5) _ c(6) _ c(7) _ c(8) _ c(9) _ c(10) _ c(11) _ c(12) _ c(13) _ c(14) _ c(15) _ c(16) _ c(17)
#define Z_FOR_19_CALL_WITH_INDEX(c, _) c(0) _ c(1) _ c(2) _ c(3) _ c(4) _ c(5) _ c(6) _ c(7) _ c(8) _ c(9) _ c(10) _ c(11) _ c(12) _ c(13) _ c(14) _ c(15) _ c(16) _ c(17) _ c(18)
#define Z_FOR_20_CALL_WITH_INDEX(c, _) c(0) _ c(1) _ c(2) _ c(3) _ c(4) _ c(5) _ c(6) _ c(7) _ c(8) _ c(9) _ c(10) _ c(11) _ c(12) _ c(13) _ c(14) _ c(15) _ c(16) _ c(17) _ c(18) _ c(19)
#define Z_FOR_21_CALL_WITH_INDEX(c, _) c(0) _ c(1) _ c(2) _ c(3) _ c(4) _ c(5) _ c(6) _ c(7) _ c(8) _ c(9) _ c(10) _ c(11) _ c(12) _ c(13) _ c(14) _ c(15) _ c(16) _ c(17) _ c(18) _ c(19) _ c(20)
#define Z_FOR_22_CALL_WITH_INDEX(c, _) c(0) _ c(1) _ c(2) _ c(3) _ c(4) _ c(5) _ c(6) _ c(7) _ c(8) _ c(9) _ c(10) _ c(11) _ c(12) _ c(13) _ c(14) _ c(15) _ c(16) _ c(17) _ c(18) _ c(19) _ c(20) _ c(21)
#define Z_FOR_23_CALL_WITH_INDEX(c, _) c(0) _ c(1) _ c(2) _ c(3) _ c(4) _ c(5) _ c(6) _ c(7) _ c(8) _ c(9) _ c(10) _ c(11) _ c(12) _ c(13) _ c(14) _ c(15) _ c(16) _ c(17) _ c(18) _ c(19) _ c(20) _ c(21) _ c(22)
#define Z_FOR_24_CALL_WITH_INDEX(c, _) c(0) _ c(1) _ c(2) _ c(3) _ c(4) _ c(5) _ c(6) _ c(7) _ c(8) _ c(9) _ c(10) _ c(11) _ c(12) _ c(13) _ c(14) _ c(15) _ c(16) _ c(17) _ c(18) _ c(19) _ c(20) _ c(21) _ c(22) _ c(23)
#define Z_FOR_25_CALL_WITH_INDEX(c, _) c(0) _ c(1) _ c(2) _ c(3) _ c(4) _ c(5) _ c(6) _ c(7) _ c(8) _ c(9) _ c(10) _ c(11) _ c(12) _ c(13) _ c(14) _ c(15) _ c(16) _ c(17) _ c(18) _ c(19) _ c(20) _ c(21) _ c(22) _ c(23) _ c(24)
#define Z_FOR_26_CALL_WITH_INDEX(c, _) c(0) _ c(1) _ c(2) _ c(3) _ c(4) _ c(5) _ c(6) _ c(7) _ c(8) _ c(9) _ c(10) _ c(11) _ c(12) _ c(13) _ c(14) _ c(15) _ c(16) _ c(17) _ c(18) _ c(19) _ c(20) _ c(21) _ c(22) _ c(23) _ c(24) _ c(25)
#define Z_FOR_27_CALL_WITH_INDEX(c, _) c(0) _ c(1) _ c(2) _ c(3) _ c(4) _ c(5) _ c(6) _ c(7) _ c(8) _ c(9) _ c(10) _ c(11) _ c(12) _ c(13) _ c(14) _ c(15) _ c(16) _ c(17) _ c(18) _ c(19) _ c(20) _ c(21) _ c(22) _ c(23) _ c(24) _ c(25) _ c(26)
#define Z_FOR_28_CALL_WITH_INDEX(c, _) c(0) _ c(1) _ c(2) _ c(3) _ c(4) _ c(5) _ c(6) _ c(7) _ c(8) _ c(9) _ c(10) _ c(11) _ c(12) _ c(13) _ c(14) _ c(15) _ c(16) _ c(17) _ c(18) _ c(19) _ c(20) _ c(21) _ c(22) _ c(23) _ c(24) _ c(25) _ c(26) _ c(27)
#define Z_FOR_29_CALL_WITH_INDEX(c, _) c(0) _ c(1) _ c(2) _ c(3) _ c(4) _ c(5) _ c(6) _ c(7) _ c(8) _ c(9) _ c(10) _ c(11) _ c(12) _ c(13) _ c(14) _ c(15) _ c(16) _ c(17) _ c(18) _ c(19) _ c(20) _ c(21) _ c(22) _ c(23) _ c(24) _ c(25) _ c(26) _ c(27) _ c(28)
#define Z_FOR_30_CALL_WITH_INDEX(c, _) c(0) _ c(1) _ c(2) _ c(3) _ c(4) _ c(5) _ c(6) _ c(7) _ c(8) _ c(9) _ c(10) _ c(11) _ c(12) _ c(13) _ c(14) _ c(15) _ c(16) _ c(17) _ c(18) _ c(19) _ c(20) _ c(21) _ c(22) _ c(23) _ c(24) _ c(25) _ c(26) _ c(27) _ c(28) _ c(29)
#define Z_FOR_31_CALL_WITH_INDEX(c, _) c(0) _ c(1) _ c(2) _ c(3) _ c(4) _ c(5) _ c(6) _ c(7) _ c(8) _ c(9) _ c(10) _ c(11) _ c(12) _ c(13) _ c(14) _ c(15) _ c(16) _ c(17) _ c(18) _ c(19) _ c(20) _ c(21) _ c(22) _ c(23) _ c(24) _ c(25) _ c(26) _ c(27) _ c(28) _ c(29) _ c(30)
#define Z_FOR_32_CALL_WITH_INDEX(c, _) c(0) _ c(1) _ c(2) _ c(3) _ c(4) _ c(5) _ c(6) _ c(7) _ c(8) _ c(9) _ c(10) _ c(11) _ c(12) _ c(13) _ c(14) _ c(15) _ c(16) _ c(17) _ c(18) _ c(19) _ c(20) _ c(21) _ c(22) _ c(23) _ c(24) _ c(25) _ c(26) _ c(27) _ c(28) _ c(29) _ c(30) _ c(31)

#define Z_FOR_0_CALL_WITH_TIME( c, _)
#define Z_FOR_1_CALL_WITH_TIME( c, _) c(1)
#define Z_FOR_2_CALL_WITH_TIME( c, _) c(1) _ c(2)
#define Z_FOR_3_CALL_WITH_TIME( c, _) c(1) _ c(2) _ c(3)
#define Z_FOR_4_CALL_WITH_TIME( c, _) c(1) _ c(2) _ c(3) _ c(4)
#define Z_FOR_5_CALL_WITH_TIME( c, _) c(1) _ c(2) _ c(3) _ c(4) _ c(5)
#define Z_FOR_6_CALL_WITH_TIME( c, _) c(1) _ c(2) _ c(3) _ c(4) _ c(5) _ c(6)
#define Z_FOR_7_CALL_WITH_TIME( c, _) c(1) _ c(2) _ c(3) _ c(4) _ c(5) _ c(6) _ c(7)
#define Z_FOR_8_CALL_WITH_TIME( c, _) c(1) _ c(2) _ c(3) _ c(4) _ c(5) _ c(6) _ c(7) _ c(8)
#define Z_FOR_9_CALL_WITH_TIME( c, _) c(1) _ c(2) _ c(3) _ c(4) _ c(5) _ c(6) _ c(7) _ c(8) _ c(9)
#define Z_FOR_10_CALL_WITH_TIME(c, _) c(1) _ c(2) _ c(3) _ c(4) _ c(5) _ c(6) _ c(7) _ c(8) _ c(9) _ c(10)
#define Z_FOR_11_CALL_WITH_TIME(c, _) c(1) _ c(2) _ c(3) _ c(4) _ c(5) _ c(6) _ c(7) _ c(8) _ c(9) _ c(10) _ c(11)
#define Z_FOR_12_CALL_WITH_TIME(c, _) c(1) _ c(2) _ c(3) _ c(4) _ c(5) _ c(6) _ c(7) _ c(8) _ c(9) _ c(10) _ c(11) _ c(12)
#define Z_FOR_13_CALL_WITH_TIME(c, _) c(1) _ c(2) _ c(3) _ c(4) _ c(5) _ c(6) _ c(7) _ c(8) _ c(9) _ c(10) _ c(11) _ c(12) _ c(13)
#define Z_FOR_14_CALL_WITH_TIME(c, _) c(1) _ c(2) _ c(3) _ c(4) _ c(5) _ c(6) _ c(7) _ c(8) _ c(9) _ c(10) _ c(11) _ c(12) _ c(13) _ c(14)
#define Z_FOR_15_CALL_WITH_TIME(c, _) c(1) _ c(2) _ c(3) _ c(4) _ c(5) _ c(6) _ c(7) _ c(8) _ c(9) _ c(10) _ c(11) _ c(12) _ c(13) _ c(14) _ c(15)
#define Z_FOR_16_CALL_WITH_TIME(c, _) c(1) _ c(2) _ c(3) _ c(4) _ c(5) _ c(6) _ c(7) _ c(8) _ c(9) _ c(10) _ c(11) _ c(12) _ c(13) _ c(14) _ c(15) _ c(16)
#define Z_FOR_17_CALL_WITH_TIME(c, _) c(1) _ c(2) _ c(3) _ c(4) _ c(5) _ c(6) _ c(7) _ c(8) _ c(9) _ c(10) _ c(11) _ c(12) _ c(13) _ c(14) _ c(15) _ c(16) _ c(17)
#define Z_FOR_18_CALL_WITH_TIME(c, _) c(1) _ c(2) _ c(3) _ c(4) _ c(5) _ c(6) _ c(7) _ c(8) _ c(9) _ c(10) _ c(11) _ c(12) _ c(13) _ c(14) _ c(15) _ c(16) _ c(17) _ c(18)
#define Z_FOR_19_CALL_WITH_TIME(c, _) c(1) _ c(2) _ c(3) _ c(4) _ c(5) _ c(6) _ c(7) _ c(8) _ c(9) _ c(10) _ c(11) _ c(12) _ c(13) _ c(14) _ c(15) _ c(16) _ c(17) _ c(18) _ c(19)
#define Z_FOR_20_CALL_WITH_TIME(c, _) c(1) _ c(2) _ c(3) _ c(4) _ c(5) _ c(6) _ c(7) _ c(8) _ c(9) _ c(10) _ c(11) _ c(12) _ c(13) _ c(14) _ c(15) _ c(16) _ c(17) _ c(18) _ c(19) _ c(20)
#define Z_FOR_21_CALL_WITH_TIME(c, _) c(1) _ c(2) _ c(3) _ c(4) _ c(5) _ c(6) _ c(7) _ c(8) _ c(9) _ c(10) _ c(11) _ c(12) _ c(13) _ c(14) _ c(15) _ c(16) _ c(17) _ c(18) _ c(19) _ c(20) _ c(21)
#define Z_FOR_22_CALL_WITH_TIME(c, _) c(1) _ c(2) _ c(3) _ c(4) _ c(5) _ c(6) _ c(7) _ c(8) _ c(9) _ c(10) _ c(11) _ c(12) _ c(13) _ c(14) _ c(15) _ c(16) _ c(17) _ c(18) _ c(19) _ c(20) _ c(21) _ c(22)
#define Z_FOR_23_CALL_WITH_TIME(c, _) c(1) _ c(2) _ c(3) _ c(4) _ c(5) _ c(6) _ c(7) _ c(8) _ c(9) _ c(10) _ c(11) _ c(12) _ c(13) _ c(14) _ c(15) _ c(16) _ c(17) _ c(18) _ c(19) _ c(20) _ c(21) _ c(22) _ c(23)
#define Z_FOR_24_CALL_WITH_TIME(c, _) c(1) _ c(2) _ c(3) _ c(4) _ c(5) _ c(6) _ c(7) _ c(8) _ c(9) _ c(10) _ c(11) _ c(12) _ c(13) _ c(14) _ c(15) _ c(16) _ c(17) _ c(18) _ c(19) _ c(20) _ c(21) _ c(22) _ c(23) _ c(24)
#define Z_FOR_25_CALL_WITH_TIME(c, _) c(1) _ c(2) _ c(3) _ c(4) _ c(5) _ c(6) _ c(7) _ c(8) _ c(9) _ c(10) _ c(11) _ c(12) _ c(13) _ c(14) _ c(15) _ c(16) _ c(17) _ c(18) _ c(19) _ c(20) _ c(21) _ c(22) _ c(23) _ c(24) _ c(25)
#define Z_FOR_26_CALL_WITH_TIME(c, _) c(1) _ c(2) _ c(3) _ c(4) _ c(5) _ c(6) _ c(7) _ c(8) _ c(9) _ c(10) _ c(11) _ c(12) _ c(13) _ c(14) _ c(15) _ c(16) _ c(17) _ c(18) _ c(19) _ c(20) _ c(21) _ c(22) _ c(23) _ c(24) _ c(25) _ c(26)
#define Z_FOR_27_CALL_WITH_TIME(c, _) c(1) _ c(2) _ c(3) _ c(4) _ c(5) _ c(6) _ c(7) _ c(8) _ c(9) _ c(10) _ c(11) _ c(12) _ c(13) _ c(14) _ c(15) _ c(16) _ c(17) _ c(18) _ c(19) _ c(20) _ c(21) _ c(22) _ c(23) _ c(24) _ c(25) _ c(26) _ c(27)
#define Z_FOR_28_CALL_WITH_TIME(c, _) c(1) _ c(2) _ c(3) _ c(4) _ c(5) _ c(6) _ c(7) _ c(8) _ c(9) _ c(10) _ c(11) _ c(12) _ c(13) _ c(14) _ c(15) _ c(16) _ c(17) _ c(18) _ c(19) _ c(20) _ c(21) _ c(22) _ c(23) _ c(24) _ c(25) _ c(26) _ c(27) _ c(28)
#define Z_FOR_29_CALL_WITH_TIME(c, _) c(1) _ c(2) _ c(3) _ c(4) _ c(5) _ c(6) _ c(7) _ c(8) _ c(9) _ c(10) _ c(11) _ c(12) _ c(13) _ c(14) _ c(15) _ c(16) _ c(17) _ c(18) _ c(19) _ c(20) _ c(21) _ c(22) _ c(23) _ c(24) _ c(25) _ c(26) _ c(27) _ c(28) _ c(29)
#define Z_FOR_30_CALL_WITH_TIME(c, _) c(1) _ c(2) _ c(3) _ c(4) _ c(5) _ c(6) _ c(7) _ c(8) _ c(9) _ c(10) _ c(11) _ c(12) _ c(13) _ c(14) _ c(15) _ c(16) _ c(17) _ c(18) _ c(19) _ c(20) _ c(21) _ c(22) _ c(23) _ c(24) _ c(25) _ c(26) _ c(27) _ c(28) _ c(29) _ c(30)
#define Z_FOR_31_CALL_WITH_TIME(c, _) c(1) _ c(2) _ c(3) _ c(4) _ c(5) _ c(6) _ c(7) _ c(8) _ c(9) _ c(10) _ c(11) _ c(12) _ c(13) _ c(14) _ c(15) _ c(16) _ c(17) _ c(18) _ c(19) _ c(20) _ c(21) _ c(22) _ c(23) _ c(24) _ c(25) _ c(26) _ c(27) _ c(28) _ c(29) _ c(30) _ c(31)
#define Z_FOR_32_CALL_WITH_TIME(c, _) c(1) _ c(2) _ c(3) _ c(4) _ c(5) _ c(6) _ c(7) _ c(8) _ c(9) _ c(10) _ c(11) _ c(12) _ c(13) _ c(14) _ c(15) _ c(16) _ c(17) _ c(18) _ c(19) _ c(20) _ c(21) _ c(22) _ c(23) _ c(24) _ c(25) _ c(26) _ c(27) _ c(28) _ c(29) _ c(30) _ c(31) _ c(32)

#define Z_FOR_0_CALL_WITH_TOKEN_AND_INDEX( c, t, _)
#define Z_FOR_1_CALL_WITH_TOKEN_AND_INDEX( c, t, _) c(t, 0)
#define Z_FOR_2_CALL_WITH_TOKEN_AND_INDEX( c, t, _) c(t, 0) _ c(t, 1)
#define Z_FOR_3_CALL_WITH_TOKEN_AND_INDEX( c, t, _) c(t, 0) _ c(t, 1) _ c(t, 2)
#define Z_FOR_4_CALL_WITH_TOKEN_AND_INDEX( c, t, _) c(t, 0) _ c(t, 1) _ c(t, 2) _ c(t, 3)
#define Z_FOR_5_CALL_WITH_TOKEN_AND_INDEX( c, t, _) c(t, 0) _ c(t, 1) _ c(t, 2) _ c(t, 3) _ c(t, 4)
#define Z_FOR_6_CALL_WITH_TOKEN_AND_INDEX( c, t, _) c(t, 0) _ c(t, 1) _ c(t, 2) _ c(t, 3) _ c(t, 4) _ c(t, 5)
#define Z_FOR_7_CALL_WITH_TOKEN_AND_INDEX( c, t, _) c(t, 0) _ c(t, 1) _ c(t, 2) _ c(t, 3) _ c(t, 4) _ c(t, 5) _ c(t, 6)
#define Z_FOR_8_CALL_WITH_TOKEN_AND_INDEX( c, t, _) c(t, 0) _ c(t, 1) _ c(t, 2) _ c(t, 3) _ c(t, 4) _ c(t, 5) _ c(t, 6) _ c(t, 7)
#define Z_FOR_9_CALL_WITH_TOKEN_AND_INDEX( c, t, _) c(t, 0) _ c(t, 1) _ c(t, 2) _ c(t, 3) _ c(t, 4) _ c(t, 5) _ c(t, 6) _ c(t, 7) _ c(t, 8)
#define Z_FOR_10_CALL_WITH_TOKEN_AND_INDEX(c, t, _) c(t, 0) _ c(t, 1) _ c(t, 2) _ c(t, 3) _ c(t, 4) _ c(t, 5) _ c(t, 6) _ c(t, 7) _ c(t, 8) _ c(t, 9)
#define Z_FOR_11_CALL_WITH_TOKEN_AND_INDEX(c, t, _) c(t, 0) _ c(t, 1) _ c(t, 2) _ c(t, 3) _ c(t, 4) _ c(t, 5) _ c(t, 6) _ c(t, 7) _ c(t, 8) _ c(t, 9) _ c(t, 10)
#define Z_FOR_12_CALL_WITH_TOKEN_AND_INDEX(c, t, _) c(t, 0) _ c(t, 1) _ c(t, 2) _ c(t, 3) _ c(t, 4) _ c(t, 5) _ c(t, 6) _ c(t, 7) _ c(t, 8) _ c(t, 9) _ c(t, 10) _ c(t, 11)
#define Z_FOR_13_CALL_WITH_TOKEN_AND_INDEX(c, t, _) c(t, 0) _ c(t, 1) _ c(t, 2) _ c(t, 3) _ c(t, 4) _ c(t, 5) _ c(t, 6) _ c(t, 7) _ c(t, 8) _ c(t, 9) _ c(t, 10) _ c(t, 11) _ c(t, 12)
#define Z_FOR_14_CALL_WITH_TOKEN_AND_INDEX(c, t, _) c(t, 0) _ c(t, 1) _ c(t, 2) _ c(t, 3) _ c(t, 4) _ c(t, 5) _ c(t, 6) _ c(t, 7) _ c(t, 8) _ c(t, 9) _ c(t, 10) _ c(t, 11) _ c(t, 12) _ c(t, 13)
#define Z_FOR_15_CALL_WITH_TOKEN_AND_INDEX(c, t, _) c(t, 0) _ c(t, 1) _ c(t, 2) _ c(t, 3) _ c(t, 4) _ c(t, 5) _ c(t, 6) _ c(t, 7) _ c(t, 8) _ c(t, 9) _ c(t, 10) _ c(t, 11) _ c(t, 12) _ c(t, 13) _ c(t, 14)
#define Z_FOR_16_CALL_WITH_TOKEN_AND_INDEX(c, t, _) c(t, 0) _ c(t, 1) _ c(t, 2) _ c(t, 3) _ c(t, 4) _ c(t, 5) _ c(t, 6) _ c(t, 7) _ c(t, 8) _ c(t, 9) _ c(t, 10) _ c(t, 11) _ c(t, 12) _ c(t, 13) _ c(t, 14) _ c(t, 15)
#define Z_FOR_17_CALL_WITH_TOKEN_AND_INDEX(c, t, _) c(t, 0) _ c(t, 1) _ c(t, 2) _ c(t, 3) _ c(t, 4) _ c(t, 5) _ c(t, 6) _ c(t, 7) _ c(t, 8) _ c(t, 9) _ c(t, 10) _ c(t, 11) _ c(t, 12) _ c(t, 13) _ c(t, 14) _ c(t, 15) _ c(t, 16)
#define Z_FOR_18_CALL_WITH_TOKEN_AND_INDEX(c, t, _) c(t, 0) _ c(t, 1) _ c(t, 2) _ c(t, 3) _ c(t, 4) _ c(t, 5) _ c(t, 6) _ c(t, 7) _ c(t, 8) _ c(t, 9) _ c(t, 10) _ c(t, 11) _ c(t, 12) _ c(t, 13) _ c(t, 14) _ c(t, 15) _ c(t, 16) _ c(t, 17)
#define Z_FOR_19_CALL_WITH_TOKEN_AND_INDEX(c, t, _) c(t, 0) _ c(t, 1) _ c(t, 2) _ c(t, 3) _ c(t, 4) _ c(t, 5) _ c(t, 6) _ c(t, 7) _ c(t, 8) _ c(t, 9) _ c(t, 10) _ c(t, 11) _ c(t, 12) _ c(t, 13) _ c(t, 14) _ c(t, 15) _ c(t, 16) _ c(t, 17) _ c(t, 18)
#define Z_FOR_20_CALL_WITH_TOKEN_AND_INDEX(c, t, _) c(t, 0) _ c(t, 1) _ c(t, 2) _ c(t, 3) _ c(t, 4) _ c(t, 5) _ c(t, 6) _ c(t, 7) _ c(t, 8) _ c(t, 9) _ c(t, 10) _ c(t, 11) _ c(t, 12) _ c(t, 13) _ c(t, 14) _ c(t, 15) _ c(t, 16) _ c(t, 17) _ c(t, 18) _ c(t, 19)
#define Z_FOR_21_CALL_WITH_TOKEN_AND_INDEX(c, t, _) c(t, 0) _ c(t, 1) _ c(t, 2) _ c(t, 3) _ c(t, 4) _ c(t, 5) _ c(t, 6) _ c(t, 7) _ c(t, 8) _ c(t, 9) _ c(t, 10) _ c(t, 11) _ c(t, 12) _ c(t, 13) _ c(t, 14) _ c(t, 15) _ c(t, 16) _ c(t, 17) _ c(t, 18) _ c(t, 19) _ c(t, 20)
#define Z_FOR_22_CALL_WITH_TOKEN_AND_INDEX(c, t, _) c(t, 0) _ c(t, 1) _ c(t, 2) _ c(t, 3) _ c(t, 4) _ c(t, 5) _ c(t, 6) _ c(t, 7) _ c(t, 8) _ c(t, 9) _ c(t, 10) _ c(t, 11) _ c(t, 12) _ c(t, 13) _ c(t, 14) _ c(t, 15) _ c(t, 16) _ c(t, 17) _ c(t, 18) _ c(t, 19) _ c(t, 20) _ c(t, 21)
#define Z_FOR_23_CALL_WITH_TOKEN_AND_INDEX(c, t, _) c(t, 0) _ c(t, 1) _ c(t, 2) _ c(t, 3) _ c(t, 4) _ c(t, 5) _ c(t, 6) _ c(t, 7) _ c(t, 8) _ c(t, 9) _ c(t, 10) _ c(t, 11) _ c(t, 12) _ c(t, 13) _ c(t, 14) _ c(t, 15) _ c(t, 16) _ c(t, 17) _ c(t, 18) _ c(t, 19) _ c(t, 20) _ c(t, 21) _ c(t, 22)
#define Z_FOR_24_CALL_WITH_TOKEN_AND_INDEX(c, t, _) c(t, 0) _ c(t, 1) _ c(t, 2) _ c(t, 3) _ c(t, 4) _ c(t, 5) _ c(t, 6) _ c(t, 7) _ c(t, 8) _ c(t, 9) _ c(t, 10) _ c(t, 11) _ c(t, 12) _ c(t, 13) _ c(t, 14) _ c(t, 15) _ c(t, 16) _ c(t, 17) _ c(t, 18) _ c(t, 19) _ c(t, 20) _ c(t, 21) _ c(t, 22) _ c(t, 23)
#define Z_FOR_25_CALL_WITH_TOKEN_AND_INDEX(c, t, _) c(t, 0) _ c(t, 1) _ c(t, 2) _ c(t, 3) _ c(t, 4) _ c(t, 5) _ c(t, 6) _ c(t, 7) _ c(t, 8) _ c(t, 9) _ c(t, 10) _ c(t, 11) _ c(t, 12) _ c(t, 13) _ c(t, 14) _ c(t, 15) _ c(t, 16) _ c(t, 17) _ c(t, 18) _ c(t, 19) _ c(t, 20) _ c(t, 21) _ c(t, 22) _ c(t, 23) _ c(t, 24)
#define Z_FOR_26_CALL_WITH_TOKEN_AND_INDEX(c, t, _) c(t, 0) _ c(t, 1) _ c(t, 2) _ c(t, 3) _ c(t, 4) _ c(t, 5) _ c(t, 6) _ c(t, 7) _ c(t, 8) _ c(t, 9) _ c(t, 10) _ c(t, 11) _ c(t, 12) _ c(t, 13) _ c(t, 14) _ c(t, 15) _ c(t, 16) _ c(t, 17) _ c(t, 18) _ c(t, 19) _ c(t, 20) _ c(t, 21) _ c(t, 22) _ c(t, 23) _ c(t, 24) _ c(t, 25)
#define Z_FOR_27_CALL_WITH_TOKEN_AND_INDEX(c, t, _) c(t, 0) _ c(t, 1) _ c(t, 2) _ c(t, 3) _ c(t, 4) _ c(t, 5) _ c(t, 6) _ c(t, 7) _ c(t, 8) _ c(t, 9) _ c(t, 10) _ c(t, 11) _ c(t, 12) _ c(t, 13) _ c(t, 14) _ c(t, 15) _ c(t, 16) _ c(t, 17) _ c(t, 18) _ c(t, 19) _ c(t, 20) _ c(t, 21) _ c(t, 22) _ c(t, 23) _ c(t, 24) _ c(t, 25) _ c(t, 26)
#define Z_FOR_28_CALL_WITH_TOKEN_AND_INDEX(c, t, _) c(t, 0) _ c(t, 1) _ c(t, 2) _ c(t, 3) _ c(t, 4) _ c(t, 5) _ c(t, 6) _ c(t, 7) _ c(t, 8) _ c(t, 9) _ c(t, 10) _ c(t, 11) _ c(t, 12) _ c(t, 13) _ c(t, 14) _ c(t, 15) _ c(t, 16) _ c(t, 17) _ c(t, 18) _ c(t, 19) _ c(t, 20) _ c(t, 21) _ c(t, 22) _ c(t, 23) _ c(t, 24) _ c(t, 25) _ c(t, 26) _ c(t, 27)
#define Z_FOR_29_CALL_WITH_TOKEN_AND_INDEX(c, t, _) c(t, 0) _ c(t, 1) _ c(t, 2) _ c(t, 3) _ c(t, 4) _ c(t, 5) _ c(t, 6) _ c(t, 7) _ c(t, 8) _ c(t, 9) _ c(t, 10) _ c(t, 11) _ c(t, 12) _ c(t, 13) _ c(t, 14) _ c(t, 15) _ c(t, 16) _ c(t, 17) _ c(t, 18) _ c(t, 19) _ c(t, 20) _ c(t, 21) _ c(t, 22) _ c(t, 23) _ c(t, 24) _ c(t, 25) _ c(t, 26) _ c(t, 27) _ c(t, 28)
#define Z_FOR_30_CALL_WITH_TOKEN_AND_INDEX(c, t, _) c(t, 0) _ c(t, 1) _ c(t, 2) _ c(t, 3) _ c(t, 4) _ c(t, 5) _ c(t, 6) _ c(t, 7) _ c(t, 8) _ c(t, 9) _ c(t, 10) _ c(t, 11) _ c(t, 12) _ c(t, 13) _ c(t, 14) _ c(t, 15) _ c(t, 16) _ c(t, 17) _ c(t, 18) _ c(t, 19) _ c(t, 20) _ c(t, 21) _ c(t, 22) _ c(t, 23) _ c(t, 24) _ c(t, 25) _ c(t, 26) _ c(t, 27) _ c(t, 28) _ c(t, 29)
#define Z_FOR_31_CALL_WITH_TOKEN_AND_INDEX(c, t, _) c(t, 0) _ c(t, 1) _ c(t, 2) _ c(t, 3) _ c(t, 4) _ c(t, 5) _ c(t, 6) _ c(t, 7) _ c(t, 8) _ c(t, 9) _ c(t, 10) _ c(t, 11) _ c(t, 12) _ c(t, 13) _ c(t, 14) _ c(t, 15) _ c(t, 16) _ c(t, 17) _ c(t, 18) _ c(t, 19) _ c(t, 20) _ c(t, 21) _ c(t, 22) _ c(t, 23) _ c(t, 24) _ c(t, 25) _ c(t, 26) _ c(t, 27) _ c(t, 28) _ c(t, 29) _ c(t, 30)
#define Z_FOR_32_CALL_WITH_TOKEN_AND_INDEX(c, t, _) c(t, 0) _ c(t, 1) _ c(t, 2) _ c(t, 3) _ c(t, 4) _ c(t, 5) _ c(t, 6) _ c(t, 7) _ c(t, 8) _ c(t, 9) _ c(t, 10) _ c(t, 11) _ c(t, 12) _ c(t, 13) _ c(t, 14) _ c(t, 15) _ c(t, 16) _ c(t, 17) _ c(t, 18) _ c(t, 19) _ c(t, 20) _ c(t, 21) _ c(t, 22) _ c(t, 23) _ c(t, 24) _ c(t, 25) _ c(t, 26) _ c(t, 27) _ c(t, 28) _ c(t, 29) _ c(t, 30) _ c(t, 31)

#define Z_FOR_0_CALL_WITH_TOKEN_AND_TIME( c, t, _)
#define Z_FOR_1_CALL_WITH_TOKEN_AND_TIME( c, t, _) c(t, 1)
#define Z_FOR_2_CALL_WITH_TOKEN_AND_TIME( c, t, _) c(t, 1) _ c(t, 2)
#define Z_FOR_3_CALL_WITH_TOKEN_AND_TIME( c, t, _) c(t, 1) _ c(t, 2) _ c(t, 3)
#define Z_FOR_4_CALL_WITH_TOKEN_AND_TIME( c, t, _) c(t, 1) _ c(t, 2) _ c(t, 3) _ c(t, 4)
#define Z_FOR_5_CALL_WITH_TOKEN_AND_TIME( c, t, _) c(t, 1) _ c(t, 2) _ c(t, 3) _ c(t, 4) _ c(t, 5)
#define Z_FOR_6_CALL_WITH_TOKEN_AND_TIME( c, t, _) c(t, 1) _ c(t, 2) _ c(t, 3) _ c(t, 4) _ c(t, 5) _ c(t, 6)
#define Z_FOR_7_CALL_WITH_TOKEN_AND_TIME( c, t, _) c(t, 1) _ c(t, 2) _ c(t, 3) _ c(t, 4) _ c(t, 5) _ c(t, 6) _ c(t, 7)
#define Z_FOR_8_CALL_WITH_TOKEN_AND_TIME( c, t, _) c(t, 1) _ c(t, 2) _ c(t, 3) _ c(t, 4) _ c(t, 5) _ c(t, 6) _ c(t, 7) _ c(t, 8)
#define Z_FOR_9_CALL_WITH_TOKEN_AND_TIME( c, t, _) c(t, 1) _ c(t, 2) _ c(t, 3) _ c(t, 4) _ c(t, 5) _ c(t, 6) _ c(t, 7) _ c(t, 8) _ c(t, 9)
#define Z_FOR_10_CALL_WITH_TOKEN_AND_TIME(c, t, _) c(t, 1) _ c(t, 2) _ c(t, 3) _ c(t, 4) _ c(t, 5) _ c(t, 6) _ c(t, 7) _ c(t, 8) _ c(t, 9) _ c(t, 10)
#define Z_FOR_11_CALL_WITH_TOKEN_AND_TIME(c, t, _) c(t, 1) _ c(t, 2) _ c(t, 3) _ c(t, 4) _ c(t, 5) _ c(t, 6) _ c(t, 7) _ c(t, 8) _ c(t, 9) _ c(t, 10) _ c(t, 11)
#define Z_FOR_12_CALL_WITH_TOKEN_AND_TIME(c, t, _) c(t, 1) _ c(t, 2) _ c(t, 3) _ c(t, 4) _ c(t, 5) _ c(t, 6) _ c(t, 7) _ c(t, 8) _ c(t, 9) _ c(t, 10) _ c(t, 11) _ c(t, 12)
#define Z_FOR_13_CALL_WITH_TOKEN_AND_TIME(c, t, _) c(t, 1) _ c(t, 2) _ c(t, 3) _ c(t, 4) _ c(t, 5) _ c(t, 6) _ c(t, 7) _ c(t, 8) _ c(t, 9) _ c(t, 10) _ c(t, 11) _ c(t, 12) _ c(t, 13)
#define Z_FOR_14_CALL_WITH_TOKEN_AND_TIME(c, t, _) c(t, 1) _ c(t, 2) _ c(t, 3) _ c(t, 4) _ c(t, 5) _ c(t, 6) _ c(t, 7) _ c(t, 8) _ c(t, 9) _ c(t, 10) _ c(t, 11) _ c(t, 12) _ c(t, 13) _ c(t, 14)
#define Z_FOR_15_CALL_WITH_TOKEN_AND_TIME(c, t, _) c(t, 1) _ c(t, 2) _ c(t, 3) _ c(t, 4) _ c(t, 5) _ c(t, 6) _ c(t, 7) _ c(t, 8) _ c(t, 9) _ c(t, 10) _ c(t, 11) _ c(t, 12) _ c(t, 13) _ c(t, 14) _ c(t, 15)
#define Z_FOR_16_CALL_WITH_TOKEN_AND_TIME(c, t, _) c(t, 1) _ c(t, 2) _ c(t, 3) _ c(t, 4) _ c(t, 5) _ c(t, 6) _ c(t, 7) _ c(t, 8) _ c(t, 9) _ c(t, 10) _ c(t, 11) _ c(t, 12) _ c(t, 13) _ c(t, 14) _ c(t, 15) _ c(t, 16)
#define Z_FOR_17_CALL_WITH_TOKEN_AND_TIME(c, t, _) c(t, 1) _ c(t, 2) _ c(t, 3) _ c(t, 4) _ c(t, 5) _ c(t, 6) _ c(t, 7) _ c(t, 8) _ c(t, 9) _ c(t, 10) _ c(t, 11) _ c(t, 12) _ c(t, 13) _ c(t, 14) _ c(t, 15) _ c(t, 16) _ c(t, 17)
#define Z_FOR_18_CALL_WITH_TOKEN_AND_TIME(c, t, _) c(t, 1) _ c(t, 2) _ c(t, 3) _ c(t, 4) _ c(t, 5) _ c(t, 6) _ c(t, 7) _ c(t, 8) _ c(t, 9) _ c(t, 10) _ c(t, 11) _ c(t, 12) _ c(t, 13) _ c(t, 14) _ c(t, 15) _ c(t, 16) _ c(t, 17) _ c(t, 18)
#define Z_FOR_19_CALL_WITH_TOKEN_AND_TIME(c, t, _) c(t, 1) _ c(t, 2) _ c(t, 3) _ c(t, 4) _ c(t, 5) _ c(t, 6) _ c(t, 7) _ c(t, 8) _ c(t, 9) _ c(t, 10) _ c(t, 11) _ c(t, 12) _ c(t, 13) _ c(t, 14) _ c(t, 15) _ c(t, 16) _ c(t, 17) _ c(t, 18) _ c(t, 19)
#define Z_FOR_20_CALL_WITH_TOKEN_AND_TIME(c, t, _) c(t, 1) _ c(t, 2) _ c(t, 3) _ c(t, 4) _ c(t, 5) _ c(t, 6) _ c(t, 7) _ c(t, 8) _ c(t, 9) _ c(t, 10) _ c(t, 11) _ c(t, 12) _ c(t, 13) _ c(t, 14) _ c(t, 15) _ c(t, 16) _ c(t, 17) _ c(t, 18) _ c(t, 19) _ c(t, 20)
#define Z_FOR_21_CALL_WITH_TOKEN_AND_TIME(c, t, _) c(t, 1) _ c(t, 2) _ c(t, 3) _ c(t, 4) _ c(t, 5) _ c(t, 6) _ c(t, 7) _ c(t, 8) _ c(t, 9) _ c(t, 10) _ c(t, 11) _ c(t, 12) _ c(t, 13) _ c(t, 14) _ c(t, 15) _ c(t, 16) _ c(t, 17) _ c(t, 18) _ c(t, 19) _ c(t, 20) _ c(t, 21)
#define Z_FOR_22_CALL_WITH_TOKEN_AND_TIME(c, t, _) c(t, 1) _ c(t, 2) _ c(t, 3) _ c(t, 4) _ c(t, 5) _ c(t, 6) _ c(t, 7) _ c(t, 8) _ c(t, 9) _ c(t, 10) _ c(t, 11) _ c(t, 12) _ c(t, 13) _ c(t, 14) _ c(t, 15) _ c(t, 16) _ c(t, 17) _ c(t, 18) _ c(t, 19) _ c(t, 20) _ c(t, 21) _ c(t, 22)
#define Z_FOR_23_CALL_WITH_TOKEN_AND_TIME(c, t, _) c(t, 1) _ c(t, 2) _ c(t, 3) _ c(t, 4) _ c(t, 5) _ c(t, 6) _ c(t, 7) _ c(t, 8) _ c(t, 9) _ c(t, 10) _ c(t, 11) _ c(t, 12) _ c(t, 13) _ c(t, 14) _ c(t, 15) _ c(t, 16) _ c(t, 17) _ c(t, 18) _ c(t, 19) _ c(t, 20) _ c(t, 21) _ c(t, 22) _ c(t, 23)
#define Z_FOR_24_CALL_WITH_TOKEN_AND_TIME(c, t, _) c(t, 1) _ c(t, 2) _ c(t, 3) _ c(t, 4) _ c(t, 5) _ c(t, 6) _ c(t, 7) _ c(t, 8) _ c(t, 9) _ c(t, 10) _ c(t, 11) _ c(t, 12) _ c(t, 13) _ c(t, 14) _ c(t, 15) _ c(t, 16) _ c(t, 17) _ c(t, 18) _ c(t, 19) _ c(t, 20) _ c(t, 21) _ c(t, 22) _ c(t, 23) _ c(t, 24)
#define Z_FOR_25_CALL_WITH_TOKEN_AND_TIME(c, t, _) c(t, 1) _ c(t, 2) _ c(t, 3) _ c(t, 4) _ c(t, 5) _ c(t, 6) _ c(t, 7) _ c(t, 8) _ c(t, 9) _ c(t, 10) _ c(t, 11) _ c(t, 12) _ c(t, 13) _ c(t, 14) _ c(t, 15) _ c(t, 16) _ c(t, 17) _ c(t, 18) _ c(t, 19) _ c(t, 20) _ c(t, 21) _ c(t, 22) _ c(t, 23) _ c(t, 24) _ c(t, 25)
#define Z_FOR_26_CALL_WITH_TOKEN_AND_TIME(c, t, _) c(t, 1) _ c(t, 2) _ c(t, 3) _ c(t, 4) _ c(t, 5) _ c(t, 6) _ c(t, 7) _ c(t, 8) _ c(t, 9) _ c(t, 10) _ c(t, 11) _ c(t, 12) _ c(t, 13) _ c(t, 14) _ c(t, 15) _ c(t, 16) _ c(t, 17) _ c(t, 18) _ c(t, 19) _ c(t, 20) _ c(t, 21) _ c(t, 22) _ c(t, 23) _ c(t, 24) _ c(t, 25) _ c(t, 26)
#define Z_FOR_27_CALL_WITH_TOKEN_AND_TIME(c, t, _) c(t, 1) _ c(t, 2) _ c(t, 3) _ c(t, 4) _ c(t, 5) _ c(t, 6) _ c(t, 7) _ c(t, 8) _ c(t, 9) _ c(t, 10) _ c(t, 11) _ c(t, 12) _ c(t, 13) _ c(t, 14) _ c(t, 15) _ c(t, 16) _ c(t, 17) _ c(t, 18) _ c(t, 19) _ c(t, 20) _ c(t, 21) _ c(t, 22) _ c(t, 23) _ c(t, 24) _ c(t, 25) _ c(t, 26) _ c(t, 27)
#define Z_FOR_28_CALL_WITH_TOKEN_AND_TIME(c, t, _) c(t, 1) _ c(t, 2) _ c(t, 3) _ c(t, 4) _ c(t, 5) _ c(t, 6) _ c(t, 7) _ c(t, 8) _ c(t, 9) _ c(t, 10) _ c(t, 11) _ c(t, 12) _ c(t, 13) _ c(t, 14) _ c(t, 15) _ c(t, 16) _ c(t, 17) _ c(t, 18) _ c(t, 19) _ c(t, 20) _ c(t, 21) _ c(t, 22) _ c(t, 23) _ c(t, 24) _ c(t, 25) _ c(t, 26) _ c(t, 27) _ c(t, 28)
#define Z_FOR_29_CALL_WITH_TOKEN_AND_TIME(c, t, _) c(t, 1) _ c(t, 2) _ c(t, 3) _ c(t, 4) _ c(t, 5) _ c(t, 6) _ c(t, 7) _ c(t, 8) _ c(t, 9) _ c(t, 10) _ c(t, 11) _ c(t, 12) _ c(t, 13) _ c(t, 14) _ c(t, 15) _ c(t, 16) _ c(t, 17) _ c(t, 18) _ c(t, 19) _ c(t, 20) _ c(t, 21) _ c(t, 22) _ c(t, 23) _ c(t, 24) _ c(t, 25) _ c(t, 26) _ c(t, 27) _ c(t, 28) _ c(t, 29)
#define Z_FOR_30_CALL_WITH_TOKEN_AND_TIME(c, t, _) c(t, 1) _ c(t, 2) _ c(t, 3) _ c(t, 4) _ c(t, 5) _ c(t, 6) _ c(t, 7) _ c(t, 8) _ c(t, 9) _ c(t, 10) _ c(t, 11) _ c(t, 12) _ c(t, 13) _ c(t, 14) _ c(t, 15) _ c(t, 16) _ c(t, 17) _ c(t, 18) _ c(t, 19) _ c(t, 20) _ c(t, 21) _ c(t, 22) _ c(t, 23) _ c(t, 24) _ c(t, 25) _ c(t, 26) _ c(t, 27) _ c(t, 28) _ c(t, 29) _ c(t, 30)
#define Z_FOR_31_CALL_WITH_TOKEN_AND_TIME(c, t, _) c(t, 1) _ c(t, 2) _ c(t, 3) _ c(t, 4) _ c(t, 5) _ c(t, 6) _ c(t, 7) _ c(t, 8) _ c(t, 9) _ c(t, 10) _ c(t, 11) _ c(t, 12) _ c(t, 13) _ c(t, 14) _ c(t, 15) _ c(t, 16) _ c(t, 17) _ c(t, 18) _ c(t, 19) _ c(t, 20) _ c(t, 21) _ c(t, 22) _ c(t, 23) _ c(t, 24) _ c(t, 25) _ c(t, 26) _ c(t, 27) _ c(t, 28) _ c(t, 29) _ c(t, 30) _ c(t, 31)
#define Z_FOR_32_CALL_WITH_TOKEN_AND_TIME(c, t, _) c(t, 1) _ c(t, 2) _ c(t, 3) _ c(t, 4) _ c(t, 5) _ c(t, 6) _ c(t, 7) _ c(t, 8) _ c(t, 9) _ c(t, 10) _ c(t, 11) _ c(t, 12) _ c(t, 13) _ c(t, 14) _ c(t, 15) _ c(t, 16) _ c(t, 17) _ c(t, 18) _ c(t, 19) _ c(t, 20) _ c(t, 21) _ c(t, 22) _ c(t, 23) _ c(t, 24) _ c(t, 25) _ c(t, 26) _ c(t, 27) _ c(t, 28) _ c(t, 29) _ c(t, 30) _ c(t, 31) _ c(t, 32)

#endif /* Z_macros_iteration_H */
