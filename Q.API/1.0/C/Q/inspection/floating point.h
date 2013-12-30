/* Q API - inspection/floating point.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2014 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_inspection_floating_point_H__
#define __Q_inspection_floating_point_H__

#include <Q/inspection/CPU.h>

/*#if	Q_CPU_ARCHITECTURE == Q_CPU_ARCHITECTURE_X86_32		|| \
	Q_CPU_ARCHITECTURE == Q_CPU_ARCHITECTURE_X86_64		|| \
	Q_CPU_ARCHITECTURE == Q_CPU_ARCHITECTURE_POWER_PC_32	|| \
	Q_CPU_ARCHITECTURE == Q_CPU_ARCHITECTURE_POWER_PC_64*/

#	define	Q_FLOATING_POINT_NAME IEEE 754 LD64

/*#endif*/

#define Q_FLOATING_POINT_HEADER \
	<Q/inspection/private/floating point/Q_FLOATING_POINT_NAME.h>

#include Q_FLOATING_POINT_HEADER

#endif /* __Q_inspection_floating_point_H__ */
