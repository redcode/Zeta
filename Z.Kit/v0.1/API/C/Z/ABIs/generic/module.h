/* Z Kit C API - ABIs/generic/module.h
	      ___
 _____	____ /	/______
/_   /_/  -_)  __/  _ /
 /____/\___/\__/ \__,_/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_ABIs_generic_module_H__
#define __Z_ABIs_generic_module_H__

#include <Z/types/base.h>
#include <Z/macros/version.h>

typedef struct {
	zcharacter const* identifier;
	zcharacter const* name;
	zuint64		  version;
	zcharacter const* information;
	void const*	  abi;
} ZModuleUnit;

typedef struct {
	zcharacter const*  identifier;
	zuint64		   abi_version;
	zsize		   unit_count;
	ZModuleUnit const* units;
} ZModuleDomain;

typedef struct {
	zsize		     domain_count;
	ZModuleDomain const* domains;
} ZModuleABI;

#endif /* __Z_ABIs_generic_module_H__ */
