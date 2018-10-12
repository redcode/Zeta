/* Z Kit - ABIs/generic/module.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_ABIs_generic_module_H_
#define _Z_ABIs_generic_module_H_

#include <Z/types/base.h>
#include <Z/macros/version.h>

typedef struct {
	zchar const* identifier;
	zchar const* name;
	zuint64	     version;
	void const*  abi;
} ZModuleUnit;

typedef struct {
	zchar const*	   identifier;
	zuint64		   abi_version;
	zusize		   unit_count;
	ZModuleUnit const* units;
} ZModuleDomain;

typedef struct {
	zusize		     domain_count;
	ZModuleDomain const* domains;
} ZModuleABI;

#endif /* _Z_ABIs_generic_module_H_ */
