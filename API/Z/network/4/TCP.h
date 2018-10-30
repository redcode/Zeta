/* Z Kit - network/4/TCP.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.

This library is free software: you can redistribute it and/or modify it
under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this library.  If not, see <http://www.gnu.org/licenses/>. */

#ifndef _Z_network_4_TCP_H_
#define _Z_network_4_TCP_H_

#include <Z/types/base.h>

typedef Z_STRICT_STRUCTURE (
	zuint16 source_port;
	zuint16 destination_port;
	zuint32 sequence_number;
	zuint64 acknowledgment_number;
	zuint16 state; /* WIP */
	zuint16 window_size;
	zuint16 checksum;
	zuint16 urgent_pointer;
) ZTCPHeader;

#endif /* _Z_network_4_TCP_H_ */
