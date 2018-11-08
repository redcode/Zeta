/* Z Kit - keys/data model.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_keys_data_model_H_
#define _Z_keys_data_model_H_

#define Z_DATA_MODEL_IP16L32 1
#define Z_DATA_MODEL_I16LP32 2
#define Z_DATA_MODEL_LP32    3
#define Z_DATA_MODEL_ILP32   4
#define Z_DATA_MODEL_LLP64   5
#define Z_DATA_MODEL_LP64    6
#define Z_DATA_MODEL_ILP64   7
#define Z_DATA_MODEL_SILP64  8

#define Z_KEY_BITS_DATA_MODEL 8
#define Z_KEY_LAST_DATA_MODEL Z_DATA_MODEL_SILP64

#define Z_DATA_MODEL_STRING_IP16L32 "IP16L32"
#define Z_DATA_MODEL_STRING_I16LP32 "I16LP32"
#define Z_DATA_MODEL_STRING_LP32    "LP32"
#define Z_DATA_MODEL_STRING_ILP32   "ILP32"
#define Z_DATA_MODEL_STRING_LP64    "LP64"
#define Z_DATA_MODEL_STRING_LLP64   "LLP64"
#define Z_DATA_MODEL_STRING_ILP64   "ILP64"
#define Z_DATA_MODEL_STRING_SILP64  "SILP64"

#endif /* _Z_keys_data_model_H_ */
