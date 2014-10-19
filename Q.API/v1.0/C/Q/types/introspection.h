/* Q API - types/introspection.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2014 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_types_introspection_H__
#define __Q_types_introspection_H__

#include <Q/types/data.h>
#include <Q/keys/introspection.h>

typedef quint8 QVariableType;

typedef struct {
	QString*	     name;
	qsize		     count;
	void*		     description;
	QVariableType	     type;
} QVariableDescription;

typedef struct {
	QString*	     type_name;
	QValueType	     type;
	QValueFormat	     format;
} QValueDescription;

typedef struct {
	QString*	     type_name;
	QArray		     members;
} QStructureDescription;

typedef struct {
	qsize		     offset;
	QVariableDescription variable;
} QStructureMemberDescription;

typedef struct {

} QFunctionDescription;

typedef struct {
	QString*   name;
	qsize	   offset;
	QValueType type;
} QContextValue;

typedef struct {
	QString*	name;
	qsize		offset;
	void*		mask;
	quint8		container_size;
} QContextBits;

#define Q_VARIABLE_DESCRIPTION(        p) ((QVariableDescription	*)(p))
#define Q_VALUE_DESCRIPTION(	       p) ((QValueDescription		*)(p))
#define Q_STRUCTURE_DESCRIPTION(       p) ((QStructureDescription	*)(p))
#define Q_STRUCTURE_MEMBER_DESCRIPTION(p) ((QStructureMemberDescription *)(p))
#define Q_CONTEXT_VALUE(	       p) ((QCOntextValue		*)(p))

#endif /* __Q_types_introspection_H__ */
