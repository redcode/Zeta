/* Q API - keys/data model.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_keys_data_model_H__
#define __Q_keys_data_model_H__

#define Q_DATA_MODEL_LP32   0
#define Q_DATA_MODEL_ILP32  1
#define Q_DATA_MODEL_LLP64  2
#define Q_DATA_MODEL_LP64   3
#define Q_DATA_MODEL_ILP64  4
#define Q_DATA_MODEL_SILP64 5

#define Q_KEY_BITS_DATA_MODEL 8
#define Q_KEY_LAST_DATA_MODEL Q_DATA_MODEL_SILP64

#define Q_DATA_MODEL_STRING_LP32   "LP32"
#define Q_DATA_MODEL_STRING_ILP32  "ILP32"
#define Q_DATA_MODEL_STRING_LP64   "LP64"
#define Q_DATA_MODEL_STRING_LLP64  "LLP64"
#define Q_DATA_MODEL_STRING_ILP64  "ILP64"
#define Q_DATA_MODEL_STRING_SILP64 "SILP64"

#endif /* __Q_keys_data_model_H__ */
