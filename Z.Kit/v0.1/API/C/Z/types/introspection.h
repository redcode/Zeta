/* Z Kit C API - types/introspection.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_types_introspection_H__
#define __Z_types_introspection_H__

#include <Z/types/data.h>
#include <Z/keys/introspection.h>
#include <Z/macros/key.h>

typedef struct {
	ZString*	    name;
	zsize		    count;
	void*		    description;
	ZKey(VARIABLE_TYPE) type;
} ZVariableDescription;

typedef struct {
	ZString*	   type_name;
	ZKey(VALUE_TYPE)   type;
	ZKey(VALUE_FORMAT) format;
} ZValueDescription;

typedef struct {
	ZString* type_name;
	ZArray   members;
} ZStructureDescription;

typedef struct {
	zsize		     offset;
	ZVariableDescription variable;
} ZStructureMemberDescription;

typedef struct {

} ZFunctionDescription;

typedef struct {
	ZString*	 name;
	zsize		 offset;
	ZKey(VALUE_TYPE) type;
} ZContextValue;

typedef struct {
	ZString* name;
	zsize	 offset;
	void*	 mask;
	zuint8	 container_size;
} ZContextBits;

#endif /* __Z_types_introspection_H__ */
