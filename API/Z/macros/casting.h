/* Zeta API - Z/macros/casting.h
 ______  ______________  ___
|__   / |  ___|___  ___|/   \
  /  /__|  __|   |  |  /  -  \
 /______|_____|  |__| /__/ \__\
Copyright (C) 2006-2025 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef Z_macros_casting_H
#define Z_macros_casting_H

#ifdef __cplusplus
#	define Z_CAST(		  type)			 type
#	define Z_CONST_CAST(	  type) const_cast	<type>
#	define Z_REINTERPRET_CAST(type) reinterpret_cast<type>
#	define Z_STATIC_CAST(	  type) static_cast	<type>
#else
#	define Z_CAST
#	define Z_CONST_CAST
#	define Z_REINTERPRET_CAST
#	define Z_STATIC_CAST
#endif

#endif /* Z_macros_casting_H */
