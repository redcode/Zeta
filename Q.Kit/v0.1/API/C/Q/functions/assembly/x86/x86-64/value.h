/* Q C API - functions/assembly/x86/x86-64/value.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_functions_assembly_x86_x86_64_value_H__
#define __Q_functions_assembly_x86_x86_64_value_H__

#include <Q/types/base.h>


Q_INLINE qboolean q_uint32_set_if_equal(
	quint32* value,
	quint32  test_value,
	quint32  new_value
)
	{
	qboolean result;

	mov		eax,edi
	lock cmpxchg	[rdx],esi
	sete		al
	movzx		rax,al
	ret

	return result;
	}


#endif /* __Q_functions_assembly_x86_x86_64_value_H__ */
