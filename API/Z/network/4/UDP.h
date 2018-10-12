/* Z Kit - network/4/UDP.h
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2018 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef _Z_network_4_UDP_H_
#define _Z_network_4_UDP_H_

#include <Z/types/base.h>

typedef Z_STRICT_STRUCTURE (
	zuint32 source_address;
	zuint32 destination_address;
	zuint8	zeros;
	zuint8	protocol;
	zuint16 udp_length;
	zuint16 source_port;
	zuint16 destination_port;
	zuint16 size;
	zuint16 checksum;
	zuint32 data;
) ZUDPPseudoHeader;

#endif /* _Z_network_4_UDP_H_ */
