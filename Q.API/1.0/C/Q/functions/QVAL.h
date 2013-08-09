/* Q API - functions/QVAL.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2013 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU General Public License v3. */

#ifndef __Q_functions_QVAL_H__
#define __Q_functions_QVAL_H__

#include <Q/types/language.h>

#if Q_COMPILER_HAS(VAL)

#	define q_val_initialize	Q_COMPILER_FUNCTION_VAL_INITIALIZE
#	define q_val_finalize	Q_COMPILER_FUNCTION_VAL_FINALIZE
#	define q_val_read	Q_COMPILER_FUNCTION_VAL_READ
#	define q_val_copy	Q_COMPILER_FUNCTION_VAL_COPY

#endif

#endif /* __Q_functions_QVAL_H__ */
