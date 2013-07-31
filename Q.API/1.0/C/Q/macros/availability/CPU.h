/* Q API - macros/availability/CPU.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2012 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_macros_availability_CPU_H__
#define __Q_macros_availability_CPU_H__

#include <Q/inspection/CPU.h>
#include <Q/inspection/compiler.h>

#if Q_CPU_IS_CAPABLE_OF(8BIT_ATOMICS)
#	define Q_AVAILABLE_IF_CPU_IS_CAPABLE_OF_8BIT_ATOMICS
#else
#	define Q_AVAILABLE_IF_CPU_IS_CAPABLE_OF_8BIT_ATOMICS \
		Q_ATTRIBUTE_UNAVAILABLE("The target CPU does not support 8-bit atomic operations")
#endif

#if Q_CPU_IS_CAPABLE_OF(16BIT_ATOMICS)
#	define Q_AVAILABLE_IF_CPU_IS_CAPABLE_OF_16BIT_ATOMICS
#else
#	define Q_AVAILABLE_IF_CPU_IS_CAPABLE_OF_16BIT_ATOMICS \
		Q_ATTRIBUTE_UNAVAILABLE("The target CPU does not support 16-bit atomic operations")
#endif

#if Q_CPU_IS_CAPABLE_OF(32BIT_ATOMICS)
#	define Q_AVAILABLE_IF_CPU_IS_CAPABLE_OF_32BIT_ATOMICS
#else
#	define Q_AVAILABLE_IF_CPU_IS_CAPABLE_OF_32BIT_ATOMICS \
		Q_ATTRIBUTE_UNAVAILABLE("The target CPU does not support 32-bit atomic operations")
#endif

#if Q_CPU_IS_CAPABLE_OF(64BIT_ATOMICS)
#	define Q_AVAILABLE_IF_CPU_IS_CAPABLE_OF_64BIT_ATOMICS
#else
#	define Q_AVAILABLE_IF_CPU_IS_CAPABLE_OF_64BIT_ATOMICS \
		Q_ATTRIBUTE_UNAVAILABLE("The target CPU does not support 64-bit atomic operations")
#endif

#if Q_CPU_IS_CAPABLE_OF(128BIT_ATOMICS)
#	define Q_AVAILABLE_IF_CPU_IS_CAPABLE_OF_128BIT_ATOMICS
#else
#	define Q_AVAILABLE_IF_CPU_IS_CAPABLE_OF_128BIT_ATOMICS \
		Q_ATTRIBUTE_UNAVAILABLE("The target CPU does not support 16-bit atomic operations")
#endif

#endif /* __Q_macros_availability_CPU_H__ */
