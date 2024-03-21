/* Zeta API - Z/inspection/Z.h
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_inspection_Z_H
#define Z_inspection_Z_H

#include <Z/macros/token.h>

#define Z_HAS(type_or_identifier ) Z_IS_TRUE(Z_HAS_##type_or_identifier)
#define Z_HAS_MEMBER(type, member) Z_IS_TRUE(Z_HAS_##type##_MEMBER_##member)

#endif /* Z_inspection_Z_H */
