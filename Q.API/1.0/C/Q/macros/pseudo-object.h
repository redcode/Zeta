/* Q API - macros/pseudo-object.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2012 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_macros_pseudo_object_H__
#define __Q_macros_pseudo_object_H__

#if defined(USE_PSEUDO_OBJECTS_WITH_ZONE)
#	define Q_PSEUDO_OBJECT_MEMBER_DECLARATION_ZONE QZone *zone;
#else
#	define Q_PSEUDO_OBJECT_MEMBER_DECLARATION_ZONE
#endif

#include <Q/types/allocation.h>

#define Q_PSEUDO_OBJECT(members)		\
struct {Q_PSEUDO_OBJECT_MEMBER_DECLARATION_ZONE	\
	members					\
}

#define Q_STRICT_PSEUDO_OBJECT(members)		\
Q_STRICT_STRUCTURE(				\
	Q_PSEUDO_OBJECT_MEMBER_DECLARATION_ZONE	\
	members					\
)

#define Q_RETAINABLE_PSEUDO_OBJECT(members)	\
struct {qsize retain_count;			\
	Q_PSEUDO_OBJECT_MEMBER_DECLARATION_ZONE	\
	members					\
}

#define Q_STRICT_RETAINABLE_PSEUDO_OBJECT(members)	\
Q_STRICT_STRUCTURE(					\
	qsize retain_count;				\
	Q_PSEUDO_OBJECT_MEMBER_DECLARATION_ZONE		\
	members						\
)

#define Q_STRICT_PSEUDO_OBJECT_SIZE (Q_POINTER_SIZE * 2)

#define Q_INMUTABLE(p)		(((void *)p) - sizeof(Q_PSEUDO_OBJECT()))
#define Q_STRICT_INMUTABLE(p)	(((void *)p) - sizeof(Q_STRICT_PSEUDO_OBJECT()))

#endif /* __Q_macros_pseudo_object_H__ */
