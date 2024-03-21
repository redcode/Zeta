/* Zeta API - Z/macros/hash.h
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_macros_hash_H
#define Z_macros_hash_H

#include <Z/types/integral.h>

/* MARK: - FNV-0 */

#define Z_FNV0_32_INITIALIZER 0
#define Z_FNV0_32_UPDATE(hash, value) (((hash) * Z_UINT32(0x01000193)) ^ (value))

#ifdef Z_UINT64
#	define Z_FNV0_64_INITIALIZER 0
#	define Z_FNV0_64_UPDATE(hash, value) (((hash) * Z_UINT64(0x00000100000001B3)) ^ (value))
#endif

/* MARK: - FNV-1 */

#define Z_FNV1_32_INITIALIZER Z_UINT32(0x811C9DC5)
#define Z_FNV1_32_UPDATE Z_FNV0_32_UPDATE

#ifdef Z_UINT64
#	define Z_FNV1_64_INITIALIZER Z_UINT64(0xCBF29CE484222325)
#	define Z_FNV1_64_UPDATE Z_FNV0_64_UPDATE
#endif

/* MARK: - FNV-1a */

#define Z_FNV1A_32_INITIALIZER Z_FNV1_32_INITIALIZER
#define Z_FNV1A_32_UPDATE(hash, value) (((hash) ^ (value)) * Z_UINT32(0x01000193))

#ifdef Z_UINT64
#	define Z_FNV1A_64_INITIALIZER Z_FNV1_64_INITIALIZER
#	define Z_FNV1A_64_UPDATE(hash, value) (((hash) ^ (value)) * Z_UINT64(0x00000100000001B3))
#endif

#endif /* Z_macros_hash_H */
