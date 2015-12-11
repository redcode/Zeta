/* Z Kit C API - functions/assembly/x86/x86-64/value.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_functions_assembly_x86_x86_64_value_H__
#define __Z_functions_assembly_x86_x86_64_value_H__

#include <Z/types/base.h>


Z_INLINE zboolean z_uint32_set_if_equal(
	zuint32* value,
	zuint32  test_value,
	zuint32  new_value
)
	{
	zboolean result;

	mov		eax,edi
	lock cmpxchg	[rdx],esi
	sete		al
	movzx		rax,al
	ret

	return result;
	}


#endif /* __Z_functions_assembly_x86_x86_64_value_H__ */
