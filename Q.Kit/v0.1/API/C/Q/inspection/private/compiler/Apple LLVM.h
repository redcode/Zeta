/* Q Kit C API - inspection/private/compiler/Apple LLVM.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_inspection_private_compiler_Apple_LLVM_H__
#define __Q_inspection_private_compiler_Apple_LLVM_H__

/* MARK: - Identification */

#ifndef Q_COMPILER
#	include <Q/keys/compiler.h>
#	include <Q/macros/version.h>

#	define Q_COMPILER		  Q_COMPILER_APPLE_LLVM
#	define Q_COMPILER_STRING	  Q_COMPILER_STRING_APPLE_LLVM
#	define Q_COMPILER_VERSION	  Q_VERSION(__clang_major__, __clang_minor__, __clang_patchlevel__)
#	define Q_COMPILER_VERSION_STRING __clang_version__
#endif

/* MARK: - Inherited */

#include <Q/inspection/private/compiler/Clang.h>

#endif /* __Q_inspection_private_compiler_Apple_LLVM_H__ */
