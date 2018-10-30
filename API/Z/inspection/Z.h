/* Z Kit - inspection/Z.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.

This library  is free software: you  can redistribute it and/or  modify it under
the terms  of the  GNU Lesser General  Public License as  published by  the Free
Software Foundation,  either version 3 of  the License, or (at  your option) any
later version.

This library is distributed in the hope  that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty  of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

You should have received  a copy of the GNU Lesser  General Public License along
with this library. If not, see <http://www.gnu.org/licenses/>. */

#ifndef _Z_inspection_Z_H_
#define _Z_inspection_Z_H_

#define Z_HAS(		  WHAT ) Z_HAS_##WHAT
#define Z_HAS_CLASS(	  Which) Z_HAS_CLASS_##Which
#define Z_HAS_TRAIT(	  Which) Z_HAS_TRAIT_##Which
#define Z_HAS_TRAIT_ALIAS(which) Z_HAS_TRAIT_ALIAS_##which

#define Z_TRAIT_HAS(Trait, what) Z_TRAIT_##Trait##_HAS_##what

#endif /* _Z_inspection_Z_H_ */
