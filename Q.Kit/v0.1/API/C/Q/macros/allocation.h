/* Q C API - macros/allocation.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_macros_allocation_H__
#define __Q_macros_allocation_H__

#include <Q/keys/allocation.h>

#define	Q_ALLOCATE(size, domain)						\
	object->zone->abi->allocate(object->zone->context, size, domain)

#define	Q_ALLOCATE_AND_CLEAN(domain, size)					\
	object->zone->abi->allocate_and_clean					\
		(object->zone->context, size, domain)

#define	Q_REALLOCATE(domain, block, new_size)					\
	object->zone->abi->reallocate						\
		(object->zone->context, domain, block, new_size)

#define	Q_DEALLOCATE(block)							\
	object->zone->abi->deallocate(object->zone->context, block)

#define Q_LOCAL_ALLOCATE(domain, size)						\
	object_zone->abi->allocate(object_zone->context, domain, size)

#define	Q_LOCAL_ALLOCATE_AND_CLEAN(domain, size)				\
	object_zone->abi->allocate_and_clean					\
		(object_zone->context, domain, 1, size)

#define Q_LOCAL_DEALLOCATE(block)						\
	object_zone->abi->deallocate(object_zone->context, block)

#define Q_LOCAL_ALLOCATE_PSEUDO_OBJECT(type)					\
	object_zone->abi->allocate_and_clean					\
		(object_zone->context,						\
		 Q_ALLOCATION_DOMAIN_PSEUDO_OBJECT, 1, sizeof(type));

#endif /* __Q_macros_allocation_H__ */
