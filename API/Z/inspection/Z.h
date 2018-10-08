/* Z Kit - inspection/Z.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_inspection_Z_H__
#define __Z_inspection_Z_H__

#define Z_HAS(		  WHAT ) Z_HAS_##WHAT
#define Z_HAS_CLASS(	  Which) Z_HAS_CLASS_##Which
#define Z_HAS_TRAIT(	  Which) Z_HAS_TRAIT_##Which
#define Z_HAS_TRAIT_ALIAS(which) Z_HAS_TRAIT_ALIAS_##which

#define Z_TRAIT_HAS(Trait, what) Z_TRAIT_##Trait##_HAS_##what

#endif /* __Z_inspection_Z_H__ */
