/* Z Kit - macros/version.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_macros_version_H_
#define _Z_macros_version_H_

#define Z_VERSION(major, minor, micro) ((major) * 4194304UL + (minor) * 4096UL + (micro))
#define Z_VERSION_MAJOR(version) ((version) / 4194304UL)
#define Z_VERSION_MINOR(version) (((version) % 4194304UL) / 4096UL)
#define Z_VERSION_MICRO(version) ((version) & 0xFFFUL)

#endif /* _Z_macros_version_H_ */
 
