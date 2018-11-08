/* Z Kit - inspection/modules/compiler/Apple LLVM.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_inspection_modules_compiler_Apple_LLVM_H_
#define _Z_inspection_modules_compiler_Apple_LLVM_H_

/* MARK: - Identification */

#ifndef Z_COMPILER
#	include <Z/macros/version.h>

#	define Z_COMPILER		  Z_COMPILER_APPLE_LLVM
#	define Z_COMPILER_STRING	  Z_COMPILER_STRING_APPLE_LLVM
#	define Z_COMPILER_VERSION	  Z_VERSION(__clang_major__, __clang_minor__, __clang_patchlevel__)
#	define Z_COMPILER_VERSION_STRING __clang_version__
#endif

/* MARK: - Inherited */

#include <Z/inspection/compiler/modules/Clang.h>

#endif /* _Z_inspection_modules_compiler_Apple_LLVM_H_ */
