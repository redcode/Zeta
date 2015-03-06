/* Q C API - functions/assembly/x86/x86-64/CPU.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_functions_assembly_x86_x86_64_CPU_H__
#define __Q_functions_assembly_x86_x86_64_CPU_H__


#define q_cpu_relax() asm volatile("pause\n": : :"memory")


#endif /* __Q_functions_assembly_x86_x86_64_CPU_H__ */
