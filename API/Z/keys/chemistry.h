/* Z Kit - keys/chemistry.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_keys_chemistry_H_
#define _Z_keys_chemistry_H_

#define Z_ELECTRICAL_TYPE_CONDUCTOR	0
#define Z_ELECTRICAL_TYPE_SEMICONDUCTOR 1
#define Z_ELECTRICAL_TYPE_INSULATOR	2

#define Z_KEY_BITS_ELECTRICAL_TYPE 8
#define Z_KEY_LAST_ELECTRICAL_TYPE Z_ELECTRICAL_TYPE_INSULATOR

#define Z_MAGNETIC_TYPE_DIAMAGNETIC	  0
#define Z_MAGNETIC_TYPE_PARAMAGNETIC	  1
#define Z_MAGNETIC_TYPE_ANTIFERROMAGNETIC 2
#define Z_MAGNETIC_TYPE_FERROMAGNETIC	  3

#define Z_KEY_BITS_ELECTRICAL_TYPE 8
#define Z_KEY_LAST_MAGNETIC_TYPE Z_MAGNETIC_TYPE_FERROMAGNETIC

#endif /* _Z_keys_chemistry_H_ */
