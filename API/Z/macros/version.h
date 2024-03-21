/* Zeta API - Z/macros/version.h
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2024 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_macros_version_H
#define Z_macros_version_H

#define Z_VERSION(major, minor, micro) \
	((major) * 4194304UL + (minor) * 4096UL + (micro))

#define Z_VERSION_MAJOR(version) \
	((version) / 4194304UL)

#define Z_VERSION_MINOR(version) \
	(((version) % 4194304UL) / 4096UL)

#define Z_VERSION_MICRO(version) \
	((version) & 0xFFFUL)

#endif /* Z_macros_version_H */
