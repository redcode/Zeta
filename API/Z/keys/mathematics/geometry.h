/* Z Kit - keys/mathematics/geometry.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.

This library is  free software: you can redistribute it  and/or modify it under
the terms  of the GNU  Lesser General Public License  as published by  the Free
Software Foundation, either  version 3 of the License, or  (at your option) any
later version.

This library is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

You should have received  a copy of the GNU Lesser General Public License along
with this library. If not, see <http://www.gnu.org/licenses/>. */

#ifndef _Z_keys_mathematics_geometry_H_
#define _Z_keys_mathematics_geometry_H_

#define Z_BRAVAIS_LATTICE_TRICLINIC_P	  1
#define Z_BRAVAIS_LATTICE_MONOCLINIC_P	  2
#define Z_BRAVAIS_LATTICE_MONOCLINIC_C	  3
#define Z_BRAVAIS_LATTICE_ORTHORHOMBIC_P  4
#define Z_BRAVAIS_LATTICE_ORTHORHOMBIC_C  5
#define Z_BRAVAIS_LATTICE_ORTHORHOMBIC_I  6
#define Z_BRAVAIS_LATTICE_ORTHORHOMBIC_F  7
#define Z_BRAVAIS_LATTICE_TETRAGONAL_P	  8
#define Z_BRAVAIS_LATTICE_TETRAGONAL_I	  9
#define Z_BRAVAIS_LATTICE_RHOMBOHEDRAL_P 10
#define Z_BRAVAIS_LATTICE_HEXAGONAL_P	 11
#define Z_BRAVAIS_LATTICE_CUBIC_P	 12
#define Z_BRAVAIS_LATTICE_CUBIC_I	 13
#define Z_BRAVAIS_LATTICE_CUBIC_F	 14

#define Z_KEY_BITS_BRAVAIS_LATTICE 8
#define Z_KEY_LAST_BRAVAIS_LATTICE Z_BRAVAIS_LATTICE_CUBIC_F

#endif /* _Z_keys_mathematics_geometry_H_ */
