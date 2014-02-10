/* Q API - types/introspection.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2014 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_types_introspection_H__
#define __Q_types_introspection_H__

#include <Q/types/base.h>

typedef quint8 QVariableType;

typedef struct {
	QString*     name;
	QType	     type;
	QValueFormat format;
} QValueTypePrototype;

typedef struct {
	QString*	name;
	qsize		offset;
	QVariableType	type;
	void*		prototype;
} QStructureMemberPrototype;

typedef struct {
} QStructureTypePrototype;

typedef struct {
	QString*      name;
	QVariableType type;
	void*	      prototype;
} QVariablePrototype;

typedef struct {
} QFunctionPrototype;


#endif /* __Q_types_introspection_H__ */
