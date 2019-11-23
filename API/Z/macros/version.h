/* Z Kit - macros/version.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//__/__| Kit
Copyright (C) 2006-2020 Manuel Sainz de Baranda y Goñi.
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

#define Z_VERSION_IS_BETWEEN(				      \
	version,					      \
	a_major, a_minor, a_micro,			      \
	b_major, b_minor, b_micro			      \
)							      \
	((version) >= Z_VERSION(a_major, a_minor, a_micro) && \
	 (version) <= Z_VERSION(b_major, b_minor, b_micro))

#endif /* Z_macros_version_H */

