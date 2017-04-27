/* Z Kit C API - keys/data model.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright © 2006-2017 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_keys_data_model_H__
#define __Z_keys_data_model_H__

#define Z_DATA_MODEL_LP32   0
#define Z_DATA_MODEL_ILP32  1
#define Z_DATA_MODEL_LLP64  2
#define Z_DATA_MODEL_LP64   3
#define Z_DATA_MODEL_ILP64  4
#define Z_DATA_MODEL_SILP64 5

#define Z_KEY_BITS_DATA_MODEL 8
#define Z_KEY_LAST_DATA_MODEL Z_DATA_MODEL_SILP64

#define Z_DATA_MODEL_STRING_LP32   "LP32"
#define Z_DATA_MODEL_STRING_ILP32  "ILP32"
#define Z_DATA_MODEL_STRING_LP64   "LP64"
#define Z_DATA_MODEL_STRING_LLP64  "LLP64"
#define Z_DATA_MODEL_STRING_ILP64  "ILP64"
#define Z_DATA_MODEL_STRING_SILP64 "SILP64"

#endif /* __Z_keys_data_model_H__ */
